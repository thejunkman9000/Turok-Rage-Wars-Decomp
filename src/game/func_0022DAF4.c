#include "b07_types.h"

extern f32 D_800C7EB8;
extern f32 D_800C7EBC;
extern f32 D_800C7EC0;

void func_0022DAF4(Actor *actor, u8 *obj)
{
    f32 k;
    f32 s;
    f32 c;

    actor->flags |= 0x800000;
    AT(f32, actor, 0x1D4) = D_800C7EB8;
    if (AT(s16, actor, 0x652) == 0xF) {
        f32 x = AT(f32, obj, 0x6C);
        k = D_800C7EBC;
        s = sinf(x + k);
        c = cosf(AT(f32, obj, 0x6C) + k);
        s *= D_800C7EC0;
        c *= D_800C7EC0;
        AT(f32, obj, 0x1C) += s;
        AT(f32, obj, 0x24) += c;
        AT(f32, obj, 0x6C) += AT(f32, actor, 0x728);
        AT(s32, actor, 0x728) = 0;
    }
}
