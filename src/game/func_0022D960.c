#include "b07_types.h"

void *func_0024E7CC(void *obj);
void func_00271FD8(Vec3f *out, Vec3f *a, void *b);
f32 func_00271B18(Vec3f *v);

void func_0022D960(Actor *actor, u8 *obj)
{
    Vec3f v10;
    Vec3f v20;
    void *p;

    p = func_0024E7CC(obj);
    AT(void *, actor, 0x7FC) = p;
    if (p != NULL) {
        AT(s32, actor, 0x7F4) = 0;
        AT(f32, actor, 0x800) = AT(f32, obj, 0x8);
        AT(f32, actor, 0x804) = AT(f32, obj, 0xC);
        AT(f32, actor, 0x808) = AT(f32, obj, 0x10);
        v10.x = AT(f32, p, 0x34);
        v10.y = AT(f32, p, 0x38);
        v10.z = AT(f32, p, 0x3C);
        func_00271FD8(&v20, &v10, (u8 *)actor + 0x800);
        v20.y = 0;
        AT(f32, actor, 0x7F8) = func_00271B18(&v20);
    }
}
