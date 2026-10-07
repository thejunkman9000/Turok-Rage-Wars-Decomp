#include "b11_types.h"

extern f32 D_800C8C58;
extern f32 D_800C8C5C;
extern f32 D_800C8C60;
extern f32 D_800C8C64;
extern f32 D_800D06C0[];
void func_0027302C(f32 *a, f32 *b);
void func_0027200C(Vec3f *out, Vec3f *a, f32 s);
void func_002734B8(f32 *m, f32 x, f32 y, f32 z);
void func_00272D70(f32 *m, f32 a, f32 x, f32 y, f32 z);
void func_0026F690(f32 *a, f32 *b, f32 *c);

void func_0024C6D8(s32 unused, B11P *p, f32 *m, s32 flag, s32 n) {
    Vec3f a18;
    Vec3f c28;
    f32 m2[16];
    f32 m1[16];
    f32 k;
    f32 f;
    f32 k2;
    if (flag != 0) {
        a18.x = m[12];
        a18.y = m[13];
        a18.z = m[14];
        c28 = p->v18;
        k = D_800D06C0[0x19 - (s8)p->u12] * D_800C8C58 * D_800C8C5C;
        f = D_800C8C60;
        if (n != 5) {
            f = n;
        }
        k = k * f;
        func_0027302C(m1, m);
        k2 = D_800C8C64;
        func_0027200C(&a18, &a18, k2);
        func_002734B8(m1, a18.x, a18.y, a18.z);
        func_00272D70(m2, k, c28.x, c28.y, c28.z);
        func_0026F690(m, m1, m2);
        func_0027200C(&a18, &a18, k2);
        func_002734B8(m, a18.x, a18.y, a18.z);
        if (p->s14 == flag) {
            p->u12 = p->u12 - 1;
        }
    }
}
