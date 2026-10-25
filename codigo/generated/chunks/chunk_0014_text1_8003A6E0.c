// DolRecomp output
#include "../generated.h"

static void loop_8003AB6C(CPUState* ctx) {
label_8003AB6C:
    ctx->downcount -= 18;
    ctx->pc = 0x8003AB6Cu;
    // 8003AB6C: sth     r5, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        mem_write16(ctx, ea, (u16)ctx->gpr[5]);
    }

    ctx->pc = 0x8003AB70u;
    // 8003AB70: sth     r6, 68(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(68);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

    ctx->pc = 0x8003AB74u;
    // 8003AB74: sth     r5, 116(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(116);
        mem_write16(ctx, ea, (u16)ctx->gpr[5]);
    }

    ctx->pc = 0x8003AB78u;
    // 8003AB78: sth     r6, 164(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(164);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

    ctx->pc = 0x8003AB7Cu;
    // 8003AB7C: sth     r5, 212(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(212);
        mem_write16(ctx, ea, (u16)ctx->gpr[5]);
    }

    ctx->pc = 0x8003AB80u;
    // 8003AB80: sth     r6, 260(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(260);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

    ctx->pc = 0x8003AB84u;
    // 8003AB84: sth     r5, 308(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(308);
        mem_write16(ctx, ea, (u16)ctx->gpr[5]);
    }

    ctx->pc = 0x8003AB88u;
    // 8003AB88: sth     r6, 356(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(356);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

    ctx->pc = 0x8003AB8Cu;
    // 8003AB8C: sth     r5, 404(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(404);
        mem_write16(ctx, ea, (u16)ctx->gpr[5]);
    }

    ctx->pc = 0x8003AB90u;
    // 8003AB90: sth     r6, 452(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(452);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

    ctx->pc = 0x8003AB94u;
    // 8003AB94: sth     r5, 500(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(500);
        mem_write16(ctx, ea, (u16)ctx->gpr[5]);
    }

    ctx->pc = 0x8003AB98u;
    // 8003AB98: sth     r6, 548(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(548);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

    ctx->pc = 0x8003AB9Cu;
    // 8003AB9C: sth     r5, 596(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(596);
        mem_write16(ctx, ea, (u16)ctx->gpr[5]);
    }

    ctx->pc = 0x8003ABA0u;
    // 8003ABA0: sth     r6, 644(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(644);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

    ctx->pc = 0x8003ABA4u;
    // 8003ABA4: sth     r5, 692(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(692);
        mem_write16(ctx, ea, (u16)ctx->gpr[5]);
    }

    ctx->pc = 0x8003ABA8u;
    // 8003ABA8: sth     r6, 740(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(740);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

    // 8003ABAC: addi    r3, r3, 768
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(768);

    // 8003ABB0: bc    16, 0, 0x8003AB6C
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003AB6Cu;
                return;
            }
            goto label_8003AB6C;
        }
    }

    ctx->pc = 0x8003ABB4u;
}

static void loop_8003ABC0(CPUState* ctx) {
label_8003ABC0:
    ctx->downcount -= 4;
    ctx->pc = 0x8003ABC0u;
    // 8003ABC0: sth     r5, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        mem_write16(ctx, ea, (u16)ctx->gpr[5]);
    }

    ctx->pc = 0x8003ABC4u;
    // 8003ABC4: sth     r6, 68(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(68);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

    // 8003ABC8: addi    r3, r3, 96
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(96);

    // 8003ABCC: bc    16, 0, 0x8003ABC0
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003ABC0u;
                return;
            }
            goto label_8003ABC0;
        }
    }

    ctx->pc = 0x8003ABD0u;
}

static void loop_8003DC4C(CPUState* ctx) {
label_8003DC4C:
    ctx->downcount -= 26;
    ctx->pc = 0x8003DC4Cu;
    // 8003DC4C: lhz     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

    // 8003DC50: mulli   r0, r0, 6
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)6);

    // 8003DC54: add   r8, r30, r0
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

    ctx->pc = 0x8003DC58u;
    // 8003DC58: lha     r5, 4(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(4);
        ctx->gpr[5] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

    ctx->pc = 0x8003DC5Cu;
    // 8003DC5C: lha     r4, 2(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(2);
        ctx->gpr[4] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

    ctx->pc = 0x8003DC60u;
    // 8003DC60: lha     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

    ctx->pc = 0x8003DC64u;
    // 8003DC64: sth     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

    ctx->pc = 0x8003DC68u;
    // 8003DC68: sth     r4, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

    ctx->pc = 0x8003DC6Cu;
    // 8003DC6C: sth     r5, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[5]);
    }

    ctx->pc = 0x8003DC70u;
    // 8003DC70: lbz     r5, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

    ctx->pc = 0x8003DC74u;
    // 8003DC74: lbz     r4, 7(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(7);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

    ctx->pc = 0x8003DC78u;
    // 8003DC78: lbz     r0, 6(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(6);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

    ctx->pc = 0x8003DC7Cu;
    // 8003DC7C: stb     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    ctx->pc = 0x8003DC80u;
    // 8003DC80: stb     r4, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

    ctx->pc = 0x8003DC84u;
    // 8003DC84: stb     r5, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

    ctx->pc = 0x8003DC88u;
    // 8003DC88: lhz     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

    // 8003DC8C: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

    // 8003DC90: add   r5, r29, r0
    {
        u32 a = ctx->gpr[29];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[5] = res;
    }

    ctx->pc = 0x8003DC94u;
    // 8003DC94: lha     r4, 2(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(2);
        ctx->gpr[4] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

    ctx->pc = 0x8003DC98u;
    // 8003DC98: lha     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

    ctx->pc = 0x8003DC9Cu;
    // 8003DC9C: sth     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

    ctx->pc = 0x8003DCA0u;
    // 8003DCA0: sth     r4, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

    // 8003DCA4: addi    r6, r6, 2
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(2);

    // 8003DCA8: bc    16, 0, 0x8003DC4C
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003DC4Cu;
                return;
            }
            goto label_8003DC4C;
        }
    }

    ctx->pc = 0x8003DCACu;
}

void func_8003A6E0(CPUState* ctx) {
    switch (ctx->pc) {
    case 0x8003A6E0u: goto label_8003A6E0;
    case 0x8003A6E4u: goto label_8003A6E4;
    case 0x8003A6E8u: goto label_8003A6E8;
    case 0x8003A6ECu: goto label_8003A6EC;
    case 0x8003A6F0u: goto label_8003A6F0;
    case 0x8003A6F4u: goto label_8003A6F4;
    case 0x8003A6F8u: goto label_8003A6F8;
    case 0x8003A6FCu: goto label_8003A6FC;
    case 0x8003A700u: goto label_8003A700;
    case 0x8003A704u: goto label_8003A704;
    case 0x8003A708u: goto label_8003A708;
    case 0x8003A70Cu: goto label_8003A70C;
    case 0x8003A710u: goto label_8003A710;
    case 0x8003A714u: goto label_8003A714;
    case 0x8003A718u: goto label_8003A718;
    case 0x8003A71Cu: goto label_8003A71C;
    case 0x8003A720u: goto label_8003A720;
    case 0x8003A724u: goto label_8003A724;
    case 0x8003A728u: goto label_8003A728;
    case 0x8003A72Cu: goto label_8003A72C;
    case 0x8003A730u: goto label_8003A730;
    case 0x8003A734u: goto label_8003A734;
    case 0x8003A738u: goto label_8003A738;
    case 0x8003A73Cu: goto label_8003A73C;
    case 0x8003A740u: goto label_8003A740;
    case 0x8003A744u: goto label_8003A744;
    case 0x8003A748u: goto label_8003A748;
    case 0x8003A74Cu: goto label_8003A74C;
    case 0x8003A750u: goto label_8003A750;
    case 0x8003A754u: goto label_8003A754;
    case 0x8003A758u: goto label_8003A758;
    case 0x8003A75Cu: goto label_8003A75C;
    case 0x8003A760u: goto label_8003A760;
    case 0x8003A764u: goto label_8003A764;
    case 0x8003A768u: goto label_8003A768;
    case 0x8003A76Cu: goto label_8003A76C;
    case 0x8003A770u: goto label_8003A770;
    case 0x8003A774u: goto label_8003A774;
    case 0x8003A778u: goto label_8003A778;
    case 0x8003A77Cu: goto label_8003A77C;
    case 0x8003A780u: goto label_8003A780;
    case 0x8003A784u: goto label_8003A784;
    case 0x8003A788u: goto label_8003A788;
    case 0x8003A78Cu: goto label_8003A78C;
    case 0x8003A790u: goto label_8003A790;
    case 0x8003A794u: goto label_8003A794;
    case 0x8003A798u: goto label_8003A798;
    case 0x8003A79Cu: goto label_8003A79C;
    case 0x8003A7A0u: goto label_8003A7A0;
    case 0x8003A7A4u: goto label_8003A7A4;
    case 0x8003A7A8u: goto label_8003A7A8;
    case 0x8003A7ACu: goto label_8003A7AC;
    case 0x8003A7B0u: goto label_8003A7B0;
    case 0x8003A7B4u: goto label_8003A7B4;
    case 0x8003A7B8u: goto label_8003A7B8;
    case 0x8003A7BCu: goto label_8003A7BC;
    case 0x8003A7C0u: goto label_8003A7C0;
    case 0x8003A7C4u: goto label_8003A7C4;
    case 0x8003A7C8u: goto label_8003A7C8;
    case 0x8003A7CCu: goto label_8003A7CC;
    case 0x8003A7D0u: goto label_8003A7D0;
    case 0x8003A7D4u: goto label_8003A7D4;
    case 0x8003A7D8u: goto label_8003A7D8;
    case 0x8003A7DCu: goto label_8003A7DC;
    case 0x8003A7E0u: goto label_8003A7E0;
    case 0x8003A7E4u: goto label_8003A7E4;
    case 0x8003A7E8u: goto label_8003A7E8;
    case 0x8003A7ECu: goto label_8003A7EC;
    case 0x8003A7F0u: goto label_8003A7F0;
    case 0x8003A7F4u: goto label_8003A7F4;
    case 0x8003A7F8u: goto label_8003A7F8;
    case 0x8003A7FCu: goto label_8003A7FC;
    case 0x8003A800u: goto label_8003A800;
    case 0x8003A804u: goto label_8003A804;
    case 0x8003A808u: goto label_8003A808;
    case 0x8003A80Cu: goto label_8003A80C;
    case 0x8003A810u: goto label_8003A810;
    case 0x8003A814u: goto label_8003A814;
    case 0x8003A818u: goto label_8003A818;
    case 0x8003A81Cu: goto label_8003A81C;
    case 0x8003A820u: goto label_8003A820;
    case 0x8003A824u: goto label_8003A824;
    case 0x8003A828u: goto label_8003A828;
    case 0x8003A82Cu: goto label_8003A82C;
    case 0x8003A830u: goto label_8003A830;
    case 0x8003A834u: goto label_8003A834;
    case 0x8003A838u: goto label_8003A838;
    case 0x8003A83Cu: goto label_8003A83C;
    case 0x8003A840u: goto label_8003A840;
    case 0x8003A844u: goto label_8003A844;
    case 0x8003A848u: goto label_8003A848;
    case 0x8003A84Cu: goto label_8003A84C;
    case 0x8003A850u: goto label_8003A850;
    case 0x8003A854u: goto label_8003A854;
    case 0x8003A858u: goto label_8003A858;
    case 0x8003A85Cu: goto label_8003A85C;
    case 0x8003A860u: goto label_8003A860;
    case 0x8003A864u: goto label_8003A864;
    case 0x8003A868u: goto label_8003A868;
    case 0x8003A86Cu: goto label_8003A86C;
    case 0x8003A870u: goto label_8003A870;
    case 0x8003A874u: goto label_8003A874;
    case 0x8003A878u: goto label_8003A878;
    case 0x8003A87Cu: goto label_8003A87C;
    case 0x8003A880u: goto label_8003A880;
    case 0x8003A884u: goto label_8003A884;
    case 0x8003A888u: goto label_8003A888;
    case 0x8003A88Cu: goto label_8003A88C;
    case 0x8003A890u: goto label_8003A890;
    case 0x8003A894u: goto label_8003A894;
    case 0x8003A898u: goto label_8003A898;
    case 0x8003A89Cu: goto label_8003A89C;
    case 0x8003A8A0u: goto label_8003A8A0;
    case 0x8003A8A4u: goto label_8003A8A4;
    case 0x8003A8A8u: goto label_8003A8A8;
    case 0x8003A8ACu: goto label_8003A8AC;
    case 0x8003A8B0u: goto label_8003A8B0;
    case 0x8003A8B4u: goto label_8003A8B4;
    case 0x8003A8B8u: goto label_8003A8B8;
    case 0x8003A8BCu: goto label_8003A8BC;
    case 0x8003A8C0u: goto label_8003A8C0;
    case 0x8003A8C4u: goto label_8003A8C4;
    case 0x8003A8C8u: goto label_8003A8C8;
    case 0x8003A8CCu: goto label_8003A8CC;
    case 0x8003A8D0u: goto label_8003A8D0;
    case 0x8003A8D4u: goto label_8003A8D4;
    case 0x8003A8D8u: goto label_8003A8D8;
    case 0x8003A8DCu: goto label_8003A8DC;
    case 0x8003A8E0u: goto label_8003A8E0;
    case 0x8003A8E4u: goto label_8003A8E4;
    case 0x8003A8E8u: goto label_8003A8E8;
    case 0x8003A8ECu: goto label_8003A8EC;
    case 0x8003A8F0u: goto label_8003A8F0;
    case 0x8003A8F4u: goto label_8003A8F4;
    case 0x8003A8F8u: goto label_8003A8F8;
    case 0x8003A8FCu: goto label_8003A8FC;
    case 0x8003A900u: goto label_8003A900;
    case 0x8003A904u: goto label_8003A904;
    case 0x8003A908u: goto label_8003A908;
    case 0x8003A90Cu: goto label_8003A90C;
    case 0x8003A910u: goto label_8003A910;
    case 0x8003A914u: goto label_8003A914;
    case 0x8003A918u: goto label_8003A918;
    case 0x8003A91Cu: goto label_8003A91C;
    case 0x8003A920u: goto label_8003A920;
    case 0x8003A924u: goto label_8003A924;
    case 0x8003A928u: goto label_8003A928;
    case 0x8003A92Cu: goto label_8003A92C;
    case 0x8003A930u: goto label_8003A930;
    case 0x8003A934u: goto label_8003A934;
    case 0x8003A938u: goto label_8003A938;
    case 0x8003A93Cu: goto label_8003A93C;
    case 0x8003A940u: goto label_8003A940;
    case 0x8003A944u: goto label_8003A944;
    case 0x8003A948u: goto label_8003A948;
    case 0x8003A94Cu: goto label_8003A94C;
    case 0x8003A950u: goto label_8003A950;
    case 0x8003A954u: goto label_8003A954;
    case 0x8003A958u: goto label_8003A958;
    case 0x8003A95Cu: goto label_8003A95C;
    case 0x8003A960u: goto label_8003A960;
    case 0x8003A964u: goto label_8003A964;
    case 0x8003A968u: goto label_8003A968;
    case 0x8003A96Cu: goto label_8003A96C;
    case 0x8003A970u: goto label_8003A970;
    case 0x8003A974u: goto label_8003A974;
    case 0x8003A978u: goto label_8003A978;
    case 0x8003A97Cu: goto label_8003A97C;
    case 0x8003A980u: goto label_8003A980;
    case 0x8003A984u: goto label_8003A984;
    case 0x8003A988u: goto label_8003A988;
    case 0x8003A98Cu: goto label_8003A98C;
    case 0x8003A990u: goto label_8003A990;
    case 0x8003A994u: goto label_8003A994;
    case 0x8003A998u: goto label_8003A998;
    case 0x8003A99Cu: goto label_8003A99C;
    case 0x8003A9A0u: goto label_8003A9A0;
    case 0x8003A9A4u: goto label_8003A9A4;
    case 0x8003A9A8u: goto label_8003A9A8;
    case 0x8003A9ACu: goto label_8003A9AC;
    case 0x8003A9B0u: goto label_8003A9B0;
    case 0x8003A9B4u: goto label_8003A9B4;
    case 0x8003A9B8u: goto label_8003A9B8;
    case 0x8003A9BCu: goto label_8003A9BC;
    case 0x8003A9C0u: goto label_8003A9C0;
    case 0x8003A9C4u: goto label_8003A9C4;
    case 0x8003A9C8u: goto label_8003A9C8;
    case 0x8003A9CCu: goto label_8003A9CC;
    case 0x8003A9D0u: goto label_8003A9D0;
    case 0x8003A9D4u: goto label_8003A9D4;
    case 0x8003A9D8u: goto label_8003A9D8;
    case 0x8003A9DCu: goto label_8003A9DC;
    case 0x8003A9E0u: goto label_8003A9E0;
    case 0x8003A9E4u: goto label_8003A9E4;
    case 0x8003A9E8u: goto label_8003A9E8;
    case 0x8003A9ECu: goto label_8003A9EC;
    case 0x8003A9F0u: goto label_8003A9F0;
    case 0x8003A9F4u: goto label_8003A9F4;
    case 0x8003A9F8u: goto label_8003A9F8;
    case 0x8003A9FCu: goto label_8003A9FC;
    case 0x8003AA00u: goto label_8003AA00;
    case 0x8003AA04u: goto label_8003AA04;
    case 0x8003AA08u: goto label_8003AA08;
    case 0x8003AA0Cu: goto label_8003AA0C;
    case 0x8003AA10u: goto label_8003AA10;
    case 0x8003AA14u: goto label_8003AA14;
    case 0x8003AA18u: goto label_8003AA18;
    case 0x8003AA1Cu: goto label_8003AA1C;
    case 0x8003AA20u: goto label_8003AA20;
    case 0x8003AA24u: goto label_8003AA24;
    case 0x8003AA28u: goto label_8003AA28;
    case 0x8003AA2Cu: goto label_8003AA2C;
    case 0x8003AA30u: goto label_8003AA30;
    case 0x8003AA34u: goto label_8003AA34;
    case 0x8003AA38u: goto label_8003AA38;
    case 0x8003AA3Cu: goto label_8003AA3C;
    case 0x8003AA40u: goto label_8003AA40;
    case 0x8003AA44u: goto label_8003AA44;
    case 0x8003AA48u: goto label_8003AA48;
    case 0x8003AA4Cu: goto label_8003AA4C;
    case 0x8003AA50u: goto label_8003AA50;
    case 0x8003AA54u: goto label_8003AA54;
    case 0x8003AA58u: goto label_8003AA58;
    case 0x8003AA5Cu: goto label_8003AA5C;
    case 0x8003AA60u: goto label_8003AA60;
    case 0x8003AA64u: goto label_8003AA64;
    case 0x8003AA68u: goto label_8003AA68;
    case 0x8003AA6Cu: goto label_8003AA6C;
    case 0x8003AA70u: goto label_8003AA70;
    case 0x8003AA74u: goto label_8003AA74;
    case 0x8003AA78u: goto label_8003AA78;
    case 0x8003AA7Cu: goto label_8003AA7C;
    case 0x8003AA80u: goto label_8003AA80;
    case 0x8003AA84u: goto label_8003AA84;
    case 0x8003AA88u: goto label_8003AA88;
    case 0x8003AA8Cu: goto label_8003AA8C;
    case 0x8003AA90u: goto label_8003AA90;
    case 0x8003AA94u: goto label_8003AA94;
    case 0x8003AA98u: goto label_8003AA98;
    case 0x8003AA9Cu: goto label_8003AA9C;
    case 0x8003AAA0u: goto label_8003AAA0;
    case 0x8003AAA4u: goto label_8003AAA4;
    case 0x8003AAA8u: goto label_8003AAA8;
    case 0x8003AAACu: goto label_8003AAAC;
    case 0x8003AAB0u: goto label_8003AAB0;
    case 0x8003AAB4u: goto label_8003AAB4;
    case 0x8003AAB8u: goto label_8003AAB8;
    case 0x8003AABCu: goto label_8003AABC;
    case 0x8003AAC0u: goto label_8003AAC0;
    case 0x8003AAC4u: goto label_8003AAC4;
    case 0x8003AAC8u: goto label_8003AAC8;
    case 0x8003AACCu: goto label_8003AACC;
    case 0x8003AAD0u: goto label_8003AAD0;
    case 0x8003AAD4u: goto label_8003AAD4;
    case 0x8003AAD8u: goto label_8003AAD8;
    case 0x8003AADCu: goto label_8003AADC;
    case 0x8003AAE0u: goto label_8003AAE0;
    case 0x8003AAE4u: goto label_8003AAE4;
    case 0x8003AAE8u: goto label_8003AAE8;
    case 0x8003AAECu: goto label_8003AAEC;
    case 0x8003AAF0u: goto label_8003AAF0;
    case 0x8003AAF4u: goto label_8003AAF4;
    case 0x8003AAF8u: goto label_8003AAF8;
    case 0x8003AAFCu: goto label_8003AAFC;
    case 0x8003AB00u: goto label_8003AB00;
    case 0x8003AB04u: goto label_8003AB04;
    case 0x8003AB08u: goto label_8003AB08;
    case 0x8003AB0Cu: goto label_8003AB0C;
    case 0x8003AB10u: goto label_8003AB10;
    case 0x8003AB14u: goto label_8003AB14;
    case 0x8003AB18u: goto label_8003AB18;
    case 0x8003AB1Cu: goto label_8003AB1C;
    case 0x8003AB20u: goto label_8003AB20;
    case 0x8003AB24u: goto label_8003AB24;
    case 0x8003AB28u: goto label_8003AB28;
    case 0x8003AB2Cu: goto label_8003AB2C;
    case 0x8003AB30u: goto label_8003AB30;
    case 0x8003AB34u: goto label_8003AB34;
    case 0x8003AB38u: goto label_8003AB38;
    case 0x8003AB3Cu: goto label_8003AB3C;
    case 0x8003AB40u: goto label_8003AB40;
    case 0x8003AB44u: goto label_8003AB44;
    case 0x8003AB48u: goto label_8003AB48;
    case 0x8003AB4Cu: goto label_8003AB4C;
    case 0x8003AB50u: goto label_8003AB50;
    case 0x8003AB54u: goto label_8003AB54;
    case 0x8003AB58u: goto label_8003AB58;
    case 0x8003AB5Cu: goto label_8003AB5C;
    case 0x8003AB60u: goto label_8003AB60;
    case 0x8003AB64u: goto label_8003AB64;
    case 0x8003AB68u: goto label_8003AB68;
    case 0x8003AB6Cu: goto label_8003AB6C;
    case 0x8003AB70u: goto label_8003AB70;
    case 0x8003AB74u: goto label_8003AB74;
    case 0x8003AB78u: goto label_8003AB78;
    case 0x8003AB7Cu: goto label_8003AB7C;
    case 0x8003AB80u: goto label_8003AB80;
    case 0x8003AB84u: goto label_8003AB84;
    case 0x8003AB88u: goto label_8003AB88;
    case 0x8003AB8Cu: goto label_8003AB8C;
    case 0x8003AB90u: goto label_8003AB90;
    case 0x8003AB94u: goto label_8003AB94;
    case 0x8003AB98u: goto label_8003AB98;
    case 0x8003AB9Cu: goto label_8003AB9C;
    case 0x8003ABA0u: goto label_8003ABA0;
    case 0x8003ABA4u: goto label_8003ABA4;
    case 0x8003ABA8u: goto label_8003ABA8;
    case 0x8003ABACu: goto label_8003ABAC;
    case 0x8003ABB0u: goto label_8003ABB0;
    case 0x8003ABB4u: goto label_8003ABB4;
    case 0x8003ABB8u: goto label_8003ABB8;
    case 0x8003ABBCu: goto label_8003ABBC;
    case 0x8003ABC0u: goto label_8003ABC0;
    case 0x8003ABC4u: goto label_8003ABC4;
    case 0x8003ABC8u: goto label_8003ABC8;
    case 0x8003ABCCu: goto label_8003ABCC;
    case 0x8003ABD0u: goto label_8003ABD0;
    case 0x8003ABD4u: goto label_8003ABD4;
    case 0x8003ABD8u: goto label_8003ABD8;
    case 0x8003ABDCu: goto label_8003ABDC;
    case 0x8003ABE0u: goto label_8003ABE0;
    case 0x8003ABE4u: goto label_8003ABE4;
    case 0x8003ABE8u: goto label_8003ABE8;
    case 0x8003ABECu: goto label_8003ABEC;
    case 0x8003ABF0u: goto label_8003ABF0;
    case 0x8003ABF4u: goto label_8003ABF4;
    case 0x8003ABF8u: goto label_8003ABF8;
    case 0x8003ABFCu: goto label_8003ABFC;
    case 0x8003AC00u: goto label_8003AC00;
    case 0x8003AC04u: goto label_8003AC04;
    case 0x8003AC08u: goto label_8003AC08;
    case 0x8003AC0Cu: goto label_8003AC0C;
    case 0x8003AC10u: goto label_8003AC10;
    case 0x8003AC14u: goto label_8003AC14;
    case 0x8003AC18u: goto label_8003AC18;
    case 0x8003AC1Cu: goto label_8003AC1C;
    case 0x8003AC20u: goto label_8003AC20;
    case 0x8003AC24u: goto label_8003AC24;
    case 0x8003AC28u: goto label_8003AC28;
    case 0x8003AC2Cu: goto label_8003AC2C;
    case 0x8003AC30u: goto label_8003AC30;
    case 0x8003AC34u: goto label_8003AC34;
    case 0x8003AC38u: goto label_8003AC38;
    case 0x8003AC3Cu: goto label_8003AC3C;
    case 0x8003AC40u: goto label_8003AC40;
    case 0x8003AC44u: goto label_8003AC44;
    case 0x8003AC48u: goto label_8003AC48;
    case 0x8003AC4Cu: goto label_8003AC4C;
    case 0x8003AC50u: goto label_8003AC50;
    case 0x8003AC54u: goto label_8003AC54;
    case 0x8003AC58u: goto label_8003AC58;
    case 0x8003AC5Cu: goto label_8003AC5C;
    case 0x8003AC60u: goto label_8003AC60;
    case 0x8003AC64u: goto label_8003AC64;
    case 0x8003AC68u: goto label_8003AC68;
    case 0x8003AC6Cu: goto label_8003AC6C;
    case 0x8003AC70u: goto label_8003AC70;
    case 0x8003AC74u: goto label_8003AC74;
    case 0x8003AC78u: goto label_8003AC78;
    case 0x8003AC7Cu: goto label_8003AC7C;
    case 0x8003AC80u: goto label_8003AC80;
    case 0x8003AC84u: goto label_8003AC84;
    case 0x8003AC88u: goto label_8003AC88;
    case 0x8003AC8Cu: goto label_8003AC8C;
    case 0x8003AC90u: goto label_8003AC90;
    case 0x8003AC94u: goto label_8003AC94;
    case 0x8003AC98u: goto label_8003AC98;
    case 0x8003AC9Cu: goto label_8003AC9C;
    case 0x8003ACA0u: goto label_8003ACA0;
    case 0x8003ACA4u: goto label_8003ACA4;
    case 0x8003ACA8u: goto label_8003ACA8;
    case 0x8003ACACu: goto label_8003ACAC;
    case 0x8003ACB0u: goto label_8003ACB0;
    case 0x8003ACB4u: goto label_8003ACB4;
    case 0x8003ACB8u: goto label_8003ACB8;
    case 0x8003ACBCu: goto label_8003ACBC;
    case 0x8003ACC0u: goto label_8003ACC0;
    case 0x8003ACC4u: goto label_8003ACC4;
    case 0x8003ACC8u: goto label_8003ACC8;
    case 0x8003ACCCu: goto label_8003ACCC;
    case 0x8003ACD0u: goto label_8003ACD0;
    case 0x8003ACD4u: goto label_8003ACD4;
    case 0x8003ACD8u: goto label_8003ACD8;
    case 0x8003ACDCu: goto label_8003ACDC;
    case 0x8003ACE0u: goto label_8003ACE0;
    case 0x8003ACE4u: goto label_8003ACE4;
    case 0x8003ACE8u: goto label_8003ACE8;
    case 0x8003ACECu: goto label_8003ACEC;
    case 0x8003ACF0u: goto label_8003ACF0;
    case 0x8003ACF4u: goto label_8003ACF4;
    case 0x8003ACF8u: goto label_8003ACF8;
    case 0x8003ACFCu: goto label_8003ACFC;
    case 0x8003AD00u: goto label_8003AD00;
    case 0x8003AD04u: goto label_8003AD04;
    case 0x8003AD08u: goto label_8003AD08;
    case 0x8003AD0Cu: goto label_8003AD0C;
    case 0x8003AD10u: goto label_8003AD10;
    case 0x8003AD14u: goto label_8003AD14;
    case 0x8003AD18u: goto label_8003AD18;
    case 0x8003AD1Cu: goto label_8003AD1C;
    case 0x8003AD20u: goto label_8003AD20;
    case 0x8003AD24u: goto label_8003AD24;
    case 0x8003AD28u: goto label_8003AD28;
    case 0x8003AD2Cu: goto label_8003AD2C;
    case 0x8003AD30u: goto label_8003AD30;
    case 0x8003AD34u: goto label_8003AD34;
    case 0x8003AD38u: goto label_8003AD38;
    case 0x8003AD3Cu: goto label_8003AD3C;
    case 0x8003AD40u: goto label_8003AD40;
    case 0x8003AD44u: goto label_8003AD44;
    case 0x8003AD48u: goto label_8003AD48;
    case 0x8003AD4Cu: goto label_8003AD4C;
    case 0x8003AD50u: goto label_8003AD50;
    case 0x8003AD54u: goto label_8003AD54;
    case 0x8003AD58u: goto label_8003AD58;
    case 0x8003AD5Cu: goto label_8003AD5C;
    case 0x8003AD60u: goto label_8003AD60;
    case 0x8003AD64u: goto label_8003AD64;
    case 0x8003AD68u: goto label_8003AD68;
    case 0x8003AD6Cu: goto label_8003AD6C;
    case 0x8003AD70u: goto label_8003AD70;
    case 0x8003AD74u: goto label_8003AD74;
    case 0x8003AD78u: goto label_8003AD78;
    case 0x8003AD7Cu: goto label_8003AD7C;
    case 0x8003AD80u: goto label_8003AD80;
    case 0x8003AD84u: goto label_8003AD84;
    case 0x8003AD88u: goto label_8003AD88;
    case 0x8003AD8Cu: goto label_8003AD8C;
    case 0x8003AD90u: goto label_8003AD90;
    case 0x8003AD94u: goto label_8003AD94;
    case 0x8003AD98u: goto label_8003AD98;
    case 0x8003AD9Cu: goto label_8003AD9C;
    case 0x8003ADA0u: goto label_8003ADA0;
    case 0x8003ADA4u: goto label_8003ADA4;
    case 0x8003ADA8u: goto label_8003ADA8;
    case 0x8003ADACu: goto label_8003ADAC;
    case 0x8003ADB0u: goto label_8003ADB0;
    case 0x8003ADB4u: goto label_8003ADB4;
    case 0x8003ADB8u: goto label_8003ADB8;
    case 0x8003ADBCu: goto label_8003ADBC;
    case 0x8003ADC0u: goto label_8003ADC0;
    case 0x8003ADC4u: goto label_8003ADC4;
    case 0x8003ADC8u: goto label_8003ADC8;
    case 0x8003ADCCu: goto label_8003ADCC;
    case 0x8003ADD0u: goto label_8003ADD0;
    case 0x8003ADD4u: goto label_8003ADD4;
    case 0x8003ADD8u: goto label_8003ADD8;
    case 0x8003ADDCu: goto label_8003ADDC;
    case 0x8003ADE0u: goto label_8003ADE0;
    case 0x8003ADE4u: goto label_8003ADE4;
    case 0x8003ADE8u: goto label_8003ADE8;
    case 0x8003ADECu: goto label_8003ADEC;
    case 0x8003ADF0u: goto label_8003ADF0;
    case 0x8003ADF4u: goto label_8003ADF4;
    case 0x8003ADF8u: goto label_8003ADF8;
    case 0x8003ADFCu: goto label_8003ADFC;
    case 0x8003AE00u: goto label_8003AE00;
    case 0x8003AE04u: goto label_8003AE04;
    case 0x8003AE08u: goto label_8003AE08;
    case 0x8003AE0Cu: goto label_8003AE0C;
    case 0x8003AE10u: goto label_8003AE10;
    case 0x8003AE14u: goto label_8003AE14;
    case 0x8003AE18u: goto label_8003AE18;
    case 0x8003AE1Cu: goto label_8003AE1C;
    case 0x8003AE20u: goto label_8003AE20;
    case 0x8003AE24u: goto label_8003AE24;
    case 0x8003AE28u: goto label_8003AE28;
    case 0x8003AE2Cu: goto label_8003AE2C;
    case 0x8003AE30u: goto label_8003AE30;
    case 0x8003AE34u: goto label_8003AE34;
    case 0x8003AE38u: goto label_8003AE38;
    case 0x8003AE3Cu: goto label_8003AE3C;
    case 0x8003AE40u: goto label_8003AE40;
    case 0x8003AE44u: goto label_8003AE44;
    case 0x8003AE48u: goto label_8003AE48;
    case 0x8003AE4Cu: goto label_8003AE4C;
    case 0x8003AE50u: goto label_8003AE50;
    case 0x8003AE54u: goto label_8003AE54;
    case 0x8003AE58u: goto label_8003AE58;
    case 0x8003AE5Cu: goto label_8003AE5C;
    case 0x8003AE60u: goto label_8003AE60;
    case 0x8003AE64u: goto label_8003AE64;
    case 0x8003AE68u: goto label_8003AE68;
    case 0x8003AE6Cu: goto label_8003AE6C;
    case 0x8003AE70u: goto label_8003AE70;
    case 0x8003AE74u: goto label_8003AE74;
    case 0x8003AE78u: goto label_8003AE78;
    case 0x8003AE7Cu: goto label_8003AE7C;
    case 0x8003AE80u: goto label_8003AE80;
    case 0x8003AE84u: goto label_8003AE84;
    case 0x8003AE88u: goto label_8003AE88;
    case 0x8003AE8Cu: goto label_8003AE8C;
    case 0x8003AE90u: goto label_8003AE90;
    case 0x8003AE94u: goto label_8003AE94;
    case 0x8003AE98u: goto label_8003AE98;
    case 0x8003AE9Cu: goto label_8003AE9C;
    case 0x8003AEA0u: goto label_8003AEA0;
    case 0x8003AEA4u: goto label_8003AEA4;
    case 0x8003AEA8u: goto label_8003AEA8;
    case 0x8003AEACu: goto label_8003AEAC;
    case 0x8003AEB0u: goto label_8003AEB0;
    case 0x8003AEB4u: goto label_8003AEB4;
    case 0x8003AEB8u: goto label_8003AEB8;
    case 0x8003AEBCu: goto label_8003AEBC;
    case 0x8003AEC0u: goto label_8003AEC0;
    case 0x8003AEC4u: goto label_8003AEC4;
    case 0x8003AEC8u: goto label_8003AEC8;
    case 0x8003AECCu: goto label_8003AECC;
    case 0x8003AED0u: goto label_8003AED0;
    case 0x8003AED4u: goto label_8003AED4;
    case 0x8003AED8u: goto label_8003AED8;
    case 0x8003AEDCu: goto label_8003AEDC;
    case 0x8003AEE0u: goto label_8003AEE0;
    case 0x8003AEE4u: goto label_8003AEE4;
    case 0x8003AEE8u: goto label_8003AEE8;
    case 0x8003AEECu: goto label_8003AEEC;
    case 0x8003AEF0u: goto label_8003AEF0;
    case 0x8003AEF4u: goto label_8003AEF4;
    case 0x8003AEF8u: goto label_8003AEF8;
    case 0x8003AEFCu: goto label_8003AEFC;
    case 0x8003AF00u: goto label_8003AF00;
    case 0x8003AF04u: goto label_8003AF04;
    case 0x8003AF08u: goto label_8003AF08;
    case 0x8003AF0Cu: goto label_8003AF0C;
    case 0x8003AF10u: goto label_8003AF10;
    case 0x8003AF14u: goto label_8003AF14;
    case 0x8003AF18u: goto label_8003AF18;
    case 0x8003AF1Cu: goto label_8003AF1C;
    case 0x8003AF20u: goto label_8003AF20;
    case 0x8003AF24u: goto label_8003AF24;
    case 0x8003AF28u: goto label_8003AF28;
    case 0x8003AF2Cu: goto label_8003AF2C;
    case 0x8003AF30u: goto label_8003AF30;
    case 0x8003AF34u: goto label_8003AF34;
    case 0x8003AF38u: goto label_8003AF38;
    case 0x8003AF3Cu: goto label_8003AF3C;
    case 0x8003AF40u: goto label_8003AF40;
    case 0x8003AF44u: goto label_8003AF44;
    case 0x8003AF48u: goto label_8003AF48;
    case 0x8003AF4Cu: goto label_8003AF4C;
    case 0x8003AF50u: goto label_8003AF50;
    case 0x8003AF54u: goto label_8003AF54;
    case 0x8003AF58u: goto label_8003AF58;
    case 0x8003AF5Cu: goto label_8003AF5C;
    case 0x8003AF60u: goto label_8003AF60;
    case 0x8003AF64u: goto label_8003AF64;
    case 0x8003AF68u: goto label_8003AF68;
    case 0x8003AF6Cu: goto label_8003AF6C;
    case 0x8003AF70u: goto label_8003AF70;
    case 0x8003AF74u: goto label_8003AF74;
    case 0x8003AF78u: goto label_8003AF78;
    case 0x8003AF7Cu: goto label_8003AF7C;
    case 0x8003AF80u: goto label_8003AF80;
    case 0x8003AF84u: goto label_8003AF84;
    case 0x8003AF88u: goto label_8003AF88;
    case 0x8003AF8Cu: goto label_8003AF8C;
    case 0x8003AF90u: goto label_8003AF90;
    case 0x8003AF94u: goto label_8003AF94;
    case 0x8003AF98u: goto label_8003AF98;
    case 0x8003AF9Cu: goto label_8003AF9C;
    case 0x8003AFA0u: goto label_8003AFA0;
    case 0x8003AFA4u: goto label_8003AFA4;
    case 0x8003AFA8u: goto label_8003AFA8;
    case 0x8003AFACu: goto label_8003AFAC;
    case 0x8003AFB0u: goto label_8003AFB0;
    case 0x8003AFB4u: goto label_8003AFB4;
    case 0x8003AFB8u: goto label_8003AFB8;
    case 0x8003AFBCu: goto label_8003AFBC;
    case 0x8003AFC0u: goto label_8003AFC0;
    case 0x8003AFC4u: goto label_8003AFC4;
    case 0x8003AFC8u: goto label_8003AFC8;
    case 0x8003AFCCu: goto label_8003AFCC;
    case 0x8003AFD0u: goto label_8003AFD0;
    case 0x8003AFD4u: goto label_8003AFD4;
    case 0x8003AFD8u: goto label_8003AFD8;
    case 0x8003AFDCu: goto label_8003AFDC;
    case 0x8003AFE0u: goto label_8003AFE0;
    case 0x8003AFE4u: goto label_8003AFE4;
    case 0x8003AFE8u: goto label_8003AFE8;
    case 0x8003AFECu: goto label_8003AFEC;
    case 0x8003AFF0u: goto label_8003AFF0;
    case 0x8003AFF4u: goto label_8003AFF4;
    case 0x8003AFF8u: goto label_8003AFF8;
    case 0x8003AFFCu: goto label_8003AFFC;
    case 0x8003B000u: goto label_8003B000;
    case 0x8003B004u: goto label_8003B004;
    case 0x8003B008u: goto label_8003B008;
    case 0x8003B00Cu: goto label_8003B00C;
    case 0x8003B010u: goto label_8003B010;
    case 0x8003B014u: goto label_8003B014;
    case 0x8003B018u: goto label_8003B018;
    case 0x8003B01Cu: goto label_8003B01C;
    case 0x8003B020u: goto label_8003B020;
    case 0x8003B024u: goto label_8003B024;
    case 0x8003B028u: goto label_8003B028;
    case 0x8003B02Cu: goto label_8003B02C;
    case 0x8003B030u: goto label_8003B030;
    case 0x8003B034u: goto label_8003B034;
    case 0x8003B038u: goto label_8003B038;
    case 0x8003B03Cu: goto label_8003B03C;
    case 0x8003B040u: goto label_8003B040;
    case 0x8003B044u: goto label_8003B044;
    case 0x8003B048u: goto label_8003B048;
    case 0x8003B04Cu: goto label_8003B04C;
    case 0x8003B050u: goto label_8003B050;
    case 0x8003B054u: goto label_8003B054;
    case 0x8003B058u: goto label_8003B058;
    case 0x8003B05Cu: goto label_8003B05C;
    case 0x8003B060u: goto label_8003B060;
    case 0x8003B064u: goto label_8003B064;
    case 0x8003B068u: goto label_8003B068;
    case 0x8003B06Cu: goto label_8003B06C;
    case 0x8003B070u: goto label_8003B070;
    case 0x8003B074u: goto label_8003B074;
    case 0x8003B078u: goto label_8003B078;
    case 0x8003B07Cu: goto label_8003B07C;
    case 0x8003B080u: goto label_8003B080;
    case 0x8003B084u: goto label_8003B084;
    case 0x8003B088u: goto label_8003B088;
    case 0x8003B08Cu: goto label_8003B08C;
    case 0x8003B090u: goto label_8003B090;
    case 0x8003B094u: goto label_8003B094;
    case 0x8003B098u: goto label_8003B098;
    case 0x8003B09Cu: goto label_8003B09C;
    case 0x8003B0A0u: goto label_8003B0A0;
    case 0x8003B0A4u: goto label_8003B0A4;
    case 0x8003B0A8u: goto label_8003B0A8;
    case 0x8003B0ACu: goto label_8003B0AC;
    case 0x8003B0B0u: goto label_8003B0B0;
    case 0x8003B0B4u: goto label_8003B0B4;
    case 0x8003B0B8u: goto label_8003B0B8;
    case 0x8003B0BCu: goto label_8003B0BC;
    case 0x8003B0C0u: goto label_8003B0C0;
    case 0x8003B0C4u: goto label_8003B0C4;
    case 0x8003B0C8u: goto label_8003B0C8;
    case 0x8003B0CCu: goto label_8003B0CC;
    case 0x8003B0D0u: goto label_8003B0D0;
    case 0x8003B0D4u: goto label_8003B0D4;
    case 0x8003B0D8u: goto label_8003B0D8;
    case 0x8003B0DCu: goto label_8003B0DC;
    case 0x8003B0E0u: goto label_8003B0E0;
    case 0x8003B0E4u: goto label_8003B0E4;
    case 0x8003B0E8u: goto label_8003B0E8;
    case 0x8003B0ECu: goto label_8003B0EC;
    case 0x8003B0F0u: goto label_8003B0F0;
    case 0x8003B0F4u: goto label_8003B0F4;
    case 0x8003B0F8u: goto label_8003B0F8;
    case 0x8003B0FCu: goto label_8003B0FC;
    case 0x8003B100u: goto label_8003B100;
    case 0x8003B104u: goto label_8003B104;
    case 0x8003B108u: goto label_8003B108;
    case 0x8003B10Cu: goto label_8003B10C;
    case 0x8003B110u: goto label_8003B110;
    case 0x8003B114u: goto label_8003B114;
    case 0x8003B118u: goto label_8003B118;
    case 0x8003B11Cu: goto label_8003B11C;
    case 0x8003B120u: goto label_8003B120;
    case 0x8003B124u: goto label_8003B124;
    case 0x8003B128u: goto label_8003B128;
    case 0x8003B12Cu: goto label_8003B12C;
    case 0x8003B130u: goto label_8003B130;
    case 0x8003B134u: goto label_8003B134;
    case 0x8003B138u: goto label_8003B138;
    case 0x8003B13Cu: goto label_8003B13C;
    case 0x8003B140u: goto label_8003B140;
    case 0x8003B144u: goto label_8003B144;
    case 0x8003B148u: goto label_8003B148;
    case 0x8003B14Cu: goto label_8003B14C;
    case 0x8003B150u: goto label_8003B150;
    case 0x8003B154u: goto label_8003B154;
    case 0x8003B158u: goto label_8003B158;
    case 0x8003B15Cu: goto label_8003B15C;
    case 0x8003B160u: goto label_8003B160;
    case 0x8003B164u: goto label_8003B164;
    case 0x8003B168u: goto label_8003B168;
    case 0x8003B16Cu: goto label_8003B16C;
    case 0x8003B170u: goto label_8003B170;
    case 0x8003B174u: goto label_8003B174;
    case 0x8003B178u: goto label_8003B178;
    case 0x8003B17Cu: goto label_8003B17C;
    case 0x8003B180u: goto label_8003B180;
    case 0x8003B184u: goto label_8003B184;
    case 0x8003B188u: goto label_8003B188;
    case 0x8003B18Cu: goto label_8003B18C;
    case 0x8003B190u: goto label_8003B190;
    case 0x8003B194u: goto label_8003B194;
    case 0x8003B198u: goto label_8003B198;
    case 0x8003B19Cu: goto label_8003B19C;
    case 0x8003B1A0u: goto label_8003B1A0;
    case 0x8003B1A4u: goto label_8003B1A4;
    case 0x8003B1A8u: goto label_8003B1A8;
    case 0x8003B1ACu: goto label_8003B1AC;
    case 0x8003B1B0u: goto label_8003B1B0;
    case 0x8003B1B4u: goto label_8003B1B4;
    case 0x8003B1B8u: goto label_8003B1B8;
    case 0x8003B1BCu: goto label_8003B1BC;
    case 0x8003B1C0u: goto label_8003B1C0;
    case 0x8003B1C4u: goto label_8003B1C4;
    case 0x8003B1C8u: goto label_8003B1C8;
    case 0x8003B1CCu: goto label_8003B1CC;
    case 0x8003B1D0u: goto label_8003B1D0;
    case 0x8003B1D4u: goto label_8003B1D4;
    case 0x8003B1D8u: goto label_8003B1D8;
    case 0x8003B1DCu: goto label_8003B1DC;
    case 0x8003B1E0u: goto label_8003B1E0;
    case 0x8003B1E4u: goto label_8003B1E4;
    case 0x8003B1E8u: goto label_8003B1E8;
    case 0x8003B1ECu: goto label_8003B1EC;
    case 0x8003B1F0u: goto label_8003B1F0;
    case 0x8003B1F4u: goto label_8003B1F4;
    case 0x8003B1F8u: goto label_8003B1F8;
    case 0x8003B1FCu: goto label_8003B1FC;
    case 0x8003B200u: goto label_8003B200;
    case 0x8003B204u: goto label_8003B204;
    case 0x8003B208u: goto label_8003B208;
    case 0x8003B20Cu: goto label_8003B20C;
    case 0x8003B210u: goto label_8003B210;
    case 0x8003B214u: goto label_8003B214;
    case 0x8003B218u: goto label_8003B218;
    case 0x8003B21Cu: goto label_8003B21C;
    case 0x8003B220u: goto label_8003B220;
    case 0x8003B224u: goto label_8003B224;
    case 0x8003B228u: goto label_8003B228;
    case 0x8003B22Cu: goto label_8003B22C;
    case 0x8003B230u: goto label_8003B230;
    case 0x8003B234u: goto label_8003B234;
    case 0x8003B238u: goto label_8003B238;
    case 0x8003B23Cu: goto label_8003B23C;
    case 0x8003B240u: goto label_8003B240;
    case 0x8003B244u: goto label_8003B244;
    case 0x8003B248u: goto label_8003B248;
    case 0x8003B24Cu: goto label_8003B24C;
    case 0x8003B250u: goto label_8003B250;
    case 0x8003B254u: goto label_8003B254;
    case 0x8003B258u: goto label_8003B258;
    case 0x8003B25Cu: goto label_8003B25C;
    case 0x8003B260u: goto label_8003B260;
    case 0x8003B264u: goto label_8003B264;
    case 0x8003B268u: goto label_8003B268;
    case 0x8003B26Cu: goto label_8003B26C;
    case 0x8003B270u: goto label_8003B270;
    case 0x8003B274u: goto label_8003B274;
    case 0x8003B278u: goto label_8003B278;
    case 0x8003B27Cu: goto label_8003B27C;
    case 0x8003B280u: goto label_8003B280;
    case 0x8003B284u: goto label_8003B284;
    case 0x8003B288u: goto label_8003B288;
    case 0x8003B28Cu: goto label_8003B28C;
    case 0x8003B290u: goto label_8003B290;
    case 0x8003B294u: goto label_8003B294;
    case 0x8003B298u: goto label_8003B298;
    case 0x8003B29Cu: goto label_8003B29C;
    case 0x8003B2A0u: goto label_8003B2A0;
    case 0x8003B2A4u: goto label_8003B2A4;
    case 0x8003B2A8u: goto label_8003B2A8;
    case 0x8003B2ACu: goto label_8003B2AC;
    case 0x8003B2B0u: goto label_8003B2B0;
    case 0x8003B2B4u: goto label_8003B2B4;
    case 0x8003B2B8u: goto label_8003B2B8;
    case 0x8003B2BCu: goto label_8003B2BC;
    case 0x8003B2C0u: goto label_8003B2C0;
    case 0x8003B2C4u: goto label_8003B2C4;
    case 0x8003B2C8u: goto label_8003B2C8;
    case 0x8003B2CCu: goto label_8003B2CC;
    case 0x8003B2D0u: goto label_8003B2D0;
    case 0x8003B2D4u: goto label_8003B2D4;
    case 0x8003B2D8u: goto label_8003B2D8;
    case 0x8003B2DCu: goto label_8003B2DC;
    case 0x8003B2E0u: goto label_8003B2E0;
    case 0x8003B2E4u: goto label_8003B2E4;
    case 0x8003B2E8u: goto label_8003B2E8;
    case 0x8003B2ECu: goto label_8003B2EC;
    case 0x8003B2F0u: goto label_8003B2F0;
    case 0x8003B2F4u: goto label_8003B2F4;
    case 0x8003B2F8u: goto label_8003B2F8;
    case 0x8003B2FCu: goto label_8003B2FC;
    case 0x8003B300u: goto label_8003B300;
    case 0x8003B304u: goto label_8003B304;
    case 0x8003B308u: goto label_8003B308;
    case 0x8003B30Cu: goto label_8003B30C;
    case 0x8003B310u: goto label_8003B310;
    case 0x8003B314u: goto label_8003B314;
    case 0x8003B318u: goto label_8003B318;
    case 0x8003B31Cu: goto label_8003B31C;
    case 0x8003B320u: goto label_8003B320;
    case 0x8003B324u: goto label_8003B324;
    case 0x8003B328u: goto label_8003B328;
    case 0x8003B32Cu: goto label_8003B32C;
    case 0x8003B330u: goto label_8003B330;
    case 0x8003B334u: goto label_8003B334;
    case 0x8003B338u: goto label_8003B338;
    case 0x8003B33Cu: goto label_8003B33C;
    case 0x8003B340u: goto label_8003B340;
    case 0x8003B344u: goto label_8003B344;
    case 0x8003B348u: goto label_8003B348;
    case 0x8003B34Cu: goto label_8003B34C;
    case 0x8003B350u: goto label_8003B350;
    case 0x8003B354u: goto label_8003B354;
    case 0x8003B358u: goto label_8003B358;
    case 0x8003B35Cu: goto label_8003B35C;
    case 0x8003B360u: goto label_8003B360;
    case 0x8003B364u: goto label_8003B364;
    case 0x8003B368u: goto label_8003B368;
    case 0x8003B36Cu: goto label_8003B36C;
    case 0x8003B370u: goto label_8003B370;
    case 0x8003B374u: goto label_8003B374;
    case 0x8003B378u: goto label_8003B378;
    case 0x8003B37Cu: goto label_8003B37C;
    case 0x8003B380u: goto label_8003B380;
    case 0x8003B384u: goto label_8003B384;
    case 0x8003B388u: goto label_8003B388;
    case 0x8003B38Cu: goto label_8003B38C;
    case 0x8003B390u: goto label_8003B390;
    case 0x8003B394u: goto label_8003B394;
    case 0x8003B398u: goto label_8003B398;
    case 0x8003B39Cu: goto label_8003B39C;
    case 0x8003B3A0u: goto label_8003B3A0;
    case 0x8003B3A4u: goto label_8003B3A4;
    case 0x8003B3A8u: goto label_8003B3A8;
    case 0x8003B3ACu: goto label_8003B3AC;
    case 0x8003B3B0u: goto label_8003B3B0;
    case 0x8003B3B4u: goto label_8003B3B4;
    case 0x8003B3B8u: goto label_8003B3B8;
    case 0x8003B3BCu: goto label_8003B3BC;
    case 0x8003B3C0u: goto label_8003B3C0;
    case 0x8003B3C4u: goto label_8003B3C4;
    case 0x8003B3C8u: goto label_8003B3C8;
    case 0x8003B3CCu: goto label_8003B3CC;
    case 0x8003B3D0u: goto label_8003B3D0;
    case 0x8003B3D4u: goto label_8003B3D4;
    case 0x8003B3D8u: goto label_8003B3D8;
    case 0x8003B3DCu: goto label_8003B3DC;
    case 0x8003B3E0u: goto label_8003B3E0;
    case 0x8003B3E4u: goto label_8003B3E4;
    case 0x8003B3E8u: goto label_8003B3E8;
    case 0x8003B3ECu: goto label_8003B3EC;
    case 0x8003B3F0u: goto label_8003B3F0;
    case 0x8003B3F4u: goto label_8003B3F4;
    case 0x8003B3F8u: goto label_8003B3F8;
    case 0x8003B3FCu: goto label_8003B3FC;
    case 0x8003B400u: goto label_8003B400;
    case 0x8003B404u: goto label_8003B404;
    case 0x8003B408u: goto label_8003B408;
    case 0x8003B40Cu: goto label_8003B40C;
    case 0x8003B410u: goto label_8003B410;
    case 0x8003B414u: goto label_8003B414;
    case 0x8003B418u: goto label_8003B418;
    case 0x8003B41Cu: goto label_8003B41C;
    case 0x8003B420u: goto label_8003B420;
    case 0x8003B424u: goto label_8003B424;
    case 0x8003B428u: goto label_8003B428;
    case 0x8003B42Cu: goto label_8003B42C;
    case 0x8003B430u: goto label_8003B430;
    case 0x8003B434u: goto label_8003B434;
    case 0x8003B438u: goto label_8003B438;
    case 0x8003B43Cu: goto label_8003B43C;
    case 0x8003B440u: goto label_8003B440;
    case 0x8003B444u: goto label_8003B444;
    case 0x8003B448u: goto label_8003B448;
    case 0x8003B44Cu: goto label_8003B44C;
    case 0x8003B450u: goto label_8003B450;
    case 0x8003B454u: goto label_8003B454;
    case 0x8003B458u: goto label_8003B458;
    case 0x8003B45Cu: goto label_8003B45C;
    case 0x8003B460u: goto label_8003B460;
    case 0x8003B464u: goto label_8003B464;
    case 0x8003B468u: goto label_8003B468;
    case 0x8003B46Cu: goto label_8003B46C;
    case 0x8003B470u: goto label_8003B470;
    case 0x8003B474u: goto label_8003B474;
    case 0x8003B478u: goto label_8003B478;
    case 0x8003B47Cu: goto label_8003B47C;
    case 0x8003B480u: goto label_8003B480;
    case 0x8003B484u: goto label_8003B484;
    case 0x8003B488u: goto label_8003B488;
    case 0x8003B48Cu: goto label_8003B48C;
    case 0x8003B490u: goto label_8003B490;
    case 0x8003B494u: goto label_8003B494;
    case 0x8003B498u: goto label_8003B498;
    case 0x8003B49Cu: goto label_8003B49C;
    case 0x8003B4A0u: goto label_8003B4A0;
    case 0x8003B4A4u: goto label_8003B4A4;
    case 0x8003B4A8u: goto label_8003B4A8;
    case 0x8003B4ACu: goto label_8003B4AC;
    case 0x8003B4B0u: goto label_8003B4B0;
    case 0x8003B4B4u: goto label_8003B4B4;
    case 0x8003B4B8u: goto label_8003B4B8;
    case 0x8003B4BCu: goto label_8003B4BC;
    case 0x8003B4C0u: goto label_8003B4C0;
    case 0x8003B4C4u: goto label_8003B4C4;
    case 0x8003B4C8u: goto label_8003B4C8;
    case 0x8003B4CCu: goto label_8003B4CC;
    case 0x8003B4D0u: goto label_8003B4D0;
    case 0x8003B4D4u: goto label_8003B4D4;
    case 0x8003B4D8u: goto label_8003B4D8;
    case 0x8003B4DCu: goto label_8003B4DC;
    case 0x8003B4E0u: goto label_8003B4E0;
    case 0x8003B4E4u: goto label_8003B4E4;
    case 0x8003B4E8u: goto label_8003B4E8;
    case 0x8003B4ECu: goto label_8003B4EC;
    case 0x8003B4F0u: goto label_8003B4F0;
    case 0x8003B4F4u: goto label_8003B4F4;
    case 0x8003B4F8u: goto label_8003B4F8;
    case 0x8003B4FCu: goto label_8003B4FC;
    case 0x8003B500u: goto label_8003B500;
    case 0x8003B504u: goto label_8003B504;
    case 0x8003B508u: goto label_8003B508;
    case 0x8003B50Cu: goto label_8003B50C;
    case 0x8003B510u: goto label_8003B510;
    case 0x8003B514u: goto label_8003B514;
    case 0x8003B518u: goto label_8003B518;
    case 0x8003B51Cu: goto label_8003B51C;
    case 0x8003B520u: goto label_8003B520;
    case 0x8003B524u: goto label_8003B524;
    case 0x8003B528u: goto label_8003B528;
    case 0x8003B52Cu: goto label_8003B52C;
    case 0x8003B530u: goto label_8003B530;
    case 0x8003B534u: goto label_8003B534;
    case 0x8003B538u: goto label_8003B538;
    case 0x8003B53Cu: goto label_8003B53C;
    case 0x8003B540u: goto label_8003B540;
    case 0x8003B544u: goto label_8003B544;
    case 0x8003B548u: goto label_8003B548;
    case 0x8003B54Cu: goto label_8003B54C;
    case 0x8003B550u: goto label_8003B550;
    case 0x8003B554u: goto label_8003B554;
    case 0x8003B558u: goto label_8003B558;
    case 0x8003B55Cu: goto label_8003B55C;
    case 0x8003B560u: goto label_8003B560;
    case 0x8003B564u: goto label_8003B564;
    case 0x8003B568u: goto label_8003B568;
    case 0x8003B56Cu: goto label_8003B56C;
    case 0x8003B570u: goto label_8003B570;
    case 0x8003B574u: goto label_8003B574;
    case 0x8003B578u: goto label_8003B578;
    case 0x8003B57Cu: goto label_8003B57C;
    case 0x8003B580u: goto label_8003B580;
    case 0x8003B584u: goto label_8003B584;
    case 0x8003B588u: goto label_8003B588;
    case 0x8003B58Cu: goto label_8003B58C;
    case 0x8003B590u: goto label_8003B590;
    case 0x8003B594u: goto label_8003B594;
    case 0x8003B598u: goto label_8003B598;
    case 0x8003B59Cu: goto label_8003B59C;
    case 0x8003B5A0u: goto label_8003B5A0;
    case 0x8003B5A4u: goto label_8003B5A4;
    case 0x8003B5A8u: goto label_8003B5A8;
    case 0x8003B5ACu: goto label_8003B5AC;
    case 0x8003B5B0u: goto label_8003B5B0;
    case 0x8003B5B4u: goto label_8003B5B4;
    case 0x8003B5B8u: goto label_8003B5B8;
    case 0x8003B5BCu: goto label_8003B5BC;
    case 0x8003B5C0u: goto label_8003B5C0;
    case 0x8003B5C4u: goto label_8003B5C4;
    case 0x8003B5C8u: goto label_8003B5C8;
    case 0x8003B5CCu: goto label_8003B5CC;
    case 0x8003B5D0u: goto label_8003B5D0;
    case 0x8003B5D4u: goto label_8003B5D4;
    case 0x8003B5D8u: goto label_8003B5D8;
    case 0x8003B5DCu: goto label_8003B5DC;
    case 0x8003B5E0u: goto label_8003B5E0;
    case 0x8003B5E4u: goto label_8003B5E4;
    case 0x8003B5E8u: goto label_8003B5E8;
    case 0x8003B5ECu: goto label_8003B5EC;
    case 0x8003B5F0u: goto label_8003B5F0;
    case 0x8003B5F4u: goto label_8003B5F4;
    case 0x8003B5F8u: goto label_8003B5F8;
    case 0x8003B5FCu: goto label_8003B5FC;
    case 0x8003B600u: goto label_8003B600;
    case 0x8003B604u: goto label_8003B604;
    case 0x8003B608u: goto label_8003B608;
    case 0x8003B60Cu: goto label_8003B60C;
    case 0x8003B610u: goto label_8003B610;
    case 0x8003B614u: goto label_8003B614;
    case 0x8003B618u: goto label_8003B618;
    case 0x8003B61Cu: goto label_8003B61C;
    case 0x8003B620u: goto label_8003B620;
    case 0x8003B624u: goto label_8003B624;
    case 0x8003B628u: goto label_8003B628;
    case 0x8003B62Cu: goto label_8003B62C;
    case 0x8003B630u: goto label_8003B630;
    case 0x8003B634u: goto label_8003B634;
    case 0x8003B638u: goto label_8003B638;
    case 0x8003B63Cu: goto label_8003B63C;
    case 0x8003B640u: goto label_8003B640;
    case 0x8003B644u: goto label_8003B644;
    case 0x8003B648u: goto label_8003B648;
    case 0x8003B64Cu: goto label_8003B64C;
    case 0x8003B650u: goto label_8003B650;
    case 0x8003B654u: goto label_8003B654;
    case 0x8003B658u: goto label_8003B658;
    case 0x8003B65Cu: goto label_8003B65C;
    case 0x8003B660u: goto label_8003B660;
    case 0x8003B664u: goto label_8003B664;
    case 0x8003B668u: goto label_8003B668;
    case 0x8003B66Cu: goto label_8003B66C;
    case 0x8003B670u: goto label_8003B670;
    case 0x8003B674u: goto label_8003B674;
    case 0x8003B678u: goto label_8003B678;
    case 0x8003B67Cu: goto label_8003B67C;
    case 0x8003B680u: goto label_8003B680;
    case 0x8003B684u: goto label_8003B684;
    case 0x8003B688u: goto label_8003B688;
    case 0x8003B68Cu: goto label_8003B68C;
    case 0x8003B690u: goto label_8003B690;
    case 0x8003B694u: goto label_8003B694;
    case 0x8003B698u: goto label_8003B698;
    case 0x8003B69Cu: goto label_8003B69C;
    case 0x8003B6A0u: goto label_8003B6A0;
    case 0x8003B6A4u: goto label_8003B6A4;
    case 0x8003B6A8u: goto label_8003B6A8;
    case 0x8003B6ACu: goto label_8003B6AC;
    case 0x8003B6B0u: goto label_8003B6B0;
    case 0x8003B6B4u: goto label_8003B6B4;
    case 0x8003B6B8u: goto label_8003B6B8;
    case 0x8003B6BCu: goto label_8003B6BC;
    case 0x8003B6C0u: goto label_8003B6C0;
    case 0x8003B6C4u: goto label_8003B6C4;
    case 0x8003B6C8u: goto label_8003B6C8;
    case 0x8003B6CCu: goto label_8003B6CC;
    case 0x8003B6D0u: goto label_8003B6D0;
    case 0x8003B6D4u: goto label_8003B6D4;
    case 0x8003B6D8u: goto label_8003B6D8;
    case 0x8003B6DCu: goto label_8003B6DC;
    case 0x8003B6E0u: goto label_8003B6E0;
    case 0x8003B6E4u: goto label_8003B6E4;
    case 0x8003B6E8u: goto label_8003B6E8;
    case 0x8003B6ECu: goto label_8003B6EC;
    case 0x8003B6F0u: goto label_8003B6F0;
    case 0x8003B6F4u: goto label_8003B6F4;
    case 0x8003B6F8u: goto label_8003B6F8;
    case 0x8003B6FCu: goto label_8003B6FC;
    case 0x8003B700u: goto label_8003B700;
    case 0x8003B704u: goto label_8003B704;
    case 0x8003B708u: goto label_8003B708;
    case 0x8003B70Cu: goto label_8003B70C;
    case 0x8003B710u: goto label_8003B710;
    case 0x8003B714u: goto label_8003B714;
    case 0x8003B718u: goto label_8003B718;
    case 0x8003B71Cu: goto label_8003B71C;
    case 0x8003B720u: goto label_8003B720;
    case 0x8003B724u: goto label_8003B724;
    case 0x8003B728u: goto label_8003B728;
    case 0x8003B72Cu: goto label_8003B72C;
    case 0x8003B730u: goto label_8003B730;
    case 0x8003B734u: goto label_8003B734;
    case 0x8003B738u: goto label_8003B738;
    case 0x8003B73Cu: goto label_8003B73C;
    case 0x8003B740u: goto label_8003B740;
    case 0x8003B744u: goto label_8003B744;
    case 0x8003B748u: goto label_8003B748;
    case 0x8003B74Cu: goto label_8003B74C;
    case 0x8003B750u: goto label_8003B750;
    case 0x8003B754u: goto label_8003B754;
    case 0x8003B758u: goto label_8003B758;
    case 0x8003B75Cu: goto label_8003B75C;
    case 0x8003B760u: goto label_8003B760;
    case 0x8003B764u: goto label_8003B764;
    case 0x8003B768u: goto label_8003B768;
    case 0x8003B76Cu: goto label_8003B76C;
    case 0x8003B770u: goto label_8003B770;
    case 0x8003B774u: goto label_8003B774;
    case 0x8003B778u: goto label_8003B778;
    case 0x8003B77Cu: goto label_8003B77C;
    case 0x8003B780u: goto label_8003B780;
    case 0x8003B784u: goto label_8003B784;
    case 0x8003B788u: goto label_8003B788;
    case 0x8003B78Cu: goto label_8003B78C;
    case 0x8003B790u: goto label_8003B790;
    case 0x8003B794u: goto label_8003B794;
    case 0x8003B798u: goto label_8003B798;
    case 0x8003B79Cu: goto label_8003B79C;
    case 0x8003B7A0u: goto label_8003B7A0;
    case 0x8003B7A4u: goto label_8003B7A4;
    case 0x8003B7A8u: goto label_8003B7A8;
    case 0x8003B7ACu: goto label_8003B7AC;
    case 0x8003B7B0u: goto label_8003B7B0;
    case 0x8003B7B4u: goto label_8003B7B4;
    case 0x8003B7B8u: goto label_8003B7B8;
    case 0x8003B7BCu: goto label_8003B7BC;
    case 0x8003B7C0u: goto label_8003B7C0;
    case 0x8003B7C4u: goto label_8003B7C4;
    case 0x8003B7C8u: goto label_8003B7C8;
    case 0x8003B7CCu: goto label_8003B7CC;
    case 0x8003B7D0u: goto label_8003B7D0;
    case 0x8003B7D4u: goto label_8003B7D4;
    case 0x8003B7D8u: goto label_8003B7D8;
    case 0x8003B7DCu: goto label_8003B7DC;
    case 0x8003B7E0u: goto label_8003B7E0;
    case 0x8003B7E4u: goto label_8003B7E4;
    case 0x8003B7E8u: goto label_8003B7E8;
    case 0x8003B7ECu: goto label_8003B7EC;
    case 0x8003B7F0u: goto label_8003B7F0;
    case 0x8003B7F4u: goto label_8003B7F4;
    case 0x8003B7F8u: goto label_8003B7F8;
    case 0x8003B7FCu: goto label_8003B7FC;
    case 0x8003B800u: goto label_8003B800;
    case 0x8003B804u: goto label_8003B804;
    case 0x8003B808u: goto label_8003B808;
    case 0x8003B80Cu: goto label_8003B80C;
    case 0x8003B810u: goto label_8003B810;
    case 0x8003B814u: goto label_8003B814;
    case 0x8003B818u: goto label_8003B818;
    case 0x8003B81Cu: goto label_8003B81C;
    case 0x8003B820u: goto label_8003B820;
    case 0x8003B824u: goto label_8003B824;
    case 0x8003B828u: goto label_8003B828;
    case 0x8003B82Cu: goto label_8003B82C;
    case 0x8003B830u: goto label_8003B830;
    case 0x8003B834u: goto label_8003B834;
    case 0x8003B838u: goto label_8003B838;
    case 0x8003B83Cu: goto label_8003B83C;
    case 0x8003B840u: goto label_8003B840;
    case 0x8003B844u: goto label_8003B844;
    case 0x8003B848u: goto label_8003B848;
    case 0x8003B84Cu: goto label_8003B84C;
    case 0x8003B850u: goto label_8003B850;
    case 0x8003B854u: goto label_8003B854;
    case 0x8003B858u: goto label_8003B858;
    case 0x8003B85Cu: goto label_8003B85C;
    case 0x8003B860u: goto label_8003B860;
    case 0x8003B864u: goto label_8003B864;
    case 0x8003B868u: goto label_8003B868;
    case 0x8003B86Cu: goto label_8003B86C;
    case 0x8003B870u: goto label_8003B870;
    case 0x8003B874u: goto label_8003B874;
    case 0x8003B878u: goto label_8003B878;
    case 0x8003B87Cu: goto label_8003B87C;
    case 0x8003B880u: goto label_8003B880;
    case 0x8003B884u: goto label_8003B884;
    case 0x8003B888u: goto label_8003B888;
    case 0x8003B88Cu: goto label_8003B88C;
    case 0x8003B890u: goto label_8003B890;
    case 0x8003B894u: goto label_8003B894;
    case 0x8003B898u: goto label_8003B898;
    case 0x8003B89Cu: goto label_8003B89C;
    case 0x8003B8A0u: goto label_8003B8A0;
    case 0x8003B8A4u: goto label_8003B8A4;
    case 0x8003B8A8u: goto label_8003B8A8;
    case 0x8003B8ACu: goto label_8003B8AC;
    case 0x8003B8B0u: goto label_8003B8B0;
    case 0x8003B8B4u: goto label_8003B8B4;
    case 0x8003B8B8u: goto label_8003B8B8;
    case 0x8003B8BCu: goto label_8003B8BC;
    case 0x8003B8C0u: goto label_8003B8C0;
    case 0x8003B8C4u: goto label_8003B8C4;
    case 0x8003B8C8u: goto label_8003B8C8;
    case 0x8003B8CCu: goto label_8003B8CC;
    case 0x8003B8D0u: goto label_8003B8D0;
    case 0x8003B8D4u: goto label_8003B8D4;
    case 0x8003B8D8u: goto label_8003B8D8;
    case 0x8003B8DCu: goto label_8003B8DC;
    case 0x8003B8E0u: goto label_8003B8E0;
    case 0x8003B8E4u: goto label_8003B8E4;
    case 0x8003B8E8u: goto label_8003B8E8;
    case 0x8003B8ECu: goto label_8003B8EC;
    case 0x8003B8F0u: goto label_8003B8F0;
    case 0x8003B8F4u: goto label_8003B8F4;
    case 0x8003B8F8u: goto label_8003B8F8;
    case 0x8003B8FCu: goto label_8003B8FC;
    case 0x8003B900u: goto label_8003B900;
    case 0x8003B904u: goto label_8003B904;
    case 0x8003B908u: goto label_8003B908;
    case 0x8003B90Cu: goto label_8003B90C;
    case 0x8003B910u: goto label_8003B910;
    case 0x8003B914u: goto label_8003B914;
    case 0x8003B918u: goto label_8003B918;
    case 0x8003B91Cu: goto label_8003B91C;
    case 0x8003B920u: goto label_8003B920;
    case 0x8003B924u: goto label_8003B924;
    case 0x8003B928u: goto label_8003B928;
    case 0x8003B92Cu: goto label_8003B92C;
    case 0x8003B930u: goto label_8003B930;
    case 0x8003B934u: goto label_8003B934;
    case 0x8003B938u: goto label_8003B938;
    case 0x8003B93Cu: goto label_8003B93C;
    case 0x8003B940u: goto label_8003B940;
    case 0x8003B944u: goto label_8003B944;
    case 0x8003B948u: goto label_8003B948;
    case 0x8003B94Cu: goto label_8003B94C;
    case 0x8003B950u: goto label_8003B950;
    case 0x8003B954u: goto label_8003B954;
    case 0x8003B958u: goto label_8003B958;
    case 0x8003B95Cu: goto label_8003B95C;
    case 0x8003B960u: goto label_8003B960;
    case 0x8003B964u: goto label_8003B964;
    case 0x8003B968u: goto label_8003B968;
    case 0x8003B96Cu: goto label_8003B96C;
    case 0x8003B970u: goto label_8003B970;
    case 0x8003B974u: goto label_8003B974;
    case 0x8003B978u: goto label_8003B978;
    case 0x8003B97Cu: goto label_8003B97C;
    case 0x8003B980u: goto label_8003B980;
    case 0x8003B984u: goto label_8003B984;
    case 0x8003B988u: goto label_8003B988;
    case 0x8003B98Cu: goto label_8003B98C;
    case 0x8003B990u: goto label_8003B990;
    case 0x8003B994u: goto label_8003B994;
    case 0x8003B998u: goto label_8003B998;
    case 0x8003B99Cu: goto label_8003B99C;
    case 0x8003B9A0u: goto label_8003B9A0;
    case 0x8003B9A4u: goto label_8003B9A4;
    case 0x8003B9A8u: goto label_8003B9A8;
    case 0x8003B9ACu: goto label_8003B9AC;
    case 0x8003B9B0u: goto label_8003B9B0;
    case 0x8003B9B4u: goto label_8003B9B4;
    case 0x8003B9B8u: goto label_8003B9B8;
    case 0x8003B9BCu: goto label_8003B9BC;
    case 0x8003B9C0u: goto label_8003B9C0;
    case 0x8003B9C4u: goto label_8003B9C4;
    case 0x8003B9C8u: goto label_8003B9C8;
    case 0x8003B9CCu: goto label_8003B9CC;
    case 0x8003B9D0u: goto label_8003B9D0;
    case 0x8003B9D4u: goto label_8003B9D4;
    case 0x8003B9D8u: goto label_8003B9D8;
    case 0x8003B9DCu: goto label_8003B9DC;
    case 0x8003B9E0u: goto label_8003B9E0;
    case 0x8003B9E4u: goto label_8003B9E4;
    case 0x8003B9E8u: goto label_8003B9E8;
    case 0x8003B9ECu: goto label_8003B9EC;
    case 0x8003B9F0u: goto label_8003B9F0;
    case 0x8003B9F4u: goto label_8003B9F4;
    case 0x8003B9F8u: goto label_8003B9F8;
    case 0x8003B9FCu: goto label_8003B9FC;
    case 0x8003BA00u: goto label_8003BA00;
    case 0x8003BA04u: goto label_8003BA04;
    case 0x8003BA08u: goto label_8003BA08;
    case 0x8003BA0Cu: goto label_8003BA0C;
    case 0x8003BA10u: goto label_8003BA10;
    case 0x8003BA14u: goto label_8003BA14;
    case 0x8003BA18u: goto label_8003BA18;
    case 0x8003BA1Cu: goto label_8003BA1C;
    case 0x8003BA20u: goto label_8003BA20;
    case 0x8003BA24u: goto label_8003BA24;
    case 0x8003BA28u: goto label_8003BA28;
    case 0x8003BA2Cu: goto label_8003BA2C;
    case 0x8003BA30u: goto label_8003BA30;
    case 0x8003BA34u: goto label_8003BA34;
    case 0x8003BA38u: goto label_8003BA38;
    case 0x8003BA3Cu: goto label_8003BA3C;
    case 0x8003BA40u: goto label_8003BA40;
    case 0x8003BA44u: goto label_8003BA44;
    case 0x8003BA48u: goto label_8003BA48;
    case 0x8003BA4Cu: goto label_8003BA4C;
    case 0x8003BA50u: goto label_8003BA50;
    case 0x8003BA54u: goto label_8003BA54;
    case 0x8003BA58u: goto label_8003BA58;
    case 0x8003BA5Cu: goto label_8003BA5C;
    case 0x8003BA60u: goto label_8003BA60;
    case 0x8003BA64u: goto label_8003BA64;
    case 0x8003BA68u: goto label_8003BA68;
    case 0x8003BA6Cu: goto label_8003BA6C;
    case 0x8003BA70u: goto label_8003BA70;
    case 0x8003BA74u: goto label_8003BA74;
    case 0x8003BA78u: goto label_8003BA78;
    case 0x8003BA7Cu: goto label_8003BA7C;
    case 0x8003BA80u: goto label_8003BA80;
    case 0x8003BA84u: goto label_8003BA84;
    case 0x8003BA88u: goto label_8003BA88;
    case 0x8003BA8Cu: goto label_8003BA8C;
    case 0x8003BA90u: goto label_8003BA90;
    case 0x8003BA94u: goto label_8003BA94;
    case 0x8003BA98u: goto label_8003BA98;
    case 0x8003BA9Cu: goto label_8003BA9C;
    case 0x8003BAA0u: goto label_8003BAA0;
    case 0x8003BAA4u: goto label_8003BAA4;
    case 0x8003BAA8u: goto label_8003BAA8;
    case 0x8003BAACu: goto label_8003BAAC;
    case 0x8003BAB0u: goto label_8003BAB0;
    case 0x8003BAB4u: goto label_8003BAB4;
    case 0x8003BAB8u: goto label_8003BAB8;
    case 0x8003BABCu: goto label_8003BABC;
    case 0x8003BAC0u: goto label_8003BAC0;
    case 0x8003BAC4u: goto label_8003BAC4;
    case 0x8003BAC8u: goto label_8003BAC8;
    case 0x8003BACCu: goto label_8003BACC;
    case 0x8003BAD0u: goto label_8003BAD0;
    case 0x8003BAD4u: goto label_8003BAD4;
    case 0x8003BAD8u: goto label_8003BAD8;
    case 0x8003BADCu: goto label_8003BADC;
    case 0x8003BAE0u: goto label_8003BAE0;
    case 0x8003BAE4u: goto label_8003BAE4;
    case 0x8003BAE8u: goto label_8003BAE8;
    case 0x8003BAECu: goto label_8003BAEC;
    case 0x8003BAF0u: goto label_8003BAF0;
    case 0x8003BAF4u: goto label_8003BAF4;
    case 0x8003BAF8u: goto label_8003BAF8;
    case 0x8003BAFCu: goto label_8003BAFC;
    case 0x8003BB00u: goto label_8003BB00;
    case 0x8003BB04u: goto label_8003BB04;
    case 0x8003BB08u: goto label_8003BB08;
    case 0x8003BB0Cu: goto label_8003BB0C;
    case 0x8003BB10u: goto label_8003BB10;
    case 0x8003BB14u: goto label_8003BB14;
    case 0x8003BB18u: goto label_8003BB18;
    case 0x8003BB1Cu: goto label_8003BB1C;
    case 0x8003BB20u: goto label_8003BB20;
    case 0x8003BB24u: goto label_8003BB24;
    case 0x8003BB28u: goto label_8003BB28;
    case 0x8003BB2Cu: goto label_8003BB2C;
    case 0x8003BB30u: goto label_8003BB30;
    case 0x8003BB34u: goto label_8003BB34;
    case 0x8003BB38u: goto label_8003BB38;
    case 0x8003BB3Cu: goto label_8003BB3C;
    case 0x8003BB40u: goto label_8003BB40;
    case 0x8003BB44u: goto label_8003BB44;
    case 0x8003BB48u: goto label_8003BB48;
    case 0x8003BB4Cu: goto label_8003BB4C;
    case 0x8003BB50u: goto label_8003BB50;
    case 0x8003BB54u: goto label_8003BB54;
    case 0x8003BB58u: goto label_8003BB58;
    case 0x8003BB5Cu: goto label_8003BB5C;
    case 0x8003BB60u: goto label_8003BB60;
    case 0x8003BB64u: goto label_8003BB64;
    case 0x8003BB68u: goto label_8003BB68;
    case 0x8003BB6Cu: goto label_8003BB6C;
    case 0x8003BB70u: goto label_8003BB70;
    case 0x8003BB74u: goto label_8003BB74;
    case 0x8003BB78u: goto label_8003BB78;
    case 0x8003BB7Cu: goto label_8003BB7C;
    case 0x8003BB80u: goto label_8003BB80;
    case 0x8003BB84u: goto label_8003BB84;
    case 0x8003BB88u: goto label_8003BB88;
    case 0x8003BB8Cu: goto label_8003BB8C;
    case 0x8003BB90u: goto label_8003BB90;
    case 0x8003BB94u: goto label_8003BB94;
    case 0x8003BB98u: goto label_8003BB98;
    case 0x8003BB9Cu: goto label_8003BB9C;
    case 0x8003BBA0u: goto label_8003BBA0;
    case 0x8003BBA4u: goto label_8003BBA4;
    case 0x8003BBA8u: goto label_8003BBA8;
    case 0x8003BBACu: goto label_8003BBAC;
    case 0x8003BBB0u: goto label_8003BBB0;
    case 0x8003BBB4u: goto label_8003BBB4;
    case 0x8003BBB8u: goto label_8003BBB8;
    case 0x8003BBBCu: goto label_8003BBBC;
    case 0x8003BBC0u: goto label_8003BBC0;
    case 0x8003BBC4u: goto label_8003BBC4;
    case 0x8003BBC8u: goto label_8003BBC8;
    case 0x8003BBCCu: goto label_8003BBCC;
    case 0x8003BBD0u: goto label_8003BBD0;
    case 0x8003BBD4u: goto label_8003BBD4;
    case 0x8003BBD8u: goto label_8003BBD8;
    case 0x8003BBDCu: goto label_8003BBDC;
    case 0x8003BBE0u: goto label_8003BBE0;
    case 0x8003BBE4u: goto label_8003BBE4;
    case 0x8003BBE8u: goto label_8003BBE8;
    case 0x8003BBECu: goto label_8003BBEC;
    case 0x8003BBF0u: goto label_8003BBF0;
    case 0x8003BBF4u: goto label_8003BBF4;
    case 0x8003BBF8u: goto label_8003BBF8;
    case 0x8003BBFCu: goto label_8003BBFC;
    case 0x8003BC00u: goto label_8003BC00;
    case 0x8003BC04u: goto label_8003BC04;
    case 0x8003BC08u: goto label_8003BC08;
    case 0x8003BC0Cu: goto label_8003BC0C;
    case 0x8003BC10u: goto label_8003BC10;
    case 0x8003BC14u: goto label_8003BC14;
    case 0x8003BC18u: goto label_8003BC18;
    case 0x8003BC1Cu: goto label_8003BC1C;
    case 0x8003BC20u: goto label_8003BC20;
    case 0x8003BC24u: goto label_8003BC24;
    case 0x8003BC28u: goto label_8003BC28;
    case 0x8003BC2Cu: goto label_8003BC2C;
    case 0x8003BC30u: goto label_8003BC30;
    case 0x8003BC34u: goto label_8003BC34;
    case 0x8003BC38u: goto label_8003BC38;
    case 0x8003BC3Cu: goto label_8003BC3C;
    case 0x8003BC40u: goto label_8003BC40;
    case 0x8003BC44u: goto label_8003BC44;
    case 0x8003BC48u: goto label_8003BC48;
    case 0x8003BC4Cu: goto label_8003BC4C;
    case 0x8003BC50u: goto label_8003BC50;
    case 0x8003BC54u: goto label_8003BC54;
    case 0x8003BC58u: goto label_8003BC58;
    case 0x8003BC5Cu: goto label_8003BC5C;
    case 0x8003BC60u: goto label_8003BC60;
    case 0x8003BC64u: goto label_8003BC64;
    case 0x8003BC68u: goto label_8003BC68;
    case 0x8003BC6Cu: goto label_8003BC6C;
    case 0x8003BC70u: goto label_8003BC70;
    case 0x8003BC74u: goto label_8003BC74;
    case 0x8003BC78u: goto label_8003BC78;
    case 0x8003BC7Cu: goto label_8003BC7C;
    case 0x8003BC80u: goto label_8003BC80;
    case 0x8003BC84u: goto label_8003BC84;
    case 0x8003BC88u: goto label_8003BC88;
    case 0x8003BC8Cu: goto label_8003BC8C;
    case 0x8003BC90u: goto label_8003BC90;
    case 0x8003BC94u: goto label_8003BC94;
    case 0x8003BC98u: goto label_8003BC98;
    case 0x8003BC9Cu: goto label_8003BC9C;
    case 0x8003BCA0u: goto label_8003BCA0;
    case 0x8003BCA4u: goto label_8003BCA4;
    case 0x8003BCA8u: goto label_8003BCA8;
    case 0x8003BCACu: goto label_8003BCAC;
    case 0x8003BCB0u: goto label_8003BCB0;
    case 0x8003BCB4u: goto label_8003BCB4;
    case 0x8003BCB8u: goto label_8003BCB8;
    case 0x8003BCBCu: goto label_8003BCBC;
    case 0x8003BCC0u: goto label_8003BCC0;
    case 0x8003BCC4u: goto label_8003BCC4;
    case 0x8003BCC8u: goto label_8003BCC8;
    case 0x8003BCCCu: goto label_8003BCCC;
    case 0x8003BCD0u: goto label_8003BCD0;
    case 0x8003BCD4u: goto label_8003BCD4;
    case 0x8003BCD8u: goto label_8003BCD8;
    case 0x8003BCDCu: goto label_8003BCDC;
    case 0x8003BCE0u: goto label_8003BCE0;
    case 0x8003BCE4u: goto label_8003BCE4;
    case 0x8003BCE8u: goto label_8003BCE8;
    case 0x8003BCECu: goto label_8003BCEC;
    case 0x8003BCF0u: goto label_8003BCF0;
    case 0x8003BCF4u: goto label_8003BCF4;
    case 0x8003BCF8u: goto label_8003BCF8;
    case 0x8003BCFCu: goto label_8003BCFC;
    case 0x8003BD00u: goto label_8003BD00;
    case 0x8003BD04u: goto label_8003BD04;
    case 0x8003BD08u: goto label_8003BD08;
    case 0x8003BD0Cu: goto label_8003BD0C;
    case 0x8003BD10u: goto label_8003BD10;
    case 0x8003BD14u: goto label_8003BD14;
    case 0x8003BD18u: goto label_8003BD18;
    case 0x8003BD1Cu: goto label_8003BD1C;
    case 0x8003BD20u: goto label_8003BD20;
    case 0x8003BD24u: goto label_8003BD24;
    case 0x8003BD28u: goto label_8003BD28;
    case 0x8003BD2Cu: goto label_8003BD2C;
    case 0x8003BD30u: goto label_8003BD30;
    case 0x8003BD34u: goto label_8003BD34;
    case 0x8003BD38u: goto label_8003BD38;
    case 0x8003BD3Cu: goto label_8003BD3C;
    case 0x8003BD40u: goto label_8003BD40;
    case 0x8003BD44u: goto label_8003BD44;
    case 0x8003BD48u: goto label_8003BD48;
    case 0x8003BD4Cu: goto label_8003BD4C;
    case 0x8003BD50u: goto label_8003BD50;
    case 0x8003BD54u: goto label_8003BD54;
    case 0x8003BD58u: goto label_8003BD58;
    case 0x8003BD5Cu: goto label_8003BD5C;
    case 0x8003BD60u: goto label_8003BD60;
    case 0x8003BD64u: goto label_8003BD64;
    case 0x8003BD68u: goto label_8003BD68;
    case 0x8003BD6Cu: goto label_8003BD6C;
    case 0x8003BD70u: goto label_8003BD70;
    case 0x8003BD74u: goto label_8003BD74;
    case 0x8003BD78u: goto label_8003BD78;
    case 0x8003BD7Cu: goto label_8003BD7C;
    case 0x8003BD80u: goto label_8003BD80;
    case 0x8003BD84u: goto label_8003BD84;
    case 0x8003BD88u: goto label_8003BD88;
    case 0x8003BD8Cu: goto label_8003BD8C;
    case 0x8003BD90u: goto label_8003BD90;
    case 0x8003BD94u: goto label_8003BD94;
    case 0x8003BD98u: goto label_8003BD98;
    case 0x8003BD9Cu: goto label_8003BD9C;
    case 0x8003BDA0u: goto label_8003BDA0;
    case 0x8003BDA4u: goto label_8003BDA4;
    case 0x8003BDA8u: goto label_8003BDA8;
    case 0x8003BDACu: goto label_8003BDAC;
    case 0x8003BDB0u: goto label_8003BDB0;
    case 0x8003BDB4u: goto label_8003BDB4;
    case 0x8003BDB8u: goto label_8003BDB8;
    case 0x8003BDBCu: goto label_8003BDBC;
    case 0x8003BDC0u: goto label_8003BDC0;
    case 0x8003BDC4u: goto label_8003BDC4;
    case 0x8003BDC8u: goto label_8003BDC8;
    case 0x8003BDCCu: goto label_8003BDCC;
    case 0x8003BDD0u: goto label_8003BDD0;
    case 0x8003BDD4u: goto label_8003BDD4;
    case 0x8003BDD8u: goto label_8003BDD8;
    case 0x8003BDDCu: goto label_8003BDDC;
    case 0x8003BDE0u: goto label_8003BDE0;
    case 0x8003BDE4u: goto label_8003BDE4;
    case 0x8003BDE8u: goto label_8003BDE8;
    case 0x8003BDECu: goto label_8003BDEC;
    case 0x8003BDF0u: goto label_8003BDF0;
    case 0x8003BDF4u: goto label_8003BDF4;
    case 0x8003BDF8u: goto label_8003BDF8;
    case 0x8003BDFCu: goto label_8003BDFC;
    case 0x8003BE00u: goto label_8003BE00;
    case 0x8003BE04u: goto label_8003BE04;
    case 0x8003BE08u: goto label_8003BE08;
    case 0x8003BE0Cu: goto label_8003BE0C;
    case 0x8003BE10u: goto label_8003BE10;
    case 0x8003BE14u: goto label_8003BE14;
    case 0x8003BE18u: goto label_8003BE18;
    case 0x8003BE1Cu: goto label_8003BE1C;
    case 0x8003BE20u: goto label_8003BE20;
    case 0x8003BE24u: goto label_8003BE24;
    case 0x8003BE28u: goto label_8003BE28;
    case 0x8003BE2Cu: goto label_8003BE2C;
    case 0x8003BE30u: goto label_8003BE30;
    case 0x8003BE34u: goto label_8003BE34;
    case 0x8003BE38u: goto label_8003BE38;
    case 0x8003BE3Cu: goto label_8003BE3C;
    case 0x8003BE40u: goto label_8003BE40;
    case 0x8003BE44u: goto label_8003BE44;
    case 0x8003BE48u: goto label_8003BE48;
    case 0x8003BE4Cu: goto label_8003BE4C;
    case 0x8003BE50u: goto label_8003BE50;
    case 0x8003BE54u: goto label_8003BE54;
    case 0x8003BE58u: goto label_8003BE58;
    case 0x8003BE5Cu: goto label_8003BE5C;
    case 0x8003BE60u: goto label_8003BE60;
    case 0x8003BE64u: goto label_8003BE64;
    case 0x8003BE68u: goto label_8003BE68;
    case 0x8003BE6Cu: goto label_8003BE6C;
    case 0x8003BE70u: goto label_8003BE70;
    case 0x8003BE74u: goto label_8003BE74;
    case 0x8003BE78u: goto label_8003BE78;
    case 0x8003BE7Cu: goto label_8003BE7C;
    case 0x8003BE80u: goto label_8003BE80;
    case 0x8003BE84u: goto label_8003BE84;
    case 0x8003BE88u: goto label_8003BE88;
    case 0x8003BE8Cu: goto label_8003BE8C;
    case 0x8003BE90u: goto label_8003BE90;
    case 0x8003BE94u: goto label_8003BE94;
    case 0x8003BE98u: goto label_8003BE98;
    case 0x8003BE9Cu: goto label_8003BE9C;
    case 0x8003BEA0u: goto label_8003BEA0;
    case 0x8003BEA4u: goto label_8003BEA4;
    case 0x8003BEA8u: goto label_8003BEA8;
    case 0x8003BEACu: goto label_8003BEAC;
    case 0x8003BEB0u: goto label_8003BEB0;
    case 0x8003BEB4u: goto label_8003BEB4;
    case 0x8003BEB8u: goto label_8003BEB8;
    case 0x8003BEBCu: goto label_8003BEBC;
    case 0x8003BEC0u: goto label_8003BEC0;
    case 0x8003BEC4u: goto label_8003BEC4;
    case 0x8003BEC8u: goto label_8003BEC8;
    case 0x8003BECCu: goto label_8003BECC;
    case 0x8003BED0u: goto label_8003BED0;
    case 0x8003BED4u: goto label_8003BED4;
    case 0x8003BED8u: goto label_8003BED8;
    case 0x8003BEDCu: goto label_8003BEDC;
    case 0x8003BEE0u: goto label_8003BEE0;
    case 0x8003BEE4u: goto label_8003BEE4;
    case 0x8003BEE8u: goto label_8003BEE8;
    case 0x8003BEECu: goto label_8003BEEC;
    case 0x8003BEF0u: goto label_8003BEF0;
    case 0x8003BEF4u: goto label_8003BEF4;
    case 0x8003BEF8u: goto label_8003BEF8;
    case 0x8003BEFCu: goto label_8003BEFC;
    case 0x8003BF00u: goto label_8003BF00;
    case 0x8003BF04u: goto label_8003BF04;
    case 0x8003BF08u: goto label_8003BF08;
    case 0x8003BF0Cu: goto label_8003BF0C;
    case 0x8003BF10u: goto label_8003BF10;
    case 0x8003BF14u: goto label_8003BF14;
    case 0x8003BF18u: goto label_8003BF18;
    case 0x8003BF1Cu: goto label_8003BF1C;
    case 0x8003BF20u: goto label_8003BF20;
    case 0x8003BF24u: goto label_8003BF24;
    case 0x8003BF28u: goto label_8003BF28;
    case 0x8003BF2Cu: goto label_8003BF2C;
    case 0x8003BF30u: goto label_8003BF30;
    case 0x8003BF34u: goto label_8003BF34;
    case 0x8003BF38u: goto label_8003BF38;
    case 0x8003BF3Cu: goto label_8003BF3C;
    case 0x8003BF40u: goto label_8003BF40;
    case 0x8003BF44u: goto label_8003BF44;
    case 0x8003BF48u: goto label_8003BF48;
    case 0x8003BF4Cu: goto label_8003BF4C;
    case 0x8003BF50u: goto label_8003BF50;
    case 0x8003BF54u: goto label_8003BF54;
    case 0x8003BF58u: goto label_8003BF58;
    case 0x8003BF5Cu: goto label_8003BF5C;
    case 0x8003BF60u: goto label_8003BF60;
    case 0x8003BF64u: goto label_8003BF64;
    case 0x8003BF68u: goto label_8003BF68;
    case 0x8003BF6Cu: goto label_8003BF6C;
    case 0x8003BF70u: goto label_8003BF70;
    case 0x8003BF74u: goto label_8003BF74;
    case 0x8003BF78u: goto label_8003BF78;
    case 0x8003BF7Cu: goto label_8003BF7C;
    case 0x8003BF80u: goto label_8003BF80;
    case 0x8003BF84u: goto label_8003BF84;
    case 0x8003BF88u: goto label_8003BF88;
    case 0x8003BF8Cu: goto label_8003BF8C;
    case 0x8003BF90u: goto label_8003BF90;
    case 0x8003BF94u: goto label_8003BF94;
    case 0x8003BF98u: goto label_8003BF98;
    case 0x8003BF9Cu: goto label_8003BF9C;
    case 0x8003BFA0u: goto label_8003BFA0;
    case 0x8003BFA4u: goto label_8003BFA4;
    case 0x8003BFA8u: goto label_8003BFA8;
    case 0x8003BFACu: goto label_8003BFAC;
    case 0x8003BFB0u: goto label_8003BFB0;
    case 0x8003BFB4u: goto label_8003BFB4;
    case 0x8003BFB8u: goto label_8003BFB8;
    case 0x8003BFBCu: goto label_8003BFBC;
    case 0x8003BFC0u: goto label_8003BFC0;
    case 0x8003BFC4u: goto label_8003BFC4;
    case 0x8003BFC8u: goto label_8003BFC8;
    case 0x8003BFCCu: goto label_8003BFCC;
    case 0x8003BFD0u: goto label_8003BFD0;
    case 0x8003BFD4u: goto label_8003BFD4;
    case 0x8003BFD8u: goto label_8003BFD8;
    case 0x8003BFDCu: goto label_8003BFDC;
    case 0x8003BFE0u: goto label_8003BFE0;
    case 0x8003BFE4u: goto label_8003BFE4;
    case 0x8003BFE8u: goto label_8003BFE8;
    case 0x8003BFECu: goto label_8003BFEC;
    case 0x8003BFF0u: goto label_8003BFF0;
    case 0x8003BFF4u: goto label_8003BFF4;
    case 0x8003BFF8u: goto label_8003BFF8;
    case 0x8003BFFCu: goto label_8003BFFC;
    case 0x8003C000u: goto label_8003C000;
    case 0x8003C004u: goto label_8003C004;
    case 0x8003C008u: goto label_8003C008;
    case 0x8003C00Cu: goto label_8003C00C;
    case 0x8003C010u: goto label_8003C010;
    case 0x8003C014u: goto label_8003C014;
    case 0x8003C018u: goto label_8003C018;
    case 0x8003C01Cu: goto label_8003C01C;
    case 0x8003C020u: goto label_8003C020;
    case 0x8003C024u: goto label_8003C024;
    case 0x8003C028u: goto label_8003C028;
    case 0x8003C02Cu: goto label_8003C02C;
    case 0x8003C030u: goto label_8003C030;
    case 0x8003C034u: goto label_8003C034;
    case 0x8003C038u: goto label_8003C038;
    case 0x8003C03Cu: goto label_8003C03C;
    case 0x8003C040u: goto label_8003C040;
    case 0x8003C044u: goto label_8003C044;
    case 0x8003C048u: goto label_8003C048;
    case 0x8003C04Cu: goto label_8003C04C;
    case 0x8003C050u: goto label_8003C050;
    case 0x8003C054u: goto label_8003C054;
    case 0x8003C058u: goto label_8003C058;
    case 0x8003C05Cu: goto label_8003C05C;
    case 0x8003C060u: goto label_8003C060;
    case 0x8003C064u: goto label_8003C064;
    case 0x8003C068u: goto label_8003C068;
    case 0x8003C06Cu: goto label_8003C06C;
    case 0x8003C070u: goto label_8003C070;
    case 0x8003C074u: goto label_8003C074;
    case 0x8003C078u: goto label_8003C078;
    case 0x8003C07Cu: goto label_8003C07C;
    case 0x8003C080u: goto label_8003C080;
    case 0x8003C084u: goto label_8003C084;
    case 0x8003C088u: goto label_8003C088;
    case 0x8003C08Cu: goto label_8003C08C;
    case 0x8003C090u: goto label_8003C090;
    case 0x8003C094u: goto label_8003C094;
    case 0x8003C098u: goto label_8003C098;
    case 0x8003C09Cu: goto label_8003C09C;
    case 0x8003C0A0u: goto label_8003C0A0;
    case 0x8003C0A4u: goto label_8003C0A4;
    case 0x8003C0A8u: goto label_8003C0A8;
    case 0x8003C0ACu: goto label_8003C0AC;
    case 0x8003C0B0u: goto label_8003C0B0;
    case 0x8003C0B4u: goto label_8003C0B4;
    case 0x8003C0B8u: goto label_8003C0B8;
    case 0x8003C0BCu: goto label_8003C0BC;
    case 0x8003C0C0u: goto label_8003C0C0;
    case 0x8003C0C4u: goto label_8003C0C4;
    case 0x8003C0C8u: goto label_8003C0C8;
    case 0x8003C0CCu: goto label_8003C0CC;
    case 0x8003C0D0u: goto label_8003C0D0;
    case 0x8003C0D4u: goto label_8003C0D4;
    case 0x8003C0D8u: goto label_8003C0D8;
    case 0x8003C0DCu: goto label_8003C0DC;
    case 0x8003C0E0u: goto label_8003C0E0;
    case 0x8003C0E4u: goto label_8003C0E4;
    case 0x8003C0E8u: goto label_8003C0E8;
    case 0x8003C0ECu: goto label_8003C0EC;
    case 0x8003C0F0u: goto label_8003C0F0;
    case 0x8003C0F4u: goto label_8003C0F4;
    case 0x8003C0F8u: goto label_8003C0F8;
    case 0x8003C0FCu: goto label_8003C0FC;
    case 0x8003C100u: goto label_8003C100;
    case 0x8003C104u: goto label_8003C104;
    case 0x8003C108u: goto label_8003C108;
    case 0x8003C10Cu: goto label_8003C10C;
    case 0x8003C110u: goto label_8003C110;
    case 0x8003C114u: goto label_8003C114;
    case 0x8003C118u: goto label_8003C118;
    case 0x8003C11Cu: goto label_8003C11C;
    case 0x8003C120u: goto label_8003C120;
    case 0x8003C124u: goto label_8003C124;
    case 0x8003C128u: goto label_8003C128;
    case 0x8003C12Cu: goto label_8003C12C;
    case 0x8003C130u: goto label_8003C130;
    case 0x8003C134u: goto label_8003C134;
    case 0x8003C138u: goto label_8003C138;
    case 0x8003C13Cu: goto label_8003C13C;
    case 0x8003C140u: goto label_8003C140;
    case 0x8003C144u: goto label_8003C144;
    case 0x8003C148u: goto label_8003C148;
    case 0x8003C14Cu: goto label_8003C14C;
    case 0x8003C150u: goto label_8003C150;
    case 0x8003C154u: goto label_8003C154;
    case 0x8003C158u: goto label_8003C158;
    case 0x8003C15Cu: goto label_8003C15C;
    case 0x8003C160u: goto label_8003C160;
    case 0x8003C164u: goto label_8003C164;
    case 0x8003C168u: goto label_8003C168;
    case 0x8003C16Cu: goto label_8003C16C;
    case 0x8003C170u: goto label_8003C170;
    case 0x8003C174u: goto label_8003C174;
    case 0x8003C178u: goto label_8003C178;
    case 0x8003C17Cu: goto label_8003C17C;
    case 0x8003C180u: goto label_8003C180;
    case 0x8003C184u: goto label_8003C184;
    case 0x8003C188u: goto label_8003C188;
    case 0x8003C18Cu: goto label_8003C18C;
    case 0x8003C190u: goto label_8003C190;
    case 0x8003C194u: goto label_8003C194;
    case 0x8003C198u: goto label_8003C198;
    case 0x8003C19Cu: goto label_8003C19C;
    case 0x8003C1A0u: goto label_8003C1A0;
    case 0x8003C1A4u: goto label_8003C1A4;
    case 0x8003C1A8u: goto label_8003C1A8;
    case 0x8003C1ACu: goto label_8003C1AC;
    case 0x8003C1B0u: goto label_8003C1B0;
    case 0x8003C1B4u: goto label_8003C1B4;
    case 0x8003C1B8u: goto label_8003C1B8;
    case 0x8003C1BCu: goto label_8003C1BC;
    case 0x8003C1C0u: goto label_8003C1C0;
    case 0x8003C1C4u: goto label_8003C1C4;
    case 0x8003C1C8u: goto label_8003C1C8;
    case 0x8003C1CCu: goto label_8003C1CC;
    case 0x8003C1D0u: goto label_8003C1D0;
    case 0x8003C1D4u: goto label_8003C1D4;
    case 0x8003C1D8u: goto label_8003C1D8;
    case 0x8003C1DCu: goto label_8003C1DC;
    case 0x8003C1E0u: goto label_8003C1E0;
    case 0x8003C1E4u: goto label_8003C1E4;
    case 0x8003C1E8u: goto label_8003C1E8;
    case 0x8003C1ECu: goto label_8003C1EC;
    case 0x8003C1F0u: goto label_8003C1F0;
    case 0x8003C1F4u: goto label_8003C1F4;
    case 0x8003C1F8u: goto label_8003C1F8;
    case 0x8003C1FCu: goto label_8003C1FC;
    case 0x8003C200u: goto label_8003C200;
    case 0x8003C204u: goto label_8003C204;
    case 0x8003C208u: goto label_8003C208;
    case 0x8003C20Cu: goto label_8003C20C;
    case 0x8003C210u: goto label_8003C210;
    case 0x8003C214u: goto label_8003C214;
    case 0x8003C218u: goto label_8003C218;
    case 0x8003C21Cu: goto label_8003C21C;
    case 0x8003C220u: goto label_8003C220;
    case 0x8003C224u: goto label_8003C224;
    case 0x8003C228u: goto label_8003C228;
    case 0x8003C22Cu: goto label_8003C22C;
    case 0x8003C230u: goto label_8003C230;
    case 0x8003C234u: goto label_8003C234;
    case 0x8003C238u: goto label_8003C238;
    case 0x8003C23Cu: goto label_8003C23C;
    case 0x8003C240u: goto label_8003C240;
    case 0x8003C244u: goto label_8003C244;
    case 0x8003C248u: goto label_8003C248;
    case 0x8003C24Cu: goto label_8003C24C;
    case 0x8003C250u: goto label_8003C250;
    case 0x8003C254u: goto label_8003C254;
    case 0x8003C258u: goto label_8003C258;
    case 0x8003C25Cu: goto label_8003C25C;
    case 0x8003C260u: goto label_8003C260;
    case 0x8003C264u: goto label_8003C264;
    case 0x8003C268u: goto label_8003C268;
    case 0x8003C26Cu: goto label_8003C26C;
    case 0x8003C270u: goto label_8003C270;
    case 0x8003C274u: goto label_8003C274;
    case 0x8003C278u: goto label_8003C278;
    case 0x8003C27Cu: goto label_8003C27C;
    case 0x8003C280u: goto label_8003C280;
    case 0x8003C284u: goto label_8003C284;
    case 0x8003C288u: goto label_8003C288;
    case 0x8003C28Cu: goto label_8003C28C;
    case 0x8003C290u: goto label_8003C290;
    case 0x8003C294u: goto label_8003C294;
    case 0x8003C298u: goto label_8003C298;
    case 0x8003C29Cu: goto label_8003C29C;
    case 0x8003C2A0u: goto label_8003C2A0;
    case 0x8003C2A4u: goto label_8003C2A4;
    case 0x8003C2A8u: goto label_8003C2A8;
    case 0x8003C2ACu: goto label_8003C2AC;
    case 0x8003C2B0u: goto label_8003C2B0;
    case 0x8003C2B4u: goto label_8003C2B4;
    case 0x8003C2B8u: goto label_8003C2B8;
    case 0x8003C2BCu: goto label_8003C2BC;
    case 0x8003C2C0u: goto label_8003C2C0;
    case 0x8003C2C4u: goto label_8003C2C4;
    case 0x8003C2C8u: goto label_8003C2C8;
    case 0x8003C2CCu: goto label_8003C2CC;
    case 0x8003C2D0u: goto label_8003C2D0;
    case 0x8003C2D4u: goto label_8003C2D4;
    case 0x8003C2D8u: goto label_8003C2D8;
    case 0x8003C2DCu: goto label_8003C2DC;
    case 0x8003C2E0u: goto label_8003C2E0;
    case 0x8003C2E4u: goto label_8003C2E4;
    case 0x8003C2E8u: goto label_8003C2E8;
    case 0x8003C2ECu: goto label_8003C2EC;
    case 0x8003C2F0u: goto label_8003C2F0;
    case 0x8003C2F4u: goto label_8003C2F4;
    case 0x8003C2F8u: goto label_8003C2F8;
    case 0x8003C2FCu: goto label_8003C2FC;
    case 0x8003C300u: goto label_8003C300;
    case 0x8003C304u: goto label_8003C304;
    case 0x8003C308u: goto label_8003C308;
    case 0x8003C30Cu: goto label_8003C30C;
    case 0x8003C310u: goto label_8003C310;
    case 0x8003C314u: goto label_8003C314;
    case 0x8003C318u: goto label_8003C318;
    case 0x8003C31Cu: goto label_8003C31C;
    case 0x8003C320u: goto label_8003C320;
    case 0x8003C324u: goto label_8003C324;
    case 0x8003C328u: goto label_8003C328;
    case 0x8003C32Cu: goto label_8003C32C;
    case 0x8003C330u: goto label_8003C330;
    case 0x8003C334u: goto label_8003C334;
    case 0x8003C338u: goto label_8003C338;
    case 0x8003C33Cu: goto label_8003C33C;
    case 0x8003C340u: goto label_8003C340;
    case 0x8003C344u: goto label_8003C344;
    case 0x8003C348u: goto label_8003C348;
    case 0x8003C34Cu: goto label_8003C34C;
    case 0x8003C350u: goto label_8003C350;
    case 0x8003C354u: goto label_8003C354;
    case 0x8003C358u: goto label_8003C358;
    case 0x8003C35Cu: goto label_8003C35C;
    case 0x8003C360u: goto label_8003C360;
    case 0x8003C364u: goto label_8003C364;
    case 0x8003C368u: goto label_8003C368;
    case 0x8003C36Cu: goto label_8003C36C;
    case 0x8003C370u: goto label_8003C370;
    case 0x8003C374u: goto label_8003C374;
    case 0x8003C378u: goto label_8003C378;
    case 0x8003C37Cu: goto label_8003C37C;
    case 0x8003C380u: goto label_8003C380;
    case 0x8003C384u: goto label_8003C384;
    case 0x8003C388u: goto label_8003C388;
    case 0x8003C38Cu: goto label_8003C38C;
    case 0x8003C390u: goto label_8003C390;
    case 0x8003C394u: goto label_8003C394;
    case 0x8003C398u: goto label_8003C398;
    case 0x8003C39Cu: goto label_8003C39C;
    case 0x8003C3A0u: goto label_8003C3A0;
    case 0x8003C3A4u: goto label_8003C3A4;
    case 0x8003C3A8u: goto label_8003C3A8;
    case 0x8003C3ACu: goto label_8003C3AC;
    case 0x8003C3B0u: goto label_8003C3B0;
    case 0x8003C3B4u: goto label_8003C3B4;
    case 0x8003C3B8u: goto label_8003C3B8;
    case 0x8003C3BCu: goto label_8003C3BC;
    case 0x8003C3C0u: goto label_8003C3C0;
    case 0x8003C3C4u: goto label_8003C3C4;
    case 0x8003C3C8u: goto label_8003C3C8;
    case 0x8003C3CCu: goto label_8003C3CC;
    case 0x8003C3D0u: goto label_8003C3D0;
    case 0x8003C3D4u: goto label_8003C3D4;
    case 0x8003C3D8u: goto label_8003C3D8;
    case 0x8003C3DCu: goto label_8003C3DC;
    case 0x8003C3E0u: goto label_8003C3E0;
    case 0x8003C3E4u: goto label_8003C3E4;
    case 0x8003C3E8u: goto label_8003C3E8;
    case 0x8003C3ECu: goto label_8003C3EC;
    case 0x8003C3F0u: goto label_8003C3F0;
    case 0x8003C3F4u: goto label_8003C3F4;
    case 0x8003C3F8u: goto label_8003C3F8;
    case 0x8003C3FCu: goto label_8003C3FC;
    case 0x8003C400u: goto label_8003C400;
    case 0x8003C404u: goto label_8003C404;
    case 0x8003C408u: goto label_8003C408;
    case 0x8003C40Cu: goto label_8003C40C;
    case 0x8003C410u: goto label_8003C410;
    case 0x8003C414u: goto label_8003C414;
    case 0x8003C418u: goto label_8003C418;
    case 0x8003C41Cu: goto label_8003C41C;
    case 0x8003C420u: goto label_8003C420;
    case 0x8003C424u: goto label_8003C424;
    case 0x8003C428u: goto label_8003C428;
    case 0x8003C42Cu: goto label_8003C42C;
    case 0x8003C430u: goto label_8003C430;
    case 0x8003C434u: goto label_8003C434;
    case 0x8003C438u: goto label_8003C438;
    case 0x8003C43Cu: goto label_8003C43C;
    case 0x8003C440u: goto label_8003C440;
    case 0x8003C444u: goto label_8003C444;
    case 0x8003C448u: goto label_8003C448;
    case 0x8003C44Cu: goto label_8003C44C;
    case 0x8003C450u: goto label_8003C450;
    case 0x8003C454u: goto label_8003C454;
    case 0x8003C458u: goto label_8003C458;
    case 0x8003C45Cu: goto label_8003C45C;
    case 0x8003C460u: goto label_8003C460;
    case 0x8003C464u: goto label_8003C464;
    case 0x8003C468u: goto label_8003C468;
    case 0x8003C46Cu: goto label_8003C46C;
    case 0x8003C470u: goto label_8003C470;
    case 0x8003C474u: goto label_8003C474;
    case 0x8003C478u: goto label_8003C478;
    case 0x8003C47Cu: goto label_8003C47C;
    case 0x8003C480u: goto label_8003C480;
    case 0x8003C484u: goto label_8003C484;
    case 0x8003C488u: goto label_8003C488;
    case 0x8003C48Cu: goto label_8003C48C;
    case 0x8003C490u: goto label_8003C490;
    case 0x8003C494u: goto label_8003C494;
    case 0x8003C498u: goto label_8003C498;
    case 0x8003C49Cu: goto label_8003C49C;
    case 0x8003C4A0u: goto label_8003C4A0;
    case 0x8003C4A4u: goto label_8003C4A4;
    case 0x8003C4A8u: goto label_8003C4A8;
    case 0x8003C4ACu: goto label_8003C4AC;
    case 0x8003C4B0u: goto label_8003C4B0;
    case 0x8003C4B4u: goto label_8003C4B4;
    case 0x8003C4B8u: goto label_8003C4B8;
    case 0x8003C4BCu: goto label_8003C4BC;
    case 0x8003C4C0u: goto label_8003C4C0;
    case 0x8003C4C4u: goto label_8003C4C4;
    case 0x8003C4C8u: goto label_8003C4C8;
    case 0x8003C4CCu: goto label_8003C4CC;
    case 0x8003C4D0u: goto label_8003C4D0;
    case 0x8003C4D4u: goto label_8003C4D4;
    case 0x8003C4D8u: goto label_8003C4D8;
    case 0x8003C4DCu: goto label_8003C4DC;
    case 0x8003C4E0u: goto label_8003C4E0;
    case 0x8003C4E4u: goto label_8003C4E4;
    case 0x8003C4E8u: goto label_8003C4E8;
    case 0x8003C4ECu: goto label_8003C4EC;
    case 0x8003C4F0u: goto label_8003C4F0;
    case 0x8003C4F4u: goto label_8003C4F4;
    case 0x8003C4F8u: goto label_8003C4F8;
    case 0x8003C4FCu: goto label_8003C4FC;
    case 0x8003C500u: goto label_8003C500;
    case 0x8003C504u: goto label_8003C504;
    case 0x8003C508u: goto label_8003C508;
    case 0x8003C50Cu: goto label_8003C50C;
    case 0x8003C510u: goto label_8003C510;
    case 0x8003C514u: goto label_8003C514;
    case 0x8003C518u: goto label_8003C518;
    case 0x8003C51Cu: goto label_8003C51C;
    case 0x8003C520u: goto label_8003C520;
    case 0x8003C524u: goto label_8003C524;
    case 0x8003C528u: goto label_8003C528;
    case 0x8003C52Cu: goto label_8003C52C;
    case 0x8003C530u: goto label_8003C530;
    case 0x8003C534u: goto label_8003C534;
    case 0x8003C538u: goto label_8003C538;
    case 0x8003C53Cu: goto label_8003C53C;
    case 0x8003C540u: goto label_8003C540;
    case 0x8003C544u: goto label_8003C544;
    case 0x8003C548u: goto label_8003C548;
    case 0x8003C54Cu: goto label_8003C54C;
    case 0x8003C550u: goto label_8003C550;
    case 0x8003C554u: goto label_8003C554;
    case 0x8003C558u: goto label_8003C558;
    case 0x8003C55Cu: goto label_8003C55C;
    case 0x8003C560u: goto label_8003C560;
    case 0x8003C564u: goto label_8003C564;
    case 0x8003C568u: goto label_8003C568;
    case 0x8003C56Cu: goto label_8003C56C;
    case 0x8003C570u: goto label_8003C570;
    case 0x8003C574u: goto label_8003C574;
    case 0x8003C578u: goto label_8003C578;
    case 0x8003C57Cu: goto label_8003C57C;
    case 0x8003C580u: goto label_8003C580;
    case 0x8003C584u: goto label_8003C584;
    case 0x8003C588u: goto label_8003C588;
    case 0x8003C58Cu: goto label_8003C58C;
    case 0x8003C590u: goto label_8003C590;
    case 0x8003C594u: goto label_8003C594;
    case 0x8003C598u: goto label_8003C598;
    case 0x8003C59Cu: goto label_8003C59C;
    case 0x8003C5A0u: goto label_8003C5A0;
    case 0x8003C5A4u: goto label_8003C5A4;
    case 0x8003C5A8u: goto label_8003C5A8;
    case 0x8003C5ACu: goto label_8003C5AC;
    case 0x8003C5B0u: goto label_8003C5B0;
    case 0x8003C5B4u: goto label_8003C5B4;
    case 0x8003C5B8u: goto label_8003C5B8;
    case 0x8003C5BCu: goto label_8003C5BC;
    case 0x8003C5C0u: goto label_8003C5C0;
    case 0x8003C5C4u: goto label_8003C5C4;
    case 0x8003C5C8u: goto label_8003C5C8;
    case 0x8003C5CCu: goto label_8003C5CC;
    case 0x8003C5D0u: goto label_8003C5D0;
    case 0x8003C5D4u: goto label_8003C5D4;
    case 0x8003C5D8u: goto label_8003C5D8;
    case 0x8003C5DCu: goto label_8003C5DC;
    case 0x8003C5E0u: goto label_8003C5E0;
    case 0x8003C5E4u: goto label_8003C5E4;
    case 0x8003C5E8u: goto label_8003C5E8;
    case 0x8003C5ECu: goto label_8003C5EC;
    case 0x8003C5F0u: goto label_8003C5F0;
    case 0x8003C5F4u: goto label_8003C5F4;
    case 0x8003C5F8u: goto label_8003C5F8;
    case 0x8003C5FCu: goto label_8003C5FC;
    case 0x8003C600u: goto label_8003C600;
    case 0x8003C604u: goto label_8003C604;
    case 0x8003C608u: goto label_8003C608;
    case 0x8003C60Cu: goto label_8003C60C;
    case 0x8003C610u: goto label_8003C610;
    case 0x8003C614u: goto label_8003C614;
    case 0x8003C618u: goto label_8003C618;
    case 0x8003C61Cu: goto label_8003C61C;
    case 0x8003C620u: goto label_8003C620;
    case 0x8003C624u: goto label_8003C624;
    case 0x8003C628u: goto label_8003C628;
    case 0x8003C62Cu: goto label_8003C62C;
    case 0x8003C630u: goto label_8003C630;
    case 0x8003C634u: goto label_8003C634;
    case 0x8003C638u: goto label_8003C638;
    case 0x8003C63Cu: goto label_8003C63C;
    case 0x8003C640u: goto label_8003C640;
    case 0x8003C644u: goto label_8003C644;
    case 0x8003C648u: goto label_8003C648;
    case 0x8003C64Cu: goto label_8003C64C;
    case 0x8003C650u: goto label_8003C650;
    case 0x8003C654u: goto label_8003C654;
    case 0x8003C658u: goto label_8003C658;
    case 0x8003C65Cu: goto label_8003C65C;
    case 0x8003C660u: goto label_8003C660;
    case 0x8003C664u: goto label_8003C664;
    case 0x8003C668u: goto label_8003C668;
    case 0x8003C66Cu: goto label_8003C66C;
    case 0x8003C670u: goto label_8003C670;
    case 0x8003C674u: goto label_8003C674;
    case 0x8003C678u: goto label_8003C678;
    case 0x8003C67Cu: goto label_8003C67C;
    case 0x8003C680u: goto label_8003C680;
    case 0x8003C684u: goto label_8003C684;
    case 0x8003C688u: goto label_8003C688;
    case 0x8003C68Cu: goto label_8003C68C;
    case 0x8003C690u: goto label_8003C690;
    case 0x8003C694u: goto label_8003C694;
    case 0x8003C698u: goto label_8003C698;
    case 0x8003C69Cu: goto label_8003C69C;
    case 0x8003C6A0u: goto label_8003C6A0;
    case 0x8003C6A4u: goto label_8003C6A4;
    case 0x8003C6A8u: goto label_8003C6A8;
    case 0x8003C6ACu: goto label_8003C6AC;
    case 0x8003C6B0u: goto label_8003C6B0;
    case 0x8003C6B4u: goto label_8003C6B4;
    case 0x8003C6B8u: goto label_8003C6B8;
    case 0x8003C6BCu: goto label_8003C6BC;
    case 0x8003C6C0u: goto label_8003C6C0;
    case 0x8003C6C4u: goto label_8003C6C4;
    case 0x8003C6C8u: goto label_8003C6C8;
    case 0x8003C6CCu: goto label_8003C6CC;
    case 0x8003C6D0u: goto label_8003C6D0;
    case 0x8003C6D4u: goto label_8003C6D4;
    case 0x8003C6D8u: goto label_8003C6D8;
    case 0x8003C6DCu: goto label_8003C6DC;
    case 0x8003C6E0u: goto label_8003C6E0;
    case 0x8003C6E4u: goto label_8003C6E4;
    case 0x8003C6E8u: goto label_8003C6E8;
    case 0x8003C6ECu: goto label_8003C6EC;
    case 0x8003C6F0u: goto label_8003C6F0;
    case 0x8003C6F4u: goto label_8003C6F4;
    case 0x8003C6F8u: goto label_8003C6F8;
    case 0x8003C6FCu: goto label_8003C6FC;
    case 0x8003C700u: goto label_8003C700;
    case 0x8003C704u: goto label_8003C704;
    case 0x8003C708u: goto label_8003C708;
    case 0x8003C70Cu: goto label_8003C70C;
    case 0x8003C710u: goto label_8003C710;
    case 0x8003C714u: goto label_8003C714;
    case 0x8003C718u: goto label_8003C718;
    case 0x8003C71Cu: goto label_8003C71C;
    case 0x8003C720u: goto label_8003C720;
    case 0x8003C724u: goto label_8003C724;
    case 0x8003C728u: goto label_8003C728;
    case 0x8003C72Cu: goto label_8003C72C;
    case 0x8003C730u: goto label_8003C730;
    case 0x8003C734u: goto label_8003C734;
    case 0x8003C738u: goto label_8003C738;
    case 0x8003C73Cu: goto label_8003C73C;
    case 0x8003C740u: goto label_8003C740;
    case 0x8003C744u: goto label_8003C744;
    case 0x8003C748u: goto label_8003C748;
    case 0x8003C74Cu: goto label_8003C74C;
    case 0x8003C750u: goto label_8003C750;
    case 0x8003C754u: goto label_8003C754;
    case 0x8003C758u: goto label_8003C758;
    case 0x8003C75Cu: goto label_8003C75C;
    case 0x8003C760u: goto label_8003C760;
    case 0x8003C764u: goto label_8003C764;
    case 0x8003C768u: goto label_8003C768;
    case 0x8003C76Cu: goto label_8003C76C;
    case 0x8003C770u: goto label_8003C770;
    case 0x8003C774u: goto label_8003C774;
    case 0x8003C778u: goto label_8003C778;
    case 0x8003C77Cu: goto label_8003C77C;
    case 0x8003C780u: goto label_8003C780;
    case 0x8003C784u: goto label_8003C784;
    case 0x8003C788u: goto label_8003C788;
    case 0x8003C78Cu: goto label_8003C78C;
    case 0x8003C790u: goto label_8003C790;
    case 0x8003C794u: goto label_8003C794;
    case 0x8003C798u: goto label_8003C798;
    case 0x8003C79Cu: goto label_8003C79C;
    case 0x8003C7A0u: goto label_8003C7A0;
    case 0x8003C7A4u: goto label_8003C7A4;
    case 0x8003C7A8u: goto label_8003C7A8;
    case 0x8003C7ACu: goto label_8003C7AC;
    case 0x8003C7B0u: goto label_8003C7B0;
    case 0x8003C7B4u: goto label_8003C7B4;
    case 0x8003C7B8u: goto label_8003C7B8;
    case 0x8003C7BCu: goto label_8003C7BC;
    case 0x8003C7C0u: goto label_8003C7C0;
    case 0x8003C7C4u: goto label_8003C7C4;
    case 0x8003C7C8u: goto label_8003C7C8;
    case 0x8003C7CCu: goto label_8003C7CC;
    case 0x8003C7D0u: goto label_8003C7D0;
    case 0x8003C7D4u: goto label_8003C7D4;
    case 0x8003C7D8u: goto label_8003C7D8;
    case 0x8003C7DCu: goto label_8003C7DC;
    case 0x8003C7E0u: goto label_8003C7E0;
    case 0x8003C7E4u: goto label_8003C7E4;
    case 0x8003C7E8u: goto label_8003C7E8;
    case 0x8003C7ECu: goto label_8003C7EC;
    case 0x8003C7F0u: goto label_8003C7F0;
    case 0x8003C7F4u: goto label_8003C7F4;
    case 0x8003C7F8u: goto label_8003C7F8;
    case 0x8003C7FCu: goto label_8003C7FC;
    case 0x8003C800u: goto label_8003C800;
    case 0x8003C804u: goto label_8003C804;
    case 0x8003C808u: goto label_8003C808;
    case 0x8003C80Cu: goto label_8003C80C;
    case 0x8003C810u: goto label_8003C810;
    case 0x8003C814u: goto label_8003C814;
    case 0x8003C818u: goto label_8003C818;
    case 0x8003C81Cu: goto label_8003C81C;
    case 0x8003C820u: goto label_8003C820;
    case 0x8003C824u: goto label_8003C824;
    case 0x8003C828u: goto label_8003C828;
    case 0x8003C82Cu: goto label_8003C82C;
    case 0x8003C830u: goto label_8003C830;
    case 0x8003C834u: goto label_8003C834;
    case 0x8003C838u: goto label_8003C838;
    case 0x8003C83Cu: goto label_8003C83C;
    case 0x8003C840u: goto label_8003C840;
    case 0x8003C844u: goto label_8003C844;
    case 0x8003C848u: goto label_8003C848;
    case 0x8003C84Cu: goto label_8003C84C;
    case 0x8003C850u: goto label_8003C850;
    case 0x8003C854u: goto label_8003C854;
    case 0x8003C858u: goto label_8003C858;
    case 0x8003C85Cu: goto label_8003C85C;
    case 0x8003C860u: goto label_8003C860;
    case 0x8003C864u: goto label_8003C864;
    case 0x8003C868u: goto label_8003C868;
    case 0x8003C86Cu: goto label_8003C86C;
    case 0x8003C870u: goto label_8003C870;
    case 0x8003C874u: goto label_8003C874;
    case 0x8003C878u: goto label_8003C878;
    case 0x8003C87Cu: goto label_8003C87C;
    case 0x8003C880u: goto label_8003C880;
    case 0x8003C884u: goto label_8003C884;
    case 0x8003C888u: goto label_8003C888;
    case 0x8003C88Cu: goto label_8003C88C;
    case 0x8003C890u: goto label_8003C890;
    case 0x8003C894u: goto label_8003C894;
    case 0x8003C898u: goto label_8003C898;
    case 0x8003C89Cu: goto label_8003C89C;
    case 0x8003C8A0u: goto label_8003C8A0;
    case 0x8003C8A4u: goto label_8003C8A4;
    case 0x8003C8A8u: goto label_8003C8A8;
    case 0x8003C8ACu: goto label_8003C8AC;
    case 0x8003C8B0u: goto label_8003C8B0;
    case 0x8003C8B4u: goto label_8003C8B4;
    case 0x8003C8B8u: goto label_8003C8B8;
    case 0x8003C8BCu: goto label_8003C8BC;
    case 0x8003C8C0u: goto label_8003C8C0;
    case 0x8003C8C4u: goto label_8003C8C4;
    case 0x8003C8C8u: goto label_8003C8C8;
    case 0x8003C8CCu: goto label_8003C8CC;
    case 0x8003C8D0u: goto label_8003C8D0;
    case 0x8003C8D4u: goto label_8003C8D4;
    case 0x8003C8D8u: goto label_8003C8D8;
    case 0x8003C8DCu: goto label_8003C8DC;
    case 0x8003C8E0u: goto label_8003C8E0;
    case 0x8003C8E4u: goto label_8003C8E4;
    case 0x8003C8E8u: goto label_8003C8E8;
    case 0x8003C8ECu: goto label_8003C8EC;
    case 0x8003C8F0u: goto label_8003C8F0;
    case 0x8003C8F4u: goto label_8003C8F4;
    case 0x8003C8F8u: goto label_8003C8F8;
    case 0x8003C8FCu: goto label_8003C8FC;
    case 0x8003C900u: goto label_8003C900;
    case 0x8003C904u: goto label_8003C904;
    case 0x8003C908u: goto label_8003C908;
    case 0x8003C90Cu: goto label_8003C90C;
    case 0x8003C910u: goto label_8003C910;
    case 0x8003C914u: goto label_8003C914;
    case 0x8003C918u: goto label_8003C918;
    case 0x8003C91Cu: goto label_8003C91C;
    case 0x8003C920u: goto label_8003C920;
    case 0x8003C924u: goto label_8003C924;
    case 0x8003C928u: goto label_8003C928;
    case 0x8003C92Cu: goto label_8003C92C;
    case 0x8003C930u: goto label_8003C930;
    case 0x8003C934u: goto label_8003C934;
    case 0x8003C938u: goto label_8003C938;
    case 0x8003C93Cu: goto label_8003C93C;
    case 0x8003C940u: goto label_8003C940;
    case 0x8003C944u: goto label_8003C944;
    case 0x8003C948u: goto label_8003C948;
    case 0x8003C94Cu: goto label_8003C94C;
    case 0x8003C950u: goto label_8003C950;
    case 0x8003C954u: goto label_8003C954;
    case 0x8003C958u: goto label_8003C958;
    case 0x8003C95Cu: goto label_8003C95C;
    case 0x8003C960u: goto label_8003C960;
    case 0x8003C964u: goto label_8003C964;
    case 0x8003C968u: goto label_8003C968;
    case 0x8003C96Cu: goto label_8003C96C;
    case 0x8003C970u: goto label_8003C970;
    case 0x8003C974u: goto label_8003C974;
    case 0x8003C978u: goto label_8003C978;
    case 0x8003C97Cu: goto label_8003C97C;
    case 0x8003C980u: goto label_8003C980;
    case 0x8003C984u: goto label_8003C984;
    case 0x8003C988u: goto label_8003C988;
    case 0x8003C98Cu: goto label_8003C98C;
    case 0x8003C990u: goto label_8003C990;
    case 0x8003C994u: goto label_8003C994;
    case 0x8003C998u: goto label_8003C998;
    case 0x8003C99Cu: goto label_8003C99C;
    case 0x8003C9A0u: goto label_8003C9A0;
    case 0x8003C9A4u: goto label_8003C9A4;
    case 0x8003C9A8u: goto label_8003C9A8;
    case 0x8003C9ACu: goto label_8003C9AC;
    case 0x8003C9B0u: goto label_8003C9B0;
    case 0x8003C9B4u: goto label_8003C9B4;
    case 0x8003C9B8u: goto label_8003C9B8;
    case 0x8003C9BCu: goto label_8003C9BC;
    case 0x8003C9C0u: goto label_8003C9C0;
    case 0x8003C9C4u: goto label_8003C9C4;
    case 0x8003C9C8u: goto label_8003C9C8;
    case 0x8003C9CCu: goto label_8003C9CC;
    case 0x8003C9D0u: goto label_8003C9D0;
    case 0x8003C9D4u: goto label_8003C9D4;
    case 0x8003C9D8u: goto label_8003C9D8;
    case 0x8003C9DCu: goto label_8003C9DC;
    case 0x8003C9E0u: goto label_8003C9E0;
    case 0x8003C9E4u: goto label_8003C9E4;
    case 0x8003C9E8u: goto label_8003C9E8;
    case 0x8003C9ECu: goto label_8003C9EC;
    case 0x8003C9F0u: goto label_8003C9F0;
    case 0x8003C9F4u: goto label_8003C9F4;
    case 0x8003C9F8u: goto label_8003C9F8;
    case 0x8003C9FCu: goto label_8003C9FC;
    case 0x8003CA00u: goto label_8003CA00;
    case 0x8003CA04u: goto label_8003CA04;
    case 0x8003CA08u: goto label_8003CA08;
    case 0x8003CA0Cu: goto label_8003CA0C;
    case 0x8003CA10u: goto label_8003CA10;
    case 0x8003CA14u: goto label_8003CA14;
    case 0x8003CA18u: goto label_8003CA18;
    case 0x8003CA1Cu: goto label_8003CA1C;
    case 0x8003CA20u: goto label_8003CA20;
    case 0x8003CA24u: goto label_8003CA24;
    case 0x8003CA28u: goto label_8003CA28;
    case 0x8003CA2Cu: goto label_8003CA2C;
    case 0x8003CA30u: goto label_8003CA30;
    case 0x8003CA34u: goto label_8003CA34;
    case 0x8003CA38u: goto label_8003CA38;
    case 0x8003CA3Cu: goto label_8003CA3C;
    case 0x8003CA40u: goto label_8003CA40;
    case 0x8003CA44u: goto label_8003CA44;
    case 0x8003CA48u: goto label_8003CA48;
    case 0x8003CA4Cu: goto label_8003CA4C;
    case 0x8003CA50u: goto label_8003CA50;
    case 0x8003CA54u: goto label_8003CA54;
    case 0x8003CA58u: goto label_8003CA58;
    case 0x8003CA5Cu: goto label_8003CA5C;
    case 0x8003CA60u: goto label_8003CA60;
    case 0x8003CA64u: goto label_8003CA64;
    case 0x8003CA68u: goto label_8003CA68;
    case 0x8003CA6Cu: goto label_8003CA6C;
    case 0x8003CA70u: goto label_8003CA70;
    case 0x8003CA74u: goto label_8003CA74;
    case 0x8003CA78u: goto label_8003CA78;
    case 0x8003CA7Cu: goto label_8003CA7C;
    case 0x8003CA80u: goto label_8003CA80;
    case 0x8003CA84u: goto label_8003CA84;
    case 0x8003CA88u: goto label_8003CA88;
    case 0x8003CA8Cu: goto label_8003CA8C;
    case 0x8003CA90u: goto label_8003CA90;
    case 0x8003CA94u: goto label_8003CA94;
    case 0x8003CA98u: goto label_8003CA98;
    case 0x8003CA9Cu: goto label_8003CA9C;
    case 0x8003CAA0u: goto label_8003CAA0;
    case 0x8003CAA4u: goto label_8003CAA4;
    case 0x8003CAA8u: goto label_8003CAA8;
    case 0x8003CAACu: goto label_8003CAAC;
    case 0x8003CAB0u: goto label_8003CAB0;
    case 0x8003CAB4u: goto label_8003CAB4;
    case 0x8003CAB8u: goto label_8003CAB8;
    case 0x8003CABCu: goto label_8003CABC;
    case 0x8003CAC0u: goto label_8003CAC0;
    case 0x8003CAC4u: goto label_8003CAC4;
    case 0x8003CAC8u: goto label_8003CAC8;
    case 0x8003CACCu: goto label_8003CACC;
    case 0x8003CAD0u: goto label_8003CAD0;
    case 0x8003CAD4u: goto label_8003CAD4;
    case 0x8003CAD8u: goto label_8003CAD8;
    case 0x8003CADCu: goto label_8003CADC;
    case 0x8003CAE0u: goto label_8003CAE0;
    case 0x8003CAE4u: goto label_8003CAE4;
    case 0x8003CAE8u: goto label_8003CAE8;
    case 0x8003CAECu: goto label_8003CAEC;
    case 0x8003CAF0u: goto label_8003CAF0;
    case 0x8003CAF4u: goto label_8003CAF4;
    case 0x8003CAF8u: goto label_8003CAF8;
    case 0x8003CAFCu: goto label_8003CAFC;
    case 0x8003CB00u: goto label_8003CB00;
    case 0x8003CB04u: goto label_8003CB04;
    case 0x8003CB08u: goto label_8003CB08;
    case 0x8003CB0Cu: goto label_8003CB0C;
    case 0x8003CB10u: goto label_8003CB10;
    case 0x8003CB14u: goto label_8003CB14;
    case 0x8003CB18u: goto label_8003CB18;
    case 0x8003CB1Cu: goto label_8003CB1C;
    case 0x8003CB20u: goto label_8003CB20;
    case 0x8003CB24u: goto label_8003CB24;
    case 0x8003CB28u: goto label_8003CB28;
    case 0x8003CB2Cu: goto label_8003CB2C;
    case 0x8003CB30u: goto label_8003CB30;
    case 0x8003CB34u: goto label_8003CB34;
    case 0x8003CB38u: goto label_8003CB38;
    case 0x8003CB3Cu: goto label_8003CB3C;
    case 0x8003CB40u: goto label_8003CB40;
    case 0x8003CB44u: goto label_8003CB44;
    case 0x8003CB48u: goto label_8003CB48;
    case 0x8003CB4Cu: goto label_8003CB4C;
    case 0x8003CB50u: goto label_8003CB50;
    case 0x8003CB54u: goto label_8003CB54;
    case 0x8003CB58u: goto label_8003CB58;
    case 0x8003CB5Cu: goto label_8003CB5C;
    case 0x8003CB60u: goto label_8003CB60;
    case 0x8003CB64u: goto label_8003CB64;
    case 0x8003CB68u: goto label_8003CB68;
    case 0x8003CB6Cu: goto label_8003CB6C;
    case 0x8003CB70u: goto label_8003CB70;
    case 0x8003CB74u: goto label_8003CB74;
    case 0x8003CB78u: goto label_8003CB78;
    case 0x8003CB7Cu: goto label_8003CB7C;
    case 0x8003CB80u: goto label_8003CB80;
    case 0x8003CB84u: goto label_8003CB84;
    case 0x8003CB88u: goto label_8003CB88;
    case 0x8003CB8Cu: goto label_8003CB8C;
    case 0x8003CB90u: goto label_8003CB90;
    case 0x8003CB94u: goto label_8003CB94;
    case 0x8003CB98u: goto label_8003CB98;
    case 0x8003CB9Cu: goto label_8003CB9C;
    case 0x8003CBA0u: goto label_8003CBA0;
    case 0x8003CBA4u: goto label_8003CBA4;
    case 0x8003CBA8u: goto label_8003CBA8;
    case 0x8003CBACu: goto label_8003CBAC;
    case 0x8003CBB0u: goto label_8003CBB0;
    case 0x8003CBB4u: goto label_8003CBB4;
    case 0x8003CBB8u: goto label_8003CBB8;
    case 0x8003CBBCu: goto label_8003CBBC;
    case 0x8003CBC0u: goto label_8003CBC0;
    case 0x8003CBC4u: goto label_8003CBC4;
    case 0x8003CBC8u: goto label_8003CBC8;
    case 0x8003CBCCu: goto label_8003CBCC;
    case 0x8003CBD0u: goto label_8003CBD0;
    case 0x8003CBD4u: goto label_8003CBD4;
    case 0x8003CBD8u: goto label_8003CBD8;
    case 0x8003CBDCu: goto label_8003CBDC;
    case 0x8003CBE0u: goto label_8003CBE0;
    case 0x8003CBE4u: goto label_8003CBE4;
    case 0x8003CBE8u: goto label_8003CBE8;
    case 0x8003CBECu: goto label_8003CBEC;
    case 0x8003CBF0u: goto label_8003CBF0;
    case 0x8003CBF4u: goto label_8003CBF4;
    case 0x8003CBF8u: goto label_8003CBF8;
    case 0x8003CBFCu: goto label_8003CBFC;
    case 0x8003CC00u: goto label_8003CC00;
    case 0x8003CC04u: goto label_8003CC04;
    case 0x8003CC08u: goto label_8003CC08;
    case 0x8003CC0Cu: goto label_8003CC0C;
    case 0x8003CC10u: goto label_8003CC10;
    case 0x8003CC14u: goto label_8003CC14;
    case 0x8003CC18u: goto label_8003CC18;
    case 0x8003CC1Cu: goto label_8003CC1C;
    case 0x8003CC20u: goto label_8003CC20;
    case 0x8003CC24u: goto label_8003CC24;
    case 0x8003CC28u: goto label_8003CC28;
    case 0x8003CC2Cu: goto label_8003CC2C;
    case 0x8003CC30u: goto label_8003CC30;
    case 0x8003CC34u: goto label_8003CC34;
    case 0x8003CC38u: goto label_8003CC38;
    case 0x8003CC3Cu: goto label_8003CC3C;
    case 0x8003CC40u: goto label_8003CC40;
    case 0x8003CC44u: goto label_8003CC44;
    case 0x8003CC48u: goto label_8003CC48;
    case 0x8003CC4Cu: goto label_8003CC4C;
    case 0x8003CC50u: goto label_8003CC50;
    case 0x8003CC54u: goto label_8003CC54;
    case 0x8003CC58u: goto label_8003CC58;
    case 0x8003CC5Cu: goto label_8003CC5C;
    case 0x8003CC60u: goto label_8003CC60;
    case 0x8003CC64u: goto label_8003CC64;
    case 0x8003CC68u: goto label_8003CC68;
    case 0x8003CC6Cu: goto label_8003CC6C;
    case 0x8003CC70u: goto label_8003CC70;
    case 0x8003CC74u: goto label_8003CC74;
    case 0x8003CC78u: goto label_8003CC78;
    case 0x8003CC7Cu: goto label_8003CC7C;
    case 0x8003CC80u: goto label_8003CC80;
    case 0x8003CC84u: goto label_8003CC84;
    case 0x8003CC88u: goto label_8003CC88;
    case 0x8003CC8Cu: goto label_8003CC8C;
    case 0x8003CC90u: goto label_8003CC90;
    case 0x8003CC94u: goto label_8003CC94;
    case 0x8003CC98u: goto label_8003CC98;
    case 0x8003CC9Cu: goto label_8003CC9C;
    case 0x8003CCA0u: goto label_8003CCA0;
    case 0x8003CCA4u: goto label_8003CCA4;
    case 0x8003CCA8u: goto label_8003CCA8;
    case 0x8003CCACu: goto label_8003CCAC;
    case 0x8003CCB0u: goto label_8003CCB0;
    case 0x8003CCB4u: goto label_8003CCB4;
    case 0x8003CCB8u: goto label_8003CCB8;
    case 0x8003CCBCu: goto label_8003CCBC;
    case 0x8003CCC0u: goto label_8003CCC0;
    case 0x8003CCC4u: goto label_8003CCC4;
    case 0x8003CCC8u: goto label_8003CCC8;
    case 0x8003CCCCu: goto label_8003CCCC;
    case 0x8003CCD0u: goto label_8003CCD0;
    case 0x8003CCD4u: goto label_8003CCD4;
    case 0x8003CCD8u: goto label_8003CCD8;
    case 0x8003CCDCu: goto label_8003CCDC;
    case 0x8003CCE0u: goto label_8003CCE0;
    case 0x8003CCE4u: goto label_8003CCE4;
    case 0x8003CCE8u: goto label_8003CCE8;
    case 0x8003CCECu: goto label_8003CCEC;
    case 0x8003CCF0u: goto label_8003CCF0;
    case 0x8003CCF4u: goto label_8003CCF4;
    case 0x8003CCF8u: goto label_8003CCF8;
    case 0x8003CCFCu: goto label_8003CCFC;
    case 0x8003CD00u: goto label_8003CD00;
    case 0x8003CD04u: goto label_8003CD04;
    case 0x8003CD08u: goto label_8003CD08;
    case 0x8003CD0Cu: goto label_8003CD0C;
    case 0x8003CD10u: goto label_8003CD10;
    case 0x8003CD14u: goto label_8003CD14;
    case 0x8003CD18u: goto label_8003CD18;
    case 0x8003CD1Cu: goto label_8003CD1C;
    case 0x8003CD20u: goto label_8003CD20;
    case 0x8003CD24u: goto label_8003CD24;
    case 0x8003CD28u: goto label_8003CD28;
    case 0x8003CD2Cu: goto label_8003CD2C;
    case 0x8003CD30u: goto label_8003CD30;
    case 0x8003CD34u: goto label_8003CD34;
    case 0x8003CD38u: goto label_8003CD38;
    case 0x8003CD3Cu: goto label_8003CD3C;
    case 0x8003CD40u: goto label_8003CD40;
    case 0x8003CD44u: goto label_8003CD44;
    case 0x8003CD48u: goto label_8003CD48;
    case 0x8003CD4Cu: goto label_8003CD4C;
    case 0x8003CD50u: goto label_8003CD50;
    case 0x8003CD54u: goto label_8003CD54;
    case 0x8003CD58u: goto label_8003CD58;
    case 0x8003CD5Cu: goto label_8003CD5C;
    case 0x8003CD60u: goto label_8003CD60;
    case 0x8003CD64u: goto label_8003CD64;
    case 0x8003CD68u: goto label_8003CD68;
    case 0x8003CD6Cu: goto label_8003CD6C;
    case 0x8003CD70u: goto label_8003CD70;
    case 0x8003CD74u: goto label_8003CD74;
    case 0x8003CD78u: goto label_8003CD78;
    case 0x8003CD7Cu: goto label_8003CD7C;
    case 0x8003CD80u: goto label_8003CD80;
    case 0x8003CD84u: goto label_8003CD84;
    case 0x8003CD88u: goto label_8003CD88;
    case 0x8003CD8Cu: goto label_8003CD8C;
    case 0x8003CD90u: goto label_8003CD90;
    case 0x8003CD94u: goto label_8003CD94;
    case 0x8003CD98u: goto label_8003CD98;
    case 0x8003CD9Cu: goto label_8003CD9C;
    case 0x8003CDA0u: goto label_8003CDA0;
    case 0x8003CDA4u: goto label_8003CDA4;
    case 0x8003CDA8u: goto label_8003CDA8;
    case 0x8003CDACu: goto label_8003CDAC;
    case 0x8003CDB0u: goto label_8003CDB0;
    case 0x8003CDB4u: goto label_8003CDB4;
    case 0x8003CDB8u: goto label_8003CDB8;
    case 0x8003CDBCu: goto label_8003CDBC;
    case 0x8003CDC0u: goto label_8003CDC0;
    case 0x8003CDC4u: goto label_8003CDC4;
    case 0x8003CDC8u: goto label_8003CDC8;
    case 0x8003CDCCu: goto label_8003CDCC;
    case 0x8003CDD0u: goto label_8003CDD0;
    case 0x8003CDD4u: goto label_8003CDD4;
    case 0x8003CDD8u: goto label_8003CDD8;
    case 0x8003CDDCu: goto label_8003CDDC;
    case 0x8003CDE0u: goto label_8003CDE0;
    case 0x8003CDE4u: goto label_8003CDE4;
    case 0x8003CDE8u: goto label_8003CDE8;
    case 0x8003CDECu: goto label_8003CDEC;
    case 0x8003CDF0u: goto label_8003CDF0;
    case 0x8003CDF4u: goto label_8003CDF4;
    case 0x8003CDF8u: goto label_8003CDF8;
    case 0x8003CDFCu: goto label_8003CDFC;
    case 0x8003CE00u: goto label_8003CE00;
    case 0x8003CE04u: goto label_8003CE04;
    case 0x8003CE08u: goto label_8003CE08;
    case 0x8003CE0Cu: goto label_8003CE0C;
    case 0x8003CE10u: goto label_8003CE10;
    case 0x8003CE14u: goto label_8003CE14;
    case 0x8003CE18u: goto label_8003CE18;
    case 0x8003CE1Cu: goto label_8003CE1C;
    case 0x8003CE20u: goto label_8003CE20;
    case 0x8003CE24u: goto label_8003CE24;
    case 0x8003CE28u: goto label_8003CE28;
    case 0x8003CE2Cu: goto label_8003CE2C;
    case 0x8003CE30u: goto label_8003CE30;
    case 0x8003CE34u: goto label_8003CE34;
    case 0x8003CE38u: goto label_8003CE38;
    case 0x8003CE3Cu: goto label_8003CE3C;
    case 0x8003CE40u: goto label_8003CE40;
    case 0x8003CE44u: goto label_8003CE44;
    case 0x8003CE48u: goto label_8003CE48;
    case 0x8003CE4Cu: goto label_8003CE4C;
    case 0x8003CE50u: goto label_8003CE50;
    case 0x8003CE54u: goto label_8003CE54;
    case 0x8003CE58u: goto label_8003CE58;
    case 0x8003CE5Cu: goto label_8003CE5C;
    case 0x8003CE60u: goto label_8003CE60;
    case 0x8003CE64u: goto label_8003CE64;
    case 0x8003CE68u: goto label_8003CE68;
    case 0x8003CE6Cu: goto label_8003CE6C;
    case 0x8003CE70u: goto label_8003CE70;
    case 0x8003CE74u: goto label_8003CE74;
    case 0x8003CE78u: goto label_8003CE78;
    case 0x8003CE7Cu: goto label_8003CE7C;
    case 0x8003CE80u: goto label_8003CE80;
    case 0x8003CE84u: goto label_8003CE84;
    case 0x8003CE88u: goto label_8003CE88;
    case 0x8003CE8Cu: goto label_8003CE8C;
    case 0x8003CE90u: goto label_8003CE90;
    case 0x8003CE94u: goto label_8003CE94;
    case 0x8003CE98u: goto label_8003CE98;
    case 0x8003CE9Cu: goto label_8003CE9C;
    case 0x8003CEA0u: goto label_8003CEA0;
    case 0x8003CEA4u: goto label_8003CEA4;
    case 0x8003CEA8u: goto label_8003CEA8;
    case 0x8003CEACu: goto label_8003CEAC;
    case 0x8003CEB0u: goto label_8003CEB0;
    case 0x8003CEB4u: goto label_8003CEB4;
    case 0x8003CEB8u: goto label_8003CEB8;
    case 0x8003CEBCu: goto label_8003CEBC;
    case 0x8003CEC0u: goto label_8003CEC0;
    case 0x8003CEC4u: goto label_8003CEC4;
    case 0x8003CEC8u: goto label_8003CEC8;
    case 0x8003CECCu: goto label_8003CECC;
    case 0x8003CED0u: goto label_8003CED0;
    case 0x8003CED4u: goto label_8003CED4;
    case 0x8003CED8u: goto label_8003CED8;
    case 0x8003CEDCu: goto label_8003CEDC;
    case 0x8003CEE0u: goto label_8003CEE0;
    case 0x8003CEE4u: goto label_8003CEE4;
    case 0x8003CEE8u: goto label_8003CEE8;
    case 0x8003CEECu: goto label_8003CEEC;
    case 0x8003CEF0u: goto label_8003CEF0;
    case 0x8003CEF4u: goto label_8003CEF4;
    case 0x8003CEF8u: goto label_8003CEF8;
    case 0x8003CEFCu: goto label_8003CEFC;
    case 0x8003CF00u: goto label_8003CF00;
    case 0x8003CF04u: goto label_8003CF04;
    case 0x8003CF08u: goto label_8003CF08;
    case 0x8003CF0Cu: goto label_8003CF0C;
    case 0x8003CF10u: goto label_8003CF10;
    case 0x8003CF14u: goto label_8003CF14;
    case 0x8003CF18u: goto label_8003CF18;
    case 0x8003CF1Cu: goto label_8003CF1C;
    case 0x8003CF20u: goto label_8003CF20;
    case 0x8003CF24u: goto label_8003CF24;
    case 0x8003CF28u: goto label_8003CF28;
    case 0x8003CF2Cu: goto label_8003CF2C;
    case 0x8003CF30u: goto label_8003CF30;
    case 0x8003CF34u: goto label_8003CF34;
    case 0x8003CF38u: goto label_8003CF38;
    case 0x8003CF3Cu: goto label_8003CF3C;
    case 0x8003CF40u: goto label_8003CF40;
    case 0x8003CF44u: goto label_8003CF44;
    case 0x8003CF48u: goto label_8003CF48;
    case 0x8003CF4Cu: goto label_8003CF4C;
    case 0x8003CF50u: goto label_8003CF50;
    case 0x8003CF54u: goto label_8003CF54;
    case 0x8003CF58u: goto label_8003CF58;
    case 0x8003CF5Cu: goto label_8003CF5C;
    case 0x8003CF60u: goto label_8003CF60;
    case 0x8003CF64u: goto label_8003CF64;
    case 0x8003CF68u: goto label_8003CF68;
    case 0x8003CF6Cu: goto label_8003CF6C;
    case 0x8003CF70u: goto label_8003CF70;
    case 0x8003CF74u: goto label_8003CF74;
    case 0x8003CF78u: goto label_8003CF78;
    case 0x8003CF7Cu: goto label_8003CF7C;
    case 0x8003CF80u: goto label_8003CF80;
    case 0x8003CF84u: goto label_8003CF84;
    case 0x8003CF88u: goto label_8003CF88;
    case 0x8003CF8Cu: goto label_8003CF8C;
    case 0x8003CF90u: goto label_8003CF90;
    case 0x8003CF94u: goto label_8003CF94;
    case 0x8003CF98u: goto label_8003CF98;
    case 0x8003CF9Cu: goto label_8003CF9C;
    case 0x8003CFA0u: goto label_8003CFA0;
    case 0x8003CFA4u: goto label_8003CFA4;
    case 0x8003CFA8u: goto label_8003CFA8;
    case 0x8003CFACu: goto label_8003CFAC;
    case 0x8003CFB0u: goto label_8003CFB0;
    case 0x8003CFB4u: goto label_8003CFB4;
    case 0x8003CFB8u: goto label_8003CFB8;
    case 0x8003CFBCu: goto label_8003CFBC;
    case 0x8003CFC0u: goto label_8003CFC0;
    case 0x8003CFC4u: goto label_8003CFC4;
    case 0x8003CFC8u: goto label_8003CFC8;
    case 0x8003CFCCu: goto label_8003CFCC;
    case 0x8003CFD0u: goto label_8003CFD0;
    case 0x8003CFD4u: goto label_8003CFD4;
    case 0x8003CFD8u: goto label_8003CFD8;
    case 0x8003CFDCu: goto label_8003CFDC;
    case 0x8003CFE0u: goto label_8003CFE0;
    case 0x8003CFE4u: goto label_8003CFE4;
    case 0x8003CFE8u: goto label_8003CFE8;
    case 0x8003CFECu: goto label_8003CFEC;
    case 0x8003CFF0u: goto label_8003CFF0;
    case 0x8003CFF4u: goto label_8003CFF4;
    case 0x8003CFF8u: goto label_8003CFF8;
    case 0x8003CFFCu: goto label_8003CFFC;
    case 0x8003D000u: goto label_8003D000;
    case 0x8003D004u: goto label_8003D004;
    case 0x8003D008u: goto label_8003D008;
    case 0x8003D00Cu: goto label_8003D00C;
    case 0x8003D010u: goto label_8003D010;
    case 0x8003D014u: goto label_8003D014;
    case 0x8003D018u: goto label_8003D018;
    case 0x8003D01Cu: goto label_8003D01C;
    case 0x8003D020u: goto label_8003D020;
    case 0x8003D024u: goto label_8003D024;
    case 0x8003D028u: goto label_8003D028;
    case 0x8003D02Cu: goto label_8003D02C;
    case 0x8003D030u: goto label_8003D030;
    case 0x8003D034u: goto label_8003D034;
    case 0x8003D038u: goto label_8003D038;
    case 0x8003D03Cu: goto label_8003D03C;
    case 0x8003D040u: goto label_8003D040;
    case 0x8003D044u: goto label_8003D044;
    case 0x8003D048u: goto label_8003D048;
    case 0x8003D04Cu: goto label_8003D04C;
    case 0x8003D050u: goto label_8003D050;
    case 0x8003D054u: goto label_8003D054;
    case 0x8003D058u: goto label_8003D058;
    case 0x8003D05Cu: goto label_8003D05C;
    case 0x8003D060u: goto label_8003D060;
    case 0x8003D064u: goto label_8003D064;
    case 0x8003D068u: goto label_8003D068;
    case 0x8003D06Cu: goto label_8003D06C;
    case 0x8003D070u: goto label_8003D070;
    case 0x8003D074u: goto label_8003D074;
    case 0x8003D078u: goto label_8003D078;
    case 0x8003D07Cu: goto label_8003D07C;
    case 0x8003D080u: goto label_8003D080;
    case 0x8003D084u: goto label_8003D084;
    case 0x8003D088u: goto label_8003D088;
    case 0x8003D08Cu: goto label_8003D08C;
    case 0x8003D090u: goto label_8003D090;
    case 0x8003D094u: goto label_8003D094;
    case 0x8003D098u: goto label_8003D098;
    case 0x8003D09Cu: goto label_8003D09C;
    case 0x8003D0A0u: goto label_8003D0A0;
    case 0x8003D0A4u: goto label_8003D0A4;
    case 0x8003D0A8u: goto label_8003D0A8;
    case 0x8003D0ACu: goto label_8003D0AC;
    case 0x8003D0B0u: goto label_8003D0B0;
    case 0x8003D0B4u: goto label_8003D0B4;
    case 0x8003D0B8u: goto label_8003D0B8;
    case 0x8003D0BCu: goto label_8003D0BC;
    case 0x8003D0C0u: goto label_8003D0C0;
    case 0x8003D0C4u: goto label_8003D0C4;
    case 0x8003D0C8u: goto label_8003D0C8;
    case 0x8003D0CCu: goto label_8003D0CC;
    case 0x8003D0D0u: goto label_8003D0D0;
    case 0x8003D0D4u: goto label_8003D0D4;
    case 0x8003D0D8u: goto label_8003D0D8;
    case 0x8003D0DCu: goto label_8003D0DC;
    case 0x8003D0E0u: goto label_8003D0E0;
    case 0x8003D0E4u: goto label_8003D0E4;
    case 0x8003D0E8u: goto label_8003D0E8;
    case 0x8003D0ECu: goto label_8003D0EC;
    case 0x8003D0F0u: goto label_8003D0F0;
    case 0x8003D0F4u: goto label_8003D0F4;
    case 0x8003D0F8u: goto label_8003D0F8;
    case 0x8003D0FCu: goto label_8003D0FC;
    case 0x8003D100u: goto label_8003D100;
    case 0x8003D104u: goto label_8003D104;
    case 0x8003D108u: goto label_8003D108;
    case 0x8003D10Cu: goto label_8003D10C;
    case 0x8003D110u: goto label_8003D110;
    case 0x8003D114u: goto label_8003D114;
    case 0x8003D118u: goto label_8003D118;
    case 0x8003D11Cu: goto label_8003D11C;
    case 0x8003D120u: goto label_8003D120;
    case 0x8003D124u: goto label_8003D124;
    case 0x8003D128u: goto label_8003D128;
    case 0x8003D12Cu: goto label_8003D12C;
    case 0x8003D130u: goto label_8003D130;
    case 0x8003D134u: goto label_8003D134;
    case 0x8003D138u: goto label_8003D138;
    case 0x8003D13Cu: goto label_8003D13C;
    case 0x8003D140u: goto label_8003D140;
    case 0x8003D144u: goto label_8003D144;
    case 0x8003D148u: goto label_8003D148;
    case 0x8003D14Cu: goto label_8003D14C;
    case 0x8003D150u: goto label_8003D150;
    case 0x8003D154u: goto label_8003D154;
    case 0x8003D158u: goto label_8003D158;
    case 0x8003D15Cu: goto label_8003D15C;
    case 0x8003D160u: goto label_8003D160;
    case 0x8003D164u: goto label_8003D164;
    case 0x8003D168u: goto label_8003D168;
    case 0x8003D16Cu: goto label_8003D16C;
    case 0x8003D170u: goto label_8003D170;
    case 0x8003D174u: goto label_8003D174;
    case 0x8003D178u: goto label_8003D178;
    case 0x8003D17Cu: goto label_8003D17C;
    case 0x8003D180u: goto label_8003D180;
    case 0x8003D184u: goto label_8003D184;
    case 0x8003D188u: goto label_8003D188;
    case 0x8003D18Cu: goto label_8003D18C;
    case 0x8003D190u: goto label_8003D190;
    case 0x8003D194u: goto label_8003D194;
    case 0x8003D198u: goto label_8003D198;
    case 0x8003D19Cu: goto label_8003D19C;
    case 0x8003D1A0u: goto label_8003D1A0;
    case 0x8003D1A4u: goto label_8003D1A4;
    case 0x8003D1A8u: goto label_8003D1A8;
    case 0x8003D1ACu: goto label_8003D1AC;
    case 0x8003D1B0u: goto label_8003D1B0;
    case 0x8003D1B4u: goto label_8003D1B4;
    case 0x8003D1B8u: goto label_8003D1B8;
    case 0x8003D1BCu: goto label_8003D1BC;
    case 0x8003D1C0u: goto label_8003D1C0;
    case 0x8003D1C4u: goto label_8003D1C4;
    case 0x8003D1C8u: goto label_8003D1C8;
    case 0x8003D1CCu: goto label_8003D1CC;
    case 0x8003D1D0u: goto label_8003D1D0;
    case 0x8003D1D4u: goto label_8003D1D4;
    case 0x8003D1D8u: goto label_8003D1D8;
    case 0x8003D1DCu: goto label_8003D1DC;
    case 0x8003D1E0u: goto label_8003D1E0;
    case 0x8003D1E4u: goto label_8003D1E4;
    case 0x8003D1E8u: goto label_8003D1E8;
    case 0x8003D1ECu: goto label_8003D1EC;
    case 0x8003D1F0u: goto label_8003D1F0;
    case 0x8003D1F4u: goto label_8003D1F4;
    case 0x8003D1F8u: goto label_8003D1F8;
    case 0x8003D1FCu: goto label_8003D1FC;
    case 0x8003D200u: goto label_8003D200;
    case 0x8003D204u: goto label_8003D204;
    case 0x8003D208u: goto label_8003D208;
    case 0x8003D20Cu: goto label_8003D20C;
    case 0x8003D210u: goto label_8003D210;
    case 0x8003D214u: goto label_8003D214;
    case 0x8003D218u: goto label_8003D218;
    case 0x8003D21Cu: goto label_8003D21C;
    case 0x8003D220u: goto label_8003D220;
    case 0x8003D224u: goto label_8003D224;
    case 0x8003D228u: goto label_8003D228;
    case 0x8003D22Cu: goto label_8003D22C;
    case 0x8003D230u: goto label_8003D230;
    case 0x8003D234u: goto label_8003D234;
    case 0x8003D238u: goto label_8003D238;
    case 0x8003D23Cu: goto label_8003D23C;
    case 0x8003D240u: goto label_8003D240;
    case 0x8003D244u: goto label_8003D244;
    case 0x8003D248u: goto label_8003D248;
    case 0x8003D24Cu: goto label_8003D24C;
    case 0x8003D250u: goto label_8003D250;
    case 0x8003D254u: goto label_8003D254;
    case 0x8003D258u: goto label_8003D258;
    case 0x8003D25Cu: goto label_8003D25C;
    case 0x8003D260u: goto label_8003D260;
    case 0x8003D264u: goto label_8003D264;
    case 0x8003D268u: goto label_8003D268;
    case 0x8003D26Cu: goto label_8003D26C;
    case 0x8003D270u: goto label_8003D270;
    case 0x8003D274u: goto label_8003D274;
    case 0x8003D278u: goto label_8003D278;
    case 0x8003D27Cu: goto label_8003D27C;
    case 0x8003D280u: goto label_8003D280;
    case 0x8003D284u: goto label_8003D284;
    case 0x8003D288u: goto label_8003D288;
    case 0x8003D28Cu: goto label_8003D28C;
    case 0x8003D290u: goto label_8003D290;
    case 0x8003D294u: goto label_8003D294;
    case 0x8003D298u: goto label_8003D298;
    case 0x8003D29Cu: goto label_8003D29C;
    case 0x8003D2A0u: goto label_8003D2A0;
    case 0x8003D2A4u: goto label_8003D2A4;
    case 0x8003D2A8u: goto label_8003D2A8;
    case 0x8003D2ACu: goto label_8003D2AC;
    case 0x8003D2B0u: goto label_8003D2B0;
    case 0x8003D2B4u: goto label_8003D2B4;
    case 0x8003D2B8u: goto label_8003D2B8;
    case 0x8003D2BCu: goto label_8003D2BC;
    case 0x8003D2C0u: goto label_8003D2C0;
    case 0x8003D2C4u: goto label_8003D2C4;
    case 0x8003D2C8u: goto label_8003D2C8;
    case 0x8003D2CCu: goto label_8003D2CC;
    case 0x8003D2D0u: goto label_8003D2D0;
    case 0x8003D2D4u: goto label_8003D2D4;
    case 0x8003D2D8u: goto label_8003D2D8;
    case 0x8003D2DCu: goto label_8003D2DC;
    case 0x8003D2E0u: goto label_8003D2E0;
    case 0x8003D2E4u: goto label_8003D2E4;
    case 0x8003D2E8u: goto label_8003D2E8;
    case 0x8003D2ECu: goto label_8003D2EC;
    case 0x8003D2F0u: goto label_8003D2F0;
    case 0x8003D2F4u: goto label_8003D2F4;
    case 0x8003D2F8u: goto label_8003D2F8;
    case 0x8003D2FCu: goto label_8003D2FC;
    case 0x8003D300u: goto label_8003D300;
    case 0x8003D304u: goto label_8003D304;
    case 0x8003D308u: goto label_8003D308;
    case 0x8003D30Cu: goto label_8003D30C;
    case 0x8003D310u: goto label_8003D310;
    case 0x8003D314u: goto label_8003D314;
    case 0x8003D318u: goto label_8003D318;
    case 0x8003D31Cu: goto label_8003D31C;
    case 0x8003D320u: goto label_8003D320;
    case 0x8003D324u: goto label_8003D324;
    case 0x8003D328u: goto label_8003D328;
    case 0x8003D32Cu: goto label_8003D32C;
    case 0x8003D330u: goto label_8003D330;
    case 0x8003D334u: goto label_8003D334;
    case 0x8003D338u: goto label_8003D338;
    case 0x8003D33Cu: goto label_8003D33C;
    case 0x8003D340u: goto label_8003D340;
    case 0x8003D344u: goto label_8003D344;
    case 0x8003D348u: goto label_8003D348;
    case 0x8003D34Cu: goto label_8003D34C;
    case 0x8003D350u: goto label_8003D350;
    case 0x8003D354u: goto label_8003D354;
    case 0x8003D358u: goto label_8003D358;
    case 0x8003D35Cu: goto label_8003D35C;
    case 0x8003D360u: goto label_8003D360;
    case 0x8003D364u: goto label_8003D364;
    case 0x8003D368u: goto label_8003D368;
    case 0x8003D36Cu: goto label_8003D36C;
    case 0x8003D370u: goto label_8003D370;
    case 0x8003D374u: goto label_8003D374;
    case 0x8003D378u: goto label_8003D378;
    case 0x8003D37Cu: goto label_8003D37C;
    case 0x8003D380u: goto label_8003D380;
    case 0x8003D384u: goto label_8003D384;
    case 0x8003D388u: goto label_8003D388;
    case 0x8003D38Cu: goto label_8003D38C;
    case 0x8003D390u: goto label_8003D390;
    case 0x8003D394u: goto label_8003D394;
    case 0x8003D398u: goto label_8003D398;
    case 0x8003D39Cu: goto label_8003D39C;
    case 0x8003D3A0u: goto label_8003D3A0;
    case 0x8003D3A4u: goto label_8003D3A4;
    case 0x8003D3A8u: goto label_8003D3A8;
    case 0x8003D3ACu: goto label_8003D3AC;
    case 0x8003D3B0u: goto label_8003D3B0;
    case 0x8003D3B4u: goto label_8003D3B4;
    case 0x8003D3B8u: goto label_8003D3B8;
    case 0x8003D3BCu: goto label_8003D3BC;
    case 0x8003D3C0u: goto label_8003D3C0;
    case 0x8003D3C4u: goto label_8003D3C4;
    case 0x8003D3C8u: goto label_8003D3C8;
    case 0x8003D3CCu: goto label_8003D3CC;
    case 0x8003D3D0u: goto label_8003D3D0;
    case 0x8003D3D4u: goto label_8003D3D4;
    case 0x8003D3D8u: goto label_8003D3D8;
    case 0x8003D3DCu: goto label_8003D3DC;
    case 0x8003D3E0u: goto label_8003D3E0;
    case 0x8003D3E4u: goto label_8003D3E4;
    case 0x8003D3E8u: goto label_8003D3E8;
    case 0x8003D3ECu: goto label_8003D3EC;
    case 0x8003D3F0u: goto label_8003D3F0;
    case 0x8003D3F4u: goto label_8003D3F4;
    case 0x8003D3F8u: goto label_8003D3F8;
    case 0x8003D3FCu: goto label_8003D3FC;
    case 0x8003D400u: goto label_8003D400;
    case 0x8003D404u: goto label_8003D404;
    case 0x8003D408u: goto label_8003D408;
    case 0x8003D40Cu: goto label_8003D40C;
    case 0x8003D410u: goto label_8003D410;
    case 0x8003D414u: goto label_8003D414;
    case 0x8003D418u: goto label_8003D418;
    case 0x8003D41Cu: goto label_8003D41C;
    case 0x8003D420u: goto label_8003D420;
    case 0x8003D424u: goto label_8003D424;
    case 0x8003D428u: goto label_8003D428;
    case 0x8003D42Cu: goto label_8003D42C;
    case 0x8003D430u: goto label_8003D430;
    case 0x8003D434u: goto label_8003D434;
    case 0x8003D438u: goto label_8003D438;
    case 0x8003D43Cu: goto label_8003D43C;
    case 0x8003D440u: goto label_8003D440;
    case 0x8003D444u: goto label_8003D444;
    case 0x8003D448u: goto label_8003D448;
    case 0x8003D44Cu: goto label_8003D44C;
    case 0x8003D450u: goto label_8003D450;
    case 0x8003D454u: goto label_8003D454;
    case 0x8003D458u: goto label_8003D458;
    case 0x8003D45Cu: goto label_8003D45C;
    case 0x8003D460u: goto label_8003D460;
    case 0x8003D464u: goto label_8003D464;
    case 0x8003D468u: goto label_8003D468;
    case 0x8003D46Cu: goto label_8003D46C;
    case 0x8003D470u: goto label_8003D470;
    case 0x8003D474u: goto label_8003D474;
    case 0x8003D478u: goto label_8003D478;
    case 0x8003D47Cu: goto label_8003D47C;
    case 0x8003D480u: goto label_8003D480;
    case 0x8003D484u: goto label_8003D484;
    case 0x8003D488u: goto label_8003D488;
    case 0x8003D48Cu: goto label_8003D48C;
    case 0x8003D490u: goto label_8003D490;
    case 0x8003D494u: goto label_8003D494;
    case 0x8003D498u: goto label_8003D498;
    case 0x8003D49Cu: goto label_8003D49C;
    case 0x8003D4A0u: goto label_8003D4A0;
    case 0x8003D4A4u: goto label_8003D4A4;
    case 0x8003D4A8u: goto label_8003D4A8;
    case 0x8003D4ACu: goto label_8003D4AC;
    case 0x8003D4B0u: goto label_8003D4B0;
    case 0x8003D4B4u: goto label_8003D4B4;
    case 0x8003D4B8u: goto label_8003D4B8;
    case 0x8003D4BCu: goto label_8003D4BC;
    case 0x8003D4C0u: goto label_8003D4C0;
    case 0x8003D4C4u: goto label_8003D4C4;
    case 0x8003D4C8u: goto label_8003D4C8;
    case 0x8003D4CCu: goto label_8003D4CC;
    case 0x8003D4D0u: goto label_8003D4D0;
    case 0x8003D4D4u: goto label_8003D4D4;
    case 0x8003D4D8u: goto label_8003D4D8;
    case 0x8003D4DCu: goto label_8003D4DC;
    case 0x8003D4E0u: goto label_8003D4E0;
    case 0x8003D4E4u: goto label_8003D4E4;
    case 0x8003D4E8u: goto label_8003D4E8;
    case 0x8003D4ECu: goto label_8003D4EC;
    case 0x8003D4F0u: goto label_8003D4F0;
    case 0x8003D4F4u: goto label_8003D4F4;
    case 0x8003D4F8u: goto label_8003D4F8;
    case 0x8003D4FCu: goto label_8003D4FC;
    case 0x8003D500u: goto label_8003D500;
    case 0x8003D504u: goto label_8003D504;
    case 0x8003D508u: goto label_8003D508;
    case 0x8003D50Cu: goto label_8003D50C;
    case 0x8003D510u: goto label_8003D510;
    case 0x8003D514u: goto label_8003D514;
    case 0x8003D518u: goto label_8003D518;
    case 0x8003D51Cu: goto label_8003D51C;
    case 0x8003D520u: goto label_8003D520;
    case 0x8003D524u: goto label_8003D524;
    case 0x8003D528u: goto label_8003D528;
    case 0x8003D52Cu: goto label_8003D52C;
    case 0x8003D530u: goto label_8003D530;
    case 0x8003D534u: goto label_8003D534;
    case 0x8003D538u: goto label_8003D538;
    case 0x8003D53Cu: goto label_8003D53C;
    case 0x8003D540u: goto label_8003D540;
    case 0x8003D544u: goto label_8003D544;
    case 0x8003D548u: goto label_8003D548;
    case 0x8003D54Cu: goto label_8003D54C;
    case 0x8003D550u: goto label_8003D550;
    case 0x8003D554u: goto label_8003D554;
    case 0x8003D558u: goto label_8003D558;
    case 0x8003D55Cu: goto label_8003D55C;
    case 0x8003D560u: goto label_8003D560;
    case 0x8003D564u: goto label_8003D564;
    case 0x8003D568u: goto label_8003D568;
    case 0x8003D56Cu: goto label_8003D56C;
    case 0x8003D570u: goto label_8003D570;
    case 0x8003D574u: goto label_8003D574;
    case 0x8003D578u: goto label_8003D578;
    case 0x8003D57Cu: goto label_8003D57C;
    case 0x8003D580u: goto label_8003D580;
    case 0x8003D584u: goto label_8003D584;
    case 0x8003D588u: goto label_8003D588;
    case 0x8003D58Cu: goto label_8003D58C;
    case 0x8003D590u: goto label_8003D590;
    case 0x8003D594u: goto label_8003D594;
    case 0x8003D598u: goto label_8003D598;
    case 0x8003D59Cu: goto label_8003D59C;
    case 0x8003D5A0u: goto label_8003D5A0;
    case 0x8003D5A4u: goto label_8003D5A4;
    case 0x8003D5A8u: goto label_8003D5A8;
    case 0x8003D5ACu: goto label_8003D5AC;
    case 0x8003D5B0u: goto label_8003D5B0;
    case 0x8003D5B4u: goto label_8003D5B4;
    case 0x8003D5B8u: goto label_8003D5B8;
    case 0x8003D5BCu: goto label_8003D5BC;
    case 0x8003D5C0u: goto label_8003D5C0;
    case 0x8003D5C4u: goto label_8003D5C4;
    case 0x8003D5C8u: goto label_8003D5C8;
    case 0x8003D5CCu: goto label_8003D5CC;
    case 0x8003D5D0u: goto label_8003D5D0;
    case 0x8003D5D4u: goto label_8003D5D4;
    case 0x8003D5D8u: goto label_8003D5D8;
    case 0x8003D5DCu: goto label_8003D5DC;
    case 0x8003D5E0u: goto label_8003D5E0;
    case 0x8003D5E4u: goto label_8003D5E4;
    case 0x8003D5E8u: goto label_8003D5E8;
    case 0x8003D5ECu: goto label_8003D5EC;
    case 0x8003D5F0u: goto label_8003D5F0;
    case 0x8003D5F4u: goto label_8003D5F4;
    case 0x8003D5F8u: goto label_8003D5F8;
    case 0x8003D5FCu: goto label_8003D5FC;
    case 0x8003D600u: goto label_8003D600;
    case 0x8003D604u: goto label_8003D604;
    case 0x8003D608u: goto label_8003D608;
    case 0x8003D60Cu: goto label_8003D60C;
    case 0x8003D610u: goto label_8003D610;
    case 0x8003D614u: goto label_8003D614;
    case 0x8003D618u: goto label_8003D618;
    case 0x8003D61Cu: goto label_8003D61C;
    case 0x8003D620u: goto label_8003D620;
    case 0x8003D624u: goto label_8003D624;
    case 0x8003D628u: goto label_8003D628;
    case 0x8003D62Cu: goto label_8003D62C;
    case 0x8003D630u: goto label_8003D630;
    case 0x8003D634u: goto label_8003D634;
    case 0x8003D638u: goto label_8003D638;
    case 0x8003D63Cu: goto label_8003D63C;
    case 0x8003D640u: goto label_8003D640;
    case 0x8003D644u: goto label_8003D644;
    case 0x8003D648u: goto label_8003D648;
    case 0x8003D64Cu: goto label_8003D64C;
    case 0x8003D650u: goto label_8003D650;
    case 0x8003D654u: goto label_8003D654;
    case 0x8003D658u: goto label_8003D658;
    case 0x8003D65Cu: goto label_8003D65C;
    case 0x8003D660u: goto label_8003D660;
    case 0x8003D664u: goto label_8003D664;
    case 0x8003D668u: goto label_8003D668;
    case 0x8003D66Cu: goto label_8003D66C;
    case 0x8003D670u: goto label_8003D670;
    case 0x8003D674u: goto label_8003D674;
    case 0x8003D678u: goto label_8003D678;
    case 0x8003D67Cu: goto label_8003D67C;
    case 0x8003D680u: goto label_8003D680;
    case 0x8003D684u: goto label_8003D684;
    case 0x8003D688u: goto label_8003D688;
    case 0x8003D68Cu: goto label_8003D68C;
    case 0x8003D690u: goto label_8003D690;
    case 0x8003D694u: goto label_8003D694;
    case 0x8003D698u: goto label_8003D698;
    case 0x8003D69Cu: goto label_8003D69C;
    case 0x8003D6A0u: goto label_8003D6A0;
    case 0x8003D6A4u: goto label_8003D6A4;
    case 0x8003D6A8u: goto label_8003D6A8;
    case 0x8003D6ACu: goto label_8003D6AC;
    case 0x8003D6B0u: goto label_8003D6B0;
    case 0x8003D6B4u: goto label_8003D6B4;
    case 0x8003D6B8u: goto label_8003D6B8;
    case 0x8003D6BCu: goto label_8003D6BC;
    case 0x8003D6C0u: goto label_8003D6C0;
    case 0x8003D6C4u: goto label_8003D6C4;
    case 0x8003D6C8u: goto label_8003D6C8;
    case 0x8003D6CCu: goto label_8003D6CC;
    case 0x8003D6D0u: goto label_8003D6D0;
    case 0x8003D6D4u: goto label_8003D6D4;
    case 0x8003D6D8u: goto label_8003D6D8;
    case 0x8003D6DCu: goto label_8003D6DC;
    case 0x8003D6E0u: goto label_8003D6E0;
    case 0x8003D6E4u: goto label_8003D6E4;
    case 0x8003D6E8u: goto label_8003D6E8;
    case 0x8003D6ECu: goto label_8003D6EC;
    case 0x8003D6F0u: goto label_8003D6F0;
    case 0x8003D6F4u: goto label_8003D6F4;
    case 0x8003D6F8u: goto label_8003D6F8;
    case 0x8003D6FCu: goto label_8003D6FC;
    case 0x8003D700u: goto label_8003D700;
    case 0x8003D704u: goto label_8003D704;
    case 0x8003D708u: goto label_8003D708;
    case 0x8003D70Cu: goto label_8003D70C;
    case 0x8003D710u: goto label_8003D710;
    case 0x8003D714u: goto label_8003D714;
    case 0x8003D718u: goto label_8003D718;
    case 0x8003D71Cu: goto label_8003D71C;
    case 0x8003D720u: goto label_8003D720;
    case 0x8003D724u: goto label_8003D724;
    case 0x8003D728u: goto label_8003D728;
    case 0x8003D72Cu: goto label_8003D72C;
    case 0x8003D730u: goto label_8003D730;
    case 0x8003D734u: goto label_8003D734;
    case 0x8003D738u: goto label_8003D738;
    case 0x8003D73Cu: goto label_8003D73C;
    case 0x8003D740u: goto label_8003D740;
    case 0x8003D744u: goto label_8003D744;
    case 0x8003D748u: goto label_8003D748;
    case 0x8003D74Cu: goto label_8003D74C;
    case 0x8003D750u: goto label_8003D750;
    case 0x8003D754u: goto label_8003D754;
    case 0x8003D758u: goto label_8003D758;
    case 0x8003D75Cu: goto label_8003D75C;
    case 0x8003D760u: goto label_8003D760;
    case 0x8003D764u: goto label_8003D764;
    case 0x8003D768u: goto label_8003D768;
    case 0x8003D76Cu: goto label_8003D76C;
    case 0x8003D770u: goto label_8003D770;
    case 0x8003D774u: goto label_8003D774;
    case 0x8003D778u: goto label_8003D778;
    case 0x8003D77Cu: goto label_8003D77C;
    case 0x8003D780u: goto label_8003D780;
    case 0x8003D784u: goto label_8003D784;
    case 0x8003D788u: goto label_8003D788;
    case 0x8003D78Cu: goto label_8003D78C;
    case 0x8003D790u: goto label_8003D790;
    case 0x8003D794u: goto label_8003D794;
    case 0x8003D798u: goto label_8003D798;
    case 0x8003D79Cu: goto label_8003D79C;
    case 0x8003D7A0u: goto label_8003D7A0;
    case 0x8003D7A4u: goto label_8003D7A4;
    case 0x8003D7A8u: goto label_8003D7A8;
    case 0x8003D7ACu: goto label_8003D7AC;
    case 0x8003D7B0u: goto label_8003D7B0;
    case 0x8003D7B4u: goto label_8003D7B4;
    case 0x8003D7B8u: goto label_8003D7B8;
    case 0x8003D7BCu: goto label_8003D7BC;
    case 0x8003D7C0u: goto label_8003D7C0;
    case 0x8003D7C4u: goto label_8003D7C4;
    case 0x8003D7C8u: goto label_8003D7C8;
    case 0x8003D7CCu: goto label_8003D7CC;
    case 0x8003D7D0u: goto label_8003D7D0;
    case 0x8003D7D4u: goto label_8003D7D4;
    case 0x8003D7D8u: goto label_8003D7D8;
    case 0x8003D7DCu: goto label_8003D7DC;
    case 0x8003D7E0u: goto label_8003D7E0;
    case 0x8003D7E4u: goto label_8003D7E4;
    case 0x8003D7E8u: goto label_8003D7E8;
    case 0x8003D7ECu: goto label_8003D7EC;
    case 0x8003D7F0u: goto label_8003D7F0;
    case 0x8003D7F4u: goto label_8003D7F4;
    case 0x8003D7F8u: goto label_8003D7F8;
    case 0x8003D7FCu: goto label_8003D7FC;
    case 0x8003D800u: goto label_8003D800;
    case 0x8003D804u: goto label_8003D804;
    case 0x8003D808u: goto label_8003D808;
    case 0x8003D80Cu: goto label_8003D80C;
    case 0x8003D810u: goto label_8003D810;
    case 0x8003D814u: goto label_8003D814;
    case 0x8003D818u: goto label_8003D818;
    case 0x8003D81Cu: goto label_8003D81C;
    case 0x8003D820u: goto label_8003D820;
    case 0x8003D824u: goto label_8003D824;
    case 0x8003D828u: goto label_8003D828;
    case 0x8003D82Cu: goto label_8003D82C;
    case 0x8003D830u: goto label_8003D830;
    case 0x8003D834u: goto label_8003D834;
    case 0x8003D838u: goto label_8003D838;
    case 0x8003D83Cu: goto label_8003D83C;
    case 0x8003D840u: goto label_8003D840;
    case 0x8003D844u: goto label_8003D844;
    case 0x8003D848u: goto label_8003D848;
    case 0x8003D84Cu: goto label_8003D84C;
    case 0x8003D850u: goto label_8003D850;
    case 0x8003D854u: goto label_8003D854;
    case 0x8003D858u: goto label_8003D858;
    case 0x8003D85Cu: goto label_8003D85C;
    case 0x8003D860u: goto label_8003D860;
    case 0x8003D864u: goto label_8003D864;
    case 0x8003D868u: goto label_8003D868;
    case 0x8003D86Cu: goto label_8003D86C;
    case 0x8003D870u: goto label_8003D870;
    case 0x8003D874u: goto label_8003D874;
    case 0x8003D878u: goto label_8003D878;
    case 0x8003D87Cu: goto label_8003D87C;
    case 0x8003D880u: goto label_8003D880;
    case 0x8003D884u: goto label_8003D884;
    case 0x8003D888u: goto label_8003D888;
    case 0x8003D88Cu: goto label_8003D88C;
    case 0x8003D890u: goto label_8003D890;
    case 0x8003D894u: goto label_8003D894;
    case 0x8003D898u: goto label_8003D898;
    case 0x8003D89Cu: goto label_8003D89C;
    case 0x8003D8A0u: goto label_8003D8A0;
    case 0x8003D8A4u: goto label_8003D8A4;
    case 0x8003D8A8u: goto label_8003D8A8;
    case 0x8003D8ACu: goto label_8003D8AC;
    case 0x8003D8B0u: goto label_8003D8B0;
    case 0x8003D8B4u: goto label_8003D8B4;
    case 0x8003D8B8u: goto label_8003D8B8;
    case 0x8003D8BCu: goto label_8003D8BC;
    case 0x8003D8C0u: goto label_8003D8C0;
    case 0x8003D8C4u: goto label_8003D8C4;
    case 0x8003D8C8u: goto label_8003D8C8;
    case 0x8003D8CCu: goto label_8003D8CC;
    case 0x8003D8D0u: goto label_8003D8D0;
    case 0x8003D8D4u: goto label_8003D8D4;
    case 0x8003D8D8u: goto label_8003D8D8;
    case 0x8003D8DCu: goto label_8003D8DC;
    case 0x8003D8E0u: goto label_8003D8E0;
    case 0x8003D8E4u: goto label_8003D8E4;
    case 0x8003D8E8u: goto label_8003D8E8;
    case 0x8003D8ECu: goto label_8003D8EC;
    case 0x8003D8F0u: goto label_8003D8F0;
    case 0x8003D8F4u: goto label_8003D8F4;
    case 0x8003D8F8u: goto label_8003D8F8;
    case 0x8003D8FCu: goto label_8003D8FC;
    case 0x8003D900u: goto label_8003D900;
    case 0x8003D904u: goto label_8003D904;
    case 0x8003D908u: goto label_8003D908;
    case 0x8003D90Cu: goto label_8003D90C;
    case 0x8003D910u: goto label_8003D910;
    case 0x8003D914u: goto label_8003D914;
    case 0x8003D918u: goto label_8003D918;
    case 0x8003D91Cu: goto label_8003D91C;
    case 0x8003D920u: goto label_8003D920;
    case 0x8003D924u: goto label_8003D924;
    case 0x8003D928u: goto label_8003D928;
    case 0x8003D92Cu: goto label_8003D92C;
    case 0x8003D930u: goto label_8003D930;
    case 0x8003D934u: goto label_8003D934;
    case 0x8003D938u: goto label_8003D938;
    case 0x8003D93Cu: goto label_8003D93C;
    case 0x8003D940u: goto label_8003D940;
    case 0x8003D944u: goto label_8003D944;
    case 0x8003D948u: goto label_8003D948;
    case 0x8003D94Cu: goto label_8003D94C;
    case 0x8003D950u: goto label_8003D950;
    case 0x8003D954u: goto label_8003D954;
    case 0x8003D958u: goto label_8003D958;
    case 0x8003D95Cu: goto label_8003D95C;
    case 0x8003D960u: goto label_8003D960;
    case 0x8003D964u: goto label_8003D964;
    case 0x8003D968u: goto label_8003D968;
    case 0x8003D96Cu: goto label_8003D96C;
    case 0x8003D970u: goto label_8003D970;
    case 0x8003D974u: goto label_8003D974;
    case 0x8003D978u: goto label_8003D978;
    case 0x8003D97Cu: goto label_8003D97C;
    case 0x8003D980u: goto label_8003D980;
    case 0x8003D984u: goto label_8003D984;
    case 0x8003D988u: goto label_8003D988;
    case 0x8003D98Cu: goto label_8003D98C;
    case 0x8003D990u: goto label_8003D990;
    case 0x8003D994u: goto label_8003D994;
    case 0x8003D998u: goto label_8003D998;
    case 0x8003D99Cu: goto label_8003D99C;
    case 0x8003D9A0u: goto label_8003D9A0;
    case 0x8003D9A4u: goto label_8003D9A4;
    case 0x8003D9A8u: goto label_8003D9A8;
    case 0x8003D9ACu: goto label_8003D9AC;
    case 0x8003D9B0u: goto label_8003D9B0;
    case 0x8003D9B4u: goto label_8003D9B4;
    case 0x8003D9B8u: goto label_8003D9B8;
    case 0x8003D9BCu: goto label_8003D9BC;
    case 0x8003D9C0u: goto label_8003D9C0;
    case 0x8003D9C4u: goto label_8003D9C4;
    case 0x8003D9C8u: goto label_8003D9C8;
    case 0x8003D9CCu: goto label_8003D9CC;
    case 0x8003D9D0u: goto label_8003D9D0;
    case 0x8003D9D4u: goto label_8003D9D4;
    case 0x8003D9D8u: goto label_8003D9D8;
    case 0x8003D9DCu: goto label_8003D9DC;
    case 0x8003D9E0u: goto label_8003D9E0;
    case 0x8003D9E4u: goto label_8003D9E4;
    case 0x8003D9E8u: goto label_8003D9E8;
    case 0x8003D9ECu: goto label_8003D9EC;
    case 0x8003D9F0u: goto label_8003D9F0;
    case 0x8003D9F4u: goto label_8003D9F4;
    case 0x8003D9F8u: goto label_8003D9F8;
    case 0x8003D9FCu: goto label_8003D9FC;
    case 0x8003DA00u: goto label_8003DA00;
    case 0x8003DA04u: goto label_8003DA04;
    case 0x8003DA08u: goto label_8003DA08;
    case 0x8003DA0Cu: goto label_8003DA0C;
    case 0x8003DA10u: goto label_8003DA10;
    case 0x8003DA14u: goto label_8003DA14;
    case 0x8003DA18u: goto label_8003DA18;
    case 0x8003DA1Cu: goto label_8003DA1C;
    case 0x8003DA20u: goto label_8003DA20;
    case 0x8003DA24u: goto label_8003DA24;
    case 0x8003DA28u: goto label_8003DA28;
    case 0x8003DA2Cu: goto label_8003DA2C;
    case 0x8003DA30u: goto label_8003DA30;
    case 0x8003DA34u: goto label_8003DA34;
    case 0x8003DA38u: goto label_8003DA38;
    case 0x8003DA3Cu: goto label_8003DA3C;
    case 0x8003DA40u: goto label_8003DA40;
    case 0x8003DA44u: goto label_8003DA44;
    case 0x8003DA48u: goto label_8003DA48;
    case 0x8003DA4Cu: goto label_8003DA4C;
    case 0x8003DA50u: goto label_8003DA50;
    case 0x8003DA54u: goto label_8003DA54;
    case 0x8003DA58u: goto label_8003DA58;
    case 0x8003DA5Cu: goto label_8003DA5C;
    case 0x8003DA60u: goto label_8003DA60;
    case 0x8003DA64u: goto label_8003DA64;
    case 0x8003DA68u: goto label_8003DA68;
    case 0x8003DA6Cu: goto label_8003DA6C;
    case 0x8003DA70u: goto label_8003DA70;
    case 0x8003DA74u: goto label_8003DA74;
    case 0x8003DA78u: goto label_8003DA78;
    case 0x8003DA7Cu: goto label_8003DA7C;
    case 0x8003DA80u: goto label_8003DA80;
    case 0x8003DA84u: goto label_8003DA84;
    case 0x8003DA88u: goto label_8003DA88;
    case 0x8003DA8Cu: goto label_8003DA8C;
    case 0x8003DA90u: goto label_8003DA90;
    case 0x8003DA94u: goto label_8003DA94;
    case 0x8003DA98u: goto label_8003DA98;
    case 0x8003DA9Cu: goto label_8003DA9C;
    case 0x8003DAA0u: goto label_8003DAA0;
    case 0x8003DAA4u: goto label_8003DAA4;
    case 0x8003DAA8u: goto label_8003DAA8;
    case 0x8003DAACu: goto label_8003DAAC;
    case 0x8003DAB0u: goto label_8003DAB0;
    case 0x8003DAB4u: goto label_8003DAB4;
    case 0x8003DAB8u: goto label_8003DAB8;
    case 0x8003DABCu: goto label_8003DABC;
    case 0x8003DAC0u: goto label_8003DAC0;
    case 0x8003DAC4u: goto label_8003DAC4;
    case 0x8003DAC8u: goto label_8003DAC8;
    case 0x8003DACCu: goto label_8003DACC;
    case 0x8003DAD0u: goto label_8003DAD0;
    case 0x8003DAD4u: goto label_8003DAD4;
    case 0x8003DAD8u: goto label_8003DAD8;
    case 0x8003DADCu: goto label_8003DADC;
    case 0x8003DAE0u: goto label_8003DAE0;
    case 0x8003DAE4u: goto label_8003DAE4;
    case 0x8003DAE8u: goto label_8003DAE8;
    case 0x8003DAECu: goto label_8003DAEC;
    case 0x8003DAF0u: goto label_8003DAF0;
    case 0x8003DAF4u: goto label_8003DAF4;
    case 0x8003DAF8u: goto label_8003DAF8;
    case 0x8003DAFCu: goto label_8003DAFC;
    case 0x8003DB00u: goto label_8003DB00;
    case 0x8003DB04u: goto label_8003DB04;
    case 0x8003DB08u: goto label_8003DB08;
    case 0x8003DB0Cu: goto label_8003DB0C;
    case 0x8003DB10u: goto label_8003DB10;
    case 0x8003DB14u: goto label_8003DB14;
    case 0x8003DB18u: goto label_8003DB18;
    case 0x8003DB1Cu: goto label_8003DB1C;
    case 0x8003DB20u: goto label_8003DB20;
    case 0x8003DB24u: goto label_8003DB24;
    case 0x8003DB28u: goto label_8003DB28;
    case 0x8003DB2Cu: goto label_8003DB2C;
    case 0x8003DB30u: goto label_8003DB30;
    case 0x8003DB34u: goto label_8003DB34;
    case 0x8003DB38u: goto label_8003DB38;
    case 0x8003DB3Cu: goto label_8003DB3C;
    case 0x8003DB40u: goto label_8003DB40;
    case 0x8003DB44u: goto label_8003DB44;
    case 0x8003DB48u: goto label_8003DB48;
    case 0x8003DB4Cu: goto label_8003DB4C;
    case 0x8003DB50u: goto label_8003DB50;
    case 0x8003DB54u: goto label_8003DB54;
    case 0x8003DB58u: goto label_8003DB58;
    case 0x8003DB5Cu: goto label_8003DB5C;
    case 0x8003DB60u: goto label_8003DB60;
    case 0x8003DB64u: goto label_8003DB64;
    case 0x8003DB68u: goto label_8003DB68;
    case 0x8003DB6Cu: goto label_8003DB6C;
    case 0x8003DB70u: goto label_8003DB70;
    case 0x8003DB74u: goto label_8003DB74;
    case 0x8003DB78u: goto label_8003DB78;
    case 0x8003DB7Cu: goto label_8003DB7C;
    case 0x8003DB80u: goto label_8003DB80;
    case 0x8003DB84u: goto label_8003DB84;
    case 0x8003DB88u: goto label_8003DB88;
    case 0x8003DB8Cu: goto label_8003DB8C;
    case 0x8003DB90u: goto label_8003DB90;
    case 0x8003DB94u: goto label_8003DB94;
    case 0x8003DB98u: goto label_8003DB98;
    case 0x8003DB9Cu: goto label_8003DB9C;
    case 0x8003DBA0u: goto label_8003DBA0;
    case 0x8003DBA4u: goto label_8003DBA4;
    case 0x8003DBA8u: goto label_8003DBA8;
    case 0x8003DBACu: goto label_8003DBAC;
    case 0x8003DBB0u: goto label_8003DBB0;
    case 0x8003DBB4u: goto label_8003DBB4;
    case 0x8003DBB8u: goto label_8003DBB8;
    case 0x8003DBBCu: goto label_8003DBBC;
    case 0x8003DBC0u: goto label_8003DBC0;
    case 0x8003DBC4u: goto label_8003DBC4;
    case 0x8003DBC8u: goto label_8003DBC8;
    case 0x8003DBCCu: goto label_8003DBCC;
    case 0x8003DBD0u: goto label_8003DBD0;
    case 0x8003DBD4u: goto label_8003DBD4;
    case 0x8003DBD8u: goto label_8003DBD8;
    case 0x8003DBDCu: goto label_8003DBDC;
    case 0x8003DBE0u: goto label_8003DBE0;
    case 0x8003DBE4u: goto label_8003DBE4;
    case 0x8003DBE8u: goto label_8003DBE8;
    case 0x8003DBECu: goto label_8003DBEC;
    case 0x8003DBF0u: goto label_8003DBF0;
    case 0x8003DBF4u: goto label_8003DBF4;
    case 0x8003DBF8u: goto label_8003DBF8;
    case 0x8003DBFCu: goto label_8003DBFC;
    case 0x8003DC00u: goto label_8003DC00;
    case 0x8003DC04u: goto label_8003DC04;
    case 0x8003DC08u: goto label_8003DC08;
    case 0x8003DC0Cu: goto label_8003DC0C;
    case 0x8003DC10u: goto label_8003DC10;
    case 0x8003DC14u: goto label_8003DC14;
    case 0x8003DC18u: goto label_8003DC18;
    case 0x8003DC1Cu: goto label_8003DC1C;
    case 0x8003DC20u: goto label_8003DC20;
    case 0x8003DC24u: goto label_8003DC24;
    case 0x8003DC28u: goto label_8003DC28;
    case 0x8003DC2Cu: goto label_8003DC2C;
    case 0x8003DC30u: goto label_8003DC30;
    case 0x8003DC34u: goto label_8003DC34;
    case 0x8003DC38u: goto label_8003DC38;
    case 0x8003DC3Cu: goto label_8003DC3C;
    case 0x8003DC40u: goto label_8003DC40;
    case 0x8003DC44u: goto label_8003DC44;
    case 0x8003DC48u: goto label_8003DC48;
    case 0x8003DC4Cu: goto label_8003DC4C;
    case 0x8003DC50u: goto label_8003DC50;
    case 0x8003DC54u: goto label_8003DC54;
    case 0x8003DC58u: goto label_8003DC58;
    case 0x8003DC5Cu: goto label_8003DC5C;
    case 0x8003DC60u: goto label_8003DC60;
    case 0x8003DC64u: goto label_8003DC64;
    case 0x8003DC68u: goto label_8003DC68;
    case 0x8003DC6Cu: goto label_8003DC6C;
    case 0x8003DC70u: goto label_8003DC70;
    case 0x8003DC74u: goto label_8003DC74;
    case 0x8003DC78u: goto label_8003DC78;
    case 0x8003DC7Cu: goto label_8003DC7C;
    case 0x8003DC80u: goto label_8003DC80;
    case 0x8003DC84u: goto label_8003DC84;
    case 0x8003DC88u: goto label_8003DC88;
    case 0x8003DC8Cu: goto label_8003DC8C;
    case 0x8003DC90u: goto label_8003DC90;
    case 0x8003DC94u: goto label_8003DC94;
    case 0x8003DC98u: goto label_8003DC98;
    case 0x8003DC9Cu: goto label_8003DC9C;
    case 0x8003DCA0u: goto label_8003DCA0;
    case 0x8003DCA4u: goto label_8003DCA4;
    case 0x8003DCA8u: goto label_8003DCA8;
    case 0x8003DCACu: goto label_8003DCAC;
    case 0x8003DCB0u: goto label_8003DCB0;
    case 0x8003DCB4u: goto label_8003DCB4;
    case 0x8003DCB8u: goto label_8003DCB8;
    case 0x8003DCBCu: goto label_8003DCBC;
    case 0x8003DCC0u: goto label_8003DCC0;
    case 0x8003DCC4u: goto label_8003DCC4;
    case 0x8003DCC8u: goto label_8003DCC8;
    case 0x8003DCCCu: goto label_8003DCCC;
    case 0x8003DCD0u: goto label_8003DCD0;
    case 0x8003DCD4u: goto label_8003DCD4;
    case 0x8003DCD8u: goto label_8003DCD8;
    case 0x8003DCDCu: goto label_8003DCDC;
    case 0x8003DCE0u: goto label_8003DCE0;
    case 0x8003DCE4u: goto label_8003DCE4;
    case 0x8003DCE8u: goto label_8003DCE8;
    case 0x8003DCECu: goto label_8003DCEC;
    case 0x8003DCF0u: goto label_8003DCF0;
    case 0x8003DCF4u: goto label_8003DCF4;
    case 0x8003DCF8u: goto label_8003DCF8;
    case 0x8003DCFCu: goto label_8003DCFC;
    case 0x8003DD00u: goto label_8003DD00;
    case 0x8003DD04u: goto label_8003DD04;
    case 0x8003DD08u: goto label_8003DD08;
    case 0x8003DD0Cu: goto label_8003DD0C;
    case 0x8003DD10u: goto label_8003DD10;
    case 0x8003DD14u: goto label_8003DD14;
    case 0x8003DD18u: goto label_8003DD18;
    case 0x8003DD1Cu: goto label_8003DD1C;
    case 0x8003DD20u: goto label_8003DD20;
    case 0x8003DD24u: goto label_8003DD24;
    case 0x8003DD28u: goto label_8003DD28;
    case 0x8003DD2Cu: goto label_8003DD2C;
    case 0x8003DD30u: goto label_8003DD30;
    case 0x8003DD34u: goto label_8003DD34;
    case 0x8003DD38u: goto label_8003DD38;
    case 0x8003DD3Cu: goto label_8003DD3C;
    case 0x8003DD40u: goto label_8003DD40;
    case 0x8003DD44u: goto label_8003DD44;
    case 0x8003DD48u: goto label_8003DD48;
    case 0x8003DD4Cu: goto label_8003DD4C;
    case 0x8003DD50u: goto label_8003DD50;
    case 0x8003DD54u: goto label_8003DD54;
    case 0x8003DD58u: goto label_8003DD58;
    case 0x8003DD5Cu: goto label_8003DD5C;
    case 0x8003DD60u: goto label_8003DD60;
    case 0x8003DD64u: goto label_8003DD64;
    case 0x8003DD68u: goto label_8003DD68;
    case 0x8003DD6Cu: goto label_8003DD6C;
    case 0x8003DD70u: goto label_8003DD70;
    case 0x8003DD74u: goto label_8003DD74;
    case 0x8003DD78u: goto label_8003DD78;
    case 0x8003DD7Cu: goto label_8003DD7C;
    case 0x8003DD80u: goto label_8003DD80;
    case 0x8003DD84u: goto label_8003DD84;
    case 0x8003DD88u: goto label_8003DD88;
    case 0x8003DD8Cu: goto label_8003DD8C;
    case 0x8003DD90u: goto label_8003DD90;
    case 0x8003DD94u: goto label_8003DD94;
    case 0x8003DD98u: goto label_8003DD98;
    case 0x8003DD9Cu: goto label_8003DD9C;
    case 0x8003DDA0u: goto label_8003DDA0;
    case 0x8003DDA4u: goto label_8003DDA4;
    case 0x8003DDA8u: goto label_8003DDA8;
    case 0x8003DDACu: goto label_8003DDAC;
    case 0x8003DDB0u: goto label_8003DDB0;
    case 0x8003DDB4u: goto label_8003DDB4;
    case 0x8003DDB8u: goto label_8003DDB8;
    case 0x8003DDBCu: goto label_8003DDBC;
    case 0x8003DDC0u: goto label_8003DDC0;
    case 0x8003DDC4u: goto label_8003DDC4;
    case 0x8003DDC8u: goto label_8003DDC8;
    case 0x8003DDCCu: goto label_8003DDCC;
    case 0x8003DDD0u: goto label_8003DDD0;
    case 0x8003DDD4u: goto label_8003DDD4;
    case 0x8003DDD8u: goto label_8003DDD8;
    case 0x8003DDDCu: goto label_8003DDDC;
    case 0x8003DDE0u: goto label_8003DDE0;
    case 0x8003DDE4u: goto label_8003DDE4;
    case 0x8003DDE8u: goto label_8003DDE8;
    case 0x8003DDECu: goto label_8003DDEC;
    case 0x8003DDF0u: goto label_8003DDF0;
    case 0x8003DDF4u: goto label_8003DDF4;
    case 0x8003DDF8u: goto label_8003DDF8;
    case 0x8003DDFCu: goto label_8003DDFC;
    case 0x8003DE00u: goto label_8003DE00;
    case 0x8003DE04u: goto label_8003DE04;
    case 0x8003DE08u: goto label_8003DE08;
    case 0x8003DE0Cu: goto label_8003DE0C;
    case 0x8003DE10u: goto label_8003DE10;
    case 0x8003DE14u: goto label_8003DE14;
    case 0x8003DE18u: goto label_8003DE18;
    case 0x8003DE1Cu: goto label_8003DE1C;
    case 0x8003DE20u: goto label_8003DE20;
    case 0x8003DE24u: goto label_8003DE24;
    case 0x8003DE28u: goto label_8003DE28;
    case 0x8003DE2Cu: goto label_8003DE2C;
    case 0x8003DE30u: goto label_8003DE30;
    case 0x8003DE34u: goto label_8003DE34;
    case 0x8003DE38u: goto label_8003DE38;
    case 0x8003DE3Cu: goto label_8003DE3C;
    case 0x8003DE40u: goto label_8003DE40;
    case 0x8003DE44u: goto label_8003DE44;
    case 0x8003DE48u: goto label_8003DE48;
    case 0x8003DE4Cu: goto label_8003DE4C;
    case 0x8003DE50u: goto label_8003DE50;
    case 0x8003DE54u: goto label_8003DE54;
    case 0x8003DE58u: goto label_8003DE58;
    case 0x8003DE5Cu: goto label_8003DE5C;
    case 0x8003DE60u: goto label_8003DE60;
    case 0x8003DE64u: goto label_8003DE64;
    case 0x8003DE68u: goto label_8003DE68;
    case 0x8003DE6Cu: goto label_8003DE6C;
    case 0x8003DE70u: goto label_8003DE70;
    case 0x8003DE74u: goto label_8003DE74;
    case 0x8003DE78u: goto label_8003DE78;
    case 0x8003DE7Cu: goto label_8003DE7C;
    case 0x8003DE80u: goto label_8003DE80;
    case 0x8003DE84u: goto label_8003DE84;
    case 0x8003DE88u: goto label_8003DE88;
    case 0x8003DE8Cu: goto label_8003DE8C;
    case 0x8003DE90u: goto label_8003DE90;
    case 0x8003DE94u: goto label_8003DE94;
    case 0x8003DE98u: goto label_8003DE98;
    case 0x8003DE9Cu: goto label_8003DE9C;
    case 0x8003DEA0u: goto label_8003DEA0;
    case 0x8003DEA4u: goto label_8003DEA4;
    case 0x8003DEA8u: goto label_8003DEA8;
    case 0x8003DEACu: goto label_8003DEAC;
    case 0x8003DEB0u: goto label_8003DEB0;
    case 0x8003DEB4u: goto label_8003DEB4;
    case 0x8003DEB8u: goto label_8003DEB8;
    case 0x8003DEBCu: goto label_8003DEBC;
    case 0x8003DEC0u: goto label_8003DEC0;
    case 0x8003DEC4u: goto label_8003DEC4;
    case 0x8003DEC8u: goto label_8003DEC8;
    case 0x8003DECCu: goto label_8003DECC;
    case 0x8003DED0u: goto label_8003DED0;
    case 0x8003DED4u: goto label_8003DED4;
    case 0x8003DED8u: goto label_8003DED8;
    case 0x8003DEDCu: goto label_8003DEDC;
    case 0x8003DEE0u: goto label_8003DEE0;
    case 0x8003DEE4u: goto label_8003DEE4;
    case 0x8003DEE8u: goto label_8003DEE8;
    case 0x8003DEECu: goto label_8003DEEC;
    case 0x8003DEF0u: goto label_8003DEF0;
    case 0x8003DEF4u: goto label_8003DEF4;
    case 0x8003DEF8u: goto label_8003DEF8;
    case 0x8003DEFCu: goto label_8003DEFC;
    case 0x8003DF00u: goto label_8003DF00;
    case 0x8003DF04u: goto label_8003DF04;
    case 0x8003DF08u: goto label_8003DF08;
    case 0x8003DF0Cu: goto label_8003DF0C;
    case 0x8003DF10u: goto label_8003DF10;
    case 0x8003DF14u: goto label_8003DF14;
    case 0x8003DF18u: goto label_8003DF18;
    case 0x8003DF1Cu: goto label_8003DF1C;
    case 0x8003DF20u: goto label_8003DF20;
    case 0x8003DF24u: goto label_8003DF24;
    case 0x8003DF28u: goto label_8003DF28;
    case 0x8003DF2Cu: goto label_8003DF2C;
    case 0x8003DF30u: goto label_8003DF30;
    case 0x8003DF34u: goto label_8003DF34;
    case 0x8003DF38u: goto label_8003DF38;
    case 0x8003DF3Cu: goto label_8003DF3C;
    case 0x8003DF40u: goto label_8003DF40;
    case 0x8003DF44u: goto label_8003DF44;
    case 0x8003DF48u: goto label_8003DF48;
    case 0x8003DF4Cu: goto label_8003DF4C;
    case 0x8003DF50u: goto label_8003DF50;
    case 0x8003DF54u: goto label_8003DF54;
    case 0x8003DF58u: goto label_8003DF58;
    case 0x8003DF5Cu: goto label_8003DF5C;
    case 0x8003DF60u: goto label_8003DF60;
    case 0x8003DF64u: goto label_8003DF64;
    case 0x8003DF68u: goto label_8003DF68;
    case 0x8003DF6Cu: goto label_8003DF6C;
    case 0x8003DF70u: goto label_8003DF70;
    case 0x8003DF74u: goto label_8003DF74;
    case 0x8003DF78u: goto label_8003DF78;
    case 0x8003DF7Cu: goto label_8003DF7C;
    case 0x8003DF80u: goto label_8003DF80;
    case 0x8003DF84u: goto label_8003DF84;
    case 0x8003DF88u: goto label_8003DF88;
    case 0x8003DF8Cu: goto label_8003DF8C;
    case 0x8003DF90u: goto label_8003DF90;
    case 0x8003DF94u: goto label_8003DF94;
    case 0x8003DF98u: goto label_8003DF98;
    case 0x8003DF9Cu: goto label_8003DF9C;
    case 0x8003DFA0u: goto label_8003DFA0;
    case 0x8003DFA4u: goto label_8003DFA4;
    case 0x8003DFA8u: goto label_8003DFA8;
    case 0x8003DFACu: goto label_8003DFAC;
    case 0x8003DFB0u: goto label_8003DFB0;
    case 0x8003DFB4u: goto label_8003DFB4;
    case 0x8003DFB8u: goto label_8003DFB8;
    case 0x8003DFBCu: goto label_8003DFBC;
    case 0x8003DFC0u: goto label_8003DFC0;
    case 0x8003DFC4u: goto label_8003DFC4;
    case 0x8003DFC8u: goto label_8003DFC8;
    case 0x8003DFCCu: goto label_8003DFCC;
    case 0x8003DFD0u: goto label_8003DFD0;
    case 0x8003DFD4u: goto label_8003DFD4;
    case 0x8003DFD8u: goto label_8003DFD8;
    case 0x8003DFDCu: goto label_8003DFDC;
    case 0x8003DFE0u: goto label_8003DFE0;
    case 0x8003DFE4u: goto label_8003DFE4;
    case 0x8003DFE8u: goto label_8003DFE8;
    case 0x8003DFECu: goto label_8003DFEC;
    case 0x8003DFF0u: goto label_8003DFF0;
    case 0x8003DFF4u: goto label_8003DFF4;
    case 0x8003DFF8u: goto label_8003DFF8;
    case 0x8003DFFCu: goto label_8003DFFC;
    case 0x8003E000u: goto label_8003E000;
    case 0x8003E004u: goto label_8003E004;
    case 0x8003E008u: goto label_8003E008;
    case 0x8003E00Cu: goto label_8003E00C;
    case 0x8003E010u: goto label_8003E010;
    case 0x8003E014u: goto label_8003E014;
    case 0x8003E018u: goto label_8003E018;
    case 0x8003E01Cu: goto label_8003E01C;
    case 0x8003E020u: goto label_8003E020;
    case 0x8003E024u: goto label_8003E024;
    case 0x8003E028u: goto label_8003E028;
    case 0x8003E02Cu: goto label_8003E02C;
    case 0x8003E030u: goto label_8003E030;
    case 0x8003E034u: goto label_8003E034;
    case 0x8003E038u: goto label_8003E038;
    case 0x8003E03Cu: goto label_8003E03C;
    case 0x8003E040u: goto label_8003E040;
    case 0x8003E044u: goto label_8003E044;
    case 0x8003E048u: goto label_8003E048;
    case 0x8003E04Cu: goto label_8003E04C;
    case 0x8003E050u: goto label_8003E050;
    case 0x8003E054u: goto label_8003E054;
    case 0x8003E058u: goto label_8003E058;
    case 0x8003E05Cu: goto label_8003E05C;
    case 0x8003E060u: goto label_8003E060;
    case 0x8003E064u: goto label_8003E064;
    case 0x8003E068u: goto label_8003E068;
    case 0x8003E06Cu: goto label_8003E06C;
    case 0x8003E070u: goto label_8003E070;
    case 0x8003E074u: goto label_8003E074;
    case 0x8003E078u: goto label_8003E078;
    case 0x8003E07Cu: goto label_8003E07C;
    case 0x8003E080u: goto label_8003E080;
    case 0x8003E084u: goto label_8003E084;
    case 0x8003E088u: goto label_8003E088;
    case 0x8003E08Cu: goto label_8003E08C;
    case 0x8003E090u: goto label_8003E090;
    case 0x8003E094u: goto label_8003E094;
    case 0x8003E098u: goto label_8003E098;
    case 0x8003E09Cu: goto label_8003E09C;
    case 0x8003E0A0u: goto label_8003E0A0;
    case 0x8003E0A4u: goto label_8003E0A4;
    case 0x8003E0A8u: goto label_8003E0A8;
    case 0x8003E0ACu: goto label_8003E0AC;
    case 0x8003E0B0u: goto label_8003E0B0;
    case 0x8003E0B4u: goto label_8003E0B4;
    case 0x8003E0B8u: goto label_8003E0B8;
    case 0x8003E0BCu: goto label_8003E0BC;
    case 0x8003E0C0u: goto label_8003E0C0;
    case 0x8003E0C4u: goto label_8003E0C4;
    case 0x8003E0C8u: goto label_8003E0C8;
    case 0x8003E0CCu: goto label_8003E0CC;
    case 0x8003E0D0u: goto label_8003E0D0;
    case 0x8003E0D4u: goto label_8003E0D4;
    case 0x8003E0D8u: goto label_8003E0D8;
    case 0x8003E0DCu: goto label_8003E0DC;
    case 0x8003E0E0u: goto label_8003E0E0;
    case 0x8003E0E4u: goto label_8003E0E4;
    case 0x8003E0E8u: goto label_8003E0E8;
    case 0x8003E0ECu: goto label_8003E0EC;
    case 0x8003E0F0u: goto label_8003E0F0;
    case 0x8003E0F4u: goto label_8003E0F4;
    case 0x8003E0F8u: goto label_8003E0F8;
    case 0x8003E0FCu: goto label_8003E0FC;
    case 0x8003E100u: goto label_8003E100;
    case 0x8003E104u: goto label_8003E104;
    case 0x8003E108u: goto label_8003E108;
    case 0x8003E10Cu: goto label_8003E10C;
    case 0x8003E110u: goto label_8003E110;
    case 0x8003E114u: goto label_8003E114;
    case 0x8003E118u: goto label_8003E118;
    case 0x8003E11Cu: goto label_8003E11C;
    case 0x8003E120u: goto label_8003E120;
    case 0x8003E124u: goto label_8003E124;
    case 0x8003E128u: goto label_8003E128;
    case 0x8003E12Cu: goto label_8003E12C;
    case 0x8003E130u: goto label_8003E130;
    case 0x8003E134u: goto label_8003E134;
    case 0x8003E138u: goto label_8003E138;
    case 0x8003E13Cu: goto label_8003E13C;
    case 0x8003E140u: goto label_8003E140;
    case 0x8003E144u: goto label_8003E144;
    case 0x8003E148u: goto label_8003E148;
    case 0x8003E14Cu: goto label_8003E14C;
    case 0x8003E150u: goto label_8003E150;
    case 0x8003E154u: goto label_8003E154;
    case 0x8003E158u: goto label_8003E158;
    case 0x8003E15Cu: goto label_8003E15C;
    case 0x8003E160u: goto label_8003E160;
    case 0x8003E164u: goto label_8003E164;
    case 0x8003E168u: goto label_8003E168;
    case 0x8003E16Cu: goto label_8003E16C;
    case 0x8003E170u: goto label_8003E170;
    case 0x8003E174u: goto label_8003E174;
    case 0x8003E178u: goto label_8003E178;
    case 0x8003E17Cu: goto label_8003E17C;
    case 0x8003E180u: goto label_8003E180;
    case 0x8003E184u: goto label_8003E184;
    case 0x8003E188u: goto label_8003E188;
    case 0x8003E18Cu: goto label_8003E18C;
    case 0x8003E190u: goto label_8003E190;
    case 0x8003E194u: goto label_8003E194;
    case 0x8003E198u: goto label_8003E198;
    case 0x8003E19Cu: goto label_8003E19C;
    case 0x8003E1A0u: goto label_8003E1A0;
    case 0x8003E1A4u: goto label_8003E1A4;
    case 0x8003E1A8u: goto label_8003E1A8;
    case 0x8003E1ACu: goto label_8003E1AC;
    case 0x8003E1B0u: goto label_8003E1B0;
    case 0x8003E1B4u: goto label_8003E1B4;
    case 0x8003E1B8u: goto label_8003E1B8;
    case 0x8003E1BCu: goto label_8003E1BC;
    case 0x8003E1C0u: goto label_8003E1C0;
    case 0x8003E1C4u: goto label_8003E1C4;
    case 0x8003E1C8u: goto label_8003E1C8;
    case 0x8003E1CCu: goto label_8003E1CC;
    case 0x8003E1D0u: goto label_8003E1D0;
    case 0x8003E1D4u: goto label_8003E1D4;
    case 0x8003E1D8u: goto label_8003E1D8;
    case 0x8003E1DCu: goto label_8003E1DC;
    case 0x8003E1E0u: goto label_8003E1E0;
    case 0x8003E1E4u: goto label_8003E1E4;
    case 0x8003E1E8u: goto label_8003E1E8;
    case 0x8003E1ECu: goto label_8003E1EC;
    case 0x8003E1F0u: goto label_8003E1F0;
    case 0x8003E1F4u: goto label_8003E1F4;
    case 0x8003E1F8u: goto label_8003E1F8;
    case 0x8003E1FCu: goto label_8003E1FC;
    case 0x8003E200u: goto label_8003E200;
    case 0x8003E204u: goto label_8003E204;
    case 0x8003E208u: goto label_8003E208;
    case 0x8003E20Cu: goto label_8003E20C;
    case 0x8003E210u: goto label_8003E210;
    case 0x8003E214u: goto label_8003E214;
    case 0x8003E218u: goto label_8003E218;
    case 0x8003E21Cu: goto label_8003E21C;
    case 0x8003E220u: goto label_8003E220;
    case 0x8003E224u: goto label_8003E224;
    case 0x8003E228u: goto label_8003E228;
    case 0x8003E22Cu: goto label_8003E22C;
    case 0x8003E230u: goto label_8003E230;
    case 0x8003E234u: goto label_8003E234;
    case 0x8003E238u: goto label_8003E238;
    case 0x8003E23Cu: goto label_8003E23C;
    case 0x8003E240u: goto label_8003E240;
    case 0x8003E244u: goto label_8003E244;
    case 0x8003E248u: goto label_8003E248;
    case 0x8003E24Cu: goto label_8003E24C;
    case 0x8003E250u: goto label_8003E250;
    case 0x8003E254u: goto label_8003E254;
    case 0x8003E258u: goto label_8003E258;
    case 0x8003E25Cu: goto label_8003E25C;
    case 0x8003E260u: goto label_8003E260;
    case 0x8003E264u: goto label_8003E264;
    case 0x8003E268u: goto label_8003E268;
    case 0x8003E26Cu: goto label_8003E26C;
    case 0x8003E270u: goto label_8003E270;
    case 0x8003E274u: goto label_8003E274;
    case 0x8003E278u: goto label_8003E278;
    case 0x8003E27Cu: goto label_8003E27C;
    case 0x8003E280u: goto label_8003E280;
    case 0x8003E284u: goto label_8003E284;
    case 0x8003E288u: goto label_8003E288;
    case 0x8003E28Cu: goto label_8003E28C;
    case 0x8003E290u: goto label_8003E290;
    case 0x8003E294u: goto label_8003E294;
    case 0x8003E298u: goto label_8003E298;
    case 0x8003E29Cu: goto label_8003E29C;
    case 0x8003E2A0u: goto label_8003E2A0;
    case 0x8003E2A4u: goto label_8003E2A4;
    case 0x8003E2A8u: goto label_8003E2A8;
    case 0x8003E2ACu: goto label_8003E2AC;
    case 0x8003E2B0u: goto label_8003E2B0;
    case 0x8003E2B4u: goto label_8003E2B4;
    case 0x8003E2B8u: goto label_8003E2B8;
    case 0x8003E2BCu: goto label_8003E2BC;
    case 0x8003E2C0u: goto label_8003E2C0;
    case 0x8003E2C4u: goto label_8003E2C4;
    case 0x8003E2C8u: goto label_8003E2C8;
    case 0x8003E2CCu: goto label_8003E2CC;
    case 0x8003E2D0u: goto label_8003E2D0;
    case 0x8003E2D4u: goto label_8003E2D4;
    case 0x8003E2D8u: goto label_8003E2D8;
    case 0x8003E2DCu: goto label_8003E2DC;
    case 0x8003E2E0u: goto label_8003E2E0;
    case 0x8003E2E4u: goto label_8003E2E4;
    case 0x8003E2E8u: goto label_8003E2E8;
    case 0x8003E2ECu: goto label_8003E2EC;
    case 0x8003E2F0u: goto label_8003E2F0;
    case 0x8003E2F4u: goto label_8003E2F4;
    case 0x8003E2F8u: goto label_8003E2F8;
    case 0x8003E2FCu: goto label_8003E2FC;
    case 0x8003E300u: goto label_8003E300;
    case 0x8003E304u: goto label_8003E304;
    case 0x8003E308u: goto label_8003E308;
    case 0x8003E30Cu: goto label_8003E30C;
    case 0x8003E310u: goto label_8003E310;
    case 0x8003E314u: goto label_8003E314;
    case 0x8003E318u: goto label_8003E318;
    case 0x8003E31Cu: goto label_8003E31C;
    case 0x8003E320u: goto label_8003E320;
    case 0x8003E324u: goto label_8003E324;
    case 0x8003E328u: goto label_8003E328;
    case 0x8003E32Cu: goto label_8003E32C;
    case 0x8003E330u: goto label_8003E330;
    case 0x8003E334u: goto label_8003E334;
    case 0x8003E338u: goto label_8003E338;
    case 0x8003E33Cu: goto label_8003E33C;
    case 0x8003E340u: goto label_8003E340;
    case 0x8003E344u: goto label_8003E344;
    case 0x8003E348u: goto label_8003E348;
    case 0x8003E34Cu: goto label_8003E34C;
    case 0x8003E350u: goto label_8003E350;
    case 0x8003E354u: goto label_8003E354;
    case 0x8003E358u: goto label_8003E358;
    case 0x8003E35Cu: goto label_8003E35C;
    case 0x8003E360u: goto label_8003E360;
    case 0x8003E364u: goto label_8003E364;
    case 0x8003E368u: goto label_8003E368;
    case 0x8003E36Cu: goto label_8003E36C;
    case 0x8003E370u: goto label_8003E370;
    case 0x8003E374u: goto label_8003E374;
    case 0x8003E378u: goto label_8003E378;
    case 0x8003E37Cu: goto label_8003E37C;
    case 0x8003E380u: goto label_8003E380;
    case 0x8003E384u: goto label_8003E384;
    case 0x8003E388u: goto label_8003E388;
    case 0x8003E38Cu: goto label_8003E38C;
    case 0x8003E390u: goto label_8003E390;
    case 0x8003E394u: goto label_8003E394;
    case 0x8003E398u: goto label_8003E398;
    case 0x8003E39Cu: goto label_8003E39C;
    case 0x8003E3A0u: goto label_8003E3A0;
    case 0x8003E3A4u: goto label_8003E3A4;
    case 0x8003E3A8u: goto label_8003E3A8;
    case 0x8003E3ACu: goto label_8003E3AC;
    case 0x8003E3B0u: goto label_8003E3B0;
    case 0x8003E3B4u: goto label_8003E3B4;
    case 0x8003E3B8u: goto label_8003E3B8;
    case 0x8003E3BCu: goto label_8003E3BC;
    case 0x8003E3C0u: goto label_8003E3C0;
    case 0x8003E3C4u: goto label_8003E3C4;
    case 0x8003E3C8u: goto label_8003E3C8;
    case 0x8003E3CCu: goto label_8003E3CC;
    case 0x8003E3D0u: goto label_8003E3D0;
    case 0x8003E3D4u: goto label_8003E3D4;
    case 0x8003E3D8u: goto label_8003E3D8;
    case 0x8003E3DCu: goto label_8003E3DC;
    case 0x8003E3E0u: goto label_8003E3E0;
    case 0x8003E3E4u: goto label_8003E3E4;
    case 0x8003E3E8u: goto label_8003E3E8;
    case 0x8003E3ECu: goto label_8003E3EC;
    case 0x8003E3F0u: goto label_8003E3F0;
    case 0x8003E3F4u: goto label_8003E3F4;
    case 0x8003E3F8u: goto label_8003E3F8;
    case 0x8003E3FCu: goto label_8003E3FC;
    case 0x8003E400u: goto label_8003E400;
    case 0x8003E404u: goto label_8003E404;
    case 0x8003E408u: goto label_8003E408;
    case 0x8003E40Cu: goto label_8003E40C;
    case 0x8003E410u: goto label_8003E410;
    case 0x8003E414u: goto label_8003E414;
    case 0x8003E418u: goto label_8003E418;
    case 0x8003E41Cu: goto label_8003E41C;
    case 0x8003E420u: goto label_8003E420;
    case 0x8003E424u: goto label_8003E424;
    case 0x8003E428u: goto label_8003E428;
    case 0x8003E42Cu: goto label_8003E42C;
    case 0x8003E430u: goto label_8003E430;
    case 0x8003E434u: goto label_8003E434;
    case 0x8003E438u: goto label_8003E438;
    case 0x8003E43Cu: goto label_8003E43C;
    case 0x8003E440u: goto label_8003E440;
    case 0x8003E444u: goto label_8003E444;
    case 0x8003E448u: goto label_8003E448;
    case 0x8003E44Cu: goto label_8003E44C;
    case 0x8003E450u: goto label_8003E450;
    case 0x8003E454u: goto label_8003E454;
    case 0x8003E458u: goto label_8003E458;
    case 0x8003E45Cu: goto label_8003E45C;
    case 0x8003E460u: goto label_8003E460;
    case 0x8003E464u: goto label_8003E464;
    case 0x8003E468u: goto label_8003E468;
    case 0x8003E46Cu: goto label_8003E46C;
    case 0x8003E470u: goto label_8003E470;
    case 0x8003E474u: goto label_8003E474;
    case 0x8003E478u: goto label_8003E478;
    case 0x8003E47Cu: goto label_8003E47C;
    case 0x8003E480u: goto label_8003E480;
    case 0x8003E484u: goto label_8003E484;
    case 0x8003E488u: goto label_8003E488;
    case 0x8003E48Cu: goto label_8003E48C;
    case 0x8003E490u: goto label_8003E490;
    case 0x8003E494u: goto label_8003E494;
    case 0x8003E498u: goto label_8003E498;
    case 0x8003E49Cu: goto label_8003E49C;
    case 0x8003E4A0u: goto label_8003E4A0;
    case 0x8003E4A4u: goto label_8003E4A4;
    case 0x8003E4A8u: goto label_8003E4A8;
    case 0x8003E4ACu: goto label_8003E4AC;
    case 0x8003E4B0u: goto label_8003E4B0;
    case 0x8003E4B4u: goto label_8003E4B4;
    case 0x8003E4B8u: goto label_8003E4B8;
    case 0x8003E4BCu: goto label_8003E4BC;
    case 0x8003E4C0u: goto label_8003E4C0;
    case 0x8003E4C4u: goto label_8003E4C4;
    case 0x8003E4C8u: goto label_8003E4C8;
    case 0x8003E4CCu: goto label_8003E4CC;
    case 0x8003E4D0u: goto label_8003E4D0;
    case 0x8003E4D4u: goto label_8003E4D4;
    case 0x8003E4D8u: goto label_8003E4D8;
    case 0x8003E4DCu: goto label_8003E4DC;
    case 0x8003E4E0u: goto label_8003E4E0;
    case 0x8003E4E4u: goto label_8003E4E4;
    case 0x8003E4E8u: goto label_8003E4E8;
    case 0x8003E4ECu: goto label_8003E4EC;
    case 0x8003E4F0u: goto label_8003E4F0;
    case 0x8003E4F4u: goto label_8003E4F4;
    case 0x8003E4F8u: goto label_8003E4F8;
    case 0x8003E4FCu: goto label_8003E4FC;
    case 0x8003E500u: goto label_8003E500;
    case 0x8003E504u: goto label_8003E504;
    case 0x8003E508u: goto label_8003E508;
    case 0x8003E50Cu: goto label_8003E50C;
    case 0x8003E510u: goto label_8003E510;
    case 0x8003E514u: goto label_8003E514;
    case 0x8003E518u: goto label_8003E518;
    case 0x8003E51Cu: goto label_8003E51C;
    case 0x8003E520u: goto label_8003E520;
    case 0x8003E524u: goto label_8003E524;
    case 0x8003E528u: goto label_8003E528;
    case 0x8003E52Cu: goto label_8003E52C;
    case 0x8003E530u: goto label_8003E530;
    case 0x8003E534u: goto label_8003E534;
    case 0x8003E538u: goto label_8003E538;
    case 0x8003E53Cu: goto label_8003E53C;
    case 0x8003E540u: goto label_8003E540;
    case 0x8003E544u: goto label_8003E544;
    case 0x8003E548u: goto label_8003E548;
    case 0x8003E54Cu: goto label_8003E54C;
    case 0x8003E550u: goto label_8003E550;
    case 0x8003E554u: goto label_8003E554;
    case 0x8003E558u: goto label_8003E558;
    case 0x8003E55Cu: goto label_8003E55C;
    case 0x8003E560u: goto label_8003E560;
    case 0x8003E564u: goto label_8003E564;
    case 0x8003E568u: goto label_8003E568;
    case 0x8003E56Cu: goto label_8003E56C;
    case 0x8003E570u: goto label_8003E570;
    case 0x8003E574u: goto label_8003E574;
    case 0x8003E578u: goto label_8003E578;
    case 0x8003E57Cu: goto label_8003E57C;
    case 0x8003E580u: goto label_8003E580;
    case 0x8003E584u: goto label_8003E584;
    case 0x8003E588u: goto label_8003E588;
    case 0x8003E58Cu: goto label_8003E58C;
    case 0x8003E590u: goto label_8003E590;
    case 0x8003E594u: goto label_8003E594;
    case 0x8003E598u: goto label_8003E598;
    case 0x8003E59Cu: goto label_8003E59C;
    case 0x8003E5A0u: goto label_8003E5A0;
    case 0x8003E5A4u: goto label_8003E5A4;
    case 0x8003E5A8u: goto label_8003E5A8;
    case 0x8003E5ACu: goto label_8003E5AC;
    case 0x8003E5B0u: goto label_8003E5B0;
    case 0x8003E5B4u: goto label_8003E5B4;
    case 0x8003E5B8u: goto label_8003E5B8;
    case 0x8003E5BCu: goto label_8003E5BC;
    case 0x8003E5C0u: goto label_8003E5C0;
    case 0x8003E5C4u: goto label_8003E5C4;
    case 0x8003E5C8u: goto label_8003E5C8;
    case 0x8003E5CCu: goto label_8003E5CC;
    case 0x8003E5D0u: goto label_8003E5D0;
    case 0x8003E5D4u: goto label_8003E5D4;
    case 0x8003E5D8u: goto label_8003E5D8;
    case 0x8003E5DCu: goto label_8003E5DC;
    case 0x8003E5E0u: goto label_8003E5E0;
    case 0x8003E5E4u: goto label_8003E5E4;
    case 0x8003E5E8u: goto label_8003E5E8;
    case 0x8003E5ECu: goto label_8003E5EC;
    case 0x8003E5F0u: goto label_8003E5F0;
    case 0x8003E5F4u: goto label_8003E5F4;
    case 0x8003E5F8u: goto label_8003E5F8;
    case 0x8003E5FCu: goto label_8003E5FC;
    case 0x8003E600u: goto label_8003E600;
    case 0x8003E604u: goto label_8003E604;
    case 0x8003E608u: goto label_8003E608;
    case 0x8003E60Cu: goto label_8003E60C;
    case 0x8003E610u: goto label_8003E610;
    case 0x8003E614u: goto label_8003E614;
    case 0x8003E618u: goto label_8003E618;
    case 0x8003E61Cu: goto label_8003E61C;
    case 0x8003E620u: goto label_8003E620;
    case 0x8003E624u: goto label_8003E624;
    case 0x8003E628u: goto label_8003E628;
    case 0x8003E62Cu: goto label_8003E62C;
    case 0x8003E630u: goto label_8003E630;
    case 0x8003E634u: goto label_8003E634;
    case 0x8003E638u: goto label_8003E638;
    case 0x8003E63Cu: goto label_8003E63C;
    case 0x8003E640u: goto label_8003E640;
    case 0x8003E644u: goto label_8003E644;
    case 0x8003E648u: goto label_8003E648;
    case 0x8003E64Cu: goto label_8003E64C;
    case 0x8003E650u: goto label_8003E650;
    case 0x8003E654u: goto label_8003E654;
    case 0x8003E658u: goto label_8003E658;
    case 0x8003E65Cu: goto label_8003E65C;
    case 0x8003E660u: goto label_8003E660;
    case 0x8003E664u: goto label_8003E664;
    case 0x8003E668u: goto label_8003E668;
    case 0x8003E66Cu: goto label_8003E66C;
    case 0x8003E670u: goto label_8003E670;
    case 0x8003E674u: goto label_8003E674;
    case 0x8003E678u: goto label_8003E678;
    case 0x8003E67Cu: goto label_8003E67C;
    case 0x8003E680u: goto label_8003E680;
    case 0x8003E684u: goto label_8003E684;
    case 0x8003E688u: goto label_8003E688;
    case 0x8003E68Cu: goto label_8003E68C;
    case 0x8003E690u: goto label_8003E690;
    case 0x8003E694u: goto label_8003E694;
    case 0x8003E698u: goto label_8003E698;
    case 0x8003E69Cu: goto label_8003E69C;
    case 0x8003E6A0u: goto label_8003E6A0;
    case 0x8003E6A4u: goto label_8003E6A4;
    case 0x8003E6A8u: goto label_8003E6A8;
    case 0x8003E6ACu: goto label_8003E6AC;
    case 0x8003E6B0u: goto label_8003E6B0;
    case 0x8003E6B4u: goto label_8003E6B4;
    case 0x8003E6B8u: goto label_8003E6B8;
    case 0x8003E6BCu: goto label_8003E6BC;
    case 0x8003E6C0u: goto label_8003E6C0;
    case 0x8003E6C4u: goto label_8003E6C4;
    case 0x8003E6C8u: goto label_8003E6C8;
    case 0x8003E6CCu: goto label_8003E6CC;
    case 0x8003E6D0u: goto label_8003E6D0;
    case 0x8003E6D4u: goto label_8003E6D4;
    case 0x8003E6D8u: goto label_8003E6D8;
    case 0x8003E6DCu: goto label_8003E6DC;
    default: return;
    }
label_8003A6E0:
    ctx->pc = 0x8003A6E0u;
    ctx->downcount -= 2;
    // 8003A6E0: cmpwi   r0, 255
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(255);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003A6E4:
    ctx->pc = 0x8003A6E4u;
    // 8003A6E4: bc    12, 2, 0x8003A6FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003A6FC;
        }
    }

label_8003A6E8:
    ctx->pc = 0x8003A6E8u;
    ctx->downcount -= 3;
    // 8003A6E8: lbzx    r0, r8, r5
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[5];
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003A6EC:
    ctx->pc = 0x8003A6ECu;
    // 8003A6EC: cmpw    r6, r0
    {
        s32 val_a = (s32)(ctx->gpr[6]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003A6F0:
    ctx->pc = 0x8003A6F0u;
    // 8003A6F0: bc    4, 2, 0x8003A6FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003A6FC;
        }
    }

label_8003A6F4:
    ctx->pc = 0x8003A6F4u;
    ctx->downcount -= 2;
    // 8003A6F4: lwz     r0, 108(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(108);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003A6F8:
    ctx->pc = 0x8003A6F8u;
    // 8003A6F8: add   r27, r0, r7
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[27] = res;
    }

label_8003A6FC:
    ctx->pc = 0x8003A6FCu;
    ctx->downcount -= 6;
    // 8003A6FC: lbz     r0, 85(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(85);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003A700:
    ctx->pc = 0x8003A700u;
    // 8003A700: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8003A704:
    ctx->pc = 0x8003A704u;
    // 8003A704: add   r5, r0, r5
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[5] = res;
    }

label_8003A708:
    ctx->pc = 0x8003A708u;
    // 8003A708: addi    r5, r5, 1
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(1);

label_8003A70C:
    ctx->pc = 0x8003A70Cu;
    // 8003A70C: addi    r7, r7, 18
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(18);

label_8003A710:
    ctx->pc = 0x8003A710u;
    // 8003A710: bc    16, 0, 0x8003A6C8
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = 0x8003A6C8u;
            return;
        }
    }

label_8003A714:
    ctx->pc = 0x8003A714u;
    ctx->downcount -= 2;
    // 8003A714: cmplwi  r27, 0x0000
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

label_8003A718:
    ctx->pc = 0x8003A718u;
    // 8003A718: bc    4, 2, 0x8003A750
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003A750;
        }
    }

label_8003A71C:
    ctx->pc = 0x8003A71Cu;
    ctx->downcount -= 3;
    // 8003A71C: extsh r0, r30
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[30];
    }

label_8003A720:
    ctx->pc = 0x8003A720u;
    // 8003A720: cmpwi   r0, 0
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

label_8003A724:
    ctx->pc = 0x8003A724u;
    // 8003A724: bc    12, 0, 0x8003A72C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003A72C;
        }
    }

label_8003A728:
    ctx->pc = 0x8003A728u;
    ctx->downcount -= 1;
    // 8003A728: b       0x8003A730
    {
            goto label_8003A730;
    }

label_8003A72C:
    ctx->pc = 0x8003A72Cu;
    ctx->downcount -= 1;
    // 8003A72C: neg  r0, r0
    {
        u32 a = ctx->gpr[0];
        ctx->gpr[0] = (~a) + 1u;
    }

label_8003A730:
    ctx->pc = 0x8003A730u;
    ctx->downcount -= 8;
    // 8003A730: li      r4, 256
    ctx->gpr[4] = (u32)(s32)(256);

label_8003A734:
    ctx->pc = 0x8003A734u;
    // 8003A734: xor   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] ^ ctx->gpr[0];
    }

label_8003A738:
    ctx->pc = 0x8003A738u;
    // 8003A738: srawi r3, r0, 1
    {
        u32 sh = 1u;
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

label_8003A73C:
    ctx->pc = 0x8003A73Cu;
    // 8003A73C: and   r0, r0, r4
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[4];
    }

label_8003A740:
    ctx->pc = 0x8003A740u;
    // 8003A740: subf   r0, r0, r3
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[3];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_8003A744:
    ctx->pc = 0x8003A744u;
    // 8003A744: rlwinm r0, r0, 1, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 1u) & 0x00000001u;
    }

label_8003A748:
    ctx->pc = 0x8003A748u;
    // 8003A748: extsh r3, r0
    {
        ctx->gpr[3] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_8003A74C:
    ctx->pc = 0x8003A74Cu;
    // 8003A74C: b       0x8003AA10
    {
            goto label_8003AA10;
    }

label_8003A750:
    ctx->pc = 0x8003A750u;
    ctx->downcount -= 6;
    // 8003A750: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003A754:
    ctx->pc = 0x8003A754u;
    // 8003A754: addi    r3, r1, 12
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(12);

label_8003A758:
    ctx->pc = 0x8003A758u;
    // 8003A758: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_8003A75C:
    ctx->pc = 0x8003A75Cu;
    // 8003A75C: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_8003A760:
    ctx->pc = 0x8003A760u;
    // 8003A760: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8003A764:
    ctx->downcount -= 6;
    // 8003A764: rlwinm r6, r5, 1, 31, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[5], 1u) & 0x00000001u;
    }

label_8003A768:
    // 8003A768: rlwinm r0, r5, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x00000001u;
    }

label_8003A76C:
    // 8003A76C: xor   r0, r0, r6
    {
        ctx->gpr[0] = ctx->gpr[0] ^ ctx->gpr[6];
    }

label_8003A770:
    // 8003A770: subf   r0, r6, r0
    {
        u32 a = ~ctx->gpr[6];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_8003A774:
    // 8003A774: cmpwi   r0, 0
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

label_8003A778:
    // 8003A778: bc    12, 2, 0x8003A7B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003A7B4;
        }
    }

label_8003A77C:
    ctx->pc = 0x8003A77Cu;
    ctx->downcount -= 14;
    // 8003A77C: lfs     f2, -31500(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003A77Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31500);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8003A780:
    ctx->pc = 0x8003A780u;
    // 8003A780: lha     r0, 0(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(0);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003A784:
    ctx->pc = 0x8003A784u;
    // 8003A784: lfd     f1, -31528(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003A784u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31528);
        ctx->fpr[1] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003A788:
    // 8003A788: xoris   r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] ^ (0x8000u << 16);

label_8003A78C:
    ctx->pc = 0x8003A78Cu;
    // 8003A78C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003A790:
    // 8003A790: lis     r0, 17200
    ctx->gpr[0] = ((u32)(s32)(17200) << 16);

label_8003A794:
    ctx->pc = 0x8003A794u;
    // 8003A794: stw     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003A798:
    ctx->pc = 0x8003A798u;
    // 8003A798: lfd     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003A798u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003A79C:
    ctx->pc = 0x8003A79Cu;
    // 8003A79C: fsubs   f0, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8003A79Cu)) return;
    ppc_fsubs(ctx, 0, 0, 1);

label_8003A7A0:
    ctx->pc = 0x8003A7A0u;
    // 8003A7A0: fmuls   f0, f2, f0
    if (!ppc_fp_available_inline(ctx, 0x8003A7A0u)) return;
    ppc_fmuls(ctx, 0, 2, 0);

label_8003A7A4:
    ctx->pc = 0x8003A7A4u;
    // 8003A7A4: fctiwz    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x8003A7A4u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_8003A7A8:
    ctx->pc = 0x8003A7A8u;
    // 8003A7A8: stfd     f0, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003A7A8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_8003A7AC:
    ctx->pc = 0x8003A7ACu;
    // 8003A7AC: lwz     r7, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8003A7B0:
    // 8003A7B0: b       0x8003A7E8
    {
            goto label_8003A7E8;
    }

label_8003A7B4:
    ctx->pc = 0x8003A7B4u;
    ctx->downcount -= 13;
    // 8003A7B4: lfs     f2, -31500(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003A7B4u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31500);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8003A7B8:
    ctx->pc = 0x8003A7B8u;
    // 8003A7B8: lha     r0, 0(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(0);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003A7BC:
    ctx->pc = 0x8003A7BCu;
    // 8003A7BC: lfd     f1, -31528(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003A7BCu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31528);
        ctx->fpr[1] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003A7C0:
    // 8003A7C0: xoris   r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] ^ (0x8000u << 16);

label_8003A7C4:
    ctx->pc = 0x8003A7C4u;
    // 8003A7C4: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003A7C8:
    // 8003A7C8: lis     r0, 17200
    ctx->gpr[0] = ((u32)(s32)(17200) << 16);

label_8003A7CC:
    ctx->pc = 0x8003A7CCu;
    // 8003A7CC: stw     r0, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003A7D0:
    ctx->pc = 0x8003A7D0u;
    // 8003A7D0: lfd     f0, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003A7D0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003A7D4:
    ctx->pc = 0x8003A7D4u;
    // 8003A7D4: fsubs   f0, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8003A7D4u)) return;
    ppc_fsubs(ctx, 0, 0, 1);

label_8003A7D8:
    ctx->pc = 0x8003A7D8u;
    // 8003A7D8: fmuls   f0, f2, f0
    if (!ppc_fp_available_inline(ctx, 0x8003A7D8u)) return;
    ppc_fmuls(ctx, 0, 2, 0);

label_8003A7DC:
    ctx->pc = 0x8003A7DCu;
    // 8003A7DC: fctiwz    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x8003A7DCu)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_8003A7E0:
    ctx->pc = 0x8003A7E0u;
    // 8003A7E0: stfd     f0, 40(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003A7E0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_8003A7E4:
    ctx->pc = 0x8003A7E4u;
    // 8003A7E4: lwz     r7, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8003A7E8:
    ctx->pc = 0x8003A7E8u;
    ctx->downcount -= 5;
    // 8003A7E8: lha     r6, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[6] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003A7EC:
    ctx->pc = 0x8003A7ECu;
    // 8003A7EC: sth     r6, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_8003A7F0:
    // 8003A7F0: extsh r0, r7
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[7];
    }

label_8003A7F4:
    // 8003A7F4: cmpw    r6, r0
    {
        s32 val_a = (s32)(ctx->gpr[6]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003A7F8:
    // 8003A7F8: bc    4, 1, 0x8003A80C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003A80C;
        }
    }

label_8003A7FC:
    ctx->pc = 0x8003A7FCu;
    ctx->downcount -= 4;
    // 8003A7FC: sth     r7, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[7]);
    }

label_8003A800:
    // 8003A800: subf   r0, r7, r6
    {
        u32 a = ~ctx->gpr[7];
        u32 b = ctx->gpr[6];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_8003A804:
    ctx->pc = 0x8003A804u;
    // 8003A804: sth     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003A808:
    // 8003A808: b       0x8003A834
    {
            goto label_8003A834;
    }

label_8003A80C:
    ctx->downcount -= 3;
    // 8003A80C: neg  r0, r0
    {
        u32 a = ctx->gpr[0];
        ctx->gpr[0] = (~a) + 1u;
    }

label_8003A810:
    // 8003A810: cmpw    r6, r0
    {
        s32 val_a = (s32)(ctx->gpr[6]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003A814:
    // 8003A814: bc    4, 0, 0x8003A82C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003A82C;
        }
    }

label_8003A818:
    ctx->downcount -= 5;
    // 8003A818: extsh r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_8003A81C:
    ctx->pc = 0x8003A81Cu;
    // 8003A81C: sth     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003A820:
    // 8003A820: add   r0, r6, r7
    {
        u32 a = ctx->gpr[6];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8003A824:
    ctx->pc = 0x8003A824u;
    // 8003A824: sth     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003A828:
    // 8003A828: b       0x8003A834
    {
            goto label_8003A834;
    }

label_8003A82C:
    ctx->downcount -= 2;
    // 8003A82C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8003A830:
    ctx->pc = 0x8003A830u;
    // 8003A830: sth     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003A834:
    ctx->downcount -= 4;
    // 8003A834: addi    r3, r3, 2
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(2);

label_8003A838:
    // 8003A838: addi    r4, r4, 2
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(2);

label_8003A83C:
    // 8003A83C: addi    r5, r5, 1
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(1);

label_8003A840:
    // 8003A840: bc    16, 0, 0x8003A764
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003A764u;
                return;
            }
            goto label_8003A764;
        }
    }

label_8003A844:
    ctx->pc = 0x8003A844u;
    ctx->downcount -= 2;
    // 8003A844: cmplwi  r29, 0x0000
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

label_8003A848:
    ctx->pc = 0x8003A848u;
    // 8003A848: bc    12, 2, 0x8003A884
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003A884;
        }
    }

label_8003A84C:
    ctx->pc = 0x8003A84Cu;
    ctx->downcount -= 5;
    // 8003A84C: lha     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003A850:
    ctx->pc = 0x8003A850u;
    // 8003A850: sth     r0, 20(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(20);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003A854:
    ctx->pc = 0x8003A854u;
    // 8003A854: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8003A858:
    ctx->pc = 0x8003A858u;
    // 8003A858: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8003A85C:
    ctx->pc = 0x8003A85Cu;
    // 8003A85C: bl      0x80039B54
    {
            ctx->lr = 0x8003A860u;
            ctx->pc = 0x80039B54u;
            return;
    }

label_8003A860:
    ctx->pc = 0x8003A860u;
    ctx->downcount -= 7;
    // 8003A860: lha     r0, 10(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(10);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003A864:
    ctx->pc = 0x8003A864u;
    // 8003A864: sth     r0, 68(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(68);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003A868:
    ctx->pc = 0x8003A868u;
    // 8003A868: addi    r3, r29, 48
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(48);

label_8003A86C:
    ctx->pc = 0x8003A86Cu;
    // 8003A86C: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8003A870:
    ctx->pc = 0x8003A870u;
    // 8003A870: lfs     f1, -31520(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003A870u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31520);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003A874:
    ctx->pc = 0x8003A874u;
    // 8003A874: lfs     f2, -31516(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003A874u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31516);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8003A878:
    ctx->pc = 0x8003A878u;
    // 8003A878: bl      0x800399C8
    {
            ctx->lr = 0x8003A87Cu;
            ctx->pc = 0x800399C8u;
            return;
    }

label_8003A87C:
    ctx->pc = 0x8003A87Cu;
    ctx->downcount -= 2;
    // 8003A87C: addi    r29, r29, 96
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(96);

label_8003A880:
    ctx->pc = 0x8003A880u;
    // 8003A880: b       0x8003A9E0
    {
            goto label_8003A9E0;
    }

label_8003A884:
    ctx->pc = 0x8003A884u;
    ctx->downcount -= 71;
    // 8003A884: lha     r3, 2(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(2);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003A888:
    ctx->pc = 0x8003A888u;
    // 8003A888: lha     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003A88C:
    ctx->pc = 0x8003A88Cu;
    // 8003A88C: add   r0, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8003A890:
    ctx->pc = 0x8003A890u;
    // 8003A890: srawi r0, r0, 1
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

label_8003A894:
    ctx->pc = 0x8003A894u;
    // 8003A894: extsh r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_8003A898:
    ctx->pc = 0x8003A898u;
    // 8003A898: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_8003A89C:
    ctx->pc = 0x8003A89Cu;
    // 8003A89C: extsh r7, r0
    {
        ctx->gpr[7] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_8003A8A0:
    ctx->pc = 0x8003A8A0u;
    // 8003A8A0: lbz     r3, -32120(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32120);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8003A8A4:
    ctx->pc = 0x8003A8A4u;
    // 8003A8A4: lfs     f2, -31500(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003A8A4u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31500);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8003A8A8:
    ctx->pc = 0x8003A8A8u;
    // 8003A8A8: lha     r6, 0(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(0);
        ctx->gpr[6] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003A8AC:
    ctx->pc = 0x8003A8ACu;
    // 8003A8AC: neg  r0, r6
    {
        u32 a = ctx->gpr[6];
        ctx->gpr[0] = (~a) + 1u;
    }

label_8003A8B0:
    ctx->pc = 0x8003A8B0u;
    // 8003A8B0: lfd     f1, -31528(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003A8B0u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31528);
        ctx->fpr[1] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003A8B4:
    ctx->pc = 0x8003A8B4u;
    // 8003A8B4: xoris   r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] ^ (0x8000u << 16);

label_8003A8B8:
    ctx->pc = 0x8003A8B8u;
    // 8003A8B8: stw     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003A8BC:
    ctx->pc = 0x8003A8BCu;
    // 8003A8BC: lis     r5, 17200
    ctx->gpr[5] = ((u32)(s32)(17200) << 16);

label_8003A8C0:
    ctx->pc = 0x8003A8C0u;
    // 8003A8C0: stw     r5, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8003A8C4:
    ctx->pc = 0x8003A8C4u;
    // 8003A8C4: lfd     f0, 40(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003A8C4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003A8C8:
    ctx->pc = 0x8003A8C8u;
    // 8003A8C8: fsubs   f0, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8003A8C8u)) return;
    ppc_fsubs(ctx, 0, 0, 1);

label_8003A8CC:
    ctx->pc = 0x8003A8CCu;
    // 8003A8CC: fmuls   f0, f2, f0
    if (!ppc_fp_available_inline(ctx, 0x8003A8CCu)) return;
    ppc_fmuls(ctx, 0, 2, 0);

label_8003A8D0:
    ctx->pc = 0x8003A8D0u;
    // 8003A8D0: fctiwz    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x8003A8D0u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_8003A8D4:
    ctx->pc = 0x8003A8D4u;
    // 8003A8D4: stfd     f0, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003A8D4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_8003A8D8:
    ctx->pc = 0x8003A8D8u;
    // 8003A8D8: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003A8DC:
    ctx->pc = 0x8003A8DCu;
    // 8003A8DC: extsh r4, r0
    {
        ctx->gpr[4] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_8003A8E0:
    ctx->pc = 0x8003A8E0u;
    // 8003A8E0: lwz     r0, -32048(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32048);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003A8E4:
    ctx->pc = 0x8003A8E4u;
    // 8003A8E4: divw   r4, r4, r0
    {
        s32 dividend = (s32)ctx->gpr[4];
        s32 divisor = (s32)ctx->gpr[0];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[4] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
    }

label_8003A8E8:
    ctx->pc = 0x8003A8E8u;
    // 8003A8E8: mullw   r4, r3, r4
    {
        s64 product = (s64)(s32)ctx->gpr[3] * (s64)(s32)ctx->gpr[4];
        ctx->gpr[4] = (u32)product;
    }

label_8003A8EC:
    ctx->pc = 0x8003A8ECu;
    // 8003A8EC: cmpw    r7, r4
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

label_8003A8F0:
    ctx->pc = 0x8003A8F0u;
    // 8003A8F0: bc    4, 0, 0x8003A8F8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003A8F8;
        }
    }

label_8003A8F4:
    ctx->pc = 0x8003A8F4u;
    ctx->downcount -= 1;
    // 8003A8F4: b       0x8003A938
    {
            goto label_8003A938;
    }

label_8003A8F8:
    ctx->pc = 0x8003A8F8u;
    ctx->downcount -= 57;
    // 8003A8F8: xoris   r4, r6, 0x8000
    ctx->gpr[4] = ctx->gpr[6] ^ (0x8000u << 16);

label_8003A8FC:
    ctx->pc = 0x8003A8FCu;
    // 8003A8FC: stw     r4, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8003A900:
    ctx->pc = 0x8003A900u;
    // 8003A900: stw     r5, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8003A904:
    ctx->pc = 0x8003A904u;
    // 8003A904: lfd     f0, 40(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003A904u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003A908:
    ctx->pc = 0x8003A908u;
    // 8003A908: fsubs   f0, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8003A908u)) return;
    ppc_fsubs(ctx, 0, 0, 1);

label_8003A90C:
    ctx->pc = 0x8003A90Cu;
    // 8003A90C: fmuls   f0, f2, f0
    if (!ppc_fp_available_inline(ctx, 0x8003A90Cu)) return;
    ppc_fmuls(ctx, 0, 2, 0);

label_8003A910:
    ctx->pc = 0x8003A910u;
    // 8003A910: fctiwz    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x8003A910u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_8003A914:
    ctx->pc = 0x8003A914u;
    // 8003A914: stfd     f0, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003A914u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_8003A918:
    ctx->pc = 0x8003A918u;
    // 8003A918: lwz     r4, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8003A91C:
    ctx->pc = 0x8003A91Cu;
    // 8003A91C: extsh r4, r4
    {
        ctx->gpr[4] = (u32)(s32)(s16)ctx->gpr[4];
    }

label_8003A920:
    ctx->pc = 0x8003A920u;
    // 8003A920: divw   r4, r4, r0
    {
        s32 dividend = (s32)ctx->gpr[4];
        s32 divisor = (s32)ctx->gpr[0];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[4] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
    }

label_8003A924:
    ctx->pc = 0x8003A924u;
    // 8003A924: mullw   r4, r3, r4
    {
        s64 product = (s64)(s32)ctx->gpr[3] * (s64)(s32)ctx->gpr[4];
        ctx->gpr[4] = (u32)product;
    }

label_8003A928:
    ctx->pc = 0x8003A928u;
    // 8003A928: cmpw    r7, r4
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

label_8003A92C:
    ctx->pc = 0x8003A92Cu;
    // 8003A92C: bc    4, 1, 0x8003A934
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003A934;
        }
    }

label_8003A930:
    ctx->pc = 0x8003A930u;
    ctx->downcount -= 1;
    // 8003A930: b       0x8003A938
    {
            goto label_8003A938;
    }

label_8003A934:
    ctx->pc = 0x8003A934u;
    ctx->downcount -= 1;
    // 8003A934: or   r4, r7, r7
    {
        ctx->gpr[4] = ctx->gpr[7] | ctx->gpr[7];
    }

label_8003A938:
    ctx->pc = 0x8003A938u;
    ctx->downcount -= 71;
    // 8003A938: extsh r4, r4
    {
        ctx->gpr[4] = (u32)(s32)(s16)ctx->gpr[4];
    }

label_8003A93C:
    ctx->pc = 0x8003A93Cu;
    // 8003A93C: lha     r6, 0(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(0);
        ctx->gpr[6] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003A940:
    ctx->pc = 0x8003A940u;
    // 8003A940: lha     r5, 10(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(10);
        ctx->gpr[5] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003A944:
    ctx->pc = 0x8003A944u;
    // 8003A944: add   r5, r6, r5
    {
        u32 a = ctx->gpr[6];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[5] = res;
    }

label_8003A948:
    ctx->pc = 0x8003A948u;
    // 8003A948: srawi r5, r5, 1
    {
        u32 sh = 1u;
        u32 value = ctx->gpr[5];
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

label_8003A94C:
    ctx->pc = 0x8003A94Cu;
    // 8003A94C: extsh r5, r5
    {
        ctx->gpr[5] = (u32)(s32)(s16)ctx->gpr[5];
    }

label_8003A950:
    ctx->pc = 0x8003A950u;
    // 8003A950: subf   r5, r6, r5
    {
        u32 a = ~ctx->gpr[6];
        u32 b = ctx->gpr[5];
        u32 res = a + b + 1u;
        ctx->gpr[5] = res;
    }

label_8003A954:
    ctx->pc = 0x8003A954u;
    // 8003A954: extsh r8, r5
    {
        ctx->gpr[8] = (u32)(s32)(s16)ctx->gpr[5];
    }

label_8003A958:
    ctx->pc = 0x8003A958u;
    // 8003A958: lfs     f2, -31500(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003A958u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31500);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8003A95C:
    ctx->pc = 0x8003A95Cu;
    // 8003A95C: lha     r5, 0(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(0);
        ctx->gpr[5] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003A960:
    ctx->pc = 0x8003A960u;
    // 8003A960: lfd     f1, -31528(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003A960u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31528);
        ctx->fpr[1] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003A964:
    ctx->pc = 0x8003A964u;
    // 8003A964: xoris   r5, r5, 0x8000
    ctx->gpr[5] = ctx->gpr[5] ^ (0x8000u << 16);

label_8003A968:
    ctx->pc = 0x8003A968u;
    // 8003A968: stw     r5, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8003A96C:
    ctx->pc = 0x8003A96Cu;
    // 8003A96C: lis     r5, 17200
    ctx->gpr[5] = ((u32)(s32)(17200) << 16);

label_8003A970:
    ctx->pc = 0x8003A970u;
    // 8003A970: stw     r5, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8003A974:
    ctx->pc = 0x8003A974u;
    // 8003A974: lfd     f0, 40(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003A974u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003A978:
    ctx->pc = 0x8003A978u;
    // 8003A978: fsubs   f0, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8003A978u)) return;
    ppc_fsubs(ctx, 0, 0, 1);

label_8003A97C:
    ctx->pc = 0x8003A97Cu;
    // 8003A97C: fmuls   f0, f2, f0
    if (!ppc_fp_available_inline(ctx, 0x8003A97Cu)) return;
    ppc_fmuls(ctx, 0, 2, 0);

label_8003A980:
    ctx->pc = 0x8003A980u;
    // 8003A980: fctiwz    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x8003A980u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_8003A984:
    ctx->pc = 0x8003A984u;
    // 8003A984: stfd     f0, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003A984u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_8003A988:
    ctx->pc = 0x8003A988u;
    // 8003A988: lwz     r5, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8003A98C:
    ctx->pc = 0x8003A98Cu;
    // 8003A98C: extsh r7, r5
    {
        ctx->gpr[7] = (u32)(s32)(s16)ctx->gpr[5];
    }

label_8003A990:
    ctx->pc = 0x8003A990u;
    // 8003A990: neg  r5, r7
    {
        u32 a = ctx->gpr[7];
        ctx->gpr[5] = (~a) + 1u;
    }

label_8003A994:
    ctx->pc = 0x8003A994u;
    // 8003A994: rlwinm r6, r0, 1, 0, 30
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[0], 1u) & 0xFFFFFFFEu;
    }

label_8003A998:
    ctx->pc = 0x8003A998u;
    // 8003A998: divw   r0, r5, r6
    {
        s32 dividend = (s32)ctx->gpr[5];
        s32 divisor = (s32)ctx->gpr[6];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[0] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
    }

label_8003A99C:
    ctx->pc = 0x8003A99Cu;
    // 8003A99C: mullw   r0, r3, r0
    {
        s64 product = (s64)(s32)ctx->gpr[3] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[0] = (u32)product;
    }

label_8003A9A0:
    ctx->pc = 0x8003A9A0u;
    // 8003A9A0: cmpw    r8, r0
    {
        s32 val_a = (s32)(ctx->gpr[8]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003A9A4:
    ctx->pc = 0x8003A9A4u;
    // 8003A9A4: bc    4, 0, 0x8003A9AC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003A9AC;
        }
    }

label_8003A9A8:
    ctx->pc = 0x8003A9A8u;
    ctx->downcount -= 1;
    // 8003A9A8: b       0x8003A9C4
    {
            goto label_8003A9C4;
    }

label_8003A9AC:
    ctx->pc = 0x8003A9ACu;
    ctx->downcount -= 47;
    // 8003A9AC: divw   r0, r7, r6
    {
        s32 dividend = (s32)ctx->gpr[7];
        s32 divisor = (s32)ctx->gpr[6];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[0] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
    }

label_8003A9B0:
    ctx->pc = 0x8003A9B0u;
    // 8003A9B0: mullw   r0, r3, r0
    {
        s64 product = (s64)(s32)ctx->gpr[3] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[0] = (u32)product;
    }

label_8003A9B4:
    ctx->pc = 0x8003A9B4u;
    // 8003A9B4: cmpw    r8, r0
    {
        s32 val_a = (s32)(ctx->gpr[8]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003A9B8:
    ctx->pc = 0x8003A9B8u;
    // 8003A9B8: bc    4, 1, 0x8003A9C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003A9C0;
        }
    }

label_8003A9BC:
    ctx->pc = 0x8003A9BCu;
    ctx->downcount -= 1;
    // 8003A9BC: b       0x8003A9C4
    {
            goto label_8003A9C4;
    }

label_8003A9C0:
    ctx->pc = 0x8003A9C0u;
    ctx->downcount -= 1;
    // 8003A9C0: or   r0, r8, r8
    {
        ctx->gpr[0] = ctx->gpr[8] | ctx->gpr[8];
    }

label_8003A9C4:
    ctx->pc = 0x8003A9C4u;
    ctx->downcount -= 7;
    // 8003A9C4: lha     r3, 0(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(0);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003A9C8:
    ctx->pc = 0x8003A9C8u;
    // 8003A9C8: extsh r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_8003A9CC:
    ctx->pc = 0x8003A9CCu;
    // 8003A9CC: add   r0, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8003A9D0:
    ctx->pc = 0x8003A9D0u;
    // 8003A9D0: sth     r0, 0(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003A9D4:
    ctx->pc = 0x8003A9D4u;
    // 8003A9D4: lha     r0, 2(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(2);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003A9D8:
    ctx->pc = 0x8003A9D8u;
    // 8003A9D8: add   r0, r0, r4
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8003A9DC:
    ctx->pc = 0x8003A9DCu;
    // 8003A9DC: sth     r0, 2(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003A9E0:
    ctx->pc = 0x8003A9E0u;
    ctx->downcount -= 2;
    // 8003A9E0: cmpwi   r31, 0
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

label_8003A9E4:
    ctx->pc = 0x8003A9E4u;
    // 8003A9E4: bc    4, 2, 0x8003A9F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003A9F4;
        }
    }

label_8003A9E8:
    ctx->pc = 0x8003A9E8u;
    ctx->downcount -= 3;
    // 8003A9E8: lha     r0, 2(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(2);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003A9EC:
    ctx->pc = 0x8003A9ECu;
    // 8003A9EC: subf   r0, r0, r30
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[30];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_8003A9F0:
    ctx->pc = 0x8003A9F0u;
    // 8003A9F0: extsh r30, r0
    {
        ctx->gpr[30] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_8003A9F4:
    ctx->pc = 0x8003A9F4u;
    ctx->downcount -= 6;
    // 8003A9F4: addi    r26, r26, 4
    ctx->gpr[26] = ctx->gpr[26] + (u32)(s32)(4);

label_8003A9F8:
    ctx->pc = 0x8003A9F8u;
    // 8003A9F8: addi    r25, r25, 2
    ctx->gpr[25] = ctx->gpr[25] + (u32)(s32)(2);

label_8003A9FC:
    ctx->pc = 0x8003A9FCu;
    // 8003A9FC: addi    r24, r24, 2
    ctx->gpr[24] = ctx->gpr[24] + (u32)(s32)(2);

label_8003AA00:
    ctx->pc = 0x8003AA00u;
    // 8003AA00: addi    r31, r31, 1
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(1);

label_8003AA04:
    ctx->pc = 0x8003AA04u;
    // 8003AA04: cmpwi   r31, 10
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(10);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003AA08:
    ctx->pc = 0x8003AA08u;
    // 8003AA08: bc    12, 0, 0x8003A69C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = 0x8003A69Cu;
            return;
        }
    }

label_8003AA0C:
    ctx->pc = 0x8003AA0Cu;
    ctx->downcount -= 1;
    // 8003AA0C: lha     r3, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003AA10:
    ctx->pc = 0x8003AA10u;
    ctx->downcount -= 10;
    // 8003AA10: psq_l   f31, 136(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8003AA10u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        ppc_psq_load_inline(ctx, 31u, ea, false, 0u, false, 0x8003AA10u);
        if (ctx->exception) return;
    }

label_8003AA14:
    ctx->pc = 0x8003AA14u;
    // 8003AA14: lfd     f31, 128(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003AA14u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(128);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003AA18:
    ctx->pc = 0x8003AA18u;
    // 8003AA18: psq_l   f30, 120(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8003AA18u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(120);
        ppc_psq_load_inline(ctx, 30u, ea, false, 0u, false, 0x8003AA18u);
        if (ctx->exception) return;
    }

label_8003AA1C:
    ctx->pc = 0x8003AA1Cu;
    // 8003AA1C: lfd     f30, 112(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003AA1Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(112);
        ctx->fpr[30] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003AA20:
    ctx->pc = 0x8003AA20u;
    // 8003AA20: psq_l   f29, 104(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8003AA20u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        ppc_psq_load_inline(ctx, 29u, ea, false, 0u, false, 0x8003AA20u);
        if (ctx->exception) return;
    }

label_8003AA24:
    ctx->pc = 0x8003AA24u;
    // 8003AA24: lfd     f29, 96(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003AA24u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        ctx->fpr[29] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003AA28:
    ctx->pc = 0x8003AA28u;
    // 8003AA28: psq_l   f28, 88(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8003AA28u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        ppc_psq_load_inline(ctx, 28u, ea, false, 0u, false, 0x8003AA28u);
        if (ctx->exception) return;
    }

label_8003AA2C:
    ctx->pc = 0x8003AA2Cu;
    // 8003AA2C: lfd     f28, 80(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003AA2Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        ctx->fpr[28] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003AA30:
    ctx->pc = 0x8003AA30u;
    // 8003AA30: addi    r11, r1, 80
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(80);

label_8003AA34:
    ctx->pc = 0x8003AA34u;
    // 8003AA34: bl      0x80286A8C
    {
            ctx->lr = 0x8003AA38u;
            ctx->pc = 0x80286A8Cu;
            return;
    }

label_8003AA38:
    ctx->pc = 0x8003AA38u;
    ctx->downcount -= 5;
    // 8003AA38: lwz     r0, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003AA3C:
    ctx->pc = 0x8003AA3Cu;
    // 8003AA3C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8003AA40:
    ctx->pc = 0x8003AA40u;
    // 8003AA40: addi    r1, r1, 144
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(144);

label_8003AA44:
    ctx->pc = 0x8003AA44u;
    // 8003AA44: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8003A6E0;
        }
    }

label_8003AA48:
    ctx->pc = 0x8003AA48u;
    ctx->downcount -= 5;
    // 8003AA48: stwu     r1, -48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-48);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8003AA4C:
    ctx->pc = 0x8003AA4Cu;
    // 8003AA4C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8003AA50:
    ctx->pc = 0x8003AA50u;
    // 8003AA50: stw     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003AA54:
    ctx->pc = 0x8003AA54u;
    // 8003AA54: addi    r11, r1, 48
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(48);

label_8003AA58:
    ctx->pc = 0x8003AA58u;
    // 8003AA58: bl      0x80286A44
    {
            ctx->lr = 0x8003AA5Cu;
            ctx->pc = 0x80286A44u;
            return;
    }

label_8003AA5C:
    ctx->pc = 0x8003AA5Cu;
    ctx->downcount -= 7;
    // 8003AA5C: or   r26, r3, r3
    {
        ctx->gpr[26] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003AA60:
    ctx->pc = 0x8003AA60u;
    // 8003AA60: or   r27, r5, r5
    {
        ctx->gpr[27] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8003AA64:
    ctx->pc = 0x8003AA64u;
    // 8003AA64: or   r28, r6, r6
    {
        ctx->gpr[28] = ctx->gpr[6] | ctx->gpr[6];
    }

label_8003AA68:
    ctx->pc = 0x8003AA68u;
    // 8003AA68: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_8003AA6C:
    ctx->pc = 0x8003AA6Cu;
    // 8003AA6C: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_8003AA70:
    ctx->pc = 0x8003AA70u;
    // 8003AA70: or   r31, r4, r4
    {
        ctx->gpr[31] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8003AA74:
    ctx->pc = 0x8003AA74u;
    // 8003AA74: b       0x8003AB24
    {
            goto label_8003AB24;
    }

label_8003AA78:
    ctx->pc = 0x8003AA78u;
    ctx->downcount -= 5;
    // 8003AA78: lwz     r6, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8003AA7C:
    // 8003AA7C: li      r25, 0
    ctx->gpr[25] = (u32)(s32)(0);

label_8003AA80:
    ctx->pc = 0x8003AA80u;
    // 8003AA80: lwz     r4, 80(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(80);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8003AA84:
    // 8003AA84: cmplwi  r4, 0x0000
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

label_8003AA88:
    // 8003AA88: bc    12, 2, 0x8003AAF0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003AAF0;
        }
    }

label_8003AA8C:
    ctx->downcount -= 7;
    // 8003AA8C: or   r5, r25, r25
    {
        ctx->gpr[5] = ctx->gpr[25] | ctx->gpr[25];
    }

label_8003AA90:
    // 8003AA90: or   r7, r25, r25
    {
        ctx->gpr[7] = ctx->gpr[25] | ctx->gpr[25];
    }

label_8003AA94:
    ctx->pc = 0x8003AA94u;
    // 8003AA94: lbz     r0, 90(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(90);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003AA98:
    ctx->pc = 0x8003AA98u;
    // 8003AA98: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8003AA9C:
    // 8003AA9C: cmpwi   r0, 0
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

label_8003AAA0:
    // 8003AAA0: bc    4, 1, 0x8003AAF0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003AAF0;
        }
    }

label_8003AAA4:
    ctx->pc = 0x8003AAA4u;
    ctx->downcount -= 8;
    // 8003AAA4: lwz     r8, 16(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8003AAA8:
    ctx->pc = 0x8003AAA8u;
    // 8003AAA8: lbz     r0, 173(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(173);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003AAAC:
    // 8003AAAC: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8003AAB0:
    // 8003AAB0: add   r3, r0, r5
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8003AAB4:
    // 8003AAB4: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8003AAB8:
    ctx->pc = 0x8003AAB8u;
    // 8003AAB8: lbzx    r0, r8, r0
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[0];
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003AABC:
    // 8003AABC: cmpwi   r0, 255
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(255);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003AAC0:
    // 8003AAC0: bc    12, 2, 0x8003AAD8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003AAD8;
        }
    }

label_8003AAC4:
    ctx->pc = 0x8003AAC4u;
    ctx->downcount -= 3;
    // 8003AAC4: lbzx    r0, r8, r5
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[5];
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003AAC8:
    // 8003AAC8: cmpw    r6, r0
    {
        s32 val_a = (s32)(ctx->gpr[6]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003AACC:
    // 8003AACC: bc    4, 2, 0x8003AAD8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003AAD8;
        }
    }

label_8003AAD0:
    ctx->pc = 0x8003AAD0u;
    ctx->downcount -= 2;
    // 8003AAD0: lwz     r0, 108(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(108);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003AAD4:
    // 8003AAD4: add   r25, r0, r7
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[25] = res;
    }

label_8003AAD8:
    ctx->pc = 0x8003AAD8u;
    ctx->downcount -= 6;
    // 8003AAD8: lbz     r0, 85(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(85);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003AADC:
    // 8003AADC: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8003AAE0:
    // 8003AAE0: add   r5, r0, r5
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[5] = res;
    }

label_8003AAE4:
    // 8003AAE4: addi    r5, r5, 1
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(1);

label_8003AAE8:
    // 8003AAE8: addi    r7, r7, 18
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(18);

label_8003AAEC:
    // 8003AAEC: bc    16, 0, 0x8003AAA4
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003AAA4u;
                return;
            }
            goto label_8003AAA4;
        }
    }

label_8003AAF0:
    ctx->downcount -= 3;
    // 8003AAF0: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8003AAF4:
    // 8003AAF4: or   r4, r25, r25
    {
        ctx->gpr[4] = ctx->gpr[25] | ctx->gpr[25];
    }

label_8003AAF8:
    // 8003AAF8: bl      0x80039B54
    {
            ctx->lr = 0x8003AAFCu;
            ctx->pc = 0x80039B54u;
            return;
    }

label_8003AAFC:
    ctx->downcount -= 6;
    // 8003AAFC: add   r29, r29, r3
    {
        u32 a = ctx->gpr[29];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[29] = res;
    }

label_8003AB00:
    // 8003AB00: addi    r3, r28, 48
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(48);

label_8003AB04:
    // 8003AB04: or   r4, r25, r25
    {
        ctx->gpr[4] = ctx->gpr[25] | ctx->gpr[25];
    }

label_8003AB08:
    ctx->pc = 0x8003AB08u;
    // 8003AB08: lfs     f1, -31520(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003AB08u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31520);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003AB0C:
    ctx->pc = 0x8003AB0Cu;
    // 8003AB0C: lfs     f2, -31516(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003AB0Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31516);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8003AB10:
    // 8003AB10: bl      0x800399C8
    {
            ctx->lr = 0x8003AB14u;
            ctx->pc = 0x800399C8u;
            return;
    }

label_8003AB14:
    ctx->downcount -= 4;
    // 8003AB14: add   r29, r29, r3
    {
        u32 a = ctx->gpr[29];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[29] = res;
    }

label_8003AB18:
    // 8003AB18: addi    r31, r31, 4
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(4);

label_8003AB1C:
    // 8003AB1C: addi    r30, r30, 1
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(1);

label_8003AB20:
    // 8003AB20: addi    r28, r28, 96
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(96);

label_8003AB24:
    ctx->downcount -= 2;
    // 8003AB24: cmpw    r30, r27
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(ctx->gpr[27]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003AB28:
    // 8003AB28: bc    12, 0, 0x8003AA78
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003AA78u;
                return;
            }
            goto label_8003AA78;
        }
    }

label_8003AB2C:
    ctx->pc = 0x8003AB2Cu;
    ctx->downcount -= 6;
    // 8003AB2C: rlwinm r0, r27, 1, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[27], 1u) & 0xFFFFFFFEu;
    }

label_8003AB30:
    ctx->pc = 0x8003AB30u;
    // 8003AB30: subf   r0, r29, r0
    {
        u32 a = ~ctx->gpr[29];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_8003AB34:
    ctx->pc = 0x8003AB34u;
    // 8003AB34: cntlzw r0, r0
    {
        u32 v = ctx->gpr[0];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_8003AB38:
    ctx->pc = 0x8003AB38u;
    // 8003AB38: rlwinm r3, r0, 27, 5, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x07FFFFFFu;
    }

label_8003AB3C:
    ctx->pc = 0x8003AB3Cu;
    // 8003AB3C: addi    r11, r1, 48
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(48);

label_8003AB40:
    ctx->pc = 0x8003AB40u;
    // 8003AB40: bl      0x80286A90
    {
            ctx->lr = 0x8003AB44u;
            ctx->pc = 0x80286A90u;
            return;
    }

label_8003AB44:
    ctx->pc = 0x8003AB44u;
    ctx->downcount -= 5;
    // 8003AB44: lwz     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003AB48:
    ctx->pc = 0x8003AB48u;
    // 8003AB48: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8003AB4C:
    ctx->pc = 0x8003AB4Cu;
    // 8003AB4C: addi    r1, r1, 48
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(48);

label_8003AB50:
    ctx->pc = 0x8003AB50u;
    // 8003AB50: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8003A6E0;
        }
    }

label_8003AB54:
    ctx->pc = 0x8003AB54u;
    ctx->downcount -= 2;
    // 8003AB54: cmpwi   r4, 0
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

label_8003AB58:
    ctx->pc = 0x8003AB58u;
    // 8003AB58: bclr  4, 1
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8003A6E0;
        }
    }

label_8003AB5C:
    ctx->pc = 0x8003AB5Cu;
    ctx->downcount -= 5;
    // 8003AB5C: rlwinm r0, r4, 29, 3, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 29u) & 0x1FFFFFFFu;
    }

label_8003AB60:
    ctx->pc = 0x8003AB60u;
    // 8003AB60: cmplwi  r0, 0x0000
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

label_8003AB64:
    ctx->pc = 0x8003AB64u;
    // 8003AB64: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8003AB68:
    ctx->pc = 0x8003AB68u;
    // 8003AB68: bc    12, 2, 0x8003ABBC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003ABBC;
        }
    }

label_8003AB6C:
    loop_8003AB6C(ctx);
    if (ctx->pc == 0x8003ABB4u) goto label_8003ABB4;
    return;
label_8003AB70:
    ctx->pc = 0x8003AB70u;
    // 8003AB70: sth     r6, 68(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(68);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_8003AB74:
    ctx->pc = 0x8003AB74u;
    // 8003AB74: sth     r5, 116(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(116);
        mem_write16(ctx, ea, (u16)ctx->gpr[5]);
    }

label_8003AB78:
    ctx->pc = 0x8003AB78u;
    // 8003AB78: sth     r6, 164(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(164);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_8003AB7C:
    ctx->pc = 0x8003AB7Cu;
    // 8003AB7C: sth     r5, 212(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(212);
        mem_write16(ctx, ea, (u16)ctx->gpr[5]);
    }

label_8003AB80:
    ctx->pc = 0x8003AB80u;
    // 8003AB80: sth     r6, 260(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(260);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_8003AB84:
    ctx->pc = 0x8003AB84u;
    // 8003AB84: sth     r5, 308(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(308);
        mem_write16(ctx, ea, (u16)ctx->gpr[5]);
    }

label_8003AB88:
    ctx->pc = 0x8003AB88u;
    // 8003AB88: sth     r6, 356(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(356);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_8003AB8C:
    ctx->pc = 0x8003AB8Cu;
    // 8003AB8C: sth     r5, 404(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(404);
        mem_write16(ctx, ea, (u16)ctx->gpr[5]);
    }

label_8003AB90:
    ctx->pc = 0x8003AB90u;
    // 8003AB90: sth     r6, 452(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(452);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_8003AB94:
    ctx->pc = 0x8003AB94u;
    // 8003AB94: sth     r5, 500(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(500);
        mem_write16(ctx, ea, (u16)ctx->gpr[5]);
    }

label_8003AB98:
    ctx->pc = 0x8003AB98u;
    // 8003AB98: sth     r6, 548(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(548);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_8003AB9C:
    ctx->pc = 0x8003AB9Cu;
    // 8003AB9C: sth     r5, 596(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(596);
        mem_write16(ctx, ea, (u16)ctx->gpr[5]);
    }

label_8003ABA0:
    ctx->pc = 0x8003ABA0u;
    // 8003ABA0: sth     r6, 644(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(644);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_8003ABA4:
    ctx->pc = 0x8003ABA4u;
    // 8003ABA4: sth     r5, 692(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(692);
        mem_write16(ctx, ea, (u16)ctx->gpr[5]);
    }

label_8003ABA8:
    ctx->pc = 0x8003ABA8u;
    // 8003ABA8: sth     r6, 740(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(740);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_8003ABAC:
    // 8003ABAC: addi    r3, r3, 768
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(768);

label_8003ABB0:
    // 8003ABB0: bc    16, 0, 0x8003AB6C
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003AB6Cu;
                return;
            }
            goto label_8003AB6C;
        }
    }

label_8003ABB4:
    ctx->pc = 0x8003ABB4u;
    ctx->downcount -= 2;
    // 8003ABB4: andi.   r4, r4, 0x0007
    {
        ctx->gpr[4] = ctx->gpr[4] & 0x0007u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[4];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8003ABB8:
    ctx->pc = 0x8003ABB8u;
    // 8003ABB8: bclr  12, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8003A6E0;
        }
    }

label_8003ABBC:
    ctx->pc = 0x8003ABBCu;
    ctx->downcount -= 2;
    // 8003ABBC: mtctr    r4
    ctx->ctr = ctx->gpr[4];

label_8003ABC0:
    loop_8003ABC0(ctx);
    if (ctx->pc == 0x8003ABD0u) goto label_8003ABD0;
    return;
label_8003ABC4:
    ctx->pc = 0x8003ABC4u;
    // 8003ABC4: sth     r6, 68(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(68);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_8003ABC8:
    // 8003ABC8: addi    r3, r3, 96
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(96);

label_8003ABCC:
    // 8003ABCC: bc    16, 0, 0x8003ABC0
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003ABC0u;
                return;
            }
            goto label_8003ABC0;
        }
    }

label_8003ABD0:
    ctx->pc = 0x8003ABD0u;
    ctx->downcount -= 1;
    // 8003ABD0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8003A6E0;
        }
    }

label_8003ABD4:
    ctx->pc = 0x8003ABD4u;
    ctx->downcount -= 1;
    // 8003ABD4: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_8003ABD8:
    ctx->downcount -= 4;
    // 8003ABD8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003ABDC:
    ctx->pc = 0x8003ABDCu;
    // 8003ABDC: lwz     r6, 80(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(80);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8003ABE0:
    // 8003ABE0: cmplwi  r6, 0x0000
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

label_8003ABE4:
    // 8003ABE4: bc    12, 2, 0x8003AC4C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003AC4C;
        }
    }

label_8003ABE8:
    ctx->downcount -= 7;
    // 8003ABE8: or   r7, r5, r5
    {
        ctx->gpr[7] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8003ABEC:
    // 8003ABEC: or   r8, r5, r5
    {
        ctx->gpr[8] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8003ABF0:
    ctx->pc = 0x8003ABF0u;
    // 8003ABF0: lbz     r0, 90(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(90);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003ABF4:
    ctx->pc = 0x8003ABF4u;
    // 8003ABF4: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8003ABF8:
    // 8003ABF8: cmpwi   r0, 0
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

label_8003ABFC:
    // 8003ABFC: bc    4, 1, 0x8003AC4C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003AC4C;
        }
    }

label_8003AC00:
    ctx->pc = 0x8003AC00u;
    ctx->downcount -= 8;
    // 8003AC00: lwz     r9, 16(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8003AC04:
    ctx->pc = 0x8003AC04u;
    // 8003AC04: lbz     r0, 173(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(173);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003AC08:
    // 8003AC08: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8003AC0C:
    // 8003AC0C: add   r4, r0, r7
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_8003AC10:
    // 8003AC10: addi    r0, r4, 1
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(1);

label_8003AC14:
    ctx->pc = 0x8003AC14u;
    // 8003AC14: lbzx    r0, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003AC18:
    // 8003AC18: cmpwi   r0, 255
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(255);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003AC1C:
    // 8003AC1C: bc    12, 2, 0x8003AC34
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003AC34;
        }
    }

label_8003AC20:
    ctx->pc = 0x8003AC20u;
    ctx->downcount -= 3;
    // 8003AC20: lbzx    r0, r9, r7
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[7];
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003AC24:
    // 8003AC24: cmpw    r10, r0
    {
        s32 val_a = (s32)(ctx->gpr[10]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003AC28:
    // 8003AC28: bc    4, 2, 0x8003AC34
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003AC34;
        }
    }

label_8003AC2C:
    ctx->pc = 0x8003AC2Cu;
    ctx->downcount -= 2;
    // 8003AC2C: lwz     r0, 108(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(108);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003AC30:
    // 8003AC30: add   r5, r0, r8
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[8];
        u32 res = a + b;
        ctx->gpr[5] = res;
    }

label_8003AC34:
    ctx->pc = 0x8003AC34u;
    ctx->downcount -= 6;
    // 8003AC34: lbz     r0, 85(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(85);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003AC38:
    // 8003AC38: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8003AC3C:
    // 8003AC3C: add   r7, r0, r7
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_8003AC40:
    // 8003AC40: addi    r7, r7, 1
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(1);

label_8003AC44:
    // 8003AC44: addi    r8, r8, 18
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(18);

label_8003AC48:
    // 8003AC48: bc    16, 0, 0x8003AC00
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003AC00u;
                return;
            }
            goto label_8003AC00;
        }
    }

label_8003AC4C:
    ctx->downcount -= 2;
    // 8003AC4C: cmplwi  r5, 0x0000
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

label_8003AC50:
    // 8003AC50: bc    12, 2, 0x8003AC64
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003AC64;
        }
    }

label_8003AC54:
    ctx->downcount -= 4;
    // 8003AC54: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8003AC58:
    ctx->pc = 0x8003AC58u;
    // 8003AC58: sth     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003AC5C:
    ctx->pc = 0x8003AC5Cu;
    // 8003AC5C: sth     r0, 2(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003AC60:
    ctx->pc = 0x8003AC60u;
    // 8003AC60: sth     r0, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003AC64:
    ctx->downcount -= 3;
    // 8003AC64: addi    r10, r10, 1
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(1);

label_8003AC68:
    // 8003AC68: cmpwi   r10, 22
    {
        s32 val_a = (s32)(ctx->gpr[10]);
        s32 val_b = (s32)(22);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003AC6C:
    // 8003AC6C: bc    12, 0, 0x8003ABD8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003ABD8u;
                return;
            }
            goto label_8003ABD8;
        }
    }

label_8003AC70:
    ctx->pc = 0x8003AC70u;
    ctx->downcount -= 1;
    // 8003AC70: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8003A6E0;
        }
    }

label_8003AC74:
    ctx->pc = 0x8003AC74u;
    ctx->downcount -= 6;
    // 8003AC74: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8003AC78:
    ctx->pc = 0x8003AC78u;
    // 8003AC78: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8003AC7C:
    ctx->pc = 0x8003AC7Cu;
    // 8003AC7C: stw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8003AC80:
    ctx->pc = 0x8003AC80u;
    // 8003AC80: stw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_8003AC84:
    ctx->pc = 0x8003AC84u;
    // 8003AC84: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8003AC88:
    ctx->pc = 0x8003AC88u;
    // 8003AC88: b       0x8003AD8C
    {
            goto label_8003AD8C;
    }

label_8003AC8C:
    ctx->pc = 0x8003AC8Cu;
    ctx->downcount -= 5;
    // 8003AC8C: lwz     r31, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8003AC90:
    // 8003AC90: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_8003AC94:
    ctx->pc = 0x8003AC94u;
    // 8003AC94: lwz     r11, 80(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(80);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8003AC98:
    // 8003AC98: cmplwi  r11, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[11]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003AC9C:
    // 8003AC9C: bc    12, 2, 0x8003AD04
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003AD04;
        }
    }

label_8003ACA0:
    ctx->downcount -= 7;
    // 8003ACA0: or   r12, r10, r10
    {
        ctx->gpr[12] = ctx->gpr[10] | ctx->gpr[10];
    }

label_8003ACA4:
    // 8003ACA4: or   r30, r10, r10
    {
        ctx->gpr[30] = ctx->gpr[10] | ctx->gpr[10];
    }

label_8003ACA8:
    ctx->pc = 0x8003ACA8u;
    // 8003ACA8: lbz     r0, 90(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(90);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003ACAC:
    ctx->pc = 0x8003ACACu;
    // 8003ACAC: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8003ACB0:
    // 8003ACB0: cmpwi   r0, 0
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

label_8003ACB4:
    // 8003ACB4: bc    4, 1, 0x8003AD04
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003AD04;
        }
    }

label_8003ACB8:
    ctx->pc = 0x8003ACB8u;
    ctx->downcount -= 8;
    // 8003ACB8: lwz     r29, 16(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(16);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_8003ACBC:
    ctx->pc = 0x8003ACBCu;
    // 8003ACBC: lbz     r0, 173(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(173);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003ACC0:
    // 8003ACC0: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8003ACC4:
    // 8003ACC4: add   r9, r0, r12
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[12];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_8003ACC8:
    // 8003ACC8: addi    r0, r9, 1
    ctx->gpr[0] = ctx->gpr[9] + (u32)(s32)(1);

label_8003ACCC:
    ctx->pc = 0x8003ACCCu;
    // 8003ACCC: lbzx    r0, r29, r0
    {
        u32 ea = ctx->gpr[29] + ctx->gpr[0];
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003ACD0:
    // 8003ACD0: cmpwi   r0, 255
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(255);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003ACD4:
    // 8003ACD4: bc    12, 2, 0x8003ACEC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003ACEC;
        }
    }

label_8003ACD8:
    ctx->pc = 0x8003ACD8u;
    ctx->downcount -= 3;
    // 8003ACD8: lbzx    r0, r29, r12
    {
        u32 ea = ctx->gpr[29] + ctx->gpr[12];
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003ACDC:
    // 8003ACDC: cmpw    r31, r0
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003ACE0:
    // 8003ACE0: bc    4, 2, 0x8003ACEC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003ACEC;
        }
    }

label_8003ACE4:
    ctx->pc = 0x8003ACE4u;
    ctx->downcount -= 2;
    // 8003ACE4: lwz     r0, 108(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(108);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003ACE8:
    // 8003ACE8: add   r10, r0, r30
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[10] = res;
    }

label_8003ACEC:
    ctx->pc = 0x8003ACECu;
    ctx->downcount -= 6;
    // 8003ACEC: lbz     r0, 85(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(85);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003ACF0:
    // 8003ACF0: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8003ACF4:
    // 8003ACF4: add   r12, r0, r12
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[12];
        u32 res = a + b;
        ctx->gpr[12] = res;
    }

label_8003ACF8:
    // 8003ACF8: addi    r12, r12, 1
    ctx->gpr[12] = ctx->gpr[12] + (u32)(s32)(1);

label_8003ACFC:
    // 8003ACFC: addi    r30, r30, 18
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(18);

label_8003AD00:
    // 8003AD00: bc    16, 0, 0x8003ACB8
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003ACB8u;
                return;
            }
            goto label_8003ACB8;
        }
    }

label_8003AD04:
    ctx->downcount -= 2;
    // 8003AD04: cmplwi  r10, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[10]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003AD08:
    // 8003AD08: bc    12, 2, 0x8003AD84
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003AD84;
        }
    }

label_8003AD0C:
    ctx->pc = 0x8003AD0Cu;
    ctx->downcount -= 3;
    // 8003AD0C: lha     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003AD10:
    // 8003AD10: cmpw    r0, r6
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[6]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003AD14:
    // 8003AD14: bc    4, 0, 0x8003AD20
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003AD20;
        }
    }

label_8003AD18:
    ctx->downcount -= 2;
    // 8003AD18: or   r0, r6, r6
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[6];
    }

label_8003AD1C:
    // 8003AD1C: b       0x8003AD2C
    {
            goto label_8003AD2C;
    }

label_8003AD20:
    ctx->downcount -= 2;
    // 8003AD20: cmpw    r0, r7
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[7]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003AD24:
    // 8003AD24: bc    4, 1, 0x8003AD2C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003AD2C;
        }
    }

label_8003AD28:
    ctx->downcount -= 1;
    // 8003AD28: or   r0, r7, r7
    {
        ctx->gpr[0] = ctx->gpr[7] | ctx->gpr[7];
    }

label_8003AD2C:
    ctx->downcount -= 5;
    // 8003AD2C: extsh r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_8003AD30:
    ctx->pc = 0x8003AD30u;
    // 8003AD30: sth     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003AD34:
    ctx->pc = 0x8003AD34u;
    // 8003AD34: lha     r0, 2(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(2);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003AD38:
    // 8003AD38: cmpw    r0, r6
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[6]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003AD3C:
    // 8003AD3C: bc    4, 0, 0x8003AD48
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003AD48;
        }
    }

label_8003AD40:
    ctx->downcount -= 2;
    // 8003AD40: or   r0, r6, r6
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[6];
    }

label_8003AD44:
    // 8003AD44: b       0x8003AD54
    {
            goto label_8003AD54;
    }

label_8003AD48:
    ctx->downcount -= 2;
    // 8003AD48: cmpw    r0, r7
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[7]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003AD4C:
    // 8003AD4C: bc    4, 1, 0x8003AD54
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003AD54;
        }
    }

label_8003AD50:
    ctx->downcount -= 1;
    // 8003AD50: or   r0, r7, r7
    {
        ctx->gpr[0] = ctx->gpr[7] | ctx->gpr[7];
    }

label_8003AD54:
    ctx->downcount -= 5;
    // 8003AD54: extsh r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_8003AD58:
    ctx->pc = 0x8003AD58u;
    // 8003AD58: sth     r0, 2(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003AD5C:
    ctx->pc = 0x8003AD5Cu;
    // 8003AD5C: lha     r0, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003AD60:
    // 8003AD60: cmpw    r0, r6
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[6]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003AD64:
    // 8003AD64: bc    4, 0, 0x8003AD70
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003AD70;
        }
    }

label_8003AD68:
    ctx->downcount -= 2;
    // 8003AD68: or   r0, r6, r6
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[6];
    }

label_8003AD6C:
    // 8003AD6C: b       0x8003AD7C
    {
            goto label_8003AD7C;
    }

label_8003AD70:
    ctx->downcount -= 2;
    // 8003AD70: cmpw    r0, r7
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[7]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003AD74:
    // 8003AD74: bc    4, 1, 0x8003AD7C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003AD7C;
        }
    }

label_8003AD78:
    ctx->downcount -= 1;
    // 8003AD78: or   r0, r7, r7
    {
        ctx->gpr[0] = ctx->gpr[7] | ctx->gpr[7];
    }

label_8003AD7C:
    ctx->downcount -= 2;
    // 8003AD7C: extsh r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_8003AD80:
    ctx->pc = 0x8003AD80u;
    // 8003AD80: sth     r0, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003AD84:
    ctx->downcount -= 2;
    // 8003AD84: addi    r4, r4, 4
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(4);

label_8003AD88:
    // 8003AD88: addi    r8, r8, 1
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(1);

label_8003AD8C:
    ctx->downcount -= 2;
    // 8003AD8C: cmpw    r8, r5
    {
        s32 val_a = (s32)(ctx->gpr[8]);
        s32 val_b = (s32)(ctx->gpr[5]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003AD90:
    // 8003AD90: bc    12, 0, 0x8003AC8C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003AC8Cu;
                return;
            }
            goto label_8003AC8C;
        }
    }

label_8003AD94:
    ctx->pc = 0x8003AD94u;
    ctx->downcount -= 5;
    // 8003AD94: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8003AD98:
    ctx->pc = 0x8003AD98u;
    // 8003AD98: lwz     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8003AD9C:
    ctx->pc = 0x8003AD9Cu;
    // 8003AD9C: lwz     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_8003ADA0:
    ctx->pc = 0x8003ADA0u;
    // 8003ADA0: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_8003ADA4:
    ctx->pc = 0x8003ADA4u;
    // 8003ADA4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8003A6E0;
        }
    }

label_8003ADA8:
    ctx->pc = 0x8003ADA8u;
    ctx->downcount -= 4;
    // 8003ADA8: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8003ADAC:
    ctx->pc = 0x8003ADACu;
    // 8003ADAC: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8003ADB0:
    ctx->pc = 0x8003ADB0u;
    // 8003ADB0: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8003ADB4:
    ctx->pc = 0x8003ADB4u;
    // 8003ADB4: b       0x8003AE7C
    {
            goto label_8003AE7C;
    }

label_8003ADB8:
    ctx->pc = 0x8003ADB8u;
    ctx->downcount -= 5;
    // 8003ADB8: lwz     r11, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8003ADBC:
    // 8003ADBC: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8003ADC0:
    ctx->pc = 0x8003ADC0u;
    // 8003ADC0: lwz     r9, 80(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(80);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8003ADC4:
    // 8003ADC4: cmplwi  r9, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[9]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003ADC8:
    // 8003ADC8: bc    12, 2, 0x8003AE30
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003AE30;
        }
    }

label_8003ADCC:
    ctx->downcount -= 7;
    // 8003ADCC: or   r10, r8, r8
    {
        ctx->gpr[10] = ctx->gpr[8] | ctx->gpr[8];
    }

label_8003ADD0:
    // 8003ADD0: or   r12, r8, r8
    {
        ctx->gpr[12] = ctx->gpr[8] | ctx->gpr[8];
    }

label_8003ADD4:
    ctx->pc = 0x8003ADD4u;
    // 8003ADD4: lbz     r0, 90(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(90);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003ADD8:
    ctx->pc = 0x8003ADD8u;
    // 8003ADD8: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8003ADDC:
    // 8003ADDC: cmpwi   r0, 0
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

label_8003ADE0:
    // 8003ADE0: bc    4, 1, 0x8003AE30
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003AE30;
        }
    }

label_8003ADE4:
    ctx->pc = 0x8003ADE4u;
    ctx->downcount -= 8;
    // 8003ADE4: lwz     r31, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8003ADE8:
    ctx->pc = 0x8003ADE8u;
    // 8003ADE8: lbz     r0, 173(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(173);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003ADEC:
    // 8003ADEC: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8003ADF0:
    // 8003ADF0: add   r7, r0, r10
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[10];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_8003ADF4:
    // 8003ADF4: addi    r0, r7, 1
    ctx->gpr[0] = ctx->gpr[7] + (u32)(s32)(1);

label_8003ADF8:
    ctx->pc = 0x8003ADF8u;
    // 8003ADF8: lbzx    r0, r31, r0
    {
        u32 ea = ctx->gpr[31] + ctx->gpr[0];
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003ADFC:
    // 8003ADFC: cmpwi   r0, 255
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(255);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003AE00:
    // 8003AE00: bc    12, 2, 0x8003AE18
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003AE18;
        }
    }

label_8003AE04:
    ctx->pc = 0x8003AE04u;
    ctx->downcount -= 3;
    // 8003AE04: lbzx    r0, r31, r10
    {
        u32 ea = ctx->gpr[31] + ctx->gpr[10];
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003AE08:
    // 8003AE08: cmpw    r11, r0
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003AE0C:
    // 8003AE0C: bc    4, 2, 0x8003AE18
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003AE18;
        }
    }

label_8003AE10:
    ctx->pc = 0x8003AE10u;
    ctx->downcount -= 2;
    // 8003AE10: lwz     r0, 108(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(108);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003AE14:
    // 8003AE14: add   r8, r0, r12
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[12];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_8003AE18:
    ctx->pc = 0x8003AE18u;
    ctx->downcount -= 6;
    // 8003AE18: lbz     r0, 85(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(85);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003AE1C:
    // 8003AE1C: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8003AE20:
    // 8003AE20: add   r10, r0, r10
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[10];
        u32 res = a + b;
        ctx->gpr[10] = res;
    }

label_8003AE24:
    // 8003AE24: addi    r10, r10, 1
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(1);

label_8003AE28:
    // 8003AE28: addi    r12, r12, 18
    ctx->gpr[12] = ctx->gpr[12] + (u32)(s32)(18);

label_8003AE2C:
    // 8003AE2C: bc    16, 0, 0x8003ADE4
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003ADE4u;
                return;
            }
            goto label_8003ADE4;
        }
    }

label_8003AE30:
    ctx->downcount -= 2;
    // 8003AE30: cmplwi  r8, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[8]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003AE34:
    // 8003AE34: bc    12, 2, 0x8003AE74
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003AE74;
        }
    }

label_8003AE38:
    ctx->pc = 0x8003AE38u;
    ctx->downcount -= 21;
    // 8003AE38: lha     r0, 2(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(2);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003AE3C:
    // 8003AE3C: mulli   r0, r0, 3
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)3);

label_8003AE40:
    // 8003AE40: srawi r0, r0, 2
    {
        u32 sh = 2u;
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

label_8003AE44:
    // 8003AE44: extsh r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_8003AE48:
    ctx->pc = 0x8003AE48u;
    // 8003AE48: sth     r0, 2(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003AE4C:
    ctx->pc = 0x8003AE4Cu;
    // 8003AE4C: lha     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003AE50:
    // 8003AE50: mulli   r0, r0, 3
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)3);

label_8003AE54:
    // 8003AE54: srawi r0, r0, 2
    {
        u32 sh = 2u;
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

label_8003AE58:
    // 8003AE58: extsh r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_8003AE5C:
    ctx->pc = 0x8003AE5Cu;
    // 8003AE5C: sth     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003AE60:
    ctx->pc = 0x8003AE60u;
    // 8003AE60: lha     r0, 4(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(4);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003AE64:
    // 8003AE64: mulli   r0, r0, 3
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)3);

label_8003AE68:
    // 8003AE68: srawi r0, r0, 2
    {
        u32 sh = 2u;
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

label_8003AE6C:
    // 8003AE6C: extsh r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_8003AE70:
    ctx->pc = 0x8003AE70u;
    // 8003AE70: sth     r0, 4(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003AE74:
    ctx->downcount -= 2;
    // 8003AE74: addi    r4, r4, 4
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(4);

label_8003AE78:
    // 8003AE78: addi    r6, r6, 1
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(1);

label_8003AE7C:
    ctx->downcount -= 2;
    // 8003AE7C: cmpw    r6, r5
    {
        s32 val_a = (s32)(ctx->gpr[6]);
        s32 val_b = (s32)(ctx->gpr[5]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003AE80:
    // 8003AE80: bc    12, 0, 0x8003ADB8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003ADB8u;
                return;
            }
            goto label_8003ADB8;
        }
    }

label_8003AE84:
    ctx->pc = 0x8003AE84u;
    ctx->downcount -= 3;
    // 8003AE84: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8003AE88:
    ctx->pc = 0x8003AE88u;
    // 8003AE88: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8003AE8C:
    ctx->pc = 0x8003AE8Cu;
    // 8003AE8C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8003A6E0;
        }
    }

label_8003AE90:
    ctx->pc = 0x8003AE90u;
    ctx->downcount -= 5;
    // 8003AE90: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8003AE94:
    ctx->pc = 0x8003AE94u;
    // 8003AE94: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8003AE98:
    ctx->pc = 0x8003AE98u;
    // 8003AE98: stw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8003AE9C:
    ctx->pc = 0x8003AE9Cu;
    // 8003AE9C: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_8003AEA0:
    ctx->pc = 0x8003AEA0u;
    // 8003AEA0: b       0x8003AF40
    {
            goto label_8003AF40;
    }

label_8003AEA4:
    ctx->pc = 0x8003AEA4u;
    ctx->downcount -= 5;
    // 8003AEA4: lwz     r11, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8003AEA8:
    // 8003AEA8: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8003AEAC:
    ctx->pc = 0x8003AEACu;
    // 8003AEAC: lwz     r9, 80(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(80);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8003AEB0:
    // 8003AEB0: cmplwi  r9, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[9]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003AEB4:
    // 8003AEB4: bc    12, 2, 0x8003AF1C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003AF1C;
        }
    }

label_8003AEB8:
    ctx->downcount -= 7;
    // 8003AEB8: or   r10, r8, r8
    {
        ctx->gpr[10] = ctx->gpr[8] | ctx->gpr[8];
    }

label_8003AEBC:
    // 8003AEBC: or   r12, r8, r8
    {
        ctx->gpr[12] = ctx->gpr[8] | ctx->gpr[8];
    }

label_8003AEC0:
    ctx->pc = 0x8003AEC0u;
    // 8003AEC0: lbz     r0, 90(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(90);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003AEC4:
    ctx->pc = 0x8003AEC4u;
    // 8003AEC4: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8003AEC8:
    // 8003AEC8: cmpwi   r0, 0
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

label_8003AECC:
    // 8003AECC: bc    4, 1, 0x8003AF1C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003AF1C;
        }
    }

label_8003AED0:
    ctx->pc = 0x8003AED0u;
    ctx->downcount -= 8;
    // 8003AED0: lwz     r31, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8003AED4:
    ctx->pc = 0x8003AED4u;
    // 8003AED4: lbz     r0, 173(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(173);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003AED8:
    // 8003AED8: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8003AEDC:
    // 8003AEDC: add   r7, r0, r10
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[10];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_8003AEE0:
    // 8003AEE0: addi    r0, r7, 1
    ctx->gpr[0] = ctx->gpr[7] + (u32)(s32)(1);

label_8003AEE4:
    ctx->pc = 0x8003AEE4u;
    // 8003AEE4: lbzx    r0, r31, r0
    {
        u32 ea = ctx->gpr[31] + ctx->gpr[0];
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003AEE8:
    // 8003AEE8: cmpwi   r0, 255
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(255);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003AEEC:
    // 8003AEEC: bc    12, 2, 0x8003AF04
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003AF04;
        }
    }

label_8003AEF0:
    ctx->pc = 0x8003AEF0u;
    ctx->downcount -= 3;
    // 8003AEF0: lbzx    r0, r31, r10
    {
        u32 ea = ctx->gpr[31] + ctx->gpr[10];
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003AEF4:
    // 8003AEF4: cmpw    r11, r0
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003AEF8:
    // 8003AEF8: bc    4, 2, 0x8003AF04
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003AF04;
        }
    }

label_8003AEFC:
    ctx->pc = 0x8003AEFCu;
    ctx->downcount -= 2;
    // 8003AEFC: lwz     r0, 108(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(108);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003AF00:
    // 8003AF00: add   r8, r0, r12
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[12];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_8003AF04:
    ctx->pc = 0x8003AF04u;
    ctx->downcount -= 6;
    // 8003AF04: lbz     r0, 85(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(85);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003AF08:
    // 8003AF08: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8003AF0C:
    // 8003AF0C: add   r10, r0, r10
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[10];
        u32 res = a + b;
        ctx->gpr[10] = res;
    }

label_8003AF10:
    // 8003AF10: addi    r10, r10, 1
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(1);

label_8003AF14:
    // 8003AF14: addi    r12, r12, 18
    ctx->gpr[12] = ctx->gpr[12] + (u32)(s32)(18);

label_8003AF18:
    // 8003AF18: bc    16, 0, 0x8003AED0
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003AED0u;
                return;
            }
            goto label_8003AED0;
        }
    }

label_8003AF1C:
    ctx->downcount -= 2;
    // 8003AF1C: cmplwi  r8, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[8]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003AF20:
    // 8003AF20: bc    12, 2, 0x8003AF34
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003AF34;
        }
    }

label_8003AF24:
    ctx->pc = 0x8003AF24u;
    ctx->downcount -= 4;
    // 8003AF24: lha     r0, 2(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(2);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003AF28:
    ctx->pc = 0x8003AF28u;
    // 8003AF28: sth     r0, 22(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(22);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003AF2C:
    ctx->pc = 0x8003AF2Cu;
    // 8003AF2C: lha     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003AF30:
    ctx->pc = 0x8003AF30u;
    // 8003AF30: sth     r0, 70(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(70);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003AF34:
    ctx->downcount -= 3;
    // 8003AF34: addi    r4, r4, 4
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(4);

label_8003AF38:
    // 8003AF38: addi    r30, r30, 1
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(1);

label_8003AF3C:
    // 8003AF3C: addi    r6, r6, 96
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(96);

label_8003AF40:
    ctx->downcount -= 2;
    // 8003AF40: cmpw    r30, r5
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(ctx->gpr[5]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003AF44:
    // 8003AF44: bc    12, 0, 0x8003AEA4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003AEA4u;
                return;
            }
            goto label_8003AEA4;
        }
    }

label_8003AF48:
    ctx->pc = 0x8003AF48u;
    ctx->downcount -= 4;
    // 8003AF48: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8003AF4C:
    ctx->pc = 0x8003AF4Cu;
    // 8003AF4C: lwz     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8003AF50:
    ctx->pc = 0x8003AF50u;
    // 8003AF50: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8003AF54:
    ctx->pc = 0x8003AF54u;
    // 8003AF54: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8003A6E0;
        }
    }

label_8003AF58:
    ctx->pc = 0x8003AF58u;
    ctx->downcount -= 13;
    // 8003AF58: stwu     r1, -144(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-144);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8003AF5C:
    ctx->pc = 0x8003AF5Cu;
    // 8003AF5C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8003AF60:
    ctx->pc = 0x8003AF60u;
    // 8003AF60: stw     r0, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003AF64:
    ctx->pc = 0x8003AF64u;
    // 8003AF64: stfd     f31, 128(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003AF64u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(128);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_8003AF68:
    ctx->pc = 0x8003AF68u;
    // 8003AF68: psq_st   f31, 136(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8003AF68u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        ppc_psq_store_inline(ctx, 31u, ea, false, 0u, false, 0x8003AF68u);
        if (ctx->exception) return;
    }

label_8003AF6C:
    ctx->pc = 0x8003AF6Cu;
    // 8003AF6C: stfd     f30, 112(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003AF6Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(112);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[30]));
    }

label_8003AF70:
    ctx->pc = 0x8003AF70u;
    // 8003AF70: psq_st   f30, 120(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8003AF70u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(120);
        ppc_psq_store_inline(ctx, 30u, ea, false, 0u, false, 0x8003AF70u);
        if (ctx->exception) return;
    }

label_8003AF74:
    ctx->pc = 0x8003AF74u;
    // 8003AF74: stfd     f29, 96(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003AF74u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[29]));
    }

label_8003AF78:
    ctx->pc = 0x8003AF78u;
    // 8003AF78: psq_st   f29, 104(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8003AF78u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        ppc_psq_store_inline(ctx, 29u, ea, false, 0u, false, 0x8003AF78u);
        if (ctx->exception) return;
    }

label_8003AF7C:
    ctx->pc = 0x8003AF7Cu;
    // 8003AF7C: stfd     f28, 80(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003AF7Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[28]));
    }

label_8003AF80:
    ctx->pc = 0x8003AF80u;
    // 8003AF80: psq_st   f28, 88(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8003AF80u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        ppc_psq_store_inline(ctx, 28u, ea, false, 0u, false, 0x8003AF80u);
        if (ctx->exception) return;
    }

label_8003AF84:
    ctx->pc = 0x8003AF84u;
    // 8003AF84: addi    r11, r1, 80
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(80);

label_8003AF88:
    ctx->pc = 0x8003AF88u;
    // 8003AF88: bl      0x80286A48
    {
            ctx->lr = 0x8003AF8Cu;
            ctx->pc = 0x80286A48u;
            return;
    }

label_8003AF8C:
    ctx->pc = 0x8003AF8Cu;
    ctx->downcount -= 9;
    // 8003AF8C: or   r26, r3, r3
    {
        ctx->gpr[26] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003AF90:
    ctx->pc = 0x8003AF90u;
    // 8003AF90: or   r27, r5, r5
    {
        ctx->gpr[27] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8003AF94:
    ctx->pc = 0x8003AF94u;
    // 8003AF94: or   r28, r6, r6
    {
        ctx->gpr[28] = ctx->gpr[6] | ctx->gpr[6];
    }

label_8003AF98:
    ctx->pc = 0x8003AF98u;
    // 8003AF98: or   r29, r7, r7
    {
        ctx->gpr[29] = ctx->gpr[7] | ctx->gpr[7];
    }

label_8003AF9C:
    ctx->pc = 0x8003AF9Cu;
    // 8003AF9C: or   r30, r8, r8
    {
        ctx->gpr[30] = ctx->gpr[8] | ctx->gpr[8];
    }

label_8003AFA0:
    ctx->pc = 0x8003AFA0u;
    // 8003AFA0: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_8003AFA4:
    ctx->pc = 0x8003AFA4u;
    // 8003AFA4: lwz     r5, 80(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(80);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8003AFA8:
    ctx->pc = 0x8003AFA8u;
    // 8003AFA8: cmplwi  r5, 0x0000
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

label_8003AFAC:
    ctx->pc = 0x8003AFACu;
    // 8003AFAC: bc    12, 2, 0x8003B014
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003B014;
        }
    }

label_8003AFB0:
    ctx->pc = 0x8003AFB0u;
    ctx->downcount -= 7;
    // 8003AFB0: or   r6, r31, r31
    {
        ctx->gpr[6] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8003AFB4:
    ctx->pc = 0x8003AFB4u;
    // 8003AFB4: or   r7, r31, r31
    {
        ctx->gpr[7] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8003AFB8:
    ctx->pc = 0x8003AFB8u;
    // 8003AFB8: lbz     r0, 90(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(90);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003AFBC:
    ctx->pc = 0x8003AFBCu;
    // 8003AFBC: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8003AFC0:
    ctx->pc = 0x8003AFC0u;
    // 8003AFC0: cmpwi   r0, 0
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

label_8003AFC4:
    ctx->pc = 0x8003AFC4u;
    // 8003AFC4: bc    4, 1, 0x8003B014
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003B014;
        }
    }

label_8003AFC8:
    ctx->pc = 0x8003AFC8u;
    ctx->downcount -= 8;
    // 8003AFC8: lwz     r8, 16(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(16);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8003AFCC:
    ctx->pc = 0x8003AFCCu;
    // 8003AFCC: lbz     r0, 173(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(173);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003AFD0:
    // 8003AFD0: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8003AFD4:
    // 8003AFD4: add   r3, r0, r6
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8003AFD8:
    // 8003AFD8: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8003AFDC:
    ctx->pc = 0x8003AFDCu;
    // 8003AFDC: lbzx    r0, r8, r0
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[0];
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003AFE0:
    // 8003AFE0: cmpwi   r0, 255
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(255);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003AFE4:
    // 8003AFE4: bc    12, 2, 0x8003AFFC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003AFFC;
        }
    }

label_8003AFE8:
    ctx->pc = 0x8003AFE8u;
    ctx->downcount -= 3;
    // 8003AFE8: lbzx    r0, r8, r6
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[6];
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003AFEC:
    // 8003AFEC: cmpwi   r0, 0
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

label_8003AFF0:
    // 8003AFF0: bc    4, 2, 0x8003AFFC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003AFFC;
        }
    }

label_8003AFF4:
    ctx->pc = 0x8003AFF4u;
    ctx->downcount -= 2;
    // 8003AFF4: lwz     r0, 108(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(108);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003AFF8:
    // 8003AFF8: add   r31, r0, r7
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[31] = res;
    }

label_8003AFFC:
    ctx->pc = 0x8003AFFCu;
    ctx->downcount -= 6;
    // 8003AFFC: lbz     r0, 85(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(85);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003B000:
    // 8003B000: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8003B004:
    // 8003B004: add   r6, r0, r6
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_8003B008:
    // 8003B008: addi    r6, r6, 1
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(1);

label_8003B00C:
    // 8003B00C: addi    r7, r7, 18
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(18);

label_8003B010:
    // 8003B010: bc    16, 0, 0x8003AFC8
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003AFC8u;
                return;
            }
            goto label_8003AFC8;
        }
    }

label_8003B014:
    ctx->pc = 0x8003B014u;
    ctx->downcount -= 2;
    // 8003B014: cmplwi  r31, 0x0000
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

label_8003B018:
    ctx->pc = 0x8003B018u;
    // 8003B018: bc    12, 2, 0x8003B22C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003B22C;
        }
    }

label_8003B01C:
    ctx->pc = 0x8003B01Cu;
    ctx->downcount -= 2;
    // 8003B01C: cmplwi  r4, 0x0000
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

label_8003B020:
    ctx->pc = 0x8003B020u;
    // 8003B020: bc    4, 2, 0x8003B048
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003B048;
        }
    }

label_8003B024:
    ctx->pc = 0x8003B024u;
    ctx->downcount -= 9;
    // 8003B024: lha     r0, 2(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(2);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003B028:
    ctx->pc = 0x8003B028u;
    // 8003B028: srawi r0, r0, 1
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

label_8003B02C:
    ctx->pc = 0x8003B02Cu;
    // 8003B02C: extsh r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_8003B030:
    ctx->pc = 0x8003B030u;
    // 8003B030: sth     r0, 2(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003B034:
    ctx->pc = 0x8003B034u;
    // 8003B034: lha     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003B038:
    ctx->pc = 0x8003B038u;
    // 8003B038: srawi r0, r0, 1
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

label_8003B03C:
    ctx->pc = 0x8003B03Cu;
    // 8003B03C: extsh r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_8003B040:
    ctx->pc = 0x8003B040u;
    // 8003B040: sth     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003B044:
    ctx->pc = 0x8003B044u;
    // 8003B044: b       0x8003B22C
    {
            goto label_8003B22C;
    }

label_8003B048:
    ctx->pc = 0x8003B048u;
    ctx->downcount -= 12;
    // 8003B048: lfs     f1, 12(r26)
    if (!ppc_fp_available_inline(ctx, 0x8003B048u)) return;
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003B04C:
    ctx->pc = 0x8003B04Cu;
    // 8003B04C: lfs     f0, 12(r4)
    if (!ppc_fp_available_inline(ctx, 0x8003B04Cu)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003B050:
    ctx->pc = 0x8003B050u;
    // 8003B050: fsubs   f31, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8003B050u)) return;
    ppc_fsubs(ctx, 31, 1, 0);

label_8003B054:
    ctx->pc = 0x8003B054u;
    // 8003B054: lfs     f1, 20(r26)
    if (!ppc_fp_available_inline(ctx, 0x8003B054u)) return;
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(20);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003B058:
    ctx->pc = 0x8003B058u;
    // 8003B058: lfs     f0, 20(r4)
    if (!ppc_fp_available_inline(ctx, 0x8003B058u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003B05C:
    ctx->pc = 0x8003B05Cu;
    // 8003B05C: fsubs   f30, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8003B05Cu)) return;
    ppc_fsubs(ctx, 30, 1, 0);

label_8003B060:
    ctx->pc = 0x8003B060u;
    // 8003B060: lfs     f1, 16(r26)
    if (!ppc_fp_available_inline(ctx, 0x8003B060u)) return;
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(16);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003B064:
    ctx->pc = 0x8003B064u;
    // 8003B064: lfs     f0, 16(r4)
    if (!ppc_fp_available_inline(ctx, 0x8003B064u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003B068:
    ctx->pc = 0x8003B068u;
    // 8003B068: fsubs   f29, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8003B068u)) return;
    ppc_fsubs(ctx, 29, 1, 0);

label_8003B06C:
    ctx->pc = 0x8003B06Cu;
    // 8003B06C: fmuls   f0, f30, f30
    if (!ppc_fp_available_inline(ctx, 0x8003B06Cu)) return;
    ppc_fmuls(ctx, 0, 30, 30);

label_8003B070:
    ctx->pc = 0x8003B070u;
    // 8003B070: fmadds f1, f31, f31, f0
    if (!ppc_fp_available_inline(ctx, 0x8003B070u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[31], ctx->fpr[31], ctx->fpr[0], true, false, false, &result))
            ctx->fpr[1] = ctx->ps1[1] = result;
    }

label_8003B074:
    ctx->pc = 0x8003B074u;
    // 8003B074: bl      0x80293B10
    {
            ctx->lr = 0x8003B078u;
            ctx->pc = 0x80293B10u;
            return;
    }

label_8003B078:
    ctx->pc = 0x8003B078u;
    ctx->downcount -= 4;
    // 8003B078: fmr    f28, f1
    if (!ppc_fp_available_inline(ctx, 0x8003B078u)) return;
    ctx->fpr[28] = ctx->fpr[1];

label_8003B07C:
    ctx->pc = 0x8003B07Cu;
    // 8003B07C: fmr    f1, f31
    if (!ppc_fp_available_inline(ctx, 0x8003B07Cu)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_8003B080:
    ctx->pc = 0x8003B080u;
    // 8003B080: fmr    f2, f30
    if (!ppc_fp_available_inline(ctx, 0x8003B080u)) return;
    ctx->fpr[2] = ctx->fpr[30];

label_8003B084:
    ctx->pc = 0x8003B084u;
    // 8003B084: bl      0x80021928
    {
            ctx->lr = 0x8003B088u;
            ctx->pc = 0x80021928u;
            return;
    }

label_8003B088:
    ctx->pc = 0x8003B088u;
    ctx->downcount -= 10;
    // 8003B088: extsh r3, r3
    {
        ctx->gpr[3] = (u32)(s32)(s16)ctx->gpr[3];
    }

label_8003B08C:
    ctx->pc = 0x8003B08Cu;
    // 8003B08C: lha     r0, 0(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(0);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003B090:
    ctx->pc = 0x8003B090u;
    // 8003B090: rlwinm r0, r0, 0, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x0000FFFFu;
    }

label_8003B094:
    ctx->pc = 0x8003B094u;
    // 8003B094: subf   r0, r0, r3
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[3];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_8003B098:
    ctx->pc = 0x8003B098u;
    // 8003B098: extsh r4, r0
    {
        ctx->gpr[4] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_8003B09C:
    ctx->pc = 0x8003B09Cu;
    // 8003B09C: sth     r4, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_8003B0A0:
    ctx->pc = 0x8003B0A0u;
    // 8003B0A0: lis     r3, 1
    ctx->gpr[3] = ((u32)(s32)(1) << 16);

label_8003B0A4:
    ctx->pc = 0x8003B0A4u;
    // 8003B0A4: addi    r0, r3, -32768
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-32768);

label_8003B0A8:
    ctx->pc = 0x8003B0A8u;
    // 8003B0A8: cmpw    r4, r0
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

label_8003B0AC:
    ctx->pc = 0x8003B0ACu;
    // 8003B0AC: bc    4, 1, 0x8003B0C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003B0C0;
        }
    }

label_8003B0B0:
    ctx->pc = 0x8003B0B0u;
    ctx->downcount -= 4;
    // 8003B0B0: addis   r3, r4, -1
    ctx->gpr[3] = ctx->gpr[4] + ((u32)(s32)(-1) << 16);

label_8003B0B4:
    ctx->pc = 0x8003B0B4u;
    // 8003B0B4: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8003B0B8:
    ctx->pc = 0x8003B0B8u;
    // 8003B0B8: extsh r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_8003B0BC:
    ctx->pc = 0x8003B0BCu;
    // 8003B0BC: sth     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003B0C0:
    ctx->pc = 0x8003B0C0u;
    ctx->downcount -= 3;
    // 8003B0C0: lha     r3, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003B0C4:
    ctx->pc = 0x8003B0C4u;
    // 8003B0C4: cmpwi   r3, -32768
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(-32768);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003B0C8:
    ctx->pc = 0x8003B0C8u;
    // 8003B0C8: bc    4, 0, 0x8003B0DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003B0DC;
        }
    }

label_8003B0CC:
    ctx->pc = 0x8003B0CCu;
    ctx->downcount -= 4;
    // 8003B0CC: addis   r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + ((u32)(s32)(1) << 16);

label_8003B0D0:
    ctx->pc = 0x8003B0D0u;
    // 8003B0D0: addi    r0, r3, -1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-1);

label_8003B0D4:
    ctx->pc = 0x8003B0D4u;
    // 8003B0D4: extsh r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_8003B0D8:
    ctx->pc = 0x8003B0D8u;
    // 8003B0D8: sth     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003B0DC:
    ctx->pc = 0x8003B0DCu;
    ctx->downcount -= 3;
    // 8003B0DC: rlwinm r0, r29, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[29], 0u) & 0x000000FFu;
    }

label_8003B0E0:
    ctx->pc = 0x8003B0E0u;
    // 8003B0E0: cmplwi  r0, 0x0000
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

label_8003B0E4:
    ctx->pc = 0x8003B0E4u;
    // 8003B0E4: bc    12, 2, 0x8003B0FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003B0FC;
        }
    }

label_8003B0E8:
    ctx->pc = 0x8003B0E8u;
    ctx->downcount -= 5;
    // 8003B0E8: lha     r3, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003B0EC:
    ctx->pc = 0x8003B0ECu;
    // 8003B0EC: addis   r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + ((u32)(s32)(1) << 16);

label_8003B0F0:
    ctx->pc = 0x8003B0F0u;
    // 8003B0F0: addi    r0, r3, -32768
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-32768);

label_8003B0F4:
    ctx->pc = 0x8003B0F4u;
    // 8003B0F4: extsh r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_8003B0F8:
    ctx->pc = 0x8003B0F8u;
    // 8003B0F8: sth     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003B0FC:
    ctx->pc = 0x8003B0FCu;
    ctx->downcount -= 3;
    // 8003B0FC: fmr    f1, f28
    if (!ppc_fp_available_inline(ctx, 0x8003B0FCu)) return;
    ctx->fpr[1] = ctx->fpr[28];

label_8003B100:
    ctx->pc = 0x8003B100u;
    // 8003B100: fmr    f2, f29
    if (!ppc_fp_available_inline(ctx, 0x8003B100u)) return;
    ctx->fpr[2] = ctx->fpr[29];

label_8003B104:
    ctx->pc = 0x8003B104u;
    // 8003B104: bl      0x80021928
    {
            ctx->lr = 0x8003B108u;
            ctx->pc = 0x80021928u;
            return;
    }

label_8003B108:
    ctx->pc = 0x8003B108u;
    ctx->downcount -= 34;
    // 8003B108: extsh r3, r3
    {
        ctx->gpr[3] = (u32)(s32)(s16)ctx->gpr[3];
    }

label_8003B10C:
    ctx->pc = 0x8003B10Cu;
    // 8003B10C: addi    r0, r3, -16383
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-16383);

label_8003B110:
    ctx->pc = 0x8003B110u;
    // 8003B110: extsh r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_8003B114:
    ctx->pc = 0x8003B114u;
    // 8003B114: sth     r0, 10(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(10);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003B118:
    ctx->pc = 0x8003B118u;
    // 8003B118: lfs     f2, -31500(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003B118u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31500);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8003B11C:
    ctx->pc = 0x8003B11Cu;
    // 8003B11C: lfd     f1, -31528(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003B11Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31528);
        ctx->fpr[1] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003B120:
    ctx->pc = 0x8003B120u;
    // 8003B120: xoris   r0, r28, 0x8000
    ctx->gpr[0] = ctx->gpr[28] ^ (0x8000u << 16);

label_8003B124:
    ctx->pc = 0x8003B124u;
    // 8003B124: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003B128:
    ctx->pc = 0x8003B128u;
    // 8003B128: lis     r3, 17200
    ctx->gpr[3] = ((u32)(s32)(17200) << 16);

label_8003B12C:
    ctx->pc = 0x8003B12Cu;
    // 8003B12C: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8003B130:
    ctx->pc = 0x8003B130u;
    // 8003B130: lfd     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B130u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003B134:
    ctx->pc = 0x8003B134u;
    // 8003B134: fsubs   f0, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8003B134u)) return;
    ppc_fsubs(ctx, 0, 0, 1);

label_8003B138:
    ctx->pc = 0x8003B138u;
    // 8003B138: fmuls   f0, f2, f0
    if (!ppc_fp_available_inline(ctx, 0x8003B138u)) return;
    ppc_fmuls(ctx, 0, 2, 0);

label_8003B13C:
    ctx->pc = 0x8003B13Cu;
    // 8003B13C: fctiwz    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x8003B13Cu)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_8003B140:
    ctx->pc = 0x8003B140u;
    // 8003B140: stfd     f0, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B140u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_8003B144:
    ctx->pc = 0x8003B144u;
    // 8003B144: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003B148:
    ctx->pc = 0x8003B148u;
    // 8003B148: extsh r28, r0
    {
        ctx->gpr[28] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_8003B14C:
    ctx->pc = 0x8003B14Cu;
    // 8003B14C: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8003B150:
    ctx->pc = 0x8003B150u;
    // 8003B150: addi    r5, r1, 8
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(8);

label_8003B154:
    ctx->pc = 0x8003B154u;
    // 8003B154: xoris   r0, r30, 0x8000
    ctx->gpr[0] = ctx->gpr[30] ^ (0x8000u << 16);

label_8003B158:
    ctx->pc = 0x8003B158u;
    // 8003B158: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003B15C:
    ctx->pc = 0x8003B15Cu;
    // 8003B15C: stw     r3, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8003B160:
    ctx->pc = 0x8003B160u;
    // 8003B160: lfd     f0, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B160u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003B164:
    ctx->pc = 0x8003B164u;
    // 8003B164: fsubs   f0, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8003B164u)) return;
    ppc_fsubs(ctx, 0, 0, 1);

label_8003B168:
    ctx->pc = 0x8003B168u;
    // 8003B168: fmuls   f1, f2, f0
    if (!ppc_fp_available_inline(ctx, 0x8003B168u)) return;
    ppc_fmuls(ctx, 1, 2, 0);

label_8003B16C:
    ctx->pc = 0x8003B16Cu;
    // 8003B16C: fctiwz    f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8003B16Cu)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[1], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_8003B170:
    ctx->pc = 0x8003B170u;
    // 8003B170: stfd     f0, 40(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B170u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_8003B174:
    ctx->pc = 0x8003B174u;
    // 8003B174: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003B178:
    ctx->pc = 0x8003B178u;
    // 8003B178: extsh r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_8003B17C:
    ctx->pc = 0x8003B17Cu;
    // 8003B17C: neg  r6, r0
    {
        u32 a = ctx->gpr[0];
        ctx->gpr[6] = (~a) + 1u;
    }

label_8003B180:
    ctx->pc = 0x8003B180u;
    // 8003B180: neg  r7, r28
    {
        u32 a = ctx->gpr[28];
        ctx->gpr[7] = (~a) + 1u;
    }

label_8003B184:
    ctx->pc = 0x8003B184u;
    // 8003B184: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_8003B188:
    ctx->pc = 0x8003B188u;
    // 8003B188: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8003B18C:
    ctx->pc = 0x8003B18Cu;
    ctx->downcount -= 7;
    // 8003B18C: lha     r3, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003B190:
    ctx->pc = 0x8003B190u;
    // 8003B190: lha     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003B194:
    // 8003B194: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_8003B198:
    ctx->pc = 0x8003B198u;
    // 8003B198: sth     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003B19C:
    ctx->pc = 0x8003B19Cu;
    // 8003B19C: lha     r3, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003B1A0:
    // 8003B1A0: cmpw    r3, r6
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(ctx->gpr[6]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003B1A4:
    // 8003B1A4: bc    4, 0, 0x8003B1B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003B1B0;
        }
    }

label_8003B1A8:
    ctx->downcount -= 2;
    // 8003B1A8: or   r0, r6, r6
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[6];
    }

label_8003B1AC:
    // 8003B1AC: b       0x8003B1D4
    {
            goto label_8003B1D4;
    }

label_8003B1B0:
    ctx->pc = 0x8003B1B0u;
    ctx->downcount -= 6;
    // 8003B1B0: fctiwz    f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8003B1B0u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[1], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_8003B1B4:
    ctx->pc = 0x8003B1B4u;
    // 8003B1B4: stfd     f0, 40(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B1B4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_8003B1B8:
    ctx->pc = 0x8003B1B8u;
    // 8003B1B8: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003B1BC:
    // 8003B1BC: extsh r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_8003B1C0:
    // 8003B1C0: cmpw    r3, r0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003B1C4:
    // 8003B1C4: bc    4, 1, 0x8003B1D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003B1D0;
        }
    }

label_8003B1C8:
    ctx->pc = 0x8003B1C8u;
    ctx->downcount -= 2;
    // 8003B1C8: stfd     f0, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B1C8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_8003B1CC:
    ctx->pc = 0x8003B1CCu;
    // 8003B1CC: lwz     r3, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003B1D0:
    ctx->downcount -= 1;
    // 8003B1D0: extsh r0, r3
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[3];
    }

label_8003B1D4:
    ctx->downcount -= 9;
    // 8003B1D4: extsh r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_8003B1D8:
    ctx->pc = 0x8003B1D8u;
    // 8003B1D8: sth     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003B1DC:
    ctx->pc = 0x8003B1DCu;
    // 8003B1DC: lha     r3, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003B1E0:
    ctx->pc = 0x8003B1E0u;
    // 8003B1E0: lha     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003B1E4:
    // 8003B1E4: add   r0, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8003B1E8:
    ctx->pc = 0x8003B1E8u;
    // 8003B1E8: sth     r0, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003B1EC:
    ctx->pc = 0x8003B1ECu;
    // 8003B1EC: lha     r0, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003B1F0:
    // 8003B1F0: cmpw    r0, r28
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[28]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003B1F4:
    // 8003B1F4: bc    4, 1, 0x8003B1FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003B1FC;
        }
    }

label_8003B1F8:
    ctx->pc = 0x8003B1F8u;
    ctx->downcount -= 1;
    // 8003B1F8: sth     r28, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        mem_write16(ctx, ea, (u16)ctx->gpr[28]);
    }

label_8003B1FC:
    ctx->pc = 0x8003B1FCu;
    ctx->downcount -= 3;
    // 8003B1FC: lha     r0, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003B200:
    // 8003B200: cmpw    r0, r7
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[7]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003B204:
    // 8003B204: bc    4, 0, 0x8003B210
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003B210;
        }
    }

label_8003B208:
    ctx->downcount -= 2;
    // 8003B208: extsh r0, r7
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[7];
    }

label_8003B20C:
    ctx->pc = 0x8003B20Cu;
    // 8003B20C: sth     r0, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003B210:
    ctx->downcount -= 3;
    // 8003B210: addi    r4, r4, 48
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(48);

label_8003B214:
    // 8003B214: addi    r5, r5, 2
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(2);

label_8003B218:
    // 8003B218: bc    16, 0, 0x8003B18C
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003B18Cu;
                return;
            }
            goto label_8003B18C;
        }
    }

label_8003B21C:
    ctx->pc = 0x8003B21Cu;
    ctx->downcount -= 4;
    // 8003B21C: lha     r0, 20(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(20);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003B220:
    ctx->pc = 0x8003B220u;
    // 8003B220: sth     r0, 2(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003B224:
    ctx->pc = 0x8003B224u;
    // 8003B224: lha     r0, 68(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(68);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003B228:
    ctx->pc = 0x8003B228u;
    // 8003B228: sth     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003B22C:
    ctx->pc = 0x8003B22Cu;
    ctx->downcount -= 10;
    // 8003B22C: psq_l   f31, 136(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8003B22Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        ppc_psq_load_inline(ctx, 31u, ea, false, 0u, false, 0x8003B22Cu);
        if (ctx->exception) return;
    }

label_8003B230:
    ctx->pc = 0x8003B230u;
    // 8003B230: lfd     f31, 128(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B230u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(128);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003B234:
    ctx->pc = 0x8003B234u;
    // 8003B234: psq_l   f30, 120(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8003B234u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(120);
        ppc_psq_load_inline(ctx, 30u, ea, false, 0u, false, 0x8003B234u);
        if (ctx->exception) return;
    }

label_8003B238:
    ctx->pc = 0x8003B238u;
    // 8003B238: lfd     f30, 112(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B238u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(112);
        ctx->fpr[30] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003B23C:
    ctx->pc = 0x8003B23Cu;
    // 8003B23C: psq_l   f29, 104(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8003B23Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        ppc_psq_load_inline(ctx, 29u, ea, false, 0u, false, 0x8003B23Cu);
        if (ctx->exception) return;
    }

label_8003B240:
    ctx->pc = 0x8003B240u;
    // 8003B240: lfd     f29, 96(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B240u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        ctx->fpr[29] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003B244:
    ctx->pc = 0x8003B244u;
    // 8003B244: psq_l   f28, 88(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8003B244u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        ppc_psq_load_inline(ctx, 28u, ea, false, 0u, false, 0x8003B244u);
        if (ctx->exception) return;
    }

label_8003B248:
    ctx->pc = 0x8003B248u;
    // 8003B248: lfd     f28, 80(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B248u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        ctx->fpr[28] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003B24C:
    ctx->pc = 0x8003B24Cu;
    // 8003B24C: addi    r11, r1, 80
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(80);

label_8003B250:
    ctx->pc = 0x8003B250u;
    // 8003B250: bl      0x80286A94
    {
            ctx->lr = 0x8003B254u;
            ctx->pc = 0x80286A94u;
            return;
    }

label_8003B254:
    ctx->pc = 0x8003B254u;
    ctx->downcount -= 5;
    // 8003B254: lwz     r0, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003B258:
    ctx->pc = 0x8003B258u;
    // 8003B258: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8003B25C:
    ctx->pc = 0x8003B25Cu;
    // 8003B25C: addi    r1, r1, 144
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(144);

label_8003B260:
    ctx->pc = 0x8003B260u;
    // 8003B260: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8003A6E0;
        }
    }

label_8003B264:
    ctx->pc = 0x8003B264u;
    ctx->downcount -= 14;
    // 8003B264: stwu     r1, -48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-48);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8003B268:
    ctx->pc = 0x8003B268u;
    // 8003B268: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8003B26C:
    ctx->pc = 0x8003B26Cu;
    // 8003B26C: stw     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003B270:
    ctx->pc = 0x8003B270u;
    // 8003B270: stw     r31, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8003B274:
    ctx->pc = 0x8003B274u;
    // 8003B274: stw     r30, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8003B278:
    ctx->pc = 0x8003B278u;
    // 8003B278: stw     r29, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_8003B27C:
    ctx->pc = 0x8003B27Cu;
    // 8003B27C: stw     r28, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_8003B280:
    ctx->pc = 0x8003B280u;
    // 8003B280: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003B284:
    ctx->pc = 0x8003B284u;
    // 8003B284: or   r29, r5, r5
    {
        ctx->gpr[29] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8003B288:
    ctx->pc = 0x8003B288u;
    // 8003B288: or   r30, r6, r6
    {
        ctx->gpr[30] = ctx->gpr[6] | ctx->gpr[6];
    }

label_8003B28C:
    ctx->pc = 0x8003B28Cu;
    // 8003B28C: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_8003B290:
    ctx->pc = 0x8003B290u;
    // 8003B290: lwz     r5, 80(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(80);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8003B294:
    ctx->pc = 0x8003B294u;
    // 8003B294: cmplwi  r5, 0x0000
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

label_8003B298:
    ctx->pc = 0x8003B298u;
    // 8003B298: bc    12, 2, 0x8003B300
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003B300;
        }
    }

label_8003B29C:
    ctx->pc = 0x8003B29Cu;
    ctx->downcount -= 7;
    // 8003B29C: or   r6, r31, r31
    {
        ctx->gpr[6] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8003B2A0:
    ctx->pc = 0x8003B2A0u;
    // 8003B2A0: or   r7, r31, r31
    {
        ctx->gpr[7] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8003B2A4:
    ctx->pc = 0x8003B2A4u;
    // 8003B2A4: lbz     r0, 90(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(90);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003B2A8:
    ctx->pc = 0x8003B2A8u;
    // 8003B2A8: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8003B2AC:
    ctx->pc = 0x8003B2ACu;
    // 8003B2AC: cmpwi   r0, 0
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

label_8003B2B0:
    ctx->pc = 0x8003B2B0u;
    // 8003B2B0: bc    4, 1, 0x8003B300
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003B300;
        }
    }

label_8003B2B4:
    ctx->pc = 0x8003B2B4u;
    ctx->downcount -= 8;
    // 8003B2B4: lwz     r8, 16(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(16);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8003B2B8:
    ctx->pc = 0x8003B2B8u;
    // 8003B2B8: lbz     r0, 173(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(173);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003B2BC:
    // 8003B2BC: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8003B2C0:
    // 8003B2C0: add   r3, r0, r6
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8003B2C4:
    // 8003B2C4: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_8003B2C8:
    ctx->pc = 0x8003B2C8u;
    // 8003B2C8: lbzx    r0, r8, r0
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[0];
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003B2CC:
    // 8003B2CC: cmpwi   r0, 255
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(255);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003B2D0:
    // 8003B2D0: bc    12, 2, 0x8003B2E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003B2E8;
        }
    }

label_8003B2D4:
    ctx->pc = 0x8003B2D4u;
    ctx->downcount -= 3;
    // 8003B2D4: lbzx    r0, r8, r6
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[6];
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003B2D8:
    // 8003B2D8: cmpwi   r0, 0
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

label_8003B2DC:
    // 8003B2DC: bc    4, 2, 0x8003B2E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003B2E8;
        }
    }

label_8003B2E0:
    ctx->pc = 0x8003B2E0u;
    ctx->downcount -= 2;
    // 8003B2E0: lwz     r0, 108(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(108);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003B2E4:
    // 8003B2E4: add   r31, r0, r7
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[31] = res;
    }

label_8003B2E8:
    ctx->pc = 0x8003B2E8u;
    ctx->downcount -= 6;
    // 8003B2E8: lbz     r0, 85(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(85);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003B2EC:
    // 8003B2EC: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8003B2F0:
    // 8003B2F0: add   r6, r0, r6
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_8003B2F4:
    // 8003B2F4: addi    r6, r6, 1
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(1);

label_8003B2F8:
    // 8003B2F8: addi    r7, r7, 18
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(18);

label_8003B2FC:
    // 8003B2FC: bc    16, 0, 0x8003B2B4
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003B2B4u;
                return;
            }
            goto label_8003B2B4;
        }
    }

label_8003B300:
    ctx->pc = 0x8003B300u;
    ctx->downcount -= 2;
    // 8003B300: cmplwi  r31, 0x0000
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

label_8003B304:
    ctx->pc = 0x8003B304u;
    // 8003B304: bc    12, 2, 0x8003B39C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003B39C;
        }
    }

label_8003B308:
    ctx->pc = 0x8003B308u;
    ctx->downcount -= 7;
    // 8003B308: lfs     f1, 12(r28)
    if (!ppc_fp_available_inline(ctx, 0x8003B308u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003B30C:
    ctx->pc = 0x8003B30Cu;
    // 8003B30C: lfs     f0, 12(r4)
    if (!ppc_fp_available_inline(ctx, 0x8003B30Cu)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003B310:
    ctx->pc = 0x8003B310u;
    // 8003B310: fsubs   f1, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8003B310u)) return;
    ppc_fsubs(ctx, 1, 1, 0);

label_8003B314:
    ctx->pc = 0x8003B314u;
    // 8003B314: lfs     f2, 20(r28)
    if (!ppc_fp_available_inline(ctx, 0x8003B314u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(20);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8003B318:
    ctx->pc = 0x8003B318u;
    // 8003B318: lfs     f0, 20(r4)
    if (!ppc_fp_available_inline(ctx, 0x8003B318u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003B31C:
    ctx->pc = 0x8003B31Cu;
    // 8003B31C: fsubs   f2, f2, f0
    if (!ppc_fp_available_inline(ctx, 0x8003B31Cu)) return;
    ppc_fsubs(ctx, 2, 2, 0);

label_8003B320:
    ctx->pc = 0x8003B320u;
    // 8003B320: bl      0x80021928
    {
            ctx->lr = 0x8003B324u;
            ctx->pc = 0x80021928u;
            return;
    }

label_8003B324:
    ctx->pc = 0x8003B324u;
    ctx->downcount -= 21;
    // 8003B324: extsh r3, r3
    {
        ctx->gpr[3] = (u32)(s32)(s16)ctx->gpr[3];
    }

label_8003B328:
    ctx->pc = 0x8003B328u;
    // 8003B328: lha     r0, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003B32C:
    ctx->pc = 0x8003B32Cu;
    // 8003B32C: subf   r0, r0, r3
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[3];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_8003B330:
    ctx->pc = 0x8003B330u;
    // 8003B330: extsh r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_8003B334:
    ctx->pc = 0x8003B334u;
    // 8003B334: sth     r0, 20(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(20);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003B338:
    ctx->pc = 0x8003B338u;
    // 8003B338: lfs     f2, -31500(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003B338u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31500);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8003B33C:
    ctx->pc = 0x8003B33Cu;
    // 8003B33C: lfd     f1, -31528(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003B33Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31528);
        ctx->fpr[1] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003B340:
    ctx->pc = 0x8003B340u;
    // 8003B340: xoris   r0, r30, 0x8000
    ctx->gpr[0] = ctx->gpr[30] ^ (0x8000u << 16);

label_8003B344:
    ctx->pc = 0x8003B344u;
    // 8003B344: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003B348:
    ctx->pc = 0x8003B348u;
    // 8003B348: lis     r0, 17200
    ctx->gpr[0] = ((u32)(s32)(17200) << 16);

label_8003B34C:
    ctx->pc = 0x8003B34Cu;
    // 8003B34C: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003B350:
    ctx->pc = 0x8003B350u;
    // 8003B350: lfd     f0, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B350u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003B354:
    ctx->pc = 0x8003B354u;
    // 8003B354: fsubs   f0, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8003B354u)) return;
    ppc_fsubs(ctx, 0, 0, 1);

label_8003B358:
    ctx->pc = 0x8003B358u;
    // 8003B358: fmuls   f0, f2, f0
    if (!ppc_fp_available_inline(ctx, 0x8003B358u)) return;
    ppc_fmuls(ctx, 0, 2, 0);

label_8003B35C:
    ctx->pc = 0x8003B35Cu;
    // 8003B35C: fctiwz    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x8003B35Cu)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_8003B360:
    ctx->pc = 0x8003B360u;
    // 8003B360: stfd     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B360u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_8003B364:
    ctx->pc = 0x8003B364u;
    // 8003B364: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003B368:
    ctx->pc = 0x8003B368u;
    // 8003B368: extsh r30, r0
    {
        ctx->gpr[30] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_8003B36C:
    ctx->pc = 0x8003B36Cu;
    // 8003B36C: lha     r0, 20(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(20);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003B370:
    ctx->pc = 0x8003B370u;
    // 8003B370: cmpw    r0, r30
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

label_8003B374:
    ctx->pc = 0x8003B374u;
    // 8003B374: bc    4, 1, 0x8003B37C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003B37C;
        }
    }

label_8003B378:
    ctx->pc = 0x8003B378u;
    ctx->downcount -= 1;
    // 8003B378: sth     r30, 20(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(20);
        mem_write16(ctx, ea, (u16)ctx->gpr[30]);
    }

label_8003B37C:
    ctx->pc = 0x8003B37Cu;
    ctx->downcount -= 4;
    // 8003B37C: lha     r0, 20(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(20);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003B380:
    ctx->pc = 0x8003B380u;
    // 8003B380: neg  r3, r30
    {
        u32 a = ctx->gpr[30];
        ctx->gpr[3] = (~a) + 1u;
    }

label_8003B384:
    ctx->pc = 0x8003B384u;
    // 8003B384: cmpw    r0, r3
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[3]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003B388:
    ctx->pc = 0x8003B388u;
    // 8003B388: bc    4, 0, 0x8003B394
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003B394;
        }
    }

label_8003B38C:
    ctx->pc = 0x8003B38Cu;
    ctx->downcount -= 2;
    // 8003B38C: extsh r0, r3
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[3];
    }

label_8003B390:
    ctx->pc = 0x8003B390u;
    // 8003B390: sth     r0, 20(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(20);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003B394:
    ctx->pc = 0x8003B394u;
    ctx->downcount -= 2;
    // 8003B394: lha     r0, 20(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(20);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003B398:
    ctx->pc = 0x8003B398u;
    // 8003B398: sth     r0, 2(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003B39C:
    ctx->pc = 0x8003B39Cu;
    ctx->downcount -= 9;
    // 8003B39C: lwz     r31, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8003B3A0:
    ctx->pc = 0x8003B3A0u;
    // 8003B3A0: lwz     r30, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8003B3A4:
    ctx->pc = 0x8003B3A4u;
    // 8003B3A4: lwz     r29, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_8003B3A8:
    ctx->pc = 0x8003B3A8u;
    // 8003B3A8: lwz     r28, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_8003B3AC:
    ctx->pc = 0x8003B3ACu;
    // 8003B3AC: lwz     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003B3B0:
    ctx->pc = 0x8003B3B0u;
    // 8003B3B0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8003B3B4:
    ctx->pc = 0x8003B3B4u;
    // 8003B3B4: addi    r1, r1, 48
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(48);

label_8003B3B8:
    ctx->pc = 0x8003B3B8u;
    // 8003B3B8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8003A6E0;
        }
    }

label_8003B3BC:
    ctx->pc = 0x8003B3BCu;
    ctx->downcount -= 4;
    // 8003B3BC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003B3C0:
    ctx->pc = 0x8003B3C0u;
    // 8003B3C0: lwz     r8, 80(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(80);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8003B3C4:
    ctx->pc = 0x8003B3C4u;
    // 8003B3C4: cmplwi  r8, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[8]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003B3C8:
    ctx->pc = 0x8003B3C8u;
    // 8003B3C8: bc    12, 2, 0x8003B410
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003B410;
        }
    }

label_8003B3CC:
    ctx->pc = 0x8003B3CCu;
    ctx->downcount -= 3;
    // 8003B3CC: lwz     r6, 12(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(12);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8003B3D0:
    ctx->pc = 0x8003B3D0u;
    // 8003B3D0: cmplwi  r6, 0x0000
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

label_8003B3D4:
    ctx->pc = 0x8003B3D4u;
    // 8003B3D4: bc    4, 2, 0x8003B3DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003B3DC;
        }
    }

label_8003B3D8:
    ctx->pc = 0x8003B3D8u;
    ctx->downcount -= 1;
    // 8003B3D8: b       0x8003B410
    {
            goto label_8003B410;
    }

label_8003B3DC:
    ctx->pc = 0x8003B3DCu;
    ctx->downcount -= 6;
    // 8003B3DC: lbz     r0, 89(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(89);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003B3E0:
    ctx->pc = 0x8003B3E0u;
    // 8003B3E0: or   r7, r5, r5
    {
        ctx->gpr[7] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8003B3E4:
    ctx->pc = 0x8003B3E4u;
    // 8003B3E4: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8003B3E8:
    ctx->pc = 0x8003B3E8u;
    // 8003B3E8: cmpwi   r0, 0
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

label_8003B3EC:
    ctx->pc = 0x8003B3ECu;
    // 8003B3EC: bc    4, 1, 0x8003B410
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003B410;
        }
    }

label_8003B3F0:
    ctx->pc = 0x8003B3F0u;
    ctx->downcount -= 3;
    // 8003B3F0: lbz     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003B3F4:
    // 8003B3F4: cmpwi   r0, 5
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

label_8003B3F8:
    // 8003B3F8: bc    4, 2, 0x8003B404
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003B404;
        }
    }

label_8003B3FC:
    ctx->pc = 0x8003B3FCu;
    ctx->downcount -= 2;
    // 8003B3FC: lwz     r0, 112(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(112);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003B400:
    // 8003B400: add   r5, r0, r7
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[5] = res;
    }

label_8003B404:
    ctx->downcount -= 3;
    // 8003B404: addi    r6, r6, 2
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(2);

label_8003B408:
    // 8003B408: addi    r7, r7, 16
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(16);

label_8003B40C:
    // 8003B40C: bc    16, 0, 0x8003B3F0
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003B3F0u;
                return;
            }
            goto label_8003B3F0;
        }
    }

label_8003B410:
    ctx->pc = 0x8003B410u;
    ctx->downcount -= 3;
    // 8003B410: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8003B414:
    ctx->pc = 0x8003B414u;
    // 8003B414: cmplwi  r8, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[8]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003B418:
    ctx->pc = 0x8003B418u;
    // 8003B418: bc    12, 2, 0x8003B460
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003B460;
        }
    }

label_8003B41C:
    ctx->pc = 0x8003B41Cu;
    ctx->downcount -= 3;
    // 8003B41C: lwz     r7, 12(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(12);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8003B420:
    ctx->pc = 0x8003B420u;
    // 8003B420: cmplwi  r7, 0x0000
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

label_8003B424:
    ctx->pc = 0x8003B424u;
    // 8003B424: bc    4, 2, 0x8003B42C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003B42C;
        }
    }

label_8003B428:
    ctx->pc = 0x8003B428u;
    ctx->downcount -= 1;
    // 8003B428: b       0x8003B460
    {
            goto label_8003B460;
    }

label_8003B42C:
    ctx->pc = 0x8003B42Cu;
    ctx->downcount -= 6;
    // 8003B42C: lbz     r0, 89(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(89);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003B430:
    ctx->pc = 0x8003B430u;
    // 8003B430: or   r8, r6, r6
    {
        ctx->gpr[8] = ctx->gpr[6] | ctx->gpr[6];
    }

label_8003B434:
    ctx->pc = 0x8003B434u;
    // 8003B434: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8003B438:
    ctx->pc = 0x8003B438u;
    // 8003B438: cmpwi   r0, 0
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

label_8003B43C:
    ctx->pc = 0x8003B43Cu;
    // 8003B43C: bc    4, 1, 0x8003B460
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003B460;
        }
    }

label_8003B440:
    ctx->pc = 0x8003B440u;
    ctx->downcount -= 3;
    // 8003B440: lbz     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003B444:
    // 8003B444: cmpwi   r0, 4
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(4);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003B448:
    // 8003B448: bc    4, 2, 0x8003B454
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003B454;
        }
    }

label_8003B44C:
    ctx->pc = 0x8003B44Cu;
    ctx->downcount -= 2;
    // 8003B44C: lwz     r0, 112(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(112);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003B450:
    // 8003B450: add   r6, r0, r8
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[8];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_8003B454:
    ctx->downcount -= 3;
    // 8003B454: addi    r7, r7, 2
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(2);

label_8003B458:
    // 8003B458: addi    r8, r8, 16
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(16);

label_8003B45C:
    // 8003B45C: bc    16, 0, 0x8003B440
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003B440u;
                return;
            }
            goto label_8003B440;
        }
    }

label_8003B460:
    ctx->pc = 0x8003B460u;
    ctx->downcount -= 2;
    // 8003B460: cmplwi  r5, 0x0000
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

label_8003B464:
    ctx->pc = 0x8003B464u;
    // 8003B464: bclr  12, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8003A6E0;
        }
    }

label_8003B468:
    ctx->pc = 0x8003B468u;
    ctx->downcount -= 2;
    // 8003B468: cmplwi  r6, 0x0000
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

label_8003B46C:
    ctx->pc = 0x8003B46Cu;
    // 8003B46C: bc    4, 2, 0x8003B474
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003B474;
        }
    }

label_8003B470:
    ctx->pc = 0x8003B470u;
    ctx->downcount -= 1;
    // 8003B470: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8003A6E0;
        }
    }

label_8003B474:
    ctx->pc = 0x8003B474u;
    ctx->downcount -= 8;
    // 8003B474: lwz     r3, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003B478:
    ctx->pc = 0x8003B478u;
    // 8003B478: lbz     r0, -32120(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32120);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003B47C:
    ctx->pc = 0x8003B47Cu;
    // 8003B47C: mulli   r0, r0, 48
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)48);

label_8003B480:
    ctx->pc = 0x8003B480u;
    // 8003B480: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8003B484:
    ctx->pc = 0x8003B484u;
    // 8003B484: cmpwi   r3, 512
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(512);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003B488:
    ctx->pc = 0x8003B488u;
    // 8003B488: bc    12, 0, 0x8003B490
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003B490;
        }
    }

label_8003B48C:
    ctx->pc = 0x8003B48Cu;
    ctx->downcount -= 1;
    // 8003B48C: li      r3, 512
    ctx->gpr[3] = (u32)(s32)(512);

label_8003B490:
    ctx->pc = 0x8003B490u;
    ctx->downcount -= 5;
    // 8003B490: stw     r3, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8003B494:
    ctx->pc = 0x8003B494u;
    // 8003B494: stw     r3, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8003B498:
    ctx->pc = 0x8003B498u;
    // 8003B498: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8003B49C:
    ctx->pc = 0x8003B49Cu;
    // 8003B49C: stb     r0, 30(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(30);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8003B4A0:
    ctx->pc = 0x8003B4A0u;
    // 8003B4A0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8003A6E0;
        }
    }

label_8003B4A4:
    ctx->pc = 0x8003B4A4u;
    ctx->downcount -= 11;
    // 8003B4A4: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8003B4A8:
    ctx->pc = 0x8003B4A8u;
    // 8003B4A8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8003B4AC:
    ctx->pc = 0x8003B4ACu;
    // 8003B4AC: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003B4B0:
    ctx->pc = 0x8003B4B0u;
    // 8003B4B0: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8003B4B4:
    ctx->pc = 0x8003B4B4u;
    // 8003B4B4: stw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8003B4B8:
    ctx->pc = 0x8003B4B8u;
    // 8003B4B8: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003B4BC:
    ctx->pc = 0x8003B4BCu;
    // 8003B4BC: or   r31, r4, r4
    {
        ctx->gpr[31] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8003B4C0:
    ctx->pc = 0x8003B4C0u;
    // 8003B4C0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003B4C4:
    ctx->pc = 0x8003B4C4u;
    // 8003B4C4: lwz     r6, 80(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(80);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8003B4C8:
    ctx->pc = 0x8003B4C8u;
    // 8003B4C8: cmplwi  r6, 0x0000
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

label_8003B4CC:
    ctx->pc = 0x8003B4CCu;
    // 8003B4CC: bc    12, 2, 0x8003B514
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003B514;
        }
    }

label_8003B4D0:
    ctx->pc = 0x8003B4D0u;
    ctx->downcount -= 3;
    // 8003B4D0: lwz     r4, 12(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(12);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8003B4D4:
    ctx->pc = 0x8003B4D4u;
    // 8003B4D4: cmplwi  r4, 0x0000
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

label_8003B4D8:
    ctx->pc = 0x8003B4D8u;
    // 8003B4D8: bc    4, 2, 0x8003B4E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003B4E0;
        }
    }

label_8003B4DC:
    ctx->pc = 0x8003B4DCu;
    ctx->downcount -= 1;
    // 8003B4DC: b       0x8003B514
    {
            goto label_8003B514;
    }

label_8003B4E0:
    ctx->pc = 0x8003B4E0u;
    ctx->downcount -= 6;
    // 8003B4E0: lbz     r0, 89(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(89);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003B4E4:
    ctx->pc = 0x8003B4E4u;
    // 8003B4E4: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003B4E8:
    ctx->pc = 0x8003B4E8u;
    // 8003B4E8: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8003B4EC:
    ctx->pc = 0x8003B4ECu;
    // 8003B4EC: cmpwi   r0, 0
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

label_8003B4F0:
    ctx->pc = 0x8003B4F0u;
    // 8003B4F0: bc    4, 1, 0x8003B514
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003B514;
        }
    }

label_8003B4F4:
    ctx->pc = 0x8003B4F4u;
    ctx->downcount -= 3;
    // 8003B4F4: lbz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003B4F8:
    // 8003B4F8: cmpwi   r0, 5
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

label_8003B4FC:
    // 8003B4FC: bc    4, 2, 0x8003B508
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003B508;
        }
    }

label_8003B500:
    ctx->pc = 0x8003B500u;
    ctx->downcount -= 2;
    // 8003B500: lwz     r0, 112(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(112);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003B504:
    // 8003B504: add   r3, r0, r5
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8003B508:
    ctx->downcount -= 3;
    // 8003B508: addi    r4, r4, 2
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(2);

label_8003B50C:
    // 8003B50C: addi    r5, r5, 16
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(16);

label_8003B510:
    // 8003B510: bc    16, 0, 0x8003B4F4
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003B4F4u;
                return;
            }
            goto label_8003B4F4;
        }
    }

label_8003B514:
    ctx->pc = 0x8003B514u;
    ctx->downcount -= 3;
    // 8003B514: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003B518:
    ctx->pc = 0x8003B518u;
    // 8003B518: cmplwi  r6, 0x0000
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

label_8003B51C:
    ctx->pc = 0x8003B51Cu;
    // 8003B51C: bc    12, 2, 0x8003B564
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003B564;
        }
    }

label_8003B520:
    ctx->pc = 0x8003B520u;
    ctx->downcount -= 3;
    // 8003B520: lwz     r5, 12(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(12);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8003B524:
    ctx->pc = 0x8003B524u;
    // 8003B524: cmplwi  r5, 0x0000
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

label_8003B528:
    ctx->pc = 0x8003B528u;
    // 8003B528: bc    4, 2, 0x8003B530
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003B530;
        }
    }

label_8003B52C:
    ctx->pc = 0x8003B52Cu;
    ctx->downcount -= 1;
    // 8003B52C: b       0x8003B564
    {
            goto label_8003B564;
    }

label_8003B530:
    ctx->pc = 0x8003B530u;
    ctx->downcount -= 6;
    // 8003B530: lbz     r0, 89(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(89);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003B534:
    ctx->pc = 0x8003B534u;
    // 8003B534: or   r6, r4, r4
    {
        ctx->gpr[6] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8003B538:
    ctx->pc = 0x8003B538u;
    // 8003B538: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8003B53C:
    ctx->pc = 0x8003B53Cu;
    // 8003B53C: cmpwi   r0, 0
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

label_8003B540:
    ctx->pc = 0x8003B540u;
    // 8003B540: bc    4, 1, 0x8003B564
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003B564;
        }
    }

label_8003B544:
    ctx->pc = 0x8003B544u;
    ctx->downcount -= 3;
    // 8003B544: lbz     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003B548:
    // 8003B548: cmpwi   r0, 4
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(4);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003B54C:
    // 8003B54C: bc    4, 2, 0x8003B558
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003B558;
        }
    }

label_8003B550:
    ctx->pc = 0x8003B550u;
    ctx->downcount -= 2;
    // 8003B550: lwz     r0, 112(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(112);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003B554:
    // 8003B554: add   r4, r0, r6
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_8003B558:
    ctx->downcount -= 3;
    // 8003B558: addi    r5, r5, 2
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(2);

label_8003B55C:
    // 8003B55C: addi    r6, r6, 16
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(16);

label_8003B560:
    // 8003B560: bc    16, 0, 0x8003B544
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003B544u;
                return;
            }
            goto label_8003B544;
        }
    }

label_8003B564:
    ctx->pc = 0x8003B564u;
    ctx->downcount -= 2;
    // 8003B564: cmplwi  r3, 0x0000
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

label_8003B568:
    ctx->pc = 0x8003B568u;
    // 8003B568: bc    12, 2, 0x8003B67C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003B67C;
        }
    }

label_8003B56C:
    ctx->pc = 0x8003B56Cu;
    ctx->downcount -= 2;
    // 8003B56C: cmplwi  r4, 0x0000
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

label_8003B570:
    ctx->pc = 0x8003B570u;
    // 8003B570: bc    4, 2, 0x8003B578
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003B578;
        }
    }

label_8003B574:
    ctx->pc = 0x8003B574u;
    ctx->downcount -= 1;
    // 8003B574: b       0x8003B67C
    {
            goto label_8003B67C;
    }

label_8003B578:
    ctx->pc = 0x8003B578u;
    ctx->downcount -= 6;
    // 8003B578: lwz     r6, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8003B57C:
    ctx->pc = 0x8003B57Cu;
    // 8003B57C: lbz     r5, 30(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(30);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_8003B580:
    ctx->pc = 0x8003B580u;
    // 8003B580: extsb r5, r5
    {
        ctx->gpr[5] = (u32)(s32)(s8)ctx->gpr[5];
    }

label_8003B584:
    ctx->pc = 0x8003B584u;
    // 8003B584: rlwinm r0, r5, 0, 28, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x0000000Fu;
    }

label_8003B588:
    ctx->pc = 0x8003B588u;
    // 8003B588: cmpwi   r0, 1
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

label_8003B58C:
    ctx->pc = 0x8003B58Cu;
    // 8003B58C: bc    12, 2, 0x8003B5EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003B5EC;
        }
    }

label_8003B590:
    ctx->pc = 0x8003B590u;
    ctx->downcount -= 1;
    // 8003B590: bc    4, 0, 0x8003B66C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003B66C;
        }
    }

label_8003B594:
    ctx->pc = 0x8003B594u;
    ctx->downcount -= 2;
    // 8003B594: cmpwi   r0, 0
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

label_8003B598:
    ctx->pc = 0x8003B598u;
    // 8003B598: bc    4, 0, 0x8003B5A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003B5A0;
        }
    }

label_8003B59C:
    ctx->pc = 0x8003B59Cu;
    ctx->downcount -= 1;
    // 8003B59C: b       0x8003B66C
    {
            goto label_8003B66C;
    }

label_8003B5A0:
    ctx->pc = 0x8003B5A0u;
    ctx->downcount -= 4;
    // 8003B5A0: lbz     r3, 31(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(31);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8003B5A4:
    ctx->pc = 0x8003B5A4u;
    // 8003B5A4: extsb r0, r3
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[3];
    }

label_8003B5A8:
    ctx->pc = 0x8003B5A8u;
    // 8003B5A8: cmpwi   r0, 0
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

label_8003B5AC:
    ctx->pc = 0x8003B5ACu;
    // 8003B5AC: bc    4, 1, 0x8003B5C4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003B5C4;
        }
    }

label_8003B5B0:
    ctx->pc = 0x8003B5B0u;
    ctx->downcount -= 5;
    // 8003B5B0: lbz     r0, -32120(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32120);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003B5B4:
    ctx->pc = 0x8003B5B4u;
    // 8003B5B4: subf   r0, r0, r3
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[3];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_8003B5B8:
    ctx->pc = 0x8003B5B8u;
    // 8003B5B8: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8003B5BC:
    ctx->pc = 0x8003B5BCu;
    // 8003B5BC: stb     r0, 31(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(31);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8003B5C0:
    ctx->pc = 0x8003B5C0u;
    // 8003B5C0: b       0x8003B66C
    {
            goto label_8003B66C;
    }

label_8003B5C4:
    ctx->pc = 0x8003B5C4u;
    ctx->downcount -= 3;
    // 8003B5C4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003B5C8:
    ctx->pc = 0x8003B5C8u;
    // 8003B5C8: li      r4, 1000
    ctx->gpr[4] = (u32)(s32)(1000);

label_8003B5CC:
    ctx->pc = 0x8003B5CCu;
    // 8003B5CC: bl      0x80022308
    {
            ctx->lr = 0x8003B5D0u;
            ctx->pc = 0x80022308u;
            return;
    }

label_8003B5D0:
    ctx->pc = 0x8003B5D0u;
    ctx->downcount -= 2;
    // 8003B5D0: cmpwi   r3, 990
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(990);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003B5D4:
    ctx->pc = 0x8003B5D4u;
    // 8003B5D4: bc    4, 1, 0x8003B66C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003B66C;
        }
    }

label_8003B5D8:
    ctx->pc = 0x8003B5D8u;
    ctx->downcount -= 5;
    // 8003B5D8: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8003B5DC:
    ctx->pc = 0x8003B5DCu;
    // 8003B5DC: stb     r0, 30(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(30);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8003B5E0:
    ctx->pc = 0x8003B5E0u;
    // 8003B5E0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8003B5E4:
    ctx->pc = 0x8003B5E4u;
    // 8003B5E4: stb     r0, 31(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(31);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8003B5E8:
    ctx->pc = 0x8003B5E8u;
    // 8003B5E8: b       0x8003B66C
    {
            goto label_8003B66C;
    }

label_8003B5EC:
    ctx->pc = 0x8003B5ECu;
    ctx->downcount -= 3;
    // 8003B5EC: rlwinm r0, r5, 0, 24, 24
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x00000080u;
    }

label_8003B5F0:
    ctx->pc = 0x8003B5F0u;
    // 8003B5F0: cmpwi   r0, 0
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

label_8003B5F4:
    ctx->pc = 0x8003B5F4u;
    // 8003B5F4: bc    12, 2, 0x8003B620
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003B620;
        }
    }

label_8003B5F8:
    ctx->pc = 0x8003B5F8u;
    ctx->downcount -= 7;
    // 8003B5F8: lbz     r0, -32120(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32120);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003B5FC:
    ctx->pc = 0x8003B5FCu;
    // 8003B5FC: mulli   r0, r0, 96
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)96);

label_8003B600:
    ctx->pc = 0x8003B600u;
    // 8003B600: subf   r6, r0, r6
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b + 1u;
        ctx->gpr[6] = res;
    }

label_8003B604:
    ctx->pc = 0x8003B604u;
    // 8003B604: cmpwi   r6, 0
    {
        s32 val_a = (s32)(ctx->gpr[6]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003B608:
    ctx->pc = 0x8003B608u;
    // 8003B608: bc    4, 0, 0x8003B664
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003B664;
        }
    }

label_8003B60C:
    ctx->pc = 0x8003B60Cu;
    ctx->downcount -= 5;
    // 8003B60C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8003B610:
    ctx->pc = 0x8003B610u;
    // 8003B610: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8003B614:
    ctx->pc = 0x8003B614u;
    // 8003B614: stb     r0, 30(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(30);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8003B618:
    ctx->pc = 0x8003B618u;
    // 8003B618: stb     r0, 31(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(31);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8003B61C:
    ctx->pc = 0x8003B61Cu;
    // 8003B61C: b       0x8003B664
    {
            goto label_8003B664;
    }

label_8003B620:
    ctx->pc = 0x8003B620u;
    ctx->downcount -= 7;
    // 8003B620: lbz     r0, -32120(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32120);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003B624:
    ctx->pc = 0x8003B624u;
    // 8003B624: mulli   r0, r0, 96
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)96);

label_8003B628:
    ctx->pc = 0x8003B628u;
    // 8003B628: add   r6, r6, r0
    {
        u32 a = ctx->gpr[6];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_8003B62C:
    ctx->pc = 0x8003B62Cu;
    // 8003B62C: cmpwi   r6, 512
    {
        s32 val_a = (s32)(ctx->gpr[6]);
        s32 val_b = (s32)(512);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003B630:
    ctx->pc = 0x8003B630u;
    // 8003B630: bc    4, 1, 0x8003B664
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003B664;
        }
    }

label_8003B634:
    ctx->pc = 0x8003B634u;
    ctx->downcount -= 3;
    // 8003B634: addi    r0, r6, -512
    ctx->gpr[0] = ctx->gpr[6] + (u32)(s32)(-512);

label_8003B638:
    ctx->pc = 0x8003B638u;
    // 8003B638: cmpwi   r0, 0
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

label_8003B63C:
    ctx->pc = 0x8003B63Cu;
    // 8003B63C: bc    4, 0, 0x8003B650
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003B650;
        }
    }

label_8003B640:
    ctx->pc = 0x8003B640u;
    ctx->downcount -= 4;
    // 8003B640: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8003B644:
    ctx->pc = 0x8003B644u;
    // 8003B644: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8003B648:
    ctx->pc = 0x8003B648u;
    // 8003B648: stb     r0, 30(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(30);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8003B64C:
    ctx->pc = 0x8003B64Cu;
    // 8003B64C: b       0x8003B65C
    {
            goto label_8003B65C;
    }

label_8003B650:
    ctx->pc = 0x8003B650u;
    ctx->downcount -= 3;
    // 8003B650: li      r6, 767
    ctx->gpr[6] = (u32)(s32)(767);

label_8003B654:
    ctx->pc = 0x8003B654u;
    // 8003B654: li      r0, -127
    ctx->gpr[0] = (u32)(s32)(-127);

label_8003B658:
    ctx->pc = 0x8003B658u;
    // 8003B658: stb     r0, 30(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(30);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8003B65C:
    ctx->pc = 0x8003B65Cu;
    ctx->downcount -= 2;
    // 8003B65C: li      r0, 40
    ctx->gpr[0] = (u32)(s32)(40);

label_8003B660:
    ctx->pc = 0x8003B660u;
    // 8003B660: stb     r0, 31(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(31);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8003B664:
    ctx->pc = 0x8003B664u;
    ctx->downcount -= 2;
    // 8003B664: stw     r6, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8003B668:
    ctx->pc = 0x8003B668u;
    // 8003B668: stw     r6, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8003B66C:
    ctx->pc = 0x8003B66Cu;
    ctx->downcount -= 4;
    // 8003B66C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8003B670:
    ctx->pc = 0x8003B670u;
    // 8003B670: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8003B674:
    ctx->pc = 0x8003B674u;
    // 8003B674: lfs     f1, -31572(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003B674u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31572);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003B678:
    ctx->pc = 0x8003B678u;
    // 8003B678: bl      0x800397E8
    {
            ctx->lr = 0x8003B67Cu;
            ctx->pc = 0x800397E8u;
            return;
    }

label_8003B67C:
    ctx->pc = 0x8003B67Cu;
    ctx->downcount -= 7;
    // 8003B67C: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8003B680:
    ctx->pc = 0x8003B680u;
    // 8003B680: lwz     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8003B684:
    ctx->pc = 0x8003B684u;
    // 8003B684: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003B688:
    ctx->pc = 0x8003B688u;
    // 8003B688: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8003B68C:
    ctx->pc = 0x8003B68Cu;
    // 8003B68C: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8003B690:
    ctx->pc = 0x8003B690u;
    // 8003B690: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8003A6E0;
        }
    }

label_8003B694:
    ctx->pc = 0x8003B694u;
    ctx->downcount -= 9;
    // 8003B694: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8003B698:
    ctx->pc = 0x8003B698u;
    // 8003B698: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8003B69C:
    ctx->pc = 0x8003B69Cu;
    // 8003B69C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003B6A0:
    ctx->pc = 0x8003B6A0u;
    // 8003B6A0: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8003B6A4:
    ctx->pc = 0x8003B6A4u;
    // 8003B6A4: or   r31, r4, r4
    {
        ctx->gpr[31] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8003B6A8:
    ctx->pc = 0x8003B6A8u;
    // 8003B6A8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003B6AC:
    ctx->pc = 0x8003B6ACu;
    // 8003B6AC: lwz     r6, 80(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(80);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8003B6B0:
    ctx->pc = 0x8003B6B0u;
    // 8003B6B0: cmplwi  r6, 0x0000
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

label_8003B6B4:
    ctx->pc = 0x8003B6B4u;
    // 8003B6B4: bc    12, 2, 0x8003B71C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003B71C;
        }
    }

label_8003B6B8:
    ctx->pc = 0x8003B6B8u;
    ctx->downcount -= 7;
    // 8003B6B8: or   r7, r5, r5
    {
        ctx->gpr[7] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8003B6BC:
    ctx->pc = 0x8003B6BCu;
    // 8003B6BC: or   r8, r5, r5
    {
        ctx->gpr[8] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8003B6C0:
    ctx->pc = 0x8003B6C0u;
    // 8003B6C0: lbz     r0, 90(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(90);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003B6C4:
    ctx->pc = 0x8003B6C4u;
    // 8003B6C4: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8003B6C8:
    ctx->pc = 0x8003B6C8u;
    // 8003B6C8: cmpwi   r0, 0
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

label_8003B6CC:
    ctx->pc = 0x8003B6CCu;
    // 8003B6CC: bc    4, 1, 0x8003B71C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003B71C;
        }
    }

label_8003B6D0:
    ctx->pc = 0x8003B6D0u;
    ctx->downcount -= 8;
    // 8003B6D0: lwz     r9, 16(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8003B6D4:
    ctx->pc = 0x8003B6D4u;
    // 8003B6D4: lbz     r0, 173(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(173);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003B6D8:
    // 8003B6D8: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8003B6DC:
    // 8003B6DC: add   r4, r0, r7
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_8003B6E0:
    // 8003B6E0: addi    r0, r4, 1
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(1);

label_8003B6E4:
    ctx->pc = 0x8003B6E4u;
    // 8003B6E4: lbzx    r0, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003B6E8:
    // 8003B6E8: cmpwi   r0, 255
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(255);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003B6EC:
    // 8003B6EC: bc    12, 2, 0x8003B704
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003B704;
        }
    }

label_8003B6F0:
    ctx->pc = 0x8003B6F0u;
    ctx->downcount -= 3;
    // 8003B6F0: lbzx    r0, r9, r7
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[7];
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003B6F4:
    // 8003B6F4: cmpwi   r0, 0
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

label_8003B6F8:
    // 8003B6F8: bc    4, 2, 0x8003B704
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003B704;
        }
    }

label_8003B6FC:
    ctx->pc = 0x8003B6FCu;
    ctx->downcount -= 2;
    // 8003B6FC: lwz     r0, 108(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(108);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003B700:
    // 8003B700: add   r5, r0, r8
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[8];
        u32 res = a + b;
        ctx->gpr[5] = res;
    }

label_8003B704:
    ctx->pc = 0x8003B704u;
    ctx->downcount -= 6;
    // 8003B704: lbz     r0, 85(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(85);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003B708:
    // 8003B708: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8003B70C:
    // 8003B70C: add   r7, r0, r7
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_8003B710:
    // 8003B710: addi    r7, r7, 1
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(1);

label_8003B714:
    // 8003B714: addi    r8, r8, 18
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(18);

label_8003B718:
    // 8003B718: bc    16, 0, 0x8003B6D0
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003B6D0u;
                return;
            }
            goto label_8003B6D0;
        }
    }

label_8003B71C:
    ctx->pc = 0x8003B71Cu;
    ctx->downcount -= 2;
    // 8003B71C: cmplwi  r5, 0x0000
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

label_8003B720:
    ctx->pc = 0x8003B720u;
    // 8003B720: bc    12, 2, 0x8003B760
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003B760;
        }
    }

label_8003B724:
    ctx->pc = 0x8003B724u;
    ctx->downcount -= 3;
    // 8003B724: lha     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003B728:
    ctx->pc = 0x8003B728u;
    // 8003B728: cmpwi   r0, 0
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

label_8003B72C:
    ctx->pc = 0x8003B72Cu;
    // 8003B72C: bc    12, 2, 0x8003B744
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003B744;
        }
    }

label_8003B730:
    ctx->pc = 0x8003B730u;
    ctx->downcount -= 7;
    // 8003B730: mulli   r0, r0, 3
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)3);

label_8003B734:
    ctx->pc = 0x8003B734u;
    // 8003B734: srawi r0, r0, 2
    {
        u32 sh = 2u;
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

label_8003B738:
    ctx->pc = 0x8003B738u;
    // 8003B738: addze  r0, r0
    {
        u32 a = ctx->gpr[0];
        u64 wide = (u64)a + ((ctx->xer >> 29) & 1u);
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_8003B73C:
    ctx->pc = 0x8003B73Cu;
    // 8003B73C: extsh r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_8003B740:
    ctx->pc = 0x8003B740u;
    // 8003B740: sth     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003B744:
    ctx->pc = 0x8003B744u;
    ctx->downcount -= 3;
    // 8003B744: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8003B748:
    ctx->pc = 0x8003B748u;
    // 8003B748: lfs     f1, -31572(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003B748u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31572);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003B74C:
    ctx->pc = 0x8003B74Cu;
    // 8003B74C: bl      0x80039F8C
    {
            ctx->lr = 0x8003B750u;
            ctx->pc = 0x80039F8Cu;
            return;
    }

label_8003B750:
    ctx->pc = 0x8003B750u;
    ctx->downcount -= 4;
    // 8003B750: lha     r0, 26(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(26);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003B754:
    ctx->pc = 0x8003B754u;
    // 8003B754: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_8003B758:
    ctx->pc = 0x8003B758u;
    // 8003B758: extsh r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_8003B75C:
    ctx->pc = 0x8003B75Cu;
    // 8003B75C: sth     r0, 26(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(26);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003B760:
    ctx->pc = 0x8003B760u;
    ctx->downcount -= 6;
    // 8003B760: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8003B764:
    ctx->pc = 0x8003B764u;
    // 8003B764: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003B768:
    ctx->pc = 0x8003B768u;
    // 8003B768: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8003B76C:
    ctx->pc = 0x8003B76Cu;
    // 8003B76C: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8003B770:
    ctx->pc = 0x8003B770u;
    // 8003B770: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8003A6E0;
        }
    }

label_8003B774:
    ctx->pc = 0x8003B774u;
    ctx->downcount -= 10;
    // 8003B774: rlwinm r0, r3, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000000FFu;
    }

label_8003B778:
    ctx->pc = 0x8003B778u;
    // 8003B778: stb     r0, -25979(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25979);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8003B77C:
    ctx->pc = 0x8003B77Cu;
    // 8003B77C: rlwinm r0, r4, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x000000FFu;
    }

label_8003B780:
    ctx->pc = 0x8003B780u;
    // 8003B780: stb     r0, -25980(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25980);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8003B784:
    ctx->pc = 0x8003B784u;
    // 8003B784: rlwinm r0, r5, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x000000FFu;
    }

label_8003B788:
    ctx->pc = 0x8003B788u;
    // 8003B788: stb     r0, -25981(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25981);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8003B78C:
    ctx->pc = 0x8003B78Cu;
    // 8003B78C: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8003B790:
    ctx->pc = 0x8003B790u;
    // 8003B790: stb     r0, -25983(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25983);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8003B794:
    ctx->pc = 0x8003B794u;
    // 8003B794: stb     r6, -25982(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25982);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_8003B798:
    ctx->pc = 0x8003B798u;
    // 8003B798: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8003A6E0;
        }
    }

label_8003B79C:
    ctx->pc = 0x8003B79Cu;
    ctx->downcount -= 6;
    // 8003B79C: sth     r3, -25968(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25968);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_8003B7A0:
    ctx->pc = 0x8003B7A0u;
    // 8003B7A0: sth     r4, -25970(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25970);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_8003B7A4:
    ctx->pc = 0x8003B7A4u;
    // 8003B7A4: sth     r5, -25972(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25972);
        mem_write16(ctx, ea, (u16)ctx->gpr[5]);
    }

label_8003B7A8:
    ctx->pc = 0x8003B7A8u;
    // 8003B7A8: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8003B7AC:
    ctx->pc = 0x8003B7ACu;
    // 8003B7AC: stb     r0, -25984(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25984);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8003B7B0:
    ctx->pc = 0x8003B7B0u;
    // 8003B7B0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8003A6E0;
        }
    }

label_8003B7B4:
    ctx->pc = 0x8003B7B4u;
    ctx->downcount -= 5;
    // 8003B7B4: stwu     r1, -80(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-80);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8003B7B8:
    ctx->pc = 0x8003B7B8u;
    // 8003B7B8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8003B7BC:
    ctx->pc = 0x8003B7BCu;
    // 8003B7BC: stw     r0, 84(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003B7C0:
    ctx->pc = 0x8003B7C0u;
    // 8003B7C0: addi    r11, r1, 80
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(80);

label_8003B7C4:
    ctx->pc = 0x8003B7C4u;
    // 8003B7C4: bl      0x80286A3C
    {
            ctx->lr = 0x8003B7C8u;
            ctx->pc = 0x80286A3Cu;
            return;
    }

label_8003B7C8:
    ctx->pc = 0x8003B7C8u;
    ctx->downcount -= 7;
    // 8003B7C8: or   r24, r3, r3
    {
        ctx->gpr[24] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003B7CC:
    ctx->pc = 0x8003B7CCu;
    // 8003B7CC: or   r25, r4, r4
    {
        ctx->gpr[25] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8003B7D0:
    ctx->pc = 0x8003B7D0u;
    // 8003B7D0: or   r26, r5, r5
    {
        ctx->gpr[26] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8003B7D4:
    ctx->pc = 0x8003B7D4u;
    // 8003B7D4: lwz     r3, 80(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(80);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003B7D8:
    ctx->pc = 0x8003B7D8u;
    // 8003B7D8: lbz     r0, 88(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(88);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003B7DC:
    ctx->pc = 0x8003B7DCu;
    // 8003B7DC: cmplwi  r0, 0x0002
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0002u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003B7E0:
    ctx->pc = 0x8003B7E0u;
    // 8003B7E0: bc    12, 0, 0x8003BA34
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003BA34;
        }
    }

label_8003B7E4:
    ctx->pc = 0x8003B7E4u;
    ctx->downcount -= 3;
    // 8003B7E4: lha     r0, 68(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(68);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003B7E8:
    ctx->pc = 0x8003B7E8u;
    // 8003B7E8: cmpwi   r0, 45
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(45);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003B7EC:
    ctx->pc = 0x8003B7ECu;
    // 8003B7EC: bc    4, 2, 0x8003BA34
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003BA34;
        }
    }

label_8003B7F0:
    ctx->pc = 0x8003B7F0u;
    ctx->downcount -= 7;
    // 8003B7F0: lwz     r27, 184(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(184);
        ctx->gpr[27] = mem_read32(ctx, ea);
    }

label_8003B7F4:
    ctx->pc = 0x8003B7F4u;
    // 8003B7F4: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_8003B7F8:
    ctx->pc = 0x8003B7F8u;
    // 8003B7F8: li      r31, 1
    ctx->gpr[31] = (u32)(s32)(1);

label_8003B7FC:
    ctx->pc = 0x8003B7FCu;
    // 8003B7FC: li      r23, 24
    ctx->gpr[23] = (u32)(s32)(24);

label_8003B800:
    ctx->pc = 0x8003B800u;
    // 8003B800: or   r30, r27, r27
    {
        ctx->gpr[30] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8003B804:
    ctx->pc = 0x8003B804u;
    // 8003B804: addi    r29, r1, 20
    ctx->gpr[29] = ctx->gpr[1] + (u32)(s32)(20);

label_8003B808:
    ctx->pc = 0x8003B808u;
    // 8003B808: b       0x8003B964
    {
            goto label_8003B964;
    }

label_8003B80C:
    ctx->pc = 0x8003B80Cu;
    ctx->downcount -= 4;
    // 8003B80C: lwz     r3, 80(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(80);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003B810:
    ctx->pc = 0x8003B810u;
    // 8003B810: lbz     r0, 88(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(88);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003B814:
    // 8003B814: cmpw    r31, r0
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003B818:
    // 8003B818: bc    4, 0, 0x8003B8AC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003B8AC;
        }
    }

label_8003B81C:
    ctx->pc = 0x8003B81Cu;
    ctx->downcount -= 9;
    // 8003B81C: lwz     r4, 44(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(44);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8003B820:
    ctx->pc = 0x8003B820u;
    // 8003B820: lbz     r0, 173(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(173);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003B824:
    // 8003B824: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8003B828:
    // 8003B828: add   r3, r23, r0
    {
        u32 a = ctx->gpr[23];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8003B82C:
    // 8003B82C: addi    r0, r3, 42
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(42);

label_8003B830:
    ctx->pc = 0x8003B830u;
    // 8003B830: lbzx    r4, r4, r0
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[0];
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_8003B834:
    // 8003B834: extsb r4, r4
    {
        ctx->gpr[4] = (u32)(s32)(s8)ctx->gpr[4];
    }

label_8003B838:
    // 8003B838: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8003B83C:
    // 8003B83C: bl      0x800286CC
    {
            ctx->lr = 0x8003B840u;
            ctx->pc = 0x800286CCu;
            return;
    }

label_8003B840:
    ctx->pc = 0x8003B840u;
    ctx->downcount -= 14;
    // 8003B840: lwz     r4, 80(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(80);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8003B844:
    ctx->pc = 0x8003B844u;
    // 8003B844: lwz     r4, 44(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(44);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8003B848:
    // 8003B848: addi    r0, r23, 24
    ctx->gpr[0] = ctx->gpr[23] + (u32)(s32)(24);

label_8003B84C:
    ctx->pc = 0x8003B84Cu;
    // 8003B84C: lfsx    f0, r4, r0
    if (!ppc_fp_available_inline(ctx, 0x8003B84Cu)) return;
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[0];
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003B850:
    ctx->pc = 0x8003B850u;
    // 8003B850: stfs     f0, 0(r29)
    if (!ppc_fp_available_inline(ctx, 0x8003B850u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003B854:
    // 8003B854: addi    r0, r23, 28
    ctx->gpr[0] = ctx->gpr[23] + (u32)(s32)(28);

label_8003B858:
    ctx->pc = 0x8003B858u;
    // 8003B858: lfsx    f0, r4, r0
    if (!ppc_fp_available_inline(ctx, 0x8003B858u)) return;
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[0];
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003B85C:
    ctx->pc = 0x8003B85Cu;
    // 8003B85C: stfs     f0, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B85Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003B860:
    // 8003B860: addi    r0, r23, 32
    ctx->gpr[0] = ctx->gpr[23] + (u32)(s32)(32);

label_8003B864:
    ctx->pc = 0x8003B864u;
    // 8003B864: lfsx    f0, r4, r0
    if (!ppc_fp_available_inline(ctx, 0x8003B864u)) return;
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[0];
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003B868:
    ctx->pc = 0x8003B868u;
    // 8003B868: stfs     f0, 28(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B868u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003B86C:
    // 8003B86C: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8003B870:
    // 8003B870: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8003B874:
    // 8003B874: bl      0x80247E40
    {
            ctx->lr = 0x8003B878u;
            ctx->pc = 0x80247E40u;
            return;
    }

label_8003B878:
    ctx->pc = 0x8003B878u;
    ctx->downcount -= 13;
    // 8003B878: lfs     f1, 0(r29)
    if (!ppc_fp_available_inline(ctx, 0x8003B878u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003B87C:
    ctx->pc = 0x8003B87Cu;
    // 8003B87C: lfs     f0, -25520(r13)
    if (!ppc_fp_available_inline(ctx, 0x8003B87Cu)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25520);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003B880:
    ctx->pc = 0x8003B880u;
    // 8003B880: fadds   f2, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8003B880u)) return;
    ppc_fadds(ctx, 2, 1, 0);

label_8003B884:
    ctx->pc = 0x8003B884u;
    // 8003B884: stfs     f2, 0(r29)
    if (!ppc_fp_available_inline(ctx, 0x8003B884u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_8003B888:
    ctx->pc = 0x8003B888u;
    // 8003B888: lfs     f1, 28(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B888u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003B88C:
    ctx->pc = 0x8003B88Cu;
    // 8003B88C: lfs     f0, -25516(r13)
    if (!ppc_fp_available_inline(ctx, 0x8003B88Cu)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25516);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003B890:
    ctx->pc = 0x8003B890u;
    // 8003B890: fadds   f0, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8003B890u)) return;
    ppc_fadds(ctx, 0, 1, 0);

label_8003B894:
    ctx->pc = 0x8003B894u;
    // 8003B894: stfs     f0, 28(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B894u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003B898:
    ctx->pc = 0x8003B898u;
    // 8003B898: stfs     f2, 108(r30)
    if (!ppc_fp_available_inline(ctx, 0x8003B898u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(108);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_8003B89C:
    ctx->pc = 0x8003B89Cu;
    // 8003B89C: lfs     f0, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B89Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003B8A0:
    ctx->pc = 0x8003B8A0u;
    // 8003B8A0: stfs     f0, 116(r30)
    if (!ppc_fp_available_inline(ctx, 0x8003B8A0u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(116);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003B8A4:
    ctx->pc = 0x8003B8A4u;
    // 8003B8A4: lfs     f0, 28(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B8A4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003B8A8:
    ctx->pc = 0x8003B8A8u;
    // 8003B8A8: stfs     f0, 124(r30)
    if (!ppc_fp_available_inline(ctx, 0x8003B8A8u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(124);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003B8AC:
    ctx->pc = 0x8003B8ACu;
    ctx->downcount -= 4;
    // 8003B8AC: lwz     r3, 80(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(80);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003B8B0:
    ctx->pc = 0x8003B8B0u;
    // 8003B8B0: lbz     r0, 88(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(88);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003B8B4:
    // 8003B8B4: cmpw    r31, r0
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003B8B8:
    // 8003B8B8: bc    4, 0, 0x8003B954
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003B954;
        }
    }

label_8003B8BC:
    ctx->pc = 0x8003B8BCu;
    ctx->downcount -= 25;
    // 8003B8BC: lwz     r4, 44(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(44);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8003B8C0:
    // 8003B8C0: add   r5, r4, r23
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[23];
        u32 res = a + b;
        ctx->gpr[5] = res;
    }

label_8003B8C4:
    ctx->pc = 0x8003B8C4u;
    // 8003B8C4: lbz     r0, 173(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(173);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003B8C8:
    // 8003B8C8: extsb r3, r0
    {
        ctx->gpr[3] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8003B8CC:
    // 8003B8CC: addi    r0, r3, 18
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(18);

label_8003B8D0:
    ctx->pc = 0x8003B8D0u;
    // 8003B8D0: lbzx    r6, r5, r0
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[0];
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_8003B8D4:
    // 8003B8D4: extsb r6, r6
    {
        ctx->gpr[6] = (u32)(s32)(s8)ctx->gpr[6];
    }

label_8003B8D8:
    ctx->pc = 0x8003B8D8u;
    // 8003B8D8: lhz     r0, 24(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8003B8DC:
    // 8003B8DC: rlwinm r0, r0, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000001u;
    }

label_8003B8E0:
    // 8003B8E0: rlwinm r3, r0, 2, 0, 29
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_8003B8E4:
    // 8003B8E4: addi    r0, r3, 12
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(12);

label_8003B8E8:
    ctx->pc = 0x8003B8E8u;
    // 8003B8E8: lwzx    r3, r26, r0
    {
        u32 ea = ctx->gpr[26] + ctx->gpr[0];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003B8EC:
    // 8003B8EC: rlwinm r0, r6, 6, 0, 25
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 6u) & 0xFFFFFFC0u;
    }

label_8003B8F0:
    // 8003B8F0: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8003B8F4:
    ctx->pc = 0x8003B8F4u;
    // 8003B8F4: lfs     f0, 0(r5)
    if (!ppc_fp_available_inline(ctx, 0x8003B8F4u)) return;
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003B8F8:
    ctx->pc = 0x8003B8F8u;
    // 8003B8F8: stfs     f0, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B8F8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003B8FC:
    // 8003B8FC: addi    r0, r23, 4
    ctx->gpr[0] = ctx->gpr[23] + (u32)(s32)(4);

label_8003B900:
    ctx->pc = 0x8003B900u;
    // 8003B900: lfsx    f0, r4, r0
    if (!ppc_fp_available_inline(ctx, 0x8003B900u)) return;
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[0];
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003B904:
    ctx->pc = 0x8003B904u;
    // 8003B904: stfs     f0, 12(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B904u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003B908:
    // 8003B908: addi    r0, r23, 8
    ctx->gpr[0] = ctx->gpr[23] + (u32)(s32)(8);

label_8003B90C:
    ctx->pc = 0x8003B90Cu;
    // 8003B90C: lfsx    f0, r4, r0
    if (!ppc_fp_available_inline(ctx, 0x8003B90Cu)) return;
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[0];
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003B910:
    ctx->pc = 0x8003B910u;
    // 8003B910: stfs     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B910u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003B914:
    // 8003B914: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_8003B918:
    // 8003B918: or   r5, r4, r4
    {
        ctx->gpr[5] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8003B91C:
    // 8003B91C: bl      0x80247E40
    {
            ctx->lr = 0x8003B920u;
            ctx->pc = 0x80247E40u;
            return;
    }

label_8003B920:
    ctx->pc = 0x8003B920u;
    ctx->downcount -= 13;
    // 8003B920: lfs     f1, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B920u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003B924:
    ctx->pc = 0x8003B924u;
    // 8003B924: lfs     f0, -25520(r13)
    if (!ppc_fp_available_inline(ctx, 0x8003B924u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25520);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003B928:
    ctx->pc = 0x8003B928u;
    // 8003B928: fadds   f2, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8003B928u)) return;
    ppc_fadds(ctx, 2, 1, 0);

label_8003B92C:
    ctx->pc = 0x8003B92Cu;
    // 8003B92C: stfs     f2, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B92Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_8003B930:
    ctx->pc = 0x8003B930u;
    // 8003B930: lfs     f1, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B930u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003B934:
    ctx->pc = 0x8003B934u;
    // 8003B934: lfs     f0, -25516(r13)
    if (!ppc_fp_available_inline(ctx, 0x8003B934u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25516);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003B938:
    ctx->pc = 0x8003B938u;
    // 8003B938: fadds   f0, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8003B938u)) return;
    ppc_fadds(ctx, 0, 1, 0);

label_8003B93C:
    ctx->pc = 0x8003B93Cu;
    // 8003B93C: stfs     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B93Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003B940:
    ctx->pc = 0x8003B940u;
    // 8003B940: stfs     f2, 84(r30)
    if (!ppc_fp_available_inline(ctx, 0x8003B940u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(84);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_8003B944:
    ctx->pc = 0x8003B944u;
    // 8003B944: lfs     f0, 12(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B944u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003B948:
    ctx->pc = 0x8003B948u;
    // 8003B948: stfs     f0, 92(r30)
    if (!ppc_fp_available_inline(ctx, 0x8003B948u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(92);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003B94C:
    ctx->pc = 0x8003B94Cu;
    // 8003B94C: lfs     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B94Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003B950:
    ctx->pc = 0x8003B950u;
    // 8003B950: stfs     f0, 100(r30)
    if (!ppc_fp_available_inline(ctx, 0x8003B950u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(100);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003B954:
    ctx->downcount -= 4;
    // 8003B954: addi    r31, r31, 2
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(2);

label_8003B958:
    // 8003B958: addi    r23, r23, 48
    ctx->gpr[23] = ctx->gpr[23] + (u32)(s32)(48);

label_8003B95C:
    // 8003B95C: addi    r30, r30, 4
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(4);

label_8003B960:
    // 8003B960: addi    r28, r28, 1
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(1);

label_8003B964:
    ctx->pc = 0x8003B964u;
    ctx->downcount -= 3;
    // 8003B964: lha     r0, 176(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(176);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003B968:
    // 8003B968: cmpw    r28, r0
    {
        s32 val_a = (s32)(ctx->gpr[28]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003B96C:
    // 8003B96C: bc    12, 0, 0x8003B80C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003B80Cu;
                return;
            }
            goto label_8003B80C;
        }
    }

label_8003B970:
    ctx->pc = 0x8003B970u;
    ctx->downcount -= 2;
    // 8003B970: cmpwi   r0, 0
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

label_8003B974:
    ctx->pc = 0x8003B974u;
    // 8003B974: bc    12, 2, 0x8003BA34
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003BA34;
        }
    }

label_8003B978:
    ctx->pc = 0x8003B978u;
    ctx->downcount -= 18;
    // 8003B978: lha     r0, 178(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(178);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003B97C:
    ctx->pc = 0x8003B97Cu;
    // 8003B97C: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_8003B980:
    ctx->pc = 0x8003B980u;
    // 8003B980: add   r3, r27, r0
    {
        u32 a = ctx->gpr[27];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8003B984:
    ctx->pc = 0x8003B984u;
    // 8003B984: lfs     f0, 108(r3)
    if (!ppc_fp_available_inline(ctx, 0x8003B984u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(108);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003B988:
    ctx->pc = 0x8003B988u;
    // 8003B988: stfs     f0, 20(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B988u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003B98C:
    ctx->pc = 0x8003B98Cu;
    // 8003B98C: lfs     f0, 116(r3)
    if (!ppc_fp_available_inline(ctx, 0x8003B98Cu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(116);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003B990:
    ctx->pc = 0x8003B990u;
    // 8003B990: stfs     f0, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B990u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003B994:
    ctx->pc = 0x8003B994u;
    // 8003B994: lfs     f0, 124(r3)
    if (!ppc_fp_available_inline(ctx, 0x8003B994u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(124);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003B998:
    ctx->pc = 0x8003B998u;
    // 8003B998: stfs     f0, 28(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B998u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003B99C:
    ctx->pc = 0x8003B99Cu;
    // 8003B99C: or   r3, r24, r24
    {
        ctx->gpr[3] = ctx->gpr[24] | ctx->gpr[24];
    }

label_8003B9A0:
    ctx->pc = 0x8003B9A0u;
    // 8003B9A0: or   r4, r25, r25
    {
        ctx->gpr[4] = ctx->gpr[25] | ctx->gpr[25];
    }

label_8003B9A4:
    ctx->pc = 0x8003B9A4u;
    // 8003B9A4: addi    r5, r1, 8
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(8);

label_8003B9A8:
    ctx->pc = 0x8003B9A8u;
    // 8003B9A8: lwz     r6, 104(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(104);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8003B9AC:
    ctx->pc = 0x8003B9ACu;
    // 8003B9AC: lwz     r6, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8003B9B0:
    ctx->pc = 0x8003B9B0u;
    // 8003B9B0: lwz     r12, 40(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(40);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_8003B9B4:
    ctx->pc = 0x8003B9B4u;
    // 8003B9B4: mtctr    r12
    ctx->ctr = ctx->gpr[12];

label_8003B9B8:
    ctx->pc = 0x8003B9B8u;
    // 8003B9B8: bctrl
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8003B9BCu;
            ctx->pc = target;
            return;
        }
    }

label_8003B9BC:
    ctx->pc = 0x8003B9BCu;
    ctx->downcount -= 13;
    // 8003B9BC: lfs     f1, 20(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B9BCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003B9C0:
    ctx->pc = 0x8003B9C0u;
    // 8003B9C0: lfs     f0, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B9C0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003B9C4:
    ctx->pc = 0x8003B9C4u;
    // 8003B9C4: fsubs   f1, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8003B9C4u)) return;
    ppc_fsubs(ctx, 1, 1, 0);

label_8003B9C8:
    ctx->pc = 0x8003B9C8u;
    // 8003B9C8: stfs     f1, 20(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B9C8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8003B9CC:
    ctx->pc = 0x8003B9CCu;
    // 8003B9CC: lfs     f2, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B9CCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8003B9D0:
    ctx->pc = 0x8003B9D0u;
    // 8003B9D0: lfs     f0, 12(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B9D0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003B9D4:
    ctx->pc = 0x8003B9D4u;
    // 8003B9D4: fsubs   f0, f2, f0
    if (!ppc_fp_available_inline(ctx, 0x8003B9D4u)) return;
    ppc_fsubs(ctx, 0, 2, 0);

label_8003B9D8:
    ctx->pc = 0x8003B9D8u;
    // 8003B9D8: stfs     f0, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B9D8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003B9DC:
    ctx->pc = 0x8003B9DCu;
    // 8003B9DC: lfs     f2, 28(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B9DCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8003B9E0:
    ctx->pc = 0x8003B9E0u;
    // 8003B9E0: lfs     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B9E0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003B9E4:
    ctx->pc = 0x8003B9E4u;
    // 8003B9E4: fsubs   f2, f2, f0
    if (!ppc_fp_available_inline(ctx, 0x8003B9E4u)) return;
    ppc_fsubs(ctx, 2, 2, 0);

label_8003B9E8:
    ctx->pc = 0x8003B9E8u;
    // 8003B9E8: stfs     f2, 28(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B9E8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_8003B9EC:
    ctx->pc = 0x8003B9ECu;
    // 8003B9EC: bl      0x80021928
    {
            ctx->lr = 0x8003B9F0u;
            ctx->pc = 0x80021928u;
            return;
    }

label_8003B9F0:
    ctx->pc = 0x8003B9F0u;
    ctx->downcount -= 8;
    // 8003B9F0: extsh r0, r3
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[3];
    }

label_8003B9F4:
    ctx->pc = 0x8003B9F4u;
    // 8003B9F4: sth     r0, 0(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003B9F8:
    ctx->pc = 0x8003B9F8u;
    // 8003B9F8: lfs     f0, 20(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003B9F8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003B9FC:
    ctx->pc = 0x8003B9FCu;
    // 8003B9FC: fmuls   f1, f0, f0
    if (!ppc_fp_available_inline(ctx, 0x8003B9FCu)) return;
    ppc_fmuls(ctx, 1, 0, 0);

label_8003BA00:
    ctx->pc = 0x8003BA00u;
    // 8003BA00: lfs     f0, 28(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BA00u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003BA04:
    ctx->pc = 0x8003BA04u;
    // 8003BA04: fmuls   f0, f0, f0
    if (!ppc_fp_available_inline(ctx, 0x8003BA04u)) return;
    ppc_fmuls(ctx, 0, 0, 0);

label_8003BA08:
    ctx->pc = 0x8003BA08u;
    // 8003BA08: fadds   f1, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8003BA08u)) return;
    ppc_fadds(ctx, 1, 1, 0);

label_8003BA0C:
    ctx->pc = 0x8003BA0Cu;
    // 8003BA0C: bl      0x80293B10
    {
            ctx->lr = 0x8003BA10u;
            ctx->pc = 0x80293B10u;
            return;
    }

label_8003BA10:
    ctx->pc = 0x8003BA10u;
    ctx->downcount -= 3;
    // 8003BA10: fmr    f2, f1
    if (!ppc_fp_available_inline(ctx, 0x8003BA10u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_8003BA14:
    ctx->pc = 0x8003BA14u;
    // 8003BA14: lfs     f1, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BA14u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003BA18:
    ctx->pc = 0x8003BA18u;
    // 8003BA18: bl      0x80021928
    {
            ctx->lr = 0x8003BA1Cu;
            ctx->pc = 0x80021928u;
            return;
    }

label_8003BA1C:
    ctx->pc = 0x8003BA1Cu;
    ctx->downcount -= 6;
    // 8003BA1C: neg  r3, r3
    {
        u32 a = ctx->gpr[3];
        ctx->gpr[3] = (~a) + 1u;
    }

label_8003BA20:
    ctx->pc = 0x8003BA20u;
    // 8003BA20: addi    r0, r3, 16384
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(16384);

label_8003BA24:
    ctx->pc = 0x8003BA24u;
    // 8003BA24: extsh r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_8003BA28:
    ctx->pc = 0x8003BA28u;
    // 8003BA28: sth     r0, 2(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003BA2C:
    ctx->pc = 0x8003BA2Cu;
    // 8003BA2C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8003BA30:
    ctx->pc = 0x8003BA30u;
    // 8003BA30: sth     r0, 4(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003BA34:
    ctx->pc = 0x8003BA34u;
    ctx->downcount -= 2;
    // 8003BA34: addi    r11, r1, 80
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(80);

label_8003BA38:
    ctx->pc = 0x8003BA38u;
    // 8003BA38: bl      0x80286A88
    {
            ctx->lr = 0x8003BA3Cu;
            ctx->pc = 0x80286A88u;
            return;
    }

label_8003BA3C:
    ctx->pc = 0x8003BA3Cu;
    ctx->downcount -= 5;
    // 8003BA3C: lwz     r0, 84(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003BA40:
    ctx->pc = 0x8003BA40u;
    // 8003BA40: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8003BA44:
    ctx->pc = 0x8003BA44u;
    // 8003BA44: addi    r1, r1, 80
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(80);

label_8003BA48:
    ctx->pc = 0x8003BA48u;
    // 8003BA48: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8003A6E0;
        }
    }

label_8003BA4C:
    ctx->pc = 0x8003BA4Cu;
    ctx->downcount -= 10;
    // 8003BA4C: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8003BA50:
    ctx->pc = 0x8003BA50u;
    // 8003BA50: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8003BA54:
    ctx->pc = 0x8003BA54u;
    // 8003BA54: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003BA58:
    ctx->pc = 0x8003BA58u;
    // 8003BA58: lwz     r4, 124(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(124);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8003BA5C:
    ctx->pc = 0x8003BA5Cu;
    // 8003BA5C: lbz     r0, 173(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(173);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003BA60:
    ctx->pc = 0x8003BA60u;
    // 8003BA60: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8003BA64:
    ctx->pc = 0x8003BA64u;
    // 8003BA64: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_8003BA68:
    ctx->pc = 0x8003BA68u;
    // 8003BA68: lwzx    r0, r4, r0
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003BA6C:
    ctx->pc = 0x8003BA6Cu;
    // 8003BA6C: cmplwi  r0, 0x0000
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

label_8003BA70:
    ctx->pc = 0x8003BA70u;
    // 8003BA70: bc    12, 2, 0x8003BA78
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003BA78;
        }
    }

label_8003BA74:
    ctx->pc = 0x8003BA74u;
    ctx->downcount -= 1;
    // 8003BA74: bl      0x80041884
    {
            ctx->lr = 0x8003BA78u;
            ctx->pc = 0x80041884u;
            return;
    }

label_8003BA78:
    ctx->pc = 0x8003BA78u;
    ctx->downcount -= 5;
    // 8003BA78: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003BA7C:
    ctx->pc = 0x8003BA7Cu;
    // 8003BA7C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8003BA80:
    ctx->pc = 0x8003BA80u;
    // 8003BA80: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8003BA84:
    ctx->pc = 0x8003BA84u;
    // 8003BA84: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8003A6E0;
        }
    }

label_8003BA88:
    ctx->pc = 0x8003BA88u;
    ctx->downcount -= 12;
    // 8003BA88: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8003BA8C:
    ctx->pc = 0x8003BA8Cu;
    // 8003BA8C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8003BA90:
    ctx->pc = 0x8003BA90u;
    // 8003BA90: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003BA94:
    ctx->pc = 0x8003BA94u;
    // 8003BA94: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8003BA98:
    ctx->pc = 0x8003BA98u;
    // 8003BA98: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003BA9C:
    ctx->pc = 0x8003BA9Cu;
    // 8003BA9C: lwz     r4, 124(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(124);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8003BAA0:
    ctx->pc = 0x8003BAA0u;
    // 8003BAA0: lbz     r0, 173(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(173);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003BAA4:
    ctx->pc = 0x8003BAA4u;
    // 8003BAA4: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8003BAA8:
    ctx->pc = 0x8003BAA8u;
    // 8003BAA8: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_8003BAAC:
    ctx->pc = 0x8003BAACu;
    // 8003BAAC: lwzx    r0, r4, r0
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003BAB0:
    ctx->pc = 0x8003BAB0u;
    // 8003BAB0: cmplwi  r0, 0x0000
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

label_8003BAB4:
    ctx->pc = 0x8003BAB4u;
    // 8003BAB4: bc    12, 2, 0x8003BAD0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003BAD0;
        }
    }

label_8003BAB8:
    ctx->pc = 0x8003BAB8u;
    ctx->downcount -= 1;
    // 8003BAB8: bl      0x80041C58
    {
            ctx->lr = 0x8003BABCu;
            ctx->pc = 0x80041C58u;
            return;
    }

label_8003BABC:
    ctx->pc = 0x8003BABCu;
    ctx->downcount -= 3;
    // 8003BABC: lwz     r0, 116(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(116);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003BAC0:
    ctx->pc = 0x8003BAC0u;
    // 8003BAC0: cmplwi  r0, 0x0000
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

label_8003BAC4:
    ctx->pc = 0x8003BAC4u;
    // 8003BAC4: bc    12, 2, 0x8003BAD0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003BAD0;
        }
    }

label_8003BAC8:
    ctx->pc = 0x8003BAC8u;
    ctx->downcount -= 2;
    // 8003BAC8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8003BACC:
    ctx->pc = 0x8003BACCu;
    // 8003BACC: bl      0x800411AC
    {
            ctx->lr = 0x8003BAD0u;
            ctx->pc = 0x800411ACu;
            return;
    }

label_8003BAD0:
    ctx->pc = 0x8003BAD0u;
    ctx->downcount -= 6;
    // 8003BAD0: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8003BAD4:
    ctx->pc = 0x8003BAD4u;
    // 8003BAD4: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003BAD8:
    ctx->pc = 0x8003BAD8u;
    // 8003BAD8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8003BADC:
    ctx->pc = 0x8003BADCu;
    // 8003BADC: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8003BAE0:
    ctx->pc = 0x8003BAE0u;
    // 8003BAE0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8003A6E0;
        }
    }

label_8003BAE4:
    ctx->pc = 0x8003BAE4u;
    ctx->downcount -= 2;
    // 8003BAE4: stw     r3, -25976(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25976);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8003BAE8:
    ctx->pc = 0x8003BAE8u;
    // 8003BAE8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8003A6E0;
        }
    }

label_8003BAEC:
    ctx->pc = 0x8003BAECu;
    ctx->downcount -= 5;
    // 8003BAEC: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8003BAF0:
    ctx->pc = 0x8003BAF0u;
    // 8003BAF0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8003BAF4:
    ctx->pc = 0x8003BAF4u;
    // 8003BAF4: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003BAF8:
    ctx->pc = 0x8003BAF8u;
    // 8003BAF8: addi    r11, r1, 32
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(32);

label_8003BAFC:
    ctx->pc = 0x8003BAFCu;
    // 8003BAFC: bl      0x80286A48
    {
            ctx->lr = 0x8003BB00u;
            ctx->pc = 0x80286A48u;
            return;
    }

label_8003BB00:
    ctx->pc = 0x8003BB00u;
    ctx->downcount -= 10;
    // 8003BB00: or   r26, r3, r3
    {
        ctx->gpr[26] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003BB04:
    ctx->pc = 0x8003BB04u;
    // 8003BB04: or   r27, r4, r4
    {
        ctx->gpr[27] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8003BB08:
    ctx->pc = 0x8003BB08u;
    // 8003BB08: or   r28, r5, r5
    {
        ctx->gpr[28] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8003BB0C:
    ctx->pc = 0x8003BB0Cu;
    // 8003BB0C: or   r29, r6, r6
    {
        ctx->gpr[29] = ctx->gpr[6] | ctx->gpr[6];
    }

label_8003BB10:
    ctx->pc = 0x8003BB10u;
    // 8003BB10: or   r30, r7, r7
    {
        ctx->gpr[30] = ctx->gpr[7] | ctx->gpr[7];
    }

label_8003BB14:
    ctx->pc = 0x8003BB14u;
    // 8003BB14: or   r31, r8, r8
    {
        ctx->gpr[31] = ctx->gpr[8] | ctx->gpr[8];
    }

label_8003BB18:
    ctx->pc = 0x8003BB18u;
    // 8003BB18: lhz     r0, 176(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(176);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8003BB1C:
    ctx->pc = 0x8003BB1Cu;
    // 8003BB1C: rlwinm r0, r0, 0, 25, 25
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000040u;
    }

label_8003BB20:
    ctx->pc = 0x8003BB20u;
    // 8003BB20: cmpwi   r0, 0
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

label_8003BB24:
    ctx->pc = 0x8003BB24u;
    // 8003BB24: bc    4, 2, 0x8003BCF0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003BCF0;
        }
    }

label_8003BB28:
    ctx->pc = 0x8003BB28u;
    ctx->downcount -= 3;
    // 8003BB28: lwz     r0, 196(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(196);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003BB2C:
    ctx->pc = 0x8003BB2Cu;
    // 8003BB2C: cmplwi  r0, 0x0000
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

label_8003BB30:
    ctx->pc = 0x8003BB30u;
    // 8003BB30: bc    12, 2, 0x8003BB38
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003BB38;
        }
    }

label_8003BB34:
    ctx->pc = 0x8003BB34u;
    ctx->downcount -= 1;
    // 8003BB34: b       0x8003BCF0
    {
            goto label_8003BCF0;
    }

label_8003BB38:
    ctx->pc = 0x8003BB38u;
    ctx->downcount -= 4;
    // 8003BB38: lha     r0, 6(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(6);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003BB3C:
    ctx->pc = 0x8003BB3Cu;
    // 8003BB3C: rlwinm r0, r0, 0, 17, 17
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00004000u;
    }

label_8003BB40:
    ctx->pc = 0x8003BB40u;
    // 8003BB40: cmpwi   r0, 0
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

label_8003BB44:
    ctx->pc = 0x8003BB44u;
    // 8003BB44: bc    4, 2, 0x8003BCF0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003BCF0;
        }
    }

label_8003BB48:
    ctx->pc = 0x8003BB48u;
    ctx->downcount -= 3;
    // 8003BB48: lwz     r3, 48(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(48);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003BB4C:
    ctx->pc = 0x8003BB4Cu;
    // 8003BB4C: cmplwi  r3, 0x0000
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

label_8003BB50:
    ctx->pc = 0x8003BB50u;
    // 8003BB50: bc    12, 2, 0x8003BB64
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003BB64;
        }
    }

label_8003BB54:
    ctx->pc = 0x8003BB54u;
    ctx->downcount -= 4;
    // 8003BB54: lha     r0, 6(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(6);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003BB58:
    ctx->pc = 0x8003BB58u;
    // 8003BB58: rlwinm r0, r0, 0, 17, 17
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00004000u;
    }

label_8003BB5C:
    ctx->pc = 0x8003BB5Cu;
    // 8003BB5C: cmpwi   r0, 0
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

label_8003BB60:
    ctx->pc = 0x8003BB60u;
    // 8003BB60: bc    4, 2, 0x8003BCF0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003BCF0;
        }
    }

label_8003BB64:
    ctx->pc = 0x8003BB64u;
    ctx->downcount -= 2;
    // 8003BB64: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_8003BB68:
    ctx->pc = 0x8003BB68u;
    // 8003BB68: bl      0x8002A74C
    {
            ctx->lr = 0x8003BB6Cu;
            ctx->pc = 0x8002A74Cu;
            return;
    }

label_8003BB6C:
    ctx->pc = 0x8003BB6Cu;
    ctx->downcount -= 7;
    // 8003BB6C: lhz     r0, 176(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(176);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8003BB70:
    ctx->pc = 0x8003BB70u;
    // 8003BB70: ori     r0, r0, 0x0800
    ctx->gpr[0] = ctx->gpr[0] | 0x0800u;

label_8003BB74:
    ctx->pc = 0x8003BB74u;
    // 8003BB74: rlwinm r0, r0, 0, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x0000FFFFu;
    }

label_8003BB78:
    ctx->pc = 0x8003BB78u;
    // 8003BB78: sth     r0, 176(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(176);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003BB7C:
    ctx->pc = 0x8003BB7Cu;
    // 8003BB7C: lwz     r3, 104(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(104);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003BB80:
    ctx->pc = 0x8003BB80u;
    // 8003BB80: cmplwi  r3, 0x0000
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

label_8003BB84:
    ctx->pc = 0x8003BB84u;
    // 8003BB84: bc    12, 2, 0x8003BC14
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003BC14;
        }
    }

label_8003BB88:
    ctx->pc = 0x8003BB88u;
    ctx->downcount -= 4;
    // 8003BB88: lhz     r0, 176(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(176);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8003BB8C:
    ctx->pc = 0x8003BB8Cu;
    // 8003BB8C: rlwinm r0, r0, 0, 17, 17
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00004000u;
    }

label_8003BB90:
    ctx->pc = 0x8003BB90u;
    // 8003BB90: cmpwi   r0, 0
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

label_8003BB94:
    ctx->pc = 0x8003BB94u;
    // 8003BB94: bc    4, 2, 0x8003BBCC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003BBCC;
        }
    }

label_8003BB98:
    ctx->pc = 0x8003BB98u;
    ctx->downcount -= 4;
    // 8003BB98: lwz     r3, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003BB9C:
    ctx->pc = 0x8003BB9Cu;
    // 8003BB9C: lwz     r12, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_8003BBA0:
    ctx->pc = 0x8003BBA0u;
    // 8003BBA0: cmplwi  r12, 0x0000
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

label_8003BBA4:
    ctx->pc = 0x8003BBA4u;
    // 8003BBA4: bc    12, 2, 0x8003BC94
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003BC94;
        }
    }

label_8003BBA8:
    ctx->pc = 0x8003BBA8u;
    ctx->downcount -= 9;
    // 8003BBA8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8003BBAC:
    ctx->pc = 0x8003BBACu;
    // 8003BBAC: or   r4, r26, r26
    {
        ctx->gpr[4] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8003BBB0:
    ctx->pc = 0x8003BBB0u;
    // 8003BBB0: or   r5, r27, r27
    {
        ctx->gpr[5] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8003BBB4:
    ctx->pc = 0x8003BBB4u;
    // 8003BBB4: or   r6, r28, r28
    {
        ctx->gpr[6] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8003BBB8:
    ctx->pc = 0x8003BBB8u;
    // 8003BBB8: or   r7, r29, r29
    {
        ctx->gpr[7] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8003BBBC:
    ctx->pc = 0x8003BBBCu;
    // 8003BBBC: or   r8, r31, r31
    {
        ctx->gpr[8] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8003BBC0:
    ctx->pc = 0x8003BBC0u;
    // 8003BBC0: mtctr    r12
    ctx->ctr = ctx->gpr[12];

label_8003BBC4:
    ctx->pc = 0x8003BBC4u;
    // 8003BBC4: bctrl
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8003BBC8u;
            ctx->pc = target;
            return;
        }
    }

label_8003BBC8:
    ctx->pc = 0x8003BBC8u;
    ctx->downcount -= 1;
    // 8003BBC8: b       0x8003BC94
    {
            goto label_8003BC94;
    }

label_8003BBCC:
    ctx->pc = 0x8003BBCCu;
    ctx->downcount -= 3;
    // 8003BBCC: extsb r0, r31
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[31];
    }

label_8003BBD0:
    ctx->pc = 0x8003BBD0u;
    // 8003BBD0: cmpwi   r0, 0
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

label_8003BBD4:
    ctx->pc = 0x8003BBD4u;
    // 8003BBD4: bc    12, 2, 0x8003BC94
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003BC94;
        }
    }

label_8003BBD8:
    ctx->pc = 0x8003BBD8u;
    ctx->downcount -= 7;
    // 8003BBD8: lwz     r3, 124(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(124);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003BBDC:
    ctx->pc = 0x8003BBDCu;
    // 8003BBDC: lbz     r0, 173(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(173);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003BBE0:
    ctx->pc = 0x8003BBE0u;
    // 8003BBE0: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8003BBE4:
    ctx->pc = 0x8003BBE4u;
    // 8003BBE4: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_8003BBE8:
    ctx->pc = 0x8003BBE8u;
    // 8003BBE8: lwzx    r0, r3, r0
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003BBEC:
    ctx->pc = 0x8003BBECu;
    // 8003BBEC: cmplwi  r0, 0x0000
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

label_8003BBF0:
    ctx->pc = 0x8003BBF0u;
    // 8003BBF0: bc    12, 2, 0x8003BC94
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003BC94;
        }
    }

label_8003BBF4:
    ctx->pc = 0x8003BBF4u;
    ctx->downcount -= 2;
    // 8003BBF4: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8003BBF8:
    ctx->pc = 0x8003BBF8u;
    // 8003BBF8: bl      0x80041C58
    {
            ctx->lr = 0x8003BBFCu;
            ctx->pc = 0x80041C58u;
            return;
    }

label_8003BBFC:
    ctx->pc = 0x8003BBFCu;
    ctx->downcount -= 3;
    // 8003BBFC: lwz     r0, 116(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(116);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003BC00:
    ctx->pc = 0x8003BC00u;
    // 8003BC00: cmplwi  r0, 0x0000
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

label_8003BC04:
    ctx->pc = 0x8003BC04u;
    // 8003BC04: bc    12, 2, 0x8003BC94
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003BC94;
        }
    }

label_8003BC08:
    ctx->pc = 0x8003BC08u;
    ctx->downcount -= 2;
    // 8003BC08: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8003BC0C:
    ctx->pc = 0x8003BC0Cu;
    // 8003BC0C: bl      0x800411AC
    {
            ctx->lr = 0x8003BC10u;
            ctx->pc = 0x800411ACu;
            return;
    }

label_8003BC10:
    ctx->pc = 0x8003BC10u;
    ctx->downcount -= 1;
    // 8003BC10: b       0x8003BC94
    {
            goto label_8003BC94;
    }

label_8003BC14:
    ctx->pc = 0x8003BC14u;
    ctx->downcount -= 3;
    // 8003BC14: extsb r0, r31
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[31];
    }

label_8003BC18:
    ctx->pc = 0x8003BC18u;
    // 8003BC18: cmpwi   r0, 0
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

label_8003BC1C:
    ctx->pc = 0x8003BC1Cu;
    // 8003BC1C: bc    12, 2, 0x8003BC94
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003BC94;
        }
    }

label_8003BC20:
    ctx->pc = 0x8003BC20u;
    ctx->downcount -= 3;
    // 8003BC20: lha     r0, 70(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(70);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003BC24:
    ctx->pc = 0x8003BC24u;
    // 8003BC24: cmpwi   r0, 31
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(31);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003BC28:
    ctx->pc = 0x8003BC28u;
    // 8003BC28: bc    12, 2, 0x8003BC3C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003BC3C;
        }
    }

label_8003BC2C:
    ctx->pc = 0x8003BC2Cu;
    ctx->downcount -= 1;
    // 8003BC2C: bc    4, 0, 0x8003BC5C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003BC5C;
        }
    }

label_8003BC30:
    ctx->pc = 0x8003BC30u;
    ctx->downcount -= 2;
    // 8003BC30: cmpwi   r0, 0
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

label_8003BC34:
    ctx->pc = 0x8003BC34u;
    // 8003BC34: bc    12, 2, 0x8003BC3C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003BC3C;
        }
    }

label_8003BC38:
    ctx->pc = 0x8003BC38u;
    ctx->downcount -= 1;
    // 8003BC38: b       0x8003BC5C
    {
            goto label_8003BC5C;
    }

label_8003BC3C:
    ctx->pc = 0x8003BC3Cu;
    ctx->downcount -= 7;
    // 8003BC3C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8003BC40:
    ctx->pc = 0x8003BC40u;
    // 8003BC40: or   r4, r26, r26
    {
        ctx->gpr[4] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8003BC44:
    ctx->pc = 0x8003BC44u;
    // 8003BC44: or   r5, r27, r27
    {
        ctx->gpr[5] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8003BC48:
    ctx->pc = 0x8003BC48u;
    // 8003BC48: or   r6, r28, r28
    {
        ctx->gpr[6] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8003BC4C:
    ctx->pc = 0x8003BC4Cu;
    // 8003BC4C: or   r7, r29, r29
    {
        ctx->gpr[7] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8003BC50:
    ctx->pc = 0x8003BC50u;
    // 8003BC50: or   r8, r31, r31
    {
        ctx->gpr[8] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8003BC54:
    ctx->pc = 0x8003BC54u;
    // 8003BC54: bl      0x802B5A40
    {
            ctx->lr = 0x8003BC58u;
            ctx->pc = 0x802B5A40u;
            return;
    }

label_8003BC58:
    ctx->pc = 0x8003BC58u;
    ctx->downcount -= 1;
    // 8003BC58: b       0x8003BC94
    {
            goto label_8003BC94;
    }

label_8003BC5C:
    ctx->pc = 0x8003BC5Cu;
    ctx->downcount -= 7;
    // 8003BC5C: lwz     r3, 124(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(124);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003BC60:
    ctx->pc = 0x8003BC60u;
    // 8003BC60: lbz     r0, 173(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(173);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003BC64:
    ctx->pc = 0x8003BC64u;
    // 8003BC64: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8003BC68:
    ctx->pc = 0x8003BC68u;
    // 8003BC68: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_8003BC6C:
    ctx->pc = 0x8003BC6Cu;
    // 8003BC6C: lwzx    r0, r3, r0
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003BC70:
    ctx->pc = 0x8003BC70u;
    // 8003BC70: cmplwi  r0, 0x0000
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

label_8003BC74:
    ctx->pc = 0x8003BC74u;
    // 8003BC74: bc    12, 2, 0x8003BC94
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003BC94;
        }
    }

label_8003BC78:
    ctx->pc = 0x8003BC78u;
    ctx->downcount -= 2;
    // 8003BC78: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8003BC7C:
    ctx->pc = 0x8003BC7Cu;
    // 8003BC7C: bl      0x80041C58
    {
            ctx->lr = 0x8003BC80u;
            ctx->pc = 0x80041C58u;
            return;
    }

label_8003BC80:
    ctx->pc = 0x8003BC80u;
    ctx->downcount -= 3;
    // 8003BC80: lwz     r0, 116(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(116);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003BC84:
    ctx->pc = 0x8003BC84u;
    // 8003BC84: cmplwi  r0, 0x0000
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

label_8003BC88:
    ctx->pc = 0x8003BC88u;
    // 8003BC88: bc    12, 2, 0x8003BC94
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003BC94;
        }
    }

label_8003BC8C:
    ctx->pc = 0x8003BC8Cu;
    ctx->downcount -= 2;
    // 8003BC8C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8003BC90:
    ctx->pc = 0x8003BC90u;
    // 8003BC90: bl      0x800411AC
    {
            ctx->lr = 0x8003BC94u;
            ctx->pc = 0x800411ACu;
            return;
    }

label_8003BC94:
    ctx->pc = 0x8003BC94u;
    ctx->downcount -= 1;
    // 8003BC94: bl      0x8002A748
    {
            ctx->lr = 0x8003BC98u;
            ctx->pc = 0x8002A748u;
            return;
    }

label_8003BC98:
    ctx->pc = 0x8003BC98u;
    ctx->downcount -= 3;
    // 8003BC98: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_8003BC9C:
    ctx->pc = 0x8003BC9Cu;
    // 8003BC9C: or   r29, r30, r30
    {
        ctx->gpr[29] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8003BCA0:
    ctx->pc = 0x8003BCA0u;
    // 8003BCA0: b       0x8003BCE4
    {
            goto label_8003BCE4;
    }

label_8003BCA4:
    ctx->pc = 0x8003BCA4u;
    ctx->downcount -= 4;
    // 8003BCA4: lwz     r3, 200(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(200);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003BCA8:
    ctx->pc = 0x8003BCA8u;
    // 8003BCA8: lha     r0, 68(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(68);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003BCAC:
    // 8003BCAC: cmpwi   r0, 45
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(45);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003BCB0:
    // 8003BCB0: bc    4, 2, 0x8003BCDC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003BCDC;
        }
    }

label_8003BCB4:
    ctx->downcount -= 10;
    // 8003BCB4: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8003BCB8:
    ctx->pc = 0x8003BCB8u;
    // 8003BCB8: lwz     r5, 124(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(124);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8003BCBC:
    ctx->pc = 0x8003BCBCu;
    // 8003BCBC: lbz     r0, 173(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(173);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003BCC0:
    // 8003BCC0: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8003BCC4:
    // 8003BCC4: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_8003BCC8:
    ctx->pc = 0x8003BCC8u;
    // 8003BCC8: lwzx    r5, r5, r0
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[0];
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8003BCCC:
    // 8003BCCC: or   r6, r26, r26
    {
        ctx->gpr[6] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8003BCD0:
    // 8003BCD0: or   r7, r27, r27
    {
        ctx->gpr[7] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8003BCD4:
    // 8003BCD4: or   r8, r28, r28
    {
        ctx->gpr[8] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8003BCD8:
    // 8003BCD8: bl      0x8003B7B4
    {
            ctx->lr = 0x8003BCDCu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003B7B4u;
                return;
            }
            goto label_8003B7B4;
    }

label_8003BCDC:
    ctx->downcount -= 2;
    // 8003BCDC: addi    r29, r29, 4
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(4);

label_8003BCE0:
    // 8003BCE0: addi    r31, r31, 1
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(1);

label_8003BCE4:
    ctx->pc = 0x8003BCE4u;
    ctx->downcount -= 3;
    // 8003BCE4: lbz     r0, 235(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(235);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003BCE8:
    // 8003BCE8: cmpw    r31, r0
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003BCEC:
    // 8003BCEC: bc    12, 0, 0x8003BCA4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003BCA4u;
                return;
            }
            goto label_8003BCA4;
        }
    }

label_8003BCF0:
    ctx->pc = 0x8003BCF0u;
    ctx->downcount -= 2;
    // 8003BCF0: addi    r11, r1, 32
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(32);

label_8003BCF4:
    ctx->pc = 0x8003BCF4u;
    // 8003BCF4: bl      0x80286A94
    {
            ctx->lr = 0x8003BCF8u;
            ctx->pc = 0x80286A94u;
            return;
    }

label_8003BCF8:
    ctx->pc = 0x8003BCF8u;
    ctx->downcount -= 5;
    // 8003BCF8: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003BCFC:
    ctx->pc = 0x8003BCFCu;
    // 8003BCFC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8003BD00:
    ctx->pc = 0x8003BD00u;
    // 8003BD00: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_8003BD04:
    ctx->pc = 0x8003BD04u;
    // 8003BD04: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8003A6E0;
        }
    }

label_8003BD08:
    ctx->pc = 0x8003BD08u;
    ctx->downcount -= 2;
    // 8003BD08: lbz     r3, -25932(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25932);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8003BD0C:
    ctx->pc = 0x8003BD0Cu;
    // 8003BD0C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8003A6E0;
        }
    }

label_8003BD10:
    ctx->pc = 0x8003BD10u;
    ctx->downcount -= 2;
    // 8003BD10: stb     r3, -25932(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25932);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_8003BD14:
    ctx->pc = 0x8003BD14u;
    // 8003BD14: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8003A6E0;
        }
    }

label_8003BD18:
    ctx->pc = 0x8003BD18u;
    ctx->downcount -= 26;
    // 8003BD18: stwu     r1, -64(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-64);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8003BD1C:
    ctx->pc = 0x8003BD1Cu;
    // 8003BD1C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8003BD20:
    ctx->pc = 0x8003BD20u;
    // 8003BD20: stw     r0, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003BD24:
    ctx->pc = 0x8003BD24u;
    // 8003BD24: stw     r31, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8003BD28:
    ctx->pc = 0x8003BD28u;
    // 8003BD28: or   r31, r4, r4
    {
        ctx->gpr[31] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8003BD2C:
    ctx->pc = 0x8003BD2Cu;
    // 8003BD2C: lfs     f3, 0(r3)
    if (!ppc_fp_available_inline(ctx, 0x8003BD2Cu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8003BD30:
    ctx->pc = 0x8003BD30u;
    // 8003BD30: stfs     f3, 20(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BD30u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[3]));
    }

label_8003BD34:
    ctx->pc = 0x8003BD34u;
    // 8003BD34: lfs     f2, 4(r3)
    if (!ppc_fp_available_inline(ctx, 0x8003BD34u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8003BD38:
    ctx->pc = 0x8003BD38u;
    // 8003BD38: stfs     f2, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BD38u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_8003BD3C:
    ctx->pc = 0x8003BD3Cu;
    // 8003BD3C: lfs     f1, 8(r3)
    if (!ppc_fp_available_inline(ctx, 0x8003BD3Cu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003BD40:
    ctx->pc = 0x8003BD40u;
    // 8003BD40: stfs     f1, 28(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BD40u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8003BD44:
    ctx->pc = 0x8003BD44u;
    // 8003BD44: lfs     f0, 16(r3)
    if (!ppc_fp_available_inline(ctx, 0x8003BD44u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003BD48:
    ctx->pc = 0x8003BD48u;
    // 8003BD48: stfs     f0, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BD48u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003BD4C:
    ctx->pc = 0x8003BD4Cu;
    // 8003BD4C: lfs     f0, 20(r3)
    if (!ppc_fp_available_inline(ctx, 0x8003BD4Cu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003BD50:
    ctx->pc = 0x8003BD50u;
    // 8003BD50: stfs     f0, 12(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BD50u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003BD54:
    ctx->pc = 0x8003BD54u;
    // 8003BD54: lfs     f0, 24(r3)
    if (!ppc_fp_available_inline(ctx, 0x8003BD54u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003BD58:
    ctx->pc = 0x8003BD58u;
    // 8003BD58: stfs     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BD58u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003BD5C:
    ctx->pc = 0x8003BD5Cu;
    // 8003BD5C: lfs     f0, 32(r3)
    if (!ppc_fp_available_inline(ctx, 0x8003BD5Cu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(32);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003BD60:
    ctx->pc = 0x8003BD60u;
    // 8003BD60: stfs     f0, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BD60u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003BD64:
    ctx->pc = 0x8003BD64u;
    // 8003BD64: lfs     f0, 36(r3)
    if (!ppc_fp_available_inline(ctx, 0x8003BD64u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(36);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003BD68:
    ctx->pc = 0x8003BD68u;
    // 8003BD68: stfs     f0, 36(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BD68u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003BD6C:
    ctx->pc = 0x8003BD6Cu;
    // 8003BD6C: lfs     f0, 40(r3)
    if (!ppc_fp_available_inline(ctx, 0x8003BD6Cu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(40);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003BD70:
    ctx->pc = 0x8003BD70u;
    // 8003BD70: stfs     f0, 40(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BD70u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003BD74:
    ctx->pc = 0x8003BD74u;
    // 8003BD74: lfs     f0, -31476(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003BD74u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31476);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003BD78:
    ctx->pc = 0x8003BD78u;
    // 8003BD78: fcmpu   cr0, f3, f0
    if (!ppc_fp_available_inline(ctx, 0x8003BD78u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[3], ctx->fpr[0], false);

label_8003BD7C:
    ctx->pc = 0x8003BD7Cu;
    // 8003BD7C: bc    4, 2, 0x8003BD90
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003BD90;
        }
    }

label_8003BD80:
    ctx->pc = 0x8003BD80u;
    ctx->downcount -= 2;
    // 8003BD80: fcmpu   cr0, f2, f0
    if (!ppc_fp_available_inline(ctx, 0x8003BD80u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[2], ctx->fpr[0], false);

label_8003BD84:
    ctx->pc = 0x8003BD84u;
    // 8003BD84: bc    4, 2, 0x8003BD90
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003BD90;
        }
    }

label_8003BD88:
    ctx->pc = 0x8003BD88u;
    ctx->downcount -= 2;
    // 8003BD88: fcmpu   cr0, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8003BD88u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[1], ctx->fpr[0], false);

label_8003BD8C:
    ctx->pc = 0x8003BD8Cu;
    // 8003BD8C: bc    12, 2, 0x8003BDE0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003BDE0;
        }
    }

label_8003BD90:
    ctx->pc = 0x8003BD90u;
    ctx->downcount -= 4;
    // 8003BD90: lfs     f0, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BD90u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003BD94:
    ctx->pc = 0x8003BD94u;
    // 8003BD94: lfs     f1, -31476(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003BD94u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31476);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003BD98:
    ctx->pc = 0x8003BD98u;
    // 8003BD98: fcmpu   cr0, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8003BD98u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[0], ctx->fpr[1], false);

label_8003BD9C:
    ctx->pc = 0x8003BD9Cu;
    // 8003BD9C: bc    4, 2, 0x8003BDB8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003BDB8;
        }
    }

label_8003BDA0:
    ctx->pc = 0x8003BDA0u;
    ctx->downcount -= 3;
    // 8003BDA0: lfs     f0, 12(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BDA0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003BDA4:
    ctx->pc = 0x8003BDA4u;
    // 8003BDA4: fcmpu   cr0, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8003BDA4u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[0], ctx->fpr[1], false);

label_8003BDA8:
    ctx->pc = 0x8003BDA8u;
    // 8003BDA8: bc    4, 2, 0x8003BDB8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003BDB8;
        }
    }

label_8003BDAC:
    ctx->pc = 0x8003BDACu;
    ctx->downcount -= 3;
    // 8003BDAC: lfs     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BDACu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003BDB0:
    ctx->pc = 0x8003BDB0u;
    // 8003BDB0: fcmpu   cr0, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8003BDB0u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[0], ctx->fpr[1], false);

label_8003BDB4:
    ctx->pc = 0x8003BDB4u;
    // 8003BDB4: bc    12, 2, 0x8003BDE0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003BDE0;
        }
    }

label_8003BDB8:
    ctx->pc = 0x8003BDB8u;
    ctx->downcount -= 4;
    // 8003BDB8: lfs     f0, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BDB8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003BDBC:
    ctx->pc = 0x8003BDBCu;
    // 8003BDBC: lfs     f1, -31476(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003BDBCu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31476);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003BDC0:
    ctx->pc = 0x8003BDC0u;
    // 8003BDC0: fcmpu   cr0, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8003BDC0u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[0], ctx->fpr[1], false);

label_8003BDC4:
    ctx->pc = 0x8003BDC4u;
    // 8003BDC4: bc    4, 2, 0x8003BDE8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003BDE8;
        }
    }

label_8003BDC8:
    ctx->pc = 0x8003BDC8u;
    ctx->downcount -= 3;
    // 8003BDC8: lfs     f0, 36(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BDC8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003BDCC:
    ctx->pc = 0x8003BDCCu;
    // 8003BDCC: fcmpu   cr0, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8003BDCCu)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[0], ctx->fpr[1], false);

label_8003BDD0:
    ctx->pc = 0x8003BDD0u;
    // 8003BDD0: bc    4, 2, 0x8003BDE8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003BDE8;
        }
    }

label_8003BDD4:
    ctx->pc = 0x8003BDD4u;
    ctx->downcount -= 3;
    // 8003BDD4: lfs     f0, 40(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BDD4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003BDD8:
    ctx->pc = 0x8003BDD8u;
    // 8003BDD8: fcmpu   cr0, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8003BDD8u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[0], ctx->fpr[1], false);

label_8003BDDC:
    ctx->pc = 0x8003BDDCu;
    // 8003BDDC: bc    4, 2, 0x8003BDE8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003BDE8;
        }
    }

label_8003BDE0:
    ctx->pc = 0x8003BDE0u;
    ctx->downcount -= 2;
    // 8003BDE0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003BDE4:
    ctx->pc = 0x8003BDE4u;
    // 8003BDE4: b       0x8003BE68
    {
            goto label_8003BE68;
    }

label_8003BDE8:
    ctx->pc = 0x8003BDE8u;
    ctx->downcount -= 3;
    // 8003BDE8: addi    r3, r1, 20
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(20);

label_8003BDEC:
    ctx->pc = 0x8003BDECu;
    // 8003BDEC: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003BDF0:
    ctx->pc = 0x8003BDF0u;
    // 8003BDF0: bl      0x80248140
    {
            ctx->lr = 0x8003BDF4u;
            ctx->pc = 0x80248140u;
            return;
    }

label_8003BDF4:
    ctx->pc = 0x8003BDF4u;
    ctx->downcount -= 3;
    // 8003BDF4: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_8003BDF8:
    ctx->pc = 0x8003BDF8u;
    // 8003BDF8: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003BDFC:
    ctx->pc = 0x8003BDFCu;
    // 8003BDFC: bl      0x80248140
    {
            ctx->lr = 0x8003BE00u;
            ctx->pc = 0x80248140u;
            return;
    }

label_8003BE00:
    ctx->pc = 0x8003BE00u;
    ctx->downcount -= 3;
    // 8003BE00: addi    r3, r1, 32
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(32);

label_8003BE04:
    ctx->pc = 0x8003BE04u;
    // 8003BE04: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003BE08:
    ctx->pc = 0x8003BE08u;
    // 8003BE08: bl      0x80248140
    {
            ctx->lr = 0x8003BE0Cu;
            ctx->pc = 0x80248140u;
            return;
    }

label_8003BE0C:
    ctx->pc = 0x8003BE0Cu;
    ctx->downcount -= 23;
    // 8003BE0C: lfs     f0, 20(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BE0Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003BE10:
    ctx->pc = 0x8003BE10u;
    // 8003BE10: stfs     f0, 0(r31)
    if (!ppc_fp_available_inline(ctx, 0x8003BE10u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003BE14:
    ctx->pc = 0x8003BE14u;
    // 8003BE14: lfs     f0, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BE14u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003BE18:
    ctx->pc = 0x8003BE18u;
    // 8003BE18: stfs     f0, 4(r31)
    if (!ppc_fp_available_inline(ctx, 0x8003BE18u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003BE1C:
    ctx->pc = 0x8003BE1Cu;
    // 8003BE1C: lfs     f0, 28(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BE1Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003BE20:
    ctx->pc = 0x8003BE20u;
    // 8003BE20: stfs     f0, 8(r31)
    if (!ppc_fp_available_inline(ctx, 0x8003BE20u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003BE24:
    ctx->pc = 0x8003BE24u;
    // 8003BE24: lfs     f1, -31476(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003BE24u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31476);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003BE28:
    ctx->pc = 0x8003BE28u;
    // 8003BE28: stfs     f1, 12(r31)
    if (!ppc_fp_available_inline(ctx, 0x8003BE28u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8003BE2C:
    ctx->pc = 0x8003BE2Cu;
    // 8003BE2C: lfs     f0, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BE2Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003BE30:
    ctx->pc = 0x8003BE30u;
    // 8003BE30: stfs     f0, 16(r31)
    if (!ppc_fp_available_inline(ctx, 0x8003BE30u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003BE34:
    ctx->pc = 0x8003BE34u;
    // 8003BE34: lfs     f0, 12(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BE34u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003BE38:
    ctx->pc = 0x8003BE38u;
    // 8003BE38: stfs     f0, 20(r31)
    if (!ppc_fp_available_inline(ctx, 0x8003BE38u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003BE3C:
    ctx->pc = 0x8003BE3Cu;
    // 8003BE3C: lfs     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BE3Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003BE40:
    ctx->pc = 0x8003BE40u;
    // 8003BE40: stfs     f0, 24(r31)
    if (!ppc_fp_available_inline(ctx, 0x8003BE40u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003BE44:
    ctx->pc = 0x8003BE44u;
    // 8003BE44: stfs     f1, 28(r31)
    if (!ppc_fp_available_inline(ctx, 0x8003BE44u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8003BE48:
    ctx->pc = 0x8003BE48u;
    // 8003BE48: lfs     f0, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BE48u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003BE4C:
    ctx->pc = 0x8003BE4Cu;
    // 8003BE4C: stfs     f0, 32(r31)
    if (!ppc_fp_available_inline(ctx, 0x8003BE4Cu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(32);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003BE50:
    ctx->pc = 0x8003BE50u;
    // 8003BE50: lfs     f0, 36(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BE50u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003BE54:
    ctx->pc = 0x8003BE54u;
    // 8003BE54: stfs     f0, 36(r31)
    if (!ppc_fp_available_inline(ctx, 0x8003BE54u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(36);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003BE58:
    ctx->pc = 0x8003BE58u;
    // 8003BE58: lfs     f0, 40(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BE58u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003BE5C:
    ctx->pc = 0x8003BE5Cu;
    // 8003BE5C: stfs     f0, 40(r31)
    if (!ppc_fp_available_inline(ctx, 0x8003BE5Cu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003BE60:
    ctx->pc = 0x8003BE60u;
    // 8003BE60: stfs     f1, 44(r31)
    if (!ppc_fp_available_inline(ctx, 0x8003BE60u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8003BE64:
    ctx->pc = 0x8003BE64u;
    // 8003BE64: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003BE68:
    ctx->pc = 0x8003BE68u;
    ctx->downcount -= 6;
    // 8003BE68: lwz     r31, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8003BE6C:
    ctx->pc = 0x8003BE6Cu;
    // 8003BE6C: lwz     r0, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003BE70:
    ctx->pc = 0x8003BE70u;
    // 8003BE70: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8003BE74:
    ctx->pc = 0x8003BE74u;
    // 8003BE74: addi    r1, r1, 64
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(64);

label_8003BE78:
    ctx->pc = 0x8003BE78u;
    // 8003BE78: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8003A6E0;
        }
    }

label_8003BE7C:
    ctx->pc = 0x8003BE7Cu;
    ctx->downcount -= 15;
    // 8003BE7C: stwu     r1, -128(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-128);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8003BE80:
    ctx->pc = 0x8003BE80u;
    // 8003BE80: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8003BE84:
    ctx->pc = 0x8003BE84u;
    // 8003BE84: stw     r0, 132(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(132);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003BE88:
    ctx->pc = 0x8003BE88u;
    // 8003BE88: stfd     f31, 112(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BE88u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(112);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_8003BE8C:
    ctx->pc = 0x8003BE8Cu;
    // 8003BE8C: psq_st   f31, 120(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8003BE8Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(120);
        ppc_psq_store_inline(ctx, 31u, ea, false, 0u, false, 0x8003BE8Cu);
        if (ctx->exception) return;
    }

label_8003BE90:
    ctx->pc = 0x8003BE90u;
    // 8003BE90: stfd     f30, 96(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BE90u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[30]));
    }

label_8003BE94:
    ctx->pc = 0x8003BE94u;
    // 8003BE94: psq_st   f30, 104(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8003BE94u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        ppc_psq_store_inline(ctx, 30u, ea, false, 0u, false, 0x8003BE94u);
        if (ctx->exception) return;
    }

label_8003BE98:
    ctx->pc = 0x8003BE98u;
    // 8003BE98: stw     r31, 92(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8003BE9C:
    ctx->pc = 0x8003BE9Cu;
    // 8003BE9C: stw     r30, 88(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8003BEA0:
    ctx->pc = 0x8003BEA0u;
    // 8003BEA0: stw     r29, 84(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_8003BEA4:
    ctx->pc = 0x8003BEA4u;
    // 8003BEA4: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8003BEA8:
    ctx->pc = 0x8003BEA8u;
    // 8003BEA8: or   r30, r5, r5
    {
        ctx->gpr[30] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8003BEAC:
    ctx->pc = 0x8003BEACu;
    // 8003BEAC: or   r31, r6, r6
    {
        ctx->gpr[31] = ctx->gpr[6] | ctx->gpr[6];
    }

label_8003BEB0:
    ctx->pc = 0x8003BEB0u;
    // 8003BEB0: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_8003BEB4:
    ctx->pc = 0x8003BEB4u;
    // 8003BEB4: bl      0x8003BD18
    {
            ctx->lr = 0x8003BEB8u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003BD18u;
                return;
            }
            goto label_8003BD18;
    }

label_8003BEB8:
    ctx->pc = 0x8003BEB8u;
    ctx->downcount -= 2;
    // 8003BEB8: cmpwi   r3, 0
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

label_8003BEBC:
    ctx->pc = 0x8003BEBCu;
    // 8003BEBC: bc    4, 2, 0x8003BEC8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003BEC8;
        }
    }

label_8003BEC0:
    ctx->pc = 0x8003BEC0u;
    ctx->downcount -= 2;
    // 8003BEC0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003BEC4:
    ctx->pc = 0x8003BEC4u;
    // 8003BEC4: b       0x8003BFA0
    {
            goto label_8003BFA0;
    }

label_8003BEC8:
    ctx->pc = 0x8003BEC8u;
    ctx->downcount -= 3;
    // 8003BEC8: lfs     f0, 32(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BEC8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003BECC:
    ctx->pc = 0x8003BECCu;
    // 8003BECC: fneg    f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8003BECCu)) return;
    ctx->fpr[1] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[0]) ^ 0x8000000000000000ull);

label_8003BED0:
    ctx->pc = 0x8003BED0u;
    // 8003BED0: bl      0x802928B4
    {
            ctx->lr = 0x8003BED4u;
            ctx->pc = 0x802928B4u;
            return;
    }

label_8003BED4:
    ctx->pc = 0x8003BED4u;
    ctx->downcount -= 4;
    // 8003BED4: fmr    f31, f1
    if (!ppc_fp_available_inline(ctx, 0x8003BED4u)) return;
    ctx->fpr[31] = ctx->fpr[1];

label_8003BED8:
    ctx->pc = 0x8003BED8u;
    // 8003BED8: lfs     f0, -31472(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003BED8u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31472);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003BEDC:
    ctx->pc = 0x8003BEDCu;
    // 8003BEDC: fcmpo   cr0, f31, f0
    if (!ppc_fp_available_inline(ctx, 0x8003BEDCu)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[31], ctx->fpr[0], true);

label_8003BEE0:
    ctx->pc = 0x8003BEE0u;
    // 8003BEE0: bc    4, 0, 0x8003BF2C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003BF2C;
        }
    }

label_8003BEE4:
    ctx->pc = 0x8003BEE4u;
    ctx->downcount -= 3;
    // 8003BEE4: lfs     f0, -31468(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003BEE4u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31468);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003BEE8:
    ctx->pc = 0x8003BEE8u;
    // 8003BEE8: fcmpo   cr0, f31, f0
    if (!ppc_fp_available_inline(ctx, 0x8003BEE8u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[31], ctx->fpr[0], true);

label_8003BEEC:
    ctx->pc = 0x8003BEECu;
    // 8003BEEC: bc    4, 1, 0x8003BF14
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003BF14;
        }
    }

label_8003BEF0:
    ctx->pc = 0x8003BEF0u;
    ctx->downcount -= 3;
    // 8003BEF0: lfs     f1, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BEF0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003BEF4:
    ctx->pc = 0x8003BEF4u;
    // 8003BEF4: lfs     f2, 48(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BEF4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8003BEF8:
    ctx->pc = 0x8003BEF8u;
    // 8003BEF8: bl      0x80292D34
    {
            ctx->lr = 0x8003BEFCu;
            ctx->pc = 0x80292D34u;
            return;
    }

label_8003BEFC:
    ctx->pc = 0x8003BEFCu;
    ctx->downcount -= 4;
    // 8003BEFC: fmr    f30, f1
    if (!ppc_fp_available_inline(ctx, 0x8003BEFCu)) return;
    ctx->fpr[30] = ctx->fpr[1];

label_8003BF00:
    ctx->pc = 0x8003BF00u;
    // 8003BF00: lfs     f1, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BF00u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003BF04:
    ctx->pc = 0x8003BF04u;
    // 8003BF04: lfs     f2, 28(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BF04u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8003BF08:
    ctx->pc = 0x8003BF08u;
    // 8003BF08: bl      0x80292D34
    {
            ctx->lr = 0x8003BF0Cu;
            ctx->pc = 0x80292D34u;
            return;
    }

label_8003BF0C:
    ctx->pc = 0x8003BF0Cu;
    ctx->downcount -= 2;
    // 8003BF0C: fmr    f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8003BF0Cu)) return;
    ctx->fpr[0] = ctx->fpr[1];

label_8003BF10:
    ctx->pc = 0x8003BF10u;
    // 8003BF10: b       0x8003BF40
    {
            goto label_8003BF40;
    }

label_8003BF14:
    ctx->pc = 0x8003BF14u;
    ctx->downcount -= 3;
    // 8003BF14: lfs     f1, 12(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BF14u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003BF18:
    ctx->pc = 0x8003BF18u;
    // 8003BF18: lfs     f2, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BF18u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8003BF1C:
    ctx->pc = 0x8003BF1Cu;
    // 8003BF1C: bl      0x80292D34
    {
            ctx->lr = 0x8003BF20u;
            ctx->pc = 0x80292D34u;
            return;
    }

label_8003BF20:
    ctx->pc = 0x8003BF20u;
    ctx->downcount -= 3;
    // 8003BF20: lfs     f0, -31476(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003BF20u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31476);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003BF24:
    ctx->pc = 0x8003BF24u;
    // 8003BF24: fsubs   f30, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8003BF24u)) return;
    ppc_fsubs(ctx, 30, 0, 1);

label_8003BF28:
    ctx->pc = 0x8003BF28u;
    // 8003BF28: b       0x8003BF40
    {
            goto label_8003BF40;
    }

label_8003BF2C:
    ctx->pc = 0x8003BF2Cu;
    ctx->downcount -= 3;
    // 8003BF2C: lfs     f1, 12(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BF2Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003BF30:
    ctx->pc = 0x8003BF30u;
    // 8003BF30: lfs     f2, 8(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BF30u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8003BF34:
    ctx->pc = 0x8003BF34u;
    // 8003BF34: bl      0x80292D34
    {
            ctx->lr = 0x8003BF38u;
            ctx->pc = 0x80292D34u;
            return;
    }

label_8003BF38:
    ctx->pc = 0x8003BF38u;
    ctx->downcount -= 2;
    // 8003BF38: lfs     f0, -31476(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003BF38u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31476);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003BF3C:
    ctx->pc = 0x8003BF3Cu;
    // 8003BF3C: fsubs   f30, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8003BF3Cu)) return;
    ppc_fsubs(ctx, 30, 1, 0);

label_8003BF40:
    ctx->pc = 0x8003BF40u;
    ctx->downcount -= 72;
    // 8003BF40: lfs     f2, -31464(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003BF40u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31464);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8003BF44:
    ctx->pc = 0x8003BF44u;
    // 8003BF44: fmuls   f0, f2, f0
    if (!ppc_fp_available_inline(ctx, 0x8003BF44u)) return;
    ppc_fmuls(ctx, 0, 2, 0);

label_8003BF48:
    ctx->pc = 0x8003BF48u;
    // 8003BF48: lfs     f1, -31460(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003BF48u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31460);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003BF4C:
    ctx->pc = 0x8003BF4Cu;
    // 8003BF4C: fdivs   f0, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8003BF4Cu)) return;
    ppc_fdivs(ctx, 0, 0, 1);

label_8003BF50:
    ctx->pc = 0x8003BF50u;
    // 8003BF50: fctiwz    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x8003BF50u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_8003BF54:
    ctx->pc = 0x8003BF54u;
    // 8003BF54: stfd     f0, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BF54u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_8003BF58:
    ctx->pc = 0x8003BF58u;
    // 8003BF58: lwz     r0, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003BF5C:
    ctx->pc = 0x8003BF5Cu;
    // 8003BF5C: extsh r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_8003BF60:
    ctx->pc = 0x8003BF60u;
    // 8003BF60: sth     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003BF64:
    ctx->pc = 0x8003BF64u;
    // 8003BF64: fmuls   f0, f2, f31
    if (!ppc_fp_available_inline(ctx, 0x8003BF64u)) return;
    ppc_fmuls(ctx, 0, 2, 31);

label_8003BF68:
    ctx->pc = 0x8003BF68u;
    // 8003BF68: fdivs   f0, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8003BF68u)) return;
    ppc_fdivs(ctx, 0, 0, 1);

label_8003BF6C:
    ctx->pc = 0x8003BF6Cu;
    // 8003BF6C: fctiwz    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x8003BF6Cu)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_8003BF70:
    ctx->pc = 0x8003BF70u;
    // 8003BF70: stfd     f0, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BF70u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_8003BF74:
    ctx->pc = 0x8003BF74u;
    // 8003BF74: lwz     r0, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003BF78:
    ctx->pc = 0x8003BF78u;
    // 8003BF78: extsh r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_8003BF7C:
    ctx->pc = 0x8003BF7Cu;
    // 8003BF7C: sth     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003BF80:
    ctx->pc = 0x8003BF80u;
    // 8003BF80: fmuls   f0, f2, f30
    if (!ppc_fp_available_inline(ctx, 0x8003BF80u)) return;
    ppc_fmuls(ctx, 0, 2, 30);

label_8003BF84:
    ctx->pc = 0x8003BF84u;
    // 8003BF84: fdivs   f0, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8003BF84u)) return;
    ppc_fdivs(ctx, 0, 0, 1);

label_8003BF88:
    ctx->pc = 0x8003BF88u;
    // 8003BF88: fctiwz    f0, f0
    if (!ppc_fp_available_inline(ctx, 0x8003BF88u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_8003BF8C:
    ctx->pc = 0x8003BF8Cu;
    // 8003BF8C: stfd     f0, 72(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BF8Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_8003BF90:
    ctx->pc = 0x8003BF90u;
    // 8003BF90: lwz     r0, 76(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(76);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003BF94:
    ctx->pc = 0x8003BF94u;
    // 8003BF94: extsh r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_8003BF98:
    ctx->pc = 0x8003BF98u;
    // 8003BF98: sth     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003BF9C:
    ctx->pc = 0x8003BF9Cu;
    // 8003BF9C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003BFA0:
    ctx->pc = 0x8003BFA0u;
    ctx->downcount -= 12;
    // 8003BFA0: psq_l   f31, 120(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8003BFA0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(120);
        ppc_psq_load_inline(ctx, 31u, ea, false, 0u, false, 0x8003BFA0u);
        if (ctx->exception) return;
    }

label_8003BFA4:
    ctx->pc = 0x8003BFA4u;
    // 8003BFA4: lfd     f31, 112(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BFA4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(112);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003BFA8:
    ctx->pc = 0x8003BFA8u;
    // 8003BFA8: psq_l   f30, 104(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8003BFA8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        ppc_psq_load_inline(ctx, 30u, ea, false, 0u, false, 0x8003BFA8u);
        if (ctx->exception) return;
    }

label_8003BFAC:
    ctx->pc = 0x8003BFACu;
    // 8003BFAC: lfd     f30, 96(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BFACu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        ctx->fpr[30] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003BFB0:
    ctx->pc = 0x8003BFB0u;
    // 8003BFB0: lwz     r31, 92(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8003BFB4:
    ctx->pc = 0x8003BFB4u;
    // 8003BFB4: lwz     r30, 88(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8003BFB8:
    ctx->pc = 0x8003BFB8u;
    // 8003BFB8: lwz     r29, 84(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_8003BFBC:
    ctx->pc = 0x8003BFBCu;
    // 8003BFBC: lwz     r0, 132(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(132);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003BFC0:
    ctx->pc = 0x8003BFC0u;
    // 8003BFC0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8003BFC4:
    ctx->pc = 0x8003BFC4u;
    // 8003BFC4: addi    r1, r1, 128
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(128);

label_8003BFC8:
    ctx->pc = 0x8003BFC8u;
    // 8003BFC8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8003A6E0;
        }
    }

label_8003BFCC:
    ctx->pc = 0x8003BFCCu;
    ctx->downcount -= 7;
    // 8003BFCC: stwu     r1, -64(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-64);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8003BFD0:
    ctx->pc = 0x8003BFD0u;
    // 8003BFD0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8003BFD4:
    ctx->pc = 0x8003BFD4u;
    // 8003BFD4: stw     r0, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003BFD8:
    ctx->pc = 0x8003BFD8u;
    // 8003BFD8: stfd     f31, 48(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003BFD8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_8003BFDC:
    ctx->pc = 0x8003BFDCu;
    // 8003BFDC: psq_st   f31, 56(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8003BFDCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        ppc_psq_store_inline(ctx, 31u, ea, false, 0u, false, 0x8003BFDCu);
        if (ctx->exception) return;
    }

label_8003BFE0:
    ctx->pc = 0x8003BFE0u;
    // 8003BFE0: addi    r11, r1, 48
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(48);

label_8003BFE4:
    ctx->pc = 0x8003BFE4u;
    // 8003BFE4: bl      0x80286A44
    {
            ctx->lr = 0x8003BFE8u;
            ctx->pc = 0x80286A44u;
            return;
    }

label_8003BFE8:
    ctx->pc = 0x8003BFE8u;
    ctx->downcount -= 4;
    // 8003BFE8: or   r27, r3, r3
    {
        ctx->gpr[27] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003BFEC:
    ctx->pc = 0x8003BFECu;
    // 8003BFEC: or   r25, r5, r5
    {
        ctx->gpr[25] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8003BFF0:
    ctx->pc = 0x8003BFF0u;
    // 8003BFF0: or   r26, r6, r6
    {
        ctx->gpr[26] = ctx->gpr[6] | ctx->gpr[6];
    }

label_8003BFF4:
    ctx->pc = 0x8003BFF4u;
    // 8003BFF4: bl      0x80022BB0
    {
            ctx->lr = 0x8003BFF8u;
            ctx->pc = 0x80022BB0u;
            return;
    }

label_8003BFF8:
    ctx->pc = 0x8003BFF8u;
    ctx->downcount -= 8;
    // 8003BFF8: lbz     r4, 243(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(243);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_8003BFFC:
    ctx->pc = 0x8003BFFCu;
    // 8003BFFC: lbz     r0, 244(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(244);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003C000:
    ctx->pc = 0x8003C000u;
    // 8003C000: add   r31, r4, r0
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[31] = res;
    }

label_8003C004:
    ctx->pc = 0x8003C004u;
    // 8003C004: addi    r27, r3, 9984
    ctx->gpr[27] = ctx->gpr[3] + (u32)(s32)(9984);

label_8003C008:
    ctx->pc = 0x8003C008u;
    // 8003C008: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003C00C:
    ctx->pc = 0x8003C00Cu;
    // 8003C00C: addi    r28, r3, 4800
    ctx->gpr[28] = ctx->gpr[3] + (u32)(s32)(4800);

label_8003C010:
    ctx->pc = 0x8003C010u;
    // 8003C010: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003C014:
    ctx->pc = 0x8003C014u;
    // 8003C014: bl      0x80022B2C
    {
            ctx->lr = 0x8003C018u;
            ctx->pc = 0x80022B2Cu;
            return;
    }

label_8003C018:
    ctx->pc = 0x8003C018u;
    ctx->downcount -= 3;
    // 8003C018: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_8003C01C:
    ctx->pc = 0x8003C01Cu;
    // 8003C01C: lfs     f31, -31476(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003C01Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31476);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_8003C020:
    ctx->pc = 0x8003C020u;
    // 8003C020: b       0x8003C060
    {
            goto label_8003C060;
    }

label_8003C024:
    ctx->downcount -= 4;
    // 8003C024: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_8003C028:
    // 8003C028: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8003C02C:
    // 8003C02C: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8003C030:
    // 8003C030: bl      0x80247860
    {
            ctx->lr = 0x8003C034u;
            ctx->pc = 0x80247860u;
            return;
    }

label_8003C034:
    ctx->downcount -= 4;
    // 8003C034: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8003C038:
    // 8003C038: or   r4, r26, r26
    {
        ctx->gpr[4] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8003C03C:
    // 8003C03C: or   r5, r28, r28
    {
        ctx->gpr[5] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8003C040:
    // 8003C040: bl      0x80247860
    {
            ctx->lr = 0x8003C044u;
            ctx->pc = 0x80247860u;
            return;
    }

label_8003C044:
    ctx->pc = 0x8003C044u;
    ctx->downcount -= 7;
    // 8003C044: stfs     f31, 12(r28)
    if (!ppc_fp_available_inline(ctx, 0x8003C044u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8003C048:
    ctx->pc = 0x8003C048u;
    // 8003C048: stfs     f31, 28(r28)
    if (!ppc_fp_available_inline(ctx, 0x8003C048u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(28);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8003C04C:
    ctx->pc = 0x8003C04Cu;
    // 8003C04C: stfs     f31, 44(r28)
    if (!ppc_fp_available_inline(ctx, 0x8003C04Cu)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8003C050:
    // 8003C050: addi    r27, r27, 64
    ctx->gpr[27] = ctx->gpr[27] + (u32)(s32)(64);

label_8003C054:
    // 8003C054: addi    r29, r29, 48
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(48);

label_8003C058:
    // 8003C058: addi    r28, r28, 48
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(48);

label_8003C05C:
    // 8003C05C: addi    r30, r30, 1
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(1);

label_8003C060:
    ctx->downcount -= 2;
    // 8003C060: cmpw    r30, r31
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(ctx->gpr[31]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003C064:
    // 8003C064: bc    12, 0, 0x8003C024
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003C024u;
                return;
            }
            goto label_8003C024;
        }
    }

label_8003C068:
    ctx->pc = 0x8003C068u;
    ctx->downcount -= 6;
    // 8003C068: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_8003C06C:
    ctx->pc = 0x8003C06Cu;
    // 8003C06C: stw     r0, -25920(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25920);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003C070:
    ctx->pc = 0x8003C070u;
    // 8003C070: psq_l   f31, 56(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8003C070u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        ppc_psq_load_inline(ctx, 31u, ea, false, 0u, false, 0x8003C070u);
        if (ctx->exception) return;
    }

label_8003C074:
    ctx->pc = 0x8003C074u;
    // 8003C074: lfd     f31, 48(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C074u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003C078:
    ctx->pc = 0x8003C078u;
    // 8003C078: addi    r11, r1, 48
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(48);

label_8003C07C:
    ctx->pc = 0x8003C07Cu;
    // 8003C07C: bl      0x80286A90
    {
            ctx->lr = 0x8003C080u;
            ctx->pc = 0x80286A90u;
            return;
    }

label_8003C080:
    ctx->pc = 0x8003C080u;
    ctx->downcount -= 5;
    // 8003C080: lwz     r0, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003C084:
    ctx->pc = 0x8003C084u;
    // 8003C084: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8003C088:
    ctx->pc = 0x8003C088u;
    // 8003C088: addi    r1, r1, 64
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(64);

label_8003C08C:
    ctx->pc = 0x8003C08Cu;
    // 8003C08C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8003A6E0;
        }
    }

label_8003C090:
    ctx->pc = 0x8003C090u;
    ctx->downcount -= 15;
    // 8003C090: stwu     r1, -288(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-288);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8003C094:
    ctx->pc = 0x8003C094u;
    // 8003C094: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8003C098:
    ctx->pc = 0x8003C098u;
    // 8003C098: stw     r0, 292(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(292);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003C09C:
    ctx->pc = 0x8003C09Cu;
    // 8003C09C: stfd     f31, 272(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C09Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(272);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_8003C0A0:
    ctx->pc = 0x8003C0A0u;
    // 8003C0A0: psq_st   f31, 280(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8003C0A0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(280);
        ppc_psq_store_inline(ctx, 31u, ea, false, 0u, false, 0x8003C0A0u);
        if (ctx->exception) return;
    }

label_8003C0A4:
    ctx->pc = 0x8003C0A4u;
    // 8003C0A4: stfd     f30, 256(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C0A4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(256);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[30]));
    }

label_8003C0A8:
    ctx->pc = 0x8003C0A8u;
    // 8003C0A8: psq_st   f30, 264(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8003C0A8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(264);
        ppc_psq_store_inline(ctx, 30u, ea, false, 0u, false, 0x8003C0A8u);
        if (ctx->exception) return;
    }

label_8003C0AC:
    ctx->pc = 0x8003C0ACu;
    // 8003C0AC: stfd     f29, 240(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C0ACu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(240);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[29]));
    }

label_8003C0B0:
    ctx->pc = 0x8003C0B0u;
    // 8003C0B0: psq_st   f29, 248(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8003C0B0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(248);
        ppc_psq_store_inline(ctx, 29u, ea, false, 0u, false, 0x8003C0B0u);
        if (ctx->exception) return;
    }

label_8003C0B4:
    ctx->pc = 0x8003C0B4u;
    // 8003C0B4: stfd     f28, 224(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C0B4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(224);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[28]));
    }

label_8003C0B8:
    ctx->pc = 0x8003C0B8u;
    // 8003C0B8: psq_st   f28, 232(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8003C0B8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(232);
        ppc_psq_store_inline(ctx, 28u, ea, false, 0u, false, 0x8003C0B8u);
        if (ctx->exception) return;
    }

label_8003C0BC:
    ctx->pc = 0x8003C0BCu;
    // 8003C0BC: stfd     f27, 208(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C0BCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(208);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[27]));
    }

label_8003C0C0:
    ctx->pc = 0x8003C0C0u;
    // 8003C0C0: psq_st   f27, 216(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8003C0C0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(216);
        ppc_psq_store_inline(ctx, 27u, ea, false, 0u, false, 0x8003C0C0u);
        if (ctx->exception) return;
    }

label_8003C0C4:
    ctx->pc = 0x8003C0C4u;
    // 8003C0C4: addi    r11, r1, 208
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(208);

label_8003C0C8:
    ctx->pc = 0x8003C0C8u;
    // 8003C0C8: bl      0x80286A3C
    {
            ctx->lr = 0x8003C0CCu;
            ctx->pc = 0x80286A3Cu;
            return;
    }

label_8003C0CC:
    ctx->pc = 0x8003C0CCu;
    ctx->downcount -= 9;
    // 8003C0CC: or   r26, r3, r3
    {
        ctx->gpr[26] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003C0D0:
    ctx->pc = 0x8003C0D0u;
    // 8003C0D0: or   r27, r4, r4
    {
        ctx->gpr[27] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8003C0D4:
    ctx->pc = 0x8003C0D4u;
    // 8003C0D4: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_8003C0D8:
    ctx->pc = 0x8003C0D8u;
    // 8003C0D8: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_8003C0DC:
    ctx->pc = 0x8003C0DCu;
    // 8003C0DC: lfd     f29, -31448(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003C0DCu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31448);
        ctx->fpr[29] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003C0E0:
    ctx->pc = 0x8003C0E0u;
    // 8003C0E0: lis     r25, 17200
    ctx->gpr[25] = ((u32)(s32)(17200) << 16);

label_8003C0E4:
    ctx->pc = 0x8003C0E4u;
    // 8003C0E4: lfs     f30, -31456(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003C0E4u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31456);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[30] = value;
        ctx->ps1[30] = value;
    }

label_8003C0E8:
    ctx->pc = 0x8003C0E8u;
    // 8003C0E8: lfs     f31, -31452(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003C0E8u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31452);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_8003C0EC:
    ctx->pc = 0x8003C0ECu;
    // 8003C0EC: b       0x8003C2C0
    {
            goto label_8003C2C0;
    }

label_8003C0F0:
    ctx->pc = 0x8003C0F0u;
    ctx->downcount -= 6;
    // 8003C0F0: lwz     r0, 84(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(84);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003C0F4:
    // 8003C0F4: add   r28, r0, r31
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[28] = res;
    }

label_8003C0F8:
    // 8003C0F8: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8003C0FC:
    ctx->pc = 0x8003C0FCu;
    // 8003C0FC: lbz     r0, 243(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(243);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003C100:
    // 8003C100: add   r4, r30, r0
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_8003C104:
    // 8003C104: bl      0x800286CC
    {
            ctx->lr = 0x8003C108u;
            ctx->pc = 0x800286CCu;
            return;
    }

label_8003C108:
    ctx->downcount -= 4;
    // 8003C108: or   r24, r3, r3
    {
        ctx->gpr[24] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003C10C:
    // 8003C10C: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8003C110:
    ctx->pc = 0x8003C110u;
    // 8003C110: lbz     r4, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_8003C114:
    // 8003C114: bl      0x800286CC
    {
            ctx->lr = 0x8003C118u;
            ctx->pc = 0x800286CCu;
            return;
    }

label_8003C118:
    ctx->downcount -= 4;
    // 8003C118: or   r23, r3, r3
    {
        ctx->gpr[23] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003C11C:
    // 8003C11C: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8003C120:
    ctx->pc = 0x8003C120u;
    // 8003C120: lbz     r4, 1(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(1);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_8003C124:
    // 8003C124: bl      0x800286CC
    {
            ctx->lr = 0x8003C128u;
            ctx->pc = 0x800286CCu;
            return;
    }

label_8003C128:
    ctx->downcount -= 22;
    // 8003C128: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003C12C:
    ctx->pc = 0x8003C12Cu;
    // 8003C12C: lbz     r0, 2(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(2);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003C130:
    ctx->pc = 0x8003C130u;
    // 8003C130: stw     r0, 156(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(156);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003C134:
    ctx->pc = 0x8003C134u;
    // 8003C134: stw     r25, 152(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(152);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_8003C138:
    ctx->pc = 0x8003C138u;
    // 8003C138: lfd     f0, 152(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C138u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(152);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003C13C:
    ctx->pc = 0x8003C13Cu;
    // 8003C13C: fsubs   f0, f0, f29
    if (!ppc_fp_available_inline(ctx, 0x8003C13Cu)) return;
    ppc_fsubs(ctx, 0, 0, 29);

label_8003C140:
    ctx->pc = 0x8003C140u;
    // 8003C140: fmuls   f28, f0, f30
    if (!ppc_fp_available_inline(ctx, 0x8003C140u)) return;
    ppc_fmuls(ctx, 28, 0, 30);

label_8003C144:
    ctx->pc = 0x8003C144u;
    // 8003C144: fsubs   f27, f31, f28
    if (!ppc_fp_available_inline(ctx, 0x8003C144u)) return;
    ppc_fsubs(ctx, 27, 31, 28);

label_8003C148:
    ctx->pc = 0x8003C148u;
    // 8003C148: lwz     r3, 60(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(60);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003C14C:
    ctx->pc = 0x8003C14Cu;
    // 8003C14C: lbz     r0, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003C150:
    // 8003C150: mulli   r0, r0, 28
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)28);

label_8003C154:
    // 8003C154: add   r4, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_8003C158:
    // 8003C158: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_8003C15C:
    ctx->pc = 0x8003C15Cu;
    // 8003C15C: lfs     f0, 16(r4)
    if (!ppc_fp_available_inline(ctx, 0x8003C15Cu)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003C160:
    ctx->pc = 0x8003C160u;
    // 8003C160: fneg    f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8003C160u)) return;
    ctx->fpr[1] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[0]) ^ 0x8000000000000000ull);

label_8003C164:
    ctx->pc = 0x8003C164u;
    // 8003C164: lfs     f0, 20(r4)
    if (!ppc_fp_available_inline(ctx, 0x8003C164u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003C168:
    ctx->pc = 0x8003C168u;
    // 8003C168: fneg    f2, f0
    if (!ppc_fp_available_inline(ctx, 0x8003C168u)) return;
    ctx->fpr[2] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[0]) ^ 0x8000000000000000ull);

label_8003C16C:
    ctx->pc = 0x8003C16Cu;
    // 8003C16C: lfs     f0, 24(r4)
    if (!ppc_fp_available_inline(ctx, 0x8003C16Cu)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(24);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003C170:
    ctx->pc = 0x8003C170u;
    // 8003C170: fneg    f3, f0
    if (!ppc_fp_available_inline(ctx, 0x8003C170u)) return;
    ctx->fpr[3] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[0]) ^ 0x8000000000000000ull);

label_8003C174:
    // 8003C174: bl      0x80247C90
    {
            ctx->lr = 0x8003C178u;
            ctx->pc = 0x80247C90u;
            return;
    }

label_8003C178:
    ctx->downcount -= 4;
    // 8003C178: or   r3, r23, r23
    {
        ctx->gpr[3] = ctx->gpr[23] | ctx->gpr[23];
    }

label_8003C17C:
    // 8003C17C: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_8003C180:
    // 8003C180: addi    r5, r1, 104
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(104);

label_8003C184:
    // 8003C184: bl      0x80247860
    {
            ctx->lr = 0x8003C188u;
            ctx->pc = 0x80247860u;
            return;
    }

label_8003C188:
    ctx->pc = 0x8003C188u;
    ctx->downcount -= 14;
    // 8003C188: lwz     r3, 60(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(60);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003C18C:
    ctx->pc = 0x8003C18Cu;
    // 8003C18C: lbz     r0, 1(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(1);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003C190:
    // 8003C190: mulli   r0, r0, 28
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)28);

label_8003C194:
    // 8003C194: add   r4, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_8003C198:
    // 8003C198: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_8003C19C:
    ctx->pc = 0x8003C19Cu;
    // 8003C19C: lfs     f0, 16(r4)
    if (!ppc_fp_available_inline(ctx, 0x8003C19Cu)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003C1A0:
    ctx->pc = 0x8003C1A0u;
    // 8003C1A0: fneg    f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8003C1A0u)) return;
    ctx->fpr[1] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[0]) ^ 0x8000000000000000ull);

label_8003C1A4:
    ctx->pc = 0x8003C1A4u;
    // 8003C1A4: lfs     f0, 20(r4)
    if (!ppc_fp_available_inline(ctx, 0x8003C1A4u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003C1A8:
    ctx->pc = 0x8003C1A8u;
    // 8003C1A8: fneg    f2, f0
    if (!ppc_fp_available_inline(ctx, 0x8003C1A8u)) return;
    ctx->fpr[2] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[0]) ^ 0x8000000000000000ull);

label_8003C1AC:
    ctx->pc = 0x8003C1ACu;
    // 8003C1AC: lfs     f0, 24(r4)
    if (!ppc_fp_available_inline(ctx, 0x8003C1ACu)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(24);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003C1B0:
    ctx->pc = 0x8003C1B0u;
    // 8003C1B0: fneg    f3, f0
    if (!ppc_fp_available_inline(ctx, 0x8003C1B0u)) return;
    ctx->fpr[3] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[0]) ^ 0x8000000000000000ull);

label_8003C1B4:
    // 8003C1B4: bl      0x80247C90
    {
            ctx->lr = 0x8003C1B8u;
            ctx->pc = 0x80247C90u;
            return;
    }

label_8003C1B8:
    ctx->downcount -= 4;
    // 8003C1B8: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8003C1BC:
    // 8003C1BC: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_8003C1C0:
    // 8003C1C0: addi    r5, r1, 56
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(56);

label_8003C1C4:
    // 8003C1C4: bl      0x80247860
    {
            ctx->lr = 0x8003C1C8u;
            ctx->pc = 0x80247860u;
            return;
    }

label_8003C1C8:
    ctx->pc = 0x8003C1C8u;
    ctx->downcount -= 62;
    // 8003C1C8: lfs     f1, 104(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C1C8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003C1CC:
    ctx->pc = 0x8003C1CCu;
    // 8003C1CC: lfs     f0, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C1CCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003C1D0:
    ctx->pc = 0x8003C1D0u;
    // 8003C1D0: fmuls   f0, f0, f27
    if (!ppc_fp_available_inline(ctx, 0x8003C1D0u)) return;
    ppc_fmuls(ctx, 0, 0, 27);

label_8003C1D4:
    ctx->pc = 0x8003C1D4u;
    // 8003C1D4: fmadds f0, f1, f28, f0
    if (!ppc_fp_available_inline(ctx, 0x8003C1D4u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[1], ctx->fpr[28], ctx->fpr[0], true, false, false, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_8003C1D8:
    ctx->pc = 0x8003C1D8u;
    // 8003C1D8: stfs     f0, 0(r24)
    if (!ppc_fp_available_inline(ctx, 0x8003C1D8u)) return;
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003C1DC:
    ctx->pc = 0x8003C1DCu;
    // 8003C1DC: lfs     f1, 108(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C1DCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(108);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003C1E0:
    ctx->pc = 0x8003C1E0u;
    // 8003C1E0: lfs     f0, 60(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C1E0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003C1E4:
    ctx->pc = 0x8003C1E4u;
    // 8003C1E4: fmuls   f0, f0, f27
    if (!ppc_fp_available_inline(ctx, 0x8003C1E4u)) return;
    ppc_fmuls(ctx, 0, 0, 27);

label_8003C1E8:
    ctx->pc = 0x8003C1E8u;
    // 8003C1E8: fmadds f0, f1, f28, f0
    if (!ppc_fp_available_inline(ctx, 0x8003C1E8u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[1], ctx->fpr[28], ctx->fpr[0], true, false, false, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_8003C1EC:
    ctx->pc = 0x8003C1ECu;
    // 8003C1EC: stfs     f0, 4(r24)
    if (!ppc_fp_available_inline(ctx, 0x8003C1ECu)) return;
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003C1F0:
    ctx->pc = 0x8003C1F0u;
    // 8003C1F0: lfs     f1, 112(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C1F0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(112);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003C1F4:
    ctx->pc = 0x8003C1F4u;
    // 8003C1F4: lfs     f0, 64(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C1F4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003C1F8:
    ctx->pc = 0x8003C1F8u;
    // 8003C1F8: fmuls   f0, f0, f27
    if (!ppc_fp_available_inline(ctx, 0x8003C1F8u)) return;
    ppc_fmuls(ctx, 0, 0, 27);

label_8003C1FC:
    ctx->pc = 0x8003C1FCu;
    // 8003C1FC: fmadds f0, f1, f28, f0
    if (!ppc_fp_available_inline(ctx, 0x8003C1FCu)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[1], ctx->fpr[28], ctx->fpr[0], true, false, false, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_8003C200:
    ctx->pc = 0x8003C200u;
    // 8003C200: stfs     f0, 8(r24)
    if (!ppc_fp_available_inline(ctx, 0x8003C200u)) return;
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003C204:
    ctx->pc = 0x8003C204u;
    // 8003C204: lfs     f1, 116(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C204u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(116);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003C208:
    ctx->pc = 0x8003C208u;
    // 8003C208: lfs     f0, 68(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C208u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003C20C:
    ctx->pc = 0x8003C20Cu;
    // 8003C20C: fmuls   f0, f0, f27
    if (!ppc_fp_available_inline(ctx, 0x8003C20Cu)) return;
    ppc_fmuls(ctx, 0, 0, 27);

label_8003C210:
    ctx->pc = 0x8003C210u;
    // 8003C210: fmadds f0, f1, f28, f0
    if (!ppc_fp_available_inline(ctx, 0x8003C210u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[1], ctx->fpr[28], ctx->fpr[0], true, false, false, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_8003C214:
    ctx->pc = 0x8003C214u;
    // 8003C214: stfs     f0, 12(r24)
    if (!ppc_fp_available_inline(ctx, 0x8003C214u)) return;
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003C218:
    ctx->pc = 0x8003C218u;
    // 8003C218: lfs     f1, 120(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C218u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(120);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003C21C:
    ctx->pc = 0x8003C21Cu;
    // 8003C21C: lfs     f0, 72(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C21Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003C220:
    ctx->pc = 0x8003C220u;
    // 8003C220: fmuls   f0, f0, f27
    if (!ppc_fp_available_inline(ctx, 0x8003C220u)) return;
    ppc_fmuls(ctx, 0, 0, 27);

label_8003C224:
    ctx->pc = 0x8003C224u;
    // 8003C224: fmadds f0, f1, f28, f0
    if (!ppc_fp_available_inline(ctx, 0x8003C224u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[1], ctx->fpr[28], ctx->fpr[0], true, false, false, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_8003C228:
    ctx->pc = 0x8003C228u;
    // 8003C228: stfs     f0, 16(r24)
    if (!ppc_fp_available_inline(ctx, 0x8003C228u)) return;
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003C22C:
    ctx->pc = 0x8003C22Cu;
    // 8003C22C: lfs     f1, 124(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C22Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(124);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003C230:
    ctx->pc = 0x8003C230u;
    // 8003C230: lfs     f0, 76(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C230u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(76);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003C234:
    ctx->pc = 0x8003C234u;
    // 8003C234: fmuls   f0, f0, f27
    if (!ppc_fp_available_inline(ctx, 0x8003C234u)) return;
    ppc_fmuls(ctx, 0, 0, 27);

label_8003C238:
    ctx->pc = 0x8003C238u;
    // 8003C238: fmadds f0, f1, f28, f0
    if (!ppc_fp_available_inline(ctx, 0x8003C238u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[1], ctx->fpr[28], ctx->fpr[0], true, false, false, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_8003C23C:
    ctx->pc = 0x8003C23Cu;
    // 8003C23C: stfs     f0, 20(r24)
    if (!ppc_fp_available_inline(ctx, 0x8003C23Cu)) return;
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(20);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003C240:
    ctx->pc = 0x8003C240u;
    // 8003C240: lfs     f1, 128(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C240u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(128);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003C244:
    ctx->pc = 0x8003C244u;
    // 8003C244: lfs     f0, 80(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C244u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003C248:
    ctx->pc = 0x8003C248u;
    // 8003C248: fmuls   f0, f0, f27
    if (!ppc_fp_available_inline(ctx, 0x8003C248u)) return;
    ppc_fmuls(ctx, 0, 0, 27);

label_8003C24C:
    ctx->pc = 0x8003C24Cu;
    // 8003C24C: fmadds f0, f1, f28, f0
    if (!ppc_fp_available_inline(ctx, 0x8003C24Cu)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[1], ctx->fpr[28], ctx->fpr[0], true, false, false, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_8003C250:
    ctx->pc = 0x8003C250u;
    // 8003C250: stfs     f0, 24(r24)
    if (!ppc_fp_available_inline(ctx, 0x8003C250u)) return;
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(24);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003C254:
    ctx->pc = 0x8003C254u;
    // 8003C254: lfs     f1, 132(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C254u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(132);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003C258:
    ctx->pc = 0x8003C258u;
    // 8003C258: lfs     f0, 84(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C258u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003C25C:
    ctx->pc = 0x8003C25Cu;
    // 8003C25C: fmuls   f0, f0, f27
    if (!ppc_fp_available_inline(ctx, 0x8003C25Cu)) return;
    ppc_fmuls(ctx, 0, 0, 27);

label_8003C260:
    ctx->pc = 0x8003C260u;
    // 8003C260: fmadds f0, f1, f28, f0
    if (!ppc_fp_available_inline(ctx, 0x8003C260u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[1], ctx->fpr[28], ctx->fpr[0], true, false, false, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_8003C264:
    ctx->pc = 0x8003C264u;
    // 8003C264: stfs     f0, 28(r24)
    if (!ppc_fp_available_inline(ctx, 0x8003C264u)) return;
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(28);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003C268:
    ctx->pc = 0x8003C268u;
    // 8003C268: lfs     f1, 136(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C268u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003C26C:
    ctx->pc = 0x8003C26Cu;
    // 8003C26C: lfs     f0, 88(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C26Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003C270:
    ctx->pc = 0x8003C270u;
    // 8003C270: fmuls   f0, f0, f27
    if (!ppc_fp_available_inline(ctx, 0x8003C270u)) return;
    ppc_fmuls(ctx, 0, 0, 27);

label_8003C274:
    ctx->pc = 0x8003C274u;
    // 8003C274: fmadds f0, f1, f28, f0
    if (!ppc_fp_available_inline(ctx, 0x8003C274u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[1], ctx->fpr[28], ctx->fpr[0], true, false, false, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_8003C278:
    ctx->pc = 0x8003C278u;
    // 8003C278: stfs     f0, 32(r24)
    if (!ppc_fp_available_inline(ctx, 0x8003C278u)) return;
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(32);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003C27C:
    ctx->pc = 0x8003C27Cu;
    // 8003C27C: lfs     f1, 140(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C27Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(140);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003C280:
    ctx->pc = 0x8003C280u;
    // 8003C280: lfs     f0, 92(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C280u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003C284:
    ctx->pc = 0x8003C284u;
    // 8003C284: fmuls   f0, f0, f27
    if (!ppc_fp_available_inline(ctx, 0x8003C284u)) return;
    ppc_fmuls(ctx, 0, 0, 27);

label_8003C288:
    ctx->pc = 0x8003C288u;
    // 8003C288: fmadds f0, f1, f28, f0
    if (!ppc_fp_available_inline(ctx, 0x8003C288u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[1], ctx->fpr[28], ctx->fpr[0], true, false, false, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_8003C28C:
    ctx->pc = 0x8003C28Cu;
    // 8003C28C: stfs     f0, 36(r24)
    if (!ppc_fp_available_inline(ctx, 0x8003C28Cu)) return;
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(36);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003C290:
    ctx->pc = 0x8003C290u;
    // 8003C290: lfs     f1, 144(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C290u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003C294:
    ctx->pc = 0x8003C294u;
    // 8003C294: lfs     f0, 96(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C294u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003C298:
    ctx->pc = 0x8003C298u;
    // 8003C298: fmuls   f0, f0, f27
    if (!ppc_fp_available_inline(ctx, 0x8003C298u)) return;
    ppc_fmuls(ctx, 0, 0, 27);

label_8003C29C:
    ctx->pc = 0x8003C29Cu;
    // 8003C29C: fmadds f0, f1, f28, f0
    if (!ppc_fp_available_inline(ctx, 0x8003C29Cu)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[1], ctx->fpr[28], ctx->fpr[0], true, false, false, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_8003C2A0:
    ctx->pc = 0x8003C2A0u;
    // 8003C2A0: stfs     f0, 40(r24)
    if (!ppc_fp_available_inline(ctx, 0x8003C2A0u)) return;
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003C2A4:
    ctx->pc = 0x8003C2A4u;
    // 8003C2A4: lfs     f1, 148(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C2A4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003C2A8:
    ctx->pc = 0x8003C2A8u;
    // 8003C2A8: lfs     f0, 100(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C2A8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(100);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003C2AC:
    ctx->pc = 0x8003C2ACu;
    // 8003C2AC: fmuls   f0, f0, f27
    if (!ppc_fp_available_inline(ctx, 0x8003C2ACu)) return;
    ppc_fmuls(ctx, 0, 0, 27);

label_8003C2B0:
    ctx->pc = 0x8003C2B0u;
    // 8003C2B0: fmadds f0, f1, f28, f0
    if (!ppc_fp_available_inline(ctx, 0x8003C2B0u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[1], ctx->fpr[28], ctx->fpr[0], true, false, false, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_8003C2B4:
    ctx->pc = 0x8003C2B4u;
    // 8003C2B4: stfs     f0, 44(r24)
    if (!ppc_fp_available_inline(ctx, 0x8003C2B4u)) return;
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003C2B8:
    // 8003C2B8: addi    r31, r31, 4
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(4);

label_8003C2BC:
    // 8003C2BC: addi    r30, r30, 1
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(1);

label_8003C2C0:
    ctx->pc = 0x8003C2C0u;
    ctx->downcount -= 3;
    // 8003C2C0: lbz     r0, 244(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(244);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003C2C4:
    // 8003C2C4: cmpw    r30, r0
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003C2C8:
    // 8003C2C8: bc    12, 0, 0x8003C0F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003C0F0u;
                return;
            }
            goto label_8003C0F0;
        }
    }

label_8003C2CC:
    ctx->pc = 0x8003C2CCu;
    ctx->downcount -= 12;
    // 8003C2CC: psq_l   f31, 280(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8003C2CCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(280);
        ppc_psq_load_inline(ctx, 31u, ea, false, 0u, false, 0x8003C2CCu);
        if (ctx->exception) return;
    }

label_8003C2D0:
    ctx->pc = 0x8003C2D0u;
    // 8003C2D0: lfd     f31, 272(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C2D0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(272);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003C2D4:
    ctx->pc = 0x8003C2D4u;
    // 8003C2D4: psq_l   f30, 264(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8003C2D4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(264);
        ppc_psq_load_inline(ctx, 30u, ea, false, 0u, false, 0x8003C2D4u);
        if (ctx->exception) return;
    }

label_8003C2D8:
    ctx->pc = 0x8003C2D8u;
    // 8003C2D8: lfd     f30, 256(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C2D8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(256);
        ctx->fpr[30] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003C2DC:
    ctx->pc = 0x8003C2DCu;
    // 8003C2DC: psq_l   f29, 248(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8003C2DCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(248);
        ppc_psq_load_inline(ctx, 29u, ea, false, 0u, false, 0x8003C2DCu);
        if (ctx->exception) return;
    }

label_8003C2E0:
    ctx->pc = 0x8003C2E0u;
    // 8003C2E0: lfd     f29, 240(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C2E0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(240);
        ctx->fpr[29] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003C2E4:
    ctx->pc = 0x8003C2E4u;
    // 8003C2E4: psq_l   f28, 232(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8003C2E4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(232);
        ppc_psq_load_inline(ctx, 28u, ea, false, 0u, false, 0x8003C2E4u);
        if (ctx->exception) return;
    }

label_8003C2E8:
    ctx->pc = 0x8003C2E8u;
    // 8003C2E8: lfd     f28, 224(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C2E8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(224);
        ctx->fpr[28] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003C2EC:
    ctx->pc = 0x8003C2ECu;
    // 8003C2EC: psq_l   f27, 216(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8003C2ECu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(216);
        ppc_psq_load_inline(ctx, 27u, ea, false, 0u, false, 0x8003C2ECu);
        if (ctx->exception) return;
    }

label_8003C2F0:
    ctx->pc = 0x8003C2F0u;
    // 8003C2F0: lfd     f27, 208(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C2F0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(208);
        ctx->fpr[27] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003C2F4:
    ctx->pc = 0x8003C2F4u;
    // 8003C2F4: addi    r11, r1, 208
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(208);

label_8003C2F8:
    ctx->pc = 0x8003C2F8u;
    // 8003C2F8: bl      0x80286A88
    {
            ctx->lr = 0x8003C2FCu;
            ctx->pc = 0x80286A88u;
            return;
    }

label_8003C2FC:
    ctx->pc = 0x8003C2FCu;
    ctx->downcount -= 5;
    // 8003C2FC: lwz     r0, 292(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(292);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003C300:
    ctx->pc = 0x8003C300u;
    // 8003C300: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8003C304:
    ctx->pc = 0x8003C304u;
    // 8003C304: addi    r1, r1, 288
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(288);

label_8003C308:
    ctx->pc = 0x8003C308u;
    // 8003C308: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8003A6E0;
        }
    }

label_8003C30C:
    ctx->pc = 0x8003C30Cu;
    ctx->downcount -= 9;
    // 8003C30C: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8003C310:
    ctx->pc = 0x8003C310u;
    // 8003C310: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8003C314:
    ctx->pc = 0x8003C314u;
    // 8003C314: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003C318:
    ctx->pc = 0x8003C318u;
    // 8003C318: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8003C31C:
    ctx->pc = 0x8003C31Cu;
    // 8003C31C: stw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8003C320:
    ctx->pc = 0x8003C320u;
    // 8003C320: stw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_8003C324:
    ctx->pc = 0x8003C324u;
    // 8003C324: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003C328:
    ctx->pc = 0x8003C328u;
    // 8003C328: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8003C32C:
    ctx->pc = 0x8003C32Cu;
    // 8003C32C: bl      0x80022BB0
    {
            ctx->lr = 0x8003C330u;
            ctx->pc = 0x80022BB0u;
            return;
    }

label_8003C330:
    ctx->pc = 0x8003C330u;
    ctx->downcount -= 4;
    // 8003C330: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003C334:
    ctx->pc = 0x8003C334u;
    // 8003C334: lbz     r0, 244(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(244);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003C338:
    ctx->pc = 0x8003C338u;
    // 8003C338: cmplwi  r0, 0x0000
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

label_8003C33C:
    ctx->pc = 0x8003C33Cu;
    // 8003C33C: bc    12, 2, 0x8003C34C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003C34C;
        }
    }

label_8003C340:
    ctx->pc = 0x8003C340u;
    ctx->downcount -= 3;
    // 8003C340: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8003C344:
    ctx->pc = 0x8003C344u;
    // 8003C344: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8003C348:
    ctx->pc = 0x8003C348u;
    // 8003C348: bl      0x8003C090
    {
            ctx->lr = 0x8003C34Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003C090u;
                return;
            }
            goto label_8003C090;
    }

label_8003C34C:
    ctx->pc = 0x8003C34Cu;
    ctx->downcount -= 5;
    // 8003C34C: lbz     r3, 243(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(243);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8003C350:
    ctx->pc = 0x8003C350u;
    // 8003C350: lbz     r0, 244(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(244);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003C354:
    ctx->pc = 0x8003C354u;
    // 8003C354: add   r29, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[29] = res;
    }

label_8003C358:
    ctx->pc = 0x8003C358u;
    // 8003C358: cmpwi   r29, 2
    {
        s32 val_a = (s32)(ctx->gpr[29]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003C35C:
    ctx->pc = 0x8003C35Cu;
    // 8003C35C: bc    12, 0, 0x8003C3D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003C3D8;
        }
    }

label_8003C360:
    ctx->pc = 0x8003C360u;
    ctx->downcount -= 2;
    // 8003C360: cmpwi   r29, 100
    {
        s32 val_a = (s32)(ctx->gpr[29]);
        s32 val_b = (s32)(100);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003C364:
    ctx->pc = 0x8003C364u;
    // 8003C364: bc    12, 1, 0x8003C3D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003C3D8;
        }
    }

label_8003C368:
    ctx->pc = 0x8003C368u;
    ctx->downcount -= 3;
    // 8003C368: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8003C36C:
    ctx->pc = 0x8003C36Cu;
    // 8003C36C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003C370:
    ctx->pc = 0x8003C370u;
    // 8003C370: bl      0x800286CC
    {
            ctx->lr = 0x8003C374u;
            ctx->pc = 0x800286CCu;
            return;
    }

label_8003C374:
    ctx->pc = 0x8003C374u;
    ctx->downcount -= 3;
    // 8003C374: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003C378:
    ctx->pc = 0x8003C378u;
    // 8003C378: rlwinm r4, r29, 6, 0, 25
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[29], 6u) & 0xFFFFFFC0u;
    }

label_8003C37C:
    ctx->pc = 0x8003C37Cu;
    // 8003C37C: bl      0x80242328
    {
            ctx->lr = 0x8003C380u;
            ctx->pc = 0x80242328u;
            return;
    }

label_8003C380:
    ctx->pc = 0x8003C380u;
    ctx->downcount -= 4;
    // 8003C380: rlwinm r0, r29, 1, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[29], 1u) & 0xFFFFFFFEu;
    }

label_8003C384:
    ctx->pc = 0x8003C384u;
    // 8003C384: rlwinm r29, r0, 0, 24, 31
    {
        ctx->gpr[29] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_8003C388:
    ctx->pc = 0x8003C388u;
    // 8003C388: addi    r31, r31, 9984
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(9984);

label_8003C38C:
    ctx->pc = 0x8003C38Cu;
    // 8003C38C: b       0x8003C3AC
    {
            goto label_8003C3AC;
    }

label_8003C390:
    ctx->downcount -= 4;
    // 8003C390: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8003C394:
    // 8003C394: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8003C398:
    // 8003C398: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003C39C:
    // 8003C39C: bl      0x80022B60
    {
            ctx->lr = 0x8003C3A0u;
            ctx->pc = 0x80022B60u;
            return;
    }

label_8003C3A0:
    ctx->downcount -= 3;
    // 8003C3A0: addi    r29, r29, -128
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(-128);

label_8003C3A4:
    // 8003C3A4: addi    r30, r30, 4096
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(4096);

label_8003C3A8:
    // 8003C3A8: addi    r31, r31, 4096
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(4096);

label_8003C3AC:
    ctx->downcount -= 3;
    // 8003C3AC: rlwinm r5, r29, 0, 24, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[29], 0u) & 0x000000FFu;
    }

label_8003C3B0:
    // 8003C3B0: cmplwi  r5, 0x0080
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(0x0080u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003C3B4:
    // 8003C3B4: bc    4, 0, 0x8003C390
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003C390u;
                return;
            }
            goto label_8003C390;
        }
    }

label_8003C3B8:
    ctx->pc = 0x8003C3B8u;
    ctx->downcount -= 2;
    // 8003C3B8: cmplwi  r5, 0x0000
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

label_8003C3BC:
    ctx->pc = 0x8003C3BCu;
    // 8003C3BC: bc    12, 2, 0x8003C3CC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003C3CC;
        }
    }

label_8003C3C0:
    ctx->pc = 0x8003C3C0u;
    ctx->downcount -= 3;
    // 8003C3C0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8003C3C4:
    ctx->pc = 0x8003C3C4u;
    // 8003C3C4: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8003C3C8:
    ctx->pc = 0x8003C3C8u;
    // 8003C3C8: bl      0x80022B60
    {
            ctx->lr = 0x8003C3CCu;
            ctx->pc = 0x80022B60u;
            return;
    }

label_8003C3CC:
    ctx->pc = 0x8003C3CCu;
    ctx->downcount -= 3;
    // 8003C3CC: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8003C3D0:
    ctx->pc = 0x8003C3D0u;
    // 8003C3D0: stw     r0, -25920(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25920);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003C3D4:
    ctx->pc = 0x8003C3D4u;
    // 8003C3D4: b       0x8003C3E0
    {
            goto label_8003C3E0;
    }

label_8003C3D8:
    ctx->pc = 0x8003C3D8u;
    ctx->downcount -= 2;
    // 8003C3D8: li      r0, 3
    ctx->gpr[0] = (u32)(s32)(3);

label_8003C3DC:
    ctx->pc = 0x8003C3DCu;
    // 8003C3DC: stw     r0, -25920(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25920);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003C3E0:
    ctx->pc = 0x8003C3E0u;
    ctx->downcount -= 8;
    // 8003C3E0: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8003C3E4:
    ctx->pc = 0x8003C3E4u;
    // 8003C3E4: lwz     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8003C3E8:
    ctx->pc = 0x8003C3E8u;
    // 8003C3E8: lwz     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_8003C3EC:
    ctx->pc = 0x8003C3ECu;
    // 8003C3EC: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003C3F0:
    ctx->pc = 0x8003C3F0u;
    // 8003C3F0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8003C3F4:
    ctx->pc = 0x8003C3F4u;
    // 8003C3F4: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_8003C3F8:
    ctx->pc = 0x8003C3F8u;
    // 8003C3F8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8003A6E0;
        }
    }

label_8003C3FC:
    ctx->pc = 0x8003C3FCu;
    ctx->downcount -= 45;
    // 8003C3FC: stwu     r1, -416(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-416);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8003C400:
    ctx->pc = 0x8003C400u;
    // 8003C400: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8003C404:
    ctx->pc = 0x8003C404u;
    // 8003C404: stw     r0, 420(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(420);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003C408:
    ctx->pc = 0x8003C408u;
    // 8003C408: stfd     f31, 400(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C408u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(400);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_8003C40C:
    ctx->pc = 0x8003C40Cu;
    // 8003C40C: psq_st   f31, 408(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8003C40Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(408);
        ppc_psq_store_inline(ctx, 31u, ea, false, 0u, false, 0x8003C40Cu);
        if (ctx->exception) return;
    }

label_8003C410:
    ctx->pc = 0x8003C410u;
    // 8003C410: stw     r31, 396(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(396);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8003C414:
    ctx->pc = 0x8003C414u;
    // 8003C414: stw     r30, 392(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(392);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8003C418:
    ctx->pc = 0x8003C418u;
    // 8003C418: stw     r29, 388(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(388);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_8003C41C:
    ctx->pc = 0x8003C41Cu;
    // 8003C41C: stw     r28, 384(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(384);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_8003C420:
    ctx->pc = 0x8003C420u;
    // 8003C420: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003C424:
    ctx->pc = 0x8003C424u;
    // 8003C424: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8003C428:
    ctx->pc = 0x8003C428u;
    // 8003C428: or   r31, r5, r5
    {
        ctx->gpr[31] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8003C42C:
    ctx->pc = 0x8003C42Cu;
    // 8003C42C: lwz     r0, -31484(r2)
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31484);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003C430:
    ctx->pc = 0x8003C430u;
    // 8003C430: stw     r0, 72(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003C434:
    ctx->pc = 0x8003C434u;
    // 8003C434: lis     r3, -32724
    ctx->gpr[3] = ((u32)(s32)(-32724) << 16);

label_8003C438:
    ctx->pc = 0x8003C438u;
    // 8003C438: addi    r4, r3, 9408
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(9408);

label_8003C43C:
    ctx->pc = 0x8003C43Cu;
    // 8003C43C: lwz     r3, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003C440:
    ctx->pc = 0x8003C440u;
    // 8003C440: lwz     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003C444:
    ctx->pc = 0x8003C444u;
    // 8003C444: stw     r3, 100(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(100);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8003C448:
    ctx->pc = 0x8003C448u;
    // 8003C448: stw     r0, 104(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003C44C:
    ctx->pc = 0x8003C44Cu;
    // 8003C44C: lwz     r3, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003C450:
    ctx->pc = 0x8003C450u;
    // 8003C450: lwz     r0, 12(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003C454:
    ctx->pc = 0x8003C454u;
    // 8003C454: stw     r3, 108(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(108);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8003C458:
    ctx->pc = 0x8003C458u;
    // 8003C458: stw     r0, 112(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(112);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003C45C:
    ctx->pc = 0x8003C45Cu;
    // 8003C45C: lwz     r3, 16(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003C460:
    ctx->pc = 0x8003C460u;
    // 8003C460: lwz     r0, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003C464:
    ctx->pc = 0x8003C464u;
    // 8003C464: stw     r3, 116(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(116);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8003C468:
    ctx->pc = 0x8003C468u;
    // 8003C468: stw     r0, 120(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(120);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003C46C:
    ctx->pc = 0x8003C46Cu;
    // 8003C46C: lis     r3, -32724
    ctx->gpr[3] = ((u32)(s32)(-32724) << 16);

label_8003C470:
    ctx->pc = 0x8003C470u;
    // 8003C470: addi    r4, r3, 9432
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(9432);

label_8003C474:
    ctx->pc = 0x8003C474u;
    // 8003C474: lwz     r3, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003C478:
    ctx->pc = 0x8003C478u;
    // 8003C478: lwz     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003C47C:
    ctx->pc = 0x8003C47Cu;
    // 8003C47C: stw     r3, 76(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(76);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8003C480:
    ctx->pc = 0x8003C480u;
    // 8003C480: stw     r0, 80(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003C484:
    ctx->pc = 0x8003C484u;
    // 8003C484: lwz     r3, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003C488:
    ctx->pc = 0x8003C488u;
    // 8003C488: lwz     r0, 12(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003C48C:
    ctx->pc = 0x8003C48Cu;
    // 8003C48C: stw     r3, 84(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8003C490:
    ctx->pc = 0x8003C490u;
    // 8003C490: stw     r0, 88(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003C494:
    ctx->pc = 0x8003C494u;
    // 8003C494: lwz     r3, 16(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003C498:
    ctx->pc = 0x8003C498u;
    // 8003C498: lwz     r0, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003C49C:
    ctx->pc = 0x8003C49Cu;
    // 8003C49C: stw     r3, 92(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8003C4A0:
    ctx->pc = 0x8003C4A0u;
    // 8003C4A0: stw     r0, 96(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003C4A4:
    ctx->pc = 0x8003C4A4u;
    // 8003C4A4: lwz     r3, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003C4A8:
    ctx->pc = 0x8003C4A8u;
    // 8003C4A8: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8003C4AC:
    ctx->pc = 0x8003C4ACu;
    // 8003C4AC: bl      0x80028584
    {
            ctx->lr = 0x8003C4B0u;
            ctx->pc = 0x80028584u;
            return;
    }

label_8003C4B0:
    ctx->pc = 0x8003C4B0u;
    ctx->downcount -= 5;
    // 8003C4B0: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003C4B4:
    ctx->pc = 0x8003C4B4u;
    // 8003C4B4: lwz     r0, 60(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(60);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003C4B8:
    ctx->pc = 0x8003C4B8u;
    // 8003C4B8: rlwinm r0, r0, 0, 22, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000200u;
    }

label_8003C4BC:
    ctx->pc = 0x8003C4BCu;
    // 8003C4BC: cmplwi  r0, 0x0000
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

label_8003C4C0:
    ctx->pc = 0x8003C4C0u;
    // 8003C4C0: bc    4, 2, 0x8003C4FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003C4FC;
        }
    }

label_8003C4C4:
    ctx->pc = 0x8003C4C4u;
    ctx->downcount -= 4;
    // 8003C4C4: lwz     r0, -25924(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25924);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003C4C8:
    ctx->pc = 0x8003C4C8u;
    // 8003C4C8: rlwinm r0, r0, 0, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000003u;
    }

label_8003C4CC:
    ctx->pc = 0x8003C4CCu;
    // 8003C4CC: cmpwi   r0, 0
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

label_8003C4D0:
    ctx->pc = 0x8003C4D0u;
    // 8003C4D0: bc    12, 2, 0x8003C4E4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003C4E4;
        }
    }

label_8003C4D4:
    ctx->pc = 0x8003C4D4u;
    ctx->downcount -= 4;
    // 8003C4D4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8003C4D8:
    ctx->pc = 0x8003C4D8u;
    // 8003C4D8: stb     r0, -25930(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25930);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8003C4DC:
    ctx->pc = 0x8003C4DCu;
    // 8003C4DC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003C4E0:
    ctx->pc = 0x8003C4E0u;
    // 8003C4E0: b       0x8003CD88
    {
            goto label_8003CD88;
    }

label_8003C4E4:
    ctx->pc = 0x8003C4E4u;
    ctx->downcount -= 4;
    // 8003C4E4: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8003C4E8:
    ctx->pc = 0x8003C4E8u;
    // 8003C4E8: stb     r0, -25930(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25930);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8003C4EC:
    ctx->pc = 0x8003C4ECu;
    // 8003C4EC: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8003C4F0:
    ctx->pc = 0x8003C4F0u;
    // 8003C4F0: bl      0x8003D88C
    {
            ctx->lr = 0x8003C4F4u;
            goto label_8003D88C;
    }

label_8003C4F4:
    ctx->pc = 0x8003C4F4u;
    ctx->downcount -= 2;
    // 8003C4F4: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003C4F8:
    ctx->pc = 0x8003C4F8u;
    // 8003C4F8: b       0x8003CD88
    {
            goto label_8003CD88;
    }

label_8003C4FC:
    ctx->pc = 0x8003C4FCu;
    ctx->downcount -= 5;
    // 8003C4FC: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8003C500:
    ctx->pc = 0x8003C500u;
    // 8003C500: stb     r0, -25930(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25930);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8003C504:
    ctx->pc = 0x8003C504u;
    // 8003C504: addi    r3, r1, 68
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(68);

label_8003C508:
    ctx->pc = 0x8003C508u;
    // 8003C508: addi    r4, r1, 64
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(64);

label_8003C50C:
    ctx->pc = 0x8003C50Cu;
    // 8003C50C: bl      0x8006C6C4
    {
            ctx->lr = 0x8003C510u;
            ctx->pc = 0x8006C6C4u;
            return;
    }

label_8003C510:
    ctx->pc = 0x8003C510u;
    ctx->downcount -= 37;
    // 8003C510: lwz     r0, -25924(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25924);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003C514:
    ctx->pc = 0x8003C514u;
    // 8003C514: lfd     f2, -31416(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003C514u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31416);
        ctx->fpr[2] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003C518:
    ctx->pc = 0x8003C518u;
    // 8003C518: xoris   r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] ^ (0x8000u << 16);

label_8003C51C:
    ctx->pc = 0x8003C51Cu;
    // 8003C51C: stw     r0, 372(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(372);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003C520:
    ctx->pc = 0x8003C520u;
    // 8003C520: lis     r3, 17200
    ctx->gpr[3] = ((u32)(s32)(17200) << 16);

label_8003C524:
    ctx->pc = 0x8003C524u;
    // 8003C524: stw     r3, 368(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(368);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8003C528:
    ctx->pc = 0x8003C528u;
    // 8003C528: lfd     f0, 368(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C528u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(368);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003C52C:
    ctx->pc = 0x8003C52Cu;
    // 8003C52C: fsubs   f1, f0, f2
    if (!ppc_fp_available_inline(ctx, 0x8003C52Cu)) return;
    ppc_fsubs(ctx, 1, 0, 2);

label_8003C530:
    ctx->pc = 0x8003C530u;
    // 8003C530: lwz     r0, 64(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003C534:
    ctx->pc = 0x8003C534u;
    // 8003C534: xoris   r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] ^ (0x8000u << 16);

label_8003C538:
    ctx->pc = 0x8003C538u;
    // 8003C538: stw     r0, 380(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(380);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003C53C:
    ctx->pc = 0x8003C53Cu;
    // 8003C53C: stw     r3, 376(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(376);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8003C540:
    ctx->pc = 0x8003C540u;
    // 8003C540: lfd     f0, 376(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C540u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(376);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003C544:
    ctx->pc = 0x8003C544u;
    // 8003C544: fsubs   f0, f0, f2
    if (!ppc_fp_available_inline(ctx, 0x8003C544u)) return;
    ppc_fsubs(ctx, 0, 0, 2);

label_8003C548:
    ctx->pc = 0x8003C548u;
    // 8003C548: fdivs   f31, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8003C548u)) return;
    ppc_fdivs(ctx, 31, 1, 0);

label_8003C54C:
    ctx->pc = 0x8003C54Cu;
    // 8003C54C: fmuls   f31, f31, f31
    if (!ppc_fp_available_inline(ctx, 0x8003C54Cu)) return;
    ppc_fmuls(ctx, 31, 31, 31);

label_8003C550:
    ctx->pc = 0x8003C550u;
    // 8003C550: lfs     f0, -31440(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003C550u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31440);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003C554:
    ctx->pc = 0x8003C554u;
    // 8003C554: fmuls   f31, f31, f0
    if (!ppc_fp_available_inline(ctx, 0x8003C554u)) return;
    ppc_fmuls(ctx, 31, 31, 0);

label_8003C558:
    ctx->pc = 0x8003C558u;
    // 8003C558: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8003C55C:
    ctx->pc = 0x8003C55Cu;
    // 8003C55C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003C560:
    ctx->pc = 0x8003C560u;
    // 8003C560: bl      0x8004C434
    {
            ctx->lr = 0x8003C564u;
            ctx->pc = 0x8004C434u;
            return;
    }

label_8003C564:
    ctx->pc = 0x8003C564u;
    ctx->downcount -= 2;
    // 8003C564: lwz     r3, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003C568:
    ctx->pc = 0x8003C568u;
    // 8003C568: bl      0x800538A4
    {
            ctx->lr = 0x8003C56Cu;
            ctx->pc = 0x800538A4u;
            return;
    }

label_8003C56C:
    ctx->pc = 0x8003C56Cu;
    ctx->downcount -= 2;
    // 8003C56C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003C570:
    ctx->pc = 0x8003C570u;
    // 8003C570: bl      0x8004C4C8
    {
            ctx->lr = 0x8003C574u;
            ctx->pc = 0x8004C4C8u;
            return;
    }

label_8003C574:
    ctx->pc = 0x8003C574u;
    ctx->downcount -= 7;
    // 8003C574: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003C578:
    ctx->pc = 0x8003C578u;
    // 8003C578: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8003C57C:
    ctx->pc = 0x8003C57Cu;
    // 8003C57C: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_8003C580:
    ctx->pc = 0x8003C580u;
    // 8003C580: li      r6, 60
    ctx->gpr[6] = (u32)(s32)(60);

label_8003C584:
    ctx->pc = 0x8003C584u;
    // 8003C584: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8003C588:
    ctx->pc = 0x8003C588u;
    // 8003C588: li      r8, 125
    ctx->gpr[8] = (u32)(s32)(125);

label_8003C58C:
    ctx->pc = 0x8003C58Cu;
    // 8003C58C: bl      0x80258880
    {
            ctx->lr = 0x8003C590u;
            ctx->pc = 0x80258880u;
            return;
    }

label_8003C590:
    ctx->pc = 0x8003C590u;
    ctx->downcount -= 2;
    // 8003C590: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003C594:
    ctx->pc = 0x8003C594u;
    // 8003C594: bl      0x8025C08C
    {
            ctx->lr = 0x8003C598u;
            ctx->pc = 0x8025C08Cu;
            return;
    }

label_8003C598:
    ctx->pc = 0x8003C598u;
    ctx->downcount -= 5;
    // 8003C598: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003C59C:
    ctx->pc = 0x8003C59Cu;
    // 8003C59C: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_8003C5A0:
    ctx->pc = 0x8003C5A0u;
    // 8003C5A0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003C5A4:
    ctx->pc = 0x8003C5A4u;
    // 8003C5A4: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_8003C5A8:
    ctx->pc = 0x8003C5A8u;
    // 8003C5A8: bl      0x8025CA34
    {
            ctx->lr = 0x8003C5ACu;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_8003C5AC:
    ctx->pc = 0x8003C5ACu;
    ctx->downcount -= 6;
    // 8003C5AC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003C5B0:
    ctx->pc = 0x8003C5B0u;
    // 8003C5B0: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_8003C5B4:
    ctx->pc = 0x8003C5B4u;
    // 8003C5B4: li      r5, 15
    ctx->gpr[5] = (u32)(s32)(15);

label_8003C5B8:
    ctx->pc = 0x8003C5B8u;
    // 8003C5B8: li      r6, 15
    ctx->gpr[6] = (u32)(s32)(15);

label_8003C5BC:
    ctx->pc = 0x8003C5BCu;
    // 8003C5BC: li      r7, 8
    ctx->gpr[7] = (u32)(s32)(8);

label_8003C5C0:
    ctx->pc = 0x8003C5C0u;
    // 8003C5C0: bl      0x8025C3B0
    {
            ctx->lr = 0x8003C5C4u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_8003C5C4:
    ctx->pc = 0x8003C5C4u;
    ctx->downcount -= 6;
    // 8003C5C4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003C5C8:
    ctx->pc = 0x8003C5C8u;
    // 8003C5C8: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_8003C5CC:
    ctx->pc = 0x8003C5CCu;
    // 8003C5CC: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_8003C5D0:
    ctx->pc = 0x8003C5D0u;
    // 8003C5D0: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_8003C5D4:
    ctx->pc = 0x8003C5D4u;
    // 8003C5D4: li      r7, 7
    ctx->gpr[7] = (u32)(s32)(7);

label_8003C5D8:
    ctx->pc = 0x8003C5D8u;
    // 8003C5D8: bl      0x8025C430
    {
            ctx->lr = 0x8003C5DCu;
            ctx->pc = 0x8025C430u;
            return;
    }

label_8003C5DC:
    ctx->pc = 0x8003C5DCu;
    ctx->downcount -= 4;
    // 8003C5DC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003C5E0:
    ctx->pc = 0x8003C5E0u;
    // 8003C5E0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003C5E4:
    ctx->pc = 0x8003C5E4u;
    // 8003C5E4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003C5E8:
    ctx->pc = 0x8003C5E8u;
    // 8003C5E8: bl      0x8025C868
    {
            ctx->lr = 0x8003C5ECu;
            ctx->pc = 0x8025C868u;
            return;
    }

label_8003C5EC:
    ctx->pc = 0x8003C5ECu;
    ctx->downcount -= 7;
    // 8003C5EC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003C5F0:
    ctx->pc = 0x8003C5F0u;
    // 8003C5F0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003C5F4:
    ctx->pc = 0x8003C5F4u;
    // 8003C5F4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003C5F8:
    ctx->pc = 0x8003C5F8u;
    // 8003C5F8: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8003C5FC:
    ctx->pc = 0x8003C5FCu;
    // 8003C5FC: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8003C600:
    ctx->pc = 0x8003C600u;
    // 8003C600: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8003C604:
    ctx->pc = 0x8003C604u;
    // 8003C604: bl      0x8025C4B4
    {
            ctx->lr = 0x8003C608u;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_8003C608:
    ctx->pc = 0x8003C608u;
    ctx->downcount -= 7;
    // 8003C608: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003C60C:
    ctx->pc = 0x8003C60Cu;
    // 8003C60C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003C610:
    ctx->pc = 0x8003C610u;
    // 8003C610: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003C614:
    ctx->pc = 0x8003C614u;
    // 8003C614: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8003C618:
    ctx->pc = 0x8003C618u;
    // 8003C618: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8003C61C:
    ctx->pc = 0x8003C61Cu;
    // 8003C61C: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8003C620:
    ctx->pc = 0x8003C620u;
    // 8003C620: bl      0x8025C574
    {
            ctx->lr = 0x8003C624u;
            ctx->pc = 0x8025C574u;
            return;
    }

label_8003C624:
    ctx->pc = 0x8003C624u;
    ctx->downcount -= 9;
    // 8003C624: lbz     r0, 241(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(241);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003C628:
    ctx->pc = 0x8003C628u;
    // 8003C628: stb     r0, 74(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(74);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8003C62C:
    ctx->pc = 0x8003C62Cu;
    // 8003C62C: stb     r0, 73(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(73);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8003C630:
    ctx->pc = 0x8003C630u;
    // 8003C630: stb     r0, 72(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8003C634:
    ctx->pc = 0x8003C634u;
    // 8003C634: lwz     r0, 72(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003C638:
    ctx->pc = 0x8003C638u;
    // 8003C638: stw     r0, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003C63C:
    ctx->pc = 0x8003C63Cu;
    // 8003C63C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003C640:
    ctx->pc = 0x8003C640u;
    // 8003C640: addi    r4, r1, 32
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(32);

label_8003C644:
    ctx->pc = 0x8003C644u;
    // 8003C644: bl      0x8025C71C
    {
            ctx->lr = 0x8003C648u;
            ctx->pc = 0x8025C71Cu;
            return;
    }

label_8003C648:
    ctx->pc = 0x8003C648u;
    ctx->downcount -= 3;
    // 8003C648: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003C64C:
    ctx->pc = 0x8003C64Cu;
    // 8003C64C: li      r4, 28
    ctx->gpr[4] = (u32)(s32)(28);

label_8003C650:
    ctx->pc = 0x8003C650u;
    // 8003C650: bl      0x8025C7FC
    {
            ctx->lr = 0x8003C654u;
            ctx->pc = 0x8025C7FCu;
            return;
    }

label_8003C654:
    ctx->pc = 0x8003C654u;
    ctx->downcount -= 3;
    // 8003C654: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003C658:
    ctx->pc = 0x8003C658u;
    // 8003C658: li      r4, 12
    ctx->gpr[4] = (u32)(s32)(12);

label_8003C65C:
    ctx->pc = 0x8003C65Cu;
    // 8003C65C: bl      0x8025C790
    {
            ctx->lr = 0x8003C660u;
            ctx->pc = 0x8025C790u;
            return;
    }

label_8003C660:
    ctx->pc = 0x8003C660u;
    ctx->downcount -= 5;
    // 8003C660: addi    r3, r1, 268
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(268);

label_8003C664:
    ctx->pc = 0x8003C664u;
    // 8003C664: lfs     f1, -31436(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003C664u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31436);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003C668:
    ctx->pc = 0x8003C668u;
    // 8003C668: fmr    f2, f1
    if (!ppc_fp_available_inline(ctx, 0x8003C668u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_8003C66C:
    ctx->pc = 0x8003C66Cu;
    // 8003C66C: lfs     f3, -31476(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003C66Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31476);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8003C670:
    ctx->pc = 0x8003C670u;
    // 8003C670: bl      0x80247CC4
    {
            ctx->lr = 0x8003C674u;
            ctx->pc = 0x80247CC4u;
            return;
    }

label_8003C674:
    ctx->pc = 0x8003C674u;
    ctx->downcount -= 5;
    // 8003C674: addi    r3, r1, 220
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(220);

label_8003C678:
    ctx->pc = 0x8003C678u;
    // 8003C678: lfs     f1, -31440(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003C678u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31440);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003C67C:
    ctx->pc = 0x8003C67Cu;
    // 8003C67C: fmr    f2, f1
    if (!ppc_fp_available_inline(ctx, 0x8003C67Cu)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_8003C680:
    ctx->pc = 0x8003C680u;
    // 8003C680: lfs     f3, -31452(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003C680u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31452);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8003C684:
    ctx->pc = 0x8003C684u;
    // 8003C684: bl      0x80247C90
    {
            ctx->lr = 0x8003C688u;
            ctx->pc = 0x80247C90u;
            return;
    }

label_8003C688:
    ctx->pc = 0x8003C688u;
    ctx->downcount -= 4;
    // 8003C688: addi    r3, r1, 220
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(220);

label_8003C68C:
    ctx->pc = 0x8003C68Cu;
    // 8003C68C: addi    r4, r1, 268
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(268);

label_8003C690:
    ctx->pc = 0x8003C690u;
    // 8003C690: or   r5, r4, r4
    {
        ctx->gpr[5] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8003C694:
    ctx->pc = 0x8003C694u;
    // 8003C694: bl      0x80247860
    {
            ctx->lr = 0x8003C698u;
            ctx->pc = 0x80247860u;
            return;
    }

label_8003C698:
    ctx->pc = 0x8003C698u;
    ctx->downcount -= 4;
    // 8003C698: addi    r3, r1, 268
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(268);

label_8003C69C:
    ctx->pc = 0x8003C69Cu;
    // 8003C69C: li      r4, 67
    ctx->gpr[4] = (u32)(s32)(67);

label_8003C6A0:
    ctx->pc = 0x8003C6A0u;
    // 8003C6A0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003C6A4:
    ctx->pc = 0x8003C6A4u;
    // 8003C6A4: bl      0x8025DAD0
    {
            ctx->lr = 0x8003C6A8u;
            ctx->pc = 0x8025DAD0u;
            return;
    }

label_8003C6A8:
    ctx->pc = 0x8003C6A8u;
    ctx->downcount -= 7;
    // 8003C6A8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003C6AC:
    ctx->pc = 0x8003C6ACu;
    // 8003C6AC: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8003C6B0:
    ctx->pc = 0x8003C6B0u;
    // 8003C6B0: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_8003C6B4:
    ctx->pc = 0x8003C6B4u;
    // 8003C6B4: li      r6, 30
    ctx->gpr[6] = (u32)(s32)(30);

label_8003C6B8:
    ctx->pc = 0x8003C6B8u;
    // 8003C6B8: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8003C6BC:
    ctx->pc = 0x8003C6BCu;
    // 8003C6BC: li      r8, 67
    ctx->gpr[8] = (u32)(s32)(67);

label_8003C6C0:
    ctx->pc = 0x8003C6C0u;
    // 8003C6C0: bl      0x80258880
    {
            ctx->lr = 0x8003C6C4u;
            ctx->pc = 0x80258880u;
            return;
    }

label_8003C6C4:
    ctx->pc = 0x8003C6C4u;
    ctx->downcount -= 3;
    // 8003C6C4: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8003C6C8:
    ctx->pc = 0x8003C6C8u;
    // 8003C6C8: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8003C6CC:
    ctx->pc = 0x8003C6CCu;
    // 8003C6CC: bl      0x80028718
    {
            ctx->lr = 0x8003C6D0u;
            ctx->pc = 0x80028718u;
            return;
    }

label_8003C6D0:
    ctx->pc = 0x8003C6D0u;
    ctx->downcount -= 3;
    // 8003C6D0: lwz     r3, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003C6D4:
    ctx->pc = 0x8003C6D4u;
    // 8003C6D4: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8003C6D8:
    ctx->pc = 0x8003C6D8u;
    // 8003C6D8: bl      0x8004C4C8
    {
            ctx->lr = 0x8003C6DCu;
            ctx->pc = 0x8004C4C8u;
            return;
    }

label_8003C6DC:
    ctx->pc = 0x8003C6DCu;
    ctx->downcount -= 2;
    // 8003C6DC: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003C6E0:
    ctx->pc = 0x8003C6E0u;
    // 8003C6E0: bl      0x8025C08C
    {
            ctx->lr = 0x8003C6E4u;
            ctx->pc = 0x8025C08Cu;
            return;
    }

label_8003C6E4:
    ctx->pc = 0x8003C6E4u;
    ctx->downcount -= 5;
    // 8003C6E4: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003C6E8:
    ctx->pc = 0x8003C6E8u;
    // 8003C6E8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003C6EC:
    ctx->pc = 0x8003C6ECu;
    // 8003C6EC: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_8003C6F0:
    ctx->pc = 0x8003C6F0u;
    // 8003C6F0: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_8003C6F4:
    ctx->pc = 0x8003C6F4u;
    // 8003C6F4: bl      0x8025CA34
    {
            ctx->lr = 0x8003C6F8u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_8003C6F8:
    ctx->pc = 0x8003C6F8u;
    ctx->downcount -= 4;
    // 8003C6F8: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003C6FC:
    ctx->pc = 0x8003C6FCu;
    // 8003C6FC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003C700:
    ctx->pc = 0x8003C700u;
    // 8003C700: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003C704:
    ctx->pc = 0x8003C704u;
    // 8003C704: bl      0x8025C868
    {
            ctx->lr = 0x8003C708u;
            ctx->pc = 0x8025C868u;
            return;
    }

label_8003C708:
    ctx->pc = 0x8003C708u;
    ctx->downcount -= 6;
    // 8003C708: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003C70C:
    ctx->pc = 0x8003C70Cu;
    // 8003C70C: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_8003C710:
    ctx->pc = 0x8003C710u;
    // 8003C710: li      r5, 8
    ctx->gpr[5] = (u32)(s32)(8);

label_8003C714:
    ctx->pc = 0x8003C714u;
    // 8003C714: li      r6, 14
    ctx->gpr[6] = (u32)(s32)(14);

label_8003C718:
    ctx->pc = 0x8003C718u;
    // 8003C718: li      r7, 10
    ctx->gpr[7] = (u32)(s32)(10);

label_8003C71C:
    ctx->pc = 0x8003C71Cu;
    // 8003C71C: bl      0x8025C3B0
    {
            ctx->lr = 0x8003C720u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_8003C720:
    ctx->pc = 0x8003C720u;
    ctx->downcount -= 6;
    // 8003C720: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003C724:
    ctx->pc = 0x8003C724u;
    // 8003C724: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_8003C728:
    ctx->pc = 0x8003C728u;
    // 8003C728: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_8003C72C:
    ctx->pc = 0x8003C72Cu;
    // 8003C72C: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_8003C730:
    ctx->pc = 0x8003C730u;
    // 8003C730: li      r7, 7
    ctx->gpr[7] = (u32)(s32)(7);

label_8003C734:
    ctx->pc = 0x8003C734u;
    // 8003C734: bl      0x8025C430
    {
            ctx->lr = 0x8003C738u;
            ctx->pc = 0x8025C430u;
            return;
    }

label_8003C738:
    ctx->pc = 0x8003C738u;
    ctx->downcount -= 7;
    // 8003C738: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003C73C:
    ctx->pc = 0x8003C73Cu;
    // 8003C73C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003C740:
    ctx->pc = 0x8003C740u;
    // 8003C740: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003C744:
    ctx->pc = 0x8003C744u;
    // 8003C744: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8003C748:
    ctx->pc = 0x8003C748u;
    // 8003C748: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8003C74C:
    ctx->pc = 0x8003C74Cu;
    // 8003C74C: li      r8, 2
    ctx->gpr[8] = (u32)(s32)(2);

label_8003C750:
    ctx->pc = 0x8003C750u;
    // 8003C750: bl      0x8025C4B4
    {
            ctx->lr = 0x8003C754u;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_8003C754:
    ctx->pc = 0x8003C754u;
    ctx->downcount -= 7;
    // 8003C754: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003C758:
    ctx->pc = 0x8003C758u;
    // 8003C758: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003C75C:
    ctx->pc = 0x8003C75Cu;
    // 8003C75C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003C760:
    ctx->pc = 0x8003C760u;
    // 8003C760: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8003C764:
    ctx->pc = 0x8003C764u;
    // 8003C764: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8003C768:
    ctx->pc = 0x8003C768u;
    // 8003C768: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8003C76C:
    ctx->pc = 0x8003C76Cu;
    // 8003C76C: bl      0x8025C574
    {
            ctx->lr = 0x8003C770u;
            ctx->pc = 0x8025C574u;
            return;
    }

label_8003C770:
    ctx->pc = 0x8003C770u;
    ctx->downcount -= 2;
    // 8003C770: addi    r3, r1, 60
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(60);

label_8003C774:
    ctx->pc = 0x8003C774u;
    // 8003C774: bl      0x8006C7C8
    {
            ctx->lr = 0x8003C778u;
            ctx->pc = 0x8006C7C8u;
            return;
    }

label_8003C778:
    ctx->pc = 0x8003C778u;
    ctx->downcount -= 3;
    // 8003C778: lwz     r3, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003C77C:
    ctx->pc = 0x8003C77Cu;
    // 8003C77C: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_8003C780:
    ctx->pc = 0x8003C780u;
    // 8003C780: bl      0x8004C4C8
    {
            ctx->lr = 0x8003C784u;
            ctx->pc = 0x8004C4C8u;
            return;
    }

label_8003C784:
    ctx->pc = 0x8003C784u;
    ctx->downcount -= 3;
    // 8003C784: addi    r3, r1, 56
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(56);

label_8003C788:
    ctx->pc = 0x8003C788u;
    // 8003C788: addi    r4, r1, 52
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(52);

label_8003C78C:
    ctx->pc = 0x8003C78Cu;
    // 8003C78C: bl      0x8006CCA0
    {
            ctx->lr = 0x8003C790u;
            ctx->pc = 0x8006CCA0u;
            return;
    }

label_8003C790:
    ctx->pc = 0x8003C790u;
    ctx->downcount -= 8;
    // 8003C790: addi    r3, r1, 172
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(172);

label_8003C794:
    ctx->pc = 0x8003C794u;
    // 8003C794: lfs     f2, -31440(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003C794u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31440);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8003C798:
    ctx->pc = 0x8003C798u;
    // 8003C798: lfs     f0, 56(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C798u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003C79C:
    ctx->pc = 0x8003C79Cu;
    // 8003C79C: fmuls   f1, f2, f0
    if (!ppc_fp_available_inline(ctx, 0x8003C79Cu)) return;
    ppc_fmuls(ctx, 1, 2, 0);

label_8003C7A0:
    ctx->pc = 0x8003C7A0u;
    // 8003C7A0: lfs     f0, 52(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C7A0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003C7A4:
    ctx->pc = 0x8003C7A4u;
    // 8003C7A4: fmuls   f2, f2, f0
    if (!ppc_fp_available_inline(ctx, 0x8003C7A4u)) return;
    ppc_fmuls(ctx, 2, 2, 0);

label_8003C7A8:
    ctx->pc = 0x8003C7A8u;
    // 8003C7A8: lfs     f3, -31476(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003C7A8u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31476);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8003C7AC:
    ctx->pc = 0x8003C7ACu;
    // 8003C7AC: bl      0x80247C90
    {
            ctx->lr = 0x8003C7B0u;
            ctx->pc = 0x80247C90u;
            return;
    }

label_8003C7B0:
    ctx->pc = 0x8003C7B0u;
    ctx->downcount -= 7;
    // 8003C7B0: lfs     f0, -31452(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003C7B0u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31452);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003C7B4:
    ctx->pc = 0x8003C7B4u;
    // 8003C7B4: stfs     f0, 172(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C7B4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003C7B8:
    ctx->pc = 0x8003C7B8u;
    // 8003C7B8: stfs     f0, 192(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C7B8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(192);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003C7BC:
    ctx->pc = 0x8003C7BCu;
    // 8003C7BC: addi    r3, r1, 172
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(172);

label_8003C7C0:
    ctx->pc = 0x8003C7C0u;
    // 8003C7C0: li      r4, 70
    ctx->gpr[4] = (u32)(s32)(70);

label_8003C7C4:
    ctx->pc = 0x8003C7C4u;
    // 8003C7C4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003C7C8:
    ctx->pc = 0x8003C7C8u;
    // 8003C7C8: bl      0x8025DAD0
    {
            ctx->lr = 0x8003C7CCu;
            ctx->pc = 0x8025DAD0u;
            return;
    }

label_8003C7CC:
    ctx->pc = 0x8003C7CCu;
    ctx->downcount -= 7;
    // 8003C7CC: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003C7D0:
    ctx->pc = 0x8003C7D0u;
    // 8003C7D0: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8003C7D4:
    ctx->pc = 0x8003C7D4u;
    // 8003C7D4: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_8003C7D8:
    ctx->pc = 0x8003C7D8u;
    // 8003C7D8: li      r6, 60
    ctx->gpr[6] = (u32)(s32)(60);

label_8003C7DC:
    ctx->pc = 0x8003C7DCu;
    // 8003C7DC: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8003C7E0:
    ctx->pc = 0x8003C7E0u;
    // 8003C7E0: li      r8, 70
    ctx->gpr[8] = (u32)(s32)(70);

label_8003C7E4:
    ctx->pc = 0x8003C7E4u;
    // 8003C7E4: bl      0x80258880
    {
            ctx->lr = 0x8003C7E8u;
            ctx->pc = 0x80258880u;
            return;
    }

label_8003C7E8:
    ctx->pc = 0x8003C7E8u;
    ctx->downcount -= 4;
    // 8003C7E8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003C7EC:
    ctx->pc = 0x8003C7ECu;
    // 8003C7EC: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8003C7F0:
    ctx->pc = 0x8003C7F0u;
    // 8003C7F0: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_8003C7F4:
    ctx->pc = 0x8003C7F4u;
    // 8003C7F4: bl      0x8025BF28
    {
            ctx->lr = 0x8003C7F8u;
            ctx->pc = 0x8025BF28u;
            return;
    }

label_8003C7F8:
    ctx->pc = 0x8003C7F8u;
    ctx->downcount -= 4;
    // 8003C7F8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003C7FC:
    ctx->pc = 0x8003C7FCu;
    // 8003C7FC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003C800:
    ctx->pc = 0x8003C800u;
    // 8003C800: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003C804:
    ctx->pc = 0x8003C804u;
    // 8003C804: bl      0x8025BD54
    {
            ctx->lr = 0x8003C808u;
            ctx->pc = 0x8025BD54u;
            return;
    }

label_8003C808:
    ctx->pc = 0x8003C808u;
    ctx->downcount -= 7;
    // 8003C808: stfs     f31, 100(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C808u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(100);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8003C80C:
    ctx->pc = 0x8003C80Cu;
    // 8003C80C: stfs     f31, 116(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C80Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(116);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8003C810:
    ctx->pc = 0x8003C810u;
    // 8003C810: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003C814:
    ctx->pc = 0x8003C814u;
    // 8003C814: addi    r4, r1, 100
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(100);

label_8003C818:
    ctx->pc = 0x8003C818u;
    // 8003C818: lwz     r0, -31992(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31992);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003C81C:
    ctx->pc = 0x8003C81Cu;
    // 8003C81C: extsb r5, r0
    {
        ctx->gpr[5] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8003C820:
    ctx->pc = 0x8003C820u;
    // 8003C820: bl      0x8025BBF4
    {
            ctx->lr = 0x8003C824u;
            ctx->pc = 0x8025BBF4u;
            return;
    }

label_8003C824:
    ctx->pc = 0x8003C824u;
    ctx->downcount -= 12;
    // 8003C824: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8003C828:
    ctx->pc = 0x8003C828u;
    // 8003C828: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003C82C:
    ctx->pc = 0x8003C82Cu;
    // 8003C82C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003C830:
    ctx->pc = 0x8003C830u;
    // 8003C830: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003C834:
    ctx->pc = 0x8003C834u;
    // 8003C834: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003C838:
    ctx->pc = 0x8003C838u;
    // 8003C838: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003C83C:
    ctx->pc = 0x8003C83Cu;
    // 8003C83C: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_8003C840:
    ctx->pc = 0x8003C840u;
    // 8003C840: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8003C844:
    ctx->pc = 0x8003C844u;
    // 8003C844: li      r8, 6
    ctx->gpr[8] = (u32)(s32)(6);

label_8003C848:
    ctx->pc = 0x8003C848u;
    // 8003C848: li      r9, 6
    ctx->gpr[9] = (u32)(s32)(6);

label_8003C84C:
    ctx->pc = 0x8003C84Cu;
    // 8003C84C: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_8003C850:
    ctx->pc = 0x8003C850u;
    // 8003C850: bl      0x8025BB58
    {
            ctx->lr = 0x8003C854u;
            ctx->pc = 0x8025BB58u;
            return;
    }

label_8003C854:
    ctx->pc = 0x8003C854u;
    ctx->downcount -= 5;
    // 8003C854: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003C858:
    ctx->pc = 0x8003C858u;
    // 8003C858: li      r4, 255
    ctx->gpr[4] = (u32)(s32)(255);

label_8003C85C:
    ctx->pc = 0x8003C85Cu;
    // 8003C85C: li      r5, 255
    ctx->gpr[5] = (u32)(s32)(255);

label_8003C860:
    ctx->pc = 0x8003C860u;
    // 8003C860: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_8003C864:
    ctx->pc = 0x8003C864u;
    // 8003C864: bl      0x8025CA34
    {
            ctx->lr = 0x8003C868u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_8003C868:
    ctx->pc = 0x8003C868u;
    ctx->downcount -= 4;
    // 8003C868: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003C86C:
    ctx->pc = 0x8003C86Cu;
    // 8003C86C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003C870:
    ctx->pc = 0x8003C870u;
    // 8003C870: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003C874:
    ctx->pc = 0x8003C874u;
    // 8003C874: bl      0x8025C868
    {
            ctx->lr = 0x8003C878u;
            ctx->pc = 0x8025C868u;
            return;
    }

label_8003C878:
    ctx->pc = 0x8003C878u;
    ctx->downcount -= 6;
    // 8003C878: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003C87C:
    ctx->pc = 0x8003C87Cu;
    // 8003C87C: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_8003C880:
    ctx->pc = 0x8003C880u;
    // 8003C880: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003C884:
    ctx->pc = 0x8003C884u;
    // 8003C884: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_8003C888:
    ctx->pc = 0x8003C888u;
    // 8003C888: li      r7, 15
    ctx->gpr[7] = (u32)(s32)(15);

label_8003C88C:
    ctx->pc = 0x8003C88Cu;
    // 8003C88C: bl      0x8025C3B0
    {
            ctx->lr = 0x8003C890u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_8003C890:
    ctx->pc = 0x8003C890u;
    ctx->downcount -= 6;
    // 8003C890: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003C894:
    ctx->pc = 0x8003C894u;
    // 8003C894: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_8003C898:
    ctx->pc = 0x8003C898u;
    // 8003C898: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_8003C89C:
    ctx->pc = 0x8003C89Cu;
    // 8003C89C: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_8003C8A0:
    ctx->pc = 0x8003C8A0u;
    // 8003C8A0: li      r7, 7
    ctx->gpr[7] = (u32)(s32)(7);

label_8003C8A4:
    ctx->pc = 0x8003C8A4u;
    // 8003C8A4: bl      0x8025C430
    {
            ctx->lr = 0x8003C8A8u;
            ctx->pc = 0x8025C430u;
            return;
    }

label_8003C8A8:
    ctx->pc = 0x8003C8A8u;
    ctx->downcount -= 7;
    // 8003C8A8: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003C8AC:
    ctx->pc = 0x8003C8ACu;
    // 8003C8AC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003C8B0:
    ctx->pc = 0x8003C8B0u;
    // 8003C8B0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003C8B4:
    ctx->pc = 0x8003C8B4u;
    // 8003C8B4: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8003C8B8:
    ctx->pc = 0x8003C8B8u;
    // 8003C8B8: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8003C8BC:
    ctx->pc = 0x8003C8BCu;
    // 8003C8BC: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8003C8C0:
    ctx->pc = 0x8003C8C0u;
    // 8003C8C0: bl      0x8025C4B4
    {
            ctx->lr = 0x8003C8C4u;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_8003C8C4:
    ctx->pc = 0x8003C8C4u;
    ctx->downcount -= 7;
    // 8003C8C4: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003C8C8:
    ctx->pc = 0x8003C8C8u;
    // 8003C8C8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003C8CC:
    ctx->pc = 0x8003C8CCu;
    // 8003C8CC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003C8D0:
    ctx->pc = 0x8003C8D0u;
    // 8003C8D0: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8003C8D4:
    ctx->pc = 0x8003C8D4u;
    // 8003C8D4: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8003C8D8:
    ctx->pc = 0x8003C8D8u;
    // 8003C8D8: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8003C8DC:
    ctx->pc = 0x8003C8DCu;
    // 8003C8DC: bl      0x8025C574
    {
            ctx->lr = 0x8003C8E0u;
            ctx->pc = 0x8025C574u;
            return;
    }

label_8003C8E0:
    ctx->pc = 0x8003C8E0u;
    ctx->downcount -= 2;
    // 8003C8E0: lwz     r3, 56(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(56);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003C8E4:
    ctx->pc = 0x8003C8E4u;
    // 8003C8E4: bl      0x800538A4
    {
            ctx->lr = 0x8003C8E8u;
            ctx->pc = 0x800538A4u;
            return;
    }

label_8003C8E8:
    ctx->pc = 0x8003C8E8u;
    ctx->downcount -= 2;
    // 8003C8E8: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_8003C8EC:
    ctx->pc = 0x8003C8ECu;
    // 8003C8EC: bl      0x8004C4C8
    {
            ctx->lr = 0x8003C8F0u;
            ctx->pc = 0x8004C4C8u;
            return;
    }

label_8003C8F0:
    ctx->pc = 0x8003C8F0u;
    ctx->downcount -= 7;
    // 8003C8F0: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_8003C8F4:
    ctx->pc = 0x8003C8F4u;
    // 8003C8F4: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8003C8F8:
    ctx->pc = 0x8003C8F8u;
    // 8003C8F8: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_8003C8FC:
    ctx->pc = 0x8003C8FCu;
    // 8003C8FC: li      r6, 60
    ctx->gpr[6] = (u32)(s32)(60);

label_8003C900:
    ctx->pc = 0x8003C900u;
    // 8003C900: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8003C904:
    ctx->pc = 0x8003C904u;
    // 8003C904: li      r8, 125
    ctx->gpr[8] = (u32)(s32)(125);

label_8003C908:
    ctx->pc = 0x8003C908u;
    // 8003C908: bl      0x80258880
    {
            ctx->lr = 0x8003C90Cu;
            ctx->pc = 0x80258880u;
            return;
    }

label_8003C90C:
    ctx->pc = 0x8003C90Cu;
    ctx->downcount -= 4;
    // 8003C90C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003C910:
    ctx->pc = 0x8003C910u;
    // 8003C910: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_8003C914:
    ctx->pc = 0x8003C914u;
    // 8003C914: li      r5, 2
    ctx->gpr[5] = (u32)(s32)(2);

label_8003C918:
    ctx->pc = 0x8003C918u;
    // 8003C918: bl      0x8025BF28
    {
            ctx->lr = 0x8003C91Cu;
            ctx->pc = 0x8025BF28u;
            return;
    }

label_8003C91C:
    ctx->pc = 0x8003C91Cu;
    ctx->downcount -= 4;
    // 8003C91C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003C920:
    ctx->pc = 0x8003C920u;
    // 8003C920: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003C924:
    ctx->pc = 0x8003C924u;
    // 8003C924: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003C928:
    ctx->pc = 0x8003C928u;
    // 8003C928: bl      0x8025BD54
    {
            ctx->lr = 0x8003C92Cu;
            ctx->pc = 0x8025BD54u;
            return;
    }

label_8003C92C:
    ctx->pc = 0x8003C92Cu;
    ctx->downcount -= 7;
    // 8003C92C: stfs     f31, 80(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C92Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8003C930:
    ctx->pc = 0x8003C930u;
    // 8003C930: stfs     f31, 96(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003C930u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8003C934:
    ctx->pc = 0x8003C934u;
    // 8003C934: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003C938:
    ctx->pc = 0x8003C938u;
    // 8003C938: addi    r4, r1, 76
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(76);

label_8003C93C:
    ctx->pc = 0x8003C93Cu;
    // 8003C93C: lwz     r0, -31988(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31988);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003C940:
    ctx->pc = 0x8003C940u;
    // 8003C940: extsb r5, r0
    {
        ctx->gpr[5] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8003C944:
    ctx->pc = 0x8003C944u;
    // 8003C944: bl      0x8025BBF4
    {
            ctx->lr = 0x8003C948u;
            ctx->pc = 0x8025BBF4u;
            return;
    }

label_8003C948:
    ctx->pc = 0x8003C948u;
    ctx->downcount -= 13;
    // 8003C948: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8003C94C:
    ctx->pc = 0x8003C94Cu;
    // 8003C94C: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003C950:
    ctx->pc = 0x8003C950u;
    // 8003C950: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8003C954:
    ctx->pc = 0x8003C954u;
    // 8003C954: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003C958:
    ctx->pc = 0x8003C958u;
    // 8003C958: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_8003C95C:
    ctx->pc = 0x8003C95Cu;
    // 8003C95C: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8003C960:
    ctx->pc = 0x8003C960u;
    // 8003C960: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003C964:
    ctx->pc = 0x8003C964u;
    // 8003C964: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_8003C968:
    ctx->pc = 0x8003C968u;
    // 8003C968: li      r7, 2
    ctx->gpr[7] = (u32)(s32)(2);

label_8003C96C:
    ctx->pc = 0x8003C96Cu;
    // 8003C96C: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8003C970:
    ctx->pc = 0x8003C970u;
    // 8003C970: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_8003C974:
    ctx->pc = 0x8003C974u;
    // 8003C974: li      r10, 1
    ctx->gpr[10] = (u32)(s32)(1);

label_8003C978:
    ctx->pc = 0x8003C978u;
    // 8003C978: bl      0x8025BB58
    {
            ctx->lr = 0x8003C97Cu;
            ctx->pc = 0x8025BB58u;
            return;
    }

label_8003C97C:
    ctx->pc = 0x8003C97Cu;
    ctx->downcount -= 6;
    // 8003C97C: lwz     r3, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003C980:
    ctx->pc = 0x8003C980u;
    // 8003C980: lwz     r0, -25924(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25924);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003C984:
    ctx->pc = 0x8003C984u;
    // 8003C984: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_8003C988:
    ctx->pc = 0x8003C988u;
    // 8003C988: lwzx    r3, r3, r0
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[0];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003C98C:
    ctx->pc = 0x8003C98Cu;
    // 8003C98C: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_8003C990:
    ctx->pc = 0x8003C990u;
    // 8003C990: bl      0x8004C4C8
    {
            ctx->lr = 0x8003C994u;
            ctx->pc = 0x8004C4C8u;
            return;
    }

label_8003C994:
    ctx->pc = 0x8003C994u;
    ctx->downcount -= 5;
    // 8003C994: addi    r3, r1, 316
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(316);

label_8003C998:
    ctx->pc = 0x8003C998u;
    // 8003C998: lfs     f1, -31432(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003C998u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31432);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003C99C:
    ctx->pc = 0x8003C99Cu;
    // 8003C99C: fmr    f2, f1
    if (!ppc_fp_available_inline(ctx, 0x8003C99Cu)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_8003C9A0:
    ctx->pc = 0x8003C9A0u;
    // 8003C9A0: lfs     f3, -31452(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003C9A0u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31452);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8003C9A4:
    ctx->pc = 0x8003C9A4u;
    // 8003C9A4: bl      0x80247CC4
    {
            ctx->lr = 0x8003C9A8u;
            ctx->pc = 0x80247CC4u;
            return;
    }

label_8003C9A8:
    ctx->pc = 0x8003C9A8u;
    ctx->downcount -= 4;
    // 8003C9A8: addi    r3, r1, 316
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(316);

label_8003C9AC:
    ctx->pc = 0x8003C9ACu;
    // 8003C9AC: li      r4, 64
    ctx->gpr[4] = (u32)(s32)(64);

label_8003C9B0:
    ctx->pc = 0x8003C9B0u;
    // 8003C9B0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003C9B4:
    ctx->pc = 0x8003C9B4u;
    // 8003C9B4: bl      0x8025DAD0
    {
            ctx->lr = 0x8003C9B8u;
            ctx->pc = 0x8025DAD0u;
            return;
    }

label_8003C9B8:
    ctx->pc = 0x8003C9B8u;
    ctx->downcount -= 7;
    // 8003C9B8: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_8003C9BC:
    ctx->pc = 0x8003C9BCu;
    // 8003C9BC: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8003C9C0:
    ctx->pc = 0x8003C9C0u;
    // 8003C9C0: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_8003C9C4:
    ctx->pc = 0x8003C9C4u;
    // 8003C9C4: li      r6, 60
    ctx->gpr[6] = (u32)(s32)(60);

label_8003C9C8:
    ctx->pc = 0x8003C9C8u;
    // 8003C9C8: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8003C9CC:
    ctx->pc = 0x8003C9CCu;
    // 8003C9CC: li      r8, 64
    ctx->gpr[8] = (u32)(s32)(64);

label_8003C9D0:
    ctx->pc = 0x8003C9D0u;
    // 8003C9D0: bl      0x80258880
    {
            ctx->lr = 0x8003C9D4u;
            ctx->pc = 0x80258880u;
            return;
    }

label_8003C9D4:
    ctx->pc = 0x8003C9D4u;
    ctx->downcount -= 3;
    // 8003C9D4: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_8003C9D8:
    ctx->pc = 0x8003C9D8u;
    // 8003C9D8: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_8003C9DC:
    ctx->pc = 0x8003C9DCu;
    // 8003C9DC: bl      0x8025C790
    {
            ctx->lr = 0x8003C9E0u;
            ctx->pc = 0x8025C790u;
            return;
    }

label_8003C9E0:
    ctx->pc = 0x8003C9E0u;
    ctx->downcount -= 5;
    // 8003C9E0: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_8003C9E4:
    ctx->pc = 0x8003C9E4u;
    // 8003C9E4: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_8003C9E8:
    ctx->pc = 0x8003C9E8u;
    // 8003C9E8: li      r5, 3
    ctx->gpr[5] = (u32)(s32)(3);

label_8003C9EC:
    ctx->pc = 0x8003C9ECu;
    // 8003C9EC: li      r6, 8
    ctx->gpr[6] = (u32)(s32)(8);

label_8003C9F0:
    ctx->pc = 0x8003C9F0u;
    // 8003C9F0: bl      0x8025CA34
    {
            ctx->lr = 0x8003C9F4u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_8003C9F4:
    ctx->pc = 0x8003C9F4u;
    ctx->downcount -= 6;
    // 8003C9F4: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_8003C9F8:
    ctx->pc = 0x8003C9F8u;
    // 8003C9F8: li      r4, 8
    ctx->gpr[4] = (u32)(s32)(8);

label_8003C9FC:
    ctx->pc = 0x8003C9FCu;
    // 8003C9FC: li      r5, 14
    ctx->gpr[5] = (u32)(s32)(14);

label_8003CA00:
    ctx->pc = 0x8003CA00u;
    // 8003CA00: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8003CA04:
    ctx->pc = 0x8003CA04u;
    // 8003CA04: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8003CA08:
    ctx->pc = 0x8003CA08u;
    // 8003CA08: bl      0x8025C3B0
    {
            ctx->lr = 0x8003CA0Cu;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_8003CA0C:
    ctx->pc = 0x8003CA0Cu;
    ctx->downcount -= 6;
    // 8003CA0C: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_8003CA10:
    ctx->pc = 0x8003CA10u;
    // 8003CA10: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_8003CA14:
    ctx->pc = 0x8003CA14u;
    // 8003CA14: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_8003CA18:
    ctx->pc = 0x8003CA18u;
    // 8003CA18: li      r6, 5
    ctx->gpr[6] = (u32)(s32)(5);

label_8003CA1C:
    ctx->pc = 0x8003CA1Cu;
    // 8003CA1C: li      r7, 7
    ctx->gpr[7] = (u32)(s32)(7);

label_8003CA20:
    ctx->pc = 0x8003CA20u;
    // 8003CA20: bl      0x8025C430
    {
            ctx->lr = 0x8003CA24u;
            ctx->pc = 0x8025C430u;
            return;
    }

label_8003CA24:
    ctx->pc = 0x8003CA24u;
    ctx->downcount -= 4;
    // 8003CA24: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_8003CA28:
    ctx->pc = 0x8003CA28u;
    // 8003CA28: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003CA2C:
    ctx->pc = 0x8003CA2Cu;
    // 8003CA2C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003CA30:
    ctx->pc = 0x8003CA30u;
    // 8003CA30: bl      0x8025C868
    {
            ctx->lr = 0x8003CA34u;
            ctx->pc = 0x8025C868u;
            return;
    }

label_8003CA34:
    ctx->pc = 0x8003CA34u;
    ctx->downcount -= 7;
    // 8003CA34: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_8003CA38:
    ctx->pc = 0x8003CA38u;
    // 8003CA38: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8003CA3C:
    ctx->pc = 0x8003CA3Cu;
    // 8003CA3C: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_8003CA40:
    ctx->pc = 0x8003CA40u;
    // 8003CA40: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8003CA44:
    ctx->pc = 0x8003CA44u;
    // 8003CA44: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8003CA48:
    ctx->pc = 0x8003CA48u;
    // 8003CA48: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8003CA4C:
    ctx->pc = 0x8003CA4Cu;
    // 8003CA4C: bl      0x8025C4B4
    {
            ctx->lr = 0x8003CA50u;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_8003CA50:
    ctx->pc = 0x8003CA50u;
    ctx->downcount -= 7;
    // 8003CA50: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_8003CA54:
    ctx->pc = 0x8003CA54u;
    // 8003CA54: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003CA58:
    ctx->pc = 0x8003CA58u;
    // 8003CA58: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003CA5C:
    ctx->pc = 0x8003CA5Cu;
    // 8003CA5C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8003CA60:
    ctx->pc = 0x8003CA60u;
    // 8003CA60: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8003CA64:
    ctx->pc = 0x8003CA64u;
    // 8003CA64: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8003CA68:
    ctx->pc = 0x8003CA68u;
    // 8003CA68: bl      0x8025C574
    {
            ctx->lr = 0x8003CA6Cu;
            ctx->pc = 0x8025C574u;
            return;
    }

label_8003CA6C:
    ctx->pc = 0x8003CA6Cu;
    ctx->downcount -= 3;
    // 8003CA6C: lwz     r0, -25924(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25924);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003CA70:
    ctx->pc = 0x8003CA70u;
    // 8003CA70: cmpwi   r0, 12
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(12);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003CA74:
    ctx->pc = 0x8003CA74u;
    // 8003CA74: bc    4, 0, 0x8003CA94
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003CA94;
        }
    }

label_8003CA78:
    ctx->pc = 0x8003CA78u;
    ctx->downcount -= 2;
    // 8003CA78: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_8003CA7C:
    ctx->pc = 0x8003CA7Cu;
    // 8003CA7C: bl      0x8025CC10
    {
            ctx->lr = 0x8003CA80u;
            ctx->pc = 0x8025CC10u;
            return;
    }

label_8003CA80:
    ctx->pc = 0x8003CA80u;
    ctx->downcount -= 2;
    // 8003CA80: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003CA84:
    ctx->pc = 0x8003CA84u;
    // 8003CA84: bl      0x8025C060
    {
            ctx->lr = 0x8003CA88u;
            ctx->pc = 0x8025C060u;
            return;
    }

label_8003CA88:
    ctx->pc = 0x8003CA88u;
    ctx->downcount -= 2;
    // 8003CA88: li      r3, 5
    ctx->gpr[3] = (u32)(s32)(5);

label_8003CA8C:
    ctx->pc = 0x8003CA8Cu;
    // 8003CA8C: bl      0x80258B50
    {
            ctx->lr = 0x8003CA90u;
            ctx->pc = 0x80258B50u;
            return;
    }

label_8003CA90:
    ctx->pc = 0x8003CA90u;
    ctx->downcount -= 1;
    // 8003CA90: b       0x8003CD2C
    {
            goto label_8003CD2C;
    }

label_8003CA94:
    ctx->pc = 0x8003CA94u;
    ctx->downcount -= 5;
    // 8003CA94: lwz     r0, -31480(r2)
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31480);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003CA98:
    ctx->pc = 0x8003CA98u;
    // 8003CA98: stw     r0, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003CA9C:
    ctx->pc = 0x8003CA9Cu;
    // 8003CA9C: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8003CAA0:
    ctx->pc = 0x8003CAA0u;
    // 8003CAA0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003CAA4:
    ctx->pc = 0x8003CAA4u;
    // 8003CAA4: bl      0x8001F63C
    {
            ctx->lr = 0x8003CAA8u;
            ctx->pc = 0x8001F63Cu;
            return;
    }

label_8003CAA8:
    ctx->pc = 0x8003CAA8u;
    ctx->downcount -= 3;
    // 8003CAA8: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003CAAC:
    ctx->pc = 0x8003CAACu;
    // 8003CAAC: cmplwi  r28, 0x0000
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

label_8003CAB0:
    ctx->pc = 0x8003CAB0u;
    // 8003CAB0: bc    12, 2, 0x8003CB44
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003CB44;
        }
    }

label_8003CAB4:
    ctx->pc = 0x8003CAB4u;
    ctx->downcount -= 2;
    // 8003CAB4: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_8003CAB8:
    ctx->pc = 0x8003CAB8u;
    // 8003CAB8: bl      0x8001DCA0
    {
            ctx->lr = 0x8003CABCu;
            ctx->pc = 0x8001DCA0u;
            return;
    }

label_8003CABC:
    ctx->pc = 0x8003CABCu;
    ctx->downcount -= 5;
    // 8003CABC: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8003CAC0:
    ctx->pc = 0x8003CAC0u;
    // 8003CAC0: lfs     f1, -31476(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003CAC0u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31476);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003CAC4:
    ctx->pc = 0x8003CAC4u;
    // 8003CAC4: lfs     f2, -31428(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003CAC4u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31428);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8003CAC8:
    ctx->pc = 0x8003CAC8u;
    // 8003CAC8: fmr    f3, f1
    if (!ppc_fp_available_inline(ctx, 0x8003CAC8u)) return;
    ctx->fpr[3] = ctx->fpr[1];

label_8003CACC:
    ctx->pc = 0x8003CACCu;
    // 8003CACC: bl      0x8001DE04
    {
            ctx->lr = 0x8003CAD0u;
            ctx->pc = 0x8001DE04u;
            return;
    }

label_8003CAD0:
    ctx->pc = 0x8003CAD0u;
    ctx->downcount -= 6;
    // 8003CAD0: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8003CAD4:
    ctx->pc = 0x8003CAD4u;
    // 8003CAD4: li      r4, 255
    ctx->gpr[4] = (u32)(s32)(255);

label_8003CAD8:
    ctx->pc = 0x8003CAD8u;
    // 8003CAD8: li      r5, 255
    ctx->gpr[5] = (u32)(s32)(255);

label_8003CADC:
    ctx->pc = 0x8003CADCu;
    // 8003CADC: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_8003CAE0:
    ctx->pc = 0x8003CAE0u;
    // 8003CAE0: li      r7, 255
    ctx->gpr[7] = (u32)(s32)(255);

label_8003CAE4:
    ctx->pc = 0x8003CAE4u;
    // 8003CAE4: bl      0x8001DC64
    {
            ctx->lr = 0x8003CAE8u;
            ctx->pc = 0x8001DC64u;
            return;
    }

label_8003CAE8:
    ctx->pc = 0x8003CAE8u;
    ctx->downcount -= 2;
    // 8003CAE8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003CAEC:
    ctx->pc = 0x8003CAECu;
    // 8003CAEC: bl      0x8001EA68
    {
            ctx->lr = 0x8003CAF0u;
            ctx->pc = 0x8001EA68u;
            return;
    }

label_8003CAF0:
    ctx->pc = 0x8003CAF0u;
    ctx->downcount -= 4;
    // 8003CAF0: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003CAF4:
    ctx->pc = 0x8003CAF4u;
    // 8003CAF4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003CAF8:
    ctx->pc = 0x8003CAF8u;
    // 8003CAF8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003CAFC:
    ctx->pc = 0x8003CAFCu;
    // 8003CAFC: bl      0x8001E77C
    {
            ctx->lr = 0x8003CB00u;
            ctx->pc = 0x8001E77Cu;
            return;
    }

label_8003CB00:
    ctx->pc = 0x8003CB00u;
    ctx->downcount -= 5;
    // 8003CB00: lwz     r0, -32032(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32032);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003CB04:
    ctx->pc = 0x8003CB04u;
    // 8003CB04: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003CB08:
    ctx->pc = 0x8003CB08u;
    // 8003CB08: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003CB0C:
    ctx->pc = 0x8003CB0Cu;
    // 8003CB0C: addi    r4, r1, 28
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(28);

label_8003CB10:
    ctx->pc = 0x8003CB10u;
    // 8003CB10: bl      0x8025A4F8
    {
            ctx->lr = 0x8003CB14u;
            ctx->pc = 0x8025A4F8u;
            return;
    }

label_8003CB14:
    ctx->pc = 0x8003CB14u;
    ctx->downcount -= 5;
    // 8003CB14: lwz     r0, -32040(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32040);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003CB18:
    ctx->pc = 0x8003CB18u;
    // 8003CB18: stw     r0, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003CB1C:
    ctx->pc = 0x8003CB1Cu;
    // 8003CB1C: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003CB20:
    ctx->pc = 0x8003CB20u;
    // 8003CB20: addi    r4, r1, 24
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(24);

label_8003CB24:
    ctx->pc = 0x8003CB24u;
    // 8003CB24: bl      0x8025A660
    {
            ctx->lr = 0x8003CB28u;
            ctx->pc = 0x8025A660u;
            return;
    }

label_8003CB28:
    ctx->pc = 0x8003CB28u;
    ctx->downcount -= 4;
    // 8003CB28: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003CB2C:
    ctx->pc = 0x8003CB2Cu;
    // 8003CB2C: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8003CB30:
    ctx->pc = 0x8003CB30u;
    // 8003CB30: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8003CB34:
    ctx->pc = 0x8003CB34u;
    // 8003CB34: bl      0x8001E618
    {
            ctx->lr = 0x8003CB38u;
            ctx->pc = 0x8001E618u;
            return;
    }

label_8003CB38:
    ctx->pc = 0x8003CB38u;
    ctx->downcount -= 1;
    // 8003CB38: bl      0x8001E7A8
    {
            ctx->lr = 0x8003CB3Cu;
            ctx->pc = 0x8001E7A8u;
            return;
    }

label_8003CB3C:
    ctx->pc = 0x8003CB3Cu;
    ctx->downcount -= 2;
    // 8003CB3C: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8003CB40:
    ctx->pc = 0x8003CB40u;
    // 8003CB40: bl      0x8001F4F8
    {
            ctx->lr = 0x8003CB44u;
            ctx->pc = 0x8001F4F8u;
            return;
    }

label_8003CB44:
    ctx->pc = 0x8003CB44u;
    ctx->downcount -= 5;
    // 8003CB44: lwz     r0, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003CB48:
    ctx->pc = 0x8003CB48u;
    // 8003CB48: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003CB4C:
    ctx->pc = 0x8003CB4Cu;
    // 8003CB4C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003CB50:
    ctx->pc = 0x8003CB50u;
    // 8003CB50: addi    r4, r1, 20
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(20);

label_8003CB54:
    ctx->pc = 0x8003CB54u;
    // 8003CB54: bl      0x8025C71C
    {
            ctx->lr = 0x8003CB58u;
            ctx->pc = 0x8025C71Cu;
            return;
    }

label_8003CB58:
    ctx->pc = 0x8003CB58u;
    ctx->downcount -= 3;
    // 8003CB58: li      r3, 5
    ctx->gpr[3] = (u32)(s32)(5);

label_8003CB5C:
    ctx->pc = 0x8003CB5Cu;
    // 8003CB5C: li      r4, 28
    ctx->gpr[4] = (u32)(s32)(28);

label_8003CB60:
    ctx->pc = 0x8003CB60u;
    // 8003CB60: bl      0x8025C7FC
    {
            ctx->lr = 0x8003CB64u;
            ctx->pc = 0x8025C7FCu;
            return;
    }

label_8003CB64:
    ctx->pc = 0x8003CB64u;
    ctx->downcount -= 3;
    // 8003CB64: li      r3, 5
    ctx->gpr[3] = (u32)(s32)(5);

label_8003CB68:
    ctx->pc = 0x8003CB68u;
    // 8003CB68: li      r4, 12
    ctx->gpr[4] = (u32)(s32)(12);

label_8003CB6C:
    ctx->pc = 0x8003CB6Cu;
    // 8003CB6C: bl      0x8025C790
    {
            ctx->lr = 0x8003CB70u;
            ctx->pc = 0x8025C790u;
            return;
    }

label_8003CB70:
    ctx->pc = 0x8003CB70u;
    ctx->downcount -= 4;
    // 8003CB70: addi    r3, r1, 44
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(44);

label_8003CB74:
    ctx->pc = 0x8003CB74u;
    // 8003CB74: addi    r4, r1, 40
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(40);

label_8003CB78:
    ctx->pc = 0x8003CB78u;
    // 8003CB78: addi    r5, r1, 36
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(36);

label_8003CB7C:
    ctx->pc = 0x8003CB7Cu;
    // 8003CB7C: bl      0x8006C6A4
    {
            ctx->lr = 0x8003CB80u;
            ctx->pc = 0x8006C6A4u;
            return;
    }

label_8003CB80:
    ctx->pc = 0x8003CB80u;
    ctx->downcount -= 15;
    // 8003CB80: lwz     r5, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8003CB84:
    ctx->pc = 0x8003CB84u;
    // 8003CB84: lwz     r4, -25924(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25924);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8003CB88:
    ctx->pc = 0x8003CB88u;
    // 8003CB88: lbz     r3, -25931(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25931);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8003CB8C:
    ctx->pc = 0x8003CB8Cu;
    // 8003CB8C: lwz     r0, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003CB90:
    ctx->pc = 0x8003CB90u;
    // 8003CB90: mullw   r0, r3, r0
    {
        s64 product = (s64)(s32)ctx->gpr[3] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[0] = (u32)product;
    }

label_8003CB94:
    ctx->pc = 0x8003CB94u;
    // 8003CB94: add   r3, r4, r0
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8003CB98:
    ctx->pc = 0x8003CB98u;
    // 8003CB98: addi    r0, r3, -12
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-12);

label_8003CB9C:
    ctx->pc = 0x8003CB9Cu;
    // 8003CB9C: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_8003CBA0:
    ctx->pc = 0x8003CBA0u;
    // 8003CBA0: lwzx    r3, r5, r0
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[0];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003CBA4:
    ctx->pc = 0x8003CBA4u;
    // 8003CBA4: li      r4, 5
    ctx->gpr[4] = (u32)(s32)(5);

label_8003CBA8:
    ctx->pc = 0x8003CBA8u;
    // 8003CBA8: bl      0x8004C4C8
    {
            ctx->lr = 0x8003CBACu;
            ctx->pc = 0x8004C4C8u;
            return;
    }

label_8003CBAC:
    ctx->pc = 0x8003CBACu;
    ctx->downcount -= 5;
    // 8003CBAC: addi    r3, r1, 124
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(124);

label_8003CBB0:
    ctx->pc = 0x8003CBB0u;
    // 8003CBB0: lfs     f1, -31424(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003CBB0u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31424);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003CBB4:
    ctx->pc = 0x8003CBB4u;
    // 8003CBB4: fmr    f2, f1
    if (!ppc_fp_available_inline(ctx, 0x8003CBB4u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_8003CBB8:
    ctx->pc = 0x8003CBB8u;
    // 8003CBB8: lfs     f3, -31452(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003CBB8u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31452);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8003CBBC:
    ctx->pc = 0x8003CBBCu;
    // 8003CBBC: bl      0x80247CC4
    {
            ctx->lr = 0x8003CBC0u;
            ctx->pc = 0x80247CC4u;
            return;
    }

label_8003CBC0:
    ctx->pc = 0x8003CBC0u;
    ctx->downcount -= 4;
    // 8003CBC0: addi    r3, r1, 124
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(124);

label_8003CBC4:
    ctx->pc = 0x8003CBC4u;
    // 8003CBC4: li      r4, 73
    ctx->gpr[4] = (u32)(s32)(73);

label_8003CBC8:
    ctx->pc = 0x8003CBC8u;
    // 8003CBC8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003CBCC:
    ctx->pc = 0x8003CBCCu;
    // 8003CBCC: bl      0x8025DAD0
    {
            ctx->lr = 0x8003CBD0u;
            ctx->pc = 0x8025DAD0u;
            return;
    }

label_8003CBD0:
    ctx->pc = 0x8003CBD0u;
    ctx->downcount -= 7;
    // 8003CBD0: li      r3, 5
    ctx->gpr[3] = (u32)(s32)(5);

label_8003CBD4:
    ctx->pc = 0x8003CBD4u;
    // 8003CBD4: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8003CBD8:
    ctx->pc = 0x8003CBD8u;
    // 8003CBD8: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_8003CBDC:
    ctx->pc = 0x8003CBDCu;
    // 8003CBDC: li      r6, 60
    ctx->gpr[6] = (u32)(s32)(60);

label_8003CBE0:
    ctx->pc = 0x8003CBE0u;
    // 8003CBE0: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8003CBE4:
    ctx->pc = 0x8003CBE4u;
    // 8003CBE4: li      r8, 73
    ctx->gpr[8] = (u32)(s32)(73);

label_8003CBE8:
    ctx->pc = 0x8003CBE8u;
    // 8003CBE8: bl      0x80258880
    {
            ctx->lr = 0x8003CBECu;
            ctx->pc = 0x80258880u;
            return;
    }

label_8003CBEC:
    ctx->pc = 0x8003CBECu;
    ctx->downcount -= 2;
    // 8003CBEC: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_8003CBF0:
    ctx->pc = 0x8003CBF0u;
    // 8003CBF0: bl      0x8025C08C
    {
            ctx->lr = 0x8003CBF4u;
            ctx->pc = 0x8025C08Cu;
            return;
    }

label_8003CBF4:
    ctx->pc = 0x8003CBF4u;
    ctx->downcount -= 5;
    // 8003CBF4: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_8003CBF8:
    ctx->pc = 0x8003CBF8u;
    // 8003CBF8: li      r4, 5
    ctx->gpr[4] = (u32)(s32)(5);

label_8003CBFC:
    ctx->pc = 0x8003CBFCu;
    // 8003CBFC: li      r5, 5
    ctx->gpr[5] = (u32)(s32)(5);

label_8003CC00:
    ctx->pc = 0x8003CC00u;
    // 8003CC00: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_8003CC04:
    ctx->pc = 0x8003CC04u;
    // 8003CC04: bl      0x8025CA34
    {
            ctx->lr = 0x8003CC08u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_8003CC08:
    ctx->pc = 0x8003CC08u;
    ctx->downcount -= 6;
    // 8003CC08: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_8003CC0C:
    ctx->pc = 0x8003CC0Cu;
    // 8003CC0C: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_8003CC10:
    ctx->pc = 0x8003CC10u;
    // 8003CC10: li      r5, 15
    ctx->gpr[5] = (u32)(s32)(15);

label_8003CC14:
    ctx->pc = 0x8003CC14u;
    // 8003CC14: li      r6, 15
    ctx->gpr[6] = (u32)(s32)(15);

label_8003CC18:
    ctx->pc = 0x8003CC18u;
    // 8003CC18: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8003CC1C:
    ctx->pc = 0x8003CC1Cu;
    // 8003CC1C: bl      0x8025C3B0
    {
            ctx->lr = 0x8003CC20u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_8003CC20:
    ctx->pc = 0x8003CC20u;
    ctx->downcount -= 6;
    // 8003CC20: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_8003CC24:
    ctx->pc = 0x8003CC24u;
    // 8003CC24: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_8003CC28:
    ctx->pc = 0x8003CC28u;
    // 8003CC28: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_8003CC2C:
    ctx->pc = 0x8003CC2Cu;
    // 8003CC2C: li      r6, 5
    ctx->gpr[6] = (u32)(s32)(5);

label_8003CC30:
    ctx->pc = 0x8003CC30u;
    // 8003CC30: li      r7, 7
    ctx->gpr[7] = (u32)(s32)(7);

label_8003CC34:
    ctx->pc = 0x8003CC34u;
    // 8003CC34: bl      0x8025C430
    {
            ctx->lr = 0x8003CC38u;
            ctx->pc = 0x8025C430u;
            return;
    }

label_8003CC38:
    ctx->pc = 0x8003CC38u;
    ctx->downcount -= 4;
    // 8003CC38: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_8003CC3C:
    ctx->pc = 0x8003CC3Cu;
    // 8003CC3C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003CC40:
    ctx->pc = 0x8003CC40u;
    // 8003CC40: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003CC44:
    ctx->pc = 0x8003CC44u;
    // 8003CC44: bl      0x8025C868
    {
            ctx->lr = 0x8003CC48u;
            ctx->pc = 0x8025C868u;
            return;
    }

label_8003CC48:
    ctx->pc = 0x8003CC48u;
    ctx->downcount -= 7;
    // 8003CC48: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_8003CC4C:
    ctx->pc = 0x8003CC4Cu;
    // 8003CC4C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003CC50:
    ctx->pc = 0x8003CC50u;
    // 8003CC50: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003CC54:
    ctx->pc = 0x8003CC54u;
    // 8003CC54: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8003CC58:
    ctx->pc = 0x8003CC58u;
    // 8003CC58: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8003CC5C:
    ctx->pc = 0x8003CC5Cu;
    // 8003CC5C: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8003CC60:
    ctx->pc = 0x8003CC60u;
    // 8003CC60: bl      0x8025C4B4
    {
            ctx->lr = 0x8003CC64u;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_8003CC64:
    ctx->pc = 0x8003CC64u;
    ctx->downcount -= 7;
    // 8003CC64: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_8003CC68:
    ctx->pc = 0x8003CC68u;
    // 8003CC68: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003CC6C:
    ctx->pc = 0x8003CC6Cu;
    // 8003CC6C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003CC70:
    ctx->pc = 0x8003CC70u;
    // 8003CC70: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8003CC74:
    ctx->pc = 0x8003CC74u;
    // 8003CC74: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8003CC78:
    ctx->pc = 0x8003CC78u;
    // 8003CC78: li      r8, 2
    ctx->gpr[8] = (u32)(s32)(2);

label_8003CC7C:
    ctx->pc = 0x8003CC7Cu;
    // 8003CC7C: bl      0x8025C574
    {
            ctx->lr = 0x8003CC80u;
            ctx->pc = 0x8025C574u;
            return;
    }

label_8003CC80:
    ctx->pc = 0x8003CC80u;
    ctx->downcount -= 2;
    // 8003CC80: li      r3, 5
    ctx->gpr[3] = (u32)(s32)(5);

label_8003CC84:
    ctx->pc = 0x8003CC84u;
    // 8003CC84: bl      0x8025C08C
    {
            ctx->lr = 0x8003CC88u;
            ctx->pc = 0x8025C08Cu;
            return;
    }

label_8003CC88:
    ctx->pc = 0x8003CC88u;
    ctx->downcount -= 5;
    // 8003CC88: li      r3, 5
    ctx->gpr[3] = (u32)(s32)(5);

label_8003CC8C:
    ctx->pc = 0x8003CC8Cu;
    // 8003CC8C: li      r4, 255
    ctx->gpr[4] = (u32)(s32)(255);

label_8003CC90:
    ctx->pc = 0x8003CC90u;
    // 8003CC90: li      r5, 255
    ctx->gpr[5] = (u32)(s32)(255);

label_8003CC94:
    ctx->pc = 0x8003CC94u;
    // 8003CC94: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_8003CC98:
    ctx->pc = 0x8003CC98u;
    // 8003CC98: bl      0x8025CA34
    {
            ctx->lr = 0x8003CC9Cu;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_8003CC9C:
    ctx->pc = 0x8003CC9Cu;
    ctx->downcount -= 6;
    // 8003CC9C: li      r3, 5
    ctx->gpr[3] = (u32)(s32)(5);

label_8003CCA0:
    ctx->pc = 0x8003CCA0u;
    // 8003CCA0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003CCA4:
    ctx->pc = 0x8003CCA4u;
    // 8003CCA4: li      r5, 14
    ctx->gpr[5] = (u32)(s32)(14);

label_8003CCA8:
    ctx->pc = 0x8003CCA8u;
    // 8003CCA8: li      r6, 5
    ctx->gpr[6] = (u32)(s32)(5);

label_8003CCAC:
    ctx->pc = 0x8003CCACu;
    // 8003CCAC: li      r7, 15
    ctx->gpr[7] = (u32)(s32)(15);

label_8003CCB0:
    ctx->pc = 0x8003CCB0u;
    // 8003CCB0: bl      0x8025C3B0
    {
            ctx->lr = 0x8003CCB4u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_8003CCB4:
    ctx->pc = 0x8003CCB4u;
    ctx->downcount -= 6;
    // 8003CCB4: li      r3, 5
    ctx->gpr[3] = (u32)(s32)(5);

label_8003CCB8:
    ctx->pc = 0x8003CCB8u;
    // 8003CCB8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003CCBC:
    ctx->pc = 0x8003CCBCu;
    // 8003CCBC: li      r5, 2
    ctx->gpr[5] = (u32)(s32)(2);

label_8003CCC0:
    ctx->pc = 0x8003CCC0u;
    // 8003CCC0: li      r6, 2
    ctx->gpr[6] = (u32)(s32)(2);

label_8003CCC4:
    ctx->pc = 0x8003CCC4u;
    // 8003CCC4: li      r7, 7
    ctx->gpr[7] = (u32)(s32)(7);

label_8003CCC8:
    ctx->pc = 0x8003CCC8u;
    // 8003CCC8: bl      0x8025C430
    {
            ctx->lr = 0x8003CCCCu;
            ctx->pc = 0x8025C430u;
            return;
    }

label_8003CCCC:
    ctx->pc = 0x8003CCCCu;
    ctx->downcount -= 4;
    // 8003CCCC: li      r3, 5
    ctx->gpr[3] = (u32)(s32)(5);

label_8003CCD0:
    ctx->pc = 0x8003CCD0u;
    // 8003CCD0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003CCD4:
    ctx->pc = 0x8003CCD4u;
    // 8003CCD4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003CCD8:
    ctx->pc = 0x8003CCD8u;
    // 8003CCD8: bl      0x8025C868
    {
            ctx->lr = 0x8003CCDCu;
            ctx->pc = 0x8025C868u;
            return;
    }

label_8003CCDC:
    ctx->pc = 0x8003CCDCu;
    ctx->downcount -= 7;
    // 8003CCDC: li      r3, 5
    ctx->gpr[3] = (u32)(s32)(5);

label_8003CCE0:
    ctx->pc = 0x8003CCE0u;
    // 8003CCE0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003CCE4:
    ctx->pc = 0x8003CCE4u;
    // 8003CCE4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003CCE8:
    ctx->pc = 0x8003CCE8u;
    // 8003CCE8: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8003CCEC:
    ctx->pc = 0x8003CCECu;
    // 8003CCEC: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8003CCF0:
    ctx->pc = 0x8003CCF0u;
    // 8003CCF0: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8003CCF4:
    ctx->pc = 0x8003CCF4u;
    // 8003CCF4: bl      0x8025C4B4
    {
            ctx->lr = 0x8003CCF8u;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_8003CCF8:
    ctx->pc = 0x8003CCF8u;
    ctx->downcount -= 7;
    // 8003CCF8: li      r3, 5
    ctx->gpr[3] = (u32)(s32)(5);

label_8003CCFC:
    ctx->pc = 0x8003CCFCu;
    // 8003CCFC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003CD00:
    ctx->pc = 0x8003CD00u;
    // 8003CD00: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003CD04:
    ctx->pc = 0x8003CD04u;
    // 8003CD04: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8003CD08:
    ctx->pc = 0x8003CD08u;
    // 8003CD08: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8003CD0C:
    ctx->pc = 0x8003CD0Cu;
    // 8003CD0C: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8003CD10:
    ctx->pc = 0x8003CD10u;
    // 8003CD10: bl      0x8025C574
    {
            ctx->lr = 0x8003CD14u;
            ctx->pc = 0x8025C574u;
            return;
    }

label_8003CD14:
    ctx->pc = 0x8003CD14u;
    ctx->downcount -= 2;
    // 8003CD14: li      r3, 6
    ctx->gpr[3] = (u32)(s32)(6);

label_8003CD18:
    ctx->pc = 0x8003CD18u;
    // 8003CD18: bl      0x8025CC10
    {
            ctx->lr = 0x8003CD1Cu;
            ctx->pc = 0x8025CC10u;
            return;
    }

label_8003CD1C:
    ctx->pc = 0x8003CD1Cu;
    ctx->downcount -= 2;
    // 8003CD1C: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003CD20:
    ctx->pc = 0x8003CD20u;
    // 8003CD20: bl      0x8025C060
    {
            ctx->lr = 0x8003CD24u;
            ctx->pc = 0x8025C060u;
            return;
    }

label_8003CD24:
    ctx->pc = 0x8003CD24u;
    ctx->downcount -= 2;
    // 8003CD24: li      r3, 6
    ctx->gpr[3] = (u32)(s32)(6);

label_8003CD28:
    ctx->pc = 0x8003CD28u;
    // 8003CD28: bl      0x80258B50
    {
            ctx->lr = 0x8003CD2Cu;
            ctx->pc = 0x80258B50u;
            return;
    }

label_8003CD2C:
    ctx->pc = 0x8003CD2Cu;
    ctx->downcount -= 2;
    // 8003CD2C: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003CD30:
    ctx->pc = 0x8003CD30u;
    // 8003CD30: bl      0x80259494
    {
            ctx->lr = 0x8003CD34u;
            ctx->pc = 0x80259494u;
            return;
    }

label_8003CD34:
    ctx->pc = 0x8003CD34u;
    ctx->downcount -= 9;
    // 8003CD34: lwz     r0, -32040(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32040);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003CD38:
    ctx->pc = 0x8003CD38u;
    // 8003CD38: stw     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003CD3C:
    ctx->pc = 0x8003CD3Cu;
    // 8003CD3C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003CD40:
    ctx->pc = 0x8003CD40u;
    // 8003CD40: lfs     f1, -31476(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003CD40u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31476);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003CD44:
    ctx->pc = 0x8003CD44u;
    // 8003CD44: fmr    f2, f1
    if (!ppc_fp_available_inline(ctx, 0x8003CD44u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_8003CD48:
    ctx->pc = 0x8003CD48u;
    // 8003CD48: fmr    f3, f1
    if (!ppc_fp_available_inline(ctx, 0x8003CD48u)) return;
    ctx->fpr[3] = ctx->fpr[1];

label_8003CD4C:
    ctx->pc = 0x8003CD4Cu;
    // 8003CD4C: fmr    f4, f1
    if (!ppc_fp_available_inline(ctx, 0x8003CD4Cu)) return;
    ctx->fpr[4] = ctx->fpr[1];

label_8003CD50:
    ctx->pc = 0x8003CD50u;
    // 8003CD50: addi    r4, r1, 16
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(16);

label_8003CD54:
    ctx->pc = 0x8003CD54u;
    // 8003CD54: bl      0x8025CC44
    {
            ctx->lr = 0x8003CD58u;
            ctx->pc = 0x8025CC44u;
            return;
    }

label_8003CD58:
    ctx->pc = 0x8003CD58u;
    ctx->downcount -= 4;
    // 8003CD58: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003CD5C:
    ctx->pc = 0x8003CD5Cu;
    // 8003CD5C: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_8003CD60:
    ctx->pc = 0x8003CD60u;
    // 8003CD60: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003CD64:
    ctx->pc = 0x8003CD64u;
    // 8003CD64: bl      0x800704F4
    {
            ctx->lr = 0x8003CD68u;
            ctx->pc = 0x800704F4u;
            return;
    }

label_8003CD68:
    ctx->pc = 0x8003CD68u;
    ctx->downcount -= 2;
    // 8003CD68: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003CD6C:
    ctx->pc = 0x8003CD6Cu;
    // 8003CD6C: bl      0x8007049C
    {
            ctx->lr = 0x8003CD70u;
            ctx->pc = 0x8007049Cu;
            return;
    }

label_8003CD70:
    ctx->pc = 0x8003CD70u;
    ctx->downcount -= 5;
    // 8003CD70: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003CD74:
    ctx->pc = 0x8003CD74u;
    // 8003CD74: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_8003CD78:
    ctx->pc = 0x8003CD78u;
    // 8003CD78: li      r5, 5
    ctx->gpr[5] = (u32)(s32)(5);

label_8003CD7C:
    ctx->pc = 0x8003CD7Cu;
    // 8003CD7C: li      r6, 5
    ctx->gpr[6] = (u32)(s32)(5);

label_8003CD80:
    ctx->pc = 0x8003CD80u;
    // 8003CD80: bl      0x8025CEF4
    {
            ctx->lr = 0x8003CD84u;
            ctx->pc = 0x8025CEF4u;
            return;
    }

label_8003CD84:
    ctx->pc = 0x8003CD84u;
    ctx->downcount -= 1;
    // 8003CD84: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003CD88:
    ctx->pc = 0x8003CD88u;
    ctx->downcount -= 11;
    // 8003CD88: psq_l   f31, 408(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8003CD88u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(408);
        ppc_psq_load_inline(ctx, 31u, ea, false, 0u, false, 0x8003CD88u);
        if (ctx->exception) return;
    }

label_8003CD8C:
    ctx->pc = 0x8003CD8Cu;
    // 8003CD8C: lfd     f31, 400(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003CD8Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(400);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003CD90:
    ctx->pc = 0x8003CD90u;
    // 8003CD90: lwz     r31, 396(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(396);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8003CD94:
    ctx->pc = 0x8003CD94u;
    // 8003CD94: lwz     r30, 392(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(392);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8003CD98:
    ctx->pc = 0x8003CD98u;
    // 8003CD98: lwz     r29, 388(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(388);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_8003CD9C:
    ctx->pc = 0x8003CD9Cu;
    // 8003CD9C: lwz     r28, 384(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(384);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_8003CDA0:
    ctx->pc = 0x8003CDA0u;
    // 8003CDA0: lwz     r0, 420(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(420);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003CDA4:
    ctx->pc = 0x8003CDA4u;
    // 8003CDA4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8003CDA8:
    ctx->pc = 0x8003CDA8u;
    // 8003CDA8: addi    r1, r1, 416
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(416);

label_8003CDAC:
    ctx->pc = 0x8003CDACu;
    // 8003CDAC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8003A6E0;
        }
    }

label_8003CDB0:
    ctx->pc = 0x8003CDB0u;
    ctx->downcount -= 7;
    // 8003CDB0: stwu     r1, -384(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-384);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8003CDB4:
    ctx->pc = 0x8003CDB4u;
    // 8003CDB4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8003CDB8:
    ctx->pc = 0x8003CDB8u;
    // 8003CDB8: stw     r0, 388(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(388);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003CDBC:
    ctx->pc = 0x8003CDBCu;
    // 8003CDBC: stfd     f31, 368(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003CDBCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(368);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_8003CDC0:
    ctx->pc = 0x8003CDC0u;
    // 8003CDC0: psq_st   f31, 376(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8003CDC0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(376);
        ppc_psq_store_inline(ctx, 31u, ea, false, 0u, false, 0x8003CDC0u);
        if (ctx->exception) return;
    }

label_8003CDC4:
    ctx->pc = 0x8003CDC4u;
    // 8003CDC4: addi    r11, r1, 368
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(368);

label_8003CDC8:
    ctx->pc = 0x8003CDC8u;
    // 8003CDC8: bl      0x80286A4C
    {
            ctx->lr = 0x8003CDCCu;
            ctx->pc = 0x80286A4Cu;
            return;
    }

label_8003CDCC:
    ctx->pc = 0x8003CDCCu;
    ctx->downcount -= 38;
    // 8003CDCC: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003CDD0:
    ctx->pc = 0x8003CDD0u;
    // 8003CDD0: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8003CDD4:
    ctx->pc = 0x8003CDD4u;
    // 8003CDD4: or   r30, r5, r5
    {
        ctx->gpr[30] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8003CDD8:
    ctx->pc = 0x8003CDD8u;
    // 8003CDD8: lwz     r3, -31492(r2)
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31492);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003CDDC:
    ctx->pc = 0x8003CDDCu;
    // 8003CDDC: lwz     r0, -31488(r2)
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31488);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003CDE0:
    ctx->pc = 0x8003CDE0u;
    // 8003CDE0: stw     r3, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8003CDE4:
    ctx->pc = 0x8003CDE4u;
    // 8003CDE4: stw     r0, 72(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003CDE8:
    ctx->pc = 0x8003CDE8u;
    // 8003CDE8: lis     r3, -32724
    ctx->gpr[3] = ((u32)(s32)(-32724) << 16);

label_8003CDEC:
    ctx->pc = 0x8003CDECu;
    // 8003CDEC: addi    r4, r3, 9360
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(9360);

label_8003CDF0:
    ctx->pc = 0x8003CDF0u;
    // 8003CDF0: lwz     r3, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003CDF4:
    ctx->pc = 0x8003CDF4u;
    // 8003CDF4: lwz     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003CDF8:
    ctx->pc = 0x8003CDF8u;
    // 8003CDF8: stw     r3, 100(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(100);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8003CDFC:
    ctx->pc = 0x8003CDFCu;
    // 8003CDFC: stw     r0, 104(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003CE00:
    ctx->pc = 0x8003CE00u;
    // 8003CE00: lwz     r3, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003CE04:
    ctx->pc = 0x8003CE04u;
    // 8003CE04: lwz     r0, 12(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003CE08:
    ctx->pc = 0x8003CE08u;
    // 8003CE08: stw     r3, 108(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(108);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8003CE0C:
    ctx->pc = 0x8003CE0Cu;
    // 8003CE0C: stw     r0, 112(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(112);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003CE10:
    ctx->pc = 0x8003CE10u;
    // 8003CE10: lwz     r3, 16(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003CE14:
    ctx->pc = 0x8003CE14u;
    // 8003CE14: lwz     r0, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003CE18:
    ctx->pc = 0x8003CE18u;
    // 8003CE18: stw     r3, 116(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(116);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8003CE1C:
    ctx->pc = 0x8003CE1Cu;
    // 8003CE1C: stw     r0, 120(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(120);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003CE20:
    ctx->pc = 0x8003CE20u;
    // 8003CE20: lis     r3, -32724
    ctx->gpr[3] = ((u32)(s32)(-32724) << 16);

label_8003CE24:
    ctx->pc = 0x8003CE24u;
    // 8003CE24: addi    r4, r3, 9384
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(9384);

label_8003CE28:
    ctx->pc = 0x8003CE28u;
    // 8003CE28: lwz     r3, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003CE2C:
    ctx->pc = 0x8003CE2Cu;
    // 8003CE2C: lwz     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003CE30:
    ctx->pc = 0x8003CE30u;
    // 8003CE30: stw     r3, 76(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(76);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8003CE34:
    ctx->pc = 0x8003CE34u;
    // 8003CE34: stw     r0, 80(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003CE38:
    ctx->pc = 0x8003CE38u;
    // 8003CE38: lwz     r3, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003CE3C:
    ctx->pc = 0x8003CE3Cu;
    // 8003CE3C: lwz     r0, 12(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003CE40:
    ctx->pc = 0x8003CE40u;
    // 8003CE40: stw     r3, 84(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8003CE44:
    ctx->pc = 0x8003CE44u;
    // 8003CE44: stw     r0, 88(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003CE48:
    ctx->pc = 0x8003CE48u;
    // 8003CE48: lwz     r3, 16(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003CE4C:
    ctx->pc = 0x8003CE4Cu;
    // 8003CE4C: lwz     r0, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003CE50:
    ctx->pc = 0x8003CE50u;
    // 8003CE50: stw     r3, 92(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8003CE54:
    ctx->pc = 0x8003CE54u;
    // 8003CE54: stw     r0, 96(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003CE58:
    ctx->pc = 0x8003CE58u;
    // 8003CE58: lwz     r3, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003CE5C:
    ctx->pc = 0x8003CE5Cu;
    // 8003CE5C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8003CE60:
    ctx->pc = 0x8003CE60u;
    // 8003CE60: bl      0x80028584
    {
            ctx->lr = 0x8003CE64u;
            ctx->pc = 0x80028584u;
            return;
    }

label_8003CE64:
    ctx->pc = 0x8003CE64u;
    ctx->downcount -= 5;
    // 8003CE64: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003CE68:
    ctx->pc = 0x8003CE68u;
    // 8003CE68: lwz     r0, 60(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(60);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003CE6C:
    ctx->pc = 0x8003CE6Cu;
    // 8003CE6C: rlwinm r0, r0, 0, 22, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000200u;
    }

label_8003CE70:
    ctx->pc = 0x8003CE70u;
    // 8003CE70: cmplwi  r0, 0x0000
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

label_8003CE74:
    ctx->pc = 0x8003CE74u;
    // 8003CE74: bc    4, 2, 0x8003CE88
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003CE88;
        }
    }

label_8003CE78:
    ctx->pc = 0x8003CE78u;
    ctx->downcount -= 4;
    // 8003CE78: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8003CE7C:
    ctx->pc = 0x8003CE7Cu;
    // 8003CE7C: stb     r0, -25930(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25930);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8003CE80:
    ctx->pc = 0x8003CE80u;
    // 8003CE80: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003CE84:
    ctx->pc = 0x8003CE84u;
    // 8003CE84: b       0x8003D86C
    {
            goto label_8003D86C;
    }

label_8003CE88:
    ctx->pc = 0x8003CE88u;
    ctx->downcount -= 5;
    // 8003CE88: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8003CE8C:
    ctx->pc = 0x8003CE8Cu;
    // 8003CE8C: stb     r0, -25930(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25930);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8003CE90:
    ctx->pc = 0x8003CE90u;
    // 8003CE90: addi    r3, r1, 56
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(56);

label_8003CE94:
    ctx->pc = 0x8003CE94u;
    // 8003CE94: addi    r4, r1, 52
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(52);

label_8003CE98:
    ctx->pc = 0x8003CE98u;
    // 8003CE98: bl      0x8006C6C4
    {
            ctx->lr = 0x8003CE9Cu;
            ctx->pc = 0x8006C6C4u;
            return;
    }

label_8003CE9C:
    ctx->pc = 0x8003CE9Cu;
    ctx->downcount -= 3;
    // 8003CE9C: lbz     r0, -25939(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25939);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003CEA0:
    ctx->pc = 0x8003CEA0u;
    // 8003CEA0: cmplwi  r0, 0x0000
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

label_8003CEA4:
    ctx->pc = 0x8003CEA4u;
    // 8003CEA4: bc    12, 2, 0x8003CEB0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003CEB0;
        }
    }

label_8003CEA8:
    ctx->pc = 0x8003CEA8u;
    ctx->downcount -= 2;
    // 8003CEA8: lfs     f31, -31476(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003CEA8u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31476);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_8003CEAC:
    ctx->pc = 0x8003CEACu;
    // 8003CEAC: b       0x8003CEF4
    {
            goto label_8003CEF4;
    }

label_8003CEB0:
    ctx->pc = 0x8003CEB0u;
    ctx->downcount -= 33;
    // 8003CEB0: lwz     r0, -25924(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25924);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003CEB4:
    ctx->pc = 0x8003CEB4u;
    // 8003CEB4: lfd     f2, -31416(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003CEB4u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31416);
        ctx->fpr[2] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003CEB8:
    ctx->pc = 0x8003CEB8u;
    // 8003CEB8: xoris   r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] ^ (0x8000u << 16);

label_8003CEBC:
    ctx->pc = 0x8003CEBCu;
    // 8003CEBC: stw     r0, 324(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(324);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003CEC0:
    ctx->pc = 0x8003CEC0u;
    // 8003CEC0: lis     r3, 17200
    ctx->gpr[3] = ((u32)(s32)(17200) << 16);

label_8003CEC4:
    ctx->pc = 0x8003CEC4u;
    // 8003CEC4: stw     r3, 320(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(320);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8003CEC8:
    ctx->pc = 0x8003CEC8u;
    // 8003CEC8: lfd     f0, 320(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003CEC8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(320);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003CECC:
    ctx->pc = 0x8003CECCu;
    // 8003CECC: fsubs   f1, f0, f2
    if (!ppc_fp_available_inline(ctx, 0x8003CECCu)) return;
    ppc_fsubs(ctx, 1, 0, 2);

label_8003CED0:
    ctx->pc = 0x8003CED0u;
    // 8003CED0: lwz     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003CED4:
    ctx->pc = 0x8003CED4u;
    // 8003CED4: xoris   r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] ^ (0x8000u << 16);

label_8003CED8:
    ctx->pc = 0x8003CED8u;
    // 8003CED8: stw     r0, 332(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(332);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003CEDC:
    ctx->pc = 0x8003CEDCu;
    // 8003CEDC: stw     r3, 328(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(328);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8003CEE0:
    ctx->pc = 0x8003CEE0u;
    // 8003CEE0: lfd     f0, 328(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003CEE0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(328);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003CEE4:
    ctx->pc = 0x8003CEE4u;
    // 8003CEE4: fsubs   f0, f0, f2
    if (!ppc_fp_available_inline(ctx, 0x8003CEE4u)) return;
    ppc_fsubs(ctx, 0, 0, 2);

label_8003CEE8:
    ctx->pc = 0x8003CEE8u;
    // 8003CEE8: fdivs   f31, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8003CEE8u)) return;
    ppc_fdivs(ctx, 31, 1, 0);

label_8003CEEC:
    ctx->pc = 0x8003CEECu;
    // 8003CEEC: lfs     f0, -31440(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003CEECu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31440);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003CEF0:
    ctx->pc = 0x8003CEF0u;
    // 8003CEF0: fmuls   f31, f31, f0
    if (!ppc_fp_available_inline(ctx, 0x8003CEF0u)) return;
    ppc_fmuls(ctx, 31, 31, 0);

label_8003CEF4:
    ctx->pc = 0x8003CEF4u;
    ctx->downcount -= 3;
    // 8003CEF4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8003CEF8:
    ctx->pc = 0x8003CEF8u;
    // 8003CEF8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003CEFC:
    ctx->pc = 0x8003CEFCu;
    // 8003CEFC: bl      0x8004C434
    {
            ctx->lr = 0x8003CF00u;
            ctx->pc = 0x8004C434u;
            return;
    }

label_8003CF00:
    ctx->pc = 0x8003CF00u;
    ctx->downcount -= 2;
    // 8003CF00: lwz     r3, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003CF04:
    ctx->pc = 0x8003CF04u;
    // 8003CF04: bl      0x800538A4
    {
            ctx->lr = 0x8003CF08u;
            ctx->pc = 0x800538A4u;
            return;
    }

label_8003CF08:
    ctx->pc = 0x8003CF08u;
    ctx->downcount -= 2;
    // 8003CF08: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003CF0C:
    ctx->pc = 0x8003CF0Cu;
    // 8003CF0C: bl      0x8004C4C8
    {
            ctx->lr = 0x8003CF10u;
            ctx->pc = 0x8004C4C8u;
            return;
    }

label_8003CF10:
    ctx->pc = 0x8003CF10u;
    ctx->downcount -= 7;
    // 8003CF10: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003CF14:
    ctx->pc = 0x8003CF14u;
    // 8003CF14: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8003CF18:
    ctx->pc = 0x8003CF18u;
    // 8003CF18: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_8003CF1C:
    ctx->pc = 0x8003CF1Cu;
    // 8003CF1C: li      r6, 60
    ctx->gpr[6] = (u32)(s32)(60);

label_8003CF20:
    ctx->pc = 0x8003CF20u;
    // 8003CF20: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8003CF24:
    ctx->pc = 0x8003CF24u;
    // 8003CF24: li      r8, 125
    ctx->gpr[8] = (u32)(s32)(125);

label_8003CF28:
    ctx->pc = 0x8003CF28u;
    // 8003CF28: bl      0x80258880
    {
            ctx->lr = 0x8003CF2Cu;
            ctx->pc = 0x80258880u;
            return;
    }

label_8003CF2C:
    ctx->pc = 0x8003CF2Cu;
    ctx->downcount -= 3;
    // 8003CF2C: lbz     r0, -25938(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25938);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003CF30:
    ctx->pc = 0x8003CF30u;
    // 8003CF30: cmplwi  r0, 0x0000
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

label_8003CF34:
    ctx->pc = 0x8003CF34u;
    // 8003CF34: bc    4, 2, 0x8003CF54
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003CF54;
        }
    }

label_8003CF38:
    ctx->pc = 0x8003CF38u;
    ctx->downcount -= 6;
    // 8003CF38: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003CF3C:
    ctx->pc = 0x8003CF3Cu;
    // 8003CF3C: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_8003CF40:
    ctx->pc = 0x8003CF40u;
    // 8003CF40: li      r5, 15
    ctx->gpr[5] = (u32)(s32)(15);

label_8003CF44:
    ctx->pc = 0x8003CF44u;
    // 8003CF44: li      r6, 15
    ctx->gpr[6] = (u32)(s32)(15);

label_8003CF48:
    ctx->pc = 0x8003CF48u;
    // 8003CF48: li      r7, 8
    ctx->gpr[7] = (u32)(s32)(8);

label_8003CF4C:
    ctx->pc = 0x8003CF4Cu;
    // 8003CF4C: bl      0x8025C3B0
    {
            ctx->lr = 0x8003CF50u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_8003CF50:
    ctx->pc = 0x8003CF50u;
    ctx->downcount -= 1;
    // 8003CF50: b       0x8003D014
    {
            goto label_8003D014;
    }

label_8003CF54:
    ctx->pc = 0x8003CF54u;
    ctx->downcount -= 2;
    // 8003CF54: cmplwi  r0, 0x0001
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

label_8003CF58:
    ctx->pc = 0x8003CF58u;
    // 8003CF58: bc    4, 2, 0x8003CF94
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003CF94;
        }
    }

label_8003CF5C:
    ctx->pc = 0x8003CF5Cu;
    ctx->downcount -= 13;
    // 8003CF5C: lwz     r0, -25924(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25924);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003CF60:
    ctx->pc = 0x8003CF60u;
    // 8003CF60: rlwinm r0, r0, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 4u) & 0xFFFFFFF0u;
    }

label_8003CF64:
    ctx->pc = 0x8003CF64u;
    // 8003CF64: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_8003CF68:
    ctx->pc = 0x8003CF68u;
    // 8003CF68: addi    r3, r13, -31996
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-31996);

label_8003CF6C:
    ctx->pc = 0x8003CF6Cu;
    // 8003CF6C: stb     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8003CF70:
    ctx->pc = 0x8003CF70u;
    // 8003CF70: stb     r0, 1(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8003CF74:
    ctx->pc = 0x8003CF74u;
    // 8003CF74: stb     r0, -31996(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31996);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8003CF78:
    ctx->pc = 0x8003CF78u;
    // 8003CF78: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003CF7C:
    ctx->pc = 0x8003CF7Cu;
    // 8003CF7C: li      r4, 8
    ctx->gpr[4] = (u32)(s32)(8);

label_8003CF80:
    ctx->pc = 0x8003CF80u;
    // 8003CF80: li      r5, 12
    ctx->gpr[5] = (u32)(s32)(12);

label_8003CF84:
    ctx->pc = 0x8003CF84u;
    // 8003CF84: li      r6, 14
    ctx->gpr[6] = (u32)(s32)(14);

label_8003CF88:
    ctx->pc = 0x8003CF88u;
    // 8003CF88: li      r7, 15
    ctx->gpr[7] = (u32)(s32)(15);

label_8003CF8C:
    ctx->pc = 0x8003CF8Cu;
    // 8003CF8C: bl      0x8025C3B0
    {
            ctx->lr = 0x8003CF90u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_8003CF90:
    ctx->pc = 0x8003CF90u;
    ctx->downcount -= 1;
    // 8003CF90: b       0x8003CFE8
    {
            goto label_8003CFE8;
    }

label_8003CF94:
    ctx->pc = 0x8003CF94u;
    ctx->downcount -= 3;
    // 8003CF94: lwz     r0, -25924(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25924);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003CF98:
    ctx->pc = 0x8003CF98u;
    // 8003CF98: cmpwi   r0, 8
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

label_8003CF9C:
    ctx->pc = 0x8003CF9Cu;
    // 8003CF9C: bc    4, 0, 0x8003CFB4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003CFB4;
        }
    }

label_8003CFA0:
    ctx->pc = 0x8003CFA0u;
    ctx->downcount -= 5;
    // 8003CFA0: rlwinm r0, r0, 5, 0, 26
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 5u) & 0xFFFFFFE0u;
    }

label_8003CFA4:
    ctx->pc = 0x8003CFA4u;
    // 8003CFA4: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_8003CFA8:
    ctx->pc = 0x8003CFA8u;
    // 8003CFA8: addi    r3, r13, -31996
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-31996);

label_8003CFAC:
    ctx->pc = 0x8003CFACu;
    // 8003CFAC: stb     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8003CFB0:
    ctx->pc = 0x8003CFB0u;
    // 8003CFB0: b       0x8003CFC0
    {
            goto label_8003CFC0;
    }

label_8003CFB4:
    ctx->pc = 0x8003CFB4u;
    ctx->downcount -= 3;
    // 8003CFB4: li      r0, 255
    ctx->gpr[0] = (u32)(s32)(255);

label_8003CFB8:
    ctx->pc = 0x8003CFB8u;
    // 8003CFB8: addi    r3, r13, -31996
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-31996);

label_8003CFBC:
    ctx->pc = 0x8003CFBCu;
    // 8003CFBC: stb     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8003CFC0:
    ctx->pc = 0x8003CFC0u;
    ctx->downcount -= 10;
    // 8003CFC0: addi    r3, r13, -31996
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-31996);

label_8003CFC4:
    ctx->pc = 0x8003CFC4u;
    // 8003CFC4: lbz     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003CFC8:
    ctx->pc = 0x8003CFC8u;
    // 8003CFC8: stb     r0, 1(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8003CFCC:
    ctx->pc = 0x8003CFCCu;
    // 8003CFCC: stb     r0, -31996(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31996);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8003CFD0:
    ctx->pc = 0x8003CFD0u;
    // 8003CFD0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003CFD4:
    ctx->pc = 0x8003CFD4u;
    // 8003CFD4: li      r4, 8
    ctx->gpr[4] = (u32)(s32)(8);

label_8003CFD8:
    ctx->pc = 0x8003CFD8u;
    // 8003CFD8: li      r5, 15
    ctx->gpr[5] = (u32)(s32)(15);

label_8003CFDC:
    ctx->pc = 0x8003CFDCu;
    // 8003CFDC: li      r6, 14
    ctx->gpr[6] = (u32)(s32)(14);

label_8003CFE0:
    ctx->pc = 0x8003CFE0u;
    // 8003CFE0: li      r7, 15
    ctx->gpr[7] = (u32)(s32)(15);

label_8003CFE4:
    ctx->pc = 0x8003CFE4u;
    // 8003CFE4: bl      0x8025C3B0
    {
            ctx->lr = 0x8003CFE8u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_8003CFE8:
    ctx->pc = 0x8003CFE8u;
    ctx->downcount -= 5;
    // 8003CFE8: lwz     r0, -31996(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31996);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003CFEC:
    ctx->pc = 0x8003CFECu;
    // 8003CFEC: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003CFF0:
    ctx->pc = 0x8003CFF0u;
    // 8003CFF0: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003CFF4:
    ctx->pc = 0x8003CFF4u;
    // 8003CFF4: addi    r4, r1, 28
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(28);

label_8003CFF8:
    ctx->pc = 0x8003CFF8u;
    // 8003CFF8: bl      0x8025C71C
    {
            ctx->lr = 0x8003CFFCu;
            ctx->pc = 0x8025C71Cu;
            return;
    }

label_8003CFFC:
    ctx->pc = 0x8003CFFCu;
    ctx->downcount -= 3;
    // 8003CFFC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003D000:
    ctx->pc = 0x8003D000u;
    // 8003D000: li      r4, 29
    ctx->gpr[4] = (u32)(s32)(29);

label_8003D004:
    ctx->pc = 0x8003D004u;
    // 8003D004: bl      0x8025C7FC
    {
            ctx->lr = 0x8003D008u;
            ctx->pc = 0x8025C7FCu;
            return;
    }

label_8003D008:
    ctx->pc = 0x8003D008u;
    ctx->downcount -= 3;
    // 8003D008: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003D00C:
    ctx->pc = 0x8003D00Cu;
    // 8003D00C: li      r4, 13
    ctx->gpr[4] = (u32)(s32)(13);

label_8003D010:
    ctx->pc = 0x8003D010u;
    // 8003D010: bl      0x8025C790
    {
            ctx->lr = 0x8003D014u;
            ctx->pc = 0x8025C790u;
            return;
    }

label_8003D014:
    ctx->pc = 0x8003D014u;
    ctx->downcount -= 2;
    // 8003D014: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003D018:
    ctx->pc = 0x8003D018u;
    // 8003D018: bl      0x8025C08C
    {
            ctx->lr = 0x8003D01Cu;
            ctx->pc = 0x8025C08Cu;
            return;
    }

label_8003D01C:
    ctx->pc = 0x8003D01Cu;
    ctx->downcount -= 5;
    // 8003D01C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003D020:
    ctx->pc = 0x8003D020u;
    // 8003D020: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_8003D024:
    ctx->pc = 0x8003D024u;
    // 8003D024: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003D028:
    ctx->pc = 0x8003D028u;
    // 8003D028: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_8003D02C:
    ctx->pc = 0x8003D02Cu;
    // 8003D02C: bl      0x8025CA34
    {
            ctx->lr = 0x8003D030u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_8003D030:
    ctx->pc = 0x8003D030u;
    ctx->downcount -= 6;
    // 8003D030: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003D034:
    ctx->pc = 0x8003D034u;
    // 8003D034: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_8003D038:
    ctx->pc = 0x8003D038u;
    // 8003D038: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_8003D03C:
    ctx->pc = 0x8003D03Cu;
    // 8003D03C: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_8003D040:
    ctx->pc = 0x8003D040u;
    // 8003D040: li      r7, 7
    ctx->gpr[7] = (u32)(s32)(7);

label_8003D044:
    ctx->pc = 0x8003D044u;
    // 8003D044: bl      0x8025C430
    {
            ctx->lr = 0x8003D048u;
            ctx->pc = 0x8025C430u;
            return;
    }

label_8003D048:
    ctx->pc = 0x8003D048u;
    ctx->downcount -= 4;
    // 8003D048: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003D04C:
    ctx->pc = 0x8003D04Cu;
    // 8003D04C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003D050:
    ctx->pc = 0x8003D050u;
    // 8003D050: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003D054:
    ctx->pc = 0x8003D054u;
    // 8003D054: bl      0x8025C868
    {
            ctx->lr = 0x8003D058u;
            ctx->pc = 0x8025C868u;
            return;
    }

label_8003D058:
    ctx->pc = 0x8003D058u;
    ctx->downcount -= 7;
    // 8003D058: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003D05C:
    ctx->pc = 0x8003D05Cu;
    // 8003D05C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003D060:
    ctx->pc = 0x8003D060u;
    // 8003D060: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003D064:
    ctx->pc = 0x8003D064u;
    // 8003D064: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8003D068:
    ctx->pc = 0x8003D068u;
    // 8003D068: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8003D06C:
    ctx->pc = 0x8003D06Cu;
    // 8003D06C: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8003D070:
    ctx->pc = 0x8003D070u;
    // 8003D070: bl      0x8025C4B4
    {
            ctx->lr = 0x8003D074u;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_8003D074:
    ctx->pc = 0x8003D074u;
    ctx->downcount -= 7;
    // 8003D074: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003D078:
    ctx->pc = 0x8003D078u;
    // 8003D078: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003D07C:
    ctx->pc = 0x8003D07Cu;
    // 8003D07C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003D080:
    ctx->pc = 0x8003D080u;
    // 8003D080: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8003D084:
    ctx->pc = 0x8003D084u;
    // 8003D084: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8003D088:
    ctx->pc = 0x8003D088u;
    // 8003D088: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8003D08C:
    ctx->pc = 0x8003D08Cu;
    // 8003D08C: bl      0x8025C574
    {
            ctx->lr = 0x8003D090u;
            ctx->pc = 0x8025C574u;
            return;
    }

label_8003D090:
    ctx->pc = 0x8003D090u;
    ctx->downcount -= 15;
    // 8003D090: lbz     r0, 241(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(241);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003D094:
    ctx->pc = 0x8003D094u;
    // 8003D094: sth     r0, 72(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003D098:
    ctx->pc = 0x8003D098u;
    // 8003D098: sth     r0, 70(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(70);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003D09C:
    ctx->pc = 0x8003D09Cu;
    // 8003D09C: sth     r0, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003D0A0:
    ctx->pc = 0x8003D0A0u;
    // 8003D0A0: lbz     r3, 55(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(55);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8003D0A4:
    ctx->pc = 0x8003D0A4u;
    // 8003D0A4: addi    r0, r3, -255
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-255);

label_8003D0A8:
    ctx->pc = 0x8003D0A8u;
    // 8003D0A8: extsh r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_8003D0AC:
    ctx->pc = 0x8003D0ACu;
    // 8003D0AC: sth     r0, 74(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(74);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003D0B0:
    ctx->pc = 0x8003D0B0u;
    // 8003D0B0: lwz     r3, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003D0B4:
    ctx->pc = 0x8003D0B4u;
    // 8003D0B4: lwz     r0, 72(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003D0B8:
    ctx->pc = 0x8003D0B8u;
    // 8003D0B8: stw     r3, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8003D0BC:
    ctx->pc = 0x8003D0BCu;
    // 8003D0BC: stw     r0, 64(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003D0C0:
    ctx->pc = 0x8003D0C0u;
    // 8003D0C0: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_8003D0C4:
    ctx->pc = 0x8003D0C4u;
    // 8003D0C4: addi    r4, r1, 60
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(60);

label_8003D0C8:
    ctx->pc = 0x8003D0C8u;
    // 8003D0C8: bl      0x8025C6A8
    {
            ctx->lr = 0x8003D0CCu;
            ctx->pc = 0x8025C6A8u;
            return;
    }

label_8003D0CC:
    ctx->pc = 0x8003D0CCu;
    ctx->downcount -= 5;
    // 8003D0CC: addi    r3, r1, 220
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(220);

label_8003D0D0:
    ctx->pc = 0x8003D0D0u;
    // 8003D0D0: lfs     f1, -31436(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003D0D0u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31436);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003D0D4:
    ctx->pc = 0x8003D0D4u;
    // 8003D0D4: fmr    f2, f1
    if (!ppc_fp_available_inline(ctx, 0x8003D0D4u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_8003D0D8:
    ctx->pc = 0x8003D0D8u;
    // 8003D0D8: lfs     f3, -31476(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003D0D8u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31476);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8003D0DC:
    ctx->pc = 0x8003D0DCu;
    // 8003D0DC: bl      0x80247CC4
    {
            ctx->lr = 0x8003D0E0u;
            ctx->pc = 0x80247CC4u;
            return;
    }

label_8003D0E0:
    ctx->pc = 0x8003D0E0u;
    ctx->downcount -= 5;
    // 8003D0E0: addi    r3, r1, 172
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(172);

label_8003D0E4:
    ctx->pc = 0x8003D0E4u;
    // 8003D0E4: lfs     f1, -31440(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003D0E4u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31440);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003D0E8:
    ctx->pc = 0x8003D0E8u;
    // 8003D0E8: fmr    f2, f1
    if (!ppc_fp_available_inline(ctx, 0x8003D0E8u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_8003D0EC:
    ctx->pc = 0x8003D0ECu;
    // 8003D0EC: lfs     f3, -31452(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003D0ECu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31452);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8003D0F0:
    ctx->pc = 0x8003D0F0u;
    // 8003D0F0: bl      0x80247C90
    {
            ctx->lr = 0x8003D0F4u;
            ctx->pc = 0x80247C90u;
            return;
    }

label_8003D0F4:
    ctx->pc = 0x8003D0F4u;
    ctx->downcount -= 4;
    // 8003D0F4: addi    r3, r1, 172
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(172);

label_8003D0F8:
    ctx->pc = 0x8003D0F8u;
    // 8003D0F8: addi    r4, r1, 220
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(220);

label_8003D0FC:
    ctx->pc = 0x8003D0FCu;
    // 8003D0FC: or   r5, r4, r4
    {
        ctx->gpr[5] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8003D100:
    ctx->pc = 0x8003D100u;
    // 8003D100: bl      0x80247860
    {
            ctx->lr = 0x8003D104u;
            ctx->pc = 0x80247860u;
            return;
    }

label_8003D104:
    ctx->pc = 0x8003D104u;
    ctx->downcount -= 4;
    // 8003D104: addi    r3, r1, 220
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(220);

label_8003D108:
    ctx->pc = 0x8003D108u;
    // 8003D108: li      r4, 67
    ctx->gpr[4] = (u32)(s32)(67);

label_8003D10C:
    ctx->pc = 0x8003D10Cu;
    // 8003D10C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003D110:
    ctx->pc = 0x8003D110u;
    // 8003D110: bl      0x8025DAD0
    {
            ctx->lr = 0x8003D114u;
            ctx->pc = 0x8025DAD0u;
            return;
    }

label_8003D114:
    ctx->pc = 0x8003D114u;
    ctx->downcount -= 7;
    // 8003D114: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003D118:
    ctx->pc = 0x8003D118u;
    // 8003D118: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8003D11C:
    ctx->pc = 0x8003D11Cu;
    // 8003D11C: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_8003D120:
    ctx->pc = 0x8003D120u;
    // 8003D120: li      r6, 30
    ctx->gpr[6] = (u32)(s32)(30);

label_8003D124:
    ctx->pc = 0x8003D124u;
    // 8003D124: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8003D128:
    ctx->pc = 0x8003D128u;
    // 8003D128: li      r8, 67
    ctx->gpr[8] = (u32)(s32)(67);

label_8003D12C:
    ctx->pc = 0x8003D12Cu;
    // 8003D12C: bl      0x80258880
    {
            ctx->lr = 0x8003D130u;
            ctx->pc = 0x80258880u;
            return;
    }

label_8003D130:
    ctx->pc = 0x8003D130u;
    ctx->downcount -= 3;
    // 8003D130: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8003D134:
    ctx->pc = 0x8003D134u;
    // 8003D134: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8003D138:
    ctx->pc = 0x8003D138u;
    // 8003D138: bl      0x80028718
    {
            ctx->lr = 0x8003D13Cu;
            ctx->pc = 0x80028718u;
            return;
    }

label_8003D13C:
    ctx->pc = 0x8003D13Cu;
    ctx->downcount -= 3;
    // 8003D13C: lwz     r3, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003D140:
    ctx->pc = 0x8003D140u;
    // 8003D140: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8003D144:
    ctx->pc = 0x8003D144u;
    // 8003D144: bl      0x8004C4C8
    {
            ctx->lr = 0x8003D148u;
            ctx->pc = 0x8004C4C8u;
            return;
    }

label_8003D148:
    ctx->pc = 0x8003D148u;
    ctx->downcount -= 2;
    // 8003D148: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003D14C:
    ctx->pc = 0x8003D14Cu;
    // 8003D14C: bl      0x8025C08C
    {
            ctx->lr = 0x8003D150u;
            ctx->pc = 0x8025C08Cu;
            return;
    }

label_8003D150:
    ctx->pc = 0x8003D150u;
    ctx->downcount -= 5;
    // 8003D150: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003D154:
    ctx->pc = 0x8003D154u;
    // 8003D154: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003D158:
    ctx->pc = 0x8003D158u;
    // 8003D158: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_8003D15C:
    ctx->pc = 0x8003D15Cu;
    // 8003D15C: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_8003D160:
    ctx->pc = 0x8003D160u;
    // 8003D160: bl      0x8025CA34
    {
            ctx->lr = 0x8003D164u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_8003D164:
    ctx->pc = 0x8003D164u;
    ctx->downcount -= 4;
    // 8003D164: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003D168:
    ctx->pc = 0x8003D168u;
    // 8003D168: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003D16C:
    ctx->pc = 0x8003D16Cu;
    // 8003D16C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003D170:
    ctx->pc = 0x8003D170u;
    // 8003D170: bl      0x8025C868
    {
            ctx->lr = 0x8003D174u;
            ctx->pc = 0x8025C868u;
            return;
    }

label_8003D174:
    ctx->pc = 0x8003D174u;
    ctx->downcount -= 6;
    // 8003D174: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003D178:
    ctx->pc = 0x8003D178u;
    // 8003D178: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_8003D17C:
    ctx->pc = 0x8003D17Cu;
    // 8003D17C: li      r5, 8
    ctx->gpr[5] = (u32)(s32)(8);

label_8003D180:
    ctx->pc = 0x8003D180u;
    // 8003D180: li      r6, 6
    ctx->gpr[6] = (u32)(s32)(6);

label_8003D184:
    ctx->pc = 0x8003D184u;
    // 8003D184: li      r7, 10
    ctx->gpr[7] = (u32)(s32)(10);

label_8003D188:
    ctx->pc = 0x8003D188u;
    // 8003D188: bl      0x8025C3B0
    {
            ctx->lr = 0x8003D18Cu;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_8003D18C:
    ctx->pc = 0x8003D18Cu;
    ctx->downcount -= 6;
    // 8003D18C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003D190:
    ctx->pc = 0x8003D190u;
    // 8003D190: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_8003D194:
    ctx->pc = 0x8003D194u;
    // 8003D194: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_8003D198:
    ctx->pc = 0x8003D198u;
    // 8003D198: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_8003D19C:
    ctx->pc = 0x8003D19Cu;
    // 8003D19C: li      r7, 3
    ctx->gpr[7] = (u32)(s32)(3);

label_8003D1A0:
    ctx->pc = 0x8003D1A0u;
    // 8003D1A0: bl      0x8025C430
    {
            ctx->lr = 0x8003D1A4u;
            ctx->pc = 0x8025C430u;
            return;
    }

label_8003D1A4:
    ctx->pc = 0x8003D1A4u;
    ctx->downcount -= 7;
    // 8003D1A4: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003D1A8:
    ctx->pc = 0x8003D1A8u;
    // 8003D1A8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003D1AC:
    ctx->pc = 0x8003D1ACu;
    // 8003D1AC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003D1B0:
    ctx->pc = 0x8003D1B0u;
    // 8003D1B0: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8003D1B4:
    ctx->pc = 0x8003D1B4u;
    // 8003D1B4: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8003D1B8:
    ctx->pc = 0x8003D1B8u;
    // 8003D1B8: li      r8, 2
    ctx->gpr[8] = (u32)(s32)(2);

label_8003D1BC:
    ctx->pc = 0x8003D1BCu;
    // 8003D1BC: bl      0x8025C4B4
    {
            ctx->lr = 0x8003D1C0u;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_8003D1C0:
    ctx->pc = 0x8003D1C0u;
    ctx->downcount -= 7;
    // 8003D1C0: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003D1C4:
    ctx->pc = 0x8003D1C4u;
    // 8003D1C4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003D1C8:
    ctx->pc = 0x8003D1C8u;
    // 8003D1C8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003D1CC:
    ctx->pc = 0x8003D1CCu;
    // 8003D1CC: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8003D1D0:
    ctx->pc = 0x8003D1D0u;
    // 8003D1D0: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8003D1D4:
    ctx->pc = 0x8003D1D4u;
    // 8003D1D4: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8003D1D8:
    ctx->pc = 0x8003D1D8u;
    // 8003D1D8: bl      0x8025C574
    {
            ctx->lr = 0x8003D1DCu;
            ctx->pc = 0x8025C574u;
            return;
    }

label_8003D1DC:
    ctx->pc = 0x8003D1DCu;
    ctx->downcount -= 3;
    // 8003D1DC: lwz     r0, -25900(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25900);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003D1E0:
    ctx->pc = 0x8003D1E0u;
    // 8003D1E0: cmpwi   r0, 0
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

label_8003D1E4:
    ctx->pc = 0x8003D1E4u;
    // 8003D1E4: bc    12, 2, 0x8003D20C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003D20C;
        }
    }

label_8003D1E8:
    ctx->pc = 0x8003D1E8u;
    ctx->downcount -= 4;
    // 8003D1E8: lwz     r3, -25892(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25892);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003D1EC:
    ctx->pc = 0x8003D1ECu;
    // 8003D1EC: addi    r4, r1, 16
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(16);

label_8003D1F0:
    ctx->pc = 0x8003D1F0u;
    // 8003D1F0: addi    r5, r1, 20
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(20);

label_8003D1F4:
    ctx->pc = 0x8003D1F4u;
    // 8003D1F4: bl      0x8001D96C
    {
            ctx->lr = 0x8003D1F8u;
            ctx->pc = 0x8001D96Cu;
            return;
    }

label_8003D1F8:
    ctx->pc = 0x8003D1F8u;
    ctx->downcount -= 3;
    // 8003D1F8: lwz     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003D1FC:
    ctx->pc = 0x8003D1FCu;
    // 8003D1FC: cmpwi   r0, 0
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

label_8003D200:
    ctx->pc = 0x8003D200u;
    // 8003D200: bc    4, 2, 0x8003D20C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003D20C;
        }
    }

label_8003D204:
    ctx->pc = 0x8003D204u;
    ctx->downcount -= 2;
    // 8003D204: li      r28, 1
    ctx->gpr[28] = (u32)(s32)(1);

label_8003D208:
    ctx->pc = 0x8003D208u;
    // 8003D208: b       0x8003D210
    {
            goto label_8003D210;
    }

label_8003D20C:
    ctx->pc = 0x8003D20Cu;
    ctx->downcount -= 1;
    // 8003D20C: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_8003D210:
    ctx->pc = 0x8003D210u;
    ctx->downcount -= 3;
    // 8003D210: rlwinm r0, r28, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[28], 0u) & 0x000000FFu;
    }

label_8003D214:
    ctx->pc = 0x8003D214u;
    // 8003D214: cmplwi  r0, 0x0000
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

label_8003D218:
    ctx->pc = 0x8003D218u;
    // 8003D218: bc    12, 2, 0x8003D404
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003D404;
        }
    }

label_8003D21C:
    ctx->pc = 0x8003D21Cu;
    ctx->downcount -= 2;
    // 8003D21C: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003D220:
    ctx->pc = 0x8003D220u;
    // 8003D220: bl      0x8025C08C
    {
            ctx->lr = 0x8003D224u;
            ctx->pc = 0x8025C08Cu;
            return;
    }

label_8003D224:
    ctx->pc = 0x8003D224u;
    ctx->downcount -= 2;
    // 8003D224: lwz     r3, -25892(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25892);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003D228:
    ctx->pc = 0x8003D228u;
    // 8003D228: bl      0x8001D98C
    {
            ctx->lr = 0x8003D22Cu;
            ctx->pc = 0x8001D98Cu;
            return;
    }

label_8003D22C:
    ctx->pc = 0x8003D22Cu;
    ctx->downcount -= 3;
    // 8003D22C: li      r4, 73
    ctx->gpr[4] = (u32)(s32)(73);

label_8003D230:
    ctx->pc = 0x8003D230u;
    // 8003D230: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003D234:
    ctx->pc = 0x8003D234u;
    // 8003D234: bl      0x8025DAD0
    {
            ctx->lr = 0x8003D238u;
            ctx->pc = 0x8025DAD0u;
            return;
    }

label_8003D238:
    ctx->pc = 0x8003D238u;
    ctx->downcount -= 7;
    // 8003D238: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003D23C:
    ctx->pc = 0x8003D23Cu;
    // 8003D23C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003D240:
    ctx->pc = 0x8003D240u;
    // 8003D240: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003D244:
    ctx->pc = 0x8003D244u;
    // 8003D244: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8003D248:
    ctx->pc = 0x8003D248u;
    // 8003D248: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8003D24C:
    ctx->pc = 0x8003D24Cu;
    // 8003D24C: li      r8, 73
    ctx->gpr[8] = (u32)(s32)(73);

label_8003D250:
    ctx->pc = 0x8003D250u;
    // 8003D250: bl      0x80258880
    {
            ctx->lr = 0x8003D254u;
            ctx->pc = 0x80258880u;
            return;
    }

label_8003D254:
    ctx->pc = 0x8003D254u;
    ctx->downcount -= 3;
    // 8003D254: lbz     r0, -25896(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25896);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003D258:
    ctx->pc = 0x8003D258u;
    // 8003D258: cmplwi  r0, 0x0000
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

label_8003D25C:
    ctx->pc = 0x8003D25Cu;
    // 8003D25C: bc    12, 2, 0x8003D268
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003D268;
        }
    }

label_8003D260:
    ctx->pc = 0x8003D260u;
    ctx->downcount -= 2;
    // 8003D260: cmplwi  r0, 0x0002
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0002u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003D264:
    ctx->pc = 0x8003D264u;
    // 8003D264: bc    4, 2, 0x8003D280
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003D280;
        }
    }

label_8003D268:
    ctx->pc = 0x8003D268u;
    ctx->downcount -= 5;
    // 8003D268: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003D26C:
    ctx->pc = 0x8003D26Cu;
    // 8003D26C: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8003D270:
    ctx->pc = 0x8003D270u;
    // 8003D270: li      r5, 5
    ctx->gpr[5] = (u32)(s32)(5);

label_8003D274:
    ctx->pc = 0x8003D274u;
    // 8003D274: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_8003D278:
    ctx->pc = 0x8003D278u;
    // 8003D278: bl      0x8025CA34
    {
            ctx->lr = 0x8003D27Cu;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_8003D27C:
    ctx->pc = 0x8003D27Cu;
    ctx->downcount -= 1;
    // 8003D27C: b       0x8003D294
    {
            goto label_8003D294;
    }

label_8003D280:
    ctx->pc = 0x8003D280u;
    ctx->downcount -= 5;
    // 8003D280: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003D284:
    ctx->pc = 0x8003D284u;
    // 8003D284: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8003D288:
    ctx->pc = 0x8003D288u;
    // 8003D288: li      r5, 5
    ctx->gpr[5] = (u32)(s32)(5);

label_8003D28C:
    ctx->pc = 0x8003D28Cu;
    // 8003D28C: li      r6, 5
    ctx->gpr[6] = (u32)(s32)(5);

label_8003D290:
    ctx->pc = 0x8003D290u;
    // 8003D290: bl      0x8025CA34
    {
            ctx->lr = 0x8003D294u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_8003D294:
    ctx->pc = 0x8003D294u;
    ctx->downcount -= 2;
    // 8003D294: lwz     r3, -25892(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25892);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003D298:
    ctx->pc = 0x8003D298u;
    // 8003D298: bl      0x8001DAF8
    {
            ctx->lr = 0x8003D29Cu;
            ctx->pc = 0x8001DAF8u;
            return;
    }

label_8003D29C:
    ctx->pc = 0x8003D29Cu;
    ctx->downcount -= 2;
    // 8003D29C: li      r4, 5
    ctx->gpr[4] = (u32)(s32)(5);

label_8003D2A0:
    ctx->pc = 0x8003D2A0u;
    // 8003D2A0: bl      0x8004C4C8
    {
            ctx->lr = 0x8003D2A4u;
            ctx->pc = 0x8004C4C8u;
            return;
    }

label_8003D2A4:
    ctx->pc = 0x8003D2A4u;
    ctx->downcount -= 4;
    // 8003D2A4: lwz     r3, -25892(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25892);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003D2A8:
    ctx->pc = 0x8003D2A8u;
    // 8003D2A8: addi    r4, r1, 36
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(36);

label_8003D2AC:
    ctx->pc = 0x8003D2ACu;
    // 8003D2AC: addi    r5, r1, 32
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(32);

label_8003D2B0:
    ctx->pc = 0x8003D2B0u;
    // 8003D2B0: bl      0x8001D96C
    {
            ctx->lr = 0x8003D2B4u;
            ctx->pc = 0x8001D96Cu;
            return;
    }

label_8003D2B4:
    ctx->pc = 0x8003D2B4u;
    ctx->downcount -= 3;
    // 8003D2B4: lwz     r0, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003D2B8:
    ctx->pc = 0x8003D2B8u;
    // 8003D2B8: cmpwi   r0, 2
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003D2BC:
    ctx->pc = 0x8003D2BCu;
    // 8003D2BC: bc    4, 2, 0x8003D2DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003D2DC;
        }
    }

label_8003D2C0:
    ctx->pc = 0x8003D2C0u;
    ctx->downcount -= 6;
    // 8003D2C0: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003D2C4:
    ctx->pc = 0x8003D2C4u;
    // 8003D2C4: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_8003D2C8:
    ctx->pc = 0x8003D2C8u;
    // 8003D2C8: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_8003D2CC:
    ctx->pc = 0x8003D2CCu;
    // 8003D2CC: li      r6, 8
    ctx->gpr[6] = (u32)(s32)(8);

label_8003D2D0:
    ctx->pc = 0x8003D2D0u;
    // 8003D2D0: li      r7, 15
    ctx->gpr[7] = (u32)(s32)(15);

label_8003D2D4:
    ctx->pc = 0x8003D2D4u;
    // 8003D2D4: bl      0x8025C3B0
    {
            ctx->lr = 0x8003D2D8u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_8003D2D8:
    ctx->pc = 0x8003D2D8u;
    ctx->downcount -= 1;
    // 8003D2D8: b       0x8003D36C
    {
            goto label_8003D36C;
    }

label_8003D2DC:
    ctx->pc = 0x8003D2DCu;
    ctx->downcount -= 2;
    // 8003D2DC: cmpwi   r0, 3
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

label_8003D2E0:
    ctx->pc = 0x8003D2E0u;
    // 8003D2E0: bc    4, 2, 0x8003D300
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003D300;
        }
    }

label_8003D2E4:
    ctx->pc = 0x8003D2E4u;
    ctx->downcount -= 6;
    // 8003D2E4: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003D2E8:
    ctx->pc = 0x8003D2E8u;
    // 8003D2E8: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_8003D2EC:
    ctx->pc = 0x8003D2ECu;
    // 8003D2EC: li      r5, 15
    ctx->gpr[5] = (u32)(s32)(15);

label_8003D2F0:
    ctx->pc = 0x8003D2F0u;
    // 8003D2F0: li      r6, 8
    ctx->gpr[6] = (u32)(s32)(8);

label_8003D2F4:
    ctx->pc = 0x8003D2F4u;
    // 8003D2F4: li      r7, 15
    ctx->gpr[7] = (u32)(s32)(15);

label_8003D2F8:
    ctx->pc = 0x8003D2F8u;
    // 8003D2F8: bl      0x8025C3B0
    {
            ctx->lr = 0x8003D2FCu;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_8003D2FC:
    ctx->pc = 0x8003D2FCu;
    ctx->downcount -= 1;
    // 8003D2FC: b       0x8003D36C
    {
            goto label_8003D36C;
    }

label_8003D300:
    ctx->pc = 0x8003D300u;
    ctx->downcount -= 2;
    // 8003D300: cmpwi   r0, 1
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

label_8003D304:
    ctx->pc = 0x8003D304u;
    // 8003D304: bc    4, 2, 0x8003D324
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003D324;
        }
    }

label_8003D308:
    ctx->pc = 0x8003D308u;
    ctx->downcount -= 6;
    // 8003D308: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003D30C:
    ctx->pc = 0x8003D30Cu;
    // 8003D30C: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_8003D310:
    ctx->pc = 0x8003D310u;
    // 8003D310: li      r5, 15
    ctx->gpr[5] = (u32)(s32)(15);

label_8003D314:
    ctx->pc = 0x8003D314u;
    // 8003D314: li      r6, 8
    ctx->gpr[6] = (u32)(s32)(8);

label_8003D318:
    ctx->pc = 0x8003D318u;
    // 8003D318: li      r7, 4
    ctx->gpr[7] = (u32)(s32)(4);

label_8003D31C:
    ctx->pc = 0x8003D31Cu;
    // 8003D31C: bl      0x8025C3B0
    {
            ctx->lr = 0x8003D320u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_8003D320:
    ctx->pc = 0x8003D320u;
    ctx->downcount -= 1;
    // 8003D320: b       0x8003D36C
    {
            goto label_8003D36C;
    }

label_8003D324:
    ctx->pc = 0x8003D324u;
    ctx->downcount -= 3;
    // 8003D324: lbz     r0, -25896(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25896);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003D328:
    ctx->pc = 0x8003D328u;
    // 8003D328: cmplwi  r0, 0x0000
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

label_8003D32C:
    ctx->pc = 0x8003D32Cu;
    // 8003D32C: bc    12, 2, 0x8003D338
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003D338;
        }
    }

label_8003D330:
    ctx->pc = 0x8003D330u;
    ctx->downcount -= 2;
    // 8003D330: cmplwi  r0, 0x0001
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

label_8003D334:
    ctx->pc = 0x8003D334u;
    // 8003D334: bc    4, 2, 0x8003D354
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003D354;
        }
    }

label_8003D338:
    ctx->pc = 0x8003D338u;
    ctx->downcount -= 6;
    // 8003D338: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003D33C:
    ctx->pc = 0x8003D33Cu;
    // 8003D33C: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_8003D340:
    ctx->pc = 0x8003D340u;
    // 8003D340: li      r5, 10
    ctx->gpr[5] = (u32)(s32)(10);

label_8003D344:
    ctx->pc = 0x8003D344u;
    // 8003D344: li      r6, 8
    ctx->gpr[6] = (u32)(s32)(8);

label_8003D348:
    ctx->pc = 0x8003D348u;
    // 8003D348: li      r7, 4
    ctx->gpr[7] = (u32)(s32)(4);

label_8003D34C:
    ctx->pc = 0x8003D34Cu;
    // 8003D34C: bl      0x8025C3B0
    {
            ctx->lr = 0x8003D350u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_8003D350:
    ctx->pc = 0x8003D350u;
    ctx->downcount -= 1;
    // 8003D350: b       0x8003D36C
    {
            goto label_8003D36C;
    }

label_8003D354:
    ctx->pc = 0x8003D354u;
    ctx->downcount -= 6;
    // 8003D354: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003D358:
    ctx->pc = 0x8003D358u;
    // 8003D358: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_8003D35C:
    ctx->pc = 0x8003D35Cu;
    // 8003D35C: li      r5, 11
    ctx->gpr[5] = (u32)(s32)(11);

label_8003D360:
    ctx->pc = 0x8003D360u;
    // 8003D360: li      r6, 8
    ctx->gpr[6] = (u32)(s32)(8);

label_8003D364:
    ctx->pc = 0x8003D364u;
    // 8003D364: li      r7, 4
    ctx->gpr[7] = (u32)(s32)(4);

label_8003D368:
    ctx->pc = 0x8003D368u;
    // 8003D368: bl      0x8025C3B0
    {
            ctx->lr = 0x8003D36Cu;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_8003D36C:
    ctx->pc = 0x8003D36Cu;
    ctx->downcount -= 4;
    // 8003D36C: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003D370:
    ctx->pc = 0x8003D370u;
    // 8003D370: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003D374:
    ctx->pc = 0x8003D374u;
    // 8003D374: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003D378:
    ctx->pc = 0x8003D378u;
    // 8003D378: bl      0x8025C868
    {
            ctx->lr = 0x8003D37Cu;
            ctx->pc = 0x8025C868u;
            return;
    }

label_8003D37C:
    ctx->pc = 0x8003D37Cu;
    ctx->downcount -= 3;
    // 8003D37C: lwz     r0, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003D380:
    ctx->pc = 0x8003D380u;
    // 8003D380: cmpwi   r0, 1
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

label_8003D384:
    ctx->pc = 0x8003D384u;
    // 8003D384: bc    4, 2, 0x8003D3A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003D3A8;
        }
    }

label_8003D388:
    ctx->pc = 0x8003D388u;
    ctx->downcount -= 7;
    // 8003D388: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003D38C:
    ctx->pc = 0x8003D38Cu;
    // 8003D38C: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8003D390:
    ctx->pc = 0x8003D390u;
    // 8003D390: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003D394:
    ctx->pc = 0x8003D394u;
    // 8003D394: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8003D398:
    ctx->pc = 0x8003D398u;
    // 8003D398: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8003D39C:
    ctx->pc = 0x8003D39Cu;
    // 8003D39C: li      r8, 2
    ctx->gpr[8] = (u32)(s32)(2);

label_8003D3A0:
    ctx->pc = 0x8003D3A0u;
    // 8003D3A0: bl      0x8025C4B4
    {
            ctx->lr = 0x8003D3A4u;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_8003D3A4:
    ctx->pc = 0x8003D3A4u;
    ctx->downcount -= 1;
    // 8003D3A4: b       0x8003D3C4
    {
            goto label_8003D3C4;
    }

label_8003D3A8:
    ctx->pc = 0x8003D3A8u;
    ctx->downcount -= 7;
    // 8003D3A8: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003D3AC:
    ctx->pc = 0x8003D3ACu;
    // 8003D3AC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003D3B0:
    ctx->pc = 0x8003D3B0u;
    // 8003D3B0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003D3B4:
    ctx->pc = 0x8003D3B4u;
    // 8003D3B4: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8003D3B8:
    ctx->pc = 0x8003D3B8u;
    // 8003D3B8: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8003D3BC:
    ctx->pc = 0x8003D3BCu;
    // 8003D3BC: li      r8, 2
    ctx->gpr[8] = (u32)(s32)(2);

label_8003D3C0:
    ctx->pc = 0x8003D3C0u;
    // 8003D3C0: bl      0x8025C4B4
    {
            ctx->lr = 0x8003D3C4u;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_8003D3C4:
    ctx->pc = 0x8003D3C4u;
    ctx->downcount -= 6;
    // 8003D3C4: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003D3C8:
    ctx->pc = 0x8003D3C8u;
    // 8003D3C8: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_8003D3CC:
    ctx->pc = 0x8003D3CCu;
    // 8003D3CC: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_8003D3D0:
    ctx->pc = 0x8003D3D0u;
    // 8003D3D0: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_8003D3D4:
    ctx->pc = 0x8003D3D4u;
    // 8003D3D4: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8003D3D8:
    ctx->pc = 0x8003D3D8u;
    // 8003D3D8: bl      0x8025C430
    {
            ctx->lr = 0x8003D3DCu;
            ctx->pc = 0x8025C430u;
            return;
    }

label_8003D3DC:
    ctx->pc = 0x8003D3DCu;
    ctx->downcount -= 7;
    // 8003D3DC: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003D3E0:
    ctx->pc = 0x8003D3E0u;
    // 8003D3E0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003D3E4:
    ctx->pc = 0x8003D3E4u;
    // 8003D3E4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003D3E8:
    ctx->pc = 0x8003D3E8u;
    // 8003D3E8: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8003D3EC:
    ctx->pc = 0x8003D3ECu;
    // 8003D3EC: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8003D3F0:
    ctx->pc = 0x8003D3F0u;
    // 8003D3F0: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8003D3F4:
    ctx->pc = 0x8003D3F4u;
    // 8003D3F4: bl      0x8025C574
    {
            ctx->lr = 0x8003D3F8u;
            ctx->pc = 0x8025C574u;
            return;
    }

label_8003D3F8:
    ctx->pc = 0x8003D3F8u;
    ctx->downcount -= 3;
    // 8003D3F8: li      r30, 3
    ctx->gpr[30] = (u32)(s32)(3);

label_8003D3FC:
    ctx->pc = 0x8003D3FCu;
    // 8003D3FC: li      r27, 5
    ctx->gpr[27] = (u32)(s32)(5);

label_8003D400:
    ctx->pc = 0x8003D400u;
    // 8003D400: b       0x8003D40C
    {
            goto label_8003D40C;
    }

label_8003D404:
    ctx->pc = 0x8003D404u;
    ctx->downcount -= 2;
    // 8003D404: li      r30, 2
    ctx->gpr[30] = (u32)(s32)(2);

label_8003D408:
    ctx->pc = 0x8003D408u;
    // 8003D408: li      r27, 1
    ctx->gpr[27] = (u32)(s32)(1);

label_8003D40C:
    ctx->pc = 0x8003D40Cu;
    ctx->downcount -= 2;
    // 8003D40C: addi    r3, r1, 48
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(48);

label_8003D410:
    ctx->pc = 0x8003D410u;
    // 8003D410: bl      0x8006C7C8
    {
            ctx->lr = 0x8003D414u;
            ctx->pc = 0x8006C7C8u;
            return;
    }

label_8003D414:
    ctx->pc = 0x8003D414u;
    ctx->downcount -= 3;
    // 8003D414: lwz     r3, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003D418:
    ctx->pc = 0x8003D418u;
    // 8003D418: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_8003D41C:
    ctx->pc = 0x8003D41Cu;
    // 8003D41C: bl      0x8004C4C8
    {
            ctx->lr = 0x8003D420u;
            ctx->pc = 0x8004C4C8u;
            return;
    }

label_8003D420:
    ctx->pc = 0x8003D420u;
    ctx->downcount -= 3;
    // 8003D420: addi    r3, r1, 44
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(44);

label_8003D424:
    ctx->pc = 0x8003D424u;
    // 8003D424: addi    r4, r1, 40
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(40);

label_8003D428:
    ctx->pc = 0x8003D428u;
    // 8003D428: bl      0x8006CCA0
    {
            ctx->lr = 0x8003D42Cu;
            ctx->pc = 0x8006CCA0u;
            return;
    }

label_8003D42C:
    ctx->pc = 0x8003D42Cu;
    ctx->downcount -= 8;
    // 8003D42C: addi    r3, r1, 124
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(124);

label_8003D430:
    ctx->pc = 0x8003D430u;
    // 8003D430: lfs     f2, -31440(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003D430u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31440);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8003D434:
    ctx->pc = 0x8003D434u;
    // 8003D434: lfs     f0, 44(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003D434u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003D438:
    ctx->pc = 0x8003D438u;
    // 8003D438: fmuls   f1, f2, f0
    if (!ppc_fp_available_inline(ctx, 0x8003D438u)) return;
    ppc_fmuls(ctx, 1, 2, 0);

label_8003D43C:
    ctx->pc = 0x8003D43Cu;
    // 8003D43C: lfs     f0, 40(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003D43Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003D440:
    ctx->pc = 0x8003D440u;
    // 8003D440: fmuls   f2, f2, f0
    if (!ppc_fp_available_inline(ctx, 0x8003D440u)) return;
    ppc_fmuls(ctx, 2, 2, 0);

label_8003D444:
    ctx->pc = 0x8003D444u;
    // 8003D444: lfs     f3, -31476(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003D444u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31476);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8003D448:
    ctx->pc = 0x8003D448u;
    // 8003D448: bl      0x80247C90
    {
            ctx->lr = 0x8003D44Cu;
            ctx->pc = 0x80247C90u;
            return;
    }

label_8003D44C:
    ctx->pc = 0x8003D44Cu;
    ctx->downcount -= 7;
    // 8003D44C: lfs     f0, -31452(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003D44Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31452);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003D450:
    ctx->pc = 0x8003D450u;
    // 8003D450: stfs     f0, 124(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003D450u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(124);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003D454:
    ctx->pc = 0x8003D454u;
    // 8003D454: stfs     f0, 144(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003D454u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003D458:
    ctx->pc = 0x8003D458u;
    // 8003D458: addi    r3, r1, 124
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(124);

label_8003D45C:
    ctx->pc = 0x8003D45Cu;
    // 8003D45C: li      r4, 70
    ctx->gpr[4] = (u32)(s32)(70);

label_8003D460:
    ctx->pc = 0x8003D460u;
    // 8003D460: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003D464:
    ctx->pc = 0x8003D464u;
    // 8003D464: bl      0x8025DAD0
    {
            ctx->lr = 0x8003D468u;
            ctx->pc = 0x8025DAD0u;
            return;
    }

label_8003D468:
    ctx->pc = 0x8003D468u;
    ctx->downcount -= 7;
    // 8003D468: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8003D46C:
    ctx->pc = 0x8003D46Cu;
    // 8003D46C: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8003D470:
    ctx->pc = 0x8003D470u;
    // 8003D470: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_8003D474:
    ctx->pc = 0x8003D474u;
    // 8003D474: li      r6, 60
    ctx->gpr[6] = (u32)(s32)(60);

label_8003D478:
    ctx->pc = 0x8003D478u;
    // 8003D478: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8003D47C:
    ctx->pc = 0x8003D47Cu;
    // 8003D47C: li      r8, 70
    ctx->gpr[8] = (u32)(s32)(70);

label_8003D480:
    ctx->pc = 0x8003D480u;
    // 8003D480: bl      0x80258880
    {
            ctx->lr = 0x8003D484u;
            ctx->pc = 0x80258880u;
            return;
    }

label_8003D484:
    ctx->pc = 0x8003D484u;
    ctx->downcount -= 4;
    // 8003D484: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003D488:
    ctx->pc = 0x8003D488u;
    // 8003D488: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8003D48C:
    ctx->pc = 0x8003D48Cu;
    // 8003D48C: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_8003D490:
    ctx->pc = 0x8003D490u;
    // 8003D490: bl      0x8025BF28
    {
            ctx->lr = 0x8003D494u;
            ctx->pc = 0x8025BF28u;
            return;
    }

label_8003D494:
    ctx->pc = 0x8003D494u;
    ctx->downcount -= 4;
    // 8003D494: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003D498:
    ctx->pc = 0x8003D498u;
    // 8003D498: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003D49C:
    ctx->pc = 0x8003D49Cu;
    // 8003D49C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003D4A0:
    ctx->pc = 0x8003D4A0u;
    // 8003D4A0: bl      0x8025BD54
    {
            ctx->lr = 0x8003D4A4u;
            ctx->pc = 0x8025BD54u;
            return;
    }

label_8003D4A4:
    ctx->pc = 0x8003D4A4u;
    ctx->downcount -= 7;
    // 8003D4A4: stfs     f31, 100(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003D4A4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(100);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8003D4A8:
    ctx->pc = 0x8003D4A8u;
    // 8003D4A8: stfs     f31, 116(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003D4A8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(116);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8003D4AC:
    ctx->pc = 0x8003D4ACu;
    // 8003D4AC: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003D4B0:
    ctx->pc = 0x8003D4B0u;
    // 8003D4B0: addi    r4, r1, 100
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(100);

label_8003D4B4:
    ctx->pc = 0x8003D4B4u;
    // 8003D4B4: lwz     r0, -32004(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32004);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003D4B8:
    ctx->pc = 0x8003D4B8u;
    // 8003D4B8: extsb r5, r0
    {
        ctx->gpr[5] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8003D4BC:
    ctx->pc = 0x8003D4BCu;
    // 8003D4BC: bl      0x8025BBF4
    {
            ctx->lr = 0x8003D4C0u;
            ctx->pc = 0x8025BBF4u;
            return;
    }

label_8003D4C0:
    ctx->pc = 0x8003D4C0u;
    ctx->downcount -= 12;
    // 8003D4C0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8003D4C4:
    ctx->pc = 0x8003D4C4u;
    // 8003D4C4: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003D4C8:
    ctx->pc = 0x8003D4C8u;
    // 8003D4C8: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003D4CC:
    ctx->pc = 0x8003D4CCu;
    // 8003D4CC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8003D4D0:
    ctx->pc = 0x8003D4D0u;
    // 8003D4D0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003D4D4:
    ctx->pc = 0x8003D4D4u;
    // 8003D4D4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003D4D8:
    ctx->pc = 0x8003D4D8u;
    // 8003D4D8: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_8003D4DC:
    ctx->pc = 0x8003D4DCu;
    // 8003D4DC: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8003D4E0:
    ctx->pc = 0x8003D4E0u;
    // 8003D4E0: li      r8, 6
    ctx->gpr[8] = (u32)(s32)(6);

label_8003D4E4:
    ctx->pc = 0x8003D4E4u;
    // 8003D4E4: li      r9, 6
    ctx->gpr[9] = (u32)(s32)(6);

label_8003D4E8:
    ctx->pc = 0x8003D4E8u;
    // 8003D4E8: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_8003D4EC:
    ctx->pc = 0x8003D4ECu;
    // 8003D4EC: bl      0x8025BB58
    {
            ctx->lr = 0x8003D4F0u;
            ctx->pc = 0x8025BB58u;
            return;
    }

label_8003D4F0:
    ctx->pc = 0x8003D4F0u;
    ctx->downcount -= 5;
    // 8003D4F0: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8003D4F4:
    ctx->pc = 0x8003D4F4u;
    // 8003D4F4: li      r4, 255
    ctx->gpr[4] = (u32)(s32)(255);

label_8003D4F8:
    ctx->pc = 0x8003D4F8u;
    // 8003D4F8: li      r5, 255
    ctx->gpr[5] = (u32)(s32)(255);

label_8003D4FC:
    ctx->pc = 0x8003D4FCu;
    // 8003D4FC: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_8003D500:
    ctx->pc = 0x8003D500u;
    // 8003D500: bl      0x8025CA34
    {
            ctx->lr = 0x8003D504u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_8003D504:
    ctx->pc = 0x8003D504u;
    ctx->downcount -= 4;
    // 8003D504: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8003D508:
    ctx->pc = 0x8003D508u;
    // 8003D508: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003D50C:
    ctx->pc = 0x8003D50Cu;
    // 8003D50C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003D510:
    ctx->pc = 0x8003D510u;
    // 8003D510: bl      0x8025C868
    {
            ctx->lr = 0x8003D514u;
            ctx->pc = 0x8025C868u;
            return;
    }

label_8003D514:
    ctx->pc = 0x8003D514u;
    ctx->downcount -= 6;
    // 8003D514: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8003D518:
    ctx->pc = 0x8003D518u;
    // 8003D518: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_8003D51C:
    ctx->pc = 0x8003D51Cu;
    // 8003D51C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003D520:
    ctx->pc = 0x8003D520u;
    // 8003D520: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_8003D524:
    ctx->pc = 0x8003D524u;
    // 8003D524: li      r7, 15
    ctx->gpr[7] = (u32)(s32)(15);

label_8003D528:
    ctx->pc = 0x8003D528u;
    // 8003D528: bl      0x8025C3B0
    {
            ctx->lr = 0x8003D52Cu;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_8003D52C:
    ctx->pc = 0x8003D52Cu;
    ctx->downcount -= 6;
    // 8003D52C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8003D530:
    ctx->pc = 0x8003D530u;
    // 8003D530: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_8003D534:
    ctx->pc = 0x8003D534u;
    // 8003D534: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_8003D538:
    ctx->pc = 0x8003D538u;
    // 8003D538: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_8003D53C:
    ctx->pc = 0x8003D53Cu;
    // 8003D53C: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8003D540:
    ctx->pc = 0x8003D540u;
    // 8003D540: bl      0x8025C430
    {
            ctx->lr = 0x8003D544u;
            ctx->pc = 0x8025C430u;
            return;
    }

label_8003D544:
    ctx->pc = 0x8003D544u;
    ctx->downcount -= 7;
    // 8003D544: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8003D548:
    ctx->pc = 0x8003D548u;
    // 8003D548: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003D54C:
    ctx->pc = 0x8003D54Cu;
    // 8003D54C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003D550:
    ctx->pc = 0x8003D550u;
    // 8003D550: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8003D554:
    ctx->pc = 0x8003D554u;
    // 8003D554: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8003D558:
    ctx->pc = 0x8003D558u;
    // 8003D558: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8003D55C:
    ctx->pc = 0x8003D55Cu;
    // 8003D55C: bl      0x8025C4B4
    {
            ctx->lr = 0x8003D560u;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_8003D560:
    ctx->pc = 0x8003D560u;
    ctx->downcount -= 7;
    // 8003D560: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8003D564:
    ctx->pc = 0x8003D564u;
    // 8003D564: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003D568:
    ctx->pc = 0x8003D568u;
    // 8003D568: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003D56C:
    ctx->pc = 0x8003D56Cu;
    // 8003D56C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8003D570:
    ctx->pc = 0x8003D570u;
    // 8003D570: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8003D574:
    ctx->pc = 0x8003D574u;
    // 8003D574: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8003D578:
    ctx->pc = 0x8003D578u;
    // 8003D578: bl      0x8025C574
    {
            ctx->lr = 0x8003D57Cu;
            ctx->pc = 0x8025C574u;
            return;
    }

label_8003D57C:
    ctx->pc = 0x8003D57Cu;
    ctx->downcount -= 3;
    // 8003D57C: lwz     r3, 56(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(56);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003D580:
    ctx->pc = 0x8003D580u;
    // 8003D580: cmplwi  r3, 0x0000
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

label_8003D584:
    ctx->pc = 0x8003D584u;
    // 8003D584: bc    12, 2, 0x8003D624
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003D624;
        }
    }

label_8003D588:
    ctx->pc = 0x8003D588u;
    ctx->downcount -= 1;
    // 8003D588: bl      0x800538A4
    {
            ctx->lr = 0x8003D58Cu;
            ctx->pc = 0x800538A4u;
            return;
    }

label_8003D58C:
    ctx->pc = 0x8003D58Cu;
    ctx->downcount -= 2;
    // 8003D58C: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_8003D590:
    ctx->pc = 0x8003D590u;
    // 8003D590: bl      0x8004C4C8
    {
            ctx->lr = 0x8003D594u;
            ctx->pc = 0x8004C4C8u;
            return;
    }

label_8003D594:
    ctx->pc = 0x8003D594u;
    ctx->downcount -= 7;
    // 8003D594: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_8003D598:
    ctx->pc = 0x8003D598u;
    // 8003D598: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8003D59C:
    ctx->pc = 0x8003D59Cu;
    // 8003D59C: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_8003D5A0:
    ctx->pc = 0x8003D5A0u;
    // 8003D5A0: li      r6, 60
    ctx->gpr[6] = (u32)(s32)(60);

label_8003D5A4:
    ctx->pc = 0x8003D5A4u;
    // 8003D5A4: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8003D5A8:
    ctx->pc = 0x8003D5A8u;
    // 8003D5A8: li      r8, 125
    ctx->gpr[8] = (u32)(s32)(125);

label_8003D5AC:
    ctx->pc = 0x8003D5ACu;
    // 8003D5AC: bl      0x80258880
    {
            ctx->lr = 0x8003D5B0u;
            ctx->pc = 0x80258880u;
            return;
    }

label_8003D5B0:
    ctx->pc = 0x8003D5B0u;
    ctx->downcount -= 4;
    // 8003D5B0: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003D5B4:
    ctx->pc = 0x8003D5B4u;
    // 8003D5B4: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_8003D5B8:
    ctx->pc = 0x8003D5B8u;
    // 8003D5B8: li      r5, 2
    ctx->gpr[5] = (u32)(s32)(2);

label_8003D5BC:
    ctx->pc = 0x8003D5BCu;
    // 8003D5BC: bl      0x8025BF28
    {
            ctx->lr = 0x8003D5C0u;
            ctx->pc = 0x8025BF28u;
            return;
    }

label_8003D5C0:
    ctx->pc = 0x8003D5C0u;
    ctx->downcount -= 4;
    // 8003D5C0: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003D5C4:
    ctx->pc = 0x8003D5C4u;
    // 8003D5C4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003D5C8:
    ctx->pc = 0x8003D5C8u;
    // 8003D5C8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003D5CC:
    ctx->pc = 0x8003D5CCu;
    // 8003D5CC: bl      0x8025BD54
    {
            ctx->lr = 0x8003D5D0u;
            ctx->pc = 0x8025BD54u;
            return;
    }

label_8003D5D0:
    ctx->pc = 0x8003D5D0u;
    ctx->downcount -= 7;
    // 8003D5D0: stfs     f31, 80(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003D5D0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8003D5D4:
    ctx->pc = 0x8003D5D4u;
    // 8003D5D4: stfs     f31, 96(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003D5D4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8003D5D8:
    ctx->pc = 0x8003D5D8u;
    // 8003D5D8: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003D5DC:
    ctx->pc = 0x8003D5DCu;
    // 8003D5DC: addi    r4, r1, 76
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(76);

label_8003D5E0:
    ctx->pc = 0x8003D5E0u;
    // 8003D5E0: lwz     r0, -32000(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32000);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003D5E4:
    ctx->pc = 0x8003D5E4u;
    // 8003D5E4: extsb r5, r0
    {
        ctx->gpr[5] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_8003D5E8:
    ctx->pc = 0x8003D5E8u;
    // 8003D5E8: bl      0x8025BBF4
    {
            ctx->lr = 0x8003D5ECu;
            ctx->pc = 0x8025BBF4u;
            return;
    }

label_8003D5EC:
    ctx->pc = 0x8003D5ECu;
    ctx->downcount -= 13;
    // 8003D5EC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8003D5F0:
    ctx->pc = 0x8003D5F0u;
    // 8003D5F0: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003D5F4:
    ctx->pc = 0x8003D5F4u;
    // 8003D5F4: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8003D5F8:
    ctx->pc = 0x8003D5F8u;
    // 8003D5F8: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003D5FC:
    ctx->pc = 0x8003D5FCu;
    // 8003D5FC: addi    r3, r30, 1
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(1);

label_8003D600:
    ctx->pc = 0x8003D600u;
    // 8003D600: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8003D604:
    ctx->pc = 0x8003D604u;
    // 8003D604: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003D608:
    ctx->pc = 0x8003D608u;
    // 8003D608: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_8003D60C:
    ctx->pc = 0x8003D60Cu;
    // 8003D60C: li      r7, 2
    ctx->gpr[7] = (u32)(s32)(2);

label_8003D610:
    ctx->pc = 0x8003D610u;
    // 8003D610: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8003D614:
    ctx->pc = 0x8003D614u;
    // 8003D614: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_8003D618:
    ctx->pc = 0x8003D618u;
    // 8003D618: li      r10, 1
    ctx->gpr[10] = (u32)(s32)(1);

label_8003D61C:
    ctx->pc = 0x8003D61Cu;
    // 8003D61C: bl      0x8025BB58
    {
            ctx->lr = 0x8003D620u;
            ctx->pc = 0x8025BB58u;
            return;
    }

label_8003D620:
    ctx->pc = 0x8003D620u;
    ctx->downcount -= 1;
    // 8003D620: b       0x8003D690
    {
            goto label_8003D690;
    }

label_8003D624:
    ctx->pc = 0x8003D624u;
    ctx->downcount -= 4;
    // 8003D624: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003D628:
    ctx->pc = 0x8003D628u;
    // 8003D628: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_8003D62C:
    ctx->pc = 0x8003D62Cu;
    // 8003D62C: li      r5, 2
    ctx->gpr[5] = (u32)(s32)(2);

label_8003D630:
    ctx->pc = 0x8003D630u;
    // 8003D630: bl      0x8025BF28
    {
            ctx->lr = 0x8003D634u;
            ctx->pc = 0x8025BF28u;
            return;
    }

label_8003D634:
    ctx->pc = 0x8003D634u;
    ctx->downcount -= 4;
    // 8003D634: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003D638:
    ctx->pc = 0x8003D638u;
    // 8003D638: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003D63C:
    ctx->pc = 0x8003D63Cu;
    // 8003D63C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003D640:
    ctx->pc = 0x8003D640u;
    // 8003D640: bl      0x8025BD54
    {
            ctx->lr = 0x8003D644u;
            ctx->pc = 0x8025BD54u;
            return;
    }

label_8003D644:
    ctx->pc = 0x8003D644u;
    ctx->downcount -= 7;
    // 8003D644: lfs     f0, -31476(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003D644u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31476);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003D648:
    ctx->pc = 0x8003D648u;
    // 8003D648: stfs     f0, 80(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003D648u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003D64C:
    ctx->pc = 0x8003D64Cu;
    // 8003D64C: stfs     f0, 96(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003D64Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003D650:
    ctx->pc = 0x8003D650u;
    // 8003D650: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003D654:
    ctx->pc = 0x8003D654u;
    // 8003D654: addi    r4, r1, 76
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(76);

label_8003D658:
    ctx->pc = 0x8003D658u;
    // 8003D658: li      r5, -15
    ctx->gpr[5] = (u32)(s32)(-15);

label_8003D65C:
    ctx->pc = 0x8003D65Cu;
    // 8003D65C: bl      0x8025BBF4
    {
            ctx->lr = 0x8003D660u;
            ctx->pc = 0x8025BBF4u;
            return;
    }

label_8003D660:
    ctx->pc = 0x8003D660u;
    ctx->downcount -= 12;
    // 8003D660: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8003D664:
    ctx->pc = 0x8003D664u;
    // 8003D664: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003D668:
    ctx->pc = 0x8003D668u;
    // 8003D668: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003D66C:
    ctx->pc = 0x8003D66Cu;
    // 8003D66C: addi    r3, r30, 1
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(1);

label_8003D670:
    ctx->pc = 0x8003D670u;
    // 8003D670: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8003D674:
    ctx->pc = 0x8003D674u;
    // 8003D674: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003D678:
    ctx->pc = 0x8003D678u;
    // 8003D678: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_8003D67C:
    ctx->pc = 0x8003D67Cu;
    // 8003D67C: li      r7, 2
    ctx->gpr[7] = (u32)(s32)(2);

label_8003D680:
    ctx->pc = 0x8003D680u;
    // 8003D680: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8003D684:
    ctx->pc = 0x8003D684u;
    // 8003D684: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_8003D688:
    ctx->pc = 0x8003D688u;
    // 8003D688: li      r10, 1
    ctx->gpr[10] = (u32)(s32)(1);

label_8003D68C:
    ctx->pc = 0x8003D68Cu;
    // 8003D68C: bl      0x8025BB58
    {
            ctx->lr = 0x8003D690u;
            ctx->pc = 0x8025BB58u;
            return;
    }

label_8003D690:
    ctx->pc = 0x8003D690u;
    ctx->downcount -= 6;
    // 8003D690: lwz     r3, 56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003D694:
    ctx->pc = 0x8003D694u;
    // 8003D694: lwz     r0, -25924(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25924);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003D698:
    ctx->pc = 0x8003D698u;
    // 8003D698: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_8003D69C:
    ctx->pc = 0x8003D69Cu;
    // 8003D69C: lwzx    r3, r3, r0
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[0];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003D6A0:
    ctx->pc = 0x8003D6A0u;
    // 8003D6A0: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_8003D6A4:
    ctx->pc = 0x8003D6A4u;
    // 8003D6A4: bl      0x8004C4C8
    {
            ctx->lr = 0x8003D6A8u;
            ctx->pc = 0x8004C4C8u;
            return;
    }

label_8003D6A8:
    ctx->pc = 0x8003D6A8u;
    ctx->downcount -= 5;
    // 8003D6A8: addi    r3, r1, 268
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(268);

label_8003D6AC:
    ctx->pc = 0x8003D6ACu;
    // 8003D6AC: lfs     f1, -31432(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003D6ACu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31432);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003D6B0:
    ctx->pc = 0x8003D6B0u;
    // 8003D6B0: fmr    f2, f1
    if (!ppc_fp_available_inline(ctx, 0x8003D6B0u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_8003D6B4:
    ctx->pc = 0x8003D6B4u;
    // 8003D6B4: lfs     f3, -31452(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003D6B4u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31452);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8003D6B8:
    ctx->pc = 0x8003D6B8u;
    // 8003D6B8: bl      0x80247CC4
    {
            ctx->lr = 0x8003D6BCu;
            ctx->pc = 0x80247CC4u;
            return;
    }

label_8003D6BC:
    ctx->pc = 0x8003D6BCu;
    ctx->downcount -= 4;
    // 8003D6BC: addi    r3, r1, 268
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(268);

label_8003D6C0:
    ctx->pc = 0x8003D6C0u;
    // 8003D6C0: li      r4, 64
    ctx->gpr[4] = (u32)(s32)(64);

label_8003D6C4:
    ctx->pc = 0x8003D6C4u;
    // 8003D6C4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003D6C8:
    ctx->pc = 0x8003D6C8u;
    // 8003D6C8: bl      0x8025DAD0
    {
            ctx->lr = 0x8003D6CCu;
            ctx->pc = 0x8025DAD0u;
            return;
    }

label_8003D6CC:
    ctx->pc = 0x8003D6CCu;
    ctx->downcount -= 7;
    // 8003D6CC: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_8003D6D0:
    ctx->pc = 0x8003D6D0u;
    // 8003D6D0: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8003D6D4:
    ctx->pc = 0x8003D6D4u;
    // 8003D6D4: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_8003D6D8:
    ctx->pc = 0x8003D6D8u;
    // 8003D6D8: li      r6, 60
    ctx->gpr[6] = (u32)(s32)(60);

label_8003D6DC:
    ctx->pc = 0x8003D6DCu;
    // 8003D6DC: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8003D6E0:
    ctx->pc = 0x8003D6E0u;
    // 8003D6E0: li      r8, 64
    ctx->gpr[8] = (u32)(s32)(64);

label_8003D6E4:
    ctx->pc = 0x8003D6E4u;
    // 8003D6E4: bl      0x80258880
    {
            ctx->lr = 0x8003D6E8u;
            ctx->pc = 0x80258880u;
            return;
    }

label_8003D6E8:
    ctx->pc = 0x8003D6E8u;
    ctx->downcount -= 3;
    // 8003D6E8: addi    r3, r30, 1
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(1);

label_8003D6EC:
    ctx->pc = 0x8003D6ECu;
    // 8003D6EC: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_8003D6F0:
    ctx->pc = 0x8003D6F0u;
    // 8003D6F0: bl      0x8025C790
    {
            ctx->lr = 0x8003D6F4u;
            ctx->pc = 0x8025C790u;
            return;
    }

label_8003D6F4:
    ctx->pc = 0x8003D6F4u;
    ctx->downcount -= 3;
    // 8003D6F4: lwz     r0, 56(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(56);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003D6F8:
    ctx->pc = 0x8003D6F8u;
    // 8003D6F8: cmplwi  r0, 0x0000
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

label_8003D6FC:
    ctx->pc = 0x8003D6FCu;
    // 8003D6FC: bc    12, 2, 0x8003D730
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003D730;
        }
    }

label_8003D700:
    ctx->pc = 0x8003D700u;
    ctx->downcount -= 5;
    // 8003D700: addi    r3, r30, 1
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(1);

label_8003D704:
    ctx->pc = 0x8003D704u;
    // 8003D704: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_8003D708:
    ctx->pc = 0x8003D708u;
    // 8003D708: li      r5, 3
    ctx->gpr[5] = (u32)(s32)(3);

label_8003D70C:
    ctx->pc = 0x8003D70Cu;
    // 8003D70C: li      r6, 8
    ctx->gpr[6] = (u32)(s32)(8);

label_8003D710:
    ctx->pc = 0x8003D710u;
    // 8003D710: bl      0x8025CA34
    {
            ctx->lr = 0x8003D714u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_8003D714:
    ctx->pc = 0x8003D714u;
    ctx->downcount -= 6;
    // 8003D714: addi    r3, r30, 1
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(1);

label_8003D718:
    ctx->pc = 0x8003D718u;
    // 8003D718: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_8003D71C:
    ctx->pc = 0x8003D71Cu;
    // 8003D71C: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_8003D720:
    ctx->pc = 0x8003D720u;
    // 8003D720: li      r6, 5
    ctx->gpr[6] = (u32)(s32)(5);

label_8003D724:
    ctx->pc = 0x8003D724u;
    // 8003D724: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8003D728:
    ctx->pc = 0x8003D728u;
    // 8003D728: bl      0x8025C430
    {
            ctx->lr = 0x8003D72Cu;
            ctx->pc = 0x8025C430u;
            return;
    }

label_8003D72C:
    ctx->pc = 0x8003D72Cu;
    ctx->downcount -= 1;
    // 8003D72C: b       0x8003D75C
    {
            goto label_8003D75C;
    }

label_8003D730:
    ctx->pc = 0x8003D730u;
    ctx->downcount -= 5;
    // 8003D730: addi    r3, r30, 1
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(1);

label_8003D734:
    ctx->pc = 0x8003D734u;
    // 8003D734: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_8003D738:
    ctx->pc = 0x8003D738u;
    // 8003D738: li      r5, 3
    ctx->gpr[5] = (u32)(s32)(3);

label_8003D73C:
    ctx->pc = 0x8003D73Cu;
    // 8003D73C: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_8003D740:
    ctx->pc = 0x8003D740u;
    // 8003D740: bl      0x8025CA34
    {
            ctx->lr = 0x8003D744u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_8003D744:
    ctx->pc = 0x8003D744u;
    ctx->downcount -= 6;
    // 8003D744: addi    r3, r30, 1
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(1);

label_8003D748:
    ctx->pc = 0x8003D748u;
    // 8003D748: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_8003D74C:
    ctx->pc = 0x8003D74Cu;
    // 8003D74C: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_8003D750:
    ctx->pc = 0x8003D750u;
    // 8003D750: li      r6, 7
    ctx->gpr[6] = (u32)(s32)(7);

label_8003D754:
    ctx->pc = 0x8003D754u;
    // 8003D754: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8003D758:
    ctx->pc = 0x8003D758u;
    // 8003D758: bl      0x8025C430
    {
            ctx->lr = 0x8003D75Cu;
            ctx->pc = 0x8025C430u;
            return;
    }

label_8003D75C:
    ctx->pc = 0x8003D75Cu;
    ctx->downcount -= 6;
    // 8003D75C: addi    r3, r30, 1
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(1);

label_8003D760:
    ctx->pc = 0x8003D760u;
    // 8003D760: li      r4, 8
    ctx->gpr[4] = (u32)(s32)(8);

label_8003D764:
    ctx->pc = 0x8003D764u;
    // 8003D764: li      r5, 14
    ctx->gpr[5] = (u32)(s32)(14);

label_8003D768:
    ctx->pc = 0x8003D768u;
    // 8003D768: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8003D76C:
    ctx->pc = 0x8003D76Cu;
    // 8003D76C: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8003D770:
    ctx->pc = 0x8003D770u;
    // 8003D770: bl      0x8025C3B0
    {
            ctx->lr = 0x8003D774u;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_8003D774:
    ctx->pc = 0x8003D774u;
    ctx->downcount -= 4;
    // 8003D774: addi    r3, r30, 1
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(1);

label_8003D778:
    ctx->pc = 0x8003D778u;
    // 8003D778: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003D77C:
    ctx->pc = 0x8003D77Cu;
    // 8003D77C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003D780:
    ctx->pc = 0x8003D780u;
    // 8003D780: bl      0x8025C868
    {
            ctx->lr = 0x8003D784u;
            ctx->pc = 0x8025C868u;
            return;
    }

label_8003D784:
    ctx->pc = 0x8003D784u;
    ctx->downcount -= 7;
    // 8003D784: addi    r3, r30, 1
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(1);

label_8003D788:
    ctx->pc = 0x8003D788u;
    // 8003D788: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8003D78C:
    ctx->pc = 0x8003D78Cu;
    // 8003D78C: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_8003D790:
    ctx->pc = 0x8003D790u;
    // 8003D790: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8003D794:
    ctx->pc = 0x8003D794u;
    // 8003D794: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8003D798:
    ctx->pc = 0x8003D798u;
    // 8003D798: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8003D79C:
    ctx->pc = 0x8003D79Cu;
    // 8003D79C: bl      0x8025C4B4
    {
            ctx->lr = 0x8003D7A0u;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_8003D7A0:
    ctx->pc = 0x8003D7A0u;
    ctx->downcount -= 7;
    // 8003D7A0: addi    r3, r30, 1
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(1);

label_8003D7A4:
    ctx->pc = 0x8003D7A4u;
    // 8003D7A4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003D7A8:
    ctx->pc = 0x8003D7A8u;
    // 8003D7A8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003D7AC:
    ctx->pc = 0x8003D7ACu;
    // 8003D7AC: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8003D7B0:
    ctx->pc = 0x8003D7B0u;
    // 8003D7B0: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8003D7B4:
    ctx->pc = 0x8003D7B4u;
    // 8003D7B4: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8003D7B8:
    ctx->pc = 0x8003D7B8u;
    // 8003D7B8: bl      0x8025C574
    {
            ctx->lr = 0x8003D7BCu;
            ctx->pc = 0x8025C574u;
            return;
    }

label_8003D7BC:
    ctx->pc = 0x8003D7BCu;
    ctx->downcount -= 3;
    // 8003D7BC: rlwinm r0, r28, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[28], 0u) & 0x000000FFu;
    }

label_8003D7C0:
    ctx->pc = 0x8003D7C0u;
    // 8003D7C0: cmplwi  r0, 0x0000
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

label_8003D7C4:
    ctx->pc = 0x8003D7C4u;
    // 8003D7C4: bc    12, 2, 0x8003D7DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003D7DC;
        }
    }

label_8003D7C8:
    ctx->pc = 0x8003D7C8u;
    ctx->downcount -= 2;
    // 8003D7C8: li      r3, 5
    ctx->gpr[3] = (u32)(s32)(5);

label_8003D7CC:
    ctx->pc = 0x8003D7CCu;
    // 8003D7CC: bl      0x8025CC10
    {
            ctx->lr = 0x8003D7D0u;
            ctx->pc = 0x8025CC10u;
            return;
    }

label_8003D7D0:
    ctx->pc = 0x8003D7D0u;
    ctx->downcount -= 2;
    // 8003D7D0: li      r3, 6
    ctx->gpr[3] = (u32)(s32)(6);

label_8003D7D4:
    ctx->pc = 0x8003D7D4u;
    // 8003D7D4: bl      0x80258B50
    {
            ctx->lr = 0x8003D7D8u;
            ctx->pc = 0x80258B50u;
            return;
    }

label_8003D7D8:
    ctx->pc = 0x8003D7D8u;
    ctx->downcount -= 1;
    // 8003D7D8: b       0x8003D7EC
    {
            goto label_8003D7EC;
    }

label_8003D7DC:
    ctx->pc = 0x8003D7DCu;
    ctx->downcount -= 2;
    // 8003D7DC: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_8003D7E0:
    ctx->pc = 0x8003D7E0u;
    // 8003D7E0: bl      0x8025CC10
    {
            ctx->lr = 0x8003D7E4u;
            ctx->pc = 0x8025CC10u;
            return;
    }

label_8003D7E4:
    ctx->pc = 0x8003D7E4u;
    ctx->downcount -= 2;
    // 8003D7E4: li      r3, 5
    ctx->gpr[3] = (u32)(s32)(5);

label_8003D7E8:
    ctx->pc = 0x8003D7E8u;
    // 8003D7E8: bl      0x80258B50
    {
            ctx->lr = 0x8003D7ECu;
            ctx->pc = 0x80258B50u;
            return;
    }

label_8003D7EC:
    ctx->pc = 0x8003D7ECu;
    ctx->downcount -= 2;
    // 8003D7EC: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003D7F0:
    ctx->pc = 0x8003D7F0u;
    // 8003D7F0: bl      0x8025C060
    {
            ctx->lr = 0x8003D7F4u;
            ctx->pc = 0x8025C060u;
            return;
    }

label_8003D7F4:
    ctx->pc = 0x8003D7F4u;
    ctx->downcount -= 2;
    // 8003D7F4: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003D7F8:
    ctx->pc = 0x8003D7F8u;
    // 8003D7F8: bl      0x80259494
    {
            ctx->lr = 0x8003D7FCu;
            ctx->pc = 0x80259494u;
            return;
    }

label_8003D7FC:
    ctx->pc = 0x8003D7FCu;
    ctx->downcount -= 5;
    // 8003D7FC: lwz     r3, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003D800:
    ctx->pc = 0x8003D800u;
    // 8003D800: lhz     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8003D804:
    ctx->pc = 0x8003D804u;
    // 8003D804: rlwinm r0, r0, 0, 23, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000100u;
    }

label_8003D808:
    ctx->pc = 0x8003D808u;
    // 8003D808: cmpwi   r0, 0
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

label_8003D80C:
    ctx->pc = 0x8003D80Cu;
    // 8003D80C: bc    12, 2, 0x8003D838
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003D838;
        }
    }

label_8003D810:
    ctx->pc = 0x8003D810u;
    ctx->downcount -= 9;
    // 8003D810: lwz     r0, -32040(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32040);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003D814:
    ctx->pc = 0x8003D814u;
    // 8003D814: stw     r0, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003D818:
    ctx->pc = 0x8003D818u;
    // 8003D818: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003D81C:
    ctx->pc = 0x8003D81Cu;
    // 8003D81C: lfs     f1, -31476(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003D81Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31476);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003D820:
    ctx->pc = 0x8003D820u;
    // 8003D820: fmr    f2, f1
    if (!ppc_fp_available_inline(ctx, 0x8003D820u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_8003D824:
    ctx->pc = 0x8003D824u;
    // 8003D824: fmr    f3, f1
    if (!ppc_fp_available_inline(ctx, 0x8003D824u)) return;
    ctx->fpr[3] = ctx->fpr[1];

label_8003D828:
    ctx->pc = 0x8003D828u;
    // 8003D828: fmr    f4, f1
    if (!ppc_fp_available_inline(ctx, 0x8003D828u)) return;
    ctx->fpr[4] = ctx->fpr[1];

label_8003D82C:
    ctx->pc = 0x8003D82Cu;
    // 8003D82C: addi    r4, r1, 24
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(24);

label_8003D830:
    ctx->pc = 0x8003D830u;
    // 8003D830: bl      0x8025CC44
    {
            ctx->lr = 0x8003D834u;
            ctx->pc = 0x8025CC44u;
            return;
    }

label_8003D834:
    ctx->pc = 0x8003D834u;
    ctx->downcount -= 1;
    // 8003D834: b       0x8003D83C
    {
            goto label_8003D83C;
    }

label_8003D838:
    ctx->pc = 0x8003D838u;
    ctx->downcount -= 1;
    // 8003D838: bl      0x800705A8
    {
            ctx->lr = 0x8003D83Cu;
            ctx->pc = 0x800705A8u;
            return;
    }

label_8003D83C:
    ctx->pc = 0x8003D83Cu;
    ctx->downcount -= 4;
    // 8003D83C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003D840:
    ctx->pc = 0x8003D840u;
    // 8003D840: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_8003D844:
    ctx->pc = 0x8003D844u;
    // 8003D844: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003D848:
    ctx->pc = 0x8003D848u;
    // 8003D848: bl      0x800704F4
    {
            ctx->lr = 0x8003D84Cu;
            ctx->pc = 0x800704F4u;
            return;
    }

label_8003D84C:
    ctx->pc = 0x8003D84Cu;
    ctx->downcount -= 2;
    // 8003D84C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003D850:
    ctx->pc = 0x8003D850u;
    // 8003D850: bl      0x8007049C
    {
            ctx->lr = 0x8003D854u;
            ctx->pc = 0x8007049Cu;
            return;
    }

label_8003D854:
    ctx->pc = 0x8003D854u;
    ctx->downcount -= 5;
    // 8003D854: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003D858:
    ctx->pc = 0x8003D858u;
    // 8003D858: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_8003D85C:
    ctx->pc = 0x8003D85Cu;
    // 8003D85C: li      r5, 5
    ctx->gpr[5] = (u32)(s32)(5);

label_8003D860:
    ctx->pc = 0x8003D860u;
    // 8003D860: li      r6, 5
    ctx->gpr[6] = (u32)(s32)(5);

label_8003D864:
    ctx->pc = 0x8003D864u;
    // 8003D864: bl      0x8025CEF4
    {
            ctx->lr = 0x8003D868u;
            ctx->pc = 0x8025CEF4u;
            return;
    }

label_8003D868:
    ctx->pc = 0x8003D868u;
    ctx->downcount -= 1;
    // 8003D868: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003D86C:
    ctx->pc = 0x8003D86Cu;
    ctx->downcount -= 4;
    // 8003D86C: psq_l   f31, 376(r1), 0, 0
    if (!ppc_fp_available_inline(ctx, 0x8003D86Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(376);
        ppc_psq_load_inline(ctx, 31u, ea, false, 0u, false, 0x8003D86Cu);
        if (ctx->exception) return;
    }

label_8003D870:
    ctx->pc = 0x8003D870u;
    // 8003D870: lfd     f31, 368(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003D870u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(368);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003D874:
    ctx->pc = 0x8003D874u;
    // 8003D874: addi    r11, r1, 368
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(368);

label_8003D878:
    ctx->pc = 0x8003D878u;
    // 8003D878: bl      0x80286A98
    {
            ctx->lr = 0x8003D87Cu;
            ctx->pc = 0x80286A98u;
            return;
    }

label_8003D87C:
    ctx->pc = 0x8003D87Cu;
    ctx->downcount -= 5;
    // 8003D87C: lwz     r0, 388(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(388);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003D880:
    ctx->pc = 0x8003D880u;
    // 8003D880: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8003D884:
    ctx->pc = 0x8003D884u;
    // 8003D884: addi    r1, r1, 384
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(384);

label_8003D888:
    ctx->pc = 0x8003D888u;
    // 8003D888: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8003A6E0;
        }
    }

label_8003D88C:
    ctx->pc = 0x8003D88Cu;
    ctx->downcount -= 10;
    // 8003D88C: stwu     r1, -96(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-96);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8003D890:
    ctx->pc = 0x8003D890u;
    // 8003D890: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8003D894:
    ctx->pc = 0x8003D894u;
    // 8003D894: stw     r0, 100(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(100);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003D898:
    ctx->pc = 0x8003D898u;
    // 8003D898: stw     r31, 92(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8003D89C:
    ctx->pc = 0x8003D89Cu;
    // 8003D89C: stw     r30, 88(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8003D8A0:
    ctx->pc = 0x8003D8A0u;
    // 8003D8A0: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003D8A4:
    ctx->pc = 0x8003D8A4u;
    // 8003D8A4: lwz     r0, -31496(r2)
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31496);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003D8A8:
    ctx->pc = 0x8003D8A8u;
    // 8003D8A8: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003D8AC:
    ctx->pc = 0x8003D8ACu;
    // 8003D8AC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003D8B0:
    ctx->pc = 0x8003D8B0u;
    // 8003D8B0: bl      0x8001F63C
    {
            ctx->lr = 0x8003D8B4u;
            ctx->pc = 0x8001F63Cu;
            return;
    }

label_8003D8B4:
    ctx->pc = 0x8003D8B4u;
    ctx->downcount -= 3;
    // 8003D8B4: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003D8B8:
    ctx->pc = 0x8003D8B8u;
    // 8003D8B8: cmplwi  r31, 0x0000
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

label_8003D8BC:
    ctx->pc = 0x8003D8BCu;
    // 8003D8BC: bc    12, 2, 0x8003D950
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003D950;
        }
    }

label_8003D8C0:
    ctx->pc = 0x8003D8C0u;
    ctx->downcount -= 2;
    // 8003D8C0: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_8003D8C4:
    ctx->pc = 0x8003D8C4u;
    // 8003D8C4: bl      0x8001DCA0
    {
            ctx->lr = 0x8003D8C8u;
            ctx->pc = 0x8001DCA0u;
            return;
    }

label_8003D8C8:
    ctx->pc = 0x8003D8C8u;
    ctx->downcount -= 5;
    // 8003D8C8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8003D8CC:
    ctx->pc = 0x8003D8CCu;
    // 8003D8CC: lfs     f1, -31476(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003D8CCu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31476);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003D8D0:
    ctx->pc = 0x8003D8D0u;
    // 8003D8D0: lfs     f2, -31428(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003D8D0u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31428);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8003D8D4:
    ctx->pc = 0x8003D8D4u;
    // 8003D8D4: fmr    f3, f1
    if (!ppc_fp_available_inline(ctx, 0x8003D8D4u)) return;
    ctx->fpr[3] = ctx->fpr[1];

label_8003D8D8:
    ctx->pc = 0x8003D8D8u;
    // 8003D8D8: bl      0x8001DE04
    {
            ctx->lr = 0x8003D8DCu;
            ctx->pc = 0x8001DE04u;
            return;
    }

label_8003D8DC:
    ctx->pc = 0x8003D8DCu;
    ctx->downcount -= 6;
    // 8003D8DC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8003D8E0:
    ctx->pc = 0x8003D8E0u;
    // 8003D8E0: li      r4, 255
    ctx->gpr[4] = (u32)(s32)(255);

label_8003D8E4:
    ctx->pc = 0x8003D8E4u;
    // 8003D8E4: li      r5, 255
    ctx->gpr[5] = (u32)(s32)(255);

label_8003D8E8:
    ctx->pc = 0x8003D8E8u;
    // 8003D8E8: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_8003D8EC:
    ctx->pc = 0x8003D8ECu;
    // 8003D8EC: li      r7, 255
    ctx->gpr[7] = (u32)(s32)(255);

label_8003D8F0:
    ctx->pc = 0x8003D8F0u;
    // 8003D8F0: bl      0x8001DC64
    {
            ctx->lr = 0x8003D8F4u;
            ctx->pc = 0x8001DC64u;
            return;
    }

label_8003D8F4:
    ctx->pc = 0x8003D8F4u;
    ctx->downcount -= 2;
    // 8003D8F4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003D8F8:
    ctx->pc = 0x8003D8F8u;
    // 8003D8F8: bl      0x8001EA68
    {
            ctx->lr = 0x8003D8FCu;
            ctx->pc = 0x8001EA68u;
            return;
    }

label_8003D8FC:
    ctx->pc = 0x8003D8FCu;
    ctx->downcount -= 4;
    // 8003D8FC: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003D900:
    ctx->pc = 0x8003D900u;
    // 8003D900: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003D904:
    ctx->pc = 0x8003D904u;
    // 8003D904: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003D908:
    ctx->pc = 0x8003D908u;
    // 8003D908: bl      0x8001E77C
    {
            ctx->lr = 0x8003D90Cu;
            ctx->pc = 0x8001E77Cu;
            return;
    }

label_8003D90C:
    ctx->pc = 0x8003D90Cu;
    ctx->downcount -= 5;
    // 8003D90C: lwz     r0, -32032(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32032);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003D910:
    ctx->pc = 0x8003D910u;
    // 8003D910: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003D914:
    ctx->pc = 0x8003D914u;
    // 8003D914: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003D918:
    ctx->pc = 0x8003D918u;
    // 8003D918: addi    r4, r1, 20
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(20);

label_8003D91C:
    ctx->pc = 0x8003D91Cu;
    // 8003D91C: bl      0x8025A4F8
    {
            ctx->lr = 0x8003D920u;
            ctx->pc = 0x8025A4F8u;
            return;
    }

label_8003D920:
    ctx->pc = 0x8003D920u;
    ctx->downcount -= 5;
    // 8003D920: lwz     r0, -32040(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32040);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003D924:
    ctx->pc = 0x8003D924u;
    // 8003D924: stw     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003D928:
    ctx->pc = 0x8003D928u;
    // 8003D928: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003D92C:
    ctx->pc = 0x8003D92Cu;
    // 8003D92C: addi    r4, r1, 16
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(16);

label_8003D930:
    ctx->pc = 0x8003D930u;
    // 8003D930: bl      0x8025A660
    {
            ctx->lr = 0x8003D934u;
            ctx->pc = 0x8025A660u;
            return;
    }

label_8003D934:
    ctx->pc = 0x8003D934u;
    ctx->downcount -= 4;
    // 8003D934: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003D938:
    ctx->pc = 0x8003D938u;
    // 8003D938: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8003D93C:
    ctx->pc = 0x8003D93Cu;
    // 8003D93C: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8003D940:
    ctx->pc = 0x8003D940u;
    // 8003D940: bl      0x8001E618
    {
            ctx->lr = 0x8003D944u;
            ctx->pc = 0x8001E618u;
            return;
    }

label_8003D944:
    ctx->pc = 0x8003D944u;
    ctx->downcount -= 1;
    // 8003D944: bl      0x8001E7A8
    {
            ctx->lr = 0x8003D948u;
            ctx->pc = 0x8001E7A8u;
            return;
    }

label_8003D948:
    ctx->pc = 0x8003D948u;
    ctx->downcount -= 2;
    // 8003D948: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8003D94C:
    ctx->pc = 0x8003D94Cu;
    // 8003D94C: bl      0x8001F4F8
    {
            ctx->lr = 0x8003D950u;
            ctx->pc = 0x8001F4F8u;
            return;
    }

label_8003D950:
    ctx->pc = 0x8003D950u;
    ctx->downcount -= 5;
    // 8003D950: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003D954:
    ctx->pc = 0x8003D954u;
    // 8003D954: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003D958:
    ctx->pc = 0x8003D958u;
    // 8003D958: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003D95C:
    ctx->pc = 0x8003D95Cu;
    // 8003D95C: addi    r4, r1, 12
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(12);

label_8003D960:
    ctx->pc = 0x8003D960u;
    // 8003D960: bl      0x8025C71C
    {
            ctx->lr = 0x8003D964u;
            ctx->pc = 0x8025C71Cu;
            return;
    }

label_8003D964:
    ctx->pc = 0x8003D964u;
    ctx->downcount -= 3;
    // 8003D964: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003D968:
    ctx->pc = 0x8003D968u;
    // 8003D968: li      r4, 28
    ctx->gpr[4] = (u32)(s32)(28);

label_8003D96C:
    ctx->pc = 0x8003D96Cu;
    // 8003D96C: bl      0x8025C7FC
    {
            ctx->lr = 0x8003D970u;
            ctx->pc = 0x8025C7FCu;
            return;
    }

label_8003D970:
    ctx->pc = 0x8003D970u;
    ctx->downcount -= 3;
    // 8003D970: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003D974:
    ctx->pc = 0x8003D974u;
    // 8003D974: li      r4, 12
    ctx->gpr[4] = (u32)(s32)(12);

label_8003D978:
    ctx->pc = 0x8003D978u;
    // 8003D978: bl      0x8025C790
    {
            ctx->lr = 0x8003D97Cu;
            ctx->pc = 0x8025C790u;
            return;
    }

label_8003D97C:
    ctx->pc = 0x8003D97Cu;
    ctx->downcount -= 4;
    // 8003D97C: addi    r3, r1, 32
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(32);

label_8003D980:
    ctx->pc = 0x8003D980u;
    // 8003D980: addi    r4, r1, 28
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(28);

label_8003D984:
    ctx->pc = 0x8003D984u;
    // 8003D984: addi    r5, r1, 24
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(24);

label_8003D988:
    ctx->pc = 0x8003D988u;
    // 8003D988: bl      0x8006C6A4
    {
            ctx->lr = 0x8003D98Cu;
            ctx->pc = 0x8006C6A4u;
            return;
    }

label_8003D98C:
    ctx->pc = 0x8003D98Cu;
    ctx->downcount -= 15;
    // 8003D98C: lwz     r5, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8003D990:
    ctx->pc = 0x8003D990u;
    // 8003D990: lwz     r0, -25924(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25924);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003D994:
    ctx->pc = 0x8003D994u;
    // 8003D994: srawi r4, r0, 2
    {
        u32 sh = 2u;
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

label_8003D998:
    ctx->pc = 0x8003D998u;
    // 8003D998: lbz     r3, -25931(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25931);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8003D99C:
    ctx->pc = 0x8003D99Cu;
    // 8003D99C: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003D9A0:
    ctx->pc = 0x8003D9A0u;
    // 8003D9A0: mullw   r0, r3, r0
    {
        s64 product = (s64)(s32)ctx->gpr[3] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[0] = (u32)product;
    }

label_8003D9A4:
    ctx->pc = 0x8003D9A4u;
    // 8003D9A4: add   r0, r4, r0
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8003D9A8:
    ctx->pc = 0x8003D9A8u;
    // 8003D9A8: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_8003D9AC:
    ctx->pc = 0x8003D9ACu;
    // 8003D9AC: lwzx    r3, r5, r0
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[0];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003D9B0:
    ctx->pc = 0x8003D9B0u;
    // 8003D9B0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003D9B4:
    ctx->pc = 0x8003D9B4u;
    // 8003D9B4: bl      0x8004C4C8
    {
            ctx->lr = 0x8003D9B8u;
            ctx->pc = 0x8004C4C8u;
            return;
    }

label_8003D9B8:
    ctx->pc = 0x8003D9B8u;
    ctx->downcount -= 5;
    // 8003D9B8: addi    r3, r1, 40
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(40);

label_8003D9BC:
    ctx->pc = 0x8003D9BCu;
    // 8003D9BC: lfs     f1, -31424(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003D9BCu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31424);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003D9C0:
    ctx->pc = 0x8003D9C0u;
    // 8003D9C0: fmr    f2, f1
    if (!ppc_fp_available_inline(ctx, 0x8003D9C0u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_8003D9C4:
    ctx->pc = 0x8003D9C4u;
    // 8003D9C4: lfs     f3, -31452(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003D9C4u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31452);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8003D9C8:
    ctx->pc = 0x8003D9C8u;
    // 8003D9C8: bl      0x80247CC4
    {
            ctx->lr = 0x8003D9CCu;
            ctx->pc = 0x80247CC4u;
            return;
    }

label_8003D9CC:
    ctx->pc = 0x8003D9CCu;
    ctx->downcount -= 4;
    // 8003D9CC: addi    r3, r1, 40
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(40);

label_8003D9D0:
    ctx->pc = 0x8003D9D0u;
    // 8003D9D0: li      r4, 64
    ctx->gpr[4] = (u32)(s32)(64);

label_8003D9D4:
    ctx->pc = 0x8003D9D4u;
    // 8003D9D4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003D9D8:
    ctx->pc = 0x8003D9D8u;
    // 8003D9D8: bl      0x8025DAD0
    {
            ctx->lr = 0x8003D9DCu;
            ctx->pc = 0x8025DAD0u;
            return;
    }

label_8003D9DC:
    ctx->pc = 0x8003D9DCu;
    ctx->downcount -= 7;
    // 8003D9DC: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003D9E0:
    ctx->pc = 0x8003D9E0u;
    // 8003D9E0: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8003D9E4:
    ctx->pc = 0x8003D9E4u;
    // 8003D9E4: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_8003D9E8:
    ctx->pc = 0x8003D9E8u;
    // 8003D9E8: li      r6, 60
    ctx->gpr[6] = (u32)(s32)(60);

label_8003D9EC:
    ctx->pc = 0x8003D9ECu;
    // 8003D9EC: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8003D9F0:
    ctx->pc = 0x8003D9F0u;
    // 8003D9F0: li      r8, 64
    ctx->gpr[8] = (u32)(s32)(64);

label_8003D9F4:
    ctx->pc = 0x8003D9F4u;
    // 8003D9F4: bl      0x80258880
    {
            ctx->lr = 0x8003D9F8u;
            ctx->pc = 0x80258880u;
            return;
    }

label_8003D9F8:
    ctx->pc = 0x8003D9F8u;
    ctx->downcount -= 2;
    // 8003D9F8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003D9FC:
    ctx->pc = 0x8003D9FCu;
    // 8003D9FC: bl      0x8025C08C
    {
            ctx->lr = 0x8003DA00u;
            ctx->pc = 0x8025C08Cu;
            return;
    }

label_8003DA00:
    ctx->pc = 0x8003DA00u;
    ctx->downcount -= 5;
    // 8003DA00: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003DA04:
    ctx->pc = 0x8003DA04u;
    // 8003DA04: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8003DA08:
    ctx->pc = 0x8003DA08u;
    // 8003DA08: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003DA0C:
    ctx->pc = 0x8003DA0Cu;
    // 8003DA0C: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_8003DA10:
    ctx->pc = 0x8003DA10u;
    // 8003DA10: bl      0x8025CA34
    {
            ctx->lr = 0x8003DA14u;
            ctx->pc = 0x8025CA34u;
            return;
    }

label_8003DA14:
    ctx->pc = 0x8003DA14u;
    ctx->downcount -= 6;
    // 8003DA14: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003DA18:
    ctx->pc = 0x8003DA18u;
    // 8003DA18: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_8003DA1C:
    ctx->pc = 0x8003DA1Cu;
    // 8003DA1C: li      r5, 15
    ctx->gpr[5] = (u32)(s32)(15);

label_8003DA20:
    ctx->pc = 0x8003DA20u;
    // 8003DA20: li      r6, 15
    ctx->gpr[6] = (u32)(s32)(15);

label_8003DA24:
    ctx->pc = 0x8003DA24u;
    // 8003DA24: li      r7, 14
    ctx->gpr[7] = (u32)(s32)(14);

label_8003DA28:
    ctx->pc = 0x8003DA28u;
    // 8003DA28: bl      0x8025C3B0
    {
            ctx->lr = 0x8003DA2Cu;
            ctx->pc = 0x8025C3B0u;
            return;
    }

label_8003DA2C:
    ctx->pc = 0x8003DA2Cu;
    ctx->downcount -= 6;
    // 8003DA2C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003DA30:
    ctx->pc = 0x8003DA30u;
    // 8003DA30: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_8003DA34:
    ctx->pc = 0x8003DA34u;
    // 8003DA34: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_8003DA38:
    ctx->pc = 0x8003DA38u;
    // 8003DA38: li      r6, 5
    ctx->gpr[6] = (u32)(s32)(5);

label_8003DA3C:
    ctx->pc = 0x8003DA3Cu;
    // 8003DA3C: li      r7, 7
    ctx->gpr[7] = (u32)(s32)(7);

label_8003DA40:
    ctx->pc = 0x8003DA40u;
    // 8003DA40: bl      0x8025C430
    {
            ctx->lr = 0x8003DA44u;
            ctx->pc = 0x8025C430u;
            return;
    }

label_8003DA44:
    ctx->pc = 0x8003DA44u;
    ctx->downcount -= 4;
    // 8003DA44: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003DA48:
    ctx->pc = 0x8003DA48u;
    // 8003DA48: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003DA4C:
    ctx->pc = 0x8003DA4Cu;
    // 8003DA4C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003DA50:
    ctx->pc = 0x8003DA50u;
    // 8003DA50: bl      0x8025C868
    {
            ctx->lr = 0x8003DA54u;
            ctx->pc = 0x8025C868u;
            return;
    }

label_8003DA54:
    ctx->pc = 0x8003DA54u;
    ctx->downcount -= 7;
    // 8003DA54: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003DA58:
    ctx->pc = 0x8003DA58u;
    // 8003DA58: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003DA5C:
    ctx->pc = 0x8003DA5Cu;
    // 8003DA5C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003DA60:
    ctx->pc = 0x8003DA60u;
    // 8003DA60: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8003DA64:
    ctx->pc = 0x8003DA64u;
    // 8003DA64: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8003DA68:
    ctx->pc = 0x8003DA68u;
    // 8003DA68: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8003DA6C:
    ctx->pc = 0x8003DA6Cu;
    // 8003DA6C: bl      0x8025C4B4
    {
            ctx->lr = 0x8003DA70u;
            ctx->pc = 0x8025C4B4u;
            return;
    }

label_8003DA70:
    ctx->pc = 0x8003DA70u;
    ctx->downcount -= 7;
    // 8003DA70: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003DA74:
    ctx->pc = 0x8003DA74u;
    // 8003DA74: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003DA78:
    ctx->pc = 0x8003DA78u;
    // 8003DA78: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003DA7C:
    ctx->pc = 0x8003DA7Cu;
    // 8003DA7C: li      r6, 3
    ctx->gpr[6] = (u32)(s32)(3);

label_8003DA80:
    ctx->pc = 0x8003DA80u;
    // 8003DA80: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8003DA84:
    ctx->pc = 0x8003DA84u;
    // 8003DA84: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8003DA88:
    ctx->pc = 0x8003DA88u;
    // 8003DA88: bl      0x8025C574
    {
            ctx->lr = 0x8003DA8Cu;
            ctx->pc = 0x8025C574u;
            return;
    }

label_8003DA8C:
    ctx->pc = 0x8003DA8Cu;
    ctx->downcount -= 2;
    // 8003DA8C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003DA90:
    ctx->pc = 0x8003DA90u;
    // 8003DA90: bl      0x8025CC10
    {
            ctx->lr = 0x8003DA94u;
            ctx->pc = 0x8025CC10u;
            return;
    }

label_8003DA94:
    ctx->pc = 0x8003DA94u;
    ctx->downcount -= 2;
    // 8003DA94: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003DA98:
    ctx->pc = 0x8003DA98u;
    // 8003DA98: bl      0x8025C060
    {
            ctx->lr = 0x8003DA9Cu;
            ctx->pc = 0x8025C060u;
            return;
    }

label_8003DA9C:
    ctx->pc = 0x8003DA9Cu;
    ctx->downcount -= 2;
    // 8003DA9C: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003DAA0:
    ctx->pc = 0x8003DAA0u;
    // 8003DAA0: bl      0x80258B50
    {
            ctx->lr = 0x8003DAA4u;
            ctx->pc = 0x80258B50u;
            return;
    }

label_8003DAA4:
    ctx->pc = 0x8003DAA4u;
    ctx->downcount -= 2;
    // 8003DAA4: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003DAA8:
    ctx->pc = 0x8003DAA8u;
    // 8003DAA8: bl      0x80259494
    {
            ctx->lr = 0x8003DAACu;
            ctx->pc = 0x80259494u;
            return;
    }

label_8003DAAC:
    ctx->pc = 0x8003DAACu;
    ctx->downcount -= 9;
    // 8003DAAC: lwz     r0, -32040(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32040);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003DAB0:
    ctx->pc = 0x8003DAB0u;
    // 8003DAB0: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003DAB4:
    ctx->pc = 0x8003DAB4u;
    // 8003DAB4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003DAB8:
    ctx->pc = 0x8003DAB8u;
    // 8003DAB8: lfs     f1, -31476(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003DAB8u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31476);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8003DABC:
    ctx->pc = 0x8003DABCu;
    // 8003DABC: fmr    f2, f1
    if (!ppc_fp_available_inline(ctx, 0x8003DABCu)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_8003DAC0:
    ctx->pc = 0x8003DAC0u;
    // 8003DAC0: fmr    f3, f1
    if (!ppc_fp_available_inline(ctx, 0x8003DAC0u)) return;
    ctx->fpr[3] = ctx->fpr[1];

label_8003DAC4:
    ctx->pc = 0x8003DAC4u;
    // 8003DAC4: fmr    f4, f1
    if (!ppc_fp_available_inline(ctx, 0x8003DAC4u)) return;
    ctx->fpr[4] = ctx->fpr[1];

label_8003DAC8:
    ctx->pc = 0x8003DAC8u;
    // 8003DAC8: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_8003DACC:
    ctx->pc = 0x8003DACCu;
    // 8003DACC: bl      0x8025CC44
    {
            ctx->lr = 0x8003DAD0u;
            ctx->pc = 0x8025CC44u;
            return;
    }

label_8003DAD0:
    ctx->pc = 0x8003DAD0u;
    ctx->downcount -= 4;
    // 8003DAD0: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003DAD4:
    ctx->pc = 0x8003DAD4u;
    // 8003DAD4: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_8003DAD8:
    ctx->pc = 0x8003DAD8u;
    // 8003DAD8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003DADC:
    ctx->pc = 0x8003DADCu;
    // 8003DADC: bl      0x800704F4
    {
            ctx->lr = 0x8003DAE0u;
            ctx->pc = 0x800704F4u;
            return;
    }

label_8003DAE0:
    ctx->pc = 0x8003DAE0u;
    ctx->downcount -= 2;
    // 8003DAE0: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003DAE4:
    ctx->pc = 0x8003DAE4u;
    // 8003DAE4: bl      0x8007049C
    {
            ctx->lr = 0x8003DAE8u;
            ctx->pc = 0x8007049Cu;
            return;
    }

label_8003DAE8:
    ctx->pc = 0x8003DAE8u;
    ctx->downcount -= 5;
    // 8003DAE8: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003DAEC:
    ctx->pc = 0x8003DAECu;
    // 8003DAEC: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_8003DAF0:
    ctx->pc = 0x8003DAF0u;
    // 8003DAF0: li      r5, 5
    ctx->gpr[5] = (u32)(s32)(5);

label_8003DAF4:
    ctx->pc = 0x8003DAF4u;
    // 8003DAF4: li      r6, 5
    ctx->gpr[6] = (u32)(s32)(5);

label_8003DAF8:
    ctx->pc = 0x8003DAF8u;
    // 8003DAF8: bl      0x8025CEF4
    {
            ctx->lr = 0x8003DAFCu;
            ctx->pc = 0x8025CEF4u;
            return;
    }

label_8003DAFC:
    ctx->pc = 0x8003DAFCu;
    ctx->downcount -= 7;
    // 8003DAFC: lwz     r31, 92(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8003DB00:
    ctx->pc = 0x8003DB00u;
    // 8003DB00: lwz     r30, 88(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8003DB04:
    ctx->pc = 0x8003DB04u;
    // 8003DB04: lwz     r0, 100(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(100);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003DB08:
    ctx->pc = 0x8003DB08u;
    // 8003DB08: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8003DB0C:
    ctx->pc = 0x8003DB0Cu;
    // 8003DB0C: addi    r1, r1, 96
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(96);

label_8003DB10:
    ctx->pc = 0x8003DB10u;
    // 8003DB10: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8003A6E0;
        }
    }

label_8003DB14:
    ctx->pc = 0x8003DB14u;
    ctx->downcount -= 11;
    // 8003DB14: stwu     r1, -256(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-256);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8003DB18:
    ctx->pc = 0x8003DB18u;
    // 8003DB18: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8003DB1C:
    ctx->pc = 0x8003DB1Cu;
    // 8003DB1C: stw     r0, 260(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(260);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003DB20:
    ctx->pc = 0x8003DB20u;
    // 8003DB20: stw     r31, 252(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(252);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8003DB24:
    ctx->pc = 0x8003DB24u;
    // 8003DB24: stw     r30, 248(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(248);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8003DB28:
    ctx->pc = 0x8003DB28u;
    // 8003DB28: stw     r29, 244(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(244);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_8003DB2C:
    ctx->pc = 0x8003DB2Cu;
    // 8003DB2C: stw     r28, 240(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(240);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_8003DB30:
    ctx->pc = 0x8003DB30u;
    // 8003DB30: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003DB34:
    ctx->pc = 0x8003DB34u;
    // 8003DB34: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8003DB38:
    ctx->pc = 0x8003DB38u;
    // 8003DB38: lwz     r31, 88(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(88);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8003DB3C:
    ctx->pc = 0x8003DB3Cu;
    // 8003DB3C: bl      0x8000F56C
    {
            ctx->lr = 0x8003DB40u;
            ctx->pc = 0x8000F56Cu;
            return;
    }

label_8003DB40:
    ctx->pc = 0x8003DB40u;
    ctx->downcount -= 5;
    // 8003DB40: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003DB44:
    ctx->pc = 0x8003DB44u;
    // 8003DB44: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8003DB48:
    ctx->pc = 0x8003DB48u;
    // 8003DB48: addi    r4, r1, 144
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(144);

label_8003DB4C:
    ctx->pc = 0x8003DB4Cu;
    // 8003DB4C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003DB50:
    ctx->pc = 0x8003DB50u;
    // 8003DB50: bl      0x8002B5F0
    {
            ctx->lr = 0x8003DB54u;
            ctx->pc = 0x8002B5F0u;
            return;
    }

label_8003DB54:
    ctx->pc = 0x8003DB54u;
    ctx->downcount -= 4;
    // 8003DB54: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8003DB58:
    ctx->pc = 0x8003DB58u;
    // 8003DB58: addi    r4, r1, 144
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(144);

label_8003DB5C:
    ctx->pc = 0x8003DB5Cu;
    // 8003DB5C: addi    r5, r1, 80
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(80);

label_8003DB60:
    ctx->pc = 0x8003DB60u;
    // 8003DB60: bl      0x80247860
    {
            ctx->lr = 0x8003DB64u;
            ctx->pc = 0x80247860u;
            return;
    }

label_8003DB64:
    ctx->pc = 0x8003DB64u;
    ctx->downcount -= 5;
    // 8003DB64: addi    r3, r1, 80
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(80);

label_8003DB68:
    ctx->pc = 0x8003DB68u;
    // 8003DB68: lis     r4, -32723
    ctx->gpr[4] = ((u32)(s32)(-32723) << 16);

label_8003DB6C:
    ctx->pc = 0x8003DB6Cu;
    // 8003DB6C: addi    r4, r4, -14624
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-14624);

label_8003DB70:
    ctx->pc = 0x8003DB70u;
    // 8003DB70: lbz     r4, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_8003DB74:
    ctx->pc = 0x8003DB74u;
    // 8003DB74: bl      0x8025DA18
    {
            ctx->lr = 0x8003DB78u;
            ctx->pc = 0x8025DA18u;
            return;
    }

label_8003DB78:
    ctx->pc = 0x8003DB78u;
    ctx->downcount -= 4;
    // 8003DB78: lis     r3, -32723
    ctx->gpr[3] = ((u32)(s32)(-32723) << 16);

label_8003DB7C:
    ctx->pc = 0x8003DB7Cu;
    // 8003DB7C: addi    r3, r3, -14624
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-14624);

label_8003DB80:
    ctx->pc = 0x8003DB80u;
    // 8003DB80: lbz     r3, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8003DB84:
    ctx->pc = 0x8003DB84u;
    // 8003DB84: bl      0x8025DA94
    {
            ctx->lr = 0x8003DB88u;
            ctx->pc = 0x8025DA94u;
            return;
    }

label_8003DB88:
    ctx->pc = 0x8003DB88u;
    ctx->downcount -= 22;
    // 8003DB88: lfs     f3, -31452(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003DB88u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31452);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8003DB8C:
    ctx->pc = 0x8003DB8Cu;
    // 8003DB8C: lfs     f0, 8(r28)
    if (!ppc_fp_available_inline(ctx, 0x8003DB8Cu)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003DB90:
    ctx->pc = 0x8003DB90u;
    // 8003DB90: fdivs   f1, f3, f0
    if (!ppc_fp_available_inline(ctx, 0x8003DB90u)) return;
    ppc_fdivs(ctx, 1, 3, 0);

label_8003DB94:
    ctx->pc = 0x8003DB94u;
    // 8003DB94: addi    r3, r1, 32
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(32);

label_8003DB98:
    ctx->pc = 0x8003DB98u;
    // 8003DB98: fmr    f2, f1
    if (!ppc_fp_available_inline(ctx, 0x8003DB98u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_8003DB9C:
    ctx->pc = 0x8003DB9Cu;
    // 8003DB9C: bl      0x80247CC4
    {
            ctx->lr = 0x8003DBA0u;
            ctx->pc = 0x80247CC4u;
            return;
    }

label_8003DBA0:
    ctx->pc = 0x8003DBA0u;
    ctx->downcount -= 8;
    // 8003DBA0: lfs     f0, -31476(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003DBA0u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31476);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003DBA4:
    ctx->pc = 0x8003DBA4u;
    // 8003DBA4: stfs     f0, 92(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003DBA4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003DBA8:
    ctx->pc = 0x8003DBA8u;
    // 8003DBA8: stfs     f0, 108(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003DBA8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(108);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003DBAC:
    ctx->pc = 0x8003DBACu;
    // 8003DBAC: stfs     f0, 124(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003DBACu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(124);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003DBB0:
    ctx->pc = 0x8003DBB0u;
    // 8003DBB0: addi    r3, r1, 80
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(80);

label_8003DBB4:
    ctx->pc = 0x8003DBB4u;
    // 8003DBB4: addi    r4, r1, 32
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(32);

label_8003DBB8:
    ctx->pc = 0x8003DBB8u;
    // 8003DBB8: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003DBBC:
    ctx->pc = 0x8003DBBCu;
    // 8003DBBC: bl      0x80247860
    {
            ctx->lr = 0x8003DBC0u;
            ctx->pc = 0x80247860u;
            return;
    }

label_8003DBC0:
    ctx->pc = 0x8003DBC0u;
    ctx->downcount -= 4;
    // 8003DBC0: addi    r3, r1, 80
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(80);

label_8003DBC4:
    ctx->pc = 0x8003DBC4u;
    // 8003DBC4: li      r4, 30
    ctx->gpr[4] = (u32)(s32)(30);

label_8003DBC8:
    ctx->pc = 0x8003DBC8u;
    // 8003DBC8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003DBCC:
    ctx->pc = 0x8003DBCCu;
    // 8003DBCC: bl      0x8025DAD0
    {
            ctx->lr = 0x8003DBD0u;
            ctx->pc = 0x8025DAD0u;
            return;
    }

label_8003DBD0:
    ctx->pc = 0x8003DBD0u;
    ctx->downcount -= 4;
    // 8003DBD0: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8003DBD4:
    ctx->pc = 0x8003DBD4u;
    // 8003DBD4: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8003DBD8:
    ctx->pc = 0x8003DBD8u;
    // 8003DBD8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003DBDC:
    ctx->pc = 0x8003DBDCu;
    // 8003DBDC: bl      0x80072FE0
    {
            ctx->lr = 0x8003DBE0u;
            ctx->pc = 0x80072FE0u;
            return;
    }

label_8003DBE0:
    ctx->pc = 0x8003DBE0u;
    ctx->downcount -= 1;
    // 8003DBE0: bl      0x80257D68
    {
            ctx->lr = 0x8003DBE4u;
            ctx->pc = 0x80257D68u;
            return;
    }

label_8003DBE4:
    ctx->pc = 0x8003DBE4u;
    ctx->downcount -= 3;
    // 8003DBE4: li      r3, 9
    ctx->gpr[3] = (u32)(s32)(9);

label_8003DBE8:
    ctx->pc = 0x8003DBE8u;
    // 8003DBE8: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8003DBEC:
    ctx->pc = 0x8003DBECu;
    // 8003DBEC: bl      0x802572E8
    {
            ctx->lr = 0x8003DBF0u;
            ctx->pc = 0x802572E8u;
            return;
    }

label_8003DBF0:
    ctx->pc = 0x8003DBF0u;
    ctx->downcount -= 3;
    // 8003DBF0: li      r3, 10
    ctx->gpr[3] = (u32)(s32)(10);

label_8003DBF4:
    ctx->pc = 0x8003DBF4u;
    // 8003DBF4: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8003DBF8:
    ctx->pc = 0x8003DBF8u;
    // 8003DBF8: bl      0x802572E8
    {
            ctx->lr = 0x8003DBFCu;
            ctx->pc = 0x802572E8u;
            return;
    }

label_8003DBFC:
    ctx->pc = 0x8003DBFCu;
    ctx->downcount -= 3;
    // 8003DBFC: li      r3, 13
    ctx->gpr[3] = (u32)(s32)(13);

label_8003DC00:
    ctx->pc = 0x8003DC00u;
    // 8003DC00: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8003DC04:
    ctx->pc = 0x8003DC04u;
    // 8003DC04: bl      0x802572E8
    {
            ctx->lr = 0x8003DC08u;
            ctx->pc = 0x802572E8u;
            return;
    }

label_8003DC08:
    ctx->pc = 0x8003DC08u;
    ctx->downcount -= 10;
    // 8003DC08: lwz     r30, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8003DC0C:
    ctx->pc = 0x8003DC0Cu;
    // 8003DC0C: lwz     r29, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_8003DC10:
    ctx->pc = 0x8003DC10u;
    // 8003DC10: li      r3, 144
    ctx->gpr[3] = (u32)(s32)(144);

label_8003DC14:
    ctx->pc = 0x8003DC14u;
    // 8003DC14: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_8003DC18:
    ctx->pc = 0x8003DC18u;
    // 8003DC18: lhz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8003DC1C:
    ctx->pc = 0x8003DC1Cu;
    // 8003DC1C: mulli   r0, r0, 3
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)3);

label_8003DC20:
    ctx->pc = 0x8003DC20u;
    // 8003DC20: rlwinm r5, r0, 0, 16, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x0000FFFFu;
    }

label_8003DC24:
    ctx->pc = 0x8003DC24u;
    // 8003DC24: bl      0x8025920C
    {
            ctx->lr = 0x8003DC28u;
            ctx->pc = 0x8025920Cu;
            return;
    }

label_8003DC28:
    ctx->pc = 0x8003DC28u;
    ctx->downcount -= 4;
    // 8003DC28: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_8003DC2C:
    ctx->pc = 0x8003DC2Cu;
    // 8003DC2C: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8003DC30:
    ctx->pc = 0x8003DC30u;
    // 8003DC30: lis     r3, -13311
    ctx->gpr[3] = ((u32)(s32)(-13311) << 16);

label_8003DC34:
    ctx->pc = 0x8003DC34u;
    // 8003DC34: b       0x8003DCB4
    {
            goto label_8003DCB4;
    }

label_8003DC38:
    ctx->pc = 0x8003DC38u;
    ctx->downcount -= 6;
    // 8003DC38: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003DC3C:
    // 8003DC3C: add   r10, r0, r7
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[10] = res;
    }

label_8003DC40:
    // 8003DC40: or   r6, r10, r10
    {
        ctx->gpr[6] = ctx->gpr[10] | ctx->gpr[10];
    }

label_8003DC44:
    // 8003DC44: li      r0, 3
    ctx->gpr[0] = (u32)(s32)(3);

label_8003DC48:
    ctx->pc = 0x8003DC48u;
    // 8003DC48: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8003DC4C:
    loop_8003DC4C(ctx);
    if (ctx->pc == 0x8003DCACu) goto label_8003DCAC;
    return;
label_8003DC50:
    // 8003DC50: mulli   r0, r0, 6
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)6);

label_8003DC54:
    // 8003DC54: add   r8, r30, r0
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_8003DC58:
    ctx->pc = 0x8003DC58u;
    // 8003DC58: lha     r5, 4(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(4);
        ctx->gpr[5] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003DC5C:
    ctx->pc = 0x8003DC5Cu;
    // 8003DC5C: lha     r4, 2(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(2);
        ctx->gpr[4] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003DC60:
    ctx->pc = 0x8003DC60u;
    // 8003DC60: lha     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003DC64:
    ctx->pc = 0x8003DC64u;
    // 8003DC64: sth     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003DC68:
    ctx->pc = 0x8003DC68u;
    // 8003DC68: sth     r4, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_8003DC6C:
    ctx->pc = 0x8003DC6Cu;
    // 8003DC6C: sth     r5, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[5]);
    }

label_8003DC70:
    ctx->pc = 0x8003DC70u;
    // 8003DC70: lbz     r5, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_8003DC74:
    ctx->pc = 0x8003DC74u;
    // 8003DC74: lbz     r4, 7(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(7);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_8003DC78:
    ctx->pc = 0x8003DC78u;
    // 8003DC78: lbz     r0, 6(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(6);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003DC7C:
    ctx->pc = 0x8003DC7Cu;
    // 8003DC7C: stb     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8003DC80:
    ctx->pc = 0x8003DC80u;
    // 8003DC80: stb     r4, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_8003DC84:
    ctx->pc = 0x8003DC84u;
    // 8003DC84: stb     r5, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

label_8003DC88:
    ctx->pc = 0x8003DC88u;
    // 8003DC88: lhz     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8003DC8C:
    // 8003DC8C: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_8003DC90:
    // 8003DC90: add   r5, r29, r0
    {
        u32 a = ctx->gpr[29];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[5] = res;
    }

label_8003DC94:
    ctx->pc = 0x8003DC94u;
    // 8003DC94: lha     r4, 2(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(2);
        ctx->gpr[4] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003DC98:
    ctx->pc = 0x8003DC98u;
    // 8003DC98: lha     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003DC9C:
    ctx->pc = 0x8003DC9Cu;
    // 8003DC9C: sth     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003DCA0:
    ctx->pc = 0x8003DCA0u;
    // 8003DCA0: sth     r4, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_8003DCA4:
    // 8003DCA4: addi    r6, r6, 2
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(2);

label_8003DCA8:
    // 8003DCA8: bc    16, 0, 0x8003DC4C
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003DC4Cu;
                return;
            }
            goto label_8003DC4C;
        }
    }

label_8003DCAC:
    ctx->downcount -= 2;
    // 8003DCAC: addi    r7, r7, 10
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(10);

label_8003DCB0:
    // 8003DCB0: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_8003DCB4:
    ctx->pc = 0x8003DCB4u;
    ctx->downcount -= 3;
    // 8003DCB4: lhz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8003DCB8:
    // 8003DCB8: cmpw    r9, r0
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003DCBC:
    // 8003DCBC: bc    12, 0, 0x8003DC38
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003DC38u;
                return;
            }
            goto label_8003DC38;
        }
    }

label_8003DCC0:
    ctx->pc = 0x8003DCC0u;
    ctx->downcount -= 2;
    // 8003DCC0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003DCC4:
    ctx->pc = 0x8003DCC4u;
    // 8003DCC4: bl      0x8025DA94
    {
            ctx->lr = 0x8003DCC8u;
            ctx->pc = 0x8025DA94u;
            return;
    }

label_8003DCC8:
    ctx->pc = 0x8003DCC8u;
    ctx->downcount -= 3;
    // 8003DCC8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003DCCC:
    ctx->pc = 0x8003DCCCu;
    // 8003DCCC: li      r4, 5
    ctx->gpr[4] = (u32)(s32)(5);

label_8003DCD0:
    ctx->pc = 0x8003DCD0u;
    // 8003DCD0: bl      0x80022308
    {
            ctx->lr = 0x8003DCD4u;
            ctx->pc = 0x80022308u;
            return;
    }

label_8003DCD4:
    ctx->pc = 0x8003DCD4u;
    ctx->downcount -= 2;
    // 8003DCD4: cmpwi   r3, 0
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

label_8003DCD8:
    ctx->pc = 0x8003DCD8u;
    // 8003DCD8: bc    4, 2, 0x8003DDC4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003DDC4;
        }
    }

label_8003DCDC:
    ctx->pc = 0x8003DCDCu;
    ctx->downcount -= 4;
    // 8003DCDC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003DCE0:
    ctx->pc = 0x8003DCE0u;
    // 8003DCE0: lha     r4, 14(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(14);
        ctx->gpr[4] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003DCE4:
    ctx->pc = 0x8003DCE4u;
    // 8003DCE4: addi    r4, r4, -1
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-1);

label_8003DCE8:
    ctx->pc = 0x8003DCE8u;
    // 8003DCE8: bl      0x80022308
    {
            ctx->lr = 0x8003DCECu;
            ctx->pc = 0x80022308u;
            return;
    }

label_8003DCEC:
    ctx->pc = 0x8003DCECu;
    ctx->downcount -= 57;
    // 8003DCEC: mulli   r0, r3, 3
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[3] * (s64)(s32)3);

label_8003DCF0:
    ctx->pc = 0x8003DCF0u;
    // 8003DCF0: lfs     f3, 8(r28)
    if (!ppc_fp_available_inline(ctx, 0x8003DCF0u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8003DCF4:
    ctx->pc = 0x8003DCF4u;
    // 8003DCF4: rlwinm r3, r0, 1, 0, 30
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 1u) & 0xFFFFFFFEu;
    }

label_8003DCF8:
    ctx->pc = 0x8003DCF8u;
    // 8003DCF8: lhax    r0, r30, r3
    {
        u32 ea = ctx->gpr[30] + ctx->gpr[3];
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003DCFC:
    ctx->pc = 0x8003DCFCu;
    // 8003DCFC: srawi r0, r0, 8
    {
        u32 sh = 8u;
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

label_8003DD00:
    ctx->pc = 0x8003DD00u;
    // 8003DD00: lfd     f2, -31416(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003DD00u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31416);
        ctx->fpr[2] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003DD04:
    ctx->pc = 0x8003DD04u;
    // 8003DD04: xoris   r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] ^ (0x8000u << 16);

label_8003DD08:
    ctx->pc = 0x8003DD08u;
    // 8003DD08: stw     r0, 212(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(212);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003DD0C:
    ctx->pc = 0x8003DD0Cu;
    // 8003DD0C: lis     r4, 17200
    ctx->gpr[4] = ((u32)(s32)(17200) << 16);

label_8003DD10:
    ctx->pc = 0x8003DD10u;
    // 8003DD10: stw     r4, 208(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(208);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8003DD14:
    ctx->pc = 0x8003DD14u;
    // 8003DD14: lfd     f0, 208(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003DD14u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(208);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003DD18:
    ctx->pc = 0x8003DD18u;
    // 8003DD18: fsubs   f1, f0, f2
    if (!ppc_fp_available_inline(ctx, 0x8003DD18u)) return;
    ppc_fsubs(ctx, 1, 0, 2);

label_8003DD1C:
    ctx->pc = 0x8003DD1Cu;
    // 8003DD1C: lfs     f0, 12(r28)
    if (!ppc_fp_available_inline(ctx, 0x8003DD1Cu)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003DD20:
    ctx->pc = 0x8003DD20u;
    // 8003DD20: fmadds f0, f3, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8003DD20u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[3], ctx->fpr[1], ctx->fpr[0], true, false, false, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_8003DD24:
    ctx->pc = 0x8003DD24u;
    // 8003DD24: stfs     f0, 20(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003DD24u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003DD28:
    ctx->pc = 0x8003DD28u;
    // 8003DD28: add   r3, r30, r3
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8003DD2C:
    ctx->pc = 0x8003DD2Cu;
    // 8003DD2C: lha     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003DD30:
    ctx->pc = 0x8003DD30u;
    // 8003DD30: srawi r0, r0, 8
    {
        u32 sh = 8u;
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

label_8003DD34:
    ctx->pc = 0x8003DD34u;
    // 8003DD34: xoris   r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] ^ (0x8000u << 16);

label_8003DD38:
    ctx->pc = 0x8003DD38u;
    // 8003DD38: stw     r0, 220(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(220);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003DD3C:
    ctx->pc = 0x8003DD3Cu;
    // 8003DD3C: stw     r4, 216(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(216);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8003DD40:
    ctx->pc = 0x8003DD40u;
    // 8003DD40: lfd     f0, 216(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003DD40u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(216);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003DD44:
    ctx->pc = 0x8003DD44u;
    // 8003DD44: fsubs   f1, f0, f2
    if (!ppc_fp_available_inline(ctx, 0x8003DD44u)) return;
    ppc_fsubs(ctx, 1, 0, 2);

label_8003DD48:
    ctx->pc = 0x8003DD48u;
    // 8003DD48: lfs     f0, 16(r28)
    if (!ppc_fp_available_inline(ctx, 0x8003DD48u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003DD4C:
    ctx->pc = 0x8003DD4Cu;
    // 8003DD4C: fmadds f0, f3, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8003DD4Cu)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[3], ctx->fpr[1], ctx->fpr[0], true, false, false, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_8003DD50:
    ctx->pc = 0x8003DD50u;
    // 8003DD50: stfs     f0, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003DD50u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003DD54:
    ctx->pc = 0x8003DD54u;
    // 8003DD54: lha     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8003DD58:
    ctx->pc = 0x8003DD58u;
    // 8003DD58: srawi r0, r0, 8
    {
        u32 sh = 8u;
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

label_8003DD5C:
    ctx->pc = 0x8003DD5Cu;
    // 8003DD5C: xoris   r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] ^ (0x8000u << 16);

label_8003DD60:
    ctx->pc = 0x8003DD60u;
    // 8003DD60: stw     r0, 228(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(228);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003DD64:
    ctx->pc = 0x8003DD64u;
    // 8003DD64: stw     r4, 224(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(224);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8003DD68:
    ctx->pc = 0x8003DD68u;
    // 8003DD68: lfd     f0, 224(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003DD68u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(224);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8003DD6C:
    ctx->pc = 0x8003DD6Cu;
    // 8003DD6C: fsubs   f1, f0, f2
    if (!ppc_fp_available_inline(ctx, 0x8003DD6Cu)) return;
    ppc_fsubs(ctx, 1, 0, 2);

label_8003DD70:
    ctx->pc = 0x8003DD70u;
    // 8003DD70: lfs     f0, 20(r28)
    if (!ppc_fp_available_inline(ctx, 0x8003DD70u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(20);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003DD74:
    ctx->pc = 0x8003DD74u;
    // 8003DD74: fmadds f0, f3, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8003DD74u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[3], ctx->fpr[1], ctx->fpr[0], true, false, false, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_8003DD78:
    ctx->pc = 0x8003DD78u;
    // 8003DD78: stfs     f0, 28(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003DD78u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003DD7C:
    ctx->pc = 0x8003DD7Cu;
    // 8003DD7C: lfs     f0, -31452(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003DD7Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31452);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003DD80:
    ctx->pc = 0x8003DD80u;
    // 8003DD80: stfs     f0, 16(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003DD80u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003DD84:
    ctx->pc = 0x8003DD84u;
    // 8003DD84: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8003DD88:
    ctx->pc = 0x8003DD88u;
    // 8003DD88: sth     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003DD8C:
    ctx->pc = 0x8003DD8Cu;
    // 8003DD8C: sth     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003DD90:
    ctx->pc = 0x8003DD90u;
    // 8003DD90: sth     r0, 10(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(10);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8003DD94:
    ctx->pc = 0x8003DD94u;
    // 8003DD94: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8003DD98:
    ctx->pc = 0x8003DD98u;
    // 8003DD98: li      r4, 2045
    ctx->gpr[4] = (u32)(s32)(2045);

label_8003DD9C:
    ctx->pc = 0x8003DD9Cu;
    // 8003DD9C: addi    r5, r1, 8
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(8);

label_8003DDA0:
    ctx->pc = 0x8003DDA0u;
    // 8003DDA0: lis     r6, 32
    ctx->gpr[6] = ((u32)(s32)(32) << 16);

label_8003DDA4:
    ctx->pc = 0x8003DDA4u;
    // 8003DDA4: addi    r6, r6, 1
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(1);

label_8003DDA8:
    ctx->pc = 0x8003DDA8u;
    // 8003DDA8: li      r7, -1
    ctx->gpr[7] = (u32)(s32)(-1);

label_8003DDAC:
    ctx->pc = 0x8003DDACu;
    // 8003DDAC: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8003DDB0:
    ctx->pc = 0x8003DDB0u;
    // 8003DDB0: lwz     r9, -26360(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26360);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8003DDB4:
    ctx->pc = 0x8003DDB4u;
    // 8003DDB4: lwz     r9, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8003DDB8:
    ctx->pc = 0x8003DDB8u;
    // 8003DDB8: lwz     r12, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_8003DDBC:
    ctx->pc = 0x8003DDBCu;
    // 8003DDBC: mtctr    r12
    ctx->ctr = ctx->gpr[12];

label_8003DDC0:
    ctx->pc = 0x8003DDC0u;
    // 8003DDC0: bctrl
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8003DDC4u;
            ctx->pc = target;
            return;
        }
    }

label_8003DDC4:
    ctx->pc = 0x8003DDC4u;
    ctx->downcount -= 9;
    // 8003DDC4: lwz     r31, 252(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(252);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8003DDC8:
    ctx->pc = 0x8003DDC8u;
    // 8003DDC8: lwz     r30, 248(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(248);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8003DDCC:
    ctx->pc = 0x8003DDCCu;
    // 8003DDCC: lwz     r29, 244(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(244);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_8003DDD0:
    ctx->pc = 0x8003DDD0u;
    // 8003DDD0: lwz     r28, 240(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(240);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_8003DDD4:
    ctx->pc = 0x8003DDD4u;
    // 8003DDD4: lwz     r0, 260(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(260);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003DDD8:
    ctx->pc = 0x8003DDD8u;
    // 8003DDD8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8003DDDC:
    ctx->pc = 0x8003DDDCu;
    // 8003DDDC: addi    r1, r1, 256
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(256);

label_8003DDE0:
    ctx->pc = 0x8003DDE0u;
    // 8003DDE0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8003A6E0;
        }
    }

label_8003DDE4:
    ctx->pc = 0x8003DDE4u;
    ctx->downcount -= 5;
    // 8003DDE4: stwu     r1, -112(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-112);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8003DDE8:
    ctx->pc = 0x8003DDE8u;
    // 8003DDE8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8003DDEC:
    ctx->pc = 0x8003DDECu;
    // 8003DDEC: stw     r0, 116(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(116);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003DDF0:
    ctx->pc = 0x8003DDF0u;
    // 8003DDF0: addi    r11, r1, 112
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(112);

label_8003DDF4:
    ctx->pc = 0x8003DDF4u;
    // 8003DDF4: bl      0x80286A4C
    {
            ctx->lr = 0x8003DDF8u;
            ctx->pc = 0x80286A4Cu;
            return;
    }

label_8003DDF8:
    ctx->pc = 0x8003DDF8u;
    ctx->downcount -= 9;
    // 8003DDF8: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003DDFC:
    ctx->pc = 0x8003DDFCu;
    // 8003DDFC: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8003DE00:
    ctx->pc = 0x8003DE00u;
    // 8003DE00: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8003DE04:
    ctx->pc = 0x8003DE04u;
    // 8003DE04: stw     r0, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003DE08:
    ctx->pc = 0x8003DE08u;
    // 8003DE08: stw     r0, -25900(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25900);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003DE0C:
    ctx->pc = 0x8003DE0Cu;
    // 8003DE0C: lbz     r0, 36(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003DE10:
    ctx->pc = 0x8003DE10u;
    // 8003DE10: rlwinm r3, r0, 0, 30, 30
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000002u;
    }

label_8003DE14:
    ctx->pc = 0x8003DE14u;
    // 8003DE14: cmpwi   r3, 0
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

label_8003DE18:
    ctx->pc = 0x8003DE18u;
    // 8003DE18: bc    12, 2, 0x8003DE24
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003DE24;
        }
    }

label_8003DE1C:
    ctx->pc = 0x8003DE1Cu;
    ctx->downcount -= 2;
    // 8003DE1C: li      r27, 1
    ctx->gpr[27] = (u32)(s32)(1);

label_8003DE20:
    ctx->pc = 0x8003DE20u;
    // 8003DE20: b       0x8003DE28
    {
            goto label_8003DE28;
    }

label_8003DE24:
    ctx->pc = 0x8003DE24u;
    ctx->downcount -= 1;
    // 8003DE24: li      r27, 0
    ctx->gpr[27] = (u32)(s32)(0);

label_8003DE28:
    ctx->pc = 0x8003DE28u;
    ctx->downcount -= 3;
    // 8003DE28: rlwinm r4, r0, 0, 27, 27
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000010u;
    }

label_8003DE2C:
    ctx->pc = 0x8003DE2Cu;
    // 8003DE2C: cmpwi   r4, 0
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

label_8003DE30:
    ctx->pc = 0x8003DE30u;
    // 8003DE30: bc    12, 2, 0x8003DE3C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003DE3C;
        }
    }

label_8003DE34:
    ctx->pc = 0x8003DE34u;
    ctx->downcount -= 2;
    // 8003DE34: li      r28, 4
    ctx->gpr[28] = (u32)(s32)(4);

label_8003DE38:
    ctx->pc = 0x8003DE38u;
    // 8003DE38: b       0x8003DE40
    {
            goto label_8003DE40;
    }

label_8003DE3C:
    ctx->pc = 0x8003DE3Cu;
    ctx->downcount -= 1;
    // 8003DE3C: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_8003DE40:
    ctx->pc = 0x8003DE40u;
    ctx->downcount -= 4;
    // 8003DE40: lhz     r0, 226(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(226);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8003DE44:
    ctx->pc = 0x8003DE44u;
    // 8003DE44: rlwinm r0, r0, 0, 30, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000002u;
    }

label_8003DE48:
    ctx->pc = 0x8003DE48u;
    // 8003DE48: cmpwi   r0, 0
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

label_8003DE4C:
    ctx->pc = 0x8003DE4Cu;
    // 8003DE4C: bc    12, 2, 0x8003DF18
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003DF18;
        }
    }

label_8003DE50:
    ctx->pc = 0x8003DE50u;
    ctx->downcount -= 2;
    // 8003DE50: cmpwi   r3, 0
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

label_8003DE54:
    ctx->pc = 0x8003DE54u;
    // 8003DE54: bc    4, 2, 0x8003DE60
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003DE60;
        }
    }

label_8003DE58:
    ctx->pc = 0x8003DE58u;
    ctx->downcount -= 2;
    // 8003DE58: cmpwi   r4, 0
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

label_8003DE5C:
    ctx->pc = 0x8003DE5Cu;
    // 8003DE5C: bc    12, 2, 0x8003DECC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003DECC;
        }
    }

label_8003DE60:
    ctx->pc = 0x8003DE60u;
    ctx->downcount -= 8;
    // 8003DE60: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8003DE64:
    ctx->pc = 0x8003DE64u;
    // 8003DE64: addi    r3, r13, -25908
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-25908);

label_8003DE68:
    ctx->pc = 0x8003DE68u;
    // 8003DE68: stb     r0, 3(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(3);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8003DE6C:
    ctx->pc = 0x8003DE6Cu;
    // 8003DE6C: lwz     r0, -25908(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25908);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003DE70:
    ctx->pc = 0x8003DE70u;
    // 8003DE70: stw     r0, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003DE74:
    ctx->pc = 0x8003DE74u;
    // 8003DE74: rlwinm r3, r28, 0, 24, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[28], 0u) & 0x000000FFu;
    }

label_8003DE78:
    ctx->pc = 0x8003DE78u;
    // 8003DE78: addi    r4, r1, 40
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(40);

label_8003DE7C:
    ctx->pc = 0x8003DE7Cu;
    // 8003DE7C: bl      0x8025A4F8
    {
            ctx->lr = 0x8003DE80u;
            ctx->pc = 0x8025A4F8u;
            return;
    }

label_8003DE80:
    ctx->pc = 0x8003DE80u;
    ctx->downcount -= 8;
    // 8003DE80: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003DE84:
    ctx->pc = 0x8003DE84u;
    // 8003DE84: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8003DE88:
    ctx->pc = 0x8003DE88u;
    // 8003DE88: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003DE8C:
    ctx->pc = 0x8003DE8Cu;
    // 8003DE8C: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_8003DE90:
    ctx->pc = 0x8003DE90u;
    // 8003DE90: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8003DE94:
    ctx->pc = 0x8003DE94u;
    // 8003DE94: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8003DE98:
    ctx->pc = 0x8003DE98u;
    // 8003DE98: li      r9, 2
    ctx->gpr[9] = (u32)(s32)(2);

label_8003DE9C:
    ctx->pc = 0x8003DE9Cu;
    // 8003DE9C: bl      0x8025A814
    {
            ctx->lr = 0x8003DEA0u;
            ctx->pc = 0x8025A814u;
            return;
    }

label_8003DEA0:
    ctx->pc = 0x8003DEA0u;
    ctx->downcount -= 8;
    // 8003DEA0: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8003DEA4:
    ctx->pc = 0x8003DEA4u;
    // 8003DEA4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003DEA8:
    ctx->pc = 0x8003DEA8u;
    // 8003DEA8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003DEAC:
    ctx->pc = 0x8003DEACu;
    // 8003DEAC: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_8003DEB0:
    ctx->pc = 0x8003DEB0u;
    // 8003DEB0: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8003DEB4:
    ctx->pc = 0x8003DEB4u;
    // 8003DEB4: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8003DEB8:
    ctx->pc = 0x8003DEB8u;
    // 8003DEB8: li      r9, 2
    ctx->gpr[9] = (u32)(s32)(2);

label_8003DEBC:
    ctx->pc = 0x8003DEBCu;
    // 8003DEBC: bl      0x8025A814
    {
            ctx->lr = 0x8003DEC0u;
            ctx->pc = 0x8025A814u;
            return;
    }

label_8003DEC0:
    ctx->pc = 0x8003DEC0u;
    ctx->downcount -= 2;
    // 8003DEC0: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8003DEC4:
    ctx->pc = 0x8003DEC4u;
    // 8003DEC4: bl      0x8025A7C8
    {
            ctx->lr = 0x8003DEC8u;
            ctx->pc = 0x8025A7C8u;
            return;
    }

label_8003DEC8:
    ctx->pc = 0x8003DEC8u;
    ctx->downcount -= 1;
    // 8003DEC8: b       0x8003E1DC
    {
            goto label_8003E1DC;
    }

label_8003DECC:
    ctx->pc = 0x8003DECCu;
    ctx->downcount -= 8;
    // 8003DECC: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_8003DED0:
    ctx->pc = 0x8003DED0u;
    // 8003DED0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003DED4:
    ctx->pc = 0x8003DED4u;
    // 8003DED4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003DED8:
    ctx->pc = 0x8003DED8u;
    // 8003DED8: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8003DEDC:
    ctx->pc = 0x8003DEDCu;
    // 8003DEDC: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8003DEE0:
    ctx->pc = 0x8003DEE0u;
    // 8003DEE0: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8003DEE4:
    ctx->pc = 0x8003DEE4u;
    // 8003DEE4: li      r9, 2
    ctx->gpr[9] = (u32)(s32)(2);

label_8003DEE8:
    ctx->pc = 0x8003DEE8u;
    // 8003DEE8: bl      0x8025A814
    {
            ctx->lr = 0x8003DEECu;
            ctx->pc = 0x8025A814u;
            return;
    }

label_8003DEEC:
    ctx->pc = 0x8003DEECu;
    ctx->downcount -= 8;
    // 8003DEEC: li      r3, 5
    ctx->gpr[3] = (u32)(s32)(5);

label_8003DEF0:
    ctx->pc = 0x8003DEF0u;
    // 8003DEF0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003DEF4:
    ctx->pc = 0x8003DEF4u;
    // 8003DEF4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003DEF8:
    ctx->pc = 0x8003DEF8u;
    // 8003DEF8: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8003DEFC:
    ctx->pc = 0x8003DEFCu;
    // 8003DEFC: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8003DF00:
    ctx->pc = 0x8003DF00u;
    // 8003DF00: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8003DF04:
    ctx->pc = 0x8003DF04u;
    // 8003DF04: li      r9, 2
    ctx->gpr[9] = (u32)(s32)(2);

label_8003DF08:
    ctx->pc = 0x8003DF08u;
    // 8003DF08: bl      0x8025A814
    {
            ctx->lr = 0x8003DF0Cu;
            ctx->pc = 0x8025A814u;
            return;
    }

label_8003DF0C:
    ctx->pc = 0x8003DF0Cu;
    ctx->downcount -= 2;
    // 8003DF0C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003DF10:
    ctx->pc = 0x8003DF10u;
    // 8003DF10: bl      0x8025A7C8
    {
            ctx->lr = 0x8003DF14u;
            ctx->pc = 0x8025A7C8u;
            return;
    }

label_8003DF14:
    ctx->pc = 0x8003DF14u;
    ctx->downcount -= 1;
    // 8003DF14: b       0x8003E1DC
    {
            goto label_8003E1DC;
    }

label_8003DF18:
    ctx->pc = 0x8003DF18u;
    ctx->downcount -= 2;
    // 8003DF18: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003DF1C:
    ctx->pc = 0x8003DF1Cu;
    // 8003DF1C: bl      0x8001EA68
    {
            ctx->lr = 0x8003DF20u;
            ctx->pc = 0x8001EA68u;
            return;
    }

label_8003DF20:
    ctx->pc = 0x8003DF20u;
    ctx->downcount -= 5;
    // 8003DF20: rlwinm r31, r28, 0, 24, 31
    {
        ctx->gpr[31] = dolrecomp_rotl32(ctx->gpr[28], 0u) & 0x000000FFu;
    }

label_8003DF24:
    ctx->pc = 0x8003DF24u;
    // 8003DF24: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8003DF28:
    ctx->pc = 0x8003DF28u;
    // 8003DF28: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8003DF2C:
    ctx->pc = 0x8003DF2Cu;
    // 8003DF2C: or   r5, r27, r27
    {
        ctx->gpr[5] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8003DF30:
    ctx->pc = 0x8003DF30u;
    // 8003DF30: bl      0x8001E77C
    {
            ctx->lr = 0x8003DF34u;
            ctx->pc = 0x8001E77Cu;
            return;
    }

label_8003DF34:
    ctx->pc = 0x8003DF34u;
    ctx->downcount -= 4;
    // 8003DF34: lhz     r3, 226(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(226);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_8003DF38:
    ctx->pc = 0x8003DF38u;
    // 8003DF38: andi.   r0, r3, 0x0009
    {
        ctx->gpr[0] = ctx->gpr[3] & 0x0009u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8003DF3C:
    ctx->pc = 0x8003DF3Cu;
    // 8003DF3C: cmpwi   r0, 0
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

label_8003DF40:
    ctx->pc = 0x8003DF40u;
    // 8003DF40: bc    4, 2, 0x8003E05C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003E05C;
        }
    }

label_8003DF44:
    ctx->pc = 0x8003DF44u;
    ctx->downcount -= 3;
    // 8003DF44: rlwinm r0, r3, 0, 28, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x0000000Cu;
    }

label_8003DF48:
    ctx->pc = 0x8003DF48u;
    // 8003DF48: cmpwi   r0, 0
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

label_8003DF4C:
    ctx->pc = 0x8003DF4Cu;
    // 8003DF4C: bc    12, 2, 0x8003DF6C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003DF6C;
        }
    }

label_8003DF50:
    ctx->pc = 0x8003DF50u;
    ctx->downcount -= 6;
    // 8003DF50: li      r27, 2
    ctx->gpr[27] = (u32)(s32)(2);

label_8003DF54:
    ctx->pc = 0x8003DF54u;
    // 8003DF54: lwz     r0, -32036(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32036);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003DF58:
    ctx->pc = 0x8003DF58u;
    // 8003DF58: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003DF5C:
    ctx->pc = 0x8003DF5Cu;
    // 8003DF5C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8003DF60:
    ctx->pc = 0x8003DF60u;
    // 8003DF60: addi    r4, r1, 36
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(36);

label_8003DF64:
    ctx->pc = 0x8003DF64u;
    // 8003DF64: bl      0x8025A4F8
    {
            ctx->lr = 0x8003DF68u;
            ctx->pc = 0x8025A4F8u;
            return;
    }

label_8003DF68:
    ctx->pc = 0x8003DF68u;
    ctx->downcount -= 1;
    // 8003DF68: b       0x8003DFCC
    {
            goto label_8003DFCC;
    }

label_8003DF6C:
    ctx->pc = 0x8003DF6Cu;
    ctx->downcount -= 5;
    // 8003DF6C: li      r27, 6
    ctx->gpr[27] = (u32)(s32)(6);

label_8003DF70:
    ctx->pc = 0x8003DF70u;
    // 8003DF70: lwz     r3, 80(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(80);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003DF74:
    ctx->pc = 0x8003DF74u;
    // 8003DF74: lbz     r3, 141(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(141);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8003DF78:
    ctx->pc = 0x8003DF78u;
    // 8003DF78: cmpwi   r3, 0
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

label_8003DF7C:
    ctx->pc = 0x8003DF7Cu;
    // 8003DF7C: bc    4, 2, 0x8003DFA0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003DFA0;
        }
    }

label_8003DF80:
    ctx->pc = 0x8003DF80u;
    ctx->downcount -= 2;
    // 8003DF80: lbz     r3, 242(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(242);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8003DF84:
    ctx->pc = 0x8003DF84u;
    // 8003DF84: bl      0x80089CDC
    {
            ctx->lr = 0x8003DF88u;
            ctx->pc = 0x80089CDCu;
            return;
    }

label_8003DF88:
    ctx->pc = 0x8003DF88u;
    ctx->downcount -= 5;
    // 8003DF88: lbz     r3, 242(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(242);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8003DF8C:
    ctx->pc = 0x8003DF8Cu;
    // 8003DF8C: addi    r4, r1, 44
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(44);

label_8003DF90:
    ctx->pc = 0x8003DF90u;
    // 8003DF90: addi    r5, r1, 45
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(45);

label_8003DF94:
    ctx->pc = 0x8003DF94u;
    // 8003DF94: addi    r6, r1, 46
    ctx->gpr[6] = ctx->gpr[1] + (u32)(s32)(46);

label_8003DF98:
    ctx->pc = 0x8003DF98u;
    // 8003DF98: bl      0x80089C88
    {
            ctx->lr = 0x8003DF9Cu;
            ctx->pc = 0x80089C88u;
            return;
    }

label_8003DF9C:
    ctx->pc = 0x8003DF9Cu;
    ctx->downcount -= 1;
    // 8003DF9C: b       0x8003DFB0
    {
            goto label_8003DFB0;
    }

label_8003DFA0:
    ctx->pc = 0x8003DFA0u;
    ctx->downcount -= 4;
    // 8003DFA0: addi    r4, r1, 44
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(44);

label_8003DFA4:
    ctx->pc = 0x8003DFA4u;
    // 8003DFA4: addi    r5, r1, 45
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(45);

label_8003DFA8:
    ctx->pc = 0x8003DFA8u;
    // 8003DFA8: addi    r6, r1, 46
    ctx->gpr[6] = ctx->gpr[1] + (u32)(s32)(46);

label_8003DFAC:
    ctx->pc = 0x8003DFACu;
    // 8003DFAC: bl      0x8001F12C
    {
            ctx->lr = 0x8003DFB0u;
            ctx->pc = 0x8001F12Cu;
            return;
    }

label_8003DFB0:
    ctx->pc = 0x8003DFB0u;
    ctx->downcount -= 7;
    // 8003DFB0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8003DFB4:
    ctx->pc = 0x8003DFB4u;
    // 8003DFB4: stb     r0, 47(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(47);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8003DFB8:
    ctx->pc = 0x8003DFB8u;
    // 8003DFB8: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003DFBC:
    ctx->pc = 0x8003DFBCu;
    // 8003DFBC: stw     r0, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003DFC0:
    ctx->pc = 0x8003DFC0u;
    // 8003DFC0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8003DFC4:
    ctx->pc = 0x8003DFC4u;
    // 8003DFC4: addi    r4, r1, 32
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(32);

label_8003DFC8:
    ctx->pc = 0x8003DFC8u;
    // 8003DFC8: bl      0x8025A4F8
    {
            ctx->lr = 0x8003DFCCu;
            ctx->pc = 0x8025A4F8u;
            return;
    }

label_8003DFCC:
    ctx->pc = 0x8003DFCCu;
    ctx->downcount -= 4;
    // 8003DFCC: lwz     r3, 80(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(80);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003DFD0:
    ctx->pc = 0x8003DFD0u;
    // 8003DFD0: lbz     r5, 140(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(140);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_8003DFD4:
    ctx->pc = 0x8003DFD4u;
    // 8003DFD4: cmplwi  r5, 0x0000
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

label_8003DFD8:
    ctx->pc = 0x8003DFD8u;
    // 8003DFD8: bc    12, 2, 0x8003DFF0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003DFF0;
        }
    }

label_8003DFDC:
    ctx->pc = 0x8003DFDCu;
    ctx->downcount -= 5;
    // 8003DFDC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8003DFE0:
    ctx->pc = 0x8003DFE0u;
    // 8003DFE0: addi    r4, r1, 52
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(52);

label_8003DFE4:
    ctx->pc = 0x8003DFE4u;
    // 8003DFE4: addi    r6, r1, 48
    ctx->gpr[6] = ctx->gpr[1] + (u32)(s32)(48);

label_8003DFE8:
    ctx->pc = 0x8003DFE8u;
    // 8003DFE8: or   r7, r27, r27
    {
        ctx->gpr[7] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8003DFEC:
    ctx->pc = 0x8003DFECu;
    // 8003DFEC: bl      0x8001EE08
    {
            ctx->lr = 0x8003DFF0u;
            ctx->pc = 0x8001EE08u;
            return;
    }

label_8003DFF0:
    ctx->pc = 0x8003DFF0u;
    ctx->downcount -= 3;
    // 8003DFF0: lwz     r0, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003DFF4:
    ctx->pc = 0x8003DFF4u;
    // 8003DFF4: cmpwi   r0, 0
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

label_8003DFF8:
    ctx->pc = 0x8003DFF8u;
    // 8003DFF8: bc    4, 2, 0x8003E014
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003E014;
        }
    }

label_8003DFFC:
    ctx->pc = 0x8003DFFCu;
    ctx->downcount -= 5;
    // 8003DFFC: lwz     r0, -32036(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32036);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003E000:
    ctx->pc = 0x8003E000u;
    // 8003E000: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003E004:
    ctx->pc = 0x8003E004u;
    // 8003E004: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8003E008:
    ctx->pc = 0x8003E008u;
    // 8003E008: addi    r4, r1, 28
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(28);

label_8003E00C:
    ctx->pc = 0x8003E00Cu;
    // 8003E00C: bl      0x8025A660
    {
            ctx->lr = 0x8003E010u;
            ctx->pc = 0x8025A660u;
            return;
    }

label_8003E010:
    ctx->pc = 0x8003E010u;
    ctx->downcount -= 1;
    // 8003E010: b       0x8003E028
    {
            goto label_8003E028;
    }

label_8003E014:
    ctx->pc = 0x8003E014u;
    ctx->downcount -= 5;
    // 8003E014: lwz     r0, -32040(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32040);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003E018:
    ctx->pc = 0x8003E018u;
    // 8003E018: stw     r0, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003E01C:
    ctx->pc = 0x8003E01Cu;
    // 8003E01C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8003E020:
    ctx->pc = 0x8003E020u;
    // 8003E020: addi    r4, r1, 24
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(24);

label_8003E024:
    ctx->pc = 0x8003E024u;
    // 8003E024: bl      0x8025A660
    {
            ctx->lr = 0x8003E028u;
            ctx->pc = 0x8025A660u;
            return;
    }

label_8003E028:
    ctx->pc = 0x8003E028u;
    ctx->downcount -= 3;
    // 8003E028: li      r27, 0
    ctx->gpr[27] = (u32)(s32)(0);

label_8003E02C:
    ctx->pc = 0x8003E02Cu;
    // 8003E02C: addi    r28, r1, 52
    ctx->gpr[28] = ctx->gpr[1] + (u32)(s32)(52);

label_8003E030:
    ctx->pc = 0x8003E030u;
    // 8003E030: b       0x8003E04C
    {
            goto label_8003E04C;
    }

label_8003E034:
    ctx->downcount -= 4;
    // 8003E034: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8003E038:
    ctx->pc = 0x8003E038u;
    // 8003E038: lwz     r4, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8003E03C:
    // 8003E03C: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8003E040:
    // 8003E040: bl      0x8001E618
    {
            ctx->lr = 0x8003E044u;
            ctx->pc = 0x8001E618u;
            return;
    }

label_8003E044:
    ctx->downcount -= 2;
    // 8003E044: addi    r28, r28, 4
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(4);

label_8003E048:
    // 8003E048: addi    r27, r27, 1
    ctx->gpr[27] = ctx->gpr[27] + (u32)(s32)(1);

label_8003E04C:
    ctx->pc = 0x8003E04Cu;
    ctx->downcount -= 3;
    // 8003E04C: lwz     r0, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003E050:
    // 8003E050: cmpw    r27, r0
    {
        s32 val_a = (s32)(ctx->gpr[27]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003E054:
    // 8003E054: bc    12, 0, 0x8003E034
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003E034u;
                return;
            }
            goto label_8003E034;
        }
    }

label_8003E058:
    ctx->pc = 0x8003E058u;
    ctx->downcount -= 1;
    // 8003E058: b       0x8003E094
    {
            goto label_8003E094;
    }

label_8003E05C:
    ctx->pc = 0x8003E05Cu;
    ctx->downcount -= 3;
    // 8003E05C: rlwinm r0, r3, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00000001u;
    }

label_8003E060:
    ctx->pc = 0x8003E060u;
    // 8003E060: cmpwi   r0, 0
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

label_8003E064:
    ctx->pc = 0x8003E064u;
    // 8003E064: bc    12, 2, 0x8003E080
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003E080;
        }
    }

label_8003E068:
    ctx->pc = 0x8003E068u;
    ctx->downcount -= 5;
    // 8003E068: lwz     r0, -32040(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32040);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003E06C:
    ctx->pc = 0x8003E06Cu;
    // 8003E06C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003E070:
    ctx->pc = 0x8003E070u;
    // 8003E070: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8003E074:
    ctx->pc = 0x8003E074u;
    // 8003E074: addi    r4, r1, 20
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(20);

label_8003E078:
    ctx->pc = 0x8003E078u;
    // 8003E078: bl      0x8025A660
    {
            ctx->lr = 0x8003E07Cu;
            ctx->pc = 0x8025A660u;
            return;
    }

label_8003E07C:
    ctx->pc = 0x8003E07Cu;
    ctx->downcount -= 1;
    // 8003E07C: b       0x8003E094
    {
            goto label_8003E094;
    }

label_8003E080:
    ctx->pc = 0x8003E080u;
    ctx->downcount -= 5;
    // 8003E080: lwz     r0, -32036(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32036);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003E084:
    ctx->pc = 0x8003E084u;
    // 8003E084: stw     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003E088:
    ctx->pc = 0x8003E088u;
    // 8003E088: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8003E08C:
    ctx->pc = 0x8003E08Cu;
    // 8003E08C: addi    r4, r1, 16
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(16);

label_8003E090:
    ctx->pc = 0x8003E090u;
    // 8003E090: bl      0x8025A660
    {
            ctx->lr = 0x8003E094u;
            ctx->pc = 0x8025A660u;
            return;
    }

label_8003E094:
    ctx->pc = 0x8003E094u;
    ctx->downcount -= 3;
    // 8003E094: lbz     r5, 250(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(250);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_8003E098:
    ctx->pc = 0x8003E098u;
    // 8003E098: cmplwi  r5, 0x0000
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

label_8003E09C:
    ctx->pc = 0x8003E09Cu;
    // 8003E09C: bc    12, 2, 0x8003E198
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003E198;
        }
    }

label_8003E0A0:
    ctx->pc = 0x8003E0A0u;
    ctx->downcount -= 5;
    // 8003E0A0: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8003E0A4:
    ctx->pc = 0x8003E0A4u;
    // 8003E0A4: addi    r4, r13, -25892
    ctx->gpr[4] = ctx->gpr[13] + (u32)(s32)(-25892);

label_8003E0A8:
    ctx->pc = 0x8003E0A8u;
    // 8003E0A8: addi    r6, r13, -25900
    ctx->gpr[6] = ctx->gpr[13] + (u32)(s32)(-25900);

label_8003E0AC:
    ctx->pc = 0x8003E0ACu;
    // 8003E0AC: li      r7, 8
    ctx->gpr[7] = (u32)(s32)(8);

label_8003E0B0:
    ctx->pc = 0x8003E0B0u;
    // 8003E0B0: bl      0x8001EE08
    {
            ctx->lr = 0x8003E0B4u;
            ctx->pc = 0x8001EE08u;
            return;
    }

label_8003E0B4:
    ctx->pc = 0x8003E0B4u;
    ctx->downcount -= 5;
    // 8003E0B4: lwz     r3, 80(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(80);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003E0B8:
    ctx->pc = 0x8003E0B8u;
    // 8003E0B8: lbz     r0, 95(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(95);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003E0BC:
    ctx->pc = 0x8003E0BCu;
    // 8003E0BC: rlwinm r0, r0, 0, 29, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000004u;
    }

label_8003E0C0:
    ctx->pc = 0x8003E0C0u;
    // 8003E0C0: cmpwi   r0, 0
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

label_8003E0C4:
    ctx->pc = 0x8003E0C4u;
    // 8003E0C4: bc    4, 2, 0x8003E0D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003E0D4;
        }
    }

label_8003E0C8:
    ctx->pc = 0x8003E0C8u;
    ctx->downcount -= 3;
    // 8003E0C8: lbz     r0, -25916(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25916);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003E0CC:
    ctx->pc = 0x8003E0CCu;
    // 8003E0CC: cmplwi  r0, 0x0000
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

label_8003E0D0:
    ctx->pc = 0x8003E0D0u;
    // 8003E0D0: bc    12, 2, 0x8003E0DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003E0DC;
        }
    }

label_8003E0D4:
    ctx->pc = 0x8003E0D4u;
    ctx->downcount -= 2;
    // 8003E0D4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8003E0D8:
    ctx->pc = 0x8003E0D8u;
    // 8003E0D8: stw     r0, -25900(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25900);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003E0DC:
    ctx->pc = 0x8003E0DCu;
    ctx->downcount -= 5;
    // 8003E0DC: li      r27, 0
    ctx->gpr[27] = (u32)(s32)(0);

label_8003E0E0:
    ctx->pc = 0x8003E0E0u;
    // 8003E0E0: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_8003E0E4:
    ctx->pc = 0x8003E0E4u;
    // 8003E0E4: addi    r28, r13, -25892
    ctx->gpr[28] = ctx->gpr[13] + (u32)(s32)(-25892);

label_8003E0E8:
    ctx->pc = 0x8003E0E8u;
    // 8003E0E8: addi    r29, r13, -25896
    ctx->gpr[29] = ctx->gpr[13] + (u32)(s32)(-25896);

label_8003E0EC:
    ctx->pc = 0x8003E0ECu;
    // 8003E0EC: b       0x8003E18C
    {
            goto label_8003E18C;
    }

label_8003E0F0:
    ctx->pc = 0x8003E0F0u;
    ctx->downcount -= 2;
    // 8003E0F0: lwz     r3, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003E0F4:
    // 8003E0F4: bl      0x8001DC90
    {
            ctx->lr = 0x8003E0F8u;
            ctx->pc = 0x8001DC90u;
            return;
    }

label_8003E0F8:
    ctx->downcount -= 3;
    // 8003E0F8: rlwinm r0, r27, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[27], 0u) & 0x000000FFu;
    }

label_8003E0FC:
    // 8003E0FC: cmplwi  r0, 0x0000
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

label_8003E100:
    // 8003E100: bc    4, 2, 0x8003E11C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003E11C;
        }
    }

label_8003E104:
    ctx->downcount -= 2;
    // 8003E104: cmpwi   r3, 1
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003E108:
    // 8003E108: bc    4, 2, 0x8003E11C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003E11C;
        }
    }

label_8003E10C:
    ctx->downcount -= 4;
    // 8003E10C: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8003E110:
    ctx->pc = 0x8003E110u;
    // 8003E110: stb     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8003E114:
    // 8003E114: li      r27, 1
    ctx->gpr[27] = (u32)(s32)(1);

label_8003E118:
    // 8003E118: b       0x8003E138
    {
            goto label_8003E138;
    }

label_8003E11C:
    ctx->downcount -= 2;
    // 8003E11C: cmpwi   r31, 0
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

label_8003E120:
    // 8003E120: bc    4, 2, 0x8003E130
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003E130;
        }
    }

label_8003E124:
    ctx->downcount -= 3;
    // 8003E124: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_8003E128:
    ctx->pc = 0x8003E128u;
    // 8003E128: stb     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8003E12C:
    // 8003E12C: b       0x8003E138
    {
            goto label_8003E138;
    }

label_8003E130:
    ctx->downcount -= 2;
    // 8003E130: li      r0, 3
    ctx->gpr[0] = (u32)(s32)(3);

label_8003E134:
    ctx->pc = 0x8003E134u;
    // 8003E134: stb     r0, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8003E138:
    ctx->pc = 0x8003E138u;
    ctx->downcount -= 4;
    // 8003E138: lbz     r3, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8003E13C:
    // 8003E13C: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_8003E140:
    // 8003E140: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003E144:
    // 8003E144: bl      0x8001E77C
    {
            ctx->lr = 0x8003E148u;
            ctx->pc = 0x8001E77Cu;
            return;
    }

label_8003E148:
    ctx->pc = 0x8003E148u;
    ctx->downcount -= 4;
    // 8003E148: lbz     r3, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8003E14C:
    ctx->pc = 0x8003E14Cu;
    // 8003E14C: lwz     r4, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8003E150:
    // 8003E150: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8003E154:
    // 8003E154: bl      0x8001E618
    {
            ctx->lr = 0x8003E158u;
            ctx->pc = 0x8001E618u;
            return;
    }

label_8003E158:
    ctx->pc = 0x8003E158u;
    ctx->downcount -= 5;
    // 8003E158: lwz     r0, -32032(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32032);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003E15C:
    ctx->pc = 0x8003E15Cu;
    // 8003E15C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003E160:
    ctx->pc = 0x8003E160u;
    // 8003E160: lbz     r3, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8003E164:
    // 8003E164: addi    r4, r1, 12
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(12);

label_8003E168:
    // 8003E168: bl      0x8025A4F8
    {
            ctx->lr = 0x8003E16Cu;
            ctx->pc = 0x8025A4F8u;
            return;
    }

label_8003E16C:
    ctx->pc = 0x8003E16Cu;
    ctx->downcount -= 5;
    // 8003E16C: lwz     r0, -32040(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32040);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003E170:
    ctx->pc = 0x8003E170u;
    // 8003E170: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003E174:
    ctx->pc = 0x8003E174u;
    // 8003E174: lbz     r3, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8003E178:
    // 8003E178: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_8003E17C:
    // 8003E17C: bl      0x8025A660
    {
            ctx->lr = 0x8003E180u;
            ctx->pc = 0x8025A660u;
            return;
    }

label_8003E180:
    ctx->downcount -= 3;
    // 8003E180: addi    r28, r28, 4
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(4);

label_8003E184:
    // 8003E184: addi    r29, r29, 1
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(1);

label_8003E188:
    // 8003E188: addi    r31, r31, 1
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(1);

label_8003E18C:
    ctx->pc = 0x8003E18Cu;
    ctx->downcount -= 3;
    // 8003E18C: lwz     r0, -25900(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25900);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003E190:
    // 8003E190: cmpw    r31, r0
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003E194:
    // 8003E194: bc    12, 0, 0x8003E0F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003E0F0u;
                return;
            }
            goto label_8003E0F0;
        }
    }

label_8003E198:
    ctx->pc = 0x8003E198u;
    ctx->downcount -= 1;
    // 8003E198: bl      0x8001E7A8
    {
            ctx->lr = 0x8003E19Cu;
            ctx->pc = 0x8001E7A8u;
            return;
    }

label_8003E19C:
    ctx->pc = 0x8003E19Cu;
    ctx->downcount -= 5;
    // 8003E19C: lwz     r3, 80(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(80);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003E1A0:
    ctx->pc = 0x8003E1A0u;
    // 8003E1A0: lbz     r3, 95(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(95);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8003E1A4:
    ctx->pc = 0x8003E1A4u;
    // 8003E1A4: rlwinm r0, r3, 0, 29, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00000004u;
    }

label_8003E1A8:
    ctx->pc = 0x8003E1A8u;
    // 8003E1A8: cmpwi   r0, 0
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

label_8003E1AC:
    ctx->pc = 0x8003E1ACu;
    // 8003E1AC: bc    4, 2, 0x8003E1BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003E1BC;
        }
    }

label_8003E1B0:
    ctx->pc = 0x8003E1B0u;
    ctx->downcount -= 3;
    // 8003E1B0: lbz     r0, -25916(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25916);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003E1B4:
    ctx->pc = 0x8003E1B4u;
    // 8003E1B4: cmplwi  r0, 0x0000
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

label_8003E1B8:
    ctx->pc = 0x8003E1B8u;
    // 8003E1B8: bc    12, 2, 0x8003E1C8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003E1C8;
        }
    }

label_8003E1BC:
    ctx->pc = 0x8003E1BCu;
    ctx->downcount -= 3;
    // 8003E1BC: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_8003E1C0:
    ctx->pc = 0x8003E1C0u;
    // 8003E1C0: stw     r0, -25900(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25900);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003E1C4:
    ctx->pc = 0x8003E1C4u;
    // 8003E1C4: b       0x8003E1DC
    {
            goto label_8003E1DC;
    }

label_8003E1C8:
    ctx->pc = 0x8003E1C8u;
    ctx->downcount -= 3;
    // 8003E1C8: andi.   r0, r3, 0x0011
    {
        ctx->gpr[0] = ctx->gpr[3] & 0x0011u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8003E1CC:
    ctx->pc = 0x8003E1CCu;
    // 8003E1CC: cmpwi   r0, 0
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

label_8003E1D0:
    ctx->pc = 0x8003E1D0u;
    // 8003E1D0: bc    12, 2, 0x8003E1DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003E1DC;
        }
    }

label_8003E1D4:
    ctx->pc = 0x8003E1D4u;
    ctx->downcount -= 2;
    // 8003E1D4: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8003E1D8:
    ctx->pc = 0x8003E1D8u;
    // 8003E1D8: stw     r0, -25900(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25900);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003E1DC:
    ctx->pc = 0x8003E1DCu;
    ctx->downcount -= 2;
    // 8003E1DC: addi    r11, r1, 112
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(112);

label_8003E1E0:
    ctx->pc = 0x8003E1E0u;
    // 8003E1E0: bl      0x80286A98
    {
            ctx->lr = 0x8003E1E4u;
            ctx->pc = 0x80286A98u;
            return;
    }

label_8003E1E4:
    ctx->pc = 0x8003E1E4u;
    ctx->downcount -= 5;
    // 8003E1E4: lwz     r0, 116(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(116);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003E1E8:
    ctx->pc = 0x8003E1E8u;
    // 8003E1E8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8003E1EC:
    ctx->pc = 0x8003E1ECu;
    // 8003E1EC: addi    r1, r1, 112
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(112);

label_8003E1F0:
    ctx->pc = 0x8003E1F0u;
    // 8003E1F0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8003A6E0;
        }
    }

label_8003E1F4:
    ctx->pc = 0x8003E1F4u;
    ctx->downcount -= 5;
    // 8003E1F4: stwu     r1, -96(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-96);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8003E1F8:
    ctx->pc = 0x8003E1F8u;
    // 8003E1F8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8003E1FC:
    ctx->pc = 0x8003E1FCu;
    // 8003E1FC: stw     r0, 100(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(100);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003E200:
    ctx->pc = 0x8003E200u;
    // 8003E200: addi    r11, r1, 96
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(96);

label_8003E204:
    ctx->pc = 0x8003E204u;
    // 8003E204: bl      0x80286A40
    {
            ctx->lr = 0x8003E208u;
            ctx->pc = 0x80286A40u;
            return;
    }

label_8003E208:
    ctx->pc = 0x8003E208u;
    ctx->downcount -= 5;
    // 8003E208: or   r24, r3, r3
    {
        ctx->gpr[24] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003E20C:
    ctx->pc = 0x8003E20Cu;
    // 8003E20C: or   r25, r4, r4
    {
        ctx->gpr[25] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8003E210:
    ctx->pc = 0x8003E210u;
    // 8003E210: or   r26, r5, r5
    {
        ctx->gpr[26] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8003E214:
    ctx->pc = 0x8003E214u;
    // 8003E214: or   r27, r6, r6
    {
        ctx->gpr[27] = ctx->gpr[6] | ctx->gpr[6];
    }

label_8003E218:
    ctx->pc = 0x8003E218u;
    // 8003E218: bl      0x80022BB0
    {
            ctx->lr = 0x8003E21Cu;
            ctx->pc = 0x80022BB0u;
            return;
    }

label_8003E21C:
    ctx->pc = 0x8003E21Cu;
    ctx->downcount -= 4;
    // 8003E21C: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003E220:
    ctx->pc = 0x8003E220u;
    // 8003E220: lwz     r0, -25920(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25920);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003E224:
    ctx->pc = 0x8003E224u;
    // 8003E224: cmpwi   r0, 1
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

label_8003E228:
    ctx->pc = 0x8003E228u;
    // 8003E228: bc    4, 2, 0x8003E280
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003E280;
        }
    }

label_8003E22C:
    ctx->pc = 0x8003E22Cu;
    ctx->downcount -= 1;
    // 8003E22C: bl      0x80022BB0
    {
            ctx->lr = 0x8003E230u;
            ctx->pc = 0x80022BB0u;
            return;
    }

label_8003E230:
    ctx->pc = 0x8003E230u;
    ctx->downcount -= 7;
    // 8003E230: lbz     r4, 243(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(243);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_8003E234:
    ctx->pc = 0x8003E234u;
    // 8003E234: lbz     r0, 244(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(244);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003E238:
    ctx->pc = 0x8003E238u;
    // 8003E238: add   r24, r4, r0
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[24] = res;
    }

label_8003E23C:
    ctx->pc = 0x8003E23Cu;
    // 8003E23C: addi    r28, r3, 9984
    ctx->gpr[28] = ctx->gpr[3] + (u32)(s32)(9984);

label_8003E240:
    ctx->pc = 0x8003E240u;
    // 8003E240: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003E244:
    ctx->pc = 0x8003E244u;
    // 8003E244: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003E248:
    ctx->pc = 0x8003E248u;
    // 8003E248: bl      0x80022B2C
    {
            ctx->lr = 0x8003E24Cu;
            ctx->pc = 0x80022B2Cu;
            return;
    }

label_8003E24C:
    ctx->pc = 0x8003E24Cu;
    ctx->downcount -= 2;
    // 8003E24C: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_8003E250:
    ctx->pc = 0x8003E250u;
    // 8003E250: b       0x8003E270
    {
            goto label_8003E270;
    }

label_8003E254:
    ctx->downcount -= 4;
    // 8003E254: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8003E258:
    // 8003E258: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8003E25C:
    // 8003E25C: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8003E260:
    // 8003E260: bl      0x80247860
    {
            ctx->lr = 0x8003E264u;
            ctx->pc = 0x80247860u;
            return;
    }

label_8003E264:
    ctx->downcount -= 3;
    // 8003E264: addi    r28, r28, 64
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(64);

label_8003E268:
    // 8003E268: addi    r29, r29, 48
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(48);

label_8003E26C:
    // 8003E26C: addi    r30, r30, 1
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(1);

label_8003E270:
    ctx->downcount -= 2;
    // 8003E270: cmpw    r30, r24
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(ctx->gpr[24]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003E274:
    // 8003E274: bc    12, 0, 0x8003E254
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003E254u;
                return;
            }
            goto label_8003E254;
        }
    }

label_8003E278:
    ctx->pc = 0x8003E278u;
    ctx->downcount -= 2;
    // 8003E278: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_8003E27C:
    ctx->pc = 0x8003E27Cu;
    // 8003E27C: stw     r0, -25920(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25920);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003E280:
    ctx->pc = 0x8003E280u;
    ctx->downcount -= 20;
    // 8003E280: lwz     r5, 16(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(16);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8003E284:
    ctx->pc = 0x8003E284u;
    // 8003E284: srawi r0, r5, 3
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

label_8003E288:
    ctx->pc = 0x8003E288u;
    // 8003E288: lwz     r3, 0(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003E28C:
    ctx->pc = 0x8003E28Cu;
    // 8003E28C: lbzx    r4, r3, r0
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[0];
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_8003E290:
    ctx->pc = 0x8003E290u;
    // 8003E290: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8003E294:
    ctx->pc = 0x8003E294u;
    // 8003E294: lbz     r0, 1(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003E298:
    ctx->pc = 0x8003E298u;
    // 8003E298: rlwinm r0, r0, 8, 0, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 8u) & 0xFFFFFF00u;
    }

label_8003E29C:
    ctx->pc = 0x8003E29Cu;
    // 8003E29C: or   r4, r4, r0
    {
        ctx->gpr[4] = ctx->gpr[4] | ctx->gpr[0];
    }

label_8003E2A0:
    ctx->pc = 0x8003E2A0u;
    // 8003E2A0: lbz     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003E2A4:
    ctx->pc = 0x8003E2A4u;
    // 8003E2A4: rlwinm r0, r0, 16, 0, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0xFFFF0000u;
    }

label_8003E2A8:
    ctx->pc = 0x8003E2A8u;
    // 8003E2A8: or   r4, r4, r0
    {
        ctx->gpr[4] = ctx->gpr[4] | ctx->gpr[0];
    }

label_8003E2AC:
    ctx->pc = 0x8003E2ACu;
    // 8003E2AC: addi    r0, r5, 4
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(4);

label_8003E2B0:
    ctx->pc = 0x8003E2B0u;
    // 8003E2B0: stw     r0, 16(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003E2B4:
    ctx->pc = 0x8003E2B4u;
    // 8003E2B4: rlwinm r0, r5, 0, 29, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x00000007u;
    }

label_8003E2B8:
    ctx->pc = 0x8003E2B8u;
    // 8003E2B8: srw   r0, r4, r0
    {
        u32 sh = ctx->gpr[0] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[4] >> sh);
    }

label_8003E2BC:
    ctx->pc = 0x8003E2BCu;
    // 8003E2BC: rlwinm r28, r0, 0, 28, 31
    {
        ctx->gpr[28] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x0000000Fu;
    }

label_8003E2C0:
    ctx->pc = 0x8003E2C0u;
    // 8003E2C0: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_8003E2C4:
    ctx->pc = 0x8003E2C4u;
    // 8003E2C4: lis     r3, -32723
    ctx->gpr[3] = ((u32)(s32)(-32723) << 16);

label_8003E2C8:
    ctx->pc = 0x8003E2C8u;
    // 8003E2C8: addi    r30, r3, -14624
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(-14624);

label_8003E2CC:
    ctx->pc = 0x8003E2CCu;
    // 8003E2CC: b       0x8003E35C
    {
            goto label_8003E35C;
    }

label_8003E2D0:
    ctx->pc = 0x8003E2D0u;
    ctx->downcount -= 19;
    // 8003E2D0: lwz     r4, 16(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(16);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8003E2D4:
    // 8003E2D4: srawi r3, r4, 3
    {
        u32 sh = 3u;
        u32 value = ctx->gpr[4];
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

label_8003E2D8:
    ctx->pc = 0x8003E2D8u;
    // 8003E2D8: lwz     r0, 0(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003E2DC:
    // 8003E2DC: add   r5, r0, r3
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[5] = res;
    }

label_8003E2E0:
    ctx->pc = 0x8003E2E0u;
    // 8003E2E0: lbz     r3, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8003E2E4:
    ctx->pc = 0x8003E2E4u;
    // 8003E2E4: lbz     r0, 1(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003E2E8:
    // 8003E2E8: rlwinm r0, r0, 8, 0, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 8u) & 0xFFFFFF00u;
    }

label_8003E2EC:
    // 8003E2EC: or   r3, r3, r0
    {
        ctx->gpr[3] = ctx->gpr[3] | ctx->gpr[0];
    }

label_8003E2F0:
    ctx->pc = 0x8003E2F0u;
    // 8003E2F0: lbz     r0, 2(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(2);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003E2F4:
    // 8003E2F4: rlwinm r0, r0, 16, 0, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0xFFFF0000u;
    }

label_8003E2F8:
    // 8003E2F8: or   r3, r3, r0
    {
        ctx->gpr[3] = ctx->gpr[3] | ctx->gpr[0];
    }

label_8003E2FC:
    // 8003E2FC: addi    r0, r4, 8
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(8);

label_8003E300:
    ctx->pc = 0x8003E300u;
    // 8003E300: stw     r0, 16(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003E304:
    // 8003E304: rlwinm r0, r4, 0, 29, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x00000007u;
    }

label_8003E308:
    // 8003E308: srw   r0, r3, r0
    {
        u32 sh = ctx->gpr[0] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[3] >> sh);
    }

label_8003E30C:
    // 8003E30C: rlwinm r4, r0, 0, 24, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_8003E310:
    ctx->pc = 0x8003E310u;
    // 8003E310: lwz     r0, -25920(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25920);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003E314:
    // 8003E314: cmpwi   r0, 2
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003E318:
    // 8003E318: bc    4, 2, 0x8003E330
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003E330;
        }
    }

label_8003E31C:
    ctx->downcount -= 6;
    // 8003E31C: mulli   r0, r4, 48
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[4] * (s64)(s32)48);

label_8003E320:
    // 8003E320: add   r3, r31, r0
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8003E324:
    ctx->pc = 0x8003E324u;
    // 8003E324: lbz     r4, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_8003E328:
    // 8003E328: bl      0x8025DA18
    {
            ctx->lr = 0x8003E32Cu;
            ctx->pc = 0x8025DA18u;
            return;
    }

label_8003E32C:
    ctx->downcount -= 1;
    // 8003E32C: b       0x8003E354
    {
            goto label_8003E354;
    }

label_8003E330:
    ctx->downcount -= 2;
    // 8003E330: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_8003E334:
    // 8003E334: bl      0x800286CC
    {
            ctx->lr = 0x8003E338u;
            ctx->pc = 0x800286CCu;
            return;
    }

label_8003E338:
    ctx->downcount -= 4;
    // 8003E338: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003E33C:
    // 8003E33C: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8003E340:
    // 8003E340: addi    r5, r1, 8
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(8);

label_8003E344:
    // 8003E344: bl      0x80247860
    {
            ctx->lr = 0x8003E348u;
            ctx->pc = 0x80247860u;
            return;
    }

label_8003E348:
    ctx->downcount -= 3;
    // 8003E348: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_8003E34C:
    ctx->pc = 0x8003E34Cu;
    // 8003E34C: lbz     r4, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_8003E350:
    // 8003E350: bl      0x8025DA18
    {
            ctx->lr = 0x8003E354u;
            ctx->pc = 0x8025DA18u;
            return;
    }

label_8003E354:
    ctx->downcount -= 2;
    // 8003E354: addi    r30, r30, 1
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(1);

label_8003E358:
    // 8003E358: addi    r29, r29, 1
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(1);

label_8003E35C:
    ctx->downcount -= 2;
    // 8003E35C: cmpw    r29, r28
    {
        s32 val_a = (s32)(ctx->gpr[29]);
        s32 val_b = (s32)(ctx->gpr[28]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003E360:
    // 8003E360: bc    12, 0, 0x8003E2D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003E2D0u;
                return;
            }
            goto label_8003E2D0;
        }
    }

label_8003E364:
    ctx->pc = 0x8003E364u;
    ctx->downcount -= 2;
    // 8003E364: addi    r11, r1, 96
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(96);

label_8003E368:
    ctx->pc = 0x8003E368u;
    // 8003E368: bl      0x80286A8C
    {
            ctx->lr = 0x8003E36Cu;
            ctx->pc = 0x80286A8Cu;
            return;
    }

label_8003E36C:
    ctx->pc = 0x8003E36Cu;
    ctx->downcount -= 5;
    // 8003E36C: lwz     r0, 100(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(100);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003E370:
    ctx->pc = 0x8003E370u;
    // 8003E370: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8003E374:
    ctx->pc = 0x8003E374u;
    // 8003E374: addi    r1, r1, 96
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(96);

label_8003E378:
    ctx->pc = 0x8003E378u;
    // 8003E378: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8003A6E0;
        }
    }

label_8003E37C:
    ctx->pc = 0x8003E37Cu;
    ctx->downcount -= 5;
    // 8003E37C: stwu     r1, -112(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-112);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8003E380:
    ctx->pc = 0x8003E380u;
    // 8003E380: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8003E384:
    ctx->pc = 0x8003E384u;
    // 8003E384: stw     r0, 116(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(116);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003E388:
    ctx->pc = 0x8003E388u;
    // 8003E388: addi    r11, r1, 112
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(112);

label_8003E38C:
    ctx->pc = 0x8003E38Cu;
    // 8003E38C: bl      0x80286A2C
    {
            ctx->lr = 0x8003E390u;
            ctx->pc = 0x80286A2Cu;
            return;
    }

label_8003E390:
    ctx->pc = 0x8003E390u;
    ctx->downcount -= 11;
    // 8003E390: or   r19, r3, r3
    {
        ctx->gpr[19] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003E394:
    ctx->pc = 0x8003E394u;
    // 8003E394: or   r25, r4, r4
    {
        ctx->gpr[25] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8003E398:
    ctx->pc = 0x8003E398u;
    // 8003E398: or   r26, r5, r5
    {
        ctx->gpr[26] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8003E39C:
    ctx->pc = 0x8003E39Cu;
    // 8003E39C: or   r27, r6, r6
    {
        ctx->gpr[27] = ctx->gpr[6] | ctx->gpr[6];
    }

label_8003E3A0:
    ctx->pc = 0x8003E3A0u;
    // 8003E3A0: or   r28, r7, r7
    {
        ctx->gpr[28] = ctx->gpr[7] | ctx->gpr[7];
    }

label_8003E3A4:
    ctx->pc = 0x8003E3A4u;
    // 8003E3A4: or   r29, r8, r8
    {
        ctx->gpr[29] = ctx->gpr[8] | ctx->gpr[8];
    }

label_8003E3A8:
    ctx->pc = 0x8003E3A8u;
    // 8003E3A8: or   r30, r9, r9
    {
        ctx->gpr[30] = ctx->gpr[9] | ctx->gpr[9];
    }

label_8003E3AC:
    ctx->pc = 0x8003E3ACu;
    // 8003E3AC: or   r31, r10, r10
    {
        ctx->gpr[31] = ctx->gpr[10] | ctx->gpr[10];
    }

label_8003E3B0:
    ctx->pc = 0x8003E3B0u;
    // 8003E3B0: lis     r3, -32723
    ctx->gpr[3] = ((u32)(s32)(-32723) << 16);

label_8003E3B4:
    ctx->pc = 0x8003E3B4u;
    // 8003E3B4: addi    r23, r3, -14624
    ctx->gpr[23] = ctx->gpr[3] + (u32)(s32)(-14624);

label_8003E3B8:
    ctx->pc = 0x8003E3B8u;
    // 8003E3B8: bl      0x80022BB0
    {
            ctx->lr = 0x8003E3BCu;
            ctx->pc = 0x80022BB0u;
            return;
    }

label_8003E3BC:
    ctx->pc = 0x8003E3BCu;
    ctx->downcount -= 4;
    // 8003E3BC: or   r24, r3, r3
    {
        ctx->gpr[24] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003E3C0:
    ctx->pc = 0x8003E3C0u;
    // 8003E3C0: lwz     r0, -25920(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25920);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003E3C4:
    ctx->pc = 0x8003E3C4u;
    // 8003E3C4: cmpwi   r0, 1
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

label_8003E3C8:
    ctx->pc = 0x8003E3C8u;
    // 8003E3C8: bc    4, 2, 0x8003E444
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003E444;
        }
    }

label_8003E3CC:
    ctx->pc = 0x8003E3CCu;
    ctx->downcount -= 3;
    // 8003E3CC: rlwinm r0, r31, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[31], 0u) & 0x000000FFu;
    }

label_8003E3D0:
    ctx->pc = 0x8003E3D0u;
    // 8003E3D0: cmplwi  r0, 0x0000
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

label_8003E3D4:
    ctx->pc = 0x8003E3D4u;
    // 8003E3D4: bc    4, 2, 0x8003E3F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003E3F0;
        }
    }

label_8003E3D8:
    ctx->pc = 0x8003E3D8u;
    ctx->downcount -= 5;
    // 8003E3D8: or   r3, r19, r19
    {
        ctx->gpr[3] = ctx->gpr[19] | ctx->gpr[19];
    }

label_8003E3DC:
    ctx->pc = 0x8003E3DCu;
    // 8003E3DC: or   r4, r25, r25
    {
        ctx->gpr[4] = ctx->gpr[25] | ctx->gpr[25];
    }

label_8003E3E0:
    ctx->pc = 0x8003E3E0u;
    // 8003E3E0: or   r5, r28, r28
    {
        ctx->gpr[5] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8003E3E4:
    ctx->pc = 0x8003E3E4u;
    // 8003E3E4: or   r6, r27, r27
    {
        ctx->gpr[6] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8003E3E8:
    ctx->pc = 0x8003E3E8u;
    // 8003E3E8: bl      0x8003BFCC
    {
            ctx->lr = 0x8003E3ECu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003BFCCu;
                return;
            }
            goto label_8003BFCC;
    }

label_8003E3EC:
    ctx->pc = 0x8003E3ECu;
    ctx->downcount -= 1;
    // 8003E3EC: b       0x8003E444
    {
            goto label_8003E444;
    }

label_8003E3F0:
    ctx->pc = 0x8003E3F0u;
    ctx->downcount -= 1;
    // 8003E3F0: bl      0x80022BB0
    {
            ctx->lr = 0x8003E3F4u;
            ctx->pc = 0x80022BB0u;
            return;
    }

label_8003E3F4:
    ctx->pc = 0x8003E3F4u;
    ctx->downcount -= 7;
    // 8003E3F4: lbz     r4, 243(r19)
    {
        u32 ea = ctx->gpr[19] + (u32)(s32)(243);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_8003E3F8:
    ctx->pc = 0x8003E3F8u;
    // 8003E3F8: lbz     r0, 244(r19)
    {
        u32 ea = ctx->gpr[19] + (u32)(s32)(244);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003E3FC:
    ctx->pc = 0x8003E3FCu;
    // 8003E3FC: add   r22, r4, r0
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[22] = res;
    }

label_8003E400:
    ctx->pc = 0x8003E400u;
    // 8003E400: addi    r19, r3, 9984
    ctx->gpr[19] = ctx->gpr[3] + (u32)(s32)(9984);

label_8003E404:
    ctx->pc = 0x8003E404u;
    // 8003E404: or   r20, r3, r3
    {
        ctx->gpr[20] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003E408:
    ctx->pc = 0x8003E408u;
    // 8003E408: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8003E40C:
    ctx->pc = 0x8003E40Cu;
    // 8003E40C: bl      0x80022B2C
    {
            ctx->lr = 0x8003E410u;
            ctx->pc = 0x80022B2Cu;
            return;
    }

label_8003E410:
    ctx->pc = 0x8003E410u;
    ctx->downcount -= 2;
    // 8003E410: li      r21, 0
    ctx->gpr[21] = (u32)(s32)(0);

label_8003E414:
    ctx->pc = 0x8003E414u;
    // 8003E414: b       0x8003E434
    {
            goto label_8003E434;
    }

label_8003E418:
    ctx->downcount -= 4;
    // 8003E418: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8003E41C:
    // 8003E41C: or   r4, r19, r19
    {
        ctx->gpr[4] = ctx->gpr[19] | ctx->gpr[19];
    }

label_8003E420:
    // 8003E420: or   r5, r20, r20
    {
        ctx->gpr[5] = ctx->gpr[20] | ctx->gpr[20];
    }

label_8003E424:
    // 8003E424: bl      0x80247860
    {
            ctx->lr = 0x8003E428u;
            ctx->pc = 0x80247860u;
            return;
    }

label_8003E428:
    ctx->downcount -= 3;
    // 8003E428: addi    r19, r19, 64
    ctx->gpr[19] = ctx->gpr[19] + (u32)(s32)(64);

label_8003E42C:
    // 8003E42C: addi    r20, r20, 48
    ctx->gpr[20] = ctx->gpr[20] + (u32)(s32)(48);

label_8003E430:
    // 8003E430: addi    r21, r21, 1
    ctx->gpr[21] = ctx->gpr[21] + (u32)(s32)(1);

label_8003E434:
    ctx->downcount -= 2;
    // 8003E434: cmpw    r21, r22
    {
        s32 val_a = (s32)(ctx->gpr[21]);
        s32 val_b = (s32)(ctx->gpr[22]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003E438:
    // 8003E438: bc    12, 0, 0x8003E418
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003E418u;
                return;
            }
            goto label_8003E418;
        }
    }

label_8003E43C:
    ctx->pc = 0x8003E43Cu;
    ctx->downcount -= 2;
    // 8003E43C: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_8003E440:
    ctx->pc = 0x8003E440u;
    // 8003E440: stw     r0, -25920(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25920);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003E444:
    ctx->pc = 0x8003E444u;
    ctx->downcount -= 18;
    // 8003E444: lwz     r5, 16(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(16);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8003E448:
    ctx->pc = 0x8003E448u;
    // 8003E448: srawi r0, r5, 3
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

label_8003E44C:
    ctx->pc = 0x8003E44Cu;
    // 8003E44C: lwz     r3, 0(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003E450:
    ctx->pc = 0x8003E450u;
    // 8003E450: lbzx    r4, r3, r0
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[0];
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_8003E454:
    ctx->pc = 0x8003E454u;
    // 8003E454: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8003E458:
    ctx->pc = 0x8003E458u;
    // 8003E458: lbz     r0, 1(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003E45C:
    ctx->pc = 0x8003E45Cu;
    // 8003E45C: rlwinm r0, r0, 8, 0, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 8u) & 0xFFFFFF00u;
    }

label_8003E460:
    ctx->pc = 0x8003E460u;
    // 8003E460: or   r4, r4, r0
    {
        ctx->gpr[4] = ctx->gpr[4] | ctx->gpr[0];
    }

label_8003E464:
    ctx->pc = 0x8003E464u;
    // 8003E464: lbz     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003E468:
    ctx->pc = 0x8003E468u;
    // 8003E468: rlwinm r0, r0, 16, 0, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0xFFFF0000u;
    }

label_8003E46C:
    ctx->pc = 0x8003E46Cu;
    // 8003E46C: or   r4, r4, r0
    {
        ctx->gpr[4] = ctx->gpr[4] | ctx->gpr[0];
    }

label_8003E470:
    ctx->pc = 0x8003E470u;
    // 8003E470: addi    r0, r5, 4
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(4);

label_8003E474:
    ctx->pc = 0x8003E474u;
    // 8003E474: stw     r0, 16(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003E478:
    ctx->pc = 0x8003E478u;
    // 8003E478: rlwinm r0, r5, 0, 29, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x00000007u;
    }

label_8003E47C:
    ctx->pc = 0x8003E47Cu;
    // 8003E47C: srw   r0, r4, r0
    {
        u32 sh = ctx->gpr[0] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[4] >> sh);
    }

label_8003E480:
    ctx->pc = 0x8003E480u;
    // 8003E480: rlwinm r20, r0, 0, 28, 31
    {
        ctx->gpr[20] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x0000000Fu;
    }

label_8003E484:
    ctx->pc = 0x8003E484u;
    // 8003E484: cmpwi   r20, 0
    {
        s32 val_a = (s32)(ctx->gpr[20]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003E488:
    ctx->pc = 0x8003E488u;
    // 8003E488: bc    12, 0, 0x8003E494
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003E494;
        }
    }

label_8003E48C:
    ctx->pc = 0x8003E48Cu;
    ctx->downcount -= 2;
    // 8003E48C: cmpwi   r20, 20
    {
        s32 val_a = (s32)(ctx->gpr[20]);
        s32 val_b = (s32)(20);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003E490:
    ctx->pc = 0x8003E490u;
    // 8003E490: bc    4, 1, 0x8003E4A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003E4A4;
        }
    }

label_8003E494:
    ctx->pc = 0x8003E494u;
    ctx->downcount -= 4;
    // 8003E494: addi    r3, r23, 72
    ctx->gpr[3] = ctx->gpr[23] + (u32)(s32)(72);

label_8003E498:
    ctx->pc = 0x8003E498u;
    // 8003E498: or   r4, r20, r20
    {
        ctx->gpr[4] = ctx->gpr[20] | ctx->gpr[20];
    }

label_8003E49C:
    ctx->pc = 0x8003E49Cu;
    // 8003E49C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8003E4A0:
    ctx->pc = 0x8003E4A0u;
    // 8003E4A0: bl      0x8007D8C0
    {
            ctx->lr = 0x8003E4A4u;
            ctx->pc = 0x8007D8C0u;
            return;
    }

label_8003E4A4:
    ctx->pc = 0x8003E4A4u;
    ctx->downcount -= 3;
    // 8003E4A4: li      r21, 0
    ctx->gpr[21] = (u32)(s32)(0);

label_8003E4A8:
    ctx->pc = 0x8003E4A8u;
    // 8003E4A8: addi    r22, r23, 12
    ctx->gpr[22] = ctx->gpr[23] + (u32)(s32)(12);

label_8003E4AC:
    ctx->pc = 0x8003E4ACu;
    // 8003E4AC: b       0x8003E608
    {
            goto label_8003E608;
    }

label_8003E4B0:
    ctx->pc = 0x8003E4B0u;
    ctx->downcount -= 19;
    // 8003E4B0: lwz     r4, 16(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(16);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8003E4B4:
    // 8003E4B4: srawi r3, r4, 3
    {
        u32 sh = 3u;
        u32 value = ctx->gpr[4];
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

label_8003E4B8:
    ctx->pc = 0x8003E4B8u;
    // 8003E4B8: lwz     r0, 0(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003E4BC:
    // 8003E4BC: add   r5, r0, r3
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[5] = res;
    }

label_8003E4C0:
    ctx->pc = 0x8003E4C0u;
    // 8003E4C0: lbz     r3, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8003E4C4:
    ctx->pc = 0x8003E4C4u;
    // 8003E4C4: lbz     r0, 1(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003E4C8:
    // 8003E4C8: rlwinm r0, r0, 8, 0, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 8u) & 0xFFFFFF00u;
    }

label_8003E4CC:
    // 8003E4CC: or   r3, r3, r0
    {
        ctx->gpr[3] = ctx->gpr[3] | ctx->gpr[0];
    }

label_8003E4D0:
    ctx->pc = 0x8003E4D0u;
    // 8003E4D0: lbz     r0, 2(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(2);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003E4D4:
    // 8003E4D4: rlwinm r0, r0, 16, 0, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0xFFFF0000u;
    }

label_8003E4D8:
    // 8003E4D8: or   r3, r3, r0
    {
        ctx->gpr[3] = ctx->gpr[3] | ctx->gpr[0];
    }

label_8003E4DC:
    // 8003E4DC: addi    r0, r4, 8
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(8);

label_8003E4E0:
    ctx->pc = 0x8003E4E0u;
    // 8003E4E0: stw     r0, 16(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003E4E4:
    // 8003E4E4: rlwinm r0, r4, 0, 29, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x00000007u;
    }

label_8003E4E8:
    // 8003E4E8: srw   r0, r3, r0
    {
        u32 sh = ctx->gpr[0] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[3] >> sh);
    }

label_8003E4EC:
    // 8003E4EC: rlwinm r4, r0, 0, 24, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_8003E4F0:
    ctx->pc = 0x8003E4F0u;
    // 8003E4F0: lwz     r0, -25920(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25920);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003E4F4:
    // 8003E4F4: cmpwi   r0, 2
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003E4F8:
    // 8003E4F8: bc    4, 2, 0x8003E560
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003E560;
        }
    }

label_8003E4FC:
    ctx->downcount -= 7;
    // 8003E4FC: mulli   r0, r4, 48
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[4] * (s64)(s32)48);

label_8003E500:
    // 8003E500: add   r3, r24, r0
    {
        u32 a = ctx->gpr[24];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8003E504:
    // 8003E504: addi    r19, r3, 4800
    ctx->gpr[19] = ctx->gpr[3] + (u32)(s32)(4800);

label_8003E508:
    ctx->pc = 0x8003E508u;
    // 8003E508: lbz     r4, 0(r23)
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_8003E50C:
    // 8003E50C: bl      0x8025DA18
    {
            ctx->lr = 0x8003E510u;
            ctx->pc = 0x8025DA18u;
            return;
    }

label_8003E510:
    ctx->downcount -= 3;
    // 8003E510: rlwinm r0, r31, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[31], 0u) & 0x000000FFu;
    }

label_8003E514:
    // 8003E514: cmplwi  r0, 0x0000
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

label_8003E518:
    // 8003E518: bc    4, 2, 0x8003E538
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003E538;
        }
    }

label_8003E51C:
    ctx->downcount -= 3;
    // 8003E51C: rlwinm r0, r30, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[30], 0u) & 0x000000FFu;
    }

label_8003E520:
    // 8003E520: cmplwi  r0, 0x0000
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

label_8003E524:
    // 8003E524: bc    12, 2, 0x8003E538
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003E538;
        }
    }

label_8003E528:
    ctx->downcount -= 4;
    // 8003E528: or   r3, r19, r19
    {
        ctx->gpr[3] = ctx->gpr[19] | ctx->gpr[19];
    }

label_8003E52C:
    ctx->pc = 0x8003E52Cu;
    // 8003E52C: lbz     r4, 0(r22)
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_8003E530:
    // 8003E530: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003E534:
    // 8003E534: bl      0x8025DAD0
    {
            ctx->lr = 0x8003E538u;
            ctx->pc = 0x8025DAD0u;
            return;
    }

label_8003E538:
    ctx->downcount -= 3;
    // 8003E538: rlwinm r0, r31, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[31], 0u) & 0x000000FFu;
    }

label_8003E53C:
    // 8003E53C: cmplwi  r0, 0x0000
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

label_8003E540:
    // 8003E540: bc    4, 2, 0x8003E5FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003E5FC;
        }
    }

label_8003E544:
    ctx->downcount -= 3;
    // 8003E544: rlwinm r0, r29, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[29], 0u) & 0x000000FFu;
    }

label_8003E548:
    // 8003E548: cmplwi  r0, 0x0000
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

label_8003E54C:
    // 8003E54C: bc    12, 2, 0x8003E5FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003E5FC;
        }
    }

label_8003E550:
    ctx->downcount -= 3;
    // 8003E550: or   r3, r19, r19
    {
        ctx->gpr[3] = ctx->gpr[19] | ctx->gpr[19];
    }

label_8003E554:
    ctx->pc = 0x8003E554u;
    // 8003E554: lbz     r4, 0(r23)
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_8003E558:
    // 8003E558: bl      0x8025DA54
    {
            ctx->lr = 0x8003E55Cu;
            ctx->pc = 0x8025DA54u;
            return;
    }

label_8003E55C:
    ctx->downcount -= 1;
    // 8003E55C: b       0x8003E5FC
    {
            goto label_8003E5FC;
    }

label_8003E560:
    ctx->downcount -= 2;
    // 8003E560: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_8003E564:
    // 8003E564: bl      0x800286CC
    {
            ctx->lr = 0x8003E568u;
            ctx->pc = 0x800286CCu;
            return;
    }

label_8003E568:
    ctx->downcount -= 4;
    // 8003E568: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003E56C:
    // 8003E56C: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8003E570:
    // 8003E570: addi    r5, r1, 8
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(8);

label_8003E574:
    // 8003E574: bl      0x80247860
    {
            ctx->lr = 0x8003E578u;
            ctx->pc = 0x80247860u;
            return;
    }

label_8003E578:
    ctx->downcount -= 3;
    // 8003E578: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_8003E57C:
    ctx->pc = 0x8003E57Cu;
    // 8003E57C: lbz     r4, 0(r23)
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_8003E580:
    // 8003E580: bl      0x8025DA18
    {
            ctx->lr = 0x8003E584u;
            ctx->pc = 0x8025DA18u;
            return;
    }

label_8003E584:
    ctx->downcount -= 3;
    // 8003E584: rlwinm r0, r31, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[31], 0u) & 0x000000FFu;
    }

label_8003E588:
    // 8003E588: cmplwi  r0, 0x0000
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

label_8003E58C:
    // 8003E58C: bc    4, 2, 0x8003E5FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003E5FC;
        }
    }

label_8003E590:
    ctx->downcount -= 3;
    // 8003E590: rlwinm r0, r29, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[29], 0u) & 0x000000FFu;
    }

label_8003E594:
    // 8003E594: cmplwi  r0, 0x0000
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

label_8003E598:
    // 8003E598: bc    4, 2, 0x8003E5A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003E5A8;
        }
    }

label_8003E59C:
    ctx->downcount -= 3;
    // 8003E59C: rlwinm r0, r30, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[30], 0u) & 0x000000FFu;
    }

label_8003E5A0:
    // 8003E5A0: cmplwi  r0, 0x0000
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

label_8003E5A4:
    // 8003E5A4: bc    12, 2, 0x8003E5FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003E5FC;
        }
    }

label_8003E5A8:
    ctx->pc = 0x8003E5A8u;
    ctx->downcount -= 8;
    // 8003E5A8: lfs     f0, -31476(r2)
    if (!ppc_fp_available_inline(ctx, 0x8003E5A8u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(-31476);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8003E5AC:
    ctx->pc = 0x8003E5ACu;
    // 8003E5AC: stfs     f0, 20(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003E5ACu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003E5B0:
    ctx->pc = 0x8003E5B0u;
    // 8003E5B0: stfs     f0, 36(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003E5B0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003E5B4:
    ctx->pc = 0x8003E5B4u;
    // 8003E5B4: stfs     f0, 52(r1)
    if (!ppc_fp_available_inline(ctx, 0x8003E5B4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8003E5B8:
    // 8003E5B8: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_8003E5BC:
    // 8003E5BC: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8003E5C0:
    // 8003E5C0: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8003E5C4:
    // 8003E5C4: bl      0x80247860
    {
            ctx->lr = 0x8003E5C8u;
            ctx->pc = 0x80247860u;
            return;
    }

label_8003E5C8:
    ctx->downcount -= 3;
    // 8003E5C8: rlwinm r0, r30, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[30], 0u) & 0x000000FFu;
    }

label_8003E5CC:
    // 8003E5CC: cmplwi  r0, 0x0000
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

label_8003E5D0:
    // 8003E5D0: bc    12, 2, 0x8003E5E4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003E5E4;
        }
    }

label_8003E5D4:
    ctx->downcount -= 4;
    // 8003E5D4: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_8003E5D8:
    ctx->pc = 0x8003E5D8u;
    // 8003E5D8: lbz     r4, 0(r22)
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_8003E5DC:
    // 8003E5DC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8003E5E0:
    // 8003E5E0: bl      0x8025DAD0
    {
            ctx->lr = 0x8003E5E4u;
            ctx->pc = 0x8025DAD0u;
            return;
    }

label_8003E5E4:
    ctx->downcount -= 3;
    // 8003E5E4: rlwinm r0, r29, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[29], 0u) & 0x000000FFu;
    }

label_8003E5E8:
    // 8003E5E8: cmplwi  r0, 0x0000
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

label_8003E5EC:
    // 8003E5EC: bc    12, 2, 0x8003E5FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003E5FC;
        }
    }

label_8003E5F0:
    ctx->downcount -= 3;
    // 8003E5F0: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_8003E5F4:
    ctx->pc = 0x8003E5F4u;
    // 8003E5F4: lbz     r4, 0(r23)
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_8003E5F8:
    // 8003E5F8: bl      0x8025DA54
    {
            ctx->lr = 0x8003E5FCu;
            ctx->pc = 0x8025DA54u;
            return;
    }

label_8003E5FC:
    ctx->downcount -= 3;
    // 8003E5FC: addi    r23, r23, 1
    ctx->gpr[23] = ctx->gpr[23] + (u32)(s32)(1);

label_8003E600:
    // 8003E600: addi    r22, r22, 1
    ctx->gpr[22] = ctx->gpr[22] + (u32)(s32)(1);

label_8003E604:
    // 8003E604: addi    r21, r21, 1
    ctx->gpr[21] = ctx->gpr[21] + (u32)(s32)(1);

label_8003E608:
    ctx->downcount -= 2;
    // 8003E608: cmpw    r21, r20
    {
        s32 val_a = (s32)(ctx->gpr[21]);
        s32 val_b = (s32)(ctx->gpr[20]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8003E60C:
    // 8003E60C: bc    12, 0, 0x8003E4B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8003E4B0u;
                return;
            }
            goto label_8003E4B0;
        }
    }

label_8003E610:
    ctx->pc = 0x8003E610u;
    ctx->downcount -= 2;
    // 8003E610: addi    r11, r1, 112
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(112);

label_8003E614:
    ctx->pc = 0x8003E614u;
    // 8003E614: bl      0x80286A78
    {
            ctx->lr = 0x8003E618u;
            ctx->pc = 0x80286A78u;
            return;
    }

label_8003E618:
    ctx->pc = 0x8003E618u;
    ctx->downcount -= 5;
    // 8003E618: lwz     r0, 116(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(116);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8003E61C:
    ctx->pc = 0x8003E61Cu;
    // 8003E61C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8003E620:
    ctx->pc = 0x8003E620u;
    // 8003E620: addi    r1, r1, 112
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(112);

label_8003E624:
    ctx->pc = 0x8003E624u;
    // 8003E624: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8003A6E0;
        }
    }

label_8003E628:
    ctx->pc = 0x8003E628u;
    ctx->downcount -= 8;
    // 8003E628: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8003E62C:
    ctx->pc = 0x8003E62Cu;
    // 8003E62C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8003E630:
    ctx->pc = 0x8003E630u;
    // 8003E630: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003E634:
    ctx->pc = 0x8003E634u;
    // 8003E634: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8003E638:
    ctx->pc = 0x8003E638u;
    // 8003E638: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_8003E63C:
    ctx->pc = 0x8003E63Cu;
    // 8003E63C: lbz     r0, 243(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(243);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003E640:
    ctx->pc = 0x8003E640u;
    // 8003E640: cmplwi  r0, 0x0001
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

label_8003E644:
    ctx->pc = 0x8003E644u;
    // 8003E644: bc    4, 1, 0x8003E64C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8003E64C;
        }
    }

label_8003E648:
    ctx->pc = 0x8003E648u;
    ctx->downcount -= 1;
    // 8003E648: ori     r31, r31, 0x0001
    ctx->gpr[31] = ctx->gpr[31] | 0x0001u;

label_8003E64C:
    ctx->pc = 0x8003E64Cu;
    ctx->downcount -= 18;
    // 8003E64C: lwz     r6, 16(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(16);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8003E650:
    ctx->pc = 0x8003E650u;
    // 8003E650: srawi r0, r6, 3
    {
        u32 sh = 3u;
        u32 value = ctx->gpr[6];
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

label_8003E654:
    ctx->pc = 0x8003E654u;
    // 8003E654: lwz     r3, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003E658:
    ctx->pc = 0x8003E658u;
    // 8003E658: lbzx    r4, r3, r0
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[0];
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_8003E65C:
    ctx->pc = 0x8003E65Cu;
    // 8003E65C: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8003E660:
    ctx->pc = 0x8003E660u;
    // 8003E660: lbz     r0, 1(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003E664:
    ctx->pc = 0x8003E664u;
    // 8003E664: rlwinm r0, r0, 8, 0, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 8u) & 0xFFFFFF00u;
    }

label_8003E668:
    ctx->pc = 0x8003E668u;
    // 8003E668: or   r4, r4, r0
    {
        ctx->gpr[4] = ctx->gpr[4] | ctx->gpr[0];
    }

label_8003E66C:
    ctx->pc = 0x8003E66Cu;
    // 8003E66C: lbz     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003E670:
    ctx->pc = 0x8003E670u;
    // 8003E670: rlwinm r0, r0, 16, 0, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0xFFFF0000u;
    }

label_8003E674:
    ctx->pc = 0x8003E674u;
    // 8003E674: or   r4, r4, r0
    {
        ctx->gpr[4] = ctx->gpr[4] | ctx->gpr[0];
    }

label_8003E678:
    ctx->pc = 0x8003E678u;
    // 8003E678: addi    r0, r6, 1
    ctx->gpr[0] = ctx->gpr[6] + (u32)(s32)(1);

label_8003E67C:
    ctx->pc = 0x8003E67Cu;
    // 8003E67C: stw     r0, 16(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003E680:
    ctx->pc = 0x8003E680u;
    // 8003E680: rlwinm r0, r6, 0, 29, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x00000007u;
    }

label_8003E684:
    ctx->pc = 0x8003E684u;
    // 8003E684: srw   r0, r4, r0
    {
        u32 sh = ctx->gpr[0] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[4] >> sh);
    }

label_8003E688:
    ctx->pc = 0x8003E688u;
    // 8003E688: rlwinm r0, r0, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000001u;
    }

label_8003E68C:
    ctx->pc = 0x8003E68Cu;
    // 8003E68C: cmpwi   r0, 0
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

label_8003E690:
    ctx->pc = 0x8003E690u;
    // 8003E690: bc    12, 2, 0x8003E69C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8003E69C;
        }
    }

label_8003E694:
    ctx->pc = 0x8003E694u;
    ctx->downcount -= 2;
    // 8003E694: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_8003E698:
    ctx->pc = 0x8003E698u;
    // 8003E698: b       0x8003E6A0
    {
            goto label_8003E6A0;
    }

label_8003E69C:
    ctx->pc = 0x8003E69Cu;
    ctx->downcount -= 1;
    // 8003E69C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8003E6A0:
    ctx->pc = 0x8003E6A0u;
    ctx->downcount -= 16;
    // 8003E6A0: or   r31, r31, r0
    {
        ctx->gpr[31] = ctx->gpr[31] | ctx->gpr[0];
    }

label_8003E6A4:
    ctx->pc = 0x8003E6A4u;
    // 8003E6A4: lwz     r6, 16(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(16);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8003E6A8:
    ctx->pc = 0x8003E6A8u;
    // 8003E6A8: srawi r0, r6, 3
    {
        u32 sh = 3u;
        u32 value = ctx->gpr[6];
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

label_8003E6AC:
    ctx->pc = 0x8003E6ACu;
    // 8003E6AC: lwz     r3, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8003E6B0:
    ctx->pc = 0x8003E6B0u;
    // 8003E6B0: lbzx    r4, r3, r0
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[0];
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_8003E6B4:
    ctx->pc = 0x8003E6B4u;
    // 8003E6B4: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8003E6B8:
    ctx->pc = 0x8003E6B8u;
    // 8003E6B8: lbz     r0, 1(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003E6BC:
    ctx->pc = 0x8003E6BCu;
    // 8003E6BC: rlwinm r0, r0, 8, 0, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 8u) & 0xFFFFFF00u;
    }

label_8003E6C0:
    ctx->pc = 0x8003E6C0u;
    // 8003E6C0: or   r4, r4, r0
    {
        ctx->gpr[4] = ctx->gpr[4] | ctx->gpr[0];
    }

label_8003E6C4:
    ctx->pc = 0x8003E6C4u;
    // 8003E6C4: lbz     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8003E6C8:
    ctx->pc = 0x8003E6C8u;
    // 8003E6C8: rlwinm r0, r0, 16, 0, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0xFFFF0000u;
    }

label_8003E6CC:
    ctx->pc = 0x8003E6CCu;
    // 8003E6CC: or   r4, r4, r0
    {
        ctx->gpr[4] = ctx->gpr[4] | ctx->gpr[0];
    }

label_8003E6D0:
    ctx->pc = 0x8003E6D0u;
    // 8003E6D0: addi    r0, r6, 1
    ctx->gpr[0] = ctx->gpr[6] + (u32)(s32)(1);

label_8003E6D4:
    ctx->pc = 0x8003E6D4u;
    // 8003E6D4: stw     r0, 16(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8003E6D8:
    ctx->pc = 0x8003E6D8u;
    // 8003E6D8: rlwinm r0, r6, 0, 29, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x00000007u;
    }

label_8003E6DC:
    ctx->pc = 0x8003E6DCu;
    // 8003E6DC: srw   r0, r4, r0
    {
        u32 sh = ctx->gpr[0] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[4] >> sh);
    }

    ctx->pc = 0x8003E6E0u;
    return;
return_dispatch_8003A6E0:
    if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) return;
    switch (ctx->pc) {
    case 0x8003A860u: goto label_8003A860;
    case 0x8003A87Cu: goto label_8003A87C;
    case 0x8003AA38u: goto label_8003AA38;
    case 0x8003AA5Cu: goto label_8003AA5C;
    case 0x8003AAFCu: goto label_8003AAFC;
    case 0x8003AB14u: goto label_8003AB14;
    case 0x8003AB44u: goto label_8003AB44;
    case 0x8003AF8Cu: goto label_8003AF8C;
    case 0x8003B078u: goto label_8003B078;
    case 0x8003B088u: goto label_8003B088;
    case 0x8003B108u: goto label_8003B108;
    case 0x8003B254u: goto label_8003B254;
    case 0x8003B324u: goto label_8003B324;
    case 0x8003B5D0u: goto label_8003B5D0;
    case 0x8003B67Cu: goto label_8003B67C;
    case 0x8003B750u: goto label_8003B750;
    case 0x8003B7C8u: goto label_8003B7C8;
    case 0x8003B840u: goto label_8003B840;
    case 0x8003B878u: goto label_8003B878;
    case 0x8003B920u: goto label_8003B920;
    case 0x8003B9BCu: goto label_8003B9BC;
    case 0x8003B9F0u: goto label_8003B9F0;
    case 0x8003BA10u: goto label_8003BA10;
    case 0x8003BA1Cu: goto label_8003BA1C;
    case 0x8003BA3Cu: goto label_8003BA3C;
    case 0x8003BA78u: goto label_8003BA78;
    case 0x8003BABCu: goto label_8003BABC;
    case 0x8003BAD0u: goto label_8003BAD0;
    case 0x8003BB00u: goto label_8003BB00;
    case 0x8003BB6Cu: goto label_8003BB6C;
    case 0x8003BBC8u: goto label_8003BBC8;
    case 0x8003BBFCu: goto label_8003BBFC;
    case 0x8003BC10u: goto label_8003BC10;
    case 0x8003BC58u: goto label_8003BC58;
    case 0x8003BC80u: goto label_8003BC80;
    case 0x8003BC94u: goto label_8003BC94;
    case 0x8003BC98u: goto label_8003BC98;
    case 0x8003BCDCu: goto label_8003BCDC;
    case 0x8003BCF8u: goto label_8003BCF8;
    case 0x8003BDF4u: goto label_8003BDF4;
    case 0x8003BE00u: goto label_8003BE00;
    case 0x8003BE0Cu: goto label_8003BE0C;
    case 0x8003BEB8u: goto label_8003BEB8;
    case 0x8003BED4u: goto label_8003BED4;
    case 0x8003BEFCu: goto label_8003BEFC;
    case 0x8003BF0Cu: goto label_8003BF0C;
    case 0x8003BF20u: goto label_8003BF20;
    case 0x8003BF38u: goto label_8003BF38;
    case 0x8003BFE8u: goto label_8003BFE8;
    case 0x8003BFF8u: goto label_8003BFF8;
    case 0x8003C018u: goto label_8003C018;
    case 0x8003C034u: goto label_8003C034;
    case 0x8003C044u: goto label_8003C044;
    case 0x8003C080u: goto label_8003C080;
    case 0x8003C0CCu: goto label_8003C0CC;
    case 0x8003C108u: goto label_8003C108;
    case 0x8003C118u: goto label_8003C118;
    case 0x8003C128u: goto label_8003C128;
    case 0x8003C178u: goto label_8003C178;
    case 0x8003C188u: goto label_8003C188;
    case 0x8003C1B8u: goto label_8003C1B8;
    case 0x8003C1C8u: goto label_8003C1C8;
    case 0x8003C2FCu: goto label_8003C2FC;
    case 0x8003C330u: goto label_8003C330;
    case 0x8003C34Cu: goto label_8003C34C;
    case 0x8003C374u: goto label_8003C374;
    case 0x8003C380u: goto label_8003C380;
    case 0x8003C3A0u: goto label_8003C3A0;
    case 0x8003C3CCu: goto label_8003C3CC;
    case 0x8003C4B0u: goto label_8003C4B0;
    case 0x8003C4F4u: goto label_8003C4F4;
    case 0x8003C510u: goto label_8003C510;
    case 0x8003C564u: goto label_8003C564;
    case 0x8003C56Cu: goto label_8003C56C;
    case 0x8003C574u: goto label_8003C574;
    case 0x8003C590u: goto label_8003C590;
    case 0x8003C598u: goto label_8003C598;
    case 0x8003C5ACu: goto label_8003C5AC;
    case 0x8003C5C4u: goto label_8003C5C4;
    case 0x8003C5DCu: goto label_8003C5DC;
    case 0x8003C5ECu: goto label_8003C5EC;
    case 0x8003C608u: goto label_8003C608;
    case 0x8003C624u: goto label_8003C624;
    case 0x8003C648u: goto label_8003C648;
    case 0x8003C654u: goto label_8003C654;
    case 0x8003C660u: goto label_8003C660;
    case 0x8003C674u: goto label_8003C674;
    case 0x8003C688u: goto label_8003C688;
    case 0x8003C698u: goto label_8003C698;
    case 0x8003C6A8u: goto label_8003C6A8;
    case 0x8003C6C4u: goto label_8003C6C4;
    case 0x8003C6D0u: goto label_8003C6D0;
    case 0x8003C6DCu: goto label_8003C6DC;
    case 0x8003C6E4u: goto label_8003C6E4;
    case 0x8003C6F8u: goto label_8003C6F8;
    case 0x8003C708u: goto label_8003C708;
    case 0x8003C720u: goto label_8003C720;
    case 0x8003C738u: goto label_8003C738;
    case 0x8003C754u: goto label_8003C754;
    case 0x8003C770u: goto label_8003C770;
    case 0x8003C778u: goto label_8003C778;
    case 0x8003C784u: goto label_8003C784;
    case 0x8003C790u: goto label_8003C790;
    case 0x8003C7B0u: goto label_8003C7B0;
    case 0x8003C7CCu: goto label_8003C7CC;
    case 0x8003C7E8u: goto label_8003C7E8;
    case 0x8003C7F8u: goto label_8003C7F8;
    case 0x8003C808u: goto label_8003C808;
    case 0x8003C824u: goto label_8003C824;
    case 0x8003C854u: goto label_8003C854;
    case 0x8003C868u: goto label_8003C868;
    case 0x8003C878u: goto label_8003C878;
    case 0x8003C890u: goto label_8003C890;
    case 0x8003C8A8u: goto label_8003C8A8;
    case 0x8003C8C4u: goto label_8003C8C4;
    case 0x8003C8E0u: goto label_8003C8E0;
    case 0x8003C8E8u: goto label_8003C8E8;
    case 0x8003C8F0u: goto label_8003C8F0;
    case 0x8003C90Cu: goto label_8003C90C;
    case 0x8003C91Cu: goto label_8003C91C;
    case 0x8003C92Cu: goto label_8003C92C;
    case 0x8003C948u: goto label_8003C948;
    case 0x8003C97Cu: goto label_8003C97C;
    case 0x8003C994u: goto label_8003C994;
    case 0x8003C9A8u: goto label_8003C9A8;
    case 0x8003C9B8u: goto label_8003C9B8;
    case 0x8003C9D4u: goto label_8003C9D4;
    case 0x8003C9E0u: goto label_8003C9E0;
    case 0x8003C9F4u: goto label_8003C9F4;
    case 0x8003CA0Cu: goto label_8003CA0C;
    case 0x8003CA24u: goto label_8003CA24;
    case 0x8003CA34u: goto label_8003CA34;
    case 0x8003CA50u: goto label_8003CA50;
    case 0x8003CA6Cu: goto label_8003CA6C;
    case 0x8003CA80u: goto label_8003CA80;
    case 0x8003CA88u: goto label_8003CA88;
    case 0x8003CA90u: goto label_8003CA90;
    case 0x8003CAA8u: goto label_8003CAA8;
    case 0x8003CABCu: goto label_8003CABC;
    case 0x8003CAD0u: goto label_8003CAD0;
    case 0x8003CAE8u: goto label_8003CAE8;
    case 0x8003CAF0u: goto label_8003CAF0;
    case 0x8003CB00u: goto label_8003CB00;
    case 0x8003CB14u: goto label_8003CB14;
    case 0x8003CB28u: goto label_8003CB28;
    case 0x8003CB38u: goto label_8003CB38;
    case 0x8003CB3Cu: goto label_8003CB3C;
    case 0x8003CB44u: goto label_8003CB44;
    case 0x8003CB58u: goto label_8003CB58;
    case 0x8003CB64u: goto label_8003CB64;
    case 0x8003CB70u: goto label_8003CB70;
    case 0x8003CB80u: goto label_8003CB80;
    case 0x8003CBACu: goto label_8003CBAC;
    case 0x8003CBC0u: goto label_8003CBC0;
    case 0x8003CBD0u: goto label_8003CBD0;
    case 0x8003CBECu: goto label_8003CBEC;
    case 0x8003CBF4u: goto label_8003CBF4;
    case 0x8003CC08u: goto label_8003CC08;
    case 0x8003CC20u: goto label_8003CC20;
    case 0x8003CC38u: goto label_8003CC38;
    case 0x8003CC48u: goto label_8003CC48;
    case 0x8003CC64u: goto label_8003CC64;
    case 0x8003CC80u: goto label_8003CC80;
    case 0x8003CC88u: goto label_8003CC88;
    case 0x8003CC9Cu: goto label_8003CC9C;
    case 0x8003CCB4u: goto label_8003CCB4;
    case 0x8003CCCCu: goto label_8003CCCC;
    case 0x8003CCDCu: goto label_8003CCDC;
    case 0x8003CCF8u: goto label_8003CCF8;
    case 0x8003CD14u: goto label_8003CD14;
    case 0x8003CD1Cu: goto label_8003CD1C;
    case 0x8003CD24u: goto label_8003CD24;
    case 0x8003CD2Cu: goto label_8003CD2C;
    case 0x8003CD34u: goto label_8003CD34;
    case 0x8003CD58u: goto label_8003CD58;
    case 0x8003CD68u: goto label_8003CD68;
    case 0x8003CD70u: goto label_8003CD70;
    case 0x8003CD84u: goto label_8003CD84;
    case 0x8003CDCCu: goto label_8003CDCC;
    case 0x8003CE64u: goto label_8003CE64;
    case 0x8003CE9Cu: goto label_8003CE9C;
    case 0x8003CF00u: goto label_8003CF00;
    case 0x8003CF08u: goto label_8003CF08;
    case 0x8003CF10u: goto label_8003CF10;
    case 0x8003CF2Cu: goto label_8003CF2C;
    case 0x8003CF50u: goto label_8003CF50;
    case 0x8003CF90u: goto label_8003CF90;
    case 0x8003CFE8u: goto label_8003CFE8;
    case 0x8003CFFCu: goto label_8003CFFC;
    case 0x8003D008u: goto label_8003D008;
    case 0x8003D014u: goto label_8003D014;
    case 0x8003D01Cu: goto label_8003D01C;
    case 0x8003D030u: goto label_8003D030;
    case 0x8003D048u: goto label_8003D048;
    case 0x8003D058u: goto label_8003D058;
    case 0x8003D074u: goto label_8003D074;
    case 0x8003D090u: goto label_8003D090;
    case 0x8003D0CCu: goto label_8003D0CC;
    case 0x8003D0E0u: goto label_8003D0E0;
    case 0x8003D0F4u: goto label_8003D0F4;
    case 0x8003D104u: goto label_8003D104;
    case 0x8003D114u: goto label_8003D114;
    case 0x8003D130u: goto label_8003D130;
    case 0x8003D13Cu: goto label_8003D13C;
    case 0x8003D148u: goto label_8003D148;
    case 0x8003D150u: goto label_8003D150;
    case 0x8003D164u: goto label_8003D164;
    case 0x8003D174u: goto label_8003D174;
    case 0x8003D18Cu: goto label_8003D18C;
    case 0x8003D1A4u: goto label_8003D1A4;
    case 0x8003D1C0u: goto label_8003D1C0;
    case 0x8003D1DCu: goto label_8003D1DC;
    case 0x8003D1F8u: goto label_8003D1F8;
    case 0x8003D224u: goto label_8003D224;
    case 0x8003D22Cu: goto label_8003D22C;
    case 0x8003D238u: goto label_8003D238;
    case 0x8003D254u: goto label_8003D254;
    case 0x8003D27Cu: goto label_8003D27C;
    case 0x8003D294u: goto label_8003D294;
    case 0x8003D29Cu: goto label_8003D29C;
    case 0x8003D2A4u: goto label_8003D2A4;
    case 0x8003D2B4u: goto label_8003D2B4;
    case 0x8003D2D8u: goto label_8003D2D8;
    case 0x8003D2FCu: goto label_8003D2FC;
    case 0x8003D320u: goto label_8003D320;
    case 0x8003D350u: goto label_8003D350;
    case 0x8003D36Cu: goto label_8003D36C;
    case 0x8003D37Cu: goto label_8003D37C;
    case 0x8003D3A4u: goto label_8003D3A4;
    case 0x8003D3C4u: goto label_8003D3C4;
    case 0x8003D3DCu: goto label_8003D3DC;
    case 0x8003D3F8u: goto label_8003D3F8;
    case 0x8003D414u: goto label_8003D414;
    case 0x8003D420u: goto label_8003D420;
    case 0x8003D42Cu: goto label_8003D42C;
    case 0x8003D44Cu: goto label_8003D44C;
    case 0x8003D468u: goto label_8003D468;
    case 0x8003D484u: goto label_8003D484;
    case 0x8003D494u: goto label_8003D494;
    case 0x8003D4A4u: goto label_8003D4A4;
    case 0x8003D4C0u: goto label_8003D4C0;
    case 0x8003D4F0u: goto label_8003D4F0;
    case 0x8003D504u: goto label_8003D504;
    case 0x8003D514u: goto label_8003D514;
    case 0x8003D52Cu: goto label_8003D52C;
    case 0x8003D544u: goto label_8003D544;
    case 0x8003D560u: goto label_8003D560;
    case 0x8003D57Cu: goto label_8003D57C;
    case 0x8003D58Cu: goto label_8003D58C;
    case 0x8003D594u: goto label_8003D594;
    case 0x8003D5B0u: goto label_8003D5B0;
    case 0x8003D5C0u: goto label_8003D5C0;
    case 0x8003D5D0u: goto label_8003D5D0;
    case 0x8003D5ECu: goto label_8003D5EC;
    case 0x8003D620u: goto label_8003D620;
    case 0x8003D634u: goto label_8003D634;
    case 0x8003D644u: goto label_8003D644;
    case 0x8003D660u: goto label_8003D660;
    case 0x8003D690u: goto label_8003D690;
    case 0x8003D6A8u: goto label_8003D6A8;
    case 0x8003D6BCu: goto label_8003D6BC;
    case 0x8003D6CCu: goto label_8003D6CC;
    case 0x8003D6E8u: goto label_8003D6E8;
    case 0x8003D6F4u: goto label_8003D6F4;
    case 0x8003D714u: goto label_8003D714;
    case 0x8003D72Cu: goto label_8003D72C;
    case 0x8003D744u: goto label_8003D744;
    case 0x8003D75Cu: goto label_8003D75C;
    case 0x8003D774u: goto label_8003D774;
    case 0x8003D784u: goto label_8003D784;
    case 0x8003D7A0u: goto label_8003D7A0;
    case 0x8003D7BCu: goto label_8003D7BC;
    case 0x8003D7D0u: goto label_8003D7D0;
    case 0x8003D7D8u: goto label_8003D7D8;
    case 0x8003D7E4u: goto label_8003D7E4;
    case 0x8003D7ECu: goto label_8003D7EC;
    case 0x8003D7F4u: goto label_8003D7F4;
    case 0x8003D7FCu: goto label_8003D7FC;
    case 0x8003D834u: goto label_8003D834;
    case 0x8003D83Cu: goto label_8003D83C;
    case 0x8003D84Cu: goto label_8003D84C;
    case 0x8003D854u: goto label_8003D854;
    case 0x8003D868u: goto label_8003D868;
    case 0x8003D87Cu: goto label_8003D87C;
    case 0x8003D8B4u: goto label_8003D8B4;
    case 0x8003D8C8u: goto label_8003D8C8;
    case 0x8003D8DCu: goto label_8003D8DC;
    case 0x8003D8F4u: goto label_8003D8F4;
    case 0x8003D8FCu: goto label_8003D8FC;
    case 0x8003D90Cu: goto label_8003D90C;
    case 0x8003D920u: goto label_8003D920;
    case 0x8003D934u: goto label_8003D934;
    case 0x8003D944u: goto label_8003D944;
    case 0x8003D948u: goto label_8003D948;
    case 0x8003D950u: goto label_8003D950;
    case 0x8003D964u: goto label_8003D964;
    case 0x8003D970u: goto label_8003D970;
    case 0x8003D97Cu: goto label_8003D97C;
    case 0x8003D98Cu: goto label_8003D98C;
    case 0x8003D9B8u: goto label_8003D9B8;
    case 0x8003D9CCu: goto label_8003D9CC;
    case 0x8003D9DCu: goto label_8003D9DC;
    case 0x8003D9F8u: goto label_8003D9F8;
    case 0x8003DA00u: goto label_8003DA00;
    case 0x8003DA14u: goto label_8003DA14;
    case 0x8003DA2Cu: goto label_8003DA2C;
    case 0x8003DA44u: goto label_8003DA44;
    case 0x8003DA54u: goto label_8003DA54;
    case 0x8003DA70u: goto label_8003DA70;
    case 0x8003DA8Cu: goto label_8003DA8C;
    case 0x8003DA94u: goto label_8003DA94;
    case 0x8003DA9Cu: goto label_8003DA9C;
    case 0x8003DAA4u: goto label_8003DAA4;
    case 0x8003DAACu: goto label_8003DAAC;
    case 0x8003DAD0u: goto label_8003DAD0;
    case 0x8003DAE0u: goto label_8003DAE0;
    case 0x8003DAE8u: goto label_8003DAE8;
    case 0x8003DAFCu: goto label_8003DAFC;
    case 0x8003DB40u: goto label_8003DB40;
    case 0x8003DB54u: goto label_8003DB54;
    case 0x8003DB64u: goto label_8003DB64;
    case 0x8003DB78u: goto label_8003DB78;
    case 0x8003DB88u: goto label_8003DB88;
    case 0x8003DBA0u: goto label_8003DBA0;
    case 0x8003DBC0u: goto label_8003DBC0;
    case 0x8003DBD0u: goto label_8003DBD0;
    case 0x8003DBE0u: goto label_8003DBE0;
    case 0x8003DBE4u: goto label_8003DBE4;
    case 0x8003DBF0u: goto label_8003DBF0;
    case 0x8003DBFCu: goto label_8003DBFC;
    case 0x8003DC08u: goto label_8003DC08;
    case 0x8003DC28u: goto label_8003DC28;
    case 0x8003DCC8u: goto label_8003DCC8;
    case 0x8003DCD4u: goto label_8003DCD4;
    case 0x8003DCECu: goto label_8003DCEC;
    case 0x8003DDC4u: goto label_8003DDC4;
    case 0x8003DDF8u: goto label_8003DDF8;
    case 0x8003DE80u: goto label_8003DE80;
    case 0x8003DEA0u: goto label_8003DEA0;
    case 0x8003DEC0u: goto label_8003DEC0;
    case 0x8003DEC8u: goto label_8003DEC8;
    case 0x8003DEECu: goto label_8003DEEC;
    case 0x8003DF0Cu: goto label_8003DF0C;
    case 0x8003DF14u: goto label_8003DF14;
    case 0x8003DF20u: goto label_8003DF20;
    case 0x8003DF34u: goto label_8003DF34;
    case 0x8003DF68u: goto label_8003DF68;
    case 0x8003DF88u: goto label_8003DF88;
    case 0x8003DF9Cu: goto label_8003DF9C;
    case 0x8003DFB0u: goto label_8003DFB0;
    case 0x8003DFCCu: goto label_8003DFCC;
    case 0x8003DFF0u: goto label_8003DFF0;
    case 0x8003E010u: goto label_8003E010;
    case 0x8003E028u: goto label_8003E028;
    case 0x8003E044u: goto label_8003E044;
    case 0x8003E07Cu: goto label_8003E07C;
    case 0x8003E094u: goto label_8003E094;
    case 0x8003E0B4u: goto label_8003E0B4;
    case 0x8003E0F8u: goto label_8003E0F8;
    case 0x8003E148u: goto label_8003E148;
    case 0x8003E158u: goto label_8003E158;
    case 0x8003E16Cu: goto label_8003E16C;
    case 0x8003E180u: goto label_8003E180;
    case 0x8003E19Cu: goto label_8003E19C;
    case 0x8003E1E4u: goto label_8003E1E4;
    case 0x8003E208u: goto label_8003E208;
    case 0x8003E21Cu: goto label_8003E21C;
    case 0x8003E230u: goto label_8003E230;
    case 0x8003E24Cu: goto label_8003E24C;
    case 0x8003E264u: goto label_8003E264;
    case 0x8003E32Cu: goto label_8003E32C;
    case 0x8003E338u: goto label_8003E338;
    case 0x8003E348u: goto label_8003E348;
    case 0x8003E354u: goto label_8003E354;
    case 0x8003E36Cu: goto label_8003E36C;
    case 0x8003E390u: goto label_8003E390;
    case 0x8003E3BCu: goto label_8003E3BC;
    case 0x8003E3ECu: goto label_8003E3EC;
    case 0x8003E3F4u: goto label_8003E3F4;
    case 0x8003E410u: goto label_8003E410;
    case 0x8003E428u: goto label_8003E428;
    case 0x8003E4A4u: goto label_8003E4A4;
    case 0x8003E510u: goto label_8003E510;
    case 0x8003E538u: goto label_8003E538;
    case 0x8003E55Cu: goto label_8003E55C;
    case 0x8003E568u: goto label_8003E568;
    case 0x8003E578u: goto label_8003E578;
    case 0x8003E584u: goto label_8003E584;
    case 0x8003E5C8u: goto label_8003E5C8;
    case 0x8003E5E4u: goto label_8003E5E4;
    case 0x8003E5FCu: goto label_8003E5FC;
    case 0x8003E618u: goto label_8003E618;
    default: return;
    }
}

