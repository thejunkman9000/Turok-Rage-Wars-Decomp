#include "span_1000/code_8029EB74.h"
#include "types.h"

/* Returns the arccosine of a value clamped to [-1, 1] as pi/2 minus the arcsine, which is computed by the polynomial approximation pi/2 - sqrt(1 - x) * p(x) on the magnitude with the sign restored. Adapted from func_8029DE48_de with the constants moved to D_800CADB4 through D_800CADD4 and the final subtraction from pi/2 added. */






extern f32 func_802B72B0_de(f32 value);

f32 func_8029DF48_de(f32 x) {
    s32 negative;
    f32 poly;
    f32 root;
    f32 result;

    if (*(&D_800C5C20_de + 1) < x) {
        x = *(&D_800C5C20_de + 1);
    }
    do {
        if (x < D_800C5C28_de) {
            x = D_800C5C28_de;
        }
        negative = 0;
        if (x < 0.0f) {
            negative = 1;
            x = -x;
        }
        poly = (((((x * (-0.011680527590215206f) + D_800C5C30_de) * x - *(&D_800C5C30_de + 1)) * x + D_800C5C38_de) * x
                 - *(&D_800C5C38_de + 1)) * x) + D_800C5C40_de;
        x = *(&D_800C5C20_de + 1) - x;
        if (x <= 0.0f) {
            root = 0.0f;
        } else {
            root = func_802B72B0_de(x);
        }
    } while (0);
    result = *(&D_800C5C40_de + 1) - root * poly;
    if (negative) {
        result = -result;
    }
    return *(&D_800C5C40_de + 1) - result;
}
