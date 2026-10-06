#include "b23_types.h"
extern f32 D_800CAE50;
void func_0029CBB0(f32 a, f32 *s, f32 *c);
void func_002A1748(void *p, s32 v, s32 n);
void func_0029DE3C(Mtx4f *a, Mtx4f *b, Mtx4f *dst);

void func_0029FDD8(Mtx4f *m, f32 angle) {
    Mtx4f tmp;
    Mtx4f *r;
    f32 s, c;
    if (angle != 0.0f) {
        func_0029CBB0(angle, &s, &c);
        r = &tmp;
        func_002A1748(r, 0, 0x40);
        tmp.m[0][0] = D_800CAE50;
        r->m[1][1] = D_800CAE50;
        r->m[2][2] = D_800CAE50;
        r->m[3][3] = D_800CAE50;
        tmp.m[1][1] = c;
        tmp.m[2][1] = -s;
        tmp.m[1][2] = s;
        tmp.m[2][2] = c;
        func_0029DE3C(m, r, m);
    }

}
