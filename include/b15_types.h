#ifndef B15_TYPES_H
#define B15_TYPES_H
#include "common.h"
#include "p1_types.h"
/* batch 15 types (funcs 0x2661FC-0x26CE18).  Names provisional. */

/* 8-byte block passed by value (word aligned: copied with lw/sw) */
typedef struct B15Blk8 {
    s16 a, b;
    s32 c;
} B15Blk8;

/* two words passed by value (copied through memory) */
typedef struct B15Pair {
    s32 a, b;
} B15Pair;

/* 4 halfwords passed by value (2-byte aligned) */
typedef struct B15S16x4 {
    s16 a, b, c, d;
} B15S16x4;

/* 7 colour/byte values passed by value (copied through the stack) */
typedef struct B15Bytes7 {
    u8 c[7];
} B15Bytes7;

/* generic "source" object passed to the sound/effect calls: type byte at +0 (0,1 = actor,2) */
typedef struct B15Def {
    /* 0x00 */ s32 type;
    /* 0x04 */ u8 pad4[0xA];
    /* 0x0E */ s8 unkE;
} B15Def;

typedef struct B15Src {
    /* 0x00 */ u8 type;
    /* 0x01 */ u8 pad1[7];
    /* 0x08 */ Vec3f pos;
    /* 0x14 */ u8 pad14[4];
    /* 0x18 */ B15Def *def;
    /* 0x1C */ u8 pad1C[0xB4];
    /* 0xD0 */ void *unkD0;
    /* 0xD4 */ u8 padD4[0xA8];
    /* 0x17C */ u32 unk17C;
} B15Src;

/* global game state block at D_801462C8 (only used words) */
typedef struct B15Globals {
    /* 0x000 */ u32 flags0;
    /* 0x004 */ u8 pad4[0x5C8];
    /* 0x5CC */ s32 unk5CC;
} B15Globals;

#endif
