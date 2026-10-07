#include "b08_types.h"

s32 func_00245788();
SurfNode *func_002866F8(void *tbl, f32 *pos);
f32 func_00275E44(SurfNode *n, f32 a, f32 b);

extern u8 D_8011FE88[];
extern f32 D_800C8680;
extern f32 D_800C8684;
extern f32 D_800C8688;
extern s32 D_800D2B40;

void func_00239FCC(Tracker *t) {
    SurfNode *n;
    f32 x, y, z, w;
    f32 d;

    if (func_00245788() != 0) {
        t->unk58 = func_002866F8(D_8011FE88, &t->unk38);
    }
    n = t->unk58;
    x = t->unk38;
    y = t->unk3C;
    z = t->unk40;
    w = t->unk44;
    t->unk64 = D_800D2B40;
    if (n != NULL && func_00245788() == 0) {
        d = ((y + w) - func_00275E44(n, x, z)) * D_800C8680;
        if (d < D_800C8684 && D_800C8688 < d) {
            t->unk64 = n->unk1C;
        }
    }
    if (func_00245788() != 0) {
        t->unk64 = D_800D2B40;
    }
    if (t->unk5C > 0.0f) {
        t->unk64 = D_800D2B40;
    }
}
