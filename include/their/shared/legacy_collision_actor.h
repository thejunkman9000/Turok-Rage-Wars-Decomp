#ifndef LEGACY_COLLISION_ACTOR_H
#define LEGACY_COLLISION_ACTOR_H
#include "types.h"
typedef struct Shared_Func80243A80Actor Shared_Func80243A80Actor;
struct Shared_Func80243A80Actor {
    u8 type; /* +0x0: src/func_80243A80.c */
    u8 pad1[7]; /* +0x1: src/func_80243A80.c */
    f32 x; /* +0x8: src/func_80243A80.c */
    f32 y; /* +0xC: src/func_80243A80.c */
    f32 z; /* +0x10: src/func_80243A80.c */
    u16 * collision; /* +0x14: src/func_80243A80.c */
    u8 pad18[4]; /* +0x18: src/func_80243A80.c */
    s32 room; /* +0x1C: src/func_80243A80.c */
    f32 velY; /* +0x20: src/func_80243A80.c */
    s32 room2; /* +0x24: src/func_80243A80.c */
    u8 pad28[12]; /* +0x28: src/func_80243A80.c */
    void * attached; /* +0x34: src/func_80243A80.c */
    u32 flags; /* +0x38: src/func_80243A80.c */
    u8 pad3C[4]; /* +0x3C: src/func_80243A80.c */
    f32 groundY; /* +0x40: src/func_80243A80.c */
    f32 contactX; /* +0x44: src/func_80243A80.c */
    f32 contactBits; /* +0x48: src/func_80243A80.c */
    f32 contactZ; /* +0x4C: src/func_80243A80.c */
    u8 pad50[28]; /* +0x50: src/func_80243A80.c */
    f32 angle; /* +0x6C: src/func_80243A80.c */
    u8 pad70[144]; /* +0x70: src/func_80243A80.c */
    u32 status; /* +0x100: src/func_80243A80.c */
};



typedef struct Shared_Func80243A80Global Shared_Func80243A80Global;
struct Shared_Func80243A80Global {
    u8 pad[216]; /* +0x0: src/func_80243A80.c */
    s32 x; /* +0xD8: src/func_80243A80.c */
    f32 y; /* +0xDC: src/func_80243A80.c */
    s32 z; /* +0xE0: src/func_80243A80.c */
};



typedef struct Shared_Func80243A80State Shared_Func80243A80State;
struct Shared_Func80243A80State {
    u32 flags; /* +0x0: src/func_80243A80.c */
    s32 w1; /* +0x4: src/func_80243A80.c */
    s32 w2; /* +0x8: src/func_80243A80.c */
    s32 w3; /* +0xC: src/func_80243A80.c */
    s32 w4; /* +0x10: src/func_80243A80.c */
    s32 w5; /* +0x14: src/func_80243A80.c */
    s32 w6; /* +0x18: src/func_80243A80.c */
};



typedef struct Shared_Func80243A80Collision Shared_Func80243A80Collision;
struct Shared_Func80243A80Collision {
    u16 id; /* +0x0: src/func_80243A80.c */
    u16 flags; /* +0x2: src/func_80243A80.c */
};



typedef struct Shared_Func80243A80Frame Shared_Func80243A80Frame;
struct Shared_Func80243A80Frame {
    void * sp18; /* +0x0: src/func_80243A80.c */
    s32 sp1C; /* +0x4: src/func_80243A80.c */
    u8 pad_20[8]; /* +0x8: src/func_80243A80.c */
    f32 sp28; /* +0x10: src/func_80243A80.c */
    u8 pad_2C[8]; /* +0x14: src/func_80243A80.c */
    f32 sp34; /* +0x1C: src/func_80243A80.c */
    s32 sp38; /* +0x20: src/func_80243A80.c */
    s32 sp3C; /* +0x24: src/func_80243A80.c */
    s32 sp40; /* +0x28: src/func_80243A80.c */
    s32 sp44; /* +0x2C: src/func_80243A80.c */
    s32 sp48; /* +0x30: src/func_80243A80.c */
    s32 sp4C; /* +0x34: src/func_80243A80.c */
    s32 sp50; /* +0x38: src/func_80243A80.c */
    u32 sp54; /* +0x3C: src/func_80243A80.c */
    u32 * sp58; /* +0x40: src/func_80243A80.c */
    f32 sp5C; /* +0x44: src/func_80243A80.c */
    f32 sp60; /* +0x48: src/func_80243A80.c */
    f32 sp64; /* +0x4C: src/func_80243A80.c */
    f32 sp68; /* +0x50: src/func_80243A80.c */
    f32 sp6C; /* +0x54: src/func_80243A80.c */
    f32 sp70; /* +0x58: src/func_80243A80.c */
    u8 pad_74[24]; /* +0x5C: src/func_80243A80.c */
    s32 sp8C; /* +0x74: src/func_80243A80.c */
    f32 sp90; /* +0x78: src/func_80243A80.c */
    s32 sp94; /* +0x7C: src/func_80243A80.c */
    u8 pad_98[44]; /* +0x80: src/func_80243A80.c */
    u16 * spC4; /* +0xAC: src/func_80243A80.c */
    s32 spC8; /* +0xB0: src/func_80243A80.c */
    u8 pad_CC[4]; /* +0xB4: src/func_80243A80.c */
    s32 spD0; /* +0xB8: src/func_80243A80.c */
    u8 pad_D4[60]; /* +0xBC: src/func_80243A80.c */
    f32 sp110; /* +0xF8: src/func_80243A80.c */
    s32 sp114; /* +0xFC: src/func_80243A80.c */
    f32 sp118; /* +0x100: src/func_80243A80.c */
    struct Shared_Func80243A80Actor * sp11C; /* +0x104: src/func_80243A80.c */
    u8 pad_120[120]; /* +0x108: src/func_80243A80.c */
    f32 sp198; /* +0x180: src/func_80243A80.c */
    f32 sp19C; /* +0x184: src/func_80243A80.c */
    f32 sp1A0; /* +0x188: src/func_80243A80.c */
    u8 pad_1A4[12]; /* +0x18C: src/func_80243A80.c */
    f32 sp1B0; /* +0x198: src/func_80243A80.c */
    f32 sp1B4; /* +0x19C: src/func_80243A80.c */
    f32 sp1B8; /* +0x1A0: src/func_80243A80.c */
    s32 sp1BC; /* +0x1A4: src/func_80243A80.c */
    f32 sp1C0; /* +0x1A8: src/func_80243A80.c */
    f32 sp1C4; /* +0x1AC: src/func_80243A80.c */
    s32 sp1C8; /* +0x1B0: src/func_80243A80.c */
    u8 pad_1CC[20]; /* +0x1B4: src/func_80243A80.c */
    f32 sp1E0; /* +0x1C8: src/func_80243A80.c */
    f32 sp1E4; /* +0x1CC: src/func_80243A80.c */
    f32 sp1E8; /* +0x1D0: src/func_80243A80.c */
    u8 pad_1EC[36]; /* +0x1D4: src/func_80243A80.c */
    f32 sp210; /* +0x1F8: src/func_80243A80.c */
    s32 sp214; /* +0x1FC: src/func_80243A80.c */
    f32 sp218; /* +0x200: src/func_80243A80.c */
    u8 pad_21C[140]; /* +0x204: src/func_80243A80.c */
    u32 sp2A8; /* +0x290: src/func_80243A80.c */
    s32 sp2AC; /* +0x294: src/func_80243A80.c */
    s32 sp2B0; /* +0x298: src/func_80243A80.c */
    s32 sp2B4; /* +0x29C: src/func_80243A80.c */
    s32 sp2B8; /* +0x2A0: src/func_80243A80.c */
    s32 sp2BC; /* +0x2A4: src/func_80243A80.c */
    s32 sp2C0; /* +0x2A8: src/func_80243A80.c */
    u8 pad_2C4[4]; /* +0x2AC: src/func_80243A80.c */
    f32 sp2C8; /* +0x2B0: src/func_80243A80.c */
};



typedef struct Shared_Func80243A80Bits Shared_Func80243A80Bits;
struct Shared_Func80243A80Bits {
    union {
        struct {
            f32 f; /* +0x0: src/func_80243A80.c */
        } view0_0;
        struct {
            s32 i; /* +0x0: src/func_80243A80.c */
        } view0_1;
    } views0;
};

typedef Shared_Func80243A80Actor Func80243A80Actor;
typedef Shared_Func80243A80Global Func80243A80Global;
typedef Shared_Func80243A80State Func80243A80State;
typedef Shared_Func80243A80Collision Func80243A80Collision;

#endif
