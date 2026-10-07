#include "b17_types.h"

extern f32 D_800C9AE0;
extern Tri3 *D_800D2638;
extern Vec3f D_80115E10;
void func_00271FD8(Vec3f *d, Vec3f *a, Vec3f *b);
void func_00272088(Vec3f *d, Vec3f *a, Vec3f *b);

Vec3f *func_00275C38(Vec3f *out, Tri3 *t) {
    Vec3f e0, e1;

    if (t == 0) {
        D_80115E10.x = 0;
        D_80115E10.z = 0;
        D_80115E10.y = D_800C9AE0;
    } else if (t != D_800D2638) {
        func_00271FD8(&e0, t->v[1], t->v[0]);
        func_00271FD8(&e1, t->v[2], t->v[1]);
        func_00272088(&D_80115E10, &e0, &e1);
    }
    *out = D_80115E10;
    D_800D2638 = t;
    return out;
}
