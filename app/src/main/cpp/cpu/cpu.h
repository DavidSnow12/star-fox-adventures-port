/* Shim global C para el codigo DolRecomp de Star Fox Adventures.
 *
 * Esta es la cabecera que codigo/generated/generated.h exige como
 * "cpu/cpu.h" (DOLRECOMP_CPU_HEADER). Se compila como C, no como
 * C++, para que los simbolos mem_* y ppc_* no sufran name mangling y
 * los 176 chunks enlacen directamente.
 *
 * Layout de CPUState: el orden y los tipos son los del cpu.h
 * canonico de DolRecomp (ExpansionPak), no un invento local. Los
 * chunks solo acceden por nombre, pero mantener el orden canonico
 * hace que este struct sea intercambiable con cualquier runtime
 * DolRecomp y que la cabecera C++ (gamecube_runtime/cpu_state.h)
 * sea un alias de este mismo tipo, no una segunda definicion que
 * pueda divergir.
 *
 * Campos que los chunks usan (verificado por grep en los 176):
 *   gpr[32], fpr[32], ps1[32], cr, xer, lr, ctr, pc, gqr[8], msr,
 *   fpscr, srr0, srr1, sr[16], hid2, ear, downcount, exception.
 * Ademas, generated.h exige: host_call (puntero a funcion, consultado
 * en dolrecomp_call()), ram/ram_size (alias de PC fisico en
 * dolrecomp_physical_pc_alias()) y GC_RAM_BASE.
 *
 * Semantica de memoria propia de este port (distinta del runtime de
 * ejemplo de DolRecomp, y a proposito):
 *   - RAM guest 0x80000000-0x81800000 y su alias sin cache
 *     0xC0000000-0xC1800000, mas la forma fisica (offset < ram_size)
 *     que generated.h aliasa a GC_RAM_BASE.
 *   - Registros de hardware 0xCC000000-0xCC020000 (CC00 y CC01):
 *     lectura 0, escritura ignorada, SIN exception, EXCEPTO el
 *     bloque ARAM/DSP 0xCC005000-0xCC00503F (Fase 5): registros
 *     guardados, y AR_MODE (0xCC005016) leido siempre con bit 0
 *     a 1 (ARAM lista, sin DMA pendiente). Ver cpu.c.
 *   - Fuera de rango: lectura 0 / escritura ignorada, CON
 *     exception = 1 en el estado (comportamiento ya verificado de
 *     la base anterior, conservado).
 *
 * Los helpers ppc_* implementan la ABI que emiten los chunks. Son
 * una implementacion propia para este port, escrita a partir de la
 * semantica PowerPC/Gekko y de las firmas del cpu.h de DolRecomp
 * (mismas firmas, no codigo copiado). Fidelidad, honesta, en esta
 * fase: la aritmetica FP es doble plana con redondeo a f32 donde
 * la instruccion es single (verificado: los fpr guardan dobles
 * planos iguales al f32, salvo payload NaN), fres/frsqrte usan el
 * reciproco exacto en vez de la estimacion Gekko (el codigo guest
 * que refina con Newton converge igual; la bit-exactitud de la
 * estimacion es trabajo de la Fase 2, no de este enlace), y las
 * excepciones program/system/trap/rfi siguen la mascara MSR de PPC.
 * Lo que NO hace esta fase: ejecutar el juego. Todo esto enlaza y
 * pasa tests de unidad; la ejecucion real exige el HLE de la Fase 2.
 */

#ifndef SFA_CPU_CPU_H
#define SFA_CPU_CPU_H

#include <stdbool.h>
#include <stdint.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;
typedef float f32;
typedef double f64;

#define GC_MAIN_RAM_SIZE (24 * 1024 * 1024)
#define GC_RAM_BASE 0x80000000u
#define GC_RAM_UNCACHED 0xC0000000u
/* Caché bloqueada (locked cache) del SDK: _LCEnable (0x8024247C)
 * programa DBAT3 sobre 0xE0000000 y pone a cero 512 lineas de
 * 32 B = 16 KiB con dcbz. getCache() devuelve 0xE0000000 cuando
 * la cache de pelicula esta inactiva (estado 0 o 4), y el juego
 * escribe ahi directamente (p. ej. updateHeavyFogTexture) y por
 * DMA LC (LCLoadBlocks/LCStoreBlocks). Sin esta region, mem_*
 * marcaba exception en el primer stbx (bloqueador nº 1). */
#define GC_LC_BASE 0xE0000000u
#define GC_LC_SIZE 16384u
#define WII_MEM2_SIZE (64 * 1024 * 1024)
#define WII_MEM2_BASE 0x90000000u
#define WII_MEM2_UNCACHED 0xD0000000u

/* Rango de hardware interceptado por mem_* en este port. */
#define SFA_HW_BASE 0xCC000000u
#define SFA_HW_END 0xCC020000u

#define PPC_EXC_PROGRAM 0x00000001u
#define PPC_EXC_DSI 0x00000002u
#define PPC_EXC_ALIGNMENT 0x00000004u
#define PPC_EXC_SYSTEM_CALL 0x00000008u
#define PPC_EXC_MACHINE_CHECK 0x00000010u
#define PPC_EXC_FP_UNAVAILABLE 0x00000020u

#define PPC_PROGRAM_FP 0x00100000u
#define PPC_PROGRAM_ILLEGAL 0x00080000u
#define PPC_PROGRAM_PRIV 0x00040000u
#define PPC_PROGRAM_TRAP 0x00020000u

#define PPC_DSI_EAR_DISABLED 0x00100000u

#define PPC_VECTOR_MACHINE_CHECK 0x00200u
#define PPC_VECTOR_DSI 0x00300u
#define PPC_VECTOR_ALIGNMENT 0x00600u
#define PPC_VECTOR_PROGRAM 0x00700u
#define PPC_VECTOR_FP_UNAVAILABLE 0x00800u
#define PPC_VECTOR_SYSTEM_CALL 0x00C00u

#define PPC_HID2_LSQE 0x80000000u
#define PPC_HID2_PSE 0x20000000u
#define PPC_HID2_LCE 0x10000000u
#define PPC_HID2_DCHERR 0x00800000u
#define PPC_HID2_DCHEE 0x00080000u

#define PPC_GEKKO_PVR 0x00083214u

#define PPC_CACHE_DCBST 0u
#define PPC_CACHE_DCBF 1u
#define PPC_CACHE_DCBI 2u
#define PPC_CACHE_ICBI 3u

typedef struct CPUState CPUState;
typedef u64 (*PPCExternalRead)(CPUState *cpu, u32 ea, u8 size);
typedef void (*PPCExternalWrite)(CPUState *cpu, u32 ea, u64 value, u8 size);
typedef u32 (*PPCExternalRead32)(CPUState *cpu, u32 ea, u8 rid);
typedef void (*PPCExternalWrite32)(CPUState *cpu, u32 ea, u32 value, u8 rid);
typedef void *(*PPCExternalPointer)(CPUState *cpu, u32 ea, u32 size);
typedef void (*PPCInstructionFallback)(CPUState *cpu, u32 raw, u32 cia);
typedef bool (*PPCHostCall)(CPUState *cpu, u32 address);
typedef u32 (*PPCSPRRead)(CPUState *cpu, u16 spr, u32 cia);
typedef void (*PPCSPRWrite)(CPUState *cpu, u16 spr, u32 value, u32 cia);
typedef void (*PPCCacheControl)(CPUState *cpu, u8 operation, u32 ea, u32 cia);

#define PPC_HOST_CALL_NATIVE_REGION_QUERY 0xFFFFFFFCu
#define PPC_NATIVE_REGION_QUERY_PENDING 0xFEu
#define PPC_NATIVE_REGION_QUERY_HANDLED 0xFFu

/* Orden canonico DolRecomp. No reordenar sin actualizar tambien la
 * documentacion de PORT-STATUS.md: el C++ usa este mismo tipo. */
struct CPUState {
    u32 gpr[32];
    f64 fpr[32];
    f64 ps1[32];
    u32 pc;
    u32 lr;
    u32 ctr;
    u32 cr;
    u32 xer;
    u32 fpscr;
    u32 msr;
    u32 srr0;
    u32 srr1;
    u32 dar;
    u32 dsisr;
    u32 ear;
    u32 hid2;
    u64 timebase;
    u32 sr[16];
    u32 gqr[8];
    u32 exception;
    u32 program_exception;
    u32 tlb_last_vps;
    u32 tlb_last_index;
    u32 tlb_invalidate_count;
    u32 external_addr;
    u32 external_value;
    u8 external_rid;
    u8 external_read_count;
    u8 external_write_count;
    u32 reserve_addr;
    bool reserve_valid;
    u32 locked_cache_tag[512];
    bool locked_cache_valid[512];
    PPCExternalRead external_read;
    PPCExternalWrite external_write;
    PPCExternalRead32 external_read32;
    PPCExternalWrite32 external_write32;
    PPCInstructionFallback instruction_fallback;
    PPCHostCall host_call;
    void *external_user_data;
    u8 *ram;
    u32 ram_size;
    PPCExternalPointer external_pointer;
    s64 downcount;
    s64 cycle_budget;
    union {
        u8 *exram;
        u8 *mem2;
    };
    union {
        u32 exram_size;
        u32 mem2_size;
    };
    PPCSPRRead spr_read;
    PPCSPRWrite spr_write;
    PPCCacheControl cache_control;
    /* Búfer de la caché bloqueada (ver GC_LC_BASE/GC_LC_SIZE).
     * AL FINAL del struct a proposito: cualquier campo nuevo
     * en medio desplazaria los offsets que los 176 chunks ya
     * compilados usan (downcount, ram, ...). A cero en el
     * arranque (InitCpuForBoot hace memset del struct);
     * LCEnable HLEado lo vuelve a poner a cero, como el bucle
     * dcbz de _LCEnable. Acceso via mem_* o directo; sin
     * reserva en el heap para no anadir una vida util que
     * gestionar en el runtime de la APK. */
    u8 locked_cache[GC_LC_SIZE];
};

#ifdef __cplusplus
extern "C" {
#endif

/* Memoria guest big-endian (implementacion en cpu.c). */
u64 mem_read64(CPUState *cpu, u32 addr);
void mem_write64(CPUState *cpu, u32 addr, u64 value);
u32 mem_read32(CPUState *cpu, u32 addr);
void mem_write32(CPUState *cpu, u32 addr, u32 value);
u16 mem_read16(CPUState *cpu, u32 addr);
void mem_write16(CPUState *cpu, u32 addr, u16 value);
u8 mem_read8(CPUState *cpu, u32 addr);
void mem_write8(CPUState *cpu, u32 addr, u8 value);

/* Contador compartido por los 176 chunks (lo declara generated.h
 * como extern; debe existir exactamente una definicion, aqui). */
extern unsigned dolrecomp_call_depth;

/* Traza dinamica de hardware (Fase 4 del port). Los chunks llaman
 * directamente a las mem_* C, no a los envoltorios C++, asi que la
 * traza vive aqui, no en mem.cpp: cualquier acceso a 0xCC00xxxx
 * (el unico rango hardware que mem_* reconoce) queda registrado
 * con direccion efectiva, tamano, lectura/escritura, valor y PC
 * guest (ctx->pc en el momento del acceso, que los chunks asignan
 * antes de cada instruccion). Para no inundar el log, por
 * direccion solo se guardan los 20 primeros eventos en detalle;
 * los contadores totales siguen contando despues del tope.
 * El estado es global porque el chassis es monohilo (un solo
 * CPUState activo); no hay cerrojos. Desactivada por defecto:
 * el HLE la activa al cargar un juego. */
void sfa_hw_trace_set_enabled(int enabled);
void sfa_hw_trace_reset(void);
unsigned long long sfa_hw_trace_total(void);
unsigned sfa_hw_trace_distinct(void);
/* CSV resumen: una fila por direccion, ordenada por total desc.
 * Devuelve 0 si se escribio, -1 si no se pudo abrir el fichero. */
int sfa_hw_trace_write_csv(const char *path);
/* CSV detalle: los (maximo) 20 primeros eventos por direccion. */
int sfa_hw_trace_write_events_csv(const char *path);

/* Captura del stream FIFO GX (Fase 5b). Las mem_write* a
 * 0xCC008000 (WGPIPE) son el unico camino por el que el codigo
 * huesped alimenta a la GP: la traza HW solo guardaba el primer
 * valor por direccion, insuficiente para interpretar comandos.
 * Con la captura activa, cada escritura a la ventana del
 * write-gather pipe (0xCC008000-0xCC00801F; el SDK escribe la
 * matriz con psq_st y el segundo float va a 0xCC008004) anade
 * sus bytes en orden big-endian al bufer lineal (capacidad fija;
 * al llenarse se deja de anadir pero se sigue contando y se
 * marca overflow, nunca se sobrescribe en silencio). El bufer
 * es global monohilo como la traza (mismo motivo). Desactivada
 * por defecto; el test host la activa antes de correr el juego
 * y la vuelca a fichero para el parser GX offline. En la APK
 * futura el mismo bufer alimentara al parser en vivo por
 * frames (Reset entre frames), sin fichero. */
void sfa_fifo_capture_set_enabled(int enabled);
void sfa_fifo_capture_reset(void);
unsigned long long sfa_fifo_capture_count(void);
unsigned long long sfa_fifo_capture_overflow(void);
unsigned long long sfa_fifo_capture_capacity(void);
const u8 *sfa_fifo_capture_data(void);
int sfa_fifo_capture_write_file(const char *path);

/* Excepciones y control. */
void ppc_take_exception(CPUState *cpu, u32 exception, u32 vector, u32 srr0,
                        u32 srr1_info);
void ppc_program_exception(CPUState *cpu, u32 cause, u32 cia);
bool ppc_fp_available(CPUState *cpu, u32 cia);
void ppc_fallback_instruction(CPUState *cpu, u32 raw, u32 cia);
bool ppc_host_call(CPUState *cpu, u32 address);
bool ppc_native_region_available(CPUState *cpu, u32 start, u32 end);
void ppc_system_call_exception(CPUState *cpu, u32 cia);
void ppc_dsi_exception(CPUState *cpu, u32 ea, u32 cia, u32 dsisr);
void ppc_alignment_exception(CPUState *cpu, u32 ea, u32 cia);
u32 ppc_mftb(CPUState *cpu, u16 tbr, u32 cia);
void ppc_rfi(CPUState *cpu, u32 cia);
void ppc_dcbz_l(CPUState *cpu, u32 ea, u32 cia);
bool ppc_trap_condition(u8 to, u32 a, u32 b);
void ppc_fpscr_updated(CPUState *cpu);
void ppc_fpscr_control_updated(CPUState *cpu);
void ppc_mtfsb0_op(CPUState *cpu, u8 bit);
void ppc_mtfsb1_op(CPUState *cpu, u8 bit);
void ppc_memory_fence(void);

/* FP escalar. */
f64 ppc_approx_reciprocal(f64 value);
f64 ppc_approx_rsqrt(f64 value);
bool ppc_fres(CPUState *cpu, f64 value, f64 *result);
bool ppc_frsqrte(CPUState *cpu, f64 value, f64 *result);
bool ppc_fma(CPUState *cpu, f64 a, f64 c, f64 b, bool single,
             bool subtract, bool negative, f64 *output);
bool ppc_fctiw(CPUState *cpu, f64 value, bool toward_zero, u64 *result);
void ppc_fcmp(CPUState *cpu, u8 crfd, f64 a, f64 b, bool ordered);
void ppc_fadds(CPUState *cpu, u8 d, u8 a, u8 b);
void ppc_fsubs(CPUState *cpu, u8 d, u8 a, u8 b);
void ppc_fmuls(CPUState *cpu, u8 d, u8 a, u8 c);
void ppc_fdivs(CPUState *cpu, u8 d, u8 a, u8 b);
void ppc_fadd(CPUState *cpu, u8 d, u8 a, u8 b);
void ppc_fsub(CPUState *cpu, u8 d, u8 a, u8 b);
void ppc_fmul(CPUState *cpu, u8 d, u8 a, u8 c);
void ppc_fdiv(CPUState *cpu, u8 d, u8 a, u8 b);
void ppc_frsp(CPUState *cpu, u8 d, u8 b);

/* Paired-single (Gekko). */
void ppc_ps_res(CPUState *cpu, f64 a, f64 b, f64 *result_a, f64 *result_b);
void ppc_ps_rsqrte(CPUState *cpu, f64 a, f64 b, f64 *result_a, f64 *result_b);
void ppc_ps_add_op(CPUState *cpu, u8 d, u8 a, u8 b);
void ppc_ps_sub_op(CPUState *cpu, u8 d, u8 a, u8 b);
void ppc_ps_mul_op(CPUState *cpu, u8 d, u8 a, u8 c);
void ppc_ps_div_op(CPUState *cpu, u8 d, u8 a, u8 b);
void ppc_ps_madd_op(CPUState *cpu, u8 d, u8 a, u8 c, u8 b,
                    bool subtract, bool negative);
void ppc_ps_madds0(CPUState *cpu, u8 d, u8 a, u8 c, u8 b);
void ppc_ps_madds1(CPUState *cpu, u8 d, u8 a, u8 c, u8 b);
void ppc_ps_sum0(CPUState *cpu, u8 d, u8 a, u8 c, u8 b);
void ppc_ps_sum1(CPUState *cpu, u8 d, u8 a, u8 c, u8 b);
void ppc_ps_muls0(CPUState *cpu, u8 d, u8 a, u8 c);
void ppc_ps_muls1(CPUState *cpu, u8 d, u8 a, u8 c);
void ppc_ps_res_op(CPUState *cpu, u8 d, u8 b);
void ppc_ps_rsqrte_op(CPUState *cpu, u8 d, u8 b);

/* Carga/almacenamiento cuantificado (psq_l/psq_st) y miscelanea. */
bool ppc_psq_load(CPUState *cpu, u8 frD, u32 ea, bool w, u8 gqr,
                  bool indexed, u32 cia);
bool ppc_psq_store(CPUState *cpu, u8 frS, u32 ea, bool w, u8 gqr,
                   bool indexed, u32 cia);
void ppc_stwcx_op(CPUState *cpu, u8 s, u32 ea, u32 cia);
void ppc_lswx(CPUState *cpu, u8 rD, u8 rA, u8 rB, u32 cia);
void ppc_cache_control(CPUState *cpu, u8 operation, u32 ea, u32 cia);
u32 ppc_eciwx(CPUState *cpu, u32 ea, u32 cia);
void ppc_ecowx(CPUState *cpu, u32 ea, u32 value, u32 cia);
void ppc_tlbie(CPUState *cpu, u32 ea, u32 cia);
bool ppc_add_overflowed(u32 a, u32 b, u32 result);
void ppc_set_xer_ov(CPUState *cpu, bool ov);

/* Formas inline que emiten los chunks: reenvian a las funciones
 * reales. ppc_fp_available_inline es la guarda MSR[FP] rapida. */
static inline bool ppc_fp_available_inline(CPUState *cpu, u32 cia) {
    if (cpu->msr & 0x00002000u)
        return true;
    return ppc_fp_available(cpu, cia);
}

static inline bool ppc_psq_load_inline(CPUState *cpu, u8 frD, u32 ea, bool w,
                                       u8 gqr, bool indexed, u32 cia) {
    return ppc_psq_load(cpu, frD, ea, w, gqr, indexed, cia);
}

static inline bool ppc_psq_store_inline(CPUState *cpu, u8 frS, u32 ea, bool w,
                                        u8 gqr, bool indexed, u32 cia) {
    return ppc_psq_store(cpu, frS, ea, w, gqr, indexed, cia);
}

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* SFA_CPU_CPU_H */
