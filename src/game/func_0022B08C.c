#include "b06_types.h"

void func_00226DAC(Plr *a, f32 *out);
void func_00272908(f32 *a, Vec3f *b, Vec3f *c);

void func_0022B08C(Plr *a, Vec3f *v) {
    Vec3f t;
    f32 m[16];
    Vec3f *pt = &t;
    f32 *p;
    t = *v;
    if (a->unk5DC != NULL) {
        p = a->unk5DC->m160;
    } else {
        func_00226DAC(a, m);
        p = m;
    }
    func_00272908(p, pt, v);
}
