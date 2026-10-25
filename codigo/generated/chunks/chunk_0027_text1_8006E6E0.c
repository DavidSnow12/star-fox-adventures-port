// DolRecomp output
#include "../generated.h"

static void loop_8006EDA8(CPUState* ctx) {
label_8006EDA8:
    ctx->downcount -= 37;
    // 8006EDA8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

    ctx->pc = 0x8006EDACu;
    // 8006EDAC: stb     r4, 16(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(16);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

    // 8006EDB0: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

    ctx->pc = 0x8006EDB4u;
    // 8006EDB4: stb     r3, 17(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(17);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

    ctx->pc = 0x8006EDB8u;
    // 8006EDB8: stb     r4, 36(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(36);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

    ctx->pc = 0x8006EDBCu;
    // 8006EDBC: stb     r3, 37(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(37);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

    ctx->pc = 0x8006EDC0u;
    // 8006EDC0: stb     r4, 56(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(56);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

    ctx->pc = 0x8006EDC4u;
    // 8006EDC4: stb     r3, 57(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(57);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

    ctx->pc = 0x8006EDC8u;
    // 8006EDC8: stb     r4, 76(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(76);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

    ctx->pc = 0x8006EDCCu;
    // 8006EDCC: stb     r3, 77(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(77);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

    ctx->pc = 0x8006EDD0u;
    // 8006EDD0: stb     r4, 96(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(96);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

    ctx->pc = 0x8006EDD4u;
    // 8006EDD4: stb     r3, 97(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(97);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

    ctx->pc = 0x8006EDD8u;
    // 8006EDD8: stb     r4, 116(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(116);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

    ctx->pc = 0x8006EDDCu;
    // 8006EDDC: stb     r3, 117(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(117);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

    ctx->pc = 0x8006EDE0u;
    // 8006EDE0: stb     r4, 136(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(136);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

    ctx->pc = 0x8006EDE4u;
    // 8006EDE4: stb     r3, 137(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(137);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

    ctx->pc = 0x8006EDE8u;
    // 8006EDE8: stb     r4, 156(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(156);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

    ctx->pc = 0x8006EDECu;
    // 8006EDEC: stb     r3, 157(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(157);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

    ctx->pc = 0x8006EDF0u;
    // 8006EDF0: stb     r4, 176(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(176);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

    ctx->pc = 0x8006EDF4u;
    // 8006EDF4: stb     r3, 177(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(177);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

    ctx->pc = 0x8006EDF8u;
    // 8006EDF8: stb     r4, 196(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(196);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

    ctx->pc = 0x8006EDFCu;
    // 8006EDFC: stb     r3, 197(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(197);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

    ctx->pc = 0x8006EE00u;
    // 8006EE00: stb     r4, 216(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(216);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

    ctx->pc = 0x8006EE04u;
    // 8006EE04: stb     r3, 217(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(217);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

    ctx->pc = 0x8006EE08u;
    // 8006EE08: stb     r4, 236(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(236);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

    ctx->pc = 0x8006EE0Cu;
    // 8006EE0C: stb     r3, 237(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(237);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

    ctx->pc = 0x8006EE10u;
    // 8006EE10: stb     r4, 256(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(256);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

    ctx->pc = 0x8006EE14u;
    // 8006EE14: stb     r3, 257(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(257);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

    ctx->pc = 0x8006EE18u;
    // 8006EE18: stb     r4, 276(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(276);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

    ctx->pc = 0x8006EE1Cu;
    // 8006EE1C: stb     r3, 277(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(277);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

    ctx->pc = 0x8006EE20u;
    // 8006EE20: stb     r4, 296(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(296);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

    ctx->pc = 0x8006EE24u;
    // 8006EE24: stb     r3, 297(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(297);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

    ctx->pc = 0x8006EE28u;
    // 8006EE28: stb     r4, 316(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(316);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

    ctx->pc = 0x8006EE2Cu;
    // 8006EE2C: stb     r3, 317(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(317);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

    // 8006EE30: addi    r6, r6, 320
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(320);

    // 8006EE34: addi    r5, r5, 16
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(16);

    // 8006EE38: bc    16, 0, 0x8006EDA8
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8006EDA8u;
                return;
            }
            goto label_8006EDA8;
        }
    }

    ctx->pc = 0x8006EE3Cu;
}

static void loop_8006EE54(CPUState* ctx) {
label_8006EE54:
    ctx->downcount -= 4;
    ctx->pc = 0x8006EE54u;
    // 8006EE54: stb     r4, 16(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(16);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

    ctx->pc = 0x8006EE58u;
    // 8006EE58: stb     r3, 17(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(17);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

    // 8006EE5C: addi    r6, r6, 20
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(20);

    // 8006EE60: bc    16, 0, 0x8006EE54
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8006EE54u;
                return;
            }
            goto label_8006EE54;
        }
    }

    ctx->pc = 0x8006EE64u;
}

static void loop_8006FE0C(CPUState* ctx) {
label_8006FE0C:
    ctx->downcount -= 38;
    // 8006FE0C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

    ctx->pc = 0x8006FE10u;
    // 8006FE10: stb     r0, 51(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(51);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FE14u;
    // 8006FE14: stb     r0, 14(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(14);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FE18u;
    // 8006FE18: stb     r0, 107(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(107);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FE1Cu;
    // 8006FE1C: stb     r0, 30(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(30);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FE20u;
    // 8006FE20: stb     r0, 163(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(163);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FE24u;
    // 8006FE24: stb     r0, 46(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(46);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FE28u;
    // 8006FE28: stb     r0, 219(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(219);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FE2Cu;
    // 8006FE2C: stb     r0, 62(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(62);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FE30u;
    // 8006FE30: stb     r0, 275(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(275);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FE34u;
    // 8006FE34: stb     r0, 78(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(78);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FE38u;
    // 8006FE38: stb     r0, 331(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(331);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FE3Cu;
    // 8006FE3C: stb     r0, 94(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(94);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FE40u;
    // 8006FE40: stb     r0, 387(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(387);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FE44u;
    // 8006FE44: stb     r0, 110(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(110);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FE48u;
    // 8006FE48: stb     r0, 443(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(443);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FE4Cu;
    // 8006FE4C: stb     r0, 126(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(126);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    // 8006FE50: addi    r4, r4, 448
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(448);

    // 8006FE54: addi    r3, r3, 128
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(128);

    ctx->pc = 0x8006FE58u;
    // 8006FE58: stb     r0, 51(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(51);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FE5Cu;
    // 8006FE5C: stb     r0, 14(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(14);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FE60u;
    // 8006FE60: stb     r0, 107(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(107);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FE64u;
    // 8006FE64: stb     r0, 30(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(30);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FE68u;
    // 8006FE68: stb     r0, 163(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(163);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FE6Cu;
    // 8006FE6C: stb     r0, 46(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(46);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FE70u;
    // 8006FE70: stb     r0, 219(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(219);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FE74u;
    // 8006FE74: stb     r0, 62(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(62);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FE78u;
    // 8006FE78: stb     r0, 275(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(275);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FE7Cu;
    // 8006FE7C: stb     r0, 78(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(78);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FE80u;
    // 8006FE80: stb     r0, 331(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(331);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FE84u;
    // 8006FE84: stb     r0, 94(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(94);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FE88u;
    // 8006FE88: stb     r0, 387(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(387);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FE8Cu;
    // 8006FE8C: stb     r0, 110(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(110);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FE90u;
    // 8006FE90: stb     r0, 443(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(443);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FE94u;
    // 8006FE94: stb     r0, 126(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(126);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    // 8006FE98: addi    r4, r4, 448
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(448);

    // 8006FE9C: addi    r3, r3, 128
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(128);

    // 8006FEA0: bc    16, 0, 0x8006FE0C
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8006FE0Cu;
                return;
            }
            goto label_8006FE0C;
        }
    }

    ctx->pc = 0x8006FEA4u;
}

static void loop_8006FED8(CPUState* ctx) {
label_8006FED8:
    ctx->downcount -= 36;
    // 8006FED8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

    ctx->pc = 0x8006FEDCu;
    // 8006FEDC: stb     r0, 51(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(51);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FEE0u;
    // 8006FEE0: stb     r0, 14(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(14);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FEE4u;
    // 8006FEE4: stb     r0, 107(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(107);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FEE8u;
    // 8006FEE8: stb     r0, 30(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(30);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FEECu;
    // 8006FEEC: stb     r0, 163(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(163);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FEF0u;
    // 8006FEF0: stb     r0, 46(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(46);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FEF4u;
    // 8006FEF4: stb     r0, 219(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(219);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FEF8u;
    // 8006FEF8: stb     r0, 62(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(62);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FEFCu;
    // 8006FEFC: stb     r0, 275(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(275);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FF00u;
    // 8006FF00: stb     r0, 78(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(78);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FF04u;
    // 8006FF04: stb     r0, 331(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(331);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FF08u;
    // 8006FF08: stb     r0, 94(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(94);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FF0Cu;
    // 8006FF0C: stb     r0, 387(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(387);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FF10u;
    // 8006FF10: stb     r0, 110(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(110);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FF14u;
    // 8006FF14: stb     r0, 443(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(443);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FF18u;
    // 8006FF18: stb     r0, 126(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(126);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FF1Cu;
    // 8006FF1C: stb     r0, 499(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(499);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FF20u;
    // 8006FF20: stb     r0, 142(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(142);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FF24u;
    // 8006FF24: stb     r0, 555(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(555);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FF28u;
    // 8006FF28: stb     r0, 158(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(158);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FF2Cu;
    // 8006FF2C: stb     r0, 611(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(611);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FF30u;
    // 8006FF30: stb     r0, 174(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(174);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FF34u;
    // 8006FF34: stb     r0, 667(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(667);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FF38u;
    // 8006FF38: stb     r0, 190(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(190);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FF3Cu;
    // 8006FF3C: stb     r0, 723(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(723);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FF40u;
    // 8006FF40: stb     r0, 206(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(206);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FF44u;
    // 8006FF44: stb     r0, 779(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(779);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FF48u;
    // 8006FF48: stb     r0, 222(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(222);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FF4Cu;
    // 8006FF4C: stb     r0, 835(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(835);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FF50u;
    // 8006FF50: stb     r0, 238(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(238);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FF54u;
    // 8006FF54: stb     r0, 891(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(891);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8006FF58u;
    // 8006FF58: stb     r0, 254(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(254);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    // 8006FF5C: addi    r3, r3, 896
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(896);

    // 8006FF60: addi    r4, r4, 256
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(256);

    // 8006FF64: bc    16, 0, 0x8006FED8
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8006FED8u;
                return;
            }
            goto label_8006FED8;
        }
    }

    ctx->pc = 0x8006FF68u;
}

void func_8006E6E0(CPUState* ctx) {
    switch (ctx->pc) {
    case 0x8006E6E0u: goto label_8006E6E0;
    case 0x8006E6E4u: goto label_8006E6E4;
    case 0x8006E6E8u: goto label_8006E6E8;
    case 0x8006E6ECu: goto label_8006E6EC;
    case 0x8006E6F0u: goto label_8006E6F0;
    case 0x8006E6F4u: goto label_8006E6F4;
    case 0x8006E6F8u: goto label_8006E6F8;
    case 0x8006E6FCu: goto label_8006E6FC;
    case 0x8006E700u: goto label_8006E700;
    case 0x8006E704u: goto label_8006E704;
    case 0x8006E708u: goto label_8006E708;
    case 0x8006E70Cu: goto label_8006E70C;
    case 0x8006E710u: goto label_8006E710;
    case 0x8006E714u: goto label_8006E714;
    case 0x8006E718u: goto label_8006E718;
    case 0x8006E71Cu: goto label_8006E71C;
    case 0x8006E720u: goto label_8006E720;
    case 0x8006E724u: goto label_8006E724;
    case 0x8006E728u: goto label_8006E728;
    case 0x8006E72Cu: goto label_8006E72C;
    case 0x8006E730u: goto label_8006E730;
    case 0x8006E734u: goto label_8006E734;
    case 0x8006E738u: goto label_8006E738;
    case 0x8006E73Cu: goto label_8006E73C;
    case 0x8006E740u: goto label_8006E740;
    case 0x8006E744u: goto label_8006E744;
    case 0x8006E748u: goto label_8006E748;
    case 0x8006E74Cu: goto label_8006E74C;
    case 0x8006E750u: goto label_8006E750;
    case 0x8006E754u: goto label_8006E754;
    case 0x8006E758u: goto label_8006E758;
    case 0x8006E75Cu: goto label_8006E75C;
    case 0x8006E760u: goto label_8006E760;
    case 0x8006E764u: goto label_8006E764;
    case 0x8006E768u: goto label_8006E768;
    case 0x8006E76Cu: goto label_8006E76C;
    case 0x8006E770u: goto label_8006E770;
    case 0x8006E774u: goto label_8006E774;
    case 0x8006E778u: goto label_8006E778;
    case 0x8006E77Cu: goto label_8006E77C;
    case 0x8006E780u: goto label_8006E780;
    case 0x8006E784u: goto label_8006E784;
    case 0x8006E788u: goto label_8006E788;
    case 0x8006E78Cu: goto label_8006E78C;
    case 0x8006E790u: goto label_8006E790;
    case 0x8006E794u: goto label_8006E794;
    case 0x8006E798u: goto label_8006E798;
    case 0x8006E79Cu: goto label_8006E79C;
    case 0x8006E7A0u: goto label_8006E7A0;
    case 0x8006E7A4u: goto label_8006E7A4;
    case 0x8006E7A8u: goto label_8006E7A8;
    case 0x8006E7ACu: goto label_8006E7AC;
    case 0x8006E7B0u: goto label_8006E7B0;
    case 0x8006E7B4u: goto label_8006E7B4;
    case 0x8006E7B8u: goto label_8006E7B8;
    case 0x8006E7BCu: goto label_8006E7BC;
    case 0x8006E7C0u: goto label_8006E7C0;
    case 0x8006E7C4u: goto label_8006E7C4;
    case 0x8006E7C8u: goto label_8006E7C8;
    case 0x8006E7CCu: goto label_8006E7CC;
    case 0x8006E7D0u: goto label_8006E7D0;
    case 0x8006E7D4u: goto label_8006E7D4;
    case 0x8006E7D8u: goto label_8006E7D8;
    case 0x8006E7DCu: goto label_8006E7DC;
    case 0x8006E7E0u: goto label_8006E7E0;
    case 0x8006E7E4u: goto label_8006E7E4;
    case 0x8006E7E8u: goto label_8006E7E8;
    case 0x8006E7ECu: goto label_8006E7EC;
    case 0x8006E7F0u: goto label_8006E7F0;
    case 0x8006E7F4u: goto label_8006E7F4;
    case 0x8006E7F8u: goto label_8006E7F8;
    case 0x8006E7FCu: goto label_8006E7FC;
    case 0x8006E800u: goto label_8006E800;
    case 0x8006E804u: goto label_8006E804;
    case 0x8006E808u: goto label_8006E808;
    case 0x8006E80Cu: goto label_8006E80C;
    case 0x8006E810u: goto label_8006E810;
    case 0x8006E814u: goto label_8006E814;
    case 0x8006E818u: goto label_8006E818;
    case 0x8006E81Cu: goto label_8006E81C;
    case 0x8006E820u: goto label_8006E820;
    case 0x8006E824u: goto label_8006E824;
    case 0x8006E828u: goto label_8006E828;
    case 0x8006E82Cu: goto label_8006E82C;
    case 0x8006E830u: goto label_8006E830;
    case 0x8006E834u: goto label_8006E834;
    case 0x8006E838u: goto label_8006E838;
    case 0x8006E83Cu: goto label_8006E83C;
    case 0x8006E840u: goto label_8006E840;
    case 0x8006E844u: goto label_8006E844;
    case 0x8006E848u: goto label_8006E848;
    case 0x8006E84Cu: goto label_8006E84C;
    case 0x8006E850u: goto label_8006E850;
    case 0x8006E854u: goto label_8006E854;
    case 0x8006E858u: goto label_8006E858;
    case 0x8006E85Cu: goto label_8006E85C;
    case 0x8006E860u: goto label_8006E860;
    case 0x8006E864u: goto label_8006E864;
    case 0x8006E868u: goto label_8006E868;
    case 0x8006E86Cu: goto label_8006E86C;
    case 0x8006E870u: goto label_8006E870;
    case 0x8006E874u: goto label_8006E874;
    case 0x8006E878u: goto label_8006E878;
    case 0x8006E87Cu: goto label_8006E87C;
    case 0x8006E880u: goto label_8006E880;
    case 0x8006E884u: goto label_8006E884;
    case 0x8006E888u: goto label_8006E888;
    case 0x8006E88Cu: goto label_8006E88C;
    case 0x8006E890u: goto label_8006E890;
    case 0x8006E894u: goto label_8006E894;
    case 0x8006E898u: goto label_8006E898;
    case 0x8006E89Cu: goto label_8006E89C;
    case 0x8006E8A0u: goto label_8006E8A0;
    case 0x8006E8A4u: goto label_8006E8A4;
    case 0x8006E8A8u: goto label_8006E8A8;
    case 0x8006E8ACu: goto label_8006E8AC;
    case 0x8006E8B0u: goto label_8006E8B0;
    case 0x8006E8B4u: goto label_8006E8B4;
    case 0x8006E8B8u: goto label_8006E8B8;
    case 0x8006E8BCu: goto label_8006E8BC;
    case 0x8006E8C0u: goto label_8006E8C0;
    case 0x8006E8C4u: goto label_8006E8C4;
    case 0x8006E8C8u: goto label_8006E8C8;
    case 0x8006E8CCu: goto label_8006E8CC;
    case 0x8006E8D0u: goto label_8006E8D0;
    case 0x8006E8D4u: goto label_8006E8D4;
    case 0x8006E8D8u: goto label_8006E8D8;
    case 0x8006E8DCu: goto label_8006E8DC;
    case 0x8006E8E0u: goto label_8006E8E0;
    case 0x8006E8E4u: goto label_8006E8E4;
    case 0x8006E8E8u: goto label_8006E8E8;
    case 0x8006E8ECu: goto label_8006E8EC;
    case 0x8006E8F0u: goto label_8006E8F0;
    case 0x8006E8F4u: goto label_8006E8F4;
    case 0x8006E8F8u: goto label_8006E8F8;
    case 0x8006E8FCu: goto label_8006E8FC;
    case 0x8006E900u: goto label_8006E900;
    case 0x8006E904u: goto label_8006E904;
    case 0x8006E908u: goto label_8006E908;
    case 0x8006E90Cu: goto label_8006E90C;
    case 0x8006E910u: goto label_8006E910;
    case 0x8006E914u: goto label_8006E914;
    case 0x8006E918u: goto label_8006E918;
    case 0x8006E91Cu: goto label_8006E91C;
    case 0x8006E920u: goto label_8006E920;
    case 0x8006E924u: goto label_8006E924;
    case 0x8006E928u: goto label_8006E928;
    case 0x8006E92Cu: goto label_8006E92C;
    case 0x8006E930u: goto label_8006E930;
    case 0x8006E934u: goto label_8006E934;
    case 0x8006E938u: goto label_8006E938;
    case 0x8006E93Cu: goto label_8006E93C;
    case 0x8006E940u: goto label_8006E940;
    case 0x8006E944u: goto label_8006E944;
    case 0x8006E948u: goto label_8006E948;
    case 0x8006E94Cu: goto label_8006E94C;
    case 0x8006E950u: goto label_8006E950;
    case 0x8006E954u: goto label_8006E954;
    case 0x8006E958u: goto label_8006E958;
    case 0x8006E95Cu: goto label_8006E95C;
    case 0x8006E960u: goto label_8006E960;
    case 0x8006E964u: goto label_8006E964;
    case 0x8006E968u: goto label_8006E968;
    case 0x8006E96Cu: goto label_8006E96C;
    case 0x8006E970u: goto label_8006E970;
    case 0x8006E974u: goto label_8006E974;
    case 0x8006E978u: goto label_8006E978;
    case 0x8006E97Cu: goto label_8006E97C;
    case 0x8006E980u: goto label_8006E980;
    case 0x8006E984u: goto label_8006E984;
    case 0x8006E988u: goto label_8006E988;
    case 0x8006E98Cu: goto label_8006E98C;
    case 0x8006E990u: goto label_8006E990;
    case 0x8006E994u: goto label_8006E994;
    case 0x8006E998u: goto label_8006E998;
    case 0x8006E99Cu: goto label_8006E99C;
    case 0x8006E9A0u: goto label_8006E9A0;
    case 0x8006E9A4u: goto label_8006E9A4;
    case 0x8006E9A8u: goto label_8006E9A8;
    case 0x8006E9ACu: goto label_8006E9AC;
    case 0x8006E9B0u: goto label_8006E9B0;
    case 0x8006E9B4u: goto label_8006E9B4;
    case 0x8006E9B8u: goto label_8006E9B8;
    case 0x8006E9BCu: goto label_8006E9BC;
    case 0x8006E9C0u: goto label_8006E9C0;
    case 0x8006E9C4u: goto label_8006E9C4;
    case 0x8006E9C8u: goto label_8006E9C8;
    case 0x8006E9CCu: goto label_8006E9CC;
    case 0x8006E9D0u: goto label_8006E9D0;
    case 0x8006E9D4u: goto label_8006E9D4;
    case 0x8006E9D8u: goto label_8006E9D8;
    case 0x8006E9DCu: goto label_8006E9DC;
    case 0x8006E9E0u: goto label_8006E9E0;
    case 0x8006E9E4u: goto label_8006E9E4;
    case 0x8006E9E8u: goto label_8006E9E8;
    case 0x8006E9ECu: goto label_8006E9EC;
    case 0x8006E9F0u: goto label_8006E9F0;
    case 0x8006E9F4u: goto label_8006E9F4;
    case 0x8006E9F8u: goto label_8006E9F8;
    case 0x8006E9FCu: goto label_8006E9FC;
    case 0x8006EA00u: goto label_8006EA00;
    case 0x8006EA04u: goto label_8006EA04;
    case 0x8006EA08u: goto label_8006EA08;
    case 0x8006EA0Cu: goto label_8006EA0C;
    case 0x8006EA10u: goto label_8006EA10;
    case 0x8006EA14u: goto label_8006EA14;
    case 0x8006EA18u: goto label_8006EA18;
    case 0x8006EA1Cu: goto label_8006EA1C;
    case 0x8006EA20u: goto label_8006EA20;
    case 0x8006EA24u: goto label_8006EA24;
    case 0x8006EA28u: goto label_8006EA28;
    case 0x8006EA2Cu: goto label_8006EA2C;
    case 0x8006EA30u: goto label_8006EA30;
    case 0x8006EA34u: goto label_8006EA34;
    case 0x8006EA38u: goto label_8006EA38;
    case 0x8006EA3Cu: goto label_8006EA3C;
    case 0x8006EA40u: goto label_8006EA40;
    case 0x8006EA44u: goto label_8006EA44;
    case 0x8006EA48u: goto label_8006EA48;
    case 0x8006EA4Cu: goto label_8006EA4C;
    case 0x8006EA50u: goto label_8006EA50;
    case 0x8006EA54u: goto label_8006EA54;
    case 0x8006EA58u: goto label_8006EA58;
    case 0x8006EA5Cu: goto label_8006EA5C;
    case 0x8006EA60u: goto label_8006EA60;
    case 0x8006EA64u: goto label_8006EA64;
    case 0x8006EA68u: goto label_8006EA68;
    case 0x8006EA6Cu: goto label_8006EA6C;
    case 0x8006EA70u: goto label_8006EA70;
    case 0x8006EA74u: goto label_8006EA74;
    case 0x8006EA78u: goto label_8006EA78;
    case 0x8006EA7Cu: goto label_8006EA7C;
    case 0x8006EA80u: goto label_8006EA80;
    case 0x8006EA84u: goto label_8006EA84;
    case 0x8006EA88u: goto label_8006EA88;
    case 0x8006EA8Cu: goto label_8006EA8C;
    case 0x8006EA90u: goto label_8006EA90;
    case 0x8006EA94u: goto label_8006EA94;
    case 0x8006EA98u: goto label_8006EA98;
    case 0x8006EA9Cu: goto label_8006EA9C;
    case 0x8006EAA0u: goto label_8006EAA0;
    case 0x8006EAA4u: goto label_8006EAA4;
    case 0x8006EAA8u: goto label_8006EAA8;
    case 0x8006EAACu: goto label_8006EAAC;
    case 0x8006EAB0u: goto label_8006EAB0;
    case 0x8006EAB4u: goto label_8006EAB4;
    case 0x8006EAB8u: goto label_8006EAB8;
    case 0x8006EABCu: goto label_8006EABC;
    case 0x8006EAC0u: goto label_8006EAC0;
    case 0x8006EAC4u: goto label_8006EAC4;
    case 0x8006EAC8u: goto label_8006EAC8;
    case 0x8006EACCu: goto label_8006EACC;
    case 0x8006EAD0u: goto label_8006EAD0;
    case 0x8006EAD4u: goto label_8006EAD4;
    case 0x8006EAD8u: goto label_8006EAD8;
    case 0x8006EADCu: goto label_8006EADC;
    case 0x8006EAE0u: goto label_8006EAE0;
    case 0x8006EAE4u: goto label_8006EAE4;
    case 0x8006EAE8u: goto label_8006EAE8;
    case 0x8006EAECu: goto label_8006EAEC;
    case 0x8006EAF0u: goto label_8006EAF0;
    case 0x8006EAF4u: goto label_8006EAF4;
    case 0x8006EAF8u: goto label_8006EAF8;
    case 0x8006EAFCu: goto label_8006EAFC;
    case 0x8006EB00u: goto label_8006EB00;
    case 0x8006EB04u: goto label_8006EB04;
    case 0x8006EB08u: goto label_8006EB08;
    case 0x8006EB0Cu: goto label_8006EB0C;
    case 0x8006EB10u: goto label_8006EB10;
    case 0x8006EB14u: goto label_8006EB14;
    case 0x8006EB18u: goto label_8006EB18;
    case 0x8006EB1Cu: goto label_8006EB1C;
    case 0x8006EB20u: goto label_8006EB20;
    case 0x8006EB24u: goto label_8006EB24;
    case 0x8006EB28u: goto label_8006EB28;
    case 0x8006EB2Cu: goto label_8006EB2C;
    case 0x8006EB30u: goto label_8006EB30;
    case 0x8006EB34u: goto label_8006EB34;
    case 0x8006EB38u: goto label_8006EB38;
    case 0x8006EB3Cu: goto label_8006EB3C;
    case 0x8006EB40u: goto label_8006EB40;
    case 0x8006EB44u: goto label_8006EB44;
    case 0x8006EB48u: goto label_8006EB48;
    case 0x8006EB4Cu: goto label_8006EB4C;
    case 0x8006EB50u: goto label_8006EB50;
    case 0x8006EB54u: goto label_8006EB54;
    case 0x8006EB58u: goto label_8006EB58;
    case 0x8006EB5Cu: goto label_8006EB5C;
    case 0x8006EB60u: goto label_8006EB60;
    case 0x8006EB64u: goto label_8006EB64;
    case 0x8006EB68u: goto label_8006EB68;
    case 0x8006EB6Cu: goto label_8006EB6C;
    case 0x8006EB70u: goto label_8006EB70;
    case 0x8006EB74u: goto label_8006EB74;
    case 0x8006EB78u: goto label_8006EB78;
    case 0x8006EB7Cu: goto label_8006EB7C;
    case 0x8006EB80u: goto label_8006EB80;
    case 0x8006EB84u: goto label_8006EB84;
    case 0x8006EB88u: goto label_8006EB88;
    case 0x8006EB8Cu: goto label_8006EB8C;
    case 0x8006EB90u: goto label_8006EB90;
    case 0x8006EB94u: goto label_8006EB94;
    case 0x8006EB98u: goto label_8006EB98;
    case 0x8006EB9Cu: goto label_8006EB9C;
    case 0x8006EBA0u: goto label_8006EBA0;
    case 0x8006EBA4u: goto label_8006EBA4;
    case 0x8006EBA8u: goto label_8006EBA8;
    case 0x8006EBACu: goto label_8006EBAC;
    case 0x8006EBB0u: goto label_8006EBB0;
    case 0x8006EBB4u: goto label_8006EBB4;
    case 0x8006EBB8u: goto label_8006EBB8;
    case 0x8006EBBCu: goto label_8006EBBC;
    case 0x8006EBC0u: goto label_8006EBC0;
    case 0x8006EBC4u: goto label_8006EBC4;
    case 0x8006EBC8u: goto label_8006EBC8;
    case 0x8006EBCCu: goto label_8006EBCC;
    case 0x8006EBD0u: goto label_8006EBD0;
    case 0x8006EBD4u: goto label_8006EBD4;
    case 0x8006EBD8u: goto label_8006EBD8;
    case 0x8006EBDCu: goto label_8006EBDC;
    case 0x8006EBE0u: goto label_8006EBE0;
    case 0x8006EBE4u: goto label_8006EBE4;
    case 0x8006EBE8u: goto label_8006EBE8;
    case 0x8006EBECu: goto label_8006EBEC;
    case 0x8006EBF0u: goto label_8006EBF0;
    case 0x8006EBF4u: goto label_8006EBF4;
    case 0x8006EBF8u: goto label_8006EBF8;
    case 0x8006EBFCu: goto label_8006EBFC;
    case 0x8006EC00u: goto label_8006EC00;
    case 0x8006EC04u: goto label_8006EC04;
    case 0x8006EC08u: goto label_8006EC08;
    case 0x8006EC0Cu: goto label_8006EC0C;
    case 0x8006EC10u: goto label_8006EC10;
    case 0x8006EC14u: goto label_8006EC14;
    case 0x8006EC18u: goto label_8006EC18;
    case 0x8006EC1Cu: goto label_8006EC1C;
    case 0x8006EC20u: goto label_8006EC20;
    case 0x8006EC24u: goto label_8006EC24;
    case 0x8006EC28u: goto label_8006EC28;
    case 0x8006EC2Cu: goto label_8006EC2C;
    case 0x8006EC30u: goto label_8006EC30;
    case 0x8006EC34u: goto label_8006EC34;
    case 0x8006EC38u: goto label_8006EC38;
    case 0x8006EC3Cu: goto label_8006EC3C;
    case 0x8006EC40u: goto label_8006EC40;
    case 0x8006EC44u: goto label_8006EC44;
    case 0x8006EC48u: goto label_8006EC48;
    case 0x8006EC4Cu: goto label_8006EC4C;
    case 0x8006EC50u: goto label_8006EC50;
    case 0x8006EC54u: goto label_8006EC54;
    case 0x8006EC58u: goto label_8006EC58;
    case 0x8006EC5Cu: goto label_8006EC5C;
    case 0x8006EC60u: goto label_8006EC60;
    case 0x8006EC64u: goto label_8006EC64;
    case 0x8006EC68u: goto label_8006EC68;
    case 0x8006EC6Cu: goto label_8006EC6C;
    case 0x8006EC70u: goto label_8006EC70;
    case 0x8006EC74u: goto label_8006EC74;
    case 0x8006EC78u: goto label_8006EC78;
    case 0x8006EC7Cu: goto label_8006EC7C;
    case 0x8006EC80u: goto label_8006EC80;
    case 0x8006EC84u: goto label_8006EC84;
    case 0x8006EC88u: goto label_8006EC88;
    case 0x8006EC8Cu: goto label_8006EC8C;
    case 0x8006EC90u: goto label_8006EC90;
    case 0x8006EC94u: goto label_8006EC94;
    case 0x8006EC98u: goto label_8006EC98;
    case 0x8006EC9Cu: goto label_8006EC9C;
    case 0x8006ECA0u: goto label_8006ECA0;
    case 0x8006ECA4u: goto label_8006ECA4;
    case 0x8006ECA8u: goto label_8006ECA8;
    case 0x8006ECACu: goto label_8006ECAC;
    case 0x8006ECB0u: goto label_8006ECB0;
    case 0x8006ECB4u: goto label_8006ECB4;
    case 0x8006ECB8u: goto label_8006ECB8;
    case 0x8006ECBCu: goto label_8006ECBC;
    case 0x8006ECC0u: goto label_8006ECC0;
    case 0x8006ECC4u: goto label_8006ECC4;
    case 0x8006ECC8u: goto label_8006ECC8;
    case 0x8006ECCCu: goto label_8006ECCC;
    case 0x8006ECD0u: goto label_8006ECD0;
    case 0x8006ECD4u: goto label_8006ECD4;
    case 0x8006ECD8u: goto label_8006ECD8;
    case 0x8006ECDCu: goto label_8006ECDC;
    case 0x8006ECE0u: goto label_8006ECE0;
    case 0x8006ECE4u: goto label_8006ECE4;
    case 0x8006ECE8u: goto label_8006ECE8;
    case 0x8006ECECu: goto label_8006ECEC;
    case 0x8006ECF0u: goto label_8006ECF0;
    case 0x8006ECF4u: goto label_8006ECF4;
    case 0x8006ECF8u: goto label_8006ECF8;
    case 0x8006ECFCu: goto label_8006ECFC;
    case 0x8006ED00u: goto label_8006ED00;
    case 0x8006ED04u: goto label_8006ED04;
    case 0x8006ED08u: goto label_8006ED08;
    case 0x8006ED0Cu: goto label_8006ED0C;
    case 0x8006ED10u: goto label_8006ED10;
    case 0x8006ED14u: goto label_8006ED14;
    case 0x8006ED18u: goto label_8006ED18;
    case 0x8006ED1Cu: goto label_8006ED1C;
    case 0x8006ED20u: goto label_8006ED20;
    case 0x8006ED24u: goto label_8006ED24;
    case 0x8006ED28u: goto label_8006ED28;
    case 0x8006ED2Cu: goto label_8006ED2C;
    case 0x8006ED30u: goto label_8006ED30;
    case 0x8006ED34u: goto label_8006ED34;
    case 0x8006ED38u: goto label_8006ED38;
    case 0x8006ED3Cu: goto label_8006ED3C;
    case 0x8006ED40u: goto label_8006ED40;
    case 0x8006ED44u: goto label_8006ED44;
    case 0x8006ED48u: goto label_8006ED48;
    case 0x8006ED4Cu: goto label_8006ED4C;
    case 0x8006ED50u: goto label_8006ED50;
    case 0x8006ED54u: goto label_8006ED54;
    case 0x8006ED58u: goto label_8006ED58;
    case 0x8006ED5Cu: goto label_8006ED5C;
    case 0x8006ED60u: goto label_8006ED60;
    case 0x8006ED64u: goto label_8006ED64;
    case 0x8006ED68u: goto label_8006ED68;
    case 0x8006ED6Cu: goto label_8006ED6C;
    case 0x8006ED70u: goto label_8006ED70;
    case 0x8006ED74u: goto label_8006ED74;
    case 0x8006ED78u: goto label_8006ED78;
    case 0x8006ED7Cu: goto label_8006ED7C;
    case 0x8006ED80u: goto label_8006ED80;
    case 0x8006ED84u: goto label_8006ED84;
    case 0x8006ED88u: goto label_8006ED88;
    case 0x8006ED8Cu: goto label_8006ED8C;
    case 0x8006ED90u: goto label_8006ED90;
    case 0x8006ED94u: goto label_8006ED94;
    case 0x8006ED98u: goto label_8006ED98;
    case 0x8006ED9Cu: goto label_8006ED9C;
    case 0x8006EDA0u: goto label_8006EDA0;
    case 0x8006EDA4u: goto label_8006EDA4;
    case 0x8006EDA8u: goto label_8006EDA8;
    case 0x8006EDACu: goto label_8006EDAC;
    case 0x8006EDB0u: goto label_8006EDB0;
    case 0x8006EDB4u: goto label_8006EDB4;
    case 0x8006EDB8u: goto label_8006EDB8;
    case 0x8006EDBCu: goto label_8006EDBC;
    case 0x8006EDC0u: goto label_8006EDC0;
    case 0x8006EDC4u: goto label_8006EDC4;
    case 0x8006EDC8u: goto label_8006EDC8;
    case 0x8006EDCCu: goto label_8006EDCC;
    case 0x8006EDD0u: goto label_8006EDD0;
    case 0x8006EDD4u: goto label_8006EDD4;
    case 0x8006EDD8u: goto label_8006EDD8;
    case 0x8006EDDCu: goto label_8006EDDC;
    case 0x8006EDE0u: goto label_8006EDE0;
    case 0x8006EDE4u: goto label_8006EDE4;
    case 0x8006EDE8u: goto label_8006EDE8;
    case 0x8006EDECu: goto label_8006EDEC;
    case 0x8006EDF0u: goto label_8006EDF0;
    case 0x8006EDF4u: goto label_8006EDF4;
    case 0x8006EDF8u: goto label_8006EDF8;
    case 0x8006EDFCu: goto label_8006EDFC;
    case 0x8006EE00u: goto label_8006EE00;
    case 0x8006EE04u: goto label_8006EE04;
    case 0x8006EE08u: goto label_8006EE08;
    case 0x8006EE0Cu: goto label_8006EE0C;
    case 0x8006EE10u: goto label_8006EE10;
    case 0x8006EE14u: goto label_8006EE14;
    case 0x8006EE18u: goto label_8006EE18;
    case 0x8006EE1Cu: goto label_8006EE1C;
    case 0x8006EE20u: goto label_8006EE20;
    case 0x8006EE24u: goto label_8006EE24;
    case 0x8006EE28u: goto label_8006EE28;
    case 0x8006EE2Cu: goto label_8006EE2C;
    case 0x8006EE30u: goto label_8006EE30;
    case 0x8006EE34u: goto label_8006EE34;
    case 0x8006EE38u: goto label_8006EE38;
    case 0x8006EE3Cu: goto label_8006EE3C;
    case 0x8006EE40u: goto label_8006EE40;
    case 0x8006EE44u: goto label_8006EE44;
    case 0x8006EE48u: goto label_8006EE48;
    case 0x8006EE4Cu: goto label_8006EE4C;
    case 0x8006EE50u: goto label_8006EE50;
    case 0x8006EE54u: goto label_8006EE54;
    case 0x8006EE58u: goto label_8006EE58;
    case 0x8006EE5Cu: goto label_8006EE5C;
    case 0x8006EE60u: goto label_8006EE60;
    case 0x8006EE64u: goto label_8006EE64;
    case 0x8006EE68u: goto label_8006EE68;
    case 0x8006EE6Cu: goto label_8006EE6C;
    case 0x8006EE70u: goto label_8006EE70;
    case 0x8006EE74u: goto label_8006EE74;
    case 0x8006EE78u: goto label_8006EE78;
    case 0x8006EE7Cu: goto label_8006EE7C;
    case 0x8006EE80u: goto label_8006EE80;
    case 0x8006EE84u: goto label_8006EE84;
    case 0x8006EE88u: goto label_8006EE88;
    case 0x8006EE8Cu: goto label_8006EE8C;
    case 0x8006EE90u: goto label_8006EE90;
    case 0x8006EE94u: goto label_8006EE94;
    case 0x8006EE98u: goto label_8006EE98;
    case 0x8006EE9Cu: goto label_8006EE9C;
    case 0x8006EEA0u: goto label_8006EEA0;
    case 0x8006EEA4u: goto label_8006EEA4;
    case 0x8006EEA8u: goto label_8006EEA8;
    case 0x8006EEACu: goto label_8006EEAC;
    case 0x8006EEB0u: goto label_8006EEB0;
    case 0x8006EEB4u: goto label_8006EEB4;
    case 0x8006EEB8u: goto label_8006EEB8;
    case 0x8006EEBCu: goto label_8006EEBC;
    case 0x8006EEC0u: goto label_8006EEC0;
    case 0x8006EEC4u: goto label_8006EEC4;
    case 0x8006EEC8u: goto label_8006EEC8;
    case 0x8006EECCu: goto label_8006EECC;
    case 0x8006EED0u: goto label_8006EED0;
    case 0x8006EED4u: goto label_8006EED4;
    case 0x8006EED8u: goto label_8006EED8;
    case 0x8006EEDCu: goto label_8006EEDC;
    case 0x8006EEE0u: goto label_8006EEE0;
    case 0x8006EEE4u: goto label_8006EEE4;
    case 0x8006EEE8u: goto label_8006EEE8;
    case 0x8006EEECu: goto label_8006EEEC;
    case 0x8006EEF0u: goto label_8006EEF0;
    case 0x8006EEF4u: goto label_8006EEF4;
    case 0x8006EEF8u: goto label_8006EEF8;
    case 0x8006EEFCu: goto label_8006EEFC;
    case 0x8006EF00u: goto label_8006EF00;
    case 0x8006EF04u: goto label_8006EF04;
    case 0x8006EF08u: goto label_8006EF08;
    case 0x8006EF0Cu: goto label_8006EF0C;
    case 0x8006EF10u: goto label_8006EF10;
    case 0x8006EF14u: goto label_8006EF14;
    case 0x8006EF18u: goto label_8006EF18;
    case 0x8006EF1Cu: goto label_8006EF1C;
    case 0x8006EF20u: goto label_8006EF20;
    case 0x8006EF24u: goto label_8006EF24;
    case 0x8006EF28u: goto label_8006EF28;
    case 0x8006EF2Cu: goto label_8006EF2C;
    case 0x8006EF30u: goto label_8006EF30;
    case 0x8006EF34u: goto label_8006EF34;
    case 0x8006EF38u: goto label_8006EF38;
    case 0x8006EF3Cu: goto label_8006EF3C;
    case 0x8006EF40u: goto label_8006EF40;
    case 0x8006EF44u: goto label_8006EF44;
    case 0x8006EF48u: goto label_8006EF48;
    case 0x8006EF4Cu: goto label_8006EF4C;
    case 0x8006EF50u: goto label_8006EF50;
    case 0x8006EF54u: goto label_8006EF54;
    case 0x8006EF58u: goto label_8006EF58;
    case 0x8006EF5Cu: goto label_8006EF5C;
    case 0x8006EF60u: goto label_8006EF60;
    case 0x8006EF64u: goto label_8006EF64;
    case 0x8006EF68u: goto label_8006EF68;
    case 0x8006EF6Cu: goto label_8006EF6C;
    case 0x8006EF70u: goto label_8006EF70;
    case 0x8006EF74u: goto label_8006EF74;
    case 0x8006EF78u: goto label_8006EF78;
    case 0x8006EF7Cu: goto label_8006EF7C;
    case 0x8006EF80u: goto label_8006EF80;
    case 0x8006EF84u: goto label_8006EF84;
    case 0x8006EF88u: goto label_8006EF88;
    case 0x8006EF8Cu: goto label_8006EF8C;
    case 0x8006EF90u: goto label_8006EF90;
    case 0x8006EF94u: goto label_8006EF94;
    case 0x8006EF98u: goto label_8006EF98;
    case 0x8006EF9Cu: goto label_8006EF9C;
    case 0x8006EFA0u: goto label_8006EFA0;
    case 0x8006EFA4u: goto label_8006EFA4;
    case 0x8006EFA8u: goto label_8006EFA8;
    case 0x8006EFACu: goto label_8006EFAC;
    case 0x8006EFB0u: goto label_8006EFB0;
    case 0x8006EFB4u: goto label_8006EFB4;
    case 0x8006EFB8u: goto label_8006EFB8;
    case 0x8006EFBCu: goto label_8006EFBC;
    case 0x8006EFC0u: goto label_8006EFC0;
    case 0x8006EFC4u: goto label_8006EFC4;
    case 0x8006EFC8u: goto label_8006EFC8;
    case 0x8006EFCCu: goto label_8006EFCC;
    case 0x8006EFD0u: goto label_8006EFD0;
    case 0x8006EFD4u: goto label_8006EFD4;
    case 0x8006EFD8u: goto label_8006EFD8;
    case 0x8006EFDCu: goto label_8006EFDC;
    case 0x8006EFE0u: goto label_8006EFE0;
    case 0x8006EFE4u: goto label_8006EFE4;
    case 0x8006EFE8u: goto label_8006EFE8;
    case 0x8006EFECu: goto label_8006EFEC;
    case 0x8006EFF0u: goto label_8006EFF0;
    case 0x8006EFF4u: goto label_8006EFF4;
    case 0x8006EFF8u: goto label_8006EFF8;
    case 0x8006EFFCu: goto label_8006EFFC;
    case 0x8006F000u: goto label_8006F000;
    case 0x8006F004u: goto label_8006F004;
    case 0x8006F008u: goto label_8006F008;
    case 0x8006F00Cu: goto label_8006F00C;
    case 0x8006F010u: goto label_8006F010;
    case 0x8006F014u: goto label_8006F014;
    case 0x8006F018u: goto label_8006F018;
    case 0x8006F01Cu: goto label_8006F01C;
    case 0x8006F020u: goto label_8006F020;
    case 0x8006F024u: goto label_8006F024;
    case 0x8006F028u: goto label_8006F028;
    case 0x8006F02Cu: goto label_8006F02C;
    case 0x8006F030u: goto label_8006F030;
    case 0x8006F034u: goto label_8006F034;
    case 0x8006F038u: goto label_8006F038;
    case 0x8006F03Cu: goto label_8006F03C;
    case 0x8006F040u: goto label_8006F040;
    case 0x8006F044u: goto label_8006F044;
    case 0x8006F048u: goto label_8006F048;
    case 0x8006F04Cu: goto label_8006F04C;
    case 0x8006F050u: goto label_8006F050;
    case 0x8006F054u: goto label_8006F054;
    case 0x8006F058u: goto label_8006F058;
    case 0x8006F05Cu: goto label_8006F05C;
    case 0x8006F060u: goto label_8006F060;
    case 0x8006F064u: goto label_8006F064;
    case 0x8006F068u: goto label_8006F068;
    case 0x8006F06Cu: goto label_8006F06C;
    case 0x8006F070u: goto label_8006F070;
    case 0x8006F074u: goto label_8006F074;
    case 0x8006F078u: goto label_8006F078;
    case 0x8006F07Cu: goto label_8006F07C;
    case 0x8006F080u: goto label_8006F080;
    case 0x8006F084u: goto label_8006F084;
    case 0x8006F088u: goto label_8006F088;
    case 0x8006F08Cu: goto label_8006F08C;
    case 0x8006F090u: goto label_8006F090;
    case 0x8006F094u: goto label_8006F094;
    case 0x8006F098u: goto label_8006F098;
    case 0x8006F09Cu: goto label_8006F09C;
    case 0x8006F0A0u: goto label_8006F0A0;
    case 0x8006F0A4u: goto label_8006F0A4;
    case 0x8006F0A8u: goto label_8006F0A8;
    case 0x8006F0ACu: goto label_8006F0AC;
    case 0x8006F0B0u: goto label_8006F0B0;
    case 0x8006F0B4u: goto label_8006F0B4;
    case 0x8006F0B8u: goto label_8006F0B8;
    case 0x8006F0BCu: goto label_8006F0BC;
    case 0x8006F0C0u: goto label_8006F0C0;
    case 0x8006F0C4u: goto label_8006F0C4;
    case 0x8006F0C8u: goto label_8006F0C8;
    case 0x8006F0CCu: goto label_8006F0CC;
    case 0x8006F0D0u: goto label_8006F0D0;
    case 0x8006F0D4u: goto label_8006F0D4;
    case 0x8006F0D8u: goto label_8006F0D8;
    case 0x8006F0DCu: goto label_8006F0DC;
    case 0x8006F0E0u: goto label_8006F0E0;
    case 0x8006F0E4u: goto label_8006F0E4;
    case 0x8006F0E8u: goto label_8006F0E8;
    case 0x8006F0ECu: goto label_8006F0EC;
    case 0x8006F0F0u: goto label_8006F0F0;
    case 0x8006F0F4u: goto label_8006F0F4;
    case 0x8006F0F8u: goto label_8006F0F8;
    case 0x8006F0FCu: goto label_8006F0FC;
    case 0x8006F100u: goto label_8006F100;
    case 0x8006F104u: goto label_8006F104;
    case 0x8006F108u: goto label_8006F108;
    case 0x8006F10Cu: goto label_8006F10C;
    case 0x8006F110u: goto label_8006F110;
    case 0x8006F114u: goto label_8006F114;
    case 0x8006F118u: goto label_8006F118;
    case 0x8006F11Cu: goto label_8006F11C;
    case 0x8006F120u: goto label_8006F120;
    case 0x8006F124u: goto label_8006F124;
    case 0x8006F128u: goto label_8006F128;
    case 0x8006F12Cu: goto label_8006F12C;
    case 0x8006F130u: goto label_8006F130;
    case 0x8006F134u: goto label_8006F134;
    case 0x8006F138u: goto label_8006F138;
    case 0x8006F13Cu: goto label_8006F13C;
    case 0x8006F140u: goto label_8006F140;
    case 0x8006F144u: goto label_8006F144;
    case 0x8006F148u: goto label_8006F148;
    case 0x8006F14Cu: goto label_8006F14C;
    case 0x8006F150u: goto label_8006F150;
    case 0x8006F154u: goto label_8006F154;
    case 0x8006F158u: goto label_8006F158;
    case 0x8006F15Cu: goto label_8006F15C;
    case 0x8006F160u: goto label_8006F160;
    case 0x8006F164u: goto label_8006F164;
    case 0x8006F168u: goto label_8006F168;
    case 0x8006F16Cu: goto label_8006F16C;
    case 0x8006F170u: goto label_8006F170;
    case 0x8006F174u: goto label_8006F174;
    case 0x8006F178u: goto label_8006F178;
    case 0x8006F17Cu: goto label_8006F17C;
    case 0x8006F180u: goto label_8006F180;
    case 0x8006F184u: goto label_8006F184;
    case 0x8006F188u: goto label_8006F188;
    case 0x8006F18Cu: goto label_8006F18C;
    case 0x8006F190u: goto label_8006F190;
    case 0x8006F194u: goto label_8006F194;
    case 0x8006F198u: goto label_8006F198;
    case 0x8006F19Cu: goto label_8006F19C;
    case 0x8006F1A0u: goto label_8006F1A0;
    case 0x8006F1A4u: goto label_8006F1A4;
    case 0x8006F1A8u: goto label_8006F1A8;
    case 0x8006F1ACu: goto label_8006F1AC;
    case 0x8006F1B0u: goto label_8006F1B0;
    case 0x8006F1B4u: goto label_8006F1B4;
    case 0x8006F1B8u: goto label_8006F1B8;
    case 0x8006F1BCu: goto label_8006F1BC;
    case 0x8006F1C0u: goto label_8006F1C0;
    case 0x8006F1C4u: goto label_8006F1C4;
    case 0x8006F1C8u: goto label_8006F1C8;
    case 0x8006F1CCu: goto label_8006F1CC;
    case 0x8006F1D0u: goto label_8006F1D0;
    case 0x8006F1D4u: goto label_8006F1D4;
    case 0x8006F1D8u: goto label_8006F1D8;
    case 0x8006F1DCu: goto label_8006F1DC;
    case 0x8006F1E0u: goto label_8006F1E0;
    case 0x8006F1E4u: goto label_8006F1E4;
    case 0x8006F1E8u: goto label_8006F1E8;
    case 0x8006F1ECu: goto label_8006F1EC;
    case 0x8006F1F0u: goto label_8006F1F0;
    case 0x8006F1F4u: goto label_8006F1F4;
    case 0x8006F1F8u: goto label_8006F1F8;
    case 0x8006F1FCu: goto label_8006F1FC;
    case 0x8006F200u: goto label_8006F200;
    case 0x8006F204u: goto label_8006F204;
    case 0x8006F208u: goto label_8006F208;
    case 0x8006F20Cu: goto label_8006F20C;
    case 0x8006F210u: goto label_8006F210;
    case 0x8006F214u: goto label_8006F214;
    case 0x8006F218u: goto label_8006F218;
    case 0x8006F21Cu: goto label_8006F21C;
    case 0x8006F220u: goto label_8006F220;
    case 0x8006F224u: goto label_8006F224;
    case 0x8006F228u: goto label_8006F228;
    case 0x8006F22Cu: goto label_8006F22C;
    case 0x8006F230u: goto label_8006F230;
    case 0x8006F234u: goto label_8006F234;
    case 0x8006F238u: goto label_8006F238;
    case 0x8006F23Cu: goto label_8006F23C;
    case 0x8006F240u: goto label_8006F240;
    case 0x8006F244u: goto label_8006F244;
    case 0x8006F248u: goto label_8006F248;
    case 0x8006F24Cu: goto label_8006F24C;
    case 0x8006F250u: goto label_8006F250;
    case 0x8006F254u: goto label_8006F254;
    case 0x8006F258u: goto label_8006F258;
    case 0x8006F25Cu: goto label_8006F25C;
    case 0x8006F260u: goto label_8006F260;
    case 0x8006F264u: goto label_8006F264;
    case 0x8006F268u: goto label_8006F268;
    case 0x8006F26Cu: goto label_8006F26C;
    case 0x8006F270u: goto label_8006F270;
    case 0x8006F274u: goto label_8006F274;
    case 0x8006F278u: goto label_8006F278;
    case 0x8006F27Cu: goto label_8006F27C;
    case 0x8006F280u: goto label_8006F280;
    case 0x8006F284u: goto label_8006F284;
    case 0x8006F288u: goto label_8006F288;
    case 0x8006F28Cu: goto label_8006F28C;
    case 0x8006F290u: goto label_8006F290;
    case 0x8006F294u: goto label_8006F294;
    case 0x8006F298u: goto label_8006F298;
    case 0x8006F29Cu: goto label_8006F29C;
    case 0x8006F2A0u: goto label_8006F2A0;
    case 0x8006F2A4u: goto label_8006F2A4;
    case 0x8006F2A8u: goto label_8006F2A8;
    case 0x8006F2ACu: goto label_8006F2AC;
    case 0x8006F2B0u: goto label_8006F2B0;
    case 0x8006F2B4u: goto label_8006F2B4;
    case 0x8006F2B8u: goto label_8006F2B8;
    case 0x8006F2BCu: goto label_8006F2BC;
    case 0x8006F2C0u: goto label_8006F2C0;
    case 0x8006F2C4u: goto label_8006F2C4;
    case 0x8006F2C8u: goto label_8006F2C8;
    case 0x8006F2CCu: goto label_8006F2CC;
    case 0x8006F2D0u: goto label_8006F2D0;
    case 0x8006F2D4u: goto label_8006F2D4;
    case 0x8006F2D8u: goto label_8006F2D8;
    case 0x8006F2DCu: goto label_8006F2DC;
    case 0x8006F2E0u: goto label_8006F2E0;
    case 0x8006F2E4u: goto label_8006F2E4;
    case 0x8006F2E8u: goto label_8006F2E8;
    case 0x8006F2ECu: goto label_8006F2EC;
    case 0x8006F2F0u: goto label_8006F2F0;
    case 0x8006F2F4u: goto label_8006F2F4;
    case 0x8006F2F8u: goto label_8006F2F8;
    case 0x8006F2FCu: goto label_8006F2FC;
    case 0x8006F300u: goto label_8006F300;
    case 0x8006F304u: goto label_8006F304;
    case 0x8006F308u: goto label_8006F308;
    case 0x8006F30Cu: goto label_8006F30C;
    case 0x8006F310u: goto label_8006F310;
    case 0x8006F314u: goto label_8006F314;
    case 0x8006F318u: goto label_8006F318;
    case 0x8006F31Cu: goto label_8006F31C;
    case 0x8006F320u: goto label_8006F320;
    case 0x8006F324u: goto label_8006F324;
    case 0x8006F328u: goto label_8006F328;
    case 0x8006F32Cu: goto label_8006F32C;
    case 0x8006F330u: goto label_8006F330;
    case 0x8006F334u: goto label_8006F334;
    case 0x8006F338u: goto label_8006F338;
    case 0x8006F33Cu: goto label_8006F33C;
    case 0x8006F340u: goto label_8006F340;
    case 0x8006F344u: goto label_8006F344;
    case 0x8006F348u: goto label_8006F348;
    case 0x8006F34Cu: goto label_8006F34C;
    case 0x8006F350u: goto label_8006F350;
    case 0x8006F354u: goto label_8006F354;
    case 0x8006F358u: goto label_8006F358;
    case 0x8006F35Cu: goto label_8006F35C;
    case 0x8006F360u: goto label_8006F360;
    case 0x8006F364u: goto label_8006F364;
    case 0x8006F368u: goto label_8006F368;
    case 0x8006F36Cu: goto label_8006F36C;
    case 0x8006F370u: goto label_8006F370;
    case 0x8006F374u: goto label_8006F374;
    case 0x8006F378u: goto label_8006F378;
    case 0x8006F37Cu: goto label_8006F37C;
    case 0x8006F380u: goto label_8006F380;
    case 0x8006F384u: goto label_8006F384;
    case 0x8006F388u: goto label_8006F388;
    case 0x8006F38Cu: goto label_8006F38C;
    case 0x8006F390u: goto label_8006F390;
    case 0x8006F394u: goto label_8006F394;
    case 0x8006F398u: goto label_8006F398;
    case 0x8006F39Cu: goto label_8006F39C;
    case 0x8006F3A0u: goto label_8006F3A0;
    case 0x8006F3A4u: goto label_8006F3A4;
    case 0x8006F3A8u: goto label_8006F3A8;
    case 0x8006F3ACu: goto label_8006F3AC;
    case 0x8006F3B0u: goto label_8006F3B0;
    case 0x8006F3B4u: goto label_8006F3B4;
    case 0x8006F3B8u: goto label_8006F3B8;
    case 0x8006F3BCu: goto label_8006F3BC;
    case 0x8006F3C0u: goto label_8006F3C0;
    case 0x8006F3C4u: goto label_8006F3C4;
    case 0x8006F3C8u: goto label_8006F3C8;
    case 0x8006F3CCu: goto label_8006F3CC;
    case 0x8006F3D0u: goto label_8006F3D0;
    case 0x8006F3D4u: goto label_8006F3D4;
    case 0x8006F3D8u: goto label_8006F3D8;
    case 0x8006F3DCu: goto label_8006F3DC;
    case 0x8006F3E0u: goto label_8006F3E0;
    case 0x8006F3E4u: goto label_8006F3E4;
    case 0x8006F3E8u: goto label_8006F3E8;
    case 0x8006F3ECu: goto label_8006F3EC;
    case 0x8006F3F0u: goto label_8006F3F0;
    case 0x8006F3F4u: goto label_8006F3F4;
    case 0x8006F3F8u: goto label_8006F3F8;
    case 0x8006F3FCu: goto label_8006F3FC;
    case 0x8006F400u: goto label_8006F400;
    case 0x8006F404u: goto label_8006F404;
    case 0x8006F408u: goto label_8006F408;
    case 0x8006F40Cu: goto label_8006F40C;
    case 0x8006F410u: goto label_8006F410;
    case 0x8006F414u: goto label_8006F414;
    case 0x8006F418u: goto label_8006F418;
    case 0x8006F41Cu: goto label_8006F41C;
    case 0x8006F420u: goto label_8006F420;
    case 0x8006F424u: goto label_8006F424;
    case 0x8006F428u: goto label_8006F428;
    case 0x8006F42Cu: goto label_8006F42C;
    case 0x8006F430u: goto label_8006F430;
    case 0x8006F434u: goto label_8006F434;
    case 0x8006F438u: goto label_8006F438;
    case 0x8006F43Cu: goto label_8006F43C;
    case 0x8006F440u: goto label_8006F440;
    case 0x8006F444u: goto label_8006F444;
    case 0x8006F448u: goto label_8006F448;
    case 0x8006F44Cu: goto label_8006F44C;
    case 0x8006F450u: goto label_8006F450;
    case 0x8006F454u: goto label_8006F454;
    case 0x8006F458u: goto label_8006F458;
    case 0x8006F45Cu: goto label_8006F45C;
    case 0x8006F460u: goto label_8006F460;
    case 0x8006F464u: goto label_8006F464;
    case 0x8006F468u: goto label_8006F468;
    case 0x8006F46Cu: goto label_8006F46C;
    case 0x8006F470u: goto label_8006F470;
    case 0x8006F474u: goto label_8006F474;
    case 0x8006F478u: goto label_8006F478;
    case 0x8006F47Cu: goto label_8006F47C;
    case 0x8006F480u: goto label_8006F480;
    case 0x8006F484u: goto label_8006F484;
    case 0x8006F488u: goto label_8006F488;
    case 0x8006F48Cu: goto label_8006F48C;
    case 0x8006F490u: goto label_8006F490;
    case 0x8006F494u: goto label_8006F494;
    case 0x8006F498u: goto label_8006F498;
    case 0x8006F49Cu: goto label_8006F49C;
    case 0x8006F4A0u: goto label_8006F4A0;
    case 0x8006F4A4u: goto label_8006F4A4;
    case 0x8006F4A8u: goto label_8006F4A8;
    case 0x8006F4ACu: goto label_8006F4AC;
    case 0x8006F4B0u: goto label_8006F4B0;
    case 0x8006F4B4u: goto label_8006F4B4;
    case 0x8006F4B8u: goto label_8006F4B8;
    case 0x8006F4BCu: goto label_8006F4BC;
    case 0x8006F4C0u: goto label_8006F4C0;
    case 0x8006F4C4u: goto label_8006F4C4;
    case 0x8006F4C8u: goto label_8006F4C8;
    case 0x8006F4CCu: goto label_8006F4CC;
    case 0x8006F4D0u: goto label_8006F4D0;
    case 0x8006F4D4u: goto label_8006F4D4;
    case 0x8006F4D8u: goto label_8006F4D8;
    case 0x8006F4DCu: goto label_8006F4DC;
    case 0x8006F4E0u: goto label_8006F4E0;
    case 0x8006F4E4u: goto label_8006F4E4;
    case 0x8006F4E8u: goto label_8006F4E8;
    case 0x8006F4ECu: goto label_8006F4EC;
    case 0x8006F4F0u: goto label_8006F4F0;
    case 0x8006F4F4u: goto label_8006F4F4;
    case 0x8006F4F8u: goto label_8006F4F8;
    case 0x8006F4FCu: goto label_8006F4FC;
    case 0x8006F500u: goto label_8006F500;
    case 0x8006F504u: goto label_8006F504;
    case 0x8006F508u: goto label_8006F508;
    case 0x8006F50Cu: goto label_8006F50C;
    case 0x8006F510u: goto label_8006F510;
    case 0x8006F514u: goto label_8006F514;
    case 0x8006F518u: goto label_8006F518;
    case 0x8006F51Cu: goto label_8006F51C;
    case 0x8006F520u: goto label_8006F520;
    case 0x8006F524u: goto label_8006F524;
    case 0x8006F528u: goto label_8006F528;
    case 0x8006F52Cu: goto label_8006F52C;
    case 0x8006F530u: goto label_8006F530;
    case 0x8006F534u: goto label_8006F534;
    case 0x8006F538u: goto label_8006F538;
    case 0x8006F53Cu: goto label_8006F53C;
    case 0x8006F540u: goto label_8006F540;
    case 0x8006F544u: goto label_8006F544;
    case 0x8006F548u: goto label_8006F548;
    case 0x8006F54Cu: goto label_8006F54C;
    case 0x8006F550u: goto label_8006F550;
    case 0x8006F554u: goto label_8006F554;
    case 0x8006F558u: goto label_8006F558;
    case 0x8006F55Cu: goto label_8006F55C;
    case 0x8006F560u: goto label_8006F560;
    case 0x8006F564u: goto label_8006F564;
    case 0x8006F568u: goto label_8006F568;
    case 0x8006F56Cu: goto label_8006F56C;
    case 0x8006F570u: goto label_8006F570;
    case 0x8006F574u: goto label_8006F574;
    case 0x8006F578u: goto label_8006F578;
    case 0x8006F57Cu: goto label_8006F57C;
    case 0x8006F580u: goto label_8006F580;
    case 0x8006F584u: goto label_8006F584;
    case 0x8006F588u: goto label_8006F588;
    case 0x8006F58Cu: goto label_8006F58C;
    case 0x8006F590u: goto label_8006F590;
    case 0x8006F594u: goto label_8006F594;
    case 0x8006F598u: goto label_8006F598;
    case 0x8006F59Cu: goto label_8006F59C;
    case 0x8006F5A0u: goto label_8006F5A0;
    case 0x8006F5A4u: goto label_8006F5A4;
    case 0x8006F5A8u: goto label_8006F5A8;
    case 0x8006F5ACu: goto label_8006F5AC;
    case 0x8006F5B0u: goto label_8006F5B0;
    case 0x8006F5B4u: goto label_8006F5B4;
    case 0x8006F5B8u: goto label_8006F5B8;
    case 0x8006F5BCu: goto label_8006F5BC;
    case 0x8006F5C0u: goto label_8006F5C0;
    case 0x8006F5C4u: goto label_8006F5C4;
    case 0x8006F5C8u: goto label_8006F5C8;
    case 0x8006F5CCu: goto label_8006F5CC;
    case 0x8006F5D0u: goto label_8006F5D0;
    case 0x8006F5D4u: goto label_8006F5D4;
    case 0x8006F5D8u: goto label_8006F5D8;
    case 0x8006F5DCu: goto label_8006F5DC;
    case 0x8006F5E0u: goto label_8006F5E0;
    case 0x8006F5E4u: goto label_8006F5E4;
    case 0x8006F5E8u: goto label_8006F5E8;
    case 0x8006F5ECu: goto label_8006F5EC;
    case 0x8006F5F0u: goto label_8006F5F0;
    case 0x8006F5F4u: goto label_8006F5F4;
    case 0x8006F5F8u: goto label_8006F5F8;
    case 0x8006F5FCu: goto label_8006F5FC;
    case 0x8006F600u: goto label_8006F600;
    case 0x8006F604u: goto label_8006F604;
    case 0x8006F608u: goto label_8006F608;
    case 0x8006F60Cu: goto label_8006F60C;
    case 0x8006F610u: goto label_8006F610;
    case 0x8006F614u: goto label_8006F614;
    case 0x8006F618u: goto label_8006F618;
    case 0x8006F61Cu: goto label_8006F61C;
    case 0x8006F620u: goto label_8006F620;
    case 0x8006F624u: goto label_8006F624;
    case 0x8006F628u: goto label_8006F628;
    case 0x8006F62Cu: goto label_8006F62C;
    case 0x8006F630u: goto label_8006F630;
    case 0x8006F634u: goto label_8006F634;
    case 0x8006F638u: goto label_8006F638;
    case 0x8006F63Cu: goto label_8006F63C;
    case 0x8006F640u: goto label_8006F640;
    case 0x8006F644u: goto label_8006F644;
    case 0x8006F648u: goto label_8006F648;
    case 0x8006F64Cu: goto label_8006F64C;
    case 0x8006F650u: goto label_8006F650;
    case 0x8006F654u: goto label_8006F654;
    case 0x8006F658u: goto label_8006F658;
    case 0x8006F65Cu: goto label_8006F65C;
    case 0x8006F660u: goto label_8006F660;
    case 0x8006F664u: goto label_8006F664;
    case 0x8006F668u: goto label_8006F668;
    case 0x8006F66Cu: goto label_8006F66C;
    case 0x8006F670u: goto label_8006F670;
    case 0x8006F674u: goto label_8006F674;
    case 0x8006F678u: goto label_8006F678;
    case 0x8006F67Cu: goto label_8006F67C;
    case 0x8006F680u: goto label_8006F680;
    case 0x8006F684u: goto label_8006F684;
    case 0x8006F688u: goto label_8006F688;
    case 0x8006F68Cu: goto label_8006F68C;
    case 0x8006F690u: goto label_8006F690;
    case 0x8006F694u: goto label_8006F694;
    case 0x8006F698u: goto label_8006F698;
    case 0x8006F69Cu: goto label_8006F69C;
    case 0x8006F6A0u: goto label_8006F6A0;
    case 0x8006F6A4u: goto label_8006F6A4;
    case 0x8006F6A8u: goto label_8006F6A8;
    case 0x8006F6ACu: goto label_8006F6AC;
    case 0x8006F6B0u: goto label_8006F6B0;
    case 0x8006F6B4u: goto label_8006F6B4;
    case 0x8006F6B8u: goto label_8006F6B8;
    case 0x8006F6BCu: goto label_8006F6BC;
    case 0x8006F6C0u: goto label_8006F6C0;
    case 0x8006F6C4u: goto label_8006F6C4;
    case 0x8006F6C8u: goto label_8006F6C8;
    case 0x8006F6CCu: goto label_8006F6CC;
    case 0x8006F6D0u: goto label_8006F6D0;
    case 0x8006F6D4u: goto label_8006F6D4;
    case 0x8006F6D8u: goto label_8006F6D8;
    case 0x8006F6DCu: goto label_8006F6DC;
    case 0x8006F6E0u: goto label_8006F6E0;
    case 0x8006F6E4u: goto label_8006F6E4;
    case 0x8006F6E8u: goto label_8006F6E8;
    case 0x8006F6ECu: goto label_8006F6EC;
    case 0x8006F6F0u: goto label_8006F6F0;
    case 0x8006F6F4u: goto label_8006F6F4;
    case 0x8006F6F8u: goto label_8006F6F8;
    case 0x8006F6FCu: goto label_8006F6FC;
    case 0x8006F700u: goto label_8006F700;
    case 0x8006F704u: goto label_8006F704;
    case 0x8006F708u: goto label_8006F708;
    case 0x8006F70Cu: goto label_8006F70C;
    case 0x8006F710u: goto label_8006F710;
    case 0x8006F714u: goto label_8006F714;
    case 0x8006F718u: goto label_8006F718;
    case 0x8006F71Cu: goto label_8006F71C;
    case 0x8006F720u: goto label_8006F720;
    case 0x8006F724u: goto label_8006F724;
    case 0x8006F728u: goto label_8006F728;
    case 0x8006F72Cu: goto label_8006F72C;
    case 0x8006F730u: goto label_8006F730;
    case 0x8006F734u: goto label_8006F734;
    case 0x8006F738u: goto label_8006F738;
    case 0x8006F73Cu: goto label_8006F73C;
    case 0x8006F740u: goto label_8006F740;
    case 0x8006F744u: goto label_8006F744;
    case 0x8006F748u: goto label_8006F748;
    case 0x8006F74Cu: goto label_8006F74C;
    case 0x8006F750u: goto label_8006F750;
    case 0x8006F754u: goto label_8006F754;
    case 0x8006F758u: goto label_8006F758;
    case 0x8006F75Cu: goto label_8006F75C;
    case 0x8006F760u: goto label_8006F760;
    case 0x8006F764u: goto label_8006F764;
    case 0x8006F768u: goto label_8006F768;
    case 0x8006F76Cu: goto label_8006F76C;
    case 0x8006F770u: goto label_8006F770;
    case 0x8006F774u: goto label_8006F774;
    case 0x8006F778u: goto label_8006F778;
    case 0x8006F77Cu: goto label_8006F77C;
    case 0x8006F780u: goto label_8006F780;
    case 0x8006F784u: goto label_8006F784;
    case 0x8006F788u: goto label_8006F788;
    case 0x8006F78Cu: goto label_8006F78C;
    case 0x8006F790u: goto label_8006F790;
    case 0x8006F794u: goto label_8006F794;
    case 0x8006F798u: goto label_8006F798;
    case 0x8006F79Cu: goto label_8006F79C;
    case 0x8006F7A0u: goto label_8006F7A0;
    case 0x8006F7A4u: goto label_8006F7A4;
    case 0x8006F7A8u: goto label_8006F7A8;
    case 0x8006F7ACu: goto label_8006F7AC;
    case 0x8006F7B0u: goto label_8006F7B0;
    case 0x8006F7B4u: goto label_8006F7B4;
    case 0x8006F7B8u: goto label_8006F7B8;
    case 0x8006F7BCu: goto label_8006F7BC;
    case 0x8006F7C0u: goto label_8006F7C0;
    case 0x8006F7C4u: goto label_8006F7C4;
    case 0x8006F7C8u: goto label_8006F7C8;
    case 0x8006F7CCu: goto label_8006F7CC;
    case 0x8006F7D0u: goto label_8006F7D0;
    case 0x8006F7D4u: goto label_8006F7D4;
    case 0x8006F7D8u: goto label_8006F7D8;
    case 0x8006F7DCu: goto label_8006F7DC;
    case 0x8006F7E0u: goto label_8006F7E0;
    case 0x8006F7E4u: goto label_8006F7E4;
    case 0x8006F7E8u: goto label_8006F7E8;
    case 0x8006F7ECu: goto label_8006F7EC;
    case 0x8006F7F0u: goto label_8006F7F0;
    case 0x8006F7F4u: goto label_8006F7F4;
    case 0x8006F7F8u: goto label_8006F7F8;
    case 0x8006F7FCu: goto label_8006F7FC;
    case 0x8006F800u: goto label_8006F800;
    case 0x8006F804u: goto label_8006F804;
    case 0x8006F808u: goto label_8006F808;
    case 0x8006F80Cu: goto label_8006F80C;
    case 0x8006F810u: goto label_8006F810;
    case 0x8006F814u: goto label_8006F814;
    case 0x8006F818u: goto label_8006F818;
    case 0x8006F81Cu: goto label_8006F81C;
    case 0x8006F820u: goto label_8006F820;
    case 0x8006F824u: goto label_8006F824;
    case 0x8006F828u: goto label_8006F828;
    case 0x8006F82Cu: goto label_8006F82C;
    case 0x8006F830u: goto label_8006F830;
    case 0x8006F834u: goto label_8006F834;
    case 0x8006F838u: goto label_8006F838;
    case 0x8006F83Cu: goto label_8006F83C;
    case 0x8006F840u: goto label_8006F840;
    case 0x8006F844u: goto label_8006F844;
    case 0x8006F848u: goto label_8006F848;
    case 0x8006F84Cu: goto label_8006F84C;
    case 0x8006F850u: goto label_8006F850;
    case 0x8006F854u: goto label_8006F854;
    case 0x8006F858u: goto label_8006F858;
    case 0x8006F85Cu: goto label_8006F85C;
    case 0x8006F860u: goto label_8006F860;
    case 0x8006F864u: goto label_8006F864;
    case 0x8006F868u: goto label_8006F868;
    case 0x8006F86Cu: goto label_8006F86C;
    case 0x8006F870u: goto label_8006F870;
    case 0x8006F874u: goto label_8006F874;
    case 0x8006F878u: goto label_8006F878;
    case 0x8006F87Cu: goto label_8006F87C;
    case 0x8006F880u: goto label_8006F880;
    case 0x8006F884u: goto label_8006F884;
    case 0x8006F888u: goto label_8006F888;
    case 0x8006F88Cu: goto label_8006F88C;
    case 0x8006F890u: goto label_8006F890;
    case 0x8006F894u: goto label_8006F894;
    case 0x8006F898u: goto label_8006F898;
    case 0x8006F89Cu: goto label_8006F89C;
    case 0x8006F8A0u: goto label_8006F8A0;
    case 0x8006F8A4u: goto label_8006F8A4;
    case 0x8006F8A8u: goto label_8006F8A8;
    case 0x8006F8ACu: goto label_8006F8AC;
    case 0x8006F8B0u: goto label_8006F8B0;
    case 0x8006F8B4u: goto label_8006F8B4;
    case 0x8006F8B8u: goto label_8006F8B8;
    case 0x8006F8BCu: goto label_8006F8BC;
    case 0x8006F8C0u: goto label_8006F8C0;
    case 0x8006F8C4u: goto label_8006F8C4;
    case 0x8006F8C8u: goto label_8006F8C8;
    case 0x8006F8CCu: goto label_8006F8CC;
    case 0x8006F8D0u: goto label_8006F8D0;
    case 0x8006F8D4u: goto label_8006F8D4;
    case 0x8006F8D8u: goto label_8006F8D8;
    case 0x8006F8DCu: goto label_8006F8DC;
    case 0x8006F8E0u: goto label_8006F8E0;
    case 0x8006F8E4u: goto label_8006F8E4;
    case 0x8006F8E8u: goto label_8006F8E8;
    case 0x8006F8ECu: goto label_8006F8EC;
    case 0x8006F8F0u: goto label_8006F8F0;
    case 0x8006F8F4u: goto label_8006F8F4;
    case 0x8006F8F8u: goto label_8006F8F8;
    case 0x8006F8FCu: goto label_8006F8FC;
    case 0x8006F900u: goto label_8006F900;
    case 0x8006F904u: goto label_8006F904;
    case 0x8006F908u: goto label_8006F908;
    case 0x8006F90Cu: goto label_8006F90C;
    case 0x8006F910u: goto label_8006F910;
    case 0x8006F914u: goto label_8006F914;
    case 0x8006F918u: goto label_8006F918;
    case 0x8006F91Cu: goto label_8006F91C;
    case 0x8006F920u: goto label_8006F920;
    case 0x8006F924u: goto label_8006F924;
    case 0x8006F928u: goto label_8006F928;
    case 0x8006F92Cu: goto label_8006F92C;
    case 0x8006F930u: goto label_8006F930;
    case 0x8006F934u: goto label_8006F934;
    case 0x8006F938u: goto label_8006F938;
    case 0x8006F93Cu: goto label_8006F93C;
    case 0x8006F940u: goto label_8006F940;
    case 0x8006F944u: goto label_8006F944;
    case 0x8006F948u: goto label_8006F948;
    case 0x8006F94Cu: goto label_8006F94C;
    case 0x8006F950u: goto label_8006F950;
    case 0x8006F954u: goto label_8006F954;
    case 0x8006F958u: goto label_8006F958;
    case 0x8006F95Cu: goto label_8006F95C;
    case 0x8006F960u: goto label_8006F960;
    case 0x8006F964u: goto label_8006F964;
    case 0x8006F968u: goto label_8006F968;
    case 0x8006F96Cu: goto label_8006F96C;
    case 0x8006F970u: goto label_8006F970;
    case 0x8006F974u: goto label_8006F974;
    case 0x8006F978u: goto label_8006F978;
    case 0x8006F97Cu: goto label_8006F97C;
    case 0x8006F980u: goto label_8006F980;
    case 0x8006F984u: goto label_8006F984;
    case 0x8006F988u: goto label_8006F988;
    case 0x8006F98Cu: goto label_8006F98C;
    case 0x8006F990u: goto label_8006F990;
    case 0x8006F994u: goto label_8006F994;
    case 0x8006F998u: goto label_8006F998;
    case 0x8006F99Cu: goto label_8006F99C;
    case 0x8006F9A0u: goto label_8006F9A0;
    case 0x8006F9A4u: goto label_8006F9A4;
    case 0x8006F9A8u: goto label_8006F9A8;
    case 0x8006F9ACu: goto label_8006F9AC;
    case 0x8006F9B0u: goto label_8006F9B0;
    case 0x8006F9B4u: goto label_8006F9B4;
    case 0x8006F9B8u: goto label_8006F9B8;
    case 0x8006F9BCu: goto label_8006F9BC;
    case 0x8006F9C0u: goto label_8006F9C0;
    case 0x8006F9C4u: goto label_8006F9C4;
    case 0x8006F9C8u: goto label_8006F9C8;
    case 0x8006F9CCu: goto label_8006F9CC;
    case 0x8006F9D0u: goto label_8006F9D0;
    case 0x8006F9D4u: goto label_8006F9D4;
    case 0x8006F9D8u: goto label_8006F9D8;
    case 0x8006F9DCu: goto label_8006F9DC;
    case 0x8006F9E0u: goto label_8006F9E0;
    case 0x8006F9E4u: goto label_8006F9E4;
    case 0x8006F9E8u: goto label_8006F9E8;
    case 0x8006F9ECu: goto label_8006F9EC;
    case 0x8006F9F0u: goto label_8006F9F0;
    case 0x8006F9F4u: goto label_8006F9F4;
    case 0x8006F9F8u: goto label_8006F9F8;
    case 0x8006F9FCu: goto label_8006F9FC;
    case 0x8006FA00u: goto label_8006FA00;
    case 0x8006FA04u: goto label_8006FA04;
    case 0x8006FA08u: goto label_8006FA08;
    case 0x8006FA0Cu: goto label_8006FA0C;
    case 0x8006FA10u: goto label_8006FA10;
    case 0x8006FA14u: goto label_8006FA14;
    case 0x8006FA18u: goto label_8006FA18;
    case 0x8006FA1Cu: goto label_8006FA1C;
    case 0x8006FA20u: goto label_8006FA20;
    case 0x8006FA24u: goto label_8006FA24;
    case 0x8006FA28u: goto label_8006FA28;
    case 0x8006FA2Cu: goto label_8006FA2C;
    case 0x8006FA30u: goto label_8006FA30;
    case 0x8006FA34u: goto label_8006FA34;
    case 0x8006FA38u: goto label_8006FA38;
    case 0x8006FA3Cu: goto label_8006FA3C;
    case 0x8006FA40u: goto label_8006FA40;
    case 0x8006FA44u: goto label_8006FA44;
    case 0x8006FA48u: goto label_8006FA48;
    case 0x8006FA4Cu: goto label_8006FA4C;
    case 0x8006FA50u: goto label_8006FA50;
    case 0x8006FA54u: goto label_8006FA54;
    case 0x8006FA58u: goto label_8006FA58;
    case 0x8006FA5Cu: goto label_8006FA5C;
    case 0x8006FA60u: goto label_8006FA60;
    case 0x8006FA64u: goto label_8006FA64;
    case 0x8006FA68u: goto label_8006FA68;
    case 0x8006FA6Cu: goto label_8006FA6C;
    case 0x8006FA70u: goto label_8006FA70;
    case 0x8006FA74u: goto label_8006FA74;
    case 0x8006FA78u: goto label_8006FA78;
    case 0x8006FA7Cu: goto label_8006FA7C;
    case 0x8006FA80u: goto label_8006FA80;
    case 0x8006FA84u: goto label_8006FA84;
    case 0x8006FA88u: goto label_8006FA88;
    case 0x8006FA8Cu: goto label_8006FA8C;
    case 0x8006FA90u: goto label_8006FA90;
    case 0x8006FA94u: goto label_8006FA94;
    case 0x8006FA98u: goto label_8006FA98;
    case 0x8006FA9Cu: goto label_8006FA9C;
    case 0x8006FAA0u: goto label_8006FAA0;
    case 0x8006FAA4u: goto label_8006FAA4;
    case 0x8006FAA8u: goto label_8006FAA8;
    case 0x8006FAACu: goto label_8006FAAC;
    case 0x8006FAB0u: goto label_8006FAB0;
    case 0x8006FAB4u: goto label_8006FAB4;
    case 0x8006FAB8u: goto label_8006FAB8;
    case 0x8006FABCu: goto label_8006FABC;
    case 0x8006FAC0u: goto label_8006FAC0;
    case 0x8006FAC4u: goto label_8006FAC4;
    case 0x8006FAC8u: goto label_8006FAC8;
    case 0x8006FACCu: goto label_8006FACC;
    case 0x8006FAD0u: goto label_8006FAD0;
    case 0x8006FAD4u: goto label_8006FAD4;
    case 0x8006FAD8u: goto label_8006FAD8;
    case 0x8006FADCu: goto label_8006FADC;
    case 0x8006FAE0u: goto label_8006FAE0;
    case 0x8006FAE4u: goto label_8006FAE4;
    case 0x8006FAE8u: goto label_8006FAE8;
    case 0x8006FAECu: goto label_8006FAEC;
    case 0x8006FAF0u: goto label_8006FAF0;
    case 0x8006FAF4u: goto label_8006FAF4;
    case 0x8006FAF8u: goto label_8006FAF8;
    case 0x8006FAFCu: goto label_8006FAFC;
    case 0x8006FB00u: goto label_8006FB00;
    case 0x8006FB04u: goto label_8006FB04;
    case 0x8006FB08u: goto label_8006FB08;
    case 0x8006FB0Cu: goto label_8006FB0C;
    case 0x8006FB10u: goto label_8006FB10;
    case 0x8006FB14u: goto label_8006FB14;
    case 0x8006FB18u: goto label_8006FB18;
    case 0x8006FB1Cu: goto label_8006FB1C;
    case 0x8006FB20u: goto label_8006FB20;
    case 0x8006FB24u: goto label_8006FB24;
    case 0x8006FB28u: goto label_8006FB28;
    case 0x8006FB2Cu: goto label_8006FB2C;
    case 0x8006FB30u: goto label_8006FB30;
    case 0x8006FB34u: goto label_8006FB34;
    case 0x8006FB38u: goto label_8006FB38;
    case 0x8006FB3Cu: goto label_8006FB3C;
    case 0x8006FB40u: goto label_8006FB40;
    case 0x8006FB44u: goto label_8006FB44;
    case 0x8006FB48u: goto label_8006FB48;
    case 0x8006FB4Cu: goto label_8006FB4C;
    case 0x8006FB50u: goto label_8006FB50;
    case 0x8006FB54u: goto label_8006FB54;
    case 0x8006FB58u: goto label_8006FB58;
    case 0x8006FB5Cu: goto label_8006FB5C;
    case 0x8006FB60u: goto label_8006FB60;
    case 0x8006FB64u: goto label_8006FB64;
    case 0x8006FB68u: goto label_8006FB68;
    case 0x8006FB6Cu: goto label_8006FB6C;
    case 0x8006FB70u: goto label_8006FB70;
    case 0x8006FB74u: goto label_8006FB74;
    case 0x8006FB78u: goto label_8006FB78;
    case 0x8006FB7Cu: goto label_8006FB7C;
    case 0x8006FB80u: goto label_8006FB80;
    case 0x8006FB84u: goto label_8006FB84;
    case 0x8006FB88u: goto label_8006FB88;
    case 0x8006FB8Cu: goto label_8006FB8C;
    case 0x8006FB90u: goto label_8006FB90;
    case 0x8006FB94u: goto label_8006FB94;
    case 0x8006FB98u: goto label_8006FB98;
    case 0x8006FB9Cu: goto label_8006FB9C;
    case 0x8006FBA0u: goto label_8006FBA0;
    case 0x8006FBA4u: goto label_8006FBA4;
    case 0x8006FBA8u: goto label_8006FBA8;
    case 0x8006FBACu: goto label_8006FBAC;
    case 0x8006FBB0u: goto label_8006FBB0;
    case 0x8006FBB4u: goto label_8006FBB4;
    case 0x8006FBB8u: goto label_8006FBB8;
    case 0x8006FBBCu: goto label_8006FBBC;
    case 0x8006FBC0u: goto label_8006FBC0;
    case 0x8006FBC4u: goto label_8006FBC4;
    case 0x8006FBC8u: goto label_8006FBC8;
    case 0x8006FBCCu: goto label_8006FBCC;
    case 0x8006FBD0u: goto label_8006FBD0;
    case 0x8006FBD4u: goto label_8006FBD4;
    case 0x8006FBD8u: goto label_8006FBD8;
    case 0x8006FBDCu: goto label_8006FBDC;
    case 0x8006FBE0u: goto label_8006FBE0;
    case 0x8006FBE4u: goto label_8006FBE4;
    case 0x8006FBE8u: goto label_8006FBE8;
    case 0x8006FBECu: goto label_8006FBEC;
    case 0x8006FBF0u: goto label_8006FBF0;
    case 0x8006FBF4u: goto label_8006FBF4;
    case 0x8006FBF8u: goto label_8006FBF8;
    case 0x8006FBFCu: goto label_8006FBFC;
    case 0x8006FC00u: goto label_8006FC00;
    case 0x8006FC04u: goto label_8006FC04;
    case 0x8006FC08u: goto label_8006FC08;
    case 0x8006FC0Cu: goto label_8006FC0C;
    case 0x8006FC10u: goto label_8006FC10;
    case 0x8006FC14u: goto label_8006FC14;
    case 0x8006FC18u: goto label_8006FC18;
    case 0x8006FC1Cu: goto label_8006FC1C;
    case 0x8006FC20u: goto label_8006FC20;
    case 0x8006FC24u: goto label_8006FC24;
    case 0x8006FC28u: goto label_8006FC28;
    case 0x8006FC2Cu: goto label_8006FC2C;
    case 0x8006FC30u: goto label_8006FC30;
    case 0x8006FC34u: goto label_8006FC34;
    case 0x8006FC38u: goto label_8006FC38;
    case 0x8006FC3Cu: goto label_8006FC3C;
    case 0x8006FC40u: goto label_8006FC40;
    case 0x8006FC44u: goto label_8006FC44;
    case 0x8006FC48u: goto label_8006FC48;
    case 0x8006FC4Cu: goto label_8006FC4C;
    case 0x8006FC50u: goto label_8006FC50;
    case 0x8006FC54u: goto label_8006FC54;
    case 0x8006FC58u: goto label_8006FC58;
    case 0x8006FC5Cu: goto label_8006FC5C;
    case 0x8006FC60u: goto label_8006FC60;
    case 0x8006FC64u: goto label_8006FC64;
    case 0x8006FC68u: goto label_8006FC68;
    case 0x8006FC6Cu: goto label_8006FC6C;
    case 0x8006FC70u: goto label_8006FC70;
    case 0x8006FC74u: goto label_8006FC74;
    case 0x8006FC78u: goto label_8006FC78;
    case 0x8006FC7Cu: goto label_8006FC7C;
    case 0x8006FC80u: goto label_8006FC80;
    case 0x8006FC84u: goto label_8006FC84;
    case 0x8006FC88u: goto label_8006FC88;
    case 0x8006FC8Cu: goto label_8006FC8C;
    case 0x8006FC90u: goto label_8006FC90;
    case 0x8006FC94u: goto label_8006FC94;
    case 0x8006FC98u: goto label_8006FC98;
    case 0x8006FC9Cu: goto label_8006FC9C;
    case 0x8006FCA0u: goto label_8006FCA0;
    case 0x8006FCA4u: goto label_8006FCA4;
    case 0x8006FCA8u: goto label_8006FCA8;
    case 0x8006FCACu: goto label_8006FCAC;
    case 0x8006FCB0u: goto label_8006FCB0;
    case 0x8006FCB4u: goto label_8006FCB4;
    case 0x8006FCB8u: goto label_8006FCB8;
    case 0x8006FCBCu: goto label_8006FCBC;
    case 0x8006FCC0u: goto label_8006FCC0;
    case 0x8006FCC4u: goto label_8006FCC4;
    case 0x8006FCC8u: goto label_8006FCC8;
    case 0x8006FCCCu: goto label_8006FCCC;
    case 0x8006FCD0u: goto label_8006FCD0;
    case 0x8006FCD4u: goto label_8006FCD4;
    case 0x8006FCD8u: goto label_8006FCD8;
    case 0x8006FCDCu: goto label_8006FCDC;
    case 0x8006FCE0u: goto label_8006FCE0;
    case 0x8006FCE4u: goto label_8006FCE4;
    case 0x8006FCE8u: goto label_8006FCE8;
    case 0x8006FCECu: goto label_8006FCEC;
    case 0x8006FCF0u: goto label_8006FCF0;
    case 0x8006FCF4u: goto label_8006FCF4;
    case 0x8006FCF8u: goto label_8006FCF8;
    case 0x8006FCFCu: goto label_8006FCFC;
    case 0x8006FD00u: goto label_8006FD00;
    case 0x8006FD04u: goto label_8006FD04;
    case 0x8006FD08u: goto label_8006FD08;
    case 0x8006FD0Cu: goto label_8006FD0C;
    case 0x8006FD10u: goto label_8006FD10;
    case 0x8006FD14u: goto label_8006FD14;
    case 0x8006FD18u: goto label_8006FD18;
    case 0x8006FD1Cu: goto label_8006FD1C;
    case 0x8006FD20u: goto label_8006FD20;
    case 0x8006FD24u: goto label_8006FD24;
    case 0x8006FD28u: goto label_8006FD28;
    case 0x8006FD2Cu: goto label_8006FD2C;
    case 0x8006FD30u: goto label_8006FD30;
    case 0x8006FD34u: goto label_8006FD34;
    case 0x8006FD38u: goto label_8006FD38;
    case 0x8006FD3Cu: goto label_8006FD3C;
    case 0x8006FD40u: goto label_8006FD40;
    case 0x8006FD44u: goto label_8006FD44;
    case 0x8006FD48u: goto label_8006FD48;
    case 0x8006FD4Cu: goto label_8006FD4C;
    case 0x8006FD50u: goto label_8006FD50;
    case 0x8006FD54u: goto label_8006FD54;
    case 0x8006FD58u: goto label_8006FD58;
    case 0x8006FD5Cu: goto label_8006FD5C;
    case 0x8006FD60u: goto label_8006FD60;
    case 0x8006FD64u: goto label_8006FD64;
    case 0x8006FD68u: goto label_8006FD68;
    case 0x8006FD6Cu: goto label_8006FD6C;
    case 0x8006FD70u: goto label_8006FD70;
    case 0x8006FD74u: goto label_8006FD74;
    case 0x8006FD78u: goto label_8006FD78;
    case 0x8006FD7Cu: goto label_8006FD7C;
    case 0x8006FD80u: goto label_8006FD80;
    case 0x8006FD84u: goto label_8006FD84;
    case 0x8006FD88u: goto label_8006FD88;
    case 0x8006FD8Cu: goto label_8006FD8C;
    case 0x8006FD90u: goto label_8006FD90;
    case 0x8006FD94u: goto label_8006FD94;
    case 0x8006FD98u: goto label_8006FD98;
    case 0x8006FD9Cu: goto label_8006FD9C;
    case 0x8006FDA0u: goto label_8006FDA0;
    case 0x8006FDA4u: goto label_8006FDA4;
    case 0x8006FDA8u: goto label_8006FDA8;
    case 0x8006FDACu: goto label_8006FDAC;
    case 0x8006FDB0u: goto label_8006FDB0;
    case 0x8006FDB4u: goto label_8006FDB4;
    case 0x8006FDB8u: goto label_8006FDB8;
    case 0x8006FDBCu: goto label_8006FDBC;
    case 0x8006FDC0u: goto label_8006FDC0;
    case 0x8006FDC4u: goto label_8006FDC4;
    case 0x8006FDC8u: goto label_8006FDC8;
    case 0x8006FDCCu: goto label_8006FDCC;
    case 0x8006FDD0u: goto label_8006FDD0;
    case 0x8006FDD4u: goto label_8006FDD4;
    case 0x8006FDD8u: goto label_8006FDD8;
    case 0x8006FDDCu: goto label_8006FDDC;
    case 0x8006FDE0u: goto label_8006FDE0;
    case 0x8006FDE4u: goto label_8006FDE4;
    case 0x8006FDE8u: goto label_8006FDE8;
    case 0x8006FDECu: goto label_8006FDEC;
    case 0x8006FDF0u: goto label_8006FDF0;
    case 0x8006FDF4u: goto label_8006FDF4;
    case 0x8006FDF8u: goto label_8006FDF8;
    case 0x8006FDFCu: goto label_8006FDFC;
    case 0x8006FE00u: goto label_8006FE00;
    case 0x8006FE04u: goto label_8006FE04;
    case 0x8006FE08u: goto label_8006FE08;
    case 0x8006FE0Cu: goto label_8006FE0C;
    case 0x8006FE10u: goto label_8006FE10;
    case 0x8006FE14u: goto label_8006FE14;
    case 0x8006FE18u: goto label_8006FE18;
    case 0x8006FE1Cu: goto label_8006FE1C;
    case 0x8006FE20u: goto label_8006FE20;
    case 0x8006FE24u: goto label_8006FE24;
    case 0x8006FE28u: goto label_8006FE28;
    case 0x8006FE2Cu: goto label_8006FE2C;
    case 0x8006FE30u: goto label_8006FE30;
    case 0x8006FE34u: goto label_8006FE34;
    case 0x8006FE38u: goto label_8006FE38;
    case 0x8006FE3Cu: goto label_8006FE3C;
    case 0x8006FE40u: goto label_8006FE40;
    case 0x8006FE44u: goto label_8006FE44;
    case 0x8006FE48u: goto label_8006FE48;
    case 0x8006FE4Cu: goto label_8006FE4C;
    case 0x8006FE50u: goto label_8006FE50;
    case 0x8006FE54u: goto label_8006FE54;
    case 0x8006FE58u: goto label_8006FE58;
    case 0x8006FE5Cu: goto label_8006FE5C;
    case 0x8006FE60u: goto label_8006FE60;
    case 0x8006FE64u: goto label_8006FE64;
    case 0x8006FE68u: goto label_8006FE68;
    case 0x8006FE6Cu: goto label_8006FE6C;
    case 0x8006FE70u: goto label_8006FE70;
    case 0x8006FE74u: goto label_8006FE74;
    case 0x8006FE78u: goto label_8006FE78;
    case 0x8006FE7Cu: goto label_8006FE7C;
    case 0x8006FE80u: goto label_8006FE80;
    case 0x8006FE84u: goto label_8006FE84;
    case 0x8006FE88u: goto label_8006FE88;
    case 0x8006FE8Cu: goto label_8006FE8C;
    case 0x8006FE90u: goto label_8006FE90;
    case 0x8006FE94u: goto label_8006FE94;
    case 0x8006FE98u: goto label_8006FE98;
    case 0x8006FE9Cu: goto label_8006FE9C;
    case 0x8006FEA0u: goto label_8006FEA0;
    case 0x8006FEA4u: goto label_8006FEA4;
    case 0x8006FEA8u: goto label_8006FEA8;
    case 0x8006FEACu: goto label_8006FEAC;
    case 0x8006FEB0u: goto label_8006FEB0;
    case 0x8006FEB4u: goto label_8006FEB4;
    case 0x8006FEB8u: goto label_8006FEB8;
    case 0x8006FEBCu: goto label_8006FEBC;
    case 0x8006FEC0u: goto label_8006FEC0;
    case 0x8006FEC4u: goto label_8006FEC4;
    case 0x8006FEC8u: goto label_8006FEC8;
    case 0x8006FECCu: goto label_8006FECC;
    case 0x8006FED0u: goto label_8006FED0;
    case 0x8006FED4u: goto label_8006FED4;
    case 0x8006FED8u: goto label_8006FED8;
    case 0x8006FEDCu: goto label_8006FEDC;
    case 0x8006FEE0u: goto label_8006FEE0;
    case 0x8006FEE4u: goto label_8006FEE4;
    case 0x8006FEE8u: goto label_8006FEE8;
    case 0x8006FEECu: goto label_8006FEEC;
    case 0x8006FEF0u: goto label_8006FEF0;
    case 0x8006FEF4u: goto label_8006FEF4;
    case 0x8006FEF8u: goto label_8006FEF8;
    case 0x8006FEFCu: goto label_8006FEFC;
    case 0x8006FF00u: goto label_8006FF00;
    case 0x8006FF04u: goto label_8006FF04;
    case 0x8006FF08u: goto label_8006FF08;
    case 0x8006FF0Cu: goto label_8006FF0C;
    case 0x8006FF10u: goto label_8006FF10;
    case 0x8006FF14u: goto label_8006FF14;
    case 0x8006FF18u: goto label_8006FF18;
    case 0x8006FF1Cu: goto label_8006FF1C;
    case 0x8006FF20u: goto label_8006FF20;
    case 0x8006FF24u: goto label_8006FF24;
    case 0x8006FF28u: goto label_8006FF28;
    case 0x8006FF2Cu: goto label_8006FF2C;
    case 0x8006FF30u: goto label_8006FF30;
    case 0x8006FF34u: goto label_8006FF34;
    case 0x8006FF38u: goto label_8006FF38;
    case 0x8006FF3Cu: goto label_8006FF3C;
    case 0x8006FF40u: goto label_8006FF40;
    case 0x8006FF44u: goto label_8006FF44;
    case 0x8006FF48u: goto label_8006FF48;
    case 0x8006FF4Cu: goto label_8006FF4C;
    case 0x8006FF50u: goto label_8006FF50;
    case 0x8006FF54u: goto label_8006FF54;
    case 0x8006FF58u: goto label_8006FF58;
    case 0x8006FF5Cu: goto label_8006FF5C;
    case 0x8006FF60u: goto label_8006FF60;
    case 0x8006FF64u: goto label_8006FF64;
    case 0x8006FF68u: goto label_8006FF68;
    case 0x8006FF6Cu: goto label_8006FF6C;
    case 0x8006FF70u: goto label_8006FF70;
    case 0x8006FF74u: goto label_8006FF74;
    case 0x8006FF78u: goto label_8006FF78;
    case 0x8006FF7Cu: goto label_8006FF7C;
    case 0x8006FF80u: goto label_8006FF80;
    case 0x8006FF84u: goto label_8006FF84;
    case 0x8006FF88u: goto label_8006FF88;
    case 0x8006FF8Cu: goto label_8006FF8C;
    case 0x8006FF90u: goto label_8006FF90;
    case 0x8006FF94u: goto label_8006FF94;
    case 0x8006FF98u: goto label_8006FF98;
    case 0x8006FF9Cu: goto label_8006FF9C;
    case 0x8006FFA0u: goto label_8006FFA0;
    case 0x8006FFA4u: goto label_8006FFA4;
    case 0x8006FFA8u: goto label_8006FFA8;
    case 0x8006FFACu: goto label_8006FFAC;
    case 0x8006FFB0u: goto label_8006FFB0;
    case 0x8006FFB4u: goto label_8006FFB4;
    case 0x8006FFB8u: goto label_8006FFB8;
    case 0x8006FFBCu: goto label_8006FFBC;
    case 0x8006FFC0u: goto label_8006FFC0;
    case 0x8006FFC4u: goto label_8006FFC4;
    case 0x8006FFC8u: goto label_8006FFC8;
    case 0x8006FFCCu: goto label_8006FFCC;
    case 0x8006FFD0u: goto label_8006FFD0;
    case 0x8006FFD4u: goto label_8006FFD4;
    case 0x8006FFD8u: goto label_8006FFD8;
    case 0x8006FFDCu: goto label_8006FFDC;
    case 0x8006FFE0u: goto label_8006FFE0;
    case 0x8006FFE4u: goto label_8006FFE4;
    case 0x8006FFE8u: goto label_8006FFE8;
    case 0x8006FFECu: goto label_8006FFEC;
    case 0x8006FFF0u: goto label_8006FFF0;
    case 0x8006FFF4u: goto label_8006FFF4;
    case 0x8006FFF8u: goto label_8006FFF8;
    case 0x8006FFFCu: goto label_8006FFFC;
    case 0x80070000u: goto label_80070000;
    case 0x80070004u: goto label_80070004;
    case 0x80070008u: goto label_80070008;
    case 0x8007000Cu: goto label_8007000C;
    case 0x80070010u: goto label_80070010;
    case 0x80070014u: goto label_80070014;
    case 0x80070018u: goto label_80070018;
    case 0x8007001Cu: goto label_8007001C;
    case 0x80070020u: goto label_80070020;
    case 0x80070024u: goto label_80070024;
    case 0x80070028u: goto label_80070028;
    case 0x8007002Cu: goto label_8007002C;
    case 0x80070030u: goto label_80070030;
    case 0x80070034u: goto label_80070034;
    case 0x80070038u: goto label_80070038;
    case 0x8007003Cu: goto label_8007003C;
    case 0x80070040u: goto label_80070040;
    case 0x80070044u: goto label_80070044;
    case 0x80070048u: goto label_80070048;
    case 0x8007004Cu: goto label_8007004C;
    case 0x80070050u: goto label_80070050;
    case 0x80070054u: goto label_80070054;
    case 0x80070058u: goto label_80070058;
    case 0x8007005Cu: goto label_8007005C;
    case 0x80070060u: goto label_80070060;
    case 0x80070064u: goto label_80070064;
    case 0x80070068u: goto label_80070068;
    case 0x8007006Cu: goto label_8007006C;
    case 0x80070070u: goto label_80070070;
    case 0x80070074u: goto label_80070074;
    case 0x80070078u: goto label_80070078;
    case 0x8007007Cu: goto label_8007007C;
    case 0x80070080u: goto label_80070080;
    case 0x80070084u: goto label_80070084;
    case 0x80070088u: goto label_80070088;
    case 0x8007008Cu: goto label_8007008C;
    case 0x80070090u: goto label_80070090;
    case 0x80070094u: goto label_80070094;
    case 0x80070098u: goto label_80070098;
    case 0x8007009Cu: goto label_8007009C;
    case 0x800700A0u: goto label_800700A0;
    case 0x800700A4u: goto label_800700A4;
    case 0x800700A8u: goto label_800700A8;
    case 0x800700ACu: goto label_800700AC;
    case 0x800700B0u: goto label_800700B0;
    case 0x800700B4u: goto label_800700B4;
    case 0x800700B8u: goto label_800700B8;
    case 0x800700BCu: goto label_800700BC;
    case 0x800700C0u: goto label_800700C0;
    case 0x800700C4u: goto label_800700C4;
    case 0x800700C8u: goto label_800700C8;
    case 0x800700CCu: goto label_800700CC;
    case 0x800700D0u: goto label_800700D0;
    case 0x800700D4u: goto label_800700D4;
    case 0x800700D8u: goto label_800700D8;
    case 0x800700DCu: goto label_800700DC;
    case 0x800700E0u: goto label_800700E0;
    case 0x800700E4u: goto label_800700E4;
    case 0x800700E8u: goto label_800700E8;
    case 0x800700ECu: goto label_800700EC;
    case 0x800700F0u: goto label_800700F0;
    case 0x800700F4u: goto label_800700F4;
    case 0x800700F8u: goto label_800700F8;
    case 0x800700FCu: goto label_800700FC;
    case 0x80070100u: goto label_80070100;
    case 0x80070104u: goto label_80070104;
    case 0x80070108u: goto label_80070108;
    case 0x8007010Cu: goto label_8007010C;
    case 0x80070110u: goto label_80070110;
    case 0x80070114u: goto label_80070114;
    case 0x80070118u: goto label_80070118;
    case 0x8007011Cu: goto label_8007011C;
    case 0x80070120u: goto label_80070120;
    case 0x80070124u: goto label_80070124;
    case 0x80070128u: goto label_80070128;
    case 0x8007012Cu: goto label_8007012C;
    case 0x80070130u: goto label_80070130;
    case 0x80070134u: goto label_80070134;
    case 0x80070138u: goto label_80070138;
    case 0x8007013Cu: goto label_8007013C;
    case 0x80070140u: goto label_80070140;
    case 0x80070144u: goto label_80070144;
    case 0x80070148u: goto label_80070148;
    case 0x8007014Cu: goto label_8007014C;
    case 0x80070150u: goto label_80070150;
    case 0x80070154u: goto label_80070154;
    case 0x80070158u: goto label_80070158;
    case 0x8007015Cu: goto label_8007015C;
    case 0x80070160u: goto label_80070160;
    case 0x80070164u: goto label_80070164;
    case 0x80070168u: goto label_80070168;
    case 0x8007016Cu: goto label_8007016C;
    case 0x80070170u: goto label_80070170;
    case 0x80070174u: goto label_80070174;
    case 0x80070178u: goto label_80070178;
    case 0x8007017Cu: goto label_8007017C;
    case 0x80070180u: goto label_80070180;
    case 0x80070184u: goto label_80070184;
    case 0x80070188u: goto label_80070188;
    case 0x8007018Cu: goto label_8007018C;
    case 0x80070190u: goto label_80070190;
    case 0x80070194u: goto label_80070194;
    case 0x80070198u: goto label_80070198;
    case 0x8007019Cu: goto label_8007019C;
    case 0x800701A0u: goto label_800701A0;
    case 0x800701A4u: goto label_800701A4;
    case 0x800701A8u: goto label_800701A8;
    case 0x800701ACu: goto label_800701AC;
    case 0x800701B0u: goto label_800701B0;
    case 0x800701B4u: goto label_800701B4;
    case 0x800701B8u: goto label_800701B8;
    case 0x800701BCu: goto label_800701BC;
    case 0x800701C0u: goto label_800701C0;
    case 0x800701C4u: goto label_800701C4;
    case 0x800701C8u: goto label_800701C8;
    case 0x800701CCu: goto label_800701CC;
    case 0x800701D0u: goto label_800701D0;
    case 0x800701D4u: goto label_800701D4;
    case 0x800701D8u: goto label_800701D8;
    case 0x800701DCu: goto label_800701DC;
    case 0x800701E0u: goto label_800701E0;
    case 0x800701E4u: goto label_800701E4;
    case 0x800701E8u: goto label_800701E8;
    case 0x800701ECu: goto label_800701EC;
    case 0x800701F0u: goto label_800701F0;
    case 0x800701F4u: goto label_800701F4;
    case 0x800701F8u: goto label_800701F8;
    case 0x800701FCu: goto label_800701FC;
    case 0x80070200u: goto label_80070200;
    case 0x80070204u: goto label_80070204;
    case 0x80070208u: goto label_80070208;
    case 0x8007020Cu: goto label_8007020C;
    case 0x80070210u: goto label_80070210;
    case 0x80070214u: goto label_80070214;
    case 0x80070218u: goto label_80070218;
    case 0x8007021Cu: goto label_8007021C;
    case 0x80070220u: goto label_80070220;
    case 0x80070224u: goto label_80070224;
    case 0x80070228u: goto label_80070228;
    case 0x8007022Cu: goto label_8007022C;
    case 0x80070230u: goto label_80070230;
    case 0x80070234u: goto label_80070234;
    case 0x80070238u: goto label_80070238;
    case 0x8007023Cu: goto label_8007023C;
    case 0x80070240u: goto label_80070240;
    case 0x80070244u: goto label_80070244;
    case 0x80070248u: goto label_80070248;
    case 0x8007024Cu: goto label_8007024C;
    case 0x80070250u: goto label_80070250;
    case 0x80070254u: goto label_80070254;
    case 0x80070258u: goto label_80070258;
    case 0x8007025Cu: goto label_8007025C;
    case 0x80070260u: goto label_80070260;
    case 0x80070264u: goto label_80070264;
    case 0x80070268u: goto label_80070268;
    case 0x8007026Cu: goto label_8007026C;
    case 0x80070270u: goto label_80070270;
    case 0x80070274u: goto label_80070274;
    case 0x80070278u: goto label_80070278;
    case 0x8007027Cu: goto label_8007027C;
    case 0x80070280u: goto label_80070280;
    case 0x80070284u: goto label_80070284;
    case 0x80070288u: goto label_80070288;
    case 0x8007028Cu: goto label_8007028C;
    case 0x80070290u: goto label_80070290;
    case 0x80070294u: goto label_80070294;
    case 0x80070298u: goto label_80070298;
    case 0x8007029Cu: goto label_8007029C;
    case 0x800702A0u: goto label_800702A0;
    case 0x800702A4u: goto label_800702A4;
    case 0x800702A8u: goto label_800702A8;
    case 0x800702ACu: goto label_800702AC;
    case 0x800702B0u: goto label_800702B0;
    case 0x800702B4u: goto label_800702B4;
    case 0x800702B8u: goto label_800702B8;
    case 0x800702BCu: goto label_800702BC;
    case 0x800702C0u: goto label_800702C0;
    case 0x800702C4u: goto label_800702C4;
    case 0x800702C8u: goto label_800702C8;
    case 0x800702CCu: goto label_800702CC;
    case 0x800702D0u: goto label_800702D0;
    case 0x800702D4u: goto label_800702D4;
    case 0x800702D8u: goto label_800702D8;
    case 0x800702DCu: goto label_800702DC;
    case 0x800702E0u: goto label_800702E0;
    case 0x800702E4u: goto label_800702E4;
    case 0x800702E8u: goto label_800702E8;
    case 0x800702ECu: goto label_800702EC;
    case 0x800702F0u: goto label_800702F0;
    case 0x800702F4u: goto label_800702F4;
    case 0x800702F8u: goto label_800702F8;
    case 0x800702FCu: goto label_800702FC;
    case 0x80070300u: goto label_80070300;
    case 0x80070304u: goto label_80070304;
    case 0x80070308u: goto label_80070308;
    case 0x8007030Cu: goto label_8007030C;
    case 0x80070310u: goto label_80070310;
    case 0x80070314u: goto label_80070314;
    case 0x80070318u: goto label_80070318;
    case 0x8007031Cu: goto label_8007031C;
    case 0x80070320u: goto label_80070320;
    case 0x80070324u: goto label_80070324;
    case 0x80070328u: goto label_80070328;
    case 0x8007032Cu: goto label_8007032C;
    case 0x80070330u: goto label_80070330;
    case 0x80070334u: goto label_80070334;
    case 0x80070338u: goto label_80070338;
    case 0x8007033Cu: goto label_8007033C;
    case 0x80070340u: goto label_80070340;
    case 0x80070344u: goto label_80070344;
    case 0x80070348u: goto label_80070348;
    case 0x8007034Cu: goto label_8007034C;
    case 0x80070350u: goto label_80070350;
    case 0x80070354u: goto label_80070354;
    case 0x80070358u: goto label_80070358;
    case 0x8007035Cu: goto label_8007035C;
    case 0x80070360u: goto label_80070360;
    case 0x80070364u: goto label_80070364;
    case 0x80070368u: goto label_80070368;
    case 0x8007036Cu: goto label_8007036C;
    case 0x80070370u: goto label_80070370;
    case 0x80070374u: goto label_80070374;
    case 0x80070378u: goto label_80070378;
    case 0x8007037Cu: goto label_8007037C;
    case 0x80070380u: goto label_80070380;
    case 0x80070384u: goto label_80070384;
    case 0x80070388u: goto label_80070388;
    case 0x8007038Cu: goto label_8007038C;
    case 0x80070390u: goto label_80070390;
    case 0x80070394u: goto label_80070394;
    case 0x80070398u: goto label_80070398;
    case 0x8007039Cu: goto label_8007039C;
    case 0x800703A0u: goto label_800703A0;
    case 0x800703A4u: goto label_800703A4;
    case 0x800703A8u: goto label_800703A8;
    case 0x800703ACu: goto label_800703AC;
    case 0x800703B0u: goto label_800703B0;
    case 0x800703B4u: goto label_800703B4;
    case 0x800703B8u: goto label_800703B8;
    case 0x800703BCu: goto label_800703BC;
    case 0x800703C0u: goto label_800703C0;
    case 0x800703C4u: goto label_800703C4;
    case 0x800703C8u: goto label_800703C8;
    case 0x800703CCu: goto label_800703CC;
    case 0x800703D0u: goto label_800703D0;
    case 0x800703D4u: goto label_800703D4;
    case 0x800703D8u: goto label_800703D8;
    case 0x800703DCu: goto label_800703DC;
    case 0x800703E0u: goto label_800703E0;
    case 0x800703E4u: goto label_800703E4;
    case 0x800703E8u: goto label_800703E8;
    case 0x800703ECu: goto label_800703EC;
    case 0x800703F0u: goto label_800703F0;
    case 0x800703F4u: goto label_800703F4;
    case 0x800703F8u: goto label_800703F8;
    case 0x800703FCu: goto label_800703FC;
    case 0x80070400u: goto label_80070400;
    case 0x80070404u: goto label_80070404;
    case 0x80070408u: goto label_80070408;
    case 0x8007040Cu: goto label_8007040C;
    case 0x80070410u: goto label_80070410;
    case 0x80070414u: goto label_80070414;
    case 0x80070418u: goto label_80070418;
    case 0x8007041Cu: goto label_8007041C;
    case 0x80070420u: goto label_80070420;
    case 0x80070424u: goto label_80070424;
    case 0x80070428u: goto label_80070428;
    case 0x8007042Cu: goto label_8007042C;
    case 0x80070430u: goto label_80070430;
    case 0x80070434u: goto label_80070434;
    case 0x80070438u: goto label_80070438;
    case 0x8007043Cu: goto label_8007043C;
    case 0x80070440u: goto label_80070440;
    case 0x80070444u: goto label_80070444;
    case 0x80070448u: goto label_80070448;
    case 0x8007044Cu: goto label_8007044C;
    case 0x80070450u: goto label_80070450;
    case 0x80070454u: goto label_80070454;
    case 0x80070458u: goto label_80070458;
    case 0x8007045Cu: goto label_8007045C;
    case 0x80070460u: goto label_80070460;
    case 0x80070464u: goto label_80070464;
    case 0x80070468u: goto label_80070468;
    case 0x8007046Cu: goto label_8007046C;
    case 0x80070470u: goto label_80070470;
    case 0x80070474u: goto label_80070474;
    case 0x80070478u: goto label_80070478;
    case 0x8007047Cu: goto label_8007047C;
    case 0x80070480u: goto label_80070480;
    case 0x80070484u: goto label_80070484;
    case 0x80070488u: goto label_80070488;
    case 0x8007048Cu: goto label_8007048C;
    case 0x80070490u: goto label_80070490;
    case 0x80070494u: goto label_80070494;
    case 0x80070498u: goto label_80070498;
    case 0x8007049Cu: goto label_8007049C;
    case 0x800704A0u: goto label_800704A0;
    case 0x800704A4u: goto label_800704A4;
    case 0x800704A8u: goto label_800704A8;
    case 0x800704ACu: goto label_800704AC;
    case 0x800704B0u: goto label_800704B0;
    case 0x800704B4u: goto label_800704B4;
    case 0x800704B8u: goto label_800704B8;
    case 0x800704BCu: goto label_800704BC;
    case 0x800704C0u: goto label_800704C0;
    case 0x800704C4u: goto label_800704C4;
    case 0x800704C8u: goto label_800704C8;
    case 0x800704CCu: goto label_800704CC;
    case 0x800704D0u: goto label_800704D0;
    case 0x800704D4u: goto label_800704D4;
    case 0x800704D8u: goto label_800704D8;
    case 0x800704DCu: goto label_800704DC;
    case 0x800704E0u: goto label_800704E0;
    case 0x800704E4u: goto label_800704E4;
    case 0x800704E8u: goto label_800704E8;
    case 0x800704ECu: goto label_800704EC;
    case 0x800704F0u: goto label_800704F0;
    case 0x800704F4u: goto label_800704F4;
    case 0x800704F8u: goto label_800704F8;
    case 0x800704FCu: goto label_800704FC;
    case 0x80070500u: goto label_80070500;
    case 0x80070504u: goto label_80070504;
    case 0x80070508u: goto label_80070508;
    case 0x8007050Cu: goto label_8007050C;
    case 0x80070510u: goto label_80070510;
    case 0x80070514u: goto label_80070514;
    case 0x80070518u: goto label_80070518;
    case 0x8007051Cu: goto label_8007051C;
    case 0x80070520u: goto label_80070520;
    case 0x80070524u: goto label_80070524;
    case 0x80070528u: goto label_80070528;
    case 0x8007052Cu: goto label_8007052C;
    case 0x80070530u: goto label_80070530;
    case 0x80070534u: goto label_80070534;
    case 0x80070538u: goto label_80070538;
    case 0x8007053Cu: goto label_8007053C;
    case 0x80070540u: goto label_80070540;
    case 0x80070544u: goto label_80070544;
    case 0x80070548u: goto label_80070548;
    case 0x8007054Cu: goto label_8007054C;
    case 0x80070550u: goto label_80070550;
    case 0x80070554u: goto label_80070554;
    case 0x80070558u: goto label_80070558;
    case 0x8007055Cu: goto label_8007055C;
    case 0x80070560u: goto label_80070560;
    case 0x80070564u: goto label_80070564;
    case 0x80070568u: goto label_80070568;
    case 0x8007056Cu: goto label_8007056C;
    case 0x80070570u: goto label_80070570;
    case 0x80070574u: goto label_80070574;
    case 0x80070578u: goto label_80070578;
    case 0x8007057Cu: goto label_8007057C;
    case 0x80070580u: goto label_80070580;
    case 0x80070584u: goto label_80070584;
    case 0x80070588u: goto label_80070588;
    case 0x8007058Cu: goto label_8007058C;
    case 0x80070590u: goto label_80070590;
    case 0x80070594u: goto label_80070594;
    case 0x80070598u: goto label_80070598;
    case 0x8007059Cu: goto label_8007059C;
    case 0x800705A0u: goto label_800705A0;
    case 0x800705A4u: goto label_800705A4;
    case 0x800705A8u: goto label_800705A8;
    case 0x800705ACu: goto label_800705AC;
    case 0x800705B0u: goto label_800705B0;
    case 0x800705B4u: goto label_800705B4;
    case 0x800705B8u: goto label_800705B8;
    case 0x800705BCu: goto label_800705BC;
    case 0x800705C0u: goto label_800705C0;
    case 0x800705C4u: goto label_800705C4;
    case 0x800705C8u: goto label_800705C8;
    case 0x800705CCu: goto label_800705CC;
    case 0x800705D0u: goto label_800705D0;
    case 0x800705D4u: goto label_800705D4;
    case 0x800705D8u: goto label_800705D8;
    case 0x800705DCu: goto label_800705DC;
    case 0x800705E0u: goto label_800705E0;
    case 0x800705E4u: goto label_800705E4;
    case 0x800705E8u: goto label_800705E8;
    case 0x800705ECu: goto label_800705EC;
    case 0x800705F0u: goto label_800705F0;
    case 0x800705F4u: goto label_800705F4;
    case 0x800705F8u: goto label_800705F8;
    case 0x800705FCu: goto label_800705FC;
    case 0x80070600u: goto label_80070600;
    case 0x80070604u: goto label_80070604;
    case 0x80070608u: goto label_80070608;
    case 0x8007060Cu: goto label_8007060C;
    case 0x80070610u: goto label_80070610;
    case 0x80070614u: goto label_80070614;
    case 0x80070618u: goto label_80070618;
    case 0x8007061Cu: goto label_8007061C;
    case 0x80070620u: goto label_80070620;
    case 0x80070624u: goto label_80070624;
    case 0x80070628u: goto label_80070628;
    case 0x8007062Cu: goto label_8007062C;
    case 0x80070630u: goto label_80070630;
    case 0x80070634u: goto label_80070634;
    case 0x80070638u: goto label_80070638;
    case 0x8007063Cu: goto label_8007063C;
    case 0x80070640u: goto label_80070640;
    case 0x80070644u: goto label_80070644;
    case 0x80070648u: goto label_80070648;
    case 0x8007064Cu: goto label_8007064C;
    case 0x80070650u: goto label_80070650;
    case 0x80070654u: goto label_80070654;
    case 0x80070658u: goto label_80070658;
    case 0x8007065Cu: goto label_8007065C;
    case 0x80070660u: goto label_80070660;
    case 0x80070664u: goto label_80070664;
    case 0x80070668u: goto label_80070668;
    case 0x8007066Cu: goto label_8007066C;
    case 0x80070670u: goto label_80070670;
    case 0x80070674u: goto label_80070674;
    case 0x80070678u: goto label_80070678;
    case 0x8007067Cu: goto label_8007067C;
    case 0x80070680u: goto label_80070680;
    case 0x80070684u: goto label_80070684;
    case 0x80070688u: goto label_80070688;
    case 0x8007068Cu: goto label_8007068C;
    case 0x80070690u: goto label_80070690;
    case 0x80070694u: goto label_80070694;
    case 0x80070698u: goto label_80070698;
    case 0x8007069Cu: goto label_8007069C;
    case 0x800706A0u: goto label_800706A0;
    case 0x800706A4u: goto label_800706A4;
    case 0x800706A8u: goto label_800706A8;
    case 0x800706ACu: goto label_800706AC;
    case 0x800706B0u: goto label_800706B0;
    case 0x800706B4u: goto label_800706B4;
    case 0x800706B8u: goto label_800706B8;
    case 0x800706BCu: goto label_800706BC;
    case 0x800706C0u: goto label_800706C0;
    case 0x800706C4u: goto label_800706C4;
    case 0x800706C8u: goto label_800706C8;
    case 0x800706CCu: goto label_800706CC;
    case 0x800706D0u: goto label_800706D0;
    case 0x800706D4u: goto label_800706D4;
    case 0x800706D8u: goto label_800706D8;
    case 0x800706DCu: goto label_800706DC;
    case 0x800706E0u: goto label_800706E0;
    case 0x800706E4u: goto label_800706E4;
    case 0x800706E8u: goto label_800706E8;
    case 0x800706ECu: goto label_800706EC;
    case 0x800706F0u: goto label_800706F0;
    case 0x800706F4u: goto label_800706F4;
    case 0x800706F8u: goto label_800706F8;
    case 0x800706FCu: goto label_800706FC;
    case 0x80070700u: goto label_80070700;
    case 0x80070704u: goto label_80070704;
    case 0x80070708u: goto label_80070708;
    case 0x8007070Cu: goto label_8007070C;
    case 0x80070710u: goto label_80070710;
    case 0x80070714u: goto label_80070714;
    case 0x80070718u: goto label_80070718;
    case 0x8007071Cu: goto label_8007071C;
    case 0x80070720u: goto label_80070720;
    case 0x80070724u: goto label_80070724;
    case 0x80070728u: goto label_80070728;
    case 0x8007072Cu: goto label_8007072C;
    case 0x80070730u: goto label_80070730;
    case 0x80070734u: goto label_80070734;
    case 0x80070738u: goto label_80070738;
    case 0x8007073Cu: goto label_8007073C;
    case 0x80070740u: goto label_80070740;
    case 0x80070744u: goto label_80070744;
    case 0x80070748u: goto label_80070748;
    case 0x8007074Cu: goto label_8007074C;
    case 0x80070750u: goto label_80070750;
    case 0x80070754u: goto label_80070754;
    case 0x80070758u: goto label_80070758;
    case 0x8007075Cu: goto label_8007075C;
    case 0x80070760u: goto label_80070760;
    case 0x80070764u: goto label_80070764;
    case 0x80070768u: goto label_80070768;
    case 0x8007076Cu: goto label_8007076C;
    case 0x80070770u: goto label_80070770;
    case 0x80070774u: goto label_80070774;
    case 0x80070778u: goto label_80070778;
    case 0x8007077Cu: goto label_8007077C;
    case 0x80070780u: goto label_80070780;
    case 0x80070784u: goto label_80070784;
    case 0x80070788u: goto label_80070788;
    case 0x8007078Cu: goto label_8007078C;
    case 0x80070790u: goto label_80070790;
    case 0x80070794u: goto label_80070794;
    case 0x80070798u: goto label_80070798;
    case 0x8007079Cu: goto label_8007079C;
    case 0x800707A0u: goto label_800707A0;
    case 0x800707A4u: goto label_800707A4;
    case 0x800707A8u: goto label_800707A8;
    case 0x800707ACu: goto label_800707AC;
    case 0x800707B0u: goto label_800707B0;
    case 0x800707B4u: goto label_800707B4;
    case 0x800707B8u: goto label_800707B8;
    case 0x800707BCu: goto label_800707BC;
    case 0x800707C0u: goto label_800707C0;
    case 0x800707C4u: goto label_800707C4;
    case 0x800707C8u: goto label_800707C8;
    case 0x800707CCu: goto label_800707CC;
    case 0x800707D0u: goto label_800707D0;
    case 0x800707D4u: goto label_800707D4;
    case 0x800707D8u: goto label_800707D8;
    case 0x800707DCu: goto label_800707DC;
    case 0x800707E0u: goto label_800707E0;
    case 0x800707E4u: goto label_800707E4;
    case 0x800707E8u: goto label_800707E8;
    case 0x800707ECu: goto label_800707EC;
    case 0x800707F0u: goto label_800707F0;
    case 0x800707F4u: goto label_800707F4;
    case 0x800707F8u: goto label_800707F8;
    case 0x800707FCu: goto label_800707FC;
    case 0x80070800u: goto label_80070800;
    case 0x80070804u: goto label_80070804;
    case 0x80070808u: goto label_80070808;
    case 0x8007080Cu: goto label_8007080C;
    case 0x80070810u: goto label_80070810;
    case 0x80070814u: goto label_80070814;
    case 0x80070818u: goto label_80070818;
    case 0x8007081Cu: goto label_8007081C;
    case 0x80070820u: goto label_80070820;
    case 0x80070824u: goto label_80070824;
    case 0x80070828u: goto label_80070828;
    case 0x8007082Cu: goto label_8007082C;
    case 0x80070830u: goto label_80070830;
    case 0x80070834u: goto label_80070834;
    case 0x80070838u: goto label_80070838;
    case 0x8007083Cu: goto label_8007083C;
    case 0x80070840u: goto label_80070840;
    case 0x80070844u: goto label_80070844;
    case 0x80070848u: goto label_80070848;
    case 0x8007084Cu: goto label_8007084C;
    case 0x80070850u: goto label_80070850;
    case 0x80070854u: goto label_80070854;
    case 0x80070858u: goto label_80070858;
    case 0x8007085Cu: goto label_8007085C;
    case 0x80070860u: goto label_80070860;
    case 0x80070864u: goto label_80070864;
    case 0x80070868u: goto label_80070868;
    case 0x8007086Cu: goto label_8007086C;
    case 0x80070870u: goto label_80070870;
    case 0x80070874u: goto label_80070874;
    case 0x80070878u: goto label_80070878;
    case 0x8007087Cu: goto label_8007087C;
    case 0x80070880u: goto label_80070880;
    case 0x80070884u: goto label_80070884;
    case 0x80070888u: goto label_80070888;
    case 0x8007088Cu: goto label_8007088C;
    case 0x80070890u: goto label_80070890;
    case 0x80070894u: goto label_80070894;
    case 0x80070898u: goto label_80070898;
    case 0x8007089Cu: goto label_8007089C;
    case 0x800708A0u: goto label_800708A0;
    case 0x800708A4u: goto label_800708A4;
    case 0x800708A8u: goto label_800708A8;
    case 0x800708ACu: goto label_800708AC;
    case 0x800708B0u: goto label_800708B0;
    case 0x800708B4u: goto label_800708B4;
    case 0x800708B8u: goto label_800708B8;
    case 0x800708BCu: goto label_800708BC;
    case 0x800708C0u: goto label_800708C0;
    case 0x800708C4u: goto label_800708C4;
    case 0x800708C8u: goto label_800708C8;
    case 0x800708CCu: goto label_800708CC;
    case 0x800708D0u: goto label_800708D0;
    case 0x800708D4u: goto label_800708D4;
    case 0x800708D8u: goto label_800708D8;
    case 0x800708DCu: goto label_800708DC;
    case 0x800708E0u: goto label_800708E0;
    case 0x800708E4u: goto label_800708E4;
    case 0x800708E8u: goto label_800708E8;
    case 0x800708ECu: goto label_800708EC;
    case 0x800708F0u: goto label_800708F0;
    case 0x800708F4u: goto label_800708F4;
    case 0x800708F8u: goto label_800708F8;
    case 0x800708FCu: goto label_800708FC;
    case 0x80070900u: goto label_80070900;
    case 0x80070904u: goto label_80070904;
    case 0x80070908u: goto label_80070908;
    case 0x8007090Cu: goto label_8007090C;
    case 0x80070910u: goto label_80070910;
    case 0x80070914u: goto label_80070914;
    case 0x80070918u: goto label_80070918;
    case 0x8007091Cu: goto label_8007091C;
    case 0x80070920u: goto label_80070920;
    case 0x80070924u: goto label_80070924;
    case 0x80070928u: goto label_80070928;
    case 0x8007092Cu: goto label_8007092C;
    case 0x80070930u: goto label_80070930;
    case 0x80070934u: goto label_80070934;
    case 0x80070938u: goto label_80070938;
    case 0x8007093Cu: goto label_8007093C;
    case 0x80070940u: goto label_80070940;
    case 0x80070944u: goto label_80070944;
    case 0x80070948u: goto label_80070948;
    case 0x8007094Cu: goto label_8007094C;
    case 0x80070950u: goto label_80070950;
    case 0x80070954u: goto label_80070954;
    case 0x80070958u: goto label_80070958;
    case 0x8007095Cu: goto label_8007095C;
    case 0x80070960u: goto label_80070960;
    case 0x80070964u: goto label_80070964;
    case 0x80070968u: goto label_80070968;
    case 0x8007096Cu: goto label_8007096C;
    case 0x80070970u: goto label_80070970;
    case 0x80070974u: goto label_80070974;
    case 0x80070978u: goto label_80070978;
    case 0x8007097Cu: goto label_8007097C;
    case 0x80070980u: goto label_80070980;
    case 0x80070984u: goto label_80070984;
    case 0x80070988u: goto label_80070988;
    case 0x8007098Cu: goto label_8007098C;
    case 0x80070990u: goto label_80070990;
    case 0x80070994u: goto label_80070994;
    case 0x80070998u: goto label_80070998;
    case 0x8007099Cu: goto label_8007099C;
    case 0x800709A0u: goto label_800709A0;
    case 0x800709A4u: goto label_800709A4;
    case 0x800709A8u: goto label_800709A8;
    case 0x800709ACu: goto label_800709AC;
    case 0x800709B0u: goto label_800709B0;
    case 0x800709B4u: goto label_800709B4;
    case 0x800709B8u: goto label_800709B8;
    case 0x800709BCu: goto label_800709BC;
    case 0x800709C0u: goto label_800709C0;
    case 0x800709C4u: goto label_800709C4;
    case 0x800709C8u: goto label_800709C8;
    case 0x800709CCu: goto label_800709CC;
    case 0x800709D0u: goto label_800709D0;
    case 0x800709D4u: goto label_800709D4;
    case 0x800709D8u: goto label_800709D8;
    case 0x800709DCu: goto label_800709DC;
    case 0x800709E0u: goto label_800709E0;
    case 0x800709E4u: goto label_800709E4;
    case 0x800709E8u: goto label_800709E8;
    case 0x800709ECu: goto label_800709EC;
    case 0x800709F0u: goto label_800709F0;
    case 0x800709F4u: goto label_800709F4;
    case 0x800709F8u: goto label_800709F8;
    case 0x800709FCu: goto label_800709FC;
    case 0x80070A00u: goto label_80070A00;
    case 0x80070A04u: goto label_80070A04;
    case 0x80070A08u: goto label_80070A08;
    case 0x80070A0Cu: goto label_80070A0C;
    case 0x80070A10u: goto label_80070A10;
    case 0x80070A14u: goto label_80070A14;
    case 0x80070A18u: goto label_80070A18;
    case 0x80070A1Cu: goto label_80070A1C;
    case 0x80070A20u: goto label_80070A20;
    case 0x80070A24u: goto label_80070A24;
    case 0x80070A28u: goto label_80070A28;
    case 0x80070A2Cu: goto label_80070A2C;
    case 0x80070A30u: goto label_80070A30;
    case 0x80070A34u: goto label_80070A34;
    case 0x80070A38u: goto label_80070A38;
    case 0x80070A3Cu: goto label_80070A3C;
    case 0x80070A40u: goto label_80070A40;
    case 0x80070A44u: goto label_80070A44;
    case 0x80070A48u: goto label_80070A48;
    case 0x80070A4Cu: goto label_80070A4C;
    case 0x80070A50u: goto label_80070A50;
    case 0x80070A54u: goto label_80070A54;
    case 0x80070A58u: goto label_80070A58;
    case 0x80070A5Cu: goto label_80070A5C;
    case 0x80070A60u: goto label_80070A60;
    case 0x80070A64u: goto label_80070A64;
    case 0x80070A68u: goto label_80070A68;
    case 0x80070A6Cu: goto label_80070A6C;
    case 0x80070A70u: goto label_80070A70;
    case 0x80070A74u: goto label_80070A74;
    case 0x80070A78u: goto label_80070A78;
    case 0x80070A7Cu: goto label_80070A7C;
    case 0x80070A80u: goto label_80070A80;
    case 0x80070A84u: goto label_80070A84;
    case 0x80070A88u: goto label_80070A88;
    case 0x80070A8Cu: goto label_80070A8C;
    case 0x80070A90u: goto label_80070A90;
    case 0x80070A94u: goto label_80070A94;
    case 0x80070A98u: goto label_80070A98;
    case 0x80070A9Cu: goto label_80070A9C;
    case 0x80070AA0u: goto label_80070AA0;
    case 0x80070AA4u: goto label_80070AA4;
    case 0x80070AA8u: goto label_80070AA8;
    case 0x80070AACu: goto label_80070AAC;
    case 0x80070AB0u: goto label_80070AB0;
    case 0x80070AB4u: goto label_80070AB4;
    case 0x80070AB8u: goto label_80070AB8;
    case 0x80070ABCu: goto label_80070ABC;
    case 0x80070AC0u: goto label_80070AC0;
    case 0x80070AC4u: goto label_80070AC4;
    case 0x80070AC8u: goto label_80070AC8;
    case 0x80070ACCu: goto label_80070ACC;
    case 0x80070AD0u: goto label_80070AD0;
    case 0x80070AD4u: goto label_80070AD4;
    case 0x80070AD8u: goto label_80070AD8;
    case 0x80070ADCu: goto label_80070ADC;
    case 0x80070AE0u: goto label_80070AE0;
    case 0x80070AE4u: goto label_80070AE4;
    case 0x80070AE8u: goto label_80070AE8;
    case 0x80070AECu: goto label_80070AEC;
    case 0x80070AF0u: goto label_80070AF0;
    case 0x80070AF4u: goto label_80070AF4;
    case 0x80070AF8u: goto label_80070AF8;
    case 0x80070AFCu: goto label_80070AFC;
    case 0x80070B00u: goto label_80070B00;
    case 0x80070B04u: goto label_80070B04;
    case 0x80070B08u: goto label_80070B08;
    case 0x80070B0Cu: goto label_80070B0C;
    case 0x80070B10u: goto label_80070B10;
    case 0x80070B14u: goto label_80070B14;
    case 0x80070B18u: goto label_80070B18;
    case 0x80070B1Cu: goto label_80070B1C;
    case 0x80070B20u: goto label_80070B20;
    case 0x80070B24u: goto label_80070B24;
    case 0x80070B28u: goto label_80070B28;
    case 0x80070B2Cu: goto label_80070B2C;
    case 0x80070B30u: goto label_80070B30;
    case 0x80070B34u: goto label_80070B34;
    case 0x80070B38u: goto label_80070B38;
    case 0x80070B3Cu: goto label_80070B3C;
    case 0x80070B40u: goto label_80070B40;
    case 0x80070B44u: goto label_80070B44;
    case 0x80070B48u: goto label_80070B48;
    case 0x80070B4Cu: goto label_80070B4C;
    case 0x80070B50u: goto label_80070B50;
    case 0x80070B54u: goto label_80070B54;
    case 0x80070B58u: goto label_80070B58;
    case 0x80070B5Cu: goto label_80070B5C;
    case 0x80070B60u: goto label_80070B60;
    case 0x80070B64u: goto label_80070B64;
    case 0x80070B68u: goto label_80070B68;
    case 0x80070B6Cu: goto label_80070B6C;
    case 0x80070B70u: goto label_80070B70;
    case 0x80070B74u: goto label_80070B74;
    case 0x80070B78u: goto label_80070B78;
    case 0x80070B7Cu: goto label_80070B7C;
    case 0x80070B80u: goto label_80070B80;
    case 0x80070B84u: goto label_80070B84;
    case 0x80070B88u: goto label_80070B88;
    case 0x80070B8Cu: goto label_80070B8C;
    case 0x80070B90u: goto label_80070B90;
    case 0x80070B94u: goto label_80070B94;
    case 0x80070B98u: goto label_80070B98;
    case 0x80070B9Cu: goto label_80070B9C;
    case 0x80070BA0u: goto label_80070BA0;
    case 0x80070BA4u: goto label_80070BA4;
    case 0x80070BA8u: goto label_80070BA8;
    case 0x80070BACu: goto label_80070BAC;
    case 0x80070BB0u: goto label_80070BB0;
    case 0x80070BB4u: goto label_80070BB4;
    case 0x80070BB8u: goto label_80070BB8;
    case 0x80070BBCu: goto label_80070BBC;
    case 0x80070BC0u: goto label_80070BC0;
    case 0x80070BC4u: goto label_80070BC4;
    case 0x80070BC8u: goto label_80070BC8;
    case 0x80070BCCu: goto label_80070BCC;
    case 0x80070BD0u: goto label_80070BD0;
    case 0x80070BD4u: goto label_80070BD4;
    case 0x80070BD8u: goto label_80070BD8;
    case 0x80070BDCu: goto label_80070BDC;
    case 0x80070BE0u: goto label_80070BE0;
    case 0x80070BE4u: goto label_80070BE4;
    case 0x80070BE8u: goto label_80070BE8;
    case 0x80070BECu: goto label_80070BEC;
    case 0x80070BF0u: goto label_80070BF0;
    case 0x80070BF4u: goto label_80070BF4;
    case 0x80070BF8u: goto label_80070BF8;
    case 0x80070BFCu: goto label_80070BFC;
    case 0x80070C00u: goto label_80070C00;
    case 0x80070C04u: goto label_80070C04;
    case 0x80070C08u: goto label_80070C08;
    case 0x80070C0Cu: goto label_80070C0C;
    case 0x80070C10u: goto label_80070C10;
    case 0x80070C14u: goto label_80070C14;
    case 0x80070C18u: goto label_80070C18;
    case 0x80070C1Cu: goto label_80070C1C;
    case 0x80070C20u: goto label_80070C20;
    case 0x80070C24u: goto label_80070C24;
    case 0x80070C28u: goto label_80070C28;
    case 0x80070C2Cu: goto label_80070C2C;
    case 0x80070C30u: goto label_80070C30;
    case 0x80070C34u: goto label_80070C34;
    case 0x80070C38u: goto label_80070C38;
    case 0x80070C3Cu: goto label_80070C3C;
    case 0x80070C40u: goto label_80070C40;
    case 0x80070C44u: goto label_80070C44;
    case 0x80070C48u: goto label_80070C48;
    case 0x80070C4Cu: goto label_80070C4C;
    case 0x80070C50u: goto label_80070C50;
    case 0x80070C54u: goto label_80070C54;
    case 0x80070C58u: goto label_80070C58;
    case 0x80070C5Cu: goto label_80070C5C;
    case 0x80070C60u: goto label_80070C60;
    case 0x80070C64u: goto label_80070C64;
    case 0x80070C68u: goto label_80070C68;
    case 0x80070C6Cu: goto label_80070C6C;
    case 0x80070C70u: goto label_80070C70;
    case 0x80070C74u: goto label_80070C74;
    case 0x80070C78u: goto label_80070C78;
    case 0x80070C7Cu: goto label_80070C7C;
    case 0x80070C80u: goto label_80070C80;
    case 0x80070C84u: goto label_80070C84;
    case 0x80070C88u: goto label_80070C88;
    case 0x80070C8Cu: goto label_80070C8C;
    case 0x80070C90u: goto label_80070C90;
    case 0x80070C94u: goto label_80070C94;
    case 0x80070C98u: goto label_80070C98;
    case 0x80070C9Cu: goto label_80070C9C;
    case 0x80070CA0u: goto label_80070CA0;
    case 0x80070CA4u: goto label_80070CA4;
    case 0x80070CA8u: goto label_80070CA8;
    case 0x80070CACu: goto label_80070CAC;
    case 0x80070CB0u: goto label_80070CB0;
    case 0x80070CB4u: goto label_80070CB4;
    case 0x80070CB8u: goto label_80070CB8;
    case 0x80070CBCu: goto label_80070CBC;
    case 0x80070CC0u: goto label_80070CC0;
    case 0x80070CC4u: goto label_80070CC4;
    case 0x80070CC8u: goto label_80070CC8;
    case 0x80070CCCu: goto label_80070CCC;
    case 0x80070CD0u: goto label_80070CD0;
    case 0x80070CD4u: goto label_80070CD4;
    case 0x80070CD8u: goto label_80070CD8;
    case 0x80070CDCu: goto label_80070CDC;
    case 0x80070CE0u: goto label_80070CE0;
    case 0x80070CE4u: goto label_80070CE4;
    case 0x80070CE8u: goto label_80070CE8;
    case 0x80070CECu: goto label_80070CEC;
    case 0x80070CF0u: goto label_80070CF0;
    case 0x80070CF4u: goto label_80070CF4;
    case 0x80070CF8u: goto label_80070CF8;
    case 0x80070CFCu: goto label_80070CFC;
    case 0x80070D00u: goto label_80070D00;
    case 0x80070D04u: goto label_80070D04;
    case 0x80070D08u: goto label_80070D08;
    case 0x80070D0Cu: goto label_80070D0C;
    case 0x80070D10u: goto label_80070D10;
    case 0x80070D14u: goto label_80070D14;
    case 0x80070D18u: goto label_80070D18;
    case 0x80070D1Cu: goto label_80070D1C;
    case 0x80070D20u: goto label_80070D20;
    case 0x80070D24u: goto label_80070D24;
    case 0x80070D28u: goto label_80070D28;
    case 0x80070D2Cu: goto label_80070D2C;
    case 0x80070D30u: goto label_80070D30;
    case 0x80070D34u: goto label_80070D34;
    case 0x80070D38u: goto label_80070D38;
    case 0x80070D3Cu: goto label_80070D3C;
    case 0x80070D40u: goto label_80070D40;
    case 0x80070D44u: goto label_80070D44;
    case 0x80070D48u: goto label_80070D48;
    case 0x80070D4Cu: goto label_80070D4C;
    case 0x80070D50u: goto label_80070D50;
    case 0x80070D54u: goto label_80070D54;
    case 0x80070D58u: goto label_80070D58;
    case 0x80070D5Cu: goto label_80070D5C;
    case 0x80070D60u: goto label_80070D60;
    case 0x80070D64u: goto label_80070D64;
    case 0x80070D68u: goto label_80070D68;
    case 0x80070D6Cu: goto label_80070D6C;
    case 0x80070D70u: goto label_80070D70;
    case 0x80070D74u: goto label_80070D74;
    case 0x80070D78u: goto label_80070D78;
    case 0x80070D7Cu: goto label_80070D7C;
    case 0x80070D80u: goto label_80070D80;
    case 0x80070D84u: goto label_80070D84;
    case 0x80070D88u: goto label_80070D88;
    case 0x80070D8Cu: goto label_80070D8C;
    case 0x80070D90u: goto label_80070D90;
    case 0x80070D94u: goto label_80070D94;
    case 0x80070D98u: goto label_80070D98;
    case 0x80070D9Cu: goto label_80070D9C;
    case 0x80070DA0u: goto label_80070DA0;
    case 0x80070DA4u: goto label_80070DA4;
    case 0x80070DA8u: goto label_80070DA8;
    case 0x80070DACu: goto label_80070DAC;
    case 0x80070DB0u: goto label_80070DB0;
    case 0x80070DB4u: goto label_80070DB4;
    case 0x80070DB8u: goto label_80070DB8;
    case 0x80070DBCu: goto label_80070DBC;
    case 0x80070DC0u: goto label_80070DC0;
    case 0x80070DC4u: goto label_80070DC4;
    case 0x80070DC8u: goto label_80070DC8;
    case 0x80070DCCu: goto label_80070DCC;
    case 0x80070DD0u: goto label_80070DD0;
    case 0x80070DD4u: goto label_80070DD4;
    case 0x80070DD8u: goto label_80070DD8;
    case 0x80070DDCu: goto label_80070DDC;
    case 0x80070DE0u: goto label_80070DE0;
    case 0x80070DE4u: goto label_80070DE4;
    case 0x80070DE8u: goto label_80070DE8;
    case 0x80070DECu: goto label_80070DEC;
    case 0x80070DF0u: goto label_80070DF0;
    case 0x80070DF4u: goto label_80070DF4;
    case 0x80070DF8u: goto label_80070DF8;
    case 0x80070DFCu: goto label_80070DFC;
    case 0x80070E00u: goto label_80070E00;
    case 0x80070E04u: goto label_80070E04;
    case 0x80070E08u: goto label_80070E08;
    case 0x80070E0Cu: goto label_80070E0C;
    case 0x80070E10u: goto label_80070E10;
    case 0x80070E14u: goto label_80070E14;
    case 0x80070E18u: goto label_80070E18;
    case 0x80070E1Cu: goto label_80070E1C;
    case 0x80070E20u: goto label_80070E20;
    case 0x80070E24u: goto label_80070E24;
    case 0x80070E28u: goto label_80070E28;
    case 0x80070E2Cu: goto label_80070E2C;
    case 0x80070E30u: goto label_80070E30;
    case 0x80070E34u: goto label_80070E34;
    case 0x80070E38u: goto label_80070E38;
    case 0x80070E3Cu: goto label_80070E3C;
    case 0x80070E40u: goto label_80070E40;
    case 0x80070E44u: goto label_80070E44;
    case 0x80070E48u: goto label_80070E48;
    case 0x80070E4Cu: goto label_80070E4C;
    case 0x80070E50u: goto label_80070E50;
    case 0x80070E54u: goto label_80070E54;
    case 0x80070E58u: goto label_80070E58;
    case 0x80070E5Cu: goto label_80070E5C;
    case 0x80070E60u: goto label_80070E60;
    case 0x80070E64u: goto label_80070E64;
    case 0x80070E68u: goto label_80070E68;
    case 0x80070E6Cu: goto label_80070E6C;
    case 0x80070E70u: goto label_80070E70;
    case 0x80070E74u: goto label_80070E74;
    case 0x80070E78u: goto label_80070E78;
    case 0x80070E7Cu: goto label_80070E7C;
    case 0x80070E80u: goto label_80070E80;
    case 0x80070E84u: goto label_80070E84;
    case 0x80070E88u: goto label_80070E88;
    case 0x80070E8Cu: goto label_80070E8C;
    case 0x80070E90u: goto label_80070E90;
    case 0x80070E94u: goto label_80070E94;
    case 0x80070E98u: goto label_80070E98;
    case 0x80070E9Cu: goto label_80070E9C;
    case 0x80070EA0u: goto label_80070EA0;
    case 0x80070EA4u: goto label_80070EA4;
    case 0x80070EA8u: goto label_80070EA8;
    case 0x80070EACu: goto label_80070EAC;
    case 0x80070EB0u: goto label_80070EB0;
    case 0x80070EB4u: goto label_80070EB4;
    case 0x80070EB8u: goto label_80070EB8;
    case 0x80070EBCu: goto label_80070EBC;
    case 0x80070EC0u: goto label_80070EC0;
    case 0x80070EC4u: goto label_80070EC4;
    case 0x80070EC8u: goto label_80070EC8;
    case 0x80070ECCu: goto label_80070ECC;
    case 0x80070ED0u: goto label_80070ED0;
    case 0x80070ED4u: goto label_80070ED4;
    case 0x80070ED8u: goto label_80070ED8;
    case 0x80070EDCu: goto label_80070EDC;
    case 0x80070EE0u: goto label_80070EE0;
    case 0x80070EE4u: goto label_80070EE4;
    case 0x80070EE8u: goto label_80070EE8;
    case 0x80070EECu: goto label_80070EEC;
    case 0x80070EF0u: goto label_80070EF0;
    case 0x80070EF4u: goto label_80070EF4;
    case 0x80070EF8u: goto label_80070EF8;
    case 0x80070EFCu: goto label_80070EFC;
    case 0x80070F00u: goto label_80070F00;
    case 0x80070F04u: goto label_80070F04;
    case 0x80070F08u: goto label_80070F08;
    case 0x80070F0Cu: goto label_80070F0C;
    case 0x80070F10u: goto label_80070F10;
    case 0x80070F14u: goto label_80070F14;
    case 0x80070F18u: goto label_80070F18;
    case 0x80070F1Cu: goto label_80070F1C;
    case 0x80070F20u: goto label_80070F20;
    case 0x80070F24u: goto label_80070F24;
    case 0x80070F28u: goto label_80070F28;
    case 0x80070F2Cu: goto label_80070F2C;
    case 0x80070F30u: goto label_80070F30;
    case 0x80070F34u: goto label_80070F34;
    case 0x80070F38u: goto label_80070F38;
    case 0x80070F3Cu: goto label_80070F3C;
    case 0x80070F40u: goto label_80070F40;
    case 0x80070F44u: goto label_80070F44;
    case 0x80070F48u: goto label_80070F48;
    case 0x80070F4Cu: goto label_80070F4C;
    case 0x80070F50u: goto label_80070F50;
    case 0x80070F54u: goto label_80070F54;
    case 0x80070F58u: goto label_80070F58;
    case 0x80070F5Cu: goto label_80070F5C;
    case 0x80070F60u: goto label_80070F60;
    case 0x80070F64u: goto label_80070F64;
    case 0x80070F68u: goto label_80070F68;
    case 0x80070F6Cu: goto label_80070F6C;
    case 0x80070F70u: goto label_80070F70;
    case 0x80070F74u: goto label_80070F74;
    case 0x80070F78u: goto label_80070F78;
    case 0x80070F7Cu: goto label_80070F7C;
    case 0x80070F80u: goto label_80070F80;
    case 0x80070F84u: goto label_80070F84;
    case 0x80070F88u: goto label_80070F88;
    case 0x80070F8Cu: goto label_80070F8C;
    case 0x80070F90u: goto label_80070F90;
    case 0x80070F94u: goto label_80070F94;
    case 0x80070F98u: goto label_80070F98;
    case 0x80070F9Cu: goto label_80070F9C;
    case 0x80070FA0u: goto label_80070FA0;
    case 0x80070FA4u: goto label_80070FA4;
    case 0x80070FA8u: goto label_80070FA8;
    case 0x80070FACu: goto label_80070FAC;
    case 0x80070FB0u: goto label_80070FB0;
    case 0x80070FB4u: goto label_80070FB4;
    case 0x80070FB8u: goto label_80070FB8;
    case 0x80070FBCu: goto label_80070FBC;
    case 0x80070FC0u: goto label_80070FC0;
    case 0x80070FC4u: goto label_80070FC4;
    case 0x80070FC8u: goto label_80070FC8;
    case 0x80070FCCu: goto label_80070FCC;
    case 0x80070FD0u: goto label_80070FD0;
    case 0x80070FD4u: goto label_80070FD4;
    case 0x80070FD8u: goto label_80070FD8;
    case 0x80070FDCu: goto label_80070FDC;
    case 0x80070FE0u: goto label_80070FE0;
    case 0x80070FE4u: goto label_80070FE4;
    case 0x80070FE8u: goto label_80070FE8;
    case 0x80070FECu: goto label_80070FEC;
    case 0x80070FF0u: goto label_80070FF0;
    case 0x80070FF4u: goto label_80070FF4;
    case 0x80070FF8u: goto label_80070FF8;
    case 0x80070FFCu: goto label_80070FFC;
    case 0x80071000u: goto label_80071000;
    case 0x80071004u: goto label_80071004;
    case 0x80071008u: goto label_80071008;
    case 0x8007100Cu: goto label_8007100C;
    case 0x80071010u: goto label_80071010;
    case 0x80071014u: goto label_80071014;
    case 0x80071018u: goto label_80071018;
    case 0x8007101Cu: goto label_8007101C;
    case 0x80071020u: goto label_80071020;
    case 0x80071024u: goto label_80071024;
    case 0x80071028u: goto label_80071028;
    case 0x8007102Cu: goto label_8007102C;
    case 0x80071030u: goto label_80071030;
    case 0x80071034u: goto label_80071034;
    case 0x80071038u: goto label_80071038;
    case 0x8007103Cu: goto label_8007103C;
    case 0x80071040u: goto label_80071040;
    case 0x80071044u: goto label_80071044;
    case 0x80071048u: goto label_80071048;
    case 0x8007104Cu: goto label_8007104C;
    case 0x80071050u: goto label_80071050;
    case 0x80071054u: goto label_80071054;
    case 0x80071058u: goto label_80071058;
    case 0x8007105Cu: goto label_8007105C;
    case 0x80071060u: goto label_80071060;
    case 0x80071064u: goto label_80071064;
    case 0x80071068u: goto label_80071068;
    case 0x8007106Cu: goto label_8007106C;
    case 0x80071070u: goto label_80071070;
    case 0x80071074u: goto label_80071074;
    case 0x80071078u: goto label_80071078;
    case 0x8007107Cu: goto label_8007107C;
    case 0x80071080u: goto label_80071080;
    case 0x80071084u: goto label_80071084;
    case 0x80071088u: goto label_80071088;
    case 0x8007108Cu: goto label_8007108C;
    case 0x80071090u: goto label_80071090;
    case 0x80071094u: goto label_80071094;
    case 0x80071098u: goto label_80071098;
    case 0x8007109Cu: goto label_8007109C;
    case 0x800710A0u: goto label_800710A0;
    case 0x800710A4u: goto label_800710A4;
    case 0x800710A8u: goto label_800710A8;
    case 0x800710ACu: goto label_800710AC;
    case 0x800710B0u: goto label_800710B0;
    case 0x800710B4u: goto label_800710B4;
    case 0x800710B8u: goto label_800710B8;
    case 0x800710BCu: goto label_800710BC;
    case 0x800710C0u: goto label_800710C0;
    case 0x800710C4u: goto label_800710C4;
    case 0x800710C8u: goto label_800710C8;
    case 0x800710CCu: goto label_800710CC;
    case 0x800710D0u: goto label_800710D0;
    case 0x800710D4u: goto label_800710D4;
    case 0x800710D8u: goto label_800710D8;
    case 0x800710DCu: goto label_800710DC;
    case 0x800710E0u: goto label_800710E0;
    case 0x800710E4u: goto label_800710E4;
    case 0x800710E8u: goto label_800710E8;
    case 0x800710ECu: goto label_800710EC;
    case 0x800710F0u: goto label_800710F0;
    case 0x800710F4u: goto label_800710F4;
    case 0x800710F8u: goto label_800710F8;
    case 0x800710FCu: goto label_800710FC;
    case 0x80071100u: goto label_80071100;
    case 0x80071104u: goto label_80071104;
    case 0x80071108u: goto label_80071108;
    case 0x8007110Cu: goto label_8007110C;
    case 0x80071110u: goto label_80071110;
    case 0x80071114u: goto label_80071114;
    case 0x80071118u: goto label_80071118;
    case 0x8007111Cu: goto label_8007111C;
    case 0x80071120u: goto label_80071120;
    case 0x80071124u: goto label_80071124;
    case 0x80071128u: goto label_80071128;
    case 0x8007112Cu: goto label_8007112C;
    case 0x80071130u: goto label_80071130;
    case 0x80071134u: goto label_80071134;
    case 0x80071138u: goto label_80071138;
    case 0x8007113Cu: goto label_8007113C;
    case 0x80071140u: goto label_80071140;
    case 0x80071144u: goto label_80071144;
    case 0x80071148u: goto label_80071148;
    case 0x8007114Cu: goto label_8007114C;
    case 0x80071150u: goto label_80071150;
    case 0x80071154u: goto label_80071154;
    case 0x80071158u: goto label_80071158;
    case 0x8007115Cu: goto label_8007115C;
    case 0x80071160u: goto label_80071160;
    case 0x80071164u: goto label_80071164;
    case 0x80071168u: goto label_80071168;
    case 0x8007116Cu: goto label_8007116C;
    case 0x80071170u: goto label_80071170;
    case 0x80071174u: goto label_80071174;
    case 0x80071178u: goto label_80071178;
    case 0x8007117Cu: goto label_8007117C;
    case 0x80071180u: goto label_80071180;
    case 0x80071184u: goto label_80071184;
    case 0x80071188u: goto label_80071188;
    case 0x8007118Cu: goto label_8007118C;
    case 0x80071190u: goto label_80071190;
    case 0x80071194u: goto label_80071194;
    case 0x80071198u: goto label_80071198;
    case 0x8007119Cu: goto label_8007119C;
    case 0x800711A0u: goto label_800711A0;
    case 0x800711A4u: goto label_800711A4;
    case 0x800711A8u: goto label_800711A8;
    case 0x800711ACu: goto label_800711AC;
    case 0x800711B0u: goto label_800711B0;
    case 0x800711B4u: goto label_800711B4;
    case 0x800711B8u: goto label_800711B8;
    case 0x800711BCu: goto label_800711BC;
    case 0x800711C0u: goto label_800711C0;
    case 0x800711C4u: goto label_800711C4;
    case 0x800711C8u: goto label_800711C8;
    case 0x800711CCu: goto label_800711CC;
    case 0x800711D0u: goto label_800711D0;
    case 0x800711D4u: goto label_800711D4;
    case 0x800711D8u: goto label_800711D8;
    case 0x800711DCu: goto label_800711DC;
    case 0x800711E0u: goto label_800711E0;
    case 0x800711E4u: goto label_800711E4;
    case 0x800711E8u: goto label_800711E8;
    case 0x800711ECu: goto label_800711EC;
    case 0x800711F0u: goto label_800711F0;
    case 0x800711F4u: goto label_800711F4;
    case 0x800711F8u: goto label_800711F8;
    case 0x800711FCu: goto label_800711FC;
    case 0x80071200u: goto label_80071200;
    case 0x80071204u: goto label_80071204;
    case 0x80071208u: goto label_80071208;
    case 0x8007120Cu: goto label_8007120C;
    case 0x80071210u: goto label_80071210;
    case 0x80071214u: goto label_80071214;
    case 0x80071218u: goto label_80071218;
    case 0x8007121Cu: goto label_8007121C;
    case 0x80071220u: goto label_80071220;
    case 0x80071224u: goto label_80071224;
    case 0x80071228u: goto label_80071228;
    case 0x8007122Cu: goto label_8007122C;
    case 0x80071230u: goto label_80071230;
    case 0x80071234u: goto label_80071234;
    case 0x80071238u: goto label_80071238;
    case 0x8007123Cu: goto label_8007123C;
    case 0x80071240u: goto label_80071240;
    case 0x80071244u: goto label_80071244;
    case 0x80071248u: goto label_80071248;
    case 0x8007124Cu: goto label_8007124C;
    case 0x80071250u: goto label_80071250;
    case 0x80071254u: goto label_80071254;
    case 0x80071258u: goto label_80071258;
    case 0x8007125Cu: goto label_8007125C;
    case 0x80071260u: goto label_80071260;
    case 0x80071264u: goto label_80071264;
    case 0x80071268u: goto label_80071268;
    case 0x8007126Cu: goto label_8007126C;
    case 0x80071270u: goto label_80071270;
    case 0x80071274u: goto label_80071274;
    case 0x80071278u: goto label_80071278;
    case 0x8007127Cu: goto label_8007127C;
    case 0x80071280u: goto label_80071280;
    case 0x80071284u: goto label_80071284;
    case 0x80071288u: goto label_80071288;
    case 0x8007128Cu: goto label_8007128C;
    case 0x80071290u: goto label_80071290;
    case 0x80071294u: goto label_80071294;
    case 0x80071298u: goto label_80071298;
    case 0x8007129Cu: goto label_8007129C;
    case 0x800712A0u: goto label_800712A0;
    case 0x800712A4u: goto label_800712A4;
    case 0x800712A8u: goto label_800712A8;
    case 0x800712ACu: goto label_800712AC;
    case 0x800712B0u: goto label_800712B0;
    case 0x800712B4u: goto label_800712B4;
    case 0x800712B8u: goto label_800712B8;
    case 0x800712BCu: goto label_800712BC;
    case 0x800712C0u: goto label_800712C0;
    case 0x800712C4u: goto label_800712C4;
    case 0x800712C8u: goto label_800712C8;
    case 0x800712CCu: goto label_800712CC;
    case 0x800712D0u: goto label_800712D0;
    case 0x800712D4u: goto label_800712D4;
    case 0x800712D8u: goto label_800712D8;
    case 0x800712DCu: goto label_800712DC;
    case 0x800712E0u: goto label_800712E0;
    case 0x800712E4u: goto label_800712E4;
    case 0x800712E8u: goto label_800712E8;
    case 0x800712ECu: goto label_800712EC;
    case 0x800712F0u: goto label_800712F0;
    case 0x800712F4u: goto label_800712F4;
    case 0x800712F8u: goto label_800712F8;
    case 0x800712FCu: goto label_800712FC;
    case 0x80071300u: goto label_80071300;
    case 0x80071304u: goto label_80071304;
    case 0x80071308u: goto label_80071308;
    case 0x8007130Cu: goto label_8007130C;
    case 0x80071310u: goto label_80071310;
    case 0x80071314u: goto label_80071314;
    case 0x80071318u: goto label_80071318;
    case 0x8007131Cu: goto label_8007131C;
    case 0x80071320u: goto label_80071320;
    case 0x80071324u: goto label_80071324;
    case 0x80071328u: goto label_80071328;
    case 0x8007132Cu: goto label_8007132C;
    case 0x80071330u: goto label_80071330;
    case 0x80071334u: goto label_80071334;
    case 0x80071338u: goto label_80071338;
    case 0x8007133Cu: goto label_8007133C;
    case 0x80071340u: goto label_80071340;
    case 0x80071344u: goto label_80071344;
    case 0x80071348u: goto label_80071348;
    case 0x8007134Cu: goto label_8007134C;
    case 0x80071350u: goto label_80071350;
    case 0x80071354u: goto label_80071354;
    case 0x80071358u: goto label_80071358;
    case 0x8007135Cu: goto label_8007135C;
    case 0x80071360u: goto label_80071360;
    case 0x80071364u: goto label_80071364;
    case 0x80071368u: goto label_80071368;
    case 0x8007136Cu: goto label_8007136C;
    case 0x80071370u: goto label_80071370;
    case 0x80071374u: goto label_80071374;
    case 0x80071378u: goto label_80071378;
    case 0x8007137Cu: goto label_8007137C;
    case 0x80071380u: goto label_80071380;
    case 0x80071384u: goto label_80071384;
    case 0x80071388u: goto label_80071388;
    case 0x8007138Cu: goto label_8007138C;
    case 0x80071390u: goto label_80071390;
    case 0x80071394u: goto label_80071394;
    case 0x80071398u: goto label_80071398;
    case 0x8007139Cu: goto label_8007139C;
    case 0x800713A0u: goto label_800713A0;
    case 0x800713A4u: goto label_800713A4;
    case 0x800713A8u: goto label_800713A8;
    case 0x800713ACu: goto label_800713AC;
    case 0x800713B0u: goto label_800713B0;
    case 0x800713B4u: goto label_800713B4;
    case 0x800713B8u: goto label_800713B8;
    case 0x800713BCu: goto label_800713BC;
    case 0x800713C0u: goto label_800713C0;
    case 0x800713C4u: goto label_800713C4;
    case 0x800713C8u: goto label_800713C8;
    case 0x800713CCu: goto label_800713CC;
    case 0x800713D0u: goto label_800713D0;
    case 0x800713D4u: goto label_800713D4;
    case 0x800713D8u: goto label_800713D8;
    case 0x800713DCu: goto label_800713DC;
    case 0x800713E0u: goto label_800713E0;
    case 0x800713E4u: goto label_800713E4;
    case 0x800713E8u: goto label_800713E8;
    case 0x800713ECu: goto label_800713EC;
    case 0x800713F0u: goto label_800713F0;
    case 0x800713F4u: goto label_800713F4;
    case 0x800713F8u: goto label_800713F8;
    case 0x800713FCu: goto label_800713FC;
    case 0x80071400u: goto label_80071400;
    case 0x80071404u: goto label_80071404;
    case 0x80071408u: goto label_80071408;
    case 0x8007140Cu: goto label_8007140C;
    case 0x80071410u: goto label_80071410;
    case 0x80071414u: goto label_80071414;
    case 0x80071418u: goto label_80071418;
    case 0x8007141Cu: goto label_8007141C;
    case 0x80071420u: goto label_80071420;
    case 0x80071424u: goto label_80071424;
    case 0x80071428u: goto label_80071428;
    case 0x8007142Cu: goto label_8007142C;
    case 0x80071430u: goto label_80071430;
    case 0x80071434u: goto label_80071434;
    case 0x80071438u: goto label_80071438;
    case 0x8007143Cu: goto label_8007143C;
    case 0x80071440u: goto label_80071440;
    case 0x80071444u: goto label_80071444;
    case 0x80071448u: goto label_80071448;
    case 0x8007144Cu: goto label_8007144C;
    case 0x80071450u: goto label_80071450;
    case 0x80071454u: goto label_80071454;
    case 0x80071458u: goto label_80071458;
    case 0x8007145Cu: goto label_8007145C;
    case 0x80071460u: goto label_80071460;
    case 0x80071464u: goto label_80071464;
    case 0x80071468u: goto label_80071468;
    case 0x8007146Cu: goto label_8007146C;
    case 0x80071470u: goto label_80071470;
    case 0x80071474u: goto label_80071474;
    case 0x80071478u: goto label_80071478;
    case 0x8007147Cu: goto label_8007147C;
    case 0x80071480u: goto label_80071480;
    case 0x80071484u: goto label_80071484;
    case 0x80071488u: goto label_80071488;
    case 0x8007148Cu: goto label_8007148C;
    case 0x80071490u: goto label_80071490;
    case 0x80071494u: goto label_80071494;
    case 0x80071498u: goto label_80071498;
    case 0x8007149Cu: goto label_8007149C;
    case 0x800714A0u: goto label_800714A0;
    case 0x800714A4u: goto label_800714A4;
    case 0x800714A8u: goto label_800714A8;
    case 0x800714ACu: goto label_800714AC;
    case 0x800714B0u: goto label_800714B0;
    case 0x800714B4u: goto label_800714B4;
    case 0x800714B8u: goto label_800714B8;
    case 0x800714BCu: goto label_800714BC;
    case 0x800714C0u: goto label_800714C0;
    case 0x800714C4u: goto label_800714C4;
    case 0x800714C8u: goto label_800714C8;
    case 0x800714CCu: goto label_800714CC;
    case 0x800714D0u: goto label_800714D0;
    case 0x800714D4u: goto label_800714D4;
    case 0x800714D8u: goto label_800714D8;
    case 0x800714DCu: goto label_800714DC;
    case 0x800714E0u: goto label_800714E0;
    case 0x800714E4u: goto label_800714E4;
    case 0x800714E8u: goto label_800714E8;
    case 0x800714ECu: goto label_800714EC;
    case 0x800714F0u: goto label_800714F0;
    case 0x800714F4u: goto label_800714F4;
    case 0x800714F8u: goto label_800714F8;
    case 0x800714FCu: goto label_800714FC;
    case 0x80071500u: goto label_80071500;
    case 0x80071504u: goto label_80071504;
    case 0x80071508u: goto label_80071508;
    case 0x8007150Cu: goto label_8007150C;
    case 0x80071510u: goto label_80071510;
    case 0x80071514u: goto label_80071514;
    case 0x80071518u: goto label_80071518;
    case 0x8007151Cu: goto label_8007151C;
    case 0x80071520u: goto label_80071520;
    case 0x80071524u: goto label_80071524;
    case 0x80071528u: goto label_80071528;
    case 0x8007152Cu: goto label_8007152C;
    case 0x80071530u: goto label_80071530;
    case 0x80071534u: goto label_80071534;
    case 0x80071538u: goto label_80071538;
    case 0x8007153Cu: goto label_8007153C;
    case 0x80071540u: goto label_80071540;
    case 0x80071544u: goto label_80071544;
    case 0x80071548u: goto label_80071548;
    case 0x8007154Cu: goto label_8007154C;
    case 0x80071550u: goto label_80071550;
    case 0x80071554u: goto label_80071554;
    case 0x80071558u: goto label_80071558;
    case 0x8007155Cu: goto label_8007155C;
    case 0x80071560u: goto label_80071560;
    case 0x80071564u: goto label_80071564;
    case 0x80071568u: goto label_80071568;
    case 0x8007156Cu: goto label_8007156C;
    case 0x80071570u: goto label_80071570;
    case 0x80071574u: goto label_80071574;
    case 0x80071578u: goto label_80071578;
    case 0x8007157Cu: goto label_8007157C;
    case 0x80071580u: goto label_80071580;
    case 0x80071584u: goto label_80071584;
    case 0x80071588u: goto label_80071588;
    case 0x8007158Cu: goto label_8007158C;
    case 0x80071590u: goto label_80071590;
    case 0x80071594u: goto label_80071594;
    case 0x80071598u: goto label_80071598;
    case 0x8007159Cu: goto label_8007159C;
    case 0x800715A0u: goto label_800715A0;
    case 0x800715A4u: goto label_800715A4;
    case 0x800715A8u: goto label_800715A8;
    case 0x800715ACu: goto label_800715AC;
    case 0x800715B0u: goto label_800715B0;
    case 0x800715B4u: goto label_800715B4;
    case 0x800715B8u: goto label_800715B8;
    case 0x800715BCu: goto label_800715BC;
    case 0x800715C0u: goto label_800715C0;
    case 0x800715C4u: goto label_800715C4;
    case 0x800715C8u: goto label_800715C8;
    case 0x800715CCu: goto label_800715CC;
    case 0x800715D0u: goto label_800715D0;
    case 0x800715D4u: goto label_800715D4;
    case 0x800715D8u: goto label_800715D8;
    case 0x800715DCu: goto label_800715DC;
    case 0x800715E0u: goto label_800715E0;
    case 0x800715E4u: goto label_800715E4;
    case 0x800715E8u: goto label_800715E8;
    case 0x800715ECu: goto label_800715EC;
    case 0x800715F0u: goto label_800715F0;
    case 0x800715F4u: goto label_800715F4;
    case 0x800715F8u: goto label_800715F8;
    case 0x800715FCu: goto label_800715FC;
    case 0x80071600u: goto label_80071600;
    case 0x80071604u: goto label_80071604;
    case 0x80071608u: goto label_80071608;
    case 0x8007160Cu: goto label_8007160C;
    case 0x80071610u: goto label_80071610;
    case 0x80071614u: goto label_80071614;
    case 0x80071618u: goto label_80071618;
    case 0x8007161Cu: goto label_8007161C;
    case 0x80071620u: goto label_80071620;
    case 0x80071624u: goto label_80071624;
    case 0x80071628u: goto label_80071628;
    case 0x8007162Cu: goto label_8007162C;
    case 0x80071630u: goto label_80071630;
    case 0x80071634u: goto label_80071634;
    case 0x80071638u: goto label_80071638;
    case 0x8007163Cu: goto label_8007163C;
    case 0x80071640u: goto label_80071640;
    case 0x80071644u: goto label_80071644;
    case 0x80071648u: goto label_80071648;
    case 0x8007164Cu: goto label_8007164C;
    case 0x80071650u: goto label_80071650;
    case 0x80071654u: goto label_80071654;
    case 0x80071658u: goto label_80071658;
    case 0x8007165Cu: goto label_8007165C;
    case 0x80071660u: goto label_80071660;
    case 0x80071664u: goto label_80071664;
    case 0x80071668u: goto label_80071668;
    case 0x8007166Cu: goto label_8007166C;
    case 0x80071670u: goto label_80071670;
    case 0x80071674u: goto label_80071674;
    case 0x80071678u: goto label_80071678;
    case 0x8007167Cu: goto label_8007167C;
    case 0x80071680u: goto label_80071680;
    case 0x80071684u: goto label_80071684;
    case 0x80071688u: goto label_80071688;
    case 0x8007168Cu: goto label_8007168C;
    case 0x80071690u: goto label_80071690;
    case 0x80071694u: goto label_80071694;
    case 0x80071698u: goto label_80071698;
    case 0x8007169Cu: goto label_8007169C;
    case 0x800716A0u: goto label_800716A0;
    case 0x800716A4u: goto label_800716A4;
    case 0x800716A8u: goto label_800716A8;
    case 0x800716ACu: goto label_800716AC;
    case 0x800716B0u: goto label_800716B0;
    case 0x800716B4u: goto label_800716B4;
    case 0x800716B8u: goto label_800716B8;
    case 0x800716BCu: goto label_800716BC;
    case 0x800716C0u: goto label_800716C0;
    case 0x800716C4u: goto label_800716C4;
    case 0x800716C8u: goto label_800716C8;
    case 0x800716CCu: goto label_800716CC;
    case 0x800716D0u: goto label_800716D0;
    case 0x800716D4u: goto label_800716D4;
    case 0x800716D8u: goto label_800716D8;
    case 0x800716DCu: goto label_800716DC;
    case 0x800716E0u: goto label_800716E0;
    case 0x800716E4u: goto label_800716E4;
    case 0x800716E8u: goto label_800716E8;
    case 0x800716ECu: goto label_800716EC;
    case 0x800716F0u: goto label_800716F0;
    case 0x800716F4u: goto label_800716F4;
    case 0x800716F8u: goto label_800716F8;
    case 0x800716FCu: goto label_800716FC;
    case 0x80071700u: goto label_80071700;
    case 0x80071704u: goto label_80071704;
    case 0x80071708u: goto label_80071708;
    case 0x8007170Cu: goto label_8007170C;
    case 0x80071710u: goto label_80071710;
    case 0x80071714u: goto label_80071714;
    case 0x80071718u: goto label_80071718;
    case 0x8007171Cu: goto label_8007171C;
    case 0x80071720u: goto label_80071720;
    case 0x80071724u: goto label_80071724;
    case 0x80071728u: goto label_80071728;
    case 0x8007172Cu: goto label_8007172C;
    case 0x80071730u: goto label_80071730;
    case 0x80071734u: goto label_80071734;
    case 0x80071738u: goto label_80071738;
    case 0x8007173Cu: goto label_8007173C;
    case 0x80071740u: goto label_80071740;
    case 0x80071744u: goto label_80071744;
    case 0x80071748u: goto label_80071748;
    case 0x8007174Cu: goto label_8007174C;
    case 0x80071750u: goto label_80071750;
    case 0x80071754u: goto label_80071754;
    case 0x80071758u: goto label_80071758;
    case 0x8007175Cu: goto label_8007175C;
    case 0x80071760u: goto label_80071760;
    case 0x80071764u: goto label_80071764;
    case 0x80071768u: goto label_80071768;
    case 0x8007176Cu: goto label_8007176C;
    case 0x80071770u: goto label_80071770;
    case 0x80071774u: goto label_80071774;
    case 0x80071778u: goto label_80071778;
    case 0x8007177Cu: goto label_8007177C;
    case 0x80071780u: goto label_80071780;
    case 0x80071784u: goto label_80071784;
    case 0x80071788u: goto label_80071788;
    case 0x8007178Cu: goto label_8007178C;
    case 0x80071790u: goto label_80071790;
    case 0x80071794u: goto label_80071794;
    case 0x80071798u: goto label_80071798;
    case 0x8007179Cu: goto label_8007179C;
    case 0x800717A0u: goto label_800717A0;
    case 0x800717A4u: goto label_800717A4;
    case 0x800717A8u: goto label_800717A8;
    case 0x800717ACu: goto label_800717AC;
    case 0x800717B0u: goto label_800717B0;
    case 0x800717B4u: goto label_800717B4;
    case 0x800717B8u: goto label_800717B8;
    case 0x800717BCu: goto label_800717BC;
    case 0x800717C0u: goto label_800717C0;
    case 0x800717C4u: goto label_800717C4;
    case 0x800717C8u: goto label_800717C8;
    case 0x800717CCu: goto label_800717CC;
    case 0x800717D0u: goto label_800717D0;
    case 0x800717D4u: goto label_800717D4;
    case 0x800717D8u: goto label_800717D8;
    case 0x800717DCu: goto label_800717DC;
    case 0x800717E0u: goto label_800717E0;
    case 0x800717E4u: goto label_800717E4;
    case 0x800717E8u: goto label_800717E8;
    case 0x800717ECu: goto label_800717EC;
    case 0x800717F0u: goto label_800717F0;
    case 0x800717F4u: goto label_800717F4;
    case 0x800717F8u: goto label_800717F8;
    case 0x800717FCu: goto label_800717FC;
    case 0x80071800u: goto label_80071800;
    case 0x80071804u: goto label_80071804;
    case 0x80071808u: goto label_80071808;
    case 0x8007180Cu: goto label_8007180C;
    case 0x80071810u: goto label_80071810;
    case 0x80071814u: goto label_80071814;
    case 0x80071818u: goto label_80071818;
    case 0x8007181Cu: goto label_8007181C;
    case 0x80071820u: goto label_80071820;
    case 0x80071824u: goto label_80071824;
    case 0x80071828u: goto label_80071828;
    case 0x8007182Cu: goto label_8007182C;
    case 0x80071830u: goto label_80071830;
    case 0x80071834u: goto label_80071834;
    case 0x80071838u: goto label_80071838;
    case 0x8007183Cu: goto label_8007183C;
    case 0x80071840u: goto label_80071840;
    case 0x80071844u: goto label_80071844;
    case 0x80071848u: goto label_80071848;
    case 0x8007184Cu: goto label_8007184C;
    case 0x80071850u: goto label_80071850;
    case 0x80071854u: goto label_80071854;
    case 0x80071858u: goto label_80071858;
    case 0x8007185Cu: goto label_8007185C;
    case 0x80071860u: goto label_80071860;
    case 0x80071864u: goto label_80071864;
    case 0x80071868u: goto label_80071868;
    case 0x8007186Cu: goto label_8007186C;
    case 0x80071870u: goto label_80071870;
    case 0x80071874u: goto label_80071874;
    case 0x80071878u: goto label_80071878;
    case 0x8007187Cu: goto label_8007187C;
    case 0x80071880u: goto label_80071880;
    case 0x80071884u: goto label_80071884;
    case 0x80071888u: goto label_80071888;
    case 0x8007188Cu: goto label_8007188C;
    case 0x80071890u: goto label_80071890;
    case 0x80071894u: goto label_80071894;
    case 0x80071898u: goto label_80071898;
    case 0x8007189Cu: goto label_8007189C;
    case 0x800718A0u: goto label_800718A0;
    case 0x800718A4u: goto label_800718A4;
    case 0x800718A8u: goto label_800718A8;
    case 0x800718ACu: goto label_800718AC;
    case 0x800718B0u: goto label_800718B0;
    case 0x800718B4u: goto label_800718B4;
    case 0x800718B8u: goto label_800718B8;
    case 0x800718BCu: goto label_800718BC;
    case 0x800718C0u: goto label_800718C0;
    case 0x800718C4u: goto label_800718C4;
    case 0x800718C8u: goto label_800718C8;
    case 0x800718CCu: goto label_800718CC;
    case 0x800718D0u: goto label_800718D0;
    case 0x800718D4u: goto label_800718D4;
    case 0x800718D8u: goto label_800718D8;
    case 0x800718DCu: goto label_800718DC;
    case 0x800718E0u: goto label_800718E0;
    case 0x800718E4u: goto label_800718E4;
    case 0x800718E8u: goto label_800718E8;
    case 0x800718ECu: goto label_800718EC;
    case 0x800718F0u: goto label_800718F0;
    case 0x800718F4u: goto label_800718F4;
    case 0x800718F8u: goto label_800718F8;
    case 0x800718FCu: goto label_800718FC;
    case 0x80071900u: goto label_80071900;
    case 0x80071904u: goto label_80071904;
    case 0x80071908u: goto label_80071908;
    case 0x8007190Cu: goto label_8007190C;
    case 0x80071910u: goto label_80071910;
    case 0x80071914u: goto label_80071914;
    case 0x80071918u: goto label_80071918;
    case 0x8007191Cu: goto label_8007191C;
    case 0x80071920u: goto label_80071920;
    case 0x80071924u: goto label_80071924;
    case 0x80071928u: goto label_80071928;
    case 0x8007192Cu: goto label_8007192C;
    case 0x80071930u: goto label_80071930;
    case 0x80071934u: goto label_80071934;
    case 0x80071938u: goto label_80071938;
    case 0x8007193Cu: goto label_8007193C;
    case 0x80071940u: goto label_80071940;
    case 0x80071944u: goto label_80071944;
    case 0x80071948u: goto label_80071948;
    case 0x8007194Cu: goto label_8007194C;
    case 0x80071950u: goto label_80071950;
    case 0x80071954u: goto label_80071954;
    case 0x80071958u: goto label_80071958;
    case 0x8007195Cu: goto label_8007195C;
    case 0x80071960u: goto label_80071960;
    case 0x80071964u: goto label_80071964;
    case 0x80071968u: goto label_80071968;
    case 0x8007196Cu: goto label_8007196C;
    case 0x80071970u: goto label_80071970;
    case 0x80071974u: goto label_80071974;
    case 0x80071978u: goto label_80071978;
    case 0x8007197Cu: goto label_8007197C;
    case 0x80071980u: goto label_80071980;
    case 0x80071984u: goto label_80071984;
    case 0x80071988u: goto label_80071988;
    case 0x8007198Cu: goto label_8007198C;
    case 0x80071990u: goto label_80071990;
    case 0x80071994u: goto label_80071994;
    case 0x80071998u: goto label_80071998;
    case 0x8007199Cu: goto label_8007199C;
    case 0x800719A0u: goto label_800719A0;
    case 0x800719A4u: goto label_800719A4;
    case 0x800719A8u: goto label_800719A8;
    case 0x800719ACu: goto label_800719AC;
    case 0x800719B0u: goto label_800719B0;
    case 0x800719B4u: goto label_800719B4;
    case 0x800719B8u: goto label_800719B8;
    case 0x800719BCu: goto label_800719BC;
    case 0x800719C0u: goto label_800719C0;
    case 0x800719C4u: goto label_800719C4;
    case 0x800719C8u: goto label_800719C8;
    case 0x800719CCu: goto label_800719CC;
    case 0x800719D0u: goto label_800719D0;
    case 0x800719D4u: goto label_800719D4;
    case 0x800719D8u: goto label_800719D8;
    case 0x800719DCu: goto label_800719DC;
    case 0x800719E0u: goto label_800719E0;
    case 0x800719E4u: goto label_800719E4;
    case 0x800719E8u: goto label_800719E8;
    case 0x800719ECu: goto label_800719EC;
    case 0x800719F0u: goto label_800719F0;
    case 0x800719F4u: goto label_800719F4;
    case 0x800719F8u: goto label_800719F8;
    case 0x800719FCu: goto label_800719FC;
    case 0x80071A00u: goto label_80071A00;
    case 0x80071A04u: goto label_80071A04;
    case 0x80071A08u: goto label_80071A08;
    case 0x80071A0Cu: goto label_80071A0C;
    case 0x80071A10u: goto label_80071A10;
    case 0x80071A14u: goto label_80071A14;
    case 0x80071A18u: goto label_80071A18;
    case 0x80071A1Cu: goto label_80071A1C;
    case 0x80071A20u: goto label_80071A20;
    case 0x80071A24u: goto label_80071A24;
    case 0x80071A28u: goto label_80071A28;
    case 0x80071A2Cu: goto label_80071A2C;
    case 0x80071A30u: goto label_80071A30;
    case 0x80071A34u: goto label_80071A34;
    case 0x80071A38u: goto label_80071A38;
    case 0x80071A3Cu: goto label_80071A3C;
    case 0x80071A40u: goto label_80071A40;
    case 0x80071A44u: goto label_80071A44;
    case 0x80071A48u: goto label_80071A48;
    case 0x80071A4Cu: goto label_80071A4C;
    case 0x80071A50u: goto label_80071A50;
    case 0x80071A54u: goto label_80071A54;
    case 0x80071A58u: goto label_80071A58;
    case 0x80071A5Cu: goto label_80071A5C;
    case 0x80071A60u: goto label_80071A60;
    case 0x80071A64u: goto label_80071A64;
    case 0x80071A68u: goto label_80071A68;
    case 0x80071A6Cu: goto label_80071A6C;
    case 0x80071A70u: goto label_80071A70;
    case 0x80071A74u: goto label_80071A74;
    case 0x80071A78u: goto label_80071A78;
    case 0x80071A7Cu: goto label_80071A7C;
    case 0x80071A80u: goto label_80071A80;
    case 0x80071A84u: goto label_80071A84;
    case 0x80071A88u: goto label_80071A88;
    case 0x80071A8Cu: goto label_80071A8C;
    case 0x80071A90u: goto label_80071A90;
    case 0x80071A94u: goto label_80071A94;
    case 0x80071A98u: goto label_80071A98;
    case 0x80071A9Cu: goto label_80071A9C;
    case 0x80071AA0u: goto label_80071AA0;
    case 0x80071AA4u: goto label_80071AA4;
    case 0x80071AA8u: goto label_80071AA8;
    case 0x80071AACu: goto label_80071AAC;
    case 0x80071AB0u: goto label_80071AB0;
    case 0x80071AB4u: goto label_80071AB4;
    case 0x80071AB8u: goto label_80071AB8;
    case 0x80071ABCu: goto label_80071ABC;
    case 0x80071AC0u: goto label_80071AC0;
    case 0x80071AC4u: goto label_80071AC4;
    case 0x80071AC8u: goto label_80071AC8;
    case 0x80071ACCu: goto label_80071ACC;
    case 0x80071AD0u: goto label_80071AD0;
    case 0x80071AD4u: goto label_80071AD4;
    case 0x80071AD8u: goto label_80071AD8;
    case 0x80071ADCu: goto label_80071ADC;
    case 0x80071AE0u: goto label_80071AE0;
    case 0x80071AE4u: goto label_80071AE4;
    case 0x80071AE8u: goto label_80071AE8;
    case 0x80071AECu: goto label_80071AEC;
    case 0x80071AF0u: goto label_80071AF0;
    case 0x80071AF4u: goto label_80071AF4;
    case 0x80071AF8u: goto label_80071AF8;
    case 0x80071AFCu: goto label_80071AFC;
    case 0x80071B00u: goto label_80071B00;
    case 0x80071B04u: goto label_80071B04;
    case 0x80071B08u: goto label_80071B08;
    case 0x80071B0Cu: goto label_80071B0C;
    case 0x80071B10u: goto label_80071B10;
    case 0x80071B14u: goto label_80071B14;
    case 0x80071B18u: goto label_80071B18;
    case 0x80071B1Cu: goto label_80071B1C;
    case 0x80071B20u: goto label_80071B20;
    case 0x80071B24u: goto label_80071B24;
    case 0x80071B28u: goto label_80071B28;
    case 0x80071B2Cu: goto label_80071B2C;
    case 0x80071B30u: goto label_80071B30;
    case 0x80071B34u: goto label_80071B34;
    case 0x80071B38u: goto label_80071B38;
    case 0x80071B3Cu: goto label_80071B3C;
    case 0x80071B40u: goto label_80071B40;
    case 0x80071B44u: goto label_80071B44;
    case 0x80071B48u: goto label_80071B48;
    case 0x80071B4Cu: goto label_80071B4C;
    case 0x80071B50u: goto label_80071B50;
    case 0x80071B54u: goto label_80071B54;
    case 0x80071B58u: goto label_80071B58;
    case 0x80071B5Cu: goto label_80071B5C;
    case 0x80071B60u: goto label_80071B60;
    case 0x80071B64u: goto label_80071B64;
    case 0x80071B68u: goto label_80071B68;
    case 0x80071B6Cu: goto label_80071B6C;
    case 0x80071B70u: goto label_80071B70;
    case 0x80071B74u: goto label_80071B74;
    case 0x80071B78u: goto label_80071B78;
    case 0x80071B7Cu: goto label_80071B7C;
    case 0x80071B80u: goto label_80071B80;
    case 0x80071B84u: goto label_80071B84;
    case 0x80071B88u: goto label_80071B88;
    case 0x80071B8Cu: goto label_80071B8C;
    case 0x80071B90u: goto label_80071B90;
    case 0x80071B94u: goto label_80071B94;
    case 0x80071B98u: goto label_80071B98;
    case 0x80071B9Cu: goto label_80071B9C;
    case 0x80071BA0u: goto label_80071BA0;
    case 0x80071BA4u: goto label_80071BA4;
    case 0x80071BA8u: goto label_80071BA8;
    case 0x80071BACu: goto label_80071BAC;
    case 0x80071BB0u: goto label_80071BB0;
    case 0x80071BB4u: goto label_80071BB4;
    case 0x80071BB8u: goto label_80071BB8;
    case 0x80071BBCu: goto label_80071BBC;
    case 0x80071BC0u: goto label_80071BC0;
    case 0x80071BC4u: goto label_80071BC4;
    case 0x80071BC8u: goto label_80071BC8;
    case 0x80071BCCu: goto label_80071BCC;
    case 0x80071BD0u: goto label_80071BD0;
    case 0x80071BD4u: goto label_80071BD4;
    case 0x80071BD8u: goto label_80071BD8;
    case 0x80071BDCu: goto label_80071BDC;
    case 0x80071BE0u: goto label_80071BE0;
    case 0x80071BE4u: goto label_80071BE4;
    case 0x80071BE8u: goto label_80071BE8;
    case 0x80071BECu: goto label_80071BEC;
    case 0x80071BF0u: goto label_80071BF0;
    case 0x80071BF4u: goto label_80071BF4;
    case 0x80071BF8u: goto label_80071BF8;
    case 0x80071BFCu: goto label_80071BFC;
    case 0x80071C00u: goto label_80071C00;
    case 0x80071C04u: goto label_80071C04;
    case 0x80071C08u: goto label_80071C08;
    case 0x80071C0Cu: goto label_80071C0C;
    case 0x80071C10u: goto label_80071C10;
    case 0x80071C14u: goto label_80071C14;
    case 0x80071C18u: goto label_80071C18;
    case 0x80071C1Cu: goto label_80071C1C;
    case 0x80071C20u: goto label_80071C20;
    case 0x80071C24u: goto label_80071C24;
    case 0x80071C28u: goto label_80071C28;
    case 0x80071C2Cu: goto label_80071C2C;
    case 0x80071C30u: goto label_80071C30;
    case 0x80071C34u: goto label_80071C34;
    case 0x80071C38u: goto label_80071C38;
    case 0x80071C3Cu: goto label_80071C3C;
    case 0x80071C40u: goto label_80071C40;
    case 0x80071C44u: goto label_80071C44;
    case 0x80071C48u: goto label_80071C48;
    case 0x80071C4Cu: goto label_80071C4C;
    case 0x80071C50u: goto label_80071C50;
    case 0x80071C54u: goto label_80071C54;
    case 0x80071C58u: goto label_80071C58;
    case 0x80071C5Cu: goto label_80071C5C;
    case 0x80071C60u: goto label_80071C60;
    case 0x80071C64u: goto label_80071C64;
    case 0x80071C68u: goto label_80071C68;
    case 0x80071C6Cu: goto label_80071C6C;
    case 0x80071C70u: goto label_80071C70;
    case 0x80071C74u: goto label_80071C74;
    case 0x80071C78u: goto label_80071C78;
    case 0x80071C7Cu: goto label_80071C7C;
    case 0x80071C80u: goto label_80071C80;
    case 0x80071C84u: goto label_80071C84;
    case 0x80071C88u: goto label_80071C88;
    case 0x80071C8Cu: goto label_80071C8C;
    case 0x80071C90u: goto label_80071C90;
    case 0x80071C94u: goto label_80071C94;
    case 0x80071C98u: goto label_80071C98;
    case 0x80071C9Cu: goto label_80071C9C;
    case 0x80071CA0u: goto label_80071CA0;
    case 0x80071CA4u: goto label_80071CA4;
    case 0x80071CA8u: goto label_80071CA8;
    case 0x80071CACu: goto label_80071CAC;
    case 0x80071CB0u: goto label_80071CB0;
    case 0x80071CB4u: goto label_80071CB4;
    case 0x80071CB8u: goto label_80071CB8;
    case 0x80071CBCu: goto label_80071CBC;
    case 0x80071CC0u: goto label_80071CC0;
    case 0x80071CC4u: goto label_80071CC4;
    case 0x80071CC8u: goto label_80071CC8;
    case 0x80071CCCu: goto label_80071CCC;
    case 0x80071CD0u: goto label_80071CD0;
    case 0x80071CD4u: goto label_80071CD4;
    case 0x80071CD8u: goto label_80071CD8;
    case 0x80071CDCu: goto label_80071CDC;
    case 0x80071CE0u: goto label_80071CE0;
    case 0x80071CE4u: goto label_80071CE4;
    case 0x80071CE8u: goto label_80071CE8;
    case 0x80071CECu: goto label_80071CEC;
    case 0x80071CF0u: goto label_80071CF0;
    case 0x80071CF4u: goto label_80071CF4;
    case 0x80071CF8u: goto label_80071CF8;
    case 0x80071CFCu: goto label_80071CFC;
    case 0x80071D00u: goto label_80071D00;
    case 0x80071D04u: goto label_80071D04;
    case 0x80071D08u: goto label_80071D08;
    case 0x80071D0Cu: goto label_80071D0C;
    case 0x80071D10u: goto label_80071D10;
    case 0x80071D14u: goto label_80071D14;
    case 0x80071D18u: goto label_80071D18;
    case 0x80071D1Cu: goto label_80071D1C;
    case 0x80071D20u: goto label_80071D20;
    case 0x80071D24u: goto label_80071D24;
    case 0x80071D28u: goto label_80071D28;
    case 0x80071D2Cu: goto label_80071D2C;
    case 0x80071D30u: goto label_80071D30;
    case 0x80071D34u: goto label_80071D34;
    case 0x80071D38u: goto label_80071D38;
    case 0x80071D3Cu: goto label_80071D3C;
    case 0x80071D40u: goto label_80071D40;
    case 0x80071D44u: goto label_80071D44;
    case 0x80071D48u: goto label_80071D48;
    case 0x80071D4Cu: goto label_80071D4C;
    case 0x80071D50u: goto label_80071D50;
    case 0x80071D54u: goto label_80071D54;
    case 0x80071D58u: goto label_80071D58;
    case 0x80071D5Cu: goto label_80071D5C;
    case 0x80071D60u: goto label_80071D60;
    case 0x80071D64u: goto label_80071D64;
    case 0x80071D68u: goto label_80071D68;
    case 0x80071D6Cu: goto label_80071D6C;
    case 0x80071D70u: goto label_80071D70;
    case 0x80071D74u: goto label_80071D74;
    case 0x80071D78u: goto label_80071D78;
    case 0x80071D7Cu: goto label_80071D7C;
    case 0x80071D80u: goto label_80071D80;
    case 0x80071D84u: goto label_80071D84;
    case 0x80071D88u: goto label_80071D88;
    case 0x80071D8Cu: goto label_80071D8C;
    case 0x80071D90u: goto label_80071D90;
    case 0x80071D94u: goto label_80071D94;
    case 0x80071D98u: goto label_80071D98;
    case 0x80071D9Cu: goto label_80071D9C;
    case 0x80071DA0u: goto label_80071DA0;
    case 0x80071DA4u: goto label_80071DA4;
    case 0x80071DA8u: goto label_80071DA8;
    case 0x80071DACu: goto label_80071DAC;
    case 0x80071DB0u: goto label_80071DB0;
    case 0x80071DB4u: goto label_80071DB4;
    case 0x80071DB8u: goto label_80071DB8;
    case 0x80071DBCu: goto label_80071DBC;
    case 0x80071DC0u: goto label_80071DC0;
    case 0x80071DC4u: goto label_80071DC4;
    case 0x80071DC8u: goto label_80071DC8;
    case 0x80071DCCu: goto label_80071DCC;
    case 0x80071DD0u: goto label_80071DD0;
    case 0x80071DD4u: goto label_80071DD4;
    case 0x80071DD8u: goto label_80071DD8;
    case 0x80071DDCu: goto label_80071DDC;
    case 0x80071DE0u: goto label_80071DE0;
    case 0x80071DE4u: goto label_80071DE4;
    case 0x80071DE8u: goto label_80071DE8;
    case 0x80071DECu: goto label_80071DEC;
    case 0x80071DF0u: goto label_80071DF0;
    case 0x80071DF4u: goto label_80071DF4;
    case 0x80071DF8u: goto label_80071DF8;
    case 0x80071DFCu: goto label_80071DFC;
    case 0x80071E00u: goto label_80071E00;
    case 0x80071E04u: goto label_80071E04;
    case 0x80071E08u: goto label_80071E08;
    case 0x80071E0Cu: goto label_80071E0C;
    case 0x80071E10u: goto label_80071E10;
    case 0x80071E14u: goto label_80071E14;
    case 0x80071E18u: goto label_80071E18;
    case 0x80071E1Cu: goto label_80071E1C;
    case 0x80071E20u: goto label_80071E20;
    case 0x80071E24u: goto label_80071E24;
    case 0x80071E28u: goto label_80071E28;
    case 0x80071E2Cu: goto label_80071E2C;
    case 0x80071E30u: goto label_80071E30;
    case 0x80071E34u: goto label_80071E34;
    case 0x80071E38u: goto label_80071E38;
    case 0x80071E3Cu: goto label_80071E3C;
    case 0x80071E40u: goto label_80071E40;
    case 0x80071E44u: goto label_80071E44;
    case 0x80071E48u: goto label_80071E48;
    case 0x80071E4Cu: goto label_80071E4C;
    case 0x80071E50u: goto label_80071E50;
    case 0x80071E54u: goto label_80071E54;
    case 0x80071E58u: goto label_80071E58;
    case 0x80071E5Cu: goto label_80071E5C;
    case 0x80071E60u: goto label_80071E60;
    case 0x80071E64u: goto label_80071E64;
    case 0x80071E68u: goto label_80071E68;
    case 0x80071E6Cu: goto label_80071E6C;
    case 0x80071E70u: goto label_80071E70;
    case 0x80071E74u: goto label_80071E74;
    case 0x80071E78u: goto label_80071E78;
    case 0x80071E7Cu: goto label_80071E7C;
    case 0x80071E80u: goto label_80071E80;
    case 0x80071E84u: goto label_80071E84;
    case 0x80071E88u: goto label_80071E88;
    case 0x80071E8Cu: goto label_80071E8C;
    case 0x80071E90u: goto label_80071E90;
    case 0x80071E94u: goto label_80071E94;
    case 0x80071E98u: goto label_80071E98;
    case 0x80071E9Cu: goto label_80071E9C;
    case 0x80071EA0u: goto label_80071EA0;
    case 0x80071EA4u: goto label_80071EA4;
    case 0x80071EA8u: goto label_80071EA8;
    case 0x80071EACu: goto label_80071EAC;
    case 0x80071EB0u: goto label_80071EB0;
    case 0x80071EB4u: goto label_80071EB4;
    case 0x80071EB8u: goto label_80071EB8;
    case 0x80071EBCu: goto label_80071EBC;
    case 0x80071EC0u: goto label_80071EC0;
    case 0x80071EC4u: goto label_80071EC4;
    case 0x80071EC8u: goto label_80071EC8;
    case 0x80071ECCu: goto label_80071ECC;
    case 0x80071ED0u: goto label_80071ED0;
    case 0x80071ED4u: goto label_80071ED4;
    case 0x80071ED8u: goto label_80071ED8;
    case 0x80071EDCu: goto label_80071EDC;
    case 0x80071EE0u: goto label_80071EE0;
    case 0x80071EE4u: goto label_80071EE4;
    case 0x80071EE8u: goto label_80071EE8;
    case 0x80071EECu: goto label_80071EEC;
    case 0x80071EF0u: goto label_80071EF0;
    case 0x80071EF4u: goto label_80071EF4;
    case 0x80071EF8u: goto label_80071EF8;
    case 0x80071EFCu: goto label_80071EFC;
    case 0x80071F00u: goto label_80071F00;
    case 0x80071F04u: goto label_80071F04;
    case 0x80071F08u: goto label_80071F08;
    case 0x80071F0Cu: goto label_80071F0C;
    case 0x80071F10u: goto label_80071F10;
    case 0x80071F14u: goto label_80071F14;
    case 0x80071F18u: goto label_80071F18;
    case 0x80071F1Cu: goto label_80071F1C;
    case 0x80071F20u: goto label_80071F20;
    case 0x80071F24u: goto label_80071F24;
    case 0x80071F28u: goto label_80071F28;
    case 0x80071F2Cu: goto label_80071F2C;
    case 0x80071F30u: goto label_80071F30;
    case 0x80071F34u: goto label_80071F34;
    case 0x80071F38u: goto label_80071F38;
    case 0x80071F3Cu: goto label_80071F3C;
    case 0x80071F40u: goto label_80071F40;
    case 0x80071F44u: goto label_80071F44;
    case 0x80071F48u: goto label_80071F48;
    case 0x80071F4Cu: goto label_80071F4C;
    case 0x80071F50u: goto label_80071F50;
    case 0x80071F54u: goto label_80071F54;
    case 0x80071F58u: goto label_80071F58;
    case 0x80071F5Cu: goto label_80071F5C;
    case 0x80071F60u: goto label_80071F60;
    case 0x80071F64u: goto label_80071F64;
    case 0x80071F68u: goto label_80071F68;
    case 0x80071F6Cu: goto label_80071F6C;
    case 0x80071F70u: goto label_80071F70;
    case 0x80071F74u: goto label_80071F74;
    case 0x80071F78u: goto label_80071F78;
    case 0x80071F7Cu: goto label_80071F7C;
    case 0x80071F80u: goto label_80071F80;
    case 0x80071F84u: goto label_80071F84;
    case 0x80071F88u: goto label_80071F88;
    case 0x80071F8Cu: goto label_80071F8C;
    case 0x80071F90u: goto label_80071F90;
    case 0x80071F94u: goto label_80071F94;
    case 0x80071F98u: goto label_80071F98;
    case 0x80071F9Cu: goto label_80071F9C;
    case 0x80071FA0u: goto label_80071FA0;
    case 0x80071FA4u: goto label_80071FA4;
    case 0x80071FA8u: goto label_80071FA8;
    case 0x80071FACu: goto label_80071FAC;
    case 0x80071FB0u: goto label_80071FB0;
    case 0x80071FB4u: goto label_80071FB4;
    case 0x80071FB8u: goto label_80071FB8;
    case 0x80071FBCu: goto label_80071FBC;
    case 0x80071FC0u: goto label_80071FC0;
    case 0x80071FC4u: goto label_80071FC4;
    case 0x80071FC8u: goto label_80071FC8;
    case 0x80071FCCu: goto label_80071FCC;
    case 0x80071FD0u: goto label_80071FD0;
    case 0x80071FD4u: goto label_80071FD4;
    case 0x80071FD8u: goto label_80071FD8;
    case 0x80071FDCu: goto label_80071FDC;
    case 0x80071FE0u: goto label_80071FE0;
    case 0x80071FE4u: goto label_80071FE4;
    case 0x80071FE8u: goto label_80071FE8;
    case 0x80071FECu: goto label_80071FEC;
    case 0x80071FF0u: goto label_80071FF0;
    case 0x80071FF4u: goto label_80071FF4;
    case 0x80071FF8u: goto label_80071FF8;
    case 0x80071FFCu: goto label_80071FFC;
    case 0x80072000u: goto label_80072000;
    case 0x80072004u: goto label_80072004;
    case 0x80072008u: goto label_80072008;
    case 0x8007200Cu: goto label_8007200C;
    case 0x80072010u: goto label_80072010;
    case 0x80072014u: goto label_80072014;
    case 0x80072018u: goto label_80072018;
    case 0x8007201Cu: goto label_8007201C;
    case 0x80072020u: goto label_80072020;
    case 0x80072024u: goto label_80072024;
    case 0x80072028u: goto label_80072028;
    case 0x8007202Cu: goto label_8007202C;
    case 0x80072030u: goto label_80072030;
    case 0x80072034u: goto label_80072034;
    case 0x80072038u: goto label_80072038;
    case 0x8007203Cu: goto label_8007203C;
    case 0x80072040u: goto label_80072040;
    case 0x80072044u: goto label_80072044;
    case 0x80072048u: goto label_80072048;
    case 0x8007204Cu: goto label_8007204C;
    case 0x80072050u: goto label_80072050;
    case 0x80072054u: goto label_80072054;
    case 0x80072058u: goto label_80072058;
    case 0x8007205Cu: goto label_8007205C;
    case 0x80072060u: goto label_80072060;
    case 0x80072064u: goto label_80072064;
    case 0x80072068u: goto label_80072068;
    case 0x8007206Cu: goto label_8007206C;
    case 0x80072070u: goto label_80072070;
    case 0x80072074u: goto label_80072074;
    case 0x80072078u: goto label_80072078;
    case 0x8007207Cu: goto label_8007207C;
    case 0x80072080u: goto label_80072080;
    case 0x80072084u: goto label_80072084;
    case 0x80072088u: goto label_80072088;
    case 0x8007208Cu: goto label_8007208C;
    case 0x80072090u: goto label_80072090;
    case 0x80072094u: goto label_80072094;
    case 0x80072098u: goto label_80072098;
    case 0x8007209Cu: goto label_8007209C;
    case 0x800720A0u: goto label_800720A0;
    case 0x800720A4u: goto label_800720A4;
    case 0x800720A8u: goto label_800720A8;
    case 0x800720ACu: goto label_800720AC;
    case 0x800720B0u: goto label_800720B0;
    case 0x800720B4u: goto label_800720B4;
    case 0x800720B8u: goto label_800720B8;
    case 0x800720BCu: goto label_800720BC;
    case 0x800720C0u: goto label_800720C0;
    case 0x800720C4u: goto label_800720C4;
    case 0x800720C8u: goto label_800720C8;
    case 0x800720CCu: goto label_800720CC;
    case 0x800720D0u: goto label_800720D0;
    case 0x800720D4u: goto label_800720D4;
    case 0x800720D8u: goto label_800720D8;
    case 0x800720DCu: goto label_800720DC;
    case 0x800720E0u: goto label_800720E0;
    case 0x800720E4u: goto label_800720E4;
    case 0x800720E8u: goto label_800720E8;
    case 0x800720ECu: goto label_800720EC;
    case 0x800720F0u: goto label_800720F0;
    case 0x800720F4u: goto label_800720F4;
    case 0x800720F8u: goto label_800720F8;
    case 0x800720FCu: goto label_800720FC;
    case 0x80072100u: goto label_80072100;
    case 0x80072104u: goto label_80072104;
    case 0x80072108u: goto label_80072108;
    case 0x8007210Cu: goto label_8007210C;
    case 0x80072110u: goto label_80072110;
    case 0x80072114u: goto label_80072114;
    case 0x80072118u: goto label_80072118;
    case 0x8007211Cu: goto label_8007211C;
    case 0x80072120u: goto label_80072120;
    case 0x80072124u: goto label_80072124;
    case 0x80072128u: goto label_80072128;
    case 0x8007212Cu: goto label_8007212C;
    case 0x80072130u: goto label_80072130;
    case 0x80072134u: goto label_80072134;
    case 0x80072138u: goto label_80072138;
    case 0x8007213Cu: goto label_8007213C;
    case 0x80072140u: goto label_80072140;
    case 0x80072144u: goto label_80072144;
    case 0x80072148u: goto label_80072148;
    case 0x8007214Cu: goto label_8007214C;
    case 0x80072150u: goto label_80072150;
    case 0x80072154u: goto label_80072154;
    case 0x80072158u: goto label_80072158;
    case 0x8007215Cu: goto label_8007215C;
    case 0x80072160u: goto label_80072160;
    case 0x80072164u: goto label_80072164;
    case 0x80072168u: goto label_80072168;
    case 0x8007216Cu: goto label_8007216C;
    case 0x80072170u: goto label_80072170;
    case 0x80072174u: goto label_80072174;
    case 0x80072178u: goto label_80072178;
    case 0x8007217Cu: goto label_8007217C;
    case 0x80072180u: goto label_80072180;
    case 0x80072184u: goto label_80072184;
    case 0x80072188u: goto label_80072188;
    case 0x8007218Cu: goto label_8007218C;
    case 0x80072190u: goto label_80072190;
    case 0x80072194u: goto label_80072194;
    case 0x80072198u: goto label_80072198;
    case 0x8007219Cu: goto label_8007219C;
    case 0x800721A0u: goto label_800721A0;
    case 0x800721A4u: goto label_800721A4;
    case 0x800721A8u: goto label_800721A8;
    case 0x800721ACu: goto label_800721AC;
    case 0x800721B0u: goto label_800721B0;
    case 0x800721B4u: goto label_800721B4;
    case 0x800721B8u: goto label_800721B8;
    case 0x800721BCu: goto label_800721BC;
    case 0x800721C0u: goto label_800721C0;
    case 0x800721C4u: goto label_800721C4;
    case 0x800721C8u: goto label_800721C8;
    case 0x800721CCu: goto label_800721CC;
    case 0x800721D0u: goto label_800721D0;
    case 0x800721D4u: goto label_800721D4;
    case 0x800721D8u: goto label_800721D8;
    case 0x800721DCu: goto label_800721DC;
    case 0x800721E0u: goto label_800721E0;
    case 0x800721E4u: goto label_800721E4;
    case 0x800721E8u: goto label_800721E8;
    case 0x800721ECu: goto label_800721EC;
    case 0x800721F0u: goto label_800721F0;
    case 0x800721F4u: goto label_800721F4;
    case 0x800721F8u: goto label_800721F8;
    case 0x800721FCu: goto label_800721FC;
    case 0x80072200u: goto label_80072200;
    case 0x80072204u: goto label_80072204;
    case 0x80072208u: goto label_80072208;
    case 0x8007220Cu: goto label_8007220C;
    case 0x80072210u: goto label_80072210;
    case 0x80072214u: goto label_80072214;
    case 0x80072218u: goto label_80072218;
    case 0x8007221Cu: goto label_8007221C;
    case 0x80072220u: goto label_80072220;
    case 0x80072224u: goto label_80072224;
    case 0x80072228u: goto label_80072228;
    case 0x8007222Cu: goto label_8007222C;
    case 0x80072230u: goto label_80072230;
    case 0x80072234u: goto label_80072234;
    case 0x80072238u: goto label_80072238;
    case 0x8007223Cu: goto label_8007223C;
    case 0x80072240u: goto label_80072240;
    case 0x80072244u: goto label_80072244;
    case 0x80072248u: goto label_80072248;
    case 0x8007224Cu: goto label_8007224C;
    case 0x80072250u: goto label_80072250;
    case 0x80072254u: goto label_80072254;
    case 0x80072258u: goto label_80072258;
    case 0x8007225Cu: goto label_8007225C;
    case 0x80072260u: goto label_80072260;
    case 0x80072264u: goto label_80072264;
    case 0x80072268u: goto label_80072268;
    case 0x8007226Cu: goto label_8007226C;
    case 0x80072270u: goto label_80072270;
    case 0x80072274u: goto label_80072274;
    case 0x80072278u: goto label_80072278;
    case 0x8007227Cu: goto label_8007227C;
    case 0x80072280u: goto label_80072280;
    case 0x80072284u: goto label_80072284;
    case 0x80072288u: goto label_80072288;
    case 0x8007228Cu: goto label_8007228C;
    case 0x80072290u: goto label_80072290;
    case 0x80072294u: goto label_80072294;
    case 0x80072298u: goto label_80072298;
    case 0x8007229Cu: goto label_8007229C;
    case 0x800722A0u: goto label_800722A0;
    case 0x800722A4u: goto label_800722A4;
    case 0x800722A8u: goto label_800722A8;
    case 0x800722ACu: goto label_800722AC;
    case 0x800722B0u: goto label_800722B0;
    case 0x800722B4u: goto label_800722B4;
    case 0x800722B8u: goto label_800722B8;
    case 0x800722BCu: goto label_800722BC;
    case 0x800722C0u: goto label_800722C0;
    case 0x800722C4u: goto label_800722C4;
    case 0x800722C8u: goto label_800722C8;
    case 0x800722CCu: goto label_800722CC;
    case 0x800722D0u: goto label_800722D0;
    case 0x800722D4u: goto label_800722D4;
    case 0x800722D8u: goto label_800722D8;
    case 0x800722DCu: goto label_800722DC;
    case 0x800722E0u: goto label_800722E0;
    case 0x800722E4u: goto label_800722E4;
    case 0x800722E8u: goto label_800722E8;
    case 0x800722ECu: goto label_800722EC;
    case 0x800722F0u: goto label_800722F0;
    case 0x800722F4u: goto label_800722F4;
    case 0x800722F8u: goto label_800722F8;
    case 0x800722FCu: goto label_800722FC;
    case 0x80072300u: goto label_80072300;
    case 0x80072304u: goto label_80072304;
    case 0x80072308u: goto label_80072308;
    case 0x8007230Cu: goto label_8007230C;
    case 0x80072310u: goto label_80072310;
    case 0x80072314u: goto label_80072314;
    case 0x80072318u: goto label_80072318;
    case 0x8007231Cu: goto label_8007231C;
    case 0x80072320u: goto label_80072320;
    case 0x80072324u: goto label_80072324;
    case 0x80072328u: goto label_80072328;
    case 0x8007232Cu: goto label_8007232C;
    case 0x80072330u: goto label_80072330;
    case 0x80072334u: goto label_80072334;
    case 0x80072338u: goto label_80072338;
    case 0x8007233Cu: goto label_8007233C;
    case 0x80072340u: goto label_80072340;
    case 0x80072344u: goto label_80072344;
    case 0x80072348u: goto label_80072348;
    case 0x8007234Cu: goto label_8007234C;
    case 0x80072350u: goto label_80072350;
    case 0x80072354u: goto label_80072354;
    case 0x80072358u: goto label_80072358;
    case 0x8007235Cu: goto label_8007235C;
    case 0x80072360u: goto label_80072360;
    case 0x80072364u: goto label_80072364;
    case 0x80072368u: goto label_80072368;
    case 0x8007236Cu: goto label_8007236C;
    case 0x80072370u: goto label_80072370;
    case 0x80072374u: goto label_80072374;
    case 0x80072378u: goto label_80072378;
    case 0x8007237Cu: goto label_8007237C;
    case 0x80072380u: goto label_80072380;
    case 0x80072384u: goto label_80072384;
    case 0x80072388u: goto label_80072388;
    case 0x8007238Cu: goto label_8007238C;
    case 0x80072390u: goto label_80072390;
    case 0x80072394u: goto label_80072394;
    case 0x80072398u: goto label_80072398;
    case 0x8007239Cu: goto label_8007239C;
    case 0x800723A0u: goto label_800723A0;
    case 0x800723A4u: goto label_800723A4;
    case 0x800723A8u: goto label_800723A8;
    case 0x800723ACu: goto label_800723AC;
    case 0x800723B0u: goto label_800723B0;
    case 0x800723B4u: goto label_800723B4;
    case 0x800723B8u: goto label_800723B8;
    case 0x800723BCu: goto label_800723BC;
    case 0x800723C0u: goto label_800723C0;
    case 0x800723C4u: goto label_800723C4;
    case 0x800723C8u: goto label_800723C8;
    case 0x800723CCu: goto label_800723CC;
    case 0x800723D0u: goto label_800723D0;
    case 0x800723D4u: goto label_800723D4;
    case 0x800723D8u: goto label_800723D8;
    case 0x800723DCu: goto label_800723DC;
    case 0x800723E0u: goto label_800723E0;
    case 0x800723E4u: goto label_800723E4;
    case 0x800723E8u: goto label_800723E8;
    case 0x800723ECu: goto label_800723EC;
    case 0x800723F0u: goto label_800723F0;
    case 0x800723F4u: goto label_800723F4;
    case 0x800723F8u: goto label_800723F8;
    case 0x800723FCu: goto label_800723FC;
    case 0x80072400u: goto label_80072400;
    case 0x80072404u: goto label_80072404;
    case 0x80072408u: goto label_80072408;
    case 0x8007240Cu: goto label_8007240C;
    case 0x80072410u: goto label_80072410;
    case 0x80072414u: goto label_80072414;
    case 0x80072418u: goto label_80072418;
    case 0x8007241Cu: goto label_8007241C;
    case 0x80072420u: goto label_80072420;
    case 0x80072424u: goto label_80072424;
    case 0x80072428u: goto label_80072428;
    case 0x8007242Cu: goto label_8007242C;
    case 0x80072430u: goto label_80072430;
    case 0x80072434u: goto label_80072434;
    case 0x80072438u: goto label_80072438;
    case 0x8007243Cu: goto label_8007243C;
    case 0x80072440u: goto label_80072440;
    case 0x80072444u: goto label_80072444;
    case 0x80072448u: goto label_80072448;
    case 0x8007244Cu: goto label_8007244C;
    case 0x80072450u: goto label_80072450;
    case 0x80072454u: goto label_80072454;
    case 0x80072458u: goto label_80072458;
    case 0x8007245Cu: goto label_8007245C;
    case 0x80072460u: goto label_80072460;
    case 0x80072464u: goto label_80072464;
    case 0x80072468u: goto label_80072468;
    case 0x8007246Cu: goto label_8007246C;
    case 0x80072470u: goto label_80072470;
    case 0x80072474u: goto label_80072474;
    case 0x80072478u: goto label_80072478;
    case 0x8007247Cu: goto label_8007247C;
    case 0x80072480u: goto label_80072480;
    case 0x80072484u: goto label_80072484;
    case 0x80072488u: goto label_80072488;
    case 0x8007248Cu: goto label_8007248C;
    case 0x80072490u: goto label_80072490;
    case 0x80072494u: goto label_80072494;
    case 0x80072498u: goto label_80072498;
    case 0x8007249Cu: goto label_8007249C;
    case 0x800724A0u: goto label_800724A0;
    case 0x800724A4u: goto label_800724A4;
    case 0x800724A8u: goto label_800724A8;
    case 0x800724ACu: goto label_800724AC;
    case 0x800724B0u: goto label_800724B0;
    case 0x800724B4u: goto label_800724B4;
    case 0x800724B8u: goto label_800724B8;
    case 0x800724BCu: goto label_800724BC;
    case 0x800724C0u: goto label_800724C0;
    case 0x800724C4u: goto label_800724C4;
    case 0x800724C8u: goto label_800724C8;
    case 0x800724CCu: goto label_800724CC;
    case 0x800724D0u: goto label_800724D0;
    case 0x800724D4u: goto label_800724D4;
    case 0x800724D8u: goto label_800724D8;
    case 0x800724DCu: goto label_800724DC;
    case 0x800724E0u: goto label_800724E0;
    case 0x800724E4u: goto label_800724E4;
    case 0x800724E8u: goto label_800724E8;
    case 0x800724ECu: goto label_800724EC;
    case 0x800724F0u: goto label_800724F0;
    case 0x800724F4u: goto label_800724F4;
    case 0x800724F8u: goto label_800724F8;
    case 0x800724FCu: goto label_800724FC;
    case 0x80072500u: goto label_80072500;
    case 0x80072504u: goto label_80072504;
    case 0x80072508u: goto label_80072508;
    case 0x8007250Cu: goto label_8007250C;
    case 0x80072510u: goto label_80072510;
    case 0x80072514u: goto label_80072514;
    case 0x80072518u: goto label_80072518;
    case 0x8007251Cu: goto label_8007251C;
    case 0x80072520u: goto label_80072520;
    case 0x80072524u: goto label_80072524;
    case 0x80072528u: goto label_80072528;
    case 0x8007252Cu: goto label_8007252C;
    case 0x80072530u: goto label_80072530;
    case 0x80072534u: goto label_80072534;
    case 0x80072538u: goto label_80072538;
    case 0x8007253Cu: goto label_8007253C;
    case 0x80072540u: goto label_80072540;
    case 0x80072544u: goto label_80072544;
    case 0x80072548u: goto label_80072548;
    case 0x8007254Cu: goto label_8007254C;
    case 0x80072550u: goto label_80072550;
    case 0x80072554u: goto label_80072554;
    case 0x80072558u: goto label_80072558;
    case 0x8007255Cu: goto label_8007255C;
    case 0x80072560u: goto label_80072560;
    case 0x80072564u: goto label_80072564;
    case 0x80072568u: goto label_80072568;
    case 0x8007256Cu: goto label_8007256C;
    case 0x80072570u: goto label_80072570;
    case 0x80072574u: goto label_80072574;
    case 0x80072578u: goto label_80072578;
    case 0x8007257Cu: goto label_8007257C;
    case 0x80072580u: goto label_80072580;
    case 0x80072584u: goto label_80072584;
    case 0x80072588u: goto label_80072588;
    case 0x8007258Cu: goto label_8007258C;
    case 0x80072590u: goto label_80072590;
    case 0x80072594u: goto label_80072594;
    case 0x80072598u: goto label_80072598;
    case 0x8007259Cu: goto label_8007259C;
    case 0x800725A0u: goto label_800725A0;
    case 0x800725A4u: goto label_800725A4;
    case 0x800725A8u: goto label_800725A8;
    case 0x800725ACu: goto label_800725AC;
    case 0x800725B0u: goto label_800725B0;
    case 0x800725B4u: goto label_800725B4;
    case 0x800725B8u: goto label_800725B8;
    case 0x800725BCu: goto label_800725BC;
    case 0x800725C0u: goto label_800725C0;
    case 0x800725C4u: goto label_800725C4;
    case 0x800725C8u: goto label_800725C8;
    case 0x800725CCu: goto label_800725CC;
    case 0x800725D0u: goto label_800725D0;
    case 0x800725D4u: goto label_800725D4;
    case 0x800725D8u: goto label_800725D8;
    case 0x800725DCu: goto label_800725DC;
    case 0x800725E0u: goto label_800725E0;
    case 0x800725E4u: goto label_800725E4;
    case 0x800725E8u: goto label_800725E8;
    case 0x800725ECu: goto label_800725EC;
    case 0x800725F0u: goto label_800725F0;
    case 0x800725F4u: goto label_800725F4;
    case 0x800725F8u: goto label_800725F8;
    case 0x800725FCu: goto label_800725FC;
    case 0x80072600u: goto label_80072600;
    case 0x80072604u: goto label_80072604;
    case 0x80072608u: goto label_80072608;
    case 0x8007260Cu: goto label_8007260C;
    case 0x80072610u: goto label_80072610;
    case 0x80072614u: goto label_80072614;
    case 0x80072618u: goto label_80072618;
    case 0x8007261Cu: goto label_8007261C;
    case 0x80072620u: goto label_80072620;
    case 0x80072624u: goto label_80072624;
    case 0x80072628u: goto label_80072628;
    case 0x8007262Cu: goto label_8007262C;
    case 0x80072630u: goto label_80072630;
    case 0x80072634u: goto label_80072634;
    case 0x80072638u: goto label_80072638;
    case 0x8007263Cu: goto label_8007263C;
    case 0x80072640u: goto label_80072640;
    case 0x80072644u: goto label_80072644;
    case 0x80072648u: goto label_80072648;
    case 0x8007264Cu: goto label_8007264C;
    case 0x80072650u: goto label_80072650;
    case 0x80072654u: goto label_80072654;
    case 0x80072658u: goto label_80072658;
    case 0x8007265Cu: goto label_8007265C;
    case 0x80072660u: goto label_80072660;
    case 0x80072664u: goto label_80072664;
    case 0x80072668u: goto label_80072668;
    case 0x8007266Cu: goto label_8007266C;
    case 0x80072670u: goto label_80072670;
    case 0x80072674u: goto label_80072674;
    case 0x80072678u: goto label_80072678;
    case 0x8007267Cu: goto label_8007267C;
    case 0x80072680u: goto label_80072680;
    case 0x80072684u: goto label_80072684;
    case 0x80072688u: goto label_80072688;
    case 0x8007268Cu: goto label_8007268C;
    case 0x80072690u: goto label_80072690;
    case 0x80072694u: goto label_80072694;
    case 0x80072698u: goto label_80072698;
    case 0x8007269Cu: goto label_8007269C;
    case 0x800726A0u: goto label_800726A0;
    case 0x800726A4u: goto label_800726A4;
    case 0x800726A8u: goto label_800726A8;
    case 0x800726ACu: goto label_800726AC;
    case 0x800726B0u: goto label_800726B0;
    case 0x800726B4u: goto label_800726B4;
    case 0x800726B8u: goto label_800726B8;
    case 0x800726BCu: goto label_800726BC;
    case 0x800726C0u: goto label_800726C0;
    case 0x800726C4u: goto label_800726C4;
    case 0x800726C8u: goto label_800726C8;
    case 0x800726CCu: goto label_800726CC;
    case 0x800726D0u: goto label_800726D0;
    case 0x800726D4u: goto label_800726D4;
    case 0x800726D8u: goto label_800726D8;
    case 0x800726DCu: goto label_800726DC;
    default: return;
    }
label_8006E6E0:
    ctx->pc = 0x8006E6E0u;
    ctx->downcount -= 13;
    // 8006E6E0: fnmsub f0, f10, f0, f4
    if (!ppc_fp_available_inline(ctx, 0x8006E6E0u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[10], ctx->fpr[0], ctx->fpr[4], false, true, true, &result))
            ctx->fpr[0] = result;
    }

label_8006E6E4:
    ctx->pc = 0x8006E6E4u;
    // 8006E6E4: fmul   f0, f3, f0
    if (!ppc_fp_available_inline(ctx, 0x8006E6E4u)) return;
    ppc_fmul(ctx, 0, 3, 0);

label_8006E6E8:
    ctx->pc = 0x8006E6E8u;
    // 8006E6E8: fmul   f3, f5, f0
    if (!ppc_fp_available_inline(ctx, 0x8006E6E8u)) return;
    ppc_fmul(ctx, 3, 5, 0);

label_8006E6EC:
    ctx->pc = 0x8006E6ECu;
    // 8006E6EC: fmul   f0, f0, f0
    if (!ppc_fp_available_inline(ctx, 0x8006E6ECu)) return;
    ppc_fmul(ctx, 0, 0, 0);

label_8006E6F0:
    ctx->pc = 0x8006E6F0u;
    // 8006E6F0: fnmsub f0, f10, f0, f4
    if (!ppc_fp_available_inline(ctx, 0x8006E6F0u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[10], ctx->fpr[0], ctx->fpr[4], false, true, true, &result))
            ctx->fpr[0] = result;
    }

label_8006E6F4:
    ctx->pc = 0x8006E6F4u;
    // 8006E6F4: fmul   f0, f3, f0
    if (!ppc_fp_available_inline(ctx, 0x8006E6F4u)) return;
    ppc_fmul(ctx, 0, 3, 0);

label_8006E6F8:
    ctx->pc = 0x8006E6F8u;
    // 8006E6F8: fmul   f0, f10, f0
    if (!ppc_fp_available_inline(ctx, 0x8006E6F8u)) return;
    ppc_fmul(ctx, 0, 10, 0);

label_8006E6FC:
    ctx->pc = 0x8006E6FCu;
    // 8006E6FC: frsp    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x8006E6FCu)) return;
    ppc_frsp(ctx, 0, 0);

label_8006E700:
    ctx->pc = 0x8006E700u;
    // 8006E700: stfs     f0, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006E700u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8006E704:
    ctx->pc = 0x8006E704u;
    // 8006E704: lfs     f10, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006E704u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[10] = value;
        ctx->ps1[10] = value;
    }

label_8006E708:
    ctx->pc = 0x8006E708u;
    // 8006E708: fsubs   f0, f2, f10
    if (!ppc_fp_available_inline(ctx, 0x8006E708u)) return;
    ppc_fsubs(ctx, 0, 2, 10);

label_8006E70C:
    ctx->pc = 0x8006E70Cu;
    // 8006E70C: fcmpo   cr0, f0, f6
    if (!ppc_fp_available_inline(ctx, 0x8006E70Cu)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[0], ctx->fpr[6], true);

label_8006E710:
    ctx->pc = 0x8006E710u;
    // 8006E710: bc    4, 0, 0x8006E718
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8006E718;
        }
    }

label_8006E714:
    ctx->pc = 0x8006E714u;
    ctx->downcount -= 1;
    // 8006E714: fmr    f0, f6
    if (!ppc_fp_available_inline(ctx, 0x8006E714u)) return;
    ctx->fpr[0] = ctx->fpr[6];

label_8006E718:
    ctx->pc = 0x8006E718u;
    ctx->downcount -= 7;
    // 8006E718: fmuls   f0, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8006E718u)) return;
    ppc_fmuls(ctx, 0, 1, 0);

label_8006E71C:
    ctx->pc = 0x8006E71Cu;
    // 8006E71C: fctiwz    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x8006E71Cu)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_8006E720:
    ctx->pc = 0x8006E720u;
    // 8006E720: stfd     f0, 88(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006E720u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_8006E724:
    ctx->pc = 0x8006E724u;
    // 8006E724: lwz     r0, 92(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8006E728:
    ctx->pc = 0x8006E728u;
    // 8006E728: stbx    r0, r6, r4
    {
        u32 ea = ctx->gpr[6] + ctx->gpr[4];
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006E72C:
    ctx->pc = 0x8006E72Cu;
    // 8006E72C: addi    r8, r8, 1
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(1);

label_8006E730:
    ctx->pc = 0x8006E730u;
    // 8006E730: bc    16, 0, 0x8006E66C
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = 0x8006E66Cu;
            return;
        }
    }

label_8006E734:
    ctx->pc = 0x8006E734u;
    ctx->downcount -= 3;
    // 8006E734: addi    r7, r7, 1
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(1);

label_8006E738:
    ctx->pc = 0x8006E738u;
    // 8006E738: cmpwi   r7, 128
    {
        s32 val_a = (s32)(ctx->gpr[7]);
        s32 val_b = (s32)(128);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8006E73C:
    ctx->pc = 0x8006E73Cu;
    // 8006E73C: bc    12, 0, 0x8006E630
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = 0x8006E630u;
            return;
        }
    }

label_8006E740:
    ctx->pc = 0x8006E740u;
    ctx->downcount -= 4;
    // 8006E740: lwz     r4, -25032(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25032);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8006E744:
    ctx->pc = 0x8006E744u;
    // 8006E744: addi    r3, r4, 96
    ctx->gpr[3] = ctx->gpr[4] + (u32)(s32)(96);

label_8006E748:
    ctx->pc = 0x8006E748u;
    // 8006E748: lwz     r4, 68(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(68);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8006E74C:
    ctx->pc = 0x8006E74Cu;
    // 8006E74C: bl      0x80242328
    {
            ctx->lr = 0x8006E750u;
            ctx->pc = 0x80242328u;
            return;
    }

label_8006E750:
    ctx->pc = 0x8006E750u;
    ctx->downcount -= 11;
    // 8006E750: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8006E754:
    ctx->pc = 0x8006E754u;
    // 8006E754: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006E758:
    ctx->pc = 0x8006E758u;
    // 8006E758: li      r3, 64
    ctx->gpr[3] = (u32)(s32)(64);

label_8006E75C:
    ctx->pc = 0x8006E75Cu;
    // 8006E75C: li      r4, 64
    ctx->gpr[4] = (u32)(s32)(64);

label_8006E760:
    ctx->pc = 0x8006E760u;
    // 8006E760: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_8006E764:
    ctx->pc = 0x8006E764u;
    // 8006E764: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8006E768:
    ctx->pc = 0x8006E768u;
    // 8006E768: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8006E76C:
    ctx->pc = 0x8006E76Cu;
    // 8006E76C: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8006E770:
    ctx->pc = 0x8006E770u;
    // 8006E770: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_8006E774:
    ctx->pc = 0x8006E774u;
    // 8006E774: li      r10, 1
    ctx->gpr[10] = (u32)(s32)(1);

label_8006E778:
    ctx->pc = 0x8006E778u;
    // 8006E778: bl      0x80054E7C
    {
            ctx->lr = 0x8006E77Cu;
            ctx->pc = 0x80054E7Cu;
            return;
    }

label_8006E77C:
    ctx->pc = 0x8006E77Cu;
    ctx->downcount -= 5;
    // 8006E77C: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8006E780:
    ctx->pc = 0x8006E780u;
    // 8006E780: stw     r4, -25040(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25040);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8006E784:
    ctx->pc = 0x8006E784u;
    // 8006E784: addi    r3, r4, 96
    ctx->gpr[3] = ctx->gpr[4] + (u32)(s32)(96);

label_8006E788:
    ctx->pc = 0x8006E788u;
    // 8006E788: lwz     r4, 68(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(68);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8006E78C:
    ctx->pc = 0x8006E78Cu;
    // 8006E78C: bl      0x802422F8
    {
            ctx->lr = 0x8006E790u;
            ctx->pc = 0x802422F8u;
            return;
    }

label_8006E790:
    ctx->pc = 0x8006E790u;
    ctx->downcount -= 2;
    // 8006E790: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8006E794:
    ctx->pc = 0x8006E794u;
    // 8006E794: bl      0x8006A09C
    {
            ctx->lr = 0x8006E798u;
            ctx->pc = 0x8006A09Cu;
            return;
    }

label_8006E798:
    ctx->pc = 0x8006E798u;
    ctx->downcount -= 11;
    // 8006E798: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8006E79C:
    ctx->pc = 0x8006E79Cu;
    // 8006E79C: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006E7A0:
    ctx->pc = 0x8006E7A0u;
    // 8006E7A0: li      r3, 32
    ctx->gpr[3] = (u32)(s32)(32);

label_8006E7A4:
    ctx->pc = 0x8006E7A4u;
    // 8006E7A4: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_8006E7A8:
    ctx->pc = 0x8006E7A8u;
    // 8006E7A8: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_8006E7AC:
    ctx->pc = 0x8006E7ACu;
    // 8006E7AC: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8006E7B0:
    ctx->pc = 0x8006E7B0u;
    // 8006E7B0: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8006E7B4:
    ctx->pc = 0x8006E7B4u;
    // 8006E7B4: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8006E7B8:
    ctx->pc = 0x8006E7B8u;
    // 8006E7B8: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_8006E7BC:
    ctx->pc = 0x8006E7BCu;
    // 8006E7BC: li      r10, 1
    ctx->gpr[10] = (u32)(s32)(1);

label_8006E7C0:
    ctx->pc = 0x8006E7C0u;
    // 8006E7C0: bl      0x80054E7C
    {
            ctx->lr = 0x8006E7C4u;
            ctx->pc = 0x80054E7Cu;
            return;
    }

label_8006E7C4:
    ctx->pc = 0x8006E7C4u;
    ctx->downcount -= 9;
    // 8006E7C4: stw     r3, -25044(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25044);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8006E7C8:
    ctx->pc = 0x8006E7C8u;
    // 8006E7C8: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8006E7CC:
    ctx->pc = 0x8006E7CCu;
    // 8006E7CC: lfs     f1, -30504(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006E7CCu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30504);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8006E7D0:
    ctx->pc = 0x8006E7D0u;
    // 8006E7D0: lfs     f0, -30672(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006E7D0u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30672);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8006E7D4:
    ctx->pc = 0x8006E7D4u;
    // 8006E7D4: lfs     f7, -30704(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006E7D4u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30704);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[7] = value;
        ctx->ps1[7] = value;
    }

label_8006E7D8:
    ctx->pc = 0x8006E7D8u;
    // 8006E7D8: lfs     f6, -30668(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006E7D8u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30668);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[6] = value;
        ctx->ps1[6] = value;
    }

label_8006E7DC:
    ctx->pc = 0x8006E7DCu;
    // 8006E7DC: lfd     f3, -30512(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006E7DCu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30512);
        ctx->fpr[3] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006E7E0:
    ctx->pc = 0x8006E7E0u;
    // 8006E7E0: lis     r6, 17200
    ctx->gpr[6] = ((u32)(s32)(17200) << 16);

label_8006E7E4:
    ctx->pc = 0x8006E7E4u;
    // 8006E7E4: lfs     f2, -30476(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006E7E4u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30476);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8006E7E8:
    ctx->downcount -= 16;
    // 8006E7E8: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8006E7EC:
    // 8006E7EC: srawi r0, r7, 3
    {
        u32 sh = 3u;
        u32 value = ctx->gpr[7];
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

label_8006E7F0:
    // 8006E7F0: rlwinm r3, r0, 5, 0, 26
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 5u) & 0xFFFFFFE0u;
    }

label_8006E7F4:
    // 8006E7F4: rlwinm r4, r7, 0, 29, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0x00000007u;
    }

label_8006E7F8:
    // 8006E7F8: xoris   r0, r7, 0x8000
    ctx->gpr[0] = ctx->gpr[7] ^ (0x8000u << 16);

label_8006E7FC:
    ctx->pc = 0x8006E7FCu;
    // 8006E7FC: stw     r0, 92(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006E800:
    ctx->pc = 0x8006E800u;
    // 8006E800: stw     r6, 88(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8006E804:
    ctx->pc = 0x8006E804u;
    // 8006E804: lfd     f4, 88(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006E804u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        ctx->fpr[4] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006E808:
    ctx->pc = 0x8006E808u;
    // 8006E808: fsubs   f4, f4, f3
    if (!ppc_fp_available_inline(ctx, 0x8006E808u)) return;
    ppc_fsubs(ctx, 4, 4, 3);

label_8006E80C:
    ctx->pc = 0x8006E80Cu;
    // 8006E80C: fsubs   f4, f4, f2
    if (!ppc_fp_available_inline(ctx, 0x8006E80Cu)) return;
    ppc_fsubs(ctx, 4, 4, 2);

label_8006E810:
    // 8006E810: add   r4, r4, r3
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_8006E814:
    ctx->pc = 0x8006E814u;
    // 8006E814: fmuls   f4, f4, f1
    if (!ppc_fp_available_inline(ctx, 0x8006E814u)) return;
    ppc_fmuls(ctx, 4, 4, 1);

label_8006E818:
    ctx->pc = 0x8006E818u;
    // 8006E818: fabs    f4, f4
    if (!ppc_fp_available_inline(ctx, 0x8006E818u)) return;
    ctx->fpr[4] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[4]) & 0x7FFFFFFFFFFFFFFFull);

label_8006E81C:
    // 8006E81C: li      r0, 4
    ctx->gpr[0] = (u32)(s32)(4);

label_8006E820:
    ctx->pc = 0x8006E820u;
    // 8006E820: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8006E824:
    ctx->pc = 0x8006E824u;
    ctx->downcount -= 10;
    // 8006E824: lwz     r5, -25044(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25044);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8006E828:
    // 8006E828: rlwinm r0, r8, 0, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[8], 0u) & 0x00000003u;
    }

label_8006E82C:
    // 8006E82C: rlwinm r0, r0, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 3u) & 0xFFFFFFF8u;
    }

label_8006E830:
    // 8006E830: add   r3, r4, r0
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8006E834:
    // 8006E834: srawi r0, r8, 2
    {
        u32 sh = 2u;
        u32 value = ctx->gpr[8];
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

label_8006E838:
    // 8006E838: rlwinm r0, r0, 7, 0, 24
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 7u) & 0xFFFFFF80u;
    }

label_8006E83C:
    // 8006E83C: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8006E840:
    // 8006E840: addi    r3, r3, 96
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(96);

label_8006E844:
    ctx->pc = 0x8006E844u;
    // 8006E844: fcmpo   cr0, f4, f0
    if (!ppc_fp_available_inline(ctx, 0x8006E844u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[4], ctx->fpr[0], true);

label_8006E848:
    // 8006E848: bc    4, 1, 0x8006E89C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8006E89C;
        }
    }

label_8006E84C:
    ctx->pc = 0x8006E84Cu;
    ctx->downcount -= 20;
    // 8006E84C: frsqrte    f5, f4
    if (!ppc_fp_available_inline(ctx, 0x8006E84Cu)) return;
    { f64 result; if (ppc_frsqrte(ctx, ctx->fpr[4], &result)) ctx->fpr[5] = result; }

label_8006E850:
    ctx->pc = 0x8006E850u;
    // 8006E850: lfd     f10, -30624(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006E850u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30624);
        ctx->fpr[10] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006E854:
    ctx->pc = 0x8006E854u;
    // 8006E854: fmul   f8, f10, f5
    if (!ppc_fp_available_inline(ctx, 0x8006E854u)) return;
    ppc_fmul(ctx, 8, 10, 5);

label_8006E858:
    ctx->pc = 0x8006E858u;
    // 8006E858: fmul   f5, f5, f5
    if (!ppc_fp_available_inline(ctx, 0x8006E858u)) return;
    ppc_fmul(ctx, 5, 5, 5);

label_8006E85C:
    ctx->pc = 0x8006E85Cu;
    // 8006E85C: lfd     f9, -30616(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006E85Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30616);
        ctx->fpr[9] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006E860:
    ctx->pc = 0x8006E860u;
    // 8006E860: fnmsub f5, f4, f5, f9
    if (!ppc_fp_available_inline(ctx, 0x8006E860u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[4], ctx->fpr[5], ctx->fpr[9], false, true, true, &result))
            ctx->fpr[5] = result;
    }

label_8006E864:
    ctx->pc = 0x8006E864u;
    // 8006E864: fmul   f5, f8, f5
    if (!ppc_fp_available_inline(ctx, 0x8006E864u)) return;
    ppc_fmul(ctx, 5, 8, 5);

label_8006E868:
    ctx->pc = 0x8006E868u;
    // 8006E868: fmul   f8, f10, f5
    if (!ppc_fp_available_inline(ctx, 0x8006E868u)) return;
    ppc_fmul(ctx, 8, 10, 5);

label_8006E86C:
    ctx->pc = 0x8006E86Cu;
    // 8006E86C: fmul   f5, f5, f5
    if (!ppc_fp_available_inline(ctx, 0x8006E86Cu)) return;
    ppc_fmul(ctx, 5, 5, 5);

label_8006E870:
    ctx->pc = 0x8006E870u;
    // 8006E870: fnmsub f5, f4, f5, f9
    if (!ppc_fp_available_inline(ctx, 0x8006E870u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[4], ctx->fpr[5], ctx->fpr[9], false, true, true, &result))
            ctx->fpr[5] = result;
    }

label_8006E874:
    ctx->pc = 0x8006E874u;
    // 8006E874: fmul   f5, f8, f5
    if (!ppc_fp_available_inline(ctx, 0x8006E874u)) return;
    ppc_fmul(ctx, 5, 8, 5);

label_8006E878:
    ctx->pc = 0x8006E878u;
    // 8006E878: fmul   f8, f10, f5
    if (!ppc_fp_available_inline(ctx, 0x8006E878u)) return;
    ppc_fmul(ctx, 8, 10, 5);

label_8006E87C:
    ctx->pc = 0x8006E87Cu;
    // 8006E87C: fmul   f5, f5, f5
    if (!ppc_fp_available_inline(ctx, 0x8006E87Cu)) return;
    ppc_fmul(ctx, 5, 5, 5);

label_8006E880:
    ctx->pc = 0x8006E880u;
    // 8006E880: fnmsub f5, f4, f5, f9
    if (!ppc_fp_available_inline(ctx, 0x8006E880u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[4], ctx->fpr[5], ctx->fpr[9], false, true, true, &result))
            ctx->fpr[5] = result;
    }

label_8006E884:
    ctx->pc = 0x8006E884u;
    // 8006E884: fmul   f5, f8, f5
    if (!ppc_fp_available_inline(ctx, 0x8006E884u)) return;
    ppc_fmul(ctx, 5, 8, 5);

label_8006E888:
    ctx->pc = 0x8006E888u;
    // 8006E888: fmul   f5, f4, f5
    if (!ppc_fp_available_inline(ctx, 0x8006E888u)) return;
    ppc_fmul(ctx, 5, 4, 5);

label_8006E88C:
    ctx->pc = 0x8006E88Cu;
    // 8006E88C: frsp    f5, f5
    if (!ppc_fp_available_inline(ctx, 0x8006E88Cu)) return;
    ppc_frsp(ctx, 5, 5);

label_8006E890:
    ctx->pc = 0x8006E890u;
    // 8006E890: stfs     f5, 28(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006E890u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[5]));
    }

label_8006E894:
    ctx->pc = 0x8006E894u;
    // 8006E894: lfs     f11, 28(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006E894u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_8006E898:
    // 8006E898: b       0x8006E8A0
    {
            goto label_8006E8A0;
    }

label_8006E89C:
    ctx->pc = 0x8006E89Cu;
    ctx->downcount -= 1;
    // 8006E89C: fmr    f11, f4
    if (!ppc_fp_available_inline(ctx, 0x8006E89Cu)) return;
    ctx->fpr[11] = ctx->fpr[4];

label_8006E8A0:
    ctx->pc = 0x8006E8A0u;
    ctx->downcount -= 2;
    // 8006E8A0: fcmpo   cr0, f11, f0
    if (!ppc_fp_available_inline(ctx, 0x8006E8A0u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[11], ctx->fpr[0], true);

label_8006E8A4:
    // 8006E8A4: bc    4, 1, 0x8006E8F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8006E8F4;
        }
    }

label_8006E8A8:
    ctx->pc = 0x8006E8A8u;
    ctx->downcount -= 19;
    // 8006E8A8: frsqrte    f5, f11
    if (!ppc_fp_available_inline(ctx, 0x8006E8A8u)) return;
    { f64 result; if (ppc_frsqrte(ctx, ctx->fpr[11], &result)) ctx->fpr[5] = result; }

label_8006E8AC:
    ctx->pc = 0x8006E8ACu;
    // 8006E8AC: lfd     f10, -30624(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006E8ACu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30624);
        ctx->fpr[10] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006E8B0:
    ctx->pc = 0x8006E8B0u;
    // 8006E8B0: fmul   f8, f10, f5
    if (!ppc_fp_available_inline(ctx, 0x8006E8B0u)) return;
    ppc_fmul(ctx, 8, 10, 5);

label_8006E8B4:
    ctx->pc = 0x8006E8B4u;
    // 8006E8B4: fmul   f5, f5, f5
    if (!ppc_fp_available_inline(ctx, 0x8006E8B4u)) return;
    ppc_fmul(ctx, 5, 5, 5);

label_8006E8B8:
    ctx->pc = 0x8006E8B8u;
    // 8006E8B8: lfd     f9, -30616(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006E8B8u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30616);
        ctx->fpr[9] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006E8BC:
    ctx->pc = 0x8006E8BCu;
    // 8006E8BC: fnmsub f5, f11, f5, f9
    if (!ppc_fp_available_inline(ctx, 0x8006E8BCu)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[11], ctx->fpr[5], ctx->fpr[9], false, true, true, &result))
            ctx->fpr[5] = result;
    }

label_8006E8C0:
    ctx->pc = 0x8006E8C0u;
    // 8006E8C0: fmul   f5, f8, f5
    if (!ppc_fp_available_inline(ctx, 0x8006E8C0u)) return;
    ppc_fmul(ctx, 5, 8, 5);

label_8006E8C4:
    ctx->pc = 0x8006E8C4u;
    // 8006E8C4: fmul   f8, f10, f5
    if (!ppc_fp_available_inline(ctx, 0x8006E8C4u)) return;
    ppc_fmul(ctx, 8, 10, 5);

label_8006E8C8:
    ctx->pc = 0x8006E8C8u;
    // 8006E8C8: fmul   f5, f5, f5
    if (!ppc_fp_available_inline(ctx, 0x8006E8C8u)) return;
    ppc_fmul(ctx, 5, 5, 5);

label_8006E8CC:
    ctx->pc = 0x8006E8CCu;
    // 8006E8CC: fnmsub f5, f11, f5, f9
    if (!ppc_fp_available_inline(ctx, 0x8006E8CCu)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[11], ctx->fpr[5], ctx->fpr[9], false, true, true, &result))
            ctx->fpr[5] = result;
    }

label_8006E8D0:
    ctx->pc = 0x8006E8D0u;
    // 8006E8D0: fmul   f5, f8, f5
    if (!ppc_fp_available_inline(ctx, 0x8006E8D0u)) return;
    ppc_fmul(ctx, 5, 8, 5);

label_8006E8D4:
    ctx->pc = 0x8006E8D4u;
    // 8006E8D4: fmul   f8, f10, f5
    if (!ppc_fp_available_inline(ctx, 0x8006E8D4u)) return;
    ppc_fmul(ctx, 8, 10, 5);

label_8006E8D8:
    ctx->pc = 0x8006E8D8u;
    // 8006E8D8: fmul   f5, f5, f5
    if (!ppc_fp_available_inline(ctx, 0x8006E8D8u)) return;
    ppc_fmul(ctx, 5, 5, 5);

label_8006E8DC:
    ctx->pc = 0x8006E8DCu;
    // 8006E8DC: fnmsub f5, f11, f5, f9
    if (!ppc_fp_available_inline(ctx, 0x8006E8DCu)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[11], ctx->fpr[5], ctx->fpr[9], false, true, true, &result))
            ctx->fpr[5] = result;
    }

label_8006E8E0:
    ctx->pc = 0x8006E8E0u;
    // 8006E8E0: fmul   f5, f8, f5
    if (!ppc_fp_available_inline(ctx, 0x8006E8E0u)) return;
    ppc_fmul(ctx, 5, 8, 5);

label_8006E8E4:
    ctx->pc = 0x8006E8E4u;
    // 8006E8E4: fmul   f5, f11, f5
    if (!ppc_fp_available_inline(ctx, 0x8006E8E4u)) return;
    ppc_fmul(ctx, 5, 11, 5);

label_8006E8E8:
    ctx->pc = 0x8006E8E8u;
    // 8006E8E8: frsp    f5, f5
    if (!ppc_fp_available_inline(ctx, 0x8006E8E8u)) return;
    ppc_frsp(ctx, 5, 5);

label_8006E8EC:
    ctx->pc = 0x8006E8ECu;
    // 8006E8EC: stfs     f5, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006E8ECu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[5]));
    }

label_8006E8F0:
    ctx->pc = 0x8006E8F0u;
    // 8006E8F0: lfs     f11, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006E8F0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_8006E8F4:
    ctx->pc = 0x8006E8F4u;
    ctx->downcount -= 8;
    // 8006E8F4: fsubs   f5, f6, f11
    if (!ppc_fp_available_inline(ctx, 0x8006E8F4u)) return;
    ppc_fsubs(ctx, 5, 6, 11);

label_8006E8F8:
    ctx->pc = 0x8006E8F8u;
    // 8006E8F8: fmuls   f5, f7, f5
    if (!ppc_fp_available_inline(ctx, 0x8006E8F8u)) return;
    ppc_fmuls(ctx, 5, 7, 5);

label_8006E8FC:
    ctx->pc = 0x8006E8FCu;
    // 8006E8FC: fctiwz    f5, f5
    if (!ppc_fp_available_inline(ctx, 0x8006E8FCu)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[5], true, &result)) ctx->fpr[5] = dolrecomp_f64_from_bits(result); }

label_8006E900:
    ctx->pc = 0x8006E900u;
    // 8006E900: stfd     f5, 88(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006E900u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[5]));
    }

label_8006E904:
    ctx->pc = 0x8006E904u;
    // 8006E904: lwz     r0, 92(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8006E908:
    ctx->pc = 0x8006E908u;
    // 8006E908: stbx    r0, r5, r3
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[3];
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006E90C:
    // 8006E90C: addi    r8, r8, 1
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(1);

label_8006E910:
    // 8006E910: bc    16, 0, 0x8006E824
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8006E824u;
                return;
            }
            goto label_8006E824;
        }
    }

label_8006E914:
    ctx->downcount -= 3;
    // 8006E914: addi    r7, r7, 1
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(1);

label_8006E918:
    // 8006E918: cmpwi   r7, 32
    {
        s32 val_a = (s32)(ctx->gpr[7]);
        s32 val_b = (s32)(32);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8006E91C:
    // 8006E91C: bc    12, 0, 0x8006E7E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8006E7E8u;
                return;
            }
            goto label_8006E7E8;
        }
    }

label_8006E920:
    ctx->pc = 0x8006E920u;
    ctx->downcount -= 4;
    // 8006E920: lwz     r4, -25044(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25044);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8006E924:
    ctx->pc = 0x8006E924u;
    // 8006E924: addi    r3, r4, 96
    ctx->gpr[3] = ctx->gpr[4] + (u32)(s32)(96);

label_8006E928:
    ctx->pc = 0x8006E928u;
    // 8006E928: lwz     r4, 68(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(68);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8006E92C:
    ctx->pc = 0x8006E92Cu;
    // 8006E92C: bl      0x80242328
    {
            ctx->lr = 0x8006E930u;
            ctx->pc = 0x80242328u;
            return;
    }

label_8006E930:
    ctx->pc = 0x8006E930u;
    ctx->downcount -= 11;
    // 8006E930: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8006E934:
    ctx->pc = 0x8006E934u;
    // 8006E934: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006E938:
    ctx->pc = 0x8006E938u;
    // 8006E938: li      r3, 128
    ctx->gpr[3] = (u32)(s32)(128);

label_8006E93C:
    ctx->pc = 0x8006E93Cu;
    // 8006E93C: li      r4, 128
    ctx->gpr[4] = (u32)(s32)(128);

label_8006E940:
    ctx->pc = 0x8006E940u;
    // 8006E940: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_8006E944:
    ctx->pc = 0x8006E944u;
    // 8006E944: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8006E948:
    ctx->pc = 0x8006E948u;
    // 8006E948: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8006E94C:
    ctx->pc = 0x8006E94Cu;
    // 8006E94C: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_8006E950:
    ctx->pc = 0x8006E950u;
    // 8006E950: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_8006E954:
    ctx->pc = 0x8006E954u;
    // 8006E954: li      r10, 1
    ctx->gpr[10] = (u32)(s32)(1);

label_8006E958:
    ctx->pc = 0x8006E958u;
    // 8006E958: bl      0x80054E7C
    {
            ctx->lr = 0x8006E95Cu;
            ctx->pc = 0x80054E7Cu;
            return;
    }

label_8006E95C:
    ctx->pc = 0x8006E95Cu;
    ctx->downcount -= 9;
    // 8006E95C: stw     r3, -25048(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25048);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8006E960:
    ctx->pc = 0x8006E960u;
    // 8006E960: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8006E964:
    ctx->pc = 0x8006E964u;
    // 8006E964: lfd     f4, -30512(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006E964u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30512);
        ctx->fpr[4] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006E968:
    ctx->pc = 0x8006E968u;
    // 8006E968: lis     r3, 17200
    ctx->gpr[3] = ((u32)(s32)(17200) << 16);

label_8006E96C:
    ctx->pc = 0x8006E96Cu;
    // 8006E96C: lfs     f3, -30684(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006E96Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30684);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8006E970:
    ctx->pc = 0x8006E970u;
    // 8006E970: lfs     f2, -30488(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006E970u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30488);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8006E974:
    ctx->pc = 0x8006E974u;
    // 8006E974: lfs     f1, -30672(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006E974u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30672);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8006E978:
    ctx->pc = 0x8006E978u;
    // 8006E978: lfs     f0, -30652(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006E978u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30652);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8006E97C:
    ctx->pc = 0x8006E97Cu;
    // 8006E97C: lfs     f7, -30476(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006E97Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30476);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[7] = value;
        ctx->ps1[7] = value;
    }

label_8006E980:
    ctx->downcount -= 16;
    // 8006E980: xoris   r0, r7, 0x8000
    ctx->gpr[0] = ctx->gpr[7] ^ (0x8000u << 16);

label_8006E984:
    ctx->pc = 0x8006E984u;
    // 8006E984: stw     r0, 92(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006E988:
    ctx->pc = 0x8006E988u;
    // 8006E988: stw     r3, 88(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8006E98C:
    ctx->pc = 0x8006E98Cu;
    // 8006E98C: lfd     f5, 88(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006E98Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        ctx->fpr[5] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006E990:
    ctx->pc = 0x8006E990u;
    // 8006E990: fsubs   f5, f5, f4
    if (!ppc_fp_available_inline(ctx, 0x8006E990u)) return;
    ppc_fsubs(ctx, 5, 5, 4);

label_8006E994:
    ctx->pc = 0x8006E994u;
    // 8006E994: fsubs   f5, f5, f3
    if (!ppc_fp_available_inline(ctx, 0x8006E994u)) return;
    ppc_fsubs(ctx, 5, 5, 3);

label_8006E998:
    ctx->pc = 0x8006E998u;
    // 8006E998: fmuls   f5, f5, f2
    if (!ppc_fp_available_inline(ctx, 0x8006E998u)) return;
    ppc_fmuls(ctx, 5, 5, 2);

label_8006E99C:
    // 8006E99C: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8006E9A0:
    // 8006E9A0: srawi r0, r7, 3
    {
        u32 sh = 3u;
        u32 value = ctx->gpr[7];
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

label_8006E9A4:
    // 8006E9A4: rlwinm r0, r0, 5, 0, 26
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 5u) & 0xFFFFFFE0u;
    }

label_8006E9A8:
    // 8006E9A8: rlwinm r4, r7, 0, 29, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0x00000007u;
    }

label_8006E9AC:
    ctx->pc = 0x8006E9ACu;
    // 8006E9AC: fmuls   f5, f5, f5
    if (!ppc_fp_available_inline(ctx, 0x8006E9ACu)) return;
    ppc_fmuls(ctx, 5, 5, 5);

label_8006E9B0:
    // 8006E9B0: add   r5, r4, r0
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[5] = res;
    }

label_8006E9B4:
    // 8006E9B4: li      r0, 128
    ctx->gpr[0] = (u32)(s32)(128);

label_8006E9B8:
    ctx->pc = 0x8006E9B8u;
    // 8006E9B8: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8006E9BC:
    ctx->pc = 0x8006E9BCu;
    ctx->downcount -= 18;
    // 8006E9BC: lwz     r6, -25048(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25048);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8006E9C0:
    // 8006E9C0: rlwinm r0, r8, 0, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[8], 0u) & 0x00000003u;
    }

label_8006E9C4:
    // 8006E9C4: rlwinm r0, r0, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 3u) & 0xFFFFFFF8u;
    }

label_8006E9C8:
    // 8006E9C8: add   r4, r5, r0
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_8006E9CC:
    // 8006E9CC: srawi r0, r8, 2
    {
        u32 sh = 2u;
        u32 value = ctx->gpr[8];
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

label_8006E9D0:
    // 8006E9D0: rlwinm r0, r0, 9, 0, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 9u) & 0xFFFFFE00u;
    }

label_8006E9D4:
    // 8006E9D4: add   r4, r4, r0
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_8006E9D8:
    // 8006E9D8: addi    r4, r4, 96
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(96);

label_8006E9DC:
    // 8006E9DC: xoris   r0, r8, 0x8000
    ctx->gpr[0] = ctx->gpr[8] ^ (0x8000u << 16);

label_8006E9E0:
    ctx->pc = 0x8006E9E0u;
    // 8006E9E0: stw     r0, 92(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006E9E4:
    ctx->pc = 0x8006E9E4u;
    // 8006E9E4: stw     r3, 88(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8006E9E8:
    ctx->pc = 0x8006E9E8u;
    // 8006E9E8: lfd     f6, 88(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006E9E8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        ctx->fpr[6] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006E9EC:
    ctx->pc = 0x8006E9ECu;
    // 8006E9EC: fsubs   f6, f6, f4
    if (!ppc_fp_available_inline(ctx, 0x8006E9ECu)) return;
    ppc_fsubs(ctx, 6, 6, 4);

label_8006E9F0:
    ctx->pc = 0x8006E9F0u;
    // 8006E9F0: fsubs   f6, f6, f3
    if (!ppc_fp_available_inline(ctx, 0x8006E9F0u)) return;
    ppc_fsubs(ctx, 6, 6, 3);

label_8006E9F4:
    ctx->pc = 0x8006E9F4u;
    // 8006E9F4: fmuls   f6, f6, f2
    if (!ppc_fp_available_inline(ctx, 0x8006E9F4u)) return;
    ppc_fmuls(ctx, 6, 6, 2);

label_8006E9F8:
    ctx->pc = 0x8006E9F8u;
    // 8006E9F8: fmadds f11, f6, f6, f5
    if (!ppc_fp_available_inline(ctx, 0x8006E9F8u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[6], ctx->fpr[6], ctx->fpr[5], true, false, false, &result))
            ctx->fpr[11] = ctx->ps1[11] = result;
    }

label_8006E9FC:
    ctx->pc = 0x8006E9FCu;
    // 8006E9FC: fcmpo   cr0, f11, f1
    if (!ppc_fp_available_inline(ctx, 0x8006E9FCu)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[11], ctx->fpr[1], true);

label_8006EA00:
    // 8006EA00: bc    4, 1, 0x8006EA50
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8006EA50;
        }
    }

label_8006EA04:
    ctx->pc = 0x8006EA04u;
    ctx->downcount -= 19;
    // 8006EA04: frsqrte    f6, f11
    if (!ppc_fp_available_inline(ctx, 0x8006EA04u)) return;
    { f64 result; if (ppc_frsqrte(ctx, ctx->fpr[11], &result)) ctx->fpr[6] = result; }

label_8006EA08:
    ctx->pc = 0x8006EA08u;
    // 8006EA08: lfd     f10, -30624(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006EA08u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30624);
        ctx->fpr[10] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006EA0C:
    ctx->pc = 0x8006EA0Cu;
    // 8006EA0C: fmul   f8, f10, f6
    if (!ppc_fp_available_inline(ctx, 0x8006EA0Cu)) return;
    ppc_fmul(ctx, 8, 10, 6);

label_8006EA10:
    ctx->pc = 0x8006EA10u;
    // 8006EA10: fmul   f6, f6, f6
    if (!ppc_fp_available_inline(ctx, 0x8006EA10u)) return;
    ppc_fmul(ctx, 6, 6, 6);

label_8006EA14:
    ctx->pc = 0x8006EA14u;
    // 8006EA14: lfd     f9, -30616(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006EA14u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30616);
        ctx->fpr[9] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006EA18:
    ctx->pc = 0x8006EA18u;
    // 8006EA18: fnmsub f6, f11, f6, f9
    if (!ppc_fp_available_inline(ctx, 0x8006EA18u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[11], ctx->fpr[6], ctx->fpr[9], false, true, true, &result))
            ctx->fpr[6] = result;
    }

label_8006EA1C:
    ctx->pc = 0x8006EA1Cu;
    // 8006EA1C: fmul   f6, f8, f6
    if (!ppc_fp_available_inline(ctx, 0x8006EA1Cu)) return;
    ppc_fmul(ctx, 6, 8, 6);

label_8006EA20:
    ctx->pc = 0x8006EA20u;
    // 8006EA20: fmul   f8, f10, f6
    if (!ppc_fp_available_inline(ctx, 0x8006EA20u)) return;
    ppc_fmul(ctx, 8, 10, 6);

label_8006EA24:
    ctx->pc = 0x8006EA24u;
    // 8006EA24: fmul   f6, f6, f6
    if (!ppc_fp_available_inline(ctx, 0x8006EA24u)) return;
    ppc_fmul(ctx, 6, 6, 6);

label_8006EA28:
    ctx->pc = 0x8006EA28u;
    // 8006EA28: fnmsub f6, f11, f6, f9
    if (!ppc_fp_available_inline(ctx, 0x8006EA28u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[11], ctx->fpr[6], ctx->fpr[9], false, true, true, &result))
            ctx->fpr[6] = result;
    }

label_8006EA2C:
    ctx->pc = 0x8006EA2Cu;
    // 8006EA2C: fmul   f6, f8, f6
    if (!ppc_fp_available_inline(ctx, 0x8006EA2Cu)) return;
    ppc_fmul(ctx, 6, 8, 6);

label_8006EA30:
    ctx->pc = 0x8006EA30u;
    // 8006EA30: fmul   f8, f10, f6
    if (!ppc_fp_available_inline(ctx, 0x8006EA30u)) return;
    ppc_fmul(ctx, 8, 10, 6);

label_8006EA34:
    ctx->pc = 0x8006EA34u;
    // 8006EA34: fmul   f6, f6, f6
    if (!ppc_fp_available_inline(ctx, 0x8006EA34u)) return;
    ppc_fmul(ctx, 6, 6, 6);

label_8006EA38:
    ctx->pc = 0x8006EA38u;
    // 8006EA38: fnmsub f6, f11, f6, f9
    if (!ppc_fp_available_inline(ctx, 0x8006EA38u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[11], ctx->fpr[6], ctx->fpr[9], false, true, true, &result))
            ctx->fpr[6] = result;
    }

label_8006EA3C:
    ctx->pc = 0x8006EA3Cu;
    // 8006EA3C: fmul   f6, f8, f6
    if (!ppc_fp_available_inline(ctx, 0x8006EA3Cu)) return;
    ppc_fmul(ctx, 6, 8, 6);

label_8006EA40:
    ctx->pc = 0x8006EA40u;
    // 8006EA40: fmul   f6, f11, f6
    if (!ppc_fp_available_inline(ctx, 0x8006EA40u)) return;
    ppc_fmul(ctx, 6, 11, 6);

label_8006EA44:
    ctx->pc = 0x8006EA44u;
    // 8006EA44: frsp    f6, f6
    if (!ppc_fp_available_inline(ctx, 0x8006EA44u)) return;
    ppc_frsp(ctx, 6, 6);

label_8006EA48:
    ctx->pc = 0x8006EA48u;
    // 8006EA48: stfs     f6, 20(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006EA48u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[6]));
    }

label_8006EA4C:
    ctx->pc = 0x8006EA4Cu;
    // 8006EA4C: lfs     f11, 20(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006EA4Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_8006EA50:
    ctx->pc = 0x8006EA50u;
    ctx->downcount -= 2;
    // 8006EA50: fcmpo   cr0, f11, f0
    if (!ppc_fp_available_inline(ctx, 0x8006EA50u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[11], ctx->fpr[0], true);

label_8006EA54:
    // 8006EA54: bc    12, 0, 0x8006EA64
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8006EA64;
        }
    }

label_8006EA58:
    ctx->pc = 0x8006EA58u;
    ctx->downcount -= 3;
    // 8006EA58: lfs     f6, -30444(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006EA58u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30444);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[6] = value;
        ctx->ps1[6] = value;
    }

label_8006EA5C:
    ctx->pc = 0x8006EA5Cu;
    // 8006EA5C: fcmpo   cr0, f11, f6
    if (!ppc_fp_available_inline(ctx, 0x8006EA5Cu)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[11], ctx->fpr[6], true);

label_8006EA60:
    // 8006EA60: bc    4, 1, 0x8006EA6C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8006EA6C;
        }
    }

label_8006EA64:
    ctx->pc = 0x8006EA64u;
    ctx->downcount -= 2;
    // 8006EA64: lfs     f11, -30672(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006EA64u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30672);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_8006EA68:
    // 8006EA68: b       0x8006EAF8
    {
            goto label_8006EAF8;
    }

label_8006EA6C:
    ctx->pc = 0x8006EA6Cu;
    ctx->downcount -= 6;
    // 8006EA6C: lfs     f9, -30660(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006EA6Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30660);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[9] = value;
        ctx->ps1[9] = value;
    }

label_8006EA70:
    ctx->pc = 0x8006EA70u;
    // 8006EA70: fsubs   f6, f11, f0
    if (!ppc_fp_available_inline(ctx, 0x8006EA70u)) return;
    ppc_fsubs(ctx, 6, 11, 0);

label_8006EA74:
    ctx->pc = 0x8006EA74u;
    // 8006EA74: fmuls   f8, f9, f6
    if (!ppc_fp_available_inline(ctx, 0x8006EA74u)) return;
    ppc_fmuls(ctx, 8, 9, 6);

label_8006EA78:
    ctx->pc = 0x8006EA78u;
    // 8006EA78: lfs     f6, -30656(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006EA78u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30656);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[6] = value;
        ctx->ps1[6] = value;
    }

label_8006EA7C:
    ctx->pc = 0x8006EA7Cu;
    // 8006EA7C: fcmpo   cr0, f8, f6
    if (!ppc_fp_available_inline(ctx, 0x8006EA7Cu)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[8], ctx->fpr[6], true);

label_8006EA80:
    // 8006EA80: bc    4, 1, 0x8006EA94
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8006EA94;
        }
    }

label_8006EA84:
    ctx->pc = 0x8006EA84u;
    ctx->downcount -= 4;
    // 8006EA84: fsubs   f8, f8, f6
    if (!ppc_fp_available_inline(ctx, 0x8006EA84u)) return;
    ppc_fsubs(ctx, 8, 8, 6);

label_8006EA88:
    ctx->pc = 0x8006EA88u;
    // 8006EA88: lfs     f6, -30668(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006EA88u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30668);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[6] = value;
        ctx->ps1[6] = value;
    }

label_8006EA8C:
    ctx->pc = 0x8006EA8Cu;
    // 8006EA8C: fnmsubs f11, f9, f8, f6
    if (!ppc_fp_available_inline(ctx, 0x8006EA8Cu)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[9], ctx->fpr[8], ctx->fpr[6], true, true, true, &result))
            ctx->fpr[11] = ctx->ps1[11] = result;
    }

label_8006EA90:
    // 8006EA90: b       0x8006EAA0
    {
            goto label_8006EAA0;
    }

label_8006EA94:
    ctx->pc = 0x8006EA94u;
    ctx->downcount -= 3;
    // 8006EA94: fsubs   f8, f6, f8
    if (!ppc_fp_available_inline(ctx, 0x8006EA94u)) return;
    ppc_fsubs(ctx, 8, 6, 8);

label_8006EA98:
    ctx->pc = 0x8006EA98u;
    // 8006EA98: lfs     f6, -30668(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006EA98u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30668);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[6] = value;
        ctx->ps1[6] = value;
    }

label_8006EA9C:
    ctx->pc = 0x8006EA9Cu;
    // 8006EA9C: fnmsubs f11, f9, f8, f6
    if (!ppc_fp_available_inline(ctx, 0x8006EA9Cu)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[9], ctx->fpr[8], ctx->fpr[6], true, true, true, &result))
            ctx->fpr[11] = ctx->ps1[11] = result;
    }

label_8006EAA0:
    ctx->pc = 0x8006EAA0u;
    ctx->downcount -= 3;
    // 8006EAA0: lfs     f6, -30672(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006EAA0u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30672);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[6] = value;
        ctx->ps1[6] = value;
    }

label_8006EAA4:
    ctx->pc = 0x8006EAA4u;
    // 8006EAA4: fcmpo   cr0, f11, f6
    if (!ppc_fp_available_inline(ctx, 0x8006EAA4u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[11], ctx->fpr[6], true);

label_8006EAA8:
    // 8006EAA8: bc    4, 1, 0x8006EAF8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8006EAF8;
        }
    }

label_8006EAAC:
    ctx->pc = 0x8006EAACu;
    ctx->downcount -= 19;
    // 8006EAAC: frsqrte    f6, f11
    if (!ppc_fp_available_inline(ctx, 0x8006EAACu)) return;
    { f64 result; if (ppc_frsqrte(ctx, ctx->fpr[11], &result)) ctx->fpr[6] = result; }

label_8006EAB0:
    ctx->pc = 0x8006EAB0u;
    // 8006EAB0: lfd     f10, -30624(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006EAB0u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30624);
        ctx->fpr[10] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006EAB4:
    ctx->pc = 0x8006EAB4u;
    // 8006EAB4: fmul   f8, f10, f6
    if (!ppc_fp_available_inline(ctx, 0x8006EAB4u)) return;
    ppc_fmul(ctx, 8, 10, 6);

label_8006EAB8:
    ctx->pc = 0x8006EAB8u;
    // 8006EAB8: fmul   f6, f6, f6
    if (!ppc_fp_available_inline(ctx, 0x8006EAB8u)) return;
    ppc_fmul(ctx, 6, 6, 6);

label_8006EABC:
    ctx->pc = 0x8006EABCu;
    // 8006EABC: lfd     f9, -30616(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006EABCu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30616);
        ctx->fpr[9] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006EAC0:
    ctx->pc = 0x8006EAC0u;
    // 8006EAC0: fnmsub f6, f11, f6, f9
    if (!ppc_fp_available_inline(ctx, 0x8006EAC0u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[11], ctx->fpr[6], ctx->fpr[9], false, true, true, &result))
            ctx->fpr[6] = result;
    }

label_8006EAC4:
    ctx->pc = 0x8006EAC4u;
    // 8006EAC4: fmul   f6, f8, f6
    if (!ppc_fp_available_inline(ctx, 0x8006EAC4u)) return;
    ppc_fmul(ctx, 6, 8, 6);

label_8006EAC8:
    ctx->pc = 0x8006EAC8u;
    // 8006EAC8: fmul   f8, f10, f6
    if (!ppc_fp_available_inline(ctx, 0x8006EAC8u)) return;
    ppc_fmul(ctx, 8, 10, 6);

label_8006EACC:
    ctx->pc = 0x8006EACCu;
    // 8006EACC: fmul   f6, f6, f6
    if (!ppc_fp_available_inline(ctx, 0x8006EACCu)) return;
    ppc_fmul(ctx, 6, 6, 6);

label_8006EAD0:
    ctx->pc = 0x8006EAD0u;
    // 8006EAD0: fnmsub f6, f11, f6, f9
    if (!ppc_fp_available_inline(ctx, 0x8006EAD0u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[11], ctx->fpr[6], ctx->fpr[9], false, true, true, &result))
            ctx->fpr[6] = result;
    }

label_8006EAD4:
    ctx->pc = 0x8006EAD4u;
    // 8006EAD4: fmul   f6, f8, f6
    if (!ppc_fp_available_inline(ctx, 0x8006EAD4u)) return;
    ppc_fmul(ctx, 6, 8, 6);

label_8006EAD8:
    ctx->pc = 0x8006EAD8u;
    // 8006EAD8: fmul   f8, f10, f6
    if (!ppc_fp_available_inline(ctx, 0x8006EAD8u)) return;
    ppc_fmul(ctx, 8, 10, 6);

label_8006EADC:
    ctx->pc = 0x8006EADCu;
    // 8006EADC: fmul   f6, f6, f6
    if (!ppc_fp_available_inline(ctx, 0x8006EADCu)) return;
    ppc_fmul(ctx, 6, 6, 6);

label_8006EAE0:
    ctx->pc = 0x8006EAE0u;
    // 8006EAE0: fnmsub f6, f11, f6, f9
    if (!ppc_fp_available_inline(ctx, 0x8006EAE0u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[11], ctx->fpr[6], ctx->fpr[9], false, true, true, &result))
            ctx->fpr[6] = result;
    }

label_8006EAE4:
    ctx->pc = 0x8006EAE4u;
    // 8006EAE4: fmul   f6, f8, f6
    if (!ppc_fp_available_inline(ctx, 0x8006EAE4u)) return;
    ppc_fmul(ctx, 6, 8, 6);

label_8006EAE8:
    ctx->pc = 0x8006EAE8u;
    // 8006EAE8: fmul   f6, f11, f6
    if (!ppc_fp_available_inline(ctx, 0x8006EAE8u)) return;
    ppc_fmul(ctx, 6, 11, 6);

label_8006EAEC:
    ctx->pc = 0x8006EAECu;
    // 8006EAEC: frsp    f6, f6
    if (!ppc_fp_available_inline(ctx, 0x8006EAECu)) return;
    ppc_frsp(ctx, 6, 6);

label_8006EAF0:
    ctx->pc = 0x8006EAF0u;
    // 8006EAF0: stfs     f6, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006EAF0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[6]));
    }

label_8006EAF4:
    ctx->pc = 0x8006EAF4u;
    // 8006EAF4: lfs     f11, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006EAF4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_8006EAF8:
    ctx->pc = 0x8006EAF8u;
    ctx->downcount -= 7;
    // 8006EAF8: fmuls   f6, f7, f11
    if (!ppc_fp_available_inline(ctx, 0x8006EAF8u)) return;
    ppc_fmuls(ctx, 6, 7, 11);

label_8006EAFC:
    ctx->pc = 0x8006EAFCu;
    // 8006EAFC: fctiwz    f6, f6
    if (!ppc_fp_available_inline(ctx, 0x8006EAFCu)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[6], true, &result)) ctx->fpr[6] = dolrecomp_f64_from_bits(result); }

label_8006EB00:
    ctx->pc = 0x8006EB00u;
    // 8006EB00: stfd     f6, 88(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006EB00u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[6]));
    }

label_8006EB04:
    ctx->pc = 0x8006EB04u;
    // 8006EB04: lwz     r0, 92(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8006EB08:
    ctx->pc = 0x8006EB08u;
    // 8006EB08: stbx    r0, r6, r4
    {
        u32 ea = ctx->gpr[6] + ctx->gpr[4];
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006EB0C:
    // 8006EB0C: addi    r8, r8, 1
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(1);

label_8006EB10:
    // 8006EB10: bc    16, 0, 0x8006E9BC
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8006E9BCu;
                return;
            }
            goto label_8006E9BC;
        }
    }

label_8006EB14:
    ctx->downcount -= 3;
    // 8006EB14: addi    r7, r7, 1
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(1);

label_8006EB18:
    // 8006EB18: cmpwi   r7, 128
    {
        s32 val_a = (s32)(ctx->gpr[7]);
        s32 val_b = (s32)(128);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8006EB1C:
    // 8006EB1C: bc    12, 0, 0x8006E980
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8006E980u;
                return;
            }
            goto label_8006E980;
        }
    }

label_8006EB20:
    ctx->pc = 0x8006EB20u;
    ctx->downcount -= 4;
    // 8006EB20: lwz     r4, -25048(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25048);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8006EB24:
    ctx->pc = 0x8006EB24u;
    // 8006EB24: addi    r3, r4, 96
    ctx->gpr[3] = ctx->gpr[4] + (u32)(s32)(96);

label_8006EB28:
    ctx->pc = 0x8006EB28u;
    // 8006EB28: lwz     r4, 68(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(68);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8006EB2C:
    ctx->pc = 0x8006EB2Cu;
    // 8006EB2C: bl      0x80242328
    {
            ctx->lr = 0x8006EB30u;
            ctx->pc = 0x80242328u;
            return;
    }

label_8006EB30:
    ctx->pc = 0x8006EB30u;
    ctx->downcount -= 11;
    // 8006EB30: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8006EB34:
    ctx->pc = 0x8006EB34u;
    // 8006EB34: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006EB38:
    ctx->pc = 0x8006EB38u;
    // 8006EB38: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_8006EB3C:
    ctx->pc = 0x8006EB3Cu;
    // 8006EB3C: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_8006EB40:
    ctx->pc = 0x8006EB40u;
    // 8006EB40: li      r5, 3
    ctx->gpr[5] = (u32)(s32)(3);

label_8006EB44:
    ctx->pc = 0x8006EB44u;
    // 8006EB44: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8006EB48:
    ctx->pc = 0x8006EB48u;
    // 8006EB48: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8006EB4C:
    ctx->pc = 0x8006EB4Cu;
    // 8006EB4C: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8006EB50:
    ctx->pc = 0x8006EB50u;
    // 8006EB50: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_8006EB54:
    ctx->pc = 0x8006EB54u;
    // 8006EB54: li      r10, 1
    ctx->gpr[10] = (u32)(s32)(1);

label_8006EB58:
    ctx->pc = 0x8006EB58u;
    // 8006EB58: bl      0x80054E7C
    {
            ctx->lr = 0x8006EB5Cu;
            ctx->pc = 0x80054E7Cu;
            return;
    }

label_8006EB5C:
    ctx->pc = 0x8006EB5Cu;
    ctx->downcount -= 18;
    // 8006EB5C: stw     r3, -25076(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25076);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8006EB60:
    ctx->pc = 0x8006EB60u;
    // 8006EB60: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8006EB64:
    ctx->pc = 0x8006EB64u;
    // 8006EB64: lfd     f9, -30512(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006EB64u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30512);
        ctx->fpr[9] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006EB68:
    ctx->pc = 0x8006EB68u;
    // 8006EB68: lis     r0, 17200
    ctx->gpr[0] = ((u32)(s32)(17200) << 16);

label_8006EB6C:
    ctx->pc = 0x8006EB6Cu;
    // 8006EB6C: lfs     f8, -30440(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006EB6Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30440);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[8] = value;
        ctx->ps1[8] = value;
    }

label_8006EB70:
    ctx->pc = 0x8006EB70u;
    // 8006EB70: lfs     f7, -30656(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006EB70u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30656);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[7] = value;
        ctx->ps1[7] = value;
    }

label_8006EB74:
    ctx->pc = 0x8006EB74u;
    // 8006EB74: lfs     f6, -30704(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006EB74u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30704);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[6] = value;
        ctx->ps1[6] = value;
    }

label_8006EB78:
    ctx->pc = 0x8006EB78u;
    // 8006EB78: lfs     f5, -30524(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006EB78u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30524);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[5] = value;
        ctx->ps1[5] = value;
    }

label_8006EB7C:
    ctx->pc = 0x8006EB7Cu;
    // 8006EB7C: fctiwz    f3, f7
    if (!ppc_fp_available_inline(ctx, 0x8006EB7Cu)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[7], true, &result)) ctx->fpr[3] = dolrecomp_f64_from_bits(result); }

label_8006EB80:
    ctx->pc = 0x8006EB80u;
    // 8006EB80: lfs     f0, -30436(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006EB80u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30436);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8006EB84:
    ctx->pc = 0x8006EB84u;
    // 8006EB84: fctiwz    f2, f0
    if (!ppc_fp_available_inline(ctx, 0x8006EB84u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[2] = dolrecomp_f64_from_bits(result); }

label_8006EB88:
    ctx->pc = 0x8006EB88u;
    // 8006EB88: lfs     f0, -30432(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006EB88u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30432);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8006EB8C:
    ctx->pc = 0x8006EB8Cu;
    // 8006EB8C: fctiwz    f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8006EB8Cu)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[1] = dolrecomp_f64_from_bits(result); }

label_8006EB90:
    ctx->pc = 0x8006EB90u;
    // 8006EB90: lfs     f0, -30428(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006EB90u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30428);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8006EB94:
    ctx->pc = 0x8006EB94u;
    // 8006EB94: fctiwz    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x8006EB94u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_8006EB98:
    ctx->pc = 0x8006EB98u;
    // 8006EB98: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_8006EB9C:
    ctx->pc = 0x8006EB9Cu;
    // 8006EB9C: mtctr    r3
    ctx->ctr = ctx->gpr[3];

label_8006EBA0:
    ctx->downcount -= 71;
    // 8006EBA0: xoris   r3, r5, 0x8000
    ctx->gpr[3] = ctx->gpr[5] ^ (0x8000u << 16);

label_8006EBA4:
    ctx->pc = 0x8006EBA4u;
    // 8006EBA4: stw     r3, 92(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8006EBA8:
    ctx->pc = 0x8006EBA8u;
    // 8006EBA8: stw     r0, 88(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006EBAC:
    ctx->pc = 0x8006EBACu;
    // 8006EBAC: lfd     f4, 88(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006EBACu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        ctx->fpr[4] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006EBB0:
    ctx->pc = 0x8006EBB0u;
    // 8006EBB0: fsubs   f4, f4, f9
    if (!ppc_fp_available_inline(ctx, 0x8006EBB0u)) return;
    ppc_fsubs(ctx, 4, 4, 9);

label_8006EBB4:
    ctx->pc = 0x8006EBB4u;
    // 8006EBB4: fdivs   f4, f4, f8
    if (!ppc_fp_available_inline(ctx, 0x8006EBB4u)) return;
    ppc_fdivs(ctx, 4, 4, 8);

label_8006EBB8:
    ctx->pc = 0x8006EBB8u;
    // 8006EBB8: fsubs   f4, f4, f7
    if (!ppc_fp_available_inline(ctx, 0x8006EBB8u)) return;
    ppc_fsubs(ctx, 4, 4, 7);

label_8006EBBC:
    ctx->pc = 0x8006EBBCu;
    // 8006EBBC: lwz     r6, -25076(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25076);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8006EBC0:
    // 8006EBC0: rlwinm r3, r5, 0, 30, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x00000003u;
    }

label_8006EBC4:
    // 8006EBC4: rlwinm r4, r3, 1, 0, 30
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[3], 1u) & 0xFFFFFFFEu;
    }

label_8006EBC8:
    // 8006EBC8: add   r6, r6, r4
    {
        u32 a = ctx->gpr[6];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_8006EBCC:
    // 8006EBCC: srawi r3, r5, 2
    {
        u32 sh = 2u;
        u32 value = ctx->gpr[5];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[3] = value;
        } else if (sh > 31) {
            ctx->gpr[3] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[3] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_8006EBD0:
    // 8006EBD0: rlwinm r3, r3, 5, 0, 26
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 5u) & 0xFFFFFFE0u;
    }

label_8006EBD4:
    // 8006EBD4: add   r7, r6, r3
    {
        u32 a = ctx->gpr[6];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_8006EBD8:
    ctx->pc = 0x8006EBD8u;
    // 8006EBD8: fmadds f4, f6, f4, f5
    if (!ppc_fp_available_inline(ctx, 0x8006EBD8u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[6], ctx->fpr[4], ctx->fpr[5], true, false, false, &result))
            ctx->fpr[4] = ctx->ps1[4] = result;
    }

label_8006EBDC:
    ctx->pc = 0x8006EBDCu;
    // 8006EBDC: fctiwz    f4, f4
    if (!ppc_fp_available_inline(ctx, 0x8006EBDCu)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[4], true, &result)) ctx->fpr[4] = dolrecomp_f64_from_bits(result); }

label_8006EBE0:
    ctx->pc = 0x8006EBE0u;
    // 8006EBE0: stfd     f4, 80(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006EBE0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[4]));
    }

label_8006EBE4:
    ctx->pc = 0x8006EBE4u;
    // 8006EBE4: lwz     r6, 84(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8006EBE8:
    // 8006EBE8: rlwinm r6, r6, 0, 24, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x000000FFu;
    }

label_8006EBEC:
    // 8006EBEC: rlwinm r8, r6, 8, 0, 23
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[6], 8u) & 0xFFFFFF00u;
    }

label_8006EBF0:
    ctx->pc = 0x8006EBF0u;
    // 8006EBF0: stfd     f3, 72(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006EBF0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[3]));
    }

label_8006EBF4:
    ctx->pc = 0x8006EBF4u;
    // 8006EBF4: lwz     r6, 76(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(76);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8006EBF8:
    // 8006EBF8: rlwinm r6, r6, 0, 24, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x000000FFu;
    }

label_8006EBFC:
    // 8006EBFC: or   r6, r8, r6
    {
        ctx->gpr[6] = ctx->gpr[8] | ctx->gpr[6];
    }

label_8006EC00:
    // 8006EC00: rlwinm r6, r6, 0, 16, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x0000FFFFu;
    }

label_8006EC04:
    ctx->pc = 0x8006EC04u;
    // 8006EC04: sth     r6, 96(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(96);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_8006EC08:
    ctx->pc = 0x8006EC08u;
    // 8006EC08: lwz     r6, -25076(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25076);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8006EC0C:
    // 8006EC0C: add   r6, r6, r4
    {
        u32 a = ctx->gpr[6];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_8006EC10:
    // 8006EC10: add   r7, r6, r3
    {
        u32 a = ctx->gpr[6];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_8006EC14:
    ctx->pc = 0x8006EC14u;
    // 8006EC14: stfd     f2, 96(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006EC14u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[2]));
    }

label_8006EC18:
    ctx->pc = 0x8006EC18u;
    // 8006EC18: lwz     r6, 100(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(100);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8006EC1C:
    // 8006EC1C: rlwinm r6, r6, 0, 24, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x000000FFu;
    }

label_8006EC20:
    // 8006EC20: or   r6, r8, r6
    {
        ctx->gpr[6] = ctx->gpr[8] | ctx->gpr[6];
    }

label_8006EC24:
    // 8006EC24: rlwinm r6, r6, 0, 16, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x0000FFFFu;
    }

label_8006EC28:
    ctx->pc = 0x8006EC28u;
    // 8006EC28: sth     r6, 104(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(104);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_8006EC2C:
    ctx->pc = 0x8006EC2Cu;
    // 8006EC2C: lwz     r6, -25076(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25076);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8006EC30:
    // 8006EC30: add   r6, r6, r4
    {
        u32 a = ctx->gpr[6];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_8006EC34:
    // 8006EC34: add   r7, r6, r3
    {
        u32 a = ctx->gpr[6];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_8006EC38:
    ctx->pc = 0x8006EC38u;
    // 8006EC38: stfd     f1, 104(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006EC38u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[1]));
    }

label_8006EC3C:
    ctx->pc = 0x8006EC3Cu;
    // 8006EC3C: lwz     r6, 108(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(108);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8006EC40:
    // 8006EC40: rlwinm r6, r6, 0, 24, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x000000FFu;
    }

label_8006EC44:
    // 8006EC44: or   r6, r8, r6
    {
        ctx->gpr[6] = ctx->gpr[8] | ctx->gpr[6];
    }

label_8006EC48:
    // 8006EC48: rlwinm r6, r6, 0, 16, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x0000FFFFu;
    }

label_8006EC4C:
    ctx->pc = 0x8006EC4Cu;
    // 8006EC4C: sth     r6, 112(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(112);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_8006EC50:
    ctx->pc = 0x8006EC50u;
    // 8006EC50: stfd     f0, 112(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006EC50u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(112);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_8006EC54:
    ctx->pc = 0x8006EC54u;
    // 8006EC54: lwz     r6, 116(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(116);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8006EC58:
    // 8006EC58: rlwinm r6, r6, 0, 24, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x000000FFu;
    }

label_8006EC5C:
    // 8006EC5C: or   r6, r8, r6
    {
        ctx->gpr[6] = ctx->gpr[8] | ctx->gpr[6];
    }

label_8006EC60:
    // 8006EC60: rlwinm r7, r6, 0, 16, 31
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x0000FFFFu;
    }

label_8006EC64:
    ctx->pc = 0x8006EC64u;
    // 8006EC64: lwz     r6, -25076(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25076);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8006EC68:
    // 8006EC68: add   r4, r6, r4
    {
        u32 a = ctx->gpr[6];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_8006EC6C:
    // 8006EC6C: add   r3, r4, r3
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8006EC70:
    ctx->pc = 0x8006EC70u;
    // 8006EC70: sth     r7, 120(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(120);
        mem_write16(ctx, ea, (u16)ctx->gpr[7]);
    }

label_8006EC74:
    // 8006EC74: addi    r5, r5, 1
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(1);

label_8006EC78:
    // 8006EC78: bc    16, 0, 0x8006EBA0
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8006EBA0u;
                return;
            }
            goto label_8006EBA0;
        }
    }

label_8006EC7C:
    ctx->pc = 0x8006EC7Cu;
    ctx->downcount -= 4;
    // 8006EC7C: lwz     r4, -25076(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25076);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8006EC80:
    ctx->pc = 0x8006EC80u;
    // 8006EC80: addi    r3, r4, 96
    ctx->gpr[3] = ctx->gpr[4] + (u32)(s32)(96);

label_8006EC84:
    ctx->pc = 0x8006EC84u;
    // 8006EC84: lwz     r4, 68(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(68);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8006EC88:
    ctx->pc = 0x8006EC88u;
    // 8006EC88: bl      0x80242328
    {
            ctx->lr = 0x8006EC8Cu;
            ctx->pc = 0x80242328u;
            return;
    }

label_8006EC8C:
    ctx->pc = 0x8006EC8Cu;
    ctx->downcount -= 11;
    // 8006EC8C: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8006EC90:
    ctx->pc = 0x8006EC90u;
    // 8006EC90: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006EC94:
    ctx->pc = 0x8006EC94u;
    // 8006EC94: li      r3, 128
    ctx->gpr[3] = (u32)(s32)(128);

label_8006EC98:
    ctx->pc = 0x8006EC98u;
    // 8006EC98: li      r4, 128
    ctx->gpr[4] = (u32)(s32)(128);

label_8006EC9C:
    ctx->pc = 0x8006EC9Cu;
    // 8006EC9C: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_8006ECA0:
    ctx->pc = 0x8006ECA0u;
    // 8006ECA0: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8006ECA4:
    ctx->pc = 0x8006ECA4u;
    // 8006ECA4: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8006ECA8:
    ctx->pc = 0x8006ECA8u;
    // 8006ECA8: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8006ECAC:
    ctx->pc = 0x8006ECACu;
    // 8006ECAC: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_8006ECB0:
    ctx->pc = 0x8006ECB0u;
    // 8006ECB0: li      r10, 1
    ctx->gpr[10] = (u32)(s32)(1);

label_8006ECB4:
    ctx->pc = 0x8006ECB4u;
    // 8006ECB4: bl      0x80054E7C
    {
            ctx->lr = 0x8006ECB8u;
            ctx->pc = 0x80054E7Cu;
            return;
    }

label_8006ECB8:
    ctx->pc = 0x8006ECB8u;
    ctx->downcount -= 5;
    // 8006ECB8: or   r25, r3, r3
    {
        ctx->gpr[25] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8006ECBC:
    ctx->pc = 0x8006ECBCu;
    // 8006ECBC: addi    r3, r25, 96
    ctx->gpr[3] = ctx->gpr[25] + (u32)(s32)(96);

label_8006ECC0:
    ctx->pc = 0x8006ECC0u;
    // 8006ECC0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8006ECC4:
    ctx->pc = 0x8006ECC4u;
    // 8006ECC4: lwz     r5, 68(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(68);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8006ECC8:
    ctx->pc = 0x8006ECC8u;
    // 8006ECC8: bl      0x800033A8
    {
            ctx->lr = 0x8006ECCCu;
            ctx->pc = 0x800033A8u;
            return;
    }

label_8006ECCC:
    ctx->pc = 0x8006ECCCu;
    ctx->downcount -= 5;
    // 8006ECCC: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8006ECD0:
    ctx->pc = 0x8006ECD0u;
    // 8006ECD0: sth     r0, 14(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(14);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8006ECD4:
    ctx->pc = 0x8006ECD4u;
    // 8006ECD4: addi    r3, r25, 96
    ctx->gpr[3] = ctx->gpr[25] + (u32)(s32)(96);

label_8006ECD8:
    ctx->pc = 0x8006ECD8u;
    // 8006ECD8: lwz     r4, 68(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(68);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8006ECDC:
    ctx->pc = 0x8006ECDCu;
    // 8006ECDC: bl      0x80242328
    {
            ctx->lr = 0x8006ECE0u;
            ctx->pc = 0x80242328u;
            return;
    }

label_8006ECE0:
    ctx->pc = 0x8006ECE0u;
    ctx->downcount -= 12;
    // 8006ECE0: stw     r25, 660(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(660);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_8006ECE4:
    ctx->pc = 0x8006ECE4u;
    // 8006ECE4: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8006ECE8:
    ctx->pc = 0x8006ECE8u;
    // 8006ECE8: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006ECEC:
    ctx->pc = 0x8006ECECu;
    // 8006ECEC: li      r3, 128
    ctx->gpr[3] = (u32)(s32)(128);

label_8006ECF0:
    ctx->pc = 0x8006ECF0u;
    // 8006ECF0: li      r4, 128
    ctx->gpr[4] = (u32)(s32)(128);

label_8006ECF4:
    ctx->pc = 0x8006ECF4u;
    // 8006ECF4: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_8006ECF8:
    ctx->pc = 0x8006ECF8u;
    // 8006ECF8: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8006ECFC:
    ctx->pc = 0x8006ECFCu;
    // 8006ECFC: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8006ED00:
    ctx->pc = 0x8006ED00u;
    // 8006ED00: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8006ED04:
    ctx->pc = 0x8006ED04u;
    // 8006ED04: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_8006ED08:
    ctx->pc = 0x8006ED08u;
    // 8006ED08: li      r10, 1
    ctx->gpr[10] = (u32)(s32)(1);

label_8006ED0C:
    ctx->pc = 0x8006ED0Cu;
    // 8006ED0C: bl      0x80054E7C
    {
            ctx->lr = 0x8006ED10u;
            ctx->pc = 0x80054E7Cu;
            return;
    }

label_8006ED10:
    ctx->pc = 0x8006ED10u;
    ctx->downcount -= 5;
    // 8006ED10: or   r25, r3, r3
    {
        ctx->gpr[25] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8006ED14:
    ctx->pc = 0x8006ED14u;
    // 8006ED14: addi    r3, r25, 96
    ctx->gpr[3] = ctx->gpr[25] + (u32)(s32)(96);

label_8006ED18:
    ctx->pc = 0x8006ED18u;
    // 8006ED18: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8006ED1C:
    ctx->pc = 0x8006ED1Cu;
    // 8006ED1C: lwz     r5, 68(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(68);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8006ED20:
    ctx->pc = 0x8006ED20u;
    // 8006ED20: bl      0x800033A8
    {
            ctx->lr = 0x8006ED24u;
            ctx->pc = 0x800033A8u;
            return;
    }

label_8006ED24:
    ctx->pc = 0x8006ED24u;
    ctx->downcount -= 5;
    // 8006ED24: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8006ED28:
    ctx->pc = 0x8006ED28u;
    // 8006ED28: sth     r0, 14(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(14);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8006ED2C:
    ctx->pc = 0x8006ED2Cu;
    // 8006ED2C: addi    r3, r25, 96
    ctx->gpr[3] = ctx->gpr[25] + (u32)(s32)(96);

label_8006ED30:
    ctx->pc = 0x8006ED30u;
    // 8006ED30: lwz     r4, 68(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(68);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8006ED34:
    ctx->pc = 0x8006ED34u;
    // 8006ED34: bl      0x80242328
    {
            ctx->lr = 0x8006ED38u;
            ctx->pc = 0x80242328u;
            return;
    }

label_8006ED38:
    ctx->pc = 0x8006ED38u;
    ctx->downcount -= 12;
    // 8006ED38: stw     r25, 664(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(664);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_8006ED3C:
    ctx->pc = 0x8006ED3Cu;
    // 8006ED3C: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8006ED40:
    ctx->pc = 0x8006ED40u;
    // 8006ED40: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006ED44:
    ctx->pc = 0x8006ED44u;
    // 8006ED44: li      r3, 128
    ctx->gpr[3] = (u32)(s32)(128);

label_8006ED48:
    ctx->pc = 0x8006ED48u;
    // 8006ED48: li      r4, 128
    ctx->gpr[4] = (u32)(s32)(128);

label_8006ED4C:
    ctx->pc = 0x8006ED4Cu;
    // 8006ED4C: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_8006ED50:
    ctx->pc = 0x8006ED50u;
    // 8006ED50: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8006ED54:
    ctx->pc = 0x8006ED54u;
    // 8006ED54: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8006ED58:
    ctx->pc = 0x8006ED58u;
    // 8006ED58: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8006ED5C:
    ctx->pc = 0x8006ED5Cu;
    // 8006ED5C: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_8006ED60:
    ctx->pc = 0x8006ED60u;
    // 8006ED60: li      r10, 1
    ctx->gpr[10] = (u32)(s32)(1);

label_8006ED64:
    ctx->pc = 0x8006ED64u;
    // 8006ED64: bl      0x80054E7C
    {
            ctx->lr = 0x8006ED68u;
            ctx->pc = 0x80054E7Cu;
            return;
    }

label_8006ED68:
    ctx->pc = 0x8006ED68u;
    ctx->downcount -= 5;
    // 8006ED68: or   r25, r3, r3
    {
        ctx->gpr[25] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8006ED6C:
    ctx->pc = 0x8006ED6Cu;
    // 8006ED6C: addi    r3, r25, 96
    ctx->gpr[3] = ctx->gpr[25] + (u32)(s32)(96);

label_8006ED70:
    ctx->pc = 0x8006ED70u;
    // 8006ED70: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8006ED74:
    ctx->pc = 0x8006ED74u;
    // 8006ED74: lwz     r5, 68(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(68);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8006ED78:
    ctx->pc = 0x8006ED78u;
    // 8006ED78: bl      0x800033A8
    {
            ctx->lr = 0x8006ED7Cu;
            ctx->pc = 0x800033A8u;
            return;
    }

label_8006ED7C:
    ctx->pc = 0x8006ED7Cu;
    ctx->downcount -= 5;
    // 8006ED7C: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8006ED80:
    ctx->pc = 0x8006ED80u;
    // 8006ED80: sth     r0, 14(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(14);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8006ED84:
    ctx->pc = 0x8006ED84u;
    // 8006ED84: addi    r3, r25, 96
    ctx->gpr[3] = ctx->gpr[25] + (u32)(s32)(96);

label_8006ED88:
    ctx->pc = 0x8006ED88u;
    // 8006ED88: lwz     r4, 68(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(68);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8006ED8C:
    ctx->pc = 0x8006ED8Cu;
    // 8006ED8C: bl      0x80242328
    {
            ctx->lr = 0x8006ED90u;
            ctx->pc = 0x80242328u;
            return;
    }

label_8006ED90:
    ctx->pc = 0x8006ED90u;
    ctx->downcount -= 2;
    // 8006ED90: stw     r25, 668(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(668);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_8006ED94:
    ctx->pc = 0x8006ED94u;
    // 8006ED94: bl      0x80258E54
    {
            ctx->lr = 0x8006ED98u;
            ctx->pc = 0x80258E54u;
            return;
    }

label_8006ED98:
    ctx->pc = 0x8006ED98u;
    ctx->downcount -= 5;
    // 8006ED98: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8006ED9C:
    ctx->pc = 0x8006ED9Cu;
    // 8006ED9C: or   r6, r30, r30
    {
        ctx->gpr[6] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8006EDA0:
    ctx->pc = 0x8006EDA0u;
    // 8006EDA0: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_8006EDA4:
    ctx->pc = 0x8006EDA4u;
    // 8006EDA4: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8006EDA8:
    loop_8006EDA8(ctx);
    if (ctx->pc == 0x8006EE3Cu) goto label_8006EE3C;
    return;
label_8006EDAC:
    ctx->pc = 0x8006EDACu;
    // 8006EDAC: stb     r4, 16(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(16);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_8006EDB0:
    // 8006EDB0: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8006EDB4:
    ctx->pc = 0x8006EDB4u;
    // 8006EDB4: stb     r3, 17(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(17);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_8006EDB8:
    ctx->pc = 0x8006EDB8u;
    // 8006EDB8: stb     r4, 36(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(36);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_8006EDBC:
    ctx->pc = 0x8006EDBCu;
    // 8006EDBC: stb     r3, 37(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(37);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_8006EDC0:
    ctx->pc = 0x8006EDC0u;
    // 8006EDC0: stb     r4, 56(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(56);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_8006EDC4:
    ctx->pc = 0x8006EDC4u;
    // 8006EDC4: stb     r3, 57(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(57);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_8006EDC8:
    ctx->pc = 0x8006EDC8u;
    // 8006EDC8: stb     r4, 76(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(76);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_8006EDCC:
    ctx->pc = 0x8006EDCCu;
    // 8006EDCC: stb     r3, 77(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(77);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_8006EDD0:
    ctx->pc = 0x8006EDD0u;
    // 8006EDD0: stb     r4, 96(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(96);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_8006EDD4:
    ctx->pc = 0x8006EDD4u;
    // 8006EDD4: stb     r3, 97(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(97);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_8006EDD8:
    ctx->pc = 0x8006EDD8u;
    // 8006EDD8: stb     r4, 116(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(116);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_8006EDDC:
    ctx->pc = 0x8006EDDCu;
    // 8006EDDC: stb     r3, 117(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(117);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_8006EDE0:
    ctx->pc = 0x8006EDE0u;
    // 8006EDE0: stb     r4, 136(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(136);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_8006EDE4:
    ctx->pc = 0x8006EDE4u;
    // 8006EDE4: stb     r3, 137(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(137);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_8006EDE8:
    ctx->pc = 0x8006EDE8u;
    // 8006EDE8: stb     r4, 156(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(156);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_8006EDEC:
    ctx->pc = 0x8006EDECu;
    // 8006EDEC: stb     r3, 157(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(157);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_8006EDF0:
    ctx->pc = 0x8006EDF0u;
    // 8006EDF0: stb     r4, 176(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(176);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_8006EDF4:
    ctx->pc = 0x8006EDF4u;
    // 8006EDF4: stb     r3, 177(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(177);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_8006EDF8:
    ctx->pc = 0x8006EDF8u;
    // 8006EDF8: stb     r4, 196(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(196);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_8006EDFC:
    ctx->pc = 0x8006EDFCu;
    // 8006EDFC: stb     r3, 197(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(197);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_8006EE00:
    ctx->pc = 0x8006EE00u;
    // 8006EE00: stb     r4, 216(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(216);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_8006EE04:
    ctx->pc = 0x8006EE04u;
    // 8006EE04: stb     r3, 217(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(217);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_8006EE08:
    ctx->pc = 0x8006EE08u;
    // 8006EE08: stb     r4, 236(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(236);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_8006EE0C:
    ctx->pc = 0x8006EE0Cu;
    // 8006EE0C: stb     r3, 237(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(237);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_8006EE10:
    ctx->pc = 0x8006EE10u;
    // 8006EE10: stb     r4, 256(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(256);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_8006EE14:
    ctx->pc = 0x8006EE14u;
    // 8006EE14: stb     r3, 257(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(257);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_8006EE18:
    ctx->pc = 0x8006EE18u;
    // 8006EE18: stb     r4, 276(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(276);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_8006EE1C:
    ctx->pc = 0x8006EE1Cu;
    // 8006EE1C: stb     r3, 277(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(277);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_8006EE20:
    ctx->pc = 0x8006EE20u;
    // 8006EE20: stb     r4, 296(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(296);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_8006EE24:
    ctx->pc = 0x8006EE24u;
    // 8006EE24: stb     r3, 297(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(297);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_8006EE28:
    ctx->pc = 0x8006EE28u;
    // 8006EE28: stb     r4, 316(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(316);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_8006EE2C:
    ctx->pc = 0x8006EE2Cu;
    // 8006EE2C: stb     r3, 317(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(317);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_8006EE30:
    // 8006EE30: addi    r6, r6, 320
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(320);

label_8006EE34:
    // 8006EE34: addi    r5, r5, 16
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(16);

label_8006EE38:
    // 8006EE38: bc    16, 0, 0x8006EDA8
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8006EDA8u;
                return;
            }
            goto label_8006EDA8;
        }
    }

label_8006EE3C:
    ctx->pc = 0x8006EE3Cu;
    ctx->downcount -= 9;
    // 8006EE3C: mulli   r0, r5, 20
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[5] * (s64)(s32)20);

label_8006EE40:
    ctx->pc = 0x8006EE40u;
    // 8006EE40: add   r6, r30, r0
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_8006EE44:
    ctx->pc = 0x8006EE44u;
    // 8006EE44: subfic  r0, r5, 33
    {
        u64 res = (u64)(u32)(s32)(33) + (u64)(~ctx->gpr[5]) + 1u;
        ctx->gpr[0] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8006EE48:
    ctx->pc = 0x8006EE48u;
    // 8006EE48: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8006EE4C:
    ctx->pc = 0x8006EE4Cu;
    // 8006EE4C: cmpwi   r5, 33
    {
        s32 val_a = (s32)(ctx->gpr[5]);
        s32 val_b = (s32)(33);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8006EE50:
    ctx->pc = 0x8006EE50u;
    // 8006EE50: bc    4, 0, 0x8006EE64
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8006EE64;
        }
    }

label_8006EE54:
    loop_8006EE54(ctx);
    if (ctx->pc == 0x8006EE64u) goto label_8006EE64;
    return;
label_8006EE58:
    ctx->pc = 0x8006EE58u;
    // 8006EE58: stb     r3, 17(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(17);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_8006EE5C:
    // 8006EE5C: addi    r6, r6, 20
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(20);

label_8006EE60:
    // 8006EE60: bc    16, 0, 0x8006EE54
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8006EE54u;
                return;
            }
            goto label_8006EE54;
        }
    }

label_8006EE64:
    ctx->pc = 0x8006EE64u;
    ctx->downcount -= 1;
    // 8006EE64: bl      0x8025B41C
    {
            ctx->lr = 0x8006EE68u;
            ctx->pc = 0x8025B41Cu;
            return;
    }

label_8006EE68:
    ctx->pc = 0x8006EE68u;
    ctx->downcount -= 2;
    // 8006EE68: or   r3, r24, r24
    {
        ctx->gpr[3] = ctx->gpr[24] | ctx->gpr[24];
    }

label_8006EE6C:
    ctx->pc = 0x8006EE6Cu;
    // 8006EE6C: bl      0x80022EA4
    {
            ctx->lr = 0x8006EE70u;
            ctx->pc = 0x80022EA4u;
            return;
    }

label_8006EE70:
    ctx->pc = 0x8006EE70u;
    ctx->downcount -= 34;
    // 8006EE70: psq_l   f31, 408(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8006EE70u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(408);
        ppc_psq_load_inline(ctx, 31u, ea, false, 0u, false, 0x8006EE70u);
        if (ctx->exception) return;
    }

label_8006EE74:
    ctx->pc = 0x8006EE74u;
    // 8006EE74: lfd     f31, 400(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006EE74u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(400);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006EE78:
    ctx->pc = 0x8006EE78u;
    // 8006EE78: psq_l   f30, 392(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8006EE78u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(392);
        ppc_psq_load_inline(ctx, 30u, ea, false, 0u, false, 0x8006EE78u);
        if (ctx->exception) return;
    }

label_8006EE7C:
    ctx->pc = 0x8006EE7Cu;
    // 8006EE7C: lfd     f30, 384(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006EE7Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(384);
        ctx->fpr[30] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006EE80:
    ctx->pc = 0x8006EE80u;
    // 8006EE80: psq_l   f29, 376(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8006EE80u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(376);
        ppc_psq_load_inline(ctx, 29u, ea, false, 0u, false, 0x8006EE80u);
        if (ctx->exception) return;
    }

label_8006EE84:
    ctx->pc = 0x8006EE84u;
    // 8006EE84: lfd     f29, 368(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006EE84u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(368);
        ctx->fpr[29] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006EE88:
    ctx->pc = 0x8006EE88u;
    // 8006EE88: psq_l   f28, 360(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8006EE88u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(360);
        ppc_psq_load_inline(ctx, 28u, ea, false, 0u, false, 0x8006EE88u);
        if (ctx->exception) return;
    }

label_8006EE8C:
    ctx->pc = 0x8006EE8Cu;
    // 8006EE8C: lfd     f28, 352(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006EE8Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(352);
        ctx->fpr[28] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006EE90:
    ctx->pc = 0x8006EE90u;
    // 8006EE90: psq_l   f27, 344(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8006EE90u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(344);
        ppc_psq_load_inline(ctx, 27u, ea, false, 0u, false, 0x8006EE90u);
        if (ctx->exception) return;
    }

label_8006EE94:
    ctx->pc = 0x8006EE94u;
    // 8006EE94: lfd     f27, 336(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006EE94u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(336);
        ctx->fpr[27] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006EE98:
    ctx->pc = 0x8006EE98u;
    // 8006EE98: psq_l   f26, 328(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8006EE98u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(328);
        ppc_psq_load_inline(ctx, 26u, ea, false, 0u, false, 0x8006EE98u);
        if (ctx->exception) return;
    }

label_8006EE9C:
    ctx->pc = 0x8006EE9Cu;
    // 8006EE9C: lfd     f26, 320(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006EE9Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(320);
        ctx->fpr[26] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006EEA0:
    ctx->pc = 0x8006EEA0u;
    // 8006EEA0: psq_l   f25, 312(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8006EEA0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(312);
        ppc_psq_load_inline(ctx, 25u, ea, false, 0u, false, 0x8006EEA0u);
        if (ctx->exception) return;
    }

label_8006EEA4:
    ctx->pc = 0x8006EEA4u;
    // 8006EEA4: lfd     f25, 304(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006EEA4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(304);
        ctx->fpr[25] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006EEA8:
    ctx->pc = 0x8006EEA8u;
    // 8006EEA8: psq_l   f24, 296(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8006EEA8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(296);
        ppc_psq_load_inline(ctx, 24u, ea, false, 0u, false, 0x8006EEA8u);
        if (ctx->exception) return;
    }

label_8006EEAC:
    ctx->pc = 0x8006EEACu;
    // 8006EEAC: lfd     f24, 288(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006EEACu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(288);
        ctx->fpr[24] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006EEB0:
    ctx->pc = 0x8006EEB0u;
    // 8006EEB0: psq_l   f23, 280(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8006EEB0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(280);
        ppc_psq_load_inline(ctx, 23u, ea, false, 0u, false, 0x8006EEB0u);
        if (ctx->exception) return;
    }

label_8006EEB4:
    ctx->pc = 0x8006EEB4u;
    // 8006EEB4: lfd     f23, 272(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006EEB4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(272);
        ctx->fpr[23] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006EEB8:
    ctx->pc = 0x8006EEB8u;
    // 8006EEB8: psq_l   f22, 264(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8006EEB8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(264);
        ppc_psq_load_inline(ctx, 22u, ea, false, 0u, false, 0x8006EEB8u);
        if (ctx->exception) return;
    }

label_8006EEBC:
    ctx->pc = 0x8006EEBCu;
    // 8006EEBC: lfd     f22, 256(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006EEBCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(256);
        ctx->fpr[22] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006EEC0:
    ctx->pc = 0x8006EEC0u;
    // 8006EEC0: psq_l   f21, 248(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8006EEC0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(248);
        ppc_psq_load_inline(ctx, 21u, ea, false, 0u, false, 0x8006EEC0u);
        if (ctx->exception) return;
    }

label_8006EEC4:
    ctx->pc = 0x8006EEC4u;
    // 8006EEC4: lfd     f21, 240(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006EEC4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(240);
        ctx->fpr[21] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006EEC8:
    ctx->pc = 0x8006EEC8u;
    // 8006EEC8: psq_l   f20, 232(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8006EEC8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(232);
        ppc_psq_load_inline(ctx, 20u, ea, false, 0u, false, 0x8006EEC8u);
        if (ctx->exception) return;
    }

label_8006EECC:
    ctx->pc = 0x8006EECCu;
    // 8006EECC: lfd     f20, 224(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006EECCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(224);
        ctx->fpr[20] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006EED0:
    ctx->pc = 0x8006EED0u;
    // 8006EED0: psq_l   f19, 216(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8006EED0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(216);
        ppc_psq_load_inline(ctx, 19u, ea, false, 0u, false, 0x8006EED0u);
        if (ctx->exception) return;
    }

label_8006EED4:
    ctx->pc = 0x8006EED4u;
    // 8006EED4: lfd     f19, 208(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006EED4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(208);
        ctx->fpr[19] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006EED8:
    ctx->pc = 0x8006EED8u;
    // 8006EED8: psq_l   f18, 200(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8006EED8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(200);
        ppc_psq_load_inline(ctx, 18u, ea, false, 0u, false, 0x8006EED8u);
        if (ctx->exception) return;
    }

label_8006EEDC:
    ctx->pc = 0x8006EEDCu;
    // 8006EEDC: lfd     f18, 192(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006EEDCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(192);
        ctx->fpr[18] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006EEE0:
    ctx->pc = 0x8006EEE0u;
    // 8006EEE0: psq_l   f17, 184(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8006EEE0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(184);
        ppc_psq_load_inline(ctx, 17u, ea, false, 0u, false, 0x8006EEE0u);
        if (ctx->exception) return;
    }

label_8006EEE4:
    ctx->pc = 0x8006EEE4u;
    // 8006EEE4: lfd     f17, 176(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006EEE4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->fpr[17] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006EEE8:
    ctx->pc = 0x8006EEE8u;
    // 8006EEE8: psq_l   f16, 168(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8006EEE8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(168);
        ppc_psq_load_inline(ctx, 16u, ea, false, 0u, false, 0x8006EEE8u);
        if (ctx->exception) return;
    }

label_8006EEEC:
    ctx->pc = 0x8006EEECu;
    // 8006EEEC: lfd     f16, 160(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006EEECu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(160);
        ctx->fpr[16] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006EEF0:
    ctx->pc = 0x8006EEF0u;
    // 8006EEF0: addi    r11, r1, 160
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(160);

label_8006EEF4:
    ctx->pc = 0x8006EEF4u;
    // 8006EEF4: bl      0x80286A8C
    {
            ctx->lr = 0x8006EEF8u;
            ctx->pc = 0x80286A8Cu;
            return;
    }

label_8006EEF8:
    ctx->pc = 0x8006EEF8u;
    ctx->downcount -= 5;
    // 8006EEF8: lwz     r0, 420(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(420);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8006EEFC:
    ctx->pc = 0x8006EEFCu;
    // 8006EEFC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8006EF00:
    ctx->pc = 0x8006EF00u;
    // 8006EF00: addi    r1, r1, 416
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(416);

label_8006EF04:
    ctx->pc = 0x8006EF04u;
    // 8006EF04: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_8006EF08:
    ctx->pc = 0x8006EF08u;
    ctx->downcount -= 5;
    // 8006EF08: lis     r5, -32719
    ctx->gpr[5] = ((u32)(s32)(-32719) << 16);

label_8006EF0C:
    ctx->pc = 0x8006EF0Cu;
    // 8006EF0C: addi    r5, r5, 144
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(144);

label_8006EF10:
    ctx->pc = 0x8006EF10u;
    // 8006EF10: rlwinm r0, r3, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000000FFu;
    }

label_8006EF14:
    ctx->pc = 0x8006EF14u;
    // 8006EF14: cmpwi   r0, 0
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

label_8006EF18:
    ctx->pc = 0x8006EF18u;
    // 8006EF18: bc    12, 0, 0x8006EF24
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8006EF24;
        }
    }

label_8006EF1C:
    ctx->pc = 0x8006EF1Cu;
    ctx->downcount -= 2;
    // 8006EF1C: cmpwi   r0, 35
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(35);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8006EF20:
    ctx->pc = 0x8006EF20u;
    // 8006EF20: bc    12, 0, 0x8006EF2C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8006EF2C;
        }
    }

label_8006EF24:
    ctx->pc = 0x8006EF24u;
    ctx->downcount -= 2;
    // 8006EF24: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8006EF28:
    ctx->pc = 0x8006EF28u;
    // 8006EF28: b       0x8006EF34
    {
            goto label_8006EF34;
    }

label_8006EF2C:
    ctx->pc = 0x8006EF2Cu;
    ctx->downcount -= 2;
    // 8006EF2C: add   r3, r5, r0
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8006EF30:
    ctx->pc = 0x8006EF30u;
    // 8006EF30: lbz     r0, 180(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(180);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8006EF34:
    ctx->pc = 0x8006EF34u;
    ctx->downcount -= 4;
    // 8006EF34: rlwinm r6, r0, 0, 24, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_8006EF38:
    ctx->pc = 0x8006EF38u;
    // 8006EF38: rlwinm r0, r4, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x000000FFu;
    }

label_8006EF3C:
    ctx->pc = 0x8006EF3Cu;
    // 8006EF3C: cmplwi  r0, 0x000A
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x000Au);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8006EF40:
    ctx->pc = 0x8006EF40u;
    // 8006EF40: bc    12, 1, 0x8006EFA0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8006EFA0;
        }
    }

label_8006EF44:
    ctx->pc = 0x8006EF44u;
    ctx->downcount -= 7;
    // 8006EF44: lis     r3, -32719
    ctx->gpr[3] = ((u32)(s32)(-32719) << 16);

label_8006EF48:
    ctx->pc = 0x8006EF48u;
    // 8006EF48: addi    r3, r3, 360
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(360);

label_8006EF4C:
    ctx->pc = 0x8006EF4Cu;
    // 8006EF4C: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_8006EF50:
    ctx->pc = 0x8006EF50u;
    // 8006EF50: lwzx    r0, r3, r0
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8006EF54:
    ctx->pc = 0x8006EF54u;
    // 8006EF54: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8006EF58:
    ctx->pc = 0x8006EF58u;
    // 8006EF58: bctr
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            return;
        }
    }

label_8006EF5C:
    ctx->pc = 0x8006EF5Cu;
    ctx->downcount -= 1;
    // 8006EF5C: b       0x8006EFA4
    {
            goto label_8006EFA4;
    }

label_8006EF60:
    ctx->pc = 0x8006EF60u;
    ctx->downcount -= 2;
    // 8006EF60: addi    r5, r5, 20
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(20);

label_8006EF64:
    ctx->pc = 0x8006EF64u;
    // 8006EF64: b       0x8006EFA4
    {
            goto label_8006EFA4;
    }

label_8006EF68:
    ctx->pc = 0x8006EF68u;
    ctx->downcount -= 2;
    // 8006EF68: addi    r5, r5, 60
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(60);

label_8006EF6C:
    ctx->pc = 0x8006EF6Cu;
    // 8006EF6C: b       0x8006EFA4
    {
            goto label_8006EFA4;
    }

label_8006EF70:
    ctx->pc = 0x8006EF70u;
    ctx->downcount -= 2;
    // 8006EF70: addi    r5, r5, 100
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(100);

label_8006EF74:
    ctx->pc = 0x8006EF74u;
    // 8006EF74: b       0x8006EFA4
    {
            goto label_8006EFA4;
    }

label_8006EF78:
    ctx->pc = 0x8006EF78u;
    ctx->downcount -= 2;
    // 8006EF78: addi    r5, r5, 80
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(80);

label_8006EF7C:
    ctx->pc = 0x8006EF7Cu;
    // 8006EF7C: b       0x8006EFA4
    {
            goto label_8006EFA4;
    }

label_8006EF80:
    ctx->pc = 0x8006EF80u;
    ctx->downcount -= 2;
    // 8006EF80: addi    r5, r5, 120
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(120);

label_8006EF84:
    ctx->pc = 0x8006EF84u;
    // 8006EF84: b       0x8006EFA4
    {
            goto label_8006EFA4;
    }

label_8006EF88:
    ctx->pc = 0x8006EF88u;
    ctx->downcount -= 2;
    // 8006EF88: addi    r5, r5, 140
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(140);

label_8006EF8C:
    ctx->pc = 0x8006EF8Cu;
    // 8006EF8C: b       0x8006EFA4
    {
            goto label_8006EFA4;
    }

label_8006EF90:
    ctx->pc = 0x8006EF90u;
    ctx->downcount -= 2;
    // 8006EF90: addi    r5, r5, 160
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(160);

label_8006EF94:
    ctx->pc = 0x8006EF94u;
    // 8006EF94: b       0x8006EFA4
    {
            goto label_8006EFA4;
    }

label_8006EF98:
    ctx->pc = 0x8006EF98u;
    ctx->downcount -= 2;
    // 8006EF98: addi    r5, r5, 40
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(40);

label_8006EF9C:
    ctx->pc = 0x8006EF9Cu;
    // 8006EF9C: b       0x8006EFA4
    {
            goto label_8006EFA4;
    }

label_8006EFA0:
    ctx->pc = 0x8006EFA0u;
    ctx->downcount -= 1;
    // 8006EFA0: addi    r5, r5, 40
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(40);

label_8006EFA4:
    ctx->pc = 0x8006EFA4u;
    ctx->downcount -= 3;
    // 8006EFA4: rlwinm r0, r6, 1, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 1u) & 0xFFFFFFFEu;
    }

label_8006EFA8:
    ctx->pc = 0x8006EFA8u;
    // 8006EFA8: lhzx    r3, r5, r0
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[0];
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_8006EFAC:
    ctx->pc = 0x8006EFACu;
    // 8006EFAC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_8006EFB0:
    ctx->pc = 0x8006EFB0u;
    ctx->downcount -= 7;
    // 8006EFB0: stwu     r1, -80(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-80);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8006EFB4:
    ctx->pc = 0x8006EFB4u;
    // 8006EFB4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8006EFB8:
    ctx->pc = 0x8006EFB8u;
    // 8006EFB8: stw     r0, 84(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006EFBC:
    ctx->pc = 0x8006EFBCu;
    // 8006EFBC: stfd     f31, 72(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006EFBCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_8006EFC0:
    ctx->pc = 0x8006EFC0u;
    // 8006EFC0: stfd     f30, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006EFC0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[30]));
    }

label_8006EFC4:
    ctx->pc = 0x8006EFC4u;
    // 8006EFC4: addi    r11, r1, 64
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(64);

label_8006EFC8:
    ctx->pc = 0x8006EFC8u;
    // 8006EFC8: bl      0x80286A4C
    {
            ctx->lr = 0x8006EFCCu;
            ctx->pc = 0x80286A4Cu;
            return;
    }

label_8006EFCC:
    ctx->pc = 0x8006EFCCu;
    ctx->downcount -= 11;
    // 8006EFCC: or   r27, r3, r3
    {
        ctx->gpr[27] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8006EFD0:
    ctx->pc = 0x8006EFD0u;
    // 8006EFD0: or   r28, r4, r4
    {
        ctx->gpr[28] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8006EFD4:
    ctx->pc = 0x8006EFD4u;
    // 8006EFD4: or   r29, r5, r5
    {
        ctx->gpr[29] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8006EFD8:
    ctx->pc = 0x8006EFD8u;
    // 8006EFD8: or   r30, r6, r6
    {
        ctx->gpr[30] = ctx->gpr[6] | ctx->gpr[6];
    }

label_8006EFDC:
    ctx->pc = 0x8006EFDCu;
    // 8006EFDC: or   r31, r7, r7
    {
        ctx->gpr[31] = ctx->gpr[7] | ctx->gpr[7];
    }

label_8006EFE0:
    ctx->pc = 0x8006EFE0u;
    // 8006EFE0: fmr    f30, f1
    if (!ppc_fp_available_inline(ctx, 0x8006EFE0u)) return;
    ctx->fpr[30] = ctx->fpr[1];

label_8006EFE4:
    ctx->pc = 0x8006EFE4u;
    // 8006EFE4: fmr    f31, f2
    if (!ppc_fp_available_inline(ctx, 0x8006EFE4u)) return;
    ctx->fpr[31] = ctx->fpr[2];

label_8006EFE8:
    ctx->pc = 0x8006EFE8u;
    // 8006EFE8: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_8006EFEC:
    ctx->pc = 0x8006EFECu;
    // 8006EFEC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8006EFF0:
    ctx->pc = 0x8006EFF0u;
    // 8006EFF0: li      r5, 28
    ctx->gpr[5] = (u32)(s32)(28);

label_8006EFF4:
    ctx->pc = 0x8006EFF4u;
    // 8006EFF4: bl      0x800033A8
    {
            ctx->lr = 0x8006EFF8u;
            ctx->pc = 0x800033A8u;
            return;
    }

label_8006EFF8:
    ctx->pc = 0x8006EFF8u;
    ctx->downcount -= 5;
    // 8006EFF8: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8006EFFC:
    ctx->pc = 0x8006EFFCu;
    // 8006EFFC: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_8006F000:
    ctx->pc = 0x8006F000u;
    // 8006F000: li      r0, 8
    ctx->gpr[0] = (u32)(s32)(8);

label_8006F004:
    ctx->pc = 0x8006F004u;
    // 8006F004: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8006F008:
    ctx->downcount -= 4;
    // 8006F008: sraw   r0, r28, r6
    {
        u32 sh = ctx->gpr[6] & 0x3Fu;
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

label_8006F00C:
    // 8006F00C: rlwinm r0, r0, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000001u;
    }

label_8006F010:
    // 8006F010: cmpwi   r0, 0
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

label_8006F014:
    // 8006F014: bc    12, 2, 0x8006F038
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8006F038;
        }
    }

label_8006F018:
    ctx->downcount -= 8;
    // 8006F018: extsb r5, r6
    {
        ctx->gpr[5] = (u32)(s32)(s8)ctx->gpr[6];
    }

label_8006F01C:
    ctx->pc = 0x8006F01Cu;
    // 8006F01C: lbz     r0, 35(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(35);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8006F020:
    // 8006F020: extsb r3, r0
    {
        ctx->gpr[3] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8006F024:
    // 8006F024: addi    r0, r3, 19
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(19);

label_8006F028:
    ctx->pc = 0x8006F028u;
    // 8006F028: stbx    r5, r4, r0
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[0];
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

label_8006F02C:
    ctx->pc = 0x8006F02Cu;
    // 8006F02C: lbz     r3, 35(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(35);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8006F030:
    // 8006F030: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8006F034:
    ctx->pc = 0x8006F034u;
    // 8006F034: stb     r0, 35(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(35);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006F038:
    ctx->downcount -= 5;
    // 8006F038: addi    r6, r6, 1
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(1);

label_8006F03C:
    // 8006F03C: sraw   r0, r28, r6
    {
        u32 sh = ctx->gpr[6] & 0x3Fu;
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

label_8006F040:
    // 8006F040: rlwinm r0, r0, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000001u;
    }

label_8006F044:
    // 8006F044: cmpwi   r0, 0
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

label_8006F048:
    // 8006F048: bc    12, 2, 0x8006F06C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8006F06C;
        }
    }

label_8006F04C:
    ctx->downcount -= 8;
    // 8006F04C: extsb r5, r6
    {
        ctx->gpr[5] = (u32)(s32)(s8)ctx->gpr[6];
    }

label_8006F050:
    ctx->pc = 0x8006F050u;
    // 8006F050: lbz     r0, 35(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(35);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8006F054:
    // 8006F054: extsb r3, r0
    {
        ctx->gpr[3] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8006F058:
    // 8006F058: addi    r0, r3, 19
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(19);

label_8006F05C:
    ctx->pc = 0x8006F05Cu;
    // 8006F05C: stbx    r5, r4, r0
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[0];
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

label_8006F060:
    ctx->pc = 0x8006F060u;
    // 8006F060: lbz     r3, 35(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(35);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8006F064:
    // 8006F064: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8006F068:
    ctx->pc = 0x8006F068u;
    // 8006F068: stb     r0, 35(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(35);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006F06C:
    ctx->downcount -= 5;
    // 8006F06C: addi    r6, r6, 1
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(1);

label_8006F070:
    // 8006F070: sraw   r0, r28, r6
    {
        u32 sh = ctx->gpr[6] & 0x3Fu;
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

label_8006F074:
    // 8006F074: rlwinm r0, r0, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000001u;
    }

label_8006F078:
    // 8006F078: cmpwi   r0, 0
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

label_8006F07C:
    // 8006F07C: bc    12, 2, 0x8006F0A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8006F0A0;
        }
    }

label_8006F080:
    ctx->downcount -= 8;
    // 8006F080: extsb r5, r6
    {
        ctx->gpr[5] = (u32)(s32)(s8)ctx->gpr[6];
    }

label_8006F084:
    ctx->pc = 0x8006F084u;
    // 8006F084: lbz     r0, 35(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(35);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8006F088:
    // 8006F088: extsb r3, r0
    {
        ctx->gpr[3] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8006F08C:
    // 8006F08C: addi    r0, r3, 19
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(19);

label_8006F090:
    ctx->pc = 0x8006F090u;
    // 8006F090: stbx    r5, r4, r0
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[0];
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

label_8006F094:
    ctx->pc = 0x8006F094u;
    // 8006F094: lbz     r3, 35(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(35);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8006F098:
    // 8006F098: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8006F09C:
    ctx->pc = 0x8006F09Cu;
    // 8006F09C: stb     r0, 35(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(35);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006F0A0:
    ctx->downcount -= 5;
    // 8006F0A0: addi    r6, r6, 1
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(1);

label_8006F0A4:
    // 8006F0A4: sraw   r0, r28, r6
    {
        u32 sh = ctx->gpr[6] & 0x3Fu;
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

label_8006F0A8:
    // 8006F0A8: rlwinm r0, r0, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000001u;
    }

label_8006F0AC:
    // 8006F0AC: cmpwi   r0, 0
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

label_8006F0B0:
    // 8006F0B0: bc    12, 2, 0x8006F0D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8006F0D4;
        }
    }

label_8006F0B4:
    ctx->downcount -= 8;
    // 8006F0B4: extsb r5, r6
    {
        ctx->gpr[5] = (u32)(s32)(s8)ctx->gpr[6];
    }

label_8006F0B8:
    ctx->pc = 0x8006F0B8u;
    // 8006F0B8: lbz     r0, 35(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(35);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8006F0BC:
    // 8006F0BC: extsb r3, r0
    {
        ctx->gpr[3] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8006F0C0:
    // 8006F0C0: addi    r0, r3, 19
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(19);

label_8006F0C4:
    ctx->pc = 0x8006F0C4u;
    // 8006F0C4: stbx    r5, r4, r0
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[0];
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

label_8006F0C8:
    ctx->pc = 0x8006F0C8u;
    // 8006F0C8: lbz     r3, 35(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(35);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8006F0CC:
    // 8006F0CC: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8006F0D0:
    ctx->pc = 0x8006F0D0u;
    // 8006F0D0: stb     r0, 35(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(35);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006F0D4:
    ctx->downcount -= 2;
    // 8006F0D4: addi    r6, r6, 1
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(1);

label_8006F0D8:
    // 8006F0D8: bc    16, 0, 0x8006F008
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8006F008u;
                return;
            }
            goto label_8006F008;
        }
    }

label_8006F0DC:
    ctx->pc = 0x8006F0DCu;
    ctx->downcount -= 8;
    // 8006F0DC: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8006F0E0:
    ctx->pc = 0x8006F0E0u;
    // 8006F0E0: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_8006F0E4:
    ctx->pc = 0x8006F0E4u;
    // 8006F0E4: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8006F0E8:
    ctx->pc = 0x8006F0E8u;
    // 8006F0E8: or   r6, r30, r30
    {
        ctx->gpr[6] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8006F0EC:
    ctx->pc = 0x8006F0ECu;
    // 8006F0EC: or   r7, r31, r31
    {
        ctx->gpr[7] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8006F0F0:
    ctx->pc = 0x8006F0F0u;
    // 8006F0F0: fmr    f1, f30
    if (!ppc_fp_available_inline(ctx, 0x8006F0F0u)) return;
    ctx->fpr[1] = ctx->fpr[30];

label_8006F0F4:
    ctx->pc = 0x8006F0F4u;
    // 8006F0F4: fmr    f2, f31
    if (!ppc_fp_available_inline(ctx, 0x8006F0F4u)) return;
    ctx->fpr[2] = ctx->fpr[31];

label_8006F0F8:
    ctx->pc = 0x8006F0F8u;
    // 8006F0F8: bl      0x8006F11C
    {
            ctx->lr = 0x8006F0FCu;
            goto label_8006F11C;
    }

label_8006F0FC:
    ctx->pc = 0x8006F0FCu;
    ctx->downcount -= 4;
    // 8006F0FC: lfd     f31, 72(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006F0FCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006F100:
    ctx->pc = 0x8006F100u;
    // 8006F100: lfd     f30, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006F100u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        ctx->fpr[30] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006F104:
    ctx->pc = 0x8006F104u;
    // 8006F104: addi    r11, r1, 64
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(64);

label_8006F108:
    ctx->pc = 0x8006F108u;
    // 8006F108: bl      0x80286A98
    {
            ctx->lr = 0x8006F10Cu;
            ctx->pc = 0x80286A98u;
            return;
    }

label_8006F10C:
    ctx->pc = 0x8006F10Cu;
    ctx->downcount -= 5;
    // 8006F10C: lwz     r0, 84(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8006F110:
    ctx->pc = 0x8006F110u;
    // 8006F110: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8006F114:
    ctx->pc = 0x8006F114u;
    // 8006F114: addi    r1, r1, 80
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(80);

label_8006F118:
    ctx->pc = 0x8006F118u;
    // 8006F118: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_8006F11C:
    ctx->pc = 0x8006F11Cu;
    ctx->downcount -= 7;
    // 8006F11C: stwu     r1, -96(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-96);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8006F120:
    ctx->pc = 0x8006F120u;
    // 8006F120: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8006F124:
    ctx->pc = 0x8006F124u;
    // 8006F124: stw     r0, 100(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(100);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006F128:
    ctx->pc = 0x8006F128u;
    // 8006F128: stfd     f31, 80(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006F128u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_8006F12C:
    ctx->pc = 0x8006F12Cu;
    // 8006F12C: psq_st   f31, 88(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8006F12Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        ppc_psq_store_inline(ctx, 31u, ea, false, 0u, false, 0x8006F12Cu);
        if (ctx->exception) return;
    }

label_8006F130:
    ctx->pc = 0x8006F130u;
    // 8006F130: addi    r11, r1, 80
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(80);

label_8006F134:
    ctx->pc = 0x8006F134u;
    // 8006F134: bl      0x80286A44
    {
            ctx->lr = 0x8006F138u;
            ctx->pc = 0x80286A44u;
            return;
    }

label_8006F138:
    ctx->pc = 0x8006F138u;
    ctx->downcount -= 8;
    // 8006F138: or   r26, r3, r3
    {
        ctx->gpr[26] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8006F13C:
    ctx->pc = 0x8006F13Cu;
    // 8006F13C: or   r27, r6, r6
    {
        ctx->gpr[27] = ctx->gpr[6] | ctx->gpr[6];
    }

label_8006F140:
    ctx->pc = 0x8006F140u;
    // 8006F140: fmr    f31, f2
    if (!ppc_fp_available_inline(ctx, 0x8006F140u)) return;
    ctx->fpr[31] = ctx->fpr[2];

label_8006F144:
    ctx->pc = 0x8006F144u;
    // 8006F144: lis     r3, -32719
    ctx->gpr[3] = ((u32)(s32)(-32719) << 16);

label_8006F148:
    ctx->pc = 0x8006F148u;
    // 8006F148: addi    r3, r3, 144
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(144);

label_8006F14C:
    ctx->pc = 0x8006F14Cu;
    // 8006F14C: rlwinm r8, r5, 0, 24, 31
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x000000FFu;
    }

label_8006F150:
    ctx->pc = 0x8006F150u;
    // 8006F150: cmplwi  r8, 0x000A
    {
        u32 val_a = (u32)(ctx->gpr[8]);
        u32 val_b = (u32)(0x000Au);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8006F154:
    ctx->pc = 0x8006F154u;
    // 8006F154: bc    12, 1, 0x8006F1B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8006F1B8;
        }
    }

label_8006F158:
    ctx->pc = 0x8006F158u;
    ctx->downcount -= 7;
    // 8006F158: lis     r5, -32719
    ctx->gpr[5] = ((u32)(s32)(-32719) << 16);

label_8006F15C:
    ctx->pc = 0x8006F15Cu;
    // 8006F15C: addi    r6, r5, 404
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(404);

label_8006F160:
    ctx->pc = 0x8006F160u;
    // 8006F160: rlwinm r5, r8, 2, 0, 29
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[8], 2u) & 0xFFFFFFFCu;
    }

label_8006F164:
    ctx->pc = 0x8006F164u;
    // 8006F164: lwzx    r5, r6, r5
    {
        u32 ea = ctx->gpr[6] + ctx->gpr[5];
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8006F168:
    ctx->pc = 0x8006F168u;
    // 8006F168: mtctr    r5
    ctx->ctr = ctx->gpr[5];

label_8006F16C:
    ctx->pc = 0x8006F16Cu;
    // 8006F16C: bctr
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            return;
        }
    }

label_8006F170:
    ctx->pc = 0x8006F170u;
    ctx->downcount -= 2;
    // 8006F170: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8006F174:
    ctx->pc = 0x8006F174u;
    // 8006F174: b       0x8006F1BC
    {
            goto label_8006F1BC;
    }

label_8006F178:
    ctx->pc = 0x8006F178u;
    ctx->downcount -= 2;
    // 8006F178: addi    r31, r3, 20
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(20);

label_8006F17C:
    ctx->pc = 0x8006F17Cu;
    // 8006F17C: b       0x8006F1BC
    {
            goto label_8006F1BC;
    }

label_8006F180:
    ctx->pc = 0x8006F180u;
    ctx->downcount -= 2;
    // 8006F180: addi    r31, r3, 60
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(60);

label_8006F184:
    ctx->pc = 0x8006F184u;
    // 8006F184: b       0x8006F1BC
    {
            goto label_8006F1BC;
    }

label_8006F188:
    ctx->pc = 0x8006F188u;
    ctx->downcount -= 2;
    // 8006F188: addi    r31, r3, 100
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(100);

label_8006F18C:
    ctx->pc = 0x8006F18Cu;
    // 8006F18C: b       0x8006F1BC
    {
            goto label_8006F1BC;
    }

label_8006F190:
    ctx->pc = 0x8006F190u;
    ctx->downcount -= 2;
    // 8006F190: addi    r31, r3, 80
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(80);

label_8006F194:
    ctx->pc = 0x8006F194u;
    // 8006F194: b       0x8006F1BC
    {
            goto label_8006F1BC;
    }

label_8006F198:
    ctx->pc = 0x8006F198u;
    ctx->downcount -= 2;
    // 8006F198: addi    r31, r3, 120
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(120);

label_8006F19C:
    ctx->pc = 0x8006F19Cu;
    // 8006F19C: b       0x8006F1BC
    {
            goto label_8006F1BC;
    }

label_8006F1A0:
    ctx->pc = 0x8006F1A0u;
    ctx->downcount -= 2;
    // 8006F1A0: addi    r31, r3, 140
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(140);

label_8006F1A4:
    ctx->pc = 0x8006F1A4u;
    // 8006F1A4: b       0x8006F1BC
    {
            goto label_8006F1BC;
    }

label_8006F1A8:
    ctx->pc = 0x8006F1A8u;
    ctx->downcount -= 2;
    // 8006F1A8: addi    r31, r3, 160
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(160);

label_8006F1AC:
    ctx->pc = 0x8006F1ACu;
    // 8006F1AC: b       0x8006F1BC
    {
            goto label_8006F1BC;
    }

label_8006F1B0:
    ctx->pc = 0x8006F1B0u;
    ctx->downcount -= 2;
    // 8006F1B0: addi    r31, r3, 40
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(40);

label_8006F1B4:
    ctx->pc = 0x8006F1B4u;
    // 8006F1B4: b       0x8006F1BC
    {
            goto label_8006F1BC;
    }

label_8006F1B8:
    ctx->pc = 0x8006F1B8u;
    ctx->downcount -= 1;
    // 8006F1B8: addi    r31, r3, 40
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(40);

label_8006F1BC:
    ctx->pc = 0x8006F1BCu;
    ctx->downcount -= 5;
    // 8006F1BC: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_8006F1C0:
    ctx->pc = 0x8006F1C0u;
    // 8006F1C0: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_8006F1C4:
    ctx->pc = 0x8006F1C4u;
    // 8006F1C4: lbz     r6, 27(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(27);
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_8006F1C8:
    ctx->pc = 0x8006F1C8u;
    // 8006F1C8: extsb r6, r6
    {
        ctx->gpr[6] = (u32)(s32)(s8)ctx->gpr[6];
    }

label_8006F1CC:
    ctx->pc = 0x8006F1CCu;
    // 8006F1CC: b       0x8006F248
    {
            goto label_8006F248;
    }

label_8006F1D0:
    ctx->downcount -= 6;
    // 8006F1D0: rlwinm r5, r29, 0, 24, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[29], 0u) & 0x000000FFu;
    }

label_8006F1D4:
    // 8006F1D4: addi    r5, r5, 19
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(19);

label_8006F1D8:
    ctx->pc = 0x8006F1D8u;
    // 8006F1D8: lbzx    r5, r4, r5
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[5];
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_8006F1DC:
    // 8006F1DC: extsb r5, r5
    {
        ctx->gpr[5] = (u32)(s32)(s8)ctx->gpr[5];
    }

label_8006F1E0:
    // 8006F1E0: cmpwi   r5, 3
    {
        s32 val_a = (s32)(ctx->gpr[5]);
        s32 val_b = (s32)(3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8006F1E4:
    // 8006F1E4: bc    12, 2, 0x8006F228
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8006F228;
        }
    }

label_8006F1E8:
    ctx->downcount -= 1;
    // 8006F1E8: bc    4, 0, 0x8006F1FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8006F1FC;
        }
    }

label_8006F1EC:
    ctx->downcount -= 2;
    // 8006F1EC: cmpwi   r5, 1
    {
        s32 val_a = (s32)(ctx->gpr[5]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8006F1F0:
    // 8006F1F0: bc    12, 2, 0x8006F208
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8006F208;
        }
    }

label_8006F1F4:
    ctx->downcount -= 1;
    // 8006F1F4: bc    4, 0, 0x8006F218
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8006F218;
        }
    }

label_8006F1F8:
    ctx->downcount -= 1;
    // 8006F1F8: b       0x8006F244
    {
            goto label_8006F244;
    }

label_8006F1FC:
    ctx->downcount -= 2;
    // 8006F1FC: cmpwi   r5, 5
    {
        s32 val_a = (s32)(ctx->gpr[5]);
        s32 val_b = (s32)(5);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8006F200:
    // 8006F200: bc    4, 0, 0x8006F244
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8006F244;
        }
    }

label_8006F204:
    ctx->downcount -= 1;
    // 8006F204: b       0x8006F238
    {
            goto label_8006F238;
    }

label_8006F208:
    ctx->downcount -= 4;
    // 8006F208: ori     r0, r30, 0x0001
    ctx->gpr[0] = ctx->gpr[30] | 0x0001u;

label_8006F20C:
    // 8006F20C: rlwinm r30, r0, 0, 24, 31
    {
        ctx->gpr[30] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_8006F210:
    // 8006F210: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8006F214:
    // 8006F214: b       0x8006F244
    {
            goto label_8006F244;
    }

label_8006F218:
    ctx->downcount -= 4;
    // 8006F218: ori     r0, r30, 0x0002
    ctx->gpr[0] = ctx->gpr[30] | 0x0002u;

label_8006F21C:
    // 8006F21C: rlwinm r30, r0, 0, 24, 31
    {
        ctx->gpr[30] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_8006F220:
    // 8006F220: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8006F224:
    // 8006F224: b       0x8006F244
    {
            goto label_8006F244;
    }

label_8006F228:
    ctx->downcount -= 4;
    // 8006F228: ori     r0, r30, 0x0004
    ctx->gpr[0] = ctx->gpr[30] | 0x0004u;

label_8006F22C:
    // 8006F22C: rlwinm r30, r0, 0, 24, 31
    {
        ctx->gpr[30] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_8006F230:
    // 8006F230: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_8006F234:
    // 8006F234: b       0x8006F244
    {
            goto label_8006F244;
    }

label_8006F238:
    ctx->downcount -= 3;
    // 8006F238: ori     r0, r30, 0x0008
    ctx->gpr[0] = ctx->gpr[30] | 0x0008u;

label_8006F23C:
    // 8006F23C: rlwinm r30, r0, 0, 24, 31
    {
        ctx->gpr[30] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_8006F240:
    // 8006F240: li      r0, 3
    ctx->gpr[0] = (u32)(s32)(3);

label_8006F244:
    ctx->downcount -= 1;
    // 8006F244: addi    r29, r29, 1
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(1);

label_8006F248:
    ctx->downcount -= 3;
    // 8006F248: rlwinm r5, r29, 0, 24, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[29], 0u) & 0x000000FFu;
    }

label_8006F24C:
    // 8006F24C: cmpw    r5, r6
    {
        s32 val_a = (s32)(ctx->gpr[5]);
        s32 val_b = (s32)(ctx->gpr[6]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8006F250:
    // 8006F250: bc    12, 0, 0x8006F1D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8006F1D0u;
                return;
            }
            goto label_8006F1D0;
        }
    }

label_8006F254:
    ctx->pc = 0x8006F254u;
    ctx->downcount -= 3;
    // 8006F254: rlwinm r4, r30, 0, 24, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[30], 0u) & 0x000000FFu;
    }

label_8006F258:
    ctx->pc = 0x8006F258u;
    // 8006F258: cmplwi  r4, 0x0000
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

label_8006F25C:
    ctx->pc = 0x8006F25Cu;
    // 8006F25C: bc    12, 2, 0x8006F54C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8006F54C;
        }
    }

label_8006F260:
    ctx->pc = 0x8006F260u;
    ctx->downcount -= 5;
    // 8006F260: lbz     r4, 608(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(608);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_8006F264:
    ctx->pc = 0x8006F264u;
    // 8006F264: extsb r4, r4
    {
        ctx->gpr[4] = (u32)(s32)(s8)ctx->gpr[4];
    }

label_8006F268:
    ctx->pc = 0x8006F268u;
    // 8006F268: rlwinm r4, r4, 0, 27, 27
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x00000010u;
    }

label_8006F26C:
    ctx->pc = 0x8006F26Cu;
    // 8006F26C: cmpwi   r4, 0
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

label_8006F270:
    ctx->pc = 0x8006F270u;
    // 8006F270: bc    4, 2, 0x8006F284
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8006F284;
        }
    }

label_8006F274:
    ctx->pc = 0x8006F274u;
    ctx->downcount -= 4;
    // 8006F274: lbz     r4, 603(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(603);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_8006F278:
    ctx->pc = 0x8006F278u;
    // 8006F278: extsb r4, r4
    {
        ctx->gpr[4] = (u32)(s32)(s8)ctx->gpr[4];
    }

label_8006F27C:
    ctx->pc = 0x8006F27Cu;
    // 8006F27C: cmpwi   r4, 0
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

label_8006F280:
    ctx->pc = 0x8006F280u;
    // 8006F280: bc    4, 2, 0x8006F54C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8006F54C;
        }
    }

label_8006F284:
    ctx->pc = 0x8006F284u;
    ctx->downcount -= 4;
    // 8006F284: lbz     r4, 184(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(184);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_8006F288:
    ctx->pc = 0x8006F288u;
    // 8006F288: extsb r4, r4
    {
        ctx->gpr[4] = (u32)(s32)(s8)ctx->gpr[4];
    }

label_8006F28C:
    ctx->pc = 0x8006F28Cu;
    // 8006F28C: cmpwi   r4, 0
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

label_8006F290:
    ctx->pc = 0x8006F290u;
    // 8006F290: bc    12, 0, 0x8006F29C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8006F29C;
        }
    }

label_8006F294:
    ctx->pc = 0x8006F294u;
    ctx->downcount -= 2;
    // 8006F294: cmpwi   r4, 35
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(35);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8006F298:
    ctx->pc = 0x8006F298u;
    // 8006F298: bc    12, 0, 0x8006F2A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8006F2A4;
        }
    }

label_8006F29C:
    ctx->pc = 0x8006F29Cu;
    ctx->downcount -= 2;
    // 8006F29C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8006F2A0:
    ctx->pc = 0x8006F2A0u;
    // 8006F2A0: b       0x8006F2AC
    {
            goto label_8006F2AC;
    }

label_8006F2A4:
    ctx->pc = 0x8006F2A4u;
    ctx->downcount -= 2;
    // 8006F2A4: add   r3, r3, r4
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8006F2A8:
    ctx->pc = 0x8006F2A8u;
    // 8006F2A8: lbz     r3, 180(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(180);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8006F2AC:
    ctx->pc = 0x8006F2ACu;
    ctx->downcount -= 4;
    // 8006F2AC: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8006F2B0:
    ctx->pc = 0x8006F2B0u;
    // 8006F2B0: lwz     r3, 196(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(196);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8006F2B4:
    ctx->pc = 0x8006F2B4u;
    // 8006F2B4: cmplwi  r3, 0x0000
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

label_8006F2B8:
    ctx->pc = 0x8006F2B8u;
    // 8006F2B8: bc    12, 2, 0x8006F2F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8006F2F4;
        }
    }

label_8006F2BC:
    ctx->pc = 0x8006F2BCu;
    ctx->downcount -= 3;
    // 8006F2BC: lha     r3, 70(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(70);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8006F2C0:
    ctx->pc = 0x8006F2C0u;
    // 8006F2C0: cmpwi   r3, 475
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(475);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8006F2C4:
    ctx->pc = 0x8006F2C4u;
    // 8006F2C4: bc    12, 2, 0x8006F2F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8006F2F0;
        }
    }

label_8006F2C8:
    ctx->pc = 0x8006F2C8u;
    ctx->downcount -= 1;
    // 8006F2C8: bc    4, 0, 0x8006F2E4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8006F2E4;
        }
    }

label_8006F2CC:
    ctx->pc = 0x8006F2CCu;
    ctx->downcount -= 2;
    // 8006F2CC: cmpwi   r3, 153
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(153);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8006F2D0:
    ctx->pc = 0x8006F2D0u;
    // 8006F2D0: bc    12, 2, 0x8006F2F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8006F2F0;
        }
    }

label_8006F2D4:
    ctx->pc = 0x8006F2D4u;
    ctx->downcount -= 1;
    // 8006F2D4: bc    4, 0, 0x8006F2F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8006F2F4;
        }
    }

label_8006F2D8:
    ctx->pc = 0x8006F2D8u;
    ctx->downcount -= 2;
    // 8006F2D8: cmpwi   r3, 93
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(93);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8006F2DC:
    ctx->pc = 0x8006F2DCu;
    // 8006F2DC: bc    12, 2, 0x8006F2F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8006F2F0;
        }
    }

label_8006F2E0:
    ctx->pc = 0x8006F2E0u;
    ctx->downcount -= 1;
    // 8006F2E0: b       0x8006F2F4
    {
            goto label_8006F2F4;
    }

label_8006F2E4:
    ctx->pc = 0x8006F2E4u;
    ctx->downcount -= 2;
    // 8006F2E4: cmpwi   r3, 547
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(547);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8006F2E8:
    ctx->pc = 0x8006F2E8u;
    // 8006F2E8: bc    12, 2, 0x8006F2F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8006F2F0;
        }
    }

label_8006F2EC:
    ctx->pc = 0x8006F2ECu;
    ctx->downcount -= 1;
    // 8006F2EC: b       0x8006F2F4
    {
            goto label_8006F2F4;
    }

label_8006F2F0:
    ctx->pc = 0x8006F2F0u;
    ctx->downcount -= 1;
    // 8006F2F0: li      r28, 4
    ctx->gpr[28] = (u32)(s32)(4);

label_8006F2F4:
    ctx->pc = 0x8006F2F4u;
    ctx->downcount -= 2;
    // 8006F2F4: cmplwi  r31, 0x0000
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

label_8006F2F8:
    ctx->pc = 0x8006F2F8u;
    // 8006F2F8: bc    12, 2, 0x8006F398
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8006F398;
        }
    }

label_8006F2FC:
    ctx->pc = 0x8006F2FCu;
    ctx->downcount -= 9;
    // 8006F2FC: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_8006F300:
    ctx->pc = 0x8006F300u;
    // 8006F300: mulli   r0, r0, 12
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)12);

label_8006F304:
    ctx->pc = 0x8006F304u;
    // 8006F304: add   r25, r27, r0
    {
        u32 a = ctx->gpr[27];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[25] = res;
    }

label_8006F308:
    ctx->pc = 0x8006F308u;
    // 8006F308: lfs     f2, 436(r7)
    if (!ppc_fp_available_inline(ctx, 0x8006F308u)) return;
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(436);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8006F30C:
    ctx->pc = 0x8006F30Cu;
    // 8006F30C: lfs     f0, -30424(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006F30Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30424);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8006F310:
    ctx->pc = 0x8006F310u;
    // 8006F310: fcmpo   cr0, f2, f0
    if (!ppc_fp_available_inline(ctx, 0x8006F310u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[2], ctx->fpr[0], true);

label_8006F314:
    ctx->pc = 0x8006F314u;
    // 8006F314: bc    4, 1, 0x8006F340
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8006F340;
        }
    }

label_8006F318:
    ctx->pc = 0x8006F318u;
    ctx->downcount -= 10;
    // 8006F318: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8006F31C:
    ctx->pc = 0x8006F31Cu;
    // 8006F31C: rlwinm r4, r30, 0, 24, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[30], 0u) & 0x000000FFu;
    }

label_8006F320:
    ctx->pc = 0x8006F320u;
    // 8006F320: or   r5, r27, r27
    {
        ctx->gpr[5] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8006F324:
    ctx->pc = 0x8006F324u;
    // 8006F324: or   r6, r7, r7
    {
        ctx->gpr[6] = ctx->gpr[7] | ctx->gpr[7];
    }

label_8006F328:
    ctx->pc = 0x8006F328u;
    // 8006F328: lwz     r7, -26344(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26344);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8006F32C:
    ctx->pc = 0x8006F32Cu;
    // 8006F32C: lwz     r7, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8006F330:
    ctx->pc = 0x8006F330u;
    // 8006F330: lwz     r12, 8(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(8);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_8006F334:
    ctx->pc = 0x8006F334u;
    // 8006F334: mtctr    r12
    ctx->ctr = ctx->gpr[12];

label_8006F338:
    ctx->pc = 0x8006F338u;
    // 8006F338: bctrl
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8006F33Cu;
            ctx->pc = target;
            return;
        }
    }

label_8006F33C:
    ctx->pc = 0x8006F33Cu;
    ctx->downcount -= 1;
    // 8006F33C: li      r28, 5
    ctx->gpr[28] = (u32)(s32)(5);

label_8006F340:
    ctx->pc = 0x8006F340u;
    ctx->downcount -= 1;
    // 8006F340: bl      0x8002BB60
    {
            ctx->lr = 0x8006F344u;
            ctx->pc = 0x8002BB60u;
            return;
    }

label_8006F344:
    ctx->pc = 0x8006F344u;
    ctx->downcount -= 2;
    // 8006F344: cmplw   r26, r3
    {
        u32 val_a = (u32)(ctx->gpr[26]);
        u32 val_b = (u32)(ctx->gpr[3]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8006F348:
    ctx->pc = 0x8006F348u;
    // 8006F348: bc    4, 2, 0x8006F37C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8006F37C;
        }
    }

label_8006F34C:
    ctx->pc = 0x8006F34Cu;
    ctx->downcount -= 4;
    // 8006F34C: lwz     r3, 184(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(184);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8006F350:
    ctx->pc = 0x8006F350u;
    // 8006F350: lha     r0, 2074(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2074);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8006F354:
    ctx->pc = 0x8006F354u;
    // 8006F354: cmpwi   r0, 1
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

label_8006F358:
    ctx->pc = 0x8006F358u;
    // 8006F358: bc    4, 2, 0x8006F368
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8006F368;
        }
    }

label_8006F35C:
    ctx->pc = 0x8006F35Cu;
    ctx->downcount -= 3;
    // 8006F35C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8006F360:
    ctx->pc = 0x8006F360u;
    // 8006F360: li      r4, 962
    ctx->gpr[4] = (u32)(s32)(962);

label_8006F364:
    ctx->pc = 0x8006F364u;
    // 8006F364: bl      0x8000BB38
    {
            ctx->lr = 0x8006F368u;
            ctx->pc = 0x8000BB38u;
            return;
    }

label_8006F368:
    ctx->pc = 0x8006F368u;
    ctx->downcount -= 4;
    // 8006F368: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8006F36C:
    ctx->pc = 0x8006F36Cu;
    // 8006F36C: rlwinm r0, r28, 1, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[28], 1u) & 0xFFFFFFFEu;
    }

label_8006F370:
    ctx->pc = 0x8006F370u;
    // 8006F370: lhzx    r4, r31, r0
    {
        u32 ea = ctx->gpr[31] + ctx->gpr[0];
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_8006F374:
    ctx->pc = 0x8006F374u;
    // 8006F374: bl      0x8000BB38
    {
            ctx->lr = 0x8006F378u;
            ctx->pc = 0x8000BB38u;
            return;
    }

label_8006F378:
    ctx->pc = 0x8006F378u;
    ctx->downcount -= 1;
    // 8006F378: b       0x8006F398
    {
            goto label_8006F398;
    }

label_8006F37C:
    ctx->pc = 0x8006F37Cu;
    ctx->downcount -= 7;
    // 8006F37C: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8006F380:
    ctx->pc = 0x8006F380u;
    // 8006F380: lfs     f1, 0(r25)
    if (!ppc_fp_available_inline(ctx, 0x8006F380u)) return;
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(0);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8006F384:
    ctx->pc = 0x8006F384u;
    // 8006F384: lfs     f2, 4(r25)
    if (!ppc_fp_available_inline(ctx, 0x8006F384u)) return;
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8006F388:
    ctx->pc = 0x8006F388u;
    // 8006F388: lfs     f3, 8(r25)
    if (!ppc_fp_available_inline(ctx, 0x8006F388u)) return;
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8006F38C:
    ctx->pc = 0x8006F38Cu;
    // 8006F38C: rlwinm r0, r28, 1, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[28], 1u) & 0xFFFFFFFEu;
    }

label_8006F390:
    ctx->pc = 0x8006F390u;
    // 8006F390: lhzx    r4, r31, r0
    {
        u32 ea = ctx->gpr[31] + ctx->gpr[0];
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_8006F394:
    ctx->pc = 0x8006F394u;
    // 8006F394: bl      0x8000BB00
    {
            ctx->lr = 0x8006F398u;
            ctx->pc = 0x8000BB00u;
            return;
    }

label_8006F398:
    ctx->pc = 0x8006F398u;
    ctx->downcount -= 3;
    // 8006F398: rlwinm r0, r29, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[29], 0u) & 0x000000FFu;
    }

label_8006F39C:
    ctx->pc = 0x8006F39Cu;
    // 8006F39C: cmplwi  r0, 0x0005
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0005u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8006F3A0:
    ctx->pc = 0x8006F3A0u;
    // 8006F3A0: bc    12, 2, 0x8006F54C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8006F54C;
        }
    }

label_8006F3A4:
    ctx->pc = 0x8006F3A4u;
    ctx->downcount -= 4;
    // 8006F3A4: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_8006F3A8:
    ctx->pc = 0x8006F3A8u;
    // 8006F3A8: lfs     f0, -30420(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006F3A8u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30420);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8006F3AC:
    ctx->pc = 0x8006F3ACu;
    // 8006F3AC: fmuls   f31, f0, f31
    if (!ppc_fp_available_inline(ctx, 0x8006F3ACu)) return;
    ppc_fmuls(ctx, 31, 0, 31);

label_8006F3B0:
    ctx->pc = 0x8006F3B0u;
    // 8006F3B0: b       0x8006F540
    {
            goto label_8006F540;
    }

label_8006F3B4:
    ctx->downcount -= 15;
    // 8006F3B4: rlwinm r0, r31, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[31], 0u) & 0x000000FFu;
    }

label_8006F3B8:
    // 8006F3B8: mulli   r0, r0, 12
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)12);

label_8006F3BC:
    // 8006F3BC: add   r29, r27, r0
    {
        u32 a = ctx->gpr[27];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[29] = res;
    }

label_8006F3C0:
    ctx->pc = 0x8006F3C0u;
    // 8006F3C0: lfs     f0, 0(r29)
    if (!ppc_fp_available_inline(ctx, 0x8006F3C0u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8006F3C4:
    ctx->pc = 0x8006F3C4u;
    // 8006F3C4: stfs     f0, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006F3C4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8006F3C8:
    ctx->pc = 0x8006F3C8u;
    // 8006F3C8: lfs     f0, 4(r29)
    if (!ppc_fp_available_inline(ctx, 0x8006F3C8u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8006F3CC:
    ctx->pc = 0x8006F3CCu;
    // 8006F3CC: stfs     f0, 12(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006F3CCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8006F3D0:
    ctx->pc = 0x8006F3D0u;
    // 8006F3D0: lfs     f0, 8(r29)
    if (!ppc_fp_available_inline(ctx, 0x8006F3D0u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8006F3D4:
    ctx->pc = 0x8006F3D4u;
    // 8006F3D4: stfs     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006F3D4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8006F3D8:
    // 8006F3D8: rlwinm r0, r30, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[30], 0u) & 0x000000FFu;
    }

label_8006F3DC:
    // 8006F3DC: rlwinm r0, r0, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000001u;
    }

label_8006F3E0:
    // 8006F3E0: cmpwi   r0, 0
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

label_8006F3E4:
    // 8006F3E4: bc    12, 2, 0x8006F530
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8006F530;
        }
    }

label_8006F3E8:
    ctx->pc = 0x8006F3E8u;
    ctx->downcount -= 3;
    // 8006F3E8: lha     r0, 68(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(68);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8006F3EC:
    // 8006F3EC: cmpwi   r0, 1
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

label_8006F3F0:
    // 8006F3F0: bc    12, 2, 0x8006F400
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8006F400;
        }
    }

label_8006F3F4:
    ctx->pc = 0x8006F3F4u;
    ctx->downcount -= 3;
    // 8006F3F4: lha     r0, 70(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(70);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8006F3F8:
    // 8006F3F8: cmpwi   r0, 1046
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(1046);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8006F3FC:
    // 8006F3FC: bc    4, 2, 0x8006F414
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8006F414;
        }
    }

label_8006F400:
    ctx->downcount -= 5;
    // 8006F400: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8006F404:
    // 8006F404: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_8006F408:
    // 8006F408: rlwinm r5, r31, 0, 31, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[31], 0u) & 0x00000001u;
    }

label_8006F40C:
    // 8006F40C: rlwinm r6, r28, 0, 24, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[28], 0u) & 0x000000FFu;
    }

label_8006F410:
    // 8006F410: bl      0x8006FB34
    {
            ctx->lr = 0x8006F414u;
            goto label_8006FB34;
    }

label_8006F414:
    ctx->pc = 0x8006F414u;
    ctx->downcount -= 24;
    // 8006F414: lfs     f0, 0(r29)
    if (!ppc_fp_available_inline(ctx, 0x8006F414u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8006F418:
    ctx->pc = 0x8006F418u;
    // 8006F418: stfs     f0, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006F418u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8006F41C:
    ctx->pc = 0x8006F41Cu;
    // 8006F41C: lfs     f0, 4(r29)
    if (!ppc_fp_available_inline(ctx, 0x8006F41Cu)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8006F420:
    ctx->pc = 0x8006F420u;
    // 8006F420: stfs     f0, 36(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006F420u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8006F424:
    ctx->pc = 0x8006F424u;
    // 8006F424: lfs     f0, 8(r29)
    if (!ppc_fp_available_inline(ctx, 0x8006F424u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8006F428:
    ctx->pc = 0x8006F428u;
    // 8006F428: stfs     f0, 40(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006F428u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8006F42C:
    ctx->pc = 0x8006F42Cu;
    // 8006F42C: stfs     f31, 28(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006F42Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8006F430:
    // 8006F430: extsh r0, r28
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[28];
    }

label_8006F434:
    ctx->pc = 0x8006F434u;
    // 8006F434: sth     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8006F438:
    // 8006F438: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8006F43C:
    ctx->pc = 0x8006F43Cu;
    // 8006F43C: sth     r0, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8006F440:
    ctx->pc = 0x8006F440u;
    // 8006F440: sth     r0, 22(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(22);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8006F444:
    ctx->pc = 0x8006F444u;
    // 8006F444: lfs     f1, -30416(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006F444u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30416);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8006F448:
    ctx->pc = 0x8006F448u;
    // 8006F448: lfs     f0, 36(r26)
    if (!ppc_fp_available_inline(ctx, 0x8006F448u)) return;
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(36);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8006F44C:
    ctx->pc = 0x8006F44Cu;
    // 8006F44C: fmuls   f0, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8006F44Cu)) return;
    ppc_fmuls(ctx, 0, 1, 0);

label_8006F450:
    ctx->pc = 0x8006F450u;
    // 8006F450: stfs     f0, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006F450u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8006F454:
    ctx->pc = 0x8006F454u;
    // 8006F454: lfs     f0, 40(r26)
    if (!ppc_fp_available_inline(ctx, 0x8006F454u)) return;
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(40);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8006F458:
    ctx->pc = 0x8006F458u;
    // 8006F458: fmuls   f0, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8006F458u)) return;
    ppc_fmuls(ctx, 0, 1, 0);

label_8006F45C:
    ctx->pc = 0x8006F45Cu;
    // 8006F45C: stfs     f0, 12(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006F45Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8006F460:
    ctx->pc = 0x8006F460u;
    // 8006F460: lfs     f0, 44(r26)
    if (!ppc_fp_available_inline(ctx, 0x8006F460u)) return;
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(44);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8006F464:
    ctx->pc = 0x8006F464u;
    // 8006F464: fmuls   f0, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8006F464u)) return;
    ppc_fmuls(ctx, 0, 1, 0);

label_8006F468:
    ctx->pc = 0x8006F468u;
    // 8006F468: stfs     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006F468u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8006F46C:
    // 8006F46C: cmpwi   r28, 6
    {
        s32 val_a = (s32)(ctx->gpr[28]);
        s32 val_b = (s32)(6);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8006F470:
    // 8006F470: bc    12, 2, 0x8006F47C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8006F47C;
        }
    }

label_8006F474:
    ctx->downcount -= 2;
    // 8006F474: cmpwi   r28, 3
    {
        s32 val_a = (s32)(ctx->gpr[28]);
        s32 val_b = (s32)(3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8006F478:
    // 8006F478: bc    4, 2, 0x8006F4D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8006F4D4;
        }
    }

label_8006F47C:
    ctx->downcount -= 3;
    // 8006F47C: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8006F480:
    // 8006F480: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_8006F484:
    // 8006F484: bl      0x80022308
    {
            ctx->lr = 0x8006F488u;
            ctx->pc = 0x80022308u;
            return;
    }

label_8006F488:
    ctx->downcount -= 3;
    // 8006F488: rlwinm r25, r3, 0, 24, 31
    {
        ctx->gpr[25] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000000FFu;
    }

label_8006F48C:
    // 8006F48C: lis     r29, 32
    ctx->gpr[29] = ((u32)(s32)(32) << 16);

label_8006F490:
    // 8006F490: b       0x8006F4C4
    {
            goto label_8006F4C4;
    }

label_8006F494:
    ctx->downcount -= 12;
    // 8006F494: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8006F498:
    // 8006F498: li      r4, 2022
    ctx->gpr[4] = (u32)(s32)(2022);

label_8006F49C:
    // 8006F49C: addi    r5, r1, 20
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(20);

label_8006F4A0:
    // 8006F4A0: addi    r6, r29, 1
    ctx->gpr[6] = ctx->gpr[29] + (u32)(s32)(1);

label_8006F4A4:
    // 8006F4A4: li      r7, -1
    ctx->gpr[7] = (u32)(s32)(-1);

label_8006F4A8:
    // 8006F4A8: addi    r8, r1, 8
    ctx->gpr[8] = ctx->gpr[1] + (u32)(s32)(8);

label_8006F4AC:
    ctx->pc = 0x8006F4ACu;
    // 8006F4AC: lwz     r9, -26360(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26360);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8006F4B0:
    ctx->pc = 0x8006F4B0u;
    // 8006F4B0: lwz     r9, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8006F4B4:
    ctx->pc = 0x8006F4B4u;
    // 8006F4B4: lwz     r12, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_8006F4B8:
    ctx->pc = 0x8006F4B8u;
    // 8006F4B8: mtctr    r12
    ctx->ctr = ctx->gpr[12];

label_8006F4BC:
    ctx->pc = 0x8006F4BCu;
    // 8006F4BC: bctrl
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8006F4C0u;
            ctx->pc = target;
            return;
        }
    }

label_8006F4C0:
    ctx->downcount -= 1;
    // 8006F4C0: addi    r25, r25, -1
    ctx->gpr[25] = ctx->gpr[25] + (u32)(s32)(-1);

label_8006F4C4:
    ctx->downcount -= 3;
    // 8006F4C4: rlwinm r0, r25, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[25], 0u) & 0x000000FFu;
    }

label_8006F4C8:
    // 8006F4C8: cmplwi  r0, 0x0000
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

label_8006F4CC:
    // 8006F4CC: bc    4, 2, 0x8006F494
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8006F494u;
                return;
            }
            goto label_8006F494;
        }
    }

label_8006F4D0:
    ctx->downcount -= 1;
    // 8006F4D0: b       0x8006F530
    {
            goto label_8006F530;
    }

label_8006F4D4:
    ctx->downcount -= 2;
    // 8006F4D4: cmpwi   r28, 2
    {
        s32 val_a = (s32)(ctx->gpr[28]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8006F4D8:
    // 8006F4D8: bc    4, 2, 0x8006F530
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8006F530;
        }
    }

label_8006F4DC:
    ctx->downcount -= 3;
    // 8006F4DC: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_8006F4E0:
    // 8006F4E0: li      r4, 8
    ctx->gpr[4] = (u32)(s32)(8);

label_8006F4E4:
    // 8006F4E4: bl      0x80022308
    {
            ctx->lr = 0x8006F4E8u;
            ctx->pc = 0x80022308u;
            return;
    }

label_8006F4E8:
    ctx->downcount -= 3;
    // 8006F4E8: rlwinm r25, r3, 0, 24, 31
    {
        ctx->gpr[25] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000000FFu;
    }

label_8006F4EC:
    // 8006F4EC: lis     r29, 32
    ctx->gpr[29] = ((u32)(s32)(32) << 16);

label_8006F4F0:
    // 8006F4F0: b       0x8006F524
    {
            goto label_8006F524;
    }

label_8006F4F4:
    ctx->downcount -= 12;
    // 8006F4F4: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8006F4F8:
    // 8006F4F8: li      r4, 2022
    ctx->gpr[4] = (u32)(s32)(2022);

label_8006F4FC:
    // 8006F4FC: addi    r5, r1, 20
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(20);

label_8006F500:
    // 8006F500: addi    r6, r29, 1
    ctx->gpr[6] = ctx->gpr[29] + (u32)(s32)(1);

label_8006F504:
    // 8006F504: li      r7, -1
    ctx->gpr[7] = (u32)(s32)(-1);

label_8006F508:
    // 8006F508: addi    r8, r1, 8
    ctx->gpr[8] = ctx->gpr[1] + (u32)(s32)(8);

label_8006F50C:
    ctx->pc = 0x8006F50Cu;
    // 8006F50C: lwz     r9, -26360(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26360);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8006F510:
    ctx->pc = 0x8006F510u;
    // 8006F510: lwz     r9, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8006F514:
    ctx->pc = 0x8006F514u;
    // 8006F514: lwz     r12, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_8006F518:
    ctx->pc = 0x8006F518u;
    // 8006F518: mtctr    r12
    ctx->ctr = ctx->gpr[12];

label_8006F51C:
    ctx->pc = 0x8006F51Cu;
    // 8006F51C: bctrl
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8006F520u;
            ctx->pc = target;
            return;
        }
    }

label_8006F520:
    ctx->downcount -= 1;
    // 8006F520: addi    r25, r25, -1
    ctx->gpr[25] = ctx->gpr[25] + (u32)(s32)(-1);

label_8006F524:
    ctx->downcount -= 3;
    // 8006F524: rlwinm r0, r25, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[25], 0u) & 0x000000FFu;
    }

label_8006F528:
    // 8006F528: cmplwi  r0, 0x0000
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

label_8006F52C:
    // 8006F52C: bc    4, 2, 0x8006F4F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8006F4F4u;
                return;
            }
            goto label_8006F4F4;
        }
    }

label_8006F530:
    ctx->downcount -= 4;
    // 8006F530: rlwinm r0, r30, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[30], 0u) & 0x000000FFu;
    }

label_8006F534:
    // 8006F534: srawi r0, r0, 1
    {
        u32 sh = 1u;
        u32 value = ctx->gpr[0];
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

label_8006F538:
    // 8006F538: rlwinm r30, r0, 0, 24, 31
    {
        ctx->gpr[30] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_8006F53C:
    // 8006F53C: addi    r31, r31, 1
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(1);

label_8006F540:
    ctx->downcount -= 3;
    // 8006F540: rlwinm r0, r30, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[30], 0u) & 0x000000FFu;
    }

label_8006F544:
    // 8006F544: cmplwi  r0, 0x0000
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

label_8006F548:
    // 8006F548: bc    4, 2, 0x8006F3B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8006F3B4u;
                return;
            }
            goto label_8006F3B4;
        }
    }

label_8006F54C:
    ctx->pc = 0x8006F54Cu;
    ctx->downcount -= 4;
    // 8006F54C: psq_l   f31, 88(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8006F54Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        ppc_psq_load_inline(ctx, 31u, ea, false, 0u, false, 0x8006F54Cu);
        if (ctx->exception) return;
    }

label_8006F550:
    ctx->pc = 0x8006F550u;
    // 8006F550: lfd     f31, 80(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006F550u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006F554:
    ctx->pc = 0x8006F554u;
    // 8006F554: addi    r11, r1, 80
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(80);

label_8006F558:
    ctx->pc = 0x8006F558u;
    // 8006F558: bl      0x80286A90
    {
            ctx->lr = 0x8006F55Cu;
            ctx->pc = 0x80286A90u;
            return;
    }

label_8006F55C:
    ctx->pc = 0x8006F55Cu;
    ctx->downcount -= 5;
    // 8006F55C: lwz     r0, 100(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(100);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8006F560:
    ctx->pc = 0x8006F560u;
    // 8006F560: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8006F564:
    ctx->pc = 0x8006F564u;
    // 8006F564: addi    r1, r1, 96
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(96);

label_8006F568:
    ctx->pc = 0x8006F568u;
    // 8006F568: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_8006F56C:
    ctx->pc = 0x8006F56Cu;
    ctx->downcount -= 4;
    // 8006F56C: lis     r4, -32719
    ctx->gpr[4] = ((u32)(s32)(-32719) << 16);

label_8006F570:
    ctx->pc = 0x8006F570u;
    // 8006F570: addi    r5, r4, 144
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(144);

label_8006F574:
    ctx->pc = 0x8006F574u;
    // 8006F574: cmplwi  r3, 0x000A
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x000Au);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8006F578:
    ctx->pc = 0x8006F578u;
    // 8006F578: bc    12, 1, 0x8006F5DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8006F5DC;
        }
    }

label_8006F57C:
    ctx->pc = 0x8006F57Cu;
    ctx->downcount -= 7;
    // 8006F57C: lis     r4, -32719
    ctx->gpr[4] = ((u32)(s32)(-32719) << 16);

label_8006F580:
    ctx->pc = 0x8006F580u;
    // 8006F580: addi    r4, r4, 448
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(448);

label_8006F584:
    ctx->pc = 0x8006F584u;
    // 8006F584: rlwinm r0, r3, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0xFFFFFFFCu;
    }

label_8006F588:
    ctx->pc = 0x8006F588u;
    // 8006F588: lwzx    r0, r4, r0
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8006F58C:
    ctx->pc = 0x8006F58Cu;
    // 8006F58C: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8006F590:
    ctx->pc = 0x8006F590u;
    // 8006F590: bctr
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            return;
        }
    }

label_8006F594:
    ctx->pc = 0x8006F594u;
    ctx->downcount -= 2;
    // 8006F594: or   r3, r5, r5
    {
        ctx->gpr[3] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8006F598:
    ctx->pc = 0x8006F598u;
    // 8006F598: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_8006F59C:
    ctx->pc = 0x8006F59Cu;
    ctx->downcount -= 2;
    // 8006F59C: addi    r3, r5, 20
    ctx->gpr[3] = ctx->gpr[5] + (u32)(s32)(20);

label_8006F5A0:
    ctx->pc = 0x8006F5A0u;
    // 8006F5A0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_8006F5A4:
    ctx->pc = 0x8006F5A4u;
    ctx->downcount -= 2;
    // 8006F5A4: addi    r3, r5, 60
    ctx->gpr[3] = ctx->gpr[5] + (u32)(s32)(60);

label_8006F5A8:
    ctx->pc = 0x8006F5A8u;
    // 8006F5A8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_8006F5AC:
    ctx->pc = 0x8006F5ACu;
    ctx->downcount -= 2;
    // 8006F5AC: addi    r3, r5, 100
    ctx->gpr[3] = ctx->gpr[5] + (u32)(s32)(100);

label_8006F5B0:
    ctx->pc = 0x8006F5B0u;
    // 8006F5B0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_8006F5B4:
    ctx->pc = 0x8006F5B4u;
    ctx->downcount -= 2;
    // 8006F5B4: addi    r3, r5, 80
    ctx->gpr[3] = ctx->gpr[5] + (u32)(s32)(80);

label_8006F5B8:
    ctx->pc = 0x8006F5B8u;
    // 8006F5B8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_8006F5BC:
    ctx->pc = 0x8006F5BCu;
    ctx->downcount -= 2;
    // 8006F5BC: addi    r3, r5, 120
    ctx->gpr[3] = ctx->gpr[5] + (u32)(s32)(120);

label_8006F5C0:
    ctx->pc = 0x8006F5C0u;
    // 8006F5C0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_8006F5C4:
    ctx->pc = 0x8006F5C4u;
    ctx->downcount -= 2;
    // 8006F5C4: addi    r3, r5, 140
    ctx->gpr[3] = ctx->gpr[5] + (u32)(s32)(140);

label_8006F5C8:
    ctx->pc = 0x8006F5C8u;
    // 8006F5C8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_8006F5CC:
    ctx->pc = 0x8006F5CCu;
    ctx->downcount -= 2;
    // 8006F5CC: addi    r3, r5, 160
    ctx->gpr[3] = ctx->gpr[5] + (u32)(s32)(160);

label_8006F5D0:
    ctx->pc = 0x8006F5D0u;
    // 8006F5D0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_8006F5D4:
    ctx->pc = 0x8006F5D4u;
    ctx->downcount -= 2;
    // 8006F5D4: addi    r3, r5, 40
    ctx->gpr[3] = ctx->gpr[5] + (u32)(s32)(40);

label_8006F5D8:
    ctx->pc = 0x8006F5D8u;
    // 8006F5D8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_8006F5DC:
    ctx->pc = 0x8006F5DCu;
    ctx->downcount -= 2;
    // 8006F5DC: addi    r3, r5, 40
    ctx->gpr[3] = ctx->gpr[5] + (u32)(s32)(40);

label_8006F5E0:
    ctx->pc = 0x8006F5E0u;
    // 8006F5E0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_8006F5E4:
    ctx->pc = 0x8006F5E4u;
    ctx->downcount -= 8;
    // 8006F5E4: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8006F5E8:
    ctx->pc = 0x8006F5E8u;
    // 8006F5E8: lis     r3, -32711
    ctx->gpr[3] = ((u32)(s32)(-32711) << 16);

label_8006F5EC:
    ctx->pc = 0x8006F5ECu;
    // 8006F5EC: addi    r4, r3, 18240
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(18240);

label_8006F5F0:
    ctx->pc = 0x8006F5F0u;
    // 8006F5F0: lis     r3, -32711
    ctx->gpr[3] = ((u32)(s32)(-32711) << 16);

label_8006F5F4:
    ctx->pc = 0x8006F5F4u;
    // 8006F5F4: addi    r3, r3, 14144
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(14144);

label_8006F5F8:
    ctx->pc = 0x8006F5F8u;
    // 8006F5F8: li      r0, 256
    ctx->gpr[0] = (u32)(s32)(256);

label_8006F5FC:
    ctx->pc = 0x8006F5FCu;
    // 8006F5FC: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8006F600:
    ctx->pc = 0x8006F600u;
    ctx->downcount -= 3;
    // 8006F600: lbz     r5, 51(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(51);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_8006F604:
    // 8006F604: cmplwi  r5, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8006F608:
    // 8006F608: bc    12, 2, 0x8006F668
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8006F668;
        }
    }

label_8006F60C:
    ctx->pc = 0x8006F60Cu;
    ctx->downcount -= 11;
    // 8006F60C: lfd     f3, -30408(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006F60Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30408);
        ctx->fpr[3] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006F610:
    ctx->pc = 0x8006F610u;
    // 8006F610: stw     r5, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8006F614:
    // 8006F614: lis     r0, 17200
    ctx->gpr[0] = ((u32)(s32)(17200) << 16);

label_8006F618:
    ctx->pc = 0x8006F618u;
    // 8006F618: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006F61C:
    ctx->pc = 0x8006F61Cu;
    // 8006F61C: lfd     f0, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006F61Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006F620:
    ctx->pc = 0x8006F620u;
    // 8006F620: fsubs   f0, f0, f3
    if (!ppc_fp_available_inline(ctx, 0x8006F620u)) return;
    ppc_fsubs(ctx, 0, 0, 3);

label_8006F624:
    ctx->pc = 0x8006F624u;
    // 8006F624: fsubs   f2, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8006F624u)) return;
    ppc_fsubs(ctx, 2, 0, 1);

label_8006F628:
    ctx->pc = 0x8006F628u;
    // 8006F628: lfs     f0, -30424(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006F628u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30424);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8006F62C:
    ctx->pc = 0x8006F62Cu;
    // 8006F62C: fcmpo   cr0, f2, f0
    if (!ppc_fp_available_inline(ctx, 0x8006F62Cu)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[2], ctx->fpr[0], true);

label_8006F630:
    // 8006F630: cror    2, 0, 2
    {
        u32 a = (ctx->cr >> (31u - 0u)) & 1u;
        u32 b = (ctx->cr >> (31u - 2u)) & 1u;
        u32 mask = 0x80000000u >> 2;
        u32 value = (a | b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8006F634:
    // 8006F634: bc    4, 2, 0x8006F644
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8006F644;
        }
    }

label_8006F638:
    ctx->downcount -= 3;
    // 8006F638: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8006F63C:
    ctx->pc = 0x8006F63Cu;
    // 8006F63C: stb     r0, 51(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(51);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006F640:
    // 8006F640: b       0x8006F668
    {
            goto label_8006F668;
    }

label_8006F644:
    ctx->pc = 0x8006F644u;
    ctx->downcount -= 9;
    // 8006F644: stw     r5, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8006F648:
    ctx->pc = 0x8006F648u;
    // 8006F648: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006F64C:
    ctx->pc = 0x8006F64Cu;
    // 8006F64C: lfd     f0, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006F64Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006F650:
    ctx->pc = 0x8006F650u;
    // 8006F650: fsubs   f0, f0, f3
    if (!ppc_fp_available_inline(ctx, 0x8006F650u)) return;
    ppc_fsubs(ctx, 0, 0, 3);

label_8006F654:
    ctx->pc = 0x8006F654u;
    // 8006F654: fsubs   f0, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8006F654u)) return;
    ppc_fsubs(ctx, 0, 0, 1);

label_8006F658:
    ctx->pc = 0x8006F658u;
    // 8006F658: fctiwz    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x8006F658u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_8006F65C:
    ctx->pc = 0x8006F65Cu;
    // 8006F65C: stfd     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006F65Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_8006F660:
    ctx->pc = 0x8006F660u;
    // 8006F660: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8006F664:
    ctx->pc = 0x8006F664u;
    // 8006F664: stb     r0, 51(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(51);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006F668:
    ctx->pc = 0x8006F668u;
    ctx->downcount -= 3;
    // 8006F668: lbz     r5, 14(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(14);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_8006F66C:
    // 8006F66C: cmplwi  r5, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8006F670:
    // 8006F670: bc    12, 2, 0x8006F6D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8006F6D0;
        }
    }

label_8006F674:
    ctx->pc = 0x8006F674u;
    ctx->downcount -= 11;
    // 8006F674: lfd     f3, -30408(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006F674u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30408);
        ctx->fpr[3] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006F678:
    ctx->pc = 0x8006F678u;
    // 8006F678: stw     r5, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8006F67C:
    // 8006F67C: lis     r0, 17200
    ctx->gpr[0] = ((u32)(s32)(17200) << 16);

label_8006F680:
    ctx->pc = 0x8006F680u;
    // 8006F680: stw     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006F684:
    ctx->pc = 0x8006F684u;
    // 8006F684: lfd     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006F684u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006F688:
    ctx->pc = 0x8006F688u;
    // 8006F688: fsubs   f0, f0, f3
    if (!ppc_fp_available_inline(ctx, 0x8006F688u)) return;
    ppc_fsubs(ctx, 0, 0, 3);

label_8006F68C:
    ctx->pc = 0x8006F68Cu;
    // 8006F68C: fsubs   f2, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8006F68Cu)) return;
    ppc_fsubs(ctx, 2, 0, 1);

label_8006F690:
    ctx->pc = 0x8006F690u;
    // 8006F690: lfs     f0, -30424(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006F690u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30424);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8006F694:
    ctx->pc = 0x8006F694u;
    // 8006F694: fcmpo   cr0, f2, f0
    if (!ppc_fp_available_inline(ctx, 0x8006F694u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[2], ctx->fpr[0], true);

label_8006F698:
    // 8006F698: cror    2, 0, 2
    {
        u32 a = (ctx->cr >> (31u - 0u)) & 1u;
        u32 b = (ctx->cr >> (31u - 2u)) & 1u;
        u32 mask = 0x80000000u >> 2;
        u32 value = (a | b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8006F69C:
    // 8006F69C: bc    4, 2, 0x8006F6AC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8006F6AC;
        }
    }

label_8006F6A0:
    ctx->downcount -= 3;
    // 8006F6A0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8006F6A4:
    ctx->pc = 0x8006F6A4u;
    // 8006F6A4: stb     r0, 14(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(14);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006F6A8:
    // 8006F6A8: b       0x8006F6D0
    {
            goto label_8006F6D0;
    }

label_8006F6AC:
    ctx->pc = 0x8006F6ACu;
    ctx->downcount -= 9;
    // 8006F6AC: stw     r5, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8006F6B0:
    ctx->pc = 0x8006F6B0u;
    // 8006F6B0: stw     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006F6B4:
    ctx->pc = 0x8006F6B4u;
    // 8006F6B4: lfd     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006F6B4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006F6B8:
    ctx->pc = 0x8006F6B8u;
    // 8006F6B8: fsubs   f0, f0, f3
    if (!ppc_fp_available_inline(ctx, 0x8006F6B8u)) return;
    ppc_fsubs(ctx, 0, 0, 3);

label_8006F6BC:
    ctx->pc = 0x8006F6BCu;
    // 8006F6BC: fsubs   f0, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8006F6BCu)) return;
    ppc_fsubs(ctx, 0, 0, 1);

label_8006F6C0:
    ctx->pc = 0x8006F6C0u;
    // 8006F6C0: fctiwz    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x8006F6C0u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_8006F6C4:
    ctx->pc = 0x8006F6C4u;
    // 8006F6C4: stfd     f0, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006F6C4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_8006F6C8:
    ctx->pc = 0x8006F6C8u;
    // 8006F6C8: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8006F6CC:
    ctx->pc = 0x8006F6CCu;
    // 8006F6CC: stb     r0, 14(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(14);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006F6D0:
    ctx->downcount -= 3;
    // 8006F6D0: addi    r4, r4, 56
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(56);

label_8006F6D4:
    // 8006F6D4: addi    r3, r3, 16
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(16);

label_8006F6D8:
    // 8006F6D8: bc    16, 0, 0x8006F600
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8006F600u;
                return;
            }
            goto label_8006F600;
        }
    }

label_8006F6DC:
    ctx->pc = 0x8006F6DCu;
    ctx->downcount -= 2;
    // 8006F6DC: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_8006F6E0:
    ctx->pc = 0x8006F6E0u;
    // 8006F6E0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_8006F6E4:
    ctx->pc = 0x8006F6E4u;
    ctx->downcount -= 10;
    // 8006F6E4: stwu     r1, -256(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-256);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8006F6E8:
    ctx->pc = 0x8006F6E8u;
    // 8006F6E8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8006F6EC:
    ctx->pc = 0x8006F6ECu;
    // 8006F6EC: stw     r0, 260(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(260);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006F6F0:
    ctx->pc = 0x8006F6F0u;
    // 8006F6F0: stfd     f31, 240(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006F6F0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(240);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_8006F6F4:
    ctx->pc = 0x8006F6F4u;
    // 8006F6F4: psq_st   f31, 248(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8006F6F4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(248);
        ppc_psq_store_inline(ctx, 31u, ea, false, 0u, false, 0x8006F6F4u);
        if (ctx->exception) return;
    }

label_8006F6F8:
    ctx->pc = 0x8006F6F8u;
    // 8006F6F8: stfd     f30, 224(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006F6F8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(224);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[30]));
    }

label_8006F6FC:
    ctx->pc = 0x8006F6FCu;
    // 8006F6FC: psq_st   f30, 232(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8006F6FCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(232);
        ppc_psq_store_inline(ctx, 30u, ea, false, 0u, false, 0x8006F6FCu);
        if (ctx->exception) return;
    }

label_8006F700:
    ctx->pc = 0x8006F700u;
    // 8006F700: stw     r31, 220(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(220);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8006F704:
    ctx->pc = 0x8006F704u;
    // 8006F704: stw     r30, 216(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(216);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8006F708:
    ctx->pc = 0x8006F708u;
    // 8006F708: bl      0x8002BB60
    {
            ctx->lr = 0x8006F70Cu;
            ctx->pc = 0x8002BB60u;
            return;
    }

label_8006F70C:
    ctx->pc = 0x8006F70Cu;
    ctx->downcount -= 2;
    // 8006F70C: cmplwi  r3, 0x0000
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

label_8006F710:
    ctx->pc = 0x8006F710u;
    // 8006F710: bc    12, 2, 0x8006FB0C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8006FB0C;
        }
    }

label_8006F714:
    ctx->pc = 0x8006F714u;
    ctx->downcount -= 1;
    // 8006F714: bl      0x8000F9D4
    {
            ctx->lr = 0x8006F718u;
            ctx->pc = 0x8000F9D4u;
            return;
    }

label_8006F718:
    ctx->pc = 0x8006F718u;
    ctx->downcount -= 2;
    // 8006F718: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8006F71C:
    ctx->pc = 0x8006F71Cu;
    // 8006F71C: bl      0x8025DA94
    {
            ctx->lr = 0x8006F720u;
            ctx->pc = 0x8025DA94u;
            return;
    }

label_8006F720:
    ctx->pc = 0x8006F720u;
    ctx->downcount -= 1;
    // 8006F720: bl      0x80257D68
    {
            ctx->lr = 0x8006F724u;
            ctx->pc = 0x80257D68u;
            return;
    }

label_8006F724:
    ctx->pc = 0x8006F724u;
    ctx->downcount -= 3;
    // 8006F724: li      r3, 9
    ctx->gpr[3] = (u32)(s32)(9);

label_8006F728:
    ctx->pc = 0x8006F728u;
    // 8006F728: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8006F72C:
    ctx->pc = 0x8006F72Cu;
    // 8006F72C: bl      0x802572E8
    {
            ctx->lr = 0x8006F730u;
            ctx->pc = 0x802572E8u;
            return;
    }

label_8006F730:
    ctx->pc = 0x8006F730u;
    ctx->downcount -= 3;
    // 8006F730: li      r3, 13
    ctx->gpr[3] = (u32)(s32)(13);

label_8006F734:
    ctx->pc = 0x8006F734u;
    // 8006F734: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8006F738:
    ctx->pc = 0x8006F738u;
    // 8006F738: bl      0x802572E8
    {
            ctx->lr = 0x8006F73Cu;
            ctx->pc = 0x802572E8u;
            return;
    }

label_8006F73C:
    ctx->pc = 0x8006F73Cu;
    ctx->downcount -= 2;
    // 8006F73C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8006F740:
    ctx->pc = 0x8006F740u;
    // 8006F740: bl      0x80258B50
    {
            ctx->lr = 0x8006F744u;
            ctx->pc = 0x80258B50u;
            return;
    }

label_8006F744:
    ctx->pc = 0x8006F744u;
    ctx->downcount -= 7;
    // 8006F744: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8006F748:
    ctx->pc = 0x8006F748u;
    // 8006F748: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8006F74C:
    ctx->pc = 0x8006F74Cu;
    // 8006F74C: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_8006F750:
    ctx->pc = 0x8006F750u;
    // 8006F750: li      r6, 30
    ctx->gpr[6] = (u32)(s32)(30);

label_8006F754:
    ctx->pc = 0x8006F754u;
    // 8006F754: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8006F758:
    ctx->pc = 0x8006F758u;
    // 8006F758: li      r8, 125
    ctx->gpr[8] = (u32)(s32)(125);

label_8006F75C:
    ctx->pc = 0x8006F75Cu;
    // 8006F75C: bl      0x80258880
    {
            ctx->lr = 0x8006F760u;
            ctx->pc = 0x80258880u;
            return;
    }

label_8006F760:
    ctx->pc = 0x8006F760u;
    ctx->downcount -= 2;
    // 8006F760: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8006F764:
    ctx->pc = 0x8006F764u;
    // 8006F764: bl      0x8025CC10
    {
            ctx->lr = 0x8006F768u;
            ctx->pc = 0x8025CC10u;
            return;
    }

label_8006F768:
    ctx->pc = 0x8006F768u;
    ctx->downcount -= 2;
    // 8006F768: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8006F76C:
    ctx->pc = 0x8006F76Cu;
    // 8006F76C: bl      0x8025C060
    {
            ctx->lr = 0x8006F770u;
            ctx->pc = 0x8025C060u;
            return;
    }

label_8006F770:
    ctx->pc = 0x8006F770u;
    ctx->downcount -= 8;
    // 8006F770: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_8006F774:
    ctx->pc = 0x8006F774u;
    // 8006F774: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8006F778:
    ctx->pc = 0x8006F778u;
    // 8006F778: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8006F77C:
    ctx->pc = 0x8006F77Cu;
    // 8006F77C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8006F780:
    ctx->pc = 0x8006F780u;
    // 8006F780: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8006F784:
    ctx->pc = 0x8006F784u;
    // 8006F784: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8006F788:
    ctx->pc = 0x8006F788u;
    // 8006F788: li      r9, 2
    ctx->gpr[9] = (u32)(s32)(2);

label_8006F78C:
    ctx->pc = 0x8006F78Cu;
    // 8006F78C: bl      0x8025A814
    {
            ctx->lr = 0x8006F790u;
            ctx->pc = 0x8025A814u;
            return;
    }

label_8006F790:
    ctx->pc = 0x8006F790u;
    ctx->downcount -= 8;
    // 8006F790: li      r3, 5
    ctx->gpr[3] = (u32)(s32)(5);

label_8006F794:
    ctx->pc = 0x8006F794u;
    // 8006F794: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8006F798:
    ctx->pc = 0x8006F798u;
    // 8006F798: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8006F79C:
    ctx->pc = 0x8006F79Cu;
    // 8006F79C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8006F7A0:
    ctx->pc = 0x8006F7A0u;
    // 8006F7A0: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8006F7A4:
    ctx->pc = 0x8006F7A4u;
    // 8006F7A4: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8006F7A8:
    ctx->pc = 0x8006F7A8u;
    // 8006F7A8: li      r9, 2
    ctx->gpr[9] = (u32)(s32)(2);

label_8006F7AC:
    ctx->pc = 0x8006F7ACu;
    // 8006F7AC: bl      0x8025A814
    {
            ctx->lr = 0x8006F7B0u;
            ctx->pc = 0x8025A814u;
            return;
    }

label_8006F7B0:
    ctx->pc = 0x8006F7B0u;
    ctx->downcount -= 2;
    // 8006F7B0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8006F7B4:
    ctx->pc = 0x8006F7B4u;
    // 8006F7B4: bl      0x8025A7C8
    {
            ctx->lr = 0x8006F7B8u;
            ctx->pc = 0x8025A7C8u;
            return;
    }

label_8006F7B8:
    ctx->pc = 0x8006F7B8u;
    ctx->downcount -= 5;
    // 8006F7B8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8006F7BC:
    ctx->pc = 0x8006F7BCu;
    // 8006F7BC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8006F7C0:
    ctx->pc = 0x8006F7C0u;
    // 8006F7C0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8006F7C4:
    ctx->pc = 0x8006F7C4u;
    // 8006F7C4: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_8006F7C8:
    ctx->pc = 0x8006F7C8u;
    // 8006F7C8: bl      0x8025CA34
    {
            ctx->lr = 0x8006F7CCu;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_8006F7CC:
    ctx->pc = 0x8006F7CCu;
    ctx->downcount -= 2;
    // 8006F7CC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8006F7D0:
    ctx->pc = 0x8006F7D0u;
    // 8006F7D0: bl      0x8025C08C
    {
            ctx->lr = 0x8006F7D4u;
            ctx->pc = 0x8025C08Cu;
            return;
    }

label_8006F7D4:
    ctx->pc = 0x8006F7D4u;
    ctx->downcount -= 6;
    // 8006F7D4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8006F7D8:
    ctx->pc = 0x8006F7D8u;
    // 8006F7D8: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_8006F7DC:
    ctx->pc = 0x8006F7DCu;
    // 8006F7DC: li      r5, 15
    ctx->gpr[5] = (u32)(s32)(15);

label_8006F7E0:
    ctx->pc = 0x8006F7E0u;
    // 8006F7E0: li      r6, 15
    ctx->gpr[6] = (u32)(s32)(15);

label_8006F7E4:
    ctx->pc = 0x8006F7E4u;
    // 8006F7E4: li      r7, 15
    ctx->gpr[7] = (u32)(s32)(15);

label_8006F7E8:
    ctx->pc = 0x8006F7E8u;
    // 8006F7E8: bl      0x8025C3B0
    {
            ctx->lr = 0x8006F7ECu;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_8006F7EC:
    ctx->pc = 0x8006F7ECu;
    ctx->downcount -= 3;
    // 8006F7EC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8006F7F0:
    ctx->pc = 0x8006F7F0u;
    // 8006F7F0: li      r4, 28
    ctx->gpr[4] = (u32)(s32)(28);

label_8006F7F4:
    ctx->pc = 0x8006F7F4u;
    // 8006F7F4: bl      0x8025C7FC
    {
            ctx->lr = 0x8006F7F8u;
            ctx->pc = 0x8025C7FCu;
            return;
    }

label_8006F7F8:
    ctx->pc = 0x8006F7F8u;
    ctx->downcount -= 6;
    // 8006F7F8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8006F7FC:
    ctx->pc = 0x8006F7FCu;
    // 8006F7FC: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_8006F800:
    ctx->pc = 0x8006F800u;
    // 8006F800: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_8006F804:
    ctx->pc = 0x8006F804u;
    // 8006F804: li      r6, 6
    ctx->gpr[6] = (u32)(s32)(6);

label_8006F808:
    ctx->pc = 0x8006F808u;
    // 8006F808: li      r7, 7
    ctx->gpr[7] = (u32)(s32)(7);

label_8006F80C:
    ctx->pc = 0x8006F80Cu;
    // 8006F80C: bl      0x8025C430
    {
            ctx->lr = 0x8006F810u;
            ctx->pc = 0x8025C430u;
            return;
    }

label_8006F810:
    ctx->pc = 0x8006F810u;
    ctx->downcount -= 7;
    // 8006F810: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8006F814:
    ctx->pc = 0x8006F814u;
    // 8006F814: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8006F818:
    ctx->pc = 0x8006F818u;
    // 8006F818: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8006F81C:
    ctx->pc = 0x8006F81Cu;
    // 8006F81C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8006F820:
    ctx->pc = 0x8006F820u;
    // 8006F820: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8006F824:
    ctx->pc = 0x8006F824u;
    // 8006F824: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8006F828:
    ctx->pc = 0x8006F828u;
    // 8006F828: bl      0x8025C4B4
    {
            ctx->lr = 0x8006F82Cu;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_8006F82C:
    ctx->pc = 0x8006F82Cu;
    ctx->downcount -= 7;
    // 8006F82C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8006F830:
    ctx->pc = 0x8006F830u;
    // 8006F830: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8006F834:
    ctx->pc = 0x8006F834u;
    // 8006F834: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8006F838:
    ctx->pc = 0x8006F838u;
    // 8006F838: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8006F83C:
    ctx->pc = 0x8006F83Cu;
    // 8006F83C: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8006F840:
    ctx->pc = 0x8006F840u;
    // 8006F840: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8006F844:
    ctx->pc = 0x8006F844u;
    // 8006F844: bl      0x8025C574
    {
            ctx->lr = 0x8006F848u;
            ctx->pc = 0x8025C574u;
            return;
    }

label_8006F848:
    ctx->pc = 0x8006F848u;
    ctx->downcount -= 4;
    // 8006F848: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8006F84C:
    ctx->pc = 0x8006F84Cu;
    // 8006F84C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8006F850:
    ctx->pc = 0x8006F850u;
    // 8006F850: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8006F854:
    ctx->pc = 0x8006F854u;
    // 8006F854: bl      0x8025C868
    {
            ctx->lr = 0x8006F858u;
            ctx->pc = 0x8025C868u;
            return;
    }

label_8006F858:
    ctx->pc = 0x8006F858u;
    ctx->downcount -= 2;
    // 8006F858: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8006F85C:
    ctx->pc = 0x8006F85Cu;
    // 8006F85C: bl      0x80259494
    {
            ctx->lr = 0x8006F860u;
            ctx->pc = 0x80259494u;
            return;
    }

label_8006F860:
    ctx->pc = 0x8006F860u;
    ctx->downcount -= 5;
    // 8006F860: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8006F864:
    ctx->pc = 0x8006F864u;
    // 8006F864: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_8006F868:
    ctx->pc = 0x8006F868u;
    // 8006F868: li      r5, 5
    ctx->gpr[5] = (u32)(s32)(5);

label_8006F86C:
    ctx->pc = 0x8006F86Cu;
    // 8006F86C: li      r6, 5
    ctx->gpr[6] = (u32)(s32)(5);

label_8006F870:
    ctx->pc = 0x8006F870u;
    // 8006F870: bl      0x8025CEF4
    {
            ctx->lr = 0x8006F874u;
            ctx->pc = 0x8025CEF4u;
            return;
    }

label_8006F874:
    ctx->pc = 0x8006F874u;
    ctx->downcount -= 7;
    // 8006F874: lbz     r0, -24984(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24984);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8006F878:
    ctx->pc = 0x8006F878u;
    // 8006F878: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_8006F87C:
    ctx->pc = 0x8006F87Cu;
    // 8006F87C: lis     r3, -32711
    ctx->gpr[3] = ((u32)(s32)(-32711) << 16);

label_8006F880:
    ctx->pc = 0x8006F880u;
    // 8006F880: addi    r3, r3, 14128
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(14128);

label_8006F884:
    ctx->pc = 0x8006F884u;
    // 8006F884: lwzx    r3, r3, r0
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[0];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8006F888:
    ctx->pc = 0x8006F888u;
    // 8006F888: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8006F88C:
    ctx->pc = 0x8006F88Cu;
    // 8006F88C: bl      0x8004C4C8
    {
            ctx->lr = 0x8006F890u;
            ctx->pc = 0x8004C4C8u;
            return;
    }

label_8006F890:
    ctx->pc = 0x8006F890u;
    ctx->downcount -= 1;
    // 8006F890: bl      0x8000F56C
    {
            ctx->lr = 0x8006F894u;
            ctx->pc = 0x8000F56Cu;
            return;
    }

label_8006F894:
    ctx->pc = 0x8006F894u;
    ctx->downcount -= 8;
    // 8006F894: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8006F898:
    ctx->pc = 0x8006F898u;
    // 8006F898: addi    r3, r1, 160
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(160);

label_8006F89C:
    ctx->pc = 0x8006F89Cu;
    // 8006F89C: lfs     f0, -25520(r13)
    if (!ppc_fp_available_inline(ctx, 0x8006F89Cu)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25520);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8006F8A0:
    ctx->pc = 0x8006F8A0u;
    // 8006F8A0: fneg    f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8006F8A0u)) return;
    ctx->fpr[1] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[0]) ^ 0x8000000000000000ull);

label_8006F8A4:
    ctx->pc = 0x8006F8A4u;
    // 8006F8A4: lfs     f2, -30424(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006F8A4u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30424);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8006F8A8:
    ctx->pc = 0x8006F8A8u;
    // 8006F8A8: lfs     f0, -25516(r13)
    if (!ppc_fp_available_inline(ctx, 0x8006F8A8u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25516);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8006F8AC:
    ctx->pc = 0x8006F8ACu;
    // 8006F8AC: fneg    f3, f0
    if (!ppc_fp_available_inline(ctx, 0x8006F8ACu)) return;
    ctx->fpr[3] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[0]) ^ 0x8000000000000000ull);

label_8006F8B0:
    ctx->pc = 0x8006F8B0u;
    // 8006F8B0: bl      0x80247C90
    {
            ctx->lr = 0x8006F8B4u;
            ctx->pc = 0x80247C90u;
            return;
    }

label_8006F8B4:
    ctx->pc = 0x8006F8B4u;
    ctx->downcount -= 4;
    // 8006F8B4: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8006F8B8:
    ctx->pc = 0x8006F8B8u;
    // 8006F8B8: addi    r4, r1, 160
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(160);

label_8006F8BC:
    ctx->pc = 0x8006F8BCu;
    // 8006F8BC: addi    r5, r1, 112
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(112);

label_8006F8C0:
    ctx->pc = 0x8006F8C0u;
    // 8006F8C0: bl      0x80247860
    {
            ctx->lr = 0x8006F8C4u;
            ctx->pc = 0x80247860u;
            return;
    }

label_8006F8C4:
    ctx->pc = 0x8006F8C4u;
    ctx->downcount -= 3;
    // 8006F8C4: addi    r3, r1, 112
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(112);

label_8006F8C8:
    ctx->pc = 0x8006F8C8u;
    // 8006F8C8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8006F8CC:
    ctx->pc = 0x8006F8CCu;
    // 8006F8CC: bl      0x8025DA18
    {
            ctx->lr = 0x8006F8D0u;
            ctx->pc = 0x8025DA18u;
            return;
    }

label_8006F8D0:
    ctx->pc = 0x8006F8D0u;
    ctx->downcount -= 4;
    // 8006F8D0: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8006F8D4:
    ctx->pc = 0x8006F8D4u;
    // 8006F8D4: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_8006F8D8:
    ctx->pc = 0x8006F8D8u;
    // 8006F8D8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8006F8DC:
    ctx->pc = 0x8006F8DCu;
    // 8006F8DC: bl      0x800704F4
    {
            ctx->lr = 0x8006F8E0u;
            goto label_800704F4;
    }

label_8006F8E0:
    ctx->pc = 0x8006F8E0u;
    ctx->downcount -= 2;
    // 8006F8E0: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8006F8E4:
    ctx->pc = 0x8006F8E4u;
    // 8006F8E4: bl      0x8007049C
    {
            ctx->lr = 0x8006F8E8u;
            goto label_8007049C;
    }

label_8006F8E8:
    ctx->pc = 0x8006F8E8u;
    ctx->downcount -= 6;
    // 8006F8E8: li      r3, 7
    ctx->gpr[3] = (u32)(s32)(7);

label_8006F8EC:
    ctx->pc = 0x8006F8ECu;
    // 8006F8EC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8006F8F0:
    ctx->pc = 0x8006F8F0u;
    // 8006F8F0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8006F8F4:
    ctx->pc = 0x8006F8F4u;
    // 8006F8F4: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_8006F8F8:
    ctx->pc = 0x8006F8F8u;
    // 8006F8F8: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8006F8FC:
    ctx->pc = 0x8006F8FCu;
    // 8006F8FC: bl      0x8025C960
    {
            ctx->lr = 0x8006F900u;
            ctx->pc = 0x8025C960u;
            return;
    }

label_8006F900:
    ctx->pc = 0x8006F900u;
    ctx->downcount -= 3;
    // 8006F900: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_8006F904:
    ctx->pc = 0x8006F904u;
    // 8006F904: lis     r3, -32711
    ctx->gpr[3] = ((u32)(s32)(-32711) << 16);

label_8006F908:
    ctx->pc = 0x8006F908u;
    // 8006F908: addi    r31, r3, 18240
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(18240);

label_8006F90C:
    ctx->pc = 0x8006F90Cu;
    ctx->downcount -= 3;
    // 8006F90C: lbz     r3, 51(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(51);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8006F910:
    // 8006F910: cmplwi  r3, 0x0000
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

label_8006F914:
    // 8006F914: bc    12, 2, 0x8006FAF8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8006FAF8;
        }
    }

label_8006F918:
    ctx->pc = 0x8006F918u;
    ctx->downcount -= 3;
    // 8006F918: lbz     r0, 50(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(50);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8006F91C:
    // 8006F91C: cmplwi  r0, 0x0001
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0001u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8006F920:
    // 8006F920: bc    4, 2, 0x8006F934
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8006F934;
        }
    }

label_8006F924:
    ctx->downcount -= 4;
    // 8006F924: srawi r0, r3, 2
    {
        u32 sh = 2u;
        u32 value = ctx->gpr[3];
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

label_8006F928:
    // 8006F928: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_8006F92C:
    ctx->pc = 0x8006F92Cu;
    // 8006F92C: stb     r0, 15(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(15);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006F930:
    // 8006F930: b       0x8006F940
    {
            goto label_8006F940;
    }

label_8006F934:
    ctx->downcount -= 3;
    // 8006F934: srawi r0, r3, 1
    {
        u32 sh = 1u;
        u32 value = ctx->gpr[3];
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

label_8006F938:
    // 8006F938: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_8006F93C:
    ctx->pc = 0x8006F93Cu;
    // 8006F93C: stb     r0, 15(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(15);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006F940:
    ctx->pc = 0x8006F940u;
    ctx->downcount -= 5;
    // 8006F940: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8006F944:
    ctx->pc = 0x8006F944u;
    // 8006F944: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006F948:
    // 8006F948: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8006F94C:
    // 8006F94C: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_8006F950:
    // 8006F950: bl      0x8025C71C
    {
            ctx->lr = 0x8006F954u;
            ctx->pc = 0x8025C71Cu;
            return;
    }

label_8006F954:
    ctx->pc = 0x8006F954u;
    ctx->downcount -= 3;
    // 8006F954: lbz     r0, 52(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8006F958:
    // 8006F958: cmplwi  r0, 0x0000
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

label_8006F95C:
    // 8006F95C: bc    12, 2, 0x8006F9BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8006F9BC;
        }
    }

label_8006F960:
    ctx->pc = 0x8006F960u;
    ctx->downcount -= 38;
    // 8006F960: lfs     f31, -30400(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006F960u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30400);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_8006F964:
    ctx->pc = 0x8006F964u;
    // 8006F964: lfs     f30, -30424(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006F964u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30424);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[30] = value;
        ctx->ps1[30] = value;
    }

label_8006F968:
    // 8006F968: addi    r3, r1, 64
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(64);

label_8006F96C:
    // 8006F96C: li      r4, 122
    ctx->gpr[4] = (u32)(s32)(122);

label_8006F970:
    ctx->pc = 0x8006F970u;
    // 8006F970: lfs     f3, -30396(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006F970u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30396);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8006F974:
    ctx->pc = 0x8006F974u;
    // 8006F974: lfs     f2, -30392(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006F974u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30392);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8006F978:
    ctx->pc = 0x8006F978u;
    // 8006F978: lhz     r6, 48(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(48);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_8006F97C:
    // 8006F97C: lis     r5, 1
    ctx->gpr[5] = ((u32)(s32)(1) << 16);

label_8006F980:
    // 8006F980: addi    r0, r5, -32768
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(-32768);

label_8006F984:
    // 8006F984: subf   r0, r6, r0
    {
        u32 a = ~ctx->gpr[6];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_8006F988:
    ctx->pc = 0x8006F988u;
    // 8006F988: lfd     f1, -30376(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006F988u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30376);
        ctx->fpr[1] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006F98C:
    // 8006F98C: xoris   r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] ^ (0x8000u << 16);

label_8006F990:
    ctx->pc = 0x8006F990u;
    // 8006F990: stw     r0, 212(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(212);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006F994:
    // 8006F994: lis     r0, 17200
    ctx->gpr[0] = ((u32)(s32)(17200) << 16);

label_8006F998:
    ctx->pc = 0x8006F998u;
    // 8006F998: stw     r0, 208(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(208);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006F99C:
    ctx->pc = 0x8006F99Cu;
    // 8006F99C: lfd     f0, 208(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006F99Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(208);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006F9A0:
    ctx->pc = 0x8006F9A0u;
    // 8006F9A0: fsubs   f0, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8006F9A0u)) return;
    ppc_fsubs(ctx, 0, 0, 1);

label_8006F9A4:
    ctx->pc = 0x8006F9A4u;
    // 8006F9A4: fmuls   f0, f2, f0
    if (!ppc_fp_available_inline(ctx, 0x8006F9A4u)) return;
    ppc_fmuls(ctx, 0, 2, 0);

label_8006F9A8:
    ctx->pc = 0x8006F9A8u;
    // 8006F9A8: fmuls   f1, f3, f0
    if (!ppc_fp_available_inline(ctx, 0x8006F9A8u)) return;
    ppc_fmuls(ctx, 1, 3, 0);

label_8006F9AC:
    ctx->pc = 0x8006F9ACu;
    // 8006F9AC: lfs     f0, -30388(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006F9ACu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30388);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8006F9B0:
    ctx->pc = 0x8006F9B0u;
    // 8006F9B0: fdivs   f1, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8006F9B0u)) return;
    ppc_fdivs(ctx, 1, 1, 0);

label_8006F9B4:
    // 8006F9B4: bl      0x80247A74
    {
            ctx->lr = 0x8006F9B8u;
            ctx->pc = 0x80247A74u;
            return;
    }

label_8006F9B8:
    ctx->downcount -= 1;
    // 8006F9B8: b       0x8006FA04
    {
            goto label_8006FA04;
    }

label_8006F9BC:
    ctx->pc = 0x8006F9BCu;
    ctx->downcount -= 34;
    // 8006F9BC: lfs     f31, -30424(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006F9BCu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30424);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_8006F9C0:
    ctx->pc = 0x8006F9C0u;
    // 8006F9C0: lfs     f30, -30400(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006F9C0u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30400);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[30] = value;
        ctx->ps1[30] = value;
    }

label_8006F9C4:
    // 8006F9C4: addi    r3, r1, 64
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(64);

label_8006F9C8:
    // 8006F9C8: li      r4, 122
    ctx->gpr[4] = (u32)(s32)(122);

label_8006F9CC:
    ctx->pc = 0x8006F9CCu;
    // 8006F9CC: lfs     f3, -30396(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006F9CCu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30396);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8006F9D0:
    ctx->pc = 0x8006F9D0u;
    // 8006F9D0: lfs     f2, -30392(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006F9D0u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30392);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8006F9D4:
    ctx->pc = 0x8006F9D4u;
    // 8006F9D4: lhz     r0, 48(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(48);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8006F9D8:
    ctx->pc = 0x8006F9D8u;
    // 8006F9D8: lfd     f1, -30408(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006F9D8u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30408);
        ctx->fpr[1] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006F9DC:
    ctx->pc = 0x8006F9DCu;
    // 8006F9DC: stw     r0, 212(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(212);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006F9E0:
    // 8006F9E0: lis     r0, 17200
    ctx->gpr[0] = ((u32)(s32)(17200) << 16);

label_8006F9E4:
    ctx->pc = 0x8006F9E4u;
    // 8006F9E4: stw     r0, 208(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(208);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006F9E8:
    ctx->pc = 0x8006F9E8u;
    // 8006F9E8: lfd     f0, 208(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006F9E8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(208);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006F9EC:
    ctx->pc = 0x8006F9ECu;
    // 8006F9EC: fsubs   f0, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8006F9ECu)) return;
    ppc_fsubs(ctx, 0, 0, 1);

label_8006F9F0:
    ctx->pc = 0x8006F9F0u;
    // 8006F9F0: fmuls   f0, f2, f0
    if (!ppc_fp_available_inline(ctx, 0x8006F9F0u)) return;
    ppc_fmuls(ctx, 0, 2, 0);

label_8006F9F4:
    ctx->pc = 0x8006F9F4u;
    // 8006F9F4: fmuls   f1, f3, f0
    if (!ppc_fp_available_inline(ctx, 0x8006F9F4u)) return;
    ppc_fmuls(ctx, 1, 3, 0);

label_8006F9F8:
    ctx->pc = 0x8006F9F8u;
    // 8006F9F8: lfs     f0, -30388(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006F9F8u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30388);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8006F9FC:
    ctx->pc = 0x8006F9FCu;
    // 8006F9FC: fdivs   f1, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8006F9FCu)) return;
    ppc_fdivs(ctx, 1, 1, 0);

label_8006FA00:
    // 8006FA00: bl      0x80247A74
    {
            ctx->lr = 0x8006FA04u;
            ctx->pc = 0x80247A74u;
            return;
    }

label_8006FA04:
    ctx->downcount -= 5;
    // 8006FA04: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_8006FA08:
    ctx->pc = 0x8006FA08u;
    // 8006FA08: lfs     f1, -30384(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006FA08u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30384);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8006FA0C:
    ctx->pc = 0x8006FA0Cu;
    // 8006FA0C: fmr    f2, f1
    if (!ppc_fp_available_inline(ctx, 0x8006FA0Cu)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_8006FA10:
    ctx->pc = 0x8006FA10u;
    // 8006FA10: lfs     f3, -30424(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006FA10u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30424);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8006FA14:
    // 8006FA14: bl      0x80247C90
    {
            ctx->lr = 0x8006FA18u;
            ctx->pc = 0x80247C90u;
            return;
    }

label_8006FA18:
    ctx->downcount -= 4;
    // 8006FA18: addi    r3, r1, 64
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(64);

label_8006FA1C:
    // 8006FA1C: addi    r4, r1, 16
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(16);

label_8006FA20:
    // 8006FA20: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8006FA24:
    // 8006FA24: bl      0x80247860
    {
            ctx->lr = 0x8006FA28u;
            ctx->pc = 0x80247860u;
            return;
    }

label_8006FA28:
    ctx->downcount -= 5;
    // 8006FA28: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_8006FA2C:
    ctx->pc = 0x8006FA2Cu;
    // 8006FA2C: lfs     f1, -30420(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006FA2Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30420);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8006FA30:
    ctx->pc = 0x8006FA30u;
    // 8006FA30: fmr    f2, f1
    if (!ppc_fp_available_inline(ctx, 0x8006FA30u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_8006FA34:
    ctx->pc = 0x8006FA34u;
    // 8006FA34: lfs     f3, -30424(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006FA34u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30424);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8006FA38:
    // 8006FA38: bl      0x80247C90
    {
            ctx->lr = 0x8006FA3Cu;
            ctx->pc = 0x80247C90u;
            return;
    }

label_8006FA3C:
    ctx->downcount -= 4;
    // 8006FA3C: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_8006FA40:
    // 8006FA40: addi    r4, r1, 64
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(64);

label_8006FA44:
    // 8006FA44: or   r5, r4, r4
    {
        ctx->gpr[5] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8006FA48:
    // 8006FA48: bl      0x80247860
    {
            ctx->lr = 0x8006FA4Cu;
            ctx->pc = 0x80247860u;
            return;
    }

label_8006FA4C:
    ctx->downcount -= 4;
    // 8006FA4C: addi    r3, r1, 64
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(64);

label_8006FA50:
    // 8006FA50: li      r4, 30
    ctx->gpr[4] = (u32)(s32)(30);

label_8006FA54:
    // 8006FA54: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_8006FA58:
    // 8006FA58: bl      0x8025DAD0
    {
            ctx->lr = 0x8006FA5Cu;
            ctx->pc = 0x8025DAD0u;
            return;
    }

label_8006FA5C:
    ctx->downcount -= 4;
    // 8006FA5C: li      r3, 128
    ctx->gpr[3] = (u32)(s32)(128);

label_8006FA60:
    // 8006FA60: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_8006FA64:
    // 8006FA64: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_8006FA68:
    // 8006FA68: bl      0x8025920C
    {
            ctx->lr = 0x8006FA6Cu;
            ctx->pc = 0x8025920Cu;
            return;
    }

label_8006FA6C:
    ctx->pc = 0x8006FA6Cu;
    ctx->downcount -= 35;
    // 8006FA6C: lfs     f2, 8(r31)
    if (!ppc_fp_available_inline(ctx, 0x8006FA6Cu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8006FA70:
    ctx->pc = 0x8006FA70u;
    // 8006FA70: lfs     f1, 4(r31)
    if (!ppc_fp_available_inline(ctx, 0x8006FA70u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8006FA74:
    ctx->pc = 0x8006FA74u;
    // 8006FA74: lfs     f0, 0(r31)
    if (!ppc_fp_available_inline(ctx, 0x8006FA74u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8006FA78:
    // 8006FA78: lis     r3, -13311
    ctx->gpr[3] = ((u32)(s32)(-13311) << 16);

label_8006FA7C:
    ctx->pc = 0x8006FA7Cu;
    // 8006FA7C: stfs     f0, -32768(r3)
    if (!ppc_fp_available_inline(ctx, 0x8006FA7Cu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8006FA80:
    ctx->pc = 0x8006FA80u;
    // 8006FA80: stfs     f1, -32768(r3)
    if (!ppc_fp_available_inline(ctx, 0x8006FA80u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8006FA84:
    ctx->pc = 0x8006FA84u;
    // 8006FA84: stfs     f2, -32768(r3)
    if (!ppc_fp_available_inline(ctx, 0x8006FA84u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_8006FA88:
    ctx->pc = 0x8006FA88u;
    // 8006FA88: lfs     f2, -30424(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006FA88u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30424);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8006FA8C:
    ctx->pc = 0x8006FA8Cu;
    // 8006FA8C: stfs     f2, -32768(r3)
    if (!ppc_fp_available_inline(ctx, 0x8006FA8Cu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_8006FA90:
    ctx->pc = 0x8006FA90u;
    // 8006FA90: stfs     f31, -32768(r3)
    if (!ppc_fp_available_inline(ctx, 0x8006FA90u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8006FA94:
    ctx->pc = 0x8006FA94u;
    // 8006FA94: lfs     f3, 20(r31)
    if (!ppc_fp_available_inline(ctx, 0x8006FA94u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8006FA98:
    ctx->pc = 0x8006FA98u;
    // 8006FA98: lfs     f1, 16(r31)
    if (!ppc_fp_available_inline(ctx, 0x8006FA98u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8006FA9C:
    ctx->pc = 0x8006FA9Cu;
    // 8006FA9C: lfs     f0, 12(r31)
    if (!ppc_fp_available_inline(ctx, 0x8006FA9Cu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8006FAA0:
    ctx->pc = 0x8006FAA0u;
    // 8006FAA0: stfs     f0, -32768(r3)
    if (!ppc_fp_available_inline(ctx, 0x8006FAA0u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8006FAA4:
    ctx->pc = 0x8006FAA4u;
    // 8006FAA4: stfs     f1, -32768(r3)
    if (!ppc_fp_available_inline(ctx, 0x8006FAA4u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8006FAA8:
    ctx->pc = 0x8006FAA8u;
    // 8006FAA8: stfs     f3, -32768(r3)
    if (!ppc_fp_available_inline(ctx, 0x8006FAA8u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[3]));
    }

label_8006FAAC:
    ctx->pc = 0x8006FAACu;
    // 8006FAAC: lfs     f1, -30400(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006FAACu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30400);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8006FAB0:
    ctx->pc = 0x8006FAB0u;
    // 8006FAB0: stfs     f1, -32768(r3)
    if (!ppc_fp_available_inline(ctx, 0x8006FAB0u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8006FAB4:
    ctx->pc = 0x8006FAB4u;
    // 8006FAB4: stfs     f31, -32768(r3)
    if (!ppc_fp_available_inline(ctx, 0x8006FAB4u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8006FAB8:
    ctx->pc = 0x8006FAB8u;
    // 8006FAB8: lfs     f4, 32(r31)
    if (!ppc_fp_available_inline(ctx, 0x8006FAB8u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(32);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[4] = value;
        ctx->ps1[4] = value;
    }

label_8006FABC:
    ctx->pc = 0x8006FABCu;
    // 8006FABC: lfs     f3, 28(r31)
    if (!ppc_fp_available_inline(ctx, 0x8006FABCu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8006FAC0:
    ctx->pc = 0x8006FAC0u;
    // 8006FAC0: lfs     f0, 24(r31)
    if (!ppc_fp_available_inline(ctx, 0x8006FAC0u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8006FAC4:
    ctx->pc = 0x8006FAC4u;
    // 8006FAC4: stfs     f0, -32768(r3)
    if (!ppc_fp_available_inline(ctx, 0x8006FAC4u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8006FAC8:
    ctx->pc = 0x8006FAC8u;
    // 8006FAC8: stfs     f3, -32768(r3)
    if (!ppc_fp_available_inline(ctx, 0x8006FAC8u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[3]));
    }

label_8006FACC:
    ctx->pc = 0x8006FACCu;
    // 8006FACC: stfs     f4, -32768(r3)
    if (!ppc_fp_available_inline(ctx, 0x8006FACCu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[4]));
    }

label_8006FAD0:
    ctx->pc = 0x8006FAD0u;
    // 8006FAD0: stfs     f1, -32768(r3)
    if (!ppc_fp_available_inline(ctx, 0x8006FAD0u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8006FAD4:
    ctx->pc = 0x8006FAD4u;
    // 8006FAD4: stfs     f30, -32768(r3)
    if (!ppc_fp_available_inline(ctx, 0x8006FAD4u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[30]));
    }

label_8006FAD8:
    ctx->pc = 0x8006FAD8u;
    // 8006FAD8: lfs     f3, 44(r31)
    if (!ppc_fp_available_inline(ctx, 0x8006FAD8u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(44);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8006FADC:
    ctx->pc = 0x8006FADCu;
    // 8006FADC: lfs     f1, 40(r31)
    if (!ppc_fp_available_inline(ctx, 0x8006FADCu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8006FAE0:
    ctx->pc = 0x8006FAE0u;
    // 8006FAE0: lfs     f0, 36(r31)
    if (!ppc_fp_available_inline(ctx, 0x8006FAE0u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(36);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8006FAE4:
    ctx->pc = 0x8006FAE4u;
    // 8006FAE4: stfs     f0, -32768(r3)
    if (!ppc_fp_available_inline(ctx, 0x8006FAE4u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8006FAE8:
    ctx->pc = 0x8006FAE8u;
    // 8006FAE8: stfs     f1, -32768(r3)
    if (!ppc_fp_available_inline(ctx, 0x8006FAE8u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8006FAEC:
    ctx->pc = 0x8006FAECu;
    // 8006FAEC: stfs     f3, -32768(r3)
    if (!ppc_fp_available_inline(ctx, 0x8006FAECu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[3]));
    }

label_8006FAF0:
    ctx->pc = 0x8006FAF0u;
    // 8006FAF0: stfs     f2, -32768(r3)
    if (!ppc_fp_available_inline(ctx, 0x8006FAF0u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_8006FAF4:
    ctx->pc = 0x8006FAF4u;
    // 8006FAF4: stfs     f30, -32768(r3)
    if (!ppc_fp_available_inline(ctx, 0x8006FAF4u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[30]));
    }

label_8006FAF8:
    ctx->downcount -= 4;
    // 8006FAF8: addi    r31, r31, 56
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(56);

label_8006FAFC:
    // 8006FAFC: addi    r30, r30, 1
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(1);

label_8006FB00:
    // 8006FB00: cmpwi   r30, 256
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(256);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8006FB04:
    // 8006FB04: bc    12, 0, 0x8006F90C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8006F90Cu;
                return;
            }
            goto label_8006F90C;
        }
    }

label_8006FB08:
    ctx->pc = 0x8006FB08u;
    ctx->downcount -= 1;
    // 8006FB08: bl      0x8000F7A0
    {
            ctx->lr = 0x8006FB0Cu;
            ctx->pc = 0x8000F7A0u;
            return;
    }

label_8006FB0C:
    ctx->pc = 0x8006FB0Cu;
    ctx->downcount -= 11;
    // 8006FB0C: psq_l   f31, 248(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8006FB0Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(248);
        ppc_psq_load_inline(ctx, 31u, ea, false, 0u, false, 0x8006FB0Cu);
        if (ctx->exception) return;
    }

label_8006FB10:
    ctx->pc = 0x8006FB10u;
    // 8006FB10: lfd     f31, 240(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006FB10u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(240);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006FB14:
    ctx->pc = 0x8006FB14u;
    // 8006FB14: psq_l   f30, 232(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8006FB14u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(232);
        ppc_psq_load_inline(ctx, 30u, ea, false, 0u, false, 0x8006FB14u);
        if (ctx->exception) return;
    }

label_8006FB18:
    ctx->pc = 0x8006FB18u;
    // 8006FB18: lfd     f30, 224(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006FB18u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(224);
        ctx->fpr[30] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006FB1C:
    ctx->pc = 0x8006FB1Cu;
    // 8006FB1C: lwz     r31, 220(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(220);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8006FB20:
    ctx->pc = 0x8006FB20u;
    // 8006FB20: lwz     r30, 216(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(216);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8006FB24:
    ctx->pc = 0x8006FB24u;
    // 8006FB24: lwz     r0, 260(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(260);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8006FB28:
    ctx->pc = 0x8006FB28u;
    // 8006FB28: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8006FB2C:
    ctx->pc = 0x8006FB2Cu;
    // 8006FB2C: addi    r1, r1, 256
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(256);

label_8006FB30:
    ctx->pc = 0x8006FB30u;
    // 8006FB30: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_8006FB34:
    ctx->pc = 0x8006FB34u;
    ctx->downcount -= 7;
    // 8006FB34: stwu     r1, -96(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-96);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8006FB38:
    ctx->pc = 0x8006FB38u;
    // 8006FB38: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8006FB3C:
    ctx->pc = 0x8006FB3Cu;
    // 8006FB3C: stw     r0, 100(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(100);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006FB40:
    ctx->pc = 0x8006FB40u;
    // 8006FB40: stfd     f31, 80(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006FB40u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_8006FB44:
    ctx->pc = 0x8006FB44u;
    // 8006FB44: psq_st   f31, 88(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8006FB44u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        ppc_psq_store_inline(ctx, 31u, ea, false, 0u, false, 0x8006FB44u);
        if (ctx->exception) return;
    }

label_8006FB48:
    ctx->pc = 0x8006FB48u;
    // 8006FB48: addi    r11, r1, 80
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(80);

label_8006FB4C:
    ctx->pc = 0x8006FB4Cu;
    // 8006FB4C: bl      0x80286A4C
    {
            ctx->lr = 0x8006FB50u;
            ctx->pc = 0x80286A4Cu;
            return;
    }

label_8006FB50:
    ctx->pc = 0x8006FB50u;
    ctx->downcount -= 9;
    // 8006FB50: or   r27, r3, r3
    {
        ctx->gpr[27] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8006FB54:
    ctx->pc = 0x8006FB54u;
    // 8006FB54: or   r28, r4, r4
    {
        ctx->gpr[28] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8006FB58:
    ctx->pc = 0x8006FB58u;
    // 8006FB58: or   r29, r5, r5
    {
        ctx->gpr[29] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8006FB5C:
    ctx->pc = 0x8006FB5Cu;
    // 8006FB5C: or   r30, r6, r6
    {
        ctx->gpr[30] = ctx->gpr[6] | ctx->gpr[6];
    }

label_8006FB60:
    ctx->pc = 0x8006FB60u;
    // 8006FB60: lis     r3, -32711
    ctx->gpr[3] = ((u32)(s32)(-32711) << 16);

label_8006FB64:
    ctx->pc = 0x8006FB64u;
    // 8006FB64: addi    r31, r3, 14112
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(14112);

label_8006FB68:
    ctx->pc = 0x8006FB68u;
    // 8006FB68: lha     r0, 68(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(68);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8006FB6C:
    ctx->pc = 0x8006FB6Cu;
    // 8006FB6C: cmpwi   r0, 1
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

label_8006FB70:
    ctx->pc = 0x8006FB70u;
    // 8006FB70: bc    4, 2, 0x8006FB80
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8006FB80;
        }
    }

label_8006FB74:
    ctx->pc = 0x8006FB74u;
    ctx->downcount -= 3;
    // 8006FB74: lbz     r0, 173(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(173);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8006FB78:
    ctx->pc = 0x8006FB78u;
    // 8006FB78: stb     r0, -24984(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24984);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FB7C:
    ctx->pc = 0x8006FB7Cu;
    // 8006FB7C: b       0x8006FB94
    {
            goto label_8006FB94;
    }

label_8006FB80:
    ctx->pc = 0x8006FB80u;
    ctx->downcount -= 3;
    // 8006FB80: lha     r0, 70(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(70);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8006FB84:
    ctx->pc = 0x8006FB84u;
    // 8006FB84: cmpwi   r0, 1046
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(1046);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8006FB88:
    ctx->pc = 0x8006FB88u;
    // 8006FB88: bc    4, 2, 0x8006FB94
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8006FB94;
        }
    }

label_8006FB8C:
    ctx->pc = 0x8006FB8Cu;
    ctx->downcount -= 2;
    // 8006FB8C: li      r0, 3
    ctx->gpr[0] = (u32)(s32)(3);

label_8006FB90:
    ctx->pc = 0x8006FB90u;
    // 8006FB90: stb     r0, -24984(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24984);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FB94:
    ctx->pc = 0x8006FB94u;
    ctx->downcount -= 8;
    // 8006FB94: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8006FB98:
    ctx->pc = 0x8006FB98u;
    // 8006FB98: lfs     f1, 12(r27)
    if (!ppc_fp_available_inline(ctx, 0x8006FB98u)) return;
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8006FB9C:
    ctx->pc = 0x8006FB9Cu;
    // 8006FB9C: lfs     f2, 16(r27)
    if (!ppc_fp_available_inline(ctx, 0x8006FB9Cu)) return;
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8006FBA0:
    ctx->pc = 0x8006FBA0u;
    // 8006FBA0: lfs     f3, 20(r27)
    if (!ppc_fp_available_inline(ctx, 0x8006FBA0u)) return;
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(20);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8006FBA4:
    ctx->pc = 0x8006FBA4u;
    // 8006FBA4: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_8006FBA8:
    ctx->pc = 0x8006FBA8u;
    // 8006FBA8: addi    r5, r1, 12
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(12);

label_8006FBAC:
    ctx->pc = 0x8006FBACu;
    // 8006FBAC: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8006FBB0:
    ctx->pc = 0x8006FBB0u;
    // 8006FBB0: bl      0x8006594C
    {
            ctx->lr = 0x8006FBB4u;
            ctx->pc = 0x8006594Cu;
            return;
    }

label_8006FBB4:
    ctx->pc = 0x8006FBB4u;
    ctx->downcount -= 2;
    // 8006FBB4: cmpwi   r3, 0
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

label_8006FBB8:
    ctx->pc = 0x8006FBB8u;
    // 8006FBB8: bc    4, 2, 0x8006FDC4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8006FDC4;
        }
    }

label_8006FBBC:
    ctx->pc = 0x8006FBBCu;
    ctx->downcount -= 3;
    // 8006FBBC: rlwinm r0, r30, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[30], 0u) & 0x000000FFu;
    }

label_8006FBC0:
    ctx->pc = 0x8006FBC0u;
    // 8006FBC0: cmplwi  r0, 0x0001
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0001u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8006FBC4:
    ctx->pc = 0x8006FBC4u;
    // 8006FBC4: bc    4, 2, 0x8006FC28
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8006FC28;
        }
    }

label_8006FBC8:
    ctx->pc = 0x8006FBC8u;
    ctx->downcount -= 22;
    // 8006FBC8: lfs     f0, 0(r28)
    if (!ppc_fp_available_inline(ctx, 0x8006FBC8u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8006FBCC:
    ctx->pc = 0x8006FBCCu;
    // 8006FBCC: lbz     r4, -24976(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24976);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_8006FBD0:
    ctx->pc = 0x8006FBD0u;
    // 8006FBD0: rlwinm r0, r4, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 4u) & 0xFFFFFFF0u;
    }

label_8006FBD4:
    ctx->pc = 0x8006FBD4u;
    // 8006FBD4: add   r3, r31, r0
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8006FBD8:
    ctx->pc = 0x8006FBD8u;
    // 8006FBD8: stfs     f0, 32(r3)
    if (!ppc_fp_available_inline(ctx, 0x8006FBD8u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(32);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8006FBDC:
    ctx->pc = 0x8006FBDCu;
    // 8006FBDC: lfs     f1, -30396(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006FBDCu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30396);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8006FBE0:
    ctx->pc = 0x8006FBE0u;
    // 8006FBE0: lfs     f0, 4(r28)
    if (!ppc_fp_available_inline(ctx, 0x8006FBE0u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8006FBE4:
    ctx->pc = 0x8006FBE4u;
    // 8006FBE4: fadds   f0, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8006FBE4u)) return;
    ppc_fadds(ctx, 0, 1, 0);

label_8006FBE8:
    ctx->pc = 0x8006FBE8u;
    // 8006FBE8: stfs     f0, 36(r3)
    if (!ppc_fp_available_inline(ctx, 0x8006FBE8u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(36);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8006FBEC:
    ctx->pc = 0x8006FBECu;
    // 8006FBEC: lfs     f0, 8(r28)
    if (!ppc_fp_available_inline(ctx, 0x8006FBECu)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8006FBF0:
    ctx->pc = 0x8006FBF0u;
    // 8006FBF0: stfs     f0, 40(r3)
    if (!ppc_fp_available_inline(ctx, 0x8006FBF0u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8006FBF4:
    ctx->pc = 0x8006FBF4u;
    // 8006FBF4: lha     r0, 0(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(0);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8006FBF8:
    ctx->pc = 0x8006FBF8u;
    // 8006FBF8: rlwinm r0, r0, 0, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x0000FFFFu;
    }

label_8006FBFC:
    ctx->pc = 0x8006FBFCu;
    // 8006FBFC: sth     r0, 44(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(44);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8006FC00:
    ctx->pc = 0x8006FC00u;
    // 8006FC00: li      r0, 255
    ctx->gpr[0] = (u32)(s32)(255);

label_8006FC04:
    ctx->pc = 0x8006FC04u;
    // 8006FC04: stb     r0, 46(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(46);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FC08:
    ctx->pc = 0x8006FC08u;
    // 8006FC08: stb     r29, 47(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(47);
        mem_write8(ctx, ea, (u8)ctx->gpr[29]);
    }

label_8006FC0C:
    ctx->pc = 0x8006FC0Cu;
    // 8006FC0C: addi    r0, r4, 1
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(1);

label_8006FC10:
    ctx->pc = 0x8006FC10u;
    // 8006FC10: stb     r0, -24976(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24976);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FC14:
    ctx->pc = 0x8006FC14u;
    // 8006FC14: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_8006FC18:
    ctx->pc = 0x8006FC18u;
    // 8006FC18: cmpwi   r0, 256
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(256);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8006FC1C:
    ctx->pc = 0x8006FC1Cu;
    // 8006FC1C: bc    12, 0, 0x8006FC28
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8006FC28;
        }
    }

label_8006FC20:
    ctx->pc = 0x8006FC20u;
    ctx->downcount -= 2;
    // 8006FC20: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8006FC24:
    ctx->pc = 0x8006FC24u;
    // 8006FC24: stb     r0, -24976(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24976);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FC28:
    ctx->pc = 0x8006FC28u;
    ctx->downcount -= 3;
    // 8006FC28: addi    r3, r1, 12
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(12);

label_8006FC2C:
    ctx->pc = 0x8006FC2Cu;
    // 8006FC2C: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8006FC30:
    ctx->pc = 0x8006FC30u;
    // 8006FC30: bl      0x80248140
    {
            ctx->lr = 0x8006FC34u;
            ctx->pc = 0x80248140u;
            return;
    }

label_8006FC34:
    ctx->pc = 0x8006FC34u;
    ctx->downcount -= 8;
    // 8006FC34: lfs     f0, -30400(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006FC34u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30400);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8006FC38:
    ctx->pc = 0x8006FC38u;
    // 8006FC38: stfs     f0, 36(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006FC38u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8006FC3C:
    ctx->pc = 0x8006FC3Cu;
    // 8006FC3C: lfs     f0, -30424(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006FC3Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30424);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8006FC40:
    ctx->pc = 0x8006FC40u;
    // 8006FC40: stfs     f0, 40(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006FC40u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8006FC44:
    ctx->pc = 0x8006FC44u;
    // 8006FC44: stfs     f0, 44(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006FC44u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8006FC48:
    ctx->pc = 0x8006FC48u;
    // 8006FC48: addi    r3, r1, 12
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(12);

label_8006FC4C:
    ctx->pc = 0x8006FC4Cu;
    // 8006FC4C: addi    r4, r1, 36
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(36);

label_8006FC50:
    ctx->pc = 0x8006FC50u;
    // 8006FC50: bl      0x802481D8
    {
            ctx->lr = 0x8006FC54u;
            ctx->pc = 0x802481D8u;
            return;
    }

label_8006FC54:
    ctx->pc = 0x8006FC54u;
    ctx->downcount -= 5;
    // 8006FC54: fabs    f1, f1
    if (!ppc_fp_available_inline(ctx, 0x8006FC54u)) return;
    ctx->fpr[1] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[1]) & 0x7FFFFFFFFFFFFFFFull);

label_8006FC58:
    ctx->pc = 0x8006FC58u;
    // 8006FC58: lfs     f0, -30368(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006FC58u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30368);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8006FC5C:
    ctx->pc = 0x8006FC5Cu;
    // 8006FC5C: fcmpo   cr0, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8006FC5Cu)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[1], ctx->fpr[0], true);

label_8006FC60:
    ctx->pc = 0x8006FC60u;
    // 8006FC60: cror    2, 1, 2
    {
        u32 a = (ctx->cr >> (31u - 1u)) & 1u;
        u32 b = (ctx->cr >> (31u - 2u)) & 1u;
        u32 mask = 0x80000000u >> 2;
        u32 value = (a | b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8006FC64:
    ctx->pc = 0x8006FC64u;
    // 8006FC64: bc    4, 2, 0x8006FC78
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8006FC78;
        }
    }

label_8006FC68:
    ctx->pc = 0x8006FC68u;
    ctx->downcount -= 4;
    // 8006FC68: lfs     f0, -30424(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006FC68u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30424);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8006FC6C:
    ctx->pc = 0x8006FC6Cu;
    // 8006FC6C: stfs     f0, 36(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006FC6Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8006FC70:
    ctx->pc = 0x8006FC70u;
    // 8006FC70: lfs     f0, -30400(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006FC70u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30400);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8006FC74:
    ctx->pc = 0x8006FC74u;
    // 8006FC74: stfs     f0, 44(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006FC74u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8006FC78:
    ctx->pc = 0x8006FC78u;
    ctx->downcount -= 4;
    // 8006FC78: addi    r3, r1, 12
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(12);

label_8006FC7C:
    ctx->pc = 0x8006FC7Cu;
    // 8006FC7C: addi    r4, r1, 36
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(36);

label_8006FC80:
    ctx->pc = 0x8006FC80u;
    // 8006FC80: addi    r5, r1, 24
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(24);

label_8006FC84:
    ctx->pc = 0x8006FC84u;
    // 8006FC84: bl      0x802481F8
    {
            ctx->lr = 0x8006FC88u;
            ctx->pc = 0x802481F8u;
            return;
    }

label_8006FC88:
    ctx->pc = 0x8006FC88u;
    ctx->downcount -= 4;
    // 8006FC88: addi    r3, r1, 24
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(24);

label_8006FC8C:
    ctx->pc = 0x8006FC8Cu;
    // 8006FC8C: addi    r4, r1, 12
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(12);

label_8006FC90:
    ctx->pc = 0x8006FC90u;
    // 8006FC90: addi    r5, r1, 36
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(36);

label_8006FC94:
    ctx->pc = 0x8006FC94u;
    // 8006FC94: bl      0x802481F8
    {
            ctx->lr = 0x8006FC98u;
            ctx->pc = 0x802481F8u;
            return;
    }

label_8006FC98:
    ctx->pc = 0x8006FC98u;
    ctx->downcount -= 3;
    // 8006FC98: addi    r3, r1, 36
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(36);

label_8006FC9C:
    ctx->pc = 0x8006FC9Cu;
    // 8006FC9C: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8006FCA0:
    ctx->pc = 0x8006FCA0u;
    // 8006FCA0: bl      0x80248140
    {
            ctx->lr = 0x8006FCA4u;
            ctx->pc = 0x80248140u;
            return;
    }

label_8006FCA4:
    ctx->pc = 0x8006FCA4u;
    ctx->downcount -= 3;
    // 8006FCA4: addi    r3, r1, 24
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(24);

label_8006FCA8:
    ctx->pc = 0x8006FCA8u;
    // 8006FCA8: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8006FCAC:
    ctx->pc = 0x8006FCACu;
    // 8006FCAC: bl      0x80248140
    {
            ctx->lr = 0x8006FCB0u;
            ctx->pc = 0x80248140u;
            return;
    }

label_8006FCB0:
    ctx->pc = 0x8006FCB0u;
    ctx->downcount -= 7;
    // 8006FCB0: lbz     r0, -24984(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24984);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8006FCB4:
    ctx->pc = 0x8006FCB4u;
    // 8006FCB4: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_8006FCB8:
    ctx->pc = 0x8006FCB8u;
    // 8006FCB8: lfsx    f31, r31, r0
    if (!ppc_fp_available_inline(ctx, 0x8006FCB8u)) return;
    {
        u32 ea = ctx->gpr[31] + ctx->gpr[0];
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_8006FCBC:
    ctx->pc = 0x8006FCBCu;
    // 8006FCBC: addi    r3, r1, 36
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(36);

label_8006FCC0:
    ctx->pc = 0x8006FCC0u;
    // 8006FCC0: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8006FCC4:
    ctx->pc = 0x8006FCC4u;
    // 8006FCC4: fmr    f1, f31
    if (!ppc_fp_available_inline(ctx, 0x8006FCC4u)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_8006FCC8:
    ctx->pc = 0x8006FCC8u;
    // 8006FCC8: bl      0x80248124
    {
            ctx->lr = 0x8006FCCCu;
            ctx->pc = 0x80248124u;
            return;
    }

label_8006FCCC:
    ctx->pc = 0x8006FCCCu;
    ctx->downcount -= 4;
    // 8006FCCC: addi    r3, r1, 24
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(24);

label_8006FCD0:
    ctx->pc = 0x8006FCD0u;
    // 8006FCD0: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8006FCD4:
    ctx->pc = 0x8006FCD4u;
    // 8006FCD4: fmr    f1, f31
    if (!ppc_fp_available_inline(ctx, 0x8006FCD4u)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_8006FCD8:
    ctx->pc = 0x8006FCD8u;
    // 8006FCD8: bl      0x80248124
    {
            ctx->lr = 0x8006FCDCu;
            ctx->pc = 0x80248124u;
            return;
    }

label_8006FCDC:
    ctx->pc = 0x8006FCDCu;
    ctx->downcount -= 58;
    // 8006FCDC: lfs     f1, 0(r28)
    if (!ppc_fp_available_inline(ctx, 0x8006FCDCu)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8006FCE0:
    ctx->pc = 0x8006FCE0u;
    // 8006FCE0: lfs     f2, 4(r28)
    if (!ppc_fp_available_inline(ctx, 0x8006FCE0u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8006FCE4:
    ctx->pc = 0x8006FCE4u;
    // 8006FCE4: lfs     f3, 8(r28)
    if (!ppc_fp_available_inline(ctx, 0x8006FCE4u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8006FCE8:
    ctx->pc = 0x8006FCE8u;
    // 8006FCE8: lfs     f4, 36(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006FCE8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[4] = value;
        ctx->ps1[4] = value;
    }

label_8006FCEC:
    ctx->pc = 0x8006FCECu;
    // 8006FCEC: fsubs   f10, f1, f4
    if (!ppc_fp_available_inline(ctx, 0x8006FCECu)) return;
    ppc_fsubs(ctx, 10, 1, 4);

label_8006FCF0:
    ctx->pc = 0x8006FCF0u;
    // 8006FCF0: lfs     f5, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006FCF0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[5] = value;
        ctx->ps1[5] = value;
    }

label_8006FCF4:
    ctx->pc = 0x8006FCF4u;
    // 8006FCF4: fsubs   f0, f10, f5
    if (!ppc_fp_available_inline(ctx, 0x8006FCF4u)) return;
    ppc_fsubs(ctx, 0, 10, 5);

label_8006FCF8:
    ctx->pc = 0x8006FCF8u;
    // 8006FCF8: lbz     r5, -24975(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24975);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_8006FCFC:
    ctx->pc = 0x8006FCFCu;
    // 8006FCFC: mulli   r0, r5, 56
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[5] * (s64)(s32)56);

label_8006FD00:
    ctx->pc = 0x8006FD00u;
    // 8006FD00: add   r4, r31, r0
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_8006FD04:
    ctx->pc = 0x8006FD04u;
    // 8006FD04: stfs     f0, 4128(r4)
    if (!ppc_fp_available_inline(ctx, 0x8006FD04u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4128);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8006FD08:
    ctx->pc = 0x8006FD08u;
    // 8006FD08: lfs     f6, 40(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006FD08u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[6] = value;
        ctx->ps1[6] = value;
    }

label_8006FD0C:
    ctx->pc = 0x8006FD0Cu;
    // 8006FD0C: fsubs   f11, f2, f6
    if (!ppc_fp_available_inline(ctx, 0x8006FD0Cu)) return;
    ppc_fsubs(ctx, 11, 2, 6);

label_8006FD10:
    ctx->pc = 0x8006FD10u;
    // 8006FD10: lfs     f7, 28(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006FD10u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[7] = value;
        ctx->ps1[7] = value;
    }

label_8006FD14:
    ctx->pc = 0x8006FD14u;
    // 8006FD14: fsubs   f0, f11, f7
    if (!ppc_fp_available_inline(ctx, 0x8006FD14u)) return;
    ppc_fsubs(ctx, 0, 11, 7);

label_8006FD18:
    ctx->pc = 0x8006FD18u;
    // 8006FD18: stfs     f0, 4132(r4)
    if (!ppc_fp_available_inline(ctx, 0x8006FD18u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4132);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8006FD1C:
    ctx->pc = 0x8006FD1Cu;
    // 8006FD1C: lfs     f8, 44(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006FD1Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[8] = value;
        ctx->ps1[8] = value;
    }

label_8006FD20:
    ctx->pc = 0x8006FD20u;
    // 8006FD20: fsubs   f12, f3, f8
    if (!ppc_fp_available_inline(ctx, 0x8006FD20u)) return;
    ppc_fsubs(ctx, 12, 3, 8);

label_8006FD24:
    ctx->pc = 0x8006FD24u;
    // 8006FD24: lfs     f9, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006FD24u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[9] = value;
        ctx->ps1[9] = value;
    }

label_8006FD28:
    ctx->pc = 0x8006FD28u;
    // 8006FD28: fsubs   f0, f12, f9
    if (!ppc_fp_available_inline(ctx, 0x8006FD28u)) return;
    ppc_fsubs(ctx, 0, 12, 9);

label_8006FD2C:
    ctx->pc = 0x8006FD2Cu;
    // 8006FD2C: stfs     f0, 4136(r4)
    if (!ppc_fp_available_inline(ctx, 0x8006FD2Cu)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4136);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8006FD30:
    ctx->pc = 0x8006FD30u;
    // 8006FD30: fadds   f1, f1, f4
    if (!ppc_fp_available_inline(ctx, 0x8006FD30u)) return;
    ppc_fadds(ctx, 1, 1, 4);

label_8006FD34:
    ctx->pc = 0x8006FD34u;
    // 8006FD34: fsubs   f0, f1, f5
    if (!ppc_fp_available_inline(ctx, 0x8006FD34u)) return;
    ppc_fsubs(ctx, 0, 1, 5);

label_8006FD38:
    ctx->pc = 0x8006FD38u;
    // 8006FD38: stfs     f0, 4140(r4)
    if (!ppc_fp_available_inline(ctx, 0x8006FD38u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4140);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8006FD3C:
    ctx->pc = 0x8006FD3Cu;
    // 8006FD3C: fadds   f2, f2, f6
    if (!ppc_fp_available_inline(ctx, 0x8006FD3Cu)) return;
    ppc_fadds(ctx, 2, 2, 6);

label_8006FD40:
    ctx->pc = 0x8006FD40u;
    // 8006FD40: fsubs   f0, f2, f7
    if (!ppc_fp_available_inline(ctx, 0x8006FD40u)) return;
    ppc_fsubs(ctx, 0, 2, 7);

label_8006FD44:
    ctx->pc = 0x8006FD44u;
    // 8006FD44: stfs     f0, 4144(r4)
    if (!ppc_fp_available_inline(ctx, 0x8006FD44u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4144);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8006FD48:
    ctx->pc = 0x8006FD48u;
    // 8006FD48: fadds   f3, f3, f8
    if (!ppc_fp_available_inline(ctx, 0x8006FD48u)) return;
    ppc_fadds(ctx, 3, 3, 8);

label_8006FD4C:
    ctx->pc = 0x8006FD4Cu;
    // 8006FD4C: fsubs   f0, f3, f9
    if (!ppc_fp_available_inline(ctx, 0x8006FD4Cu)) return;
    ppc_fsubs(ctx, 0, 3, 9);

label_8006FD50:
    ctx->pc = 0x8006FD50u;
    // 8006FD50: stfs     f0, 4148(r4)
    if (!ppc_fp_available_inline(ctx, 0x8006FD50u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4148);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8006FD54:
    ctx->pc = 0x8006FD54u;
    // 8006FD54: fadds   f0, f5, f1
    if (!ppc_fp_available_inline(ctx, 0x8006FD54u)) return;
    ppc_fadds(ctx, 0, 5, 1);

label_8006FD58:
    ctx->pc = 0x8006FD58u;
    // 8006FD58: stfs     f0, 4152(r4)
    if (!ppc_fp_available_inline(ctx, 0x8006FD58u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4152);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8006FD5C:
    ctx->pc = 0x8006FD5Cu;
    // 8006FD5C: fadds   f0, f7, f2
    if (!ppc_fp_available_inline(ctx, 0x8006FD5Cu)) return;
    ppc_fadds(ctx, 0, 7, 2);

label_8006FD60:
    ctx->pc = 0x8006FD60u;
    // 8006FD60: stfs     f0, 4156(r4)
    if (!ppc_fp_available_inline(ctx, 0x8006FD60u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4156);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8006FD64:
    ctx->pc = 0x8006FD64u;
    // 8006FD64: fadds   f0, f9, f3
    if (!ppc_fp_available_inline(ctx, 0x8006FD64u)) return;
    ppc_fadds(ctx, 0, 9, 3);

label_8006FD68:
    ctx->pc = 0x8006FD68u;
    // 8006FD68: stfs     f0, 4160(r4)
    if (!ppc_fp_available_inline(ctx, 0x8006FD68u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4160);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8006FD6C:
    ctx->pc = 0x8006FD6Cu;
    // 8006FD6C: fadds   f0, f5, f10
    if (!ppc_fp_available_inline(ctx, 0x8006FD6Cu)) return;
    ppc_fadds(ctx, 0, 5, 10);

label_8006FD70:
    ctx->pc = 0x8006FD70u;
    // 8006FD70: stfs     f0, 4164(r4)
    if (!ppc_fp_available_inline(ctx, 0x8006FD70u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4164);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8006FD74:
    ctx->pc = 0x8006FD74u;
    // 8006FD74: fadds   f0, f7, f11
    if (!ppc_fp_available_inline(ctx, 0x8006FD74u)) return;
    ppc_fadds(ctx, 0, 7, 11);

label_8006FD78:
    ctx->pc = 0x8006FD78u;
    // 8006FD78: stfs     f0, 4168(r4)
    if (!ppc_fp_available_inline(ctx, 0x8006FD78u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4168);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8006FD7C:
    ctx->pc = 0x8006FD7Cu;
    // 8006FD7C: fadds   f0, f9, f12
    if (!ppc_fp_available_inline(ctx, 0x8006FD7Cu)) return;
    ppc_fadds(ctx, 0, 9, 12);

label_8006FD80:
    ctx->pc = 0x8006FD80u;
    // 8006FD80: stfs     f0, 4172(r4)
    if (!ppc_fp_available_inline(ctx, 0x8006FD80u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4172);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8006FD84:
    ctx->pc = 0x8006FD84u;
    // 8006FD84: lha     r3, 0(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(0);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8006FD88:
    ctx->pc = 0x8006FD88u;
    // 8006FD88: lis     r0, 1
    ctx->gpr[0] = ((u32)(s32)(1) << 16);

label_8006FD8C:
    ctx->pc = 0x8006FD8Cu;
    // 8006FD8C: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_8006FD90:
    ctx->pc = 0x8006FD90u;
    // 8006FD90: rlwinm r0, r0, 0, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x0000FFFFu;
    }

label_8006FD94:
    ctx->pc = 0x8006FD94u;
    // 8006FD94: sth     r0, 4176(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4176);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8006FD98:
    ctx->pc = 0x8006FD98u;
    // 8006FD98: stb     r30, 4178(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4178);
        mem_write8(ctx, ea, (u8)ctx->gpr[30]);
    }

label_8006FD9C:
    ctx->pc = 0x8006FD9Cu;
    // 8006FD9C: li      r0, 255
    ctx->gpr[0] = (u32)(s32)(255);

label_8006FDA0:
    ctx->pc = 0x8006FDA0u;
    // 8006FDA0: stb     r0, 4179(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4179);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FDA4:
    ctx->pc = 0x8006FDA4u;
    // 8006FDA4: stb     r29, 4180(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4180);
        mem_write8(ctx, ea, (u8)ctx->gpr[29]);
    }

label_8006FDA8:
    ctx->pc = 0x8006FDA8u;
    // 8006FDA8: addi    r0, r5, 1
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(1);

label_8006FDAC:
    ctx->pc = 0x8006FDACu;
    // 8006FDAC: stb     r0, -24975(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24975);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FDB0:
    ctx->pc = 0x8006FDB0u;
    // 8006FDB0: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_8006FDB4:
    ctx->pc = 0x8006FDB4u;
    // 8006FDB4: cmpwi   r0, 256
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(256);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8006FDB8:
    ctx->pc = 0x8006FDB8u;
    // 8006FDB8: bc    12, 0, 0x8006FDC4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8006FDC4;
        }
    }

label_8006FDBC:
    ctx->pc = 0x8006FDBCu;
    ctx->downcount -= 2;
    // 8006FDBC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8006FDC0:
    ctx->pc = 0x8006FDC0u;
    // 8006FDC0: stb     r0, -24975(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24975);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FDC4:
    ctx->pc = 0x8006FDC4u;
    ctx->downcount -= 4;
    // 8006FDC4: psq_l   f31, 88(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8006FDC4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        ppc_psq_load_inline(ctx, 31u, ea, false, 0u, false, 0x8006FDC4u);
        if (ctx->exception) return;
    }

label_8006FDC8:
    ctx->pc = 0x8006FDC8u;
    // 8006FDC8: lfd     f31, 80(r1)
    if (!ppc_fp_available_inline(ctx, 0x8006FDC8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8006FDCC:
    ctx->pc = 0x8006FDCCu;
    // 8006FDCC: addi    r11, r1, 80
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(80);

label_8006FDD0:
    ctx->pc = 0x8006FDD0u;
    // 8006FDD0: bl      0x80286A98
    {
            ctx->lr = 0x8006FDD4u;
            ctx->pc = 0x80286A98u;
            return;
    }

label_8006FDD4:
    ctx->pc = 0x8006FDD4u;
    ctx->downcount -= 5;
    // 8006FDD4: lwz     r0, 100(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(100);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8006FDD8:
    ctx->pc = 0x8006FDD8u;
    // 8006FDD8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8006FDDC:
    ctx->pc = 0x8006FDDCu;
    // 8006FDDC: addi    r1, r1, 96
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(96);

label_8006FDE0:
    ctx->pc = 0x8006FDE0u;
    // 8006FDE0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_8006FDE4:
    ctx->pc = 0x8006FDE4u;
    ctx->downcount -= 4;
    // 8006FDE4: rlwinm r0, r3, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000000FFu;
    }

label_8006FDE8:
    ctx->pc = 0x8006FDE8u;
    // 8006FDE8: stb     r0, -24974(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24974);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FDEC:
    ctx->pc = 0x8006FDECu;
    // 8006FDEC: cmpwi   r3, 0
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

label_8006FDF0:
    ctx->pc = 0x8006FDF0u;
    // 8006FDF0: bclr  4, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_8006FDF4:
    ctx->pc = 0x8006FDF4u;
    ctx->downcount -= 7;
    // 8006FDF4: lis     r3, -32711
    ctx->gpr[3] = ((u32)(s32)(-32711) << 16);

label_8006FDF8:
    ctx->pc = 0x8006FDF8u;
    // 8006FDF8: addi    r4, r3, 18240
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(18240);

label_8006FDFC:
    ctx->pc = 0x8006FDFCu;
    // 8006FDFC: lis     r3, -32711
    ctx->gpr[3] = ((u32)(s32)(-32711) << 16);

label_8006FE00:
    ctx->pc = 0x8006FE00u;
    // 8006FE00: addi    r3, r3, 14144
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(14144);

label_8006FE04:
    ctx->pc = 0x8006FE04u;
    // 8006FE04: li      r0, 16
    ctx->gpr[0] = (u32)(s32)(16);

label_8006FE08:
    ctx->pc = 0x8006FE08u;
    // 8006FE08: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8006FE0C:
    loop_8006FE0C(ctx);
    if (ctx->pc == 0x8006FEA4u) goto label_8006FEA4;
    return;
label_8006FE10:
    ctx->pc = 0x8006FE10u;
    // 8006FE10: stb     r0, 51(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(51);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FE14:
    ctx->pc = 0x8006FE14u;
    // 8006FE14: stb     r0, 14(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(14);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FE18:
    ctx->pc = 0x8006FE18u;
    // 8006FE18: stb     r0, 107(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(107);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FE1C:
    ctx->pc = 0x8006FE1Cu;
    // 8006FE1C: stb     r0, 30(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(30);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FE20:
    ctx->pc = 0x8006FE20u;
    // 8006FE20: stb     r0, 163(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(163);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FE24:
    ctx->pc = 0x8006FE24u;
    // 8006FE24: stb     r0, 46(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(46);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FE28:
    ctx->pc = 0x8006FE28u;
    // 8006FE28: stb     r0, 219(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(219);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FE2C:
    ctx->pc = 0x8006FE2Cu;
    // 8006FE2C: stb     r0, 62(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(62);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FE30:
    ctx->pc = 0x8006FE30u;
    // 8006FE30: stb     r0, 275(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(275);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FE34:
    ctx->pc = 0x8006FE34u;
    // 8006FE34: stb     r0, 78(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(78);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FE38:
    ctx->pc = 0x8006FE38u;
    // 8006FE38: stb     r0, 331(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(331);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FE3C:
    ctx->pc = 0x8006FE3Cu;
    // 8006FE3C: stb     r0, 94(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(94);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FE40:
    ctx->pc = 0x8006FE40u;
    // 8006FE40: stb     r0, 387(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(387);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FE44:
    ctx->pc = 0x8006FE44u;
    // 8006FE44: stb     r0, 110(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(110);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FE48:
    ctx->pc = 0x8006FE48u;
    // 8006FE48: stb     r0, 443(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(443);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FE4C:
    ctx->pc = 0x8006FE4Cu;
    // 8006FE4C: stb     r0, 126(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(126);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FE50:
    // 8006FE50: addi    r4, r4, 448
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(448);

label_8006FE54:
    // 8006FE54: addi    r3, r3, 128
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(128);

label_8006FE58:
    ctx->pc = 0x8006FE58u;
    // 8006FE58: stb     r0, 51(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(51);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FE5C:
    ctx->pc = 0x8006FE5Cu;
    // 8006FE5C: stb     r0, 14(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(14);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FE60:
    ctx->pc = 0x8006FE60u;
    // 8006FE60: stb     r0, 107(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(107);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FE64:
    ctx->pc = 0x8006FE64u;
    // 8006FE64: stb     r0, 30(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(30);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FE68:
    ctx->pc = 0x8006FE68u;
    // 8006FE68: stb     r0, 163(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(163);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FE6C:
    ctx->pc = 0x8006FE6Cu;
    // 8006FE6C: stb     r0, 46(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(46);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FE70:
    ctx->pc = 0x8006FE70u;
    // 8006FE70: stb     r0, 219(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(219);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FE74:
    ctx->pc = 0x8006FE74u;
    // 8006FE74: stb     r0, 62(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(62);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FE78:
    ctx->pc = 0x8006FE78u;
    // 8006FE78: stb     r0, 275(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(275);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FE7C:
    ctx->pc = 0x8006FE7Cu;
    // 8006FE7C: stb     r0, 78(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(78);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FE80:
    ctx->pc = 0x8006FE80u;
    // 8006FE80: stb     r0, 331(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(331);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FE84:
    ctx->pc = 0x8006FE84u;
    // 8006FE84: stb     r0, 94(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(94);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FE88:
    ctx->pc = 0x8006FE88u;
    // 8006FE88: stb     r0, 387(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(387);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FE8C:
    ctx->pc = 0x8006FE8Cu;
    // 8006FE8C: stb     r0, 110(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(110);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FE90:
    ctx->pc = 0x8006FE90u;
    // 8006FE90: stb     r0, 443(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(443);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FE94:
    ctx->pc = 0x8006FE94u;
    // 8006FE94: stb     r0, 126(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(126);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FE98:
    // 8006FE98: addi    r4, r4, 448
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(448);

label_8006FE9C:
    // 8006FE9C: addi    r3, r3, 128
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(128);

label_8006FEA0:
    // 8006FEA0: bc    16, 0, 0x8006FE0C
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8006FE0Cu;
                return;
            }
            goto label_8006FE0C;
        }
    }

label_8006FEA4:
    ctx->pc = 0x8006FEA4u;
    ctx->downcount -= 3;
    // 8006FEA4: stb     r0, -24975(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24975);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FEA8:
    ctx->pc = 0x8006FEA8u;
    // 8006FEA8: stb     r0, -24976(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24976);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FEAC:
    ctx->pc = 0x8006FEACu;
    // 8006FEAC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_8006FEB0:
    ctx->pc = 0x8006FEB0u;
    ctx->downcount -= 11;
    // 8006FEB0: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8006FEB4:
    ctx->pc = 0x8006FEB4u;
    // 8006FEB4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8006FEB8:
    ctx->pc = 0x8006FEB8u;
    // 8006FEB8: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006FEBC:
    ctx->pc = 0x8006FEBCu;
    // 8006FEBC: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8006FEC0:
    ctx->pc = 0x8006FEC0u;
    // 8006FEC0: lis     r3, -32711
    ctx->gpr[3] = ((u32)(s32)(-32711) << 16);

label_8006FEC4:
    ctx->pc = 0x8006FEC4u;
    // 8006FEC4: addi    r31, r3, 14112
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(14112);

label_8006FEC8:
    ctx->pc = 0x8006FEC8u;
    // 8006FEC8: addi    r3, r31, 4128
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(4128);

label_8006FECC:
    ctx->pc = 0x8006FECCu;
    // 8006FECC: addi    r4, r31, 32
    ctx->gpr[4] = ctx->gpr[31] + (u32)(s32)(32);

label_8006FED0:
    ctx->pc = 0x8006FED0u;
    // 8006FED0: li      r0, 16
    ctx->gpr[0] = (u32)(s32)(16);

label_8006FED4:
    ctx->pc = 0x8006FED4u;
    // 8006FED4: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8006FED8:
    loop_8006FED8(ctx);
    if (ctx->pc == 0x8006FF68u) goto label_8006FF68;
    return;
label_8006FEDC:
    ctx->pc = 0x8006FEDCu;
    // 8006FEDC: stb     r0, 51(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(51);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FEE0:
    ctx->pc = 0x8006FEE0u;
    // 8006FEE0: stb     r0, 14(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(14);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FEE4:
    ctx->pc = 0x8006FEE4u;
    // 8006FEE4: stb     r0, 107(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(107);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FEE8:
    ctx->pc = 0x8006FEE8u;
    // 8006FEE8: stb     r0, 30(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(30);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FEEC:
    ctx->pc = 0x8006FEECu;
    // 8006FEEC: stb     r0, 163(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(163);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FEF0:
    ctx->pc = 0x8006FEF0u;
    // 8006FEF0: stb     r0, 46(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(46);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FEF4:
    ctx->pc = 0x8006FEF4u;
    // 8006FEF4: stb     r0, 219(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(219);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FEF8:
    ctx->pc = 0x8006FEF8u;
    // 8006FEF8: stb     r0, 62(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(62);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FEFC:
    ctx->pc = 0x8006FEFCu;
    // 8006FEFC: stb     r0, 275(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(275);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FF00:
    ctx->pc = 0x8006FF00u;
    // 8006FF00: stb     r0, 78(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(78);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FF04:
    ctx->pc = 0x8006FF04u;
    // 8006FF04: stb     r0, 331(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(331);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FF08:
    ctx->pc = 0x8006FF08u;
    // 8006FF08: stb     r0, 94(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(94);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FF0C:
    ctx->pc = 0x8006FF0Cu;
    // 8006FF0C: stb     r0, 387(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(387);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FF10:
    ctx->pc = 0x8006FF10u;
    // 8006FF10: stb     r0, 110(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(110);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FF14:
    ctx->pc = 0x8006FF14u;
    // 8006FF14: stb     r0, 443(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(443);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FF18:
    ctx->pc = 0x8006FF18u;
    // 8006FF18: stb     r0, 126(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(126);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FF1C:
    ctx->pc = 0x8006FF1Cu;
    // 8006FF1C: stb     r0, 499(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(499);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FF20:
    ctx->pc = 0x8006FF20u;
    // 8006FF20: stb     r0, 142(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(142);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FF24:
    ctx->pc = 0x8006FF24u;
    // 8006FF24: stb     r0, 555(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(555);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FF28:
    ctx->pc = 0x8006FF28u;
    // 8006FF28: stb     r0, 158(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(158);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FF2C:
    ctx->pc = 0x8006FF2Cu;
    // 8006FF2C: stb     r0, 611(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(611);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FF30:
    ctx->pc = 0x8006FF30u;
    // 8006FF30: stb     r0, 174(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(174);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FF34:
    ctx->pc = 0x8006FF34u;
    // 8006FF34: stb     r0, 667(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(667);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FF38:
    ctx->pc = 0x8006FF38u;
    // 8006FF38: stb     r0, 190(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(190);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FF3C:
    ctx->pc = 0x8006FF3Cu;
    // 8006FF3C: stb     r0, 723(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(723);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FF40:
    ctx->pc = 0x8006FF40u;
    // 8006FF40: stb     r0, 206(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(206);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FF44:
    ctx->pc = 0x8006FF44u;
    // 8006FF44: stb     r0, 779(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(779);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FF48:
    ctx->pc = 0x8006FF48u;
    // 8006FF48: stb     r0, 222(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(222);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FF4C:
    ctx->pc = 0x8006FF4Cu;
    // 8006FF4C: stb     r0, 835(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(835);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FF50:
    ctx->pc = 0x8006FF50u;
    // 8006FF50: stb     r0, 238(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(238);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FF54:
    ctx->pc = 0x8006FF54u;
    // 8006FF54: stb     r0, 891(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(891);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FF58:
    ctx->pc = 0x8006FF58u;
    // 8006FF58: stb     r0, 254(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(254);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FF5C:
    // 8006FF5C: addi    r3, r3, 896
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(896);

label_8006FF60:
    // 8006FF60: addi    r4, r4, 256
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(256);

label_8006FF64:
    // 8006FF64: bc    16, 0, 0x8006FED8
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8006FED8u;
                return;
            }
            goto label_8006FED8;
        }
    }

label_8006FF68:
    ctx->pc = 0x8006FF68u;
    ctx->downcount -= 2;
    // 8006FF68: li      r3, 25
    ctx->gpr[3] = (u32)(s32)(25);

label_8006FF6C:
    ctx->pc = 0x8006FF6Cu;
    // 8006FF6C: bl      0x80054F38
    {
            ctx->lr = 0x8006FF70u;
            ctx->pc = 0x80054F38u;
            return;
    }

label_8006FF70:
    ctx->pc = 0x8006FF70u;
    ctx->downcount -= 3;
    // 8006FF70: stw     r3, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8006FF74:
    ctx->pc = 0x8006FF74u;
    // 8006FF74: li      r3, 24
    ctx->gpr[3] = (u32)(s32)(24);

label_8006FF78:
    ctx->pc = 0x8006FF78u;
    // 8006FF78: bl      0x80054F38
    {
            ctx->lr = 0x8006FF7Cu;
            ctx->pc = 0x80054F38u;
            return;
    }

label_8006FF7C:
    ctx->pc = 0x8006FF7Cu;
    ctx->downcount -= 3;
    // 8006FF7C: stw     r3, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8006FF80:
    ctx->pc = 0x8006FF80u;
    // 8006FF80: li      r3, 26
    ctx->gpr[3] = (u32)(s32)(26);

label_8006FF84:
    ctx->pc = 0x8006FF84u;
    // 8006FF84: bl      0x80054F38
    {
            ctx->lr = 0x8006FF88u;
            ctx->pc = 0x80054F38u;
            return;
    }

label_8006FF88:
    ctx->pc = 0x8006FF88u;
    ctx->downcount -= 3;
    // 8006FF88: stw     r3, 24(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8006FF8C:
    ctx->pc = 0x8006FF8Cu;
    // 8006FF8C: li      r3, 1606
    ctx->gpr[3] = (u32)(s32)(1606);

label_8006FF90:
    ctx->pc = 0x8006FF90u;
    // 8006FF90: bl      0x80054F38
    {
            ctx->lr = 0x8006FF94u;
            ctx->pc = 0x80054F38u;
            return;
    }

label_8006FF94:
    ctx->pc = 0x8006FF94u;
    ctx->downcount -= 19;
    // 8006FF94: stw     r3, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8006FF98:
    ctx->pc = 0x8006FF98u;
    // 8006FF98: lfs     f0, -30364(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006FF98u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30364);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8006FF9C:
    ctx->pc = 0x8006FF9Cu;
    // 8006FF9C: stfs     f0, 0(r31)
    if (!ppc_fp_available_inline(ctx, 0x8006FF9Cu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8006FFA0:
    ctx->pc = 0x8006FFA0u;
    // 8006FFA0: lfs     f0, -30360(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006FFA0u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30360);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8006FFA4:
    ctx->pc = 0x8006FFA4u;
    // 8006FFA4: stfs     f0, 4(r31)
    if (!ppc_fp_available_inline(ctx, 0x8006FFA4u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8006FFA8:
    ctx->pc = 0x8006FFA8u;
    // 8006FFA8: stfs     f0, 8(r31)
    if (!ppc_fp_available_inline(ctx, 0x8006FFA8u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8006FFAC:
    ctx->pc = 0x8006FFACu;
    // 8006FFAC: lfs     f0, -30356(r2)
    if (!ppc_fp_available_inline(ctx, 0x8006FFACu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30356);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8006FFB0:
    ctx->pc = 0x8006FFB0u;
    // 8006FFB0: stfs     f0, 12(r31)
    if (!ppc_fp_available_inline(ctx, 0x8006FFB0u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8006FFB4:
    ctx->pc = 0x8006FFB4u;
    // 8006FFB4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8006FFB8:
    ctx->pc = 0x8006FFB8u;
    // 8006FFB8: stb     r0, -24974(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24974);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FFBC:
    ctx->pc = 0x8006FFBCu;
    // 8006FFBC: stb     r0, -24975(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24975);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FFC0:
    ctx->pc = 0x8006FFC0u;
    // 8006FFC0: stb     r0, -24976(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24976);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8006FFC4:
    ctx->pc = 0x8006FFC4u;
    // 8006FFC4: stw     r0, -24980(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24980);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006FFC8:
    ctx->pc = 0x8006FFC8u;
    // 8006FFC8: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8006FFCC:
    ctx->pc = 0x8006FFCCu;
    // 8006FFCC: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8006FFD0:
    ctx->pc = 0x8006FFD0u;
    // 8006FFD0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8006FFD4:
    ctx->pc = 0x8006FFD4u;
    // 8006FFD4: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8006FFD8:
    ctx->pc = 0x8006FFD8u;
    // 8006FFD8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_8006FFDC:
    ctx->pc = 0x8006FFDCu;
    ctx->downcount -= 3;
    // 8006FFDC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8006FFE0:
    ctx->pc = 0x8006FFE0u;
    // 8006FFE0: cmpwi   r3, 0
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

label_8006FFE4:
    ctx->pc = 0x8006FFE4u;
    // 8006FFE4: bc    12, 0, 0x80070004
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80070004;
        }
    }

label_8006FFE8:
    ctx->pc = 0x8006FFE8u;
    ctx->downcount -= 2;
    // 8006FFE8: cmpwi   r3, 640
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(640);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8006FFEC:
    ctx->pc = 0x8006FFECu;
    // 8006FFEC: bc    4, 0, 0x80070004
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070004;
        }
    }

label_8006FFF0:
    ctx->pc = 0x8006FFF0u;
    ctx->downcount -= 2;
    // 8006FFF0: cmpwi   r4, 0
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

label_8006FFF4:
    ctx->pc = 0x8006FFF4u;
    // 8006FFF4: bc    12, 0, 0x80070004
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80070004;
        }
    }

label_8006FFF8:
    ctx->pc = 0x8006FFF8u;
    ctx->downcount -= 2;
    // 8006FFF8: cmpwi   r4, 480
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(480);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8006FFFC:
    ctx->pc = 0x8006FFFCu;
    // 8006FFFC: bc    4, 0, 0x80070004
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070004;
        }
    }

label_80070000:
    ctx->pc = 0x80070000u;
    ctx->downcount -= 1;
    // 80070000: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80070004:
    ctx->pc = 0x80070004u;
    ctx->downcount -= 2;
    // 80070004: cmpwi   r0, 0
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

label_80070008:
    ctx->pc = 0x80070008u;
    // 80070008: bc    12, 2, 0x800700B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800700B0;
        }
    }

label_8007000C:
    ctx->pc = 0x8007000Cu;
    ctx->downcount -= 2;
    // 8007000C: cmpwi   r3, 16
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(16);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80070010:
    ctx->pc = 0x80070010u;
    // 80070010: bc    4, 0, 0x80070018
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070018;
        }
    }

label_80070014:
    ctx->pc = 0x80070014u;
    ctx->downcount -= 1;
    // 80070014: li      r3, 16
    ctx->gpr[3] = (u32)(s32)(16);

label_80070018:
    ctx->pc = 0x80070018u;
    ctx->downcount -= 2;
    // 80070018: cmpwi   r4, 6
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(6);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8007001C:
    ctx->pc = 0x8007001Cu;
    // 8007001C: bc    4, 0, 0x80070024
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070024;
        }
    }

label_80070020:
    ctx->pc = 0x80070020u;
    ctx->downcount -= 1;
    // 80070020: li      r4, 6
    ctx->gpr[4] = (u32)(s32)(6);

label_80070024:
    ctx->pc = 0x80070024u;
    ctx->downcount -= 3;
    // 80070024: lhz     r6, -24968(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24968);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_80070028:
    ctx->pc = 0x80070028u;
    // 80070028: cmplwi  r6, 0x0014
    {
        u32 val_a = (u32)(ctx->gpr[6]);
        u32 val_b = (u32)(0x0014u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8007002C:
    ctx->pc = 0x8007002Cu;
    // 8007002C: bc    4, 0, 0x8007005C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8007005C;
        }
    }

label_80070030:
    ctx->pc = 0x80070030u;
    ctx->downcount -= 13;
    // 80070030: rlwinm r0, r3, 0, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x0000FFFFu;
    }

label_80070034:
    ctx->pc = 0x80070034u;
    // 80070034: mulli   r7, r6, 12
    ctx->gpr[7] = (u32)((s64)(s32)ctx->gpr[6] * (s64)(s32)12);

label_80070038:
    ctx->pc = 0x80070038u;
    // 80070038: lis     r3, -32710
    ctx->gpr[3] = ((u32)(s32)(-32710) << 16);

label_8007003C:
    ctx->pc = 0x8007003Cu;
    // 8007003C: addi    r3, r3, -32720
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-32720);

label_80070040:
    ctx->pc = 0x80070040u;
    // 80070040: sthx    r0, r3, r7
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[7];
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80070044:
    ctx->pc = 0x80070044u;
    // 80070044: rlwinm r0, r4, 0, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x0000FFFFu;
    }

label_80070048:
    ctx->pc = 0x80070048u;
    // 80070048: add   r3, r3, r7
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8007004C:
    ctx->pc = 0x8007004Cu;
    // 8007004C: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80070050:
    ctx->pc = 0x80070050u;
    // 80070050: stw     r5, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80070054:
    ctx->pc = 0x80070054u;
    // 80070054: addi    r0, r6, 1
    ctx->gpr[0] = ctx->gpr[6] + (u32)(s32)(1);

label_80070058:
    ctx->pc = 0x80070058u;
    // 80070058: sth     r0, -24968(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24968);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8007005C:
    ctx->pc = 0x8007005Cu;
    ctx->downcount -= 8;
    // 8007005C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80070060:
    ctx->pc = 0x80070060u;
    // 80070060: lis     r3, -32711
    ctx->gpr[3] = ((u32)(s32)(-32711) << 16);

label_80070064:
    ctx->pc = 0x80070064u;
    // 80070064: addi    r3, r3, 32576
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(32576);

label_80070068:
    ctx->pc = 0x80070068u;
    // 80070068: lhz     r0, -24966(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24966);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8007006C:
    ctx->pc = 0x8007006Cu;
    // 8007006C: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_80070070:
    ctx->pc = 0x80070070u;
    // 80070070: cmplwi  r0, 0x0000
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

label_80070074:
    ctx->pc = 0x80070074u;
    // 80070074: bc    4, 1, 0x800700A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800700A8;
        }
    }

label_80070078:
    ctx->pc = 0x80070078u;
    ctx->downcount -= 3;
    // 80070078: lwz     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8007007C:
    // 8007007C: cmpw    r5, r0
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

label_80070080:
    // 80070080: bc    4, 2, 0x8007009C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8007009C;
        }
    }

label_80070084:
    ctx->downcount -= 8;
    // 80070084: lis     r3, -32711
    ctx->gpr[3] = ((u32)(s32)(-32711) << 16);

label_80070088:
    // 80070088: addi    r3, r3, 32576
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(32576);

label_8007008C:
    // 8007008C: mulli   r0, r4, 12
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[4] * (s64)(s32)12);

label_80070090:
    // 80070090: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80070094:
    ctx->pc = 0x80070094u;
    // 80070094: lwz     r3, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80070098:
    ctx->pc = 0x80070098u;
    // 80070098: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_8007009C:
    ctx->downcount -= 3;
    // 8007009C: addi    r3, r3, 12
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(12);

label_800700A0:
    // 800700A0: addi    r4, r4, 1
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(1);

label_800700A4:
    // 800700A4: bc    16, 0, 0x80070078
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80070078u;
                return;
            }
            goto label_80070078;
        }
    }

label_800700A8:
    ctx->pc = 0x800700A8u;
    ctx->downcount -= 2;
    // 800700A8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800700AC:
    ctx->pc = 0x800700ACu;
    // 800700AC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_800700B0:
    ctx->pc = 0x800700B0u;
    ctx->downcount -= 2;
    // 800700B0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800700B4:
    ctx->pc = 0x800700B4u;
    // 800700B4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_800700B8:
    ctx->pc = 0x800700B8u;
    ctx->downcount -= 3;
    // 800700B8: lwz     r3, -24964(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24964);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800700BC:
    ctx->pc = 0x800700BCu;
    // 800700BC: cmplwi  r3, 0x0000
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

label_800700C0:
    ctx->pc = 0x800700C0u;
    // 800700C0: bc    12, 2, 0x800700D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800700D0;
        }
    }

label_800700C4:
    ctx->pc = 0x800700C4u;
    ctx->downcount -= 3;
    // 800700C4: rlwinm r0, r3, 16, 0, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 16u) & 0xFFFF0000u;
    }

label_800700C8:
    ctx->pc = 0x800700C8u;
    // 800700C8: or   r3, r3, r0
    {
        ctx->gpr[3] = ctx->gpr[3] | ctx->gpr[0];
    }

label_800700CC:
    ctx->pc = 0x800700CCu;
    // 800700CC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_800700D0:
    ctx->pc = 0x800700D0u;
    ctx->downcount -= 3;
    // 800700D0: lis     r3, 480
    ctx->gpr[3] = ((u32)(s32)(480) << 16);

label_800700D4:
    ctx->pc = 0x800700D4u;
    // 800700D4: addi    r3, r3, 640
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(640);

label_800700D8:
    ctx->pc = 0x800700D8u;
    // 800700D8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_800700DC:
    ctx->pc = 0x800700DCu;
    ctx->downcount -= 2;
    // 800700DC: stw     r3, -24964(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24964);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800700E0:
    ctx->pc = 0x800700E0u;
    // 800700E0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_800700E4:
    ctx->pc = 0x800700E4u;
    ctx->downcount -= 3;
    // 800700E4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800700E8:
    ctx->pc = 0x800700E8u;
    // 800700E8: stw     r0, -24964(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24964);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800700EC:
    ctx->pc = 0x800700ECu;
    // 800700EC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_800700F0:
    ctx->pc = 0x800700F0u;
    ctx->downcount -= 27;
    // 800700F0: stwu     r1, -144(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-144);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800700F4:
    ctx->pc = 0x800700F4u;
    // 800700F4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800700F8:
    ctx->pc = 0x800700F8u;
    // 800700F8: stw     r0, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800700FC:
    ctx->pc = 0x800700FCu;
    // 800700FC: stfd     f31, 128(r1)
    if (!ppc_fp_available_inline(ctx, 0x800700FCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(128);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_80070100:
    ctx->pc = 0x80070100u;
    // 80070100: psq_st   f31, 136(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x80070100u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        ppc_psq_store_inline(ctx, 31u, ea, false, 0u, false, 0x80070100u);
        if (ctx->exception) return;
    }

label_80070104:
    ctx->pc = 0x80070104u;
    // 80070104: stfd     f30, 112(r1)
    if (!ppc_fp_available_inline(ctx, 0x80070104u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(112);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[30]));
    }

label_80070108:
    ctx->pc = 0x80070108u;
    // 80070108: psq_st   f30, 120(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x80070108u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(120);
        ppc_psq_store_inline(ctx, 30u, ea, false, 0u, false, 0x80070108u);
        if (ctx->exception) return;
    }

label_8007010C:
    ctx->pc = 0x8007010Cu;
    // 8007010C: stfd     f29, 96(r1)
    if (!ppc_fp_available_inline(ctx, 0x8007010Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[29]));
    }

label_80070110:
    ctx->pc = 0x80070110u;
    // 80070110: psq_st   f29, 104(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x80070110u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        ppc_psq_store_inline(ctx, 29u, ea, false, 0u, false, 0x80070110u);
        if (ctx->exception) return;
    }

label_80070114:
    ctx->pc = 0x80070114u;
    // 80070114: stfd     f28, 80(r1)
    if (!ppc_fp_available_inline(ctx, 0x80070114u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[28]));
    }

label_80070118:
    ctx->pc = 0x80070118u;
    // 80070118: psq_st   f28, 88(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x80070118u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        ppc_psq_store_inline(ctx, 28u, ea, false, 0u, false, 0x80070118u);
        if (ctx->exception) return;
    }

label_8007011C:
    ctx->pc = 0x8007011Cu;
    // 8007011C: stfd     f27, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x8007011Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[27]));
    }

label_80070120:
    ctx->pc = 0x80070120u;
    // 80070120: psq_st   f27, 72(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x80070120u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        ppc_psq_store_inline(ctx, 27u, ea, false, 0u, false, 0x80070120u);
        if (ctx->exception) return;
    }

label_80070124:
    ctx->pc = 0x80070124u;
    // 80070124: stfd     f26, 48(r1)
    if (!ppc_fp_available_inline(ctx, 0x80070124u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[26]));
    }

label_80070128:
    ctx->pc = 0x80070128u;
    // 80070128: psq_st   f26, 56(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x80070128u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        ppc_psq_store_inline(ctx, 26u, ea, false, 0u, false, 0x80070128u);
        if (ctx->exception) return;
    }

label_8007012C:
    ctx->pc = 0x8007012Cu;
    // 8007012C: stfd     f25, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x8007012Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[25]));
    }

label_80070130:
    ctx->pc = 0x80070130u;
    // 80070130: psq_st   f25, 40(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x80070130u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ppc_psq_store_inline(ctx, 25u, ea, false, 0u, false, 0x80070130u);
        if (ctx->exception) return;
    }

label_80070134:
    ctx->pc = 0x80070134u;
    // 80070134: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80070138:
    ctx->pc = 0x80070138u;
    // 80070138: stw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8007013C:
    ctx->pc = 0x8007013Cu;
    // 8007013C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80070140:
    ctx->pc = 0x80070140u;
    // 80070140: or   r31, r4, r4
    {
        ctx->gpr[31] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80070144:
    ctx->pc = 0x80070144u;
    // 80070144: fmr    f27, f1
    if (!ppc_fp_available_inline(ctx, 0x80070144u)) return;
    ctx->fpr[27] = ctx->fpr[1];

label_80070148:
    ctx->pc = 0x80070148u;
    // 80070148: fmr    f28, f2
    if (!ppc_fp_available_inline(ctx, 0x80070148u)) return;
    ctx->fpr[28] = ctx->fpr[2];

label_8007014C:
    ctx->pc = 0x8007014Cu;
    // 8007014C: fmr    f29, f3
    if (!ppc_fp_available_inline(ctx, 0x8007014Cu)) return;
    ctx->fpr[29] = ctx->fpr[3];

label_80070150:
    ctx->pc = 0x80070150u;
    // 80070150: fmr    f30, f4
    if (!ppc_fp_available_inline(ctx, 0x80070150u)) return;
    ctx->fpr[30] = ctx->fpr[4];

label_80070154:
    ctx->pc = 0x80070154u;
    // 80070154: fmr    f31, f5
    if (!ppc_fp_available_inline(ctx, 0x80070154u)) return;
    ctx->fpr[31] = ctx->fpr[5];

label_80070158:
    ctx->pc = 0x80070158u;
    // 80070158: bl      0x80070418
    {
            ctx->lr = 0x8007015Cu;
            goto label_80070418;
    }

label_8007015C:
    ctx->pc = 0x8007015Cu;
    ctx->downcount -= 34;
    // 8007015C: lfs     f2, -30352(r2)
    if (!ppc_fp_available_inline(ctx, 0x8007015Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30352);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_80070160:
    ctx->pc = 0x80070160u;
    // 80070160: lfs     f0, -30348(r2)
    if (!ppc_fp_available_inline(ctx, 0x80070160u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30348);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80070164:
    ctx->pc = 0x80070164u;
    // 80070164: fmuls   f0, f0, f27
    if (!ppc_fp_available_inline(ctx, 0x80070164u)) return;
    ppc_fmuls(ctx, 0, 0, 27);

label_80070168:
    ctx->pc = 0x80070168u;
    // 80070168: fctiwz    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x80070168u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_8007016C:
    ctx->pc = 0x8007016Cu;
    // 8007016C: stfd     f0, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x8007016Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_80070170:
    ctx->pc = 0x80070170u;
    // 80070170: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80070174:
    ctx->pc = 0x80070174u;
    // 80070174: lfd     f1, -30320(r2)
    if (!ppc_fp_available_inline(ctx, 0x80070174u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30320);
        ctx->fpr[1] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80070178:
    ctx->pc = 0x80070178u;
    // 80070178: xoris   r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] ^ (0x8000u << 16);

label_8007017C:
    ctx->pc = 0x8007017Cu;
    // 8007017C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80070180:
    ctx->pc = 0x80070180u;
    // 80070180: lis     r0, 17200
    ctx->gpr[0] = ((u32)(s32)(17200) << 16);

label_80070184:
    ctx->pc = 0x80070184u;
    // 80070184: stw     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80070188:
    ctx->pc = 0x80070188u;
    // 80070188: lfd     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x80070188u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8007018C:
    ctx->pc = 0x8007018Cu;
    // 8007018C: fsubs   f0, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8007018Cu)) return;
    ppc_fsubs(ctx, 0, 0, 1);

label_80070190:
    ctx->pc = 0x80070190u;
    // 80070190: fmuls   f1, f2, f0
    if (!ppc_fp_available_inline(ctx, 0x80070190u)) return;
    ppc_fmuls(ctx, 1, 2, 0);

label_80070194:
    ctx->pc = 0x80070194u;
    // 80070194: lfs     f0, -30344(r2)
    if (!ppc_fp_available_inline(ctx, 0x80070194u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30344);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80070198:
    ctx->pc = 0x80070198u;
    // 80070198: fdivs   f25, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x80070198u)) return;
    ppc_fdivs(ctx, 25, 1, 0);

label_8007019C:
    ctx->pc = 0x8007019Cu;
    // 8007019C: fmr    f1, f25
    if (!ppc_fp_available_inline(ctx, 0x8007019Cu)) return;
    ctx->fpr[1] = ctx->fpr[25];

label_800701A0:
    ctx->pc = 0x800701A0u;
    // 800701A0: bl      0x802947F0
    {
            ctx->lr = 0x800701A4u;
            ctx->pc = 0x802947F0u;
            return;
    }

label_800701A4:
    ctx->pc = 0x800701A4u;
    ctx->downcount -= 3;
    // 800701A4: fmr    f26, f1
    if (!ppc_fp_available_inline(ctx, 0x800701A4u)) return;
    ctx->fpr[26] = ctx->fpr[1];

label_800701A8:
    ctx->pc = 0x800701A8u;
    // 800701A8: fmr    f1, f25
    if (!ppc_fp_available_inline(ctx, 0x800701A8u)) return;
    ctx->fpr[1] = ctx->fpr[25];

label_800701AC:
    ctx->pc = 0x800701ACu;
    // 800701AC: bl      0x80294B74
    {
            ctx->lr = 0x800701B0u;
            ctx->pc = 0x80294B74u;
            return;
    }

label_800701B0:
    ctx->pc = 0x800701B0u;
    ctx->downcount -= 129;
    // 800701B0: fdivs   f1, f1, f26
    if (!ppc_fp_available_inline(ctx, 0x800701B0u)) return;
    ppc_fdivs(ctx, 1, 1, 26);

label_800701B4:
    ctx->pc = 0x800701B4u;
    // 800701B4: fdivs   f0, f1, f28
    if (!ppc_fp_available_inline(ctx, 0x800701B4u)) return;
    ppc_fdivs(ctx, 0, 1, 28);

label_800701B8:
    ctx->pc = 0x800701B8u;
    // 800701B8: stfs     f0, 0(r30)
    if (!ppc_fp_available_inline(ctx, 0x800701B8u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800701BC:
    ctx->pc = 0x800701BCu;
    // 800701BC: stfs     f1, 20(r30)
    if (!ppc_fp_available_inline(ctx, 0x800701BCu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_800701C0:
    ctx->pc = 0x800701C0u;
    // 800701C0: fneg    f2, f29
    if (!ppc_fp_available_inline(ctx, 0x800701C0u)) return;
    ctx->fpr[2] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[29]) ^ 0x8000000000000000ull);

label_800701C4:
    ctx->pc = 0x800701C4u;
    // 800701C4: fsubs   f1, f30, f29
    if (!ppc_fp_available_inline(ctx, 0x800701C4u)) return;
    ppc_fsubs(ctx, 1, 30, 29);

label_800701C8:
    ctx->pc = 0x800701C8u;
    // 800701C8: fdivs   f0, f2, f1
    if (!ppc_fp_available_inline(ctx, 0x800701C8u)) return;
    ppc_fdivs(ctx, 0, 2, 1);

label_800701CC:
    ctx->pc = 0x800701CCu;
    // 800701CC: stfs     f0, 40(r30)
    if (!ppc_fp_available_inline(ctx, 0x800701CCu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800701D0:
    ctx->pc = 0x800701D0u;
    // 800701D0: lfs     f0, -30340(r2)
    if (!ppc_fp_available_inline(ctx, 0x800701D0u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30340);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800701D4:
    ctx->pc = 0x800701D4u;
    // 800701D4: stfs     f0, 44(r30)
    if (!ppc_fp_available_inline(ctx, 0x800701D4u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800701D8:
    ctx->pc = 0x800701D8u;
    // 800701D8: fmuls   f0, f2, f30
    if (!ppc_fp_available_inline(ctx, 0x800701D8u)) return;
    ppc_fmuls(ctx, 0, 2, 30);

label_800701DC:
    ctx->pc = 0x800701DCu;
    // 800701DC: fdivs   f0, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x800701DCu)) return;
    ppc_fdivs(ctx, 0, 0, 1);

label_800701E0:
    ctx->pc = 0x800701E0u;
    // 800701E0: stfs     f0, 56(r30)
    if (!ppc_fp_available_inline(ctx, 0x800701E0u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(56);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800701E4:
    ctx->pc = 0x800701E4u;
    // 800701E4: lfs     f0, -30336(r2)
    if (!ppc_fp_available_inline(ctx, 0x800701E4u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30336);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800701E8:
    ctx->pc = 0x800701E8u;
    // 800701E8: stfs     f0, 60(r30)
    if (!ppc_fp_available_inline(ctx, 0x800701E8u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(60);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800701EC:
    ctx->pc = 0x800701ECu;
    // 800701EC: lfs     f0, 0(r30)
    if (!ppc_fp_available_inline(ctx, 0x800701ECu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800701F0:
    ctx->pc = 0x800701F0u;
    // 800701F0: fmuls   f0, f0, f31
    if (!ppc_fp_available_inline(ctx, 0x800701F0u)) return;
    ppc_fmuls(ctx, 0, 0, 31);

label_800701F4:
    ctx->pc = 0x800701F4u;
    // 800701F4: stfs     f0, 0(r30)
    if (!ppc_fp_available_inline(ctx, 0x800701F4u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800701F8:
    ctx->pc = 0x800701F8u;
    // 800701F8: lfs     f0, 4(r30)
    if (!ppc_fp_available_inline(ctx, 0x800701F8u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800701FC:
    ctx->pc = 0x800701FCu;
    // 800701FC: fmuls   f0, f0, f31
    if (!ppc_fp_available_inline(ctx, 0x800701FCu)) return;
    ppc_fmuls(ctx, 0, 0, 31);

label_80070200:
    ctx->pc = 0x80070200u;
    // 80070200: stfs     f0, 4(r30)
    if (!ppc_fp_available_inline(ctx, 0x80070200u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80070204:
    ctx->pc = 0x80070204u;
    // 80070204: lfs     f0, 8(r30)
    if (!ppc_fp_available_inline(ctx, 0x80070204u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80070208:
    ctx->pc = 0x80070208u;
    // 80070208: fmuls   f0, f0, f31
    if (!ppc_fp_available_inline(ctx, 0x80070208u)) return;
    ppc_fmuls(ctx, 0, 0, 31);

label_8007020C:
    ctx->pc = 0x8007020Cu;
    // 8007020C: stfs     f0, 8(r30)
    if (!ppc_fp_available_inline(ctx, 0x8007020Cu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80070210:
    ctx->pc = 0x80070210u;
    // 80070210: lfs     f0, 12(r30)
    if (!ppc_fp_available_inline(ctx, 0x80070210u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80070214:
    ctx->pc = 0x80070214u;
    // 80070214: fmuls   f0, f0, f31
    if (!ppc_fp_available_inline(ctx, 0x80070214u)) return;
    ppc_fmuls(ctx, 0, 0, 31);

label_80070218:
    ctx->pc = 0x80070218u;
    // 80070218: stfs     f0, 12(r30)
    if (!ppc_fp_available_inline(ctx, 0x80070218u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8007021C:
    ctx->pc = 0x8007021Cu;
    // 8007021C: lfs     f0, 16(r30)
    if (!ppc_fp_available_inline(ctx, 0x8007021Cu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80070220:
    ctx->pc = 0x80070220u;
    // 80070220: fmuls   f0, f0, f31
    if (!ppc_fp_available_inline(ctx, 0x80070220u)) return;
    ppc_fmuls(ctx, 0, 0, 31);

label_80070224:
    ctx->pc = 0x80070224u;
    // 80070224: stfs     f0, 16(r30)
    if (!ppc_fp_available_inline(ctx, 0x80070224u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80070228:
    ctx->pc = 0x80070228u;
    // 80070228: lfs     f0, 20(r30)
    if (!ppc_fp_available_inline(ctx, 0x80070228u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8007022C:
    ctx->pc = 0x8007022Cu;
    // 8007022C: fmuls   f0, f0, f31
    if (!ppc_fp_available_inline(ctx, 0x8007022Cu)) return;
    ppc_fmuls(ctx, 0, 0, 31);

label_80070230:
    ctx->pc = 0x80070230u;
    // 80070230: stfs     f0, 20(r30)
    if (!ppc_fp_available_inline(ctx, 0x80070230u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80070234:
    ctx->pc = 0x80070234u;
    // 80070234: lfs     f0, 24(r30)
    if (!ppc_fp_available_inline(ctx, 0x80070234u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(24);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80070238:
    ctx->pc = 0x80070238u;
    // 80070238: fmuls   f0, f0, f31
    if (!ppc_fp_available_inline(ctx, 0x80070238u)) return;
    ppc_fmuls(ctx, 0, 0, 31);

label_8007023C:
    ctx->pc = 0x8007023Cu;
    // 8007023C: stfs     f0, 24(r30)
    if (!ppc_fp_available_inline(ctx, 0x8007023Cu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(24);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80070240:
    ctx->pc = 0x80070240u;
    // 80070240: lfs     f0, 28(r30)
    if (!ppc_fp_available_inline(ctx, 0x80070240u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80070244:
    ctx->pc = 0x80070244u;
    // 80070244: fmuls   f0, f0, f31
    if (!ppc_fp_available_inline(ctx, 0x80070244u)) return;
    ppc_fmuls(ctx, 0, 0, 31);

label_80070248:
    ctx->pc = 0x80070248u;
    // 80070248: stfs     f0, 28(r30)
    if (!ppc_fp_available_inline(ctx, 0x80070248u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8007024C:
    ctx->pc = 0x8007024Cu;
    // 8007024C: lfs     f0, 32(r30)
    if (!ppc_fp_available_inline(ctx, 0x8007024Cu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80070250:
    ctx->pc = 0x80070250u;
    // 80070250: fmuls   f0, f0, f31
    if (!ppc_fp_available_inline(ctx, 0x80070250u)) return;
    ppc_fmuls(ctx, 0, 0, 31);

label_80070254:
    ctx->pc = 0x80070254u;
    // 80070254: stfs     f0, 32(r30)
    if (!ppc_fp_available_inline(ctx, 0x80070254u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80070258:
    ctx->pc = 0x80070258u;
    // 80070258: lfs     f0, 36(r30)
    if (!ppc_fp_available_inline(ctx, 0x80070258u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(36);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8007025C:
    ctx->pc = 0x8007025Cu;
    // 8007025C: fmuls   f0, f0, f31
    if (!ppc_fp_available_inline(ctx, 0x8007025Cu)) return;
    ppc_fmuls(ctx, 0, 0, 31);

label_80070260:
    ctx->pc = 0x80070260u;
    // 80070260: stfs     f0, 36(r30)
    if (!ppc_fp_available_inline(ctx, 0x80070260u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(36);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80070264:
    ctx->pc = 0x80070264u;
    // 80070264: lfs     f0, 40(r30)
    if (!ppc_fp_available_inline(ctx, 0x80070264u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(40);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80070268:
    ctx->pc = 0x80070268u;
    // 80070268: fmuls   f0, f0, f31
    if (!ppc_fp_available_inline(ctx, 0x80070268u)) return;
    ppc_fmuls(ctx, 0, 0, 31);

label_8007026C:
    ctx->pc = 0x8007026Cu;
    // 8007026C: stfs     f0, 40(r30)
    if (!ppc_fp_available_inline(ctx, 0x8007026Cu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80070270:
    ctx->pc = 0x80070270u;
    // 80070270: lfs     f0, 44(r30)
    if (!ppc_fp_available_inline(ctx, 0x80070270u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(44);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80070274:
    ctx->pc = 0x80070274u;
    // 80070274: fmuls   f0, f0, f31
    if (!ppc_fp_available_inline(ctx, 0x80070274u)) return;
    ppc_fmuls(ctx, 0, 0, 31);

label_80070278:
    ctx->pc = 0x80070278u;
    // 80070278: stfs     f0, 44(r30)
    if (!ppc_fp_available_inline(ctx, 0x80070278u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8007027C:
    ctx->pc = 0x8007027Cu;
    // 8007027C: lfs     f0, 48(r30)
    if (!ppc_fp_available_inline(ctx, 0x8007027Cu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(48);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80070280:
    ctx->pc = 0x80070280u;
    // 80070280: fmuls   f0, f0, f31
    if (!ppc_fp_available_inline(ctx, 0x80070280u)) return;
    ppc_fmuls(ctx, 0, 0, 31);

label_80070284:
    ctx->pc = 0x80070284u;
    // 80070284: stfs     f0, 48(r30)
    if (!ppc_fp_available_inline(ctx, 0x80070284u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(48);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80070288:
    ctx->pc = 0x80070288u;
    // 80070288: lfs     f0, 52(r30)
    if (!ppc_fp_available_inline(ctx, 0x80070288u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(52);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8007028C:
    ctx->pc = 0x8007028Cu;
    // 8007028C: fmuls   f0, f0, f31
    if (!ppc_fp_available_inline(ctx, 0x8007028Cu)) return;
    ppc_fmuls(ctx, 0, 0, 31);

label_80070290:
    ctx->pc = 0x80070290u;
    // 80070290: stfs     f0, 52(r30)
    if (!ppc_fp_available_inline(ctx, 0x80070290u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(52);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80070294:
    ctx->pc = 0x80070294u;
    // 80070294: lfs     f0, 56(r30)
    if (!ppc_fp_available_inline(ctx, 0x80070294u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(56);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80070298:
    ctx->pc = 0x80070298u;
    // 80070298: fmuls   f0, f0, f31
    if (!ppc_fp_available_inline(ctx, 0x80070298u)) return;
    ppc_fmuls(ctx, 0, 0, 31);

label_8007029C:
    ctx->pc = 0x8007029Cu;
    // 8007029C: stfs     f0, 56(r30)
    if (!ppc_fp_available_inline(ctx, 0x8007029Cu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(56);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800702A0:
    ctx->pc = 0x800702A0u;
    // 800702A0: lfs     f0, 60(r30)
    if (!ppc_fp_available_inline(ctx, 0x800702A0u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(60);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800702A4:
    ctx->pc = 0x800702A4u;
    // 800702A4: fmuls   f0, f0, f31
    if (!ppc_fp_available_inline(ctx, 0x800702A4u)) return;
    ppc_fmuls(ctx, 0, 0, 31);

label_800702A8:
    ctx->pc = 0x800702A8u;
    // 800702A8: stfs     f0, 60(r30)
    if (!ppc_fp_available_inline(ctx, 0x800702A8u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(60);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800702AC:
    ctx->pc = 0x800702ACu;
    // 800702AC: cmplwi  r31, 0x0000
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

label_800702B0:
    ctx->pc = 0x800702B0u;
    // 800702B0: bc    12, 2, 0x80070304
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80070304;
        }
    }

label_800702B4:
    ctx->pc = 0x800702B4u;
    ctx->downcount -= 5;
    // 800702B4: fadds   f1, f29, f30
    if (!ppc_fp_available_inline(ctx, 0x800702B4u)) return;
    ppc_fadds(ctx, 1, 29, 30);

label_800702B8:
    ctx->pc = 0x800702B8u;
    // 800702B8: lfs     f0, -30332(r2)
    if (!ppc_fp_available_inline(ctx, 0x800702B8u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30332);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800702BC:
    ctx->pc = 0x800702BCu;
    // 800702BC: fcmpo   cr0, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x800702BCu)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[1], ctx->fpr[0], true);

label_800702C0:
    ctx->pc = 0x800702C0u;
    // 800702C0: cror    2, 0, 2
    {
        u32 a = (ctx->cr >> (31u - 0u)) & 1u;
        u32 b = (ctx->cr >> (31u - 2u)) & 1u;
        u32 mask = 0x80000000u >> 2;
        u32 value = (a | b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800702C4:
    ctx->pc = 0x800702C4u;
    // 800702C4: bc    4, 2, 0x800702D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800702D8;
        }
    }

label_800702C8:
    ctx->pc = 0x800702C8u;
    ctx->downcount -= 4;
    // 800702C8: lis     r3, 1
    ctx->gpr[3] = ((u32)(s32)(1) << 16);

label_800702CC:
    ctx->pc = 0x800702CCu;
    // 800702CC: addi    r0, r3, -1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-1);

label_800702D0:
    ctx->pc = 0x800702D0u;
    // 800702D0: sth     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_800702D4:
    ctx->pc = 0x800702D4u;
    // 800702D4: b       0x80070304
    {
            goto label_80070304;
    }

label_800702D8:
    ctx->pc = 0x800702D8u;
    ctx->downcount -= 25;
    // 800702D8: lfs     f0, -30328(r2)
    if (!ppc_fp_available_inline(ctx, 0x800702D8u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30328);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800702DC:
    ctx->pc = 0x800702DCu;
    // 800702DC: fdivs   f0, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x800702DCu)) return;
    ppc_fdivs(ctx, 0, 0, 1);

label_800702E0:
    ctx->pc = 0x800702E0u;
    // 800702E0: fctiwz    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x800702E0u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_800702E4:
    ctx->pc = 0x800702E4u;
    // 800702E4: stfd     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x800702E4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_800702E8:
    ctx->pc = 0x800702E8u;
    // 800702E8: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800702EC:
    ctx->pc = 0x800702ECu;
    // 800702EC: sth     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_800702F0:
    ctx->pc = 0x800702F0u;
    // 800702F0: lhz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_800702F4:
    ctx->pc = 0x800702F4u;
    // 800702F4: cmplwi  r0, 0x0000
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

label_800702F8:
    ctx->pc = 0x800702F8u;
    // 800702F8: bc    4, 2, 0x80070304
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070304;
        }
    }

label_800702FC:
    ctx->pc = 0x800702FCu;
    ctx->downcount -= 2;
    // 800702FC: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80070300:
    ctx->pc = 0x80070300u;
    // 80070300: sth     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80070304:
    ctx->pc = 0x80070304u;
    ctx->downcount -= 11;
    // 80070304: fabs    f0, f29
    if (!ppc_fp_available_inline(ctx, 0x80070304u)) return;
    ctx->fpr[0] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[29]) & 0x7FFFFFFFFFFFFFFFull);

label_80070308:
    ctx->pc = 0x80070308u;
    // 80070308: frsp    f3, f0
    if (!ppc_fp_available_inline(ctx, 0x80070308u)) return;
    ppc_frsp(ctx, 3, 0);

label_8007030C:
    ctx->pc = 0x8007030Cu;
    // 8007030C: stfs     f3, -24912(r13)
    if (!ppc_fp_available_inline(ctx, 0x8007030Cu)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24912);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[3]));
    }

label_80070310:
    ctx->pc = 0x80070310u;
    // 80070310: fabs    f0, f30
    if (!ppc_fp_available_inline(ctx, 0x80070310u)) return;
    ctx->fpr[0] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[30]) & 0x7FFFFFFFFFFFFFFFull);

label_80070314:
    ctx->pc = 0x80070314u;
    // 80070314: frsp    f4, f0
    if (!ppc_fp_available_inline(ctx, 0x80070314u)) return;
    ppc_frsp(ctx, 4, 0);

label_80070318:
    ctx->pc = 0x80070318u;
    // 80070318: stfs     f4, -24916(r13)
    if (!ppc_fp_available_inline(ctx, 0x80070318u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24916);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[4]));
    }

label_8007031C:
    ctx->pc = 0x8007031Cu;
    // 8007031C: lis     r3, -32710
    ctx->gpr[3] = ((u32)(s32)(-32710) << 16);

label_80070320:
    ctx->pc = 0x80070320u;
    // 80070320: addi    r3, r3, -32224
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-32224);

label_80070324:
    ctx->pc = 0x80070324u;
    // 80070324: fmr    f1, f27
    if (!ppc_fp_available_inline(ctx, 0x80070324u)) return;
    ctx->fpr[1] = ctx->fpr[27];

label_80070328:
    ctx->pc = 0x80070328u;
    // 80070328: fmr    f2, f28
    if (!ppc_fp_available_inline(ctx, 0x80070328u)) return;
    ctx->fpr[2] = ctx->fpr[28];

label_8007032C:
    ctx->pc = 0x8007032Cu;
    // 8007032C: bl      0x80247F74
    {
            ctx->lr = 0x80070330u;
            ctx->pc = 0x80247F74u;
            return;
    }

label_80070330:
    ctx->pc = 0x80070330u;
    ctx->downcount -= 23;
    // 80070330: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80070334:
    ctx->pc = 0x80070334u;
    // 80070334: stw     r0, -24908(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24908);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80070338:
    ctx->pc = 0x80070338u;
    // 80070338: psq_l   f31, 136(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x80070338u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        ppc_psq_load_inline(ctx, 31u, ea, false, 0u, false, 0x80070338u);
        if (ctx->exception) return;
    }

label_8007033C:
    ctx->pc = 0x8007033Cu;
    // 8007033C: lfd     f31, 128(r1)
    if (!ppc_fp_available_inline(ctx, 0x8007033Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(128);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80070340:
    ctx->pc = 0x80070340u;
    // 80070340: psq_l   f30, 120(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x80070340u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(120);
        ppc_psq_load_inline(ctx, 30u, ea, false, 0u, false, 0x80070340u);
        if (ctx->exception) return;
    }

label_80070344:
    ctx->pc = 0x80070344u;
    // 80070344: lfd     f30, 112(r1)
    if (!ppc_fp_available_inline(ctx, 0x80070344u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(112);
        ctx->fpr[30] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80070348:
    ctx->pc = 0x80070348u;
    // 80070348: psq_l   f29, 104(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x80070348u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        ppc_psq_load_inline(ctx, 29u, ea, false, 0u, false, 0x80070348u);
        if (ctx->exception) return;
    }

label_8007034C:
    ctx->pc = 0x8007034Cu;
    // 8007034C: lfd     f29, 96(r1)
    if (!ppc_fp_available_inline(ctx, 0x8007034Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        ctx->fpr[29] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80070350:
    ctx->pc = 0x80070350u;
    // 80070350: psq_l   f28, 88(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x80070350u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        ppc_psq_load_inline(ctx, 28u, ea, false, 0u, false, 0x80070350u);
        if (ctx->exception) return;
    }

label_80070354:
    ctx->pc = 0x80070354u;
    // 80070354: lfd     f28, 80(r1)
    if (!ppc_fp_available_inline(ctx, 0x80070354u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        ctx->fpr[28] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80070358:
    ctx->pc = 0x80070358u;
    // 80070358: psq_l   f27, 72(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x80070358u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        ppc_psq_load_inline(ctx, 27u, ea, false, 0u, false, 0x80070358u);
        if (ctx->exception) return;
    }

label_8007035C:
    ctx->pc = 0x8007035Cu;
    // 8007035C: lfd     f27, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x8007035Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        ctx->fpr[27] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80070360:
    ctx->pc = 0x80070360u;
    // 80070360: psq_l   f26, 56(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x80070360u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        ppc_psq_load_inline(ctx, 26u, ea, false, 0u, false, 0x80070360u);
        if (ctx->exception) return;
    }

label_80070364:
    ctx->pc = 0x80070364u;
    // 80070364: lfd     f26, 48(r1)
    if (!ppc_fp_available_inline(ctx, 0x80070364u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->fpr[26] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80070368:
    ctx->pc = 0x80070368u;
    // 80070368: psq_l   f25, 40(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x80070368u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ppc_psq_load_inline(ctx, 25u, ea, false, 0u, false, 0x80070368u);
        if (ctx->exception) return;
    }

label_8007036C:
    ctx->pc = 0x8007036Cu;
    // 8007036C: lfd     f25, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x8007036Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->fpr[25] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80070370:
    ctx->pc = 0x80070370u;
    // 80070370: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80070374:
    ctx->pc = 0x80070374u;
    // 80070374: lwz     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80070378:
    ctx->pc = 0x80070378u;
    // 80070378: lwz     r0, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8007037C:
    ctx->pc = 0x8007037Cu;
    // 8007037C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80070380:
    ctx->pc = 0x80070380u;
    // 80070380: addi    r1, r1, 144
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(144);

label_80070384:
    ctx->pc = 0x80070384u;
    // 80070384: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_80070388:
    ctx->pc = 0x80070388u;
    ctx->downcount -= 18;
    // 80070388: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8007038C:
    ctx->pc = 0x8007038Cu;
    // 8007038C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80070390:
    ctx->pc = 0x80070390u;
    // 80070390: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80070394:
    ctx->pc = 0x80070394u;
    // 80070394: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80070398:
    ctx->pc = 0x80070398u;
    // 80070398: stw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8007039C:
    ctx->pc = 0x8007039Cu;
    // 8007039C: stw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_800703A0:
    ctx->pc = 0x800703A0u;
    // 800703A0: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800703A4:
    ctx->pc = 0x800703A4u;
    // 800703A4: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_800703A8:
    ctx->pc = 0x800703A8u;
    // 800703A8: or   r31, r5, r5
    {
        ctx->gpr[31] = ctx->gpr[5] | ctx->gpr[5];
    }

label_800703AC:
    ctx->pc = 0x800703ACu;
    // 800703AC: lfs     f0, 0(r31)
    if (!ppc_fp_available_inline(ctx, 0x800703ACu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800703B0:
    ctx->pc = 0x800703B0u;
    // 800703B0: fmuls   f2, f0, f0
    if (!ppc_fp_available_inline(ctx, 0x800703B0u)) return;
    ppc_fmuls(ctx, 2, 0, 0);

label_800703B4:
    ctx->pc = 0x800703B4u;
    // 800703B4: lfs     f0, 0(r29)
    if (!ppc_fp_available_inline(ctx, 0x800703B4u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800703B8:
    ctx->pc = 0x800703B8u;
    // 800703B8: fmuls   f1, f0, f0
    if (!ppc_fp_available_inline(ctx, 0x800703B8u)) return;
    ppc_fmuls(ctx, 1, 0, 0);

label_800703BC:
    ctx->pc = 0x800703BCu;
    // 800703BC: lfs     f0, 0(r30)
    if (!ppc_fp_available_inline(ctx, 0x800703BCu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800703C0:
    ctx->pc = 0x800703C0u;
    // 800703C0: fmuls   f0, f0, f0
    if (!ppc_fp_available_inline(ctx, 0x800703C0u)) return;
    ppc_fmuls(ctx, 0, 0, 0);

label_800703C4:
    ctx->pc = 0x800703C4u;
    // 800703C4: fadds   f0, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x800703C4u)) return;
    ppc_fadds(ctx, 0, 1, 0);

label_800703C8:
    ctx->pc = 0x800703C8u;
    // 800703C8: fadds   f1, f2, f0
    if (!ppc_fp_available_inline(ctx, 0x800703C8u)) return;
    ppc_fadds(ctx, 1, 2, 0);

label_800703CC:
    ctx->pc = 0x800703CCu;
    // 800703CC: bl      0x80293B10
    {
            ctx->lr = 0x800703D0u;
            ctx->pc = 0x80293B10u;
            return;
    }

label_800703D0:
    ctx->pc = 0x800703D0u;
    ctx->downcount -= 35;
    // 800703D0: lfs     f0, -30312(r2)
    if (!ppc_fp_available_inline(ctx, 0x800703D0u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30312);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800703D4:
    ctx->pc = 0x800703D4u;
    // 800703D4: fdivs   f1, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x800703D4u)) return;
    ppc_fdivs(ctx, 1, 0, 1);

label_800703D8:
    ctx->pc = 0x800703D8u;
    // 800703D8: lfs     f0, 0(r29)
    if (!ppc_fp_available_inline(ctx, 0x800703D8u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800703DC:
    ctx->pc = 0x800703DCu;
    // 800703DC: fmuls   f0, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x800703DCu)) return;
    ppc_fmuls(ctx, 0, 0, 1);

label_800703E0:
    ctx->pc = 0x800703E0u;
    // 800703E0: stfs     f0, 0(r29)
    if (!ppc_fp_available_inline(ctx, 0x800703E0u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800703E4:
    ctx->pc = 0x800703E4u;
    // 800703E4: lfs     f0, 0(r30)
    if (!ppc_fp_available_inline(ctx, 0x800703E4u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800703E8:
    ctx->pc = 0x800703E8u;
    // 800703E8: fmuls   f0, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x800703E8u)) return;
    ppc_fmuls(ctx, 0, 0, 1);

label_800703EC:
    ctx->pc = 0x800703ECu;
    // 800703EC: stfs     f0, 0(r30)
    if (!ppc_fp_available_inline(ctx, 0x800703ECu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800703F0:
    ctx->pc = 0x800703F0u;
    // 800703F0: lfs     f0, 0(r31)
    if (!ppc_fp_available_inline(ctx, 0x800703F0u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800703F4:
    ctx->pc = 0x800703F4u;
    // 800703F4: fmuls   f0, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x800703F4u)) return;
    ppc_fmuls(ctx, 0, 0, 1);

label_800703F8:
    ctx->pc = 0x800703F8u;
    // 800703F8: stfs     f0, 0(r31)
    if (!ppc_fp_available_inline(ctx, 0x800703F8u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800703FC:
    ctx->pc = 0x800703FCu;
    // 800703FC: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80070400:
    ctx->pc = 0x80070400u;
    // 80070400: lwz     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80070404:
    ctx->pc = 0x80070404u;
    // 80070404: lwz     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80070408:
    ctx->pc = 0x80070408u;
    // 80070408: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8007040C:
    ctx->pc = 0x8007040Cu;
    // 8007040C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80070410:
    ctx->pc = 0x80070410u;
    // 80070410: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_80070414:
    ctx->pc = 0x80070414u;
    // 80070414: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_80070418:
    ctx->pc = 0x80070418u;
    ctx->downcount -= 6;
    // 80070418: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8007041C:
    ctx->pc = 0x8007041Cu;
    // 8007041C: lfs     f1, -30304(r2)
    if (!ppc_fp_available_inline(ctx, 0x8007041Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30304);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80070420:
    ctx->pc = 0x80070420u;
    // 80070420: lfs     f0, -30300(r2)
    if (!ppc_fp_available_inline(ctx, 0x80070420u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30300);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80070424:
    ctx->pc = 0x80070424u;
    // 80070424: li      r0, 4
    ctx->gpr[0] = (u32)(s32)(4);

label_80070428:
    ctx->pc = 0x80070428u;
    // 80070428: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8007042C:
    ctx->downcount -= 3;
    // 8007042C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80070430:
    // 80070430: cmpw    r4, r0
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80070434:
    // 80070434: bc    4, 2, 0x80070440
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070440;
        }
    }

label_80070438:
    ctx->pc = 0x80070438u;
    ctx->downcount -= 2;
    // 80070438: stfs     f1, 0(r3)
    if (!ppc_fp_available_inline(ctx, 0x80070438u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8007043C:
    // 8007043C: b       0x80070444
    {
            goto label_80070444;
    }

label_80070440:
    ctx->pc = 0x80070440u;
    ctx->downcount -= 1;
    // 80070440: stfs     f0, 0(r3)
    if (!ppc_fp_available_inline(ctx, 0x80070440u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80070444:
    ctx->downcount -= 3;
    // 80070444: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80070448:
    // 80070448: cmpw    r4, r0
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8007044C:
    // 8007044C: bc    4, 2, 0x80070458
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070458;
        }
    }

label_80070450:
    ctx->pc = 0x80070450u;
    ctx->downcount -= 2;
    // 80070450: stfs     f1, 4(r3)
    if (!ppc_fp_available_inline(ctx, 0x80070450u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80070454:
    // 80070454: b       0x8007045C
    {
            goto label_8007045C;
    }

label_80070458:
    ctx->pc = 0x80070458u;
    ctx->downcount -= 1;
    // 80070458: stfs     f0, 4(r3)
    if (!ppc_fp_available_inline(ctx, 0x80070458u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8007045C:
    ctx->downcount -= 3;
    // 8007045C: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_80070460:
    // 80070460: cmpw    r4, r0
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80070464:
    // 80070464: bc    4, 2, 0x80070470
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070470;
        }
    }

label_80070468:
    ctx->pc = 0x80070468u;
    ctx->downcount -= 2;
    // 80070468: stfs     f1, 8(r3)
    if (!ppc_fp_available_inline(ctx, 0x80070468u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8007046C:
    // 8007046C: b       0x80070474
    {
            goto label_80070474;
    }

label_80070470:
    ctx->pc = 0x80070470u;
    ctx->downcount -= 1;
    // 80070470: stfs     f0, 8(r3)
    if (!ppc_fp_available_inline(ctx, 0x80070470u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80070474:
    ctx->downcount -= 3;
    // 80070474: li      r0, 3
    ctx->gpr[0] = (u32)(s32)(3);

label_80070478:
    // 80070478: cmpw    r4, r0
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8007047C:
    // 8007047C: bc    4, 2, 0x80070488
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070488;
        }
    }

label_80070480:
    ctx->pc = 0x80070480u;
    ctx->downcount -= 2;
    // 80070480: stfs     f1, 12(r3)
    if (!ppc_fp_available_inline(ctx, 0x80070480u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80070484:
    // 80070484: b       0x8007048C
    {
            goto label_8007048C;
    }

label_80070488:
    ctx->pc = 0x80070488u;
    ctx->downcount -= 1;
    // 80070488: stfs     f0, 12(r3)
    if (!ppc_fp_available_inline(ctx, 0x80070488u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8007048C:
    ctx->downcount -= 3;
    // 8007048C: addi    r3, r3, 16
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(16);

label_80070490:
    // 80070490: addi    r4, r4, 1
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(1);

label_80070494:
    // 80070494: bc    16, 0, 0x8007042C
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8007042Cu;
                return;
            }
            goto label_8007042C;
        }
    }

label_80070498:
    ctx->pc = 0x80070498u;
    ctx->downcount -= 1;
    // 80070498: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_8007049C:
    ctx->pc = 0x8007049Cu;
    ctx->downcount -= 9;
    // 8007049C: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800704A0:
    ctx->pc = 0x800704A0u;
    // 800704A0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800704A4:
    ctx->pc = 0x800704A4u;
    // 800704A4: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800704A8:
    ctx->pc = 0x800704A8u;
    // 800704A8: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_800704AC:
    ctx->pc = 0x800704ACu;
    // 800704AC: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800704B0:
    ctx->pc = 0x800704B0u;
    // 800704B0: lbz     r3, -24951(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24951);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_800704B4:
    ctx->pc = 0x800704B4u;
    // 800704B4: rlwinm r0, r31, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[31], 0u) & 0x000000FFu;
    }

label_800704B8:
    ctx->pc = 0x800704B8u;
    // 800704B8: cmplw   r3, r0
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

label_800704BC:
    ctx->pc = 0x800704BCu;
    // 800704BC: bc    4, 2, 0x800704CC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800704CC;
        }
    }

label_800704C0:
    ctx->pc = 0x800704C0u;
    ctx->downcount -= 3;
    // 800704C0: lbz     r0, -24943(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24943);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_800704C4:
    ctx->pc = 0x800704C4u;
    // 800704C4: cmplwi  r0, 0x0000
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

label_800704C8:
    ctx->pc = 0x800704C8u;
    // 800704C8: bc    4, 2, 0x800704E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800704E0;
        }
    }

label_800704CC:
    ctx->pc = 0x800704CCu;
    ctx->downcount -= 2;
    // 800704CC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800704D0:
    ctx->pc = 0x800704D0u;
    // 800704D0: bl      0x8025D0F0
    {
            ctx->lr = 0x800704D4u;
            ctx->pc = 0x8025D0F0u;
            return;
    }

label_800704D4:
    ctx->pc = 0x800704D4u;
    ctx->downcount -= 3;
    // 800704D4: stb     r31, -24951(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24951);
        mem_write8(ctx, ea, (u8)ctx->gpr[31]);
    }

label_800704D8:
    ctx->pc = 0x800704D8u;
    // 800704D8: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_800704DC:
    ctx->pc = 0x800704DCu;
    // 800704DC: stb     r0, -24943(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24943);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_800704E0:
    ctx->pc = 0x800704E0u;
    ctx->downcount -= 6;
    // 800704E0: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_800704E4:
    ctx->pc = 0x800704E4u;
    // 800704E4: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800704E8:
    ctx->pc = 0x800704E8u;
    // 800704E8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800704EC:
    ctx->pc = 0x800704ECu;
    // 800704EC: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800704F0:
    ctx->pc = 0x800704F0u;
    // 800704F0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_800704F4:
    ctx->pc = 0x800704F4u;
    ctx->downcount -= 13;
    // 800704F4: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800704F8:
    ctx->pc = 0x800704F8u;
    // 800704F8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800704FC:
    ctx->pc = 0x800704FCu;
    // 800704FC: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80070500:
    ctx->pc = 0x80070500u;
    // 80070500: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80070504:
    ctx->pc = 0x80070504u;
    // 80070504: stw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80070508:
    ctx->pc = 0x80070508u;
    // 80070508: stw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_8007050C:
    ctx->pc = 0x8007050Cu;
    // 8007050C: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80070510:
    ctx->pc = 0x80070510u;
    // 80070510: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80070514:
    ctx->pc = 0x80070514u;
    // 80070514: or   r31, r5, r5
    {
        ctx->gpr[31] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80070518:
    ctx->pc = 0x80070518u;
    // 80070518: lbz     r3, -24944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24944);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8007051C:
    ctx->pc = 0x8007051Cu;
    // 8007051C: rlwinm r0, r29, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[29], 0u) & 0x000000FFu;
    }

label_80070520:
    ctx->pc = 0x80070520u;
    // 80070520: cmplw   r3, r0
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

label_80070524:
    ctx->pc = 0x80070524u;
    // 80070524: bc    4, 2, 0x80070550
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070550;
        }
    }

label_80070528:
    ctx->pc = 0x80070528u;
    ctx->downcount -= 3;
    // 80070528: lwz     r0, -24948(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24948);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8007052C:
    ctx->pc = 0x8007052Cu;
    // 8007052C: cmpw    r0, r30
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[30]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80070530:
    ctx->pc = 0x80070530u;
    // 80070530: bc    4, 2, 0x80070550
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070550;
        }
    }

label_80070534:
    ctx->pc = 0x80070534u;
    ctx->downcount -= 4;
    // 80070534: lbz     r3, -24950(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24950);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_80070538:
    ctx->pc = 0x80070538u;
    // 80070538: rlwinm r0, r31, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[31], 0u) & 0x000000FFu;
    }

label_8007053C:
    ctx->pc = 0x8007053Cu;
    // 8007053C: cmplw   r3, r0
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

label_80070540:
    ctx->pc = 0x80070540u;
    // 80070540: bc    4, 2, 0x80070550
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070550;
        }
    }

label_80070544:
    ctx->pc = 0x80070544u;
    ctx->downcount -= 3;
    // 80070544: lbz     r0, -24942(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24942);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80070548:
    ctx->pc = 0x80070548u;
    // 80070548: cmplwi  r0, 0x0000
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

label_8007054C:
    ctx->pc = 0x8007054Cu;
    // 8007054C: bc    4, 2, 0x80070574
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070574;
        }
    }

label_80070550:
    ctx->pc = 0x80070550u;
    ctx->downcount -= 4;
    // 80070550: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80070554:
    ctx->pc = 0x80070554u;
    // 80070554: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80070558:
    ctx->pc = 0x80070558u;
    // 80070558: or   r5, r31, r31
    {
        ctx->gpr[5] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8007055C:
    ctx->pc = 0x8007055Cu;
    // 8007055C: bl      0x8025D078
    {
            ctx->lr = 0x80070560u;
            ctx->pc = 0x8025D078u;
            return;
    }

label_80070560:
    ctx->pc = 0x80070560u;
    ctx->downcount -= 5;
    // 80070560: stb     r29, -24944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24944);
        mem_write8(ctx, ea, (u8)ctx->gpr[29]);
    }

label_80070564:
    ctx->pc = 0x80070564u;
    // 80070564: stw     r30, -24948(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24948);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80070568:
    ctx->pc = 0x80070568u;
    // 80070568: stb     r31, -24950(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24950);
        mem_write8(ctx, ea, (u8)ctx->gpr[31]);
    }

label_8007056C:
    ctx->pc = 0x8007056Cu;
    // 8007056C: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80070570:
    ctx->pc = 0x80070570u;
    // 80070570: stb     r0, -24942(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24942);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80070574:
    ctx->pc = 0x80070574u;
    ctx->downcount -= 8;
    // 80070574: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80070578:
    ctx->pc = 0x80070578u;
    // 80070578: lwz     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8007057C:
    ctx->pc = 0x8007057Cu;
    // 8007057C: lwz     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80070580:
    ctx->pc = 0x80070580u;
    // 80070580: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80070584:
    ctx->pc = 0x80070584u;
    // 80070584: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80070588:
    ctx->pc = 0x80070588u;
    // 80070588: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_8007058C:
    ctx->pc = 0x8007058Cu;
    // 8007058C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_80070590:
    ctx->pc = 0x80070590u;
    ctx->downcount -= 4;
    // 80070590: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80070594:
    ctx->pc = 0x80070594u;
    // 80070594: stb     r0, -24942(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24942);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80070598:
    ctx->pc = 0x80070598u;
    // 80070598: stb     r0, -24943(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24943);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8007059C:
    ctx->pc = 0x8007059Cu;
    // 8007059C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_800705A0:
    ctx->pc = 0x800705A0u;
    ctx->downcount -= 2;
    // 800705A0: stb     r3, -31511(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31511);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_800705A4:
    ctx->pc = 0x800705A4u;
    // 800705A4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_800705A8:
    ctx->pc = 0x800705A8u;
    ctx->downcount -= 12;
    // 800705A8: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800705AC:
    ctx->pc = 0x800705ACu;
    // 800705AC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800705B0:
    ctx->pc = 0x800705B0u;
    // 800705B0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800705B4:
    ctx->pc = 0x800705B4u;
    // 800705B4: lwz     r0, -24940(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24940);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800705B8:
    ctx->pc = 0x800705B8u;
    // 800705B8: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800705BC:
    ctx->pc = 0x800705BCu;
    // 800705BC: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_800705C0:
    ctx->pc = 0x800705C0u;
    // 800705C0: lfs     f1, -24932(r13)
    if (!ppc_fp_available_inline(ctx, 0x800705C0u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24932);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800705C4:
    ctx->pc = 0x800705C4u;
    // 800705C4: lfs     f2, -24936(r13)
    if (!ppc_fp_available_inline(ctx, 0x800705C4u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24936);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_800705C8:
    ctx->pc = 0x800705C8u;
    // 800705C8: lfs     f3, -24912(r13)
    if (!ppc_fp_available_inline(ctx, 0x800705C8u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24912);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_800705CC:
    ctx->pc = 0x800705CCu;
    // 800705CC: lfs     f4, -24916(r13)
    if (!ppc_fp_available_inline(ctx, 0x800705CCu)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24916);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[4] = value;
        ctx->ps1[4] = value;
    }

label_800705D0:
    ctx->pc = 0x800705D0u;
    // 800705D0: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_800705D4:
    ctx->pc = 0x800705D4u;
    // 800705D4: bl      0x8025CC44
    {
            ctx->lr = 0x800705D8u;
            ctx->pc = 0x8025CC44u;
            return;
    }

label_800705D8:
    ctx->pc = 0x800705D8u;
    ctx->downcount -= 5;
    // 800705D8: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800705DC:
    ctx->pc = 0x800705DCu;
    // 800705DC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800705E0:
    ctx->pc = 0x800705E0u;
    // 800705E0: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800705E4:
    ctx->pc = 0x800705E4u;
    // 800705E4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_800705E8:
    ctx->pc = 0x800705E8u;
    ctx->downcount -= 10;
    // 800705E8: stwu     r1, -48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-48);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800705EC:
    ctx->pc = 0x800705ECu;
    // 800705EC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800705F0:
    ctx->pc = 0x800705F0u;
    // 800705F0: stw     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800705F4:
    ctx->pc = 0x800705F4u;
    // 800705F4: stfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800705F4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_800705F8:
    ctx->pc = 0x800705F8u;
    // 800705F8: psq_st   f31, 40(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x800705F8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ppc_psq_store_inline(ctx, 31u, ea, false, 0u, false, 0x800705F8u);
        if (ctx->exception) return;
    }

label_800705FC:
    ctx->pc = 0x800705FCu;
    // 800705FC: stfd     f30, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x800705FCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[30]));
    }

label_80070600:
    ctx->pc = 0x80070600u;
    // 80070600: psq_st   f30, 24(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x80070600u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ppc_psq_store_inline(ctx, 30u, ea, false, 0u, false, 0x80070600u);
        if (ctx->exception) return;
    }

label_80070604:
    ctx->pc = 0x80070604u;
    // 80070604: fmr    f30, f1
    if (!ppc_fp_available_inline(ctx, 0x80070604u)) return;
    ctx->fpr[30] = ctx->fpr[1];

label_80070608:
    ctx->pc = 0x80070608u;
    // 80070608: fmr    f31, f2
    if (!ppc_fp_available_inline(ctx, 0x80070608u)) return;
    ctx->fpr[31] = ctx->fpr[2];

label_8007060C:
    ctx->pc = 0x8007060Cu;
    // 8007060C: bl      0x8000FC3C
    {
            ctx->lr = 0x80070610u;
            ctx->pc = 0x8000FC3Cu;
            return;
    }

label_80070610:
    ctx->pc = 0x80070610u;
    ctx->downcount -= 2;
    // 80070610: stfs     f1, -24912(r13)
    if (!ppc_fp_available_inline(ctx, 0x80070610u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24912);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80070614:
    ctx->pc = 0x80070614u;
    // 80070614: bl      0x8000FC08
    {
            ctx->lr = 0x80070618u;
            ctx->pc = 0x8000FC08u;
            return;
    }

label_80070618:
    ctx->pc = 0x80070618u;
    ctx->downcount -= 7;
    // 80070618: stfs     f1, -24916(r13)
    if (!ppc_fp_available_inline(ctx, 0x80070618u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24916);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8007061C:
    ctx->pc = 0x8007061Cu;
    // 8007061C: lfs     f0, -30240(r2)
    if (!ppc_fp_available_inline(ctx, 0x8007061Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30240);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80070620:
    ctx->pc = 0x80070620u;
    // 80070620: fmuls   f1, f0, f30
    if (!ppc_fp_available_inline(ctx, 0x80070620u)) return;
    ppc_fmuls(ctx, 1, 0, 30);

label_80070624:
    ctx->pc = 0x80070624u;
    // 80070624: fmuls   f3, f0, f31
    if (!ppc_fp_available_inline(ctx, 0x80070624u)) return;
    ppc_fmuls(ctx, 3, 0, 31);

label_80070628:
    ctx->pc = 0x80070628u;
    // 80070628: lfs     f0, -30236(r2)
    if (!ppc_fp_available_inline(ctx, 0x80070628u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30236);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8007062C:
    ctx->pc = 0x8007062Cu;
    // 8007062C: fcmpo   cr0, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8007062Cu)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[1], ctx->fpr[0], true);

label_80070630:
    ctx->pc = 0x80070630u;
    // 80070630: bc    4, 0, 0x80070638
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070638;
        }
    }

label_80070634:
    ctx->pc = 0x80070634u;
    ctx->downcount -= 1;
    // 80070634: b       0x8007064C
    {
            goto label_8007064C;
    }

label_80070638:
    ctx->pc = 0x80070638u;
    ctx->downcount -= 3;
    // 80070638: lfs     f0, -30232(r2)
    if (!ppc_fp_available_inline(ctx, 0x80070638u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30232);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8007063C:
    ctx->pc = 0x8007063Cu;
    // 8007063C: fcmpo   cr0, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8007063Cu)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[1], ctx->fpr[0], true);

label_80070640:
    ctx->pc = 0x80070640u;
    // 80070640: bc    4, 1, 0x80070648
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070648;
        }
    }

label_80070644:
    ctx->pc = 0x80070644u;
    ctx->downcount -= 1;
    // 80070644: b       0x8007064C
    {
            goto label_8007064C;
    }

label_80070648:
    ctx->pc = 0x80070648u;
    ctx->downcount -= 1;
    // 80070648: fmr    f0, f1
    if (!ppc_fp_available_inline(ctx, 0x80070648u)) return;
    ctx->fpr[0] = ctx->fpr[1];

label_8007064C:
    ctx->pc = 0x8007064Cu;
    ctx->downcount -= 3;
    // 8007064C: lfs     f2, -30236(r2)
    if (!ppc_fp_available_inline(ctx, 0x8007064Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30236);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_80070650:
    ctx->pc = 0x80070650u;
    // 80070650: fcmpo   cr0, f3, f2
    if (!ppc_fp_available_inline(ctx, 0x80070650u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[3], ctx->fpr[2], true);

label_80070654:
    ctx->pc = 0x80070654u;
    // 80070654: bc    4, 0, 0x8007065C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8007065C;
        }
    }

label_80070658:
    ctx->pc = 0x80070658u;
    ctx->downcount -= 1;
    // 80070658: b       0x80070670
    {
            goto label_80070670;
    }

label_8007065C:
    ctx->pc = 0x8007065Cu;
    ctx->downcount -= 3;
    // 8007065C: lfs     f2, -30232(r2)
    if (!ppc_fp_available_inline(ctx, 0x8007065Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30232);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_80070660:
    ctx->pc = 0x80070660u;
    // 80070660: fcmpo   cr0, f3, f2
    if (!ppc_fp_available_inline(ctx, 0x80070660u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[3], ctx->fpr[2], true);

label_80070664:
    ctx->pc = 0x80070664u;
    // 80070664: bc    4, 1, 0x8007066C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8007066C;
        }
    }

label_80070668:
    ctx->pc = 0x80070668u;
    ctx->downcount -= 1;
    // 80070668: b       0x80070670
    {
            goto label_80070670;
    }

label_8007066C:
    ctx->pc = 0x8007066Cu;
    ctx->downcount -= 1;
    // 8007066C: fmr    f2, f3
    if (!ppc_fp_available_inline(ctx, 0x8007066Cu)) return;
    ctx->fpr[2] = ctx->fpr[3];

label_80070670:
    ctx->pc = 0x80070670u;
    ctx->downcount -= 12;
    // 80070670: lfs     f3, -24912(r13)
    if (!ppc_fp_available_inline(ctx, 0x80070670u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24912);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_80070674:
    ctx->pc = 0x80070674u;
    // 80070674: lfs     f4, -24916(r13)
    if (!ppc_fp_available_inline(ctx, 0x80070674u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24916);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[4] = value;
        ctx->ps1[4] = value;
    }

label_80070678:
    ctx->pc = 0x80070678u;
    // 80070678: fsubs   f5, f4, f3
    if (!ppc_fp_available_inline(ctx, 0x80070678u)) return;
    ppc_fsubs(ctx, 5, 4, 3);

label_8007067C:
    ctx->pc = 0x8007067Cu;
    // 8007067C: fmadds f1, f0, f5, f3
    if (!ppc_fp_available_inline(ctx, 0x8007067Cu)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[0], ctx->fpr[5], ctx->fpr[3], true, false, false, &result))
            ctx->fpr[1] = ctx->ps1[1] = result;
    }

label_80070680:
    ctx->pc = 0x80070680u;
    // 80070680: stfs     f1, -24932(r13)
    if (!ppc_fp_available_inline(ctx, 0x80070680u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24932);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80070684:
    ctx->pc = 0x80070684u;
    // 80070684: fmadds f2, f2, f5, f3
    if (!ppc_fp_available_inline(ctx, 0x80070684u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[2], ctx->fpr[5], ctx->fpr[3], true, false, false, &result))
            ctx->fpr[2] = ctx->ps1[2] = result;
    }

label_80070688:
    ctx->pc = 0x80070688u;
    // 80070688: stfs     f2, -24936(r13)
    if (!ppc_fp_available_inline(ctx, 0x80070688u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24936);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_8007068C:
    ctx->pc = 0x8007068Cu;
    // 8007068C: lwz     r0, -24940(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24940);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80070690:
    ctx->pc = 0x80070690u;
    // 80070690: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80070694:
    ctx->pc = 0x80070694u;
    // 80070694: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_80070698:
    ctx->pc = 0x80070698u;
    // 80070698: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_8007069C:
    ctx->pc = 0x8007069Cu;
    // 8007069C: bl      0x8025CC44
    {
            ctx->lr = 0x800706A0u;
            ctx->pc = 0x8025CC44u;
            return;
    }

label_800706A0:
    ctx->pc = 0x800706A0u;
    ctx->downcount -= 9;
    // 800706A0: psq_l   f31, 40(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x800706A0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ppc_psq_load_inline(ctx, 31u, ea, false, 0u, false, 0x800706A0u);
        if (ctx->exception) return;
    }

label_800706A4:
    ctx->pc = 0x800706A4u;
    // 800706A4: lfd     f31, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x800706A4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800706A8:
    ctx->pc = 0x800706A8u;
    // 800706A8: psq_l   f30, 24(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x800706A8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ppc_psq_load_inline(ctx, 30u, ea, false, 0u, false, 0x800706A8u);
        if (ctx->exception) return;
    }

label_800706AC:
    ctx->pc = 0x800706ACu;
    // 800706AC: lfd     f30, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x800706ACu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[30] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800706B0:
    ctx->pc = 0x800706B0u;
    // 800706B0: lwz     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800706B4:
    ctx->pc = 0x800706B4u;
    // 800706B4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800706B8:
    ctx->pc = 0x800706B8u;
    // 800706B8: addi    r1, r1, 48
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(48);

label_800706BC:
    ctx->pc = 0x800706BCu;
    // 800706BC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_800706C0:
    ctx->pc = 0x800706C0u;
    ctx->downcount -= 8;
    // 800706C0: lbz     r0, -24940(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24940);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_800706C4:
    ctx->pc = 0x800706C4u;
    // 800706C4: stb     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_800706C8:
    ctx->pc = 0x800706C8u;
    // 800706C8: addi    r4, r13, -24940
    ctx->gpr[4] = ctx->gpr[13] + (u32)(s32)(-24940);

label_800706CC:
    ctx->pc = 0x800706CCu;
    // 800706CC: lbz     r0, 1(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(1);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_800706D0:
    ctx->pc = 0x800706D0u;
    // 800706D0: stb     r0, 1(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_800706D4:
    ctx->pc = 0x800706D4u;
    // 800706D4: lbz     r0, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_800706D8:
    ctx->pc = 0x800706D8u;
    // 800706D8: stb     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_800706DC:
    ctx->pc = 0x800706DCu;
    // 800706DC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_800706E0:
    ctx->pc = 0x800706E0u;
    ctx->downcount -= 5;
    // 800706E0: stb     r3, -24940(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24940);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_800706E4:
    ctx->pc = 0x800706E4u;
    // 800706E4: addi    r3, r13, -24940
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-24940);

label_800706E8:
    ctx->pc = 0x800706E8u;
    // 800706E8: stb     r4, 1(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_800706EC:
    ctx->pc = 0x800706ECu;
    // 800706EC: stb     r5, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

label_800706F0:
    ctx->pc = 0x800706F0u;
    // 800706F0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_800706F4:
    ctx->pc = 0x800706F4u;
    ctx->downcount -= 5;
    // 800706F4: stwu     r1, -128(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-128);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800706F8:
    ctx->pc = 0x800706F8u;
    // 800706F8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800706FC:
    ctx->pc = 0x800706FCu;
    // 800706FC: stw     r0, 132(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(132);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80070700:
    ctx->pc = 0x80070700u;
    // 80070700: addi    r11, r1, 128
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(128);

label_80070704:
    ctx->pc = 0x80070704u;
    // 80070704: bl      0x80286A44
    {
            ctx->lr = 0x80070708u;
            ctx->pc = 0x80286A44u;
            return;
    }

label_80070708:
    ctx->pc = 0x80070708u;
    ctx->downcount -= 7;
    // 80070708: or   r26, r3, r3
    {
        ctx->gpr[26] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8007070C:
    ctx->pc = 0x8007070Cu;
    // 8007070C: or   r27, r4, r4
    {
        ctx->gpr[27] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80070710:
    ctx->pc = 0x80070710u;
    // 80070710: or   r28, r5, r5
    {
        ctx->gpr[28] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80070714:
    ctx->pc = 0x80070714u;
    // 80070714: lwz     r29, 0(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(0);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80070718:
    ctx->pc = 0x80070718u;
    // 80070718: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8007071C:
    ctx->pc = 0x8007071Cu;
    // 8007071C: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80070720:
    ctx->pc = 0x80070720u;
    // 80070720: bl      0x80028584
    {
            ctx->lr = 0x80070724u;
            ctx->pc = 0x80028584u;
            return;
    }

label_80070724:
    ctx->pc = 0x80070724u;
    ctx->downcount -= 3;
    // 80070724: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80070728:
    ctx->pc = 0x80070728u;
    // 80070728: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8007072C:
    ctx->pc = 0x8007072Cu;
    // 8007072C: bl      0x8004C434
    {
            ctx->lr = 0x80070730u;
            ctx->pc = 0x8004C434u;
            return;
    }

label_80070730:
    ctx->pc = 0x80070730u;
    ctx->downcount -= 2;
    // 80070730: lwz     r3, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80070734:
    ctx->pc = 0x80070734u;
    // 80070734: bl      0x800538A4
    {
            ctx->lr = 0x80070738u;
            ctx->pc = 0x800538A4u;
            return;
    }

label_80070738:
    ctx->pc = 0x80070738u;
    ctx->downcount -= 2;
    // 80070738: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8007073C:
    ctx->pc = 0x8007073Cu;
    // 8007073C: bl      0x8004C4C8
    {
            ctx->lr = 0x80070740u;
            ctx->pc = 0x8004C4C8u;
            return;
    }

label_80070740:
    ctx->pc = 0x80070740u;
    ctx->downcount -= 2;
    // 80070740: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80070744:
    ctx->pc = 0x80070744u;
    // 80070744: bl      0x8006C8D4
    {
            ctx->lr = 0x80070748u;
            ctx->pc = 0x8006C8D4u;
            return;
    }

label_80070748:
    ctx->pc = 0x80070748u;
    ctx->downcount -= 2;
    // 80070748: lwz     r3, 52(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(52);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8007074C:
    ctx->pc = 0x8007074Cu;
    // 8007074C: bl      0x800538A4
    {
            ctx->lr = 0x80070750u;
            ctx->pc = 0x800538A4u;
            return;
    }

label_80070750:
    ctx->pc = 0x80070750u;
    ctx->downcount -= 13;
    // 80070750: or   r25, r3, r3
    {
        ctx->gpr[25] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80070754:
    ctx->pc = 0x80070754u;
    // 80070754: addi    r3, r25, 32
    ctx->gpr[3] = ctx->gpr[25] + (u32)(s32)(32);

label_80070758:
    ctx->pc = 0x80070758u;
    // 80070758: addi    r4, r25, 96
    ctx->gpr[4] = ctx->gpr[25] + (u32)(s32)(96);

label_8007075C:
    ctx->pc = 0x8007075Cu;
    // 8007075C: lhz     r5, 10(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(10);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_80070760:
    ctx->pc = 0x80070760u;
    // 80070760: lhz     r6, 12(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(12);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_80070764:
    ctx->pc = 0x80070764u;
    // 80070764: lbz     r7, 22(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(22);
        ctx->gpr[7] = mem_read8(ctx, ea);
    }

label_80070768:
    ctx->pc = 0x80070768u;
    // 80070768: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_8007076C:
    ctx->pc = 0x8007076Cu;
    // 8007076C: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_80070770:
    ctx->pc = 0x80070770u;
    // 80070770: lbz     r10, 28(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(28);
        ctx->gpr[10] = mem_read8(ctx, ea);
    }

label_80070774:
    ctx->pc = 0x80070774u;
    // 80070774: lbz     r0, 29(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(29);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80070778:
    ctx->pc = 0x80070778u;
    // 80070778: subf   r0, r10, r0
    {
        u32 a = ~ctx->gpr[10];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_8007077C:
    ctx->pc = 0x8007077Cu;
    // 8007077C: cmpwi   r0, 0
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

label_80070780:
    ctx->pc = 0x80070780u;
    // 80070780: bc    4, 1, 0x8007078C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8007078C;
        }
    }

label_80070784:
    ctx->pc = 0x80070784u;
    ctx->downcount -= 2;
    // 80070784: li      r10, 1
    ctx->gpr[10] = (u32)(s32)(1);

label_80070788:
    ctx->pc = 0x80070788u;
    // 80070788: b       0x80070790
    {
            goto label_80070790;
    }

label_8007078C:
    ctx->pc = 0x8007078Cu;
    ctx->downcount -= 1;
    // 8007078C: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_80070790:
    ctx->pc = 0x80070790u;
    ctx->downcount -= 1;
    // 80070790: bl      0x8025AC80
    {
            ctx->lr = 0x80070794u;
            ctx->pc = 0x8025AC80u;
            return;
    }

label_80070794:
    ctx->pc = 0x80070794u;
    ctx->downcount -= 3;
    // 80070794: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_80070798:
    ctx->pc = 0x80070798u;
    // 80070798: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_8007079C:
    ctx->pc = 0x8007079Cu;
    // 8007079C: bl      0x8004C4C8
    {
            ctx->lr = 0x800707A0u;
            ctx->pc = 0x8004C4C8u;
            return;
    }

label_800707A0:
    ctx->pc = 0x800707A0u;
    ctx->downcount -= 5;
    // 800707A0: lis     r3, -32710
    ctx->gpr[3] = ((u32)(s32)(-32710) << 16);

label_800707A4:
    ctx->pc = 0x800707A4u;
    // 800707A4: addi    r3, r3, -32336
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-32336);

label_800707A8:
    ctx->pc = 0x800707A8u;
    // 800707A8: li      r4, 82
    ctx->gpr[4] = (u32)(s32)(82);

label_800707AC:
    ctx->pc = 0x800707ACu;
    // 800707AC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800707B0:
    ctx->pc = 0x800707B0u;
    // 800707B0: bl      0x8025DAD0
    {
            ctx->lr = 0x800707B4u;
            ctx->pc = 0x8025DAD0u;
            return;
    }

label_800707B4:
    ctx->pc = 0x800707B4u;
    ctx->downcount -= 7;
    // 800707B4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800707B8:
    ctx->pc = 0x800707B8u;
    // 800707B8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800707BC:
    ctx->pc = 0x800707BCu;
    // 800707BC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800707C0:
    ctx->pc = 0x800707C0u;
    // 800707C0: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800707C4:
    ctx->pc = 0x800707C4u;
    // 800707C4: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800707C8:
    ctx->pc = 0x800707C8u;
    // 800707C8: li      r8, 82
    ctx->gpr[8] = (u32)(s32)(82);

label_800707CC:
    ctx->pc = 0x800707CCu;
    // 800707CC: bl      0x80258880
    {
            ctx->lr = 0x800707D0u;
            ctx->pc = 0x80258880u;
            return;
    }

label_800707D0:
    ctx->pc = 0x800707D0u;
    ctx->downcount -= 5;
    // 800707D0: lis     r3, -32710
    ctx->gpr[3] = ((u32)(s32)(-32710) << 16);

label_800707D4:
    ctx->pc = 0x800707D4u;
    // 800707D4: addi    r3, r3, -32384
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-32384);

label_800707D8:
    ctx->pc = 0x800707D8u;
    // 800707D8: li      r4, 85
    ctx->gpr[4] = (u32)(s32)(85);

label_800707DC:
    ctx->pc = 0x800707DCu;
    // 800707DC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800707E0:
    ctx->pc = 0x800707E0u;
    // 800707E0: bl      0x8025DAD0
    {
            ctx->lr = 0x800707E4u;
            ctx->pc = 0x8025DAD0u;
            return;
    }

label_800707E4:
    ctx->pc = 0x800707E4u;
    ctx->downcount -= 7;
    // 800707E4: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_800707E8:
    ctx->pc = 0x800707E8u;
    // 800707E8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800707EC:
    ctx->pc = 0x800707ECu;
    // 800707EC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800707F0:
    ctx->pc = 0x800707F0u;
    // 800707F0: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800707F4:
    ctx->pc = 0x800707F4u;
    // 800707F4: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800707F8:
    ctx->pc = 0x800707F8u;
    // 800707F8: li      r8, 85
    ctx->gpr[8] = (u32)(s32)(85);

label_800707FC:
    ctx->pc = 0x800707FCu;
    // 800707FC: bl      0x80258880
    {
            ctx->lr = 0x80070800u;
            ctx->pc = 0x80258880u;
            return;
    }

label_80070800:
    ctx->pc = 0x80070800u;
    ctx->downcount -= 3;
    // 80070800: addi    r3, r1, 32
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(32);

label_80070804:
    ctx->pc = 0x80070804u;
    // 80070804: addi    r4, r1, 28
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(28);

label_80070808:
    ctx->pc = 0x80070808u;
    // 80070808: bl      0x8006CCA0
    {
            ctx->lr = 0x8007080Cu;
            ctx->pc = 0x8006CCA0u;
            return;
    }

label_8007080C:
    ctx->pc = 0x8007080Cu;
    ctx->downcount -= 5;
    // 8007080C: addi    r3, r1, 36
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(36);

label_80070810:
    ctx->pc = 0x80070810u;
    // 80070810: lfs     f1, -30228(r2)
    if (!ppc_fp_available_inline(ctx, 0x80070810u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30228);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80070814:
    ctx->pc = 0x80070814u;
    // 80070814: fmr    f2, f1
    if (!ppc_fp_available_inline(ctx, 0x80070814u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_80070818:
    ctx->pc = 0x80070818u;
    // 80070818: fmr    f3, f1
    if (!ppc_fp_available_inline(ctx, 0x80070818u)) return;
    ctx->fpr[3] = ctx->fpr[1];

label_8007081C:
    ctx->pc = 0x8007081Cu;
    // 8007081C: bl      0x80247CC4
    {
            ctx->lr = 0x80070820u;
            ctx->pc = 0x80247CC4u;
            return;
    }

label_80070820:
    ctx->pc = 0x80070820u;
    ctx->downcount -= 7;
    // 80070820: lfs     f0, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x80070820u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80070824:
    ctx->pc = 0x80070824u;
    // 80070824: fneg    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x80070824u)) return;
    ctx->fpr[0] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[0]) ^ 0x8000000000000000ull);

label_80070828:
    ctx->pc = 0x80070828u;
    // 80070828: stfs     f0, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x80070828u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8007082C:
    ctx->pc = 0x8007082Cu;
    // 8007082C: addi    r3, r1, 36
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(36);

label_80070830:
    ctx->pc = 0x80070830u;
    // 80070830: li      r4, 33
    ctx->gpr[4] = (u32)(s32)(33);

label_80070834:
    ctx->pc = 0x80070834u;
    // 80070834: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80070838:
    ctx->pc = 0x80070838u;
    // 80070838: bl      0x8025DAD0
    {
            ctx->lr = 0x8007083Cu;
            ctx->pc = 0x8025DAD0u;
            return;
    }

label_8007083C:
    ctx->pc = 0x8007083Cu;
    ctx->downcount -= 7;
    // 8007083C: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80070840:
    ctx->pc = 0x80070840u;
    // 80070840: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80070844:
    ctx->pc = 0x80070844u;
    // 80070844: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_80070848:
    ctx->pc = 0x80070848u;
    // 80070848: li      r6, 33
    ctx->gpr[6] = (u32)(s32)(33);

label_8007084C:
    ctx->pc = 0x8007084Cu;
    // 8007084C: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80070850:
    ctx->pc = 0x80070850u;
    // 80070850: li      r8, 125
    ctx->gpr[8] = (u32)(s32)(125);

label_80070854:
    ctx->pc = 0x80070854u;
    // 80070854: bl      0x80258880
    {
            ctx->lr = 0x80070858u;
            ctx->pc = 0x80258880u;
            return;
    }

label_80070858:
    ctx->pc = 0x80070858u;
    ctx->downcount -= 7;
    // 80070858: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_8007085C:
    ctx->pc = 0x8007085Cu;
    // 8007085C: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80070860:
    ctx->pc = 0x80070860u;
    // 80070860: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_80070864:
    ctx->pc = 0x80070864u;
    // 80070864: li      r6, 33
    ctx->gpr[6] = (u32)(s32)(33);

label_80070868:
    ctx->pc = 0x80070868u;
    // 80070868: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8007086C:
    ctx->pc = 0x8007086Cu;
    // 8007086C: li      r8, 125
    ctx->gpr[8] = (u32)(s32)(125);

label_80070870:
    ctx->pc = 0x80070870u;
    // 80070870: bl      0x80258880
    {
            ctx->lr = 0x80070874u;
            ctx->pc = 0x80258880u;
            return;
    }

label_80070874:
    ctx->pc = 0x80070874u;
    ctx->downcount -= 1;
    // 80070874: bl      0x8004C42C
    {
            ctx->lr = 0x80070878u;
            ctx->pc = 0x8004C42Cu;
            return;
    }

label_80070878:
    ctx->pc = 0x80070878u;
    ctx->downcount -= 3;
    // 80070878: rlwinm r0, r3, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000000FFu;
    }

label_8007087C:
    ctx->pc = 0x8007087Cu;
    // 8007087C: cmplwi  r0, 0x0000
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

label_80070880:
    ctx->pc = 0x80070880u;
    // 80070880: bc    12, 2, 0x800708B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800708B0;
        }
    }

label_80070884:
    ctx->pc = 0x80070884u;
    ctx->downcount -= 11;
    // 80070884: lbz     r0, -24940(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24940);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80070888:
    ctx->pc = 0x80070888u;
    // 80070888: stb     r0, -31388(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31388);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8007088C:
    ctx->pc = 0x8007088Cu;
    // 8007088C: addi    r4, r13, -24940
    ctx->gpr[4] = ctx->gpr[13] + (u32)(s32)(-24940);

label_80070890:
    ctx->pc = 0x80070890u;
    // 80070890: lbz     r0, 1(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(1);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80070894:
    ctx->pc = 0x80070894u;
    // 80070894: addi    r3, r13, -31388
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-31388);

label_80070898:
    ctx->pc = 0x80070898u;
    // 80070898: stb     r0, 1(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8007089C:
    ctx->pc = 0x8007089Cu;
    // 8007089C: lbz     r0, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_800708A0:
    ctx->pc = 0x800708A0u;
    // 800708A0: stb     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_800708A4:
    ctx->pc = 0x800708A4u;
    // 800708A4: li      r0, 128
    ctx->gpr[0] = (u32)(s32)(128);

label_800708A8:
    ctx->pc = 0x800708A8u;
    // 800708A8: stb     r0, 3(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(3);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_800708AC:
    ctx->pc = 0x800708ACu;
    // 800708AC: b       0x80070928
    {
            goto label_80070928;
    }

label_800708B0:
    ctx->pc = 0x800708B0u;
    ctx->downcount -= 16;
    // 800708B0: addi    r3, r13, -31388
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-31388);

label_800708B4:
    ctx->pc = 0x800708B4u;
    // 800708B4: addi    r25, r13, -31388
    ctx->gpr[25] = ctx->gpr[13] + (u32)(s32)(-31388);

label_800708B8:
    ctx->pc = 0x800708B8u;
    // 800708B8: addi    r25, r25, 1
    ctx->gpr[25] = ctx->gpr[25] + (u32)(s32)(1);

label_800708BC:
    ctx->pc = 0x800708BCu;
    // 800708BC: or   r4, r25, r25
    {
        ctx->gpr[4] = ctx->gpr[25] | ctx->gpr[25];
    }

label_800708C0:
    ctx->pc = 0x800708C0u;
    // 800708C0: addi    r30, r13, -31388
    ctx->gpr[30] = ctx->gpr[13] + (u32)(s32)(-31388);

label_800708C4:
    ctx->pc = 0x800708C4u;
    // 800708C4: addi    r30, r30, 2
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(2);

label_800708C8:
    ctx->pc = 0x800708C8u;
    // 800708C8: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800708CC:
    ctx->pc = 0x800708CCu;
    // 800708CC: addi    r6, r1, 16
    ctx->gpr[6] = ctx->gpr[1] + (u32)(s32)(16);

label_800708D0:
    ctx->pc = 0x800708D0u;
    // 800708D0: or   r7, r6, r6
    {
        ctx->gpr[7] = ctx->gpr[6] | ctx->gpr[6];
    }

label_800708D4:
    ctx->pc = 0x800708D4u;
    // 800708D4: or   r8, r6, r6
    {
        ctx->gpr[8] = ctx->gpr[6] | ctx->gpr[6];
    }

label_800708D8:
    ctx->pc = 0x800708D8u;
    // 800708D8: lwz     r9, -26408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26408);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800708DC:
    ctx->pc = 0x800708DCu;
    // 800708DC: lwz     r9, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800708E0:
    ctx->pc = 0x800708E0u;
    // 800708E0: lwz     r12, 64(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(64);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_800708E4:
    ctx->pc = 0x800708E4u;
    // 800708E4: mtctr    r12
    ctx->ctr = ctx->gpr[12];

label_800708E8:
    ctx->pc = 0x800708E8u;
    // 800708E8: bctrl
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x800708ECu;
            ctx->pc = target;
            return;
        }
    }

label_800708EC:
    ctx->pc = 0x800708ECu;
    ctx->downcount -= 15;
    // 800708EC: lbz     r0, -31388(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31388);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_800708F0:
    ctx->pc = 0x800708F0u;
    // 800708F0: srawi r0, r0, 3
    {
        u32 sh = 3u;
        u32 value = ctx->gpr[0];
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

label_800708F4:
    ctx->pc = 0x800708F4u;
    // 800708F4: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_800708F8:
    ctx->pc = 0x800708F8u;
    // 800708F8: stb     r0, -31388(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31388);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_800708FC:
    ctx->pc = 0x800708FCu;
    // 800708FC: lbz     r0, 0(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80070900:
    ctx->pc = 0x80070900u;
    // 80070900: srawi r0, r0, 3
    {
        u32 sh = 3u;
        u32 value = ctx->gpr[0];
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

label_80070904:
    ctx->pc = 0x80070904u;
    // 80070904: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_80070908:
    ctx->pc = 0x80070908u;
    // 80070908: stb     r0, 0(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8007090C:
    ctx->pc = 0x8007090Cu;
    // 8007090C: lbz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80070910:
    ctx->pc = 0x80070910u;
    // 80070910: srawi r0, r0, 3
    {
        u32 sh = 3u;
        u32 value = ctx->gpr[0];
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

label_80070914:
    ctx->pc = 0x80070914u;
    // 80070914: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_80070918:
    ctx->pc = 0x80070918u;
    // 80070918: stb     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8007091C:
    ctx->pc = 0x8007091Cu;
    // 8007091C: lbz     r0, -31512(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31512);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80070920:
    ctx->pc = 0x80070920u;
    // 80070920: addi    r3, r13, -31388
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-31388);

label_80070924:
    ctx->pc = 0x80070924u;
    // 80070924: stb     r0, 3(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(3);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80070928:
    ctx->pc = 0x80070928u;
    ctx->downcount -= 5;
    // 80070928: lwz     r0, -31388(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31388);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8007092C:
    ctx->pc = 0x8007092Cu;
    // 8007092C: stw     r0, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80070930:
    ctx->pc = 0x80070930u;
    // 80070930: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_80070934:
    ctx->pc = 0x80070934u;
    // 80070934: addi    r4, r1, 24
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(24);

label_80070938:
    ctx->pc = 0x80070938u;
    // 80070938: bl      0x8025C634
    {
            ctx->lr = 0x8007093Cu;
            ctx->pc = 0x8025C634u;
            return;
    }

label_8007093C:
    ctx->pc = 0x8007093Cu;
    ctx->downcount -= 5;
    // 8007093C: lwz     r0, -31384(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31384);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80070940:
    ctx->pc = 0x80070940u;
    // 80070940: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80070944:
    ctx->pc = 0x80070944u;
    // 80070944: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80070948:
    ctx->pc = 0x80070948u;
    // 80070948: addi    r4, r1, 20
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(20);

label_8007094C:
    ctx->pc = 0x8007094Cu;
    // 8007094C: bl      0x8025C71C
    {
            ctx->lr = 0x80070950u;
            ctx->pc = 0x8025C71Cu;
            return;
    }

label_80070950:
    ctx->pc = 0x80070950u;
    ctx->downcount -= 3;
    // 80070950: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80070954:
    ctx->pc = 0x80070954u;
    // 80070954: li      r4, 12
    ctx->gpr[4] = (u32)(s32)(12);

label_80070958:
    ctx->pc = 0x80070958u;
    // 80070958: bl      0x8025C790
    {
            ctx->lr = 0x8007095Cu;
            ctx->pc = 0x8025C790u;
            return;
    }

label_8007095C:
    ctx->pc = 0x8007095Cu;
    ctx->downcount -= 4;
    // 8007095C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80070960:
    ctx->pc = 0x80070960u;
    // 80070960: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80070964:
    ctx->pc = 0x80070964u;
    // 80070964: li      r5, 2
    ctx->gpr[5] = (u32)(s32)(2);

label_80070968:
    ctx->pc = 0x80070968u;
    // 80070968: bl      0x8025BF28
    {
            ctx->lr = 0x8007096Cu;
            ctx->pc = 0x8025BF28u;
            return;
    }

label_8007096C:
    ctx->pc = 0x8007096Cu;
    ctx->downcount -= 4;
    // 8007096C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80070970:
    ctx->pc = 0x80070970u;
    // 80070970: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80070974:
    ctx->pc = 0x80070974u;
    // 80070974: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80070978:
    ctx->pc = 0x80070978u;
    // 80070978: bl      0x8025BD54
    {
            ctx->lr = 0x8007097Cu;
            ctx->pc = 0x8025BD54u;
            return;
    }

label_8007097C:
    ctx->pc = 0x8007097Cu;
    ctx->downcount -= 5;
    // 8007097C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80070980:
    ctx->pc = 0x80070980u;
    // 80070980: lis     r4, -32719
    ctx->gpr[4] = ((u32)(s32)(-32719) << 16);

label_80070984:
    ctx->pc = 0x80070984u;
    // 80070984: addi    r4, r4, 640
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(640);

label_80070988:
    ctx->pc = 0x80070988u;
    // 80070988: li      r5, -1
    ctx->gpr[5] = (u32)(s32)(-1);

label_8007098C:
    ctx->pc = 0x8007098Cu;
    // 8007098C: bl      0x8025BBF4
    {
            ctx->lr = 0x80070990u;
            ctx->pc = 0x8025BBF4u;
            return;
    }

label_80070990:
    ctx->pc = 0x80070990u;
    ctx->downcount -= 5;
    // 80070990: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80070994:
    ctx->pc = 0x80070994u;
    // 80070994: lis     r4, -32719
    ctx->gpr[4] = ((u32)(s32)(-32719) << 16);

label_80070998:
    ctx->pc = 0x80070998u;
    // 80070998: addi    r4, r4, 640
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(640);

label_8007099C:
    ctx->pc = 0x8007099Cu;
    // 8007099C: li      r5, -2
    ctx->gpr[5] = (u32)(s32)(-2);

label_800709A0:
    ctx->pc = 0x800709A0u;
    // 800709A0: bl      0x8025BBF4
    {
            ctx->lr = 0x800709A4u;
            ctx->pc = 0x8025BBF4u;
            return;
    }

label_800709A4:
    ctx->pc = 0x800709A4u;
    ctx->downcount -= 12;
    // 800709A4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800709A8:
    ctx->pc = 0x800709A8u;
    // 800709A8: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800709AC:
    ctx->pc = 0x800709ACu;
    // 800709AC: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800709B0:
    ctx->pc = 0x800709B0u;
    // 800709B0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800709B4:
    ctx->pc = 0x800709B4u;
    // 800709B4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800709B8:
    ctx->pc = 0x800709B8u;
    // 800709B8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800709BC:
    ctx->pc = 0x800709BCu;
    // 800709BC: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_800709C0:
    ctx->pc = 0x800709C0u;
    // 800709C0: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_800709C4:
    ctx->pc = 0x800709C4u;
    // 800709C4: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800709C8:
    ctx->pc = 0x800709C8u;
    // 800709C8: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800709CC:
    ctx->pc = 0x800709CCu;
    // 800709CC: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_800709D0:
    ctx->pc = 0x800709D0u;
    // 800709D0: bl      0x8025BB58
    {
            ctx->lr = 0x800709D4u;
            ctx->pc = 0x8025BB58u;
            return;
    }

label_800709D4:
    ctx->pc = 0x800709D4u;
    ctx->downcount -= 12;
    // 800709D4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800709D8:
    ctx->pc = 0x800709D8u;
    // 800709D8: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800709DC:
    ctx->pc = 0x800709DCu;
    // 800709DC: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800709E0:
    ctx->pc = 0x800709E0u;
    // 800709E0: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_800709E4:
    ctx->pc = 0x800709E4u;
    // 800709E4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800709E8:
    ctx->pc = 0x800709E8u;
    // 800709E8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800709EC:
    ctx->pc = 0x800709ECu;
    // 800709EC: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_800709F0:
    ctx->pc = 0x800709F0u;
    // 800709F0: li      r7, 2
    ctx->gpr[7] = (u32)(s32)(2);

label_800709F4:
    ctx->pc = 0x800709F4u;
    // 800709F4: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800709F8:
    ctx->pc = 0x800709F8u;
    // 800709F8: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800709FC:
    ctx->pc = 0x800709FCu;
    // 800709FC: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_80070A00:
    ctx->pc = 0x80070A00u;
    // 80070A00: bl      0x8025BB58
    {
            ctx->lr = 0x80070A04u;
            ctx->pc = 0x8025BB58u;
            return;
    }

label_80070A04:
    ctx->pc = 0x80070A04u;
    ctx->downcount -= 5;
    // 80070A04: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80070A08:
    ctx->pc = 0x80070A08u;
    // 80070A08: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80070A0C:
    ctx->pc = 0x80070A0Cu;
    // 80070A0C: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80070A10:
    ctx->pc = 0x80070A10u;
    // 80070A10: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_80070A14:
    ctx->pc = 0x80070A14u;
    // 80070A14: bl      0x8025CA34
    {
            ctx->lr = 0x80070A18u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_80070A18:
    ctx->pc = 0x80070A18u;
    ctx->downcount -= 6;
    // 80070A18: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80070A1C:
    ctx->pc = 0x80070A1Cu;
    // 80070A1C: li      r4, 6
    ctx->gpr[4] = (u32)(s32)(6);

label_80070A20:
    ctx->pc = 0x80070A20u;
    // 80070A20: li      r5, 15
    ctx->gpr[5] = (u32)(s32)(15);

label_80070A24:
    ctx->pc = 0x80070A24u;
    // 80070A24: li      r6, 15
    ctx->gpr[6] = (u32)(s32)(15);

label_80070A28:
    ctx->pc = 0x80070A28u;
    // 80070A28: li      r7, 8
    ctx->gpr[7] = (u32)(s32)(8);

label_80070A2C:
    ctx->pc = 0x80070A2Cu;
    // 80070A2C: bl      0x8025C3B0
    {
            ctx->lr = 0x80070A30u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_80070A30:
    ctx->pc = 0x80070A30u;
    ctx->downcount -= 6;
    // 80070A30: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80070A34:
    ctx->pc = 0x80070A34u;
    // 80070A34: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_80070A38:
    ctx->pc = 0x80070A38u;
    // 80070A38: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_80070A3C:
    ctx->pc = 0x80070A3Cu;
    // 80070A3C: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_80070A40:
    ctx->pc = 0x80070A40u;
    // 80070A40: li      r7, 7
    ctx->gpr[7] = (u32)(s32)(7);

label_80070A44:
    ctx->pc = 0x80070A44u;
    // 80070A44: bl      0x8025C430
    {
            ctx->lr = 0x80070A48u;
            ctx->pc = 0x8025C430u;
            return;
    }

label_80070A48:
    ctx->pc = 0x80070A48u;
    ctx->downcount -= 4;
    // 80070A48: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80070A4C:
    ctx->pc = 0x80070A4Cu;
    // 80070A4C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80070A50:
    ctx->pc = 0x80070A50u;
    // 80070A50: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80070A54:
    ctx->pc = 0x80070A54u;
    // 80070A54: bl      0x8025C868
    {
            ctx->lr = 0x80070A58u;
            ctx->pc = 0x8025C868u;
            return;
    }

label_80070A58:
    ctx->pc = 0x80070A58u;
    ctx->downcount -= 1;
    // 80070A58: bl      0x8004C42C
    {
            ctx->lr = 0x80070A5Cu;
            ctx->pc = 0x8004C42Cu;
            return;
    }

label_80070A5C:
    ctx->pc = 0x80070A5Cu;
    ctx->downcount -= 3;
    // 80070A5C: rlwinm r0, r3, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000000FFu;
    }

label_80070A60:
    ctx->pc = 0x80070A60u;
    // 80070A60: cmplwi  r0, 0x0000
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

label_80070A64:
    ctx->pc = 0x80070A64u;
    // 80070A64: bc    12, 2, 0x80070A88
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80070A88;
        }
    }

label_80070A68:
    ctx->pc = 0x80070A68u;
    ctx->downcount -= 7;
    // 80070A68: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80070A6C:
    ctx->pc = 0x80070A6Cu;
    // 80070A6C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80070A70:
    ctx->pc = 0x80070A70u;
    // 80070A70: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80070A74:
    ctx->pc = 0x80070A74u;
    // 80070A74: li      r6, 3
    ctx->gpr[6] = (u32)(s32)(3);

label_80070A78:
    ctx->pc = 0x80070A78u;
    // 80070A78: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_80070A7C:
    ctx->pc = 0x80070A7Cu;
    // 80070A7C: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80070A80:
    ctx->pc = 0x80070A80u;
    // 80070A80: bl      0x8025C4B4
    {
            ctx->lr = 0x80070A84u;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_80070A84:
    ctx->pc = 0x80070A84u;
    ctx->downcount -= 1;
    // 80070A84: b       0x80070AA4
    {
            goto label_80070AA4;
    }

label_80070A88:
    ctx->pc = 0x80070A88u;
    ctx->downcount -= 7;
    // 80070A88: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80070A8C:
    ctx->pc = 0x80070A8Cu;
    // 80070A8C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80070A90:
    ctx->pc = 0x80070A90u;
    // 80070A90: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80070A94:
    ctx->pc = 0x80070A94u;
    // 80070A94: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80070A98:
    ctx->pc = 0x80070A98u;
    // 80070A98: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_80070A9C:
    ctx->pc = 0x80070A9Cu;
    // 80070A9C: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80070AA0:
    ctx->pc = 0x80070AA0u;
    // 80070AA0: bl      0x8025C4B4
    {
            ctx->lr = 0x80070AA4u;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_80070AA4:
    ctx->pc = 0x80070AA4u;
    ctx->downcount -= 7;
    // 80070AA4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80070AA8:
    ctx->pc = 0x80070AA8u;
    // 80070AA8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80070AAC:
    ctx->pc = 0x80070AACu;
    // 80070AAC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80070AB0:
    ctx->pc = 0x80070AB0u;
    // 80070AB0: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80070AB4:
    ctx->pc = 0x80070AB4u;
    // 80070AB4: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_80070AB8:
    ctx->pc = 0x80070AB8u;
    // 80070AB8: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80070ABC:
    ctx->pc = 0x80070ABCu;
    // 80070ABC: bl      0x8025C574
    {
            ctx->lr = 0x80070AC0u;
            ctx->pc = 0x8025C574u;
            return;
    }

label_80070AC0:
    ctx->pc = 0x80070AC0u;
    ctx->downcount -= 5;
    // 80070AC0: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80070AC4:
    ctx->pc = 0x80070AC4u;
    // 80070AC4: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80070AC8:
    ctx->pc = 0x80070AC8u;
    // 80070AC8: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80070ACC:
    ctx->pc = 0x80070ACCu;
    // 80070ACC: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_80070AD0:
    ctx->pc = 0x80070AD0u;
    // 80070AD0: bl      0x8025CA34
    {
            ctx->lr = 0x80070AD4u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_80070AD4:
    ctx->pc = 0x80070AD4u;
    ctx->downcount -= 6;
    // 80070AD4: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80070AD8:
    ctx->pc = 0x80070AD8u;
    // 80070AD8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80070ADC:
    ctx->pc = 0x80070ADCu;
    // 80070ADC: li      r5, 8
    ctx->gpr[5] = (u32)(s32)(8);

label_80070AE0:
    ctx->pc = 0x80070AE0u;
    // 80070AE0: li      r6, 14
    ctx->gpr[6] = (u32)(s32)(14);

label_80070AE4:
    ctx->pc = 0x80070AE4u;
    // 80070AE4: li      r7, 15
    ctx->gpr[7] = (u32)(s32)(15);

label_80070AE8:
    ctx->pc = 0x80070AE8u;
    // 80070AE8: bl      0x8025C3B0
    {
            ctx->lr = 0x80070AECu;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_80070AEC:
    ctx->pc = 0x80070AECu;
    ctx->downcount -= 6;
    // 80070AEC: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80070AF0:
    ctx->pc = 0x80070AF0u;
    // 80070AF0: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_80070AF4:
    ctx->pc = 0x80070AF4u;
    // 80070AF4: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_80070AF8:
    ctx->pc = 0x80070AF8u;
    // 80070AF8: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_80070AFC:
    ctx->pc = 0x80070AFCu;
    // 80070AFC: li      r7, 7
    ctx->gpr[7] = (u32)(s32)(7);

label_80070B00:
    ctx->pc = 0x80070B00u;
    // 80070B00: bl      0x8025C430
    {
            ctx->lr = 0x80070B04u;
            ctx->pc = 0x8025C430u;
            return;
    }

label_80070B04:
    ctx->pc = 0x80070B04u;
    ctx->downcount -= 4;
    // 80070B04: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80070B08:
    ctx->pc = 0x80070B08u;
    // 80070B08: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80070B0C:
    ctx->pc = 0x80070B0Cu;
    // 80070B0C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80070B10:
    ctx->pc = 0x80070B10u;
    // 80070B10: bl      0x8025C868
    {
            ctx->lr = 0x80070B14u;
            ctx->pc = 0x8025C868u;
            return;
    }

label_80070B14:
    ctx->pc = 0x80070B14u;
    ctx->downcount -= 7;
    // 80070B14: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80070B18:
    ctx->pc = 0x80070B18u;
    // 80070B18: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80070B1C:
    ctx->pc = 0x80070B1Cu;
    // 80070B1C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80070B20:
    ctx->pc = 0x80070B20u;
    // 80070B20: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80070B24:
    ctx->pc = 0x80070B24u;
    // 80070B24: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_80070B28:
    ctx->pc = 0x80070B28u;
    // 80070B28: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80070B2C:
    ctx->pc = 0x80070B2Cu;
    // 80070B2C: bl      0x8025C4B4
    {
            ctx->lr = 0x80070B30u;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_80070B30:
    ctx->pc = 0x80070B30u;
    ctx->downcount -= 7;
    // 80070B30: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80070B34:
    ctx->pc = 0x80070B34u;
    // 80070B34: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80070B38:
    ctx->pc = 0x80070B38u;
    // 80070B38: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80070B3C:
    ctx->pc = 0x80070B3Cu;
    // 80070B3C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80070B40:
    ctx->pc = 0x80070B40u;
    // 80070B40: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_80070B44:
    ctx->pc = 0x80070B44u;
    // 80070B44: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80070B48:
    ctx->pc = 0x80070B48u;
    // 80070B48: bl      0x8025C574
    {
            ctx->lr = 0x80070B4Cu;
            ctx->pc = 0x8025C574u;
            return;
    }

label_80070B4C:
    ctx->pc = 0x80070B4Cu;
    ctx->downcount -= 2;
    // 80070B4C: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80070B50:
    ctx->pc = 0x80070B50u;
    // 80070B50: bl      0x8025C08C
    {
            ctx->lr = 0x80070B54u;
            ctx->pc = 0x8025C08Cu;
            return;
    }

label_80070B54:
    ctx->pc = 0x80070B54u;
    ctx->downcount -= 5;
    // 80070B54: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80070B58:
    ctx->pc = 0x80070B58u;
    // 80070B58: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_80070B5C:
    ctx->pc = 0x80070B5Cu;
    // 80070B5C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80070B60:
    ctx->pc = 0x80070B60u;
    // 80070B60: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_80070B64:
    ctx->pc = 0x80070B64u;
    // 80070B64: bl      0x8025CA34
    {
            ctx->lr = 0x80070B68u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_80070B68:
    ctx->pc = 0x80070B68u;
    ctx->downcount -= 6;
    // 80070B68: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80070B6C:
    ctx->pc = 0x80070B6Cu;
    // 80070B6C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80070B70:
    ctx->pc = 0x80070B70u;
    // 80070B70: li      r5, 8
    ctx->gpr[5] = (u32)(s32)(8);

label_80070B74:
    ctx->pc = 0x80070B74u;
    // 80070B74: li      r6, 9
    ctx->gpr[6] = (u32)(s32)(9);

label_80070B78:
    ctx->pc = 0x80070B78u;
    // 80070B78: li      r7, 15
    ctx->gpr[7] = (u32)(s32)(15);

label_80070B7C:
    ctx->pc = 0x80070B7Cu;
    // 80070B7C: bl      0x8025C3B0
    {
            ctx->lr = 0x80070B80u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_80070B80:
    ctx->pc = 0x80070B80u;
    ctx->downcount -= 6;
    // 80070B80: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80070B84:
    ctx->pc = 0x80070B84u;
    // 80070B84: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_80070B88:
    ctx->pc = 0x80070B88u;
    // 80070B88: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_80070B8C:
    ctx->pc = 0x80070B8Cu;
    // 80070B8C: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_80070B90:
    ctx->pc = 0x80070B90u;
    // 80070B90: li      r7, 5
    ctx->gpr[7] = (u32)(s32)(5);

label_80070B94:
    ctx->pc = 0x80070B94u;
    // 80070B94: bl      0x8025C430
    {
            ctx->lr = 0x80070B98u;
            ctx->pc = 0x8025C430u;
            return;
    }

label_80070B98:
    ctx->pc = 0x80070B98u;
    ctx->downcount -= 4;
    // 80070B98: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80070B9C:
    ctx->pc = 0x80070B9Cu;
    // 80070B9C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80070BA0:
    ctx->pc = 0x80070BA0u;
    // 80070BA0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80070BA4:
    ctx->pc = 0x80070BA4u;
    // 80070BA4: bl      0x8025C868
    {
            ctx->lr = 0x80070BA8u;
            ctx->pc = 0x8025C868u;
            return;
    }

label_80070BA8:
    ctx->pc = 0x80070BA8u;
    ctx->downcount -= 7;
    // 80070BA8: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80070BAC:
    ctx->pc = 0x80070BACu;
    // 80070BAC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80070BB0:
    ctx->pc = 0x80070BB0u;
    // 80070BB0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80070BB4:
    ctx->pc = 0x80070BB4u;
    // 80070BB4: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80070BB8:
    ctx->pc = 0x80070BB8u;
    // 80070BB8: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_80070BBC:
    ctx->pc = 0x80070BBCu;
    // 80070BBC: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80070BC0:
    ctx->pc = 0x80070BC0u;
    // 80070BC0: bl      0x8025C4B4
    {
            ctx->lr = 0x80070BC4u;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_80070BC4:
    ctx->pc = 0x80070BC4u;
    ctx->downcount -= 7;
    // 80070BC4: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80070BC8:
    ctx->pc = 0x80070BC8u;
    // 80070BC8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80070BCC:
    ctx->pc = 0x80070BCCu;
    // 80070BCC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80070BD0:
    ctx->pc = 0x80070BD0u;
    // 80070BD0: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80070BD4:
    ctx->pc = 0x80070BD4u;
    // 80070BD4: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_80070BD8:
    ctx->pc = 0x80070BD8u;
    // 80070BD8: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80070BDC:
    ctx->pc = 0x80070BDCu;
    // 80070BDC: bl      0x8025C574
    {
            ctx->lr = 0x80070BE0u;
            ctx->pc = 0x8025C574u;
            return;
    }

label_80070BE0:
    ctx->pc = 0x80070BE0u;
    ctx->downcount -= 8;
    // 80070BE0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80070BE4:
    ctx->pc = 0x80070BE4u;
    // 80070BE4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80070BE8:
    ctx->pc = 0x80070BE8u;
    // 80070BE8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80070BEC:
    ctx->pc = 0x80070BECu;
    // 80070BEC: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_80070BF0:
    ctx->pc = 0x80070BF0u;
    // 80070BF0: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80070BF4:
    ctx->pc = 0x80070BF4u;
    // 80070BF4: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80070BF8:
    ctx->pc = 0x80070BF8u;
    // 80070BF8: li      r9, 2
    ctx->gpr[9] = (u32)(s32)(2);

label_80070BFC:
    ctx->pc = 0x80070BFCu;
    // 80070BFC: bl      0x8025A814
    {
            ctx->lr = 0x80070C00u;
            ctx->pc = 0x8025A814u;
            return;
    }

label_80070C00:
    ctx->pc = 0x80070C00u;
    ctx->downcount -= 8;
    // 80070C00: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80070C04:
    ctx->pc = 0x80070C04u;
    // 80070C04: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80070C08:
    ctx->pc = 0x80070C08u;
    // 80070C08: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80070C0C:
    ctx->pc = 0x80070C0Cu;
    // 80070C0C: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_80070C10:
    ctx->pc = 0x80070C10u;
    // 80070C10: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80070C14:
    ctx->pc = 0x80070C14u;
    // 80070C14: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80070C18:
    ctx->pc = 0x80070C18u;
    // 80070C18: li      r9, 2
    ctx->gpr[9] = (u32)(s32)(2);

label_80070C1C:
    ctx->pc = 0x80070C1Cu;
    // 80070C1C: bl      0x8025A814
    {
            ctx->lr = 0x80070C20u;
            ctx->pc = 0x8025A814u;
            return;
    }

label_80070C20:
    ctx->pc = 0x80070C20u;
    ctx->downcount -= 2;
    // 80070C20: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80070C24:
    ctx->pc = 0x80070C24u;
    // 80070C24: bl      0x8025C060
    {
            ctx->lr = 0x80070C28u;
            ctx->pc = 0x8025C060u;
            return;
    }

label_80070C28:
    ctx->pc = 0x80070C28u;
    ctx->downcount -= 2;
    // 80070C28: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80070C2C:
    ctx->pc = 0x80070C2Cu;
    // 80070C2C: bl      0x8025A7C8
    {
            ctx->lr = 0x80070C30u;
            ctx->pc = 0x8025A7C8u;
            return;
    }

label_80070C30:
    ctx->pc = 0x80070C30u;
    ctx->downcount -= 2;
    // 80070C30: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_80070C34:
    ctx->pc = 0x80070C34u;
    // 80070C34: bl      0x80258B50
    {
            ctx->lr = 0x80070C38u;
            ctx->pc = 0x80258B50u;
            return;
    }

label_80070C38:
    ctx->pc = 0x80070C38u;
    ctx->downcount -= 2;
    // 80070C38: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_80070C3C:
    ctx->pc = 0x80070C3Cu;
    // 80070C3C: bl      0x8025CC10
    {
            ctx->lr = 0x80070C40u;
            ctx->pc = 0x8025CC10u;
            return;
    }

label_80070C40:
    ctx->pc = 0x80070C40u;
    ctx->downcount -= 2;
    // 80070C40: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80070C44:
    ctx->pc = 0x80070C44u;
    // 80070C44: bl      0x80028624
    {
            ctx->lr = 0x80070C48u;
            ctx->pc = 0x80028624u;
            return;
    }

label_80070C48:
    ctx->pc = 0x80070C48u;
    ctx->downcount -= 3;
    // 80070C48: or   r12, r3, r3
    {
        ctx->gpr[12] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80070C4C:
    ctx->pc = 0x80070C4Cu;
    // 80070C4C: cmplwi  r12, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[12]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80070C50:
    ctx->pc = 0x80070C50u;
    // 80070C50: bc    12, 2, 0x80070C6C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80070C6C;
        }
    }

label_80070C54:
    ctx->pc = 0x80070C54u;
    ctx->downcount -= 6;
    // 80070C54: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80070C58:
    ctx->pc = 0x80070C58u;
    // 80070C58: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80070C5C:
    ctx->pc = 0x80070C5Cu;
    // 80070C5C: or   r5, r28, r28
    {
        ctx->gpr[5] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80070C60:
    ctx->pc = 0x80070C60u;
    // 80070C60: mtctr    r12
    ctx->ctr = ctx->gpr[12];

label_80070C64:
    ctx->pc = 0x80070C64u;
    // 80070C64: bctrl
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80070C68u;
            ctx->pc = target;
            return;
        }
    }

label_80070C68:
    ctx->pc = 0x80070C68u;
    ctx->downcount -= 1;
    // 80070C68: b       0x80071078
    {
            goto label_80071078;
    }

label_80070C6C:
    ctx->pc = 0x80070C6Cu;
    ctx->downcount -= 4;
    // 80070C6C: li      r30, 1
    ctx->gpr[30] = (u32)(s32)(1);

label_80070C70:
    ctx->pc = 0x80070C70u;
    // 80070C70: lbz     r0, 55(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(55);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80070C74:
    ctx->pc = 0x80070C74u;
    // 80070C74: cmplwi  r0, 0x00FF
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

label_80070C78:
    ctx->pc = 0x80070C78u;
    // 80070C78: bc    12, 0, 0x80070C98
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80070C98;
        }
    }

label_80070C7C:
    ctx->pc = 0x80070C7Cu;
    ctx->downcount -= 4;
    // 80070C7C: lwz     r3, 60(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(60);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80070C80:
    ctx->pc = 0x80070C80u;
    // 80070C80: rlwinm r0, r3, 0, 1, 1
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x40000000u;
    }

label_80070C84:
    ctx->pc = 0x80070C84u;
    // 80070C84: cmplwi  r0, 0x0000
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

label_80070C88:
    ctx->pc = 0x80070C88u;
    // 80070C88: bc    4, 2, 0x80070C98
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070C98;
        }
    }

label_80070C8C:
    ctx->pc = 0x80070C8Cu;
    ctx->downcount -= 3;
    // 80070C8C: lbz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80070C90:
    ctx->pc = 0x80070C90u;
    // 80070C90: cmplwi  r0, 0x00FF
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

label_80070C94:
    ctx->pc = 0x80070C94u;
    // 80070C94: bc    4, 0, 0x80070E3C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070E3C;
        }
    }

label_80070C98:
    ctx->pc = 0x80070C98u;
    ctx->downcount -= 5;
    // 80070C98: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80070C9C:
    ctx->pc = 0x80070C9Cu;
    // 80070C9C: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_80070CA0:
    ctx->pc = 0x80070CA0u;
    // 80070CA0: li      r5, 5
    ctx->gpr[5] = (u32)(s32)(5);

label_80070CA4:
    ctx->pc = 0x80070CA4u;
    // 80070CA4: li      r6, 5
    ctx->gpr[6] = (u32)(s32)(5);

label_80070CA8:
    ctx->pc = 0x80070CA8u;
    // 80070CA8: bl      0x8025CEF4
    {
            ctx->lr = 0x80070CACu;
            ctx->pc = 0x8025CEF4u;
            return;
    }

label_80070CAC:
    ctx->pc = 0x80070CACu;
    ctx->downcount -= 4;
    // 80070CAC: lhz     r3, 2(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(2);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_80070CB0:
    ctx->pc = 0x80070CB0u;
    // 80070CB0: rlwinm r0, r3, 0, 21, 21
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00000400u;
    }

label_80070CB4:
    ctx->pc = 0x80070CB4u;
    // 80070CB4: cmpwi   r0, 0
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

label_80070CB8:
    ctx->pc = 0x80070CB8u;
    // 80070CB8: bc    12, 2, 0x80070D34
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80070D34;
        }
    }

label_80070CBC:
    ctx->pc = 0x80070CBCu;
    ctx->downcount -= 3;
    // 80070CBC: lbz     r0, -24944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24944);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80070CC0:
    ctx->pc = 0x80070CC0u;
    // 80070CC0: cmplwi  r0, 0x0000
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

label_80070CC4:
    ctx->pc = 0x80070CC4u;
    // 80070CC4: bc    4, 2, 0x80070CEC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070CEC;
        }
    }

label_80070CC8:
    ctx->pc = 0x80070CC8u;
    ctx->downcount -= 3;
    // 80070CC8: lwz     r0, -24948(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24948);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80070CCC:
    ctx->pc = 0x80070CCCu;
    // 80070CCC: cmpwi   r0, 3
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80070CD0:
    ctx->pc = 0x80070CD0u;
    // 80070CD0: bc    4, 2, 0x80070CEC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070CEC;
        }
    }

label_80070CD4:
    ctx->pc = 0x80070CD4u;
    ctx->downcount -= 3;
    // 80070CD4: lbz     r0, -24950(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24950);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80070CD8:
    ctx->pc = 0x80070CD8u;
    // 80070CD8: cmplwi  r0, 0x0000
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

label_80070CDC:
    ctx->pc = 0x80070CDCu;
    // 80070CDC: bc    4, 2, 0x80070CEC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070CEC;
        }
    }

label_80070CE0:
    ctx->pc = 0x80070CE0u;
    ctx->downcount -= 3;
    // 80070CE0: lbz     r0, -24942(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24942);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80070CE4:
    ctx->pc = 0x80070CE4u;
    // 80070CE4: cmplwi  r0, 0x0000
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

label_80070CE8:
    ctx->pc = 0x80070CE8u;
    // 80070CE8: bc    4, 2, 0x80070D18
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070D18;
        }
    }

label_80070CEC:
    ctx->pc = 0x80070CECu;
    ctx->downcount -= 4;
    // 80070CEC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80070CF0:
    ctx->pc = 0x80070CF0u;
    // 80070CF0: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_80070CF4:
    ctx->pc = 0x80070CF4u;
    // 80070CF4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80070CF8:
    ctx->pc = 0x80070CF8u;
    // 80070CF8: bl      0x8025D078
    {
            ctx->lr = 0x80070CFCu;
            ctx->pc = 0x8025D078u;
            return;
    }

label_80070CFC:
    ctx->pc = 0x80070CFCu;
    ctx->downcount -= 7;
    // 80070CFC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80070D00:
    ctx->pc = 0x80070D00u;
    // 80070D00: stb     r3, -24944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24944);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_80070D04:
    ctx->pc = 0x80070D04u;
    // 80070D04: li      r0, 3
    ctx->gpr[0] = (u32)(s32)(3);

label_80070D08:
    ctx->pc = 0x80070D08u;
    // 80070D08: stw     r0, -24948(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24948);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80070D0C:
    ctx->pc = 0x80070D0Cu;
    // 80070D0C: stb     r3, -24950(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24950);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_80070D10:
    ctx->pc = 0x80070D10u;
    // 80070D10: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80070D14:
    ctx->pc = 0x80070D14u;
    // 80070D14: stb     r0, -24942(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24942);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80070D18:
    ctx->pc = 0x80070D18u;
    ctx->downcount -= 6;
    // 80070D18: li      r3, 7
    ctx->gpr[3] = (u32)(s32)(7);

label_80070D1C:
    ctx->pc = 0x80070D1Cu;
    // 80070D1C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80070D20:
    ctx->pc = 0x80070D20u;
    // 80070D20: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80070D24:
    ctx->pc = 0x80070D24u;
    // 80070D24: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_80070D28:
    ctx->pc = 0x80070D28u;
    // 80070D28: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80070D2C:
    ctx->pc = 0x80070D2Cu;
    // 80070D2C: bl      0x8025C960
    {
            ctx->lr = 0x80070D30u;
            ctx->pc = 0x8025C960u;
            return;
    }

label_80070D30:
    ctx->pc = 0x80070D30u;
    ctx->downcount -= 1;
    // 80070D30: b       0x80071034
    {
            goto label_80071034;
    }

label_80070D34:
    ctx->pc = 0x80070D34u;
    ctx->downcount -= 3;
    // 80070D34: rlwinm r0, r3, 0, 18, 18
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00002000u;
    }

label_80070D38:
    ctx->pc = 0x80070D38u;
    // 80070D38: cmpwi   r0, 0
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

label_80070D3C:
    ctx->pc = 0x80070D3Cu;
    // 80070D3C: bc    12, 2, 0x80070DC4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80070DC4;
        }
    }

label_80070D40:
    ctx->pc = 0x80070D40u;
    ctx->downcount -= 4;
    // 80070D40: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_80070D44:
    ctx->pc = 0x80070D44u;
    // 80070D44: lbz     r0, -24944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24944);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80070D48:
    ctx->pc = 0x80070D48u;
    // 80070D48: cmplwi  r0, 0x0001
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0001u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80070D4C:
    ctx->pc = 0x80070D4Cu;
    // 80070D4C: bc    4, 2, 0x80070D74
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070D74;
        }
    }

label_80070D50:
    ctx->pc = 0x80070D50u;
    ctx->downcount -= 3;
    // 80070D50: lwz     r0, -24948(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24948);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80070D54:
    ctx->pc = 0x80070D54u;
    // 80070D54: cmpwi   r0, 3
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80070D58:
    ctx->pc = 0x80070D58u;
    // 80070D58: bc    4, 2, 0x80070D74
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070D74;
        }
    }

label_80070D5C:
    ctx->pc = 0x80070D5Cu;
    ctx->downcount -= 3;
    // 80070D5C: lbz     r0, -24950(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24950);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80070D60:
    ctx->pc = 0x80070D60u;
    // 80070D60: cmplwi  r0, 0x0001
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0001u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80070D64:
    ctx->pc = 0x80070D64u;
    // 80070D64: bc    4, 2, 0x80070D74
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070D74;
        }
    }

label_80070D68:
    ctx->pc = 0x80070D68u;
    ctx->downcount -= 3;
    // 80070D68: lbz     r0, -24942(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24942);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80070D6C:
    ctx->pc = 0x80070D6Cu;
    // 80070D6C: cmplwi  r0, 0x0000
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

label_80070D70:
    ctx->pc = 0x80070D70u;
    // 80070D70: bc    4, 2, 0x80070D9C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070D9C;
        }
    }

label_80070D74:
    ctx->pc = 0x80070D74u;
    ctx->downcount -= 4;
    // 80070D74: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80070D78:
    ctx->pc = 0x80070D78u;
    // 80070D78: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_80070D7C:
    ctx->pc = 0x80070D7Cu;
    // 80070D7C: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80070D80:
    ctx->pc = 0x80070D80u;
    // 80070D80: bl      0x8025D078
    {
            ctx->lr = 0x80070D84u;
            ctx->pc = 0x8025D078u;
            return;
    }

label_80070D84:
    ctx->pc = 0x80070D84u;
    ctx->downcount -= 6;
    // 80070D84: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80070D88:
    ctx->pc = 0x80070D88u;
    // 80070D88: stb     r3, -24944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24944);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_80070D8C:
    ctx->pc = 0x80070D8Cu;
    // 80070D8C: li      r0, 3
    ctx->gpr[0] = (u32)(s32)(3);

label_80070D90:
    ctx->pc = 0x80070D90u;
    // 80070D90: stw     r0, -24948(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24948);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80070D94:
    ctx->pc = 0x80070D94u;
    // 80070D94: stb     r3, -24950(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24950);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_80070D98:
    ctx->pc = 0x80070D98u;
    // 80070D98: stb     r3, -24942(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24942);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_80070D9C:
    ctx->pc = 0x80070D9Cu;
    ctx->downcount -= 1;
    // 80070D9C: bl      0x8003BD08
    {
            ctx->lr = 0x80070DA0u;
            ctx->pc = 0x8003BD08u;
            return;
    }

label_80070DA0:
    ctx->pc = 0x80070DA0u;
    ctx->downcount -= 2;
    // 80070DA0: or   r26, r3, r3
    {
        ctx->gpr[26] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80070DA4:
    ctx->pc = 0x80070DA4u;
    // 80070DA4: bl      0x8003BD08
    {
            ctx->lr = 0x80070DA8u;
            ctx->pc = 0x8003BD08u;
            return;
    }

label_80070DA8:
    ctx->pc = 0x80070DA8u;
    ctx->downcount -= 6;
    // 80070DA8: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80070DAC:
    ctx->pc = 0x80070DACu;
    // 80070DAC: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_80070DB0:
    ctx->pc = 0x80070DB0u;
    // 80070DB0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80070DB4:
    ctx->pc = 0x80070DB4u;
    // 80070DB4: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_80070DB8:
    ctx->pc = 0x80070DB8u;
    // 80070DB8: or   r7, r26, r26
    {
        ctx->gpr[7] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80070DBC:
    ctx->pc = 0x80070DBCu;
    // 80070DBC: bl      0x8025C960
    {
            ctx->lr = 0x80070DC0u;
            ctx->pc = 0x8025C960u;
            return;
    }

label_80070DC0:
    ctx->pc = 0x80070DC0u;
    ctx->downcount -= 1;
    // 80070DC0: b       0x80071034
    {
            goto label_80071034;
    }

label_80070DC4:
    ctx->pc = 0x80070DC4u;
    ctx->downcount -= 3;
    // 80070DC4: lbz     r0, -24944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24944);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80070DC8:
    ctx->pc = 0x80070DC8u;
    // 80070DC8: cmplwi  r0, 0x0001
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0001u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80070DCC:
    ctx->pc = 0x80070DCCu;
    // 80070DCC: bc    4, 2, 0x80070DF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070DF4;
        }
    }

label_80070DD0:
    ctx->pc = 0x80070DD0u;
    ctx->downcount -= 3;
    // 80070DD0: lwz     r0, -24948(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24948);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80070DD4:
    ctx->pc = 0x80070DD4u;
    // 80070DD4: cmpwi   r0, 3
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80070DD8:
    ctx->pc = 0x80070DD8u;
    // 80070DD8: bc    4, 2, 0x80070DF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070DF4;
        }
    }

label_80070DDC:
    ctx->pc = 0x80070DDCu;
    ctx->downcount -= 3;
    // 80070DDC: lbz     r0, -24950(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24950);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80070DE0:
    ctx->pc = 0x80070DE0u;
    // 80070DE0: cmplwi  r0, 0x0000
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

label_80070DE4:
    ctx->pc = 0x80070DE4u;
    // 80070DE4: bc    4, 2, 0x80070DF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070DF4;
        }
    }

label_80070DE8:
    ctx->pc = 0x80070DE8u;
    ctx->downcount -= 3;
    // 80070DE8: lbz     r0, -24942(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24942);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80070DEC:
    ctx->pc = 0x80070DECu;
    // 80070DEC: cmplwi  r0, 0x0000
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

label_80070DF0:
    ctx->pc = 0x80070DF0u;
    // 80070DF0: bc    4, 2, 0x80070E20
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070E20;
        }
    }

label_80070DF4:
    ctx->pc = 0x80070DF4u;
    ctx->downcount -= 4;
    // 80070DF4: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80070DF8:
    ctx->pc = 0x80070DF8u;
    // 80070DF8: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_80070DFC:
    ctx->pc = 0x80070DFCu;
    // 80070DFC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80070E00:
    ctx->pc = 0x80070E00u;
    // 80070E00: bl      0x8025D078
    {
            ctx->lr = 0x80070E04u;
            ctx->pc = 0x8025D078u;
            return;
    }

label_80070E04:
    ctx->pc = 0x80070E04u;
    ctx->downcount -= 7;
    // 80070E04: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80070E08:
    ctx->pc = 0x80070E08u;
    // 80070E08: stb     r3, -24944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24944);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_80070E0C:
    ctx->pc = 0x80070E0Cu;
    // 80070E0C: li      r0, 3
    ctx->gpr[0] = (u32)(s32)(3);

label_80070E10:
    ctx->pc = 0x80070E10u;
    // 80070E10: stw     r0, -24948(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24948);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80070E14:
    ctx->pc = 0x80070E14u;
    // 80070E14: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80070E18:
    ctx->pc = 0x80070E18u;
    // 80070E18: stb     r0, -24950(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24950);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80070E1C:
    ctx->pc = 0x80070E1Cu;
    // 80070E1C: stb     r3, -24942(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24942);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_80070E20:
    ctx->pc = 0x80070E20u;
    ctx->downcount -= 6;
    // 80070E20: li      r3, 7
    ctx->gpr[3] = (u32)(s32)(7);

label_80070E24:
    ctx->pc = 0x80070E24u;
    // 80070E24: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80070E28:
    ctx->pc = 0x80070E28u;
    // 80070E28: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80070E2C:
    ctx->pc = 0x80070E2Cu;
    // 80070E2C: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_80070E30:
    ctx->pc = 0x80070E30u;
    // 80070E30: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80070E34:
    ctx->pc = 0x80070E34u;
    // 80070E34: bl      0x8025C960
    {
            ctx->lr = 0x80070E38u;
            ctx->pc = 0x8025C960u;
            return;
    }

label_80070E38:
    ctx->pc = 0x80070E38u;
    ctx->downcount -= 1;
    // 80070E38: b       0x80071034
    {
            goto label_80071034;
    }

label_80070E3C:
    ctx->pc = 0x80070E3Cu;
    ctx->downcount -= 3;
    // 80070E3C: rlwinm r0, r3, 0, 21, 21
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00000400u;
    }

label_80070E40:
    ctx->pc = 0x80070E40u;
    // 80070E40: cmplwi  r0, 0x0000
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

label_80070E44:
    ctx->pc = 0x80070E44u;
    // 80070E44: bc    12, 2, 0x80070F40
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80070F40;
        }
    }

label_80070E48:
    ctx->pc = 0x80070E48u;
    ctx->downcount -= 5;
    // 80070E48: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80070E4C:
    ctx->pc = 0x80070E4Cu;
    // 80070E4C: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80070E50:
    ctx->pc = 0x80070E50u;
    // 80070E50: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80070E54:
    ctx->pc = 0x80070E54u;
    // 80070E54: li      r6, 5
    ctx->gpr[6] = (u32)(s32)(5);

label_80070E58:
    ctx->pc = 0x80070E58u;
    // 80070E58: bl      0x8025CEF4
    {
            ctx->lr = 0x80070E5Cu;
            ctx->pc = 0x8025CEF4u;
            return;
    }

label_80070E5C:
    ctx->pc = 0x80070E5Cu;
    ctx->downcount -= 4;
    // 80070E5C: lhz     r0, 2(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(2);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80070E60:
    ctx->pc = 0x80070E60u;
    // 80070E60: rlwinm r0, r0, 0, 21, 21
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000400u;
    }

label_80070E64:
    ctx->pc = 0x80070E64u;
    // 80070E64: cmpwi   r0, 0
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

label_80070E68:
    ctx->pc = 0x80070E68u;
    // 80070E68: bc    12, 2, 0x80070ECC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80070ECC;
        }
    }

label_80070E6C:
    ctx->pc = 0x80070E6Cu;
    ctx->downcount -= 3;
    // 80070E6C: lbz     r0, -24944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24944);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80070E70:
    ctx->pc = 0x80070E70u;
    // 80070E70: cmplwi  r0, 0x0000
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

label_80070E74:
    ctx->pc = 0x80070E74u;
    // 80070E74: bc    4, 2, 0x80070E9C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070E9C;
        }
    }

label_80070E78:
    ctx->pc = 0x80070E78u;
    ctx->downcount -= 3;
    // 80070E78: lwz     r0, -24948(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24948);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80070E7C:
    ctx->pc = 0x80070E7Cu;
    // 80070E7C: cmpwi   r0, 3
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80070E80:
    ctx->pc = 0x80070E80u;
    // 80070E80: bc    4, 2, 0x80070E9C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070E9C;
        }
    }

label_80070E84:
    ctx->pc = 0x80070E84u;
    ctx->downcount -= 3;
    // 80070E84: lbz     r0, -24950(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24950);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80070E88:
    ctx->pc = 0x80070E88u;
    // 80070E88: cmplwi  r0, 0x0000
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

label_80070E8C:
    ctx->pc = 0x80070E8Cu;
    // 80070E8C: bc    4, 2, 0x80070E9C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070E9C;
        }
    }

label_80070E90:
    ctx->pc = 0x80070E90u;
    ctx->downcount -= 3;
    // 80070E90: lbz     r0, -24942(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24942);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80070E94:
    ctx->pc = 0x80070E94u;
    // 80070E94: cmplwi  r0, 0x0000
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

label_80070E98:
    ctx->pc = 0x80070E98u;
    // 80070E98: bc    4, 2, 0x80070F24
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070F24;
        }
    }

label_80070E9C:
    ctx->pc = 0x80070E9Cu;
    ctx->downcount -= 4;
    // 80070E9C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80070EA0:
    ctx->pc = 0x80070EA0u;
    // 80070EA0: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_80070EA4:
    ctx->pc = 0x80070EA4u;
    // 80070EA4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80070EA8:
    ctx->pc = 0x80070EA8u;
    // 80070EA8: bl      0x8025D078
    {
            ctx->lr = 0x80070EACu;
            ctx->pc = 0x8025D078u;
            return;
    }

label_80070EAC:
    ctx->pc = 0x80070EACu;
    ctx->downcount -= 8;
    // 80070EAC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80070EB0:
    ctx->pc = 0x80070EB0u;
    // 80070EB0: stb     r3, -24944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24944);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_80070EB4:
    ctx->pc = 0x80070EB4u;
    // 80070EB4: li      r0, 3
    ctx->gpr[0] = (u32)(s32)(3);

label_80070EB8:
    ctx->pc = 0x80070EB8u;
    // 80070EB8: stw     r0, -24948(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24948);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80070EBC:
    ctx->pc = 0x80070EBCu;
    // 80070EBC: stb     r3, -24950(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24950);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_80070EC0:
    ctx->pc = 0x80070EC0u;
    // 80070EC0: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80070EC4:
    ctx->pc = 0x80070EC4u;
    // 80070EC4: stb     r0, -24942(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24942);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80070EC8:
    ctx->pc = 0x80070EC8u;
    // 80070EC8: b       0x80070F24
    {
            goto label_80070F24;
    }

label_80070ECC:
    ctx->pc = 0x80070ECCu;
    ctx->downcount -= 3;
    // 80070ECC: lbz     r0, -24944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24944);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80070ED0:
    ctx->pc = 0x80070ED0u;
    // 80070ED0: cmplwi  r0, 0x0001
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0001u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80070ED4:
    ctx->pc = 0x80070ED4u;
    // 80070ED4: bc    4, 2, 0x80070EFC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070EFC;
        }
    }

label_80070ED8:
    ctx->pc = 0x80070ED8u;
    ctx->downcount -= 3;
    // 80070ED8: lwz     r0, -24948(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24948);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80070EDC:
    ctx->pc = 0x80070EDCu;
    // 80070EDC: cmpwi   r0, 3
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80070EE0:
    ctx->pc = 0x80070EE0u;
    // 80070EE0: bc    4, 2, 0x80070EFC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070EFC;
        }
    }

label_80070EE4:
    ctx->pc = 0x80070EE4u;
    ctx->downcount -= 3;
    // 80070EE4: lbz     r0, -24950(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24950);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80070EE8:
    ctx->pc = 0x80070EE8u;
    // 80070EE8: cmplwi  r0, 0x0001
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0001u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80070EEC:
    ctx->pc = 0x80070EECu;
    // 80070EEC: bc    4, 2, 0x80070EFC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070EFC;
        }
    }

label_80070EF0:
    ctx->pc = 0x80070EF0u;
    ctx->downcount -= 3;
    // 80070EF0: lbz     r0, -24942(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24942);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80070EF4:
    ctx->pc = 0x80070EF4u;
    // 80070EF4: cmplwi  r0, 0x0000
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

label_80070EF8:
    ctx->pc = 0x80070EF8u;
    // 80070EF8: bc    4, 2, 0x80070F24
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070F24;
        }
    }

label_80070EFC:
    ctx->pc = 0x80070EFCu;
    ctx->downcount -= 4;
    // 80070EFC: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80070F00:
    ctx->pc = 0x80070F00u;
    // 80070F00: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_80070F04:
    ctx->pc = 0x80070F04u;
    // 80070F04: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80070F08:
    ctx->pc = 0x80070F08u;
    // 80070F08: bl      0x8025D078
    {
            ctx->lr = 0x80070F0Cu;
            ctx->pc = 0x8025D078u;
            return;
    }

label_80070F0C:
    ctx->pc = 0x80070F0Cu;
    ctx->downcount -= 6;
    // 80070F0C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80070F10:
    ctx->pc = 0x80070F10u;
    // 80070F10: stb     r3, -24944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24944);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_80070F14:
    ctx->pc = 0x80070F14u;
    // 80070F14: li      r0, 3
    ctx->gpr[0] = (u32)(s32)(3);

label_80070F18:
    ctx->pc = 0x80070F18u;
    // 80070F18: stw     r0, -24948(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24948);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80070F1C:
    ctx->pc = 0x80070F1Cu;
    // 80070F1C: stb     r3, -24950(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24950);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_80070F20:
    ctx->pc = 0x80070F20u;
    // 80070F20: stb     r3, -24942(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24942);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_80070F24:
    ctx->pc = 0x80070F24u;
    ctx->downcount -= 6;
    // 80070F24: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_80070F28:
    ctx->pc = 0x80070F28u;
    // 80070F28: li      r4, 192
    ctx->gpr[4] = (u32)(s32)(192);

label_80070F2C:
    ctx->pc = 0x80070F2Cu;
    // 80070F2C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80070F30:
    ctx->pc = 0x80070F30u;
    // 80070F30: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_80070F34:
    ctx->pc = 0x80070F34u;
    // 80070F34: li      r7, 192
    ctx->gpr[7] = (u32)(s32)(192);

label_80070F38:
    ctx->pc = 0x80070F38u;
    // 80070F38: bl      0x8025C960
    {
            ctx->lr = 0x80070F3Cu;
            ctx->pc = 0x8025C960u;
            return;
    }

label_80070F3C:
    ctx->pc = 0x80070F3Cu;
    ctx->downcount -= 1;
    // 80070F3C: b       0x80071034
    {
            goto label_80071034;
    }

label_80070F40:
    ctx->pc = 0x80070F40u;
    ctx->downcount -= 5;
    // 80070F40: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80070F44:
    ctx->pc = 0x80070F44u;
    // 80070F44: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80070F48:
    ctx->pc = 0x80070F48u;
    // 80070F48: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80070F4C:
    ctx->pc = 0x80070F4Cu;
    // 80070F4C: li      r6, 5
    ctx->gpr[6] = (u32)(s32)(5);

label_80070F50:
    ctx->pc = 0x80070F50u;
    // 80070F50: bl      0x8025CEF4
    {
            ctx->lr = 0x80070F54u;
            ctx->pc = 0x8025CEF4u;
            return;
    }

label_80070F54:
    ctx->pc = 0x80070F54u;
    ctx->downcount -= 4;
    // 80070F54: lhz     r0, 2(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(2);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80070F58:
    ctx->pc = 0x80070F58u;
    // 80070F58: rlwinm r0, r0, 0, 21, 21
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000400u;
    }

label_80070F5C:
    ctx->pc = 0x80070F5Cu;
    // 80070F5C: cmpwi   r0, 0
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

label_80070F60:
    ctx->pc = 0x80070F60u;
    // 80070F60: bc    12, 2, 0x80070FC4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80070FC4;
        }
    }

label_80070F64:
    ctx->pc = 0x80070F64u;
    ctx->downcount -= 3;
    // 80070F64: lbz     r0, -24944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24944);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80070F68:
    ctx->pc = 0x80070F68u;
    // 80070F68: cmplwi  r0, 0x0000
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

label_80070F6C:
    ctx->pc = 0x80070F6Cu;
    // 80070F6C: bc    4, 2, 0x80070F94
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070F94;
        }
    }

label_80070F70:
    ctx->pc = 0x80070F70u;
    ctx->downcount -= 3;
    // 80070F70: lwz     r0, -24948(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24948);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80070F74:
    ctx->pc = 0x80070F74u;
    // 80070F74: cmpwi   r0, 3
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80070F78:
    ctx->pc = 0x80070F78u;
    // 80070F78: bc    4, 2, 0x80070F94
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070F94;
        }
    }

label_80070F7C:
    ctx->pc = 0x80070F7Cu;
    ctx->downcount -= 3;
    // 80070F7C: lbz     r0, -24950(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24950);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80070F80:
    ctx->pc = 0x80070F80u;
    // 80070F80: cmplwi  r0, 0x0000
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

label_80070F84:
    ctx->pc = 0x80070F84u;
    // 80070F84: bc    4, 2, 0x80070F94
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070F94;
        }
    }

label_80070F88:
    ctx->pc = 0x80070F88u;
    ctx->downcount -= 3;
    // 80070F88: lbz     r0, -24942(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24942);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80070F8C:
    ctx->pc = 0x80070F8Cu;
    // 80070F8C: cmplwi  r0, 0x0000
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

label_80070F90:
    ctx->pc = 0x80070F90u;
    // 80070F90: bc    4, 2, 0x8007101C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8007101C;
        }
    }

label_80070F94:
    ctx->pc = 0x80070F94u;
    ctx->downcount -= 4;
    // 80070F94: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80070F98:
    ctx->pc = 0x80070F98u;
    // 80070F98: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_80070F9C:
    ctx->pc = 0x80070F9Cu;
    // 80070F9C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80070FA0:
    ctx->pc = 0x80070FA0u;
    // 80070FA0: bl      0x8025D078
    {
            ctx->lr = 0x80070FA4u;
            ctx->pc = 0x8025D078u;
            return;
    }

label_80070FA4:
    ctx->pc = 0x80070FA4u;
    ctx->downcount -= 8;
    // 80070FA4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80070FA8:
    ctx->pc = 0x80070FA8u;
    // 80070FA8: stb     r3, -24944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24944);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_80070FAC:
    ctx->pc = 0x80070FACu;
    // 80070FAC: li      r0, 3
    ctx->gpr[0] = (u32)(s32)(3);

label_80070FB0:
    ctx->pc = 0x80070FB0u;
    // 80070FB0: stw     r0, -24948(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24948);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80070FB4:
    ctx->pc = 0x80070FB4u;
    // 80070FB4: stb     r3, -24950(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24950);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_80070FB8:
    ctx->pc = 0x80070FB8u;
    // 80070FB8: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80070FBC:
    ctx->pc = 0x80070FBCu;
    // 80070FBC: stb     r0, -24942(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24942);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80070FC0:
    ctx->pc = 0x80070FC0u;
    // 80070FC0: b       0x8007101C
    {
            goto label_8007101C;
    }

label_80070FC4:
    ctx->pc = 0x80070FC4u;
    ctx->downcount -= 3;
    // 80070FC4: lbz     r0, -24944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24944);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80070FC8:
    ctx->pc = 0x80070FC8u;
    // 80070FC8: cmplwi  r0, 0x0001
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0001u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80070FCC:
    ctx->pc = 0x80070FCCu;
    // 80070FCC: bc    4, 2, 0x80070FF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070FF4;
        }
    }

label_80070FD0:
    ctx->pc = 0x80070FD0u;
    ctx->downcount -= 3;
    // 80070FD0: lwz     r0, -24948(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24948);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80070FD4:
    ctx->pc = 0x80070FD4u;
    // 80070FD4: cmpwi   r0, 3
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80070FD8:
    ctx->pc = 0x80070FD8u;
    // 80070FD8: bc    4, 2, 0x80070FF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070FF4;
        }
    }

label_80070FDC:
    ctx->pc = 0x80070FDCu;
    ctx->downcount -= 3;
    // 80070FDC: lbz     r0, -24950(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24950);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80070FE0:
    ctx->pc = 0x80070FE0u;
    // 80070FE0: cmplwi  r0, 0x0001
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0001u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80070FE4:
    ctx->pc = 0x80070FE4u;
    // 80070FE4: bc    4, 2, 0x80070FF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80070FF4;
        }
    }

label_80070FE8:
    ctx->pc = 0x80070FE8u;
    ctx->downcount -= 3;
    // 80070FE8: lbz     r0, -24942(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24942);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80070FEC:
    ctx->pc = 0x80070FECu;
    // 80070FEC: cmplwi  r0, 0x0000
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

label_80070FF0:
    ctx->pc = 0x80070FF0u;
    // 80070FF0: bc    4, 2, 0x8007101C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8007101C;
        }
    }

label_80070FF4:
    ctx->pc = 0x80070FF4u;
    ctx->downcount -= 4;
    // 80070FF4: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80070FF8:
    ctx->pc = 0x80070FF8u;
    // 80070FF8: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_80070FFC:
    ctx->pc = 0x80070FFCu;
    // 80070FFC: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80071000:
    ctx->pc = 0x80071000u;
    // 80071000: bl      0x8025D078
    {
            ctx->lr = 0x80071004u;
            ctx->pc = 0x8025D078u;
            return;
    }

label_80071004:
    ctx->pc = 0x80071004u;
    ctx->downcount -= 6;
    // 80071004: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80071008:
    ctx->pc = 0x80071008u;
    // 80071008: stb     r3, -24944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24944);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_8007100C:
    ctx->pc = 0x8007100Cu;
    // 8007100C: li      r0, 3
    ctx->gpr[0] = (u32)(s32)(3);

label_80071010:
    ctx->pc = 0x80071010u;
    // 80071010: stw     r0, -24948(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24948);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80071014:
    ctx->pc = 0x80071014u;
    // 80071014: stb     r3, -24950(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24950);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_80071018:
    ctx->pc = 0x80071018u;
    // 80071018: stb     r3, -24942(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24942);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_8007101C:
    ctx->pc = 0x8007101Cu;
    ctx->downcount -= 6;
    // 8007101C: li      r3, 7
    ctx->gpr[3] = (u32)(s32)(7);

label_80071020:
    ctx->pc = 0x80071020u;
    // 80071020: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071024:
    ctx->pc = 0x80071024u;
    // 80071024: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80071028:
    ctx->pc = 0x80071028u;
    // 80071028: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_8007102C:
    ctx->pc = 0x8007102Cu;
    // 8007102C: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80071030:
    ctx->pc = 0x80071030u;
    // 80071030: bl      0x8025C960
    {
            ctx->lr = 0x80071034u;
            ctx->pc = 0x8025C960u;
            return;
    }

label_80071034:
    ctx->pc = 0x80071034u;
    ctx->downcount -= 4;
    // 80071034: lwz     r0, 60(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(60);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80071038:
    ctx->pc = 0x80071038u;
    // 80071038: rlwinm r0, r0, 0, 21, 21
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000400u;
    }

label_8007103C:
    ctx->pc = 0x8007103Cu;
    // 8007103C: cmplwi  r0, 0x0000
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

label_80071040:
    ctx->pc = 0x80071040u;
    // 80071040: bc    12, 2, 0x80071048
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80071048;
        }
    }

label_80071044:
    ctx->pc = 0x80071044u;
    ctx->downcount -= 1;
    // 80071044: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_80071048:
    ctx->pc = 0x80071048u;
    ctx->downcount -= 4;
    // 80071048: lbz     r3, -24951(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24951);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8007104C:
    ctx->pc = 0x8007104Cu;
    // 8007104C: rlwinm r0, r30, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[30], 0u) & 0x000000FFu;
    }

label_80071050:
    ctx->pc = 0x80071050u;
    // 80071050: cmplw   r3, r0
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

label_80071054:
    ctx->pc = 0x80071054u;
    // 80071054: bc    4, 2, 0x80071064
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80071064;
        }
    }

label_80071058:
    ctx->pc = 0x80071058u;
    ctx->downcount -= 3;
    // 80071058: lbz     r0, -24943(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24943);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8007105C:
    ctx->pc = 0x8007105Cu;
    // 8007105C: cmplwi  r0, 0x0000
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

label_80071060:
    ctx->pc = 0x80071060u;
    // 80071060: bc    4, 2, 0x80071078
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80071078;
        }
    }

label_80071064:
    ctx->pc = 0x80071064u;
    ctx->downcount -= 2;
    // 80071064: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80071068:
    ctx->pc = 0x80071068u;
    // 80071068: bl      0x8025D0F0
    {
            ctx->lr = 0x8007106Cu;
            ctx->pc = 0x8025D0F0u;
            return;
    }

label_8007106C:
    ctx->pc = 0x8007106Cu;
    ctx->downcount -= 3;
    // 8007106C: stb     r30, -24951(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24951);
        mem_write8(ctx, ea, (u8)ctx->gpr[30]);
    }

label_80071070:
    ctx->pc = 0x80071070u;
    // 80071070: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80071074:
    ctx->pc = 0x80071074u;
    // 80071074: stb     r0, -24943(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24943);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80071078:
    ctx->pc = 0x80071078u;
    ctx->downcount -= 4;
    // 80071078: lwz     r0, 60(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(60);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8007107C:
    ctx->pc = 0x8007107Cu;
    // 8007107C: rlwinm r0, r0, 0, 28, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000008u;
    }

label_80071080:
    ctx->pc = 0x80071080u;
    // 80071080: cmplwi  r0, 0x0000
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

label_80071084:
    ctx->pc = 0x80071084u;
    // 80071084: bc    12, 2, 0x80071094
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80071094;
        }
    }

label_80071088:
    ctx->pc = 0x80071088u;
    ctx->downcount -= 2;
    // 80071088: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8007108C:
    ctx->pc = 0x8007108Cu;
    // 8007108C: bl      0x80259494
    {
            ctx->lr = 0x80071090u;
            ctx->pc = 0x80259494u;
            return;
    }

label_80071090:
    ctx->pc = 0x80071090u;
    ctx->downcount -= 1;
    // 80071090: b       0x8007109C
    {
            goto label_8007109C;
    }

label_80071094:
    ctx->pc = 0x80071094u;
    ctx->downcount -= 2;
    // 80071094: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80071098:
    ctx->pc = 0x80071098u;
    // 80071098: bl      0x80259494
    {
            ctx->lr = 0x8007109Cu;
            ctx->pc = 0x80259494u;
            return;
    }

label_8007109C:
    ctx->pc = 0x8007109Cu;
    ctx->downcount -= 3;
    // 8007109C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_800710A0:
    ctx->pc = 0x800710A0u;
    // 800710A0: addi    r11, r1, 128
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(128);

label_800710A4:
    ctx->pc = 0x800710A4u;
    // 800710A4: bl      0x80286A90
    {
            ctx->lr = 0x800710A8u;
            ctx->pc = 0x80286A90u;
            return;
    }

label_800710A8:
    ctx->pc = 0x800710A8u;
    ctx->downcount -= 5;
    // 800710A8: lwz     r0, 132(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(132);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800710AC:
    ctx->pc = 0x800710ACu;
    // 800710AC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800710B0:
    ctx->pc = 0x800710B0u;
    // 800710B0: addi    r1, r1, 128
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(128);

label_800710B4:
    ctx->pc = 0x800710B4u;
    // 800710B4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_800710B8:
    ctx->pc = 0x800710B8u;
    ctx->downcount -= 8;
    // 800710B8: stwu     r1, -160(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-160);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800710BC:
    ctx->pc = 0x800710BCu;
    // 800710BC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800710C0:
    ctx->pc = 0x800710C0u;
    // 800710C0: stw     r0, 164(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(164);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800710C4:
    ctx->pc = 0x800710C4u;
    // 800710C4: stw     r31, 156(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(156);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_800710C8:
    ctx->pc = 0x800710C8u;
    // 800710C8: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800710CC:
    ctx->pc = 0x800710CCu;
    // 800710CC: addi    r3, r1, 40
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(40);

label_800710D0:
    ctx->pc = 0x800710D0u;
    // 800710D0: addi    r4, r1, 36
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(36);

label_800710D4:
    ctx->pc = 0x800710D4u;
    // 800710D4: bl      0x8006CCA0
    {
            ctx->lr = 0x800710D8u;
            ctx->pc = 0x8006CCA0u;
            return;
    }

label_800710D8:
    ctx->pc = 0x800710D8u;
    ctx->downcount -= 2;
    // 800710D8: addi    r3, r1, 44
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(44);

label_800710DC:
    ctx->pc = 0x800710DCu;
    // 800710DC: bl      0x8006C7C8
    {
            ctx->lr = 0x800710E0u;
            ctx->pc = 0x8006C7C8u;
            return;
    }

label_800710E0:
    ctx->pc = 0x800710E0u;
    ctx->downcount -= 1;
    // 800710E0: bl      0x8006CA14
    {
            ctx->lr = 0x800710E4u;
            ctx->pc = 0x8006CA14u;
            return;
    }

label_800710E4:
    ctx->pc = 0x800710E4u;
    ctx->downcount -= 2;
    // 800710E4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800710E8:
    ctx->pc = 0x800710E8u;
    // 800710E8: bl      0x8006C8D4
    {
            ctx->lr = 0x800710ECu;
            ctx->pc = 0x8006C8D4u;
            return;
    }

label_800710EC:
    ctx->pc = 0x800710ECu;
    ctx->downcount -= 3;
    // 800710EC: lwz     r3, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800710F0:
    ctx->pc = 0x800710F0u;
    // 800710F0: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_800710F4:
    ctx->pc = 0x800710F4u;
    // 800710F4: bl      0x8004C4C8
    {
            ctx->lr = 0x800710F8u;
            ctx->pc = 0x8004C4C8u;
            return;
    }

label_800710F8:
    ctx->pc = 0x800710F8u;
    ctx->downcount -= 7;
    // 800710F8: addi    r3, r13, -31404
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-31404);

label_800710FC:
    ctx->pc = 0x800710FCu;
    // 800710FC: stb     r31, 3(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(3);
        mem_write8(ctx, ea, (u8)ctx->gpr[31]);
    }

label_80071100:
    ctx->pc = 0x80071100u;
    // 80071100: lwz     r0, -31404(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31404);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80071104:
    ctx->pc = 0x80071104u;
    // 80071104: stw     r0, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80071108:
    ctx->pc = 0x80071108u;
    // 80071108: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8007110C:
    ctx->pc = 0x8007110Cu;
    // 8007110C: addi    r4, r1, 32
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(32);

label_80071110:
    ctx->pc = 0x80071110u;
    // 80071110: bl      0x8025C71C
    {
            ctx->lr = 0x80071114u;
            ctx->pc = 0x8025C71Cu;
            return;
    }

label_80071114:
    ctx->pc = 0x80071114u;
    ctx->downcount -= 5;
    // 80071114: lwz     r0, -31400(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31400);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80071118:
    ctx->pc = 0x80071118u;
    // 80071118: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8007111C:
    ctx->pc = 0x8007111Cu;
    // 8007111C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80071120:
    ctx->pc = 0x80071120u;
    // 80071120: addi    r4, r1, 28
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(28);

label_80071124:
    ctx->pc = 0x80071124u;
    // 80071124: bl      0x8025C71C
    {
            ctx->lr = 0x80071128u;
            ctx->pc = 0x8025C71Cu;
            return;
    }

label_80071128:
    ctx->pc = 0x80071128u;
    ctx->downcount -= 5;
    // 80071128: lwz     r0, -31396(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31396);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8007112C:
    ctx->pc = 0x8007112Cu;
    // 8007112C: stw     r0, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80071130:
    ctx->pc = 0x80071130u;
    // 80071130: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80071134:
    ctx->pc = 0x80071134u;
    // 80071134: addi    r4, r1, 24
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(24);

label_80071138:
    ctx->pc = 0x80071138u;
    // 80071138: bl      0x8025C71C
    {
            ctx->lr = 0x8007113Cu;
            ctx->pc = 0x8025C71Cu;
            return;
    }

label_8007113C:
    ctx->pc = 0x8007113Cu;
    ctx->downcount -= 5;
    // 8007113C: lwz     r0, -31392(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31392);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80071140:
    ctx->pc = 0x80071140u;
    // 80071140: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80071144:
    ctx->pc = 0x80071144u;
    // 80071144: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_80071148:
    ctx->pc = 0x80071148u;
    // 80071148: addi    r4, r1, 20
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(20);

label_8007114C:
    ctx->pc = 0x8007114Cu;
    // 8007114C: bl      0x8025C71C
    {
            ctx->lr = 0x80071150u;
            ctx->pc = 0x8025C71Cu;
            return;
    }

label_80071150:
    ctx->pc = 0x80071150u;
    ctx->downcount -= 7;
    // 80071150: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80071154:
    ctx->pc = 0x80071154u;
    // 80071154: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80071158:
    ctx->pc = 0x80071158u;
    // 80071158: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_8007115C:
    ctx->pc = 0x8007115Cu;
    // 8007115C: li      r6, 60
    ctx->gpr[6] = (u32)(s32)(60);

label_80071160:
    ctx->pc = 0x80071160u;
    // 80071160: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80071164:
    ctx->pc = 0x80071164u;
    // 80071164: li      r8, 125
    ctx->gpr[8] = (u32)(s32)(125);

label_80071168:
    ctx->pc = 0x80071168u;
    // 80071168: bl      0x80258880
    {
            ctx->lr = 0x8007116Cu;
            ctx->pc = 0x80258880u;
            return;
    }

label_8007116C:
    ctx->pc = 0x8007116Cu;
    ctx->downcount -= 5;
    // 8007116C: addi    r3, r1, 96
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(96);

label_80071170:
    ctx->pc = 0x80071170u;
    // 80071170: lfs     f1, -30224(r2)
    if (!ppc_fp_available_inline(ctx, 0x80071170u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30224);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80071174:
    ctx->pc = 0x80071174u;
    // 80071174: fmr    f2, f1
    if (!ppc_fp_available_inline(ctx, 0x80071174u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_80071178:
    ctx->pc = 0x80071178u;
    // 80071178: lfs     f3, -30228(r2)
    if (!ppc_fp_available_inline(ctx, 0x80071178u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30228);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8007117C:
    ctx->pc = 0x8007117Cu;
    // 8007117C: bl      0x80247CC4
    {
            ctx->lr = 0x80071180u;
            ctx->pc = 0x80247CC4u;
            return;
    }

label_80071180:
    ctx->pc = 0x80071180u;
    ctx->downcount -= 7;
    // 80071180: lfs     f0, 40(r1)
    if (!ppc_fp_available_inline(ctx, 0x80071180u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80071184:
    ctx->pc = 0x80071184u;
    // 80071184: fneg    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x80071184u)) return;
    ctx->fpr[0] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[0]) ^ 0x8000000000000000ull);

label_80071188:
    ctx->pc = 0x80071188u;
    // 80071188: stfs     f0, 124(r1)
    if (!ppc_fp_available_inline(ctx, 0x80071188u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(124);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8007118C:
    ctx->pc = 0x8007118Cu;
    // 8007118C: addi    r3, r1, 96
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(96);

label_80071190:
    ctx->pc = 0x80071190u;
    // 80071190: li      r4, 30
    ctx->gpr[4] = (u32)(s32)(30);

label_80071194:
    ctx->pc = 0x80071194u;
    // 80071194: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80071198:
    ctx->pc = 0x80071198u;
    // 80071198: bl      0x8025DAD0
    {
            ctx->lr = 0x8007119Cu;
            ctx->pc = 0x8025DAD0u;
            return;
    }

label_8007119C:
    ctx->pc = 0x8007119Cu;
    ctx->downcount -= 7;
    // 8007119C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_800711A0:
    ctx->pc = 0x800711A0u;
    // 800711A0: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_800711A4:
    ctx->pc = 0x800711A4u;
    // 800711A4: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_800711A8:
    ctx->pc = 0x800711A8u;
    // 800711A8: li      r6, 30
    ctx->gpr[6] = (u32)(s32)(30);

label_800711AC:
    ctx->pc = 0x800711ACu;
    // 800711AC: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800711B0:
    ctx->pc = 0x800711B0u;
    // 800711B0: li      r8, 125
    ctx->gpr[8] = (u32)(s32)(125);

label_800711B4:
    ctx->pc = 0x800711B4u;
    // 800711B4: bl      0x80258880
    {
            ctx->lr = 0x800711B8u;
            ctx->pc = 0x80258880u;
            return;
    }

label_800711B8:
    ctx->pc = 0x800711B8u;
    ctx->downcount -= 5;
    // 800711B8: addi    r3, r1, 96
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(96);

label_800711BC:
    ctx->pc = 0x800711BCu;
    // 800711BC: lfs     f1, -30220(r2)
    if (!ppc_fp_available_inline(ctx, 0x800711BCu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30220);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800711C0:
    ctx->pc = 0x800711C0u;
    // 800711C0: fmr    f2, f1
    if (!ppc_fp_available_inline(ctx, 0x800711C0u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_800711C4:
    ctx->pc = 0x800711C4u;
    // 800711C4: lfs     f3, -30228(r2)
    if (!ppc_fp_available_inline(ctx, 0x800711C4u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30228);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_800711C8:
    ctx->pc = 0x800711C8u;
    // 800711C8: bl      0x80247CC4
    {
            ctx->lr = 0x800711CCu;
            ctx->pc = 0x80247CC4u;
            return;
    }

label_800711CC:
    ctx->pc = 0x800711CCu;
    ctx->downcount -= 4;
    // 800711CC: addi    r3, r1, 48
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(48);

label_800711D0:
    ctx->pc = 0x800711D0u;
    // 800711D0: li      r4, 122
    ctx->gpr[4] = (u32)(s32)(122);

label_800711D4:
    ctx->pc = 0x800711D4u;
    // 800711D4: lfs     f1, -30216(r2)
    if (!ppc_fp_available_inline(ctx, 0x800711D4u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30216);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800711D8:
    ctx->pc = 0x800711D8u;
    // 800711D8: bl      0x80247A74
    {
            ctx->lr = 0x800711DCu;
            ctx->pc = 0x80247A74u;
            return;
    }

label_800711DC:
    ctx->pc = 0x800711DCu;
    ctx->downcount -= 4;
    // 800711DC: addi    r3, r1, 48
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(48);

label_800711E0:
    ctx->pc = 0x800711E0u;
    // 800711E0: addi    r4, r1, 96
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(96);

label_800711E4:
    ctx->pc = 0x800711E4u;
    // 800711E4: or   r5, r4, r4
    {
        ctx->gpr[5] = ctx->gpr[4] | ctx->gpr[4];
    }

label_800711E8:
    ctx->pc = 0x800711E8u;
    // 800711E8: bl      0x80247860
    {
            ctx->lr = 0x800711ECu;
            ctx->pc = 0x80247860u;
            return;
    }

label_800711EC:
    ctx->pc = 0x800711ECu;
    ctx->downcount -= 7;
    // 800711EC: lfs     f0, 36(r1)
    if (!ppc_fp_available_inline(ctx, 0x800711ECu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800711F0:
    ctx->pc = 0x800711F0u;
    // 800711F0: stfs     f0, 108(r1)
    if (!ppc_fp_available_inline(ctx, 0x800711F0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(108);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800711F4:
    ctx->pc = 0x800711F4u;
    // 800711F4: stfs     f0, 124(r1)
    if (!ppc_fp_available_inline(ctx, 0x800711F4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(124);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800711F8:
    ctx->pc = 0x800711F8u;
    // 800711F8: addi    r3, r1, 96
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(96);

label_800711FC:
    ctx->pc = 0x800711FCu;
    // 800711FC: li      r4, 33
    ctx->gpr[4] = (u32)(s32)(33);

label_80071200:
    ctx->pc = 0x80071200u;
    // 80071200: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80071204:
    ctx->pc = 0x80071204u;
    // 80071204: bl      0x8025DAD0
    {
            ctx->lr = 0x80071208u;
            ctx->pc = 0x8025DAD0u;
            return;
    }

label_80071208:
    ctx->pc = 0x80071208u;
    ctx->downcount -= 7;
    // 80071208: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8007120C:
    ctx->pc = 0x8007120Cu;
    // 8007120C: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80071210:
    ctx->pc = 0x80071210u;
    // 80071210: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_80071214:
    ctx->pc = 0x80071214u;
    // 80071214: li      r6, 33
    ctx->gpr[6] = (u32)(s32)(33);

label_80071218:
    ctx->pc = 0x80071218u;
    // 80071218: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8007121C:
    ctx->pc = 0x8007121Cu;
    // 8007121C: li      r8, 125
    ctx->gpr[8] = (u32)(s32)(125);

label_80071220:
    ctx->pc = 0x80071220u;
    // 80071220: bl      0x80258880
    {
            ctx->lr = 0x80071224u;
            ctx->pc = 0x80258880u;
            return;
    }

label_80071224:
    ctx->pc = 0x80071224u;
    ctx->downcount -= 5;
    // 80071224: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80071228:
    ctx->pc = 0x80071228u;
    // 80071228: li      r4, 255
    ctx->gpr[4] = (u32)(s32)(255);

label_8007122C:
    ctx->pc = 0x8007122Cu;
    // 8007122C: li      r5, 255
    ctx->gpr[5] = (u32)(s32)(255);

label_80071230:
    ctx->pc = 0x80071230u;
    // 80071230: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_80071234:
    ctx->pc = 0x80071234u;
    // 80071234: bl      0x8025CA34
    {
            ctx->lr = 0x80071238u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_80071238:
    ctx->pc = 0x80071238u;
    ctx->downcount -= 2;
    // 80071238: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8007123C:
    ctx->pc = 0x8007123Cu;
    // 8007123C: bl      0x8025C08C
    {
            ctx->lr = 0x80071240u;
            ctx->pc = 0x8025C08Cu;
            return;
    }

label_80071240:
    ctx->pc = 0x80071240u;
    ctx->downcount -= 6;
    // 80071240: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80071244:
    ctx->pc = 0x80071244u;
    // 80071244: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_80071248:
    ctx->pc = 0x80071248u;
    // 80071248: li      r5, 15
    ctx->gpr[5] = (u32)(s32)(15);

label_8007124C:
    ctx->pc = 0x8007124Cu;
    // 8007124C: li      r6, 15
    ctx->gpr[6] = (u32)(s32)(15);

label_80071250:
    ctx->pc = 0x80071250u;
    // 80071250: li      r7, 15
    ctx->gpr[7] = (u32)(s32)(15);

label_80071254:
    ctx->pc = 0x80071254u;
    // 80071254: bl      0x8025C3B0
    {
            ctx->lr = 0x80071258u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_80071258:
    ctx->pc = 0x80071258u;
    ctx->downcount -= 6;
    // 80071258: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8007125C:
    ctx->pc = 0x8007125Cu;
    // 8007125C: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_80071260:
    ctx->pc = 0x80071260u;
    // 80071260: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_80071264:
    ctx->pc = 0x80071264u;
    // 80071264: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_80071268:
    ctx->pc = 0x80071268u;
    // 80071268: li      r7, 7
    ctx->gpr[7] = (u32)(s32)(7);

label_8007126C:
    ctx->pc = 0x8007126Cu;
    // 8007126C: bl      0x8025C430
    {
            ctx->lr = 0x80071270u;
            ctx->pc = 0x8025C430u;
            return;
    }

label_80071270:
    ctx->pc = 0x80071270u;
    ctx->downcount -= 4;
    // 80071270: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80071274:
    ctx->pc = 0x80071274u;
    // 80071274: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071278:
    ctx->pc = 0x80071278u;
    // 80071278: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8007127C:
    ctx->pc = 0x8007127Cu;
    // 8007127C: bl      0x8025C868
    {
            ctx->lr = 0x80071280u;
            ctx->pc = 0x8025C868u;
            return;
    }

label_80071280:
    ctx->pc = 0x80071280u;
    ctx->downcount -= 7;
    // 80071280: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80071284:
    ctx->pc = 0x80071284u;
    // 80071284: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071288:
    ctx->pc = 0x80071288u;
    // 80071288: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8007128C:
    ctx->pc = 0x8007128Cu;
    // 8007128C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80071290:
    ctx->pc = 0x80071290u;
    // 80071290: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_80071294:
    ctx->pc = 0x80071294u;
    // 80071294: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80071298:
    ctx->pc = 0x80071298u;
    // 80071298: bl      0x8025C4B4
    {
            ctx->lr = 0x8007129Cu;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_8007129C:
    ctx->pc = 0x8007129Cu;
    ctx->downcount -= 7;
    // 8007129C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800712A0:
    ctx->pc = 0x800712A0u;
    // 800712A0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800712A4:
    ctx->pc = 0x800712A4u;
    // 800712A4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800712A8:
    ctx->pc = 0x800712A8u;
    // 800712A8: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800712AC:
    ctx->pc = 0x800712ACu;
    // 800712AC: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_800712B0:
    ctx->pc = 0x800712B0u;
    // 800712B0: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800712B4:
    ctx->pc = 0x800712B4u;
    // 800712B4: bl      0x8025C574
    {
            ctx->lr = 0x800712B8u;
            ctx->pc = 0x8025C574u;
            return;
    }

label_800712B8:
    ctx->pc = 0x800712B8u;
    ctx->downcount -= 4;
    // 800712B8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800712BC:
    ctx->pc = 0x800712BCu;
    // 800712BC: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_800712C0:
    ctx->pc = 0x800712C0u;
    // 800712C0: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_800712C4:
    ctx->pc = 0x800712C4u;
    // 800712C4: bl      0x8025BF28
    {
            ctx->lr = 0x800712C8u;
            ctx->pc = 0x8025BF28u;
            return;
    }

label_800712C8:
    ctx->pc = 0x800712C8u;
    ctx->downcount -= 4;
    // 800712C8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800712CC:
    ctx->pc = 0x800712CCu;
    // 800712CC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800712D0:
    ctx->pc = 0x800712D0u;
    // 800712D0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800712D4:
    ctx->pc = 0x800712D4u;
    // 800712D4: bl      0x8025BD54
    {
            ctx->lr = 0x800712D8u;
            ctx->pc = 0x8025BD54u;
            return;
    }

label_800712D8:
    ctx->pc = 0x800712D8u;
    ctx->downcount -= 5;
    // 800712D8: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_800712DC:
    ctx->pc = 0x800712DCu;
    // 800712DC: lis     r4, -32719
    ctx->gpr[4] = ((u32)(s32)(-32719) << 16);

label_800712E0:
    ctx->pc = 0x800712E0u;
    // 800712E0: addi    r4, r4, 592
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(592);

label_800712E4:
    ctx->pc = 0x800712E4u;
    // 800712E4: li      r5, -3
    ctx->gpr[5] = (u32)(s32)(-3);

label_800712E8:
    ctx->pc = 0x800712E8u;
    // 800712E8: bl      0x8025BBF4
    {
            ctx->lr = 0x800712ECu;
            ctx->pc = 0x8025BBF4u;
            return;
    }

label_800712EC:
    ctx->pc = 0x800712ECu;
    ctx->downcount -= 13;
    // 800712EC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800712F0:
    ctx->pc = 0x800712F0u;
    // 800712F0: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800712F4:
    ctx->pc = 0x800712F4u;
    // 800712F4: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_800712F8:
    ctx->pc = 0x800712F8u;
    // 800712F8: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800712FC:
    ctx->pc = 0x800712FCu;
    // 800712FC: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80071300:
    ctx->pc = 0x80071300u;
    // 80071300: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071304:
    ctx->pc = 0x80071304u;
    // 80071304: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80071308:
    ctx->pc = 0x80071308u;
    // 80071308: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_8007130C:
    ctx->pc = 0x8007130Cu;
    // 8007130C: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_80071310:
    ctx->pc = 0x80071310u;
    // 80071310: li      r8, 6
    ctx->gpr[8] = (u32)(s32)(6);

label_80071314:
    ctx->pc = 0x80071314u;
    // 80071314: li      r9, 6
    ctx->gpr[9] = (u32)(s32)(6);

label_80071318:
    ctx->pc = 0x80071318u;
    // 80071318: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_8007131C:
    ctx->pc = 0x8007131Cu;
    // 8007131C: bl      0x8025BB58
    {
            ctx->lr = 0x80071320u;
            ctx->pc = 0x8025BB58u;
            return;
    }

label_80071320:
    ctx->pc = 0x80071320u;
    ctx->downcount -= 4;
    // 80071320: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80071324:
    ctx->pc = 0x80071324u;
    // 80071324: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80071328:
    ctx->pc = 0x80071328u;
    // 80071328: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_8007132C:
    ctx->pc = 0x8007132Cu;
    // 8007132C: bl      0x8025BF28
    {
            ctx->lr = 0x80071330u;
            ctx->pc = 0x8025BF28u;
            return;
    }

label_80071330:
    ctx->pc = 0x80071330u;
    ctx->downcount -= 4;
    // 80071330: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80071334:
    ctx->pc = 0x80071334u;
    // 80071334: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071338:
    ctx->pc = 0x80071338u;
    // 80071338: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8007133C:
    ctx->pc = 0x8007133Cu;
    // 8007133C: bl      0x8025BD54
    {
            ctx->lr = 0x80071340u;
            ctx->pc = 0x8025BD54u;
            return;
    }

label_80071340:
    ctx->pc = 0x80071340u;
    ctx->downcount -= 5;
    // 80071340: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80071344:
    ctx->pc = 0x80071344u;
    // 80071344: lis     r4, -32719
    ctx->gpr[4] = ((u32)(s32)(-32719) << 16);

label_80071348:
    ctx->pc = 0x80071348u;
    // 80071348: addi    r4, r4, 616
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(616);

label_8007134C:
    ctx->pc = 0x8007134Cu;
    // 8007134C: li      r5, -3
    ctx->gpr[5] = (u32)(s32)(-3);

label_80071350:
    ctx->pc = 0x80071350u;
    // 80071350: bl      0x8025BBF4
    {
            ctx->lr = 0x80071354u;
            ctx->pc = 0x8025BBF4u;
            return;
    }

label_80071354:
    ctx->pc = 0x80071354u;
    ctx->downcount -= 13;
    // 80071354: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80071358:
    ctx->pc = 0x80071358u;
    // 80071358: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8007135C:
    ctx->pc = 0x8007135Cu;
    // 8007135C: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80071360:
    ctx->pc = 0x80071360u;
    // 80071360: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80071364:
    ctx->pc = 0x80071364u;
    // 80071364: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80071368:
    ctx->pc = 0x80071368u;
    // 80071368: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8007136C:
    ctx->pc = 0x8007136Cu;
    // 8007136C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80071370:
    ctx->pc = 0x80071370u;
    // 80071370: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_80071374:
    ctx->pc = 0x80071374u;
    // 80071374: li      r7, 2
    ctx->gpr[7] = (u32)(s32)(2);

label_80071378:
    ctx->pc = 0x80071378u;
    // 80071378: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8007137C:
    ctx->pc = 0x8007137Cu;
    // 8007137C: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_80071380:
    ctx->pc = 0x80071380u;
    // 80071380: li      r10, 1
    ctx->gpr[10] = (u32)(s32)(1);

label_80071384:
    ctx->pc = 0x80071384u;
    // 80071384: bl      0x8025BB58
    {
            ctx->lr = 0x80071388u;
            ctx->pc = 0x8025BB58u;
            return;
    }

label_80071388:
    ctx->pc = 0x80071388u;
    ctx->downcount -= 5;
    // 80071388: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8007138C:
    ctx->pc = 0x8007138Cu;
    // 8007138C: li      r4, 255
    ctx->gpr[4] = (u32)(s32)(255);

label_80071390:
    ctx->pc = 0x80071390u;
    // 80071390: li      r5, 255
    ctx->gpr[5] = (u32)(s32)(255);

label_80071394:
    ctx->pc = 0x80071394u;
    // 80071394: li      r6, 8
    ctx->gpr[6] = (u32)(s32)(8);

label_80071398:
    ctx->pc = 0x80071398u;
    // 80071398: bl      0x8025CA34
    {
            ctx->lr = 0x8007139Cu;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_8007139C:
    ctx->pc = 0x8007139Cu;
    ctx->downcount -= 6;
    // 8007139C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_800713A0:
    ctx->pc = 0x800713A0u;
    // 800713A0: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_800713A4:
    ctx->pc = 0x800713A4u;
    // 800713A4: li      r5, 15
    ctx->gpr[5] = (u32)(s32)(15);

label_800713A8:
    ctx->pc = 0x800713A8u;
    // 800713A8: li      r6, 15
    ctx->gpr[6] = (u32)(s32)(15);

label_800713AC:
    ctx->pc = 0x800713ACu;
    // 800713AC: li      r7, 15
    ctx->gpr[7] = (u32)(s32)(15);

label_800713B0:
    ctx->pc = 0x800713B0u;
    // 800713B0: bl      0x8025C3B0
    {
            ctx->lr = 0x800713B4u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_800713B4:
    ctx->pc = 0x800713B4u;
    ctx->downcount -= 6;
    // 800713B4: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_800713B8:
    ctx->pc = 0x800713B8u;
    // 800713B8: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_800713BC:
    ctx->pc = 0x800713BCu;
    // 800713BC: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_800713C0:
    ctx->pc = 0x800713C0u;
    // 800713C0: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_800713C4:
    ctx->pc = 0x800713C4u;
    // 800713C4: li      r7, 5
    ctx->gpr[7] = (u32)(s32)(5);

label_800713C8:
    ctx->pc = 0x800713C8u;
    // 800713C8: bl      0x8025C430
    {
            ctx->lr = 0x800713CCu;
            ctx->pc = 0x8025C430u;
            return;
    }

label_800713CC:
    ctx->pc = 0x800713CCu;
    ctx->downcount -= 4;
    // 800713CC: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_800713D0:
    ctx->pc = 0x800713D0u;
    // 800713D0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800713D4:
    ctx->pc = 0x800713D4u;
    // 800713D4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800713D8:
    ctx->pc = 0x800713D8u;
    // 800713D8: bl      0x8025C868
    {
            ctx->lr = 0x800713DCu;
            ctx->pc = 0x8025C868u;
            return;
    }

label_800713DC:
    ctx->pc = 0x800713DCu;
    ctx->downcount -= 7;
    // 800713DC: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_800713E0:
    ctx->pc = 0x800713E0u;
    // 800713E0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800713E4:
    ctx->pc = 0x800713E4u;
    // 800713E4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800713E8:
    ctx->pc = 0x800713E8u;
    // 800713E8: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800713EC:
    ctx->pc = 0x800713ECu;
    // 800713EC: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_800713F0:
    ctx->pc = 0x800713F0u;
    // 800713F0: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800713F4:
    ctx->pc = 0x800713F4u;
    // 800713F4: bl      0x8025C4B4
    {
            ctx->lr = 0x800713F8u;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_800713F8:
    ctx->pc = 0x800713F8u;
    ctx->downcount -= 7;
    // 800713F8: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_800713FC:
    ctx->pc = 0x800713FCu;
    // 800713FC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071400:
    ctx->pc = 0x80071400u;
    // 80071400: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80071404:
    ctx->pc = 0x80071404u;
    // 80071404: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80071408:
    ctx->pc = 0x80071408u;
    // 80071408: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8007140C:
    ctx->pc = 0x8007140Cu;
    // 8007140C: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80071410:
    ctx->pc = 0x80071410u;
    // 80071410: bl      0x8025C574
    {
            ctx->lr = 0x80071414u;
            ctx->pc = 0x8025C574u;
            return;
    }

label_80071414:
    ctx->pc = 0x80071414u;
    ctx->downcount -= 5;
    // 80071414: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80071418:
    ctx->pc = 0x80071418u;
    // 80071418: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8007141C:
    ctx->pc = 0x8007141Cu;
    // 8007141C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80071420:
    ctx->pc = 0x80071420u;
    // 80071420: li      r6, 8
    ctx->gpr[6] = (u32)(s32)(8);

label_80071424:
    ctx->pc = 0x80071424u;
    // 80071424: bl      0x8025CA34
    {
            ctx->lr = 0x80071428u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_80071428:
    ctx->pc = 0x80071428u;
    ctx->downcount -= 6;
    // 80071428: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8007142C:
    ctx->pc = 0x8007142Cu;
    // 8007142C: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_80071430:
    ctx->pc = 0x80071430u;
    // 80071430: li      r5, 15
    ctx->gpr[5] = (u32)(s32)(15);

label_80071434:
    ctx->pc = 0x80071434u;
    // 80071434: li      r6, 15
    ctx->gpr[6] = (u32)(s32)(15);

label_80071438:
    ctx->pc = 0x80071438u;
    // 80071438: li      r7, 8
    ctx->gpr[7] = (u32)(s32)(8);

label_8007143C:
    ctx->pc = 0x8007143Cu;
    // 8007143C: bl      0x8025C3B0
    {
            ctx->lr = 0x80071440u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_80071440:
    ctx->pc = 0x80071440u;
    ctx->downcount -= 6;
    // 80071440: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80071444:
    ctx->pc = 0x80071444u;
    // 80071444: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071448:
    ctx->pc = 0x80071448u;
    // 80071448: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_8007144C:
    ctx->pc = 0x8007144Cu;
    // 8007144C: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_80071450:
    ctx->pc = 0x80071450u;
    // 80071450: li      r7, 5
    ctx->gpr[7] = (u32)(s32)(5);

label_80071454:
    ctx->pc = 0x80071454u;
    // 80071454: bl      0x8025C430
    {
            ctx->lr = 0x80071458u;
            ctx->pc = 0x8025C430u;
            return;
    }

label_80071458:
    ctx->pc = 0x80071458u;
    ctx->downcount -= 4;
    // 80071458: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8007145C:
    ctx->pc = 0x8007145Cu;
    // 8007145C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071460:
    ctx->pc = 0x80071460u;
    // 80071460: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80071464:
    ctx->pc = 0x80071464u;
    // 80071464: bl      0x8025C868
    {
            ctx->lr = 0x80071468u;
            ctx->pc = 0x8025C868u;
            return;
    }

label_80071468:
    ctx->pc = 0x80071468u;
    ctx->downcount -= 7;
    // 80071468: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8007146C:
    ctx->pc = 0x8007146Cu;
    // 8007146C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071470:
    ctx->pc = 0x80071470u;
    // 80071470: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80071474:
    ctx->pc = 0x80071474u;
    // 80071474: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80071478:
    ctx->pc = 0x80071478u;
    // 80071478: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8007147C:
    ctx->pc = 0x8007147Cu;
    // 8007147C: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80071480:
    ctx->pc = 0x80071480u;
    // 80071480: bl      0x8025C4B4
    {
            ctx->lr = 0x80071484u;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_80071484:
    ctx->pc = 0x80071484u;
    ctx->downcount -= 7;
    // 80071484: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80071488:
    ctx->pc = 0x80071488u;
    // 80071488: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8007148C:
    ctx->pc = 0x8007148Cu;
    // 8007148C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80071490:
    ctx->pc = 0x80071490u;
    // 80071490: li      r6, 3
    ctx->gpr[6] = (u32)(s32)(3);

label_80071494:
    ctx->pc = 0x80071494u;
    // 80071494: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_80071498:
    ctx->pc = 0x80071498u;
    // 80071498: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8007149C:
    ctx->pc = 0x8007149Cu;
    // 8007149C: bl      0x8025C574
    {
            ctx->lr = 0x800714A0u;
            ctx->pc = 0x8025C574u;
            return;
    }

label_800714A0:
    ctx->pc = 0x800714A0u;
    ctx->downcount -= 3;
    // 800714A0: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_800714A4:
    ctx->pc = 0x800714A4u;
    // 800714A4: li      r4, 12
    ctx->gpr[4] = (u32)(s32)(12);

label_800714A8:
    ctx->pc = 0x800714A8u;
    // 800714A8: bl      0x8025C790
    {
            ctx->lr = 0x800714ACu;
            ctx->pc = 0x8025C790u;
            return;
    }

label_800714AC:
    ctx->pc = 0x800714ACu;
    ctx->downcount -= 3;
    // 800714AC: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_800714B0:
    ctx->pc = 0x800714B0u;
    // 800714B0: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_800714B4:
    ctx->pc = 0x800714B4u;
    // 800714B4: bl      0x8025C7FC
    {
            ctx->lr = 0x800714B8u;
            ctx->pc = 0x8025C7FCu;
            return;
    }

label_800714B8:
    ctx->pc = 0x800714B8u;
    ctx->downcount -= 2;
    // 800714B8: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_800714BC:
    ctx->pc = 0x800714BCu;
    // 800714BC: bl      0x8025C08C
    {
            ctx->lr = 0x800714C0u;
            ctx->pc = 0x8025C08Cu;
            return;
    }

label_800714C0:
    ctx->pc = 0x800714C0u;
    ctx->downcount -= 5;
    // 800714C0: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_800714C4:
    ctx->pc = 0x800714C4u;
    // 800714C4: li      r4, 255
    ctx->gpr[4] = (u32)(s32)(255);

label_800714C8:
    ctx->pc = 0x800714C8u;
    // 800714C8: li      r5, 255
    ctx->gpr[5] = (u32)(s32)(255);

label_800714CC:
    ctx->pc = 0x800714CCu;
    // 800714CC: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_800714D0:
    ctx->pc = 0x800714D0u;
    // 800714D0: bl      0x8025CA34
    {
            ctx->lr = 0x800714D4u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_800714D4:
    ctx->pc = 0x800714D4u;
    ctx->downcount -= 6;
    // 800714D4: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_800714D8:
    ctx->pc = 0x800714D8u;
    // 800714D8: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_800714DC:
    ctx->pc = 0x800714DCu;
    // 800714DC: li      r5, 14
    ctx->gpr[5] = (u32)(s32)(14);

label_800714E0:
    ctx->pc = 0x800714E0u;
    // 800714E0: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800714E4:
    ctx->pc = 0x800714E4u;
    // 800714E4: li      r7, 15
    ctx->gpr[7] = (u32)(s32)(15);

label_800714E8:
    ctx->pc = 0x800714E8u;
    // 800714E8: bl      0x8025C3B0
    {
            ctx->lr = 0x800714ECu;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_800714EC:
    ctx->pc = 0x800714ECu;
    ctx->downcount -= 6;
    // 800714EC: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_800714F0:
    ctx->pc = 0x800714F0u;
    // 800714F0: li      r4, 6
    ctx->gpr[4] = (u32)(s32)(6);

label_800714F4:
    ctx->pc = 0x800714F4u;
    // 800714F4: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_800714F8:
    ctx->pc = 0x800714F8u;
    // 800714F8: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_800714FC:
    ctx->pc = 0x800714FCu;
    // 800714FC: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80071500:
    ctx->pc = 0x80071500u;
    // 80071500: bl      0x8025C430
    {
            ctx->lr = 0x80071504u;
            ctx->pc = 0x8025C430u;
            return;
    }

label_80071504:
    ctx->pc = 0x80071504u;
    ctx->downcount -= 4;
    // 80071504: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_80071508:
    ctx->pc = 0x80071508u;
    // 80071508: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8007150C:
    ctx->pc = 0x8007150Cu;
    // 8007150C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80071510:
    ctx->pc = 0x80071510u;
    // 80071510: bl      0x8025C868
    {
            ctx->lr = 0x80071514u;
            ctx->pc = 0x8025C868u;
            return;
    }

label_80071514:
    ctx->pc = 0x80071514u;
    ctx->downcount -= 7;
    // 80071514: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_80071518:
    ctx->pc = 0x80071518u;
    // 80071518: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8007151C:
    ctx->pc = 0x8007151Cu;
    // 8007151C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80071520:
    ctx->pc = 0x80071520u;
    // 80071520: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80071524:
    ctx->pc = 0x80071524u;
    // 80071524: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_80071528:
    ctx->pc = 0x80071528u;
    // 80071528: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_8007152C:
    ctx->pc = 0x8007152Cu;
    // 8007152C: bl      0x8025C4B4
    {
            ctx->lr = 0x80071530u;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_80071530:
    ctx->pc = 0x80071530u;
    ctx->downcount -= 7;
    // 80071530: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_80071534:
    ctx->pc = 0x80071534u;
    // 80071534: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80071538:
    ctx->pc = 0x80071538u;
    // 80071538: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8007153C:
    ctx->pc = 0x8007153Cu;
    // 8007153C: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_80071540:
    ctx->pc = 0x80071540u;
    // 80071540: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_80071544:
    ctx->pc = 0x80071544u;
    // 80071544: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_80071548:
    ctx->pc = 0x80071548u;
    // 80071548: bl      0x8025C574
    {
            ctx->lr = 0x8007154Cu;
            ctx->pc = 0x8025C574u;
            return;
    }

label_8007154C:
    ctx->pc = 0x8007154Cu;
    ctx->downcount -= 3;
    // 8007154C: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_80071550:
    ctx->pc = 0x80071550u;
    // 80071550: li      r4, 13
    ctx->gpr[4] = (u32)(s32)(13);

label_80071554:
    ctx->pc = 0x80071554u;
    // 80071554: bl      0x8025C790
    {
            ctx->lr = 0x80071558u;
            ctx->pc = 0x8025C790u;
            return;
    }

label_80071558:
    ctx->pc = 0x80071558u;
    ctx->downcount -= 3;
    // 80071558: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_8007155C:
    ctx->pc = 0x8007155Cu;
    // 8007155C: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_80071560:
    ctx->pc = 0x80071560u;
    // 80071560: bl      0x8025C7FC
    {
            ctx->lr = 0x80071564u;
            ctx->pc = 0x8025C7FCu;
            return;
    }

label_80071564:
    ctx->pc = 0x80071564u;
    ctx->downcount -= 2;
    // 80071564: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_80071568:
    ctx->pc = 0x80071568u;
    // 80071568: bl      0x8025C08C
    {
            ctx->lr = 0x8007156Cu;
            ctx->pc = 0x8025C08Cu;
            return;
    }

label_8007156C:
    ctx->pc = 0x8007156Cu;
    ctx->downcount -= 5;
    // 8007156C: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_80071570:
    ctx->pc = 0x80071570u;
    // 80071570: li      r4, 255
    ctx->gpr[4] = (u32)(s32)(255);

label_80071574:
    ctx->pc = 0x80071574u;
    // 80071574: li      r5, 255
    ctx->gpr[5] = (u32)(s32)(255);

label_80071578:
    ctx->pc = 0x80071578u;
    // 80071578: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_8007157C:
    ctx->pc = 0x8007157Cu;
    // 8007157C: bl      0x8025CA34
    {
            ctx->lr = 0x80071580u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_80071580:
    ctx->pc = 0x80071580u;
    ctx->downcount -= 6;
    // 80071580: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_80071584:
    ctx->pc = 0x80071584u;
    // 80071584: li      r4, 14
    ctx->gpr[4] = (u32)(s32)(14);

label_80071588:
    ctx->pc = 0x80071588u;
    // 80071588: li      r5, 15
    ctx->gpr[5] = (u32)(s32)(15);

label_8007158C:
    ctx->pc = 0x8007158Cu;
    // 8007158C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80071590:
    ctx->pc = 0x80071590u;
    // 80071590: li      r7, 2
    ctx->gpr[7] = (u32)(s32)(2);

label_80071594:
    ctx->pc = 0x80071594u;
    // 80071594: bl      0x8025C3B0
    {
            ctx->lr = 0x80071598u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_80071598:
    ctx->pc = 0x80071598u;
    ctx->downcount -= 6;
    // 80071598: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_8007159C:
    ctx->pc = 0x8007159Cu;
    // 8007159C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800715A0:
    ctx->pc = 0x800715A0u;
    // 800715A0: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_800715A4:
    ctx->pc = 0x800715A4u;
    // 800715A4: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_800715A8:
    ctx->pc = 0x800715A8u;
    // 800715A8: li      r7, 6
    ctx->gpr[7] = (u32)(s32)(6);

label_800715AC:
    ctx->pc = 0x800715ACu;
    // 800715AC: bl      0x8025C430
    {
            ctx->lr = 0x800715B0u;
            ctx->pc = 0x8025C430u;
            return;
    }

label_800715B0:
    ctx->pc = 0x800715B0u;
    ctx->downcount -= 4;
    // 800715B0: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_800715B4:
    ctx->pc = 0x800715B4u;
    // 800715B4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800715B8:
    ctx->pc = 0x800715B8u;
    // 800715B8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800715BC:
    ctx->pc = 0x800715BCu;
    // 800715BC: bl      0x8025C868
    {
            ctx->lr = 0x800715C0u;
            ctx->pc = 0x8025C868u;
            return;
    }

label_800715C0:
    ctx->pc = 0x800715C0u;
    ctx->downcount -= 7;
    // 800715C0: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_800715C4:
    ctx->pc = 0x800715C4u;
    // 800715C4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800715C8:
    ctx->pc = 0x800715C8u;
    // 800715C8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800715CC:
    ctx->pc = 0x800715CCu;
    // 800715CC: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800715D0:
    ctx->pc = 0x800715D0u;
    // 800715D0: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_800715D4:
    ctx->pc = 0x800715D4u;
    // 800715D4: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_800715D8:
    ctx->pc = 0x800715D8u;
    // 800715D8: bl      0x8025C4B4
    {
            ctx->lr = 0x800715DCu;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_800715DC:
    ctx->pc = 0x800715DCu;
    ctx->downcount -= 7;
    // 800715DC: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_800715E0:
    ctx->pc = 0x800715E0u;
    // 800715E0: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_800715E4:
    ctx->pc = 0x800715E4u;
    // 800715E4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800715E8:
    ctx->pc = 0x800715E8u;
    // 800715E8: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_800715EC:
    ctx->pc = 0x800715ECu;
    // 800715EC: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_800715F0:
    ctx->pc = 0x800715F0u;
    // 800715F0: li      r8, 2
    ctx->gpr[8] = (u32)(s32)(2);

label_800715F4:
    ctx->pc = 0x800715F4u;
    // 800715F4: bl      0x8025C574
    {
            ctx->lr = 0x800715F8u;
            ctx->pc = 0x8025C574u;
            return;
    }

label_800715F8:
    ctx->pc = 0x800715F8u;
    ctx->downcount -= 3;
    // 800715F8: li      r3, 5
    ctx->gpr[3] = (u32)(s32)(5);

label_800715FC:
    ctx->pc = 0x800715FCu;
    // 800715FC: li      r4, 14
    ctx->gpr[4] = (u32)(s32)(14);

label_80071600:
    ctx->pc = 0x80071600u;
    // 80071600: bl      0x8025C790
    {
            ctx->lr = 0x80071604u;
            ctx->pc = 0x8025C790u;
            return;
    }

label_80071604:
    ctx->pc = 0x80071604u;
    ctx->downcount -= 5;
    // 80071604: li      r3, 5
    ctx->gpr[3] = (u32)(s32)(5);

label_80071608:
    ctx->pc = 0x80071608u;
    // 80071608: li      r4, 255
    ctx->gpr[4] = (u32)(s32)(255);

label_8007160C:
    ctx->pc = 0x8007160Cu;
    // 8007160C: li      r5, 255
    ctx->gpr[5] = (u32)(s32)(255);

label_80071610:
    ctx->pc = 0x80071610u;
    // 80071610: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_80071614:
    ctx->pc = 0x80071614u;
    // 80071614: bl      0x8025CA34
    {
            ctx->lr = 0x80071618u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_80071618:
    ctx->pc = 0x80071618u;
    ctx->downcount -= 2;
    // 80071618: li      r3, 5
    ctx->gpr[3] = (u32)(s32)(5);

label_8007161C:
    ctx->pc = 0x8007161Cu;
    // 8007161C: bl      0x8025C08C
    {
            ctx->lr = 0x80071620u;
            ctx->pc = 0x8025C08Cu;
            return;
    }

label_80071620:
    ctx->pc = 0x80071620u;
    ctx->downcount -= 6;
    // 80071620: li      r3, 5
    ctx->gpr[3] = (u32)(s32)(5);

label_80071624:
    ctx->pc = 0x80071624u;
    // 80071624: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_80071628:
    ctx->pc = 0x80071628u;
    // 80071628: li      r5, 14
    ctx->gpr[5] = (u32)(s32)(14);

label_8007162C:
    ctx->pc = 0x8007162Cu;
    // 8007162C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80071630:
    ctx->pc = 0x80071630u;
    // 80071630: li      r7, 15
    ctx->gpr[7] = (u32)(s32)(15);

label_80071634:
    ctx->pc = 0x80071634u;
    // 80071634: bl      0x8025C3B0
    {
            ctx->lr = 0x80071638u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_80071638:
    ctx->pc = 0x80071638u;
    ctx->downcount -= 6;
    // 80071638: li      r3, 5
    ctx->gpr[3] = (u32)(s32)(5);

label_8007163C:
    ctx->pc = 0x8007163Cu;
    // 8007163C: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80071640:
    ctx->pc = 0x80071640u;
    // 80071640: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_80071644:
    ctx->pc = 0x80071644u;
    // 80071644: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_80071648:
    ctx->pc = 0x80071648u;
    // 80071648: li      r7, 2
    ctx->gpr[7] = (u32)(s32)(2);

label_8007164C:
    ctx->pc = 0x8007164Cu;
    // 8007164C: bl      0x8025C430
    {
            ctx->lr = 0x80071650u;
            ctx->pc = 0x8025C430u;
            return;
    }

label_80071650:
    ctx->pc = 0x80071650u;
    ctx->downcount -= 4;
    // 80071650: li      r3, 5
    ctx->gpr[3] = (u32)(s32)(5);

label_80071654:
    ctx->pc = 0x80071654u;
    // 80071654: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071658:
    ctx->pc = 0x80071658u;
    // 80071658: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8007165C:
    ctx->pc = 0x8007165Cu;
    // 8007165C: bl      0x8025C868
    {
            ctx->lr = 0x80071660u;
            ctx->pc = 0x8025C868u;
            return;
    }

label_80071660:
    ctx->pc = 0x80071660u;
    ctx->downcount -= 7;
    // 80071660: li      r3, 5
    ctx->gpr[3] = (u32)(s32)(5);

label_80071664:
    ctx->pc = 0x80071664u;
    // 80071664: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071668:
    ctx->pc = 0x80071668u;
    // 80071668: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8007166C:
    ctx->pc = 0x8007166Cu;
    // 8007166C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80071670:
    ctx->pc = 0x80071670u;
    // 80071670: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_80071674:
    ctx->pc = 0x80071674u;
    // 80071674: li      r8, 2
    ctx->gpr[8] = (u32)(s32)(2);

label_80071678:
    ctx->pc = 0x80071678u;
    // 80071678: bl      0x8025C4B4
    {
            ctx->lr = 0x8007167Cu;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_8007167C:
    ctx->pc = 0x8007167Cu;
    ctx->downcount -= 7;
    // 8007167C: li      r3, 5
    ctx->gpr[3] = (u32)(s32)(5);

label_80071680:
    ctx->pc = 0x80071680u;
    // 80071680: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071684:
    ctx->pc = 0x80071684u;
    // 80071684: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80071688:
    ctx->pc = 0x80071688u;
    // 80071688: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8007168C:
    ctx->pc = 0x8007168Cu;
    // 8007168C: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_80071690:
    ctx->pc = 0x80071690u;
    // 80071690: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80071694:
    ctx->pc = 0x80071694u;
    // 80071694: bl      0x8025C574
    {
            ctx->lr = 0x80071698u;
            ctx->pc = 0x8025C574u;
            return;
    }

label_80071698:
    ctx->pc = 0x80071698u;
    ctx->downcount -= 3;
    // 80071698: li      r3, 6
    ctx->gpr[3] = (u32)(s32)(6);

label_8007169C:
    ctx->pc = 0x8007169Cu;
    // 8007169C: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_800716A0:
    ctx->pc = 0x800716A0u;
    // 800716A0: bl      0x8025C790
    {
            ctx->lr = 0x800716A4u;
            ctx->pc = 0x8025C790u;
            return;
    }

label_800716A4:
    ctx->pc = 0x800716A4u;
    ctx->downcount -= 3;
    // 800716A4: li      r3, 6
    ctx->gpr[3] = (u32)(s32)(6);

label_800716A8:
    ctx->pc = 0x800716A8u;
    // 800716A8: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_800716AC:
    ctx->pc = 0x800716ACu;
    // 800716AC: bl      0x8025C7FC
    {
            ctx->lr = 0x800716B0u;
            ctx->pc = 0x8025C7FCu;
            return;
    }

label_800716B0:
    ctx->pc = 0x800716B0u;
    ctx->downcount -= 5;
    // 800716B0: lwz     r0, -31408(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31408);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800716B4:
    ctx->pc = 0x800716B4u;
    // 800716B4: stw     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800716B8:
    ctx->pc = 0x800716B8u;
    // 800716B8: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_800716BC:
    ctx->pc = 0x800716BCu;
    // 800716BC: addi    r4, r1, 16
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(16);

label_800716C0:
    ctx->pc = 0x800716C0u;
    // 800716C0: bl      0x8025C634
    {
            ctx->lr = 0x800716C4u;
            ctx->pc = 0x8025C634u;
            return;
    }

label_800716C4:
    ctx->pc = 0x800716C4u;
    ctx->downcount -= 5;
    // 800716C4: li      r3, 6
    ctx->gpr[3] = (u32)(s32)(6);

label_800716C8:
    ctx->pc = 0x800716C8u;
    // 800716C8: li      r4, 255
    ctx->gpr[4] = (u32)(s32)(255);

label_800716CC:
    ctx->pc = 0x800716CCu;
    // 800716CC: li      r5, 255
    ctx->gpr[5] = (u32)(s32)(255);

label_800716D0:
    ctx->pc = 0x800716D0u;
    // 800716D0: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_800716D4:
    ctx->pc = 0x800716D4u;
    // 800716D4: bl      0x8025CA34
    {
            ctx->lr = 0x800716D8u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_800716D8:
    ctx->pc = 0x800716D8u;
    ctx->downcount -= 2;
    // 800716D8: li      r3, 6
    ctx->gpr[3] = (u32)(s32)(6);

label_800716DC:
    ctx->pc = 0x800716DCu;
    // 800716DC: bl      0x8025C08C
    {
            ctx->lr = 0x800716E0u;
            ctx->pc = 0x8025C08Cu;
            return;
    }

label_800716E0:
    ctx->pc = 0x800716E0u;
    ctx->downcount -= 6;
    // 800716E0: li      r3, 6
    ctx->gpr[3] = (u32)(s32)(6);

label_800716E4:
    ctx->pc = 0x800716E4u;
    // 800716E4: li      r4, 14
    ctx->gpr[4] = (u32)(s32)(14);

label_800716E8:
    ctx->pc = 0x800716E8u;
    // 800716E8: li      r5, 15
    ctx->gpr[5] = (u32)(s32)(15);

label_800716EC:
    ctx->pc = 0x800716ECu;
    // 800716EC: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800716F0:
    ctx->pc = 0x800716F0u;
    // 800716F0: li      r7, 4
    ctx->gpr[7] = (u32)(s32)(4);

label_800716F4:
    ctx->pc = 0x800716F4u;
    // 800716F4: bl      0x8025C3B0
    {
            ctx->lr = 0x800716F8u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_800716F8:
    ctx->pc = 0x800716F8u;
    ctx->downcount -= 6;
    // 800716F8: li      r3, 6
    ctx->gpr[3] = (u32)(s32)(6);

label_800716FC:
    ctx->pc = 0x800716FCu;
    // 800716FC: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_80071700:
    ctx->pc = 0x80071700u;
    // 80071700: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_80071704:
    ctx->pc = 0x80071704u;
    // 80071704: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_80071708:
    ctx->pc = 0x80071708u;
    // 80071708: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8007170C:
    ctx->pc = 0x8007170Cu;
    // 8007170C: bl      0x8025C430
    {
            ctx->lr = 0x80071710u;
            ctx->pc = 0x8025C430u;
            return;
    }

label_80071710:
    ctx->pc = 0x80071710u;
    ctx->downcount -= 4;
    // 80071710: li      r3, 6
    ctx->gpr[3] = (u32)(s32)(6);

label_80071714:
    ctx->pc = 0x80071714u;
    // 80071714: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071718:
    ctx->pc = 0x80071718u;
    // 80071718: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8007171C:
    ctx->pc = 0x8007171Cu;
    // 8007171C: bl      0x8025C868
    {
            ctx->lr = 0x80071720u;
            ctx->pc = 0x8025C868u;
            return;
    }

label_80071720:
    ctx->pc = 0x80071720u;
    ctx->downcount -= 7;
    // 80071720: li      r3, 6
    ctx->gpr[3] = (u32)(s32)(6);

label_80071724:
    ctx->pc = 0x80071724u;
    // 80071724: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071728:
    ctx->pc = 0x80071728u;
    // 80071728: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8007172C:
    ctx->pc = 0x8007172Cu;
    // 8007172C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80071730:
    ctx->pc = 0x80071730u;
    // 80071730: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_80071734:
    ctx->pc = 0x80071734u;
    // 80071734: li      r8, 2
    ctx->gpr[8] = (u32)(s32)(2);

label_80071738:
    ctx->pc = 0x80071738u;
    // 80071738: bl      0x8025C4B4
    {
            ctx->lr = 0x8007173Cu;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_8007173C:
    ctx->pc = 0x8007173Cu;
    ctx->downcount -= 7;
    // 8007173C: li      r3, 6
    ctx->gpr[3] = (u32)(s32)(6);

label_80071740:
    ctx->pc = 0x80071740u;
    // 80071740: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071744:
    ctx->pc = 0x80071744u;
    // 80071744: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80071748:
    ctx->pc = 0x80071748u;
    // 80071748: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8007174C:
    ctx->pc = 0x8007174Cu;
    // 8007174C: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_80071750:
    ctx->pc = 0x80071750u;
    // 80071750: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80071754:
    ctx->pc = 0x80071754u;
    // 80071754: bl      0x8025C574
    {
            ctx->lr = 0x80071758u;
            ctx->pc = 0x8025C574u;
            return;
    }

label_80071758:
    ctx->pc = 0x80071758u;
    ctx->downcount -= 3;
    // 80071758: li      r3, 7
    ctx->gpr[3] = (u32)(s32)(7);

label_8007175C:
    ctx->pc = 0x8007175Cu;
    // 8007175C: li      r4, 28
    ctx->gpr[4] = (u32)(s32)(28);

label_80071760:
    ctx->pc = 0x80071760u;
    // 80071760: bl      0x8025C7FC
    {
            ctx->lr = 0x80071764u;
            ctx->pc = 0x8025C7FCu;
            return;
    }

label_80071764:
    ctx->pc = 0x80071764u;
    ctx->downcount -= 2;
    // 80071764: li      r3, 7
    ctx->gpr[3] = (u32)(s32)(7);

label_80071768:
    ctx->pc = 0x80071768u;
    // 80071768: bl      0x8025C08C
    {
            ctx->lr = 0x8007176Cu;
            ctx->pc = 0x8025C08Cu;
            return;
    }

label_8007176C:
    ctx->pc = 0x8007176Cu;
    ctx->downcount -= 5;
    // 8007176C: li      r3, 7
    ctx->gpr[3] = (u32)(s32)(7);

label_80071770:
    ctx->pc = 0x80071770u;
    // 80071770: li      r4, 255
    ctx->gpr[4] = (u32)(s32)(255);

label_80071774:
    ctx->pc = 0x80071774u;
    // 80071774: li      r5, 255
    ctx->gpr[5] = (u32)(s32)(255);

label_80071778:
    ctx->pc = 0x80071778u;
    // 80071778: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_8007177C:
    ctx->pc = 0x8007177Cu;
    // 8007177C: bl      0x8025CA34
    {
            ctx->lr = 0x80071780u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_80071780:
    ctx->pc = 0x80071780u;
    ctx->downcount -= 6;
    // 80071780: li      r3, 7
    ctx->gpr[3] = (u32)(s32)(7);

label_80071784:
    ctx->pc = 0x80071784u;
    // 80071784: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_80071788:
    ctx->pc = 0x80071788u;
    // 80071788: li      r5, 2
    ctx->gpr[5] = (u32)(s32)(2);

label_8007178C:
    ctx->pc = 0x8007178Cu;
    // 8007178C: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_80071790:
    ctx->pc = 0x80071790u;
    // 80071790: li      r7, 15
    ctx->gpr[7] = (u32)(s32)(15);

label_80071794:
    ctx->pc = 0x80071794u;
    // 80071794: bl      0x8025C3B0
    {
            ctx->lr = 0x80071798u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_80071798:
    ctx->pc = 0x80071798u;
    ctx->downcount -= 6;
    // 80071798: li      r3, 7
    ctx->gpr[3] = (u32)(s32)(7);

label_8007179C:
    ctx->pc = 0x8007179Cu;
    // 8007179C: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_800717A0:
    ctx->pc = 0x800717A0u;
    // 800717A0: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_800717A4:
    ctx->pc = 0x800717A4u;
    // 800717A4: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_800717A8:
    ctx->pc = 0x800717A8u;
    // 800717A8: li      r7, 6
    ctx->gpr[7] = (u32)(s32)(6);

label_800717AC:
    ctx->pc = 0x800717ACu;
    // 800717AC: bl      0x8025C430
    {
            ctx->lr = 0x800717B0u;
            ctx->pc = 0x8025C430u;
            return;
    }

label_800717B0:
    ctx->pc = 0x800717B0u;
    ctx->downcount -= 4;
    // 800717B0: li      r3, 7
    ctx->gpr[3] = (u32)(s32)(7);

label_800717B4:
    ctx->pc = 0x800717B4u;
    // 800717B4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800717B8:
    ctx->pc = 0x800717B8u;
    // 800717B8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800717BC:
    ctx->pc = 0x800717BCu;
    // 800717BC: bl      0x8025C868
    {
            ctx->lr = 0x800717C0u;
            ctx->pc = 0x8025C868u;
            return;
    }

label_800717C0:
    ctx->pc = 0x800717C0u;
    ctx->downcount -= 7;
    // 800717C0: li      r3, 7
    ctx->gpr[3] = (u32)(s32)(7);

label_800717C4:
    ctx->pc = 0x800717C4u;
    // 800717C4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800717C8:
    ctx->pc = 0x800717C8u;
    // 800717C8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800717CC:
    ctx->pc = 0x800717CCu;
    // 800717CC: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800717D0:
    ctx->pc = 0x800717D0u;
    // 800717D0: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_800717D4:
    ctx->pc = 0x800717D4u;
    // 800717D4: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800717D8:
    ctx->pc = 0x800717D8u;
    // 800717D8: bl      0x8025C4B4
    {
            ctx->lr = 0x800717DCu;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_800717DC:
    ctx->pc = 0x800717DCu;
    ctx->downcount -= 7;
    // 800717DC: li      r3, 7
    ctx->gpr[3] = (u32)(s32)(7);

label_800717E0:
    ctx->pc = 0x800717E0u;
    // 800717E0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800717E4:
    ctx->pc = 0x800717E4u;
    // 800717E4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800717E8:
    ctx->pc = 0x800717E8u;
    // 800717E8: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800717EC:
    ctx->pc = 0x800717ECu;
    // 800717EC: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_800717F0:
    ctx->pc = 0x800717F0u;
    // 800717F0: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800717F4:
    ctx->pc = 0x800717F4u;
    // 800717F4: bl      0x8025C574
    {
            ctx->lr = 0x800717F8u;
            ctx->pc = 0x8025C574u;
            return;
    }

label_800717F8:
    ctx->pc = 0x800717F8u;
    ctx->downcount -= 2;
    // 800717F8: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_800717FC:
    ctx->pc = 0x800717FCu;
    // 800717FC: bl      0x80258B50
    {
            ctx->lr = 0x80071800u;
            ctx->pc = 0x80258B50u;
            return;
    }

label_80071800:
    ctx->pc = 0x80071800u;
    ctx->downcount -= 2;
    // 80071800: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80071804:
    ctx->pc = 0x80071804u;
    // 80071804: bl      0x8025C060
    {
            ctx->lr = 0x80071808u;
            ctx->pc = 0x8025C060u;
            return;
    }

label_80071808:
    ctx->pc = 0x80071808u;
    ctx->downcount -= 8;
    // 80071808: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_8007180C:
    ctx->pc = 0x8007180Cu;
    // 8007180C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071810:
    ctx->pc = 0x80071810u;
    // 80071810: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80071814:
    ctx->pc = 0x80071814u;
    // 80071814: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80071818:
    ctx->pc = 0x80071818u;
    // 80071818: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8007181C:
    ctx->pc = 0x8007181Cu;
    // 8007181C: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80071820:
    ctx->pc = 0x80071820u;
    // 80071820: li      r9, 2
    ctx->gpr[9] = (u32)(s32)(2);

label_80071824:
    ctx->pc = 0x80071824u;
    // 80071824: bl      0x8025A814
    {
            ctx->lr = 0x80071828u;
            ctx->pc = 0x8025A814u;
            return;
    }

label_80071828:
    ctx->pc = 0x80071828u;
    ctx->downcount -= 8;
    // 80071828: li      r3, 5
    ctx->gpr[3] = (u32)(s32)(5);

label_8007182C:
    ctx->pc = 0x8007182Cu;
    // 8007182C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071830:
    ctx->pc = 0x80071830u;
    // 80071830: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80071834:
    ctx->pc = 0x80071834u;
    // 80071834: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80071838:
    ctx->pc = 0x80071838u;
    // 80071838: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8007183C:
    ctx->pc = 0x8007183Cu;
    // 8007183C: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80071840:
    ctx->pc = 0x80071840u;
    // 80071840: li      r9, 2
    ctx->gpr[9] = (u32)(s32)(2);

label_80071844:
    ctx->pc = 0x80071844u;
    // 80071844: bl      0x8025A814
    {
            ctx->lr = 0x80071848u;
            ctx->pc = 0x8025A814u;
            return;
    }

label_80071848:
    ctx->pc = 0x80071848u;
    ctx->downcount -= 2;
    // 80071848: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8007184C:
    ctx->pc = 0x8007184Cu;
    // 8007184C: bl      0x8025A7C8
    {
            ctx->lr = 0x80071850u;
            ctx->pc = 0x8025A7C8u;
            return;
    }

label_80071850:
    ctx->pc = 0x80071850u;
    ctx->downcount -= 2;
    // 80071850: li      r3, 8
    ctx->gpr[3] = (u32)(s32)(8);

label_80071854:
    ctx->pc = 0x80071854u;
    // 80071854: bl      0x8025CC10
    {
            ctx->lr = 0x80071858u;
            ctx->pc = 0x8025CC10u;
            return;
    }

label_80071858:
    ctx->pc = 0x80071858u;
    ctx->downcount -= 1;
    // 80071858: bl      0x80257D68
    {
            ctx->lr = 0x8007185Cu;
            ctx->pc = 0x80257D68u;
            return;
    }

label_8007185C:
    ctx->pc = 0x8007185Cu;
    ctx->downcount -= 3;
    // 8007185C: li      r3, 9
    ctx->gpr[3] = (u32)(s32)(9);

label_80071860:
    ctx->pc = 0x80071860u;
    // 80071860: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80071864:
    ctx->pc = 0x80071864u;
    // 80071864: bl      0x802572E8
    {
            ctx->lr = 0x80071868u;
            ctx->pc = 0x802572E8u;
            return;
    }

label_80071868:
    ctx->pc = 0x80071868u;
    ctx->downcount -= 3;
    // 80071868: li      r3, 13
    ctx->gpr[3] = (u32)(s32)(13);

label_8007186C:
    ctx->pc = 0x8007186Cu;
    // 8007186C: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80071870:
    ctx->pc = 0x80071870u;
    // 80071870: bl      0x802572E8
    {
            ctx->lr = 0x80071874u;
            ctx->pc = 0x802572E8u;
            return;
    }

label_80071874:
    ctx->pc = 0x80071874u;
    ctx->downcount -= 2;
    // 80071874: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80071878:
    ctx->pc = 0x80071878u;
    // 80071878: bl      0x80259494
    {
            ctx->lr = 0x8007187Cu;
            ctx->pc = 0x80259494u;
            return;
    }

label_8007187C:
    ctx->pc = 0x8007187Cu;
    ctx->downcount -= 5;
    // 8007187C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80071880:
    ctx->pc = 0x80071880u;
    // 80071880: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_80071884:
    ctx->pc = 0x80071884u;
    // 80071884: li      r5, 5
    ctx->gpr[5] = (u32)(s32)(5);

label_80071888:
    ctx->pc = 0x80071888u;
    // 80071888: li      r6, 5
    ctx->gpr[6] = (u32)(s32)(5);

label_8007188C:
    ctx->pc = 0x8007188Cu;
    // 8007188C: bl      0x8025CEF4
    {
            ctx->lr = 0x80071890u;
            ctx->pc = 0x8025CEF4u;
            return;
    }

label_80071890:
    ctx->pc = 0x80071890u;
    ctx->downcount -= 3;
    // 80071890: lbz     r0, -24944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24944);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80071894:
    ctx->pc = 0x80071894u;
    // 80071894: cmplwi  r0, 0x0000
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

label_80071898:
    ctx->pc = 0x80071898u;
    // 80071898: bc    4, 2, 0x800718C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800718C0;
        }
    }

label_8007189C:
    ctx->pc = 0x8007189Cu;
    ctx->downcount -= 3;
    // 8007189C: lwz     r0, -24948(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24948);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800718A0:
    ctx->pc = 0x800718A0u;
    // 800718A0: cmpwi   r0, 7
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(7);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800718A4:
    ctx->pc = 0x800718A4u;
    // 800718A4: bc    4, 2, 0x800718C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800718C0;
        }
    }

label_800718A8:
    ctx->pc = 0x800718A8u;
    ctx->downcount -= 3;
    // 800718A8: lbz     r0, -24950(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24950);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_800718AC:
    ctx->pc = 0x800718ACu;
    // 800718AC: cmplwi  r0, 0x0000
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

label_800718B0:
    ctx->pc = 0x800718B0u;
    // 800718B0: bc    4, 2, 0x800718C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800718C0;
        }
    }

label_800718B4:
    ctx->pc = 0x800718B4u;
    ctx->downcount -= 3;
    // 800718B4: lbz     r0, -24942(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24942);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_800718B8:
    ctx->pc = 0x800718B8u;
    // 800718B8: cmplwi  r0, 0x0000
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

label_800718BC:
    ctx->pc = 0x800718BCu;
    // 800718BC: bc    4, 2, 0x800718EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800718EC;
        }
    }

label_800718C0:
    ctx->pc = 0x800718C0u;
    ctx->downcount -= 4;
    // 800718C0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800718C4:
    ctx->pc = 0x800718C4u;
    // 800718C4: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_800718C8:
    ctx->pc = 0x800718C8u;
    // 800718C8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800718CC:
    ctx->pc = 0x800718CCu;
    // 800718CC: bl      0x8025D078
    {
            ctx->lr = 0x800718D0u;
            ctx->pc = 0x8025D078u;
            return;
    }

label_800718D0:
    ctx->pc = 0x800718D0u;
    ctx->downcount -= 7;
    // 800718D0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800718D4:
    ctx->pc = 0x800718D4u;
    // 800718D4: stb     r3, -24944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24944);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_800718D8:
    ctx->pc = 0x800718D8u;
    // 800718D8: li      r0, 7
    ctx->gpr[0] = (u32)(s32)(7);

label_800718DC:
    ctx->pc = 0x800718DCu;
    // 800718DC: stw     r0, -24948(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24948);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800718E0:
    ctx->pc = 0x800718E0u;
    // 800718E0: stb     r3, -24950(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24950);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_800718E4:
    ctx->pc = 0x800718E4u;
    // 800718E4: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_800718E8:
    ctx->pc = 0x800718E8u;
    // 800718E8: stb     r0, -24942(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24942);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_800718EC:
    ctx->pc = 0x800718ECu;
    ctx->downcount -= 3;
    // 800718EC: lbz     r0, -24951(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24951);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_800718F0:
    ctx->pc = 0x800718F0u;
    // 800718F0: cmplwi  r0, 0x0001
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0001u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800718F4:
    ctx->pc = 0x800718F4u;
    // 800718F4: bc    4, 2, 0x80071904
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80071904;
        }
    }

label_800718F8:
    ctx->pc = 0x800718F8u;
    ctx->downcount -= 3;
    // 800718F8: lbz     r0, -24943(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24943);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_800718FC:
    ctx->pc = 0x800718FCu;
    // 800718FC: cmplwi  r0, 0x0000
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

label_80071900:
    ctx->pc = 0x80071900u;
    // 80071900: bc    4, 2, 0x80071918
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80071918;
        }
    }

label_80071904:
    ctx->pc = 0x80071904u;
    ctx->downcount -= 2;
    // 80071904: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80071908:
    ctx->pc = 0x80071908u;
    // 80071908: bl      0x8025D0F0
    {
            ctx->lr = 0x8007190Cu;
            ctx->pc = 0x8025D0F0u;
            return;
    }

label_8007190C:
    ctx->pc = 0x8007190Cu;
    ctx->downcount -= 3;
    // 8007190C: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80071910:
    ctx->pc = 0x80071910u;
    // 80071910: stb     r0, -24951(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24951);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80071914:
    ctx->pc = 0x80071914u;
    // 80071914: stb     r0, -24943(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24943);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80071918:
    ctx->pc = 0x80071918u;
    ctx->downcount -= 6;
    // 80071918: li      r3, 7
    ctx->gpr[3] = (u32)(s32)(7);

label_8007191C:
    ctx->pc = 0x8007191Cu;
    // 8007191C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071920:
    ctx->pc = 0x80071920u;
    // 80071920: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80071924:
    ctx->pc = 0x80071924u;
    // 80071924: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_80071928:
    ctx->pc = 0x80071928u;
    // 80071928: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8007192C:
    ctx->pc = 0x8007192Cu;
    // 8007192C: bl      0x8025C960
    {
            ctx->lr = 0x80071930u;
            ctx->pc = 0x8025C960u;
            return;
    }

label_80071930:
    ctx->pc = 0x80071930u;
    ctx->downcount -= 4;
    // 80071930: lis     r3, -32710
    ctx->gpr[3] = ((u32)(s32)(-32710) << 16);

label_80071934:
    ctx->pc = 0x80071934u;
    // 80071934: addi    r3, r3, -32288
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-32288);

label_80071938:
    ctx->pc = 0x80071938u;
    // 80071938: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8007193C:
    ctx->pc = 0x8007193Cu;
    // 8007193C: bl      0x8025D8B8
    {
            ctx->lr = 0x80071940u;
            ctx->pc = 0x8025D8B8u;
            return;
    }

label_80071940:
    ctx->pc = 0x80071940u;
    ctx->downcount -= 2;
    // 80071940: li      r3, 60
    ctx->gpr[3] = (u32)(s32)(60);

label_80071944:
    ctx->pc = 0x80071944u;
    // 80071944: bl      0x8025DA94
    {
            ctx->lr = 0x80071948u;
            ctx->pc = 0x8025DA94u;
            return;
    }

label_80071948:
    ctx->pc = 0x80071948u;
    ctx->downcount -= 4;
    // 80071948: li      r3, 128
    ctx->gpr[3] = (u32)(s32)(128);

label_8007194C:
    ctx->pc = 0x8007194Cu;
    // 8007194C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071950:
    ctx->pc = 0x80071950u;
    // 80071950: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_80071954:
    ctx->pc = 0x80071954u;
    // 80071954: bl      0x8025920C
    {
            ctx->lr = 0x80071958u;
            ctx->pc = 0x8025920Cu;
            return;
    }

label_80071958:
    ctx->pc = 0x80071958u;
    ctx->downcount -= 27;
    // 80071958: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8007195C:
    ctx->pc = 0x8007195Cu;
    // 8007195C: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_80071960:
    ctx->pc = 0x80071960u;
    // 80071960: sth     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_80071964:
    ctx->pc = 0x80071964u;
    // 80071964: sth     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_80071968:
    ctx->pc = 0x80071968u;
    // 80071968: li      r4, -8
    ctx->gpr[4] = (u32)(s32)(-8);

label_8007196C:
    ctx->pc = 0x8007196Cu;
    // 8007196C: sth     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_80071970:
    ctx->pc = 0x80071970u;
    // 80071970: sth     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_80071974:
    ctx->pc = 0x80071974u;
    // 80071974: sth     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_80071978:
    ctx->pc = 0x80071978u;
    // 80071978: li      r0, 640
    ctx->gpr[0] = (u32)(s32)(640);

label_8007197C:
    ctx->pc = 0x8007197Cu;
    // 8007197C: sth     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80071980:
    ctx->pc = 0x80071980u;
    // 80071980: sth     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_80071984:
    ctx->pc = 0x80071984u;
    // 80071984: sth     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_80071988:
    ctx->pc = 0x80071988u;
    // 80071988: li      r3, 128
    ctx->gpr[3] = (u32)(s32)(128);

label_8007198C:
    ctx->pc = 0x8007198Cu;
    // 8007198C: sth     r3, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_80071990:
    ctx->pc = 0x80071990u;
    // 80071990: sth     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_80071994:
    ctx->pc = 0x80071994u;
    // 80071994: sth     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80071998:
    ctx->pc = 0x80071998u;
    // 80071998: li      r0, 480
    ctx->gpr[0] = (u32)(s32)(480);

label_8007199C:
    ctx->pc = 0x8007199Cu;
    // 8007199C: sth     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_800719A0:
    ctx->pc = 0x800719A0u;
    // 800719A0: sth     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_800719A4:
    ctx->pc = 0x800719A4u;
    // 800719A4: sth     r3, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_800719A8:
    ctx->pc = 0x800719A8u;
    // 800719A8: sth     r3, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_800719AC:
    ctx->pc = 0x800719ACu;
    // 800719AC: sth     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_800719B0:
    ctx->pc = 0x800719B0u;
    // 800719B0: sth     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_800719B4:
    ctx->pc = 0x800719B4u;
    // 800719B4: sth     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_800719B8:
    ctx->pc = 0x800719B8u;
    // 800719B8: sth     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_800719BC:
    ctx->pc = 0x800719BCu;
    // 800719BC: sth     r3, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_800719C0:
    ctx->pc = 0x800719C0u;
    // 800719C0: bl      0x8000FB20
    {
            ctx->lr = 0x800719C4u;
            ctx->pc = 0x8000FB20u;
            return;
    }

label_800719C4:
    ctx->pc = 0x800719C4u;
    ctx->downcount -= 2;
    // 800719C4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800719C8:
    ctx->pc = 0x800719C8u;
    // 800719C8: bl      0x8025DA94
    {
            ctx->lr = 0x800719CCu;
            ctx->pc = 0x8025DA94u;
            return;
    }

label_800719CC:
    ctx->pc = 0x800719CCu;
    ctx->downcount -= 6;
    // 800719CC: lwz     r31, 156(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(156);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_800719D0:
    ctx->pc = 0x800719D0u;
    // 800719D0: lwz     r0, 164(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(164);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800719D4:
    ctx->pc = 0x800719D4u;
    // 800719D4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800719D8:
    ctx->pc = 0x800719D8u;
    // 800719D8: addi    r1, r1, 160
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(160);

label_800719DC:
    ctx->pc = 0x800719DCu;
    // 800719DC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_800719E0:
    ctx->pc = 0x800719E0u;
    ctx->downcount -= 4;
    // 800719E0: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800719E4:
    ctx->pc = 0x800719E4u;
    // 800719E4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800719E8:
    ctx->pc = 0x800719E8u;
    // 800719E8: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800719EC:
    ctx->pc = 0x800719ECu;
    // 800719EC: bl      0x8006CA14
    {
            ctx->lr = 0x800719F0u;
            ctx->pc = 0x8006CA14u;
            return;
    }

label_800719F0:
    ctx->pc = 0x800719F0u;
    ctx->downcount -= 2;
    // 800719F0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800719F4:
    ctx->pc = 0x800719F4u;
    // 800719F4: bl      0x8006C8D4
    {
            ctx->lr = 0x800719F8u;
            ctx->pc = 0x8006C8D4u;
            return;
    }

label_800719F8:
    ctx->pc = 0x800719F8u;
    ctx->downcount -= 6;
    // 800719F8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800719FC:
    ctx->pc = 0x800719FCu;
    // 800719FC: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80071A00:
    ctx->pc = 0x80071A00u;
    // 80071A00: li      r5, 2
    ctx->gpr[5] = (u32)(s32)(2);

label_80071A04:
    ctx->pc = 0x80071A04u;
    // 80071A04: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80071A08:
    ctx->pc = 0x80071A08u;
    // 80071A08: li      r7, 3
    ctx->gpr[7] = (u32)(s32)(3);

label_80071A0C:
    ctx->pc = 0x80071A0Cu;
    // 80071A0C: bl      0x8025C8C0
    {
            ctx->lr = 0x80071A10u;
            ctx->pc = 0x8025C8C0u;
            return;
    }

label_80071A10:
    ctx->pc = 0x80071A10u;
    ctx->downcount -= 6;
    // 80071A10: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80071A14:
    ctx->pc = 0x80071A14u;
    // 80071A14: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071A18:
    ctx->pc = 0x80071A18u;
    // 80071A18: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80071A1C:
    ctx->pc = 0x80071A1Cu;
    // 80071A1C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80071A20:
    ctx->pc = 0x80071A20u;
    // 80071A20: li      r7, 3
    ctx->gpr[7] = (u32)(s32)(3);

label_80071A24:
    ctx->pc = 0x80071A24u;
    // 80071A24: bl      0x8025C8C0
    {
            ctx->lr = 0x80071A28u;
            ctx->pc = 0x8025C8C0u;
            return;
    }

label_80071A28:
    ctx->pc = 0x80071A28u;
    ctx->downcount -= 6;
    // 80071A28: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80071A2C:
    ctx->pc = 0x80071A2Cu;
    // 80071A2C: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80071A30:
    ctx->pc = 0x80071A30u;
    // 80071A30: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80071A34:
    ctx->pc = 0x80071A34u;
    // 80071A34: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_80071A38:
    ctx->pc = 0x80071A38u;
    // 80071A38: li      r7, 3
    ctx->gpr[7] = (u32)(s32)(3);

label_80071A3C:
    ctx->pc = 0x80071A3Cu;
    // 80071A3C: bl      0x8025C8C0
    {
            ctx->lr = 0x80071A40u;
            ctx->pc = 0x8025C8C0u;
            return;
    }

label_80071A40:
    ctx->pc = 0x80071A40u;
    ctx->downcount -= 6;
    // 80071A40: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_80071A44:
    ctx->pc = 0x80071A44u;
    // 80071A44: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80071A48:
    ctx->pc = 0x80071A48u;
    // 80071A48: li      r5, 2
    ctx->gpr[5] = (u32)(s32)(2);

label_80071A4C:
    ctx->pc = 0x80071A4Cu;
    // 80071A4C: li      r6, 2
    ctx->gpr[6] = (u32)(s32)(2);

label_80071A50:
    ctx->pc = 0x80071A50u;
    // 80071A50: li      r7, 3
    ctx->gpr[7] = (u32)(s32)(3);

label_80071A54:
    ctx->pc = 0x80071A54u;
    // 80071A54: bl      0x8025C8C0
    {
            ctx->lr = 0x80071A58u;
            ctx->pc = 0x8025C8C0u;
            return;
    }

label_80071A58:
    ctx->pc = 0x80071A58u;
    ctx->downcount -= 7;
    // 80071A58: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80071A5C:
    ctx->pc = 0x80071A5Cu;
    // 80071A5C: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80071A60:
    ctx->pc = 0x80071A60u;
    // 80071A60: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_80071A64:
    ctx->pc = 0x80071A64u;
    // 80071A64: li      r6, 60
    ctx->gpr[6] = (u32)(s32)(60);

label_80071A68:
    ctx->pc = 0x80071A68u;
    // 80071A68: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80071A6C:
    ctx->pc = 0x80071A6Cu;
    // 80071A6C: li      r8, 125
    ctx->gpr[8] = (u32)(s32)(125);

label_80071A70:
    ctx->pc = 0x80071A70u;
    // 80071A70: bl      0x80258880
    {
            ctx->lr = 0x80071A74u;
            ctx->pc = 0x80258880u;
            return;
    }

label_80071A74:
    ctx->pc = 0x80071A74u;
    ctx->downcount -= 5;
    // 80071A74: lwz     r0, -31424(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31424);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80071A78:
    ctx->pc = 0x80071A78u;
    // 80071A78: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80071A7C:
    ctx->pc = 0x80071A7Cu;
    // 80071A7C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80071A80:
    ctx->pc = 0x80071A80u;
    // 80071A80: addi    r4, r1, 20
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(20);

label_80071A84:
    ctx->pc = 0x80071A84u;
    // 80071A84: bl      0x8025C71C
    {
            ctx->lr = 0x80071A88u;
            ctx->pc = 0x8025C71Cu;
            return;
    }

label_80071A88:
    ctx->pc = 0x80071A88u;
    ctx->downcount -= 5;
    // 80071A88: lwz     r0, -31420(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31420);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80071A8C:
    ctx->pc = 0x80071A8Cu;
    // 80071A8C: stw     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80071A90:
    ctx->pc = 0x80071A90u;
    // 80071A90: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80071A94:
    ctx->pc = 0x80071A94u;
    // 80071A94: addi    r4, r1, 16
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(16);

label_80071A98:
    ctx->pc = 0x80071A98u;
    // 80071A98: bl      0x8025C71C
    {
            ctx->lr = 0x80071A9Cu;
            ctx->pc = 0x8025C71Cu;
            return;
    }

label_80071A9C:
    ctx->pc = 0x80071A9Cu;
    ctx->downcount -= 5;
    // 80071A9C: lwz     r0, -31416(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31416);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80071AA0:
    ctx->pc = 0x80071AA0u;
    // 80071AA0: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80071AA4:
    ctx->pc = 0x80071AA4u;
    // 80071AA4: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80071AA8:
    ctx->pc = 0x80071AA8u;
    // 80071AA8: addi    r4, r1, 12
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(12);

label_80071AAC:
    ctx->pc = 0x80071AACu;
    // 80071AAC: bl      0x8025C71C
    {
            ctx->lr = 0x80071AB0u;
            ctx->pc = 0x8025C71Cu;
            return;
    }

label_80071AB0:
    ctx->pc = 0x80071AB0u;
    ctx->downcount -= 5;
    // 80071AB0: lwz     r0, -31412(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31412);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80071AB4:
    ctx->pc = 0x80071AB4u;
    // 80071AB4: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80071AB8:
    ctx->pc = 0x80071AB8u;
    // 80071AB8: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80071ABC:
    ctx->pc = 0x80071ABCu;
    // 80071ABC: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_80071AC0:
    ctx->pc = 0x80071AC0u;
    // 80071AC0: bl      0x8025C634
    {
            ctx->lr = 0x80071AC4u;
            ctx->pc = 0x8025C634u;
            return;
    }

label_80071AC4:
    ctx->pc = 0x80071AC4u;
    ctx->downcount -= 2;
    // 80071AC4: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80071AC8:
    ctx->pc = 0x80071AC8u;
    // 80071AC8: bl      0x80258B50
    {
            ctx->lr = 0x80071ACCu;
            ctx->pc = 0x80258B50u;
            return;
    }

label_80071ACC:
    ctx->pc = 0x80071ACCu;
    ctx->downcount -= 2;
    // 80071ACC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80071AD0:
    ctx->pc = 0x80071AD0u;
    // 80071AD0: bl      0x8025C060
    {
            ctx->lr = 0x80071AD4u;
            ctx->pc = 0x8025C060u;
            return;
    }

label_80071AD4:
    ctx->pc = 0x80071AD4u;
    ctx->downcount -= 8;
    // 80071AD4: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_80071AD8:
    ctx->pc = 0x80071AD8u;
    // 80071AD8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071ADC:
    ctx->pc = 0x80071ADCu;
    // 80071ADC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80071AE0:
    ctx->pc = 0x80071AE0u;
    // 80071AE0: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80071AE4:
    ctx->pc = 0x80071AE4u;
    // 80071AE4: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80071AE8:
    ctx->pc = 0x80071AE8u;
    // 80071AE8: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80071AEC:
    ctx->pc = 0x80071AECu;
    // 80071AEC: li      r9, 2
    ctx->gpr[9] = (u32)(s32)(2);

label_80071AF0:
    ctx->pc = 0x80071AF0u;
    // 80071AF0: bl      0x8025A814
    {
            ctx->lr = 0x80071AF4u;
            ctx->pc = 0x8025A814u;
            return;
    }

label_80071AF4:
    ctx->pc = 0x80071AF4u;
    ctx->downcount -= 8;
    // 80071AF4: li      r3, 5
    ctx->gpr[3] = (u32)(s32)(5);

label_80071AF8:
    ctx->pc = 0x80071AF8u;
    // 80071AF8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071AFC:
    ctx->pc = 0x80071AFCu;
    // 80071AFC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80071B00:
    ctx->pc = 0x80071B00u;
    // 80071B00: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80071B04:
    ctx->pc = 0x80071B04u;
    // 80071B04: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80071B08:
    ctx->pc = 0x80071B08u;
    // 80071B08: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80071B0C:
    ctx->pc = 0x80071B0Cu;
    // 80071B0C: li      r9, 2
    ctx->gpr[9] = (u32)(s32)(2);

label_80071B10:
    ctx->pc = 0x80071B10u;
    // 80071B10: bl      0x8025A814
    {
            ctx->lr = 0x80071B14u;
            ctx->pc = 0x8025A814u;
            return;
    }

label_80071B14:
    ctx->pc = 0x80071B14u;
    ctx->downcount -= 2;
    // 80071B14: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80071B18:
    ctx->pc = 0x80071B18u;
    // 80071B18: bl      0x8025A7C8
    {
            ctx->lr = 0x80071B1Cu;
            ctx->pc = 0x8025A7C8u;
            return;
    }

label_80071B1C:
    ctx->pc = 0x80071B1Cu;
    ctx->downcount -= 2;
    // 80071B1C: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_80071B20:
    ctx->pc = 0x80071B20u;
    // 80071B20: bl      0x8025CC10
    {
            ctx->lr = 0x80071B24u;
            ctx->pc = 0x8025CC10u;
            return;
    }

label_80071B24:
    ctx->pc = 0x80071B24u;
    ctx->downcount -= 3;
    // 80071B24: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80071B28:
    ctx->pc = 0x80071B28u;
    // 80071B28: li      r4, 12
    ctx->gpr[4] = (u32)(s32)(12);

label_80071B2C:
    ctx->pc = 0x80071B2Cu;
    // 80071B2C: bl      0x8025C790
    {
            ctx->lr = 0x80071B30u;
            ctx->pc = 0x8025C790u;
            return;
    }

label_80071B30:
    ctx->pc = 0x80071B30u;
    ctx->downcount -= 2;
    // 80071B30: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80071B34:
    ctx->pc = 0x80071B34u;
    // 80071B34: bl      0x8025C08C
    {
            ctx->lr = 0x80071B38u;
            ctx->pc = 0x8025C08Cu;
            return;
    }

label_80071B38:
    ctx->pc = 0x80071B38u;
    ctx->downcount -= 5;
    // 80071B38: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80071B3C:
    ctx->pc = 0x80071B3Cu;
    // 80071B3C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071B40:
    ctx->pc = 0x80071B40u;
    // 80071B40: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80071B44:
    ctx->pc = 0x80071B44u;
    // 80071B44: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_80071B48:
    ctx->pc = 0x80071B48u;
    // 80071B48: bl      0x8025CA34
    {
            ctx->lr = 0x80071B4Cu;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_80071B4C:
    ctx->pc = 0x80071B4Cu;
    ctx->downcount -= 6;
    // 80071B4C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80071B50:
    ctx->pc = 0x80071B50u;
    // 80071B50: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_80071B54:
    ctx->pc = 0x80071B54u;
    // 80071B54: li      r5, 8
    ctx->gpr[5] = (u32)(s32)(8);

label_80071B58:
    ctx->pc = 0x80071B58u;
    // 80071B58: li      r6, 14
    ctx->gpr[6] = (u32)(s32)(14);

label_80071B5C:
    ctx->pc = 0x80071B5Cu;
    // 80071B5C: li      r7, 2
    ctx->gpr[7] = (u32)(s32)(2);

label_80071B60:
    ctx->pc = 0x80071B60u;
    // 80071B60: bl      0x8025C3B0
    {
            ctx->lr = 0x80071B64u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_80071B64:
    ctx->pc = 0x80071B64u;
    ctx->downcount -= 6;
    // 80071B64: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80071B68:
    ctx->pc = 0x80071B68u;
    // 80071B68: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_80071B6C:
    ctx->pc = 0x80071B6Cu;
    // 80071B6C: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_80071B70:
    ctx->pc = 0x80071B70u;
    // 80071B70: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_80071B74:
    ctx->pc = 0x80071B74u;
    // 80071B74: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_80071B78:
    ctx->pc = 0x80071B78u;
    // 80071B78: bl      0x8025C430
    {
            ctx->lr = 0x80071B7Cu;
            ctx->pc = 0x8025C430u;
            return;
    }

label_80071B7C:
    ctx->pc = 0x80071B7Cu;
    ctx->downcount -= 4;
    // 80071B7C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80071B80:
    ctx->pc = 0x80071B80u;
    // 80071B80: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071B84:
    ctx->pc = 0x80071B84u;
    // 80071B84: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80071B88:
    ctx->pc = 0x80071B88u;
    // 80071B88: bl      0x8025C868
    {
            ctx->lr = 0x80071B8Cu;
            ctx->pc = 0x8025C868u;
            return;
    }

label_80071B8C:
    ctx->pc = 0x80071B8Cu;
    ctx->downcount -= 7;
    // 80071B8C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80071B90:
    ctx->pc = 0x80071B90u;
    // 80071B90: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071B94:
    ctx->pc = 0x80071B94u;
    // 80071B94: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80071B98:
    ctx->pc = 0x80071B98u;
    // 80071B98: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80071B9C:
    ctx->pc = 0x80071B9Cu;
    // 80071B9C: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_80071BA0:
    ctx->pc = 0x80071BA0u;
    // 80071BA0: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80071BA4:
    ctx->pc = 0x80071BA4u;
    // 80071BA4: bl      0x8025C4B4
    {
            ctx->lr = 0x80071BA8u;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_80071BA8:
    ctx->pc = 0x80071BA8u;
    ctx->downcount -= 7;
    // 80071BA8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80071BAC:
    ctx->pc = 0x80071BACu;
    // 80071BAC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071BB0:
    ctx->pc = 0x80071BB0u;
    // 80071BB0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80071BB4:
    ctx->pc = 0x80071BB4u;
    // 80071BB4: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80071BB8:
    ctx->pc = 0x80071BB8u;
    // 80071BB8: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_80071BBC:
    ctx->pc = 0x80071BBCu;
    // 80071BBC: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80071BC0:
    ctx->pc = 0x80071BC0u;
    // 80071BC0: bl      0x8025C574
    {
            ctx->lr = 0x80071BC4u;
            ctx->pc = 0x8025C574u;
            return;
    }

label_80071BC4:
    ctx->pc = 0x80071BC4u;
    ctx->downcount -= 3;
    // 80071BC4: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80071BC8:
    ctx->pc = 0x80071BC8u;
    // 80071BC8: li      r4, 13
    ctx->gpr[4] = (u32)(s32)(13);

label_80071BCC:
    ctx->pc = 0x80071BCCu;
    // 80071BCC: bl      0x8025C790
    {
            ctx->lr = 0x80071BD0u;
            ctx->pc = 0x8025C790u;
            return;
    }

label_80071BD0:
    ctx->pc = 0x80071BD0u;
    ctx->downcount -= 3;
    // 80071BD0: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80071BD4:
    ctx->pc = 0x80071BD4u;
    // 80071BD4: li      r4, 29
    ctx->gpr[4] = (u32)(s32)(29);

label_80071BD8:
    ctx->pc = 0x80071BD8u;
    // 80071BD8: bl      0x8025C7FC
    {
            ctx->lr = 0x80071BDCu;
            ctx->pc = 0x8025C7FCu;
            return;
    }

label_80071BDC:
    ctx->pc = 0x80071BDCu;
    ctx->downcount -= 2;
    // 80071BDC: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80071BE0:
    ctx->pc = 0x80071BE0u;
    // 80071BE0: bl      0x8025C08C
    {
            ctx->lr = 0x80071BE4u;
            ctx->pc = 0x8025C08Cu;
            return;
    }

label_80071BE4:
    ctx->pc = 0x80071BE4u;
    ctx->downcount -= 5;
    // 80071BE4: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80071BE8:
    ctx->pc = 0x80071BE8u;
    // 80071BE8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071BEC:
    ctx->pc = 0x80071BECu;
    // 80071BEC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80071BF0:
    ctx->pc = 0x80071BF0u;
    // 80071BF0: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_80071BF4:
    ctx->pc = 0x80071BF4u;
    // 80071BF4: bl      0x8025CA34
    {
            ctx->lr = 0x80071BF8u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_80071BF8:
    ctx->pc = 0x80071BF8u;
    ctx->downcount -= 6;
    // 80071BF8: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80071BFC:
    ctx->pc = 0x80071BFCu;
    // 80071BFC: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_80071C00:
    ctx->pc = 0x80071C00u;
    // 80071C00: li      r5, 8
    ctx->gpr[5] = (u32)(s32)(8);

label_80071C04:
    ctx->pc = 0x80071C04u;
    // 80071C04: li      r6, 14
    ctx->gpr[6] = (u32)(s32)(14);

label_80071C08:
    ctx->pc = 0x80071C08u;
    // 80071C08: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80071C0C:
    ctx->pc = 0x80071C0Cu;
    // 80071C0C: bl      0x8025C3B0
    {
            ctx->lr = 0x80071C10u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_80071C10:
    ctx->pc = 0x80071C10u;
    ctx->downcount -= 6;
    // 80071C10: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80071C14:
    ctx->pc = 0x80071C14u;
    // 80071C14: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_80071C18:
    ctx->pc = 0x80071C18u;
    // 80071C18: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_80071C1C:
    ctx->pc = 0x80071C1Cu;
    // 80071C1C: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_80071C20:
    ctx->pc = 0x80071C20u;
    // 80071C20: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80071C24:
    ctx->pc = 0x80071C24u;
    // 80071C24: bl      0x8025C430
    {
            ctx->lr = 0x80071C28u;
            ctx->pc = 0x8025C430u;
            return;
    }

label_80071C28:
    ctx->pc = 0x80071C28u;
    ctx->downcount -= 4;
    // 80071C28: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80071C2C:
    ctx->pc = 0x80071C2Cu;
    // 80071C2C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071C30:
    ctx->pc = 0x80071C30u;
    // 80071C30: li      r5, 2
    ctx->gpr[5] = (u32)(s32)(2);

label_80071C34:
    ctx->pc = 0x80071C34u;
    // 80071C34: bl      0x8025C868
    {
            ctx->lr = 0x80071C38u;
            ctx->pc = 0x8025C868u;
            return;
    }

label_80071C38:
    ctx->pc = 0x80071C38u;
    ctx->downcount -= 7;
    // 80071C38: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80071C3C:
    ctx->pc = 0x80071C3Cu;
    // 80071C3C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071C40:
    ctx->pc = 0x80071C40u;
    // 80071C40: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80071C44:
    ctx->pc = 0x80071C44u;
    // 80071C44: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80071C48:
    ctx->pc = 0x80071C48u;
    // 80071C48: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_80071C4C:
    ctx->pc = 0x80071C4Cu;
    // 80071C4C: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80071C50:
    ctx->pc = 0x80071C50u;
    // 80071C50: bl      0x8025C4B4
    {
            ctx->lr = 0x80071C54u;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_80071C54:
    ctx->pc = 0x80071C54u;
    ctx->downcount -= 7;
    // 80071C54: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80071C58:
    ctx->pc = 0x80071C58u;
    // 80071C58: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071C5C:
    ctx->pc = 0x80071C5Cu;
    // 80071C5C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80071C60:
    ctx->pc = 0x80071C60u;
    // 80071C60: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80071C64:
    ctx->pc = 0x80071C64u;
    // 80071C64: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_80071C68:
    ctx->pc = 0x80071C68u;
    // 80071C68: li      r8, 3
    ctx->gpr[8] = (u32)(s32)(3);

label_80071C6C:
    ctx->pc = 0x80071C6Cu;
    // 80071C6C: bl      0x8025C574
    {
            ctx->lr = 0x80071C70u;
            ctx->pc = 0x8025C574u;
            return;
    }

label_80071C70:
    ctx->pc = 0x80071C70u;
    ctx->downcount -= 3;
    // 80071C70: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80071C74:
    ctx->pc = 0x80071C74u;
    // 80071C74: li      r4, 14
    ctx->gpr[4] = (u32)(s32)(14);

label_80071C78:
    ctx->pc = 0x80071C78u;
    // 80071C78: bl      0x8025C790
    {
            ctx->lr = 0x80071C7Cu;
            ctx->pc = 0x8025C790u;
            return;
    }

label_80071C7C:
    ctx->pc = 0x80071C7Cu;
    ctx->downcount -= 2;
    // 80071C7C: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80071C80:
    ctx->pc = 0x80071C80u;
    // 80071C80: bl      0x8025C08C
    {
            ctx->lr = 0x80071C84u;
            ctx->pc = 0x8025C08Cu;
            return;
    }

label_80071C84:
    ctx->pc = 0x80071C84u;
    ctx->downcount -= 5;
    // 80071C84: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80071C88:
    ctx->pc = 0x80071C88u;
    // 80071C88: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071C8C:
    ctx->pc = 0x80071C8Cu;
    // 80071C8C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80071C90:
    ctx->pc = 0x80071C90u;
    // 80071C90: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_80071C94:
    ctx->pc = 0x80071C94u;
    // 80071C94: bl      0x8025CA34
    {
            ctx->lr = 0x80071C98u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_80071C98:
    ctx->pc = 0x80071C98u;
    ctx->downcount -= 6;
    // 80071C98: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80071C9C:
    ctx->pc = 0x80071C9Cu;
    // 80071C9C: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_80071CA0:
    ctx->pc = 0x80071CA0u;
    // 80071CA0: li      r5, 8
    ctx->gpr[5] = (u32)(s32)(8);

label_80071CA4:
    ctx->pc = 0x80071CA4u;
    // 80071CA4: li      r6, 14
    ctx->gpr[6] = (u32)(s32)(14);

label_80071CA8:
    ctx->pc = 0x80071CA8u;
    // 80071CA8: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80071CAC:
    ctx->pc = 0x80071CACu;
    // 80071CAC: bl      0x8025C3B0
    {
            ctx->lr = 0x80071CB0u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_80071CB0:
    ctx->pc = 0x80071CB0u;
    ctx->downcount -= 6;
    // 80071CB0: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80071CB4:
    ctx->pc = 0x80071CB4u;
    // 80071CB4: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_80071CB8:
    ctx->pc = 0x80071CB8u;
    // 80071CB8: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_80071CBC:
    ctx->pc = 0x80071CBCu;
    // 80071CBC: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_80071CC0:
    ctx->pc = 0x80071CC0u;
    // 80071CC0: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80071CC4:
    ctx->pc = 0x80071CC4u;
    // 80071CC4: bl      0x8025C430
    {
            ctx->lr = 0x80071CC8u;
            ctx->pc = 0x8025C430u;
            return;
    }

label_80071CC8:
    ctx->pc = 0x80071CC8u;
    ctx->downcount -= 4;
    // 80071CC8: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80071CCC:
    ctx->pc = 0x80071CCCu;
    // 80071CCC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071CD0:
    ctx->pc = 0x80071CD0u;
    // 80071CD0: li      r5, 3
    ctx->gpr[5] = (u32)(s32)(3);

label_80071CD4:
    ctx->pc = 0x80071CD4u;
    // 80071CD4: bl      0x8025C868
    {
            ctx->lr = 0x80071CD8u;
            ctx->pc = 0x8025C868u;
            return;
    }

label_80071CD8:
    ctx->pc = 0x80071CD8u;
    ctx->downcount -= 7;
    // 80071CD8: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80071CDC:
    ctx->pc = 0x80071CDCu;
    // 80071CDC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071CE0:
    ctx->pc = 0x80071CE0u;
    // 80071CE0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80071CE4:
    ctx->pc = 0x80071CE4u;
    // 80071CE4: li      r6, 3
    ctx->gpr[6] = (u32)(s32)(3);

label_80071CE8:
    ctx->pc = 0x80071CE8u;
    // 80071CE8: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_80071CEC:
    ctx->pc = 0x80071CECu;
    // 80071CEC: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80071CF0:
    ctx->pc = 0x80071CF0u;
    // 80071CF0: bl      0x8025C4B4
    {
            ctx->lr = 0x80071CF4u;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_80071CF4:
    ctx->pc = 0x80071CF4u;
    ctx->downcount -= 7;
    // 80071CF4: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80071CF8:
    ctx->pc = 0x80071CF8u;
    // 80071CF8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071CFC:
    ctx->pc = 0x80071CFCu;
    // 80071CFC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80071D00:
    ctx->pc = 0x80071D00u;
    // 80071D00: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80071D04:
    ctx->pc = 0x80071D04u;
    // 80071D04: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_80071D08:
    ctx->pc = 0x80071D08u;
    // 80071D08: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80071D0C:
    ctx->pc = 0x80071D0Cu;
    // 80071D0C: bl      0x8025C574
    {
            ctx->lr = 0x80071D10u;
            ctx->pc = 0x8025C574u;
            return;
    }

label_80071D10:
    ctx->pc = 0x80071D10u;
    ctx->downcount -= 2;
    // 80071D10: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_80071D14:
    ctx->pc = 0x80071D14u;
    // 80071D14: bl      0x8025C08C
    {
            ctx->lr = 0x80071D18u;
            ctx->pc = 0x8025C08Cu;
            return;
    }

label_80071D18:
    ctx->pc = 0x80071D18u;
    ctx->downcount -= 5;
    // 80071D18: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_80071D1C:
    ctx->pc = 0x80071D1Cu;
    // 80071D1C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071D20:
    ctx->pc = 0x80071D20u;
    // 80071D20: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80071D24:
    ctx->pc = 0x80071D24u;
    // 80071D24: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_80071D28:
    ctx->pc = 0x80071D28u;
    // 80071D28: bl      0x8025CA34
    {
            ctx->lr = 0x80071D2Cu;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_80071D2C:
    ctx->pc = 0x80071D2Cu;
    ctx->downcount -= 6;
    // 80071D2C: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_80071D30:
    ctx->pc = 0x80071D30u;
    // 80071D30: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071D34:
    ctx->pc = 0x80071D34u;
    // 80071D34: li      r5, 15
    ctx->gpr[5] = (u32)(s32)(15);

label_80071D38:
    ctx->pc = 0x80071D38u;
    // 80071D38: li      r6, 15
    ctx->gpr[6] = (u32)(s32)(15);

label_80071D3C:
    ctx->pc = 0x80071D3Cu;
    // 80071D3C: li      r7, 8
    ctx->gpr[7] = (u32)(s32)(8);

label_80071D40:
    ctx->pc = 0x80071D40u;
    // 80071D40: bl      0x8025C3B0
    {
            ctx->lr = 0x80071D44u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_80071D44:
    ctx->pc = 0x80071D44u;
    ctx->downcount -= 6;
    // 80071D44: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_80071D48:
    ctx->pc = 0x80071D48u;
    // 80071D48: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_80071D4C:
    ctx->pc = 0x80071D4Cu;
    // 80071D4C: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_80071D50:
    ctx->pc = 0x80071D50u;
    // 80071D50: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_80071D54:
    ctx->pc = 0x80071D54u;
    // 80071D54: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80071D58:
    ctx->pc = 0x80071D58u;
    // 80071D58: bl      0x8025C430
    {
            ctx->lr = 0x80071D5Cu;
            ctx->pc = 0x8025C430u;
            return;
    }

label_80071D5C:
    ctx->pc = 0x80071D5Cu;
    ctx->downcount -= 4;
    // 80071D5C: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_80071D60:
    ctx->pc = 0x80071D60u;
    // 80071D60: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071D64:
    ctx->pc = 0x80071D64u;
    // 80071D64: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80071D68:
    ctx->pc = 0x80071D68u;
    // 80071D68: bl      0x8025C868
    {
            ctx->lr = 0x80071D6Cu;
            ctx->pc = 0x8025C868u;
            return;
    }

label_80071D6C:
    ctx->pc = 0x80071D6Cu;
    ctx->downcount -= 7;
    // 80071D6C: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_80071D70:
    ctx->pc = 0x80071D70u;
    // 80071D70: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80071D74:
    ctx->pc = 0x80071D74u;
    // 80071D74: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80071D78:
    ctx->pc = 0x80071D78u;
    // 80071D78: li      r6, 2
    ctx->gpr[6] = (u32)(s32)(2);

label_80071D7C:
    ctx->pc = 0x80071D7Cu;
    // 80071D7C: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_80071D80:
    ctx->pc = 0x80071D80u;
    // 80071D80: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80071D84:
    ctx->pc = 0x80071D84u;
    // 80071D84: bl      0x8025C4B4
    {
            ctx->lr = 0x80071D88u;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_80071D88:
    ctx->pc = 0x80071D88u;
    ctx->downcount -= 7;
    // 80071D88: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_80071D8C:
    ctx->pc = 0x80071D8Cu;
    // 80071D8C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071D90:
    ctx->pc = 0x80071D90u;
    // 80071D90: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80071D94:
    ctx->pc = 0x80071D94u;
    // 80071D94: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80071D98:
    ctx->pc = 0x80071D98u;
    // 80071D98: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_80071D9C:
    ctx->pc = 0x80071D9Cu;
    // 80071D9C: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80071DA0:
    ctx->pc = 0x80071DA0u;
    // 80071DA0: bl      0x8025C574
    {
            ctx->lr = 0x80071DA4u;
            ctx->pc = 0x8025C574u;
            return;
    }

label_80071DA4:
    ctx->pc = 0x80071DA4u;
    ctx->downcount -= 1;
    // 80071DA4: bl      0x80257D68
    {
            ctx->lr = 0x80071DA8u;
            ctx->pc = 0x80257D68u;
            return;
    }

label_80071DA8:
    ctx->pc = 0x80071DA8u;
    ctx->downcount -= 3;
    // 80071DA8: li      r3, 9
    ctx->gpr[3] = (u32)(s32)(9);

label_80071DAC:
    ctx->pc = 0x80071DACu;
    // 80071DAC: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80071DB0:
    ctx->pc = 0x80071DB0u;
    // 80071DB0: bl      0x802572E8
    {
            ctx->lr = 0x80071DB4u;
            ctx->pc = 0x802572E8u;
            return;
    }

label_80071DB4:
    ctx->pc = 0x80071DB4u;
    ctx->downcount -= 3;
    // 80071DB4: li      r3, 13
    ctx->gpr[3] = (u32)(s32)(13);

label_80071DB8:
    ctx->pc = 0x80071DB8u;
    // 80071DB8: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80071DBC:
    ctx->pc = 0x80071DBCu;
    // 80071DBC: bl      0x802572E8
    {
            ctx->lr = 0x80071DC0u;
            ctx->pc = 0x802572E8u;
            return;
    }

label_80071DC0:
    ctx->pc = 0x80071DC0u;
    ctx->downcount -= 2;
    // 80071DC0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80071DC4:
    ctx->pc = 0x80071DC4u;
    // 80071DC4: bl      0x80259494
    {
            ctx->lr = 0x80071DC8u;
            ctx->pc = 0x80259494u;
            return;
    }

label_80071DC8:
    ctx->pc = 0x80071DC8u;
    ctx->downcount -= 5;
    // 80071DC8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80071DCC:
    ctx->pc = 0x80071DCCu;
    // 80071DCC: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80071DD0:
    ctx->pc = 0x80071DD0u;
    // 80071DD0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80071DD4:
    ctx->pc = 0x80071DD4u;
    // 80071DD4: li      r6, 5
    ctx->gpr[6] = (u32)(s32)(5);

label_80071DD8:
    ctx->pc = 0x80071DD8u;
    // 80071DD8: bl      0x8025CEF4
    {
            ctx->lr = 0x80071DDCu;
            ctx->pc = 0x8025CEF4u;
            return;
    }

label_80071DDC:
    ctx->pc = 0x80071DDCu;
    ctx->downcount -= 3;
    // 80071DDC: lbz     r0, -24944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24944);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80071DE0:
    ctx->pc = 0x80071DE0u;
    // 80071DE0: cmplwi  r0, 0x0000
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

label_80071DE4:
    ctx->pc = 0x80071DE4u;
    // 80071DE4: bc    4, 2, 0x80071E0C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80071E0C;
        }
    }

label_80071DE8:
    ctx->pc = 0x80071DE8u;
    ctx->downcount -= 3;
    // 80071DE8: lwz     r0, -24948(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24948);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80071DEC:
    ctx->pc = 0x80071DECu;
    // 80071DEC: cmpwi   r0, 7
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(7);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80071DF0:
    ctx->pc = 0x80071DF0u;
    // 80071DF0: bc    4, 2, 0x80071E0C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80071E0C;
        }
    }

label_80071DF4:
    ctx->pc = 0x80071DF4u;
    ctx->downcount -= 3;
    // 80071DF4: lbz     r0, -24950(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24950);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80071DF8:
    ctx->pc = 0x80071DF8u;
    // 80071DF8: cmplwi  r0, 0x0000
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

label_80071DFC:
    ctx->pc = 0x80071DFCu;
    // 80071DFC: bc    4, 2, 0x80071E0C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80071E0C;
        }
    }

label_80071E00:
    ctx->pc = 0x80071E00u;
    ctx->downcount -= 3;
    // 80071E00: lbz     r0, -24942(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24942);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80071E04:
    ctx->pc = 0x80071E04u;
    // 80071E04: cmplwi  r0, 0x0000
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

label_80071E08:
    ctx->pc = 0x80071E08u;
    // 80071E08: bc    4, 2, 0x80071E38
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80071E38;
        }
    }

label_80071E0C:
    ctx->pc = 0x80071E0Cu;
    ctx->downcount -= 4;
    // 80071E0C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80071E10:
    ctx->pc = 0x80071E10u;
    // 80071E10: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_80071E14:
    ctx->pc = 0x80071E14u;
    // 80071E14: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80071E18:
    ctx->pc = 0x80071E18u;
    // 80071E18: bl      0x8025D078
    {
            ctx->lr = 0x80071E1Cu;
            ctx->pc = 0x8025D078u;
            return;
    }

label_80071E1C:
    ctx->pc = 0x80071E1Cu;
    ctx->downcount -= 7;
    // 80071E1C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80071E20:
    ctx->pc = 0x80071E20u;
    // 80071E20: stb     r3, -24944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24944);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_80071E24:
    ctx->pc = 0x80071E24u;
    // 80071E24: li      r0, 7
    ctx->gpr[0] = (u32)(s32)(7);

label_80071E28:
    ctx->pc = 0x80071E28u;
    // 80071E28: stw     r0, -24948(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24948);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80071E2C:
    ctx->pc = 0x80071E2Cu;
    // 80071E2C: stb     r3, -24950(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24950);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_80071E30:
    ctx->pc = 0x80071E30u;
    // 80071E30: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80071E34:
    ctx->pc = 0x80071E34u;
    // 80071E34: stb     r0, -24942(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24942);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80071E38:
    ctx->pc = 0x80071E38u;
    ctx->downcount -= 3;
    // 80071E38: lbz     r0, -24951(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24951);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80071E3C:
    ctx->pc = 0x80071E3Cu;
    // 80071E3C: cmplwi  r0, 0x0001
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0001u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80071E40:
    ctx->pc = 0x80071E40u;
    // 80071E40: bc    4, 2, 0x80071E50
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80071E50;
        }
    }

label_80071E44:
    ctx->pc = 0x80071E44u;
    ctx->downcount -= 3;
    // 80071E44: lbz     r0, -24943(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24943);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80071E48:
    ctx->pc = 0x80071E48u;
    // 80071E48: cmplwi  r0, 0x0000
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

label_80071E4C:
    ctx->pc = 0x80071E4Cu;
    // 80071E4C: bc    4, 2, 0x80071E64
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80071E64;
        }
    }

label_80071E50:
    ctx->pc = 0x80071E50u;
    ctx->downcount -= 2;
    // 80071E50: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80071E54:
    ctx->pc = 0x80071E54u;
    // 80071E54: bl      0x8025D0F0
    {
            ctx->lr = 0x80071E58u;
            ctx->pc = 0x8025D0F0u;
            return;
    }

label_80071E58:
    ctx->pc = 0x80071E58u;
    ctx->downcount -= 3;
    // 80071E58: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80071E5C:
    ctx->pc = 0x80071E5Cu;
    // 80071E5C: stb     r0, -24951(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24951);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80071E60:
    ctx->pc = 0x80071E60u;
    // 80071E60: stb     r0, -24943(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24943);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80071E64:
    ctx->pc = 0x80071E64u;
    ctx->downcount -= 6;
    // 80071E64: li      r3, 7
    ctx->gpr[3] = (u32)(s32)(7);

label_80071E68:
    ctx->pc = 0x80071E68u;
    // 80071E68: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071E6C:
    ctx->pc = 0x80071E6Cu;
    // 80071E6C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80071E70:
    ctx->pc = 0x80071E70u;
    // 80071E70: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_80071E74:
    ctx->pc = 0x80071E74u;
    // 80071E74: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80071E78:
    ctx->pc = 0x80071E78u;
    // 80071E78: bl      0x8025C960
    {
            ctx->lr = 0x80071E7Cu;
            ctx->pc = 0x8025C960u;
            return;
    }

label_80071E7C:
    ctx->pc = 0x80071E7Cu;
    ctx->downcount -= 4;
    // 80071E7C: lis     r3, -32710
    ctx->gpr[3] = ((u32)(s32)(-32710) << 16);

label_80071E80:
    ctx->pc = 0x80071E80u;
    // 80071E80: addi    r3, r3, -32288
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-32288);

label_80071E84:
    ctx->pc = 0x80071E84u;
    // 80071E84: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80071E88:
    ctx->pc = 0x80071E88u;
    // 80071E88: bl      0x8025D8B8
    {
            ctx->lr = 0x80071E8Cu;
            ctx->pc = 0x8025D8B8u;
            return;
    }

label_80071E8C:
    ctx->pc = 0x80071E8Cu;
    ctx->downcount -= 2;
    // 80071E8C: li      r3, 60
    ctx->gpr[3] = (u32)(s32)(60);

label_80071E90:
    ctx->pc = 0x80071E90u;
    // 80071E90: bl      0x8025DA94
    {
            ctx->lr = 0x80071E94u;
            ctx->pc = 0x8025DA94u;
            return;
    }

label_80071E94:
    ctx->pc = 0x80071E94u;
    ctx->downcount -= 4;
    // 80071E94: li      r3, 128
    ctx->gpr[3] = (u32)(s32)(128);

label_80071E98:
    ctx->pc = 0x80071E98u;
    // 80071E98: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071E9C:
    ctx->pc = 0x80071E9Cu;
    // 80071E9C: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_80071EA0:
    ctx->pc = 0x80071EA0u;
    // 80071EA0: bl      0x8025920C
    {
            ctx->lr = 0x80071EA4u;
            ctx->pc = 0x8025920Cu;
            return;
    }

label_80071EA4:
    ctx->pc = 0x80071EA4u;
    ctx->downcount -= 27;
    // 80071EA4: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80071EA8:
    ctx->pc = 0x80071EA8u;
    // 80071EA8: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_80071EAC:
    ctx->pc = 0x80071EACu;
    // 80071EAC: sth     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_80071EB0:
    ctx->pc = 0x80071EB0u;
    // 80071EB0: sth     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_80071EB4:
    ctx->pc = 0x80071EB4u;
    // 80071EB4: li      r4, -8
    ctx->gpr[4] = (u32)(s32)(-8);

label_80071EB8:
    ctx->pc = 0x80071EB8u;
    // 80071EB8: sth     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_80071EBC:
    ctx->pc = 0x80071EBCu;
    // 80071EBC: sth     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_80071EC0:
    ctx->pc = 0x80071EC0u;
    // 80071EC0: sth     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_80071EC4:
    ctx->pc = 0x80071EC4u;
    // 80071EC4: li      r0, 640
    ctx->gpr[0] = (u32)(s32)(640);

label_80071EC8:
    ctx->pc = 0x80071EC8u;
    // 80071EC8: sth     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80071ECC:
    ctx->pc = 0x80071ECCu;
    // 80071ECC: sth     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_80071ED0:
    ctx->pc = 0x80071ED0u;
    // 80071ED0: sth     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_80071ED4:
    ctx->pc = 0x80071ED4u;
    // 80071ED4: li      r3, 128
    ctx->gpr[3] = (u32)(s32)(128);

label_80071ED8:
    ctx->pc = 0x80071ED8u;
    // 80071ED8: sth     r3, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_80071EDC:
    ctx->pc = 0x80071EDCu;
    // 80071EDC: sth     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_80071EE0:
    ctx->pc = 0x80071EE0u;
    // 80071EE0: sth     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80071EE4:
    ctx->pc = 0x80071EE4u;
    // 80071EE4: li      r0, 480
    ctx->gpr[0] = (u32)(s32)(480);

label_80071EE8:
    ctx->pc = 0x80071EE8u;
    // 80071EE8: sth     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80071EEC:
    ctx->pc = 0x80071EECu;
    // 80071EEC: sth     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_80071EF0:
    ctx->pc = 0x80071EF0u;
    // 80071EF0: sth     r3, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_80071EF4:
    ctx->pc = 0x80071EF4u;
    // 80071EF4: sth     r3, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_80071EF8:
    ctx->pc = 0x80071EF8u;
    // 80071EF8: sth     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_80071EFC:
    ctx->pc = 0x80071EFCu;
    // 80071EFC: sth     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80071F00:
    ctx->pc = 0x80071F00u;
    // 80071F00: sth     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_80071F04:
    ctx->pc = 0x80071F04u;
    // 80071F04: sth     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_80071F08:
    ctx->pc = 0x80071F08u;
    // 80071F08: sth     r3, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_80071F0C:
    ctx->pc = 0x80071F0Cu;
    // 80071F0C: bl      0x8000FB20
    {
            ctx->lr = 0x80071F10u;
            ctx->pc = 0x8000FB20u;
            return;
    }

label_80071F10:
    ctx->pc = 0x80071F10u;
    ctx->downcount -= 6;
    // 80071F10: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80071F14:
    ctx->pc = 0x80071F14u;
    // 80071F14: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80071F18:
    ctx->pc = 0x80071F18u;
    // 80071F18: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80071F1C:
    ctx->pc = 0x80071F1Cu;
    // 80071F1C: li      r6, 2
    ctx->gpr[6] = (u32)(s32)(2);

label_80071F20:
    ctx->pc = 0x80071F20u;
    // 80071F20: li      r7, 3
    ctx->gpr[7] = (u32)(s32)(3);

label_80071F24:
    ctx->pc = 0x80071F24u;
    // 80071F24: bl      0x8025C8C0
    {
            ctx->lr = 0x80071F28u;
            ctx->pc = 0x8025C8C0u;
            return;
    }

label_80071F28:
    ctx->pc = 0x80071F28u;
    ctx->downcount -= 5;
    // 80071F28: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80071F2C:
    ctx->pc = 0x80071F2Cu;
    // 80071F2C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80071F30:
    ctx->pc = 0x80071F30u;
    // 80071F30: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_80071F34:
    ctx->pc = 0x80071F34u;
    // 80071F34: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_80071F38:
    ctx->pc = 0x80071F38u;
    ctx->downcount -= 54;
    // 80071F38: stwu     r1, -48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-48);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80071F3C:
    ctx->pc = 0x80071F3Cu;
    // 80071F3C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80071F40:
    ctx->pc = 0x80071F40u;
    // 80071F40: stw     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80071F44:
    ctx->pc = 0x80071F44u;
    // 80071F44: lwz     r0, -30256(r2)
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30256);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80071F48:
    ctx->pc = 0x80071F48u;
    // 80071F48: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80071F4C:
    ctx->pc = 0x80071F4Cu;
    // 80071F4C: lwz     r0, -30252(r2)
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30252);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80071F50:
    ctx->pc = 0x80071F50u;
    // 80071F50: stw     r0, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80071F54:
    ctx->pc = 0x80071F54u;
    // 80071F54: lwz     r0, -30248(r2)
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30248);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80071F58:
    ctx->pc = 0x80071F58u;
    // 80071F58: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80071F5C:
    ctx->pc = 0x80071F5Cu;
    // 80071F5C: lwz     r0, -30244(r2)
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30244);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80071F60:
    ctx->pc = 0x80071F60u;
    // 80071F60: stw     r0, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80071F64:
    ctx->pc = 0x80071F64u;
    // 80071F64: lbz     r4, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_80071F68:
    ctx->pc = 0x80071F68u;
    // 80071F68: lbz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80071F6C:
    ctx->pc = 0x80071F6Cu;
    // 80071F6C: srawi r5, r0, 3
    {
        u32 sh = 3u;
        u32 value = ctx->gpr[0];
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

label_80071F70:
    ctx->pc = 0x80071F70u;
    // 80071F70: add   r0, r4, r5
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80071F74:
    ctx->pc = 0x80071F74u;
    // 80071F74: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_80071F78:
    ctx->pc = 0x80071F78u;
    // 80071F78: stb     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80071F7C:
    ctx->pc = 0x80071F7Cu;
    // 80071F7C: lbz     r4, 37(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(37);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_80071F80:
    ctx->pc = 0x80071F80u;
    // 80071F80: lbz     r0, 1(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80071F84:
    ctx->pc = 0x80071F84u;
    // 80071F84: srawi r6, r0, 3
    {
        u32 sh = 3u;
        u32 value = ctx->gpr[0];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[6] = value;
        } else if (sh > 31) {
            ctx->gpr[6] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[6] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_80071F88:
    ctx->pc = 0x80071F88u;
    // 80071F88: add   r0, r4, r6
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80071F8C:
    ctx->pc = 0x80071F8Cu;
    // 80071F8C: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_80071F90:
    ctx->pc = 0x80071F90u;
    // 80071F90: stb     r0, 37(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(37);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80071F94:
    ctx->pc = 0x80071F94u;
    // 80071F94: lbz     r4, 38(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(38);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_80071F98:
    ctx->pc = 0x80071F98u;
    // 80071F98: lbz     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80071F9C:
    ctx->pc = 0x80071F9Cu;
    // 80071F9C: srawi r3, r0, 3
    {
        u32 sh = 3u;
        u32 value = ctx->gpr[0];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[3] = value;
        } else if (sh > 31) {
            ctx->gpr[3] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[3] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_80071FA0:
    ctx->pc = 0x80071FA0u;
    // 80071FA0: add   r0, r4, r3
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80071FA4:
    ctx->pc = 0x80071FA4u;
    // 80071FA4: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_80071FA8:
    ctx->pc = 0x80071FA8u;
    // 80071FA8: stb     r0, 38(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(38);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80071FAC:
    ctx->pc = 0x80071FACu;
    // 80071FAC: lbz     r0, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80071FB0:
    ctx->pc = 0x80071FB0u;
    // 80071FB0: add   r0, r0, r5
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80071FB4:
    ctx->pc = 0x80071FB4u;
    // 80071FB4: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_80071FB8:
    ctx->pc = 0x80071FB8u;
    // 80071FB8: stb     r0, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80071FBC:
    ctx->pc = 0x80071FBCu;
    // 80071FBC: lbz     r0, 33(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(33);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80071FC0:
    ctx->pc = 0x80071FC0u;
    // 80071FC0: add   r0, r0, r6
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80071FC4:
    ctx->pc = 0x80071FC4u;
    // 80071FC4: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_80071FC8:
    ctx->pc = 0x80071FC8u;
    // 80071FC8: stb     r0, 33(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(33);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80071FCC:
    ctx->pc = 0x80071FCCu;
    // 80071FCC: lbz     r0, 34(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(34);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80071FD0:
    ctx->pc = 0x80071FD0u;
    // 80071FD0: add   r0, r0, r3
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80071FD4:
    ctx->pc = 0x80071FD4u;
    // 80071FD4: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_80071FD8:
    ctx->pc = 0x80071FD8u;
    // 80071FD8: stb     r0, 34(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(34);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80071FDC:
    ctx->pc = 0x80071FDCu;
    // 80071FDC: lbz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80071FE0:
    ctx->pc = 0x80071FE0u;
    // 80071FE0: add   r0, r0, r5
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80071FE4:
    ctx->pc = 0x80071FE4u;
    // 80071FE4: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_80071FE8:
    ctx->pc = 0x80071FE8u;
    // 80071FE8: stb     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80071FEC:
    ctx->pc = 0x80071FECu;
    // 80071FEC: lbz     r0, 29(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(29);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80071FF0:
    ctx->pc = 0x80071FF0u;
    // 80071FF0: add   r0, r0, r6
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80071FF4:
    ctx->pc = 0x80071FF4u;
    // 80071FF4: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_80071FF8:
    ctx->pc = 0x80071FF8u;
    // 80071FF8: stb     r0, 29(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(29);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80071FFC:
    ctx->pc = 0x80071FFCu;
    // 80071FFC: lbz     r0, 30(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(30);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80072000:
    ctx->pc = 0x80072000u;
    // 80072000: add   r0, r0, r3
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80072004:
    ctx->pc = 0x80072004u;
    // 80072004: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_80072008:
    ctx->pc = 0x80072008u;
    // 80072008: stb     r0, 30(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(30);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8007200C:
    ctx->pc = 0x8007200Cu;
    // 8007200C: bl      0x8006CA14
    {
            ctx->lr = 0x80072010u;
            ctx->pc = 0x8006CA14u;
            return;
    }

label_80072010:
    ctx->pc = 0x80072010u;
    ctx->downcount -= 2;
    // 80072010: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80072014:
    ctx->pc = 0x80072014u;
    // 80072014: bl      0x8006C8D4
    {
            ctx->lr = 0x80072018u;
            ctx->pc = 0x8006C8D4u;
            return;
    }

label_80072018:
    ctx->pc = 0x80072018u;
    ctx->downcount -= 6;
    // 80072018: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8007201C:
    ctx->pc = 0x8007201Cu;
    // 8007201C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80072020:
    ctx->pc = 0x80072020u;
    // 80072020: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80072024:
    ctx->pc = 0x80072024u;
    // 80072024: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80072028:
    ctx->pc = 0x80072028u;
    // 80072028: li      r7, 3
    ctx->gpr[7] = (u32)(s32)(3);

label_8007202C:
    ctx->pc = 0x8007202Cu;
    // 8007202C: bl      0x8025C8C0
    {
            ctx->lr = 0x80072030u;
            ctx->pc = 0x8025C8C0u;
            return;
    }

label_80072030:
    ctx->pc = 0x80072030u;
    ctx->downcount -= 6;
    // 80072030: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80072034:
    ctx->pc = 0x80072034u;
    // 80072034: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80072038:
    ctx->pc = 0x80072038u;
    // 80072038: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_8007203C:
    ctx->pc = 0x8007203Cu;
    // 8007203C: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_80072040:
    ctx->pc = 0x80072040u;
    // 80072040: li      r7, 3
    ctx->gpr[7] = (u32)(s32)(3);

label_80072044:
    ctx->pc = 0x80072044u;
    // 80072044: bl      0x8025C8C0
    {
            ctx->lr = 0x80072048u;
            ctx->pc = 0x8025C8C0u;
            return;
    }

label_80072048:
    ctx->pc = 0x80072048u;
    ctx->downcount -= 6;
    // 80072048: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_8007204C:
    ctx->pc = 0x8007204Cu;
    // 8007204C: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80072050:
    ctx->pc = 0x80072050u;
    // 80072050: li      r5, 2
    ctx->gpr[5] = (u32)(s32)(2);

label_80072054:
    ctx->pc = 0x80072054u;
    // 80072054: li      r6, 2
    ctx->gpr[6] = (u32)(s32)(2);

label_80072058:
    ctx->pc = 0x80072058u;
    // 80072058: li      r7, 3
    ctx->gpr[7] = (u32)(s32)(3);

label_8007205C:
    ctx->pc = 0x8007205Cu;
    // 8007205C: bl      0x8025C8C0
    {
            ctx->lr = 0x80072060u;
            ctx->pc = 0x8025C8C0u;
            return;
    }

label_80072060:
    ctx->pc = 0x80072060u;
    ctx->downcount -= 7;
    // 80072060: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80072064:
    ctx->pc = 0x80072064u;
    // 80072064: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80072068:
    ctx->pc = 0x80072068u;
    // 80072068: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_8007206C:
    ctx->pc = 0x8007206Cu;
    // 8007206C: li      r6, 60
    ctx->gpr[6] = (u32)(s32)(60);

label_80072070:
    ctx->pc = 0x80072070u;
    // 80072070: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80072074:
    ctx->pc = 0x80072074u;
    // 80072074: li      r8, 125
    ctx->gpr[8] = (u32)(s32)(125);

label_80072078:
    ctx->pc = 0x80072078u;
    // 80072078: bl      0x80258880
    {
            ctx->lr = 0x8007207Cu;
            ctx->pc = 0x80258880u;
            return;
    }

label_8007207C:
    ctx->pc = 0x8007207Cu;
    ctx->downcount -= 5;
    // 8007207C: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80072080:
    ctx->pc = 0x80072080u;
    // 80072080: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80072084:
    ctx->pc = 0x80072084u;
    // 80072084: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80072088:
    ctx->pc = 0x80072088u;
    // 80072088: addi    r4, r1, 20
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(20);

label_8007208C:
    ctx->pc = 0x8007208Cu;
    // 8007208C: bl      0x8025C71C
    {
            ctx->lr = 0x80072090u;
            ctx->pc = 0x8025C71Cu;
            return;
    }

label_80072090:
    ctx->pc = 0x80072090u;
    ctx->downcount -= 5;
    // 80072090: lwz     r0, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80072094:
    ctx->pc = 0x80072094u;
    // 80072094: stw     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80072098:
    ctx->pc = 0x80072098u;
    // 80072098: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8007209C:
    ctx->pc = 0x8007209Cu;
    // 8007209C: addi    r4, r1, 16
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(16);

label_800720A0:
    ctx->pc = 0x800720A0u;
    // 800720A0: bl      0x8025C71C
    {
            ctx->lr = 0x800720A4u;
            ctx->pc = 0x8025C71Cu;
            return;
    }

label_800720A4:
    ctx->pc = 0x800720A4u;
    ctx->downcount -= 5;
    // 800720A4: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800720A8:
    ctx->pc = 0x800720A8u;
    // 800720A8: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800720AC:
    ctx->pc = 0x800720ACu;
    // 800720AC: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_800720B0:
    ctx->pc = 0x800720B0u;
    // 800720B0: addi    r4, r1, 12
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(12);

label_800720B4:
    ctx->pc = 0x800720B4u;
    // 800720B4: bl      0x8025C71C
    {
            ctx->lr = 0x800720B8u;
            ctx->pc = 0x8025C71Cu;
            return;
    }

label_800720B8:
    ctx->pc = 0x800720B8u;
    ctx->downcount -= 5;
    // 800720B8: lwz     r0, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800720BC:
    ctx->pc = 0x800720BCu;
    // 800720BC: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800720C0:
    ctx->pc = 0x800720C0u;
    // 800720C0: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_800720C4:
    ctx->pc = 0x800720C4u;
    // 800720C4: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_800720C8:
    ctx->pc = 0x800720C8u;
    // 800720C8: bl      0x8025C634
    {
            ctx->lr = 0x800720CCu;
            ctx->pc = 0x8025C634u;
            return;
    }

label_800720CC:
    ctx->pc = 0x800720CCu;
    ctx->downcount -= 2;
    // 800720CC: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_800720D0:
    ctx->pc = 0x800720D0u;
    // 800720D0: bl      0x80258B50
    {
            ctx->lr = 0x800720D4u;
            ctx->pc = 0x80258B50u;
            return;
    }

label_800720D4:
    ctx->pc = 0x800720D4u;
    ctx->downcount -= 2;
    // 800720D4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800720D8:
    ctx->pc = 0x800720D8u;
    // 800720D8: bl      0x8025C060
    {
            ctx->lr = 0x800720DCu;
            ctx->pc = 0x8025C060u;
            return;
    }

label_800720DC:
    ctx->pc = 0x800720DCu;
    ctx->downcount -= 8;
    // 800720DC: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_800720E0:
    ctx->pc = 0x800720E0u;
    // 800720E0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800720E4:
    ctx->pc = 0x800720E4u;
    // 800720E4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800720E8:
    ctx->pc = 0x800720E8u;
    // 800720E8: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800720EC:
    ctx->pc = 0x800720ECu;
    // 800720EC: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800720F0:
    ctx->pc = 0x800720F0u;
    // 800720F0: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800720F4:
    ctx->pc = 0x800720F4u;
    // 800720F4: li      r9, 2
    ctx->gpr[9] = (u32)(s32)(2);

label_800720F8:
    ctx->pc = 0x800720F8u;
    // 800720F8: bl      0x8025A814
    {
            ctx->lr = 0x800720FCu;
            ctx->pc = 0x8025A814u;
            return;
    }

label_800720FC:
    ctx->pc = 0x800720FCu;
    ctx->downcount -= 8;
    // 800720FC: li      r3, 5
    ctx->gpr[3] = (u32)(s32)(5);

label_80072100:
    ctx->pc = 0x80072100u;
    // 80072100: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80072104:
    ctx->pc = 0x80072104u;
    // 80072104: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80072108:
    ctx->pc = 0x80072108u;
    // 80072108: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8007210C:
    ctx->pc = 0x8007210Cu;
    // 8007210C: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80072110:
    ctx->pc = 0x80072110u;
    // 80072110: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80072114:
    ctx->pc = 0x80072114u;
    // 80072114: li      r9, 2
    ctx->gpr[9] = (u32)(s32)(2);

label_80072118:
    ctx->pc = 0x80072118u;
    // 80072118: bl      0x8025A814
    {
            ctx->lr = 0x8007211Cu;
            ctx->pc = 0x8025A814u;
            return;
    }

label_8007211C:
    ctx->pc = 0x8007211Cu;
    ctx->downcount -= 2;
    // 8007211C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80072120:
    ctx->pc = 0x80072120u;
    // 80072120: bl      0x8025A7C8
    {
            ctx->lr = 0x80072124u;
            ctx->pc = 0x8025A7C8u;
            return;
    }

label_80072124:
    ctx->pc = 0x80072124u;
    ctx->downcount -= 2;
    // 80072124: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_80072128:
    ctx->pc = 0x80072128u;
    // 80072128: bl      0x8025CC10
    {
            ctx->lr = 0x8007212Cu;
            ctx->pc = 0x8025CC10u;
            return;
    }

label_8007212C:
    ctx->pc = 0x8007212Cu;
    ctx->downcount -= 3;
    // 8007212C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80072130:
    ctx->pc = 0x80072130u;
    // 80072130: li      r4, 12
    ctx->gpr[4] = (u32)(s32)(12);

label_80072134:
    ctx->pc = 0x80072134u;
    // 80072134: bl      0x8025C790
    {
            ctx->lr = 0x80072138u;
            ctx->pc = 0x8025C790u;
            return;
    }

label_80072138:
    ctx->pc = 0x80072138u;
    ctx->downcount -= 2;
    // 80072138: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8007213C:
    ctx->pc = 0x8007213Cu;
    // 8007213C: bl      0x8025C08C
    {
            ctx->lr = 0x80072140u;
            ctx->pc = 0x8025C08Cu;
            return;
    }

label_80072140:
    ctx->pc = 0x80072140u;
    ctx->downcount -= 5;
    // 80072140: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80072144:
    ctx->pc = 0x80072144u;
    // 80072144: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80072148:
    ctx->pc = 0x80072148u;
    // 80072148: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8007214C:
    ctx->pc = 0x8007214Cu;
    // 8007214C: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_80072150:
    ctx->pc = 0x80072150u;
    // 80072150: bl      0x8025CA34
    {
            ctx->lr = 0x80072154u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_80072154:
    ctx->pc = 0x80072154u;
    ctx->downcount -= 6;
    // 80072154: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80072158:
    ctx->pc = 0x80072158u;
    // 80072158: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_8007215C:
    ctx->pc = 0x8007215Cu;
    // 8007215C: li      r5, 8
    ctx->gpr[5] = (u32)(s32)(8);

label_80072160:
    ctx->pc = 0x80072160u;
    // 80072160: li      r6, 14
    ctx->gpr[6] = (u32)(s32)(14);

label_80072164:
    ctx->pc = 0x80072164u;
    // 80072164: li      r7, 2
    ctx->gpr[7] = (u32)(s32)(2);

label_80072168:
    ctx->pc = 0x80072168u;
    // 80072168: bl      0x8025C3B0
    {
            ctx->lr = 0x8007216Cu;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_8007216C:
    ctx->pc = 0x8007216Cu;
    ctx->downcount -= 6;
    // 8007216C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80072170:
    ctx->pc = 0x80072170u;
    // 80072170: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_80072174:
    ctx->pc = 0x80072174u;
    // 80072174: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_80072178:
    ctx->pc = 0x80072178u;
    // 80072178: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_8007217C:
    ctx->pc = 0x8007217Cu;
    // 8007217C: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_80072180:
    ctx->pc = 0x80072180u;
    // 80072180: bl      0x8025C430
    {
            ctx->lr = 0x80072184u;
            ctx->pc = 0x8025C430u;
            return;
    }

label_80072184:
    ctx->pc = 0x80072184u;
    ctx->downcount -= 4;
    // 80072184: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80072188:
    ctx->pc = 0x80072188u;
    // 80072188: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8007218C:
    ctx->pc = 0x8007218Cu;
    // 8007218C: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80072190:
    ctx->pc = 0x80072190u;
    // 80072190: bl      0x8025C868
    {
            ctx->lr = 0x80072194u;
            ctx->pc = 0x8025C868u;
            return;
    }

label_80072194:
    ctx->pc = 0x80072194u;
    ctx->downcount -= 7;
    // 80072194: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80072198:
    ctx->pc = 0x80072198u;
    // 80072198: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8007219C:
    ctx->pc = 0x8007219Cu;
    // 8007219C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800721A0:
    ctx->pc = 0x800721A0u;
    // 800721A0: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800721A4:
    ctx->pc = 0x800721A4u;
    // 800721A4: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_800721A8:
    ctx->pc = 0x800721A8u;
    // 800721A8: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800721AC:
    ctx->pc = 0x800721ACu;
    // 800721AC: bl      0x8025C4B4
    {
            ctx->lr = 0x800721B0u;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_800721B0:
    ctx->pc = 0x800721B0u;
    ctx->downcount -= 7;
    // 800721B0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800721B4:
    ctx->pc = 0x800721B4u;
    // 800721B4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800721B8:
    ctx->pc = 0x800721B8u;
    // 800721B8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800721BC:
    ctx->pc = 0x800721BCu;
    // 800721BC: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800721C0:
    ctx->pc = 0x800721C0u;
    // 800721C0: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_800721C4:
    ctx->pc = 0x800721C4u;
    // 800721C4: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800721C8:
    ctx->pc = 0x800721C8u;
    // 800721C8: bl      0x8025C574
    {
            ctx->lr = 0x800721CCu;
            ctx->pc = 0x8025C574u;
            return;
    }

label_800721CC:
    ctx->pc = 0x800721CCu;
    ctx->downcount -= 3;
    // 800721CC: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_800721D0:
    ctx->pc = 0x800721D0u;
    // 800721D0: li      r4, 13
    ctx->gpr[4] = (u32)(s32)(13);

label_800721D4:
    ctx->pc = 0x800721D4u;
    // 800721D4: bl      0x8025C790
    {
            ctx->lr = 0x800721D8u;
            ctx->pc = 0x8025C790u;
            return;
    }

label_800721D8:
    ctx->pc = 0x800721D8u;
    ctx->downcount -= 3;
    // 800721D8: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_800721DC:
    ctx->pc = 0x800721DCu;
    // 800721DC: li      r4, 29
    ctx->gpr[4] = (u32)(s32)(29);

label_800721E0:
    ctx->pc = 0x800721E0u;
    // 800721E0: bl      0x8025C7FC
    {
            ctx->lr = 0x800721E4u;
            ctx->pc = 0x8025C7FCu;
            return;
    }

label_800721E4:
    ctx->pc = 0x800721E4u;
    ctx->downcount -= 2;
    // 800721E4: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_800721E8:
    ctx->pc = 0x800721E8u;
    // 800721E8: bl      0x8025C08C
    {
            ctx->lr = 0x800721ECu;
            ctx->pc = 0x8025C08Cu;
            return;
    }

label_800721EC:
    ctx->pc = 0x800721ECu;
    ctx->downcount -= 5;
    // 800721EC: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_800721F0:
    ctx->pc = 0x800721F0u;
    // 800721F0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800721F4:
    ctx->pc = 0x800721F4u;
    // 800721F4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800721F8:
    ctx->pc = 0x800721F8u;
    // 800721F8: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_800721FC:
    ctx->pc = 0x800721FCu;
    // 800721FC: bl      0x8025CA34
    {
            ctx->lr = 0x80072200u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_80072200:
    ctx->pc = 0x80072200u;
    ctx->downcount -= 6;
    // 80072200: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80072204:
    ctx->pc = 0x80072204u;
    // 80072204: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_80072208:
    ctx->pc = 0x80072208u;
    // 80072208: li      r5, 8
    ctx->gpr[5] = (u32)(s32)(8);

label_8007220C:
    ctx->pc = 0x8007220Cu;
    // 8007220C: li      r6, 14
    ctx->gpr[6] = (u32)(s32)(14);

label_80072210:
    ctx->pc = 0x80072210u;
    // 80072210: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80072214:
    ctx->pc = 0x80072214u;
    // 80072214: bl      0x8025C3B0
    {
            ctx->lr = 0x80072218u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_80072218:
    ctx->pc = 0x80072218u;
    ctx->downcount -= 6;
    // 80072218: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8007221C:
    ctx->pc = 0x8007221Cu;
    // 8007221C: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_80072220:
    ctx->pc = 0x80072220u;
    // 80072220: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_80072224:
    ctx->pc = 0x80072224u;
    // 80072224: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_80072228:
    ctx->pc = 0x80072228u;
    // 80072228: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8007222C:
    ctx->pc = 0x8007222Cu;
    // 8007222C: bl      0x8025C430
    {
            ctx->lr = 0x80072230u;
            ctx->pc = 0x8025C430u;
            return;
    }

label_80072230:
    ctx->pc = 0x80072230u;
    ctx->downcount -= 4;
    // 80072230: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80072234:
    ctx->pc = 0x80072234u;
    // 80072234: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80072238:
    ctx->pc = 0x80072238u;
    // 80072238: li      r5, 2
    ctx->gpr[5] = (u32)(s32)(2);

label_8007223C:
    ctx->pc = 0x8007223Cu;
    // 8007223C: bl      0x8025C868
    {
            ctx->lr = 0x80072240u;
            ctx->pc = 0x8025C868u;
            return;
    }

label_80072240:
    ctx->pc = 0x80072240u;
    ctx->downcount -= 7;
    // 80072240: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80072244:
    ctx->pc = 0x80072244u;
    // 80072244: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80072248:
    ctx->pc = 0x80072248u;
    // 80072248: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8007224C:
    ctx->pc = 0x8007224Cu;
    // 8007224C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80072250:
    ctx->pc = 0x80072250u;
    // 80072250: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_80072254:
    ctx->pc = 0x80072254u;
    // 80072254: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80072258:
    ctx->pc = 0x80072258u;
    // 80072258: bl      0x8025C4B4
    {
            ctx->lr = 0x8007225Cu;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_8007225C:
    ctx->pc = 0x8007225Cu;
    ctx->downcount -= 7;
    // 8007225C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80072260:
    ctx->pc = 0x80072260u;
    // 80072260: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80072264:
    ctx->pc = 0x80072264u;
    // 80072264: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80072268:
    ctx->pc = 0x80072268u;
    // 80072268: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8007226C:
    ctx->pc = 0x8007226Cu;
    // 8007226C: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_80072270:
    ctx->pc = 0x80072270u;
    // 80072270: li      r8, 3
    ctx->gpr[8] = (u32)(s32)(3);

label_80072274:
    ctx->pc = 0x80072274u;
    // 80072274: bl      0x8025C574
    {
            ctx->lr = 0x80072278u;
            ctx->pc = 0x8025C574u;
            return;
    }

label_80072278:
    ctx->pc = 0x80072278u;
    ctx->downcount -= 3;
    // 80072278: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8007227C:
    ctx->pc = 0x8007227Cu;
    // 8007227C: li      r4, 14
    ctx->gpr[4] = (u32)(s32)(14);

label_80072280:
    ctx->pc = 0x80072280u;
    // 80072280: bl      0x8025C790
    {
            ctx->lr = 0x80072284u;
            ctx->pc = 0x8025C790u;
            return;
    }

label_80072284:
    ctx->pc = 0x80072284u;
    ctx->downcount -= 2;
    // 80072284: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80072288:
    ctx->pc = 0x80072288u;
    // 80072288: bl      0x8025C08C
    {
            ctx->lr = 0x8007228Cu;
            ctx->pc = 0x8025C08Cu;
            return;
    }

label_8007228C:
    ctx->pc = 0x8007228Cu;
    ctx->downcount -= 5;
    // 8007228C: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80072290:
    ctx->pc = 0x80072290u;
    // 80072290: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80072294:
    ctx->pc = 0x80072294u;
    // 80072294: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80072298:
    ctx->pc = 0x80072298u;
    // 80072298: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_8007229C:
    ctx->pc = 0x8007229Cu;
    // 8007229C: bl      0x8025CA34
    {
            ctx->lr = 0x800722A0u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_800722A0:
    ctx->pc = 0x800722A0u;
    ctx->downcount -= 6;
    // 800722A0: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_800722A4:
    ctx->pc = 0x800722A4u;
    // 800722A4: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_800722A8:
    ctx->pc = 0x800722A8u;
    // 800722A8: li      r5, 8
    ctx->gpr[5] = (u32)(s32)(8);

label_800722AC:
    ctx->pc = 0x800722ACu;
    // 800722AC: li      r6, 14
    ctx->gpr[6] = (u32)(s32)(14);

label_800722B0:
    ctx->pc = 0x800722B0u;
    // 800722B0: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800722B4:
    ctx->pc = 0x800722B4u;
    // 800722B4: bl      0x8025C3B0
    {
            ctx->lr = 0x800722B8u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_800722B8:
    ctx->pc = 0x800722B8u;
    ctx->downcount -= 6;
    // 800722B8: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_800722BC:
    ctx->pc = 0x800722BCu;
    // 800722BC: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_800722C0:
    ctx->pc = 0x800722C0u;
    // 800722C0: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_800722C4:
    ctx->pc = 0x800722C4u;
    // 800722C4: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_800722C8:
    ctx->pc = 0x800722C8u;
    // 800722C8: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800722CC:
    ctx->pc = 0x800722CCu;
    // 800722CC: bl      0x8025C430
    {
            ctx->lr = 0x800722D0u;
            ctx->pc = 0x8025C430u;
            return;
    }

label_800722D0:
    ctx->pc = 0x800722D0u;
    ctx->downcount -= 4;
    // 800722D0: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_800722D4:
    ctx->pc = 0x800722D4u;
    // 800722D4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800722D8:
    ctx->pc = 0x800722D8u;
    // 800722D8: li      r5, 3
    ctx->gpr[5] = (u32)(s32)(3);

label_800722DC:
    ctx->pc = 0x800722DCu;
    // 800722DC: bl      0x8025C868
    {
            ctx->lr = 0x800722E0u;
            ctx->pc = 0x8025C868u;
            return;
    }

label_800722E0:
    ctx->pc = 0x800722E0u;
    ctx->downcount -= 7;
    // 800722E0: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_800722E4:
    ctx->pc = 0x800722E4u;
    // 800722E4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800722E8:
    ctx->pc = 0x800722E8u;
    // 800722E8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800722EC:
    ctx->pc = 0x800722ECu;
    // 800722EC: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800722F0:
    ctx->pc = 0x800722F0u;
    // 800722F0: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_800722F4:
    ctx->pc = 0x800722F4u;
    // 800722F4: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800722F8:
    ctx->pc = 0x800722F8u;
    // 800722F8: bl      0x8025C4B4
    {
            ctx->lr = 0x800722FCu;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_800722FC:
    ctx->pc = 0x800722FCu;
    ctx->downcount -= 7;
    // 800722FC: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80072300:
    ctx->pc = 0x80072300u;
    // 80072300: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80072304:
    ctx->pc = 0x80072304u;
    // 80072304: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80072308:
    ctx->pc = 0x80072308u;
    // 80072308: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8007230C:
    ctx->pc = 0x8007230Cu;
    // 8007230C: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_80072310:
    ctx->pc = 0x80072310u;
    // 80072310: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80072314:
    ctx->pc = 0x80072314u;
    // 80072314: bl      0x8025C574
    {
            ctx->lr = 0x80072318u;
            ctx->pc = 0x8025C574u;
            return;
    }

label_80072318:
    ctx->pc = 0x80072318u;
    ctx->downcount -= 1;
    // 80072318: bl      0x80257D68
    {
            ctx->lr = 0x8007231Cu;
            ctx->pc = 0x80257D68u;
            return;
    }

label_8007231C:
    ctx->pc = 0x8007231Cu;
    ctx->downcount -= 3;
    // 8007231C: li      r3, 9
    ctx->gpr[3] = (u32)(s32)(9);

label_80072320:
    ctx->pc = 0x80072320u;
    // 80072320: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80072324:
    ctx->pc = 0x80072324u;
    // 80072324: bl      0x802572E8
    {
            ctx->lr = 0x80072328u;
            ctx->pc = 0x802572E8u;
            return;
    }

label_80072328:
    ctx->pc = 0x80072328u;
    ctx->downcount -= 3;
    // 80072328: li      r3, 13
    ctx->gpr[3] = (u32)(s32)(13);

label_8007232C:
    ctx->pc = 0x8007232Cu;
    // 8007232C: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80072330:
    ctx->pc = 0x80072330u;
    // 80072330: bl      0x802572E8
    {
            ctx->lr = 0x80072334u;
            ctx->pc = 0x802572E8u;
            return;
    }

label_80072334:
    ctx->pc = 0x80072334u;
    ctx->downcount -= 2;
    // 80072334: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80072338:
    ctx->pc = 0x80072338u;
    // 80072338: bl      0x80259494
    {
            ctx->lr = 0x8007233Cu;
            ctx->pc = 0x80259494u;
            return;
    }

label_8007233C:
    ctx->pc = 0x8007233Cu;
    ctx->downcount -= 5;
    // 8007233C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80072340:
    ctx->pc = 0x80072340u;
    // 80072340: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80072344:
    ctx->pc = 0x80072344u;
    // 80072344: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80072348:
    ctx->pc = 0x80072348u;
    // 80072348: li      r6, 5
    ctx->gpr[6] = (u32)(s32)(5);

label_8007234C:
    ctx->pc = 0x8007234Cu;
    // 8007234C: bl      0x8025CEF4
    {
            ctx->lr = 0x80072350u;
            ctx->pc = 0x8025CEF4u;
            return;
    }

label_80072350:
    ctx->pc = 0x80072350u;
    ctx->downcount -= 3;
    // 80072350: lbz     r0, -24944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24944);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80072354:
    ctx->pc = 0x80072354u;
    // 80072354: cmplwi  r0, 0x0000
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

label_80072358:
    ctx->pc = 0x80072358u;
    // 80072358: bc    4, 2, 0x80072380
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80072380;
        }
    }

label_8007235C:
    ctx->pc = 0x8007235Cu;
    ctx->downcount -= 3;
    // 8007235C: lwz     r0, -24948(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24948);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80072360:
    ctx->pc = 0x80072360u;
    // 80072360: cmpwi   r0, 7
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(7);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80072364:
    ctx->pc = 0x80072364u;
    // 80072364: bc    4, 2, 0x80072380
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80072380;
        }
    }

label_80072368:
    ctx->pc = 0x80072368u;
    ctx->downcount -= 3;
    // 80072368: lbz     r0, -24950(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24950);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8007236C:
    ctx->pc = 0x8007236Cu;
    // 8007236C: cmplwi  r0, 0x0000
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

label_80072370:
    ctx->pc = 0x80072370u;
    // 80072370: bc    4, 2, 0x80072380
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80072380;
        }
    }

label_80072374:
    ctx->pc = 0x80072374u;
    ctx->downcount -= 3;
    // 80072374: lbz     r0, -24942(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24942);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80072378:
    ctx->pc = 0x80072378u;
    // 80072378: cmplwi  r0, 0x0000
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

label_8007237C:
    ctx->pc = 0x8007237Cu;
    // 8007237C: bc    4, 2, 0x800723AC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800723AC;
        }
    }

label_80072380:
    ctx->pc = 0x80072380u;
    ctx->downcount -= 4;
    // 80072380: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80072384:
    ctx->pc = 0x80072384u;
    // 80072384: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_80072388:
    ctx->pc = 0x80072388u;
    // 80072388: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8007238C:
    ctx->pc = 0x8007238Cu;
    // 8007238C: bl      0x8025D078
    {
            ctx->lr = 0x80072390u;
            ctx->pc = 0x8025D078u;
            return;
    }

label_80072390:
    ctx->pc = 0x80072390u;
    ctx->downcount -= 7;
    // 80072390: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80072394:
    ctx->pc = 0x80072394u;
    // 80072394: stb     r3, -24944(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24944);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_80072398:
    ctx->pc = 0x80072398u;
    // 80072398: li      r0, 7
    ctx->gpr[0] = (u32)(s32)(7);

label_8007239C:
    ctx->pc = 0x8007239Cu;
    // 8007239C: stw     r0, -24948(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24948);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800723A0:
    ctx->pc = 0x800723A0u;
    // 800723A0: stb     r3, -24950(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24950);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_800723A4:
    ctx->pc = 0x800723A4u;
    // 800723A4: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_800723A8:
    ctx->pc = 0x800723A8u;
    // 800723A8: stb     r0, -24942(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24942);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_800723AC:
    ctx->pc = 0x800723ACu;
    ctx->downcount -= 3;
    // 800723AC: lbz     r0, -24951(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24951);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_800723B0:
    ctx->pc = 0x800723B0u;
    // 800723B0: cmplwi  r0, 0x0001
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0001u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800723B4:
    ctx->pc = 0x800723B4u;
    // 800723B4: bc    4, 2, 0x800723C4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800723C4;
        }
    }

label_800723B8:
    ctx->pc = 0x800723B8u;
    ctx->downcount -= 3;
    // 800723B8: lbz     r0, -24943(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24943);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_800723BC:
    ctx->pc = 0x800723BCu;
    // 800723BC: cmplwi  r0, 0x0000
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

label_800723C0:
    ctx->pc = 0x800723C0u;
    // 800723C0: bc    4, 2, 0x800723D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800723D8;
        }
    }

label_800723C4:
    ctx->pc = 0x800723C4u;
    ctx->downcount -= 2;
    // 800723C4: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_800723C8:
    ctx->pc = 0x800723C8u;
    // 800723C8: bl      0x8025D0F0
    {
            ctx->lr = 0x800723CCu;
            ctx->pc = 0x8025D0F0u;
            return;
    }

label_800723CC:
    ctx->pc = 0x800723CCu;
    ctx->downcount -= 3;
    // 800723CC: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_800723D0:
    ctx->pc = 0x800723D0u;
    // 800723D0: stb     r0, -24951(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24951);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_800723D4:
    ctx->pc = 0x800723D4u;
    // 800723D4: stb     r0, -24943(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-24943);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_800723D8:
    ctx->pc = 0x800723D8u;
    ctx->downcount -= 6;
    // 800723D8: li      r3, 7
    ctx->gpr[3] = (u32)(s32)(7);

label_800723DC:
    ctx->pc = 0x800723DCu;
    // 800723DC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800723E0:
    ctx->pc = 0x800723E0u;
    // 800723E0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800723E4:
    ctx->pc = 0x800723E4u;
    // 800723E4: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_800723E8:
    ctx->pc = 0x800723E8u;
    // 800723E8: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800723EC:
    ctx->pc = 0x800723ECu;
    // 800723EC: bl      0x8025C960
    {
            ctx->lr = 0x800723F0u;
            ctx->pc = 0x8025C960u;
            return;
    }

label_800723F0:
    ctx->pc = 0x800723F0u;
    ctx->downcount -= 4;
    // 800723F0: lis     r3, -32710
    ctx->gpr[3] = ((u32)(s32)(-32710) << 16);

label_800723F4:
    ctx->pc = 0x800723F4u;
    // 800723F4: addi    r3, r3, -32288
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-32288);

label_800723F8:
    ctx->pc = 0x800723F8u;
    // 800723F8: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_800723FC:
    ctx->pc = 0x800723FCu;
    // 800723FC: bl      0x8025D8B8
    {
            ctx->lr = 0x80072400u;
            ctx->pc = 0x8025D8B8u;
            return;
    }

label_80072400:
    ctx->pc = 0x80072400u;
    ctx->downcount -= 2;
    // 80072400: li      r3, 60
    ctx->gpr[3] = (u32)(s32)(60);

label_80072404:
    ctx->pc = 0x80072404u;
    // 80072404: bl      0x8025DA94
    {
            ctx->lr = 0x80072408u;
            ctx->pc = 0x8025DA94u;
            return;
    }

label_80072408:
    ctx->pc = 0x80072408u;
    ctx->downcount -= 4;
    // 80072408: li      r3, 128
    ctx->gpr[3] = (u32)(s32)(128);

label_8007240C:
    ctx->pc = 0x8007240Cu;
    // 8007240C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80072410:
    ctx->pc = 0x80072410u;
    // 80072410: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_80072414:
    ctx->pc = 0x80072414u;
    // 80072414: bl      0x8025920C
    {
            ctx->lr = 0x80072418u;
            ctx->pc = 0x8025920Cu;
            return;
    }

label_80072418:
    ctx->pc = 0x80072418u;
    ctx->downcount -= 27;
    // 80072418: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8007241C:
    ctx->pc = 0x8007241Cu;
    // 8007241C: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_80072420:
    ctx->pc = 0x80072420u;
    // 80072420: sth     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_80072424:
    ctx->pc = 0x80072424u;
    // 80072424: sth     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_80072428:
    ctx->pc = 0x80072428u;
    // 80072428: li      r4, -8
    ctx->gpr[4] = (u32)(s32)(-8);

label_8007242C:
    ctx->pc = 0x8007242Cu;
    // 8007242C: sth     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_80072430:
    ctx->pc = 0x80072430u;
    // 80072430: sth     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_80072434:
    ctx->pc = 0x80072434u;
    // 80072434: sth     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_80072438:
    ctx->pc = 0x80072438u;
    // 80072438: li      r0, 640
    ctx->gpr[0] = (u32)(s32)(640);

label_8007243C:
    ctx->pc = 0x8007243Cu;
    // 8007243C: sth     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80072440:
    ctx->pc = 0x80072440u;
    // 80072440: sth     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_80072444:
    ctx->pc = 0x80072444u;
    // 80072444: sth     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_80072448:
    ctx->pc = 0x80072448u;
    // 80072448: li      r3, 128
    ctx->gpr[3] = (u32)(s32)(128);

label_8007244C:
    ctx->pc = 0x8007244Cu;
    // 8007244C: sth     r3, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_80072450:
    ctx->pc = 0x80072450u;
    // 80072450: sth     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_80072454:
    ctx->pc = 0x80072454u;
    // 80072454: sth     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80072458:
    ctx->pc = 0x80072458u;
    // 80072458: li      r0, 480
    ctx->gpr[0] = (u32)(s32)(480);

label_8007245C:
    ctx->pc = 0x8007245Cu;
    // 8007245C: sth     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80072460:
    ctx->pc = 0x80072460u;
    // 80072460: sth     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_80072464:
    ctx->pc = 0x80072464u;
    // 80072464: sth     r3, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_80072468:
    ctx->pc = 0x80072468u;
    // 80072468: sth     r3, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_8007246C:
    ctx->pc = 0x8007246Cu;
    // 8007246C: sth     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_80072470:
    ctx->pc = 0x80072470u;
    // 80072470: sth     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80072474:
    ctx->pc = 0x80072474u;
    // 80072474: sth     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_80072478:
    ctx->pc = 0x80072478u;
    // 80072478: sth     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_8007247C:
    ctx->pc = 0x8007247Cu;
    // 8007247C: sth     r3, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_80072480:
    ctx->pc = 0x80072480u;
    // 80072480: bl      0x8000FB20
    {
            ctx->lr = 0x80072484u;
            ctx->pc = 0x8000FB20u;
            return;
    }

label_80072484:
    ctx->pc = 0x80072484u;
    ctx->downcount -= 5;
    // 80072484: lwz     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80072488:
    ctx->pc = 0x80072488u;
    // 80072488: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8007248C:
    ctx->pc = 0x8007248Cu;
    // 8007248C: addi    r1, r1, 48
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(48);

label_80072490:
    ctx->pc = 0x80072490u;
    // 80072490: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8006E6E0;
        }
    }

label_80072494:
    ctx->pc = 0x80072494u;
    ctx->downcount -= 89;
    // 80072494: stwu     r1, -304(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-304);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80072498:
    ctx->pc = 0x80072498u;
    // 80072498: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8007249C:
    ctx->pc = 0x8007249Cu;
    // 8007249C: stw     r0, 308(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(308);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800724A0:
    ctx->pc = 0x800724A0u;
    // 800724A0: stfd     f31, 288(r1)
    if (!ppc_fp_available_inline(ctx, 0x800724A0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(288);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_800724A4:
    ctx->pc = 0x800724A4u;
    // 800724A4: psq_st   f31, 296(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x800724A4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(296);
        ppc_psq_store_inline(ctx, 31u, ea, false, 0u, false, 0x800724A4u);
        if (ctx->exception) return;
    }

label_800724A8:
    ctx->pc = 0x800724A8u;
    // 800724A8: stfd     f30, 272(r1)
    if (!ppc_fp_available_inline(ctx, 0x800724A8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(272);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[30]));
    }

label_800724AC:
    ctx->pc = 0x800724ACu;
    // 800724AC: psq_st   f30, 280(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x800724ACu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(280);
        ppc_psq_store_inline(ctx, 30u, ea, false, 0u, false, 0x800724ACu);
        if (ctx->exception) return;
    }

label_800724B0:
    ctx->pc = 0x800724B0u;
    // 800724B0: fmr    f30, f1
    if (!ppc_fp_available_inline(ctx, 0x800724B0u)) return;
    ctx->fpr[30] = ctx->fpr[1];

label_800724B4:
    ctx->pc = 0x800724B4u;
    // 800724B4: fmr    f31, f2
    if (!ppc_fp_available_inline(ctx, 0x800724B4u)) return;
    ctx->fpr[31] = ctx->fpr[2];

label_800724B8:
    ctx->pc = 0x800724B8u;
    // 800724B8: lwz     r0, -30272(r2)
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30272);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800724BC:
    ctx->pc = 0x800724BCu;
    // 800724BC: stw     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800724C0:
    ctx->pc = 0x800724C0u;
    // 800724C0: lwz     r0, -30268(r2)
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800724C4:
    ctx->pc = 0x800724C4u;
    // 800724C4: stw     r0, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800724C8:
    ctx->pc = 0x800724C8u;
    // 800724C8: lwz     r0, -30264(r2)
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30264);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800724CC:
    ctx->pc = 0x800724CCu;
    // 800724CC: stw     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800724D0:
    ctx->pc = 0x800724D0u;
    // 800724D0: lwz     r0, -30260(r2)
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30260);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800724D4:
    ctx->pc = 0x800724D4u;
    // 800724D4: stw     r0, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800724D8:
    ctx->pc = 0x800724D8u;
    // 800724D8: lbz     r5, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_800724DC:
    ctx->pc = 0x800724DCu;
    // 800724DC: lbz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_800724E0:
    ctx->pc = 0x800724E0u;
    // 800724E0: srawi r7, r0, 2
    {
        u32 sh = 2u;
        u32 value = ctx->gpr[0];
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

label_800724E4:
    ctx->pc = 0x800724E4u;
    // 800724E4: add   r5, r5, r7
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[5] = res;
    }

label_800724E8:
    ctx->pc = 0x800724E8u;
    // 800724E8: rlwinm r5, r5, 0, 24, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x000000FFu;
    }

label_800724EC:
    ctx->pc = 0x800724ECu;
    // 800724EC: stb     r5, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

label_800724F0:
    ctx->pc = 0x800724F0u;
    // 800724F0: lbz     r6, 53(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(53);
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_800724F4:
    ctx->pc = 0x800724F4u;
    // 800724F4: lbz     r5, 1(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(1);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_800724F8:
    ctx->pc = 0x800724F8u;
    // 800724F8: srawi r8, r5, 2
    {
        u32 sh = 2u;
        u32 value = ctx->gpr[5];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[8] = value;
        } else if (sh > 31) {
            ctx->gpr[8] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[8] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_800724FC:
    ctx->pc = 0x800724FCu;
    // 800724FC: add   r6, r6, r8
    {
        u32 a = ctx->gpr[6];
        u32 b = ctx->gpr[8];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_80072500:
    ctx->pc = 0x80072500u;
    // 80072500: rlwinm r6, r6, 0, 24, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x000000FFu;
    }

label_80072504:
    ctx->pc = 0x80072504u;
    // 80072504: stb     r6, 53(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(53);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_80072508:
    ctx->pc = 0x80072508u;
    // 80072508: lbz     r6, 54(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(54);
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_8007250C:
    ctx->pc = 0x8007250Cu;
    // 8007250C: lbz     r4, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_80072510:
    ctx->pc = 0x80072510u;
    // 80072510: srawi r9, r4, 2
    {
        u32 sh = 2u;
        u32 value = ctx->gpr[4];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[9] = value;
        } else if (sh > 31) {
            ctx->gpr[9] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[9] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_80072514:
    ctx->pc = 0x80072514u;
    // 80072514: add   r6, r6, r9
    {
        u32 a = ctx->gpr[6];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_80072518:
    ctx->pc = 0x80072518u;
    // 80072518: rlwinm r6, r6, 0, 24, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x000000FFu;
    }

label_8007251C:
    ctx->pc = 0x8007251Cu;
    // 8007251C: stb     r6, 54(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(54);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_80072520:
    ctx->pc = 0x80072520u;
    // 80072520: lbz     r6, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_80072524:
    ctx->pc = 0x80072524u;
    // 80072524: add   r6, r6, r7
    {
        u32 a = ctx->gpr[6];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_80072528:
    ctx->pc = 0x80072528u;
    // 80072528: rlwinm r6, r6, 0, 24, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x000000FFu;
    }

label_8007252C:
    ctx->pc = 0x8007252Cu;
    // 8007252C: stb     r6, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_80072530:
    ctx->pc = 0x80072530u;
    // 80072530: lbz     r6, 49(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(49);
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_80072534:
    ctx->pc = 0x80072534u;
    // 80072534: add   r6, r6, r8
    {
        u32 a = ctx->gpr[6];
        u32 b = ctx->gpr[8];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_80072538:
    ctx->pc = 0x80072538u;
    // 80072538: rlwinm r6, r6, 0, 24, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x000000FFu;
    }

label_8007253C:
    ctx->pc = 0x8007253Cu;
    // 8007253C: stb     r6, 49(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(49);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_80072540:
    ctx->pc = 0x80072540u;
    // 80072540: lbz     r6, 50(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(50);
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_80072544:
    ctx->pc = 0x80072544u;
    // 80072544: add   r6, r6, r9
    {
        u32 a = ctx->gpr[6];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_80072548:
    ctx->pc = 0x80072548u;
    // 80072548: rlwinm r6, r6, 0, 24, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x000000FFu;
    }

label_8007254C:
    ctx->pc = 0x8007254Cu;
    // 8007254C: stb     r6, 50(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(50);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_80072550:
    ctx->pc = 0x80072550u;
    // 80072550: lbz     r6, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_80072554:
    ctx->pc = 0x80072554u;
    // 80072554: add   r6, r6, r7
    {
        u32 a = ctx->gpr[6];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_80072558:
    ctx->pc = 0x80072558u;
    // 80072558: rlwinm r6, r6, 0, 24, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x000000FFu;
    }

label_8007255C:
    ctx->pc = 0x8007255Cu;
    // 8007255C: stb     r6, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_80072560:
    ctx->pc = 0x80072560u;
    // 80072560: lbz     r6, 45(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(45);
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_80072564:
    ctx->pc = 0x80072564u;
    // 80072564: add   r6, r6, r8
    {
        u32 a = ctx->gpr[6];
        u32 b = ctx->gpr[8];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_80072568:
    ctx->pc = 0x80072568u;
    // 80072568: rlwinm r6, r6, 0, 24, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x000000FFu;
    }

label_8007256C:
    ctx->pc = 0x8007256Cu;
    // 8007256C: stb     r6, 45(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(45);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_80072570:
    ctx->pc = 0x80072570u;
    // 80072570: lbz     r6, 46(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(46);
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_80072574:
    ctx->pc = 0x80072574u;
    // 80072574: add   r6, r6, r9
    {
        u32 a = ctx->gpr[6];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_80072578:
    ctx->pc = 0x80072578u;
    // 80072578: rlwinm r6, r6, 0, 24, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x000000FFu;
    }

label_8007257C:
    ctx->pc = 0x8007257Cu;
    // 8007257C: stb     r6, 46(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(46);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_80072580:
    ctx->pc = 0x80072580u;
    // 80072580: lbz     r6, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_80072584:
    ctx->pc = 0x80072584u;
    // 80072584: srawi r0, r0, 3
    {
        u32 sh = 3u;
        u32 value = ctx->gpr[0];
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

label_80072588:
    ctx->pc = 0x80072588u;
    // 80072588: add   r0, r6, r0
    {
        u32 a = ctx->gpr[6];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8007258C:
    ctx->pc = 0x8007258Cu;
    // 8007258C: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_80072590:
    ctx->pc = 0x80072590u;
    // 80072590: stb     r0, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80072594:
    ctx->pc = 0x80072594u;
    // 80072594: lbz     r6, 41(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(41);
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_80072598:
    ctx->pc = 0x80072598u;
    // 80072598: srawi r0, r5, 3
    {
        u32 sh = 3u;
        u32 value = ctx->gpr[5];
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

label_8007259C:
    ctx->pc = 0x8007259Cu;
    // 8007259C: add   r0, r6, r0
    {
        u32 a = ctx->gpr[6];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_800725A0:
    ctx->pc = 0x800725A0u;
    // 800725A0: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_800725A4:
    ctx->pc = 0x800725A4u;
    // 800725A4: stb     r0, 41(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(41);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_800725A8:
    ctx->pc = 0x800725A8u;
    // 800725A8: lbz     r5, 42(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(42);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_800725AC:
    ctx->pc = 0x800725ACu;
    // 800725AC: srawi r0, r4, 3
    {
        u32 sh = 3u;
        u32 value = ctx->gpr[4];
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

label_800725B0:
    ctx->pc = 0x800725B0u;
    // 800725B0: add   r0, r5, r0
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_800725B4:
    ctx->pc = 0x800725B4u;
    // 800725B4: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_800725B8:
    ctx->pc = 0x800725B8u;
    // 800725B8: stb     r0, 42(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(42);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_800725BC:
    ctx->pc = 0x800725BCu;
    // 800725BC: lfs     f1, 0(r3)
    if (!ppc_fp_available_inline(ctx, 0x800725BCu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800725C0:
    ctx->pc = 0x800725C0u;
    // 800725C0: lfs     f3, 8(r3)
    if (!ppc_fp_available_inline(ctx, 0x800725C0u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_800725C4:
    ctx->pc = 0x800725C4u;
    // 800725C4: lfs     f0, -25520(r13)
    if (!ppc_fp_available_inline(ctx, 0x800725C4u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25520);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800725C8:
    ctx->pc = 0x800725C8u;
    // 800725C8: fsubs   f1, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x800725C8u)) return;
    ppc_fsubs(ctx, 1, 1, 0);

label_800725CC:
    ctx->pc = 0x800725CCu;
    // 800725CC: lfs     f0, -25516(r13)
    if (!ppc_fp_available_inline(ctx, 0x800725CCu)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25516);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800725D0:
    ctx->pc = 0x800725D0u;
    // 800725D0: fsubs   f3, f3, f0
    if (!ppc_fp_available_inline(ctx, 0x800725D0u)) return;
    ppc_fsubs(ctx, 3, 3, 0);

label_800725D4:
    ctx->pc = 0x800725D4u;
    // 800725D4: lfs     f2, 4(r3)
    if (!ppc_fp_available_inline(ctx, 0x800725D4u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_800725D8:
    ctx->pc = 0x800725D8u;
    // 800725D8: fmr    f4, f30
    if (!ppc_fp_available_inline(ctx, 0x800725D8u)) return;
    ctx->fpr[4] = ctx->fpr[30];

label_800725DC:
    ctx->pc = 0x800725DCu;
    // 800725DC: addi    r3, r1, 76
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(76);

label_800725E0:
    ctx->pc = 0x800725E0u;
    // 800725E0: addi    r4, r1, 72
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(72);

label_800725E4:
    ctx->pc = 0x800725E4u;
    // 800725E4: addi    r5, r1, 68
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(68);

label_800725E8:
    ctx->pc = 0x800725E8u;
    // 800725E8: addi    r6, r1, 64
    ctx->gpr[6] = ctx->gpr[1] + (u32)(s32)(64);

label_800725EC:
    ctx->pc = 0x800725ECu;
    // 800725EC: addi    r7, r1, 60
    ctx->gpr[7] = ctx->gpr[1] + (u32)(s32)(60);

label_800725F0:
    ctx->pc = 0x800725F0u;
    // 800725F0: addi    r8, r1, 56
    ctx->gpr[8] = ctx->gpr[1] + (u32)(s32)(56);

label_800725F4:
    ctx->pc = 0x800725F4u;
    // 800725F4: bl      0x8000EBA8
    {
            ctx->lr = 0x800725F8u;
            ctx->pc = 0x8000EBA8u;
            return;
    }

label_800725F8:
    ctx->pc = 0x800725F8u;
    ctx->downcount -= 7;
    // 800725F8: lfs     f1, 68(r1)
    if (!ppc_fp_available_inline(ctx, 0x800725F8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800725FC:
    ctx->pc = 0x800725FCu;
    // 800725FC: lfs     f0, -30228(r2)
    if (!ppc_fp_available_inline(ctx, 0x800725FCu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30228);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80072600:
    ctx->pc = 0x80072600u;
    // 80072600: fadds   f1, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x80072600u)) return;
    ppc_fadds(ctx, 1, 1, 0);

label_80072604:
    ctx->pc = 0x80072604u;
    // 80072604: stfs     f1, 68(r1)
    if (!ppc_fp_available_inline(ctx, 0x80072604u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80072608:
    ctx->pc = 0x80072608u;
    // 80072608: lfs     f0, -30192(r2)
    if (!ppc_fp_available_inline(ctx, 0x80072608u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30192);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8007260C:
    ctx->pc = 0x8007260Cu;
    // 8007260C: fmuls   f1, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8007260Cu)) return;
    ppc_fmuls(ctx, 1, 0, 1);

label_80072610:
    ctx->pc = 0x80072610u;
    // 80072610: bl      0x80286924
    {
            ctx->lr = 0x80072614u;
            ctx->pc = 0x80286924u;
            return;
    }

label_80072614:
    ctx->pc = 0x80072614u;
    ctx->downcount -= 6;
    // 80072614: rlwinm r0, r3, 0, 8, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00FF0000u;
    }

label_80072618:
    ctx->pc = 0x80072618u;
    // 80072618: rlwinm r0, r0, 16, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0x0000FFFFu;
    }

label_8007261C:
    ctx->pc = 0x8007261Cu;
    // 8007261C: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_80072620:
    ctx->pc = 0x80072620u;
    // 80072620: stb     r0, 55(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(55);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80072624:
    ctx->pc = 0x80072624u;
    // 80072624: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80072628:
    ctx->pc = 0x80072628u;
    // 80072628: bl      0x8006C8D4
    {
            ctx->lr = 0x8007262Cu;
            ctx->pc = 0x8006C8D4u;
            return;
    }

label_8007262C:
    ctx->pc = 0x8007262Cu;
    ctx->downcount -= 2;
    // 8007262C: addi    r3, r1, 84
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(84);

label_80072630:
    ctx->pc = 0x80072630u;
    // 80072630: bl      0x8006C7BC
    {
            ctx->lr = 0x80072634u;
            ctx->pc = 0x8006C7BCu;
            return;
    }

label_80072634:
    ctx->pc = 0x80072634u;
    ctx->downcount -= 3;
    // 80072634: lwz     r3, 84(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80072638:
    ctx->pc = 0x80072638u;
    // 80072638: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8007263C:
    ctx->pc = 0x8007263Cu;
    // 8007263C: bl      0x8004C4C8
    {
            ctx->lr = 0x80072640u;
            ctx->pc = 0x8004C4C8u;
            return;
    }

label_80072640:
    ctx->pc = 0x80072640u;
    ctx->downcount -= 2;
    // 80072640: addi    r3, r1, 80
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(80);

label_80072644:
    ctx->pc = 0x80072644u;
    // 80072644: bl      0x8006C724
    {
            ctx->lr = 0x80072648u;
            ctx->pc = 0x8006C724u;
            return;
    }

label_80072648:
    ctx->pc = 0x80072648u;
    ctx->downcount -= 3;
    // 80072648: lwz     r3, 80(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8007264C:
    ctx->pc = 0x8007264Cu;
    // 8007264C: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80072650:
    ctx->pc = 0x80072650u;
    // 80072650: bl      0x8004C4C8
    {
            ctx->lr = 0x80072654u;
            ctx->pc = 0x8004C4C8u;
            return;
    }

label_80072654:
    ctx->pc = 0x80072654u;
    ctx->downcount -= 6;
    // 80072654: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80072658:
    ctx->pc = 0x80072658u;
    // 80072658: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8007265C:
    ctx->pc = 0x8007265Cu;
    // 8007265C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80072660:
    ctx->pc = 0x80072660u;
    // 80072660: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80072664:
    ctx->pc = 0x80072664u;
    // 80072664: li      r7, 3
    ctx->gpr[7] = (u32)(s32)(3);

label_80072668:
    ctx->pc = 0x80072668u;
    // 80072668: bl      0x8025C8C0
    {
            ctx->lr = 0x8007266Cu;
            ctx->pc = 0x8025C8C0u;
            return;
    }

label_8007266C:
    ctx->pc = 0x8007266Cu;
    ctx->downcount -= 6;
    // 8007266C: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80072670:
    ctx->pc = 0x80072670u;
    // 80072670: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80072674:
    ctx->pc = 0x80072674u;
    // 80072674: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80072678:
    ctx->pc = 0x80072678u;
    // 80072678: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_8007267C:
    ctx->pc = 0x8007267Cu;
    // 8007267C: li      r7, 3
    ctx->gpr[7] = (u32)(s32)(3);

label_80072680:
    ctx->pc = 0x80072680u;
    // 80072680: bl      0x8025C8C0
    {
            ctx->lr = 0x80072684u;
            ctx->pc = 0x8025C8C0u;
            return;
    }

label_80072684:
    ctx->pc = 0x80072684u;
    ctx->downcount -= 6;
    // 80072684: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_80072688:
    ctx->pc = 0x80072688u;
    // 80072688: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_8007268C:
    ctx->pc = 0x8007268Cu;
    // 8007268C: li      r5, 2
    ctx->gpr[5] = (u32)(s32)(2);

label_80072690:
    ctx->pc = 0x80072690u;
    // 80072690: li      r6, 2
    ctx->gpr[6] = (u32)(s32)(2);

label_80072694:
    ctx->pc = 0x80072694u;
    // 80072694: li      r7, 3
    ctx->gpr[7] = (u32)(s32)(3);

label_80072698:
    ctx->pc = 0x80072698u;
    // 80072698: bl      0x8025C8C0
    {
            ctx->lr = 0x8007269Cu;
            ctx->pc = 0x8025C8C0u;
            return;
    }

label_8007269C:
    ctx->pc = 0x8007269Cu;
    ctx->downcount -= 7;
    // 8007269C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800726A0:
    ctx->pc = 0x800726A0u;
    // 800726A0: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_800726A4:
    ctx->pc = 0x800726A4u;
    // 800726A4: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_800726A8:
    ctx->pc = 0x800726A8u;
    // 800726A8: li      r6, 60
    ctx->gpr[6] = (u32)(s32)(60);

label_800726AC:
    ctx->pc = 0x800726ACu;
    // 800726AC: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800726B0:
    ctx->pc = 0x800726B0u;
    // 800726B0: li      r8, 125
    ctx->gpr[8] = (u32)(s32)(125);

label_800726B4:
    ctx->pc = 0x800726B4u;
    // 800726B4: bl      0x80258880
    {
            ctx->lr = 0x800726B8u;
            ctx->pc = 0x80258880u;
            return;
    }

label_800726B8:
    ctx->pc = 0x800726B8u;
    ctx->downcount -= 7;
    // 800726B8: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_800726BC:
    ctx->pc = 0x800726BCu;
    // 800726BC: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_800726C0:
    ctx->pc = 0x800726C0u;
    // 800726C0: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_800726C4:
    ctx->pc = 0x800726C4u;
    // 800726C4: li      r6, 60
    ctx->gpr[6] = (u32)(s32)(60);

label_800726C8:
    ctx->pc = 0x800726C8u;
    // 800726C8: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800726CC:
    ctx->pc = 0x800726CCu;
    // 800726CC: li      r8, 125
    ctx->gpr[8] = (u32)(s32)(125);

label_800726D0:
    ctx->pc = 0x800726D0u;
    // 800726D0: bl      0x80258880
    {
            ctx->lr = 0x800726D4u;
            ctx->pc = 0x80258880u;
            return;
    }

label_800726D4:
    ctx->pc = 0x800726D4u;
    ctx->downcount -= 3;
    // 800726D4: addi    r3, r1, 160
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(160);

label_800726D8:
    ctx->pc = 0x800726D8u;
    // 800726D8: lfs     f2, -30208(r2)
    if (!ppc_fp_available_inline(ctx, 0x800726D8u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-30208);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_800726DC:
    ctx->pc = 0x800726DCu;
    // 800726DC: lfs     f0, 76(r1)
    if (!ppc_fp_available_inline(ctx, 0x800726DCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(76);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

    ctx->pc = 0x800726E0u;
    return;
return_dispatch_8006E6E0:
    if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) return;
    switch (ctx->pc) {
    case 0x8006E750u: goto label_8006E750;
    case 0x8006E77Cu: goto label_8006E77C;
    case 0x8006E790u: goto label_8006E790;
    case 0x8006E798u: goto label_8006E798;
    case 0x8006E7C4u: goto label_8006E7C4;
    case 0x8006E930u: goto label_8006E930;
    case 0x8006E95Cu: goto label_8006E95C;
    case 0x8006EB30u: goto label_8006EB30;
    case 0x8006EB5Cu: goto label_8006EB5C;
    case 0x8006EC8Cu: goto label_8006EC8C;
    case 0x8006ECB8u: goto label_8006ECB8;
    case 0x8006ECCCu: goto label_8006ECCC;
    case 0x8006ECE0u: goto label_8006ECE0;
    case 0x8006ED10u: goto label_8006ED10;
    case 0x8006ED24u: goto label_8006ED24;
    case 0x8006ED38u: goto label_8006ED38;
    case 0x8006ED68u: goto label_8006ED68;
    case 0x8006ED7Cu: goto label_8006ED7C;
    case 0x8006ED90u: goto label_8006ED90;
    case 0x8006ED98u: goto label_8006ED98;
    case 0x8006EE68u: goto label_8006EE68;
    case 0x8006EE70u: goto label_8006EE70;
    case 0x8006EEF8u: goto label_8006EEF8;
    case 0x8006EFCCu: goto label_8006EFCC;
    case 0x8006EFF8u: goto label_8006EFF8;
    case 0x8006F0FCu: goto label_8006F0FC;
    case 0x8006F10Cu: goto label_8006F10C;
    case 0x8006F138u: goto label_8006F138;
    case 0x8006F33Cu: goto label_8006F33C;
    case 0x8006F344u: goto label_8006F344;
    case 0x8006F368u: goto label_8006F368;
    case 0x8006F378u: goto label_8006F378;
    case 0x8006F398u: goto label_8006F398;
    case 0x8006F414u: goto label_8006F414;
    case 0x8006F488u: goto label_8006F488;
    case 0x8006F4C0u: goto label_8006F4C0;
    case 0x8006F4E8u: goto label_8006F4E8;
    case 0x8006F520u: goto label_8006F520;
    case 0x8006F55Cu: goto label_8006F55C;
    case 0x8006F70Cu: goto label_8006F70C;
    case 0x8006F718u: goto label_8006F718;
    case 0x8006F720u: goto label_8006F720;
    case 0x8006F724u: goto label_8006F724;
    case 0x8006F730u: goto label_8006F730;
    case 0x8006F73Cu: goto label_8006F73C;
    case 0x8006F744u: goto label_8006F744;
    case 0x8006F760u: goto label_8006F760;
    case 0x8006F768u: goto label_8006F768;
    case 0x8006F770u: goto label_8006F770;
    case 0x8006F790u: goto label_8006F790;
    case 0x8006F7B0u: goto label_8006F7B0;
    case 0x8006F7B8u: goto label_8006F7B8;
    case 0x8006F7CCu: goto label_8006F7CC;
    case 0x8006F7D4u: goto label_8006F7D4;
    case 0x8006F7ECu: goto label_8006F7EC;
    case 0x8006F7F8u: goto label_8006F7F8;
    case 0x8006F810u: goto label_8006F810;
    case 0x8006F82Cu: goto label_8006F82C;
    case 0x8006F848u: goto label_8006F848;
    case 0x8006F858u: goto label_8006F858;
    case 0x8006F860u: goto label_8006F860;
    case 0x8006F874u: goto label_8006F874;
    case 0x8006F890u: goto label_8006F890;
    case 0x8006F894u: goto label_8006F894;
    case 0x8006F8B4u: goto label_8006F8B4;
    case 0x8006F8C4u: goto label_8006F8C4;
    case 0x8006F8D0u: goto label_8006F8D0;
    case 0x8006F8E0u: goto label_8006F8E0;
    case 0x8006F8E8u: goto label_8006F8E8;
    case 0x8006F900u: goto label_8006F900;
    case 0x8006F954u: goto label_8006F954;
    case 0x8006F9B8u: goto label_8006F9B8;
    case 0x8006FA04u: goto label_8006FA04;
    case 0x8006FA18u: goto label_8006FA18;
    case 0x8006FA28u: goto label_8006FA28;
    case 0x8006FA3Cu: goto label_8006FA3C;
    case 0x8006FA4Cu: goto label_8006FA4C;
    case 0x8006FA5Cu: goto label_8006FA5C;
    case 0x8006FA6Cu: goto label_8006FA6C;
    case 0x8006FB0Cu: goto label_8006FB0C;
    case 0x8006FB50u: goto label_8006FB50;
    case 0x8006FBB4u: goto label_8006FBB4;
    case 0x8006FC34u: goto label_8006FC34;
    case 0x8006FC54u: goto label_8006FC54;
    case 0x8006FC88u: goto label_8006FC88;
    case 0x8006FC98u: goto label_8006FC98;
    case 0x8006FCA4u: goto label_8006FCA4;
    case 0x8006FCB0u: goto label_8006FCB0;
    case 0x8006FCCCu: goto label_8006FCCC;
    case 0x8006FCDCu: goto label_8006FCDC;
    case 0x8006FDD4u: goto label_8006FDD4;
    case 0x8006FF70u: goto label_8006FF70;
    case 0x8006FF7Cu: goto label_8006FF7C;
    case 0x8006FF88u: goto label_8006FF88;
    case 0x8006FF94u: goto label_8006FF94;
    case 0x8007015Cu: goto label_8007015C;
    case 0x800701A4u: goto label_800701A4;
    case 0x800701B0u: goto label_800701B0;
    case 0x80070330u: goto label_80070330;
    case 0x800703D0u: goto label_800703D0;
    case 0x800704D4u: goto label_800704D4;
    case 0x80070560u: goto label_80070560;
    case 0x800705D8u: goto label_800705D8;
    case 0x80070610u: goto label_80070610;
    case 0x80070618u: goto label_80070618;
    case 0x800706A0u: goto label_800706A0;
    case 0x80070708u: goto label_80070708;
    case 0x80070724u: goto label_80070724;
    case 0x80070730u: goto label_80070730;
    case 0x80070738u: goto label_80070738;
    case 0x80070740u: goto label_80070740;
    case 0x80070748u: goto label_80070748;
    case 0x80070750u: goto label_80070750;
    case 0x80070794u: goto label_80070794;
    case 0x800707A0u: goto label_800707A0;
    case 0x800707B4u: goto label_800707B4;
    case 0x800707D0u: goto label_800707D0;
    case 0x800707E4u: goto label_800707E4;
    case 0x80070800u: goto label_80070800;
    case 0x8007080Cu: goto label_8007080C;
    case 0x80070820u: goto label_80070820;
    case 0x8007083Cu: goto label_8007083C;
    case 0x80070858u: goto label_80070858;
    case 0x80070874u: goto label_80070874;
    case 0x80070878u: goto label_80070878;
    case 0x800708ECu: goto label_800708EC;
    case 0x8007093Cu: goto label_8007093C;
    case 0x80070950u: goto label_80070950;
    case 0x8007095Cu: goto label_8007095C;
    case 0x8007096Cu: goto label_8007096C;
    case 0x8007097Cu: goto label_8007097C;
    case 0x80070990u: goto label_80070990;
    case 0x800709A4u: goto label_800709A4;
    case 0x800709D4u: goto label_800709D4;
    case 0x80070A04u: goto label_80070A04;
    case 0x80070A18u: goto label_80070A18;
    case 0x80070A30u: goto label_80070A30;
    case 0x80070A48u: goto label_80070A48;
    case 0x80070A58u: goto label_80070A58;
    case 0x80070A5Cu: goto label_80070A5C;
    case 0x80070A84u: goto label_80070A84;
    case 0x80070AA4u: goto label_80070AA4;
    case 0x80070AC0u: goto label_80070AC0;
    case 0x80070AD4u: goto label_80070AD4;
    case 0x80070AECu: goto label_80070AEC;
    case 0x80070B04u: goto label_80070B04;
    case 0x80070B14u: goto label_80070B14;
    case 0x80070B30u: goto label_80070B30;
    case 0x80070B4Cu: goto label_80070B4C;
    case 0x80070B54u: goto label_80070B54;
    case 0x80070B68u: goto label_80070B68;
    case 0x80070B80u: goto label_80070B80;
    case 0x80070B98u: goto label_80070B98;
    case 0x80070BA8u: goto label_80070BA8;
    case 0x80070BC4u: goto label_80070BC4;
    case 0x80070BE0u: goto label_80070BE0;
    case 0x80070C00u: goto label_80070C00;
    case 0x80070C20u: goto label_80070C20;
    case 0x80070C28u: goto label_80070C28;
    case 0x80070C30u: goto label_80070C30;
    case 0x80070C38u: goto label_80070C38;
    case 0x80070C40u: goto label_80070C40;
    case 0x80070C48u: goto label_80070C48;
    case 0x80070C68u: goto label_80070C68;
    case 0x80070CACu: goto label_80070CAC;
    case 0x80070CFCu: goto label_80070CFC;
    case 0x80070D30u: goto label_80070D30;
    case 0x80070D84u: goto label_80070D84;
    case 0x80070DA0u: goto label_80070DA0;
    case 0x80070DA8u: goto label_80070DA8;
    case 0x80070DC0u: goto label_80070DC0;
    case 0x80070E04u: goto label_80070E04;
    case 0x80070E38u: goto label_80070E38;
    case 0x80070E5Cu: goto label_80070E5C;
    case 0x80070EACu: goto label_80070EAC;
    case 0x80070F0Cu: goto label_80070F0C;
    case 0x80070F3Cu: goto label_80070F3C;
    case 0x80070F54u: goto label_80070F54;
    case 0x80070FA4u: goto label_80070FA4;
    case 0x80071004u: goto label_80071004;
    case 0x80071034u: goto label_80071034;
    case 0x8007106Cu: goto label_8007106C;
    case 0x80071090u: goto label_80071090;
    case 0x8007109Cu: goto label_8007109C;
    case 0x800710A8u: goto label_800710A8;
    case 0x800710D8u: goto label_800710D8;
    case 0x800710E0u: goto label_800710E0;
    case 0x800710E4u: goto label_800710E4;
    case 0x800710ECu: goto label_800710EC;
    case 0x800710F8u: goto label_800710F8;
    case 0x80071114u: goto label_80071114;
    case 0x80071128u: goto label_80071128;
    case 0x8007113Cu: goto label_8007113C;
    case 0x80071150u: goto label_80071150;
    case 0x8007116Cu: goto label_8007116C;
    case 0x80071180u: goto label_80071180;
    case 0x8007119Cu: goto label_8007119C;
    case 0x800711B8u: goto label_800711B8;
    case 0x800711CCu: goto label_800711CC;
    case 0x800711DCu: goto label_800711DC;
    case 0x800711ECu: goto label_800711EC;
    case 0x80071208u: goto label_80071208;
    case 0x80071224u: goto label_80071224;
    case 0x80071238u: goto label_80071238;
    case 0x80071240u: goto label_80071240;
    case 0x80071258u: goto label_80071258;
    case 0x80071270u: goto label_80071270;
    case 0x80071280u: goto label_80071280;
    case 0x8007129Cu: goto label_8007129C;
    case 0x800712B8u: goto label_800712B8;
    case 0x800712C8u: goto label_800712C8;
    case 0x800712D8u: goto label_800712D8;
    case 0x800712ECu: goto label_800712EC;
    case 0x80071320u: goto label_80071320;
    case 0x80071330u: goto label_80071330;
    case 0x80071340u: goto label_80071340;
    case 0x80071354u: goto label_80071354;
    case 0x80071388u: goto label_80071388;
    case 0x8007139Cu: goto label_8007139C;
    case 0x800713B4u: goto label_800713B4;
    case 0x800713CCu: goto label_800713CC;
    case 0x800713DCu: goto label_800713DC;
    case 0x800713F8u: goto label_800713F8;
    case 0x80071414u: goto label_80071414;
    case 0x80071428u: goto label_80071428;
    case 0x80071440u: goto label_80071440;
    case 0x80071458u: goto label_80071458;
    case 0x80071468u: goto label_80071468;
    case 0x80071484u: goto label_80071484;
    case 0x800714A0u: goto label_800714A0;
    case 0x800714ACu: goto label_800714AC;
    case 0x800714B8u: goto label_800714B8;
    case 0x800714C0u: goto label_800714C0;
    case 0x800714D4u: goto label_800714D4;
    case 0x800714ECu: goto label_800714EC;
    case 0x80071504u: goto label_80071504;
    case 0x80071514u: goto label_80071514;
    case 0x80071530u: goto label_80071530;
    case 0x8007154Cu: goto label_8007154C;
    case 0x80071558u: goto label_80071558;
    case 0x80071564u: goto label_80071564;
    case 0x8007156Cu: goto label_8007156C;
    case 0x80071580u: goto label_80071580;
    case 0x80071598u: goto label_80071598;
    case 0x800715B0u: goto label_800715B0;
    case 0x800715C0u: goto label_800715C0;
    case 0x800715DCu: goto label_800715DC;
    case 0x800715F8u: goto label_800715F8;
    case 0x80071604u: goto label_80071604;
    case 0x80071618u: goto label_80071618;
    case 0x80071620u: goto label_80071620;
    case 0x80071638u: goto label_80071638;
    case 0x80071650u: goto label_80071650;
    case 0x80071660u: goto label_80071660;
    case 0x8007167Cu: goto label_8007167C;
    case 0x80071698u: goto label_80071698;
    case 0x800716A4u: goto label_800716A4;
    case 0x800716B0u: goto label_800716B0;
    case 0x800716C4u: goto label_800716C4;
    case 0x800716D8u: goto label_800716D8;
    case 0x800716E0u: goto label_800716E0;
    case 0x800716F8u: goto label_800716F8;
    case 0x80071710u: goto label_80071710;
    case 0x80071720u: goto label_80071720;
    case 0x8007173Cu: goto label_8007173C;
    case 0x80071758u: goto label_80071758;
    case 0x80071764u: goto label_80071764;
    case 0x8007176Cu: goto label_8007176C;
    case 0x80071780u: goto label_80071780;
    case 0x80071798u: goto label_80071798;
    case 0x800717B0u: goto label_800717B0;
    case 0x800717C0u: goto label_800717C0;
    case 0x800717DCu: goto label_800717DC;
    case 0x800717F8u: goto label_800717F8;
    case 0x80071800u: goto label_80071800;
    case 0x80071808u: goto label_80071808;
    case 0x80071828u: goto label_80071828;
    case 0x80071848u: goto label_80071848;
    case 0x80071850u: goto label_80071850;
    case 0x80071858u: goto label_80071858;
    case 0x8007185Cu: goto label_8007185C;
    case 0x80071868u: goto label_80071868;
    case 0x80071874u: goto label_80071874;
    case 0x8007187Cu: goto label_8007187C;
    case 0x80071890u: goto label_80071890;
    case 0x800718D0u: goto label_800718D0;
    case 0x8007190Cu: goto label_8007190C;
    case 0x80071930u: goto label_80071930;
    case 0x80071940u: goto label_80071940;
    case 0x80071948u: goto label_80071948;
    case 0x80071958u: goto label_80071958;
    case 0x800719C4u: goto label_800719C4;
    case 0x800719CCu: goto label_800719CC;
    case 0x800719F0u: goto label_800719F0;
    case 0x800719F8u: goto label_800719F8;
    case 0x80071A10u: goto label_80071A10;
    case 0x80071A28u: goto label_80071A28;
    case 0x80071A40u: goto label_80071A40;
    case 0x80071A58u: goto label_80071A58;
    case 0x80071A74u: goto label_80071A74;
    case 0x80071A88u: goto label_80071A88;
    case 0x80071A9Cu: goto label_80071A9C;
    case 0x80071AB0u: goto label_80071AB0;
    case 0x80071AC4u: goto label_80071AC4;
    case 0x80071ACCu: goto label_80071ACC;
    case 0x80071AD4u: goto label_80071AD4;
    case 0x80071AF4u: goto label_80071AF4;
    case 0x80071B14u: goto label_80071B14;
    case 0x80071B1Cu: goto label_80071B1C;
    case 0x80071B24u: goto label_80071B24;
    case 0x80071B30u: goto label_80071B30;
    case 0x80071B38u: goto label_80071B38;
    case 0x80071B4Cu: goto label_80071B4C;
    case 0x80071B64u: goto label_80071B64;
    case 0x80071B7Cu: goto label_80071B7C;
    case 0x80071B8Cu: goto label_80071B8C;
    case 0x80071BA8u: goto label_80071BA8;
    case 0x80071BC4u: goto label_80071BC4;
    case 0x80071BD0u: goto label_80071BD0;
    case 0x80071BDCu: goto label_80071BDC;
    case 0x80071BE4u: goto label_80071BE4;
    case 0x80071BF8u: goto label_80071BF8;
    case 0x80071C10u: goto label_80071C10;
    case 0x80071C28u: goto label_80071C28;
    case 0x80071C38u: goto label_80071C38;
    case 0x80071C54u: goto label_80071C54;
    case 0x80071C70u: goto label_80071C70;
    case 0x80071C7Cu: goto label_80071C7C;
    case 0x80071C84u: goto label_80071C84;
    case 0x80071C98u: goto label_80071C98;
    case 0x80071CB0u: goto label_80071CB0;
    case 0x80071CC8u: goto label_80071CC8;
    case 0x80071CD8u: goto label_80071CD8;
    case 0x80071CF4u: goto label_80071CF4;
    case 0x80071D10u: goto label_80071D10;
    case 0x80071D18u: goto label_80071D18;
    case 0x80071D2Cu: goto label_80071D2C;
    case 0x80071D44u: goto label_80071D44;
    case 0x80071D5Cu: goto label_80071D5C;
    case 0x80071D6Cu: goto label_80071D6C;
    case 0x80071D88u: goto label_80071D88;
    case 0x80071DA4u: goto label_80071DA4;
    case 0x80071DA8u: goto label_80071DA8;
    case 0x80071DB4u: goto label_80071DB4;
    case 0x80071DC0u: goto label_80071DC0;
    case 0x80071DC8u: goto label_80071DC8;
    case 0x80071DDCu: goto label_80071DDC;
    case 0x80071E1Cu: goto label_80071E1C;
    case 0x80071E58u: goto label_80071E58;
    case 0x80071E7Cu: goto label_80071E7C;
    case 0x80071E8Cu: goto label_80071E8C;
    case 0x80071E94u: goto label_80071E94;
    case 0x80071EA4u: goto label_80071EA4;
    case 0x80071F10u: goto label_80071F10;
    case 0x80071F28u: goto label_80071F28;
    case 0x80072010u: goto label_80072010;
    case 0x80072018u: goto label_80072018;
    case 0x80072030u: goto label_80072030;
    case 0x80072048u: goto label_80072048;
    case 0x80072060u: goto label_80072060;
    case 0x8007207Cu: goto label_8007207C;
    case 0x80072090u: goto label_80072090;
    case 0x800720A4u: goto label_800720A4;
    case 0x800720B8u: goto label_800720B8;
    case 0x800720CCu: goto label_800720CC;
    case 0x800720D4u: goto label_800720D4;
    case 0x800720DCu: goto label_800720DC;
    case 0x800720FCu: goto label_800720FC;
    case 0x8007211Cu: goto label_8007211C;
    case 0x80072124u: goto label_80072124;
    case 0x8007212Cu: goto label_8007212C;
    case 0x80072138u: goto label_80072138;
    case 0x80072140u: goto label_80072140;
    case 0x80072154u: goto label_80072154;
    case 0x8007216Cu: goto label_8007216C;
    case 0x80072184u: goto label_80072184;
    case 0x80072194u: goto label_80072194;
    case 0x800721B0u: goto label_800721B0;
    case 0x800721CCu: goto label_800721CC;
    case 0x800721D8u: goto label_800721D8;
    case 0x800721E4u: goto label_800721E4;
    case 0x800721ECu: goto label_800721EC;
    case 0x80072200u: goto label_80072200;
    case 0x80072218u: goto label_80072218;
    case 0x80072230u: goto label_80072230;
    case 0x80072240u: goto label_80072240;
    case 0x8007225Cu: goto label_8007225C;
    case 0x80072278u: goto label_80072278;
    case 0x80072284u: goto label_80072284;
    case 0x8007228Cu: goto label_8007228C;
    case 0x800722A0u: goto label_800722A0;
    case 0x800722B8u: goto label_800722B8;
    case 0x800722D0u: goto label_800722D0;
    case 0x800722E0u: goto label_800722E0;
    case 0x800722FCu: goto label_800722FC;
    case 0x80072318u: goto label_80072318;
    case 0x8007231Cu: goto label_8007231C;
    case 0x80072328u: goto label_80072328;
    case 0x80072334u: goto label_80072334;
    case 0x8007233Cu: goto label_8007233C;
    case 0x80072350u: goto label_80072350;
    case 0x80072390u: goto label_80072390;
    case 0x800723CCu: goto label_800723CC;
    case 0x800723F0u: goto label_800723F0;
    case 0x80072400u: goto label_80072400;
    case 0x80072408u: goto label_80072408;
    case 0x80072418u: goto label_80072418;
    case 0x80072484u: goto label_80072484;
    case 0x800725F8u: goto label_800725F8;
    case 0x80072614u: goto label_80072614;
    case 0x8007262Cu: goto label_8007262C;
    case 0x80072634u: goto label_80072634;
    case 0x80072640u: goto label_80072640;
    case 0x80072648u: goto label_80072648;
    case 0x80072654u: goto label_80072654;
    case 0x8007266Cu: goto label_8007266C;
    case 0x80072684u: goto label_80072684;
    case 0x8007269Cu: goto label_8007269C;
    case 0x800726B8u: goto label_800726B8;
    case 0x800726D4u: goto label_800726D4;
    default: return;
    }
}

