#include "b08_types.h"

f32 func_00274810(f32 a, f32 b);

extern f32 D_800C8170;
extern f32 D_800C8174;
extern f32 D_800C8178;
extern f32 D_800C817C;
extern f32 D_800D2988;

s32 func_002337C0(Chan *c) {
    f32 k;
    f32 t;
    f32 g;

    if (c->v.x > c->v.y) {
        c->v.y = c->v.x;
    }
    if (c->v.z == 0.0f) {
        c->d = D_800C8170;
    }
    t = c->v.y + c->v.y;
    if (c->v.z < t) {
        c->v.z = t;
    }
    g = D_800D2988;
    k = D_800C8174;
    c->v.x = func_00274810(c->v.x, g * k);
    c->v.y = func_00274810(c->v.y, D_800D2988 * k);
    switch (c->mode) {
    case 1:
        if (c->v.z > 0.0f) {
            c->d = c->d + 2.0f * c->v.z * (D_800D2988 * k);
            c->v.z = func_00274810(c->v.z, D_800C8178);
        }
        break;
    case 0:
        if (c->v.z > 0.0f) {
            c->v.z = func_00274810(c->v.z, D_800C817C);
        }
        break;
    }
    return c->v.z == 0.0f;
}

