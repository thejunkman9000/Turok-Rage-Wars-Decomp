#include "b11_types.h"

extern u8 D_8011FE88[];
s32 func_0028B238(void *a, s32 b);

s32 func_0024E914(Obj *a) {
    if (a->type == 1) {
        return a->unkE4;
    }
    return func_0028B238(D_8011FE88, a->unk4);
}
