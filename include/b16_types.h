#ifndef B16_TYPES_H
#define B16_TYPES_H

#include "p1_types.h"

/* Types recovered in batch 16 (vector / matrix / display-list helpers, main image 0x6DE7C-0x75144) */

/* 4x4 f32 matrix, row major (rows 0x10 apart) */
typedef struct B16Mtx {
    f32 m[4][4];
} B16Mtx;

/* same matrix passed as a decayed array parameter */
typedef f32 B16Mtx4[4][4];

#endif
