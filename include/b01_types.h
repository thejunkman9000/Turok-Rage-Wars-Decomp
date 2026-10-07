#ifndef B01_TYPES_H
#define B01_TYPES_H

#include "common.h"
#include "p1_types.h"
#include "b01_gen.h"   /* generated: B01Def, B01Seg, B01Actor, B01State (from wip/types_spec.txt) */

/* Types recovered in batch 01 (game code, ROM 0x1000-0x875C).  Offsets as seen in the asm.
   B01Actor / B01State are supersets of p1's Actor / ActorState for the offsets this batch used. */

/* class-constants block of a p1 Actor (p1's ActorDef.info.unk14 is an f32 view of B01Def.unk28 etc.) */
#define B01_DEF(a) ((B01Def *)(a)->def)

/* constants block embedded in the def at +0x14 (what p1 calls ActorInfo) */
#define B01_INFO(def) ((B01Info *)((u8 *)(def) + 0x14))

/* second argument of the hit/event callbacks (state + 4/8 words) */
typedef struct B01Hit {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s32 unk4;
    /* 0x08 */ B01Actor *actor;
} B01Hit;

/* request block sent to the I/O thread through osSendMesg(&D_800F6F40, &req, 1); reply queue at +0x1C */
typedef struct B01IoReq {
    /* 0x00 */ s32 w0;
    /* 0x04 */ s32 w4;
    /* 0x08 */ s32 w8;
    /* 0x0C */ union { s32 i; struct { u16 hi; u16 cmd; } h; } wC;
    /* 0x10 */ s32 w10;
    /* 0x14 */ s32 w14;
    /* 0x18 */ s32 w18;
    /* 0x1C */ OSMesgQueue *reply;
} B01IoReq;

/* position of an actor-like object: Vec3f at +8 */
#define B01_POS(a) (*(Vec3f *)((u8 *)(a) + 8))

/* 8-byte struct passed by value (second word never initialised by the callers seen) */
typedef struct B01Pair {
    s32 a;
    s32 b;
} B01Pair;

/* event record passed as third argument to some handlers */
typedef struct B01Evt {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ u8 pad4[8];
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
} B01Evt;

#endif
