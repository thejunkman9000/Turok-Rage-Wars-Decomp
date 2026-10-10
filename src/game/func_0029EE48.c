#include "span_1000/code_8029EB74.h"
#include "types.h"

/* Returns the arcsine of a value clamped to [-1, 1] using the polynomial approximation pi/2 - sqrt(1 - x) * p(x) on its magnitude and restoring the sign afterwards. */






extern f32 func_802B72B0_de(f32 value);

f32 func_8029DE48_de(f32 x) {
    s32 negative;
    f32 poly;
    f32 root;
    f32 result;

    if (D_800C5C00_de < x) {
        x = D_800C5C00_de;
    }
    do {
        if (x < *(&D_800C5C00_de + 1)) {
            x = *(&D_800C5C00_de + 1);
        }
        negative = 0;
        if (x < 0.0f) {
            negative = 1;
            x = -x;
        }
        poly = (((((x * D_800C5C08_de + *(&D_800C5C08_de + 1)) * x - D_800C5C10_de) * x + *(&D_800C5C10_de + 1)) * x
                 - D_800C5C18_de) * x) + *(&D_800C5C18_de + 1);
        x = D_800C5C00_de - x;
        if (x <= 0.0f) {
            root = 0.0f;
        } else {
            root = func_802B72B0_de(x);
        }
    } while (0);
    result = D_800C5C20_de - root * poly;
    if (negative) {
        result = -result;
    }
    return result;
}
