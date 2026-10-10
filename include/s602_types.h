#ifndef S602_TYPES_H
#define S602_TYPES_H
#include "common.h"

typedef struct S6BB { f32 f[6]; } S6BB;

/* screen/viewport node (embedded at +0x40 in S6World, chained through next) */
typedef struct S6Nd S6Nd;
struct S6Nd {
    /* 0x000 */ u8 pad0[4];
    /* 0x004 */ S6Nd *next;
    /* 0x008 */ u8 pad8[0x10];
    /* 0x018 */ u8 sub18[0x14];
    /* 0x02C */ u8 sub2C[0x14];
    /* 0x040 */ u8 sub40[0x14];
    /* 0x054 */ u8 pad54[0x10];
    /* 0x064 */ u32 flags;
    /* 0x068 */ u8 pad68[0x29C - 0x68];
    /* 0x29C */ f32 r0;
    /* 0x2A0 */ f32 r1;
    /* 0x2A4 */ f32 r2;
    /* 0x2A8 */ f32 r3;
    /* 0x2AC */ u8 pad2AC[0x350 - 0x2AC];
    /* 0x350 */ S6BB bbA;
    /* 0x368 */ S6BB bbB;
};

typedef struct S6World {
    /* 0x000 */ u8 pad0[0x20];
    /* 0x020 */ S6Nd *first;
    /* 0x024 */ u8 pad24[0xC];
    /* 0x030 */ u32 mode;
    /* 0x034 */ u32 oldMode;
    /* 0x038 */ s32 cnt;
    /* 0x03C */ u8 pad3C[4];
    /* 0x040 */ S6Nd nd;
    /* 0x3C0 */ u8 pad3C0[0x11D8 - 0x3C0];
    /* 0x11D8 */ u8 listA[0x14];
    /* 0x11EC */ u8 listB[0x14];
} S6World;

#endif
