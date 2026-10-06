#include "b11_types.h"

extern u8 D_8011FE88[];
s32 func_0028B2D4(void *a, s32 b);

s32 func_0024E7CC(Obj *a) {
    s32 r = 0;
    s32 k = (s32)a->unk14;
    if (k != 0) {
        r = func_0028B2D4(D_8011FE88, k);
    }
    return r;
}
