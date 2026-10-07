#include "b07_types.h"

extern f32 D_8013B184;
extern f32 D_800C7F08;

void *func_0024E7CC(void *obj);
s32 func_0024E61C(void *obj);
void func_0021B1E4(Actor *actor, s32 a1, s32 a2, s32 a3);

void func_0022E694(Actor *actor, u8 *obj)
{
    void *p = func_0024E7CC(obj);

    if (p != NULL && (AT(u32, p, 0x44) & 0x4000)) {
        AT(s32, obj, 0x20) = 0;
    } else if (D_8013B184 - D_800C7F08 > AT(f32, obj, 0xC)) {
        func_0021B1E4(actor, AT(s32, actor, 0x5EC), 0, 0);
    }
    if (func_0024E61C(obj) != 0) {
        AT(Vec3f, actor, 0x6F8) = AT(Vec3f, obj, 0x8);
    }
}
