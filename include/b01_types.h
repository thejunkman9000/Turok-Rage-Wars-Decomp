#ifndef B01_TYPES_H
#define B01_TYPES_H

#include "common.h"
#include "p1_types.h"

/* Types recovered in batch 01 (game code, ROM 0x1000-0x875C).  Offsets as seen in the asm. */

/* class constants block pointed to by Actor.def (+0x18); same object as p1's ActorDef but with the
   fields batch 01 needed (p1's ActorInfo.unk14 is an f32 view of the same bytes as unk28 here). */
typedef struct B01Def {
    /* 0x00 */ u8 pad0[0x14];
    /* 0x14 */ u32 flags14;
    /* 0x18 */ u8 pad18[4];
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ u8 pad20[4];
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s16 unk28;
    /* 0x2A */ u8 pad2A[0xE];
    /* 0x38 */ u32 flags38;
    /* 0x3C */ u8 pad3C[4];
    /* 0x40 */ s32 unk40;
} B01Def;

/* state/handler block seen with a Vec3f at +0x130 (same block as p1's ActorState) */
typedef struct B01StateV {
    /* 0x000 */ u8 pad0[0x130];
    /* 0x130 */ Vec3f vec130;
} B01StateV;

/* state block fields used by the timer/impulse helpers (ActorState.unk40 is an f32 too) */
typedef struct B01StateT {
    /* 0x00 */ u8 pad0[0x40];
    /* 0x40 */ f32 unk40;
    /* 0x44 */ u8 pad44[0x20];
    /* 0x64 */ f32 unk64;
} B01StateT;

#define B01_DEF(a) ((B01Def *)(a)->def)

#endif
