#include "b11_types.h"

extern const f32 D_800C8C6C;
f32 *func_0028FD94(s32 node, s32 key);
void func_00270B1C(f32 *out, f32 t, f32 *a, f32 *b);

void func_0024CB3C(B11Trk *s, s32 idx, f32 *out) {
    s32 key = s->keys[idx].b;
    f32 *n;
    B11Val *r;
    if (key == -1) {
        r = &s->vals[idx];
        out[0] = r->q[0] * D_800C8C6C;
        out[1] = r->q[1] * D_800C8C6C;
        out[2] = r->q[2] * D_800C8C6C;
        out[3] = r->q[3] * D_800C8C6C;
    } else {
        n = func_0028FD94(s->nodeC, key);
        func_00270B1C(out, s->t, n + s->unk10, n + s->unk14);
    }
}