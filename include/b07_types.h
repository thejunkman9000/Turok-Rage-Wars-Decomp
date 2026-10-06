#ifndef B07_TYPES_H
#define B07_TYPES_H

#include "p1_types.h"

/* typed access at a raw byte offset (game objects here are big structs with unknown layout) */
#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

/* element of the weapon table D_800D052C */
typedef struct B07Weapon {
    u8 pad0[8];
    s16 unk8;
} B07Weapon;

#endif
