#include "b11_types.h"

extern u8 D_8011FE88[];
B11Node *func_0028B2D4(void *a, B11Box *b);

f32 func_0024E7FC(Obj *a) {
    B11Box *b = a->unk14;
    if (b != 0 && (b->flags2 & 1)) {
        f32 *n = (f32 *)func_0028B2D4(D_8011FE88, b);
        if (n != 0) {
            return n[8];
        }
    }
    return 0.0f;
}
