#ifndef B21_TYPES_H
#define B21_TYPES_H

#include "common.h"
#include "p1_types.h"

/* Types recovered in batch 21 (game code ROM 0x92004-0x99xxx).
   Names are provisional; padding arrays keep the offsets seen in the asm. */

/* OSTask-like record filled by func_0029193C (0x68 bytes, two per slot at +0x20 / +0x88) */
typedef struct B21Task {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ s32 unk30;
    /* 0x34 */ s32 unk34;
    /* 0x38 */ s32 unk38;
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ s32 unk40;
    /* 0x44 */ s32 unk44;
    /* 0x48 */ s32 unk48;
    /* 0x4C */ s32 unk4C;
    /* 0x50 */ s32 unk50;
    /* 0x54 */ s32 unk54;
    /* 0x58 */ u8 pad58[0x68 - 0x58];
} B21Task;

/* 0x140 byte slot at the start of the game object (frame buffers / render contexts?) */
typedef struct B21Slot {
    /* 0x000 */ u8 pad0[0x20];
    /* 0x020 */ B21Task task[2];
    /* 0x0F0 */ u8 unkF0[0x20];
    /* 0x110 */ s32 unk110;
    /* 0x114 */ s32 unk114;
    /* 0x118 */ s32 unk118;
    /* 0x11C */ s32 unk11C;
    /* 0x120 */ s32 unk120;
    /* 0x124 */ u8 pad124[4];
    /* 0x128 */ s32 unk128;
    /* 0x12C */ u8 pad12C[0x140 - 0x12C];
} B21Slot;

/* Game object (D_8011FAC0, size >= 0x26DC8); only fields seen in the asm are named. */
typedef struct B21Game {
    /* 0x00000 */ B21Slot slots[3];
    /* 0x003C0 */ B21Slot *curSlot;
    /* 0x003C4 */ s32 unk3C4;
    /* 0x003C8 */ u8 sub3C8[0x1BCF8 - 0x3C8];
    /* 0x1BCF8 */ u8 sub1BCF8[0x25580 - 0x1BCF8];
    /* 0x25580 */ u8 sub25580[0x255C8 - 0x25580];
    /* 0x255C8 */ u8 sub255C8[0x26826 - 0x255C8];
    /* 0x26826 */ u8 unk26826;
    /* 0x26827 */ u8 pad26827[0x26DB0 - 0x26827];
    /* 0x26DB0 */ f32 unk26DB0;
    /* 0x26DB4 */ s32 unk26DB4;
    /* 0x26DB8 */ s32 unk26DB8;
    /* 0x26DBC */ s32 unk26DBC;
    /* 0x26DC0 */ u8 unk26DC0;
    /* 0x26DC1 */ u8 unk26DC1;
    /* 0x26DC2 */ u8 pad26DC2[2];
    /* 0x26DC4 */ f32 unk26DC4;
    /* 0x26DC8 */ s32 unk26DC8;
    /* 0x26DCC */ u8 pad26DCC[0x26DD0 - 0x26DCC];
    /* 0x26DD0 */ s32 unk26DD0;
    /* 0x26DD4 */ s32 unk26DD4;
    /* 0x26DD8 */ s32 unk26DD8;
    /* 0x26DDC */ s32 unk26DDC;
} B21Game;

#include "b21_blk.h"

/* plane / 4-component vector (x,y,z,w) */
typedef struct B21Plane {
    f32 x, y, z, w;
} B21Plane;

#endif
