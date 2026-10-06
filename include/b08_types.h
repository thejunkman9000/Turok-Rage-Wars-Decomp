#ifndef B08_TYPES_H
#define B08_TYPES_H

#include "common.h"
#include "p1_types.h"

/* gcc 2.8.1 -O2 expands a plain sqrtf() call inline (sqrt.s + NaN check); the ROM always calls it.
   Declaring the callee under another C name (same asm symbol) keeps it an ordinary call. */
extern f32 b08_sqrtf(f32 x) __asm__("sqrtf");

/* Types recovered in batch 08 (main image 0x34028-0x3B3E0, func_00233428..func_0023A4D0). */

/* five-word channel record (func_002337C0 normalises one; objects embed 4 of them at +0x04, +0x18, +0x2C, +0x40) */
typedef struct Chan {
    /* 0x00 */ s32 mode;
    /* 0x04 */ Vec3f v;
    /* 0x10 */ f32 d;
} Chan;

typedef struct ChanObj {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ Chan ch[4];
} ChanObj;

/* PLAYER-BEGIN */
typedef struct Player Player;
struct Player {
    /* 0x0000 */ u8 pad0[0x5D8];
    /* 0x05D8 */ ActorStats *stats;
    /* 0x05DC */ u8 pad5DC[0x52];
    /* 0x062E */ s16 unk62E;
    /* 0x0630 */ u8 pad630[0x20];
    /* 0x0650 */ s16 unk650;
    /* 0x0652 */ u8 pad652[0x5A];
    /* 0x06AC */ u32 flags6AC;
    /* 0x06B0 */ u8 pad6B0[0xC0];
    /* 0x0770 */ s16 unk770;
    /* 0x0772 */ u8 pad772[0xA66];
    /* 0x11D8 */ f32 unk11D8;
};
/* PLAYER-END */

#endif
