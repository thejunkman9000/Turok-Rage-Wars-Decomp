#ifndef UNBAKE_SPAN_1000_CODE_802B53FC_H
#define UNBAKE_SPAN_1000_CODE_802B53FC_H
#include "acmd.h"
#include "audio_callbacks.h"
#include "../types.h"
#include "common/types_1dc8418c21db.h"
/* unbake published declaration: published_046f9b91cdb88c064d3a1184 */
extern float D_800C788C_de;

struct ALDelay28;
/* unbake published declaration: published_1436647867fa7a88b1e36c1c */
typedef struct ALDelay28 ALDelay28;

struct CallbackStateC;
/* unbake published declaration: published_149b3825b212559523416350 */
struct CallbackStateC {
    unsigned char padding_0[8];
    void (*callback)(void *, s32, s32);
};

struct ALDelay;
/* unbake published declaration: published_15866c75e467244331c797e4 */
typedef struct ALDelay ALDelay;

struct func_802BB32C_S2;
/* unbake published declaration: published_1a3222375ebdd272ab0cc375 */
typedef struct func_802BB32C_S2 func_802BB32C_S2;

struct ALResampler_s28;
/* unbake published declaration: published_1c2c26935619c55002af8d79 */
struct ALResampler_s28 {
    ALFilter_s14 filter;
    void *state;
    f32 ratio;
    s32 upitch;
    f32 delta;
    s32 first;
};

struct ALFilter_s14_2;
/* unbake published declaration: published_95879db5c6c4cfcc2bc21872 */
typedef struct ALFilter_s14_2 ALFilter_s14_2;

struct ALFilter_s14_2;
/* unbake published declaration: published_bb6055776d48a2ec54bad806 */
struct ALFilter_s14_2 {
    struct ALFilter_s14_2 *source;
    ALCmdHandler handler;
    void *setParam;
    s16 inp;
    s16 outp;
    s32 type;
};

struct ALResampler_s;
/* unbake published declaration: published_1da2f148b5ac09b65f6499fc */
struct ALResampler_s {
    ALFilter_s14_2 filter;
    void *state;
    f32 ratio;
    s32 upitch;
    f32 delta;
    s32 first;
    void *ctrlList;
    void *ctrlTail;
    s32 motion;
};

/* unbake published declaration: published_277471028a75ceb97cb06e23 */
extern void *func_802B625C_de(void *arg0, s32 arg1, s32 arg2, void *arg3);

/* unbake published declaration: published_2ae11f55665cfa199d084591 */
extern void *jtbl_800C7750[];

struct ALResampler_s28;
/* unbake published declaration: published_f47fd707481b892bd83d8bd8 */
typedef struct ALResampler_s28 ALResampler_s28;

struct ALDelay28;
/* unbake published declaration: published_4afa1b434ea04ebd6d4c1b03 */
struct ALDelay28 {
    u32 input;
    u32 output;
    s16 ffcoef;
    s16 fbcoef;
    s16 gain;
    f32 rsinc;
    f32 rsval;
    s32 rsdelta;
    f32 rsgain;
    void *lp;
    ALResampler_s28 *rs;
};

struct ALDelay;
/* unbake published declaration: published_5547b6eeecc164a01f81ad8f */
struct ALDelay {
    u32 input;
    u32 output;
    s16 ffcoef;
    s16 fbcoef;
    s16 gain;
    f32 rsinc;
    f32 rsval;
    s32 rsdelta;
    f32 rsgain;
    void *lp;
    void *rs;
};

struct ALResampler_s;
/* unbake published declaration: published_671868ecc935b797d76bcd2a */
typedef struct ALResampler_s ALResampler_s;

struct IntegerState34;
/* unbake published declaration: published_7a11fb6c7ed0b94df20b3647 */
typedef struct IntegerState34 IntegerState34;

struct ALFx;
/* unbake published declaration: published_7bac7f5789fedc358b3da938 */
typedef struct ALFx ALFx;

struct func_802BB32C_S2;
/* unbake published declaration: published_869c3a6d5e984b71115bd49d */
struct func_802BB32C_S2 {
    char pad0[0x2];
    u16 unk2;
    char pad2[0x28 - 0x2 - sizeof(u16)];
    s32 unk28;
    char pad28[0x2F - 0x28 - sizeof(s32)];
    u8 unk2F;
};

struct func_802BB32C_S1;
/* unbake published declaration: published_8a42947899385ea6e13ee637 */
struct func_802BB32C_S1 {
    s32 unk0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    s32 unk4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    s32 unk10;
    char pad10[0x14 - 0x10 - sizeof(s32)];
    s32 unk14;
};

struct func_802BB590_S1;
/* unbake published declaration: published_a19ae6301fee16ba522eb70c */
struct func_802BB590_S1 {
    char pad0[0x30];
    void * unk30;
    char pad30[0x34 - 0x30 - sizeof(void*)];
    s32 unk34;
};

struct func_802BB590_S1;
/* unbake published declaration: published_a727e5c4ed10fa33e59cae6b */
typedef struct func_802BB590_S1 func_802BB590_S1;

/* unbake published declaration: published_b0abf2144ad37d04248a34fd */
extern float D_800C7748_de;

/* unbake published declaration: published_c598833016a54ea3716363cb */
extern float D_800C7880_de;

/* unbake published declaration: published_c94c87fd8773b02e13e869e0 */
extern f32 func_802B6300_de(ALDelay *d, s32 count);

/* unbake published declaration: published_cbed1bd34ebd49b77f719300 */
extern float D_800C7888_de;

/* unbake published declaration: published_d39360bfa2b7c25a34db8a7e */
extern float D_800C7884_de;

struct IntegerState34;
/* unbake published declaration: published_da527718b01a6532acb5da30 */
struct IntegerState34 {
    char pad0[0x18];
    s32 unk_18;
    char pad18[0x1C - 0x18 - sizeof(s32)];
    s32 unk_1C;
    char pad1C[0x20 - 0x1C - sizeof(s32)];
    s32 unk_20;
    char pad20[0x24 - 0x20 - sizeof(s32)];
    s32 unk_24;
    char pad24[0x30 - 0x24 - sizeof(s32)];
    s32 unk_30;
};

struct func_802BB32C_S1;
/* unbake published declaration: published_df7436443c112054a2cb9451 */
typedef struct func_802BB32C_S1 func_802BB32C_S1;

struct CallbackStateC;
/* unbake published declaration: published_e4f74a998471933d1bd802e0 */
typedef struct CallbackStateC CallbackStateC;

struct ALFx;
/* unbake published declaration: published_e672387f8d8ca1a9ff39588e */
struct ALFx {
    ALFilter_s14 filter;
    s16 *base;
    s16 *input;
    u32 length;
    ALDelay28 *delay;
    u8 section_count;
    void *paramHdl;
};

/* unbake published declaration: published_eefcfc2bee3410ddf64c4f2b */
extern float D_800C7740_de;

#endif
