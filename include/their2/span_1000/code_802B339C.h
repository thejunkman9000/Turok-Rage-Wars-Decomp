#ifndef UNBAKE_SPAN_1000_CODE_802B339C_H
#define UNBAKE_SPAN_1000_CODE_802B339C_H
#include "../types.h"
#include "common/types_1dc8418c21db.h"
struct ObjectState10_5;
/* unbake published declaration: published_2560f979cd7e7237a58c7839 */
typedef struct ObjectState10_5 ObjectState10_5;

struct ObjectState14_2;
/* unbake published declaration: published_258f10e9ef137e170564b1a6 */
typedef struct ObjectState14_2 ObjectState14_2;

struct func_802B8540_S1;
/* unbake published declaration: published_3bb9d184960f30ee4116a872 */
struct func_802B8540_S1 {
    char pad0[0x16];
    unsigned short unk16;
};

/* unbake published declaration: published_80af5ce7b112eaa4ea3805db */
typedef void ( *Shared_func_802B3540_de_FuncPtr)(void *, signed int, void *);

struct ObjectState1C;
/* unbake published declaration: published_84bd9ebff989666191e0878e */
typedef struct ObjectState1C ObjectState1C;

struct ALStartParamAlt;
struct Node_func_80239AF4_de;
/* unbake published declaration: published_86b00bdaf438fe0bfa435a77 */
struct ALStartParamAlt {
    struct Node_func_80239AF4_de *next;
    s32 delta;
    s16 type;
    s16 unity;
    f32 pitch;
    s16 volume;
    u8 pan;
    u8 fxMix;
    s32 samples;
    void *wave;
};

struct ALStartParamAlt;
/* unbake published declaration: published_908e79aefb7a93c4474603a4 */
typedef struct ALStartParamAlt ALStartParamAlt;

struct ObjectState1C;
/* unbake published declaration: published_90dc1bc1f77573d4c14ca3dd */
struct ObjectState1C {
    char pad0[0x8];
    ObjectLinks4_3 unk_8;
    char pad8[0x1A - 0x8 - sizeof(ObjectLinks4_3)];
    u16 unk_1A;
};

/* unbake published declaration: published_96ea728205c815660cae9816 */
extern void func_802B3540_de(void *arg0, void *arg1, s32 arg2);

struct func_802B8540_S1;
/* unbake published declaration: published_9bd2c136d674c93a088b127b */
typedef struct func_802B8540_S1 func_802B8540_S1;

struct ObjectState10_5;
/* unbake published declaration: published_e36616c5ef0e53f3a44765cd */
struct ObjectState10_5 {
    s32 unk_0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    s32 unk_4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    s16 unk_8;
    char pad8[0xA - 0x8 - sizeof(s16)];
    u16 unk_A;
    char padA[0xC - 0xA - sizeof(u16)];
    s32 unk_C;
};

/* unbake published declaration: published_e401d7d6486fccccbd0d7334 */
typedef void ( *Shared_func_802B3480_de_FuncPtr)(void *, signed int, void *);

struct ObjectState14_2;
/* unbake published declaration: published_f072ff563c8da6ca4b450283 */
struct ObjectState14_2 {
    s32 unk_0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    s32 unk_4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    s16 unk_8;
    char pad8[0xC - 0x8 - sizeof(s16)];
    s32 unk_C;
    char padC[0x10 - 0xC - sizeof(s32)];
    s32 unk_10;
};

extern void func_802B38B4_eu_x(void);
#endif
