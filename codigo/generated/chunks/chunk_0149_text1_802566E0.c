// DolRecomp output
#include "../generated.h"

static void loop_802570C0(CPUState* ctx) {
label_802570C0:
    ctx->downcount -= 5;
    ctx->pc = 0x802570C0u;
    // 802570C0: lwzu     r3, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[3] = mem_read32(ctx, ea);
        ctx->gpr[4] = ea;
    }

    ctx->pc = 0x802570C4u;
    // 802570C4: lwz     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x802570C8u;
    // 802570C8: stwu     r3, 8(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
        ctx->gpr[5] = ea;
    }

    ctx->pc = 0x802570CCu;
    // 802570CC: stw     r0, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 802570D0: bc    16, 0, 0x802570C0
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802570C0u;
                return;
            }
            goto label_802570C0;
        }
    }

    ctx->pc = 0x802570D4u;
}

static void loop_8025933C(CPUState* ctx) {
label_8025933C:
    ctx->downcount -= 9;
    ctx->pc = 0x8025933Cu;
    // 8025933C: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

    ctx->pc = 0x80259340u;
    // 80259340: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

    ctx->pc = 0x80259344u;
    // 80259344: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

    ctx->pc = 0x80259348u;
    // 80259348: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

    ctx->pc = 0x8025934Cu;
    // 8025934C: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

    ctx->pc = 0x80259350u;
    // 80259350: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

    ctx->pc = 0x80259354u;
    // 80259354: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

    ctx->pc = 0x80259358u;
    // 80259358: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

    // 8025935C: bc    16, 0, 0x8025933C
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8025933Cu;
                return;
            }
            goto label_8025933C;
        }
    }

    ctx->pc = 0x80259360u;
}

static void loop_8025936C(CPUState* ctx) {
label_8025936C:
    ctx->downcount -= 2;
    ctx->pc = 0x8025936Cu;
    // 8025936C: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

    // 80259370: bc    16, 0, 0x8025936C
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8025936Cu;
                return;
            }
            goto label_8025936C;
        }
    }

    ctx->pc = 0x80259374u;
}

static void loop_802599C0(CPUState* ctx) {
label_802599C0:
    ctx->downcount -= 1;
    // 802599C0: rlwinm r4, r4, 31, 1, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 31u) & 0x7FFFFFFFu;
    }

    // 802599C4: rlwinm. r0, r4, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

    // 802599C8: bc    12, 2, 0x802599C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802599C0u;
                return;
            }
            goto label_802599C0;
        }
    }

    ctx->pc = 0x802599CCu;
}

void func_802566E0(CPUState* ctx) {
    switch (ctx->pc) {
    case 0x802566E0u: goto label_802566E0;
    case 0x802566E4u: goto label_802566E4;
    case 0x802566E8u: goto label_802566E8;
    case 0x802566ECu: goto label_802566EC;
    case 0x802566F0u: goto label_802566F0;
    case 0x802566F4u: goto label_802566F4;
    case 0x802566F8u: goto label_802566F8;
    case 0x802566FCu: goto label_802566FC;
    case 0x80256700u: goto label_80256700;
    case 0x80256704u: goto label_80256704;
    case 0x80256708u: goto label_80256708;
    case 0x8025670Cu: goto label_8025670C;
    case 0x80256710u: goto label_80256710;
    case 0x80256714u: goto label_80256714;
    case 0x80256718u: goto label_80256718;
    case 0x8025671Cu: goto label_8025671C;
    case 0x80256720u: goto label_80256720;
    case 0x80256724u: goto label_80256724;
    case 0x80256728u: goto label_80256728;
    case 0x8025672Cu: goto label_8025672C;
    case 0x80256730u: goto label_80256730;
    case 0x80256734u: goto label_80256734;
    case 0x80256738u: goto label_80256738;
    case 0x8025673Cu: goto label_8025673C;
    case 0x80256740u: goto label_80256740;
    case 0x80256744u: goto label_80256744;
    case 0x80256748u: goto label_80256748;
    case 0x8025674Cu: goto label_8025674C;
    case 0x80256750u: goto label_80256750;
    case 0x80256754u: goto label_80256754;
    case 0x80256758u: goto label_80256758;
    case 0x8025675Cu: goto label_8025675C;
    case 0x80256760u: goto label_80256760;
    case 0x80256764u: goto label_80256764;
    case 0x80256768u: goto label_80256768;
    case 0x8025676Cu: goto label_8025676C;
    case 0x80256770u: goto label_80256770;
    case 0x80256774u: goto label_80256774;
    case 0x80256778u: goto label_80256778;
    case 0x8025677Cu: goto label_8025677C;
    case 0x80256780u: goto label_80256780;
    case 0x80256784u: goto label_80256784;
    case 0x80256788u: goto label_80256788;
    case 0x8025678Cu: goto label_8025678C;
    case 0x80256790u: goto label_80256790;
    case 0x80256794u: goto label_80256794;
    case 0x80256798u: goto label_80256798;
    case 0x8025679Cu: goto label_8025679C;
    case 0x802567A0u: goto label_802567A0;
    case 0x802567A4u: goto label_802567A4;
    case 0x802567A8u: goto label_802567A8;
    case 0x802567ACu: goto label_802567AC;
    case 0x802567B0u: goto label_802567B0;
    case 0x802567B4u: goto label_802567B4;
    case 0x802567B8u: goto label_802567B8;
    case 0x802567BCu: goto label_802567BC;
    case 0x802567C0u: goto label_802567C0;
    case 0x802567C4u: goto label_802567C4;
    case 0x802567C8u: goto label_802567C8;
    case 0x802567CCu: goto label_802567CC;
    case 0x802567D0u: goto label_802567D0;
    case 0x802567D4u: goto label_802567D4;
    case 0x802567D8u: goto label_802567D8;
    case 0x802567DCu: goto label_802567DC;
    case 0x802567E0u: goto label_802567E0;
    case 0x802567E4u: goto label_802567E4;
    case 0x802567E8u: goto label_802567E8;
    case 0x802567ECu: goto label_802567EC;
    case 0x802567F0u: goto label_802567F0;
    case 0x802567F4u: goto label_802567F4;
    case 0x802567F8u: goto label_802567F8;
    case 0x802567FCu: goto label_802567FC;
    case 0x80256800u: goto label_80256800;
    case 0x80256804u: goto label_80256804;
    case 0x80256808u: goto label_80256808;
    case 0x8025680Cu: goto label_8025680C;
    case 0x80256810u: goto label_80256810;
    case 0x80256814u: goto label_80256814;
    case 0x80256818u: goto label_80256818;
    case 0x8025681Cu: goto label_8025681C;
    case 0x80256820u: goto label_80256820;
    case 0x80256824u: goto label_80256824;
    case 0x80256828u: goto label_80256828;
    case 0x8025682Cu: goto label_8025682C;
    case 0x80256830u: goto label_80256830;
    case 0x80256834u: goto label_80256834;
    case 0x80256838u: goto label_80256838;
    case 0x8025683Cu: goto label_8025683C;
    case 0x80256840u: goto label_80256840;
    case 0x80256844u: goto label_80256844;
    case 0x80256848u: goto label_80256848;
    case 0x8025684Cu: goto label_8025684C;
    case 0x80256850u: goto label_80256850;
    case 0x80256854u: goto label_80256854;
    case 0x80256858u: goto label_80256858;
    case 0x8025685Cu: goto label_8025685C;
    case 0x80256860u: goto label_80256860;
    case 0x80256864u: goto label_80256864;
    case 0x80256868u: goto label_80256868;
    case 0x8025686Cu: goto label_8025686C;
    case 0x80256870u: goto label_80256870;
    case 0x80256874u: goto label_80256874;
    case 0x80256878u: goto label_80256878;
    case 0x8025687Cu: goto label_8025687C;
    case 0x80256880u: goto label_80256880;
    case 0x80256884u: goto label_80256884;
    case 0x80256888u: goto label_80256888;
    case 0x8025688Cu: goto label_8025688C;
    case 0x80256890u: goto label_80256890;
    case 0x80256894u: goto label_80256894;
    case 0x80256898u: goto label_80256898;
    case 0x8025689Cu: goto label_8025689C;
    case 0x802568A0u: goto label_802568A0;
    case 0x802568A4u: goto label_802568A4;
    case 0x802568A8u: goto label_802568A8;
    case 0x802568ACu: goto label_802568AC;
    case 0x802568B0u: goto label_802568B0;
    case 0x802568B4u: goto label_802568B4;
    case 0x802568B8u: goto label_802568B8;
    case 0x802568BCu: goto label_802568BC;
    case 0x802568C0u: goto label_802568C0;
    case 0x802568C4u: goto label_802568C4;
    case 0x802568C8u: goto label_802568C8;
    case 0x802568CCu: goto label_802568CC;
    case 0x802568D0u: goto label_802568D0;
    case 0x802568D4u: goto label_802568D4;
    case 0x802568D8u: goto label_802568D8;
    case 0x802568DCu: goto label_802568DC;
    case 0x802568E0u: goto label_802568E0;
    case 0x802568E4u: goto label_802568E4;
    case 0x802568E8u: goto label_802568E8;
    case 0x802568ECu: goto label_802568EC;
    case 0x802568F0u: goto label_802568F0;
    case 0x802568F4u: goto label_802568F4;
    case 0x802568F8u: goto label_802568F8;
    case 0x802568FCu: goto label_802568FC;
    case 0x80256900u: goto label_80256900;
    case 0x80256904u: goto label_80256904;
    case 0x80256908u: goto label_80256908;
    case 0x8025690Cu: goto label_8025690C;
    case 0x80256910u: goto label_80256910;
    case 0x80256914u: goto label_80256914;
    case 0x80256918u: goto label_80256918;
    case 0x8025691Cu: goto label_8025691C;
    case 0x80256920u: goto label_80256920;
    case 0x80256924u: goto label_80256924;
    case 0x80256928u: goto label_80256928;
    case 0x8025692Cu: goto label_8025692C;
    case 0x80256930u: goto label_80256930;
    case 0x80256934u: goto label_80256934;
    case 0x80256938u: goto label_80256938;
    case 0x8025693Cu: goto label_8025693C;
    case 0x80256940u: goto label_80256940;
    case 0x80256944u: goto label_80256944;
    case 0x80256948u: goto label_80256948;
    case 0x8025694Cu: goto label_8025694C;
    case 0x80256950u: goto label_80256950;
    case 0x80256954u: goto label_80256954;
    case 0x80256958u: goto label_80256958;
    case 0x8025695Cu: goto label_8025695C;
    case 0x80256960u: goto label_80256960;
    case 0x80256964u: goto label_80256964;
    case 0x80256968u: goto label_80256968;
    case 0x8025696Cu: goto label_8025696C;
    case 0x80256970u: goto label_80256970;
    case 0x80256974u: goto label_80256974;
    case 0x80256978u: goto label_80256978;
    case 0x8025697Cu: goto label_8025697C;
    case 0x80256980u: goto label_80256980;
    case 0x80256984u: goto label_80256984;
    case 0x80256988u: goto label_80256988;
    case 0x8025698Cu: goto label_8025698C;
    case 0x80256990u: goto label_80256990;
    case 0x80256994u: goto label_80256994;
    case 0x80256998u: goto label_80256998;
    case 0x8025699Cu: goto label_8025699C;
    case 0x802569A0u: goto label_802569A0;
    case 0x802569A4u: goto label_802569A4;
    case 0x802569A8u: goto label_802569A8;
    case 0x802569ACu: goto label_802569AC;
    case 0x802569B0u: goto label_802569B0;
    case 0x802569B4u: goto label_802569B4;
    case 0x802569B8u: goto label_802569B8;
    case 0x802569BCu: goto label_802569BC;
    case 0x802569C0u: goto label_802569C0;
    case 0x802569C4u: goto label_802569C4;
    case 0x802569C8u: goto label_802569C8;
    case 0x802569CCu: goto label_802569CC;
    case 0x802569D0u: goto label_802569D0;
    case 0x802569D4u: goto label_802569D4;
    case 0x802569D8u: goto label_802569D8;
    case 0x802569DCu: goto label_802569DC;
    case 0x802569E0u: goto label_802569E0;
    case 0x802569E4u: goto label_802569E4;
    case 0x802569E8u: goto label_802569E8;
    case 0x802569ECu: goto label_802569EC;
    case 0x802569F0u: goto label_802569F0;
    case 0x802569F4u: goto label_802569F4;
    case 0x802569F8u: goto label_802569F8;
    case 0x802569FCu: goto label_802569FC;
    case 0x80256A00u: goto label_80256A00;
    case 0x80256A04u: goto label_80256A04;
    case 0x80256A08u: goto label_80256A08;
    case 0x80256A0Cu: goto label_80256A0C;
    case 0x80256A10u: goto label_80256A10;
    case 0x80256A14u: goto label_80256A14;
    case 0x80256A18u: goto label_80256A18;
    case 0x80256A1Cu: goto label_80256A1C;
    case 0x80256A20u: goto label_80256A20;
    case 0x80256A24u: goto label_80256A24;
    case 0x80256A28u: goto label_80256A28;
    case 0x80256A2Cu: goto label_80256A2C;
    case 0x80256A30u: goto label_80256A30;
    case 0x80256A34u: goto label_80256A34;
    case 0x80256A38u: goto label_80256A38;
    case 0x80256A3Cu: goto label_80256A3C;
    case 0x80256A40u: goto label_80256A40;
    case 0x80256A44u: goto label_80256A44;
    case 0x80256A48u: goto label_80256A48;
    case 0x80256A4Cu: goto label_80256A4C;
    case 0x80256A50u: goto label_80256A50;
    case 0x80256A54u: goto label_80256A54;
    case 0x80256A58u: goto label_80256A58;
    case 0x80256A5Cu: goto label_80256A5C;
    case 0x80256A60u: goto label_80256A60;
    case 0x80256A64u: goto label_80256A64;
    case 0x80256A68u: goto label_80256A68;
    case 0x80256A6Cu: goto label_80256A6C;
    case 0x80256A70u: goto label_80256A70;
    case 0x80256A74u: goto label_80256A74;
    case 0x80256A78u: goto label_80256A78;
    case 0x80256A7Cu: goto label_80256A7C;
    case 0x80256A80u: goto label_80256A80;
    case 0x80256A84u: goto label_80256A84;
    case 0x80256A88u: goto label_80256A88;
    case 0x80256A8Cu: goto label_80256A8C;
    case 0x80256A90u: goto label_80256A90;
    case 0x80256A94u: goto label_80256A94;
    case 0x80256A98u: goto label_80256A98;
    case 0x80256A9Cu: goto label_80256A9C;
    case 0x80256AA0u: goto label_80256AA0;
    case 0x80256AA4u: goto label_80256AA4;
    case 0x80256AA8u: goto label_80256AA8;
    case 0x80256AACu: goto label_80256AAC;
    case 0x80256AB0u: goto label_80256AB0;
    case 0x80256AB4u: goto label_80256AB4;
    case 0x80256AB8u: goto label_80256AB8;
    case 0x80256ABCu: goto label_80256ABC;
    case 0x80256AC0u: goto label_80256AC0;
    case 0x80256AC4u: goto label_80256AC4;
    case 0x80256AC8u: goto label_80256AC8;
    case 0x80256ACCu: goto label_80256ACC;
    case 0x80256AD0u: goto label_80256AD0;
    case 0x80256AD4u: goto label_80256AD4;
    case 0x80256AD8u: goto label_80256AD8;
    case 0x80256ADCu: goto label_80256ADC;
    case 0x80256AE0u: goto label_80256AE0;
    case 0x80256AE4u: goto label_80256AE4;
    case 0x80256AE8u: goto label_80256AE8;
    case 0x80256AECu: goto label_80256AEC;
    case 0x80256AF0u: goto label_80256AF0;
    case 0x80256AF4u: goto label_80256AF4;
    case 0x80256AF8u: goto label_80256AF8;
    case 0x80256AFCu: goto label_80256AFC;
    case 0x80256B00u: goto label_80256B00;
    case 0x80256B04u: goto label_80256B04;
    case 0x80256B08u: goto label_80256B08;
    case 0x80256B0Cu: goto label_80256B0C;
    case 0x80256B10u: goto label_80256B10;
    case 0x80256B14u: goto label_80256B14;
    case 0x80256B18u: goto label_80256B18;
    case 0x80256B1Cu: goto label_80256B1C;
    case 0x80256B20u: goto label_80256B20;
    case 0x80256B24u: goto label_80256B24;
    case 0x80256B28u: goto label_80256B28;
    case 0x80256B2Cu: goto label_80256B2C;
    case 0x80256B30u: goto label_80256B30;
    case 0x80256B34u: goto label_80256B34;
    case 0x80256B38u: goto label_80256B38;
    case 0x80256B3Cu: goto label_80256B3C;
    case 0x80256B40u: goto label_80256B40;
    case 0x80256B44u: goto label_80256B44;
    case 0x80256B48u: goto label_80256B48;
    case 0x80256B4Cu: goto label_80256B4C;
    case 0x80256B50u: goto label_80256B50;
    case 0x80256B54u: goto label_80256B54;
    case 0x80256B58u: goto label_80256B58;
    case 0x80256B5Cu: goto label_80256B5C;
    case 0x80256B60u: goto label_80256B60;
    case 0x80256B64u: goto label_80256B64;
    case 0x80256B68u: goto label_80256B68;
    case 0x80256B6Cu: goto label_80256B6C;
    case 0x80256B70u: goto label_80256B70;
    case 0x80256B74u: goto label_80256B74;
    case 0x80256B78u: goto label_80256B78;
    case 0x80256B7Cu: goto label_80256B7C;
    case 0x80256B80u: goto label_80256B80;
    case 0x80256B84u: goto label_80256B84;
    case 0x80256B88u: goto label_80256B88;
    case 0x80256B8Cu: goto label_80256B8C;
    case 0x80256B90u: goto label_80256B90;
    case 0x80256B94u: goto label_80256B94;
    case 0x80256B98u: goto label_80256B98;
    case 0x80256B9Cu: goto label_80256B9C;
    case 0x80256BA0u: goto label_80256BA0;
    case 0x80256BA4u: goto label_80256BA4;
    case 0x80256BA8u: goto label_80256BA8;
    case 0x80256BACu: goto label_80256BAC;
    case 0x80256BB0u: goto label_80256BB0;
    case 0x80256BB4u: goto label_80256BB4;
    case 0x80256BB8u: goto label_80256BB8;
    case 0x80256BBCu: goto label_80256BBC;
    case 0x80256BC0u: goto label_80256BC0;
    case 0x80256BC4u: goto label_80256BC4;
    case 0x80256BC8u: goto label_80256BC8;
    case 0x80256BCCu: goto label_80256BCC;
    case 0x80256BD0u: goto label_80256BD0;
    case 0x80256BD4u: goto label_80256BD4;
    case 0x80256BD8u: goto label_80256BD8;
    case 0x80256BDCu: goto label_80256BDC;
    case 0x80256BE0u: goto label_80256BE0;
    case 0x80256BE4u: goto label_80256BE4;
    case 0x80256BE8u: goto label_80256BE8;
    case 0x80256BECu: goto label_80256BEC;
    case 0x80256BF0u: goto label_80256BF0;
    case 0x80256BF4u: goto label_80256BF4;
    case 0x80256BF8u: goto label_80256BF8;
    case 0x80256BFCu: goto label_80256BFC;
    case 0x80256C00u: goto label_80256C00;
    case 0x80256C04u: goto label_80256C04;
    case 0x80256C08u: goto label_80256C08;
    case 0x80256C0Cu: goto label_80256C0C;
    case 0x80256C10u: goto label_80256C10;
    case 0x80256C14u: goto label_80256C14;
    case 0x80256C18u: goto label_80256C18;
    case 0x80256C1Cu: goto label_80256C1C;
    case 0x80256C20u: goto label_80256C20;
    case 0x80256C24u: goto label_80256C24;
    case 0x80256C28u: goto label_80256C28;
    case 0x80256C2Cu: goto label_80256C2C;
    case 0x80256C30u: goto label_80256C30;
    case 0x80256C34u: goto label_80256C34;
    case 0x80256C38u: goto label_80256C38;
    case 0x80256C3Cu: goto label_80256C3C;
    case 0x80256C40u: goto label_80256C40;
    case 0x80256C44u: goto label_80256C44;
    case 0x80256C48u: goto label_80256C48;
    case 0x80256C4Cu: goto label_80256C4C;
    case 0x80256C50u: goto label_80256C50;
    case 0x80256C54u: goto label_80256C54;
    case 0x80256C58u: goto label_80256C58;
    case 0x80256C5Cu: goto label_80256C5C;
    case 0x80256C60u: goto label_80256C60;
    case 0x80256C64u: goto label_80256C64;
    case 0x80256C68u: goto label_80256C68;
    case 0x80256C6Cu: goto label_80256C6C;
    case 0x80256C70u: goto label_80256C70;
    case 0x80256C74u: goto label_80256C74;
    case 0x80256C78u: goto label_80256C78;
    case 0x80256C7Cu: goto label_80256C7C;
    case 0x80256C80u: goto label_80256C80;
    case 0x80256C84u: goto label_80256C84;
    case 0x80256C88u: goto label_80256C88;
    case 0x80256C8Cu: goto label_80256C8C;
    case 0x80256C90u: goto label_80256C90;
    case 0x80256C94u: goto label_80256C94;
    case 0x80256C98u: goto label_80256C98;
    case 0x80256C9Cu: goto label_80256C9C;
    case 0x80256CA0u: goto label_80256CA0;
    case 0x80256CA4u: goto label_80256CA4;
    case 0x80256CA8u: goto label_80256CA8;
    case 0x80256CACu: goto label_80256CAC;
    case 0x80256CB0u: goto label_80256CB0;
    case 0x80256CB4u: goto label_80256CB4;
    case 0x80256CB8u: goto label_80256CB8;
    case 0x80256CBCu: goto label_80256CBC;
    case 0x80256CC0u: goto label_80256CC0;
    case 0x80256CC4u: goto label_80256CC4;
    case 0x80256CC8u: goto label_80256CC8;
    case 0x80256CCCu: goto label_80256CCC;
    case 0x80256CD0u: goto label_80256CD0;
    case 0x80256CD4u: goto label_80256CD4;
    case 0x80256CD8u: goto label_80256CD8;
    case 0x80256CDCu: goto label_80256CDC;
    case 0x80256CE0u: goto label_80256CE0;
    case 0x80256CE4u: goto label_80256CE4;
    case 0x80256CE8u: goto label_80256CE8;
    case 0x80256CECu: goto label_80256CEC;
    case 0x80256CF0u: goto label_80256CF0;
    case 0x80256CF4u: goto label_80256CF4;
    case 0x80256CF8u: goto label_80256CF8;
    case 0x80256CFCu: goto label_80256CFC;
    case 0x80256D00u: goto label_80256D00;
    case 0x80256D04u: goto label_80256D04;
    case 0x80256D08u: goto label_80256D08;
    case 0x80256D0Cu: goto label_80256D0C;
    case 0x80256D10u: goto label_80256D10;
    case 0x80256D14u: goto label_80256D14;
    case 0x80256D18u: goto label_80256D18;
    case 0x80256D1Cu: goto label_80256D1C;
    case 0x80256D20u: goto label_80256D20;
    case 0x80256D24u: goto label_80256D24;
    case 0x80256D28u: goto label_80256D28;
    case 0x80256D2Cu: goto label_80256D2C;
    case 0x80256D30u: goto label_80256D30;
    case 0x80256D34u: goto label_80256D34;
    case 0x80256D38u: goto label_80256D38;
    case 0x80256D3Cu: goto label_80256D3C;
    case 0x80256D40u: goto label_80256D40;
    case 0x80256D44u: goto label_80256D44;
    case 0x80256D48u: goto label_80256D48;
    case 0x80256D4Cu: goto label_80256D4C;
    case 0x80256D50u: goto label_80256D50;
    case 0x80256D54u: goto label_80256D54;
    case 0x80256D58u: goto label_80256D58;
    case 0x80256D5Cu: goto label_80256D5C;
    case 0x80256D60u: goto label_80256D60;
    case 0x80256D64u: goto label_80256D64;
    case 0x80256D68u: goto label_80256D68;
    case 0x80256D6Cu: goto label_80256D6C;
    case 0x80256D70u: goto label_80256D70;
    case 0x80256D74u: goto label_80256D74;
    case 0x80256D78u: goto label_80256D78;
    case 0x80256D7Cu: goto label_80256D7C;
    case 0x80256D80u: goto label_80256D80;
    case 0x80256D84u: goto label_80256D84;
    case 0x80256D88u: goto label_80256D88;
    case 0x80256D8Cu: goto label_80256D8C;
    case 0x80256D90u: goto label_80256D90;
    case 0x80256D94u: goto label_80256D94;
    case 0x80256D98u: goto label_80256D98;
    case 0x80256D9Cu: goto label_80256D9C;
    case 0x80256DA0u: goto label_80256DA0;
    case 0x80256DA4u: goto label_80256DA4;
    case 0x80256DA8u: goto label_80256DA8;
    case 0x80256DACu: goto label_80256DAC;
    case 0x80256DB0u: goto label_80256DB0;
    case 0x80256DB4u: goto label_80256DB4;
    case 0x80256DB8u: goto label_80256DB8;
    case 0x80256DBCu: goto label_80256DBC;
    case 0x80256DC0u: goto label_80256DC0;
    case 0x80256DC4u: goto label_80256DC4;
    case 0x80256DC8u: goto label_80256DC8;
    case 0x80256DCCu: goto label_80256DCC;
    case 0x80256DD0u: goto label_80256DD0;
    case 0x80256DD4u: goto label_80256DD4;
    case 0x80256DD8u: goto label_80256DD8;
    case 0x80256DDCu: goto label_80256DDC;
    case 0x80256DE0u: goto label_80256DE0;
    case 0x80256DE4u: goto label_80256DE4;
    case 0x80256DE8u: goto label_80256DE8;
    case 0x80256DECu: goto label_80256DEC;
    case 0x80256DF0u: goto label_80256DF0;
    case 0x80256DF4u: goto label_80256DF4;
    case 0x80256DF8u: goto label_80256DF8;
    case 0x80256DFCu: goto label_80256DFC;
    case 0x80256E00u: goto label_80256E00;
    case 0x80256E04u: goto label_80256E04;
    case 0x80256E08u: goto label_80256E08;
    case 0x80256E0Cu: goto label_80256E0C;
    case 0x80256E10u: goto label_80256E10;
    case 0x80256E14u: goto label_80256E14;
    case 0x80256E18u: goto label_80256E18;
    case 0x80256E1Cu: goto label_80256E1C;
    case 0x80256E20u: goto label_80256E20;
    case 0x80256E24u: goto label_80256E24;
    case 0x80256E28u: goto label_80256E28;
    case 0x80256E2Cu: goto label_80256E2C;
    case 0x80256E30u: goto label_80256E30;
    case 0x80256E34u: goto label_80256E34;
    case 0x80256E38u: goto label_80256E38;
    case 0x80256E3Cu: goto label_80256E3C;
    case 0x80256E40u: goto label_80256E40;
    case 0x80256E44u: goto label_80256E44;
    case 0x80256E48u: goto label_80256E48;
    case 0x80256E4Cu: goto label_80256E4C;
    case 0x80256E50u: goto label_80256E50;
    case 0x80256E54u: goto label_80256E54;
    case 0x80256E58u: goto label_80256E58;
    case 0x80256E5Cu: goto label_80256E5C;
    case 0x80256E60u: goto label_80256E60;
    case 0x80256E64u: goto label_80256E64;
    case 0x80256E68u: goto label_80256E68;
    case 0x80256E6Cu: goto label_80256E6C;
    case 0x80256E70u: goto label_80256E70;
    case 0x80256E74u: goto label_80256E74;
    case 0x80256E78u: goto label_80256E78;
    case 0x80256E7Cu: goto label_80256E7C;
    case 0x80256E80u: goto label_80256E80;
    case 0x80256E84u: goto label_80256E84;
    case 0x80256E88u: goto label_80256E88;
    case 0x80256E8Cu: goto label_80256E8C;
    case 0x80256E90u: goto label_80256E90;
    case 0x80256E94u: goto label_80256E94;
    case 0x80256E98u: goto label_80256E98;
    case 0x80256E9Cu: goto label_80256E9C;
    case 0x80256EA0u: goto label_80256EA0;
    case 0x80256EA4u: goto label_80256EA4;
    case 0x80256EA8u: goto label_80256EA8;
    case 0x80256EACu: goto label_80256EAC;
    case 0x80256EB0u: goto label_80256EB0;
    case 0x80256EB4u: goto label_80256EB4;
    case 0x80256EB8u: goto label_80256EB8;
    case 0x80256EBCu: goto label_80256EBC;
    case 0x80256EC0u: goto label_80256EC0;
    case 0x80256EC4u: goto label_80256EC4;
    case 0x80256EC8u: goto label_80256EC8;
    case 0x80256ECCu: goto label_80256ECC;
    case 0x80256ED0u: goto label_80256ED0;
    case 0x80256ED4u: goto label_80256ED4;
    case 0x80256ED8u: goto label_80256ED8;
    case 0x80256EDCu: goto label_80256EDC;
    case 0x80256EE0u: goto label_80256EE0;
    case 0x80256EE4u: goto label_80256EE4;
    case 0x80256EE8u: goto label_80256EE8;
    case 0x80256EECu: goto label_80256EEC;
    case 0x80256EF0u: goto label_80256EF0;
    case 0x80256EF4u: goto label_80256EF4;
    case 0x80256EF8u: goto label_80256EF8;
    case 0x80256EFCu: goto label_80256EFC;
    case 0x80256F00u: goto label_80256F00;
    case 0x80256F04u: goto label_80256F04;
    case 0x80256F08u: goto label_80256F08;
    case 0x80256F0Cu: goto label_80256F0C;
    case 0x80256F10u: goto label_80256F10;
    case 0x80256F14u: goto label_80256F14;
    case 0x80256F18u: goto label_80256F18;
    case 0x80256F1Cu: goto label_80256F1C;
    case 0x80256F20u: goto label_80256F20;
    case 0x80256F24u: goto label_80256F24;
    case 0x80256F28u: goto label_80256F28;
    case 0x80256F2Cu: goto label_80256F2C;
    case 0x80256F30u: goto label_80256F30;
    case 0x80256F34u: goto label_80256F34;
    case 0x80256F38u: goto label_80256F38;
    case 0x80256F3Cu: goto label_80256F3C;
    case 0x80256F40u: goto label_80256F40;
    case 0x80256F44u: goto label_80256F44;
    case 0x80256F48u: goto label_80256F48;
    case 0x80256F4Cu: goto label_80256F4C;
    case 0x80256F50u: goto label_80256F50;
    case 0x80256F54u: goto label_80256F54;
    case 0x80256F58u: goto label_80256F58;
    case 0x80256F5Cu: goto label_80256F5C;
    case 0x80256F60u: goto label_80256F60;
    case 0x80256F64u: goto label_80256F64;
    case 0x80256F68u: goto label_80256F68;
    case 0x80256F6Cu: goto label_80256F6C;
    case 0x80256F70u: goto label_80256F70;
    case 0x80256F74u: goto label_80256F74;
    case 0x80256F78u: goto label_80256F78;
    case 0x80256F7Cu: goto label_80256F7C;
    case 0x80256F80u: goto label_80256F80;
    case 0x80256F84u: goto label_80256F84;
    case 0x80256F88u: goto label_80256F88;
    case 0x80256F8Cu: goto label_80256F8C;
    case 0x80256F90u: goto label_80256F90;
    case 0x80256F94u: goto label_80256F94;
    case 0x80256F98u: goto label_80256F98;
    case 0x80256F9Cu: goto label_80256F9C;
    case 0x80256FA0u: goto label_80256FA0;
    case 0x80256FA4u: goto label_80256FA4;
    case 0x80256FA8u: goto label_80256FA8;
    case 0x80256FACu: goto label_80256FAC;
    case 0x80256FB0u: goto label_80256FB0;
    case 0x80256FB4u: goto label_80256FB4;
    case 0x80256FB8u: goto label_80256FB8;
    case 0x80256FBCu: goto label_80256FBC;
    case 0x80256FC0u: goto label_80256FC0;
    case 0x80256FC4u: goto label_80256FC4;
    case 0x80256FC8u: goto label_80256FC8;
    case 0x80256FCCu: goto label_80256FCC;
    case 0x80256FD0u: goto label_80256FD0;
    case 0x80256FD4u: goto label_80256FD4;
    case 0x80256FD8u: goto label_80256FD8;
    case 0x80256FDCu: goto label_80256FDC;
    case 0x80256FE0u: goto label_80256FE0;
    case 0x80256FE4u: goto label_80256FE4;
    case 0x80256FE8u: goto label_80256FE8;
    case 0x80256FECu: goto label_80256FEC;
    case 0x80256FF0u: goto label_80256FF0;
    case 0x80256FF4u: goto label_80256FF4;
    case 0x80256FF8u: goto label_80256FF8;
    case 0x80256FFCu: goto label_80256FFC;
    case 0x80257000u: goto label_80257000;
    case 0x80257004u: goto label_80257004;
    case 0x80257008u: goto label_80257008;
    case 0x8025700Cu: goto label_8025700C;
    case 0x80257010u: goto label_80257010;
    case 0x80257014u: goto label_80257014;
    case 0x80257018u: goto label_80257018;
    case 0x8025701Cu: goto label_8025701C;
    case 0x80257020u: goto label_80257020;
    case 0x80257024u: goto label_80257024;
    case 0x80257028u: goto label_80257028;
    case 0x8025702Cu: goto label_8025702C;
    case 0x80257030u: goto label_80257030;
    case 0x80257034u: goto label_80257034;
    case 0x80257038u: goto label_80257038;
    case 0x8025703Cu: goto label_8025703C;
    case 0x80257040u: goto label_80257040;
    case 0x80257044u: goto label_80257044;
    case 0x80257048u: goto label_80257048;
    case 0x8025704Cu: goto label_8025704C;
    case 0x80257050u: goto label_80257050;
    case 0x80257054u: goto label_80257054;
    case 0x80257058u: goto label_80257058;
    case 0x8025705Cu: goto label_8025705C;
    case 0x80257060u: goto label_80257060;
    case 0x80257064u: goto label_80257064;
    case 0x80257068u: goto label_80257068;
    case 0x8025706Cu: goto label_8025706C;
    case 0x80257070u: goto label_80257070;
    case 0x80257074u: goto label_80257074;
    case 0x80257078u: goto label_80257078;
    case 0x8025707Cu: goto label_8025707C;
    case 0x80257080u: goto label_80257080;
    case 0x80257084u: goto label_80257084;
    case 0x80257088u: goto label_80257088;
    case 0x8025708Cu: goto label_8025708C;
    case 0x80257090u: goto label_80257090;
    case 0x80257094u: goto label_80257094;
    case 0x80257098u: goto label_80257098;
    case 0x8025709Cu: goto label_8025709C;
    case 0x802570A0u: goto label_802570A0;
    case 0x802570A4u: goto label_802570A4;
    case 0x802570A8u: goto label_802570A8;
    case 0x802570ACu: goto label_802570AC;
    case 0x802570B0u: goto label_802570B0;
    case 0x802570B4u: goto label_802570B4;
    case 0x802570B8u: goto label_802570B8;
    case 0x802570BCu: goto label_802570BC;
    case 0x802570C0u: goto label_802570C0;
    case 0x802570C4u: goto label_802570C4;
    case 0x802570C8u: goto label_802570C8;
    case 0x802570CCu: goto label_802570CC;
    case 0x802570D0u: goto label_802570D0;
    case 0x802570D4u: goto label_802570D4;
    case 0x802570D8u: goto label_802570D8;
    case 0x802570DCu: goto label_802570DC;
    case 0x802570E0u: goto label_802570E0;
    case 0x802570E4u: goto label_802570E4;
    case 0x802570E8u: goto label_802570E8;
    case 0x802570ECu: goto label_802570EC;
    case 0x802570F0u: goto label_802570F0;
    case 0x802570F4u: goto label_802570F4;
    case 0x802570F8u: goto label_802570F8;
    case 0x802570FCu: goto label_802570FC;
    case 0x80257100u: goto label_80257100;
    case 0x80257104u: goto label_80257104;
    case 0x80257108u: goto label_80257108;
    case 0x8025710Cu: goto label_8025710C;
    case 0x80257110u: goto label_80257110;
    case 0x80257114u: goto label_80257114;
    case 0x80257118u: goto label_80257118;
    case 0x8025711Cu: goto label_8025711C;
    case 0x80257120u: goto label_80257120;
    case 0x80257124u: goto label_80257124;
    case 0x80257128u: goto label_80257128;
    case 0x8025712Cu: goto label_8025712C;
    case 0x80257130u: goto label_80257130;
    case 0x80257134u: goto label_80257134;
    case 0x80257138u: goto label_80257138;
    case 0x8025713Cu: goto label_8025713C;
    case 0x80257140u: goto label_80257140;
    case 0x80257144u: goto label_80257144;
    case 0x80257148u: goto label_80257148;
    case 0x8025714Cu: goto label_8025714C;
    case 0x80257150u: goto label_80257150;
    case 0x80257154u: goto label_80257154;
    case 0x80257158u: goto label_80257158;
    case 0x8025715Cu: goto label_8025715C;
    case 0x80257160u: goto label_80257160;
    case 0x80257164u: goto label_80257164;
    case 0x80257168u: goto label_80257168;
    case 0x8025716Cu: goto label_8025716C;
    case 0x80257170u: goto label_80257170;
    case 0x80257174u: goto label_80257174;
    case 0x80257178u: goto label_80257178;
    case 0x8025717Cu: goto label_8025717C;
    case 0x80257180u: goto label_80257180;
    case 0x80257184u: goto label_80257184;
    case 0x80257188u: goto label_80257188;
    case 0x8025718Cu: goto label_8025718C;
    case 0x80257190u: goto label_80257190;
    case 0x80257194u: goto label_80257194;
    case 0x80257198u: goto label_80257198;
    case 0x8025719Cu: goto label_8025719C;
    case 0x802571A0u: goto label_802571A0;
    case 0x802571A4u: goto label_802571A4;
    case 0x802571A8u: goto label_802571A8;
    case 0x802571ACu: goto label_802571AC;
    case 0x802571B0u: goto label_802571B0;
    case 0x802571B4u: goto label_802571B4;
    case 0x802571B8u: goto label_802571B8;
    case 0x802571BCu: goto label_802571BC;
    case 0x802571C0u: goto label_802571C0;
    case 0x802571C4u: goto label_802571C4;
    case 0x802571C8u: goto label_802571C8;
    case 0x802571CCu: goto label_802571CC;
    case 0x802571D0u: goto label_802571D0;
    case 0x802571D4u: goto label_802571D4;
    case 0x802571D8u: goto label_802571D8;
    case 0x802571DCu: goto label_802571DC;
    case 0x802571E0u: goto label_802571E0;
    case 0x802571E4u: goto label_802571E4;
    case 0x802571E8u: goto label_802571E8;
    case 0x802571ECu: goto label_802571EC;
    case 0x802571F0u: goto label_802571F0;
    case 0x802571F4u: goto label_802571F4;
    case 0x802571F8u: goto label_802571F8;
    case 0x802571FCu: goto label_802571FC;
    case 0x80257200u: goto label_80257200;
    case 0x80257204u: goto label_80257204;
    case 0x80257208u: goto label_80257208;
    case 0x8025720Cu: goto label_8025720C;
    case 0x80257210u: goto label_80257210;
    case 0x80257214u: goto label_80257214;
    case 0x80257218u: goto label_80257218;
    case 0x8025721Cu: goto label_8025721C;
    case 0x80257220u: goto label_80257220;
    case 0x80257224u: goto label_80257224;
    case 0x80257228u: goto label_80257228;
    case 0x8025722Cu: goto label_8025722C;
    case 0x80257230u: goto label_80257230;
    case 0x80257234u: goto label_80257234;
    case 0x80257238u: goto label_80257238;
    case 0x8025723Cu: goto label_8025723C;
    case 0x80257240u: goto label_80257240;
    case 0x80257244u: goto label_80257244;
    case 0x80257248u: goto label_80257248;
    case 0x8025724Cu: goto label_8025724C;
    case 0x80257250u: goto label_80257250;
    case 0x80257254u: goto label_80257254;
    case 0x80257258u: goto label_80257258;
    case 0x8025725Cu: goto label_8025725C;
    case 0x80257260u: goto label_80257260;
    case 0x80257264u: goto label_80257264;
    case 0x80257268u: goto label_80257268;
    case 0x8025726Cu: goto label_8025726C;
    case 0x80257270u: goto label_80257270;
    case 0x80257274u: goto label_80257274;
    case 0x80257278u: goto label_80257278;
    case 0x8025727Cu: goto label_8025727C;
    case 0x80257280u: goto label_80257280;
    case 0x80257284u: goto label_80257284;
    case 0x80257288u: goto label_80257288;
    case 0x8025728Cu: goto label_8025728C;
    case 0x80257290u: goto label_80257290;
    case 0x80257294u: goto label_80257294;
    case 0x80257298u: goto label_80257298;
    case 0x8025729Cu: goto label_8025729C;
    case 0x802572A0u: goto label_802572A0;
    case 0x802572A4u: goto label_802572A4;
    case 0x802572A8u: goto label_802572A8;
    case 0x802572ACu: goto label_802572AC;
    case 0x802572B0u: goto label_802572B0;
    case 0x802572B4u: goto label_802572B4;
    case 0x802572B8u: goto label_802572B8;
    case 0x802572BCu: goto label_802572BC;
    case 0x802572C0u: goto label_802572C0;
    case 0x802572C4u: goto label_802572C4;
    case 0x802572C8u: goto label_802572C8;
    case 0x802572CCu: goto label_802572CC;
    case 0x802572D0u: goto label_802572D0;
    case 0x802572D4u: goto label_802572D4;
    case 0x802572D8u: goto label_802572D8;
    case 0x802572DCu: goto label_802572DC;
    case 0x802572E0u: goto label_802572E0;
    case 0x802572E4u: goto label_802572E4;
    case 0x802572E8u: goto label_802572E8;
    case 0x802572ECu: goto label_802572EC;
    case 0x802572F0u: goto label_802572F0;
    case 0x802572F4u: goto label_802572F4;
    case 0x802572F8u: goto label_802572F8;
    case 0x802572FCu: goto label_802572FC;
    case 0x80257300u: goto label_80257300;
    case 0x80257304u: goto label_80257304;
    case 0x80257308u: goto label_80257308;
    case 0x8025730Cu: goto label_8025730C;
    case 0x80257310u: goto label_80257310;
    case 0x80257314u: goto label_80257314;
    case 0x80257318u: goto label_80257318;
    case 0x8025731Cu: goto label_8025731C;
    case 0x80257320u: goto label_80257320;
    case 0x80257324u: goto label_80257324;
    case 0x80257328u: goto label_80257328;
    case 0x8025732Cu: goto label_8025732C;
    case 0x80257330u: goto label_80257330;
    case 0x80257334u: goto label_80257334;
    case 0x80257338u: goto label_80257338;
    case 0x8025733Cu: goto label_8025733C;
    case 0x80257340u: goto label_80257340;
    case 0x80257344u: goto label_80257344;
    case 0x80257348u: goto label_80257348;
    case 0x8025734Cu: goto label_8025734C;
    case 0x80257350u: goto label_80257350;
    case 0x80257354u: goto label_80257354;
    case 0x80257358u: goto label_80257358;
    case 0x8025735Cu: goto label_8025735C;
    case 0x80257360u: goto label_80257360;
    case 0x80257364u: goto label_80257364;
    case 0x80257368u: goto label_80257368;
    case 0x8025736Cu: goto label_8025736C;
    case 0x80257370u: goto label_80257370;
    case 0x80257374u: goto label_80257374;
    case 0x80257378u: goto label_80257378;
    case 0x8025737Cu: goto label_8025737C;
    case 0x80257380u: goto label_80257380;
    case 0x80257384u: goto label_80257384;
    case 0x80257388u: goto label_80257388;
    case 0x8025738Cu: goto label_8025738C;
    case 0x80257390u: goto label_80257390;
    case 0x80257394u: goto label_80257394;
    case 0x80257398u: goto label_80257398;
    case 0x8025739Cu: goto label_8025739C;
    case 0x802573A0u: goto label_802573A0;
    case 0x802573A4u: goto label_802573A4;
    case 0x802573A8u: goto label_802573A8;
    case 0x802573ACu: goto label_802573AC;
    case 0x802573B0u: goto label_802573B0;
    case 0x802573B4u: goto label_802573B4;
    case 0x802573B8u: goto label_802573B8;
    case 0x802573BCu: goto label_802573BC;
    case 0x802573C0u: goto label_802573C0;
    case 0x802573C4u: goto label_802573C4;
    case 0x802573C8u: goto label_802573C8;
    case 0x802573CCu: goto label_802573CC;
    case 0x802573D0u: goto label_802573D0;
    case 0x802573D4u: goto label_802573D4;
    case 0x802573D8u: goto label_802573D8;
    case 0x802573DCu: goto label_802573DC;
    case 0x802573E0u: goto label_802573E0;
    case 0x802573E4u: goto label_802573E4;
    case 0x802573E8u: goto label_802573E8;
    case 0x802573ECu: goto label_802573EC;
    case 0x802573F0u: goto label_802573F0;
    case 0x802573F4u: goto label_802573F4;
    case 0x802573F8u: goto label_802573F8;
    case 0x802573FCu: goto label_802573FC;
    case 0x80257400u: goto label_80257400;
    case 0x80257404u: goto label_80257404;
    case 0x80257408u: goto label_80257408;
    case 0x8025740Cu: goto label_8025740C;
    case 0x80257410u: goto label_80257410;
    case 0x80257414u: goto label_80257414;
    case 0x80257418u: goto label_80257418;
    case 0x8025741Cu: goto label_8025741C;
    case 0x80257420u: goto label_80257420;
    case 0x80257424u: goto label_80257424;
    case 0x80257428u: goto label_80257428;
    case 0x8025742Cu: goto label_8025742C;
    case 0x80257430u: goto label_80257430;
    case 0x80257434u: goto label_80257434;
    case 0x80257438u: goto label_80257438;
    case 0x8025743Cu: goto label_8025743C;
    case 0x80257440u: goto label_80257440;
    case 0x80257444u: goto label_80257444;
    case 0x80257448u: goto label_80257448;
    case 0x8025744Cu: goto label_8025744C;
    case 0x80257450u: goto label_80257450;
    case 0x80257454u: goto label_80257454;
    case 0x80257458u: goto label_80257458;
    case 0x8025745Cu: goto label_8025745C;
    case 0x80257460u: goto label_80257460;
    case 0x80257464u: goto label_80257464;
    case 0x80257468u: goto label_80257468;
    case 0x8025746Cu: goto label_8025746C;
    case 0x80257470u: goto label_80257470;
    case 0x80257474u: goto label_80257474;
    case 0x80257478u: goto label_80257478;
    case 0x8025747Cu: goto label_8025747C;
    case 0x80257480u: goto label_80257480;
    case 0x80257484u: goto label_80257484;
    case 0x80257488u: goto label_80257488;
    case 0x8025748Cu: goto label_8025748C;
    case 0x80257490u: goto label_80257490;
    case 0x80257494u: goto label_80257494;
    case 0x80257498u: goto label_80257498;
    case 0x8025749Cu: goto label_8025749C;
    case 0x802574A0u: goto label_802574A0;
    case 0x802574A4u: goto label_802574A4;
    case 0x802574A8u: goto label_802574A8;
    case 0x802574ACu: goto label_802574AC;
    case 0x802574B0u: goto label_802574B0;
    case 0x802574B4u: goto label_802574B4;
    case 0x802574B8u: goto label_802574B8;
    case 0x802574BCu: goto label_802574BC;
    case 0x802574C0u: goto label_802574C0;
    case 0x802574C4u: goto label_802574C4;
    case 0x802574C8u: goto label_802574C8;
    case 0x802574CCu: goto label_802574CC;
    case 0x802574D0u: goto label_802574D0;
    case 0x802574D4u: goto label_802574D4;
    case 0x802574D8u: goto label_802574D8;
    case 0x802574DCu: goto label_802574DC;
    case 0x802574E0u: goto label_802574E0;
    case 0x802574E4u: goto label_802574E4;
    case 0x802574E8u: goto label_802574E8;
    case 0x802574ECu: goto label_802574EC;
    case 0x802574F0u: goto label_802574F0;
    case 0x802574F4u: goto label_802574F4;
    case 0x802574F8u: goto label_802574F8;
    case 0x802574FCu: goto label_802574FC;
    case 0x80257500u: goto label_80257500;
    case 0x80257504u: goto label_80257504;
    case 0x80257508u: goto label_80257508;
    case 0x8025750Cu: goto label_8025750C;
    case 0x80257510u: goto label_80257510;
    case 0x80257514u: goto label_80257514;
    case 0x80257518u: goto label_80257518;
    case 0x8025751Cu: goto label_8025751C;
    case 0x80257520u: goto label_80257520;
    case 0x80257524u: goto label_80257524;
    case 0x80257528u: goto label_80257528;
    case 0x8025752Cu: goto label_8025752C;
    case 0x80257530u: goto label_80257530;
    case 0x80257534u: goto label_80257534;
    case 0x80257538u: goto label_80257538;
    case 0x8025753Cu: goto label_8025753C;
    case 0x80257540u: goto label_80257540;
    case 0x80257544u: goto label_80257544;
    case 0x80257548u: goto label_80257548;
    case 0x8025754Cu: goto label_8025754C;
    case 0x80257550u: goto label_80257550;
    case 0x80257554u: goto label_80257554;
    case 0x80257558u: goto label_80257558;
    case 0x8025755Cu: goto label_8025755C;
    case 0x80257560u: goto label_80257560;
    case 0x80257564u: goto label_80257564;
    case 0x80257568u: goto label_80257568;
    case 0x8025756Cu: goto label_8025756C;
    case 0x80257570u: goto label_80257570;
    case 0x80257574u: goto label_80257574;
    case 0x80257578u: goto label_80257578;
    case 0x8025757Cu: goto label_8025757C;
    case 0x80257580u: goto label_80257580;
    case 0x80257584u: goto label_80257584;
    case 0x80257588u: goto label_80257588;
    case 0x8025758Cu: goto label_8025758C;
    case 0x80257590u: goto label_80257590;
    case 0x80257594u: goto label_80257594;
    case 0x80257598u: goto label_80257598;
    case 0x8025759Cu: goto label_8025759C;
    case 0x802575A0u: goto label_802575A0;
    case 0x802575A4u: goto label_802575A4;
    case 0x802575A8u: goto label_802575A8;
    case 0x802575ACu: goto label_802575AC;
    case 0x802575B0u: goto label_802575B0;
    case 0x802575B4u: goto label_802575B4;
    case 0x802575B8u: goto label_802575B8;
    case 0x802575BCu: goto label_802575BC;
    case 0x802575C0u: goto label_802575C0;
    case 0x802575C4u: goto label_802575C4;
    case 0x802575C8u: goto label_802575C8;
    case 0x802575CCu: goto label_802575CC;
    case 0x802575D0u: goto label_802575D0;
    case 0x802575D4u: goto label_802575D4;
    case 0x802575D8u: goto label_802575D8;
    case 0x802575DCu: goto label_802575DC;
    case 0x802575E0u: goto label_802575E0;
    case 0x802575E4u: goto label_802575E4;
    case 0x802575E8u: goto label_802575E8;
    case 0x802575ECu: goto label_802575EC;
    case 0x802575F0u: goto label_802575F0;
    case 0x802575F4u: goto label_802575F4;
    case 0x802575F8u: goto label_802575F8;
    case 0x802575FCu: goto label_802575FC;
    case 0x80257600u: goto label_80257600;
    case 0x80257604u: goto label_80257604;
    case 0x80257608u: goto label_80257608;
    case 0x8025760Cu: goto label_8025760C;
    case 0x80257610u: goto label_80257610;
    case 0x80257614u: goto label_80257614;
    case 0x80257618u: goto label_80257618;
    case 0x8025761Cu: goto label_8025761C;
    case 0x80257620u: goto label_80257620;
    case 0x80257624u: goto label_80257624;
    case 0x80257628u: goto label_80257628;
    case 0x8025762Cu: goto label_8025762C;
    case 0x80257630u: goto label_80257630;
    case 0x80257634u: goto label_80257634;
    case 0x80257638u: goto label_80257638;
    case 0x8025763Cu: goto label_8025763C;
    case 0x80257640u: goto label_80257640;
    case 0x80257644u: goto label_80257644;
    case 0x80257648u: goto label_80257648;
    case 0x8025764Cu: goto label_8025764C;
    case 0x80257650u: goto label_80257650;
    case 0x80257654u: goto label_80257654;
    case 0x80257658u: goto label_80257658;
    case 0x8025765Cu: goto label_8025765C;
    case 0x80257660u: goto label_80257660;
    case 0x80257664u: goto label_80257664;
    case 0x80257668u: goto label_80257668;
    case 0x8025766Cu: goto label_8025766C;
    case 0x80257670u: goto label_80257670;
    case 0x80257674u: goto label_80257674;
    case 0x80257678u: goto label_80257678;
    case 0x8025767Cu: goto label_8025767C;
    case 0x80257680u: goto label_80257680;
    case 0x80257684u: goto label_80257684;
    case 0x80257688u: goto label_80257688;
    case 0x8025768Cu: goto label_8025768C;
    case 0x80257690u: goto label_80257690;
    case 0x80257694u: goto label_80257694;
    case 0x80257698u: goto label_80257698;
    case 0x8025769Cu: goto label_8025769C;
    case 0x802576A0u: goto label_802576A0;
    case 0x802576A4u: goto label_802576A4;
    case 0x802576A8u: goto label_802576A8;
    case 0x802576ACu: goto label_802576AC;
    case 0x802576B0u: goto label_802576B0;
    case 0x802576B4u: goto label_802576B4;
    case 0x802576B8u: goto label_802576B8;
    case 0x802576BCu: goto label_802576BC;
    case 0x802576C0u: goto label_802576C0;
    case 0x802576C4u: goto label_802576C4;
    case 0x802576C8u: goto label_802576C8;
    case 0x802576CCu: goto label_802576CC;
    case 0x802576D0u: goto label_802576D0;
    case 0x802576D4u: goto label_802576D4;
    case 0x802576D8u: goto label_802576D8;
    case 0x802576DCu: goto label_802576DC;
    case 0x802576E0u: goto label_802576E0;
    case 0x802576E4u: goto label_802576E4;
    case 0x802576E8u: goto label_802576E8;
    case 0x802576ECu: goto label_802576EC;
    case 0x802576F0u: goto label_802576F0;
    case 0x802576F4u: goto label_802576F4;
    case 0x802576F8u: goto label_802576F8;
    case 0x802576FCu: goto label_802576FC;
    case 0x80257700u: goto label_80257700;
    case 0x80257704u: goto label_80257704;
    case 0x80257708u: goto label_80257708;
    case 0x8025770Cu: goto label_8025770C;
    case 0x80257710u: goto label_80257710;
    case 0x80257714u: goto label_80257714;
    case 0x80257718u: goto label_80257718;
    case 0x8025771Cu: goto label_8025771C;
    case 0x80257720u: goto label_80257720;
    case 0x80257724u: goto label_80257724;
    case 0x80257728u: goto label_80257728;
    case 0x8025772Cu: goto label_8025772C;
    case 0x80257730u: goto label_80257730;
    case 0x80257734u: goto label_80257734;
    case 0x80257738u: goto label_80257738;
    case 0x8025773Cu: goto label_8025773C;
    case 0x80257740u: goto label_80257740;
    case 0x80257744u: goto label_80257744;
    case 0x80257748u: goto label_80257748;
    case 0x8025774Cu: goto label_8025774C;
    case 0x80257750u: goto label_80257750;
    case 0x80257754u: goto label_80257754;
    case 0x80257758u: goto label_80257758;
    case 0x8025775Cu: goto label_8025775C;
    case 0x80257760u: goto label_80257760;
    case 0x80257764u: goto label_80257764;
    case 0x80257768u: goto label_80257768;
    case 0x8025776Cu: goto label_8025776C;
    case 0x80257770u: goto label_80257770;
    case 0x80257774u: goto label_80257774;
    case 0x80257778u: goto label_80257778;
    case 0x8025777Cu: goto label_8025777C;
    case 0x80257780u: goto label_80257780;
    case 0x80257784u: goto label_80257784;
    case 0x80257788u: goto label_80257788;
    case 0x8025778Cu: goto label_8025778C;
    case 0x80257790u: goto label_80257790;
    case 0x80257794u: goto label_80257794;
    case 0x80257798u: goto label_80257798;
    case 0x8025779Cu: goto label_8025779C;
    case 0x802577A0u: goto label_802577A0;
    case 0x802577A4u: goto label_802577A4;
    case 0x802577A8u: goto label_802577A8;
    case 0x802577ACu: goto label_802577AC;
    case 0x802577B0u: goto label_802577B0;
    case 0x802577B4u: goto label_802577B4;
    case 0x802577B8u: goto label_802577B8;
    case 0x802577BCu: goto label_802577BC;
    case 0x802577C0u: goto label_802577C0;
    case 0x802577C4u: goto label_802577C4;
    case 0x802577C8u: goto label_802577C8;
    case 0x802577CCu: goto label_802577CC;
    case 0x802577D0u: goto label_802577D0;
    case 0x802577D4u: goto label_802577D4;
    case 0x802577D8u: goto label_802577D8;
    case 0x802577DCu: goto label_802577DC;
    case 0x802577E0u: goto label_802577E0;
    case 0x802577E4u: goto label_802577E4;
    case 0x802577E8u: goto label_802577E8;
    case 0x802577ECu: goto label_802577EC;
    case 0x802577F0u: goto label_802577F0;
    case 0x802577F4u: goto label_802577F4;
    case 0x802577F8u: goto label_802577F8;
    case 0x802577FCu: goto label_802577FC;
    case 0x80257800u: goto label_80257800;
    case 0x80257804u: goto label_80257804;
    case 0x80257808u: goto label_80257808;
    case 0x8025780Cu: goto label_8025780C;
    case 0x80257810u: goto label_80257810;
    case 0x80257814u: goto label_80257814;
    case 0x80257818u: goto label_80257818;
    case 0x8025781Cu: goto label_8025781C;
    case 0x80257820u: goto label_80257820;
    case 0x80257824u: goto label_80257824;
    case 0x80257828u: goto label_80257828;
    case 0x8025782Cu: goto label_8025782C;
    case 0x80257830u: goto label_80257830;
    case 0x80257834u: goto label_80257834;
    case 0x80257838u: goto label_80257838;
    case 0x8025783Cu: goto label_8025783C;
    case 0x80257840u: goto label_80257840;
    case 0x80257844u: goto label_80257844;
    case 0x80257848u: goto label_80257848;
    case 0x8025784Cu: goto label_8025784C;
    case 0x80257850u: goto label_80257850;
    case 0x80257854u: goto label_80257854;
    case 0x80257858u: goto label_80257858;
    case 0x8025785Cu: goto label_8025785C;
    case 0x80257860u: goto label_80257860;
    case 0x80257864u: goto label_80257864;
    case 0x80257868u: goto label_80257868;
    case 0x8025786Cu: goto label_8025786C;
    case 0x80257870u: goto label_80257870;
    case 0x80257874u: goto label_80257874;
    case 0x80257878u: goto label_80257878;
    case 0x8025787Cu: goto label_8025787C;
    case 0x80257880u: goto label_80257880;
    case 0x80257884u: goto label_80257884;
    case 0x80257888u: goto label_80257888;
    case 0x8025788Cu: goto label_8025788C;
    case 0x80257890u: goto label_80257890;
    case 0x80257894u: goto label_80257894;
    case 0x80257898u: goto label_80257898;
    case 0x8025789Cu: goto label_8025789C;
    case 0x802578A0u: goto label_802578A0;
    case 0x802578A4u: goto label_802578A4;
    case 0x802578A8u: goto label_802578A8;
    case 0x802578ACu: goto label_802578AC;
    case 0x802578B0u: goto label_802578B0;
    case 0x802578B4u: goto label_802578B4;
    case 0x802578B8u: goto label_802578B8;
    case 0x802578BCu: goto label_802578BC;
    case 0x802578C0u: goto label_802578C0;
    case 0x802578C4u: goto label_802578C4;
    case 0x802578C8u: goto label_802578C8;
    case 0x802578CCu: goto label_802578CC;
    case 0x802578D0u: goto label_802578D0;
    case 0x802578D4u: goto label_802578D4;
    case 0x802578D8u: goto label_802578D8;
    case 0x802578DCu: goto label_802578DC;
    case 0x802578E0u: goto label_802578E0;
    case 0x802578E4u: goto label_802578E4;
    case 0x802578E8u: goto label_802578E8;
    case 0x802578ECu: goto label_802578EC;
    case 0x802578F0u: goto label_802578F0;
    case 0x802578F4u: goto label_802578F4;
    case 0x802578F8u: goto label_802578F8;
    case 0x802578FCu: goto label_802578FC;
    case 0x80257900u: goto label_80257900;
    case 0x80257904u: goto label_80257904;
    case 0x80257908u: goto label_80257908;
    case 0x8025790Cu: goto label_8025790C;
    case 0x80257910u: goto label_80257910;
    case 0x80257914u: goto label_80257914;
    case 0x80257918u: goto label_80257918;
    case 0x8025791Cu: goto label_8025791C;
    case 0x80257920u: goto label_80257920;
    case 0x80257924u: goto label_80257924;
    case 0x80257928u: goto label_80257928;
    case 0x8025792Cu: goto label_8025792C;
    case 0x80257930u: goto label_80257930;
    case 0x80257934u: goto label_80257934;
    case 0x80257938u: goto label_80257938;
    case 0x8025793Cu: goto label_8025793C;
    case 0x80257940u: goto label_80257940;
    case 0x80257944u: goto label_80257944;
    case 0x80257948u: goto label_80257948;
    case 0x8025794Cu: goto label_8025794C;
    case 0x80257950u: goto label_80257950;
    case 0x80257954u: goto label_80257954;
    case 0x80257958u: goto label_80257958;
    case 0x8025795Cu: goto label_8025795C;
    case 0x80257960u: goto label_80257960;
    case 0x80257964u: goto label_80257964;
    case 0x80257968u: goto label_80257968;
    case 0x8025796Cu: goto label_8025796C;
    case 0x80257970u: goto label_80257970;
    case 0x80257974u: goto label_80257974;
    case 0x80257978u: goto label_80257978;
    case 0x8025797Cu: goto label_8025797C;
    case 0x80257980u: goto label_80257980;
    case 0x80257984u: goto label_80257984;
    case 0x80257988u: goto label_80257988;
    case 0x8025798Cu: goto label_8025798C;
    case 0x80257990u: goto label_80257990;
    case 0x80257994u: goto label_80257994;
    case 0x80257998u: goto label_80257998;
    case 0x8025799Cu: goto label_8025799C;
    case 0x802579A0u: goto label_802579A0;
    case 0x802579A4u: goto label_802579A4;
    case 0x802579A8u: goto label_802579A8;
    case 0x802579ACu: goto label_802579AC;
    case 0x802579B0u: goto label_802579B0;
    case 0x802579B4u: goto label_802579B4;
    case 0x802579B8u: goto label_802579B8;
    case 0x802579BCu: goto label_802579BC;
    case 0x802579C0u: goto label_802579C0;
    case 0x802579C4u: goto label_802579C4;
    case 0x802579C8u: goto label_802579C8;
    case 0x802579CCu: goto label_802579CC;
    case 0x802579D0u: goto label_802579D0;
    case 0x802579D4u: goto label_802579D4;
    case 0x802579D8u: goto label_802579D8;
    case 0x802579DCu: goto label_802579DC;
    case 0x802579E0u: goto label_802579E0;
    case 0x802579E4u: goto label_802579E4;
    case 0x802579E8u: goto label_802579E8;
    case 0x802579ECu: goto label_802579EC;
    case 0x802579F0u: goto label_802579F0;
    case 0x802579F4u: goto label_802579F4;
    case 0x802579F8u: goto label_802579F8;
    case 0x802579FCu: goto label_802579FC;
    case 0x80257A00u: goto label_80257A00;
    case 0x80257A04u: goto label_80257A04;
    case 0x80257A08u: goto label_80257A08;
    case 0x80257A0Cu: goto label_80257A0C;
    case 0x80257A10u: goto label_80257A10;
    case 0x80257A14u: goto label_80257A14;
    case 0x80257A18u: goto label_80257A18;
    case 0x80257A1Cu: goto label_80257A1C;
    case 0x80257A20u: goto label_80257A20;
    case 0x80257A24u: goto label_80257A24;
    case 0x80257A28u: goto label_80257A28;
    case 0x80257A2Cu: goto label_80257A2C;
    case 0x80257A30u: goto label_80257A30;
    case 0x80257A34u: goto label_80257A34;
    case 0x80257A38u: goto label_80257A38;
    case 0x80257A3Cu: goto label_80257A3C;
    case 0x80257A40u: goto label_80257A40;
    case 0x80257A44u: goto label_80257A44;
    case 0x80257A48u: goto label_80257A48;
    case 0x80257A4Cu: goto label_80257A4C;
    case 0x80257A50u: goto label_80257A50;
    case 0x80257A54u: goto label_80257A54;
    case 0x80257A58u: goto label_80257A58;
    case 0x80257A5Cu: goto label_80257A5C;
    case 0x80257A60u: goto label_80257A60;
    case 0x80257A64u: goto label_80257A64;
    case 0x80257A68u: goto label_80257A68;
    case 0x80257A6Cu: goto label_80257A6C;
    case 0x80257A70u: goto label_80257A70;
    case 0x80257A74u: goto label_80257A74;
    case 0x80257A78u: goto label_80257A78;
    case 0x80257A7Cu: goto label_80257A7C;
    case 0x80257A80u: goto label_80257A80;
    case 0x80257A84u: goto label_80257A84;
    case 0x80257A88u: goto label_80257A88;
    case 0x80257A8Cu: goto label_80257A8C;
    case 0x80257A90u: goto label_80257A90;
    case 0x80257A94u: goto label_80257A94;
    case 0x80257A98u: goto label_80257A98;
    case 0x80257A9Cu: goto label_80257A9C;
    case 0x80257AA0u: goto label_80257AA0;
    case 0x80257AA4u: goto label_80257AA4;
    case 0x80257AA8u: goto label_80257AA8;
    case 0x80257AACu: goto label_80257AAC;
    case 0x80257AB0u: goto label_80257AB0;
    case 0x80257AB4u: goto label_80257AB4;
    case 0x80257AB8u: goto label_80257AB8;
    case 0x80257ABCu: goto label_80257ABC;
    case 0x80257AC0u: goto label_80257AC0;
    case 0x80257AC4u: goto label_80257AC4;
    case 0x80257AC8u: goto label_80257AC8;
    case 0x80257ACCu: goto label_80257ACC;
    case 0x80257AD0u: goto label_80257AD0;
    case 0x80257AD4u: goto label_80257AD4;
    case 0x80257AD8u: goto label_80257AD8;
    case 0x80257ADCu: goto label_80257ADC;
    case 0x80257AE0u: goto label_80257AE0;
    case 0x80257AE4u: goto label_80257AE4;
    case 0x80257AE8u: goto label_80257AE8;
    case 0x80257AECu: goto label_80257AEC;
    case 0x80257AF0u: goto label_80257AF0;
    case 0x80257AF4u: goto label_80257AF4;
    case 0x80257AF8u: goto label_80257AF8;
    case 0x80257AFCu: goto label_80257AFC;
    case 0x80257B00u: goto label_80257B00;
    case 0x80257B04u: goto label_80257B04;
    case 0x80257B08u: goto label_80257B08;
    case 0x80257B0Cu: goto label_80257B0C;
    case 0x80257B10u: goto label_80257B10;
    case 0x80257B14u: goto label_80257B14;
    case 0x80257B18u: goto label_80257B18;
    case 0x80257B1Cu: goto label_80257B1C;
    case 0x80257B20u: goto label_80257B20;
    case 0x80257B24u: goto label_80257B24;
    case 0x80257B28u: goto label_80257B28;
    case 0x80257B2Cu: goto label_80257B2C;
    case 0x80257B30u: goto label_80257B30;
    case 0x80257B34u: goto label_80257B34;
    case 0x80257B38u: goto label_80257B38;
    case 0x80257B3Cu: goto label_80257B3C;
    case 0x80257B40u: goto label_80257B40;
    case 0x80257B44u: goto label_80257B44;
    case 0x80257B48u: goto label_80257B48;
    case 0x80257B4Cu: goto label_80257B4C;
    case 0x80257B50u: goto label_80257B50;
    case 0x80257B54u: goto label_80257B54;
    case 0x80257B58u: goto label_80257B58;
    case 0x80257B5Cu: goto label_80257B5C;
    case 0x80257B60u: goto label_80257B60;
    case 0x80257B64u: goto label_80257B64;
    case 0x80257B68u: goto label_80257B68;
    case 0x80257B6Cu: goto label_80257B6C;
    case 0x80257B70u: goto label_80257B70;
    case 0x80257B74u: goto label_80257B74;
    case 0x80257B78u: goto label_80257B78;
    case 0x80257B7Cu: goto label_80257B7C;
    case 0x80257B80u: goto label_80257B80;
    case 0x80257B84u: goto label_80257B84;
    case 0x80257B88u: goto label_80257B88;
    case 0x80257B8Cu: goto label_80257B8C;
    case 0x80257B90u: goto label_80257B90;
    case 0x80257B94u: goto label_80257B94;
    case 0x80257B98u: goto label_80257B98;
    case 0x80257B9Cu: goto label_80257B9C;
    case 0x80257BA0u: goto label_80257BA0;
    case 0x80257BA4u: goto label_80257BA4;
    case 0x80257BA8u: goto label_80257BA8;
    case 0x80257BACu: goto label_80257BAC;
    case 0x80257BB0u: goto label_80257BB0;
    case 0x80257BB4u: goto label_80257BB4;
    case 0x80257BB8u: goto label_80257BB8;
    case 0x80257BBCu: goto label_80257BBC;
    case 0x80257BC0u: goto label_80257BC0;
    case 0x80257BC4u: goto label_80257BC4;
    case 0x80257BC8u: goto label_80257BC8;
    case 0x80257BCCu: goto label_80257BCC;
    case 0x80257BD0u: goto label_80257BD0;
    case 0x80257BD4u: goto label_80257BD4;
    case 0x80257BD8u: goto label_80257BD8;
    case 0x80257BDCu: goto label_80257BDC;
    case 0x80257BE0u: goto label_80257BE0;
    case 0x80257BE4u: goto label_80257BE4;
    case 0x80257BE8u: goto label_80257BE8;
    case 0x80257BECu: goto label_80257BEC;
    case 0x80257BF0u: goto label_80257BF0;
    case 0x80257BF4u: goto label_80257BF4;
    case 0x80257BF8u: goto label_80257BF8;
    case 0x80257BFCu: goto label_80257BFC;
    case 0x80257C00u: goto label_80257C00;
    case 0x80257C04u: goto label_80257C04;
    case 0x80257C08u: goto label_80257C08;
    case 0x80257C0Cu: goto label_80257C0C;
    case 0x80257C10u: goto label_80257C10;
    case 0x80257C14u: goto label_80257C14;
    case 0x80257C18u: goto label_80257C18;
    case 0x80257C1Cu: goto label_80257C1C;
    case 0x80257C20u: goto label_80257C20;
    case 0x80257C24u: goto label_80257C24;
    case 0x80257C28u: goto label_80257C28;
    case 0x80257C2Cu: goto label_80257C2C;
    case 0x80257C30u: goto label_80257C30;
    case 0x80257C34u: goto label_80257C34;
    case 0x80257C38u: goto label_80257C38;
    case 0x80257C3Cu: goto label_80257C3C;
    case 0x80257C40u: goto label_80257C40;
    case 0x80257C44u: goto label_80257C44;
    case 0x80257C48u: goto label_80257C48;
    case 0x80257C4Cu: goto label_80257C4C;
    case 0x80257C50u: goto label_80257C50;
    case 0x80257C54u: goto label_80257C54;
    case 0x80257C58u: goto label_80257C58;
    case 0x80257C5Cu: goto label_80257C5C;
    case 0x80257C60u: goto label_80257C60;
    case 0x80257C64u: goto label_80257C64;
    case 0x80257C68u: goto label_80257C68;
    case 0x80257C6Cu: goto label_80257C6C;
    case 0x80257C70u: goto label_80257C70;
    case 0x80257C74u: goto label_80257C74;
    case 0x80257C78u: goto label_80257C78;
    case 0x80257C7Cu: goto label_80257C7C;
    case 0x80257C80u: goto label_80257C80;
    case 0x80257C84u: goto label_80257C84;
    case 0x80257C88u: goto label_80257C88;
    case 0x80257C8Cu: goto label_80257C8C;
    case 0x80257C90u: goto label_80257C90;
    case 0x80257C94u: goto label_80257C94;
    case 0x80257C98u: goto label_80257C98;
    case 0x80257C9Cu: goto label_80257C9C;
    case 0x80257CA0u: goto label_80257CA0;
    case 0x80257CA4u: goto label_80257CA4;
    case 0x80257CA8u: goto label_80257CA8;
    case 0x80257CACu: goto label_80257CAC;
    case 0x80257CB0u: goto label_80257CB0;
    case 0x80257CB4u: goto label_80257CB4;
    case 0x80257CB8u: goto label_80257CB8;
    case 0x80257CBCu: goto label_80257CBC;
    case 0x80257CC0u: goto label_80257CC0;
    case 0x80257CC4u: goto label_80257CC4;
    case 0x80257CC8u: goto label_80257CC8;
    case 0x80257CCCu: goto label_80257CCC;
    case 0x80257CD0u: goto label_80257CD0;
    case 0x80257CD4u: goto label_80257CD4;
    case 0x80257CD8u: goto label_80257CD8;
    case 0x80257CDCu: goto label_80257CDC;
    case 0x80257CE0u: goto label_80257CE0;
    case 0x80257CE4u: goto label_80257CE4;
    case 0x80257CE8u: goto label_80257CE8;
    case 0x80257CECu: goto label_80257CEC;
    case 0x80257CF0u: goto label_80257CF0;
    case 0x80257CF4u: goto label_80257CF4;
    case 0x80257CF8u: goto label_80257CF8;
    case 0x80257CFCu: goto label_80257CFC;
    case 0x80257D00u: goto label_80257D00;
    case 0x80257D04u: goto label_80257D04;
    case 0x80257D08u: goto label_80257D08;
    case 0x80257D0Cu: goto label_80257D0C;
    case 0x80257D10u: goto label_80257D10;
    case 0x80257D14u: goto label_80257D14;
    case 0x80257D18u: goto label_80257D18;
    case 0x80257D1Cu: goto label_80257D1C;
    case 0x80257D20u: goto label_80257D20;
    case 0x80257D24u: goto label_80257D24;
    case 0x80257D28u: goto label_80257D28;
    case 0x80257D2Cu: goto label_80257D2C;
    case 0x80257D30u: goto label_80257D30;
    case 0x80257D34u: goto label_80257D34;
    case 0x80257D38u: goto label_80257D38;
    case 0x80257D3Cu: goto label_80257D3C;
    case 0x80257D40u: goto label_80257D40;
    case 0x80257D44u: goto label_80257D44;
    case 0x80257D48u: goto label_80257D48;
    case 0x80257D4Cu: goto label_80257D4C;
    case 0x80257D50u: goto label_80257D50;
    case 0x80257D54u: goto label_80257D54;
    case 0x80257D58u: goto label_80257D58;
    case 0x80257D5Cu: goto label_80257D5C;
    case 0x80257D60u: goto label_80257D60;
    case 0x80257D64u: goto label_80257D64;
    case 0x80257D68u: goto label_80257D68;
    case 0x80257D6Cu: goto label_80257D6C;
    case 0x80257D70u: goto label_80257D70;
    case 0x80257D74u: goto label_80257D74;
    case 0x80257D78u: goto label_80257D78;
    case 0x80257D7Cu: goto label_80257D7C;
    case 0x80257D80u: goto label_80257D80;
    case 0x80257D84u: goto label_80257D84;
    case 0x80257D88u: goto label_80257D88;
    case 0x80257D8Cu: goto label_80257D8C;
    case 0x80257D90u: goto label_80257D90;
    case 0x80257D94u: goto label_80257D94;
    case 0x80257D98u: goto label_80257D98;
    case 0x80257D9Cu: goto label_80257D9C;
    case 0x80257DA0u: goto label_80257DA0;
    case 0x80257DA4u: goto label_80257DA4;
    case 0x80257DA8u: goto label_80257DA8;
    case 0x80257DACu: goto label_80257DAC;
    case 0x80257DB0u: goto label_80257DB0;
    case 0x80257DB4u: goto label_80257DB4;
    case 0x80257DB8u: goto label_80257DB8;
    case 0x80257DBCu: goto label_80257DBC;
    case 0x80257DC0u: goto label_80257DC0;
    case 0x80257DC4u: goto label_80257DC4;
    case 0x80257DC8u: goto label_80257DC8;
    case 0x80257DCCu: goto label_80257DCC;
    case 0x80257DD0u: goto label_80257DD0;
    case 0x80257DD4u: goto label_80257DD4;
    case 0x80257DD8u: goto label_80257DD8;
    case 0x80257DDCu: goto label_80257DDC;
    case 0x80257DE0u: goto label_80257DE0;
    case 0x80257DE4u: goto label_80257DE4;
    case 0x80257DE8u: goto label_80257DE8;
    case 0x80257DECu: goto label_80257DEC;
    case 0x80257DF0u: goto label_80257DF0;
    case 0x80257DF4u: goto label_80257DF4;
    case 0x80257DF8u: goto label_80257DF8;
    case 0x80257DFCu: goto label_80257DFC;
    case 0x80257E00u: goto label_80257E00;
    case 0x80257E04u: goto label_80257E04;
    case 0x80257E08u: goto label_80257E08;
    case 0x80257E0Cu: goto label_80257E0C;
    case 0x80257E10u: goto label_80257E10;
    case 0x80257E14u: goto label_80257E14;
    case 0x80257E18u: goto label_80257E18;
    case 0x80257E1Cu: goto label_80257E1C;
    case 0x80257E20u: goto label_80257E20;
    case 0x80257E24u: goto label_80257E24;
    case 0x80257E28u: goto label_80257E28;
    case 0x80257E2Cu: goto label_80257E2C;
    case 0x80257E30u: goto label_80257E30;
    case 0x80257E34u: goto label_80257E34;
    case 0x80257E38u: goto label_80257E38;
    case 0x80257E3Cu: goto label_80257E3C;
    case 0x80257E40u: goto label_80257E40;
    case 0x80257E44u: goto label_80257E44;
    case 0x80257E48u: goto label_80257E48;
    case 0x80257E4Cu: goto label_80257E4C;
    case 0x80257E50u: goto label_80257E50;
    case 0x80257E54u: goto label_80257E54;
    case 0x80257E58u: goto label_80257E58;
    case 0x80257E5Cu: goto label_80257E5C;
    case 0x80257E60u: goto label_80257E60;
    case 0x80257E64u: goto label_80257E64;
    case 0x80257E68u: goto label_80257E68;
    case 0x80257E6Cu: goto label_80257E6C;
    case 0x80257E70u: goto label_80257E70;
    case 0x80257E74u: goto label_80257E74;
    case 0x80257E78u: goto label_80257E78;
    case 0x80257E7Cu: goto label_80257E7C;
    case 0x80257E80u: goto label_80257E80;
    case 0x80257E84u: goto label_80257E84;
    case 0x80257E88u: goto label_80257E88;
    case 0x80257E8Cu: goto label_80257E8C;
    case 0x80257E90u: goto label_80257E90;
    case 0x80257E94u: goto label_80257E94;
    case 0x80257E98u: goto label_80257E98;
    case 0x80257E9Cu: goto label_80257E9C;
    case 0x80257EA0u: goto label_80257EA0;
    case 0x80257EA4u: goto label_80257EA4;
    case 0x80257EA8u: goto label_80257EA8;
    case 0x80257EACu: goto label_80257EAC;
    case 0x80257EB0u: goto label_80257EB0;
    case 0x80257EB4u: goto label_80257EB4;
    case 0x80257EB8u: goto label_80257EB8;
    case 0x80257EBCu: goto label_80257EBC;
    case 0x80257EC0u: goto label_80257EC0;
    case 0x80257EC4u: goto label_80257EC4;
    case 0x80257EC8u: goto label_80257EC8;
    case 0x80257ECCu: goto label_80257ECC;
    case 0x80257ED0u: goto label_80257ED0;
    case 0x80257ED4u: goto label_80257ED4;
    case 0x80257ED8u: goto label_80257ED8;
    case 0x80257EDCu: goto label_80257EDC;
    case 0x80257EE0u: goto label_80257EE0;
    case 0x80257EE4u: goto label_80257EE4;
    case 0x80257EE8u: goto label_80257EE8;
    case 0x80257EECu: goto label_80257EEC;
    case 0x80257EF0u: goto label_80257EF0;
    case 0x80257EF4u: goto label_80257EF4;
    case 0x80257EF8u: goto label_80257EF8;
    case 0x80257EFCu: goto label_80257EFC;
    case 0x80257F00u: goto label_80257F00;
    case 0x80257F04u: goto label_80257F04;
    case 0x80257F08u: goto label_80257F08;
    case 0x80257F0Cu: goto label_80257F0C;
    case 0x80257F10u: goto label_80257F10;
    case 0x80257F14u: goto label_80257F14;
    case 0x80257F18u: goto label_80257F18;
    case 0x80257F1Cu: goto label_80257F1C;
    case 0x80257F20u: goto label_80257F20;
    case 0x80257F24u: goto label_80257F24;
    case 0x80257F28u: goto label_80257F28;
    case 0x80257F2Cu: goto label_80257F2C;
    case 0x80257F30u: goto label_80257F30;
    case 0x80257F34u: goto label_80257F34;
    case 0x80257F38u: goto label_80257F38;
    case 0x80257F3Cu: goto label_80257F3C;
    case 0x80257F40u: goto label_80257F40;
    case 0x80257F44u: goto label_80257F44;
    case 0x80257F48u: goto label_80257F48;
    case 0x80257F4Cu: goto label_80257F4C;
    case 0x80257F50u: goto label_80257F50;
    case 0x80257F54u: goto label_80257F54;
    case 0x80257F58u: goto label_80257F58;
    case 0x80257F5Cu: goto label_80257F5C;
    case 0x80257F60u: goto label_80257F60;
    case 0x80257F64u: goto label_80257F64;
    case 0x80257F68u: goto label_80257F68;
    case 0x80257F6Cu: goto label_80257F6C;
    case 0x80257F70u: goto label_80257F70;
    case 0x80257F74u: goto label_80257F74;
    case 0x80257F78u: goto label_80257F78;
    case 0x80257F7Cu: goto label_80257F7C;
    case 0x80257F80u: goto label_80257F80;
    case 0x80257F84u: goto label_80257F84;
    case 0x80257F88u: goto label_80257F88;
    case 0x80257F8Cu: goto label_80257F8C;
    case 0x80257F90u: goto label_80257F90;
    case 0x80257F94u: goto label_80257F94;
    case 0x80257F98u: goto label_80257F98;
    case 0x80257F9Cu: goto label_80257F9C;
    case 0x80257FA0u: goto label_80257FA0;
    case 0x80257FA4u: goto label_80257FA4;
    case 0x80257FA8u: goto label_80257FA8;
    case 0x80257FACu: goto label_80257FAC;
    case 0x80257FB0u: goto label_80257FB0;
    case 0x80257FB4u: goto label_80257FB4;
    case 0x80257FB8u: goto label_80257FB8;
    case 0x80257FBCu: goto label_80257FBC;
    case 0x80257FC0u: goto label_80257FC0;
    case 0x80257FC4u: goto label_80257FC4;
    case 0x80257FC8u: goto label_80257FC8;
    case 0x80257FCCu: goto label_80257FCC;
    case 0x80257FD0u: goto label_80257FD0;
    case 0x80257FD4u: goto label_80257FD4;
    case 0x80257FD8u: goto label_80257FD8;
    case 0x80257FDCu: goto label_80257FDC;
    case 0x80257FE0u: goto label_80257FE0;
    case 0x80257FE4u: goto label_80257FE4;
    case 0x80257FE8u: goto label_80257FE8;
    case 0x80257FECu: goto label_80257FEC;
    case 0x80257FF0u: goto label_80257FF0;
    case 0x80257FF4u: goto label_80257FF4;
    case 0x80257FF8u: goto label_80257FF8;
    case 0x80257FFCu: goto label_80257FFC;
    case 0x80258000u: goto label_80258000;
    case 0x80258004u: goto label_80258004;
    case 0x80258008u: goto label_80258008;
    case 0x8025800Cu: goto label_8025800C;
    case 0x80258010u: goto label_80258010;
    case 0x80258014u: goto label_80258014;
    case 0x80258018u: goto label_80258018;
    case 0x8025801Cu: goto label_8025801C;
    case 0x80258020u: goto label_80258020;
    case 0x80258024u: goto label_80258024;
    case 0x80258028u: goto label_80258028;
    case 0x8025802Cu: goto label_8025802C;
    case 0x80258030u: goto label_80258030;
    case 0x80258034u: goto label_80258034;
    case 0x80258038u: goto label_80258038;
    case 0x8025803Cu: goto label_8025803C;
    case 0x80258040u: goto label_80258040;
    case 0x80258044u: goto label_80258044;
    case 0x80258048u: goto label_80258048;
    case 0x8025804Cu: goto label_8025804C;
    case 0x80258050u: goto label_80258050;
    case 0x80258054u: goto label_80258054;
    case 0x80258058u: goto label_80258058;
    case 0x8025805Cu: goto label_8025805C;
    case 0x80258060u: goto label_80258060;
    case 0x80258064u: goto label_80258064;
    case 0x80258068u: goto label_80258068;
    case 0x8025806Cu: goto label_8025806C;
    case 0x80258070u: goto label_80258070;
    case 0x80258074u: goto label_80258074;
    case 0x80258078u: goto label_80258078;
    case 0x8025807Cu: goto label_8025807C;
    case 0x80258080u: goto label_80258080;
    case 0x80258084u: goto label_80258084;
    case 0x80258088u: goto label_80258088;
    case 0x8025808Cu: goto label_8025808C;
    case 0x80258090u: goto label_80258090;
    case 0x80258094u: goto label_80258094;
    case 0x80258098u: goto label_80258098;
    case 0x8025809Cu: goto label_8025809C;
    case 0x802580A0u: goto label_802580A0;
    case 0x802580A4u: goto label_802580A4;
    case 0x802580A8u: goto label_802580A8;
    case 0x802580ACu: goto label_802580AC;
    case 0x802580B0u: goto label_802580B0;
    case 0x802580B4u: goto label_802580B4;
    case 0x802580B8u: goto label_802580B8;
    case 0x802580BCu: goto label_802580BC;
    case 0x802580C0u: goto label_802580C0;
    case 0x802580C4u: goto label_802580C4;
    case 0x802580C8u: goto label_802580C8;
    case 0x802580CCu: goto label_802580CC;
    case 0x802580D0u: goto label_802580D0;
    case 0x802580D4u: goto label_802580D4;
    case 0x802580D8u: goto label_802580D8;
    case 0x802580DCu: goto label_802580DC;
    case 0x802580E0u: goto label_802580E0;
    case 0x802580E4u: goto label_802580E4;
    case 0x802580E8u: goto label_802580E8;
    case 0x802580ECu: goto label_802580EC;
    case 0x802580F0u: goto label_802580F0;
    case 0x802580F4u: goto label_802580F4;
    case 0x802580F8u: goto label_802580F8;
    case 0x802580FCu: goto label_802580FC;
    case 0x80258100u: goto label_80258100;
    case 0x80258104u: goto label_80258104;
    case 0x80258108u: goto label_80258108;
    case 0x8025810Cu: goto label_8025810C;
    case 0x80258110u: goto label_80258110;
    case 0x80258114u: goto label_80258114;
    case 0x80258118u: goto label_80258118;
    case 0x8025811Cu: goto label_8025811C;
    case 0x80258120u: goto label_80258120;
    case 0x80258124u: goto label_80258124;
    case 0x80258128u: goto label_80258128;
    case 0x8025812Cu: goto label_8025812C;
    case 0x80258130u: goto label_80258130;
    case 0x80258134u: goto label_80258134;
    case 0x80258138u: goto label_80258138;
    case 0x8025813Cu: goto label_8025813C;
    case 0x80258140u: goto label_80258140;
    case 0x80258144u: goto label_80258144;
    case 0x80258148u: goto label_80258148;
    case 0x8025814Cu: goto label_8025814C;
    case 0x80258150u: goto label_80258150;
    case 0x80258154u: goto label_80258154;
    case 0x80258158u: goto label_80258158;
    case 0x8025815Cu: goto label_8025815C;
    case 0x80258160u: goto label_80258160;
    case 0x80258164u: goto label_80258164;
    case 0x80258168u: goto label_80258168;
    case 0x8025816Cu: goto label_8025816C;
    case 0x80258170u: goto label_80258170;
    case 0x80258174u: goto label_80258174;
    case 0x80258178u: goto label_80258178;
    case 0x8025817Cu: goto label_8025817C;
    case 0x80258180u: goto label_80258180;
    case 0x80258184u: goto label_80258184;
    case 0x80258188u: goto label_80258188;
    case 0x8025818Cu: goto label_8025818C;
    case 0x80258190u: goto label_80258190;
    case 0x80258194u: goto label_80258194;
    case 0x80258198u: goto label_80258198;
    case 0x8025819Cu: goto label_8025819C;
    case 0x802581A0u: goto label_802581A0;
    case 0x802581A4u: goto label_802581A4;
    case 0x802581A8u: goto label_802581A8;
    case 0x802581ACu: goto label_802581AC;
    case 0x802581B0u: goto label_802581B0;
    case 0x802581B4u: goto label_802581B4;
    case 0x802581B8u: goto label_802581B8;
    case 0x802581BCu: goto label_802581BC;
    case 0x802581C0u: goto label_802581C0;
    case 0x802581C4u: goto label_802581C4;
    case 0x802581C8u: goto label_802581C8;
    case 0x802581CCu: goto label_802581CC;
    case 0x802581D0u: goto label_802581D0;
    case 0x802581D4u: goto label_802581D4;
    case 0x802581D8u: goto label_802581D8;
    case 0x802581DCu: goto label_802581DC;
    case 0x802581E0u: goto label_802581E0;
    case 0x802581E4u: goto label_802581E4;
    case 0x802581E8u: goto label_802581E8;
    case 0x802581ECu: goto label_802581EC;
    case 0x802581F0u: goto label_802581F0;
    case 0x802581F4u: goto label_802581F4;
    case 0x802581F8u: goto label_802581F8;
    case 0x802581FCu: goto label_802581FC;
    case 0x80258200u: goto label_80258200;
    case 0x80258204u: goto label_80258204;
    case 0x80258208u: goto label_80258208;
    case 0x8025820Cu: goto label_8025820C;
    case 0x80258210u: goto label_80258210;
    case 0x80258214u: goto label_80258214;
    case 0x80258218u: goto label_80258218;
    case 0x8025821Cu: goto label_8025821C;
    case 0x80258220u: goto label_80258220;
    case 0x80258224u: goto label_80258224;
    case 0x80258228u: goto label_80258228;
    case 0x8025822Cu: goto label_8025822C;
    case 0x80258230u: goto label_80258230;
    case 0x80258234u: goto label_80258234;
    case 0x80258238u: goto label_80258238;
    case 0x8025823Cu: goto label_8025823C;
    case 0x80258240u: goto label_80258240;
    case 0x80258244u: goto label_80258244;
    case 0x80258248u: goto label_80258248;
    case 0x8025824Cu: goto label_8025824C;
    case 0x80258250u: goto label_80258250;
    case 0x80258254u: goto label_80258254;
    case 0x80258258u: goto label_80258258;
    case 0x8025825Cu: goto label_8025825C;
    case 0x80258260u: goto label_80258260;
    case 0x80258264u: goto label_80258264;
    case 0x80258268u: goto label_80258268;
    case 0x8025826Cu: goto label_8025826C;
    case 0x80258270u: goto label_80258270;
    case 0x80258274u: goto label_80258274;
    case 0x80258278u: goto label_80258278;
    case 0x8025827Cu: goto label_8025827C;
    case 0x80258280u: goto label_80258280;
    case 0x80258284u: goto label_80258284;
    case 0x80258288u: goto label_80258288;
    case 0x8025828Cu: goto label_8025828C;
    case 0x80258290u: goto label_80258290;
    case 0x80258294u: goto label_80258294;
    case 0x80258298u: goto label_80258298;
    case 0x8025829Cu: goto label_8025829C;
    case 0x802582A0u: goto label_802582A0;
    case 0x802582A4u: goto label_802582A4;
    case 0x802582A8u: goto label_802582A8;
    case 0x802582ACu: goto label_802582AC;
    case 0x802582B0u: goto label_802582B0;
    case 0x802582B4u: goto label_802582B4;
    case 0x802582B8u: goto label_802582B8;
    case 0x802582BCu: goto label_802582BC;
    case 0x802582C0u: goto label_802582C0;
    case 0x802582C4u: goto label_802582C4;
    case 0x802582C8u: goto label_802582C8;
    case 0x802582CCu: goto label_802582CC;
    case 0x802582D0u: goto label_802582D0;
    case 0x802582D4u: goto label_802582D4;
    case 0x802582D8u: goto label_802582D8;
    case 0x802582DCu: goto label_802582DC;
    case 0x802582E0u: goto label_802582E0;
    case 0x802582E4u: goto label_802582E4;
    case 0x802582E8u: goto label_802582E8;
    case 0x802582ECu: goto label_802582EC;
    case 0x802582F0u: goto label_802582F0;
    case 0x802582F4u: goto label_802582F4;
    case 0x802582F8u: goto label_802582F8;
    case 0x802582FCu: goto label_802582FC;
    case 0x80258300u: goto label_80258300;
    case 0x80258304u: goto label_80258304;
    case 0x80258308u: goto label_80258308;
    case 0x8025830Cu: goto label_8025830C;
    case 0x80258310u: goto label_80258310;
    case 0x80258314u: goto label_80258314;
    case 0x80258318u: goto label_80258318;
    case 0x8025831Cu: goto label_8025831C;
    case 0x80258320u: goto label_80258320;
    case 0x80258324u: goto label_80258324;
    case 0x80258328u: goto label_80258328;
    case 0x8025832Cu: goto label_8025832C;
    case 0x80258330u: goto label_80258330;
    case 0x80258334u: goto label_80258334;
    case 0x80258338u: goto label_80258338;
    case 0x8025833Cu: goto label_8025833C;
    case 0x80258340u: goto label_80258340;
    case 0x80258344u: goto label_80258344;
    case 0x80258348u: goto label_80258348;
    case 0x8025834Cu: goto label_8025834C;
    case 0x80258350u: goto label_80258350;
    case 0x80258354u: goto label_80258354;
    case 0x80258358u: goto label_80258358;
    case 0x8025835Cu: goto label_8025835C;
    case 0x80258360u: goto label_80258360;
    case 0x80258364u: goto label_80258364;
    case 0x80258368u: goto label_80258368;
    case 0x8025836Cu: goto label_8025836C;
    case 0x80258370u: goto label_80258370;
    case 0x80258374u: goto label_80258374;
    case 0x80258378u: goto label_80258378;
    case 0x8025837Cu: goto label_8025837C;
    case 0x80258380u: goto label_80258380;
    case 0x80258384u: goto label_80258384;
    case 0x80258388u: goto label_80258388;
    case 0x8025838Cu: goto label_8025838C;
    case 0x80258390u: goto label_80258390;
    case 0x80258394u: goto label_80258394;
    case 0x80258398u: goto label_80258398;
    case 0x8025839Cu: goto label_8025839C;
    case 0x802583A0u: goto label_802583A0;
    case 0x802583A4u: goto label_802583A4;
    case 0x802583A8u: goto label_802583A8;
    case 0x802583ACu: goto label_802583AC;
    case 0x802583B0u: goto label_802583B0;
    case 0x802583B4u: goto label_802583B4;
    case 0x802583B8u: goto label_802583B8;
    case 0x802583BCu: goto label_802583BC;
    case 0x802583C0u: goto label_802583C0;
    case 0x802583C4u: goto label_802583C4;
    case 0x802583C8u: goto label_802583C8;
    case 0x802583CCu: goto label_802583CC;
    case 0x802583D0u: goto label_802583D0;
    case 0x802583D4u: goto label_802583D4;
    case 0x802583D8u: goto label_802583D8;
    case 0x802583DCu: goto label_802583DC;
    case 0x802583E0u: goto label_802583E0;
    case 0x802583E4u: goto label_802583E4;
    case 0x802583E8u: goto label_802583E8;
    case 0x802583ECu: goto label_802583EC;
    case 0x802583F0u: goto label_802583F0;
    case 0x802583F4u: goto label_802583F4;
    case 0x802583F8u: goto label_802583F8;
    case 0x802583FCu: goto label_802583FC;
    case 0x80258400u: goto label_80258400;
    case 0x80258404u: goto label_80258404;
    case 0x80258408u: goto label_80258408;
    case 0x8025840Cu: goto label_8025840C;
    case 0x80258410u: goto label_80258410;
    case 0x80258414u: goto label_80258414;
    case 0x80258418u: goto label_80258418;
    case 0x8025841Cu: goto label_8025841C;
    case 0x80258420u: goto label_80258420;
    case 0x80258424u: goto label_80258424;
    case 0x80258428u: goto label_80258428;
    case 0x8025842Cu: goto label_8025842C;
    case 0x80258430u: goto label_80258430;
    case 0x80258434u: goto label_80258434;
    case 0x80258438u: goto label_80258438;
    case 0x8025843Cu: goto label_8025843C;
    case 0x80258440u: goto label_80258440;
    case 0x80258444u: goto label_80258444;
    case 0x80258448u: goto label_80258448;
    case 0x8025844Cu: goto label_8025844C;
    case 0x80258450u: goto label_80258450;
    case 0x80258454u: goto label_80258454;
    case 0x80258458u: goto label_80258458;
    case 0x8025845Cu: goto label_8025845C;
    case 0x80258460u: goto label_80258460;
    case 0x80258464u: goto label_80258464;
    case 0x80258468u: goto label_80258468;
    case 0x8025846Cu: goto label_8025846C;
    case 0x80258470u: goto label_80258470;
    case 0x80258474u: goto label_80258474;
    case 0x80258478u: goto label_80258478;
    case 0x8025847Cu: goto label_8025847C;
    case 0x80258480u: goto label_80258480;
    case 0x80258484u: goto label_80258484;
    case 0x80258488u: goto label_80258488;
    case 0x8025848Cu: goto label_8025848C;
    case 0x80258490u: goto label_80258490;
    case 0x80258494u: goto label_80258494;
    case 0x80258498u: goto label_80258498;
    case 0x8025849Cu: goto label_8025849C;
    case 0x802584A0u: goto label_802584A0;
    case 0x802584A4u: goto label_802584A4;
    case 0x802584A8u: goto label_802584A8;
    case 0x802584ACu: goto label_802584AC;
    case 0x802584B0u: goto label_802584B0;
    case 0x802584B4u: goto label_802584B4;
    case 0x802584B8u: goto label_802584B8;
    case 0x802584BCu: goto label_802584BC;
    case 0x802584C0u: goto label_802584C0;
    case 0x802584C4u: goto label_802584C4;
    case 0x802584C8u: goto label_802584C8;
    case 0x802584CCu: goto label_802584CC;
    case 0x802584D0u: goto label_802584D0;
    case 0x802584D4u: goto label_802584D4;
    case 0x802584D8u: goto label_802584D8;
    case 0x802584DCu: goto label_802584DC;
    case 0x802584E0u: goto label_802584E0;
    case 0x802584E4u: goto label_802584E4;
    case 0x802584E8u: goto label_802584E8;
    case 0x802584ECu: goto label_802584EC;
    case 0x802584F0u: goto label_802584F0;
    case 0x802584F4u: goto label_802584F4;
    case 0x802584F8u: goto label_802584F8;
    case 0x802584FCu: goto label_802584FC;
    case 0x80258500u: goto label_80258500;
    case 0x80258504u: goto label_80258504;
    case 0x80258508u: goto label_80258508;
    case 0x8025850Cu: goto label_8025850C;
    case 0x80258510u: goto label_80258510;
    case 0x80258514u: goto label_80258514;
    case 0x80258518u: goto label_80258518;
    case 0x8025851Cu: goto label_8025851C;
    case 0x80258520u: goto label_80258520;
    case 0x80258524u: goto label_80258524;
    case 0x80258528u: goto label_80258528;
    case 0x8025852Cu: goto label_8025852C;
    case 0x80258530u: goto label_80258530;
    case 0x80258534u: goto label_80258534;
    case 0x80258538u: goto label_80258538;
    case 0x8025853Cu: goto label_8025853C;
    case 0x80258540u: goto label_80258540;
    case 0x80258544u: goto label_80258544;
    case 0x80258548u: goto label_80258548;
    case 0x8025854Cu: goto label_8025854C;
    case 0x80258550u: goto label_80258550;
    case 0x80258554u: goto label_80258554;
    case 0x80258558u: goto label_80258558;
    case 0x8025855Cu: goto label_8025855C;
    case 0x80258560u: goto label_80258560;
    case 0x80258564u: goto label_80258564;
    case 0x80258568u: goto label_80258568;
    case 0x8025856Cu: goto label_8025856C;
    case 0x80258570u: goto label_80258570;
    case 0x80258574u: goto label_80258574;
    case 0x80258578u: goto label_80258578;
    case 0x8025857Cu: goto label_8025857C;
    case 0x80258580u: goto label_80258580;
    case 0x80258584u: goto label_80258584;
    case 0x80258588u: goto label_80258588;
    case 0x8025858Cu: goto label_8025858C;
    case 0x80258590u: goto label_80258590;
    case 0x80258594u: goto label_80258594;
    case 0x80258598u: goto label_80258598;
    case 0x8025859Cu: goto label_8025859C;
    case 0x802585A0u: goto label_802585A0;
    case 0x802585A4u: goto label_802585A4;
    case 0x802585A8u: goto label_802585A8;
    case 0x802585ACu: goto label_802585AC;
    case 0x802585B0u: goto label_802585B0;
    case 0x802585B4u: goto label_802585B4;
    case 0x802585B8u: goto label_802585B8;
    case 0x802585BCu: goto label_802585BC;
    case 0x802585C0u: goto label_802585C0;
    case 0x802585C4u: goto label_802585C4;
    case 0x802585C8u: goto label_802585C8;
    case 0x802585CCu: goto label_802585CC;
    case 0x802585D0u: goto label_802585D0;
    case 0x802585D4u: goto label_802585D4;
    case 0x802585D8u: goto label_802585D8;
    case 0x802585DCu: goto label_802585DC;
    case 0x802585E0u: goto label_802585E0;
    case 0x802585E4u: goto label_802585E4;
    case 0x802585E8u: goto label_802585E8;
    case 0x802585ECu: goto label_802585EC;
    case 0x802585F0u: goto label_802585F0;
    case 0x802585F4u: goto label_802585F4;
    case 0x802585F8u: goto label_802585F8;
    case 0x802585FCu: goto label_802585FC;
    case 0x80258600u: goto label_80258600;
    case 0x80258604u: goto label_80258604;
    case 0x80258608u: goto label_80258608;
    case 0x8025860Cu: goto label_8025860C;
    case 0x80258610u: goto label_80258610;
    case 0x80258614u: goto label_80258614;
    case 0x80258618u: goto label_80258618;
    case 0x8025861Cu: goto label_8025861C;
    case 0x80258620u: goto label_80258620;
    case 0x80258624u: goto label_80258624;
    case 0x80258628u: goto label_80258628;
    case 0x8025862Cu: goto label_8025862C;
    case 0x80258630u: goto label_80258630;
    case 0x80258634u: goto label_80258634;
    case 0x80258638u: goto label_80258638;
    case 0x8025863Cu: goto label_8025863C;
    case 0x80258640u: goto label_80258640;
    case 0x80258644u: goto label_80258644;
    case 0x80258648u: goto label_80258648;
    case 0x8025864Cu: goto label_8025864C;
    case 0x80258650u: goto label_80258650;
    case 0x80258654u: goto label_80258654;
    case 0x80258658u: goto label_80258658;
    case 0x8025865Cu: goto label_8025865C;
    case 0x80258660u: goto label_80258660;
    case 0x80258664u: goto label_80258664;
    case 0x80258668u: goto label_80258668;
    case 0x8025866Cu: goto label_8025866C;
    case 0x80258670u: goto label_80258670;
    case 0x80258674u: goto label_80258674;
    case 0x80258678u: goto label_80258678;
    case 0x8025867Cu: goto label_8025867C;
    case 0x80258680u: goto label_80258680;
    case 0x80258684u: goto label_80258684;
    case 0x80258688u: goto label_80258688;
    case 0x8025868Cu: goto label_8025868C;
    case 0x80258690u: goto label_80258690;
    case 0x80258694u: goto label_80258694;
    case 0x80258698u: goto label_80258698;
    case 0x8025869Cu: goto label_8025869C;
    case 0x802586A0u: goto label_802586A0;
    case 0x802586A4u: goto label_802586A4;
    case 0x802586A8u: goto label_802586A8;
    case 0x802586ACu: goto label_802586AC;
    case 0x802586B0u: goto label_802586B0;
    case 0x802586B4u: goto label_802586B4;
    case 0x802586B8u: goto label_802586B8;
    case 0x802586BCu: goto label_802586BC;
    case 0x802586C0u: goto label_802586C0;
    case 0x802586C4u: goto label_802586C4;
    case 0x802586C8u: goto label_802586C8;
    case 0x802586CCu: goto label_802586CC;
    case 0x802586D0u: goto label_802586D0;
    case 0x802586D4u: goto label_802586D4;
    case 0x802586D8u: goto label_802586D8;
    case 0x802586DCu: goto label_802586DC;
    case 0x802586E0u: goto label_802586E0;
    case 0x802586E4u: goto label_802586E4;
    case 0x802586E8u: goto label_802586E8;
    case 0x802586ECu: goto label_802586EC;
    case 0x802586F0u: goto label_802586F0;
    case 0x802586F4u: goto label_802586F4;
    case 0x802586F8u: goto label_802586F8;
    case 0x802586FCu: goto label_802586FC;
    case 0x80258700u: goto label_80258700;
    case 0x80258704u: goto label_80258704;
    case 0x80258708u: goto label_80258708;
    case 0x8025870Cu: goto label_8025870C;
    case 0x80258710u: goto label_80258710;
    case 0x80258714u: goto label_80258714;
    case 0x80258718u: goto label_80258718;
    case 0x8025871Cu: goto label_8025871C;
    case 0x80258720u: goto label_80258720;
    case 0x80258724u: goto label_80258724;
    case 0x80258728u: goto label_80258728;
    case 0x8025872Cu: goto label_8025872C;
    case 0x80258730u: goto label_80258730;
    case 0x80258734u: goto label_80258734;
    case 0x80258738u: goto label_80258738;
    case 0x8025873Cu: goto label_8025873C;
    case 0x80258740u: goto label_80258740;
    case 0x80258744u: goto label_80258744;
    case 0x80258748u: goto label_80258748;
    case 0x8025874Cu: goto label_8025874C;
    case 0x80258750u: goto label_80258750;
    case 0x80258754u: goto label_80258754;
    case 0x80258758u: goto label_80258758;
    case 0x8025875Cu: goto label_8025875C;
    case 0x80258760u: goto label_80258760;
    case 0x80258764u: goto label_80258764;
    case 0x80258768u: goto label_80258768;
    case 0x8025876Cu: goto label_8025876C;
    case 0x80258770u: goto label_80258770;
    case 0x80258774u: goto label_80258774;
    case 0x80258778u: goto label_80258778;
    case 0x8025877Cu: goto label_8025877C;
    case 0x80258780u: goto label_80258780;
    case 0x80258784u: goto label_80258784;
    case 0x80258788u: goto label_80258788;
    case 0x8025878Cu: goto label_8025878C;
    case 0x80258790u: goto label_80258790;
    case 0x80258794u: goto label_80258794;
    case 0x80258798u: goto label_80258798;
    case 0x8025879Cu: goto label_8025879C;
    case 0x802587A0u: goto label_802587A0;
    case 0x802587A4u: goto label_802587A4;
    case 0x802587A8u: goto label_802587A8;
    case 0x802587ACu: goto label_802587AC;
    case 0x802587B0u: goto label_802587B0;
    case 0x802587B4u: goto label_802587B4;
    case 0x802587B8u: goto label_802587B8;
    case 0x802587BCu: goto label_802587BC;
    case 0x802587C0u: goto label_802587C0;
    case 0x802587C4u: goto label_802587C4;
    case 0x802587C8u: goto label_802587C8;
    case 0x802587CCu: goto label_802587CC;
    case 0x802587D0u: goto label_802587D0;
    case 0x802587D4u: goto label_802587D4;
    case 0x802587D8u: goto label_802587D8;
    case 0x802587DCu: goto label_802587DC;
    case 0x802587E0u: goto label_802587E0;
    case 0x802587E4u: goto label_802587E4;
    case 0x802587E8u: goto label_802587E8;
    case 0x802587ECu: goto label_802587EC;
    case 0x802587F0u: goto label_802587F0;
    case 0x802587F4u: goto label_802587F4;
    case 0x802587F8u: goto label_802587F8;
    case 0x802587FCu: goto label_802587FC;
    case 0x80258800u: goto label_80258800;
    case 0x80258804u: goto label_80258804;
    case 0x80258808u: goto label_80258808;
    case 0x8025880Cu: goto label_8025880C;
    case 0x80258810u: goto label_80258810;
    case 0x80258814u: goto label_80258814;
    case 0x80258818u: goto label_80258818;
    case 0x8025881Cu: goto label_8025881C;
    case 0x80258820u: goto label_80258820;
    case 0x80258824u: goto label_80258824;
    case 0x80258828u: goto label_80258828;
    case 0x8025882Cu: goto label_8025882C;
    case 0x80258830u: goto label_80258830;
    case 0x80258834u: goto label_80258834;
    case 0x80258838u: goto label_80258838;
    case 0x8025883Cu: goto label_8025883C;
    case 0x80258840u: goto label_80258840;
    case 0x80258844u: goto label_80258844;
    case 0x80258848u: goto label_80258848;
    case 0x8025884Cu: goto label_8025884C;
    case 0x80258850u: goto label_80258850;
    case 0x80258854u: goto label_80258854;
    case 0x80258858u: goto label_80258858;
    case 0x8025885Cu: goto label_8025885C;
    case 0x80258860u: goto label_80258860;
    case 0x80258864u: goto label_80258864;
    case 0x80258868u: goto label_80258868;
    case 0x8025886Cu: goto label_8025886C;
    case 0x80258870u: goto label_80258870;
    case 0x80258874u: goto label_80258874;
    case 0x80258878u: goto label_80258878;
    case 0x8025887Cu: goto label_8025887C;
    case 0x80258880u: goto label_80258880;
    case 0x80258884u: goto label_80258884;
    case 0x80258888u: goto label_80258888;
    case 0x8025888Cu: goto label_8025888C;
    case 0x80258890u: goto label_80258890;
    case 0x80258894u: goto label_80258894;
    case 0x80258898u: goto label_80258898;
    case 0x8025889Cu: goto label_8025889C;
    case 0x802588A0u: goto label_802588A0;
    case 0x802588A4u: goto label_802588A4;
    case 0x802588A8u: goto label_802588A8;
    case 0x802588ACu: goto label_802588AC;
    case 0x802588B0u: goto label_802588B0;
    case 0x802588B4u: goto label_802588B4;
    case 0x802588B8u: goto label_802588B8;
    case 0x802588BCu: goto label_802588BC;
    case 0x802588C0u: goto label_802588C0;
    case 0x802588C4u: goto label_802588C4;
    case 0x802588C8u: goto label_802588C8;
    case 0x802588CCu: goto label_802588CC;
    case 0x802588D0u: goto label_802588D0;
    case 0x802588D4u: goto label_802588D4;
    case 0x802588D8u: goto label_802588D8;
    case 0x802588DCu: goto label_802588DC;
    case 0x802588E0u: goto label_802588E0;
    case 0x802588E4u: goto label_802588E4;
    case 0x802588E8u: goto label_802588E8;
    case 0x802588ECu: goto label_802588EC;
    case 0x802588F0u: goto label_802588F0;
    case 0x802588F4u: goto label_802588F4;
    case 0x802588F8u: goto label_802588F8;
    case 0x802588FCu: goto label_802588FC;
    case 0x80258900u: goto label_80258900;
    case 0x80258904u: goto label_80258904;
    case 0x80258908u: goto label_80258908;
    case 0x8025890Cu: goto label_8025890C;
    case 0x80258910u: goto label_80258910;
    case 0x80258914u: goto label_80258914;
    case 0x80258918u: goto label_80258918;
    case 0x8025891Cu: goto label_8025891C;
    case 0x80258920u: goto label_80258920;
    case 0x80258924u: goto label_80258924;
    case 0x80258928u: goto label_80258928;
    case 0x8025892Cu: goto label_8025892C;
    case 0x80258930u: goto label_80258930;
    case 0x80258934u: goto label_80258934;
    case 0x80258938u: goto label_80258938;
    case 0x8025893Cu: goto label_8025893C;
    case 0x80258940u: goto label_80258940;
    case 0x80258944u: goto label_80258944;
    case 0x80258948u: goto label_80258948;
    case 0x8025894Cu: goto label_8025894C;
    case 0x80258950u: goto label_80258950;
    case 0x80258954u: goto label_80258954;
    case 0x80258958u: goto label_80258958;
    case 0x8025895Cu: goto label_8025895C;
    case 0x80258960u: goto label_80258960;
    case 0x80258964u: goto label_80258964;
    case 0x80258968u: goto label_80258968;
    case 0x8025896Cu: goto label_8025896C;
    case 0x80258970u: goto label_80258970;
    case 0x80258974u: goto label_80258974;
    case 0x80258978u: goto label_80258978;
    case 0x8025897Cu: goto label_8025897C;
    case 0x80258980u: goto label_80258980;
    case 0x80258984u: goto label_80258984;
    case 0x80258988u: goto label_80258988;
    case 0x8025898Cu: goto label_8025898C;
    case 0x80258990u: goto label_80258990;
    case 0x80258994u: goto label_80258994;
    case 0x80258998u: goto label_80258998;
    case 0x8025899Cu: goto label_8025899C;
    case 0x802589A0u: goto label_802589A0;
    case 0x802589A4u: goto label_802589A4;
    case 0x802589A8u: goto label_802589A8;
    case 0x802589ACu: goto label_802589AC;
    case 0x802589B0u: goto label_802589B0;
    case 0x802589B4u: goto label_802589B4;
    case 0x802589B8u: goto label_802589B8;
    case 0x802589BCu: goto label_802589BC;
    case 0x802589C0u: goto label_802589C0;
    case 0x802589C4u: goto label_802589C4;
    case 0x802589C8u: goto label_802589C8;
    case 0x802589CCu: goto label_802589CC;
    case 0x802589D0u: goto label_802589D0;
    case 0x802589D4u: goto label_802589D4;
    case 0x802589D8u: goto label_802589D8;
    case 0x802589DCu: goto label_802589DC;
    case 0x802589E0u: goto label_802589E0;
    case 0x802589E4u: goto label_802589E4;
    case 0x802589E8u: goto label_802589E8;
    case 0x802589ECu: goto label_802589EC;
    case 0x802589F0u: goto label_802589F0;
    case 0x802589F4u: goto label_802589F4;
    case 0x802589F8u: goto label_802589F8;
    case 0x802589FCu: goto label_802589FC;
    case 0x80258A00u: goto label_80258A00;
    case 0x80258A04u: goto label_80258A04;
    case 0x80258A08u: goto label_80258A08;
    case 0x80258A0Cu: goto label_80258A0C;
    case 0x80258A10u: goto label_80258A10;
    case 0x80258A14u: goto label_80258A14;
    case 0x80258A18u: goto label_80258A18;
    case 0x80258A1Cu: goto label_80258A1C;
    case 0x80258A20u: goto label_80258A20;
    case 0x80258A24u: goto label_80258A24;
    case 0x80258A28u: goto label_80258A28;
    case 0x80258A2Cu: goto label_80258A2C;
    case 0x80258A30u: goto label_80258A30;
    case 0x80258A34u: goto label_80258A34;
    case 0x80258A38u: goto label_80258A38;
    case 0x80258A3Cu: goto label_80258A3C;
    case 0x80258A40u: goto label_80258A40;
    case 0x80258A44u: goto label_80258A44;
    case 0x80258A48u: goto label_80258A48;
    case 0x80258A4Cu: goto label_80258A4C;
    case 0x80258A50u: goto label_80258A50;
    case 0x80258A54u: goto label_80258A54;
    case 0x80258A58u: goto label_80258A58;
    case 0x80258A5Cu: goto label_80258A5C;
    case 0x80258A60u: goto label_80258A60;
    case 0x80258A64u: goto label_80258A64;
    case 0x80258A68u: goto label_80258A68;
    case 0x80258A6Cu: goto label_80258A6C;
    case 0x80258A70u: goto label_80258A70;
    case 0x80258A74u: goto label_80258A74;
    case 0x80258A78u: goto label_80258A78;
    case 0x80258A7Cu: goto label_80258A7C;
    case 0x80258A80u: goto label_80258A80;
    case 0x80258A84u: goto label_80258A84;
    case 0x80258A88u: goto label_80258A88;
    case 0x80258A8Cu: goto label_80258A8C;
    case 0x80258A90u: goto label_80258A90;
    case 0x80258A94u: goto label_80258A94;
    case 0x80258A98u: goto label_80258A98;
    case 0x80258A9Cu: goto label_80258A9C;
    case 0x80258AA0u: goto label_80258AA0;
    case 0x80258AA4u: goto label_80258AA4;
    case 0x80258AA8u: goto label_80258AA8;
    case 0x80258AACu: goto label_80258AAC;
    case 0x80258AB0u: goto label_80258AB0;
    case 0x80258AB4u: goto label_80258AB4;
    case 0x80258AB8u: goto label_80258AB8;
    case 0x80258ABCu: goto label_80258ABC;
    case 0x80258AC0u: goto label_80258AC0;
    case 0x80258AC4u: goto label_80258AC4;
    case 0x80258AC8u: goto label_80258AC8;
    case 0x80258ACCu: goto label_80258ACC;
    case 0x80258AD0u: goto label_80258AD0;
    case 0x80258AD4u: goto label_80258AD4;
    case 0x80258AD8u: goto label_80258AD8;
    case 0x80258ADCu: goto label_80258ADC;
    case 0x80258AE0u: goto label_80258AE0;
    case 0x80258AE4u: goto label_80258AE4;
    case 0x80258AE8u: goto label_80258AE8;
    case 0x80258AECu: goto label_80258AEC;
    case 0x80258AF0u: goto label_80258AF0;
    case 0x80258AF4u: goto label_80258AF4;
    case 0x80258AF8u: goto label_80258AF8;
    case 0x80258AFCu: goto label_80258AFC;
    case 0x80258B00u: goto label_80258B00;
    case 0x80258B04u: goto label_80258B04;
    case 0x80258B08u: goto label_80258B08;
    case 0x80258B0Cu: goto label_80258B0C;
    case 0x80258B10u: goto label_80258B10;
    case 0x80258B14u: goto label_80258B14;
    case 0x80258B18u: goto label_80258B18;
    case 0x80258B1Cu: goto label_80258B1C;
    case 0x80258B20u: goto label_80258B20;
    case 0x80258B24u: goto label_80258B24;
    case 0x80258B28u: goto label_80258B28;
    case 0x80258B2Cu: goto label_80258B2C;
    case 0x80258B30u: goto label_80258B30;
    case 0x80258B34u: goto label_80258B34;
    case 0x80258B38u: goto label_80258B38;
    case 0x80258B3Cu: goto label_80258B3C;
    case 0x80258B40u: goto label_80258B40;
    case 0x80258B44u: goto label_80258B44;
    case 0x80258B48u: goto label_80258B48;
    case 0x80258B4Cu: goto label_80258B4C;
    case 0x80258B50u: goto label_80258B50;
    case 0x80258B54u: goto label_80258B54;
    case 0x80258B58u: goto label_80258B58;
    case 0x80258B5Cu: goto label_80258B5C;
    case 0x80258B60u: goto label_80258B60;
    case 0x80258B64u: goto label_80258B64;
    case 0x80258B68u: goto label_80258B68;
    case 0x80258B6Cu: goto label_80258B6C;
    case 0x80258B70u: goto label_80258B70;
    case 0x80258B74u: goto label_80258B74;
    case 0x80258B78u: goto label_80258B78;
    case 0x80258B7Cu: goto label_80258B7C;
    case 0x80258B80u: goto label_80258B80;
    case 0x80258B84u: goto label_80258B84;
    case 0x80258B88u: goto label_80258B88;
    case 0x80258B8Cu: goto label_80258B8C;
    case 0x80258B90u: goto label_80258B90;
    case 0x80258B94u: goto label_80258B94;
    case 0x80258B98u: goto label_80258B98;
    case 0x80258B9Cu: goto label_80258B9C;
    case 0x80258BA0u: goto label_80258BA0;
    case 0x80258BA4u: goto label_80258BA4;
    case 0x80258BA8u: goto label_80258BA8;
    case 0x80258BACu: goto label_80258BAC;
    case 0x80258BB0u: goto label_80258BB0;
    case 0x80258BB4u: goto label_80258BB4;
    case 0x80258BB8u: goto label_80258BB8;
    case 0x80258BBCu: goto label_80258BBC;
    case 0x80258BC0u: goto label_80258BC0;
    case 0x80258BC4u: goto label_80258BC4;
    case 0x80258BC8u: goto label_80258BC8;
    case 0x80258BCCu: goto label_80258BCC;
    case 0x80258BD0u: goto label_80258BD0;
    case 0x80258BD4u: goto label_80258BD4;
    case 0x80258BD8u: goto label_80258BD8;
    case 0x80258BDCu: goto label_80258BDC;
    case 0x80258BE0u: goto label_80258BE0;
    case 0x80258BE4u: goto label_80258BE4;
    case 0x80258BE8u: goto label_80258BE8;
    case 0x80258BECu: goto label_80258BEC;
    case 0x80258BF0u: goto label_80258BF0;
    case 0x80258BF4u: goto label_80258BF4;
    case 0x80258BF8u: goto label_80258BF8;
    case 0x80258BFCu: goto label_80258BFC;
    case 0x80258C00u: goto label_80258C00;
    case 0x80258C04u: goto label_80258C04;
    case 0x80258C08u: goto label_80258C08;
    case 0x80258C0Cu: goto label_80258C0C;
    case 0x80258C10u: goto label_80258C10;
    case 0x80258C14u: goto label_80258C14;
    case 0x80258C18u: goto label_80258C18;
    case 0x80258C1Cu: goto label_80258C1C;
    case 0x80258C20u: goto label_80258C20;
    case 0x80258C24u: goto label_80258C24;
    case 0x80258C28u: goto label_80258C28;
    case 0x80258C2Cu: goto label_80258C2C;
    case 0x80258C30u: goto label_80258C30;
    case 0x80258C34u: goto label_80258C34;
    case 0x80258C38u: goto label_80258C38;
    case 0x80258C3Cu: goto label_80258C3C;
    case 0x80258C40u: goto label_80258C40;
    case 0x80258C44u: goto label_80258C44;
    case 0x80258C48u: goto label_80258C48;
    case 0x80258C4Cu: goto label_80258C4C;
    case 0x80258C50u: goto label_80258C50;
    case 0x80258C54u: goto label_80258C54;
    case 0x80258C58u: goto label_80258C58;
    case 0x80258C5Cu: goto label_80258C5C;
    case 0x80258C60u: goto label_80258C60;
    case 0x80258C64u: goto label_80258C64;
    case 0x80258C68u: goto label_80258C68;
    case 0x80258C6Cu: goto label_80258C6C;
    case 0x80258C70u: goto label_80258C70;
    case 0x80258C74u: goto label_80258C74;
    case 0x80258C78u: goto label_80258C78;
    case 0x80258C7Cu: goto label_80258C7C;
    case 0x80258C80u: goto label_80258C80;
    case 0x80258C84u: goto label_80258C84;
    case 0x80258C88u: goto label_80258C88;
    case 0x80258C8Cu: goto label_80258C8C;
    case 0x80258C90u: goto label_80258C90;
    case 0x80258C94u: goto label_80258C94;
    case 0x80258C98u: goto label_80258C98;
    case 0x80258C9Cu: goto label_80258C9C;
    case 0x80258CA0u: goto label_80258CA0;
    case 0x80258CA4u: goto label_80258CA4;
    case 0x80258CA8u: goto label_80258CA8;
    case 0x80258CACu: goto label_80258CAC;
    case 0x80258CB0u: goto label_80258CB0;
    case 0x80258CB4u: goto label_80258CB4;
    case 0x80258CB8u: goto label_80258CB8;
    case 0x80258CBCu: goto label_80258CBC;
    case 0x80258CC0u: goto label_80258CC0;
    case 0x80258CC4u: goto label_80258CC4;
    case 0x80258CC8u: goto label_80258CC8;
    case 0x80258CCCu: goto label_80258CCC;
    case 0x80258CD0u: goto label_80258CD0;
    case 0x80258CD4u: goto label_80258CD4;
    case 0x80258CD8u: goto label_80258CD8;
    case 0x80258CDCu: goto label_80258CDC;
    case 0x80258CE0u: goto label_80258CE0;
    case 0x80258CE4u: goto label_80258CE4;
    case 0x80258CE8u: goto label_80258CE8;
    case 0x80258CECu: goto label_80258CEC;
    case 0x80258CF0u: goto label_80258CF0;
    case 0x80258CF4u: goto label_80258CF4;
    case 0x80258CF8u: goto label_80258CF8;
    case 0x80258CFCu: goto label_80258CFC;
    case 0x80258D00u: goto label_80258D00;
    case 0x80258D04u: goto label_80258D04;
    case 0x80258D08u: goto label_80258D08;
    case 0x80258D0Cu: goto label_80258D0C;
    case 0x80258D10u: goto label_80258D10;
    case 0x80258D14u: goto label_80258D14;
    case 0x80258D18u: goto label_80258D18;
    case 0x80258D1Cu: goto label_80258D1C;
    case 0x80258D20u: goto label_80258D20;
    case 0x80258D24u: goto label_80258D24;
    case 0x80258D28u: goto label_80258D28;
    case 0x80258D2Cu: goto label_80258D2C;
    case 0x80258D30u: goto label_80258D30;
    case 0x80258D34u: goto label_80258D34;
    case 0x80258D38u: goto label_80258D38;
    case 0x80258D3Cu: goto label_80258D3C;
    case 0x80258D40u: goto label_80258D40;
    case 0x80258D44u: goto label_80258D44;
    case 0x80258D48u: goto label_80258D48;
    case 0x80258D4Cu: goto label_80258D4C;
    case 0x80258D50u: goto label_80258D50;
    case 0x80258D54u: goto label_80258D54;
    case 0x80258D58u: goto label_80258D58;
    case 0x80258D5Cu: goto label_80258D5C;
    case 0x80258D60u: goto label_80258D60;
    case 0x80258D64u: goto label_80258D64;
    case 0x80258D68u: goto label_80258D68;
    case 0x80258D6Cu: goto label_80258D6C;
    case 0x80258D70u: goto label_80258D70;
    case 0x80258D74u: goto label_80258D74;
    case 0x80258D78u: goto label_80258D78;
    case 0x80258D7Cu: goto label_80258D7C;
    case 0x80258D80u: goto label_80258D80;
    case 0x80258D84u: goto label_80258D84;
    case 0x80258D88u: goto label_80258D88;
    case 0x80258D8Cu: goto label_80258D8C;
    case 0x80258D90u: goto label_80258D90;
    case 0x80258D94u: goto label_80258D94;
    case 0x80258D98u: goto label_80258D98;
    case 0x80258D9Cu: goto label_80258D9C;
    case 0x80258DA0u: goto label_80258DA0;
    case 0x80258DA4u: goto label_80258DA4;
    case 0x80258DA8u: goto label_80258DA8;
    case 0x80258DACu: goto label_80258DAC;
    case 0x80258DB0u: goto label_80258DB0;
    case 0x80258DB4u: goto label_80258DB4;
    case 0x80258DB8u: goto label_80258DB8;
    case 0x80258DBCu: goto label_80258DBC;
    case 0x80258DC0u: goto label_80258DC0;
    case 0x80258DC4u: goto label_80258DC4;
    case 0x80258DC8u: goto label_80258DC8;
    case 0x80258DCCu: goto label_80258DCC;
    case 0x80258DD0u: goto label_80258DD0;
    case 0x80258DD4u: goto label_80258DD4;
    case 0x80258DD8u: goto label_80258DD8;
    case 0x80258DDCu: goto label_80258DDC;
    case 0x80258DE0u: goto label_80258DE0;
    case 0x80258DE4u: goto label_80258DE4;
    case 0x80258DE8u: goto label_80258DE8;
    case 0x80258DECu: goto label_80258DEC;
    case 0x80258DF0u: goto label_80258DF0;
    case 0x80258DF4u: goto label_80258DF4;
    case 0x80258DF8u: goto label_80258DF8;
    case 0x80258DFCu: goto label_80258DFC;
    case 0x80258E00u: goto label_80258E00;
    case 0x80258E04u: goto label_80258E04;
    case 0x80258E08u: goto label_80258E08;
    case 0x80258E0Cu: goto label_80258E0C;
    case 0x80258E10u: goto label_80258E10;
    case 0x80258E14u: goto label_80258E14;
    case 0x80258E18u: goto label_80258E18;
    case 0x80258E1Cu: goto label_80258E1C;
    case 0x80258E20u: goto label_80258E20;
    case 0x80258E24u: goto label_80258E24;
    case 0x80258E28u: goto label_80258E28;
    case 0x80258E2Cu: goto label_80258E2C;
    case 0x80258E30u: goto label_80258E30;
    case 0x80258E34u: goto label_80258E34;
    case 0x80258E38u: goto label_80258E38;
    case 0x80258E3Cu: goto label_80258E3C;
    case 0x80258E40u: goto label_80258E40;
    case 0x80258E44u: goto label_80258E44;
    case 0x80258E48u: goto label_80258E48;
    case 0x80258E4Cu: goto label_80258E4C;
    case 0x80258E50u: goto label_80258E50;
    case 0x80258E54u: goto label_80258E54;
    case 0x80258E58u: goto label_80258E58;
    case 0x80258E5Cu: goto label_80258E5C;
    case 0x80258E60u: goto label_80258E60;
    case 0x80258E64u: goto label_80258E64;
    case 0x80258E68u: goto label_80258E68;
    case 0x80258E6Cu: goto label_80258E6C;
    case 0x80258E70u: goto label_80258E70;
    case 0x80258E74u: goto label_80258E74;
    case 0x80258E78u: goto label_80258E78;
    case 0x80258E7Cu: goto label_80258E7C;
    case 0x80258E80u: goto label_80258E80;
    case 0x80258E84u: goto label_80258E84;
    case 0x80258E88u: goto label_80258E88;
    case 0x80258E8Cu: goto label_80258E8C;
    case 0x80258E90u: goto label_80258E90;
    case 0x80258E94u: goto label_80258E94;
    case 0x80258E98u: goto label_80258E98;
    case 0x80258E9Cu: goto label_80258E9C;
    case 0x80258EA0u: goto label_80258EA0;
    case 0x80258EA4u: goto label_80258EA4;
    case 0x80258EA8u: goto label_80258EA8;
    case 0x80258EACu: goto label_80258EAC;
    case 0x80258EB0u: goto label_80258EB0;
    case 0x80258EB4u: goto label_80258EB4;
    case 0x80258EB8u: goto label_80258EB8;
    case 0x80258EBCu: goto label_80258EBC;
    case 0x80258EC0u: goto label_80258EC0;
    case 0x80258EC4u: goto label_80258EC4;
    case 0x80258EC8u: goto label_80258EC8;
    case 0x80258ECCu: goto label_80258ECC;
    case 0x80258ED0u: goto label_80258ED0;
    case 0x80258ED4u: goto label_80258ED4;
    case 0x80258ED8u: goto label_80258ED8;
    case 0x80258EDCu: goto label_80258EDC;
    case 0x80258EE0u: goto label_80258EE0;
    case 0x80258EE4u: goto label_80258EE4;
    case 0x80258EE8u: goto label_80258EE8;
    case 0x80258EECu: goto label_80258EEC;
    case 0x80258EF0u: goto label_80258EF0;
    case 0x80258EF4u: goto label_80258EF4;
    case 0x80258EF8u: goto label_80258EF8;
    case 0x80258EFCu: goto label_80258EFC;
    case 0x80258F00u: goto label_80258F00;
    case 0x80258F04u: goto label_80258F04;
    case 0x80258F08u: goto label_80258F08;
    case 0x80258F0Cu: goto label_80258F0C;
    case 0x80258F10u: goto label_80258F10;
    case 0x80258F14u: goto label_80258F14;
    case 0x80258F18u: goto label_80258F18;
    case 0x80258F1Cu: goto label_80258F1C;
    case 0x80258F20u: goto label_80258F20;
    case 0x80258F24u: goto label_80258F24;
    case 0x80258F28u: goto label_80258F28;
    case 0x80258F2Cu: goto label_80258F2C;
    case 0x80258F30u: goto label_80258F30;
    case 0x80258F34u: goto label_80258F34;
    case 0x80258F38u: goto label_80258F38;
    case 0x80258F3Cu: goto label_80258F3C;
    case 0x80258F40u: goto label_80258F40;
    case 0x80258F44u: goto label_80258F44;
    case 0x80258F48u: goto label_80258F48;
    case 0x80258F4Cu: goto label_80258F4C;
    case 0x80258F50u: goto label_80258F50;
    case 0x80258F54u: goto label_80258F54;
    case 0x80258F58u: goto label_80258F58;
    case 0x80258F5Cu: goto label_80258F5C;
    case 0x80258F60u: goto label_80258F60;
    case 0x80258F64u: goto label_80258F64;
    case 0x80258F68u: goto label_80258F68;
    case 0x80258F6Cu: goto label_80258F6C;
    case 0x80258F70u: goto label_80258F70;
    case 0x80258F74u: goto label_80258F74;
    case 0x80258F78u: goto label_80258F78;
    case 0x80258F7Cu: goto label_80258F7C;
    case 0x80258F80u: goto label_80258F80;
    case 0x80258F84u: goto label_80258F84;
    case 0x80258F88u: goto label_80258F88;
    case 0x80258F8Cu: goto label_80258F8C;
    case 0x80258F90u: goto label_80258F90;
    case 0x80258F94u: goto label_80258F94;
    case 0x80258F98u: goto label_80258F98;
    case 0x80258F9Cu: goto label_80258F9C;
    case 0x80258FA0u: goto label_80258FA0;
    case 0x80258FA4u: goto label_80258FA4;
    case 0x80258FA8u: goto label_80258FA8;
    case 0x80258FACu: goto label_80258FAC;
    case 0x80258FB0u: goto label_80258FB0;
    case 0x80258FB4u: goto label_80258FB4;
    case 0x80258FB8u: goto label_80258FB8;
    case 0x80258FBCu: goto label_80258FBC;
    case 0x80258FC0u: goto label_80258FC0;
    case 0x80258FC4u: goto label_80258FC4;
    case 0x80258FC8u: goto label_80258FC8;
    case 0x80258FCCu: goto label_80258FCC;
    case 0x80258FD0u: goto label_80258FD0;
    case 0x80258FD4u: goto label_80258FD4;
    case 0x80258FD8u: goto label_80258FD8;
    case 0x80258FDCu: goto label_80258FDC;
    case 0x80258FE0u: goto label_80258FE0;
    case 0x80258FE4u: goto label_80258FE4;
    case 0x80258FE8u: goto label_80258FE8;
    case 0x80258FECu: goto label_80258FEC;
    case 0x80258FF0u: goto label_80258FF0;
    case 0x80258FF4u: goto label_80258FF4;
    case 0x80258FF8u: goto label_80258FF8;
    case 0x80258FFCu: goto label_80258FFC;
    case 0x80259000u: goto label_80259000;
    case 0x80259004u: goto label_80259004;
    case 0x80259008u: goto label_80259008;
    case 0x8025900Cu: goto label_8025900C;
    case 0x80259010u: goto label_80259010;
    case 0x80259014u: goto label_80259014;
    case 0x80259018u: goto label_80259018;
    case 0x8025901Cu: goto label_8025901C;
    case 0x80259020u: goto label_80259020;
    case 0x80259024u: goto label_80259024;
    case 0x80259028u: goto label_80259028;
    case 0x8025902Cu: goto label_8025902C;
    case 0x80259030u: goto label_80259030;
    case 0x80259034u: goto label_80259034;
    case 0x80259038u: goto label_80259038;
    case 0x8025903Cu: goto label_8025903C;
    case 0x80259040u: goto label_80259040;
    case 0x80259044u: goto label_80259044;
    case 0x80259048u: goto label_80259048;
    case 0x8025904Cu: goto label_8025904C;
    case 0x80259050u: goto label_80259050;
    case 0x80259054u: goto label_80259054;
    case 0x80259058u: goto label_80259058;
    case 0x8025905Cu: goto label_8025905C;
    case 0x80259060u: goto label_80259060;
    case 0x80259064u: goto label_80259064;
    case 0x80259068u: goto label_80259068;
    case 0x8025906Cu: goto label_8025906C;
    case 0x80259070u: goto label_80259070;
    case 0x80259074u: goto label_80259074;
    case 0x80259078u: goto label_80259078;
    case 0x8025907Cu: goto label_8025907C;
    case 0x80259080u: goto label_80259080;
    case 0x80259084u: goto label_80259084;
    case 0x80259088u: goto label_80259088;
    case 0x8025908Cu: goto label_8025908C;
    case 0x80259090u: goto label_80259090;
    case 0x80259094u: goto label_80259094;
    case 0x80259098u: goto label_80259098;
    case 0x8025909Cu: goto label_8025909C;
    case 0x802590A0u: goto label_802590A0;
    case 0x802590A4u: goto label_802590A4;
    case 0x802590A8u: goto label_802590A8;
    case 0x802590ACu: goto label_802590AC;
    case 0x802590B0u: goto label_802590B0;
    case 0x802590B4u: goto label_802590B4;
    case 0x802590B8u: goto label_802590B8;
    case 0x802590BCu: goto label_802590BC;
    case 0x802590C0u: goto label_802590C0;
    case 0x802590C4u: goto label_802590C4;
    case 0x802590C8u: goto label_802590C8;
    case 0x802590CCu: goto label_802590CC;
    case 0x802590D0u: goto label_802590D0;
    case 0x802590D4u: goto label_802590D4;
    case 0x802590D8u: goto label_802590D8;
    case 0x802590DCu: goto label_802590DC;
    case 0x802590E0u: goto label_802590E0;
    case 0x802590E4u: goto label_802590E4;
    case 0x802590E8u: goto label_802590E8;
    case 0x802590ECu: goto label_802590EC;
    case 0x802590F0u: goto label_802590F0;
    case 0x802590F4u: goto label_802590F4;
    case 0x802590F8u: goto label_802590F8;
    case 0x802590FCu: goto label_802590FC;
    case 0x80259100u: goto label_80259100;
    case 0x80259104u: goto label_80259104;
    case 0x80259108u: goto label_80259108;
    case 0x8025910Cu: goto label_8025910C;
    case 0x80259110u: goto label_80259110;
    case 0x80259114u: goto label_80259114;
    case 0x80259118u: goto label_80259118;
    case 0x8025911Cu: goto label_8025911C;
    case 0x80259120u: goto label_80259120;
    case 0x80259124u: goto label_80259124;
    case 0x80259128u: goto label_80259128;
    case 0x8025912Cu: goto label_8025912C;
    case 0x80259130u: goto label_80259130;
    case 0x80259134u: goto label_80259134;
    case 0x80259138u: goto label_80259138;
    case 0x8025913Cu: goto label_8025913C;
    case 0x80259140u: goto label_80259140;
    case 0x80259144u: goto label_80259144;
    case 0x80259148u: goto label_80259148;
    case 0x8025914Cu: goto label_8025914C;
    case 0x80259150u: goto label_80259150;
    case 0x80259154u: goto label_80259154;
    case 0x80259158u: goto label_80259158;
    case 0x8025915Cu: goto label_8025915C;
    case 0x80259160u: goto label_80259160;
    case 0x80259164u: goto label_80259164;
    case 0x80259168u: goto label_80259168;
    case 0x8025916Cu: goto label_8025916C;
    case 0x80259170u: goto label_80259170;
    case 0x80259174u: goto label_80259174;
    case 0x80259178u: goto label_80259178;
    case 0x8025917Cu: goto label_8025917C;
    case 0x80259180u: goto label_80259180;
    case 0x80259184u: goto label_80259184;
    case 0x80259188u: goto label_80259188;
    case 0x8025918Cu: goto label_8025918C;
    case 0x80259190u: goto label_80259190;
    case 0x80259194u: goto label_80259194;
    case 0x80259198u: goto label_80259198;
    case 0x8025919Cu: goto label_8025919C;
    case 0x802591A0u: goto label_802591A0;
    case 0x802591A4u: goto label_802591A4;
    case 0x802591A8u: goto label_802591A8;
    case 0x802591ACu: goto label_802591AC;
    case 0x802591B0u: goto label_802591B0;
    case 0x802591B4u: goto label_802591B4;
    case 0x802591B8u: goto label_802591B8;
    case 0x802591BCu: goto label_802591BC;
    case 0x802591C0u: goto label_802591C0;
    case 0x802591C4u: goto label_802591C4;
    case 0x802591C8u: goto label_802591C8;
    case 0x802591CCu: goto label_802591CC;
    case 0x802591D0u: goto label_802591D0;
    case 0x802591D4u: goto label_802591D4;
    case 0x802591D8u: goto label_802591D8;
    case 0x802591DCu: goto label_802591DC;
    case 0x802591E0u: goto label_802591E0;
    case 0x802591E4u: goto label_802591E4;
    case 0x802591E8u: goto label_802591E8;
    case 0x802591ECu: goto label_802591EC;
    case 0x802591F0u: goto label_802591F0;
    case 0x802591F4u: goto label_802591F4;
    case 0x802591F8u: goto label_802591F8;
    case 0x802591FCu: goto label_802591FC;
    case 0x80259200u: goto label_80259200;
    case 0x80259204u: goto label_80259204;
    case 0x80259208u: goto label_80259208;
    case 0x8025920Cu: goto label_8025920C;
    case 0x80259210u: goto label_80259210;
    case 0x80259214u: goto label_80259214;
    case 0x80259218u: goto label_80259218;
    case 0x8025921Cu: goto label_8025921C;
    case 0x80259220u: goto label_80259220;
    case 0x80259224u: goto label_80259224;
    case 0x80259228u: goto label_80259228;
    case 0x8025922Cu: goto label_8025922C;
    case 0x80259230u: goto label_80259230;
    case 0x80259234u: goto label_80259234;
    case 0x80259238u: goto label_80259238;
    case 0x8025923Cu: goto label_8025923C;
    case 0x80259240u: goto label_80259240;
    case 0x80259244u: goto label_80259244;
    case 0x80259248u: goto label_80259248;
    case 0x8025924Cu: goto label_8025924C;
    case 0x80259250u: goto label_80259250;
    case 0x80259254u: goto label_80259254;
    case 0x80259258u: goto label_80259258;
    case 0x8025925Cu: goto label_8025925C;
    case 0x80259260u: goto label_80259260;
    case 0x80259264u: goto label_80259264;
    case 0x80259268u: goto label_80259268;
    case 0x8025926Cu: goto label_8025926C;
    case 0x80259270u: goto label_80259270;
    case 0x80259274u: goto label_80259274;
    case 0x80259278u: goto label_80259278;
    case 0x8025927Cu: goto label_8025927C;
    case 0x80259280u: goto label_80259280;
    case 0x80259284u: goto label_80259284;
    case 0x80259288u: goto label_80259288;
    case 0x8025928Cu: goto label_8025928C;
    case 0x80259290u: goto label_80259290;
    case 0x80259294u: goto label_80259294;
    case 0x80259298u: goto label_80259298;
    case 0x8025929Cu: goto label_8025929C;
    case 0x802592A0u: goto label_802592A0;
    case 0x802592A4u: goto label_802592A4;
    case 0x802592A8u: goto label_802592A8;
    case 0x802592ACu: goto label_802592AC;
    case 0x802592B0u: goto label_802592B0;
    case 0x802592B4u: goto label_802592B4;
    case 0x802592B8u: goto label_802592B8;
    case 0x802592BCu: goto label_802592BC;
    case 0x802592C0u: goto label_802592C0;
    case 0x802592C4u: goto label_802592C4;
    case 0x802592C8u: goto label_802592C8;
    case 0x802592CCu: goto label_802592CC;
    case 0x802592D0u: goto label_802592D0;
    case 0x802592D4u: goto label_802592D4;
    case 0x802592D8u: goto label_802592D8;
    case 0x802592DCu: goto label_802592DC;
    case 0x802592E0u: goto label_802592E0;
    case 0x802592E4u: goto label_802592E4;
    case 0x802592E8u: goto label_802592E8;
    case 0x802592ECu: goto label_802592EC;
    case 0x802592F0u: goto label_802592F0;
    case 0x802592F4u: goto label_802592F4;
    case 0x802592F8u: goto label_802592F8;
    case 0x802592FCu: goto label_802592FC;
    case 0x80259300u: goto label_80259300;
    case 0x80259304u: goto label_80259304;
    case 0x80259308u: goto label_80259308;
    case 0x8025930Cu: goto label_8025930C;
    case 0x80259310u: goto label_80259310;
    case 0x80259314u: goto label_80259314;
    case 0x80259318u: goto label_80259318;
    case 0x8025931Cu: goto label_8025931C;
    case 0x80259320u: goto label_80259320;
    case 0x80259324u: goto label_80259324;
    case 0x80259328u: goto label_80259328;
    case 0x8025932Cu: goto label_8025932C;
    case 0x80259330u: goto label_80259330;
    case 0x80259334u: goto label_80259334;
    case 0x80259338u: goto label_80259338;
    case 0x8025933Cu: goto label_8025933C;
    case 0x80259340u: goto label_80259340;
    case 0x80259344u: goto label_80259344;
    case 0x80259348u: goto label_80259348;
    case 0x8025934Cu: goto label_8025934C;
    case 0x80259350u: goto label_80259350;
    case 0x80259354u: goto label_80259354;
    case 0x80259358u: goto label_80259358;
    case 0x8025935Cu: goto label_8025935C;
    case 0x80259360u: goto label_80259360;
    case 0x80259364u: goto label_80259364;
    case 0x80259368u: goto label_80259368;
    case 0x8025936Cu: goto label_8025936C;
    case 0x80259370u: goto label_80259370;
    case 0x80259374u: goto label_80259374;
    case 0x80259378u: goto label_80259378;
    case 0x8025937Cu: goto label_8025937C;
    case 0x80259380u: goto label_80259380;
    case 0x80259384u: goto label_80259384;
    case 0x80259388u: goto label_80259388;
    case 0x8025938Cu: goto label_8025938C;
    case 0x80259390u: goto label_80259390;
    case 0x80259394u: goto label_80259394;
    case 0x80259398u: goto label_80259398;
    case 0x8025939Cu: goto label_8025939C;
    case 0x802593A0u: goto label_802593A0;
    case 0x802593A4u: goto label_802593A4;
    case 0x802593A8u: goto label_802593A8;
    case 0x802593ACu: goto label_802593AC;
    case 0x802593B0u: goto label_802593B0;
    case 0x802593B4u: goto label_802593B4;
    case 0x802593B8u: goto label_802593B8;
    case 0x802593BCu: goto label_802593BC;
    case 0x802593C0u: goto label_802593C0;
    case 0x802593C4u: goto label_802593C4;
    case 0x802593C8u: goto label_802593C8;
    case 0x802593CCu: goto label_802593CC;
    case 0x802593D0u: goto label_802593D0;
    case 0x802593D4u: goto label_802593D4;
    case 0x802593D8u: goto label_802593D8;
    case 0x802593DCu: goto label_802593DC;
    case 0x802593E0u: goto label_802593E0;
    case 0x802593E4u: goto label_802593E4;
    case 0x802593E8u: goto label_802593E8;
    case 0x802593ECu: goto label_802593EC;
    case 0x802593F0u: goto label_802593F0;
    case 0x802593F4u: goto label_802593F4;
    case 0x802593F8u: goto label_802593F8;
    case 0x802593FCu: goto label_802593FC;
    case 0x80259400u: goto label_80259400;
    case 0x80259404u: goto label_80259404;
    case 0x80259408u: goto label_80259408;
    case 0x8025940Cu: goto label_8025940C;
    case 0x80259410u: goto label_80259410;
    case 0x80259414u: goto label_80259414;
    case 0x80259418u: goto label_80259418;
    case 0x8025941Cu: goto label_8025941C;
    case 0x80259420u: goto label_80259420;
    case 0x80259424u: goto label_80259424;
    case 0x80259428u: goto label_80259428;
    case 0x8025942Cu: goto label_8025942C;
    case 0x80259430u: goto label_80259430;
    case 0x80259434u: goto label_80259434;
    case 0x80259438u: goto label_80259438;
    case 0x8025943Cu: goto label_8025943C;
    case 0x80259440u: goto label_80259440;
    case 0x80259444u: goto label_80259444;
    case 0x80259448u: goto label_80259448;
    case 0x8025944Cu: goto label_8025944C;
    case 0x80259450u: goto label_80259450;
    case 0x80259454u: goto label_80259454;
    case 0x80259458u: goto label_80259458;
    case 0x8025945Cu: goto label_8025945C;
    case 0x80259460u: goto label_80259460;
    case 0x80259464u: goto label_80259464;
    case 0x80259468u: goto label_80259468;
    case 0x8025946Cu: goto label_8025946C;
    case 0x80259470u: goto label_80259470;
    case 0x80259474u: goto label_80259474;
    case 0x80259478u: goto label_80259478;
    case 0x8025947Cu: goto label_8025947C;
    case 0x80259480u: goto label_80259480;
    case 0x80259484u: goto label_80259484;
    case 0x80259488u: goto label_80259488;
    case 0x8025948Cu: goto label_8025948C;
    case 0x80259490u: goto label_80259490;
    case 0x80259494u: goto label_80259494;
    case 0x80259498u: goto label_80259498;
    case 0x8025949Cu: goto label_8025949C;
    case 0x802594A0u: goto label_802594A0;
    case 0x802594A4u: goto label_802594A4;
    case 0x802594A8u: goto label_802594A8;
    case 0x802594ACu: goto label_802594AC;
    case 0x802594B0u: goto label_802594B0;
    case 0x802594B4u: goto label_802594B4;
    case 0x802594B8u: goto label_802594B8;
    case 0x802594BCu: goto label_802594BC;
    case 0x802594C0u: goto label_802594C0;
    case 0x802594C4u: goto label_802594C4;
    case 0x802594C8u: goto label_802594C8;
    case 0x802594CCu: goto label_802594CC;
    case 0x802594D0u: goto label_802594D0;
    case 0x802594D4u: goto label_802594D4;
    case 0x802594D8u: goto label_802594D8;
    case 0x802594DCu: goto label_802594DC;
    case 0x802594E0u: goto label_802594E0;
    case 0x802594E4u: goto label_802594E4;
    case 0x802594E8u: goto label_802594E8;
    case 0x802594ECu: goto label_802594EC;
    case 0x802594F0u: goto label_802594F0;
    case 0x802594F4u: goto label_802594F4;
    case 0x802594F8u: goto label_802594F8;
    case 0x802594FCu: goto label_802594FC;
    case 0x80259500u: goto label_80259500;
    case 0x80259504u: goto label_80259504;
    case 0x80259508u: goto label_80259508;
    case 0x8025950Cu: goto label_8025950C;
    case 0x80259510u: goto label_80259510;
    case 0x80259514u: goto label_80259514;
    case 0x80259518u: goto label_80259518;
    case 0x8025951Cu: goto label_8025951C;
    case 0x80259520u: goto label_80259520;
    case 0x80259524u: goto label_80259524;
    case 0x80259528u: goto label_80259528;
    case 0x8025952Cu: goto label_8025952C;
    case 0x80259530u: goto label_80259530;
    case 0x80259534u: goto label_80259534;
    case 0x80259538u: goto label_80259538;
    case 0x8025953Cu: goto label_8025953C;
    case 0x80259540u: goto label_80259540;
    case 0x80259544u: goto label_80259544;
    case 0x80259548u: goto label_80259548;
    case 0x8025954Cu: goto label_8025954C;
    case 0x80259550u: goto label_80259550;
    case 0x80259554u: goto label_80259554;
    case 0x80259558u: goto label_80259558;
    case 0x8025955Cu: goto label_8025955C;
    case 0x80259560u: goto label_80259560;
    case 0x80259564u: goto label_80259564;
    case 0x80259568u: goto label_80259568;
    case 0x8025956Cu: goto label_8025956C;
    case 0x80259570u: goto label_80259570;
    case 0x80259574u: goto label_80259574;
    case 0x80259578u: goto label_80259578;
    case 0x8025957Cu: goto label_8025957C;
    case 0x80259580u: goto label_80259580;
    case 0x80259584u: goto label_80259584;
    case 0x80259588u: goto label_80259588;
    case 0x8025958Cu: goto label_8025958C;
    case 0x80259590u: goto label_80259590;
    case 0x80259594u: goto label_80259594;
    case 0x80259598u: goto label_80259598;
    case 0x8025959Cu: goto label_8025959C;
    case 0x802595A0u: goto label_802595A0;
    case 0x802595A4u: goto label_802595A4;
    case 0x802595A8u: goto label_802595A8;
    case 0x802595ACu: goto label_802595AC;
    case 0x802595B0u: goto label_802595B0;
    case 0x802595B4u: goto label_802595B4;
    case 0x802595B8u: goto label_802595B8;
    case 0x802595BCu: goto label_802595BC;
    case 0x802595C0u: goto label_802595C0;
    case 0x802595C4u: goto label_802595C4;
    case 0x802595C8u: goto label_802595C8;
    case 0x802595CCu: goto label_802595CC;
    case 0x802595D0u: goto label_802595D0;
    case 0x802595D4u: goto label_802595D4;
    case 0x802595D8u: goto label_802595D8;
    case 0x802595DCu: goto label_802595DC;
    case 0x802595E0u: goto label_802595E0;
    case 0x802595E4u: goto label_802595E4;
    case 0x802595E8u: goto label_802595E8;
    case 0x802595ECu: goto label_802595EC;
    case 0x802595F0u: goto label_802595F0;
    case 0x802595F4u: goto label_802595F4;
    case 0x802595F8u: goto label_802595F8;
    case 0x802595FCu: goto label_802595FC;
    case 0x80259600u: goto label_80259600;
    case 0x80259604u: goto label_80259604;
    case 0x80259608u: goto label_80259608;
    case 0x8025960Cu: goto label_8025960C;
    case 0x80259610u: goto label_80259610;
    case 0x80259614u: goto label_80259614;
    case 0x80259618u: goto label_80259618;
    case 0x8025961Cu: goto label_8025961C;
    case 0x80259620u: goto label_80259620;
    case 0x80259624u: goto label_80259624;
    case 0x80259628u: goto label_80259628;
    case 0x8025962Cu: goto label_8025962C;
    case 0x80259630u: goto label_80259630;
    case 0x80259634u: goto label_80259634;
    case 0x80259638u: goto label_80259638;
    case 0x8025963Cu: goto label_8025963C;
    case 0x80259640u: goto label_80259640;
    case 0x80259644u: goto label_80259644;
    case 0x80259648u: goto label_80259648;
    case 0x8025964Cu: goto label_8025964C;
    case 0x80259650u: goto label_80259650;
    case 0x80259654u: goto label_80259654;
    case 0x80259658u: goto label_80259658;
    case 0x8025965Cu: goto label_8025965C;
    case 0x80259660u: goto label_80259660;
    case 0x80259664u: goto label_80259664;
    case 0x80259668u: goto label_80259668;
    case 0x8025966Cu: goto label_8025966C;
    case 0x80259670u: goto label_80259670;
    case 0x80259674u: goto label_80259674;
    case 0x80259678u: goto label_80259678;
    case 0x8025967Cu: goto label_8025967C;
    case 0x80259680u: goto label_80259680;
    case 0x80259684u: goto label_80259684;
    case 0x80259688u: goto label_80259688;
    case 0x8025968Cu: goto label_8025968C;
    case 0x80259690u: goto label_80259690;
    case 0x80259694u: goto label_80259694;
    case 0x80259698u: goto label_80259698;
    case 0x8025969Cu: goto label_8025969C;
    case 0x802596A0u: goto label_802596A0;
    case 0x802596A4u: goto label_802596A4;
    case 0x802596A8u: goto label_802596A8;
    case 0x802596ACu: goto label_802596AC;
    case 0x802596B0u: goto label_802596B0;
    case 0x802596B4u: goto label_802596B4;
    case 0x802596B8u: goto label_802596B8;
    case 0x802596BCu: goto label_802596BC;
    case 0x802596C0u: goto label_802596C0;
    case 0x802596C4u: goto label_802596C4;
    case 0x802596C8u: goto label_802596C8;
    case 0x802596CCu: goto label_802596CC;
    case 0x802596D0u: goto label_802596D0;
    case 0x802596D4u: goto label_802596D4;
    case 0x802596D8u: goto label_802596D8;
    case 0x802596DCu: goto label_802596DC;
    case 0x802596E0u: goto label_802596E0;
    case 0x802596E4u: goto label_802596E4;
    case 0x802596E8u: goto label_802596E8;
    case 0x802596ECu: goto label_802596EC;
    case 0x802596F0u: goto label_802596F0;
    case 0x802596F4u: goto label_802596F4;
    case 0x802596F8u: goto label_802596F8;
    case 0x802596FCu: goto label_802596FC;
    case 0x80259700u: goto label_80259700;
    case 0x80259704u: goto label_80259704;
    case 0x80259708u: goto label_80259708;
    case 0x8025970Cu: goto label_8025970C;
    case 0x80259710u: goto label_80259710;
    case 0x80259714u: goto label_80259714;
    case 0x80259718u: goto label_80259718;
    case 0x8025971Cu: goto label_8025971C;
    case 0x80259720u: goto label_80259720;
    case 0x80259724u: goto label_80259724;
    case 0x80259728u: goto label_80259728;
    case 0x8025972Cu: goto label_8025972C;
    case 0x80259730u: goto label_80259730;
    case 0x80259734u: goto label_80259734;
    case 0x80259738u: goto label_80259738;
    case 0x8025973Cu: goto label_8025973C;
    case 0x80259740u: goto label_80259740;
    case 0x80259744u: goto label_80259744;
    case 0x80259748u: goto label_80259748;
    case 0x8025974Cu: goto label_8025974C;
    case 0x80259750u: goto label_80259750;
    case 0x80259754u: goto label_80259754;
    case 0x80259758u: goto label_80259758;
    case 0x8025975Cu: goto label_8025975C;
    case 0x80259760u: goto label_80259760;
    case 0x80259764u: goto label_80259764;
    case 0x80259768u: goto label_80259768;
    case 0x8025976Cu: goto label_8025976C;
    case 0x80259770u: goto label_80259770;
    case 0x80259774u: goto label_80259774;
    case 0x80259778u: goto label_80259778;
    case 0x8025977Cu: goto label_8025977C;
    case 0x80259780u: goto label_80259780;
    case 0x80259784u: goto label_80259784;
    case 0x80259788u: goto label_80259788;
    case 0x8025978Cu: goto label_8025978C;
    case 0x80259790u: goto label_80259790;
    case 0x80259794u: goto label_80259794;
    case 0x80259798u: goto label_80259798;
    case 0x8025979Cu: goto label_8025979C;
    case 0x802597A0u: goto label_802597A0;
    case 0x802597A4u: goto label_802597A4;
    case 0x802597A8u: goto label_802597A8;
    case 0x802597ACu: goto label_802597AC;
    case 0x802597B0u: goto label_802597B0;
    case 0x802597B4u: goto label_802597B4;
    case 0x802597B8u: goto label_802597B8;
    case 0x802597BCu: goto label_802597BC;
    case 0x802597C0u: goto label_802597C0;
    case 0x802597C4u: goto label_802597C4;
    case 0x802597C8u: goto label_802597C8;
    case 0x802597CCu: goto label_802597CC;
    case 0x802597D0u: goto label_802597D0;
    case 0x802597D4u: goto label_802597D4;
    case 0x802597D8u: goto label_802597D8;
    case 0x802597DCu: goto label_802597DC;
    case 0x802597E0u: goto label_802597E0;
    case 0x802597E4u: goto label_802597E4;
    case 0x802597E8u: goto label_802597E8;
    case 0x802597ECu: goto label_802597EC;
    case 0x802597F0u: goto label_802597F0;
    case 0x802597F4u: goto label_802597F4;
    case 0x802597F8u: goto label_802597F8;
    case 0x802597FCu: goto label_802597FC;
    case 0x80259800u: goto label_80259800;
    case 0x80259804u: goto label_80259804;
    case 0x80259808u: goto label_80259808;
    case 0x8025980Cu: goto label_8025980C;
    case 0x80259810u: goto label_80259810;
    case 0x80259814u: goto label_80259814;
    case 0x80259818u: goto label_80259818;
    case 0x8025981Cu: goto label_8025981C;
    case 0x80259820u: goto label_80259820;
    case 0x80259824u: goto label_80259824;
    case 0x80259828u: goto label_80259828;
    case 0x8025982Cu: goto label_8025982C;
    case 0x80259830u: goto label_80259830;
    case 0x80259834u: goto label_80259834;
    case 0x80259838u: goto label_80259838;
    case 0x8025983Cu: goto label_8025983C;
    case 0x80259840u: goto label_80259840;
    case 0x80259844u: goto label_80259844;
    case 0x80259848u: goto label_80259848;
    case 0x8025984Cu: goto label_8025984C;
    case 0x80259850u: goto label_80259850;
    case 0x80259854u: goto label_80259854;
    case 0x80259858u: goto label_80259858;
    case 0x8025985Cu: goto label_8025985C;
    case 0x80259860u: goto label_80259860;
    case 0x80259864u: goto label_80259864;
    case 0x80259868u: goto label_80259868;
    case 0x8025986Cu: goto label_8025986C;
    case 0x80259870u: goto label_80259870;
    case 0x80259874u: goto label_80259874;
    case 0x80259878u: goto label_80259878;
    case 0x8025987Cu: goto label_8025987C;
    case 0x80259880u: goto label_80259880;
    case 0x80259884u: goto label_80259884;
    case 0x80259888u: goto label_80259888;
    case 0x8025988Cu: goto label_8025988C;
    case 0x80259890u: goto label_80259890;
    case 0x80259894u: goto label_80259894;
    case 0x80259898u: goto label_80259898;
    case 0x8025989Cu: goto label_8025989C;
    case 0x802598A0u: goto label_802598A0;
    case 0x802598A4u: goto label_802598A4;
    case 0x802598A8u: goto label_802598A8;
    case 0x802598ACu: goto label_802598AC;
    case 0x802598B0u: goto label_802598B0;
    case 0x802598B4u: goto label_802598B4;
    case 0x802598B8u: goto label_802598B8;
    case 0x802598BCu: goto label_802598BC;
    case 0x802598C0u: goto label_802598C0;
    case 0x802598C4u: goto label_802598C4;
    case 0x802598C8u: goto label_802598C8;
    case 0x802598CCu: goto label_802598CC;
    case 0x802598D0u: goto label_802598D0;
    case 0x802598D4u: goto label_802598D4;
    case 0x802598D8u: goto label_802598D8;
    case 0x802598DCu: goto label_802598DC;
    case 0x802598E0u: goto label_802598E0;
    case 0x802598E4u: goto label_802598E4;
    case 0x802598E8u: goto label_802598E8;
    case 0x802598ECu: goto label_802598EC;
    case 0x802598F0u: goto label_802598F0;
    case 0x802598F4u: goto label_802598F4;
    case 0x802598F8u: goto label_802598F8;
    case 0x802598FCu: goto label_802598FC;
    case 0x80259900u: goto label_80259900;
    case 0x80259904u: goto label_80259904;
    case 0x80259908u: goto label_80259908;
    case 0x8025990Cu: goto label_8025990C;
    case 0x80259910u: goto label_80259910;
    case 0x80259914u: goto label_80259914;
    case 0x80259918u: goto label_80259918;
    case 0x8025991Cu: goto label_8025991C;
    case 0x80259920u: goto label_80259920;
    case 0x80259924u: goto label_80259924;
    case 0x80259928u: goto label_80259928;
    case 0x8025992Cu: goto label_8025992C;
    case 0x80259930u: goto label_80259930;
    case 0x80259934u: goto label_80259934;
    case 0x80259938u: goto label_80259938;
    case 0x8025993Cu: goto label_8025993C;
    case 0x80259940u: goto label_80259940;
    case 0x80259944u: goto label_80259944;
    case 0x80259948u: goto label_80259948;
    case 0x8025994Cu: goto label_8025994C;
    case 0x80259950u: goto label_80259950;
    case 0x80259954u: goto label_80259954;
    case 0x80259958u: goto label_80259958;
    case 0x8025995Cu: goto label_8025995C;
    case 0x80259960u: goto label_80259960;
    case 0x80259964u: goto label_80259964;
    case 0x80259968u: goto label_80259968;
    case 0x8025996Cu: goto label_8025996C;
    case 0x80259970u: goto label_80259970;
    case 0x80259974u: goto label_80259974;
    case 0x80259978u: goto label_80259978;
    case 0x8025997Cu: goto label_8025997C;
    case 0x80259980u: goto label_80259980;
    case 0x80259984u: goto label_80259984;
    case 0x80259988u: goto label_80259988;
    case 0x8025998Cu: goto label_8025998C;
    case 0x80259990u: goto label_80259990;
    case 0x80259994u: goto label_80259994;
    case 0x80259998u: goto label_80259998;
    case 0x8025999Cu: goto label_8025999C;
    case 0x802599A0u: goto label_802599A0;
    case 0x802599A4u: goto label_802599A4;
    case 0x802599A8u: goto label_802599A8;
    case 0x802599ACu: goto label_802599AC;
    case 0x802599B0u: goto label_802599B0;
    case 0x802599B4u: goto label_802599B4;
    case 0x802599B8u: goto label_802599B8;
    case 0x802599BCu: goto label_802599BC;
    case 0x802599C0u: goto label_802599C0;
    case 0x802599C4u: goto label_802599C4;
    case 0x802599C8u: goto label_802599C8;
    case 0x802599CCu: goto label_802599CC;
    case 0x802599D0u: goto label_802599D0;
    case 0x802599D4u: goto label_802599D4;
    case 0x802599D8u: goto label_802599D8;
    case 0x802599DCu: goto label_802599DC;
    case 0x802599E0u: goto label_802599E0;
    case 0x802599E4u: goto label_802599E4;
    case 0x802599E8u: goto label_802599E8;
    case 0x802599ECu: goto label_802599EC;
    case 0x802599F0u: goto label_802599F0;
    case 0x802599F4u: goto label_802599F4;
    case 0x802599F8u: goto label_802599F8;
    case 0x802599FCu: goto label_802599FC;
    case 0x80259A00u: goto label_80259A00;
    case 0x80259A04u: goto label_80259A04;
    case 0x80259A08u: goto label_80259A08;
    case 0x80259A0Cu: goto label_80259A0C;
    case 0x80259A10u: goto label_80259A10;
    case 0x80259A14u: goto label_80259A14;
    case 0x80259A18u: goto label_80259A18;
    case 0x80259A1Cu: goto label_80259A1C;
    case 0x80259A20u: goto label_80259A20;
    case 0x80259A24u: goto label_80259A24;
    case 0x80259A28u: goto label_80259A28;
    case 0x80259A2Cu: goto label_80259A2C;
    case 0x80259A30u: goto label_80259A30;
    case 0x80259A34u: goto label_80259A34;
    case 0x80259A38u: goto label_80259A38;
    case 0x80259A3Cu: goto label_80259A3C;
    case 0x80259A40u: goto label_80259A40;
    case 0x80259A44u: goto label_80259A44;
    case 0x80259A48u: goto label_80259A48;
    case 0x80259A4Cu: goto label_80259A4C;
    case 0x80259A50u: goto label_80259A50;
    case 0x80259A54u: goto label_80259A54;
    case 0x80259A58u: goto label_80259A58;
    case 0x80259A5Cu: goto label_80259A5C;
    case 0x80259A60u: goto label_80259A60;
    case 0x80259A64u: goto label_80259A64;
    case 0x80259A68u: goto label_80259A68;
    case 0x80259A6Cu: goto label_80259A6C;
    case 0x80259A70u: goto label_80259A70;
    case 0x80259A74u: goto label_80259A74;
    case 0x80259A78u: goto label_80259A78;
    case 0x80259A7Cu: goto label_80259A7C;
    case 0x80259A80u: goto label_80259A80;
    case 0x80259A84u: goto label_80259A84;
    case 0x80259A88u: goto label_80259A88;
    case 0x80259A8Cu: goto label_80259A8C;
    case 0x80259A90u: goto label_80259A90;
    case 0x80259A94u: goto label_80259A94;
    case 0x80259A98u: goto label_80259A98;
    case 0x80259A9Cu: goto label_80259A9C;
    case 0x80259AA0u: goto label_80259AA0;
    case 0x80259AA4u: goto label_80259AA4;
    case 0x80259AA8u: goto label_80259AA8;
    case 0x80259AACu: goto label_80259AAC;
    case 0x80259AB0u: goto label_80259AB0;
    case 0x80259AB4u: goto label_80259AB4;
    case 0x80259AB8u: goto label_80259AB8;
    case 0x80259ABCu: goto label_80259ABC;
    case 0x80259AC0u: goto label_80259AC0;
    case 0x80259AC4u: goto label_80259AC4;
    case 0x80259AC8u: goto label_80259AC8;
    case 0x80259ACCu: goto label_80259ACC;
    case 0x80259AD0u: goto label_80259AD0;
    case 0x80259AD4u: goto label_80259AD4;
    case 0x80259AD8u: goto label_80259AD8;
    case 0x80259ADCu: goto label_80259ADC;
    case 0x80259AE0u: goto label_80259AE0;
    case 0x80259AE4u: goto label_80259AE4;
    case 0x80259AE8u: goto label_80259AE8;
    case 0x80259AECu: goto label_80259AEC;
    case 0x80259AF0u: goto label_80259AF0;
    case 0x80259AF4u: goto label_80259AF4;
    case 0x80259AF8u: goto label_80259AF8;
    case 0x80259AFCu: goto label_80259AFC;
    case 0x80259B00u: goto label_80259B00;
    case 0x80259B04u: goto label_80259B04;
    case 0x80259B08u: goto label_80259B08;
    case 0x80259B0Cu: goto label_80259B0C;
    case 0x80259B10u: goto label_80259B10;
    case 0x80259B14u: goto label_80259B14;
    case 0x80259B18u: goto label_80259B18;
    case 0x80259B1Cu: goto label_80259B1C;
    case 0x80259B20u: goto label_80259B20;
    case 0x80259B24u: goto label_80259B24;
    case 0x80259B28u: goto label_80259B28;
    case 0x80259B2Cu: goto label_80259B2C;
    case 0x80259B30u: goto label_80259B30;
    case 0x80259B34u: goto label_80259B34;
    case 0x80259B38u: goto label_80259B38;
    case 0x80259B3Cu: goto label_80259B3C;
    case 0x80259B40u: goto label_80259B40;
    case 0x80259B44u: goto label_80259B44;
    case 0x80259B48u: goto label_80259B48;
    case 0x80259B4Cu: goto label_80259B4C;
    case 0x80259B50u: goto label_80259B50;
    case 0x80259B54u: goto label_80259B54;
    case 0x80259B58u: goto label_80259B58;
    case 0x80259B5Cu: goto label_80259B5C;
    case 0x80259B60u: goto label_80259B60;
    case 0x80259B64u: goto label_80259B64;
    case 0x80259B68u: goto label_80259B68;
    case 0x80259B6Cu: goto label_80259B6C;
    case 0x80259B70u: goto label_80259B70;
    case 0x80259B74u: goto label_80259B74;
    case 0x80259B78u: goto label_80259B78;
    case 0x80259B7Cu: goto label_80259B7C;
    case 0x80259B80u: goto label_80259B80;
    case 0x80259B84u: goto label_80259B84;
    case 0x80259B88u: goto label_80259B88;
    case 0x80259B8Cu: goto label_80259B8C;
    case 0x80259B90u: goto label_80259B90;
    case 0x80259B94u: goto label_80259B94;
    case 0x80259B98u: goto label_80259B98;
    case 0x80259B9Cu: goto label_80259B9C;
    case 0x80259BA0u: goto label_80259BA0;
    case 0x80259BA4u: goto label_80259BA4;
    case 0x80259BA8u: goto label_80259BA8;
    case 0x80259BACu: goto label_80259BAC;
    case 0x80259BB0u: goto label_80259BB0;
    case 0x80259BB4u: goto label_80259BB4;
    case 0x80259BB8u: goto label_80259BB8;
    case 0x80259BBCu: goto label_80259BBC;
    case 0x80259BC0u: goto label_80259BC0;
    case 0x80259BC4u: goto label_80259BC4;
    case 0x80259BC8u: goto label_80259BC8;
    case 0x80259BCCu: goto label_80259BCC;
    case 0x80259BD0u: goto label_80259BD0;
    case 0x80259BD4u: goto label_80259BD4;
    case 0x80259BD8u: goto label_80259BD8;
    case 0x80259BDCu: goto label_80259BDC;
    case 0x80259BE0u: goto label_80259BE0;
    case 0x80259BE4u: goto label_80259BE4;
    case 0x80259BE8u: goto label_80259BE8;
    case 0x80259BECu: goto label_80259BEC;
    case 0x80259BF0u: goto label_80259BF0;
    case 0x80259BF4u: goto label_80259BF4;
    case 0x80259BF8u: goto label_80259BF8;
    case 0x80259BFCu: goto label_80259BFC;
    case 0x80259C00u: goto label_80259C00;
    case 0x80259C04u: goto label_80259C04;
    case 0x80259C08u: goto label_80259C08;
    case 0x80259C0Cu: goto label_80259C0C;
    case 0x80259C10u: goto label_80259C10;
    case 0x80259C14u: goto label_80259C14;
    case 0x80259C18u: goto label_80259C18;
    case 0x80259C1Cu: goto label_80259C1C;
    case 0x80259C20u: goto label_80259C20;
    case 0x80259C24u: goto label_80259C24;
    case 0x80259C28u: goto label_80259C28;
    case 0x80259C2Cu: goto label_80259C2C;
    case 0x80259C30u: goto label_80259C30;
    case 0x80259C34u: goto label_80259C34;
    case 0x80259C38u: goto label_80259C38;
    case 0x80259C3Cu: goto label_80259C3C;
    case 0x80259C40u: goto label_80259C40;
    case 0x80259C44u: goto label_80259C44;
    case 0x80259C48u: goto label_80259C48;
    case 0x80259C4Cu: goto label_80259C4C;
    case 0x80259C50u: goto label_80259C50;
    case 0x80259C54u: goto label_80259C54;
    case 0x80259C58u: goto label_80259C58;
    case 0x80259C5Cu: goto label_80259C5C;
    case 0x80259C60u: goto label_80259C60;
    case 0x80259C64u: goto label_80259C64;
    case 0x80259C68u: goto label_80259C68;
    case 0x80259C6Cu: goto label_80259C6C;
    case 0x80259C70u: goto label_80259C70;
    case 0x80259C74u: goto label_80259C74;
    case 0x80259C78u: goto label_80259C78;
    case 0x80259C7Cu: goto label_80259C7C;
    case 0x80259C80u: goto label_80259C80;
    case 0x80259C84u: goto label_80259C84;
    case 0x80259C88u: goto label_80259C88;
    case 0x80259C8Cu: goto label_80259C8C;
    case 0x80259C90u: goto label_80259C90;
    case 0x80259C94u: goto label_80259C94;
    case 0x80259C98u: goto label_80259C98;
    case 0x80259C9Cu: goto label_80259C9C;
    case 0x80259CA0u: goto label_80259CA0;
    case 0x80259CA4u: goto label_80259CA4;
    case 0x80259CA8u: goto label_80259CA8;
    case 0x80259CACu: goto label_80259CAC;
    case 0x80259CB0u: goto label_80259CB0;
    case 0x80259CB4u: goto label_80259CB4;
    case 0x80259CB8u: goto label_80259CB8;
    case 0x80259CBCu: goto label_80259CBC;
    case 0x80259CC0u: goto label_80259CC0;
    case 0x80259CC4u: goto label_80259CC4;
    case 0x80259CC8u: goto label_80259CC8;
    case 0x80259CCCu: goto label_80259CCC;
    case 0x80259CD0u: goto label_80259CD0;
    case 0x80259CD4u: goto label_80259CD4;
    case 0x80259CD8u: goto label_80259CD8;
    case 0x80259CDCu: goto label_80259CDC;
    case 0x80259CE0u: goto label_80259CE0;
    case 0x80259CE4u: goto label_80259CE4;
    case 0x80259CE8u: goto label_80259CE8;
    case 0x80259CECu: goto label_80259CEC;
    case 0x80259CF0u: goto label_80259CF0;
    case 0x80259CF4u: goto label_80259CF4;
    case 0x80259CF8u: goto label_80259CF8;
    case 0x80259CFCu: goto label_80259CFC;
    case 0x80259D00u: goto label_80259D00;
    case 0x80259D04u: goto label_80259D04;
    case 0x80259D08u: goto label_80259D08;
    case 0x80259D0Cu: goto label_80259D0C;
    case 0x80259D10u: goto label_80259D10;
    case 0x80259D14u: goto label_80259D14;
    case 0x80259D18u: goto label_80259D18;
    case 0x80259D1Cu: goto label_80259D1C;
    case 0x80259D20u: goto label_80259D20;
    case 0x80259D24u: goto label_80259D24;
    case 0x80259D28u: goto label_80259D28;
    case 0x80259D2Cu: goto label_80259D2C;
    case 0x80259D30u: goto label_80259D30;
    case 0x80259D34u: goto label_80259D34;
    case 0x80259D38u: goto label_80259D38;
    case 0x80259D3Cu: goto label_80259D3C;
    case 0x80259D40u: goto label_80259D40;
    case 0x80259D44u: goto label_80259D44;
    case 0x80259D48u: goto label_80259D48;
    case 0x80259D4Cu: goto label_80259D4C;
    case 0x80259D50u: goto label_80259D50;
    case 0x80259D54u: goto label_80259D54;
    case 0x80259D58u: goto label_80259D58;
    case 0x80259D5Cu: goto label_80259D5C;
    case 0x80259D60u: goto label_80259D60;
    case 0x80259D64u: goto label_80259D64;
    case 0x80259D68u: goto label_80259D68;
    case 0x80259D6Cu: goto label_80259D6C;
    case 0x80259D70u: goto label_80259D70;
    case 0x80259D74u: goto label_80259D74;
    case 0x80259D78u: goto label_80259D78;
    case 0x80259D7Cu: goto label_80259D7C;
    case 0x80259D80u: goto label_80259D80;
    case 0x80259D84u: goto label_80259D84;
    case 0x80259D88u: goto label_80259D88;
    case 0x80259D8Cu: goto label_80259D8C;
    case 0x80259D90u: goto label_80259D90;
    case 0x80259D94u: goto label_80259D94;
    case 0x80259D98u: goto label_80259D98;
    case 0x80259D9Cu: goto label_80259D9C;
    case 0x80259DA0u: goto label_80259DA0;
    case 0x80259DA4u: goto label_80259DA4;
    case 0x80259DA8u: goto label_80259DA8;
    case 0x80259DACu: goto label_80259DAC;
    case 0x80259DB0u: goto label_80259DB0;
    case 0x80259DB4u: goto label_80259DB4;
    case 0x80259DB8u: goto label_80259DB8;
    case 0x80259DBCu: goto label_80259DBC;
    case 0x80259DC0u: goto label_80259DC0;
    case 0x80259DC4u: goto label_80259DC4;
    case 0x80259DC8u: goto label_80259DC8;
    case 0x80259DCCu: goto label_80259DCC;
    case 0x80259DD0u: goto label_80259DD0;
    case 0x80259DD4u: goto label_80259DD4;
    case 0x80259DD8u: goto label_80259DD8;
    case 0x80259DDCu: goto label_80259DDC;
    case 0x80259DE0u: goto label_80259DE0;
    case 0x80259DE4u: goto label_80259DE4;
    case 0x80259DE8u: goto label_80259DE8;
    case 0x80259DECu: goto label_80259DEC;
    case 0x80259DF0u: goto label_80259DF0;
    case 0x80259DF4u: goto label_80259DF4;
    case 0x80259DF8u: goto label_80259DF8;
    case 0x80259DFCu: goto label_80259DFC;
    case 0x80259E00u: goto label_80259E00;
    case 0x80259E04u: goto label_80259E04;
    case 0x80259E08u: goto label_80259E08;
    case 0x80259E0Cu: goto label_80259E0C;
    case 0x80259E10u: goto label_80259E10;
    case 0x80259E14u: goto label_80259E14;
    case 0x80259E18u: goto label_80259E18;
    case 0x80259E1Cu: goto label_80259E1C;
    case 0x80259E20u: goto label_80259E20;
    case 0x80259E24u: goto label_80259E24;
    case 0x80259E28u: goto label_80259E28;
    case 0x80259E2Cu: goto label_80259E2C;
    case 0x80259E30u: goto label_80259E30;
    case 0x80259E34u: goto label_80259E34;
    case 0x80259E38u: goto label_80259E38;
    case 0x80259E3Cu: goto label_80259E3C;
    case 0x80259E40u: goto label_80259E40;
    case 0x80259E44u: goto label_80259E44;
    case 0x80259E48u: goto label_80259E48;
    case 0x80259E4Cu: goto label_80259E4C;
    case 0x80259E50u: goto label_80259E50;
    case 0x80259E54u: goto label_80259E54;
    case 0x80259E58u: goto label_80259E58;
    case 0x80259E5Cu: goto label_80259E5C;
    case 0x80259E60u: goto label_80259E60;
    case 0x80259E64u: goto label_80259E64;
    case 0x80259E68u: goto label_80259E68;
    case 0x80259E6Cu: goto label_80259E6C;
    case 0x80259E70u: goto label_80259E70;
    case 0x80259E74u: goto label_80259E74;
    case 0x80259E78u: goto label_80259E78;
    case 0x80259E7Cu: goto label_80259E7C;
    case 0x80259E80u: goto label_80259E80;
    case 0x80259E84u: goto label_80259E84;
    case 0x80259E88u: goto label_80259E88;
    case 0x80259E8Cu: goto label_80259E8C;
    case 0x80259E90u: goto label_80259E90;
    case 0x80259E94u: goto label_80259E94;
    case 0x80259E98u: goto label_80259E98;
    case 0x80259E9Cu: goto label_80259E9C;
    case 0x80259EA0u: goto label_80259EA0;
    case 0x80259EA4u: goto label_80259EA4;
    case 0x80259EA8u: goto label_80259EA8;
    case 0x80259EACu: goto label_80259EAC;
    case 0x80259EB0u: goto label_80259EB0;
    case 0x80259EB4u: goto label_80259EB4;
    case 0x80259EB8u: goto label_80259EB8;
    case 0x80259EBCu: goto label_80259EBC;
    case 0x80259EC0u: goto label_80259EC0;
    case 0x80259EC4u: goto label_80259EC4;
    case 0x80259EC8u: goto label_80259EC8;
    case 0x80259ECCu: goto label_80259ECC;
    case 0x80259ED0u: goto label_80259ED0;
    case 0x80259ED4u: goto label_80259ED4;
    case 0x80259ED8u: goto label_80259ED8;
    case 0x80259EDCu: goto label_80259EDC;
    case 0x80259EE0u: goto label_80259EE0;
    case 0x80259EE4u: goto label_80259EE4;
    case 0x80259EE8u: goto label_80259EE8;
    case 0x80259EECu: goto label_80259EEC;
    case 0x80259EF0u: goto label_80259EF0;
    case 0x80259EF4u: goto label_80259EF4;
    case 0x80259EF8u: goto label_80259EF8;
    case 0x80259EFCu: goto label_80259EFC;
    case 0x80259F00u: goto label_80259F00;
    case 0x80259F04u: goto label_80259F04;
    case 0x80259F08u: goto label_80259F08;
    case 0x80259F0Cu: goto label_80259F0C;
    case 0x80259F10u: goto label_80259F10;
    case 0x80259F14u: goto label_80259F14;
    case 0x80259F18u: goto label_80259F18;
    case 0x80259F1Cu: goto label_80259F1C;
    case 0x80259F20u: goto label_80259F20;
    case 0x80259F24u: goto label_80259F24;
    case 0x80259F28u: goto label_80259F28;
    case 0x80259F2Cu: goto label_80259F2C;
    case 0x80259F30u: goto label_80259F30;
    case 0x80259F34u: goto label_80259F34;
    case 0x80259F38u: goto label_80259F38;
    case 0x80259F3Cu: goto label_80259F3C;
    case 0x80259F40u: goto label_80259F40;
    case 0x80259F44u: goto label_80259F44;
    case 0x80259F48u: goto label_80259F48;
    case 0x80259F4Cu: goto label_80259F4C;
    case 0x80259F50u: goto label_80259F50;
    case 0x80259F54u: goto label_80259F54;
    case 0x80259F58u: goto label_80259F58;
    case 0x80259F5Cu: goto label_80259F5C;
    case 0x80259F60u: goto label_80259F60;
    case 0x80259F64u: goto label_80259F64;
    case 0x80259F68u: goto label_80259F68;
    case 0x80259F6Cu: goto label_80259F6C;
    case 0x80259F70u: goto label_80259F70;
    case 0x80259F74u: goto label_80259F74;
    case 0x80259F78u: goto label_80259F78;
    case 0x80259F7Cu: goto label_80259F7C;
    case 0x80259F80u: goto label_80259F80;
    case 0x80259F84u: goto label_80259F84;
    case 0x80259F88u: goto label_80259F88;
    case 0x80259F8Cu: goto label_80259F8C;
    case 0x80259F90u: goto label_80259F90;
    case 0x80259F94u: goto label_80259F94;
    case 0x80259F98u: goto label_80259F98;
    case 0x80259F9Cu: goto label_80259F9C;
    case 0x80259FA0u: goto label_80259FA0;
    case 0x80259FA4u: goto label_80259FA4;
    case 0x80259FA8u: goto label_80259FA8;
    case 0x80259FACu: goto label_80259FAC;
    case 0x80259FB0u: goto label_80259FB0;
    case 0x80259FB4u: goto label_80259FB4;
    case 0x80259FB8u: goto label_80259FB8;
    case 0x80259FBCu: goto label_80259FBC;
    case 0x80259FC0u: goto label_80259FC0;
    case 0x80259FC4u: goto label_80259FC4;
    case 0x80259FC8u: goto label_80259FC8;
    case 0x80259FCCu: goto label_80259FCC;
    case 0x80259FD0u: goto label_80259FD0;
    case 0x80259FD4u: goto label_80259FD4;
    case 0x80259FD8u: goto label_80259FD8;
    case 0x80259FDCu: goto label_80259FDC;
    case 0x80259FE0u: goto label_80259FE0;
    case 0x80259FE4u: goto label_80259FE4;
    case 0x80259FE8u: goto label_80259FE8;
    case 0x80259FECu: goto label_80259FEC;
    case 0x80259FF0u: goto label_80259FF0;
    case 0x80259FF4u: goto label_80259FF4;
    case 0x80259FF8u: goto label_80259FF8;
    case 0x80259FFCu: goto label_80259FFC;
    case 0x8025A000u: goto label_8025A000;
    case 0x8025A004u: goto label_8025A004;
    case 0x8025A008u: goto label_8025A008;
    case 0x8025A00Cu: goto label_8025A00C;
    case 0x8025A010u: goto label_8025A010;
    case 0x8025A014u: goto label_8025A014;
    case 0x8025A018u: goto label_8025A018;
    case 0x8025A01Cu: goto label_8025A01C;
    case 0x8025A020u: goto label_8025A020;
    case 0x8025A024u: goto label_8025A024;
    case 0x8025A028u: goto label_8025A028;
    case 0x8025A02Cu: goto label_8025A02C;
    case 0x8025A030u: goto label_8025A030;
    case 0x8025A034u: goto label_8025A034;
    case 0x8025A038u: goto label_8025A038;
    case 0x8025A03Cu: goto label_8025A03C;
    case 0x8025A040u: goto label_8025A040;
    case 0x8025A044u: goto label_8025A044;
    case 0x8025A048u: goto label_8025A048;
    case 0x8025A04Cu: goto label_8025A04C;
    case 0x8025A050u: goto label_8025A050;
    case 0x8025A054u: goto label_8025A054;
    case 0x8025A058u: goto label_8025A058;
    case 0x8025A05Cu: goto label_8025A05C;
    case 0x8025A060u: goto label_8025A060;
    case 0x8025A064u: goto label_8025A064;
    case 0x8025A068u: goto label_8025A068;
    case 0x8025A06Cu: goto label_8025A06C;
    case 0x8025A070u: goto label_8025A070;
    case 0x8025A074u: goto label_8025A074;
    case 0x8025A078u: goto label_8025A078;
    case 0x8025A07Cu: goto label_8025A07C;
    case 0x8025A080u: goto label_8025A080;
    case 0x8025A084u: goto label_8025A084;
    case 0x8025A088u: goto label_8025A088;
    case 0x8025A08Cu: goto label_8025A08C;
    case 0x8025A090u: goto label_8025A090;
    case 0x8025A094u: goto label_8025A094;
    case 0x8025A098u: goto label_8025A098;
    case 0x8025A09Cu: goto label_8025A09C;
    case 0x8025A0A0u: goto label_8025A0A0;
    case 0x8025A0A4u: goto label_8025A0A4;
    case 0x8025A0A8u: goto label_8025A0A8;
    case 0x8025A0ACu: goto label_8025A0AC;
    case 0x8025A0B0u: goto label_8025A0B0;
    case 0x8025A0B4u: goto label_8025A0B4;
    case 0x8025A0B8u: goto label_8025A0B8;
    case 0x8025A0BCu: goto label_8025A0BC;
    case 0x8025A0C0u: goto label_8025A0C0;
    case 0x8025A0C4u: goto label_8025A0C4;
    case 0x8025A0C8u: goto label_8025A0C8;
    case 0x8025A0CCu: goto label_8025A0CC;
    case 0x8025A0D0u: goto label_8025A0D0;
    case 0x8025A0D4u: goto label_8025A0D4;
    case 0x8025A0D8u: goto label_8025A0D8;
    case 0x8025A0DCu: goto label_8025A0DC;
    case 0x8025A0E0u: goto label_8025A0E0;
    case 0x8025A0E4u: goto label_8025A0E4;
    case 0x8025A0E8u: goto label_8025A0E8;
    case 0x8025A0ECu: goto label_8025A0EC;
    case 0x8025A0F0u: goto label_8025A0F0;
    case 0x8025A0F4u: goto label_8025A0F4;
    case 0x8025A0F8u: goto label_8025A0F8;
    case 0x8025A0FCu: goto label_8025A0FC;
    case 0x8025A100u: goto label_8025A100;
    case 0x8025A104u: goto label_8025A104;
    case 0x8025A108u: goto label_8025A108;
    case 0x8025A10Cu: goto label_8025A10C;
    case 0x8025A110u: goto label_8025A110;
    case 0x8025A114u: goto label_8025A114;
    case 0x8025A118u: goto label_8025A118;
    case 0x8025A11Cu: goto label_8025A11C;
    case 0x8025A120u: goto label_8025A120;
    case 0x8025A124u: goto label_8025A124;
    case 0x8025A128u: goto label_8025A128;
    case 0x8025A12Cu: goto label_8025A12C;
    case 0x8025A130u: goto label_8025A130;
    case 0x8025A134u: goto label_8025A134;
    case 0x8025A138u: goto label_8025A138;
    case 0x8025A13Cu: goto label_8025A13C;
    case 0x8025A140u: goto label_8025A140;
    case 0x8025A144u: goto label_8025A144;
    case 0x8025A148u: goto label_8025A148;
    case 0x8025A14Cu: goto label_8025A14C;
    case 0x8025A150u: goto label_8025A150;
    case 0x8025A154u: goto label_8025A154;
    case 0x8025A158u: goto label_8025A158;
    case 0x8025A15Cu: goto label_8025A15C;
    case 0x8025A160u: goto label_8025A160;
    case 0x8025A164u: goto label_8025A164;
    case 0x8025A168u: goto label_8025A168;
    case 0x8025A16Cu: goto label_8025A16C;
    case 0x8025A170u: goto label_8025A170;
    case 0x8025A174u: goto label_8025A174;
    case 0x8025A178u: goto label_8025A178;
    case 0x8025A17Cu: goto label_8025A17C;
    case 0x8025A180u: goto label_8025A180;
    case 0x8025A184u: goto label_8025A184;
    case 0x8025A188u: goto label_8025A188;
    case 0x8025A18Cu: goto label_8025A18C;
    case 0x8025A190u: goto label_8025A190;
    case 0x8025A194u: goto label_8025A194;
    case 0x8025A198u: goto label_8025A198;
    case 0x8025A19Cu: goto label_8025A19C;
    case 0x8025A1A0u: goto label_8025A1A0;
    case 0x8025A1A4u: goto label_8025A1A4;
    case 0x8025A1A8u: goto label_8025A1A8;
    case 0x8025A1ACu: goto label_8025A1AC;
    case 0x8025A1B0u: goto label_8025A1B0;
    case 0x8025A1B4u: goto label_8025A1B4;
    case 0x8025A1B8u: goto label_8025A1B8;
    case 0x8025A1BCu: goto label_8025A1BC;
    case 0x8025A1C0u: goto label_8025A1C0;
    case 0x8025A1C4u: goto label_8025A1C4;
    case 0x8025A1C8u: goto label_8025A1C8;
    case 0x8025A1CCu: goto label_8025A1CC;
    case 0x8025A1D0u: goto label_8025A1D0;
    case 0x8025A1D4u: goto label_8025A1D4;
    case 0x8025A1D8u: goto label_8025A1D8;
    case 0x8025A1DCu: goto label_8025A1DC;
    case 0x8025A1E0u: goto label_8025A1E0;
    case 0x8025A1E4u: goto label_8025A1E4;
    case 0x8025A1E8u: goto label_8025A1E8;
    case 0x8025A1ECu: goto label_8025A1EC;
    case 0x8025A1F0u: goto label_8025A1F0;
    case 0x8025A1F4u: goto label_8025A1F4;
    case 0x8025A1F8u: goto label_8025A1F8;
    case 0x8025A1FCu: goto label_8025A1FC;
    case 0x8025A200u: goto label_8025A200;
    case 0x8025A204u: goto label_8025A204;
    case 0x8025A208u: goto label_8025A208;
    case 0x8025A20Cu: goto label_8025A20C;
    case 0x8025A210u: goto label_8025A210;
    case 0x8025A214u: goto label_8025A214;
    case 0x8025A218u: goto label_8025A218;
    case 0x8025A21Cu: goto label_8025A21C;
    case 0x8025A220u: goto label_8025A220;
    case 0x8025A224u: goto label_8025A224;
    case 0x8025A228u: goto label_8025A228;
    case 0x8025A22Cu: goto label_8025A22C;
    case 0x8025A230u: goto label_8025A230;
    case 0x8025A234u: goto label_8025A234;
    case 0x8025A238u: goto label_8025A238;
    case 0x8025A23Cu: goto label_8025A23C;
    case 0x8025A240u: goto label_8025A240;
    case 0x8025A244u: goto label_8025A244;
    case 0x8025A248u: goto label_8025A248;
    case 0x8025A24Cu: goto label_8025A24C;
    case 0x8025A250u: goto label_8025A250;
    case 0x8025A254u: goto label_8025A254;
    case 0x8025A258u: goto label_8025A258;
    case 0x8025A25Cu: goto label_8025A25C;
    case 0x8025A260u: goto label_8025A260;
    case 0x8025A264u: goto label_8025A264;
    case 0x8025A268u: goto label_8025A268;
    case 0x8025A26Cu: goto label_8025A26C;
    case 0x8025A270u: goto label_8025A270;
    case 0x8025A274u: goto label_8025A274;
    case 0x8025A278u: goto label_8025A278;
    case 0x8025A27Cu: goto label_8025A27C;
    case 0x8025A280u: goto label_8025A280;
    case 0x8025A284u: goto label_8025A284;
    case 0x8025A288u: goto label_8025A288;
    case 0x8025A28Cu: goto label_8025A28C;
    case 0x8025A290u: goto label_8025A290;
    case 0x8025A294u: goto label_8025A294;
    case 0x8025A298u: goto label_8025A298;
    case 0x8025A29Cu: goto label_8025A29C;
    case 0x8025A2A0u: goto label_8025A2A0;
    case 0x8025A2A4u: goto label_8025A2A4;
    case 0x8025A2A8u: goto label_8025A2A8;
    case 0x8025A2ACu: goto label_8025A2AC;
    case 0x8025A2B0u: goto label_8025A2B0;
    case 0x8025A2B4u: goto label_8025A2B4;
    case 0x8025A2B8u: goto label_8025A2B8;
    case 0x8025A2BCu: goto label_8025A2BC;
    case 0x8025A2C0u: goto label_8025A2C0;
    case 0x8025A2C4u: goto label_8025A2C4;
    case 0x8025A2C8u: goto label_8025A2C8;
    case 0x8025A2CCu: goto label_8025A2CC;
    case 0x8025A2D0u: goto label_8025A2D0;
    case 0x8025A2D4u: goto label_8025A2D4;
    case 0x8025A2D8u: goto label_8025A2D8;
    case 0x8025A2DCu: goto label_8025A2DC;
    case 0x8025A2E0u: goto label_8025A2E0;
    case 0x8025A2E4u: goto label_8025A2E4;
    case 0x8025A2E8u: goto label_8025A2E8;
    case 0x8025A2ECu: goto label_8025A2EC;
    case 0x8025A2F0u: goto label_8025A2F0;
    case 0x8025A2F4u: goto label_8025A2F4;
    case 0x8025A2F8u: goto label_8025A2F8;
    case 0x8025A2FCu: goto label_8025A2FC;
    case 0x8025A300u: goto label_8025A300;
    case 0x8025A304u: goto label_8025A304;
    case 0x8025A308u: goto label_8025A308;
    case 0x8025A30Cu: goto label_8025A30C;
    case 0x8025A310u: goto label_8025A310;
    case 0x8025A314u: goto label_8025A314;
    case 0x8025A318u: goto label_8025A318;
    case 0x8025A31Cu: goto label_8025A31C;
    case 0x8025A320u: goto label_8025A320;
    case 0x8025A324u: goto label_8025A324;
    case 0x8025A328u: goto label_8025A328;
    case 0x8025A32Cu: goto label_8025A32C;
    case 0x8025A330u: goto label_8025A330;
    case 0x8025A334u: goto label_8025A334;
    case 0x8025A338u: goto label_8025A338;
    case 0x8025A33Cu: goto label_8025A33C;
    case 0x8025A340u: goto label_8025A340;
    case 0x8025A344u: goto label_8025A344;
    case 0x8025A348u: goto label_8025A348;
    case 0x8025A34Cu: goto label_8025A34C;
    case 0x8025A350u: goto label_8025A350;
    case 0x8025A354u: goto label_8025A354;
    case 0x8025A358u: goto label_8025A358;
    case 0x8025A35Cu: goto label_8025A35C;
    case 0x8025A360u: goto label_8025A360;
    case 0x8025A364u: goto label_8025A364;
    case 0x8025A368u: goto label_8025A368;
    case 0x8025A36Cu: goto label_8025A36C;
    case 0x8025A370u: goto label_8025A370;
    case 0x8025A374u: goto label_8025A374;
    case 0x8025A378u: goto label_8025A378;
    case 0x8025A37Cu: goto label_8025A37C;
    case 0x8025A380u: goto label_8025A380;
    case 0x8025A384u: goto label_8025A384;
    case 0x8025A388u: goto label_8025A388;
    case 0x8025A38Cu: goto label_8025A38C;
    case 0x8025A390u: goto label_8025A390;
    case 0x8025A394u: goto label_8025A394;
    case 0x8025A398u: goto label_8025A398;
    case 0x8025A39Cu: goto label_8025A39C;
    case 0x8025A3A0u: goto label_8025A3A0;
    case 0x8025A3A4u: goto label_8025A3A4;
    case 0x8025A3A8u: goto label_8025A3A8;
    case 0x8025A3ACu: goto label_8025A3AC;
    case 0x8025A3B0u: goto label_8025A3B0;
    case 0x8025A3B4u: goto label_8025A3B4;
    case 0x8025A3B8u: goto label_8025A3B8;
    case 0x8025A3BCu: goto label_8025A3BC;
    case 0x8025A3C0u: goto label_8025A3C0;
    case 0x8025A3C4u: goto label_8025A3C4;
    case 0x8025A3C8u: goto label_8025A3C8;
    case 0x8025A3CCu: goto label_8025A3CC;
    case 0x8025A3D0u: goto label_8025A3D0;
    case 0x8025A3D4u: goto label_8025A3D4;
    case 0x8025A3D8u: goto label_8025A3D8;
    case 0x8025A3DCu: goto label_8025A3DC;
    case 0x8025A3E0u: goto label_8025A3E0;
    case 0x8025A3E4u: goto label_8025A3E4;
    case 0x8025A3E8u: goto label_8025A3E8;
    case 0x8025A3ECu: goto label_8025A3EC;
    case 0x8025A3F0u: goto label_8025A3F0;
    case 0x8025A3F4u: goto label_8025A3F4;
    case 0x8025A3F8u: goto label_8025A3F8;
    case 0x8025A3FCu: goto label_8025A3FC;
    case 0x8025A400u: goto label_8025A400;
    case 0x8025A404u: goto label_8025A404;
    case 0x8025A408u: goto label_8025A408;
    case 0x8025A40Cu: goto label_8025A40C;
    case 0x8025A410u: goto label_8025A410;
    case 0x8025A414u: goto label_8025A414;
    case 0x8025A418u: goto label_8025A418;
    case 0x8025A41Cu: goto label_8025A41C;
    case 0x8025A420u: goto label_8025A420;
    case 0x8025A424u: goto label_8025A424;
    case 0x8025A428u: goto label_8025A428;
    case 0x8025A42Cu: goto label_8025A42C;
    case 0x8025A430u: goto label_8025A430;
    case 0x8025A434u: goto label_8025A434;
    case 0x8025A438u: goto label_8025A438;
    case 0x8025A43Cu: goto label_8025A43C;
    case 0x8025A440u: goto label_8025A440;
    case 0x8025A444u: goto label_8025A444;
    case 0x8025A448u: goto label_8025A448;
    case 0x8025A44Cu: goto label_8025A44C;
    case 0x8025A450u: goto label_8025A450;
    case 0x8025A454u: goto label_8025A454;
    case 0x8025A458u: goto label_8025A458;
    case 0x8025A45Cu: goto label_8025A45C;
    case 0x8025A460u: goto label_8025A460;
    case 0x8025A464u: goto label_8025A464;
    case 0x8025A468u: goto label_8025A468;
    case 0x8025A46Cu: goto label_8025A46C;
    case 0x8025A470u: goto label_8025A470;
    case 0x8025A474u: goto label_8025A474;
    case 0x8025A478u: goto label_8025A478;
    case 0x8025A47Cu: goto label_8025A47C;
    case 0x8025A480u: goto label_8025A480;
    case 0x8025A484u: goto label_8025A484;
    case 0x8025A488u: goto label_8025A488;
    case 0x8025A48Cu: goto label_8025A48C;
    case 0x8025A490u: goto label_8025A490;
    case 0x8025A494u: goto label_8025A494;
    case 0x8025A498u: goto label_8025A498;
    case 0x8025A49Cu: goto label_8025A49C;
    case 0x8025A4A0u: goto label_8025A4A0;
    case 0x8025A4A4u: goto label_8025A4A4;
    case 0x8025A4A8u: goto label_8025A4A8;
    case 0x8025A4ACu: goto label_8025A4AC;
    case 0x8025A4B0u: goto label_8025A4B0;
    case 0x8025A4B4u: goto label_8025A4B4;
    case 0x8025A4B8u: goto label_8025A4B8;
    case 0x8025A4BCu: goto label_8025A4BC;
    case 0x8025A4C0u: goto label_8025A4C0;
    case 0x8025A4C4u: goto label_8025A4C4;
    case 0x8025A4C8u: goto label_8025A4C8;
    case 0x8025A4CCu: goto label_8025A4CC;
    case 0x8025A4D0u: goto label_8025A4D0;
    case 0x8025A4D4u: goto label_8025A4D4;
    case 0x8025A4D8u: goto label_8025A4D8;
    case 0x8025A4DCu: goto label_8025A4DC;
    case 0x8025A4E0u: goto label_8025A4E0;
    case 0x8025A4E4u: goto label_8025A4E4;
    case 0x8025A4E8u: goto label_8025A4E8;
    case 0x8025A4ECu: goto label_8025A4EC;
    case 0x8025A4F0u: goto label_8025A4F0;
    case 0x8025A4F4u: goto label_8025A4F4;
    case 0x8025A4F8u: goto label_8025A4F8;
    case 0x8025A4FCu: goto label_8025A4FC;
    case 0x8025A500u: goto label_8025A500;
    case 0x8025A504u: goto label_8025A504;
    case 0x8025A508u: goto label_8025A508;
    case 0x8025A50Cu: goto label_8025A50C;
    case 0x8025A510u: goto label_8025A510;
    case 0x8025A514u: goto label_8025A514;
    case 0x8025A518u: goto label_8025A518;
    case 0x8025A51Cu: goto label_8025A51C;
    case 0x8025A520u: goto label_8025A520;
    case 0x8025A524u: goto label_8025A524;
    case 0x8025A528u: goto label_8025A528;
    case 0x8025A52Cu: goto label_8025A52C;
    case 0x8025A530u: goto label_8025A530;
    case 0x8025A534u: goto label_8025A534;
    case 0x8025A538u: goto label_8025A538;
    case 0x8025A53Cu: goto label_8025A53C;
    case 0x8025A540u: goto label_8025A540;
    case 0x8025A544u: goto label_8025A544;
    case 0x8025A548u: goto label_8025A548;
    case 0x8025A54Cu: goto label_8025A54C;
    case 0x8025A550u: goto label_8025A550;
    case 0x8025A554u: goto label_8025A554;
    case 0x8025A558u: goto label_8025A558;
    case 0x8025A55Cu: goto label_8025A55C;
    case 0x8025A560u: goto label_8025A560;
    case 0x8025A564u: goto label_8025A564;
    case 0x8025A568u: goto label_8025A568;
    case 0x8025A56Cu: goto label_8025A56C;
    case 0x8025A570u: goto label_8025A570;
    case 0x8025A574u: goto label_8025A574;
    case 0x8025A578u: goto label_8025A578;
    case 0x8025A57Cu: goto label_8025A57C;
    case 0x8025A580u: goto label_8025A580;
    case 0x8025A584u: goto label_8025A584;
    case 0x8025A588u: goto label_8025A588;
    case 0x8025A58Cu: goto label_8025A58C;
    case 0x8025A590u: goto label_8025A590;
    case 0x8025A594u: goto label_8025A594;
    case 0x8025A598u: goto label_8025A598;
    case 0x8025A59Cu: goto label_8025A59C;
    case 0x8025A5A0u: goto label_8025A5A0;
    case 0x8025A5A4u: goto label_8025A5A4;
    case 0x8025A5A8u: goto label_8025A5A8;
    case 0x8025A5ACu: goto label_8025A5AC;
    case 0x8025A5B0u: goto label_8025A5B0;
    case 0x8025A5B4u: goto label_8025A5B4;
    case 0x8025A5B8u: goto label_8025A5B8;
    case 0x8025A5BCu: goto label_8025A5BC;
    case 0x8025A5C0u: goto label_8025A5C0;
    case 0x8025A5C4u: goto label_8025A5C4;
    case 0x8025A5C8u: goto label_8025A5C8;
    case 0x8025A5CCu: goto label_8025A5CC;
    case 0x8025A5D0u: goto label_8025A5D0;
    case 0x8025A5D4u: goto label_8025A5D4;
    case 0x8025A5D8u: goto label_8025A5D8;
    case 0x8025A5DCu: goto label_8025A5DC;
    case 0x8025A5E0u: goto label_8025A5E0;
    case 0x8025A5E4u: goto label_8025A5E4;
    case 0x8025A5E8u: goto label_8025A5E8;
    case 0x8025A5ECu: goto label_8025A5EC;
    case 0x8025A5F0u: goto label_8025A5F0;
    case 0x8025A5F4u: goto label_8025A5F4;
    case 0x8025A5F8u: goto label_8025A5F8;
    case 0x8025A5FCu: goto label_8025A5FC;
    case 0x8025A600u: goto label_8025A600;
    case 0x8025A604u: goto label_8025A604;
    case 0x8025A608u: goto label_8025A608;
    case 0x8025A60Cu: goto label_8025A60C;
    case 0x8025A610u: goto label_8025A610;
    case 0x8025A614u: goto label_8025A614;
    case 0x8025A618u: goto label_8025A618;
    case 0x8025A61Cu: goto label_8025A61C;
    case 0x8025A620u: goto label_8025A620;
    case 0x8025A624u: goto label_8025A624;
    case 0x8025A628u: goto label_8025A628;
    case 0x8025A62Cu: goto label_8025A62C;
    case 0x8025A630u: goto label_8025A630;
    case 0x8025A634u: goto label_8025A634;
    case 0x8025A638u: goto label_8025A638;
    case 0x8025A63Cu: goto label_8025A63C;
    case 0x8025A640u: goto label_8025A640;
    case 0x8025A644u: goto label_8025A644;
    case 0x8025A648u: goto label_8025A648;
    case 0x8025A64Cu: goto label_8025A64C;
    case 0x8025A650u: goto label_8025A650;
    case 0x8025A654u: goto label_8025A654;
    case 0x8025A658u: goto label_8025A658;
    case 0x8025A65Cu: goto label_8025A65C;
    case 0x8025A660u: goto label_8025A660;
    case 0x8025A664u: goto label_8025A664;
    case 0x8025A668u: goto label_8025A668;
    case 0x8025A66Cu: goto label_8025A66C;
    case 0x8025A670u: goto label_8025A670;
    case 0x8025A674u: goto label_8025A674;
    case 0x8025A678u: goto label_8025A678;
    case 0x8025A67Cu: goto label_8025A67C;
    case 0x8025A680u: goto label_8025A680;
    case 0x8025A684u: goto label_8025A684;
    case 0x8025A688u: goto label_8025A688;
    case 0x8025A68Cu: goto label_8025A68C;
    case 0x8025A690u: goto label_8025A690;
    case 0x8025A694u: goto label_8025A694;
    case 0x8025A698u: goto label_8025A698;
    case 0x8025A69Cu: goto label_8025A69C;
    case 0x8025A6A0u: goto label_8025A6A0;
    case 0x8025A6A4u: goto label_8025A6A4;
    case 0x8025A6A8u: goto label_8025A6A8;
    case 0x8025A6ACu: goto label_8025A6AC;
    case 0x8025A6B0u: goto label_8025A6B0;
    case 0x8025A6B4u: goto label_8025A6B4;
    case 0x8025A6B8u: goto label_8025A6B8;
    case 0x8025A6BCu: goto label_8025A6BC;
    case 0x8025A6C0u: goto label_8025A6C0;
    case 0x8025A6C4u: goto label_8025A6C4;
    case 0x8025A6C8u: goto label_8025A6C8;
    case 0x8025A6CCu: goto label_8025A6CC;
    case 0x8025A6D0u: goto label_8025A6D0;
    case 0x8025A6D4u: goto label_8025A6D4;
    case 0x8025A6D8u: goto label_8025A6D8;
    case 0x8025A6DCu: goto label_8025A6DC;
    default: return;
    }
label_802566E0:
    ctx->pc = 0x802566E0u;
    ctx->downcount -= 2;
    // 802566E0: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802566E4:
    ctx->pc = 0x802566E4u;
    // 802566E4: bl      0x80258E8C
    {
            ctx->lr = 0x802566E8u;
            goto label_80258E8C;
    }

label_802566E8:
    ctx->pc = 0x802566E8u;
    ctx->downcount -= 3;
    // 802566E8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802566EC:
    ctx->pc = 0x802566ECu;
    // 802566EC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802566F0:
    ctx->pc = 0x802566F0u;
    // 802566F0: bl      0x80258F60
    {
            ctx->lr = 0x802566F4u;
            goto label_80258F60;
    }

label_802566F4:
    ctx->pc = 0x802566F4u;
    ctx->downcount -= 4;
    // 802566F4: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802566F8:
    ctx->pc = 0x802566F8u;
    // 802566F8: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_802566FC:
    ctx->pc = 0x802566FCu;
    // 802566FC: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80256700:
    ctx->pc = 0x80256700u;
    // 80256700: bl      0x80258F90
    {
            ctx->lr = 0x80256704u;
            goto label_80258F90;
    }

label_80256704:
    ctx->pc = 0x80256704u;
    ctx->downcount -= 3;
    // 80256704: li      r3, 35
    ctx->gpr[3] = (u32)(s32)(35);

label_80256708:
    ctx->pc = 0x80256708u;
    // 80256708: li      r4, 22
    ctx->gpr[4] = (u32)(s32)(22);

label_8025670C:
    ctx->pc = 0x8025670Cu;
    // 8025670C: bl      0x8025DE84
    {
            ctx->lr = 0x80256710u;
            ctx->pc = 0x8025DE84u;
            return;
    }

label_80256710:
    ctx->pc = 0x80256710u;
    ctx->downcount -= 1;
    // 80256710: bl      0x8025E71C
    {
            ctx->lr = 0x80256714u;
            ctx->pc = 0x8025E71Cu;
            return;
    }

label_80256714:
    ctx->pc = 0x80256714u;
    ctx->downcount -= 7;
    // 80256714: lwz     r0, 124(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(124);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256718:
    ctx->pc = 0x80256718u;
    // 80256718: lwz     r31, 116(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(116);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8025671C:
    ctx->pc = 0x8025671Cu;
    // 8025671C: lwz     r30, 112(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(112);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80256720:
    ctx->pc = 0x80256720u;
    // 80256720: addi    r1, r1, 120
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(120);

label_80256724:
    ctx->pc = 0x80256724u;
    // 80256724: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80256728:
    ctx->pc = 0x80256728u;
    // 80256728: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_8025672C:
    ctx->pc = 0x8025672Cu;
    ctx->downcount -= 13;
    // 8025672C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80256730:
    ctx->pc = 0x80256730u;
    // 80256730: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256734:
    ctx->pc = 0x80256734u;
    // 80256734: stwu     r1, -736(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-736);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80256738:
    ctx->pc = 0x80256738u;
    // 80256738: stw     r31, 732(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(732);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8025673C:
    ctx->pc = 0x8025673Cu;
    // 8025673C: or   r31, r4, r4
    {
        ctx->gpr[31] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80256740:
    ctx->pc = 0x80256740u;
    // 80256740: lwz     r5, -20700(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20700);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80256744:
    ctx->pc = 0x80256744u;
    // 80256744: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256748:
    ctx->pc = 0x80256748u;
    // 80256748: lhz     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8025674C:
    ctx->pc = 0x8025674Cu;
    // 8025674C: stw     r0, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256750:
    ctx->pc = 0x80256750u;
    // 80256750: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256754:
    ctx->pc = 0x80256754u;
    // 80256754: lwz     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256758:
    ctx->pc = 0x80256758u;
    // 80256758: rlwinm. r0, r0, 29, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 29u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8025675C:
    ctx->pc = 0x8025675Cu;
    // 8025675C: bc    12, 2, 0x80256794
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80256794;
        }
    }

label_80256760:
    ctx->pc = 0x80256760u;
    ctx->downcount -= 3;
    // 80256760: lwz     r0, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256764:
    ctx->pc = 0x80256764u;
    // 80256764: rlwinm. r0, r0, 31, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80256768:
    ctx->pc = 0x80256768u;
    // 80256768: bc    12, 2, 0x80256794
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80256794;
        }
    }

label_8025676C:
    ctx->pc = 0x8025676Cu;
    ctx->downcount -= 2;
    // 8025676C: lwz     r3, -20680(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20680);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256770:
    ctx->pc = 0x80256770u;
    // 80256770: bl      0x80247014
    {
            ctx->lr = 0x80256774u;
            ctx->pc = 0x80247014u;
            return;
    }

label_80256774:
    ctx->pc = 0x80256774u;
    ctx->downcount -= 5;
    // 80256774: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80256778:
    ctx->pc = 0x80256778u;
    // 80256778: stw     r0, -20672(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20672);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8025677C:
    ctx->pc = 0x8025677Cu;
    // 8025677C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80256780:
    ctx->pc = 0x80256780u;
    // 80256780: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80256784:
    ctx->pc = 0x80256784u;
    // 80256784: bl      0x80257038
    {
            ctx->lr = 0x80256788u;
            goto label_80257038;
    }

label_80256788:
    ctx->pc = 0x80256788u;
    ctx->downcount -= 3;
    // 80256788: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8025678C:
    ctx->pc = 0x8025678Cu;
    // 8025678C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80256790:
    ctx->pc = 0x80256790u;
    // 80256790: bl      0x80256FEC
    {
            ctx->lr = 0x80256794u;
            goto label_80256FEC;
    }

label_80256794:
    ctx->pc = 0x80256794u;
    ctx->downcount -= 4;
    // 80256794: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256798:
    ctx->pc = 0x80256798u;
    // 80256798: lwz     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8025679C:
    ctx->pc = 0x8025679Cu;
    // 8025679C: rlwinm. r0, r0, 30, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 30u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802567A0:
    ctx->pc = 0x802567A0u;
    // 802567A0: bc    12, 2, 0x802567E4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802567E4;
        }
    }

label_802567A4:
    ctx->pc = 0x802567A4u;
    ctx->downcount -= 3;
    // 802567A4: lwz     r0, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802567A8:
    ctx->pc = 0x802567A8u;
    // 802567A8: rlwinm. r0, r0, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802567AC:
    ctx->pc = 0x802567ACu;
    // 802567AC: bc    12, 2, 0x802567E4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802567E4;
        }
    }

label_802567B0:
    ctx->pc = 0x802567B0u;
    ctx->downcount -= 6;
    // 802567B0: lwz     r5, -20664(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20664);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802567B4:
    ctx->pc = 0x802567B4u;
    // 802567B4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802567B8:
    ctx->pc = 0x802567B8u;
    // 802567B8: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_802567BC:
    ctx->pc = 0x802567BCu;
    // 802567BC: addi    r0, r5, 1
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(1);

label_802567C0:
    ctx->pc = 0x802567C0u;
    // 802567C0: stw     r0, -20664(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20664);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802567C4:
    ctx->pc = 0x802567C4u;
    // 802567C4: bl      0x80256FEC
    {
            ctx->lr = 0x802567C8u;
            goto label_80256FEC;
    }

label_802567C8:
    ctx->pc = 0x802567C8u;
    ctx->downcount -= 3;
    // 802567C8: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802567CC:
    ctx->pc = 0x802567CCu;
    // 802567CC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802567D0:
    ctx->pc = 0x802567D0u;
    // 802567D0: bl      0x80257038
    {
            ctx->lr = 0x802567D4u;
            goto label_80257038;
    }

label_802567D4:
    ctx->pc = 0x802567D4u;
    ctx->downcount -= 4;
    // 802567D4: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_802567D8:
    ctx->pc = 0x802567D8u;
    // 802567D8: lwz     r3, -20680(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20680);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802567DC:
    ctx->pc = 0x802567DCu;
    // 802567DC: stw     r0, -20672(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20672);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802567E0:
    ctx->pc = 0x802567E0u;
    // 802567E0: bl      0x8024729C
    {
            ctx->lr = 0x802567E4u;
            ctx->pc = 0x8024729Cu;
            return;
    }

label_802567E4:
    ctx->pc = 0x802567E4u;
    ctx->downcount -= 5;
    // 802567E4: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802567E8:
    ctx->pc = 0x802567E8u;
    // 802567E8: lwz     r4, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802567EC:
    ctx->pc = 0x802567ECu;
    // 802567EC: addi    r5, r3, 8
    ctx->gpr[5] = ctx->gpr[3] + (u32)(s32)(8);

label_802567F0:
    ctx->pc = 0x802567F0u;
    // 802567F0: rlwinm. r0, r4, 27, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 27u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802567F4:
    ctx->pc = 0x802567F4u;
    // 802567F4: bc    12, 2, 0x80256854
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80256854;
        }
    }

label_802567F8:
    ctx->pc = 0x802567F8u;
    ctx->downcount -= 3;
    // 802567F8: lwz     r0, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802567FC:
    ctx->pc = 0x802567FCu;
    // 802567FC: rlwinm. r0, r0, 28, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 28u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80256800:
    ctx->pc = 0x80256800u;
    // 80256800: bc    12, 2, 0x80256854
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80256854;
        }
    }

label_80256804:
    ctx->pc = 0x80256804u;
    ctx->downcount -= 9;
    // 80256804: rlwinm r0, r4, 0, 27, 25
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFFDFu;
    }

label_80256808:
    ctx->pc = 0x80256808u;
    // 80256808: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8025680C:
    ctx->pc = 0x8025680Cu;
    // 8025680C: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80256810:
    ctx->pc = 0x80256810u;
    // 80256810: lwz     r3, -20700(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20700);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256814:
    ctx->pc = 0x80256814u;
    // 80256814: lwz     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256818:
    ctx->pc = 0x80256818u;
    // 80256818: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8025681C:
    ctx->pc = 0x8025681Cu;
    // 8025681C: lwz     r0, -20668(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20668);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256820:
    ctx->pc = 0x80256820u;
    // 80256820: cmplwi  r0, 0x0000
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

label_80256824:
    ctx->pc = 0x80256824u;
    // 80256824: bc    12, 2, 0x80256854
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80256854;
        }
    }

label_80256828:
    ctx->pc = 0x80256828u;
    ctx->downcount -= 2;
    // 80256828: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_8025682C:
    ctx->pc = 0x8025682Cu;
    // 8025682C: bl      0x80242DB4
    {
            ctx->lr = 0x80256830u;
            ctx->pc = 0x80242DB4u;
            return;
    }

label_80256830:
    ctx->pc = 0x80256830u;
    ctx->downcount -= 2;
    // 80256830: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_80256834:
    ctx->pc = 0x80256834u;
    // 80256834: bl      0x80242BEC
    {
            ctx->lr = 0x80256838u;
            ctx->pc = 0x80242BECu;
            return;
    }

label_80256838:
    ctx->pc = 0x80256838u;
    ctx->downcount -= 4;
    // 80256838: lwz     r12, -20668(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20668);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_8025683C:
    ctx->pc = 0x8025683Cu;
    // 8025683C: mtlr    r12
    ctx->lr = ctx->gpr[12];

label_80256840:
    ctx->pc = 0x80256840u;
    // 80256840: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80256844u;
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80256844:
    ctx->pc = 0x80256844u;
    ctx->downcount -= 2;
    // 80256844: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_80256848:
    ctx->pc = 0x80256848u;
    // 80256848: bl      0x80242DB4
    {
            ctx->lr = 0x8025684Cu;
            ctx->pc = 0x80242DB4u;
            return;
    }

label_8025684C:
    ctx->pc = 0x8025684Cu;
    ctx->downcount -= 2;
    // 8025684C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80256850:
    ctx->pc = 0x80256850u;
    // 80256850: bl      0x80242BEC
    {
            ctx->lr = 0x80256854u;
            ctx->pc = 0x80242BECu;
            return;
    }

label_80256854:
    ctx->pc = 0x80256854u;
    ctx->downcount -= 6;
    // 80256854: lwz     r0, 740(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(740);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256858:
    ctx->pc = 0x80256858u;
    // 80256858: lwz     r31, 732(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(732);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8025685C:
    ctx->pc = 0x8025685Cu;
    // 8025685C: addi    r1, r1, 736
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(736);

label_80256860:
    ctx->pc = 0x80256860u;
    // 80256860: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80256864:
    ctx->pc = 0x80256864u;
    // 80256864: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80256868:
    ctx->pc = 0x80256868u;
    ctx->downcount -= 17;
    // 80256868: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8025686C:
    ctx->pc = 0x8025686Cu;
    // 8025686C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256870:
    ctx->pc = 0x80256870u;
    // 80256870: addi    r0, r5, -4
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(-4);

label_80256874:
    ctx->pc = 0x80256874u;
    // 80256874: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80256878:
    ctx->pc = 0x80256878u;
    // 80256878: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8025687C:
    ctx->pc = 0x8025687Cu;
    // 8025687C: addi    r31, r4, 0
    ctx->gpr[31] = ctx->gpr[4] + (u32)(s32)(0);

label_80256880:
    ctx->pc = 0x80256880u;
    // 80256880: add   r0, r31, r0
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80256884:
    ctx->pc = 0x80256884u;
    // 80256884: stw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80256888:
    ctx->pc = 0x80256888u;
    // 80256888: addi    r30, r3, 0
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(0);

label_8025688C:
    ctx->pc = 0x8025688Cu;
    // 8025688C: addi    r4, r5, -16384
    ctx->gpr[4] = ctx->gpr[5] + (u32)(s32)(-16384);

label_80256890:
    ctx->pc = 0x80256890u;
    // 80256890: stw     r31, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80256894:
    ctx->pc = 0x80256894u;
    // 80256894: stw     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256898:
    ctx->pc = 0x80256898u;
    // 80256898: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8025689C:
    ctx->pc = 0x8025689Cu;
    // 8025689C: stw     r5, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_802568A0:
    ctx->pc = 0x802568A0u;
    // 802568A0: rlwinm r5, r5, 31, 1, 26
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 31u) & 0x7FFFFFE0u;
    }

label_802568A4:
    ctx->pc = 0x802568A4u;
    // 802568A4: stw     r0, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802568A8:
    ctx->pc = 0x802568A8u;
    // 802568A8: bl      0x80256944
    {
            ctx->lr = 0x802568ACu;
            goto label_80256944;
    }

label_802568AC:
    ctx->pc = 0x802568ACu;
    ctx->downcount -= 4;
    // 802568AC: addi    r3, r30, 0
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(0);

label_802568B0:
    ctx->pc = 0x802568B0u;
    // 802568B0: addi    r4, r31, 0
    ctx->gpr[4] = ctx->gpr[31] + (u32)(s32)(0);

label_802568B4:
    ctx->pc = 0x802568B4u;
    // 802568B4: addi    r5, r31, 0
    ctx->gpr[5] = ctx->gpr[31] + (u32)(s32)(0);

label_802568B8:
    ctx->pc = 0x802568B8u;
    // 802568B8: bl      0x802568D4
    {
            ctx->lr = 0x802568BCu;
            goto label_802568D4;
    }

label_802568BC:
    ctx->pc = 0x802568BCu;
    ctx->downcount -= 7;
    // 802568BC: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802568C0:
    ctx->pc = 0x802568C0u;
    // 802568C0: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802568C4:
    ctx->pc = 0x802568C4u;
    // 802568C4: lwz     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_802568C8:
    ctx->pc = 0x802568C8u;
    // 802568C8: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_802568CC:
    ctx->pc = 0x802568CCu;
    // 802568CC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802568D0:
    ctx->pc = 0x802568D0u;
    // 802568D0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_802568D4:
    ctx->pc = 0x802568D4u;
    ctx->downcount -= 10;
    // 802568D4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802568D8:
    ctx->pc = 0x802568D8u;
    // 802568D8: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802568DC:
    ctx->pc = 0x802568DCu;
    // 802568DC: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802568E0:
    ctx->pc = 0x802568E0u;
    // 802568E0: stw     r31, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_802568E4:
    ctx->pc = 0x802568E4u;
    // 802568E4: addi    r31, r5, 0
    ctx->gpr[31] = ctx->gpr[5] + (u32)(s32)(0);

label_802568E8:
    ctx->pc = 0x802568E8u;
    // 802568E8: stw     r30, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_802568EC:
    ctx->pc = 0x802568ECu;
    // 802568EC: addi    r30, r4, 0
    ctx->gpr[30] = ctx->gpr[4] + (u32)(s32)(0);

label_802568F0:
    ctx->pc = 0x802568F0u;
    // 802568F0: stw     r29, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_802568F4:
    ctx->pc = 0x802568F4u;
    // 802568F4: addi    r29, r3, 0
    ctx->gpr[29] = ctx->gpr[3] + (u32)(s32)(0);

label_802568F8:
    ctx->pc = 0x802568F8u;
    // 802568F8: bl      0x802440BC
    {
            ctx->lr = 0x802568FCu;
            ctx->pc = 0x802440BCu;
            return;
    }

label_802568FC:
    ctx->pc = 0x802568FCu;
    ctx->downcount -= 7;
    // 802568FC: stw     r30, 20(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80256900:
    ctx->pc = 0x80256900u;
    // 80256900: subf   r0, r30, r31
    {
        u32 a = ~ctx->gpr[30];
        u32 b = ctx->gpr[31];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80256904:
    ctx->pc = 0x80256904u;
    // 80256904: stw     r31, 24(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80256908:
    ctx->pc = 0x80256908u;
    // 80256908: stw     r0, 28(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8025690C:
    ctx->pc = 0x8025690Cu;
    // 8025690C: lwz     r4, 28(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(28);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80256910:
    ctx->pc = 0x80256910u;
    // 80256910: cmpwi   r4, 0
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

label_80256914:
    ctx->pc = 0x80256914u;
    // 80256914: bc    4, 0, 0x80256924
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80256924;
        }
    }

label_80256918:
    ctx->pc = 0x80256918u;
    ctx->downcount -= 3;
    // 80256918: lwz     r0, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8025691C:
    ctx->pc = 0x8025691Cu;
    // 8025691C: add   r0, r4, r0
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80256920:
    ctx->pc = 0x80256920u;
    // 80256920: stw     r0, 28(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256924:
    ctx->pc = 0x80256924u;
    ctx->downcount -= 1;
    // 80256924: bl      0x802440E4
    {
            ctx->lr = 0x80256928u;
            ctx->pc = 0x802440E4u;
            return;
    }

label_80256928:
    ctx->pc = 0x80256928u;
    ctx->downcount -= 8;
    // 80256928: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8025692C:
    ctx->pc = 0x8025692Cu;
    // 8025692C: lwz     r31, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80256930:
    ctx->pc = 0x80256930u;
    // 80256930: lwz     r30, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80256934:
    ctx->pc = 0x80256934u;
    // 80256934: lwz     r29, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80256938:
    ctx->pc = 0x80256938u;
    // 80256938: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_8025693C:
    ctx->pc = 0x8025693Cu;
    // 8025693C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80256940:
    ctx->pc = 0x80256940u;
    // 80256940: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80256944:
    ctx->pc = 0x80256944u;
    ctx->downcount -= 3;
    // 80256944: stw     r4, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80256948:
    ctx->pc = 0x80256948u;
    // 80256948: stw     r5, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8025694C:
    ctx->pc = 0x8025694Cu;
    // 8025694C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80256950:
    ctx->pc = 0x80256950u;
    ctx->downcount -= 7;
    // 80256950: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80256954:
    ctx->pc = 0x80256954u;
    // 80256954: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256958:
    ctx->pc = 0x80256958u;
    // 80256958: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8025695C:
    ctx->pc = 0x8025695Cu;
    // 8025695C: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80256960:
    ctx->pc = 0x80256960u;
    // 80256960: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80256964:
    ctx->pc = 0x80256964u;
    // 80256964: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80256968:
    ctx->pc = 0x80256968u;
    // 80256968: bl      0x802440BC
    {
            ctx->lr = 0x8025696Cu;
            ctx->pc = 0x802440BCu;
            return;
    }

label_8025696C:
    ctx->pc = 0x8025696Cu;
    ctx->downcount -= 5;
    // 8025696C: lwz     r0, -20684(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20684);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256970:
    ctx->pc = 0x80256970u;
    // 80256970: addi    r31, r3, 0
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(0);

label_80256974:
    ctx->pc = 0x80256974u;
    // 80256974: stw     r30, -20688(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20688);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80256978:
    ctx->pc = 0x80256978u;
    // 80256978: cmplw   r30, r0
    {
        u32 val_a = (u32)(ctx->gpr[30]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8025697C:
    ctx->pc = 0x8025697Cu;
    // 8025697C: bc    4, 2, 0x802569E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802569E0;
        }
    }

label_80256980:
    ctx->pc = 0x80256980u;
    ctx->downcount -= 18;
    // 80256980: lwz     r5, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80256984:
    ctx->pc = 0x80256984u;
    // 80256984: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80256988:
    ctx->pc = 0x80256988u;
    // 80256988: lwz     r4, -20704(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20704);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8025698C:
    ctx->pc = 0x8025698Cu;
    // 8025698C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80256990:
    ctx->pc = 0x80256990u;
    // 80256990: rlwinm r5, r5, 0, 2, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x3FFFFFFFu;
    }

label_80256994:
    ctx->pc = 0x80256994u;
    // 80256994: stw     r5, 12(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80256998:
    ctx->pc = 0x80256998u;
    // 80256998: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8025699C:
    ctx->pc = 0x8025699Cu;
    // 8025699C: lwz     r6, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802569A0:
    ctx->pc = 0x802569A0u;
    // 802569A0: lwz     r5, -20704(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20704);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802569A4:
    ctx->pc = 0x802569A4u;
    // 802569A4: rlwinm r6, r6, 0, 2, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x3FFFFFFFu;
    }

label_802569A8:
    ctx->pc = 0x802569A8u;
    // 802569A8: stw     r6, 16(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_802569AC:
    ctx->pc = 0x802569ACu;
    // 802569AC: lwz     r6, 24(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(24);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802569B0:
    ctx->pc = 0x802569B0u;
    // 802569B0: lwz     r5, -20704(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20704);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802569B4:
    ctx->pc = 0x802569B4u;
    // 802569B4: rlwinm r6, r6, 0, 2, 26
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x3FFFFFE0u;
    }

label_802569B8:
    ctx->pc = 0x802569B8u;
    // 802569B8: rlwinm r6, r6, 0, 6, 4
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFBFFFFFFu;
    }

label_802569BC:
    ctx->pc = 0x802569BCu;
    // 802569BC: stw     r6, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_802569C0:
    ctx->pc = 0x802569C0u;
    // 802569C0: stb     r0, -20676(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20676);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802569C4:
    ctx->pc = 0x802569C4u;
    // 802569C4: bl      0x80257038
    {
            ctx->lr = 0x802569C8u;
            goto label_80257038;
    }

label_802569C8:
    ctx->pc = 0x802569C8u;
    ctx->downcount -= 3;
    // 802569C8: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802569CC:
    ctx->pc = 0x802569CCu;
    // 802569CC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802569D0:
    ctx->pc = 0x802569D0u;
    // 802569D0: bl      0x80256FEC
    {
            ctx->lr = 0x802569D4u;
            goto label_80256FEC;
    }

label_802569D4:
    ctx->pc = 0x802569D4u;
    ctx->downcount -= 2;
    // 802569D4: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802569D8:
    ctx->pc = 0x802569D8u;
    // 802569D8: bl      0x80256FA8
    {
            ctx->lr = 0x802569DCu;
            goto label_80256FA8;
    }

label_802569DC:
    ctx->pc = 0x802569DCu;
    ctx->downcount -= 1;
    // 802569DC: b       0x80256A3C
    {
            goto label_80256A3C;
    }

label_802569E0:
    ctx->pc = 0x802569E0u;
    ctx->downcount -= 3;
    // 802569E0: lbz     r0, -20676(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20676);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_802569E4:
    ctx->pc = 0x802569E4u;
    // 802569E4: cmplwi  r0, 0x0000
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

label_802569E8:
    ctx->pc = 0x802569E8u;
    // 802569E8: bc    12, 2, 0x802569FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802569FC;
        }
    }

label_802569EC:
    ctx->pc = 0x802569ECu;
    ctx->downcount -= 2;
    // 802569EC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802569F0:
    ctx->pc = 0x802569F0u;
    // 802569F0: bl      0x80256FA8
    {
            ctx->lr = 0x802569F4u;
            goto label_80256FA8;
    }

label_802569F4:
    ctx->pc = 0x802569F4u;
    ctx->downcount -= 2;
    // 802569F4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802569F8:
    ctx->pc = 0x802569F8u;
    // 802569F8: stb     r0, -20676(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20676);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802569FC:
    ctx->pc = 0x802569FCu;
    ctx->downcount -= 3;
    // 802569FC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80256A00:
    ctx->pc = 0x80256A00u;
    // 80256A00: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80256A04:
    ctx->pc = 0x80256A04u;
    // 80256A04: bl      0x80256FEC
    {
            ctx->lr = 0x80256A08u;
            goto label_80256FEC;
    }

label_80256A08:
    ctx->pc = 0x80256A08u;
    ctx->downcount -= 13;
    // 80256A08: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256A0C:
    ctx->pc = 0x80256A0Cu;
    // 80256A0C: lwz     r3, -20704(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20704);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256A10:
    ctx->pc = 0x80256A10u;
    // 80256A10: rlwinm r0, r0, 0, 2, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x3FFFFFFFu;
    }

label_80256A14:
    ctx->pc = 0x80256A14u;
    // 80256A14: stw     r0, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256A18:
    ctx->pc = 0x80256A18u;
    // 80256A18: lwz     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256A1C:
    ctx->pc = 0x80256A1Cu;
    // 80256A1C: lwz     r3, -20704(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20704);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256A20:
    ctx->pc = 0x80256A20u;
    // 80256A20: rlwinm r0, r0, 0, 2, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x3FFFFFFFu;
    }

label_80256A24:
    ctx->pc = 0x80256A24u;
    // 80256A24: stw     r0, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256A28:
    ctx->pc = 0x80256A28u;
    // 80256A28: lwz     r0, 24(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256A2C:
    ctx->pc = 0x80256A2Cu;
    // 80256A2C: lwz     r3, -20704(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20704);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256A30:
    ctx->pc = 0x80256A30u;
    // 80256A30: rlwinm r0, r0, 0, 2, 26
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x3FFFFFE0u;
    }

label_80256A34:
    ctx->pc = 0x80256A34u;
    // 80256A34: rlwinm r0, r0, 0, 6, 4
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFBFFFFFFu;
    }

label_80256A38:
    ctx->pc = 0x80256A38u;
    // 80256A38: stw     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256A3C:
    ctx->pc = 0x80256A3Cu;
    ctx->downcount -= 5;
    // 80256A3C: sync
    ppc_memory_fence();

label_80256A40:
    ctx->pc = 0x80256A40u;
    // 80256A40: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80256A44:
    ctx->pc = 0x80256A44u;
    // 80256A44: bl      0x802440E4
    {
            ctx->lr = 0x80256A48u;
            ctx->pc = 0x802440E4u;
            return;
    }

label_80256A48:
    ctx->pc = 0x80256A48u;
    ctx->downcount -= 7;
    // 80256A48: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256A4C:
    ctx->pc = 0x80256A4Cu;
    // 80256A4C: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80256A50:
    ctx->pc = 0x80256A50u;
    // 80256A50: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80256A54:
    ctx->pc = 0x80256A54u;
    // 80256A54: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80256A58:
    ctx->pc = 0x80256A58u;
    // 80256A58: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80256A5C:
    ctx->pc = 0x80256A5Cu;
    // 80256A5C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80256A60:
    ctx->pc = 0x80256A60u;
    ctx->downcount -= 7;
    // 80256A60: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80256A64:
    ctx->pc = 0x80256A64u;
    // 80256A64: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256A68:
    ctx->pc = 0x80256A68u;
    // 80256A68: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80256A6C:
    ctx->pc = 0x80256A6Cu;
    // 80256A6C: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80256A70:
    ctx->pc = 0x80256A70u;
    // 80256A70: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80256A74:
    ctx->pc = 0x80256A74u;
    // 80256A74: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80256A78:
    ctx->pc = 0x80256A78u;
    // 80256A78: bl      0x802440BC
    {
            ctx->lr = 0x80256A7Cu;
            ctx->pc = 0x802440BCu;
            return;
    }

label_80256A7C:
    ctx->pc = 0x80256A7Cu;
    ctx->downcount -= 2;
    // 80256A7C: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80256A80:
    ctx->pc = 0x80256A80u;
    // 80256A80: bl      0x80256F84
    {
            ctx->lr = 0x80256A84u;
            goto label_80256F84;
    }

label_80256A84:
    ctx->pc = 0x80256A84u;
    ctx->downcount -= 3;
    // 80256A84: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80256A88:
    ctx->pc = 0x80256A88u;
    // 80256A88: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80256A8C:
    ctx->pc = 0x80256A8Cu;
    // 80256A8C: bl      0x80256FEC
    {
            ctx->lr = 0x80256A90u;
            goto label_80256FEC;
    }

label_80256A90:
    ctx->pc = 0x80256A90u;
    ctx->downcount -= 57;
    // 80256A90: stw     r30, -20684(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20684);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80256A94:
    ctx->pc = 0x80256A94u;
    // 80256A94: lwz     r3, -20700(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20700);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256A98:
    ctx->pc = 0x80256A98u;
    // 80256A98: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256A9C:
    ctx->pc = 0x80256A9Cu;
    // 80256A9C: sth     r0, 32(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(32);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80256AA0:
    ctx->pc = 0x80256AA0u;
    // 80256AA0: lwz     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256AA4:
    ctx->pc = 0x80256AA4u;
    // 80256AA4: lwz     r3, -20700(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20700);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256AA8:
    ctx->pc = 0x80256AA8u;
    // 80256AA8: sth     r0, 36(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(36);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80256AAC:
    ctx->pc = 0x80256AACu;
    // 80256AAC: lwz     r0, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256AB0:
    ctx->pc = 0x80256AB0u;
    // 80256AB0: lwz     r3, -20700(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20700);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256AB4:
    ctx->pc = 0x80256AB4u;
    // 80256AB4: sth     r0, 48(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(48);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80256AB8:
    ctx->pc = 0x80256AB8u;
    // 80256AB8: lwz     r0, 24(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256ABC:
    ctx->pc = 0x80256ABCu;
    // 80256ABC: lwz     r3, -20700(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20700);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256AC0:
    ctx->pc = 0x80256AC0u;
    // 80256AC0: sth     r0, 52(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(52);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80256AC4:
    ctx->pc = 0x80256AC4u;
    // 80256AC4: lwz     r0, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256AC8:
    ctx->pc = 0x80256AC8u;
    // 80256AC8: lwz     r3, -20700(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20700);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256ACC:
    ctx->pc = 0x80256ACCu;
    // 80256ACC: sth     r0, 56(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(56);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80256AD0:
    ctx->pc = 0x80256AD0u;
    // 80256AD0: lwz     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256AD4:
    ctx->pc = 0x80256AD4u;
    // 80256AD4: lwz     r3, -20700(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20700);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256AD8:
    ctx->pc = 0x80256AD8u;
    // 80256AD8: sth     r0, 40(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(40);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80256ADC:
    ctx->pc = 0x80256ADCu;
    // 80256ADC: lwz     r0, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256AE0:
    ctx->pc = 0x80256AE0u;
    // 80256AE0: lwz     r3, -20700(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20700);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256AE4:
    ctx->pc = 0x80256AE4u;
    // 80256AE4: sth     r0, 44(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(44);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80256AE8:
    ctx->pc = 0x80256AE8u;
    // 80256AE8: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256AEC:
    ctx->pc = 0x80256AECu;
    // 80256AEC: lwz     r3, -20700(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20700);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256AF0:
    ctx->pc = 0x80256AF0u;
    // 80256AF0: rlwinm r0, r0, 16, 18, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0x00003FFFu;
    }

label_80256AF4:
    ctx->pc = 0x80256AF4u;
    // 80256AF4: sth     r0, 34(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(34);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80256AF8:
    ctx->pc = 0x80256AF8u;
    // 80256AF8: lwz     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256AFC:
    ctx->pc = 0x80256AFCu;
    // 80256AFC: lwz     r3, -20700(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20700);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256B00:
    ctx->pc = 0x80256B00u;
    // 80256B00: rlwinm r0, r0, 16, 18, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0x00003FFFu;
    }

label_80256B04:
    ctx->pc = 0x80256B04u;
    // 80256B04: sth     r0, 38(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(38);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80256B08:
    ctx->pc = 0x80256B08u;
    // 80256B08: lwz     r0, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256B0C:
    ctx->pc = 0x80256B0Cu;
    // 80256B0C: lwz     r3, -20700(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20700);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256B10:
    ctx->pc = 0x80256B10u;
    // 80256B10: srawi r0, r0, 16
    {
        u32 sh = 16u;
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

label_80256B14:
    ctx->pc = 0x80256B14u;
    // 80256B14: sth     r0, 50(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(50);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80256B18:
    ctx->pc = 0x80256B18u;
    // 80256B18: lwz     r0, 24(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256B1C:
    ctx->pc = 0x80256B1Cu;
    // 80256B1C: lwz     r3, -20700(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20700);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256B20:
    ctx->pc = 0x80256B20u;
    // 80256B20: rlwinm r0, r0, 16, 18, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0x00003FFFu;
    }

label_80256B24:
    ctx->pc = 0x80256B24u;
    // 80256B24: sth     r0, 54(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(54);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80256B28:
    ctx->pc = 0x80256B28u;
    // 80256B28: lwz     r0, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256B2C:
    ctx->pc = 0x80256B2Cu;
    // 80256B2C: lwz     r3, -20700(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20700);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256B30:
    ctx->pc = 0x80256B30u;
    // 80256B30: rlwinm r0, r0, 16, 18, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0x00003FFFu;
    }

label_80256B34:
    ctx->pc = 0x80256B34u;
    // 80256B34: sth     r0, 58(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(58);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80256B38:
    ctx->pc = 0x80256B38u;
    // 80256B38: lwz     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256B3C:
    ctx->pc = 0x80256B3Cu;
    // 80256B3C: lwz     r3, -20700(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20700);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256B40:
    ctx->pc = 0x80256B40u;
    // 80256B40: rlwinm r0, r0, 16, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0x0000FFFFu;
    }

label_80256B44:
    ctx->pc = 0x80256B44u;
    // 80256B44: sth     r0, 42(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(42);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80256B48:
    ctx->pc = 0x80256B48u;
    // 80256B48: lwz     r0, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256B4C:
    ctx->pc = 0x80256B4Cu;
    // 80256B4C: lwz     r3, -20700(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20700);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256B50:
    ctx->pc = 0x80256B50u;
    // 80256B50: rlwinm r0, r0, 16, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0x0000FFFFu;
    }

label_80256B54:
    ctx->pc = 0x80256B54u;
    // 80256B54: sth     r0, 46(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(46);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80256B58:
    ctx->pc = 0x80256B58u;
    // 80256B58: sync
    ppc_memory_fence();

label_80256B5C:
    ctx->pc = 0x80256B5Cu;
    // 80256B5C: lwz     r3, -20688(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20688);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256B60:
    ctx->pc = 0x80256B60u;
    // 80256B60: lwz     r0, -20684(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20684);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256B64:
    ctx->pc = 0x80256B64u;
    // 80256B64: cmplw   r3, r0
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

label_80256B68:
    ctx->pc = 0x80256B68u;
    // 80256B68: bc    4, 2, 0x80256B8C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80256B8C;
        }
    }

label_80256B6C:
    ctx->pc = 0x80256B6Cu;
    ctx->downcount -= 5;
    // 80256B6C: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80256B70:
    ctx->pc = 0x80256B70u;
    // 80256B70: stb     r0, -20676(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20676);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80256B74:
    ctx->pc = 0x80256B74u;
    // 80256B74: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80256B78:
    ctx->pc = 0x80256B78u;
    // 80256B78: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80256B7C:
    ctx->pc = 0x80256B7Cu;
    // 80256B7C: bl      0x80256FEC
    {
            ctx->lr = 0x80256B80u;
            goto label_80256FEC;
    }

label_80256B80:
    ctx->pc = 0x80256B80u;
    ctx->downcount -= 2;
    // 80256B80: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80256B84:
    ctx->pc = 0x80256B84u;
    // 80256B84: bl      0x80256FA8
    {
            ctx->lr = 0x80256B88u;
            goto label_80256FA8;
    }

label_80256B88:
    ctx->pc = 0x80256B88u;
    ctx->downcount -= 1;
    // 80256B88: b       0x80256BA8
    {
            goto label_80256BA8;
    }

label_80256B8C:
    ctx->pc = 0x80256B8Cu;
    ctx->downcount -= 5;
    // 80256B8C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80256B90:
    ctx->pc = 0x80256B90u;
    // 80256B90: stb     r0, -20676(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20676);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80256B94:
    ctx->pc = 0x80256B94u;
    // 80256B94: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80256B98:
    ctx->pc = 0x80256B98u;
    // 80256B98: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80256B9C:
    ctx->pc = 0x80256B9Cu;
    // 80256B9C: bl      0x80256FEC
    {
            ctx->lr = 0x80256BA0u;
            goto label_80256FEC;
    }

label_80256BA0:
    ctx->pc = 0x80256BA0u;
    ctx->downcount -= 2;
    // 80256BA0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80256BA4:
    ctx->pc = 0x80256BA4u;
    // 80256BA4: bl      0x80256FA8
    {
            ctx->lr = 0x80256BA8u;
            goto label_80256FA8;
    }

label_80256BA8:
    ctx->pc = 0x80256BA8u;
    ctx->downcount -= 3;
    // 80256BA8: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80256BAC:
    ctx->pc = 0x80256BACu;
    // 80256BAC: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80256BB0:
    ctx->pc = 0x80256BB0u;
    // 80256BB0: bl      0x80257038
    {
            ctx->lr = 0x80256BB4u;
            goto label_80257038;
    }

label_80256BB4:
    ctx->pc = 0x80256BB4u;
    ctx->downcount -= 1;
    // 80256BB4: bl      0x80256F5C
    {
            ctx->lr = 0x80256BB8u;
            goto label_80256F5C;
    }

label_80256BB8:
    ctx->pc = 0x80256BB8u;
    ctx->downcount -= 2;
    // 80256BB8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80256BBC:
    ctx->pc = 0x80256BBCu;
    // 80256BBC: bl      0x802440E4
    {
            ctx->lr = 0x80256BC0u;
            ctx->pc = 0x802440E4u;
            return;
    }

label_80256BC0:
    ctx->pc = 0x80256BC0u;
    ctx->downcount -= 7;
    // 80256BC0: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256BC4:
    ctx->pc = 0x80256BC4u;
    // 80256BC4: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80256BC8:
    ctx->pc = 0x80256BC8u;
    // 80256BC8: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80256BCC:
    ctx->pc = 0x80256BCCu;
    // 80256BCC: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80256BD0:
    ctx->pc = 0x80256BD0u;
    // 80256BD0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80256BD4:
    ctx->pc = 0x80256BD4u;
    // 80256BD4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80256BD8:
    ctx->pc = 0x80256BD8u;
    ctx->downcount -= 4;
    // 80256BD8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80256BDC:
    ctx->pc = 0x80256BDCu;
    // 80256BDC: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256BE0:
    ctx->pc = 0x80256BE0u;
    // 80256BE0: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80256BE4:
    ctx->pc = 0x80256BE4u;
    // 80256BE4: bl      0x80256BF8
    {
            ctx->lr = 0x80256BE8u;
            goto label_80256BF8;
    }

label_80256BE8:
    ctx->pc = 0x80256BE8u;
    ctx->downcount -= 5;
    // 80256BE8: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256BEC:
    ctx->pc = 0x80256BECu;
    // 80256BEC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80256BF0:
    ctx->pc = 0x80256BF0u;
    // 80256BF0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80256BF4:
    ctx->pc = 0x80256BF4u;
    // 80256BF4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80256BF8:
    ctx->pc = 0x80256BF8u;
    ctx->downcount -= 7;
    // 80256BF8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80256BFC:
    ctx->pc = 0x80256BFCu;
    // 80256BFC: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256C00:
    ctx->pc = 0x80256C00u;
    // 80256C00: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80256C04:
    ctx->pc = 0x80256C04u;
    // 80256C04: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80256C08:
    ctx->pc = 0x80256C08u;
    // 80256C08: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80256C0C:
    ctx->pc = 0x80256C0Cu;
    // 80256C0C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80256C10:
    ctx->pc = 0x80256C10u;
    // 80256C10: bl      0x802440BC
    {
            ctx->lr = 0x80256C14u;
            ctx->pc = 0x802440BCu;
            return;
    }

label_80256C14:
    ctx->pc = 0x80256C14u;
    ctx->downcount -= 2;
    // 80256C14: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80256C18:
    ctx->pc = 0x80256C18u;
    // 80256C18: bl      0x80258C10
    {
            ctx->lr = 0x80256C1Cu;
            goto label_80258C10;
    }

label_80256C1C:
    ctx->pc = 0x80256C1Cu;
    ctx->downcount -= 16;
    // 80256C1C: lwz     r3, -20704(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20704);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256C20:
    ctx->pc = 0x80256C20u;
    // 80256C20: lwz     r3, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256C24:
    ctx->pc = 0x80256C24u;
    // 80256C24: addis   r0, r3, -32768
    ctx->gpr[0] = ctx->gpr[3] + ((u32)(s32)(-32768) << 16);

label_80256C28:
    ctx->pc = 0x80256C28u;
    // 80256C28: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256C2C:
    ctx->pc = 0x80256C2Cu;
    // 80256C2C: lwz     r3, -20704(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20704);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256C30:
    ctx->pc = 0x80256C30u;
    // 80256C30: lwz     r3, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256C34:
    ctx->pc = 0x80256C34u;
    // 80256C34: addis   r0, r3, -32768
    ctx->gpr[0] = ctx->gpr[3] + ((u32)(s32)(-32768) << 16);

label_80256C38:
    ctx->pc = 0x80256C38u;
    // 80256C38: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256C3C:
    ctx->pc = 0x80256C3Cu;
    // 80256C3C: lwz     r3, -20704(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20704);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256C40:
    ctx->pc = 0x80256C40u;
    // 80256C40: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256C44:
    ctx->pc = 0x80256C44u;
    // 80256C44: rlwinm r3, r0, 0, 6, 4
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFBFFFFFFu;
    }

label_80256C48:
    ctx->pc = 0x80256C48u;
    // 80256C48: addis   r0, r3, -32768
    ctx->gpr[0] = ctx->gpr[3] + ((u32)(s32)(-32768) << 16);

label_80256C4C:
    ctx->pc = 0x80256C4Cu;
    // 80256C4C: stw     r0, 24(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256C50:
    ctx->pc = 0x80256C50u;
    // 80256C50: lbz     r0, -20676(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20676);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80256C54:
    ctx->pc = 0x80256C54u;
    // 80256C54: cmplwi  r0, 0x0000
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

label_80256C58:
    ctx->pc = 0x80256C58u;
    // 80256C58: bc    12, 2, 0x80256C8C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80256C8C;
        }
    }

label_80256C5C:
    ctx->pc = 0x80256C5Cu;
    ctx->downcount -= 12;
    // 80256C5C: lwz     r4, -20700(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20700);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80256C60:
    ctx->pc = 0x80256C60u;
    // 80256C60: lhz     r3, 58(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(58);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_80256C64:
    ctx->pc = 0x80256C64u;
    // 80256C64: lhz     r4, 56(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(56);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_80256C68:
    ctx->pc = 0x80256C68u;
    // 80256C68: rlwimi r4, r3, 16, 0, 15
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[3], 16u);
        ctx->gpr[4] = (ctx->gpr[4] & ~0xFFFF0000u) | (rot & 0xFFFF0000u);
    }

label_80256C6C:
    ctx->pc = 0x80256C6Cu;
    // 80256C6C: addis   r0, r4, -32768
    ctx->gpr[0] = ctx->gpr[4] + ((u32)(s32)(-32768) << 16);

label_80256C70:
    ctx->pc = 0x80256C70u;
    // 80256C70: stw     r0, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256C74:
    ctx->pc = 0x80256C74u;
    // 80256C74: lwz     r4, -20700(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20700);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80256C78:
    ctx->pc = 0x80256C78u;
    // 80256C78: lhz     r3, 50(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(50);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_80256C7C:
    ctx->pc = 0x80256C7Cu;
    // 80256C7C: lhz     r0, 48(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(48);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80256C80:
    ctx->pc = 0x80256C80u;
    // 80256C80: rlwimi r0, r3, 16, 0, 15
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[3], 16u);
        ctx->gpr[0] = (ctx->gpr[0] & ~0xFFFF0000u) | (rot & 0xFFFF0000u);
    }

label_80256C84:
    ctx->pc = 0x80256C84u;
    // 80256C84: stw     r0, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256C88:
    ctx->pc = 0x80256C88u;
    // 80256C88: b       0x80256CB4
    {
            goto label_80256CB4;
    }

label_80256C8C:
    ctx->pc = 0x80256C8Cu;
    ctx->downcount -= 7;
    // 80256C8C: lwz     r3, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256C90:
    ctx->pc = 0x80256C90u;
    // 80256C90: lwz     r0, 24(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256C94:
    ctx->pc = 0x80256C94u;
    // 80256C94: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80256C98:
    ctx->pc = 0x80256C98u;
    // 80256C98: stw     r0, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256C9C:
    ctx->pc = 0x80256C9Cu;
    // 80256C9C: lwz     r3, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256CA0:
    ctx->pc = 0x80256CA0u;
    // 80256CA0: cmpwi   r3, 0
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

label_80256CA4:
    ctx->pc = 0x80256CA4u;
    // 80256CA4: bc    4, 0, 0x80256CB4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80256CB4;
        }
    }

label_80256CA8:
    ctx->pc = 0x80256CA8u;
    ctx->downcount -= 3;
    // 80256CA8: lwz     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256CAC:
    ctx->pc = 0x80256CACu;
    // 80256CAC: add   r0, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80256CB0:
    ctx->pc = 0x80256CB0u;
    // 80256CB0: stw     r0, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256CB4:
    ctx->pc = 0x80256CB4u;
    ctx->downcount -= 2;
    // 80256CB4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80256CB8:
    ctx->pc = 0x80256CB8u;
    // 80256CB8: bl      0x802440E4
    {
            ctx->lr = 0x80256CBCu;
            ctx->pc = 0x802440E4u;
            return;
    }

label_80256CBC:
    ctx->pc = 0x80256CBCu;
    ctx->downcount -= 7;
    // 80256CBC: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256CC0:
    ctx->pc = 0x80256CC0u;
    // 80256CC0: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80256CC4:
    ctx->pc = 0x80256CC4u;
    // 80256CC4: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80256CC8:
    ctx->pc = 0x80256CC8u;
    // 80256CC8: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80256CCC:
    ctx->pc = 0x80256CCCu;
    // 80256CCC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80256CD0:
    ctx->pc = 0x80256CD0u;
    // 80256CD0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80256CD4:
    ctx->pc = 0x80256CD4u;
    ctx->downcount -= 25;
    // 80256CD4: lwz     r9, -20700(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20700);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80256CD8:
    ctx->pc = 0x80256CD8u;
    // 80256CD8: lwz     r8, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80256CDC:
    ctx->pc = 0x80256CDCu;
    // 80256CDC: lhz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80256CE0:
    ctx->pc = 0x80256CE0u;
    // 80256CE0: stw     r0, 12(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256CE4:
    ctx->pc = 0x80256CE4u;
    // 80256CE4: lwz     r8, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80256CE8:
    ctx->pc = 0x80256CE8u;
    // 80256CE8: lwz     r0, 12(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256CEC:
    ctx->pc = 0x80256CECu;
    // 80256CEC: rlwinm r0, r0, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000001u;
    }

label_80256CF0:
    ctx->pc = 0x80256CF0u;
    // 80256CF0: stb     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80256CF4:
    ctx->pc = 0x80256CF4u;
    // 80256CF4: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256CF8:
    ctx->pc = 0x80256CF8u;
    // 80256CF8: lwz     r0, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256CFC:
    ctx->pc = 0x80256CFCu;
    // 80256CFC: rlwinm r0, r0, 31, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x00000001u;
    }

label_80256D00:
    ctx->pc = 0x80256D00u;
    // 80256D00: stb     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80256D04:
    ctx->pc = 0x80256D04u;
    // 80256D04: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256D08:
    ctx->pc = 0x80256D08u;
    // 80256D08: lwz     r0, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256D0C:
    ctx->pc = 0x80256D0Cu;
    // 80256D0C: rlwinm r0, r0, 30, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 30u) & 0x00000001u;
    }

label_80256D10:
    ctx->pc = 0x80256D10u;
    // 80256D10: stb     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80256D14:
    ctx->pc = 0x80256D14u;
    // 80256D14: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256D18:
    ctx->pc = 0x80256D18u;
    // 80256D18: lwz     r0, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256D1C:
    ctx->pc = 0x80256D1Cu;
    // 80256D1C: rlwinm r0, r0, 29, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 29u) & 0x00000001u;
    }

label_80256D20:
    ctx->pc = 0x80256D20u;
    // 80256D20: stb     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80256D24:
    ctx->pc = 0x80256D24u;
    // 80256D24: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256D28:
    ctx->pc = 0x80256D28u;
    // 80256D28: lwz     r0, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256D2C:
    ctx->pc = 0x80256D2Cu;
    // 80256D2C: rlwinm r0, r0, 28, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 28u) & 0x00000001u;
    }

label_80256D30:
    ctx->pc = 0x80256D30u;
    // 80256D30: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80256D34:
    ctx->pc = 0x80256D34u;
    // 80256D34: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80256D38:
    ctx->pc = 0x80256D38u;
    ctx->downcount -= 3;
    // 80256D38: lwz     r0, -20688(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20688);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256D3C:
    ctx->pc = 0x80256D3Cu;
    // 80256D3C: cmplw   r3, r0
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

label_80256D40:
    ctx->pc = 0x80256D40u;
    // 80256D40: bc    4, 2, 0x80256D58
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80256D58;
        }
    }

label_80256D44:
    ctx->pc = 0x80256D44u;
    ctx->downcount -= 5;
    // 80256D44: lwz     r6, -20704(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20704);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80256D48:
    ctx->pc = 0x80256D48u;
    // 80256D48: lwz     r0, 20(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256D4C:
    ctx->pc = 0x80256D4Cu;
    // 80256D4C: rlwinm r6, r0, 0, 6, 4
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFBFFFFFFu;
    }

label_80256D50:
    ctx->pc = 0x80256D50u;
    // 80256D50: addis   r0, r6, -32768
    ctx->gpr[0] = ctx->gpr[6] + ((u32)(s32)(-32768) << 16);

label_80256D54:
    ctx->pc = 0x80256D54u;
    // 80256D54: stw     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256D58:
    ctx->pc = 0x80256D58u;
    ctx->downcount -= 3;
    // 80256D58: lwz     r0, -20684(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20684);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256D5C:
    ctx->pc = 0x80256D5Cu;
    // 80256D5C: cmplw   r3, r0
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

label_80256D60:
    ctx->pc = 0x80256D60u;
    // 80256D60: bc    4, 2, 0x80256D94
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80256D94;
        }
    }

label_80256D64:
    ctx->pc = 0x80256D64u;
    ctx->downcount -= 12;
    // 80256D64: lwz     r7, -20700(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20700);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80256D68:
    ctx->pc = 0x80256D68u;
    // 80256D68: lhz     r6, 58(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(58);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_80256D6C:
    ctx->pc = 0x80256D6Cu;
    // 80256D6C: lhz     r7, 56(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(56);
        ctx->gpr[7] = mem_read16(ctx, ea);
    }

label_80256D70:
    ctx->pc = 0x80256D70u;
    // 80256D70: rlwimi r7, r6, 16, 0, 15
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[6], 16u);
        ctx->gpr[7] = (ctx->gpr[7] & ~0xFFFF0000u) | (rot & 0xFFFF0000u);
    }

label_80256D74:
    ctx->pc = 0x80256D74u;
    // 80256D74: addis   r0, r7, -32768
    ctx->gpr[0] = ctx->gpr[7] + ((u32)(s32)(-32768) << 16);

label_80256D78:
    ctx->pc = 0x80256D78u;
    // 80256D78: stw     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256D7C:
    ctx->pc = 0x80256D7Cu;
    // 80256D7C: lwz     r7, -20700(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20700);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80256D80:
    ctx->pc = 0x80256D80u;
    // 80256D80: lhz     r6, 50(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(50);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_80256D84:
    ctx->pc = 0x80256D84u;
    // 80256D84: lhz     r0, 48(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(48);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80256D88:
    ctx->pc = 0x80256D88u;
    // 80256D88: rlwimi r0, r6, 16, 0, 15
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[6], 16u);
        ctx->gpr[0] = (ctx->gpr[0] & ~0xFFFF0000u) | (rot & 0xFFFF0000u);
    }

label_80256D8C:
    ctx->pc = 0x80256D8Cu;
    // 80256D8C: stw     r0, 28(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256D90:
    ctx->pc = 0x80256D90u;
    // 80256D90: b       0x80256DBC
    {
            goto label_80256DBC;
    }

label_80256D94:
    ctx->pc = 0x80256D94u;
    ctx->downcount -= 7;
    // 80256D94: lwz     r6, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80256D98:
    ctx->pc = 0x80256D98u;
    // 80256D98: lwz     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256D9C:
    ctx->pc = 0x80256D9Cu;
    // 80256D9C: subf   r0, r6, r0
    {
        u32 a = ~ctx->gpr[6];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80256DA0:
    ctx->pc = 0x80256DA0u;
    // 80256DA0: stw     r0, 28(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256DA4:
    ctx->pc = 0x80256DA4u;
    // 80256DA4: lwz     r6, 28(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(28);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80256DA8:
    ctx->pc = 0x80256DA8u;
    // 80256DA8: cmpwi   r6, 0
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

label_80256DAC:
    ctx->pc = 0x80256DACu;
    // 80256DAC: bc    4, 0, 0x80256DBC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80256DBC;
        }
    }

label_80256DB0:
    ctx->pc = 0x80256DB0u;
    ctx->downcount -= 3;
    // 80256DB0: lwz     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256DB4:
    ctx->pc = 0x80256DB4u;
    // 80256DB4: add   r0, r6, r0
    {
        u32 a = ctx->gpr[6];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80256DB8:
    ctx->pc = 0x80256DB8u;
    // 80256DB8: stw     r0, 28(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256DBC:
    ctx->pc = 0x80256DBCu;
    ctx->downcount -= 5;
    // 80256DBC: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256DC0:
    ctx->pc = 0x80256DC0u;
    // 80256DC0: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256DC4:
    ctx->pc = 0x80256DC4u;
    // 80256DC4: lwz     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256DC8:
    ctx->pc = 0x80256DC8u;
    // 80256DC8: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256DCC:
    ctx->pc = 0x80256DCCu;
    // 80256DCC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80256DD0:
    ctx->pc = 0x80256DD0u;
    ctx->downcount -= 8;
    // 80256DD0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80256DD4:
    ctx->pc = 0x80256DD4u;
    // 80256DD4: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256DD8:
    ctx->pc = 0x80256DD8u;
    // 80256DD8: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80256DDC:
    ctx->pc = 0x80256DDCu;
    // 80256DDC: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80256DE0:
    ctx->pc = 0x80256DE0u;
    // 80256DE0: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80256DE4:
    ctx->pc = 0x80256DE4u;
    // 80256DE4: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80256DE8:
    ctx->pc = 0x80256DE8u;
    // 80256DE8: lwz     r31, -20668(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20668);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80256DEC:
    ctx->pc = 0x80256DECu;
    // 80256DEC: bl      0x802440BC
    {
            ctx->lr = 0x80256DF0u;
            ctx->pc = 0x802440BCu;
            return;
    }

label_80256DF0:
    ctx->pc = 0x80256DF0u;
    ctx->downcount -= 2;
    // 80256DF0: stw     r30, -20668(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20668);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80256DF4:
    ctx->pc = 0x80256DF4u;
    // 80256DF4: bl      0x802440E4
    {
            ctx->lr = 0x80256DF8u;
            ctx->pc = 0x802440E4u;
            return;
    }

label_80256DF8:
    ctx->pc = 0x80256DF8u;
    ctx->downcount -= 8;
    // 80256DF8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80256DFC:
    ctx->pc = 0x80256DFCu;
    // 80256DFC: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256E00:
    ctx->pc = 0x80256E00u;
    // 80256E00: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80256E04:
    ctx->pc = 0x80256E04u;
    // 80256E04: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80256E08:
    ctx->pc = 0x80256E08u;
    // 80256E08: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80256E0C:
    ctx->pc = 0x80256E0Cu;
    // 80256E0C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80256E10:
    ctx->pc = 0x80256E10u;
    // 80256E10: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80256E14:
    ctx->pc = 0x80256E14u;
    ctx->downcount -= 7;
    // 80256E14: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80256E18:
    ctx->pc = 0x80256E18u;
    // 80256E18: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256E1C:
    ctx->pc = 0x80256E1Cu;
    // 80256E1C: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80256E20:
    ctx->pc = 0x80256E20u;
    // 80256E20: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80256E24:
    ctx->pc = 0x80256E24u;
    // 80256E24: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80256E28:
    ctx->pc = 0x80256E28u;
    // 80256E28: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80256E2C:
    ctx->pc = 0x80256E2Cu;
    // 80256E2C: bl      0x802440BC
    {
            ctx->lr = 0x80256E30u;
            ctx->pc = 0x802440BCu;
            return;
    }

label_80256E30:
    ctx->pc = 0x80256E30u;
    ctx->downcount -= 2;
    // 80256E30: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80256E34:
    ctx->pc = 0x80256E34u;
    // 80256E34: bl      0x80256F84
    {
            ctx->lr = 0x80256E38u;
            goto label_80256F84;
    }

label_80256E38:
    ctx->pc = 0x80256E38u;
    ctx->downcount -= 21;
    // 80256E38: lwz     r3, -20700(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20700);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256E3C:
    ctx->pc = 0x80256E3Cu;
    // 80256E3C: rlwinm r0, r31, 16, 18, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[31], 16u) & 0x00003FFFu;
    }

label_80256E40:
    ctx->pc = 0x80256E40u;
    // 80256E40: sth     r31, 60(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(60);
        mem_write16(ctx, ea, (u16)ctx->gpr[31]);
    }

label_80256E44:
    ctx->pc = 0x80256E44u;
    // 80256E44: lwz     r3, -20700(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20700);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256E48:
    ctx->pc = 0x80256E48u;
    // 80256E48: sth     r0, 62(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(62);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80256E4C:
    ctx->pc = 0x80256E4Cu;
    // 80256E4C: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256E50:
    ctx->pc = 0x80256E50u;
    // 80256E50: lwzu     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_80256E54:
    ctx->pc = 0x80256E54u;
    // 80256E54: rlwinm r0, r0, 0, 31, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFDu;
    }

label_80256E58:
    ctx->pc = 0x80256E58u;
    // 80256E58: ori     r0, r0, 0x0002
    ctx->gpr[0] = ctx->gpr[0] | 0x0002u;

label_80256E5C:
    ctx->pc = 0x80256E5Cu;
    // 80256E5C: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256E60:
    ctx->pc = 0x80256E60u;
    // 80256E60: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256E64:
    ctx->pc = 0x80256E64u;
    // 80256E64: lwzu     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_80256E68:
    ctx->pc = 0x80256E68u;
    // 80256E68: rlwinm r0, r0, 0, 27, 25
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFDFu;
    }

label_80256E6C:
    ctx->pc = 0x80256E6Cu;
    // 80256E6C: ori     r0, r0, 0x0020
    ctx->gpr[0] = ctx->gpr[0] | 0x0020u;

label_80256E70:
    ctx->pc = 0x80256E70u;
    // 80256E70: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256E74:
    ctx->pc = 0x80256E74u;
    // 80256E74: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80256E78:
    ctx->pc = 0x80256E78u;
    // 80256E78: lwz     r3, -20700(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20700);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256E7C:
    ctx->pc = 0x80256E7Cu;
    // 80256E7C: lwz     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256E80:
    ctx->pc = 0x80256E80u;
    // 80256E80: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80256E84:
    ctx->pc = 0x80256E84u;
    // 80256E84: stw     r31, -20660(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20660);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80256E88:
    ctx->pc = 0x80256E88u;
    // 80256E88: bl      0x80256F5C
    {
            ctx->lr = 0x80256E8Cu;
            goto label_80256F5C;
    }

label_80256E8C:
    ctx->pc = 0x80256E8Cu;
    ctx->downcount -= 2;
    // 80256E8C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80256E90:
    ctx->pc = 0x80256E90u;
    // 80256E90: bl      0x802440E4
    {
            ctx->lr = 0x80256E94u;
            ctx->pc = 0x802440E4u;
            return;
    }

label_80256E94:
    ctx->pc = 0x80256E94u;
    ctx->downcount -= 7;
    // 80256E94: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256E98:
    ctx->pc = 0x80256E98u;
    // 80256E98: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80256E9C:
    ctx->pc = 0x80256E9Cu;
    // 80256E9C: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80256EA0:
    ctx->pc = 0x80256EA0u;
    // 80256EA0: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80256EA4:
    ctx->pc = 0x80256EA4u;
    // 80256EA4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80256EA8:
    ctx->pc = 0x80256EA8u;
    // 80256EA8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80256EAC:
    ctx->pc = 0x80256EACu;
    ctx->downcount -= 4;
    // 80256EAC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80256EB0:
    ctx->pc = 0x80256EB0u;
    // 80256EB0: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256EB4:
    ctx->pc = 0x80256EB4u;
    // 80256EB4: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80256EB8:
    ctx->pc = 0x80256EB8u;
    // 80256EB8: bl      0x802440BC
    {
            ctx->lr = 0x80256EBCu;
            ctx->pc = 0x802440BCu;
            return;
    }

label_80256EBC:
    ctx->pc = 0x80256EBCu;
    ctx->downcount -= 17;
    // 80256EBC: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80256EC0:
    ctx->pc = 0x80256EC0u;
    // 80256EC0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80256EC4:
    ctx->pc = 0x80256EC4u;
    // 80256EC4: addi    r5, r4, 8
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(8);

label_80256EC8:
    ctx->pc = 0x80256EC8u;
    // 80256EC8: lwz     r4, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80256ECC:
    ctx->pc = 0x80256ECCu;
    // 80256ECC: rlwinm r4, r4, 0, 31, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFFFDu;
    }

label_80256ED0:
    ctx->pc = 0x80256ED0u;
    // 80256ED0: stw     r4, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80256ED4:
    ctx->pc = 0x80256ED4u;
    // 80256ED4: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80256ED8:
    ctx->pc = 0x80256ED8u;
    // 80256ED8: addi    r5, r4, 8
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(8);

label_80256EDC:
    ctx->pc = 0x80256EDCu;
    // 80256EDC: lwz     r4, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80256EE0:
    ctx->pc = 0x80256EE0u;
    // 80256EE0: rlwinm r4, r4, 0, 27, 25
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFFDFu;
    }

label_80256EE4:
    ctx->pc = 0x80256EE4u;
    // 80256EE4: stw     r4, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80256EE8:
    ctx->pc = 0x80256EE8u;
    // 80256EE8: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80256EEC:
    ctx->pc = 0x80256EECu;
    // 80256EEC: lwz     r4, -20700(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20700);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80256EF0:
    ctx->pc = 0x80256EF0u;
    // 80256EF0: lwz     r5, 8(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(8);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80256EF4:
    ctx->pc = 0x80256EF4u;
    // 80256EF4: sth     r5, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[5]);
    }

label_80256EF8:
    ctx->pc = 0x80256EF8u;
    // 80256EF8: stw     r0, -20660(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20660);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256EFC:
    ctx->pc = 0x80256EFCu;
    // 80256EFC: bl      0x802440E4
    {
            ctx->lr = 0x80256F00u;
            ctx->pc = 0x802440E4u;
            return;
    }

label_80256F00:
    ctx->pc = 0x80256F00u;
    ctx->downcount -= 5;
    // 80256F00: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256F04:
    ctx->pc = 0x80256F04u;
    // 80256F04: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80256F08:
    ctx->pc = 0x80256F08u;
    // 80256F08: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80256F0C:
    ctx->pc = 0x80256F0Cu;
    // 80256F0C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80256F10:
    ctx->pc = 0x80256F10u;
    ctx->downcount -= 7;
    // 80256F10: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80256F14:
    ctx->pc = 0x80256F14u;
    // 80256F14: lis     r3, -32731
    ctx->gpr[3] = ((u32)(s32)(-32731) << 16);

label_80256F18:
    ctx->pc = 0x80256F18u;
    // 80256F18: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256F1C:
    ctx->pc = 0x80256F1Cu;
    // 80256F1C: addi    r4, r3, 26412
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(26412);

label_80256F20:
    ctx->pc = 0x80256F20u;
    // 80256F20: li      r3, 17
    ctx->gpr[3] = (u32)(s32)(17);

label_80256F24:
    ctx->pc = 0x80256F24u;
    // 80256F24: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80256F28:
    ctx->pc = 0x80256F28u;
    // 80256F28: bl      0x80244108
    {
            ctx->lr = 0x80256F2Cu;
            ctx->pc = 0x80244108u;
            return;
    }

label_80256F2C:
    ctx->pc = 0x80256F2Cu;
    ctx->downcount -= 2;
    // 80256F2C: li      r3, 16384
    ctx->gpr[3] = (u32)(s32)(16384);

label_80256F30:
    ctx->pc = 0x80256F30u;
    // 80256F30: bl      0x8024450C
    {
            ctx->lr = 0x80256F34u;
            ctx->pc = 0x8024450Cu;
            return;
    }

label_80256F34:
    ctx->pc = 0x80256F34u;
    ctx->downcount -= 1;
    // 80256F34: bl      0x80246734
    {
            ctx->lr = 0x80256F38u;
            ctx->pc = 0x80246734u;
            return;
    }

label_80256F38:
    ctx->pc = 0x80256F38u;
    ctx->downcount -= 10;
    // 80256F38: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80256F3C:
    ctx->pc = 0x80256F3Cu;
    // 80256F3C: stw     r3, -20680(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20680);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80256F40:
    ctx->pc = 0x80256F40u;
    // 80256F40: stw     r0, -20672(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20672);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256F44:
    ctx->pc = 0x80256F44u;
    // 80256F44: stw     r0, -20688(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20688);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256F48:
    ctx->pc = 0x80256F48u;
    // 80256F48: stw     r0, -20684(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20684);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256F4C:
    ctx->pc = 0x80256F4Cu;
    // 80256F4C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256F50:
    ctx->pc = 0x80256F50u;
    // 80256F50: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80256F54:
    ctx->pc = 0x80256F54u;
    // 80256F54: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80256F58:
    ctx->pc = 0x80256F58u;
    // 80256F58: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80256F5C:
    ctx->pc = 0x80256F5Cu;
    ctx->downcount -= 10;
    // 80256F5C: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256F60:
    ctx->pc = 0x80256F60u;
    // 80256F60: lwzu     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_80256F64:
    ctx->pc = 0x80256F64u;
    // 80256F64: rlwinm r0, r0, 0, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFEu;
    }

label_80256F68:
    ctx->pc = 0x80256F68u;
    // 80256F68: ori     r0, r0, 0x0001
    ctx->gpr[0] = ctx->gpr[0] | 0x0001u;

label_80256F6C:
    ctx->pc = 0x80256F6Cu;
    // 80256F6C: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256F70:
    ctx->pc = 0x80256F70u;
    // 80256F70: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80256F74:
    ctx->pc = 0x80256F74u;
    // 80256F74: lwz     r3, -20700(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20700);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256F78:
    ctx->pc = 0x80256F78u;
    // 80256F78: lwz     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256F7C:
    ctx->pc = 0x80256F7Cu;
    // 80256F7C: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80256F80:
    ctx->pc = 0x80256F80u;
    // 80256F80: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80256F84:
    ctx->pc = 0x80256F84u;
    ctx->downcount -= 9;
    // 80256F84: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256F88:
    ctx->pc = 0x80256F88u;
    // 80256F88: lwzu     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_80256F8C:
    ctx->pc = 0x80256F8Cu;
    // 80256F8C: rlwinm r0, r0, 0, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFEu;
    }

label_80256F90:
    ctx->pc = 0x80256F90u;
    // 80256F90: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256F94:
    ctx->pc = 0x80256F94u;
    // 80256F94: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80256F98:
    ctx->pc = 0x80256F98u;
    // 80256F98: lwz     r3, -20700(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20700);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256F9C:
    ctx->pc = 0x80256F9Cu;
    // 80256F9C: lwz     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256FA0:
    ctx->pc = 0x80256FA0u;
    // 80256FA0: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80256FA4:
    ctx->pc = 0x80256FA4u;
    // 80256FA4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80256FA8:
    ctx->pc = 0x80256FA8u;
    ctx->downcount -= 2;
    // 80256FA8: rlwinm. r0, r3, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000000FFu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80256FAC:
    ctx->pc = 0x80256FACu;
    // 80256FAC: bc    12, 2, 0x80256FB8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80256FB8;
        }
    }

label_80256FB0:
    ctx->pc = 0x80256FB0u;
    ctx->downcount -= 2;
    // 80256FB0: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80256FB4:
    ctx->pc = 0x80256FB4u;
    // 80256FB4: b       0x80256FBC
    {
            goto label_80256FBC;
    }

label_80256FB8:
    ctx->pc = 0x80256FB8u;
    ctx->downcount -= 1;
    // 80256FB8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80256FBC:
    ctx->pc = 0x80256FBCu;
    ctx->downcount -= 12;
    // 80256FBC: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256FC0:
    ctx->pc = 0x80256FC0u;
    // 80256FC0: rlwinm r0, r0, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 4u) & 0xFFFFFFF0u;
    }

label_80256FC4:
    ctx->pc = 0x80256FC4u;
    // 80256FC4: addi    r4, r3, 8
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(8);

label_80256FC8:
    ctx->pc = 0x80256FC8u;
    // 80256FC8: lwz     r3, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256FCC:
    ctx->pc = 0x80256FCCu;
    // 80256FCC: rlwinm r3, r3, 0, 28, 26
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFEFu;
    }

label_80256FD0:
    ctx->pc = 0x80256FD0u;
    // 80256FD0: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80256FD4:
    ctx->pc = 0x80256FD4u;
    // 80256FD4: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80256FD8:
    ctx->pc = 0x80256FD8u;
    // 80256FD8: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80256FDC:
    ctx->pc = 0x80256FDCu;
    // 80256FDC: lwz     r3, -20700(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20700);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80256FE0:
    ctx->pc = 0x80256FE0u;
    // 80256FE0: lwz     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80256FE4:
    ctx->pc = 0x80256FE4u;
    // 80256FE4: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80256FE8:
    ctx->pc = 0x80256FE8u;
    // 80256FE8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80256FEC:
    ctx->pc = 0x80256FECu;
    ctx->downcount -= 19;
    // 80256FEC: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80256FF0:
    ctx->pc = 0x80256FF0u;
    // 80256FF0: rlwinm r3, r3, 2, 22, 29
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0x000003FCu;
    }

label_80256FF4:
    ctx->pc = 0x80256FF4u;
    // 80256FF4: rlwinm r0, r4, 3, 21, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 3u) & 0x000007F8u;
    }

label_80256FF8:
    ctx->pc = 0x80256FF8u;
    // 80256FF8: addi    r6, r5, 8
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(8);

label_80256FFC:
    ctx->pc = 0x80256FFCu;
    // 80256FFC: lwz     r5, 8(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(8);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80257000:
    ctx->pc = 0x80257000u;
    // 80257000: rlwinm r4, r5, 0, 30, 28
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFFBu;
    }

label_80257004:
    ctx->pc = 0x80257004u;
    // 80257004: or   r3, r4, r3
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[3];
    }

label_80257008:
    ctx->pc = 0x80257008u;
    // 80257008: stw     r3, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8025700C:
    ctx->pc = 0x8025700Cu;
    // 8025700C: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257010:
    ctx->pc = 0x80257010u;
    // 80257010: addi    r4, r3, 8
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(8);

label_80257014:
    ctx->pc = 0x80257014u;
    // 80257014: lwz     r3, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257018:
    ctx->pc = 0x80257018u;
    // 80257018: rlwinm r3, r3, 0, 29, 27
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFF7u;
    }

label_8025701C:
    ctx->pc = 0x8025701Cu;
    // 8025701C: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80257020:
    ctx->pc = 0x80257020u;
    // 80257020: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80257024:
    ctx->pc = 0x80257024u;
    // 80257024: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80257028:
    ctx->pc = 0x80257028u;
    // 80257028: lwz     r3, -20700(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20700);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8025702C:
    ctx->pc = 0x8025702Cu;
    // 8025702C: lwz     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257030:
    ctx->pc = 0x80257030u;
    // 80257030: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80257034:
    ctx->pc = 0x80257034u;
    // 80257034: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80257038:
    ctx->pc = 0x80257038u;
    ctx->downcount -= 19;
    // 80257038: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8025703C:
    ctx->pc = 0x8025703Cu;
    // 8025703C: rlwinm r3, r3, 0, 24, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000000FFu;
    }

label_80257040:
    ctx->pc = 0x80257040u;
    // 80257040: rlwinm r0, r4, 1, 23, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 1u) & 0x000001FEu;
    }

label_80257044:
    ctx->pc = 0x80257044u;
    // 80257044: addi    r6, r5, 16
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(16);

label_80257048:
    ctx->pc = 0x80257048u;
    // 80257048: lwz     r5, 16(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(16);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8025704C:
    ctx->pc = 0x8025704Cu;
    // 8025704C: rlwinm r4, r5, 0, 0, 30
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFFEu;
    }

label_80257050:
    ctx->pc = 0x80257050u;
    // 80257050: or   r3, r4, r3
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[3];
    }

label_80257054:
    ctx->pc = 0x80257054u;
    // 80257054: stw     r3, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80257058:
    ctx->pc = 0x80257058u;
    // 80257058: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8025705C:
    ctx->pc = 0x8025705Cu;
    // 8025705C: addi    r4, r3, 16
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(16);

label_80257060:
    ctx->pc = 0x80257060u;
    // 80257060: lwz     r3, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257064:
    ctx->pc = 0x80257064u;
    // 80257064: rlwinm r3, r3, 0, 31, 29
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFFDu;
    }

label_80257068:
    ctx->pc = 0x80257068u;
    // 80257068: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_8025706C:
    ctx->pc = 0x8025706Cu;
    // 8025706C: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80257070:
    ctx->pc = 0x80257070u;
    // 80257070: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80257074:
    ctx->pc = 0x80257074u;
    // 80257074: lwz     r3, -20700(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20700);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257078:
    ctx->pc = 0x80257078u;
    // 80257078: lwz     r0, 16(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8025707C:
    ctx->pc = 0x8025707Cu;
    // 8025707C: sth     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80257080:
    ctx->pc = 0x80257080u;
    // 80257080: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80257084:
    ctx->pc = 0x80257084u;
    ctx->downcount -= 7;
    // 80257084: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80257088:
    ctx->pc = 0x80257088u;
    // 80257088: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8025708C:
    ctx->pc = 0x8025708Cu;
    // 8025708C: stwu     r1, -168(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-168);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80257090:
    ctx->pc = 0x80257090u;
    // 80257090: stw     r31, 164(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(164);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80257094:
    ctx->pc = 0x80257094u;
    // 80257094: stw     r30, 160(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(160);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80257098:
    ctx->pc = 0x80257098u;
    // 80257098: stw     r29, 156(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(156);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_8025709C:
    ctx->pc = 0x8025709Cu;
    // 8025709C: bl      0x80257188
    {
            ctx->lr = 0x802570A0u;
            goto label_80257188;
    }

label_802570A0:
    ctx->pc = 0x802570A0u;
    ctx->downcount -= 2;
    // 802570A0: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_802570A4:
    ctx->pc = 0x802570A4u;
    // 802570A4: bl      0x80257180
    {
            ctx->lr = 0x802570A8u;
            goto label_80257180;
    }

label_802570A8:
    ctx->pc = 0x802570A8u;
    ctx->downcount -= 7;
    // 802570A8: li      r0, 16
    ctx->gpr[0] = (u32)(s32)(16);

label_802570AC:
    ctx->pc = 0x802570ACu;
    // 802570AC: lwz     r29, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_802570B0:
    ctx->pc = 0x802570B0u;
    // 802570B0: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_802570B4:
    ctx->pc = 0x802570B4u;
    // 802570B4: addi    r30, r3, 0
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(0);

label_802570B8:
    ctx->pc = 0x802570B8u;
    // 802570B8: addi    r5, r1, 12
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(12);

label_802570BC:
    ctx->pc = 0x802570BCu;
    // 802570BC: addi    r4, r31, -8
    ctx->gpr[4] = ctx->gpr[31] + (u32)(s32)(-8);

label_802570C0:
    loop_802570C0(ctx);
    if (ctx->pc == 0x802570D4u) goto label_802570D4;
    return;
label_802570C4:
    ctx->pc = 0x802570C4u;
    // 802570C4: lwz     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802570C8:
    ctx->pc = 0x802570C8u;
    // 802570C8: stwu     r3, 8(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
        ctx->gpr[5] = ea;
    }

label_802570CC:
    ctx->pc = 0x802570CCu;
    // 802570CC: stw     r0, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802570D0:
    // 802570D0: bc    16, 0, 0x802570C0
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802570C0u;
                return;
            }
            goto label_802570C0;
        }
    }

label_802570D4:
    ctx->pc = 0x802570D4u;
    ctx->downcount -= 1;
    // 802570D4: bl      0x802440BC
    {
            ctx->lr = 0x802570D8u;
            ctx->pc = 0x802440BCu;
            return;
    }

label_802570D8:
    ctx->pc = 0x802570D8u;
    ctx->downcount -= 7;
    // 802570D8: stw     r29, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_802570DC:
    ctx->pc = 0x802570DCu;
    // 802570DC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802570E0:
    ctx->pc = 0x802570E0u;
    // 802570E0: stw     r29, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_802570E4:
    ctx->pc = 0x802570E4u;
    // 802570E4: stw     r0, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802570E8:
    ctx->pc = 0x802570E8u;
    // 802570E8: lwz     r4, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802570EC:
    ctx->pc = 0x802570ECu;
    // 802570EC: cmpwi   r4, 0
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

label_802570F0:
    ctx->pc = 0x802570F0u;
    // 802570F0: bc    4, 0, 0x80257100
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80257100;
        }
    }

label_802570F4:
    ctx->pc = 0x802570F4u;
    ctx->downcount -= 3;
    // 802570F4: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802570F8:
    ctx->pc = 0x802570F8u;
    // 802570F8: add   r0, r4, r0
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_802570FC:
    ctx->pc = 0x802570FCu;
    // 802570FC: stw     r0, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80257100:
    ctx->pc = 0x80257100u;
    ctx->downcount -= 1;
    // 80257100: bl      0x802440E4
    {
            ctx->lr = 0x80257104u;
            ctx->pc = 0x802440E4u;
            return;
    }

label_80257104:
    ctx->pc = 0x80257104u;
    ctx->downcount -= 2;
    // 80257104: addi    r3, r1, 20
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(20);

label_80257108:
    ctx->pc = 0x80257108u;
    // 80257108: bl      0x80256A60
    {
            ctx->lr = 0x8025710Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80256A60u;
                return;
            }
            goto label_80256A60;
    }

label_8025710C:
    ctx->pc = 0x8025710Cu;
    ctx->downcount -= 2;
    // 8025710C: cmplw   r30, r31
    {
        u32 val_a = (u32)(ctx->gpr[30]);
        u32 val_b = (u32)(ctx->gpr[31]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80257110:
    ctx->pc = 0x80257110u;
    // 80257110: bc    4, 2, 0x8025711C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8025711C;
        }
    }

label_80257114:
    ctx->pc = 0x80257114u;
    ctx->downcount -= 2;
    // 80257114: addi    r3, r1, 20
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(20);

label_80257118:
    ctx->pc = 0x80257118u;
    // 80257118: bl      0x80256950
    {
            ctx->lr = 0x8025711Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80256950u;
                return;
            }
            goto label_80256950;
    }

label_8025711C:
    ctx->pc = 0x8025711Cu;
    ctx->downcount -= 1;
    // 8025711C: bl      0x802440BC
    {
            ctx->lr = 0x80257120u;
            ctx->pc = 0x802440BCu;
            return;
    }

label_80257120:
    ctx->pc = 0x80257120u;
    ctx->downcount -= 7;
    // 80257120: stw     r29, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80257124:
    ctx->pc = 0x80257124u;
    // 80257124: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80257128:
    ctx->pc = 0x80257128u;
    // 80257128: stw     r29, 24(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_8025712C:
    ctx->pc = 0x8025712Cu;
    // 8025712C: stw     r0, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80257130:
    ctx->pc = 0x80257130u;
    // 80257130: lwz     r4, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80257134:
    ctx->pc = 0x80257134u;
    // 80257134: cmpwi   r4, 0
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

label_80257138:
    ctx->pc = 0x80257138u;
    // 80257138: bc    4, 0, 0x80257148
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80257148;
        }
    }

label_8025713C:
    ctx->pc = 0x8025713Cu;
    ctx->downcount -= 3;
    // 8025713C: lwz     r0, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257140:
    ctx->pc = 0x80257140u;
    // 80257140: add   r0, r4, r0
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80257144:
    ctx->pc = 0x80257144u;
    // 80257144: stw     r0, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80257148:
    ctx->pc = 0x80257148u;
    ctx->downcount -= 1;
    // 80257148: bl      0x802440E4
    {
            ctx->lr = 0x8025714Cu;
            ctx->pc = 0x802440E4u;
            return;
    }

label_8025714C:
    ctx->pc = 0x8025714Cu;
    ctx->downcount -= 2;
    // 8025714C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80257150:
    ctx->pc = 0x80257150u;
    // 80257150: bl      0x80256A60
    {
            ctx->lr = 0x80257154u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80256A60u;
                return;
            }
            goto label_80256A60;
    }

label_80257154:
    ctx->pc = 0x80257154u;
    ctx->downcount -= 2;
    // 80257154: cmplw   r30, r31
    {
        u32 val_a = (u32)(ctx->gpr[30]);
        u32 val_b = (u32)(ctx->gpr[31]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80257158:
    ctx->pc = 0x80257158u;
    // 80257158: bc    4, 2, 0x80257164
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80257164;
        }
    }

label_8025715C:
    ctx->pc = 0x8025715Cu;
    ctx->downcount -= 2;
    // 8025715C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80257160:
    ctx->pc = 0x80257160u;
    // 80257160: bl      0x80256950
    {
            ctx->lr = 0x80257164u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80256950u;
                return;
            }
            goto label_80256950;
    }

label_80257164:
    ctx->pc = 0x80257164u;
    ctx->downcount -= 8;
    // 80257164: lwz     r0, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257168:
    ctx->pc = 0x80257168u;
    // 80257168: lwz     r31, 164(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(164);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8025716C:
    ctx->pc = 0x8025716Cu;
    // 8025716C: lwz     r30, 160(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(160);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80257170:
    ctx->pc = 0x80257170u;
    // 80257170: lwz     r29, 156(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(156);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80257174:
    ctx->pc = 0x80257174u;
    // 80257174: addi    r1, r1, 168
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(168);

label_80257178:
    ctx->pc = 0x80257178u;
    // 80257178: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8025717C:
    ctx->pc = 0x8025717Cu;
    // 8025717C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80257180:
    ctx->pc = 0x80257180u;
    ctx->downcount -= 2;
    // 80257180: lwz     r3, -20688(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20688);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257184:
    ctx->pc = 0x80257184u;
    // 80257184: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80257188:
    ctx->pc = 0x80257188u;
    ctx->downcount -= 2;
    // 80257188: lwz     r3, -20684(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20684);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8025718C:
    ctx->pc = 0x8025718Cu;
    // 8025718C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80257190:
    ctx->pc = 0x80257190u;
    ctx->downcount -= 4;
    // 80257190: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80257194:
    ctx->pc = 0x80257194u;
    // 80257194: lwz     r4, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80257198:
    ctx->pc = 0x80257198u;
    // 80257198: rlwinm. r0, r4, 19, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 19u) & 0x00000003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8025719C:
    ctx->pc = 0x8025719Cu;
    // 8025719C: bc    12, 2, 0x802571A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802571A8;
        }
    }

label_802571A0:
    ctx->pc = 0x802571A0u;
    ctx->downcount -= 2;
    // 802571A0: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802571A4:
    ctx->pc = 0x802571A4u;
    // 802571A4: b       0x802571AC
    {
            goto label_802571AC;
    }

label_802571A8:
    ctx->pc = 0x802571A8u;
    ctx->downcount -= 1;
    // 802571A8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_802571AC:
    ctx->pc = 0x802571ACu;
    ctx->downcount -= 2;
    // 802571AC: rlwinm. r0, r4, 17, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 17u) & 0x00000003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802571B0:
    ctx->pc = 0x802571B0u;
    // 802571B0: bc    12, 2, 0x802571BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802571BC;
        }
    }

label_802571B4:
    ctx->pc = 0x802571B4u;
    ctx->downcount -= 2;
    // 802571B4: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_802571B8:
    ctx->pc = 0x802571B8u;
    // 802571B8: b       0x802571C0
    {
            goto label_802571C0;
    }

label_802571BC:
    ctx->pc = 0x802571BCu;
    ctx->downcount -= 1;
    // 802571BC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802571C0:
    ctx->pc = 0x802571C0u;
    ctx->downcount -= 4;
    // 802571C0: lbz     r0, 1053(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1053);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_802571C4:
    ctx->pc = 0x802571C4u;
    // 802571C4: add   r7, r3, r4
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_802571C8:
    ctx->pc = 0x802571C8u;
    // 802571C8: cmplwi  r0, 0x0000
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

label_802571CC:
    ctx->pc = 0x802571CCu;
    // 802571CC: bc    12, 2, 0x802571D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802571D8;
        }
    }

label_802571D0:
    ctx->pc = 0x802571D0u;
    ctx->downcount -= 2;
    // 802571D0: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_802571D4:
    ctx->pc = 0x802571D4u;
    // 802571D4: b       0x802571F0
    {
            goto label_802571F0;
    }

label_802571D8:
    ctx->pc = 0x802571D8u;
    ctx->downcount -= 3;
    // 802571D8: lbz     r0, 1052(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1052);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_802571DC:
    ctx->pc = 0x802571DCu;
    // 802571DC: cmplwi  r0, 0x0000
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

label_802571E0:
    ctx->pc = 0x802571E0u;
    // 802571E0: bc    12, 2, 0x802571EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802571EC;
        }
    }

label_802571E4:
    ctx->pc = 0x802571E4u;
    ctx->downcount -= 2;
    // 802571E4: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_802571E8:
    ctx->pc = 0x802571E8u;
    // 802571E8: b       0x802571F0
    {
            goto label_802571F0;
    }

label_802571EC:
    ctx->pc = 0x802571ECu;
    ctx->downcount -= 1;
    // 802571EC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_802571F0:
    ctx->pc = 0x802571F0u;
    ctx->downcount -= 3;
    // 802571F0: lwz     r6, 24(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(24);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802571F4:
    ctx->pc = 0x802571F4u;
    // 802571F4: rlwinm. r0, r6, 0, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x00000003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802571F8:
    ctx->pc = 0x802571F8u;
    // 802571F8: bc    12, 2, 0x80257204
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80257204;
        }
    }

label_802571FC:
    ctx->pc = 0x802571FCu;
    ctx->downcount -= 2;
    // 802571FC: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80257200:
    ctx->pc = 0x80257200u;
    // 80257200: b       0x80257208
    {
            goto label_80257208;
    }

label_80257204:
    ctx->pc = 0x80257204u;
    ctx->downcount -= 1;
    // 80257204: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80257208:
    ctx->pc = 0x80257208u;
    ctx->downcount -= 2;
    // 80257208: rlwinm. r0, r6, 30, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 30u) & 0x00000003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8025720C:
    ctx->pc = 0x8025720Cu;
    // 8025720C: bc    12, 2, 0x80257218
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80257218;
        }
    }

label_80257210:
    ctx->pc = 0x80257210u;
    ctx->downcount -= 2;
    // 80257210: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80257214:
    ctx->pc = 0x80257214u;
    // 80257214: b       0x8025721C
    {
            goto label_8025721C;
    }

label_80257218:
    ctx->pc = 0x80257218u;
    ctx->downcount -= 1;
    // 80257218: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8025721C:
    ctx->pc = 0x8025721Cu;
    ctx->downcount -= 3;
    // 8025721C: rlwinm. r0, r6, 28, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 28u) & 0x00000003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80257220:
    ctx->pc = 0x80257220u;
    // 80257220: add   r8, r3, r5
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_80257224:
    ctx->pc = 0x80257224u;
    // 80257224: bc    12, 2, 0x80257230
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80257230;
        }
    }

label_80257228:
    ctx->pc = 0x80257228u;
    ctx->downcount -= 2;
    // 80257228: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8025722C:
    ctx->pc = 0x8025722Cu;
    // 8025722C: b       0x80257234
    {
            goto label_80257234;
    }

label_80257230:
    ctx->pc = 0x80257230u;
    ctx->downcount -= 1;
    // 80257230: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80257234:
    ctx->pc = 0x80257234u;
    ctx->downcount -= 3;
    // 80257234: rlwinm. r0, r6, 26, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 26u) & 0x00000003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80257238:
    ctx->pc = 0x80257238u;
    // 80257238: add   r8, r8, r3
    {
        u32 a = ctx->gpr[8];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_8025723C:
    ctx->pc = 0x8025723Cu;
    // 8025723C: bc    12, 2, 0x80257248
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80257248;
        }
    }

label_80257240:
    ctx->pc = 0x80257240u;
    ctx->downcount -= 2;
    // 80257240: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80257244:
    ctx->pc = 0x80257244u;
    // 80257244: b       0x8025724C
    {
            goto label_8025724C;
    }

label_80257248:
    ctx->pc = 0x80257248u;
    ctx->downcount -= 1;
    // 80257248: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8025724C:
    ctx->pc = 0x8025724Cu;
    ctx->downcount -= 3;
    // 8025724C: rlwinm. r0, r6, 24, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 24u) & 0x00000003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80257250:
    ctx->pc = 0x80257250u;
    // 80257250: add   r8, r8, r3
    {
        u32 a = ctx->gpr[8];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_80257254:
    ctx->pc = 0x80257254u;
    // 80257254: bc    12, 2, 0x80257260
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80257260;
        }
    }

label_80257258:
    ctx->pc = 0x80257258u;
    ctx->downcount -= 2;
    // 80257258: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8025725C:
    ctx->pc = 0x8025725Cu;
    // 8025725C: b       0x80257264
    {
            goto label_80257264;
    }

label_80257260:
    ctx->pc = 0x80257260u;
    ctx->downcount -= 1;
    // 80257260: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80257264:
    ctx->pc = 0x80257264u;
    ctx->downcount -= 3;
    // 80257264: rlwinm. r0, r6, 22, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 22u) & 0x00000003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80257268:
    ctx->pc = 0x80257268u;
    // 80257268: add   r8, r8, r3
    {
        u32 a = ctx->gpr[8];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_8025726C:
    ctx->pc = 0x8025726Cu;
    // 8025726C: bc    12, 2, 0x80257278
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80257278;
        }
    }

label_80257270:
    ctx->pc = 0x80257270u;
    ctx->downcount -= 2;
    // 80257270: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80257274:
    ctx->pc = 0x80257274u;
    // 80257274: b       0x8025727C
    {
            goto label_8025727C;
    }

label_80257278:
    ctx->pc = 0x80257278u;
    ctx->downcount -= 1;
    // 80257278: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8025727C:
    ctx->pc = 0x8025727Cu;
    ctx->downcount -= 3;
    // 8025727C: rlwinm. r0, r6, 20, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 20u) & 0x00000003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80257280:
    ctx->pc = 0x80257280u;
    // 80257280: add   r8, r8, r3
    {
        u32 a = ctx->gpr[8];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_80257284:
    ctx->pc = 0x80257284u;
    // 80257284: bc    12, 2, 0x80257290
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80257290;
        }
    }

label_80257288:
    ctx->pc = 0x80257288u;
    ctx->downcount -= 2;
    // 80257288: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8025728C:
    ctx->pc = 0x8025728Cu;
    // 8025728C: b       0x80257294
    {
            goto label_80257294;
    }

label_80257290:
    ctx->pc = 0x80257290u;
    ctx->downcount -= 1;
    // 80257290: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80257294:
    ctx->pc = 0x80257294u;
    ctx->downcount -= 3;
    // 80257294: rlwinm. r0, r6, 18, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 18u) & 0x00000003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80257298:
    ctx->pc = 0x80257298u;
    // 80257298: add   r8, r8, r3
    {
        u32 a = ctx->gpr[8];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_8025729C:
    ctx->pc = 0x8025729Cu;
    // 8025729C: bc    12, 2, 0x802572A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802572A8;
        }
    }

label_802572A0:
    ctx->pc = 0x802572A0u;
    ctx->downcount -= 2;
    // 802572A0: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_802572A4:
    ctx->pc = 0x802572A4u;
    // 802572A4: b       0x802572AC
    {
            goto label_802572AC;
    }

label_802572A8:
    ctx->pc = 0x802572A8u;
    ctx->downcount -= 1;
    // 802572A8: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_802572AC:
    ctx->pc = 0x802572ACu;
    ctx->downcount -= 15;
    // 802572AC: li      r0, 16
    ctx->gpr[0] = (u32)(s32)(16);

label_802572B0:
    ctx->pc = 0x802572B0u;
    // 802572B0: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802572B4:
    ctx->pc = 0x802572B4u;
    // 802572B4: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_802572B8:
    ctx->pc = 0x802572B8u;
    // 802572B8: add   r8, r8, r6
    {
        u32 a = ctx->gpr[8];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_802572BC:
    ctx->pc = 0x802572BCu;
    // 802572BC: stb     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802572C0:
    ctx->pc = 0x802572C0u;
    // 802572C0: rlwinm r0, r4, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 2u) & 0xFFFFFFFCu;
    }

label_802572C4:
    ctx->pc = 0x802572C4u;
    // 802572C4: li      r4, 4104
    ctx->gpr[4] = (u32)(s32)(4104);

label_802572C8:
    ctx->pc = 0x802572C8u;
    // 802572C8: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802572CC:
    ctx->pc = 0x802572CCu;
    // 802572CC: rlwinm r4, r8, 4, 0, 27
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[8], 4u) & 0xFFFFFFF0u;
    }

label_802572D0:
    ctx->pc = 0x802572D0u;
    // 802572D0: or   r0, r7, r0
    {
        ctx->gpr[0] = ctx->gpr[7] | ctx->gpr[0];
    }

label_802572D4:
    ctx->pc = 0x802572D4u;
    // 802572D4: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_802572D8:
    ctx->pc = 0x802572D8u;
    // 802572D8: stw     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802572DC:
    ctx->pc = 0x802572DCu;
    // 802572DC: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_802572E0:
    ctx->pc = 0x802572E0u;
    // 802572E0: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802572E4:
    ctx->pc = 0x802572E4u;
    // 802572E4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_802572E8:
    ctx->pc = 0x802572E8u;
    ctx->downcount -= 2;
    // 802572E8: cmplwi  r3, 0x0019
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0019u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802572EC:
    ctx->pc = 0x802572ECu;
    // 802572EC: bc    12, 1, 0x802575EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802575EC;
        }
    }

label_802572F0:
    ctx->pc = 0x802572F0u;
    ctx->downcount -= 7;
    // 802572F0: lis     r5, -32717
    ctx->gpr[5] = ((u32)(s32)(-32717) << 16);

label_802572F4:
    ctx->pc = 0x802572F4u;
    // 802572F4: addi    r5, r5, -704
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(-704);

label_802572F8:
    ctx->pc = 0x802572F8u;
    // 802572F8: rlwinm r0, r3, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0xFFFFFFFCu;
    }

label_802572FC:
    ctx->pc = 0x802572FCu;
    // 802572FC: lwzx    r0, r5, r0
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257300:
    ctx->pc = 0x80257300u;
    // 80257300: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_80257304:
    ctx->pc = 0x80257304u;
    // 80257304: bctr
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            return;
        }
    }

label_80257308:
    ctx->pc = 0x80257308u;
    ctx->downcount -= 6;
    // 80257308: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8025730C:
    ctx->pc = 0x8025730Cu;
    // 8025730C: lwzu     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_80257310:
    ctx->pc = 0x80257310u;
    // 80257310: rlwinm r0, r0, 0, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFEu;
    }

label_80257314:
    ctx->pc = 0x80257314u;
    // 80257314: or   r0, r0, r4
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[4];
    }

label_80257318:
    ctx->pc = 0x80257318u;
    // 80257318: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8025731C:
    ctx->pc = 0x8025731Cu;
    // 8025731C: b       0x802575EC
    {
            goto label_802575EC;
    }

label_80257320:
    ctx->pc = 0x80257320u;
    ctx->downcount -= 8;
    // 80257320: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257324:
    ctx->pc = 0x80257324u;
    // 80257324: rlwinm r0, r4, 1, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 1u) & 0xFFFFFFFEu;
    }

label_80257328:
    ctx->pc = 0x80257328u;
    // 80257328: addi    r4, r3, 20
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20);

label_8025732C:
    ctx->pc = 0x8025732Cu;
    // 8025732C: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257330:
    ctx->pc = 0x80257330u;
    // 80257330: rlwinm r3, r3, 0, 31, 29
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFFDu;
    }

label_80257334:
    ctx->pc = 0x80257334u;
    // 80257334: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80257338:
    ctx->pc = 0x80257338u;
    // 80257338: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8025733C:
    ctx->pc = 0x8025733Cu;
    // 8025733C: b       0x802575EC
    {
            goto label_802575EC;
    }

label_80257340:
    ctx->pc = 0x80257340u;
    ctx->downcount -= 8;
    // 80257340: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257344:
    ctx->pc = 0x80257344u;
    // 80257344: rlwinm r0, r4, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 2u) & 0xFFFFFFFCu;
    }

label_80257348:
    ctx->pc = 0x80257348u;
    // 80257348: addi    r4, r3, 20
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20);

label_8025734C:
    ctx->pc = 0x8025734Cu;
    // 8025734C: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257350:
    ctx->pc = 0x80257350u;
    // 80257350: rlwinm r3, r3, 0, 30, 28
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFFBu;
    }

label_80257354:
    ctx->pc = 0x80257354u;
    // 80257354: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80257358:
    ctx->pc = 0x80257358u;
    // 80257358: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8025735C:
    ctx->pc = 0x8025735Cu;
    // 8025735C: b       0x802575EC
    {
            goto label_802575EC;
    }

label_80257360:
    ctx->pc = 0x80257360u;
    ctx->downcount -= 8;
    // 80257360: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257364:
    ctx->pc = 0x80257364u;
    // 80257364: rlwinm r0, r4, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 3u) & 0xFFFFFFF8u;
    }

label_80257368:
    ctx->pc = 0x80257368u;
    // 80257368: addi    r4, r3, 20
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20);

label_8025736C:
    ctx->pc = 0x8025736Cu;
    // 8025736C: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257370:
    ctx->pc = 0x80257370u;
    // 80257370: rlwinm r3, r3, 0, 29, 27
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFF7u;
    }

label_80257374:
    ctx->pc = 0x80257374u;
    // 80257374: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80257378:
    ctx->pc = 0x80257378u;
    // 80257378: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8025737C:
    ctx->pc = 0x8025737Cu;
    // 8025737C: b       0x802575EC
    {
            goto label_802575EC;
    }

label_80257380:
    ctx->pc = 0x80257380u;
    ctx->downcount -= 8;
    // 80257380: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257384:
    ctx->pc = 0x80257384u;
    // 80257384: rlwinm r0, r4, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 4u) & 0xFFFFFFF0u;
    }

label_80257388:
    ctx->pc = 0x80257388u;
    // 80257388: addi    r4, r3, 20
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20);

label_8025738C:
    ctx->pc = 0x8025738Cu;
    // 8025738C: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257390:
    ctx->pc = 0x80257390u;
    // 80257390: rlwinm r3, r3, 0, 28, 26
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFEFu;
    }

label_80257394:
    ctx->pc = 0x80257394u;
    // 80257394: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80257398:
    ctx->pc = 0x80257398u;
    // 80257398: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8025739C:
    ctx->pc = 0x8025739Cu;
    // 8025739C: b       0x802575EC
    {
            goto label_802575EC;
    }

label_802573A0:
    ctx->pc = 0x802573A0u;
    ctx->downcount -= 8;
    // 802573A0: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802573A4:
    ctx->pc = 0x802573A4u;
    // 802573A4: rlwinm r0, r4, 5, 0, 26
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 5u) & 0xFFFFFFE0u;
    }

label_802573A8:
    ctx->pc = 0x802573A8u;
    // 802573A8: addi    r4, r3, 20
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20);

label_802573AC:
    ctx->pc = 0x802573ACu;
    // 802573AC: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802573B0:
    ctx->pc = 0x802573B0u;
    // 802573B0: rlwinm r3, r3, 0, 27, 25
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFDFu;
    }

label_802573B4:
    ctx->pc = 0x802573B4u;
    // 802573B4: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802573B8:
    ctx->pc = 0x802573B8u;
    // 802573B8: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802573BC:
    ctx->pc = 0x802573BCu;
    // 802573BC: b       0x802575EC
    {
            goto label_802575EC;
    }

label_802573C0:
    ctx->pc = 0x802573C0u;
    ctx->downcount -= 8;
    // 802573C0: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802573C4:
    ctx->pc = 0x802573C4u;
    // 802573C4: rlwinm r0, r4, 6, 0, 25
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 6u) & 0xFFFFFFC0u;
    }

label_802573C8:
    ctx->pc = 0x802573C8u;
    // 802573C8: addi    r4, r3, 20
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20);

label_802573CC:
    ctx->pc = 0x802573CCu;
    // 802573CC: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802573D0:
    ctx->pc = 0x802573D0u;
    // 802573D0: rlwinm r3, r3, 0, 26, 24
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFBFu;
    }

label_802573D4:
    ctx->pc = 0x802573D4u;
    // 802573D4: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802573D8:
    ctx->pc = 0x802573D8u;
    // 802573D8: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802573DC:
    ctx->pc = 0x802573DCu;
    // 802573DC: b       0x802575EC
    {
            goto label_802575EC;
    }

label_802573E0:
    ctx->pc = 0x802573E0u;
    ctx->downcount -= 8;
    // 802573E0: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802573E4:
    ctx->pc = 0x802573E4u;
    // 802573E4: rlwinm r0, r4, 7, 0, 24
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 7u) & 0xFFFFFF80u;
    }

label_802573E8:
    ctx->pc = 0x802573E8u;
    // 802573E8: addi    r4, r3, 20
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20);

label_802573EC:
    ctx->pc = 0x802573ECu;
    // 802573EC: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802573F0:
    ctx->pc = 0x802573F0u;
    // 802573F0: rlwinm r3, r3, 0, 25, 23
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFF7Fu;
    }

label_802573F4:
    ctx->pc = 0x802573F4u;
    // 802573F4: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802573F8:
    ctx->pc = 0x802573F8u;
    // 802573F8: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802573FC:
    ctx->pc = 0x802573FCu;
    // 802573FC: b       0x802575EC
    {
            goto label_802575EC;
    }

label_80257400:
    ctx->pc = 0x80257400u;
    ctx->downcount -= 8;
    // 80257400: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257404:
    ctx->pc = 0x80257404u;
    // 80257404: rlwinm r0, r4, 8, 0, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 8u) & 0xFFFFFF00u;
    }

label_80257408:
    ctx->pc = 0x80257408u;
    // 80257408: addi    r4, r3, 20
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20);

label_8025740C:
    ctx->pc = 0x8025740Cu;
    // 8025740C: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257410:
    ctx->pc = 0x80257410u;
    // 80257410: rlwinm r3, r3, 0, 24, 22
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFEFFu;
    }

label_80257414:
    ctx->pc = 0x80257414u;
    // 80257414: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80257418:
    ctx->pc = 0x80257418u;
    // 80257418: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8025741C:
    ctx->pc = 0x8025741Cu;
    // 8025741C: b       0x802575EC
    {
            goto label_802575EC;
    }

label_80257420:
    ctx->pc = 0x80257420u;
    ctx->downcount -= 8;
    // 80257420: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257424:
    ctx->pc = 0x80257424u;
    // 80257424: rlwinm r0, r4, 9, 0, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 9u) & 0xFFFFFE00u;
    }

label_80257428:
    ctx->pc = 0x80257428u;
    // 80257428: addi    r4, r3, 20
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20);

label_8025742C:
    ctx->pc = 0x8025742Cu;
    // 8025742C: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257430:
    ctx->pc = 0x80257430u;
    // 80257430: rlwinm r3, r3, 0, 23, 20
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFF9FFu;
    }

label_80257434:
    ctx->pc = 0x80257434u;
    // 80257434: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80257438:
    ctx->pc = 0x80257438u;
    // 80257438: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8025743C:
    ctx->pc = 0x8025743Cu;
    // 8025743C: b       0x802575EC
    {
            goto label_802575EC;
    }

label_80257440:
    ctx->pc = 0x80257440u;
    ctx->downcount -= 2;
    // 80257440: cmpwi   r4, 0
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

label_80257444:
    ctx->pc = 0x80257444u;
    // 80257444: bc    12, 2, 0x8025746C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8025746C;
        }
    }

label_80257448:
    ctx->pc = 0x80257448u;
    ctx->downcount -= 9;
    // 80257448: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8025744C:
    ctx->pc = 0x8025744Cu;
    // 8025744C: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80257450:
    ctx->pc = 0x80257450u;
    // 80257450: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80257454:
    ctx->pc = 0x80257454u;
    // 80257454: stb     r5, 1052(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1052);
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

label_80257458:
    ctx->pc = 0x80257458u;
    // 80257458: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8025745C:
    ctx->pc = 0x8025745Cu;
    // 8025745C: stb     r0, 1053(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1053);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80257460:
    ctx->pc = 0x80257460u;
    // 80257460: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257464:
    ctx->pc = 0x80257464u;
    // 80257464: stw     r4, 1048(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1048);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80257468:
    ctx->pc = 0x80257468u;
    // 80257468: b       0x802575EC
    {
            goto label_802575EC;
    }

label_8025746C:
    ctx->pc = 0x8025746Cu;
    ctx->downcount -= 4;
    // 8025746C: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257470:
    ctx->pc = 0x80257470u;
    // 80257470: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80257474:
    ctx->pc = 0x80257474u;
    // 80257474: stb     r0, 1052(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1052);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80257478:
    ctx->pc = 0x80257478u;
    // 80257478: b       0x802575EC
    {
            goto label_802575EC;
    }

label_8025747C:
    ctx->pc = 0x8025747Cu;
    ctx->downcount -= 2;
    // 8025747C: cmpwi   r4, 0
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

label_80257480:
    ctx->pc = 0x80257480u;
    // 80257480: bc    12, 2, 0x802574A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802574A8;
        }
    }

label_80257484:
    ctx->pc = 0x80257484u;
    ctx->downcount -= 9;
    // 80257484: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257488:
    ctx->pc = 0x80257488u;
    // 80257488: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_8025748C:
    ctx->pc = 0x8025748Cu;
    // 8025748C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80257490:
    ctx->pc = 0x80257490u;
    // 80257490: stb     r5, 1053(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1053);
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

label_80257494:
    ctx->pc = 0x80257494u;
    // 80257494: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257498:
    ctx->pc = 0x80257498u;
    // 80257498: stb     r0, 1052(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1052);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8025749C:
    ctx->pc = 0x8025749Cu;
    // 8025749C: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802574A0:
    ctx->pc = 0x802574A0u;
    // 802574A0: stw     r4, 1048(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1048);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802574A4:
    ctx->pc = 0x802574A4u;
    // 802574A4: b       0x802575EC
    {
            goto label_802575EC;
    }

label_802574A8:
    ctx->pc = 0x802574A8u;
    ctx->downcount -= 4;
    // 802574A8: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802574AC:
    ctx->pc = 0x802574ACu;
    // 802574AC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802574B0:
    ctx->pc = 0x802574B0u;
    // 802574B0: stb     r0, 1053(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1053);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802574B4:
    ctx->pc = 0x802574B4u;
    // 802574B4: b       0x802575EC
    {
            goto label_802575EC;
    }

label_802574B8:
    ctx->pc = 0x802574B8u;
    ctx->downcount -= 8;
    // 802574B8: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802574BC:
    ctx->pc = 0x802574BCu;
    // 802574BC: rlwinm r0, r4, 13, 0, 18
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 13u) & 0xFFFFE000u;
    }

label_802574C0:
    ctx->pc = 0x802574C0u;
    // 802574C0: addi    r4, r3, 20
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20);

label_802574C4:
    ctx->pc = 0x802574C4u;
    // 802574C4: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802574C8:
    ctx->pc = 0x802574C8u;
    // 802574C8: rlwinm r3, r3, 0, 19, 16
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFF9FFFu;
    }

label_802574CC:
    ctx->pc = 0x802574CCu;
    // 802574CC: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802574D0:
    ctx->pc = 0x802574D0u;
    // 802574D0: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802574D4:
    ctx->pc = 0x802574D4u;
    // 802574D4: b       0x802575EC
    {
            goto label_802575EC;
    }

label_802574D8:
    ctx->pc = 0x802574D8u;
    ctx->downcount -= 8;
    // 802574D8: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802574DC:
    ctx->pc = 0x802574DCu;
    // 802574DC: rlwinm r0, r4, 15, 0, 16
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 15u) & 0xFFFF8000u;
    }

label_802574E0:
    ctx->pc = 0x802574E0u;
    // 802574E0: addi    r4, r3, 20
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20);

label_802574E4:
    ctx->pc = 0x802574E4u;
    // 802574E4: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802574E8:
    ctx->pc = 0x802574E8u;
    // 802574E8: rlwinm r3, r3, 0, 17, 14
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFE7FFFu;
    }

label_802574EC:
    ctx->pc = 0x802574ECu;
    // 802574EC: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802574F0:
    ctx->pc = 0x802574F0u;
    // 802574F0: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802574F4:
    ctx->pc = 0x802574F4u;
    // 802574F4: b       0x802575EC
    {
            goto label_802575EC;
    }

label_802574F8:
    ctx->pc = 0x802574F8u;
    ctx->downcount -= 6;
    // 802574F8: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802574FC:
    ctx->pc = 0x802574FCu;
    // 802574FC: lwzu     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_80257500:
    ctx->pc = 0x80257500u;
    // 80257500: rlwinm r0, r0, 0, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFCu;
    }

label_80257504:
    ctx->pc = 0x80257504u;
    // 80257504: or   r0, r0, r4
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[4];
    }

label_80257508:
    ctx->pc = 0x80257508u;
    // 80257508: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8025750C:
    ctx->pc = 0x8025750Cu;
    // 8025750C: b       0x802575EC
    {
            goto label_802575EC;
    }

label_80257510:
    ctx->pc = 0x80257510u;
    ctx->downcount -= 8;
    // 80257510: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257514:
    ctx->pc = 0x80257514u;
    // 80257514: rlwinm r0, r4, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 2u) & 0xFFFFFFFCu;
    }

label_80257518:
    ctx->pc = 0x80257518u;
    // 80257518: addi    r4, r3, 24
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(24);

label_8025751C:
    ctx->pc = 0x8025751Cu;
    // 8025751C: lwz     r3, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257520:
    ctx->pc = 0x80257520u;
    // 80257520: rlwinm r3, r3, 0, 30, 27
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFF3u;
    }

label_80257524:
    ctx->pc = 0x80257524u;
    // 80257524: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80257528:
    ctx->pc = 0x80257528u;
    // 80257528: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8025752C:
    ctx->pc = 0x8025752Cu;
    // 8025752C: b       0x802575EC
    {
            goto label_802575EC;
    }

label_80257530:
    ctx->pc = 0x80257530u;
    ctx->downcount -= 8;
    // 80257530: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257534:
    ctx->pc = 0x80257534u;
    // 80257534: rlwinm r0, r4, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 4u) & 0xFFFFFFF0u;
    }

label_80257538:
    ctx->pc = 0x80257538u;
    // 80257538: addi    r4, r3, 24
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(24);

label_8025753C:
    ctx->pc = 0x8025753Cu;
    // 8025753C: lwz     r3, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257540:
    ctx->pc = 0x80257540u;
    // 80257540: rlwinm r3, r3, 0, 28, 25
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFCFu;
    }

label_80257544:
    ctx->pc = 0x80257544u;
    // 80257544: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80257548:
    ctx->pc = 0x80257548u;
    // 80257548: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8025754C:
    ctx->pc = 0x8025754Cu;
    // 8025754C: b       0x802575EC
    {
            goto label_802575EC;
    }

label_80257550:
    ctx->pc = 0x80257550u;
    ctx->downcount -= 8;
    // 80257550: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257554:
    ctx->pc = 0x80257554u;
    // 80257554: rlwinm r0, r4, 6, 0, 25
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 6u) & 0xFFFFFFC0u;
    }

label_80257558:
    ctx->pc = 0x80257558u;
    // 80257558: addi    r4, r3, 24
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(24);

label_8025755C:
    ctx->pc = 0x8025755Cu;
    // 8025755C: lwz     r3, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257560:
    ctx->pc = 0x80257560u;
    // 80257560: rlwinm r3, r3, 0, 26, 23
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFF3Fu;
    }

label_80257564:
    ctx->pc = 0x80257564u;
    // 80257564: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80257568:
    ctx->pc = 0x80257568u;
    // 80257568: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8025756C:
    ctx->pc = 0x8025756Cu;
    // 8025756C: b       0x802575EC
    {
            goto label_802575EC;
    }

label_80257570:
    ctx->pc = 0x80257570u;
    ctx->downcount -= 8;
    // 80257570: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257574:
    ctx->pc = 0x80257574u;
    // 80257574: rlwinm r0, r4, 8, 0, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 8u) & 0xFFFFFF00u;
    }

label_80257578:
    ctx->pc = 0x80257578u;
    // 80257578: addi    r4, r3, 24
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(24);

label_8025757C:
    ctx->pc = 0x8025757Cu;
    // 8025757C: lwz     r3, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257580:
    ctx->pc = 0x80257580u;
    // 80257580: rlwinm r3, r3, 0, 24, 21
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFCFFu;
    }

label_80257584:
    ctx->pc = 0x80257584u;
    // 80257584: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80257588:
    ctx->pc = 0x80257588u;
    // 80257588: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8025758C:
    ctx->pc = 0x8025758Cu;
    // 8025758C: b       0x802575EC
    {
            goto label_802575EC;
    }

label_80257590:
    ctx->pc = 0x80257590u;
    ctx->downcount -= 8;
    // 80257590: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257594:
    ctx->pc = 0x80257594u;
    // 80257594: rlwinm r0, r4, 10, 0, 21
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 10u) & 0xFFFFFC00u;
    }

label_80257598:
    ctx->pc = 0x80257598u;
    // 80257598: addi    r4, r3, 24
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(24);

label_8025759C:
    ctx->pc = 0x8025759Cu;
    // 8025759C: lwz     r3, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802575A0:
    ctx->pc = 0x802575A0u;
    // 802575A0: rlwinm r3, r3, 0, 22, 19
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFF3FFu;
    }

label_802575A4:
    ctx->pc = 0x802575A4u;
    // 802575A4: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802575A8:
    ctx->pc = 0x802575A8u;
    // 802575A8: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802575AC:
    ctx->pc = 0x802575ACu;
    // 802575AC: b       0x802575EC
    {
            goto label_802575EC;
    }

label_802575B0:
    ctx->pc = 0x802575B0u;
    ctx->downcount -= 8;
    // 802575B0: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802575B4:
    ctx->pc = 0x802575B4u;
    // 802575B4: rlwinm r0, r4, 12, 0, 19
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 12u) & 0xFFFFF000u;
    }

label_802575B8:
    ctx->pc = 0x802575B8u;
    // 802575B8: addi    r4, r3, 24
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(24);

label_802575BC:
    ctx->pc = 0x802575BCu;
    // 802575BC: lwz     r3, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802575C0:
    ctx->pc = 0x802575C0u;
    // 802575C0: rlwinm r3, r3, 0, 20, 17
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFCFFFu;
    }

label_802575C4:
    ctx->pc = 0x802575C4u;
    // 802575C4: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802575C8:
    ctx->pc = 0x802575C8u;
    // 802575C8: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802575CC:
    ctx->pc = 0x802575CCu;
    // 802575CC: b       0x802575EC
    {
            goto label_802575EC;
    }

label_802575D0:
    ctx->pc = 0x802575D0u;
    ctx->downcount -= 7;
    // 802575D0: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802575D4:
    ctx->pc = 0x802575D4u;
    // 802575D4: rlwinm r0, r4, 14, 0, 17
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 14u) & 0xFFFFC000u;
    }

label_802575D8:
    ctx->pc = 0x802575D8u;
    // 802575D8: addi    r4, r3, 24
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(24);

label_802575DC:
    ctx->pc = 0x802575DCu;
    // 802575DC: lwz     r3, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802575E0:
    ctx->pc = 0x802575E0u;
    // 802575E0: rlwinm r3, r3, 0, 18, 15
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFF3FFFu;
    }

label_802575E4:
    ctx->pc = 0x802575E4u;
    // 802575E4: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802575E8:
    ctx->pc = 0x802575E8u;
    // 802575E8: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802575EC:
    ctx->pc = 0x802575ECu;
    ctx->downcount -= 4;
    // 802575EC: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802575F0:
    ctx->pc = 0x802575F0u;
    // 802575F0: lbz     r0, 1052(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1052);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_802575F4:
    ctx->pc = 0x802575F4u;
    // 802575F4: cmplwi  r0, 0x0000
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

label_802575F8:
    ctx->pc = 0x802575F8u;
    // 802575F8: bc    4, 2, 0x80257608
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80257608;
        }
    }

label_802575FC:
    ctx->pc = 0x802575FCu;
    ctx->downcount -= 3;
    // 802575FC: lbz     r0, 1053(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1053);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80257600:
    ctx->pc = 0x80257600u;
    // 80257600: cmplwi  r0, 0x0000
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

label_80257604:
    ctx->pc = 0x80257604u;
    // 80257604: bc    12, 2, 0x80257628
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80257628;
        }
    }

label_80257608:
    ctx->pc = 0x80257608u;
    ctx->downcount -= 8;
    // 80257608: addi    r4, r3, 20
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20);

label_8025760C:
    ctx->pc = 0x8025760Cu;
    // 8025760C: lwz     r0, 1048(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1048);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257610:
    ctx->pc = 0x80257610u;
    // 80257610: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257614:
    ctx->pc = 0x80257614u;
    // 80257614: rlwinm r0, r0, 11, 0, 20
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 11u) & 0xFFFFF800u;
    }

label_80257618:
    ctx->pc = 0x80257618u;
    // 80257618: rlwinm r3, r3, 0, 21, 18
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFE7FFu;
    }

label_8025761C:
    ctx->pc = 0x8025761Cu;
    // 8025761C: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80257620:
    ctx->pc = 0x80257620u;
    // 80257620: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80257624:
    ctx->pc = 0x80257624u;
    // 80257624: b       0x80257634
    {
            goto label_80257634;
    }

label_80257628:
    ctx->pc = 0x80257628u;
    ctx->downcount -= 3;
    // 80257628: lwzu     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_8025762C:
    ctx->pc = 0x8025762Cu;
    // 8025762C: rlwinm r0, r0, 0, 21, 18
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFE7FFu;
    }

label_80257630:
    ctx->pc = 0x80257630u;
    // 80257630: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80257634:
    ctx->pc = 0x80257634u;
    ctx->downcount -= 5;
    // 80257634: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257638:
    ctx->pc = 0x80257638u;
    // 80257638: lwz     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8025763C:
    ctx->pc = 0x8025763Cu;
    // 8025763C: ori     r0, r0, 0x0008
    ctx->gpr[0] = ctx->gpr[0] | 0x0008u;

label_80257640:
    ctx->pc = 0x80257640u;
    // 80257640: stw     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80257644:
    ctx->pc = 0x80257644u;
    // 80257644: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80257648:
    ctx->pc = 0x80257648u;
    ctx->downcount -= 3;
    // 80257648: lis     r4, -32717
    ctx->gpr[4] = ((u32)(s32)(-32717) << 16);

label_8025764C:
    ctx->pc = 0x8025764Cu;
    // 8025764C: addi    r4, r4, -600
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-600);

label_80257650:
    ctx->pc = 0x80257650u;
    // 80257650: b       0x80257964
    {
            goto label_80257964;
    }

label_80257654:
    ctx->pc = 0x80257654u;
    ctx->downcount -= 4;
    // 80257654: lwz     r5, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80257658:
    ctx->pc = 0x80257658u;
    // 80257658: lwz     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8025765C:
    // 8025765C: cmplwi  r5, 0x0019
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(0x0019u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80257660:
    // 80257660: bc    12, 1, 0x80257960
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80257960;
        }
    }

label_80257664:
    ctx->downcount -= 5;
    // 80257664: rlwinm r5, r5, 2, 0, 29
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 2u) & 0xFFFFFFFCu;
    }

label_80257668:
    ctx->pc = 0x80257668u;
    // 80257668: lwzx    r5, r4, r5
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[5];
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8025766C:
    ctx->pc = 0x8025766Cu;
    // 8025766C: mtctr    r5
    ctx->ctr = ctx->gpr[5];

label_80257670:
    ctx->pc = 0x80257670u;
    // 80257670: bctr
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            return;
        }
    }

label_80257674:
    ctx->pc = 0x80257674u;
    ctx->downcount -= 7;
    // 80257674: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80257678:
    // 80257678: addi    r6, r5, 20
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(20);

label_8025767C:
    ctx->pc = 0x8025767Cu;
    // 8025767C: lwz     r5, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80257680:
    // 80257680: rlwinm r5, r5, 0, 0, 30
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFFEu;
    }

label_80257684:
    // 80257684: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80257688:
    ctx->pc = 0x80257688u;
    // 80257688: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8025768C:
    // 8025768C: b       0x80257960
    {
            goto label_80257960;
    }

label_80257690:
    ctx->pc = 0x80257690u;
    ctx->downcount -= 8;
    // 80257690: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80257694:
    // 80257694: rlwinm r0, r0, 1, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 1u) & 0xFFFFFFFEu;
    }

label_80257698:
    // 80257698: addi    r6, r5, 20
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(20);

label_8025769C:
    ctx->pc = 0x8025769Cu;
    // 8025769C: lwz     r5, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802576A0:
    // 802576A0: rlwinm r5, r5, 0, 31, 29
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFFDu;
    }

label_802576A4:
    // 802576A4: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_802576A8:
    ctx->pc = 0x802576A8u;
    // 802576A8: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802576AC:
    // 802576AC: b       0x80257960
    {
            goto label_80257960;
    }

label_802576B0:
    ctx->pc = 0x802576B0u;
    ctx->downcount -= 8;
    // 802576B0: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802576B4:
    // 802576B4: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_802576B8:
    // 802576B8: addi    r6, r5, 20
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(20);

label_802576BC:
    ctx->pc = 0x802576BCu;
    // 802576BC: lwz     r5, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802576C0:
    // 802576C0: rlwinm r5, r5, 0, 30, 28
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFFBu;
    }

label_802576C4:
    // 802576C4: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_802576C8:
    ctx->pc = 0x802576C8u;
    // 802576C8: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802576CC:
    // 802576CC: b       0x80257960
    {
            goto label_80257960;
    }

label_802576D0:
    ctx->pc = 0x802576D0u;
    ctx->downcount -= 8;
    // 802576D0: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802576D4:
    // 802576D4: rlwinm r0, r0, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 3u) & 0xFFFFFFF8u;
    }

label_802576D8:
    // 802576D8: addi    r6, r5, 20
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(20);

label_802576DC:
    ctx->pc = 0x802576DCu;
    // 802576DC: lwz     r5, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802576E0:
    // 802576E0: rlwinm r5, r5, 0, 29, 27
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFF7u;
    }

label_802576E4:
    // 802576E4: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_802576E8:
    ctx->pc = 0x802576E8u;
    // 802576E8: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802576EC:
    // 802576EC: b       0x80257960
    {
            goto label_80257960;
    }

label_802576F0:
    ctx->pc = 0x802576F0u;
    ctx->downcount -= 8;
    // 802576F0: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802576F4:
    // 802576F4: rlwinm r0, r0, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 4u) & 0xFFFFFFF0u;
    }

label_802576F8:
    // 802576F8: addi    r6, r5, 20
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(20);

label_802576FC:
    ctx->pc = 0x802576FCu;
    // 802576FC: lwz     r5, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80257700:
    // 80257700: rlwinm r5, r5, 0, 28, 26
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFEFu;
    }

label_80257704:
    // 80257704: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80257708:
    ctx->pc = 0x80257708u;
    // 80257708: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8025770C:
    // 8025770C: b       0x80257960
    {
            goto label_80257960;
    }

label_80257710:
    ctx->pc = 0x80257710u;
    ctx->downcount -= 8;
    // 80257710: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80257714:
    // 80257714: rlwinm r0, r0, 5, 0, 26
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 5u) & 0xFFFFFFE0u;
    }

label_80257718:
    // 80257718: addi    r6, r5, 20
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(20);

label_8025771C:
    ctx->pc = 0x8025771Cu;
    // 8025771C: lwz     r5, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80257720:
    // 80257720: rlwinm r5, r5, 0, 27, 25
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFDFu;
    }

label_80257724:
    // 80257724: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80257728:
    ctx->pc = 0x80257728u;
    // 80257728: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8025772C:
    // 8025772C: b       0x80257960
    {
            goto label_80257960;
    }

label_80257730:
    ctx->pc = 0x80257730u;
    ctx->downcount -= 8;
    // 80257730: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80257734:
    // 80257734: rlwinm r0, r0, 6, 0, 25
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 6u) & 0xFFFFFFC0u;
    }

label_80257738:
    // 80257738: addi    r6, r5, 20
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(20);

label_8025773C:
    ctx->pc = 0x8025773Cu;
    // 8025773C: lwz     r5, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80257740:
    // 80257740: rlwinm r5, r5, 0, 26, 24
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFBFu;
    }

label_80257744:
    // 80257744: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80257748:
    ctx->pc = 0x80257748u;
    // 80257748: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8025774C:
    // 8025774C: b       0x80257960
    {
            goto label_80257960;
    }

label_80257750:
    ctx->pc = 0x80257750u;
    ctx->downcount -= 8;
    // 80257750: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80257754:
    // 80257754: rlwinm r0, r0, 7, 0, 24
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 7u) & 0xFFFFFF80u;
    }

label_80257758:
    // 80257758: addi    r6, r5, 20
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(20);

label_8025775C:
    ctx->pc = 0x8025775Cu;
    // 8025775C: lwz     r5, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80257760:
    // 80257760: rlwinm r5, r5, 0, 25, 23
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFF7Fu;
    }

label_80257764:
    // 80257764: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80257768:
    ctx->pc = 0x80257768u;
    // 80257768: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8025776C:
    // 8025776C: b       0x80257960
    {
            goto label_80257960;
    }

label_80257770:
    ctx->pc = 0x80257770u;
    ctx->downcount -= 8;
    // 80257770: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80257774:
    // 80257774: rlwinm r0, r0, 8, 0, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 8u) & 0xFFFFFF00u;
    }

label_80257778:
    // 80257778: addi    r6, r5, 20
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(20);

label_8025777C:
    ctx->pc = 0x8025777Cu;
    // 8025777C: lwz     r5, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80257780:
    // 80257780: rlwinm r5, r5, 0, 24, 22
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFEFFu;
    }

label_80257784:
    // 80257784: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80257788:
    ctx->pc = 0x80257788u;
    // 80257788: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8025778C:
    // 8025778C: b       0x80257960
    {
            goto label_80257960;
    }

label_80257790:
    ctx->pc = 0x80257790u;
    ctx->downcount -= 8;
    // 80257790: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80257794:
    // 80257794: rlwinm r0, r0, 9, 0, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 9u) & 0xFFFFFE00u;
    }

label_80257798:
    // 80257798: addi    r6, r5, 20
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(20);

label_8025779C:
    ctx->pc = 0x8025779Cu;
    // 8025779C: lwz     r5, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802577A0:
    // 802577A0: rlwinm r5, r5, 0, 23, 20
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFF9FFu;
    }

label_802577A4:
    // 802577A4: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_802577A8:
    ctx->pc = 0x802577A8u;
    // 802577A8: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802577AC:
    // 802577AC: b       0x80257960
    {
            goto label_80257960;
    }

label_802577B0:
    ctx->downcount -= 2;
    // 802577B0: cmpwi   r0, 0
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

label_802577B4:
    // 802577B4: bc    12, 2, 0x802577DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802577DC;
        }
    }

label_802577B8:
    ctx->pc = 0x802577B8u;
    ctx->downcount -= 9;
    // 802577B8: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802577BC:
    // 802577BC: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_802577C0:
    // 802577C0: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_802577C4:
    ctx->pc = 0x802577C4u;
    // 802577C4: stb     r7, 1052(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1052);
        mem_write8(ctx, ea, (u8)ctx->gpr[7]);
    }

label_802577C8:
    ctx->pc = 0x802577C8u;
    // 802577C8: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802577CC:
    ctx->pc = 0x802577CCu;
    // 802577CC: stb     r6, 1053(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1053);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_802577D0:
    ctx->pc = 0x802577D0u;
    // 802577D0: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802577D4:
    ctx->pc = 0x802577D4u;
    // 802577D4: stw     r0, 1048(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1048);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802577D8:
    // 802577D8: b       0x80257960
    {
            goto label_80257960;
    }

label_802577DC:
    ctx->pc = 0x802577DCu;
    ctx->downcount -= 4;
    // 802577DC: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802577E0:
    // 802577E0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802577E4:
    ctx->pc = 0x802577E4u;
    // 802577E4: stb     r0, 1052(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1052);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802577E8:
    // 802577E8: b       0x80257960
    {
            goto label_80257960;
    }

label_802577EC:
    ctx->downcount -= 2;
    // 802577EC: cmpwi   r0, 0
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

label_802577F0:
    // 802577F0: bc    12, 2, 0x80257818
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80257818;
        }
    }

label_802577F4:
    ctx->pc = 0x802577F4u;
    ctx->downcount -= 9;
    // 802577F4: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802577F8:
    // 802577F8: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_802577FC:
    // 802577FC: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80257800:
    ctx->pc = 0x80257800u;
    // 80257800: stb     r7, 1053(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1053);
        mem_write8(ctx, ea, (u8)ctx->gpr[7]);
    }

label_80257804:
    ctx->pc = 0x80257804u;
    // 80257804: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80257808:
    ctx->pc = 0x80257808u;
    // 80257808: stb     r6, 1052(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1052);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_8025780C:
    ctx->pc = 0x8025780Cu;
    // 8025780C: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80257810:
    ctx->pc = 0x80257810u;
    // 80257810: stw     r0, 1048(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1048);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80257814:
    // 80257814: b       0x80257960
    {
            goto label_80257960;
    }

label_80257818:
    ctx->pc = 0x80257818u;
    ctx->downcount -= 4;
    // 80257818: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8025781C:
    // 8025781C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80257820:
    ctx->pc = 0x80257820u;
    // 80257820: stb     r0, 1053(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1053);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80257824:
    // 80257824: b       0x80257960
    {
            goto label_80257960;
    }

label_80257828:
    ctx->pc = 0x80257828u;
    ctx->downcount -= 8;
    // 80257828: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8025782C:
    // 8025782C: rlwinm r0, r0, 13, 0, 18
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 13u) & 0xFFFFE000u;
    }

label_80257830:
    // 80257830: addi    r6, r5, 20
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(20);

label_80257834:
    ctx->pc = 0x80257834u;
    // 80257834: lwz     r5, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80257838:
    // 80257838: rlwinm r5, r5, 0, 19, 16
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFF9FFFu;
    }

label_8025783C:
    // 8025783C: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80257840:
    ctx->pc = 0x80257840u;
    // 80257840: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80257844:
    // 80257844: b       0x80257960
    {
            goto label_80257960;
    }

label_80257848:
    ctx->pc = 0x80257848u;
    ctx->downcount -= 8;
    // 80257848: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8025784C:
    // 8025784C: rlwinm r0, r0, 15, 0, 16
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 15u) & 0xFFFF8000u;
    }

label_80257850:
    // 80257850: addi    r6, r5, 20
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(20);

label_80257854:
    ctx->pc = 0x80257854u;
    // 80257854: lwz     r5, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80257858:
    // 80257858: rlwinm r5, r5, 0, 17, 14
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFE7FFFu;
    }

label_8025785C:
    // 8025785C: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80257860:
    ctx->pc = 0x80257860u;
    // 80257860: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80257864:
    // 80257864: b       0x80257960
    {
            goto label_80257960;
    }

label_80257868:
    ctx->pc = 0x80257868u;
    ctx->downcount -= 7;
    // 80257868: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8025786C:
    // 8025786C: addi    r6, r5, 24
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(24);

label_80257870:
    ctx->pc = 0x80257870u;
    // 80257870: lwz     r5, 24(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(24);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80257874:
    // 80257874: rlwinm r5, r5, 0, 0, 29
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFFCu;
    }

label_80257878:
    // 80257878: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_8025787C:
    ctx->pc = 0x8025787Cu;
    // 8025787C: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80257880:
    // 80257880: b       0x80257960
    {
            goto label_80257960;
    }

label_80257884:
    ctx->pc = 0x80257884u;
    ctx->downcount -= 8;
    // 80257884: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80257888:
    // 80257888: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_8025788C:
    // 8025788C: addi    r6, r5, 24
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(24);

label_80257890:
    ctx->pc = 0x80257890u;
    // 80257890: lwz     r5, 24(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(24);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80257894:
    // 80257894: rlwinm r5, r5, 0, 30, 27
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFF3u;
    }

label_80257898:
    // 80257898: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_8025789C:
    ctx->pc = 0x8025789Cu;
    // 8025789C: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802578A0:
    // 802578A0: b       0x80257960
    {
            goto label_80257960;
    }

label_802578A4:
    ctx->pc = 0x802578A4u;
    ctx->downcount -= 8;
    // 802578A4: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802578A8:
    // 802578A8: rlwinm r0, r0, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 4u) & 0xFFFFFFF0u;
    }

label_802578AC:
    // 802578AC: addi    r6, r5, 24
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(24);

label_802578B0:
    ctx->pc = 0x802578B0u;
    // 802578B0: lwz     r5, 24(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(24);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802578B4:
    // 802578B4: rlwinm r5, r5, 0, 28, 25
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFCFu;
    }

label_802578B8:
    // 802578B8: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_802578BC:
    ctx->pc = 0x802578BCu;
    // 802578BC: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802578C0:
    // 802578C0: b       0x80257960
    {
            goto label_80257960;
    }

label_802578C4:
    ctx->pc = 0x802578C4u;
    ctx->downcount -= 8;
    // 802578C4: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802578C8:
    // 802578C8: rlwinm r0, r0, 6, 0, 25
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 6u) & 0xFFFFFFC0u;
    }

label_802578CC:
    // 802578CC: addi    r6, r5, 24
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(24);

label_802578D0:
    ctx->pc = 0x802578D0u;
    // 802578D0: lwz     r5, 24(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(24);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802578D4:
    // 802578D4: rlwinm r5, r5, 0, 26, 23
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFF3Fu;
    }

label_802578D8:
    // 802578D8: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_802578DC:
    ctx->pc = 0x802578DCu;
    // 802578DC: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802578E0:
    // 802578E0: b       0x80257960
    {
            goto label_80257960;
    }

label_802578E4:
    ctx->pc = 0x802578E4u;
    ctx->downcount -= 8;
    // 802578E4: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802578E8:
    // 802578E8: rlwinm r0, r0, 8, 0, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 8u) & 0xFFFFFF00u;
    }

label_802578EC:
    // 802578EC: addi    r6, r5, 24
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(24);

label_802578F0:
    ctx->pc = 0x802578F0u;
    // 802578F0: lwz     r5, 24(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(24);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802578F4:
    // 802578F4: rlwinm r5, r5, 0, 24, 21
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFCFFu;
    }

label_802578F8:
    // 802578F8: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_802578FC:
    ctx->pc = 0x802578FCu;
    // 802578FC: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80257900:
    // 80257900: b       0x80257960
    {
            goto label_80257960;
    }

label_80257904:
    ctx->pc = 0x80257904u;
    ctx->downcount -= 8;
    // 80257904: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80257908:
    // 80257908: rlwinm r0, r0, 10, 0, 21
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 10u) & 0xFFFFFC00u;
    }

label_8025790C:
    // 8025790C: addi    r6, r5, 24
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(24);

label_80257910:
    ctx->pc = 0x80257910u;
    // 80257910: lwz     r5, 24(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(24);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80257914:
    // 80257914: rlwinm r5, r5, 0, 22, 19
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFF3FFu;
    }

label_80257918:
    // 80257918: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_8025791C:
    ctx->pc = 0x8025791Cu;
    // 8025791C: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80257920:
    // 80257920: b       0x80257960
    {
            goto label_80257960;
    }

label_80257924:
    ctx->pc = 0x80257924u;
    ctx->downcount -= 8;
    // 80257924: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80257928:
    // 80257928: rlwinm r0, r0, 12, 0, 19
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 12u) & 0xFFFFF000u;
    }

label_8025792C:
    // 8025792C: addi    r6, r5, 24
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(24);

label_80257930:
    ctx->pc = 0x80257930u;
    // 80257930: lwz     r5, 24(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(24);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80257934:
    // 80257934: rlwinm r5, r5, 0, 20, 17
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFCFFFu;
    }

label_80257938:
    // 80257938: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_8025793C:
    ctx->pc = 0x8025793Cu;
    // 8025793C: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80257940:
    // 80257940: b       0x80257960
    {
            goto label_80257960;
    }

label_80257944:
    ctx->pc = 0x80257944u;
    ctx->downcount -= 7;
    // 80257944: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80257948:
    // 80257948: rlwinm r0, r0, 14, 0, 17
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 14u) & 0xFFFFC000u;
    }

label_8025794C:
    // 8025794C: addi    r6, r5, 24
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(24);

label_80257950:
    ctx->pc = 0x80257950u;
    // 80257950: lwz     r5, 24(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(24);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80257954:
    // 80257954: rlwinm r5, r5, 0, 18, 15
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFF3FFFu;
    }

label_80257958:
    // 80257958: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_8025795C:
    ctx->pc = 0x8025795Cu;
    // 8025795C: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80257960:
    ctx->downcount -= 1;
    // 80257960: addi    r3, r3, 8
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(8);

label_80257964:
    ctx->pc = 0x80257964u;
    ctx->downcount -= 3;
    // 80257964: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257968:
    // 80257968: cmpwi   r0, 255
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

label_8025796C:
    // 8025796C: bc    4, 2, 0x80257654
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80257654u;
                return;
            }
            goto label_80257654;
        }
    }

label_80257970:
    ctx->pc = 0x80257970u;
    ctx->downcount -= 4;
    // 80257970: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257974:
    ctx->pc = 0x80257974u;
    // 80257974: lbz     r0, 1052(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1052);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80257978:
    ctx->pc = 0x80257978u;
    // 80257978: cmplwi  r0, 0x0000
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

label_8025797C:
    ctx->pc = 0x8025797Cu;
    // 8025797C: bc    4, 2, 0x8025798C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8025798C;
        }
    }

label_80257980:
    ctx->pc = 0x80257980u;
    ctx->downcount -= 3;
    // 80257980: lbz     r0, 1053(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1053);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80257984:
    ctx->pc = 0x80257984u;
    // 80257984: cmplwi  r0, 0x0000
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

label_80257988:
    ctx->pc = 0x80257988u;
    // 80257988: bc    12, 2, 0x802579AC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802579AC;
        }
    }

label_8025798C:
    ctx->pc = 0x8025798Cu;
    ctx->downcount -= 8;
    // 8025798C: addi    r4, r3, 20
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20);

label_80257990:
    ctx->pc = 0x80257990u;
    // 80257990: lwz     r0, 1048(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1048);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257994:
    ctx->pc = 0x80257994u;
    // 80257994: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257998:
    ctx->pc = 0x80257998u;
    // 80257998: rlwinm r0, r0, 11, 0, 20
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 11u) & 0xFFFFF800u;
    }

label_8025799C:
    ctx->pc = 0x8025799Cu;
    // 8025799C: rlwinm r3, r3, 0, 21, 18
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFE7FFu;
    }

label_802579A0:
    ctx->pc = 0x802579A0u;
    // 802579A0: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802579A4:
    ctx->pc = 0x802579A4u;
    // 802579A4: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802579A8:
    ctx->pc = 0x802579A8u;
    // 802579A8: b       0x802579B8
    {
            goto label_802579B8;
    }

label_802579AC:
    ctx->pc = 0x802579ACu;
    ctx->downcount -= 3;
    // 802579AC: lwzu     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_802579B0:
    ctx->pc = 0x802579B0u;
    // 802579B0: rlwinm r0, r0, 0, 21, 18
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFE7FFu;
    }

label_802579B4:
    ctx->pc = 0x802579B4u;
    // 802579B4: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802579B8:
    ctx->pc = 0x802579B8u;
    ctx->downcount -= 5;
    // 802579B8: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802579BC:
    ctx->pc = 0x802579BCu;
    // 802579BC: lwz     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802579C0:
    ctx->pc = 0x802579C0u;
    // 802579C0: ori     r0, r0, 0x0008
    ctx->gpr[0] = ctx->gpr[0] | 0x0008u;

label_802579C4:
    ctx->pc = 0x802579C4u;
    // 802579C4: stw     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802579C8:
    ctx->pc = 0x802579C8u;
    // 802579C8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_802579CC:
    ctx->pc = 0x802579CCu;
    ctx->downcount -= 17;
    // 802579CC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802579D0:
    ctx->pc = 0x802579D0u;
    // 802579D0: li      r6, 8
    ctx->gpr[6] = (u32)(s32)(8);

label_802579D4:
    ctx->pc = 0x802579D4u;
    // 802579D4: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802579D8:
    ctx->pc = 0x802579D8u;
    // 802579D8: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_802579DC:
    ctx->pc = 0x802579DCu;
    // 802579DC: li      r3, 80
    ctx->gpr[3] = (u32)(s32)(80);

label_802579E0:
    ctx->pc = 0x802579E0u;
    // 802579E0: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_802579E4:
    ctx->pc = 0x802579E4u;
    // 802579E4: li      r0, 96
    ctx->gpr[0] = (u32)(s32)(96);

label_802579E8:
    ctx->pc = 0x802579E8u;
    // 802579E8: stb     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_802579EC:
    ctx->pc = 0x802579ECu;
    // 802579EC: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802579F0:
    ctx->pc = 0x802579F0u;
    // 802579F0: stb     r3, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_802579F4:
    ctx->pc = 0x802579F4u;
    // 802579F4: lwz     r3, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802579F8:
    ctx->pc = 0x802579F8u;
    // 802579F8: stw     r3, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_802579FC:
    ctx->pc = 0x802579FCu;
    // 802579FC: stb     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_80257A00:
    ctx->pc = 0x80257A00u;
    // 80257A00: stb     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80257A04:
    ctx->pc = 0x80257A04u;
    // 80257A04: lwz     r0, 24(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257A08:
    ctx->pc = 0x80257A08u;
    // 80257A08: stw     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80257A0C:
    ctx->pc = 0x80257A0Cu;
    // 80257A0C: bl      0x80257190
    {
            ctx->lr = 0x80257A10u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80257190u;
                return;
            }
            goto label_80257190;
    }

label_80257A10:
    ctx->pc = 0x80257A10u;
    ctx->downcount -= 5;
    // 80257A10: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257A14:
    ctx->pc = 0x80257A14u;
    // 80257A14: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80257A18:
    ctx->pc = 0x80257A18u;
    // 80257A18: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80257A1C:
    ctx->pc = 0x80257A1Cu;
    // 80257A1C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80257A20:
    ctx->pc = 0x80257A20u;
    ctx->downcount -= 4;
    // 80257A20: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257A24:
    ctx->pc = 0x80257A24u;
    // 80257A24: lhz     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80257A28:
    ctx->pc = 0x80257A28u;
    // 80257A28: cmplwi  r0, 0x0000
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

label_80257A2C:
    ctx->pc = 0x80257A2Cu;
    // 80257A2C: bclr  12, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80257A30:
    ctx->pc = 0x80257A30u;
    ctx->downcount -= 27;
    // 80257A30: lwz     r9, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80257A34:
    ctx->pc = 0x80257A34u;
    // 80257A34: addi    r5, r13, -27592
    ctx->gpr[5] = ctx->gpr[13] + (u32)(s32)(-27592);

label_80257A38:
    ctx->pc = 0x80257A38u;
    // 80257A38: lwz     r8, 28(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(28);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80257A3C:
    ctx->pc = 0x80257A3Cu;
    // 80257A3C: rlwinm r0, r9, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[9], 0u) & 0x00000001u;
    }

label_80257A40:
    ctx->pc = 0x80257A40u;
    // 80257A40: lwz     r4, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80257A44:
    ctx->pc = 0x80257A44u;
    // 80257A44: rlwinm r6, r9, 31, 31, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[9], 31u) & 0x00000001u;
    }

label_80257A48:
    ctx->pc = 0x80257A48u;
    // 80257A48: add   r0, r0, r6
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80257A4C:
    ctx->pc = 0x80257A4Cu;
    // 80257A4C: rlwinm r6, r9, 30, 31, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[9], 30u) & 0x00000001u;
    }

label_80257A50:
    ctx->pc = 0x80257A50u;
    // 80257A50: add   r0, r0, r6
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80257A54:
    ctx->pc = 0x80257A54u;
    // 80257A54: rlwinm r7, r9, 29, 31, 31
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[9], 29u) & 0x00000001u;
    }

label_80257A58:
    ctx->pc = 0x80257A58u;
    // 80257A58: rlwinm r6, r9, 23, 30, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[9], 23u) & 0x00000003u;
    }

label_80257A5C:
    ctx->pc = 0x80257A5Cu;
    // 80257A5C: lbzx    r5, r5, r6
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[6];
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_80257A60:
    ctx->pc = 0x80257A60u;
    // 80257A60: rlwinm r8, r8, 23, 31, 31
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[8], 23u) & 0x00000001u;
    }

label_80257A64:
    ctx->pc = 0x80257A64u;
    // 80257A64: add   r0, r0, r7
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80257A68:
    ctx->pc = 0x80257A68u;
    // 80257A68: rlwinm r6, r9, 28, 31, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[9], 28u) & 0x00000001u;
    }

label_80257A6C:
    ctx->pc = 0x80257A6Cu;
    // 80257A6C: add   r0, r0, r6
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80257A70:
    ctx->pc = 0x80257A70u;
    // 80257A70: rlwinm r6, r9, 27, 31, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[9], 27u) & 0x00000001u;
    }

label_80257A74:
    ctx->pc = 0x80257A74u;
    // 80257A74: add   r0, r0, r6
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80257A78:
    ctx->pc = 0x80257A78u;
    // 80257A78: rlwinm r6, r9, 26, 31, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[9], 26u) & 0x00000001u;
    }

label_80257A7C:
    ctx->pc = 0x80257A7Cu;
    // 80257A7C: add   r0, r0, r6
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80257A80:
    ctx->pc = 0x80257A80u;
    // 80257A80: rlwinm r6, r9, 25, 31, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[9], 25u) & 0x00000001u;
    }

label_80257A84:
    ctx->pc = 0x80257A84u;
    // 80257A84: add   r0, r0, r6
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80257A88:
    ctx->pc = 0x80257A88u;
    // 80257A88: rlwinm r6, r9, 24, 31, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[9], 24u) & 0x00000001u;
    }

label_80257A8C:
    ctx->pc = 0x80257A8Cu;
    // 80257A8C: add   r0, r0, r6
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80257A90:
    ctx->pc = 0x80257A90u;
    // 80257A90: cmpwi   r8, 1
    {
        s32 val_a = (s32)(ctx->gpr[8]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80257A94:
    ctx->pc = 0x80257A94u;
    // 80257A94: add   r0, r0, r5
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80257A98:
    ctx->pc = 0x80257A98u;
    // 80257A98: bc    4, 2, 0x80257AA4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80257AA4;
        }
    }

label_80257A9C:
    ctx->pc = 0x80257A9Cu;
    ctx->downcount -= 2;
    // 80257A9C: li      r8, 3
    ctx->gpr[8] = (u32)(s32)(3);

label_80257AA0:
    ctx->pc = 0x80257AA0u;
    // 80257AA0: b       0x80257AA8
    {
            goto label_80257AA8;
    }

label_80257AA4:
    ctx->pc = 0x80257AA4u;
    ctx->downcount -= 1;
    // 80257AA4: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_80257AA8:
    ctx->pc = 0x80257AA8u;
    ctx->downcount -= 43;
    // 80257AA8: rlwinm r6, r9, 21, 30, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[9], 21u) & 0x00000003u;
    }

label_80257AAC:
    ctx->pc = 0x80257AACu;
    // 80257AAC: addi    r5, r13, -27592
    ctx->gpr[5] = ctx->gpr[13] + (u32)(s32)(-27592);

label_80257AB0:
    ctx->pc = 0x80257AB0u;
    // 80257AB0: lbzx    r6, r5, r6
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[6];
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_80257AB4:
    ctx->pc = 0x80257AB4u;
    // 80257AB4: rlwinm r5, r9, 19, 30, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[9], 19u) & 0x00000003u;
    }

label_80257AB8:
    ctx->pc = 0x80257AB8u;
    // 80257AB8: addi    r7, r13, -27600
    ctx->gpr[7] = ctx->gpr[13] + (u32)(s32)(-27600);

label_80257ABC:
    ctx->pc = 0x80257ABCu;
    // 80257ABC: mullw   r8, r6, r8
    {
        s64 product = (s64)(s32)ctx->gpr[6] * (s64)(s32)ctx->gpr[8];
        ctx->gpr[8] = (u32)product;
    }

label_80257AC0:
    ctx->pc = 0x80257AC0u;
    // 80257AC0: lbzx    r6, r7, r5
    {
        u32 ea = ctx->gpr[7] + ctx->gpr[5];
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_80257AC4:
    ctx->pc = 0x80257AC4u;
    // 80257AC4: add   r0, r0, r8
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[8];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80257AC8:
    ctx->pc = 0x80257AC8u;
    // 80257AC8: rlwinm r5, r9, 17, 30, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[9], 17u) & 0x00000003u;
    }

label_80257ACC:
    ctx->pc = 0x80257ACCu;
    // 80257ACC: lbzx    r9, r7, r5
    {
        u32 ea = ctx->gpr[7] + ctx->gpr[5];
        ctx->gpr[9] = mem_read8(ctx, ea);
    }

label_80257AD0:
    ctx->pc = 0x80257AD0u;
    // 80257AD0: add   r0, r0, r6
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80257AD4:
    ctx->pc = 0x80257AD4u;
    // 80257AD4: rlwinm r6, r4, 0, 30, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x00000003u;
    }

label_80257AD8:
    ctx->pc = 0x80257AD8u;
    // 80257AD8: addi    r8, r13, -27596
    ctx->gpr[8] = ctx->gpr[13] + (u32)(s32)(-27596);

label_80257ADC:
    ctx->pc = 0x80257ADCu;
    // 80257ADC: rlwinm r5, r4, 30, 30, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[4], 30u) & 0x00000003u;
    }

label_80257AE0:
    ctx->pc = 0x80257AE0u;
    // 80257AE0: lbzx    r7, r8, r6
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[6];
        ctx->gpr[7] = mem_read8(ctx, ea);
    }

label_80257AE4:
    ctx->pc = 0x80257AE4u;
    // 80257AE4: add   r0, r0, r9
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80257AE8:
    ctx->pc = 0x80257AE8u;
    // 80257AE8: lbzx    r6, r8, r5
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[5];
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_80257AEC:
    ctx->pc = 0x80257AECu;
    // 80257AEC: add   r0, r0, r7
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80257AF0:
    ctx->pc = 0x80257AF0u;
    // 80257AF0: rlwinm r5, r4, 28, 30, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[4], 28u) & 0x00000003u;
    }

label_80257AF4:
    ctx->pc = 0x80257AF4u;
    // 80257AF4: lbzx    r7, r8, r5
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[5];
        ctx->gpr[7] = mem_read8(ctx, ea);
    }

label_80257AF8:
    ctx->pc = 0x80257AF8u;
    // 80257AF8: add   r0, r0, r6
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80257AFC:
    ctx->pc = 0x80257AFCu;
    // 80257AFC: rlwinm r5, r4, 26, 30, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[4], 26u) & 0x00000003u;
    }

label_80257B00:
    ctx->pc = 0x80257B00u;
    // 80257B00: lbzx    r6, r8, r5
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[5];
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_80257B04:
    ctx->pc = 0x80257B04u;
    // 80257B04: add   r0, r0, r7
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80257B08:
    ctx->pc = 0x80257B08u;
    // 80257B08: rlwinm r5, r4, 24, 30, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[4], 24u) & 0x00000003u;
    }

label_80257B0C:
    ctx->pc = 0x80257B0Cu;
    // 80257B0C: lbzx    r7, r8, r5
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[5];
        ctx->gpr[7] = mem_read8(ctx, ea);
    }

label_80257B10:
    ctx->pc = 0x80257B10u;
    // 80257B10: add   r0, r0, r6
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80257B14:
    ctx->pc = 0x80257B14u;
    // 80257B14: rlwinm r5, r4, 22, 30, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[4], 22u) & 0x00000003u;
    }

label_80257B18:
    ctx->pc = 0x80257B18u;
    // 80257B18: lbzx    r6, r8, r5
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[5];
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_80257B1C:
    ctx->pc = 0x80257B1Cu;
    // 80257B1C: rlwinm r5, r4, 20, 30, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[4], 20u) & 0x00000003u;
    }

label_80257B20:
    ctx->pc = 0x80257B20u;
    // 80257B20: add   r0, r0, r7
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80257B24:
    ctx->pc = 0x80257B24u;
    // 80257B24: lbzx    r5, r8, r5
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[5];
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_80257B28:
    ctx->pc = 0x80257B28u;
    // 80257B28: rlwinm r4, r4, 18, 30, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 18u) & 0x00000003u;
    }

label_80257B2C:
    ctx->pc = 0x80257B2Cu;
    // 80257B2C: add   r0, r0, r6
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80257B30:
    ctx->pc = 0x80257B30u;
    // 80257B30: lbzx    r4, r8, r4
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[4];
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_80257B34:
    ctx->pc = 0x80257B34u;
    // 80257B34: add   r0, r0, r5
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80257B38:
    ctx->pc = 0x80257B38u;
    // 80257B38: add   r0, r0, r4
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80257B3C:
    ctx->pc = 0x80257B3Cu;
    // 80257B3C: sth     r0, 6(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(6);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80257B40:
    ctx->pc = 0x80257B40u;
    // 80257B40: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80257B44:
    ctx->pc = 0x80257B44u;
    ctx->downcount -= 2;
    // 80257B44: cmplwi  r3, 0x0019
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0019u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80257B48:
    ctx->pc = 0x80257B48u;
    // 80257B48: bc    12, 1, 0x80257CEC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80257CEC;
        }
    }

label_80257B4C:
    ctx->pc = 0x80257B4Cu;
    ctx->downcount -= 7;
    // 80257B4C: lis     r5, -32717
    ctx->gpr[5] = ((u32)(s32)(-32717) << 16);

label_80257B50:
    ctx->pc = 0x80257B50u;
    // 80257B50: addi    r5, r5, -496
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(-496);

label_80257B54:
    ctx->pc = 0x80257B54u;
    // 80257B54: rlwinm r0, r3, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0xFFFFFFFCu;
    }

label_80257B58:
    ctx->pc = 0x80257B58u;
    // 80257B58: lwzx    r0, r5, r0
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257B5C:
    ctx->pc = 0x80257B5Cu;
    // 80257B5C: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_80257B60:
    ctx->pc = 0x80257B60u;
    // 80257B60: bctr
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            return;
        }
    }

label_80257B64:
    ctx->pc = 0x80257B64u;
    ctx->downcount -= 4;
    // 80257B64: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257B68:
    ctx->pc = 0x80257B68u;
    // 80257B68: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257B6C:
    ctx->pc = 0x80257B6Cu;
    // 80257B6C: rlwinm r0, r0, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000001u;
    }

label_80257B70:
    ctx->pc = 0x80257B70u;
    // 80257B70: b       0x80257CF0
    {
            goto label_80257CF0;
    }

label_80257B74:
    ctx->pc = 0x80257B74u;
    ctx->downcount -= 4;
    // 80257B74: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257B78:
    ctx->pc = 0x80257B78u;
    // 80257B78: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257B7C:
    ctx->pc = 0x80257B7Cu;
    // 80257B7C: rlwinm r0, r0, 31, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x00000001u;
    }

label_80257B80:
    ctx->pc = 0x80257B80u;
    // 80257B80: b       0x80257CF0
    {
            goto label_80257CF0;
    }

label_80257B84:
    ctx->pc = 0x80257B84u;
    ctx->downcount -= 4;
    // 80257B84: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257B88:
    ctx->pc = 0x80257B88u;
    // 80257B88: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257B8C:
    ctx->pc = 0x80257B8Cu;
    // 80257B8C: rlwinm r0, r0, 30, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 30u) & 0x00000001u;
    }

label_80257B90:
    ctx->pc = 0x80257B90u;
    // 80257B90: b       0x80257CF0
    {
            goto label_80257CF0;
    }

label_80257B94:
    ctx->pc = 0x80257B94u;
    ctx->downcount -= 4;
    // 80257B94: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257B98:
    ctx->pc = 0x80257B98u;
    // 80257B98: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257B9C:
    ctx->pc = 0x80257B9Cu;
    // 80257B9C: rlwinm r0, r0, 29, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 29u) & 0x00000001u;
    }

label_80257BA0:
    ctx->pc = 0x80257BA0u;
    // 80257BA0: b       0x80257CF0
    {
            goto label_80257CF0;
    }

label_80257BA4:
    ctx->pc = 0x80257BA4u;
    ctx->downcount -= 4;
    // 80257BA4: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257BA8:
    ctx->pc = 0x80257BA8u;
    // 80257BA8: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257BAC:
    ctx->pc = 0x80257BACu;
    // 80257BAC: rlwinm r0, r0, 28, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 28u) & 0x00000001u;
    }

label_80257BB0:
    ctx->pc = 0x80257BB0u;
    // 80257BB0: b       0x80257CF0
    {
            goto label_80257CF0;
    }

label_80257BB4:
    ctx->pc = 0x80257BB4u;
    ctx->downcount -= 4;
    // 80257BB4: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257BB8:
    ctx->pc = 0x80257BB8u;
    // 80257BB8: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257BBC:
    ctx->pc = 0x80257BBCu;
    // 80257BBC: rlwinm r0, r0, 27, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x00000001u;
    }

label_80257BC0:
    ctx->pc = 0x80257BC0u;
    // 80257BC0: b       0x80257CF0
    {
            goto label_80257CF0;
    }

label_80257BC4:
    ctx->pc = 0x80257BC4u;
    ctx->downcount -= 4;
    // 80257BC4: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257BC8:
    ctx->pc = 0x80257BC8u;
    // 80257BC8: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257BCC:
    ctx->pc = 0x80257BCCu;
    // 80257BCC: rlwinm r0, r0, 26, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 26u) & 0x00000001u;
    }

label_80257BD0:
    ctx->pc = 0x80257BD0u;
    // 80257BD0: b       0x80257CF0
    {
            goto label_80257CF0;
    }

label_80257BD4:
    ctx->pc = 0x80257BD4u;
    ctx->downcount -= 4;
    // 80257BD4: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257BD8:
    ctx->pc = 0x80257BD8u;
    // 80257BD8: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257BDC:
    ctx->pc = 0x80257BDCu;
    // 80257BDC: rlwinm r0, r0, 25, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 25u) & 0x00000001u;
    }

label_80257BE0:
    ctx->pc = 0x80257BE0u;
    // 80257BE0: b       0x80257CF0
    {
            goto label_80257CF0;
    }

label_80257BE4:
    ctx->pc = 0x80257BE4u;
    ctx->downcount -= 4;
    // 80257BE4: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257BE8:
    ctx->pc = 0x80257BE8u;
    // 80257BE8: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257BEC:
    ctx->pc = 0x80257BECu;
    // 80257BEC: rlwinm r0, r0, 24, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 24u) & 0x00000001u;
    }

label_80257BF0:
    ctx->pc = 0x80257BF0u;
    // 80257BF0: b       0x80257CF0
    {
            goto label_80257CF0;
    }

label_80257BF4:
    ctx->pc = 0x80257BF4u;
    ctx->downcount -= 4;
    // 80257BF4: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257BF8:
    ctx->pc = 0x80257BF8u;
    // 80257BF8: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257BFC:
    ctx->pc = 0x80257BFCu;
    // 80257BFC: rlwinm r0, r0, 23, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 23u) & 0x00000003u;
    }

label_80257C00:
    ctx->pc = 0x80257C00u;
    // 80257C00: b       0x80257CF0
    {
            goto label_80257CF0;
    }

label_80257C04:
    ctx->pc = 0x80257C04u;
    ctx->downcount -= 4;
    // 80257C04: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257C08:
    ctx->pc = 0x80257C08u;
    // 80257C08: lbz     r0, 1052(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1052);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80257C0C:
    ctx->pc = 0x80257C0Cu;
    // 80257C0C: cmplwi  r0, 0x0000
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

label_80257C10:
    ctx->pc = 0x80257C10u;
    // 80257C10: bc    12, 2, 0x80257C20
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80257C20;
        }
    }

label_80257C14:
    ctx->pc = 0x80257C14u;
    ctx->downcount -= 3;
    // 80257C14: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257C18:
    ctx->pc = 0x80257C18u;
    // 80257C18: rlwinm r0, r0, 21, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 21u) & 0x00000003u;
    }

label_80257C1C:
    ctx->pc = 0x80257C1Cu;
    // 80257C1C: b       0x80257CF0
    {
            goto label_80257CF0;
    }

label_80257C20:
    ctx->pc = 0x80257C20u;
    ctx->downcount -= 2;
    // 80257C20: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80257C24:
    ctx->pc = 0x80257C24u;
    // 80257C24: b       0x80257CF0
    {
            goto label_80257CF0;
    }

label_80257C28:
    ctx->pc = 0x80257C28u;
    ctx->downcount -= 4;
    // 80257C28: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257C2C:
    ctx->pc = 0x80257C2Cu;
    // 80257C2C: lbz     r0, 1053(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1053);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80257C30:
    ctx->pc = 0x80257C30u;
    // 80257C30: cmplwi  r0, 0x0000
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

label_80257C34:
    ctx->pc = 0x80257C34u;
    // 80257C34: bc    12, 2, 0x80257C44
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80257C44;
        }
    }

label_80257C38:
    ctx->pc = 0x80257C38u;
    ctx->downcount -= 3;
    // 80257C38: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257C3C:
    ctx->pc = 0x80257C3Cu;
    // 80257C3C: rlwinm r0, r0, 21, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 21u) & 0x00000003u;
    }

label_80257C40:
    ctx->pc = 0x80257C40u;
    // 80257C40: b       0x80257CF0
    {
            goto label_80257CF0;
    }

label_80257C44:
    ctx->pc = 0x80257C44u;
    ctx->downcount -= 2;
    // 80257C44: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80257C48:
    ctx->pc = 0x80257C48u;
    // 80257C48: b       0x80257CF0
    {
            goto label_80257CF0;
    }

label_80257C4C:
    ctx->pc = 0x80257C4Cu;
    ctx->downcount -= 4;
    // 80257C4C: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257C50:
    ctx->pc = 0x80257C50u;
    // 80257C50: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257C54:
    ctx->pc = 0x80257C54u;
    // 80257C54: rlwinm r0, r0, 19, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 19u) & 0x00000003u;
    }

label_80257C58:
    ctx->pc = 0x80257C58u;
    // 80257C58: b       0x80257CF0
    {
            goto label_80257CF0;
    }

label_80257C5C:
    ctx->pc = 0x80257C5Cu;
    ctx->downcount -= 4;
    // 80257C5C: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257C60:
    ctx->pc = 0x80257C60u;
    // 80257C60: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257C64:
    ctx->pc = 0x80257C64u;
    // 80257C64: rlwinm r0, r0, 17, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 17u) & 0x00000003u;
    }

label_80257C68:
    ctx->pc = 0x80257C68u;
    // 80257C68: b       0x80257CF0
    {
            goto label_80257CF0;
    }

label_80257C6C:
    ctx->pc = 0x80257C6Cu;
    ctx->downcount -= 4;
    // 80257C6C: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257C70:
    ctx->pc = 0x80257C70u;
    // 80257C70: lwz     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257C74:
    ctx->pc = 0x80257C74u;
    // 80257C74: rlwinm r0, r0, 0, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000003u;
    }

label_80257C78:
    ctx->pc = 0x80257C78u;
    // 80257C78: b       0x80257CF0
    {
            goto label_80257CF0;
    }

label_80257C7C:
    ctx->pc = 0x80257C7Cu;
    ctx->downcount -= 4;
    // 80257C7C: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257C80:
    ctx->pc = 0x80257C80u;
    // 80257C80: lwz     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257C84:
    ctx->pc = 0x80257C84u;
    // 80257C84: rlwinm r0, r0, 30, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 30u) & 0x00000003u;
    }

label_80257C88:
    ctx->pc = 0x80257C88u;
    // 80257C88: b       0x80257CF0
    {
            goto label_80257CF0;
    }

label_80257C8C:
    ctx->pc = 0x80257C8Cu;
    ctx->downcount -= 4;
    // 80257C8C: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257C90:
    ctx->pc = 0x80257C90u;
    // 80257C90: lwz     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257C94:
    ctx->pc = 0x80257C94u;
    // 80257C94: rlwinm r0, r0, 28, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 28u) & 0x00000003u;
    }

label_80257C98:
    ctx->pc = 0x80257C98u;
    // 80257C98: b       0x80257CF0
    {
            goto label_80257CF0;
    }

label_80257C9C:
    ctx->pc = 0x80257C9Cu;
    ctx->downcount -= 4;
    // 80257C9C: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257CA0:
    ctx->pc = 0x80257CA0u;
    // 80257CA0: lwz     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257CA4:
    ctx->pc = 0x80257CA4u;
    // 80257CA4: rlwinm r0, r0, 26, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 26u) & 0x00000003u;
    }

label_80257CA8:
    ctx->pc = 0x80257CA8u;
    // 80257CA8: b       0x80257CF0
    {
            goto label_80257CF0;
    }

label_80257CAC:
    ctx->pc = 0x80257CACu;
    ctx->downcount -= 4;
    // 80257CAC: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257CB0:
    ctx->pc = 0x80257CB0u;
    // 80257CB0: lwz     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257CB4:
    ctx->pc = 0x80257CB4u;
    // 80257CB4: rlwinm r0, r0, 24, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 24u) & 0x00000003u;
    }

label_80257CB8:
    ctx->pc = 0x80257CB8u;
    // 80257CB8: b       0x80257CF0
    {
            goto label_80257CF0;
    }

label_80257CBC:
    ctx->pc = 0x80257CBCu;
    ctx->downcount -= 4;
    // 80257CBC: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257CC0:
    ctx->pc = 0x80257CC0u;
    // 80257CC0: lwz     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257CC4:
    ctx->pc = 0x80257CC4u;
    // 80257CC4: rlwinm r0, r0, 22, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 22u) & 0x00000003u;
    }

label_80257CC8:
    ctx->pc = 0x80257CC8u;
    // 80257CC8: b       0x80257CF0
    {
            goto label_80257CF0;
    }

label_80257CCC:
    ctx->pc = 0x80257CCCu;
    ctx->downcount -= 4;
    // 80257CCC: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257CD0:
    ctx->pc = 0x80257CD0u;
    // 80257CD0: lwz     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257CD4:
    ctx->pc = 0x80257CD4u;
    // 80257CD4: rlwinm r0, r0, 20, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 20u) & 0x00000003u;
    }

label_80257CD8:
    ctx->pc = 0x80257CD8u;
    // 80257CD8: b       0x80257CF0
    {
            goto label_80257CF0;
    }

label_80257CDC:
    ctx->pc = 0x80257CDCu;
    ctx->downcount -= 4;
    // 80257CDC: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257CE0:
    ctx->pc = 0x80257CE0u;
    // 80257CE0: lwz     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257CE4:
    ctx->pc = 0x80257CE4u;
    // 80257CE4: rlwinm r0, r0, 18, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 18u) & 0x00000003u;
    }

label_80257CE8:
    ctx->pc = 0x80257CE8u;
    // 80257CE8: b       0x80257CF0
    {
            goto label_80257CF0;
    }

label_80257CEC:
    ctx->pc = 0x80257CECu;
    ctx->downcount -= 1;
    // 80257CEC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80257CF0:
    ctx->pc = 0x80257CF0u;
    ctx->downcount -= 2;
    // 80257CF0: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80257CF4:
    ctx->pc = 0x80257CF4u;
    // 80257CF4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80257CF8:
    ctx->pc = 0x80257CF8u;
    ctx->downcount -= 9;
    // 80257CF8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80257CFC:
    ctx->pc = 0x80257CFCu;
    // 80257CFC: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80257D00:
    ctx->pc = 0x80257D00u;
    // 80257D00: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80257D04:
    ctx->pc = 0x80257D04u;
    // 80257D04: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80257D08:
    ctx->pc = 0x80257D08u;
    // 80257D08: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_80257D0C:
    ctx->pc = 0x80257D0Cu;
    // 80257D0C: stw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80257D10:
    ctx->pc = 0x80257D10u;
    // 80257D10: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_80257D14:
    ctx->pc = 0x80257D14u;
    // 80257D14: stw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80257D18:
    ctx->pc = 0x80257D18u;
    // 80257D18: addi    r29, r3, 0
    ctx->gpr[29] = ctx->gpr[3] + (u32)(s32)(0);

label_80257D1C:
    ctx->downcount -= 5;
    // 80257D1C: add   r4, r29, r31
    {
        u32 a = ctx->gpr[29];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_80257D20:
    ctx->pc = 0x80257D20u;
    // 80257D20: stw     r30, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80257D24:
    // 80257D24: addi    r3, r30, 0
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(0);

label_80257D28:
    // 80257D28: addi    r4, r4, 4
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(4);

label_80257D2C:
    // 80257D2C: bl      0x80257B44
    {
            ctx->lr = 0x80257D30u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80257B44u;
                return;
            }
            goto label_80257B44;
    }

label_80257D30:
    ctx->downcount -= 4;
    // 80257D30: addi    r30, r30, 1
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(1);

label_80257D34:
    // 80257D34: cmpwi   r30, 26
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(26);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80257D38:
    // 80257D38: addi    r31, r31, 8
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(8);

label_80257D3C:
    // 80257D3C: bc    12, 0, 0x80257D1C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80257D1Cu;
                return;
            }
            goto label_80257D1C;
        }
    }

label_80257D40:
    ctx->pc = 0x80257D40u;
    ctx->downcount -= 11;
    // 80257D40: rlwinm r0, r30, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[30], 3u) & 0xFFFFFFF8u;
    }

label_80257D44:
    ctx->pc = 0x80257D44u;
    // 80257D44: li      r3, 255
    ctx->gpr[3] = (u32)(s32)(255);

label_80257D48:
    ctx->pc = 0x80257D48u;
    // 80257D48: stwx    r3, r29, r0
    {
        u32 ea = ctx->gpr[29] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80257D4C:
    ctx->pc = 0x80257D4Cu;
    // 80257D4C: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257D50:
    ctx->pc = 0x80257D50u;
    // 80257D50: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80257D54:
    ctx->pc = 0x80257D54u;
    // 80257D54: lwz     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80257D58:
    ctx->pc = 0x80257D58u;
    // 80257D58: lwz     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80257D5C:
    ctx->pc = 0x80257D5Cu;
    // 80257D5C: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_80257D60:
    ctx->pc = 0x80257D60u;
    // 80257D60: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80257D64:
    ctx->pc = 0x80257D64u;
    // 80257D64: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80257D68:
    ctx->pc = 0x80257D68u;
    ctx->downcount -= 19;
    // 80257D68: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257D6C:
    ctx->pc = 0x80257D6Cu;
    // 80257D6C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80257D70:
    ctx->pc = 0x80257D70u;
    // 80257D70: stw     r4, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80257D74:
    ctx->pc = 0x80257D74u;
    // 80257D74: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257D78:
    ctx->pc = 0x80257D78u;
    // 80257D78: lwzu     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_80257D7C:
    ctx->pc = 0x80257D7Cu;
    // 80257D7C: rlwinm r0, r0, 0, 23, 20
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFF9FFu;
    }

label_80257D80:
    ctx->pc = 0x80257D80u;
    // 80257D80: ori     r0, r0, 0x0200
    ctx->gpr[0] = ctx->gpr[0] | 0x0200u;

label_80257D84:
    ctx->pc = 0x80257D84u;
    // 80257D84: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80257D88:
    ctx->pc = 0x80257D88u;
    // 80257D88: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257D8C:
    ctx->pc = 0x80257D8Cu;
    // 80257D8C: stw     r4, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80257D90:
    ctx->pc = 0x80257D90u;
    // 80257D90: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257D94:
    ctx->pc = 0x80257D94u;
    // 80257D94: stb     r4, 1052(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1052);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_80257D98:
    ctx->pc = 0x80257D98u;
    // 80257D98: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257D9C:
    ctx->pc = 0x80257D9Cu;
    // 80257D9C: stb     r4, 1053(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1053);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_80257DA0:
    ctx->pc = 0x80257DA0u;
    // 80257DA0: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80257DA4:
    ctx->pc = 0x80257DA4u;
    // 80257DA4: lwz     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257DA8:
    ctx->pc = 0x80257DA8u;
    // 80257DA8: ori     r0, r0, 0x0008
    ctx->gpr[0] = ctx->gpr[0] | 0x0008u;

label_80257DAC:
    ctx->pc = 0x80257DACu;
    // 80257DAC: stw     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80257DB0:
    ctx->pc = 0x80257DB0u;
    // 80257DB0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80257DB4:
    ctx->pc = 0x80257DB4u;
    ctx->downcount -= 9;
    // 80257DB4: addi    r0, r4, -9
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(-9);

label_80257DB8:
    ctx->pc = 0x80257DB8u;
    // 80257DB8: lwz     r8, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80257DBC:
    ctx->pc = 0x80257DBCu;
    // 80257DBC: rlwinm r4, r3, 2, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0xFFFFFFFCu;
    }

label_80257DC0:
    ctx->pc = 0x80257DC0u;
    // 80257DC0: add   r9, r8, r4
    {
        u32 a = ctx->gpr[8];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_80257DC4:
    ctx->pc = 0x80257DC4u;
    // 80257DC4: cmplwi  r0, 0x0010
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0010u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80257DC8:
    ctx->pc = 0x80257DC8u;
    // 80257DC8: addi    r4, r9, 28
    ctx->gpr[4] = ctx->gpr[9] + (u32)(s32)(28);

label_80257DCC:
    ctx->pc = 0x80257DCCu;
    // 80257DCC: addi    r8, r9, 60
    ctx->gpr[8] = ctx->gpr[9] + (u32)(s32)(60);

label_80257DD0:
    ctx->pc = 0x80257DD0u;
    // 80257DD0: addi    r9, r9, 92
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(92);

label_80257DD4:
    ctx->pc = 0x80257DD4u;
    // 80257DD4: bc    12, 1, 0x802580DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802580DC;
        }
    }

label_80257DD8:
    ctx->pc = 0x80257DD8u;
    ctx->downcount -= 7;
    // 80257DD8: lis     r10, -32717
    ctx->gpr[10] = ((u32)(s32)(-32717) << 16);

label_80257DDC:
    ctx->pc = 0x80257DDCu;
    // 80257DDC: addi    r10, r10, -392
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(-392);

label_80257DE0:
    ctx->pc = 0x80257DE0u;
    // 80257DE0: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_80257DE4:
    ctx->pc = 0x80257DE4u;
    // 80257DE4: lwzx    r0, r10, r0
    {
        u32 ea = ctx->gpr[10] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257DE8:
    ctx->pc = 0x80257DE8u;
    // 80257DE8: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_80257DEC:
    ctx->pc = 0x80257DECu;
    // 80257DEC: bctr
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            return;
        }
    }

label_80257DF0:
    ctx->pc = 0x80257DF0u;
    ctx->downcount -= 15;
    // 80257DF0: lwz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257DF4:
    ctx->pc = 0x80257DF4u;
    // 80257DF4: rlwinm r6, r6, 1, 0, 30
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 1u) & 0xFFFFFFFEu;
    }

label_80257DF8:
    ctx->pc = 0x80257DF8u;
    // 80257DF8: rlwinm r0, r0, 0, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFEu;
    }

label_80257DFC:
    ctx->pc = 0x80257DFCu;
    // 80257DFC: or   r0, r0, r5
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[5];
    }

label_80257E00:
    ctx->pc = 0x80257E00u;
    // 80257E00: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80257E04:
    ctx->pc = 0x80257E04u;
    // 80257E04: rlwinm r0, r7, 4, 20, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 4u) & 0x00000FF0u;
    }

label_80257E08:
    ctx->pc = 0x80257E08u;
    // 80257E08: lwz     r5, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80257E0C:
    ctx->pc = 0x80257E0Cu;
    // 80257E0C: rlwinm r5, r5, 0, 31, 27
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFF1u;
    }

label_80257E10:
    ctx->pc = 0x80257E10u;
    // 80257E10: or   r5, r5, r6
    {
        ctx->gpr[5] = ctx->gpr[5] | ctx->gpr[6];
    }

label_80257E14:
    ctx->pc = 0x80257E14u;
    // 80257E14: stw     r5, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80257E18:
    ctx->pc = 0x80257E18u;
    // 80257E18: lwz     r5, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80257E1C:
    ctx->pc = 0x80257E1Cu;
    // 80257E1C: rlwinm r5, r5, 0, 28, 22
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFE0Fu;
    }

label_80257E20:
    ctx->pc = 0x80257E20u;
    // 80257E20: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80257E24:
    ctx->pc = 0x80257E24u;
    // 80257E24: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80257E28:
    ctx->pc = 0x80257E28u;
    // 80257E28: b       0x802580DC
    {
            goto label_802580DC;
    }

label_80257E2C:
    ctx->pc = 0x80257E2Cu;
    ctx->downcount -= 7;
    // 80257E2C: lwz     r7, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80257E30:
    ctx->pc = 0x80257E30u;
    // 80257E30: rlwinm r0, r6, 10, 0, 21
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 10u) & 0xFFFFFC00u;
    }

label_80257E34:
    ctx->pc = 0x80257E34u;
    // 80257E34: cmpwi   r5, 2
    {
        s32 val_a = (s32)(ctx->gpr[5]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80257E38:
    ctx->pc = 0x80257E38u;
    // 80257E38: rlwinm r6, r7, 0, 22, 18
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFFFFE3FFu;
    }

label_80257E3C:
    ctx->pc = 0x80257E3Cu;
    // 80257E3C: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_80257E40:
    ctx->pc = 0x80257E40u;
    // 80257E40: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80257E44:
    ctx->pc = 0x80257E44u;
    // 80257E44: bc    4, 2, 0x80257E6C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80257E6C;
        }
    }

label_80257E48:
    ctx->pc = 0x80257E48u;
    ctx->downcount -= 9;
    // 80257E48: lwz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257E4C:
    ctx->pc = 0x80257E4Cu;
    // 80257E4C: rlwinm r0, r0, 0, 23, 21
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFDFFu;
    }

label_80257E50:
    ctx->pc = 0x80257E50u;
    // 80257E50: ori     r0, r0, 0x0200
    ctx->gpr[0] = ctx->gpr[0] | 0x0200u;

label_80257E54:
    ctx->pc = 0x80257E54u;
    // 80257E54: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80257E58:
    ctx->pc = 0x80257E58u;
    // 80257E58: lwz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257E5C:
    ctx->pc = 0x80257E5Cu;
    // 80257E5C: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_80257E60:
    ctx->pc = 0x80257E60u;
    // 80257E60: oris    r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] | (0x8000u << 16);

label_80257E64:
    ctx->pc = 0x80257E64u;
    // 80257E64: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80257E68:
    ctx->pc = 0x80257E68u;
    // 80257E68: b       0x802580DC
    {
            goto label_802580DC;
    }

label_80257E6C:
    ctx->pc = 0x80257E6Cu;
    ctx->downcount -= 9;
    // 80257E6C: lwz     r6, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80257E70:
    ctx->pc = 0x80257E70u;
    // 80257E70: rlwinm r0, r5, 9, 0, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 9u) & 0xFFFFFE00u;
    }

label_80257E74:
    ctx->pc = 0x80257E74u;
    // 80257E74: rlwinm r5, r6, 0, 23, 21
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFFFFFDFFu;
    }

label_80257E78:
    ctx->pc = 0x80257E78u;
    // 80257E78: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80257E7C:
    ctx->pc = 0x80257E7Cu;
    // 80257E7C: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80257E80:
    ctx->pc = 0x80257E80u;
    // 80257E80: lwz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257E84:
    ctx->pc = 0x80257E84u;
    // 80257E84: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_80257E88:
    ctx->pc = 0x80257E88u;
    // 80257E88: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80257E8C:
    ctx->pc = 0x80257E8Cu;
    // 80257E8C: b       0x802580DC
    {
            goto label_802580DC;
    }

label_80257E90:
    ctx->pc = 0x80257E90u;
    ctx->downcount -= 11;
    // 80257E90: lwz     r7, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80257E94:
    ctx->pc = 0x80257E94u;
    // 80257E94: rlwinm r5, r5, 13, 0, 18
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 13u) & 0xFFFFE000u;
    }

label_80257E98:
    ctx->pc = 0x80257E98u;
    // 80257E98: rlwinm r0, r6, 14, 0, 17
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 14u) & 0xFFFFC000u;
    }

label_80257E9C:
    ctx->pc = 0x80257E9Cu;
    // 80257E9C: rlwinm r6, r7, 0, 19, 17
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFFFFDFFFu;
    }

label_80257EA0:
    ctx->pc = 0x80257EA0u;
    // 80257EA0: or   r5, r6, r5
    {
        ctx->gpr[5] = ctx->gpr[6] | ctx->gpr[5];
    }

label_80257EA4:
    ctx->pc = 0x80257EA4u;
    // 80257EA4: stw     r5, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80257EA8:
    ctx->pc = 0x80257EA8u;
    // 80257EA8: lwz     r5, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80257EAC:
    ctx->pc = 0x80257EACu;
    // 80257EAC: rlwinm r5, r5, 0, 18, 14
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFE3FFFu;
    }

label_80257EB0:
    ctx->pc = 0x80257EB0u;
    // 80257EB0: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80257EB4:
    ctx->pc = 0x80257EB4u;
    // 80257EB4: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80257EB8:
    ctx->pc = 0x80257EB8u;
    // 80257EB8: b       0x802580DC
    {
            goto label_802580DC;
    }

label_80257EBC:
    ctx->pc = 0x80257EBCu;
    ctx->downcount -= 11;
    // 80257EBC: lwz     r7, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80257EC0:
    ctx->pc = 0x80257EC0u;
    // 80257EC0: rlwinm r5, r5, 17, 0, 14
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 17u) & 0xFFFE0000u;
    }

label_80257EC4:
    ctx->pc = 0x80257EC4u;
    // 80257EC4: rlwinm r0, r6, 18, 0, 13
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 18u) & 0xFFFC0000u;
    }

label_80257EC8:
    ctx->pc = 0x80257EC8u;
    // 80257EC8: rlwinm r6, r7, 0, 15, 13
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFFFDFFFFu;
    }

label_80257ECC:
    ctx->pc = 0x80257ECCu;
    // 80257ECC: or   r5, r6, r5
    {
        ctx->gpr[5] = ctx->gpr[6] | ctx->gpr[5];
    }

label_80257ED0:
    ctx->pc = 0x80257ED0u;
    // 80257ED0: stw     r5, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80257ED4:
    ctx->pc = 0x80257ED4u;
    // 80257ED4: lwz     r5, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80257ED8:
    ctx->pc = 0x80257ED8u;
    // 80257ED8: rlwinm r5, r5, 0, 14, 10
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFE3FFFFu;
    }

label_80257EDC:
    ctx->pc = 0x80257EDCu;
    // 80257EDC: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80257EE0:
    ctx->pc = 0x80257EE0u;
    // 80257EE0: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80257EE4:
    ctx->pc = 0x80257EE4u;
    // 80257EE4: b       0x802580DC
    {
            goto label_802580DC;
    }

label_80257EE8:
    ctx->pc = 0x80257EE8u;
    ctx->downcount -= 16;
    // 80257EE8: lwz     r8, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80257EEC:
    ctx->pc = 0x80257EECu;
    // 80257EEC: rlwinm r0, r5, 21, 0, 10
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 21u) & 0xFFE00000u;
    }

label_80257EF0:
    ctx->pc = 0x80257EF0u;
    // 80257EF0: rlwinm r5, r8, 0, 11, 9
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[8], 0u) & 0xFFDFFFFFu;
    }

label_80257EF4:
    ctx->pc = 0x80257EF4u;
    // 80257EF4: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80257EF8:
    ctx->pc = 0x80257EF8u;
    // 80257EF8: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80257EFC:
    ctx->pc = 0x80257EFCu;
    // 80257EFC: rlwinm r5, r6, 22, 0, 9
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[6], 22u) & 0xFFC00000u;
    }

label_80257F00:
    ctx->pc = 0x80257F00u;
    // 80257F00: rlwinm r0, r7, 25, 0, 6
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 25u) & 0xFE000000u;
    }

label_80257F04:
    ctx->pc = 0x80257F04u;
    // 80257F04: lwz     r6, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80257F08:
    ctx->pc = 0x80257F08u;
    // 80257F08: rlwinm r6, r6, 0, 10, 6
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFE3FFFFFu;
    }

label_80257F0C:
    ctx->pc = 0x80257F0Cu;
    // 80257F0C: or   r5, r6, r5
    {
        ctx->gpr[5] = ctx->gpr[6] | ctx->gpr[5];
    }

label_80257F10:
    ctx->pc = 0x80257F10u;
    // 80257F10: stw     r5, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80257F14:
    ctx->pc = 0x80257F14u;
    // 80257F14: lwz     r5, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80257F18:
    ctx->pc = 0x80257F18u;
    // 80257F18: rlwinm r5, r5, 0, 7, 1
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xC1FFFFFFu;
    }

label_80257F1C:
    ctx->pc = 0x80257F1Cu;
    // 80257F1C: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80257F20:
    ctx->pc = 0x80257F20u;
    // 80257F20: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80257F24:
    ctx->pc = 0x80257F24u;
    // 80257F24: b       0x802580DC
    {
            goto label_802580DC;
    }

label_80257F28:
    ctx->pc = 0x80257F28u;
    ctx->downcount -= 15;
    // 80257F28: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80257F2C:
    ctx->pc = 0x80257F2Cu;
    // 80257F2C: rlwinm r4, r6, 1, 0, 30
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[6], 1u) & 0xFFFFFFFEu;
    }

label_80257F30:
    ctx->pc = 0x80257F30u;
    // 80257F30: rlwinm r0, r0, 0, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFEu;
    }

label_80257F34:
    ctx->pc = 0x80257F34u;
    // 80257F34: or   r0, r0, r5
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[5];
    }

label_80257F38:
    ctx->pc = 0x80257F38u;
    // 80257F38: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80257F3C:
    ctx->pc = 0x80257F3Cu;
    // 80257F3C: rlwinm r0, r7, 4, 20, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 4u) & 0x00000FF0u;
    }

label_80257F40:
    ctx->pc = 0x80257F40u;
    // 80257F40: lwz     r5, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80257F44:
    ctx->pc = 0x80257F44u;
    // 80257F44: rlwinm r5, r5, 0, 31, 27
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFF1u;
    }

label_80257F48:
    ctx->pc = 0x80257F48u;
    // 80257F48: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_80257F4C:
    ctx->pc = 0x80257F4Cu;
    // 80257F4C: stw     r4, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80257F50:
    ctx->pc = 0x80257F50u;
    // 80257F50: lwz     r4, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80257F54:
    ctx->pc = 0x80257F54u;
    // 80257F54: rlwinm r4, r4, 0, 28, 22
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFE0Fu;
    }

label_80257F58:
    ctx->pc = 0x80257F58u;
    // 80257F58: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80257F5C:
    ctx->pc = 0x80257F5Cu;
    // 80257F5C: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80257F60:
    ctx->pc = 0x80257F60u;
    // 80257F60: b       0x802580DC
    {
            goto label_802580DC;
    }

label_80257F64:
    ctx->pc = 0x80257F64u;
    ctx->downcount -= 16;
    // 80257F64: lwz     r4, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80257F68:
    ctx->pc = 0x80257F68u;
    // 80257F68: rlwinm r0, r5, 9, 0, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 9u) & 0xFFFFFE00u;
    }

label_80257F6C:
    ctx->pc = 0x80257F6Cu;
    // 80257F6C: rlwinm r4, r4, 0, 23, 21
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFDFFu;
    }

label_80257F70:
    ctx->pc = 0x80257F70u;
    // 80257F70: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80257F74:
    ctx->pc = 0x80257F74u;
    // 80257F74: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80257F78:
    ctx->pc = 0x80257F78u;
    // 80257F78: rlwinm r4, r6, 10, 0, 21
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[6], 10u) & 0xFFFFFC00u;
    }

label_80257F7C:
    ctx->pc = 0x80257F7Cu;
    // 80257F7C: rlwinm r0, r7, 13, 11, 18
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 13u) & 0x001FE000u;
    }

label_80257F80:
    ctx->pc = 0x80257F80u;
    // 80257F80: lwz     r5, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80257F84:
    ctx->pc = 0x80257F84u;
    // 80257F84: rlwinm r5, r5, 0, 22, 18
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFE3FFu;
    }

label_80257F88:
    ctx->pc = 0x80257F88u;
    // 80257F88: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_80257F8C:
    ctx->pc = 0x80257F8Cu;
    // 80257F8C: stw     r4, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80257F90:
    ctx->pc = 0x80257F90u;
    // 80257F90: lwz     r4, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80257F94:
    ctx->pc = 0x80257F94u;
    // 80257F94: rlwinm r4, r4, 0, 19, 13
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFC1FFFu;
    }

label_80257F98:
    ctx->pc = 0x80257F98u;
    // 80257F98: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80257F9C:
    ctx->pc = 0x80257F9Cu;
    // 80257F9C: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80257FA0:
    ctx->pc = 0x80257FA0u;
    // 80257FA0: b       0x802580DC
    {
            goto label_802580DC;
    }

label_80257FA4:
    ctx->pc = 0x80257FA4u;
    ctx->downcount -= 16;
    // 80257FA4: lwz     r4, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80257FA8:
    ctx->pc = 0x80257FA8u;
    // 80257FA8: rlwinm r0, r5, 18, 0, 13
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 18u) & 0xFFFC0000u;
    }

label_80257FAC:
    ctx->pc = 0x80257FACu;
    // 80257FAC: rlwinm r4, r4, 0, 14, 12
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFBFFFFu;
    }

label_80257FB0:
    ctx->pc = 0x80257FB0u;
    // 80257FB0: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80257FB4:
    ctx->pc = 0x80257FB4u;
    // 80257FB4: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80257FB8:
    ctx->pc = 0x80257FB8u;
    // 80257FB8: rlwinm r4, r6, 19, 0, 12
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[6], 19u) & 0xFFF80000u;
    }

label_80257FBC:
    ctx->pc = 0x80257FBCu;
    // 80257FBC: rlwinm r0, r7, 22, 2, 9
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 22u) & 0x3FC00000u;
    }

label_80257FC0:
    ctx->pc = 0x80257FC0u;
    // 80257FC0: lwz     r5, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80257FC4:
    ctx->pc = 0x80257FC4u;
    // 80257FC4: rlwinm r5, r5, 0, 13, 9
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFC7FFFFu;
    }

label_80257FC8:
    ctx->pc = 0x80257FC8u;
    // 80257FC8: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_80257FCC:
    ctx->pc = 0x80257FCCu;
    // 80257FCC: stw     r4, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80257FD0:
    ctx->pc = 0x80257FD0u;
    // 80257FD0: lwz     r4, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80257FD4:
    ctx->pc = 0x80257FD4u;
    // 80257FD4: rlwinm r4, r4, 0, 10, 4
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xF83FFFFFu;
    }

label_80257FD8:
    ctx->pc = 0x80257FD8u;
    // 80257FD8: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80257FDC:
    ctx->pc = 0x80257FDCu;
    // 80257FDC: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80257FE0:
    ctx->pc = 0x80257FE0u;
    // 80257FE0: b       0x802580DC
    {
            goto label_802580DC;
    }

label_80257FE4:
    ctx->pc = 0x80257FE4u;
    ctx->downcount -= 16;
    // 80257FE4: lwz     r10, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80257FE8:
    ctx->pc = 0x80257FE8u;
    // 80257FE8: rlwinm r0, r5, 27, 0, 4
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 27u) & 0xF8000000u;
    }

label_80257FEC:
    ctx->pc = 0x80257FECu;
    // 80257FEC: rlwinm r4, r6, 28, 0, 3
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[6], 28u) & 0xF0000000u;
    }

label_80257FF0:
    ctx->pc = 0x80257FF0u;
    // 80257FF0: rlwinm r5, r10, 0, 5, 3
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[10], 0u) & 0xF7FFFFFFu;
    }

label_80257FF4:
    ctx->pc = 0x80257FF4u;
    // 80257FF4: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80257FF8:
    ctx->pc = 0x80257FF8u;
    // 80257FF8: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80257FFC:
    ctx->pc = 0x80257FFCu;
    // 80257FFC: rlwinm r0, r7, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0x000000FFu;
    }

label_80258000:
    ctx->pc = 0x80258000u;
    // 80258000: lwz     r5, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80258004:
    ctx->pc = 0x80258004u;
    // 80258004: rlwinm r5, r5, 0, 4, 0
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x8FFFFFFFu;
    }

label_80258008:
    ctx->pc = 0x80258008u;
    // 80258008: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_8025800C:
    ctx->pc = 0x8025800Cu;
    // 8025800C: stw     r4, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80258010:
    ctx->pc = 0x80258010u;
    // 80258010: lwz     r4, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80258014:
    ctx->pc = 0x80258014u;
    // 80258014: rlwinm r4, r4, 0, 0, 26
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFFE0u;
    }

label_80258018:
    ctx->pc = 0x80258018u;
    // 80258018: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_8025801C:
    ctx->pc = 0x8025801Cu;
    // 8025801C: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258020:
    ctx->pc = 0x80258020u;
    // 80258020: b       0x802580DC
    {
            goto label_802580DC;
    }

label_80258024:
    ctx->pc = 0x80258024u;
    ctx->downcount -= 16;
    // 80258024: lwz     r4, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80258028:
    ctx->pc = 0x80258028u;
    // 80258028: rlwinm r0, r5, 5, 0, 26
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 5u) & 0xFFFFFFE0u;
    }

label_8025802C:
    ctx->pc = 0x8025802Cu;
    // 8025802C: rlwinm r4, r4, 0, 27, 25
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFFDFu;
    }

label_80258030:
    ctx->pc = 0x80258030u;
    // 80258030: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80258034:
    ctx->pc = 0x80258034u;
    // 80258034: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258038:
    ctx->pc = 0x80258038u;
    // 80258038: rlwinm r4, r6, 6, 0, 25
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[6], 6u) & 0xFFFFFFC0u;
    }

label_8025803C:
    ctx->pc = 0x8025803Cu;
    // 8025803C: rlwinm r0, r7, 9, 15, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 9u) & 0x0001FE00u;
    }

label_80258040:
    ctx->pc = 0x80258040u;
    // 80258040: lwz     r5, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80258044:
    ctx->pc = 0x80258044u;
    // 80258044: rlwinm r5, r5, 0, 26, 22
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFE3Fu;
    }

label_80258048:
    ctx->pc = 0x80258048u;
    // 80258048: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_8025804C:
    ctx->pc = 0x8025804Cu;
    // 8025804C: stw     r4, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80258050:
    ctx->pc = 0x80258050u;
    // 80258050: lwz     r4, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80258054:
    ctx->pc = 0x80258054u;
    // 80258054: rlwinm r4, r4, 0, 23, 17
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFC1FFu;
    }

label_80258058:
    ctx->pc = 0x80258058u;
    // 80258058: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_8025805C:
    ctx->pc = 0x8025805Cu;
    // 8025805C: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258060:
    ctx->pc = 0x80258060u;
    // 80258060: b       0x802580DC
    {
            goto label_802580DC;
    }

label_80258064:
    ctx->pc = 0x80258064u;
    ctx->downcount -= 16;
    // 80258064: lwz     r4, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80258068:
    ctx->pc = 0x80258068u;
    // 80258068: rlwinm r0, r5, 14, 0, 17
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 14u) & 0xFFFFC000u;
    }

label_8025806C:
    ctx->pc = 0x8025806Cu;
    // 8025806C: rlwinm r4, r4, 0, 18, 16
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFBFFFu;
    }

label_80258070:
    ctx->pc = 0x80258070u;
    // 80258070: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80258074:
    ctx->pc = 0x80258074u;
    // 80258074: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258078:
    ctx->pc = 0x80258078u;
    // 80258078: rlwinm r4, r6, 15, 0, 16
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[6], 15u) & 0xFFFF8000u;
    }

label_8025807C:
    ctx->pc = 0x8025807Cu;
    // 8025807C: rlwinm r0, r7, 18, 6, 13
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 18u) & 0x03FC0000u;
    }

label_80258080:
    ctx->pc = 0x80258080u;
    // 80258080: lwz     r5, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80258084:
    ctx->pc = 0x80258084u;
    // 80258084: rlwinm r5, r5, 0, 17, 13
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFC7FFFu;
    }

label_80258088:
    ctx->pc = 0x80258088u;
    // 80258088: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_8025808C:
    ctx->pc = 0x8025808Cu;
    // 8025808C: stw     r4, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80258090:
    ctx->pc = 0x80258090u;
    // 80258090: lwz     r4, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80258094:
    ctx->pc = 0x80258094u;
    // 80258094: rlwinm r4, r4, 0, 14, 8
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFF83FFFFu;
    }

label_80258098:
    ctx->pc = 0x80258098u;
    // 80258098: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_8025809C:
    ctx->pc = 0x8025809Cu;
    // 8025809C: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802580A0:
    ctx->pc = 0x802580A0u;
    // 802580A0: b       0x802580DC
    {
            goto label_802580DC;
    }

label_802580A4:
    ctx->pc = 0x802580A4u;
    ctx->downcount -= 14;
    // 802580A4: lwz     r4, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802580A8:
    ctx->pc = 0x802580A8u;
    // 802580A8: rlwinm r0, r5, 23, 0, 8
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 23u) & 0xFF800000u;
    }

label_802580AC:
    ctx->pc = 0x802580ACu;
    // 802580AC: rlwinm r4, r4, 0, 9, 7
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFF7FFFFFu;
    }

label_802580B0:
    ctx->pc = 0x802580B0u;
    // 802580B0: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_802580B4:
    ctx->pc = 0x802580B4u;
    // 802580B4: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802580B8:
    ctx->pc = 0x802580B8u;
    // 802580B8: rlwinm r0, r6, 24, 0, 7
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 24u) & 0xFF000000u;
    }

label_802580BC:
    ctx->pc = 0x802580BCu;
    // 802580BC: lwz     r4, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802580C0:
    ctx->pc = 0x802580C0u;
    // 802580C0: rlwinm r4, r4, 0, 8, 4
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xF8FFFFFFu;
    }

label_802580C4:
    ctx->pc = 0x802580C4u;
    // 802580C4: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_802580C8:
    ctx->pc = 0x802580C8u;
    // 802580C8: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802580CC:
    ctx->pc = 0x802580CCu;
    // 802580CC: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802580D0:
    ctx->pc = 0x802580D0u;
    // 802580D0: rlwinm r0, r0, 0, 5, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x07FFFFFFu;
    }

label_802580D4:
    ctx->pc = 0x802580D4u;
    // 802580D4: rlwimi r0, r7, 27, 0, 4
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[7], 27u);
        ctx->gpr[0] = (ctx->gpr[0] & ~0xF8000000u) | (rot & 0xF8000000u);
    }

label_802580D8:
    ctx->pc = 0x802580D8u;
    // 802580D8: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802580DC:
    ctx->pc = 0x802580DCu;
    ctx->downcount -= 13;
    // 802580DC: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802580E0:
    ctx->pc = 0x802580E0u;
    // 802580E0: rlwinm r0, r3, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000000FFu;
    }

label_802580E4:
    ctx->pc = 0x802580E4u;
    // 802580E4: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802580E8:
    ctx->pc = 0x802580E8u;
    // 802580E8: lwz     r4, 1268(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1268);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802580EC:
    ctx->pc = 0x802580ECu;
    // 802580EC: slw   r0, r3, r0
    {
        u32 sh = ctx->gpr[0] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[3] << sh);
    }

label_802580F0:
    ctx->pc = 0x802580F0u;
    // 802580F0: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_802580F4:
    ctx->pc = 0x802580F4u;
    // 802580F4: ori     r3, r4, 0x0010
    ctx->gpr[3] = ctx->gpr[4] | 0x0010u;

label_802580F8:
    ctx->pc = 0x802580F8u;
    // 802580F8: stw     r3, 1268(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1268);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_802580FC:
    ctx->pc = 0x802580FCu;
    // 802580FC: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80258100:
    ctx->pc = 0x80258100u;
    // 80258100: lbz     r3, 1266(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(1266);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_80258104:
    ctx->pc = 0x80258104u;
    // 80258104: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80258108:
    ctx->pc = 0x80258108u;
    // 80258108: stb     r0, 1266(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(1266);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8025810C:
    ctx->pc = 0x8025810Cu;
    // 8025810C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80258110:
    ctx->pc = 0x80258110u;
    ctx->downcount -= 9;
    // 80258110: lwz     r6, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80258114:
    ctx->pc = 0x80258114u;
    // 80258114: rlwinm r0, r3, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0xFFFFFFFCu;
    }

label_80258118:
    ctx->pc = 0x80258118u;
    // 80258118: lis     r5, -32717
    ctx->gpr[5] = ((u32)(s32)(-32717) << 16);

label_8025811C:
    ctx->pc = 0x8025811Cu;
    // 8025811C: add   r6, r6, r0
    {
        u32 a = ctx->gpr[6];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_80258120:
    ctx->pc = 0x80258120u;
    // 80258120: addi    r8, r6, 28
    ctx->gpr[8] = ctx->gpr[6] + (u32)(s32)(28);

label_80258124:
    ctx->pc = 0x80258124u;
    // 80258124: addi    r9, r6, 60
    ctx->gpr[9] = ctx->gpr[6] + (u32)(s32)(60);

label_80258128:
    ctx->pc = 0x80258128u;
    // 80258128: addi    r10, r6, 92
    ctx->gpr[10] = ctx->gpr[6] + (u32)(s32)(92);

label_8025812C:
    ctx->pc = 0x8025812Cu;
    // 8025812C: addi    r5, r5, -324
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(-324);

label_80258130:
    ctx->pc = 0x80258130u;
    // 80258130: b       0x8025844C
    {
            goto label_8025844C;
    }

label_80258134:
    ctx->pc = 0x80258134u;
    ctx->downcount -= 7;
    // 80258134: lwz     r6, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80258138:
    ctx->pc = 0x80258138u;
    // 80258138: lbz     r7, 12(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        ctx->gpr[7] = mem_read8(ctx, ea);
    }

label_8025813C:
    // 8025813C: addi    r11, r6, -9
    ctx->gpr[11] = ctx->gpr[6] + (u32)(s32)(-9);

label_80258140:
    ctx->pc = 0x80258140u;
    // 80258140: lwz     r6, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80258144:
    // 80258144: cmplwi  r11, 0x0010
    {
        u32 val_a = (u32)(ctx->gpr[11]);
        u32 val_b = (u32)(0x0010u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80258148:
    ctx->pc = 0x80258148u;
    // 80258148: lwz     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8025814C:
    // 8025814C: bc    12, 1, 0x80258448
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80258448;
        }
    }

label_80258150:
    ctx->downcount -= 5;
    // 80258150: rlwinm r11, r11, 2, 0, 29
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 2u) & 0xFFFFFFFCu;
    }

label_80258154:
    ctx->pc = 0x80258154u;
    // 80258154: lwzx    r11, r5, r11
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[11];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80258158:
    ctx->pc = 0x80258158u;
    // 80258158: mtctr    r11
    ctx->ctr = ctx->gpr[11];

label_8025815C:
    ctx->pc = 0x8025815Cu;
    // 8025815C: bctr
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            return;
        }
    }

label_80258160:
    ctx->pc = 0x80258160u;
    ctx->downcount -= 15;
    // 80258160: lwz     r12, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_80258164:
    // 80258164: rlwinm r11, r6, 1, 0, 30
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[6], 1u) & 0xFFFFFFFEu;
    }

label_80258168:
    // 80258168: rlwinm r6, r7, 4, 0, 27
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[7], 4u) & 0xFFFFFFF0u;
    }

label_8025816C:
    // 8025816C: rlwinm r7, r12, 0, 0, 30
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[12], 0u) & 0xFFFFFFFEu;
    }

label_80258170:
    // 80258170: or   r0, r7, r0
    {
        ctx->gpr[0] = ctx->gpr[7] | ctx->gpr[0];
    }

label_80258174:
    ctx->pc = 0x80258174u;
    // 80258174: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258178:
    ctx->pc = 0x80258178u;
    // 80258178: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8025817C:
    // 8025817C: rlwinm r0, r0, 0, 31, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFF1u;
    }

label_80258180:
    // 80258180: or   r0, r0, r11
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[11];
    }

label_80258184:
    ctx->pc = 0x80258184u;
    // 80258184: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258188:
    ctx->pc = 0x80258188u;
    // 80258188: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8025818C:
    // 8025818C: rlwinm r0, r0, 0, 28, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFE0Fu;
    }

label_80258190:
    // 80258190: or   r0, r0, r6
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[6];
    }

label_80258194:
    ctx->pc = 0x80258194u;
    // 80258194: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258198:
    // 80258198: b       0x80258448
    {
            goto label_80258448;
    }

label_8025819C:
    ctx->pc = 0x8025819Cu;
    ctx->downcount -= 7;
    // 8025819C: lwz     r7, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_802581A0:
    // 802581A0: rlwinm r6, r6, 10, 0, 21
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 10u) & 0xFFFFFC00u;
    }

label_802581A4:
    // 802581A4: cmpwi   r0, 2
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

label_802581A8:
    // 802581A8: rlwinm r7, r7, 0, 22, 18
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFFFFE3FFu;
    }

label_802581AC:
    // 802581AC: or   r6, r7, r6
    {
        ctx->gpr[6] = ctx->gpr[7] | ctx->gpr[6];
    }

label_802581B0:
    ctx->pc = 0x802581B0u;
    // 802581B0: stw     r6, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_802581B4:
    // 802581B4: bc    4, 2, 0x802581DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802581DC;
        }
    }

label_802581B8:
    ctx->pc = 0x802581B8u;
    ctx->downcount -= 9;
    // 802581B8: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802581BC:
    // 802581BC: rlwinm r0, r0, 0, 23, 21
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFDFFu;
    }

label_802581C0:
    // 802581C0: ori     r0, r0, 0x0200
    ctx->gpr[0] = ctx->gpr[0] | 0x0200u;

label_802581C4:
    ctx->pc = 0x802581C4u;
    // 802581C4: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802581C8:
    ctx->pc = 0x802581C8u;
    // 802581C8: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802581CC:
    // 802581CC: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_802581D0:
    // 802581D0: oris    r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] | (0x8000u << 16);

label_802581D4:
    ctx->pc = 0x802581D4u;
    // 802581D4: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802581D8:
    // 802581D8: b       0x80258448
    {
            goto label_80258448;
    }

label_802581DC:
    ctx->pc = 0x802581DCu;
    ctx->downcount -= 9;
    // 802581DC: lwz     r6, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802581E0:
    // 802581E0: rlwinm r0, r0, 9, 0, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 9u) & 0xFFFFFE00u;
    }

label_802581E4:
    // 802581E4: rlwinm r6, r6, 0, 23, 21
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFFFFFDFFu;
    }

label_802581E8:
    // 802581E8: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_802581EC:
    ctx->pc = 0x802581ECu;
    // 802581EC: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802581F0:
    ctx->pc = 0x802581F0u;
    // 802581F0: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802581F4:
    // 802581F4: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_802581F8:
    ctx->pc = 0x802581F8u;
    // 802581F8: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802581FC:
    // 802581FC: b       0x80258448
    {
            goto label_80258448;
    }

label_80258200:
    ctx->pc = 0x80258200u;
    ctx->downcount -= 11;
    // 80258200: lwz     r11, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80258204:
    // 80258204: rlwinm r7, r0, 13, 0, 18
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[0], 13u) & 0xFFFFE000u;
    }

label_80258208:
    // 80258208: rlwinm r0, r6, 14, 0, 17
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 14u) & 0xFFFFC000u;
    }

label_8025820C:
    // 8025820C: rlwinm r6, r11, 0, 19, 17
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[11], 0u) & 0xFFFFDFFFu;
    }

label_80258210:
    // 80258210: or   r6, r6, r7
    {
        ctx->gpr[6] = ctx->gpr[6] | ctx->gpr[7];
    }

label_80258214:
    ctx->pc = 0x80258214u;
    // 80258214: stw     r6, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80258218:
    ctx->pc = 0x80258218u;
    // 80258218: lwz     r6, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8025821C:
    // 8025821C: rlwinm r6, r6, 0, 18, 14
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFFFE3FFFu;
    }

label_80258220:
    // 80258220: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_80258224:
    ctx->pc = 0x80258224u;
    // 80258224: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258228:
    // 80258228: b       0x80258448
    {
            goto label_80258448;
    }

label_8025822C:
    ctx->pc = 0x8025822Cu;
    ctx->downcount -= 11;
    // 8025822C: lwz     r11, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80258230:
    // 80258230: rlwinm r7, r0, 17, 0, 14
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[0], 17u) & 0xFFFE0000u;
    }

label_80258234:
    // 80258234: rlwinm r0, r6, 18, 0, 13
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 18u) & 0xFFFC0000u;
    }

label_80258238:
    // 80258238: rlwinm r6, r11, 0, 15, 13
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[11], 0u) & 0xFFFDFFFFu;
    }

label_8025823C:
    // 8025823C: or   r6, r6, r7
    {
        ctx->gpr[6] = ctx->gpr[6] | ctx->gpr[7];
    }

label_80258240:
    ctx->pc = 0x80258240u;
    // 80258240: stw     r6, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80258244:
    ctx->pc = 0x80258244u;
    // 80258244: lwz     r6, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80258248:
    // 80258248: rlwinm r6, r6, 0, 14, 10
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFFE3FFFFu;
    }

label_8025824C:
    // 8025824C: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_80258250:
    ctx->pc = 0x80258250u;
    // 80258250: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258254:
    // 80258254: b       0x80258448
    {
            goto label_80258448;
    }

label_80258258:
    ctx->pc = 0x80258258u;
    ctx->downcount -= 16;
    // 80258258: lwz     r11, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8025825C:
    // 8025825C: rlwinm r0, r0, 21, 0, 10
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 21u) & 0xFFE00000u;
    }

label_80258260:
    // 80258260: rlwinm r6, r6, 22, 0, 9
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 22u) & 0xFFC00000u;
    }

label_80258264:
    // 80258264: rlwinm r11, r11, 0, 11, 9
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 0u) & 0xFFDFFFFFu;
    }

label_80258268:
    // 80258268: or   r0, r11, r0
    {
        ctx->gpr[0] = ctx->gpr[11] | ctx->gpr[0];
    }

label_8025826C:
    ctx->pc = 0x8025826Cu;
    // 8025826C: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258270:
    // 80258270: rlwinm r0, r7, 25, 0, 6
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 25u) & 0xFE000000u;
    }

label_80258274:
    ctx->pc = 0x80258274u;
    // 80258274: lwz     r7, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80258278:
    // 80258278: rlwinm r7, r7, 0, 10, 6
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFE3FFFFFu;
    }

label_8025827C:
    // 8025827C: or   r6, r7, r6
    {
        ctx->gpr[6] = ctx->gpr[7] | ctx->gpr[6];
    }

label_80258280:
    ctx->pc = 0x80258280u;
    // 80258280: stw     r6, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80258284:
    ctx->pc = 0x80258284u;
    // 80258284: lwz     r6, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80258288:
    // 80258288: rlwinm r6, r6, 0, 7, 1
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xC1FFFFFFu;
    }

label_8025828C:
    // 8025828C: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_80258290:
    ctx->pc = 0x80258290u;
    // 80258290: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258294:
    // 80258294: b       0x80258448
    {
            goto label_80258448;
    }

label_80258298:
    ctx->pc = 0x80258298u;
    ctx->downcount -= 15;
    // 80258298: lwz     r12, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_8025829C:
    // 8025829C: rlwinm r11, r6, 1, 0, 30
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[6], 1u) & 0xFFFFFFFEu;
    }

label_802582A0:
    // 802582A0: rlwinm r6, r7, 4, 0, 27
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[7], 4u) & 0xFFFFFFF0u;
    }

label_802582A4:
    // 802582A4: rlwinm r7, r12, 0, 0, 30
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[12], 0u) & 0xFFFFFFFEu;
    }

label_802582A8:
    // 802582A8: or   r0, r7, r0
    {
        ctx->gpr[0] = ctx->gpr[7] | ctx->gpr[0];
    }

label_802582AC:
    ctx->pc = 0x802582ACu;
    // 802582AC: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802582B0:
    ctx->pc = 0x802582B0u;
    // 802582B0: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802582B4:
    // 802582B4: rlwinm r0, r0, 0, 31, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFF1u;
    }

label_802582B8:
    // 802582B8: or   r0, r0, r11
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[11];
    }

label_802582BC:
    ctx->pc = 0x802582BCu;
    // 802582BC: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802582C0:
    ctx->pc = 0x802582C0u;
    // 802582C0: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802582C4:
    // 802582C4: rlwinm r0, r0, 0, 28, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFE0Fu;
    }

label_802582C8:
    // 802582C8: or   r0, r0, r6
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[6];
    }

label_802582CC:
    ctx->pc = 0x802582CCu;
    // 802582CC: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802582D0:
    // 802582D0: b       0x80258448
    {
            goto label_80258448;
    }

label_802582D4:
    ctx->pc = 0x802582D4u;
    ctx->downcount -= 16;
    // 802582D4: lwz     r11, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_802582D8:
    // 802582D8: rlwinm r0, r0, 9, 0, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 9u) & 0xFFFFFE00u;
    }

label_802582DC:
    // 802582DC: rlwinm r6, r6, 10, 0, 21
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 10u) & 0xFFFFFC00u;
    }

label_802582E0:
    // 802582E0: rlwinm r11, r11, 0, 23, 21
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 0u) & 0xFFFFFDFFu;
    }

label_802582E4:
    // 802582E4: or   r0, r11, r0
    {
        ctx->gpr[0] = ctx->gpr[11] | ctx->gpr[0];
    }

label_802582E8:
    ctx->pc = 0x802582E8u;
    // 802582E8: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802582EC:
    // 802582EC: rlwinm r0, r7, 13, 0, 18
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 13u) & 0xFFFFE000u;
    }

label_802582F0:
    ctx->pc = 0x802582F0u;
    // 802582F0: lwz     r7, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_802582F4:
    // 802582F4: rlwinm r7, r7, 0, 22, 18
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFFFFE3FFu;
    }

label_802582F8:
    // 802582F8: or   r6, r7, r6
    {
        ctx->gpr[6] = ctx->gpr[7] | ctx->gpr[6];
    }

label_802582FC:
    ctx->pc = 0x802582FCu;
    // 802582FC: stw     r6, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80258300:
    ctx->pc = 0x80258300u;
    // 80258300: lwz     r6, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80258304:
    // 80258304: rlwinm r6, r6, 0, 19, 13
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFFFC1FFFu;
    }

label_80258308:
    // 80258308: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_8025830C:
    ctx->pc = 0x8025830Cu;
    // 8025830C: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258310:
    // 80258310: b       0x80258448
    {
            goto label_80258448;
    }

label_80258314:
    ctx->pc = 0x80258314u;
    ctx->downcount -= 16;
    // 80258314: lwz     r11, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80258318:
    // 80258318: rlwinm r0, r0, 18, 0, 13
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 18u) & 0xFFFC0000u;
    }

label_8025831C:
    // 8025831C: rlwinm r6, r6, 19, 0, 12
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 19u) & 0xFFF80000u;
    }

label_80258320:
    // 80258320: rlwinm r11, r11, 0, 14, 12
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 0u) & 0xFFFBFFFFu;
    }

label_80258324:
    // 80258324: or   r0, r11, r0
    {
        ctx->gpr[0] = ctx->gpr[11] | ctx->gpr[0];
    }

label_80258328:
    ctx->pc = 0x80258328u;
    // 80258328: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8025832C:
    // 8025832C: rlwinm r0, r7, 22, 0, 9
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 22u) & 0xFFC00000u;
    }

label_80258330:
    ctx->pc = 0x80258330u;
    // 80258330: lwz     r7, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80258334:
    // 80258334: rlwinm r7, r7, 0, 13, 9
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFFC7FFFFu;
    }

label_80258338:
    // 80258338: or   r6, r7, r6
    {
        ctx->gpr[6] = ctx->gpr[7] | ctx->gpr[6];
    }

label_8025833C:
    ctx->pc = 0x8025833Cu;
    // 8025833C: stw     r6, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80258340:
    ctx->pc = 0x80258340u;
    // 80258340: lwz     r6, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80258344:
    // 80258344: rlwinm r6, r6, 0, 10, 4
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xF83FFFFFu;
    }

label_80258348:
    // 80258348: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_8025834C:
    ctx->pc = 0x8025834Cu;
    // 8025834C: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258350:
    // 80258350: b       0x80258448
    {
            goto label_80258448;
    }

label_80258354:
    ctx->pc = 0x80258354u;
    ctx->downcount -= 15;
    // 80258354: lwz     r12, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_80258358:
    // 80258358: rlwinm r11, r0, 27, 0, 4
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0xF8000000u;
    }

label_8025835C:
    // 8025835C: rlwinm r0, r6, 28, 0, 3
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 28u) & 0xF0000000u;
    }

label_80258360:
    // 80258360: rlwinm r6, r12, 0, 5, 3
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[12], 0u) & 0xF7FFFFFFu;
    }

label_80258364:
    // 80258364: or   r6, r6, r11
    {
        ctx->gpr[6] = ctx->gpr[6] | ctx->gpr[11];
    }

label_80258368:
    ctx->pc = 0x80258368u;
    // 80258368: stw     r6, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8025836C:
    ctx->pc = 0x8025836Cu;
    // 8025836C: lwz     r6, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80258370:
    // 80258370: rlwinm r6, r6, 0, 4, 0
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x8FFFFFFFu;
    }

label_80258374:
    // 80258374: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_80258378:
    ctx->pc = 0x80258378u;
    // 80258378: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8025837C:
    ctx->pc = 0x8025837Cu;
    // 8025837C: lwz     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80258380:
    // 80258380: rlwinm r0, r0, 0, 0, 26
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFE0u;
    }

label_80258384:
    // 80258384: or   r0, r0, r7
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[7];
    }

label_80258388:
    ctx->pc = 0x80258388u;
    // 80258388: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8025838C:
    // 8025838C: b       0x80258448
    {
            goto label_80258448;
    }

label_80258390:
    ctx->pc = 0x80258390u;
    ctx->downcount -= 16;
    // 80258390: lwz     r11, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80258394:
    // 80258394: rlwinm r0, r0, 5, 0, 26
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 5u) & 0xFFFFFFE0u;
    }

label_80258398:
    // 80258398: rlwinm r6, r6, 6, 0, 25
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 6u) & 0xFFFFFFC0u;
    }

label_8025839C:
    // 8025839C: rlwinm r11, r11, 0, 27, 25
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 0u) & 0xFFFFFFDFu;
    }

label_802583A0:
    // 802583A0: or   r0, r11, r0
    {
        ctx->gpr[0] = ctx->gpr[11] | ctx->gpr[0];
    }

label_802583A4:
    ctx->pc = 0x802583A4u;
    // 802583A4: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802583A8:
    // 802583A8: rlwinm r0, r7, 9, 0, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 9u) & 0xFFFFFE00u;
    }

label_802583AC:
    ctx->pc = 0x802583ACu;
    // 802583AC: lwz     r7, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_802583B0:
    // 802583B0: rlwinm r7, r7, 0, 26, 22
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFFFFFE3Fu;
    }

label_802583B4:
    // 802583B4: or   r6, r7, r6
    {
        ctx->gpr[6] = ctx->gpr[7] | ctx->gpr[6];
    }

label_802583B8:
    ctx->pc = 0x802583B8u;
    // 802583B8: stw     r6, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_802583BC:
    ctx->pc = 0x802583BCu;
    // 802583BC: lwz     r6, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802583C0:
    // 802583C0: rlwinm r6, r6, 0, 23, 17
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFFFFC1FFu;
    }

label_802583C4:
    // 802583C4: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_802583C8:
    ctx->pc = 0x802583C8u;
    // 802583C8: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802583CC:
    // 802583CC: b       0x80258448
    {
            goto label_80258448;
    }

label_802583D0:
    ctx->pc = 0x802583D0u;
    ctx->downcount -= 16;
    // 802583D0: lwz     r11, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_802583D4:
    // 802583D4: rlwinm r0, r0, 14, 0, 17
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 14u) & 0xFFFFC000u;
    }

label_802583D8:
    // 802583D8: rlwinm r6, r6, 15, 0, 16
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 15u) & 0xFFFF8000u;
    }

label_802583DC:
    // 802583DC: rlwinm r11, r11, 0, 18, 16
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 0u) & 0xFFFFBFFFu;
    }

label_802583E0:
    // 802583E0: or   r0, r11, r0
    {
        ctx->gpr[0] = ctx->gpr[11] | ctx->gpr[0];
    }

label_802583E4:
    ctx->pc = 0x802583E4u;
    // 802583E4: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802583E8:
    // 802583E8: rlwinm r0, r7, 18, 0, 13
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 18u) & 0xFFFC0000u;
    }

label_802583EC:
    ctx->pc = 0x802583ECu;
    // 802583EC: lwz     r7, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_802583F0:
    // 802583F0: rlwinm r7, r7, 0, 17, 13
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFFFC7FFFu;
    }

label_802583F4:
    // 802583F4: or   r6, r7, r6
    {
        ctx->gpr[6] = ctx->gpr[7] | ctx->gpr[6];
    }

label_802583F8:
    ctx->pc = 0x802583F8u;
    // 802583F8: stw     r6, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_802583FC:
    ctx->pc = 0x802583FCu;
    // 802583FC: lwz     r6, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80258400:
    // 80258400: rlwinm r6, r6, 0, 14, 8
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFF83FFFFu;
    }

label_80258404:
    // 80258404: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_80258408:
    ctx->pc = 0x80258408u;
    // 80258408: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8025840C:
    // 8025840C: b       0x80258448
    {
            goto label_80258448;
    }

label_80258410:
    ctx->pc = 0x80258410u;
    ctx->downcount -= 14;
    // 80258410: lwz     r12, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_80258414:
    // 80258414: rlwinm r11, r0, 23, 0, 8
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[0], 23u) & 0xFF800000u;
    }

label_80258418:
    // 80258418: rlwinm r0, r6, 24, 0, 7
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 24u) & 0xFF000000u;
    }

label_8025841C:
    // 8025841C: rlwinm r6, r12, 0, 9, 7
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[12], 0u) & 0xFF7FFFFFu;
    }

label_80258420:
    // 80258420: or   r6, r6, r11
    {
        ctx->gpr[6] = ctx->gpr[6] | ctx->gpr[11];
    }

label_80258424:
    ctx->pc = 0x80258424u;
    // 80258424: stw     r6, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80258428:
    ctx->pc = 0x80258428u;
    // 80258428: lwz     r6, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8025842C:
    // 8025842C: rlwinm r6, r6, 0, 8, 4
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xF8FFFFFFu;
    }

label_80258430:
    // 80258430: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_80258434:
    ctx->pc = 0x80258434u;
    // 80258434: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258438:
    ctx->pc = 0x80258438u;
    // 80258438: lwz     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8025843C:
    // 8025843C: rlwinm r0, r0, 0, 5, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x07FFFFFFu;
    }

label_80258440:
    // 80258440: rlwimi r0, r7, 27, 0, 4
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[7], 27u);
        ctx->gpr[0] = (ctx->gpr[0] & ~0xF8000000u) | (rot & 0xF8000000u);
    }

label_80258444:
    ctx->pc = 0x80258444u;
    // 80258444: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258448:
    ctx->downcount -= 1;
    // 80258448: addi    r4, r4, 16
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(16);

label_8025844C:
    ctx->pc = 0x8025844Cu;
    ctx->downcount -= 3;
    // 8025844C: lwz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80258450:
    // 80258450: cmpwi   r0, 255
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

label_80258454:
    // 80258454: bc    4, 2, 0x80258134
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80258134u;
                return;
            }
            goto label_80258134;
        }
    }

label_80258458:
    ctx->pc = 0x80258458u;
    ctx->downcount -= 13;
    // 80258458: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8025845C:
    ctx->pc = 0x8025845Cu;
    // 8025845C: rlwinm r0, r3, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000000FFu;
    }

label_80258460:
    ctx->pc = 0x80258460u;
    // 80258460: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80258464:
    ctx->pc = 0x80258464u;
    // 80258464: lwz     r4, 1268(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1268);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80258468:
    ctx->pc = 0x80258468u;
    // 80258468: slw   r0, r3, r0
    {
        u32 sh = ctx->gpr[0] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[3] << sh);
    }

label_8025846C:
    ctx->pc = 0x8025846Cu;
    // 8025846C: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_80258470:
    ctx->pc = 0x80258470u;
    // 80258470: ori     r3, r4, 0x0010
    ctx->gpr[3] = ctx->gpr[4] | 0x0010u;

label_80258474:
    ctx->pc = 0x80258474u;
    // 80258474: stw     r3, 1268(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1268);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80258478:
    ctx->pc = 0x80258478u;
    // 80258478: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8025847C:
    ctx->pc = 0x8025847Cu;
    // 8025847C: lbz     r3, 1266(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(1266);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_80258480:
    ctx->pc = 0x80258480u;
    // 80258480: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80258484:
    ctx->pc = 0x80258484u;
    // 80258484: stb     r0, 1266(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(1266);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80258488:
    ctx->pc = 0x80258488u;
    // 80258488: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_8025848C:
    ctx->pc = 0x8025848Cu;
    ctx->downcount -= 5;
    // 8025848C: lwz     r10, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80258490:
    ctx->pc = 0x80258490u;
    // 80258490: li      r12, 0
    ctx->gpr[12] = (u32)(s32)(0);

label_80258494:
    ctx->pc = 0x80258494u;
    // 80258494: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_80258498:
    ctx->pc = 0x80258498u;
    // 80258498: lis     r7, -13311
    ctx->gpr[7] = ((u32)(s32)(-13311) << 16);

label_8025849C:
    ctx->pc = 0x8025849Cu;
    // 8025849C: b       0x8025850C
    {
            goto label_8025850C;
    }

label_802584A0:
    ctx->downcount -= 6;
    // 802584A0: rlwinm r9, r12, 0, 24, 31
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[12], 0u) & 0x000000FFu;
    }

label_802584A4:
    ctx->pc = 0x802584A4u;
    // 802584A4: lbz     r3, 1266(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(1266);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_802584A8:
    // 802584A8: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_802584AC:
    // 802584AC: slw   r0, r0, r9
    {
        u32 sh = ctx->gpr[9] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[0] << sh);
    }

label_802584B0:
    // 802584B0: and.   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] & ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802584B4:
    // 802584B4: bc    12, 2, 0x80258504
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80258504;
        }
    }

label_802584B8:
    ctx->downcount -= 19;
    // 802584B8: li      r8, 8
    ctx->gpr[8] = (u32)(s32)(8);

label_802584BC:
    ctx->pc = 0x802584BCu;
    // 802584BC: stb     r8, -32768(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[8]);
    }

label_802584C0:
    // 802584C0: ori     r3, r9, 0x0070
    ctx->gpr[3] = ctx->gpr[9] | 0x0070u;

label_802584C4:
    // 802584C4: addi    r0, r11, 28
    ctx->gpr[0] = ctx->gpr[11] + (u32)(s32)(28);

label_802584C8:
    ctx->pc = 0x802584C8u;
    // 802584C8: stb     r3, -32768(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_802584CC:
    // 802584CC: ori     r5, r9, 0x0080
    ctx->gpr[5] = ctx->gpr[9] | 0x0080u;

label_802584D0:
    // 802584D0: addi    r4, r11, 60
    ctx->gpr[4] = ctx->gpr[11] + (u32)(s32)(60);

label_802584D4:
    ctx->pc = 0x802584D4u;
    // 802584D4: lwzx    r6, r10, r0
    {
        u32 ea = ctx->gpr[10] + ctx->gpr[0];
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_802584D8:
    // 802584D8: ori     r3, r9, 0x0090
    ctx->gpr[3] = ctx->gpr[9] | 0x0090u;

label_802584DC:
    // 802584DC: addi    r0, r11, 92
    ctx->gpr[0] = ctx->gpr[11] + (u32)(s32)(92);

label_802584E0:
    ctx->pc = 0x802584E0u;
    // 802584E0: stw     r6, -32768(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_802584E4:
    ctx->pc = 0x802584E4u;
    // 802584E4: stb     r8, -32768(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[8]);
    }

label_802584E8:
    ctx->pc = 0x802584E8u;
    // 802584E8: stb     r5, -32768(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

label_802584EC:
    ctx->pc = 0x802584ECu;
    // 802584EC: lwzx    r4, r10, r4
    {
        u32 ea = ctx->gpr[10] + ctx->gpr[4];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802584F0:
    ctx->pc = 0x802584F0u;
    // 802584F0: stw     r4, -32768(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802584F4:
    ctx->pc = 0x802584F4u;
    // 802584F4: stb     r8, -32768(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[8]);
    }

label_802584F8:
    ctx->pc = 0x802584F8u;
    // 802584F8: stb     r3, -32768(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_802584FC:
    ctx->pc = 0x802584FCu;
    // 802584FC: lwzx    r0, r10, r0
    {
        u32 ea = ctx->gpr[10] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80258500:
    ctx->pc = 0x80258500u;
    // 80258500: stw     r0, -32768(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258504:
    ctx->downcount -= 2;
    // 80258504: addi    r11, r11, 4
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(4);

label_80258508:
    // 80258508: addi    r12, r12, 1
    ctx->gpr[12] = ctx->gpr[12] + (u32)(s32)(1);

label_8025850C:
    ctx->downcount -= 3;
    // 8025850C: rlwinm r0, r12, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[12], 0u) & 0x000000FFu;
    }

label_80258510:
    // 80258510: cmplwi  r0, 0x0008
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0008u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80258514:
    // 80258514: bc    12, 0, 0x802584A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802584A0u;
                return;
            }
            goto label_802584A0;
        }
    }

label_80258518:
    ctx->pc = 0x80258518u;
    ctx->downcount -= 4;
    // 80258518: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8025851C:
    ctx->pc = 0x8025851Cu;
    // 8025851C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80258520:
    ctx->pc = 0x80258520u;
    // 80258520: stb     r0, 1266(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1266);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80258524:
    ctx->pc = 0x80258524u;
    // 80258524: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80258528:
    ctx->pc = 0x80258528u;
    ctx->downcount -= 9;
    // 80258528: addi    r0, r4, -9
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(-9);

label_8025852C:
    ctx->pc = 0x8025852Cu;
    // 8025852C: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80258530:
    ctx->pc = 0x80258530u;
    // 80258530: rlwinm r3, r3, 2, 0, 29
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0xFFFFFFFCu;
    }

label_80258534:
    ctx->pc = 0x80258534u;
    // 80258534: add   r4, r4, r3
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_80258538:
    ctx->pc = 0x80258538u;
    // 80258538: cmplwi  r0, 0x0010
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0010u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8025853C:
    ctx->pc = 0x8025853Cu;
    // 8025853C: addi    r3, r4, 28
    ctx->gpr[3] = ctx->gpr[4] + (u32)(s32)(28);

label_80258540:
    ctx->pc = 0x80258540u;
    // 80258540: addi    r8, r4, 60
    ctx->gpr[8] = ctx->gpr[4] + (u32)(s32)(60);

label_80258544:
    ctx->pc = 0x80258544u;
    // 80258544: addi    r9, r4, 92
    ctx->gpr[9] = ctx->gpr[4] + (u32)(s32)(92);

label_80258548:
    ctx->pc = 0x80258548u;
    // 80258548: bc    12, 1, 0x80258758
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80258758;
        }
    }

label_8025854C:
    ctx->pc = 0x8025854Cu;
    ctx->downcount -= 7;
    // 8025854C: lis     r4, -32717
    ctx->gpr[4] = ((u32)(s32)(-32717) << 16);

label_80258550:
    ctx->pc = 0x80258550u;
    // 80258550: addi    r4, r4, -256
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-256);

label_80258554:
    ctx->pc = 0x80258554u;
    // 80258554: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_80258558:
    ctx->pc = 0x80258558u;
    // 80258558: lwzx    r0, r4, r0
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8025855C:
    ctx->pc = 0x8025855Cu;
    // 8025855C: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_80258560:
    ctx->pc = 0x80258560u;
    // 80258560: bctr
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            return;
        }
    }

label_80258564:
    ctx->pc = 0x80258564u;
    ctx->downcount -= 10;
    // 80258564: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80258568:
    ctx->pc = 0x80258568u;
    // 80258568: rlwinm r0, r0, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000001u;
    }

label_8025856C:
    ctx->pc = 0x8025856Cu;
    // 8025856C: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258570:
    ctx->pc = 0x80258570u;
    // 80258570: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80258574:
    ctx->pc = 0x80258574u;
    // 80258574: rlwinm r0, r0, 31, 29, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x00000007u;
    }

label_80258578:
    ctx->pc = 0x80258578u;
    // 80258578: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8025857C:
    ctx->pc = 0x8025857Cu;
    // 8025857C: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80258580:
    ctx->pc = 0x80258580u;
    // 80258580: rlwinm r0, r0, 28, 27, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 28u) & 0x0000001Fu;
    }

label_80258584:
    ctx->pc = 0x80258584u;
    // 80258584: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80258588:
    ctx->pc = 0x80258588u;
    // 80258588: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_8025858C:
    ctx->pc = 0x8025858Cu;
    ctx->downcount -= 6;
    // 8025858C: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80258590:
    ctx->pc = 0x80258590u;
    // 80258590: rlwinm r0, r0, 23, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 23u) & 0x00000001u;
    }

label_80258594:
    ctx->pc = 0x80258594u;
    // 80258594: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258598:
    ctx->pc = 0x80258598u;
    // 80258598: lwz     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8025859C:
    ctx->pc = 0x8025859Cu;
    // 8025859C: cmpwi   r0, 1
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

label_802585A0:
    ctx->pc = 0x802585A0u;
    // 802585A0: bc    4, 2, 0x802585B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802585B8;
        }
    }

label_802585A4:
    ctx->pc = 0x802585A4u;
    ctx->downcount -= 3;
    // 802585A4: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802585A8:
    ctx->pc = 0x802585A8u;
    // 802585A8: rlwinm. r0, r0, 1, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 1u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802585AC:
    ctx->pc = 0x802585ACu;
    // 802585AC: bc    12, 2, 0x802585B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802585B8;
        }
    }

label_802585B0:
    ctx->pc = 0x802585B0u;
    ctx->downcount -= 2;
    // 802585B0: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_802585B4:
    ctx->pc = 0x802585B4u;
    // 802585B4: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802585B8:
    ctx->pc = 0x802585B8u;
    ctx->downcount -= 6;
    // 802585B8: lwz     r3, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802585BC:
    ctx->pc = 0x802585BCu;
    // 802585BC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802585C0:
    ctx->pc = 0x802585C0u;
    // 802585C0: rlwinm r3, r3, 22, 29, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 22u) & 0x00000007u;
    }

label_802585C4:
    ctx->pc = 0x802585C4u;
    // 802585C4: stw     r3, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_802585C8:
    ctx->pc = 0x802585C8u;
    // 802585C8: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802585CC:
    ctx->pc = 0x802585CCu;
    // 802585CC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_802585D0:
    ctx->pc = 0x802585D0u;
    ctx->downcount -= 9;
    // 802585D0: lwz     r4, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802585D4:
    ctx->pc = 0x802585D4u;
    // 802585D4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802585D8:
    ctx->pc = 0x802585D8u;
    // 802585D8: rlwinm r4, r4, 19, 31, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 19u) & 0x00000001u;
    }

label_802585DC:
    ctx->pc = 0x802585DCu;
    // 802585DC: stw     r4, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802585E0:
    ctx->pc = 0x802585E0u;
    // 802585E0: lwz     r3, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802585E4:
    ctx->pc = 0x802585E4u;
    // 802585E4: rlwinm r3, r3, 18, 29, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 18u) & 0x00000007u;
    }

label_802585E8:
    ctx->pc = 0x802585E8u;
    // 802585E8: stw     r3, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_802585EC:
    ctx->pc = 0x802585ECu;
    // 802585EC: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802585F0:
    ctx->pc = 0x802585F0u;
    // 802585F0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_802585F4:
    ctx->pc = 0x802585F4u;
    ctx->downcount -= 9;
    // 802585F4: lwz     r4, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802585F8:
    ctx->pc = 0x802585F8u;
    // 802585F8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802585FC:
    ctx->pc = 0x802585FCu;
    // 802585FC: rlwinm r4, r4, 15, 31, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 15u) & 0x00000001u;
    }

label_80258600:
    ctx->pc = 0x80258600u;
    // 80258600: stw     r4, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80258604:
    ctx->pc = 0x80258604u;
    // 80258604: lwz     r3, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80258608:
    ctx->pc = 0x80258608u;
    // 80258608: rlwinm r3, r3, 14, 29, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 14u) & 0x00000007u;
    }

label_8025860C:
    ctx->pc = 0x8025860Cu;
    // 8025860C: stw     r3, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80258610:
    ctx->pc = 0x80258610u;
    // 80258610: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80258614:
    ctx->pc = 0x80258614u;
    // 80258614: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80258618:
    ctx->pc = 0x80258618u;
    ctx->downcount -= 10;
    // 80258618: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8025861C:
    ctx->pc = 0x8025861Cu;
    // 8025861C: rlwinm r0, r0, 11, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 11u) & 0x00000001u;
    }

label_80258620:
    ctx->pc = 0x80258620u;
    // 80258620: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258624:
    ctx->pc = 0x80258624u;
    // 80258624: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80258628:
    ctx->pc = 0x80258628u;
    // 80258628: rlwinm r0, r0, 10, 29, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 10u) & 0x00000007u;
    }

label_8025862C:
    ctx->pc = 0x8025862Cu;
    // 8025862C: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258630:
    ctx->pc = 0x80258630u;
    // 80258630: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80258634:
    ctx->pc = 0x80258634u;
    // 80258634: rlwinm r0, r0, 7, 27, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 7u) & 0x0000001Fu;
    }

label_80258638:
    ctx->pc = 0x80258638u;
    // 80258638: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8025863C:
    ctx->pc = 0x8025863Cu;
    // 8025863C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80258640:
    ctx->pc = 0x80258640u;
    ctx->downcount -= 10;
    // 80258640: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80258644:
    ctx->pc = 0x80258644u;
    // 80258644: rlwinm r0, r0, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000001u;
    }

label_80258648:
    ctx->pc = 0x80258648u;
    // 80258648: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8025864C:
    ctx->pc = 0x8025864Cu;
    // 8025864C: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80258650:
    ctx->pc = 0x80258650u;
    // 80258650: rlwinm r0, r0, 31, 29, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x00000007u;
    }

label_80258654:
    ctx->pc = 0x80258654u;
    // 80258654: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258658:
    ctx->pc = 0x80258658u;
    // 80258658: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8025865C:
    ctx->pc = 0x8025865Cu;
    // 8025865C: rlwinm r0, r0, 28, 27, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 28u) & 0x0000001Fu;
    }

label_80258660:
    ctx->pc = 0x80258660u;
    // 80258660: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80258664:
    ctx->pc = 0x80258664u;
    // 80258664: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80258668:
    ctx->pc = 0x80258668u;
    ctx->downcount -= 10;
    // 80258668: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8025866C:
    ctx->pc = 0x8025866Cu;
    // 8025866C: rlwinm r0, r0, 23, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 23u) & 0x00000001u;
    }

label_80258670:
    ctx->pc = 0x80258670u;
    // 80258670: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258674:
    ctx->pc = 0x80258674u;
    // 80258674: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80258678:
    ctx->pc = 0x80258678u;
    // 80258678: rlwinm r0, r0, 22, 29, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 22u) & 0x00000007u;
    }

label_8025867C:
    ctx->pc = 0x8025867Cu;
    // 8025867C: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258680:
    ctx->pc = 0x80258680u;
    // 80258680: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80258684:
    ctx->pc = 0x80258684u;
    // 80258684: rlwinm r0, r0, 19, 27, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 19u) & 0x0000001Fu;
    }

label_80258688:
    ctx->pc = 0x80258688u;
    // 80258688: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8025868C:
    ctx->pc = 0x8025868Cu;
    // 8025868C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80258690:
    ctx->pc = 0x80258690u;
    ctx->downcount -= 10;
    // 80258690: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80258694:
    ctx->pc = 0x80258694u;
    // 80258694: rlwinm r0, r0, 14, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 14u) & 0x00000001u;
    }

label_80258698:
    ctx->pc = 0x80258698u;
    // 80258698: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8025869C:
    ctx->pc = 0x8025869Cu;
    // 8025869C: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802586A0:
    ctx->pc = 0x802586A0u;
    // 802586A0: rlwinm r0, r0, 13, 29, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 13u) & 0x00000007u;
    }

label_802586A4:
    ctx->pc = 0x802586A4u;
    // 802586A4: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802586A8:
    ctx->pc = 0x802586A8u;
    // 802586A8: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802586AC:
    ctx->pc = 0x802586ACu;
    // 802586AC: rlwinm r0, r0, 10, 27, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 10u) & 0x0000001Fu;
    }

label_802586B0:
    ctx->pc = 0x802586B0u;
    // 802586B0: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802586B4:
    ctx->pc = 0x802586B4u;
    // 802586B4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_802586B8:
    ctx->pc = 0x802586B8u;
    ctx->downcount -= 10;
    // 802586B8: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802586BC:
    ctx->pc = 0x802586BCu;
    // 802586BC: rlwinm r0, r0, 5, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 5u) & 0x00000001u;
    }

label_802586C0:
    ctx->pc = 0x802586C0u;
    // 802586C0: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802586C4:
    ctx->pc = 0x802586C4u;
    // 802586C4: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802586C8:
    ctx->pc = 0x802586C8u;
    // 802586C8: rlwinm r0, r0, 4, 29, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 4u) & 0x00000007u;
    }

label_802586CC:
    ctx->pc = 0x802586CCu;
    // 802586CC: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802586D0:
    ctx->pc = 0x802586D0u;
    // 802586D0: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802586D4:
    ctx->pc = 0x802586D4u;
    // 802586D4: rlwinm r0, r0, 0, 27, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x0000001Fu;
    }

label_802586D8:
    ctx->pc = 0x802586D8u;
    // 802586D8: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802586DC:
    ctx->pc = 0x802586DCu;
    // 802586DC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_802586E0:
    ctx->pc = 0x802586E0u;
    ctx->downcount -= 10;
    // 802586E0: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802586E4:
    ctx->pc = 0x802586E4u;
    // 802586E4: rlwinm r0, r0, 27, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x00000001u;
    }

label_802586E8:
    ctx->pc = 0x802586E8u;
    // 802586E8: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802586EC:
    ctx->pc = 0x802586ECu;
    // 802586EC: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802586F0:
    ctx->pc = 0x802586F0u;
    // 802586F0: rlwinm r0, r0, 26, 29, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 26u) & 0x00000007u;
    }

label_802586F4:
    ctx->pc = 0x802586F4u;
    // 802586F4: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802586F8:
    ctx->pc = 0x802586F8u;
    // 802586F8: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802586FC:
    ctx->pc = 0x802586FCu;
    // 802586FC: rlwinm r0, r0, 23, 27, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 23u) & 0x0000001Fu;
    }

label_80258700:
    ctx->pc = 0x80258700u;
    // 80258700: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80258704:
    ctx->pc = 0x80258704u;
    // 80258704: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80258708:
    ctx->pc = 0x80258708u;
    ctx->downcount -= 10;
    // 80258708: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8025870C:
    ctx->pc = 0x8025870Cu;
    // 8025870C: rlwinm r0, r0, 18, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 18u) & 0x00000001u;
    }

label_80258710:
    ctx->pc = 0x80258710u;
    // 80258710: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258714:
    ctx->pc = 0x80258714u;
    // 80258714: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80258718:
    ctx->pc = 0x80258718u;
    // 80258718: rlwinm r0, r0, 17, 29, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 17u) & 0x00000007u;
    }

label_8025871C:
    ctx->pc = 0x8025871Cu;
    // 8025871C: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258720:
    ctx->pc = 0x80258720u;
    // 80258720: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80258724:
    ctx->pc = 0x80258724u;
    // 80258724: rlwinm r0, r0, 14, 27, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 14u) & 0x0000001Fu;
    }

label_80258728:
    ctx->pc = 0x80258728u;
    // 80258728: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8025872C:
    ctx->pc = 0x8025872Cu;
    // 8025872C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80258730:
    ctx->pc = 0x80258730u;
    ctx->downcount -= 10;
    // 80258730: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80258734:
    ctx->pc = 0x80258734u;
    // 80258734: rlwinm r0, r0, 9, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 9u) & 0x00000001u;
    }

label_80258738:
    ctx->pc = 0x80258738u;
    // 80258738: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8025873C:
    ctx->pc = 0x8025873Cu;
    // 8025873C: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80258740:
    ctx->pc = 0x80258740u;
    // 80258740: rlwinm r0, r0, 8, 29, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 8u) & 0x00000007u;
    }

label_80258744:
    ctx->pc = 0x80258744u;
    // 80258744: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258748:
    ctx->pc = 0x80258748u;
    // 80258748: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8025874C:
    ctx->pc = 0x8025874Cu;
    // 8025874C: rlwinm r0, r0, 5, 27, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 5u) & 0x0000001Fu;
    }

label_80258750:
    ctx->pc = 0x80258750u;
    // 80258750: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80258754:
    ctx->pc = 0x80258754u;
    // 80258754: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80258758:
    ctx->pc = 0x80258758u;
    ctx->downcount -= 6;
    // 80258758: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8025875C:
    ctx->pc = 0x8025875Cu;
    // 8025875C: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258760:
    ctx->pc = 0x80258760u;
    // 80258760: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80258764:
    ctx->pc = 0x80258764u;
    // 80258764: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258768:
    ctx->pc = 0x80258768u;
    // 80258768: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8025876C:
    ctx->pc = 0x8025876Cu;
    // 8025876C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80258770:
    ctx->pc = 0x80258770u;
    ctx->downcount -= 9;
    // 80258770: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80258774:
    ctx->pc = 0x80258774u;
    // 80258774: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258778:
    ctx->pc = 0x80258778u;
    // 80258778: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8025877C:
    ctx->pc = 0x8025877Cu;
    // 8025877C: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80258780:
    ctx->pc = 0x80258780u;
    // 80258780: li      r31, 9
    ctx->gpr[31] = (u32)(s32)(9);

label_80258784:
    ctx->pc = 0x80258784u;
    // 80258784: stw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80258788:
    ctx->pc = 0x80258788u;
    // 80258788: addi    r30, r4, 0
    ctx->gpr[30] = ctx->gpr[4] + (u32)(s32)(0);

label_8025878C:
    ctx->pc = 0x8025878Cu;
    // 8025878C: stw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80258790:
    ctx->pc = 0x80258790u;
    // 80258790: addi    r29, r3, 0
    ctx->gpr[29] = ctx->gpr[3] + (u32)(s32)(0);

label_80258794:
    ctx->pc = 0x80258794u;
    ctx->downcount -= 7;
    // 80258794: stw     r31, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80258798:
    // 80258798: addi    r3, r29, 0
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(0);

label_8025879C:
    // 8025879C: addi    r4, r31, 0
    ctx->gpr[4] = ctx->gpr[31] + (u32)(s32)(0);

label_802587A0:
    // 802587A0: addi    r5, r30, 4
    ctx->gpr[5] = ctx->gpr[30] + (u32)(s32)(4);

label_802587A4:
    // 802587A4: addi    r6, r30, 8
    ctx->gpr[6] = ctx->gpr[30] + (u32)(s32)(8);

label_802587A8:
    // 802587A8: addi    r7, r30, 12
    ctx->gpr[7] = ctx->gpr[30] + (u32)(s32)(12);

label_802587AC:
    // 802587AC: bl      0x80258528
    {
            ctx->lr = 0x802587B0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80258528u;
                return;
            }
            goto label_80258528;
    }

label_802587B0:
    ctx->downcount -= 4;
    // 802587B0: addi    r31, r31, 1
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(1);

label_802587B4:
    // 802587B4: cmpwi   r31, 26
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(26);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802587B8:
    // 802587B8: addi    r30, r30, 16
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(16);

label_802587BC:
    // 802587BC: bc    12, 0, 0x80258794
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80258794u;
                return;
            }
            goto label_80258794;
        }
    }

label_802587C0:
    ctx->pc = 0x802587C0u;
    ctx->downcount -= 10;
    // 802587C0: li      r0, 255
    ctx->gpr[0] = (u32)(s32)(255);

label_802587C4:
    ctx->pc = 0x802587C4u;
    // 802587C4: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802587C8:
    ctx->pc = 0x802587C8u;
    // 802587C8: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802587CC:
    ctx->pc = 0x802587CCu;
    // 802587CC: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802587D0:
    ctx->pc = 0x802587D0u;
    // 802587D0: lwz     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_802587D4:
    ctx->pc = 0x802587D4u;
    // 802587D4: lwz     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_802587D8:
    ctx->pc = 0x802587D8u;
    // 802587D8: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_802587DC:
    ctx->pc = 0x802587DCu;
    // 802587DC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802587E0:
    ctx->pc = 0x802587E0u;
    // 802587E0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_802587E4:
    ctx->pc = 0x802587E4u;
    ctx->downcount -= 2;
    // 802587E4: cmpwi   r3, 25
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(25);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802587E8:
    ctx->pc = 0x802587E8u;
    // 802587E8: bc    4, 2, 0x802587F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802587F0;
        }
    }

label_802587EC:
    ctx->pc = 0x802587ECu;
    ctx->downcount -= 1;
    // 802587EC: li      r3, 10
    ctx->gpr[3] = (u32)(s32)(10);

label_802587F0:
    ctx->pc = 0x802587F0u;
    ctx->downcount -= 10;
    // 802587F0: li      r0, 8
    ctx->gpr[0] = (u32)(s32)(8);

label_802587F4:
    ctx->pc = 0x802587F4u;
    // 802587F4: addi    r6, r3, -9
    ctx->gpr[6] = ctx->gpr[3] + (u32)(s32)(-9);

label_802587F8:
    ctx->pc = 0x802587F8u;
    // 802587F8: lis     r3, -13311
    ctx->gpr[3] = ((u32)(s32)(-13311) << 16);

label_802587FC:
    ctx->pc = 0x802587FCu;
    // 802587FC: stb     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80258800:
    ctx->pc = 0x80258800u;
    // 80258800: ori     r0, r6, 0x00A0
    ctx->gpr[0] = ctx->gpr[6] | 0x00A0u;

label_80258804:
    ctx->pc = 0x80258804u;
    // 80258804: rlwinm r4, r4, 0, 2, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x3FFFFFFFu;
    }

label_80258808:
    ctx->pc = 0x80258808u;
    // 80258808: stb     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8025880C:
    ctx->pc = 0x8025880Cu;
    // 8025880C: addic.  r0, r6, -12
    {
        u64 a = ctx->gpr[6];
        u64 b = (u32)(s32)(-12);
        u64 res = a + b;
        ctx->gpr[0] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80258810:
    ctx->pc = 0x80258810u;
    // 80258810: stw     r4, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80258814:
    ctx->pc = 0x80258814u;
    // 80258814: bc    12, 0, 0x80258830
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80258830;
        }
    }

label_80258818:
    ctx->pc = 0x80258818u;
    ctx->downcount -= 2;
    // 80258818: cmpwi   r0, 4
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

label_8025881C:
    ctx->pc = 0x8025881Cu;
    // 8025881C: bc    4, 0, 0x80258830
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80258830;
        }
    }

label_80258820:
    ctx->pc = 0x80258820u;
    ctx->downcount -= 4;
    // 80258820: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80258824:
    ctx->pc = 0x80258824u;
    // 80258824: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_80258828:
    ctx->pc = 0x80258828u;
    // 80258828: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8025882C:
    ctx->pc = 0x8025882Cu;
    // 8025882C: stw     r4, 136(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(136);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80258830:
    ctx->pc = 0x80258830u;
    ctx->downcount -= 9;
    // 80258830: li      r0, 8
    ctx->gpr[0] = (u32)(s32)(8);

label_80258834:
    ctx->pc = 0x80258834u;
    // 80258834: lis     r3, -13311
    ctx->gpr[3] = ((u32)(s32)(-13311) << 16);

label_80258838:
    ctx->pc = 0x80258838u;
    // 80258838: stb     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8025883C:
    ctx->pc = 0x8025883Cu;
    // 8025883C: ori     r0, r6, 0x00B0
    ctx->gpr[0] = ctx->gpr[6] | 0x00B0u;

label_80258840:
    ctx->pc = 0x80258840u;
    // 80258840: rlwinm r4, r5, 0, 24, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x000000FFu;
    }

label_80258844:
    ctx->pc = 0x80258844u;
    // 80258844: stb     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80258848:
    ctx->pc = 0x80258848u;
    // 80258848: addic.  r0, r6, -12
    {
        u64 a = ctx->gpr[6];
        u64 b = (u32)(s32)(-12);
        u64 res = a + b;
        ctx->gpr[0] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8025884C:
    ctx->pc = 0x8025884Cu;
    // 8025884C: stw     r4, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80258850:
    ctx->pc = 0x80258850u;
    // 80258850: bclr  12, 0
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80258854:
    ctx->pc = 0x80258854u;
    ctx->downcount -= 2;
    // 80258854: cmpwi   r0, 4
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

label_80258858:
    ctx->pc = 0x80258858u;
    // 80258858: bclr  4, 0
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_8025885C:
    ctx->pc = 0x8025885Cu;
    ctx->downcount -= 5;
    // 8025885C: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80258860:
    ctx->pc = 0x80258860u;
    // 80258860: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_80258864:
    ctx->pc = 0x80258864u;
    // 80258864: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80258868:
    ctx->pc = 0x80258868u;
    // 80258868: stw     r4, 152(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(152);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8025886C:
    ctx->pc = 0x8025886Cu;
    // 8025886C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80258870:
    ctx->pc = 0x80258870u;
    ctx->downcount -= 4;
    // 80258870: li      r0, 72
    ctx->gpr[0] = (u32)(s32)(72);

label_80258874:
    ctx->pc = 0x80258874u;
    // 80258874: lis     r3, -13311
    ctx->gpr[3] = ((u32)(s32)(-13311) << 16);

label_80258878:
    ctx->pc = 0x80258878u;
    // 80258878: stb     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8025887C:
    ctx->pc = 0x8025887Cu;
    // 8025887C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80258880:
    ctx->pc = 0x80258880u;
    ctx->downcount -= 8;
    // 80258880: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80258884:
    ctx->pc = 0x80258884u;
    // 80258884: cmplwi  r5, 0x0014
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(0x0014u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80258888:
    ctx->pc = 0x80258888u;
    // 80258888: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8025888C:
    ctx->pc = 0x8025888Cu;
    // 8025888C: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_80258890:
    ctx->pc = 0x80258890u;
    // 80258890: li      r12, 0
    ctx->gpr[12] = (u32)(s32)(0);

label_80258894:
    ctx->pc = 0x80258894u;
    // 80258894: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80258898:
    ctx->pc = 0x80258898u;
    // 80258898: li      r10, 5
    ctx->gpr[10] = (u32)(s32)(5);

label_8025889C:
    ctx->pc = 0x8025889Cu;
    // 8025889C: bc    12, 1, 0x80258934
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80258934;
        }
    }

label_802588A0:
    ctx->pc = 0x802588A0u;
    ctx->downcount -= 7;
    // 802588A0: lis     r9, -32717
    ctx->gpr[9] = ((u32)(s32)(-32717) << 16);

label_802588A4:
    ctx->pc = 0x802588A4u;
    // 802588A4: addi    r9, r9, -160
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-160);

label_802588A8:
    ctx->pc = 0x802588A8u;
    // 802588A8: rlwinm r0, r5, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 2u) & 0xFFFFFFFCu;
    }

label_802588AC:
    ctx->pc = 0x802588ACu;
    // 802588AC: lwzx    r0, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802588B0:
    ctx->pc = 0x802588B0u;
    // 802588B0: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_802588B4:
    ctx->pc = 0x802588B4u;
    // 802588B4: bctr
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            return;
        }
    }

label_802588B8:
    ctx->pc = 0x802588B8u;
    ctx->downcount -= 3;
    // 802588B8: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_802588BC:
    ctx->pc = 0x802588BCu;
    // 802588BC: li      r12, 1
    ctx->gpr[12] = (u32)(s32)(1);

label_802588C0:
    ctx->pc = 0x802588C0u;
    // 802588C0: b       0x80258934
    {
            goto label_80258934;
    }

label_802588C4:
    ctx->pc = 0x802588C4u;
    ctx->downcount -= 3;
    // 802588C4: li      r10, 1
    ctx->gpr[10] = (u32)(s32)(1);

label_802588C8:
    ctx->pc = 0x802588C8u;
    // 802588C8: li      r12, 1
    ctx->gpr[12] = (u32)(s32)(1);

label_802588CC:
    ctx->pc = 0x802588CCu;
    // 802588CC: b       0x80258934
    {
            goto label_80258934;
    }

label_802588D0:
    ctx->pc = 0x802588D0u;
    ctx->downcount -= 3;
    // 802588D0: li      r10, 3
    ctx->gpr[10] = (u32)(s32)(3);

label_802588D4:
    ctx->pc = 0x802588D4u;
    // 802588D4: li      r12, 1
    ctx->gpr[12] = (u32)(s32)(1);

label_802588D8:
    ctx->pc = 0x802588D8u;
    // 802588D8: b       0x80258934
    {
            goto label_80258934;
    }

label_802588DC:
    ctx->pc = 0x802588DCu;
    ctx->downcount -= 3;
    // 802588DC: li      r10, 4
    ctx->gpr[10] = (u32)(s32)(4);

label_802588E0:
    ctx->pc = 0x802588E0u;
    // 802588E0: li      r12, 1
    ctx->gpr[12] = (u32)(s32)(1);

label_802588E4:
    ctx->pc = 0x802588E4u;
    // 802588E4: b       0x80258934
    {
            goto label_80258934;
    }

label_802588E8:
    ctx->pc = 0x802588E8u;
    ctx->downcount -= 2;
    // 802588E8: li      r10, 2
    ctx->gpr[10] = (u32)(s32)(2);

label_802588EC:
    ctx->pc = 0x802588ECu;
    // 802588EC: b       0x80258934
    {
            goto label_80258934;
    }

label_802588F0:
    ctx->pc = 0x802588F0u;
    ctx->downcount -= 2;
    // 802588F0: li      r10, 2
    ctx->gpr[10] = (u32)(s32)(2);

label_802588F4:
    ctx->pc = 0x802588F4u;
    // 802588F4: b       0x80258934
    {
            goto label_80258934;
    }

label_802588F8:
    ctx->pc = 0x802588F8u;
    ctx->downcount -= 2;
    // 802588F8: li      r10, 5
    ctx->gpr[10] = (u32)(s32)(5);

label_802588FC:
    ctx->pc = 0x802588FCu;
    // 802588FC: b       0x80258934
    {
            goto label_80258934;
    }

label_80258900:
    ctx->pc = 0x80258900u;
    ctx->downcount -= 2;
    // 80258900: li      r10, 6
    ctx->gpr[10] = (u32)(s32)(6);

label_80258904:
    ctx->pc = 0x80258904u;
    // 80258904: b       0x80258934
    {
            goto label_80258934;
    }

label_80258908:
    ctx->pc = 0x80258908u;
    ctx->downcount -= 2;
    // 80258908: li      r10, 7
    ctx->gpr[10] = (u32)(s32)(7);

label_8025890C:
    ctx->pc = 0x8025890Cu;
    // 8025890C: b       0x80258934
    {
            goto label_80258934;
    }

label_80258910:
    ctx->pc = 0x80258910u;
    ctx->downcount -= 2;
    // 80258910: li      r10, 8
    ctx->gpr[10] = (u32)(s32)(8);

label_80258914:
    ctx->pc = 0x80258914u;
    // 80258914: b       0x80258934
    {
            goto label_80258934;
    }

label_80258918:
    ctx->pc = 0x80258918u;
    ctx->downcount -= 2;
    // 80258918: li      r10, 9
    ctx->gpr[10] = (u32)(s32)(9);

label_8025891C:
    ctx->pc = 0x8025891Cu;
    // 8025891C: b       0x80258934
    {
            goto label_80258934;
    }

label_80258920:
    ctx->pc = 0x80258920u;
    ctx->downcount -= 2;
    // 80258920: li      r10, 10
    ctx->gpr[10] = (u32)(s32)(10);

label_80258924:
    ctx->pc = 0x80258924u;
    // 80258924: b       0x80258934
    {
            goto label_80258934;
    }

label_80258928:
    ctx->pc = 0x80258928u;
    ctx->downcount -= 2;
    // 80258928: li      r10, 11
    ctx->gpr[10] = (u32)(s32)(11);

label_8025892C:
    ctx->pc = 0x8025892Cu;
    // 8025892C: b       0x80258934
    {
            goto label_80258934;
    }

label_80258930:
    ctx->pc = 0x80258930u;
    ctx->downcount -= 1;
    // 80258930: li      r10, 12
    ctx->gpr[10] = (u32)(s32)(12);

label_80258934:
    ctx->pc = 0x80258934u;
    ctx->downcount -= 2;
    // 80258934: cmpwi   r4, 1
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80258938:
    ctx->pc = 0x80258938u;
    // 80258938: bc    12, 2, 0x8025895C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8025895C;
        }
    }

label_8025893C:
    ctx->pc = 0x8025893Cu;
    ctx->downcount -= 1;
    // 8025893C: bc    4, 0, 0x8025894C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8025894C;
        }
    }

label_80258940:
    ctx->pc = 0x80258940u;
    ctx->downcount -= 2;
    // 80258940: cmpwi   r4, 0
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

label_80258944:
    ctx->pc = 0x80258944u;
    // 80258944: bc    4, 0, 0x80258970
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80258970;
        }
    }

label_80258948:
    ctx->pc = 0x80258948u;
    ctx->downcount -= 1;
    // 80258948: b       0x802589EC
    {
            goto label_802589EC;
    }

label_8025894C:
    ctx->pc = 0x8025894Cu;
    ctx->downcount -= 2;
    // 8025894C: cmpwi   r4, 10
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(10);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80258950:
    ctx->pc = 0x80258950u;
    // 80258950: bc    12, 2, 0x802589C4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802589C4;
        }
    }

label_80258954:
    ctx->pc = 0x80258954u;
    ctx->downcount -= 1;
    // 80258954: bc    4, 0, 0x802589EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802589EC;
        }
    }

label_80258958:
    ctx->pc = 0x80258958u;
    ctx->downcount -= 1;
    // 80258958: b       0x80258988
    {
            goto label_80258988;
    }

label_8025895C:
    ctx->pc = 0x8025895Cu;
    ctx->downcount -= 5;
    // 8025895C: rlwinm r0, r12, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[12], 2u) & 0xFFFFFFFCu;
    }

label_80258960:
    ctx->pc = 0x80258960u;
    // 80258960: rlwinm r4, r0, 0, 28, 19
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFF00Fu;
    }

label_80258964:
    ctx->pc = 0x80258964u;
    // 80258964: rlwinm r0, r10, 7, 0, 24
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[10], 7u) & 0xFFFFFF80u;
    }

label_80258968:
    ctx->pc = 0x80258968u;
    // 80258968: or   r11, r4, r0
    {
        ctx->gpr[11] = ctx->gpr[4] | ctx->gpr[0];
    }

label_8025896C:
    ctx->pc = 0x8025896Cu;
    // 8025896C: b       0x802589EC
    {
            goto label_802589EC;
    }

label_80258970:
    ctx->pc = 0x80258970u;
    ctx->downcount -= 6;
    // 80258970: rlwinm r0, r12, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[12], 2u) & 0xFFFFFFFCu;
    }

label_80258974:
    ctx->pc = 0x80258974u;
    // 80258974: ori     r0, r0, 0x0002
    ctx->gpr[0] = ctx->gpr[0] | 0x0002u;

label_80258978:
    ctx->pc = 0x80258978u;
    // 80258978: rlwinm r4, r0, 0, 28, 19
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFF00Fu;
    }

label_8025897C:
    ctx->pc = 0x8025897Cu;
    // 8025897C: rlwinm r0, r10, 7, 0, 24
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[10], 7u) & 0xFFFFFF80u;
    }

label_80258980:
    ctx->pc = 0x80258980u;
    // 80258980: or   r11, r4, r0
    {
        ctx->gpr[11] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80258984:
    ctx->pc = 0x80258984u;
    // 80258984: b       0x802589EC
    {
            goto label_802589EC;
    }

label_80258988:
    ctx->pc = 0x80258988u;
    ctx->downcount -= 15;
    // 80258988: rlwinm r0, r12, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[12], 2u) & 0xFFFFFFFCu;
    }

label_8025898C:
    ctx->pc = 0x8025898Cu;
    // 8025898C: rlwinm r0, r0, 0, 28, 24
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFF8Fu;
    }

label_80258990:
    ctx->pc = 0x80258990u;
    // 80258990: ori     r0, r0, 0x0010
    ctx->gpr[0] = ctx->gpr[0] | 0x0010u;

label_80258994:
    ctx->pc = 0x80258994u;
    // 80258994: rlwinm r9, r0, 0, 25, 19
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFF07Fu;
    }

label_80258998:
    ctx->pc = 0x80258998u;
    // 80258998: rlwinm r0, r10, 7, 0, 24
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[10], 7u) & 0xFFFFFF80u;
    }

label_8025899C:
    ctx->pc = 0x8025899Cu;
    // 8025899C: or   r9, r9, r0
    {
        ctx->gpr[9] = ctx->gpr[9] | ctx->gpr[0];
    }

label_802589A0:
    ctx->pc = 0x802589A0u;
    // 802589A0: addi    r5, r5, -12
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(-12);

label_802589A4:
    ctx->pc = 0x802589A4u;
    // 802589A4: addi    r0, r4, -2
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(-2);

label_802589A8:
    ctx->pc = 0x802589A8u;
    // 802589A8: rlwinm r9, r9, 0, 20, 16
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 0u) & 0xFFFF8FFFu;
    }

label_802589AC:
    ctx->pc = 0x802589ACu;
    // 802589AC: rlwinm r4, r5, 12, 0, 19
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[5], 12u) & 0xFFFFF000u;
    }

label_802589B0:
    ctx->pc = 0x802589B0u;
    // 802589B0: or   r4, r9, r4
    {
        ctx->gpr[4] = ctx->gpr[9] | ctx->gpr[4];
    }

label_802589B4:
    ctx->pc = 0x802589B4u;
    // 802589B4: rlwinm r4, r4, 0, 17, 13
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFC7FFFu;
    }

label_802589B8:
    ctx->pc = 0x802589B8u;
    // 802589B8: rlwinm r0, r0, 15, 0, 16
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 15u) & 0xFFFF8000u;
    }

label_802589BC:
    ctx->pc = 0x802589BCu;
    // 802589BC: or   r11, r4, r0
    {
        ctx->gpr[11] = ctx->gpr[4] | ctx->gpr[0];
    }

label_802589C0:
    ctx->pc = 0x802589C0u;
    // 802589C0: b       0x802589EC
    {
            goto label_802589EC;
    }

label_802589C4:
    ctx->pc = 0x802589C4u;
    ctx->downcount -= 3;
    // 802589C4: cmpwi   r5, 19
    {
        s32 val_a = (s32)(ctx->gpr[5]);
        s32 val_b = (s32)(19);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802589C8:
    ctx->pc = 0x802589C8u;
    // 802589C8: rlwinm r0, r12, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[12], 2u) & 0xFFFFFFFCu;
    }

label_802589CC:
    ctx->pc = 0x802589CCu;
    // 802589CC: bc    4, 2, 0x802589DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802589DC;
        }
    }

label_802589D0:
    ctx->pc = 0x802589D0u;
    ctx->downcount -= 3;
    // 802589D0: rlwinm r0, r0, 0, 28, 24
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFF8Fu;
    }

label_802589D4:
    ctx->pc = 0x802589D4u;
    // 802589D4: ori     r0, r0, 0x0020
    ctx->gpr[0] = ctx->gpr[0] | 0x0020u;

label_802589D8:
    ctx->pc = 0x802589D8u;
    // 802589D8: b       0x802589E4
    {
            goto label_802589E4;
    }

label_802589DC:
    ctx->pc = 0x802589DCu;
    ctx->downcount -= 2;
    // 802589DC: rlwinm r0, r0, 0, 28, 24
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFF8Fu;
    }

label_802589E0:
    ctx->pc = 0x802589E0u;
    // 802589E0: ori     r0, r0, 0x0030
    ctx->gpr[0] = ctx->gpr[0] | 0x0030u;

label_802589E4:
    ctx->pc = 0x802589E4u;
    ctx->downcount -= 2;
    // 802589E4: rlwinm r0, r0, 0, 25, 19
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFF07Fu;
    }

label_802589E8:
    ctx->pc = 0x802589E8u;
    // 802589E8: ori     r11, r0, 0x0100
    ctx->gpr[11] = ctx->gpr[0] | 0x0100u;

label_802589EC:
    ctx->pc = 0x802589ECu;
    ctx->downcount -= 16;
    // 802589EC: li      r10, 16
    ctx->gpr[10] = (u32)(s32)(16);

label_802589F0:
    ctx->pc = 0x802589F0u;
    // 802589F0: lis     r9, -13311
    ctx->gpr[9] = ((u32)(s32)(-13311) << 16);

label_802589F4:
    ctx->pc = 0x802589F4u;
    // 802589F4: stb     r10, -32768(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[10]);
    }

label_802589F8:
    ctx->pc = 0x802589F8u;
    // 802589F8: addi    r0, r3, 4160
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(4160);

label_802589FC:
    ctx->pc = 0x802589FCu;
    // 802589FC: addi    r4, r8, -64
    ctx->gpr[4] = ctx->gpr[8] + (u32)(s32)(-64);

label_80258A00:
    ctx->pc = 0x80258A00u;
    // 80258A00: stw     r0, -32768(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258A04:
    ctx->pc = 0x80258A04u;
    // 80258A04: rlwinm r5, r4, 0, 24, 22
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFEFFu;
    }

label_80258A08:
    ctx->pc = 0x80258A08u;
    // 80258A08: rlwinm r4, r7, 8, 16, 23
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[7], 8u) & 0x0000FF00u;
    }

label_80258A0C:
    ctx->pc = 0x80258A0Cu;
    // 80258A0C: stw     r11, -32768(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80258A10:
    ctx->pc = 0x80258A10u;
    // 80258A10: addi    r0, r3, 4176
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(4176);

label_80258A14:
    ctx->pc = 0x80258A14u;
    // 80258A14: cmplwi  r3, 0x0006
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0006u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80258A18:
    ctx->pc = 0x80258A18u;
    // 80258A18: stb     r10, -32768(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[10]);
    }

label_80258A1C:
    ctx->pc = 0x80258A1Cu;
    // 80258A1C: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_80258A20:
    ctx->pc = 0x80258A20u;
    // 80258A20: stw     r0, -32768(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258A24:
    ctx->pc = 0x80258A24u;
    // 80258A24: stw     r4, -32768(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80258A28:
    ctx->pc = 0x80258A28u;
    // 80258A28: bc    12, 1, 0x80258B1C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80258B1C;
        }
    }

label_80258A2C:
    ctx->pc = 0x80258A2Cu;
    ctx->downcount -= 7;
    // 80258A2C: lis     r4, -32717
    ctx->gpr[4] = ((u32)(s32)(-32717) << 16);

label_80258A30:
    ctx->pc = 0x80258A30u;
    // 80258A30: addi    r4, r4, -188
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-188);

label_80258A34:
    ctx->pc = 0x80258A34u;
    // 80258A34: rlwinm r0, r3, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0xFFFFFFFCu;
    }

label_80258A38:
    ctx->pc = 0x80258A38u;
    // 80258A38: lwzx    r0, r4, r0
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80258A3C:
    ctx->pc = 0x80258A3Cu;
    // 80258A3C: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_80258A40:
    ctx->pc = 0x80258A40u;
    // 80258A40: bctr
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            return;
        }
    }

label_80258A44:
    ctx->pc = 0x80258A44u;
    ctx->downcount -= 8;
    // 80258A44: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80258A48:
    ctx->pc = 0x80258A48u;
    // 80258A48: rlwinm r0, r6, 6, 0, 25
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 6u) & 0xFFFFFFC0u;
    }

label_80258A4C:
    ctx->pc = 0x80258A4Cu;
    // 80258A4C: addi    r5, r4, 128
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(128);

label_80258A50:
    ctx->pc = 0x80258A50u;
    // 80258A50: lwz     r4, 128(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(128);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80258A54:
    ctx->pc = 0x80258A54u;
    // 80258A54: rlwinm r4, r4, 0, 26, 19
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFF03Fu;
    }

label_80258A58:
    ctx->pc = 0x80258A58u;
    // 80258A58: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80258A5C:
    ctx->pc = 0x80258A5Cu;
    // 80258A5C: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258A60:
    ctx->pc = 0x80258A60u;
    // 80258A60: b       0x80258B38
    {
            goto label_80258B38;
    }

label_80258A64:
    ctx->pc = 0x80258A64u;
    ctx->downcount -= 8;
    // 80258A64: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80258A68:
    ctx->pc = 0x80258A68u;
    // 80258A68: rlwinm r0, r6, 12, 0, 19
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 12u) & 0xFFFFF000u;
    }

label_80258A6C:
    ctx->pc = 0x80258A6Cu;
    // 80258A6C: addi    r5, r4, 128
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(128);

label_80258A70:
    ctx->pc = 0x80258A70u;
    // 80258A70: lwz     r4, 128(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(128);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80258A74:
    ctx->pc = 0x80258A74u;
    // 80258A74: rlwinm r4, r4, 0, 20, 13
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFC0FFFu;
    }

label_80258A78:
    ctx->pc = 0x80258A78u;
    // 80258A78: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80258A7C:
    ctx->pc = 0x80258A7Cu;
    // 80258A7C: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258A80:
    ctx->pc = 0x80258A80u;
    // 80258A80: b       0x80258B38
    {
            goto label_80258B38;
    }

label_80258A84:
    ctx->pc = 0x80258A84u;
    ctx->downcount -= 8;
    // 80258A84: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80258A88:
    ctx->pc = 0x80258A88u;
    // 80258A88: rlwinm r0, r6, 18, 0, 13
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 18u) & 0xFFFC0000u;
    }

label_80258A8C:
    ctx->pc = 0x80258A8Cu;
    // 80258A8C: addi    r5, r4, 128
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(128);

label_80258A90:
    ctx->pc = 0x80258A90u;
    // 80258A90: lwz     r4, 128(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(128);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80258A94:
    ctx->pc = 0x80258A94u;
    // 80258A94: rlwinm r4, r4, 0, 14, 7
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFF03FFFFu;
    }

label_80258A98:
    ctx->pc = 0x80258A98u;
    // 80258A98: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80258A9C:
    ctx->pc = 0x80258A9Cu;
    // 80258A9C: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258AA0:
    ctx->pc = 0x80258AA0u;
    // 80258AA0: b       0x80258B38
    {
            goto label_80258B38;
    }

label_80258AA4:
    ctx->pc = 0x80258AA4u;
    ctx->downcount -= 8;
    // 80258AA4: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80258AA8:
    ctx->pc = 0x80258AA8u;
    // 80258AA8: rlwinm r0, r6, 24, 0, 7
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 24u) & 0xFF000000u;
    }

label_80258AAC:
    ctx->pc = 0x80258AACu;
    // 80258AAC: addi    r5, r4, 128
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(128);

label_80258AB0:
    ctx->pc = 0x80258AB0u;
    // 80258AB0: lwz     r4, 128(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(128);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80258AB4:
    ctx->pc = 0x80258AB4u;
    // 80258AB4: rlwinm r4, r4, 0, 8, 1
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xC0FFFFFFu;
    }

label_80258AB8:
    ctx->pc = 0x80258AB8u;
    // 80258AB8: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80258ABC:
    ctx->pc = 0x80258ABCu;
    // 80258ABC: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258AC0:
    ctx->pc = 0x80258AC0u;
    // 80258AC0: b       0x80258B38
    {
            goto label_80258B38;
    }

label_80258AC4:
    ctx->pc = 0x80258AC4u;
    ctx->downcount -= 6;
    // 80258AC4: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80258AC8:
    ctx->pc = 0x80258AC8u;
    // 80258AC8: lwzu     r0, 132(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(132);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_80258ACC:
    ctx->pc = 0x80258ACCu;
    // 80258ACC: rlwinm r0, r0, 0, 0, 25
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFC0u;
    }

label_80258AD0:
    ctx->pc = 0x80258AD0u;
    // 80258AD0: or   r0, r0, r6
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[6];
    }

label_80258AD4:
    ctx->pc = 0x80258AD4u;
    // 80258AD4: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258AD8:
    ctx->pc = 0x80258AD8u;
    // 80258AD8: b       0x80258B38
    {
            goto label_80258B38;
    }

label_80258ADC:
    ctx->pc = 0x80258ADCu;
    ctx->downcount -= 8;
    // 80258ADC: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80258AE0:
    ctx->pc = 0x80258AE0u;
    // 80258AE0: rlwinm r0, r6, 6, 0, 25
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 6u) & 0xFFFFFFC0u;
    }

label_80258AE4:
    ctx->pc = 0x80258AE4u;
    // 80258AE4: addi    r5, r4, 132
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(132);

label_80258AE8:
    ctx->pc = 0x80258AE8u;
    // 80258AE8: lwz     r4, 132(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(132);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80258AEC:
    ctx->pc = 0x80258AECu;
    // 80258AEC: rlwinm r4, r4, 0, 26, 19
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFF03Fu;
    }

label_80258AF0:
    ctx->pc = 0x80258AF0u;
    // 80258AF0: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80258AF4:
    ctx->pc = 0x80258AF4u;
    // 80258AF4: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258AF8:
    ctx->pc = 0x80258AF8u;
    // 80258AF8: b       0x80258B38
    {
            goto label_80258B38;
    }

label_80258AFC:
    ctx->pc = 0x80258AFCu;
    ctx->downcount -= 8;
    // 80258AFC: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80258B00:
    ctx->pc = 0x80258B00u;
    // 80258B00: rlwinm r0, r6, 12, 0, 19
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 12u) & 0xFFFFF000u;
    }

label_80258B04:
    ctx->pc = 0x80258B04u;
    // 80258B04: addi    r5, r4, 132
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(132);

label_80258B08:
    ctx->pc = 0x80258B08u;
    // 80258B08: lwz     r4, 132(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(132);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80258B0C:
    ctx->pc = 0x80258B0Cu;
    // 80258B0C: rlwinm r4, r4, 0, 20, 13
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFC0FFFu;
    }

label_80258B10:
    ctx->pc = 0x80258B10u;
    // 80258B10: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80258B14:
    ctx->pc = 0x80258B14u;
    // 80258B14: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258B18:
    ctx->pc = 0x80258B18u;
    // 80258B18: b       0x80258B38
    {
            goto label_80258B38;
    }

label_80258B1C:
    ctx->pc = 0x80258B1Cu;
    ctx->downcount -= 7;
    // 80258B1C: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80258B20:
    ctx->pc = 0x80258B20u;
    // 80258B20: rlwinm r0, r6, 18, 0, 13
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 18u) & 0xFFFC0000u;
    }

label_80258B24:
    ctx->pc = 0x80258B24u;
    // 80258B24: addi    r5, r4, 132
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(132);

label_80258B28:
    ctx->pc = 0x80258B28u;
    // 80258B28: lwz     r4, 132(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(132);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80258B2C:
    ctx->pc = 0x80258B2Cu;
    // 80258B2C: rlwinm r4, r4, 0, 14, 7
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFF03FFFFu;
    }

label_80258B30:
    ctx->pc = 0x80258B30u;
    // 80258B30: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80258B34:
    ctx->pc = 0x80258B34u;
    // 80258B34: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258B38:
    ctx->pc = 0x80258B38u;
    ctx->downcount -= 2;
    // 80258B38: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_80258B3C:
    ctx->pc = 0x80258B3Cu;
    // 80258B3C: bl      0x8025DE00
    {
            ctx->lr = 0x80258B40u;
            ctx->pc = 0x8025DE00u;
            return;
    }

label_80258B40:
    ctx->pc = 0x80258B40u;
    ctx->downcount -= 5;
    // 80258B40: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80258B44:
    ctx->pc = 0x80258B44u;
    // 80258B44: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80258B48:
    ctx->pc = 0x80258B48u;
    // 80258B48: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80258B4C:
    ctx->pc = 0x80258B4Cu;
    // 80258B4C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80258B50:
    ctx->pc = 0x80258B50u;
    ctx->downcount -= 18;
    // 80258B50: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80258B54:
    ctx->pc = 0x80258B54u;
    // 80258B54: rlwinm r7, r3, 0, 24, 31
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000000FFu;
    }

label_80258B58:
    ctx->pc = 0x80258B58u;
    // 80258B58: li      r3, 16
    ctx->gpr[3] = (u32)(s32)(16);

label_80258B5C:
    ctx->pc = 0x80258B5Cu;
    // 80258B5C: addi    r6, r4, 516
    ctx->gpr[6] = ctx->gpr[4] + (u32)(s32)(516);

label_80258B60:
    ctx->pc = 0x80258B60u;
    // 80258B60: lwz     r5, 516(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(516);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80258B64:
    ctx->pc = 0x80258B64u;
    // 80258B64: lis     r4, -13311
    ctx->gpr[4] = ((u32)(s32)(-13311) << 16);

label_80258B68:
    ctx->pc = 0x80258B68u;
    // 80258B68: li      r0, 4159
    ctx->gpr[0] = (u32)(s32)(4159);

label_80258B6C:
    ctx->pc = 0x80258B6Cu;
    // 80258B6C: rlwinm r5, r5, 0, 0, 27
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFF0u;
    }

label_80258B70:
    ctx->pc = 0x80258B70u;
    // 80258B70: or   r5, r5, r7
    {
        ctx->gpr[5] = ctx->gpr[5] | ctx->gpr[7];
    }

label_80258B74:
    ctx->pc = 0x80258B74u;
    // 80258B74: stw     r5, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80258B78:
    ctx->pc = 0x80258B78u;
    // 80258B78: stb     r3, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_80258B7C:
    ctx->pc = 0x80258B7Cu;
    // 80258B7C: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80258B80:
    ctx->pc = 0x80258B80u;
    // 80258B80: stw     r0, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258B84:
    ctx->pc = 0x80258B84u;
    // 80258B84: stw     r7, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80258B88:
    ctx->pc = 0x80258B88u;
    // 80258B88: lwz     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80258B8C:
    ctx->pc = 0x80258B8Cu;
    // 80258B8C: ori     r0, r0, 0x0004
    ctx->gpr[0] = ctx->gpr[0] | 0x0004u;

label_80258B90:
    ctx->pc = 0x80258B90u;
    // 80258B90: stw     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258B94:
    ctx->pc = 0x80258B94u;
    // 80258B94: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80258B98:
    ctx->pc = 0x80258B98u;
    ctx->downcount -= 2;
    // 80258B98: cmpwi   r3, 1
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

label_80258B9C:
    ctx->pc = 0x80258B9Cu;
    // 80258B9C: bc    12, 2, 0x80258BB0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80258BB0;
        }
    }

label_80258BA0:
    ctx->pc = 0x80258BA0u;
    ctx->downcount -= 1;
    // 80258BA0: bclr  12, 0
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80258BA4:
    ctx->pc = 0x80258BA4u;
    ctx->downcount -= 2;
    // 80258BA4: cmpwi   r3, 3
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80258BA8:
    ctx->pc = 0x80258BA8u;
    // 80258BA8: bclr  4, 0
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80258BAC:
    ctx->pc = 0x80258BACu;
    ctx->downcount -= 1;
    // 80258BAC: b       0x80258BF8
    {
            goto label_80258BF8;
    }

label_80258BB0:
    ctx->pc = 0x80258BB0u;
    ctx->downcount -= 14;
    // 80258BB0: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80258BB4:
    ctx->pc = 0x80258BB4u;
    // 80258BB4: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80258BB8:
    ctx->pc = 0x80258BB8u;
    // 80258BB8: sth     r4, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_80258BBC:
    ctx->pc = 0x80258BBCu;
    // 80258BBC: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80258BC0:
    ctx->pc = 0x80258BC0u;
    // 80258BC0: lhz     r3, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_80258BC4:
    ctx->pc = 0x80258BC4u;
    // 80258BC4: cntlzw r3, r3
    {
        u32 v = ctx->gpr[3];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[3] = n;
    }

label_80258BC8:
    ctx->pc = 0x80258BC8u;
    // 80258BC8: rlwinm r3, r3, 27, 16, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 27u) & 0x0000FFFFu;
    }

label_80258BCC:
    ctx->pc = 0x80258BCCu;
    // 80258BCC: sth     r3, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_80258BD0:
    ctx->pc = 0x80258BD0u;
    // 80258BD0: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80258BD4:
    ctx->pc = 0x80258BD4u;
    // 80258BD4: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80258BD8:
    ctx->pc = 0x80258BD8u;
    // 80258BD8: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80258BDC:
    ctx->pc = 0x80258BDCu;
    // 80258BDC: lhz     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80258BE0:
    ctx->pc = 0x80258BE0u;
    // 80258BE0: cmplwi  r0, 0x0000
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

label_80258BE4:
    ctx->pc = 0x80258BE4u;
    // 80258BE4: bclr  12, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80258BE8:
    ctx->pc = 0x80258BE8u;
    ctx->downcount -= 4;
    // 80258BE8: lwz     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80258BEC:
    ctx->pc = 0x80258BECu;
    // 80258BEC: ori     r0, r0, 0x0008
    ctx->gpr[0] = ctx->gpr[0] | 0x0008u;

label_80258BF0:
    ctx->pc = 0x80258BF0u;
    // 80258BF0: stw     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258BF4:
    ctx->pc = 0x80258BF4u;
    // 80258BF4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80258BF8:
    ctx->pc = 0x80258BF8u;
    ctx->downcount -= 6;
    // 80258BF8: neg  r4, r4
    {
        u32 a = ctx->gpr[4];
        ctx->gpr[4] = (~a) + 1u;
    }

label_80258BFC:
    ctx->pc = 0x80258BFCu;
    // 80258BFC: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80258C00:
    ctx->pc = 0x80258C00u;
    // 80258C00: addic   r0, r4, -1
    {
        u64 a = ctx->gpr[4];
        u64 b = (u32)(s32)(-1);
        u64 res = a + b;
        ctx->gpr[0] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_80258C04:
    ctx->pc = 0x80258C04u;
    // 80258C04: subfe   r0, r0, r4
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[4];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80258C08:
    ctx->pc = 0x80258C08u;
    // 80258C08: stb     r0, 1265(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1265);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80258C0C:
    ctx->pc = 0x80258C0Cu;
    // 80258C0C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80258C10:
    ctx->pc = 0x80258C10u;
    ctx->downcount -= 7;
    // 80258C10: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80258C14:
    ctx->pc = 0x80258C14u;
    // 80258C14: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258C18:
    ctx->pc = 0x80258C18u;
    // 80258C18: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80258C1C:
    ctx->pc = 0x80258C1Cu;
    // 80258C1C: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80258C20:
    ctx->pc = 0x80258C20u;
    // 80258C20: lwz     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80258C24:
    ctx->pc = 0x80258C24u;
    // 80258C24: cmplwi  r0, 0x0000
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

label_80258C28:
    ctx->pc = 0x80258C28u;
    // 80258C28: bc    12, 2, 0x80258C30
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80258C30;
        }
    }

label_80258C2C:
    ctx->pc = 0x80258C2Cu;
    ctx->downcount -= 1;
    // 80258C2C: bl      0x8025916C
    {
            ctx->lr = 0x80258C30u;
            goto label_8025916C;
    }

label_80258C30:
    ctx->pc = 0x80258C30u;
    ctx->downcount -= 11;
    // 80258C30: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80258C34:
    ctx->pc = 0x80258C34u;
    // 80258C34: lis     r3, -13311
    ctx->gpr[3] = ((u32)(s32)(-13311) << 16);

label_80258C38:
    ctx->pc = 0x80258C38u;
    // 80258C38: stw     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258C3C:
    ctx->pc = 0x80258C3Cu;
    // 80258C3C: stw     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258C40:
    ctx->pc = 0x80258C40u;
    // 80258C40: stw     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258C44:
    ctx->pc = 0x80258C44u;
    // 80258C44: stw     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258C48:
    ctx->pc = 0x80258C48u;
    // 80258C48: stw     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258C4C:
    ctx->pc = 0x80258C4Cu;
    // 80258C4C: stw     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258C50:
    ctx->pc = 0x80258C50u;
    // 80258C50: stw     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258C54:
    ctx->pc = 0x80258C54u;
    // 80258C54: stw     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258C58:
    ctx->pc = 0x80258C58u;
    // 80258C58: bl      0x80240CBC
    {
            ctx->lr = 0x80258C5Cu;
            ctx->pc = 0x80240CBCu;
            return;
    }

label_80258C5C:
    ctx->pc = 0x80258C5Cu;
    ctx->downcount -= 5;
    // 80258C5C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80258C60:
    ctx->pc = 0x80258C60u;
    // 80258C60: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80258C64:
    ctx->pc = 0x80258C64u;
    // 80258C64: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80258C68:
    ctx->pc = 0x80258C68u;
    // 80258C68: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80258C6C:
    ctx->pc = 0x80258C6Cu;
    ctx->downcount -= 3;
    // 80258C6C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80258C70:
    ctx->pc = 0x80258C70u;
    // 80258C70: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258C74:
    ctx->pc = 0x80258C74u;
    // 80258C74: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80258C78:
    ctx->downcount -= 1;
    // 80258C78: bl      0x80240CD4
    {
            ctx->lr = 0x80258C7Cu;
            ctx->pc = 0x80240CD4u;
            return;
    }

label_80258C7C:
    ctx->downcount -= 2;
    // 80258C7C: rlwinm. r0, r3, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80258C80:
    // 80258C80: bc    4, 2, 0x80258C78
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80258C78u;
                return;
            }
            goto label_80258C78;
        }
    }

label_80258C84:
    ctx->pc = 0x80258C84u;
    ctx->downcount -= 3;
    // 80258C84: lis     r3, 3073
    ctx->gpr[3] = ((u32)(s32)(3073) << 16);

label_80258C88:
    ctx->pc = 0x80258C88u;
    // 80258C88: addi    r3, r3, -32768
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-32768);

label_80258C8C:
    ctx->pc = 0x80258C8Cu;
    // 80258C8C: bl      0x80240CE0
    {
            ctx->lr = 0x80258C90u;
            ctx->pc = 0x80240CE0u;
            return;
    }

label_80258C90:
    ctx->pc = 0x80258C90u;
    ctx->downcount -= 5;
    // 80258C90: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80258C94:
    ctx->pc = 0x80258C94u;
    // 80258C94: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80258C98:
    ctx->pc = 0x80258C98u;
    // 80258C98: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80258C9C:
    ctx->pc = 0x80258C9Cu;
    // 80258C9C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80258CA0:
    ctx->pc = 0x80258CA0u;
    ctx->downcount -= 11;
    // 80258CA0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80258CA4:
    ctx->pc = 0x80258CA4u;
    // 80258CA4: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258CA8:
    ctx->pc = 0x80258CA8u;
    // 80258CA8: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80258CAC:
    ctx->pc = 0x80258CACu;
    // 80258CAC: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80258CB0:
    ctx->pc = 0x80258CB0u;
    // 80258CB0: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80258CB4:
    ctx->pc = 0x80258CB4u;
    // 80258CB4: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80258CB8:
    ctx->pc = 0x80258CB8u;
    // 80258CB8: stw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80258CBC:
    ctx->pc = 0x80258CBCu;
    // 80258CBC: stw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_80258CC0:
    ctx->pc = 0x80258CC0u;
    // 80258CC0: lwz     r3, -20704(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20704);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80258CC4:
    ctx->pc = 0x80258CC4u;
    // 80258CC4: stw     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258CC8:
    ctx->pc = 0x80258CC8u;
    // 80258CC8: bl      0x802475FC
    {
            ctx->lr = 0x80258CCCu;
            ctx->pc = 0x802475FCu;
            return;
    }

label_80258CCC:
    ctx->pc = 0x80258CCCu;
    ctx->downcount -= 5;
    // 80258CCC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80258CD0:
    ctx->pc = 0x80258CD0u;
    // 80258CD0: addi    r31, r4, 0
    ctx->gpr[31] = ctx->gpr[4] + (u32)(s32)(0);

label_80258CD4:
    ctx->pc = 0x80258CD4u;
    // 80258CD4: addi    r30, r3, 0
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(0);

label_80258CD8:
    ctx->pc = 0x80258CD8u;
    // 80258CD8: xoris   r28, r0, 0x8000
    ctx->gpr[28] = ctx->gpr[0] ^ (0x8000u << 16);

label_80258CDC:
    ctx->pc = 0x80258CDCu;
    // 80258CDC: li      r29, 50
    ctx->gpr[29] = (u32)(s32)(50);

label_80258CE0:
    ctx->downcount -= 1;
    // 80258CE0: bl      0x802475FC
    {
            ctx->lr = 0x80258CE4u;
            ctx->pc = 0x802475FCu;
            return;
    }

label_80258CE4:
    ctx->downcount -= 8;
    // 80258CE4: subfc   r4, r31, r4
    {
        u32 a = ~ctx->gpr[31];
        u32 b = ctx->gpr[4];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[4] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80258CE8:
    // 80258CE8: subfe   r0, r30, r3
    {
        u32 a = ~ctx->gpr[30];
        u32 b = ctx->gpr[3];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80258CEC:
    // 80258CEC: xoris   r3, r0, 0x8000
    ctx->gpr[3] = ctx->gpr[0] ^ (0x8000u << 16);

label_80258CF0:
    // 80258CF0: subfc   r0, r4, r29
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[29];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80258CF4:
    // 80258CF4: subfe   r3, r3, r28
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[28];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80258CF8:
    // 80258CF8: subfe   r3, r28, r28
    {
        u32 a = ~ctx->gpr[28];
        u32 b = ctx->gpr[28];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80258CFC:
    // 80258CFC: neg.  r3, r3
    {
        u32 a = ctx->gpr[3];
        ctx->gpr[3] = (~a) + 1u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[3];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80258D00:
    // 80258D00: bc    12, 2, 0x80258CE0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80258CE0u;
                return;
            }
            goto label_80258CE0;
        }
    }

label_80258D04:
    ctx->pc = 0x80258D04u;
    ctx->downcount -= 4;
    // 80258D04: lwz     r3, -20704(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20704);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80258D08:
    ctx->pc = 0x80258D08u;
    // 80258D08: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_80258D0C:
    ctx->pc = 0x80258D0Cu;
    // 80258D0C: stw     r30, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80258D10:
    ctx->pc = 0x80258D10u;
    // 80258D10: bl      0x802475FC
    {
            ctx->lr = 0x80258D14u;
            ctx->pc = 0x802475FCu;
            return;
    }

label_80258D14:
    ctx->pc = 0x80258D14u;
    ctx->downcount -= 4;
    // 80258D14: addi    r28, r4, 0
    ctx->gpr[28] = ctx->gpr[4] + (u32)(s32)(0);

label_80258D18:
    ctx->pc = 0x80258D18u;
    // 80258D18: addi    r29, r3, 0
    ctx->gpr[29] = ctx->gpr[3] + (u32)(s32)(0);

label_80258D1C:
    ctx->pc = 0x80258D1Cu;
    // 80258D1C: xoris   r31, r30, 0x8000
    ctx->gpr[31] = ctx->gpr[30] ^ (0x8000u << 16);

label_80258D20:
    ctx->pc = 0x80258D20u;
    // 80258D20: li      r30, 5
    ctx->gpr[30] = (u32)(s32)(5);

label_80258D24:
    ctx->downcount -= 1;
    // 80258D24: bl      0x802475FC
    {
            ctx->lr = 0x80258D28u;
            ctx->pc = 0x802475FCu;
            return;
    }

label_80258D28:
    ctx->downcount -= 8;
    // 80258D28: subfc   r4, r28, r4
    {
        u32 a = ~ctx->gpr[28];
        u32 b = ctx->gpr[4];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[4] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80258D2C:
    // 80258D2C: subfe   r0, r29, r3
    {
        u32 a = ~ctx->gpr[29];
        u32 b = ctx->gpr[3];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80258D30:
    // 80258D30: xoris   r3, r0, 0x8000
    ctx->gpr[3] = ctx->gpr[0] ^ (0x8000u << 16);

label_80258D34:
    // 80258D34: subfc   r0, r4, r30
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[30];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80258D38:
    // 80258D38: subfe   r3, r3, r31
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[31];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80258D3C:
    // 80258D3C: subfe   r3, r31, r31
    {
        u32 a = ~ctx->gpr[31];
        u32 b = ctx->gpr[31];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80258D40:
    // 80258D40: neg.  r3, r3
    {
        u32 a = ctx->gpr[3];
        ctx->gpr[3] = (~a) + 1u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[3];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80258D44:
    // 80258D44: bc    12, 2, 0x80258D24
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80258D24u;
                return;
            }
            goto label_80258D24;
        }
    }

label_80258D48:
    ctx->pc = 0x80258D48u;
    ctx->downcount -= 1;
    // 80258D48: bl      0x80257084
    {
            ctx->lr = 0x80258D4Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80257084u;
                return;
            }
            goto label_80257084;
    }

label_80258D4C:
    ctx->pc = 0x80258D4Cu;
    ctx->downcount -= 9;
    // 80258D4C: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80258D50:
    ctx->pc = 0x80258D50u;
    // 80258D50: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80258D54:
    ctx->pc = 0x80258D54u;
    // 80258D54: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80258D58:
    ctx->pc = 0x80258D58u;
    // 80258D58: lwz     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80258D5C:
    ctx->pc = 0x80258D5Cu;
    // 80258D5C: lwz     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_80258D60:
    ctx->pc = 0x80258D60u;
    // 80258D60: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80258D64:
    ctx->pc = 0x80258D64u;
    // 80258D64: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80258D68:
    ctx->pc = 0x80258D68u;
    // 80258D68: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80258D6C:
    ctx->pc = 0x80258D6Cu;
    ctx->downcount -= 7;
    // 80258D6C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80258D70:
    ctx->pc = 0x80258D70u;
    // 80258D70: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258D74:
    ctx->pc = 0x80258D74u;
    // 80258D74: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80258D78:
    ctx->pc = 0x80258D78u;
    // 80258D78: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80258D7C:
    ctx->pc = 0x80258D7Cu;
    // 80258D7C: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80258D80:
    ctx->pc = 0x80258D80u;
    // 80258D80: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80258D84:
    ctx->pc = 0x80258D84u;
    // 80258D84: bl      0x802440BC
    {
            ctx->lr = 0x80258D88u;
            ctx->pc = 0x802440BCu;
            return;
    }

label_80258D88:
    ctx->pc = 0x80258D88u;
    ctx->downcount -= 17;
    // 80258D88: li      r6, 97
    ctx->gpr[6] = (u32)(s32)(97);

label_80258D8C:
    ctx->pc = 0x80258D8Cu;
    // 80258D8C: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80258D90:
    ctx->pc = 0x80258D90u;
    // 80258D90: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_80258D94:
    ctx->pc = 0x80258D94u;
    // 80258D94: rlwinm r0, r30, 0, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[30], 0u) & 0x0000FFFFu;
    }

label_80258D98:
    ctx->pc = 0x80258D98u;
    // 80258D98: stb     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_80258D9C:
    ctx->pc = 0x80258D9Cu;
    // 80258D9C: oris    r0, r0, 0x4800
    ctx->gpr[0] = ctx->gpr[0] | (0x4800u << 16);

label_80258DA0:
    ctx->pc = 0x80258DA0u;
    // 80258DA0: stw     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258DA4:
    ctx->pc = 0x80258DA4u;
    // 80258DA4: rlwinm r0, r0, 0, 0, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFF0000u;
    }

label_80258DA8:
    ctx->pc = 0x80258DA8u;
    // 80258DA8: rlwimi r0, r30, 0, 16, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[30], 0u);
        ctx->gpr[0] = (ctx->gpr[0] & ~0x0000FFFFu) | (rot & 0x0000FFFFu);
    }

label_80258DAC:
    ctx->pc = 0x80258DACu;
    // 80258DAC: rlwinm r0, r0, 0, 8, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00FFFFFFu;
    }

label_80258DB0:
    ctx->pc = 0x80258DB0u;
    // 80258DB0: stb     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_80258DB4:
    ctx->pc = 0x80258DB4u;
    // 80258DB4: oris    r0, r0, 0x4700
    ctx->gpr[0] = ctx->gpr[0] | (0x4700u << 16);

label_80258DB8:
    ctx->pc = 0x80258DB8u;
    // 80258DB8: stw     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258DBC:
    ctx->pc = 0x80258DBCu;
    // 80258DBC: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80258DC0:
    ctx->pc = 0x80258DC0u;
    // 80258DC0: lwz     r0, 1268(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80258DC4:
    ctx->pc = 0x80258DC4u;
    // 80258DC4: cmplwi  r0, 0x0000
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

label_80258DC8:
    ctx->pc = 0x80258DC8u;
    // 80258DC8: bc    12, 2, 0x80258DD0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80258DD0;
        }
    }

label_80258DCC:
    ctx->pc = 0x80258DCCu;
    ctx->downcount -= 1;
    // 80258DCC: bl      0x8025916C
    {
            ctx->lr = 0x80258DD0u;
            goto label_8025916C;
    }

label_80258DD0:
    ctx->pc = 0x80258DD0u;
    ctx->downcount -= 11;
    // 80258DD0: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_80258DD4:
    ctx->pc = 0x80258DD4u;
    // 80258DD4: lis     r3, -13311
    ctx->gpr[3] = ((u32)(s32)(-13311) << 16);

label_80258DD8:
    ctx->pc = 0x80258DD8u;
    // 80258DD8: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80258DDC:
    ctx->pc = 0x80258DDCu;
    // 80258DDC: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80258DE0:
    ctx->pc = 0x80258DE0u;
    // 80258DE0: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80258DE4:
    ctx->pc = 0x80258DE4u;
    // 80258DE4: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80258DE8:
    ctx->pc = 0x80258DE8u;
    // 80258DE8: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80258DEC:
    ctx->pc = 0x80258DECu;
    // 80258DEC: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80258DF0:
    ctx->pc = 0x80258DF0u;
    // 80258DF0: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80258DF4:
    ctx->pc = 0x80258DF4u;
    // 80258DF4: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80258DF8:
    ctx->pc = 0x80258DF8u;
    // 80258DF8: bl      0x80240CBC
    {
            ctx->lr = 0x80258DFCu;
            ctx->pc = 0x80240CBCu;
            return;
    }

label_80258DFC:
    ctx->pc = 0x80258DFCu;
    ctx->downcount -= 2;
    // 80258DFC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80258E00:
    ctx->pc = 0x80258E00u;
    // 80258E00: bl      0x802440E4
    {
            ctx->lr = 0x80258E04u;
            ctx->pc = 0x802440E4u;
            return;
    }

label_80258E04:
    ctx->pc = 0x80258E04u;
    ctx->downcount -= 9;
    // 80258E04: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80258E08:
    ctx->pc = 0x80258E08u;
    // 80258E08: sth     r31, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[31]);
    }

label_80258E0C:
    ctx->pc = 0x80258E0Cu;
    // 80258E0C: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80258E10:
    ctx->pc = 0x80258E10u;
    // 80258E10: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80258E14:
    ctx->pc = 0x80258E14u;
    // 80258E14: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80258E18:
    ctx->pc = 0x80258E18u;
    // 80258E18: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80258E1C:
    ctx->pc = 0x80258E1Cu;
    // 80258E1C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80258E20:
    ctx->pc = 0x80258E20u;
    // 80258E20: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80258E24:
    ctx->pc = 0x80258E24u;
    ctx->downcount -= 3;
    // 80258E24: lwz     r3, -20696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80258E28:
    ctx->pc = 0x80258E28u;
    // 80258E28: lhz     r3, 14(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(14);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_80258E2C:
    ctx->pc = 0x80258E2Cu;
    // 80258E2C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80258E30:
    ctx->pc = 0x80258E30u;
    ctx->downcount -= 9;
    // 80258E30: li      r0, 97
    ctx->gpr[0] = (u32)(s32)(97);

label_80258E34:
    ctx->pc = 0x80258E34u;
    // 80258E34: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80258E38:
    ctx->pc = 0x80258E38u;
    // 80258E38: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_80258E3C:
    ctx->pc = 0x80258E3Cu;
    // 80258E3C: stb     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80258E40:
    ctx->pc = 0x80258E40u;
    // 80258E40: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80258E44:
    ctx->pc = 0x80258E44u;
    // 80258E44: lwz     r3, 476(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(476);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80258E48:
    ctx->pc = 0x80258E48u;
    // 80258E48: stw     r3, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80258E4C:
    ctx->pc = 0x80258E4Cu;
    // 80258E4C: sth     r0, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80258E50:
    ctx->pc = 0x80258E50u;
    // 80258E50: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80258E54:
    ctx->pc = 0x80258E54u;
    ctx->downcount -= 9;
    // 80258E54: li      r0, 97
    ctx->gpr[0] = (u32)(s32)(97);

label_80258E58:
    ctx->pc = 0x80258E58u;
    // 80258E58: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80258E5C:
    ctx->pc = 0x80258E5Cu;
    // 80258E5C: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_80258E60:
    ctx->pc = 0x80258E60u;
    // 80258E60: stb     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80258E64:
    ctx->pc = 0x80258E64u;
    // 80258E64: lis     r4, 25344
    ctx->gpr[4] = ((u32)(s32)(25344) << 16);

label_80258E68:
    ctx->pc = 0x80258E68u;
    // 80258E68: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80258E6C:
    ctx->pc = 0x80258E6Cu;
    // 80258E6C: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80258E70:
    ctx->pc = 0x80258E70u;
    // 80258E70: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80258E74:
    ctx->pc = 0x80258E74u;
    // 80258E74: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80258E78:
    ctx->pc = 0x80258E78u;
    ctx->downcount -= 5;
    // 80258E78: lwz     r5, -20696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80258E7C:
    ctx->pc = 0x80258E7Cu;
    // 80258E7C: rlwinm r0, r4, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x000000FFu;
    }

label_80258E80:
    ctx->pc = 0x80258E80u;
    // 80258E80: rlwimi r0, r3, 8, 0, 23
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[3], 8u);
        ctx->gpr[0] = (ctx->gpr[0] & ~0xFFFFFF00u) | (rot & 0xFFFFFF00u);
    }

label_80258E84:
    ctx->pc = 0x80258E84u;
    // 80258E84: sth     r0, 6(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(6);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80258E88:
    ctx->pc = 0x80258E88u;
    // 80258E88: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80258E8C:
    ctx->pc = 0x80258E8Cu;
    ctx->downcount -= 5;
    // 80258E8C: rlwinm r0, r3, 0, 30, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFFBu;
    }

label_80258E90:
    ctx->pc = 0x80258E90u;
    // 80258E90: lwz     r3, -20696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80258E94:
    ctx->pc = 0x80258E94u;
    // 80258E94: ori     r0, r0, 0x0004
    ctx->gpr[0] = ctx->gpr[0] | 0x0004u;

label_80258E98:
    ctx->pc = 0x80258E98u;
    // 80258E98: sth     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80258E9C:
    ctx->pc = 0x80258E9Cu;
    // 80258E9C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80258EA0:
    ctx->pc = 0x80258EA0u;
    ctx->downcount -= 7;
    // 80258EA0: lwz     r4, -20696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80258EA4:
    ctx->pc = 0x80258EA4u;
    // 80258EA4: rlwinm r0, r3, 4, 20, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 4u) & 0x00000FF0u;
    }

label_80258EA8:
    ctx->pc = 0x80258EA8u;
    // 80258EA8: lhzu     r3, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        ctx->gpr[3] = mem_read16(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_80258EAC:
    ctx->pc = 0x80258EACu;
    // 80258EAC: rlwinm r3, r3, 0, 28, 26
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFEFu;
    }

label_80258EB0:
    ctx->pc = 0x80258EB0u;
    // 80258EB0: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80258EB4:
    ctx->pc = 0x80258EB4u;
    // 80258EB4: sth     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80258EB8:
    ctx->pc = 0x80258EB8u;
    // 80258EB8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80258EBC:
    ctx->pc = 0x80258EBCu;
    ctx->downcount -= 6;
    // 80258EBC: lwz     r7, -20696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20696);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80258EC0:
    ctx->pc = 0x80258EC0u;
    // 80258EC0: cmpwi   r3, 1
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

label_80258EC4:
    ctx->pc = 0x80258EC4u;
    // 80258EC4: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_80258EC8:
    ctx->pc = 0x80258EC8u;
    // 80258EC8: addi    r10, r7, 2
    ctx->gpr[10] = ctx->gpr[7] + (u32)(s32)(2);

label_80258ECC:
    ctx->pc = 0x80258ECCu;
    // 80258ECC: lhz     r7, 2(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(2);
        ctx->gpr[7] = mem_read16(ctx, ea);
    }

label_80258ED0:
    ctx->pc = 0x80258ED0u;
    // 80258ED0: bc    12, 2, 0x80258EE0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80258EE0;
        }
    }

label_80258ED4:
    ctx->pc = 0x80258ED4u;
    ctx->downcount -= 2;
    // 80258ED4: cmpwi   r3, 3
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80258ED8:
    ctx->pc = 0x80258ED8u;
    // 80258ED8: bc    12, 2, 0x80258EE0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80258EE0;
        }
    }

label_80258EDC:
    ctx->pc = 0x80258EDCu;
    ctx->downcount -= 1;
    // 80258EDC: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_80258EE0:
    ctx->pc = 0x80258EE0u;
    ctx->downcount -= 25;
    // 80258EE0: rlwinm r8, r7, 0, 0, 30
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFFFFFFFEu;
    }

label_80258EE4:
    ctx->pc = 0x80258EE4u;
    // 80258EE4: subfic  r0, r3, 3
    {
        u64 res = (u64)(u32)(s32)(3) + (u64)(~ctx->gpr[3]) + 1u;
        ctx->gpr[0] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_80258EE8:
    ctx->pc = 0x80258EE8u;
    // 80258EE8: cntlzw r7, r0
    {
        u32 v = ctx->gpr[0];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[7] = n;
    }

label_80258EEC:
    ctx->pc = 0x80258EECu;
    // 80258EEC: subfic  r0, r3, 2
    {
        u64 res = (u64)(u32)(s32)(2) + (u64)(~ctx->gpr[3]) + 1u;
        ctx->gpr[0] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_80258EF0:
    ctx->pc = 0x80258EF0u;
    // 80258EF0: or   r8, r8, r9
    {
        ctx->gpr[8] = ctx->gpr[8] | ctx->gpr[9];
    }

label_80258EF4:
    ctx->pc = 0x80258EF4u;
    // 80258EF4: cntlzw r0, r0
    {
        u32 v = ctx->gpr[0];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_80258EF8:
    ctx->pc = 0x80258EF8u;
    // 80258EF8: rlwinm r8, r8, 0, 21, 19
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[8], 0u) & 0xFFFFF7FFu;
    }

label_80258EFC:
    ctx->pc = 0x80258EFCu;
    // 80258EFC: rlwinm r3, r7, 6, 0, 20
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[7], 6u) & 0xFFFFF800u;
    }

label_80258F00:
    ctx->pc = 0x80258F00u;
    // 80258F00: or   r3, r8, r3
    {
        ctx->gpr[3] = ctx->gpr[8] | ctx->gpr[3];
    }

label_80258F04:
    ctx->pc = 0x80258F04u;
    // 80258F04: rlwinm r3, r3, 0, 31, 29
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFFDu;
    }

label_80258F08:
    ctx->pc = 0x80258F08u;
    // 80258F08: rlwinm r0, r0, 28, 4, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 28u) & 0x0FFFFFFEu;
    }

label_80258F0C:
    ctx->pc = 0x80258F0Cu;
    // 80258F0C: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80258F10:
    ctx->pc = 0x80258F10u;
    // 80258F10: rlwinm r3, r0, 0, 20, 15
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFF0FFFu;
    }

label_80258F14:
    ctx->pc = 0x80258F14u;
    // 80258F14: rlwinm r0, r6, 12, 0, 19
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 12u) & 0xFFFFF000u;
    }

label_80258F18:
    ctx->pc = 0x80258F18u;
    // 80258F18: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80258F1C:
    ctx->pc = 0x80258F1Cu;
    // 80258F1C: rlwinm r3, r0, 0, 24, 20
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFF8FFu;
    }

label_80258F20:
    ctx->pc = 0x80258F20u;
    // 80258F20: rlwinm r0, r4, 8, 0, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 8u) & 0xFFFFFF00u;
    }

label_80258F24:
    ctx->pc = 0x80258F24u;
    // 80258F24: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80258F28:
    ctx->pc = 0x80258F28u;
    // 80258F28: rlwinm r3, r0, 0, 27, 23
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFF1Fu;
    }

label_80258F2C:
    ctx->pc = 0x80258F2Cu;
    // 80258F2C: rlwinm r0, r5, 5, 0, 26
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 5u) & 0xFFFFFFE0u;
    }

label_80258F30:
    ctx->pc = 0x80258F30u;
    // 80258F30: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80258F34:
    ctx->pc = 0x80258F34u;
    // 80258F34: rlwinm r0, r0, 0, 8, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00FFFFFFu;
    }

label_80258F38:
    ctx->pc = 0x80258F38u;
    // 80258F38: oris    r0, r0, 0x4100
    ctx->gpr[0] = ctx->gpr[0] | (0x4100u << 16);

label_80258F3C:
    ctx->pc = 0x80258F3Cu;
    // 80258F3C: sth     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80258F40:
    ctx->pc = 0x80258F40u;
    // 80258F40: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80258F44:
    ctx->pc = 0x80258F44u;
    ctx->downcount -= 7;
    // 80258F44: lwz     r4, -20696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80258F48:
    ctx->pc = 0x80258F48u;
    // 80258F48: rlwinm r0, r3, 3, 21, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 3u) & 0x000007F8u;
    }

label_80258F4C:
    ctx->pc = 0x80258F4Cu;
    // 80258F4C: lhzu     r3, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        ctx->gpr[3] = mem_read16(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_80258F50:
    ctx->pc = 0x80258F50u;
    // 80258F50: rlwinm r3, r3, 0, 29, 27
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFF7u;
    }

label_80258F54:
    ctx->pc = 0x80258F54u;
    // 80258F54: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80258F58:
    ctx->pc = 0x80258F58u;
    // 80258F58: sth     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80258F5C:
    ctx->pc = 0x80258F5Cu;
    // 80258F5C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80258F60:
    ctx->pc = 0x80258F60u;
    ctx->downcount -= 5;
    // 80258F60: lwz     r5, -20696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80258F64:
    ctx->pc = 0x80258F64u;
    // 80258F64: rlwinm r0, r3, 8, 16, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 8u) & 0x0000FF00u;
    }

label_80258F68:
    ctx->pc = 0x80258F68u;
    // 80258F68: rlwimi r0, r4, 0, 24, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[4], 0u);
        ctx->gpr[0] = (ctx->gpr[0] & ~0x000000FFu) | (rot & 0x000000FFu);
    }

label_80258F6C:
    ctx->pc = 0x80258F6Cu;
    // 80258F6C: sth     r0, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80258F70:
    ctx->pc = 0x80258F70u;
    // 80258F70: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80258F74:
    ctx->pc = 0x80258F74u;
    ctx->downcount -= 7;
    // 80258F74: lwz     r4, -20696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80258F78:
    ctx->pc = 0x80258F78u;
    // 80258F78: rlwinm r0, r3, 2, 22, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0x000003FCu;
    }

label_80258F7C:
    ctx->pc = 0x80258F7Cu;
    // 80258F7C: lhzu     r3, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        ctx->gpr[3] = mem_read16(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_80258F80:
    ctx->pc = 0x80258F80u;
    // 80258F80: rlwinm r3, r3, 0, 30, 28
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFFBu;
    }

label_80258F84:
    ctx->pc = 0x80258F84u;
    // 80258F84: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80258F88:
    ctx->pc = 0x80258F88u;
    // 80258F88: sth     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80258F8C:
    ctx->pc = 0x80258F8Cu;
    // 80258F8C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80258F90:
    ctx->pc = 0x80258F90u;
    ctx->downcount -= 10;
    // 80258F90: rlwinm r0, r3, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000000FFu;
    }

label_80258F94:
    ctx->pc = 0x80258F94u;
    // 80258F94: lwz     r3, -20696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80258F98:
    ctx->pc = 0x80258F98u;
    // 80258F98: rlwinm r6, r0, 0, 31, 27
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFF1u;
    }

label_80258F9C:
    ctx->pc = 0x80258F9Cu;
    // 80258F9C: rlwinm r0, r4, 1, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 1u) & 0xFFFFFFFEu;
    }

label_80258FA0:
    ctx->pc = 0x80258FA0u;
    // 80258FA0: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_80258FA4:
    ctx->pc = 0x80258FA4u;
    // 80258FA4: rlwinm r4, r0, 0, 28, 26
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFEFu;
    }

label_80258FA8:
    ctx->pc = 0x80258FA8u;
    // 80258FA8: rlwinm r0, r5, 4, 20, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 4u) & 0x00000FF0u;
    }

label_80258FAC:
    ctx->pc = 0x80258FACu;
    // 80258FAC: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80258FB0:
    ctx->pc = 0x80258FB0u;
    // 80258FB0: sth     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80258FB4:
    ctx->pc = 0x80258FB4u;
    // 80258FB4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80258FB8:
    ctx->pc = 0x80258FB8u;
    ctx->downcount -= 10;
    // 80258FB8: rlwinm r0, r3, 2, 14, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0x0003FFFCu;
    }

label_80258FBC:
    ctx->pc = 0x80258FBCu;
    // 80258FBC: oris    r0, r0, 0xC800
    ctx->gpr[0] = ctx->gpr[0] | (0xC800u << 16);

label_80258FC0:
    ctx->pc = 0x80258FC0u;
    // 80258FC0: rlwinm r3, r0, 0, 20, 9
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFC00FFFu;
    }

label_80258FC4:
    ctx->pc = 0x80258FC4u;
    // 80258FC4: rlwinm r0, r4, 12, 4, 19
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 12u) & 0x0FFFF000u;
    }

label_80258FC8:
    ctx->pc = 0x80258FC8u;
    // 80258FC8: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80258FCC:
    ctx->pc = 0x80258FCCu;
    // 80258FCC: rlwinm r0, r0, 0, 10, 7
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFF3FFFFFu;
    }

label_80258FD0:
    ctx->pc = 0x80258FD0u;
    // 80258FD0: oris    r3, r0, 0x0040
    ctx->gpr[3] = ctx->gpr[0] | (0x0040u << 16);

label_80258FD4:
    ctx->pc = 0x80258FD4u;
    // 80258FD4: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80258FD8:
    ctx->pc = 0x80258FD8u;
    // 80258FD8: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258FDC:
    ctx->pc = 0x80258FDCu;
    // 80258FDC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80258FE0:
    ctx->pc = 0x80258FE0u;
    ctx->downcount -= 11;
    // 80258FE0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80258FE4:
    ctx->pc = 0x80258FE4u;
    // 80258FE4: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80258FE8:
    ctx->pc = 0x80258FE8u;
    // 80258FE8: stwu     r1, -736(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-736);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80258FEC:
    ctx->pc = 0x80258FECu;
    // 80258FEC: stw     r31, 732(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(732);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80258FF0:
    ctx->pc = 0x80258FF0u;
    // 80258FF0: stw     r30, 728(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(728);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80258FF4:
    ctx->pc = 0x80258FF4u;
    // 80258FF4: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80258FF8:
    ctx->pc = 0x80258FF8u;
    // 80258FF8: lwz     r0, -20656(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20656);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80258FFC:
    ctx->pc = 0x80258FFCu;
    // 80258FFC: lwz     r3, -20696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259000:
    ctx->pc = 0x80259000u;
    // 80259000: cmplwi  r0, 0x0000
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

label_80259004:
    ctx->pc = 0x80259004u;
    // 80259004: lhz     r31, 14(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(14);
        ctx->gpr[31] = mem_read16(ctx, ea);
    }

label_80259008:
    ctx->pc = 0x80259008u;
    // 80259008: bc    12, 2, 0x8025903C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8025903C;
        }
    }

label_8025900C:
    ctx->pc = 0x8025900Cu;
    ctx->downcount -= 2;
    // 8025900C: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_80259010:
    ctx->pc = 0x80259010u;
    // 80259010: bl      0x80242DB4
    {
            ctx->lr = 0x80259014u;
            ctx->pc = 0x80242DB4u;
            return;
    }

label_80259014:
    ctx->pc = 0x80259014u;
    ctx->downcount -= 2;
    // 80259014: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_80259018:
    ctx->pc = 0x80259018u;
    // 80259018: bl      0x80242BEC
    {
            ctx->lr = 0x8025901Cu;
            ctx->pc = 0x80242BECu;
            return;
    }

label_8025901C:
    ctx->pc = 0x8025901Cu;
    ctx->downcount -= 5;
    // 8025901C: lwz     r12, -20656(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20656);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_80259020:
    ctx->pc = 0x80259020u;
    // 80259020: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_80259024:
    ctx->pc = 0x80259024u;
    // 80259024: mtlr    r12
    ctx->lr = ctx->gpr[12];

label_80259028:
    ctx->pc = 0x80259028u;
    // 80259028: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8025902Cu;
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_8025902C:
    ctx->pc = 0x8025902Cu;
    ctx->downcount -= 2;
    // 8025902C: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_80259030:
    ctx->pc = 0x80259030u;
    // 80259030: bl      0x80242DB4
    {
            ctx->lr = 0x80259034u;
            ctx->pc = 0x80242DB4u;
            return;
    }

label_80259034:
    ctx->pc = 0x80259034u;
    ctx->downcount -= 2;
    // 80259034: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80259038:
    ctx->pc = 0x80259038u;
    // 80259038: bl      0x80242BEC
    {
            ctx->lr = 0x8025903Cu;
            ctx->pc = 0x80242BECu;
            return;
    }

label_8025903C:
    ctx->pc = 0x8025903Cu;
    ctx->downcount -= 12;
    // 8025903C: lwz     r3, -20696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259040:
    ctx->pc = 0x80259040u;
    // 80259040: lhzu     r0, 10(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(10);
        ctx->gpr[0] = mem_read16(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_80259044:
    ctx->pc = 0x80259044u;
    // 80259044: rlwinm r0, r0, 0, 30, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFBu;
    }

label_80259048:
    ctx->pc = 0x80259048u;
    // 80259048: ori     r0, r0, 0x0004
    ctx->gpr[0] = ctx->gpr[0] | 0x0004u;

label_8025904C:
    ctx->pc = 0x8025904Cu;
    // 8025904C: sth     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80259050:
    ctx->pc = 0x80259050u;
    // 80259050: lwz     r0, 740(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(740);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80259054:
    ctx->pc = 0x80259054u;
    // 80259054: lwz     r31, 732(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(732);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80259058:
    ctx->pc = 0x80259058u;
    // 80259058: lwz     r30, 728(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(728);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8025905C:
    ctx->pc = 0x8025905Cu;
    // 8025905C: addi    r1, r1, 736
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(736);

label_80259060:
    ctx->pc = 0x80259060u;
    // 80259060: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80259064:
    ctx->pc = 0x80259064u;
    // 80259064: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80259068:
    ctx->pc = 0x80259068u;
    ctx->downcount -= 15;
    // 80259068: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8025906C:
    ctx->pc = 0x8025906Cu;
    // 8025906C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80259070:
    ctx->pc = 0x80259070u;
    // 80259070: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80259074:
    ctx->pc = 0x80259074u;
    // 80259074: stwu     r1, -736(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-736);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80259078:
    ctx->pc = 0x80259078u;
    // 80259078: stw     r31, 732(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(732);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8025907C:
    ctx->pc = 0x8025907Cu;
    // 8025907C: addi    r31, r4, 0
    ctx->gpr[31] = ctx->gpr[4] + (u32)(s32)(0);

label_80259080:
    ctx->pc = 0x80259080u;
    // 80259080: lwz     r5, -20696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80259084:
    ctx->pc = 0x80259084u;
    // 80259084: lhz     r0, 10(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(10);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80259088:
    ctx->pc = 0x80259088u;
    // 80259088: rlwinm r0, r0, 0, 29, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFF7u;
    }

label_8025908C:
    ctx->pc = 0x8025908Cu;
    // 8025908C: ori     r0, r0, 0x0008
    ctx->gpr[0] = ctx->gpr[0] | 0x0008u;

label_80259090:
    ctx->pc = 0x80259090u;
    // 80259090: sth     r0, 10(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(10);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80259094:
    ctx->pc = 0x80259094u;
    // 80259094: lwz     r0, -20652(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20652);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80259098:
    ctx->pc = 0x80259098u;
    // 80259098: stb     r3, -20648(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20648);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_8025909C:
    ctx->pc = 0x8025909Cu;
    // 8025909C: cmplwi  r0, 0x0000
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

label_802590A0:
    ctx->pc = 0x802590A0u;
    // 802590A0: bc    12, 2, 0x802590D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802590D0;
        }
    }

label_802590A4:
    ctx->pc = 0x802590A4u;
    ctx->downcount -= 2;
    // 802590A4: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_802590A8:
    ctx->pc = 0x802590A8u;
    // 802590A8: bl      0x80242DB4
    {
            ctx->lr = 0x802590ACu;
            ctx->pc = 0x80242DB4u;
            return;
    }

label_802590AC:
    ctx->pc = 0x802590ACu;
    ctx->downcount -= 2;
    // 802590AC: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_802590B0:
    ctx->pc = 0x802590B0u;
    // 802590B0: bl      0x80242BEC
    {
            ctx->lr = 0x802590B4u;
            ctx->pc = 0x80242BECu;
            return;
    }

label_802590B4:
    ctx->pc = 0x802590B4u;
    ctx->downcount -= 4;
    // 802590B4: lwz     r12, -20652(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20652);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_802590B8:
    ctx->pc = 0x802590B8u;
    // 802590B8: mtlr    r12
    ctx->lr = ctx->gpr[12];

label_802590BC:
    ctx->pc = 0x802590BCu;
    // 802590BC: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x802590C0u;
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_802590C0:
    ctx->pc = 0x802590C0u;
    ctx->downcount -= 2;
    // 802590C0: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_802590C4:
    ctx->pc = 0x802590C4u;
    // 802590C4: bl      0x80242DB4
    {
            ctx->lr = 0x802590C8u;
            ctx->pc = 0x80242DB4u;
            return;
    }

label_802590C8:
    ctx->pc = 0x802590C8u;
    ctx->downcount -= 2;
    // 802590C8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_802590CC:
    ctx->pc = 0x802590CCu;
    // 802590CC: bl      0x80242BEC
    {
            ctx->lr = 0x802590D0u;
            ctx->pc = 0x80242BECu;
            return;
    }

label_802590D0:
    ctx->pc = 0x802590D0u;
    ctx->downcount -= 2;
    // 802590D0: addi    r3, r13, -20644
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-20644);

label_802590D4:
    ctx->pc = 0x802590D4u;
    // 802590D4: bl      0x802474F8
    {
            ctx->lr = 0x802590D8u;
            ctx->pc = 0x802474F8u;
            return;
    }

label_802590D8:
    ctx->pc = 0x802590D8u;
    ctx->downcount -= 6;
    // 802590D8: lwz     r0, 740(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(740);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802590DC:
    ctx->pc = 0x802590DCu;
    // 802590DC: lwz     r31, 732(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(732);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802590E0:
    ctx->pc = 0x802590E0u;
    // 802590E0: addi    r1, r1, 736
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(736);

label_802590E4:
    ctx->pc = 0x802590E4u;
    // 802590E4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802590E8:
    ctx->pc = 0x802590E8u;
    // 802590E8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_802590EC:
    ctx->pc = 0x802590ECu;
    ctx->downcount -= 7;
    // 802590EC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_802590F0:
    ctx->pc = 0x802590F0u;
    // 802590F0: lis     r3, -32730
    ctx->gpr[3] = ((u32)(s32)(-32730) << 16);

label_802590F4:
    ctx->pc = 0x802590F4u;
    // 802590F4: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802590F8:
    ctx->pc = 0x802590F8u;
    // 802590F8: addi    r4, r3, -28704
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(-28704);

label_802590FC:
    ctx->pc = 0x802590FCu;
    // 802590FC: li      r3, 18
    ctx->gpr[3] = (u32)(s32)(18);

label_80259100:
    ctx->pc = 0x80259100u;
    // 80259100: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80259104:
    ctx->pc = 0x80259104u;
    // 80259104: bl      0x80244108
    {
            ctx->lr = 0x80259108u;
            ctx->pc = 0x80244108u;
            return;
    }

label_80259108:
    ctx->pc = 0x80259108u;
    ctx->downcount -= 4;
    // 80259108: lis     r3, -32730
    ctx->gpr[3] = ((u32)(s32)(-32730) << 16);

label_8025910C:
    ctx->pc = 0x8025910Cu;
    // 8025910C: addi    r4, r3, -28568
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(-28568);

label_80259110:
    ctx->pc = 0x80259110u;
    // 80259110: li      r3, 19
    ctx->gpr[3] = (u32)(s32)(19);

label_80259114:
    ctx->pc = 0x80259114u;
    // 80259114: bl      0x80244108
    {
            ctx->lr = 0x80259118u;
            ctx->pc = 0x80244108u;
            return;
    }

label_80259118:
    ctx->pc = 0x80259118u;
    ctx->downcount -= 2;
    // 80259118: addi    r3, r13, -20644
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-20644);

label_8025911C:
    ctx->pc = 0x8025911Cu;
    // 8025911C: bl      0x80246724
    {
            ctx->lr = 0x80259120u;
            ctx->pc = 0x80246724u;
            return;
    }

label_80259120:
    ctx->pc = 0x80259120u;
    ctx->downcount -= 2;
    // 80259120: li      r3, 8192
    ctx->gpr[3] = (u32)(s32)(8192);

label_80259124:
    ctx->pc = 0x80259124u;
    // 80259124: bl      0x8024450C
    {
            ctx->lr = 0x80259128u;
            ctx->pc = 0x8024450Cu;
            return;
    }

label_80259128:
    ctx->pc = 0x80259128u;
    ctx->downcount -= 2;
    // 80259128: li      r3, 4096
    ctx->gpr[3] = (u32)(s32)(4096);

label_8025912C:
    ctx->pc = 0x8025912Cu;
    // 8025912C: bl      0x8024450C
    {
            ctx->lr = 0x80259130u;
            ctx->pc = 0x8024450Cu;
            return;
    }

label_80259130:
    ctx->pc = 0x80259130u;
    ctx->downcount -= 16;
    // 80259130: lwz     r3, -20696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-20696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259134:
    ctx->pc = 0x80259134u;
    // 80259134: lhzu     r0, 10(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(10);
        ctx->gpr[0] = mem_read16(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_80259138:
    ctx->pc = 0x80259138u;
    // 80259138: rlwinm r0, r0, 0, 30, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFBu;
    }

label_8025913C:
    ctx->pc = 0x8025913Cu;
    // 8025913C: ori     r0, r0, 0x0004
    ctx->gpr[0] = ctx->gpr[0] | 0x0004u;

label_80259140:
    ctx->pc = 0x80259140u;
    // 80259140: rlwinm r0, r0, 0, 29, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFF7u;
    }

label_80259144:
    ctx->pc = 0x80259144u;
    // 80259144: ori     r0, r0, 0x0008
    ctx->gpr[0] = ctx->gpr[0] | 0x0008u;

label_80259148:
    ctx->pc = 0x80259148u;
    // 80259148: rlwinm r0, r0, 0, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFEu;
    }

label_8025914C:
    ctx->pc = 0x8025914Cu;
    // 8025914C: ori     r0, r0, 0x0001
    ctx->gpr[0] = ctx->gpr[0] | 0x0001u;

label_80259150:
    ctx->pc = 0x80259150u;
    // 80259150: rlwinm r0, r0, 0, 31, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFDu;
    }

label_80259154:
    ctx->pc = 0x80259154u;
    // 80259154: ori     r0, r0, 0x0002
    ctx->gpr[0] = ctx->gpr[0] | 0x0002u;

label_80259158:
    ctx->pc = 0x80259158u;
    // 80259158: sth     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8025915C:
    ctx->pc = 0x8025915Cu;
    // 8025915C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80259160:
    ctx->pc = 0x80259160u;
    // 80259160: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80259164:
    ctx->pc = 0x80259164u;
    // 80259164: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80259168:
    ctx->pc = 0x80259168u;
    // 80259168: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_8025916C:
    ctx->pc = 0x8025916Cu;
    ctx->downcount -= 7;
    // 8025916C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80259170:
    ctx->pc = 0x80259170u;
    // 80259170: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80259174:
    ctx->pc = 0x80259174u;
    // 80259174: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80259178:
    ctx->pc = 0x80259178u;
    // 80259178: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8025917C:
    ctx->pc = 0x8025917Cu;
    // 8025917C: lwz     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80259180:
    ctx->pc = 0x80259180u;
    // 80259180: rlwinm. r0, r0, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80259184:
    ctx->pc = 0x80259184u;
    // 80259184: bc    12, 2, 0x8025918C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8025918C;
        }
    }

label_80259188:
    ctx->pc = 0x80259188u;
    ctx->downcount -= 1;
    // 80259188: bl      0x8025B79C
    {
            ctx->lr = 0x8025918Cu;
            ctx->pc = 0x8025B79Cu;
            return;
    }

label_8025918C:
    ctx->pc = 0x8025918Cu;
    ctx->downcount -= 4;
    // 8025918C: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259190:
    ctx->pc = 0x80259190u;
    // 80259190: lwz     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80259194:
    ctx->pc = 0x80259194u;
    // 80259194: rlwinm. r0, r0, 0, 30, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000002u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80259198:
    ctx->pc = 0x80259198u;
    // 80259198: bc    12, 2, 0x802591A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802591A0;
        }
    }

label_8025919C:
    ctx->pc = 0x8025919Cu;
    ctx->downcount -= 1;
    // 8025919C: bl      0x8025C11C
    {
            ctx->lr = 0x802591A0u;
            ctx->pc = 0x8025C11Cu;
            return;
    }

label_802591A0:
    ctx->pc = 0x802591A0u;
    ctx->downcount -= 4;
    // 802591A0: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802591A4:
    ctx->pc = 0x802591A4u;
    // 802591A4: lwz     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802591A8:
    ctx->pc = 0x802591A8u;
    // 802591A8: rlwinm. r0, r0, 0, 29, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000004u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802591AC:
    ctx->pc = 0x802591ACu;
    // 802591AC: bc    12, 2, 0x802591B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802591B4;
        }
    }

label_802591B0:
    ctx->pc = 0x802591B0u;
    ctx->downcount -= 1;
    // 802591B0: bl      0x80259528
    {
            ctx->lr = 0x802591B4u;
            goto label_80259528;
    }

label_802591B4:
    ctx->pc = 0x802591B4u;
    ctx->downcount -= 4;
    // 802591B4: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802591B8:
    ctx->pc = 0x802591B8u;
    // 802591B8: lwz     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802591BC:
    ctx->pc = 0x802591BCu;
    // 802591BC: rlwinm. r0, r0, 0, 28, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000008u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802591C0:
    ctx->pc = 0x802591C0u;
    // 802591C0: bc    12, 2, 0x802591C8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802591C8;
        }
    }

label_802591C4:
    ctx->pc = 0x802591C4u;
    ctx->downcount -= 1;
    // 802591C4: bl      0x802579CC
    {
            ctx->lr = 0x802591C8u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802579CCu;
                return;
            }
            goto label_802579CC;
    }

label_802591C8:
    ctx->pc = 0x802591C8u;
    ctx->downcount -= 4;
    // 802591C8: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802591CC:
    ctx->pc = 0x802591CCu;
    // 802591CC: lwz     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802591D0:
    ctx->pc = 0x802591D0u;
    // 802591D0: rlwinm. r0, r0, 0, 27, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000010u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802591D4:
    ctx->pc = 0x802591D4u;
    // 802591D4: bc    12, 2, 0x802591DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802591DC;
        }
    }

label_802591D8:
    ctx->pc = 0x802591D8u;
    ctx->downcount -= 1;
    // 802591D8: bl      0x8025848C
    {
            ctx->lr = 0x802591DCu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8025848Cu;
                return;
            }
            goto label_8025848C;
    }

label_802591DC:
    ctx->pc = 0x802591DCu;
    ctx->downcount -= 4;
    // 802591DC: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802591E0:
    ctx->pc = 0x802591E0u;
    // 802591E0: lwz     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802591E4:
    ctx->pc = 0x802591E4u;
    // 802591E4: rlwinm. r0, r0, 0, 27, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000018u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802591E8:
    ctx->pc = 0x802591E8u;
    // 802591E8: bc    12, 2, 0x802591F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802591F0;
        }
    }

label_802591EC:
    ctx->pc = 0x802591ECu;
    ctx->downcount -= 1;
    // 802591EC: bl      0x80257A20
    {
            ctx->lr = 0x802591F0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80257A20u;
                return;
            }
            goto label_80257A20;
    }

label_802591F0:
    ctx->pc = 0x802591F0u;
    ctx->downcount -= 8;
    // 802591F0: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802591F4:
    ctx->pc = 0x802591F4u;
    // 802591F4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802591F8:
    ctx->pc = 0x802591F8u;
    // 802591F8: stw     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802591FC:
    ctx->pc = 0x802591FCu;
    // 802591FC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80259200:
    ctx->pc = 0x80259200u;
    // 80259200: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80259204:
    ctx->pc = 0x80259204u;
    // 80259204: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80259208:
    ctx->pc = 0x80259208u;
    // 80259208: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_8025920C:
    ctx->pc = 0x8025920Cu;
    ctx->downcount -= 13;
    // 8025920C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80259210:
    ctx->pc = 0x80259210u;
    // 80259210: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80259214:
    ctx->pc = 0x80259214u;
    // 80259214: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80259218:
    ctx->pc = 0x80259218u;
    // 80259218: stw     r31, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8025921C:
    ctx->pc = 0x8025921Cu;
    // 8025921C: addi    r31, r5, 0
    ctx->gpr[31] = ctx->gpr[5] + (u32)(s32)(0);

label_80259220:
    ctx->pc = 0x80259220u;
    // 80259220: stw     r30, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80259224:
    ctx->pc = 0x80259224u;
    // 80259224: addi    r30, r4, 0
    ctx->gpr[30] = ctx->gpr[4] + (u32)(s32)(0);

label_80259228:
    ctx->pc = 0x80259228u;
    // 80259228: stw     r29, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_8025922C:
    ctx->pc = 0x8025922Cu;
    // 8025922C: addi    r29, r3, 0
    ctx->gpr[29] = ctx->gpr[3] + (u32)(s32)(0);

label_80259230:
    ctx->pc = 0x80259230u;
    // 80259230: lwz     r6, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80259234:
    ctx->pc = 0x80259234u;
    // 80259234: lwz     r0, 1268(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80259238:
    ctx->pc = 0x80259238u;
    // 80259238: cmplwi  r0, 0x0000
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

label_8025923C:
    ctx->pc = 0x8025923Cu;
    // 8025923C: bc    12, 2, 0x802592BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802592BC;
        }
    }

label_80259240:
    ctx->pc = 0x80259240u;
    ctx->downcount -= 2;
    // 80259240: rlwinm. r0, r0, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80259244:
    ctx->pc = 0x80259244u;
    // 80259244: bc    12, 2, 0x8025924C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8025924C;
        }
    }

label_80259248:
    ctx->pc = 0x80259248u;
    ctx->downcount -= 1;
    // 80259248: bl      0x8025B79C
    {
            ctx->lr = 0x8025924Cu;
            ctx->pc = 0x8025B79Cu;
            return;
    }

label_8025924C:
    ctx->pc = 0x8025924Cu;
    ctx->downcount -= 4;
    // 8025924C: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259250:
    ctx->pc = 0x80259250u;
    // 80259250: lwz     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80259254:
    ctx->pc = 0x80259254u;
    // 80259254: rlwinm. r0, r0, 0, 30, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000002u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80259258:
    ctx->pc = 0x80259258u;
    // 80259258: bc    12, 2, 0x80259260
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80259260;
        }
    }

label_8025925C:
    ctx->pc = 0x8025925Cu;
    ctx->downcount -= 1;
    // 8025925C: bl      0x8025C11C
    {
            ctx->lr = 0x80259260u;
            ctx->pc = 0x8025C11Cu;
            return;
    }

label_80259260:
    ctx->pc = 0x80259260u;
    ctx->downcount -= 4;
    // 80259260: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259264:
    ctx->pc = 0x80259264u;
    // 80259264: lwz     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80259268:
    ctx->pc = 0x80259268u;
    // 80259268: rlwinm. r0, r0, 0, 29, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000004u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8025926C:
    ctx->pc = 0x8025926Cu;
    // 8025926C: bc    12, 2, 0x80259274
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80259274;
        }
    }

label_80259270:
    ctx->pc = 0x80259270u;
    ctx->downcount -= 1;
    // 80259270: bl      0x80259528
    {
            ctx->lr = 0x80259274u;
            goto label_80259528;
    }

label_80259274:
    ctx->pc = 0x80259274u;
    ctx->downcount -= 4;
    // 80259274: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259278:
    ctx->pc = 0x80259278u;
    // 80259278: lwz     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8025927C:
    ctx->pc = 0x8025927Cu;
    // 8025927C: rlwinm. r0, r0, 0, 28, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000008u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80259280:
    ctx->pc = 0x80259280u;
    // 80259280: bc    12, 2, 0x80259288
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80259288;
        }
    }

label_80259284:
    ctx->pc = 0x80259284u;
    ctx->downcount -= 1;
    // 80259284: bl      0x802579CC
    {
            ctx->lr = 0x80259288u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802579CCu;
                return;
            }
            goto label_802579CC;
    }

label_80259288:
    ctx->pc = 0x80259288u;
    ctx->downcount -= 4;
    // 80259288: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8025928C:
    ctx->pc = 0x8025928Cu;
    // 8025928C: lwz     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80259290:
    ctx->pc = 0x80259290u;
    // 80259290: rlwinm. r0, r0, 0, 27, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000010u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80259294:
    ctx->pc = 0x80259294u;
    // 80259294: bc    12, 2, 0x8025929C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8025929C;
        }
    }

label_80259298:
    ctx->pc = 0x80259298u;
    ctx->downcount -= 1;
    // 80259298: bl      0x8025848C
    {
            ctx->lr = 0x8025929Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8025848Cu;
                return;
            }
            goto label_8025848C;
    }

label_8025929C:
    ctx->pc = 0x8025929Cu;
    ctx->downcount -= 4;
    // 8025929C: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802592A0:
    ctx->pc = 0x802592A0u;
    // 802592A0: lwz     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802592A4:
    ctx->pc = 0x802592A4u;
    // 802592A4: rlwinm. r0, r0, 0, 27, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000018u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802592A8:
    ctx->pc = 0x802592A8u;
    // 802592A8: bc    12, 2, 0x802592B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802592B0;
        }
    }

label_802592AC:
    ctx->pc = 0x802592ACu;
    ctx->downcount -= 1;
    // 802592AC: bl      0x80257A20
    {
            ctx->lr = 0x802592B0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80257A20u;
                return;
            }
            goto label_80257A20;
    }

label_802592B0:
    ctx->pc = 0x802592B0u;
    ctx->downcount -= 3;
    // 802592B0: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802592B4:
    ctx->pc = 0x802592B4u;
    // 802592B4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802592B8:
    ctx->pc = 0x802592B8u;
    // 802592B8: stw     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802592BC:
    ctx->pc = 0x802592BCu;
    ctx->downcount -= 4;
    // 802592BC: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802592C0:
    ctx->pc = 0x802592C0u;
    // 802592C0: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802592C4:
    ctx->pc = 0x802592C4u;
    // 802592C4: cmplwi  r0, 0x0000
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

label_802592C8:
    ctx->pc = 0x802592C8u;
    // 802592C8: bc    4, 2, 0x802592D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802592D0;
        }
    }

label_802592CC:
    ctx->pc = 0x802592CCu;
    ctx->downcount -= 1;
    // 802592CC: bl      0x802592FC
    {
            ctx->lr = 0x802592D0u;
            goto label_802592FC;
    }

label_802592D0:
    ctx->pc = 0x802592D0u;
    ctx->downcount -= 12;
    // 802592D0: or   r0, r30, r29
    {
        ctx->gpr[0] = ctx->gpr[30] | ctx->gpr[29];
    }

label_802592D4:
    ctx->pc = 0x802592D4u;
    // 802592D4: lis     r3, -13311
    ctx->gpr[3] = ((u32)(s32)(-13311) << 16);

label_802592D8:
    ctx->pc = 0x802592D8u;
    // 802592D8: stb     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802592DC:
    ctx->pc = 0x802592DCu;
    // 802592DC: sth     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[31]);
    }

label_802592E0:
    ctx->pc = 0x802592E0u;
    // 802592E0: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802592E4:
    ctx->pc = 0x802592E4u;
    // 802592E4: lwz     r31, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_802592E8:
    ctx->pc = 0x802592E8u;
    // 802592E8: lwz     r30, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_802592EC:
    ctx->pc = 0x802592ECu;
    // 802592EC: lwz     r29, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_802592F0:
    ctx->pc = 0x802592F0u;
    // 802592F0: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_802592F4:
    ctx->pc = 0x802592F4u;
    // 802592F4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802592F8:
    ctx->pc = 0x802592F8u;
    // 802592F8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_802592FC:
    ctx->pc = 0x802592FCu;
    ctx->downcount -= 17;
    // 802592FC: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259300:
    ctx->pc = 0x80259300u;
    // 80259300: li      r0, 152
    ctx->gpr[0] = (u32)(s32)(152);

label_80259304:
    ctx->pc = 0x80259304u;
    // 80259304: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_80259308:
    ctx->pc = 0x80259308u;
    // 80259308: lhz     r6, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_8025930C:
    ctx->pc = 0x8025930Cu;
    // 8025930C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80259310:
    ctx->pc = 0x80259310u;
    // 80259310: lhz     r3, 6(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(6);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_80259314:
    ctx->pc = 0x80259314u;
    // 80259314: mullw   r7, r6, r3
    {
        s64 product = (s64)(s32)ctx->gpr[6] * (s64)(s32)ctx->gpr[3];
        ctx->gpr[7] = (u32)product;
    }

label_80259318:
    ctx->pc = 0x80259318u;
    // 80259318: stb     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8025931C:
    ctx->pc = 0x8025931Cu;
    // 8025931C: sth     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_80259320:
    ctx->pc = 0x80259320u;
    // 80259320: addi    r3, r7, 3
    ctx->gpr[3] = ctx->gpr[7] + (u32)(s32)(3);

label_80259324:
    ctx->pc = 0x80259324u;
    // 80259324: cmplwi  r7, 0x0000
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

label_80259328:
    ctx->pc = 0x80259328u;
    // 80259328: rlwinm r3, r3, 30, 2, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 30u) & 0x3FFFFFFFu;
    }

label_8025932C:
    ctx->pc = 0x8025932Cu;
    // 8025932C: bc    4, 1, 0x80259374
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80259374;
        }
    }

label_80259330:
    ctx->pc = 0x80259330u;
    ctx->downcount -= 4;
    // 80259330: rlwinm. r0, r3, 29, 3, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 29u) & 0x1FFFFFFFu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80259334:
    ctx->pc = 0x80259334u;
    // 80259334: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_80259338:
    ctx->pc = 0x80259338u;
    // 80259338: bc    12, 2, 0x80259368
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80259368;
        }
    }

label_8025933C:
    loop_8025933C(ctx);
    if (ctx->pc == 0x80259360u) goto label_80259360;
    return;
label_80259340:
    ctx->pc = 0x80259340u;
    // 80259340: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80259344:
    ctx->pc = 0x80259344u;
    // 80259344: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80259348:
    ctx->pc = 0x80259348u;
    // 80259348: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8025934C:
    ctx->pc = 0x8025934Cu;
    // 8025934C: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80259350:
    ctx->pc = 0x80259350u;
    // 80259350: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80259354:
    ctx->pc = 0x80259354u;
    // 80259354: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80259358:
    ctx->pc = 0x80259358u;
    // 80259358: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8025935C:
    // 8025935C: bc    16, 0, 0x8025933C
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8025933Cu;
                return;
            }
            goto label_8025933C;
        }
    }

label_80259360:
    ctx->pc = 0x80259360u;
    ctx->downcount -= 2;
    // 80259360: andi.   r3, r3, 0x0007
    {
        ctx->gpr[3] = ctx->gpr[3] & 0x0007u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[3];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80259364:
    ctx->pc = 0x80259364u;
    // 80259364: bc    12, 2, 0x80259374
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80259374;
        }
    }

label_80259368:
    ctx->pc = 0x80259368u;
    ctx->downcount -= 2;
    // 80259368: mtctr    r3
    ctx->ctr = ctx->gpr[3];

label_8025936C:
    loop_8025936C(ctx);
    if (ctx->pc == 0x80259374u) goto label_80259374;
    return;
label_80259370:
    // 80259370: bc    16, 0, 0x8025936C
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8025936Cu;
                return;
            }
            goto label_8025936C;
        }
    }

label_80259374:
    ctx->pc = 0x80259374u;
    ctx->downcount -= 4;
    // 80259374: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259378:
    ctx->pc = 0x80259378u;
    // 80259378: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8025937C:
    ctx->pc = 0x8025937Cu;
    // 8025937C: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80259380:
    ctx->pc = 0x80259380u;
    // 80259380: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80259384:
    ctx->pc = 0x80259384u;
    ctx->downcount -= 22;
    // 80259384: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80259388:
    ctx->pc = 0x80259388u;
    // 80259388: rlwinm r6, r4, 16, 0, 15
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[4], 16u) & 0xFFFF0000u;
    }

label_8025938C:
    ctx->pc = 0x8025938Cu;
    // 8025938C: li      r4, 97
    ctx->gpr[4] = (u32)(s32)(97);

label_80259390:
    ctx->pc = 0x80259390u;
    // 80259390: lwz     r0, 124(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(124);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80259394:
    ctx->pc = 0x80259394u;
    // 80259394: addi    r7, r5, 124
    ctx->gpr[7] = ctx->gpr[5] + (u32)(s32)(124);

label_80259398:
    ctx->pc = 0x80259398u;
    // 80259398: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_8025939C:
    ctx->pc = 0x8025939Cu;
    // 8025939C: rlwinm r0, r0, 0, 0, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFF00u;
    }

label_802593A0:
    ctx->pc = 0x802593A0u;
    // 802593A0: rlwimi r0, r3, 0, 24, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[3], 0u);
        ctx->gpr[0] = (ctx->gpr[0] & ~0x000000FFu) | (rot & 0x000000FFu);
    }

label_802593A4:
    ctx->pc = 0x802593A4u;
    // 802593A4: stw     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802593A8:
    ctx->pc = 0x802593A8u;
    // 802593A8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802593AC:
    ctx->pc = 0x802593ACu;
    // 802593AC: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802593B0:
    ctx->pc = 0x802593B0u;
    // 802593B0: addi    r7, r3, 124
    ctx->gpr[7] = ctx->gpr[3] + (u32)(s32)(124);

label_802593B4:
    ctx->pc = 0x802593B4u;
    // 802593B4: lwz     r3, 124(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(124);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802593B8:
    ctx->pc = 0x802593B8u;
    // 802593B8: rlwinm r3, r3, 0, 16, 12
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFF8FFFFu;
    }

label_802593BC:
    ctx->pc = 0x802593BCu;
    // 802593BC: or   r3, r3, r6
    {
        ctx->gpr[3] = ctx->gpr[3] | ctx->gpr[6];
    }

label_802593C0:
    ctx->pc = 0x802593C0u;
    // 802593C0: stw     r3, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_802593C4:
    ctx->pc = 0x802593C4u;
    // 802593C4: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_802593C8:
    ctx->pc = 0x802593C8u;
    // 802593C8: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802593CC:
    ctx->pc = 0x802593CCu;
    // 802593CC: lwz     r3, 124(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(124);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802593D0:
    ctx->pc = 0x802593D0u;
    // 802593D0: stw     r3, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_802593D4:
    ctx->pc = 0x802593D4u;
    // 802593D4: sth     r0, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_802593D8:
    ctx->pc = 0x802593D8u;
    // 802593D8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_802593DC:
    ctx->pc = 0x802593DCu;
    ctx->downcount -= 21;
    // 802593DC: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802593E0:
    ctx->pc = 0x802593E0u;
    // 802593E0: rlwinm r6, r4, 19, 0, 12
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[4], 19u) & 0xFFF80000u;
    }

label_802593E4:
    ctx->pc = 0x802593E4u;
    // 802593E4: lwzu     r0, 124(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(124);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[5] = ea;
    }

label_802593E8:
    ctx->pc = 0x802593E8u;
    // 802593E8: li      r4, 97
    ctx->gpr[4] = (u32)(s32)(97);

label_802593EC:
    ctx->pc = 0x802593ECu;
    // 802593EC: rlwinm r0, r0, 0, 24, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFF00FFu;
    }

label_802593F0:
    ctx->pc = 0x802593F0u;
    // 802593F0: rlwimi r0, r3, 8, 16, 23
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[3], 8u);
        ctx->gpr[0] = (ctx->gpr[0] & ~0x0000FF00u) | (rot & 0x0000FF00u);
    }

label_802593F4:
    ctx->pc = 0x802593F4u;
    // 802593F4: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802593F8:
    ctx->pc = 0x802593F8u;
    // 802593F8: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_802593FC:
    ctx->pc = 0x802593FCu;
    // 802593FC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80259400:
    ctx->pc = 0x80259400u;
    // 80259400: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259404:
    ctx->pc = 0x80259404u;
    // 80259404: addi    r7, r3, 124
    ctx->gpr[7] = ctx->gpr[3] + (u32)(s32)(124);

label_80259408:
    ctx->pc = 0x80259408u;
    // 80259408: lwz     r3, 124(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(124);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8025940C:
    ctx->pc = 0x8025940Cu;
    // 8025940C: rlwinm r3, r3, 0, 13, 9
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFC7FFFFu;
    }

label_80259410:
    ctx->pc = 0x80259410u;
    // 80259410: or   r3, r3, r6
    {
        ctx->gpr[3] = ctx->gpr[3] | ctx->gpr[6];
    }

label_80259414:
    ctx->pc = 0x80259414u;
    // 80259414: stw     r3, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80259418:
    ctx->pc = 0x80259418u;
    // 80259418: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_8025941C:
    ctx->pc = 0x8025941Cu;
    // 8025941C: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80259420:
    ctx->pc = 0x80259420u;
    // 80259420: lwz     r3, 124(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(124);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259424:
    ctx->pc = 0x80259424u;
    // 80259424: stw     r3, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80259428:
    ctx->pc = 0x80259428u;
    // 80259428: sth     r0, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8025942C:
    ctx->pc = 0x8025942Cu;
    // 8025942C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80259430:
    ctx->pc = 0x80259430u;
    ctx->downcount -= 25;
    // 80259430: lwz     r0, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80259434:
    ctx->pc = 0x80259434u;
    // 80259434: rlwinm r7, r3, 2, 0, 29
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0xFFFFFFFCu;
    }

label_80259438:
    ctx->pc = 0x80259438u;
    // 80259438: add   r6, r0, r7
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_8025943C:
    ctx->pc = 0x8025943Cu;
    // 8025943C: lwz     r3, 184(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(184);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259440:
    ctx->pc = 0x80259440u;
    // 80259440: rlwinm r0, r4, 18, 6, 13
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 18u) & 0x03FC0000u;
    }

label_80259444:
    ctx->pc = 0x80259444u;
    // 80259444: rlwinm r4, r5, 19, 5, 12
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[5], 19u) & 0x07F80000u;
    }

label_80259448:
    ctx->pc = 0x80259448u;
    // 80259448: rlwinm r3, r3, 0, 14, 12
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFBFFFFu;
    }

label_8025944C:
    ctx->pc = 0x8025944Cu;
    // 8025944C: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80259450:
    ctx->pc = 0x80259450u;
    // 80259450: stw     r0, 184(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(184);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80259454:
    ctx->pc = 0x80259454u;
    // 80259454: li      r3, 97
    ctx->gpr[3] = (u32)(s32)(97);

label_80259458:
    ctx->pc = 0x80259458u;
    // 80259458: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_8025945C:
    ctx->pc = 0x8025945Cu;
    // 8025945C: lwz     r6, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80259460:
    ctx->pc = 0x80259460u;
    // 80259460: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80259464:
    ctx->pc = 0x80259464u;
    // 80259464: add   r8, r6, r7
    {
        u32 a = ctx->gpr[6];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_80259468:
    ctx->pc = 0x80259468u;
    // 80259468: lwz     r6, 184(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(184);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8025946C:
    ctx->pc = 0x8025946Cu;
    // 8025946C: rlwinm r6, r6, 0, 13, 11
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFFF7FFFFu;
    }

label_80259470:
    ctx->pc = 0x80259470u;
    // 80259470: or   r4, r6, r4
    {
        ctx->gpr[4] = ctx->gpr[6] | ctx->gpr[4];
    }

label_80259474:
    ctx->pc = 0x80259474u;
    // 80259474: stw     r4, 184(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(184);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80259478:
    ctx->pc = 0x80259478u;
    // 80259478: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8025947C:
    ctx->pc = 0x8025947Cu;
    // 8025947C: stb     r3, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_80259480:
    ctx->pc = 0x80259480u;
    // 80259480: add   r3, r4, r7
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80259484:
    ctx->pc = 0x80259484u;
    // 80259484: lwz     r3, 184(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(184);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259488:
    ctx->pc = 0x80259488u;
    // 80259488: stw     r3, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8025948C:
    ctx->pc = 0x8025948Cu;
    // 8025948C: sth     r0, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80259490:
    ctx->pc = 0x80259490u;
    // 80259490: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80259494:
    ctx->pc = 0x80259494u;
    ctx->downcount -= 2;
    // 80259494: cmpwi   r3, 2
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80259498:
    ctx->pc = 0x80259498u;
    // 80259498: bc    12, 2, 0x802594B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_802594B4;
        }
    }

label_8025949C:
    ctx->pc = 0x8025949Cu;
    ctx->downcount -= 1;
    // 8025949C: bc    4, 0, 0x802594B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802594B8;
        }
    }

label_802594A0:
    ctx->pc = 0x802594A0u;
    ctx->downcount -= 2;
    // 802594A0: cmpwi   r3, 1
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

label_802594A4:
    ctx->pc = 0x802594A4u;
    // 802594A4: bc    4, 0, 0x802594AC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802594AC;
        }
    }

label_802594A8:
    ctx->pc = 0x802594A8u;
    ctx->downcount -= 1;
    // 802594A8: b       0x802594B8
    {
            goto label_802594B8;
    }

label_802594AC:
    ctx->pc = 0x802594ACu;
    ctx->downcount -= 2;
    // 802594AC: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_802594B0:
    ctx->pc = 0x802594B0u;
    // 802594B0: b       0x802594B8
    {
            goto label_802594B8;
    }

label_802594B4:
    ctx->pc = 0x802594B4u;
    ctx->downcount -= 1;
    // 802594B4: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_802594B8:
    ctx->pc = 0x802594B8u;
    ctx->downcount -= 11;
    // 802594B8: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802594BC:
    ctx->pc = 0x802594BCu;
    // 802594BC: rlwinm r0, r3, 14, 0, 17
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 14u) & 0xFFFFC000u;
    }

label_802594C0:
    ctx->pc = 0x802594C0u;
    // 802594C0: lwzu     r3, 516(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(516);
        ctx->gpr[3] = mem_read32(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_802594C4:
    ctx->pc = 0x802594C4u;
    // 802594C4: rlwinm r3, r3, 0, 18, 15
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFF3FFFu;
    }

label_802594C8:
    ctx->pc = 0x802594C8u;
    // 802594C8: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802594CC:
    ctx->pc = 0x802594CCu;
    // 802594CC: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802594D0:
    ctx->pc = 0x802594D0u;
    // 802594D0: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802594D4:
    ctx->pc = 0x802594D4u;
    // 802594D4: lwz     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802594D8:
    ctx->pc = 0x802594D8u;
    // 802594D8: ori     r0, r0, 0x0004
    ctx->gpr[0] = ctx->gpr[0] | 0x0004u;

label_802594DC:
    ctx->pc = 0x802594DCu;
    // 802594DC: stw     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802594E0:
    ctx->pc = 0x802594E0u;
    // 802594E0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_802594E4:
    ctx->pc = 0x802594E4u;
    ctx->downcount -= 17;
    // 802594E4: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802594E8:
    ctx->pc = 0x802594E8u;
    // 802594E8: rlwinm r0, r3, 19, 5, 12
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 19u) & 0x07F80000u;
    }

label_802594EC:
    ctx->pc = 0x802594ECu;
    // 802594EC: li      r5, 97
    ctx->gpr[5] = (u32)(s32)(97);

label_802594F0:
    ctx->pc = 0x802594F0u;
    // 802594F0: lwz     r3, 516(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(516);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802594F4:
    ctx->pc = 0x802594F4u;
    // 802594F4: addi    r6, r4, 516
    ctx->gpr[6] = ctx->gpr[4] + (u32)(s32)(516);

label_802594F8:
    ctx->pc = 0x802594F8u;
    // 802594F8: lis     r4, -13311
    ctx->gpr[4] = ((u32)(s32)(-13311) << 16);

label_802594FC:
    ctx->pc = 0x802594FCu;
    // 802594FC: rlwinm r3, r3, 0, 13, 11
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFF7FFFFu;
    }

label_80259500:
    ctx->pc = 0x80259500u;
    // 80259500: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80259504:
    ctx->pc = 0x80259504u;
    // 80259504: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80259508:
    ctx->pc = 0x80259508u;
    // 80259508: lis     r0, -504
    ctx->gpr[0] = ((u32)(s32)(-504) << 16);

label_8025950C:
    ctx->pc = 0x8025950Cu;
    // 8025950C: stb     r5, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

label_80259510:
    ctx->pc = 0x80259510u;
    // 80259510: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259514:
    ctx->pc = 0x80259514u;
    // 80259514: stw     r0, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80259518:
    ctx->pc = 0x80259518u;
    // 80259518: stb     r5, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

label_8025951C:
    ctx->pc = 0x8025951Cu;
    // 8025951C: lwz     r0, 516(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(516);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80259520:
    ctx->pc = 0x80259520u;
    // 80259520: stw     r0, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80259524:
    ctx->pc = 0x80259524u;
    // 80259524: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80259528:
    ctx->pc = 0x80259528u;
    ctx->downcount -= 9;
    // 80259528: li      r0, 97
    ctx->gpr[0] = (u32)(s32)(97);

label_8025952C:
    ctx->pc = 0x8025952Cu;
    // 8025952C: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80259530:
    ctx->pc = 0x80259530u;
    // 80259530: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_80259534:
    ctx->pc = 0x80259534u;
    // 80259534: stb     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80259538:
    ctx->pc = 0x80259538u;
    // 80259538: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8025953C:
    ctx->pc = 0x8025953Cu;
    // 8025953C: lwz     r3, 516(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(516);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259540:
    ctx->pc = 0x80259540u;
    // 80259540: stw     r3, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80259544:
    ctx->pc = 0x80259544u;
    // 80259544: sth     r0, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80259548:
    ctx->pc = 0x80259548u;
    // 80259548: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_8025954C:
    ctx->pc = 0x8025954Cu;
    ctx->downcount -= 48;
    // 8025954C: lwz     r7, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80259550:
    ctx->pc = 0x80259550u;
    // 80259550: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80259554:
    ctx->pc = 0x80259554u;
    // 80259554: rlwinm r4, r4, 10, 6, 21
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 10u) & 0x03FFFC00u;
    }

label_80259558:
    ctx->pc = 0x80259558u;
    // 80259558: stw     r8, 480(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(480);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8025955C:
    ctx->pc = 0x8025955Cu;
    // 8025955C: rlwinm r7, r5, 0, 16, 31
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x0000FFFFu;
    }

label_80259560:
    ctx->pc = 0x80259560u;
    // 80259560: rlwinm r5, r6, 0, 16, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x0000FFFFu;
    }

label_80259564:
    ctx->pc = 0x80259564u;
    // 80259564: lwz     r6, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80259568:
    ctx->pc = 0x80259568u;
    // 80259568: addi    r0, r5, -1
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(-1);

label_8025956C:
    ctx->pc = 0x8025956Cu;
    // 8025956C: rlwinm r5, r3, 0, 16, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x0000FFFFu;
    }

label_80259570:
    ctx->pc = 0x80259570u;
    // 80259570: addi    r9, r6, 480
    ctx->gpr[9] = ctx->gpr[6] + (u32)(s32)(480);

label_80259574:
    ctx->pc = 0x80259574u;
    // 80259574: lwz     r6, 480(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(480);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80259578:
    ctx->pc = 0x80259578u;
    // 80259578: addi    r3, r7, -1
    ctx->gpr[3] = ctx->gpr[7] + (u32)(s32)(-1);

label_8025957C:
    ctx->pc = 0x8025957Cu;
    // 8025957C: rlwinm r6, r6, 0, 0, 21
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFFFFFC00u;
    }

label_80259580:
    ctx->pc = 0x80259580u;
    // 80259580: or   r5, r6, r5
    {
        ctx->gpr[5] = ctx->gpr[6] | ctx->gpr[5];
    }

label_80259584:
    ctx->pc = 0x80259584u;
    // 80259584: stw     r5, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80259588:
    ctx->pc = 0x80259588u;
    // 80259588: rlwinm r0, r0, 10, 0, 21
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 10u) & 0xFFFFFC00u;
    }

label_8025958C:
    ctx->pc = 0x8025958Cu;
    // 8025958C: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80259590:
    ctx->pc = 0x80259590u;
    // 80259590: addi    r6, r5, 480
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(480);

label_80259594:
    ctx->pc = 0x80259594u;
    // 80259594: lwz     r5, 480(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(480);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80259598:
    ctx->pc = 0x80259598u;
    // 80259598: rlwinm r5, r5, 0, 22, 11
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFF003FFu;
    }

label_8025959C:
    ctx->pc = 0x8025959Cu;
    // 8025959C: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_802595A0:
    ctx->pc = 0x802595A0u;
    // 802595A0: stw     r4, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802595A4:
    ctx->pc = 0x802595A4u;
    // 802595A4: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802595A8:
    ctx->pc = 0x802595A8u;
    // 802595A8: addi    r5, r4, 480
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(480);

label_802595AC:
    ctx->pc = 0x802595ACu;
    // 802595AC: lwz     r4, 480(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(480);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802595B0:
    ctx->pc = 0x802595B0u;
    // 802595B0: rlwinm r4, r4, 0, 8, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x00FFFFFFu;
    }

label_802595B4:
    ctx->pc = 0x802595B4u;
    // 802595B4: oris    r4, r4, 0x4900
    ctx->gpr[4] = ctx->gpr[4] | (0x4900u << 16);

label_802595B8:
    ctx->pc = 0x802595B8u;
    // 802595B8: stw     r4, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_802595BC:
    ctx->pc = 0x802595BCu;
    // 802595BC: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802595C0:
    ctx->pc = 0x802595C0u;
    // 802595C0: stw     r8, 484(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(484);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_802595C4:
    ctx->pc = 0x802595C4u;
    // 802595C4: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802595C8:
    ctx->pc = 0x802595C8u;
    // 802595C8: addi    r5, r4, 484
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(484);

label_802595CC:
    ctx->pc = 0x802595CCu;
    // 802595CC: lwz     r4, 484(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(484);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802595D0:
    ctx->pc = 0x802595D0u;
    // 802595D0: rlwinm r4, r4, 0, 0, 21
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFC00u;
    }

label_802595D4:
    ctx->pc = 0x802595D4u;
    // 802595D4: or   r3, r4, r3
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[3];
    }

label_802595D8:
    ctx->pc = 0x802595D8u;
    // 802595D8: stw     r3, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_802595DC:
    ctx->pc = 0x802595DCu;
    // 802595DC: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802595E0:
    ctx->pc = 0x802595E0u;
    // 802595E0: addi    r4, r3, 484
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(484);

label_802595E4:
    ctx->pc = 0x802595E4u;
    // 802595E4: lwz     r3, 484(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(484);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802595E8:
    ctx->pc = 0x802595E8u;
    // 802595E8: rlwinm r3, r3, 0, 22, 11
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFF003FFu;
    }

label_802595EC:
    ctx->pc = 0x802595ECu;
    // 802595EC: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802595F0:
    ctx->pc = 0x802595F0u;
    // 802595F0: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802595F4:
    ctx->pc = 0x802595F4u;
    // 802595F4: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802595F8:
    ctx->pc = 0x802595F8u;
    // 802595F8: lwzu     r0, 484(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(484);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_802595FC:
    ctx->pc = 0x802595FCu;
    // 802595FC: rlwinm r0, r0, 0, 8, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00FFFFFFu;
    }

label_80259600:
    ctx->pc = 0x80259600u;
    // 80259600: oris    r0, r0, 0x4A00
    ctx->gpr[0] = ctx->gpr[0] | (0x4A00u << 16);

label_80259604:
    ctx->pc = 0x80259604u;
    // 80259604: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80259608:
    ctx->pc = 0x80259608u;
    // 80259608: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_8025960C:
    ctx->pc = 0x8025960Cu;
    ctx->downcount -= 48;
    // 8025960C: lwz     r7, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80259610:
    ctx->pc = 0x80259610u;
    // 80259610: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80259614:
    ctx->pc = 0x80259614u;
    // 80259614: rlwinm r4, r4, 10, 6, 21
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 10u) & 0x03FFFC00u;
    }

label_80259618:
    ctx->pc = 0x80259618u;
    // 80259618: stw     r8, 496(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(496);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8025961C:
    ctx->pc = 0x8025961Cu;
    // 8025961C: rlwinm r7, r5, 0, 16, 31
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x0000FFFFu;
    }

label_80259620:
    ctx->pc = 0x80259620u;
    // 80259620: rlwinm r5, r6, 0, 16, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x0000FFFFu;
    }

label_80259624:
    ctx->pc = 0x80259624u;
    // 80259624: lwz     r6, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80259628:
    ctx->pc = 0x80259628u;
    // 80259628: addi    r0, r5, -1
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(-1);

label_8025962C:
    ctx->pc = 0x8025962Cu;
    // 8025962C: rlwinm r5, r3, 0, 16, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x0000FFFFu;
    }

label_80259630:
    ctx->pc = 0x80259630u;
    // 80259630: addi    r9, r6, 496
    ctx->gpr[9] = ctx->gpr[6] + (u32)(s32)(496);

label_80259634:
    ctx->pc = 0x80259634u;
    // 80259634: lwz     r6, 496(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(496);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80259638:
    ctx->pc = 0x80259638u;
    // 80259638: addi    r3, r7, -1
    ctx->gpr[3] = ctx->gpr[7] + (u32)(s32)(-1);

label_8025963C:
    ctx->pc = 0x8025963Cu;
    // 8025963C: rlwinm r6, r6, 0, 0, 21
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFFFFFC00u;
    }

label_80259640:
    ctx->pc = 0x80259640u;
    // 80259640: or   r5, r6, r5
    {
        ctx->gpr[5] = ctx->gpr[6] | ctx->gpr[5];
    }

label_80259644:
    ctx->pc = 0x80259644u;
    // 80259644: stw     r5, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80259648:
    ctx->pc = 0x80259648u;
    // 80259648: rlwinm r0, r0, 10, 0, 21
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 10u) & 0xFFFFFC00u;
    }

label_8025964C:
    ctx->pc = 0x8025964Cu;
    // 8025964C: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80259650:
    ctx->pc = 0x80259650u;
    // 80259650: addi    r6, r5, 496
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(496);

label_80259654:
    ctx->pc = 0x80259654u;
    // 80259654: lwz     r5, 496(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(496);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80259658:
    ctx->pc = 0x80259658u;
    // 80259658: rlwinm r5, r5, 0, 22, 11
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFF003FFu;
    }

label_8025965C:
    ctx->pc = 0x8025965Cu;
    // 8025965C: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_80259660:
    ctx->pc = 0x80259660u;
    // 80259660: stw     r4, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80259664:
    ctx->pc = 0x80259664u;
    // 80259664: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80259668:
    ctx->pc = 0x80259668u;
    // 80259668: addi    r5, r4, 496
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(496);

label_8025966C:
    ctx->pc = 0x8025966Cu;
    // 8025966C: lwz     r4, 496(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(496);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80259670:
    ctx->pc = 0x80259670u;
    // 80259670: rlwinm r4, r4, 0, 8, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x00FFFFFFu;
    }

label_80259674:
    ctx->pc = 0x80259674u;
    // 80259674: oris    r4, r4, 0x4900
    ctx->gpr[4] = ctx->gpr[4] | (0x4900u << 16);

label_80259678:
    ctx->pc = 0x80259678u;
    // 80259678: stw     r4, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8025967C:
    ctx->pc = 0x8025967Cu;
    // 8025967C: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80259680:
    ctx->pc = 0x80259680u;
    // 80259680: stw     r8, 500(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(500);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80259684:
    ctx->pc = 0x80259684u;
    // 80259684: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80259688:
    ctx->pc = 0x80259688u;
    // 80259688: addi    r5, r4, 500
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(500);

label_8025968C:
    ctx->pc = 0x8025968Cu;
    // 8025968C: lwz     r4, 500(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(500);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80259690:
    ctx->pc = 0x80259690u;
    // 80259690: rlwinm r4, r4, 0, 0, 21
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFC00u;
    }

label_80259694:
    ctx->pc = 0x80259694u;
    // 80259694: or   r3, r4, r3
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[3];
    }

label_80259698:
    ctx->pc = 0x80259698u;
    // 80259698: stw     r3, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8025969C:
    ctx->pc = 0x8025969Cu;
    // 8025969C: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802596A0:
    ctx->pc = 0x802596A0u;
    // 802596A0: addi    r4, r3, 500
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(500);

label_802596A4:
    ctx->pc = 0x802596A4u;
    // 802596A4: lwz     r3, 500(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(500);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802596A8:
    ctx->pc = 0x802596A8u;
    // 802596A8: rlwinm r3, r3, 0, 22, 11
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFF003FFu;
    }

label_802596AC:
    ctx->pc = 0x802596ACu;
    // 802596AC: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802596B0:
    ctx->pc = 0x802596B0u;
    // 802596B0: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802596B4:
    ctx->pc = 0x802596B4u;
    // 802596B4: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802596B8:
    ctx->pc = 0x802596B8u;
    // 802596B8: lwzu     r0, 500(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(500);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_802596BC:
    ctx->pc = 0x802596BCu;
    // 802596BC: rlwinm r0, r0, 0, 8, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00FFFFFFu;
    }

label_802596C0:
    ctx->pc = 0x802596C0u;
    // 802596C0: oris    r0, r0, 0x4A00
    ctx->gpr[0] = ctx->gpr[0] | (0x4A00u << 16);

label_802596C4:
    ctx->pc = 0x802596C4u;
    // 802596C4: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802596C8:
    ctx->pc = 0x802596C8u;
    // 802596C8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_802596CC:
    ctx->pc = 0x802596CCu;
    ctx->downcount -= 17;
    // 802596CC: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802596D0:
    ctx->pc = 0x802596D0u;
    // 802596D0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802596D4:
    ctx->pc = 0x802596D4u;
    // 802596D4: stw     r0, 488(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(488);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802596D8:
    ctx->pc = 0x802596D8u;
    // 802596D8: rlwinm r0, r3, 1, 16, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 1u) & 0x0000FFFEu;
    }

label_802596DC:
    ctx->pc = 0x802596DCu;
    // 802596DC: srawi r0, r0, 5
    {
        u32 sh = 5u;
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

label_802596E0:
    ctx->pc = 0x802596E0u;
    // 802596E0: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802596E4:
    ctx->pc = 0x802596E4u;
    // 802596E4: addi    r4, r3, 488
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(488);

label_802596E8:
    ctx->pc = 0x802596E8u;
    // 802596E8: lwz     r3, 488(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(488);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802596EC:
    ctx->pc = 0x802596ECu;
    // 802596EC: rlwinm r3, r3, 0, 0, 21
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFC00u;
    }

label_802596F0:
    ctx->pc = 0x802596F0u;
    // 802596F0: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_802596F4:
    ctx->pc = 0x802596F4u;
    // 802596F4: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802596F8:
    ctx->pc = 0x802596F8u;
    // 802596F8: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802596FC:
    ctx->pc = 0x802596FCu;
    // 802596FC: lwzu     r0, 488(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(488);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_80259700:
    ctx->pc = 0x80259700u;
    // 80259700: rlwinm r0, r0, 0, 8, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00FFFFFFu;
    }

label_80259704:
    ctx->pc = 0x80259704u;
    // 80259704: oris    r0, r0, 0x4D00
    ctx->gpr[0] = ctx->gpr[0] | (0x4D00u << 16);

label_80259708:
    ctx->pc = 0x80259708u;
    // 80259708: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8025970C:
    ctx->pc = 0x8025970Cu;
    // 8025970C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80259710:
    ctx->pc = 0x80259710u;
    ctx->downcount -= 14;
    // 80259710: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80259714:
    ctx->pc = 0x80259714u;
    // 80259714: cmpwi   r5, 19
    {
        s32 val_a = (s32)(ctx->gpr[5]);
        s32 val_b = (s32)(19);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80259718:
    ctx->pc = 0x80259718u;
    // 80259718: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8025971C:
    ctx->pc = 0x8025971Cu;
    // 8025971C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80259720:
    ctx->pc = 0x80259720u;
    // 80259720: addi    r8, r3, 0
    ctx->gpr[8] = ctx->gpr[3] + (u32)(s32)(0);

label_80259724:
    ctx->pc = 0x80259724u;
    // 80259724: stwu     r1, -48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-48);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80259728:
    ctx->pc = 0x80259728u;
    // 80259728: stw     r31, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8025972C:
    ctx->pc = 0x8025972Cu;
    // 8025972C: rlwinm r31, r5, 0, 28, 31
    {
        ctx->gpr[31] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x0000000Fu;
    }

label_80259730:
    ctx->pc = 0x80259730u;
    // 80259730: stw     r30, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80259734:
    ctx->pc = 0x80259734u;
    // 80259734: addi    r30, r6, 0
    ctx->gpr[30] = ctx->gpr[6] + (u32)(s32)(0);

label_80259738:
    ctx->pc = 0x80259738u;
    // 80259738: lwz     r7, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8025973C:
    ctx->pc = 0x8025973Cu;
    // 8025973C: stb     r0, 512(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(512);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80259740:
    ctx->pc = 0x80259740u;
    // 80259740: addi    r7, r4, 0
    ctx->gpr[7] = ctx->gpr[4] + (u32)(s32)(0);

label_80259744:
    ctx->pc = 0x80259744u;
    // 80259744: bc    4, 2, 0x8025974C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8025974C;
        }
    }

label_80259748:
    ctx->pc = 0x80259748u;
    ctx->downcount -= 1;
    // 80259748: li      r31, 11
    ctx->gpr[31] = (u32)(s32)(11);

label_8025974C:
    ctx->pc = 0x8025974Cu;
    ctx->downcount -= 2;
    // 8025974C: cmpwi   r5, 38
    {
        s32 val_a = (s32)(ctx->gpr[5]);
        s32 val_b = (s32)(38);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80259750:
    ctx->pc = 0x80259750u;
    // 80259750: bc    12, 2, 0x8025976C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8025976C;
        }
    }

label_80259754:
    ctx->pc = 0x80259754u;
    ctx->downcount -= 1;
    // 80259754: bc    4, 0, 0x80259788
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80259788;
        }
    }

label_80259758:
    ctx->pc = 0x80259758u;
    ctx->downcount -= 2;
    // 80259758: cmpwi   r5, 4
    {
        s32 val_a = (s32)(ctx->gpr[5]);
        s32 val_b = (s32)(4);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8025975C:
    ctx->pc = 0x8025975Cu;
    // 8025975C: bc    4, 0, 0x80259788
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80259788;
        }
    }

label_80259760:
    ctx->pc = 0x80259760u;
    ctx->downcount -= 2;
    // 80259760: cmpwi   r5, 0
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

label_80259764:
    ctx->pc = 0x80259764u;
    // 80259764: bc    4, 0, 0x8025976C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8025976C;
        }
    }

label_80259768:
    ctx->pc = 0x80259768u;
    ctx->downcount -= 1;
    // 80259768: b       0x80259788
    {
            goto label_80259788;
    }

label_8025976C:
    ctx->pc = 0x8025976Cu;
    ctx->downcount -= 7;
    // 8025976C: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259770:
    ctx->pc = 0x80259770u;
    // 80259770: lwzu     r0, 508(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(508);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_80259774:
    ctx->pc = 0x80259774u;
    // 80259774: rlwinm r0, r0, 0, 17, 14
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFE7FFFu;
    }

label_80259778:
    ctx->pc = 0x80259778u;
    // 80259778: oris    r0, r0, 0x0001
    ctx->gpr[0] = ctx->gpr[0] | (0x0001u << 16);

label_8025977C:
    ctx->pc = 0x8025977Cu;
    // 8025977C: ori     r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] | 0x8000u;

label_80259780:
    ctx->pc = 0x80259780u;
    // 80259780: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80259784:
    ctx->pc = 0x80259784u;
    // 80259784: b       0x8025979C
    {
            goto label_8025979C;
    }

label_80259788:
    ctx->pc = 0x80259788u;
    ctx->downcount -= 5;
    // 80259788: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8025978C:
    ctx->pc = 0x8025978Cu;
    // 8025978C: lwzu     r0, 508(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(508);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_80259790:
    ctx->pc = 0x80259790u;
    // 80259790: rlwinm r0, r0, 0, 17, 14
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFE7FFFu;
    }

label_80259794:
    ctx->pc = 0x80259794u;
    // 80259794: oris    r0, r0, 0x0001
    ctx->gpr[0] = ctx->gpr[0] | (0x0001u << 16);

label_80259798:
    ctx->pc = 0x80259798u;
    // 80259798: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8025979C:
    ctx->pc = 0x8025979Cu;
    ctx->downcount -= 20;
    // 8025979C: rlwinm r4, r5, 0, 27, 27
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x00000010u;
    }

label_802597A0:
    ctx->pc = 0x802597A0u;
    // 802597A0: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802597A4:
    ctx->pc = 0x802597A4u;
    // 802597A4: addi    r0, r4, -16
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(-16);

label_802597A8:
    ctx->pc = 0x802597A8u;
    // 802597A8: cntlzw r0, r0
    {
        u32 v = ctx->gpr[0];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_802597AC:
    ctx->pc = 0x802597ACu;
    // 802597AC: rlwinm r0, r0, 27, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x000000FFu;
    }

label_802597B0:
    ctx->pc = 0x802597B0u;
    // 802597B0: stb     r0, 512(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(512);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_802597B4:
    ctx->pc = 0x802597B4u;
    // 802597B4: addi    r3, r5, 0
    ctx->gpr[3] = ctx->gpr[5] + (u32)(s32)(0);

label_802597B8:
    ctx->pc = 0x802597B8u;
    // 802597B8: addi    r5, r7, 0
    ctx->gpr[5] = ctx->gpr[7] + (u32)(s32)(0);

label_802597BC:
    ctx->pc = 0x802597BCu;
    // 802597BC: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802597C0:
    ctx->pc = 0x802597C0u;
    // 802597C0: addi    r7, r1, 28
    ctx->gpr[7] = ctx->gpr[1] + (u32)(s32)(28);

label_802597C4:
    ctx->pc = 0x802597C4u;
    // 802597C4: lwz     r0, 508(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(508);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802597C8:
    ctx->pc = 0x802597C8u;
    // 802597C8: addi    r6, r4, 508
    ctx->gpr[6] = ctx->gpr[4] + (u32)(s32)(508);

label_802597CC:
    ctx->pc = 0x802597CCu;
    // 802597CC: addi    r4, r8, 0
    ctx->gpr[4] = ctx->gpr[8] + (u32)(s32)(0);

label_802597D0:
    ctx->pc = 0x802597D0u;
    // 802597D0: rlwinm r0, r0, 0, 29, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFF7u;
    }

label_802597D4:
    ctx->pc = 0x802597D4u;
    // 802597D4: rlwimi r0, r31, 0, 28, 28
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[31], 0u);
        ctx->gpr[0] = (ctx->gpr[0] & ~0x00000008u) | (rot & 0x00000008u);
    }

label_802597D8:
    ctx->pc = 0x802597D8u;
    // 802597D8: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802597DC:
    ctx->pc = 0x802597DCu;
    // 802597DC: rlwinm r31, r31, 0, 29, 31
    {
        ctx->gpr[31] = dolrecomp_rotl32(ctx->gpr[31], 0u) & 0x00000007u;
    }

label_802597E0:
    ctx->pc = 0x802597E0u;
    // 802597E0: addi    r6, r1, 32
    ctx->gpr[6] = ctx->gpr[1] + (u32)(s32)(32);

label_802597E4:
    ctx->pc = 0x802597E4u;
    // 802597E4: addi    r8, r1, 24
    ctx->gpr[8] = ctx->gpr[1] + (u32)(s32)(24);

label_802597E8:
    ctx->pc = 0x802597E8u;
    // 802597E8: bl      0x8025ABB8
    {
            ctx->lr = 0x802597ECu;
            ctx->pc = 0x8025ABB8u;
            return;
    }

label_802597EC:
    ctx->pc = 0x802597ECu;
    ctx->downcount -= 42;
    // 802597EC: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802597F0:
    ctx->pc = 0x802597F0u;
    // 802597F0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_802597F4:
    ctx->pc = 0x802597F4u;
    // 802597F4: stw     r0, 504(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(504);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802597F8:
    ctx->pc = 0x802597F8u;
    // 802597F8: rlwinm r3, r30, 9, 15, 22
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[30], 9u) & 0x0001FE00u;
    }

label_802597FC:
    ctx->pc = 0x802597FCu;
    // 802597FC: rlwinm r0, r31, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[31], 4u) & 0xFFFFFFF0u;
    }

label_80259800:
    ctx->pc = 0x80259800u;
    // 80259800: lwz     r5, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80259804:
    ctx->pc = 0x80259804u;
    // 80259804: lwz     r4, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80259808:
    ctx->pc = 0x80259808u;
    // 80259808: lwz     r6, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8025980C:
    ctx->pc = 0x8025980Cu;
    // 8025980C: mullw   r4, r5, r4
    {
        s64 product = (s64)(s32)ctx->gpr[5] * (s64)(s32)ctx->gpr[4];
        ctx->gpr[4] = (u32)product;
    }

label_80259810:
    ctx->pc = 0x80259810u;
    // 80259810: lwzu     r5, 504(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(504);
        ctx->gpr[5] = mem_read32(ctx, ea);
        ctx->gpr[6] = ea;
    }

label_80259814:
    ctx->pc = 0x80259814u;
    // 80259814: rlwinm r5, r5, 0, 0, 21
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFC00u;
    }

label_80259818:
    ctx->pc = 0x80259818u;
    // 80259818: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_8025981C:
    ctx->pc = 0x8025981Cu;
    // 8025981C: stw     r4, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80259820:
    ctx->pc = 0x80259820u;
    // 80259820: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80259824:
    ctx->pc = 0x80259824u;
    // 80259824: addi    r5, r4, 504
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(504);

label_80259828:
    ctx->pc = 0x80259828u;
    // 80259828: lwz     r4, 504(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(504);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8025982C:
    ctx->pc = 0x8025982Cu;
    // 8025982C: rlwinm r4, r4, 0, 8, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x00FFFFFFu;
    }

label_80259830:
    ctx->pc = 0x80259830u;
    // 80259830: oris    r4, r4, 0x4D00
    ctx->gpr[4] = ctx->gpr[4] | (0x4D00u << 16);

label_80259834:
    ctx->pc = 0x80259834u;
    // 80259834: stw     r4, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80259838:
    ctx->pc = 0x80259838u;
    // 80259838: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8025983C:
    ctx->pc = 0x8025983Cu;
    // 8025983C: addi    r5, r4, 508
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(508);

label_80259840:
    ctx->pc = 0x80259840u;
    // 80259840: lwz     r4, 508(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(508);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80259844:
    ctx->pc = 0x80259844u;
    // 80259844: rlwinm r4, r4, 0, 23, 21
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFDFFu;
    }

label_80259848:
    ctx->pc = 0x80259848u;
    // 80259848: or   r3, r4, r3
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[3];
    }

label_8025984C:
    ctx->pc = 0x8025984Cu;
    // 8025984C: stw     r3, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80259850:
    ctx->pc = 0x80259850u;
    // 80259850: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259854:
    ctx->pc = 0x80259854u;
    // 80259854: addi    r4, r3, 508
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(508);

label_80259858:
    ctx->pc = 0x80259858u;
    // 80259858: lwz     r3, 508(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(508);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8025985C:
    ctx->pc = 0x8025985Cu;
    // 8025985C: rlwinm r3, r3, 0, 28, 24
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFF8Fu;
    }

label_80259860:
    ctx->pc = 0x80259860u;
    // 80259860: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80259864:
    ctx->pc = 0x80259864u;
    // 80259864: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80259868:
    ctx->pc = 0x80259868u;
    // 80259868: lwz     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8025986C:
    ctx->pc = 0x8025986Cu;
    // 8025986C: lwz     r31, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80259870:
    ctx->pc = 0x80259870u;
    // 80259870: lwz     r30, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80259874:
    ctx->pc = 0x80259874u;
    // 80259874: addi    r1, r1, 48
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(48);

label_80259878:
    ctx->pc = 0x80259878u;
    // 80259878: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8025987C:
    ctx->pc = 0x8025987Cu;
    // 8025987C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80259880:
    ctx->pc = 0x80259880u;
    ctx->downcount -= 11;
    // 80259880: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80259884:
    ctx->pc = 0x80259884u;
    // 80259884: rlwinm r0, r3, 12, 0, 19
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 12u) & 0xFFFFF000u;
    }

label_80259888:
    ctx->pc = 0x80259888u;
    // 80259888: lwzu     r3, 492(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(492);
        ctx->gpr[3] = mem_read32(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_8025988C:
    ctx->pc = 0x8025988Cu;
    // 8025988C: rlwinm r3, r3, 0, 20, 17
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFCFFFu;
    }

label_80259890:
    ctx->pc = 0x80259890u;
    // 80259890: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80259894:
    ctx->pc = 0x80259894u;
    // 80259894: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80259898:
    ctx->pc = 0x80259898u;
    // 80259898: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8025989C:
    ctx->pc = 0x8025989Cu;
    // 8025989C: lwzu     r0, 508(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(508);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_802598A0:
    ctx->pc = 0x802598A0u;
    // 802598A0: rlwinm r0, r0, 0, 20, 17
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFCFFFu;
    }

label_802598A4:
    ctx->pc = 0x802598A4u;
    // 802598A4: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802598A8:
    ctx->pc = 0x802598A8u;
    // 802598A8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_802598AC:
    ctx->pc = 0x802598ACu;
    ctx->downcount -= 31;
    // 802598AC: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_802598B0:
    ctx->pc = 0x802598B0u;
    // 802598B0: rlwinm r4, r3, 0, 31, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00000001u;
    }

label_802598B4:
    ctx->pc = 0x802598B4u;
    // 802598B4: addi    r0, r4, -1
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(-1);

label_802598B8:
    ctx->pc = 0x802598B8u;
    // 802598B8: lwz     r4, 492(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(492);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_802598BC:
    ctx->pc = 0x802598BCu;
    // 802598BC: addi    r6, r5, 492
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(492);

label_802598C0:
    ctx->pc = 0x802598C0u;
    // 802598C0: cntlzw r0, r0
    {
        u32 v = ctx->gpr[0];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_802598C4:
    ctx->pc = 0x802598C4u;
    // 802598C4: rlwinm r5, r4, 0, 0, 30
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFFFEu;
    }

label_802598C8:
    ctx->pc = 0x802598C8u;
    // 802598C8: rlwinm r4, r0, 27, 24, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x000000FFu;
    }

label_802598CC:
    ctx->pc = 0x802598CCu;
    // 802598CC: or   r0, r5, r4
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[4];
    }

label_802598D0:
    ctx->pc = 0x802598D0u;
    // 802598D0: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802598D4:
    ctx->pc = 0x802598D4u;
    // 802598D4: rlwinm r3, r3, 0, 30, 30
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00000002u;
    }

label_802598D8:
    ctx->pc = 0x802598D8u;
    // 802598D8: addi    r0, r3, -2
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-2);

label_802598DC:
    ctx->pc = 0x802598DCu;
    // 802598DC: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802598E0:
    ctx->pc = 0x802598E0u;
    // 802598E0: cntlzw r0, r0
    {
        u32 v = ctx->gpr[0];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_802598E4:
    ctx->pc = 0x802598E4u;
    // 802598E4: rlwinm r6, r0, 28, 23, 30
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[0], 28u) & 0x000001FEu;
    }

label_802598E8:
    ctx->pc = 0x802598E8u;
    // 802598E8: addi    r5, r3, 492
    ctx->gpr[5] = ctx->gpr[3] + (u32)(s32)(492);

label_802598EC:
    ctx->pc = 0x802598ECu;
    // 802598EC: lwz     r3, 492(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(492);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_802598F0:
    ctx->pc = 0x802598F0u;
    // 802598F0: rlwinm r0, r3, 0, 31, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFFDu;
    }

label_802598F4:
    ctx->pc = 0x802598F4u;
    // 802598F4: or   r0, r0, r6
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[6];
    }

label_802598F8:
    ctx->pc = 0x802598F8u;
    // 802598F8: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_802598FC:
    ctx->pc = 0x802598FCu;
    // 802598FC: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259900:
    ctx->pc = 0x80259900u;
    // 80259900: lwzu     r0, 508(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(508);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_80259904:
    ctx->pc = 0x80259904u;
    // 80259904: rlwinm r0, r0, 0, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFEu;
    }

label_80259908:
    ctx->pc = 0x80259908u;
    // 80259908: or   r0, r0, r4
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[4];
    }

label_8025990C:
    ctx->pc = 0x8025990Cu;
    // 8025990C: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80259910:
    ctx->pc = 0x80259910u;
    // 80259910: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259914:
    ctx->pc = 0x80259914u;
    // 80259914: lwzu     r0, 508(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(508);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_80259918:
    ctx->pc = 0x80259918u;
    // 80259918: rlwinm r0, r0, 0, 31, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFDu;
    }

label_8025991C:
    ctx->pc = 0x8025991Cu;
    // 8025991C: or   r0, r0, r6
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[6];
    }

label_80259920:
    ctx->pc = 0x80259920u;
    // 80259920: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80259924:
    ctx->pc = 0x80259924u;
    // 80259924: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80259928:
    ctx->pc = 0x80259928u;
    ctx->downcount -= 22;
    // 80259928: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8025992C:
    ctx->pc = 0x8025992Cu;
    // 8025992C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80259930:
    ctx->pc = 0x80259930u;
    // 80259930: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80259934:
    ctx->pc = 0x80259934u;
    // 80259934: lfs     f0, 4528(r2)
    if (!ppc_fp_available_inline(ctx, 0x80259934u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4528);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80259938:
    ctx->pc = 0x80259938u;
    // 80259938: fdivs   f1, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x80259938u)) return;
    ppc_fdivs(ctx, 1, 0, 1);

label_8025993C:
    ctx->pc = 0x8025993Cu;
    // 8025993C: bl      0x80286924
    {
            ctx->lr = 0x80259940u;
            ctx->pc = 0x80286924u;
            return;
    }

label_80259940:
    ctx->pc = 0x80259940u;
    ctx->downcount -= 68;
    // 80259940: rlwinm r6, r3, 0, 23, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000001FFu;
    }

label_80259944:
    ctx->pc = 0x80259944u;
    // 80259944: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80259948:
    ctx->pc = 0x80259948u;
    // 80259948: li      r0, 97
    ctx->gpr[0] = (u32)(s32)(97);

label_8025994C:
    ctx->pc = 0x8025994Cu;
    // 8025994C: lis     r3, -13311
    ctx->gpr[3] = ((u32)(s32)(-13311) << 16);

label_80259950:
    ctx->pc = 0x80259950u;
    // 80259950: stb     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80259954:
    ctx->pc = 0x80259954u;
    // 80259954: oris    r0, r6, 0x4E00
    ctx->gpr[0] = ctx->gpr[6] | (0x4E00u << 16);

label_80259958:
    ctx->pc = 0x80259958u;
    // 80259958: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8025995C:
    ctx->pc = 0x8025995Cu;
    // 8025995C: stw     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80259960:
    ctx->pc = 0x80259960u;
    // 80259960: subfic  r3, r6, 256
    {
        u64 res = (u64)(u32)(s32)(256) + (u64)(~ctx->gpr[6]) + 1u;
        ctx->gpr[3] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_80259964:
    ctx->pc = 0x80259964u;
    // 80259964: addic   r0, r3, -1
    {
        u64 a = ctx->gpr[3];
        u64 b = (u32)(s32)(-1);
        u64 res = a + b;
        ctx->gpr[0] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_80259968:
    ctx->pc = 0x80259968u;
    // 80259968: sth     r5, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[5]);
    }

label_8025996C:
    ctx->pc = 0x8025996Cu;
    // 8025996C: subfe   r0, r0, r3
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[3];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80259970:
    ctx->pc = 0x80259970u;
    // 80259970: rlwinm r0, r0, 10, 14, 21
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 10u) & 0x0003FC00u;
    }

label_80259974:
    ctx->pc = 0x80259974u;
    // 80259974: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259978:
    ctx->pc = 0x80259978u;
    // 80259978: cmplwi  r6, 0x0080
    {
        u32 val_a = (u32)(ctx->gpr[6]);
        u32 val_b = (u32)(0x0080u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8025997C:
    ctx->pc = 0x8025997Cu;
    // 8025997C: addi    r4, r6, 0
    ctx->gpr[4] = ctx->gpr[6] + (u32)(s32)(0);

label_80259980:
    ctx->pc = 0x80259980u;
    // 80259980: addi    r5, r3, 492
    ctx->gpr[5] = ctx->gpr[3] + (u32)(s32)(492);

label_80259984:
    ctx->pc = 0x80259984u;
    // 80259984: lwz     r3, 492(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(492);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259988:
    ctx->pc = 0x80259988u;
    // 80259988: rlwinm r3, r3, 0, 22, 20
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFBFFu;
    }

label_8025998C:
    ctx->pc = 0x8025998Cu;
    // 8025998C: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80259990:
    ctx->pc = 0x80259990u;
    // 80259990: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80259994:
    ctx->pc = 0x80259994u;
    // 80259994: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259998:
    ctx->pc = 0x80259998u;
    // 80259998: lwz     r0, 484(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(484);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8025999C:
    ctx->pc = 0x8025999Cu;
    // 8025999C: rlwinm r5, r0, 22, 22, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[0], 22u) & 0x000003FFu;
    }

label_802599A0:
    ctx->pc = 0x802599A0u;
    // 802599A0: rlwinm r0, r0, 30, 14, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 30u) & 0x0003FF00u;
    }

label_802599A4:
    ctx->pc = 0x802599A4u;
    // 802599A4: divwu   r3, r0, r6
    {
        u32 divisor = ctx->gpr[6];
        ctx->gpr[3] = divisor == 0 ? 0u : ctx->gpr[0] / divisor;
    }

label_802599A8:
    ctx->pc = 0x802599A8u;
    // 802599A8: addi    r5, r5, 1
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(1);

label_802599AC:
    ctx->pc = 0x802599ACu;
    // 802599AC: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_802599B0:
    ctx->pc = 0x802599B0u;
    // 802599B0: bc    4, 1, 0x802599E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802599E0;
        }
    }

label_802599B4:
    ctx->pc = 0x802599B4u;
    ctx->downcount -= 2;
    // 802599B4: cmplwi  r6, 0x0100
    {
        u32 val_a = (u32)(ctx->gpr[6]);
        u32 val_b = (u32)(0x0100u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802599B8:
    ctx->pc = 0x802599B8u;
    // 802599B8: bc    4, 0, 0x802599E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802599E0;
        }
    }

label_802599BC:
    ctx->pc = 0x802599BCu;
    ctx->downcount -= 1;
    // 802599BC: b       0x802599C4
    {
            goto label_802599C4;
    }

label_802599C0:
    loop_802599C0(ctx);
    if (ctx->pc == 0x802599CCu) goto label_802599CC;
    return;
label_802599C4:
    ctx->downcount -= 2;
    // 802599C4: rlwinm. r0, r4, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802599C8:
    // 802599C8: bc    12, 2, 0x802599C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x802599C0u;
                return;
            }
            goto label_802599C0;
        }
    }

label_802599CC:
    ctx->pc = 0x802599CCu;
    ctx->downcount -= 47;
    // 802599CC: divwu   r0, r5, r4
    {
        u32 divisor = ctx->gpr[4];
        ctx->gpr[0] = divisor == 0 ? 0u : ctx->gpr[5] / divisor;
    }

label_802599D0:
    ctx->pc = 0x802599D0u;
    // 802599D0: mullw   r0, r0, r4
    {
        s64 product = (s64)(s32)ctx->gpr[0] * (s64)(s32)ctx->gpr[4];
        ctx->gpr[0] = (u32)product;
    }

label_802599D4:
    ctx->pc = 0x802599D4u;
    // 802599D4: subf.   r0, r0, r5
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[5];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_802599D8:
    ctx->pc = 0x802599D8u;
    // 802599D8: bc    4, 2, 0x802599E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802599E0;
        }
    }

label_802599DC:
    ctx->pc = 0x802599DCu;
    ctx->downcount -= 1;
    // 802599DC: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_802599E0:
    ctx->pc = 0x802599E0u;
    ctx->downcount -= 2;
    // 802599E0: cmplwi  r3, 0x0400
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0400u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_802599E4:
    ctx->pc = 0x802599E4u;
    // 802599E4: bc    4, 1, 0x802599EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_802599EC;
        }
    }

label_802599E8:
    ctx->pc = 0x802599E8u;
    ctx->downcount -= 1;
    // 802599E8: li      r3, 1024
    ctx->gpr[3] = (u32)(s32)(1024);

label_802599EC:
    ctx->pc = 0x802599ECu;
    ctx->downcount -= 5;
    // 802599EC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_802599F0:
    ctx->pc = 0x802599F0u;
    // 802599F0: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_802599F4:
    ctx->pc = 0x802599F4u;
    // 802599F4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_802599F8:
    ctx->pc = 0x802599F8u;
    // 802599F8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_802599FC:
    ctx->pc = 0x802599FCu;
    ctx->downcount -= 26;
    // 802599FC: rlwinm r0, r4, 0, 8, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x00FFFFFFu;
    }

label_80259A00:
    ctx->pc = 0x80259A00u;
    // 80259A00: lbz     r4, 3(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(3);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_80259A04:
    ctx->pc = 0x80259A04u;
    // 80259A04: lbz     r5, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_80259A08:
    ctx->pc = 0x80259A08u;
    // 80259A08: li      r6, 97
    ctx->gpr[6] = (u32)(s32)(97);

label_80259A0C:
    ctx->pc = 0x80259A0Cu;
    // 80259A0C: rlwinm r7, r4, 8, 0, 23
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[4], 8u) & 0xFFFFFF00u;
    }

label_80259A10:
    ctx->pc = 0x80259A10u;
    // 80259A10: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80259A14:
    ctx->pc = 0x80259A14u;
    // 80259A14: rlwimi r7, r5, 0, 24, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[5], 0u);
        ctx->gpr[7] = (ctx->gpr[7] & ~0x000000FFu) | (rot & 0x000000FFu);
    }

label_80259A18:
    ctx->pc = 0x80259A18u;
    // 80259A18: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_80259A1C:
    ctx->pc = 0x80259A1Cu;
    // 80259A1C: rlwinm r7, r7, 0, 8, 31
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0x00FFFFFFu;
    }

label_80259A20:
    ctx->pc = 0x80259A20u;
    // 80259A20: stb     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_80259A24:
    ctx->pc = 0x80259A24u;
    // 80259A24: oris    r7, r7, 0x4F00
    ctx->gpr[7] = ctx->gpr[7] | (0x4F00u << 16);

label_80259A28:
    ctx->pc = 0x80259A28u;
    // 80259A28: stw     r7, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80259A2C:
    ctx->pc = 0x80259A2Cu;
    // 80259A2C: oris    r7, r0, 0x5100
    ctx->gpr[7] = ctx->gpr[0] | (0x5100u << 16);

label_80259A30:
    ctx->pc = 0x80259A30u;
    // 80259A30: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80259A34:
    ctx->pc = 0x80259A34u;
    // 80259A34: lbz     r8, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        ctx->gpr[8] = mem_read8(ctx, ea);
    }

label_80259A38:
    ctx->pc = 0x80259A38u;
    // 80259A38: lbz     r3, 1(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_80259A3C:
    ctx->pc = 0x80259A3Cu;
    // 80259A3C: rlwinm r3, r3, 8, 0, 23
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 8u) & 0xFFFFFF00u;
    }

label_80259A40:
    ctx->pc = 0x80259A40u;
    // 80259A40: stb     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_80259A44:
    ctx->pc = 0x80259A44u;
    // 80259A44: rlwimi r3, r8, 0, 24, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[8], 0u);
        ctx->gpr[3] = (ctx->gpr[3] & ~0x000000FFu) | (rot & 0x000000FFu);
    }

label_80259A48:
    ctx->pc = 0x80259A48u;
    // 80259A48: rlwinm r3, r3, 0, 8, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00FFFFFFu;
    }

label_80259A4C:
    ctx->pc = 0x80259A4Cu;
    // 80259A4C: oris    r3, r3, 0x5000
    ctx->gpr[3] = ctx->gpr[3] | (0x5000u << 16);

label_80259A50:
    ctx->pc = 0x80259A50u;
    // 80259A50: stw     r3, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80259A54:
    ctx->pc = 0x80259A54u;
    // 80259A54: stb     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_80259A58:
    ctx->pc = 0x80259A58u;
    // 80259A58: stw     r7, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80259A5C:
    ctx->pc = 0x80259A5Cu;
    // 80259A5C: sth     r0, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80259A60:
    ctx->pc = 0x80259A60u;
    // 80259A60: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80259A64:
    ctx->pc = 0x80259A64u;
    ctx->downcount -= 14;
    // 80259A64: stwu     r1, -80(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-80);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80259A68:
    ctx->pc = 0x80259A68u;
    // 80259A68: rlwinm. r0, r3, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000000FFu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80259A6C:
    ctx->pc = 0x80259A6Cu;
    // 80259A6C: stmw     r23, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        for (u32 r = 23; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80259A70:
    ctx->pc = 0x80259A70u;
    // 80259A70: bc    12, 2, 0x80259B98
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80259B98;
        }
    }

label_80259A74:
    ctx->pc = 0x80259A74u;
    ctx->downcount -= 73;
    // 80259A74: lbz     r0, 1(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(1);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80259A78:
    ctx->pc = 0x80259A78u;
    // 80259A78: lbz     r3, 7(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(7);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_80259A7C:
    ctx->pc = 0x80259A7Cu;
    // 80259A7C: rlwinm r30, r0, 4, 0, 27
    {
        ctx->gpr[30] = dolrecomp_rotl32(ctx->gpr[0], 4u) & 0xFFFFFFF0u;
    }

label_80259A80:
    ctx->pc = 0x80259A80u;
    // 80259A80: lbz     r8, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[8] = mem_read8(ctx, ea);
    }

label_80259A84:
    ctx->pc = 0x80259A84u;
    // 80259A84: lbz     r0, 19(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(19);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80259A88:
    ctx->pc = 0x80259A88u;
    // 80259A88: rlwinm r25, r3, 4, 0, 27
    {
        ctx->gpr[25] = dolrecomp_rotl32(ctx->gpr[3], 4u) & 0xFFFFFFF0u;
    }

label_80259A8C:
    ctx->pc = 0x80259A8Cu;
    // 80259A8C: lbz     r10, 6(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(6);
        ctx->gpr[10] = mem_read8(ctx, ea);
    }

label_80259A90:
    ctx->pc = 0x80259A90u;
    // 80259A90: rlwimi r30, r8, 0, 28, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[8], 0u);
        ctx->gpr[30] = (ctx->gpr[30] & ~0x0000000Fu) | (rot & 0x0000000Fu);
    }

label_80259A94:
    ctx->pc = 0x80259A94u;
    // 80259A94: lbz     r11, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        ctx->gpr[11] = mem_read8(ctx, ea);
    }

label_80259A98:
    ctx->pc = 0x80259A98u;
    // 80259A98: lbz     r7, 13(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(13);
        ctx->gpr[7] = mem_read8(ctx, ea);
    }

label_80259A9C:
    ctx->pc = 0x80259A9Cu;
    // 80259A9C: rlwimi r25, r10, 0, 28, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[10], 0u);
        ctx->gpr[25] = (ctx->gpr[25] & ~0x0000000Fu) | (rot & 0x0000000Fu);
    }

label_80259AA0:
    ctx->pc = 0x80259AA0u;
    // 80259AA0: rlwinm r27, r11, 8, 0, 23
    {
        ctx->gpr[27] = dolrecomp_rotl32(ctx->gpr[11], 8u) & 0xFFFFFF00u;
    }

label_80259AA4:
    ctx->pc = 0x80259AA4u;
    // 80259AA4: lbz     r9, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read8(ctx, ea);
    }

label_80259AA8:
    ctx->pc = 0x80259AA8u;
    // 80259AA8: lbz     r3, 14(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(14);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_80259AAC:
    ctx->pc = 0x80259AACu;
    // 80259AAC: rlwinm r26, r9, 8, 0, 23
    {
        ctx->gpr[26] = dolrecomp_rotl32(ctx->gpr[9], 8u) & 0xFFFFFF00u;
    }

label_80259AB0:
    ctx->pc = 0x80259AB0u;
    // 80259AB0: lbz     r28, 3(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(3);
        ctx->gpr[28] = mem_read8(ctx, ea);
    }

label_80259AB4:
    ctx->pc = 0x80259AB4u;
    // 80259AB4: rlwimi r27, r30, 0, 24, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[30], 0u);
        ctx->gpr[27] = (ctx->gpr[27] & ~0x000000FFu) | (rot & 0x000000FFu);
    }

label_80259AB8:
    ctx->pc = 0x80259AB8u;
    // 80259AB8: lbz     r9, 16(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read8(ctx, ea);
    }

label_80259ABC:
    ctx->pc = 0x80259ABCu;
    // 80259ABC: rlwinm r23, r7, 4, 0, 27
    {
        ctx->gpr[23] = dolrecomp_rotl32(ctx->gpr[7], 4u) & 0xFFFFFFF0u;
    }

label_80259AC0:
    ctx->pc = 0x80259AC0u;
    // 80259AC0: lbz     r12, 12(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        ctx->gpr[12] = mem_read8(ctx, ea);
    }

label_80259AC4:
    ctx->pc = 0x80259AC4u;
    // 80259AC4: lbz     r7, 21(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(21);
        ctx->gpr[7] = mem_read8(ctx, ea);
    }

label_80259AC8:
    ctx->pc = 0x80259AC8u;
    // 80259AC8: rlwinm r24, r3, 8, 0, 23
    {
        ctx->gpr[24] = dolrecomp_rotl32(ctx->gpr[3], 8u) & 0xFFFFFF00u;
    }

label_80259ACC:
    ctx->pc = 0x80259ACCu;
    // 80259ACC: rlwimi r23, r12, 0, 28, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[12], 0u);
        ctx->gpr[23] = (ctx->gpr[23] & ~0x0000000Fu) | (rot & 0x0000000Fu);
    }

label_80259AD0:
    ctx->pc = 0x80259AD0u;
    // 80259AD0: lbz     r29, 18(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(18);
        ctx->gpr[29] = mem_read8(ctx, ea);
    }

label_80259AD4:
    ctx->pc = 0x80259AD4u;
    // 80259AD4: rlwinm r0, r0, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 4u) & 0xFFFFFFF0u;
    }

label_80259AD8:
    ctx->pc = 0x80259AD8u;
    // 80259AD8: rlwimi r0, r29, 0, 28, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[29], 0u);
        ctx->gpr[0] = (ctx->gpr[0] & ~0x0000000Fu) | (rot & 0x0000000Fu);
    }

label_80259ADC:
    ctx->pc = 0x80259ADCu;
    // 80259ADC: lbz     r8, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        ctx->gpr[8] = mem_read8(ctx, ea);
    }

label_80259AE0:
    ctx->pc = 0x80259AE0u;
    // 80259AE0: rlwinm r28, r28, 12, 0, 19
    {
        ctx->gpr[28] = dolrecomp_rotl32(ctx->gpr[28], 12u) & 0xFFFFF000u;
    }

label_80259AE4:
    ctx->pc = 0x80259AE4u;
    // 80259AE4: lbz     r31, 9(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(9);
        ctx->gpr[31] = mem_read8(ctx, ea);
    }

label_80259AE8:
    ctx->pc = 0x80259AE8u;
    // 80259AE8: rlwimi r28, r27, 0, 20, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[27], 0u);
        ctx->gpr[28] = (ctx->gpr[28] & ~0x00000FFFu) | (rot & 0x00000FFFu);
    }

label_80259AEC:
    ctx->pc = 0x80259AECu;
    // 80259AEC: lbz     r29, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[29] = mem_read8(ctx, ea);
    }

label_80259AF0:
    ctx->pc = 0x80259AF0u;
    // 80259AF0: rlwimi r24, r23, 0, 24, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[23], 0u);
        ctx->gpr[24] = (ctx->gpr[24] & ~0x000000FFu) | (rot & 0x000000FFu);
    }

label_80259AF4:
    ctx->pc = 0x80259AF4u;
    // 80259AF4: lbz     r10, 15(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(15);
        ctx->gpr[10] = mem_read8(ctx, ea);
    }

label_80259AF8:
    ctx->pc = 0x80259AF8u;
    // 80259AF8: rlwinm r23, r8, 8, 0, 23
    {
        ctx->gpr[23] = dolrecomp_rotl32(ctx->gpr[8], 8u) & 0xFFFFFF00u;
    }

label_80259AFC:
    ctx->pc = 0x80259AFCu;
    // 80259AFC: lbz     r12, 10(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(10);
        ctx->gpr[12] = mem_read8(ctx, ea);
    }

label_80259B00:
    ctx->pc = 0x80259B00u;
    // 80259B00: rlwimi r26, r25, 0, 24, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[25], 0u);
        ctx->gpr[26] = (ctx->gpr[26] & ~0x000000FFu) | (rot & 0x000000FFu);
    }

label_80259B04:
    ctx->pc = 0x80259B04u;
    // 80259B04: lbz     r3, 22(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(22);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_80259B08:
    ctx->pc = 0x80259B08u;
    // 80259B08: rlwinm r25, r10, 12, 0, 19
    {
        ctx->gpr[25] = dolrecomp_rotl32(ctx->gpr[10], 12u) & 0xFFFFF000u;
    }

label_80259B0C:
    ctx->pc = 0x80259B0Cu;
    // 80259B0C: lbz     r30, 5(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(5);
        ctx->gpr[30] = mem_read8(ctx, ea);
    }

label_80259B10:
    ctx->pc = 0x80259B10u;
    // 80259B10: rlwimi r23, r0, 0, 24, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[0], 0u);
        ctx->gpr[23] = (ctx->gpr[23] & ~0x000000FFu) | (rot & 0x000000FFu);
    }

label_80259B14:
    ctx->pc = 0x80259B14u;
    // 80259B14: lbz     r0, 23(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(23);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80259B18:
    ctx->pc = 0x80259B18u;
    // 80259B18: rlwinm r27, r31, 12, 0, 19
    {
        ctx->gpr[27] = dolrecomp_rotl32(ctx->gpr[31], 12u) & 0xFFFFF000u;
    }

label_80259B1C:
    ctx->pc = 0x80259B1Cu;
    // 80259B1C: lbz     r11, 11(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(11);
        ctx->gpr[11] = mem_read8(ctx, ea);
    }

label_80259B20:
    ctx->pc = 0x80259B20u;
    // 80259B20: lbz     r8, 17(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(17);
        ctx->gpr[8] = mem_read8(ctx, ea);
    }

label_80259B24:
    ctx->pc = 0x80259B24u;
    // 80259B24: rlwinm r4, r29, 16, 0, 15
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[29], 16u) & 0xFFFF0000u;
    }

label_80259B28:
    ctx->pc = 0x80259B28u;
    // 80259B28: rlwinm r7, r7, 12, 0, 19
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[7], 12u) & 0xFFFFF000u;
    }

label_80259B2C:
    ctx->pc = 0x80259B2Cu;
    // 80259B2C: rlwinm r10, r12, 16, 0, 15
    {
        ctx->gpr[10] = dolrecomp_rotl32(ctx->gpr[12], 16u) & 0xFFFF0000u;
    }

label_80259B30:
    ctx->pc = 0x80259B30u;
    // 80259B30: rlwimi r27, r26, 0, 20, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[26], 0u);
        ctx->gpr[27] = (ctx->gpr[27] & ~0x00000FFFu) | (rot & 0x00000FFFu);
    }

label_80259B34:
    ctx->pc = 0x80259B34u;
    // 80259B34: rlwinm r12, r3, 16, 0, 15
    {
        ctx->gpr[12] = dolrecomp_rotl32(ctx->gpr[3], 16u) & 0xFFFF0000u;
    }

label_80259B38:
    ctx->pc = 0x80259B38u;
    // 80259B38: rlwimi r7, r23, 0, 20, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[23], 0u);
        ctx->gpr[7] = (ctx->gpr[7] & ~0x00000FFFu) | (rot & 0x00000FFFu);
    }

label_80259B3C:
    ctx->pc = 0x80259B3Cu;
    // 80259B3C: rlwimi r4, r28, 0, 16, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[28], 0u);
        ctx->gpr[4] = (ctx->gpr[4] & ~0x0000FFFFu) | (rot & 0x0000FFFFu);
    }

label_80259B40:
    ctx->pc = 0x80259B40u;
    // 80259B40: rlwinm r3, r30, 20, 0, 11
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[30], 20u) & 0xFFF00000u;
    }

label_80259B44:
    ctx->pc = 0x80259B44u;
    // 80259B44: rlwimi r25, r24, 0, 20, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[24], 0u);
        ctx->gpr[25] = (ctx->gpr[25] & ~0x00000FFFu) | (rot & 0x00000FFFu);
    }

label_80259B48:
    ctx->pc = 0x80259B48u;
    // 80259B48: rlwinm r9, r9, 16, 0, 15
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 16u) & 0xFFFF0000u;
    }

label_80259B4C:
    ctx->pc = 0x80259B4Cu;
    // 80259B4C: rlwimi r10, r27, 0, 16, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[27], 0u);
        ctx->gpr[10] = (ctx->gpr[10] & ~0x0000FFFFu) | (rot & 0x0000FFFFu);
    }

label_80259B50:
    ctx->pc = 0x80259B50u;
    // 80259B50: rlwimi r3, r4, 0, 12, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[4], 0u);
        ctx->gpr[3] = (ctx->gpr[3] & ~0x000FFFFFu) | (rot & 0x000FFFFFu);
    }

label_80259B54:
    ctx->pc = 0x80259B54u;
    // 80259B54: rlwimi r12, r7, 0, 16, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[7], 0u);
        ctx->gpr[12] = (ctx->gpr[12] & ~0x0000FFFFu) | (rot & 0x0000FFFFu);
    }

label_80259B58:
    ctx->pc = 0x80259B58u;
    // 80259B58: rlwinm r7, r3, 0, 8, 31
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00FFFFFFu;
    }

label_80259B5C:
    ctx->pc = 0x80259B5Cu;
    // 80259B5C: rlwinm r3, r11, 20, 0, 11
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[11], 20u) & 0xFFF00000u;
    }

label_80259B60:
    ctx->pc = 0x80259B60u;
    // 80259B60: rlwimi r3, r10, 0, 12, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[10], 0u);
        ctx->gpr[3] = (ctx->gpr[3] & ~0x000FFFFFu) | (rot & 0x000FFFFFu);
    }

label_80259B64:
    ctx->pc = 0x80259B64u;
    // 80259B64: rlwinm r4, r3, 0, 8, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00FFFFFFu;
    }

label_80259B68:
    ctx->pc = 0x80259B68u;
    // 80259B68: rlwinm r3, r8, 20, 0, 11
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[8], 20u) & 0xFFF00000u;
    }

label_80259B6C:
    ctx->pc = 0x80259B6Cu;
    // 80259B6C: rlwimi r9, r25, 0, 16, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[25], 0u);
        ctx->gpr[9] = (ctx->gpr[9] & ~0x0000FFFFu) | (rot & 0x0000FFFFu);
    }

label_80259B70:
    ctx->pc = 0x80259B70u;
    // 80259B70: rlwimi r3, r9, 0, 12, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[9], 0u);
        ctx->gpr[3] = (ctx->gpr[3] & ~0x000FFFFFu) | (rot & 0x000FFFFFu);
    }

label_80259B74:
    ctx->pc = 0x80259B74u;
    // 80259B74: rlwinm r0, r0, 20, 0, 11
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 20u) & 0xFFF00000u;
    }

label_80259B78:
    ctx->pc = 0x80259B78u;
    // 80259B78: rlwimi r0, r12, 0, 12, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[12], 0u);
        ctx->gpr[0] = (ctx->gpr[0] & ~0x000FFFFFu) | (rot & 0x000FFFFFu);
    }

label_80259B7C:
    ctx->pc = 0x80259B7Cu;
    // 80259B7C: rlwinm r3, r3, 0, 8, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00FFFFFFu;
    }

label_80259B80:
    ctx->pc = 0x80259B80u;
    // 80259B80: rlwinm r0, r0, 0, 8, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00FFFFFFu;
    }

label_80259B84:
    ctx->pc = 0x80259B84u;
    // 80259B84: oris    r8, r7, 0x0100
    ctx->gpr[8] = ctx->gpr[7] | (0x0100u << 16);

label_80259B88:
    ctx->pc = 0x80259B88u;
    // 80259B88: oris    r7, r4, 0x0200
    ctx->gpr[7] = ctx->gpr[4] | (0x0200u << 16);

label_80259B8C:
    ctx->pc = 0x80259B8Cu;
    // 80259B8C: oris    r9, r3, 0x0300
    ctx->gpr[9] = ctx->gpr[3] | (0x0300u << 16);

label_80259B90:
    ctx->pc = 0x80259B90u;
    // 80259B90: oris    r10, r0, 0x0400
    ctx->gpr[10] = ctx->gpr[0] | (0x0400u << 16);

label_80259B94:
    ctx->pc = 0x80259B94u;
    // 80259B94: b       0x80259BB8
    {
            goto label_80259BB8;
    }

label_80259B98:
    ctx->pc = 0x80259B98u;
    ctx->downcount -= 8;
    // 80259B98: lis     r8, 358
    ctx->gpr[8] = ((u32)(s32)(358) << 16);

label_80259B9C:
    ctx->pc = 0x80259B9Cu;
    // 80259B9C: lis     r7, 614
    ctx->gpr[7] = ((u32)(s32)(614) << 16);

label_80259BA0:
    ctx->pc = 0x80259BA0u;
    // 80259BA0: lis     r4, 870
    ctx->gpr[4] = ((u32)(s32)(870) << 16);

label_80259BA4:
    ctx->pc = 0x80259BA4u;
    // 80259BA4: lis     r3, 1126
    ctx->gpr[3] = ((u32)(s32)(1126) << 16);

label_80259BA8:
    ctx->pc = 0x80259BA8u;
    // 80259BA8: addi    r8, r8, 26214
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(26214);

label_80259BAC:
    ctx->pc = 0x80259BACu;
    // 80259BAC: addi    r7, r7, 26214
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(26214);

label_80259BB0:
    ctx->pc = 0x80259BB0u;
    // 80259BB0: addi    r9, r4, 26214
    ctx->gpr[9] = ctx->gpr[4] + (u32)(s32)(26214);

label_80259BB4:
    ctx->pc = 0x80259BB4u;
    // 80259BB4: addi    r10, r3, 26214
    ctx->gpr[10] = ctx->gpr[3] + (u32)(s32)(26214);

label_80259BB8:
    ctx->pc = 0x80259BB8u;
    ctx->downcount -= 12;
    // 80259BB8: li      r4, 97
    ctx->gpr[4] = (u32)(s32)(97);

label_80259BBC:
    ctx->pc = 0x80259BBCu;
    // 80259BBC: lis     r3, -13311
    ctx->gpr[3] = ((u32)(s32)(-13311) << 16);

label_80259BC0:
    ctx->pc = 0x80259BC0u;
    // 80259BC0: stb     r4, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_80259BC4:
    ctx->pc = 0x80259BC4u;
    // 80259BC4: rlwinm. r0, r5, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x000000FFu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80259BC8:
    ctx->pc = 0x80259BC8u;
    // 80259BC8: stw     r8, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80259BCC:
    ctx->pc = 0x80259BCCu;
    // 80259BCC: stb     r4, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_80259BD0:
    ctx->pc = 0x80259BD0u;
    // 80259BD0: stw     r7, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80259BD4:
    ctx->pc = 0x80259BD4u;
    // 80259BD4: stb     r4, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_80259BD8:
    ctx->pc = 0x80259BD8u;
    // 80259BD8: stw     r9, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80259BDC:
    ctx->pc = 0x80259BDCu;
    // 80259BDC: stb     r4, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_80259BE0:
    ctx->pc = 0x80259BE0u;
    // 80259BE0: stw     r10, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80259BE4:
    ctx->pc = 0x80259BE4u;
    // 80259BE4: bc    12, 2, 0x80259C4C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80259C4C;
        }
    }

label_80259BE8:
    ctx->pc = 0x80259BE8u;
    ctx->downcount -= 25;
    // 80259BE8: lbz     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80259BEC:
    ctx->pc = 0x80259BECu;
    // 80259BEC: lbz     r3, 1(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(1);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_80259BF0:
    ctx->pc = 0x80259BF0u;
    // 80259BF0: oris    r5, r0, 0x5300
    ctx->gpr[5] = ctx->gpr[0] | (0x5300u << 16);

label_80259BF4:
    ctx->pc = 0x80259BF4u;
    // 80259BF4: lbz     r0, 4(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80259BF8:
    ctx->pc = 0x80259BF8u;
    // 80259BF8: lbz     r4, 2(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(2);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_80259BFC:
    ctx->pc = 0x80259BFCu;
    // 80259BFC: rlwinm r7, r5, 0, 26, 19
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFF03Fu;
    }

label_80259C00:
    ctx->pc = 0x80259C00u;
    // 80259C00: rlwinm r5, r3, 6, 0, 25
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[3], 6u) & 0xFFFFFFC0u;
    }

label_80259C04:
    ctx->pc = 0x80259C04u;
    // 80259C04: lbz     r3, 5(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(5);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_80259C08:
    ctx->pc = 0x80259C08u;
    // 80259C08: or   r7, r7, r5
    {
        ctx->gpr[7] = ctx->gpr[7] | ctx->gpr[5];
    }

label_80259C0C:
    ctx->pc = 0x80259C0Cu;
    // 80259C0C: oris    r8, r0, 0x5400
    ctx->gpr[8] = ctx->gpr[0] | (0x5400u << 16);

label_80259C10:
    ctx->pc = 0x80259C10u;
    // 80259C10: lbz     r5, 3(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(3);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_80259C14:
    ctx->pc = 0x80259C14u;
    // 80259C14: lbz     r0, 6(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(6);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80259C18:
    ctx->pc = 0x80259C18u;
    // 80259C18: rlwinm r6, r7, 0, 20, 13
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFFFC0FFFu;
    }

label_80259C1C:
    ctx->pc = 0x80259C1Cu;
    // 80259C1C: rlwinm r4, r4, 12, 0, 19
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 12u) & 0xFFFFF000u;
    }

label_80259C20:
    ctx->pc = 0x80259C20u;
    // 80259C20: or   r6, r6, r4
    {
        ctx->gpr[6] = ctx->gpr[6] | ctx->gpr[4];
    }

label_80259C24:
    ctx->pc = 0x80259C24u;
    // 80259C24: rlwinm r4, r8, 0, 26, 19
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[8], 0u) & 0xFFFFF03Fu;
    }

label_80259C28:
    ctx->pc = 0x80259C28u;
    // 80259C28: rlwinm r3, r3, 6, 0, 25
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 6u) & 0xFFFFFFC0u;
    }

label_80259C2C:
    ctx->pc = 0x80259C2Cu;
    // 80259C2C: or   r3, r4, r3
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[3];
    }

label_80259C30:
    ctx->pc = 0x80259C30u;
    // 80259C30: rlwinm r6, r6, 0, 14, 7
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFF03FFFFu;
    }

label_80259C34:
    ctx->pc = 0x80259C34u;
    // 80259C34: rlwinm r4, r5, 18, 0, 13
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[5], 18u) & 0xFFFC0000u;
    }

label_80259C38:
    ctx->pc = 0x80259C38u;
    // 80259C38: rlwinm r3, r3, 0, 20, 13
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFC0FFFu;
    }

label_80259C3C:
    ctx->pc = 0x80259C3Cu;
    // 80259C3C: rlwinm r0, r0, 12, 0, 19
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 12u) & 0xFFFFF000u;
    }

label_80259C40:
    ctx->pc = 0x80259C40u;
    // 80259C40: or   r6, r6, r4
    {
        ctx->gpr[6] = ctx->gpr[6] | ctx->gpr[4];
    }

label_80259C44:
    ctx->pc = 0x80259C44u;
    // 80259C44: or   r7, r3, r0
    {
        ctx->gpr[7] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80259C48:
    ctx->pc = 0x80259C48u;
    // 80259C48: b       0x80259C5C
    {
            goto label_80259C5C;
    }

label_80259C4C:
    ctx->pc = 0x80259C4Cu;
    ctx->downcount -= 4;
    // 80259C4C: lis     r4, 21337
    ctx->gpr[4] = ((u32)(s32)(21337) << 16);

label_80259C50:
    ctx->pc = 0x80259C50u;
    // 80259C50: lis     r3, 21504
    ctx->gpr[3] = ((u32)(s32)(21504) << 16);

label_80259C54:
    ctx->pc = 0x80259C54u;
    // 80259C54: addi    r6, r4, 20480
    ctx->gpr[6] = ctx->gpr[4] + (u32)(s32)(20480);

label_80259C58:
    ctx->pc = 0x80259C58u;
    // 80259C58: addi    r7, r3, 21
    ctx->gpr[7] = ctx->gpr[3] + (u32)(s32)(21);

label_80259C5C:
    ctx->pc = 0x80259C5Cu;
    ctx->downcount -= 22;
    // 80259C5C: li      r5, 97
    ctx->gpr[5] = (u32)(s32)(97);

label_80259C60:
    ctx->pc = 0x80259C60u;
    // 80259C60: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259C64:
    ctx->pc = 0x80259C64u;
    // 80259C64: lis     r4, -13311
    ctx->gpr[4] = ((u32)(s32)(-13311) << 16);

label_80259C68:
    ctx->pc = 0x80259C68u;
    // 80259C68: stb     r5, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

label_80259C6C:
    ctx->pc = 0x80259C6Cu;
    // 80259C6C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80259C70:
    ctx->pc = 0x80259C70u;
    // 80259C70: stw     r6, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80259C74:
    ctx->pc = 0x80259C74u;
    // 80259C74: stb     r5, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

label_80259C78:
    ctx->pc = 0x80259C78u;
    // 80259C78: stw     r7, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80259C7C:
    ctx->pc = 0x80259C7Cu;
    // 80259C7C: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80259C80:
    ctx->pc = 0x80259C80u;
    // 80259C80: lmw     r23, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        for (u32 r = 23; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80259C84:
    ctx->pc = 0x80259C84u;
    // 80259C84: addi    r1, r1, 80
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(80);

label_80259C88:
    ctx->pc = 0x80259C88u;
    // 80259C88: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80259C8C:
    ctx->pc = 0x80259C8Cu;
    ctx->downcount -= 7;
    // 80259C8C: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80259C90:
    ctx->pc = 0x80259C90u;
    // 80259C90: rlwinm r0, r3, 7, 0, 24
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 7u) & 0xFFFFFF80u;
    }

label_80259C94:
    ctx->pc = 0x80259C94u;
    // 80259C94: lwzu     r3, 492(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(492);
        ctx->gpr[3] = mem_read32(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_80259C98:
    ctx->pc = 0x80259C98u;
    // 80259C98: rlwinm r3, r3, 0, 25, 22
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFE7Fu;
    }

label_80259C9C:
    ctx->pc = 0x80259C9Cu;
    // 80259C9C: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80259CA0:
    ctx->pc = 0x80259CA0u;
    // 80259CA0: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80259CA4:
    ctx->pc = 0x80259CA4u;
    // 80259CA4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80259CA8:
    ctx->pc = 0x80259CA8u;
    ctx->downcount -= 2;
    // 80259CA8: rlwinm. r0, r4, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x000000FFu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80259CAC:
    ctx->pc = 0x80259CACu;
    // 80259CAC: bc    12, 2, 0x80259CE8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80259CE8;
        }
    }

label_80259CB0:
    ctx->pc = 0x80259CB0u;
    ctx->downcount -= 14;
    // 80259CB0: lwz     r7, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80259CB4:
    ctx->pc = 0x80259CB4u;
    // 80259CB4: li      r0, 97
    ctx->gpr[0] = (u32)(s32)(97);

label_80259CB8:
    ctx->pc = 0x80259CB8u;
    // 80259CB8: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_80259CBC:
    ctx->pc = 0x80259CBCu;
    // 80259CBC: lwz     r6, 472(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(472);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80259CC0:
    ctx->pc = 0x80259CC0u;
    // 80259CC0: rlwinm r6, r6, 0, 0, 30
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFFFFFFFEu;
    }

label_80259CC4:
    ctx->pc = 0x80259CC4u;
    // 80259CC4: stb     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80259CC8:
    ctx->pc = 0x80259CC8u;
    // 80259CC8: ori     r6, r6, 0x0001
    ctx->gpr[6] = ctx->gpr[6] | 0x0001u;

label_80259CCC:
    ctx->pc = 0x80259CCCu;
    // 80259CCC: rlwinm r6, r6, 0, 31, 27
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFFFFFFF1u;
    }

label_80259CD0:
    ctx->pc = 0x80259CD0u;
    // 80259CD0: ori     r6, r6, 0x000E
    ctx->gpr[6] = ctx->gpr[6] | 0x000Eu;

label_80259CD4:
    ctx->pc = 0x80259CD4u;
    // 80259CD4: stw     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80259CD8:
    ctx->pc = 0x80259CD8u;
    // 80259CD8: lwz     r6, 464(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(464);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80259CDC:
    ctx->pc = 0x80259CDCu;
    // 80259CDC: stb     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80259CE0:
    ctx->pc = 0x80259CE0u;
    // 80259CE0: rlwinm r0, r6, 0, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFFFFFFFCu;
    }

label_80259CE4:
    ctx->pc = 0x80259CE4u;
    // 80259CE4: stw     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80259CE8:
    ctx->pc = 0x80259CE8u;
    ctx->downcount -= 3;
    // 80259CE8: rlwinm. r0, r4, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x000000FFu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80259CEC:
    ctx->pc = 0x80259CECu;
    // 80259CEC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80259CF0:
    ctx->pc = 0x80259CF0u;
    // 80259CF0: bc    4, 2, 0x80259D08
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80259D08;
        }
    }

label_80259CF4:
    ctx->pc = 0x80259CF4u;
    ctx->downcount -= 5;
    // 80259CF4: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80259CF8:
    ctx->pc = 0x80259CF8u;
    // 80259CF8: lwz     r5, 476(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(476);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80259CFC:
    ctx->pc = 0x80259CFCu;
    // 80259CFC: rlwinm r5, r5, 0, 29, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x00000007u;
    }

label_80259D00:
    ctx->pc = 0x80259D00u;
    // 80259D00: cmplwi  r5, 0x0003
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(0x0003u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80259D04:
    ctx->pc = 0x80259D04u;
    // 80259D04: bc    4, 2, 0x80259D34
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80259D34;
        }
    }

label_80259D08:
    ctx->pc = 0x80259D08u;
    ctx->downcount -= 5;
    // 80259D08: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80259D0C:
    ctx->pc = 0x80259D0Cu;
    // 80259D0C: lwz     r7, 476(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(476);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80259D10:
    ctx->pc = 0x80259D10u;
    // 80259D10: rlwinm r5, r7, 26, 31, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[7], 26u) & 0x00000001u;
    }

label_80259D14:
    ctx->pc = 0x80259D14u;
    // 80259D14: cmplwi  r5, 0x0001
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(0x0001u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80259D18:
    ctx->pc = 0x80259D18u;
    // 80259D18: bc    4, 2, 0x80259D34
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80259D34;
        }
    }

label_80259D1C:
    ctx->pc = 0x80259D1Cu;
    ctx->downcount -= 6;
    // 80259D1C: li      r0, 97
    ctx->gpr[0] = (u32)(s32)(97);

label_80259D20:
    ctx->pc = 0x80259D20u;
    // 80259D20: lis     r6, -13311
    ctx->gpr[6] = ((u32)(s32)(-13311) << 16);

label_80259D24:
    ctx->pc = 0x80259D24u;
    // 80259D24: stb     r0, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80259D28:
    ctx->pc = 0x80259D28u;
    // 80259D28: rlwinm r5, r7, 0, 26, 24
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFFFFFFBFu;
    }

label_80259D2C:
    ctx->pc = 0x80259D2Cu;
    // 80259D2C: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80259D30:
    ctx->pc = 0x80259D30u;
    // 80259D30: stw     r5, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80259D34:
    ctx->pc = 0x80259D34u;
    ctx->downcount -= 39;
    // 80259D34: li      r9, 97
    ctx->gpr[9] = (u32)(s32)(97);

label_80259D38:
    ctx->pc = 0x80259D38u;
    // 80259D38: lwz     r7, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80259D3C:
    ctx->pc = 0x80259D3Cu;
    // 80259D3C: lis     r8, -13311
    ctx->gpr[8] = ((u32)(s32)(-13311) << 16);

label_80259D40:
    ctx->pc = 0x80259D40u;
    // 80259D40: stb     r9, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[9]);
    }

label_80259D44:
    ctx->pc = 0x80259D44u;
    // 80259D44: rlwinm r3, r3, 27, 8, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 27u) & 0x00FFFFFFu;
    }

label_80259D48:
    ctx->pc = 0x80259D48u;
    // 80259D48: oris    r10, r3, 0x4B00
    ctx->gpr[10] = ctx->gpr[3] | (0x4B00u << 16);

label_80259D4C:
    ctx->pc = 0x80259D4Cu;
    // 80259D4C: lwz     r6, 480(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(480);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80259D50:
    ctx->pc = 0x80259D50u;
    // 80259D50: rlwinm. r5, r4, 0, 24, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x000000FFu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[5];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80259D54:
    ctx->pc = 0x80259D54u;
    // 80259D54: rlwinm r3, r4, 11, 13, 20
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[4], 11u) & 0x0007F800u;
    }

label_80259D58:
    ctx->pc = 0x80259D58u;
    // 80259D58: stw     r6, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80259D5C:
    ctx->pc = 0x80259D5Cu;
    // 80259D5C: stb     r9, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[9]);
    }

label_80259D60:
    ctx->pc = 0x80259D60u;
    // 80259D60: lwz     r4, 484(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(484);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80259D64:
    ctx->pc = 0x80259D64u;
    // 80259D64: stw     r4, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80259D68:
    ctx->pc = 0x80259D68u;
    // 80259D68: stb     r9, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[9]);
    }

label_80259D6C:
    ctx->pc = 0x80259D6Cu;
    // 80259D6C: lwz     r4, 488(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(488);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80259D70:
    ctx->pc = 0x80259D70u;
    // 80259D70: stw     r4, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80259D74:
    ctx->pc = 0x80259D74u;
    // 80259D74: stb     r9, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[9]);
    }

label_80259D78:
    ctx->pc = 0x80259D78u;
    // 80259D78: stw     r10, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80259D7C:
    ctx->pc = 0x80259D7Cu;
    // 80259D7C: lwz     r4, 492(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(492);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80259D80:
    ctx->pc = 0x80259D80u;
    // 80259D80: rlwinm r4, r4, 0, 21, 19
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFF7FFu;
    }

label_80259D84:
    ctx->pc = 0x80259D84u;
    // 80259D84: or   r3, r4, r3
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[3];
    }

label_80259D88:
    ctx->pc = 0x80259D88u;
    // 80259D88: stw     r3, 492(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(492);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80259D8C:
    ctx->pc = 0x80259D8Cu;
    // 80259D8C: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259D90:
    ctx->pc = 0x80259D90u;
    // 80259D90: addi    r4, r3, 492
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(492);

label_80259D94:
    ctx->pc = 0x80259D94u;
    // 80259D94: lwz     r3, 492(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(492);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259D98:
    ctx->pc = 0x80259D98u;
    // 80259D98: rlwinm r3, r3, 0, 18, 16
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFBFFFu;
    }

label_80259D9C:
    ctx->pc = 0x80259D9Cu;
    // 80259D9C: ori     r3, r3, 0x4000
    ctx->gpr[3] = ctx->gpr[3] | 0x4000u;

label_80259DA0:
    ctx->pc = 0x80259DA0u;
    // 80259DA0: stw     r3, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80259DA4:
    ctx->pc = 0x80259DA4u;
    // 80259DA4: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259DA8:
    ctx->pc = 0x80259DA8u;
    // 80259DA8: addi    r4, r3, 492
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(492);

label_80259DAC:
    ctx->pc = 0x80259DACu;
    // 80259DAC: lwz     r3, 492(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(492);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259DB0:
    ctx->pc = 0x80259DB0u;
    // 80259DB0: rlwinm r3, r3, 0, 8, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00FFFFFFu;
    }

label_80259DB4:
    ctx->pc = 0x80259DB4u;
    // 80259DB4: oris    r3, r3, 0x5200
    ctx->gpr[3] = ctx->gpr[3] | (0x5200u << 16);

label_80259DB8:
    ctx->pc = 0x80259DB8u;
    // 80259DB8: stw     r3, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80259DBC:
    ctx->pc = 0x80259DBCu;
    // 80259DBC: stb     r9, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[9]);
    }

label_80259DC0:
    ctx->pc = 0x80259DC0u;
    // 80259DC0: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80259DC4:
    ctx->pc = 0x80259DC4u;
    // 80259DC4: lwz     r3, 492(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(492);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259DC8:
    ctx->pc = 0x80259DC8u;
    // 80259DC8: stw     r3, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80259DCC:
    ctx->pc = 0x80259DCCu;
    // 80259DCC: bc    12, 2, 0x80259DE8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80259DE8;
        }
    }

label_80259DD0:
    ctx->pc = 0x80259DD0u;
    ctx->downcount -= 6;
    // 80259DD0: stb     r9, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[9]);
    }

label_80259DD4:
    ctx->pc = 0x80259DD4u;
    // 80259DD4: lwz     r3, 472(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(472);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259DD8:
    ctx->pc = 0x80259DD8u;
    // 80259DD8: stw     r3, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80259DDC:
    ctx->pc = 0x80259DDCu;
    // 80259DDC: stb     r9, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[9]);
    }

label_80259DE0:
    ctx->pc = 0x80259DE0u;
    // 80259DE0: lwz     r3, 464(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(464);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259DE4:
    ctx->pc = 0x80259DE4u;
    // 80259DE4: stw     r3, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80259DE8:
    ctx->pc = 0x80259DE8u;
    ctx->downcount -= 2;
    // 80259DE8: rlwinm. r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80259DEC:
    ctx->pc = 0x80259DECu;
    // 80259DEC: bc    12, 2, 0x80259E08
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80259E08;
        }
    }

label_80259DF0:
    ctx->pc = 0x80259DF0u;
    ctx->downcount -= 6;
    // 80259DF0: li      r0, 97
    ctx->gpr[0] = (u32)(s32)(97);

label_80259DF4:
    ctx->pc = 0x80259DF4u;
    // 80259DF4: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259DF8:
    ctx->pc = 0x80259DF8u;
    // 80259DF8: lis     r4, -13311
    ctx->gpr[4] = ((u32)(s32)(-13311) << 16);

label_80259DFC:
    ctx->pc = 0x80259DFCu;
    // 80259DFC: stb     r0, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80259E00:
    ctx->pc = 0x80259E00u;
    // 80259E00: lwz     r0, 476(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(476);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80259E04:
    ctx->pc = 0x80259E04u;
    // 80259E04: stw     r0, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80259E08:
    ctx->pc = 0x80259E08u;
    ctx->downcount -= 4;
    // 80259E08: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259E0C:
    ctx->pc = 0x80259E0Cu;
    // 80259E0C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80259E10:
    ctx->pc = 0x80259E10u;
    // 80259E10: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80259E14:
    ctx->pc = 0x80259E14u;
    // 80259E14: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80259E18:
    ctx->pc = 0x80259E18u;
    ctx->downcount -= 2;
    // 80259E18: rlwinm. r0, r4, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x000000FFu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80259E1C:
    ctx->pc = 0x80259E1Cu;
    // 80259E1C: bc    12, 2, 0x80259E58
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80259E58;
        }
    }

label_80259E20:
    ctx->pc = 0x80259E20u;
    ctx->downcount -= 14;
    // 80259E20: lwz     r7, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80259E24:
    ctx->pc = 0x80259E24u;
    // 80259E24: li      r0, 97
    ctx->gpr[0] = (u32)(s32)(97);

label_80259E28:
    ctx->pc = 0x80259E28u;
    // 80259E28: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_80259E2C:
    ctx->pc = 0x80259E2Cu;
    // 80259E2C: lwz     r6, 472(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(472);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80259E30:
    ctx->pc = 0x80259E30u;
    // 80259E30: rlwinm r6, r6, 0, 0, 30
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFFFFFFFEu;
    }

label_80259E34:
    ctx->pc = 0x80259E34u;
    // 80259E34: stb     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80259E38:
    ctx->pc = 0x80259E38u;
    // 80259E38: ori     r6, r6, 0x0001
    ctx->gpr[6] = ctx->gpr[6] | 0x0001u;

label_80259E3C:
    ctx->pc = 0x80259E3Cu;
    // 80259E3C: rlwinm r6, r6, 0, 31, 27
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFFFFFFF1u;
    }

label_80259E40:
    ctx->pc = 0x80259E40u;
    // 80259E40: ori     r6, r6, 0x000E
    ctx->gpr[6] = ctx->gpr[6] | 0x000Eu;

label_80259E44:
    ctx->pc = 0x80259E44u;
    // 80259E44: stw     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80259E48:
    ctx->pc = 0x80259E48u;
    // 80259E48: lwz     r6, 464(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(464);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80259E4C:
    ctx->pc = 0x80259E4Cu;
    // 80259E4C: stb     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80259E50:
    ctx->pc = 0x80259E50u;
    // 80259E50: rlwinm r0, r6, 0, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFFFFFFFCu;
    }

label_80259E54:
    ctx->pc = 0x80259E54u;
    // 80259E54: stw     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80259E58:
    ctx->pc = 0x80259E58u;
    ctx->downcount -= 6;
    // 80259E58: lwz     r6, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80259E5C:
    ctx->pc = 0x80259E5Cu;
    // 80259E5C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80259E60:
    ctx->pc = 0x80259E60u;
    // 80259E60: lbz     r5, 512(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(512);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_80259E64:
    ctx->pc = 0x80259E64u;
    // 80259E64: lwz     r7, 476(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(476);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80259E68:
    ctx->pc = 0x80259E68u;
    // 80259E68: cmplwi  r5, 0x0000
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

label_80259E6C:
    ctx->pc = 0x80259E6Cu;
    // 80259E6C: bc    12, 2, 0x80259E88
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80259E88;
        }
    }

label_80259E70:
    ctx->pc = 0x80259E70u;
    ctx->downcount -= 3;
    // 80259E70: rlwinm r5, r7, 0, 29, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0x00000007u;
    }

label_80259E74:
    ctx->pc = 0x80259E74u;
    // 80259E74: cmplwi  r5, 0x0003
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(0x0003u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80259E78:
    ctx->pc = 0x80259E78u;
    // 80259E78: bc    12, 2, 0x80259E88
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80259E88;
        }
    }

label_80259E7C:
    ctx->pc = 0x80259E7Cu;
    ctx->downcount -= 3;
    // 80259E7C: rlwinm r0, r7, 0, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFFFFFFF8u;
    }

label_80259E80:
    ctx->pc = 0x80259E80u;
    // 80259E80: ori     r7, r0, 0x0003
    ctx->gpr[7] = ctx->gpr[0] | 0x0003u;

label_80259E84:
    ctx->pc = 0x80259E84u;
    // 80259E84: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80259E88:
    ctx->pc = 0x80259E88u;
    ctx->downcount -= 2;
    // 80259E88: rlwinm. r5, r4, 0, 24, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x000000FFu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[5];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80259E8C:
    ctx->pc = 0x80259E8Cu;
    // 80259E8C: bc    4, 2, 0x80259E9C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80259E9C;
        }
    }

label_80259E90:
    ctx->pc = 0x80259E90u;
    ctx->downcount -= 3;
    // 80259E90: rlwinm r5, r7, 0, 29, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0x00000007u;
    }

label_80259E94:
    ctx->pc = 0x80259E94u;
    // 80259E94: cmplwi  r5, 0x0003
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(0x0003u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80259E98:
    ctx->pc = 0x80259E98u;
    // 80259E98: bc    4, 2, 0x80259EB0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80259EB0;
        }
    }

label_80259E9C:
    ctx->pc = 0x80259E9Cu;
    ctx->downcount -= 3;
    // 80259E9C: rlwinm r5, r7, 26, 31, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[7], 26u) & 0x00000001u;
    }

label_80259EA0:
    ctx->pc = 0x80259EA0u;
    // 80259EA0: cmplwi  r5, 0x0001
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(0x0001u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80259EA4:
    ctx->pc = 0x80259EA4u;
    // 80259EA4: bc    4, 2, 0x80259EB0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80259EB0;
        }
    }

label_80259EA8:
    ctx->pc = 0x80259EA8u;
    ctx->downcount -= 2;
    // 80259EA8: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80259EAC:
    ctx->pc = 0x80259EACu;
    // 80259EAC: rlwinm r7, r7, 0, 26, 24
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFFFFFFBFu;
    }

label_80259EB0:
    ctx->pc = 0x80259EB0u;
    ctx->downcount -= 2;
    // 80259EB0: rlwinm. r5, r0, 0, 24, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[5];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80259EB4:
    ctx->pc = 0x80259EB4u;
    // 80259EB4: bc    12, 2, 0x80259EC8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80259EC8;
        }
    }

label_80259EB8:
    ctx->pc = 0x80259EB8u;
    ctx->downcount -= 4;
    // 80259EB8: li      r6, 97
    ctx->gpr[6] = (u32)(s32)(97);

label_80259EBC:
    ctx->pc = 0x80259EBCu;
    // 80259EBC: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_80259EC0:
    ctx->pc = 0x80259EC0u;
    // 80259EC0: stb     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_80259EC4:
    ctx->pc = 0x80259EC4u;
    // 80259EC4: stw     r7, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80259EC8:
    ctx->pc = 0x80259EC8u;
    ctx->downcount -= 38;
    // 80259EC8: li      r9, 97
    ctx->gpr[9] = (u32)(s32)(97);

label_80259ECC:
    ctx->pc = 0x80259ECCu;
    // 80259ECC: lwz     r7, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80259ED0:
    ctx->pc = 0x80259ED0u;
    // 80259ED0: lis     r8, -13311
    ctx->gpr[8] = ((u32)(s32)(-13311) << 16);

label_80259ED4:
    ctx->pc = 0x80259ED4u;
    // 80259ED4: stb     r9, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[9]);
    }

label_80259ED8:
    ctx->pc = 0x80259ED8u;
    // 80259ED8: rlwinm r3, r3, 27, 8, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 27u) & 0x00FFFFFFu;
    }

label_80259EDC:
    ctx->pc = 0x80259EDCu;
    // 80259EDC: oris    r10, r3, 0x4B00
    ctx->gpr[10] = ctx->gpr[3] | (0x4B00u << 16);

label_80259EE0:
    ctx->pc = 0x80259EE0u;
    // 80259EE0: lwz     r6, 496(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(496);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80259EE4:
    ctx->pc = 0x80259EE4u;
    // 80259EE4: rlwinm. r5, r4, 0, 24, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x000000FFu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[5];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80259EE8:
    ctx->pc = 0x80259EE8u;
    // 80259EE8: rlwinm r3, r4, 11, 13, 20
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[4], 11u) & 0x0007F800u;
    }

label_80259EEC:
    ctx->pc = 0x80259EECu;
    // 80259EEC: stw     r6, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80259EF0:
    ctx->pc = 0x80259EF0u;
    // 80259EF0: stb     r9, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[9]);
    }

label_80259EF4:
    ctx->pc = 0x80259EF4u;
    // 80259EF4: lwz     r4, 500(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(500);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80259EF8:
    ctx->pc = 0x80259EF8u;
    // 80259EF8: stw     r4, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80259EFC:
    ctx->pc = 0x80259EFCu;
    // 80259EFC: stb     r9, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[9]);
    }

label_80259F00:
    ctx->pc = 0x80259F00u;
    // 80259F00: lwz     r4, 504(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(504);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80259F04:
    ctx->pc = 0x80259F04u;
    // 80259F04: stw     r4, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80259F08:
    ctx->pc = 0x80259F08u;
    // 80259F08: stb     r9, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[9]);
    }

label_80259F0C:
    ctx->pc = 0x80259F0Cu;
    // 80259F0C: stw     r10, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80259F10:
    ctx->pc = 0x80259F10u;
    // 80259F10: lwz     r4, 508(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(508);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80259F14:
    ctx->pc = 0x80259F14u;
    // 80259F14: rlwinm r4, r4, 0, 21, 19
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFF7FFu;
    }

label_80259F18:
    ctx->pc = 0x80259F18u;
    // 80259F18: or   r3, r4, r3
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[3];
    }

label_80259F1C:
    ctx->pc = 0x80259F1Cu;
    // 80259F1C: stw     r3, 508(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(508);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80259F20:
    ctx->pc = 0x80259F20u;
    // 80259F20: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259F24:
    ctx->pc = 0x80259F24u;
    // 80259F24: addi    r4, r3, 508
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(508);

label_80259F28:
    ctx->pc = 0x80259F28u;
    // 80259F28: lwz     r3, 508(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(508);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259F2C:
    ctx->pc = 0x80259F2Cu;
    // 80259F2C: rlwinm r3, r3, 0, 18, 16
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFBFFFu;
    }

label_80259F30:
    ctx->pc = 0x80259F30u;
    // 80259F30: stw     r3, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80259F34:
    ctx->pc = 0x80259F34u;
    // 80259F34: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259F38:
    ctx->pc = 0x80259F38u;
    // 80259F38: addi    r4, r3, 508
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(508);

label_80259F3C:
    ctx->pc = 0x80259F3Cu;
    // 80259F3C: lwz     r3, 508(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(508);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259F40:
    ctx->pc = 0x80259F40u;
    // 80259F40: rlwinm r3, r3, 0, 8, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00FFFFFFu;
    }

label_80259F44:
    ctx->pc = 0x80259F44u;
    // 80259F44: oris    r3, r3, 0x5200
    ctx->gpr[3] = ctx->gpr[3] | (0x5200u << 16);

label_80259F48:
    ctx->pc = 0x80259F48u;
    // 80259F48: stw     r3, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80259F4C:
    ctx->pc = 0x80259F4Cu;
    // 80259F4C: stb     r9, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[9]);
    }

label_80259F50:
    ctx->pc = 0x80259F50u;
    // 80259F50: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80259F54:
    ctx->pc = 0x80259F54u;
    // 80259F54: lwz     r3, 508(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(508);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259F58:
    ctx->pc = 0x80259F58u;
    // 80259F58: stw     r3, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80259F5C:
    ctx->pc = 0x80259F5Cu;
    // 80259F5C: bc    12, 2, 0x80259F78
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80259F78;
        }
    }

label_80259F60:
    ctx->pc = 0x80259F60u;
    ctx->downcount -= 6;
    // 80259F60: stb     r9, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[9]);
    }

label_80259F64:
    ctx->pc = 0x80259F64u;
    // 80259F64: lwz     r3, 472(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(472);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259F68:
    ctx->pc = 0x80259F68u;
    // 80259F68: stw     r3, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80259F6C:
    ctx->pc = 0x80259F6Cu;
    // 80259F6C: stb     r9, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[9]);
    }

label_80259F70:
    ctx->pc = 0x80259F70u;
    // 80259F70: lwz     r3, 464(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(464);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259F74:
    ctx->pc = 0x80259F74u;
    // 80259F74: stw     r3, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80259F78:
    ctx->pc = 0x80259F78u;
    ctx->downcount -= 2;
    // 80259F78: rlwinm. r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80259F7C:
    ctx->pc = 0x80259F7Cu;
    // 80259F7C: bc    12, 2, 0x80259F98
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80259F98;
        }
    }

label_80259F80:
    ctx->pc = 0x80259F80u;
    ctx->downcount -= 6;
    // 80259F80: li      r0, 97
    ctx->gpr[0] = (u32)(s32)(97);

label_80259F84:
    ctx->pc = 0x80259F84u;
    // 80259F84: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259F88:
    ctx->pc = 0x80259F88u;
    // 80259F88: lis     r4, -13311
    ctx->gpr[4] = ((u32)(s32)(-13311) << 16);

label_80259F8C:
    ctx->pc = 0x80259F8Cu;
    // 80259F8C: stb     r0, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80259F90:
    ctx->pc = 0x80259F90u;
    // 80259F90: lwz     r0, 476(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(476);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80259F94:
    ctx->pc = 0x80259F94u;
    // 80259F94: stw     r0, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80259F98:
    ctx->pc = 0x80259F98u;
    ctx->downcount -= 4;
    // 80259F98: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259F9C:
    ctx->pc = 0x80259F9Cu;
    // 80259F9C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80259FA0:
    ctx->pc = 0x80259FA0u;
    // 80259FA0: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80259FA4:
    ctx->pc = 0x80259FA4u;
    // 80259FA4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80259FA8:
    ctx->pc = 0x80259FA8u;
    ctx->downcount -= 14;
    // 80259FA8: li      r6, 97
    ctx->gpr[6] = (u32)(s32)(97);

label_80259FAC:
    ctx->pc = 0x80259FACu;
    // 80259FAC: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80259FB0:
    ctx->pc = 0x80259FB0u;
    // 80259FB0: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_80259FB4:
    ctx->pc = 0x80259FB4u;
    // 80259FB4: lis     r4, 21760
    ctx->gpr[4] = ((u32)(s32)(21760) << 16);

label_80259FB8:
    ctx->pc = 0x80259FB8u;
    // 80259FB8: stb     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_80259FBC:
    ctx->pc = 0x80259FBCu;
    // 80259FBC: addi    r0, r4, 1023
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(1023);

label_80259FC0:
    ctx->pc = 0x80259FC0u;
    // 80259FC0: stw     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80259FC4:
    ctx->pc = 0x80259FC4u;
    // 80259FC4: lis     r4, 22016
    ctx->gpr[4] = ((u32)(s32)(22016) << 16);

label_80259FC8:
    ctx->pc = 0x80259FC8u;
    // 80259FC8: addi    r4, r4, 1023
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(1023);

label_80259FCC:
    ctx->pc = 0x80259FCCu;
    // 80259FCC: stb     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_80259FD0:
    ctx->pc = 0x80259FD0u;
    // 80259FD0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80259FD4:
    ctx->pc = 0x80259FD4u;
    // 80259FD4: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80259FD8:
    ctx->pc = 0x80259FD8u;
    // 80259FD8: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80259FDC:
    ctx->pc = 0x80259FDCu;
    // 80259FDC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80259FE0:
    ctx->pc = 0x80259FE0u;
    ctx->downcount -= 7;
    // 80259FE0: stfs     f1, 16(r3)
    if (!ppc_fp_available_inline(ctx, 0x80259FE0u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_80259FE4:
    ctx->pc = 0x80259FE4u;
    // 80259FE4: stfs     f2, 20(r3)
    if (!ppc_fp_available_inline(ctx, 0x80259FE4u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_80259FE8:
    ctx->pc = 0x80259FE8u;
    // 80259FE8: stfs     f3, 24(r3)
    if (!ppc_fp_available_inline(ctx, 0x80259FE8u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[3]));
    }

label_80259FEC:
    ctx->pc = 0x80259FECu;
    // 80259FEC: stfs     f4, 28(r3)
    if (!ppc_fp_available_inline(ctx, 0x80259FECu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(28);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[4]));
    }

label_80259FF0:
    ctx->pc = 0x80259FF0u;
    // 80259FF0: stfs     f5, 32(r3)
    if (!ppc_fp_available_inline(ctx, 0x80259FF0u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(32);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[5]));
    }

label_80259FF4:
    ctx->pc = 0x80259FF4u;
    // 80259FF4: stfs     f6, 36(r3)
    if (!ppc_fp_available_inline(ctx, 0x80259FF4u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(36);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[6]));
    }

label_80259FF8:
    ctx->pc = 0x80259FF8u;
    // 80259FF8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_80259FFC:
    ctx->pc = 0x80259FFCu;
    ctx->downcount -= 4;
    // 80259FFC: stfs     f1, 16(r3)
    if (!ppc_fp_available_inline(ctx, 0x80259FFCu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8025A000:
    ctx->pc = 0x8025A000u;
    // 8025A000: stfs     f2, 20(r3)
    if (!ppc_fp_available_inline(ctx, 0x8025A000u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_8025A004:
    ctx->pc = 0x8025A004u;
    // 8025A004: stfs     f3, 24(r3)
    if (!ppc_fp_available_inline(ctx, 0x8025A004u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[3]));
    }

label_8025A008:
    ctx->pc = 0x8025A008u;
    // 8025A008: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_8025A00C:
    ctx->pc = 0x8025A00Cu;
    ctx->downcount -= 4;
    // 8025A00C: stfs     f1, 28(r3)
    if (!ppc_fp_available_inline(ctx, 0x8025A00Cu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(28);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8025A010:
    ctx->pc = 0x8025A010u;
    // 8025A010: stfs     f2, 32(r3)
    if (!ppc_fp_available_inline(ctx, 0x8025A010u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(32);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_8025A014:
    ctx->pc = 0x8025A014u;
    // 8025A014: stfs     f3, 36(r3)
    if (!ppc_fp_available_inline(ctx, 0x8025A014u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(36);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[3]));
    }

label_8025A018:
    ctx->pc = 0x8025A018u;
    // 8025A018: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_8025A01C:
    ctx->pc = 0x8025A01Cu;
    ctx->downcount -= 7;
    // 8025A01C: lfs     f0, 28(r3)
    if (!ppc_fp_available_inline(ctx, 0x8025A01Cu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(28);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8025A020:
    ctx->pc = 0x8025A020u;
    // 8025A020: stfs     f0, 0(r4)
    if (!ppc_fp_available_inline(ctx, 0x8025A020u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8025A024:
    ctx->pc = 0x8025A024u;
    // 8025A024: lfs     f0, 32(r3)
    if (!ppc_fp_available_inline(ctx, 0x8025A024u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(32);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8025A028:
    ctx->pc = 0x8025A028u;
    // 8025A028: stfs     f0, 0(r5)
    if (!ppc_fp_available_inline(ctx, 0x8025A028u)) return;
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8025A02C:
    ctx->pc = 0x8025A02Cu;
    // 8025A02C: lfs     f0, 36(r3)
    if (!ppc_fp_available_inline(ctx, 0x8025A02Cu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(36);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8025A030:
    ctx->pc = 0x8025A030u;
    // 8025A030: stfs     f0, 0(r6)
    if (!ppc_fp_available_inline(ctx, 0x8025A030u)) return;
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8025A034:
    ctx->pc = 0x8025A034u;
    // 8025A034: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_8025A038:
    ctx->pc = 0x8025A038u;
    ctx->downcount -= 11;
    // 8025A038: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8025A03C:
    ctx->pc = 0x8025A03Cu;
    // 8025A03C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8025A040:
    ctx->pc = 0x8025A040u;
    // 8025A040: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8025A044:
    ctx->pc = 0x8025A044u;
    // 8025A044: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8025A048:
    ctx->pc = 0x8025A048u;
    // 8025A048: addi    r31, r4, 0
    ctx->gpr[31] = ctx->gpr[4] + (u32)(s32)(0);

label_8025A04C:
    ctx->pc = 0x8025A04Cu;
    // 8025A04C: stw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8025A050:
    ctx->pc = 0x8025A050u;
    // 8025A050: addi    r30, r3, 0
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(0);

label_8025A054:
    ctx->pc = 0x8025A054u;
    // 8025A054: lfs     f0, 4536(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A054u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4536);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8025A058:
    ctx->pc = 0x8025A058u;
    // 8025A058: fcmpo   cr0, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8025A058u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[1], ctx->fpr[0], true);

label_8025A05C:
    ctx->pc = 0x8025A05Cu;
    // 8025A05C: cror    2, 0, 2
    {
        u32 a = (ctx->cr >> (31u - 0u)) & 1u;
        u32 b = (ctx->cr >> (31u - 2u)) & 1u;
        u32 mask = 0x80000000u >> 2;
        u32 value = (a | b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8025A060:
    ctx->pc = 0x8025A060u;
    // 8025A060: bc    12, 2, 0x8025A070
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8025A070;
        }
    }

label_8025A064:
    ctx->pc = 0x8025A064u;
    ctx->downcount -= 3;
    // 8025A064: lfs     f0, 4540(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A064u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4540);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8025A068:
    ctx->pc = 0x8025A068u;
    // 8025A068: fcmpo   cr0, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8025A068u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[1], ctx->fpr[0], true);

label_8025A06C:
    ctx->pc = 0x8025A06Cu;
    // 8025A06C: bc    4, 1, 0x8025A074
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8025A074;
        }
    }

label_8025A070:
    ctx->pc = 0x8025A070u;
    ctx->downcount -= 1;
    // 8025A070: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_8025A074:
    ctx->pc = 0x8025A074u;
    ctx->downcount -= 21;
    // 8025A074: lfs     f2, 4544(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A074u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4544);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8025A078:
    ctx->pc = 0x8025A078u;
    // 8025A078: lfs     f0, 4548(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A078u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4548);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8025A07C:
    ctx->pc = 0x8025A07Cu;
    // 8025A07C: fmuls   f1, f2, f1
    if (!ppc_fp_available_inline(ctx, 0x8025A07Cu)) return;
    ppc_fmuls(ctx, 1, 2, 1);

label_8025A080:
    ctx->pc = 0x8025A080u;
    // 8025A080: fdivs   f1, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8025A080u)) return;
    ppc_fdivs(ctx, 1, 1, 0);

label_8025A084:
    ctx->pc = 0x8025A084u;
    // 8025A084: bl      0x802951C0
    {
            ctx->lr = 0x8025A088u;
            ctx->pc = 0x802951C0u;
            return;
    }

label_8025A088:
    ctx->pc = 0x8025A088u;
    ctx->downcount -= 2;
    // 8025A088: cmplwi  r31, 0x0006
    {
        u32 val_a = (u32)(ctx->gpr[31]);
        u32 val_b = (u32)(0x0006u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8025A08C:
    ctx->pc = 0x8025A08Cu;
    // 8025A08C: bc    12, 1, 0x8025A188
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8025A188;
        }
    }

label_8025A090:
    ctx->pc = 0x8025A090u;
    ctx->downcount -= 7;
    // 8025A090: lis     r3, -32717
    ctx->gpr[3] = ((u32)(s32)(-32717) << 16);

label_8025A094:
    ctx->pc = 0x8025A094u;
    // 8025A094: addi    r3, r3, 168
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(168);

label_8025A098:
    ctx->pc = 0x8025A098u;
    // 8025A098: rlwinm r0, r31, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[31], 2u) & 0xFFFFFFFCu;
    }

label_8025A09C:
    ctx->pc = 0x8025A09Cu;
    // 8025A09C: lwzx    r0, r3, r0
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8025A0A0:
    ctx->pc = 0x8025A0A0u;
    // 8025A0A0: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8025A0A4:
    ctx->pc = 0x8025A0A4u;
    // 8025A0A4: bctr
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            return;
        }
    }

label_8025A0A8:
    ctx->pc = 0x8025A0A8u;
    ctx->downcount -= 5;
    // 8025A0A8: lfs     f0, 4552(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A0A8u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4552);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8025A0AC:
    ctx->pc = 0x8025A0ACu;
    // 8025A0AC: lfs     f2, 4556(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A0ACu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4556);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8025A0B0:
    ctx->pc = 0x8025A0B0u;
    // 8025A0B0: fmuls   f5, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8025A0B0u)) return;
    ppc_fmuls(ctx, 5, 0, 1);

label_8025A0B4:
    ctx->pc = 0x8025A0B4u;
    // 8025A0B4: lfs     f3, 4536(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A0B4u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4536);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8025A0B8:
    ctx->pc = 0x8025A0B8u;
    // 8025A0B8: b       0x8025A194
    {
            goto label_8025A194;
    }

label_8025A0BC:
    ctx->pc = 0x8025A0BCu;
    ctx->downcount -= 39;
    // 8025A0BC: lfs     f0, 4560(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A0BCu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4560);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8025A0C0:
    ctx->pc = 0x8025A0C0u;
    // 8025A0C0: fneg    f2, f1
    if (!ppc_fp_available_inline(ctx, 0x8025A0C0u)) return;
    ctx->fpr[2] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[1]) ^ 0x8000000000000000ull);

label_8025A0C4:
    ctx->pc = 0x8025A0C4u;
    // 8025A0C4: lfs     f3, 4536(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A0C4u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4536);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8025A0C8:
    ctx->pc = 0x8025A0C8u;
    // 8025A0C8: fsubs   f1, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8025A0C8u)) return;
    ppc_fsubs(ctx, 1, 0, 1);

label_8025A0CC:
    ctx->pc = 0x8025A0CCu;
    // 8025A0CC: fdivs   f5, f2, f1
    if (!ppc_fp_available_inline(ctx, 0x8025A0CCu)) return;
    ppc_fdivs(ctx, 5, 2, 1);

label_8025A0D0:
    ctx->pc = 0x8025A0D0u;
    // 8025A0D0: fdivs   f2, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8025A0D0u)) return;
    ppc_fdivs(ctx, 2, 0, 1);

label_8025A0D4:
    ctx->pc = 0x8025A0D4u;
    // 8025A0D4: b       0x8025A194
    {
            goto label_8025A194;
    }

label_8025A0D8:
    ctx->pc = 0x8025A0D8u;
    ctx->downcount -= 39;
    // 8025A0D8: lfs     f0, 4560(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A0D8u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4560);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8025A0DC:
    ctx->pc = 0x8025A0DCu;
    // 8025A0DC: fneg    f2, f1
    if (!ppc_fp_available_inline(ctx, 0x8025A0DCu)) return;
    ctx->fpr[2] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[1]) ^ 0x8000000000000000ull);

label_8025A0E0:
    ctx->pc = 0x8025A0E0u;
    // 8025A0E0: lfs     f5, 4536(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A0E0u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4536);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[5] = value;
        ctx->ps1[5] = value;
    }

label_8025A0E4:
    ctx->pc = 0x8025A0E4u;
    // 8025A0E4: fsubs   f1, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8025A0E4u)) return;
    ppc_fsubs(ctx, 1, 0, 1);

label_8025A0E8:
    ctx->pc = 0x8025A0E8u;
    // 8025A0E8: fdivs   f2, f2, f1
    if (!ppc_fp_available_inline(ctx, 0x8025A0E8u)) return;
    ppc_fdivs(ctx, 2, 2, 1);

label_8025A0EC:
    ctx->pc = 0x8025A0ECu;
    // 8025A0EC: fdivs   f3, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8025A0ECu)) return;
    ppc_fdivs(ctx, 3, 0, 1);

label_8025A0F0:
    ctx->pc = 0x8025A0F0u;
    // 8025A0F0: b       0x8025A194
    {
            goto label_8025A194;
    }

label_8025A0F4:
    ctx->pc = 0x8025A0F4u;
    ctx->downcount -= 59;
    // 8025A0F4: lfs     f0, 4560(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A0F4u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4560);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8025A0F8:
    ctx->pc = 0x8025A0F8u;
    // 8025A0F8: lfs     f3, 4564(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A0F8u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4564);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8025A0FC:
    ctx->pc = 0x8025A0FCu;
    // 8025A0FC: fsubs   f4, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8025A0FCu)) return;
    ppc_fsubs(ctx, 4, 0, 1);

label_8025A100:
    ctx->pc = 0x8025A100u;
    // 8025A100: lfs     f0, 4568(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A100u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4568);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8025A104:
    ctx->pc = 0x8025A104u;
    // 8025A104: fsubs   f2, f1, f3
    if (!ppc_fp_available_inline(ctx, 0x8025A104u)) return;
    ppc_fsubs(ctx, 2, 1, 3);

label_8025A108:
    ctx->pc = 0x8025A108u;
    // 8025A108: fmuls   f4, f4, f4
    if (!ppc_fp_available_inline(ctx, 0x8025A108u)) return;
    ppc_fmuls(ctx, 4, 4, 4);

label_8025A10C:
    ctx->pc = 0x8025A10Cu;
    // 8025A10C: fmuls   f1, f1, f2
    if (!ppc_fp_available_inline(ctx, 0x8025A10Cu)) return;
    ppc_fmuls(ctx, 1, 1, 2);

label_8025A110:
    ctx->pc = 0x8025A110u;
    // 8025A110: fdivs   f2, f3, f4
    if (!ppc_fp_available_inline(ctx, 0x8025A110u)) return;
    ppc_fdivs(ctx, 2, 3, 4);

label_8025A114:
    ctx->pc = 0x8025A114u;
    // 8025A114: fdivs   f5, f1, f4
    if (!ppc_fp_available_inline(ctx, 0x8025A114u)) return;
    ppc_fdivs(ctx, 5, 1, 4);

label_8025A118:
    ctx->pc = 0x8025A118u;
    // 8025A118: fdivs   f3, f0, f4
    if (!ppc_fp_available_inline(ctx, 0x8025A118u)) return;
    ppc_fdivs(ctx, 3, 0, 4);

label_8025A11C:
    ctx->pc = 0x8025A11Cu;
    // 8025A11C: b       0x8025A194
    {
            goto label_8025A194;
    }

label_8025A120:
    ctx->pc = 0x8025A120u;
    ctx->downcount -= 60;
    // 8025A120: lfs     f0, 4560(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A120u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4560);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8025A124:
    ctx->pc = 0x8025A124u;
    // 8025A124: lfs     f3, 4572(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A124u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4572);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8025A128:
    ctx->pc = 0x8025A128u;
    // 8025A128: fsubs   f4, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8025A128u)) return;
    ppc_fsubs(ctx, 4, 0, 1);

label_8025A12C:
    ctx->pc = 0x8025A12Cu;
    // 8025A12C: lfs     f2, 4576(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A12Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4576);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8025A130:
    ctx->pc = 0x8025A130u;
    // 8025A130: fadds   f0, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8025A130u)) return;
    ppc_fadds(ctx, 0, 0, 1);

label_8025A134:
    ctx->pc = 0x8025A134u;
    // 8025A134: fmuls   f1, f3, f1
    if (!ppc_fp_available_inline(ctx, 0x8025A134u)) return;
    ppc_fmuls(ctx, 1, 3, 1);

label_8025A138:
    ctx->pc = 0x8025A138u;
    // 8025A138: fmuls   f4, f4, f4
    if (!ppc_fp_available_inline(ctx, 0x8025A138u)) return;
    ppc_fmuls(ctx, 4, 4, 4);

label_8025A13C:
    ctx->pc = 0x8025A13Cu;
    // 8025A13C: fmuls   f0, f2, f0
    if (!ppc_fp_available_inline(ctx, 0x8025A13Cu)) return;
    ppc_fmuls(ctx, 0, 2, 0);

label_8025A140:
    ctx->pc = 0x8025A140u;
    // 8025A140: fdivs   f5, f1, f4
    if (!ppc_fp_available_inline(ctx, 0x8025A140u)) return;
    ppc_fdivs(ctx, 5, 1, 4);

label_8025A144:
    ctx->pc = 0x8025A144u;
    // 8025A144: fdivs   f2, f0, f4
    if (!ppc_fp_available_inline(ctx, 0x8025A144u)) return;
    ppc_fdivs(ctx, 2, 0, 4);

label_8025A148:
    ctx->pc = 0x8025A148u;
    // 8025A148: fdivs   f3, f3, f4
    if (!ppc_fp_available_inline(ctx, 0x8025A148u)) return;
    ppc_fdivs(ctx, 3, 3, 4);

label_8025A14C:
    ctx->pc = 0x8025A14Cu;
    // 8025A14C: b       0x8025A194
    {
            goto label_8025A194;
    }

label_8025A150:
    ctx->pc = 0x8025A150u;
    ctx->downcount -= 62;
    // 8025A150: lfs     f4, 4560(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A150u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4560);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[4] = value;
        ctx->ps1[4] = value;
    }

label_8025A154:
    ctx->pc = 0x8025A154u;
    // 8025A154: lfs     f0, 4564(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A154u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4564);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8025A158:
    ctx->pc = 0x8025A158u;
    // 8025A158: fsubs   f5, f4, f1
    if (!ppc_fp_available_inline(ctx, 0x8025A158u)) return;
    ppc_fsubs(ctx, 5, 4, 1);

label_8025A15C:
    ctx->pc = 0x8025A15Cu;
    // 8025A15C: lfs     f2, 4576(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A15Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4576);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8025A160:
    ctx->pc = 0x8025A160u;
    // 8025A160: fmuls   f3, f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8025A160u)) return;
    ppc_fmuls(ctx, 3, 0, 1);

label_8025A164:
    ctx->pc = 0x8025A164u;
    // 8025A164: lfs     f0, 4580(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A164u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4580);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8025A168:
    ctx->pc = 0x8025A168u;
    // 8025A168: fmuls   f2, f2, f1
    if (!ppc_fp_available_inline(ctx, 0x8025A168u)) return;
    ppc_fmuls(ctx, 2, 2, 1);

label_8025A16C:
    ctx->pc = 0x8025A16Cu;
    // 8025A16C: fmuls   f5, f5, f5
    if (!ppc_fp_available_inline(ctx, 0x8025A16Cu)) return;
    ppc_fmuls(ctx, 5, 5, 5);

label_8025A170:
    ctx->pc = 0x8025A170u;
    // 8025A170: fmuls   f1, f3, f1
    if (!ppc_fp_available_inline(ctx, 0x8025A170u)) return;
    ppc_fmuls(ctx, 1, 3, 1);

label_8025A174:
    ctx->pc = 0x8025A174u;
    // 8025A174: fdivs   f2, f2, f5
    if (!ppc_fp_available_inline(ctx, 0x8025A174u)) return;
    ppc_fdivs(ctx, 2, 2, 5);

label_8025A178:
    ctx->pc = 0x8025A178u;
    // 8025A178: fdivs   f1, f1, f5
    if (!ppc_fp_available_inline(ctx, 0x8025A178u)) return;
    ppc_fdivs(ctx, 1, 1, 5);

label_8025A17C:
    ctx->pc = 0x8025A17Cu;
    // 8025A17C: fdivs   f3, f0, f5
    if (!ppc_fp_available_inline(ctx, 0x8025A17Cu)) return;
    ppc_fdivs(ctx, 3, 0, 5);

label_8025A180:
    ctx->pc = 0x8025A180u;
    // 8025A180: fsubs   f5, f4, f1
    if (!ppc_fp_available_inline(ctx, 0x8025A180u)) return;
    ppc_fsubs(ctx, 5, 4, 1);

label_8025A184:
    ctx->pc = 0x8025A184u;
    // 8025A184: b       0x8025A194
    {
            goto label_8025A194;
    }

label_8025A188:
    ctx->pc = 0x8025A188u;
    ctx->downcount -= 3;
    // 8025A188: lfs     f2, 4536(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A188u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4536);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8025A18C:
    ctx->pc = 0x8025A18Cu;
    // 8025A18C: lfs     f5, 4560(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A18Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4560);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[5] = value;
        ctx->ps1[5] = value;
    }

label_8025A190:
    ctx->pc = 0x8025A190u;
    // 8025A190: fmr    f3, f2
    if (!ppc_fp_available_inline(ctx, 0x8025A190u)) return;
    ctx->fpr[3] = ctx->fpr[2];

label_8025A194:
    ctx->pc = 0x8025A194u;
    ctx->downcount -= 10;
    // 8025A194: stfs     f5, 16(r30)
    if (!ppc_fp_available_inline(ctx, 0x8025A194u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[5]));
    }

label_8025A198:
    ctx->pc = 0x8025A198u;
    // 8025A198: stfs     f2, 20(r30)
    if (!ppc_fp_available_inline(ctx, 0x8025A198u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_8025A19C:
    ctx->pc = 0x8025A19Cu;
    // 8025A19C: stfs     f3, 24(r30)
    if (!ppc_fp_available_inline(ctx, 0x8025A19Cu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(24);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[3]));
    }

label_8025A1A0:
    ctx->pc = 0x8025A1A0u;
    // 8025A1A0: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8025A1A4:
    ctx->pc = 0x8025A1A4u;
    // 8025A1A4: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8025A1A8:
    ctx->pc = 0x8025A1A8u;
    // 8025A1A8: lwz     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8025A1AC:
    ctx->pc = 0x8025A1ACu;
    // 8025A1AC: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_8025A1B0:
    ctx->pc = 0x8025A1B0u;
    // 8025A1B0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8025A1B4:
    ctx->pc = 0x8025A1B4u;
    // 8025A1B4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_8025A1B8:
    ctx->pc = 0x8025A1B8u;
    ctx->downcount -= 3;
    // 8025A1B8: lfs     f0, 4536(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A1B8u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4536);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8025A1BC:
    ctx->pc = 0x8025A1BCu;
    // 8025A1BC: fcmpo   cr0, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8025A1BCu)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[1], ctx->fpr[0], true);

label_8025A1C0:
    ctx->pc = 0x8025A1C0u;
    // 8025A1C0: bc    4, 0, 0x8025A1C8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8025A1C8;
        }
    }

label_8025A1C4:
    ctx->pc = 0x8025A1C4u;
    ctx->downcount -= 1;
    // 8025A1C4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8025A1C8:
    ctx->pc = 0x8025A1C8u;
    ctx->downcount -= 4;
    // 8025A1C8: lfs     f0, 4536(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A1C8u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4536);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8025A1CC:
    ctx->pc = 0x8025A1CCu;
    // 8025A1CC: fcmpo   cr0, f2, f0
    if (!ppc_fp_available_inline(ctx, 0x8025A1CCu)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[2], ctx->fpr[0], true);

label_8025A1D0:
    ctx->pc = 0x8025A1D0u;
    // 8025A1D0: cror    2, 0, 2
    {
        u32 a = (ctx->cr >> (31u - 0u)) & 1u;
        u32 b = (ctx->cr >> (31u - 2u)) & 1u;
        u32 mask = 0x80000000u >> 2;
        u32 value = (a | b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8025A1D4:
    ctx->pc = 0x8025A1D4u;
    // 8025A1D4: bc    12, 2, 0x8025A1E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8025A1E8;
        }
    }

label_8025A1D8:
    ctx->pc = 0x8025A1D8u;
    ctx->downcount -= 4;
    // 8025A1D8: lfs     f0, 4560(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A1D8u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4560);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8025A1DC:
    ctx->pc = 0x8025A1DCu;
    // 8025A1DC: fcmpo   cr0, f2, f0
    if (!ppc_fp_available_inline(ctx, 0x8025A1DCu)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[2], ctx->fpr[0], true);

label_8025A1E0:
    ctx->pc = 0x8025A1E0u;
    // 8025A1E0: cror    2, 1, 2
    {
        u32 a = (ctx->cr >> (31u - 1u)) & 1u;
        u32 b = (ctx->cr >> (31u - 2u)) & 1u;
        u32 mask = 0x80000000u >> 2;
        u32 value = (a | b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8025A1E4:
    ctx->pc = 0x8025A1E4u;
    // 8025A1E4: bc    4, 2, 0x8025A1EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8025A1EC;
        }
    }

label_8025A1E8:
    ctx->pc = 0x8025A1E8u;
    ctx->downcount -= 1;
    // 8025A1E8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8025A1EC:
    ctx->pc = 0x8025A1ECu;
    ctx->downcount -= 2;
    // 8025A1EC: cmpwi   r4, 2
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8025A1F0:
    ctx->pc = 0x8025A1F0u;
    // 8025A1F0: bc    12, 2, 0x8025A22C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8025A22C;
        }
    }

label_8025A1F4:
    ctx->pc = 0x8025A1F4u;
    ctx->downcount -= 1;
    // 8025A1F4: bc    4, 0, 0x8025A208
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8025A208;
        }
    }

label_8025A1F8:
    ctx->pc = 0x8025A1F8u;
    ctx->downcount -= 2;
    // 8025A1F8: cmpwi   r4, 0
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

label_8025A1FC:
    ctx->pc = 0x8025A1FCu;
    // 8025A1FC: bc    12, 2, 0x8025A26C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8025A26C;
        }
    }

label_8025A200:
    ctx->pc = 0x8025A200u;
    ctx->downcount -= 1;
    // 8025A200: bc    4, 0, 0x8025A214
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8025A214;
        }
    }

label_8025A204:
    ctx->pc = 0x8025A204u;
    ctx->downcount -= 1;
    // 8025A204: b       0x8025A26C
    {
            goto label_8025A26C;
    }

label_8025A208:
    ctx->pc = 0x8025A208u;
    ctx->downcount -= 2;
    // 8025A208: cmpwi   r4, 4
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(4);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8025A20C:
    ctx->pc = 0x8025A20Cu;
    // 8025A20C: bc    4, 0, 0x8025A26C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8025A26C;
        }
    }

label_8025A210:
    ctx->pc = 0x8025A210u;
    ctx->downcount -= 1;
    // 8025A210: b       0x8025A250
    {
            goto label_8025A250;
    }

label_8025A214:
    ctx->pc = 0x8025A214u;
    ctx->downcount -= 22;
    // 8025A214: lfs     f5, 4560(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A214u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4560);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[5] = value;
        ctx->ps1[5] = value;
    }

label_8025A218:
    ctx->pc = 0x8025A218u;
    // 8025A218: fmuls   f0, f2, f1
    if (!ppc_fp_available_inline(ctx, 0x8025A218u)) return;
    ppc_fmuls(ctx, 0, 2, 1);

label_8025A21C:
    ctx->pc = 0x8025A21Cu;
    // 8025A21C: lfs     f4, 4536(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A21Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4536);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[4] = value;
        ctx->ps1[4] = value;
    }

label_8025A220:
    ctx->pc = 0x8025A220u;
    // 8025A220: fsubs   f1, f5, f2
    if (!ppc_fp_available_inline(ctx, 0x8025A220u)) return;
    ppc_fsubs(ctx, 1, 5, 2);

label_8025A224:
    ctx->pc = 0x8025A224u;
    // 8025A224: fdivs   f3, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8025A224u)) return;
    ppc_fdivs(ctx, 3, 1, 0);

label_8025A228:
    ctx->pc = 0x8025A228u;
    // 8025A228: b       0x8025A278
    {
            goto label_8025A278;
    }

label_8025A22C:
    ctx->pc = 0x8025A22Cu;
    ctx->downcount -= 41;
    // 8025A22C: lfs     f5, 4560(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A22Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4560);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[5] = value;
        ctx->ps1[5] = value;
    }

label_8025A230:
    ctx->pc = 0x8025A230u;
    // 8025A230: fmuls   f4, f2, f1
    if (!ppc_fp_available_inline(ctx, 0x8025A230u)) return;
    ppc_fmuls(ctx, 4, 2, 1);

label_8025A234:
    ctx->pc = 0x8025A234u;
    // 8025A234: lfs     f3, 4584(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A234u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4584);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8025A238:
    ctx->pc = 0x8025A238u;
    // 8025A238: fsubs   f2, f5, f2
    if (!ppc_fp_available_inline(ctx, 0x8025A238u)) return;
    ppc_fsubs(ctx, 2, 5, 2);

label_8025A23C:
    ctx->pc = 0x8025A23Cu;
    // 8025A23C: fmuls   f0, f1, f4
    if (!ppc_fp_available_inline(ctx, 0x8025A23Cu)) return;
    ppc_fmuls(ctx, 0, 1, 4);

label_8025A240:
    ctx->pc = 0x8025A240u;
    // 8025A240: fmuls   f1, f3, f2
    if (!ppc_fp_available_inline(ctx, 0x8025A240u)) return;
    ppc_fmuls(ctx, 1, 3, 2);

label_8025A244:
    ctx->pc = 0x8025A244u;
    // 8025A244: fdivs   f3, f1, f4
    if (!ppc_fp_available_inline(ctx, 0x8025A244u)) return;
    ppc_fdivs(ctx, 3, 1, 4);

label_8025A248:
    ctx->pc = 0x8025A248u;
    // 8025A248: fdivs   f4, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8025A248u)) return;
    ppc_fdivs(ctx, 4, 1, 0);

label_8025A24C:
    ctx->pc = 0x8025A24Cu;
    // 8025A24C: b       0x8025A278
    {
            goto label_8025A278;
    }

label_8025A250:
    ctx->pc = 0x8025A250u;
    ctx->downcount -= 23;
    // 8025A250: fmuls   f0, f2, f1
    if (!ppc_fp_available_inline(ctx, 0x8025A250u)) return;
    ppc_fmuls(ctx, 0, 2, 1);

label_8025A254:
    ctx->pc = 0x8025A254u;
    // 8025A254: lfs     f5, 4560(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A254u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4560);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[5] = value;
        ctx->ps1[5] = value;
    }

label_8025A258:
    ctx->pc = 0x8025A258u;
    // 8025A258: lfs     f3, 4536(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A258u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4536);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8025A25C:
    ctx->pc = 0x8025A25Cu;
    // 8025A25C: fsubs   f2, f5, f2
    if (!ppc_fp_available_inline(ctx, 0x8025A25Cu)) return;
    ppc_fsubs(ctx, 2, 5, 2);

label_8025A260:
    ctx->pc = 0x8025A260u;
    // 8025A260: fmuls   f0, f1, f0
    if (!ppc_fp_available_inline(ctx, 0x8025A260u)) return;
    ppc_fmuls(ctx, 0, 1, 0);

label_8025A264:
    ctx->pc = 0x8025A264u;
    // 8025A264: fdivs   f4, f2, f0
    if (!ppc_fp_available_inline(ctx, 0x8025A264u)) return;
    ppc_fdivs(ctx, 4, 2, 0);

label_8025A268:
    ctx->pc = 0x8025A268u;
    // 8025A268: b       0x8025A278
    {
            goto label_8025A278;
    }

label_8025A26C:
    ctx->pc = 0x8025A26Cu;
    ctx->downcount -= 3;
    // 8025A26C: lfs     f3, 4536(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A26Cu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4536);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8025A270:
    ctx->pc = 0x8025A270u;
    // 8025A270: lfs     f5, 4560(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A270u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4560);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[5] = value;
        ctx->ps1[5] = value;
    }

label_8025A274:
    ctx->pc = 0x8025A274u;
    // 8025A274: fmr    f4, f3
    if (!ppc_fp_available_inline(ctx, 0x8025A274u)) return;
    ctx->fpr[4] = ctx->fpr[3];

label_8025A278:
    ctx->pc = 0x8025A278u;
    ctx->downcount -= 4;
    // 8025A278: stfs     f5, 28(r3)
    if (!ppc_fp_available_inline(ctx, 0x8025A278u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(28);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[5]));
    }

label_8025A27C:
    ctx->pc = 0x8025A27Cu;
    // 8025A27C: stfs     f3, 32(r3)
    if (!ppc_fp_available_inline(ctx, 0x8025A27Cu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(32);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[3]));
    }

label_8025A280:
    ctx->pc = 0x8025A280u;
    // 8025A280: stfs     f4, 36(r3)
    if (!ppc_fp_available_inline(ctx, 0x8025A280u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(36);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[4]));
    }

label_8025A284:
    ctx->pc = 0x8025A284u;
    // 8025A284: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_8025A288:
    ctx->pc = 0x8025A288u;
    ctx->downcount -= 4;
    // 8025A288: stfs     f1, 40(r3)
    if (!ppc_fp_available_inline(ctx, 0x8025A288u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8025A28C:
    ctx->pc = 0x8025A28Cu;
    // 8025A28C: stfs     f2, 44(r3)
    if (!ppc_fp_available_inline(ctx, 0x8025A28Cu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_8025A290:
    ctx->pc = 0x8025A290u;
    // 8025A290: stfs     f3, 48(r3)
    if (!ppc_fp_available_inline(ctx, 0x8025A290u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(48);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[3]));
    }

label_8025A294:
    ctx->pc = 0x8025A294u;
    // 8025A294: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_8025A298:
    ctx->pc = 0x8025A298u;
    ctx->downcount -= 7;
    // 8025A298: fneg    f4, f1
    if (!ppc_fp_available_inline(ctx, 0x8025A298u)) return;
    ctx->fpr[4] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[1]) ^ 0x8000000000000000ull);

label_8025A29C:
    ctx->pc = 0x8025A29Cu;
    // 8025A29C: fneg    f1, f2
    if (!ppc_fp_available_inline(ctx, 0x8025A29Cu)) return;
    ctx->fpr[1] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[2]) ^ 0x8000000000000000ull);

label_8025A2A0:
    ctx->pc = 0x8025A2A0u;
    // 8025A2A0: fneg    f0, f3
    if (!ppc_fp_available_inline(ctx, 0x8025A2A0u)) return;
    ctx->fpr[0] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[3]) ^ 0x8000000000000000ull);

label_8025A2A4:
    ctx->pc = 0x8025A2A4u;
    // 8025A2A4: stfs     f4, 52(r3)
    if (!ppc_fp_available_inline(ctx, 0x8025A2A4u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(52);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[4]));
    }

label_8025A2A8:
    ctx->pc = 0x8025A2A8u;
    // 8025A2A8: stfs     f1, 56(r3)
    if (!ppc_fp_available_inline(ctx, 0x8025A2A8u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(56);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8025A2AC:
    ctx->pc = 0x8025A2ACu;
    // 8025A2AC: stfs     f0, 60(r3)
    if (!ppc_fp_available_inline(ctx, 0x8025A2ACu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(60);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8025A2B0:
    ctx->pc = 0x8025A2B0u;
    // 8025A2B0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_8025A2B4:
    ctx->pc = 0x8025A2B4u;
    ctx->downcount -= 13;
    // 8025A2B4: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8025A2B8:
    ctx->pc = 0x8025A2B8u;
    // 8025A2B8: fneg    f0, f1
    if (!ppc_fp_available_inline(ctx, 0x8025A2B8u)) return;
    ctx->fpr[0] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[1]) ^ 0x8000000000000000ull);

label_8025A2BC:
    ctx->pc = 0x8025A2BCu;
    // 8025A2BC: fneg    f1, f2
    if (!ppc_fp_available_inline(ctx, 0x8025A2BCu)) return;
    ctx->fpr[1] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[2]) ^ 0x8000000000000000ull);

label_8025A2C0:
    ctx->pc = 0x8025A2C0u;
    // 8025A2C0: lfs     f5, 4560(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A2C0u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4560);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[5] = value;
        ctx->ps1[5] = value;
    }

label_8025A2C4:
    ctx->pc = 0x8025A2C4u;
    // 8025A2C4: fmuls   f6, f0, f0
    if (!ppc_fp_available_inline(ctx, 0x8025A2C4u)) return;
    ppc_fmuls(ctx, 6, 0, 0);

label_8025A2C8:
    ctx->pc = 0x8025A2C8u;
    // 8025A2C8: lfs     f4, 4536(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A2C8u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4536);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[4] = value;
        ctx->ps1[4] = value;
    }

label_8025A2CC:
    ctx->pc = 0x8025A2CCu;
    // 8025A2CC: fsubs   f2, f5, f3
    if (!ppc_fp_available_inline(ctx, 0x8025A2CCu)) return;
    ppc_fsubs(ctx, 2, 5, 3);

label_8025A2D0:
    ctx->pc = 0x8025A2D0u;
    // 8025A2D0: fmuls   f5, f1, f1
    if (!ppc_fp_available_inline(ctx, 0x8025A2D0u)) return;
    ppc_fmuls(ctx, 5, 1, 1);

label_8025A2D4:
    ctx->pc = 0x8025A2D4u;
    // 8025A2D4: fmuls   f7, f2, f2
    if (!ppc_fp_available_inline(ctx, 0x8025A2D4u)) return;
    ppc_fmuls(ctx, 7, 2, 2);

label_8025A2D8:
    ctx->pc = 0x8025A2D8u;
    // 8025A2D8: fadds   f5, f6, f5
    if (!ppc_fp_available_inline(ctx, 0x8025A2D8u)) return;
    ppc_fadds(ctx, 5, 6, 5);

label_8025A2DC:
    ctx->pc = 0x8025A2DCu;
    // 8025A2DC: fadds   f8, f7, f5
    if (!ppc_fp_available_inline(ctx, 0x8025A2DCu)) return;
    ppc_fadds(ctx, 8, 7, 5);

label_8025A2E0:
    ctx->pc = 0x8025A2E0u;
    // 8025A2E0: fcmpo   cr0, f8, f4
    if (!ppc_fp_available_inline(ctx, 0x8025A2E0u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[8], ctx->fpr[4], true);

label_8025A2E4:
    ctx->pc = 0x8025A2E4u;
    // 8025A2E4: bc    4, 1, 0x8025A340
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8025A340;
        }
    }

label_8025A2E8:
    ctx->pc = 0x8025A2E8u;
    ctx->downcount -= 22;
    // 8025A2E8: frsqrte    f5, f8
    if (!ppc_fp_available_inline(ctx, 0x8025A2E8u)) return;
    { f64 result; if (ppc_frsqrte(ctx, ctx->fpr[8], &result)) ctx->fpr[5] = result; }

label_8025A2EC:
    ctx->pc = 0x8025A2ECu;
    // 8025A2EC: lfd     f7, 4592(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A2ECu)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4592);
        ctx->fpr[7] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8025A2F0:
    ctx->pc = 0x8025A2F0u;
    // 8025A2F0: lfd     f6, 4600(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A2F0u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4600);
        ctx->fpr[6] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8025A2F4:
    ctx->pc = 0x8025A2F4u;
    // 8025A2F4: fmul   f4, f5, f5
    if (!ppc_fp_available_inline(ctx, 0x8025A2F4u)) return;
    ppc_fmul(ctx, 4, 5, 5);

label_8025A2F8:
    ctx->pc = 0x8025A2F8u;
    // 8025A2F8: fmul   f5, f7, f5
    if (!ppc_fp_available_inline(ctx, 0x8025A2F8u)) return;
    ppc_fmul(ctx, 5, 7, 5);

label_8025A2FC:
    ctx->pc = 0x8025A2FCu;
    // 8025A2FC: fmul   f4, f8, f4
    if (!ppc_fp_available_inline(ctx, 0x8025A2FCu)) return;
    ppc_fmul(ctx, 4, 8, 4);

label_8025A300:
    ctx->pc = 0x8025A300u;
    // 8025A300: fsub   f4, f6, f4
    if (!ppc_fp_available_inline(ctx, 0x8025A300u)) return;
    ppc_fsub(ctx, 4, 6, 4);

label_8025A304:
    ctx->pc = 0x8025A304u;
    // 8025A304: fmul   f5, f5, f4
    if (!ppc_fp_available_inline(ctx, 0x8025A304u)) return;
    ppc_fmul(ctx, 5, 5, 4);

label_8025A308:
    ctx->pc = 0x8025A308u;
    // 8025A308: fmul   f4, f5, f5
    if (!ppc_fp_available_inline(ctx, 0x8025A308u)) return;
    ppc_fmul(ctx, 4, 5, 5);

label_8025A30C:
    ctx->pc = 0x8025A30Cu;
    // 8025A30C: fmul   f5, f7, f5
    if (!ppc_fp_available_inline(ctx, 0x8025A30Cu)) return;
    ppc_fmul(ctx, 5, 7, 5);

label_8025A310:
    ctx->pc = 0x8025A310u;
    // 8025A310: fmul   f4, f8, f4
    if (!ppc_fp_available_inline(ctx, 0x8025A310u)) return;
    ppc_fmul(ctx, 4, 8, 4);

label_8025A314:
    ctx->pc = 0x8025A314u;
    // 8025A314: fsub   f4, f6, f4
    if (!ppc_fp_available_inline(ctx, 0x8025A314u)) return;
    ppc_fsub(ctx, 4, 6, 4);

label_8025A318:
    ctx->pc = 0x8025A318u;
    // 8025A318: fmul   f5, f5, f4
    if (!ppc_fp_available_inline(ctx, 0x8025A318u)) return;
    ppc_fmul(ctx, 5, 5, 4);

label_8025A31C:
    ctx->pc = 0x8025A31Cu;
    // 8025A31C: fmul   f4, f5, f5
    if (!ppc_fp_available_inline(ctx, 0x8025A31Cu)) return;
    ppc_fmul(ctx, 4, 5, 5);

label_8025A320:
    ctx->pc = 0x8025A320u;
    // 8025A320: fmul   f5, f7, f5
    if (!ppc_fp_available_inline(ctx, 0x8025A320u)) return;
    ppc_fmul(ctx, 5, 7, 5);

label_8025A324:
    ctx->pc = 0x8025A324u;
    // 8025A324: fmul   f4, f8, f4
    if (!ppc_fp_available_inline(ctx, 0x8025A324u)) return;
    ppc_fmul(ctx, 4, 8, 4);

label_8025A328:
    ctx->pc = 0x8025A328u;
    // 8025A328: fsub   f4, f6, f4
    if (!ppc_fp_available_inline(ctx, 0x8025A328u)) return;
    ppc_fsub(ctx, 4, 6, 4);

label_8025A32C:
    ctx->pc = 0x8025A32Cu;
    // 8025A32C: fmul   f4, f5, f4
    if (!ppc_fp_available_inline(ctx, 0x8025A32Cu)) return;
    ppc_fmul(ctx, 4, 5, 4);

label_8025A330:
    ctx->pc = 0x8025A330u;
    // 8025A330: fmul   f4, f8, f4
    if (!ppc_fp_available_inline(ctx, 0x8025A330u)) return;
    ppc_fmul(ctx, 4, 8, 4);

label_8025A334:
    ctx->pc = 0x8025A334u;
    // 8025A334: frsp    f4, f4
    if (!ppc_fp_available_inline(ctx, 0x8025A334u)) return;
    ppc_frsp(ctx, 4, 4);

label_8025A338:
    ctx->pc = 0x8025A338u;
    // 8025A338: stfs     f4, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x8025A338u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[4]));
    }

label_8025A33C:
    ctx->pc = 0x8025A33Cu;
    // 8025A33C: lfs     f8, 24(r1)
    if (!ppc_fp_available_inline(ctx, 0x8025A33Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[8] = value;
        ctx->ps1[8] = value;
    }

label_8025A340:
    ctx->pc = 0x8025A340u;
    ctx->downcount -= 34;
    // 8025A340: lfs     f4, 4560(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A340u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4560);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[4] = value;
        ctx->ps1[4] = value;
    }

label_8025A344:
    ctx->pc = 0x8025A344u;
    // 8025A344: fneg    f3, f3
    if (!ppc_fp_available_inline(ctx, 0x8025A344u)) return;
    ctx->fpr[3] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[3]) ^ 0x8000000000000000ull);

label_8025A348:
    ctx->pc = 0x8025A348u;
    // 8025A348: fdivs   f6, f4, f8
    if (!ppc_fp_available_inline(ctx, 0x8025A348u)) return;
    ppc_fdivs(ctx, 6, 4, 8);

label_8025A34C:
    ctx->pc = 0x8025A34Cu;
    // 8025A34C: fmuls   f5, f0, f6
    if (!ppc_fp_available_inline(ctx, 0x8025A34Cu)) return;
    ppc_fmuls(ctx, 5, 0, 6);

label_8025A350:
    ctx->pc = 0x8025A350u;
    // 8025A350: fmuls   f4, f1, f6
    if (!ppc_fp_available_inline(ctx, 0x8025A350u)) return;
    ppc_fmuls(ctx, 4, 1, 6);

label_8025A354:
    ctx->pc = 0x8025A354u;
    // 8025A354: fmuls   f2, f2, f6
    if (!ppc_fp_available_inline(ctx, 0x8025A354u)) return;
    ppc_fmuls(ctx, 2, 2, 6);

label_8025A358:
    ctx->pc = 0x8025A358u;
    // 8025A358: stfs     f5, 52(r3)
    if (!ppc_fp_available_inline(ctx, 0x8025A358u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(52);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[5]));
    }

label_8025A35C:
    ctx->pc = 0x8025A35Cu;
    // 8025A35C: stfs     f4, 56(r3)
    if (!ppc_fp_available_inline(ctx, 0x8025A35Cu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(56);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[4]));
    }

label_8025A360:
    ctx->pc = 0x8025A360u;
    // 8025A360: stfs     f2, 60(r3)
    if (!ppc_fp_available_inline(ctx, 0x8025A360u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(60);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_8025A364:
    ctx->pc = 0x8025A364u;
    // 8025A364: lfs     f4, 4608(r2)
    if (!ppc_fp_available_inline(ctx, 0x8025A364u)) return;
    {
        u32 ea = ctx->gpr[2] + (u32)(s32)(4608);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[4] = value;
        ctx->ps1[4] = value;
    }

label_8025A368:
    ctx->pc = 0x8025A368u;
    // 8025A368: fmuls   f2, f4, f0
    if (!ppc_fp_available_inline(ctx, 0x8025A368u)) return;
    ppc_fmuls(ctx, 2, 4, 0);

label_8025A36C:
    ctx->pc = 0x8025A36Cu;
    // 8025A36C: fmuls   f1, f4, f1
    if (!ppc_fp_available_inline(ctx, 0x8025A36Cu)) return;
    ppc_fmuls(ctx, 1, 4, 1);

label_8025A370:
    ctx->pc = 0x8025A370u;
    // 8025A370: fmuls   f0, f4, f3
    if (!ppc_fp_available_inline(ctx, 0x8025A370u)) return;
    ppc_fmuls(ctx, 0, 4, 3);

label_8025A374:
    ctx->pc = 0x8025A374u;
    // 8025A374: stfs     f2, 40(r3)
    if (!ppc_fp_available_inline(ctx, 0x8025A374u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_8025A378:
    ctx->pc = 0x8025A378u;
    // 8025A378: stfs     f1, 44(r3)
    if (!ppc_fp_available_inline(ctx, 0x8025A378u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8025A37C:
    ctx->pc = 0x8025A37Cu;
    // 8025A37C: stfs     f0, 48(r3)
    if (!ppc_fp_available_inline(ctx, 0x8025A37Cu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(48);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8025A380:
    ctx->pc = 0x8025A380u;
    // 8025A380: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_8025A384:
    ctx->pc = 0x8025A384u;
    // 8025A384: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_8025A388:
    ctx->pc = 0x8025A388u;
    ctx->downcount -= 10;
    // 8025A388: lbz     r0, 1(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(1);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8025A38C:
    ctx->pc = 0x8025A38Cu;
    // 8025A38C: lbz     r5, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_8025A390:
    ctx->pc = 0x8025A390u;
    // 8025A390: lbz     r6, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_8025A394:
    ctx->pc = 0x8025A394u;
    // 8025A394: rlwinm r0, r0, 16, 0, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0xFFFF0000u;
    }

label_8025A398:
    ctx->pc = 0x8025A398u;
    // 8025A398: rlwimi r0, r5, 24, 0, 7
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[5], 24u);
        ctx->gpr[0] = (ctx->gpr[0] & ~0xFF000000u) | (rot & 0xFF000000u);
    }

label_8025A39C:
    ctx->pc = 0x8025A39Cu;
    // 8025A39C: lbz     r4, 3(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(3);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_8025A3A0:
    ctx->pc = 0x8025A3A0u;
    // 8025A3A0: rlwimi r0, r6, 8, 16, 23
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[6], 8u);
        ctx->gpr[0] = (ctx->gpr[0] & ~0x0000FF00u) | (rot & 0x0000FF00u);
    }

label_8025A3A4:
    ctx->pc = 0x8025A3A4u;
    // 8025A3A4: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_8025A3A8:
    ctx->pc = 0x8025A3A8u;
    // 8025A3A8: stw     r0, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8025A3AC:
    ctx->pc = 0x8025A3ACu;
    // 8025A3AC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_8025A3B0:
    ctx->pc = 0x8025A3B0u;
    ctx->downcount -= 2;
    // 8025A3B0: cmpwi   r4, 16
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(16);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8025A3B4:
    ctx->pc = 0x8025A3B4u;
    // 8025A3B4: bc    12, 2, 0x8025A430
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8025A430;
        }
    }

label_8025A3B8:
    ctx->pc = 0x8025A3B8u;
    ctx->downcount -= 1;
    // 8025A3B8: bc    4, 0, 0x8025A3EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8025A3EC;
        }
    }

label_8025A3BC:
    ctx->pc = 0x8025A3BCu;
    ctx->downcount -= 2;
    // 8025A3BC: cmpwi   r4, 4
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(4);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8025A3C0:
    ctx->pc = 0x8025A3C0u;
    // 8025A3C0: bc    12, 2, 0x8025A420
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8025A420;
        }
    }

label_8025A3C4:
    ctx->pc = 0x8025A3C4u;
    ctx->downcount -= 1;
    // 8025A3C4: bc    4, 0, 0x8025A3E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8025A3E0;
        }
    }

label_8025A3C8:
    ctx->pc = 0x8025A3C8u;
    ctx->downcount -= 2;
    // 8025A3C8: cmpwi   r4, 2
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8025A3CC:
    ctx->pc = 0x8025A3CCu;
    // 8025A3CC: bc    12, 2, 0x8025A418
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8025A418;
        }
    }

label_8025A3D0:
    ctx->pc = 0x8025A3D0u;
    ctx->downcount -= 1;
    // 8025A3D0: bc    4, 0, 0x8025A450
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8025A450;
        }
    }

label_8025A3D4:
    ctx->pc = 0x8025A3D4u;
    ctx->downcount -= 2;
    // 8025A3D4: cmpwi   r4, 1
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8025A3D8:
    ctx->pc = 0x8025A3D8u;
    // 8025A3D8: bc    4, 0, 0x8025A410
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8025A410;
        }
    }

label_8025A3DC:
    ctx->pc = 0x8025A3DCu;
    ctx->downcount -= 1;
    // 8025A3DC: b       0x8025A450
    {
            goto label_8025A450;
    }

label_8025A3E0:
    ctx->pc = 0x8025A3E0u;
    ctx->downcount -= 2;
    // 8025A3E0: cmpwi   r4, 8
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(8);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8025A3E4:
    ctx->pc = 0x8025A3E4u;
    // 8025A3E4: bc    12, 2, 0x8025A428
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8025A428;
        }
    }

label_8025A3E8:
    ctx->pc = 0x8025A3E8u;
    ctx->downcount -= 1;
    // 8025A3E8: b       0x8025A450
    {
            goto label_8025A450;
    }

label_8025A3EC:
    ctx->pc = 0x8025A3ECu;
    ctx->downcount -= 2;
    // 8025A3EC: cmpwi   r4, 64
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(64);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8025A3F0:
    ctx->pc = 0x8025A3F0u;
    // 8025A3F0: bc    12, 2, 0x8025A440
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8025A440;
        }
    }

label_8025A3F4:
    ctx->pc = 0x8025A3F4u;
    ctx->downcount -= 1;
    // 8025A3F4: bc    4, 0, 0x8025A404
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8025A404;
        }
    }

label_8025A3F8:
    ctx->pc = 0x8025A3F8u;
    ctx->downcount -= 2;
    // 8025A3F8: cmpwi   r4, 32
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(32);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8025A3FC:
    ctx->pc = 0x8025A3FCu;
    // 8025A3FC: bc    12, 2, 0x8025A438
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8025A438;
        }
    }

label_8025A400:
    ctx->pc = 0x8025A400u;
    ctx->downcount -= 1;
    // 8025A400: b       0x8025A450
    {
            goto label_8025A450;
    }

label_8025A404:
    ctx->pc = 0x8025A404u;
    ctx->downcount -= 2;
    // 8025A404: cmpwi   r4, 128
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(128);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8025A408:
    ctx->pc = 0x8025A408u;
    // 8025A408: bc    12, 2, 0x8025A448
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8025A448;
        }
    }

label_8025A40C:
    ctx->pc = 0x8025A40Cu;
    ctx->downcount -= 1;
    // 8025A40C: b       0x8025A450
    {
            goto label_8025A450;
    }

label_8025A410:
    ctx->pc = 0x8025A410u;
    ctx->downcount -= 2;
    // 8025A410: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8025A414:
    ctx->pc = 0x8025A414u;
    // 8025A414: b       0x8025A454
    {
            goto label_8025A454;
    }

label_8025A418:
    ctx->pc = 0x8025A418u;
    ctx->downcount -= 2;
    // 8025A418: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8025A41C:
    ctx->pc = 0x8025A41Cu;
    // 8025A41C: b       0x8025A454
    {
            goto label_8025A454;
    }

label_8025A420:
    ctx->pc = 0x8025A420u;
    ctx->downcount -= 2;
    // 8025A420: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_8025A424:
    ctx->pc = 0x8025A424u;
    // 8025A424: b       0x8025A454
    {
            goto label_8025A454;
    }

label_8025A428:
    ctx->pc = 0x8025A428u;
    ctx->downcount -= 2;
    // 8025A428: li      r0, 3
    ctx->gpr[0] = (u32)(s32)(3);

label_8025A42C:
    ctx->pc = 0x8025A42Cu;
    // 8025A42C: b       0x8025A454
    {
            goto label_8025A454;
    }

label_8025A430:
    ctx->pc = 0x8025A430u;
    ctx->downcount -= 2;
    // 8025A430: li      r0, 4
    ctx->gpr[0] = (u32)(s32)(4);

label_8025A434:
    ctx->pc = 0x8025A434u;
    // 8025A434: b       0x8025A454
    {
            goto label_8025A454;
    }

label_8025A438:
    ctx->pc = 0x8025A438u;
    ctx->downcount -= 2;
    // 8025A438: li      r0, 5
    ctx->gpr[0] = (u32)(s32)(5);

label_8025A43C:
    ctx->pc = 0x8025A43Cu;
    // 8025A43C: b       0x8025A454
    {
            goto label_8025A454;
    }

label_8025A440:
    ctx->pc = 0x8025A440u;
    ctx->downcount -= 2;
    // 8025A440: li      r0, 6
    ctx->gpr[0] = (u32)(s32)(6);

label_8025A444:
    ctx->pc = 0x8025A444u;
    // 8025A444: b       0x8025A454
    {
            goto label_8025A454;
    }

label_8025A448:
    ctx->pc = 0x8025A448u;
    ctx->downcount -= 2;
    // 8025A448: li      r0, 7
    ctx->gpr[0] = (u32)(s32)(7);

label_8025A44C:
    ctx->pc = 0x8025A44Cu;
    // 8025A44C: b       0x8025A454
    {
            goto label_8025A454;
    }

label_8025A450:
    ctx->pc = 0x8025A450u;
    ctx->downcount -= 1;
    // 8025A450: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8025A454:
    ctx->pc = 0x8025A454u;
    ctx->downcount -= 41;
    // 8025A454: rlwinm r5, r0, 4, 0, 27
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[0], 4u) & 0xFFFFFFF0u;
    }

label_8025A458:
    ctx->pc = 0x8025A458u;
    // 8025A458: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8025A45C:
    ctx->pc = 0x8025A45Cu;
    // 8025A45C: addi    r0, r5, 1536
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(1536);

label_8025A460:
    ctx->pc = 0x8025A460u;
    // 8025A460: li      r5, 16
    ctx->gpr[5] = (u32)(s32)(16);

label_8025A464:
    ctx->pc = 0x8025A464u;
    // 8025A464: lis     r6, -13311
    ctx->gpr[6] = ((u32)(s32)(-13311) << 16);

label_8025A468:
    ctx->pc = 0x8025A468u;
    // 8025A468: stb     r5, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

label_8025A46C:
    ctx->pc = 0x8025A46Cu;
    // 8025A46C: oris    r0, r0, 0x000F
    ctx->gpr[0] = ctx->gpr[0] | (0x000Fu << 16);

label_8025A470:
    ctx->pc = 0x8025A470u;
    // 8025A470: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8025A474:
    ctx->pc = 0x8025A474u;
    // 8025A474: stw     r0, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8025A478:
    ctx->pc = 0x8025A478u;
    // 8025A478: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8025A47C:
    ctx->pc = 0x8025A47Cu;
    // 8025A47C: stw     r5, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8025A480:
    ctx->pc = 0x8025A480u;
    // 8025A480: stw     r5, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8025A484:
    ctx->pc = 0x8025A484u;
    // 8025A484: stw     r5, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8025A488:
    ctx->pc = 0x8025A488u;
    // 8025A488: lwz     r5, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8025A48C:
    ctx->pc = 0x8025A48Cu;
    // 8025A48C: stw     r5, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8025A490:
    ctx->pc = 0x8025A490u;
    // 8025A490: lfs     f0, 16(r3)
    if (!ppc_fp_available_inline(ctx, 0x8025A490u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8025A494:
    ctx->pc = 0x8025A494u;
    // 8025A494: stfs     f0, -32768(r6)
    if (!ppc_fp_available_inline(ctx, 0x8025A494u)) return;
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8025A498:
    ctx->pc = 0x8025A498u;
    // 8025A498: lfs     f0, 20(r3)
    if (!ppc_fp_available_inline(ctx, 0x8025A498u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8025A49C:
    ctx->pc = 0x8025A49Cu;
    // 8025A49C: stfs     f0, -32768(r6)
    if (!ppc_fp_available_inline(ctx, 0x8025A49Cu)) return;
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8025A4A0:
    ctx->pc = 0x8025A4A0u;
    // 8025A4A0: lfs     f0, 24(r3)
    if (!ppc_fp_available_inline(ctx, 0x8025A4A0u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8025A4A4:
    ctx->pc = 0x8025A4A4u;
    // 8025A4A4: stfs     f0, -32768(r6)
    if (!ppc_fp_available_inline(ctx, 0x8025A4A4u)) return;
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8025A4A8:
    ctx->pc = 0x8025A4A8u;
    // 8025A4A8: lfs     f0, 28(r3)
    if (!ppc_fp_available_inline(ctx, 0x8025A4A8u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(28);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8025A4AC:
    ctx->pc = 0x8025A4ACu;
    // 8025A4AC: stfs     f0, -32768(r6)
    if (!ppc_fp_available_inline(ctx, 0x8025A4ACu)) return;
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8025A4B0:
    ctx->pc = 0x8025A4B0u;
    // 8025A4B0: lfs     f0, 32(r3)
    if (!ppc_fp_available_inline(ctx, 0x8025A4B0u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(32);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8025A4B4:
    ctx->pc = 0x8025A4B4u;
    // 8025A4B4: stfs     f0, -32768(r6)
    if (!ppc_fp_available_inline(ctx, 0x8025A4B4u)) return;
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8025A4B8:
    ctx->pc = 0x8025A4B8u;
    // 8025A4B8: lfs     f0, 36(r3)
    if (!ppc_fp_available_inline(ctx, 0x8025A4B8u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(36);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8025A4BC:
    ctx->pc = 0x8025A4BCu;
    // 8025A4BC: stfs     f0, -32768(r6)
    if (!ppc_fp_available_inline(ctx, 0x8025A4BCu)) return;
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8025A4C0:
    ctx->pc = 0x8025A4C0u;
    // 8025A4C0: lfs     f0, 40(r3)
    if (!ppc_fp_available_inline(ctx, 0x8025A4C0u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(40);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8025A4C4:
    ctx->pc = 0x8025A4C4u;
    // 8025A4C4: stfs     f0, -32768(r6)
    if (!ppc_fp_available_inline(ctx, 0x8025A4C4u)) return;
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8025A4C8:
    ctx->pc = 0x8025A4C8u;
    // 8025A4C8: lfs     f0, 44(r3)
    if (!ppc_fp_available_inline(ctx, 0x8025A4C8u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(44);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8025A4CC:
    ctx->pc = 0x8025A4CCu;
    // 8025A4CC: stfs     f0, -32768(r6)
    if (!ppc_fp_available_inline(ctx, 0x8025A4CCu)) return;
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8025A4D0:
    ctx->pc = 0x8025A4D0u;
    // 8025A4D0: lfs     f0, 48(r3)
    if (!ppc_fp_available_inline(ctx, 0x8025A4D0u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(48);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8025A4D4:
    ctx->pc = 0x8025A4D4u;
    // 8025A4D4: stfs     f0, -32768(r6)
    if (!ppc_fp_available_inline(ctx, 0x8025A4D4u)) return;
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8025A4D8:
    ctx->pc = 0x8025A4D8u;
    // 8025A4D8: lfs     f0, 52(r3)
    if (!ppc_fp_available_inline(ctx, 0x8025A4D8u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(52);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8025A4DC:
    ctx->pc = 0x8025A4DCu;
    // 8025A4DC: stfs     f0, -32768(r6)
    if (!ppc_fp_available_inline(ctx, 0x8025A4DCu)) return;
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8025A4E0:
    ctx->pc = 0x8025A4E0u;
    // 8025A4E0: lfs     f0, 56(r3)
    if (!ppc_fp_available_inline(ctx, 0x8025A4E0u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(56);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8025A4E4:
    ctx->pc = 0x8025A4E4u;
    // 8025A4E4: stfs     f0, -32768(r6)
    if (!ppc_fp_available_inline(ctx, 0x8025A4E4u)) return;
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8025A4E8:
    ctx->pc = 0x8025A4E8u;
    // 8025A4E8: lfs     f0, 60(r3)
    if (!ppc_fp_available_inline(ctx, 0x8025A4E8u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(60);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8025A4EC:
    ctx->pc = 0x8025A4ECu;
    // 8025A4EC: stfs     f0, -32768(r6)
    if (!ppc_fp_available_inline(ctx, 0x8025A4ECu)) return;
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8025A4F0:
    ctx->pc = 0x8025A4F0u;
    // 8025A4F0: sth     r0, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8025A4F4:
    ctx->pc = 0x8025A4F4u;
    // 8025A4F4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_8025A4F8:
    ctx->pc = 0x8025A4F8u;
    ctx->downcount -= 2;
    // 8025A4F8: cmpwi   r3, 3
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8025A4FC:
    ctx->pc = 0x8025A4FCu;
    // 8025A4FC: bc    12, 2, 0x8025A5AC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8025A5AC;
        }
    }

label_8025A500:
    ctx->pc = 0x8025A500u;
    ctx->downcount -= 1;
    // 8025A500: bc    4, 0, 0x8025A51C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8025A51C;
        }
    }

label_8025A504:
    ctx->pc = 0x8025A504u;
    ctx->downcount -= 2;
    // 8025A504: cmpwi   r3, 1
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

label_8025A508:
    ctx->pc = 0x8025A508u;
    // 8025A508: bc    12, 2, 0x8025A560
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8025A560;
        }
    }

label_8025A50C:
    ctx->pc = 0x8025A50Cu;
    ctx->downcount -= 1;
    // 8025A50C: bc    4, 0, 0x8025A594
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8025A594;
        }
    }

label_8025A510:
    ctx->pc = 0x8025A510u;
    ctx->downcount -= 2;
    // 8025A510: cmpwi   r3, 0
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

label_8025A514:
    ctx->pc = 0x8025A514u;
    // 8025A514: bc    4, 0, 0x8025A52C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8025A52C;
        }
    }

label_8025A518:
    ctx->pc = 0x8025A518u;
    ctx->downcount -= 1;
    // 8025A518: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_8025A51C:
    ctx->pc = 0x8025A51Cu;
    ctx->downcount -= 2;
    // 8025A51C: cmpwi   r3, 5
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(5);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8025A520:
    ctx->pc = 0x8025A520u;
    // 8025A520: bc    12, 2, 0x8025A5F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8025A5F4;
        }
    }

label_8025A524:
    ctx->pc = 0x8025A524u;
    ctx->downcount -= 1;
    // 8025A524: bclr  4, 0
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_8025A528:
    ctx->pc = 0x8025A528u;
    ctx->downcount -= 1;
    // 8025A528: b       0x8025A5C4
    {
            goto label_8025A5C4;
    }

label_8025A52C:
    ctx->pc = 0x8025A52Cu;
    ctx->downcount -= 13;
    // 8025A52C: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8025A530:
    ctx->pc = 0x8025A530u;
    // 8025A530: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8025A534:
    ctx->pc = 0x8025A534u;
    // 8025A534: lbz     r6, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_8025A538:
    ctx->pc = 0x8025A538u;
    // 8025A538: lwz     r7, 168(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(168);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8025A53C:
    ctx->pc = 0x8025A53Cu;
    // 8025A53C: lbz     r5, 1(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(1);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_8025A540:
    ctx->pc = 0x8025A540u;
    // 8025A540: lbz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8025A544:
    ctx->pc = 0x8025A544u;
    // 8025A544: rlwinm r7, r7, 0, 24, 31
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0x000000FFu;
    }

label_8025A548:
    ctx->pc = 0x8025A548u;
    // 8025A548: rlwimi r7, r6, 8, 16, 23
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[6], 8u);
        ctx->gpr[7] = (ctx->gpr[7] & ~0x0000FF00u) | (rot & 0x0000FF00u);
    }

label_8025A54C:
    ctx->pc = 0x8025A54Cu;
    // 8025A54C: rlwinm r4, r5, 16, 0, 15
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[5], 16u) & 0xFFFF0000u;
    }

label_8025A550:
    ctx->pc = 0x8025A550u;
    // 8025A550: rlwimi r4, r7, 0, 16, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[7], 0u);
        ctx->gpr[4] = (ctx->gpr[4] & ~0x0000FFFFu) | (rot & 0x0000FFFFu);
    }

label_8025A554:
    ctx->pc = 0x8025A554u;
    // 8025A554: rlwinm r7, r0, 24, 0, 7
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[0], 24u) & 0xFF000000u;
    }

label_8025A558:
    ctx->pc = 0x8025A558u;
    // 8025A558: rlwimi r7, r4, 0, 8, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[4], 0u);
        ctx->gpr[7] = (ctx->gpr[7] & ~0x00FFFFFFu) | (rot & 0x00FFFFFFu);
    }

label_8025A55C:
    ctx->pc = 0x8025A55Cu;
    // 8025A55C: b       0x8025A628
    {
            goto label_8025A628;
    }

label_8025A560:
    ctx->pc = 0x8025A560u;
    ctx->downcount -= 13;
    // 8025A560: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8025A564:
    ctx->pc = 0x8025A564u;
    // 8025A564: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8025A568:
    ctx->pc = 0x8025A568u;
    // 8025A568: lbz     r6, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_8025A56C:
    ctx->pc = 0x8025A56Cu;
    // 8025A56C: lwz     r7, 172(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(172);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8025A570:
    ctx->pc = 0x8025A570u;
    // 8025A570: lbz     r5, 1(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(1);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_8025A574:
    ctx->pc = 0x8025A574u;
    // 8025A574: lbz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8025A578:
    ctx->pc = 0x8025A578u;
    // 8025A578: rlwinm r7, r7, 0, 24, 31
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0x000000FFu;
    }

label_8025A57C:
    ctx->pc = 0x8025A57Cu;
    // 8025A57C: rlwimi r7, r6, 8, 16, 23
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[6], 8u);
        ctx->gpr[7] = (ctx->gpr[7] & ~0x0000FF00u) | (rot & 0x0000FF00u);
    }

label_8025A580:
    ctx->pc = 0x8025A580u;
    // 8025A580: rlwinm r4, r5, 16, 0, 15
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[5], 16u) & 0xFFFF0000u;
    }

label_8025A584:
    ctx->pc = 0x8025A584u;
    // 8025A584: rlwimi r4, r7, 0, 16, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[7], 0u);
        ctx->gpr[4] = (ctx->gpr[4] & ~0x0000FFFFu) | (rot & 0x0000FFFFu);
    }

label_8025A588:
    ctx->pc = 0x8025A588u;
    // 8025A588: rlwinm r7, r0, 24, 0, 7
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[0], 24u) & 0xFF000000u;
    }

label_8025A58C:
    ctx->pc = 0x8025A58Cu;
    // 8025A58C: rlwimi r7, r4, 0, 8, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[4], 0u);
        ctx->gpr[7] = (ctx->gpr[7] & ~0x00FFFFFFu) | (rot & 0x00FFFFFFu);
    }

label_8025A590:
    ctx->pc = 0x8025A590u;
    // 8025A590: b       0x8025A628
    {
            goto label_8025A628;
    }

label_8025A594:
    ctx->pc = 0x8025A594u;
    ctx->downcount -= 6;
    // 8025A594: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8025A598:
    ctx->pc = 0x8025A598u;
    // 8025A598: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8025A59C:
    ctx->pc = 0x8025A59Cu;
    // 8025A59C: lbz     r7, 3(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(3);
        ctx->gpr[7] = mem_read8(ctx, ea);
    }

label_8025A5A0:
    ctx->pc = 0x8025A5A0u;
    // 8025A5A0: lwz     r0, 168(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(168);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8025A5A4:
    ctx->pc = 0x8025A5A4u;
    // 8025A5A4: rlwimi r7, r0, 0, 0, 23
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[0], 0u);
        ctx->gpr[7] = (ctx->gpr[7] & ~0xFFFFFF00u) | (rot & 0xFFFFFF00u);
    }

label_8025A5A8:
    ctx->pc = 0x8025A5A8u;
    // 8025A5A8: b       0x8025A628
    {
            goto label_8025A628;
    }

label_8025A5AC:
    ctx->pc = 0x8025A5ACu;
    ctx->downcount -= 6;
    // 8025A5AC: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8025A5B0:
    ctx->pc = 0x8025A5B0u;
    // 8025A5B0: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8025A5B4:
    ctx->pc = 0x8025A5B4u;
    // 8025A5B4: lbz     r7, 3(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(3);
        ctx->gpr[7] = mem_read8(ctx, ea);
    }

label_8025A5B8:
    ctx->pc = 0x8025A5B8u;
    // 8025A5B8: lwz     r0, 172(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(172);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8025A5BC:
    ctx->pc = 0x8025A5BCu;
    // 8025A5BC: rlwimi r7, r0, 0, 0, 23
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[0], 0u);
        ctx->gpr[7] = (ctx->gpr[7] & ~0xFFFFFF00u) | (rot & 0xFFFFFF00u);
    }

label_8025A5C0:
    ctx->pc = 0x8025A5C0u;
    // 8025A5C0: b       0x8025A628
    {
            goto label_8025A628;
    }

label_8025A5C4:
    ctx->pc = 0x8025A5C4u;
    ctx->downcount -= 12;
    // 8025A5C4: lbz     r0, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8025A5C8:
    ctx->pc = 0x8025A5C8u;
    // 8025A5C8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8025A5CC:
    ctx->pc = 0x8025A5CCu;
    // 8025A5CC: lbz     r7, 3(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(3);
        ctx->gpr[7] = mem_read8(ctx, ea);
    }

label_8025A5D0:
    ctx->pc = 0x8025A5D0u;
    // 8025A5D0: rlwinm r6, r0, 8, 0, 23
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[0], 8u) & 0xFFFFFF00u;
    }

label_8025A5D4:
    ctx->pc = 0x8025A5D4u;
    // 8025A5D4: lbz     r5, 1(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(1);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_8025A5D8:
    ctx->pc = 0x8025A5D8u;
    // 8025A5D8: lbz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8025A5DC:
    ctx->pc = 0x8025A5DCu;
    // 8025A5DC: rlwimi r6, r7, 0, 24, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[7], 0u);
        ctx->gpr[6] = (ctx->gpr[6] & ~0x000000FFu) | (rot & 0x000000FFu);
    }

label_8025A5E0:
    ctx->pc = 0x8025A5E0u;
    // 8025A5E0: rlwinm r4, r5, 16, 0, 15
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[5], 16u) & 0xFFFF0000u;
    }

label_8025A5E4:
    ctx->pc = 0x8025A5E4u;
    // 8025A5E4: rlwimi r4, r6, 0, 16, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[6], 0u);
        ctx->gpr[4] = (ctx->gpr[4] & ~0x0000FFFFu) | (rot & 0x0000FFFFu);
    }

label_8025A5E8:
    ctx->pc = 0x8025A5E8u;
    // 8025A5E8: rlwinm r7, r0, 24, 0, 7
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[0], 24u) & 0xFF000000u;
    }

label_8025A5EC:
    ctx->pc = 0x8025A5ECu;
    // 8025A5EC: rlwimi r7, r4, 0, 8, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[4], 0u);
        ctx->gpr[7] = (ctx->gpr[7] & ~0x00FFFFFFu) | (rot & 0x00FFFFFFu);
    }

label_8025A5F0:
    ctx->pc = 0x8025A5F0u;
    // 8025A5F0: b       0x8025A628
    {
            goto label_8025A628;
    }

label_8025A5F4:
    ctx->pc = 0x8025A5F4u;
    ctx->downcount -= 12;
    // 8025A5F4: lbz     r0, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8025A5F8:
    ctx->pc = 0x8025A5F8u;
    // 8025A5F8: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8025A5FC:
    ctx->pc = 0x8025A5FCu;
    // 8025A5FC: lbz     r7, 3(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(3);
        ctx->gpr[7] = mem_read8(ctx, ea);
    }

label_8025A600:
    ctx->pc = 0x8025A600u;
    // 8025A600: rlwinm r6, r0, 8, 0, 23
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[0], 8u) & 0xFFFFFF00u;
    }

label_8025A604:
    ctx->pc = 0x8025A604u;
    // 8025A604: lbz     r5, 1(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(1);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_8025A608:
    ctx->pc = 0x8025A608u;
    // 8025A608: lbz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8025A60C:
    ctx->pc = 0x8025A60Cu;
    // 8025A60C: rlwimi r6, r7, 0, 24, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[7], 0u);
        ctx->gpr[6] = (ctx->gpr[6] & ~0x000000FFu) | (rot & 0x000000FFu);
    }

label_8025A610:
    ctx->pc = 0x8025A610u;
    // 8025A610: rlwinm r4, r5, 16, 0, 15
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[5], 16u) & 0xFFFF0000u;
    }

label_8025A614:
    ctx->pc = 0x8025A614u;
    // 8025A614: rlwimi r4, r6, 0, 16, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[6], 0u);
        ctx->gpr[4] = (ctx->gpr[4] & ~0x0000FFFFu) | (rot & 0x0000FFFFu);
    }

label_8025A618:
    ctx->pc = 0x8025A618u;
    // 8025A618: rlwinm r7, r0, 24, 0, 7
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[0], 24u) & 0xFF000000u;
    }

label_8025A61C:
    ctx->pc = 0x8025A61Cu;
    // 8025A61C: rlwimi r7, r4, 0, 8, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[4], 0u);
        ctx->gpr[7] = (ctx->gpr[7] & ~0x00FFFFFFu) | (rot & 0x00FFFFFFu);
    }

label_8025A620:
    ctx->pc = 0x8025A620u;
    // 8025A620: b       0x8025A628
    {
            goto label_8025A628;
    }

label_8025A624:
    ctx->pc = 0x8025A624u;
    ctx->downcount -= 1;
    // 8025A624: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_8025A628:
    ctx->pc = 0x8025A628u;
    ctx->downcount -= 14;
    // 8025A628: li      r0, 16
    ctx->gpr[0] = (u32)(s32)(16);

label_8025A62C:
    ctx->pc = 0x8025A62Cu;
    // 8025A62C: lwz     r4, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8025A630:
    ctx->pc = 0x8025A630u;
    // 8025A630: lis     r6, -13311
    ctx->gpr[6] = ((u32)(s32)(-13311) << 16);

label_8025A634:
    ctx->pc = 0x8025A634u;
    // 8025A634: stb     r0, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8025A638:
    ctx->pc = 0x8025A638u;
    // 8025A638: addi    r0, r3, 4106
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(4106);

label_8025A63C:
    ctx->pc = 0x8025A63Cu;
    // 8025A63C: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_8025A640:
    ctx->pc = 0x8025A640u;
    // 8025A640: stw     r0, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8025A644:
    ctx->pc = 0x8025A644u;
    // 8025A644: rlwinm r0, r3, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0xFFFFFFFCu;
    }

label_8025A648:
    ctx->pc = 0x8025A648u;
    // 8025A648: stw     r7, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8025A64C:
    ctx->pc = 0x8025A64Cu;
    // 8025A64C: sth     r5, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[5]);
    }

label_8025A650:
    ctx->pc = 0x8025A650u;
    // 8025A650: lwz     r3, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8025A654:
    ctx->pc = 0x8025A654u;
    // 8025A654: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8025A658:
    ctx->pc = 0x8025A658u;
    // 8025A658: stw     r7, 168(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(168);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8025A65C:
    ctx->pc = 0x8025A65Cu;
    // 8025A65C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_8025A660:
    ctx->pc = 0x8025A660u;
    ctx->downcount -= 2;
    // 8025A660: cmpwi   r3, 3
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8025A664:
    ctx->pc = 0x8025A664u;
    // 8025A664: bc    12, 2, 0x8025A714
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = 0x8025A714u;
            return;
        }
    }

label_8025A668:
    ctx->pc = 0x8025A668u;
    ctx->downcount -= 1;
    // 8025A668: bc    4, 0, 0x8025A684
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8025A684;
        }
    }

label_8025A66C:
    ctx->pc = 0x8025A66Cu;
    ctx->downcount -= 2;
    // 8025A66C: cmpwi   r3, 1
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

label_8025A670:
    ctx->pc = 0x8025A670u;
    // 8025A670: bc    12, 2, 0x8025A6C8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8025A6C8;
        }
    }

label_8025A674:
    ctx->pc = 0x8025A674u;
    ctx->downcount -= 1;
    // 8025A674: bc    4, 0, 0x8025A6FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            ctx->pc = 0x8025A6FCu;
            return;
        }
    }

label_8025A678:
    ctx->pc = 0x8025A678u;
    ctx->downcount -= 2;
    // 8025A678: cmpwi   r3, 0
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

label_8025A67C:
    ctx->pc = 0x8025A67Cu;
    // 8025A67C: bc    4, 0, 0x8025A694
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8025A694;
        }
    }

label_8025A680:
    ctx->pc = 0x8025A680u;
    ctx->downcount -= 1;
    // 8025A680: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_8025A684:
    ctx->pc = 0x8025A684u;
    ctx->downcount -= 2;
    // 8025A684: cmpwi   r3, 5
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(5);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8025A688:
    ctx->pc = 0x8025A688u;
    // 8025A688: bc    12, 2, 0x8025A75C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = 0x8025A75Cu;
            return;
        }
    }

label_8025A68C:
    ctx->pc = 0x8025A68Cu;
    ctx->downcount -= 1;
    // 8025A68C: bclr  4, 0
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_802566E0;
        }
    }

label_8025A690:
    ctx->pc = 0x8025A690u;
    ctx->downcount -= 1;
    // 8025A690: b       0x8025A72C
    {
            ctx->pc = 0x8025A72Cu;
            return;
    }

label_8025A694:
    ctx->pc = 0x8025A694u;
    ctx->downcount -= 13;
    // 8025A694: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8025A698:
    ctx->pc = 0x8025A698u;
    // 8025A698: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8025A69C:
    ctx->pc = 0x8025A69Cu;
    // 8025A69C: lbz     r6, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_8025A6A0:
    ctx->pc = 0x8025A6A0u;
    // 8025A6A0: lwz     r7, 176(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(176);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8025A6A4:
    ctx->pc = 0x8025A6A4u;
    // 8025A6A4: lbz     r5, 1(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(1);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_8025A6A8:
    ctx->pc = 0x8025A6A8u;
    // 8025A6A8: lbz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8025A6AC:
    ctx->pc = 0x8025A6ACu;
    // 8025A6AC: rlwinm r7, r7, 0, 24, 31
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0x000000FFu;
    }

label_8025A6B0:
    ctx->pc = 0x8025A6B0u;
    // 8025A6B0: rlwimi r7, r6, 8, 16, 23
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[6], 8u);
        ctx->gpr[7] = (ctx->gpr[7] & ~0x0000FF00u) | (rot & 0x0000FF00u);
    }

label_8025A6B4:
    ctx->pc = 0x8025A6B4u;
    // 8025A6B4: rlwinm r4, r5, 16, 0, 15
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[5], 16u) & 0xFFFF0000u;
    }

label_8025A6B8:
    ctx->pc = 0x8025A6B8u;
    // 8025A6B8: rlwimi r4, r7, 0, 16, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[7], 0u);
        ctx->gpr[4] = (ctx->gpr[4] & ~0x0000FFFFu) | (rot & 0x0000FFFFu);
    }

label_8025A6BC:
    ctx->pc = 0x8025A6BCu;
    // 8025A6BC: rlwinm r7, r0, 24, 0, 7
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[0], 24u) & 0xFF000000u;
    }

label_8025A6C0:
    ctx->pc = 0x8025A6C0u;
    // 8025A6C0: rlwimi r7, r4, 0, 8, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[4], 0u);
        ctx->gpr[7] = (ctx->gpr[7] & ~0x00FFFFFFu) | (rot & 0x00FFFFFFu);
    }

label_8025A6C4:
    ctx->pc = 0x8025A6C4u;
    // 8025A6C4: b       0x8025A790
    {
            ctx->pc = 0x8025A790u;
            return;
    }

label_8025A6C8:
    ctx->pc = 0x8025A6C8u;
    ctx->downcount -= 6;
    // 8025A6C8: lwz     r5, -27608(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27608);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8025A6CC:
    ctx->pc = 0x8025A6CCu;
    // 8025A6CC: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8025A6D0:
    ctx->pc = 0x8025A6D0u;
    // 8025A6D0: lbz     r6, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_8025A6D4:
    ctx->pc = 0x8025A6D4u;
    // 8025A6D4: lwz     r7, 180(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(180);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8025A6D8:
    ctx->pc = 0x8025A6D8u;
    // 8025A6D8: lbz     r5, 1(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(1);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_8025A6DC:
    ctx->pc = 0x8025A6DCu;
    // 8025A6DC: lbz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

    ctx->pc = 0x8025A6E0u;
    return;
return_dispatch_802566E0:
    if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) return;
    switch (ctx->pc) {
    case 0x802566E8u: goto label_802566E8;
    case 0x802566F4u: goto label_802566F4;
    case 0x80256704u: goto label_80256704;
    case 0x80256710u: goto label_80256710;
    case 0x80256714u: goto label_80256714;
    case 0x80256774u: goto label_80256774;
    case 0x80256788u: goto label_80256788;
    case 0x80256794u: goto label_80256794;
    case 0x802567C8u: goto label_802567C8;
    case 0x802567D4u: goto label_802567D4;
    case 0x802567E4u: goto label_802567E4;
    case 0x80256830u: goto label_80256830;
    case 0x80256838u: goto label_80256838;
    case 0x80256844u: goto label_80256844;
    case 0x8025684Cu: goto label_8025684C;
    case 0x80256854u: goto label_80256854;
    case 0x802568ACu: goto label_802568AC;
    case 0x802568BCu: goto label_802568BC;
    case 0x802568FCu: goto label_802568FC;
    case 0x80256928u: goto label_80256928;
    case 0x8025696Cu: goto label_8025696C;
    case 0x802569C8u: goto label_802569C8;
    case 0x802569D4u: goto label_802569D4;
    case 0x802569DCu: goto label_802569DC;
    case 0x802569F4u: goto label_802569F4;
    case 0x80256A08u: goto label_80256A08;
    case 0x80256A48u: goto label_80256A48;
    case 0x80256A7Cu: goto label_80256A7C;
    case 0x80256A84u: goto label_80256A84;
    case 0x80256A90u: goto label_80256A90;
    case 0x80256B80u: goto label_80256B80;
    case 0x80256B88u: goto label_80256B88;
    case 0x80256BA0u: goto label_80256BA0;
    case 0x80256BA8u: goto label_80256BA8;
    case 0x80256BB4u: goto label_80256BB4;
    case 0x80256BB8u: goto label_80256BB8;
    case 0x80256BC0u: goto label_80256BC0;
    case 0x80256BE8u: goto label_80256BE8;
    case 0x80256C14u: goto label_80256C14;
    case 0x80256C1Cu: goto label_80256C1C;
    case 0x80256CBCu: goto label_80256CBC;
    case 0x80256DF0u: goto label_80256DF0;
    case 0x80256DF8u: goto label_80256DF8;
    case 0x80256E30u: goto label_80256E30;
    case 0x80256E38u: goto label_80256E38;
    case 0x80256E8Cu: goto label_80256E8C;
    case 0x80256E94u: goto label_80256E94;
    case 0x80256EBCu: goto label_80256EBC;
    case 0x80256F00u: goto label_80256F00;
    case 0x80256F2Cu: goto label_80256F2C;
    case 0x80256F34u: goto label_80256F34;
    case 0x80256F38u: goto label_80256F38;
    case 0x802570A0u: goto label_802570A0;
    case 0x802570A8u: goto label_802570A8;
    case 0x802570D8u: goto label_802570D8;
    case 0x80257104u: goto label_80257104;
    case 0x8025710Cu: goto label_8025710C;
    case 0x8025711Cu: goto label_8025711C;
    case 0x80257120u: goto label_80257120;
    case 0x8025714Cu: goto label_8025714C;
    case 0x80257154u: goto label_80257154;
    case 0x80257164u: goto label_80257164;
    case 0x80257A10u: goto label_80257A10;
    case 0x80257D30u: goto label_80257D30;
    case 0x802587B0u: goto label_802587B0;
    case 0x80258B40u: goto label_80258B40;
    case 0x80258C30u: goto label_80258C30;
    case 0x80258C5Cu: goto label_80258C5C;
    case 0x80258C7Cu: goto label_80258C7C;
    case 0x80258C90u: goto label_80258C90;
    case 0x80258CCCu: goto label_80258CCC;
    case 0x80258CE4u: goto label_80258CE4;
    case 0x80258D14u: goto label_80258D14;
    case 0x80258D28u: goto label_80258D28;
    case 0x80258D4Cu: goto label_80258D4C;
    case 0x80258D88u: goto label_80258D88;
    case 0x80258DD0u: goto label_80258DD0;
    case 0x80258DFCu: goto label_80258DFC;
    case 0x80258E04u: goto label_80258E04;
    case 0x80259014u: goto label_80259014;
    case 0x8025901Cu: goto label_8025901C;
    case 0x8025902Cu: goto label_8025902C;
    case 0x80259034u: goto label_80259034;
    case 0x8025903Cu: goto label_8025903C;
    case 0x802590ACu: goto label_802590AC;
    case 0x802590B4u: goto label_802590B4;
    case 0x802590C0u: goto label_802590C0;
    case 0x802590C8u: goto label_802590C8;
    case 0x802590D0u: goto label_802590D0;
    case 0x802590D8u: goto label_802590D8;
    case 0x80259108u: goto label_80259108;
    case 0x80259118u: goto label_80259118;
    case 0x80259120u: goto label_80259120;
    case 0x80259128u: goto label_80259128;
    case 0x80259130u: goto label_80259130;
    case 0x8025918Cu: goto label_8025918C;
    case 0x802591A0u: goto label_802591A0;
    case 0x802591B4u: goto label_802591B4;
    case 0x802591C8u: goto label_802591C8;
    case 0x802591DCu: goto label_802591DC;
    case 0x802591F0u: goto label_802591F0;
    case 0x8025924Cu: goto label_8025924C;
    case 0x80259260u: goto label_80259260;
    case 0x80259274u: goto label_80259274;
    case 0x80259288u: goto label_80259288;
    case 0x8025929Cu: goto label_8025929C;
    case 0x802592B0u: goto label_802592B0;
    case 0x802592D0u: goto label_802592D0;
    case 0x802597ECu: goto label_802597EC;
    case 0x80259940u: goto label_80259940;
    case 0x8025A088u: goto label_8025A088;
    default: return;
    }
}

