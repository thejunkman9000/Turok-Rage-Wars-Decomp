#include "b16_types.h"
#define WRAP(x) \
    while ((x) < -3.14159265f) { (x) += 6.28318531f; } \
    while ((x) > 3.14159265f) { (x) -= 6.28318531f; }

f32 func_00271CC4(f32 a, f32 b) {
    f32 d;
    f32 t = b;
    WRAP(t)
    d = a - t;
    WRAP(d)
    if (-d < 0.0f) {
        WRAP(b)
        d = a - b;
        WRAP(d)
        return d;
    } else {
        WRAP(b)
        d = a - b;
        WRAP(d)
        return -d;
    }
}
