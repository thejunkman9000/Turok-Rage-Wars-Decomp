#include "b21_types.h"

/* box: min.xyz at [0..2], max.xyz at [3..5] */
s32 func_00297C30(B21Plane *pl, f32 *box) {
    f32 b, x, y, z, d, nx, ny, nz;
    nx = pl->x;
    x = box[0] * nx;
    b = box[3] * nx;
    if (!(x <= b)) x = b;
    d = x;
    ny = pl->y;
    y = box[1] * ny;
    b = box[4] * ny;
    if (!(y <= b)) y = b;
    d += y;
    nz = pl->z;
    z = box[2] * nz;
    b = box[5] * nz;
    if (!(z <= b)) z = b;
    d += z;
    return d <= pl->w;
}
