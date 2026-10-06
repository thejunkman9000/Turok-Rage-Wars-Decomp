#ifndef B10_TYPES_H
#define B10_TYPES_H

#include "p1_types.h"

typedef struct B10Ent {
    /* 0x000 */ u8 c0;
    u8 pad1[0x27];
} B10Ent;

typedef struct B10Ctl {
    /* 0x000 */ void* p0;
    /* 0x004 */ s32 f4;
    s32 unk8;
    /* 0x00C */ void* fn0C;
    /* 0x010 */ void* fn10;
    s32 unk14;
    s32 unk18;
    /* 0x01C */ f32 f1C;
    /* 0x020 */ f32 f20;
    s32 unk24;
    s32 unk28;
    /* 0x02C */ f32 f2C;
    /* 0x030 */ f32 f30;
    /* 0x034 */ f32 f34;
    /* 0x038 */ s32 f38;
    /* 0x03C */ s32 f3C;
    /* 0x040 */ s32 f40;
    /* 0x044 */ s32 f44;
    /* 0x048 */ s32 f48;
    s32 unk4C;
    /* 0x050 */ s32 f50;
    /* 0x054 */ s32 f54;
    s32 unk58;
    /* 0x05C */ s32 f5C;
    /* 0x060 */ s32 f60;
    /* 0x064 */ f32 f64;
    s32 unk68;
    s32 unk6C;
    s32 unk70;
    s32 unk74;
    s32 unk78;
    s32 unk7C;
    s32 unk80;
    s32 unk84;
    s32 unk88;
    s32 unk8C;
    s32 unk90;
    s32 unk94;
    s32 unk98;
    s32 unk9C;
    /* 0x0A0 */ f32 fA0;
    s32 unkA4;
    /* 0x0A8 */ s32 fA8;
    /* 0x0AC */ s32 fAC;
    /* 0x0B0 */ s32 fB0;
    /* 0x0B4 */ s32 fB4;
    s32 unkB8;
    s32 unkBC;
    s32 unkC0;
    s32 unkC4;
    s32 unkC8;
    s32 unkCC;
    s32 unkD0;
    s32 unkD4;
    /* 0x0D8 */ s32 fD8;
    /* 0x0DC */ s32 fDC;
    /* 0x0E0 */ s32 fE0;
    /* 0x0E4 */ void* fE4;
    /* 0x0E8 */ void* fE8;
    s32 unkEC;
    s32 unkF0;
    s32 unkF4;
    s32 unkF8;
    s32 unkFC;
    /* 0x100 */ f32 f100;
    /* 0x104 */ s32 f104;
    /* 0x108 */ s32 f108;
    /* 0x10C */ s32 f10C;
    /* 0x110 */ s32 f110;
    /* 0x114 */ s32 f114;
    /* 0x118 */ B10Ent ent[5];
    /* 0x1E0 */ s32 f1E0;
} B10Ctl;

typedef struct B10A {
    u8 pad0[0x1C];
    /* 0x01C */ f32 v1C[3];
    u8 pad28[0x10];
    /* 0x038 */ u32 f38;
    /* 0x03C */ u32 f3C;
    u8 pad40[0x1C];
    /* 0x05C */ f32 m5C[16];
} B10A;

typedef struct B10Vec {
    /* 0x000 */ f32 x;
    /* 0x004 */ f32 y;
    /* 0x008 */ f32 z;
} B10Vec;

typedef struct B10Pair {
    /* 0x000 */ s32 a;
    /* 0x004 */ s32 b;
} B10Pair;

typedef struct B10X {
    u8 pad0[0x68];
    /* 0x068 */ f32 m68[16];
    u8 padA8[0xC];
    /* 0x0B4 */ s32** pB4;
} B10X;

typedef struct B10Obj {
    /* 0x000 */ u8 type;
    u8 pad1[0x7];
    /* 0x008 */ s32 u8;
    /* 0x00C */ f32 fC;
    /* 0x010 */ s32 u10;
    /* 0x014 */ s32 u14;
    u8 pad18[0x4];
    /* 0x01C */ Vec3f v1C;
    u8 pad28[0x30];
    /* 0x058 */ B10X* p58;
    u8 pad5C[0x8];
    /* 0x064 */ f32 m64[16];
    /* 0x0A4 */ s32* pA4;
    u8 padA8[0x58];
    /* 0x100 */ u32 flags100;
} B10Obj;

typedef struct B10Blk {
    /* 0x000 */ s32 w[20];
} B10Blk;

typedef struct B10Q {
    /* 0x000 */ s32 w0;
    /* 0x004 */ u8 b4;
    /* 0x005 */ u8 b5;
    u8 pad6[0x16];
} B10Q;

typedef struct B10G {
    /* 0x000 */ s32 f0;
    u8 pad4[0x98];
    /* 0x09C */ s32 f9C;
} B10G;

typedef struct B10Pl {
    u8 pad0[0x57C];
    /* 0x57C */ s32 f57C;
    /* 0x580 */ s32 f580;
    u8 pad584[0xC];
    /* 0x590 */ s32 f590;
} B10Pl;

typedef struct B10Tgt {
    u8 pad0[0x29C];
    /* 0x29C */ f32 f29C;
    /* 0x2A0 */ f32 f2A0;
    /* 0x2A4 */ f32 f2A4;
    /* 0x2A8 */ f32 f2A8;
} B10Tgt;

#endif
