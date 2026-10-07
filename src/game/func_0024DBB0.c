#include "b11_types.h"

extern u8 D_8013B364[];
extern u8 D_80131600[];
extern f32 D_800C8DC4;
s32 func_0020CB3C(void *a, Vec3f *v);
Vec3f *func_0020C994(void *a, s32 b);
void func_002720EC(Vec3f *v);
void func_0027200C(Vec3f *out, Vec3f *a, f32 s);
void func_0028FFB0(void *a, s32 b, s32 id, Vec3f c, Vec3f d, s32 e, f32 f);

void func_0024DBB0(Obj *a, Vec3f v, s32 id, f32 t) {
    Vec3f A;
    Vec3f B;
    Vec3f C;
    Vec3f D;
    struct { s32 f0; Vec3f e; u8 pad[0x148]; s32 f158; s32 f15C; } S;
    Vec3f *n;
    n = func_0020C994(D_8013B364, func_0020CB3C(D_8013B364, &v));
    S.e = v;
    D = S.e;
    S.f158 = (s32)a->unk14;
    if (n != 0) {
        D = *n;
    }
    A.x = 0;
    A.z = 0;
    A.y = D_800C8DC4;
    B.x = B.y = B.z = A.x;
    func_002720EC(&B);
    if (id != 0xBD7) {
        func_0027200C(&C, &B, 409.59998f);
    }
    func_0028FFB0(D_80131600, 0, id, C, D, S.f158, t);
}
