#ifndef B04_TYPES_H
#define B04_TYPES_H
#include "p1_types.h"

/* batch-4 (b04) recovered types; unique names prefixed B04.
   Structs between the GENERATED markers come from the offset table used while matching: padding arrays keep the
   offsets seen in the asm, field names are provisional (unkXX = offset). */

/* gcc 2.8.1 -O2 inlines sqrtf as sqrt.s + c.eq.s + (bc1t over) jal sqrtf; the ROM always calls sqrtf.
   Calling it through an asm-label alias keeps the call (alternative: compile with -fno-builtin). */
f32 b04_sqrtf(f32 x) __asm__("sqrtf");
#define sqrtf(x) b04_sqrtf(x)

typedef struct B04Pos { u8 pad0[8]; f32 x; f32 y; f32 z; } B04Pos;

/* BEGIN GENERATED */
typedef struct B04Weapon B04Weapon;
struct B04Weapon {
    /* 0x000 */ u8 pad0[0xb0];
    /* 0x0b0 */ u32 flagsB0;
};

typedef struct B04Act B04Act;
struct B04Act {
    /* 0x000 */ u8 pad0[0x18];
    /* 0x018 */ ActorDef * def;
    /* 0x01c */ u8 pad1C[0xc8];
    /* 0x0e4 */ u16 unkE4;
    /* 0x0e6 */ u8 padE6[0x1a];
    /* 0x100 */ u32 flags;
    /* 0x104 */ u8 pad104[0xd4];
    /* 0x1d8 */ B04Act * owner;
    /* 0x1dc */ u8 pad1DC[0x104];
    /* 0x2e0 */ u32 unk2E0;
    /* 0x2e4 */ u8 pad2E4[0x2f4];
    /* 0x5d8 */ ActorStats * stats;
    /* 0x5dc */ u8 pad5DC[0xbc];
    /* 0x698 */ B04Weapon * wpn;
    /* 0x69c */ u8 pad69C[0xec];
    /* 0x788 */ s32 unk788;
    /* 0x78c */ u8 pad78C[0x8];
    /* 0x794 */ B04Act * unk794;
    /* 0x798 */ u8 pad798[0xf48];
    /* 0x16e0 */ B04Act * next;
};
/* END GENERATED */
#endif
