#include "b21_types.h"

extern f32 D_800CA6A0;

f32 func_00297930(B21Plane *pl, Vec3f *a, Vec3f *b) {
    f32 d1 = pl->x * a->x + pl->y * a->y + pl->z * a->z;
    f32 d2 = pl->x * b->x + pl->y * b->y + pl->z * b->z;
    if (d2 == d1) {
        return D_800CA6A0;
    }
    return (pl->w - d1) / (d2 - d1);
}
