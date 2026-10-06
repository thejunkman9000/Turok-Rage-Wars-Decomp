#include "b16_types.h"

f32 func_802BC380(f32 x);

void func_002727B8(Vec3f *v, f32 maxLen) {
    f32 sq;
    f32 s;
    sq = v->x * v->x + v->y * v->y + v->z * v->z;
    if (maxLen * maxLen < sq) {
        s = maxLen / func_802BC380(sq);
        v->x *= s;
        v->y *= s;
        v->z *= s;
    }
}
