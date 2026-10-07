#ifndef M04_TYPES_H
#define M04_TYPES_H

#include "common.h"

/* Types recovered in workspace m04 (leftover main-image functions). */
typedef struct M04Vec3 {
    f32 x, y, z;
} M04Vec3;

typedef union M04IF {
    s32 i;
    f32 f;
} M04IF;

/* sound effect / music channel object */
typedef struct M04Fx {
    /* 0x00 */ struct SndMgr *owner;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 state;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 idx;
    /* 0x14 */ s32 vol;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[2];
    /* 0x1E */ s16 snd;
    /* 0x20 */ f32 f20;
    /* 0x24 */ f32 f24;
} M04Fx;

/* animation / stream slot (20 bytes) */
typedef struct M04Anim {
    /* 0x00 */ s32 f0;
    /* 0x04 */ s16 f4;
    /* 0x06 */ s16 f6;
    /* 0x08 */ u16 f8;
    /* 0x0A */ u8 fA;
    /* 0x0B */ u8 fB;
    /* 0x0C */ s32 fC;
    /* 0x10 */ s32 f10;
} M04Anim;

typedef struct M04Pair16 {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ u16 w2;
    /* 0x04 */ u8 pad4[2];
    /* 0x06 */ u16 w6;
} M04Pair16;

/* particle / effect parameter block passed by value (8 bytes) */
typedef struct M04Part {
    s16 a;
    s16 b;
    u8 c[4];
} __attribute__((aligned(4))) M04Part;

/* sorted table header: count at +0xE, u32 values from +0x10 */
typedef struct M04SortTab {
    /* 0x00 */ u8 pad0[0xE];
    /* 0x0E */ s16 n;
    /* 0x10 */ u32 v[1];
} M04SortTab;

/* 12-byte record of six 16-bit words (copied with lwl/lwr) */
typedef struct M04Rec12 {
    u16 w0, w1, w2;
    s16 w3;
    u16 w4, w5;
} M04Rec12;

typedef struct M04Tgt {
    /* 0x000 */ u8 pad0[0x128];
    /* 0x128 */ f32 x;
    /* 0x12C */ f32 y;
    /* 0x130 */ f32 z;
    /* 0x134 */ u8 pad134[0x528 - 0x134];
    /* 0x528 */ f32 f528;
} M04Tgt;

typedef struct M04Ctx {
    /* 0x0000 */ u8 pad0[0x84];
    /* 0x0084 */ u8 player[0x58];
    /* 0x00DC */ s16 snd[16];
    /* 0x00FC */ u8 padFC[8];
    /* 0x0104 */ s32 unk104;
    /* 0x0108 */ u8 pad108[0x2B88 - 0x108];
    /* 0x2B88 */ u8 *tab2B88;
    /* 0x2B8C */ u8 pad2B8C[8];
    /* 0x2B94 */ s8 defaultPan;
    /* 0x2B95 */ u8 pad2B95[3];
    /* 0x2B98 */ M04Tgt *tgt;
    /* 0x2B9C */ u8 pad2B9C[4];
    /* 0x2BA0 */ f32 volA;
    /* 0x2BA4 */ f32 volB;
    /* 0x2BA8 */ f32 volC;
    /* 0x2BAC */ u8 pad2BAC[0xC];
    /* 0x2BB8 */ s32 unk2BB8;
} M04Ctx;

/* parameter block embedded at +0x10 of a sound voice slot */
typedef struct M04VP {
    /* 0x00 */ s32 w0;
    /* 0x04 */ s32 w4;
    /* 0x08 */ s32 vol;
    /* 0x0C */ s32 wC;
    /* 0x10 */ s16 s10;
    /* 0x12 */ u8 pad12[2];
    /* 0x14 */ M04IF v14;
    /* 0x18 */ s16 pan;
    /* 0x1A */ u8 pad1A[2];
    /* 0x1C */ f32 scale;
    /* 0x20 */ f32 f20;
    /* 0x24 */ f32 f24;
    /* 0x28 */ s16 s28;
    /* 0x2A */ s16 s2A;
    /* 0x2C */ s16 s2C;
    /* 0x2E */ u8 pad2E[6];
    /* 0x34 */ M04Vec3 pos;
    /* 0x40 */ s32 f40;
    /* 0x44 */ s8 mode;
    /* 0x45 */ u8 pad45[3];
    /* 0x48 */ f32 f48;
    /* 0x4C */ f32 f4C;
} M04VP;

/* sound voice slot (0xCC bytes) / emitter object */
typedef struct M04Emitter {
    /* 0x00 */ s32 w0;
    /* 0x04 */ s32 w4;
    /* 0x08 */ s32 w8;
    /* 0x0C */ s32 id;
    /* 0x10 */ M04VP vp;
    /* 0x60 */ M04Rec12 env;
    /* 0x6C */ f32 envA;
    /* 0x70 */ f32 envSlope0;
    /* 0x74 */ M04Rec12 env2;
    /* 0x80 */ f32 env2A;
    /* 0x84 */ f32 env2Slope;
    /* 0x88 */ s32 hasEnv;
    /* 0x8C */ M04Rec12 rec;
    /* 0x98 */ f32 env0;
    /* 0x9C */ f32 envSlope;
    /* 0xA0 */ s32 unkA0;
    /* 0xA4 */ u32 flags;
    /* 0xA8 */ s32 kind;
    /* 0xAC */ s32 unkAC;
    /* 0xB0 */ M04Ctx *ctx;
    /* 0xB4 */ s32 unkB4;
    /* 0xB8 */ f32 unkB8;
    /* 0xBC */ s32 unkBC;
    /* 0xC0 */ s32 resetFlag;
    /* 0xC4 */ s32 unkC4;
    /* 0xC8 */ f32 unkC8;
} M04Emitter;

#endif
