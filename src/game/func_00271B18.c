#include "b16_types.h"
f32 func_802BC380(f32 x);
f32 func_00274640(f32 x);
#define ABS(a) ((a) < 0.0f ? -(a) : (a))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

f32 func_00271B18(Vec3f *v) {
    f32 x = v->x;
    f32 z = v->z;
    f32 len, r, res, t;
    len = x * x + z * z;
    if (len == 0.0f) {
        return 0.0f;
    }
    len = func_802BC380(len);
    if (len == 0.0f) {
        return 0.0f;
    }
    if (ABS(x) < ABS(z)) {
        x /= len;
        r = func_00274640(MAX(-1.0f, MIN(1.0f, x)));
        res = -r;
        if (z < 0.0f) {
            res = r;
        }
        res -= 1.5707964f;
    } else {
        z /= len;
        t = MAX(-1.0f, MIN(1.0f, z));
        r = func_00274640(-t);
        res = -r;
        if (x < 0.0f) {
            res = r;
        }
    }
    return res;
}
