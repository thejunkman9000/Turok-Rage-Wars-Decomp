#ifndef R01_TYPES_H
#define R01_TYPES_H
#include "common.h"
#include "p1_types.h"

/* round 3 worker r01: types for main-image leftovers */

/* memory map entry table at D_800F6D00: 12-byte records {lo, hi, flags} (low-region I/O copy code) */
typedef struct R1Map {
    /* 0x0 */ u32 lo;
    /* 0x4 */ u32 hi;
    /* 0x8 */ s32 flags;
} R1Map;

/* hit/contact record pointed to by D_80103FCC: impact position at +0xE4 (used by func_002106E0) */
typedef struct R1Hit {
    /* 0x000 */ u8 pad0[0xE4];
    /* 0x0E4 */ Vec3f pos;
} R1Hit;

#endif
