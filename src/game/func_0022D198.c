#include "b07_types.h"

void func_00271FD8(Vec3f *out, void *a, void *b);
void func_002720EC(Vec3f *v);
void func_0027200C(Vec3f *out, Vec3f *v, f32 s);
void func_00271FA4(void *out, void *a, Vec3f *b);

void func_0022D198(Actor *actor)
{
    Vec3f v;

    func_00271FD8(&v, (u8 *)actor + 0x16C4, (u8 *)actor + 0x4A0);
    func_002720EC(&v);
    func_0027200C(&v, &v, 30.0f);
    func_00271FA4((u8 *)actor + 0x6E8, (u8 *)actor + 0x4A0, &v);
}
