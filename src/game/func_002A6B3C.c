#include "b23_types.h"
extern f32 D_800CB030;
extern f32 D_800CB034;
void func_002A6B3C(f32 *p) {
    f32 v = *p;
    f32 w;
    w = v;
    if (v < 0.0f) {
        *p = 0.0f;
    } else if (w > D_800CB034) {
        *p = D_800CB034;
    }
}
