// DolRecomp output
// cpu: gekko

#ifndef RECOMP_GENERATED_H
#define RECOMP_GENERATED_H

#define DOLRECOMP_CPU_GEKKO 1
#define DOLRECOMP_CPU_NAME "gekko"

#include <string.h>
#include <math.h>
#ifndef DOLRECOMP_CPU_HEADER
#define DOLRECOMP_CPU_HEADER "cpu/cpu.h"
#endif
#include DOLRECOMP_CPU_HEADER

#ifndef DOLRECOMP_C_LOOP_CYCLE_BUDGET
#define DOLRECOMP_C_LOOP_CYCLE_BUDGET 256
#endif

/* Cross-chunk calls turn guest recursion into host recursion, and a
   chunk frame is not small. Without a ceiling a deep guest call chain
   overflows the host stack, which is a crash rather than a slow
   emulator. Past the limit the call site falls back to returning to
   the chassis, which is always correct -- ctx->pc already names the
   target, so the chassis simply dispatches it as it did before.
   The counter is plain static, not atomic: the chassis runs the module
   on one CPU thread. */
#ifndef DOLRECOMP_C_MAX_CALL_DEPTH
#define DOLRECOMP_C_MAX_CALL_DEPTH 24
#endif
extern unsigned dolrecomp_call_depth;
static inline int dolrecomp_call_enter(void) {
    if (dolrecomp_call_depth >= (unsigned)DOLRECOMP_C_MAX_CALL_DEPTH)
        return 0;
    dolrecomp_call_depth++;
    return 1;
}
static inline void dolrecomp_call_leave(void) {
    if (dolrecomp_call_depth)
        dolrecomp_call_depth--;
}

static inline u32 dolrecomp_rotl32(u32 value, u32 sh) {
    sh &= 31u;
    return sh ? ((value << sh) | (value >> (32u - sh))) : value;
}

static inline f64 dolrecomp_f32_from_bits(u32 bits) {
    u64 x = bits;
    u64 exp = (x >> 23) & 0xFFu;
    u64 frac = x & 0x007FFFFFu;
    u64 result;
    if (exp > 0 && exp < 255) {
        u64 y = !(exp >> 7);
        u64 z = (y << 61) | (y << 60) | (y << 59);
        result = ((x & 0xC0000000u) << 32) | z |
                 ((x & 0x3FFFFFFFu) << 29);
    } else if (exp == 0 && frac != 0) {
        exp = 1023 - 126;
        do {
            frac <<= 1;
            exp -= 1;
        } while ((frac & 0x00800000u) == 0);
        result = ((x & 0x80000000u) << 32) | (exp << 52) |
                 ((frac & 0x007FFFFFu) << 29);
    } else {
        u64 y = exp >> 7;
        u64 z = (y << 61) | (y << 60) | (y << 59);
        result = ((x & 0xC0000000u) << 32) | z |
                 ((x & 0x3FFFFFFFu) << 29);
    }
    f64 value;
    memcpy(&value, &result, sizeof(value));
    return value;
}

static inline u32 dolrecomp_f32_to_bits(f64 value) {
    u64 bits;
    memcpy(&bits, &value, sizeof(bits));
    u32 exp = (u32)((bits >> 52) & 0x7FFu);
    if (exp > 896 || (bits & 0x7FFFFFFFFFFFFFFFull) == 0) {
        return (u32)(((bits >> 32) & 0xC0000000u) |
                     ((bits >> 29) & 0x3FFFFFFFu));
    }
    if (exp >= 874) {
        u32 result =
            (u32)(0x80000000u | ((bits & 0x000FFFFFFFFFFFFFull) >> 21));
        result >>= 905 - exp;
        result |= (u32)((bits >> 32) & 0x80000000u);
        return result;
    }
    return (u32)(((bits >> 32) & 0xC0000000u) |
                 ((bits >> 29) & 0x3FFFFFFFu));
}

static inline f64 dolrecomp_f64_from_bits(u64 bits) {
    f64 value;
    memcpy(&value, &bits, sizeof(value));
    return value;
}

static inline u64 dolrecomp_f64_to_bits(f64 value) {
    u64 bits;
    memcpy(&bits, &value, sizeof(bits));
    return bits;
}

static inline f64 dolrecomp_ps_from_bits(u32 bits) {
    return dolrecomp_f32_from_bits(bits);
}

static inline u32 dolrecomp_ps_to_bits(f64 value) {
    return dolrecomp_f32_to_bits(value);
}


// Function entry points
void func_80003100(CPUState* ctx);
void func_800066E0(CPUState* ctx);
void func_8000A6E0(CPUState* ctx);
void func_8000E6E0(CPUState* ctx);
void func_800126E0(CPUState* ctx);
void func_800166E0(CPUState* ctx);
void func_8001A6E0(CPUState* ctx);
void func_8001E6E0(CPUState* ctx);
void func_800226E0(CPUState* ctx);
void func_800266E0(CPUState* ctx);
void func_8002A6E0(CPUState* ctx);
void func_8002E6E0(CPUState* ctx);
void func_800326E0(CPUState* ctx);
void func_800366E0(CPUState* ctx);
void func_8003A6E0(CPUState* ctx);
void func_8003E6E0(CPUState* ctx);
void func_800426E0(CPUState* ctx);
void func_800466E0(CPUState* ctx);
void func_8004A6E0(CPUState* ctx);
void func_8004E6E0(CPUState* ctx);
void func_800526E0(CPUState* ctx);
void func_800566E0(CPUState* ctx);
void func_8005A6E0(CPUState* ctx);
void func_8005E6E0(CPUState* ctx);
void func_800626E0(CPUState* ctx);
void func_800666E0(CPUState* ctx);
void func_8006A6E0(CPUState* ctx);
void func_8006E6E0(CPUState* ctx);
void func_800726E0(CPUState* ctx);
void func_800766E0(CPUState* ctx);
void func_8007A6E0(CPUState* ctx);
void func_8007E6E0(CPUState* ctx);
void func_800826E0(CPUState* ctx);
void func_800866E0(CPUState* ctx);
void func_8008A6E0(CPUState* ctx);
void func_8008E6E0(CPUState* ctx);
void func_800926E0(CPUState* ctx);
void func_800966E0(CPUState* ctx);
void func_8009A6E0(CPUState* ctx);
void func_8009E6E0(CPUState* ctx);
void func_800A26E0(CPUState* ctx);
void func_800A66E0(CPUState* ctx);
void func_800AA6E0(CPUState* ctx);
void func_800AE6E0(CPUState* ctx);
void func_800B26E0(CPUState* ctx);
void func_800B66E0(CPUState* ctx);
void func_800BA6E0(CPUState* ctx);
void func_800BE6E0(CPUState* ctx);
void func_800C26E0(CPUState* ctx);
void func_800C66E0(CPUState* ctx);
void func_800CA6E0(CPUState* ctx);
void func_800CE6E0(CPUState* ctx);
void func_800D26E0(CPUState* ctx);
void func_800D66E0(CPUState* ctx);
void func_800DA6E0(CPUState* ctx);
void func_800DE6E0(CPUState* ctx);
void func_800E26E0(CPUState* ctx);
void func_800E66E0(CPUState* ctx);
void func_800EA6E0(CPUState* ctx);
void func_800EE6E0(CPUState* ctx);
void func_800F26E0(CPUState* ctx);
void func_800F66E0(CPUState* ctx);
void func_800FA6E0(CPUState* ctx);
void func_800FE6E0(CPUState* ctx);
void func_801026E0(CPUState* ctx);
void func_801066E0(CPUState* ctx);
void func_8010A6E0(CPUState* ctx);
void func_8010E6E0(CPUState* ctx);
void func_801126E0(CPUState* ctx);
void func_801166E0(CPUState* ctx);
void func_8011A6E0(CPUState* ctx);
void func_8011E6E0(CPUState* ctx);
void func_801226E0(CPUState* ctx);
void func_801266E0(CPUState* ctx);
void func_8012A6E0(CPUState* ctx);
void func_8012E6E0(CPUState* ctx);
void func_801326E0(CPUState* ctx);
void func_801366E0(CPUState* ctx);
void func_8013A6E0(CPUState* ctx);
void func_8013E6E0(CPUState* ctx);
void func_801426E0(CPUState* ctx);
void func_801466E0(CPUState* ctx);
void func_8014A6E0(CPUState* ctx);
void func_8014E6E0(CPUState* ctx);
void func_801526E0(CPUState* ctx);
void func_801566E0(CPUState* ctx);
void func_8015A6E0(CPUState* ctx);
void func_8015E6E0(CPUState* ctx);
void func_801626E0(CPUState* ctx);
void func_801666E0(CPUState* ctx);
void func_8016A6E0(CPUState* ctx);
void func_8016E6E0(CPUState* ctx);
void func_801726E0(CPUState* ctx);
void func_801766E0(CPUState* ctx);
void func_8017A6E0(CPUState* ctx);
void func_8017E6E0(CPUState* ctx);
void func_801826E0(CPUState* ctx);
void func_801866E0(CPUState* ctx);
void func_8018A6E0(CPUState* ctx);
void func_8018E6E0(CPUState* ctx);
void func_801926E0(CPUState* ctx);
void func_801966E0(CPUState* ctx);
void func_8019A6E0(CPUState* ctx);
void func_8019E6E0(CPUState* ctx);
void func_801A26E0(CPUState* ctx);
void func_801A66E0(CPUState* ctx);
void func_801AA6E0(CPUState* ctx);
void func_801AE6E0(CPUState* ctx);
void func_801B26E0(CPUState* ctx);
void func_801B66E0(CPUState* ctx);
void func_801BA6E0(CPUState* ctx);
void func_801BE6E0(CPUState* ctx);
void func_801C26E0(CPUState* ctx);
void func_801C66E0(CPUState* ctx);
void func_801CA6E0(CPUState* ctx);
void func_801CE6E0(CPUState* ctx);
void func_801D26E0(CPUState* ctx);
void func_801D66E0(CPUState* ctx);
void func_801DA6E0(CPUState* ctx);
void func_801DE6E0(CPUState* ctx);
void func_801E26E0(CPUState* ctx);
void func_801E66E0(CPUState* ctx);
void func_801EA6E0(CPUState* ctx);
void func_801EE6E0(CPUState* ctx);
void func_801F26E0(CPUState* ctx);
void func_801F66E0(CPUState* ctx);
void func_801FA6E0(CPUState* ctx);
void func_801FE6E0(CPUState* ctx);
void func_802026E0(CPUState* ctx);
void func_802066E0(CPUState* ctx);
void func_8020A6E0(CPUState* ctx);
void func_8020E6E0(CPUState* ctx);
void func_802126E0(CPUState* ctx);
void func_802166E0(CPUState* ctx);
void func_8021A6E0(CPUState* ctx);
void func_8021E6E0(CPUState* ctx);
void func_802226E0(CPUState* ctx);
void func_802266E0(CPUState* ctx);
void func_8022A6E0(CPUState* ctx);
void func_8022E6E0(CPUState* ctx);
void func_802326E0(CPUState* ctx);
void func_802366E0(CPUState* ctx);
void func_8023A6E0(CPUState* ctx);
void func_8023E6E0(CPUState* ctx);
void func_802426E0(CPUState* ctx);
void func_802466E0(CPUState* ctx);
void func_8024A6E0(CPUState* ctx);
void func_8024E6E0(CPUState* ctx);
void func_802526E0(CPUState* ctx);
void func_802566E0(CPUState* ctx);
void func_8025A6E0(CPUState* ctx);
void func_8025E6E0(CPUState* ctx);
void func_802626E0(CPUState* ctx);
void func_802666E0(CPUState* ctx);
void func_8026A6E0(CPUState* ctx);
void func_8026E6E0(CPUState* ctx);
void func_802726E0(CPUState* ctx);
void func_802766E0(CPUState* ctx);
void func_8027A6E0(CPUState* ctx);
void func_8027E6E0(CPUState* ctx);
void func_802826E0(CPUState* ctx);
void func_802866E0(CPUState* ctx);
void func_8028A6E0(CPUState* ctx);
void func_8028E6E0(CPUState* ctx);
void func_802926E0(CPUState* ctx);
void func_802966E0(CPUState* ctx);
void func_8029A6E0(CPUState* ctx);
void func_8029E6E0(CPUState* ctx);
void func_802A26E0(CPUState* ctx);
void func_802A66E0(CPUState* ctx);
void func_802AA6E0(CPUState* ctx);
void func_802AE6E0(CPUState* ctx);
void func_802B26E0(CPUState* ctx);
void func_802B66E0(CPUState* ctx);
void func_802BA6E0(CPUState* ctx);
void func_802BE6E0(CPUState* ctx);

#define DOLRECOMP_ENTRY_POINT 0x80003140u

typedef void (*DolRecompFunction)(CPUState* ctx);

#if defined(__GNUC__) || defined(__clang__)
#define DOLRECOMP_UNUSED __attribute__((unused))
#else
#define DOLRECOMP_UNUSED
#endif

#if defined(DOLRECOMP_ENABLE_REPLACEMENTS)
int dolrecomp_dispatch_replacement(CPUState* ctx, u32 address);
#else
static inline int dolrecomp_dispatch_replacement(CPUState* ctx, u32 address) {
    (void)ctx;
    (void)address;
    return 0;
}
#endif

static inline DolRecompFunction dolrecomp_find_original(u32 address) {
    if (address >= 0x80003100u && address < 0x80005620u && ((address - 0x80003100u) & 3u) == 0u) return func_80003100;
    {
        u32 offset = address - 0x800066E0u;
        if (offset < 0x002BBB20u && (offset & 3u) == 0u) {
            static const DolRecompFunction chunk_functions[] = {
                func_800066E0,
                func_8000A6E0,
                func_8000E6E0,
                func_800126E0,
                func_800166E0,
                func_8001A6E0,
                func_8001E6E0,
                func_800226E0,
                func_800266E0,
                func_8002A6E0,
                func_8002E6E0,
                func_800326E0,
                func_800366E0,
                func_8003A6E0,
                func_8003E6E0,
                func_800426E0,
                func_800466E0,
                func_8004A6E0,
                func_8004E6E0,
                func_800526E0,
                func_800566E0,
                func_8005A6E0,
                func_8005E6E0,
                func_800626E0,
                func_800666E0,
                func_8006A6E0,
                func_8006E6E0,
                func_800726E0,
                func_800766E0,
                func_8007A6E0,
                func_8007E6E0,
                func_800826E0,
                func_800866E0,
                func_8008A6E0,
                func_8008E6E0,
                func_800926E0,
                func_800966E0,
                func_8009A6E0,
                func_8009E6E0,
                func_800A26E0,
                func_800A66E0,
                func_800AA6E0,
                func_800AE6E0,
                func_800B26E0,
                func_800B66E0,
                func_800BA6E0,
                func_800BE6E0,
                func_800C26E0,
                func_800C66E0,
                func_800CA6E0,
                func_800CE6E0,
                func_800D26E0,
                func_800D66E0,
                func_800DA6E0,
                func_800DE6E0,
                func_800E26E0,
                func_800E66E0,
                func_800EA6E0,
                func_800EE6E0,
                func_800F26E0,
                func_800F66E0,
                func_800FA6E0,
                func_800FE6E0,
                func_801026E0,
                func_801066E0,
                func_8010A6E0,
                func_8010E6E0,
                func_801126E0,
                func_801166E0,
                func_8011A6E0,
                func_8011E6E0,
                func_801226E0,
                func_801266E0,
                func_8012A6E0,
                func_8012E6E0,
                func_801326E0,
                func_801366E0,
                func_8013A6E0,
                func_8013E6E0,
                func_801426E0,
                func_801466E0,
                func_8014A6E0,
                func_8014E6E0,
                func_801526E0,
                func_801566E0,
                func_8015A6E0,
                func_8015E6E0,
                func_801626E0,
                func_801666E0,
                func_8016A6E0,
                func_8016E6E0,
                func_801726E0,
                func_801766E0,
                func_8017A6E0,
                func_8017E6E0,
                func_801826E0,
                func_801866E0,
                func_8018A6E0,
                func_8018E6E0,
                func_801926E0,
                func_801966E0,
                func_8019A6E0,
                func_8019E6E0,
                func_801A26E0,
                func_801A66E0,
                func_801AA6E0,
                func_801AE6E0,
                func_801B26E0,
                func_801B66E0,
                func_801BA6E0,
                func_801BE6E0,
                func_801C26E0,
                func_801C66E0,
                func_801CA6E0,
                func_801CE6E0,
                func_801D26E0,
                func_801D66E0,
                func_801DA6E0,
                func_801DE6E0,
                func_801E26E0,
                func_801E66E0,
                func_801EA6E0,
                func_801EE6E0,
                func_801F26E0,
                func_801F66E0,
                func_801FA6E0,
                func_801FE6E0,
                func_802026E0,
                func_802066E0,
                func_8020A6E0,
                func_8020E6E0,
                func_802126E0,
                func_802166E0,
                func_8021A6E0,
                func_8021E6E0,
                func_802226E0,
                func_802266E0,
                func_8022A6E0,
                func_8022E6E0,
                func_802326E0,
                func_802366E0,
                func_8023A6E0,
                func_8023E6E0,
                func_802426E0,
                func_802466E0,
                func_8024A6E0,
                func_8024E6E0,
                func_802526E0,
                func_802566E0,
                func_8025A6E0,
                func_8025E6E0,
                func_802626E0,
                func_802666E0,
                func_8026A6E0,
                func_8026E6E0,
                func_802726E0,
                func_802766E0,
                func_8027A6E0,
                func_8027E6E0,
                func_802826E0,
                func_802866E0,
                func_8028A6E0,
                func_8028E6E0,
                func_802926E0,
                func_802966E0,
                func_8029A6E0,
                func_8029E6E0,
                func_802A26E0,
                func_802A66E0,
                func_802AA6E0,
                func_802AE6E0,
                func_802B26E0,
                func_802B66E0,
                func_802BA6E0,
                func_802BE6E0,
            };
            return chunk_functions[offset / 0x00004000u];
        }
    }
    return NULL;
}

static inline int dolrecomp_call_original(CPUState* ctx, u32 address) {
    DolRecompFunction fn = dolrecomp_find_original(address);
    if (!fn) return 0;
    ctx->pc = address;
    fn(ctx);
    return 1;
}

static inline bool dolrecomp_physical_pc_alias(CPUState* ctx, u32 address, u32* alias_out) {
    if (address < ctx->ram_size) {
        *alias_out = address | GC_RAM_BASE;
        return *alias_out != address;
    }
    return false;
}

static inline int dolrecomp_call(CPUState* ctx, u32 address) {
    u32 alias;
    ctx->pc = address;
    if (dolrecomp_dispatch_replacement(ctx, address)) return 1;
    if (ctx->host_call && ppc_host_call(ctx, address)) return 1;
    if (dolrecomp_call_original(ctx, address)) return 1;
    if (dolrecomp_physical_pc_alias(ctx, address, &alias)) {
        ctx->pc = alias;
        if (dolrecomp_dispatch_replacement(ctx, alias)) return 1;
        if (ctx->host_call && ppc_host_call(ctx, alias)) return 1;
        if (dolrecomp_call_original(ctx, alias)) return 1;
    }
    return 0;
}

static inline DOLRECOMP_UNUSED int dolrecomp_run_blocks(CPUState* ctx, u32 max_blocks) {
    u32 blocks = 0;
    while (max_blocks == 0u || blocks < max_blocks) {
        if (!dolrecomp_call(ctx, ctx->pc)) return 0;
        if (ctx->exception) return 0;
        blocks++;
    }
    return 1;
}

#undef DOLRECOMP_UNUSED

#endif /* RECOMP_GENERATED_H */

// end
