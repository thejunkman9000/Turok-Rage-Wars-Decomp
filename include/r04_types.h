#ifndef R04_TYPES_H
#define R04_TYPES_H

#include "p1_types.h"

/* mover step / collision triangle context (round 3, workspace r04) */
typedef struct R4Fl {
    /* 0x00 */ u32 flags;
    u8 pad4[1];
    /* 0x05 */ s8 b5;
    /* 0x06 */ s8 b6;
    u8 pad7[9];
    /* 0x10 */ f32 f10;
    u8 pad14[4];
    /* 0x18 */ f32 f18;
} R4Fl;

typedef struct R4Obj {
    u8 pad0[8];
    /* 0x08 */ f32 f8;
    /* 0x0C */ f32 fC;
    u8 pad10[0xC];
    /* 0x1C */ f32 f1C;
    u8 pad20[0x1C];
    /* 0x3C */ u32 flags3C;
    /* 0x40 */ R4Fl *p40;
} R4Obj;

typedef struct R4Ev {
    /* 0x00 */ s32 type;
    /* 0x04 */ f32 f4;
    /* 0x08 */ s32 f8;
    /* 0x0C */ s32 fC;
    /* 0x10 */ s32 f10;
    /* 0x14 */ s32 nv;
    /* 0x18 */ Vec3f v[3];
    u8 pad3C[0xC];
    /* 0x48 */ Vec3f n;
    /* 0x54 */ s32 f54;
    /* 0x58 */ s32 f58;
    u8 pad5C[0x84];
} R4Ev;

typedef struct R4Mat {
    u8 pad0[0x68];
    /* 0x68 */ f32 m[16];
} R4Mat;

typedef struct R4Vtx {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    u8 pad8[0x14];
    /* 0x1C */ s16 *pos;
} R4Vtx;

typedef struct R4Mv {
    /* 0x00 */ R4Obj *obj;
    u8 pad4[0x4C];
    /* 0x50 */ s32 cnt;
    /* 0x54 */ f32 step;
    /* 0x58 */ R4Mat *p58;
    /* 0x5C */ s32 mode;
    /* 0x60 */ u32 flags60;
} R4Mv;


/* player move step (func_00245D20) */
typedef struct R4Pl {
    /* 0x00 */ u8 type;
    u8 pad1[0x1F];
    /* 0x20 */ f32 f20;
    u8 pad24[4];
    /* 0x28 */ Vec3f v;
    /* 0x34 */ u8 pad34[4];
    /* 0x38 */ u32 flags;
    u8 pad3C[0x30];
    /* 0x6C */ f32 f6C;
} R4Pl;

typedef struct R4In {
    u8 pad0[0x52];
    /* 0x52 */ u16 f52;
    u8 pad54[9];
    /* 0x5D */ u8 b5D;
    u8 pad5E[1];
    /* 0x5F */ s8 b5F;
    /* 0x60 */ s8 b60;
    /* 0x61 */ s8 b61;
} R4In;

#endif
