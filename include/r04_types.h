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
    u8 pad10[8];
    /* 0x18 */ u32 w18;
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


/* mover step (func_00243A80, round 3) */
typedef struct R4Hh {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ u16 h2;
} R4Hh;

typedef struct R4Ob {
    /* 0x00 */ u8 type;
    u8 pad1[7];
    /* 0x08 */ Vec3f pos;
    /* 0x14 */ R4Hh *p14;
    u8 pad18[4];
    /* 0x1C */ Vec3f vel;
    u8 pad28[0xC];
    /* 0x34 */ struct R4Ob *p34;
    /* 0x38 */ u32 flags38;
    u8 pad3C[4];
    /* 0x40 */ f32 f40;
    /* 0x44 */ Vec3f v44;
    u8 pad50[0x1C];
    /* 0x6C */ f32 f6C;
    u8 pad70[0x90];
    /* 0x100 */ u32 flags100;
} R4Ob;

typedef struct R4Mc {
    /* 0x00 */ R4Ob *o;
    /* 0x04 */ s32 ground;
    u8 pad8[8];
    /* 0x10 */ f32 f10;
    u8 pad14[8];
    /* 0x1C */ f32 f1C;
    /* 0x20 */ s32 w20;
    /* 0x24 */ s32 w24;
    /* 0x28 */ s32 w28;
    /* 0x2C */ s32 w2C;
    /* 0x30 */ s32 w30;
    /* 0x34 */ s32 w34;
    /* 0x38 */ s32 w38;
    /* 0x3C */ u32 flags;
    /* 0x40 */ u32 *fp;
    /* 0x44 */ Vec3f p44;
    /* 0x50 */ Vec3f p50;
    u8 pad5C[0x18];
    /* 0x74 */ Vec3f p74;
    u8 pad80[0x2C];
    /* 0xAC */ R4Hh *fAC;
    /* 0xB0 */ s32 kind;
    u8 padB4[4];
    /* 0xB8 */ s32 kindB;
    u8 padBC[0x3C];
    /* 0xF8 */ Vec3f nrm;
    /* 0x104 */ R4Ob *hitobj;
    u8 pad108[0x78];
    /* 0x180 */ Vec3f p180;
    u8 pad18C[0xC];
    /* 0x198 */ Vec3f p198;
    /* 0x1A4 */ Vec3f p1A4;
} R4Mc;

typedef struct R4Hit {
    u8 pad0[0x18];
    /* 0x18 */ Vec3f a;
    u8 pad24[0x24];
    /* 0x48 */ Vec3f b;
    u8 pad54[0x88];
} R4Hit;

typedef struct R4Fl7 {
    u32 w[7];
} R4Fl7;


/* collision vertex / context (func_00242FD8) */
typedef struct R4Vt {
    f32 x;
    f32 y;
    f32 z;
    u8 padC[0xC];
    u32 flags;
    s16 *src;
} R4Vt;

typedef struct R4Cx {
    R4Obj *obj;
    u8 pad4[0x48];
    f32 lim2;
    u8 pad50[0xC];
    s32 mode;
    u32 flags;
    f32 m[4][4];
    u8 *segbase;
} R4Cx;

#endif
