#ifndef S1007_TYPES_H
#define S1007_TYPES_H

#include "common.h"
#include "p1_types.h"

/* s1007: types for the tail of overlay A (VRAM 0x44E038..0x44EDA0): level / match setup helpers.
   Offsets are the ones seen in the asm; names are provisional. */

/* light / direction record: a Vec3f at +0x14 and an enable word at +0x20 (func_0044E8B0) */
typedef struct S7Light {
    /* 0x00 */ u8 pad0[0x14];
    /* 0x14 */ Vec3f dir;
    /* 0x20 */ s32 enabled;
} S7Light;

/* script / animation context pair (func_0044ED24): two 0x48-byte contexts, the word at +0x40 of each is cleared */
typedef struct S7Anim {
    /* 0x00 */ u8 pad0[0x40];
    /* 0x40 */ s32 unk40;
    /* 0x44 */ u8 pad44[4];
} S7Anim;

typedef struct S7AnimPair {
    /* 0x00 */ S7Anim a;
    /* 0x48 */ S7Anim b;
} S7AnimPair;

/* the match / level block (func_0044EACC): the fields used here sit above 0x26000 */
typedef struct S7Match {
    /* 0x00000 */ u8 pad0[0x26825];
    /* 0x26825 */ u8 unk26825;
    /* 0x26826 */ u8 pad26826[0x26DBC - 0x26826];
    /* 0x26DBC */ s32 state;
    /* 0x26DC0 */ u8 pad26DC0;
    /* 0x26DC1 */ u8 unk26DC1;
    /* 0x26DC2 */ u8 pad26DC2[0x26DD8 - 0x26DC2];
    /* 0x26DD8 */ s32 unk26DD8;
    /* 0x26DDC */ s32 unk26DDC;
} S7Match;

/* the game block D_801468A0 (func_0044EACC) */
typedef struct S7Blk {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ u8 pad10[0x88 - 0x10];
    /* 0x88 */ s32 unk88;
    /* 0x8C */ u8 pad8C[0xAC - 0x8C];
    /* 0xAC */ s32 unkAC;
} S7Blk;

/* pool / list setup (func_0044EBB0): the level's resource block; every member below is a contiguous array/list as seen from the loops */
typedef struct S7DL { void *head; void *tail; s32 count; } S7DL;           /* 12-byte list head (func_00279520 / func_00279578) */
typedef struct S7NodePool { S7DL freel; S7DL usedl; } S7NodePool;          /* func_00279620 */
typedef struct S7Queue { void *head; void *tail; s32 prevOff; s32 nextOff; s32 count; } S7Queue;   /* intrusive list head (func_00255C40), 20 bytes */
typedef struct S7Item { u8 pad0[184]; } S7Item;
typedef struct S7Node84 { u8 pad0[84]; } S7Node84;
typedef struct S7Node28 { u8 pad0[28]; } S7Node28;
typedef struct S7Node80 { u8 pad0[80]; } S7Node80;

typedef struct S7Pools {
    /* 0x0000 */ s32 unk0;
    /* 0x0004 */ u8 pad4[0x2588 - 4];
    /* 0x2588 */ s32 unk2588;
    /* 0x258C */ u8 pad258C[4];
    /* 0x2590 */ S7Item items[96];
    /* 0x6A90 */ S7DL list;
    /* 0x6A9C */ S7Node84 nodesA[32];
    /* 0x751C */ S7NodePool poolA;
    /* 0x7534 */ S7Node28 nodesB[3];
    /* 0x7588 */ S7NodePool poolB;
    /* 0x75A0 */ S7Node80 nodesC[100];
    /* 0x94E0 */ S7Queue lists[10];
    /* 0x95A8 */ S7Queue queue;
} S7Pools;

/* func_0044ECB0: two 256-byte lookup tables at +0xC8 and +0x1C8, four words at +0x90 are cleared */
typedef struct S7Tabs {
    /* 0x00 */ u8 pad0[0x90];
    /* 0x90 */ s32 unk90;
    /* 0x94 */ s32 unk94;
    /* 0x98 */ s32 unk98;
    /* 0x9C */ s32 unk9C;
    /* 0xA0 */ u8 padA0[0xC8 - 0xA0];
    /* 0xC8 */ u8 tab0[256];
    /* 0x1C8 */ u8 tab1[256];
} S7Tabs;

/* func_0044E7C0: a pool of 32 effect slots of 0x1E0 bytes linked through prev (+0x1D8) / next (+0x1DC); the pool header follows the slots (+0x3C00) */
typedef struct S7Slot {
    /* 0x000 */ u8 pad0[0x1D8];
    /* 0x1D8 */ struct S7Slot *prev;
    /* 0x1DC */ struct S7Slot *next;
} S7Slot;

typedef struct S7Fx {
    /* 0x0000 */ S7Slot slot[32];
    /* 0x3C00 */ S7Slot *head;
    /* 0x3C04 */ S7Slot *tail;
    /* 0x3C08 */ s32 count;
} S7Fx;

/* the two small records D_8011F448 / D_8011F2C0 (same type as func_00219460's argument) */
typedef struct S7Rec {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ u8 pad8[4];
    /* 0x0C */ s16 unkC;
    /* 0x0E */ s8 unkE;
    /* 0x0F */ u8 padF[3];
    /* 0x12 */ s8 unk12;
    /* 0x13 */ u8 pad13;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
} S7Rec;

/* func_0044E038: track resource holder and the 20-byte placed objects of a track (the same layout as the other decompilation's Track/Object_func_8044D220_de) */
typedef struct S7Track {
    /* 0x00 */ u8 pad0[0x90];
    /* 0x90 */ void *resource;
} S7Track;

typedef struct S7Obj {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s16 kind;
    /* 0x12 */ s16 pad12;
} S7Obj;

#endif
