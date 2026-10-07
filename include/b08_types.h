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

typedef struct SurfNode {
    u8 pad0[0x1C];
    s32 unk1C;
} SurfNode;

typedef struct Quad4 {
    s32 w[4];
} Quad4;

/* tracked-point record (func_00238F14 initialises it, func_00239FCC updates it) */
typedef struct Tracker {
    /* 0x00 */ u8 pad0[0x24];
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ f32 unk30;
    /* 0x34 */ f32 unk34;
    /* 0x38 */ f32 unk38;
    /* 0x3C */ f32 unk3C;
    /* 0x40 */ f32 unk40;
    /* 0x44 */ f32 unk44;
    /* 0x48 */ Quad4 unk48;
    /* 0x58 */ SurfNode *unk58;
    /* 0x5C */ f32 unk5C;
    /* 0x60 */ f32 unk60;
    /* 0x64 */ s32 unk64;
} Tracker;

/* PLAYER-BEGIN */
typedef struct Player Player;
struct Player {
    /* 0x0000 */ u8 pad0[0x38];
    /* 0x0038 */ u32 flags38;
    /* 0x003C */ u8 pad3C[0x59C];
    /* 0x05D8 */ ActorStats *stats;
    /* 0x05DC */ void *pawn;
    /* 0x05E0 */ u8 pad5E0[0x4E];
    /* 0x062E */ s16 unk62E;
    /* 0x0630 */ u8 pad630[0x20];
    /* 0x0650 */ s16 unk650;
    /* 0x0652 */ u8 pad652[0x5A];
    /* 0x06AC */ u32 flags6AC;
    /* 0x06B0 */ u8 pad6B0[0xC0];
    /* 0x0770 */ s16 unk770;
    /* 0x0772 */ u8 pad772[0xA66];
    /* 0x11D8 */ f32 unk11D8;
    /* 0x11DC */ u8 pad11DC[0x504];
    /* 0x16E0 */ Player *next;
};
/* PLAYER-END */

#endif
