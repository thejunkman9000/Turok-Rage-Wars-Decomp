#ifndef B21_BLK_H
#define B21_BLK_H

#include "common.h"

/* global game-mode block (D_801468A0 = D_80145040 + 0x1860), batch 21 view; GameFlags in p1_types.h is the same block */
typedef struct B21GameBlk {
    /* 0x00 */ f32 unk0;
    /* 0x04 */ f32 unk4;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ u8 pad10[0x10];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ u8 pad24[0x40];
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0x20];
    /* 0x88 */ s32 unk88;
    /* 0x8C */ u8 pad8C[0x20];
    /* 0xAC */ s32 unkAC;
} B21GameBlk;

/* sub-object at D_80145040 + 0x48 (D_80145088) */
typedef struct B21Sub48 {
    /* 0x000 */ u8 pad0[0x160];
    /* 0x160 */ s32 unk160;
} B21Sub48;

/* sub-object at D_80145040 + 0x1288 (D_801462C8) */
typedef struct B21Sub1288 {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ u8 pad4[0x19];
    /* 0x1D */ u8 unk1D;
    /* 0x1E */ u8 unk1E;
    /* 0x1F */ u8 pad1F[0x93];
    /* 0xB2 */ u8 unkB2;
} B21Sub1288;

#endif
