#include "b01_types.h"

void func_00202CA0(void *dst, Vec3f *v);
void func_002742B4(void *q, void *arg);

void func_00203CFC(void *unused, B01StateV *state, void *arg) {
    f32 out[4];
    Vec3f v;
    v.x = state->vec130.x;
    v.y = state->vec130.y;
    v.z = state->vec130.z;
    func_00202CA0(out, &v);
    func_002742B4(out, arg);
}
