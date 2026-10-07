#include "b01_types.h"
void func_00202CA0(f32 *dst, Vec3f *v);
void func_002742B4(f32 *a, f32 *b);
void func_00271FD8(f32 *dst, void *p, s32 q);
void func_00272C3C(f32 *a, f32 *b, void *p);
void func_00271FA4(void *a, void *b, s32 q);


void func_00203D4C(void *unused, B01State *state, s32 arg2, void *arg3) {
    f32 m[16];
    f32 v50[4];
    f32 v60[4];
    Vec3f v;
    f32 *pm = m;
    f32 *p50 = v50;
    v.x = state->vec130.x;
    v.y = state->vec130.y;
    v.z = state->vec130.z;
    func_00202CA0(v60, &v);
    func_002742B4(v60, pm);
    func_00271FD8(p50, arg3, arg2);
    func_00272C3C(pm, p50, arg3);
    func_00271FA4(arg3, arg3, arg2);
}
