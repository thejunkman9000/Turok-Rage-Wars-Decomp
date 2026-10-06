#include "b16_types.h"

void func_00274090(f32 *p);

f32 func_00273F54(f32 t, f32 a, f32 b) {
    f32 alt, d, r;
    func_00274090(&a);
    func_00274090(&b);
    if (a > b) {
        alt = b + 6.28318531f;
        d = alt - a;
        if (d < a - b) b = alt;
    } else {
        alt = b - 6.28318531f;
        d = a - alt;
        if (d < b - a) b = alt;
    }
    r = a + t * (b - a);
    func_00274090(&r);
    return r;
}
