#include "b23_types.h"

void func_002A0000(Mtx4f *m, Vec3f *v) {
    ((f32 *)m)[0xC] += v->x;
    ((f32 *)m)[0xD] += v->y;
    ((f32 *)m)[0xE] += v->z;
}
