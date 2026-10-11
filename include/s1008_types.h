#ifndef S1008_TYPES_H
#define S1008_TYPES_H
#include "b14_types.h"

/* effect/entity pool of the 0x5F00 world object (see func_00262EA8): a free list at +0x5F00 and an active list at +0x5F14 */
typedef struct S1008Eff S1008Eff;
struct S1008Eff {
    /* 0x000 */ u8 pad0[0x174];
    /* 0x174 */ s32 f174;
    /* 0x178 */ u8 pad178[0x2EC - 0x178];
    /* 0x2EC */ S1008Eff *next;
    /* 0x2F0 */ s32 *counter;
};
typedef struct {
    /* 0x0000 */ u8 pad0[0x5F00];
    /* 0x5F00 */ S1008Eff *freeHead;
    /* 0x5F04 */ u8 pad5F04[0x5F14 - 0x5F04];
    /* 0x5F14 */ S1008Eff *activeHead;
    /* 0x5F18 */ u8 pad5F18[0x5F24 - 0x5F18];
    /* 0x5F24 */ u32 state;
} S1008Pool;

/* record-screen widgets and menu object (D_800E3590, 0x210 bytes, allocated by func_0041CEB0) */
typedef struct S1008Node {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ u8 style;
    /* 0x11 */ u8 pad11[3];
    /* 0x14 */ u16 x;
    /* 0x16 */ u16 y;
    /* 0x18 */ s16 w;
} S1008Node;
typedef struct S1008Menu {
    /* 0x000 */ void *owner;
    /* 0x004 */ void *handle;
    /* 0x008 */ u8 pad8[0xC8 - 8];
    /* 0x0C8 */ S1008Node *left;
    /* 0x0CC */ s32 leftStep;
    /* 0x0D0 */ S1008Node *right;
    /* 0x0D4 */ s32 rightStep;
    /* 0x0D8 */ s32 state;
    /* 0x0DC */ s32 timer;
    /* 0x0E0 */ s32 fade;
    /* 0x0E4 */ S1008Node *groupA;
    /* 0x0E8 */ S1008Node *cursor;
    /* 0x0EC */ S1008Node *focus;
    /* 0x0F0 */ S1008Node *nodeF0;
    /* 0x0F4 */ S1008Node *groupB;
    /* 0x0F8 */ s32 styleStep;
    /* 0x0FC */ s32 styleValue;
    /* 0x100 */ S1008Node *groupC;
    /* 0x104 */ s32 alphaStep;
    /* 0x108 */ s32 clock;
    /* 0x10C */ s32 f10C;
    /* 0x110 */ u8 pad110[0x210 - 0x110];
} S1008Menu;

#endif
