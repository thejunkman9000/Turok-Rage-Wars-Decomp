#include "b06_types.h"

void func_00273208(f32 *m, Vec3f *v);
void func_0027200C(Vec3f *out, Vec3f *v, f32 s);
void func_00271FA4(Vec3f *out, Vec3f *a, u8 *b);
void func_002734B8(f32 *m, f32 x, f32 y, f32 z);
void func_00273DDC(f32 *m);
void func_002702EC(f32 *m, u8 *dst);

void func_0022B3C0(u8 *a, s32 unused, Vec3f *v) {
    f32 m[16];
    Vec3f t;
    func_00273208(m, v);
    func_0027200C(&t, v, 5.12f);
    func_00271FA4(&t, &t, a + 0x1200);
    func_002734B8(m, t.x, t.y, t.z);
    func_00273DDC(m);
    func_002702EC(m, a + 0x1600);
}
