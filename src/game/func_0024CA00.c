#include "b11_types.h"

extern const f32 D_800C8C68;
f32 *func_0028FD94(s32 node, s32 key);

void func_0024CA00(B11Trk *s, s32 idx, f32 *out) {
    s32 key = s->keys[idx].b;
    f32 *n;
    f32 *a;
    f32 *b;
    f32 t;
    B11Val *r;
    if (key == -1) {
        r = &s->vals[idx];
        out[0] = r->q[0] * D_800C8C68;
        out[1] = r->q[1] * D_800C8C68;
        out[2] = r->q[2] * D_800C8C68;
        out[3] = r->q[3] * D_800C8C68;
    } else {
        n = func_0028FD94(s->nodeC, key);
        a = n + s->unk10;
        b = n + s->unk14;
        t = s->t;
        out[0] = a[0] + t * (b[0] - a[0]);
        out[1] = a[1] + t * (b[1] - a[1]);
        out[2] = a[2] + t * (b[2] - a[2]);
        out[3] = a[3] + t * (b[3] - a[3]);
    }
}
