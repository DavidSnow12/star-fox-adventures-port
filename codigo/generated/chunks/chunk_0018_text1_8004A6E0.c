// DolRecomp output
#include "../generated.h"

static void loop_8004AE10(CPUState* ctx) {
label_8004AE10:
    ctx->downcount -= 9;
    // 8004AE10: rlwinm r0, r4, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 3u) & 0xFFFFFFF8u;
    }

    // 8004AE14: add   r9, r5, r0
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

    ctx->pc = 0x8004AE18u;
    // 8004AE18: lhz     r3, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

    // 8004AE1C: rlwinm r0, r8, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[8], 3u) & 0xFFFFFFF8u;
    }

    // 8004AE20: add   r8, r5, r0
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

    ctx->pc = 0x8004AE24u;
    // 8004AE24: sth     r3, 4(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

    ctx->pc = 0x8004AE28u;
    // 8004AE28: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x8004AE2Cu;
    // 8004AE2C: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 8004AE30: or   r8, r4, r4
    {
        ctx->gpr[8] = ctx->gpr[4] | ctx->gpr[4];
    }

    // 8004AE34: srawi r4, r8, 1
    {
        u32 sh = 1u;
        u32 value = ctx->gpr[8];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[4] = value;
        } else if (sh > 31) {
            ctx->gpr[4] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[4] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

    // 8004AE38: rlwinm r0, r4, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 3u) & 0xFFFFFFF8u;
    }

    ctx->pc = 0x8004AE3Cu;
    // 8004AE3C: lwzx    r0, r5, r0
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 8004AE40: cmplw   r0, r7
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[7]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 8004AE44: bc    12, 0, 0x8004AE10
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004AE10u;
                return;
            }
            goto label_8004AE10;
        }
    }

    ctx->pc = 0x8004AE48u;
}

static void loop_8004AF54(CPUState* ctx) {
label_8004AF54:
    ctx->downcount -= 9;
    // 8004AF54: rlwinm r0, r5, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 3u) & 0xFFFFFFF8u;
    }

    // 8004AF58: add   r8, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

    ctx->pc = 0x8004AF5Cu;
    // 8004AF5C: lhz     r4, 4(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(4);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

    // 8004AF60: rlwinm r0, r31, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[31], 3u) & 0xFFFFFFF8u;
    }

    // 8004AF64: add   r9, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

    ctx->pc = 0x8004AF68u;
    // 8004AF68: sth     r4, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

    ctx->pc = 0x8004AF6Cu;
    // 8004AF6C: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x8004AF70u;
    // 8004AF70: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 8004AF74: or   r31, r5, r5
    {
        ctx->gpr[31] = ctx->gpr[5] | ctx->gpr[5];
    }

    // 8004AF78: srawi r5, r31, 1
    {
        u32 sh = 1u;
        u32 value = ctx->gpr[31];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[5] = value;
        } else if (sh > 31) {
            ctx->gpr[5] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[5] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

    // 8004AF7C: rlwinm r0, r5, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 3u) & 0xFFFFFFF8u;
    }

    ctx->pc = 0x8004AF80u;
    // 8004AF80: lwzx    r0, r3, r0
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 8004AF84: cmplw   r0, r7
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[7]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 8004AF88: bc    12, 0, 0x8004AF54
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004AF54u;
                return;
            }
            goto label_8004AF54;
        }
    }

    ctx->pc = 0x8004AF8Cu;
}

static void loop_8004B070(CPUState* ctx) {
label_8004B070:
    ctx->downcount -= 9;
    // 8004B070: rlwinm r0, r4, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 3u) & 0xFFFFFFF8u;
    }

    // 8004B074: add   r9, r5, r0
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

    ctx->pc = 0x8004B078u;
    // 8004B078: lhz     r3, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

    // 8004B07C: rlwinm r0, r8, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[8], 3u) & 0xFFFFFFF8u;
    }

    // 8004B080: add   r8, r5, r0
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

    ctx->pc = 0x8004B084u;
    // 8004B084: sth     r3, 4(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

    ctx->pc = 0x8004B088u;
    // 8004B088: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x8004B08Cu;
    // 8004B08C: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 8004B090: or   r8, r4, r4
    {
        ctx->gpr[8] = ctx->gpr[4] | ctx->gpr[4];
    }

    // 8004B094: srawi r4, r8, 1
    {
        u32 sh = 1u;
        u32 value = ctx->gpr[8];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[4] = value;
        } else if (sh > 31) {
            ctx->gpr[4] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[4] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

    // 8004B098: rlwinm r0, r4, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 3u) & 0xFFFFFFF8u;
    }

    ctx->pc = 0x8004B09Cu;
    // 8004B09C: lwzx    r0, r5, r0
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 8004B0A0: cmplw   r0, r7
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[7]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 8004B0A4: bc    12, 0, 0x8004B070
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004B070u;
                return;
            }
            goto label_8004B070;
        }
    }

    ctx->pc = 0x8004B0A8u;
}

static void loop_8004B124(CPUState* ctx) {
label_8004B124:
    ctx->downcount -= 9;
    // 8004B124: rlwinm r0, r4, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 3u) & 0xFFFFFFF8u;
    }

    // 8004B128: add   r9, r5, r0
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

    ctx->pc = 0x8004B12Cu;
    // 8004B12C: lhz     r3, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

    // 8004B130: rlwinm r0, r8, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[8], 3u) & 0xFFFFFFF8u;
    }

    // 8004B134: add   r8, r5, r0
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

    ctx->pc = 0x8004B138u;
    // 8004B138: sth     r3, 4(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

    ctx->pc = 0x8004B13Cu;
    // 8004B13C: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x8004B140u;
    // 8004B140: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 8004B144: or   r8, r4, r4
    {
        ctx->gpr[8] = ctx->gpr[4] | ctx->gpr[4];
    }

    // 8004B148: srawi r4, r8, 1
    {
        u32 sh = 1u;
        u32 value = ctx->gpr[8];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[4] = value;
        } else if (sh > 31) {
            ctx->gpr[4] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[4] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

    // 8004B14C: rlwinm r0, r4, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 3u) & 0xFFFFFFF8u;
    }

    ctx->pc = 0x8004B150u;
    // 8004B150: lwzx    r0, r5, r0
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 8004B154: cmplw   r0, r7
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[7]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 8004B158: bc    12, 0, 0x8004B124
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004B124u;
                return;
            }
            goto label_8004B124;
        }
    }

    ctx->pc = 0x8004B15Cu;
}

static void loop_8004B348(CPUState* ctx) {
label_8004B348:
    ctx->downcount -= 6;
    ctx->pc = 0x8004B348u;
    // 8004B348: lwz     r4, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

    // 8004B34C: rlwinm r0, r5, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 4u) & 0xFFFFFFF0u;
    }

    // 8004B350: add   r4, r4, r0
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

    // 8004B354: rlwinm r0, r6, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x000000FFu;
    }

    ctx->pc = 0x8004B358u;
    // 8004B358: stb     r0, 13(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(13);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    // 8004B35C: or   r6, r5, r5
    {
        ctx->gpr[6] = ctx->gpr[5] | ctx->gpr[5];
    }

    ctx->pc = 0x8004B360u;
    // 8004B360: lbz     r5, 12(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

    // 8004B364: cmplwi  r5, 0x00FF
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(0x00FFu);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 8004B368: bc    4, 2, 0x8004B348
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004B348u;
                return;
            }
            goto label_8004B348;
        }
    }

    ctx->pc = 0x8004B36Cu;
}

static void loop_8004B534(CPUState* ctx) {
label_8004B534:
    ctx->downcount -= 52;
    // 8004B534: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

    ctx->pc = 0x8004B538u;
    // 8004B538: lwz     r10, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x8004B53Cu;
    // 8004B53C: stwx    r0, r10, r8
    {
        u32 ea = ctx->gpr[10] + ctx->gpr[8];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x8004B540u;
    // 8004B540: lwz     r11, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

    // 8004B544: addi    r10, r9, 14
    ctx->gpr[10] = ctx->gpr[9] + (u32)(s32)(14);

    ctx->pc = 0x8004B548u;
    // 8004B548: stbx    r0, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8004B54Cu;
    // 8004B54C: lwz     r11, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

    // 8004B550: addi    r10, r8, 8
    ctx->gpr[10] = ctx->gpr[8] + (u32)(s32)(8);

    ctx->pc = 0x8004B554u;
    // 8004B554: stwx    r0, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x8004B558u;
    // 8004B558: lwz     r11, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

    // 8004B55C: addi    r10, r9, 30
    ctx->gpr[10] = ctx->gpr[9] + (u32)(s32)(30);

    ctx->pc = 0x8004B560u;
    // 8004B560: stbx    r0, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8004B564u;
    // 8004B564: lwz     r11, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

    // 8004B568: addi    r10, r8, 16
    ctx->gpr[10] = ctx->gpr[8] + (u32)(s32)(16);

    ctx->pc = 0x8004B56Cu;
    // 8004B56C: stwx    r0, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x8004B570u;
    // 8004B570: lwz     r11, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

    // 8004B574: addi    r10, r9, 46
    ctx->gpr[10] = ctx->gpr[9] + (u32)(s32)(46);

    ctx->pc = 0x8004B578u;
    // 8004B578: stbx    r0, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8004B57Cu;
    // 8004B57C: lwz     r11, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

    // 8004B580: addi    r10, r8, 24
    ctx->gpr[10] = ctx->gpr[8] + (u32)(s32)(24);

    ctx->pc = 0x8004B584u;
    // 8004B584: stwx    r0, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x8004B588u;
    // 8004B588: lwz     r11, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

    // 8004B58C: addi    r10, r9, 62
    ctx->gpr[10] = ctx->gpr[9] + (u32)(s32)(62);

    ctx->pc = 0x8004B590u;
    // 8004B590: stbx    r0, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8004B594u;
    // 8004B594: lwz     r11, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

    // 8004B598: addi    r10, r8, 32
    ctx->gpr[10] = ctx->gpr[8] + (u32)(s32)(32);

    ctx->pc = 0x8004B59Cu;
    // 8004B59C: stwx    r0, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x8004B5A0u;
    // 8004B5A0: lwz     r11, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

    // 8004B5A4: addi    r10, r9, 78
    ctx->gpr[10] = ctx->gpr[9] + (u32)(s32)(78);

    ctx->pc = 0x8004B5A8u;
    // 8004B5A8: stbx    r0, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8004B5ACu;
    // 8004B5AC: lwz     r11, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

    // 8004B5B0: addi    r10, r8, 40
    ctx->gpr[10] = ctx->gpr[8] + (u32)(s32)(40);

    ctx->pc = 0x8004B5B4u;
    // 8004B5B4: stwx    r0, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x8004B5B8u;
    // 8004B5B8: lwz     r11, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

    // 8004B5BC: addi    r10, r9, 94
    ctx->gpr[10] = ctx->gpr[9] + (u32)(s32)(94);

    ctx->pc = 0x8004B5C0u;
    // 8004B5C0: stbx    r0, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8004B5C4u;
    // 8004B5C4: lwz     r11, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

    // 8004B5C8: addi    r10, r8, 48
    ctx->gpr[10] = ctx->gpr[8] + (u32)(s32)(48);

    ctx->pc = 0x8004B5CCu;
    // 8004B5CC: stwx    r0, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x8004B5D0u;
    // 8004B5D0: lwz     r11, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

    // 8004B5D4: addi    r10, r9, 110
    ctx->gpr[10] = ctx->gpr[9] + (u32)(s32)(110);

    ctx->pc = 0x8004B5D8u;
    // 8004B5D8: stbx    r0, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8004B5DCu;
    // 8004B5DC: lwz     r11, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

    // 8004B5E0: addi    r10, r8, 56
    ctx->gpr[10] = ctx->gpr[8] + (u32)(s32)(56);

    ctx->pc = 0x8004B5E4u;
    // 8004B5E4: stwx    r0, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x8004B5E8u;
    // 8004B5E8: lwz     r11, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

    // 8004B5EC: addi    r10, r9, 126
    ctx->gpr[10] = ctx->gpr[9] + (u32)(s32)(126);

    ctx->pc = 0x8004B5F0u;
    // 8004B5F0: stbx    r0, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    // 8004B5F4: addi    r8, r8, 64
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(64);

    // 8004B5F8: addi    r9, r9, 128
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(128);

    // 8004B5FC: addi    r3, r3, 8
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(8);

    // 8004B600: bc    16, 0, 0x8004B534
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004B534u;
                return;
            }
            goto label_8004B534;
        }
    }

    ctx->pc = 0x8004B604u;
}

static void loop_8004B61C(CPUState* ctx) {
label_8004B61C:
    ctx->downcount -= 8;
    ctx->pc = 0x8004B61Cu;
    // 8004B61C: lwz     r3, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x8004B620u;
    // 8004B620: stwx    r0, r3, r9
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[9];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x8004B624u;
    // 8004B624: lwz     r8, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

    // 8004B628: addi    r3, r10, 14
    ctx->gpr[3] = ctx->gpr[10] + (u32)(s32)(14);

    ctx->pc = 0x8004B62Cu;
    // 8004B62C: stbx    r0, r8, r3
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[3];
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    // 8004B630: addi    r9, r9, 8
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(8);

    // 8004B634: addi    r10, r10, 16
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(16);

    // 8004B638: bc    16, 0, 0x8004B61C
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004B61Cu;
                return;
            }
            goto label_8004B61C;
        }
    }

    ctx->pc = 0x8004B63Cu;
}

static void loop_8004B714(CPUState* ctx) {
label_8004B714:
    ctx->downcount -= 9;
    // 8004B714: rlwinm r0, r4, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 3u) & 0xFFFFFFF8u;
    }

    // 8004B718: add   r9, r5, r0
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

    ctx->pc = 0x8004B71Cu;
    // 8004B71C: lhz     r3, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

    // 8004B720: rlwinm r0, r8, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[8], 3u) & 0xFFFFFFF8u;
    }

    // 8004B724: add   r8, r5, r0
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

    ctx->pc = 0x8004B728u;
    // 8004B728: sth     r3, 4(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

    ctx->pc = 0x8004B72Cu;
    // 8004B72C: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x8004B730u;
    // 8004B730: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 8004B734: or   r8, r4, r4
    {
        ctx->gpr[8] = ctx->gpr[4] | ctx->gpr[4];
    }

    // 8004B738: srawi r4, r8, 1
    {
        u32 sh = 1u;
        u32 value = ctx->gpr[8];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[4] = value;
        } else if (sh > 31) {
            ctx->gpr[4] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[4] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

    // 8004B73C: rlwinm r0, r4, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 3u) & 0xFFFFFFF8u;
    }

    ctx->pc = 0x8004B740u;
    // 8004B740: lwzx    r0, r5, r0
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 8004B744: cmplw   r0, r7
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[7]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 8004B748: bc    12, 0, 0x8004B714
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004B714u;
                return;
            }
            goto label_8004B714;
        }
    }

    ctx->pc = 0x8004B74Cu;
}

static void loop_8004B964(CPUState* ctx) {
label_8004B964:
    ctx->downcount -= 3;
    ctx->pc = 0x8004B964u;
    // 8004B964: stb     r19, 0(r18)
    {
        u32 ea = ctx->gpr[18] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[19]);
    }

    // 8004B968: addi    r18, r18, 1
    ctx->gpr[18] = ctx->gpr[18] + (u32)(s32)(1);

    // 8004B96C: bc    16, 0, 0x8004B964
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004B964u;
                return;
            }
            goto label_8004B964;
        }
    }

    ctx->pc = 0x8004B970u;
}

static void loop_8004B980(CPUState* ctx) {
label_8004B980:
    ctx->downcount -= 3;
    ctx->pc = 0x8004B980u;
    // 8004B980: stb     r19, 0(r18)
    {
        u32 ea = ctx->gpr[18] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[19]);
    }

    // 8004B984: addi    r18, r18, 1
    ctx->gpr[18] = ctx->gpr[18] + (u32)(s32)(1);

    // 8004B988: bc    16, 0, 0x8004B980
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004B980u;
                return;
            }
            goto label_8004B980;
        }
    }

    ctx->pc = 0x8004B98Cu;
}

static void loop_8004B99C(CPUState* ctx) {
label_8004B99C:
    ctx->downcount -= 3;
    ctx->pc = 0x8004B99Cu;
    // 8004B99C: sth     r19, 0(r18)
    {
        u32 ea = ctx->gpr[18] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[19]);
    }

    // 8004B9A0: addi    r18, r18, 2
    ctx->gpr[18] = ctx->gpr[18] + (u32)(s32)(2);

    // 8004B9A4: bc    16, 0, 0x8004B99C
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004B99Cu;
                return;
            }
            goto label_8004B99C;
        }
    }

    ctx->pc = 0x8004B9A8u;
}

static void loop_8004B9B4(CPUState* ctx) {
label_8004B9B4:
    ctx->downcount -= 3;
    ctx->pc = 0x8004B9B4u;
    // 8004B9B4: stb     r19, 0(r18)
    {
        u32 ea = ctx->gpr[18] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[19]);
    }

    // 8004B9B8: addi    r18, r18, 1
    ctx->gpr[18] = ctx->gpr[18] + (u32)(s32)(1);

    // 8004B9BC: bc    16, 0, 0x8004B9B4
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004B9B4u;
                return;
            }
            goto label_8004B9B4;
        }
    }

    ctx->pc = 0x8004B9C0u;
}

static void loop_8004B9D0(CPUState* ctx) {
label_8004B9D0:
    ctx->downcount -= 3;
    ctx->pc = 0x8004B9D0u;
    // 8004B9D0: sth     r19, 0(r18)
    {
        u32 ea = ctx->gpr[18] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[19]);
    }

    // 8004B9D4: addi    r18, r18, 2
    ctx->gpr[18] = ctx->gpr[18] + (u32)(s32)(2);

    // 8004B9D8: bc    16, 0, 0x8004B9D0
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004B9D0u;
                return;
            }
            goto label_8004B9D0;
        }
    }

    ctx->pc = 0x8004B9DCu;
}

static void loop_8004B9E8(CPUState* ctx) {
label_8004B9E8:
    ctx->downcount -= 3;
    ctx->pc = 0x8004B9E8u;
    // 8004B9E8: stb     r19, 0(r18)
    {
        u32 ea = ctx->gpr[18] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[19]);
    }

    // 8004B9EC: addi    r18, r18, 1
    ctx->gpr[18] = ctx->gpr[18] + (u32)(s32)(1);

    // 8004B9F0: bc    16, 0, 0x8004B9E8
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004B9E8u;
                return;
            }
            goto label_8004B9E8;
        }
    }

    ctx->pc = 0x8004B9F4u;
}

static void loop_8004BAB0(CPUState* ctx) {
label_8004BAB0:
    ctx->downcount -= 18;
    ctx->pc = 0x8004BAB0u;
    // 8004BAB0: lbz     r18, 1(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1);
        ctx->gpr[18] = mem_read8(ctx, ea);
    }

    // 8004BAB4: subfic  r17, r7, 8
    {
        u64 res = (u64)(u32)(s32)(8) + (u64)(~ctx->gpr[7]) + 1u;
        ctx->gpr[17] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

    // 8004BAB8: slw   r18, r18, r17
    {
        u32 sh = ctx->gpr[17] & 0x3Fu;
        ctx->gpr[18] = sh > 31 ? 0u : (ctx->gpr[18] << sh);
    }

    ctx->pc = 0x8004BABCu;
    // 8004BABC: lbz     r17, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[17] = mem_read8(ctx, ea);
    }

    // 8004BAC0: rlwnm r17, r17, r15, 24, 31
    {
        ctx->gpr[17] = dolrecomp_rotl32(ctx->gpr[17], ctx->gpr[15]) & 0x000000FFu;
    }

    // 8004BAC4: or   r17, r17, r18
    {
        ctx->gpr[17] = ctx->gpr[17] | ctx->gpr[18];
    }

    // 8004BAC8: andi.   r17, r17, 0x0007
    {
        ctx->gpr[17] = ctx->gpr[17] & 0x0007u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[17];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

    ctx->pc = 0x8004BACCu;
    // 8004BACC: lbzx    r18, r29, r21
    {
        u32 ea = ctx->gpr[29] + ctx->gpr[21];
        ctx->gpr[18] = mem_read8(ctx, ea);
    }

    ctx->pc = 0x8004BAD0u;
    // 8004BAD0: stbx    r17, r30, r18
    {
        u32 ea = ctx->gpr[30] + ctx->gpr[18];
        mem_write8(ctx, ea, (u8)ctx->gpr[17]);
    }

    ctx->pc = 0x8004BAD4u;
    // 8004BAD4: lbzx    r18, r31, r17
    {
        u32 ea = ctx->gpr[31] + ctx->gpr[17];
        ctx->gpr[18] = mem_read8(ctx, ea);
    }

    // 8004BAD8: addi    r18, r18, 1
    ctx->gpr[18] = ctx->gpr[18] + (u32)(s32)(1);

    // 8004BADC: addi    r7, r7, 3
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(3);

    ctx->pc = 0x8004BAE0u;
    // 8004BAE0: stbx    r18, r31, r17
    {
        u32 ea = ctx->gpr[31] + ctx->gpr[17];
        mem_write8(ctx, ea, (u8)ctx->gpr[18]);
    }

    // 8004BAE4: srawi r17, r7, 3
    {
        u32 sh = 3u;
        u32 value = ctx->gpr[7];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[17] = value;
        } else if (sh > 31) {
            ctx->gpr[17] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[17] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

    // 8004BAE8: add   r3, r3, r17
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[17];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

    // 8004BAEC: andi.   r7, r7, 0x0007
    {
        ctx->gpr[7] = ctx->gpr[7] & 0x0007u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[7];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

    // 8004BAF0: subfic  r15, r7, 32
    {
        u64 res = (u64)(u32)(s32)(32) + (u64)(~ctx->gpr[7]) + 1u;
        ctx->gpr[15] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

    // 8004BAF4: addi    r21, r21, 1
    ctx->gpr[21] = ctx->gpr[21] + (u32)(s32)(1);

    // 8004BAF8: cmpw    r21, r25
    {
        s32 val_a = (s32)(ctx->gpr[21]);
        s32 val_b = (s32)(ctx->gpr[25]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 8004BAFC: bc    4, 2, 0x8004BAB0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004BAB0u;
                return;
            }
            goto label_8004BAB0;
        }
    }

    ctx->pc = 0x8004BB00u;
}

static void loop_8004BB94(CPUState* ctx) {
label_8004BB94:
    ctx->downcount -= 5;
    ctx->pc = 0x8004BB94u;
    // 8004BB94: lbzx    r30, r17, r29
    {
        u32 ea = ctx->gpr[17] + ctx->gpr[29];
        ctx->gpr[30] = mem_read8(ctx, ea);
    }

    // 8004BB98: addi    r30, r30, 1
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(1);

    ctx->pc = 0x8004BB9Cu;
    // 8004BB9C: stbx    r30, r17, r29
    {
        u32 ea = ctx->gpr[17] + ctx->gpr[29];
        mem_write8(ctx, ea, (u8)ctx->gpr[30]);
    }

    ctx->pc = 0x8004BBA0u;
    // 8004BBA0: stbx    r28, r27, r30
    {
        u32 ea = ctx->gpr[27] + ctx->gpr[30];
        mem_write8(ctx, ea, (u8)ctx->gpr[28]);
    }

    // 8004BBA4: addi    r31, r31, 1
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(1);

    // 8004BBA8: subf   r18, r17, r4
    {
        u32 a = ~ctx->gpr[17];
        u32 b = ctx->gpr[4];
        u32 res = a + b + 1u;
        ctx->gpr[18] = res;
    }

    // 8004BBAC: li      r22, 1
    ctx->gpr[22] = (u32)(s32)(1);

    // 8004BBB0: slw   r18, r22, r18
    {
        u32 sh = ctx->gpr[18] & 0x3Fu;
        ctx->gpr[18] = sh > 31 ? 0u : (ctx->gpr[22] << sh);
    }

    // 8004BBB4: cmpw    r31, r18
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(ctx->gpr[18]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 8004BBB8: bc    12, 0, 0x8004BB94
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004BB94u;
                return;
            }
            goto label_8004BB94;
        }
    }

    ctx->pc = 0x8004BBBCu;
}

static void loop_8004BE14(CPUState* ctx) {
label_8004BE14:
    ctx->downcount -= 10;
    // 8004BE14: add   r18, r30, r17
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[17];
        u32 res = a + b;
        ctx->gpr[18] = res;
    }

    // 8004BE18: add   r29, r18, r17
    {
        u32 a = ctx->gpr[18];
        u32 b = ctx->gpr[17];
        u32 res = a + b;
        ctx->gpr[29] = res;
    }

    ctx->pc = 0x8004BE1Cu;
    // 8004BE1C: lhz     r18, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[18] = mem_read16(ctx, ea);
    }

    // 8004BE20: addi    r18, r18, 1
    ctx->gpr[18] = ctx->gpr[18] + (u32)(s32)(1);

    ctx->pc = 0x8004BE24u;
    // 8004BE24: sth     r18, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[18]);
    }

    // 8004BE28: addi    r18, r18, -1
    ctx->gpr[18] = ctx->gpr[18] + (u32)(s32)(-1);

    // 8004BE2C: add   r29, r9, r18
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[18];
        u32 res = a + b;
        ctx->gpr[29] = res;
    }

    // 8004BE30: add   r29, r29, r18
    {
        u32 a = ctx->gpr[29];
        u32 b = ctx->gpr[18];
        u32 res = a + b;
        ctx->gpr[29] = res;
    }

    ctx->pc = 0x8004BE34u;
    // 8004BE34: sth     r28, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[28]);
    }

    // 8004BE38: addi    r31, r31, 1
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(1);

    // 8004BE3C: subf   r29, r17, r10
    {
        u32 a = ~ctx->gpr[17];
        u32 b = ctx->gpr[10];
        u32 res = a + b + 1u;
        ctx->gpr[29] = res;
    }

    // 8004BE40: li      r18, 1
    ctx->gpr[18] = (u32)(s32)(1);

    // 8004BE44: slw   r18, r18, r29
    {
        u32 sh = ctx->gpr[29] & 0x3Fu;
        ctx->gpr[18] = sh > 31 ? 0u : (ctx->gpr[18] << sh);
    }

    // 8004BE48: cmpw    r31, r18
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(ctx->gpr[18]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 8004BE4C: bc    12, 0, 0x8004BE14
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004BE14u;
                return;
            }
            goto label_8004BE14;
        }
    }

    ctx->pc = 0x8004BE50u;
}

static void loop_8004BEEC(CPUState* ctx) {
label_8004BEEC:
    ctx->downcount -= 8;
    // 8004BEEC: add   r18, r27, r17
    {
        u32 a = ctx->gpr[27];
        u32 b = ctx->gpr[17];
        u32 res = a + b;
        ctx->gpr[18] = res;
    }

    // 8004BEF0: add   r18, r18, r17
    {
        u32 a = ctx->gpr[18];
        u32 b = ctx->gpr[17];
        u32 res = a + b;
        ctx->gpr[18] = res;
    }

    ctx->pc = 0x8004BEF4u;
    // 8004BEF4: lhz     r28, 0(r18)
    {
        u32 ea = ctx->gpr[18] + (u32)(s32)(0);
        ctx->gpr[28] = mem_read16(ctx, ea);
    }

    // 8004BEF8: addi    r28, r28, 1
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(1);

    ctx->pc = 0x8004BEFCu;
    // 8004BEFC: sth     r28, 0(r18)
    {
        u32 ea = ctx->gpr[18] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[28]);
    }

    // 8004BF00: addi    r28, r28, -1
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(-1);

    ctx->pc = 0x8004BF04u;
    // 8004BF04: stbx    r26, r12, r28
    {
        u32 ea = ctx->gpr[12] + ctx->gpr[28];
        mem_write8(ctx, ea, (u8)ctx->gpr[26]);
    }

    // 8004BF08: addi    r31, r31, 1
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(1);

    // 8004BF0C: subf   r18, r17, r14
    {
        u32 a = ~ctx->gpr[17];
        u32 b = ctx->gpr[14];
        u32 res = a + b + 1u;
        ctx->gpr[18] = res;
    }

    // 8004BF10: li      r29, 1
    ctx->gpr[29] = (u32)(s32)(1);

    // 8004BF14: slw   r18, r29, r18
    {
        u32 sh = ctx->gpr[18] & 0x3Fu;
        ctx->gpr[18] = sh > 31 ? 0u : (ctx->gpr[29] << sh);
    }

    // 8004BF18: cmpw    r31, r18
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(ctx->gpr[18]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 8004BF1C: bc    12, 0, 0x8004BEEC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004BEECu;
                return;
            }
            goto label_8004BEEC;
        }
    }

    ctx->pc = 0x8004BF20u;
}

static void loop_8004C134(CPUState* ctx) {
label_8004C134:
    ctx->downcount -= 3;
    ctx->pc = 0x8004C134u;
    // 8004C134: lbzu     r16, 1(r23)
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(1);
        ctx->gpr[16] = mem_read8(ctx, ea);
        ctx->gpr[23] = ea;
    }

    ctx->pc = 0x8004C138u;
    // 8004C138: stbu     r16, 1(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1);
        mem_write8(ctx, ea, (u8)ctx->gpr[16]);
        ctx->gpr[5] = ea;
    }

    // 8004C13C: bc    16, 0, 0x8004C134
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004C134u;
                return;
            }
            goto label_8004C134;
        }
    }

    ctx->pc = 0x8004C140u;
}

void func_8004A6E0(CPUState* ctx) {
    switch (ctx->pc) {
    case 0x8004A6E0u: goto label_8004A6E0;
    case 0x8004A6E4u: goto label_8004A6E4;
    case 0x8004A6E8u: goto label_8004A6E8;
    case 0x8004A6ECu: goto label_8004A6EC;
    case 0x8004A6F0u: goto label_8004A6F0;
    case 0x8004A6F4u: goto label_8004A6F4;
    case 0x8004A6F8u: goto label_8004A6F8;
    case 0x8004A6FCu: goto label_8004A6FC;
    case 0x8004A700u: goto label_8004A700;
    case 0x8004A704u: goto label_8004A704;
    case 0x8004A708u: goto label_8004A708;
    case 0x8004A70Cu: goto label_8004A70C;
    case 0x8004A710u: goto label_8004A710;
    case 0x8004A714u: goto label_8004A714;
    case 0x8004A718u: goto label_8004A718;
    case 0x8004A71Cu: goto label_8004A71C;
    case 0x8004A720u: goto label_8004A720;
    case 0x8004A724u: goto label_8004A724;
    case 0x8004A728u: goto label_8004A728;
    case 0x8004A72Cu: goto label_8004A72C;
    case 0x8004A730u: goto label_8004A730;
    case 0x8004A734u: goto label_8004A734;
    case 0x8004A738u: goto label_8004A738;
    case 0x8004A73Cu: goto label_8004A73C;
    case 0x8004A740u: goto label_8004A740;
    case 0x8004A744u: goto label_8004A744;
    case 0x8004A748u: goto label_8004A748;
    case 0x8004A74Cu: goto label_8004A74C;
    case 0x8004A750u: goto label_8004A750;
    case 0x8004A754u: goto label_8004A754;
    case 0x8004A758u: goto label_8004A758;
    case 0x8004A75Cu: goto label_8004A75C;
    case 0x8004A760u: goto label_8004A760;
    case 0x8004A764u: goto label_8004A764;
    case 0x8004A768u: goto label_8004A768;
    case 0x8004A76Cu: goto label_8004A76C;
    case 0x8004A770u: goto label_8004A770;
    case 0x8004A774u: goto label_8004A774;
    case 0x8004A778u: goto label_8004A778;
    case 0x8004A77Cu: goto label_8004A77C;
    case 0x8004A780u: goto label_8004A780;
    case 0x8004A784u: goto label_8004A784;
    case 0x8004A788u: goto label_8004A788;
    case 0x8004A78Cu: goto label_8004A78C;
    case 0x8004A790u: goto label_8004A790;
    case 0x8004A794u: goto label_8004A794;
    case 0x8004A798u: goto label_8004A798;
    case 0x8004A79Cu: goto label_8004A79C;
    case 0x8004A7A0u: goto label_8004A7A0;
    case 0x8004A7A4u: goto label_8004A7A4;
    case 0x8004A7A8u: goto label_8004A7A8;
    case 0x8004A7ACu: goto label_8004A7AC;
    case 0x8004A7B0u: goto label_8004A7B0;
    case 0x8004A7B4u: goto label_8004A7B4;
    case 0x8004A7B8u: goto label_8004A7B8;
    case 0x8004A7BCu: goto label_8004A7BC;
    case 0x8004A7C0u: goto label_8004A7C0;
    case 0x8004A7C4u: goto label_8004A7C4;
    case 0x8004A7C8u: goto label_8004A7C8;
    case 0x8004A7CCu: goto label_8004A7CC;
    case 0x8004A7D0u: goto label_8004A7D0;
    case 0x8004A7D4u: goto label_8004A7D4;
    case 0x8004A7D8u: goto label_8004A7D8;
    case 0x8004A7DCu: goto label_8004A7DC;
    case 0x8004A7E0u: goto label_8004A7E0;
    case 0x8004A7E4u: goto label_8004A7E4;
    case 0x8004A7E8u: goto label_8004A7E8;
    case 0x8004A7ECu: goto label_8004A7EC;
    case 0x8004A7F0u: goto label_8004A7F0;
    case 0x8004A7F4u: goto label_8004A7F4;
    case 0x8004A7F8u: goto label_8004A7F8;
    case 0x8004A7FCu: goto label_8004A7FC;
    case 0x8004A800u: goto label_8004A800;
    case 0x8004A804u: goto label_8004A804;
    case 0x8004A808u: goto label_8004A808;
    case 0x8004A80Cu: goto label_8004A80C;
    case 0x8004A810u: goto label_8004A810;
    case 0x8004A814u: goto label_8004A814;
    case 0x8004A818u: goto label_8004A818;
    case 0x8004A81Cu: goto label_8004A81C;
    case 0x8004A820u: goto label_8004A820;
    case 0x8004A824u: goto label_8004A824;
    case 0x8004A828u: goto label_8004A828;
    case 0x8004A82Cu: goto label_8004A82C;
    case 0x8004A830u: goto label_8004A830;
    case 0x8004A834u: goto label_8004A834;
    case 0x8004A838u: goto label_8004A838;
    case 0x8004A83Cu: goto label_8004A83C;
    case 0x8004A840u: goto label_8004A840;
    case 0x8004A844u: goto label_8004A844;
    case 0x8004A848u: goto label_8004A848;
    case 0x8004A84Cu: goto label_8004A84C;
    case 0x8004A850u: goto label_8004A850;
    case 0x8004A854u: goto label_8004A854;
    case 0x8004A858u: goto label_8004A858;
    case 0x8004A85Cu: goto label_8004A85C;
    case 0x8004A860u: goto label_8004A860;
    case 0x8004A864u: goto label_8004A864;
    case 0x8004A868u: goto label_8004A868;
    case 0x8004A86Cu: goto label_8004A86C;
    case 0x8004A870u: goto label_8004A870;
    case 0x8004A874u: goto label_8004A874;
    case 0x8004A878u: goto label_8004A878;
    case 0x8004A87Cu: goto label_8004A87C;
    case 0x8004A880u: goto label_8004A880;
    case 0x8004A884u: goto label_8004A884;
    case 0x8004A888u: goto label_8004A888;
    case 0x8004A88Cu: goto label_8004A88C;
    case 0x8004A890u: goto label_8004A890;
    case 0x8004A894u: goto label_8004A894;
    case 0x8004A898u: goto label_8004A898;
    case 0x8004A89Cu: goto label_8004A89C;
    case 0x8004A8A0u: goto label_8004A8A0;
    case 0x8004A8A4u: goto label_8004A8A4;
    case 0x8004A8A8u: goto label_8004A8A8;
    case 0x8004A8ACu: goto label_8004A8AC;
    case 0x8004A8B0u: goto label_8004A8B0;
    case 0x8004A8B4u: goto label_8004A8B4;
    case 0x8004A8B8u: goto label_8004A8B8;
    case 0x8004A8BCu: goto label_8004A8BC;
    case 0x8004A8C0u: goto label_8004A8C0;
    case 0x8004A8C4u: goto label_8004A8C4;
    case 0x8004A8C8u: goto label_8004A8C8;
    case 0x8004A8CCu: goto label_8004A8CC;
    case 0x8004A8D0u: goto label_8004A8D0;
    case 0x8004A8D4u: goto label_8004A8D4;
    case 0x8004A8D8u: goto label_8004A8D8;
    case 0x8004A8DCu: goto label_8004A8DC;
    case 0x8004A8E0u: goto label_8004A8E0;
    case 0x8004A8E4u: goto label_8004A8E4;
    case 0x8004A8E8u: goto label_8004A8E8;
    case 0x8004A8ECu: goto label_8004A8EC;
    case 0x8004A8F0u: goto label_8004A8F0;
    case 0x8004A8F4u: goto label_8004A8F4;
    case 0x8004A8F8u: goto label_8004A8F8;
    case 0x8004A8FCu: goto label_8004A8FC;
    case 0x8004A900u: goto label_8004A900;
    case 0x8004A904u: goto label_8004A904;
    case 0x8004A908u: goto label_8004A908;
    case 0x8004A90Cu: goto label_8004A90C;
    case 0x8004A910u: goto label_8004A910;
    case 0x8004A914u: goto label_8004A914;
    case 0x8004A918u: goto label_8004A918;
    case 0x8004A91Cu: goto label_8004A91C;
    case 0x8004A920u: goto label_8004A920;
    case 0x8004A924u: goto label_8004A924;
    case 0x8004A928u: goto label_8004A928;
    case 0x8004A92Cu: goto label_8004A92C;
    case 0x8004A930u: goto label_8004A930;
    case 0x8004A934u: goto label_8004A934;
    case 0x8004A938u: goto label_8004A938;
    case 0x8004A93Cu: goto label_8004A93C;
    case 0x8004A940u: goto label_8004A940;
    case 0x8004A944u: goto label_8004A944;
    case 0x8004A948u: goto label_8004A948;
    case 0x8004A94Cu: goto label_8004A94C;
    case 0x8004A950u: goto label_8004A950;
    case 0x8004A954u: goto label_8004A954;
    case 0x8004A958u: goto label_8004A958;
    case 0x8004A95Cu: goto label_8004A95C;
    case 0x8004A960u: goto label_8004A960;
    case 0x8004A964u: goto label_8004A964;
    case 0x8004A968u: goto label_8004A968;
    case 0x8004A96Cu: goto label_8004A96C;
    case 0x8004A970u: goto label_8004A970;
    case 0x8004A974u: goto label_8004A974;
    case 0x8004A978u: goto label_8004A978;
    case 0x8004A97Cu: goto label_8004A97C;
    case 0x8004A980u: goto label_8004A980;
    case 0x8004A984u: goto label_8004A984;
    case 0x8004A988u: goto label_8004A988;
    case 0x8004A98Cu: goto label_8004A98C;
    case 0x8004A990u: goto label_8004A990;
    case 0x8004A994u: goto label_8004A994;
    case 0x8004A998u: goto label_8004A998;
    case 0x8004A99Cu: goto label_8004A99C;
    case 0x8004A9A0u: goto label_8004A9A0;
    case 0x8004A9A4u: goto label_8004A9A4;
    case 0x8004A9A8u: goto label_8004A9A8;
    case 0x8004A9ACu: goto label_8004A9AC;
    case 0x8004A9B0u: goto label_8004A9B0;
    case 0x8004A9B4u: goto label_8004A9B4;
    case 0x8004A9B8u: goto label_8004A9B8;
    case 0x8004A9BCu: goto label_8004A9BC;
    case 0x8004A9C0u: goto label_8004A9C0;
    case 0x8004A9C4u: goto label_8004A9C4;
    case 0x8004A9C8u: goto label_8004A9C8;
    case 0x8004A9CCu: goto label_8004A9CC;
    case 0x8004A9D0u: goto label_8004A9D0;
    case 0x8004A9D4u: goto label_8004A9D4;
    case 0x8004A9D8u: goto label_8004A9D8;
    case 0x8004A9DCu: goto label_8004A9DC;
    case 0x8004A9E0u: goto label_8004A9E0;
    case 0x8004A9E4u: goto label_8004A9E4;
    case 0x8004A9E8u: goto label_8004A9E8;
    case 0x8004A9ECu: goto label_8004A9EC;
    case 0x8004A9F0u: goto label_8004A9F0;
    case 0x8004A9F4u: goto label_8004A9F4;
    case 0x8004A9F8u: goto label_8004A9F8;
    case 0x8004A9FCu: goto label_8004A9FC;
    case 0x8004AA00u: goto label_8004AA00;
    case 0x8004AA04u: goto label_8004AA04;
    case 0x8004AA08u: goto label_8004AA08;
    case 0x8004AA0Cu: goto label_8004AA0C;
    case 0x8004AA10u: goto label_8004AA10;
    case 0x8004AA14u: goto label_8004AA14;
    case 0x8004AA18u: goto label_8004AA18;
    case 0x8004AA1Cu: goto label_8004AA1C;
    case 0x8004AA20u: goto label_8004AA20;
    case 0x8004AA24u: goto label_8004AA24;
    case 0x8004AA28u: goto label_8004AA28;
    case 0x8004AA2Cu: goto label_8004AA2C;
    case 0x8004AA30u: goto label_8004AA30;
    case 0x8004AA34u: goto label_8004AA34;
    case 0x8004AA38u: goto label_8004AA38;
    case 0x8004AA3Cu: goto label_8004AA3C;
    case 0x8004AA40u: goto label_8004AA40;
    case 0x8004AA44u: goto label_8004AA44;
    case 0x8004AA48u: goto label_8004AA48;
    case 0x8004AA4Cu: goto label_8004AA4C;
    case 0x8004AA50u: goto label_8004AA50;
    case 0x8004AA54u: goto label_8004AA54;
    case 0x8004AA58u: goto label_8004AA58;
    case 0x8004AA5Cu: goto label_8004AA5C;
    case 0x8004AA60u: goto label_8004AA60;
    case 0x8004AA64u: goto label_8004AA64;
    case 0x8004AA68u: goto label_8004AA68;
    case 0x8004AA6Cu: goto label_8004AA6C;
    case 0x8004AA70u: goto label_8004AA70;
    case 0x8004AA74u: goto label_8004AA74;
    case 0x8004AA78u: goto label_8004AA78;
    case 0x8004AA7Cu: goto label_8004AA7C;
    case 0x8004AA80u: goto label_8004AA80;
    case 0x8004AA84u: goto label_8004AA84;
    case 0x8004AA88u: goto label_8004AA88;
    case 0x8004AA8Cu: goto label_8004AA8C;
    case 0x8004AA90u: goto label_8004AA90;
    case 0x8004AA94u: goto label_8004AA94;
    case 0x8004AA98u: goto label_8004AA98;
    case 0x8004AA9Cu: goto label_8004AA9C;
    case 0x8004AAA0u: goto label_8004AAA0;
    case 0x8004AAA4u: goto label_8004AAA4;
    case 0x8004AAA8u: goto label_8004AAA8;
    case 0x8004AAACu: goto label_8004AAAC;
    case 0x8004AAB0u: goto label_8004AAB0;
    case 0x8004AAB4u: goto label_8004AAB4;
    case 0x8004AAB8u: goto label_8004AAB8;
    case 0x8004AABCu: goto label_8004AABC;
    case 0x8004AAC0u: goto label_8004AAC0;
    case 0x8004AAC4u: goto label_8004AAC4;
    case 0x8004AAC8u: goto label_8004AAC8;
    case 0x8004AACCu: goto label_8004AACC;
    case 0x8004AAD0u: goto label_8004AAD0;
    case 0x8004AAD4u: goto label_8004AAD4;
    case 0x8004AAD8u: goto label_8004AAD8;
    case 0x8004AADCu: goto label_8004AADC;
    case 0x8004AAE0u: goto label_8004AAE0;
    case 0x8004AAE4u: goto label_8004AAE4;
    case 0x8004AAE8u: goto label_8004AAE8;
    case 0x8004AAECu: goto label_8004AAEC;
    case 0x8004AAF0u: goto label_8004AAF0;
    case 0x8004AAF4u: goto label_8004AAF4;
    case 0x8004AAF8u: goto label_8004AAF8;
    case 0x8004AAFCu: goto label_8004AAFC;
    case 0x8004AB00u: goto label_8004AB00;
    case 0x8004AB04u: goto label_8004AB04;
    case 0x8004AB08u: goto label_8004AB08;
    case 0x8004AB0Cu: goto label_8004AB0C;
    case 0x8004AB10u: goto label_8004AB10;
    case 0x8004AB14u: goto label_8004AB14;
    case 0x8004AB18u: goto label_8004AB18;
    case 0x8004AB1Cu: goto label_8004AB1C;
    case 0x8004AB20u: goto label_8004AB20;
    case 0x8004AB24u: goto label_8004AB24;
    case 0x8004AB28u: goto label_8004AB28;
    case 0x8004AB2Cu: goto label_8004AB2C;
    case 0x8004AB30u: goto label_8004AB30;
    case 0x8004AB34u: goto label_8004AB34;
    case 0x8004AB38u: goto label_8004AB38;
    case 0x8004AB3Cu: goto label_8004AB3C;
    case 0x8004AB40u: goto label_8004AB40;
    case 0x8004AB44u: goto label_8004AB44;
    case 0x8004AB48u: goto label_8004AB48;
    case 0x8004AB4Cu: goto label_8004AB4C;
    case 0x8004AB50u: goto label_8004AB50;
    case 0x8004AB54u: goto label_8004AB54;
    case 0x8004AB58u: goto label_8004AB58;
    case 0x8004AB5Cu: goto label_8004AB5C;
    case 0x8004AB60u: goto label_8004AB60;
    case 0x8004AB64u: goto label_8004AB64;
    case 0x8004AB68u: goto label_8004AB68;
    case 0x8004AB6Cu: goto label_8004AB6C;
    case 0x8004AB70u: goto label_8004AB70;
    case 0x8004AB74u: goto label_8004AB74;
    case 0x8004AB78u: goto label_8004AB78;
    case 0x8004AB7Cu: goto label_8004AB7C;
    case 0x8004AB80u: goto label_8004AB80;
    case 0x8004AB84u: goto label_8004AB84;
    case 0x8004AB88u: goto label_8004AB88;
    case 0x8004AB8Cu: goto label_8004AB8C;
    case 0x8004AB90u: goto label_8004AB90;
    case 0x8004AB94u: goto label_8004AB94;
    case 0x8004AB98u: goto label_8004AB98;
    case 0x8004AB9Cu: goto label_8004AB9C;
    case 0x8004ABA0u: goto label_8004ABA0;
    case 0x8004ABA4u: goto label_8004ABA4;
    case 0x8004ABA8u: goto label_8004ABA8;
    case 0x8004ABACu: goto label_8004ABAC;
    case 0x8004ABB0u: goto label_8004ABB0;
    case 0x8004ABB4u: goto label_8004ABB4;
    case 0x8004ABB8u: goto label_8004ABB8;
    case 0x8004ABBCu: goto label_8004ABBC;
    case 0x8004ABC0u: goto label_8004ABC0;
    case 0x8004ABC4u: goto label_8004ABC4;
    case 0x8004ABC8u: goto label_8004ABC8;
    case 0x8004ABCCu: goto label_8004ABCC;
    case 0x8004ABD0u: goto label_8004ABD0;
    case 0x8004ABD4u: goto label_8004ABD4;
    case 0x8004ABD8u: goto label_8004ABD8;
    case 0x8004ABDCu: goto label_8004ABDC;
    case 0x8004ABE0u: goto label_8004ABE0;
    case 0x8004ABE4u: goto label_8004ABE4;
    case 0x8004ABE8u: goto label_8004ABE8;
    case 0x8004ABECu: goto label_8004ABEC;
    case 0x8004ABF0u: goto label_8004ABF0;
    case 0x8004ABF4u: goto label_8004ABF4;
    case 0x8004ABF8u: goto label_8004ABF8;
    case 0x8004ABFCu: goto label_8004ABFC;
    case 0x8004AC00u: goto label_8004AC00;
    case 0x8004AC04u: goto label_8004AC04;
    case 0x8004AC08u: goto label_8004AC08;
    case 0x8004AC0Cu: goto label_8004AC0C;
    case 0x8004AC10u: goto label_8004AC10;
    case 0x8004AC14u: goto label_8004AC14;
    case 0x8004AC18u: goto label_8004AC18;
    case 0x8004AC1Cu: goto label_8004AC1C;
    case 0x8004AC20u: goto label_8004AC20;
    case 0x8004AC24u: goto label_8004AC24;
    case 0x8004AC28u: goto label_8004AC28;
    case 0x8004AC2Cu: goto label_8004AC2C;
    case 0x8004AC30u: goto label_8004AC30;
    case 0x8004AC34u: goto label_8004AC34;
    case 0x8004AC38u: goto label_8004AC38;
    case 0x8004AC3Cu: goto label_8004AC3C;
    case 0x8004AC40u: goto label_8004AC40;
    case 0x8004AC44u: goto label_8004AC44;
    case 0x8004AC48u: goto label_8004AC48;
    case 0x8004AC4Cu: goto label_8004AC4C;
    case 0x8004AC50u: goto label_8004AC50;
    case 0x8004AC54u: goto label_8004AC54;
    case 0x8004AC58u: goto label_8004AC58;
    case 0x8004AC5Cu: goto label_8004AC5C;
    case 0x8004AC60u: goto label_8004AC60;
    case 0x8004AC64u: goto label_8004AC64;
    case 0x8004AC68u: goto label_8004AC68;
    case 0x8004AC6Cu: goto label_8004AC6C;
    case 0x8004AC70u: goto label_8004AC70;
    case 0x8004AC74u: goto label_8004AC74;
    case 0x8004AC78u: goto label_8004AC78;
    case 0x8004AC7Cu: goto label_8004AC7C;
    case 0x8004AC80u: goto label_8004AC80;
    case 0x8004AC84u: goto label_8004AC84;
    case 0x8004AC88u: goto label_8004AC88;
    case 0x8004AC8Cu: goto label_8004AC8C;
    case 0x8004AC90u: goto label_8004AC90;
    case 0x8004AC94u: goto label_8004AC94;
    case 0x8004AC98u: goto label_8004AC98;
    case 0x8004AC9Cu: goto label_8004AC9C;
    case 0x8004ACA0u: goto label_8004ACA0;
    case 0x8004ACA4u: goto label_8004ACA4;
    case 0x8004ACA8u: goto label_8004ACA8;
    case 0x8004ACACu: goto label_8004ACAC;
    case 0x8004ACB0u: goto label_8004ACB0;
    case 0x8004ACB4u: goto label_8004ACB4;
    case 0x8004ACB8u: goto label_8004ACB8;
    case 0x8004ACBCu: goto label_8004ACBC;
    case 0x8004ACC0u: goto label_8004ACC0;
    case 0x8004ACC4u: goto label_8004ACC4;
    case 0x8004ACC8u: goto label_8004ACC8;
    case 0x8004ACCCu: goto label_8004ACCC;
    case 0x8004ACD0u: goto label_8004ACD0;
    case 0x8004ACD4u: goto label_8004ACD4;
    case 0x8004ACD8u: goto label_8004ACD8;
    case 0x8004ACDCu: goto label_8004ACDC;
    case 0x8004ACE0u: goto label_8004ACE0;
    case 0x8004ACE4u: goto label_8004ACE4;
    case 0x8004ACE8u: goto label_8004ACE8;
    case 0x8004ACECu: goto label_8004ACEC;
    case 0x8004ACF0u: goto label_8004ACF0;
    case 0x8004ACF4u: goto label_8004ACF4;
    case 0x8004ACF8u: goto label_8004ACF8;
    case 0x8004ACFCu: goto label_8004ACFC;
    case 0x8004AD00u: goto label_8004AD00;
    case 0x8004AD04u: goto label_8004AD04;
    case 0x8004AD08u: goto label_8004AD08;
    case 0x8004AD0Cu: goto label_8004AD0C;
    case 0x8004AD10u: goto label_8004AD10;
    case 0x8004AD14u: goto label_8004AD14;
    case 0x8004AD18u: goto label_8004AD18;
    case 0x8004AD1Cu: goto label_8004AD1C;
    case 0x8004AD20u: goto label_8004AD20;
    case 0x8004AD24u: goto label_8004AD24;
    case 0x8004AD28u: goto label_8004AD28;
    case 0x8004AD2Cu: goto label_8004AD2C;
    case 0x8004AD30u: goto label_8004AD30;
    case 0x8004AD34u: goto label_8004AD34;
    case 0x8004AD38u: goto label_8004AD38;
    case 0x8004AD3Cu: goto label_8004AD3C;
    case 0x8004AD40u: goto label_8004AD40;
    case 0x8004AD44u: goto label_8004AD44;
    case 0x8004AD48u: goto label_8004AD48;
    case 0x8004AD4Cu: goto label_8004AD4C;
    case 0x8004AD50u: goto label_8004AD50;
    case 0x8004AD54u: goto label_8004AD54;
    case 0x8004AD58u: goto label_8004AD58;
    case 0x8004AD5Cu: goto label_8004AD5C;
    case 0x8004AD60u: goto label_8004AD60;
    case 0x8004AD64u: goto label_8004AD64;
    case 0x8004AD68u: goto label_8004AD68;
    case 0x8004AD6Cu: goto label_8004AD6C;
    case 0x8004AD70u: goto label_8004AD70;
    case 0x8004AD74u: goto label_8004AD74;
    case 0x8004AD78u: goto label_8004AD78;
    case 0x8004AD7Cu: goto label_8004AD7C;
    case 0x8004AD80u: goto label_8004AD80;
    case 0x8004AD84u: goto label_8004AD84;
    case 0x8004AD88u: goto label_8004AD88;
    case 0x8004AD8Cu: goto label_8004AD8C;
    case 0x8004AD90u: goto label_8004AD90;
    case 0x8004AD94u: goto label_8004AD94;
    case 0x8004AD98u: goto label_8004AD98;
    case 0x8004AD9Cu: goto label_8004AD9C;
    case 0x8004ADA0u: goto label_8004ADA0;
    case 0x8004ADA4u: goto label_8004ADA4;
    case 0x8004ADA8u: goto label_8004ADA8;
    case 0x8004ADACu: goto label_8004ADAC;
    case 0x8004ADB0u: goto label_8004ADB0;
    case 0x8004ADB4u: goto label_8004ADB4;
    case 0x8004ADB8u: goto label_8004ADB8;
    case 0x8004ADBCu: goto label_8004ADBC;
    case 0x8004ADC0u: goto label_8004ADC0;
    case 0x8004ADC4u: goto label_8004ADC4;
    case 0x8004ADC8u: goto label_8004ADC8;
    case 0x8004ADCCu: goto label_8004ADCC;
    case 0x8004ADD0u: goto label_8004ADD0;
    case 0x8004ADD4u: goto label_8004ADD4;
    case 0x8004ADD8u: goto label_8004ADD8;
    case 0x8004ADDCu: goto label_8004ADDC;
    case 0x8004ADE0u: goto label_8004ADE0;
    case 0x8004ADE4u: goto label_8004ADE4;
    case 0x8004ADE8u: goto label_8004ADE8;
    case 0x8004ADECu: goto label_8004ADEC;
    case 0x8004ADF0u: goto label_8004ADF0;
    case 0x8004ADF4u: goto label_8004ADF4;
    case 0x8004ADF8u: goto label_8004ADF8;
    case 0x8004ADFCu: goto label_8004ADFC;
    case 0x8004AE00u: goto label_8004AE00;
    case 0x8004AE04u: goto label_8004AE04;
    case 0x8004AE08u: goto label_8004AE08;
    case 0x8004AE0Cu: goto label_8004AE0C;
    case 0x8004AE10u: goto label_8004AE10;
    case 0x8004AE14u: goto label_8004AE14;
    case 0x8004AE18u: goto label_8004AE18;
    case 0x8004AE1Cu: goto label_8004AE1C;
    case 0x8004AE20u: goto label_8004AE20;
    case 0x8004AE24u: goto label_8004AE24;
    case 0x8004AE28u: goto label_8004AE28;
    case 0x8004AE2Cu: goto label_8004AE2C;
    case 0x8004AE30u: goto label_8004AE30;
    case 0x8004AE34u: goto label_8004AE34;
    case 0x8004AE38u: goto label_8004AE38;
    case 0x8004AE3Cu: goto label_8004AE3C;
    case 0x8004AE40u: goto label_8004AE40;
    case 0x8004AE44u: goto label_8004AE44;
    case 0x8004AE48u: goto label_8004AE48;
    case 0x8004AE4Cu: goto label_8004AE4C;
    case 0x8004AE50u: goto label_8004AE50;
    case 0x8004AE54u: goto label_8004AE54;
    case 0x8004AE58u: goto label_8004AE58;
    case 0x8004AE5Cu: goto label_8004AE5C;
    case 0x8004AE60u: goto label_8004AE60;
    case 0x8004AE64u: goto label_8004AE64;
    case 0x8004AE68u: goto label_8004AE68;
    case 0x8004AE6Cu: goto label_8004AE6C;
    case 0x8004AE70u: goto label_8004AE70;
    case 0x8004AE74u: goto label_8004AE74;
    case 0x8004AE78u: goto label_8004AE78;
    case 0x8004AE7Cu: goto label_8004AE7C;
    case 0x8004AE80u: goto label_8004AE80;
    case 0x8004AE84u: goto label_8004AE84;
    case 0x8004AE88u: goto label_8004AE88;
    case 0x8004AE8Cu: goto label_8004AE8C;
    case 0x8004AE90u: goto label_8004AE90;
    case 0x8004AE94u: goto label_8004AE94;
    case 0x8004AE98u: goto label_8004AE98;
    case 0x8004AE9Cu: goto label_8004AE9C;
    case 0x8004AEA0u: goto label_8004AEA0;
    case 0x8004AEA4u: goto label_8004AEA4;
    case 0x8004AEA8u: goto label_8004AEA8;
    case 0x8004AEACu: goto label_8004AEAC;
    case 0x8004AEB0u: goto label_8004AEB0;
    case 0x8004AEB4u: goto label_8004AEB4;
    case 0x8004AEB8u: goto label_8004AEB8;
    case 0x8004AEBCu: goto label_8004AEBC;
    case 0x8004AEC0u: goto label_8004AEC0;
    case 0x8004AEC4u: goto label_8004AEC4;
    case 0x8004AEC8u: goto label_8004AEC8;
    case 0x8004AECCu: goto label_8004AECC;
    case 0x8004AED0u: goto label_8004AED0;
    case 0x8004AED4u: goto label_8004AED4;
    case 0x8004AED8u: goto label_8004AED8;
    case 0x8004AEDCu: goto label_8004AEDC;
    case 0x8004AEE0u: goto label_8004AEE0;
    case 0x8004AEE4u: goto label_8004AEE4;
    case 0x8004AEE8u: goto label_8004AEE8;
    case 0x8004AEECu: goto label_8004AEEC;
    case 0x8004AEF0u: goto label_8004AEF0;
    case 0x8004AEF4u: goto label_8004AEF4;
    case 0x8004AEF8u: goto label_8004AEF8;
    case 0x8004AEFCu: goto label_8004AEFC;
    case 0x8004AF00u: goto label_8004AF00;
    case 0x8004AF04u: goto label_8004AF04;
    case 0x8004AF08u: goto label_8004AF08;
    case 0x8004AF0Cu: goto label_8004AF0C;
    case 0x8004AF10u: goto label_8004AF10;
    case 0x8004AF14u: goto label_8004AF14;
    case 0x8004AF18u: goto label_8004AF18;
    case 0x8004AF1Cu: goto label_8004AF1C;
    case 0x8004AF20u: goto label_8004AF20;
    case 0x8004AF24u: goto label_8004AF24;
    case 0x8004AF28u: goto label_8004AF28;
    case 0x8004AF2Cu: goto label_8004AF2C;
    case 0x8004AF30u: goto label_8004AF30;
    case 0x8004AF34u: goto label_8004AF34;
    case 0x8004AF38u: goto label_8004AF38;
    case 0x8004AF3Cu: goto label_8004AF3C;
    case 0x8004AF40u: goto label_8004AF40;
    case 0x8004AF44u: goto label_8004AF44;
    case 0x8004AF48u: goto label_8004AF48;
    case 0x8004AF4Cu: goto label_8004AF4C;
    case 0x8004AF50u: goto label_8004AF50;
    case 0x8004AF54u: goto label_8004AF54;
    case 0x8004AF58u: goto label_8004AF58;
    case 0x8004AF5Cu: goto label_8004AF5C;
    case 0x8004AF60u: goto label_8004AF60;
    case 0x8004AF64u: goto label_8004AF64;
    case 0x8004AF68u: goto label_8004AF68;
    case 0x8004AF6Cu: goto label_8004AF6C;
    case 0x8004AF70u: goto label_8004AF70;
    case 0x8004AF74u: goto label_8004AF74;
    case 0x8004AF78u: goto label_8004AF78;
    case 0x8004AF7Cu: goto label_8004AF7C;
    case 0x8004AF80u: goto label_8004AF80;
    case 0x8004AF84u: goto label_8004AF84;
    case 0x8004AF88u: goto label_8004AF88;
    case 0x8004AF8Cu: goto label_8004AF8C;
    case 0x8004AF90u: goto label_8004AF90;
    case 0x8004AF94u: goto label_8004AF94;
    case 0x8004AF98u: goto label_8004AF98;
    case 0x8004AF9Cu: goto label_8004AF9C;
    case 0x8004AFA0u: goto label_8004AFA0;
    case 0x8004AFA4u: goto label_8004AFA4;
    case 0x8004AFA8u: goto label_8004AFA8;
    case 0x8004AFACu: goto label_8004AFAC;
    case 0x8004AFB0u: goto label_8004AFB0;
    case 0x8004AFB4u: goto label_8004AFB4;
    case 0x8004AFB8u: goto label_8004AFB8;
    case 0x8004AFBCu: goto label_8004AFBC;
    case 0x8004AFC0u: goto label_8004AFC0;
    case 0x8004AFC4u: goto label_8004AFC4;
    case 0x8004AFC8u: goto label_8004AFC8;
    case 0x8004AFCCu: goto label_8004AFCC;
    case 0x8004AFD0u: goto label_8004AFD0;
    case 0x8004AFD4u: goto label_8004AFD4;
    case 0x8004AFD8u: goto label_8004AFD8;
    case 0x8004AFDCu: goto label_8004AFDC;
    case 0x8004AFE0u: goto label_8004AFE0;
    case 0x8004AFE4u: goto label_8004AFE4;
    case 0x8004AFE8u: goto label_8004AFE8;
    case 0x8004AFECu: goto label_8004AFEC;
    case 0x8004AFF0u: goto label_8004AFF0;
    case 0x8004AFF4u: goto label_8004AFF4;
    case 0x8004AFF8u: goto label_8004AFF8;
    case 0x8004AFFCu: goto label_8004AFFC;
    case 0x8004B000u: goto label_8004B000;
    case 0x8004B004u: goto label_8004B004;
    case 0x8004B008u: goto label_8004B008;
    case 0x8004B00Cu: goto label_8004B00C;
    case 0x8004B010u: goto label_8004B010;
    case 0x8004B014u: goto label_8004B014;
    case 0x8004B018u: goto label_8004B018;
    case 0x8004B01Cu: goto label_8004B01C;
    case 0x8004B020u: goto label_8004B020;
    case 0x8004B024u: goto label_8004B024;
    case 0x8004B028u: goto label_8004B028;
    case 0x8004B02Cu: goto label_8004B02C;
    case 0x8004B030u: goto label_8004B030;
    case 0x8004B034u: goto label_8004B034;
    case 0x8004B038u: goto label_8004B038;
    case 0x8004B03Cu: goto label_8004B03C;
    case 0x8004B040u: goto label_8004B040;
    case 0x8004B044u: goto label_8004B044;
    case 0x8004B048u: goto label_8004B048;
    case 0x8004B04Cu: goto label_8004B04C;
    case 0x8004B050u: goto label_8004B050;
    case 0x8004B054u: goto label_8004B054;
    case 0x8004B058u: goto label_8004B058;
    case 0x8004B05Cu: goto label_8004B05C;
    case 0x8004B060u: goto label_8004B060;
    case 0x8004B064u: goto label_8004B064;
    case 0x8004B068u: goto label_8004B068;
    case 0x8004B06Cu: goto label_8004B06C;
    case 0x8004B070u: goto label_8004B070;
    case 0x8004B074u: goto label_8004B074;
    case 0x8004B078u: goto label_8004B078;
    case 0x8004B07Cu: goto label_8004B07C;
    case 0x8004B080u: goto label_8004B080;
    case 0x8004B084u: goto label_8004B084;
    case 0x8004B088u: goto label_8004B088;
    case 0x8004B08Cu: goto label_8004B08C;
    case 0x8004B090u: goto label_8004B090;
    case 0x8004B094u: goto label_8004B094;
    case 0x8004B098u: goto label_8004B098;
    case 0x8004B09Cu: goto label_8004B09C;
    case 0x8004B0A0u: goto label_8004B0A0;
    case 0x8004B0A4u: goto label_8004B0A4;
    case 0x8004B0A8u: goto label_8004B0A8;
    case 0x8004B0ACu: goto label_8004B0AC;
    case 0x8004B0B0u: goto label_8004B0B0;
    case 0x8004B0B4u: goto label_8004B0B4;
    case 0x8004B0B8u: goto label_8004B0B8;
    case 0x8004B0BCu: goto label_8004B0BC;
    case 0x8004B0C0u: goto label_8004B0C0;
    case 0x8004B0C4u: goto label_8004B0C4;
    case 0x8004B0C8u: goto label_8004B0C8;
    case 0x8004B0CCu: goto label_8004B0CC;
    case 0x8004B0D0u: goto label_8004B0D0;
    case 0x8004B0D4u: goto label_8004B0D4;
    case 0x8004B0D8u: goto label_8004B0D8;
    case 0x8004B0DCu: goto label_8004B0DC;
    case 0x8004B0E0u: goto label_8004B0E0;
    case 0x8004B0E4u: goto label_8004B0E4;
    case 0x8004B0E8u: goto label_8004B0E8;
    case 0x8004B0ECu: goto label_8004B0EC;
    case 0x8004B0F0u: goto label_8004B0F0;
    case 0x8004B0F4u: goto label_8004B0F4;
    case 0x8004B0F8u: goto label_8004B0F8;
    case 0x8004B0FCu: goto label_8004B0FC;
    case 0x8004B100u: goto label_8004B100;
    case 0x8004B104u: goto label_8004B104;
    case 0x8004B108u: goto label_8004B108;
    case 0x8004B10Cu: goto label_8004B10C;
    case 0x8004B110u: goto label_8004B110;
    case 0x8004B114u: goto label_8004B114;
    case 0x8004B118u: goto label_8004B118;
    case 0x8004B11Cu: goto label_8004B11C;
    case 0x8004B120u: goto label_8004B120;
    case 0x8004B124u: goto label_8004B124;
    case 0x8004B128u: goto label_8004B128;
    case 0x8004B12Cu: goto label_8004B12C;
    case 0x8004B130u: goto label_8004B130;
    case 0x8004B134u: goto label_8004B134;
    case 0x8004B138u: goto label_8004B138;
    case 0x8004B13Cu: goto label_8004B13C;
    case 0x8004B140u: goto label_8004B140;
    case 0x8004B144u: goto label_8004B144;
    case 0x8004B148u: goto label_8004B148;
    case 0x8004B14Cu: goto label_8004B14C;
    case 0x8004B150u: goto label_8004B150;
    case 0x8004B154u: goto label_8004B154;
    case 0x8004B158u: goto label_8004B158;
    case 0x8004B15Cu: goto label_8004B15C;
    case 0x8004B160u: goto label_8004B160;
    case 0x8004B164u: goto label_8004B164;
    case 0x8004B168u: goto label_8004B168;
    case 0x8004B16Cu: goto label_8004B16C;
    case 0x8004B170u: goto label_8004B170;
    case 0x8004B174u: goto label_8004B174;
    case 0x8004B178u: goto label_8004B178;
    case 0x8004B17Cu: goto label_8004B17C;
    case 0x8004B180u: goto label_8004B180;
    case 0x8004B184u: goto label_8004B184;
    case 0x8004B188u: goto label_8004B188;
    case 0x8004B18Cu: goto label_8004B18C;
    case 0x8004B190u: goto label_8004B190;
    case 0x8004B194u: goto label_8004B194;
    case 0x8004B198u: goto label_8004B198;
    case 0x8004B19Cu: goto label_8004B19C;
    case 0x8004B1A0u: goto label_8004B1A0;
    case 0x8004B1A4u: goto label_8004B1A4;
    case 0x8004B1A8u: goto label_8004B1A8;
    case 0x8004B1ACu: goto label_8004B1AC;
    case 0x8004B1B0u: goto label_8004B1B0;
    case 0x8004B1B4u: goto label_8004B1B4;
    case 0x8004B1B8u: goto label_8004B1B8;
    case 0x8004B1BCu: goto label_8004B1BC;
    case 0x8004B1C0u: goto label_8004B1C0;
    case 0x8004B1C4u: goto label_8004B1C4;
    case 0x8004B1C8u: goto label_8004B1C8;
    case 0x8004B1CCu: goto label_8004B1CC;
    case 0x8004B1D0u: goto label_8004B1D0;
    case 0x8004B1D4u: goto label_8004B1D4;
    case 0x8004B1D8u: goto label_8004B1D8;
    case 0x8004B1DCu: goto label_8004B1DC;
    case 0x8004B1E0u: goto label_8004B1E0;
    case 0x8004B1E4u: goto label_8004B1E4;
    case 0x8004B1E8u: goto label_8004B1E8;
    case 0x8004B1ECu: goto label_8004B1EC;
    case 0x8004B1F0u: goto label_8004B1F0;
    case 0x8004B1F4u: goto label_8004B1F4;
    case 0x8004B1F8u: goto label_8004B1F8;
    case 0x8004B1FCu: goto label_8004B1FC;
    case 0x8004B200u: goto label_8004B200;
    case 0x8004B204u: goto label_8004B204;
    case 0x8004B208u: goto label_8004B208;
    case 0x8004B20Cu: goto label_8004B20C;
    case 0x8004B210u: goto label_8004B210;
    case 0x8004B214u: goto label_8004B214;
    case 0x8004B218u: goto label_8004B218;
    case 0x8004B21Cu: goto label_8004B21C;
    case 0x8004B220u: goto label_8004B220;
    case 0x8004B224u: goto label_8004B224;
    case 0x8004B228u: goto label_8004B228;
    case 0x8004B22Cu: goto label_8004B22C;
    case 0x8004B230u: goto label_8004B230;
    case 0x8004B234u: goto label_8004B234;
    case 0x8004B238u: goto label_8004B238;
    case 0x8004B23Cu: goto label_8004B23C;
    case 0x8004B240u: goto label_8004B240;
    case 0x8004B244u: goto label_8004B244;
    case 0x8004B248u: goto label_8004B248;
    case 0x8004B24Cu: goto label_8004B24C;
    case 0x8004B250u: goto label_8004B250;
    case 0x8004B254u: goto label_8004B254;
    case 0x8004B258u: goto label_8004B258;
    case 0x8004B25Cu: goto label_8004B25C;
    case 0x8004B260u: goto label_8004B260;
    case 0x8004B264u: goto label_8004B264;
    case 0x8004B268u: goto label_8004B268;
    case 0x8004B26Cu: goto label_8004B26C;
    case 0x8004B270u: goto label_8004B270;
    case 0x8004B274u: goto label_8004B274;
    case 0x8004B278u: goto label_8004B278;
    case 0x8004B27Cu: goto label_8004B27C;
    case 0x8004B280u: goto label_8004B280;
    case 0x8004B284u: goto label_8004B284;
    case 0x8004B288u: goto label_8004B288;
    case 0x8004B28Cu: goto label_8004B28C;
    case 0x8004B290u: goto label_8004B290;
    case 0x8004B294u: goto label_8004B294;
    case 0x8004B298u: goto label_8004B298;
    case 0x8004B29Cu: goto label_8004B29C;
    case 0x8004B2A0u: goto label_8004B2A0;
    case 0x8004B2A4u: goto label_8004B2A4;
    case 0x8004B2A8u: goto label_8004B2A8;
    case 0x8004B2ACu: goto label_8004B2AC;
    case 0x8004B2B0u: goto label_8004B2B0;
    case 0x8004B2B4u: goto label_8004B2B4;
    case 0x8004B2B8u: goto label_8004B2B8;
    case 0x8004B2BCu: goto label_8004B2BC;
    case 0x8004B2C0u: goto label_8004B2C0;
    case 0x8004B2C4u: goto label_8004B2C4;
    case 0x8004B2C8u: goto label_8004B2C8;
    case 0x8004B2CCu: goto label_8004B2CC;
    case 0x8004B2D0u: goto label_8004B2D0;
    case 0x8004B2D4u: goto label_8004B2D4;
    case 0x8004B2D8u: goto label_8004B2D8;
    case 0x8004B2DCu: goto label_8004B2DC;
    case 0x8004B2E0u: goto label_8004B2E0;
    case 0x8004B2E4u: goto label_8004B2E4;
    case 0x8004B2E8u: goto label_8004B2E8;
    case 0x8004B2ECu: goto label_8004B2EC;
    case 0x8004B2F0u: goto label_8004B2F0;
    case 0x8004B2F4u: goto label_8004B2F4;
    case 0x8004B2F8u: goto label_8004B2F8;
    case 0x8004B2FCu: goto label_8004B2FC;
    case 0x8004B300u: goto label_8004B300;
    case 0x8004B304u: goto label_8004B304;
    case 0x8004B308u: goto label_8004B308;
    case 0x8004B30Cu: goto label_8004B30C;
    case 0x8004B310u: goto label_8004B310;
    case 0x8004B314u: goto label_8004B314;
    case 0x8004B318u: goto label_8004B318;
    case 0x8004B31Cu: goto label_8004B31C;
    case 0x8004B320u: goto label_8004B320;
    case 0x8004B324u: goto label_8004B324;
    case 0x8004B328u: goto label_8004B328;
    case 0x8004B32Cu: goto label_8004B32C;
    case 0x8004B330u: goto label_8004B330;
    case 0x8004B334u: goto label_8004B334;
    case 0x8004B338u: goto label_8004B338;
    case 0x8004B33Cu: goto label_8004B33C;
    case 0x8004B340u: goto label_8004B340;
    case 0x8004B344u: goto label_8004B344;
    case 0x8004B348u: goto label_8004B348;
    case 0x8004B34Cu: goto label_8004B34C;
    case 0x8004B350u: goto label_8004B350;
    case 0x8004B354u: goto label_8004B354;
    case 0x8004B358u: goto label_8004B358;
    case 0x8004B35Cu: goto label_8004B35C;
    case 0x8004B360u: goto label_8004B360;
    case 0x8004B364u: goto label_8004B364;
    case 0x8004B368u: goto label_8004B368;
    case 0x8004B36Cu: goto label_8004B36C;
    case 0x8004B370u: goto label_8004B370;
    case 0x8004B374u: goto label_8004B374;
    case 0x8004B378u: goto label_8004B378;
    case 0x8004B37Cu: goto label_8004B37C;
    case 0x8004B380u: goto label_8004B380;
    case 0x8004B384u: goto label_8004B384;
    case 0x8004B388u: goto label_8004B388;
    case 0x8004B38Cu: goto label_8004B38C;
    case 0x8004B390u: goto label_8004B390;
    case 0x8004B394u: goto label_8004B394;
    case 0x8004B398u: goto label_8004B398;
    case 0x8004B39Cu: goto label_8004B39C;
    case 0x8004B3A0u: goto label_8004B3A0;
    case 0x8004B3A4u: goto label_8004B3A4;
    case 0x8004B3A8u: goto label_8004B3A8;
    case 0x8004B3ACu: goto label_8004B3AC;
    case 0x8004B3B0u: goto label_8004B3B0;
    case 0x8004B3B4u: goto label_8004B3B4;
    case 0x8004B3B8u: goto label_8004B3B8;
    case 0x8004B3BCu: goto label_8004B3BC;
    case 0x8004B3C0u: goto label_8004B3C0;
    case 0x8004B3C4u: goto label_8004B3C4;
    case 0x8004B3C8u: goto label_8004B3C8;
    case 0x8004B3CCu: goto label_8004B3CC;
    case 0x8004B3D0u: goto label_8004B3D0;
    case 0x8004B3D4u: goto label_8004B3D4;
    case 0x8004B3D8u: goto label_8004B3D8;
    case 0x8004B3DCu: goto label_8004B3DC;
    case 0x8004B3E0u: goto label_8004B3E0;
    case 0x8004B3E4u: goto label_8004B3E4;
    case 0x8004B3E8u: goto label_8004B3E8;
    case 0x8004B3ECu: goto label_8004B3EC;
    case 0x8004B3F0u: goto label_8004B3F0;
    case 0x8004B3F4u: goto label_8004B3F4;
    case 0x8004B3F8u: goto label_8004B3F8;
    case 0x8004B3FCu: goto label_8004B3FC;
    case 0x8004B400u: goto label_8004B400;
    case 0x8004B404u: goto label_8004B404;
    case 0x8004B408u: goto label_8004B408;
    case 0x8004B40Cu: goto label_8004B40C;
    case 0x8004B410u: goto label_8004B410;
    case 0x8004B414u: goto label_8004B414;
    case 0x8004B418u: goto label_8004B418;
    case 0x8004B41Cu: goto label_8004B41C;
    case 0x8004B420u: goto label_8004B420;
    case 0x8004B424u: goto label_8004B424;
    case 0x8004B428u: goto label_8004B428;
    case 0x8004B42Cu: goto label_8004B42C;
    case 0x8004B430u: goto label_8004B430;
    case 0x8004B434u: goto label_8004B434;
    case 0x8004B438u: goto label_8004B438;
    case 0x8004B43Cu: goto label_8004B43C;
    case 0x8004B440u: goto label_8004B440;
    case 0x8004B444u: goto label_8004B444;
    case 0x8004B448u: goto label_8004B448;
    case 0x8004B44Cu: goto label_8004B44C;
    case 0x8004B450u: goto label_8004B450;
    case 0x8004B454u: goto label_8004B454;
    case 0x8004B458u: goto label_8004B458;
    case 0x8004B45Cu: goto label_8004B45C;
    case 0x8004B460u: goto label_8004B460;
    case 0x8004B464u: goto label_8004B464;
    case 0x8004B468u: goto label_8004B468;
    case 0x8004B46Cu: goto label_8004B46C;
    case 0x8004B470u: goto label_8004B470;
    case 0x8004B474u: goto label_8004B474;
    case 0x8004B478u: goto label_8004B478;
    case 0x8004B47Cu: goto label_8004B47C;
    case 0x8004B480u: goto label_8004B480;
    case 0x8004B484u: goto label_8004B484;
    case 0x8004B488u: goto label_8004B488;
    case 0x8004B48Cu: goto label_8004B48C;
    case 0x8004B490u: goto label_8004B490;
    case 0x8004B494u: goto label_8004B494;
    case 0x8004B498u: goto label_8004B498;
    case 0x8004B49Cu: goto label_8004B49C;
    case 0x8004B4A0u: goto label_8004B4A0;
    case 0x8004B4A4u: goto label_8004B4A4;
    case 0x8004B4A8u: goto label_8004B4A8;
    case 0x8004B4ACu: goto label_8004B4AC;
    case 0x8004B4B0u: goto label_8004B4B0;
    case 0x8004B4B4u: goto label_8004B4B4;
    case 0x8004B4B8u: goto label_8004B4B8;
    case 0x8004B4BCu: goto label_8004B4BC;
    case 0x8004B4C0u: goto label_8004B4C0;
    case 0x8004B4C4u: goto label_8004B4C4;
    case 0x8004B4C8u: goto label_8004B4C8;
    case 0x8004B4CCu: goto label_8004B4CC;
    case 0x8004B4D0u: goto label_8004B4D0;
    case 0x8004B4D4u: goto label_8004B4D4;
    case 0x8004B4D8u: goto label_8004B4D8;
    case 0x8004B4DCu: goto label_8004B4DC;
    case 0x8004B4E0u: goto label_8004B4E0;
    case 0x8004B4E4u: goto label_8004B4E4;
    case 0x8004B4E8u: goto label_8004B4E8;
    case 0x8004B4ECu: goto label_8004B4EC;
    case 0x8004B4F0u: goto label_8004B4F0;
    case 0x8004B4F4u: goto label_8004B4F4;
    case 0x8004B4F8u: goto label_8004B4F8;
    case 0x8004B4FCu: goto label_8004B4FC;
    case 0x8004B500u: goto label_8004B500;
    case 0x8004B504u: goto label_8004B504;
    case 0x8004B508u: goto label_8004B508;
    case 0x8004B50Cu: goto label_8004B50C;
    case 0x8004B510u: goto label_8004B510;
    case 0x8004B514u: goto label_8004B514;
    case 0x8004B518u: goto label_8004B518;
    case 0x8004B51Cu: goto label_8004B51C;
    case 0x8004B520u: goto label_8004B520;
    case 0x8004B524u: goto label_8004B524;
    case 0x8004B528u: goto label_8004B528;
    case 0x8004B52Cu: goto label_8004B52C;
    case 0x8004B530u: goto label_8004B530;
    case 0x8004B534u: goto label_8004B534;
    case 0x8004B538u: goto label_8004B538;
    case 0x8004B53Cu: goto label_8004B53C;
    case 0x8004B540u: goto label_8004B540;
    case 0x8004B544u: goto label_8004B544;
    case 0x8004B548u: goto label_8004B548;
    case 0x8004B54Cu: goto label_8004B54C;
    case 0x8004B550u: goto label_8004B550;
    case 0x8004B554u: goto label_8004B554;
    case 0x8004B558u: goto label_8004B558;
    case 0x8004B55Cu: goto label_8004B55C;
    case 0x8004B560u: goto label_8004B560;
    case 0x8004B564u: goto label_8004B564;
    case 0x8004B568u: goto label_8004B568;
    case 0x8004B56Cu: goto label_8004B56C;
    case 0x8004B570u: goto label_8004B570;
    case 0x8004B574u: goto label_8004B574;
    case 0x8004B578u: goto label_8004B578;
    case 0x8004B57Cu: goto label_8004B57C;
    case 0x8004B580u: goto label_8004B580;
    case 0x8004B584u: goto label_8004B584;
    case 0x8004B588u: goto label_8004B588;
    case 0x8004B58Cu: goto label_8004B58C;
    case 0x8004B590u: goto label_8004B590;
    case 0x8004B594u: goto label_8004B594;
    case 0x8004B598u: goto label_8004B598;
    case 0x8004B59Cu: goto label_8004B59C;
    case 0x8004B5A0u: goto label_8004B5A0;
    case 0x8004B5A4u: goto label_8004B5A4;
    case 0x8004B5A8u: goto label_8004B5A8;
    case 0x8004B5ACu: goto label_8004B5AC;
    case 0x8004B5B0u: goto label_8004B5B0;
    case 0x8004B5B4u: goto label_8004B5B4;
    case 0x8004B5B8u: goto label_8004B5B8;
    case 0x8004B5BCu: goto label_8004B5BC;
    case 0x8004B5C0u: goto label_8004B5C0;
    case 0x8004B5C4u: goto label_8004B5C4;
    case 0x8004B5C8u: goto label_8004B5C8;
    case 0x8004B5CCu: goto label_8004B5CC;
    case 0x8004B5D0u: goto label_8004B5D0;
    case 0x8004B5D4u: goto label_8004B5D4;
    case 0x8004B5D8u: goto label_8004B5D8;
    case 0x8004B5DCu: goto label_8004B5DC;
    case 0x8004B5E0u: goto label_8004B5E0;
    case 0x8004B5E4u: goto label_8004B5E4;
    case 0x8004B5E8u: goto label_8004B5E8;
    case 0x8004B5ECu: goto label_8004B5EC;
    case 0x8004B5F0u: goto label_8004B5F0;
    case 0x8004B5F4u: goto label_8004B5F4;
    case 0x8004B5F8u: goto label_8004B5F8;
    case 0x8004B5FCu: goto label_8004B5FC;
    case 0x8004B600u: goto label_8004B600;
    case 0x8004B604u: goto label_8004B604;
    case 0x8004B608u: goto label_8004B608;
    case 0x8004B60Cu: goto label_8004B60C;
    case 0x8004B610u: goto label_8004B610;
    case 0x8004B614u: goto label_8004B614;
    case 0x8004B618u: goto label_8004B618;
    case 0x8004B61Cu: goto label_8004B61C;
    case 0x8004B620u: goto label_8004B620;
    case 0x8004B624u: goto label_8004B624;
    case 0x8004B628u: goto label_8004B628;
    case 0x8004B62Cu: goto label_8004B62C;
    case 0x8004B630u: goto label_8004B630;
    case 0x8004B634u: goto label_8004B634;
    case 0x8004B638u: goto label_8004B638;
    case 0x8004B63Cu: goto label_8004B63C;
    case 0x8004B640u: goto label_8004B640;
    case 0x8004B644u: goto label_8004B644;
    case 0x8004B648u: goto label_8004B648;
    case 0x8004B64Cu: goto label_8004B64C;
    case 0x8004B650u: goto label_8004B650;
    case 0x8004B654u: goto label_8004B654;
    case 0x8004B658u: goto label_8004B658;
    case 0x8004B65Cu: goto label_8004B65C;
    case 0x8004B660u: goto label_8004B660;
    case 0x8004B664u: goto label_8004B664;
    case 0x8004B668u: goto label_8004B668;
    case 0x8004B66Cu: goto label_8004B66C;
    case 0x8004B670u: goto label_8004B670;
    case 0x8004B674u: goto label_8004B674;
    case 0x8004B678u: goto label_8004B678;
    case 0x8004B67Cu: goto label_8004B67C;
    case 0x8004B680u: goto label_8004B680;
    case 0x8004B684u: goto label_8004B684;
    case 0x8004B688u: goto label_8004B688;
    case 0x8004B68Cu: goto label_8004B68C;
    case 0x8004B690u: goto label_8004B690;
    case 0x8004B694u: goto label_8004B694;
    case 0x8004B698u: goto label_8004B698;
    case 0x8004B69Cu: goto label_8004B69C;
    case 0x8004B6A0u: goto label_8004B6A0;
    case 0x8004B6A4u: goto label_8004B6A4;
    case 0x8004B6A8u: goto label_8004B6A8;
    case 0x8004B6ACu: goto label_8004B6AC;
    case 0x8004B6B0u: goto label_8004B6B0;
    case 0x8004B6B4u: goto label_8004B6B4;
    case 0x8004B6B8u: goto label_8004B6B8;
    case 0x8004B6BCu: goto label_8004B6BC;
    case 0x8004B6C0u: goto label_8004B6C0;
    case 0x8004B6C4u: goto label_8004B6C4;
    case 0x8004B6C8u: goto label_8004B6C8;
    case 0x8004B6CCu: goto label_8004B6CC;
    case 0x8004B6D0u: goto label_8004B6D0;
    case 0x8004B6D4u: goto label_8004B6D4;
    case 0x8004B6D8u: goto label_8004B6D8;
    case 0x8004B6DCu: goto label_8004B6DC;
    case 0x8004B6E0u: goto label_8004B6E0;
    case 0x8004B6E4u: goto label_8004B6E4;
    case 0x8004B6E8u: goto label_8004B6E8;
    case 0x8004B6ECu: goto label_8004B6EC;
    case 0x8004B6F0u: goto label_8004B6F0;
    case 0x8004B6F4u: goto label_8004B6F4;
    case 0x8004B6F8u: goto label_8004B6F8;
    case 0x8004B6FCu: goto label_8004B6FC;
    case 0x8004B700u: goto label_8004B700;
    case 0x8004B704u: goto label_8004B704;
    case 0x8004B708u: goto label_8004B708;
    case 0x8004B70Cu: goto label_8004B70C;
    case 0x8004B710u: goto label_8004B710;
    case 0x8004B714u: goto label_8004B714;
    case 0x8004B718u: goto label_8004B718;
    case 0x8004B71Cu: goto label_8004B71C;
    case 0x8004B720u: goto label_8004B720;
    case 0x8004B724u: goto label_8004B724;
    case 0x8004B728u: goto label_8004B728;
    case 0x8004B72Cu: goto label_8004B72C;
    case 0x8004B730u: goto label_8004B730;
    case 0x8004B734u: goto label_8004B734;
    case 0x8004B738u: goto label_8004B738;
    case 0x8004B73Cu: goto label_8004B73C;
    case 0x8004B740u: goto label_8004B740;
    case 0x8004B744u: goto label_8004B744;
    case 0x8004B748u: goto label_8004B748;
    case 0x8004B74Cu: goto label_8004B74C;
    case 0x8004B750u: goto label_8004B750;
    case 0x8004B754u: goto label_8004B754;
    case 0x8004B758u: goto label_8004B758;
    case 0x8004B75Cu: goto label_8004B75C;
    case 0x8004B760u: goto label_8004B760;
    case 0x8004B764u: goto label_8004B764;
    case 0x8004B768u: goto label_8004B768;
    case 0x8004B76Cu: goto label_8004B76C;
    case 0x8004B770u: goto label_8004B770;
    case 0x8004B774u: goto label_8004B774;
    case 0x8004B778u: goto label_8004B778;
    case 0x8004B77Cu: goto label_8004B77C;
    case 0x8004B780u: goto label_8004B780;
    case 0x8004B784u: goto label_8004B784;
    case 0x8004B788u: goto label_8004B788;
    case 0x8004B78Cu: goto label_8004B78C;
    case 0x8004B790u: goto label_8004B790;
    case 0x8004B794u: goto label_8004B794;
    case 0x8004B798u: goto label_8004B798;
    case 0x8004B79Cu: goto label_8004B79C;
    case 0x8004B7A0u: goto label_8004B7A0;
    case 0x8004B7A4u: goto label_8004B7A4;
    case 0x8004B7A8u: goto label_8004B7A8;
    case 0x8004B7ACu: goto label_8004B7AC;
    case 0x8004B7B0u: goto label_8004B7B0;
    case 0x8004B7B4u: goto label_8004B7B4;
    case 0x8004B7B8u: goto label_8004B7B8;
    case 0x8004B7BCu: goto label_8004B7BC;
    case 0x8004B7C0u: goto label_8004B7C0;
    case 0x8004B7C4u: goto label_8004B7C4;
    case 0x8004B7C8u: goto label_8004B7C8;
    case 0x8004B7CCu: goto label_8004B7CC;
    case 0x8004B7D0u: goto label_8004B7D0;
    case 0x8004B7D4u: goto label_8004B7D4;
    case 0x8004B7D8u: goto label_8004B7D8;
    case 0x8004B7DCu: goto label_8004B7DC;
    case 0x8004B7E0u: goto label_8004B7E0;
    case 0x8004B7E4u: goto label_8004B7E4;
    case 0x8004B7E8u: goto label_8004B7E8;
    case 0x8004B7ECu: goto label_8004B7EC;
    case 0x8004B7F0u: goto label_8004B7F0;
    case 0x8004B7F4u: goto label_8004B7F4;
    case 0x8004B7F8u: goto label_8004B7F8;
    case 0x8004B7FCu: goto label_8004B7FC;
    case 0x8004B800u: goto label_8004B800;
    case 0x8004B804u: goto label_8004B804;
    case 0x8004B808u: goto label_8004B808;
    case 0x8004B80Cu: goto label_8004B80C;
    case 0x8004B810u: goto label_8004B810;
    case 0x8004B814u: goto label_8004B814;
    case 0x8004B818u: goto label_8004B818;
    case 0x8004B81Cu: goto label_8004B81C;
    case 0x8004B820u: goto label_8004B820;
    case 0x8004B824u: goto label_8004B824;
    case 0x8004B828u: goto label_8004B828;
    case 0x8004B82Cu: goto label_8004B82C;
    case 0x8004B830u: goto label_8004B830;
    case 0x8004B834u: goto label_8004B834;
    case 0x8004B838u: goto label_8004B838;
    case 0x8004B83Cu: goto label_8004B83C;
    case 0x8004B840u: goto label_8004B840;
    case 0x8004B844u: goto label_8004B844;
    case 0x8004B848u: goto label_8004B848;
    case 0x8004B84Cu: goto label_8004B84C;
    case 0x8004B850u: goto label_8004B850;
    case 0x8004B854u: goto label_8004B854;
    case 0x8004B858u: goto label_8004B858;
    case 0x8004B85Cu: goto label_8004B85C;
    case 0x8004B860u: goto label_8004B860;
    case 0x8004B864u: goto label_8004B864;
    case 0x8004B868u: goto label_8004B868;
    case 0x8004B86Cu: goto label_8004B86C;
    case 0x8004B870u: goto label_8004B870;
    case 0x8004B874u: goto label_8004B874;
    case 0x8004B878u: goto label_8004B878;
    case 0x8004B87Cu: goto label_8004B87C;
    case 0x8004B880u: goto label_8004B880;
    case 0x8004B884u: goto label_8004B884;
    case 0x8004B888u: goto label_8004B888;
    case 0x8004B88Cu: goto label_8004B88C;
    case 0x8004B890u: goto label_8004B890;
    case 0x8004B894u: goto label_8004B894;
    case 0x8004B898u: goto label_8004B898;
    case 0x8004B89Cu: goto label_8004B89C;
    case 0x8004B8A0u: goto label_8004B8A0;
    case 0x8004B8A4u: goto label_8004B8A4;
    case 0x8004B8A8u: goto label_8004B8A8;
    case 0x8004B8ACu: goto label_8004B8AC;
    case 0x8004B8B0u: goto label_8004B8B0;
    case 0x8004B8B4u: goto label_8004B8B4;
    case 0x8004B8B8u: goto label_8004B8B8;
    case 0x8004B8BCu: goto label_8004B8BC;
    case 0x8004B8C0u: goto label_8004B8C0;
    case 0x8004B8C4u: goto label_8004B8C4;
    case 0x8004B8C8u: goto label_8004B8C8;
    case 0x8004B8CCu: goto label_8004B8CC;
    case 0x8004B8D0u: goto label_8004B8D0;
    case 0x8004B8D4u: goto label_8004B8D4;
    case 0x8004B8D8u: goto label_8004B8D8;
    case 0x8004B8DCu: goto label_8004B8DC;
    case 0x8004B8E0u: goto label_8004B8E0;
    case 0x8004B8E4u: goto label_8004B8E4;
    case 0x8004B8E8u: goto label_8004B8E8;
    case 0x8004B8ECu: goto label_8004B8EC;
    case 0x8004B8F0u: goto label_8004B8F0;
    case 0x8004B8F4u: goto label_8004B8F4;
    case 0x8004B8F8u: goto label_8004B8F8;
    case 0x8004B8FCu: goto label_8004B8FC;
    case 0x8004B900u: goto label_8004B900;
    case 0x8004B904u: goto label_8004B904;
    case 0x8004B908u: goto label_8004B908;
    case 0x8004B90Cu: goto label_8004B90C;
    case 0x8004B910u: goto label_8004B910;
    case 0x8004B914u: goto label_8004B914;
    case 0x8004B918u: goto label_8004B918;
    case 0x8004B91Cu: goto label_8004B91C;
    case 0x8004B920u: goto label_8004B920;
    case 0x8004B924u: goto label_8004B924;
    case 0x8004B928u: goto label_8004B928;
    case 0x8004B92Cu: goto label_8004B92C;
    case 0x8004B930u: goto label_8004B930;
    case 0x8004B934u: goto label_8004B934;
    case 0x8004B938u: goto label_8004B938;
    case 0x8004B93Cu: goto label_8004B93C;
    case 0x8004B940u: goto label_8004B940;
    case 0x8004B944u: goto label_8004B944;
    case 0x8004B948u: goto label_8004B948;
    case 0x8004B94Cu: goto label_8004B94C;
    case 0x8004B950u: goto label_8004B950;
    case 0x8004B954u: goto label_8004B954;
    case 0x8004B958u: goto label_8004B958;
    case 0x8004B95Cu: goto label_8004B95C;
    case 0x8004B960u: goto label_8004B960;
    case 0x8004B964u: goto label_8004B964;
    case 0x8004B968u: goto label_8004B968;
    case 0x8004B96Cu: goto label_8004B96C;
    case 0x8004B970u: goto label_8004B970;
    case 0x8004B974u: goto label_8004B974;
    case 0x8004B978u: goto label_8004B978;
    case 0x8004B97Cu: goto label_8004B97C;
    case 0x8004B980u: goto label_8004B980;
    case 0x8004B984u: goto label_8004B984;
    case 0x8004B988u: goto label_8004B988;
    case 0x8004B98Cu: goto label_8004B98C;
    case 0x8004B990u: goto label_8004B990;
    case 0x8004B994u: goto label_8004B994;
    case 0x8004B998u: goto label_8004B998;
    case 0x8004B99Cu: goto label_8004B99C;
    case 0x8004B9A0u: goto label_8004B9A0;
    case 0x8004B9A4u: goto label_8004B9A4;
    case 0x8004B9A8u: goto label_8004B9A8;
    case 0x8004B9ACu: goto label_8004B9AC;
    case 0x8004B9B0u: goto label_8004B9B0;
    case 0x8004B9B4u: goto label_8004B9B4;
    case 0x8004B9B8u: goto label_8004B9B8;
    case 0x8004B9BCu: goto label_8004B9BC;
    case 0x8004B9C0u: goto label_8004B9C0;
    case 0x8004B9C4u: goto label_8004B9C4;
    case 0x8004B9C8u: goto label_8004B9C8;
    case 0x8004B9CCu: goto label_8004B9CC;
    case 0x8004B9D0u: goto label_8004B9D0;
    case 0x8004B9D4u: goto label_8004B9D4;
    case 0x8004B9D8u: goto label_8004B9D8;
    case 0x8004B9DCu: goto label_8004B9DC;
    case 0x8004B9E0u: goto label_8004B9E0;
    case 0x8004B9E4u: goto label_8004B9E4;
    case 0x8004B9E8u: goto label_8004B9E8;
    case 0x8004B9ECu: goto label_8004B9EC;
    case 0x8004B9F0u: goto label_8004B9F0;
    case 0x8004B9F4u: goto label_8004B9F4;
    case 0x8004B9F8u: goto label_8004B9F8;
    case 0x8004B9FCu: goto label_8004B9FC;
    case 0x8004BA00u: goto label_8004BA00;
    case 0x8004BA04u: goto label_8004BA04;
    case 0x8004BA08u: goto label_8004BA08;
    case 0x8004BA0Cu: goto label_8004BA0C;
    case 0x8004BA10u: goto label_8004BA10;
    case 0x8004BA14u: goto label_8004BA14;
    case 0x8004BA18u: goto label_8004BA18;
    case 0x8004BA1Cu: goto label_8004BA1C;
    case 0x8004BA20u: goto label_8004BA20;
    case 0x8004BA24u: goto label_8004BA24;
    case 0x8004BA28u: goto label_8004BA28;
    case 0x8004BA2Cu: goto label_8004BA2C;
    case 0x8004BA30u: goto label_8004BA30;
    case 0x8004BA34u: goto label_8004BA34;
    case 0x8004BA38u: goto label_8004BA38;
    case 0x8004BA3Cu: goto label_8004BA3C;
    case 0x8004BA40u: goto label_8004BA40;
    case 0x8004BA44u: goto label_8004BA44;
    case 0x8004BA48u: goto label_8004BA48;
    case 0x8004BA4Cu: goto label_8004BA4C;
    case 0x8004BA50u: goto label_8004BA50;
    case 0x8004BA54u: goto label_8004BA54;
    case 0x8004BA58u: goto label_8004BA58;
    case 0x8004BA5Cu: goto label_8004BA5C;
    case 0x8004BA60u: goto label_8004BA60;
    case 0x8004BA64u: goto label_8004BA64;
    case 0x8004BA68u: goto label_8004BA68;
    case 0x8004BA6Cu: goto label_8004BA6C;
    case 0x8004BA70u: goto label_8004BA70;
    case 0x8004BA74u: goto label_8004BA74;
    case 0x8004BA78u: goto label_8004BA78;
    case 0x8004BA7Cu: goto label_8004BA7C;
    case 0x8004BA80u: goto label_8004BA80;
    case 0x8004BA84u: goto label_8004BA84;
    case 0x8004BA88u: goto label_8004BA88;
    case 0x8004BA8Cu: goto label_8004BA8C;
    case 0x8004BA90u: goto label_8004BA90;
    case 0x8004BA94u: goto label_8004BA94;
    case 0x8004BA98u: goto label_8004BA98;
    case 0x8004BA9Cu: goto label_8004BA9C;
    case 0x8004BAA0u: goto label_8004BAA0;
    case 0x8004BAA4u: goto label_8004BAA4;
    case 0x8004BAA8u: goto label_8004BAA8;
    case 0x8004BAACu: goto label_8004BAAC;
    case 0x8004BAB0u: goto label_8004BAB0;
    case 0x8004BAB4u: goto label_8004BAB4;
    case 0x8004BAB8u: goto label_8004BAB8;
    case 0x8004BABCu: goto label_8004BABC;
    case 0x8004BAC0u: goto label_8004BAC0;
    case 0x8004BAC4u: goto label_8004BAC4;
    case 0x8004BAC8u: goto label_8004BAC8;
    case 0x8004BACCu: goto label_8004BACC;
    case 0x8004BAD0u: goto label_8004BAD0;
    case 0x8004BAD4u: goto label_8004BAD4;
    case 0x8004BAD8u: goto label_8004BAD8;
    case 0x8004BADCu: goto label_8004BADC;
    case 0x8004BAE0u: goto label_8004BAE0;
    case 0x8004BAE4u: goto label_8004BAE4;
    case 0x8004BAE8u: goto label_8004BAE8;
    case 0x8004BAECu: goto label_8004BAEC;
    case 0x8004BAF0u: goto label_8004BAF0;
    case 0x8004BAF4u: goto label_8004BAF4;
    case 0x8004BAF8u: goto label_8004BAF8;
    case 0x8004BAFCu: goto label_8004BAFC;
    case 0x8004BB00u: goto label_8004BB00;
    case 0x8004BB04u: goto label_8004BB04;
    case 0x8004BB08u: goto label_8004BB08;
    case 0x8004BB0Cu: goto label_8004BB0C;
    case 0x8004BB10u: goto label_8004BB10;
    case 0x8004BB14u: goto label_8004BB14;
    case 0x8004BB18u: goto label_8004BB18;
    case 0x8004BB1Cu: goto label_8004BB1C;
    case 0x8004BB20u: goto label_8004BB20;
    case 0x8004BB24u: goto label_8004BB24;
    case 0x8004BB28u: goto label_8004BB28;
    case 0x8004BB2Cu: goto label_8004BB2C;
    case 0x8004BB30u: goto label_8004BB30;
    case 0x8004BB34u: goto label_8004BB34;
    case 0x8004BB38u: goto label_8004BB38;
    case 0x8004BB3Cu: goto label_8004BB3C;
    case 0x8004BB40u: goto label_8004BB40;
    case 0x8004BB44u: goto label_8004BB44;
    case 0x8004BB48u: goto label_8004BB48;
    case 0x8004BB4Cu: goto label_8004BB4C;
    case 0x8004BB50u: goto label_8004BB50;
    case 0x8004BB54u: goto label_8004BB54;
    case 0x8004BB58u: goto label_8004BB58;
    case 0x8004BB5Cu: goto label_8004BB5C;
    case 0x8004BB60u: goto label_8004BB60;
    case 0x8004BB64u: goto label_8004BB64;
    case 0x8004BB68u: goto label_8004BB68;
    case 0x8004BB6Cu: goto label_8004BB6C;
    case 0x8004BB70u: goto label_8004BB70;
    case 0x8004BB74u: goto label_8004BB74;
    case 0x8004BB78u: goto label_8004BB78;
    case 0x8004BB7Cu: goto label_8004BB7C;
    case 0x8004BB80u: goto label_8004BB80;
    case 0x8004BB84u: goto label_8004BB84;
    case 0x8004BB88u: goto label_8004BB88;
    case 0x8004BB8Cu: goto label_8004BB8C;
    case 0x8004BB90u: goto label_8004BB90;
    case 0x8004BB94u: goto label_8004BB94;
    case 0x8004BB98u: goto label_8004BB98;
    case 0x8004BB9Cu: goto label_8004BB9C;
    case 0x8004BBA0u: goto label_8004BBA0;
    case 0x8004BBA4u: goto label_8004BBA4;
    case 0x8004BBA8u: goto label_8004BBA8;
    case 0x8004BBACu: goto label_8004BBAC;
    case 0x8004BBB0u: goto label_8004BBB0;
    case 0x8004BBB4u: goto label_8004BBB4;
    case 0x8004BBB8u: goto label_8004BBB8;
    case 0x8004BBBCu: goto label_8004BBBC;
    case 0x8004BBC0u: goto label_8004BBC0;
    case 0x8004BBC4u: goto label_8004BBC4;
    case 0x8004BBC8u: goto label_8004BBC8;
    case 0x8004BBCCu: goto label_8004BBCC;
    case 0x8004BBD0u: goto label_8004BBD0;
    case 0x8004BBD4u: goto label_8004BBD4;
    case 0x8004BBD8u: goto label_8004BBD8;
    case 0x8004BBDCu: goto label_8004BBDC;
    case 0x8004BBE0u: goto label_8004BBE0;
    case 0x8004BBE4u: goto label_8004BBE4;
    case 0x8004BBE8u: goto label_8004BBE8;
    case 0x8004BBECu: goto label_8004BBEC;
    case 0x8004BBF0u: goto label_8004BBF0;
    case 0x8004BBF4u: goto label_8004BBF4;
    case 0x8004BBF8u: goto label_8004BBF8;
    case 0x8004BBFCu: goto label_8004BBFC;
    case 0x8004BC00u: goto label_8004BC00;
    case 0x8004BC04u: goto label_8004BC04;
    case 0x8004BC08u: goto label_8004BC08;
    case 0x8004BC0Cu: goto label_8004BC0C;
    case 0x8004BC10u: goto label_8004BC10;
    case 0x8004BC14u: goto label_8004BC14;
    case 0x8004BC18u: goto label_8004BC18;
    case 0x8004BC1Cu: goto label_8004BC1C;
    case 0x8004BC20u: goto label_8004BC20;
    case 0x8004BC24u: goto label_8004BC24;
    case 0x8004BC28u: goto label_8004BC28;
    case 0x8004BC2Cu: goto label_8004BC2C;
    case 0x8004BC30u: goto label_8004BC30;
    case 0x8004BC34u: goto label_8004BC34;
    case 0x8004BC38u: goto label_8004BC38;
    case 0x8004BC3Cu: goto label_8004BC3C;
    case 0x8004BC40u: goto label_8004BC40;
    case 0x8004BC44u: goto label_8004BC44;
    case 0x8004BC48u: goto label_8004BC48;
    case 0x8004BC4Cu: goto label_8004BC4C;
    case 0x8004BC50u: goto label_8004BC50;
    case 0x8004BC54u: goto label_8004BC54;
    case 0x8004BC58u: goto label_8004BC58;
    case 0x8004BC5Cu: goto label_8004BC5C;
    case 0x8004BC60u: goto label_8004BC60;
    case 0x8004BC64u: goto label_8004BC64;
    case 0x8004BC68u: goto label_8004BC68;
    case 0x8004BC6Cu: goto label_8004BC6C;
    case 0x8004BC70u: goto label_8004BC70;
    case 0x8004BC74u: goto label_8004BC74;
    case 0x8004BC78u: goto label_8004BC78;
    case 0x8004BC7Cu: goto label_8004BC7C;
    case 0x8004BC80u: goto label_8004BC80;
    case 0x8004BC84u: goto label_8004BC84;
    case 0x8004BC88u: goto label_8004BC88;
    case 0x8004BC8Cu: goto label_8004BC8C;
    case 0x8004BC90u: goto label_8004BC90;
    case 0x8004BC94u: goto label_8004BC94;
    case 0x8004BC98u: goto label_8004BC98;
    case 0x8004BC9Cu: goto label_8004BC9C;
    case 0x8004BCA0u: goto label_8004BCA0;
    case 0x8004BCA4u: goto label_8004BCA4;
    case 0x8004BCA8u: goto label_8004BCA8;
    case 0x8004BCACu: goto label_8004BCAC;
    case 0x8004BCB0u: goto label_8004BCB0;
    case 0x8004BCB4u: goto label_8004BCB4;
    case 0x8004BCB8u: goto label_8004BCB8;
    case 0x8004BCBCu: goto label_8004BCBC;
    case 0x8004BCC0u: goto label_8004BCC0;
    case 0x8004BCC4u: goto label_8004BCC4;
    case 0x8004BCC8u: goto label_8004BCC8;
    case 0x8004BCCCu: goto label_8004BCCC;
    case 0x8004BCD0u: goto label_8004BCD0;
    case 0x8004BCD4u: goto label_8004BCD4;
    case 0x8004BCD8u: goto label_8004BCD8;
    case 0x8004BCDCu: goto label_8004BCDC;
    case 0x8004BCE0u: goto label_8004BCE0;
    case 0x8004BCE4u: goto label_8004BCE4;
    case 0x8004BCE8u: goto label_8004BCE8;
    case 0x8004BCECu: goto label_8004BCEC;
    case 0x8004BCF0u: goto label_8004BCF0;
    case 0x8004BCF4u: goto label_8004BCF4;
    case 0x8004BCF8u: goto label_8004BCF8;
    case 0x8004BCFCu: goto label_8004BCFC;
    case 0x8004BD00u: goto label_8004BD00;
    case 0x8004BD04u: goto label_8004BD04;
    case 0x8004BD08u: goto label_8004BD08;
    case 0x8004BD0Cu: goto label_8004BD0C;
    case 0x8004BD10u: goto label_8004BD10;
    case 0x8004BD14u: goto label_8004BD14;
    case 0x8004BD18u: goto label_8004BD18;
    case 0x8004BD1Cu: goto label_8004BD1C;
    case 0x8004BD20u: goto label_8004BD20;
    case 0x8004BD24u: goto label_8004BD24;
    case 0x8004BD28u: goto label_8004BD28;
    case 0x8004BD2Cu: goto label_8004BD2C;
    case 0x8004BD30u: goto label_8004BD30;
    case 0x8004BD34u: goto label_8004BD34;
    case 0x8004BD38u: goto label_8004BD38;
    case 0x8004BD3Cu: goto label_8004BD3C;
    case 0x8004BD40u: goto label_8004BD40;
    case 0x8004BD44u: goto label_8004BD44;
    case 0x8004BD48u: goto label_8004BD48;
    case 0x8004BD4Cu: goto label_8004BD4C;
    case 0x8004BD50u: goto label_8004BD50;
    case 0x8004BD54u: goto label_8004BD54;
    case 0x8004BD58u: goto label_8004BD58;
    case 0x8004BD5Cu: goto label_8004BD5C;
    case 0x8004BD60u: goto label_8004BD60;
    case 0x8004BD64u: goto label_8004BD64;
    case 0x8004BD68u: goto label_8004BD68;
    case 0x8004BD6Cu: goto label_8004BD6C;
    case 0x8004BD70u: goto label_8004BD70;
    case 0x8004BD74u: goto label_8004BD74;
    case 0x8004BD78u: goto label_8004BD78;
    case 0x8004BD7Cu: goto label_8004BD7C;
    case 0x8004BD80u: goto label_8004BD80;
    case 0x8004BD84u: goto label_8004BD84;
    case 0x8004BD88u: goto label_8004BD88;
    case 0x8004BD8Cu: goto label_8004BD8C;
    case 0x8004BD90u: goto label_8004BD90;
    case 0x8004BD94u: goto label_8004BD94;
    case 0x8004BD98u: goto label_8004BD98;
    case 0x8004BD9Cu: goto label_8004BD9C;
    case 0x8004BDA0u: goto label_8004BDA0;
    case 0x8004BDA4u: goto label_8004BDA4;
    case 0x8004BDA8u: goto label_8004BDA8;
    case 0x8004BDACu: goto label_8004BDAC;
    case 0x8004BDB0u: goto label_8004BDB0;
    case 0x8004BDB4u: goto label_8004BDB4;
    case 0x8004BDB8u: goto label_8004BDB8;
    case 0x8004BDBCu: goto label_8004BDBC;
    case 0x8004BDC0u: goto label_8004BDC0;
    case 0x8004BDC4u: goto label_8004BDC4;
    case 0x8004BDC8u: goto label_8004BDC8;
    case 0x8004BDCCu: goto label_8004BDCC;
    case 0x8004BDD0u: goto label_8004BDD0;
    case 0x8004BDD4u: goto label_8004BDD4;
    case 0x8004BDD8u: goto label_8004BDD8;
    case 0x8004BDDCu: goto label_8004BDDC;
    case 0x8004BDE0u: goto label_8004BDE0;
    case 0x8004BDE4u: goto label_8004BDE4;
    case 0x8004BDE8u: goto label_8004BDE8;
    case 0x8004BDECu: goto label_8004BDEC;
    case 0x8004BDF0u: goto label_8004BDF0;
    case 0x8004BDF4u: goto label_8004BDF4;
    case 0x8004BDF8u: goto label_8004BDF8;
    case 0x8004BDFCu: goto label_8004BDFC;
    case 0x8004BE00u: goto label_8004BE00;
    case 0x8004BE04u: goto label_8004BE04;
    case 0x8004BE08u: goto label_8004BE08;
    case 0x8004BE0Cu: goto label_8004BE0C;
    case 0x8004BE10u: goto label_8004BE10;
    case 0x8004BE14u: goto label_8004BE14;
    case 0x8004BE18u: goto label_8004BE18;
    case 0x8004BE1Cu: goto label_8004BE1C;
    case 0x8004BE20u: goto label_8004BE20;
    case 0x8004BE24u: goto label_8004BE24;
    case 0x8004BE28u: goto label_8004BE28;
    case 0x8004BE2Cu: goto label_8004BE2C;
    case 0x8004BE30u: goto label_8004BE30;
    case 0x8004BE34u: goto label_8004BE34;
    case 0x8004BE38u: goto label_8004BE38;
    case 0x8004BE3Cu: goto label_8004BE3C;
    case 0x8004BE40u: goto label_8004BE40;
    case 0x8004BE44u: goto label_8004BE44;
    case 0x8004BE48u: goto label_8004BE48;
    case 0x8004BE4Cu: goto label_8004BE4C;
    case 0x8004BE50u: goto label_8004BE50;
    case 0x8004BE54u: goto label_8004BE54;
    case 0x8004BE58u: goto label_8004BE58;
    case 0x8004BE5Cu: goto label_8004BE5C;
    case 0x8004BE60u: goto label_8004BE60;
    case 0x8004BE64u: goto label_8004BE64;
    case 0x8004BE68u: goto label_8004BE68;
    case 0x8004BE6Cu: goto label_8004BE6C;
    case 0x8004BE70u: goto label_8004BE70;
    case 0x8004BE74u: goto label_8004BE74;
    case 0x8004BE78u: goto label_8004BE78;
    case 0x8004BE7Cu: goto label_8004BE7C;
    case 0x8004BE80u: goto label_8004BE80;
    case 0x8004BE84u: goto label_8004BE84;
    case 0x8004BE88u: goto label_8004BE88;
    case 0x8004BE8Cu: goto label_8004BE8C;
    case 0x8004BE90u: goto label_8004BE90;
    case 0x8004BE94u: goto label_8004BE94;
    case 0x8004BE98u: goto label_8004BE98;
    case 0x8004BE9Cu: goto label_8004BE9C;
    case 0x8004BEA0u: goto label_8004BEA0;
    case 0x8004BEA4u: goto label_8004BEA4;
    case 0x8004BEA8u: goto label_8004BEA8;
    case 0x8004BEACu: goto label_8004BEAC;
    case 0x8004BEB0u: goto label_8004BEB0;
    case 0x8004BEB4u: goto label_8004BEB4;
    case 0x8004BEB8u: goto label_8004BEB8;
    case 0x8004BEBCu: goto label_8004BEBC;
    case 0x8004BEC0u: goto label_8004BEC0;
    case 0x8004BEC4u: goto label_8004BEC4;
    case 0x8004BEC8u: goto label_8004BEC8;
    case 0x8004BECCu: goto label_8004BECC;
    case 0x8004BED0u: goto label_8004BED0;
    case 0x8004BED4u: goto label_8004BED4;
    case 0x8004BED8u: goto label_8004BED8;
    case 0x8004BEDCu: goto label_8004BEDC;
    case 0x8004BEE0u: goto label_8004BEE0;
    case 0x8004BEE4u: goto label_8004BEE4;
    case 0x8004BEE8u: goto label_8004BEE8;
    case 0x8004BEECu: goto label_8004BEEC;
    case 0x8004BEF0u: goto label_8004BEF0;
    case 0x8004BEF4u: goto label_8004BEF4;
    case 0x8004BEF8u: goto label_8004BEF8;
    case 0x8004BEFCu: goto label_8004BEFC;
    case 0x8004BF00u: goto label_8004BF00;
    case 0x8004BF04u: goto label_8004BF04;
    case 0x8004BF08u: goto label_8004BF08;
    case 0x8004BF0Cu: goto label_8004BF0C;
    case 0x8004BF10u: goto label_8004BF10;
    case 0x8004BF14u: goto label_8004BF14;
    case 0x8004BF18u: goto label_8004BF18;
    case 0x8004BF1Cu: goto label_8004BF1C;
    case 0x8004BF20u: goto label_8004BF20;
    case 0x8004BF24u: goto label_8004BF24;
    case 0x8004BF28u: goto label_8004BF28;
    case 0x8004BF2Cu: goto label_8004BF2C;
    case 0x8004BF30u: goto label_8004BF30;
    case 0x8004BF34u: goto label_8004BF34;
    case 0x8004BF38u: goto label_8004BF38;
    case 0x8004BF3Cu: goto label_8004BF3C;
    case 0x8004BF40u: goto label_8004BF40;
    case 0x8004BF44u: goto label_8004BF44;
    case 0x8004BF48u: goto label_8004BF48;
    case 0x8004BF4Cu: goto label_8004BF4C;
    case 0x8004BF50u: goto label_8004BF50;
    case 0x8004BF54u: goto label_8004BF54;
    case 0x8004BF58u: goto label_8004BF58;
    case 0x8004BF5Cu: goto label_8004BF5C;
    case 0x8004BF60u: goto label_8004BF60;
    case 0x8004BF64u: goto label_8004BF64;
    case 0x8004BF68u: goto label_8004BF68;
    case 0x8004BF6Cu: goto label_8004BF6C;
    case 0x8004BF70u: goto label_8004BF70;
    case 0x8004BF74u: goto label_8004BF74;
    case 0x8004BF78u: goto label_8004BF78;
    case 0x8004BF7Cu: goto label_8004BF7C;
    case 0x8004BF80u: goto label_8004BF80;
    case 0x8004BF84u: goto label_8004BF84;
    case 0x8004BF88u: goto label_8004BF88;
    case 0x8004BF8Cu: goto label_8004BF8C;
    case 0x8004BF90u: goto label_8004BF90;
    case 0x8004BF94u: goto label_8004BF94;
    case 0x8004BF98u: goto label_8004BF98;
    case 0x8004BF9Cu: goto label_8004BF9C;
    case 0x8004BFA0u: goto label_8004BFA0;
    case 0x8004BFA4u: goto label_8004BFA4;
    case 0x8004BFA8u: goto label_8004BFA8;
    case 0x8004BFACu: goto label_8004BFAC;
    case 0x8004BFB0u: goto label_8004BFB0;
    case 0x8004BFB4u: goto label_8004BFB4;
    case 0x8004BFB8u: goto label_8004BFB8;
    case 0x8004BFBCu: goto label_8004BFBC;
    case 0x8004BFC0u: goto label_8004BFC0;
    case 0x8004BFC4u: goto label_8004BFC4;
    case 0x8004BFC8u: goto label_8004BFC8;
    case 0x8004BFCCu: goto label_8004BFCC;
    case 0x8004BFD0u: goto label_8004BFD0;
    case 0x8004BFD4u: goto label_8004BFD4;
    case 0x8004BFD8u: goto label_8004BFD8;
    case 0x8004BFDCu: goto label_8004BFDC;
    case 0x8004BFE0u: goto label_8004BFE0;
    case 0x8004BFE4u: goto label_8004BFE4;
    case 0x8004BFE8u: goto label_8004BFE8;
    case 0x8004BFECu: goto label_8004BFEC;
    case 0x8004BFF0u: goto label_8004BFF0;
    case 0x8004BFF4u: goto label_8004BFF4;
    case 0x8004BFF8u: goto label_8004BFF8;
    case 0x8004BFFCu: goto label_8004BFFC;
    case 0x8004C000u: goto label_8004C000;
    case 0x8004C004u: goto label_8004C004;
    case 0x8004C008u: goto label_8004C008;
    case 0x8004C00Cu: goto label_8004C00C;
    case 0x8004C010u: goto label_8004C010;
    case 0x8004C014u: goto label_8004C014;
    case 0x8004C018u: goto label_8004C018;
    case 0x8004C01Cu: goto label_8004C01C;
    case 0x8004C020u: goto label_8004C020;
    case 0x8004C024u: goto label_8004C024;
    case 0x8004C028u: goto label_8004C028;
    case 0x8004C02Cu: goto label_8004C02C;
    case 0x8004C030u: goto label_8004C030;
    case 0x8004C034u: goto label_8004C034;
    case 0x8004C038u: goto label_8004C038;
    case 0x8004C03Cu: goto label_8004C03C;
    case 0x8004C040u: goto label_8004C040;
    case 0x8004C044u: goto label_8004C044;
    case 0x8004C048u: goto label_8004C048;
    case 0x8004C04Cu: goto label_8004C04C;
    case 0x8004C050u: goto label_8004C050;
    case 0x8004C054u: goto label_8004C054;
    case 0x8004C058u: goto label_8004C058;
    case 0x8004C05Cu: goto label_8004C05C;
    case 0x8004C060u: goto label_8004C060;
    case 0x8004C064u: goto label_8004C064;
    case 0x8004C068u: goto label_8004C068;
    case 0x8004C06Cu: goto label_8004C06C;
    case 0x8004C070u: goto label_8004C070;
    case 0x8004C074u: goto label_8004C074;
    case 0x8004C078u: goto label_8004C078;
    case 0x8004C07Cu: goto label_8004C07C;
    case 0x8004C080u: goto label_8004C080;
    case 0x8004C084u: goto label_8004C084;
    case 0x8004C088u: goto label_8004C088;
    case 0x8004C08Cu: goto label_8004C08C;
    case 0x8004C090u: goto label_8004C090;
    case 0x8004C094u: goto label_8004C094;
    case 0x8004C098u: goto label_8004C098;
    case 0x8004C09Cu: goto label_8004C09C;
    case 0x8004C0A0u: goto label_8004C0A0;
    case 0x8004C0A4u: goto label_8004C0A4;
    case 0x8004C0A8u: goto label_8004C0A8;
    case 0x8004C0ACu: goto label_8004C0AC;
    case 0x8004C0B0u: goto label_8004C0B0;
    case 0x8004C0B4u: goto label_8004C0B4;
    case 0x8004C0B8u: goto label_8004C0B8;
    case 0x8004C0BCu: goto label_8004C0BC;
    case 0x8004C0C0u: goto label_8004C0C0;
    case 0x8004C0C4u: goto label_8004C0C4;
    case 0x8004C0C8u: goto label_8004C0C8;
    case 0x8004C0CCu: goto label_8004C0CC;
    case 0x8004C0D0u: goto label_8004C0D0;
    case 0x8004C0D4u: goto label_8004C0D4;
    case 0x8004C0D8u: goto label_8004C0D8;
    case 0x8004C0DCu: goto label_8004C0DC;
    case 0x8004C0E0u: goto label_8004C0E0;
    case 0x8004C0E4u: goto label_8004C0E4;
    case 0x8004C0E8u: goto label_8004C0E8;
    case 0x8004C0ECu: goto label_8004C0EC;
    case 0x8004C0F0u: goto label_8004C0F0;
    case 0x8004C0F4u: goto label_8004C0F4;
    case 0x8004C0F8u: goto label_8004C0F8;
    case 0x8004C0FCu: goto label_8004C0FC;
    case 0x8004C100u: goto label_8004C100;
    case 0x8004C104u: goto label_8004C104;
    case 0x8004C108u: goto label_8004C108;
    case 0x8004C10Cu: goto label_8004C10C;
    case 0x8004C110u: goto label_8004C110;
    case 0x8004C114u: goto label_8004C114;
    case 0x8004C118u: goto label_8004C118;
    case 0x8004C11Cu: goto label_8004C11C;
    case 0x8004C120u: goto label_8004C120;
    case 0x8004C124u: goto label_8004C124;
    case 0x8004C128u: goto label_8004C128;
    case 0x8004C12Cu: goto label_8004C12C;
    case 0x8004C130u: goto label_8004C130;
    case 0x8004C134u: goto label_8004C134;
    case 0x8004C138u: goto label_8004C138;
    case 0x8004C13Cu: goto label_8004C13C;
    case 0x8004C140u: goto label_8004C140;
    case 0x8004C144u: goto label_8004C144;
    case 0x8004C148u: goto label_8004C148;
    case 0x8004C14Cu: goto label_8004C14C;
    case 0x8004C150u: goto label_8004C150;
    case 0x8004C154u: goto label_8004C154;
    case 0x8004C158u: goto label_8004C158;
    case 0x8004C15Cu: goto label_8004C15C;
    case 0x8004C160u: goto label_8004C160;
    case 0x8004C164u: goto label_8004C164;
    case 0x8004C168u: goto label_8004C168;
    case 0x8004C16Cu: goto label_8004C16C;
    case 0x8004C170u: goto label_8004C170;
    case 0x8004C174u: goto label_8004C174;
    case 0x8004C178u: goto label_8004C178;
    case 0x8004C17Cu: goto label_8004C17C;
    case 0x8004C180u: goto label_8004C180;
    case 0x8004C184u: goto label_8004C184;
    case 0x8004C188u: goto label_8004C188;
    case 0x8004C18Cu: goto label_8004C18C;
    case 0x8004C190u: goto label_8004C190;
    case 0x8004C194u: goto label_8004C194;
    case 0x8004C198u: goto label_8004C198;
    case 0x8004C19Cu: goto label_8004C19C;
    case 0x8004C1A0u: goto label_8004C1A0;
    case 0x8004C1A4u: goto label_8004C1A4;
    case 0x8004C1A8u: goto label_8004C1A8;
    case 0x8004C1ACu: goto label_8004C1AC;
    case 0x8004C1B0u: goto label_8004C1B0;
    case 0x8004C1B4u: goto label_8004C1B4;
    case 0x8004C1B8u: goto label_8004C1B8;
    case 0x8004C1BCu: goto label_8004C1BC;
    case 0x8004C1C0u: goto label_8004C1C0;
    case 0x8004C1C4u: goto label_8004C1C4;
    case 0x8004C1C8u: goto label_8004C1C8;
    case 0x8004C1CCu: goto label_8004C1CC;
    case 0x8004C1D0u: goto label_8004C1D0;
    case 0x8004C1D4u: goto label_8004C1D4;
    case 0x8004C1D8u: goto label_8004C1D8;
    case 0x8004C1DCu: goto label_8004C1DC;
    case 0x8004C1E0u: goto label_8004C1E0;
    case 0x8004C1E4u: goto label_8004C1E4;
    case 0x8004C1E8u: goto label_8004C1E8;
    case 0x8004C1ECu: goto label_8004C1EC;
    case 0x8004C1F0u: goto label_8004C1F0;
    case 0x8004C1F4u: goto label_8004C1F4;
    case 0x8004C1F8u: goto label_8004C1F8;
    case 0x8004C1FCu: goto label_8004C1FC;
    case 0x8004C200u: goto label_8004C200;
    case 0x8004C204u: goto label_8004C204;
    case 0x8004C208u: goto label_8004C208;
    case 0x8004C20Cu: goto label_8004C20C;
    case 0x8004C210u: goto label_8004C210;
    case 0x8004C214u: goto label_8004C214;
    case 0x8004C218u: goto label_8004C218;
    case 0x8004C21Cu: goto label_8004C21C;
    case 0x8004C220u: goto label_8004C220;
    case 0x8004C224u: goto label_8004C224;
    case 0x8004C228u: goto label_8004C228;
    case 0x8004C22Cu: goto label_8004C22C;
    case 0x8004C230u: goto label_8004C230;
    case 0x8004C234u: goto label_8004C234;
    case 0x8004C238u: goto label_8004C238;
    case 0x8004C23Cu: goto label_8004C23C;
    case 0x8004C240u: goto label_8004C240;
    case 0x8004C244u: goto label_8004C244;
    case 0x8004C248u: goto label_8004C248;
    case 0x8004C24Cu: goto label_8004C24C;
    case 0x8004C250u: goto label_8004C250;
    case 0x8004C254u: goto label_8004C254;
    case 0x8004C258u: goto label_8004C258;
    case 0x8004C25Cu: goto label_8004C25C;
    case 0x8004C260u: goto label_8004C260;
    case 0x8004C264u: goto label_8004C264;
    case 0x8004C268u: goto label_8004C268;
    case 0x8004C26Cu: goto label_8004C26C;
    case 0x8004C270u: goto label_8004C270;
    case 0x8004C274u: goto label_8004C274;
    case 0x8004C278u: goto label_8004C278;
    case 0x8004C27Cu: goto label_8004C27C;
    case 0x8004C280u: goto label_8004C280;
    case 0x8004C284u: goto label_8004C284;
    case 0x8004C288u: goto label_8004C288;
    case 0x8004C28Cu: goto label_8004C28C;
    case 0x8004C290u: goto label_8004C290;
    case 0x8004C294u: goto label_8004C294;
    case 0x8004C298u: goto label_8004C298;
    case 0x8004C29Cu: goto label_8004C29C;
    case 0x8004C2A0u: goto label_8004C2A0;
    case 0x8004C2A4u: goto label_8004C2A4;
    case 0x8004C2A8u: goto label_8004C2A8;
    case 0x8004C2ACu: goto label_8004C2AC;
    case 0x8004C2B0u: goto label_8004C2B0;
    case 0x8004C2B4u: goto label_8004C2B4;
    case 0x8004C2B8u: goto label_8004C2B8;
    case 0x8004C2BCu: goto label_8004C2BC;
    case 0x8004C2C0u: goto label_8004C2C0;
    case 0x8004C2C4u: goto label_8004C2C4;
    case 0x8004C2C8u: goto label_8004C2C8;
    case 0x8004C2CCu: goto label_8004C2CC;
    case 0x8004C2D0u: goto label_8004C2D0;
    case 0x8004C2D4u: goto label_8004C2D4;
    case 0x8004C2D8u: goto label_8004C2D8;
    case 0x8004C2DCu: goto label_8004C2DC;
    case 0x8004C2E0u: goto label_8004C2E0;
    case 0x8004C2E4u: goto label_8004C2E4;
    case 0x8004C2E8u: goto label_8004C2E8;
    case 0x8004C2ECu: goto label_8004C2EC;
    case 0x8004C2F0u: goto label_8004C2F0;
    case 0x8004C2F4u: goto label_8004C2F4;
    case 0x8004C2F8u: goto label_8004C2F8;
    case 0x8004C2FCu: goto label_8004C2FC;
    case 0x8004C300u: goto label_8004C300;
    case 0x8004C304u: goto label_8004C304;
    case 0x8004C308u: goto label_8004C308;
    case 0x8004C30Cu: goto label_8004C30C;
    case 0x8004C310u: goto label_8004C310;
    case 0x8004C314u: goto label_8004C314;
    case 0x8004C318u: goto label_8004C318;
    case 0x8004C31Cu: goto label_8004C31C;
    case 0x8004C320u: goto label_8004C320;
    case 0x8004C324u: goto label_8004C324;
    case 0x8004C328u: goto label_8004C328;
    case 0x8004C32Cu: goto label_8004C32C;
    case 0x8004C330u: goto label_8004C330;
    case 0x8004C334u: goto label_8004C334;
    case 0x8004C338u: goto label_8004C338;
    case 0x8004C33Cu: goto label_8004C33C;
    case 0x8004C340u: goto label_8004C340;
    case 0x8004C344u: goto label_8004C344;
    case 0x8004C348u: goto label_8004C348;
    case 0x8004C34Cu: goto label_8004C34C;
    case 0x8004C350u: goto label_8004C350;
    case 0x8004C354u: goto label_8004C354;
    case 0x8004C358u: goto label_8004C358;
    case 0x8004C35Cu: goto label_8004C35C;
    case 0x8004C360u: goto label_8004C360;
    case 0x8004C364u: goto label_8004C364;
    case 0x8004C368u: goto label_8004C368;
    case 0x8004C36Cu: goto label_8004C36C;
    case 0x8004C370u: goto label_8004C370;
    case 0x8004C374u: goto label_8004C374;
    case 0x8004C378u: goto label_8004C378;
    case 0x8004C37Cu: goto label_8004C37C;
    case 0x8004C380u: goto label_8004C380;
    case 0x8004C384u: goto label_8004C384;
    case 0x8004C388u: goto label_8004C388;
    case 0x8004C38Cu: goto label_8004C38C;
    case 0x8004C390u: goto label_8004C390;
    case 0x8004C394u: goto label_8004C394;
    case 0x8004C398u: goto label_8004C398;
    case 0x8004C39Cu: goto label_8004C39C;
    case 0x8004C3A0u: goto label_8004C3A0;
    case 0x8004C3A4u: goto label_8004C3A4;
    case 0x8004C3A8u: goto label_8004C3A8;
    case 0x8004C3ACu: goto label_8004C3AC;
    case 0x8004C3B0u: goto label_8004C3B0;
    case 0x8004C3B4u: goto label_8004C3B4;
    case 0x8004C3B8u: goto label_8004C3B8;
    case 0x8004C3BCu: goto label_8004C3BC;
    case 0x8004C3C0u: goto label_8004C3C0;
    case 0x8004C3C4u: goto label_8004C3C4;
    case 0x8004C3C8u: goto label_8004C3C8;
    case 0x8004C3CCu: goto label_8004C3CC;
    case 0x8004C3D0u: goto label_8004C3D0;
    case 0x8004C3D4u: goto label_8004C3D4;
    case 0x8004C3D8u: goto label_8004C3D8;
    case 0x8004C3DCu: goto label_8004C3DC;
    case 0x8004C3E0u: goto label_8004C3E0;
    case 0x8004C3E4u: goto label_8004C3E4;
    case 0x8004C3E8u: goto label_8004C3E8;
    case 0x8004C3ECu: goto label_8004C3EC;
    case 0x8004C3F0u: goto label_8004C3F0;
    case 0x8004C3F4u: goto label_8004C3F4;
    case 0x8004C3F8u: goto label_8004C3F8;
    case 0x8004C3FCu: goto label_8004C3FC;
    case 0x8004C400u: goto label_8004C400;
    case 0x8004C404u: goto label_8004C404;
    case 0x8004C408u: goto label_8004C408;
    case 0x8004C40Cu: goto label_8004C40C;
    case 0x8004C410u: goto label_8004C410;
    case 0x8004C414u: goto label_8004C414;
    case 0x8004C418u: goto label_8004C418;
    case 0x8004C41Cu: goto label_8004C41C;
    case 0x8004C420u: goto label_8004C420;
    case 0x8004C424u: goto label_8004C424;
    case 0x8004C428u: goto label_8004C428;
    case 0x8004C42Cu: goto label_8004C42C;
    case 0x8004C430u: goto label_8004C430;
    case 0x8004C434u: goto label_8004C434;
    case 0x8004C438u: goto label_8004C438;
    case 0x8004C43Cu: goto label_8004C43C;
    case 0x8004C440u: goto label_8004C440;
    case 0x8004C444u: goto label_8004C444;
    case 0x8004C448u: goto label_8004C448;
    case 0x8004C44Cu: goto label_8004C44C;
    case 0x8004C450u: goto label_8004C450;
    case 0x8004C454u: goto label_8004C454;
    case 0x8004C458u: goto label_8004C458;
    case 0x8004C45Cu: goto label_8004C45C;
    case 0x8004C460u: goto label_8004C460;
    case 0x8004C464u: goto label_8004C464;
    case 0x8004C468u: goto label_8004C468;
    case 0x8004C46Cu: goto label_8004C46C;
    case 0x8004C470u: goto label_8004C470;
    case 0x8004C474u: goto label_8004C474;
    case 0x8004C478u: goto label_8004C478;
    case 0x8004C47Cu: goto label_8004C47C;
    case 0x8004C480u: goto label_8004C480;
    case 0x8004C484u: goto label_8004C484;
    case 0x8004C488u: goto label_8004C488;
    case 0x8004C48Cu: goto label_8004C48C;
    case 0x8004C490u: goto label_8004C490;
    case 0x8004C494u: goto label_8004C494;
    case 0x8004C498u: goto label_8004C498;
    case 0x8004C49Cu: goto label_8004C49C;
    case 0x8004C4A0u: goto label_8004C4A0;
    case 0x8004C4A4u: goto label_8004C4A4;
    case 0x8004C4A8u: goto label_8004C4A8;
    case 0x8004C4ACu: goto label_8004C4AC;
    case 0x8004C4B0u: goto label_8004C4B0;
    case 0x8004C4B4u: goto label_8004C4B4;
    case 0x8004C4B8u: goto label_8004C4B8;
    case 0x8004C4BCu: goto label_8004C4BC;
    case 0x8004C4C0u: goto label_8004C4C0;
    case 0x8004C4C4u: goto label_8004C4C4;
    case 0x8004C4C8u: goto label_8004C4C8;
    case 0x8004C4CCu: goto label_8004C4CC;
    case 0x8004C4D0u: goto label_8004C4D0;
    case 0x8004C4D4u: goto label_8004C4D4;
    case 0x8004C4D8u: goto label_8004C4D8;
    case 0x8004C4DCu: goto label_8004C4DC;
    case 0x8004C4E0u: goto label_8004C4E0;
    case 0x8004C4E4u: goto label_8004C4E4;
    case 0x8004C4E8u: goto label_8004C4E8;
    case 0x8004C4ECu: goto label_8004C4EC;
    case 0x8004C4F0u: goto label_8004C4F0;
    case 0x8004C4F4u: goto label_8004C4F4;
    case 0x8004C4F8u: goto label_8004C4F8;
    case 0x8004C4FCu: goto label_8004C4FC;
    case 0x8004C500u: goto label_8004C500;
    case 0x8004C504u: goto label_8004C504;
    case 0x8004C508u: goto label_8004C508;
    case 0x8004C50Cu: goto label_8004C50C;
    case 0x8004C510u: goto label_8004C510;
    case 0x8004C514u: goto label_8004C514;
    case 0x8004C518u: goto label_8004C518;
    case 0x8004C51Cu: goto label_8004C51C;
    case 0x8004C520u: goto label_8004C520;
    case 0x8004C524u: goto label_8004C524;
    case 0x8004C528u: goto label_8004C528;
    case 0x8004C52Cu: goto label_8004C52C;
    case 0x8004C530u: goto label_8004C530;
    case 0x8004C534u: goto label_8004C534;
    case 0x8004C538u: goto label_8004C538;
    case 0x8004C53Cu: goto label_8004C53C;
    case 0x8004C540u: goto label_8004C540;
    case 0x8004C544u: goto label_8004C544;
    case 0x8004C548u: goto label_8004C548;
    case 0x8004C54Cu: goto label_8004C54C;
    case 0x8004C550u: goto label_8004C550;
    case 0x8004C554u: goto label_8004C554;
    case 0x8004C558u: goto label_8004C558;
    case 0x8004C55Cu: goto label_8004C55C;
    case 0x8004C560u: goto label_8004C560;
    case 0x8004C564u: goto label_8004C564;
    case 0x8004C568u: goto label_8004C568;
    case 0x8004C56Cu: goto label_8004C56C;
    case 0x8004C570u: goto label_8004C570;
    case 0x8004C574u: goto label_8004C574;
    case 0x8004C578u: goto label_8004C578;
    case 0x8004C57Cu: goto label_8004C57C;
    case 0x8004C580u: goto label_8004C580;
    case 0x8004C584u: goto label_8004C584;
    case 0x8004C588u: goto label_8004C588;
    case 0x8004C58Cu: goto label_8004C58C;
    case 0x8004C590u: goto label_8004C590;
    case 0x8004C594u: goto label_8004C594;
    case 0x8004C598u: goto label_8004C598;
    case 0x8004C59Cu: goto label_8004C59C;
    case 0x8004C5A0u: goto label_8004C5A0;
    case 0x8004C5A4u: goto label_8004C5A4;
    case 0x8004C5A8u: goto label_8004C5A8;
    case 0x8004C5ACu: goto label_8004C5AC;
    case 0x8004C5B0u: goto label_8004C5B0;
    case 0x8004C5B4u: goto label_8004C5B4;
    case 0x8004C5B8u: goto label_8004C5B8;
    case 0x8004C5BCu: goto label_8004C5BC;
    case 0x8004C5C0u: goto label_8004C5C0;
    case 0x8004C5C4u: goto label_8004C5C4;
    case 0x8004C5C8u: goto label_8004C5C8;
    case 0x8004C5CCu: goto label_8004C5CC;
    case 0x8004C5D0u: goto label_8004C5D0;
    case 0x8004C5D4u: goto label_8004C5D4;
    case 0x8004C5D8u: goto label_8004C5D8;
    case 0x8004C5DCu: goto label_8004C5DC;
    case 0x8004C5E0u: goto label_8004C5E0;
    case 0x8004C5E4u: goto label_8004C5E4;
    case 0x8004C5E8u: goto label_8004C5E8;
    case 0x8004C5ECu: goto label_8004C5EC;
    case 0x8004C5F0u: goto label_8004C5F0;
    case 0x8004C5F4u: goto label_8004C5F4;
    case 0x8004C5F8u: goto label_8004C5F8;
    case 0x8004C5FCu: goto label_8004C5FC;
    case 0x8004C600u: goto label_8004C600;
    case 0x8004C604u: goto label_8004C604;
    case 0x8004C608u: goto label_8004C608;
    case 0x8004C60Cu: goto label_8004C60C;
    case 0x8004C610u: goto label_8004C610;
    case 0x8004C614u: goto label_8004C614;
    case 0x8004C618u: goto label_8004C618;
    case 0x8004C61Cu: goto label_8004C61C;
    case 0x8004C620u: goto label_8004C620;
    case 0x8004C624u: goto label_8004C624;
    case 0x8004C628u: goto label_8004C628;
    case 0x8004C62Cu: goto label_8004C62C;
    case 0x8004C630u: goto label_8004C630;
    case 0x8004C634u: goto label_8004C634;
    case 0x8004C638u: goto label_8004C638;
    case 0x8004C63Cu: goto label_8004C63C;
    case 0x8004C640u: goto label_8004C640;
    case 0x8004C644u: goto label_8004C644;
    case 0x8004C648u: goto label_8004C648;
    case 0x8004C64Cu: goto label_8004C64C;
    case 0x8004C650u: goto label_8004C650;
    case 0x8004C654u: goto label_8004C654;
    case 0x8004C658u: goto label_8004C658;
    case 0x8004C65Cu: goto label_8004C65C;
    case 0x8004C660u: goto label_8004C660;
    case 0x8004C664u: goto label_8004C664;
    case 0x8004C668u: goto label_8004C668;
    case 0x8004C66Cu: goto label_8004C66C;
    case 0x8004C670u: goto label_8004C670;
    case 0x8004C674u: goto label_8004C674;
    case 0x8004C678u: goto label_8004C678;
    case 0x8004C67Cu: goto label_8004C67C;
    case 0x8004C680u: goto label_8004C680;
    case 0x8004C684u: goto label_8004C684;
    case 0x8004C688u: goto label_8004C688;
    case 0x8004C68Cu: goto label_8004C68C;
    case 0x8004C690u: goto label_8004C690;
    case 0x8004C694u: goto label_8004C694;
    case 0x8004C698u: goto label_8004C698;
    case 0x8004C69Cu: goto label_8004C69C;
    case 0x8004C6A0u: goto label_8004C6A0;
    case 0x8004C6A4u: goto label_8004C6A4;
    case 0x8004C6A8u: goto label_8004C6A8;
    case 0x8004C6ACu: goto label_8004C6AC;
    case 0x8004C6B0u: goto label_8004C6B0;
    case 0x8004C6B4u: goto label_8004C6B4;
    case 0x8004C6B8u: goto label_8004C6B8;
    case 0x8004C6BCu: goto label_8004C6BC;
    case 0x8004C6C0u: goto label_8004C6C0;
    case 0x8004C6C4u: goto label_8004C6C4;
    case 0x8004C6C8u: goto label_8004C6C8;
    case 0x8004C6CCu: goto label_8004C6CC;
    case 0x8004C6D0u: goto label_8004C6D0;
    case 0x8004C6D4u: goto label_8004C6D4;
    case 0x8004C6D8u: goto label_8004C6D8;
    case 0x8004C6DCu: goto label_8004C6DC;
    case 0x8004C6E0u: goto label_8004C6E0;
    case 0x8004C6E4u: goto label_8004C6E4;
    case 0x8004C6E8u: goto label_8004C6E8;
    case 0x8004C6ECu: goto label_8004C6EC;
    case 0x8004C6F0u: goto label_8004C6F0;
    case 0x8004C6F4u: goto label_8004C6F4;
    case 0x8004C6F8u: goto label_8004C6F8;
    case 0x8004C6FCu: goto label_8004C6FC;
    case 0x8004C700u: goto label_8004C700;
    case 0x8004C704u: goto label_8004C704;
    case 0x8004C708u: goto label_8004C708;
    case 0x8004C70Cu: goto label_8004C70C;
    case 0x8004C710u: goto label_8004C710;
    case 0x8004C714u: goto label_8004C714;
    case 0x8004C718u: goto label_8004C718;
    case 0x8004C71Cu: goto label_8004C71C;
    case 0x8004C720u: goto label_8004C720;
    case 0x8004C724u: goto label_8004C724;
    case 0x8004C728u: goto label_8004C728;
    case 0x8004C72Cu: goto label_8004C72C;
    case 0x8004C730u: goto label_8004C730;
    case 0x8004C734u: goto label_8004C734;
    case 0x8004C738u: goto label_8004C738;
    case 0x8004C73Cu: goto label_8004C73C;
    case 0x8004C740u: goto label_8004C740;
    case 0x8004C744u: goto label_8004C744;
    case 0x8004C748u: goto label_8004C748;
    case 0x8004C74Cu: goto label_8004C74C;
    case 0x8004C750u: goto label_8004C750;
    case 0x8004C754u: goto label_8004C754;
    case 0x8004C758u: goto label_8004C758;
    case 0x8004C75Cu: goto label_8004C75C;
    case 0x8004C760u: goto label_8004C760;
    case 0x8004C764u: goto label_8004C764;
    case 0x8004C768u: goto label_8004C768;
    case 0x8004C76Cu: goto label_8004C76C;
    case 0x8004C770u: goto label_8004C770;
    case 0x8004C774u: goto label_8004C774;
    case 0x8004C778u: goto label_8004C778;
    case 0x8004C77Cu: goto label_8004C77C;
    case 0x8004C780u: goto label_8004C780;
    case 0x8004C784u: goto label_8004C784;
    case 0x8004C788u: goto label_8004C788;
    case 0x8004C78Cu: goto label_8004C78C;
    case 0x8004C790u: goto label_8004C790;
    case 0x8004C794u: goto label_8004C794;
    case 0x8004C798u: goto label_8004C798;
    case 0x8004C79Cu: goto label_8004C79C;
    case 0x8004C7A0u: goto label_8004C7A0;
    case 0x8004C7A4u: goto label_8004C7A4;
    case 0x8004C7A8u: goto label_8004C7A8;
    case 0x8004C7ACu: goto label_8004C7AC;
    case 0x8004C7B0u: goto label_8004C7B0;
    case 0x8004C7B4u: goto label_8004C7B4;
    case 0x8004C7B8u: goto label_8004C7B8;
    case 0x8004C7BCu: goto label_8004C7BC;
    case 0x8004C7C0u: goto label_8004C7C0;
    case 0x8004C7C4u: goto label_8004C7C4;
    case 0x8004C7C8u: goto label_8004C7C8;
    case 0x8004C7CCu: goto label_8004C7CC;
    case 0x8004C7D0u: goto label_8004C7D0;
    case 0x8004C7D4u: goto label_8004C7D4;
    case 0x8004C7D8u: goto label_8004C7D8;
    case 0x8004C7DCu: goto label_8004C7DC;
    case 0x8004C7E0u: goto label_8004C7E0;
    case 0x8004C7E4u: goto label_8004C7E4;
    case 0x8004C7E8u: goto label_8004C7E8;
    case 0x8004C7ECu: goto label_8004C7EC;
    case 0x8004C7F0u: goto label_8004C7F0;
    case 0x8004C7F4u: goto label_8004C7F4;
    case 0x8004C7F8u: goto label_8004C7F8;
    case 0x8004C7FCu: goto label_8004C7FC;
    case 0x8004C800u: goto label_8004C800;
    case 0x8004C804u: goto label_8004C804;
    case 0x8004C808u: goto label_8004C808;
    case 0x8004C80Cu: goto label_8004C80C;
    case 0x8004C810u: goto label_8004C810;
    case 0x8004C814u: goto label_8004C814;
    case 0x8004C818u: goto label_8004C818;
    case 0x8004C81Cu: goto label_8004C81C;
    case 0x8004C820u: goto label_8004C820;
    case 0x8004C824u: goto label_8004C824;
    case 0x8004C828u: goto label_8004C828;
    case 0x8004C82Cu: goto label_8004C82C;
    case 0x8004C830u: goto label_8004C830;
    case 0x8004C834u: goto label_8004C834;
    case 0x8004C838u: goto label_8004C838;
    case 0x8004C83Cu: goto label_8004C83C;
    case 0x8004C840u: goto label_8004C840;
    case 0x8004C844u: goto label_8004C844;
    case 0x8004C848u: goto label_8004C848;
    case 0x8004C84Cu: goto label_8004C84C;
    case 0x8004C850u: goto label_8004C850;
    case 0x8004C854u: goto label_8004C854;
    case 0x8004C858u: goto label_8004C858;
    case 0x8004C85Cu: goto label_8004C85C;
    case 0x8004C860u: goto label_8004C860;
    case 0x8004C864u: goto label_8004C864;
    case 0x8004C868u: goto label_8004C868;
    case 0x8004C86Cu: goto label_8004C86C;
    case 0x8004C870u: goto label_8004C870;
    case 0x8004C874u: goto label_8004C874;
    case 0x8004C878u: goto label_8004C878;
    case 0x8004C87Cu: goto label_8004C87C;
    case 0x8004C880u: goto label_8004C880;
    case 0x8004C884u: goto label_8004C884;
    case 0x8004C888u: goto label_8004C888;
    case 0x8004C88Cu: goto label_8004C88C;
    case 0x8004C890u: goto label_8004C890;
    case 0x8004C894u: goto label_8004C894;
    case 0x8004C898u: goto label_8004C898;
    case 0x8004C89Cu: goto label_8004C89C;
    case 0x8004C8A0u: goto label_8004C8A0;
    case 0x8004C8A4u: goto label_8004C8A4;
    case 0x8004C8A8u: goto label_8004C8A8;
    case 0x8004C8ACu: goto label_8004C8AC;
    case 0x8004C8B0u: goto label_8004C8B0;
    case 0x8004C8B4u: goto label_8004C8B4;
    case 0x8004C8B8u: goto label_8004C8B8;
    case 0x8004C8BCu: goto label_8004C8BC;
    case 0x8004C8C0u: goto label_8004C8C0;
    case 0x8004C8C4u: goto label_8004C8C4;
    case 0x8004C8C8u: goto label_8004C8C8;
    case 0x8004C8CCu: goto label_8004C8CC;
    case 0x8004C8D0u: goto label_8004C8D0;
    case 0x8004C8D4u: goto label_8004C8D4;
    case 0x8004C8D8u: goto label_8004C8D8;
    case 0x8004C8DCu: goto label_8004C8DC;
    case 0x8004C8E0u: goto label_8004C8E0;
    case 0x8004C8E4u: goto label_8004C8E4;
    case 0x8004C8E8u: goto label_8004C8E8;
    case 0x8004C8ECu: goto label_8004C8EC;
    case 0x8004C8F0u: goto label_8004C8F0;
    case 0x8004C8F4u: goto label_8004C8F4;
    case 0x8004C8F8u: goto label_8004C8F8;
    case 0x8004C8FCu: goto label_8004C8FC;
    case 0x8004C900u: goto label_8004C900;
    case 0x8004C904u: goto label_8004C904;
    case 0x8004C908u: goto label_8004C908;
    case 0x8004C90Cu: goto label_8004C90C;
    case 0x8004C910u: goto label_8004C910;
    case 0x8004C914u: goto label_8004C914;
    case 0x8004C918u: goto label_8004C918;
    case 0x8004C91Cu: goto label_8004C91C;
    case 0x8004C920u: goto label_8004C920;
    case 0x8004C924u: goto label_8004C924;
    case 0x8004C928u: goto label_8004C928;
    case 0x8004C92Cu: goto label_8004C92C;
    case 0x8004C930u: goto label_8004C930;
    case 0x8004C934u: goto label_8004C934;
    case 0x8004C938u: goto label_8004C938;
    case 0x8004C93Cu: goto label_8004C93C;
    case 0x8004C940u: goto label_8004C940;
    case 0x8004C944u: goto label_8004C944;
    case 0x8004C948u: goto label_8004C948;
    case 0x8004C94Cu: goto label_8004C94C;
    case 0x8004C950u: goto label_8004C950;
    case 0x8004C954u: goto label_8004C954;
    case 0x8004C958u: goto label_8004C958;
    case 0x8004C95Cu: goto label_8004C95C;
    case 0x8004C960u: goto label_8004C960;
    case 0x8004C964u: goto label_8004C964;
    case 0x8004C968u: goto label_8004C968;
    case 0x8004C96Cu: goto label_8004C96C;
    case 0x8004C970u: goto label_8004C970;
    case 0x8004C974u: goto label_8004C974;
    case 0x8004C978u: goto label_8004C978;
    case 0x8004C97Cu: goto label_8004C97C;
    case 0x8004C980u: goto label_8004C980;
    case 0x8004C984u: goto label_8004C984;
    case 0x8004C988u: goto label_8004C988;
    case 0x8004C98Cu: goto label_8004C98C;
    case 0x8004C990u: goto label_8004C990;
    case 0x8004C994u: goto label_8004C994;
    case 0x8004C998u: goto label_8004C998;
    case 0x8004C99Cu: goto label_8004C99C;
    case 0x8004C9A0u: goto label_8004C9A0;
    case 0x8004C9A4u: goto label_8004C9A4;
    case 0x8004C9A8u: goto label_8004C9A8;
    case 0x8004C9ACu: goto label_8004C9AC;
    case 0x8004C9B0u: goto label_8004C9B0;
    case 0x8004C9B4u: goto label_8004C9B4;
    case 0x8004C9B8u: goto label_8004C9B8;
    case 0x8004C9BCu: goto label_8004C9BC;
    case 0x8004C9C0u: goto label_8004C9C0;
    case 0x8004C9C4u: goto label_8004C9C4;
    case 0x8004C9C8u: goto label_8004C9C8;
    case 0x8004C9CCu: goto label_8004C9CC;
    case 0x8004C9D0u: goto label_8004C9D0;
    case 0x8004C9D4u: goto label_8004C9D4;
    case 0x8004C9D8u: goto label_8004C9D8;
    case 0x8004C9DCu: goto label_8004C9DC;
    case 0x8004C9E0u: goto label_8004C9E0;
    case 0x8004C9E4u: goto label_8004C9E4;
    case 0x8004C9E8u: goto label_8004C9E8;
    case 0x8004C9ECu: goto label_8004C9EC;
    case 0x8004C9F0u: goto label_8004C9F0;
    case 0x8004C9F4u: goto label_8004C9F4;
    case 0x8004C9F8u: goto label_8004C9F8;
    case 0x8004C9FCu: goto label_8004C9FC;
    case 0x8004CA00u: goto label_8004CA00;
    case 0x8004CA04u: goto label_8004CA04;
    case 0x8004CA08u: goto label_8004CA08;
    case 0x8004CA0Cu: goto label_8004CA0C;
    case 0x8004CA10u: goto label_8004CA10;
    case 0x8004CA14u: goto label_8004CA14;
    case 0x8004CA18u: goto label_8004CA18;
    case 0x8004CA1Cu: goto label_8004CA1C;
    case 0x8004CA20u: goto label_8004CA20;
    case 0x8004CA24u: goto label_8004CA24;
    case 0x8004CA28u: goto label_8004CA28;
    case 0x8004CA2Cu: goto label_8004CA2C;
    case 0x8004CA30u: goto label_8004CA30;
    case 0x8004CA34u: goto label_8004CA34;
    case 0x8004CA38u: goto label_8004CA38;
    case 0x8004CA3Cu: goto label_8004CA3C;
    case 0x8004CA40u: goto label_8004CA40;
    case 0x8004CA44u: goto label_8004CA44;
    case 0x8004CA48u: goto label_8004CA48;
    case 0x8004CA4Cu: goto label_8004CA4C;
    case 0x8004CA50u: goto label_8004CA50;
    case 0x8004CA54u: goto label_8004CA54;
    case 0x8004CA58u: goto label_8004CA58;
    case 0x8004CA5Cu: goto label_8004CA5C;
    case 0x8004CA60u: goto label_8004CA60;
    case 0x8004CA64u: goto label_8004CA64;
    case 0x8004CA68u: goto label_8004CA68;
    case 0x8004CA6Cu: goto label_8004CA6C;
    case 0x8004CA70u: goto label_8004CA70;
    case 0x8004CA74u: goto label_8004CA74;
    case 0x8004CA78u: goto label_8004CA78;
    case 0x8004CA7Cu: goto label_8004CA7C;
    case 0x8004CA80u: goto label_8004CA80;
    case 0x8004CA84u: goto label_8004CA84;
    case 0x8004CA88u: goto label_8004CA88;
    case 0x8004CA8Cu: goto label_8004CA8C;
    case 0x8004CA90u: goto label_8004CA90;
    case 0x8004CA94u: goto label_8004CA94;
    case 0x8004CA98u: goto label_8004CA98;
    case 0x8004CA9Cu: goto label_8004CA9C;
    case 0x8004CAA0u: goto label_8004CAA0;
    case 0x8004CAA4u: goto label_8004CAA4;
    case 0x8004CAA8u: goto label_8004CAA8;
    case 0x8004CAACu: goto label_8004CAAC;
    case 0x8004CAB0u: goto label_8004CAB0;
    case 0x8004CAB4u: goto label_8004CAB4;
    case 0x8004CAB8u: goto label_8004CAB8;
    case 0x8004CABCu: goto label_8004CABC;
    case 0x8004CAC0u: goto label_8004CAC0;
    case 0x8004CAC4u: goto label_8004CAC4;
    case 0x8004CAC8u: goto label_8004CAC8;
    case 0x8004CACCu: goto label_8004CACC;
    case 0x8004CAD0u: goto label_8004CAD0;
    case 0x8004CAD4u: goto label_8004CAD4;
    case 0x8004CAD8u: goto label_8004CAD8;
    case 0x8004CADCu: goto label_8004CADC;
    case 0x8004CAE0u: goto label_8004CAE0;
    case 0x8004CAE4u: goto label_8004CAE4;
    case 0x8004CAE8u: goto label_8004CAE8;
    case 0x8004CAECu: goto label_8004CAEC;
    case 0x8004CAF0u: goto label_8004CAF0;
    case 0x8004CAF4u: goto label_8004CAF4;
    case 0x8004CAF8u: goto label_8004CAF8;
    case 0x8004CAFCu: goto label_8004CAFC;
    case 0x8004CB00u: goto label_8004CB00;
    case 0x8004CB04u: goto label_8004CB04;
    case 0x8004CB08u: goto label_8004CB08;
    case 0x8004CB0Cu: goto label_8004CB0C;
    case 0x8004CB10u: goto label_8004CB10;
    case 0x8004CB14u: goto label_8004CB14;
    case 0x8004CB18u: goto label_8004CB18;
    case 0x8004CB1Cu: goto label_8004CB1C;
    case 0x8004CB20u: goto label_8004CB20;
    case 0x8004CB24u: goto label_8004CB24;
    case 0x8004CB28u: goto label_8004CB28;
    case 0x8004CB2Cu: goto label_8004CB2C;
    case 0x8004CB30u: goto label_8004CB30;
    case 0x8004CB34u: goto label_8004CB34;
    case 0x8004CB38u: goto label_8004CB38;
    case 0x8004CB3Cu: goto label_8004CB3C;
    case 0x8004CB40u: goto label_8004CB40;
    case 0x8004CB44u: goto label_8004CB44;
    case 0x8004CB48u: goto label_8004CB48;
    case 0x8004CB4Cu: goto label_8004CB4C;
    case 0x8004CB50u: goto label_8004CB50;
    case 0x8004CB54u: goto label_8004CB54;
    case 0x8004CB58u: goto label_8004CB58;
    case 0x8004CB5Cu: goto label_8004CB5C;
    case 0x8004CB60u: goto label_8004CB60;
    case 0x8004CB64u: goto label_8004CB64;
    case 0x8004CB68u: goto label_8004CB68;
    case 0x8004CB6Cu: goto label_8004CB6C;
    case 0x8004CB70u: goto label_8004CB70;
    case 0x8004CB74u: goto label_8004CB74;
    case 0x8004CB78u: goto label_8004CB78;
    case 0x8004CB7Cu: goto label_8004CB7C;
    case 0x8004CB80u: goto label_8004CB80;
    case 0x8004CB84u: goto label_8004CB84;
    case 0x8004CB88u: goto label_8004CB88;
    case 0x8004CB8Cu: goto label_8004CB8C;
    case 0x8004CB90u: goto label_8004CB90;
    case 0x8004CB94u: goto label_8004CB94;
    case 0x8004CB98u: goto label_8004CB98;
    case 0x8004CB9Cu: goto label_8004CB9C;
    case 0x8004CBA0u: goto label_8004CBA0;
    case 0x8004CBA4u: goto label_8004CBA4;
    case 0x8004CBA8u: goto label_8004CBA8;
    case 0x8004CBACu: goto label_8004CBAC;
    case 0x8004CBB0u: goto label_8004CBB0;
    case 0x8004CBB4u: goto label_8004CBB4;
    case 0x8004CBB8u: goto label_8004CBB8;
    case 0x8004CBBCu: goto label_8004CBBC;
    case 0x8004CBC0u: goto label_8004CBC0;
    case 0x8004CBC4u: goto label_8004CBC4;
    case 0x8004CBC8u: goto label_8004CBC8;
    case 0x8004CBCCu: goto label_8004CBCC;
    case 0x8004CBD0u: goto label_8004CBD0;
    case 0x8004CBD4u: goto label_8004CBD4;
    case 0x8004CBD8u: goto label_8004CBD8;
    case 0x8004CBDCu: goto label_8004CBDC;
    case 0x8004CBE0u: goto label_8004CBE0;
    case 0x8004CBE4u: goto label_8004CBE4;
    case 0x8004CBE8u: goto label_8004CBE8;
    case 0x8004CBECu: goto label_8004CBEC;
    case 0x8004CBF0u: goto label_8004CBF0;
    case 0x8004CBF4u: goto label_8004CBF4;
    case 0x8004CBF8u: goto label_8004CBF8;
    case 0x8004CBFCu: goto label_8004CBFC;
    case 0x8004CC00u: goto label_8004CC00;
    case 0x8004CC04u: goto label_8004CC04;
    case 0x8004CC08u: goto label_8004CC08;
    case 0x8004CC0Cu: goto label_8004CC0C;
    case 0x8004CC10u: goto label_8004CC10;
    case 0x8004CC14u: goto label_8004CC14;
    case 0x8004CC18u: goto label_8004CC18;
    case 0x8004CC1Cu: goto label_8004CC1C;
    case 0x8004CC20u: goto label_8004CC20;
    case 0x8004CC24u: goto label_8004CC24;
    case 0x8004CC28u: goto label_8004CC28;
    case 0x8004CC2Cu: goto label_8004CC2C;
    case 0x8004CC30u: goto label_8004CC30;
    case 0x8004CC34u: goto label_8004CC34;
    case 0x8004CC38u: goto label_8004CC38;
    case 0x8004CC3Cu: goto label_8004CC3C;
    case 0x8004CC40u: goto label_8004CC40;
    case 0x8004CC44u: goto label_8004CC44;
    case 0x8004CC48u: goto label_8004CC48;
    case 0x8004CC4Cu: goto label_8004CC4C;
    case 0x8004CC50u: goto label_8004CC50;
    case 0x8004CC54u: goto label_8004CC54;
    case 0x8004CC58u: goto label_8004CC58;
    case 0x8004CC5Cu: goto label_8004CC5C;
    case 0x8004CC60u: goto label_8004CC60;
    case 0x8004CC64u: goto label_8004CC64;
    case 0x8004CC68u: goto label_8004CC68;
    case 0x8004CC6Cu: goto label_8004CC6C;
    case 0x8004CC70u: goto label_8004CC70;
    case 0x8004CC74u: goto label_8004CC74;
    case 0x8004CC78u: goto label_8004CC78;
    case 0x8004CC7Cu: goto label_8004CC7C;
    case 0x8004CC80u: goto label_8004CC80;
    case 0x8004CC84u: goto label_8004CC84;
    case 0x8004CC88u: goto label_8004CC88;
    case 0x8004CC8Cu: goto label_8004CC8C;
    case 0x8004CC90u: goto label_8004CC90;
    case 0x8004CC94u: goto label_8004CC94;
    case 0x8004CC98u: goto label_8004CC98;
    case 0x8004CC9Cu: goto label_8004CC9C;
    case 0x8004CCA0u: goto label_8004CCA0;
    case 0x8004CCA4u: goto label_8004CCA4;
    case 0x8004CCA8u: goto label_8004CCA8;
    case 0x8004CCACu: goto label_8004CCAC;
    case 0x8004CCB0u: goto label_8004CCB0;
    case 0x8004CCB4u: goto label_8004CCB4;
    case 0x8004CCB8u: goto label_8004CCB8;
    case 0x8004CCBCu: goto label_8004CCBC;
    case 0x8004CCC0u: goto label_8004CCC0;
    case 0x8004CCC4u: goto label_8004CCC4;
    case 0x8004CCC8u: goto label_8004CCC8;
    case 0x8004CCCCu: goto label_8004CCCC;
    case 0x8004CCD0u: goto label_8004CCD0;
    case 0x8004CCD4u: goto label_8004CCD4;
    case 0x8004CCD8u: goto label_8004CCD8;
    case 0x8004CCDCu: goto label_8004CCDC;
    case 0x8004CCE0u: goto label_8004CCE0;
    case 0x8004CCE4u: goto label_8004CCE4;
    case 0x8004CCE8u: goto label_8004CCE8;
    case 0x8004CCECu: goto label_8004CCEC;
    case 0x8004CCF0u: goto label_8004CCF0;
    case 0x8004CCF4u: goto label_8004CCF4;
    case 0x8004CCF8u: goto label_8004CCF8;
    case 0x8004CCFCu: goto label_8004CCFC;
    case 0x8004CD00u: goto label_8004CD00;
    case 0x8004CD04u: goto label_8004CD04;
    case 0x8004CD08u: goto label_8004CD08;
    case 0x8004CD0Cu: goto label_8004CD0C;
    case 0x8004CD10u: goto label_8004CD10;
    case 0x8004CD14u: goto label_8004CD14;
    case 0x8004CD18u: goto label_8004CD18;
    case 0x8004CD1Cu: goto label_8004CD1C;
    case 0x8004CD20u: goto label_8004CD20;
    case 0x8004CD24u: goto label_8004CD24;
    case 0x8004CD28u: goto label_8004CD28;
    case 0x8004CD2Cu: goto label_8004CD2C;
    case 0x8004CD30u: goto label_8004CD30;
    case 0x8004CD34u: goto label_8004CD34;
    case 0x8004CD38u: goto label_8004CD38;
    case 0x8004CD3Cu: goto label_8004CD3C;
    case 0x8004CD40u: goto label_8004CD40;
    case 0x8004CD44u: goto label_8004CD44;
    case 0x8004CD48u: goto label_8004CD48;
    case 0x8004CD4Cu: goto label_8004CD4C;
    case 0x8004CD50u: goto label_8004CD50;
    case 0x8004CD54u: goto label_8004CD54;
    case 0x8004CD58u: goto label_8004CD58;
    case 0x8004CD5Cu: goto label_8004CD5C;
    case 0x8004CD60u: goto label_8004CD60;
    case 0x8004CD64u: goto label_8004CD64;
    case 0x8004CD68u: goto label_8004CD68;
    case 0x8004CD6Cu: goto label_8004CD6C;
    case 0x8004CD70u: goto label_8004CD70;
    case 0x8004CD74u: goto label_8004CD74;
    case 0x8004CD78u: goto label_8004CD78;
    case 0x8004CD7Cu: goto label_8004CD7C;
    case 0x8004CD80u: goto label_8004CD80;
    case 0x8004CD84u: goto label_8004CD84;
    case 0x8004CD88u: goto label_8004CD88;
    case 0x8004CD8Cu: goto label_8004CD8C;
    case 0x8004CD90u: goto label_8004CD90;
    case 0x8004CD94u: goto label_8004CD94;
    case 0x8004CD98u: goto label_8004CD98;
    case 0x8004CD9Cu: goto label_8004CD9C;
    case 0x8004CDA0u: goto label_8004CDA0;
    case 0x8004CDA4u: goto label_8004CDA4;
    case 0x8004CDA8u: goto label_8004CDA8;
    case 0x8004CDACu: goto label_8004CDAC;
    case 0x8004CDB0u: goto label_8004CDB0;
    case 0x8004CDB4u: goto label_8004CDB4;
    case 0x8004CDB8u: goto label_8004CDB8;
    case 0x8004CDBCu: goto label_8004CDBC;
    case 0x8004CDC0u: goto label_8004CDC0;
    case 0x8004CDC4u: goto label_8004CDC4;
    case 0x8004CDC8u: goto label_8004CDC8;
    case 0x8004CDCCu: goto label_8004CDCC;
    case 0x8004CDD0u: goto label_8004CDD0;
    case 0x8004CDD4u: goto label_8004CDD4;
    case 0x8004CDD8u: goto label_8004CDD8;
    case 0x8004CDDCu: goto label_8004CDDC;
    case 0x8004CDE0u: goto label_8004CDE0;
    case 0x8004CDE4u: goto label_8004CDE4;
    case 0x8004CDE8u: goto label_8004CDE8;
    case 0x8004CDECu: goto label_8004CDEC;
    case 0x8004CDF0u: goto label_8004CDF0;
    case 0x8004CDF4u: goto label_8004CDF4;
    case 0x8004CDF8u: goto label_8004CDF8;
    case 0x8004CDFCu: goto label_8004CDFC;
    case 0x8004CE00u: goto label_8004CE00;
    case 0x8004CE04u: goto label_8004CE04;
    case 0x8004CE08u: goto label_8004CE08;
    case 0x8004CE0Cu: goto label_8004CE0C;
    case 0x8004CE10u: goto label_8004CE10;
    case 0x8004CE14u: goto label_8004CE14;
    case 0x8004CE18u: goto label_8004CE18;
    case 0x8004CE1Cu: goto label_8004CE1C;
    case 0x8004CE20u: goto label_8004CE20;
    case 0x8004CE24u: goto label_8004CE24;
    case 0x8004CE28u: goto label_8004CE28;
    case 0x8004CE2Cu: goto label_8004CE2C;
    case 0x8004CE30u: goto label_8004CE30;
    case 0x8004CE34u: goto label_8004CE34;
    case 0x8004CE38u: goto label_8004CE38;
    case 0x8004CE3Cu: goto label_8004CE3C;
    case 0x8004CE40u: goto label_8004CE40;
    case 0x8004CE44u: goto label_8004CE44;
    case 0x8004CE48u: goto label_8004CE48;
    case 0x8004CE4Cu: goto label_8004CE4C;
    case 0x8004CE50u: goto label_8004CE50;
    case 0x8004CE54u: goto label_8004CE54;
    case 0x8004CE58u: goto label_8004CE58;
    case 0x8004CE5Cu: goto label_8004CE5C;
    case 0x8004CE60u: goto label_8004CE60;
    case 0x8004CE64u: goto label_8004CE64;
    case 0x8004CE68u: goto label_8004CE68;
    case 0x8004CE6Cu: goto label_8004CE6C;
    case 0x8004CE70u: goto label_8004CE70;
    case 0x8004CE74u: goto label_8004CE74;
    case 0x8004CE78u: goto label_8004CE78;
    case 0x8004CE7Cu: goto label_8004CE7C;
    case 0x8004CE80u: goto label_8004CE80;
    case 0x8004CE84u: goto label_8004CE84;
    case 0x8004CE88u: goto label_8004CE88;
    case 0x8004CE8Cu: goto label_8004CE8C;
    case 0x8004CE90u: goto label_8004CE90;
    case 0x8004CE94u: goto label_8004CE94;
    case 0x8004CE98u: goto label_8004CE98;
    case 0x8004CE9Cu: goto label_8004CE9C;
    case 0x8004CEA0u: goto label_8004CEA0;
    case 0x8004CEA4u: goto label_8004CEA4;
    case 0x8004CEA8u: goto label_8004CEA8;
    case 0x8004CEACu: goto label_8004CEAC;
    case 0x8004CEB0u: goto label_8004CEB0;
    case 0x8004CEB4u: goto label_8004CEB4;
    case 0x8004CEB8u: goto label_8004CEB8;
    case 0x8004CEBCu: goto label_8004CEBC;
    case 0x8004CEC0u: goto label_8004CEC0;
    case 0x8004CEC4u: goto label_8004CEC4;
    case 0x8004CEC8u: goto label_8004CEC8;
    case 0x8004CECCu: goto label_8004CECC;
    case 0x8004CED0u: goto label_8004CED0;
    case 0x8004CED4u: goto label_8004CED4;
    case 0x8004CED8u: goto label_8004CED8;
    case 0x8004CEDCu: goto label_8004CEDC;
    case 0x8004CEE0u: goto label_8004CEE0;
    case 0x8004CEE4u: goto label_8004CEE4;
    case 0x8004CEE8u: goto label_8004CEE8;
    case 0x8004CEECu: goto label_8004CEEC;
    case 0x8004CEF0u: goto label_8004CEF0;
    case 0x8004CEF4u: goto label_8004CEF4;
    case 0x8004CEF8u: goto label_8004CEF8;
    case 0x8004CEFCu: goto label_8004CEFC;
    case 0x8004CF00u: goto label_8004CF00;
    case 0x8004CF04u: goto label_8004CF04;
    case 0x8004CF08u: goto label_8004CF08;
    case 0x8004CF0Cu: goto label_8004CF0C;
    case 0x8004CF10u: goto label_8004CF10;
    case 0x8004CF14u: goto label_8004CF14;
    case 0x8004CF18u: goto label_8004CF18;
    case 0x8004CF1Cu: goto label_8004CF1C;
    case 0x8004CF20u: goto label_8004CF20;
    case 0x8004CF24u: goto label_8004CF24;
    case 0x8004CF28u: goto label_8004CF28;
    case 0x8004CF2Cu: goto label_8004CF2C;
    case 0x8004CF30u: goto label_8004CF30;
    case 0x8004CF34u: goto label_8004CF34;
    case 0x8004CF38u: goto label_8004CF38;
    case 0x8004CF3Cu: goto label_8004CF3C;
    case 0x8004CF40u: goto label_8004CF40;
    case 0x8004CF44u: goto label_8004CF44;
    case 0x8004CF48u: goto label_8004CF48;
    case 0x8004CF4Cu: goto label_8004CF4C;
    case 0x8004CF50u: goto label_8004CF50;
    case 0x8004CF54u: goto label_8004CF54;
    case 0x8004CF58u: goto label_8004CF58;
    case 0x8004CF5Cu: goto label_8004CF5C;
    case 0x8004CF60u: goto label_8004CF60;
    case 0x8004CF64u: goto label_8004CF64;
    case 0x8004CF68u: goto label_8004CF68;
    case 0x8004CF6Cu: goto label_8004CF6C;
    case 0x8004CF70u: goto label_8004CF70;
    case 0x8004CF74u: goto label_8004CF74;
    case 0x8004CF78u: goto label_8004CF78;
    case 0x8004CF7Cu: goto label_8004CF7C;
    case 0x8004CF80u: goto label_8004CF80;
    case 0x8004CF84u: goto label_8004CF84;
    case 0x8004CF88u: goto label_8004CF88;
    case 0x8004CF8Cu: goto label_8004CF8C;
    case 0x8004CF90u: goto label_8004CF90;
    case 0x8004CF94u: goto label_8004CF94;
    case 0x8004CF98u: goto label_8004CF98;
    case 0x8004CF9Cu: goto label_8004CF9C;
    case 0x8004CFA0u: goto label_8004CFA0;
    case 0x8004CFA4u: goto label_8004CFA4;
    case 0x8004CFA8u: goto label_8004CFA8;
    case 0x8004CFACu: goto label_8004CFAC;
    case 0x8004CFB0u: goto label_8004CFB0;
    case 0x8004CFB4u: goto label_8004CFB4;
    case 0x8004CFB8u: goto label_8004CFB8;
    case 0x8004CFBCu: goto label_8004CFBC;
    case 0x8004CFC0u: goto label_8004CFC0;
    case 0x8004CFC4u: goto label_8004CFC4;
    case 0x8004CFC8u: goto label_8004CFC8;
    case 0x8004CFCCu: goto label_8004CFCC;
    case 0x8004CFD0u: goto label_8004CFD0;
    case 0x8004CFD4u: goto label_8004CFD4;
    case 0x8004CFD8u: goto label_8004CFD8;
    case 0x8004CFDCu: goto label_8004CFDC;
    case 0x8004CFE0u: goto label_8004CFE0;
    case 0x8004CFE4u: goto label_8004CFE4;
    case 0x8004CFE8u: goto label_8004CFE8;
    case 0x8004CFECu: goto label_8004CFEC;
    case 0x8004CFF0u: goto label_8004CFF0;
    case 0x8004CFF4u: goto label_8004CFF4;
    case 0x8004CFF8u: goto label_8004CFF8;
    case 0x8004CFFCu: goto label_8004CFFC;
    case 0x8004D000u: goto label_8004D000;
    case 0x8004D004u: goto label_8004D004;
    case 0x8004D008u: goto label_8004D008;
    case 0x8004D00Cu: goto label_8004D00C;
    case 0x8004D010u: goto label_8004D010;
    case 0x8004D014u: goto label_8004D014;
    case 0x8004D018u: goto label_8004D018;
    case 0x8004D01Cu: goto label_8004D01C;
    case 0x8004D020u: goto label_8004D020;
    case 0x8004D024u: goto label_8004D024;
    case 0x8004D028u: goto label_8004D028;
    case 0x8004D02Cu: goto label_8004D02C;
    case 0x8004D030u: goto label_8004D030;
    case 0x8004D034u: goto label_8004D034;
    case 0x8004D038u: goto label_8004D038;
    case 0x8004D03Cu: goto label_8004D03C;
    case 0x8004D040u: goto label_8004D040;
    case 0x8004D044u: goto label_8004D044;
    case 0x8004D048u: goto label_8004D048;
    case 0x8004D04Cu: goto label_8004D04C;
    case 0x8004D050u: goto label_8004D050;
    case 0x8004D054u: goto label_8004D054;
    case 0x8004D058u: goto label_8004D058;
    case 0x8004D05Cu: goto label_8004D05C;
    case 0x8004D060u: goto label_8004D060;
    case 0x8004D064u: goto label_8004D064;
    case 0x8004D068u: goto label_8004D068;
    case 0x8004D06Cu: goto label_8004D06C;
    case 0x8004D070u: goto label_8004D070;
    case 0x8004D074u: goto label_8004D074;
    case 0x8004D078u: goto label_8004D078;
    case 0x8004D07Cu: goto label_8004D07C;
    case 0x8004D080u: goto label_8004D080;
    case 0x8004D084u: goto label_8004D084;
    case 0x8004D088u: goto label_8004D088;
    case 0x8004D08Cu: goto label_8004D08C;
    case 0x8004D090u: goto label_8004D090;
    case 0x8004D094u: goto label_8004D094;
    case 0x8004D098u: goto label_8004D098;
    case 0x8004D09Cu: goto label_8004D09C;
    case 0x8004D0A0u: goto label_8004D0A0;
    case 0x8004D0A4u: goto label_8004D0A4;
    case 0x8004D0A8u: goto label_8004D0A8;
    case 0x8004D0ACu: goto label_8004D0AC;
    case 0x8004D0B0u: goto label_8004D0B0;
    case 0x8004D0B4u: goto label_8004D0B4;
    case 0x8004D0B8u: goto label_8004D0B8;
    case 0x8004D0BCu: goto label_8004D0BC;
    case 0x8004D0C0u: goto label_8004D0C0;
    case 0x8004D0C4u: goto label_8004D0C4;
    case 0x8004D0C8u: goto label_8004D0C8;
    case 0x8004D0CCu: goto label_8004D0CC;
    case 0x8004D0D0u: goto label_8004D0D0;
    case 0x8004D0D4u: goto label_8004D0D4;
    case 0x8004D0D8u: goto label_8004D0D8;
    case 0x8004D0DCu: goto label_8004D0DC;
    case 0x8004D0E0u: goto label_8004D0E0;
    case 0x8004D0E4u: goto label_8004D0E4;
    case 0x8004D0E8u: goto label_8004D0E8;
    case 0x8004D0ECu: goto label_8004D0EC;
    case 0x8004D0F0u: goto label_8004D0F0;
    case 0x8004D0F4u: goto label_8004D0F4;
    case 0x8004D0F8u: goto label_8004D0F8;
    case 0x8004D0FCu: goto label_8004D0FC;
    case 0x8004D100u: goto label_8004D100;
    case 0x8004D104u: goto label_8004D104;
    case 0x8004D108u: goto label_8004D108;
    case 0x8004D10Cu: goto label_8004D10C;
    case 0x8004D110u: goto label_8004D110;
    case 0x8004D114u: goto label_8004D114;
    case 0x8004D118u: goto label_8004D118;
    case 0x8004D11Cu: goto label_8004D11C;
    case 0x8004D120u: goto label_8004D120;
    case 0x8004D124u: goto label_8004D124;
    case 0x8004D128u: goto label_8004D128;
    case 0x8004D12Cu: goto label_8004D12C;
    case 0x8004D130u: goto label_8004D130;
    case 0x8004D134u: goto label_8004D134;
    case 0x8004D138u: goto label_8004D138;
    case 0x8004D13Cu: goto label_8004D13C;
    case 0x8004D140u: goto label_8004D140;
    case 0x8004D144u: goto label_8004D144;
    case 0x8004D148u: goto label_8004D148;
    case 0x8004D14Cu: goto label_8004D14C;
    case 0x8004D150u: goto label_8004D150;
    case 0x8004D154u: goto label_8004D154;
    case 0x8004D158u: goto label_8004D158;
    case 0x8004D15Cu: goto label_8004D15C;
    case 0x8004D160u: goto label_8004D160;
    case 0x8004D164u: goto label_8004D164;
    case 0x8004D168u: goto label_8004D168;
    case 0x8004D16Cu: goto label_8004D16C;
    case 0x8004D170u: goto label_8004D170;
    case 0x8004D174u: goto label_8004D174;
    case 0x8004D178u: goto label_8004D178;
    case 0x8004D17Cu: goto label_8004D17C;
    case 0x8004D180u: goto label_8004D180;
    case 0x8004D184u: goto label_8004D184;
    case 0x8004D188u: goto label_8004D188;
    case 0x8004D18Cu: goto label_8004D18C;
    case 0x8004D190u: goto label_8004D190;
    case 0x8004D194u: goto label_8004D194;
    case 0x8004D198u: goto label_8004D198;
    case 0x8004D19Cu: goto label_8004D19C;
    case 0x8004D1A0u: goto label_8004D1A0;
    case 0x8004D1A4u: goto label_8004D1A4;
    case 0x8004D1A8u: goto label_8004D1A8;
    case 0x8004D1ACu: goto label_8004D1AC;
    case 0x8004D1B0u: goto label_8004D1B0;
    case 0x8004D1B4u: goto label_8004D1B4;
    case 0x8004D1B8u: goto label_8004D1B8;
    case 0x8004D1BCu: goto label_8004D1BC;
    case 0x8004D1C0u: goto label_8004D1C0;
    case 0x8004D1C4u: goto label_8004D1C4;
    case 0x8004D1C8u: goto label_8004D1C8;
    case 0x8004D1CCu: goto label_8004D1CC;
    case 0x8004D1D0u: goto label_8004D1D0;
    case 0x8004D1D4u: goto label_8004D1D4;
    case 0x8004D1D8u: goto label_8004D1D8;
    case 0x8004D1DCu: goto label_8004D1DC;
    case 0x8004D1E0u: goto label_8004D1E0;
    case 0x8004D1E4u: goto label_8004D1E4;
    case 0x8004D1E8u: goto label_8004D1E8;
    case 0x8004D1ECu: goto label_8004D1EC;
    case 0x8004D1F0u: goto label_8004D1F0;
    case 0x8004D1F4u: goto label_8004D1F4;
    case 0x8004D1F8u: goto label_8004D1F8;
    case 0x8004D1FCu: goto label_8004D1FC;
    case 0x8004D200u: goto label_8004D200;
    case 0x8004D204u: goto label_8004D204;
    case 0x8004D208u: goto label_8004D208;
    case 0x8004D20Cu: goto label_8004D20C;
    case 0x8004D210u: goto label_8004D210;
    case 0x8004D214u: goto label_8004D214;
    case 0x8004D218u: goto label_8004D218;
    case 0x8004D21Cu: goto label_8004D21C;
    case 0x8004D220u: goto label_8004D220;
    case 0x8004D224u: goto label_8004D224;
    case 0x8004D228u: goto label_8004D228;
    case 0x8004D22Cu: goto label_8004D22C;
    case 0x8004D230u: goto label_8004D230;
    case 0x8004D234u: goto label_8004D234;
    case 0x8004D238u: goto label_8004D238;
    case 0x8004D23Cu: goto label_8004D23C;
    case 0x8004D240u: goto label_8004D240;
    case 0x8004D244u: goto label_8004D244;
    case 0x8004D248u: goto label_8004D248;
    case 0x8004D24Cu: goto label_8004D24C;
    case 0x8004D250u: goto label_8004D250;
    case 0x8004D254u: goto label_8004D254;
    case 0x8004D258u: goto label_8004D258;
    case 0x8004D25Cu: goto label_8004D25C;
    case 0x8004D260u: goto label_8004D260;
    case 0x8004D264u: goto label_8004D264;
    case 0x8004D268u: goto label_8004D268;
    case 0x8004D26Cu: goto label_8004D26C;
    case 0x8004D270u: goto label_8004D270;
    case 0x8004D274u: goto label_8004D274;
    case 0x8004D278u: goto label_8004D278;
    case 0x8004D27Cu: goto label_8004D27C;
    case 0x8004D280u: goto label_8004D280;
    case 0x8004D284u: goto label_8004D284;
    case 0x8004D288u: goto label_8004D288;
    case 0x8004D28Cu: goto label_8004D28C;
    case 0x8004D290u: goto label_8004D290;
    case 0x8004D294u: goto label_8004D294;
    case 0x8004D298u: goto label_8004D298;
    case 0x8004D29Cu: goto label_8004D29C;
    case 0x8004D2A0u: goto label_8004D2A0;
    case 0x8004D2A4u: goto label_8004D2A4;
    case 0x8004D2A8u: goto label_8004D2A8;
    case 0x8004D2ACu: goto label_8004D2AC;
    case 0x8004D2B0u: goto label_8004D2B0;
    case 0x8004D2B4u: goto label_8004D2B4;
    case 0x8004D2B8u: goto label_8004D2B8;
    case 0x8004D2BCu: goto label_8004D2BC;
    case 0x8004D2C0u: goto label_8004D2C0;
    case 0x8004D2C4u: goto label_8004D2C4;
    case 0x8004D2C8u: goto label_8004D2C8;
    case 0x8004D2CCu: goto label_8004D2CC;
    case 0x8004D2D0u: goto label_8004D2D0;
    case 0x8004D2D4u: goto label_8004D2D4;
    case 0x8004D2D8u: goto label_8004D2D8;
    case 0x8004D2DCu: goto label_8004D2DC;
    case 0x8004D2E0u: goto label_8004D2E0;
    case 0x8004D2E4u: goto label_8004D2E4;
    case 0x8004D2E8u: goto label_8004D2E8;
    case 0x8004D2ECu: goto label_8004D2EC;
    case 0x8004D2F0u: goto label_8004D2F0;
    case 0x8004D2F4u: goto label_8004D2F4;
    case 0x8004D2F8u: goto label_8004D2F8;
    case 0x8004D2FCu: goto label_8004D2FC;
    case 0x8004D300u: goto label_8004D300;
    case 0x8004D304u: goto label_8004D304;
    case 0x8004D308u: goto label_8004D308;
    case 0x8004D30Cu: goto label_8004D30C;
    case 0x8004D310u: goto label_8004D310;
    case 0x8004D314u: goto label_8004D314;
    case 0x8004D318u: goto label_8004D318;
    case 0x8004D31Cu: goto label_8004D31C;
    case 0x8004D320u: goto label_8004D320;
    case 0x8004D324u: goto label_8004D324;
    case 0x8004D328u: goto label_8004D328;
    case 0x8004D32Cu: goto label_8004D32C;
    case 0x8004D330u: goto label_8004D330;
    case 0x8004D334u: goto label_8004D334;
    case 0x8004D338u: goto label_8004D338;
    case 0x8004D33Cu: goto label_8004D33C;
    case 0x8004D340u: goto label_8004D340;
    case 0x8004D344u: goto label_8004D344;
    case 0x8004D348u: goto label_8004D348;
    case 0x8004D34Cu: goto label_8004D34C;
    case 0x8004D350u: goto label_8004D350;
    case 0x8004D354u: goto label_8004D354;
    case 0x8004D358u: goto label_8004D358;
    case 0x8004D35Cu: goto label_8004D35C;
    case 0x8004D360u: goto label_8004D360;
    case 0x8004D364u: goto label_8004D364;
    case 0x8004D368u: goto label_8004D368;
    case 0x8004D36Cu: goto label_8004D36C;
    case 0x8004D370u: goto label_8004D370;
    case 0x8004D374u: goto label_8004D374;
    case 0x8004D378u: goto label_8004D378;
    case 0x8004D37Cu: goto label_8004D37C;
    case 0x8004D380u: goto label_8004D380;
    case 0x8004D384u: goto label_8004D384;
    case 0x8004D388u: goto label_8004D388;
    case 0x8004D38Cu: goto label_8004D38C;
    case 0x8004D390u: goto label_8004D390;
    case 0x8004D394u: goto label_8004D394;
    case 0x8004D398u: goto label_8004D398;
    case 0x8004D39Cu: goto label_8004D39C;
    case 0x8004D3A0u: goto label_8004D3A0;
    case 0x8004D3A4u: goto label_8004D3A4;
    case 0x8004D3A8u: goto label_8004D3A8;
    case 0x8004D3ACu: goto label_8004D3AC;
    case 0x8004D3B0u: goto label_8004D3B0;
    case 0x8004D3B4u: goto label_8004D3B4;
    case 0x8004D3B8u: goto label_8004D3B8;
    case 0x8004D3BCu: goto label_8004D3BC;
    case 0x8004D3C0u: goto label_8004D3C0;
    case 0x8004D3C4u: goto label_8004D3C4;
    case 0x8004D3C8u: goto label_8004D3C8;
    case 0x8004D3CCu: goto label_8004D3CC;
    case 0x8004D3D0u: goto label_8004D3D0;
    case 0x8004D3D4u: goto label_8004D3D4;
    case 0x8004D3D8u: goto label_8004D3D8;
    case 0x8004D3DCu: goto label_8004D3DC;
    case 0x8004D3E0u: goto label_8004D3E0;
    case 0x8004D3E4u: goto label_8004D3E4;
    case 0x8004D3E8u: goto label_8004D3E8;
    case 0x8004D3ECu: goto label_8004D3EC;
    case 0x8004D3F0u: goto label_8004D3F0;
    case 0x8004D3F4u: goto label_8004D3F4;
    case 0x8004D3F8u: goto label_8004D3F8;
    case 0x8004D3FCu: goto label_8004D3FC;
    case 0x8004D400u: goto label_8004D400;
    case 0x8004D404u: goto label_8004D404;
    case 0x8004D408u: goto label_8004D408;
    case 0x8004D40Cu: goto label_8004D40C;
    case 0x8004D410u: goto label_8004D410;
    case 0x8004D414u: goto label_8004D414;
    case 0x8004D418u: goto label_8004D418;
    case 0x8004D41Cu: goto label_8004D41C;
    case 0x8004D420u: goto label_8004D420;
    case 0x8004D424u: goto label_8004D424;
    case 0x8004D428u: goto label_8004D428;
    case 0x8004D42Cu: goto label_8004D42C;
    case 0x8004D430u: goto label_8004D430;
    case 0x8004D434u: goto label_8004D434;
    case 0x8004D438u: goto label_8004D438;
    case 0x8004D43Cu: goto label_8004D43C;
    case 0x8004D440u: goto label_8004D440;
    case 0x8004D444u: goto label_8004D444;
    case 0x8004D448u: goto label_8004D448;
    case 0x8004D44Cu: goto label_8004D44C;
    case 0x8004D450u: goto label_8004D450;
    case 0x8004D454u: goto label_8004D454;
    case 0x8004D458u: goto label_8004D458;
    case 0x8004D45Cu: goto label_8004D45C;
    case 0x8004D460u: goto label_8004D460;
    case 0x8004D464u: goto label_8004D464;
    case 0x8004D468u: goto label_8004D468;
    case 0x8004D46Cu: goto label_8004D46C;
    case 0x8004D470u: goto label_8004D470;
    case 0x8004D474u: goto label_8004D474;
    case 0x8004D478u: goto label_8004D478;
    case 0x8004D47Cu: goto label_8004D47C;
    case 0x8004D480u: goto label_8004D480;
    case 0x8004D484u: goto label_8004D484;
    case 0x8004D488u: goto label_8004D488;
    case 0x8004D48Cu: goto label_8004D48C;
    case 0x8004D490u: goto label_8004D490;
    case 0x8004D494u: goto label_8004D494;
    case 0x8004D498u: goto label_8004D498;
    case 0x8004D49Cu: goto label_8004D49C;
    case 0x8004D4A0u: goto label_8004D4A0;
    case 0x8004D4A4u: goto label_8004D4A4;
    case 0x8004D4A8u: goto label_8004D4A8;
    case 0x8004D4ACu: goto label_8004D4AC;
    case 0x8004D4B0u: goto label_8004D4B0;
    case 0x8004D4B4u: goto label_8004D4B4;
    case 0x8004D4B8u: goto label_8004D4B8;
    case 0x8004D4BCu: goto label_8004D4BC;
    case 0x8004D4C0u: goto label_8004D4C0;
    case 0x8004D4C4u: goto label_8004D4C4;
    case 0x8004D4C8u: goto label_8004D4C8;
    case 0x8004D4CCu: goto label_8004D4CC;
    case 0x8004D4D0u: goto label_8004D4D0;
    case 0x8004D4D4u: goto label_8004D4D4;
    case 0x8004D4D8u: goto label_8004D4D8;
    case 0x8004D4DCu: goto label_8004D4DC;
    case 0x8004D4E0u: goto label_8004D4E0;
    case 0x8004D4E4u: goto label_8004D4E4;
    case 0x8004D4E8u: goto label_8004D4E8;
    case 0x8004D4ECu: goto label_8004D4EC;
    case 0x8004D4F0u: goto label_8004D4F0;
    case 0x8004D4F4u: goto label_8004D4F4;
    case 0x8004D4F8u: goto label_8004D4F8;
    case 0x8004D4FCu: goto label_8004D4FC;
    case 0x8004D500u: goto label_8004D500;
    case 0x8004D504u: goto label_8004D504;
    case 0x8004D508u: goto label_8004D508;
    case 0x8004D50Cu: goto label_8004D50C;
    case 0x8004D510u: goto label_8004D510;
    case 0x8004D514u: goto label_8004D514;
    case 0x8004D518u: goto label_8004D518;
    case 0x8004D51Cu: goto label_8004D51C;
    case 0x8004D520u: goto label_8004D520;
    case 0x8004D524u: goto label_8004D524;
    case 0x8004D528u: goto label_8004D528;
    case 0x8004D52Cu: goto label_8004D52C;
    case 0x8004D530u: goto label_8004D530;
    case 0x8004D534u: goto label_8004D534;
    case 0x8004D538u: goto label_8004D538;
    case 0x8004D53Cu: goto label_8004D53C;
    case 0x8004D540u: goto label_8004D540;
    case 0x8004D544u: goto label_8004D544;
    case 0x8004D548u: goto label_8004D548;
    case 0x8004D54Cu: goto label_8004D54C;
    case 0x8004D550u: goto label_8004D550;
    case 0x8004D554u: goto label_8004D554;
    case 0x8004D558u: goto label_8004D558;
    case 0x8004D55Cu: goto label_8004D55C;
    case 0x8004D560u: goto label_8004D560;
    case 0x8004D564u: goto label_8004D564;
    case 0x8004D568u: goto label_8004D568;
    case 0x8004D56Cu: goto label_8004D56C;
    case 0x8004D570u: goto label_8004D570;
    case 0x8004D574u: goto label_8004D574;
    case 0x8004D578u: goto label_8004D578;
    case 0x8004D57Cu: goto label_8004D57C;
    case 0x8004D580u: goto label_8004D580;
    case 0x8004D584u: goto label_8004D584;
    case 0x8004D588u: goto label_8004D588;
    case 0x8004D58Cu: goto label_8004D58C;
    case 0x8004D590u: goto label_8004D590;
    case 0x8004D594u: goto label_8004D594;
    case 0x8004D598u: goto label_8004D598;
    case 0x8004D59Cu: goto label_8004D59C;
    case 0x8004D5A0u: goto label_8004D5A0;
    case 0x8004D5A4u: goto label_8004D5A4;
    case 0x8004D5A8u: goto label_8004D5A8;
    case 0x8004D5ACu: goto label_8004D5AC;
    case 0x8004D5B0u: goto label_8004D5B0;
    case 0x8004D5B4u: goto label_8004D5B4;
    case 0x8004D5B8u: goto label_8004D5B8;
    case 0x8004D5BCu: goto label_8004D5BC;
    case 0x8004D5C0u: goto label_8004D5C0;
    case 0x8004D5C4u: goto label_8004D5C4;
    case 0x8004D5C8u: goto label_8004D5C8;
    case 0x8004D5CCu: goto label_8004D5CC;
    case 0x8004D5D0u: goto label_8004D5D0;
    case 0x8004D5D4u: goto label_8004D5D4;
    case 0x8004D5D8u: goto label_8004D5D8;
    case 0x8004D5DCu: goto label_8004D5DC;
    case 0x8004D5E0u: goto label_8004D5E0;
    case 0x8004D5E4u: goto label_8004D5E4;
    case 0x8004D5E8u: goto label_8004D5E8;
    case 0x8004D5ECu: goto label_8004D5EC;
    case 0x8004D5F0u: goto label_8004D5F0;
    case 0x8004D5F4u: goto label_8004D5F4;
    case 0x8004D5F8u: goto label_8004D5F8;
    case 0x8004D5FCu: goto label_8004D5FC;
    case 0x8004D600u: goto label_8004D600;
    case 0x8004D604u: goto label_8004D604;
    case 0x8004D608u: goto label_8004D608;
    case 0x8004D60Cu: goto label_8004D60C;
    case 0x8004D610u: goto label_8004D610;
    case 0x8004D614u: goto label_8004D614;
    case 0x8004D618u: goto label_8004D618;
    case 0x8004D61Cu: goto label_8004D61C;
    case 0x8004D620u: goto label_8004D620;
    case 0x8004D624u: goto label_8004D624;
    case 0x8004D628u: goto label_8004D628;
    case 0x8004D62Cu: goto label_8004D62C;
    case 0x8004D630u: goto label_8004D630;
    case 0x8004D634u: goto label_8004D634;
    case 0x8004D638u: goto label_8004D638;
    case 0x8004D63Cu: goto label_8004D63C;
    case 0x8004D640u: goto label_8004D640;
    case 0x8004D644u: goto label_8004D644;
    case 0x8004D648u: goto label_8004D648;
    case 0x8004D64Cu: goto label_8004D64C;
    case 0x8004D650u: goto label_8004D650;
    case 0x8004D654u: goto label_8004D654;
    case 0x8004D658u: goto label_8004D658;
    case 0x8004D65Cu: goto label_8004D65C;
    case 0x8004D660u: goto label_8004D660;
    case 0x8004D664u: goto label_8004D664;
    case 0x8004D668u: goto label_8004D668;
    case 0x8004D66Cu: goto label_8004D66C;
    case 0x8004D670u: goto label_8004D670;
    case 0x8004D674u: goto label_8004D674;
    case 0x8004D678u: goto label_8004D678;
    case 0x8004D67Cu: goto label_8004D67C;
    case 0x8004D680u: goto label_8004D680;
    case 0x8004D684u: goto label_8004D684;
    case 0x8004D688u: goto label_8004D688;
    case 0x8004D68Cu: goto label_8004D68C;
    case 0x8004D690u: goto label_8004D690;
    case 0x8004D694u: goto label_8004D694;
    case 0x8004D698u: goto label_8004D698;
    case 0x8004D69Cu: goto label_8004D69C;
    case 0x8004D6A0u: goto label_8004D6A0;
    case 0x8004D6A4u: goto label_8004D6A4;
    case 0x8004D6A8u: goto label_8004D6A8;
    case 0x8004D6ACu: goto label_8004D6AC;
    case 0x8004D6B0u: goto label_8004D6B0;
    case 0x8004D6B4u: goto label_8004D6B4;
    case 0x8004D6B8u: goto label_8004D6B8;
    case 0x8004D6BCu: goto label_8004D6BC;
    case 0x8004D6C0u: goto label_8004D6C0;
    case 0x8004D6C4u: goto label_8004D6C4;
    case 0x8004D6C8u: goto label_8004D6C8;
    case 0x8004D6CCu: goto label_8004D6CC;
    case 0x8004D6D0u: goto label_8004D6D0;
    case 0x8004D6D4u: goto label_8004D6D4;
    case 0x8004D6D8u: goto label_8004D6D8;
    case 0x8004D6DCu: goto label_8004D6DC;
    case 0x8004D6E0u: goto label_8004D6E0;
    case 0x8004D6E4u: goto label_8004D6E4;
    case 0x8004D6E8u: goto label_8004D6E8;
    case 0x8004D6ECu: goto label_8004D6EC;
    case 0x8004D6F0u: goto label_8004D6F0;
    case 0x8004D6F4u: goto label_8004D6F4;
    case 0x8004D6F8u: goto label_8004D6F8;
    case 0x8004D6FCu: goto label_8004D6FC;
    case 0x8004D700u: goto label_8004D700;
    case 0x8004D704u: goto label_8004D704;
    case 0x8004D708u: goto label_8004D708;
    case 0x8004D70Cu: goto label_8004D70C;
    case 0x8004D710u: goto label_8004D710;
    case 0x8004D714u: goto label_8004D714;
    case 0x8004D718u: goto label_8004D718;
    case 0x8004D71Cu: goto label_8004D71C;
    case 0x8004D720u: goto label_8004D720;
    case 0x8004D724u: goto label_8004D724;
    case 0x8004D728u: goto label_8004D728;
    case 0x8004D72Cu: goto label_8004D72C;
    case 0x8004D730u: goto label_8004D730;
    case 0x8004D734u: goto label_8004D734;
    case 0x8004D738u: goto label_8004D738;
    case 0x8004D73Cu: goto label_8004D73C;
    case 0x8004D740u: goto label_8004D740;
    case 0x8004D744u: goto label_8004D744;
    case 0x8004D748u: goto label_8004D748;
    case 0x8004D74Cu: goto label_8004D74C;
    case 0x8004D750u: goto label_8004D750;
    case 0x8004D754u: goto label_8004D754;
    case 0x8004D758u: goto label_8004D758;
    case 0x8004D75Cu: goto label_8004D75C;
    case 0x8004D760u: goto label_8004D760;
    case 0x8004D764u: goto label_8004D764;
    case 0x8004D768u: goto label_8004D768;
    case 0x8004D76Cu: goto label_8004D76C;
    case 0x8004D770u: goto label_8004D770;
    case 0x8004D774u: goto label_8004D774;
    case 0x8004D778u: goto label_8004D778;
    case 0x8004D77Cu: goto label_8004D77C;
    case 0x8004D780u: goto label_8004D780;
    case 0x8004D784u: goto label_8004D784;
    case 0x8004D788u: goto label_8004D788;
    case 0x8004D78Cu: goto label_8004D78C;
    case 0x8004D790u: goto label_8004D790;
    case 0x8004D794u: goto label_8004D794;
    case 0x8004D798u: goto label_8004D798;
    case 0x8004D79Cu: goto label_8004D79C;
    case 0x8004D7A0u: goto label_8004D7A0;
    case 0x8004D7A4u: goto label_8004D7A4;
    case 0x8004D7A8u: goto label_8004D7A8;
    case 0x8004D7ACu: goto label_8004D7AC;
    case 0x8004D7B0u: goto label_8004D7B0;
    case 0x8004D7B4u: goto label_8004D7B4;
    case 0x8004D7B8u: goto label_8004D7B8;
    case 0x8004D7BCu: goto label_8004D7BC;
    case 0x8004D7C0u: goto label_8004D7C0;
    case 0x8004D7C4u: goto label_8004D7C4;
    case 0x8004D7C8u: goto label_8004D7C8;
    case 0x8004D7CCu: goto label_8004D7CC;
    case 0x8004D7D0u: goto label_8004D7D0;
    case 0x8004D7D4u: goto label_8004D7D4;
    case 0x8004D7D8u: goto label_8004D7D8;
    case 0x8004D7DCu: goto label_8004D7DC;
    case 0x8004D7E0u: goto label_8004D7E0;
    case 0x8004D7E4u: goto label_8004D7E4;
    case 0x8004D7E8u: goto label_8004D7E8;
    case 0x8004D7ECu: goto label_8004D7EC;
    case 0x8004D7F0u: goto label_8004D7F0;
    case 0x8004D7F4u: goto label_8004D7F4;
    case 0x8004D7F8u: goto label_8004D7F8;
    case 0x8004D7FCu: goto label_8004D7FC;
    case 0x8004D800u: goto label_8004D800;
    case 0x8004D804u: goto label_8004D804;
    case 0x8004D808u: goto label_8004D808;
    case 0x8004D80Cu: goto label_8004D80C;
    case 0x8004D810u: goto label_8004D810;
    case 0x8004D814u: goto label_8004D814;
    case 0x8004D818u: goto label_8004D818;
    case 0x8004D81Cu: goto label_8004D81C;
    case 0x8004D820u: goto label_8004D820;
    case 0x8004D824u: goto label_8004D824;
    case 0x8004D828u: goto label_8004D828;
    case 0x8004D82Cu: goto label_8004D82C;
    case 0x8004D830u: goto label_8004D830;
    case 0x8004D834u: goto label_8004D834;
    case 0x8004D838u: goto label_8004D838;
    case 0x8004D83Cu: goto label_8004D83C;
    case 0x8004D840u: goto label_8004D840;
    case 0x8004D844u: goto label_8004D844;
    case 0x8004D848u: goto label_8004D848;
    case 0x8004D84Cu: goto label_8004D84C;
    case 0x8004D850u: goto label_8004D850;
    case 0x8004D854u: goto label_8004D854;
    case 0x8004D858u: goto label_8004D858;
    case 0x8004D85Cu: goto label_8004D85C;
    case 0x8004D860u: goto label_8004D860;
    case 0x8004D864u: goto label_8004D864;
    case 0x8004D868u: goto label_8004D868;
    case 0x8004D86Cu: goto label_8004D86C;
    case 0x8004D870u: goto label_8004D870;
    case 0x8004D874u: goto label_8004D874;
    case 0x8004D878u: goto label_8004D878;
    case 0x8004D87Cu: goto label_8004D87C;
    case 0x8004D880u: goto label_8004D880;
    case 0x8004D884u: goto label_8004D884;
    case 0x8004D888u: goto label_8004D888;
    case 0x8004D88Cu: goto label_8004D88C;
    case 0x8004D890u: goto label_8004D890;
    case 0x8004D894u: goto label_8004D894;
    case 0x8004D898u: goto label_8004D898;
    case 0x8004D89Cu: goto label_8004D89C;
    case 0x8004D8A0u: goto label_8004D8A0;
    case 0x8004D8A4u: goto label_8004D8A4;
    case 0x8004D8A8u: goto label_8004D8A8;
    case 0x8004D8ACu: goto label_8004D8AC;
    case 0x8004D8B0u: goto label_8004D8B0;
    case 0x8004D8B4u: goto label_8004D8B4;
    case 0x8004D8B8u: goto label_8004D8B8;
    case 0x8004D8BCu: goto label_8004D8BC;
    case 0x8004D8C0u: goto label_8004D8C0;
    case 0x8004D8C4u: goto label_8004D8C4;
    case 0x8004D8C8u: goto label_8004D8C8;
    case 0x8004D8CCu: goto label_8004D8CC;
    case 0x8004D8D0u: goto label_8004D8D0;
    case 0x8004D8D4u: goto label_8004D8D4;
    case 0x8004D8D8u: goto label_8004D8D8;
    case 0x8004D8DCu: goto label_8004D8DC;
    case 0x8004D8E0u: goto label_8004D8E0;
    case 0x8004D8E4u: goto label_8004D8E4;
    case 0x8004D8E8u: goto label_8004D8E8;
    case 0x8004D8ECu: goto label_8004D8EC;
    case 0x8004D8F0u: goto label_8004D8F0;
    case 0x8004D8F4u: goto label_8004D8F4;
    case 0x8004D8F8u: goto label_8004D8F8;
    case 0x8004D8FCu: goto label_8004D8FC;
    case 0x8004D900u: goto label_8004D900;
    case 0x8004D904u: goto label_8004D904;
    case 0x8004D908u: goto label_8004D908;
    case 0x8004D90Cu: goto label_8004D90C;
    case 0x8004D910u: goto label_8004D910;
    case 0x8004D914u: goto label_8004D914;
    case 0x8004D918u: goto label_8004D918;
    case 0x8004D91Cu: goto label_8004D91C;
    case 0x8004D920u: goto label_8004D920;
    case 0x8004D924u: goto label_8004D924;
    case 0x8004D928u: goto label_8004D928;
    case 0x8004D92Cu: goto label_8004D92C;
    case 0x8004D930u: goto label_8004D930;
    case 0x8004D934u: goto label_8004D934;
    case 0x8004D938u: goto label_8004D938;
    case 0x8004D93Cu: goto label_8004D93C;
    case 0x8004D940u: goto label_8004D940;
    case 0x8004D944u: goto label_8004D944;
    case 0x8004D948u: goto label_8004D948;
    case 0x8004D94Cu: goto label_8004D94C;
    case 0x8004D950u: goto label_8004D950;
    case 0x8004D954u: goto label_8004D954;
    case 0x8004D958u: goto label_8004D958;
    case 0x8004D95Cu: goto label_8004D95C;
    case 0x8004D960u: goto label_8004D960;
    case 0x8004D964u: goto label_8004D964;
    case 0x8004D968u: goto label_8004D968;
    case 0x8004D96Cu: goto label_8004D96C;
    case 0x8004D970u: goto label_8004D970;
    case 0x8004D974u: goto label_8004D974;
    case 0x8004D978u: goto label_8004D978;
    case 0x8004D97Cu: goto label_8004D97C;
    case 0x8004D980u: goto label_8004D980;
    case 0x8004D984u: goto label_8004D984;
    case 0x8004D988u: goto label_8004D988;
    case 0x8004D98Cu: goto label_8004D98C;
    case 0x8004D990u: goto label_8004D990;
    case 0x8004D994u: goto label_8004D994;
    case 0x8004D998u: goto label_8004D998;
    case 0x8004D99Cu: goto label_8004D99C;
    case 0x8004D9A0u: goto label_8004D9A0;
    case 0x8004D9A4u: goto label_8004D9A4;
    case 0x8004D9A8u: goto label_8004D9A8;
    case 0x8004D9ACu: goto label_8004D9AC;
    case 0x8004D9B0u: goto label_8004D9B0;
    case 0x8004D9B4u: goto label_8004D9B4;
    case 0x8004D9B8u: goto label_8004D9B8;
    case 0x8004D9BCu: goto label_8004D9BC;
    case 0x8004D9C0u: goto label_8004D9C0;
    case 0x8004D9C4u: goto label_8004D9C4;
    case 0x8004D9C8u: goto label_8004D9C8;
    case 0x8004D9CCu: goto label_8004D9CC;
    case 0x8004D9D0u: goto label_8004D9D0;
    case 0x8004D9D4u: goto label_8004D9D4;
    case 0x8004D9D8u: goto label_8004D9D8;
    case 0x8004D9DCu: goto label_8004D9DC;
    case 0x8004D9E0u: goto label_8004D9E0;
    case 0x8004D9E4u: goto label_8004D9E4;
    case 0x8004D9E8u: goto label_8004D9E8;
    case 0x8004D9ECu: goto label_8004D9EC;
    case 0x8004D9F0u: goto label_8004D9F0;
    case 0x8004D9F4u: goto label_8004D9F4;
    case 0x8004D9F8u: goto label_8004D9F8;
    case 0x8004D9FCu: goto label_8004D9FC;
    case 0x8004DA00u: goto label_8004DA00;
    case 0x8004DA04u: goto label_8004DA04;
    case 0x8004DA08u: goto label_8004DA08;
    case 0x8004DA0Cu: goto label_8004DA0C;
    case 0x8004DA10u: goto label_8004DA10;
    case 0x8004DA14u: goto label_8004DA14;
    case 0x8004DA18u: goto label_8004DA18;
    case 0x8004DA1Cu: goto label_8004DA1C;
    case 0x8004DA20u: goto label_8004DA20;
    case 0x8004DA24u: goto label_8004DA24;
    case 0x8004DA28u: goto label_8004DA28;
    case 0x8004DA2Cu: goto label_8004DA2C;
    case 0x8004DA30u: goto label_8004DA30;
    case 0x8004DA34u: goto label_8004DA34;
    case 0x8004DA38u: goto label_8004DA38;
    case 0x8004DA3Cu: goto label_8004DA3C;
    case 0x8004DA40u: goto label_8004DA40;
    case 0x8004DA44u: goto label_8004DA44;
    case 0x8004DA48u: goto label_8004DA48;
    case 0x8004DA4Cu: goto label_8004DA4C;
    case 0x8004DA50u: goto label_8004DA50;
    case 0x8004DA54u: goto label_8004DA54;
    case 0x8004DA58u: goto label_8004DA58;
    case 0x8004DA5Cu: goto label_8004DA5C;
    case 0x8004DA60u: goto label_8004DA60;
    case 0x8004DA64u: goto label_8004DA64;
    case 0x8004DA68u: goto label_8004DA68;
    case 0x8004DA6Cu: goto label_8004DA6C;
    case 0x8004DA70u: goto label_8004DA70;
    case 0x8004DA74u: goto label_8004DA74;
    case 0x8004DA78u: goto label_8004DA78;
    case 0x8004DA7Cu: goto label_8004DA7C;
    case 0x8004DA80u: goto label_8004DA80;
    case 0x8004DA84u: goto label_8004DA84;
    case 0x8004DA88u: goto label_8004DA88;
    case 0x8004DA8Cu: goto label_8004DA8C;
    case 0x8004DA90u: goto label_8004DA90;
    case 0x8004DA94u: goto label_8004DA94;
    case 0x8004DA98u: goto label_8004DA98;
    case 0x8004DA9Cu: goto label_8004DA9C;
    case 0x8004DAA0u: goto label_8004DAA0;
    case 0x8004DAA4u: goto label_8004DAA4;
    case 0x8004DAA8u: goto label_8004DAA8;
    case 0x8004DAACu: goto label_8004DAAC;
    case 0x8004DAB0u: goto label_8004DAB0;
    case 0x8004DAB4u: goto label_8004DAB4;
    case 0x8004DAB8u: goto label_8004DAB8;
    case 0x8004DABCu: goto label_8004DABC;
    case 0x8004DAC0u: goto label_8004DAC0;
    case 0x8004DAC4u: goto label_8004DAC4;
    case 0x8004DAC8u: goto label_8004DAC8;
    case 0x8004DACCu: goto label_8004DACC;
    case 0x8004DAD0u: goto label_8004DAD0;
    case 0x8004DAD4u: goto label_8004DAD4;
    case 0x8004DAD8u: goto label_8004DAD8;
    case 0x8004DADCu: goto label_8004DADC;
    case 0x8004DAE0u: goto label_8004DAE0;
    case 0x8004DAE4u: goto label_8004DAE4;
    case 0x8004DAE8u: goto label_8004DAE8;
    case 0x8004DAECu: goto label_8004DAEC;
    case 0x8004DAF0u: goto label_8004DAF0;
    case 0x8004DAF4u: goto label_8004DAF4;
    case 0x8004DAF8u: goto label_8004DAF8;
    case 0x8004DAFCu: goto label_8004DAFC;
    case 0x8004DB00u: goto label_8004DB00;
    case 0x8004DB04u: goto label_8004DB04;
    case 0x8004DB08u: goto label_8004DB08;
    case 0x8004DB0Cu: goto label_8004DB0C;
    case 0x8004DB10u: goto label_8004DB10;
    case 0x8004DB14u: goto label_8004DB14;
    case 0x8004DB18u: goto label_8004DB18;
    case 0x8004DB1Cu: goto label_8004DB1C;
    case 0x8004DB20u: goto label_8004DB20;
    case 0x8004DB24u: goto label_8004DB24;
    case 0x8004DB28u: goto label_8004DB28;
    case 0x8004DB2Cu: goto label_8004DB2C;
    case 0x8004DB30u: goto label_8004DB30;
    case 0x8004DB34u: goto label_8004DB34;
    case 0x8004DB38u: goto label_8004DB38;
    case 0x8004DB3Cu: goto label_8004DB3C;
    case 0x8004DB40u: goto label_8004DB40;
    case 0x8004DB44u: goto label_8004DB44;
    case 0x8004DB48u: goto label_8004DB48;
    case 0x8004DB4Cu: goto label_8004DB4C;
    case 0x8004DB50u: goto label_8004DB50;
    case 0x8004DB54u: goto label_8004DB54;
    case 0x8004DB58u: goto label_8004DB58;
    case 0x8004DB5Cu: goto label_8004DB5C;
    case 0x8004DB60u: goto label_8004DB60;
    case 0x8004DB64u: goto label_8004DB64;
    case 0x8004DB68u: goto label_8004DB68;
    case 0x8004DB6Cu: goto label_8004DB6C;
    case 0x8004DB70u: goto label_8004DB70;
    case 0x8004DB74u: goto label_8004DB74;
    case 0x8004DB78u: goto label_8004DB78;
    case 0x8004DB7Cu: goto label_8004DB7C;
    case 0x8004DB80u: goto label_8004DB80;
    case 0x8004DB84u: goto label_8004DB84;
    case 0x8004DB88u: goto label_8004DB88;
    case 0x8004DB8Cu: goto label_8004DB8C;
    case 0x8004DB90u: goto label_8004DB90;
    case 0x8004DB94u: goto label_8004DB94;
    case 0x8004DB98u: goto label_8004DB98;
    case 0x8004DB9Cu: goto label_8004DB9C;
    case 0x8004DBA0u: goto label_8004DBA0;
    case 0x8004DBA4u: goto label_8004DBA4;
    case 0x8004DBA8u: goto label_8004DBA8;
    case 0x8004DBACu: goto label_8004DBAC;
    case 0x8004DBB0u: goto label_8004DBB0;
    case 0x8004DBB4u: goto label_8004DBB4;
    case 0x8004DBB8u: goto label_8004DBB8;
    case 0x8004DBBCu: goto label_8004DBBC;
    case 0x8004DBC0u: goto label_8004DBC0;
    case 0x8004DBC4u: goto label_8004DBC4;
    case 0x8004DBC8u: goto label_8004DBC8;
    case 0x8004DBCCu: goto label_8004DBCC;
    case 0x8004DBD0u: goto label_8004DBD0;
    case 0x8004DBD4u: goto label_8004DBD4;
    case 0x8004DBD8u: goto label_8004DBD8;
    case 0x8004DBDCu: goto label_8004DBDC;
    case 0x8004DBE0u: goto label_8004DBE0;
    case 0x8004DBE4u: goto label_8004DBE4;
    case 0x8004DBE8u: goto label_8004DBE8;
    case 0x8004DBECu: goto label_8004DBEC;
    case 0x8004DBF0u: goto label_8004DBF0;
    case 0x8004DBF4u: goto label_8004DBF4;
    case 0x8004DBF8u: goto label_8004DBF8;
    case 0x8004DBFCu: goto label_8004DBFC;
    case 0x8004DC00u: goto label_8004DC00;
    case 0x8004DC04u: goto label_8004DC04;
    case 0x8004DC08u: goto label_8004DC08;
    case 0x8004DC0Cu: goto label_8004DC0C;
    case 0x8004DC10u: goto label_8004DC10;
    case 0x8004DC14u: goto label_8004DC14;
    case 0x8004DC18u: goto label_8004DC18;
    case 0x8004DC1Cu: goto label_8004DC1C;
    case 0x8004DC20u: goto label_8004DC20;
    case 0x8004DC24u: goto label_8004DC24;
    case 0x8004DC28u: goto label_8004DC28;
    case 0x8004DC2Cu: goto label_8004DC2C;
    case 0x8004DC30u: goto label_8004DC30;
    case 0x8004DC34u: goto label_8004DC34;
    case 0x8004DC38u: goto label_8004DC38;
    case 0x8004DC3Cu: goto label_8004DC3C;
    case 0x8004DC40u: goto label_8004DC40;
    case 0x8004DC44u: goto label_8004DC44;
    case 0x8004DC48u: goto label_8004DC48;
    case 0x8004DC4Cu: goto label_8004DC4C;
    case 0x8004DC50u: goto label_8004DC50;
    case 0x8004DC54u: goto label_8004DC54;
    case 0x8004DC58u: goto label_8004DC58;
    case 0x8004DC5Cu: goto label_8004DC5C;
    case 0x8004DC60u: goto label_8004DC60;
    case 0x8004DC64u: goto label_8004DC64;
    case 0x8004DC68u: goto label_8004DC68;
    case 0x8004DC6Cu: goto label_8004DC6C;
    case 0x8004DC70u: goto label_8004DC70;
    case 0x8004DC74u: goto label_8004DC74;
    case 0x8004DC78u: goto label_8004DC78;
    case 0x8004DC7Cu: goto label_8004DC7C;
    case 0x8004DC80u: goto label_8004DC80;
    case 0x8004DC84u: goto label_8004DC84;
    case 0x8004DC88u: goto label_8004DC88;
    case 0x8004DC8Cu: goto label_8004DC8C;
    case 0x8004DC90u: goto label_8004DC90;
    case 0x8004DC94u: goto label_8004DC94;
    case 0x8004DC98u: goto label_8004DC98;
    case 0x8004DC9Cu: goto label_8004DC9C;
    case 0x8004DCA0u: goto label_8004DCA0;
    case 0x8004DCA4u: goto label_8004DCA4;
    case 0x8004DCA8u: goto label_8004DCA8;
    case 0x8004DCACu: goto label_8004DCAC;
    case 0x8004DCB0u: goto label_8004DCB0;
    case 0x8004DCB4u: goto label_8004DCB4;
    case 0x8004DCB8u: goto label_8004DCB8;
    case 0x8004DCBCu: goto label_8004DCBC;
    case 0x8004DCC0u: goto label_8004DCC0;
    case 0x8004DCC4u: goto label_8004DCC4;
    case 0x8004DCC8u: goto label_8004DCC8;
    case 0x8004DCCCu: goto label_8004DCCC;
    case 0x8004DCD0u: goto label_8004DCD0;
    case 0x8004DCD4u: goto label_8004DCD4;
    case 0x8004DCD8u: goto label_8004DCD8;
    case 0x8004DCDCu: goto label_8004DCDC;
    case 0x8004DCE0u: goto label_8004DCE0;
    case 0x8004DCE4u: goto label_8004DCE4;
    case 0x8004DCE8u: goto label_8004DCE8;
    case 0x8004DCECu: goto label_8004DCEC;
    case 0x8004DCF0u: goto label_8004DCF0;
    case 0x8004DCF4u: goto label_8004DCF4;
    case 0x8004DCF8u: goto label_8004DCF8;
    case 0x8004DCFCu: goto label_8004DCFC;
    case 0x8004DD00u: goto label_8004DD00;
    case 0x8004DD04u: goto label_8004DD04;
    case 0x8004DD08u: goto label_8004DD08;
    case 0x8004DD0Cu: goto label_8004DD0C;
    case 0x8004DD10u: goto label_8004DD10;
    case 0x8004DD14u: goto label_8004DD14;
    case 0x8004DD18u: goto label_8004DD18;
    case 0x8004DD1Cu: goto label_8004DD1C;
    case 0x8004DD20u: goto label_8004DD20;
    case 0x8004DD24u: goto label_8004DD24;
    case 0x8004DD28u: goto label_8004DD28;
    case 0x8004DD2Cu: goto label_8004DD2C;
    case 0x8004DD30u: goto label_8004DD30;
    case 0x8004DD34u: goto label_8004DD34;
    case 0x8004DD38u: goto label_8004DD38;
    case 0x8004DD3Cu: goto label_8004DD3C;
    case 0x8004DD40u: goto label_8004DD40;
    case 0x8004DD44u: goto label_8004DD44;
    case 0x8004DD48u: goto label_8004DD48;
    case 0x8004DD4Cu: goto label_8004DD4C;
    case 0x8004DD50u: goto label_8004DD50;
    case 0x8004DD54u: goto label_8004DD54;
    case 0x8004DD58u: goto label_8004DD58;
    case 0x8004DD5Cu: goto label_8004DD5C;
    case 0x8004DD60u: goto label_8004DD60;
    case 0x8004DD64u: goto label_8004DD64;
    case 0x8004DD68u: goto label_8004DD68;
    case 0x8004DD6Cu: goto label_8004DD6C;
    case 0x8004DD70u: goto label_8004DD70;
    case 0x8004DD74u: goto label_8004DD74;
    case 0x8004DD78u: goto label_8004DD78;
    case 0x8004DD7Cu: goto label_8004DD7C;
    case 0x8004DD80u: goto label_8004DD80;
    case 0x8004DD84u: goto label_8004DD84;
    case 0x8004DD88u: goto label_8004DD88;
    case 0x8004DD8Cu: goto label_8004DD8C;
    case 0x8004DD90u: goto label_8004DD90;
    case 0x8004DD94u: goto label_8004DD94;
    case 0x8004DD98u: goto label_8004DD98;
    case 0x8004DD9Cu: goto label_8004DD9C;
    case 0x8004DDA0u: goto label_8004DDA0;
    case 0x8004DDA4u: goto label_8004DDA4;
    case 0x8004DDA8u: goto label_8004DDA8;
    case 0x8004DDACu: goto label_8004DDAC;
    case 0x8004DDB0u: goto label_8004DDB0;
    case 0x8004DDB4u: goto label_8004DDB4;
    case 0x8004DDB8u: goto label_8004DDB8;
    case 0x8004DDBCu: goto label_8004DDBC;
    case 0x8004DDC0u: goto label_8004DDC0;
    case 0x8004DDC4u: goto label_8004DDC4;
    case 0x8004DDC8u: goto label_8004DDC8;
    case 0x8004DDCCu: goto label_8004DDCC;
    case 0x8004DDD0u: goto label_8004DDD0;
    case 0x8004DDD4u: goto label_8004DDD4;
    case 0x8004DDD8u: goto label_8004DDD8;
    case 0x8004DDDCu: goto label_8004DDDC;
    case 0x8004DDE0u: goto label_8004DDE0;
    case 0x8004DDE4u: goto label_8004DDE4;
    case 0x8004DDE8u: goto label_8004DDE8;
    case 0x8004DDECu: goto label_8004DDEC;
    case 0x8004DDF0u: goto label_8004DDF0;
    case 0x8004DDF4u: goto label_8004DDF4;
    case 0x8004DDF8u: goto label_8004DDF8;
    case 0x8004DDFCu: goto label_8004DDFC;
    case 0x8004DE00u: goto label_8004DE00;
    case 0x8004DE04u: goto label_8004DE04;
    case 0x8004DE08u: goto label_8004DE08;
    case 0x8004DE0Cu: goto label_8004DE0C;
    case 0x8004DE10u: goto label_8004DE10;
    case 0x8004DE14u: goto label_8004DE14;
    case 0x8004DE18u: goto label_8004DE18;
    case 0x8004DE1Cu: goto label_8004DE1C;
    case 0x8004DE20u: goto label_8004DE20;
    case 0x8004DE24u: goto label_8004DE24;
    case 0x8004DE28u: goto label_8004DE28;
    case 0x8004DE2Cu: goto label_8004DE2C;
    case 0x8004DE30u: goto label_8004DE30;
    case 0x8004DE34u: goto label_8004DE34;
    case 0x8004DE38u: goto label_8004DE38;
    case 0x8004DE3Cu: goto label_8004DE3C;
    case 0x8004DE40u: goto label_8004DE40;
    case 0x8004DE44u: goto label_8004DE44;
    case 0x8004DE48u: goto label_8004DE48;
    case 0x8004DE4Cu: goto label_8004DE4C;
    case 0x8004DE50u: goto label_8004DE50;
    case 0x8004DE54u: goto label_8004DE54;
    case 0x8004DE58u: goto label_8004DE58;
    case 0x8004DE5Cu: goto label_8004DE5C;
    case 0x8004DE60u: goto label_8004DE60;
    case 0x8004DE64u: goto label_8004DE64;
    case 0x8004DE68u: goto label_8004DE68;
    case 0x8004DE6Cu: goto label_8004DE6C;
    case 0x8004DE70u: goto label_8004DE70;
    case 0x8004DE74u: goto label_8004DE74;
    case 0x8004DE78u: goto label_8004DE78;
    case 0x8004DE7Cu: goto label_8004DE7C;
    case 0x8004DE80u: goto label_8004DE80;
    case 0x8004DE84u: goto label_8004DE84;
    case 0x8004DE88u: goto label_8004DE88;
    case 0x8004DE8Cu: goto label_8004DE8C;
    case 0x8004DE90u: goto label_8004DE90;
    case 0x8004DE94u: goto label_8004DE94;
    case 0x8004DE98u: goto label_8004DE98;
    case 0x8004DE9Cu: goto label_8004DE9C;
    case 0x8004DEA0u: goto label_8004DEA0;
    case 0x8004DEA4u: goto label_8004DEA4;
    case 0x8004DEA8u: goto label_8004DEA8;
    case 0x8004DEACu: goto label_8004DEAC;
    case 0x8004DEB0u: goto label_8004DEB0;
    case 0x8004DEB4u: goto label_8004DEB4;
    case 0x8004DEB8u: goto label_8004DEB8;
    case 0x8004DEBCu: goto label_8004DEBC;
    case 0x8004DEC0u: goto label_8004DEC0;
    case 0x8004DEC4u: goto label_8004DEC4;
    case 0x8004DEC8u: goto label_8004DEC8;
    case 0x8004DECCu: goto label_8004DECC;
    case 0x8004DED0u: goto label_8004DED0;
    case 0x8004DED4u: goto label_8004DED4;
    case 0x8004DED8u: goto label_8004DED8;
    case 0x8004DEDCu: goto label_8004DEDC;
    case 0x8004DEE0u: goto label_8004DEE0;
    case 0x8004DEE4u: goto label_8004DEE4;
    case 0x8004DEE8u: goto label_8004DEE8;
    case 0x8004DEECu: goto label_8004DEEC;
    case 0x8004DEF0u: goto label_8004DEF0;
    case 0x8004DEF4u: goto label_8004DEF4;
    case 0x8004DEF8u: goto label_8004DEF8;
    case 0x8004DEFCu: goto label_8004DEFC;
    case 0x8004DF00u: goto label_8004DF00;
    case 0x8004DF04u: goto label_8004DF04;
    case 0x8004DF08u: goto label_8004DF08;
    case 0x8004DF0Cu: goto label_8004DF0C;
    case 0x8004DF10u: goto label_8004DF10;
    case 0x8004DF14u: goto label_8004DF14;
    case 0x8004DF18u: goto label_8004DF18;
    case 0x8004DF1Cu: goto label_8004DF1C;
    case 0x8004DF20u: goto label_8004DF20;
    case 0x8004DF24u: goto label_8004DF24;
    case 0x8004DF28u: goto label_8004DF28;
    case 0x8004DF2Cu: goto label_8004DF2C;
    case 0x8004DF30u: goto label_8004DF30;
    case 0x8004DF34u: goto label_8004DF34;
    case 0x8004DF38u: goto label_8004DF38;
    case 0x8004DF3Cu: goto label_8004DF3C;
    case 0x8004DF40u: goto label_8004DF40;
    case 0x8004DF44u: goto label_8004DF44;
    case 0x8004DF48u: goto label_8004DF48;
    case 0x8004DF4Cu: goto label_8004DF4C;
    case 0x8004DF50u: goto label_8004DF50;
    case 0x8004DF54u: goto label_8004DF54;
    case 0x8004DF58u: goto label_8004DF58;
    case 0x8004DF5Cu: goto label_8004DF5C;
    case 0x8004DF60u: goto label_8004DF60;
    case 0x8004DF64u: goto label_8004DF64;
    case 0x8004DF68u: goto label_8004DF68;
    case 0x8004DF6Cu: goto label_8004DF6C;
    case 0x8004DF70u: goto label_8004DF70;
    case 0x8004DF74u: goto label_8004DF74;
    case 0x8004DF78u: goto label_8004DF78;
    case 0x8004DF7Cu: goto label_8004DF7C;
    case 0x8004DF80u: goto label_8004DF80;
    case 0x8004DF84u: goto label_8004DF84;
    case 0x8004DF88u: goto label_8004DF88;
    case 0x8004DF8Cu: goto label_8004DF8C;
    case 0x8004DF90u: goto label_8004DF90;
    case 0x8004DF94u: goto label_8004DF94;
    case 0x8004DF98u: goto label_8004DF98;
    case 0x8004DF9Cu: goto label_8004DF9C;
    case 0x8004DFA0u: goto label_8004DFA0;
    case 0x8004DFA4u: goto label_8004DFA4;
    case 0x8004DFA8u: goto label_8004DFA8;
    case 0x8004DFACu: goto label_8004DFAC;
    case 0x8004DFB0u: goto label_8004DFB0;
    case 0x8004DFB4u: goto label_8004DFB4;
    case 0x8004DFB8u: goto label_8004DFB8;
    case 0x8004DFBCu: goto label_8004DFBC;
    case 0x8004DFC0u: goto label_8004DFC0;
    case 0x8004DFC4u: goto label_8004DFC4;
    case 0x8004DFC8u: goto label_8004DFC8;
    case 0x8004DFCCu: goto label_8004DFCC;
    case 0x8004DFD0u: goto label_8004DFD0;
    case 0x8004DFD4u: goto label_8004DFD4;
    case 0x8004DFD8u: goto label_8004DFD8;
    case 0x8004DFDCu: goto label_8004DFDC;
    case 0x8004DFE0u: goto label_8004DFE0;
    case 0x8004DFE4u: goto label_8004DFE4;
    case 0x8004DFE8u: goto label_8004DFE8;
    case 0x8004DFECu: goto label_8004DFEC;
    case 0x8004DFF0u: goto label_8004DFF0;
    case 0x8004DFF4u: goto label_8004DFF4;
    case 0x8004DFF8u: goto label_8004DFF8;
    case 0x8004DFFCu: goto label_8004DFFC;
    case 0x8004E000u: goto label_8004E000;
    case 0x8004E004u: goto label_8004E004;
    case 0x8004E008u: goto label_8004E008;
    case 0x8004E00Cu: goto label_8004E00C;
    case 0x8004E010u: goto label_8004E010;
    case 0x8004E014u: goto label_8004E014;
    case 0x8004E018u: goto label_8004E018;
    case 0x8004E01Cu: goto label_8004E01C;
    case 0x8004E020u: goto label_8004E020;
    case 0x8004E024u: goto label_8004E024;
    case 0x8004E028u: goto label_8004E028;
    case 0x8004E02Cu: goto label_8004E02C;
    case 0x8004E030u: goto label_8004E030;
    case 0x8004E034u: goto label_8004E034;
    case 0x8004E038u: goto label_8004E038;
    case 0x8004E03Cu: goto label_8004E03C;
    case 0x8004E040u: goto label_8004E040;
    case 0x8004E044u: goto label_8004E044;
    case 0x8004E048u: goto label_8004E048;
    case 0x8004E04Cu: goto label_8004E04C;
    case 0x8004E050u: goto label_8004E050;
    case 0x8004E054u: goto label_8004E054;
    case 0x8004E058u: goto label_8004E058;
    case 0x8004E05Cu: goto label_8004E05C;
    case 0x8004E060u: goto label_8004E060;
    case 0x8004E064u: goto label_8004E064;
    case 0x8004E068u: goto label_8004E068;
    case 0x8004E06Cu: goto label_8004E06C;
    case 0x8004E070u: goto label_8004E070;
    case 0x8004E074u: goto label_8004E074;
    case 0x8004E078u: goto label_8004E078;
    case 0x8004E07Cu: goto label_8004E07C;
    case 0x8004E080u: goto label_8004E080;
    case 0x8004E084u: goto label_8004E084;
    case 0x8004E088u: goto label_8004E088;
    case 0x8004E08Cu: goto label_8004E08C;
    case 0x8004E090u: goto label_8004E090;
    case 0x8004E094u: goto label_8004E094;
    case 0x8004E098u: goto label_8004E098;
    case 0x8004E09Cu: goto label_8004E09C;
    case 0x8004E0A0u: goto label_8004E0A0;
    case 0x8004E0A4u: goto label_8004E0A4;
    case 0x8004E0A8u: goto label_8004E0A8;
    case 0x8004E0ACu: goto label_8004E0AC;
    case 0x8004E0B0u: goto label_8004E0B0;
    case 0x8004E0B4u: goto label_8004E0B4;
    case 0x8004E0B8u: goto label_8004E0B8;
    case 0x8004E0BCu: goto label_8004E0BC;
    case 0x8004E0C0u: goto label_8004E0C0;
    case 0x8004E0C4u: goto label_8004E0C4;
    case 0x8004E0C8u: goto label_8004E0C8;
    case 0x8004E0CCu: goto label_8004E0CC;
    case 0x8004E0D0u: goto label_8004E0D0;
    case 0x8004E0D4u: goto label_8004E0D4;
    case 0x8004E0D8u: goto label_8004E0D8;
    case 0x8004E0DCu: goto label_8004E0DC;
    case 0x8004E0E0u: goto label_8004E0E0;
    case 0x8004E0E4u: goto label_8004E0E4;
    case 0x8004E0E8u: goto label_8004E0E8;
    case 0x8004E0ECu: goto label_8004E0EC;
    case 0x8004E0F0u: goto label_8004E0F0;
    case 0x8004E0F4u: goto label_8004E0F4;
    case 0x8004E0F8u: goto label_8004E0F8;
    case 0x8004E0FCu: goto label_8004E0FC;
    case 0x8004E100u: goto label_8004E100;
    case 0x8004E104u: goto label_8004E104;
    case 0x8004E108u: goto label_8004E108;
    case 0x8004E10Cu: goto label_8004E10C;
    case 0x8004E110u: goto label_8004E110;
    case 0x8004E114u: goto label_8004E114;
    case 0x8004E118u: goto label_8004E118;
    case 0x8004E11Cu: goto label_8004E11C;
    case 0x8004E120u: goto label_8004E120;
    case 0x8004E124u: goto label_8004E124;
    case 0x8004E128u: goto label_8004E128;
    case 0x8004E12Cu: goto label_8004E12C;
    case 0x8004E130u: goto label_8004E130;
    case 0x8004E134u: goto label_8004E134;
    case 0x8004E138u: goto label_8004E138;
    case 0x8004E13Cu: goto label_8004E13C;
    case 0x8004E140u: goto label_8004E140;
    case 0x8004E144u: goto label_8004E144;
    case 0x8004E148u: goto label_8004E148;
    case 0x8004E14Cu: goto label_8004E14C;
    case 0x8004E150u: goto label_8004E150;
    case 0x8004E154u: goto label_8004E154;
    case 0x8004E158u: goto label_8004E158;
    case 0x8004E15Cu: goto label_8004E15C;
    case 0x8004E160u: goto label_8004E160;
    case 0x8004E164u: goto label_8004E164;
    case 0x8004E168u: goto label_8004E168;
    case 0x8004E16Cu: goto label_8004E16C;
    case 0x8004E170u: goto label_8004E170;
    case 0x8004E174u: goto label_8004E174;
    case 0x8004E178u: goto label_8004E178;
    case 0x8004E17Cu: goto label_8004E17C;
    case 0x8004E180u: goto label_8004E180;
    case 0x8004E184u: goto label_8004E184;
    case 0x8004E188u: goto label_8004E188;
    case 0x8004E18Cu: goto label_8004E18C;
    case 0x8004E190u: goto label_8004E190;
    case 0x8004E194u: goto label_8004E194;
    case 0x8004E198u: goto label_8004E198;
    case 0x8004E19Cu: goto label_8004E19C;
    case 0x8004E1A0u: goto label_8004E1A0;
    case 0x8004E1A4u: goto label_8004E1A4;
    case 0x8004E1A8u: goto label_8004E1A8;
    case 0x8004E1ACu: goto label_8004E1AC;
    case 0x8004E1B0u: goto label_8004E1B0;
    case 0x8004E1B4u: goto label_8004E1B4;
    case 0x8004E1B8u: goto label_8004E1B8;
    case 0x8004E1BCu: goto label_8004E1BC;
    case 0x8004E1C0u: goto label_8004E1C0;
    case 0x8004E1C4u: goto label_8004E1C4;
    case 0x8004E1C8u: goto label_8004E1C8;
    case 0x8004E1CCu: goto label_8004E1CC;
    case 0x8004E1D0u: goto label_8004E1D0;
    case 0x8004E1D4u: goto label_8004E1D4;
    case 0x8004E1D8u: goto label_8004E1D8;
    case 0x8004E1DCu: goto label_8004E1DC;
    case 0x8004E1E0u: goto label_8004E1E0;
    case 0x8004E1E4u: goto label_8004E1E4;
    case 0x8004E1E8u: goto label_8004E1E8;
    case 0x8004E1ECu: goto label_8004E1EC;
    case 0x8004E1F0u: goto label_8004E1F0;
    case 0x8004E1F4u: goto label_8004E1F4;
    case 0x8004E1F8u: goto label_8004E1F8;
    case 0x8004E1FCu: goto label_8004E1FC;
    case 0x8004E200u: goto label_8004E200;
    case 0x8004E204u: goto label_8004E204;
    case 0x8004E208u: goto label_8004E208;
    case 0x8004E20Cu: goto label_8004E20C;
    case 0x8004E210u: goto label_8004E210;
    case 0x8004E214u: goto label_8004E214;
    case 0x8004E218u: goto label_8004E218;
    case 0x8004E21Cu: goto label_8004E21C;
    case 0x8004E220u: goto label_8004E220;
    case 0x8004E224u: goto label_8004E224;
    case 0x8004E228u: goto label_8004E228;
    case 0x8004E22Cu: goto label_8004E22C;
    case 0x8004E230u: goto label_8004E230;
    case 0x8004E234u: goto label_8004E234;
    case 0x8004E238u: goto label_8004E238;
    case 0x8004E23Cu: goto label_8004E23C;
    case 0x8004E240u: goto label_8004E240;
    case 0x8004E244u: goto label_8004E244;
    case 0x8004E248u: goto label_8004E248;
    case 0x8004E24Cu: goto label_8004E24C;
    case 0x8004E250u: goto label_8004E250;
    case 0x8004E254u: goto label_8004E254;
    case 0x8004E258u: goto label_8004E258;
    case 0x8004E25Cu: goto label_8004E25C;
    case 0x8004E260u: goto label_8004E260;
    case 0x8004E264u: goto label_8004E264;
    case 0x8004E268u: goto label_8004E268;
    case 0x8004E26Cu: goto label_8004E26C;
    case 0x8004E270u: goto label_8004E270;
    case 0x8004E274u: goto label_8004E274;
    case 0x8004E278u: goto label_8004E278;
    case 0x8004E27Cu: goto label_8004E27C;
    case 0x8004E280u: goto label_8004E280;
    case 0x8004E284u: goto label_8004E284;
    case 0x8004E288u: goto label_8004E288;
    case 0x8004E28Cu: goto label_8004E28C;
    case 0x8004E290u: goto label_8004E290;
    case 0x8004E294u: goto label_8004E294;
    case 0x8004E298u: goto label_8004E298;
    case 0x8004E29Cu: goto label_8004E29C;
    case 0x8004E2A0u: goto label_8004E2A0;
    case 0x8004E2A4u: goto label_8004E2A4;
    case 0x8004E2A8u: goto label_8004E2A8;
    case 0x8004E2ACu: goto label_8004E2AC;
    case 0x8004E2B0u: goto label_8004E2B0;
    case 0x8004E2B4u: goto label_8004E2B4;
    case 0x8004E2B8u: goto label_8004E2B8;
    case 0x8004E2BCu: goto label_8004E2BC;
    case 0x8004E2C0u: goto label_8004E2C0;
    case 0x8004E2C4u: goto label_8004E2C4;
    case 0x8004E2C8u: goto label_8004E2C8;
    case 0x8004E2CCu: goto label_8004E2CC;
    case 0x8004E2D0u: goto label_8004E2D0;
    case 0x8004E2D4u: goto label_8004E2D4;
    case 0x8004E2D8u: goto label_8004E2D8;
    case 0x8004E2DCu: goto label_8004E2DC;
    case 0x8004E2E0u: goto label_8004E2E0;
    case 0x8004E2E4u: goto label_8004E2E4;
    case 0x8004E2E8u: goto label_8004E2E8;
    case 0x8004E2ECu: goto label_8004E2EC;
    case 0x8004E2F0u: goto label_8004E2F0;
    case 0x8004E2F4u: goto label_8004E2F4;
    case 0x8004E2F8u: goto label_8004E2F8;
    case 0x8004E2FCu: goto label_8004E2FC;
    case 0x8004E300u: goto label_8004E300;
    case 0x8004E304u: goto label_8004E304;
    case 0x8004E308u: goto label_8004E308;
    case 0x8004E30Cu: goto label_8004E30C;
    case 0x8004E310u: goto label_8004E310;
    case 0x8004E314u: goto label_8004E314;
    case 0x8004E318u: goto label_8004E318;
    case 0x8004E31Cu: goto label_8004E31C;
    case 0x8004E320u: goto label_8004E320;
    case 0x8004E324u: goto label_8004E324;
    case 0x8004E328u: goto label_8004E328;
    case 0x8004E32Cu: goto label_8004E32C;
    case 0x8004E330u: goto label_8004E330;
    case 0x8004E334u: goto label_8004E334;
    case 0x8004E338u: goto label_8004E338;
    case 0x8004E33Cu: goto label_8004E33C;
    case 0x8004E340u: goto label_8004E340;
    case 0x8004E344u: goto label_8004E344;
    case 0x8004E348u: goto label_8004E348;
    case 0x8004E34Cu: goto label_8004E34C;
    case 0x8004E350u: goto label_8004E350;
    case 0x8004E354u: goto label_8004E354;
    case 0x8004E358u: goto label_8004E358;
    case 0x8004E35Cu: goto label_8004E35C;
    case 0x8004E360u: goto label_8004E360;
    case 0x8004E364u: goto label_8004E364;
    case 0x8004E368u: goto label_8004E368;
    case 0x8004E36Cu: goto label_8004E36C;
    case 0x8004E370u: goto label_8004E370;
    case 0x8004E374u: goto label_8004E374;
    case 0x8004E378u: goto label_8004E378;
    case 0x8004E37Cu: goto label_8004E37C;
    case 0x8004E380u: goto label_8004E380;
    case 0x8004E384u: goto label_8004E384;
    case 0x8004E388u: goto label_8004E388;
    case 0x8004E38Cu: goto label_8004E38C;
    case 0x8004E390u: goto label_8004E390;
    case 0x8004E394u: goto label_8004E394;
    case 0x8004E398u: goto label_8004E398;
    case 0x8004E39Cu: goto label_8004E39C;
    case 0x8004E3A0u: goto label_8004E3A0;
    case 0x8004E3A4u: goto label_8004E3A4;
    case 0x8004E3A8u: goto label_8004E3A8;
    case 0x8004E3ACu: goto label_8004E3AC;
    case 0x8004E3B0u: goto label_8004E3B0;
    case 0x8004E3B4u: goto label_8004E3B4;
    case 0x8004E3B8u: goto label_8004E3B8;
    case 0x8004E3BCu: goto label_8004E3BC;
    case 0x8004E3C0u: goto label_8004E3C0;
    case 0x8004E3C4u: goto label_8004E3C4;
    case 0x8004E3C8u: goto label_8004E3C8;
    case 0x8004E3CCu: goto label_8004E3CC;
    case 0x8004E3D0u: goto label_8004E3D0;
    case 0x8004E3D4u: goto label_8004E3D4;
    case 0x8004E3D8u: goto label_8004E3D8;
    case 0x8004E3DCu: goto label_8004E3DC;
    case 0x8004E3E0u: goto label_8004E3E0;
    case 0x8004E3E4u: goto label_8004E3E4;
    case 0x8004E3E8u: goto label_8004E3E8;
    case 0x8004E3ECu: goto label_8004E3EC;
    case 0x8004E3F0u: goto label_8004E3F0;
    case 0x8004E3F4u: goto label_8004E3F4;
    case 0x8004E3F8u: goto label_8004E3F8;
    case 0x8004E3FCu: goto label_8004E3FC;
    case 0x8004E400u: goto label_8004E400;
    case 0x8004E404u: goto label_8004E404;
    case 0x8004E408u: goto label_8004E408;
    case 0x8004E40Cu: goto label_8004E40C;
    case 0x8004E410u: goto label_8004E410;
    case 0x8004E414u: goto label_8004E414;
    case 0x8004E418u: goto label_8004E418;
    case 0x8004E41Cu: goto label_8004E41C;
    case 0x8004E420u: goto label_8004E420;
    case 0x8004E424u: goto label_8004E424;
    case 0x8004E428u: goto label_8004E428;
    case 0x8004E42Cu: goto label_8004E42C;
    case 0x8004E430u: goto label_8004E430;
    case 0x8004E434u: goto label_8004E434;
    case 0x8004E438u: goto label_8004E438;
    case 0x8004E43Cu: goto label_8004E43C;
    case 0x8004E440u: goto label_8004E440;
    case 0x8004E444u: goto label_8004E444;
    case 0x8004E448u: goto label_8004E448;
    case 0x8004E44Cu: goto label_8004E44C;
    case 0x8004E450u: goto label_8004E450;
    case 0x8004E454u: goto label_8004E454;
    case 0x8004E458u: goto label_8004E458;
    case 0x8004E45Cu: goto label_8004E45C;
    case 0x8004E460u: goto label_8004E460;
    case 0x8004E464u: goto label_8004E464;
    case 0x8004E468u: goto label_8004E468;
    case 0x8004E46Cu: goto label_8004E46C;
    case 0x8004E470u: goto label_8004E470;
    case 0x8004E474u: goto label_8004E474;
    case 0x8004E478u: goto label_8004E478;
    case 0x8004E47Cu: goto label_8004E47C;
    case 0x8004E480u: goto label_8004E480;
    case 0x8004E484u: goto label_8004E484;
    case 0x8004E488u: goto label_8004E488;
    case 0x8004E48Cu: goto label_8004E48C;
    case 0x8004E490u: goto label_8004E490;
    case 0x8004E494u: goto label_8004E494;
    case 0x8004E498u: goto label_8004E498;
    case 0x8004E49Cu: goto label_8004E49C;
    case 0x8004E4A0u: goto label_8004E4A0;
    case 0x8004E4A4u: goto label_8004E4A4;
    case 0x8004E4A8u: goto label_8004E4A8;
    case 0x8004E4ACu: goto label_8004E4AC;
    case 0x8004E4B0u: goto label_8004E4B0;
    case 0x8004E4B4u: goto label_8004E4B4;
    case 0x8004E4B8u: goto label_8004E4B8;
    case 0x8004E4BCu: goto label_8004E4BC;
    case 0x8004E4C0u: goto label_8004E4C0;
    case 0x8004E4C4u: goto label_8004E4C4;
    case 0x8004E4C8u: goto label_8004E4C8;
    case 0x8004E4CCu: goto label_8004E4CC;
    case 0x8004E4D0u: goto label_8004E4D0;
    case 0x8004E4D4u: goto label_8004E4D4;
    case 0x8004E4D8u: goto label_8004E4D8;
    case 0x8004E4DCu: goto label_8004E4DC;
    case 0x8004E4E0u: goto label_8004E4E0;
    case 0x8004E4E4u: goto label_8004E4E4;
    case 0x8004E4E8u: goto label_8004E4E8;
    case 0x8004E4ECu: goto label_8004E4EC;
    case 0x8004E4F0u: goto label_8004E4F0;
    case 0x8004E4F4u: goto label_8004E4F4;
    case 0x8004E4F8u: goto label_8004E4F8;
    case 0x8004E4FCu: goto label_8004E4FC;
    case 0x8004E500u: goto label_8004E500;
    case 0x8004E504u: goto label_8004E504;
    case 0x8004E508u: goto label_8004E508;
    case 0x8004E50Cu: goto label_8004E50C;
    case 0x8004E510u: goto label_8004E510;
    case 0x8004E514u: goto label_8004E514;
    case 0x8004E518u: goto label_8004E518;
    case 0x8004E51Cu: goto label_8004E51C;
    case 0x8004E520u: goto label_8004E520;
    case 0x8004E524u: goto label_8004E524;
    case 0x8004E528u: goto label_8004E528;
    case 0x8004E52Cu: goto label_8004E52C;
    case 0x8004E530u: goto label_8004E530;
    case 0x8004E534u: goto label_8004E534;
    case 0x8004E538u: goto label_8004E538;
    case 0x8004E53Cu: goto label_8004E53C;
    case 0x8004E540u: goto label_8004E540;
    case 0x8004E544u: goto label_8004E544;
    case 0x8004E548u: goto label_8004E548;
    case 0x8004E54Cu: goto label_8004E54C;
    case 0x8004E550u: goto label_8004E550;
    case 0x8004E554u: goto label_8004E554;
    case 0x8004E558u: goto label_8004E558;
    case 0x8004E55Cu: goto label_8004E55C;
    case 0x8004E560u: goto label_8004E560;
    case 0x8004E564u: goto label_8004E564;
    case 0x8004E568u: goto label_8004E568;
    case 0x8004E56Cu: goto label_8004E56C;
    case 0x8004E570u: goto label_8004E570;
    case 0x8004E574u: goto label_8004E574;
    case 0x8004E578u: goto label_8004E578;
    case 0x8004E57Cu: goto label_8004E57C;
    case 0x8004E580u: goto label_8004E580;
    case 0x8004E584u: goto label_8004E584;
    case 0x8004E588u: goto label_8004E588;
    case 0x8004E58Cu: goto label_8004E58C;
    case 0x8004E590u: goto label_8004E590;
    case 0x8004E594u: goto label_8004E594;
    case 0x8004E598u: goto label_8004E598;
    case 0x8004E59Cu: goto label_8004E59C;
    case 0x8004E5A0u: goto label_8004E5A0;
    case 0x8004E5A4u: goto label_8004E5A4;
    case 0x8004E5A8u: goto label_8004E5A8;
    case 0x8004E5ACu: goto label_8004E5AC;
    case 0x8004E5B0u: goto label_8004E5B0;
    case 0x8004E5B4u: goto label_8004E5B4;
    case 0x8004E5B8u: goto label_8004E5B8;
    case 0x8004E5BCu: goto label_8004E5BC;
    case 0x8004E5C0u: goto label_8004E5C0;
    case 0x8004E5C4u: goto label_8004E5C4;
    case 0x8004E5C8u: goto label_8004E5C8;
    case 0x8004E5CCu: goto label_8004E5CC;
    case 0x8004E5D0u: goto label_8004E5D0;
    case 0x8004E5D4u: goto label_8004E5D4;
    case 0x8004E5D8u: goto label_8004E5D8;
    case 0x8004E5DCu: goto label_8004E5DC;
    case 0x8004E5E0u: goto label_8004E5E0;
    case 0x8004E5E4u: goto label_8004E5E4;
    case 0x8004E5E8u: goto label_8004E5E8;
    case 0x8004E5ECu: goto label_8004E5EC;
    case 0x8004E5F0u: goto label_8004E5F0;
    case 0x8004E5F4u: goto label_8004E5F4;
    case 0x8004E5F8u: goto label_8004E5F8;
    case 0x8004E5FCu: goto label_8004E5FC;
    case 0x8004E600u: goto label_8004E600;
    case 0x8004E604u: goto label_8004E604;
    case 0x8004E608u: goto label_8004E608;
    case 0x8004E60Cu: goto label_8004E60C;
    case 0x8004E610u: goto label_8004E610;
    case 0x8004E614u: goto label_8004E614;
    case 0x8004E618u: goto label_8004E618;
    case 0x8004E61Cu: goto label_8004E61C;
    case 0x8004E620u: goto label_8004E620;
    case 0x8004E624u: goto label_8004E624;
    case 0x8004E628u: goto label_8004E628;
    case 0x8004E62Cu: goto label_8004E62C;
    case 0x8004E630u: goto label_8004E630;
    case 0x8004E634u: goto label_8004E634;
    case 0x8004E638u: goto label_8004E638;
    case 0x8004E63Cu: goto label_8004E63C;
    case 0x8004E640u: goto label_8004E640;
    case 0x8004E644u: goto label_8004E644;
    case 0x8004E648u: goto label_8004E648;
    case 0x8004E64Cu: goto label_8004E64C;
    case 0x8004E650u: goto label_8004E650;
    case 0x8004E654u: goto label_8004E654;
    case 0x8004E658u: goto label_8004E658;
    case 0x8004E65Cu: goto label_8004E65C;
    case 0x8004E660u: goto label_8004E660;
    case 0x8004E664u: goto label_8004E664;
    case 0x8004E668u: goto label_8004E668;
    case 0x8004E66Cu: goto label_8004E66C;
    case 0x8004E670u: goto label_8004E670;
    case 0x8004E674u: goto label_8004E674;
    case 0x8004E678u: goto label_8004E678;
    case 0x8004E67Cu: goto label_8004E67C;
    case 0x8004E680u: goto label_8004E680;
    case 0x8004E684u: goto label_8004E684;
    case 0x8004E688u: goto label_8004E688;
    case 0x8004E68Cu: goto label_8004E68C;
    case 0x8004E690u: goto label_8004E690;
    case 0x8004E694u: goto label_8004E694;
    case 0x8004E698u: goto label_8004E698;
    case 0x8004E69Cu: goto label_8004E69C;
    case 0x8004E6A0u: goto label_8004E6A0;
    case 0x8004E6A4u: goto label_8004E6A4;
    case 0x8004E6A8u: goto label_8004E6A8;
    case 0x8004E6ACu: goto label_8004E6AC;
    case 0x8004E6B0u: goto label_8004E6B0;
    case 0x8004E6B4u: goto label_8004E6B4;
    case 0x8004E6B8u: goto label_8004E6B8;
    case 0x8004E6BCu: goto label_8004E6BC;
    case 0x8004E6C0u: goto label_8004E6C0;
    case 0x8004E6C4u: goto label_8004E6C4;
    case 0x8004E6C8u: goto label_8004E6C8;
    case 0x8004E6CCu: goto label_8004E6CC;
    case 0x8004E6D0u: goto label_8004E6D0;
    case 0x8004E6D4u: goto label_8004E6D4;
    case 0x8004E6D8u: goto label_8004E6D8;
    case 0x8004E6DCu: goto label_8004E6DC;
    default: return;
    }
label_8004A6E0:
    ctx->pc = 0x8004A6E0u;
    ctx->downcount -= 4;
    // 8004A6E0: lwz     r0, -25784(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25784);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A6E4:
    ctx->pc = 0x8004A6E4u;
    // 8004A6E4: lwz     r3, -25756(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25756);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004A6E8:
    ctx->pc = 0x8004A6E8u;
    // 8004A6E8: cmplw   r0, r3
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[3]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004A6EC:
    ctx->pc = 0x8004A6ECu;
    // 8004A6EC: bc    4, 2, 0x8004A6F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004A6F4;
        }
    }

label_8004A6F0:
    ctx->pc = 0x8004A6F0u;
    ctx->downcount -= 1;
    // 8004A6F0: lwz     r3, -25760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25760);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004A6F4:
    ctx->pc = 0x8004A6F4u;
    ctx->downcount -= 4;
    // 8004A6F4: stw     r3, -25784(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25784);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8004A6F8:
    ctx->pc = 0x8004A6F8u;
    // 8004A6F8: rlwinm r0, r30, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[30], 0u) & 0x000000FFu;
    }

label_8004A6FC:
    ctx->pc = 0x8004A6FCu;
    // 8004A6FC: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004A700:
    ctx->pc = 0x8004A700u;
    // 8004A700: bc    12, 2, 0x8004A734
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004A734;
        }
    }

label_8004A704:
    ctx->pc = 0x8004A704u;
    ctx->downcount -= 3;
    // 8004A704: lbz     r3, -31684(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31684);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8004A708:
    ctx->pc = 0x8004A708u;
    // 8004A708: cmplwi  r3, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004A70C:
    ctx->pc = 0x8004A70Cu;
    // 8004A70C: bc    12, 2, 0x8004A734
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004A734;
        }
    }

label_8004A710:
    ctx->pc = 0x8004A710u;
    ctx->downcount -= 5;
    // 8004A710: addi    r0, r3, -1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-1);

label_8004A714:
    ctx->pc = 0x8004A714u;
    // 8004A714: stb     r0, -31684(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31684);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004A718:
    ctx->pc = 0x8004A718u;
    // 8004A718: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_8004A71C:
    ctx->pc = 0x8004A71Cu;
    // 8004A71C: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004A720:
    ctx->pc = 0x8004A720u;
    // 8004A720: bc    4, 2, 0x8004A734
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004A734;
        }
    }

label_8004A724:
    ctx->pc = 0x8004A724u;
    ctx->downcount -= 2;
    // 8004A724: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8004A728:
    ctx->pc = 0x8004A728u;
    // 8004A728: bl      0x8024E088
    {
            ctx->lr = 0x8004A72Cu;
            ctx->pc = 0x8024E088u;
            return;
    }

label_8004A72C:
    ctx->pc = 0x8004A72Cu;
    ctx->downcount -= 2;
    // 8004A72C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8004A730:
    ctx->pc = 0x8004A730u;
    // 8004A730: stb     r0, -31684(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31684);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004A734:
    ctx->pc = 0x8004A734u;
    ctx->downcount -= 8;
    // 8004A734: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8004A738:
    ctx->pc = 0x8004A738u;
    // 8004A738: lwz     r31, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8004A73C:
    ctx->pc = 0x8004A73Cu;
    // 8004A73C: lwz     r30, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8004A740:
    ctx->pc = 0x8004A740u;
    // 8004A740: lwz     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A744:
    ctx->pc = 0x8004A744u;
    // 8004A744: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A748:
    ctx->pc = 0x8004A748u;
    // 8004A748: addi    r1, r1, 48
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(48);

label_8004A74C:
    ctx->pc = 0x8004A74Cu;
    // 8004A74C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004A750:
    ctx->pc = 0x8004A750u;
    ctx->downcount -= 7;
    // 8004A750: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A754:
    ctx->pc = 0x8004A754u;
    // 8004A754: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A758:
    ctx->pc = 0x8004A758u;
    // 8004A758: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A75C:
    ctx->pc = 0x8004A75Cu;
    // 8004A75C: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8004A760:
    ctx->pc = 0x8004A760u;
    // 8004A760: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A764:
    ctx->pc = 0x8004A764u;
    // 8004A764: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8004A768:
    ctx->pc = 0x8004A768u;
    // 8004A768: bl      0x8024E088
    {
            ctx->lr = 0x8004A76Cu;
            ctx->pc = 0x8024E088u;
            return;
    }

label_8004A76C:
    ctx->pc = 0x8004A76Cu;
    ctx->downcount -= 1;
    // 8004A76C: bl      0x8024DF00
    {
            ctx->lr = 0x8004A770u;
            ctx->pc = 0x8024DF00u;
            return;
    }

label_8004A770:
    ctx->pc = 0x8004A770u;
    ctx->downcount -= 8;
    // 8004A770: rlwinm r0, r31, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[31], 0u) & 0x000000FFu;
    }

label_8004A774:
    ctx->pc = 0x8004A774u;
    // 8004A774: stb     r0, -31684(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31684);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004A778:
    ctx->pc = 0x8004A778u;
    // 8004A778: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8004A77C:
    ctx->pc = 0x8004A77Cu;
    // 8004A77C: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A780:
    ctx->pc = 0x8004A780u;
    // 8004A780: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A784:
    ctx->pc = 0x8004A784u;
    // 8004A784: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8004A788:
    ctx->pc = 0x8004A788u;
    // 8004A788: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004A78C:
    ctx->pc = 0x8004A78Cu;
    ctx->downcount -= 5;
    // 8004A78C: stwu     r1, -80(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-80);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A790:
    ctx->pc = 0x8004A790u;
    // 8004A790: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A794:
    ctx->pc = 0x8004A794u;
    // 8004A794: stw     r0, 84(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A798:
    ctx->pc = 0x8004A798u;
    // 8004A798: addi    r11, r1, 80
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(80);

label_8004A79C:
    ctx->pc = 0x8004A79Cu;
    // 8004A79C: bl      0x80286A4C
    {
            ctx->lr = 0x8004A7A0u;
            ctx->pc = 0x80286A4Cu;
            return;
    }

label_8004A7A0:
    ctx->pc = 0x8004A7A0u;
    ctx->downcount -= 7;
    // 8004A7A0: lis     r3, -32723
    ctx->gpr[3] = ((u32)(s32)(-32723) << 16);

label_8004A7A4:
    ctx->pc = 0x8004A7A4u;
    // 8004A7A4: addi    r31, r3, -8576
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(-8576);

label_8004A7A8:
    ctx->pc = 0x8004A7A8u;
    // 8004A7A8: addi    r3, r1, 36
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(36);

label_8004A7AC:
    ctx->pc = 0x8004A7ACu;
    // 8004A7AC: addi    r4, r1, 40
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(40);

label_8004A7B0:
    ctx->pc = 0x8004A7B0u;
    // 8004A7B0: addi    r5, r1, 28
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(28);

label_8004A7B4:
    ctx->pc = 0x8004A7B4u;
    // 8004A7B4: addi    r6, r1, 32
    ctx->gpr[6] = ctx->gpr[1] + (u32)(s32)(32);

label_8004A7B8:
    ctx->pc = 0x8004A7B8u;
    // 8004A7B8: bl      0x8025E72C
    {
            ctx->lr = 0x8004A7BCu;
            ctx->pc = 0x8025E72Cu;
            return;
    }

label_8004A7BC:
    ctx->pc = 0x8004A7BCu;
    ctx->downcount -= 5;
    // 8004A7BC: addi    r3, r1, 20
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(20);

label_8004A7C0:
    ctx->pc = 0x8004A7C0u;
    // 8004A7C0: addi    r4, r1, 24
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(24);

label_8004A7C4:
    ctx->pc = 0x8004A7C4u;
    // 8004A7C4: addi    r5, r1, 12
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(12);

label_8004A7C8:
    ctx->pc = 0x8004A7C8u;
    // 8004A7C8: addi    r6, r1, 16
    ctx->gpr[6] = ctx->gpr[1] + (u32)(s32)(16);

label_8004A7CC:
    ctx->pc = 0x8004A7CCu;
    // 8004A7CC: bl      0x8025E72C
    {
            ctx->lr = 0x8004A7D0u;
            ctx->pc = 0x8025E72Cu;
            return;
    }

label_8004A7D0:
    ctx->pc = 0x8004A7D0u;
    ctx->downcount -= 28;
    // 8004A7D0: lwz     r3, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004A7D4:
    ctx->pc = 0x8004A7D4u;
    // 8004A7D4: lwz     r0, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A7D8:
    ctx->pc = 0x8004A7D8u;
    // 8004A7D8: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_8004A7DC:
    ctx->pc = 0x8004A7DCu;
    // 8004A7DC: cntlzw r0, r0
    {
        u32 v = ctx->gpr[0];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_8004A7E0:
    ctx->pc = 0x8004A7E0u;
    // 8004A7E0: rlwinm r30, r0, 27, 5, 31
    {
        ctx->gpr[30] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x07FFFFFFu;
    }

label_8004A7E4:
    ctx->pc = 0x8004A7E4u;
    // 8004A7E4: lwz     r3, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004A7E8:
    ctx->pc = 0x8004A7E8u;
    // 8004A7E8: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A7EC:
    ctx->pc = 0x8004A7ECu;
    // 8004A7EC: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_8004A7F0:
    ctx->pc = 0x8004A7F0u;
    // 8004A7F0: cntlzw r0, r0
    {
        u32 v = ctx->gpr[0];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_8004A7F4:
    ctx->pc = 0x8004A7F4u;
    // 8004A7F4: rlwinm r29, r0, 27, 5, 31
    {
        ctx->gpr[29] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x07FFFFFFu;
    }

label_8004A7F8:
    ctx->pc = 0x8004A7F8u;
    // 8004A7F8: lwz     r3, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004A7FC:
    ctx->pc = 0x8004A7FCu;
    // 8004A7FC: lwz     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A800:
    ctx->pc = 0x8004A800u;
    // 8004A800: subf   r3, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[3] = res;
    }

label_8004A804:
    ctx->pc = 0x8004A804u;
    // 8004A804: neg  r0, r3
    {
        u32 a = ctx->gpr[3];
        ctx->gpr[0] = (~a) + 1u;
    }

label_8004A808:
    ctx->pc = 0x8004A808u;
    // 8004A808: or   r0, r0, r3
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[3];
    }

label_8004A80C:
    ctx->pc = 0x8004A80Cu;
    // 8004A80C: rlwinm r28, r0, 1, 31, 31
    {
        ctx->gpr[28] = dolrecomp_rotl32(ctx->gpr[0], 1u) & 0x00000001u;
    }

label_8004A810:
    ctx->pc = 0x8004A810u;
    // 8004A810: lwz     r3, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004A814:
    ctx->pc = 0x8004A814u;
    // 8004A814: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A818:
    ctx->pc = 0x8004A818u;
    // 8004A818: subf   r3, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[3] = res;
    }

label_8004A81C:
    ctx->pc = 0x8004A81Cu;
    // 8004A81C: neg  r0, r3
    {
        u32 a = ctx->gpr[3];
        ctx->gpr[0] = (~a) + 1u;
    }

label_8004A820:
    ctx->pc = 0x8004A820u;
    // 8004A820: or   r0, r0, r3
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[3];
    }

label_8004A824:
    ctx->pc = 0x8004A824u;
    // 8004A824: rlwinm r27, r0, 1, 31, 31
    {
        ctx->gpr[27] = dolrecomp_rotl32(ctx->gpr[0], 1u) & 0x00000001u;
    }

label_8004A828:
    ctx->pc = 0x8004A828u;
    // 8004A828: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_8004A82C:
    ctx->pc = 0x8004A82Cu;
    // 8004A82C: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A830:
    ctx->pc = 0x8004A830u;
    // 8004A830: addi    r5, r1, 10
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(10);

label_8004A834:
    ctx->pc = 0x8004A834u;
    // 8004A834: addi    r6, r1, 9
    ctx->gpr[6] = ctx->gpr[1] + (u32)(s32)(9);

label_8004A838:
    ctx->pc = 0x8004A838u;
    // 8004A838: or   r7, r3, r3
    {
        ctx->gpr[7] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004A83C:
    ctx->pc = 0x8004A83Cu;
    // 8004A83C: bl      0x80256CD4
    {
            ctx->lr = 0x8004A840u;
            ctx->pc = 0x80256CD4u;
            return;
    }

label_8004A840:
    ctx->pc = 0x8004A840u;
    ctx->downcount -= 10;
    // 8004A840: addis   r3, r31, 4
    ctx->gpr[3] = ctx->gpr[31] + ((u32)(s32)(4) << 16);

label_8004A844:
    ctx->pc = 0x8004A844u;
    // 8004A844: addi    r3, r3, 44
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(44);

label_8004A848:
    ctx->pc = 0x8004A848u;
    // 8004A848: lbz     r4, 10(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(10);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_8004A84C:
    ctx->pc = 0x8004A84Cu;
    // 8004A84C: lbz     r5, 9(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(9);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_8004A850:
    ctx->pc = 0x8004A850u;
    // 8004A850: or   r6, r30, r30
    {
        ctx->gpr[6] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8004A854:
    ctx->pc = 0x8004A854u;
    // 8004A854: or   r7, r29, r29
    {
        ctx->gpr[7] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8004A858:
    ctx->pc = 0x8004A858u;
    // 8004A858: or   r8, r28, r28
    {
        ctx->gpr[8] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8004A85C:
    ctx->pc = 0x8004A85Cu;
    // 8004A85C: or   r9, r27, r27
    {
        ctx->gpr[9] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8004A860:
    ctx->pc = 0x8004A860u;
    // 8004A860: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8004A864:
    ctx->pc = 0x8004A864u;
    // 8004A864: bl      0x8007D8C0
    {
            ctx->lr = 0x8004A868u;
            ctx->pc = 0x8007D8C0u;
            return;
    }

label_8004A868:
    ctx->pc = 0x8004A868u;
    ctx->downcount -= 2;
    // 8004A868: cmplwi  r29, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[29]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004A86C:
    ctx->pc = 0x8004A86Cu;
    // 8004A86C: bc    4, 2, 0x8004A88C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004A88C;
        }
    }

label_8004A870:
    ctx->pc = 0x8004A870u;
    ctx->downcount -= 2;
    // 8004A870: cmplwi  r28, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[28]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004A874:
    ctx->pc = 0x8004A874u;
    // 8004A874: bc    12, 2, 0x8004A88C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004A88C;
        }
    }

label_8004A878:
    ctx->pc = 0x8004A878u;
    ctx->downcount -= 4;
    // 8004A878: addis   r3, r31, 4
    ctx->gpr[3] = ctx->gpr[31] + ((u32)(s32)(4) << 16);

label_8004A87C:
    ctx->pc = 0x8004A87Cu;
    // 8004A87C: addi    r3, r3, 252
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(252);

label_8004A880:
    ctx->pc = 0x8004A880u;
    // 8004A880: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8004A884:
    ctx->pc = 0x8004A884u;
    // 8004A884: bl      0x8007D8C0
    {
            ctx->lr = 0x8004A888u;
            ctx->pc = 0x8007D8C0u;
            return;
    }

label_8004A888:
    ctx->pc = 0x8004A888u;
    ctx->downcount -= 1;
    // 8004A888: b       0x8004A948
    {
            goto label_8004A948;
    }

label_8004A88C:
    ctx->pc = 0x8004A88Cu;
    ctx->downcount -= 2;
    // 8004A88C: cmplwi  r30, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[30]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004A890:
    ctx->pc = 0x8004A890u;
    // 8004A890: bc    4, 2, 0x8004A8B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004A8B8;
        }
    }

label_8004A894:
    ctx->pc = 0x8004A894u;
    ctx->downcount -= 2;
    // 8004A894: cmplwi  r29, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[29]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004A898:
    ctx->pc = 0x8004A898u;
    // 8004A898: bc    12, 2, 0x8004A8B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004A8B8;
        }
    }

label_8004A89C:
    ctx->pc = 0x8004A89Cu;
    ctx->downcount -= 2;
    // 8004A89C: cmplwi  r28, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[28]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004A8A0:
    ctx->pc = 0x8004A8A0u;
    // 8004A8A0: bc    12, 2, 0x8004A8B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004A8B8;
        }
    }

label_8004A8A4:
    ctx->pc = 0x8004A8A4u;
    ctx->downcount -= 4;
    // 8004A8A4: addis   r3, r31, 4
    ctx->gpr[3] = ctx->gpr[31] + ((u32)(s32)(4) << 16);

label_8004A8A8:
    ctx->pc = 0x8004A8A8u;
    // 8004A8A8: addi    r3, r3, 284
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(284);

label_8004A8AC:
    ctx->pc = 0x8004A8ACu;
    // 8004A8AC: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8004A8B0:
    ctx->pc = 0x8004A8B0u;
    // 8004A8B0: bl      0x8007D8C0
    {
            ctx->lr = 0x8004A8B4u;
            ctx->pc = 0x8007D8C0u;
            return;
    }

label_8004A8B4:
    ctx->pc = 0x8004A8B4u;
    ctx->downcount -= 1;
    // 8004A8B4: b       0x8004A948
    {
            goto label_8004A948;
    }

label_8004A8B8:
    ctx->pc = 0x8004A8B8u;
    ctx->downcount -= 3;
    // 8004A8B8: lbz     r3, 9(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(9);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8004A8BC:
    ctx->pc = 0x8004A8BCu;
    // 8004A8BC: cmplwi  r3, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004A8C0:
    ctx->pc = 0x8004A8C0u;
    // 8004A8C0: bc    4, 2, 0x8004A8F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004A8F0;
        }
    }

label_8004A8C4:
    ctx->pc = 0x8004A8C4u;
    ctx->downcount -= 2;
    // 8004A8C4: cmplwi  r30, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[30]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004A8C8:
    ctx->pc = 0x8004A8C8u;
    // 8004A8C8: bc    12, 2, 0x8004A8F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004A8F0;
        }
    }

label_8004A8CC:
    ctx->pc = 0x8004A8CCu;
    ctx->downcount -= 2;
    // 8004A8CC: cmplwi  r29, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[29]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004A8D0:
    ctx->pc = 0x8004A8D0u;
    // 8004A8D0: bc    12, 2, 0x8004A8F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004A8F0;
        }
    }

label_8004A8D4:
    ctx->pc = 0x8004A8D4u;
    ctx->downcount -= 2;
    // 8004A8D4: cmplwi  r28, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[28]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004A8D8:
    ctx->pc = 0x8004A8D8u;
    // 8004A8D8: bc    12, 2, 0x8004A8F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004A8F0;
        }
    }

label_8004A8DC:
    ctx->pc = 0x8004A8DCu;
    ctx->downcount -= 4;
    // 8004A8DC: addis   r3, r31, 4
    ctx->gpr[3] = ctx->gpr[31] + ((u32)(s32)(4) << 16);

label_8004A8E0:
    ctx->pc = 0x8004A8E0u;
    // 8004A8E0: addi    r3, r3, 324
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(324);

label_8004A8E4:
    ctx->pc = 0x8004A8E4u;
    // 8004A8E4: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8004A8E8:
    ctx->pc = 0x8004A8E8u;
    // 8004A8E8: bl      0x8007D8C0
    {
            ctx->lr = 0x8004A8ECu;
            ctx->pc = 0x8007D8C0u;
            return;
    }

label_8004A8EC:
    ctx->pc = 0x8004A8ECu;
    ctx->downcount -= 1;
    // 8004A8EC: b       0x8004A948
    {
            goto label_8004A948;
    }

label_8004A8F0:
    ctx->pc = 0x8004A8F0u;
    ctx->downcount -= 3;
    // 8004A8F0: lbz     r0, 10(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(10);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8004A8F4:
    ctx->pc = 0x8004A8F4u;
    // 8004A8F4: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004A8F8:
    ctx->pc = 0x8004A8F8u;
    // 8004A8F8: bc    12, 2, 0x8004A938
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004A938;
        }
    }

label_8004A8FC:
    ctx->pc = 0x8004A8FCu;
    ctx->downcount -= 2;
    // 8004A8FC: cmplwi  r3, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004A900:
    ctx->pc = 0x8004A900u;
    // 8004A900: bc    12, 2, 0x8004A938
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004A938;
        }
    }

label_8004A904:
    ctx->pc = 0x8004A904u;
    ctx->downcount -= 2;
    // 8004A904: cmplwi  r30, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[30]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004A908:
    ctx->pc = 0x8004A908u;
    // 8004A908: bc    12, 2, 0x8004A938
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004A938;
        }
    }

label_8004A90C:
    ctx->pc = 0x8004A90Cu;
    ctx->downcount -= 2;
    // 8004A90C: cmplwi  r29, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[29]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004A910:
    ctx->pc = 0x8004A910u;
    // 8004A910: bc    12, 2, 0x8004A938
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004A938;
        }
    }

label_8004A914:
    ctx->pc = 0x8004A914u;
    ctx->downcount -= 2;
    // 8004A914: cmplwi  r28, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[28]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004A918:
    ctx->pc = 0x8004A918u;
    // 8004A918: bc    12, 2, 0x8004A938
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004A938;
        }
    }

label_8004A91C:
    ctx->pc = 0x8004A91Cu;
    ctx->downcount -= 2;
    // 8004A91C: cmplwi  r27, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[27]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004A920:
    ctx->pc = 0x8004A920u;
    // 8004A920: bc    12, 2, 0x8004A938
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004A938;
        }
    }

label_8004A924:
    ctx->pc = 0x8004A924u;
    ctx->downcount -= 4;
    // 8004A924: addis   r3, r31, 4
    ctx->gpr[3] = ctx->gpr[31] + ((u32)(s32)(4) << 16);

label_8004A928:
    ctx->pc = 0x8004A928u;
    // 8004A928: addi    r3, r3, 364
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(364);

label_8004A92C:
    ctx->pc = 0x8004A92Cu;
    // 8004A92C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8004A930:
    ctx->pc = 0x8004A930u;
    // 8004A930: bl      0x8007D8C0
    {
            ctx->lr = 0x8004A934u;
            ctx->pc = 0x8007D8C0u;
            return;
    }

label_8004A934:
    ctx->pc = 0x8004A934u;
    ctx->downcount -= 1;
    // 8004A934: b       0x8004A948
    {
            goto label_8004A948;
    }

label_8004A938:
    ctx->pc = 0x8004A938u;
    ctx->downcount -= 4;
    // 8004A938: addis   r3, r31, 4
    ctx->gpr[3] = ctx->gpr[31] + ((u32)(s32)(4) << 16);

label_8004A93C:
    ctx->pc = 0x8004A93Cu;
    // 8004A93C: addi    r3, r3, 412
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(412);

label_8004A940:
    ctx->pc = 0x8004A940u;
    // 8004A940: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8004A944:
    ctx->pc = 0x8004A944u;
    // 8004A944: bl      0x8007D8C0
    {
            ctx->lr = 0x8004A948u;
            ctx->pc = 0x8007D8C0u;
            return;
    }

label_8004A948:
    ctx->pc = 0x8004A948u;
    ctx->downcount -= 2;
    // 8004A948: addi    r11, r1, 80
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(80);

label_8004A94C:
    ctx->pc = 0x8004A94Cu;
    // 8004A94C: bl      0x80286A98
    {
            ctx->lr = 0x8004A950u;
            ctx->pc = 0x80286A98u;
            return;
    }

label_8004A950:
    ctx->pc = 0x8004A950u;
    ctx->downcount -= 5;
    // 8004A950: lwz     r0, 84(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004A954:
    ctx->pc = 0x8004A954u;
    // 8004A954: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004A958:
    ctx->pc = 0x8004A958u;
    // 8004A958: addi    r1, r1, 80
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(80);

label_8004A95C:
    ctx->pc = 0x8004A95Cu;
    // 8004A95C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004A960:
    ctx->pc = 0x8004A960u;
    ctx->downcount -= 6;
    // 8004A960: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004A964:
    ctx->pc = 0x8004A964u;
    // 8004A964: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004A968:
    ctx->pc = 0x8004A968u;
    // 8004A968: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A96C:
    ctx->pc = 0x8004A96Cu;
    // 8004A96C: rlwinm r0, r3, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000000FFu;
    }

label_8004A970:
    ctx->pc = 0x8004A970u;
    // 8004A970: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004A974:
    ctx->pc = 0x8004A974u;
    // 8004A974: bc    12, 2, 0x8004A9D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004A9D4;
        }
    }

label_8004A978:
    ctx->pc = 0x8004A978u;
    ctx->downcount -= 3;
    // 8004A978: li      r3, 35
    ctx->gpr[3] = (u32)(s32)(35);

label_8004A97C:
    ctx->pc = 0x8004A97Cu;
    // 8004A97C: li      r4, 22
    ctx->gpr[4] = (u32)(s32)(22);

label_8004A980:
    ctx->pc = 0x8004A980u;
    // 8004A980: bl      0x8025DE84
    {
            ctx->lr = 0x8004A984u;
            ctx->pc = 0x8025DE84u;
            return;
    }

label_8004A984:
    ctx->pc = 0x8004A984u;
    ctx->downcount -= 20;
    // 8004A984: li      r5, 97
    ctx->gpr[5] = (u32)(s32)(97);

label_8004A988:
    ctx->pc = 0x8004A988u;
    // 8004A988: lis     r4, -13311
    ctx->gpr[4] = ((u32)(s32)(-13311) << 16);

label_8004A98C:
    ctx->pc = 0x8004A98Cu;
    // 8004A98C: stb     r5, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

label_8004A990:
    ctx->pc = 0x8004A990u;
    // 8004A990: lis     r3, 9219
    ctx->gpr[3] = ((u32)(s32)(9219) << 16);

label_8004A994:
    ctx->pc = 0x8004A994u;
    // 8004A994: addi    r0, r3, -16380
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-16380);

label_8004A998:
    ctx->pc = 0x8004A998u;
    // 8004A998: stw     r0, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A99C:
    ctx->pc = 0x8004A99Cu;
    // 8004A99C: stb     r5, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

label_8004A9A0:
    ctx->pc = 0x8004A9A0u;
    // 8004A9A0: lis     r3, 8960
    ctx->gpr[3] = ((u32)(s32)(8960) << 16);

label_8004A9A4:
    ctx->pc = 0x8004A9A4u;
    // 8004A9A4: addi    r0, r3, 32
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(32);

label_8004A9A8:
    ctx->pc = 0x8004A9A8u;
    // 8004A9A8: stw     r0, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A9AC:
    ctx->pc = 0x8004A9ACu;
    // 8004A9AC: li      r0, 16
    ctx->gpr[0] = (u32)(s32)(16);

label_8004A9B0:
    ctx->pc = 0x8004A9B0u;
    // 8004A9B0: stb     r0, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004A9B4:
    ctx->pc = 0x8004A9B4u;
    // 8004A9B4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8004A9B8:
    ctx->pc = 0x8004A9B8u;
    // 8004A9B8: sth     r0, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8004A9BC:
    ctx->pc = 0x8004A9BCu;
    // 8004A9BC: li      r0, 4102
    ctx->gpr[0] = (u32)(s32)(4102);

label_8004A9C0:
    ctx->pc = 0x8004A9C0u;
    // 8004A9C0: sth     r0, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8004A9C4:
    ctx->pc = 0x8004A9C4u;
    // 8004A9C4: lis     r3, 8
    ctx->gpr[3] = ((u32)(s32)(8) << 16);

label_8004A9C8:
    ctx->pc = 0x8004A9C8u;
    // 8004A9C8: addi    r0, r3, 17408
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(17408);

label_8004A9CC:
    ctx->pc = 0x8004A9CCu;
    // 8004A9CC: stw     r0, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A9D0:
    ctx->pc = 0x8004A9D0u;
    // 8004A9D0: b       0x8004AA10
    {
            goto label_8004AA10;
    }

label_8004A9D4:
    ctx->pc = 0x8004A9D4u;
    ctx->downcount -= 15;
    // 8004A9D4: li      r3, 97
    ctx->gpr[3] = (u32)(s32)(97);

label_8004A9D8:
    ctx->pc = 0x8004A9D8u;
    // 8004A9D8: lis     r4, -13311
    ctx->gpr[4] = ((u32)(s32)(-13311) << 16);

label_8004A9DC:
    ctx->pc = 0x8004A9DCu;
    // 8004A9DC: stb     r3, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_8004A9E0:
    ctx->pc = 0x8004A9E0u;
    // 8004A9E0: lis     r0, 9216
    ctx->gpr[0] = ((u32)(s32)(9216) << 16);

label_8004A9E4:
    ctx->pc = 0x8004A9E4u;
    // 8004A9E4: stw     r0, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A9E8:
    ctx->pc = 0x8004A9E8u;
    // 8004A9E8: stb     r3, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_8004A9EC:
    ctx->pc = 0x8004A9ECu;
    // 8004A9EC: lis     r0, 8960
    ctx->gpr[0] = ((u32)(s32)(8960) << 16);

label_8004A9F0:
    ctx->pc = 0x8004A9F0u;
    // 8004A9F0: stw     r0, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004A9F4:
    ctx->pc = 0x8004A9F4u;
    // 8004A9F4: li      r0, 16
    ctx->gpr[0] = (u32)(s32)(16);

label_8004A9F8:
    ctx->pc = 0x8004A9F8u;
    // 8004A9F8: stb     r0, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004A9FC:
    ctx->pc = 0x8004A9FCu;
    // 8004A9FC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8004AA00:
    ctx->pc = 0x8004AA00u;
    // 8004AA00: sth     r3, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_8004AA04:
    ctx->pc = 0x8004AA04u;
    // 8004AA04: li      r0, 4102
    ctx->gpr[0] = (u32)(s32)(4102);

label_8004AA08:
    ctx->pc = 0x8004AA08u;
    // 8004AA08: sth     r0, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8004AA0C:
    ctx->pc = 0x8004AA0Cu;
    // 8004AA0C: stw     r3, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8004AA10:
    ctx->pc = 0x8004AA10u;
    ctx->downcount -= 5;
    // 8004AA10: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AA14:
    ctx->pc = 0x8004AA14u;
    // 8004AA14: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004AA18:
    ctx->pc = 0x8004AA18u;
    // 8004AA18: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8004AA1C:
    ctx->pc = 0x8004AA1Cu;
    // 8004AA1C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004AA20:
    ctx->pc = 0x8004AA20u;
    ctx->downcount -= 7;
    // 8004AA20: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004AA24:
    ctx->pc = 0x8004AA24u;
    // 8004AA24: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004AA28:
    ctx->pc = 0x8004AA28u;
    // 8004AA28: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004AA2C:
    ctx->pc = 0x8004AA2Cu;
    // 8004AA2C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8004AA30:
    ctx->pc = 0x8004AA30u;
    // 8004AA30: stb     r0, -25816(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25816);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004AA34:
    ctx->pc = 0x8004AA34u;
    // 8004AA34: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8004AA38:
    ctx->pc = 0x8004AA38u;
    // 8004AA38: bl      0x8004A960
    {
            ctx->lr = 0x8004AA3Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004A960u;
                return;
            }
            goto label_8004A960;
    }

label_8004AA3C:
    ctx->pc = 0x8004AA3Cu;
    ctx->downcount -= 5;
    // 8004AA3C: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AA40:
    ctx->pc = 0x8004AA40u;
    // 8004AA40: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004AA44:
    ctx->pc = 0x8004AA44u;
    // 8004AA44: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8004AA48:
    ctx->pc = 0x8004AA48u;
    // 8004AA48: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004AA4C:
    ctx->pc = 0x8004AA4Cu;
    ctx->downcount -= 7;
    // 8004AA4C: stwu     r1, -48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-48);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004AA50:
    ctx->pc = 0x8004AA50u;
    // 8004AA50: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004AA54:
    ctx->pc = 0x8004AA54u;
    // 8004AA54: stw     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004AA58:
    ctx->pc = 0x8004AA58u;
    // 8004AA58: stw     r31, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8004AA5C:
    ctx->pc = 0x8004AA5Cu;
    // 8004AA5C: lis     r3, -32714
    ctx->gpr[3] = ((u32)(s32)(-32714) << 16);

label_8004AA60:
    ctx->pc = 0x8004AA60u;
    // 8004AA60: addi    r3, r3, 4064
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4064);

label_8004AA64:
    ctx->pc = 0x8004AA64u;
    // 8004AA64: bl      0x80246414
    {
            ctx->lr = 0x8004AA68u;
            ctx->pc = 0x80246414u;
            return;
    }

label_8004AA68:
    ctx->pc = 0x8004AA68u;
    ctx->downcount -= 3;
    // 8004AA68: lis     r3, -32714
    ctx->gpr[3] = ((u32)(s32)(-32714) << 16);

label_8004AA6C:
    ctx->pc = 0x8004AA6Cu;
    // 8004AA6C: addi    r3, r3, 4064
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4064);

label_8004AA70:
    ctx->pc = 0x8004AA70u;
    // 8004AA70: bl      0x802464E0
    {
            ctx->lr = 0x8004AA74u;
            ctx->pc = 0x802464E0u;
            return;
    }

label_8004AA74:
    ctx->pc = 0x8004AA74u;
    ctx->downcount -= 1;
    // 8004AA74: bl      0x80286EDC
    {
            ctx->lr = 0x8004AA78u;
            ctx->pc = 0x80286EDCu;
            return;
    }

label_8004AA78:
    ctx->pc = 0x8004AA78u;
    ctx->downcount -= 38;
    // 8004AA78: lis     r3, -32768
    ctx->gpr[3] = ((u32)(s32)(-32768) << 16);

label_8004AA7C:
    ctx->pc = 0x8004AA7Cu;
    // 8004AA7C: lwz     r0, 248(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(248);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AA80:
    ctx->pc = 0x8004AA80u;
    // 8004AA80: rlwinm r0, r0, 30, 2, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 30u) & 0x3FFFFFFFu;
    }

label_8004AA84:
    ctx->pc = 0x8004AA84u;
    // 8004AA84: lis     r3, 4194
    ctx->gpr[3] = ((u32)(s32)(4194) << 16);

label_8004AA88:
    ctx->pc = 0x8004AA88u;
    // 8004AA88: addi    r3, r3, 19923
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(19923);

label_8004AA8C:
    ctx->pc = 0x8004AA8Cu;
    // 8004AA8C: mulhwu   r0, r3, r0
    {
        u64 product = (u64)ctx->gpr[3] * (u64)ctx->gpr[0];
        ctx->gpr[0] = (u32)(product >> 32);
    }

label_8004AA90:
    ctx->pc = 0x8004AA90u;
    // 8004AA90: rlwinm r0, r0, 26, 6, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 26u) & 0x03FFFFFFu;
    }

label_8004AA94:
    ctx->pc = 0x8004AA94u;
    // 8004AA94: lfd     f2, -31352(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004AA94u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31352);
        ctx->fpr[2] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8004AA98:
    ctx->pc = 0x8004AA98u;
    // 8004AA98: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004AA9C:
    ctx->pc = 0x8004AA9Cu;
    // 8004AA9C: lis     r0, 17200
    ctx->gpr[0] = ((u32)(s32)(17200) << 16);

label_8004AAA0:
    ctx->pc = 0x8004AAA0u;
    // 8004AAA0: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004AAA4:
    ctx->pc = 0x8004AAA4u;
    // 8004AAA4: lfd     f0, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004AAA4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8004AAA8:
    ctx->pc = 0x8004AAA8u;
    // 8004AAA8: fsubs   f0, f0, f2
    if (!ppc_fp_available_inline(ctx, 0x8004AAA8u)) return;
    ppc_fsubs(ctx, 0, 0, 2);

label_8004AAAC:
    ctx->pc = 0x8004AAACu;
    // 8004AAAC: fdivs   f0, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8004AAACu)) return;
    ppc_fdivs(ctx, 0, 1, 0);

label_8004AAB0:
    ctx->pc = 0x8004AAB0u;
    // 8004AAB0: stfs     f0, -25800(r13)
    if (!ppc_fp_available_inline(ctx, 0x8004AAB0u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25800);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004AAB4:
    ctx->pc = 0x8004AAB4u;
    // 8004AAB4: lis     r3, -32714
    ctx->gpr[3] = ((u32)(s32)(-32714) << 16);

label_8004AAB8:
    ctx->pc = 0x8004AAB8u;
    // 8004AAB8: addi    r3, r3, 4064
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4064);

label_8004AABC:
    ctx->pc = 0x8004AABCu;
    // 8004AABC: bl      0x80246550
    {
            ctx->lr = 0x8004AAC0u;
            ctx->pc = 0x80246550u;
            return;
    }

label_8004AAC0:
    ctx->pc = 0x8004AAC0u;
    ctx->downcount -= 3;
    // 8004AAC0: lis     r3, -32714
    ctx->gpr[3] = ((u32)(s32)(-32714) << 16);

label_8004AAC4:
    ctx->pc = 0x8004AAC4u;
    // 8004AAC4: addi    r3, r3, 4064
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4064);

label_8004AAC8:
    ctx->pc = 0x8004AAC8u;
    // 8004AAC8: bl      0x802463D8
    {
            ctx->lr = 0x8004AACCu;
            ctx->pc = 0x802463D8u;
            return;
    }

label_8004AACC:
    ctx->pc = 0x8004AACCu;
    ctx->downcount -= 9;
    // 8004AACC: lfs     f2, -31324(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004AACCu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31324);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8004AAD0:
    ctx->pc = 0x8004AAD0u;
    // 8004AAD0: lfs     f1, -31320(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004AAD0u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31320);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8004AAD4:
    ctx->pc = 0x8004AAD4u;
    // 8004AAD4: lfs     f0, -25800(r13)
    if (!ppc_fp_available_inline(ctx, 0x8004AAD4u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25800);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004AAD8:
    ctx->pc = 0x8004AAD8u;
    // 8004AAD8: fmuls   f0, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8004AAD8u)) return;
    ppc_fmuls(ctx, 0, 1, 0);

label_8004AADC:
    ctx->pc = 0x8004AADCu;
    // 8004AADC: fmuls   f0, f2, f0
    if (!ppc_fp_available_inline(ctx, 0x8004AADCu)) return;
    ppc_fmuls(ctx, 0, 2, 0);

label_8004AAE0:
    ctx->pc = 0x8004AAE0u;
    // 8004AAE0: stfs     f0, -32116(r13)
    if (!ppc_fp_available_inline(ctx, 0x8004AAE0u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32116);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004AAE4:
    ctx->pc = 0x8004AAE4u;
    // 8004AAE4: lbz     r0, -26672(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26672);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8004AAE8:
    ctx->pc = 0x8004AAE8u;
    // 8004AAE8: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004AAEC:
    ctx->pc = 0x8004AAECu;
    // 8004AAEC: bc    12, 2, 0x8004AAF8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004AAF8;
        }
    }

label_8004AAF0:
    ctx->pc = 0x8004AAF0u;
    ctx->downcount -= 2;
    // 8004AAF0: lfs     f0, -31368(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004AAF0u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31368);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004AAF4:
    ctx->pc = 0x8004AAF4u;
    // 8004AAF4: stfs     f0, -32116(r13)
    if (!ppc_fp_available_inline(ctx, 0x8004AAF4u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32116);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004AAF8:
    ctx->pc = 0x8004AAF8u;
    ctx->downcount -= 4;
    // 8004AAF8: lfs     f1, -32116(r13)
    if (!ppc_fp_available_inline(ctx, 0x8004AAF8u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32116);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8004AAFC:
    ctx->pc = 0x8004AAFCu;
    // 8004AAFC: lfs     f0, -31364(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004AAFCu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31364);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004AB00:
    ctx->pc = 0x8004AB00u;
    // 8004AB00: fcmpo   cr0, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8004AB00u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[1], ctx->fpr[0], true);

label_8004AB04:
    ctx->pc = 0x8004AB04u;
    // 8004AB04: bc    4, 1, 0x8004AB0C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004AB0C;
        }
    }

label_8004AB08:
    ctx->pc = 0x8004AB08u;
    ctx->downcount -= 1;
    // 8004AB08: stfs     f0, -32116(r13)
    if (!ppc_fp_available_inline(ctx, 0x8004AB08u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32116);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004AB0C:
    ctx->pc = 0x8004AB0Cu;
    ctx->downcount -= 4;
    // 8004AB0C: lfs     f1, -32116(r13)
    if (!ppc_fp_available_inline(ctx, 0x8004AB0Cu)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32116);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8004AB10:
    ctx->pc = 0x8004AB10u;
    // 8004AB10: lfs     f0, -31356(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004AB10u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31356);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004AB14:
    ctx->pc = 0x8004AB14u;
    // 8004AB14: fcmpo   cr0, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8004AB14u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[1], ctx->fpr[0], true);

label_8004AB18:
    ctx->pc = 0x8004AB18u;
    // 8004AB18: bc    4, 1, 0x8004AB28
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004AB28;
        }
    }

label_8004AB1C:
    ctx->pc = 0x8004AB1Cu;
    ctx->downcount -= 19;
    // 8004AB1C: lfs     f0, -31360(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004AB1Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31360);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004AB20:
    ctx->pc = 0x8004AB20u;
    // 8004AB20: fdivs   f0, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8004AB20u)) return;
    ppc_fdivs(ctx, 0, 0, 1);

label_8004AB24:
    ctx->pc = 0x8004AB24u;
    // 8004AB24: b       0x8004AB2C
    {
            goto label_8004AB2C;
    }

label_8004AB28:
    ctx->pc = 0x8004AB28u;
    ctx->downcount -= 1;
    // 8004AB28: lfs     f0, -31360(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004AB28u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31360);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004AB2C:
    ctx->pc = 0x8004AB2Cu;
    ctx->downcount -= 20;
    // 8004AB2C: stfs     f0, -32112(r13)
    if (!ppc_fp_available_inline(ctx, 0x8004AB2Cu)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32112);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004AB30:
    ctx->pc = 0x8004AB30u;
    // 8004AB30: lfs     f0, -25812(r13)
    if (!ppc_fp_available_inline(ctx, 0x8004AB30u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25812);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004AB34:
    ctx->pc = 0x8004AB34u;
    // 8004AB34: fadds   f2, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8004AB34u)) return;
    ppc_fadds(ctx, 2, 1, 0);

label_8004AB38:
    ctx->pc = 0x8004AB38u;
    // 8004AB38: fctiwz    f0, f2
    if (!ppc_fp_available_inline(ctx, 0x8004AB38u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[2], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_8004AB3C:
    ctx->pc = 0x8004AB3Cu;
    // 8004AB3C: stfd     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004AB3Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_8004AB40:
    ctx->pc = 0x8004AB40u;
    // 8004AB40: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AB44:
    ctx->pc = 0x8004AB44u;
    // 8004AB44: rlwinm r4, r0, 0, 24, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_8004AB48:
    ctx->pc = 0x8004AB48u;
    // 8004AB48: stb     r4, -32120(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32120);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_8004AB4C:
    ctx->pc = 0x8004AB4Cu;
    // 8004AB4C: rlwinm r3, r4, 0, 24, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x000000FFu;
    }

label_8004AB50:
    ctx->pc = 0x8004AB50u;
    // 8004AB50: lfd     f1, -31352(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004AB50u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31352);
        ctx->fpr[1] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8004AB54:
    ctx->pc = 0x8004AB54u;
    // 8004AB54: stw     r3, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8004AB58:
    ctx->pc = 0x8004AB58u;
    // 8004AB58: lis     r0, 17200
    ctx->gpr[0] = ((u32)(s32)(17200) << 16);

label_8004AB5C:
    ctx->pc = 0x8004AB5Cu;
    // 8004AB5C: stw     r0, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004AB60:
    ctx->pc = 0x8004AB60u;
    // 8004AB60: lfd     f0, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004AB60u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8004AB64:
    ctx->pc = 0x8004AB64u;
    // 8004AB64: fsubs   f0, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8004AB64u)) return;
    ppc_fsubs(ctx, 0, 0, 1);

label_8004AB68:
    ctx->pc = 0x8004AB68u;
    // 8004AB68: fsubs   f0, f2, f0
    if (!ppc_fp_available_inline(ctx, 0x8004AB68u)) return;
    ppc_fsubs(ctx, 0, 2, 0);

label_8004AB6C:
    ctx->pc = 0x8004AB6Cu;
    // 8004AB6C: stfs     f0, -25812(r13)
    if (!ppc_fp_available_inline(ctx, 0x8004AB6Cu)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25812);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004AB70:
    ctx->pc = 0x8004AB70u;
    // 8004AB70: stb     r4, -32119(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32119);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_8004AB74:
    ctx->pc = 0x8004AB74u;
    // 8004AB74: cmplwi  r3, 0x0001
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0001u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004AB78:
    ctx->pc = 0x8004AB78u;
    // 8004AB78: bc    4, 0, 0x8004AB84
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004AB84;
        }
    }

label_8004AB7C:
    ctx->pc = 0x8004AB7Cu;
    ctx->downcount -= 2;
    // 8004AB7C: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8004AB80:
    ctx->pc = 0x8004AB80u;
    // 8004AB80: stb     r0, -32120(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32120);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004AB84:
    ctx->pc = 0x8004AB84u;
    ctx->downcount -= 1;
    // 8004AB84: bl      0x802440BC
    {
            ctx->lr = 0x8004AB88u;
            ctx->pc = 0x802440BCu;
            return;
    }

label_8004AB88:
    ctx->pc = 0x8004AB88u;
    ctx->downcount -= 2;
    // 8004AB88: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004AB8C:
    ctx->pc = 0x8004AB8Cu;
    // 8004AB8C: bl      0x80246734
    {
            ctx->lr = 0x8004AB90u;
            ctx->pc = 0x80246734u;
            return;
    }

label_8004AB90:
    ctx->pc = 0x8004AB90u;
    ctx->downcount -= 5;
    // 8004AB90: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004AB94:
    ctx->pc = 0x8004AB94u;
    // 8004AB94: stw     r6, -25772(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25772);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8004AB98:
    ctx->pc = 0x8004AB98u;
    // 8004AB98: lhz     r4, 712(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(712);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_8004AB9C:
    ctx->pc = 0x8004AB9Cu;
    // 8004AB9C: cmplwi  r4, 0x0002
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(0x0002u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004ABA0:
    ctx->pc = 0x8004ABA0u;
    // 8004ABA0: bc    12, 2, 0x8004ABBC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004ABBC;
        }
    }

label_8004ABA4:
    ctx->pc = 0x8004ABA4u;
    ctx->downcount -= 6;
    // 8004ABA4: lis     r3, -32719
    ctx->gpr[3] = ((u32)(s32)(-32719) << 16);

label_8004ABA8:
    ctx->pc = 0x8004ABA8u;
    // 8004ABA8: addi    r3, r3, -8136
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-8136);

label_8004ABAC:
    ctx->pc = 0x8004ABACu;
    // 8004ABAC: lhz     r5, 714(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(714);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_8004ABB0:
    ctx->pc = 0x8004ABB0u;
    // 8004ABB0: lwz     r6, 716(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(716);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8004ABB4:
    ctx->pc = 0x8004ABB4u;
    // 8004ABB4: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8004ABB8:
    ctx->pc = 0x8004ABB8u;
    // 8004ABB8: bl      0x8007D8C0
    {
            ctx->lr = 0x8004ABBCu;
            ctx->pc = 0x8007D8C0u;
            return;
    }

label_8004ABBC:
    ctx->pc = 0x8004ABBCu;
    ctx->downcount -= 3;
    // 8004ABBC: lis     r3, -32714
    ctx->gpr[3] = ((u32)(s32)(-32714) << 16);

label_8004ABC0:
    ctx->pc = 0x8004ABC0u;
    // 8004ABC0: addi    r3, r3, 4240
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4240);

label_8004ABC4:
    ctx->pc = 0x8004ABC4u;
    // 8004ABC4: bl      0x80013774
    {
            ctx->lr = 0x8004ABC8u;
            ctx->pc = 0x80013774u;
            return;
    }

label_8004ABC8:
    ctx->pc = 0x8004ABC8u;
    ctx->downcount -= 2;
    // 8004ABC8: cmplwi  r3, 0x0001
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0001u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004ABCC:
    ctx->pc = 0x8004ABCCu;
    // 8004ABCC: bc    4, 1, 0x8004ABE0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004ABE0;
        }
    }

label_8004ABD0:
    ctx->pc = 0x8004ABD0u;
    ctx->downcount -= 4;
    // 8004ABD0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8004ABD4:
    ctx->pc = 0x8004ABD4u;
    // 8004ABD4: stw     r0, -25820(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25820);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004ABD8:
    ctx->pc = 0x8004ABD8u;
    // 8004ABD8: addi    r3, r13, -25796
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-25796);

label_8004ABDC:
    ctx->pc = 0x8004ABDCu;
    // 8004ABDC: bl      0x8024740C
    {
            ctx->lr = 0x8004ABE0u;
            ctx->pc = 0x8024740Cu;
            return;
    }

label_8004ABE0:
    ctx->pc = 0x8004ABE0u;
    ctx->downcount -= 2;
    // 8004ABE0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8004ABE4:
    ctx->pc = 0x8004ABE4u;
    // 8004ABE4: bl      0x802440E4
    {
            ctx->lr = 0x8004ABE8u;
            ctx->pc = 0x802440E4u;
            return;
    }

label_8004ABE8:
    ctx->pc = 0x8004ABE8u;
    ctx->downcount -= 1;
    // 8004ABE8: bl      0x8000F7A0
    {
            ctx->lr = 0x8004ABECu;
            ctx->pc = 0x8000F7A0u;
            return;
    }

label_8004ABEC:
    ctx->pc = 0x8004ABECu;
    ctx->downcount -= 1;
    // 8004ABEC: bl      0x80258870
    {
            ctx->lr = 0x8004ABF0u;
            ctx->pc = 0x80258870u;
            return;
    }

label_8004ABF0:
    ctx->pc = 0x8004ABF0u;
    ctx->downcount -= 1;
    // 8004ABF0: bl      0x8025B41C
    {
            ctx->lr = 0x8004ABF4u;
            ctx->pc = 0x8025B41Cu;
            return;
    }

label_8004ABF4:
    ctx->pc = 0x8004ABF4u;
    ctx->downcount -= 6;
    // 8004ABF4: lwz     r31, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8004ABF8:
    ctx->pc = 0x8004ABF8u;
    // 8004ABF8: lwz     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004ABFC:
    ctx->pc = 0x8004ABFCu;
    // 8004ABFC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004AC00:
    ctx->pc = 0x8004AC00u;
    // 8004AC00: addi    r1, r1, 48
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(48);

label_8004AC04:
    ctx->pc = 0x8004AC04u;
    // 8004AC04: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004AC08:
    ctx->pc = 0x8004AC08u;
    ctx->downcount -= 6;
    // 8004AC08: lwz     r6, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8004AC0C:
    ctx->pc = 0x8004AC0Cu;
    // 8004AC0C: lwz     r5, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8004AC10:
    ctx->pc = 0x8004AC10u;
    // 8004AC10: lbz     r0, 25(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(25);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8004AC14:
    ctx->pc = 0x8004AC14u;
    // 8004AC14: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8004AC18:
    ctx->pc = 0x8004AC18u;
    // 8004AC18: cmpwi   r0, 36
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(36);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004AC1C:
    ctx->pc = 0x8004AC1Cu;
    // 8004AC1C: bc    12, 2, 0x8004AC24
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004AC24;
        }
    }

label_8004AC20:
    ctx->pc = 0x8004AC20u;
    ctx->downcount -= 1;
    // 8004AC20: b       0x8004ACA8
    {
            goto label_8004ACA8;
    }

label_8004AC24:
    ctx->pc = 0x8004AC24u;
    ctx->downcount -= 4;
    // 8004AC24: lbz     r4, 12(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_8004AC28:
    ctx->pc = 0x8004AC28u;
    // 8004AC28: rlwinm r0, r4, 0, 24, 24
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x00000080u;
    }

label_8004AC2C:
    ctx->pc = 0x8004AC2Cu;
    // 8004AC2C: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004AC30:
    ctx->pc = 0x8004AC30u;
    // 8004AC30: bc    4, 2, 0x8004ACA0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004ACA0;
        }
    }

label_8004AC34:
    ctx->pc = 0x8004AC34u;
    ctx->downcount -= 3;
    // 8004AC34: lbz     r0, 3(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(3);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8004AC38:
    ctx->pc = 0x8004AC38u;
    // 8004AC38: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004AC3C:
    ctx->pc = 0x8004AC3Cu;
    // 8004AC3C: bc    12, 2, 0x8004AC50
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004AC50;
        }
    }

label_8004AC40:
    ctx->pc = 0x8004AC40u;
    ctx->downcount -= 4;
    // 8004AC40: subf   r0, r6, r0
    {
        u32 a = ~ctx->gpr[6];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_8004AC44:
    ctx->pc = 0x8004AC44u;
    // 8004AC44: cntlzw r0, r0
    {
        u32 v = ctx->gpr[0];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_8004AC48:
    ctx->pc = 0x8004AC48u;
    // 8004AC48: rlwinm r3, r0, 27, 5, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x07FFFFFFu;
    }

label_8004AC4C:
    ctx->pc = 0x8004AC4Cu;
    // 8004AC4C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004AC50:
    ctx->pc = 0x8004AC50u;
    ctx->downcount -= 8;
    // 8004AC50: lwz     r3, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004AC54:
    ctx->pc = 0x8004AC54u;
    // 8004AC54: rlwinm r0, r4, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 4u) & 0xFFFFFFF0u;
    }

label_8004AC58:
    ctx->pc = 0x8004AC58u;
    // 8004AC58: lwzx    r7, r3, r0
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[0];
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8004AC5C:
    ctx->pc = 0x8004AC5Cu;
    // 8004AC5C: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8004AC60:
    ctx->pc = 0x8004AC60u;
    // 8004AC60: or   r4, r7, r7
    {
        ctx->gpr[4] = ctx->gpr[7] | ctx->gpr[7];
    }

label_8004AC64:
    ctx->pc = 0x8004AC64u;
    // 8004AC64: li      r0, 4
    ctx->gpr[0] = (u32)(s32)(4);

label_8004AC68:
    ctx->pc = 0x8004AC68u;
    // 8004AC68: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8004AC6C:
    ctx->pc = 0x8004AC6Cu;
    ctx->downcount -= 4;
    // 8004AC6C: lwz     r3, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004AC70:
    ctx->pc = 0x8004AC70u;
    // 8004AC70: lwz     r0, 28(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AC74:
    // 8004AC74: cmplw   r3, r0
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004AC78:
    // 8004AC78: bc    4, 2, 0x8004AC94
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004AC94;
        }
    }

label_8004AC7C:
    ctx->downcount -= 6;
    // 8004AC7C: add   r3, r8, r7
    {
        u32 a = ctx->gpr[8];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8004AC80:
    ctx->pc = 0x8004AC80u;
    // 8004AC80: lbz     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8004AC84:
    // 8004AC84: subf   r0, r6, r0
    {
        u32 a = ~ctx->gpr[6];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_8004AC88:
    // 8004AC88: cntlzw r0, r0
    {
        u32 v = ctx->gpr[0];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_8004AC8C:
    // 8004AC8C: rlwinm r3, r0, 27, 5, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x07FFFFFFu;
    }

label_8004AC90:
    ctx->pc = 0x8004AC90u;
    // 8004AC90: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004AC94:
    ctx->downcount -= 3;
    // 8004AC94: addi    r4, r4, 4
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(4);

label_8004AC98:
    // 8004AC98: addi    r8, r8, 1
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(1);

label_8004AC9C:
    // 8004AC9C: bc    16, 0, 0x8004AC6C
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004AC6Cu;
                return;
            }
            goto label_8004AC6C;
        }
    }

label_8004ACA0:
    ctx->pc = 0x8004ACA0u;
    ctx->downcount -= 2;
    // 8004ACA0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8004ACA4:
    ctx->pc = 0x8004ACA4u;
    // 8004ACA4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004ACA8:
    ctx->pc = 0x8004ACA8u;
    ctx->downcount -= 4;
    // 8004ACA8: subf   r0, r6, r5
    {
        u32 a = ~ctx->gpr[6];
        u32 b = ctx->gpr[5];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_8004ACAC:
    ctx->pc = 0x8004ACACu;
    // 8004ACAC: cntlzw r0, r0
    {
        u32 v = ctx->gpr[0];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_8004ACB0:
    ctx->pc = 0x8004ACB0u;
    // 8004ACB0: rlwinm r3, r0, 27, 5, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x07FFFFFFu;
    }

label_8004ACB4:
    ctx->pc = 0x8004ACB4u;
    // 8004ACB4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004ACB8:
    ctx->pc = 0x8004ACB8u;
    ctx->downcount -= 6;
    // 8004ACB8: rlwinm r0, r5, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 3u) & 0xFFFFFFF8u;
    }

label_8004ACBC:
    ctx->pc = 0x8004ACBCu;
    // 8004ACBC: lwzx    r9, r3, r0
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[0];
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8004ACC0:
    ctx->pc = 0x8004ACC0u;
    // 8004ACC0: add   r6, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_8004ACC4:
    ctx->pc = 0x8004ACC4u;
    // 8004ACC4: lhz     r10, 4(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read16(ctx, ea);
    }

label_8004ACC8:
    ctx->pc = 0x8004ACC8u;
    // 8004ACC8: srawi r7, r4, 1
    {
        u32 sh = 1u;
        u32 value = ctx->gpr[4];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[7] = value;
        } else if (sh > 31) {
            ctx->gpr[7] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[7] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_8004ACCC:
    ctx->pc = 0x8004ACCCu;
    // 8004ACCC: b       0x8004AD24
    {
            goto label_8004AD24;
    }

label_8004ACD0:
    ctx->downcount -= 3;
    // 8004ACD0: add   r11, r5, r5
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_8004ACD4:
    // 8004ACD4: cmpw    r11, r4
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(ctx->gpr[4]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004ACD8:
    // 8004ACD8: bc    4, 0, 0x8004ACF8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004ACF8;
        }
    }

label_8004ACDC:
    ctx->downcount -= 6;
    // 8004ACDC: rlwinm r0, r11, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[11], 3u) & 0xFFFFFFF8u;
    }

label_8004ACE0:
    // 8004ACE0: add   r8, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_8004ACE4:
    ctx->pc = 0x8004ACE4u;
    // 8004ACE4: lwz     r6, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8004ACE8:
    ctx->pc = 0x8004ACE8u;
    // 8004ACE8: lwz     r0, 8(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004ACEC:
    // 8004ACEC: cmplw   r6, r0
    {
        u32 val_a = (u32)(ctx->gpr[6]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004ACF0:
    // 8004ACF0: bc    4, 0, 0x8004ACF8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004ACF8;
        }
    }

label_8004ACF4:
    ctx->downcount -= 1;
    // 8004ACF4: addi    r11, r11, 1
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(1);

label_8004ACF8:
    ctx->downcount -= 5;
    // 8004ACF8: rlwinm r0, r11, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[11], 3u) & 0xFFFFFFF8u;
    }

label_8004ACFC:
    // 8004ACFC: add   r8, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_8004AD00:
    ctx->pc = 0x8004AD00u;
    // 8004AD00: lwz     r6, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8004AD04:
    // 8004AD04: cmplw   r9, r6
    {
        u32 val_a = (u32)(ctx->gpr[9]);
        u32 val_b = (u32)(ctx->gpr[6]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004AD08:
    // 8004AD08: bc    4, 0, 0x8004AD2C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004AD2C;
        }
    }

label_8004AD0C:
    ctx->downcount -= 6;
    // 8004AD0C: rlwinm r0, r5, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 3u) & 0xFFFFFFF8u;
    }

label_8004AD10:
    // 8004AD10: add   r5, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[5] = res;
    }

label_8004AD14:
    ctx->pc = 0x8004AD14u;
    // 8004AD14: stw     r6, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8004AD18:
    ctx->pc = 0x8004AD18u;
    // 8004AD18: lhz     r0, 4(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8004AD1C:
    ctx->pc = 0x8004AD1Cu;
    // 8004AD1C: sth     r0, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8004AD20:
    // 8004AD20: or   r5, r11, r11
    {
        ctx->gpr[5] = ctx->gpr[11] | ctx->gpr[11];
    }

label_8004AD24:
    ctx->downcount -= 2;
    // 8004AD24: cmpw    r5, r7
    {
        s32 val_a = (s32)(ctx->gpr[5]);
        s32 val_b = (s32)(ctx->gpr[7]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004AD28:
    // 8004AD28: bc    4, 1, 0x8004ACD0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004ACD0u;
                return;
            }
            goto label_8004ACD0;
        }
    }

label_8004AD2C:
    ctx->pc = 0x8004AD2Cu;
    ctx->downcount -= 5;
    // 8004AD2C: rlwinm r0, r5, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 3u) & 0xFFFFFFF8u;
    }

label_8004AD30:
    ctx->pc = 0x8004AD30u;
    // 8004AD30: stwx    r9, r3, r0
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8004AD34:
    ctx->pc = 0x8004AD34u;
    // 8004AD34: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8004AD38:
    ctx->pc = 0x8004AD38u;
    // 8004AD38: sth     r10, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[10]);
    }

label_8004AD3C:
    ctx->pc = 0x8004AD3Cu;
    // 8004AD3C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004AD40:
    ctx->pc = 0x8004AD40u;
    ctx->downcount -= 5;
    // 8004AD40: stwu     r1, -48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-48);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004AD44:
    ctx->pc = 0x8004AD44u;
    // 8004AD44: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004AD48:
    ctx->pc = 0x8004AD48u;
    // 8004AD48: stw     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004AD4C:
    ctx->pc = 0x8004AD4Cu;
    // 8004AD4C: addi    r11, r1, 48
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(48);

label_8004AD50:
    ctx->pc = 0x8004AD50u;
    // 8004AD50: bl      0x80286A40
    {
            ctx->lr = 0x8004AD54u;
            ctx->pc = 0x80286A40u;
            return;
    }

label_8004AD54:
    ctx->pc = 0x8004AD54u;
    ctx->downcount -= 5;
    // 8004AD54: or   r25, r3, r3
    {
        ctx->gpr[25] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004AD58:
    ctx->pc = 0x8004AD58u;
    // 8004AD58: or   r26, r5, r5
    {
        ctx->gpr[26] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8004AD5C:
    ctx->pc = 0x8004AD5Cu;
    // 8004AD5C: or   r27, r6, r6
    {
        ctx->gpr[27] = ctx->gpr[6] | ctx->gpr[6];
    }

label_8004AD60:
    ctx->pc = 0x8004AD60u;
    // 8004AD60: or   r28, r7, r7
    {
        ctx->gpr[28] = ctx->gpr[7] | ctx->gpr[7];
    }

label_8004AD64:
    ctx->pc = 0x8004AD64u;
    // 8004AD64: bl      0x8004AC08
    {
            ctx->lr = 0x8004AD68u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004AC08u;
                return;
            }
            goto label_8004AC08;
    }

label_8004AD68:
    ctx->pc = 0x8004AD68u;
    ctx->downcount -= 2;
    // 8004AD68: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004AD6C:
    ctx->pc = 0x8004AD6Cu;
    // 8004AD6C: bc    12, 2, 0x8004AE58
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004AE58;
        }
    }

label_8004AD70:
    ctx->pc = 0x8004AD70u;
    ctx->downcount -= 3;
    // 8004AD70: lha     r24, 32(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(32);
        ctx->gpr[24] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8004AD74:
    ctx->pc = 0x8004AD74u;
    // 8004AD74: cmpwi   r24, 254
    {
        s32 val_a = (s32)(ctx->gpr[24]);
        s32 val_b = (s32)(254);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004AD78:
    ctx->pc = 0x8004AD78u;
    // 8004AD78: bc    12, 2, 0x8004ADBC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004ADBC;
        }
    }

label_8004AD7C:
    ctx->pc = 0x8004AD7Cu;
    ctx->downcount -= 14;
    // 8004AD7C: lwz     r3, 0(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004AD80:
    ctx->pc = 0x8004AD80u;
    // 8004AD80: addi    r0, r24, 1
    ctx->gpr[0] = ctx->gpr[24] + (u32)(s32)(1);

label_8004AD84:
    ctx->pc = 0x8004AD84u;
    // 8004AD84: sth     r0, 32(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(32);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8004AD88:
    ctx->pc = 0x8004AD88u;
    // 8004AD88: rlwinm r0, r24, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[24], 4u) & 0xFFFFFFF0u;
    }

label_8004AD8C:
    ctx->pc = 0x8004AD8Cu;
    // 8004AD8C: add   r30, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[30] = res;
    }

label_8004AD90:
    ctx->pc = 0x8004AD90u;
    // 8004AD90: stw     r28, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_8004AD94:
    ctx->pc = 0x8004AD94u;
    // 8004AD94: stw     r27, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[27]);
    }

label_8004AD98:
    ctx->pc = 0x8004AD98u;
    // 8004AD98: rlwinm r0, r26, 0, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[26], 0u) & 0x0000FFFFu;
    }

label_8004AD9C:
    ctx->pc = 0x8004AD9Cu;
    // 8004AD9C: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_8004ADA0:
    ctx->pc = 0x8004ADA0u;
    // 8004ADA0: stb     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004ADA4:
    ctx->pc = 0x8004ADA4u;
    // 8004ADA4: lwz     r3, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004ADA8:
    ctx->pc = 0x8004ADA8u;
    // 8004ADA8: addi    r3, r3, 8
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(8);

label_8004ADAC:
    ctx->pc = 0x8004ADACu;
    // 8004ADAC: lwz     r4, 12(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(12);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004ADB0:
    ctx->pc = 0x8004ADB0u;
    // 8004ADB0: bl      0x80021838
    {
            ctx->lr = 0x8004ADB4u;
            ctx->pc = 0x80021838u;
            return;
    }

label_8004ADB4:
    ctx->pc = 0x8004ADB4u;
    ctx->downcount -= 1;
    // 8004ADB4: bl      0x80286924
    {
            ctx->lr = 0x8004ADB8u;
            ctx->pc = 0x80286924u;
            return;
    }

label_8004ADB8:
    ctx->pc = 0x8004ADB8u;
    ctx->downcount -= 1;
    // 8004ADB8: stw     r3, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8004ADBC:
    ctx->pc = 0x8004ADBCu;
    ctx->downcount -= 21;
    // 8004ADBC: lwz     r5, 4(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8004ADC0:
    ctx->pc = 0x8004ADC0u;
    // 8004ADC0: rlwinm r4, r24, 0, 16, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[24], 0u) & 0x0000FFFFu;
    }

label_8004ADC4:
    ctx->pc = 0x8004ADC4u;
    // 8004ADC4: lha     r3, 34(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(34);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8004ADC8:
    ctx->pc = 0x8004ADC8u;
    // 8004ADC8: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8004ADCC:
    ctx->pc = 0x8004ADCCu;
    // 8004ADCC: sth     r0, 34(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(34);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8004ADD0:
    ctx->pc = 0x8004ADD0u;
    // 8004ADD0: extsh r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_8004ADD4:
    ctx->pc = 0x8004ADD4u;
    // 8004ADD4: rlwinm r0, r0, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 3u) & 0xFFFFFFF8u;
    }

label_8004ADD8:
    ctx->pc = 0x8004ADD8u;
    // 8004ADD8: add   r3, r5, r0
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8004ADDC:
    ctx->pc = 0x8004ADDCu;
    // 8004ADDC: sth     r4, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_8004ADE0:
    ctx->pc = 0x8004ADE0u;
    // 8004ADE0: li      r3, -2
    ctx->gpr[3] = (u32)(s32)(-2);

label_8004ADE4:
    ctx->pc = 0x8004ADE4u;
    // 8004ADE4: lha     r0, 34(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(34);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8004ADE8:
    ctx->pc = 0x8004ADE8u;
    // 8004ADE8: rlwinm r0, r0, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 3u) & 0xFFFFFFF8u;
    }

label_8004ADEC:
    ctx->pc = 0x8004ADECu;
    // 8004ADEC: stwx    r3, r5, r0
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8004ADF0:
    ctx->pc = 0x8004ADF0u;
    // 8004ADF0: lha     r8, 34(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(34);
        ctx->gpr[8] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8004ADF4:
    ctx->pc = 0x8004ADF4u;
    // 8004ADF4: rlwinm r0, r8, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[8], 3u) & 0xFFFFFFF8u;
    }

label_8004ADF8:
    ctx->pc = 0x8004ADF8u;
    // 8004ADF8: lwzx    r7, r5, r0
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[0];
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8004ADFC:
    ctx->pc = 0x8004ADFCu;
    // 8004ADFC: add   r3, r5, r0
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8004AE00:
    ctx->pc = 0x8004AE00u;
    // 8004AE00: lhz     r6, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_8004AE04:
    ctx->pc = 0x8004AE04u;
    // 8004AE04: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_8004AE08:
    ctx->pc = 0x8004AE08u;
    // 8004AE08: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004AE0C:
    ctx->pc = 0x8004AE0Cu;
    // 8004AE0C: b       0x8004AE34
    {
            goto label_8004AE34;
    }

label_8004AE10:
    loop_8004AE10(ctx);
    if (ctx->pc == 0x8004AE48u) goto label_8004AE48;
    return;
label_8004AE14:
    // 8004AE14: add   r9, r5, r0
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_8004AE18:
    ctx->pc = 0x8004AE18u;
    // 8004AE18: lhz     r3, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_8004AE1C:
    // 8004AE1C: rlwinm r0, r8, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[8], 3u) & 0xFFFFFFF8u;
    }

label_8004AE20:
    // 8004AE20: add   r8, r5, r0
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_8004AE24:
    ctx->pc = 0x8004AE24u;
    // 8004AE24: sth     r3, 4(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_8004AE28:
    ctx->pc = 0x8004AE28u;
    // 8004AE28: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AE2C:
    ctx->pc = 0x8004AE2Cu;
    // 8004AE2C: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004AE30:
    // 8004AE30: or   r8, r4, r4
    {
        ctx->gpr[8] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8004AE34:
    ctx->downcount -= 5;
    // 8004AE34: srawi r4, r8, 1
    {
        u32 sh = 1u;
        u32 value = ctx->gpr[8];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[4] = value;
        } else if (sh > 31) {
            ctx->gpr[4] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[4] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_8004AE38:
    // 8004AE38: rlwinm r0, r4, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 3u) & 0xFFFFFFF8u;
    }

label_8004AE3C:
    ctx->pc = 0x8004AE3Cu;
    // 8004AE3C: lwzx    r0, r5, r0
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AE40:
    // 8004AE40: cmplw   r0, r7
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[7]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004AE44:
    // 8004AE44: bc    12, 0, 0x8004AE10
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004AE10u;
                return;
            }
            goto label_8004AE10;
        }
    }

label_8004AE48:
    ctx->pc = 0x8004AE48u;
    ctx->downcount -= 4;
    // 8004AE48: rlwinm r0, r8, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[8], 3u) & 0xFFFFFFF8u;
    }

label_8004AE4C:
    ctx->pc = 0x8004AE4Cu;
    // 8004AE4C: stwx    r7, r5, r0
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8004AE50:
    ctx->pc = 0x8004AE50u;
    // 8004AE50: add   r3, r5, r0
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8004AE54:
    ctx->pc = 0x8004AE54u;
    // 8004AE54: sth     r6, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_8004AE58:
    ctx->pc = 0x8004AE58u;
    ctx->downcount -= 7;
    // 8004AE58: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004AE5C:
    ctx->pc = 0x8004AE5Cu;
    // 8004AE5C: or   r4, r5, r5
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8004AE60:
    ctx->pc = 0x8004AE60u;
    // 8004AE60: lha     r30, 32(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(32);
        ctx->gpr[30] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8004AE64:
    ctx->pc = 0x8004AE64u;
    // 8004AE64: mtctr    r30
    ctx->ctr = ctx->gpr[30];

label_8004AE68:
    ctx->pc = 0x8004AE68u;
    // 8004AE68: cmpwi   r30, 0
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004AE6C:
    ctx->pc = 0x8004AE6Cu;
    // 8004AE6C: bc    4, 1, 0x8004AE98
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004AE98;
        }
    }

label_8004AE70:
    ctx->pc = 0x8004AE70u;
    ctx->downcount -= 5;
    // 8004AE70: lwz     r0, 0(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AE74:
    // 8004AE74: add   r3, r0, r4
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8004AE78:
    ctx->pc = 0x8004AE78u;
    // 8004AE78: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AE7C:
    // 8004AE7C: cmplw   r0, r28
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[28]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004AE80:
    // 8004AE80: bc    4, 2, 0x8004AE8C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004AE8C;
        }
    }

label_8004AE84:
    ctx->pc = 0x8004AE84u;
    ctx->downcount -= 2;
    // 8004AE84: lbz     r29, 14(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(14);
        ctx->gpr[29] = mem_read8(ctx, ea);
    }

label_8004AE88:
    // 8004AE88: b       0x8004AE9C
    {
            goto label_8004AE9C;
    }

label_8004AE8C:
    ctx->downcount -= 3;
    // 8004AE8C: addi    r4, r4, 16
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(16);

label_8004AE90:
    // 8004AE90: addi    r5, r5, 1
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(1);

label_8004AE94:
    // 8004AE94: bc    16, 0, 0x8004AE70
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004AE70u;
                return;
            }
            goto label_8004AE70;
        }
    }

label_8004AE98:
    ctx->pc = 0x8004AE98u;
    ctx->downcount -= 1;
    // 8004AE98: li      r5, -1
    ctx->gpr[5] = (u32)(s32)(-1);

label_8004AE9C:
    ctx->pc = 0x8004AE9Cu;
    ctx->downcount -= 2;
    // 8004AE9C: cmpwi   r5, 0
    {
        s32 val_a = (s32)(ctx->gpr[5]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004AEA0:
    ctx->pc = 0x8004AEA0u;
    // 8004AEA0: bc    12, 0, 0x8004AFA0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004AFA0;
        }
    }

label_8004AEA4:
    ctx->pc = 0x8004AEA4u;
    ctx->downcount -= 2;
    // 8004AEA4: cmpwi   r29, 0
    {
        s32 val_a = (s32)(ctx->gpr[29]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004AEA8:
    ctx->pc = 0x8004AEA8u;
    // 8004AEA8: bc    4, 2, 0x8004AFA0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004AFA0;
        }
    }

label_8004AEAC:
    ctx->pc = 0x8004AEACu;
    ctx->downcount -= 6;
    // 8004AEAC: lwz     r3, 0(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004AEB0:
    ctx->pc = 0x8004AEB0u;
    // 8004AEB0: rlwinm r0, r5, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 4u) & 0xFFFFFFF0u;
    }

label_8004AEB4:
    ctx->pc = 0x8004AEB4u;
    // 8004AEB4: add   r4, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_8004AEB8:
    ctx->pc = 0x8004AEB8u;
    // 8004AEB8: lwz     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AEBC:
    ctx->pc = 0x8004AEBCu;
    // 8004AEBC: cmplw   r27, r0
    {
        u32 val_a = (u32)(ctx->gpr[27]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004AEC0:
    ctx->pc = 0x8004AEC0u;
    // 8004AEC0: bc    4, 0, 0x8004B16C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004B16C;
        }
    }

label_8004AEC4:
    ctx->pc = 0x8004AEC4u;
    ctx->downcount -= 11;
    // 8004AEC4: rlwinm r0, r26, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[26], 0u) & 0x000000FFu;
    }

label_8004AEC8:
    ctx->pc = 0x8004AEC8u;
    // 8004AEC8: stb     r0, 12(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004AECC:
    ctx->pc = 0x8004AECCu;
    // 8004AECC: stw     r27, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[27]);
    }

label_8004AED0:
    ctx->pc = 0x8004AED0u;
    // 8004AED0: lwz     r3, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004AED4:
    ctx->pc = 0x8004AED4u;
    // 8004AED4: lwz     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AED8:
    ctx->pc = 0x8004AED8u;
    // 8004AED8: add   r8, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_8004AEDC:
    ctx->pc = 0x8004AEDCu;
    // 8004AEDC: lha     r4, 34(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(34);
        ctx->gpr[4] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8004AEE0:
    ctx->pc = 0x8004AEE0u;
    // 8004AEE0: lwz     r3, 4(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004AEE4:
    ctx->pc = 0x8004AEE4u;
    // 8004AEE4: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004AEE8:
    ctx->pc = 0x8004AEE8u;
    // 8004AEE8: rlwinm r6, r5, 0, 16, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x0000FFFFu;
    }

label_8004AEEC:
    ctx->pc = 0x8004AEECu;
    // 8004AEEC: b       0x8004AF10
    {
            goto label_8004AF10;
    }

label_8004AEF0:
    ctx->downcount -= 5;
    // 8004AEF0: rlwinm r5, r7, 3, 0, 28
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[7], 3u) & 0xFFFFFFF8u;
    }

label_8004AEF4:
    // 8004AEF4: addi    r0, r5, 4
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(4);

label_8004AEF8:
    ctx->pc = 0x8004AEF8u;
    // 8004AEF8: lhzx    r0, r3, r0
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[0];
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8004AEFC:
    // 8004AEFC: cmplw   r6, r0
    {
        u32 val_a = (u32)(ctx->gpr[6]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004AF00:
    // 8004AF00: bc    4, 2, 0x8004AF0C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004AF0C;
        }
    }

label_8004AF04:
    ctx->downcount -= 2;
    // 8004AF04: or   r31, r7, r7
    {
        ctx->gpr[31] = ctx->gpr[7] | ctx->gpr[7];
    }

label_8004AF08:
    // 8004AF08: addi    r7, r4, 1
    ctx->gpr[7] = ctx->gpr[4] + (u32)(s32)(1);

label_8004AF0C:
    ctx->downcount -= 1;
    // 8004AF0C: addi    r7, r7, 1
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(1);

label_8004AF10:
    ctx->downcount -= 2;
    // 8004AF10: cmpw    r7, r4
    {
        s32 val_a = (s32)(ctx->gpr[7]);
        s32 val_b = (s32)(ctx->gpr[4]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004AF14:
    // 8004AF14: bc    4, 1, 0x8004AEF0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004AEF0u;
                return;
            }
            goto label_8004AEF0;
        }
    }

label_8004AF18:
    ctx->pc = 0x8004AF18u;
    ctx->downcount -= 6;
    // 8004AF18: rlwinm r0, r31, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[31], 3u) & 0xFFFFFFF8u;
    }

label_8004AF1C:
    ctx->pc = 0x8004AF1Cu;
    // 8004AF1C: add   r5, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[5] = res;
    }

label_8004AF20:
    ctx->pc = 0x8004AF20u;
    // 8004AF20: lwz     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AF24:
    ctx->pc = 0x8004AF24u;
    // 8004AF24: stw     r8, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8004AF28:
    ctx->pc = 0x8004AF28u;
    // 8004AF28: cmplw   r8, r0
    {
        u32 val_a = (u32)(ctx->gpr[8]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004AF2C:
    ctx->pc = 0x8004AF2Cu;
    // 8004AF2C: bc    4, 0, 0x8004AF3C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004AF3C;
        }
    }

label_8004AF30:
    ctx->pc = 0x8004AF30u;
    ctx->downcount -= 2;
    // 8004AF30: or   r5, r31, r31
    {
        ctx->gpr[5] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8004AF34:
    ctx->pc = 0x8004AF34u;
    // 8004AF34: bl      0x8004ACB8
    {
            ctx->lr = 0x8004AF38u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004ACB8u;
                return;
            }
            goto label_8004ACB8;
    }

label_8004AF38:
    ctx->pc = 0x8004AF38u;
    ctx->downcount -= 1;
    // 8004AF38: b       0x8004B16C
    {
            goto label_8004B16C;
    }

label_8004AF3C:
    ctx->pc = 0x8004AF3Cu;
    ctx->downcount -= 1;
    // 8004AF3C: bc    4, 1, 0x8004B16C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004B16C;
        }
    }

label_8004AF40:
    ctx->pc = 0x8004AF40u;
    ctx->downcount -= 5;
    // 8004AF40: lwz     r7, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8004AF44:
    ctx->pc = 0x8004AF44u;
    // 8004AF44: lhz     r6, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_8004AF48:
    ctx->pc = 0x8004AF48u;
    // 8004AF48: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_8004AF4C:
    ctx->pc = 0x8004AF4Cu;
    // 8004AF4C: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004AF50:
    ctx->pc = 0x8004AF50u;
    // 8004AF50: b       0x8004AF78
    {
            goto label_8004AF78;
    }

label_8004AF54:
    loop_8004AF54(ctx);
    if (ctx->pc == 0x8004AF8Cu) goto label_8004AF8C;
    return;
label_8004AF58:
    // 8004AF58: add   r8, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_8004AF5C:
    ctx->pc = 0x8004AF5Cu;
    // 8004AF5C: lhz     r4, 4(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(4);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_8004AF60:
    // 8004AF60: rlwinm r0, r31, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[31], 3u) & 0xFFFFFFF8u;
    }

label_8004AF64:
    // 8004AF64: add   r9, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_8004AF68:
    ctx->pc = 0x8004AF68u;
    // 8004AF68: sth     r4, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_8004AF6C:
    ctx->pc = 0x8004AF6Cu;
    // 8004AF6C: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AF70:
    ctx->pc = 0x8004AF70u;
    // 8004AF70: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004AF74:
    // 8004AF74: or   r31, r5, r5
    {
        ctx->gpr[31] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8004AF78:
    ctx->downcount -= 5;
    // 8004AF78: srawi r5, r31, 1
    {
        u32 sh = 1u;
        u32 value = ctx->gpr[31];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[5] = value;
        } else if (sh > 31) {
            ctx->gpr[5] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[5] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_8004AF7C:
    // 8004AF7C: rlwinm r0, r5, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 3u) & 0xFFFFFFF8u;
    }

label_8004AF80:
    ctx->pc = 0x8004AF80u;
    // 8004AF80: lwzx    r0, r3, r0
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004AF84:
    // 8004AF84: cmplw   r0, r7
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[7]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004AF88:
    // 8004AF88: bc    12, 0, 0x8004AF54
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004AF54u;
                return;
            }
            goto label_8004AF54;
        }
    }

label_8004AF8C:
    ctx->pc = 0x8004AF8Cu;
    ctx->downcount -= 5;
    // 8004AF8C: rlwinm r0, r31, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[31], 3u) & 0xFFFFFFF8u;
    }

label_8004AF90:
    ctx->pc = 0x8004AF90u;
    // 8004AF90: stwx    r7, r3, r0
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8004AF94:
    ctx->pc = 0x8004AF94u;
    // 8004AF94: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8004AF98:
    ctx->pc = 0x8004AF98u;
    // 8004AF98: sth     r6, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_8004AF9C:
    ctx->pc = 0x8004AF9Cu;
    // 8004AF9C: b       0x8004B16C
    {
            goto label_8004B16C;
    }

label_8004AFA0:
    ctx->pc = 0x8004AFA0u;
    ctx->downcount -= 2;
    // 8004AFA0: cmpwi   r5, 0
    {
        s32 val_a = (s32)(ctx->gpr[5]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004AFA4:
    ctx->pc = 0x8004AFA4u;
    // 8004AFA4: bc    4, 0, 0x8004B16C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004B16C;
        }
    }

label_8004AFA8:
    ctx->pc = 0x8004AFA8u;
    ctx->downcount -= 2;
    // 8004AFA8: cmpwi   r30, 254
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(254);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004AFAC:
    ctx->pc = 0x8004AFACu;
    // 8004AFAC: bc    4, 2, 0x8004AFB8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004AFB8;
        }
    }

label_8004AFB0:
    ctx->pc = 0x8004AFB0u;
    ctx->downcount -= 2;
    // 8004AFB0: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_8004AFB4:
    ctx->pc = 0x8004AFB4u;
    // 8004AFB4: b       0x8004AFFC
    {
            goto label_8004AFFC;
    }

label_8004AFB8:
    ctx->pc = 0x8004AFB8u;
    ctx->downcount -= 15;
    // 8004AFB8: lwz     r4, 0(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004AFBC:
    ctx->pc = 0x8004AFBCu;
    // 8004AFBC: lha     r3, 32(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(32);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8004AFC0:
    ctx->pc = 0x8004AFC0u;
    // 8004AFC0: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8004AFC4:
    ctx->pc = 0x8004AFC4u;
    // 8004AFC4: sth     r0, 32(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(32);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8004AFC8:
    ctx->pc = 0x8004AFC8u;
    // 8004AFC8: rlwinm r0, r3, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 4u) & 0xFFFFFFF0u;
    }

label_8004AFCC:
    ctx->pc = 0x8004AFCCu;
    // 8004AFCC: add   r29, r4, r0
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[29] = res;
    }

label_8004AFD0:
    ctx->pc = 0x8004AFD0u;
    // 8004AFD0: stw     r28, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_8004AFD4:
    ctx->pc = 0x8004AFD4u;
    // 8004AFD4: stw     r27, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[27]);
    }

label_8004AFD8:
    ctx->pc = 0x8004AFD8u;
    // 8004AFD8: rlwinm r0, r26, 0, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[26], 0u) & 0x0000FFFFu;
    }

label_8004AFDC:
    ctx->pc = 0x8004AFDCu;
    // 8004AFDC: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_8004AFE0:
    ctx->pc = 0x8004AFE0u;
    // 8004AFE0: stb     r0, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004AFE4:
    ctx->pc = 0x8004AFE4u;
    // 8004AFE4: lwz     r3, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004AFE8:
    ctx->pc = 0x8004AFE8u;
    // 8004AFE8: addi    r3, r3, 8
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(8);

label_8004AFEC:
    ctx->pc = 0x8004AFECu;
    // 8004AFEC: lwz     r4, 12(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(12);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004AFF0:
    ctx->pc = 0x8004AFF0u;
    // 8004AFF0: bl      0x80021838
    {
            ctx->lr = 0x8004AFF4u;
            ctx->pc = 0x80021838u;
            return;
    }

label_8004AFF4:
    ctx->pc = 0x8004AFF4u;
    ctx->downcount -= 1;
    // 8004AFF4: bl      0x80286924
    {
            ctx->lr = 0x8004AFF8u;
            ctx->pc = 0x80286924u;
            return;
    }

label_8004AFF8:
    ctx->pc = 0x8004AFF8u;
    ctx->downcount -= 1;
    // 8004AFF8: stw     r3, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8004AFFC:
    ctx->pc = 0x8004AFFCu;
    ctx->downcount -= 2;
    // 8004AFFC: cmplwi  r29, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[29]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004B000:
    ctx->pc = 0x8004B000u;
    // 8004B000: bc    12, 2, 0x8004B16C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004B16C;
        }
    }

label_8004B004:
    ctx->pc = 0x8004B004u;
    ctx->downcount -= 4;
    // 8004B004: lwz     r3, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004B008:
    ctx->pc = 0x8004B008u;
    // 8004B008: lwz     r0, 36(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004B00C:
    ctx->pc = 0x8004B00Cu;
    // 8004B00C: cmplw   r3, r0
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004B010:
    ctx->pc = 0x8004B010u;
    // 8004B010: bc    4, 1, 0x8004B0BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004B0BC;
        }
    }

label_8004B014:
    ctx->pc = 0x8004B014u;
    ctx->downcount -= 23;
    // 8004B014: lwz     r0, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004B018:
    ctx->pc = 0x8004B018u;
    // 8004B018: add   r6, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_8004B01C:
    ctx->pc = 0x8004B01Cu;
    // 8004B01C: lwz     r5, 4(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8004B020:
    ctx->pc = 0x8004B020u;
    // 8004B020: rlwinm r4, r30, 0, 16, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[30], 0u) & 0x0000FFFFu;
    }

label_8004B024:
    ctx->pc = 0x8004B024u;
    // 8004B024: lha     r3, 34(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(34);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8004B028:
    ctx->pc = 0x8004B028u;
    // 8004B028: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8004B02C:
    ctx->pc = 0x8004B02Cu;
    // 8004B02C: sth     r0, 34(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(34);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8004B030:
    ctx->pc = 0x8004B030u;
    // 8004B030: extsh r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_8004B034:
    ctx->pc = 0x8004B034u;
    // 8004B034: rlwinm r0, r0, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 3u) & 0xFFFFFFF8u;
    }

label_8004B038:
    ctx->pc = 0x8004B038u;
    // 8004B038: add   r3, r5, r0
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8004B03C:
    ctx->pc = 0x8004B03Cu;
    // 8004B03C: sth     r4, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_8004B040:
    ctx->pc = 0x8004B040u;
    // 8004B040: subfic  r3, r6, -1
    {
        u64 res = (u64)(u32)(s32)(-1) + (u64)(~ctx->gpr[6]) + 1u;
        ctx->gpr[3] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8004B044:
    ctx->pc = 0x8004B044u;
    // 8004B044: lha     r0, 34(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(34);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8004B048:
    ctx->pc = 0x8004B048u;
    // 8004B048: rlwinm r0, r0, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 3u) & 0xFFFFFFF8u;
    }

label_8004B04C:
    ctx->pc = 0x8004B04Cu;
    // 8004B04C: stwx    r3, r5, r0
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8004B050:
    ctx->pc = 0x8004B050u;
    // 8004B050: lha     r8, 34(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(34);
        ctx->gpr[8] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8004B054:
    ctx->pc = 0x8004B054u;
    // 8004B054: rlwinm r0, r8, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[8], 3u) & 0xFFFFFFF8u;
    }

label_8004B058:
    ctx->pc = 0x8004B058u;
    // 8004B058: lwzx    r7, r5, r0
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[0];
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8004B05C:
    ctx->pc = 0x8004B05Cu;
    // 8004B05C: add   r3, r5, r0
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8004B060:
    ctx->pc = 0x8004B060u;
    // 8004B060: lhz     r6, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_8004B064:
    ctx->pc = 0x8004B064u;
    // 8004B064: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_8004B068:
    ctx->pc = 0x8004B068u;
    // 8004B068: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B06C:
    ctx->pc = 0x8004B06Cu;
    // 8004B06C: b       0x8004B094
    {
            goto label_8004B094;
    }

label_8004B070:
    loop_8004B070(ctx);
    if (ctx->pc == 0x8004B0A8u) goto label_8004B0A8;
    return;
label_8004B074:
    // 8004B074: add   r9, r5, r0
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_8004B078:
    ctx->pc = 0x8004B078u;
    // 8004B078: lhz     r3, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_8004B07C:
    // 8004B07C: rlwinm r0, r8, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[8], 3u) & 0xFFFFFFF8u;
    }

label_8004B080:
    // 8004B080: add   r8, r5, r0
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_8004B084:
    ctx->pc = 0x8004B084u;
    // 8004B084: sth     r3, 4(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_8004B088:
    ctx->pc = 0x8004B088u;
    // 8004B088: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004B08C:
    ctx->pc = 0x8004B08Cu;
    // 8004B08C: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B090:
    // 8004B090: or   r8, r4, r4
    {
        ctx->gpr[8] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8004B094:
    ctx->downcount -= 5;
    // 8004B094: srawi r4, r8, 1
    {
        u32 sh = 1u;
        u32 value = ctx->gpr[8];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[4] = value;
        } else if (sh > 31) {
            ctx->gpr[4] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[4] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_8004B098:
    // 8004B098: rlwinm r0, r4, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 3u) & 0xFFFFFFF8u;
    }

label_8004B09C:
    ctx->pc = 0x8004B09Cu;
    // 8004B09C: lwzx    r0, r5, r0
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004B0A0:
    // 8004B0A0: cmplw   r0, r7
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[7]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004B0A4:
    // 8004B0A4: bc    12, 0, 0x8004B070
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004B070u;
                return;
            }
            goto label_8004B070;
        }
    }

label_8004B0A8:
    ctx->pc = 0x8004B0A8u;
    ctx->downcount -= 5;
    // 8004B0A8: rlwinm r0, r8, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[8], 3u) & 0xFFFFFFF8u;
    }

label_8004B0AC:
    ctx->pc = 0x8004B0ACu;
    // 8004B0AC: stwx    r7, r5, r0
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8004B0B0:
    ctx->pc = 0x8004B0B0u;
    // 8004B0B0: add   r3, r5, r0
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8004B0B4:
    ctx->pc = 0x8004B0B4u;
    // 8004B0B4: sth     r6, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_8004B0B8:
    ctx->pc = 0x8004B0B8u;
    // 8004B0B8: b       0x8004B16C
    {
            goto label_8004B16C;
    }

label_8004B0BC:
    ctx->pc = 0x8004B0BCu;
    ctx->downcount -= 1;
    // 8004B0BC: bc    4, 0, 0x8004B0C4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004B0C4;
        }
    }

label_8004B0C0:
    ctx->pc = 0x8004B0C0u;
    ctx->downcount -= 1;
    // 8004B0C0: stw     r3, 36(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8004B0C4:
    ctx->pc = 0x8004B0C4u;
    ctx->downcount -= 24;
    // 8004B0C4: lwz     r3, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004B0C8:
    ctx->pc = 0x8004B0C8u;
    // 8004B0C8: lwz     r0, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004B0CC:
    ctx->pc = 0x8004B0CCu;
    // 8004B0CC: add   r6, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_8004B0D0:
    ctx->pc = 0x8004B0D0u;
    // 8004B0D0: lwz     r5, 4(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8004B0D4:
    ctx->pc = 0x8004B0D4u;
    // 8004B0D4: rlwinm r4, r30, 0, 16, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[30], 0u) & 0x0000FFFFu;
    }

label_8004B0D8:
    ctx->pc = 0x8004B0D8u;
    // 8004B0D8: lha     r3, 34(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(34);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8004B0DC:
    ctx->pc = 0x8004B0DCu;
    // 8004B0DC: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8004B0E0:
    ctx->pc = 0x8004B0E0u;
    // 8004B0E0: sth     r0, 34(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(34);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8004B0E4:
    ctx->pc = 0x8004B0E4u;
    // 8004B0E4: extsh r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_8004B0E8:
    ctx->pc = 0x8004B0E8u;
    // 8004B0E8: rlwinm r0, r0, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 3u) & 0xFFFFFFF8u;
    }

label_8004B0EC:
    ctx->pc = 0x8004B0ECu;
    // 8004B0EC: add   r3, r5, r0
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8004B0F0:
    ctx->pc = 0x8004B0F0u;
    // 8004B0F0: sth     r4, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_8004B0F4:
    ctx->pc = 0x8004B0F4u;
    // 8004B0F4: subfic  r3, r6, -1
    {
        u64 res = (u64)(u32)(s32)(-1) + (u64)(~ctx->gpr[6]) + 1u;
        ctx->gpr[3] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8004B0F8:
    ctx->pc = 0x8004B0F8u;
    // 8004B0F8: lha     r0, 34(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(34);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8004B0FC:
    ctx->pc = 0x8004B0FCu;
    // 8004B0FC: rlwinm r0, r0, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 3u) & 0xFFFFFFF8u;
    }

label_8004B100:
    ctx->pc = 0x8004B100u;
    // 8004B100: stwx    r3, r5, r0
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8004B104:
    ctx->pc = 0x8004B104u;
    // 8004B104: lha     r8, 34(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(34);
        ctx->gpr[8] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8004B108:
    ctx->pc = 0x8004B108u;
    // 8004B108: rlwinm r0, r8, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[8], 3u) & 0xFFFFFFF8u;
    }

label_8004B10C:
    ctx->pc = 0x8004B10Cu;
    // 8004B10C: lwzx    r7, r5, r0
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[0];
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8004B110:
    ctx->pc = 0x8004B110u;
    // 8004B110: add   r3, r5, r0
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8004B114:
    ctx->pc = 0x8004B114u;
    // 8004B114: lhz     r6, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_8004B118:
    ctx->pc = 0x8004B118u;
    // 8004B118: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_8004B11C:
    ctx->pc = 0x8004B11Cu;
    // 8004B11C: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B120:
    ctx->pc = 0x8004B120u;
    // 8004B120: b       0x8004B148
    {
            goto label_8004B148;
    }

label_8004B124:
    loop_8004B124(ctx);
    if (ctx->pc == 0x8004B15Cu) goto label_8004B15C;
    return;
label_8004B128:
    // 8004B128: add   r9, r5, r0
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_8004B12C:
    ctx->pc = 0x8004B12Cu;
    // 8004B12C: lhz     r3, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_8004B130:
    // 8004B130: rlwinm r0, r8, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[8], 3u) & 0xFFFFFFF8u;
    }

label_8004B134:
    // 8004B134: add   r8, r5, r0
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_8004B138:
    ctx->pc = 0x8004B138u;
    // 8004B138: sth     r3, 4(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_8004B13C:
    ctx->pc = 0x8004B13Cu;
    // 8004B13C: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004B140:
    ctx->pc = 0x8004B140u;
    // 8004B140: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B144:
    // 8004B144: or   r8, r4, r4
    {
        ctx->gpr[8] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8004B148:
    ctx->downcount -= 5;
    // 8004B148: srawi r4, r8, 1
    {
        u32 sh = 1u;
        u32 value = ctx->gpr[8];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[4] = value;
        } else if (sh > 31) {
            ctx->gpr[4] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[4] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_8004B14C:
    // 8004B14C: rlwinm r0, r4, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 3u) & 0xFFFFFFF8u;
    }

label_8004B150:
    ctx->pc = 0x8004B150u;
    // 8004B150: lwzx    r0, r5, r0
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004B154:
    // 8004B154: cmplw   r0, r7
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[7]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004B158:
    // 8004B158: bc    12, 0, 0x8004B124
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004B124u;
                return;
            }
            goto label_8004B124;
        }
    }

label_8004B15C:
    ctx->pc = 0x8004B15Cu;
    ctx->downcount -= 4;
    // 8004B15C: rlwinm r0, r8, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[8], 3u) & 0xFFFFFFF8u;
    }

label_8004B160:
    ctx->pc = 0x8004B160u;
    // 8004B160: stwx    r7, r5, r0
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8004B164:
    ctx->pc = 0x8004B164u;
    // 8004B164: add   r3, r5, r0
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8004B168:
    ctx->pc = 0x8004B168u;
    // 8004B168: sth     r6, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_8004B16C:
    ctx->pc = 0x8004B16Cu;
    ctx->downcount -= 2;
    // 8004B16C: addi    r11, r1, 48
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(48);

label_8004B170:
    ctx->pc = 0x8004B170u;
    // 8004B170: bl      0x80286A8C
    {
            ctx->lr = 0x8004B174u;
            ctx->pc = 0x80286A8Cu;
            return;
    }

label_8004B174:
    ctx->pc = 0x8004B174u;
    ctx->downcount -= 5;
    // 8004B174: lwz     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004B178:
    ctx->pc = 0x8004B178u;
    // 8004B178: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004B17C:
    ctx->pc = 0x8004B17Cu;
    // 8004B17C: addi    r1, r1, 48
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(48);

label_8004B180:
    ctx->pc = 0x8004B180u;
    // 8004B180: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004B184:
    ctx->pc = 0x8004B184u;
    ctx->downcount -= 5;
    // 8004B184: stwu     r1, -48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-48);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004B188:
    ctx->pc = 0x8004B188u;
    // 8004B188: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004B18C:
    ctx->pc = 0x8004B18Cu;
    // 8004B18C: stw     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B190:
    ctx->pc = 0x8004B190u;
    // 8004B190: addi    r11, r1, 48
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(48);

label_8004B194:
    ctx->pc = 0x8004B194u;
    // 8004B194: bl      0x80286A40
    {
            ctx->lr = 0x8004B198u;
            ctx->pc = 0x80286A40u;
            return;
    }

label_8004B198:
    ctx->pc = 0x8004B198u;
    ctx->downcount -= 7;
    // 8004B198: or   r24, r3, r3
    {
        ctx->gpr[24] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004B19C:
    ctx->pc = 0x8004B19Cu;
    // 8004B19C: or   r25, r4, r4
    {
        ctx->gpr[25] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8004B1A0:
    ctx->pc = 0x8004B1A0u;
    // 8004B1A0: or   r26, r5, r5
    {
        ctx->gpr[26] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8004B1A4:
    ctx->pc = 0x8004B1A4u;
    // 8004B1A4: lwz     r29, 0(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(0);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_8004B1A8:
    ctx->pc = 0x8004B1A8u;
    // 8004B1A8: lbz     r0, 40(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(40);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8004B1AC:
    ctx->pc = 0x8004B1ACu;
    // 8004B1AC: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004B1B0:
    ctx->pc = 0x8004B1B0u;
    // 8004B1B0: bc    12, 2, 0x8004B1C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004B1C0;
        }
    }

label_8004B1B4:
    ctx->pc = 0x8004B1B4u;
    ctx->downcount -= 3;
    // 8004B1B4: lbz     r0, 27(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(27);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8004B1B8:
    ctx->pc = 0x8004B1B8u;
    // 8004B1B8: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8004B1BC:
    ctx->pc = 0x8004B1BCu;
    // 8004B1BC: b       0x8004B1CC
    {
            goto label_8004B1CC;
    }

label_8004B1C0:
    ctx->pc = 0x8004B1C0u;
    ctx->downcount -= 3;
    // 8004B1C0: lbz     r0, 27(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(27);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8004B1C4:
    ctx->pc = 0x8004B1C4u;
    // 8004B1C4: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8004B1C8:
    ctx->pc = 0x8004B1C8u;
    // 8004B1C8: nor   r0, r0, r0
    {
        ctx->gpr[0] = ~(ctx->gpr[0] | ctx->gpr[0]);
    }

label_8004B1CC:
    ctx->pc = 0x8004B1CCu;
    ctx->downcount -= 3;
    // 8004B1CC: li      r27, 0
    ctx->gpr[27] = (u32)(s32)(0);

label_8004B1D0:
    ctx->pc = 0x8004B1D0u;
    // 8004B1D0: or   r30, r29, r29
    {
        ctx->gpr[30] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8004B1D4:
    ctx->pc = 0x8004B1D4u;
    // 8004B1D4: rlwinm r31, r0, 0, 24, 31
    {
        ctx->gpr[31] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_8004B1D8:
    ctx->pc = 0x8004B1D8u;
    ctx->downcount -= 3;
    // 8004B1D8: lwz     r3, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004B1DC:
    // 8004B1DC: cmpwi   r3, -1
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(-1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004B1E0:
    // 8004B1E0: bc    4, 1, 0x8004B2D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004B2D4;
        }
    }

label_8004B1E4:
    ctx->downcount -= 5;
    // 8004B1E4: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8004B1E8:
    // 8004B1E8: slw   r0, r0, r27
    {
        u32 sh = ctx->gpr[27] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[0] << sh);
    }

label_8004B1EC:
    // 8004B1EC: and   r0, r31, r0
    {
        ctx->gpr[0] = ctx->gpr[31] & ctx->gpr[0];
    }

label_8004B1F0:
    // 8004B1F0: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004B1F4:
    // 8004B1F4: bc    12, 2, 0x8004B2D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004B2D4;
        }
    }

label_8004B1F8:
    ctx->pc = 0x8004B1F8u;
    ctx->downcount -= 6;
    // 8004B1F8: lwz     r4, -26340(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26340);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004B1FC:
    ctx->pc = 0x8004B1FCu;
    // 8004B1FC: lwz     r4, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004B200:
    ctx->pc = 0x8004B200u;
    // 8004B200: lwz     r12, 28(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(28);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_8004B204:
    ctx->pc = 0x8004B204u;
    // 8004B204: mtctr    r12
    ctx->ctr = ctx->gpr[12];

label_8004B208:
    ctx->pc = 0x8004B208u;
    // 8004B208: bctrl
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8004B20Cu;
            ctx->pc = target;
            return;
        }
    }

label_8004B20C:
    ctx->downcount -= 3;
    // 8004B20C: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004B210:
    // 8004B210: cmplwi  r28, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[28]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004B214:
    // 8004B214: bc    12, 2, 0x8004B2D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004B2D4;
        }
    }

label_8004B218:
    ctx->pc = 0x8004B218u;
    ctx->downcount -= 4;
    // 8004B218: lbz     r0, 25(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(25);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8004B21C:
    // 8004B21C: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8004B220:
    // 8004B220: cmpwi   r0, 36
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(36);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004B224:
    // 8004B224: bc    12, 2, 0x8004B22C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004B22C;
        }
    }

label_8004B228:
    ctx->downcount -= 1;
    // 8004B228: b       0x8004B2D0
    {
            goto label_8004B2D0;
    }

label_8004B22C:
    ctx->downcount -= 2;
    // 8004B22C: li      r3, 1250
    ctx->gpr[3] = (u32)(s32)(1250);

label_8004B230:
    // 8004B230: bl      0x800201B4
    {
            ctx->lr = 0x8004B234u;
            ctx->pc = 0x800201B4u;
            return;
    }

label_8004B234:
    ctx->pc = 0x8004B234u;
    ctx->downcount -= 3;
    // 8004B234: lha     r3, 48(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(48);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8004B238:
    // 8004B238: cmpwi   r3, -1
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(-1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004B23C:
    // 8004B23C: bc    12, 2, 0x8004B24C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004B24C;
        }
    }

label_8004B240:
    ctx->downcount -= 1;
    // 8004B240: bl      0x800201B4
    {
            ctx->lr = 0x8004B244u;
            ctx->pc = 0x800201B4u;
            return;
    }

label_8004B244:
    ctx->downcount -= 2;
    // 8004B244: cmplwi  r3, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004B248:
    // 8004B248: bc    12, 2, 0x8004B2D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004B2D4;
        }
    }

label_8004B24C:
    ctx->pc = 0x8004B24Cu;
    ctx->downcount -= 3;
    // 8004B24C: lha     r3, 50(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(50);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8004B250:
    // 8004B250: cmpwi   r3, -1
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(-1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004B254:
    // 8004B254: bc    12, 2, 0x8004B264
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004B264;
        }
    }

label_8004B258:
    ctx->downcount -= 1;
    // 8004B258: bl      0x800201B4
    {
            ctx->lr = 0x8004B25Cu;
            ctx->pc = 0x800201B4u;
            return;
    }

label_8004B25C:
    ctx->downcount -= 2;
    // 8004B25C: cmplwi  r3, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004B260:
    // 8004B260: bc    4, 2, 0x8004B2D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004B2D4;
        }
    }

label_8004B264:
    ctx->pc = 0x8004B264u;
    ctx->downcount -= 4;
    // 8004B264: lbz     r0, 26(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(26);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8004B268:
    // 8004B268: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8004B26C:
    // 8004B26C: cmpwi   r0, 8
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(8);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004B270:
    // 8004B270: bc    4, 2, 0x8004B284
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004B284;
        }
    }

label_8004B274:
    ctx->pc = 0x8004B274u;
    ctx->downcount -= 4;
    // 8004B274: lbz     r0, 26(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(26);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8004B278:
    // 8004B278: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8004B27C:
    // 8004B27C: cmpwi   r0, 9
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(9);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004B280:
    // 8004B280: bc    12, 2, 0x8004B2D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004B2D4;
        }
    }

label_8004B284:
    ctx->downcount -= 3;
    // 8004B284: addi    r3, r29, 8
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(8);

label_8004B288:
    // 8004B288: addi    r4, r28, 8
    ctx->gpr[4] = ctx->gpr[28] + (u32)(s32)(8);

label_8004B28C:
    // 8004B28C: bl      0x80021838
    {
            ctx->lr = 0x8004B290u;
            ctx->pc = 0x80021838u;
            return;
    }

label_8004B290:
    ctx->pc = 0x8004B290u;
    ctx->downcount -= 9;
    // 8004B290: lwz     r0, 8(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004B294:
    ctx->pc = 0x8004B294u;
    // 8004B294: lfd     f2, -31312(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004B294u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31312);
        ctx->fpr[2] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8004B298:
    ctx->pc = 0x8004B298u;
    // 8004B298: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B29C:
    // 8004B29C: lis     r0, 17200
    ctx->gpr[0] = ((u32)(s32)(17200) << 16);

label_8004B2A0:
    ctx->pc = 0x8004B2A0u;
    // 8004B2A0: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B2A4:
    ctx->pc = 0x8004B2A4u;
    // 8004B2A4: lfd     f0, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004B2A4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8004B2A8:
    ctx->pc = 0x8004B2A8u;
    // 8004B2A8: fsubs   f0, f0, f2
    if (!ppc_fp_available_inline(ctx, 0x8004B2A8u)) return;
    ppc_fsubs(ctx, 0, 0, 2);

label_8004B2AC:
    ctx->pc = 0x8004B2ACu;
    // 8004B2AC: fadds   f1, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8004B2ACu)) return;
    ppc_fadds(ctx, 1, 0, 1);

label_8004B2B0:
    // 8004B2B0: bl      0x80286924
    {
            ctx->lr = 0x8004B2B4u;
            ctx->pc = 0x80286924u;
            return;
    }

label_8004B2B4:
    ctx->downcount -= 6;
    // 8004B2B4: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004B2B8:
    // 8004B2B8: or   r3, r24, r24
    {
        ctx->gpr[3] = ctx->gpr[24] | ctx->gpr[24];
    }

label_8004B2BC:
    // 8004B2BC: or   r4, r25, r25
    {
        ctx->gpr[4] = ctx->gpr[25] | ctx->gpr[25];
    }

label_8004B2C0:
    // 8004B2C0: or   r5, r26, r26
    {
        ctx->gpr[5] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8004B2C4:
    // 8004B2C4: or   r7, r28, r28
    {
        ctx->gpr[7] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8004B2C8:
    // 8004B2C8: bl      0x8004AD40
    {
            ctx->lr = 0x8004B2CCu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004AD40u;
                return;
            }
            goto label_8004AD40;
    }

label_8004B2CC:
    ctx->downcount -= 1;
    // 8004B2CC: b       0x8004B2D4
    {
            goto label_8004B2D4;
    }

label_8004B2D0:
    ctx->pc = 0x8004B2D0u;
    ctx->downcount -= 1;
    // 8004B2D0: stw     r28, -25728(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25728);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_8004B2D4:
    ctx->downcount -= 4;
    // 8004B2D4: addi    r30, r30, 4
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(4);

label_8004B2D8:
    // 8004B2D8: addi    r27, r27, 1
    ctx->gpr[27] = ctx->gpr[27] + (u32)(s32)(1);

label_8004B2DC:
    // 8004B2DC: cmpwi   r27, 4
    {
        s32 val_a = (s32)(ctx->gpr[27]);
        s32 val_b = (s32)(4);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004B2E0:
    // 8004B2E0: bc    12, 0, 0x8004B1D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004B1D8u;
                return;
            }
            goto label_8004B1D8;
        }
    }

label_8004B2E4:
    ctx->pc = 0x8004B2E4u;
    ctx->downcount -= 2;
    // 8004B2E4: addi    r11, r1, 48
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(48);

label_8004B2E8:
    ctx->pc = 0x8004B2E8u;
    // 8004B2E8: bl      0x80286A8C
    {
            ctx->lr = 0x8004B2ECu;
            ctx->pc = 0x80286A8Cu;
            return;
    }

label_8004B2EC:
    ctx->pc = 0x8004B2ECu;
    ctx->downcount -= 5;
    // 8004B2EC: lwz     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004B2F0:
    ctx->pc = 0x8004B2F0u;
    // 8004B2F0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004B2F4:
    ctx->pc = 0x8004B2F4u;
    // 8004B2F4: addi    r1, r1, 48
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(48);

label_8004B2F8:
    ctx->pc = 0x8004B2F8u;
    // 8004B2F8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004B2FC:
    ctx->pc = 0x8004B2FCu;
    ctx->downcount -= 4;
    // 8004B2FC: lha     r5, 44(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(44);
        ctx->gpr[5] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8004B300:
    ctx->pc = 0x8004B300u;
    // 8004B300: lha     r0, 42(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(42);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8004B304:
    ctx->pc = 0x8004B304u;
    // 8004B304: cmpw    r5, r0
    {
        s32 val_a = (s32)(ctx->gpr[5]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004B308:
    ctx->pc = 0x8004B308u;
    // 8004B308: bc    4, 0, 0x8004B324
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004B324;
        }
    }

label_8004B30C:
    ctx->pc = 0x8004B30Cu;
    ctx->downcount -= 6;
    // 8004B30C: lwz     r4, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004B310:
    ctx->pc = 0x8004B310u;
    // 8004B310: addi    r0, r5, 1
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(1);

label_8004B314:
    ctx->pc = 0x8004B314u;
    // 8004B314: sth     r0, 44(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(44);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8004B318:
    ctx->pc = 0x8004B318u;
    // 8004B318: rlwinm r0, r5, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 2u) & 0xFFFFFFFCu;
    }

label_8004B31C:
    ctx->pc = 0x8004B31Cu;
    // 8004B31C: lwzx    r3, r4, r0
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[0];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004B320:
    ctx->pc = 0x8004B320u;
    // 8004B320: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004B324:
    ctx->pc = 0x8004B324u;
    ctx->downcount -= 2;
    // 8004B324: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8004B328:
    ctx->pc = 0x8004B328u;
    // 8004B328: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004B32C:
    ctx->pc = 0x8004B32Cu;
    ctx->downcount -= 7;
    // 8004B32C: lwz     r6, 28(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(28);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8004B330:
    ctx->pc = 0x8004B330u;
    // 8004B330: lwz     r4, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004B334:
    ctx->pc = 0x8004B334u;
    // 8004B334: rlwinm r0, r6, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 4u) & 0xFFFFFFF0u;
    }

label_8004B338:
    ctx->pc = 0x8004B338u;
    // 8004B338: add   r4, r4, r0
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_8004B33C:
    ctx->pc = 0x8004B33Cu;
    // 8004B33C: li      r0, 255
    ctx->gpr[0] = (u32)(s32)(255);

label_8004B340:
    ctx->pc = 0x8004B340u;
    // 8004B340: stb     r0, 13(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(13);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004B344:
    ctx->pc = 0x8004B344u;
    // 8004B344: b       0x8004B360
    {
            goto label_8004B360;
    }

label_8004B348:
    loop_8004B348(ctx);
    if (ctx->pc == 0x8004B36Cu) goto label_8004B36C;
    return;
label_8004B34C:
    // 8004B34C: rlwinm r0, r5, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 4u) & 0xFFFFFFF0u;
    }

label_8004B350:
    // 8004B350: add   r4, r4, r0
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_8004B354:
    // 8004B354: rlwinm r0, r6, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x000000FFu;
    }

label_8004B358:
    ctx->pc = 0x8004B358u;
    // 8004B358: stb     r0, 13(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(13);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004B35C:
    // 8004B35C: or   r6, r5, r5
    {
        ctx->gpr[6] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8004B360:
    ctx->pc = 0x8004B360u;
    ctx->downcount -= 3;
    // 8004B360: lbz     r5, 12(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_8004B364:
    // 8004B364: cmplwi  r5, 0x00FF
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(0x00FFu);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004B368:
    // 8004B368: bc    4, 2, 0x8004B348
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004B348u;
                return;
            }
            goto label_8004B348;
        }
    }

label_8004B36C:
    ctx->pc = 0x8004B36Cu;
    ctx->downcount -= 3;
    // 8004B36C: lbz     r0, 13(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(13);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8004B370:
    ctx->pc = 0x8004B370u;
    // 8004B370: cmplwi  r0, 0x00FF
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x00FFu);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004B374:
    ctx->pc = 0x8004B374u;
    // 8004B374: bc    4, 2, 0x8004B380
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004B380;
        }
    }

label_8004B378:
    ctx->pc = 0x8004B378u;
    ctx->downcount -= 2;
    // 8004B378: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004B37C:
    ctx->pc = 0x8004B37Cu;
    // 8004B37C: b       0x8004B38C
    {
            goto label_8004B38C;
    }

label_8004B380:
    ctx->pc = 0x8004B380u;
    ctx->downcount -= 3;
    // 8004B380: lwz     r4, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004B384:
    ctx->pc = 0x8004B384u;
    // 8004B384: rlwinm r0, r0, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 4u) & 0xFFFFFFF0u;
    }

label_8004B388:
    ctx->pc = 0x8004B388u;
    // 8004B388: add   r7, r4, r0
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_8004B38C:
    ctx->pc = 0x8004B38Cu;
    ctx->downcount -= 3;
    // 8004B38C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004B390:
    ctx->pc = 0x8004B390u;
    // 8004B390: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004B394:
    ctx->pc = 0x8004B394u;
    // 8004B394: b       0x8004B3DC
    {
            goto label_8004B3DC;
    }

label_8004B398:
    ctx->pc = 0x8004B398u;
    ctx->downcount -= 7;
    // 8004B398: lwz     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004B39C:
    ctx->pc = 0x8004B39Cu;
    // 8004B39C: lwz     r4, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004B3A0:
    ctx->pc = 0x8004B3A0u;
    // 8004B3A0: stwx    r0, r4, r5
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[5];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B3A4:
    // 8004B3A4: addi    r5, r5, 4
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(4);

label_8004B3A8:
    // 8004B3A8: addi    r6, r6, 1
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(1);

label_8004B3AC:
    // 8004B3AC: cmpwi   r6, 100
    {
        s32 val_a = (s32)(ctx->gpr[6]);
        s32 val_b = (s32)(100);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004B3B0:
    // 8004B3B0: bc    12, 0, 0x8004B3BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004B3BC;
        }
    }

label_8004B3B4:
    ctx->downcount -= 2;
    // 8004B3B4: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004B3B8:
    // 8004B3B8: b       0x8004B3DC
    {
            goto label_8004B3DC;
    }

label_8004B3BC:
    ctx->pc = 0x8004B3BCu;
    ctx->downcount -= 3;
    // 8004B3BC: lbz     r0, 13(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(13);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8004B3C0:
    // 8004B3C0: cmplwi  r0, 0x00FF
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x00FFu);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004B3C4:
    // 8004B3C4: bc    4, 2, 0x8004B3D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004B3D0;
        }
    }

label_8004B3C8:
    ctx->downcount -= 2;
    // 8004B3C8: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004B3CC:
    // 8004B3CC: b       0x8004B3DC
    {
            goto label_8004B3DC;
    }

label_8004B3D0:
    ctx->pc = 0x8004B3D0u;
    ctx->downcount -= 3;
    // 8004B3D0: lwz     r4, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004B3D4:
    // 8004B3D4: rlwinm r0, r0, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 4u) & 0xFFFFFFF0u;
    }

label_8004B3D8:
    // 8004B3D8: add   r7, r4, r0
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_8004B3DC:
    ctx->downcount -= 2;
    // 8004B3DC: cmplwi  r7, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[7]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004B3E0:
    // 8004B3E0: bc    4, 2, 0x8004B398
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004B398u;
                return;
            }
            goto label_8004B398;
        }
    }

label_8004B3E4:
    ctx->pc = 0x8004B3E4u;
    ctx->downcount -= 6;
    // 8004B3E4: extsh r0, r6
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[6];
    }

label_8004B3E8:
    ctx->pc = 0x8004B3E8u;
    // 8004B3E8: sth     r0, 42(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(42);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8004B3EC:
    ctx->pc = 0x8004B3ECu;
    // 8004B3EC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8004B3F0:
    ctx->pc = 0x8004B3F0u;
    // 8004B3F0: sth     r0, 44(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(44);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8004B3F4:
    ctx->pc = 0x8004B3F4u;
    // 8004B3F4: or   r3, r6, r6
    {
        ctx->gpr[3] = ctx->gpr[6] | ctx->gpr[6];
    }

label_8004B3F8:
    ctx->pc = 0x8004B3F8u;
    // 8004B3F8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004B3FC:
    ctx->pc = 0x8004B3FCu;
    ctx->downcount -= 5;
    // 8004B3FC: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004B400:
    ctx->pc = 0x8004B400u;
    // 8004B400: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004B404:
    ctx->pc = 0x8004B404u;
    // 8004B404: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B408:
    ctx->pc = 0x8004B408u;
    // 8004B408: addi    r11, r1, 32
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(32);

label_8004B40C:
    ctx->pc = 0x8004B40Cu;
    // 8004B40C: bl      0x80286A48
    {
            ctx->lr = 0x8004B410u;
            ctx->pc = 0x80286A48u;
            return;
    }

label_8004B410:
    ctx->pc = 0x8004B410u;
    ctx->downcount -= 5;
    // 8004B410: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004B414:
    ctx->pc = 0x8004B414u;
    // 8004B414: or   r31, r4, r4
    {
        ctx->gpr[31] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8004B418:
    ctx->pc = 0x8004B418u;
    // 8004B418: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_8004B41C:
    ctx->pc = 0x8004B41Cu;
    // 8004B41C: li      r27, 0
    ctx->gpr[27] = (u32)(s32)(0);

label_8004B420:
    ctx->pc = 0x8004B420u;
    // 8004B420: b       0x8004B4D4
    {
            goto label_8004B4D4;
    }

label_8004B424:
    ctx->pc = 0x8004B424u;
    ctx->downcount -= 4;
    // 8004B424: lwz     r3, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004B428:
    ctx->pc = 0x8004B428u;
    // 8004B428: lha     r0, 34(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(34);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8004B42C:
    // 8004B42C: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004B430:
    // 8004B430: bc    4, 2, 0x8004B43C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004B43C;
        }
    }

label_8004B434:
    ctx->downcount -= 2;
    // 8004B434: li      r29, -1
    ctx->gpr[29] = (u32)(s32)(-1);

label_8004B438:
    // 8004B438: b       0x8004B474
    {
            goto label_8004B474;
    }

label_8004B43C:
    ctx->pc = 0x8004B43Cu;
    ctx->downcount -= 14;
    // 8004B43C: lhz     r29, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        ctx->gpr[29] = mem_read16(ctx, ea);
    }

label_8004B440:
    // 8004B440: rlwinm r0, r0, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 3u) & 0xFFFFFFF8u;
    }

label_8004B444:
    ctx->pc = 0x8004B444u;
    // 8004B444: lwzx    r0, r3, r0
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004B448:
    ctx->pc = 0x8004B448u;
    // 8004B448: stw     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B44C:
    ctx->pc = 0x8004B44Cu;
    // 8004B44C: lha     r4, 34(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(34);
        ctx->gpr[4] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8004B450:
    // 8004B450: addi    r0, r4, -1
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(-1);

label_8004B454:
    ctx->pc = 0x8004B454u;
    // 8004B454: sth     r0, 34(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(34);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8004B458:
    // 8004B458: rlwinm r4, r4, 3, 0, 28
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 3u) & 0xFFFFFFF8u;
    }

label_8004B45C:
    // 8004B45C: addi    r0, r4, 4
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(4);

label_8004B460:
    ctx->pc = 0x8004B460u;
    // 8004B460: lhzx    r0, r3, r0
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[0];
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8004B464:
    ctx->pc = 0x8004B464u;
    // 8004B464: sth     r0, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8004B468:
    ctx->pc = 0x8004B468u;
    // 8004B468: lha     r4, 34(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(34);
        ctx->gpr[4] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8004B46C:
    // 8004B46C: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_8004B470:
    // 8004B470: bl      0x8004ACB8
    {
            ctx->lr = 0x8004B474u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004ACB8u;
                return;
            }
            goto label_8004ACB8;
    }

label_8004B474:
    ctx->downcount -= 2;
    // 8004B474: cmpwi   r29, 0
    {
        s32 val_a = (s32)(ctx->gpr[29]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004B478:
    // 8004B478: bc    12, 0, 0x8004B4C8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004B4C8;
        }
    }

label_8004B47C:
    ctx->pc = 0x8004B47Cu;
    ctx->downcount -= 7;
    // 8004B47C: lwz     r3, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004B480:
    // 8004B480: rlwinm r0, r29, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[29], 4u) & 0xFFFFFFF0u;
    }

label_8004B484:
    // 8004B484: add   r26, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[26] = res;
    }

label_8004B488:
    ctx->pc = 0x8004B488u;
    // 8004B488: stw     r29, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_8004B48C:
    // 8004B48C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8004B490:
    // 8004B490: or   r4, r26, r26
    {
        ctx->gpr[4] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8004B494:
    // 8004B494: bl      0x8004AC08
    {
            ctx->lr = 0x8004B498u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004AC08u;
                return;
            }
            goto label_8004AC08;
    }

label_8004B498:
    ctx->downcount -= 2;
    // 8004B498: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004B49C:
    // 8004B49C: bc    12, 2, 0x8004B4AC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004B4AC;
        }
    }

label_8004B4A0:
    ctx->downcount -= 3;
    // 8004B4A0: li      r28, 1
    ctx->gpr[28] = (u32)(s32)(1);

label_8004B4A4:
    // 8004B4A4: li      r27, 1
    ctx->gpr[27] = (u32)(s32)(1);

label_8004B4A8:
    // 8004B4A8: b       0x8004B4D0
    {
            goto label_8004B4D0;
    }

label_8004B4AC:
    ctx->downcount -= 6;
    // 8004B4AC: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8004B4B0:
    ctx->pc = 0x8004B4B0u;
    // 8004B4B0: stb     r0, 14(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(14);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004B4B4:
    // 8004B4B4: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8004B4B8:
    // 8004B4B8: or   r4, r26, r26
    {
        ctx->gpr[4] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8004B4BC:
    // 8004B4BC: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8004B4C0:
    // 8004B4C0: bl      0x8004B184
    {
            ctx->lr = 0x8004B4C4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004B184u;
                return;
            }
            goto label_8004B184;
    }

label_8004B4C4:
    ctx->downcount -= 1;
    // 8004B4C4: b       0x8004B4D0
    {
            goto label_8004B4D0;
    }

label_8004B4C8:
    ctx->downcount -= 2;
    // 8004B4C8: li      r28, 1
    ctx->gpr[28] = (u32)(s32)(1);

label_8004B4CC:
    // 8004B4CC: li      r27, -1
    ctx->gpr[27] = (u32)(s32)(-1);

label_8004B4D0:
    ctx->downcount -= 1;
    // 8004B4D0: addi    r31, r31, -1
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(-1);

label_8004B4D4:
    ctx->downcount -= 2;
    // 8004B4D4: cmpwi   r28, 0
    {
        s32 val_a = (s32)(ctx->gpr[28]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004B4D8:
    // 8004B4D8: bc    4, 2, 0x8004B4E4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004B4E4;
        }
    }

label_8004B4DC:
    ctx->downcount -= 2;
    // 8004B4DC: cmpwi   r31, 0
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004B4E0:
    // 8004B4E0: bc    4, 2, 0x8004B424
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004B424u;
                return;
            }
            goto label_8004B424;
        }
    }

label_8004B4E4:
    ctx->pc = 0x8004B4E4u;
    ctx->downcount -= 3;
    // 8004B4E4: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8004B4E8:
    ctx->pc = 0x8004B4E8u;
    // 8004B4E8: addi    r11, r1, 32
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(32);

label_8004B4EC:
    ctx->pc = 0x8004B4ECu;
    // 8004B4EC: bl      0x80286A94
    {
            ctx->lr = 0x8004B4F0u;
            ctx->pc = 0x80286A94u;
            return;
    }

label_8004B4F0:
    ctx->pc = 0x8004B4F0u;
    ctx->downcount -= 5;
    // 8004B4F0: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004B4F4:
    ctx->pc = 0x8004B4F4u;
    // 8004B4F4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004B4F8:
    ctx->pc = 0x8004B4F8u;
    // 8004B4F8: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_8004B4FC:
    ctx->pc = 0x8004B4FCu;
    // 8004B4FC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004B500:
    ctx->pc = 0x8004B500u;
    ctx->downcount -= 14;
    // 8004B500: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004B504:
    ctx->pc = 0x8004B504u;
    // 8004B504: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004B508:
    ctx->pc = 0x8004B508u;
    // 8004B508: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B50C:
    ctx->pc = 0x8004B50Cu;
    // 8004B50C: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8004B510:
    ctx->pc = 0x8004B510u;
    // 8004B510: stw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8004B514:
    ctx->pc = 0x8004B514u;
    // 8004B514: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004B518:
    ctx->pc = 0x8004B518u;
    // 8004B518: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8004B51C:
    ctx->pc = 0x8004B51Cu;
    // 8004B51C: sth     r3, 34(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(34);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_8004B520:
    ctx->pc = 0x8004B520u;
    // 8004B520: sth     r3, 32(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(32);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_8004B524:
    ctx->pc = 0x8004B524u;
    // 8004B524: or   r8, r3, r3
    {
        ctx->gpr[8] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004B528:
    ctx->pc = 0x8004B528u;
    // 8004B528: or   r9, r3, r3
    {
        ctx->gpr[9] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004B52C:
    ctx->pc = 0x8004B52Cu;
    // 8004B52C: li      r0, 31
    ctx->gpr[0] = (u32)(s32)(31);

label_8004B530:
    ctx->pc = 0x8004B530u;
    // 8004B530: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8004B534:
    loop_8004B534(ctx);
    if (ctx->pc == 0x8004B604u) goto label_8004B604;
    return;
label_8004B538:
    ctx->pc = 0x8004B538u;
    // 8004B538: lwz     r10, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8004B53C:
    ctx->pc = 0x8004B53Cu;
    // 8004B53C: stwx    r0, r10, r8
    {
        u32 ea = ctx->gpr[10] + ctx->gpr[8];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B540:
    ctx->pc = 0x8004B540u;
    // 8004B540: lwz     r11, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8004B544:
    // 8004B544: addi    r10, r9, 14
    ctx->gpr[10] = ctx->gpr[9] + (u32)(s32)(14);

label_8004B548:
    ctx->pc = 0x8004B548u;
    // 8004B548: stbx    r0, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004B54C:
    ctx->pc = 0x8004B54Cu;
    // 8004B54C: lwz     r11, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8004B550:
    // 8004B550: addi    r10, r8, 8
    ctx->gpr[10] = ctx->gpr[8] + (u32)(s32)(8);

label_8004B554:
    ctx->pc = 0x8004B554u;
    // 8004B554: stwx    r0, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B558:
    ctx->pc = 0x8004B558u;
    // 8004B558: lwz     r11, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8004B55C:
    // 8004B55C: addi    r10, r9, 30
    ctx->gpr[10] = ctx->gpr[9] + (u32)(s32)(30);

label_8004B560:
    ctx->pc = 0x8004B560u;
    // 8004B560: stbx    r0, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004B564:
    ctx->pc = 0x8004B564u;
    // 8004B564: lwz     r11, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8004B568:
    // 8004B568: addi    r10, r8, 16
    ctx->gpr[10] = ctx->gpr[8] + (u32)(s32)(16);

label_8004B56C:
    ctx->pc = 0x8004B56Cu;
    // 8004B56C: stwx    r0, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B570:
    ctx->pc = 0x8004B570u;
    // 8004B570: lwz     r11, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8004B574:
    // 8004B574: addi    r10, r9, 46
    ctx->gpr[10] = ctx->gpr[9] + (u32)(s32)(46);

label_8004B578:
    ctx->pc = 0x8004B578u;
    // 8004B578: stbx    r0, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004B57C:
    ctx->pc = 0x8004B57Cu;
    // 8004B57C: lwz     r11, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8004B580:
    // 8004B580: addi    r10, r8, 24
    ctx->gpr[10] = ctx->gpr[8] + (u32)(s32)(24);

label_8004B584:
    ctx->pc = 0x8004B584u;
    // 8004B584: stwx    r0, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B588:
    ctx->pc = 0x8004B588u;
    // 8004B588: lwz     r11, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8004B58C:
    // 8004B58C: addi    r10, r9, 62
    ctx->gpr[10] = ctx->gpr[9] + (u32)(s32)(62);

label_8004B590:
    ctx->pc = 0x8004B590u;
    // 8004B590: stbx    r0, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004B594:
    ctx->pc = 0x8004B594u;
    // 8004B594: lwz     r11, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8004B598:
    // 8004B598: addi    r10, r8, 32
    ctx->gpr[10] = ctx->gpr[8] + (u32)(s32)(32);

label_8004B59C:
    ctx->pc = 0x8004B59Cu;
    // 8004B59C: stwx    r0, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B5A0:
    ctx->pc = 0x8004B5A0u;
    // 8004B5A0: lwz     r11, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8004B5A4:
    // 8004B5A4: addi    r10, r9, 78
    ctx->gpr[10] = ctx->gpr[9] + (u32)(s32)(78);

label_8004B5A8:
    ctx->pc = 0x8004B5A8u;
    // 8004B5A8: stbx    r0, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004B5AC:
    ctx->pc = 0x8004B5ACu;
    // 8004B5AC: lwz     r11, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8004B5B0:
    // 8004B5B0: addi    r10, r8, 40
    ctx->gpr[10] = ctx->gpr[8] + (u32)(s32)(40);

label_8004B5B4:
    ctx->pc = 0x8004B5B4u;
    // 8004B5B4: stwx    r0, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B5B8:
    ctx->pc = 0x8004B5B8u;
    // 8004B5B8: lwz     r11, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8004B5BC:
    // 8004B5BC: addi    r10, r9, 94
    ctx->gpr[10] = ctx->gpr[9] + (u32)(s32)(94);

label_8004B5C0:
    ctx->pc = 0x8004B5C0u;
    // 8004B5C0: stbx    r0, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004B5C4:
    ctx->pc = 0x8004B5C4u;
    // 8004B5C4: lwz     r11, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8004B5C8:
    // 8004B5C8: addi    r10, r8, 48
    ctx->gpr[10] = ctx->gpr[8] + (u32)(s32)(48);

label_8004B5CC:
    ctx->pc = 0x8004B5CCu;
    // 8004B5CC: stwx    r0, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B5D0:
    ctx->pc = 0x8004B5D0u;
    // 8004B5D0: lwz     r11, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8004B5D4:
    // 8004B5D4: addi    r10, r9, 110
    ctx->gpr[10] = ctx->gpr[9] + (u32)(s32)(110);

label_8004B5D8:
    ctx->pc = 0x8004B5D8u;
    // 8004B5D8: stbx    r0, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004B5DC:
    ctx->pc = 0x8004B5DCu;
    // 8004B5DC: lwz     r11, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8004B5E0:
    // 8004B5E0: addi    r10, r8, 56
    ctx->gpr[10] = ctx->gpr[8] + (u32)(s32)(56);

label_8004B5E4:
    ctx->pc = 0x8004B5E4u;
    // 8004B5E4: stwx    r0, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B5E8:
    ctx->pc = 0x8004B5E8u;
    // 8004B5E8: lwz     r11, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8004B5EC:
    // 8004B5EC: addi    r10, r9, 126
    ctx->gpr[10] = ctx->gpr[9] + (u32)(s32)(126);

label_8004B5F0:
    ctx->pc = 0x8004B5F0u;
    // 8004B5F0: stbx    r0, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004B5F4:
    // 8004B5F4: addi    r8, r8, 64
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(64);

label_8004B5F8:
    // 8004B5F8: addi    r9, r9, 128
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(128);

label_8004B5FC:
    // 8004B5FC: addi    r3, r3, 8
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(8);

label_8004B600:
    // 8004B600: bc    16, 0, 0x8004B534
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004B534u;
                return;
            }
            goto label_8004B534;
        }
    }

label_8004B604:
    ctx->pc = 0x8004B604u;
    ctx->downcount -= 7;
    // 8004B604: rlwinm r9, r3, 3, 0, 28
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[3], 3u) & 0xFFFFFFF8u;
    }

label_8004B608:
    ctx->pc = 0x8004B608u;
    // 8004B608: rlwinm r10, r3, 4, 0, 27
    {
        ctx->gpr[10] = dolrecomp_rotl32(ctx->gpr[3], 4u) & 0xFFFFFFF0u;
    }

label_8004B60C:
    ctx->pc = 0x8004B60Cu;
    // 8004B60C: subfic  r8, r3, 254
    {
        u64 res = (u64)(u32)(s32)(254) + (u64)(~ctx->gpr[3]) + 1u;
        ctx->gpr[8] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8004B610:
    ctx->pc = 0x8004B610u;
    // 8004B610: mtctr    r8
    ctx->ctr = ctx->gpr[8];

label_8004B614:
    ctx->pc = 0x8004B614u;
    // 8004B614: cmpwi   r3, 254
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(254);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004B618:
    ctx->pc = 0x8004B618u;
    // 8004B618: bc    4, 0, 0x8004B63C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004B63C;
        }
    }

label_8004B61C:
    loop_8004B61C(ctx);
    if (ctx->pc == 0x8004B63Cu) goto label_8004B63C;
    return;
label_8004B620:
    ctx->pc = 0x8004B620u;
    // 8004B620: stwx    r0, r3, r9
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[9];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B624:
    ctx->pc = 0x8004B624u;
    // 8004B624: lwz     r8, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8004B628:
    // 8004B628: addi    r3, r10, 14
    ctx->gpr[3] = ctx->gpr[10] + (u32)(s32)(14);

label_8004B62C:
    ctx->pc = 0x8004B62Cu;
    // 8004B62C: stbx    r0, r8, r3
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[3];
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004B630:
    // 8004B630: addi    r9, r9, 8
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(8);

label_8004B634:
    // 8004B634: addi    r10, r10, 16
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(16);

label_8004B638:
    // 8004B638: bc    16, 0, 0x8004B61C
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004B61Cu;
                return;
            }
            goto label_8004B61C;
        }
    }

label_8004B63C:
    ctx->pc = 0x8004B63Cu;
    ctx->downcount -= 10;
    // 8004B63C: stw     r4, 24(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8004B640:
    ctx->pc = 0x8004B640u;
    // 8004B640: stw     r5, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8004B644:
    ctx->pc = 0x8004B644u;
    // 8004B644: stw     r6, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8004B648:
    ctx->pc = 0x8004B648u;
    // 8004B648: rlwinm r0, r7, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0x00000001u;
    }

label_8004B64C:
    ctx->pc = 0x8004B64Cu;
    // 8004B64C: stb     r0, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004B650:
    ctx->pc = 0x8004B650u;
    // 8004B650: li      r0, 10000
    ctx->gpr[0] = (u32)(s32)(10000);

label_8004B654:
    ctx->pc = 0x8004B654u;
    // 8004B654: stw     r0, 36(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B658:
    ctx->pc = 0x8004B658u;
    // 8004B658: lha     r5, 32(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(32);
        ctx->gpr[5] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8004B65C:
    ctx->pc = 0x8004B65Cu;
    // 8004B65C: cmpwi   r5, 254
    {
        s32 val_a = (s32)(ctx->gpr[5]);
        s32 val_b = (s32)(254);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004B660:
    ctx->pc = 0x8004B660u;
    // 8004B660: bc    4, 2, 0x8004B66C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004B66C;
        }
    }

label_8004B664:
    ctx->pc = 0x8004B664u;
    ctx->downcount -= 2;
    // 8004B664: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_8004B668:
    ctx->pc = 0x8004B668u;
    // 8004B668: b       0x8004B6AC
    {
            goto label_8004B6AC;
    }

label_8004B66C:
    ctx->pc = 0x8004B66Cu;
    ctx->downcount -= 14;
    // 8004B66C: lwz     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004B670:
    ctx->pc = 0x8004B670u;
    // 8004B670: addi    r0, r5, 1
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(1);

label_8004B674:
    ctx->pc = 0x8004B674u;
    // 8004B674: sth     r0, 32(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(32);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8004B678:
    ctx->pc = 0x8004B678u;
    // 8004B678: rlwinm r0, r5, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 4u) & 0xFFFFFFF0u;
    }

label_8004B67C:
    ctx->pc = 0x8004B67Cu;
    // 8004B67C: add   r30, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[30] = res;
    }

label_8004B680:
    ctx->pc = 0x8004B680u;
    // 8004B680: stw     r4, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8004B684:
    ctx->pc = 0x8004B684u;
    // 8004B684: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8004B688:
    ctx->pc = 0x8004B688u;
    // 8004B688: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B68C:
    ctx->pc = 0x8004B68Cu;
    // 8004B68C: li      r0, 255
    ctx->gpr[0] = (u32)(s32)(255);

label_8004B690:
    ctx->pc = 0x8004B690u;
    // 8004B690: stb     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004B694:
    ctx->pc = 0x8004B694u;
    // 8004B694: lwz     r3, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004B698:
    ctx->pc = 0x8004B698u;
    // 8004B698: addi    r3, r3, 8
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(8);

label_8004B69C:
    ctx->pc = 0x8004B69Cu;
    // 8004B69C: lwz     r4, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004B6A0:
    ctx->pc = 0x8004B6A0u;
    // 8004B6A0: bl      0x80021838
    {
            ctx->lr = 0x8004B6A4u;
            ctx->pc = 0x80021838u;
            return;
    }

label_8004B6A4:
    ctx->pc = 0x8004B6A4u;
    ctx->downcount -= 1;
    // 8004B6A4: bl      0x80286924
    {
            ctx->lr = 0x8004B6A8u;
            ctx->pc = 0x80286924u;
            return;
    }

label_8004B6A8:
    ctx->pc = 0x8004B6A8u;
    ctx->downcount -= 1;
    // 8004B6A8: stw     r3, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8004B6AC:
    ctx->pc = 0x8004B6ACu;
    ctx->downcount -= 26;
    // 8004B6AC: lwz     r3, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004B6B0:
    ctx->pc = 0x8004B6B0u;
    // 8004B6B0: lwz     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004B6B4:
    ctx->pc = 0x8004B6B4u;
    // 8004B6B4: add   r6, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_8004B6B8:
    ctx->pc = 0x8004B6B8u;
    // 8004B6B8: lwz     r5, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8004B6BC:
    ctx->pc = 0x8004B6BCu;
    // 8004B6BC: lha     r3, 32(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(32);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8004B6C0:
    ctx->pc = 0x8004B6C0u;
    // 8004B6C0: addi    r0, r3, -1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-1);

label_8004B6C4:
    ctx->pc = 0x8004B6C4u;
    // 8004B6C4: rlwinm r4, r0, 0, 16, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x0000FFFFu;
    }

label_8004B6C8:
    ctx->pc = 0x8004B6C8u;
    // 8004B6C8: lha     r3, 34(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(34);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8004B6CC:
    ctx->pc = 0x8004B6CCu;
    // 8004B6CC: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8004B6D0:
    ctx->pc = 0x8004B6D0u;
    // 8004B6D0: sth     r0, 34(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(34);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8004B6D4:
    ctx->pc = 0x8004B6D4u;
    // 8004B6D4: extsh r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_8004B6D8:
    ctx->pc = 0x8004B6D8u;
    // 8004B6D8: rlwinm r0, r0, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 3u) & 0xFFFFFFF8u;
    }

label_8004B6DC:
    ctx->pc = 0x8004B6DCu;
    // 8004B6DC: add   r3, r5, r0
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8004B6E0:
    ctx->pc = 0x8004B6E0u;
    // 8004B6E0: sth     r4, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_8004B6E4:
    ctx->pc = 0x8004B6E4u;
    // 8004B6E4: subfic  r3, r6, -1
    {
        u64 res = (u64)(u32)(s32)(-1) + (u64)(~ctx->gpr[6]) + 1u;
        ctx->gpr[3] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8004B6E8:
    ctx->pc = 0x8004B6E8u;
    // 8004B6E8: lha     r0, 34(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(34);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8004B6EC:
    ctx->pc = 0x8004B6ECu;
    // 8004B6EC: rlwinm r0, r0, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 3u) & 0xFFFFFFF8u;
    }

label_8004B6F0:
    ctx->pc = 0x8004B6F0u;
    // 8004B6F0: stwx    r3, r5, r0
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8004B6F4:
    ctx->pc = 0x8004B6F4u;
    // 8004B6F4: lha     r8, 34(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(34);
        ctx->gpr[8] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8004B6F8:
    ctx->pc = 0x8004B6F8u;
    // 8004B6F8: rlwinm r0, r8, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[8], 3u) & 0xFFFFFFF8u;
    }

label_8004B6FC:
    ctx->pc = 0x8004B6FCu;
    // 8004B6FC: lwzx    r7, r5, r0
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[0];
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8004B700:
    ctx->pc = 0x8004B700u;
    // 8004B700: add   r3, r5, r0
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8004B704:
    ctx->pc = 0x8004B704u;
    // 8004B704: lhz     r6, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_8004B708:
    ctx->pc = 0x8004B708u;
    // 8004B708: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_8004B70C:
    ctx->pc = 0x8004B70Cu;
    // 8004B70C: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B710:
    ctx->pc = 0x8004B710u;
    // 8004B710: b       0x8004B738
    {
            goto label_8004B738;
    }

label_8004B714:
    loop_8004B714(ctx);
    if (ctx->pc == 0x8004B74Cu) goto label_8004B74C;
    return;
label_8004B718:
    // 8004B718: add   r9, r5, r0
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_8004B71C:
    ctx->pc = 0x8004B71Cu;
    // 8004B71C: lhz     r3, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_8004B720:
    // 8004B720: rlwinm r0, r8, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[8], 3u) & 0xFFFFFFF8u;
    }

label_8004B724:
    // 8004B724: add   r8, r5, r0
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_8004B728:
    ctx->pc = 0x8004B728u;
    // 8004B728: sth     r3, 4(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_8004B72C:
    ctx->pc = 0x8004B72Cu;
    // 8004B72C: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004B730:
    ctx->pc = 0x8004B730u;
    // 8004B730: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B734:
    // 8004B734: or   r8, r4, r4
    {
        ctx->gpr[8] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8004B738:
    ctx->downcount -= 5;
    // 8004B738: srawi r4, r8, 1
    {
        u32 sh = 1u;
        u32 value = ctx->gpr[8];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[4] = value;
        } else if (sh > 31) {
            ctx->gpr[4] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[4] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_8004B73C:
    // 8004B73C: rlwinm r0, r4, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 3u) & 0xFFFFFFF8u;
    }

label_8004B740:
    ctx->pc = 0x8004B740u;
    // 8004B740: lwzx    r0, r5, r0
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004B744:
    // 8004B744: cmplw   r0, r7
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[7]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004B748:
    // 8004B748: bc    12, 0, 0x8004B714
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004B714u;
                return;
            }
            goto label_8004B714;
        }
    }

label_8004B74C:
    ctx->pc = 0x8004B74Cu;
    ctx->downcount -= 12;
    // 8004B74C: rlwinm r0, r8, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[8], 3u) & 0xFFFFFFF8u;
    }

label_8004B750:
    ctx->pc = 0x8004B750u;
    // 8004B750: stwx    r7, r5, r0
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8004B754:
    ctx->pc = 0x8004B754u;
    // 8004B754: add   r3, r5, r0
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8004B758:
    ctx->pc = 0x8004B758u;
    // 8004B758: sth     r6, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_8004B75C:
    ctx->pc = 0x8004B75Cu;
    // 8004B75C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8004B760:
    ctx->pc = 0x8004B760u;
    // 8004B760: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8004B764:
    ctx->pc = 0x8004B764u;
    // 8004B764: lwz     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8004B768:
    ctx->pc = 0x8004B768u;
    // 8004B768: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004B76C:
    ctx->pc = 0x8004B76Cu;
    // 8004B76C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004B770:
    ctx->pc = 0x8004B770u;
    // 8004B770: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8004B774:
    ctx->pc = 0x8004B774u;
    // 8004B774: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004B778:
    ctx->pc = 0x8004B778u;
    ctx->downcount -= 8;
    // 8004B778: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004B77C:
    ctx->pc = 0x8004B77Cu;
    // 8004B77C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004B780:
    ctx->pc = 0x8004B780u;
    // 8004B780: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B784:
    ctx->pc = 0x8004B784u;
    // 8004B784: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8004B788:
    ctx->pc = 0x8004B788u;
    // 8004B788: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004B78C:
    ctx->pc = 0x8004B78Cu;
    // 8004B78C: lwz     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004B790:
    ctx->pc = 0x8004B790u;
    // 8004B790: cmplwi  r3, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004B794:
    ctx->pc = 0x8004B794u;
    // 8004B794: bc    12, 2, 0x8004B7A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004B7A4;
        }
    }

label_8004B798:
    ctx->pc = 0x8004B798u;
    ctx->downcount -= 1;
    // 8004B798: bl      0x80023968
    {
            ctx->lr = 0x8004B79Cu;
            ctx->pc = 0x80023968u;
            return;
    }

label_8004B79C:
    ctx->pc = 0x8004B79Cu;
    ctx->downcount -= 2;
    // 8004B79C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8004B7A0:
    ctx->pc = 0x8004B7A0u;
    // 8004B7A0: stw     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B7A4:
    ctx->pc = 0x8004B7A4u;
    ctx->downcount -= 6;
    // 8004B7A4: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8004B7A8:
    ctx->pc = 0x8004B7A8u;
    // 8004B7A8: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004B7AC:
    ctx->pc = 0x8004B7ACu;
    // 8004B7AC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004B7B0:
    ctx->pc = 0x8004B7B0u;
    // 8004B7B0: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8004B7B4:
    ctx->pc = 0x8004B7B4u;
    // 8004B7B4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004B7B8:
    ctx->pc = 0x8004B7B8u;
    ctx->downcount -= 9;
    // 8004B7B8: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004B7BC:
    ctx->pc = 0x8004B7BCu;
    // 8004B7BC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004B7C0:
    ctx->pc = 0x8004B7C0u;
    // 8004B7C0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B7C4:
    ctx->pc = 0x8004B7C4u;
    // 8004B7C4: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8004B7C8:
    ctx->pc = 0x8004B7C8u;
    // 8004B7C8: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004B7CC:
    ctx->pc = 0x8004B7CCu;
    // 8004B7CC: li      r3, 6496
    ctx->gpr[3] = (u32)(s32)(6496);

label_8004B7D0:
    ctx->pc = 0x8004B7D0u;
    // 8004B7D0: li      r4, 16
    ctx->gpr[4] = (u32)(s32)(16);

label_8004B7D4:
    ctx->pc = 0x8004B7D4u;
    // 8004B7D4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004B7D8:
    ctx->pc = 0x8004B7D8u;
    // 8004B7D8: bl      0x80023E30
    {
            ctx->lr = 0x8004B7DCu;
            ctx->pc = 0x80023E30u;
            return;
    }

label_8004B7DC:
    ctx->pc = 0x8004B7DCu;
    ctx->downcount -= 13;
    // 8004B7DC: stw     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8004B7E0:
    ctx->pc = 0x8004B7E0u;
    // 8004B7E0: lwz     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004B7E4:
    ctx->pc = 0x8004B7E4u;
    // 8004B7E4: addi    r0, r3, 4064
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(4064);

label_8004B7E8:
    ctx->pc = 0x8004B7E8u;
    // 8004B7E8: stw     r0, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B7EC:
    ctx->pc = 0x8004B7ECu;
    // 8004B7EC: lwz     r3, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004B7F0:
    ctx->pc = 0x8004B7F0u;
    // 8004B7F0: addi    r0, r3, 2032
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(2032);

label_8004B7F4:
    ctx->pc = 0x8004B7F4u;
    // 8004B7F4: stw     r0, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B7F8:
    ctx->pc = 0x8004B7F8u;
    // 8004B7F8: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8004B7FC:
    ctx->pc = 0x8004B7FCu;
    // 8004B7FC: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004B800:
    ctx->pc = 0x8004B800u;
    // 8004B800: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004B804:
    ctx->pc = 0x8004B804u;
    // 8004B804: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8004B808:
    ctx->pc = 0x8004B808u;
    // 8004B808: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004B80C:
    ctx->pc = 0x8004B80Cu;
    ctx->downcount -= 7;
    // 8004B80C: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004B810:
    ctx->pc = 0x8004B810u;
    // 8004B810: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004B814:
    ctx->pc = 0x8004B814u;
    // 8004B814: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B818:
    ctx->pc = 0x8004B818u;
    // 8004B818: li      r3, 32
    ctx->gpr[3] = (u32)(s32)(32);

label_8004B81C:
    ctx->pc = 0x8004B81Cu;
    // 8004B81C: li      r4, 255
    ctx->gpr[4] = (u32)(s32)(255);

label_8004B820:
    ctx->pc = 0x8004B820u;
    // 8004B820: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004B824:
    ctx->pc = 0x8004B824u;
    // 8004B824: bl      0x80023E30
    {
            ctx->lr = 0x8004B828u;
            ctx->pc = 0x80023E30u;
            return;
    }

label_8004B828:
    ctx->pc = 0x8004B828u;
    ctx->downcount -= 6;
    // 8004B828: stw     r3, -25720(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25720);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8004B82C:
    ctx->pc = 0x8004B82Cu;
    // 8004B82C: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004B830:
    ctx->pc = 0x8004B830u;
    // 8004B830: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004B834:
    ctx->pc = 0x8004B834u;
    // 8004B834: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8004B838:
    ctx->pc = 0x8004B838u;
    // 8004B838: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004B83C:
    ctx->pc = 0x8004B83Cu;
    ctx->downcount -= 18;
    // 8004B83C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004B840:
    ctx->pc = 0x8004B840u;
    // 8004B840: stwu     r1, -84(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-84);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004B844:
    ctx->pc = 0x8004B844u;
    // 8004B844: stw     r0, 88(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004B848:
    ctx->pc = 0x8004B848u;
    // 8004B848: stmw     r14, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 14; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8004B84C:
    ctx->pc = 0x8004B84Cu;
    // 8004B84C: addi    r5, r5, -1
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(-1);

label_8004B850:
    ctx->pc = 0x8004B850u;
    // 8004B850: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004B854:
    ctx->pc = 0x8004B854u;
    // 8004B854: li      r15, 32
    ctx->gpr[15] = (u32)(s32)(32);

label_8004B858:
    ctx->pc = 0x8004B858u;
    // 8004B858: addi    r3, r3, 2
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(2);

label_8004B85C:
    ctx->pc = 0x8004B85Cu;
    ctx->downcount -= 23;
    // 8004B85C: lbz     r16, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[16] = mem_read8(ctx, ea);
    }

label_8004B860:
    // 8004B860: addi    r7, r7, 1
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(1);

label_8004B864:
    // 8004B864: rlwnm r16, r16, r15, 31, 31
    {
        ctx->gpr[16] = dolrecomp_rotl32(ctx->gpr[16], ctx->gpr[15]) & 0x00000001u;
    }

label_8004B868:
    // 8004B868: srawi r17, r7, 3
    {
        u32 sh = 3u;
        u32 value = ctx->gpr[7];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[17] = value;
        } else if (sh > 31) {
            ctx->gpr[17] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[17] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_8004B86C:
    ctx->pc = 0x8004B86Cu;
    // 8004B86C: stw     r16, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[16]);
    }

label_8004B870:
    // 8004B870: add   r3, r3, r17
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[17];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8004B874:
    // 8004B874: andi.   r7, r7, 0x0007
    {
        ctx->gpr[7] = ctx->gpr[7] & 0x0007u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[7];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8004B878:
    // 8004B878: subfic  r15, r7, 32
    {
        u64 res = (u64)(u32)(s32)(32) + (u64)(~ctx->gpr[7]) + 1u;
        ctx->gpr[15] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8004B87C:
    // 8004B87C: cmpwi   r7, 6
    {
        s32 val_a = (s32)(ctx->gpr[7]);
        s32 val_b = (s32)(6);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004B880:
    ctx->pc = 0x8004B880u;
    // 8004B880: lbz     r18, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[18] = mem_read8(ctx, ea);
    }

label_8004B884:
    // 8004B884: rlwnm r18, r18, r15, 24, 31
    {
        ctx->gpr[18] = dolrecomp_rotl32(ctx->gpr[18], ctx->gpr[15]) & 0x000000FFu;
    }

label_8004B888:
    // 8004B888: subfic  r19, r7, 8
    {
        u64 res = (u64)(u32)(s32)(8) + (u64)(~ctx->gpr[7]) + 1u;
        ctx->gpr[19] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8004B88C:
    ctx->pc = 0x8004B88Cu;
    // 8004B88C: lbz     r20, 1(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1);
        ctx->gpr[20] = mem_read8(ctx, ea);
    }

label_8004B890:
    // 8004B890: slw   r19, r20, r19
    {
        u32 sh = ctx->gpr[19] & 0x3Fu;
        ctx->gpr[19] = sh > 31 ? 0u : (ctx->gpr[20] << sh);
    }

label_8004B894:
    // 8004B894: or   r18, r18, r19
    {
        ctx->gpr[18] = ctx->gpr[18] | ctx->gpr[19];
    }

label_8004B898:
    // 8004B898: andi.   r18, r18, 0x0003
    {
        ctx->gpr[18] = ctx->gpr[18] & 0x0003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[18];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8004B89C:
    // 8004B89C: addi    r7, r7, 2
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(2);

label_8004B8A0:
    // 8004B8A0: srawi r17, r7, 3
    {
        u32 sh = 3u;
        u32 value = ctx->gpr[7];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[17] = value;
        } else if (sh > 31) {
            ctx->gpr[17] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[17] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_8004B8A4:
    // 8004B8A4: add   r3, r3, r17
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[17];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8004B8A8:
    // 8004B8A8: andi.   r7, r7, 0x0007
    {
        ctx->gpr[7] = ctx->gpr[7] & 0x0007u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[7];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8004B8AC:
    // 8004B8AC: subfic  r15, r7, 32
    {
        u64 res = (u64)(u32)(s32)(32) + (u64)(~ctx->gpr[7]) + 1u;
        ctx->gpr[15] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8004B8B0:
    // 8004B8B0: cmpwi   r18, 0
    {
        s32 val_a = (s32)(ctx->gpr[18]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004B8B4:
    // 8004B8B4: bc    4, 2, 0x8004B8FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004B8FC;
        }
    }

label_8004B8B8:
    ctx->downcount -= 2;
    // 8004B8B8: cmpwi   r7, 0
    {
        s32 val_a = (s32)(ctx->gpr[7]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004B8BC:
    // 8004B8BC: bc    12, 2, 0x8004B8C8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004B8C8;
        }
    }

label_8004B8C0:
    ctx->downcount -= 2;
    // 8004B8C0: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_8004B8C4:
    // 8004B8C4: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004B8C8:
    ctx->pc = 0x8004B8C8u;
    ctx->downcount -= 6;
    // 8004B8C8: lhz     r18, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[18] = mem_read16(ctx, ea);
    }

label_8004B8CC:
    // 8004B8CC: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_8004B8D0:
    ctx->pc = 0x8004B8D0u;
    // 8004B8D0: lhz     r19, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[19] = mem_read16(ctx, ea);
    }

label_8004B8D4:
    // 8004B8D4: addi    r3, r3, 3
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(3);

label_8004B8D8:
    // 8004B8D8: rlwinm r19, r19, 8, 0, 23
    {
        ctx->gpr[19] = dolrecomp_rotl32(ctx->gpr[19], 8u) & 0xFFFFFF00u;
    }

label_8004B8DC:
    // 8004B8DC: or   r18, r18, r19
    {
        ctx->gpr[18] = ctx->gpr[18] | ctx->gpr[19];
    }

label_8004B8E0:
    ctx->pc = 0x8004B8E0u;
    ctx->downcount -= 6;
    // 8004B8E0: lbz     r19, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[19] = mem_read8(ctx, ea);
    }

label_8004B8E4:
    // 8004B8E4: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_8004B8E8:
    ctx->pc = 0x8004B8E8u;
    // 8004B8E8: stbu     r19, 1(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1);
        mem_write8(ctx, ea, (u8)ctx->gpr[19]);
        ctx->gpr[5] = ea;
    }

label_8004B8EC:
    ctx->pc = 0x8004B8ECu;
    // 8004B8EC: mcrxr   cr0
    {
        u32 bits = (ctx->xer >> 28) & 0xFu;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (bits << 28);
        ctx->xer &= ~0xE0000000u;
    }

label_8004B8F0:
    // 8004B8F0: addme.  r18, r18
    {
        u32 input = ctx->gpr[18];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 res = (u64)input + 0xFFFFFFFFull + carry;
        ctx->gpr[18] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | ((res >> 32) ? 0x20000000u : 0u);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[18];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8004B8F4:
    // 8004B8F4: bc    4, 2, 0x8004B8E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004B8E0u;
                return;
            }
            goto label_8004B8E0;
        }
    }

label_8004B8F8:
    ctx->downcount -= 1;
    // 8004B8F8: b       0x8004C148
    {
            goto label_8004C148;
    }

label_8004B8FC:
    ctx->downcount -= 2;
    // 8004B8FC: cmpwi   r18, 1
    {
        s32 val_a = (s32)(ctx->gpr[18]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004B900:
    // 8004B900: bc    4, 2, 0x8004B930
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004B930;
        }
    }

label_8004B904:
    ctx->downcount -= 11;
    // 8004B904: lis     r8, -32719
    ctx->gpr[8] = ((u32)(s32)(-32719) << 16);

label_8004B908:
    // 8004B908: addi    r8, r8, -8096
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(-8096);

label_8004B90C:
    // 8004B90C: lis     r9, -32719
    ctx->gpr[9] = ((u32)(s32)(-32719) << 16);

label_8004B910:
    // 8004B910: addi    r9, r9, -7808
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-7808);

label_8004B914:
    // 8004B914: li      r10, 9
    ctx->gpr[10] = (u32)(s32)(9);

label_8004B918:
    // 8004B918: lis     r11, -32719
    ctx->gpr[11] = ((u32)(s32)(-32719) << 16);

label_8004B91C:
    // 8004B91C: addi    r11, r11, -6784
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(-6784);

label_8004B920:
    // 8004B920: lis     r12, -32719
    ctx->gpr[12] = ((u32)(s32)(-32719) << 16);

label_8004B924:
    // 8004B924: addi    r12, r12, -6752
    ctx->gpr[12] = ctx->gpr[12] + (u32)(s32)(-6752);

label_8004B928:
    // 8004B928: li      r14, 5
    ctx->gpr[14] = (u32)(s32)(5);

label_8004B92C:
    // 8004B92C: b       0x8004BF2C
    {
            goto label_8004BF2C;
    }

label_8004B930:
    ctx->downcount -= 14;
    // 8004B930: lis     r8, -32714
    ctx->gpr[8] = ((u32)(s32)(-32714) << 16);

label_8004B934:
    // 8004B934: addi    r8, r8, 4256
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(4256);

label_8004B938:
    // 8004B938: lis     r9, -32714
    ctx->gpr[9] = ((u32)(s32)(-32714) << 16);

label_8004B93C:
    // 8004B93C: addi    r9, r9, 4544
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(4544);

label_8004B940:
    // 8004B940: lis     r11, -32713
    ctx->gpr[11] = ((u32)(s32)(-32713) << 16);

label_8004B944:
    // 8004B944: addi    r11, r11, 4544
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(4544);

label_8004B948:
    // 8004B948: lis     r12, -32713
    ctx->gpr[12] = ((u32)(s32)(-32713) << 16);

label_8004B94C:
    // 8004B94C: addi    r12, r12, 4576
    ctx->gpr[12] = ctx->gpr[12] + (u32)(s32)(4576);

label_8004B950:
    // 8004B950: li      r19, 0
    ctx->gpr[19] = (u32)(s32)(0);

label_8004B954:
    // 8004B954: li      r21, 8
    ctx->gpr[21] = (u32)(s32)(8);

label_8004B958:
    ctx->pc = 0x8004B958u;
    // 8004B958: mtctr    r21
    ctx->ctr = ctx->gpr[21];

label_8004B95C:
    // 8004B95C: lis     r18, -32706
    ctx->gpr[18] = ((u32)(s32)(-32706) << 16);

label_8004B960:
    // 8004B960: addi    r18, r18, -6440
    ctx->gpr[18] = ctx->gpr[18] + (u32)(s32)(-6440);

label_8004B964:
    loop_8004B964(ctx);
    if (ctx->pc == 0x8004B970u) goto label_8004B970;
    return;
label_8004B968:
    // 8004B968: addi    r18, r18, 1
    ctx->gpr[18] = ctx->gpr[18] + (u32)(s32)(1);

label_8004B96C:
    // 8004B96C: bc    16, 0, 0x8004B964
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004B964u;
                return;
            }
            goto label_8004B964;
        }
    }

label_8004B970:
    ctx->downcount -= 5;
    // 8004B970: li      r21, 19
    ctx->gpr[21] = (u32)(s32)(19);

label_8004B974:
    ctx->pc = 0x8004B974u;
    // 8004B974: mtctr    r21
    ctx->ctr = ctx->gpr[21];

label_8004B978:
    // 8004B978: lis     r18, -32712
    ctx->gpr[18] = ((u32)(s32)(-32712) << 16);

label_8004B97C:
    // 8004B97C: addi    r18, r18, -28192
    ctx->gpr[18] = ctx->gpr[18] + (u32)(s32)(-28192);

label_8004B980:
    loop_8004B980(ctx);
    if (ctx->pc == 0x8004B98Cu) goto label_8004B98C;
    return;
label_8004B984:
    // 8004B984: addi    r18, r18, 1
    ctx->gpr[18] = ctx->gpr[18] + (u32)(s32)(1);

label_8004B988:
    // 8004B988: bc    16, 0, 0x8004B980
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004B980u;
                return;
            }
            goto label_8004B980;
        }
    }

label_8004B98C:
    ctx->downcount -= 5;
    // 8004B98C: li      r21, 16
    ctx->gpr[21] = (u32)(s32)(16);

label_8004B990:
    ctx->pc = 0x8004B990u;
    // 8004B990: mtctr    r21
    ctx->ctr = ctx->gpr[21];

label_8004B994:
    // 8004B994: lis     r18, -32712
    ctx->gpr[18] = ((u32)(s32)(-32712) << 16);

label_8004B998:
    // 8004B998: addi    r18, r18, -28172
    ctx->gpr[18] = ctx->gpr[18] + (u32)(s32)(-28172);

label_8004B99C:
    loop_8004B99C(ctx);
    if (ctx->pc == 0x8004B9A8u) goto label_8004B9A8;
    return;
label_8004B9A0:
    // 8004B9A0: addi    r18, r18, 2
    ctx->gpr[18] = ctx->gpr[18] + (u32)(s32)(2);

label_8004B9A4:
    // 8004B9A4: bc    16, 0, 0x8004B99C
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004B99Cu;
                return;
            }
            goto label_8004B99C;
        }
    }

label_8004B9A8:
    ctx->downcount -= 4;
    // 8004B9A8: li      r21, 288
    ctx->gpr[21] = (u32)(s32)(288);

label_8004B9AC:
    ctx->pc = 0x8004B9ACu;
    // 8004B9AC: mtctr    r21
    ctx->ctr = ctx->gpr[21];

label_8004B9B0:
    // 8004B9B0: or   r18, r8, r8
    {
        ctx->gpr[18] = ctx->gpr[8] | ctx->gpr[8];
    }

label_8004B9B4:
    loop_8004B9B4(ctx);
    if (ctx->pc == 0x8004B9C0u) goto label_8004B9C0;
    return;
label_8004B9B8:
    // 8004B9B8: addi    r18, r18, 1
    ctx->gpr[18] = ctx->gpr[18] + (u32)(s32)(1);

label_8004B9BC:
    // 8004B9BC: bc    16, 0, 0x8004B9B4
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004B9B4u;
                return;
            }
            goto label_8004B9B4;
        }
    }

label_8004B9C0:
    ctx->downcount -= 5;
    // 8004B9C0: li      r21, 16
    ctx->gpr[21] = (u32)(s32)(16);

label_8004B9C4:
    ctx->pc = 0x8004B9C4u;
    // 8004B9C4: mtctr    r21
    ctx->ctr = ctx->gpr[21];

label_8004B9C8:
    // 8004B9C8: lis     r18, -32712
    ctx->gpr[18] = ((u32)(s32)(-32712) << 16);

label_8004B9CC:
    // 8004B9CC: addi    r18, r18, -28140
    ctx->gpr[18] = ctx->gpr[18] + (u32)(s32)(-28140);

label_8004B9D0:
    loop_8004B9D0(ctx);
    if (ctx->pc == 0x8004B9DCu) goto label_8004B9DC;
    return;
label_8004B9D4:
    // 8004B9D4: addi    r18, r18, 2
    ctx->gpr[18] = ctx->gpr[18] + (u32)(s32)(2);

label_8004B9D8:
    // 8004B9D8: bc    16, 0, 0x8004B9D0
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004B9D0u;
                return;
            }
            goto label_8004B9D0;
        }
    }

label_8004B9DC:
    ctx->downcount -= 4;
    // 8004B9DC: li      r21, 32
    ctx->gpr[21] = (u32)(s32)(32);

label_8004B9E0:
    ctx->pc = 0x8004B9E0u;
    // 8004B9E0: mtctr    r21
    ctx->ctr = ctx->gpr[21];

label_8004B9E4:
    // 8004B9E4: or   r18, r11, r11
    {
        ctx->gpr[18] = ctx->gpr[11] | ctx->gpr[11];
    }

label_8004B9E8:
    loop_8004B9E8(ctx);
    if (ctx->pc == 0x8004B9F4u) goto label_8004B9F4;
    return;
label_8004B9EC:
    // 8004B9EC: addi    r18, r18, 1
    ctx->gpr[18] = ctx->gpr[18] + (u32)(s32)(1);

label_8004B9F0:
    // 8004B9F0: bc    16, 0, 0x8004B9E8
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004B9E8u;
                return;
            }
            goto label_8004B9E8;
        }
    }

label_8004B9F4:
    ctx->pc = 0x8004B9F4u;
    ctx->downcount -= 47;
    // 8004B9F4: lbz     r18, 1(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1);
        ctx->gpr[18] = mem_read8(ctx, ea);
    }

label_8004B9F8:
    // 8004B9F8: subfic  r17, r7, 8
    {
        u64 res = (u64)(u32)(s32)(8) + (u64)(~ctx->gpr[7]) + 1u;
        ctx->gpr[17] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8004B9FC:
    // 8004B9FC: slw   r18, r18, r17
    {
        u32 sh = ctx->gpr[17] & 0x3Fu;
        ctx->gpr[18] = sh > 31 ? 0u : (ctx->gpr[18] << sh);
    }

label_8004BA00:
    ctx->pc = 0x8004BA00u;
    // 8004BA00: lbz     r17, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[17] = mem_read8(ctx, ea);
    }

label_8004BA04:
    // 8004BA04: rlwnm r17, r17, r15, 24, 31
    {
        ctx->gpr[17] = dolrecomp_rotl32(ctx->gpr[17], ctx->gpr[15]) & 0x000000FFu;
    }

label_8004BA08:
    // 8004BA08: or   r17, r17, r18
    {
        ctx->gpr[17] = ctx->gpr[17] | ctx->gpr[18];
    }

label_8004BA0C:
    // 8004BA0C: andi.   r17, r17, 0x001F
    {
        ctx->gpr[17] = ctx->gpr[17] & 0x001Fu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[17];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8004BA10:
    // 8004BA10: addi    r7, r7, 5
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(5);

label_8004BA14:
    // 8004BA14: addi    r23, r17, 257
    ctx->gpr[23] = ctx->gpr[17] + (u32)(s32)(257);

label_8004BA18:
    // 8004BA18: srawi r17, r7, 3
    {
        u32 sh = 3u;
        u32 value = ctx->gpr[7];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[17] = value;
        } else if (sh > 31) {
            ctx->gpr[17] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[17] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_8004BA1C:
    // 8004BA1C: add   r3, r3, r17
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[17];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8004BA20:
    // 8004BA20: andi.   r7, r7, 0x0007
    {
        ctx->gpr[7] = ctx->gpr[7] & 0x0007u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[7];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8004BA24:
    // 8004BA24: subfic  r15, r7, 32
    {
        u64 res = (u64)(u32)(s32)(32) + (u64)(~ctx->gpr[7]) + 1u;
        ctx->gpr[15] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8004BA28:
    ctx->pc = 0x8004BA28u;
    // 8004BA28: lbz     r18, 1(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1);
        ctx->gpr[18] = mem_read8(ctx, ea);
    }

label_8004BA2C:
    // 8004BA2C: subfic  r17, r7, 8
    {
        u64 res = (u64)(u32)(s32)(8) + (u64)(~ctx->gpr[7]) + 1u;
        ctx->gpr[17] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8004BA30:
    // 8004BA30: slw   r18, r18, r17
    {
        u32 sh = ctx->gpr[17] & 0x3Fu;
        ctx->gpr[18] = sh > 31 ? 0u : (ctx->gpr[18] << sh);
    }

label_8004BA34:
    ctx->pc = 0x8004BA34u;
    // 8004BA34: lbz     r17, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[17] = mem_read8(ctx, ea);
    }

label_8004BA38:
    // 8004BA38: rlwnm r17, r17, r15, 24, 31
    {
        ctx->gpr[17] = dolrecomp_rotl32(ctx->gpr[17], ctx->gpr[15]) & 0x000000FFu;
    }

label_8004BA3C:
    // 8004BA3C: or   r17, r17, r18
    {
        ctx->gpr[17] = ctx->gpr[17] | ctx->gpr[18];
    }

label_8004BA40:
    // 8004BA40: andi.   r17, r17, 0x001F
    {
        ctx->gpr[17] = ctx->gpr[17] & 0x001Fu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[17];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8004BA44:
    // 8004BA44: addi    r7, r7, 5
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(5);

label_8004BA48:
    // 8004BA48: addi    r24, r17, 1
    ctx->gpr[24] = ctx->gpr[17] + (u32)(s32)(1);

label_8004BA4C:
    // 8004BA4C: srawi r17, r7, 3
    {
        u32 sh = 3u;
        u32 value = ctx->gpr[7];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[17] = value;
        } else if (sh > 31) {
            ctx->gpr[17] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[17] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_8004BA50:
    // 8004BA50: add   r3, r3, r17
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[17];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8004BA54:
    // 8004BA54: andi.   r7, r7, 0x0007
    {
        ctx->gpr[7] = ctx->gpr[7] & 0x0007u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[7];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8004BA58:
    // 8004BA58: subfic  r15, r7, 32
    {
        u64 res = (u64)(u32)(s32)(32) + (u64)(~ctx->gpr[7]) + 1u;
        ctx->gpr[15] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8004BA5C:
    ctx->pc = 0x8004BA5Cu;
    // 8004BA5C: lbz     r18, 1(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1);
        ctx->gpr[18] = mem_read8(ctx, ea);
    }

label_8004BA60:
    // 8004BA60: subfic  r17, r7, 8
    {
        u64 res = (u64)(u32)(s32)(8) + (u64)(~ctx->gpr[7]) + 1u;
        ctx->gpr[17] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8004BA64:
    // 8004BA64: slw   r18, r18, r17
    {
        u32 sh = ctx->gpr[17] & 0x3Fu;
        ctx->gpr[18] = sh > 31 ? 0u : (ctx->gpr[18] << sh);
    }

label_8004BA68:
    ctx->pc = 0x8004BA68u;
    // 8004BA68: lbz     r17, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[17] = mem_read8(ctx, ea);
    }

label_8004BA6C:
    // 8004BA6C: rlwnm r17, r17, r15, 24, 31
    {
        ctx->gpr[17] = dolrecomp_rotl32(ctx->gpr[17], ctx->gpr[15]) & 0x000000FFu;
    }

label_8004BA70:
    // 8004BA70: or   r17, r17, r18
    {
        ctx->gpr[17] = ctx->gpr[17] | ctx->gpr[18];
    }

label_8004BA74:
    // 8004BA74: andi.   r17, r17, 0x000F
    {
        ctx->gpr[17] = ctx->gpr[17] & 0x000Fu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[17];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8004BA78:
    // 8004BA78: addi    r7, r7, 4
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(4);

label_8004BA7C:
    // 8004BA7C: addi    r25, r17, 4
    ctx->gpr[25] = ctx->gpr[17] + (u32)(s32)(4);

label_8004BA80:
    // 8004BA80: srawi r17, r7, 3
    {
        u32 sh = 3u;
        u32 value = ctx->gpr[7];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[17] = value;
        } else if (sh > 31) {
            ctx->gpr[17] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[17] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_8004BA84:
    // 8004BA84: add   r3, r3, r17
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[17];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8004BA88:
    // 8004BA88: andi.   r7, r7, 0x0007
    {
        ctx->gpr[7] = ctx->gpr[7] & 0x0007u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[7];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8004BA8C:
    // 8004BA8C: subfic  r15, r7, 32
    {
        u64 res = (u64)(u32)(s32)(32) + (u64)(~ctx->gpr[7]) + 1u;
        ctx->gpr[15] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8004BA90:
    // 8004BA90: lis     r29, -32724
    ctx->gpr[29] = ((u32)(s32)(-32724) << 16);

label_8004BA94:
    // 8004BA94: lis     r30, -32712
    ctx->gpr[30] = ((u32)(s32)(-32712) << 16);

label_8004BA98:
    // 8004BA98: lis     r31, -32706
    ctx->gpr[31] = ((u32)(s32)(-32706) << 16);

label_8004BA9C:
    // 8004BA9C: addi    r29, r29, 9680
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(9680);

label_8004BAA0:
    // 8004BAA0: addi    r30, r30, -28192
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-28192);

label_8004BAA4:
    // 8004BAA4: addi    r31, r31, -6440
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(-6440);

label_8004BAA8:
    // 8004BAA8: li      r21, 0
    ctx->gpr[21] = (u32)(s32)(0);

label_8004BAAC:
    // 8004BAAC: b       0x8004BAF8
    {
            goto label_8004BAF8;
    }

label_8004BAB0:
    loop_8004BAB0(ctx);
    if (ctx->pc == 0x8004BB00u) goto label_8004BB00;
    return;
label_8004BAB4:
    // 8004BAB4: subfic  r17, r7, 8
    {
        u64 res = (u64)(u32)(s32)(8) + (u64)(~ctx->gpr[7]) + 1u;
        ctx->gpr[17] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8004BAB8:
    // 8004BAB8: slw   r18, r18, r17
    {
        u32 sh = ctx->gpr[17] & 0x3Fu;
        ctx->gpr[18] = sh > 31 ? 0u : (ctx->gpr[18] << sh);
    }

label_8004BABC:
    ctx->pc = 0x8004BABCu;
    // 8004BABC: lbz     r17, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[17] = mem_read8(ctx, ea);
    }

label_8004BAC0:
    // 8004BAC0: rlwnm r17, r17, r15, 24, 31
    {
        ctx->gpr[17] = dolrecomp_rotl32(ctx->gpr[17], ctx->gpr[15]) & 0x000000FFu;
    }

label_8004BAC4:
    // 8004BAC4: or   r17, r17, r18
    {
        ctx->gpr[17] = ctx->gpr[17] | ctx->gpr[18];
    }

label_8004BAC8:
    // 8004BAC8: andi.   r17, r17, 0x0007
    {
        ctx->gpr[17] = ctx->gpr[17] & 0x0007u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[17];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8004BACC:
    ctx->pc = 0x8004BACCu;
    // 8004BACC: lbzx    r18, r29, r21
    {
        u32 ea = ctx->gpr[29] + ctx->gpr[21];
        ctx->gpr[18] = mem_read8(ctx, ea);
    }

label_8004BAD0:
    ctx->pc = 0x8004BAD0u;
    // 8004BAD0: stbx    r17, r30, r18
    {
        u32 ea = ctx->gpr[30] + ctx->gpr[18];
        mem_write8(ctx, ea, (u8)ctx->gpr[17]);
    }

label_8004BAD4:
    ctx->pc = 0x8004BAD4u;
    // 8004BAD4: lbzx    r18, r31, r17
    {
        u32 ea = ctx->gpr[31] + ctx->gpr[17];
        ctx->gpr[18] = mem_read8(ctx, ea);
    }

label_8004BAD8:
    // 8004BAD8: addi    r18, r18, 1
    ctx->gpr[18] = ctx->gpr[18] + (u32)(s32)(1);

label_8004BADC:
    // 8004BADC: addi    r7, r7, 3
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(3);

label_8004BAE0:
    ctx->pc = 0x8004BAE0u;
    // 8004BAE0: stbx    r18, r31, r17
    {
        u32 ea = ctx->gpr[31] + ctx->gpr[17];
        mem_write8(ctx, ea, (u8)ctx->gpr[18]);
    }

label_8004BAE4:
    // 8004BAE4: srawi r17, r7, 3
    {
        u32 sh = 3u;
        u32 value = ctx->gpr[7];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[17] = value;
        } else if (sh > 31) {
            ctx->gpr[17] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[17] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_8004BAE8:
    // 8004BAE8: add   r3, r3, r17
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[17];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8004BAEC:
    // 8004BAEC: andi.   r7, r7, 0x0007
    {
        ctx->gpr[7] = ctx->gpr[7] & 0x0007u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[7];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8004BAF0:
    // 8004BAF0: subfic  r15, r7, 32
    {
        u64 res = (u64)(u32)(s32)(32) + (u64)(~ctx->gpr[7]) + 1u;
        ctx->gpr[15] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8004BAF4:
    // 8004BAF4: addi    r21, r21, 1
    ctx->gpr[21] = ctx->gpr[21] + (u32)(s32)(1);

label_8004BAF8:
    ctx->downcount -= 2;
    // 8004BAF8: cmpw    r21, r25
    {
        s32 val_a = (s32)(ctx->gpr[21]);
        s32 val_b = (s32)(ctx->gpr[25]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004BAFC:
    // 8004BAFC: bc    4, 2, 0x8004BAB0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004BAB0u;
                return;
            }
            goto label_8004BAB0;
        }
    }

label_8004BB00:
    ctx->downcount -= 3;
    // 8004BB00: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_8004BB04:
    // 8004BB04: lis     r16, -32706
    ctx->gpr[16] = ((u32)(s32)(-32706) << 16);

label_8004BB08:
    // 8004BB08: addi    r16, r16, -6440
    ctx->gpr[16] = ctx->gpr[16] + (u32)(s32)(-6440);

label_8004BB0C:
    ctx->pc = 0x8004BB0Cu;
    ctx->downcount -= 3;
    // 8004BB0C: lbzx    r18, r4, r16
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[16];
        ctx->gpr[18] = mem_read8(ctx, ea);
    }

label_8004BB10:
    // 8004BB10: cmpwi   r18, 0
    {
        s32 val_a = (s32)(ctx->gpr[18]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004BB14:
    // 8004BB14: bc    4, 2, 0x8004BB20
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004BB20;
        }
    }

label_8004BB18:
    ctx->downcount -= 2;
    // 8004BB18: addi    r4, r4, -1
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-1);

label_8004BB1C:
    // 8004BB1C: b       0x8004BB0C
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004BB0Cu;
                return;
            }
            goto label_8004BB0C;
    }

label_8004BB20:
    ctx->downcount -= 5;
    // 8004BB20: li      r26, 1
    ctx->gpr[26] = (u32)(s32)(1);

label_8004BB24:
    // 8004BB24: li      r22, 0
    ctx->gpr[22] = (u32)(s32)(0);

label_8004BB28:
    // 8004BB28: lis     r31, -32706
    ctx->gpr[31] = ((u32)(s32)(-32706) << 16);

label_8004BB2C:
    // 8004BB2C: addi    r31, r31, -6448
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(-6448);

label_8004BB30:
    // 8004BB30: b       0x8004BB54
    {
            goto label_8004BB54;
    }

label_8004BB34:
    ctx->pc = 0x8004BB34u;
    ctx->downcount -= 3;
    // 8004BB34: lbzx    r18, r26, r16
    {
        u32 ea = ctx->gpr[26] + ctx->gpr[16];
        ctx->gpr[18] = mem_read8(ctx, ea);
    }

label_8004BB38:
    // 8004BB38: cmpwi   r18, 0
    {
        s32 val_a = (s32)(ctx->gpr[18]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004BB3C:
    // 8004BB3C: bc    12, 2, 0x8004BB50
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004BB50;
        }
    }

label_8004BB40:
    ctx->pc = 0x8004BB40u;
    ctx->downcount -= 4;
    // 8004BB40: stbx    r22, r31, r26
    {
        u32 ea = ctx->gpr[31] + ctx->gpr[26];
        mem_write8(ctx, ea, (u8)ctx->gpr[22]);
    }

label_8004BB44:
    // 8004BB44: subf   r17, r26, r4
    {
        u32 a = ~ctx->gpr[26];
        u32 b = ctx->gpr[4];
        u32 res = a + b + 1u;
        ctx->gpr[17] = res;
    }

label_8004BB48:
    // 8004BB48: slw   r17, r18, r17
    {
        u32 sh = ctx->gpr[17] & 0x3Fu;
        ctx->gpr[17] = sh > 31 ? 0u : (ctx->gpr[18] << sh);
    }

label_8004BB4C:
    // 8004BB4C: add   r22, r22, r17
    {
        u32 a = ctx->gpr[22];
        u32 b = ctx->gpr[17];
        u32 res = a + b;
        ctx->gpr[22] = res;
    }

label_8004BB50:
    ctx->downcount -= 1;
    // 8004BB50: addi    r26, r26, 1
    ctx->gpr[26] = ctx->gpr[26] + (u32)(s32)(1);

label_8004BB54:
    ctx->downcount -= 2;
    // 8004BB54: cmpw    r26, r4
    {
        s32 val_a = (s32)(ctx->gpr[26]);
        s32 val_b = (s32)(ctx->gpr[4]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004BB58:
    // 8004BB58: bc    4, 1, 0x8004BB34
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004BB34u;
                return;
            }
            goto label_8004BB34;
        }
    }

label_8004BB5C:
    ctx->downcount -= 7;
    // 8004BB5C: lis     r16, -32712
    ctx->gpr[16] = ((u32)(s32)(-32712) << 16);

label_8004BB60:
    // 8004BB60: addi    r16, r16, -28192
    ctx->gpr[16] = ctx->gpr[16] + (u32)(s32)(-28192);

label_8004BB64:
    // 8004BB64: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_8004BB68:
    // 8004BB68: lis     r27, -32712
    ctx->gpr[27] = ((u32)(s32)(-32712) << 16);

label_8004BB6C:
    // 8004BB6C: addi    r27, r27, -28108
    ctx->gpr[27] = ctx->gpr[27] + (u32)(s32)(-28108);

label_8004BB70:
    // 8004BB70: addi    r27, r27, -1
    ctx->gpr[27] = ctx->gpr[27] + (u32)(s32)(-1);

label_8004BB74:
    // 8004BB74: b       0x8004BBC0
    {
            goto label_8004BBC0;
    }

label_8004BB78:
    ctx->downcount -= 5;
    // 8004BB78: lis     r29, -32706
    ctx->gpr[29] = ((u32)(s32)(-32706) << 16);

label_8004BB7C:
    // 8004BB7C: addi    r29, r29, -6448
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(-6448);

label_8004BB80:
    ctx->pc = 0x8004BB80u;
    // 8004BB80: lbzx    r17, r16, r28
    {
        u32 ea = ctx->gpr[16] + ctx->gpr[28];
        ctx->gpr[17] = mem_read8(ctx, ea);
    }

label_8004BB84:
    // 8004BB84: cmpwi   r17, 0
    {
        s32 val_a = (s32)(ctx->gpr[17]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004BB88:
    // 8004BB88: bc    12, 2, 0x8004BBBC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004BBBC;
        }
    }

label_8004BB8C:
    ctx->downcount -= 2;
    // 8004BB8C: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_8004BB90:
    // 8004BB90: b       0x8004BBA8
    {
            goto label_8004BBA8;
    }

label_8004BB94:
    loop_8004BB94(ctx);
    if (ctx->pc == 0x8004BBBCu) goto label_8004BBBC;
    return;
label_8004BB98:
    // 8004BB98: addi    r30, r30, 1
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(1);

label_8004BB9C:
    ctx->pc = 0x8004BB9Cu;
    // 8004BB9C: stbx    r30, r17, r29
    {
        u32 ea = ctx->gpr[17] + ctx->gpr[29];
        mem_write8(ctx, ea, (u8)ctx->gpr[30]);
    }

label_8004BBA0:
    ctx->pc = 0x8004BBA0u;
    // 8004BBA0: stbx    r28, r27, r30
    {
        u32 ea = ctx->gpr[27] + ctx->gpr[30];
        mem_write8(ctx, ea, (u8)ctx->gpr[28]);
    }

label_8004BBA4:
    // 8004BBA4: addi    r31, r31, 1
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(1);

label_8004BBA8:
    ctx->downcount -= 5;
    // 8004BBA8: subf   r18, r17, r4
    {
        u32 a = ~ctx->gpr[17];
        u32 b = ctx->gpr[4];
        u32 res = a + b + 1u;
        ctx->gpr[18] = res;
    }

label_8004BBAC:
    // 8004BBAC: li      r22, 1
    ctx->gpr[22] = (u32)(s32)(1);

label_8004BBB0:
    // 8004BBB0: slw   r18, r22, r18
    {
        u32 sh = ctx->gpr[18] & 0x3Fu;
        ctx->gpr[18] = sh > 31 ? 0u : (ctx->gpr[22] << sh);
    }

label_8004BBB4:
    // 8004BBB4: cmpw    r31, r18
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(ctx->gpr[18]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004BBB8:
    // 8004BBB8: bc    12, 0, 0x8004BB94
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004BB94u;
                return;
            }
            goto label_8004BB94;
        }
    }

label_8004BBBC:
    ctx->downcount -= 1;
    // 8004BBBC: addi    r28, r28, 1
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(1);

label_8004BBC0:
    ctx->downcount -= 2;
    // 8004BBC0: cmpwi   r28, 19
    {
        s32 val_a = (s32)(ctx->gpr[28]);
        s32 val_b = (s32)(19);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004BBC4:
    // 8004BBC4: bc    12, 0, 0x8004BB78
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004BB78u;
                return;
            }
            goto label_8004BB78;
        }
    }

label_8004BBC8:
    ctx->downcount -= 4;
    // 8004BBC8: or   r19, r8, r8
    {
        ctx->gpr[19] = ctx->gpr[8] | ctx->gpr[8];
    }

label_8004BBCC:
    // 8004BBCC: lis     r20, -32712
    ctx->gpr[20] = ((u32)(s32)(-32712) << 16);

label_8004BBD0:
    // 8004BBD0: addi    r20, r20, -28172
    ctx->gpr[20] = ctx->gpr[20] + (u32)(s32)(-28172);

label_8004BBD4:
    // 8004BBD4: li      r21, 0
    ctx->gpr[21] = (u32)(s32)(0);

label_8004BBD8:
    ctx->downcount -= 4;
    // 8004BBD8: subfic  r16, r4, 8
    {
        u64 res = (u64)(u32)(s32)(8) + (u64)(~ctx->gpr[4]) + 1u;
        ctx->gpr[16] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8004BBDC:
    // 8004BBDC: cmpw    r7, r16
    {
        s32 val_a = (s32)(ctx->gpr[7]);
        s32 val_b = (s32)(ctx->gpr[16]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004BBE0:
    // 8004BBE0: li      r18, 0
    ctx->gpr[18] = (u32)(s32)(0);

label_8004BBE4:
    // 8004BBE4: bc    4, 1, 0x8004BBF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004BBF4;
        }
    }

label_8004BBE8:
    ctx->pc = 0x8004BBE8u;
    ctx->downcount -= 3;
    // 8004BBE8: lbz     r18, 1(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1);
        ctx->gpr[18] = mem_read8(ctx, ea);
    }

label_8004BBEC:
    // 8004BBEC: subfic  r17, r7, 8
    {
        u64 res = (u64)(u32)(s32)(8) + (u64)(~ctx->gpr[7]) + 1u;
        ctx->gpr[17] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8004BBF0:
    // 8004BBF0: slw   r18, r18, r17
    {
        u32 sh = ctx->gpr[17] & 0x3Fu;
        ctx->gpr[18] = sh > 31 ? 0u : (ctx->gpr[18] << sh);
    }

label_8004BBF4:
    ctx->pc = 0x8004BBF4u;
    ctx->downcount -= 27;
    // 8004BBF4: lbz     r17, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[17] = mem_read8(ctx, ea);
    }

label_8004BBF8:
    // 8004BBF8: rlwnm r17, r17, r15, 24, 31
    {
        ctx->gpr[17] = dolrecomp_rotl32(ctx->gpr[17], ctx->gpr[15]) & 0x000000FFu;
    }

label_8004BBFC:
    // 8004BBFC: or   r17, r17, r18
    {
        ctx->gpr[17] = ctx->gpr[17] | ctx->gpr[18];
    }

label_8004BC00:
    // 8004BC00: li      r18, 1
    ctx->gpr[18] = (u32)(s32)(1);

label_8004BC04:
    // 8004BC04: slw   r18, r18, r4
    {
        u32 sh = ctx->gpr[4] & 0x3Fu;
        ctx->gpr[18] = sh > 31 ? 0u : (ctx->gpr[18] << sh);
    }

label_8004BC08:
    // 8004BC08: addi    r18, r18, -1
    ctx->gpr[18] = ctx->gpr[18] + (u32)(s32)(-1);

label_8004BC0C:
    // 8004BC0C: and   r27, r17, r18
    {
        ctx->gpr[27] = ctx->gpr[17] & ctx->gpr[18];
    }

label_8004BC10:
    // 8004BC10: lis     r31, -32719
    ctx->gpr[31] = ((u32)(s32)(-32719) << 16);

label_8004BC14:
    // 8004BC14: addi    r31, r31, -6720
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(-6720);

label_8004BC18:
    // 8004BC18: addi    r17, r4, 24
    ctx->gpr[17] = ctx->gpr[4] + (u32)(s32)(24);

label_8004BC1C:
    ctx->pc = 0x8004BC1Cu;
    // 8004BC1C: lbzx    r16, r27, r31
    {
        u32 ea = ctx->gpr[27] + ctx->gpr[31];
        ctx->gpr[16] = mem_read8(ctx, ea);
    }

label_8004BC20:
    // 8004BC20: rlwnm r27, r16, r17, 24, 31
    {
        ctx->gpr[27] = dolrecomp_rotl32(ctx->gpr[16], ctx->gpr[17]) & 0x000000FFu;
    }

label_8004BC24:
    // 8004BC24: lis     r16, -32712
    ctx->gpr[16] = ((u32)(s32)(-32712) << 16);

label_8004BC28:
    // 8004BC28: addi    r16, r16, -28108
    ctx->gpr[16] = ctx->gpr[16] + (u32)(s32)(-28108);

label_8004BC2C:
    // 8004BC2C: add   r16, r16, r27
    {
        u32 a = ctx->gpr[16];
        u32 b = ctx->gpr[27];
        u32 res = a + b;
        ctx->gpr[16] = res;
    }

label_8004BC30:
    ctx->pc = 0x8004BC30u;
    // 8004BC30: lbz     r28, 0(r16)
    {
        u32 ea = ctx->gpr[16] + (u32)(s32)(0);
        ctx->gpr[28] = mem_read8(ctx, ea);
    }

label_8004BC34:
    // 8004BC34: lis     r16, -32712
    ctx->gpr[16] = ((u32)(s32)(-32712) << 16);

label_8004BC38:
    // 8004BC38: addi    r16, r16, -28192
    ctx->gpr[16] = ctx->gpr[16] + (u32)(s32)(-28192);

label_8004BC3C:
    // 8004BC3C: add   r16, r16, r28
    {
        u32 a = ctx->gpr[16];
        u32 b = ctx->gpr[28];
        u32 res = a + b;
        ctx->gpr[16] = res;
    }

label_8004BC40:
    ctx->pc = 0x8004BC40u;
    // 8004BC40: lbz     r16, 0(r16)
    {
        u32 ea = ctx->gpr[16] + (u32)(s32)(0);
        ctx->gpr[16] = mem_read8(ctx, ea);
    }

label_8004BC44:
    // 8004BC44: add   r7, r7, r16
    {
        u32 a = ctx->gpr[7];
        u32 b = ctx->gpr[16];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_8004BC48:
    // 8004BC48: srawi r17, r7, 3
    {
        u32 sh = 3u;
        u32 value = ctx->gpr[7];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[17] = value;
        } else if (sh > 31) {
            ctx->gpr[17] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[17] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_8004BC4C:
    // 8004BC4C: add   r3, r3, r17
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[17];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8004BC50:
    // 8004BC50: andi.   r7, r7, 0x0007
    {
        ctx->gpr[7] = ctx->gpr[7] & 0x0007u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[7];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8004BC54:
    // 8004BC54: cmpwi   r28, 16
    {
        s32 val_a = (s32)(ctx->gpr[28]);
        s32 val_b = (s32)(16);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004BC58:
    // 8004BC58: subfic  r15, r7, 32
    {
        u64 res = (u64)(u32)(s32)(32) + (u64)(~ctx->gpr[7]) + 1u;
        ctx->gpr[15] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8004BC5C:
    // 8004BC5C: bc    4, 2, 0x8004BC98
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004BC98;
        }
    }

label_8004BC60:
    ctx->pc = 0x8004BC60u;
    ctx->downcount -= 14;
    // 8004BC60: lbz     r18, 1(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1);
        ctx->gpr[18] = mem_read8(ctx, ea);
    }

label_8004BC64:
    // 8004BC64: subfic  r17, r7, 8
    {
        u64 res = (u64)(u32)(s32)(8) + (u64)(~ctx->gpr[7]) + 1u;
        ctx->gpr[17] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8004BC68:
    // 8004BC68: slw   r18, r18, r17
    {
        u32 sh = ctx->gpr[17] & 0x3Fu;
        ctx->gpr[18] = sh > 31 ? 0u : (ctx->gpr[18] << sh);
    }

label_8004BC6C:
    ctx->pc = 0x8004BC6Cu;
    // 8004BC6C: lbz     r17, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[17] = mem_read8(ctx, ea);
    }

label_8004BC70:
    // 8004BC70: rlwnm r17, r17, r15, 24, 31
    {
        ctx->gpr[17] = dolrecomp_rotl32(ctx->gpr[17], ctx->gpr[15]) & 0x000000FFu;
    }

label_8004BC74:
    // 8004BC74: or   r17, r17, r18
    {
        ctx->gpr[17] = ctx->gpr[17] | ctx->gpr[18];
    }

label_8004BC78:
    // 8004BC78: andi.   r17, r17, 0x0003
    {
        ctx->gpr[17] = ctx->gpr[17] & 0x0003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[17];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8004BC7C:
    // 8004BC7C: addi    r7, r7, 2
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(2);

label_8004BC80:
    // 8004BC80: addi    r30, r17, 3
    ctx->gpr[30] = ctx->gpr[17] + (u32)(s32)(3);

label_8004BC84:
    // 8004BC84: srawi r17, r7, 3
    {
        u32 sh = 3u;
        u32 value = ctx->gpr[7];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[17] = value;
        } else if (sh > 31) {
            ctx->gpr[17] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[17] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_8004BC88:
    // 8004BC88: add   r3, r3, r17
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[17];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8004BC8C:
    // 8004BC8C: andi.   r7, r7, 0x0007
    {
        ctx->gpr[7] = ctx->gpr[7] & 0x0007u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[7];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8004BC90:
    // 8004BC90: subfic  r15, r7, 32
    {
        u64 res = (u64)(u32)(s32)(32) + (u64)(~ctx->gpr[7]) + 1u;
        ctx->gpr[15] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8004BC94:
    // 8004BC94: b       0x8004BD28
    {
            goto label_8004BD28;
    }

label_8004BC98:
    ctx->downcount -= 2;
    // 8004BC98: cmpwi   r28, 17
    {
        s32 val_a = (s32)(ctx->gpr[28]);
        s32 val_b = (s32)(17);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004BC9C:
    // 8004BC9C: bc    4, 2, 0x8004BCDC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004BCDC;
        }
    }

label_8004BCA0:
    ctx->downcount -= 15;
    // 8004BCA0: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_8004BCA4:
    ctx->pc = 0x8004BCA4u;
    // 8004BCA4: lbz     r18, 1(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1);
        ctx->gpr[18] = mem_read8(ctx, ea);
    }

label_8004BCA8:
    // 8004BCA8: subfic  r17, r7, 8
    {
        u64 res = (u64)(u32)(s32)(8) + (u64)(~ctx->gpr[7]) + 1u;
        ctx->gpr[17] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8004BCAC:
    // 8004BCAC: slw   r18, r18, r17
    {
        u32 sh = ctx->gpr[17] & 0x3Fu;
        ctx->gpr[18] = sh > 31 ? 0u : (ctx->gpr[18] << sh);
    }

label_8004BCB0:
    ctx->pc = 0x8004BCB0u;
    // 8004BCB0: lbz     r17, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[17] = mem_read8(ctx, ea);
    }

label_8004BCB4:
    // 8004BCB4: rlwnm r17, r17, r15, 24, 31
    {
        ctx->gpr[17] = dolrecomp_rotl32(ctx->gpr[17], ctx->gpr[15]) & 0x000000FFu;
    }

label_8004BCB8:
    // 8004BCB8: or   r17, r17, r18
    {
        ctx->gpr[17] = ctx->gpr[17] | ctx->gpr[18];
    }

label_8004BCBC:
    // 8004BCBC: andi.   r17, r17, 0x0007
    {
        ctx->gpr[17] = ctx->gpr[17] & 0x0007u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[17];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8004BCC0:
    // 8004BCC0: addi    r7, r7, 3
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(3);

label_8004BCC4:
    // 8004BCC4: addi    r30, r17, 3
    ctx->gpr[30] = ctx->gpr[17] + (u32)(s32)(3);

label_8004BCC8:
    // 8004BCC8: srawi r17, r7, 3
    {
        u32 sh = 3u;
        u32 value = ctx->gpr[7];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[17] = value;
        } else if (sh > 31) {
            ctx->gpr[17] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[17] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_8004BCCC:
    // 8004BCCC: add   r3, r3, r17
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[17];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8004BCD0:
    // 8004BCD0: andi.   r7, r7, 0x0007
    {
        ctx->gpr[7] = ctx->gpr[7] & 0x0007u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[7];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8004BCD4:
    // 8004BCD4: subfic  r15, r7, 32
    {
        u64 res = (u64)(u32)(s32)(32) + (u64)(~ctx->gpr[7]) + 1u;
        ctx->gpr[15] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8004BCD8:
    // 8004BCD8: b       0x8004BD28
    {
            goto label_8004BD28;
    }

label_8004BCDC:
    ctx->downcount -= 2;
    // 8004BCDC: cmpwi   r28, 18
    {
        s32 val_a = (s32)(ctx->gpr[28]);
        s32 val_b = (s32)(18);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004BCE0:
    // 8004BCE0: bc    4, 2, 0x8004BD20
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004BD20;
        }
    }

label_8004BCE4:
    ctx->downcount -= 15;
    // 8004BCE4: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_8004BCE8:
    ctx->pc = 0x8004BCE8u;
    // 8004BCE8: lbz     r18, 1(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1);
        ctx->gpr[18] = mem_read8(ctx, ea);
    }

label_8004BCEC:
    // 8004BCEC: subfic  r17, r7, 8
    {
        u64 res = (u64)(u32)(s32)(8) + (u64)(~ctx->gpr[7]) + 1u;
        ctx->gpr[17] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8004BCF0:
    // 8004BCF0: slw   r18, r18, r17
    {
        u32 sh = ctx->gpr[17] & 0x3Fu;
        ctx->gpr[18] = sh > 31 ? 0u : (ctx->gpr[18] << sh);
    }

label_8004BCF4:
    ctx->pc = 0x8004BCF4u;
    // 8004BCF4: lbz     r17, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[17] = mem_read8(ctx, ea);
    }

label_8004BCF8:
    // 8004BCF8: rlwnm r17, r17, r15, 24, 31
    {
        ctx->gpr[17] = dolrecomp_rotl32(ctx->gpr[17], ctx->gpr[15]) & 0x000000FFu;
    }

label_8004BCFC:
    // 8004BCFC: or   r17, r17, r18
    {
        ctx->gpr[17] = ctx->gpr[17] | ctx->gpr[18];
    }

label_8004BD00:
    // 8004BD00: andi.   r17, r17, 0x007F
    {
        ctx->gpr[17] = ctx->gpr[17] & 0x007Fu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[17];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8004BD04:
    // 8004BD04: addi    r7, r7, 7
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(7);

label_8004BD08:
    // 8004BD08: addi    r30, r17, 11
    ctx->gpr[30] = ctx->gpr[17] + (u32)(s32)(11);

label_8004BD0C:
    // 8004BD0C: srawi r17, r7, 3
    {
        u32 sh = 3u;
        u32 value = ctx->gpr[7];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[17] = value;
        } else if (sh > 31) {
            ctx->gpr[17] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[17] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_8004BD10:
    // 8004BD10: add   r3, r3, r17
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[17];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8004BD14:
    // 8004BD14: andi.   r7, r7, 0x0007
    {
        ctx->gpr[7] = ctx->gpr[7] & 0x0007u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[7];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8004BD18:
    // 8004BD18: subfic  r15, r7, 32
    {
        u64 res = (u64)(u32)(s32)(32) + (u64)(~ctx->gpr[7]) + 1u;
        ctx->gpr[15] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8004BD1C:
    // 8004BD1C: b       0x8004BD28
    {
            goto label_8004BD28;
    }

label_8004BD20:
    ctx->downcount -= 2;
    // 8004BD20: or   r29, r28, r28
    {
        ctx->gpr[29] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8004BD24:
    // 8004BD24: li      r30, 1
    ctx->gpr[30] = (u32)(s32)(1);

label_8004BD28:
    ctx->pc = 0x8004BD28u;
    ctx->downcount -= 9;
    // 8004BD28: stbx    r29, r19, r21
    {
        u32 ea = ctx->gpr[19] + ctx->gpr[21];
        mem_write8(ctx, ea, (u8)ctx->gpr[29]);
    }

label_8004BD2C:
    // 8004BD2C: addi    r21, r21, 1
    ctx->gpr[21] = ctx->gpr[21] + (u32)(s32)(1);

label_8004BD30:
    // 8004BD30: add   r16, r20, r29
    {
        u32 a = ctx->gpr[20];
        u32 b = ctx->gpr[29];
        u32 res = a + b;
        ctx->gpr[16] = res;
    }

label_8004BD34:
    // 8004BD34: add   r16, r16, r29
    {
        u32 a = ctx->gpr[16];
        u32 b = ctx->gpr[29];
        u32 res = a + b;
        ctx->gpr[16] = res;
    }

label_8004BD38:
    ctx->pc = 0x8004BD38u;
    // 8004BD38: lhz     r17, 0(r16)
    {
        u32 ea = ctx->gpr[16] + (u32)(s32)(0);
        ctx->gpr[17] = mem_read16(ctx, ea);
    }

label_8004BD3C:
    // 8004BD3C: addi    r17, r17, 1
    ctx->gpr[17] = ctx->gpr[17] + (u32)(s32)(1);

label_8004BD40:
    ctx->pc = 0x8004BD40u;
    // 8004BD40: sth     r17, 0(r16)
    {
        u32 ea = ctx->gpr[16] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[17]);
    }

label_8004BD44:
    // 8004BD44: cmpw    r19, r8
    {
        s32 val_a = (s32)(ctx->gpr[19]);
        s32 val_b = (s32)(ctx->gpr[8]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004BD48:
    // 8004BD48: bc    4, 2, 0x8004BD64
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004BD64;
        }
    }

label_8004BD4C:
    ctx->downcount -= 2;
    // 8004BD4C: cmpw    r21, r23
    {
        s32 val_a = (s32)(ctx->gpr[21]);
        s32 val_b = (s32)(ctx->gpr[23]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004BD50:
    // 8004BD50: bc    4, 2, 0x8004BD64
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004BD64;
        }
    }

label_8004BD54:
    ctx->downcount -= 4;
    // 8004BD54: or   r19, r11, r11
    {
        ctx->gpr[19] = ctx->gpr[11] | ctx->gpr[11];
    }

label_8004BD58:
    // 8004BD58: lis     r20, -32712
    ctx->gpr[20] = ((u32)(s32)(-32712) << 16);

label_8004BD5C:
    // 8004BD5C: addi    r20, r20, -28140
    ctx->gpr[20] = ctx->gpr[20] + (u32)(s32)(-28140);

label_8004BD60:
    // 8004BD60: li      r21, 0
    ctx->gpr[21] = (u32)(s32)(0);

label_8004BD64:
    ctx->pc = 0x8004BD64u;
    ctx->downcount -= 3;
    // 8004BD64: mcrxr   cr0
    {
        u32 bits = (ctx->xer >> 28) & 0xFu;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (bits << 28);
        ctx->xer &= ~0xE0000000u;
    }

label_8004BD68:
    // 8004BD68: addme.  r30, r30
    {
        u32 input = ctx->gpr[30];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 res = (u64)input + 0xFFFFFFFFull + carry;
        ctx->gpr[30] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | ((res >> 32) ? 0x20000000u : 0u);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[30];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8004BD6C:
    // 8004BD6C: bc    4, 2, 0x8004BD28
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004BD28u;
                return;
            }
            goto label_8004BD28;
        }
    }

label_8004BD70:
    ctx->downcount -= 2;
    // 8004BD70: cmpw    r19, r8
    {
        s32 val_a = (s32)(ctx->gpr[19]);
        s32 val_b = (s32)(ctx->gpr[8]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004BD74:
    // 8004BD74: bc    12, 2, 0x8004BBD8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004BBD8u;
                return;
            }
            goto label_8004BBD8;
        }
    }

label_8004BD78:
    ctx->downcount -= 2;
    // 8004BD78: cmpw    r21, r24
    {
        s32 val_a = (s32)(ctx->gpr[21]);
        s32 val_b = (s32)(ctx->gpr[24]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004BD7C:
    // 8004BD7C: bc    12, 0, 0x8004BBD8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004BBD8u;
                return;
            }
            goto label_8004BBD8;
        }
    }

label_8004BD80:
    ctx->downcount -= 5;
    // 8004BD80: li      r10, 15
    ctx->gpr[10] = (u32)(s32)(15);

label_8004BD84:
    // 8004BD84: lis     r16, -32712
    ctx->gpr[16] = ((u32)(s32)(-32712) << 16);

label_8004BD88:
    // 8004BD88: addi    r16, r16, -28172
    ctx->gpr[16] = ctx->gpr[16] + (u32)(s32)(-28172);

label_8004BD8C:
    // 8004BD8C: add   r18, r16, r10
    {
        u32 a = ctx->gpr[16];
        u32 b = ctx->gpr[10];
        u32 res = a + b;
        ctx->gpr[18] = res;
    }

label_8004BD90:
    // 8004BD90: add   r18, r18, r10
    {
        u32 a = ctx->gpr[18];
        u32 b = ctx->gpr[10];
        u32 res = a + b;
        ctx->gpr[18] = res;
    }

label_8004BD94:
    ctx->pc = 0x8004BD94u;
    ctx->downcount -= 3;
    // 8004BD94: lhz     r17, 0(r18)
    {
        u32 ea = ctx->gpr[18] + (u32)(s32)(0);
        ctx->gpr[17] = mem_read16(ctx, ea);
    }

label_8004BD98:
    // 8004BD98: cmpwi   r17, 0
    {
        s32 val_a = (s32)(ctx->gpr[17]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004BD9C:
    // 8004BD9C: bc    4, 2, 0x8004BDAC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004BDAC;
        }
    }

label_8004BDA0:
    ctx->downcount -= 3;
    // 8004BDA0: addi    r18, r18, -2
    ctx->gpr[18] = ctx->gpr[18] + (u32)(s32)(-2);

label_8004BDA4:
    // 8004BDA4: addi    r10, r10, -1
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(-1);

label_8004BDA8:
    // 8004BDA8: b       0x8004BD94
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004BD94u;
                return;
            }
            goto label_8004BD94;
    }

label_8004BDAC:
    ctx->downcount -= 5;
    // 8004BDAC: lis     r30, -32712
    ctx->gpr[30] = ((u32)(s32)(-32712) << 16);

label_8004BDB0:
    // 8004BDB0: addi    r30, r30, -27980
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-27980);

label_8004BDB4:
    // 8004BDB4: li      r26, 1
    ctx->gpr[26] = (u32)(s32)(1);

label_8004BDB8:
    // 8004BDB8: li      r22, 0
    ctx->gpr[22] = (u32)(s32)(0);

label_8004BDBC:
    // 8004BDBC: b       0x8004BDF0
    {
            goto label_8004BDF0;
    }

label_8004BDC0:
    ctx->downcount -= 5;
    // 8004BDC0: add   r17, r16, r26
    {
        u32 a = ctx->gpr[16];
        u32 b = ctx->gpr[26];
        u32 res = a + b;
        ctx->gpr[17] = res;
    }

label_8004BDC4:
    // 8004BDC4: add   r17, r17, r26
    {
        u32 a = ctx->gpr[17];
        u32 b = ctx->gpr[26];
        u32 res = a + b;
        ctx->gpr[17] = res;
    }

label_8004BDC8:
    ctx->pc = 0x8004BDC8u;
    // 8004BDC8: lhz     r17, 0(r17)
    {
        u32 ea = ctx->gpr[17] + (u32)(s32)(0);
        ctx->gpr[17] = mem_read16(ctx, ea);
    }

label_8004BDCC:
    // 8004BDCC: cmpwi   r17, 0
    {
        s32 val_a = (s32)(ctx->gpr[17]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004BDD0:
    // 8004BDD0: bc    12, 2, 0x8004BDEC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004BDEC;
        }
    }

label_8004BDD4:
    ctx->downcount -= 6;
    // 8004BDD4: add   r28, r30, r26
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[26];
        u32 res = a + b;
        ctx->gpr[28] = res;
    }

label_8004BDD8:
    // 8004BDD8: add   r28, r28, r26
    {
        u32 a = ctx->gpr[28];
        u32 b = ctx->gpr[26];
        u32 res = a + b;
        ctx->gpr[28] = res;
    }

label_8004BDDC:
    ctx->pc = 0x8004BDDCu;
    // 8004BDDC: sth     r22, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[22]);
    }

label_8004BDE0:
    // 8004BDE0: subf   r28, r26, r10
    {
        u32 a = ~ctx->gpr[26];
        u32 b = ctx->gpr[10];
        u32 res = a + b + 1u;
        ctx->gpr[28] = res;
    }

label_8004BDE4:
    // 8004BDE4: slw   r17, r17, r28
    {
        u32 sh = ctx->gpr[28] & 0x3Fu;
        ctx->gpr[17] = sh > 31 ? 0u : (ctx->gpr[17] << sh);
    }

label_8004BDE8:
    // 8004BDE8: add   r22, r22, r17
    {
        u32 a = ctx->gpr[22];
        u32 b = ctx->gpr[17];
        u32 res = a + b;
        ctx->gpr[22] = res;
    }

label_8004BDEC:
    ctx->downcount -= 1;
    // 8004BDEC: addi    r26, r26, 1
    ctx->gpr[26] = ctx->gpr[26] + (u32)(s32)(1);

label_8004BDF0:
    ctx->downcount -= 2;
    // 8004BDF0: cmpw    r26, r10
    {
        s32 val_a = (s32)(ctx->gpr[26]);
        s32 val_b = (s32)(ctx->gpr[10]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004BDF4:
    // 8004BDF4: bc    4, 1, 0x8004BDC0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004BDC0u;
                return;
            }
            goto label_8004BDC0;
        }
    }

label_8004BDF8:
    ctx->downcount -= 2;
    // 8004BDF8: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_8004BDFC:
    // 8004BDFC: b       0x8004BE54
    {
            goto label_8004BE54;
    }

label_8004BE00:
    ctx->pc = 0x8004BE00u;
    ctx->downcount -= 3;
    // 8004BE00: lbzx    r17, r8, r28
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[28];
        ctx->gpr[17] = mem_read8(ctx, ea);
    }

label_8004BE04:
    // 8004BE04: cmpwi   r17, 0
    {
        s32 val_a = (s32)(ctx->gpr[17]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004BE08:
    // 8004BE08: bc    12, 2, 0x8004BE50
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004BE50;
        }
    }

label_8004BE0C:
    ctx->downcount -= 2;
    // 8004BE0C: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_8004BE10:
    // 8004BE10: b       0x8004BE3C
    {
            goto label_8004BE3C;
    }

label_8004BE14:
    loop_8004BE14(ctx);
    if (ctx->pc == 0x8004BE50u) goto label_8004BE50;
    return;
label_8004BE18:
    // 8004BE18: add   r29, r18, r17
    {
        u32 a = ctx->gpr[18];
        u32 b = ctx->gpr[17];
        u32 res = a + b;
        ctx->gpr[29] = res;
    }

label_8004BE1C:
    ctx->pc = 0x8004BE1Cu;
    // 8004BE1C: lhz     r18, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[18] = mem_read16(ctx, ea);
    }

label_8004BE20:
    // 8004BE20: addi    r18, r18, 1
    ctx->gpr[18] = ctx->gpr[18] + (u32)(s32)(1);

label_8004BE24:
    ctx->pc = 0x8004BE24u;
    // 8004BE24: sth     r18, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[18]);
    }

label_8004BE28:
    // 8004BE28: addi    r18, r18, -1
    ctx->gpr[18] = ctx->gpr[18] + (u32)(s32)(-1);

label_8004BE2C:
    // 8004BE2C: add   r29, r9, r18
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[18];
        u32 res = a + b;
        ctx->gpr[29] = res;
    }

label_8004BE30:
    // 8004BE30: add   r29, r29, r18
    {
        u32 a = ctx->gpr[29];
        u32 b = ctx->gpr[18];
        u32 res = a + b;
        ctx->gpr[29] = res;
    }

label_8004BE34:
    ctx->pc = 0x8004BE34u;
    // 8004BE34: sth     r28, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[28]);
    }

label_8004BE38:
    // 8004BE38: addi    r31, r31, 1
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(1);

label_8004BE3C:
    ctx->downcount -= 5;
    // 8004BE3C: subf   r29, r17, r10
    {
        u32 a = ~ctx->gpr[17];
        u32 b = ctx->gpr[10];
        u32 res = a + b + 1u;
        ctx->gpr[29] = res;
    }

label_8004BE40:
    // 8004BE40: li      r18, 1
    ctx->gpr[18] = (u32)(s32)(1);

label_8004BE44:
    // 8004BE44: slw   r18, r18, r29
    {
        u32 sh = ctx->gpr[29] & 0x3Fu;
        ctx->gpr[18] = sh > 31 ? 0u : (ctx->gpr[18] << sh);
    }

label_8004BE48:
    // 8004BE48: cmpw    r31, r18
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(ctx->gpr[18]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004BE4C:
    // 8004BE4C: bc    12, 0, 0x8004BE14
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004BE14u;
                return;
            }
            goto label_8004BE14;
        }
    }

label_8004BE50:
    ctx->downcount -= 1;
    // 8004BE50: addi    r28, r28, 1
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(1);

label_8004BE54:
    ctx->downcount -= 2;
    // 8004BE54: cmpw    r28, r23
    {
        s32 val_a = (s32)(ctx->gpr[28]);
        s32 val_b = (s32)(ctx->gpr[23]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004BE58:
    // 8004BE58: bc    12, 0, 0x8004BE00
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004BE00u;
                return;
            }
            goto label_8004BE00;
        }
    }

label_8004BE5C:
    ctx->downcount -= 5;
    // 8004BE5C: li      r14, 15
    ctx->gpr[14] = (u32)(s32)(15);

label_8004BE60:
    // 8004BE60: lis     r16, -32712
    ctx->gpr[16] = ((u32)(s32)(-32712) << 16);

label_8004BE64:
    // 8004BE64: addi    r16, r16, -28140
    ctx->gpr[16] = ctx->gpr[16] + (u32)(s32)(-28140);

label_8004BE68:
    // 8004BE68: lis     r27, -32712
    ctx->gpr[27] = ((u32)(s32)(-32712) << 16);

label_8004BE6C:
    // 8004BE6C: addi    r27, r27, -27948
    ctx->gpr[27] = ctx->gpr[27] + (u32)(s32)(-27948);

label_8004BE70:
    ctx->downcount -= 5;
    // 8004BE70: add   r17, r16, r14
    {
        u32 a = ctx->gpr[16];
        u32 b = ctx->gpr[14];
        u32 res = a + b;
        ctx->gpr[17] = res;
    }

label_8004BE74:
    // 8004BE74: add   r17, r17, r14
    {
        u32 a = ctx->gpr[17];
        u32 b = ctx->gpr[14];
        u32 res = a + b;
        ctx->gpr[17] = res;
    }

label_8004BE78:
    ctx->pc = 0x8004BE78u;
    // 8004BE78: lhz     r18, 0(r17)
    {
        u32 ea = ctx->gpr[17] + (u32)(s32)(0);
        ctx->gpr[18] = mem_read16(ctx, ea);
    }

label_8004BE7C:
    // 8004BE7C: cmpwi   r18, 0
    {
        s32 val_a = (s32)(ctx->gpr[18]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004BE80:
    // 8004BE80: bc    4, 2, 0x8004BE8C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004BE8C;
        }
    }

label_8004BE84:
    ctx->downcount -= 2;
    // 8004BE84: addi    r14, r14, -1
    ctx->gpr[14] = ctx->gpr[14] + (u32)(s32)(-1);

label_8004BE88:
    // 8004BE88: b       0x8004BE70
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004BE70u;
                return;
            }
            goto label_8004BE70;
    }

label_8004BE8C:
    ctx->downcount -= 3;
    // 8004BE8C: li      r26, 1
    ctx->gpr[26] = (u32)(s32)(1);

label_8004BE90:
    // 8004BE90: li      r22, 0
    ctx->gpr[22] = (u32)(s32)(0);

label_8004BE94:
    // 8004BE94: b       0x8004BEC8
    {
            goto label_8004BEC8;
    }

label_8004BE98:
    ctx->downcount -= 5;
    // 8004BE98: add   r17, r16, r26
    {
        u32 a = ctx->gpr[16];
        u32 b = ctx->gpr[26];
        u32 res = a + b;
        ctx->gpr[17] = res;
    }

label_8004BE9C:
    // 8004BE9C: add   r17, r17, r26
    {
        u32 a = ctx->gpr[17];
        u32 b = ctx->gpr[26];
        u32 res = a + b;
        ctx->gpr[17] = res;
    }

label_8004BEA0:
    ctx->pc = 0x8004BEA0u;
    // 8004BEA0: lhz     r18, 0(r17)
    {
        u32 ea = ctx->gpr[17] + (u32)(s32)(0);
        ctx->gpr[18] = mem_read16(ctx, ea);
    }

label_8004BEA4:
    // 8004BEA4: cmpwi   r18, 0
    {
        s32 val_a = (s32)(ctx->gpr[18]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004BEA8:
    // 8004BEA8: bc    12, 2, 0x8004BEC4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004BEC4;
        }
    }

label_8004BEAC:
    ctx->downcount -= 6;
    // 8004BEAC: add   r17, r27, r26
    {
        u32 a = ctx->gpr[27];
        u32 b = ctx->gpr[26];
        u32 res = a + b;
        ctx->gpr[17] = res;
    }

label_8004BEB0:
    // 8004BEB0: add   r17, r17, r26
    {
        u32 a = ctx->gpr[17];
        u32 b = ctx->gpr[26];
        u32 res = a + b;
        ctx->gpr[17] = res;
    }

label_8004BEB4:
    ctx->pc = 0x8004BEB4u;
    // 8004BEB4: sth     r22, 0(r17)
    {
        u32 ea = ctx->gpr[17] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[22]);
    }

label_8004BEB8:
    // 8004BEB8: subf   r28, r26, r14
    {
        u32 a = ~ctx->gpr[26];
        u32 b = ctx->gpr[14];
        u32 res = a + b + 1u;
        ctx->gpr[28] = res;
    }

label_8004BEBC:
    // 8004BEBC: slw   r18, r18, r28
    {
        u32 sh = ctx->gpr[28] & 0x3Fu;
        ctx->gpr[18] = sh > 31 ? 0u : (ctx->gpr[18] << sh);
    }

label_8004BEC0:
    // 8004BEC0: add   r22, r22, r18
    {
        u32 a = ctx->gpr[22];
        u32 b = ctx->gpr[18];
        u32 res = a + b;
        ctx->gpr[22] = res;
    }

label_8004BEC4:
    ctx->downcount -= 1;
    // 8004BEC4: addi    r26, r26, 1
    ctx->gpr[26] = ctx->gpr[26] + (u32)(s32)(1);

label_8004BEC8:
    ctx->downcount -= 2;
    // 8004BEC8: cmpw    r26, r14
    {
        s32 val_a = (s32)(ctx->gpr[26]);
        s32 val_b = (s32)(ctx->gpr[14]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004BECC:
    // 8004BECC: bc    4, 1, 0x8004BE98
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004BE98u;
                return;
            }
            goto label_8004BE98;
        }
    }

label_8004BED0:
    ctx->downcount -= 2;
    // 8004BED0: li      r26, 0
    ctx->gpr[26] = (u32)(s32)(0);

label_8004BED4:
    // 8004BED4: b       0x8004BF24
    {
            goto label_8004BF24;
    }

label_8004BED8:
    ctx->pc = 0x8004BED8u;
    ctx->downcount -= 3;
    // 8004BED8: lbzx    r17, r11, r26
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[26];
        ctx->gpr[17] = mem_read8(ctx, ea);
    }

label_8004BEDC:
    // 8004BEDC: cmpwi   r17, 0
    {
        s32 val_a = (s32)(ctx->gpr[17]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004BEE0:
    // 8004BEE0: bc    12, 2, 0x8004BF20
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004BF20;
        }
    }

label_8004BEE4:
    ctx->downcount -= 2;
    // 8004BEE4: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_8004BEE8:
    // 8004BEE8: b       0x8004BF0C
    {
            goto label_8004BF0C;
    }

label_8004BEEC:
    loop_8004BEEC(ctx);
    if (ctx->pc == 0x8004BF20u) goto label_8004BF20;
    return;
label_8004BEF0:
    // 8004BEF0: add   r18, r18, r17
    {
        u32 a = ctx->gpr[18];
        u32 b = ctx->gpr[17];
        u32 res = a + b;
        ctx->gpr[18] = res;
    }

label_8004BEF4:
    ctx->pc = 0x8004BEF4u;
    // 8004BEF4: lhz     r28, 0(r18)
    {
        u32 ea = ctx->gpr[18] + (u32)(s32)(0);
        ctx->gpr[28] = mem_read16(ctx, ea);
    }

label_8004BEF8:
    // 8004BEF8: addi    r28, r28, 1
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(1);

label_8004BEFC:
    ctx->pc = 0x8004BEFCu;
    // 8004BEFC: sth     r28, 0(r18)
    {
        u32 ea = ctx->gpr[18] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[28]);
    }

label_8004BF00:
    // 8004BF00: addi    r28, r28, -1
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(-1);

label_8004BF04:
    ctx->pc = 0x8004BF04u;
    // 8004BF04: stbx    r26, r12, r28
    {
        u32 ea = ctx->gpr[12] + ctx->gpr[28];
        mem_write8(ctx, ea, (u8)ctx->gpr[26]);
    }

label_8004BF08:
    // 8004BF08: addi    r31, r31, 1
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(1);

label_8004BF0C:
    ctx->downcount -= 5;
    // 8004BF0C: subf   r18, r17, r14
    {
        u32 a = ~ctx->gpr[17];
        u32 b = ctx->gpr[14];
        u32 res = a + b + 1u;
        ctx->gpr[18] = res;
    }

label_8004BF10:
    // 8004BF10: li      r29, 1
    ctx->gpr[29] = (u32)(s32)(1);

label_8004BF14:
    // 8004BF14: slw   r18, r29, r18
    {
        u32 sh = ctx->gpr[18] & 0x3Fu;
        ctx->gpr[18] = sh > 31 ? 0u : (ctx->gpr[29] << sh);
    }

label_8004BF18:
    // 8004BF18: cmpw    r31, r18
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(ctx->gpr[18]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004BF1C:
    // 8004BF1C: bc    12, 0, 0x8004BEEC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004BEECu;
                return;
            }
            goto label_8004BEEC;
        }
    }

label_8004BF20:
    ctx->downcount -= 1;
    // 8004BF20: addi    r26, r26, 1
    ctx->gpr[26] = ctx->gpr[26] + (u32)(s32)(1);

label_8004BF24:
    ctx->downcount -= 2;
    // 8004BF24: cmpw    r26, r24
    {
        s32 val_a = (s32)(ctx->gpr[26]);
        s32 val_b = (s32)(ctx->gpr[24]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004BF28:
    // 8004BF28: bc    12, 0, 0x8004BED8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004BED8u;
                return;
            }
            goto label_8004BED8;
        }
    }

label_8004BF2C:
    ctx->downcount -= 37;
    // 8004BF2C: lis     r31, -32719
    ctx->gpr[31] = ((u32)(s32)(-32719) << 16);

label_8004BF30:
    // 8004BF30: addi    r31, r31, -6720
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(-6720);

label_8004BF34:
    ctx->pc = 0x8004BF34u;
    // 8004BF34: lbz     r19, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        ctx->gpr[19] = mem_read8(ctx, ea);
    }

label_8004BF38:
    // 8004BF38: subfic  r17, r7, 16
    {
        u64 res = (u64)(u32)(s32)(16) + (u64)(~ctx->gpr[7]) + 1u;
        ctx->gpr[17] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8004BF3C:
    // 8004BF3C: slw   r19, r19, r17
    {
        u32 sh = ctx->gpr[17] & 0x3Fu;
        ctx->gpr[19] = sh > 31 ? 0u : (ctx->gpr[19] << sh);
    }

label_8004BF40:
    ctx->pc = 0x8004BF40u;
    // 8004BF40: lbz     r18, 1(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1);
        ctx->gpr[18] = mem_read8(ctx, ea);
    }

label_8004BF44:
    // 8004BF44: subfic  r17, r7, 8
    {
        u64 res = (u64)(u32)(s32)(8) + (u64)(~ctx->gpr[7]) + 1u;
        ctx->gpr[17] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8004BF48:
    // 8004BF48: slw   r18, r18, r17
    {
        u32 sh = ctx->gpr[17] & 0x3Fu;
        ctx->gpr[18] = sh > 31 ? 0u : (ctx->gpr[18] << sh);
    }

label_8004BF4C:
    ctx->pc = 0x8004BF4Cu;
    // 8004BF4C: lbz     r17, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[17] = mem_read8(ctx, ea);
    }

label_8004BF50:
    // 8004BF50: rlwnm r17, r17, r15, 24, 31
    {
        ctx->gpr[17] = dolrecomp_rotl32(ctx->gpr[17], ctx->gpr[15]) & 0x000000FFu;
    }

label_8004BF54:
    // 8004BF54: or   r17, r17, r18
    {
        ctx->gpr[17] = ctx->gpr[17] | ctx->gpr[18];
    }

label_8004BF58:
    // 8004BF58: or   r17, r17, r19
    {
        ctx->gpr[17] = ctx->gpr[17] | ctx->gpr[19];
    }

label_8004BF5C:
    // 8004BF5C: li      r18, 1
    ctx->gpr[18] = (u32)(s32)(1);

label_8004BF60:
    // 8004BF60: slw   r18, r18, r10
    {
        u32 sh = ctx->gpr[10] & 0x3Fu;
        ctx->gpr[18] = sh > 31 ? 0u : (ctx->gpr[18] << sh);
    }

label_8004BF64:
    // 8004BF64: addi    r18, r18, -1
    ctx->gpr[18] = ctx->gpr[18] + (u32)(s32)(-1);

label_8004BF68:
    // 8004BF68: and   r24, r17, r18
    {
        ctx->gpr[24] = ctx->gpr[17] & ctx->gpr[18];
    }

label_8004BF6C:
    // 8004BF6C: addi    r17, r10, -8
    ctx->gpr[17] = ctx->gpr[10] + (u32)(s32)(-8);

label_8004BF70:
    // 8004BF70: andi.   r16, r24, 0x00FF
    {
        ctx->gpr[16] = ctx->gpr[24] & 0x00FFu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[16];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8004BF74:
    ctx->pc = 0x8004BF74u;
    // 8004BF74: lbzx    r16, r16, r31
    {
        u32 ea = ctx->gpr[16] + ctx->gpr[31];
        ctx->gpr[16] = mem_read8(ctx, ea);
    }

label_8004BF78:
    // 8004BF78: rlwinm r24, r24, 24, 8, 31
    {
        ctx->gpr[24] = dolrecomp_rotl32(ctx->gpr[24], 24u) & 0x00FFFFFFu;
    }

label_8004BF7C:
    // 8004BF7C: rlwnm r16, r16, r17, 16, 31
    {
        ctx->gpr[16] = dolrecomp_rotl32(ctx->gpr[16], ctx->gpr[17]) & 0x0000FFFFu;
    }

label_8004BF80:
    // 8004BF80: addi    r17, r10, 16
    ctx->gpr[17] = ctx->gpr[10] + (u32)(s32)(16);

label_8004BF84:
    ctx->pc = 0x8004BF84u;
    // 8004BF84: lbzx    r24, r24, r31
    {
        u32 ea = ctx->gpr[24] + ctx->gpr[31];
        ctx->gpr[24] = mem_read8(ctx, ea);
    }

label_8004BF88:
    // 8004BF88: rlwnm r17, r24, r17, 24, 31
    {
        ctx->gpr[17] = dolrecomp_rotl32(ctx->gpr[24], ctx->gpr[17]) & 0x000000FFu;
    }

label_8004BF8C:
    // 8004BF8C: or   r24, r16, r17
    {
        ctx->gpr[24] = ctx->gpr[16] | ctx->gpr[17];
    }

label_8004BF90:
    // 8004BF90: add   r16, r9, r24
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[24];
        u32 res = a + b;
        ctx->gpr[16] = res;
    }

label_8004BF94:
    // 8004BF94: add   r16, r16, r24
    {
        u32 a = ctx->gpr[16];
        u32 b = ctx->gpr[24];
        u32 res = a + b;
        ctx->gpr[16] = res;
    }

label_8004BF98:
    ctx->pc = 0x8004BF98u;
    // 8004BF98: lhz     r25, 0(r16)
    {
        u32 ea = ctx->gpr[16] + (u32)(s32)(0);
        ctx->gpr[25] = mem_read16(ctx, ea);
    }

label_8004BF9C:
    // 8004BF9C: add   r16, r8, r25
    {
        u32 a = ctx->gpr[8];
        u32 b = ctx->gpr[25];
        u32 res = a + b;
        ctx->gpr[16] = res;
    }

label_8004BFA0:
    ctx->pc = 0x8004BFA0u;
    // 8004BFA0: lbz     r28, 0(r16)
    {
        u32 ea = ctx->gpr[16] + (u32)(s32)(0);
        ctx->gpr[28] = mem_read8(ctx, ea);
    }

label_8004BFA4:
    // 8004BFA4: add   r7, r7, r28
    {
        u32 a = ctx->gpr[7];
        u32 b = ctx->gpr[28];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_8004BFA8:
    // 8004BFA8: srawi r17, r7, 3
    {
        u32 sh = 3u;
        u32 value = ctx->gpr[7];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[17] = value;
        } else if (sh > 31) {
            ctx->gpr[17] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[17] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_8004BFAC:
    // 8004BFAC: add   r3, r3, r17
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[17];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8004BFB0:
    // 8004BFB0: andi.   r7, r7, 0x0007
    {
        ctx->gpr[7] = ctx->gpr[7] & 0x0007u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[7];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8004BFB4:
    // 8004BFB4: subfic  r15, r7, 32
    {
        u64 res = (u64)(u32)(s32)(32) + (u64)(~ctx->gpr[7]) + 1u;
        ctx->gpr[15] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8004BFB8:
    // 8004BFB8: cmpwi   r25, 256
    {
        s32 val_a = (s32)(ctx->gpr[25]);
        s32 val_b = (s32)(256);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004BFBC:
    // 8004BFBC: bc    4, 0, 0x8004BFC8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004BFC8;
        }
    }

label_8004BFC0:
    ctx->pc = 0x8004BFC0u;
    ctx->downcount -= 2;
    // 8004BFC0: stbu     r25, 1(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1);
        mem_write8(ctx, ea, (u8)ctx->gpr[25]);
        ctx->gpr[5] = ea;
    }

label_8004BFC4:
    // 8004BFC4: b       0x8004C140
    {
            goto label_8004C140;
    }

label_8004BFC8:
    ctx->downcount -= 1;
    // 8004BFC8: bc    12, 2, 0x8004C148
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004C148;
        }
    }

label_8004BFCC:
    ctx->downcount -= 9;
    // 8004BFCC: addi    r16, r25, -257
    ctx->gpr[16] = ctx->gpr[25] + (u32)(s32)(-257);

label_8004BFD0:
    // 8004BFD0: rlwinm r16, r16, 2, 0, 29
    {
        ctx->gpr[16] = dolrecomp_rotl32(ctx->gpr[16], 2u) & 0xFFFFFFFCu;
    }

label_8004BFD4:
    // 8004BFD4: lis     r17, -32724
    ctx->gpr[17] = ((u32)(s32)(-32724) << 16);

label_8004BFD8:
    // 8004BFD8: addi    r17, r17, 9700
    ctx->gpr[17] = ctx->gpr[17] + (u32)(s32)(9700);

label_8004BFDC:
    ctx->pc = 0x8004BFDCu;
    // 8004BFDC: lhzx    r30, r17, r16
    {
        u32 ea = ctx->gpr[17] + ctx->gpr[16];
        ctx->gpr[30] = mem_read16(ctx, ea);
    }

label_8004BFE0:
    // 8004BFE0: addi    r17, r17, 2
    ctx->gpr[17] = ctx->gpr[17] + (u32)(s32)(2);

label_8004BFE4:
    ctx->pc = 0x8004BFE4u;
    // 8004BFE4: lhzx    r29, r17, r16
    {
        u32 ea = ctx->gpr[17] + ctx->gpr[16];
        ctx->gpr[29] = mem_read16(ctx, ea);
    }

label_8004BFE8:
    // 8004BFE8: cmpwi   r29, 0
    {
        s32 val_a = (s32)(ctx->gpr[29]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004BFEC:
    // 8004BFEC: bc    12, 2, 0x8004C030
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004C030;
        }
    }

label_8004BFF0:
    ctx->pc = 0x8004BFF0u;
    ctx->downcount -= 16;
    // 8004BFF0: lbz     r18, 1(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1);
        ctx->gpr[18] = mem_read8(ctx, ea);
    }

label_8004BFF4:
    // 8004BFF4: subfic  r17, r7, 8
    {
        u64 res = (u64)(u32)(s32)(8) + (u64)(~ctx->gpr[7]) + 1u;
        ctx->gpr[17] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8004BFF8:
    // 8004BFF8: slw   r18, r18, r17
    {
        u32 sh = ctx->gpr[17] & 0x3Fu;
        ctx->gpr[18] = sh > 31 ? 0u : (ctx->gpr[18] << sh);
    }

label_8004BFFC:
    ctx->pc = 0x8004BFFCu;
    // 8004BFFC: lbz     r17, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[17] = mem_read8(ctx, ea);
    }

label_8004C000:
    // 8004C000: rlwnm r17, r17, r15, 24, 31
    {
        ctx->gpr[17] = dolrecomp_rotl32(ctx->gpr[17], ctx->gpr[15]) & 0x000000FFu;
    }

label_8004C004:
    // 8004C004: or   r17, r17, r18
    {
        ctx->gpr[17] = ctx->gpr[17] | ctx->gpr[18];
    }

label_8004C008:
    // 8004C008: li      r18, 1
    ctx->gpr[18] = (u32)(s32)(1);

label_8004C00C:
    // 8004C00C: slw   r18, r18, r29
    {
        u32 sh = ctx->gpr[29] & 0x3Fu;
        ctx->gpr[18] = sh > 31 ? 0u : (ctx->gpr[18] << sh);
    }

label_8004C010:
    // 8004C010: addi    r18, r18, -1
    ctx->gpr[18] = ctx->gpr[18] + (u32)(s32)(-1);

label_8004C014:
    // 8004C014: and   r16, r17, r18
    {
        ctx->gpr[16] = ctx->gpr[17] & ctx->gpr[18];
    }

label_8004C018:
    // 8004C018: add   r30, r30, r16
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[16];
        u32 res = a + b;
        ctx->gpr[30] = res;
    }

label_8004C01C:
    // 8004C01C: add   r7, r7, r29
    {
        u32 a = ctx->gpr[7];
        u32 b = ctx->gpr[29];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_8004C020:
    // 8004C020: srawi r17, r7, 3
    {
        u32 sh = 3u;
        u32 value = ctx->gpr[7];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[17] = value;
        } else if (sh > 31) {
            ctx->gpr[17] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[17] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_8004C024:
    // 8004C024: add   r3, r3, r17
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[17];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8004C028:
    // 8004C028: andi.   r7, r7, 0x0007
    {
        ctx->gpr[7] = ctx->gpr[7] & 0x0007u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[7];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8004C02C:
    // 8004C02C: subfic  r15, r7, 32
    {
        u64 res = (u64)(u32)(s32)(32) + (u64)(~ctx->gpr[7]) + 1u;
        ctx->gpr[15] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8004C030:
    ctx->downcount -= 43;
    // 8004C030: lis     r31, -32719
    ctx->gpr[31] = ((u32)(s32)(-32719) << 16);

label_8004C034:
    // 8004C034: addi    r31, r31, -6720
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(-6720);

label_8004C038:
    ctx->pc = 0x8004C038u;
    // 8004C038: lbz     r19, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        ctx->gpr[19] = mem_read8(ctx, ea);
    }

label_8004C03C:
    // 8004C03C: subfic  r17, r7, 16
    {
        u64 res = (u64)(u32)(s32)(16) + (u64)(~ctx->gpr[7]) + 1u;
        ctx->gpr[17] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8004C040:
    // 8004C040: slw   r19, r19, r17
    {
        u32 sh = ctx->gpr[17] & 0x3Fu;
        ctx->gpr[19] = sh > 31 ? 0u : (ctx->gpr[19] << sh);
    }

label_8004C044:
    ctx->pc = 0x8004C044u;
    // 8004C044: lbz     r18, 1(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1);
        ctx->gpr[18] = mem_read8(ctx, ea);
    }

label_8004C048:
    // 8004C048: subfic  r17, r7, 8
    {
        u64 res = (u64)(u32)(s32)(8) + (u64)(~ctx->gpr[7]) + 1u;
        ctx->gpr[17] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8004C04C:
    // 8004C04C: slw   r18, r18, r17
    {
        u32 sh = ctx->gpr[17] & 0x3Fu;
        ctx->gpr[18] = sh > 31 ? 0u : (ctx->gpr[18] << sh);
    }

label_8004C050:
    ctx->pc = 0x8004C050u;
    // 8004C050: lbz     r17, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[17] = mem_read8(ctx, ea);
    }

label_8004C054:
    // 8004C054: rlwnm r17, r17, r15, 24, 31
    {
        ctx->gpr[17] = dolrecomp_rotl32(ctx->gpr[17], ctx->gpr[15]) & 0x000000FFu;
    }

label_8004C058:
    // 8004C058: or   r17, r17, r18
    {
        ctx->gpr[17] = ctx->gpr[17] | ctx->gpr[18];
    }

label_8004C05C:
    // 8004C05C: or   r17, r17, r19
    {
        ctx->gpr[17] = ctx->gpr[17] | ctx->gpr[19];
    }

label_8004C060:
    // 8004C060: li      r18, 1
    ctx->gpr[18] = (u32)(s32)(1);

label_8004C064:
    // 8004C064: slw   r18, r18, r14
    {
        u32 sh = ctx->gpr[14] & 0x3Fu;
        ctx->gpr[18] = sh > 31 ? 0u : (ctx->gpr[18] << sh);
    }

label_8004C068:
    // 8004C068: addi    r18, r18, -1
    ctx->gpr[18] = ctx->gpr[18] + (u32)(s32)(-1);

label_8004C06C:
    // 8004C06C: and   r26, r17, r18
    {
        ctx->gpr[26] = ctx->gpr[17] & ctx->gpr[18];
    }

label_8004C070:
    // 8004C070: addi    r17, r14, -8
    ctx->gpr[17] = ctx->gpr[14] + (u32)(s32)(-8);

label_8004C074:
    // 8004C074: andi.   r16, r26, 0x00FF
    {
        ctx->gpr[16] = ctx->gpr[26] & 0x00FFu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[16];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8004C078:
    ctx->pc = 0x8004C078u;
    // 8004C078: lbzx    r16, r16, r31
    {
        u32 ea = ctx->gpr[16] + ctx->gpr[31];
        ctx->gpr[16] = mem_read8(ctx, ea);
    }

label_8004C07C:
    // 8004C07C: rlwinm r26, r26, 24, 8, 31
    {
        ctx->gpr[26] = dolrecomp_rotl32(ctx->gpr[26], 24u) & 0x00FFFFFFu;
    }

label_8004C080:
    // 8004C080: rlwnm r16, r16, r17, 16, 31
    {
        ctx->gpr[16] = dolrecomp_rotl32(ctx->gpr[16], ctx->gpr[17]) & 0x0000FFFFu;
    }

label_8004C084:
    // 8004C084: addi    r17, r14, 16
    ctx->gpr[17] = ctx->gpr[14] + (u32)(s32)(16);

label_8004C088:
    ctx->pc = 0x8004C088u;
    // 8004C088: lbzx    r26, r26, r31
    {
        u32 ea = ctx->gpr[26] + ctx->gpr[31];
        ctx->gpr[26] = mem_read8(ctx, ea);
    }

label_8004C08C:
    // 8004C08C: rlwnm r17, r26, r17, 24, 31
    {
        ctx->gpr[17] = dolrecomp_rotl32(ctx->gpr[26], ctx->gpr[17]) & 0x000000FFu;
    }

label_8004C090:
    // 8004C090: or   r26, r16, r17
    {
        ctx->gpr[26] = ctx->gpr[16] | ctx->gpr[17];
    }

label_8004C094:
    // 8004C094: add   r16, r12, r26
    {
        u32 a = ctx->gpr[12];
        u32 b = ctx->gpr[26];
        u32 res = a + b;
        ctx->gpr[16] = res;
    }

label_8004C098:
    ctx->pc = 0x8004C098u;
    // 8004C098: lbz     r27, 0(r16)
    {
        u32 ea = ctx->gpr[16] + (u32)(s32)(0);
        ctx->gpr[27] = mem_read8(ctx, ea);
    }

label_8004C09C:
    // 8004C09C: add   r16, r11, r27
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[27];
        u32 res = a + b;
        ctx->gpr[16] = res;
    }

label_8004C0A0:
    ctx->pc = 0x8004C0A0u;
    // 8004C0A0: lbz     r28, 0(r16)
    {
        u32 ea = ctx->gpr[16] + (u32)(s32)(0);
        ctx->gpr[28] = mem_read8(ctx, ea);
    }

label_8004C0A4:
    // 8004C0A4: add   r7, r7, r28
    {
        u32 a = ctx->gpr[7];
        u32 b = ctx->gpr[28];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_8004C0A8:
    // 8004C0A8: srawi r17, r7, 3
    {
        u32 sh = 3u;
        u32 value = ctx->gpr[7];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[17] = value;
        } else if (sh > 31) {
            ctx->gpr[17] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[17] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_8004C0AC:
    // 8004C0AC: add   r3, r3, r17
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[17];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8004C0B0:
    // 8004C0B0: andi.   r7, r7, 0x0007
    {
        ctx->gpr[7] = ctx->gpr[7] & 0x0007u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[7];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8004C0B4:
    // 8004C0B4: subfic  r15, r7, 32
    {
        u64 res = (u64)(u32)(s32)(32) + (u64)(~ctx->gpr[7]) + 1u;
        ctx->gpr[15] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8004C0B8:
    // 8004C0B8: lis     r16, -32724
    ctx->gpr[16] = ((u32)(s32)(-32724) << 16);

label_8004C0BC:
    // 8004C0BC: addi    r16, r16, 9816
    ctx->gpr[16] = ctx->gpr[16] + (u32)(s32)(9816);

label_8004C0C0:
    // 8004C0C0: rlwinm r27, r27, 2, 0, 29
    {
        ctx->gpr[27] = dolrecomp_rotl32(ctx->gpr[27], 2u) & 0xFFFFFFFCu;
    }

label_8004C0C4:
    // 8004C0C4: add   r16, r16, r27
    {
        u32 a = ctx->gpr[16];
        u32 b = ctx->gpr[27];
        u32 res = a + b;
        ctx->gpr[16] = res;
    }

label_8004C0C8:
    ctx->pc = 0x8004C0C8u;
    // 8004C0C8: lhz     r31, 0(r16)
    {
        u32 ea = ctx->gpr[16] + (u32)(s32)(0);
        ctx->gpr[31] = mem_read16(ctx, ea);
    }

label_8004C0CC:
    // 8004C0CC: addi    r16, r16, 2
    ctx->gpr[16] = ctx->gpr[16] + (u32)(s32)(2);

label_8004C0D0:
    ctx->pc = 0x8004C0D0u;
    // 8004C0D0: lhz     r29, 0(r16)
    {
        u32 ea = ctx->gpr[16] + (u32)(s32)(0);
        ctx->gpr[29] = mem_read16(ctx, ea);
    }

label_8004C0D4:
    // 8004C0D4: cmpwi   r29, 0
    {
        s32 val_a = (s32)(ctx->gpr[29]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C0D8:
    // 8004C0D8: bc    12, 2, 0x8004C12C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004C12C;
        }
    }

label_8004C0DC:
    ctx->downcount -= 20;
    // 8004C0DC: subfic  r17, r7, 16
    {
        u64 res = (u64)(u32)(s32)(16) + (u64)(~ctx->gpr[7]) + 1u;
        ctx->gpr[17] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8004C0E0:
    ctx->pc = 0x8004C0E0u;
    // 8004C0E0: lbz     r19, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        ctx->gpr[19] = mem_read8(ctx, ea);
    }

label_8004C0E4:
    // 8004C0E4: slw   r19, r19, r17
    {
        u32 sh = ctx->gpr[17] & 0x3Fu;
        ctx->gpr[19] = sh > 31 ? 0u : (ctx->gpr[19] << sh);
    }

label_8004C0E8:
    // 8004C0E8: subfic  r17, r7, 8
    {
        u64 res = (u64)(u32)(s32)(8) + (u64)(~ctx->gpr[7]) + 1u;
        ctx->gpr[17] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8004C0EC:
    ctx->pc = 0x8004C0ECu;
    // 8004C0EC: lbz     r18, 1(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1);
        ctx->gpr[18] = mem_read8(ctx, ea);
    }

label_8004C0F0:
    // 8004C0F0: slw   r18, r18, r17
    {
        u32 sh = ctx->gpr[17] & 0x3Fu;
        ctx->gpr[18] = sh > 31 ? 0u : (ctx->gpr[18] << sh);
    }

label_8004C0F4:
    ctx->pc = 0x8004C0F4u;
    // 8004C0F4: lbz     r17, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[17] = mem_read8(ctx, ea);
    }

label_8004C0F8:
    // 8004C0F8: rlwnm r17, r17, r15, 24, 31
    {
        ctx->gpr[17] = dolrecomp_rotl32(ctx->gpr[17], ctx->gpr[15]) & 0x000000FFu;
    }

label_8004C0FC:
    // 8004C0FC: or   r17, r17, r18
    {
        ctx->gpr[17] = ctx->gpr[17] | ctx->gpr[18];
    }

label_8004C100:
    // 8004C100: or   r17, r17, r19
    {
        ctx->gpr[17] = ctx->gpr[17] | ctx->gpr[19];
    }

label_8004C104:
    // 8004C104: li      r18, 1
    ctx->gpr[18] = (u32)(s32)(1);

label_8004C108:
    // 8004C108: slw   r18, r18, r29
    {
        u32 sh = ctx->gpr[29] & 0x3Fu;
        ctx->gpr[18] = sh > 31 ? 0u : (ctx->gpr[18] << sh);
    }

label_8004C10C:
    // 8004C10C: addi    r18, r18, -1
    ctx->gpr[18] = ctx->gpr[18] + (u32)(s32)(-1);

label_8004C110:
    // 8004C110: and   r16, r17, r18
    {
        ctx->gpr[16] = ctx->gpr[17] & ctx->gpr[18];
    }

label_8004C114:
    // 8004C114: add   r31, r31, r16
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[16];
        u32 res = a + b;
        ctx->gpr[31] = res;
    }

label_8004C118:
    // 8004C118: add   r7, r7, r29
    {
        u32 a = ctx->gpr[7];
        u32 b = ctx->gpr[29];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_8004C11C:
    // 8004C11C: srawi r17, r7, 3
    {
        u32 sh = 3u;
        u32 value = ctx->gpr[7];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[17] = value;
        } else if (sh > 31) {
            ctx->gpr[17] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[17] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_8004C120:
    // 8004C120: add   r3, r3, r17
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[17];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8004C124:
    // 8004C124: andi.   r7, r7, 0x0007
    {
        ctx->gpr[7] = ctx->gpr[7] & 0x0007u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[7];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8004C128:
    // 8004C128: subfic  r15, r7, 32
    {
        u64 res = (u64)(u32)(s32)(32) + (u64)(~ctx->gpr[7]) + 1u;
        ctx->gpr[15] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8004C12C:
    ctx->downcount -= 3;
    // 8004C12C: subf   r23, r31, r5
    {
        u32 a = ~ctx->gpr[31];
        u32 b = ctx->gpr[5];
        u32 res = a + b + 1u;
        ctx->gpr[23] = res;
    }

label_8004C130:
    ctx->pc = 0x8004C130u;
    // 8004C130: mtctr    r30
    ctx->ctr = ctx->gpr[30];

label_8004C134:
    loop_8004C134(ctx);
    if (ctx->pc == 0x8004C140u) goto label_8004C140;
    return;
label_8004C138:
    ctx->pc = 0x8004C138u;
    // 8004C138: stbu     r16, 1(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1);
        mem_write8(ctx, ea, (u8)ctx->gpr[16]);
        ctx->gpr[5] = ea;
    }

label_8004C13C:
    // 8004C13C: bc    16, 0, 0x8004C134
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004C134u;
                return;
            }
            goto label_8004C134;
        }
    }

label_8004C140:
    ctx->downcount -= 2;
    // 8004C140: cmpwi   r25, 256
    {
        s32 val_a = (s32)(ctx->gpr[25]);
        s32 val_b = (s32)(256);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C144:
    // 8004C144: bc    4, 2, 0x8004BF2C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004BF2Cu;
                return;
            }
            goto label_8004BF2C;
        }
    }

label_8004C148:
    ctx->pc = 0x8004C148u;
    ctx->downcount -= 3;
    // 8004C148: lwz     r16, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[16] = mem_read32(ctx, ea);
    }

label_8004C14C:
    // 8004C14C: cmpwi   r16, 0
    {
        s32 val_a = (s32)(ctx->gpr[16]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C150:
    // 8004C150: bc    12, 2, 0x8004B85C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004B85Cu;
                return;
            }
            goto label_8004B85C;
        }
    }

label_8004C154:
    ctx->pc = 0x8004C154u;
    ctx->downcount -= 17;
    // 8004C154: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8004C158:
    ctx->pc = 0x8004C158u;
    // 8004C158: lwz     r0, 88(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004C15C:
    ctx->pc = 0x8004C15Cu;
    // 8004C15C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004C160:
    ctx->pc = 0x8004C160u;
    // 8004C160: lmw     r14, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 14; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8004C164:
    ctx->pc = 0x8004C164u;
    // 8004C164: addi    r1, r1, 84
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(84);

label_8004C168:
    ctx->pc = 0x8004C168u;
    // 8004C168: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004C16C:
    ctx->pc = 0x8004C16Cu;
    ctx->downcount -= 8;
    // 8004C16C: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004C170:
    ctx->pc = 0x8004C170u;
    // 8004C170: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004C174:
    ctx->pc = 0x8004C174u;
    // 8004C174: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004C178:
    ctx->pc = 0x8004C178u;
    // 8004C178: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8004C17C:
    ctx->pc = 0x8004C17Cu;
    // 8004C17C: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_8004C180:
    ctx->pc = 0x8004C180u;
    // 8004C180: rlwinm r0, r4, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x000000FFu;
    }

label_8004C184:
    ctx->pc = 0x8004C184u;
    // 8004C184: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C188:
    ctx->pc = 0x8004C188u;
    // 8004C188: bc    12, 2, 0x8004C27C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004C27C;
        }
    }

label_8004C18C:
    ctx->pc = 0x8004C18Cu;
    ctx->downcount -= 4;
    // 8004C18C: lbz     r4, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_8004C190:
    ctx->pc = 0x8004C190u;
    // 8004C190: lbz     r0, 1(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8004C194:
    ctx->pc = 0x8004C194u;
    // 8004C194: cmplw   r4, r0
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C198:
    ctx->pc = 0x8004C198u;
    // 8004C198: bc    4, 2, 0x8004C264
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004C264;
        }
    }

label_8004C19C:
    ctx->pc = 0x8004C19Cu;
    ctx->downcount -= 3;
    // 8004C19C: lbz     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8004C1A0:
    ctx->pc = 0x8004C1A0u;
    // 8004C1A0: cmplw   r4, r0
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C1A4:
    ctx->pc = 0x8004C1A4u;
    // 8004C1A4: bc    4, 2, 0x8004C264
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004C264;
        }
    }

label_8004C1A8:
    ctx->pc = 0x8004C1A8u;
    ctx->downcount -= 2;
    // 8004C1A8: cmplwi  r4, 0x00FF
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(0x00FFu);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C1AC:
    ctx->pc = 0x8004C1ACu;
    // 8004C1AC: bc    4, 2, 0x8004C1C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004C1C0;
        }
    }

label_8004C1B0:
    ctx->pc = 0x8004C1B0u;
    ctx->downcount -= 4;
    // 8004C1B0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8004C1B4:
    ctx->pc = 0x8004C1B4u;
    // 8004C1B4: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004C1B8:
    ctx->pc = 0x8004C1B8u;
    // 8004C1B8: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_8004C1BC:
    ctx->pc = 0x8004C1BCu;
    // 8004C1BC: b       0x8004C264
    {
            goto label_8004C264;
    }

label_8004C1C0:
    ctx->pc = 0x8004C1C0u;
    ctx->downcount -= 2;
    // 8004C1C0: cmplwi  r4, 0x00E0
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(0x00E0u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C1C4:
    ctx->pc = 0x8004C1C4u;
    // 8004C1C4: bc    4, 2, 0x8004C1D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004C1D8;
        }
    }

label_8004C1C8:
    ctx->pc = 0x8004C1C8u;
    ctx->downcount -= 4;
    // 8004C1C8: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8004C1CC:
    ctx->pc = 0x8004C1CCu;
    // 8004C1CC: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004C1D0:
    ctx->pc = 0x8004C1D0u;
    // 8004C1D0: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_8004C1D4:
    ctx->pc = 0x8004C1D4u;
    // 8004C1D4: b       0x8004C264
    {
            goto label_8004C264;
    }

label_8004C1D8:
    ctx->pc = 0x8004C1D8u;
    ctx->downcount -= 2;
    // 8004C1D8: cmplwi  r4, 0x00C0
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(0x00C0u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C1DC:
    ctx->pc = 0x8004C1DCu;
    // 8004C1DC: bc    4, 2, 0x8004C1F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004C1F0;
        }
    }

label_8004C1E0:
    ctx->pc = 0x8004C1E0u;
    ctx->downcount -= 4;
    // 8004C1E0: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_8004C1E4:
    ctx->pc = 0x8004C1E4u;
    // 8004C1E4: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004C1E8:
    ctx->pc = 0x8004C1E8u;
    // 8004C1E8: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_8004C1EC:
    ctx->pc = 0x8004C1ECu;
    // 8004C1EC: b       0x8004C264
    {
            goto label_8004C264;
    }

label_8004C1F0:
    ctx->pc = 0x8004C1F0u;
    ctx->downcount -= 2;
    // 8004C1F0: cmplwi  r4, 0x00A0
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(0x00A0u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C1F4:
    ctx->pc = 0x8004C1F4u;
    // 8004C1F4: bc    4, 2, 0x8004C208
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004C208;
        }
    }

label_8004C1F8:
    ctx->pc = 0x8004C1F8u;
    ctx->downcount -= 4;
    // 8004C1F8: li      r0, 3
    ctx->gpr[0] = (u32)(s32)(3);

label_8004C1FC:
    ctx->pc = 0x8004C1FCu;
    // 8004C1FC: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004C200:
    ctx->pc = 0x8004C200u;
    // 8004C200: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_8004C204:
    ctx->pc = 0x8004C204u;
    // 8004C204: b       0x8004C264
    {
            goto label_8004C264;
    }

label_8004C208:
    ctx->pc = 0x8004C208u;
    ctx->downcount -= 2;
    // 8004C208: cmplwi  r4, 0x0080
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(0x0080u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C20C:
    ctx->pc = 0x8004C20Cu;
    // 8004C20C: bc    4, 2, 0x8004C220
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004C220;
        }
    }

label_8004C210:
    ctx->pc = 0x8004C210u;
    ctx->downcount -= 4;
    // 8004C210: li      r0, 4
    ctx->gpr[0] = (u32)(s32)(4);

label_8004C214:
    ctx->pc = 0x8004C214u;
    // 8004C214: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004C218:
    ctx->pc = 0x8004C218u;
    // 8004C218: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_8004C21C:
    ctx->pc = 0x8004C21Cu;
    // 8004C21C: b       0x8004C264
    {
            goto label_8004C264;
    }

label_8004C220:
    ctx->pc = 0x8004C220u;
    ctx->downcount -= 2;
    // 8004C220: cmplwi  r4, 0x0060
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(0x0060u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C224:
    ctx->pc = 0x8004C224u;
    // 8004C224: bc    4, 2, 0x8004C238
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004C238;
        }
    }

label_8004C228:
    ctx->pc = 0x8004C228u;
    ctx->downcount -= 4;
    // 8004C228: li      r0, 5
    ctx->gpr[0] = (u32)(s32)(5);

label_8004C22C:
    ctx->pc = 0x8004C22Cu;
    // 8004C22C: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004C230:
    ctx->pc = 0x8004C230u;
    // 8004C230: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_8004C234:
    ctx->pc = 0x8004C234u;
    // 8004C234: b       0x8004C264
    {
            goto label_8004C264;
    }

label_8004C238:
    ctx->pc = 0x8004C238u;
    ctx->downcount -= 2;
    // 8004C238: cmplwi  r4, 0x0040
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(0x0040u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C23C:
    ctx->pc = 0x8004C23Cu;
    // 8004C23C: bc    4, 2, 0x8004C250
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004C250;
        }
    }

label_8004C240:
    ctx->pc = 0x8004C240u;
    ctx->downcount -= 4;
    // 8004C240: li      r0, 6
    ctx->gpr[0] = (u32)(s32)(6);

label_8004C244:
    ctx->pc = 0x8004C244u;
    // 8004C244: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004C248:
    ctx->pc = 0x8004C248u;
    // 8004C248: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_8004C24C:
    ctx->pc = 0x8004C24Cu;
    // 8004C24C: b       0x8004C264
    {
            goto label_8004C264;
    }

label_8004C250:
    ctx->pc = 0x8004C250u;
    ctx->downcount -= 2;
    // 8004C250: cmplwi  r4, 0x0020
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(0x0020u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C254:
    ctx->pc = 0x8004C254u;
    // 8004C254: bc    4, 2, 0x8004C264
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004C264;
        }
    }

label_8004C258:
    ctx->pc = 0x8004C258u;
    ctx->downcount -= 3;
    // 8004C258: li      r0, 7
    ctx->gpr[0] = (u32)(s32)(7);

label_8004C25C:
    ctx->pc = 0x8004C25Cu;
    // 8004C25C: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004C260:
    ctx->pc = 0x8004C260u;
    // 8004C260: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_8004C264:
    ctx->pc = 0x8004C264u;
    ctx->downcount -= 3;
    // 8004C264: rlwinm r0, r8, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[8], 0u) & 0x000000FFu;
    }

label_8004C268:
    ctx->pc = 0x8004C268u;
    // 8004C268: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C26C:
    ctx->pc = 0x8004C26Cu;
    // 8004C26C: bc    4, 2, 0x8004C280
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004C280;
        }
    }

label_8004C270:
    ctx->pc = 0x8004C270u;
    ctx->downcount -= 3;
    // 8004C270: lwz     r0, -25624(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25624);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004C274:
    ctx->pc = 0x8004C274u;
    // 8004C274: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004C278:
    ctx->pc = 0x8004C278u;
    // 8004C278: b       0x8004C280
    {
            goto label_8004C280;
    }

label_8004C27C:
    ctx->pc = 0x8004C27Cu;
    ctx->downcount -= 1;
    // 8004C27C: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_8004C280:
    ctx->pc = 0x8004C280u;
    ctx->downcount -= 3;
    // 8004C280: rlwinm r0, r5, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x000000FFu;
    }

label_8004C284:
    ctx->pc = 0x8004C284u;
    // 8004C284: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C288:
    ctx->pc = 0x8004C288u;
    // 8004C288: bc    12, 2, 0x8004C364
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004C364;
        }
    }

label_8004C28C:
    ctx->pc = 0x8004C28Cu;
    ctx->downcount -= 3;
    // 8004C28C: lbz     r0, 3(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(3);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8004C290:
    ctx->pc = 0x8004C290u;
    // 8004C290: cmplwi  r0, 0x00FF
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x00FFu);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C294:
    ctx->pc = 0x8004C294u;
    // 8004C294: bc    4, 2, 0x8004C2A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004C2A8;
        }
    }

label_8004C298:
    ctx->pc = 0x8004C298u;
    ctx->downcount -= 4;
    // 8004C298: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8004C29C:
    ctx->pc = 0x8004C29Cu;
    // 8004C29C: stw     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004C2A0:
    ctx->pc = 0x8004C2A0u;
    // 8004C2A0: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_8004C2A4:
    ctx->pc = 0x8004C2A4u;
    // 8004C2A4: b       0x8004C34C
    {
            goto label_8004C34C;
    }

label_8004C2A8:
    ctx->pc = 0x8004C2A8u;
    ctx->downcount -= 2;
    // 8004C2A8: cmplwi  r0, 0x00E0
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x00E0u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C2AC:
    ctx->pc = 0x8004C2ACu;
    // 8004C2AC: bc    4, 2, 0x8004C2C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004C2C0;
        }
    }

label_8004C2B0:
    ctx->pc = 0x8004C2B0u;
    ctx->downcount -= 4;
    // 8004C2B0: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8004C2B4:
    ctx->pc = 0x8004C2B4u;
    // 8004C2B4: stw     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004C2B8:
    ctx->pc = 0x8004C2B8u;
    // 8004C2B8: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_8004C2BC:
    ctx->pc = 0x8004C2BCu;
    // 8004C2BC: b       0x8004C34C
    {
            goto label_8004C34C;
    }

label_8004C2C0:
    ctx->pc = 0x8004C2C0u;
    ctx->downcount -= 2;
    // 8004C2C0: cmplwi  r0, 0x00C0
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x00C0u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C2C4:
    ctx->pc = 0x8004C2C4u;
    // 8004C2C4: bc    4, 2, 0x8004C2D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004C2D8;
        }
    }

label_8004C2C8:
    ctx->pc = 0x8004C2C8u;
    ctx->downcount -= 4;
    // 8004C2C8: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_8004C2CC:
    ctx->pc = 0x8004C2CCu;
    // 8004C2CC: stw     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004C2D0:
    ctx->pc = 0x8004C2D0u;
    // 8004C2D0: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_8004C2D4:
    ctx->pc = 0x8004C2D4u;
    // 8004C2D4: b       0x8004C34C
    {
            goto label_8004C34C;
    }

label_8004C2D8:
    ctx->pc = 0x8004C2D8u;
    ctx->downcount -= 2;
    // 8004C2D8: cmplwi  r0, 0x00A0
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x00A0u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C2DC:
    ctx->pc = 0x8004C2DCu;
    // 8004C2DC: bc    4, 2, 0x8004C2F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004C2F0;
        }
    }

label_8004C2E0:
    ctx->pc = 0x8004C2E0u;
    ctx->downcount -= 4;
    // 8004C2E0: li      r0, 3
    ctx->gpr[0] = (u32)(s32)(3);

label_8004C2E4:
    ctx->pc = 0x8004C2E4u;
    // 8004C2E4: stw     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004C2E8:
    ctx->pc = 0x8004C2E8u;
    // 8004C2E8: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_8004C2EC:
    ctx->pc = 0x8004C2ECu;
    // 8004C2EC: b       0x8004C34C
    {
            goto label_8004C34C;
    }

label_8004C2F0:
    ctx->pc = 0x8004C2F0u;
    ctx->downcount -= 2;
    // 8004C2F0: cmplwi  r0, 0x0080
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0080u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C2F4:
    ctx->pc = 0x8004C2F4u;
    // 8004C2F4: bc    4, 2, 0x8004C308
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004C308;
        }
    }

label_8004C2F8:
    ctx->pc = 0x8004C2F8u;
    ctx->downcount -= 4;
    // 8004C2F8: li      r0, 4
    ctx->gpr[0] = (u32)(s32)(4);

label_8004C2FC:
    ctx->pc = 0x8004C2FCu;
    // 8004C2FC: stw     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004C300:
    ctx->pc = 0x8004C300u;
    // 8004C300: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_8004C304:
    ctx->pc = 0x8004C304u;
    // 8004C304: b       0x8004C34C
    {
            goto label_8004C34C;
    }

label_8004C308:
    ctx->pc = 0x8004C308u;
    ctx->downcount -= 2;
    // 8004C308: cmplwi  r0, 0x0060
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0060u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C30C:
    ctx->pc = 0x8004C30Cu;
    // 8004C30C: bc    4, 2, 0x8004C320
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004C320;
        }
    }

label_8004C310:
    ctx->pc = 0x8004C310u;
    ctx->downcount -= 4;
    // 8004C310: li      r0, 5
    ctx->gpr[0] = (u32)(s32)(5);

label_8004C314:
    ctx->pc = 0x8004C314u;
    // 8004C314: stw     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004C318:
    ctx->pc = 0x8004C318u;
    // 8004C318: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_8004C31C:
    ctx->pc = 0x8004C31Cu;
    // 8004C31C: b       0x8004C34C
    {
            goto label_8004C34C;
    }

label_8004C320:
    ctx->pc = 0x8004C320u;
    ctx->downcount -= 2;
    // 8004C320: cmplwi  r0, 0x0040
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0040u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C324:
    ctx->pc = 0x8004C324u;
    // 8004C324: bc    4, 2, 0x8004C338
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004C338;
        }
    }

label_8004C328:
    ctx->pc = 0x8004C328u;
    ctx->downcount -= 4;
    // 8004C328: li      r0, 6
    ctx->gpr[0] = (u32)(s32)(6);

label_8004C32C:
    ctx->pc = 0x8004C32Cu;
    // 8004C32C: stw     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004C330:
    ctx->pc = 0x8004C330u;
    // 8004C330: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_8004C334:
    ctx->pc = 0x8004C334u;
    // 8004C334: b       0x8004C34C
    {
            goto label_8004C34C;
    }

label_8004C338:
    ctx->pc = 0x8004C338u;
    ctx->downcount -= 2;
    // 8004C338: cmplwi  r0, 0x0020
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0020u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C33C:
    ctx->pc = 0x8004C33Cu;
    // 8004C33C: bc    4, 2, 0x8004C34C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004C34C;
        }
    }

label_8004C340:
    ctx->pc = 0x8004C340u;
    ctx->downcount -= 3;
    // 8004C340: li      r0, 7
    ctx->gpr[0] = (u32)(s32)(7);

label_8004C344:
    ctx->pc = 0x8004C344u;
    // 8004C344: stw     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004C348:
    ctx->pc = 0x8004C348u;
    // 8004C348: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_8004C34C:
    ctx->pc = 0x8004C34Cu;
    ctx->downcount -= 3;
    // 8004C34C: rlwinm r0, r9, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[9], 0u) & 0x000000FFu;
    }

label_8004C350:
    ctx->pc = 0x8004C350u;
    // 8004C350: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C354:
    ctx->pc = 0x8004C354u;
    // 8004C354: bc    4, 2, 0x8004C368
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004C368;
        }
    }

label_8004C358:
    ctx->pc = 0x8004C358u;
    ctx->downcount -= 3;
    // 8004C358: lwz     r0, -25628(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25628);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004C35C:
    ctx->pc = 0x8004C35Cu;
    // 8004C35C: stw     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004C360:
    ctx->pc = 0x8004C360u;
    // 8004C360: b       0x8004C368
    {
            goto label_8004C368;
    }

label_8004C364:
    ctx->pc = 0x8004C364u;
    ctx->downcount -= 1;
    // 8004C364: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_8004C368:
    ctx->pc = 0x8004C368u;
    ctx->downcount -= 3;
    // 8004C368: rlwinm r0, r8, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[8], 0u) & 0x000000FFu;
    }

label_8004C36C:
    ctx->pc = 0x8004C36Cu;
    // 8004C36C: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C370:
    ctx->pc = 0x8004C370u;
    // 8004C370: bc    12, 2, 0x8004C380
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004C380;
        }
    }

label_8004C374:
    ctx->pc = 0x8004C374u;
    ctx->downcount -= 3;
    // 8004C374: rlwinm r0, r9, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[9], 0u) & 0x000000FFu;
    }

label_8004C378:
    ctx->pc = 0x8004C378u;
    // 8004C378: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C37C:
    ctx->pc = 0x8004C37Cu;
    // 8004C37C: bc    4, 2, 0x8004C3B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004C3B8;
        }
    }

label_8004C380:
    ctx->pc = 0x8004C380u;
    ctx->downcount -= 5;
    // 8004C380: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004C384:
    ctx->pc = 0x8004C384u;
    // 8004C384: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004C388:
    ctx->pc = 0x8004C388u;
    // 8004C388: lwz     r3, -25620(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25620);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004C38C:
    ctx->pc = 0x8004C38Cu;
    // 8004C38C: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_8004C390:
    ctx->pc = 0x8004C390u;
    // 8004C390: bl      0x8025C71C
    {
            ctx->lr = 0x8004C394u;
            ctx->pc = 0x8025C71Cu;
            return;
    }

label_8004C394:
    ctx->pc = 0x8004C394u;
    ctx->downcount -= 9;
    // 8004C394: lwz     r3, -25620(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25620);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004C398:
    ctx->pc = 0x8004C398u;
    // 8004C398: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8004C39C:
    ctx->pc = 0x8004C39Cu;
    // 8004C39C: stw     r0, -25620(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25620);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004C3A0:
    ctx->pc = 0x8004C3A0u;
    // 8004C3A0: lwz     r3, -25624(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25624);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004C3A4:
    ctx->pc = 0x8004C3A4u;
    // 8004C3A4: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8004C3A8:
    ctx->pc = 0x8004C3A8u;
    // 8004C3A8: stw     r0, -25624(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25624);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004C3AC:
    ctx->pc = 0x8004C3ACu;
    // 8004C3AC: lwz     r3, -25628(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25628);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004C3B0:
    ctx->pc = 0x8004C3B0u;
    // 8004C3B0: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8004C3B4:
    ctx->pc = 0x8004C3B4u;
    // 8004C3B4: stw     r0, -25628(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25628);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004C3B8:
    ctx->pc = 0x8004C3B8u;
    ctx->downcount -= 5;
    // 8004C3B8: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004C3BC:
    ctx->pc = 0x8004C3BCu;
    // 8004C3BC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004C3C0:
    ctx->pc = 0x8004C3C0u;
    // 8004C3C0: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8004C3C4:
    ctx->pc = 0x8004C3C4u;
    // 8004C3C4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004C3C8:
    ctx->pc = 0x8004C3C8u;
    ctx->downcount -= 6;
    // 8004C3C8: addi    r4, r13, -31652
    ctx->gpr[4] = ctx->gpr[13] + (u32)(s32)(-31652);

label_8004C3CC:
    ctx->pc = 0x8004C3CCu;
    // 8004C3CC: stb     r3, 3(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(3);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_8004C3D0:
    ctx->pc = 0x8004C3D0u;
    // 8004C3D0: stfs     f1, -31648(r13)
    if (!ppc_fp_available_inline(ctx, 0x8004C3D0u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31648);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8004C3D4:
    ctx->pc = 0x8004C3D4u;
    // 8004C3D4: lfs     f0, -31280(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004C3D4u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31280);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004C3D8:
    ctx->pc = 0x8004C3D8u;
    // 8004C3D8: fcmpo   cr0, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8004C3D8u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[1], ctx->fpr[0], true);

label_8004C3DC:
    ctx->pc = 0x8004C3DCu;
    // 8004C3DC: bclr  4, 1
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004C3E0:
    ctx->pc = 0x8004C3E0u;
    ctx->downcount -= 2;
    // 8004C3E0: stfs     f0, -31648(r13)
    if (!ppc_fp_available_inline(ctx, 0x8004C3E0u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31648);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004C3E4:
    ctx->pc = 0x8004C3E4u;
    // 8004C3E4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004C3E8:
    ctx->pc = 0x8004C3E8u;
    ctx->downcount -= 3;
    // 8004C3E8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8004C3EC:
    ctx->pc = 0x8004C3ECu;
    // 8004C3EC: stb     r0, -25696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25696);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004C3F0:
    ctx->pc = 0x8004C3F0u;
    // 8004C3F0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004C3F4:
    ctx->pc = 0x8004C3F4u;
    ctx->downcount -= 9;
    // 8004C3F4: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8004C3F8:
    ctx->pc = 0x8004C3F8u;
    // 8004C3F8: stb     r0, -25696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25696);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004C3FC:
    ctx->pc = 0x8004C3FCu;
    // 8004C3FC: stfs     f1, -25668(r13)
    if (!ppc_fp_available_inline(ctx, 0x8004C3FCu)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25668);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8004C400:
    ctx->pc = 0x8004C400u;
    // 8004C400: stfs     f2, -25672(r13)
    if (!ppc_fp_available_inline(ctx, 0x8004C400u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25672);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_8004C404:
    ctx->pc = 0x8004C404u;
    // 8004C404: stfs     f3, -25676(r13)
    if (!ppc_fp_available_inline(ctx, 0x8004C404u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25676);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[3]));
    }

label_8004C408:
    ctx->pc = 0x8004C408u;
    // 8004C408: stfs     f4, -25680(r13)
    if (!ppc_fp_available_inline(ctx, 0x8004C408u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25680);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[4]));
    }

label_8004C40C:
    ctx->pc = 0x8004C40Cu;
    // 8004C40C: stfs     f5, -25684(r13)
    if (!ppc_fp_available_inline(ctx, 0x8004C40Cu)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25684);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[5]));
    }

label_8004C410:
    ctx->pc = 0x8004C410u;
    // 8004C410: stb     r3, -25687(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25687);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_8004C414:
    ctx->pc = 0x8004C414u;
    // 8004C414: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004C418:
    ctx->pc = 0x8004C418u;
    ctx->downcount -= 5;
    // 8004C418: lfs     f0, -25668(r13)
    if (!ppc_fp_available_inline(ctx, 0x8004C418u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25668);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004C41C:
    ctx->pc = 0x8004C41Cu;
    // 8004C41C: stfs     f0, 0(r3)
    if (!ppc_fp_available_inline(ctx, 0x8004C41Cu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004C420:
    ctx->pc = 0x8004C420u;
    // 8004C420: lfs     f0, -25672(r13)
    if (!ppc_fp_available_inline(ctx, 0x8004C420u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25672);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004C424:
    ctx->pc = 0x8004C424u;
    // 8004C424: stfs     f0, 0(r4)
    if (!ppc_fp_available_inline(ctx, 0x8004C424u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004C428:
    ctx->pc = 0x8004C428u;
    // 8004C428: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004C42C:
    ctx->pc = 0x8004C42Cu;
    ctx->downcount -= 2;
    // 8004C42C: lbz     r3, -25696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25696);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8004C430:
    ctx->pc = 0x8004C430u;
    // 8004C430: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004C434:
    ctx->pc = 0x8004C434u;
    ctx->downcount -= 5;
    // 8004C434: or   r0, r3, r3
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004C438:
    ctx->pc = 0x8004C438u;
    // 8004C438: rlwinm r3, r4, 3, 0, 28
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[4], 3u) & 0xFFFFFFF8u;
    }

label_8004C43C:
    ctx->pc = 0x8004C43Cu;
    // 8004C43C: addi    r3, r3, 36
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(36);

label_8004C440:
    ctx->pc = 0x8004C440u;
    // 8004C440: add   r3, r0, r3
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8004C444:
    ctx->pc = 0x8004C444u;
    // 8004C444: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004C448:
    ctx->pc = 0x8004C448u;
    ctx->downcount -= 8;
    // 8004C448: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004C44C:
    ctx->pc = 0x8004C44Cu;
    // 8004C44C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004C450:
    ctx->pc = 0x8004C450u;
    // 8004C450: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004C454:
    ctx->pc = 0x8004C454u;
    // 8004C454: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8004C458:
    ctx->pc = 0x8004C458u;
    // 8004C458: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004C45C:
    ctx->pc = 0x8004C45Cu;
    // 8004C45C: or   r5, r4, r4
    {
        ctx->gpr[5] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8004C460:
    ctx->pc = 0x8004C460u;
    // 8004C460: cmplwi  r31, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[31]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C464:
    ctx->pc = 0x8004C464u;
    // 8004C464: bc    12, 2, 0x8004C4B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004C4B4;
        }
    }

label_8004C468:
    ctx->pc = 0x8004C468u;
    ctx->downcount -= 4;
    // 8004C468: addi    r3, r31, 32
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(32);

label_8004C46C:
    ctx->pc = 0x8004C46Cu;
    // 8004C46C: lbz     r0, 72(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(72);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8004C470:
    ctx->pc = 0x8004C470u;
    // 8004C470: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C474:
    ctx->pc = 0x8004C474u;
    // 8004C474: bc    12, 2, 0x8004C484
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004C484;
        }
    }

label_8004C478:
    ctx->pc = 0x8004C478u;
    ctx->downcount -= 2;
    // 8004C478: lwz     r4, 64(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(64);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004C47C:
    ctx->pc = 0x8004C47Cu;
    // 8004C47C: bl      0x8025B0B8
    {
            ctx->lr = 0x8004C480u;
            ctx->pc = 0x8025B0B8u;
            return;
    }

label_8004C480:
    ctx->pc = 0x8004C480u;
    ctx->downcount -= 1;
    // 8004C480: b       0x8004C488
    {
            goto label_8004C488;
    }

label_8004C484:
    ctx->pc = 0x8004C484u;
    ctx->downcount -= 1;
    // 8004C484: bl      0x8025B260
    {
            ctx->lr = 0x8004C488u;
            ctx->pc = 0x8025B260u;
            return;
    }

label_8004C488:
    ctx->pc = 0x8004C488u;
    ctx->downcount -= 3;
    // 8004C488: lwz     r0, 80(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(80);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004C48C:
    ctx->pc = 0x8004C48Cu;
    // 8004C48C: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C490:
    ctx->pc = 0x8004C490u;
    // 8004C490: bc    12, 2, 0x8004C4B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004C4B4;
        }
    }

label_8004C494:
    ctx->pc = 0x8004C494u;
    ctx->downcount -= 4;
    // 8004C494: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8004C498:
    ctx->pc = 0x8004C498u;
    // 8004C498: lis     r4, -32712
    ctx->gpr[4] = ((u32)(s32)(-32712) << 16);

label_8004C49C:
    ctx->pc = 0x8004C49Cu;
    // 8004C49C: addi    r4, r4, -27904
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-27904);

label_8004C4A0:
    ctx->pc = 0x8004C4A0u;
    // 8004C4A0: bl      0x80053E24
    {
            ctx->lr = 0x8004C4A4u;
            ctx->pc = 0x80053E24u;
            return;
    }

label_8004C4A4:
    ctx->pc = 0x8004C4A4u;
    ctx->downcount -= 4;
    // 8004C4A4: lis     r3, -32712
    ctx->gpr[3] = ((u32)(s32)(-32712) << 16);

label_8004C4A8:
    ctx->pc = 0x8004C4A8u;
    // 8004C4A8: addi    r3, r3, -27904
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-27904);

label_8004C4AC:
    ctx->pc = 0x8004C4ACu;
    // 8004C4AC: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8004C4B0:
    ctx->pc = 0x8004C4B0u;
    // 8004C4B0: bl      0x8025B260
    {
            ctx->lr = 0x8004C4B4u;
            ctx->pc = 0x8025B260u;
            return;
    }

label_8004C4B4:
    ctx->pc = 0x8004C4B4u;
    ctx->downcount -= 6;
    // 8004C4B4: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8004C4B8:
    ctx->pc = 0x8004C4B8u;
    // 8004C4B8: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004C4BC:
    ctx->pc = 0x8004C4BCu;
    // 8004C4BC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004C4C0:
    ctx->pc = 0x8004C4C0u;
    // 8004C4C0: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8004C4C4:
    ctx->pc = 0x8004C4C4u;
    // 8004C4C4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004C4C8:
    ctx->pc = 0x8004C4C8u;
    ctx->downcount -= 7;
    // 8004C4C8: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004C4CC:
    ctx->pc = 0x8004C4CCu;
    // 8004C4CC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004C4D0:
    ctx->pc = 0x8004C4D0u;
    // 8004C4D0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004C4D4:
    ctx->pc = 0x8004C4D4u;
    // 8004C4D4: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004C4D8:
    ctx->pc = 0x8004C4D8u;
    // 8004C4D8: or   r5, r4, r4
    {
        ctx->gpr[5] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8004C4DC:
    ctx->pc = 0x8004C4DCu;
    // 8004C4DC: cmplwi  r6, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[6]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C4E0:
    ctx->pc = 0x8004C4E0u;
    // 8004C4E0: bc    12, 2, 0x8004C504
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004C504;
        }
    }

label_8004C4E4:
    ctx->pc = 0x8004C4E4u;
    ctx->downcount -= 4;
    // 8004C4E4: addi    r3, r6, 32
    ctx->gpr[3] = ctx->gpr[6] + (u32)(s32)(32);

label_8004C4E8:
    ctx->pc = 0x8004C4E8u;
    // 8004C4E8: lbz     r0, 72(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(72);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8004C4EC:
    ctx->pc = 0x8004C4ECu;
    // 8004C4EC: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C4F0:
    ctx->pc = 0x8004C4F0u;
    // 8004C4F0: bc    12, 2, 0x8004C500
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004C500;
        }
    }

label_8004C4F4:
    ctx->pc = 0x8004C4F4u;
    ctx->downcount -= 2;
    // 8004C4F4: lwz     r4, 64(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(64);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004C4F8:
    ctx->pc = 0x8004C4F8u;
    // 8004C4F8: bl      0x8025B0B8
    {
            ctx->lr = 0x8004C4FCu;
            ctx->pc = 0x8025B0B8u;
            return;
    }

label_8004C4FC:
    ctx->pc = 0x8004C4FCu;
    ctx->downcount -= 1;
    // 8004C4FC: b       0x8004C504
    {
            goto label_8004C504;
    }

label_8004C500:
    ctx->pc = 0x8004C500u;
    ctx->downcount -= 1;
    // 8004C500: bl      0x8025B260
    {
            ctx->lr = 0x8004C504u;
            ctx->pc = 0x8025B260u;
            return;
    }

label_8004C504:
    ctx->pc = 0x8004C504u;
    ctx->downcount -= 5;
    // 8004C504: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004C508:
    ctx->pc = 0x8004C508u;
    // 8004C508: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004C50C:
    ctx->pc = 0x8004C50Cu;
    // 8004C50C: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8004C510:
    ctx->pc = 0x8004C510u;
    // 8004C510: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004C514:
    ctx->pc = 0x8004C514u;
    ctx->downcount -= 5;
    // 8004C514: stwu     r1, -96(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-96);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004C518:
    ctx->pc = 0x8004C518u;
    // 8004C518: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004C51C:
    ctx->pc = 0x8004C51Cu;
    // 8004C51C: stw     r0, 100(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(100);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004C520:
    ctx->pc = 0x8004C520u;
    // 8004C520: addi    r11, r1, 96
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(96);

label_8004C524:
    ctx->pc = 0x8004C524u;
    // 8004C524: bl      0x80286A3C
    {
            ctx->lr = 0x8004C528u;
            ctx->pc = 0x80286A3Cu;
            return;
    }

label_8004C528:
    ctx->pc = 0x8004C528u;
    ctx->downcount -= 19;
    // 8004C528: or   r26, r3, r3
    {
        ctx->gpr[26] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004C52C:
    ctx->pc = 0x8004C52Cu;
    // 8004C52C: or   r27, r4, r4
    {
        ctx->gpr[27] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8004C530:
    ctx->pc = 0x8004C530u;
    // 8004C530: lis     r3, -32724
    ctx->gpr[3] = ((u32)(s32)(-32724) << 16);

label_8004C534:
    ctx->pc = 0x8004C534u;
    // 8004C534: addi    r4, r3, 10152
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(10152);

label_8004C538:
    ctx->pc = 0x8004C538u;
    // 8004C538: lwz     r3, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004C53C:
    ctx->pc = 0x8004C53Cu;
    // 8004C53C: lwz     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004C540:
    ctx->pc = 0x8004C540u;
    // 8004C540: stw     r3, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8004C544:
    ctx->pc = 0x8004C544u;
    // 8004C544: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004C548:
    ctx->pc = 0x8004C548u;
    // 8004C548: lwz     r3, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004C54C:
    ctx->pc = 0x8004C54Cu;
    // 8004C54C: lwz     r0, 12(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004C550:
    ctx->pc = 0x8004C550u;
    // 8004C550: stw     r3, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8004C554:
    ctx->pc = 0x8004C554u;
    // 8004C554: stw     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004C558:
    ctx->pc = 0x8004C558u;
    // 8004C558: lwz     r3, 16(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004C55C:
    ctx->pc = 0x8004C55Cu;
    // 8004C55C: lwz     r0, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004C560:
    ctx->pc = 0x8004C560u;
    // 8004C560: stw     r3, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8004C564:
    ctx->pc = 0x8004C564u;
    // 8004C564: stw     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004C568:
    ctx->pc = 0x8004C568u;
    // 8004C568: lwz     r0, -25692(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25692);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004C56C:
    ctx->pc = 0x8004C56Cu;
    // 8004C56C: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C570:
    ctx->pc = 0x8004C570u;
    // 8004C570: bc    4, 2, 0x8004C660
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004C660;
        }
    }

label_8004C574:
    ctx->pc = 0x8004C574u;
    ctx->downcount -= 11;
    // 8004C574: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8004C578:
    ctx->pc = 0x8004C578u;
    // 8004C578: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004C57C:
    ctx->pc = 0x8004C57Cu;
    // 8004C57C: li      r3, 32
    ctx->gpr[3] = (u32)(s32)(32);

label_8004C580:
    ctx->pc = 0x8004C580u;
    // 8004C580: li      r4, 32
    ctx->gpr[4] = (u32)(s32)(32);

label_8004C584:
    ctx->pc = 0x8004C584u;
    // 8004C584: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_8004C588:
    ctx->pc = 0x8004C588u;
    // 8004C588: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004C58C:
    ctx->pc = 0x8004C58Cu;
    // 8004C58C: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004C590:
    ctx->pc = 0x8004C590u;
    // 8004C590: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_8004C594:
    ctx->pc = 0x8004C594u;
    // 8004C594: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_8004C598:
    ctx->pc = 0x8004C598u;
    // 8004C598: li      r10, 1
    ctx->gpr[10] = (u32)(s32)(1);

label_8004C59C:
    ctx->pc = 0x8004C59Cu;
    // 8004C59C: bl      0x80054E7C
    {
            ctx->lr = 0x8004C5A0u;
            ctx->pc = 0x80054E7Cu;
            return;
    }

label_8004C5A0:
    ctx->pc = 0x8004C5A0u;
    ctx->downcount -= 2;
    // 8004C5A0: stw     r3, -25692(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25692);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8004C5A4:
    ctx->pc = 0x8004C5A4u;
    // 8004C5A4: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_8004C5A8:
    ctx->downcount -= 5;
    // 8004C5A8: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_8004C5AC:
    // 8004C5AC: srawi r0, r29, 2
    {
        u32 sh = 2u;
        u32 value = ctx->gpr[29];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[0] = value;
        } else if (sh > 31) {
            ctx->gpr[0] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[0] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_8004C5B0:
    // 8004C5B0: rlwinm r31, r0, 5, 0, 26
    {
        ctx->gpr[31] = dolrecomp_rotl32(ctx->gpr[0], 5u) & 0xFFFFFFE0u;
    }

label_8004C5B4:
    // 8004C5B4: rlwinm r0, r29, 0, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[29], 0u) & 0x00000003u;
    }

label_8004C5B8:
    // 8004C5B8: rlwinm r30, r0, 1, 0, 30
    {
        ctx->gpr[30] = dolrecomp_rotl32(ctx->gpr[0], 1u) & 0xFFFFFFFEu;
    }

label_8004C5BC:
    ctx->pc = 0x8004C5BCu;
    ctx->downcount -= 12;
    // 8004C5BC: lwz     r0, -25692(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25692);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004C5C0:
    // 8004C5C0: add   r0, r0, r30
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8004C5C4:
    // 8004C5C4: add   r3, r0, r31
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8004C5C8:
    // 8004C5C8: rlwinm r0, r28, 0, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[28], 0u) & 0x00000003u;
    }

label_8004C5CC:
    // 8004C5CC: rlwinm r0, r0, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 3u) & 0xFFFFFFF8u;
    }

label_8004C5D0:
    // 8004C5D0: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8004C5D4:
    // 8004C5D4: srawi r0, r28, 2
    {
        u32 sh = 2u;
        u32 value = ctx->gpr[28];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[0] = value;
        } else if (sh > 31) {
            ctx->gpr[0] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[0] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_8004C5D8:
    // 8004C5D8: rlwinm r0, r0, 8, 0, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 8u) & 0xFFFFFF00u;
    }

label_8004C5DC:
    // 8004C5DC: add   r24, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[24] = res;
    }

label_8004C5E0:
    // 8004C5E0: li      r3, 128
    ctx->gpr[3] = (u32)(s32)(128);

label_8004C5E4:
    // 8004C5E4: li      r4, 255
    ctx->gpr[4] = (u32)(s32)(255);

label_8004C5E8:
    // 8004C5E8: bl      0x80022308
    {
            ctx->lr = 0x8004C5ECu;
            ctx->pc = 0x80022308u;
            return;
    }

label_8004C5EC:
    ctx->downcount -= 4;
    // 8004C5EC: or   r25, r3, r3
    {
        ctx->gpr[25] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004C5F0:
    // 8004C5F0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8004C5F4:
    // 8004C5F4: li      r4, 64
    ctx->gpr[4] = (u32)(s32)(64);

label_8004C5F8:
    // 8004C5F8: bl      0x80022308
    {
            ctx->lr = 0x8004C5FCu;
            ctx->pc = 0x80022308u;
            return;
    }

label_8004C5FC:
    ctx->downcount -= 4;
    // 8004C5FC: subf   r23, r3, r25
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[25];
        u32 res = a + b + 1u;
        ctx->gpr[23] = res;
    }

label_8004C600:
    // 8004C600: li      r3, 64
    ctx->gpr[3] = (u32)(s32)(64);

label_8004C604:
    // 8004C604: li      r4, 128
    ctx->gpr[4] = (u32)(s32)(128);

label_8004C608:
    // 8004C608: bl      0x80022308
    {
            ctx->lr = 0x8004C60Cu;
            ctx->pc = 0x80022308u;
            return;
    }

label_8004C60C:
    ctx->downcount -= 14;
    // 8004C60C: subf   r5, r3, r25
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[25];
        u32 res = a + b + 1u;
        ctx->gpr[5] = res;
    }

label_8004C610:
    // 8004C610: rlwinm r0, r25, 0, 24, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[25], 0u) & 0x000000F8u;
    }

label_8004C614:
    // 8004C614: srawi r4, r0, 3
    {
        u32 sh = 3u;
        u32 value = ctx->gpr[0];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[4] = value;
        } else if (sh > 31) {
            ctx->gpr[4] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[4] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_8004C618:
    // 8004C618: rlwinm r0, r23, 0, 24, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[23], 0u) & 0x000000F8u;
    }

label_8004C61C:
    // 8004C61C: rlwinm r3, r0, 8, 0, 23
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 8u) & 0xFFFFFF00u;
    }

label_8004C620:
    // 8004C620: rlwinm r0, r5, 0, 24, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x000000FCu;
    }

label_8004C624:
    // 8004C624: rlwinm r0, r0, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 3u) & 0xFFFFFFF8u;
    }

label_8004C628:
    // 8004C628: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_8004C62C:
    // 8004C62C: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_8004C630:
    // 8004C630: rlwinm r0, r0, 0, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x0000FFFFu;
    }

label_8004C634:
    ctx->pc = 0x8004C634u;
    // 8004C634: sth     r0, 96(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(96);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8004C638:
    // 8004C638: addi    r28, r28, 1
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(1);

label_8004C63C:
    // 8004C63C: cmpwi   r28, 32
    {
        s32 val_a = (s32)(ctx->gpr[28]);
        s32 val_b = (s32)(32);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C640:
    // 8004C640: bc    12, 0, 0x8004C5BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004C5BCu;
                return;
            }
            goto label_8004C5BC;
        }
    }

label_8004C644:
    ctx->downcount -= 3;
    // 8004C644: addi    r29, r29, 1
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(1);

label_8004C648:
    // 8004C648: cmpwi   r29, 32
    {
        s32 val_a = (s32)(ctx->gpr[29]);
        s32 val_b = (s32)(32);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C64C:
    // 8004C64C: bc    12, 0, 0x8004C5A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004C5A8u;
                return;
            }
            goto label_8004C5A8;
        }
    }

label_8004C650:
    ctx->pc = 0x8004C650u;
    ctx->downcount -= 4;
    // 8004C650: lwz     r4, -25692(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25692);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004C654:
    ctx->pc = 0x8004C654u;
    // 8004C654: addi    r3, r4, 96
    ctx->gpr[3] = ctx->gpr[4] + (u32)(s32)(96);

label_8004C658:
    ctx->pc = 0x8004C658u;
    // 8004C658: lwz     r4, 68(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(68);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004C65C:
    ctx->pc = 0x8004C65Cu;
    // 8004C65C: bl      0x80242328
    {
            ctx->lr = 0x8004C660u;
            ctx->pc = 0x80242328u;
            return;
    }

label_8004C660:
    ctx->pc = 0x8004C660u;
    ctx->downcount -= 3;
    // 8004C660: addi    r3, r1, 28
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(28);

label_8004C664:
    ctx->pc = 0x8004C664u;
    // 8004C664: addi    r4, r1, 24
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(24);

label_8004C668:
    ctx->pc = 0x8004C668u;
    // 8004C668: bl      0x8006CCA0
    {
            ctx->lr = 0x8004C66Cu;
            ctx->pc = 0x8006CCA0u;
            return;
    }

label_8004C66C:
    ctx->pc = 0x8004C66Cu;
    ctx->downcount -= 4;
    // 8004C66C: lfs     f1, -31264(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004C66Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31264);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8004C670:
    ctx->pc = 0x8004C670u;
    // 8004C670: lfs     f0, 28(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004C670u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004C674:
    ctx->pc = 0x8004C674u;
    // 8004C674: fmuls   f1, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8004C674u)) return;
    ppc_fmuls(ctx, 1, 1, 0);

label_8004C678:
    ctx->pc = 0x8004C678u;
    // 8004C678: bl      0x802947F0
    {
            ctx->lr = 0x8004C67Cu;
            ctx->pc = 0x802947F0u;
            return;
    }

label_8004C67C:
    ctx->pc = 0x8004C67Cu;
    ctx->downcount -= 8;
    // 8004C67C: lfs     f2, -31256(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004C67Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31256);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8004C680:
    ctx->pc = 0x8004C680u;
    // 8004C680: lfs     f0, -31260(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004C680u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31260);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004C684:
    ctx->pc = 0x8004C684u;
    // 8004C684: fmadds f0, f2, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8004C684u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[2], ctx->fpr[1], ctx->fpr[0], true, false, false, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_8004C688:
    ctx->pc = 0x8004C688u;
    // 8004C688: stfs     f0, 36(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004C688u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004C68C:
    ctx->pc = 0x8004C68Cu;
    // 8004C68C: lfs     f1, -31264(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004C68Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31264);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8004C690:
    ctx->pc = 0x8004C690u;
    // 8004C690: lfs     f0, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004C690u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004C694:
    ctx->pc = 0x8004C694u;
    // 8004C694: fmuls   f1, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8004C694u)) return;
    ppc_fmuls(ctx, 1, 1, 0);

label_8004C698:
    ctx->pc = 0x8004C698u;
    // 8004C698: bl      0x802947F0
    {
            ctx->lr = 0x8004C69Cu;
            ctx->pc = 0x802947F0u;
            return;
    }

label_8004C69C:
    ctx->pc = 0x8004C69Cu;
    ctx->downcount -= 10;
    // 8004C69C: lfs     f2, -31256(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004C69Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31256);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8004C6A0:
    ctx->pc = 0x8004C6A0u;
    // 8004C6A0: lfs     f0, -31260(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004C6A0u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31260);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004C6A4:
    ctx->pc = 0x8004C6A4u;
    // 8004C6A4: fmadds f0, f2, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8004C6A4u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[2], ctx->fpr[1], ctx->fpr[0], true, false, false, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_8004C6A8:
    ctx->pc = 0x8004C6A8u;
    // 8004C6A8: stfs     f0, 52(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004C6A8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004C6AC:
    ctx->pc = 0x8004C6ACu;
    // 8004C6AC: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004C6B0:
    ctx->pc = 0x8004C6B0u;
    // 8004C6B0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004C6B4:
    ctx->pc = 0x8004C6B4u;
    // 8004C6B4: lwz     r5, -25596(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25596);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8004C6B8:
    ctx->pc = 0x8004C6B8u;
    // 8004C6B8: addi    r5, r5, 1
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(1);

label_8004C6BC:
    ctx->pc = 0x8004C6BCu;
    // 8004C6BC: li      r6, 8
    ctx->gpr[6] = (u32)(s32)(8);

label_8004C6C0:
    ctx->pc = 0x8004C6C0u;
    // 8004C6C0: bl      0x8025CA34
    {
            ctx->lr = 0x8004C6C4u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_8004C6C4:
    ctx->pc = 0x8004C6C4u;
    ctx->downcount -= 4;
    // 8004C6C4: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004C6C8:
    ctx->pc = 0x8004C6C8u;
    // 8004C6C8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004C6CC:
    ctx->pc = 0x8004C6CCu;
    // 8004C6CC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004C6D0:
    ctx->pc = 0x8004C6D0u;
    // 8004C6D0: bl      0x8025C868
    {
            ctx->lr = 0x8004C6D4u;
            ctx->pc = 0x8025C868u;
            return;
    }

label_8004C6D4:
    ctx->pc = 0x8004C6D4u;
    ctx->downcount -= 2;
    // 8004C6D4: cmplwi  r27, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[27]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C6D8:
    ctx->pc = 0x8004C6D8u;
    // 8004C6D8: bc    12, 2, 0x8004C718
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004C718;
        }
    }

label_8004C6DC:
    ctx->pc = 0x8004C6DCu;
    ctx->downcount -= 4;
    // 8004C6DC: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8004C6E0:
    ctx->pc = 0x8004C6E0u;
    // 8004C6E0: lwz     r4, -25608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004C6E4:
    ctx->pc = 0x8004C6E4u;
    // 8004C6E4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004C6E8:
    ctx->pc = 0x8004C6E8u;
    // 8004C6E8: bl      0x8025DAD0
    {
            ctx->lr = 0x8004C6ECu;
            ctx->pc = 0x8025DAD0u;
            return;
    }

label_8004C6EC:
    ctx->pc = 0x8004C6ECu;
    ctx->downcount -= 7;
    // 8004C6EC: lwz     r3, -25600(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25600);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004C6F0:
    ctx->pc = 0x8004C6F0u;
    // 8004C6F0: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8004C6F4:
    ctx->pc = 0x8004C6F4u;
    // 8004C6F4: lwz     r5, -25616(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25616);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8004C6F8:
    ctx->pc = 0x8004C6F8u;
    // 8004C6F8: li      r6, 60
    ctx->gpr[6] = (u32)(s32)(60);

label_8004C6FC:
    ctx->pc = 0x8004C6FCu;
    // 8004C6FC: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004C700:
    ctx->pc = 0x8004C700u;
    // 8004C700: lwz     r8, -25608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25608);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8004C704:
    ctx->pc = 0x8004C704u;
    // 8004C704: bl      0x80258880
    {
            ctx->lr = 0x8004C708u;
            ctx->pc = 0x80258880u;
            return;
    }

label_8004C708:
    ctx->pc = 0x8004C708u;
    ctx->downcount -= 4;
    // 8004C708: lwz     r3, -25608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004C70C:
    ctx->pc = 0x8004C70Cu;
    // 8004C70C: addi    r0, r3, 3
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(3);

label_8004C710:
    ctx->pc = 0x8004C710u;
    // 8004C710: stw     r0, -25608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25608);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004C714:
    ctx->pc = 0x8004C714u;
    // 8004C714: b       0x8004C734
    {
            goto label_8004C734;
    }

label_8004C718:
    ctx->pc = 0x8004C718u;
    ctx->downcount -= 7;
    // 8004C718: lwz     r3, -25600(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25600);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004C71C:
    ctx->pc = 0x8004C71Cu;
    // 8004C71C: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8004C720:
    ctx->pc = 0x8004C720u;
    // 8004C720: lwz     r5, -25616(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25616);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8004C724:
    ctx->pc = 0x8004C724u;
    // 8004C724: li      r6, 60
    ctx->gpr[6] = (u32)(s32)(60);

label_8004C728:
    ctx->pc = 0x8004C728u;
    // 8004C728: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004C72C:
    ctx->pc = 0x8004C72Cu;
    // 8004C72C: li      r8, 125
    ctx->gpr[8] = (u32)(s32)(125);

label_8004C730:
    ctx->pc = 0x8004C730u;
    // 8004C730: bl      0x80258880
    {
            ctx->lr = 0x8004C734u;
            ctx->pc = 0x80258880u;
            return;
    }

label_8004C734:
    ctx->pc = 0x8004C734u;
    ctx->downcount -= 5;
    // 8004C734: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8004C738:
    ctx->pc = 0x8004C738u;
    // 8004C738: addi    r4, r1, 32
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(32);

label_8004C73C:
    ctx->pc = 0x8004C73Cu;
    // 8004C73C: lwz     r0, -31644(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31644);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004C740:
    ctx->pc = 0x8004C740u;
    // 8004C740: extsb r5, r0
    {
        ctx->gpr[5] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8004C744:
    ctx->pc = 0x8004C744u;
    // 8004C744: bl      0x8025BBF4
    {
            ctx->lr = 0x8004C748u;
            ctx->pc = 0x8025BBF4u;
            return;
    }

label_8004C748:
    ctx->pc = 0x8004C748u;
    ctx->downcount -= 4;
    // 8004C748: lwz     r3, -25612(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25612);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004C74C:
    ctx->pc = 0x8004C74Cu;
    // 8004C74C: lwz     r4, -25600(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25600);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004C750:
    ctx->pc = 0x8004C750u;
    // 8004C750: lwz     r5, -25596(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25596);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8004C754:
    ctx->pc = 0x8004C754u;
    // 8004C754: bl      0x8025BF28
    {
            ctx->lr = 0x8004C758u;
            ctx->pc = 0x8025BF28u;
            return;
    }

label_8004C758:
    ctx->pc = 0x8004C758u;
    ctx->downcount -= 13;
    // 8004C758: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8004C75C:
    ctx->pc = 0x8004C75Cu;
    // 8004C75C: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004C760:
    ctx->pc = 0x8004C760u;
    // 8004C760: li      r0, 3
    ctx->gpr[0] = (u32)(s32)(3);

label_8004C764:
    ctx->pc = 0x8004C764u;
    // 8004C764: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004C768:
    ctx->pc = 0x8004C768u;
    // 8004C768: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004C76C:
    ctx->pc = 0x8004C76Cu;
    // 8004C76C: lwz     r4, -25612(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25612);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004C770:
    ctx->pc = 0x8004C770u;
    // 8004C770: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004C774:
    ctx->pc = 0x8004C774u;
    // 8004C774: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_8004C778:
    ctx->pc = 0x8004C778u;
    // 8004C778: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004C77C:
    ctx->pc = 0x8004C77Cu;
    // 8004C77C: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8004C780:
    ctx->pc = 0x8004C780u;
    // 8004C780: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_8004C784:
    ctx->pc = 0x8004C784u;
    // 8004C784: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_8004C788:
    ctx->pc = 0x8004C788u;
    // 8004C788: bl      0x8025BB58
    {
            ctx->lr = 0x8004C78Cu;
            ctx->pc = 0x8025BB58u;
            return;
    }

label_8004C78C:
    ctx->pc = 0x8004C78Cu;
    ctx->downcount -= 6;
    // 8004C78C: addi    r3, r13, -31640
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-31640);

label_8004C790:
    ctx->pc = 0x8004C790u;
    // 8004C790: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8004C794:
    ctx->pc = 0x8004C794u;
    // 8004C794: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004C798:
    ctx->pc = 0x8004C798u;
    // 8004C798: addi    r6, r1, 20
    ctx->gpr[6] = ctx->gpr[1] + (u32)(s32)(20);

label_8004C79C:
    ctx->pc = 0x8004C79Cu;
    // 8004C79C: addi    r7, r1, 16
    ctx->gpr[7] = ctx->gpr[1] + (u32)(s32)(16);

label_8004C7A0:
    ctx->pc = 0x8004C7A0u;
    // 8004C7A0: bl      0x8004C16C
    {
            ctx->lr = 0x8004C7A4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8004C16Cu;
                return;
            }
            goto label_8004C16C;
    }

label_8004C7A4:
    ctx->pc = 0x8004C7A4u;
    ctx->downcount -= 3;
    // 8004C7A4: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004C7A8:
    ctx->pc = 0x8004C7A8u;
    // 8004C7A8: lwz     r4, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004C7AC:
    ctx->pc = 0x8004C7ACu;
    // 8004C7AC: bl      0x8025C790
    {
            ctx->lr = 0x8004C7B0u;
            ctx->pc = 0x8025C790u;
            return;
    }

label_8004C7B0:
    ctx->pc = 0x8004C7B0u;
    ctx->downcount -= 6;
    // 8004C7B0: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004C7B4:
    ctx->pc = 0x8004C7B4u;
    // 8004C7B4: li      r4, 14
    ctx->gpr[4] = (u32)(s32)(14);

label_8004C7B8:
    ctx->pc = 0x8004C7B8u;
    // 8004C7B8: li      r5, 8
    ctx->gpr[5] = (u32)(s32)(8);

label_8004C7BC:
    ctx->pc = 0x8004C7BCu;
    // 8004C7BC: li      r6, 11
    ctx->gpr[6] = (u32)(s32)(11);

label_8004C7C0:
    ctx->pc = 0x8004C7C0u;
    // 8004C7C0: li      r7, 15
    ctx->gpr[7] = (u32)(s32)(15);

label_8004C7C4:
    ctx->pc = 0x8004C7C4u;
    // 8004C7C4: bl      0x8025C3B0
    {
            ctx->lr = 0x8004C7C8u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_8004C7C8:
    ctx->pc = 0x8004C7C8u;
    ctx->downcount -= 6;
    // 8004C7C8: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004C7CC:
    ctx->pc = 0x8004C7CCu;
    // 8004C7CC: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_8004C7D0:
    ctx->pc = 0x8004C7D0u;
    // 8004C7D0: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_8004C7D4:
    ctx->pc = 0x8004C7D4u;
    // 8004C7D4: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_8004C7D8:
    ctx->pc = 0x8004C7D8u;
    // 8004C7D8: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004C7DC:
    ctx->pc = 0x8004C7DCu;
    // 8004C7DC: bl      0x8025C430
    {
            ctx->lr = 0x8004C7E0u;
            ctx->pc = 0x8025C430u;
            return;
    }

label_8004C7E0:
    ctx->pc = 0x8004C7E0u;
    ctx->downcount -= 7;
    // 8004C7E0: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004C7E4:
    ctx->pc = 0x8004C7E4u;
    // 8004C7E4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004C7E8:
    ctx->pc = 0x8004C7E8u;
    // 8004C7E8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004C7EC:
    ctx->pc = 0x8004C7ECu;
    // 8004C7EC: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004C7F0:
    ctx->pc = 0x8004C7F0u;
    // 8004C7F0: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004C7F4:
    ctx->pc = 0x8004C7F4u;
    // 8004C7F4: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_8004C7F8:
    ctx->pc = 0x8004C7F8u;
    // 8004C7F8: bl      0x8025C4B4
    {
            ctx->lr = 0x8004C7FCu;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_8004C7FC:
    ctx->pc = 0x8004C7FCu;
    ctx->downcount -= 7;
    // 8004C7FC: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004C800:
    ctx->pc = 0x8004C800u;
    // 8004C800: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004C804:
    ctx->pc = 0x8004C804u;
    // 8004C804: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004C808:
    ctx->pc = 0x8004C808u;
    // 8004C808: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004C80C:
    ctx->pc = 0x8004C80Cu;
    // 8004C80C: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004C810:
    ctx->pc = 0x8004C810u;
    // 8004C810: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8004C814:
    ctx->pc = 0x8004C814u;
    // 8004C814: bl      0x8025C574
    {
            ctx->lr = 0x8004C818u;
            ctx->pc = 0x8025C574u;
            return;
    }

label_8004C818:
    ctx->pc = 0x8004C818u;
    ctx->downcount -= 6;
    // 8004C818: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004C81C:
    ctx->pc = 0x8004C81Cu;
    // 8004C81C: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_8004C820:
    ctx->pc = 0x8004C820u;
    // 8004C820: li      r4, 255
    ctx->gpr[4] = (u32)(s32)(255);

label_8004C824:
    ctx->pc = 0x8004C824u;
    // 8004C824: li      r5, 255
    ctx->gpr[5] = (u32)(s32)(255);

label_8004C828:
    ctx->pc = 0x8004C828u;
    // 8004C828: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_8004C82C:
    ctx->pc = 0x8004C82Cu;
    // 8004C82C: bl      0x8025CA34
    {
            ctx->lr = 0x8004C830u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_8004C830:
    ctx->pc = 0x8004C830u;
    ctx->downcount -= 3;
    // 8004C830: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004C834:
    ctx->pc = 0x8004C834u;
    // 8004C834: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_8004C838:
    ctx->pc = 0x8004C838u;
    // 8004C838: bl      0x8025C08C
    {
            ctx->lr = 0x8004C83Cu;
            ctx->pc = 0x8025C08Cu;
            return;
    }

label_8004C83C:
    ctx->pc = 0x8004C83Cu;
    ctx->downcount -= 7;
    // 8004C83C: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004C840:
    ctx->pc = 0x8004C840u;
    // 8004C840: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_8004C844:
    ctx->pc = 0x8004C844u;
    // 8004C844: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_8004C848:
    ctx->pc = 0x8004C848u;
    // 8004C848: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004C84C:
    ctx->pc = 0x8004C84Cu;
    // 8004C84C: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_8004C850:
    ctx->pc = 0x8004C850u;
    // 8004C850: li      r7, 15
    ctx->gpr[7] = (u32)(s32)(15);

label_8004C854:
    ctx->pc = 0x8004C854u;
    // 8004C854: bl      0x8025C3B0
    {
            ctx->lr = 0x8004C858u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_8004C858:
    ctx->pc = 0x8004C858u;
    ctx->downcount -= 7;
    // 8004C858: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004C85C:
    ctx->pc = 0x8004C85Cu;
    // 8004C85C: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_8004C860:
    ctx->pc = 0x8004C860u;
    // 8004C860: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_8004C864:
    ctx->pc = 0x8004C864u;
    // 8004C864: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_8004C868:
    ctx->pc = 0x8004C868u;
    // 8004C868: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_8004C86C:
    ctx->pc = 0x8004C86Cu;
    // 8004C86C: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004C870:
    ctx->pc = 0x8004C870u;
    // 8004C870: bl      0x8025C430
    {
            ctx->lr = 0x8004C874u;
            ctx->pc = 0x8025C430u;
            return;
    }

label_8004C874:
    ctx->pc = 0x8004C874u;
    ctx->downcount -= 8;
    // 8004C874: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004C878:
    ctx->pc = 0x8004C878u;
    // 8004C878: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_8004C87C:
    ctx->pc = 0x8004C87Cu;
    // 8004C87C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004C880:
    ctx->pc = 0x8004C880u;
    // 8004C880: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004C884:
    ctx->pc = 0x8004C884u;
    // 8004C884: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004C888:
    ctx->pc = 0x8004C888u;
    // 8004C888: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004C88C:
    ctx->pc = 0x8004C88Cu;
    // 8004C88C: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8004C890:
    ctx->pc = 0x8004C890u;
    // 8004C890: bl      0x8025C4B4
    {
            ctx->lr = 0x8004C894u;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_8004C894:
    ctx->pc = 0x8004C894u;
    ctx->downcount -= 8;
    // 8004C894: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004C898:
    ctx->pc = 0x8004C898u;
    // 8004C898: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_8004C89C:
    ctx->pc = 0x8004C89Cu;
    // 8004C89C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004C8A0:
    ctx->pc = 0x8004C8A0u;
    // 8004C8A0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004C8A4:
    ctx->pc = 0x8004C8A4u;
    // 8004C8A4: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004C8A8:
    ctx->pc = 0x8004C8A8u;
    // 8004C8A8: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004C8AC:
    ctx->pc = 0x8004C8ACu;
    // 8004C8AC: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8004C8B0:
    ctx->pc = 0x8004C8B0u;
    // 8004C8B0: bl      0x8025C574
    {
            ctx->lr = 0x8004C8B4u;
            ctx->pc = 0x8025C574u;
            return;
    }

label_8004C8B4:
    ctx->pc = 0x8004C8B4u;
    ctx->downcount -= 5;
    // 8004C8B4: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8004C8B8:
    ctx->pc = 0x8004C8B8u;
    // 8004C8B8: stb     r0, -25688(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25688);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004C8BC:
    ctx->pc = 0x8004C8BCu;
    // 8004C8BC: lwz     r5, -25596(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25596);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8004C8C0:
    ctx->pc = 0x8004C8C0u;
    // 8004C8C0: cmplwi  r26, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[26]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C8C4:
    ctx->pc = 0x8004C8C4u;
    // 8004C8C4: bc    12, 2, 0x8004C8EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004C8EC;
        }
    }

label_8004C8C8:
    ctx->pc = 0x8004C8C8u;
    ctx->downcount -= 4;
    // 8004C8C8: addi    r3, r26, 32
    ctx->gpr[3] = ctx->gpr[26] + (u32)(s32)(32);

label_8004C8CC:
    ctx->pc = 0x8004C8CCu;
    // 8004C8CC: lbz     r0, 72(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(72);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8004C8D0:
    ctx->pc = 0x8004C8D0u;
    // 8004C8D0: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C8D4:
    ctx->pc = 0x8004C8D4u;
    // 8004C8D4: bc    12, 2, 0x8004C8E4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004C8E4;
        }
    }

label_8004C8D8:
    ctx->pc = 0x8004C8D8u;
    ctx->downcount -= 2;
    // 8004C8D8: lwz     r4, 64(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(64);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004C8DC:
    ctx->pc = 0x8004C8DCu;
    // 8004C8DC: bl      0x8025B0B8
    {
            ctx->lr = 0x8004C8E0u;
            ctx->pc = 0x8025B0B8u;
            return;
    }

label_8004C8E0:
    ctx->pc = 0x8004C8E0u;
    ctx->downcount -= 1;
    // 8004C8E0: b       0x8004C8EC
    {
            goto label_8004C8EC;
    }

label_8004C8E4:
    ctx->pc = 0x8004C8E4u;
    ctx->downcount -= 2;
    // 8004C8E4: or   r4, r5, r5
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8004C8E8:
    ctx->pc = 0x8004C8E8u;
    // 8004C8E8: bl      0x8025B260
    {
            ctx->lr = 0x8004C8ECu;
            ctx->pc = 0x8025B260u;
            return;
    }

label_8004C8EC:
    ctx->pc = 0x8004C8ECu;
    ctx->downcount -= 5;
    // 8004C8EC: lwz     r3, -25596(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25596);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004C8F0:
    ctx->pc = 0x8004C8F0u;
    // 8004C8F0: addi    r5, r3, 1
    ctx->gpr[5] = ctx->gpr[3] + (u32)(s32)(1);

label_8004C8F4:
    ctx->pc = 0x8004C8F4u;
    // 8004C8F4: lwz     r4, -25692(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25692);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004C8F8:
    ctx->pc = 0x8004C8F8u;
    // 8004C8F8: cmplwi  r4, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C8FC:
    ctx->pc = 0x8004C8FCu;
    // 8004C8FC: bc    12, 2, 0x8004C924
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004C924;
        }
    }

label_8004C900:
    ctx->pc = 0x8004C900u;
    ctx->downcount -= 4;
    // 8004C900: addi    r3, r4, 32
    ctx->gpr[3] = ctx->gpr[4] + (u32)(s32)(32);

label_8004C904:
    ctx->pc = 0x8004C904u;
    // 8004C904: lbz     r0, 72(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(72);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8004C908:
    ctx->pc = 0x8004C908u;
    // 8004C908: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C90C:
    ctx->pc = 0x8004C90Cu;
    // 8004C90C: bc    12, 2, 0x8004C91C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004C91C;
        }
    }

label_8004C910:
    ctx->pc = 0x8004C910u;
    ctx->downcount -= 2;
    // 8004C910: lwz     r4, 64(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(64);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004C914:
    ctx->pc = 0x8004C914u;
    // 8004C914: bl      0x8025B0B8
    {
            ctx->lr = 0x8004C918u;
            ctx->pc = 0x8025B0B8u;
            return;
    }

label_8004C918:
    ctx->pc = 0x8004C918u;
    ctx->downcount -= 1;
    // 8004C918: b       0x8004C924
    {
            goto label_8004C924;
    }

label_8004C91C:
    ctx->pc = 0x8004C91Cu;
    ctx->downcount -= 2;
    // 8004C91C: or   r4, r5, r5
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8004C920:
    ctx->pc = 0x8004C920u;
    // 8004C920: bl      0x8025B260
    {
            ctx->lr = 0x8004C924u;
            ctx->pc = 0x8025B260u;
            return;
    }

label_8004C924:
    ctx->pc = 0x8004C924u;
    ctx->downcount -= 23;
    // 8004C924: lwz     r3, -25616(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25616);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004C928:
    ctx->pc = 0x8004C928u;
    // 8004C928: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8004C92C:
    ctx->pc = 0x8004C92Cu;
    // 8004C92C: stw     r0, -25616(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25616);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004C930:
    ctx->pc = 0x8004C930u;
    // 8004C930: lwz     r3, -25600(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25600);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004C934:
    ctx->pc = 0x8004C934u;
    // 8004C934: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8004C938:
    ctx->pc = 0x8004C938u;
    // 8004C938: stw     r0, -25600(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25600);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004C93C:
    ctx->pc = 0x8004C93Cu;
    // 8004C93C: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004C940:
    ctx->pc = 0x8004C940u;
    // 8004C940: addi    r0, r3, 2
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(2);

label_8004C944:
    ctx->pc = 0x8004C944u;
    // 8004C944: stw     r0, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004C948:
    ctx->pc = 0x8004C948u;
    // 8004C948: lwz     r3, -25596(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25596);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004C94C:
    ctx->pc = 0x8004C94Cu;
    // 8004C94C: addi    r0, r3, 2
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(2);

label_8004C950:
    ctx->pc = 0x8004C950u;
    // 8004C950: stw     r0, -25596(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25596);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004C954:
    ctx->pc = 0x8004C954u;
    // 8004C954: lbz     r3, -25630(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25630);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8004C958:
    ctx->pc = 0x8004C958u;
    // 8004C958: addi    r0, r3, 2
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(2);

label_8004C95C:
    ctx->pc = 0x8004C95Cu;
    // 8004C95C: stb     r0, -25630(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25630);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004C960:
    ctx->pc = 0x8004C960u;
    // 8004C960: lbz     r3, -25631(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25631);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8004C964:
    ctx->pc = 0x8004C964u;
    // 8004C964: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8004C968:
    ctx->pc = 0x8004C968u;
    // 8004C968: stb     r0, -25631(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25631);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004C96C:
    ctx->pc = 0x8004C96Cu;
    // 8004C96C: lbz     r3, -25632(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25632);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8004C970:
    ctx->pc = 0x8004C970u;
    // 8004C970: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8004C974:
    ctx->pc = 0x8004C974u;
    // 8004C974: stb     r0, -25632(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25632);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004C978:
    ctx->pc = 0x8004C978u;
    // 8004C978: addi    r11, r1, 96
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(96);

label_8004C97C:
    ctx->pc = 0x8004C97Cu;
    // 8004C97C: bl      0x80286A88
    {
            ctx->lr = 0x8004C980u;
            ctx->pc = 0x80286A88u;
            return;
    }

label_8004C980:
    ctx->pc = 0x8004C980u;
    ctx->downcount -= 5;
    // 8004C980: lwz     r0, 100(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(100);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004C984:
    ctx->pc = 0x8004C984u;
    // 8004C984: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004C988:
    ctx->pc = 0x8004C988u;
    // 8004C988: addi    r1, r1, 96
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(96);

label_8004C98C:
    ctx->pc = 0x8004C98Cu;
    // 8004C98C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004C990:
    ctx->pc = 0x8004C990u;
    ctx->downcount -= 5;
    // 8004C990: stwu     r1, -160(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-160);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004C994:
    ctx->pc = 0x8004C994u;
    // 8004C994: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004C998:
    ctx->pc = 0x8004C998u;
    // 8004C998: stw     r0, 164(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(164);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004C99C:
    ctx->pc = 0x8004C99Cu;
    // 8004C99C: addi    r11, r1, 160
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(160);

label_8004C9A0:
    ctx->pc = 0x8004C9A0u;
    // 8004C9A0: bl      0x80286A4C
    {
            ctx->lr = 0x8004C9A4u;
            ctx->pc = 0x80286A4Cu;
            return;
    }

label_8004C9A4:
    ctx->pc = 0x8004C9A4u;
    ctx->downcount -= 8;
    // 8004C9A4: or   r27, r3, r3
    {
        ctx->gpr[27] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004C9A8:
    ctx->pc = 0x8004C9A8u;
    // 8004C9A8: or   r28, r4, r4
    {
        ctx->gpr[28] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8004C9AC:
    ctx->pc = 0x8004C9ACu;
    // 8004C9AC: or   r29, r5, r5
    {
        ctx->gpr[29] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8004C9B0:
    ctx->pc = 0x8004C9B0u;
    // 8004C9B0: or   r30, r6, r6
    {
        ctx->gpr[30] = ctx->gpr[6] | ctx->gpr[6];
    }

label_8004C9B4:
    ctx->pc = 0x8004C9B4u;
    // 8004C9B4: or   r31, r7, r7
    {
        ctx->gpr[31] = ctx->gpr[7] | ctx->gpr[7];
    }

label_8004C9B8:
    ctx->pc = 0x8004C9B8u;
    // 8004C9B8: lbz     r0, -25630(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25630);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8004C9BC:
    ctx->pc = 0x8004C9BCu;
    // 8004C9BC: cmplwi  r0, 0x000B
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x000Bu);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C9C0:
    ctx->pc = 0x8004C9C0u;
    // 8004C9C0: bc    12, 1, 0x8004CFD8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004CFD8;
        }
    }

label_8004C9C4:
    ctx->pc = 0x8004C9C4u;
    ctx->downcount -= 3;
    // 8004C9C4: lbz     r0, -25631(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25631);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8004C9C8:
    ctx->pc = 0x8004C9C8u;
    // 8004C9C8: cmplwi  r0, 0x0006
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0006u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C9CC:
    ctx->pc = 0x8004C9CCu;
    // 8004C9CC: bc    12, 1, 0x8004CFD8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004CFD8;
        }
    }

label_8004C9D0:
    ctx->pc = 0x8004C9D0u;
    ctx->downcount -= 3;
    // 8004C9D0: lwz     r0, -25596(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25596);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004C9D4:
    ctx->pc = 0x8004C9D4u;
    // 8004C9D4: cmpwi   r0, 5
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(5);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C9D8:
    ctx->pc = 0x8004C9D8u;
    // 8004C9D8: bc    12, 1, 0x8004CFD8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004CFD8;
        }
    }

label_8004C9DC:
    ctx->pc = 0x8004C9DCu;
    ctx->downcount -= 3;
    // 8004C9DC: lwz     r0, -25620(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25620);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004C9E0:
    ctx->pc = 0x8004C9E0u;
    // 8004C9E0: cmpwi   r0, 1
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004C9E4:
    ctx->pc = 0x8004C9E4u;
    // 8004C9E4: bc    4, 1, 0x8004C9EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004C9EC;
        }
    }

label_8004C9E8:
    ctx->pc = 0x8004C9E8u;
    ctx->downcount -= 1;
    // 8004C9E8: b       0x8004CFD8
    {
            goto label_8004CFD8;
    }

label_8004C9EC:
    ctx->pc = 0x8004C9ECu;
    ctx->downcount -= 7;
    // 8004C9EC: lwz     r3, -25600(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25600);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004C9F0:
    ctx->pc = 0x8004C9F0u;
    // 8004C9F0: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8004C9F4:
    ctx->pc = 0x8004C9F4u;
    // 8004C9F4: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_8004C9F8:
    ctx->pc = 0x8004C9F8u;
    // 8004C9F8: li      r6, 60
    ctx->gpr[6] = (u32)(s32)(60);

label_8004C9FC:
    ctx->pc = 0x8004C9FCu;
    // 8004C9FC: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004CA00:
    ctx->pc = 0x8004CA00u;
    // 8004CA00: li      r8, 125
    ctx->gpr[8] = (u32)(s32)(125);

label_8004CA04:
    ctx->pc = 0x8004CA04u;
    // 8004CA04: bl      0x80258880
    {
            ctx->lr = 0x8004CA08u;
            ctx->pc = 0x80258880u;
            return;
    }

label_8004CA08:
    ctx->pc = 0x8004CA08u;
    ctx->downcount -= 8;
    // 8004CA08: lwz     r3, -25600(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25600);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CA0C:
    ctx->pc = 0x8004CA0Cu;
    // 8004CA0C: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_8004CA10:
    ctx->pc = 0x8004CA10u;
    // 8004CA10: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8004CA14:
    ctx->pc = 0x8004CA14u;
    // 8004CA14: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_8004CA18:
    ctx->pc = 0x8004CA18u;
    // 8004CA18: li      r6, 60
    ctx->gpr[6] = (u32)(s32)(60);

label_8004CA1C:
    ctx->pc = 0x8004CA1Cu;
    // 8004CA1C: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004CA20:
    ctx->pc = 0x8004CA20u;
    // 8004CA20: li      r8, 125
    ctx->gpr[8] = (u32)(s32)(125);

label_8004CA24:
    ctx->pc = 0x8004CA24u;
    // 8004CA24: bl      0x80258880
    {
            ctx->lr = 0x8004CA28u;
            ctx->pc = 0x80258880u;
            return;
    }

label_8004CA28:
    ctx->pc = 0x8004CA28u;
    ctx->downcount -= 7;
    // 8004CA28: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CA2C:
    ctx->pc = 0x8004CA2Cu;
    // 8004CA2C: lwz     r4, -25600(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25600);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004CA30:
    ctx->pc = 0x8004CA30u;
    // 8004CA30: addi    r4, r4, 1
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(1);

label_8004CA34:
    ctx->pc = 0x8004CA34u;
    // 8004CA34: lwz     r5, -25596(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25596);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8004CA38:
    ctx->pc = 0x8004CA38u;
    // 8004CA38: addi    r5, r5, 1
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(1);

label_8004CA3C:
    ctx->pc = 0x8004CA3Cu;
    // 8004CA3C: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_8004CA40:
    ctx->pc = 0x8004CA40u;
    // 8004CA40: bl      0x8025CA34
    {
            ctx->lr = 0x8004CA44u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_8004CA44:
    ctx->pc = 0x8004CA44u;
    ctx->downcount -= 2;
    // 8004CA44: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CA48:
    ctx->pc = 0x8004CA48u;
    // 8004CA48: bl      0x8025C08C
    {
            ctx->lr = 0x8004CA4Cu;
            ctx->pc = 0x8025C08Cu;
            return;
    }

label_8004CA4C:
    ctx->pc = 0x8004CA4Cu;
    ctx->downcount -= 6;
    // 8004CA4C: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CA50:
    ctx->pc = 0x8004CA50u;
    // 8004CA50: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_8004CA54:
    ctx->pc = 0x8004CA54u;
    // 8004CA54: li      r5, 8
    ctx->gpr[5] = (u32)(s32)(8);

label_8004CA58:
    ctx->pc = 0x8004CA58u;
    // 8004CA58: li      r6, 14
    ctx->gpr[6] = (u32)(s32)(14);

label_8004CA5C:
    ctx->pc = 0x8004CA5Cu;
    // 8004CA5C: li      r7, 2
    ctx->gpr[7] = (u32)(s32)(2);

label_8004CA60:
    ctx->pc = 0x8004CA60u;
    // 8004CA60: bl      0x8025C3B0
    {
            ctx->lr = 0x8004CA64u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_8004CA64:
    ctx->pc = 0x8004CA64u;
    ctx->downcount -= 7;
    // 8004CA64: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CA68:
    ctx->pc = 0x8004CA68u;
    // 8004CA68: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004CA6C:
    ctx->pc = 0x8004CA6Cu;
    // 8004CA6C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004CA70:
    ctx->pc = 0x8004CA70u;
    // 8004CA70: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004CA74:
    ctx->pc = 0x8004CA74u;
    // 8004CA74: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004CA78:
    ctx->pc = 0x8004CA78u;
    // 8004CA78: li      r8, 2
    ctx->gpr[8] = (u32)(s32)(2);

label_8004CA7C:
    ctx->pc = 0x8004CA7Cu;
    // 8004CA7C: bl      0x8025C4B4
    {
            ctx->lr = 0x8004CA80u;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_8004CA80:
    ctx->pc = 0x8004CA80u;
    ctx->downcount -= 6;
    // 8004CA80: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CA84:
    ctx->pc = 0x8004CA84u;
    // 8004CA84: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_8004CA88:
    ctx->pc = 0x8004CA88u;
    // 8004CA88: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_8004CA8C:
    ctx->pc = 0x8004CA8Cu;
    // 8004CA8C: li      r6, 6
    ctx->gpr[6] = (u32)(s32)(6);

label_8004CA90:
    ctx->pc = 0x8004CA90u;
    // 8004CA90: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004CA94:
    ctx->pc = 0x8004CA94u;
    // 8004CA94: bl      0x8025C430
    {
            ctx->lr = 0x8004CA98u;
            ctx->pc = 0x8025C430u;
            return;
    }

label_8004CA98:
    ctx->pc = 0x8004CA98u;
    ctx->downcount -= 7;
    // 8004CA98: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CA9C:
    ctx->pc = 0x8004CA9Cu;
    // 8004CA9C: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8004CAA0:
    ctx->pc = 0x8004CAA0u;
    // 8004CAA0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004CAA4:
    ctx->pc = 0x8004CAA4u;
    // 8004CAA4: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004CAA8:
    ctx->pc = 0x8004CAA8u;
    // 8004CAA8: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004CAAC:
    ctx->pc = 0x8004CAACu;
    // 8004CAAC: li      r8, 2
    ctx->gpr[8] = (u32)(s32)(2);

label_8004CAB0:
    ctx->pc = 0x8004CAB0u;
    // 8004CAB0: bl      0x8025C574
    {
            ctx->lr = 0x8004CAB4u;
            ctx->pc = 0x8025C574u;
            return;
    }

label_8004CAB4:
    ctx->pc = 0x8004CAB4u;
    ctx->downcount -= 3;
    // 8004CAB4: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CAB8:
    ctx->pc = 0x8004CAB8u;
    // 8004CAB8: lwz     r4, -25624(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25624);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004CABC:
    ctx->pc = 0x8004CABCu;
    // 8004CABC: bl      0x8025C790
    {
            ctx->lr = 0x8004CAC0u;
            ctx->pc = 0x8025C790u;
            return;
    }

label_8004CAC0:
    ctx->pc = 0x8004CAC0u;
    ctx->downcount -= 3;
    // 8004CAC0: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CAC4:
    ctx->pc = 0x8004CAC4u;
    // 8004CAC4: lwz     r4, -25628(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25628);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004CAC8:
    ctx->pc = 0x8004CAC8u;
    // 8004CAC8: bl      0x8025C7FC
    {
            ctx->lr = 0x8004CACCu;
            ctx->pc = 0x8025C7FCu;
            return;
    }

label_8004CACC:
    ctx->pc = 0x8004CACCu;
    ctx->downcount -= 4;
    // 8004CACC: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CAD0:
    ctx->pc = 0x8004CAD0u;
    // 8004CAD0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004CAD4:
    ctx->pc = 0x8004CAD4u;
    // 8004CAD4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004CAD8:
    ctx->pc = 0x8004CAD8u;
    // 8004CAD8: bl      0x8025C868
    {
            ctx->lr = 0x8004CADCu;
            ctx->pc = 0x8025C868u;
            return;
    }

label_8004CADC:
    ctx->pc = 0x8004CADCu;
    ctx->downcount -= 8;
    // 8004CADC: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CAE0:
    ctx->pc = 0x8004CAE0u;
    // 8004CAE0: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_8004CAE4:
    ctx->pc = 0x8004CAE4u;
    // 8004CAE4: lwz     r4, -25600(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25600);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004CAE8:
    ctx->pc = 0x8004CAE8u;
    // 8004CAE8: addi    r4, r4, 1
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(1);

label_8004CAEC:
    ctx->pc = 0x8004CAECu;
    // 8004CAEC: lwz     r5, -25596(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25596);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8004CAF0:
    ctx->pc = 0x8004CAF0u;
    // 8004CAF0: addi    r5, r5, 2
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(2);

label_8004CAF4:
    ctx->pc = 0x8004CAF4u;
    // 8004CAF4: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_8004CAF8:
    ctx->pc = 0x8004CAF8u;
    // 8004CAF8: bl      0x8025CA34
    {
            ctx->lr = 0x8004CAFCu;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_8004CAFC:
    ctx->pc = 0x8004CAFCu;
    ctx->downcount -= 3;
    // 8004CAFC: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CB00:
    ctx->pc = 0x8004CB00u;
    // 8004CB00: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_8004CB04:
    ctx->pc = 0x8004CB04u;
    // 8004CB04: bl      0x8025C08C
    {
            ctx->lr = 0x8004CB08u;
            ctx->pc = 0x8025C08Cu;
            return;
    }

label_8004CB08:
    ctx->pc = 0x8004CB08u;
    ctx->downcount -= 7;
    // 8004CB08: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CB0C:
    ctx->pc = 0x8004CB0Cu;
    // 8004CB0C: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_8004CB10:
    ctx->pc = 0x8004CB10u;
    // 8004CB10: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_8004CB14:
    ctx->pc = 0x8004CB14u;
    // 8004CB14: li      r5, 8
    ctx->gpr[5] = (u32)(s32)(8);

label_8004CB18:
    ctx->pc = 0x8004CB18u;
    // 8004CB18: li      r6, 14
    ctx->gpr[6] = (u32)(s32)(14);

label_8004CB1C:
    ctx->pc = 0x8004CB1Cu;
    // 8004CB1C: li      r7, 4
    ctx->gpr[7] = (u32)(s32)(4);

label_8004CB20:
    ctx->pc = 0x8004CB20u;
    // 8004CB20: bl      0x8025C3B0
    {
            ctx->lr = 0x8004CB24u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_8004CB24:
    ctx->pc = 0x8004CB24u;
    ctx->downcount -= 8;
    // 8004CB24: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CB28:
    ctx->pc = 0x8004CB28u;
    // 8004CB28: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_8004CB2C:
    ctx->pc = 0x8004CB2Cu;
    // 8004CB2C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004CB30:
    ctx->pc = 0x8004CB30u;
    // 8004CB30: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004CB34:
    ctx->pc = 0x8004CB34u;
    // 8004CB34: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_8004CB38:
    ctx->pc = 0x8004CB38u;
    // 8004CB38: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004CB3C:
    ctx->pc = 0x8004CB3Cu;
    // 8004CB3C: li      r8, 2
    ctx->gpr[8] = (u32)(s32)(2);

label_8004CB40:
    ctx->pc = 0x8004CB40u;
    // 8004CB40: bl      0x8025C4B4
    {
            ctx->lr = 0x8004CB44u;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_8004CB44:
    ctx->pc = 0x8004CB44u;
    ctx->downcount -= 7;
    // 8004CB44: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CB48:
    ctx->pc = 0x8004CB48u;
    // 8004CB48: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_8004CB4C:
    ctx->pc = 0x8004CB4Cu;
    // 8004CB4C: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_8004CB50:
    ctx->pc = 0x8004CB50u;
    // 8004CB50: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_8004CB54:
    ctx->pc = 0x8004CB54u;
    // 8004CB54: li      r6, 6
    ctx->gpr[6] = (u32)(s32)(6);

label_8004CB58:
    ctx->pc = 0x8004CB58u;
    // 8004CB58: li      r7, 2
    ctx->gpr[7] = (u32)(s32)(2);

label_8004CB5C:
    ctx->pc = 0x8004CB5Cu;
    // 8004CB5C: bl      0x8025C430
    {
            ctx->lr = 0x8004CB60u;
            ctx->pc = 0x8025C430u;
            return;
    }

label_8004CB60:
    ctx->pc = 0x8004CB60u;
    ctx->downcount -= 8;
    // 8004CB60: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CB64:
    ctx->pc = 0x8004CB64u;
    // 8004CB64: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_8004CB68:
    ctx->pc = 0x8004CB68u;
    // 8004CB68: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8004CB6C:
    ctx->pc = 0x8004CB6Cu;
    // 8004CB6C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004CB70:
    ctx->pc = 0x8004CB70u;
    // 8004CB70: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004CB74:
    ctx->pc = 0x8004CB74u;
    // 8004CB74: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004CB78:
    ctx->pc = 0x8004CB78u;
    // 8004CB78: li      r8, 2
    ctx->gpr[8] = (u32)(s32)(2);

label_8004CB7C:
    ctx->pc = 0x8004CB7Cu;
    // 8004CB7C: bl      0x8025C574
    {
            ctx->lr = 0x8004CB80u;
            ctx->pc = 0x8025C574u;
            return;
    }

label_8004CB80:
    ctx->pc = 0x8004CB80u;
    ctx->downcount -= 5;
    // 8004CB80: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CB84:
    ctx->pc = 0x8004CB84u;
    // 8004CB84: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_8004CB88:
    ctx->pc = 0x8004CB88u;
    // 8004CB88: lwz     r4, -25624(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25624);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004CB8C:
    ctx->pc = 0x8004CB8Cu;
    // 8004CB8C: addi    r4, r4, 1
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(1);

label_8004CB90:
    ctx->pc = 0x8004CB90u;
    // 8004CB90: bl      0x8025C790
    {
            ctx->lr = 0x8004CB94u;
            ctx->pc = 0x8025C790u;
            return;
    }

label_8004CB94:
    ctx->pc = 0x8004CB94u;
    ctx->downcount -= 5;
    // 8004CB94: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CB98:
    ctx->pc = 0x8004CB98u;
    // 8004CB98: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_8004CB9C:
    ctx->pc = 0x8004CB9Cu;
    // 8004CB9C: lwz     r4, -25628(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25628);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004CBA0:
    ctx->pc = 0x8004CBA0u;
    // 8004CBA0: addi    r4, r4, 1
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(1);

label_8004CBA4:
    ctx->pc = 0x8004CBA4u;
    // 8004CBA4: bl      0x8025C7FC
    {
            ctx->lr = 0x8004CBA8u;
            ctx->pc = 0x8025C7FCu;
            return;
    }

label_8004CBA8:
    ctx->pc = 0x8004CBA8u;
    ctx->downcount -= 5;
    // 8004CBA8: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CBAC:
    ctx->pc = 0x8004CBACu;
    // 8004CBAC: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_8004CBB0:
    ctx->pc = 0x8004CBB0u;
    // 8004CBB0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004CBB4:
    ctx->pc = 0x8004CBB4u;
    // 8004CBB4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004CBB8:
    ctx->pc = 0x8004CBB8u;
    // 8004CBB8: bl      0x8025C868
    {
            ctx->lr = 0x8004CBBCu;
            ctx->pc = 0x8025C868u;
            return;
    }

label_8004CBBC:
    ctx->pc = 0x8004CBBCu;
    ctx->downcount -= 6;
    // 8004CBBC: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CBC0:
    ctx->pc = 0x8004CBC0u;
    // 8004CBC0: addi    r3, r3, 2
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(2);

label_8004CBC4:
    ctx->pc = 0x8004CBC4u;
    // 8004CBC4: lwz     r4, -25600(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25600);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004CBC8:
    ctx->pc = 0x8004CBC8u;
    // 8004CBC8: lwz     r5, -25596(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25596);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8004CBCC:
    ctx->pc = 0x8004CBCCu;
    // 8004CBCC: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_8004CBD0:
    ctx->pc = 0x8004CBD0u;
    // 8004CBD0: bl      0x8025CA34
    {
            ctx->lr = 0x8004CBD4u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_8004CBD4:
    ctx->pc = 0x8004CBD4u;
    ctx->downcount -= 3;
    // 8004CBD4: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CBD8:
    ctx->pc = 0x8004CBD8u;
    // 8004CBD8: addi    r3, r3, 2
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(2);

label_8004CBDC:
    ctx->pc = 0x8004CBDCu;
    // 8004CBDC: bl      0x8025C08C
    {
            ctx->lr = 0x8004CBE0u;
            ctx->pc = 0x8025C08Cu;
            return;
    }

label_8004CBE0:
    ctx->pc = 0x8004CBE0u;
    ctx->downcount -= 7;
    // 8004CBE0: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CBE4:
    ctx->pc = 0x8004CBE4u;
    // 8004CBE4: addi    r3, r3, 2
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(2);

label_8004CBE8:
    ctx->pc = 0x8004CBE8u;
    // 8004CBE8: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_8004CBEC:
    ctx->pc = 0x8004CBECu;
    // 8004CBEC: li      r5, 8
    ctx->gpr[5] = (u32)(s32)(8);

label_8004CBF0:
    ctx->pc = 0x8004CBF0u;
    // 8004CBF0: li      r6, 12
    ctx->gpr[6] = (u32)(s32)(12);

label_8004CBF4:
    ctx->pc = 0x8004CBF4u;
    // 8004CBF4: li      r7, 4
    ctx->gpr[7] = (u32)(s32)(4);

label_8004CBF8:
    ctx->pc = 0x8004CBF8u;
    // 8004CBF8: bl      0x8025C3B0
    {
            ctx->lr = 0x8004CBFCu;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_8004CBFC:
    ctx->pc = 0x8004CBFCu;
    ctx->downcount -= 8;
    // 8004CBFC: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CC00:
    ctx->pc = 0x8004CC00u;
    // 8004CC00: addi    r3, r3, 2
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(2);

label_8004CC04:
    ctx->pc = 0x8004CC04u;
    // 8004CC04: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004CC08:
    ctx->pc = 0x8004CC08u;
    // 8004CC08: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004CC0C:
    ctx->pc = 0x8004CC0Cu;
    // 8004CC0C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004CC10:
    ctx->pc = 0x8004CC10u;
    // 8004CC10: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004CC14:
    ctx->pc = 0x8004CC14u;
    // 8004CC14: li      r8, 2
    ctx->gpr[8] = (u32)(s32)(2);

label_8004CC18:
    ctx->pc = 0x8004CC18u;
    // 8004CC18: bl      0x8025C4B4
    {
            ctx->lr = 0x8004CC1Cu;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_8004CC1C:
    ctx->pc = 0x8004CC1Cu;
    ctx->downcount -= 7;
    // 8004CC1C: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CC20:
    ctx->pc = 0x8004CC20u;
    // 8004CC20: addi    r3, r3, 2
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(2);

label_8004CC24:
    ctx->pc = 0x8004CC24u;
    // 8004CC24: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_8004CC28:
    ctx->pc = 0x8004CC28u;
    // 8004CC28: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_8004CC2C:
    ctx->pc = 0x8004CC2Cu;
    // 8004CC2C: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_8004CC30:
    ctx->pc = 0x8004CC30u;
    // 8004CC30: li      r7, 2
    ctx->gpr[7] = (u32)(s32)(2);

label_8004CC34:
    ctx->pc = 0x8004CC34u;
    // 8004CC34: bl      0x8025C430
    {
            ctx->lr = 0x8004CC38u;
            ctx->pc = 0x8025C430u;
            return;
    }

label_8004CC38:
    ctx->pc = 0x8004CC38u;
    ctx->downcount -= 8;
    // 8004CC38: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CC3C:
    ctx->pc = 0x8004CC3Cu;
    // 8004CC3C: addi    r3, r3, 2
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(2);

label_8004CC40:
    ctx->pc = 0x8004CC40u;
    // 8004CC40: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004CC44:
    ctx->pc = 0x8004CC44u;
    // 8004CC44: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004CC48:
    ctx->pc = 0x8004CC48u;
    // 8004CC48: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004CC4C:
    ctx->pc = 0x8004CC4Cu;
    // 8004CC4C: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004CC50:
    ctx->pc = 0x8004CC50u;
    // 8004CC50: li      r8, 2
    ctx->gpr[8] = (u32)(s32)(2);

label_8004CC54:
    ctx->pc = 0x8004CC54u;
    // 8004CC54: bl      0x8025C574
    {
            ctx->lr = 0x8004CC58u;
            ctx->pc = 0x8025C574u;
            return;
    }

label_8004CC58:
    ctx->pc = 0x8004CC58u;
    ctx->downcount -= 5;
    // 8004CC58: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CC5C:
    ctx->pc = 0x8004CC5Cu;
    // 8004CC5C: addi    r3, r3, 2
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(2);

label_8004CC60:
    ctx->pc = 0x8004CC60u;
    // 8004CC60: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004CC64:
    ctx->pc = 0x8004CC64u;
    // 8004CC64: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004CC68:
    ctx->pc = 0x8004CC68u;
    // 8004CC68: bl      0x8025C868
    {
            ctx->lr = 0x8004CC6Cu;
            ctx->pc = 0x8025C868u;
            return;
    }

label_8004CC6C:
    ctx->pc = 0x8004CC6Cu;
    ctx->downcount -= 6;
    // 8004CC6C: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CC70:
    ctx->pc = 0x8004CC70u;
    // 8004CC70: addi    r3, r3, 3
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(3);

label_8004CC74:
    ctx->pc = 0x8004CC74u;
    // 8004CC74: li      r4, 255
    ctx->gpr[4] = (u32)(s32)(255);

label_8004CC78:
    ctx->pc = 0x8004CC78u;
    // 8004CC78: li      r5, 255
    ctx->gpr[5] = (u32)(s32)(255);

label_8004CC7C:
    ctx->pc = 0x8004CC7Cu;
    // 8004CC7C: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_8004CC80:
    ctx->pc = 0x8004CC80u;
    // 8004CC80: bl      0x8025CA34
    {
            ctx->lr = 0x8004CC84u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_8004CC84:
    ctx->pc = 0x8004CC84u;
    ctx->downcount -= 3;
    // 8004CC84: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CC88:
    ctx->pc = 0x8004CC88u;
    // 8004CC88: addi    r3, r3, 3
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(3);

label_8004CC8C:
    ctx->pc = 0x8004CC8Cu;
    // 8004CC8C: bl      0x8025C08C
    {
            ctx->lr = 0x8004CC90u;
            ctx->pc = 0x8025C08Cu;
            return;
    }

label_8004CC90:
    ctx->pc = 0x8004CC90u;
    ctx->downcount -= 7;
    // 8004CC90: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CC94:
    ctx->pc = 0x8004CC94u;
    // 8004CC94: addi    r3, r3, 3
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(3);

label_8004CC98:
    ctx->pc = 0x8004CC98u;
    // 8004CC98: li      r4, 5
    ctx->gpr[4] = (u32)(s32)(5);

label_8004CC9C:
    ctx->pc = 0x8004CC9Cu;
    // 8004CC9C: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_8004CCA0:
    ctx->pc = 0x8004CCA0u;
    // 8004CCA0: li      r6, 14
    ctx->gpr[6] = (u32)(s32)(14);

label_8004CCA4:
    ctx->pc = 0x8004CCA4u;
    // 8004CCA4: li      r7, 15
    ctx->gpr[7] = (u32)(s32)(15);

label_8004CCA8:
    ctx->pc = 0x8004CCA8u;
    // 8004CCA8: bl      0x8025C3B0
    {
            ctx->lr = 0x8004CCACu;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_8004CCAC:
    ctx->pc = 0x8004CCACu;
    ctx->downcount -= 8;
    // 8004CCAC: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CCB0:
    ctx->pc = 0x8004CCB0u;
    // 8004CCB0: addi    r3, r3, 3
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(3);

label_8004CCB4:
    ctx->pc = 0x8004CCB4u;
    // 8004CCB4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004CCB8:
    ctx->pc = 0x8004CCB8u;
    // 8004CCB8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004CCBC:
    ctx->pc = 0x8004CCBCu;
    // 8004CCBC: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004CCC0:
    ctx->pc = 0x8004CCC0u;
    // 8004CCC0: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004CCC4:
    ctx->pc = 0x8004CCC4u;
    // 8004CCC4: li      r8, 2
    ctx->gpr[8] = (u32)(s32)(2);

label_8004CCC8:
    ctx->pc = 0x8004CCC8u;
    // 8004CCC8: bl      0x8025C4B4
    {
            ctx->lr = 0x8004CCCCu;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_8004CCCC:
    ctx->pc = 0x8004CCCCu;
    ctx->downcount -= 7;
    // 8004CCCC: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CCD0:
    ctx->pc = 0x8004CCD0u;
    // 8004CCD0: addi    r3, r3, 3
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(3);

label_8004CCD4:
    ctx->pc = 0x8004CCD4u;
    // 8004CCD4: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_8004CCD8:
    ctx->pc = 0x8004CCD8u;
    // 8004CCD8: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_8004CCDC:
    ctx->pc = 0x8004CCDCu;
    // 8004CCDC: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_8004CCE0:
    ctx->pc = 0x8004CCE0u;
    // 8004CCE0: li      r7, 7
    ctx->gpr[7] = (u32)(s32)(7);

label_8004CCE4:
    ctx->pc = 0x8004CCE4u;
    // 8004CCE4: bl      0x8025C430
    {
            ctx->lr = 0x8004CCE8u;
            ctx->pc = 0x8025C430u;
            return;
    }

label_8004CCE8:
    ctx->pc = 0x8004CCE8u;
    ctx->downcount -= 8;
    // 8004CCE8: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CCEC:
    ctx->pc = 0x8004CCECu;
    // 8004CCEC: addi    r3, r3, 3
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(3);

label_8004CCF0:
    ctx->pc = 0x8004CCF0u;
    // 8004CCF0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004CCF4:
    ctx->pc = 0x8004CCF4u;
    // 8004CCF4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004CCF8:
    ctx->pc = 0x8004CCF8u;
    // 8004CCF8: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004CCFC:
    ctx->pc = 0x8004CCFCu;
    // 8004CCFC: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004CD00:
    ctx->pc = 0x8004CD00u;
    // 8004CD00: li      r8, 2
    ctx->gpr[8] = (u32)(s32)(2);

label_8004CD04:
    ctx->pc = 0x8004CD04u;
    // 8004CD04: bl      0x8025C574
    {
            ctx->lr = 0x8004CD08u;
            ctx->pc = 0x8025C574u;
            return;
    }

label_8004CD08:
    ctx->pc = 0x8004CD08u;
    ctx->downcount -= 5;
    // 8004CD08: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CD0C:
    ctx->pc = 0x8004CD0Cu;
    // 8004CD0C: addi    r3, r3, 3
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(3);

label_8004CD10:
    ctx->pc = 0x8004CD10u;
    // 8004CD10: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004CD14:
    ctx->pc = 0x8004CD14u;
    // 8004CD14: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004CD18:
    ctx->pc = 0x8004CD18u;
    // 8004CD18: bl      0x8025C868
    {
            ctx->lr = 0x8004CD1Cu;
            ctx->pc = 0x8025C868u;
            return;
    }

label_8004CD1C:
    ctx->pc = 0x8004CD1Cu;
    ctx->downcount -= 5;
    // 8004CD1C: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CD20:
    ctx->pc = 0x8004CD20u;
    // 8004CD20: addi    r3, r3, 3
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(3);

label_8004CD24:
    ctx->pc = 0x8004CD24u;
    // 8004CD24: lwz     r4, -25624(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25624);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004CD28:
    ctx->pc = 0x8004CD28u;
    // 8004CD28: addi    r4, r4, 2
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(2);

label_8004CD2C:
    ctx->pc = 0x8004CD2Cu;
    // 8004CD2C: bl      0x8025C790
    {
            ctx->lr = 0x8004CD30u;
            ctx->pc = 0x8025C790u;
            return;
    }

label_8004CD30:
    ctx->pc = 0x8004CD30u;
    ctx->downcount -= 6;
    // 8004CD30: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CD34:
    ctx->pc = 0x8004CD34u;
    // 8004CD34: addi    r3, r3, 4
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4);

label_8004CD38:
    ctx->pc = 0x8004CD38u;
    // 8004CD38: li      r4, 255
    ctx->gpr[4] = (u32)(s32)(255);

label_8004CD3C:
    ctx->pc = 0x8004CD3Cu;
    // 8004CD3C: li      r5, 255
    ctx->gpr[5] = (u32)(s32)(255);

label_8004CD40:
    ctx->pc = 0x8004CD40u;
    // 8004CD40: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_8004CD44:
    ctx->pc = 0x8004CD44u;
    // 8004CD44: bl      0x8025CA34
    {
            ctx->lr = 0x8004CD48u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_8004CD48:
    ctx->pc = 0x8004CD48u;
    ctx->downcount -= 3;
    // 8004CD48: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CD4C:
    ctx->pc = 0x8004CD4Cu;
    // 8004CD4C: addi    r3, r3, 4
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4);

label_8004CD50:
    ctx->pc = 0x8004CD50u;
    // 8004CD50: bl      0x8025C08C
    {
            ctx->lr = 0x8004CD54u;
            ctx->pc = 0x8025C08Cu;
            return;
    }

label_8004CD54:
    ctx->pc = 0x8004CD54u;
    ctx->downcount -= 7;
    // 8004CD54: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CD58:
    ctx->pc = 0x8004CD58u;
    // 8004CD58: addi    r3, r3, 4
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4);

label_8004CD5C:
    ctx->pc = 0x8004CD5Cu;
    // 8004CD5C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004CD60:
    ctx->pc = 0x8004CD60u;
    // 8004CD60: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_8004CD64:
    ctx->pc = 0x8004CD64u;
    // 8004CD64: li      r6, 14
    ctx->gpr[6] = (u32)(s32)(14);

label_8004CD68:
    ctx->pc = 0x8004CD68u;
    // 8004CD68: li      r7, 15
    ctx->gpr[7] = (u32)(s32)(15);

label_8004CD6C:
    ctx->pc = 0x8004CD6Cu;
    // 8004CD6C: bl      0x8025C3B0
    {
            ctx->lr = 0x8004CD70u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_8004CD70:
    ctx->pc = 0x8004CD70u;
    ctx->downcount -= 8;
    // 8004CD70: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CD74:
    ctx->pc = 0x8004CD74u;
    // 8004CD74: addi    r3, r3, 4
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4);

label_8004CD78:
    ctx->pc = 0x8004CD78u;
    // 8004CD78: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004CD7C:
    ctx->pc = 0x8004CD7Cu;
    // 8004CD7C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004CD80:
    ctx->pc = 0x8004CD80u;
    // 8004CD80: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004CD84:
    ctx->pc = 0x8004CD84u;
    // 8004CD84: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004CD88:
    ctx->pc = 0x8004CD88u;
    // 8004CD88: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8004CD8C:
    ctx->pc = 0x8004CD8Cu;
    // 8004CD8C: bl      0x8025C4B4
    {
            ctx->lr = 0x8004CD90u;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_8004CD90:
    ctx->pc = 0x8004CD90u;
    ctx->downcount -= 7;
    // 8004CD90: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CD94:
    ctx->pc = 0x8004CD94u;
    // 8004CD94: addi    r3, r3, 4
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4);

label_8004CD98:
    ctx->pc = 0x8004CD98u;
    // 8004CD98: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_8004CD9C:
    ctx->pc = 0x8004CD9Cu;
    // 8004CD9C: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_8004CDA0:
    ctx->pc = 0x8004CDA0u;
    // 8004CDA0: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_8004CDA4:
    ctx->pc = 0x8004CDA4u;
    // 8004CDA4: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004CDA8:
    ctx->pc = 0x8004CDA8u;
    // 8004CDA8: bl      0x8025C430
    {
            ctx->lr = 0x8004CDACu;
            ctx->pc = 0x8025C430u;
            return;
    }

label_8004CDAC:
    ctx->pc = 0x8004CDACu;
    ctx->downcount -= 8;
    // 8004CDAC: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CDB0:
    ctx->pc = 0x8004CDB0u;
    // 8004CDB0: addi    r3, r3, 4
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4);

label_8004CDB4:
    ctx->pc = 0x8004CDB4u;
    // 8004CDB4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004CDB8:
    ctx->pc = 0x8004CDB8u;
    // 8004CDB8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004CDBC:
    ctx->pc = 0x8004CDBCu;
    // 8004CDBC: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004CDC0:
    ctx->pc = 0x8004CDC0u;
    // 8004CDC0: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004CDC4:
    ctx->pc = 0x8004CDC4u;
    // 8004CDC4: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8004CDC8:
    ctx->pc = 0x8004CDC8u;
    // 8004CDC8: bl      0x8025C574
    {
            ctx->lr = 0x8004CDCCu;
            ctx->pc = 0x8025C574u;
            return;
    }

label_8004CDCC:
    ctx->pc = 0x8004CDCCu;
    ctx->downcount -= 5;
    // 8004CDCC: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CDD0:
    ctx->pc = 0x8004CDD0u;
    // 8004CDD0: addi    r3, r3, 4
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4);

label_8004CDD4:
    ctx->pc = 0x8004CDD4u;
    // 8004CDD4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004CDD8:
    ctx->pc = 0x8004CDD8u;
    // 8004CDD8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004CDDC:
    ctx->pc = 0x8004CDDCu;
    // 8004CDDC: bl      0x8025C868
    {
            ctx->lr = 0x8004CDE0u;
            ctx->pc = 0x8025C868u;
            return;
    }

label_8004CDE0:
    ctx->pc = 0x8004CDE0u;
    ctx->downcount -= 4;
    // 8004CDE0: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CDE4:
    ctx->pc = 0x8004CDE4u;
    // 8004CDE4: addi    r3, r3, 4
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4);

label_8004CDE8:
    ctx->pc = 0x8004CDE8u;
    // 8004CDE8: li      r4, 6
    ctx->gpr[4] = (u32)(s32)(6);

label_8004CDEC:
    ctx->pc = 0x8004CDECu;
    // 8004CDEC: bl      0x8025C790
    {
            ctx->lr = 0x8004CDF0u;
            ctx->pc = 0x8025C790u;
            return;
    }

label_8004CDF0:
    ctx->pc = 0x8004CDF0u;
    ctx->downcount -= 9;
    // 8004CDF0: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8004CDF4:
    ctx->pc = 0x8004CDF4u;
    // 8004CDF4: stb     r0, -25688(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25688);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004CDF8:
    ctx->pc = 0x8004CDF8u;
    // 8004CDF8: lwz     r3, -31304(r2)
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31304);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CDFC:
    ctx->pc = 0x8004CDFCu;
    // 8004CDFC: lwz     r0, -31300(r2)
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31300);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004CE00:
    ctx->pc = 0x8004CE00u;
    // 8004CE00: stw     r3, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8004CE04:
    ctx->pc = 0x8004CE04u;
    // 8004CE04: stw     r0, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004CE08:
    ctx->pc = 0x8004CE08u;
    // 8004CE08: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8004CE0C:
    ctx->pc = 0x8004CE0Cu;
    // 8004CE0C: addi    r4, r1, 20
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(20);

label_8004CE10:
    ctx->pc = 0x8004CE10u;
    // 8004CE10: bl      0x8025C6A8
    {
            ctx->lr = 0x8004CE14u;
            ctx->pc = 0x8025C6A8u;
            return;
    }

label_8004CE14:
    ctx->pc = 0x8004CE14u;
    ctx->downcount -= 5;
    // 8004CE14: lwz     r0, -31296(r2)
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31296);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004CE18:
    ctx->pc = 0x8004CE18u;
    // 8004CE18: stw     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004CE1C:
    ctx->pc = 0x8004CE1Cu;
    // 8004CE1C: lwz     r3, -25620(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25620);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CE20:
    ctx->pc = 0x8004CE20u;
    // 8004CE20: addi    r4, r1, 16
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(16);

label_8004CE24:
    ctx->pc = 0x8004CE24u;
    // 8004CE24: bl      0x8025C71C
    {
            ctx->lr = 0x8004CE28u;
            ctx->pc = 0x8025C71Cu;
            return;
    }

label_8004CE28:
    ctx->pc = 0x8004CE28u;
    ctx->downcount -= 6;
    // 8004CE28: lwz     r0, -31292(r2)
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31292);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004CE2C:
    ctx->pc = 0x8004CE2Cu;
    // 8004CE2C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004CE30:
    ctx->pc = 0x8004CE30u;
    // 8004CE30: lwz     r3, -25620(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25620);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CE34:
    ctx->pc = 0x8004CE34u;
    // 8004CE34: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_8004CE38:
    ctx->pc = 0x8004CE38u;
    // 8004CE38: addi    r4, r1, 12
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(12);

label_8004CE3C:
    ctx->pc = 0x8004CE3Cu;
    // 8004CE3C: bl      0x8025C71C
    {
            ctx->lr = 0x8004CE40u;
            ctx->pc = 0x8025C71Cu;
            return;
    }

label_8004CE40:
    ctx->pc = 0x8004CE40u;
    ctx->downcount -= 6;
    // 8004CE40: lwz     r0, -31288(r2)
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31288);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004CE44:
    ctx->pc = 0x8004CE44u;
    // 8004CE44: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004CE48:
    ctx->pc = 0x8004CE48u;
    // 8004CE48: lwz     r3, -25620(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25620);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CE4C:
    ctx->pc = 0x8004CE4Cu;
    // 8004CE4C: addi    r3, r3, 2
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(2);

label_8004CE50:
    ctx->pc = 0x8004CE50u;
    // 8004CE50: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_8004CE54:
    ctx->pc = 0x8004CE54u;
    // 8004CE54: bl      0x8025C71C
    {
            ctx->lr = 0x8004CE58u;
            ctx->pc = 0x8025C71Cu;
            return;
    }

label_8004CE58:
    ctx->pc = 0x8004CE58u;
    ctx->downcount -= 9;
    // 8004CE58: addi    r3, r1, 92
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(92);

label_8004CE5C:
    ctx->pc = 0x8004CE5Cu;
    // 8004CE5C: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8004CE60:
    ctx->pc = 0x8004CE60u;
    // 8004CE60: rlwinm r5, r30, 0, 16, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[30], 0u) & 0x0000FFFFu;
    }

label_8004CE64:
    ctx->pc = 0x8004CE64u;
    // 8004CE64: rlwinm r6, r31, 0, 16, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[31], 0u) & 0x0000FFFFu;
    }

label_8004CE68:
    ctx->pc = 0x8004CE68u;
    // 8004CE68: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004CE6C:
    ctx->pc = 0x8004CE6Cu;
    // 8004CE6C: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8004CE70:
    ctx->pc = 0x8004CE70u;
    // 8004CE70: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_8004CE74:
    ctx->pc = 0x8004CE74u;
    // 8004CE74: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_8004CE78:
    ctx->pc = 0x8004CE78u;
    // 8004CE78: bl      0x8025AC80
    {
            ctx->lr = 0x8004CE7Cu;
            ctx->pc = 0x8025AC80u;
            return;
    }

label_8004CE7C:
    ctx->pc = 0x8004CE7Cu;
    ctx->downcount -= 10;
    // 8004CE7C: addi    r3, r1, 92
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(92);

label_8004CE80:
    ctx->pc = 0x8004CE80u;
    // 8004CE80: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004CE84:
    ctx->pc = 0x8004CE84u;
    // 8004CE84: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004CE88:
    ctx->pc = 0x8004CE88u;
    // 8004CE88: lfs     f1, -31276(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004CE88u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31276);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8004CE8C:
    ctx->pc = 0x8004CE8Cu;
    // 8004CE8C: fmr    f2, f1
    if (!ppc_fp_available_inline(ctx, 0x8004CE8Cu)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_8004CE90:
    ctx->pc = 0x8004CE90u;
    // 8004CE90: fmr    f3, f1
    if (!ppc_fp_available_inline(ctx, 0x8004CE90u)) return;
    ctx->fpr[3] = ctx->fpr[1];

label_8004CE94:
    ctx->pc = 0x8004CE94u;
    // 8004CE94: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004CE98:
    ctx->pc = 0x8004CE98u;
    // 8004CE98: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004CE9C:
    ctx->pc = 0x8004CE9Cu;
    // 8004CE9C: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8004CEA0:
    ctx->pc = 0x8004CEA0u;
    // 8004CEA0: bl      0x8025AEF4
    {
            ctx->lr = 0x8004CEA4u;
            ctx->pc = 0x8025AEF4u;
            return;
    }

label_8004CEA4:
    ctx->pc = 0x8004CEA4u;
    ctx->downcount -= 3;
    // 8004CEA4: addi    r3, r1, 92
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(92);

label_8004CEA8:
    ctx->pc = 0x8004CEA8u;
    // 8004CEA8: lwz     r4, -25596(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25596);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004CEAC:
    ctx->pc = 0x8004CEACu;
    // 8004CEAC: bl      0x8025B260
    {
            ctx->lr = 0x8004CEB0u;
            ctx->pc = 0x8025B260u;
            return;
    }

label_8004CEB0:
    ctx->pc = 0x8004CEB0u;
    ctx->downcount -= 13;
    // 8004CEB0: addi    r3, r1, 60
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(60);

label_8004CEB4:
    ctx->pc = 0x8004CEB4u;
    // 8004CEB4: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8004CEB8:
    ctx->pc = 0x8004CEB8u;
    // 8004CEB8: extsh r0, r30
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[30];
    }

label_8004CEBC:
    ctx->pc = 0x8004CEBCu;
    // 8004CEBC: srawi r28, r0, 1
    {
        u32 sh = 1u;
        u32 value = ctx->gpr[0];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[28] = value;
        } else if (sh > 31) {
            ctx->gpr[28] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[28] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_8004CEC0:
    ctx->pc = 0x8004CEC0u;
    // 8004CEC0: rlwinm r5, r28, 0, 16, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[28], 0u) & 0x0000FFFFu;
    }

label_8004CEC4:
    ctx->pc = 0x8004CEC4u;
    // 8004CEC4: extsh r0, r31
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[31];
    }

label_8004CEC8:
    ctx->pc = 0x8004CEC8u;
    // 8004CEC8: srawi r27, r0, 1
    {
        u32 sh = 1u;
        u32 value = ctx->gpr[0];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[27] = value;
        } else if (sh > 31) {
            ctx->gpr[27] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[27] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_8004CECC:
    ctx->pc = 0x8004CECCu;
    // 8004CECC: rlwinm r6, r27, 0, 16, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[27], 0u) & 0x0000FFFFu;
    }

label_8004CED0:
    ctx->pc = 0x8004CED0u;
    // 8004CED0: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004CED4:
    ctx->pc = 0x8004CED4u;
    // 8004CED4: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8004CED8:
    ctx->pc = 0x8004CED8u;
    // 8004CED8: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_8004CEDC:
    ctx->pc = 0x8004CEDCu;
    // 8004CEDC: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_8004CEE0:
    ctx->pc = 0x8004CEE0u;
    // 8004CEE0: bl      0x8025AC80
    {
            ctx->lr = 0x8004CEE4u;
            ctx->pc = 0x8025AC80u;
            return;
    }

label_8004CEE4:
    ctx->pc = 0x8004CEE4u;
    ctx->downcount -= 10;
    // 8004CEE4: addi    r3, r1, 60
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(60);

label_8004CEE8:
    ctx->pc = 0x8004CEE8u;
    // 8004CEE8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004CEEC:
    ctx->pc = 0x8004CEECu;
    // 8004CEEC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004CEF0:
    ctx->pc = 0x8004CEF0u;
    // 8004CEF0: lfs     f1, -31276(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004CEF0u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31276);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8004CEF4:
    ctx->pc = 0x8004CEF4u;
    // 8004CEF4: fmr    f2, f1
    if (!ppc_fp_available_inline(ctx, 0x8004CEF4u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_8004CEF8:
    ctx->pc = 0x8004CEF8u;
    // 8004CEF8: fmr    f3, f1
    if (!ppc_fp_available_inline(ctx, 0x8004CEF8u)) return;
    ctx->fpr[3] = ctx->fpr[1];

label_8004CEFC:
    ctx->pc = 0x8004CEFCu;
    // 8004CEFC: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004CF00:
    ctx->pc = 0x8004CF00u;
    // 8004CF00: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004CF04:
    ctx->pc = 0x8004CF04u;
    // 8004CF04: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8004CF08:
    ctx->pc = 0x8004CF08u;
    // 8004CF08: bl      0x8025AEF4
    {
            ctx->lr = 0x8004CF0Cu;
            ctx->pc = 0x8025AEF4u;
            return;
    }

label_8004CF0C:
    ctx->pc = 0x8004CF0Cu;
    ctx->downcount -= 4;
    // 8004CF0C: addi    r3, r1, 60
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(60);

label_8004CF10:
    ctx->pc = 0x8004CF10u;
    // 8004CF10: lwz     r4, -25596(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25596);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004CF14:
    ctx->pc = 0x8004CF14u;
    // 8004CF14: addi    r4, r4, 1
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(1);

label_8004CF18:
    ctx->pc = 0x8004CF18u;
    // 8004CF18: bl      0x8025B260
    {
            ctx->lr = 0x8004CF1Cu;
            ctx->pc = 0x8025B260u;
            return;
    }

label_8004CF1C:
    ctx->pc = 0x8004CF1Cu;
    ctx->downcount -= 9;
    // 8004CF1C: addi    r3, r1, 28
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(28);

label_8004CF20:
    ctx->pc = 0x8004CF20u;
    // 8004CF20: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8004CF24:
    ctx->pc = 0x8004CF24u;
    // 8004CF24: rlwinm r5, r28, 0, 16, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[28], 0u) & 0x0000FFFFu;
    }

label_8004CF28:
    ctx->pc = 0x8004CF28u;
    // 8004CF28: rlwinm r6, r27, 0, 16, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[27], 0u) & 0x0000FFFFu;
    }

label_8004CF2C:
    ctx->pc = 0x8004CF2Cu;
    // 8004CF2C: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004CF30:
    ctx->pc = 0x8004CF30u;
    // 8004CF30: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8004CF34:
    ctx->pc = 0x8004CF34u;
    // 8004CF34: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_8004CF38:
    ctx->pc = 0x8004CF38u;
    // 8004CF38: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_8004CF3C:
    ctx->pc = 0x8004CF3Cu;
    // 8004CF3C: bl      0x8025AC80
    {
            ctx->lr = 0x8004CF40u;
            ctx->pc = 0x8025AC80u;
            return;
    }

label_8004CF40:
    ctx->pc = 0x8004CF40u;
    ctx->downcount -= 10;
    // 8004CF40: addi    r3, r1, 28
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(28);

label_8004CF44:
    ctx->pc = 0x8004CF44u;
    // 8004CF44: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004CF48:
    ctx->pc = 0x8004CF48u;
    // 8004CF48: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004CF4C:
    ctx->pc = 0x8004CF4Cu;
    // 8004CF4C: lfs     f1, -31276(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004CF4Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31276);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8004CF50:
    ctx->pc = 0x8004CF50u;
    // 8004CF50: fmr    f2, f1
    if (!ppc_fp_available_inline(ctx, 0x8004CF50u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_8004CF54:
    ctx->pc = 0x8004CF54u;
    // 8004CF54: fmr    f3, f1
    if (!ppc_fp_available_inline(ctx, 0x8004CF54u)) return;
    ctx->fpr[3] = ctx->fpr[1];

label_8004CF58:
    ctx->pc = 0x8004CF58u;
    // 8004CF58: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004CF5C:
    ctx->pc = 0x8004CF5Cu;
    // 8004CF5C: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004CF60:
    ctx->pc = 0x8004CF60u;
    // 8004CF60: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8004CF64:
    ctx->pc = 0x8004CF64u;
    // 8004CF64: bl      0x8025AEF4
    {
            ctx->lr = 0x8004CF68u;
            ctx->pc = 0x8025AEF4u;
            return;
    }

label_8004CF68:
    ctx->pc = 0x8004CF68u;
    ctx->downcount -= 4;
    // 8004CF68: addi    r3, r1, 28
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(28);

label_8004CF6C:
    ctx->pc = 0x8004CF6Cu;
    // 8004CF6C: lwz     r4, -25596(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25596);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004CF70:
    ctx->pc = 0x8004CF70u;
    // 8004CF70: addi    r4, r4, 2
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(2);

label_8004CF74:
    ctx->pc = 0x8004CF74u;
    // 8004CF74: bl      0x8025B260
    {
            ctx->lr = 0x8004CF78u;
            ctx->pc = 0x8025B260u;
            return;
    }

label_8004CF78:
    ctx->pc = 0x8004CF78u;
    ctx->downcount -= 24;
    // 8004CF78: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CF7C:
    ctx->pc = 0x8004CF7Cu;
    // 8004CF7C: addi    r0, r3, 5
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(5);

label_8004CF80:
    ctx->pc = 0x8004CF80u;
    // 8004CF80: stw     r0, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004CF84:
    ctx->pc = 0x8004CF84u;
    // 8004CF84: lwz     r3, -25600(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25600);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CF88:
    ctx->pc = 0x8004CF88u;
    // 8004CF88: addi    r0, r3, 2
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(2);

label_8004CF8C:
    ctx->pc = 0x8004CF8Cu;
    // 8004CF8C: stw     r0, -25600(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25600);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004CF90:
    ctx->pc = 0x8004CF90u;
    // 8004CF90: lwz     r3, -25596(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25596);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CF94:
    ctx->pc = 0x8004CF94u;
    // 8004CF94: addi    r0, r3, 3
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(3);

label_8004CF98:
    ctx->pc = 0x8004CF98u;
    // 8004CF98: stw     r0, -25596(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25596);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004CF9C:
    ctx->pc = 0x8004CF9Cu;
    // 8004CF9C: lwz     r3, -25620(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25620);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CFA0:
    ctx->pc = 0x8004CFA0u;
    // 8004CFA0: addi    r0, r3, 3
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(3);

label_8004CFA4:
    ctx->pc = 0x8004CFA4u;
    // 8004CFA4: stw     r0, -25620(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25620);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004CFA8:
    ctx->pc = 0x8004CFA8u;
    // 8004CFA8: lwz     r3, -25624(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25624);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CFAC:
    ctx->pc = 0x8004CFACu;
    // 8004CFAC: addi    r0, r3, 3
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(3);

label_8004CFB0:
    ctx->pc = 0x8004CFB0u;
    // 8004CFB0: stw     r0, -25624(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25624);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004CFB4:
    ctx->pc = 0x8004CFB4u;
    // 8004CFB4: lwz     r3, -25628(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25628);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004CFB8:
    ctx->pc = 0x8004CFB8u;
    // 8004CFB8: addi    r0, r3, 3
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(3);

label_8004CFBC:
    ctx->pc = 0x8004CFBCu;
    // 8004CFBC: stw     r0, -25628(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25628);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004CFC0:
    ctx->pc = 0x8004CFC0u;
    // 8004CFC0: lbz     r3, -25630(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25630);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8004CFC4:
    ctx->pc = 0x8004CFC4u;
    // 8004CFC4: addi    r0, r3, 5
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(5);

label_8004CFC8:
    ctx->pc = 0x8004CFC8u;
    // 8004CFC8: stb     r0, -25630(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25630);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004CFCC:
    ctx->pc = 0x8004CFCCu;
    // 8004CFCC: lbz     r3, -25631(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25631);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8004CFD0:
    ctx->pc = 0x8004CFD0u;
    // 8004CFD0: addi    r0, r3, 2
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(2);

label_8004CFD4:
    ctx->pc = 0x8004CFD4u;
    // 8004CFD4: stb     r0, -25631(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25631);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004CFD8:
    ctx->pc = 0x8004CFD8u;
    ctx->downcount -= 2;
    // 8004CFD8: addi    r11, r1, 160
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(160);

label_8004CFDC:
    ctx->pc = 0x8004CFDCu;
    // 8004CFDC: bl      0x80286A98
    {
            ctx->lr = 0x8004CFE0u;
            ctx->pc = 0x80286A98u;
            return;
    }

label_8004CFE0:
    ctx->pc = 0x8004CFE0u;
    ctx->downcount -= 5;
    // 8004CFE0: lwz     r0, 164(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(164);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004CFE4:
    ctx->pc = 0x8004CFE4u;
    // 8004CFE4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004CFE8:
    ctx->pc = 0x8004CFE8u;
    // 8004CFE8: addi    r1, r1, 160
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(160);

label_8004CFEC:
    ctx->pc = 0x8004CFECu;
    // 8004CFEC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004CFF0:
    ctx->pc = 0x8004CFF0u;
    ctx->downcount -= 12;
    // 8004CFF0: stwu     r1, -144(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-144);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004CFF4:
    ctx->pc = 0x8004CFF4u;
    // 8004CFF4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004CFF8:
    ctx->pc = 0x8004CFF8u;
    // 8004CFF8: stw     r0, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004CFFC:
    ctx->pc = 0x8004CFFCu;
    // 8004CFFC: stw     r31, 140(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(140);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8004D000:
    ctx->pc = 0x8004D000u;
    // 8004D000: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004D004:
    ctx->pc = 0x8004D004u;
    // 8004D004: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8004D008:
    ctx->pc = 0x8004D008u;
    // 8004D008: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8004D00C:
    ctx->pc = 0x8004D00Cu;
    // 8004D00C: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_8004D010:
    ctx->pc = 0x8004D010u;
    // 8004D010: li      r6, 60
    ctx->gpr[6] = (u32)(s32)(60);

label_8004D014:
    ctx->pc = 0x8004D014u;
    // 8004D014: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004D018:
    ctx->pc = 0x8004D018u;
    // 8004D018: li      r8, 125
    ctx->gpr[8] = (u32)(s32)(125);

label_8004D01C:
    ctx->pc = 0x8004D01Cu;
    // 8004D01C: bl      0x80258880
    {
            ctx->lr = 0x8004D020u;
            ctx->pc = 0x80258880u;
            return;
    }

label_8004D020:
    ctx->pc = 0x8004D020u;
    ctx->downcount -= 2;
    // 8004D020: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8004D024:
    ctx->pc = 0x8004D024u;
    // 8004D024: bl      0x8025C08C
    {
            ctx->lr = 0x8004D028u;
            ctx->pc = 0x8025C08Cu;
            return;
    }

label_8004D028:
    ctx->pc = 0x8004D028u;
    ctx->downcount -= 5;
    // 8004D028: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8004D02C:
    ctx->pc = 0x8004D02Cu;
    // 8004D02C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004D030:
    ctx->pc = 0x8004D030u;
    // 8004D030: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004D034:
    ctx->pc = 0x8004D034u;
    // 8004D034: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_8004D038:
    ctx->pc = 0x8004D038u;
    // 8004D038: bl      0x8025CA34
    {
            ctx->lr = 0x8004D03Cu;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_8004D03C:
    ctx->pc = 0x8004D03Cu;
    ctx->downcount -= 6;
    // 8004D03C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8004D040:
    ctx->pc = 0x8004D040u;
    // 8004D040: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_8004D044:
    ctx->pc = 0x8004D044u;
    // 8004D044: li      r5, 8
    ctx->gpr[5] = (u32)(s32)(8);

label_8004D048:
    ctx->pc = 0x8004D048u;
    // 8004D048: li      r6, 10
    ctx->gpr[6] = (u32)(s32)(10);

label_8004D04C:
    ctx->pc = 0x8004D04Cu;
    // 8004D04C: li      r7, 15
    ctx->gpr[7] = (u32)(s32)(15);

label_8004D050:
    ctx->pc = 0x8004D050u;
    // 8004D050: bl      0x8025C3B0
    {
            ctx->lr = 0x8004D054u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_8004D054:
    ctx->pc = 0x8004D054u;
    ctx->downcount -= 6;
    // 8004D054: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8004D058:
    ctx->pc = 0x8004D058u;
    // 8004D058: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_8004D05C:
    ctx->pc = 0x8004D05Cu;
    // 8004D05C: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_8004D060:
    ctx->pc = 0x8004D060u;
    // 8004D060: li      r6, 5
    ctx->gpr[6] = (u32)(s32)(5);

label_8004D064:
    ctx->pc = 0x8004D064u;
    // 8004D064: li      r7, 7
    ctx->gpr[7] = (u32)(s32)(7);

label_8004D068:
    ctx->pc = 0x8004D068u;
    // 8004D068: bl      0x8025C430
    {
            ctx->lr = 0x8004D06Cu;
            ctx->pc = 0x8025C430u;
            return;
    }

label_8004D06C:
    ctx->pc = 0x8004D06Cu;
    ctx->downcount -= 4;
    // 8004D06C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8004D070:
    ctx->pc = 0x8004D070u;
    // 8004D070: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004D074:
    ctx->pc = 0x8004D074u;
    // 8004D074: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004D078:
    ctx->pc = 0x8004D078u;
    // 8004D078: bl      0x8025C868
    {
            ctx->lr = 0x8004D07Cu;
            ctx->pc = 0x8025C868u;
            return;
    }

label_8004D07C:
    ctx->pc = 0x8004D07Cu;
    ctx->downcount -= 7;
    // 8004D07C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8004D080:
    ctx->pc = 0x8004D080u;
    // 8004D080: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004D084:
    ctx->pc = 0x8004D084u;
    // 8004D084: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004D088:
    ctx->pc = 0x8004D088u;
    // 8004D088: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004D08C:
    ctx->pc = 0x8004D08Cu;
    // 8004D08C: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004D090:
    ctx->pc = 0x8004D090u;
    // 8004D090: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8004D094:
    ctx->pc = 0x8004D094u;
    // 8004D094: bl      0x8025C4B4
    {
            ctx->lr = 0x8004D098u;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_8004D098:
    ctx->pc = 0x8004D098u;
    ctx->downcount -= 7;
    // 8004D098: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8004D09C:
    ctx->pc = 0x8004D09Cu;
    // 8004D09C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004D0A0:
    ctx->pc = 0x8004D0A0u;
    // 8004D0A0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004D0A4:
    ctx->pc = 0x8004D0A4u;
    // 8004D0A4: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004D0A8:
    ctx->pc = 0x8004D0A8u;
    // 8004D0A8: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004D0AC:
    ctx->pc = 0x8004D0ACu;
    // 8004D0AC: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8004D0B0:
    ctx->pc = 0x8004D0B0u;
    // 8004D0B0: bl      0x8025C574
    {
            ctx->lr = 0x8004D0B4u;
            ctx->pc = 0x8025C574u;
            return;
    }

label_8004D0B4:
    ctx->pc = 0x8004D0B4u;
    ctx->downcount -= 16;
    // 8004D0B4: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8004D0B8:
    ctx->pc = 0x8004D0B8u;
    // 8004D0B8: stb     r0, -25688(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25688);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004D0BC:
    ctx->pc = 0x8004D0BCu;
    // 8004D0BC: lfs     f1, -31252(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004D0BCu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31252);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8004D0C0:
    ctx->pc = 0x8004D0C0u;
    // 8004D0C0: stfs     f1, 80(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004D0C0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8004D0C4:
    ctx->pc = 0x8004D0C4u;
    // 8004D0C4: lfs     f0, -31276(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004D0C4u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31276);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004D0C8:
    ctx->pc = 0x8004D0C8u;
    // 8004D0C8: stfs     f0, 84(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004D0C8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004D0CC:
    ctx->pc = 0x8004D0CCu;
    // 8004D0CC: stfs     f0, 88(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004D0CCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004D0D0:
    ctx->pc = 0x8004D0D0u;
    // 8004D0D0: stfs     f0, 92(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004D0D0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004D0D4:
    ctx->pc = 0x8004D0D4u;
    // 8004D0D4: stfs     f0, 96(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004D0D4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004D0D8:
    ctx->pc = 0x8004D0D8u;
    // 8004D0D8: stfs     f0, 100(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004D0D8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(100);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004D0DC:
    ctx->pc = 0x8004D0DCu;
    // 8004D0DC: stfs     f1, 104(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004D0DCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8004D0E0:
    ctx->pc = 0x8004D0E0u;
    // 8004D0E0: stfs     f0, 108(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004D0E0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(108);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004D0E4:
    ctx->pc = 0x8004D0E4u;
    // 8004D0E4: addi    r3, r1, 80
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(80);

label_8004D0E8:
    ctx->pc = 0x8004D0E8u;
    // 8004D0E8: li      r4, 30
    ctx->gpr[4] = (u32)(s32)(30);

label_8004D0EC:
    ctx->pc = 0x8004D0ECu;
    // 8004D0EC: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_8004D0F0:
    ctx->pc = 0x8004D0F0u;
    // 8004D0F0: bl      0x8025DAD0
    {
            ctx->lr = 0x8004D0F4u;
            ctx->pc = 0x8025DAD0u;
            return;
    }

label_8004D0F4:
    ctx->pc = 0x8004D0F4u;
    ctx->downcount -= 7;
    // 8004D0F4: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8004D0F8:
    ctx->pc = 0x8004D0F8u;
    // 8004D0F8: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8004D0FC:
    ctx->pc = 0x8004D0FCu;
    // 8004D0FC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004D100:
    ctx->pc = 0x8004D100u;
    // 8004D100: li      r6, 30
    ctx->gpr[6] = (u32)(s32)(30);

label_8004D104:
    ctx->pc = 0x8004D104u;
    // 8004D104: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004D108:
    ctx->pc = 0x8004D108u;
    // 8004D108: li      r8, 125
    ctx->gpr[8] = (u32)(s32)(125);

label_8004D10C:
    ctx->pc = 0x8004D10Cu;
    // 8004D10C: bl      0x80258880
    {
            ctx->lr = 0x8004D110u;
            ctx->pc = 0x80258880u;
            return;
    }

label_8004D110:
    ctx->pc = 0x8004D110u;
    ctx->downcount -= 2;
    // 8004D110: addi    r3, r1, 20
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(20);

label_8004D114:
    ctx->pc = 0x8004D114u;
    // 8004D114: bl      0x8006C7C8
    {
            ctx->lr = 0x8004D118u;
            ctx->pc = 0x8006C7C8u;
            return;
    }

label_8004D118:
    ctx->pc = 0x8004D118u;
    ctx->downcount -= 3;
    // 8004D118: lwz     r4, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004D11C:
    ctx->pc = 0x8004D11Cu;
    // 8004D11C: cmplwi  r4, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004D120:
    ctx->pc = 0x8004D120u;
    // 8004D120: bc    12, 2, 0x8004D14C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004D14C;
        }
    }

label_8004D124:
    ctx->pc = 0x8004D124u;
    ctx->downcount -= 4;
    // 8004D124: addi    r3, r4, 32
    ctx->gpr[3] = ctx->gpr[4] + (u32)(s32)(32);

label_8004D128:
    ctx->pc = 0x8004D128u;
    // 8004D128: lbz     r0, 72(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(72);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8004D12C:
    ctx->pc = 0x8004D12Cu;
    // 8004D12C: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004D130:
    ctx->pc = 0x8004D130u;
    // 8004D130: bc    12, 2, 0x8004D144
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004D144;
        }
    }

label_8004D134:
    ctx->pc = 0x8004D134u;
    ctx->downcount -= 3;
    // 8004D134: lwz     r4, 64(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(64);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004D138:
    ctx->pc = 0x8004D138u;
    // 8004D138: li      r5, 2
    ctx->gpr[5] = (u32)(s32)(2);

label_8004D13C:
    ctx->pc = 0x8004D13Cu;
    // 8004D13C: bl      0x8025B0B8
    {
            ctx->lr = 0x8004D140u;
            ctx->pc = 0x8025B0B8u;
            return;
    }

label_8004D140:
    ctx->pc = 0x8004D140u;
    ctx->downcount -= 1;
    // 8004D140: b       0x8004D14C
    {
            goto label_8004D14C;
    }

label_8004D144:
    ctx->pc = 0x8004D144u;
    ctx->downcount -= 2;
    // 8004D144: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_8004D148:
    ctx->pc = 0x8004D148u;
    // 8004D148: bl      0x8025B260
    {
            ctx->lr = 0x8004D14Cu;
            ctx->pc = 0x8025B260u;
            return;
    }

label_8004D14C:
    ctx->pc = 0x8004D14Cu;
    ctx->downcount -= 3;
    // 8004D14C: addi    r3, r1, 28
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(28);

label_8004D150:
    ctx->pc = 0x8004D150u;
    // 8004D150: addi    r4, r1, 24
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(24);

label_8004D154:
    ctx->pc = 0x8004D154u;
    // 8004D154: bl      0x8006CCA0
    {
            ctx->lr = 0x8004D158u;
            ctx->pc = 0x8006CCA0u;
            return;
    }

label_8004D158:
    ctx->pc = 0x8004D158u;
    ctx->downcount -= 8;
    // 8004D158: addi    r3, r1, 32
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(32);

label_8004D15C:
    ctx->pc = 0x8004D15Cu;
    // 8004D15C: lfs     f2, -31256(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004D15Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31256);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8004D160:
    ctx->pc = 0x8004D160u;
    // 8004D160: lfs     f0, 28(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004D160u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004D164:
    ctx->pc = 0x8004D164u;
    // 8004D164: fmuls   f1, f2, f0
    if (!ppc_fp_available_inline(ctx, 0x8004D164u)) return;
    ppc_fmuls(ctx, 1, 2, 0);

label_8004D168:
    ctx->pc = 0x8004D168u;
    // 8004D168: lfs     f0, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004D168u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004D16C:
    ctx->pc = 0x8004D16Cu;
    // 8004D16C: fmuls   f2, f2, f0
    if (!ppc_fp_available_inline(ctx, 0x8004D16Cu)) return;
    ppc_fmuls(ctx, 2, 2, 0);

label_8004D170:
    ctx->pc = 0x8004D170u;
    // 8004D170: lfs     f3, -31276(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004D170u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31276);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8004D174:
    ctx->pc = 0x8004D174u;
    // 8004D174: bl      0x80247C90
    {
            ctx->lr = 0x8004D178u;
            ctx->pc = 0x80247C90u;
            return;
    }

label_8004D178:
    ctx->pc = 0x8004D178u;
    ctx->downcount -= 7;
    // 8004D178: lfs     f0, -31248(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004D178u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31248);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004D17C:
    ctx->pc = 0x8004D17Cu;
    // 8004D17C: stfs     f0, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004D17Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004D180:
    ctx->pc = 0x8004D180u;
    // 8004D180: stfs     f0, 52(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004D180u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004D184:
    ctx->pc = 0x8004D184u;
    // 8004D184: addi    r3, r1, 32
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(32);

label_8004D188:
    ctx->pc = 0x8004D188u;
    // 8004D188: li      r4, 33
    ctx->gpr[4] = (u32)(s32)(33);

label_8004D18C:
    ctx->pc = 0x8004D18Cu;
    // 8004D18C: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_8004D190:
    ctx->pc = 0x8004D190u;
    // 8004D190: bl      0x8025DAD0
    {
            ctx->lr = 0x8004D194u;
            ctx->pc = 0x8025DAD0u;
            return;
    }

label_8004D194:
    ctx->pc = 0x8004D194u;
    ctx->downcount -= 7;
    // 8004D194: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8004D198:
    ctx->pc = 0x8004D198u;
    // 8004D198: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8004D19C:
    ctx->pc = 0x8004D19Cu;
    // 8004D19C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004D1A0:
    ctx->pc = 0x8004D1A0u;
    // 8004D1A0: li      r6, 33
    ctx->gpr[6] = (u32)(s32)(33);

label_8004D1A4:
    ctx->pc = 0x8004D1A4u;
    // 8004D1A4: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004D1A8:
    ctx->pc = 0x8004D1A8u;
    // 8004D1A8: li      r8, 125
    ctx->gpr[8] = (u32)(s32)(125);

label_8004D1AC:
    ctx->pc = 0x8004D1ACu;
    // 8004D1AC: bl      0x80258880
    {
            ctx->lr = 0x8004D1B0u;
            ctx->pc = 0x80258880u;
            return;
    }

label_8004D1B0:
    ctx->pc = 0x8004D1B0u;
    ctx->downcount -= 4;
    // 8004D1B0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8004D1B4:
    ctx->pc = 0x8004D1B4u;
    // 8004D1B4: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_8004D1B8:
    ctx->pc = 0x8004D1B8u;
    // 8004D1B8: li      r5, 2
    ctx->gpr[5] = (u32)(s32)(2);

label_8004D1BC:
    ctx->pc = 0x8004D1BCu;
    // 8004D1BC: bl      0x8025BF28
    {
            ctx->lr = 0x8004D1C0u;
            ctx->pc = 0x8025BF28u;
            return;
    }

label_8004D1C0:
    ctx->pc = 0x8004D1C0u;
    ctx->downcount -= 4;
    // 8004D1C0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8004D1C4:
    ctx->pc = 0x8004D1C4u;
    // 8004D1C4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004D1C8:
    ctx->pc = 0x8004D1C8u;
    // 8004D1C8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004D1CC:
    ctx->pc = 0x8004D1CCu;
    // 8004D1CC: bl      0x8025BD54
    {
            ctx->lr = 0x8004D1D0u;
            ctx->pc = 0x8025BD54u;
            return;
    }

label_8004D1D0:
    ctx->pc = 0x8004D1D0u;
    ctx->downcount -= 12;
    // 8004D1D0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8004D1D4:
    ctx->pc = 0x8004D1D4u;
    // 8004D1D4: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004D1D8:
    ctx->pc = 0x8004D1D8u;
    // 8004D1D8: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004D1DC:
    ctx->pc = 0x8004D1DCu;
    // 8004D1DC: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8004D1E0:
    ctx->pc = 0x8004D1E0u;
    // 8004D1E0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004D1E4:
    ctx->pc = 0x8004D1E4u;
    // 8004D1E4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004D1E8:
    ctx->pc = 0x8004D1E8u;
    // 8004D1E8: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_8004D1EC:
    ctx->pc = 0x8004D1ECu;
    // 8004D1EC: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004D1F0:
    ctx->pc = 0x8004D1F0u;
    // 8004D1F0: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8004D1F4:
    ctx->pc = 0x8004D1F4u;
    // 8004D1F4: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_8004D1F8:
    ctx->pc = 0x8004D1F8u;
    // 8004D1F8: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_8004D1FC:
    ctx->pc = 0x8004D1FCu;
    // 8004D1FC: bl      0x8025BB58
    {
            ctx->lr = 0x8004D200u;
            ctx->pc = 0x8025BB58u;
            return;
    }

label_8004D200:
    ctx->pc = 0x8004D200u;
    ctx->downcount -= 3;
    // 8004D200: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8004D204:
    ctx->pc = 0x8004D204u;
    // 8004D204: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_8004D208:
    ctx->pc = 0x8004D208u;
    // 8004D208: bl      0x8025C790
    {
            ctx->lr = 0x8004D20Cu;
            ctx->pc = 0x8025C790u;
            return;
    }

label_8004D20C:
    ctx->pc = 0x8004D20Cu;
    ctx->downcount -= 5;
    // 8004D20C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8004D210:
    ctx->pc = 0x8004D210u;
    // 8004D210: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8004D214:
    ctx->pc = 0x8004D214u;
    // 8004D214: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_8004D218:
    ctx->pc = 0x8004D218u;
    // 8004D218: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_8004D21C:
    ctx->pc = 0x8004D21Cu;
    // 8004D21C: bl      0x8025CA34
    {
            ctx->lr = 0x8004D220u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_8004D220:
    ctx->pc = 0x8004D220u;
    ctx->downcount -= 6;
    // 8004D220: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8004D224:
    ctx->pc = 0x8004D224u;
    // 8004D224: li      r4, 8
    ctx->gpr[4] = (u32)(s32)(8);

label_8004D228:
    ctx->pc = 0x8004D228u;
    // 8004D228: li      r5, 14
    ctx->gpr[5] = (u32)(s32)(14);

label_8004D22C:
    ctx->pc = 0x8004D22Cu;
    // 8004D22C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004D230:
    ctx->pc = 0x8004D230u;
    // 8004D230: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004D234:
    ctx->pc = 0x8004D234u;
    // 8004D234: bl      0x8025C3B0
    {
            ctx->lr = 0x8004D238u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_8004D238:
    ctx->pc = 0x8004D238u;
    ctx->downcount -= 6;
    // 8004D238: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8004D23C:
    ctx->pc = 0x8004D23Cu;
    // 8004D23C: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_8004D240:
    ctx->pc = 0x8004D240u;
    // 8004D240: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_8004D244:
    ctx->pc = 0x8004D244u;
    // 8004D244: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004D248:
    ctx->pc = 0x8004D248u;
    // 8004D248: li      r7, 7
    ctx->gpr[7] = (u32)(s32)(7);

label_8004D24C:
    ctx->pc = 0x8004D24Cu;
    // 8004D24C: bl      0x8025C430
    {
            ctx->lr = 0x8004D250u;
            ctx->pc = 0x8025C430u;
            return;
    }

label_8004D250:
    ctx->pc = 0x8004D250u;
    ctx->downcount -= 4;
    // 8004D250: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8004D254:
    ctx->pc = 0x8004D254u;
    // 8004D254: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004D258:
    ctx->pc = 0x8004D258u;
    // 8004D258: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004D25C:
    ctx->pc = 0x8004D25Cu;
    // 8004D25C: bl      0x8025C868
    {
            ctx->lr = 0x8004D260u;
            ctx->pc = 0x8025C868u;
            return;
    }

label_8004D260:
    ctx->pc = 0x8004D260u;
    ctx->downcount -= 7;
    // 8004D260: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8004D264:
    ctx->pc = 0x8004D264u;
    // 8004D264: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8004D268:
    ctx->pc = 0x8004D268u;
    // 8004D268: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_8004D26C:
    ctx->pc = 0x8004D26Cu;
    // 8004D26C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004D270:
    ctx->pc = 0x8004D270u;
    // 8004D270: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004D274:
    ctx->pc = 0x8004D274u;
    // 8004D274: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8004D278:
    ctx->pc = 0x8004D278u;
    // 8004D278: bl      0x8025C4B4
    {
            ctx->lr = 0x8004D27Cu;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_8004D27C:
    ctx->pc = 0x8004D27Cu;
    ctx->downcount -= 7;
    // 8004D27C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8004D280:
    ctx->pc = 0x8004D280u;
    // 8004D280: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004D284:
    ctx->pc = 0x8004D284u;
    // 8004D284: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004D288:
    ctx->pc = 0x8004D288u;
    // 8004D288: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004D28C:
    ctx->pc = 0x8004D28Cu;
    // 8004D28C: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004D290:
    ctx->pc = 0x8004D290u;
    // 8004D290: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8004D294:
    ctx->pc = 0x8004D294u;
    // 8004D294: bl      0x8025C574
    {
            ctx->lr = 0x8004D298u;
            ctx->pc = 0x8025C574u;
            return;
    }

label_8004D298:
    ctx->pc = 0x8004D298u;
    ctx->downcount -= 2;
    // 8004D298: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_8004D29C:
    ctx->pc = 0x8004D29Cu;
    // 8004D29C: bl      0x8006C79C
    {
            ctx->lr = 0x8004D2A0u;
            ctx->pc = 0x8006C79Cu;
            return;
    }

label_8004D2A0:
    ctx->pc = 0x8004D2A0u;
    ctx->downcount -= 3;
    // 8004D2A0: lwz     r4, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004D2A4:
    ctx->pc = 0x8004D2A4u;
    // 8004D2A4: cmplwi  r4, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004D2A8:
    ctx->pc = 0x8004D2A8u;
    // 8004D2A8: bc    12, 2, 0x8004D2D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004D2D4;
        }
    }

label_8004D2AC:
    ctx->pc = 0x8004D2ACu;
    ctx->downcount -= 4;
    // 8004D2AC: addi    r3, r4, 32
    ctx->gpr[3] = ctx->gpr[4] + (u32)(s32)(32);

label_8004D2B0:
    ctx->pc = 0x8004D2B0u;
    // 8004D2B0: lbz     r0, 72(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(72);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8004D2B4:
    ctx->pc = 0x8004D2B4u;
    // 8004D2B4: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004D2B8:
    ctx->pc = 0x8004D2B8u;
    // 8004D2B8: bc    12, 2, 0x8004D2CC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004D2CC;
        }
    }

label_8004D2BC:
    ctx->pc = 0x8004D2BCu;
    ctx->downcount -= 3;
    // 8004D2BC: lwz     r4, 64(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(64);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004D2C0:
    ctx->pc = 0x8004D2C0u;
    // 8004D2C0: li      r5, 3
    ctx->gpr[5] = (u32)(s32)(3);

label_8004D2C4:
    ctx->pc = 0x8004D2C4u;
    // 8004D2C4: bl      0x8025B0B8
    {
            ctx->lr = 0x8004D2C8u;
            ctx->pc = 0x8025B0B8u;
            return;
    }

label_8004D2C8:
    ctx->pc = 0x8004D2C8u;
    ctx->downcount -= 1;
    // 8004D2C8: b       0x8004D2D4
    {
            goto label_8004D2D4;
    }

label_8004D2CC:
    ctx->pc = 0x8004D2CCu;
    ctx->downcount -= 2;
    // 8004D2CC: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_8004D2D0:
    ctx->pc = 0x8004D2D0u;
    // 8004D2D0: bl      0x8025B260
    {
            ctx->lr = 0x8004D2D4u;
            ctx->pc = 0x8025B260u;
            return;
    }

label_8004D2D4:
    ctx->pc = 0x8004D2D4u;
    ctx->downcount -= 15;
    // 8004D2D4: lfs     f1, -31276(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004D2D4u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31276);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8004D2D8:
    ctx->pc = 0x8004D2D8u;
    // 8004D2D8: stfs     f1, 80(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004D2D8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8004D2DC:
    ctx->pc = 0x8004D2DCu;
    // 8004D2DC: stfs     f1, 84(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004D2DCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8004D2E0:
    ctx->pc = 0x8004D2E0u;
    // 8004D2E0: lfs     f0, -31244(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004D2E0u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31244);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004D2E4:
    ctx->pc = 0x8004D2E4u;
    // 8004D2E4: stfs     f0, 88(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004D2E4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004D2E8:
    ctx->pc = 0x8004D2E8u;
    // 8004D2E8: lfs     f0, -31240(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004D2E8u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31240);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004D2EC:
    ctx->pc = 0x8004D2ECu;
    // 8004D2EC: stfs     f0, 92(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004D2ECu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004D2F0:
    ctx->pc = 0x8004D2F0u;
    // 8004D2F0: stfs     f1, 96(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004D2F0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8004D2F4:
    ctx->pc = 0x8004D2F4u;
    // 8004D2F4: stfs     f1, 100(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004D2F4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(100);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8004D2F8:
    ctx->pc = 0x8004D2F8u;
    // 8004D2F8: stfs     f1, 104(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004D2F8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8004D2FC:
    ctx->pc = 0x8004D2FCu;
    // 8004D2FC: stfs     f1, 108(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004D2FCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(108);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8004D300:
    ctx->pc = 0x8004D300u;
    // 8004D300: addi    r3, r1, 80
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(80);

label_8004D304:
    ctx->pc = 0x8004D304u;
    // 8004D304: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8004D308:
    ctx->pc = 0x8004D308u;
    // 8004D308: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004D30C:
    ctx->pc = 0x8004D30Cu;
    // 8004D30C: bl      0x80247860
    {
            ctx->lr = 0x8004D310u;
            ctx->pc = 0x80247860u;
            return;
    }

label_8004D310:
    ctx->pc = 0x8004D310u;
    ctx->downcount -= 4;
    // 8004D310: addi    r3, r1, 80
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(80);

label_8004D314:
    ctx->pc = 0x8004D314u;
    // 8004D314: li      r4, 36
    ctx->gpr[4] = (u32)(s32)(36);

label_8004D318:
    ctx->pc = 0x8004D318u;
    // 8004D318: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_8004D31C:
    ctx->pc = 0x8004D31Cu;
    // 8004D31C: bl      0x8025DAD0
    {
            ctx->lr = 0x8004D320u;
            ctx->pc = 0x8025DAD0u;
            return;
    }

label_8004D320:
    ctx->pc = 0x8004D320u;
    ctx->downcount -= 7;
    // 8004D320: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_8004D324:
    ctx->pc = 0x8004D324u;
    // 8004D324: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8004D328:
    ctx->pc = 0x8004D328u;
    // 8004D328: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004D32C:
    ctx->pc = 0x8004D32Cu;
    // 8004D32C: li      r6, 36
    ctx->gpr[6] = (u32)(s32)(36);

label_8004D330:
    ctx->pc = 0x8004D330u;
    // 8004D330: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004D334:
    ctx->pc = 0x8004D334u;
    // 8004D334: li      r8, 125
    ctx->gpr[8] = (u32)(s32)(125);

label_8004D338:
    ctx->pc = 0x8004D338u;
    // 8004D338: bl      0x80258880
    {
            ctx->lr = 0x8004D33Cu;
            ctx->pc = 0x80258880u;
            return;
    }

label_8004D33C:
    ctx->pc = 0x8004D33Cu;
    ctx->downcount -= 2;
    // 8004D33C: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8004D340:
    ctx->pc = 0x8004D340u;
    // 8004D340: bl      0x8025C08C
    {
            ctx->lr = 0x8004D344u;
            ctx->pc = 0x8025C08Cu;
            return;
    }

label_8004D344:
    ctx->pc = 0x8004D344u;
    ctx->downcount -= 5;
    // 8004D344: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8004D348:
    ctx->pc = 0x8004D348u;
    // 8004D348: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_8004D34C:
    ctx->pc = 0x8004D34Cu;
    // 8004D34C: li      r5, 3
    ctx->gpr[5] = (u32)(s32)(3);

label_8004D350:
    ctx->pc = 0x8004D350u;
    // 8004D350: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_8004D354:
    ctx->pc = 0x8004D354u;
    // 8004D354: bl      0x8025CA34
    {
            ctx->lr = 0x8004D358u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_8004D358:
    ctx->pc = 0x8004D358u;
    ctx->downcount -= 6;
    // 8004D358: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8004D35C:
    ctx->pc = 0x8004D35Cu;
    // 8004D35C: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_8004D360:
    ctx->pc = 0x8004D360u;
    // 8004D360: li      r5, 15
    ctx->gpr[5] = (u32)(s32)(15);

label_8004D364:
    ctx->pc = 0x8004D364u;
    // 8004D364: li      r6, 15
    ctx->gpr[6] = (u32)(s32)(15);

label_8004D368:
    ctx->pc = 0x8004D368u;
    // 8004D368: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004D36C:
    ctx->pc = 0x8004D36Cu;
    // 8004D36C: bl      0x8025C3B0
    {
            ctx->lr = 0x8004D370u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_8004D370:
    ctx->pc = 0x8004D370u;
    ctx->downcount -= 6;
    // 8004D370: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8004D374:
    ctx->pc = 0x8004D374u;
    // 8004D374: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_8004D378:
    ctx->pc = 0x8004D378u;
    // 8004D378: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_8004D37C:
    ctx->pc = 0x8004D37Cu;
    // 8004D37C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004D380:
    ctx->pc = 0x8004D380u;
    // 8004D380: li      r7, 7
    ctx->gpr[7] = (u32)(s32)(7);

label_8004D384:
    ctx->pc = 0x8004D384u;
    // 8004D384: bl      0x8025C430
    {
            ctx->lr = 0x8004D388u;
            ctx->pc = 0x8025C430u;
            return;
    }

label_8004D388:
    ctx->pc = 0x8004D388u;
    ctx->downcount -= 4;
    // 8004D388: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8004D38C:
    ctx->pc = 0x8004D38Cu;
    // 8004D38C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004D390:
    ctx->pc = 0x8004D390u;
    // 8004D390: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004D394:
    ctx->pc = 0x8004D394u;
    // 8004D394: bl      0x8025C868
    {
            ctx->lr = 0x8004D398u;
            ctx->pc = 0x8025C868u;
            return;
    }

label_8004D398:
    ctx->pc = 0x8004D398u;
    ctx->downcount -= 7;
    // 8004D398: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8004D39C:
    ctx->pc = 0x8004D39Cu;
    // 8004D39C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004D3A0:
    ctx->pc = 0x8004D3A0u;
    // 8004D3A0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004D3A4:
    ctx->pc = 0x8004D3A4u;
    // 8004D3A4: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004D3A8:
    ctx->pc = 0x8004D3A8u;
    // 8004D3A8: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004D3AC:
    ctx->pc = 0x8004D3ACu;
    // 8004D3AC: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8004D3B0:
    ctx->pc = 0x8004D3B0u;
    // 8004D3B0: bl      0x8025C4B4
    {
            ctx->lr = 0x8004D3B4u;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_8004D3B4:
    ctx->pc = 0x8004D3B4u;
    ctx->downcount -= 7;
    // 8004D3B4: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8004D3B8:
    ctx->pc = 0x8004D3B8u;
    // 8004D3B8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004D3BC:
    ctx->pc = 0x8004D3BCu;
    // 8004D3BC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004D3C0:
    ctx->pc = 0x8004D3C0u;
    // 8004D3C0: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004D3C4:
    ctx->pc = 0x8004D3C4u;
    // 8004D3C4: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004D3C8:
    ctx->pc = 0x8004D3C8u;
    // 8004D3C8: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8004D3CC:
    ctx->pc = 0x8004D3CCu;
    // 8004D3CC: bl      0x8025C574
    {
            ctx->lr = 0x8004D3D0u;
            ctx->pc = 0x8025C574u;
            return;
    }

label_8004D3D0:
    ctx->pc = 0x8004D3D0u;
    ctx->downcount -= 18;
    // 8004D3D0: li      r5, 3
    ctx->gpr[5] = (u32)(s32)(3);

label_8004D3D4:
    ctx->pc = 0x8004D3D4u;
    // 8004D3D4: stw     r5, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8004D3D8:
    ctx->pc = 0x8004D3D8u;
    // 8004D3D8: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_8004D3DC:
    ctx->pc = 0x8004D3DCu;
    // 8004D3DC: stw     r4, -25600(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25600);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8004D3E0:
    ctx->pc = 0x8004D3E0u;
    // 8004D3E0: stw     r4, -25596(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25596);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8004D3E4:
    ctx->pc = 0x8004D3E4u;
    // 8004D3E4: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8004D3E8:
    ctx->pc = 0x8004D3E8u;
    // 8004D3E8: stw     r3, -25612(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25612);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8004D3EC:
    ctx->pc = 0x8004D3ECu;
    // 8004D3EC: li      r0, 39
    ctx->gpr[0] = (u32)(s32)(39);

label_8004D3F0:
    ctx->pc = 0x8004D3F0u;
    // 8004D3F0: stw     r0, -25604(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25604);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004D3F4:
    ctx->pc = 0x8004D3F4u;
    // 8004D3F4: stb     r5, -25630(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25630);
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

label_8004D3F8:
    ctx->pc = 0x8004D3F8u;
    // 8004D3F8: stb     r4, -25631(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25631);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_8004D3FC:
    ctx->pc = 0x8004D3FCu;
    // 8004D3FC: stb     r3, -25632(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25632);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_8004D400:
    ctx->pc = 0x8004D400u;
    // 8004D400: lwz     r31, 140(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(140);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8004D404:
    ctx->pc = 0x8004D404u;
    // 8004D404: lwz     r0, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004D408:
    ctx->pc = 0x8004D408u;
    // 8004D408: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004D40C:
    ctx->pc = 0x8004D40Cu;
    // 8004D40C: addi    r1, r1, 144
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(144);

label_8004D410:
    ctx->pc = 0x8004D410u;
    // 8004D410: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004D414:
    ctx->pc = 0x8004D414u;
    ctx->downcount -= 5;
    // 8004D414: stwu     r1, -128(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-128);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004D418:
    ctx->pc = 0x8004D418u;
    // 8004D418: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004D41C:
    ctx->pc = 0x8004D41Cu;
    // 8004D41C: stw     r0, 132(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(132);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004D420:
    ctx->pc = 0x8004D420u;
    // 8004D420: stw     r31, 124(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(124);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8004D424:
    ctx->pc = 0x8004D424u;
    // 8004D424: bl      0x8006C938
    {
            ctx->lr = 0x8004D428u;
            ctx->pc = 0x8006C938u;
            return;
    }

label_8004D428:
    ctx->pc = 0x8004D428u;
    ctx->downcount -= 11;
    // 8004D428: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004D42C:
    ctx->pc = 0x8004D42Cu;
    // 8004D42C: addi    r3, r1, 56
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(56);

label_8004D430:
    ctx->pc = 0x8004D430u;
    // 8004D430: lfs     f1, -31236(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004D430u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31236);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8004D434:
    ctx->pc = 0x8004D434u;
    // 8004D434: lfs     f2, -31232(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004D434u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31232);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8004D438:
    ctx->pc = 0x8004D438u;
    // 8004D438: fmr    f3, f2
    if (!ppc_fp_available_inline(ctx, 0x8004D438u)) return;
    ctx->fpr[3] = ctx->fpr[2];

label_8004D43C:
    ctx->pc = 0x8004D43Cu;
    // 8004D43C: fmr    f4, f1
    if (!ppc_fp_available_inline(ctx, 0x8004D43Cu)) return;
    ctx->fpr[4] = ctx->fpr[1];

label_8004D440:
    ctx->pc = 0x8004D440u;
    // 8004D440: lfs     f5, -31260(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004D440u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31260);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[5] = value;
        ctx->ps1[5] = value;
    }

label_8004D444:
    ctx->pc = 0x8004D444u;
    // 8004D444: fmr    f6, f5
    if (!ppc_fp_available_inline(ctx, 0x8004D444u)) return;
    ctx->fpr[6] = ctx->fpr[5];

label_8004D448:
    ctx->pc = 0x8004D448u;
    // 8004D448: fmr    f7, f5
    if (!ppc_fp_available_inline(ctx, 0x8004D448u)) return;
    ctx->fpr[7] = ctx->fpr[5];

label_8004D44C:
    ctx->pc = 0x8004D44Cu;
    // 8004D44C: fmr    f8, f5
    if (!ppc_fp_available_inline(ctx, 0x8004D44Cu)) return;
    ctx->fpr[8] = ctx->fpr[5];

label_8004D450:
    ctx->pc = 0x8004D450u;
    // 8004D450: bl      0x80247DB8
    {
            ctx->lr = 0x8004D454u;
            ctx->pc = 0x80247DB8u;
            return;
    }

label_8004D454:
    ctx->pc = 0x8004D454u;
    ctx->downcount -= 4;
    // 8004D454: addi    r3, r1, 56
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(56);

label_8004D458:
    ctx->pc = 0x8004D458u;
    // 8004D458: lwz     r4, -25608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004D45C:
    ctx->pc = 0x8004D45Cu;
    // 8004D45C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004D460:
    ctx->pc = 0x8004D460u;
    // 8004D460: bl      0x8025DAD0
    {
            ctx->lr = 0x8004D464u;
            ctx->pc = 0x8025DAD0u;
            return;
    }

label_8004D464:
    ctx->pc = 0x8004D464u;
    ctx->downcount -= 7;
    // 8004D464: lwz     r3, -25600(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25600);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D468:
    ctx->pc = 0x8004D468u;
    // 8004D468: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004D46C:
    ctx->pc = 0x8004D46Cu;
    // 8004D46C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004D470:
    ctx->pc = 0x8004D470u;
    // 8004D470: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004D474:
    ctx->pc = 0x8004D474u;
    // 8004D474: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004D478:
    ctx->pc = 0x8004D478u;
    // 8004D478: lwz     r8, -25608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25608);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8004D47C:
    ctx->pc = 0x8004D47Cu;
    // 8004D47C: bl      0x80258880
    {
            ctx->lr = 0x8004D480u;
            ctx->pc = 0x80258880u;
            return;
    }

label_8004D480:
    ctx->pc = 0x8004D480u;
    ctx->downcount -= 2;
    // 8004D480: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D484:
    ctx->pc = 0x8004D484u;
    // 8004D484: bl      0x8025C08C
    {
            ctx->lr = 0x8004D488u;
            ctx->pc = 0x8025C08Cu;
            return;
    }

label_8004D488:
    ctx->pc = 0x8004D488u;
    ctx->downcount -= 5;
    // 8004D488: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D48C:
    ctx->pc = 0x8004D48Cu;
    // 8004D48C: lwz     r4, -25600(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25600);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004D490:
    ctx->pc = 0x8004D490u;
    // 8004D490: lwz     r5, -25596(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25596);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8004D494:
    ctx->pc = 0x8004D494u;
    // 8004D494: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_8004D498:
    ctx->pc = 0x8004D498u;
    // 8004D498: bl      0x8025CA34
    {
            ctx->lr = 0x8004D49Cu;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_8004D49C:
    ctx->pc = 0x8004D49Cu;
    ctx->downcount -= 6;
    // 8004D49C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8004D4A0:
    ctx->pc = 0x8004D4A0u;
    // 8004D4A0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004D4A4:
    ctx->pc = 0x8004D4A4u;
    // 8004D4A4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004D4A8:
    ctx->pc = 0x8004D4A8u;
    // 8004D4A8: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004D4AC:
    ctx->pc = 0x8004D4ACu;
    // 8004D4AC: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004D4B0:
    ctx->pc = 0x8004D4B0u;
    // 8004D4B0: bl      0x8025C8C0
    {
            ctx->lr = 0x8004D4B4u;
            ctx->pc = 0x8025C8C0u;
            return;
    }

label_8004D4B4:
    ctx->pc = 0x8004D4B4u;
    ctx->downcount -= 4;
    // 8004D4B4: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D4B8:
    ctx->pc = 0x8004D4B8u;
    // 8004D4B8: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8004D4BC:
    ctx->pc = 0x8004D4BCu;
    // 8004D4BC: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_8004D4C0:
    ctx->pc = 0x8004D4C0u;
    // 8004D4C0: bl      0x8025C868
    {
            ctx->lr = 0x8004D4C4u;
            ctx->pc = 0x8025C868u;
            return;
    }

label_8004D4C4:
    ctx->pc = 0x8004D4C4u;
    ctx->downcount -= 3;
    // 8004D4C4: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D4C8:
    ctx->pc = 0x8004D4C8u;
    // 8004D4C8: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004D4CC:
    ctx->pc = 0x8004D4CCu;
    // 8004D4CC: bc    4, 2, 0x8004D4E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004D4E8;
        }
    }

label_8004D4D0:
    ctx->pc = 0x8004D4D0u;
    ctx->downcount -= 5;
    // 8004D4D0: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_8004D4D4:
    ctx->pc = 0x8004D4D4u;
    // 8004D4D4: li      r5, 15
    ctx->gpr[5] = (u32)(s32)(15);

label_8004D4D8:
    ctx->pc = 0x8004D4D8u;
    // 8004D4D8: li      r6, 15
    ctx->gpr[6] = (u32)(s32)(15);

label_8004D4DC:
    ctx->pc = 0x8004D4DCu;
    // 8004D4DC: li      r7, 15
    ctx->gpr[7] = (u32)(s32)(15);

label_8004D4E0:
    ctx->pc = 0x8004D4E0u;
    // 8004D4E0: bl      0x8025C3B0
    {
            ctx->lr = 0x8004D4E4u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_8004D4E4:
    ctx->pc = 0x8004D4E4u;
    ctx->downcount -= 1;
    // 8004D4E4: b       0x8004D4FC
    {
            goto label_8004D4FC;
    }

label_8004D4E8:
    ctx->pc = 0x8004D4E8u;
    ctx->downcount -= 5;
    // 8004D4E8: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_8004D4EC:
    ctx->pc = 0x8004D4ECu;
    // 8004D4EC: li      r5, 15
    ctx->gpr[5] = (u32)(s32)(15);

label_8004D4F0:
    ctx->pc = 0x8004D4F0u;
    // 8004D4F0: li      r6, 15
    ctx->gpr[6] = (u32)(s32)(15);

label_8004D4F4:
    ctx->pc = 0x8004D4F4u;
    // 8004D4F4: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004D4F8:
    ctx->pc = 0x8004D4F8u;
    // 8004D4F8: bl      0x8025C3B0
    {
            ctx->lr = 0x8004D4FCu;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_8004D4FC:
    ctx->pc = 0x8004D4FCu;
    ctx->downcount -= 6;
    // 8004D4FC: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D500:
    ctx->pc = 0x8004D500u;
    // 8004D500: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_8004D504:
    ctx->pc = 0x8004D504u;
    // 8004D504: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_8004D508:
    ctx->pc = 0x8004D508u;
    // 8004D508: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_8004D50C:
    ctx->pc = 0x8004D50Cu;
    // 8004D50C: li      r7, 4
    ctx->gpr[7] = (u32)(s32)(4);

label_8004D510:
    ctx->pc = 0x8004D510u;
    // 8004D510: bl      0x8025C430
    {
            ctx->lr = 0x8004D514u;
            ctx->pc = 0x8025C430u;
            return;
    }

label_8004D514:
    ctx->pc = 0x8004D514u;
    ctx->downcount -= 7;
    // 8004D514: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D518:
    ctx->pc = 0x8004D518u;
    // 8004D518: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004D51C:
    ctx->pc = 0x8004D51Cu;
    // 8004D51C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004D520:
    ctx->pc = 0x8004D520u;
    // 8004D520: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004D524:
    ctx->pc = 0x8004D524u;
    // 8004D524: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004D528:
    ctx->pc = 0x8004D528u;
    // 8004D528: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8004D52C:
    ctx->pc = 0x8004D52Cu;
    // 8004D52C: bl      0x8025C4B4
    {
            ctx->lr = 0x8004D530u;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_8004D530:
    ctx->pc = 0x8004D530u;
    ctx->downcount -= 7;
    // 8004D530: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D534:
    ctx->pc = 0x8004D534u;
    // 8004D534: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004D538:
    ctx->pc = 0x8004D538u;
    // 8004D538: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004D53C:
    ctx->pc = 0x8004D53Cu;
    // 8004D53C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004D540:
    ctx->pc = 0x8004D540u;
    // 8004D540: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004D544:
    ctx->pc = 0x8004D544u;
    // 8004D544: li      r8, 2
    ctx->gpr[8] = (u32)(s32)(2);

label_8004D548:
    ctx->pc = 0x8004D548u;
    // 8004D548: bl      0x8025C574
    {
            ctx->lr = 0x8004D54Cu;
            ctx->pc = 0x8025C574u;
            return;
    }

label_8004D54C:
    ctx->pc = 0x8004D54Cu;
    ctx->downcount -= 5;
    // 8004D54C: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8004D550:
    ctx->pc = 0x8004D550u;
    // 8004D550: stb     r0, -25688(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25688);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004D554:
    ctx->pc = 0x8004D554u;
    // 8004D554: lwz     r5, -25596(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25596);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8004D558:
    ctx->pc = 0x8004D558u;
    // 8004D558: cmplwi  r31, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[31]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004D55C:
    ctx->pc = 0x8004D55Cu;
    // 8004D55C: bc    12, 2, 0x8004D584
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004D584;
        }
    }

label_8004D560:
    ctx->pc = 0x8004D560u;
    ctx->downcount -= 4;
    // 8004D560: addi    r3, r31, 32
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(32);

label_8004D564:
    ctx->pc = 0x8004D564u;
    // 8004D564: lbz     r0, 72(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(72);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8004D568:
    ctx->pc = 0x8004D568u;
    // 8004D568: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004D56C:
    ctx->pc = 0x8004D56Cu;
    // 8004D56C: bc    12, 2, 0x8004D57C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004D57C;
        }
    }

label_8004D570:
    ctx->pc = 0x8004D570u;
    ctx->downcount -= 2;
    // 8004D570: lwz     r4, 64(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(64);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004D574:
    ctx->pc = 0x8004D574u;
    // 8004D574: bl      0x8025B0B8
    {
            ctx->lr = 0x8004D578u;
            ctx->pc = 0x8025B0B8u;
            return;
    }

label_8004D578:
    ctx->pc = 0x8004D578u;
    ctx->downcount -= 1;
    // 8004D578: b       0x8004D584
    {
            goto label_8004D584;
    }

label_8004D57C:
    ctx->pc = 0x8004D57Cu;
    ctx->downcount -= 2;
    // 8004D57C: or   r4, r5, r5
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8004D580:
    ctx->pc = 0x8004D580u;
    // 8004D580: bl      0x8025B260
    {
            ctx->lr = 0x8004D584u;
            ctx->pc = 0x8025B260u;
            return;
    }

label_8004D584:
    ctx->pc = 0x8004D584u;
    ctx->downcount -= 13;
    // 8004D584: lwz     r3, -25608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D588:
    ctx->pc = 0x8004D588u;
    // 8004D588: addi    r0, r3, 3
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(3);

label_8004D58C:
    ctx->pc = 0x8004D58Cu;
    // 8004D58C: stw     r0, -25608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25608);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004D590:
    ctx->pc = 0x8004D590u;
    // 8004D590: lwz     r3, -25600(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25600);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D594:
    ctx->pc = 0x8004D594u;
    // 8004D594: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8004D598:
    ctx->pc = 0x8004D598u;
    // 8004D598: stw     r0, -25600(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25600);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004D59C:
    ctx->pc = 0x8004D59Cu;
    // 8004D59C: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D5A0:
    ctx->pc = 0x8004D5A0u;
    // 8004D5A0: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8004D5A4:
    ctx->pc = 0x8004D5A4u;
    // 8004D5A4: stw     r0, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004D5A8:
    ctx->pc = 0x8004D5A8u;
    // 8004D5A8: lwz     r3, -25596(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25596);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D5AC:
    ctx->pc = 0x8004D5ACu;
    // 8004D5AC: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8004D5B0:
    ctx->pc = 0x8004D5B0u;
    // 8004D5B0: stw     r0, -25596(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25596);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004D5B4:
    ctx->pc = 0x8004D5B4u;
    // 8004D5B4: bl      0x8002BB60
    {
            ctx->lr = 0x8004D5B8u;
            ctx->pc = 0x8002BB60u;
            return;
    }

label_8004D5B8:
    ctx->pc = 0x8004D5B8u;
    ctx->downcount -= 2;
    // 8004D5B8: cmplwi  r3, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004D5BC:
    ctx->pc = 0x8004D5BCu;
    // 8004D5BC: bc    12, 2, 0x8004D5D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004D5D4;
        }
    }

label_8004D5C0:
    ctx->pc = 0x8004D5C0u;
    ctx->downcount -= 4;
    // 8004D5C0: lfs     f1, 24(r3)
    if (!ppc_fp_available_inline(ctx, 0x8004D5C0u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8004D5C4:
    ctx->pc = 0x8004D5C4u;
    // 8004D5C4: lfs     f2, 28(r3)
    if (!ppc_fp_available_inline(ctx, 0x8004D5C4u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(28);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8004D5C8:
    ctx->pc = 0x8004D5C8u;
    // 8004D5C8: lfs     f3, 32(r3)
    if (!ppc_fp_available_inline(ctx, 0x8004D5C8u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(32);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8004D5CC:
    ctx->pc = 0x8004D5CCu;
    // 8004D5CC: bl      0x8000F4A0
    {
            ctx->lr = 0x8004D5D0u;
            ctx->pc = 0x8000F4A0u;
            return;
    }

label_8004D5D0:
    ctx->pc = 0x8004D5D0u;
    ctx->downcount -= 1;
    // 8004D5D0: b       0x8004D5D8
    {
            goto label_8004D5D8;
    }

label_8004D5D4:
    ctx->pc = 0x8004D5D4u;
    ctx->downcount -= 1;
    // 8004D5D4: lfs     f1, -31228(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004D5D4u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31228);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8004D5D8:
    ctx->pc = 0x8004D5D8u;
    ctx->downcount -= 40;
    // 8004D5D8: lfs     f0, -31224(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004D5D8u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31224);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004D5DC:
    ctx->pc = 0x8004D5DCu;
    // 8004D5DC: fsubs   f3, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8004D5DCu)) return;
    ppc_fsubs(ctx, 3, 1, 0);

label_8004D5E0:
    ctx->pc = 0x8004D5E0u;
    // 8004D5E0: lfs     f2, -31280(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004D5E0u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31280);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8004D5E4:
    ctx->pc = 0x8004D5E4u;
    // 8004D5E4: fsubs   f0, f1, f3
    if (!ppc_fp_available_inline(ctx, 0x8004D5E4u)) return;
    ppc_fsubs(ctx, 0, 1, 3);

label_8004D5E8:
    ctx->pc = 0x8004D5E8u;
    // 8004D5E8: fdivs   f0, f2, f0
    if (!ppc_fp_available_inline(ctx, 0x8004D5E8u)) return;
    ppc_fdivs(ctx, 0, 2, 0);

label_8004D5EC:
    ctx->pc = 0x8004D5ECu;
    // 8004D5EC: fneg    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x8004D5ECu)) return;
    ctx->fpr[0] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[0]) ^ 0x8000000000000000ull);

label_8004D5F0:
    ctx->pc = 0x8004D5F0u;
    // 8004D5F0: lfs     f1, -31276(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004D5F0u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31276);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8004D5F4:
    ctx->pc = 0x8004D5F4u;
    // 8004D5F4: stfs     f1, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004D5F4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8004D5F8:
    ctx->pc = 0x8004D5F8u;
    // 8004D5F8: stfs     f1, 12(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004D5F8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8004D5FC:
    ctx->pc = 0x8004D5FCu;
    // 8004D5FC: stfs     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004D5FCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004D600:
    ctx->pc = 0x8004D600u;
    // 8004D600: fmuls   f0, f0, f3
    if (!ppc_fp_available_inline(ctx, 0x8004D600u)) return;
    ppc_fmuls(ctx, 0, 0, 3);

label_8004D604:
    ctx->pc = 0x8004D604u;
    // 8004D604: stfs     f0, 20(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004D604u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004D608:
    ctx->pc = 0x8004D608u;
    // 8004D608: stfs     f1, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004D608u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8004D60C:
    ctx->pc = 0x8004D60Cu;
    // 8004D60C: stfs     f1, 28(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004D60Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8004D610:
    ctx->pc = 0x8004D610u;
    // 8004D610: stfs     f1, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004D610u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8004D614:
    ctx->pc = 0x8004D614u;
    // 8004D614: stfs     f1, 36(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004D614u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8004D618:
    ctx->pc = 0x8004D618u;
    // 8004D618: stfs     f1, 40(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004D618u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8004D61C:
    ctx->pc = 0x8004D61Cu;
    // 8004D61C: stfs     f1, 44(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004D61Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8004D620:
    ctx->pc = 0x8004D620u;
    // 8004D620: stfs     f1, 48(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004D620u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8004D624:
    ctx->pc = 0x8004D624u;
    // 8004D624: stfs     f1, 52(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004D624u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8004D628:
    ctx->pc = 0x8004D628u;
    // 8004D628: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_8004D62C:
    ctx->pc = 0x8004D62Cu;
    // 8004D62C: lwz     r4, -25608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004D630:
    ctx->pc = 0x8004D630u;
    // 8004D630: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004D634:
    ctx->pc = 0x8004D634u;
    // 8004D634: bl      0x8025DAD0
    {
            ctx->lr = 0x8004D638u;
            ctx->pc = 0x8025DAD0u;
            return;
    }

label_8004D638:
    ctx->pc = 0x8004D638u;
    ctx->downcount -= 7;
    // 8004D638: lwz     r3, -25600(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25600);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D63C:
    ctx->pc = 0x8004D63Cu;
    // 8004D63C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004D640:
    ctx->pc = 0x8004D640u;
    // 8004D640: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004D644:
    ctx->pc = 0x8004D644u;
    // 8004D644: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004D648:
    ctx->pc = 0x8004D648u;
    // 8004D648: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004D64C:
    ctx->pc = 0x8004D64Cu;
    // 8004D64C: lwz     r8, -25608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25608);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8004D650:
    ctx->pc = 0x8004D650u;
    // 8004D650: bl      0x80258880
    {
            ctx->lr = 0x8004D654u;
            ctx->pc = 0x80258880u;
            return;
    }

label_8004D654:
    ctx->pc = 0x8004D654u;
    ctx->downcount -= 2;
    // 8004D654: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D658:
    ctx->pc = 0x8004D658u;
    // 8004D658: bl      0x8025C08C
    {
            ctx->lr = 0x8004D65Cu;
            ctx->pc = 0x8025C08Cu;
            return;
    }

label_8004D65C:
    ctx->pc = 0x8004D65Cu;
    ctx->downcount -= 5;
    // 8004D65C: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D660:
    ctx->pc = 0x8004D660u;
    // 8004D660: lwz     r4, -25600(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25600);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004D664:
    ctx->pc = 0x8004D664u;
    // 8004D664: lwz     r5, -25596(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25596);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8004D668:
    ctx->pc = 0x8004D668u;
    // 8004D668: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_8004D66C:
    ctx->pc = 0x8004D66Cu;
    // 8004D66C: bl      0x8025CA34
    {
            ctx->lr = 0x8004D670u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_8004D670:
    ctx->pc = 0x8004D670u;
    ctx->downcount -= 4;
    // 8004D670: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D674:
    ctx->pc = 0x8004D674u;
    // 8004D674: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8004D678:
    ctx->pc = 0x8004D678u;
    // 8004D678: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_8004D67C:
    ctx->pc = 0x8004D67Cu;
    // 8004D67C: bl      0x8025C868
    {
            ctx->lr = 0x8004D680u;
            ctx->pc = 0x8025C868u;
            return;
    }

label_8004D680:
    ctx->pc = 0x8004D680u;
    ctx->downcount -= 6;
    // 8004D680: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D684:
    ctx->pc = 0x8004D684u;
    // 8004D684: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_8004D688:
    ctx->pc = 0x8004D688u;
    // 8004D688: li      r5, 15
    ctx->gpr[5] = (u32)(s32)(15);

label_8004D68C:
    ctx->pc = 0x8004D68Cu;
    // 8004D68C: li      r6, 15
    ctx->gpr[6] = (u32)(s32)(15);

label_8004D690:
    ctx->pc = 0x8004D690u;
    // 8004D690: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004D694:
    ctx->pc = 0x8004D694u;
    // 8004D694: bl      0x8025C3B0
    {
            ctx->lr = 0x8004D698u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_8004D698:
    ctx->pc = 0x8004D698u;
    ctx->downcount -= 3;
    // 8004D698: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D69C:
    ctx->pc = 0x8004D69Cu;
    // 8004D69C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004D6A0:
    ctx->pc = 0x8004D6A0u;
    // 8004D6A0: bl      0x8025C7FC
    {
            ctx->lr = 0x8004D6A4u;
            ctx->pc = 0x8025C7FCu;
            return;
    }

label_8004D6A4:
    ctx->pc = 0x8004D6A4u;
    ctx->downcount -= 6;
    // 8004D6A4: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D6A8:
    ctx->pc = 0x8004D6A8u;
    // 8004D6A8: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_8004D6AC:
    ctx->pc = 0x8004D6ACu;
    // 8004D6AC: li      r5, 2
    ctx->gpr[5] = (u32)(s32)(2);

label_8004D6B0:
    ctx->pc = 0x8004D6B0u;
    // 8004D6B0: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_8004D6B4:
    ctx->pc = 0x8004D6B4u;
    // 8004D6B4: li      r7, 6
    ctx->gpr[7] = (u32)(s32)(6);

label_8004D6B8:
    ctx->pc = 0x8004D6B8u;
    // 8004D6B8: bl      0x8025C430
    {
            ctx->lr = 0x8004D6BCu;
            ctx->pc = 0x8025C430u;
            return;
    }

label_8004D6BC:
    ctx->pc = 0x8004D6BCu;
    ctx->downcount -= 7;
    // 8004D6BC: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D6C0:
    ctx->pc = 0x8004D6C0u;
    // 8004D6C0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004D6C4:
    ctx->pc = 0x8004D6C4u;
    // 8004D6C4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004D6C8:
    ctx->pc = 0x8004D6C8u;
    // 8004D6C8: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004D6CC:
    ctx->pc = 0x8004D6CCu;
    // 8004D6CC: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004D6D0:
    ctx->pc = 0x8004D6D0u;
    // 8004D6D0: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8004D6D4:
    ctx->pc = 0x8004D6D4u;
    // 8004D6D4: bl      0x8025C4B4
    {
            ctx->lr = 0x8004D6D8u;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_8004D6D8:
    ctx->pc = 0x8004D6D8u;
    ctx->downcount -= 7;
    // 8004D6D8: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D6DC:
    ctx->pc = 0x8004D6DCu;
    // 8004D6DC: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8004D6E0:
    ctx->pc = 0x8004D6E0u;
    // 8004D6E0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004D6E4:
    ctx->pc = 0x8004D6E4u;
    // 8004D6E4: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004D6E8:
    ctx->pc = 0x8004D6E8u;
    // 8004D6E8: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004D6EC:
    ctx->pc = 0x8004D6ECu;
    // 8004D6EC: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8004D6F0:
    ctx->pc = 0x8004D6F0u;
    // 8004D6F0: bl      0x8025C574
    {
            ctx->lr = 0x8004D6F4u;
            ctx->pc = 0x8025C574u;
            return;
    }

label_8004D6F4:
    ctx->pc = 0x8004D6F4u;
    ctx->downcount -= 3;
    // 8004D6F4: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8004D6F8:
    ctx->pc = 0x8004D6F8u;
    // 8004D6F8: stb     r0, -25688(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25688);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004D6FC:
    ctx->pc = 0x8004D6FCu;
    // 8004D6FC: bl      0x8006C930
    {
            ctx->lr = 0x8004D700u;
            ctx->pc = 0x8006C930u;
            return;
    }

label_8004D700:
    ctx->pc = 0x8004D700u;
    ctx->downcount -= 4;
    // 8004D700: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004D704:
    ctx->pc = 0x8004D704u;
    // 8004D704: lwz     r5, -25596(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25596);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8004D708:
    ctx->pc = 0x8004D708u;
    // 8004D708: cmplwi  r4, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004D70C:
    ctx->pc = 0x8004D70Cu;
    // 8004D70C: bc    12, 2, 0x8004D734
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004D734;
        }
    }

label_8004D710:
    ctx->pc = 0x8004D710u;
    ctx->downcount -= 4;
    // 8004D710: addi    r3, r4, 32
    ctx->gpr[3] = ctx->gpr[4] + (u32)(s32)(32);

label_8004D714:
    ctx->pc = 0x8004D714u;
    // 8004D714: lbz     r0, 72(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(72);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8004D718:
    ctx->pc = 0x8004D718u;
    // 8004D718: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004D71C:
    ctx->pc = 0x8004D71Cu;
    // 8004D71C: bc    12, 2, 0x8004D72C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004D72C;
        }
    }

label_8004D720:
    ctx->pc = 0x8004D720u;
    ctx->downcount -= 2;
    // 8004D720: lwz     r4, 64(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(64);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004D724:
    ctx->pc = 0x8004D724u;
    // 8004D724: bl      0x8025B0B8
    {
            ctx->lr = 0x8004D728u;
            ctx->pc = 0x8025B0B8u;
            return;
    }

label_8004D728:
    ctx->pc = 0x8004D728u;
    ctx->downcount -= 1;
    // 8004D728: b       0x8004D734
    {
            goto label_8004D734;
    }

label_8004D72C:
    ctx->pc = 0x8004D72Cu;
    ctx->downcount -= 2;
    // 8004D72C: or   r4, r5, r5
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8004D730:
    ctx->pc = 0x8004D730u;
    // 8004D730: bl      0x8025B260
    {
            ctx->lr = 0x8004D734u;
            ctx->pc = 0x8025B260u;
            return;
    }

label_8004D734:
    ctx->pc = 0x8004D734u;
    ctx->downcount -= 26;
    // 8004D734: lwz     r3, -25608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D738:
    ctx->pc = 0x8004D738u;
    // 8004D738: addi    r0, r3, 3
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(3);

label_8004D73C:
    ctx->pc = 0x8004D73Cu;
    // 8004D73C: stw     r0, -25608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25608);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004D740:
    ctx->pc = 0x8004D740u;
    // 8004D740: lwz     r3, -25600(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25600);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D744:
    ctx->pc = 0x8004D744u;
    // 8004D744: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8004D748:
    ctx->pc = 0x8004D748u;
    // 8004D748: stw     r0, -25600(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25600);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004D74C:
    ctx->pc = 0x8004D74Cu;
    // 8004D74C: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D750:
    ctx->pc = 0x8004D750u;
    // 8004D750: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8004D754:
    ctx->pc = 0x8004D754u;
    // 8004D754: stw     r0, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004D758:
    ctx->pc = 0x8004D758u;
    // 8004D758: lwz     r3, -25596(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25596);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D75C:
    ctx->pc = 0x8004D75Cu;
    // 8004D75C: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8004D760:
    ctx->pc = 0x8004D760u;
    // 8004D760: stw     r0, -25596(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25596);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004D764:
    ctx->pc = 0x8004D764u;
    // 8004D764: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8004D768:
    ctx->pc = 0x8004D768u;
    // 8004D768: stb     r0, -25629(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25629);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004D76C:
    ctx->pc = 0x8004D76Cu;
    // 8004D76C: lbz     r3, -25630(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25630);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8004D770:
    ctx->pc = 0x8004D770u;
    // 8004D770: addi    r0, r3, 2
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(2);

label_8004D774:
    ctx->pc = 0x8004D774u;
    // 8004D774: stb     r0, -25630(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25630);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004D778:
    ctx->pc = 0x8004D778u;
    // 8004D778: lbz     r3, -25631(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25631);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8004D77C:
    ctx->pc = 0x8004D77Cu;
    // 8004D77C: addi    r0, r3, 2
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(2);

label_8004D780:
    ctx->pc = 0x8004D780u;
    // 8004D780: stb     r0, -25631(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25631);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004D784:
    ctx->pc = 0x8004D784u;
    // 8004D784: lwz     r31, 124(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(124);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8004D788:
    ctx->pc = 0x8004D788u;
    // 8004D788: lwz     r0, 132(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(132);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004D78C:
    ctx->pc = 0x8004D78Cu;
    // 8004D78C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004D790:
    ctx->pc = 0x8004D790u;
    // 8004D790: addi    r1, r1, 128
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(128);

label_8004D794:
    ctx->pc = 0x8004D794u;
    // 8004D794: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004D798:
    ctx->pc = 0x8004D798u;
    ctx->downcount -= 12;
    // 8004D798: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004D79C:
    ctx->pc = 0x8004D79Cu;
    // 8004D79C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004D7A0:
    ctx->pc = 0x8004D7A0u;
    // 8004D7A0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004D7A4:
    ctx->pc = 0x8004D7A4u;
    // 8004D7A4: lbz     r0, 67(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(67);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8004D7A8:
    ctx->pc = 0x8004D7A8u;
    // 8004D7A8: stb     r0, 14(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(14);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004D7AC:
    ctx->pc = 0x8004D7ACu;
    // 8004D7AC: stb     r0, 13(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(13);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004D7B0:
    ctx->pc = 0x8004D7B0u;
    // 8004D7B0: stb     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004D7B4:
    ctx->pc = 0x8004D7B4u;
    // 8004D7B4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004D7B8:
    ctx->pc = 0x8004D7B8u;
    // 8004D7B8: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004D7BC:
    ctx->pc = 0x8004D7BCu;
    // 8004D7BC: lwz     r3, -25620(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25620);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D7C0:
    ctx->pc = 0x8004D7C0u;
    // 8004D7C0: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_8004D7C4:
    ctx->pc = 0x8004D7C4u;
    // 8004D7C4: bl      0x8025C71C
    {
            ctx->lr = 0x8004D7C8u;
            ctx->pc = 0x8025C71Cu;
            return;
    }

label_8004D7C8:
    ctx->pc = 0x8004D7C8u;
    ctx->downcount -= 3;
    // 8004D7C8: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D7CC:
    ctx->pc = 0x8004D7CCu;
    // 8004D7CC: lwz     r4, -25624(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25624);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004D7D0:
    ctx->pc = 0x8004D7D0u;
    // 8004D7D0: bl      0x8025C790
    {
            ctx->lr = 0x8004D7D4u;
            ctx->pc = 0x8025C790u;
            return;
    }

label_8004D7D4:
    ctx->pc = 0x8004D7D4u;
    ctx->downcount -= 2;
    // 8004D7D4: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D7D8:
    ctx->pc = 0x8004D7D8u;
    // 8004D7D8: bl      0x8025C08C
    {
            ctx->lr = 0x8004D7DCu;
            ctx->pc = 0x8025C08Cu;
            return;
    }

label_8004D7DC:
    ctx->pc = 0x8004D7DCu;
    ctx->downcount -= 5;
    // 8004D7DC: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D7E0:
    ctx->pc = 0x8004D7E0u;
    // 8004D7E0: li      r4, 255
    ctx->gpr[4] = (u32)(s32)(255);

label_8004D7E4:
    ctx->pc = 0x8004D7E4u;
    // 8004D7E4: li      r5, 255
    ctx->gpr[5] = (u32)(s32)(255);

label_8004D7E8:
    ctx->pc = 0x8004D7E8u;
    // 8004D7E8: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_8004D7EC:
    ctx->pc = 0x8004D7ECu;
    // 8004D7EC: bl      0x8025CA34
    {
            ctx->lr = 0x8004D7F0u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_8004D7F0:
    ctx->pc = 0x8004D7F0u;
    ctx->downcount -= 4;
    // 8004D7F0: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D7F4:
    ctx->pc = 0x8004D7F4u;
    // 8004D7F4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004D7F8:
    ctx->pc = 0x8004D7F8u;
    // 8004D7F8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004D7FC:
    ctx->pc = 0x8004D7FCu;
    // 8004D7FC: bl      0x8025C868
    {
            ctx->lr = 0x8004D800u;
            ctx->pc = 0x8025C868u;
            return;
    }

label_8004D800:
    ctx->pc = 0x8004D800u;
    ctx->downcount -= 6;
    // 8004D800: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D804:
    ctx->pc = 0x8004D804u;
    // 8004D804: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004D808:
    ctx->pc = 0x8004D808u;
    // 8004D808: li      r5, 2
    ctx->gpr[5] = (u32)(s32)(2);

label_8004D80C:
    ctx->pc = 0x8004D80Cu;
    // 8004D80C: li      r6, 14
    ctx->gpr[6] = (u32)(s32)(14);

label_8004D810:
    ctx->pc = 0x8004D810u;
    // 8004D810: li      r7, 15
    ctx->gpr[7] = (u32)(s32)(15);

label_8004D814:
    ctx->pc = 0x8004D814u;
    // 8004D814: bl      0x8025C3B0
    {
            ctx->lr = 0x8004D818u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_8004D818:
    ctx->pc = 0x8004D818u;
    ctx->downcount -= 6;
    // 8004D818: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D81C:
    ctx->pc = 0x8004D81Cu;
    // 8004D81C: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_8004D820:
    ctx->pc = 0x8004D820u;
    // 8004D820: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_8004D824:
    ctx->pc = 0x8004D824u;
    // 8004D824: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_8004D828:
    ctx->pc = 0x8004D828u;
    // 8004D828: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004D82C:
    ctx->pc = 0x8004D82Cu;
    // 8004D82C: bl      0x8025C430
    {
            ctx->lr = 0x8004D830u;
            ctx->pc = 0x8025C430u;
            return;
    }

label_8004D830:
    ctx->pc = 0x8004D830u;
    ctx->downcount -= 7;
    // 8004D830: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D834:
    ctx->pc = 0x8004D834u;
    // 8004D834: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004D838:
    ctx->pc = 0x8004D838u;
    // 8004D838: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004D83C:
    ctx->pc = 0x8004D83Cu;
    // 8004D83C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004D840:
    ctx->pc = 0x8004D840u;
    // 8004D840: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004D844:
    ctx->pc = 0x8004D844u;
    // 8004D844: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8004D848:
    ctx->pc = 0x8004D848u;
    // 8004D848: bl      0x8025C4B4
    {
            ctx->lr = 0x8004D84Cu;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_8004D84C:
    ctx->pc = 0x8004D84Cu;
    ctx->downcount -= 7;
    // 8004D84C: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D850:
    ctx->pc = 0x8004D850u;
    // 8004D850: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004D854:
    ctx->pc = 0x8004D854u;
    // 8004D854: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004D858:
    ctx->pc = 0x8004D858u;
    // 8004D858: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004D85C:
    ctx->pc = 0x8004D85Cu;
    // 8004D85C: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004D860:
    ctx->pc = 0x8004D860u;
    // 8004D860: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8004D864:
    ctx->pc = 0x8004D864u;
    // 8004D864: bl      0x8025C574
    {
            ctx->lr = 0x8004D868u;
            ctx->pc = 0x8025C574u;
            return;
    }

label_8004D868:
    ctx->pc = 0x8004D868u;
    ctx->downcount -= 22;
    // 8004D868: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8004D86C:
    ctx->pc = 0x8004D86Cu;
    // 8004D86C: stb     r0, -25688(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25688);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004D870:
    ctx->pc = 0x8004D870u;
    // 8004D870: lwz     r3, -25620(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25620);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D874:
    ctx->pc = 0x8004D874u;
    // 8004D874: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8004D878:
    ctx->pc = 0x8004D878u;
    // 8004D878: stw     r0, -25620(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25620);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004D87C:
    ctx->pc = 0x8004D87Cu;
    // 8004D87C: lwz     r3, -25624(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25624);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D880:
    ctx->pc = 0x8004D880u;
    // 8004D880: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8004D884:
    ctx->pc = 0x8004D884u;
    // 8004D884: stw     r0, -25624(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25624);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004D888:
    ctx->pc = 0x8004D888u;
    // 8004D888: lwz     r3, -25628(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25628);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D88C:
    ctx->pc = 0x8004D88Cu;
    // 8004D88C: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8004D890:
    ctx->pc = 0x8004D890u;
    // 8004D890: stw     r0, -25628(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25628);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004D894:
    ctx->pc = 0x8004D894u;
    // 8004D894: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D898:
    ctx->pc = 0x8004D898u;
    // 8004D898: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8004D89C:
    ctx->pc = 0x8004D89Cu;
    // 8004D89C: stw     r0, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004D8A0:
    ctx->pc = 0x8004D8A0u;
    // 8004D8A0: lbz     r3, -25630(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25630);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8004D8A4:
    ctx->pc = 0x8004D8A4u;
    // 8004D8A4: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8004D8A8:
    ctx->pc = 0x8004D8A8u;
    // 8004D8A8: stb     r0, -25630(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25630);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004D8AC:
    ctx->pc = 0x8004D8ACu;
    // 8004D8AC: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004D8B0:
    ctx->pc = 0x8004D8B0u;
    // 8004D8B0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004D8B4:
    ctx->pc = 0x8004D8B4u;
    // 8004D8B4: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8004D8B8:
    ctx->pc = 0x8004D8B8u;
    // 8004D8B8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004D8BC:
    ctx->pc = 0x8004D8BCu;
    ctx->downcount -= 18;
    // 8004D8BC: stwu     r1, -48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-48);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004D8C0:
    ctx->pc = 0x8004D8C0u;
    // 8004D8C0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004D8C4:
    ctx->pc = 0x8004D8C4u;
    // 8004D8C4: stw     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004D8C8:
    ctx->pc = 0x8004D8C8u;
    // 8004D8C8: lis     r3, -32724
    ctx->gpr[3] = ((u32)(s32)(-32724) << 16);

label_8004D8CC:
    ctx->pc = 0x8004D8CCu;
    // 8004D8CC: addi    r4, r3, 10128
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(10128);

label_8004D8D0:
    ctx->pc = 0x8004D8D0u;
    // 8004D8D0: lwz     r3, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D8D4:
    ctx->pc = 0x8004D8D4u;
    // 8004D8D4: lwz     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004D8D8:
    ctx->pc = 0x8004D8D8u;
    // 8004D8D8: stw     r3, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8004D8DC:
    ctx->pc = 0x8004D8DCu;
    // 8004D8DC: stw     r0, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004D8E0:
    ctx->pc = 0x8004D8E0u;
    // 8004D8E0: lwz     r3, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D8E4:
    ctx->pc = 0x8004D8E4u;
    // 8004D8E4: lwz     r0, 12(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004D8E8:
    ctx->pc = 0x8004D8E8u;
    // 8004D8E8: stw     r3, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8004D8EC:
    ctx->pc = 0x8004D8ECu;
    // 8004D8EC: stw     r0, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004D8F0:
    ctx->pc = 0x8004D8F0u;
    // 8004D8F0: lwz     r3, 16(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D8F4:
    ctx->pc = 0x8004D8F4u;
    // 8004D8F4: lwz     r0, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004D8F8:
    ctx->pc = 0x8004D8F8u;
    // 8004D8F8: stw     r3, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8004D8FC:
    ctx->pc = 0x8004D8FCu;
    // 8004D8FC: stw     r0, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004D900:
    ctx->pc = 0x8004D900u;
    // 8004D900: bl      0x8006C854
    {
            ctx->lr = 0x8004D904u;
            ctx->pc = 0x8006C854u;
            return;
    }

label_8004D904:
    ctx->pc = 0x8004D904u;
    ctx->downcount -= 7;
    // 8004D904: lfs     f0, -31260(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004D904u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31260);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004D908:
    ctx->pc = 0x8004D908u;
    // 8004D908: fmuls   f0, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8004D908u)) return;
    ppc_fmuls(ctx, 0, 0, 1);

label_8004D90C:
    ctx->pc = 0x8004D90Cu;
    // 8004D90C: stfs     f0, 20(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004D90Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004D910:
    ctx->pc = 0x8004D910u;
    // 8004D910: stfs     f0, 40(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004D910u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004D914:
    ctx->pc = 0x8004D914u;
    // 8004D914: lwz     r4, -25600(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25600);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004D918:
    ctx->pc = 0x8004D918u;
    // 8004D918: cmpwi   r4, 0
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004D91C:
    ctx->pc = 0x8004D91Cu;
    // 8004D91C: bc    4, 1, 0x8004D938
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8004D938;
        }
    }

label_8004D920:
    ctx->pc = 0x8004D920u;
    ctx->downcount -= 5;
    // 8004D920: lwz     r3, -25612(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25612);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D924:
    ctx->pc = 0x8004D924u;
    // 8004D924: addi    r4, r4, -1
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-1);

label_8004D928:
    ctx->pc = 0x8004D928u;
    // 8004D928: lwz     r5, -25596(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25596);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8004D92C:
    ctx->pc = 0x8004D92Cu;
    // 8004D92C: addi    r5, r5, 1
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(1);

label_8004D930:
    ctx->pc = 0x8004D930u;
    // 8004D930: bl      0x8025BF28
    {
            ctx->lr = 0x8004D934u;
            ctx->pc = 0x8025BF28u;
            return;
    }

label_8004D934:
    ctx->pc = 0x8004D934u;
    ctx->downcount -= 1;
    // 8004D934: b       0x8004D948
    {
            goto label_8004D948;
    }

label_8004D938:
    ctx->pc = 0x8004D938u;
    ctx->downcount -= 4;
    // 8004D938: lwz     r3, -25612(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25612);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D93C:
    ctx->pc = 0x8004D93Cu;
    // 8004D93C: lwz     r5, -25596(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25596);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8004D940:
    ctx->pc = 0x8004D940u;
    // 8004D940: addi    r5, r5, 1
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(1);

label_8004D944:
    ctx->pc = 0x8004D944u;
    // 8004D944: bl      0x8025BF28
    {
            ctx->lr = 0x8004D948u;
            ctx->pc = 0x8025BF28u;
            return;
    }

label_8004D948:
    ctx->pc = 0x8004D948u;
    ctx->downcount -= 4;
    // 8004D948: lwz     r3, -25612(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25612);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D94C:
    ctx->pc = 0x8004D94Cu;
    // 8004D94C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004D950:
    ctx->pc = 0x8004D950u;
    // 8004D950: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004D954:
    ctx->pc = 0x8004D954u;
    // 8004D954: bl      0x8025BD54
    {
            ctx->lr = 0x8004D958u;
            ctx->pc = 0x8025BD54u;
            return;
    }

label_8004D958:
    ctx->pc = 0x8004D958u;
    ctx->downcount -= 4;
    // 8004D958: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8004D95C:
    ctx->pc = 0x8004D95Cu;
    // 8004D95C: addi    r4, r1, 20
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(20);

label_8004D960:
    ctx->pc = 0x8004D960u;
    // 8004D960: li      r5, -3
    ctx->gpr[5] = (u32)(s32)(-3);

label_8004D964:
    ctx->pc = 0x8004D964u;
    // 8004D964: bl      0x8025BBF4
    {
            ctx->lr = 0x8004D968u;
            ctx->pc = 0x8025BBF4u;
            return;
    }

label_8004D968:
    ctx->pc = 0x8004D968u;
    ctx->downcount -= 12;
    // 8004D968: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8004D96C:
    ctx->pc = 0x8004D96Cu;
    // 8004D96C: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004D970:
    ctx->pc = 0x8004D970u;
    // 8004D970: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004D974:
    ctx->pc = 0x8004D974u;
    // 8004D974: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D978:
    ctx->pc = 0x8004D978u;
    // 8004D978: lwz     r4, -25612(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25612);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004D97C:
    ctx->pc = 0x8004D97Cu;
    // 8004D97C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004D980:
    ctx->pc = 0x8004D980u;
    // 8004D980: li      r6, 3
    ctx->gpr[6] = (u32)(s32)(3);

label_8004D984:
    ctx->pc = 0x8004D984u;
    // 8004D984: li      r7, 2
    ctx->gpr[7] = (u32)(s32)(2);

label_8004D988:
    ctx->pc = 0x8004D988u;
    // 8004D988: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8004D98C:
    ctx->pc = 0x8004D98Cu;
    // 8004D98C: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_8004D990:
    ctx->pc = 0x8004D990u;
    // 8004D990: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_8004D994:
    ctx->pc = 0x8004D994u;
    // 8004D994: bl      0x8025BB58
    {
            ctx->lr = 0x8004D998u;
            ctx->pc = 0x8025BB58u;
            return;
    }

label_8004D998:
    ctx->pc = 0x8004D998u;
    ctx->downcount -= 2;
    // 8004D998: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_8004D99C:
    ctx->pc = 0x8004D99Cu;
    // 8004D99C: bl      0x8006C7C8
    {
            ctx->lr = 0x8004D9A0u;
            ctx->pc = 0x8006C7C8u;
            return;
    }

label_8004D9A0:
    ctx->pc = 0x8004D9A0u;
    ctx->downcount -= 5;
    // 8004D9A0: lwz     r3, -25596(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25596);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D9A4:
    ctx->pc = 0x8004D9A4u;
    // 8004D9A4: addi    r5, r3, 1
    ctx->gpr[5] = ctx->gpr[3] + (u32)(s32)(1);

label_8004D9A8:
    ctx->pc = 0x8004D9A8u;
    // 8004D9A8: lwz     r4, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004D9AC:
    ctx->pc = 0x8004D9ACu;
    // 8004D9AC: cmplwi  r4, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004D9B0:
    ctx->pc = 0x8004D9B0u;
    // 8004D9B0: bc    12, 2, 0x8004D9D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004D9D8;
        }
    }

label_8004D9B4:
    ctx->pc = 0x8004D9B4u;
    ctx->downcount -= 4;
    // 8004D9B4: addi    r3, r4, 32
    ctx->gpr[3] = ctx->gpr[4] + (u32)(s32)(32);

label_8004D9B8:
    ctx->pc = 0x8004D9B8u;
    // 8004D9B8: lbz     r0, 72(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(72);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8004D9BC:
    ctx->pc = 0x8004D9BCu;
    // 8004D9BC: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004D9C0:
    ctx->pc = 0x8004D9C0u;
    // 8004D9C0: bc    12, 2, 0x8004D9D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004D9D0;
        }
    }

label_8004D9C4:
    ctx->pc = 0x8004D9C4u;
    ctx->downcount -= 2;
    // 8004D9C4: lwz     r4, 64(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(64);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004D9C8:
    ctx->pc = 0x8004D9C8u;
    // 8004D9C8: bl      0x8025B0B8
    {
            ctx->lr = 0x8004D9CCu;
            ctx->pc = 0x8025B0B8u;
            return;
    }

label_8004D9CC:
    ctx->pc = 0x8004D9CCu;
    ctx->downcount -= 1;
    // 8004D9CC: b       0x8004D9D8
    {
            goto label_8004D9D8;
    }

label_8004D9D0:
    ctx->pc = 0x8004D9D0u;
    ctx->downcount -= 2;
    // 8004D9D0: or   r4, r5, r5
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8004D9D4:
    ctx->pc = 0x8004D9D4u;
    // 8004D9D4: bl      0x8025B260
    {
            ctx->lr = 0x8004D9D8u;
            ctx->pc = 0x8025B260u;
            return;
    }

label_8004D9D8:
    ctx->pc = 0x8004D9D8u;
    ctx->downcount -= 5;
    // 8004D9D8: lis     r3, -32710
    ctx->gpr[3] = ((u32)(s32)(-32710) << 16);

label_8004D9DC:
    ctx->pc = 0x8004D9DCu;
    // 8004D9DC: addi    r3, r3, -32384
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-32384);

label_8004D9E0:
    ctx->pc = 0x8004D9E0u;
    // 8004D9E0: lwz     r4, -25608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004D9E4:
    ctx->pc = 0x8004D9E4u;
    // 8004D9E4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004D9E8:
    ctx->pc = 0x8004D9E8u;
    // 8004D9E8: bl      0x8025DAD0
    {
            ctx->lr = 0x8004D9ECu;
            ctx->pc = 0x8025DAD0u;
            return;
    }

label_8004D9EC:
    ctx->pc = 0x8004D9ECu;
    ctx->downcount -= 7;
    // 8004D9EC: lwz     r3, -25600(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25600);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004D9F0:
    ctx->pc = 0x8004D9F0u;
    // 8004D9F0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004D9F4:
    ctx->pc = 0x8004D9F4u;
    // 8004D9F4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004D9F8:
    ctx->pc = 0x8004D9F8u;
    // 8004D9F8: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004D9FC:
    ctx->pc = 0x8004D9FCu;
    // 8004D9FC: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004DA00:
    ctx->pc = 0x8004DA00u;
    // 8004DA00: lwz     r8, -25608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25608);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8004DA04:
    ctx->pc = 0x8004DA04u;
    // 8004DA04: bl      0x80258880
    {
            ctx->lr = 0x8004DA08u;
            ctx->pc = 0x80258880u;
            return;
    }

label_8004DA08:
    ctx->pc = 0x8004DA08u;
    ctx->downcount -= 5;
    // 8004DA08: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004DA0C:
    ctx->pc = 0x8004DA0Cu;
    // 8004DA0C: lwz     r4, -25600(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25600);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004DA10:
    ctx->pc = 0x8004DA10u;
    // 8004DA10: lwz     r5, -25596(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25596);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8004DA14:
    ctx->pc = 0x8004DA14u;
    // 8004DA14: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_8004DA18:
    ctx->pc = 0x8004DA18u;
    // 8004DA18: bl      0x8025CA34
    {
            ctx->lr = 0x8004DA1Cu;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_8004DA1C:
    ctx->pc = 0x8004DA1Cu;
    ctx->downcount -= 6;
    // 8004DA1C: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004DA20:
    ctx->pc = 0x8004DA20u;
    // 8004DA20: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_8004DA24:
    ctx->pc = 0x8004DA24u;
    // 8004DA24: li      r5, 15
    ctx->gpr[5] = (u32)(s32)(15);

label_8004DA28:
    ctx->pc = 0x8004DA28u;
    // 8004DA28: li      r6, 15
    ctx->gpr[6] = (u32)(s32)(15);

label_8004DA2C:
    ctx->pc = 0x8004DA2Cu;
    // 8004DA2C: li      r7, 8
    ctx->gpr[7] = (u32)(s32)(8);

label_8004DA30:
    ctx->pc = 0x8004DA30u;
    // 8004DA30: bl      0x8025C3B0
    {
            ctx->lr = 0x8004DA34u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_8004DA34:
    ctx->pc = 0x8004DA34u;
    ctx->downcount -= 4;
    // 8004DA34: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004DA38:
    ctx->pc = 0x8004DA38u;
    // 8004DA38: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004DA3C:
    ctx->pc = 0x8004DA3Cu;
    // 8004DA3C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004DA40:
    ctx->pc = 0x8004DA40u;
    // 8004DA40: bl      0x8025C868
    {
            ctx->lr = 0x8004DA44u;
            ctx->pc = 0x8025C868u;
            return;
    }

label_8004DA44:
    ctx->pc = 0x8004DA44u;
    ctx->downcount -= 6;
    // 8004DA44: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004DA48:
    ctx->pc = 0x8004DA48u;
    // 8004DA48: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_8004DA4C:
    ctx->pc = 0x8004DA4Cu;
    // 8004DA4C: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_8004DA50:
    ctx->pc = 0x8004DA50u;
    // 8004DA50: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_8004DA54:
    ctx->pc = 0x8004DA54u;
    // 8004DA54: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004DA58:
    ctx->pc = 0x8004DA58u;
    // 8004DA58: bl      0x8025C430
    {
            ctx->lr = 0x8004DA5Cu;
            ctx->pc = 0x8025C430u;
            return;
    }

label_8004DA5C:
    ctx->pc = 0x8004DA5Cu;
    ctx->downcount -= 7;
    // 8004DA5C: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004DA60:
    ctx->pc = 0x8004DA60u;
    // 8004DA60: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004DA64:
    ctx->pc = 0x8004DA64u;
    // 8004DA64: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004DA68:
    ctx->pc = 0x8004DA68u;
    // 8004DA68: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004DA6C:
    ctx->pc = 0x8004DA6Cu;
    // 8004DA6C: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004DA70:
    ctx->pc = 0x8004DA70u;
    // 8004DA70: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_8004DA74:
    ctx->pc = 0x8004DA74u;
    // 8004DA74: bl      0x8025C4B4
    {
            ctx->lr = 0x8004DA78u;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_8004DA78:
    ctx->pc = 0x8004DA78u;
    ctx->downcount -= 7;
    // 8004DA78: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004DA7C:
    ctx->pc = 0x8004DA7Cu;
    // 8004DA7C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004DA80:
    ctx->pc = 0x8004DA80u;
    // 8004DA80: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004DA84:
    ctx->pc = 0x8004DA84u;
    // 8004DA84: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004DA88:
    ctx->pc = 0x8004DA88u;
    // 8004DA88: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004DA8C:
    ctx->pc = 0x8004DA8Cu;
    // 8004DA8C: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8004DA90:
    ctx->pc = 0x8004DA90u;
    // 8004DA90: bl      0x8025C574
    {
            ctx->lr = 0x8004DA94u;
            ctx->pc = 0x8025C574u;
            return;
    }

label_8004DA94:
    ctx->pc = 0x8004DA94u;
    ctx->downcount -= 2;
    // 8004DA94: lwz     r3, -25596(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25596);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004DA98:
    ctx->pc = 0x8004DA98u;
    // 8004DA98: bl      0x8006C8D4
    {
            ctx->lr = 0x8004DA9Cu;
            ctx->pc = 0x8006C8D4u;
            return;
    }

label_8004DA9C:
    ctx->pc = 0x8004DA9Cu;
    ctx->downcount -= 29;
    // 8004DA9C: lwz     r3, -25612(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25612);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004DAA0:
    ctx->pc = 0x8004DAA0u;
    // 8004DAA0: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8004DAA4:
    ctx->pc = 0x8004DAA4u;
    // 8004DAA4: stw     r0, -25612(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25612);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004DAA8:
    ctx->pc = 0x8004DAA8u;
    // 8004DAA8: lwz     r3, -25608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004DAAC:
    ctx->pc = 0x8004DAACu;
    // 8004DAAC: addi    r0, r3, 3
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(3);

label_8004DAB0:
    ctx->pc = 0x8004DAB0u;
    // 8004DAB0: stw     r0, -25608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25608);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004DAB4:
    ctx->pc = 0x8004DAB4u;
    // 8004DAB4: lwz     r3, -25600(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25600);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004DAB8:
    ctx->pc = 0x8004DAB8u;
    // 8004DAB8: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8004DABC:
    ctx->pc = 0x8004DABCu;
    // 8004DABC: stw     r0, -25600(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25600);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004DAC0:
    ctx->pc = 0x8004DAC0u;
    // 8004DAC0: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004DAC4:
    ctx->pc = 0x8004DAC4u;
    // 8004DAC4: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8004DAC8:
    ctx->pc = 0x8004DAC8u;
    // 8004DAC8: stw     r0, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004DACC:
    ctx->pc = 0x8004DACCu;
    // 8004DACC: lwz     r3, -25596(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25596);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004DAD0:
    ctx->pc = 0x8004DAD0u;
    // 8004DAD0: addi    r0, r3, 2
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(2);

label_8004DAD4:
    ctx->pc = 0x8004DAD4u;
    // 8004DAD4: stw     r0, -25596(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25596);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004DAD8:
    ctx->pc = 0x8004DAD8u;
    // 8004DAD8: lbz     r3, -25630(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25630);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8004DADC:
    ctx->pc = 0x8004DADCu;
    // 8004DADC: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8004DAE0:
    ctx->pc = 0x8004DAE0u;
    // 8004DAE0: stb     r0, -25630(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25630);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004DAE4:
    ctx->pc = 0x8004DAE4u;
    // 8004DAE4: lbz     r3, -25631(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25631);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8004DAE8:
    ctx->pc = 0x8004DAE8u;
    // 8004DAE8: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8004DAEC:
    ctx->pc = 0x8004DAECu;
    // 8004DAEC: stb     r0, -25631(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25631);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004DAF0:
    ctx->pc = 0x8004DAF0u;
    // 8004DAF0: lbz     r3, -25632(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25632);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8004DAF4:
    ctx->pc = 0x8004DAF4u;
    // 8004DAF4: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8004DAF8:
    ctx->pc = 0x8004DAF8u;
    // 8004DAF8: stb     r0, -25632(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25632);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004DAFC:
    ctx->pc = 0x8004DAFCu;
    // 8004DAFC: lwz     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004DB00:
    ctx->pc = 0x8004DB00u;
    // 8004DB00: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004DB04:
    ctx->pc = 0x8004DB04u;
    // 8004DB04: addi    r1, r1, 48
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(48);

label_8004DB08:
    ctx->pc = 0x8004DB08u;
    // 8004DB08: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004DB0C:
    ctx->pc = 0x8004DB0Cu;
    ctx->downcount -= 5;
    // 8004DB0C: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004DB10:
    ctx->pc = 0x8004DB10u;
    // 8004DB10: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004DB14:
    ctx->pc = 0x8004DB14u;
    // 8004DB14: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004DB18:
    ctx->pc = 0x8004DB18u;
    // 8004DB18: lwz     r3, -25596(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25596);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004DB1C:
    ctx->pc = 0x8004DB1Cu;
    // 8004DB1C: bl      0x8006C940
    {
            ctx->lr = 0x8004DB20u;
            ctx->pc = 0x8006C940u;
            return;
    }

label_8004DB20:
    ctx->pc = 0x8004DB20u;
    ctx->downcount -= 7;
    // 8004DB20: lwz     r3, -25600(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25600);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004DB24:
    ctx->pc = 0x8004DB24u;
    // 8004DB24: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004DB28:
    ctx->pc = 0x8004DB28u;
    // 8004DB28: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004DB2C:
    ctx->pc = 0x8004DB2Cu;
    // 8004DB2C: li      r6, 36
    ctx->gpr[6] = (u32)(s32)(36);

label_8004DB30:
    ctx->pc = 0x8004DB30u;
    // 8004DB30: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004DB34:
    ctx->pc = 0x8004DB34u;
    // 8004DB34: li      r8, 125
    ctx->gpr[8] = (u32)(s32)(125);

label_8004DB38:
    ctx->pc = 0x8004DB38u;
    // 8004DB38: bl      0x80258880
    {
            ctx->lr = 0x8004DB3Cu;
            ctx->pc = 0x80258880u;
            return;
    }

label_8004DB3C:
    ctx->pc = 0x8004DB3Cu;
    ctx->downcount -= 2;
    // 8004DB3C: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004DB40:
    ctx->pc = 0x8004DB40u;
    // 8004DB40: bl      0x8025C08C
    {
            ctx->lr = 0x8004DB44u;
            ctx->pc = 0x8025C08Cu;
            return;
    }

label_8004DB44:
    ctx->pc = 0x8004DB44u;
    ctx->downcount -= 3;
    // 8004DB44: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004DB48:
    ctx->pc = 0x8004DB48u;
    // 8004DB48: li      r4, 6
    ctx->gpr[4] = (u32)(s32)(6);

label_8004DB4C:
    ctx->pc = 0x8004DB4Cu;
    // 8004DB4C: bl      0x8025C790
    {
            ctx->lr = 0x8004DB50u;
            ctx->pc = 0x8025C790u;
            return;
    }

label_8004DB50:
    ctx->pc = 0x8004DB50u;
    ctx->downcount -= 5;
    // 8004DB50: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004DB54:
    ctx->pc = 0x8004DB54u;
    // 8004DB54: lwz     r4, -25600(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25600);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004DB58:
    ctx->pc = 0x8004DB58u;
    // 8004DB58: lwz     r5, -25596(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25596);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8004DB5C:
    ctx->pc = 0x8004DB5Cu;
    // 8004DB5C: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_8004DB60:
    ctx->pc = 0x8004DB60u;
    // 8004DB60: bl      0x8025CA34
    {
            ctx->lr = 0x8004DB64u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_8004DB64:
    ctx->pc = 0x8004DB64u;
    ctx->downcount -= 6;
    // 8004DB64: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004DB68:
    ctx->pc = 0x8004DB68u;
    // 8004DB68: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_8004DB6C:
    ctx->pc = 0x8004DB6Cu;
    // 8004DB6C: li      r5, 8
    ctx->gpr[5] = (u32)(s32)(8);

label_8004DB70:
    ctx->pc = 0x8004DB70u;
    // 8004DB70: li      r6, 14
    ctx->gpr[6] = (u32)(s32)(14);

label_8004DB74:
    ctx->pc = 0x8004DB74u;
    // 8004DB74: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004DB78:
    ctx->pc = 0x8004DB78u;
    // 8004DB78: bl      0x8025C3B0
    {
            ctx->lr = 0x8004DB7Cu;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_8004DB7C:
    ctx->pc = 0x8004DB7Cu;
    ctx->downcount -= 6;
    // 8004DB7C: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004DB80:
    ctx->pc = 0x8004DB80u;
    // 8004DB80: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_8004DB84:
    ctx->pc = 0x8004DB84u;
    // 8004DB84: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_8004DB88:
    ctx->pc = 0x8004DB88u;
    // 8004DB88: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_8004DB8C:
    ctx->pc = 0x8004DB8Cu;
    // 8004DB8C: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004DB90:
    ctx->pc = 0x8004DB90u;
    // 8004DB90: bl      0x8025C430
    {
            ctx->lr = 0x8004DB94u;
            ctx->pc = 0x8025C430u;
            return;
    }

label_8004DB94:
    ctx->pc = 0x8004DB94u;
    ctx->downcount -= 4;
    // 8004DB94: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004DB98:
    ctx->pc = 0x8004DB98u;
    // 8004DB98: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004DB9C:
    ctx->pc = 0x8004DB9Cu;
    // 8004DB9C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004DBA0:
    ctx->pc = 0x8004DBA0u;
    // 8004DBA0: bl      0x8025C868
    {
            ctx->lr = 0x8004DBA4u;
            ctx->pc = 0x8025C868u;
            return;
    }

label_8004DBA4:
    ctx->pc = 0x8004DBA4u;
    ctx->downcount -= 7;
    // 8004DBA4: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004DBA8:
    ctx->pc = 0x8004DBA8u;
    // 8004DBA8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004DBAC:
    ctx->pc = 0x8004DBACu;
    // 8004DBAC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004DBB0:
    ctx->pc = 0x8004DBB0u;
    // 8004DBB0: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004DBB4:
    ctx->pc = 0x8004DBB4u;
    // 8004DBB4: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004DBB8:
    ctx->pc = 0x8004DBB8u;
    // 8004DBB8: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8004DBBC:
    ctx->pc = 0x8004DBBCu;
    // 8004DBBC: bl      0x8025C4B4
    {
            ctx->lr = 0x8004DBC0u;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_8004DBC0:
    ctx->pc = 0x8004DBC0u;
    ctx->downcount -= 7;
    // 8004DBC0: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004DBC4:
    ctx->pc = 0x8004DBC4u;
    // 8004DBC4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004DBC8:
    ctx->pc = 0x8004DBC8u;
    // 8004DBC8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004DBCC:
    ctx->pc = 0x8004DBCCu;
    // 8004DBCC: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004DBD0:
    ctx->pc = 0x8004DBD0u;
    // 8004DBD0: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004DBD4:
    ctx->pc = 0x8004DBD4u;
    // 8004DBD4: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8004DBD8:
    ctx->pc = 0x8004DBD8u;
    // 8004DBD8: bl      0x8025C574
    {
            ctx->lr = 0x8004DBDCu;
            ctx->pc = 0x8025C574u;
            return;
    }

label_8004DBDC:
    ctx->pc = 0x8004DBDCu;
    ctx->downcount -= 24;
    // 8004DBDC: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8004DBE0:
    ctx->pc = 0x8004DBE0u;
    // 8004DBE0: stb     r0, -25688(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25688);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004DBE4:
    ctx->pc = 0x8004DBE4u;
    // 8004DBE4: lwz     r3, -25600(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25600);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004DBE8:
    ctx->pc = 0x8004DBE8u;
    // 8004DBE8: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8004DBEC:
    ctx->pc = 0x8004DBECu;
    // 8004DBEC: stw     r0, -25600(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25600);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004DBF0:
    ctx->pc = 0x8004DBF0u;
    // 8004DBF0: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004DBF4:
    ctx->pc = 0x8004DBF4u;
    // 8004DBF4: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8004DBF8:
    ctx->pc = 0x8004DBF8u;
    // 8004DBF8: stw     r0, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004DBFC:
    ctx->pc = 0x8004DBFCu;
    // 8004DBFC: lwz     r3, -25596(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25596);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004DC00:
    ctx->pc = 0x8004DC00u;
    // 8004DC00: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8004DC04:
    ctx->pc = 0x8004DC04u;
    // 8004DC04: stw     r0, -25596(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25596);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004DC08:
    ctx->pc = 0x8004DC08u;
    // 8004DC08: li      r0, 39
    ctx->gpr[0] = (u32)(s32)(39);

label_8004DC0C:
    ctx->pc = 0x8004DC0Cu;
    // 8004DC0C: stw     r0, -25604(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25604);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004DC10:
    ctx->pc = 0x8004DC10u;
    // 8004DC10: lbz     r3, -25630(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25630);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8004DC14:
    ctx->pc = 0x8004DC14u;
    // 8004DC14: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8004DC18:
    ctx->pc = 0x8004DC18u;
    // 8004DC18: stb     r0, -25630(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25630);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004DC1C:
    ctx->pc = 0x8004DC1Cu;
    // 8004DC1C: lbz     r3, -25631(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25631);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8004DC20:
    ctx->pc = 0x8004DC20u;
    // 8004DC20: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8004DC24:
    ctx->pc = 0x8004DC24u;
    // 8004DC24: stb     r0, -25631(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25631);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004DC28:
    ctx->pc = 0x8004DC28u;
    // 8004DC28: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004DC2C:
    ctx->pc = 0x8004DC2Cu;
    // 8004DC2C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004DC30:
    ctx->pc = 0x8004DC30u;
    // 8004DC30: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8004DC34:
    ctx->pc = 0x8004DC34u;
    // 8004DC34: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004DC38:
    ctx->pc = 0x8004DC38u;
    ctx->downcount -= 38;
    // 8004DC38: stwu     r1, -336(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-336);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004DC3C:
    ctx->pc = 0x8004DC3Cu;
    // 8004DC3C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004DC40:
    ctx->pc = 0x8004DC40u;
    // 8004DC40: stw     r0, 340(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(340);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004DC44:
    ctx->pc = 0x8004DC44u;
    // 8004DC44: stfd     f31, 320(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004DC44u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(320);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_8004DC48:
    ctx->pc = 0x8004DC48u;
    // 8004DC48: psq_st   f31, 328(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8004DC48u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(328);
        ppc_psq_store_inline(ctx, 31u, ea, false, 0u, false, 0x8004DC48u);
        if (ctx->exception) return;
    }

label_8004DC4C:
    ctx->pc = 0x8004DC4Cu;
    // 8004DC4C: stw     r31, 316(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(316);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8004DC50:
    ctx->pc = 0x8004DC50u;
    // 8004DC50: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004DC54:
    ctx->pc = 0x8004DC54u;
    // 8004DC54: lis     r3, -32724
    ctx->gpr[3] = ((u32)(s32)(-32724) << 16);

label_8004DC58:
    ctx->pc = 0x8004DC58u;
    // 8004DC58: addi    r4, r3, 10056
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(10056);

label_8004DC5C:
    ctx->pc = 0x8004DC5Cu;
    // 8004DC5C: lwz     r3, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004DC60:
    ctx->pc = 0x8004DC60u;
    // 8004DC60: lwz     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004DC64:
    ctx->pc = 0x8004DC64u;
    // 8004DC64: stw     r3, 76(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(76);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8004DC68:
    ctx->pc = 0x8004DC68u;
    // 8004DC68: stw     r0, 80(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004DC6C:
    ctx->pc = 0x8004DC6Cu;
    // 8004DC6C: lwz     r3, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004DC70:
    ctx->pc = 0x8004DC70u;
    // 8004DC70: lwz     r0, 12(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004DC74:
    ctx->pc = 0x8004DC74u;
    // 8004DC74: stw     r3, 84(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8004DC78:
    ctx->pc = 0x8004DC78u;
    // 8004DC78: stw     r0, 88(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004DC7C:
    ctx->pc = 0x8004DC7Cu;
    // 8004DC7C: lwz     r3, 16(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004DC80:
    ctx->pc = 0x8004DC80u;
    // 8004DC80: lwz     r0, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004DC84:
    ctx->pc = 0x8004DC84u;
    // 8004DC84: stw     r3, 92(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8004DC88:
    ctx->pc = 0x8004DC88u;
    // 8004DC88: stw     r0, 96(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004DC8C:
    ctx->pc = 0x8004DC8Cu;
    // 8004DC8C: lis     r3, -32724
    ctx->gpr[3] = ((u32)(s32)(-32724) << 16);

label_8004DC90:
    ctx->pc = 0x8004DC90u;
    // 8004DC90: addi    r4, r3, 10080
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(10080);

label_8004DC94:
    ctx->pc = 0x8004DC94u;
    // 8004DC94: lwz     r3, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004DC98:
    ctx->pc = 0x8004DC98u;
    // 8004DC98: lwz     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004DC9C:
    ctx->pc = 0x8004DC9Cu;
    // 8004DC9C: stw     r3, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8004DCA0:
    ctx->pc = 0x8004DCA0u;
    // 8004DCA0: stw     r0, 56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004DCA4:
    ctx->pc = 0x8004DCA4u;
    // 8004DCA4: lwz     r3, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004DCA8:
    ctx->pc = 0x8004DCA8u;
    // 8004DCA8: lwz     r0, 12(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004DCAC:
    ctx->pc = 0x8004DCACu;
    // 8004DCAC: stw     r3, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8004DCB0:
    ctx->pc = 0x8004DCB0u;
    // 8004DCB0: stw     r0, 64(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004DCB4:
    ctx->pc = 0x8004DCB4u;
    // 8004DCB4: lwz     r3, 16(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004DCB8:
    ctx->pc = 0x8004DCB8u;
    // 8004DCB8: lwz     r0, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004DCBC:
    ctx->pc = 0x8004DCBCu;
    // 8004DCBC: stw     r3, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8004DCC0:
    ctx->pc = 0x8004DCC0u;
    // 8004DCC0: stw     r0, 72(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004DCC4:
    ctx->pc = 0x8004DCC4u;
    // 8004DCC4: lwz     r4, 36(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(36);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004DCC8:
    ctx->pc = 0x8004DCC8u;
    // 8004DCC8: cmplwi  r4, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004DCCC:
    ctx->pc = 0x8004DCCCu;
    // 8004DCCC: bc    12, 2, 0x8004DCF8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004DCF8;
        }
    }

label_8004DCD0:
    ctx->pc = 0x8004DCD0u;
    ctx->downcount -= 4;
    // 8004DCD0: addi    r3, r4, 32
    ctx->gpr[3] = ctx->gpr[4] + (u32)(s32)(32);

label_8004DCD4:
    ctx->pc = 0x8004DCD4u;
    // 8004DCD4: lbz     r0, 72(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(72);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8004DCD8:
    ctx->pc = 0x8004DCD8u;
    // 8004DCD8: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004DCDC:
    ctx->pc = 0x8004DCDCu;
    // 8004DCDC: bc    12, 2, 0x8004DCF0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004DCF0;
        }
    }

label_8004DCE0:
    ctx->pc = 0x8004DCE0u;
    ctx->downcount -= 3;
    // 8004DCE0: lwz     r4, 64(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(64);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004DCE4:
    ctx->pc = 0x8004DCE4u;
    // 8004DCE4: li      r5, 2
    ctx->gpr[5] = (u32)(s32)(2);

label_8004DCE8:
    ctx->pc = 0x8004DCE8u;
    // 8004DCE8: bl      0x8025B0B8
    {
            ctx->lr = 0x8004DCECu;
            ctx->pc = 0x8025B0B8u;
            return;
    }

label_8004DCEC:
    ctx->pc = 0x8004DCECu;
    ctx->downcount -= 1;
    // 8004DCEC: b       0x8004DCF8
    {
            goto label_8004DCF8;
    }

label_8004DCF0:
    ctx->pc = 0x8004DCF0u;
    ctx->downcount -= 2;
    // 8004DCF0: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_8004DCF4:
    ctx->pc = 0x8004DCF4u;
    // 8004DCF4: bl      0x8025B260
    {
            ctx->lr = 0x8004DCF8u;
            ctx->pc = 0x8025B260u;
            return;
    }

label_8004DCF8:
    ctx->pc = 0x8004DCF8u;
    ctx->downcount -= 7;
    // 8004DCF8: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_8004DCFC:
    ctx->pc = 0x8004DCFCu;
    // 8004DCFC: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8004DD00:
    ctx->pc = 0x8004DD00u;
    // 8004DD00: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_8004DD04:
    ctx->pc = 0x8004DD04u;
    // 8004DD04: li      r6, 60
    ctx->gpr[6] = (u32)(s32)(60);

label_8004DD08:
    ctx->pc = 0x8004DD08u;
    // 8004DD08: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004DD0C:
    ctx->pc = 0x8004DD0Cu;
    // 8004DD0C: li      r8, 125
    ctx->gpr[8] = (u32)(s32)(125);

label_8004DD10:
    ctx->pc = 0x8004DD10u;
    // 8004DD10: bl      0x80258880
    {
            ctx->lr = 0x8004DD14u;
            ctx->pc = 0x80258880u;
            return;
    }

label_8004DD14:
    ctx->pc = 0x8004DD14u;
    ctx->downcount -= 3;
    // 8004DD14: addi    r3, r1, 40
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(40);

label_8004DD18:
    ctx->pc = 0x8004DD18u;
    // 8004DD18: addi    r4, r1, 36
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(36);

label_8004DD1C:
    ctx->pc = 0x8004DD1Cu;
    // 8004DD1C: bl      0x8006CCA0
    {
            ctx->lr = 0x8004DD20u;
            ctx->pc = 0x8006CCA0u;
            return;
    }

label_8004DD20:
    ctx->pc = 0x8004DD20u;
    ctx->downcount -= 6;
    // 8004DD20: lfs     f1, -31264(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004DD20u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31264);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8004DD24:
    ctx->pc = 0x8004DD24u;
    // 8004DD24: lfs     f0, 40(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004DD24u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004DD28:
    ctx->pc = 0x8004DD28u;
    // 8004DD28: fmuls   f1, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8004DD28u)) return;
    ppc_fmuls(ctx, 1, 1, 0);

label_8004DD2C:
    ctx->pc = 0x8004DD2Cu;
    // 8004DD2C: addi    r3, r1, 28
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(28);

label_8004DD30:
    ctx->pc = 0x8004DD30u;
    // 8004DD30: addi    r4, r1, 32
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(32);

label_8004DD34:
    ctx->pc = 0x8004DD34u;
    // 8004DD34: bl      0x802945D4
    {
            ctx->lr = 0x8004DD38u;
            ctx->pc = 0x802945D4u;
            return;
    }

label_8004DD38:
    ctx->pc = 0x8004DD38u;
    ctx->downcount -= 4;
    // 8004DD38: lfs     f1, -31264(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004DD38u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31264);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8004DD3C:
    ctx->pc = 0x8004DD3Cu;
    // 8004DD3C: lfs     f0, 36(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004DD3Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004DD40:
    ctx->pc = 0x8004DD40u;
    // 8004DD40: fmuls   f1, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8004DD40u)) return;
    ppc_fmuls(ctx, 1, 1, 0);

label_8004DD44:
    ctx->pc = 0x8004DD44u;
    // 8004DD44: bl      0x80294B74
    {
            ctx->lr = 0x8004DD48u;
            ctx->pc = 0x80294B74u;
            return;
    }

label_8004DD48:
    ctx->pc = 0x8004DD48u;
    ctx->downcount -= 23;
    // 8004DD48: lfs     f2, -31216(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004DD48u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31216);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8004DD4C:
    ctx->pc = 0x8004DD4Cu;
    // 8004DD4C: lfs     f0, -31220(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004DD4Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31220);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004DD50:
    ctx->pc = 0x8004DD50u;
    // 8004DD50: fmadds f2, f2, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8004DD50u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[2], ctx->fpr[1], ctx->fpr[0], true, false, false, &result))
            ctx->fpr[2] = ctx->ps1[2] = result;
    }

label_8004DD54:
    ctx->pc = 0x8004DD54u;
    // 8004DD54: lfs     f0, -31648(r13)
    if (!ppc_fp_available_inline(ctx, 0x8004DD54u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31648);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004DD58:
    ctx->pc = 0x8004DD58u;
    // 8004DD58: fmuls   f2, f2, f0
    if (!ppc_fp_available_inline(ctx, 0x8004DD58u)) return;
    ppc_fmuls(ctx, 2, 2, 0);

label_8004DD5C:
    ctx->pc = 0x8004DD5Cu;
    // 8004DD5C: lfs     f0, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004DD5Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004DD60:
    ctx->pc = 0x8004DD60u;
    // 8004DD60: fmuls   f1, f0, f2
    if (!ppc_fp_available_inline(ctx, 0x8004DD60u)) return;
    ppc_fmuls(ctx, 1, 0, 2);

label_8004DD64:
    ctx->pc = 0x8004DD64u;
    // 8004DD64: stfs     f1, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004DD64u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8004DD68:
    ctx->pc = 0x8004DD68u;
    // 8004DD68: lfs     f0, 28(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004DD68u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004DD6C:
    ctx->pc = 0x8004DD6Cu;
    // 8004DD6C: fmuls   f0, f0, f2
    if (!ppc_fp_available_inline(ctx, 0x8004DD6Cu)) return;
    ppc_fmuls(ctx, 0, 0, 2);

label_8004DD70:
    ctx->pc = 0x8004DD70u;
    // 8004DD70: stfs     f0, 28(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004DD70u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004DD74:
    ctx->pc = 0x8004DD74u;
    // 8004DD74: stfs     f1, 76(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004DD74u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(76);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8004DD78:
    ctx->pc = 0x8004DD78u;
    // 8004DD78: stfs     f0, 80(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004DD78u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004DD7C:
    ctx->pc = 0x8004DD7Cu;
    // 8004DD7C: fneg    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x8004DD7Cu)) return;
    ctx->fpr[0] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[0]) ^ 0x8000000000000000ull);

label_8004DD80:
    ctx->pc = 0x8004DD80u;
    // 8004DD80: stfs     f0, 88(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004DD80u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004DD84:
    ctx->pc = 0x8004DD84u;
    // 8004DD84: stfs     f1, 92(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004DD84u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8004DD88:
    ctx->pc = 0x8004DD88u;
    // 8004DD88: lfs     f1, -31264(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004DD88u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31264);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8004DD8C:
    ctx->pc = 0x8004DD8Cu;
    // 8004DD8C: lfs     f0, 36(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004DD8Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004DD90:
    ctx->pc = 0x8004DD90u;
    // 8004DD90: fneg    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x8004DD90u)) return;
    ctx->fpr[0] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[0]) ^ 0x8000000000000000ull);

label_8004DD94:
    ctx->pc = 0x8004DD94u;
    // 8004DD94: fmuls   f1, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8004DD94u)) return;
    ppc_fmuls(ctx, 1, 1, 0);

label_8004DD98:
    ctx->pc = 0x8004DD98u;
    // 8004DD98: addi    r3, r1, 28
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(28);

label_8004DD9C:
    ctx->pc = 0x8004DD9Cu;
    // 8004DD9C: addi    r4, r1, 32
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(32);

label_8004DDA0:
    ctx->pc = 0x8004DDA0u;
    // 8004DDA0: bl      0x802945D4
    {
            ctx->lr = 0x8004DDA4u;
            ctx->pc = 0x802945D4u;
            return;
    }

label_8004DDA4:
    ctx->pc = 0x8004DDA4u;
    ctx->downcount -= 4;
    // 8004DDA4: lfs     f1, -31264(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004DDA4u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31264);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8004DDA8:
    ctx->pc = 0x8004DDA8u;
    // 8004DDA8: lfs     f0, 40(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004DDA8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004DDAC:
    ctx->pc = 0x8004DDACu;
    // 8004DDAC: fmuls   f1, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8004DDACu)) return;
    ppc_fmuls(ctx, 1, 1, 0);

label_8004DDB0:
    ctx->pc = 0x8004DDB0u;
    // 8004DDB0: bl      0x80294B74
    {
            ctx->lr = 0x8004DDB4u;
            ctx->pc = 0x80294B74u;
            return;
    }

label_8004DDB4:
    ctx->pc = 0x8004DDB4u;
    ctx->downcount -= 20;
    // 8004DDB4: lfs     f0, -31260(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004DDB4u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31260);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004DDB8:
    ctx->pc = 0x8004DDB8u;
    // 8004DDB8: fmadds f31, f0, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8004DDB8u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[0], ctx->fpr[1], ctx->fpr[0], true, false, false, &result))
            ctx->fpr[31] = ctx->ps1[31] = result;
    }

label_8004DDBC:
    ctx->pc = 0x8004DDBCu;
    // 8004DDBC: lfs     f2, -31216(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004DDBCu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31216);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8004DDC0:
    ctx->pc = 0x8004DDC0u;
    // 8004DDC0: lfs     f0, -31220(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004DDC0u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31220);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004DDC4:
    ctx->pc = 0x8004DDC4u;
    // 8004DDC4: fmadds f2, f2, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8004DDC4u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[2], ctx->fpr[1], ctx->fpr[0], true, false, false, &result))
            ctx->fpr[2] = ctx->ps1[2] = result;
    }

label_8004DDC8:
    ctx->pc = 0x8004DDC8u;
    // 8004DDC8: lfs     f0, -31648(r13)
    if (!ppc_fp_available_inline(ctx, 0x8004DDC8u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31648);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004DDCC:
    ctx->pc = 0x8004DDCCu;
    // 8004DDCC: fmuls   f2, f2, f0
    if (!ppc_fp_available_inline(ctx, 0x8004DDCCu)) return;
    ppc_fmuls(ctx, 2, 2, 0);

label_8004DDD0:
    ctx->pc = 0x8004DDD0u;
    // 8004DDD0: lfs     f0, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004DDD0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004DDD4:
    ctx->pc = 0x8004DDD4u;
    // 8004DDD4: fmuls   f1, f0, f2
    if (!ppc_fp_available_inline(ctx, 0x8004DDD4u)) return;
    ppc_fmuls(ctx, 1, 0, 2);

label_8004DDD8:
    ctx->pc = 0x8004DDD8u;
    // 8004DDD8: stfs     f1, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004DDD8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8004DDDC:
    ctx->pc = 0x8004DDDCu;
    // 8004DDDC: lfs     f0, 28(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004DDDCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004DDE0:
    ctx->pc = 0x8004DDE0u;
    // 8004DDE0: fmuls   f0, f0, f2
    if (!ppc_fp_available_inline(ctx, 0x8004DDE0u)) return;
    ppc_fmuls(ctx, 0, 0, 2);

label_8004DDE4:
    ctx->pc = 0x8004DDE4u;
    // 8004DDE4: stfs     f0, 28(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004DDE4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004DDE8:
    ctx->pc = 0x8004DDE8u;
    // 8004DDE8: stfs     f1, 52(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004DDE8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8004DDEC:
    ctx->pc = 0x8004DDECu;
    // 8004DDEC: stfs     f0, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004DDECu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004DDF0:
    ctx->pc = 0x8004DDF0u;
    // 8004DDF0: fneg    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x8004DDF0u)) return;
    ctx->fpr[0] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[0]) ^ 0x8000000000000000ull);

label_8004DDF4:
    ctx->pc = 0x8004DDF4u;
    // 8004DDF4: stfs     f0, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004DDF4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004DDF8:
    ctx->pc = 0x8004DDF8u;
    // 8004DDF8: stfs     f1, 68(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004DDF8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8004DDFC:
    ctx->pc = 0x8004DDFCu;
    // 8004DDFC: addi    r3, r1, 44
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(44);

label_8004DE00:
    ctx->pc = 0x8004DE00u;
    // 8004DE00: bl      0x8006C6E8
    {
            ctx->lr = 0x8004DE04u;
            ctx->pc = 0x8006C6E8u;
            return;
    }

label_8004DE04:
    ctx->pc = 0x8004DE04u;
    ctx->downcount -= 3;
    // 8004DE04: lwz     r4, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004DE08:
    ctx->pc = 0x8004DE08u;
    // 8004DE08: cmplwi  r4, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004DE0C:
    ctx->pc = 0x8004DE0Cu;
    // 8004DE0C: bc    12, 2, 0x8004DE38
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004DE38;
        }
    }

label_8004DE10:
    ctx->pc = 0x8004DE10u;
    ctx->downcount -= 4;
    // 8004DE10: addi    r3, r4, 32
    ctx->gpr[3] = ctx->gpr[4] + (u32)(s32)(32);

label_8004DE14:
    ctx->pc = 0x8004DE14u;
    // 8004DE14: lbz     r0, 72(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(72);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8004DE18:
    ctx->pc = 0x8004DE18u;
    // 8004DE18: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004DE1C:
    ctx->pc = 0x8004DE1Cu;
    // 8004DE1C: bc    12, 2, 0x8004DE30
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004DE30;
        }
    }

label_8004DE20:
    ctx->pc = 0x8004DE20u;
    ctx->downcount -= 3;
    // 8004DE20: lwz     r4, 64(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(64);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004DE24:
    ctx->pc = 0x8004DE24u;
    // 8004DE24: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004DE28:
    ctx->pc = 0x8004DE28u;
    // 8004DE28: bl      0x8025B0B8
    {
            ctx->lr = 0x8004DE2Cu;
            ctx->pc = 0x8025B0B8u;
            return;
    }

label_8004DE2C:
    ctx->pc = 0x8004DE2Cu;
    ctx->downcount -= 1;
    // 8004DE2C: b       0x8004DE38
    {
            goto label_8004DE38;
    }

label_8004DE30:
    ctx->pc = 0x8004DE30u;
    ctx->downcount -= 2;
    // 8004DE30: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004DE34:
    ctx->pc = 0x8004DE34u;
    // 8004DE34: bl      0x8025B260
    {
            ctx->lr = 0x8004DE38u;
            ctx->pc = 0x8025B260u;
            return;
    }

label_8004DE38:
    ctx->pc = 0x8004DE38u;
    ctx->downcount -= 3;
    // 8004DE38: lbz     r3, 42(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(42);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8004DE3C:
    ctx->pc = 0x8004DE3Cu;
    // 8004DE3C: cmplwi  r3, 0x00FF
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x00FFu);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004DE40:
    ctx->pc = 0x8004DE40u;
    // 8004DE40: bc    12, 2, 0x8004DE68
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004DE68;
        }
    }

label_8004DE44:
    ctx->pc = 0x8004DE44u;
    ctx->downcount -= 3;
    // 8004DE44: addi    r4, r1, 24
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(24);

label_8004DE48:
    ctx->pc = 0x8004DE48u;
    // 8004DE48: addi    r5, r1, 20
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(20);

label_8004DE4C:
    ctx->pc = 0x8004DE4Cu;
    // 8004DE4C: bl      0x80056D70
    {
            ctx->lr = 0x8004DE50u;
            ctx->pc = 0x80056D70u;
            return;
    }

label_8004DE50:
    ctx->pc = 0x8004DE50u;
    ctx->downcount -= 5;
    // 8004DE50: addi    r3, r1, 100
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(100);

label_8004DE54:
    ctx->pc = 0x8004DE54u;
    // 8004DE54: lfs     f1, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004DE54u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8004DE58:
    ctx->pc = 0x8004DE58u;
    // 8004DE58: lfs     f2, 20(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004DE58u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8004DE5C:
    ctx->pc = 0x8004DE5Cu;
    // 8004DE5C: lfs     f3, -31276(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004DE5Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31276);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8004DE60:
    ctx->pc = 0x8004DE60u;
    // 8004DE60: bl      0x80247C90
    {
            ctx->lr = 0x8004DE64u;
            ctx->pc = 0x80247C90u;
            return;
    }

label_8004DE64:
    ctx->pc = 0x8004DE64u;
    ctx->downcount -= 1;
    // 8004DE64: b       0x8004DE70
    {
            goto label_8004DE70;
    }

label_8004DE68:
    ctx->pc = 0x8004DE68u;
    ctx->downcount -= 2;
    // 8004DE68: addi    r3, r1, 100
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(100);

label_8004DE6C:
    ctx->pc = 0x8004DE6Cu;
    // 8004DE6C: bl      0x80247800
    {
            ctx->lr = 0x8004DE70u;
            ctx->pc = 0x80247800u;
            return;
    }

label_8004DE70:
    ctx->pc = 0x8004DE70u;
    ctx->downcount -= 4;
    // 8004DE70: addi    r3, r1, 100
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(100);

label_8004DE74:
    ctx->pc = 0x8004DE74u;
    // 8004DE74: li      r4, 70
    ctx->gpr[4] = (u32)(s32)(70);

label_8004DE78:
    ctx->pc = 0x8004DE78u;
    // 8004DE78: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004DE7C:
    ctx->pc = 0x8004DE7Cu;
    // 8004DE7C: bl      0x8025DAD0
    {
            ctx->lr = 0x8004DE80u;
            ctx->pc = 0x8025DAD0u;
            return;
    }

label_8004DE80:
    ctx->pc = 0x8004DE80u;
    ctx->downcount -= 7;
    // 8004DE80: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8004DE84:
    ctx->pc = 0x8004DE84u;
    // 8004DE84: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004DE88:
    ctx->pc = 0x8004DE88u;
    // 8004DE88: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_8004DE8C:
    ctx->pc = 0x8004DE8Cu;
    // 8004DE8C: li      r6, 60
    ctx->gpr[6] = (u32)(s32)(60);

label_8004DE90:
    ctx->pc = 0x8004DE90u;
    // 8004DE90: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004DE94:
    ctx->pc = 0x8004DE94u;
    // 8004DE94: li      r8, 70
    ctx->gpr[8] = (u32)(s32)(70);

label_8004DE98:
    ctx->pc = 0x8004DE98u;
    // 8004DE98: bl      0x80258880
    {
            ctx->lr = 0x8004DE9Cu;
            ctx->pc = 0x80258880u;
            return;
    }

label_8004DE9C:
    ctx->pc = 0x8004DE9Cu;
    ctx->downcount -= 2;
    // 8004DE9C: addi    r3, r1, 48
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(48);

label_8004DEA0:
    ctx->pc = 0x8004DEA0u;
    // 8004DEA0: bl      0x8006C7C8
    {
            ctx->lr = 0x8004DEA4u;
            ctx->pc = 0x8006C7C8u;
            return;
    }

label_8004DEA4:
    ctx->pc = 0x8004DEA4u;
    ctx->downcount -= 3;
    // 8004DEA4: lwz     r4, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004DEA8:
    ctx->pc = 0x8004DEA8u;
    // 8004DEA8: cmplwi  r4, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004DEAC:
    ctx->pc = 0x8004DEACu;
    // 8004DEAC: bc    12, 2, 0x8004DED8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004DED8;
        }
    }

label_8004DEB0:
    ctx->pc = 0x8004DEB0u;
    ctx->downcount -= 4;
    // 8004DEB0: addi    r3, r4, 32
    ctx->gpr[3] = ctx->gpr[4] + (u32)(s32)(32);

label_8004DEB4:
    ctx->pc = 0x8004DEB4u;
    // 8004DEB4: lbz     r0, 72(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(72);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8004DEB8:
    ctx->pc = 0x8004DEB8u;
    // 8004DEB8: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004DEBC:
    ctx->pc = 0x8004DEBCu;
    // 8004DEBC: bc    12, 2, 0x8004DED0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004DED0;
        }
    }

label_8004DEC0:
    ctx->pc = 0x8004DEC0u;
    ctx->downcount -= 3;
    // 8004DEC0: lwz     r4, 64(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(64);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004DEC4:
    ctx->pc = 0x8004DEC4u;
    // 8004DEC4: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_8004DEC8:
    ctx->pc = 0x8004DEC8u;
    // 8004DEC8: bl      0x8025B0B8
    {
            ctx->lr = 0x8004DECCu;
            ctx->pc = 0x8025B0B8u;
            return;
    }

label_8004DECC:
    ctx->pc = 0x8004DECCu;
    ctx->downcount -= 1;
    // 8004DECC: b       0x8004DED8
    {
            goto label_8004DED8;
    }

label_8004DED0:
    ctx->pc = 0x8004DED0u;
    ctx->downcount -= 2;
    // 8004DED0: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8004DED4:
    ctx->pc = 0x8004DED4u;
    // 8004DED4: bl      0x8025B260
    {
            ctx->lr = 0x8004DED8u;
            ctx->pc = 0x8025B260u;
            return;
    }

label_8004DED8:
    ctx->pc = 0x8004DED8u;
    ctx->downcount -= 5;
    // 8004DED8: addi    r3, r1, 244
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(244);

label_8004DEDC:
    ctx->pc = 0x8004DEDCu;
    // 8004DEDC: lfs     f1, -31268(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004DEDCu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31268);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8004DEE0:
    ctx->pc = 0x8004DEE0u;
    // 8004DEE0: fmr    f2, f1
    if (!ppc_fp_available_inline(ctx, 0x8004DEE0u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_8004DEE4:
    ctx->pc = 0x8004DEE4u;
    // 8004DEE4: lfs     f3, -31280(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004DEE4u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31280);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8004DEE8:
    ctx->pc = 0x8004DEE8u;
    // 8004DEE8: bl      0x80247CC4
    {
            ctx->lr = 0x8004DEECu;
            ctx->pc = 0x80247CC4u;
            return;
    }

label_8004DEEC:
    ctx->pc = 0x8004DEECu;
    ctx->downcount -= 8;
    // 8004DEEC: lfs     f1, -31216(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004DEECu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31216);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8004DEF0:
    ctx->pc = 0x8004DEF0u;
    // 8004DEF0: lfs     f0, 36(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004DEF0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004DEF4:
    ctx->pc = 0x8004DEF4u;
    // 8004DEF4: fmuls   f0, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8004DEF4u)) return;
    ppc_fmuls(ctx, 0, 1, 0);

label_8004DEF8:
    ctx->pc = 0x8004DEF8u;
    // 8004DEF8: stfs     f0, 272(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004DEF8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(272);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004DEFC:
    ctx->pc = 0x8004DEFCu;
    // 8004DEFC: addi    r3, r1, 244
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(244);

label_8004DF00:
    ctx->pc = 0x8004DF00u;
    // 8004DF00: li      r4, 64
    ctx->gpr[4] = (u32)(s32)(64);

label_8004DF04:
    ctx->pc = 0x8004DF04u;
    // 8004DF04: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004DF08:
    ctx->pc = 0x8004DF08u;
    // 8004DF08: bl      0x8025DAD0
    {
            ctx->lr = 0x8004DF0Cu;
            ctx->pc = 0x8025DAD0u;
            return;
    }

label_8004DF0C:
    ctx->pc = 0x8004DF0Cu;
    ctx->downcount -= 7;
    // 8004DF0C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8004DF10:
    ctx->pc = 0x8004DF10u;
    // 8004DF10: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004DF14:
    ctx->pc = 0x8004DF14u;
    // 8004DF14: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_8004DF18:
    ctx->pc = 0x8004DF18u;
    // 8004DF18: li      r6, 60
    ctx->gpr[6] = (u32)(s32)(60);

label_8004DF1C:
    ctx->pc = 0x8004DF1Cu;
    // 8004DF1C: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004DF20:
    ctx->pc = 0x8004DF20u;
    // 8004DF20: li      r8, 64
    ctx->gpr[8] = (u32)(s32)(64);

label_8004DF24:
    ctx->pc = 0x8004DF24u;
    // 8004DF24: bl      0x80258880
    {
            ctx->lr = 0x8004DF28u;
            ctx->pc = 0x80258880u;
            return;
    }

label_8004DF28:
    ctx->pc = 0x8004DF28u;
    ctx->downcount -= 4;
    // 8004DF28: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8004DF2C:
    ctx->pc = 0x8004DF2Cu;
    // 8004DF2C: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8004DF30:
    ctx->pc = 0x8004DF30u;
    // 8004DF30: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_8004DF34:
    ctx->pc = 0x8004DF34u;
    // 8004DF34: bl      0x8025BF28
    {
            ctx->lr = 0x8004DF38u;
            ctx->pc = 0x8025BF28u;
            return;
    }

label_8004DF38:
    ctx->pc = 0x8004DF38u;
    ctx->downcount -= 4;
    // 8004DF38: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8004DF3C:
    ctx->pc = 0x8004DF3Cu;
    // 8004DF3C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004DF40:
    ctx->pc = 0x8004DF40u;
    // 8004DF40: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004DF44:
    ctx->pc = 0x8004DF44u;
    // 8004DF44: bl      0x8025BD54
    {
            ctx->lr = 0x8004DF48u;
            ctx->pc = 0x8025BD54u;
            return;
    }

label_8004DF48:
    ctx->pc = 0x8004DF48u;
    ctx->downcount -= 4;
    // 8004DF48: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8004DF4C:
    ctx->pc = 0x8004DF4Cu;
    // 8004DF4C: addi    r4, r1, 76
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(76);

label_8004DF50:
    ctx->pc = 0x8004DF50u;
    // 8004DF50: li      r5, -2
    ctx->gpr[5] = (u32)(s32)(-2);

label_8004DF54:
    ctx->pc = 0x8004DF54u;
    // 8004DF54: bl      0x8025BBF4
    {
            ctx->lr = 0x8004DF58u;
            ctx->pc = 0x8025BBF4u;
            return;
    }

label_8004DF58:
    ctx->pc = 0x8004DF58u;
    ctx->downcount -= 4;
    // 8004DF58: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8004DF5C:
    ctx->pc = 0x8004DF5Cu;
    // 8004DF5C: addi    r4, r1, 52
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(52);

label_8004DF60:
    ctx->pc = 0x8004DF60u;
    // 8004DF60: li      r5, -2
    ctx->gpr[5] = (u32)(s32)(-2);

label_8004DF64:
    ctx->pc = 0x8004DF64u;
    // 8004DF64: bl      0x8025BBF4
    {
            ctx->lr = 0x8004DF68u;
            ctx->pc = 0x8025BBF4u;
            return;
    }

label_8004DF68:
    ctx->pc = 0x8004DF68u;
    ctx->downcount -= 12;
    // 8004DF68: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8004DF6C:
    ctx->pc = 0x8004DF6Cu;
    // 8004DF6C: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004DF70:
    ctx->pc = 0x8004DF70u;
    // 8004DF70: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004DF74:
    ctx->pc = 0x8004DF74u;
    // 8004DF74: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8004DF78:
    ctx->pc = 0x8004DF78u;
    // 8004DF78: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004DF7C:
    ctx->pc = 0x8004DF7Cu;
    // 8004DF7C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004DF80:
    ctx->pc = 0x8004DF80u;
    // 8004DF80: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_8004DF84:
    ctx->pc = 0x8004DF84u;
    // 8004DF84: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004DF88:
    ctx->pc = 0x8004DF88u;
    // 8004DF88: li      r8, 6
    ctx->gpr[8] = (u32)(s32)(6);

label_8004DF8C:
    ctx->pc = 0x8004DF8Cu;
    // 8004DF8C: li      r9, 6
    ctx->gpr[9] = (u32)(s32)(6);

label_8004DF90:
    ctx->pc = 0x8004DF90u;
    // 8004DF90: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_8004DF94:
    ctx->pc = 0x8004DF94u;
    // 8004DF94: bl      0x8025BB58
    {
            ctx->lr = 0x8004DF98u;
            ctx->pc = 0x8025BB58u;
            return;
    }

label_8004DF98:
    ctx->pc = 0x8004DF98u;
    ctx->downcount -= 5;
    // 8004DF98: addi    r3, r1, 196
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(196);

label_8004DF9C:
    ctx->pc = 0x8004DF9Cu;
    // 8004DF9C: lfs     f1, -31212(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004DF9Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31212);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8004DFA0:
    ctx->pc = 0x8004DFA0u;
    // 8004DFA0: fmr    f2, f1
    if (!ppc_fp_available_inline(ctx, 0x8004DFA0u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_8004DFA4:
    ctx->pc = 0x8004DFA4u;
    // 8004DFA4: lfs     f3, -31280(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004DFA4u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31280);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8004DFA8:
    ctx->pc = 0x8004DFA8u;
    // 8004DFA8: bl      0x80247CC4
    {
            ctx->lr = 0x8004DFACu;
            ctx->pc = 0x80247CC4u;
            return;
    }

label_8004DFAC:
    ctx->pc = 0x8004DFACu;
    ctx->downcount -= 4;
    // 8004DFAC: addi    r3, r1, 148
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(148);

label_8004DFB0:
    ctx->pc = 0x8004DFB0u;
    // 8004DFB0: li      r4, 122
    ctx->gpr[4] = (u32)(s32)(122);

label_8004DFB4:
    ctx->pc = 0x8004DFB4u;
    // 8004DFB4: lfs     f1, -31208(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004DFB4u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31208);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8004DFB8:
    ctx->pc = 0x8004DFB8u;
    // 8004DFB8: bl      0x80247A74
    {
            ctx->lr = 0x8004DFBCu;
            ctx->pc = 0x80247A74u;
            return;
    }

label_8004DFBC:
    ctx->pc = 0x8004DFBCu;
    ctx->downcount -= 4;
    // 8004DFBC: addi    r3, r1, 148
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(148);

label_8004DFC0:
    ctx->pc = 0x8004DFC0u;
    // 8004DFC0: addi    r4, r1, 196
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(196);

label_8004DFC4:
    ctx->pc = 0x8004DFC4u;
    // 8004DFC4: or   r5, r4, r4
    {
        ctx->gpr[5] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8004DFC8:
    ctx->pc = 0x8004DFC8u;
    // 8004DFC8: bl      0x80247860
    {
            ctx->lr = 0x8004DFCCu;
            ctx->pc = 0x80247860u;
            return;
    }

label_8004DFCC:
    ctx->pc = 0x8004DFCCu;
    ctx->downcount -= 9;
    // 8004DFCC: lfs     f1, -31204(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004DFCCu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31204);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8004DFD0:
    ctx->pc = 0x8004DFD0u;
    // 8004DFD0: lfs     f0, 40(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004DFD0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004DFD4:
    ctx->pc = 0x8004DFD4u;
    // 8004DFD4: fmuls   f0, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8004DFD4u)) return;
    ppc_fmuls(ctx, 0, 1, 0);

label_8004DFD8:
    ctx->pc = 0x8004DFD8u;
    // 8004DFD8: stfs     f0, 208(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004DFD8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(208);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004DFDC:
    ctx->pc = 0x8004DFDCu;
    // 8004DFDC: stfs     f0, 224(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004DFDCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(224);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004DFE0:
    ctx->pc = 0x8004DFE0u;
    // 8004DFE0: addi    r3, r1, 196
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(196);

label_8004DFE4:
    ctx->pc = 0x8004DFE4u;
    // 8004DFE4: li      r4, 67
    ctx->gpr[4] = (u32)(s32)(67);

label_8004DFE8:
    ctx->pc = 0x8004DFE8u;
    // 8004DFE8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004DFEC:
    ctx->pc = 0x8004DFECu;
    // 8004DFEC: bl      0x8025DAD0
    {
            ctx->lr = 0x8004DFF0u;
            ctx->pc = 0x8025DAD0u;
            return;
    }

label_8004DFF0:
    ctx->pc = 0x8004DFF0u;
    ctx->downcount -= 7;
    // 8004DFF0: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8004DFF4:
    ctx->pc = 0x8004DFF4u;
    // 8004DFF4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004DFF8:
    ctx->pc = 0x8004DFF8u;
    // 8004DFF8: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_8004DFFC:
    ctx->pc = 0x8004DFFCu;
    // 8004DFFC: li      r6, 60
    ctx->gpr[6] = (u32)(s32)(60);

label_8004E000:
    ctx->pc = 0x8004E000u;
    // 8004E000: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004E004:
    ctx->pc = 0x8004E004u;
    // 8004E004: li      r8, 67
    ctx->gpr[8] = (u32)(s32)(67);

label_8004E008:
    ctx->pc = 0x8004E008u;
    // 8004E008: bl      0x80258880
    {
            ctx->lr = 0x8004E00Cu;
            ctx->pc = 0x80258880u;
            return;
    }

label_8004E00C:
    ctx->pc = 0x8004E00Cu;
    ctx->downcount -= 4;
    // 8004E00C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8004E010:
    ctx->pc = 0x8004E010u;
    // 8004E010: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_8004E014:
    ctx->pc = 0x8004E014u;
    // 8004E014: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_8004E018:
    ctx->pc = 0x8004E018u;
    // 8004E018: bl      0x8025BF28
    {
            ctx->lr = 0x8004E01Cu;
            ctx->pc = 0x8025BF28u;
            return;
    }

label_8004E01C:
    ctx->pc = 0x8004E01Cu;
    ctx->downcount -= 4;
    // 8004E01C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8004E020:
    ctx->pc = 0x8004E020u;
    // 8004E020: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004E024:
    ctx->pc = 0x8004E024u;
    // 8004E024: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004E028:
    ctx->pc = 0x8004E028u;
    // 8004E028: bl      0x8025BD54
    {
            ctx->lr = 0x8004E02Cu;
            ctx->pc = 0x8025BD54u;
            return;
    }

label_8004E02C:
    ctx->pc = 0x8004E02Cu;
    ctx->downcount -= 12;
    // 8004E02C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8004E030:
    ctx->pc = 0x8004E030u;
    // 8004E030: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004E034:
    ctx->pc = 0x8004E034u;
    // 8004E034: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004E038:
    ctx->pc = 0x8004E038u;
    // 8004E038: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8004E03C:
    ctx->pc = 0x8004E03Cu;
    // 8004E03C: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8004E040:
    ctx->pc = 0x8004E040u;
    // 8004E040: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004E044:
    ctx->pc = 0x8004E044u;
    // 8004E044: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_8004E048:
    ctx->pc = 0x8004E048u;
    // 8004E048: li      r7, 2
    ctx->gpr[7] = (u32)(s32)(2);

label_8004E04C:
    ctx->pc = 0x8004E04Cu;
    // 8004E04C: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8004E050:
    ctx->pc = 0x8004E050u;
    // 8004E050: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_8004E054:
    ctx->pc = 0x8004E054u;
    // 8004E054: li      r10, 1
    ctx->gpr[10] = (u32)(s32)(1);

label_8004E058:
    ctx->pc = 0x8004E058u;
    // 8004E058: bl      0x8025BB58
    {
            ctx->lr = 0x8004E05Cu;
            ctx->pc = 0x8025BB58u;
            return;
    }

label_8004E05C:
    ctx->pc = 0x8004E05Cu;
    ctx->downcount -= 15;
    // 8004E05C: lfs     f0, -31200(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004E05Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31200);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004E060:
    ctx->pc = 0x8004E060u;
    // 8004E060: fmuls   f0, f0, f31
    if (!ppc_fp_available_inline(ctx, 0x8004E060u)) return;
    ppc_fmuls(ctx, 0, 0, 31);

label_8004E064:
    ctx->pc = 0x8004E064u;
    // 8004E064: fctiwz    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x8004E064u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_8004E068:
    ctx->pc = 0x8004E068u;
    // 8004E068: stfd     f0, 296(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E068u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(296);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_8004E06C:
    ctx->pc = 0x8004E06Cu;
    // 8004E06C: lwz     r0, 300(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(300);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004E070:
    ctx->pc = 0x8004E070u;
    // 8004E070: stb     r0, -31652(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31652);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004E074:
    ctx->pc = 0x8004E074u;
    // 8004E074: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8004E078:
    ctx->pc = 0x8004E078u;
    // 8004E078: addi    r3, r13, -31652
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-31652);

label_8004E07C:
    ctx->pc = 0x8004E07Cu;
    // 8004E07C: stb     r0, 1(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004E080:
    ctx->pc = 0x8004E080u;
    // 8004E080: stb     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004E084:
    ctx->pc = 0x8004E084u;
    // 8004E084: lwz     r0, -31652(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31652);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004E088:
    ctx->pc = 0x8004E088u;
    // 8004E088: stw     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004E08C:
    ctx->pc = 0x8004E08Cu;
    // 8004E08C: lwz     r3, -25620(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25620);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004E090:
    ctx->pc = 0x8004E090u;
    // 8004E090: addi    r4, r1, 16
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(16);

label_8004E094:
    ctx->pc = 0x8004E094u;
    // 8004E094: bl      0x8025C71C
    {
            ctx->lr = 0x8004E098u;
            ctx->pc = 0x8025C71Cu;
            return;
    }

label_8004E098:
    ctx->pc = 0x8004E098u;
    ctx->downcount -= 3;
    // 8004E098: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8004E09C:
    ctx->pc = 0x8004E09Cu;
    // 8004E09C: lwz     r4, -25628(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25628);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004E0A0:
    ctx->pc = 0x8004E0A0u;
    // 8004E0A0: bl      0x8025C7FC
    {
            ctx->lr = 0x8004E0A4u;
            ctx->pc = 0x8025C7FCu;
            return;
    }

label_8004E0A4:
    ctx->pc = 0x8004E0A4u;
    ctx->downcount -= 3;
    // 8004E0A4: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8004E0A8:
    ctx->pc = 0x8004E0A8u;
    // 8004E0A8: lwz     r4, -25624(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25624);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004E0AC:
    ctx->pc = 0x8004E0ACu;
    // 8004E0AC: bl      0x8025C790
    {
            ctx->lr = 0x8004E0B0u;
            ctx->pc = 0x8025C790u;
            return;
    }

label_8004E0B0:
    ctx->pc = 0x8004E0B0u;
    ctx->downcount -= 2;
    // 8004E0B0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8004E0B4:
    ctx->pc = 0x8004E0B4u;
    // 8004E0B4: bl      0x8025C08C
    {
            ctx->lr = 0x8004E0B8u;
            ctx->pc = 0x8025C08Cu;
            return;
    }

label_8004E0B8:
    ctx->pc = 0x8004E0B8u;
    ctx->downcount -= 6;
    // 8004E0B8: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_8004E0BC:
    ctx->pc = 0x8004E0BCu;
    // 8004E0BC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004E0C0:
    ctx->pc = 0x8004E0C0u;
    // 8004E0C0: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_8004E0C4:
    ctx->pc = 0x8004E0C4u;
    // 8004E0C4: li      r6, 2
    ctx->gpr[6] = (u32)(s32)(2);

label_8004E0C8:
    ctx->pc = 0x8004E0C8u;
    // 8004E0C8: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004E0CC:
    ctx->pc = 0x8004E0CCu;
    // 8004E0CC: bl      0x8025C8C0
    {
            ctx->lr = 0x8004E0D0u;
            ctx->pc = 0x8025C8C0u;
            return;
    }

label_8004E0D0:
    ctx->pc = 0x8004E0D0u;
    ctx->downcount -= 5;
    // 8004E0D0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8004E0D4:
    ctx->pc = 0x8004E0D4u;
    // 8004E0D4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004E0D8:
    ctx->pc = 0x8004E0D8u;
    // 8004E0D8: li      r5, 2
    ctx->gpr[5] = (u32)(s32)(2);

label_8004E0DC:
    ctx->pc = 0x8004E0DCu;
    // 8004E0DC: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_8004E0E0:
    ctx->pc = 0x8004E0E0u;
    // 8004E0E0: bl      0x8025CA34
    {
            ctx->lr = 0x8004E0E4u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_8004E0E4:
    ctx->pc = 0x8004E0E4u;
    ctx->downcount -= 6;
    // 8004E0E4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8004E0E8:
    ctx->pc = 0x8004E0E8u;
    // 8004E0E8: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_8004E0EC:
    ctx->pc = 0x8004E0ECu;
    // 8004E0EC: li      r5, 8
    ctx->gpr[5] = (u32)(s32)(8);

label_8004E0F0:
    ctx->pc = 0x8004E0F0u;
    // 8004E0F0: li      r6, 10
    ctx->gpr[6] = (u32)(s32)(10);

label_8004E0F4:
    ctx->pc = 0x8004E0F4u;
    // 8004E0F4: li      r7, 15
    ctx->gpr[7] = (u32)(s32)(15);

label_8004E0F8:
    ctx->pc = 0x8004E0F8u;
    // 8004E0F8: bl      0x8025C3B0
    {
            ctx->lr = 0x8004E0FCu;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_8004E0FC:
    ctx->pc = 0x8004E0FCu;
    ctx->downcount -= 6;
    // 8004E0FC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8004E100:
    ctx->pc = 0x8004E100u;
    // 8004E100: li      r4, 6
    ctx->gpr[4] = (u32)(s32)(6);

label_8004E104:
    ctx->pc = 0x8004E104u;
    // 8004E104: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_8004E108:
    ctx->pc = 0x8004E108u;
    // 8004E108: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_8004E10C:
    ctx->pc = 0x8004E10Cu;
    // 8004E10C: li      r7, 4
    ctx->gpr[7] = (u32)(s32)(4);

label_8004E110:
    ctx->pc = 0x8004E110u;
    // 8004E110: bl      0x8025C430
    {
            ctx->lr = 0x8004E114u;
            ctx->pc = 0x8025C430u;
            return;
    }

label_8004E114:
    ctx->pc = 0x8004E114u;
    ctx->downcount -= 4;
    // 8004E114: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8004E118:
    ctx->pc = 0x8004E118u;
    // 8004E118: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004E11C:
    ctx->pc = 0x8004E11Cu;
    // 8004E11C: li      r5, 3
    ctx->gpr[5] = (u32)(s32)(3);

label_8004E120:
    ctx->pc = 0x8004E120u;
    // 8004E120: bl      0x8025C868
    {
            ctx->lr = 0x8004E124u;
            ctx->pc = 0x8025C868u;
            return;
    }

label_8004E124:
    ctx->pc = 0x8004E124u;
    ctx->downcount -= 7;
    // 8004E124: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8004E128:
    ctx->pc = 0x8004E128u;
    // 8004E128: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004E12C:
    ctx->pc = 0x8004E12Cu;
    // 8004E12C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004E130:
    ctx->pc = 0x8004E130u;
    // 8004E130: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004E134:
    ctx->pc = 0x8004E134u;
    // 8004E134: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004E138:
    ctx->pc = 0x8004E138u;
    // 8004E138: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8004E13C:
    ctx->pc = 0x8004E13Cu;
    // 8004E13C: bl      0x8025C4B4
    {
            ctx->lr = 0x8004E140u;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_8004E140:
    ctx->pc = 0x8004E140u;
    ctx->downcount -= 7;
    // 8004E140: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8004E144:
    ctx->pc = 0x8004E144u;
    // 8004E144: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8004E148:
    ctx->pc = 0x8004E148u;
    // 8004E148: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004E14C:
    ctx->pc = 0x8004E14Cu;
    // 8004E14C: li      r6, 2
    ctx->gpr[6] = (u32)(s32)(2);

label_8004E150:
    ctx->pc = 0x8004E150u;
    // 8004E150: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004E154:
    ctx->pc = 0x8004E154u;
    // 8004E154: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8004E158:
    ctx->pc = 0x8004E158u;
    // 8004E158: bl      0x8025C574
    {
            ctx->lr = 0x8004E15Cu;
            ctx->pc = 0x8025C574u;
            return;
    }

label_8004E15C:
    ctx->pc = 0x8004E15Cu;
    ctx->downcount -= 7;
    // 8004E15C: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8004E160:
    ctx->pc = 0x8004E160u;
    // 8004E160: stb     r0, -25688(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25688);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004E164:
    ctx->pc = 0x8004E164u;
    // 8004E164: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8004E168:
    ctx->pc = 0x8004E168u;
    // 8004E168: li      r4, 255
    ctx->gpr[4] = (u32)(s32)(255);

label_8004E16C:
    ctx->pc = 0x8004E16Cu;
    // 8004E16C: li      r5, 255
    ctx->gpr[5] = (u32)(s32)(255);

label_8004E170:
    ctx->pc = 0x8004E170u;
    // 8004E170: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_8004E174:
    ctx->pc = 0x8004E174u;
    // 8004E174: bl      0x8025CA34
    {
            ctx->lr = 0x8004E178u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_8004E178:
    ctx->pc = 0x8004E178u;
    ctx->downcount -= 6;
    // 8004E178: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8004E17C:
    ctx->pc = 0x8004E17Cu;
    // 8004E17C: li      r4, 14
    ctx->gpr[4] = (u32)(s32)(14);

label_8004E180:
    ctx->pc = 0x8004E180u;
    // 8004E180: li      r5, 15
    ctx->gpr[5] = (u32)(s32)(15);

label_8004E184:
    ctx->pc = 0x8004E184u;
    // 8004E184: li      r6, 15
    ctx->gpr[6] = (u32)(s32)(15);

label_8004E188:
    ctx->pc = 0x8004E188u;
    // 8004E188: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004E18C:
    ctx->pc = 0x8004E18Cu;
    // 8004E18C: bl      0x8025C3B0
    {
            ctx->lr = 0x8004E190u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_8004E190:
    ctx->pc = 0x8004E190u;
    ctx->downcount -= 6;
    // 8004E190: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8004E194:
    ctx->pc = 0x8004E194u;
    // 8004E194: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_8004E198:
    ctx->pc = 0x8004E198u;
    // 8004E198: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_8004E19C:
    ctx->pc = 0x8004E19Cu;
    // 8004E19C: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_8004E1A0:
    ctx->pc = 0x8004E1A0u;
    // 8004E1A0: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004E1A4:
    ctx->pc = 0x8004E1A4u;
    // 8004E1A4: bl      0x8025C430
    {
            ctx->lr = 0x8004E1A8u;
            ctx->pc = 0x8025C430u;
            return;
    }

label_8004E1A8:
    ctx->pc = 0x8004E1A8u;
    ctx->downcount -= 4;
    // 8004E1A8: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8004E1AC:
    ctx->pc = 0x8004E1ACu;
    // 8004E1AC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004E1B0:
    ctx->pc = 0x8004E1B0u;
    // 8004E1B0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004E1B4:
    ctx->pc = 0x8004E1B4u;
    // 8004E1B4: bl      0x8025C868
    {
            ctx->lr = 0x8004E1B8u;
            ctx->pc = 0x8025C868u;
            return;
    }

label_8004E1B8:
    ctx->pc = 0x8004E1B8u;
    ctx->downcount -= 7;
    // 8004E1B8: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8004E1BC:
    ctx->pc = 0x8004E1BCu;
    // 8004E1BC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004E1C0:
    ctx->pc = 0x8004E1C0u;
    // 8004E1C0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004E1C4:
    ctx->pc = 0x8004E1C4u;
    // 8004E1C4: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004E1C8:
    ctx->pc = 0x8004E1C8u;
    // 8004E1C8: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004E1CC:
    ctx->pc = 0x8004E1CCu;
    // 8004E1CC: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8004E1D0:
    ctx->pc = 0x8004E1D0u;
    // 8004E1D0: bl      0x8025C4B4
    {
            ctx->lr = 0x8004E1D4u;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_8004E1D4:
    ctx->pc = 0x8004E1D4u;
    ctx->downcount -= 7;
    // 8004E1D4: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8004E1D8:
    ctx->pc = 0x8004E1D8u;
    // 8004E1D8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004E1DC:
    ctx->pc = 0x8004E1DCu;
    // 8004E1DC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004E1E0:
    ctx->pc = 0x8004E1E0u;
    // 8004E1E0: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004E1E4:
    ctx->pc = 0x8004E1E4u;
    // 8004E1E4: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004E1E8:
    ctx->pc = 0x8004E1E8u;
    // 8004E1E8: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8004E1EC:
    ctx->pc = 0x8004E1ECu;
    // 8004E1EC: bl      0x8025C574
    {
            ctx->lr = 0x8004E1F0u;
            ctx->pc = 0x8025C574u;
            return;
    }

label_8004E1F0:
    ctx->pc = 0x8004E1F0u;
    ctx->downcount -= 5;
    // 8004E1F0: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8004E1F4:
    ctx->pc = 0x8004E1F4u;
    // 8004E1F4: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_8004E1F8:
    ctx->pc = 0x8004E1F8u;
    // 8004E1F8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004E1FC:
    ctx->pc = 0x8004E1FCu;
    // 8004E1FC: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_8004E200:
    ctx->pc = 0x8004E200u;
    // 8004E200: bl      0x8025CA34
    {
            ctx->lr = 0x8004E204u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_8004E204:
    ctx->pc = 0x8004E204u;
    ctx->downcount -= 6;
    // 8004E204: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8004E208:
    ctx->pc = 0x8004E208u;
    // 8004E208: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004E20C:
    ctx->pc = 0x8004E20Cu;
    // 8004E20C: li      r5, 8
    ctx->gpr[5] = (u32)(s32)(8);

label_8004E210:
    ctx->pc = 0x8004E210u;
    // 8004E210: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_8004E214:
    ctx->pc = 0x8004E214u;
    // 8004E214: li      r7, 15
    ctx->gpr[7] = (u32)(s32)(15);

label_8004E218:
    ctx->pc = 0x8004E218u;
    // 8004E218: bl      0x8025C3B0
    {
            ctx->lr = 0x8004E21Cu;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_8004E21C:
    ctx->pc = 0x8004E21Cu;
    ctx->downcount -= 6;
    // 8004E21C: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8004E220:
    ctx->pc = 0x8004E220u;
    // 8004E220: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_8004E224:
    ctx->pc = 0x8004E224u;
    // 8004E224: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_8004E228:
    ctx->pc = 0x8004E228u;
    // 8004E228: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_8004E22C:
    ctx->pc = 0x8004E22Cu;
    // 8004E22C: li      r7, 7
    ctx->gpr[7] = (u32)(s32)(7);

label_8004E230:
    ctx->pc = 0x8004E230u;
    // 8004E230: bl      0x8025C430
    {
            ctx->lr = 0x8004E234u;
            ctx->pc = 0x8025C430u;
            return;
    }

label_8004E234:
    ctx->pc = 0x8004E234u;
    ctx->downcount -= 4;
    // 8004E234: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8004E238:
    ctx->pc = 0x8004E238u;
    // 8004E238: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004E23C:
    ctx->pc = 0x8004E23Cu;
    // 8004E23C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004E240:
    ctx->pc = 0x8004E240u;
    // 8004E240: bl      0x8025C868
    {
            ctx->lr = 0x8004E244u;
            ctx->pc = 0x8025C868u;
            return;
    }

label_8004E244:
    ctx->pc = 0x8004E244u;
    ctx->downcount -= 7;
    // 8004E244: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8004E248:
    ctx->pc = 0x8004E248u;
    // 8004E248: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004E24C:
    ctx->pc = 0x8004E24Cu;
    // 8004E24C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004E250:
    ctx->pc = 0x8004E250u;
    // 8004E250: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004E254:
    ctx->pc = 0x8004E254u;
    // 8004E254: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004E258:
    ctx->pc = 0x8004E258u;
    // 8004E258: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8004E25C:
    ctx->pc = 0x8004E25Cu;
    // 8004E25C: bl      0x8025C4B4
    {
            ctx->lr = 0x8004E260u;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_8004E260:
    ctx->pc = 0x8004E260u;
    ctx->downcount -= 7;
    // 8004E260: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8004E264:
    ctx->pc = 0x8004E264u;
    // 8004E264: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004E268:
    ctx->pc = 0x8004E268u;
    // 8004E268: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004E26C:
    ctx->pc = 0x8004E26Cu;
    // 8004E26C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004E270:
    ctx->pc = 0x8004E270u;
    // 8004E270: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8004E274:
    ctx->pc = 0x8004E274u;
    // 8004E274: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8004E278:
    ctx->pc = 0x8004E278u;
    // 8004E278: bl      0x8025C574
    {
            ctx->lr = 0x8004E27Cu;
            ctx->pc = 0x8025C574u;
            return;
    }

label_8004E27C:
    ctx->pc = 0x8004E27Cu;
    ctx->downcount -= 26;
    // 8004E27C: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_8004E280:
    ctx->pc = 0x8004E280u;
    // 8004E280: stw     r4, -25600(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25600);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8004E284:
    ctx->pc = 0x8004E284u;
    // 8004E284: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_8004E288:
    ctx->pc = 0x8004E288u;
    // 8004E288: stw     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8004E28C:
    ctx->pc = 0x8004E28Cu;
    // 8004E28C: stw     r3, -25596(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25596);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8004E290:
    ctx->pc = 0x8004E290u;
    // 8004E290: li      r0, 73
    ctx->gpr[0] = (u32)(s32)(73);

label_8004E294:
    ctx->pc = 0x8004E294u;
    // 8004E294: stw     r0, -25608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25608);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004E298:
    ctx->pc = 0x8004E298u;
    // 8004E298: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_8004E29C:
    ctx->pc = 0x8004E29Cu;
    // 8004E29C: stw     r0, -25612(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25612);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004E2A0:
    ctx->pc = 0x8004E2A0u;
    // 8004E2A0: stb     r3, -25630(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25630);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_8004E2A4:
    ctx->pc = 0x8004E2A4u;
    // 8004E2A4: stb     r4, -25631(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25631);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_8004E2A8:
    ctx->pc = 0x8004E2A8u;
    // 8004E2A8: stb     r0, -25632(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25632);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8004E2AC:
    ctx->pc = 0x8004E2ACu;
    // 8004E2AC: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8004E2B0:
    ctx->pc = 0x8004E2B0u;
    // 8004E2B0: stw     r0, -25620(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25620);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004E2B4:
    ctx->pc = 0x8004E2B4u;
    // 8004E2B4: li      r0, 13
    ctx->gpr[0] = (u32)(s32)(13);

label_8004E2B8:
    ctx->pc = 0x8004E2B8u;
    // 8004E2B8: stw     r0, -25624(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25624);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004E2BC:
    ctx->pc = 0x8004E2BCu;
    // 8004E2BC: li      r0, 29
    ctx->gpr[0] = (u32)(s32)(29);

label_8004E2C0:
    ctx->pc = 0x8004E2C0u;
    // 8004E2C0: stw     r0, -25628(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25628);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004E2C4:
    ctx->pc = 0x8004E2C4u;
    // 8004E2C4: psq_l   f31, 328(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8004E2C4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(328);
        ppc_psq_load_inline(ctx, 31u, ea, false, 0u, false, 0x8004E2C4u);
        if (ctx->exception) return;
    }

label_8004E2C8:
    ctx->pc = 0x8004E2C8u;
    // 8004E2C8: lfd     f31, 320(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E2C8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(320);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8004E2CC:
    ctx->pc = 0x8004E2CCu;
    // 8004E2CC: lwz     r31, 316(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(316);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8004E2D0:
    ctx->pc = 0x8004E2D0u;
    // 8004E2D0: lwz     r0, 340(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(340);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004E2D4:
    ctx->pc = 0x8004E2D4u;
    // 8004E2D4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8004E2D8:
    ctx->pc = 0x8004E2D8u;
    // 8004E2D8: addi    r1, r1, 336
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(336);

label_8004E2DC:
    ctx->pc = 0x8004E2DCu;
    // 8004E2DC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8004A6E0;
        }
    }

label_8004E2E0:
    ctx->pc = 0x8004E2E0u;
    ctx->downcount -= 43;
    // 8004E2E0: stwu     r1, -544(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-544);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8004E2E4:
    ctx->pc = 0x8004E2E4u;
    // 8004E2E4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8004E2E8:
    ctx->pc = 0x8004E2E8u;
    // 8004E2E8: stw     r0, 548(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(548);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004E2EC:
    ctx->pc = 0x8004E2ECu;
    // 8004E2EC: stw     r31, 540(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(540);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8004E2F0:
    ctx->pc = 0x8004E2F0u;
    // 8004E2F0: lis     r3, -32724
    ctx->gpr[3] = ((u32)(s32)(-32724) << 16);

label_8004E2F4:
    ctx->pc = 0x8004E2F4u;
    // 8004E2F4: addi    r4, r3, 9936
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(9936);

label_8004E2F8:
    ctx->pc = 0x8004E2F8u;
    // 8004E2F8: lwz     r3, 48(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(48);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004E2FC:
    ctx->pc = 0x8004E2FCu;
    // 8004E2FC: lwz     r0, 52(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004E300:
    ctx->pc = 0x8004E300u;
    // 8004E300: stw     r3, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8004E304:
    ctx->pc = 0x8004E304u;
    // 8004E304: stw     r0, 72(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004E308:
    ctx->pc = 0x8004E308u;
    // 8004E308: lwz     r0, 56(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(56);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004E30C:
    ctx->pc = 0x8004E30Cu;
    // 8004E30C: stw     r0, 76(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(76);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004E310:
    ctx->pc = 0x8004E310u;
    // 8004E310: lwz     r3, 60(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(60);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004E314:
    ctx->pc = 0x8004E314u;
    // 8004E314: lwz     r0, 64(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(64);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004E318:
    ctx->pc = 0x8004E318u;
    // 8004E318: stw     r3, 56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8004E31C:
    ctx->pc = 0x8004E31Cu;
    // 8004E31C: stw     r0, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004E320:
    ctx->pc = 0x8004E320u;
    // 8004E320: lwz     r0, 68(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(68);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004E324:
    ctx->pc = 0x8004E324u;
    // 8004E324: stw     r0, 64(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004E328:
    ctx->pc = 0x8004E328u;
    // 8004E328: lwz     r3, 72(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(72);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004E32C:
    ctx->pc = 0x8004E32Cu;
    // 8004E32C: lwz     r0, 76(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(76);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004E330:
    ctx->pc = 0x8004E330u;
    // 8004E330: stw     r3, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8004E334:
    ctx->pc = 0x8004E334u;
    // 8004E334: stw     r0, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004E338:
    ctx->pc = 0x8004E338u;
    // 8004E338: lwz     r0, 80(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(80);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004E33C:
    ctx->pc = 0x8004E33Cu;
    // 8004E33C: stw     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004E340:
    ctx->pc = 0x8004E340u;
    // 8004E340: lwz     r3, 84(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(84);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004E344:
    ctx->pc = 0x8004E344u;
    // 8004E344: lwz     r0, 88(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(88);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004E348:
    ctx->pc = 0x8004E348u;
    // 8004E348: stw     r3, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8004E34C:
    ctx->pc = 0x8004E34Cu;
    // 8004E34C: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004E350:
    ctx->pc = 0x8004E350u;
    // 8004E350: lwz     r0, 92(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(92);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004E354:
    ctx->pc = 0x8004E354u;
    // 8004E354: stw     r0, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004E358:
    ctx->pc = 0x8004E358u;
    // 8004E358: lwz     r3, 96(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(96);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004E35C:
    ctx->pc = 0x8004E35Cu;
    // 8004E35C: lwz     r0, 100(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(100);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004E360:
    ctx->pc = 0x8004E360u;
    // 8004E360: stw     r3, 80(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8004E364:
    ctx->pc = 0x8004E364u;
    // 8004E364: stw     r0, 84(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004E368:
    ctx->pc = 0x8004E368u;
    // 8004E368: lwz     r3, 104(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(104);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004E36C:
    ctx->pc = 0x8004E36Cu;
    // 8004E36C: lwz     r0, 108(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(108);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004E370:
    ctx->pc = 0x8004E370u;
    // 8004E370: stw     r3, 88(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8004E374:
    ctx->pc = 0x8004E374u;
    // 8004E374: stw     r0, 92(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004E378:
    ctx->pc = 0x8004E378u;
    // 8004E378: lwz     r3, 112(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(112);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004E37C:
    ctx->pc = 0x8004E37Cu;
    // 8004E37C: lwz     r0, 116(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(116);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8004E380:
    ctx->pc = 0x8004E380u;
    // 8004E380: stw     r3, 96(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8004E384:
    ctx->pc = 0x8004E384u;
    // 8004E384: stw     r0, 100(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(100);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004E388:
    ctx->pc = 0x8004E388u;
    // 8004E388: bl      0x8000F578
    {
            ctx->lr = 0x8004E38Cu;
            ctx->pc = 0x8000F578u;
            return;
    }

label_8004E38C:
    ctx->pc = 0x8004E38Cu;
    ctx->downcount -= 5;
    // 8004E38C: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004E390:
    ctx->pc = 0x8004E390u;
    // 8004E390: addi    r3, r1, 248
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(248);

label_8004E394:
    ctx->pc = 0x8004E394u;
    // 8004E394: addi    r4, r1, 68
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(68);

label_8004E398:
    ctx->pc = 0x8004E398u;
    // 8004E398: lfs     f1, -31280(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004E398u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31280);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8004E39C:
    ctx->pc = 0x8004E39Cu;
    // 8004E39C: bl      0x80247B8C
    {
            ctx->lr = 0x8004E3A0u;
            ctx->pc = 0x80247B8Cu;
            return;
    }

label_8004E3A0:
    ctx->pc = 0x8004E3A0u;
    ctx->downcount -= 4;
    // 8004E3A0: addi    r3, r1, 200
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(200);

label_8004E3A4:
    ctx->pc = 0x8004E3A4u;
    // 8004E3A4: addi    r4, r1, 56
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(56);

label_8004E3A8:
    ctx->pc = 0x8004E3A8u;
    // 8004E3A8: lfs     f1, -31280(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004E3A8u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31280);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8004E3AC:
    ctx->pc = 0x8004E3ACu;
    // 8004E3AC: bl      0x80247B8C
    {
            ctx->lr = 0x8004E3B0u;
            ctx->pc = 0x80247B8Cu;
            return;
    }

label_8004E3B0:
    ctx->pc = 0x8004E3B0u;
    ctx->downcount -= 4;
    // 8004E3B0: addi    r3, r1, 152
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(152);

label_8004E3B4:
    ctx->pc = 0x8004E3B4u;
    // 8004E3B4: addi    r4, r1, 44
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(44);

label_8004E3B8:
    ctx->pc = 0x8004E3B8u;
    // 8004E3B8: lfs     f1, -31280(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004E3B8u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31280);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8004E3BC:
    ctx->pc = 0x8004E3BCu;
    // 8004E3BC: bl      0x80247B8C
    {
            ctx->lr = 0x8004E3C0u;
            ctx->pc = 0x80247B8Cu;
            return;
    }

label_8004E3C0:
    ctx->pc = 0x8004E3C0u;
    ctx->downcount -= 4;
    // 8004E3C0: addi    r3, r1, 104
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(104);

label_8004E3C4:
    ctx->pc = 0x8004E3C4u;
    // 8004E3C4: addi    r4, r1, 32
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(32);

label_8004E3C8:
    ctx->pc = 0x8004E3C8u;
    // 8004E3C8: lfs     f1, -31280(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004E3C8u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31280);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8004E3CC:
    ctx->pc = 0x8004E3CCu;
    // 8004E3CC: bl      0x80247B8C
    {
            ctx->lr = 0x8004E3D0u;
            ctx->pc = 0x80247B8Cu;
            return;
    }

label_8004E3D0:
    ctx->pc = 0x8004E3D0u;
    ctx->downcount -= 42;
    // 8004E3D0: lfs     f4, -31196(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004E3D0u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31196);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[4] = value;
        ctx->ps1[4] = value;
    }

label_8004E3D4:
    ctx->pc = 0x8004E3D4u;
    // 8004E3D4: stfs     f4, 488(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E3D4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(488);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[4]));
    }

label_8004E3D8:
    ctx->pc = 0x8004E3D8u;
    // 8004E3D8: lfs     f3, -31276(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004E3D8u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31276);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8004E3DC:
    ctx->pc = 0x8004E3DCu;
    // 8004E3DC: stfs     f3, 492(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E3DCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(492);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[3]));
    }

label_8004E3E0:
    ctx->pc = 0x8004E3E0u;
    // 8004E3E0: stfs     f3, 496(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E3E0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(496);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[3]));
    }

label_8004E3E4:
    ctx->pc = 0x8004E3E4u;
    // 8004E3E4: lfs     f2, -31272(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004E3E4u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31272);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8004E3E8:
    ctx->pc = 0x8004E3E8u;
    // 8004E3E8: lfs     f1, -31192(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004E3E8u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31192);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8004E3EC:
    ctx->pc = 0x8004E3ECu;
    // 8004E3EC: lfs     f0, -25520(r13)
    if (!ppc_fp_available_inline(ctx, 0x8004E3ECu)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25520);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004E3F0:
    ctx->pc = 0x8004E3F0u;
    // 8004E3F0: fmuls   f5, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8004E3F0u)) return;
    ppc_fmuls(ctx, 5, 1, 0);

label_8004E3F4:
    ctx->pc = 0x8004E3F4u;
    // 8004E3F4: fmuls   f0, f2, f5
    if (!ppc_fp_available_inline(ctx, 0x8004E3F4u)) return;
    ppc_fmuls(ctx, 0, 2, 5);

label_8004E3F8:
    ctx->pc = 0x8004E3F8u;
    // 8004E3F8: stfs     f0, 500(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E3F8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(500);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004E3FC:
    ctx->pc = 0x8004E3FCu;
    // 8004E3FC: stfs     f3, 504(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E3FCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(504);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[3]));
    }

label_8004E400:
    ctx->pc = 0x8004E400u;
    // 8004E400: stfs     f4, 508(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E400u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(508);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[4]));
    }

label_8004E404:
    ctx->pc = 0x8004E404u;
    // 8004E404: stfs     f3, 512(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E404u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(512);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[3]));
    }

label_8004E408:
    ctx->pc = 0x8004E408u;
    // 8004E408: stfs     f3, 516(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E408u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(516);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[3]));
    }

label_8004E40C:
    ctx->pc = 0x8004E40Cu;
    // 8004E40C: stfs     f3, 520(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E40Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(520);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[3]));
    }

label_8004E410:
    ctx->pc = 0x8004E410u;
    // 8004E410: stfs     f3, 524(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E410u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(524);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[3]));
    }

label_8004E414:
    ctx->pc = 0x8004E414u;
    // 8004E414: stfs     f4, 528(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E414u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(528);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[4]));
    }

label_8004E418:
    ctx->pc = 0x8004E418u;
    // 8004E418: lfs     f0, -25516(r13)
    if (!ppc_fp_available_inline(ctx, 0x8004E418u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25516);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004E41C:
    ctx->pc = 0x8004E41Cu;
    // 8004E41C: fmuls   f4, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8004E41Cu)) return;
    ppc_fmuls(ctx, 4, 1, 0);

label_8004E420:
    ctx->pc = 0x8004E420u;
    // 8004E420: fmuls   f0, f2, f4
    if (!ppc_fp_available_inline(ctx, 0x8004E420u)) return;
    ppc_fmuls(ctx, 0, 2, 4);

label_8004E424:
    ctx->pc = 0x8004E424u;
    // 8004E424: stfs     f0, 532(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E424u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(532);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004E428:
    ctx->pc = 0x8004E428u;
    // 8004E428: lfs     f2, -31188(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004E428u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31188);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8004E42C:
    ctx->pc = 0x8004E42Cu;
    // 8004E42C: stfs     f2, 440(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E42Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(440);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_8004E430:
    ctx->pc = 0x8004E430u;
    // 8004E430: stfs     f3, 444(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E430u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(444);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[3]));
    }

label_8004E434:
    ctx->pc = 0x8004E434u;
    // 8004E434: stfs     f3, 448(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E434u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(448);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[3]));
    }

label_8004E438:
    ctx->pc = 0x8004E438u;
    // 8004E438: lfs     f1, -31260(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004E438u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31260);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8004E43C:
    ctx->pc = 0x8004E43Cu;
    // 8004E43C: fmuls   f0, f1, f5
    if (!ppc_fp_available_inline(ctx, 0x8004E43Cu)) return;
    ppc_fmuls(ctx, 0, 1, 5);

label_8004E440:
    ctx->pc = 0x8004E440u;
    // 8004E440: stfs     f0, 452(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E440u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(452);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004E444:
    ctx->pc = 0x8004E444u;
    // 8004E444: stfs     f3, 456(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E444u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(456);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[3]));
    }

label_8004E448:
    ctx->pc = 0x8004E448u;
    // 8004E448: stfs     f2, 460(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E448u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(460);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_8004E44C:
    ctx->pc = 0x8004E44Cu;
    // 8004E44C: stfs     f3, 464(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E44Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(464);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[3]));
    }

label_8004E450:
    ctx->pc = 0x8004E450u;
    // 8004E450: stfs     f3, 468(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E450u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(468);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[3]));
    }

label_8004E454:
    ctx->pc = 0x8004E454u;
    // 8004E454: stfs     f3, 472(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E454u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(472);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[3]));
    }

label_8004E458:
    ctx->pc = 0x8004E458u;
    // 8004E458: stfs     f3, 476(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E458u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(476);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[3]));
    }

label_8004E45C:
    ctx->pc = 0x8004E45Cu;
    // 8004E45C: stfs     f2, 480(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E45Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(480);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_8004E460:
    ctx->pc = 0x8004E460u;
    // 8004E460: fmuls   f0, f1, f4
    if (!ppc_fp_available_inline(ctx, 0x8004E460u)) return;
    ppc_fmuls(ctx, 0, 1, 4);

label_8004E464:
    ctx->pc = 0x8004E464u;
    // 8004E464: stfs     f0, 484(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E464u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(484);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004E468:
    ctx->pc = 0x8004E468u;
    // 8004E468: addi    r3, r1, 488
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(488);

label_8004E46C:
    ctx->pc = 0x8004E46Cu;
    // 8004E46C: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8004E470:
    ctx->pc = 0x8004E470u;
    // 8004E470: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004E474:
    ctx->pc = 0x8004E474u;
    // 8004E474: bl      0x80247860
    {
            ctx->lr = 0x8004E478u;
            ctx->pc = 0x80247860u;
            return;
    }

label_8004E478:
    ctx->pc = 0x8004E478u;
    ctx->downcount -= 4;
    // 8004E478: addi    r3, r1, 248
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(248);

label_8004E47C:
    ctx->pc = 0x8004E47Cu;
    // 8004E47C: addi    r4, r1, 488
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(488);

label_8004E480:
    ctx->pc = 0x8004E480u;
    // 8004E480: or   r5, r4, r4
    {
        ctx->gpr[5] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8004E484:
    ctx->pc = 0x8004E484u;
    // 8004E484: bl      0x80247860
    {
            ctx->lr = 0x8004E488u;
            ctx->pc = 0x80247860u;
            return;
    }

label_8004E488:
    ctx->pc = 0x8004E488u;
    ctx->downcount -= 10;
    // 8004E488: lfs     f0, -31276(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004E488u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31276);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004E48C:
    ctx->pc = 0x8004E48Cu;
    // 8004E48C: stfs     f0, 520(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E48Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(520);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004E490:
    ctx->pc = 0x8004E490u;
    // 8004E490: stfs     f0, 524(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E490u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(524);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004E494:
    ctx->pc = 0x8004E494u;
    // 8004E494: stfs     f0, 528(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E494u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(528);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004E498:
    ctx->pc = 0x8004E498u;
    // 8004E498: lfs     f0, -31280(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004E498u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31280);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004E49C:
    ctx->pc = 0x8004E49Cu;
    // 8004E49C: stfs     f0, 532(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E49Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(532);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004E4A0:
    ctx->pc = 0x8004E4A0u;
    // 8004E4A0: addi    r3, r1, 440
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(440);

label_8004E4A4:
    ctx->pc = 0x8004E4A4u;
    // 8004E4A4: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8004E4A8:
    ctx->pc = 0x8004E4A8u;
    // 8004E4A8: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004E4AC:
    ctx->pc = 0x8004E4ACu;
    // 8004E4AC: bl      0x80247860
    {
            ctx->lr = 0x8004E4B0u;
            ctx->pc = 0x80247860u;
            return;
    }

label_8004E4B0:
    ctx->pc = 0x8004E4B0u;
    ctx->downcount -= 4;
    // 8004E4B0: addi    r3, r1, 200
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(200);

label_8004E4B4:
    ctx->pc = 0x8004E4B4u;
    // 8004E4B4: addi    r4, r1, 440
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(440);

label_8004E4B8:
    ctx->pc = 0x8004E4B8u;
    // 8004E4B8: or   r5, r4, r4
    {
        ctx->gpr[5] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8004E4BC:
    ctx->pc = 0x8004E4BCu;
    // 8004E4BC: bl      0x80247860
    {
            ctx->lr = 0x8004E4C0u;
            ctx->pc = 0x80247860u;
            return;
    }

label_8004E4C0:
    ctx->pc = 0x8004E4C0u;
    ctx->downcount -= 10;
    // 8004E4C0: lfs     f0, -31276(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004E4C0u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31276);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004E4C4:
    ctx->pc = 0x8004E4C4u;
    // 8004E4C4: stfs     f0, 472(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E4C4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(472);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004E4C8:
    ctx->pc = 0x8004E4C8u;
    // 8004E4C8: stfs     f0, 476(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E4C8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(476);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004E4CC:
    ctx->pc = 0x8004E4CCu;
    // 8004E4CC: stfs     f0, 480(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E4CCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(480);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004E4D0:
    ctx->pc = 0x8004E4D0u;
    // 8004E4D0: lfs     f0, -31280(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004E4D0u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31280);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004E4D4:
    ctx->pc = 0x8004E4D4u;
    // 8004E4D4: stfs     f0, 484(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E4D4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(484);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004E4D8:
    ctx->pc = 0x8004E4D8u;
    // 8004E4D8: addi    r3, r1, 488
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(488);

label_8004E4DC:
    ctx->pc = 0x8004E4DCu;
    // 8004E4DC: lwz     r4, -25608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004E4E0:
    ctx->pc = 0x8004E4E0u;
    // 8004E4E0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004E4E4:
    ctx->pc = 0x8004E4E4u;
    // 8004E4E4: bl      0x8025DAD0
    {
            ctx->lr = 0x8004E4E8u;
            ctx->pc = 0x8025DAD0u;
            return;
    }

label_8004E4E8:
    ctx->pc = 0x8004E4E8u;
    ctx->downcount -= 7;
    // 8004E4E8: lwz     r3, -25600(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25600);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004E4EC:
    ctx->pc = 0x8004E4ECu;
    // 8004E4EC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004E4F0:
    ctx->pc = 0x8004E4F0u;
    // 8004E4F0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004E4F4:
    ctx->pc = 0x8004E4F4u;
    // 8004E4F4: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004E4F8:
    ctx->pc = 0x8004E4F8u;
    // 8004E4F8: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004E4FC:
    ctx->pc = 0x8004E4FCu;
    // 8004E4FC: lwz     r8, -25608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25608);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8004E500:
    ctx->pc = 0x8004E500u;
    // 8004E500: bl      0x80258880
    {
            ctx->lr = 0x8004E504u;
            ctx->pc = 0x80258880u;
            return;
    }

label_8004E504:
    ctx->pc = 0x8004E504u;
    ctx->downcount -= 5;
    // 8004E504: addi    r3, r1, 440
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(440);

label_8004E508:
    ctx->pc = 0x8004E508u;
    // 8004E508: lwz     r4, -25608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004E50C:
    ctx->pc = 0x8004E50Cu;
    // 8004E50C: addi    r4, r4, 3
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(3);

label_8004E510:
    ctx->pc = 0x8004E510u;
    // 8004E510: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004E514:
    ctx->pc = 0x8004E514u;
    // 8004E514: bl      0x8025DAD0
    {
            ctx->lr = 0x8004E518u;
            ctx->pc = 0x8025DAD0u;
            return;
    }

label_8004E518:
    ctx->pc = 0x8004E518u;
    ctx->downcount -= 9;
    // 8004E518: lwz     r3, -25600(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25600);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004E51C:
    ctx->pc = 0x8004E51Cu;
    // 8004E51C: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_8004E520:
    ctx->pc = 0x8004E520u;
    // 8004E520: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004E524:
    ctx->pc = 0x8004E524u;
    // 8004E524: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004E528:
    ctx->pc = 0x8004E528u;
    // 8004E528: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004E52C:
    ctx->pc = 0x8004E52Cu;
    // 8004E52C: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004E530:
    ctx->pc = 0x8004E530u;
    // 8004E530: lwz     r8, -25608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25608);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8004E534:
    ctx->pc = 0x8004E534u;
    // 8004E534: addi    r8, r8, 3
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(3);

label_8004E538:
    ctx->pc = 0x8004E538u;
    // 8004E538: bl      0x80258880
    {
            ctx->lr = 0x8004E53Cu;
            ctx->pc = 0x80258880u;
            return;
    }

label_8004E53C:
    ctx->pc = 0x8004E53Cu;
    ctx->downcount -= 2;
    // 8004E53C: addi    r3, r1, 28
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(28);

label_8004E540:
    ctx->pc = 0x8004E540u;
    // 8004E540: bl      0x8006C6F4
    {
            ctx->lr = 0x8004E544u;
            ctx->pc = 0x8006C6F4u;
            return;
    }

label_8004E544:
    ctx->pc = 0x8004E544u;
    ctx->downcount -= 4;
    // 8004E544: lwz     r5, -25596(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25596);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8004E548:
    ctx->pc = 0x8004E548u;
    // 8004E548: lwz     r4, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004E54C:
    ctx->pc = 0x8004E54Cu;
    // 8004E54C: cmplwi  r4, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004E550:
    ctx->pc = 0x8004E550u;
    // 8004E550: bc    12, 2, 0x8004E578
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004E578;
        }
    }

label_8004E554:
    ctx->pc = 0x8004E554u;
    ctx->downcount -= 4;
    // 8004E554: addi    r3, r4, 32
    ctx->gpr[3] = ctx->gpr[4] + (u32)(s32)(32);

label_8004E558:
    ctx->pc = 0x8004E558u;
    // 8004E558: lbz     r0, 72(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(72);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8004E55C:
    ctx->pc = 0x8004E55Cu;
    // 8004E55C: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8004E560:
    ctx->pc = 0x8004E560u;
    // 8004E560: bc    12, 2, 0x8004E570
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8004E570;
        }
    }

label_8004E564:
    ctx->pc = 0x8004E564u;
    ctx->downcount -= 2;
    // 8004E564: lwz     r4, 64(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(64);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004E568:
    ctx->pc = 0x8004E568u;
    // 8004E568: bl      0x8025B0B8
    {
            ctx->lr = 0x8004E56Cu;
            ctx->pc = 0x8025B0B8u;
            return;
    }

label_8004E56C:
    ctx->pc = 0x8004E56Cu;
    ctx->downcount -= 1;
    // 8004E56C: b       0x8004E578
    {
            goto label_8004E578;
    }

label_8004E570:
    ctx->pc = 0x8004E570u;
    ctx->downcount -= 2;
    // 8004E570: or   r4, r5, r5
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8004E574:
    ctx->pc = 0x8004E574u;
    // 8004E574: bl      0x8025B260
    {
            ctx->lr = 0x8004E578u;
            ctx->pc = 0x8025B260u;
            return;
    }

label_8004E578:
    ctx->pc = 0x8004E578u;
    ctx->downcount -= 3;
    // 8004E578: addi    r3, r1, 20
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(20);

label_8004E57C:
    ctx->pc = 0x8004E57Cu;
    // 8004E57C: addi    r4, r1, 16
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(16);

label_8004E580:
    ctx->pc = 0x8004E580u;
    // 8004E580: bl      0x8006CCA0
    {
            ctx->lr = 0x8004E584u;
            ctx->pc = 0x8006CCA0u;
            return;
    }

label_8004E584:
    ctx->pc = 0x8004E584u;
    ctx->downcount -= 4;
    // 8004E584: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8004E588:
    ctx->pc = 0x8004E588u;
    // 8004E588: addi    r4, r1, 80
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(80);

label_8004E58C:
    ctx->pc = 0x8004E58Cu;
    // 8004E58C: li      r5, -1
    ctx->gpr[5] = (u32)(s32)(-1);

label_8004E590:
    ctx->pc = 0x8004E590u;
    // 8004E590: bl      0x8025BBF4
    {
            ctx->lr = 0x8004E594u;
            ctx->pc = 0x8025BBF4u;
            return;
    }

label_8004E594:
    ctx->pc = 0x8004E594u;
    ctx->downcount -= 6;
    // 8004E594: lwz     r3, -25612(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25612);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004E598:
    ctx->pc = 0x8004E598u;
    // 8004E598: lwz     r4, -25600(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25600);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004E59C:
    ctx->pc = 0x8004E59Cu;
    // 8004E59C: addi    r4, r4, 2
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(2);

label_8004E5A0:
    ctx->pc = 0x8004E5A0u;
    // 8004E5A0: lwz     r5, -25596(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25596);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8004E5A4:
    ctx->pc = 0x8004E5A4u;
    // 8004E5A4: addi    r5, r5, 1
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(1);

label_8004E5A8:
    ctx->pc = 0x8004E5A8u;
    // 8004E5A8: bl      0x8025BF28
    {
            ctx->lr = 0x8004E5ACu;
            ctx->pc = 0x8025BF28u;
            return;
    }

label_8004E5AC:
    ctx->pc = 0x8004E5ACu;
    ctx->downcount -= 23;
    // 8004E5AC: lfs     f3, -31192(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004E5ACu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31192);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8004E5B0:
    ctx->pc = 0x8004E5B0u;
    // 8004E5B0: stfs     f3, 392(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E5B0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(392);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[3]));
    }

label_8004E5B4:
    ctx->pc = 0x8004E5B4u;
    // 8004E5B4: lfs     f2, -31276(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004E5B4u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31276);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8004E5B8:
    ctx->pc = 0x8004E5B8u;
    // 8004E5B8: stfs     f2, 396(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E5B8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(396);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_8004E5BC:
    ctx->pc = 0x8004E5BCu;
    // 8004E5BC: stfs     f2, 400(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E5BCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(400);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_8004E5C0:
    ctx->pc = 0x8004E5C0u;
    // 8004E5C0: lfs     f1, -25520(r13)
    if (!ppc_fp_available_inline(ctx, 0x8004E5C0u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25520);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8004E5C4:
    ctx->pc = 0x8004E5C4u;
    // 8004E5C4: lfs     f0, 20(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E5C4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004E5C8:
    ctx->pc = 0x8004E5C8u;
    // 8004E5C8: fmadds f0, f3, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8004E5C8u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[3], ctx->fpr[1], ctx->fpr[0], true, false, false, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_8004E5CC:
    ctx->pc = 0x8004E5CCu;
    // 8004E5CC: stfs     f0, 404(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E5CCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(404);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004E5D0:
    ctx->pc = 0x8004E5D0u;
    // 8004E5D0: stfs     f2, 408(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E5D0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(408);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_8004E5D4:
    ctx->pc = 0x8004E5D4u;
    // 8004E5D4: stfs     f3, 412(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E5D4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(412);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[3]));
    }

label_8004E5D8:
    ctx->pc = 0x8004E5D8u;
    // 8004E5D8: stfs     f2, 416(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E5D8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(416);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_8004E5DC:
    ctx->pc = 0x8004E5DCu;
    // 8004E5DC: stfs     f2, 420(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E5DCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(420);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_8004E5E0:
    ctx->pc = 0x8004E5E0u;
    // 8004E5E0: stfs     f2, 424(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E5E0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(424);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_8004E5E4:
    ctx->pc = 0x8004E5E4u;
    // 8004E5E4: stfs     f2, 428(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E5E4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(428);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_8004E5E8:
    ctx->pc = 0x8004E5E8u;
    // 8004E5E8: stfs     f3, 432(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E5E8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(432);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[3]));
    }

label_8004E5EC:
    ctx->pc = 0x8004E5ECu;
    // 8004E5EC: lfs     f0, -25516(r13)
    if (!ppc_fp_available_inline(ctx, 0x8004E5ECu)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25516);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004E5F0:
    ctx->pc = 0x8004E5F0u;
    // 8004E5F0: fmuls   f0, f3, f0
    if (!ppc_fp_available_inline(ctx, 0x8004E5F0u)) return;
    ppc_fmuls(ctx, 0, 3, 0);

label_8004E5F4:
    ctx->pc = 0x8004E5F4u;
    // 8004E5F4: stfs     f0, 436(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E5F4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(436);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004E5F8:
    ctx->pc = 0x8004E5F8u;
    // 8004E5F8: addi    r3, r1, 296
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(296);

label_8004E5FC:
    ctx->pc = 0x8004E5FCu;
    // 8004E5FC: li      r4, 121
    ctx->gpr[4] = (u32)(s32)(121);

label_8004E600:
    ctx->pc = 0x8004E600u;
    // 8004E600: lfs     f1, -31184(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004E600u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31184);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8004E604:
    ctx->pc = 0x8004E604u;
    // 8004E604: bl      0x80247A74
    {
            ctx->lr = 0x8004E608u;
            ctx->pc = 0x80247A74u;
            return;
    }

label_8004E608:
    ctx->pc = 0x8004E608u;
    ctx->downcount -= 4;
    // 8004E608: addi    r3, r1, 296
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(296);

label_8004E60C:
    ctx->pc = 0x8004E60Cu;
    // 8004E60C: addi    r4, r1, 392
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(392);

label_8004E610:
    ctx->pc = 0x8004E610u;
    // 8004E610: or   r5, r4, r4
    {
        ctx->gpr[5] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8004E614:
    ctx->pc = 0x8004E614u;
    // 8004E614: bl      0x80247860
    {
            ctx->lr = 0x8004E618u;
            ctx->pc = 0x80247860u;
            return;
    }

label_8004E618:
    ctx->pc = 0x8004E618u;
    ctx->downcount -= 4;
    // 8004E618: addi    r3, r1, 392
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(392);

label_8004E61C:
    ctx->pc = 0x8004E61Cu;
    // 8004E61C: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8004E620:
    ctx->pc = 0x8004E620u;
    // 8004E620: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8004E624:
    ctx->pc = 0x8004E624u;
    // 8004E624: bl      0x80247860
    {
            ctx->lr = 0x8004E628u;
            ctx->pc = 0x80247860u;
            return;
    }

label_8004E628:
    ctx->pc = 0x8004E628u;
    ctx->downcount -= 4;
    // 8004E628: addi    r3, r1, 152
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(152);

label_8004E62C:
    ctx->pc = 0x8004E62Cu;
    // 8004E62C: addi    r4, r1, 392
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(392);

label_8004E630:
    ctx->pc = 0x8004E630u;
    // 8004E630: or   r5, r4, r4
    {
        ctx->gpr[5] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8004E634:
    ctx->pc = 0x8004E634u;
    // 8004E634: bl      0x80247860
    {
            ctx->lr = 0x8004E638u;
            ctx->pc = 0x80247860u;
            return;
    }

label_8004E638:
    ctx->pc = 0x8004E638u;
    ctx->downcount -= 11;
    // 8004E638: lfs     f0, -31276(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004E638u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31276);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004E63C:
    ctx->pc = 0x8004E63Cu;
    // 8004E63C: stfs     f0, 424(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E63Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(424);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004E640:
    ctx->pc = 0x8004E640u;
    // 8004E640: stfs     f0, 428(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E640u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(428);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004E644:
    ctx->pc = 0x8004E644u;
    // 8004E644: stfs     f0, 432(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E644u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(432);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004E648:
    ctx->pc = 0x8004E648u;
    // 8004E648: lfs     f0, -31280(r2)
    if (!ppc_fp_available_inline(ctx, 0x8004E648u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31280);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8004E64C:
    ctx->pc = 0x8004E64Cu;
    // 8004E64C: stfs     f0, 436(r1)
    if (!ppc_fp_available_inline(ctx, 0x8004E64Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(436);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8004E650:
    ctx->pc = 0x8004E650u;
    // 8004E650: addi    r3, r1, 392
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(392);

label_8004E654:
    ctx->pc = 0x8004E654u;
    // 8004E654: lwz     r4, -25608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004E658:
    ctx->pc = 0x8004E658u;
    // 8004E658: addi    r4, r4, 6
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(6);

label_8004E65C:
    ctx->pc = 0x8004E65Cu;
    // 8004E65C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004E660:
    ctx->pc = 0x8004E660u;
    // 8004E660: bl      0x8025DAD0
    {
            ctx->lr = 0x8004E664u;
            ctx->pc = 0x8025DAD0u;
            return;
    }

label_8004E664:
    ctx->pc = 0x8004E664u;
    ctx->downcount -= 9;
    // 8004E664: lwz     r3, -25600(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25600);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004E668:
    ctx->pc = 0x8004E668u;
    // 8004E668: addi    r3, r3, 2
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(2);

label_8004E66C:
    ctx->pc = 0x8004E66Cu;
    // 8004E66C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004E670:
    ctx->pc = 0x8004E670u;
    // 8004E670: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004E674:
    ctx->pc = 0x8004E674u;
    // 8004E674: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8004E678:
    ctx->pc = 0x8004E678u;
    // 8004E678: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8004E67C:
    ctx->pc = 0x8004E67Cu;
    // 8004E67C: lwz     r8, -25608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25608);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8004E680:
    ctx->pc = 0x8004E680u;
    // 8004E680: addi    r8, r8, 6
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(6);

label_8004E684:
    ctx->pc = 0x8004E684u;
    // 8004E684: bl      0x80258880
    {
            ctx->lr = 0x8004E688u;
            ctx->pc = 0x80258880u;
            return;
    }

label_8004E688:
    ctx->pc = 0x8004E688u;
    ctx->downcount -= 12;
    // 8004E688: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8004E68C:
    ctx->pc = 0x8004E68Cu;
    // 8004E68C: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004E690:
    ctx->pc = 0x8004E690u;
    // 8004E690: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8004E694:
    ctx->pc = 0x8004E694u;
    // 8004E694: lwz     r3, -25592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25592);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004E698:
    ctx->pc = 0x8004E698u;
    // 8004E698: lwz     r4, -25612(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25612);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004E69C:
    ctx->pc = 0x8004E69Cu;
    // 8004E69C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004E6A0:
    ctx->pc = 0x8004E6A0u;
    // 8004E6A0: li      r6, 2
    ctx->gpr[6] = (u32)(s32)(2);

label_8004E6A4:
    ctx->pc = 0x8004E6A4u;
    // 8004E6A4: li      r7, 2
    ctx->gpr[7] = (u32)(s32)(2);

label_8004E6A8:
    ctx->pc = 0x8004E6A8u;
    // 8004E6A8: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8004E6AC:
    ctx->pc = 0x8004E6ACu;
    // 8004E6AC: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_8004E6B0:
    ctx->pc = 0x8004E6B0u;
    // 8004E6B0: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_8004E6B4:
    ctx->pc = 0x8004E6B4u;
    // 8004E6B4: bl      0x8025BB58
    {
            ctx->lr = 0x8004E6B8u;
            ctx->pc = 0x8025BB58u;
            return;
    }

label_8004E6B8:
    ctx->pc = 0x8004E6B8u;
    ctx->downcount -= 4;
    // 8004E6B8: lwz     r3, -25612(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25612);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004E6BC:
    ctx->pc = 0x8004E6BCu;
    // 8004E6BC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8004E6C0:
    ctx->pc = 0x8004E6C0u;
    // 8004E6C0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8004E6C4:
    ctx->pc = 0x8004E6C4u;
    // 8004E6C4: bl      0x8025BD54
    {
            ctx->lr = 0x8004E6C8u;
            ctx->pc = 0x8025BD54u;
            return;
    }

label_8004E6C8:
    ctx->pc = 0x8004E6C8u;
    ctx->downcount -= 6;
    // 8004E6C8: lwz     r3, -25612(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25612);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8004E6CC:
    ctx->pc = 0x8004E6CCu;
    // 8004E6CC: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_8004E6D0:
    ctx->pc = 0x8004E6D0u;
    // 8004E6D0: lwz     r4, -25600(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25600);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8004E6D4:
    ctx->pc = 0x8004E6D4u;
    // 8004E6D4: addi    r4, r4, 3
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(3);

label_8004E6D8:
    ctx->pc = 0x8004E6D8u;
    // 8004E6D8: lwz     r5, -25596(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25596);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8004E6DC:
    ctx->pc = 0x8004E6DCu;
    // 8004E6DC: addi    r5, r5, 1
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(1);

    ctx->pc = 0x8004E6E0u;
    return;
return_dispatch_8004A6E0:
    if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) return;
    switch (ctx->pc) {
    case 0x8004A72Cu: goto label_8004A72C;
    case 0x8004A76Cu: goto label_8004A76C;
    case 0x8004A770u: goto label_8004A770;
    case 0x8004A7A0u: goto label_8004A7A0;
    case 0x8004A7BCu: goto label_8004A7BC;
    case 0x8004A7D0u: goto label_8004A7D0;
    case 0x8004A840u: goto label_8004A840;
    case 0x8004A868u: goto label_8004A868;
    case 0x8004A888u: goto label_8004A888;
    case 0x8004A8B4u: goto label_8004A8B4;
    case 0x8004A8ECu: goto label_8004A8EC;
    case 0x8004A934u: goto label_8004A934;
    case 0x8004A948u: goto label_8004A948;
    case 0x8004A950u: goto label_8004A950;
    case 0x8004A984u: goto label_8004A984;
    case 0x8004AA3Cu: goto label_8004AA3C;
    case 0x8004AA68u: goto label_8004AA68;
    case 0x8004AA74u: goto label_8004AA74;
    case 0x8004AA78u: goto label_8004AA78;
    case 0x8004AAC0u: goto label_8004AAC0;
    case 0x8004AACCu: goto label_8004AACC;
    case 0x8004AB88u: goto label_8004AB88;
    case 0x8004AB90u: goto label_8004AB90;
    case 0x8004ABBCu: goto label_8004ABBC;
    case 0x8004ABC8u: goto label_8004ABC8;
    case 0x8004ABE0u: goto label_8004ABE0;
    case 0x8004ABE8u: goto label_8004ABE8;
    case 0x8004ABECu: goto label_8004ABEC;
    case 0x8004ABF0u: goto label_8004ABF0;
    case 0x8004ABF4u: goto label_8004ABF4;
    case 0x8004AD54u: goto label_8004AD54;
    case 0x8004AD68u: goto label_8004AD68;
    case 0x8004ADB4u: goto label_8004ADB4;
    case 0x8004ADB8u: goto label_8004ADB8;
    case 0x8004AF38u: goto label_8004AF38;
    case 0x8004AFF4u: goto label_8004AFF4;
    case 0x8004AFF8u: goto label_8004AFF8;
    case 0x8004B174u: goto label_8004B174;
    case 0x8004B198u: goto label_8004B198;
    case 0x8004B20Cu: goto label_8004B20C;
    case 0x8004B234u: goto label_8004B234;
    case 0x8004B244u: goto label_8004B244;
    case 0x8004B25Cu: goto label_8004B25C;
    case 0x8004B290u: goto label_8004B290;
    case 0x8004B2B4u: goto label_8004B2B4;
    case 0x8004B2CCu: goto label_8004B2CC;
    case 0x8004B2ECu: goto label_8004B2EC;
    case 0x8004B410u: goto label_8004B410;
    case 0x8004B474u: goto label_8004B474;
    case 0x8004B498u: goto label_8004B498;
    case 0x8004B4C4u: goto label_8004B4C4;
    case 0x8004B4F0u: goto label_8004B4F0;
    case 0x8004B6A4u: goto label_8004B6A4;
    case 0x8004B6A8u: goto label_8004B6A8;
    case 0x8004B79Cu: goto label_8004B79C;
    case 0x8004B7DCu: goto label_8004B7DC;
    case 0x8004B828u: goto label_8004B828;
    case 0x8004C394u: goto label_8004C394;
    case 0x8004C480u: goto label_8004C480;
    case 0x8004C488u: goto label_8004C488;
    case 0x8004C4A4u: goto label_8004C4A4;
    case 0x8004C4B4u: goto label_8004C4B4;
    case 0x8004C4FCu: goto label_8004C4FC;
    case 0x8004C504u: goto label_8004C504;
    case 0x8004C528u: goto label_8004C528;
    case 0x8004C5A0u: goto label_8004C5A0;
    case 0x8004C5ECu: goto label_8004C5EC;
    case 0x8004C5FCu: goto label_8004C5FC;
    case 0x8004C60Cu: goto label_8004C60C;
    case 0x8004C660u: goto label_8004C660;
    case 0x8004C66Cu: goto label_8004C66C;
    case 0x8004C67Cu: goto label_8004C67C;
    case 0x8004C69Cu: goto label_8004C69C;
    case 0x8004C6C4u: goto label_8004C6C4;
    case 0x8004C6D4u: goto label_8004C6D4;
    case 0x8004C6ECu: goto label_8004C6EC;
    case 0x8004C708u: goto label_8004C708;
    case 0x8004C734u: goto label_8004C734;
    case 0x8004C748u: goto label_8004C748;
    case 0x8004C758u: goto label_8004C758;
    case 0x8004C78Cu: goto label_8004C78C;
    case 0x8004C7A4u: goto label_8004C7A4;
    case 0x8004C7B0u: goto label_8004C7B0;
    case 0x8004C7C8u: goto label_8004C7C8;
    case 0x8004C7E0u: goto label_8004C7E0;
    case 0x8004C7FCu: goto label_8004C7FC;
    case 0x8004C818u: goto label_8004C818;
    case 0x8004C830u: goto label_8004C830;
    case 0x8004C83Cu: goto label_8004C83C;
    case 0x8004C858u: goto label_8004C858;
    case 0x8004C874u: goto label_8004C874;
    case 0x8004C894u: goto label_8004C894;
    case 0x8004C8B4u: goto label_8004C8B4;
    case 0x8004C8E0u: goto label_8004C8E0;
    case 0x8004C8ECu: goto label_8004C8EC;
    case 0x8004C918u: goto label_8004C918;
    case 0x8004C924u: goto label_8004C924;
    case 0x8004C980u: goto label_8004C980;
    case 0x8004C9A4u: goto label_8004C9A4;
    case 0x8004CA08u: goto label_8004CA08;
    case 0x8004CA28u: goto label_8004CA28;
    case 0x8004CA44u: goto label_8004CA44;
    case 0x8004CA4Cu: goto label_8004CA4C;
    case 0x8004CA64u: goto label_8004CA64;
    case 0x8004CA80u: goto label_8004CA80;
    case 0x8004CA98u: goto label_8004CA98;
    case 0x8004CAB4u: goto label_8004CAB4;
    case 0x8004CAC0u: goto label_8004CAC0;
    case 0x8004CACCu: goto label_8004CACC;
    case 0x8004CADCu: goto label_8004CADC;
    case 0x8004CAFCu: goto label_8004CAFC;
    case 0x8004CB08u: goto label_8004CB08;
    case 0x8004CB24u: goto label_8004CB24;
    case 0x8004CB44u: goto label_8004CB44;
    case 0x8004CB60u: goto label_8004CB60;
    case 0x8004CB80u: goto label_8004CB80;
    case 0x8004CB94u: goto label_8004CB94;
    case 0x8004CBA8u: goto label_8004CBA8;
    case 0x8004CBBCu: goto label_8004CBBC;
    case 0x8004CBD4u: goto label_8004CBD4;
    case 0x8004CBE0u: goto label_8004CBE0;
    case 0x8004CBFCu: goto label_8004CBFC;
    case 0x8004CC1Cu: goto label_8004CC1C;
    case 0x8004CC38u: goto label_8004CC38;
    case 0x8004CC58u: goto label_8004CC58;
    case 0x8004CC6Cu: goto label_8004CC6C;
    case 0x8004CC84u: goto label_8004CC84;
    case 0x8004CC90u: goto label_8004CC90;
    case 0x8004CCACu: goto label_8004CCAC;
    case 0x8004CCCCu: goto label_8004CCCC;
    case 0x8004CCE8u: goto label_8004CCE8;
    case 0x8004CD08u: goto label_8004CD08;
    case 0x8004CD1Cu: goto label_8004CD1C;
    case 0x8004CD30u: goto label_8004CD30;
    case 0x8004CD48u: goto label_8004CD48;
    case 0x8004CD54u: goto label_8004CD54;
    case 0x8004CD70u: goto label_8004CD70;
    case 0x8004CD90u: goto label_8004CD90;
    case 0x8004CDACu: goto label_8004CDAC;
    case 0x8004CDCCu: goto label_8004CDCC;
    case 0x8004CDE0u: goto label_8004CDE0;
    case 0x8004CDF0u: goto label_8004CDF0;
    case 0x8004CE14u: goto label_8004CE14;
    case 0x8004CE28u: goto label_8004CE28;
    case 0x8004CE40u: goto label_8004CE40;
    case 0x8004CE58u: goto label_8004CE58;
    case 0x8004CE7Cu: goto label_8004CE7C;
    case 0x8004CEA4u: goto label_8004CEA4;
    case 0x8004CEB0u: goto label_8004CEB0;
    case 0x8004CEE4u: goto label_8004CEE4;
    case 0x8004CF0Cu: goto label_8004CF0C;
    case 0x8004CF1Cu: goto label_8004CF1C;
    case 0x8004CF40u: goto label_8004CF40;
    case 0x8004CF68u: goto label_8004CF68;
    case 0x8004CF78u: goto label_8004CF78;
    case 0x8004CFE0u: goto label_8004CFE0;
    case 0x8004D020u: goto label_8004D020;
    case 0x8004D028u: goto label_8004D028;
    case 0x8004D03Cu: goto label_8004D03C;
    case 0x8004D054u: goto label_8004D054;
    case 0x8004D06Cu: goto label_8004D06C;
    case 0x8004D07Cu: goto label_8004D07C;
    case 0x8004D098u: goto label_8004D098;
    case 0x8004D0B4u: goto label_8004D0B4;
    case 0x8004D0F4u: goto label_8004D0F4;
    case 0x8004D110u: goto label_8004D110;
    case 0x8004D118u: goto label_8004D118;
    case 0x8004D140u: goto label_8004D140;
    case 0x8004D14Cu: goto label_8004D14C;
    case 0x8004D158u: goto label_8004D158;
    case 0x8004D178u: goto label_8004D178;
    case 0x8004D194u: goto label_8004D194;
    case 0x8004D1B0u: goto label_8004D1B0;
    case 0x8004D1C0u: goto label_8004D1C0;
    case 0x8004D1D0u: goto label_8004D1D0;
    case 0x8004D200u: goto label_8004D200;
    case 0x8004D20Cu: goto label_8004D20C;
    case 0x8004D220u: goto label_8004D220;
    case 0x8004D238u: goto label_8004D238;
    case 0x8004D250u: goto label_8004D250;
    case 0x8004D260u: goto label_8004D260;
    case 0x8004D27Cu: goto label_8004D27C;
    case 0x8004D298u: goto label_8004D298;
    case 0x8004D2A0u: goto label_8004D2A0;
    case 0x8004D2C8u: goto label_8004D2C8;
    case 0x8004D2D4u: goto label_8004D2D4;
    case 0x8004D310u: goto label_8004D310;
    case 0x8004D320u: goto label_8004D320;
    case 0x8004D33Cu: goto label_8004D33C;
    case 0x8004D344u: goto label_8004D344;
    case 0x8004D358u: goto label_8004D358;
    case 0x8004D370u: goto label_8004D370;
    case 0x8004D388u: goto label_8004D388;
    case 0x8004D398u: goto label_8004D398;
    case 0x8004D3B4u: goto label_8004D3B4;
    case 0x8004D3D0u: goto label_8004D3D0;
    case 0x8004D428u: goto label_8004D428;
    case 0x8004D454u: goto label_8004D454;
    case 0x8004D464u: goto label_8004D464;
    case 0x8004D480u: goto label_8004D480;
    case 0x8004D488u: goto label_8004D488;
    case 0x8004D49Cu: goto label_8004D49C;
    case 0x8004D4B4u: goto label_8004D4B4;
    case 0x8004D4C4u: goto label_8004D4C4;
    case 0x8004D4E4u: goto label_8004D4E4;
    case 0x8004D4FCu: goto label_8004D4FC;
    case 0x8004D514u: goto label_8004D514;
    case 0x8004D530u: goto label_8004D530;
    case 0x8004D54Cu: goto label_8004D54C;
    case 0x8004D578u: goto label_8004D578;
    case 0x8004D584u: goto label_8004D584;
    case 0x8004D5B8u: goto label_8004D5B8;
    case 0x8004D5D0u: goto label_8004D5D0;
    case 0x8004D638u: goto label_8004D638;
    case 0x8004D654u: goto label_8004D654;
    case 0x8004D65Cu: goto label_8004D65C;
    case 0x8004D670u: goto label_8004D670;
    case 0x8004D680u: goto label_8004D680;
    case 0x8004D698u: goto label_8004D698;
    case 0x8004D6A4u: goto label_8004D6A4;
    case 0x8004D6BCu: goto label_8004D6BC;
    case 0x8004D6D8u: goto label_8004D6D8;
    case 0x8004D6F4u: goto label_8004D6F4;
    case 0x8004D700u: goto label_8004D700;
    case 0x8004D728u: goto label_8004D728;
    case 0x8004D734u: goto label_8004D734;
    case 0x8004D7C8u: goto label_8004D7C8;
    case 0x8004D7D4u: goto label_8004D7D4;
    case 0x8004D7DCu: goto label_8004D7DC;
    case 0x8004D7F0u: goto label_8004D7F0;
    case 0x8004D800u: goto label_8004D800;
    case 0x8004D818u: goto label_8004D818;
    case 0x8004D830u: goto label_8004D830;
    case 0x8004D84Cu: goto label_8004D84C;
    case 0x8004D868u: goto label_8004D868;
    case 0x8004D904u: goto label_8004D904;
    case 0x8004D934u: goto label_8004D934;
    case 0x8004D948u: goto label_8004D948;
    case 0x8004D958u: goto label_8004D958;
    case 0x8004D968u: goto label_8004D968;
    case 0x8004D998u: goto label_8004D998;
    case 0x8004D9A0u: goto label_8004D9A0;
    case 0x8004D9CCu: goto label_8004D9CC;
    case 0x8004D9D8u: goto label_8004D9D8;
    case 0x8004D9ECu: goto label_8004D9EC;
    case 0x8004DA08u: goto label_8004DA08;
    case 0x8004DA1Cu: goto label_8004DA1C;
    case 0x8004DA34u: goto label_8004DA34;
    case 0x8004DA44u: goto label_8004DA44;
    case 0x8004DA5Cu: goto label_8004DA5C;
    case 0x8004DA78u: goto label_8004DA78;
    case 0x8004DA94u: goto label_8004DA94;
    case 0x8004DA9Cu: goto label_8004DA9C;
    case 0x8004DB20u: goto label_8004DB20;
    case 0x8004DB3Cu: goto label_8004DB3C;
    case 0x8004DB44u: goto label_8004DB44;
    case 0x8004DB50u: goto label_8004DB50;
    case 0x8004DB64u: goto label_8004DB64;
    case 0x8004DB7Cu: goto label_8004DB7C;
    case 0x8004DB94u: goto label_8004DB94;
    case 0x8004DBA4u: goto label_8004DBA4;
    case 0x8004DBC0u: goto label_8004DBC0;
    case 0x8004DBDCu: goto label_8004DBDC;
    case 0x8004DCECu: goto label_8004DCEC;
    case 0x8004DCF8u: goto label_8004DCF8;
    case 0x8004DD14u: goto label_8004DD14;
    case 0x8004DD20u: goto label_8004DD20;
    case 0x8004DD38u: goto label_8004DD38;
    case 0x8004DD48u: goto label_8004DD48;
    case 0x8004DDA4u: goto label_8004DDA4;
    case 0x8004DDB4u: goto label_8004DDB4;
    case 0x8004DE04u: goto label_8004DE04;
    case 0x8004DE2Cu: goto label_8004DE2C;
    case 0x8004DE38u: goto label_8004DE38;
    case 0x8004DE50u: goto label_8004DE50;
    case 0x8004DE64u: goto label_8004DE64;
    case 0x8004DE70u: goto label_8004DE70;
    case 0x8004DE80u: goto label_8004DE80;
    case 0x8004DE9Cu: goto label_8004DE9C;
    case 0x8004DEA4u: goto label_8004DEA4;
    case 0x8004DECCu: goto label_8004DECC;
    case 0x8004DED8u: goto label_8004DED8;
    case 0x8004DEECu: goto label_8004DEEC;
    case 0x8004DF0Cu: goto label_8004DF0C;
    case 0x8004DF28u: goto label_8004DF28;
    case 0x8004DF38u: goto label_8004DF38;
    case 0x8004DF48u: goto label_8004DF48;
    case 0x8004DF58u: goto label_8004DF58;
    case 0x8004DF68u: goto label_8004DF68;
    case 0x8004DF98u: goto label_8004DF98;
    case 0x8004DFACu: goto label_8004DFAC;
    case 0x8004DFBCu: goto label_8004DFBC;
    case 0x8004DFCCu: goto label_8004DFCC;
    case 0x8004DFF0u: goto label_8004DFF0;
    case 0x8004E00Cu: goto label_8004E00C;
    case 0x8004E01Cu: goto label_8004E01C;
    case 0x8004E02Cu: goto label_8004E02C;
    case 0x8004E05Cu: goto label_8004E05C;
    case 0x8004E098u: goto label_8004E098;
    case 0x8004E0A4u: goto label_8004E0A4;
    case 0x8004E0B0u: goto label_8004E0B0;
    case 0x8004E0B8u: goto label_8004E0B8;
    case 0x8004E0D0u: goto label_8004E0D0;
    case 0x8004E0E4u: goto label_8004E0E4;
    case 0x8004E0FCu: goto label_8004E0FC;
    case 0x8004E114u: goto label_8004E114;
    case 0x8004E124u: goto label_8004E124;
    case 0x8004E140u: goto label_8004E140;
    case 0x8004E15Cu: goto label_8004E15C;
    case 0x8004E178u: goto label_8004E178;
    case 0x8004E190u: goto label_8004E190;
    case 0x8004E1A8u: goto label_8004E1A8;
    case 0x8004E1B8u: goto label_8004E1B8;
    case 0x8004E1D4u: goto label_8004E1D4;
    case 0x8004E1F0u: goto label_8004E1F0;
    case 0x8004E204u: goto label_8004E204;
    case 0x8004E21Cu: goto label_8004E21C;
    case 0x8004E234u: goto label_8004E234;
    case 0x8004E244u: goto label_8004E244;
    case 0x8004E260u: goto label_8004E260;
    case 0x8004E27Cu: goto label_8004E27C;
    case 0x8004E38Cu: goto label_8004E38C;
    case 0x8004E3A0u: goto label_8004E3A0;
    case 0x8004E3B0u: goto label_8004E3B0;
    case 0x8004E3C0u: goto label_8004E3C0;
    case 0x8004E3D0u: goto label_8004E3D0;
    case 0x8004E478u: goto label_8004E478;
    case 0x8004E488u: goto label_8004E488;
    case 0x8004E4B0u: goto label_8004E4B0;
    case 0x8004E4C0u: goto label_8004E4C0;
    case 0x8004E4E8u: goto label_8004E4E8;
    case 0x8004E504u: goto label_8004E504;
    case 0x8004E518u: goto label_8004E518;
    case 0x8004E53Cu: goto label_8004E53C;
    case 0x8004E544u: goto label_8004E544;
    case 0x8004E56Cu: goto label_8004E56C;
    case 0x8004E578u: goto label_8004E578;
    case 0x8004E584u: goto label_8004E584;
    case 0x8004E594u: goto label_8004E594;
    case 0x8004E5ACu: goto label_8004E5AC;
    case 0x8004E608u: goto label_8004E608;
    case 0x8004E618u: goto label_8004E618;
    case 0x8004E628u: goto label_8004E628;
    case 0x8004E638u: goto label_8004E638;
    case 0x8004E664u: goto label_8004E664;
    case 0x8004E688u: goto label_8004E688;
    case 0x8004E6B8u: goto label_8004E6B8;
    case 0x8004E6C8u: goto label_8004E6C8;
    default: return;
    }
}

