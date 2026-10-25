/* Implementacion del shim C para DolRecomp (ver cpu.h).
 *
 * Compila como C (no C++): los simbolos aqui definidos son los que
 * los 176 chunks esperan sin mangling. La semantica de memoria es
 * la de este port (RAM + alias sin cache + forma fisica, hardware
 * 0xCC00xxxx a 0 sin exception, fuera de rango con exception); la
 * de FP/excepciones sigue el manual PowerPC/Gekko en primera
 * aproximacion (ver caveats en cpu.h).
 */

#include "cpu/cpu.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fenv.h>

unsigned dolrecomp_call_depth = 0;

/* ---------------- traza dinamica de hardware (Fase 4) ---------------- */

#define SFA_HW_TRACE_MAX_ADDRS 2048
#define SFA_HW_TRACE_EVENTS_PER_ADDR 20

typedef struct {
    u32 addr;
    u64 reads;
    u64 writes;
    u32 first_count;
    u32 first_pc[SFA_HW_TRACE_EVENTS_PER_ADDR];
    u8 first_is_write[SFA_HW_TRACE_EVENTS_PER_ADDR];
    u8 first_size[SFA_HW_TRACE_EVENTS_PER_ADDR];
    u64 first_value[SFA_HW_TRACE_EVENTS_PER_ADDR];
} SfaHwTraceEntry;

static int sfa_hw_trace_enabled = 0;
static SfaHwTraceEntry sfa_hw_trace_entries[SFA_HW_TRACE_MAX_ADDRS];
static unsigned sfa_hw_trace_n = 0;
static unsigned long long sfa_hw_trace_total_count = 0;
static unsigned long long sfa_hw_trace_dropped_addrs = 0;

static void sfa_hw_trace_record(CPUState *cpu, u32 addr, u8 size,
                                int is_write, u64 value) {
    if (!sfa_hw_trace_enabled)
        return;
    sfa_hw_trace_total_count++;
    unsigned i;
    for (i = 0; i < sfa_hw_trace_n; i++) {
        if (sfa_hw_trace_entries[i].addr == addr)
            break;
    }
    if (i == sfa_hw_trace_n) {
        if (sfa_hw_trace_n >= SFA_HW_TRACE_MAX_ADDRS) {
            sfa_hw_trace_dropped_addrs++;
            return;
        }
        memset(&sfa_hw_trace_entries[i], 0, sizeof(sfa_hw_trace_entries[i]));
        sfa_hw_trace_entries[i].addr = addr;
        sfa_hw_trace_n++;
    }
    SfaHwTraceEntry *e = &sfa_hw_trace_entries[i];
    if (is_write)
        e->writes++;
    else
        e->reads++;
    if (e->first_count < SFA_HW_TRACE_EVENTS_PER_ADDR) {
        unsigned slot = e->first_count++;
        e->first_pc[slot] = cpu ? cpu->pc : 0;
        e->first_is_write[slot] = (u8)is_write;
        e->first_size[slot] = size;
        e->first_value[slot] = value;
    }
}

void sfa_hw_trace_set_enabled(int enabled) {
    sfa_hw_trace_enabled = enabled ? 1 : 0;
}

void sfa_hw_trace_reset(void) {
    sfa_hw_trace_n = 0;
    sfa_hw_trace_total_count = 0;
    sfa_hw_trace_dropped_addrs = 0;
    memset(sfa_hw_trace_entries, 0, sizeof(sfa_hw_trace_entries));
}

unsigned long long sfa_hw_trace_total(void) {
    return sfa_hw_trace_total_count;
}

unsigned sfa_hw_trace_distinct(void) {
    return sfa_hw_trace_n;
}

static int sfa_hw_trace_entry_cmp(const void *a, const void *b) {
    const SfaHwTraceEntry *ea = (const SfaHwTraceEntry *)a;
    const SfaHwTraceEntry *eb = (const SfaHwTraceEntry *)b;
    u64 ta = ea->reads + ea->writes;
    u64 tb = eb->reads + eb->writes;
    if (ta != tb)
        return ta < tb ? 1 : -1;
    return ea->addr < eb->addr ? -1 : (ea->addr > eb->addr ? 1 : 0);
}

int sfa_hw_trace_write_csv(const char *path) {
    if (path == NULL)
        return -1;
    FILE *f = fopen(path, "w");
    if (f == NULL)
        return -1;
    SfaHwTraceEntry *sorted = NULL;
    if (sfa_hw_trace_n > 0) {
        sorted = (SfaHwTraceEntry *)malloc(
            sizeof(SfaHwTraceEntry) * sfa_hw_trace_n);
        if (sorted == NULL) {
            fclose(f);
            return -1;
        }
        memcpy(sorted, sfa_hw_trace_entries,
               sizeof(SfaHwTraceEntry) * sfa_hw_trace_n);
        qsort(sorted, sfa_hw_trace_n, sizeof(SfaHwTraceEntry),
              sfa_hw_trace_entry_cmp);
    }
    fprintf(f, "address,reads,writes,total,first_pc,first_op,first_size,"
               "first_value\n");
    for (unsigned i = 0; i < sfa_hw_trace_n; i++) {
        SfaHwTraceEntry *e = &sorted[i];
        if (e->first_count > 0) {
            fprintf(f, "0x%08X,%llu,%llu,%llu,0x%08X,%s,%u,0x%llX\n",
                    e->addr, (unsigned long long)e->reads,
                    (unsigned long long)e->writes,
                    (unsigned long long)(e->reads + e->writes),
                    e->first_pc[0], e->first_is_write[0] ? "W" : "R",
                    e->first_size[0],
                    (unsigned long long)e->first_value[0]);
        } else {
            fprintf(f, "0x%08X,%llu,%llu,%llu,,,, \n",
                    e->addr, (unsigned long long)e->reads,
                    (unsigned long long)e->writes,
                    (unsigned long long)(e->reads + e->writes));
        }
    }
    fprintf(f, "# total=%llu distinct=%u dropped_addrs=%llu\n",
            sfa_hw_trace_total_count, sfa_hw_trace_n,
            sfa_hw_trace_dropped_addrs);
    free(sorted);
    fclose(f);
    return 0;
}

int sfa_hw_trace_write_events_csv(const char *path) {
    if (path == NULL)
        return -1;
    FILE *f = fopen(path, "w");
    if (f == NULL)
        return -1;
    fprintf(f, "address,seq,op,size,value,guest_pc\n");
    for (unsigned i = 0; i < sfa_hw_trace_n; i++) {
        SfaHwTraceEntry *e = &sfa_hw_trace_entries[i];
        for (unsigned j = 0; j < e->first_count; j++) {
            fprintf(f, "0x%08X,%u,%s,%u,0x%llX,0x%08X\n",
                    e->addr, j, e->first_is_write[j] ? "W" : "R",
                    e->first_size[j],
                    (unsigned long long)e->first_value[j], e->first_pc[j]);
        }
    }
    fclose(f);
    return 0;
}

/* ---------------- memoria guest ---------------- */

static u8 *resolve_addr(CPUState *cpu, u32 addr, u32 *avail) {
    if (addr >= GC_RAM_BASE && addr < GC_RAM_BASE + cpu->ram_size) {
        u32 offset = addr - GC_RAM_BASE;
        *avail = cpu->ram_size - offset;
        return cpu->ram + offset;
    }
    if (addr >= GC_RAM_UNCACHED && addr < GC_RAM_UNCACHED + cpu->ram_size) {
        u32 offset = addr - GC_RAM_UNCACHED;
        *avail = cpu->ram_size - offset;
        return cpu->ram + offset;
    }
    if (cpu->mem2 && cpu->mem2_size) {
        if (addr >= WII_MEM2_BASE && addr < WII_MEM2_BASE + cpu->mem2_size) {
            u32 offset = addr - WII_MEM2_BASE;
            *avail = cpu->mem2_size - offset;
            return cpu->mem2 + offset;
        }
        if (addr >= WII_MEM2_UNCACHED &&
            addr < WII_MEM2_UNCACHED + cpu->mem2_size) {
            u32 offset = addr - WII_MEM2_UNCACHED;
            *avail = cpu->mem2_size - offset;
            return cpu->mem2 + offset;
        }
    }
    /* Forma fisica: offset directo en RAM (la que generated.h aliasa
     * a GC_RAM_BASE para el PC). */
    if (addr < cpu->ram_size) {
        *avail = cpu->ram_size - addr;
        return cpu->ram + addr;
    }
    *avail = 0;
    return NULL;
}

static bool is_hardware(u32 addr) {
    return addr >= SFA_HW_BASE && addr < SFA_HW_END;
}

static void clear_matching_reservation(CPUState *cpu, u32 addr) {
    u32 reserve_addr = cpu->reserve_addr & ~0x40000000u;
    u32 store_addr = addr & ~0x40000000u;
    if (cpu->reserve_valid && ((reserve_addr ^ store_addr) & ~31u) == 0)
        cpu->reserve_valid = false;
}

static u8 *read_ptr(CPUState *cpu, u32 addr, u32 size, bool *hw) {
    *hw = false;
    if (cpu == NULL || cpu->ram == NULL)
        return NULL;
    if (is_hardware(addr)) {
        *hw = true;
        return NULL;
    }
    u32 avail = 0;
    u8 *host = resolve_addr(cpu, addr, &avail);
    if (host == NULL || avail < size)
        return NULL;
    return host;
}

static u8 *write_ptr(CPUState *cpu, u32 addr, u32 size, bool *hw) {
    return read_ptr(cpu, addr, size, hw);
}

static u16 read_be16(const u8 *p) {
    return (u16)(((u16)p[0] << 8) | (u16)p[1]);
}

static u32 read_be32(const u8 *p) {
    return ((u32)p[0] << 24) | ((u32)p[1] << 16) | ((u32)p[2] << 8) | (u32)p[3];
}

static u64 read_be64(const u8 *p) {
    return ((u64)read_be32(p) << 32) | read_be32(p + 4);
}

static void write_be16(u8 *p, u16 v) {
    p[0] = (u8)(v >> 8);
    p[1] = (u8)v;
}

static void write_be32(u8 *p, u32 v) {
    p[0] = (u8)(v >> 24);
    p[1] = (u8)(v >> 16);
    p[2] = (u8)(v >> 8);
    p[3] = (u8)v;
}

static void write_be64(u8 *p, u64 v) {
    write_be32(p, (u32)(v >> 32));
    write_be32(p + 4, (u32)v);
}

u8 mem_read8(CPUState *cpu, u32 addr) {
    bool hw = false;
    u8 *p = read_ptr(cpu, addr, 1, &hw);
    if (hw) {
        sfa_hw_trace_record(cpu, addr, 1, 0, 0);
        return 0;
    }
    if (p == NULL) {
        if (cpu != NULL) {
            cpu->exception = 1;
            // DAR = direccion efectiva fallida (como en una DSI
            // real): el chassis la registra para diagnosticar.
            cpu->dar = addr;
        }
        return 0;
    }
    return p[0];
}

u16 mem_read16(CPUState *cpu, u32 addr) {
    bool hw = false;
    u8 *p = read_ptr(cpu, addr, 2, &hw);
    if (hw) {
        sfa_hw_trace_record(cpu, addr, 2, 0, 0);
        return 0;
    }
    if (p == NULL) {
        if (cpu != NULL) {
            cpu->exception = 1;
            // DAR = direccion efectiva fallida (como en una DSI
            // real): el chassis la registra para diagnosticar.
            cpu->dar = addr;
        }
        return 0;
    }
    return read_be16(p);
}

u32 mem_read32(CPUState *cpu, u32 addr) {
    bool hw = false;
    u8 *p = read_ptr(cpu, addr, 4, &hw);
    if (hw) {
        sfa_hw_trace_record(cpu, addr, 4, 0, 0);
        return 0;
    }
    if (p == NULL) {
        if (cpu != NULL) {
            cpu->exception = 1;
            // DAR = direccion efectiva fallida (como en una DSI
            // real): el chassis la registra para diagnosticar.
            cpu->dar = addr;
        }
        return 0;
    }
    return read_be32(p);
}

u64 mem_read64(CPUState *cpu, u32 addr) {
    bool hw = false;
    u8 *p = read_ptr(cpu, addr, 8, &hw);
    if (hw) {
        sfa_hw_trace_record(cpu, addr, 8, 0, 0);
        return 0;
    }
    if (p == NULL) {
        if (cpu != NULL) {
            cpu->exception = 1;
            // DAR = direccion efectiva fallida (como en una DSI
            // real): el chassis la registra para diagnosticar.
            cpu->dar = addr;
        }
        return 0;
    }
    return read_be64(p);
}

void mem_write8(CPUState *cpu, u32 addr, u8 value) {
    bool hw = false;
    u8 *p = write_ptr(cpu, addr, 1, &hw);
    if (hw) {
        sfa_hw_trace_record(cpu, addr, 1, 1, value);
        return;
    }
    if (p == NULL) {
        if (cpu != NULL) {
            cpu->exception = 1;
            cpu->dar = addr;
        }
        return;
    }
    clear_matching_reservation(cpu, addr);
    p[0] = value;
}

void mem_write16(CPUState *cpu, u32 addr, u16 value) {
    bool hw = false;
    u8 *p = write_ptr(cpu, addr, 2, &hw);
    if (hw) {
        sfa_hw_trace_record(cpu, addr, 2, 1, value);
        return;
    }
    if (p == NULL) {
        if (cpu != NULL) {
            cpu->exception = 1;
            cpu->dar = addr;
        }
        return;
    }
    clear_matching_reservation(cpu, addr);
    write_be16(p, value);
}

void mem_write32(CPUState *cpu, u32 addr, u32 value) {
    bool hw = false;
    u8 *p = write_ptr(cpu, addr, 4, &hw);
    if (hw) {
        sfa_hw_trace_record(cpu, addr, 4, 1, value);
        return;
    }
    if (p == NULL) {
        if (cpu != NULL) {
            cpu->exception = 1;
            cpu->dar = addr;
        }
        return;
    }
    clear_matching_reservation(cpu, addr);
    write_be32(p, value);
}

void mem_write64(CPUState *cpu, u32 addr, u64 value) {
    bool hw = false;
    u8 *p = write_ptr(cpu, addr, 8, &hw);
    if (hw) {
        sfa_hw_trace_record(cpu, addr, 8, 1, value);
        return;
    }
    if (p == NULL) {
        if (cpu != NULL) {
            cpu->exception = 1;
            cpu->dar = addr;
        }
        return;
    }
    clear_matching_reservation(cpu, addr);
    write_be64(p, value);
}

/* ---------------- excepciones y control ---------------- */

#define PPC_BIT(n) (1u << (31u - (n)))
#define PPC_MSR_POW PPC_BIT(13)
#define PPC_MSR_ILE PPC_BIT(15)
#define PPC_MSR_EE PPC_BIT(16)
#define PPC_MSR_PR PPC_BIT(17)
#define PPC_MSR_FP PPC_BIT(18)
#define PPC_MSR_ME PPC_BIT(19)
#define PPC_MSR_FE0 PPC_BIT(20)
#define PPC_MSR_SE PPC_BIT(21)
#define PPC_MSR_BE PPC_BIT(22)
#define PPC_MSR_FE1 PPC_BIT(23)
#define PPC_MSR_IP PPC_BIT(25)
#define PPC_MSR_IR PPC_BIT(26)
#define PPC_MSR_DR PPC_BIT(27)
#define PPC_MSR_PM PPC_BIT(29)
#define PPC_MSR_RI PPC_BIT(30)
#define PPC_MSR_LE PPC_BIT(31)
#define PPC_MSR_RFI_MASK 0x87C0FFFFu

static u32 exception_vector_address(u32 msr, u32 vector) {
    return ((msr & PPC_MSR_IP) ? 0xFFF00000u : 0u) + vector;
}

static u32 exception_msr(u32 old_msr, u32 exception) {
    u32 clear = PPC_MSR_POW | PPC_MSR_EE | PPC_MSR_PR | PPC_MSR_FP |
                PPC_MSR_FE0 | PPC_MSR_SE | PPC_MSR_BE | PPC_MSR_FE1 |
                PPC_MSR_IR | PPC_MSR_DR | PPC_MSR_PM | PPC_MSR_RI |
                PPC_MSR_LE;
    if (exception & PPC_EXC_MACHINE_CHECK)
        clear |= PPC_MSR_ME;
    u32 next = old_msr & ~clear;
    if (old_msr & PPC_MSR_ILE)
        next |= PPC_MSR_LE;
    return next;
}

void ppc_take_exception(CPUState *cpu, u32 exception, u32 vector, u32 srr0,
                        u32 srr1_info) {
    u32 old_msr = cpu->msr;
    cpu->srr0 = srr0;
    cpu->srr1 = (old_msr & PPC_MSR_RFI_MASK) | srr1_info;
    cpu->exception |= exception;
    cpu->msr = exception_msr(old_msr, exception);
    cpu->pc = exception_vector_address(cpu->msr, vector);
}

void ppc_program_exception(CPUState *cpu, u32 cause, u32 cia) {
    cpu->program_exception |= cause;
    ppc_take_exception(cpu, PPC_EXC_PROGRAM, PPC_VECTOR_PROGRAM, cia, cause);
}

bool ppc_fp_available(CPUState *cpu, u32 cia) {
    if (cpu->msr & PPC_MSR_FP)
        return true;
    ppc_take_exception(cpu, PPC_EXC_FP_UNAVAILABLE,
                       PPC_VECTOR_FP_UNAVAILABLE, cia, 0);
    return false;
}

void ppc_fallback_instruction(CPUState *cpu, u32 raw, u32 cia) {
    if (cpu->instruction_fallback) {
        cpu->instruction_fallback(cpu, raw, cia);
        return;
    }
    (void)raw;
    ppc_program_exception(cpu, PPC_PROGRAM_ILLEGAL, cia);
}

bool ppc_host_call(CPUState *cpu, u32 address) {
    return cpu->host_call ? cpu->host_call(cpu, address) : false;
}

bool ppc_native_region_available(CPUState *cpu, u32 start, u32 end) {
    if (cpu == NULL || cpu->host_call == NULL)
        return true;
    u32 saved_addr = cpu->external_addr;
    u32 saved_value = cpu->external_value;
    u8 saved_rid = cpu->external_rid;
    cpu->external_addr = start;
    cpu->external_value = end;
    cpu->external_rid = PPC_NATIVE_REGION_QUERY_PENDING;
    bool blocked = cpu->host_call(cpu, PPC_HOST_CALL_NATIVE_REGION_QUERY);
    bool handled = cpu->external_rid == PPC_NATIVE_REGION_QUERY_HANDLED;
    cpu->external_addr = saved_addr;
    cpu->external_value = saved_value;
    cpu->external_rid = saved_rid;
    return handled && !blocked;
}

void ppc_system_call_exception(CPUState *cpu, u32 cia) {
    ppc_take_exception(cpu, PPC_EXC_SYSTEM_CALL, PPC_VECTOR_SYSTEM_CALL,
                       cia + 4u, 0);
}

void ppc_dsi_exception(CPUState *cpu, u32 ea, u32 cia, u32 dsisr) {
    cpu->dar = ea;
    cpu->dsisr = dsisr;
    ppc_take_exception(cpu, PPC_EXC_DSI, PPC_VECTOR_DSI, cia, 0);
}

void ppc_alignment_exception(CPUState *cpu, u32 ea, u32 cia) {
    cpu->dar = ea;
    ppc_take_exception(cpu, PPC_EXC_ALIGNMENT, PPC_VECTOR_ALIGNMENT, cia, 0);
}

u32 ppc_mftb(CPUState *cpu, u16 tbr, u32 cia) {
    if (tbr == 268)
        return (u32)cpu->timebase;
    if (tbr == 269)
        return (u32)(cpu->timebase >> 32);
    ppc_program_exception(cpu, PPC_PROGRAM_ILLEGAL, cia);
    return 0;
}

void ppc_rfi(CPUState *cpu, u32 cia) {
    if (cpu->msr & PPC_MSR_PR) {
        ppc_program_exception(cpu, PPC_PROGRAM_PRIV, cia);
        return;
    }
    cpu->msr = (cpu->msr & ~PPC_MSR_RFI_MASK) | (cpu->srr1 & PPC_MSR_RFI_MASK);
    cpu->msr &= ~PPC_MSR_POW;
    cpu->pc = cpu->srr0 & ~3u;
}

void ppc_dcbz_l(CPUState *cpu, u32 ea, u32 cia) {
    if (cpu->msr & PPC_MSR_PR) {
        ppc_program_exception(cpu, PPC_PROGRAM_PRIV, cia);
        return;
    }
    if ((cpu->hid2 & PPC_HID2_LCE) == 0) {
        ppc_program_exception(cpu, PPC_PROGRAM_ILLEGAL, cia);
        return;
    }
    u32 block = ea & ~31u;
    u32 slot = (block >> 5) & 511u;
    bool hit = cpu->locked_cache_valid[slot] &&
               cpu->locked_cache_tag[slot] == block;
    bool first_hit_error = hit && (cpu->hid2 & PPC_HID2_DCHERR) == 0;
    if (hit) {
        cpu->hid2 |= PPC_HID2_DCHERR;
        if (first_hit_error && (cpu->hid2 & PPC_HID2_DCHEE) &&
            (cpu->msr & PPC_MSR_EE) && (cpu->msr & PPC_MSR_ME)) {
            ppc_take_exception(cpu, PPC_EXC_MACHINE_CHECK,
                               PPC_VECTOR_MACHINE_CHECK, cia,
                               PPC_BIT(10));
        }
    } else {
        cpu->locked_cache_valid[slot] = true;
        cpu->locked_cache_tag[slot] = block;
    }
    for (u32 i = 0; i < 32; i += 4)
        mem_write32(cpu, block + i, 0);
}

bool ppc_trap_condition(u8 to, u32 a, u32 b) {
    s32 sa = (s32)a;
    s32 sb = (s32)b;
    return ((sa < sb) && (to & 0x10u)) || ((sa > sb) && (to & 0x08u)) ||
           ((sa == sb) && (to & 0x04u)) || ((a < b) && (to & 0x02u)) ||
           ((a > b) && (to & 0x01u));
}

void ppc_memory_fence(void) {
    __atomic_thread_fence(__ATOMIC_SEQ_CST);
}

bool ppc_add_overflowed(u32 a, u32 b, u32 result) {
    return (((a ^ result) & (b ^ result)) >> 31) != 0;
}

void ppc_set_xer_ov(CPUState *cpu, bool ov) {
    cpu->xer = (cpu->xer & ~0x40000000u) | (ov ? 0x40000000u : 0u);
    if (ov)
        cpu->xer |= 0x80000000u;
}

void ppc_tlbie(CPUState *cpu, u32 ea, u32 cia) {
    if (cpu->msr & PPC_MSR_PR) {
        ppc_program_exception(cpu, PPC_PROGRAM_PRIV, cia);
        return;
    }
    cpu->tlb_last_vps = (ea >> 12) & 0xFFFFu;
    cpu->tlb_last_index = (ea >> 12) & 0x3Fu;
    cpu->tlb_invalidate_count++;
}

void ppc_lswx(CPUState *cpu, u8 rD, u8 rA, u8 rB, u32 cia) {
    u32 count = cpu->xer & 0x7Fu;
    u32 reg_count = (count + 3u) / 4u;
    /* Rango de registros destino, con wrap modulo 32: si contiene el
     * registro base, la instruccion es ilegal. */
    for (u32 i = 0; i < reg_count; i++) {
        u32 reg = (rD + i) & 31u;
        if (reg == rA || reg == rB) {
            ppc_program_exception(cpu, PPC_PROGRAM_ILLEGAL, cia);
            return;
        }
    }
    u32 ea = (rA ? cpu->gpr[rA] : 0u) + cpu->gpr[rB];
    for (u32 n = 0; n < count; n++) {
        u32 reg = (rD + n / 4u) & 31u;
        if ((n & 3u) == 0)
            cpu->gpr[reg] = 0;
        cpu->gpr[reg] |= (u32)mem_read8(cpu, ea + n) << (24u - 8u * (n & 3u));
    }
}

void ppc_cache_control(CPUState *cpu, u8 operation, u32 ea, u32 cia) {
    if (operation == PPC_CACHE_DCBI && (cpu->msr & PPC_MSR_PR)) {
        ppc_program_exception(cpu, PPC_PROGRAM_PRIV, cia);
        return;
    }
    if (cpu->cache_control)
        cpu->cache_control(cpu, operation, ea, cia);
}

u32 ppc_eciwx(CPUState *cpu, u32 ea, u32 cia) {
    if ((cpu->ear & 0x80000000u) == 0) {
        ppc_dsi_exception(cpu, ea, cia, PPC_DSI_EAR_DISABLED);
        return 0;
    }
    if ((ea & 3u) != 0) {
        ppc_alignment_exception(cpu, ea, cia);
        return 0;
    }
    u8 rid = (u8)(cpu->ear & 0xFu);
    cpu->external_addr = ea;
    cpu->external_rid = rid;
    cpu->external_read_count++;
    if (cpu->external_read32)
        return cpu->external_read32(cpu, ea, rid);
    return 0;
}

void ppc_ecowx(CPUState *cpu, u32 ea, u32 value, u32 cia) {
    if ((cpu->ear & 0x80000000u) == 0) {
        ppc_dsi_exception(cpu, ea, cia, PPC_DSI_EAR_DISABLED);
        return;
    }
    if ((ea & 3u) != 0) {
        ppc_alignment_exception(cpu, ea, cia);
        return;
    }
    u8 rid = (u8)(cpu->ear & 0xFu);
    cpu->external_addr = ea;
    cpu->external_value = value;
    cpu->external_rid = rid;
    cpu->external_write_count++;
    if (cpu->external_write32)
        cpu->external_write32(cpu, ea, value, rid);
}

void ppc_stwcx_op(CPUState *cpu, u8 s, u32 ea, u32 cia) {
    if (ea & 3u) {
        ppc_alignment_exception(cpu, ea, cia);
        return;
    }
    u32 so = (cpu->xer >> 31) & 1u;
    bool success = cpu->reserve_valid && ea == cpu->reserve_addr;
    if (success) {
        mem_write32(cpu, ea, cpu->gpr[s]);
        cpu->reserve_valid = false;
    }
    cpu->cr = (cpu->cr & 0x0FFFFFFFu) | (((success ? 2u : 0u) | so) << 28);
}

/* ---------------- FP escalar ---------------- */

enum {
    FPSCR_ZX = 0x04000000u,
    FPSCR_XX = 0x02000000u,
    FPSCR_VXSNAN = 0x01000000u,
    FPSCR_VXISI = 0x00800000u,
    FPSCR_VXIDI = 0x00400000u,
    FPSCR_VXZDZ = 0x00200000u,
    FPSCR_VXIMZ = 0x00100000u,
    FPSCR_FR = 0x00040000u,
    FPSCR_FI = 0x00020000u,
    FPSCR_VE = 0x00000080u,
    FPSCR_ZE = 0x00000010u,
    FPSCR_NI = 0x00000004u,
};

static u64 f64_bits(f64 value) {
    u64 bits;
    memcpy(&bits, &value, sizeof(bits));
    return bits;
}

static f64 f64_value(u64 bits) {
    f64 value;
    memcpy(&value, &bits, sizeof(value));
    return value;
}

static f64 quiet_nan(f64 value) {
    return f64_value(f64_bits(value) | 0x0008000000000000ull);
}

static bool is_snan(f64 value) {
    u64 bits = f64_bits(value);
    u64 fraction = bits & 0x000FFFFFFFFFFFFFull;
    return (bits & 0x7FF0000000000000ull) == 0x7FF0000000000000ull &&
           fraction != 0 && (fraction & 0x0008000000000000ull) == 0;
}

/* Codigo de clase FPRF (bits 12-16 de FPSCR) segun el manual PPC. */
static u32 classify_f64(f64 value) {
    u64 bits = f64_bits(value);
    u64 sign = bits >> 63;
    u64 exponent = bits & 0x7FF0000000000000ull;
    u64 fraction = bits & 0x000FFFFFFFFFFFFFull;
    if (exponent == 0x7FF0000000000000ull)
        return fraction ? 0x11u : (sign ? 0x09u : 0x05u);
    if (exponent == 0)
        return fraction ? (sign ? 0x18u : 0x14u) : (sign ? 0x12u : 0x02u);
    return sign ? 0x08u : 0x04u;
}

static u32 classify_f32(f32 value) {
    u32 bits;
    memcpy(&bits, &value, sizeof(bits));
    u32 sign = bits >> 31;
    u32 exponent = bits & 0x7F800000u;
    u32 fraction = bits & 0x007FFFFFu;
    if (exponent == 0x7F800000u)
        return fraction ? 0x11u : (sign ? 0x09u : 0x05u);
    if (exponent == 0)
        return fraction ? (sign ? 0x18u : 0x14u) : (sign ? 0x12u : 0x02u);
    return sign ? 0x08u : 0x04u;
}

static void set_fprf(CPUState *cpu, u32 value) {
    cpu->fpscr = (cpu->fpscr & ~(0x1Fu << 12)) | ((value & 0x1Fu) << 12);
}

void ppc_fpscr_updated(CPUState *cpu) {
    const u32 vx_any = 0x01F80700u;
    const u32 any_e = 0x000000F8u;
    u32 fpscr = cpu->fpscr;
    fpscr = (fpscr & ~0x20000000u) | ((fpscr & vx_any) ? 0x20000000u : 0u);
    fpscr = (fpscr & ~0x40000000u) |
            ((((fpscr >> 22) & fpscr & any_e) != 0) ? 0x40000000u : 0u);
    cpu->fpscr = fpscr;
}

static void set_fp_exception(CPUState *cpu, u32 bit) {
    if ((cpu->fpscr & bit) != bit)
        cpu->fpscr |= 0x80000000u;
    cpu->fpscr |= bit;
    ppc_fpscr_updated(cpu);
}

void ppc_fpscr_control_updated(CPUState *cpu) {
    static const int rounding[4] = {FE_TONEAREST, FE_TOWARDZERO, FE_UPWARD,
                                    FE_DOWNWARD};
    ppc_fpscr_updated(cpu);
    fesetround(rounding[cpu->fpscr & 3u]);
}

void ppc_mtfsb0_op(CPUState *cpu, u8 bit) {
    cpu->fpscr &= ~(0x80000000u >> bit);
    ppc_fpscr_control_updated(cpu);
}

void ppc_mtfsb1_op(CPUState *cpu, u8 bit) {
    u32 mask = 0x80000000u >> bit;
    if (mask & 0x01F80700u)
        set_fp_exception(cpu, mask);
    else
        cpu->fpscr |= mask;
    ppc_fpscr_control_updated(cpu);
}

static void clear_fi_fr(CPUState *cpu) {
    cpu->fpscr &= ~(FPSCR_FI | FPSCR_FR);
}

static void set_fi_fr(CPUState *cpu, f64 exact, f64 rounded) {
    clear_fi_fr(cpu);
    if (isnan(exact) || exact == rounded)
        return;
    set_fp_exception(cpu, FPSCR_XX);
    cpu->fpscr |= FPSCR_FI;
    if (fabs(rounded) > fabs(exact))
        cpu->fpscr |= FPSCR_FR;
}

static f32 force_single(CPUState *cpu, f64 value) {
    /* NI (non-IEEE): los valores muy pequenos se tratan como cero
     * con signo, y los subnormales f32 tambien se llevan a cero. */
    if (cpu->fpscr & FPSCR_NI) {
        u64 bits = f64_bits(value);
        if ((bits & 0x7FFFFFFFFFFFFFFFull) < 0x3810000000000000ull)
            return copysignf(0.0f, (f32)value);
    }
    f32 result = (f32)value;
    if ((cpu->fpscr & FPSCR_NI) && fpclassify(result) == FP_SUBNORMAL)
        return copysignf(0.0f, result);
    return result;
}

typedef enum { FP_ADD, FP_SUB, FP_MUL, FP_DIV } FPBinaryOp;

typedef struct {
    f64 value;
    u32 exception;
} FPBinaryResult;

static FPBinaryResult binary_fp(CPUState *cpu, FPBinaryOp op, f64 a, f64 b) {
    (void)cpu;
    FPBinaryResult result = {0, 0};
    switch (op) {
    case FP_ADD: result.value = a + b; break;
    case FP_SUB: result.value = a - b; break;
    case FP_MUL: result.value = a * b; break;
    case FP_DIV: result.value = a / b; break;
    }
    if (op == FP_DIV && isinf(result.value) && b == 0.0) {
        result.exception = FPSCR_ZX;
    } else if (isnan(result.value)) {
        if (is_snan(a) || is_snan(b)) {
            result.exception = FPSCR_VXSNAN;
        }
        if (isnan(a))
            result.value = quiet_nan(a);
        else if (isnan(b))
            result.value = quiet_nan(b);
        else if (op == FP_MUL) {
            result.value = f64_value(0x7FF8000000000000ull);
            result.exception = FPSCR_VXIMZ;
        } else if (op == FP_DIV) {
            result.value = f64_value(0x7FF8000000000000ull);
            result.exception = b == 0.0 ? FPSCR_VXZDZ : FPSCR_VXIDI;
        } else {
            result.value = f64_value(0x7FF8000000000000ull);
            result.exception = FPSCR_VXISI;
        }
    }
    if (result.exception)
        set_fp_exception(cpu, result.exception);
    return result;
}

static bool binary_result_enabled(const CPUState *cpu, FPBinaryResult result) {
    const u32 invalid = FPSCR_VXSNAN | FPSCR_VXISI | FPSCR_VXIDI |
                        FPSCR_VXZDZ | FPSCR_VXIMZ;
    if ((result.exception & invalid) && (cpu->fpscr & FPSCR_VE))
        return false;
    if (result.exception == FPSCR_ZX && (cpu->fpscr & FPSCR_ZE))
        return false;
    return true;
}

static void write_single_result(CPUState *cpu, u8 d, f32 value) {
    cpu->fpr[d] = (f64)value;
    cpu->ps1[d] = (f64)value;
    set_fprf(cpu, classify_f32(value));
}

static void binary_single(CPUState *cpu, u8 d, f64 a, f64 b, FPBinaryOp op) {
    FPBinaryResult result = binary_fp(cpu, op, a, b);
    if (!binary_result_enabled(cpu, result))
        return;
    f32 rounded = force_single(cpu, result.value);
    if (isfinite(result.value))
        set_fi_fr(cpu, result.value, (f64)rounded);
    write_single_result(cpu, d, rounded);
}

static void binary_double(CPUState *cpu, u8 d, f64 a, f64 b, FPBinaryOp op) {
    FPBinaryResult result = binary_fp(cpu, op, a, b);
    if (!binary_result_enabled(cpu, result))
        return;
    cpu->fpr[d] = result.value;
    if (op == FP_MUL)
        clear_fi_fr(cpu);
    set_fprf(cpu, classify_f64(cpu->fpr[d]));
}

void ppc_fadds(CPUState *cpu, u8 d, u8 a, u8 b) {
    binary_single(cpu, d, cpu->fpr[a], cpu->fpr[b], FP_ADD);
}

void ppc_fsubs(CPUState *cpu, u8 d, u8 a, u8 b) {
    binary_single(cpu, d, cpu->fpr[a], cpu->fpr[b], FP_SUB);
}

void ppc_fmuls(CPUState *cpu, u8 d, u8 a, u8 c) {
    binary_single(cpu, d, cpu->fpr[a], cpu->fpr[c], FP_MUL);
}

void ppc_fdivs(CPUState *cpu, u8 d, u8 a, u8 b) {
    binary_single(cpu, d, cpu->fpr[a], cpu->fpr[b], FP_DIV);
}

void ppc_fadd(CPUState *cpu, u8 d, u8 a, u8 b) {
    binary_double(cpu, d, cpu->fpr[a], cpu->fpr[b], FP_ADD);
}

void ppc_fsub(CPUState *cpu, u8 d, u8 a, u8 b) {
    binary_double(cpu, d, cpu->fpr[a], cpu->fpr[b], FP_SUB);
}

void ppc_fmul(CPUState *cpu, u8 d, u8 a, u8 c) {
    binary_double(cpu, d, cpu->fpr[a], cpu->fpr[c], FP_MUL);
}

void ppc_fdiv(CPUState *cpu, u8 d, u8 a, u8 b) {
    binary_double(cpu, d, cpu->fpr[a], cpu->fpr[b], FP_DIV);
}

void ppc_frsp(CPUState *cpu, u8 d, u8 b) {
    f64 value = cpu->fpr[b];
    f32 rounded = force_single(cpu, value);
    if (isnan(value)) {
        bool snan = is_snan(value);
        if (snan)
            set_fp_exception(cpu, FPSCR_VXSNAN);
        clear_fi_fr(cpu);
        if (snan && (cpu->fpscr & FPSCR_VE))
            return;
    } else {
        set_fi_fr(cpu, value, (f64)rounded);
    }
    write_single_result(cpu, d, rounded);
}

f64 ppc_approx_reciprocal(f64 value) {
    if (value == 0.0)
        return copysign(INFINITY, value);
    if (isnan(value))
        return quiet_nan(value);
    if (isinf(value))
        return copysign(0.0, value);
    return 1.0 / value;
}

f64 ppc_approx_rsqrt(f64 value) {
    if (value == 0.0)
        return copysign(INFINITY, value);
    if (isnan(value))
        return quiet_nan(value);
    if (isinf(value))
        return value > 0.0 ? 0.0 : quiet_nan(value);
    if (value < 0.0)
        return quiet_nan(value);
    return 1.0 / sqrt(value);
}

bool ppc_fres(CPUState *cpu, f64 value, f64 *result) {
    if (value == 0.0) {
        set_fp_exception(cpu, FPSCR_ZX);
        cpu->fpscr &= ~0x00006000u;
        if (cpu->fpscr & FPSCR_ZE)
            return false;
    } else if (is_snan(value)) {
        set_fp_exception(cpu, FPSCR_VXSNAN);
        cpu->fpscr &= ~0x00006000u;
        if (cpu->fpscr & FPSCR_VE)
            return false;
    } else if (isnan(value) || isinf(value)) {
        cpu->fpscr &= ~0x00006000u;
    }
    *result = ppc_approx_reciprocal(value);
    set_fprf(cpu, classify_f32((f32)*result));
    return true;
}

bool ppc_frsqrte(CPUState *cpu, f64 value, f64 *result) {
    if (value == 0.0) {
        set_fp_exception(cpu, FPSCR_ZX);
        cpu->fpscr &= ~0x00006000u;
        if (cpu->fpscr & FPSCR_ZE)
            return false;
    } else if (is_snan(value)) {
        set_fp_exception(cpu, FPSCR_VXSNAN);
        cpu->fpscr &= ~0x00006000u;
        if (cpu->fpscr & FPSCR_VE)
            return false;
    } else if (value < 0.0) {
        set_fp_exception(cpu, FPSCR_VXISI);
        cpu->fpscr &= ~0x00006000u;
        if (cpu->fpscr & FPSCR_VE)
            return false;
        *result = quiet_nan(value);
        return true;
    } else if (isnan(value) || isinf(value)) {
        cpu->fpscr &= ~0x00006000u;
    }
    *result = ppc_approx_rsqrt(value);
    set_fprf(cpu, classify_f32((f32)*result));
    return true;
}

bool ppc_fma(CPUState *cpu, f64 a, f64 c, f64 b, bool single,
             bool subtract, bool negative, f64 *output) {
    f64 addend = subtract ? -b : b;
    f64 result = single ? (f64)(f32)fmaf((f32)a, (f32)c, (f32)addend)
                        : fma(a, c, addend);
    if (isnan(result)) {
        u32 invalid = 0;
        if (is_snan(a) || is_snan(b) || is_snan(c))
            invalid |= FPSCR_VXSNAN;
        cpu->fpscr &= ~0x00006000u;
        if (isnan(a))
            result = quiet_nan(a);
        else if (isnan(b))
            result = quiet_nan(b);
        else if (isnan(c))
            result = quiet_nan(c);
        else {
            bool invalid_multiply = (a == 0.0 && isinf(c)) ||
                                    (isinf(a) && c == 0.0);
            invalid |= invalid_multiply ? FPSCR_VXIMZ : FPSCR_VXISI;
            result = f64_value(0x7FF8000000000000ull);
        }
        if (invalid) {
            set_fp_exception(cpu, invalid);
            if (cpu->fpscr & FPSCR_VE)
                return false;
        }
    } else if (isinf(a) || isinf(b) || isinf(c)) {
        cpu->fpscr &= ~0x00006000u;
    }
    if (negative && !isnan(result))
        result = -result;
    set_fprf(cpu, single ? classify_f32((f32)result) : classify_f64(result));
    *output = result;
    return true;
}

static f64 round_nearest_even(f64 value) {
    f64 lo = floor(value);
    f64 fraction = value - lo;
    if (fraction < 0.5)
        return lo;
    if (fraction > 0.5)
        return lo + 1.0;
    return fmod(lo, 2.0) == 0.0 ? lo : lo + 1.0;
}

bool ppc_fctiw(CPUState *cpu, f64 value, bool toward_zero, u64 *output) {
    f64 rounded;
    switch (toward_zero ? 1u : (cpu->fpscr & 3u)) {
    case 1: rounded = trunc(value); break;
    case 2: rounded = ceil(value); break;
    case 3: rounded = floor(value); break;
    default: rounded = round_nearest_even(value); break;
    }
    u32 result = 0;
    bool invalid = false;
    if (isnan(value)) {
        if (is_snan(value))
            set_fp_exception(cpu, FPSCR_VXSNAN);
        result = 0x80000000u;
        invalid = true;
    } else if (rounded >= 2147483648.0) {
        result = 0x7FFFFFFFu;
        invalid = true;
    } else if (rounded < -2147483648.0) {
        result = 0x80000000u;
        invalid = true;
    } else {
        result = (u32)(s32)rounded;
    }
    cpu->fpscr &= ~0x00006000u;
    if (invalid) {
        set_fp_exception(cpu, 0x00000100u);
    } else if (rounded != value) {
        set_fp_exception(cpu, FPSCR_XX);
        cpu->fpscr |= 0x00004000u;
        if (fabs(rounded) > fabs(value))
            cpu->fpscr |= 0x00002000u;
    }
    if (invalid && (cpu->fpscr & FPSCR_VE))
        return false;
    *output = 0xFFF8000000000000ull | result |
              ((result == 0 && signbit(value)) ? 0x100000000ull : 0ull);
    return true;
}

void ppc_fcmp(CPUState *cpu, u8 crfd, f64 a, f64 b, bool ordered) {
    u32 compare = 0;
    if (isnan(a) || isnan(b)) {
        compare = 1u;
        if (is_snan(a) || is_snan(b)) {
            set_fp_exception(cpu, FPSCR_VXSNAN);
            if (ordered && (cpu->fpscr & FPSCR_VE) == 0)
                set_fp_exception(cpu, 0x00080000u);
        } else if (ordered) {
            set_fp_exception(cpu, 0x00080000u);
        }
    } else if (a < b) {
        compare = 8u;
    } else if (a > b) {
        compare = 4u;
    } else {
        compare = 2u;
    }
    /* FPCC son los 4 bits bajos de FPRF; el bit de clase (16) no se
     * toca en una comparacion: se reemplaza, no se hace OR. */
    cpu->fpscr = (cpu->fpscr & ~(0xFu << 12)) | (compare << 12);
    u32 shift = 4u * (7u - crfd);
    cpu->cr = (cpu->cr & ~(0xFu << shift)) | (compare << shift);
}

/* ---------------- paired-single y PSQ ---------------- */

static void write_paired_result(CPUState *cpu, u8 d, f64 ps0, f64 ps1) {
    cpu->fpr[d] = (f64)(f32)ps0;
    cpu->ps1[d] = (f64)(f32)ps1;
    set_fprf(cpu, classify_f32((f32)ps0));
}

static f64 paired_binary_nan(f64 a, f64 b, f64 result) {
    if (isnan(a))
        return quiet_nan(a);
    if (isnan(b))
        return quiet_nan(b);
    if (isnan(result))
        return f64_value(0x7FF8000000000000ull);
    return result;
}

static f64 paired_fma_nan(f64 a, f64 b, f64 c, f64 result) {
    if (isnan(a))
        return quiet_nan(a);
    if (isnan(b))
        return quiet_nan(b);
    if (isnan(c))
        return quiet_nan(c);
    if (isnan(result))
        return f64_value(0x7FF8000000000000ull);
    return result;
}

static f64 single_fma(f64 a, f64 c, f64 b) {
    return (f64)(f32)fmaf((f32)a, (f32)c, (f32)b);
}

void ppc_ps_add_op(CPUState *cpu, u8 d, u8 a, u8 b) {
    write_paired_result(
        cpu, d,
        paired_binary_nan(cpu->fpr[a], cpu->fpr[b], cpu->fpr[a] + cpu->fpr[b]),
        paired_binary_nan(cpu->ps1[a], cpu->ps1[b], cpu->ps1[a] + cpu->ps1[b]));
}

void ppc_ps_sub_op(CPUState *cpu, u8 d, u8 a, u8 b) {
    write_paired_result(
        cpu, d,
        paired_binary_nan(cpu->fpr[a], cpu->fpr[b], cpu->fpr[a] - cpu->fpr[b]),
        paired_binary_nan(cpu->ps1[a], cpu->ps1[b], cpu->ps1[a] - cpu->ps1[b]));
}

void ppc_ps_mul_op(CPUState *cpu, u8 d, u8 a, u8 c) {
    write_paired_result(
        cpu, d,
        paired_binary_nan(cpu->fpr[a], cpu->fpr[c], cpu->fpr[a] * cpu->fpr[c]),
        paired_binary_nan(cpu->ps1[a], cpu->ps1[c],
                          cpu->ps1[a] * cpu->ps1[c]));
}

void ppc_ps_div_op(CPUState *cpu, u8 d, u8 a, u8 b) {
    write_paired_result(
        cpu, d,
        paired_binary_nan(cpu->fpr[a], cpu->fpr[b], cpu->fpr[a] / cpu->fpr[b]),
        paired_binary_nan(cpu->ps1[a], cpu->ps1[b], cpu->ps1[a] / cpu->ps1[b]));
}

void ppc_ps_madd_op(CPUState *cpu, u8 d, u8 a, u8 c, u8 b,
                    bool subtract, bool negative) {
    f64 ps0 = single_fma(cpu->fpr[a], cpu->fpr[c],
                         subtract ? -cpu->fpr[b] : cpu->fpr[b]);
    f64 ps1 = single_fma(cpu->ps1[a], cpu->ps1[c],
                         subtract ? -cpu->ps1[b] : cpu->ps1[b]);
    ps0 = paired_fma_nan(cpu->fpr[a], cpu->fpr[b], cpu->fpr[c], ps0);
    ps1 = paired_fma_nan(cpu->ps1[a], cpu->ps1[b], cpu->ps1[c], ps1);
    if (negative) {
        ps0 = (f64)(f32)ps0;
        ps1 = (f64)(f32)ps1;
        if (!isnan(ps0))
            ps0 = -ps0;
        if (!isnan(ps1))
            ps1 = -ps1;
    }
    write_paired_result(cpu, d, ps0, ps1);
}

void ppc_ps_madds0(CPUState *cpu, u8 d, u8 a, u8 c, u8 b) {
    f64 ps0 = single_fma(cpu->fpr[a], cpu->fpr[c], cpu->fpr[b]);
    f64 ps1 = single_fma(cpu->ps1[a], cpu->fpr[c], cpu->ps1[b]);
    write_paired_result(
        cpu, d, paired_fma_nan(cpu->fpr[a], cpu->fpr[b], cpu->fpr[c], ps0),
        paired_fma_nan(cpu->ps1[a], cpu->ps1[b], cpu->fpr[c], ps1));
}

void ppc_ps_madds1(CPUState *cpu, u8 d, u8 a, u8 c, u8 b) {
    f64 ps0 = single_fma(cpu->fpr[a], cpu->ps1[c], cpu->fpr[b]);
    f64 ps1 = single_fma(cpu->ps1[a], cpu->ps1[c], cpu->ps1[b]);
    write_paired_result(
        cpu, d, paired_fma_nan(cpu->fpr[a], cpu->fpr[b], cpu->ps1[c], ps0),
        paired_fma_nan(cpu->ps1[a], cpu->ps1[b], cpu->ps1[c], ps1));
}

void ppc_ps_sum0(CPUState *cpu, u8 d, u8 a, u8 c, u8 b) {
    write_paired_result(
        cpu, d,
        paired_binary_nan(cpu->fpr[a], cpu->ps1[b],
                          cpu->fpr[a] + cpu->ps1[b]),
        cpu->ps1[c]);
}

void ppc_ps_sum1(CPUState *cpu, u8 d, u8 a, u8 c, u8 b) {
    write_paired_result(
        cpu, d, cpu->fpr[c],
        paired_binary_nan(cpu->fpr[a], cpu->ps1[b],
                          cpu->fpr[a] + cpu->ps1[b]));
}

void ppc_ps_muls0(CPUState *cpu, u8 d, u8 a, u8 c) {
    f64 scalar = cpu->fpr[c];
    write_paired_result(
        cpu, d,
        paired_binary_nan(cpu->fpr[a], cpu->fpr[c], cpu->fpr[a] * scalar),
        paired_binary_nan(cpu->ps1[a], cpu->fpr[c], cpu->ps1[a] * scalar));
}

void ppc_ps_muls1(CPUState *cpu, u8 d, u8 a, u8 c) {
    f64 scalar = cpu->ps1[c];
    write_paired_result(
        cpu, d,
        paired_binary_nan(cpu->fpr[a], cpu->ps1[c], cpu->fpr[a] * scalar),
        paired_binary_nan(cpu->ps1[a], cpu->ps1[c], cpu->ps1[a] * scalar));
}

void ppc_ps_res(CPUState *cpu, f64 a, f64 b, f64 *result_a, f64 *result_b) {
    f64 ra = quiet_nan(a);
    f64 rb = quiet_nan(b);
    (void)ppc_fres(cpu, a, &ra);
    (void)ppc_fres(cpu, b, &rb);
    *result_a = ra;
    *result_b = rb;
}

void ppc_ps_rsqrte(CPUState *cpu, f64 a, f64 b, f64 *result_a, f64 *result_b) {
    f64 ra = quiet_nan(a);
    f64 rb = quiet_nan(b);
    (void)ppc_frsqrte(cpu, a, &ra);
    (void)ppc_frsqrte(cpu, b, &rb);
    *result_a = ra;
    *result_b = rb;
}

void ppc_ps_res_op(CPUState *cpu, u8 d, u8 b) {
    ppc_ps_res(cpu, cpu->fpr[b], cpu->ps1[b], &cpu->fpr[d], &cpu->ps1[d]);
}

void ppc_ps_rsqrte_op(CPUState *cpu, u8 d, u8 b) {
    ppc_ps_rsqrte(cpu, cpu->fpr[b], cpu->ps1[b], &cpu->fpr[d], &cpu->ps1[d]);
}

/* GQR: escala con signo de 6 bits; tipos 0=f32 (4 B), 4=u8, 5=u16,
 * 6=s8, 7=s16. En carga, escala y tipo salen de los bits altos del
 * GQR; en almacenamiento, de los bits bajos. */
static s32 gqr_scale(u32 value) {
    u32 v = value & 0x3Fu;
    return (s32)(v >= 32u ? v - 64u : v);
}

static u32 psq_type_size(u8 type) {
    switch (type) {
    case 0: return 4;
    case 4:
    case 6: return 1;
    case 5:
    case 7: return 2;
    default: return 0;
    }
}

static bool psq_access_is_valid(CPUState *cpu, u8 type, u32 ea, u32 cia) {
    if (psq_type_size(type) == 0) {
        ppc_program_exception(cpu, PPC_PROGRAM_ILLEGAL, cia);
        return false;
    }
    if (type == 0 && (ea & 3u) != 0) {
        ppc_alignment_exception(cpu, ea, cia);
        return false;
    }
    return true;
}

static f64 psq_load_value(CPUState *cpu, u32 ea, u8 type, s32 scale) {
    switch (type) {
    case 0: {
        u32 bits = mem_read32(cpu, ea);
        f32 single;
        memcpy(&single, &bits, sizeof(single));
        return (f64)single;
    }
    case 4:
        return (f64)(f32)ldexp((f64)mem_read8(cpu, ea), -scale);
    case 5:
        return (f64)(f32)ldexp((f64)mem_read16(cpu, ea), -scale);
    case 6:
        return (f64)(f32)ldexp((f64)(s8)mem_read8(cpu, ea), -scale);
    case 7:
        return (f64)(f32)ldexp((f64)(s16)mem_read16(cpu, ea), -scale);
    default:
        return 0.0;
    }
}

static s64 psq_quantize_int(f64 value, s64 min_value, s64 max_value,
                            s32 scale) {
    if (isnan(value))
        return max_value;
    if (isinf(value))
        return value < 0.0 ? min_value : max_value;
    f64 scaled = trunc(ldexp(value, scale));
    if (scaled <= (f64)min_value)
        return min_value;
    if (scaled >= (f64)max_value)
        return max_value;
    return (s64)scaled;
}

static void psq_store_value(CPUState *cpu, u32 ea, u8 type, s32 scale,
                            f64 value) {
    switch (type) {
    case 0: {
        f32 single = (f32)value;
        u32 bits;
        memcpy(&bits, &single, sizeof(bits));
        mem_write32(cpu, ea,
                    fpclassify(single) == FP_SUBNORMAL ? 0u : bits);
        break;
    }
    case 4:
        mem_write8(cpu, ea, (u8)psq_quantize_int(value, 0, 255, scale));
        break;
    case 5:
        mem_write16(cpu, ea, (u16)psq_quantize_int(value, 0, 65535, scale));
        break;
    case 6:
        mem_write8(cpu, ea, (u8)(s8)psq_quantize_int(value, -128, 127, scale));
        break;
    case 7:
        mem_write16(cpu, ea,
                    (u16)(s16)psq_quantize_int(value, -32768, 32767, scale));
        break;
    }
}

static bool psq_check_enabled(CPUState *cpu, bool indexed, u32 cia) {
    if ((cpu->hid2 & PPC_HID2_PSE) == 0 ||
        (!indexed && (cpu->hid2 & PPC_HID2_LSQE) == 0)) {
        ppc_program_exception(cpu, PPC_PROGRAM_ILLEGAL, cia);
        return false;
    }
    return true;
}

bool ppc_psq_load(CPUState *cpu, u8 frD, u32 ea, bool w, u8 gqr_index,
                  bool indexed, u32 cia) {
    if (!psq_check_enabled(cpu, indexed, cia))
        return false;
    u32 gqr = cpu->gqr[gqr_index & 7u];
    s32 scale = gqr_scale(gqr >> 24);
    u8 type = (u8)((gqr >> 16) & 7u);
    u32 size = psq_type_size(type);
    if (!psq_access_is_valid(cpu, type, ea, cia))
        return false;
    cpu->fpr[frD] = psq_load_value(cpu, ea, type, scale);
    if (w) {
        cpu->ps1[frD] = 1.0;
    } else {
        u32 ps1_ea = ea + size;
        if (!psq_access_is_valid(cpu, type, ps1_ea, cia))
            return false;
        cpu->ps1[frD] = psq_load_value(cpu, ps1_ea, type, scale);
    }
    return true;
}

bool ppc_psq_store(CPUState *cpu, u8 frS, u32 ea, bool w, u8 gqr_index,
                   bool indexed, u32 cia) {
    if (!psq_check_enabled(cpu, indexed, cia))
        return false;
    u32 gqr = cpu->gqr[gqr_index & 7u];
    s32 scale = gqr_scale(gqr >> 8);
    u8 type = (u8)(gqr & 7u);
    u32 size = psq_type_size(type);
    if (!psq_access_is_valid(cpu, type, ea, cia))
        return false;
    psq_store_value(cpu, ea, type, scale, cpu->fpr[frS]);
    if (!w) {
        u32 ps1_ea = ea + size;
        if (!psq_access_is_valid(cpu, type, ps1_ea, cia))
            return false;
        psq_store_value(cpu, ps1_ea, type, scale, cpu->ps1[frS]);
    }
    return true;
}
