#ifndef B07_TYPES_H
#define B07_TYPES_H

#include "p1_types.h"

/* typed access at a raw byte offset (game objects here are big structs with unknown layout) */
#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

/* element of the weapon table D_800D052C */
typedef struct B07Weapon {
    u8 pad0[8];
    s16 unk8;
} B07Weapon;

/* global game-mode block at D_801468A0 (superset of p1 GameFlags; only used words are named) */
typedef struct B07Game {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 cnt2C[5];
    /* 0x40 */ s32 cnt40[5];
    /* 0x54 */ s32 unk54;
    /* 0x58 */ u8 pad58[0x18];
    /* 0x70 */ s32 unk70;
    /* 0x74 */ u8 pad74[4];
    /* 0x78 */ s32 unk78;
} B07Game;

/* 0x190 byte rows at D_80102B00 (indexed by Actor.unk5D4; superset of p1 ActorRow400) */
typedef struct B07Row {
    /* 0x000 */ u8 pad0[8];
    /* 0x008 */ s32 unk8;
    /* 0x00C */ u8 unkC;
    /* 0x00D */ u8 unkD;
    /* 0x00E */ u8 unkE;
    /* 0x00F */ u8 padF[0x17A];
    /* 0x189 */ u8 unk189;
    /* 0x18A */ u8 unk18A;
    /* 0x18B */ u8 unk18B;
    /* 0x18C */ u8 unk18C;
    /* 0x18D */ u8 unk18D;
    /* 0x18E */ u8 pad18E[2];
} B07Row;

/* 0x96 byte records at D_80146398 */
typedef struct B07Rec96 {
    /* 0x00 */ u8 pad0[0x79];
    /* 0x79 */ u8 unk79;
    /* 0x7A */ u8 unk7A;
    /* 0x7B */ u8 unk7B;
    /* 0x7C */ u8 pad7C;
    /* 0x7D */ u8 unk7D;
    /* 0x7E */ u8 pad7E[4];
    /* 0x82 */ u8 unk82;
    /* 0x83 */ u8 pad83[0x13];
} B07Rec96;

/* 0x50 byte block copied by value (start of an Actor) */
typedef struct B07Blk50 {
    s32 w[0x14];
} B07Blk50;

/* 16 byte vertex (F3D Vtx layout) */
typedef struct B07Vtx {
    s16 x, y, z;
    s16 flag;
    s16 s, t;
    u8 r, g, b, a;
} B07Vtx;

#endif
