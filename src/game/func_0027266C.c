#include "b16_types.h"
f32 func_802BC380(f32 x);
f32 func_00274640(f32 x);
f32 func_0027266C(Vec3f *v) {
    f32 x = v->x;
    f32 y = v->y;
    f32 z = v->z;
    f32 sq, len, t;
    if (y == 0.0f) return 0.0f;
    sq = x * x + y * y + z * z;
    if (sq == 0.0f) return 0.0f;
    len = func_802BC380(sq);
    t = y / len;
    if (t < -1.0f || 1.0f < t) return 0.0f;
    return func_00274640(t) - 1.5707964f;
}
