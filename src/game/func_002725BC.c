#include "b16_types.h"

f32 func_802BC380(f32 x);

s32 func_002725BC(Vec3f *v, f32 maxLen) {
    f32 sq;
    f32 len;
    f32 s;
    sq = v->x * v->x + v->y * v->y + v->z * v->z;
    if (maxLen * maxLen < sq) {
        len = func_802BC380(sq);
        if (len != 0.0f) {
            s = maxLen / len;
            v->x *= s;
            v->y *= s;
            v->z *= s;
            return 1;
        }
    }
    return 0;
}
