#include "b08_types.h"

s32 func_00245788();
SurfNode *func_002866F8(void *tbl, f32 *pos);
f32 func_00275E44(SurfNode *n, f32 a, f32 b);

extern u8 D_8011FE88[];
extern f32 D_800C8610;
extern f32 D_800C8614;
extern f32 D_800C8618;
extern s32 D_800D2B40;

void func_00238F14(Tracker *t, s32 a, s32 b, s32 c, f32 d, f32 e, f32 f, f32 g, f32 h, f32 i,
                   Quad4 q, SurfNode *n, f32 j, f32 k) {
    SurfNode *node;
    f32 x, y, z, w;
    f32 dist;

    t->unk24 = a;
    t->unk28 = b;
    t->unk2C = c;
    t->unk30 = d;
    t->unk34 = e;
    t->unk38 = f;
    t->unk3C = g;
    t->unk40 = h;
    t->unk44 = i;
    t->unk48 = q;
    t->unk58 = n;
    t->unk5C = j;
    t->unk60 = k;
    if (func_00245788() != 0) {
        t->unk58 = func_002866F8(D_8011FE88, &t->unk38);
    }
    node = t->unk58;
    x = t->unk38;
    y = t->unk3C;
    z = t->unk40;
    w = t->unk44;
    t->unk64 = D_800D2B40;
    if (node != NULL && func_00245788() == 0) {
        dist = ((y + w) - func_00275E44(node, x, z)) * D_800C8610;
        if (dist < D_800C8614 && D_800C8618 < dist) {
            t->unk64 = node->unk1C;
        }
    }
    if (func_00245788() != 0) {
        t->unk64 = D_800D2B40;
    }
    if (t->unk5C > 0.0f) {
        t->unk64 = D_800D2B40;
    }
}
