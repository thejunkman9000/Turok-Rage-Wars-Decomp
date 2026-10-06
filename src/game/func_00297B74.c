#include "b21_types.h"

s32 func_00297B74(B21Plane *pl, f32 *box) {
    s32 i;
    f32 bb, b, x, y, z, d, nx, ny, nz;
    B21Plane *q;
    f32 bx3 = box[3];
    f32 bx0 = box[0];
    s32 ok;
    for (i = 0; i < 6; i++) {
        q = &pl[i];
        nx = q->x;
        x = bx0 * nx;
        bb = bx3 * nx;
        if (!(x <= bb)) x = bb;
        d = x;
        ny = q->y;
        y = box[1] * ny;
        b = box[4] * ny;
        if (!(y <= b)) y = b;
        d += y;
        nz = q->z;
        z = box[2] * nz;
        b = box[5] * nz;
        if (!(z <= b)) z = b;
        d += z;
        ok = d <= q->w;
        if (!ok) {
            return 0;
        }
    }
    return 1;
}
