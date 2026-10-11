#ifndef S903_TYPES_H
#define S903_TYPES_H
/* types of func_0023A4D0 (textured ground shadow / decal quad emitter); names are provisional */
#include "types.h"

typedef struct SdV3 { f32 x, y, z; } SdV3;
typedef struct SdV4 { f32 x, y, z, w; } SdV4;

typedef struct SdInfo {
    /* 0x0 */ u8 type;
    /* 0x1 */ u8 div;
    /* 0x2 */ u8 shs;
    /* 0x3 */ u8 sht;
} SdInfo;

typedef struct SdRes {
    /* 0x0 */ s32 cnt;
    /* 0x4 */ s32 pad4;
    /* 0x8 */ SdInfo *info;
    /* 0xC */ s32 padC;
} SdRes;

typedef struct SdCls {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ u8 c1[3];
    /* 0x05 */ u8 c2[3];
    /* 0x08 */ u8 pad8[4];
    /* 0x0C */ f32 unkC;
    /* 0x10 */ u8 pad10[8];
    /* 0x18 */ f32 unk18;
    /* 0x1C */ u8 pad1C[0xC];
    /* 0x28 */ u8 unk28;
} SdCls;

typedef struct SdEmit {
    /* 0x000 */ u8 pad0[0xC];
    /* 0x00C */ SdCls *cls;
    /* 0x010 */ u8 pad10[4];
    /* 0x014 */ u8 sub[8];
    /* 0x01C */ f32 unk1C;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ u8 pad24[0x208 - 0x24];
    /* 0x208 */ f32 unk208;
    /* 0x20C */ f32 unk20C;
    /* 0x210 */ f32 unk210;
    /* 0x214 */ u8 pad214[4];
    /* 0x218 */ f32 unk218;
    /* 0x21C */ u8 pad21C[4];
    /* 0x220 */ f32 unk220;
} SdEmit;

typedef struct SdView {
    /* 0x000 */ u8 pad0[0x260];
    /* 0x260 */ SdV3 pos[5];
    /* 0x29C */ u8 pad29C[0x310 - 0x29C];
    /* 0x310 */ u8 mtx[1];
} SdView;

typedef struct SdVtx {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ s16 z;
    /* 0x6 */ s16 flag;
    /* 0x8 */ s16 u;
    /* 0xA */ s16 v;
    /* 0xC */ u8 col[4];
} SdVtx;

#endif
