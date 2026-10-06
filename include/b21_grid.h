#ifndef B21_GRID_H
#define B21_GRID_H

#include "common.h"

/* tile/path grid object: 17x17 s16 map centred on (x, y), at +0x18 */
typedef struct B21Grid {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 x;
    /* 0x0C */ s32 y;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s16 map[17 * 17];
} B21Grid;

#endif
