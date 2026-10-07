#include "b11_types.h"

f32 *func_0028FD94(s32 node, s32 key);

void func_0024C91C(B11Trk *s, s32 idx, Vec3f *out) {
    s32 key = s->keys[idx].a;
    f32 *n;
    f32 *a;
    f32 *b;
    f32 t;
    if (key == -1) {
        *out = s->vals[idx].v;
    } else {
        n = func_0028FD94(s->node8, key);
        a = n + s->unk18;
        b = n + s->unk1C;
        t = s->t;
        out->x = a[0] + t * (b[0] - a[0]);
        out->y = a[1] + t * (b[1] - a[1]);
        out->z = a[2] + t * (b[2] - a[2]);
    }
}
