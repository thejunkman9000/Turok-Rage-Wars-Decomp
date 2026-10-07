#include "b13_types.h"

extern f32 D_800D0D10;
extern f32 D_800C9078;

f32 func_0025C12C(Vec3f *a, Vec3f *b) {
    f32 d2 = (a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y) + (a->z - b->z) * (a->z - b->z);
    if (D_800D0D10 <= d2) {
        return 0.0f;
    }
    return D_800C9078 - d2 / D_800D0D10;
}
