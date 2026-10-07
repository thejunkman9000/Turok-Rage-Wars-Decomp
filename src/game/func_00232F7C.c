#include "b07_types.h"
extern f32 D_800C8130;
extern s32 D_801450B8;
void func_00273A34(Actor *actor, f32 v);
void func_00232F7C(Actor *actor, u8 *obj)
{
    f32 v = AT(f32, AT(u8 *, obj, 0x8), 0x294) * D_800C8130;
    if (D_801450B8 == 1) {
        if (AT(s32, obj, 0x4) == 2) {
            func_00273A34(actor, -v);
        }
    } else {
        if (AT(s32, obj, 0x4) == 0) {
            func_00273A34(actor, -v);
        }
    }
}
