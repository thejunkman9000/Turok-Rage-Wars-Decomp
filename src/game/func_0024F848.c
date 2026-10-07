#include "b11_types.h"

extern u8 D_8011FE88[];
extern u32 D_801462C8;
s32 func_0028B238(void *a, s32 b);

s32 func_0024F848(Obj *a) {
    ObjDef *d = a->def;
    s32 r;
    s32 id;
    u32 f;
    if (d->type == 12) {
        return 0;
    }
    r = d->unkE;
    id = func_0028B238(D_8011FE88, a->unk4);
    if (id < 0x6AB) {
        if (id >= 0x6A9) {
            f = D_801462C8;
            if (f & 0x800) {
                r = 1;
            }
            if (f & 0x1000) {
                r = 2;
            }
        }
    }
    return r;
}
