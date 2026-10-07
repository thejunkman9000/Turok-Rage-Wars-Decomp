#include "b01_types.h"

void func_00202CA0(void *dst, Vec3f *v);

void *func_00203848(void *dst, void *unused, B01State *state) {
    Vec3f v;
    v.x = state->vec130.x;
    v.y = state->vec130.y;
    v.z = state->vec130.z;
    func_00202CA0(dst, &v);
    return dst;
}
