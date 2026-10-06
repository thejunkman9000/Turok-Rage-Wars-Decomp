#ifndef B21_WORLD_H
#define B21_WORLD_H

#include "common.h"
#include "b21_blk.h"

/* The global game state object at D_80145040 (batch 21 view).  Many separate-looking globals
   (D_80145060, D_801462C8, D_801468A0, D_8014694C, D_80146958, ...) are members of this one struct:
   the ROM derives their addresses from a single base register.  Offsets relative to D_80145040. */
typedef struct B21World {
    /* 0x0000 */ u8 pad0[0x48];
    /* 0x0048 */ B21Sub48 sub48;
    /* 0x01AC */ u8 pad1AC[0x430];
    /* 0x05DC */ u8 sub5DC[4];
    /* 0x05E0 */ u8 pad5E0[0xCA8];
    /* 0x1288 */ B21Sub1288 sub1288;
    /* 0x133C */ u8 pad133C[0x524];
    /* 0x1860 */ B21GameBlk blk;
} B21World;

extern B21World D_80145040;

#endif
