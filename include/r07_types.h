#ifndef R07_TYPES_H
#define R07_TYPES_H
#include "common.h"
#include "b21_types.h"

/* frame slot (D_8014AD98 / D_8011FE80), same layout as B21Slot with +0x124 named */
typedef struct R07Slot {
    /* 0x000 */ u8 pad0[0xF0];
    /* 0x0F0 */ u8 unkF0[0x20];
    /* 0x110 */ s32 unk110;
    /* 0x114 */ s32 unk114;
    /* 0x118 */ s32 unk118;
    /* 0x11C */ s32 unk11C;
    /* 0x120 */ s32 unk120;
    /* 0x124 */ s32 unk124;
    /* 0x128 */ s32 unk128;
    /* 0x12C */ u8 pad12C[0x140 - 0x12C];
} R07Slot;
#endif
