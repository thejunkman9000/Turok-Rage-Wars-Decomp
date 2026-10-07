#ifndef B16_TYPES_H
#define B16_TYPES_H

#include "p1_types.h"

/* Types recovered in batch 16 (vector / matrix / display-list helpers, main image 0x6DE7C-0x75144) */

/* 4x4 f32 matrix, row major (rows 0x10 apart) */
typedef struct B16Mtx {
    f32 m[4][4];
} B16Mtx;

/* 4 floats (quaternion / plane / rgba) */
typedef struct B16Vec4 {
    f32 x, y, z, w;
} B16Vec4;

/* same matrix passed as a decayed array parameter */
typedef f32 B16Mtx4[4][4];

/* libultra fixed point matrix: 16.16 integer parts in i[], fractions in f[] */
typedef struct B16MtxFx {
    u32 i[8];
    u32 f[8];
} B16MtxFx;

#endif
