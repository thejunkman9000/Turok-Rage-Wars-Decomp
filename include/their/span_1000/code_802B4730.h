#ifndef UNBAKE_SPAN_1000_CODE_802B4730_H
#define UNBAKE_SPAN_1000_CODE_802B4730_H
#include "../types.h"
struct ALParam_s;
/* unbake published declaration: published_06eb294f18e00124c4cbbbe9 */
typedef struct ALParam_s ALParam_s;

struct func_802BA4B0_S1;
/* unbake published declaration: published_0c733061bf8fed6fa699f576 */
struct func_802BA4B0_S1 {
    int unk0;
    char pad0[0x4 - 0x0 - sizeof(int)];
    int unk4;
    char pad4[0x8 - 0x4 - sizeof(int)];
    int unk8;
    char pad8[0xC - 0x8 - sizeof(int)];
    short unkC;
    char padC[0xE - 0xC - sizeof(short)];
    short unkE;
    char padE[0x10 - 0xE - sizeof(short)];
    int unk10;
};

/* unbake published declaration: published_0d4e8aa895962cb5eb31038d */
extern float D_800C7708_de;

/* unbake published declaration: published_285fa96582c82b00598ff6c1 */
extern float D_800C75E0_de;

struct ALFilter_s;
/* unbake published declaration: published_705875a0304a2bf7308899c0 */
typedef struct ALFilter_s ALFilter_s;

struct ALFilter_s;
/* unbake published declaration: published_bd0410373429ab8aa665f7b9 */
struct ALFilter_s {
    struct ALFilter_s *source;
    void *handler;
    s32 (*setParam)(void *, s32, void *);
    s16 inp;
    s16 outp;
    s32 type;
};

struct ALParam_s;
/* unbake published declaration: published_e7c87c437c7e8853ac48c914 */
struct ALParam_s {
    struct ALParam_s *next;
    s32 delta;
    s32 type;
    union {
        s32 i;
        f32 f;
        void *p;
    } data;
};

struct ALEnvMixer;
struct ALFilter_s;
struct ALParam_s;
/* unbake published declaration: published_3bbe0042552999181cd1eb97 */
struct ALEnvMixer {
    ALFilter_s filter;
    void *state;
    s16 pan;
    s16 volume;
    s16 cvolL;
    s16 cvolR;
    s16 dryamt;
    s16 wetamt;
    u16 lratl;
    s16 lratm;
    s16 ltgt;
    u16 rratl;
    s16 rratm;
    s16 rtgt;
    s32 delta;
    s32 segEnd;
    s32 first;
    struct ALParam_s *ctrlList;
    struct ALParam_s *ctrlTail;
    struct ALFilter_s **sources;
    s32 motion;
};

/* unbake published declaration: published_c0037a8a8cc8050dc7336f04 */
typedef signed short AudioPoleFilterState[4];

struct AudioLowPassFilter;
/* unbake published declaration: published_9bd0345dc597caeea167f7a9 */
struct AudioLowPassFilter {
    s16 cutoff;
    s16 gain;
    union {
        s16 taps[16];
        s64 alignment;
    } coefficients;
    AudioPoleFilterState *state;
    s32 first;
};

struct AudioLowPassFilter;
/* unbake published declaration: published_e71b9318f4501301f3e0bdd3 */
typedef struct AudioLowPassFilter AudioLowPassFilter;

/* unbake published declaration: published_4273eedbf09e55fe520dd33c */
extern void func_802B468C_de(AudioLowPassFilter *lp);

struct func_802B95DC_S1;
/* unbake published declaration: published_494e2bda4c683e3ae35e46d0 */
typedef struct func_802B95DC_S1 func_802B95DC_S1;

struct LogTab;
/* unbake published declaration: published_96332719bd32b191ae34343b */
typedef struct LogTab LogTab;

struct LogTab;
/* unbake published declaration: published_e5090891e4d7c1ecb98e7b7c */
struct LogTab {
    f64 v[8];
};

/* unbake published declaration: published_80962e68f71e0e7b56af2d3c */
extern s16 func_802B4F68_de(f64 vol, f64 tgt, s32 count, u16 *ratel);

struct ALEnvMixer;
/* unbake published declaration: published_8577400049b1fcfd62556fd3 */
typedef struct ALEnvMixer ALEnvMixer;

/* unbake published declaration: published_9f4154edace0881cf1742c68 */
extern f64 func_802B53B4_de(f64 arg0, s32 arg1);

/* unbake published declaration: published_b3bbda3854cbc4e145d2f161 */
extern f64 func_802B5300_de(f64 arg0, s32 *arg2);

/* unbake published declaration: published_b8c2deea24ee86038ecc0b7a */
extern float D_800C770C_de;

struct func_802B95DC_S1;
/* unbake published declaration: published_d1e697f468c2222f15ecbd50 */
struct func_802B95DC_S1 {
    char pad0[0x14];
    s32 unk14;
    char pad14[0x18 - 0x14 - sizeof(s32)];
    f32 unk18;
    char pad18[0x1C - 0x18 - sizeof(f32)];
    s32 unk1C;
    char pad1C[0x20 - 0x1C - sizeof(s32)];
    s32 unk20;
    char pad20[0x24 - 0x20 - sizeof(s32)];
    s32 unk24;
    char pad24[0x28 - 0x24 - sizeof(s32)];
    s32 unk28;
    char pad28[0x2C - 0x28 - sizeof(s32)];
    s32 unk2C;
    char pad2C[0x30 - 0x2C - sizeof(s32)];
    s32 unk30;
};

struct func_802BA4B0_S1;
/* unbake published declaration: published_ef9b94684c821f711c965f18 */
typedef struct func_802BA4B0_S1 func_802BA4B0_S1;

/* unbake published declaration: published_fca0bea20f9041705f06bb4c */
extern f32 func_802B5288_de(f32 arg0, s32 arg1, s32 arg2, s32 arg3);

extern void func_802B4A08_eu_x(void);
#endif
