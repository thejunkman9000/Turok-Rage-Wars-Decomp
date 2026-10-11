#ifndef S1001_TYPES_H
#define S1001_TYPES_H

#include "common.h"
#include "b02_types.h"

/* s1001: types for func_0020DDE0, the AI aim / launch-angle controller.
   S1Ctl is the b02 AI controller (B2Ctl) seen from this function: same layout, but the fields 0x268..0x284 that B2Ctl keeps as
   padding (pad268[0x10] / pad27C[0x10]) are spelled out.  Offsets are the ones seen in the asm; names are provisional. */

/* packed float / pair of halfwords, passed by value in one register (func_00285600) */
typedef struct S1Pair {
    /* 0x0 */ u16 a;
    /* 0x2 */ u16 b;
} S1Pair;

/* element of the shot table (0x3C bytes), points at the speed / gravity parameters */
typedef struct S1Rec {
    /* 0x00 */ S1Pair grav;
    /* 0x04 */ S1Pair speed;
} S1Rec;

typedef struct S1Elem {
    /* 0x00 */ u8 pad0[0x30];
    /* 0x30 */ S1Rec *rec;
    /* 0x34 */ u8 pad34[0x8];
} S1Elem;

typedef struct S1Ctl {
    /* 0x000 */ B2Actor *owner;
    /* 0x004 */ u8 pad4[0x244];
    /* 0x248 */ f32 unk248;      /* elevation angle (degrees) to the target */
    /* 0x24C */ f32 unk24C;
    /* 0x250 */ f32 unk250;
    /* 0x254 */ f32 unk254;
    /* 0x258 */ Vec3f v258;      /* target position */
    /* 0x264 */ f32 unk264;      /* distance to the target */
    /* 0x268 */ s32 unk268;      /* search state: 0 = init, 1..10, 11..20, >= 21 = give up */
    /* 0x26C */ s32 unk26C;      /* last seen owner mode (owner->unk62E) */
    /* 0x270 */ s32 unk270;
    /* 0x274 */ s32 unk274;
    /* 0x278 */ f32 unk278;      /* current launch pitch (degrees) */
    /* 0x27C */ f32 unk27C;      /* upper bound of the search interval */
    /* 0x280 */ f32 unk280;      /* lower bound of the search interval */
    /* 0x284 */ s32 unk284;      /* 45 degree sector 0..3 of the pitch */
} S1Ctl;

#endif
