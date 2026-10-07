#include "b17_types.h"

extern f32 D_800C9AF4;
extern Tri4 *D_800D2630;
extern Vec3f D_80115DF0;
void func_00272088(Vec3f *d, Vec3f *a, Vec3f *b);

Vec3f *func_00275F98(Vec3f *out, Tri4 *t) {
    Vec3f e0, e1;

    if (t == 0) {
        D_80115DF0.x = 0;
        D_80115DF0.z = 0;
        D_80115DF0.y = D_800C9AF4;
    } else if (t != D_800D2630) {
        e0.x = t->v[1]->x - t->v[0]->x;
        e0.y = t->v[1]->y - t->v[0]->y;
        e0.z = t->v[1]->z - t->v[0]->z;
        e1.x = t->v[2]->x - t->v[1]->x;
        e1.y = t->v[2]->y - t->v[1]->y;
        e1.z = t->v[2]->z - t->v[1]->z;
        func_00272088(&D_80115DF0, &e1, &e0);
    }
    *out = D_80115DF0;
    D_800D2630 = t;
    return out;
}
