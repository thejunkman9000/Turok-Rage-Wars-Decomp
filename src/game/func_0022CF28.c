#include "b07_types.h"
extern f32 D_800C7E84;
extern f32 D_800C7E88;
extern f32 D_800C7E8C;
void func_0023912C(void *p);
void func_00218464(void *p);
void func_0025DE74(s32 id, f32 x, f32 y, f32 z, void *src, s32 a5);
void func_0022CF28(Actor *actor, ActorState *state)
{
    f32 t, k;
    AT(f32, actor, 0x6C0) *= D_800C7E84;
    AT(f32, actor, 0x6C4) *= D_800C7E84;
    t = AT(f32, state, 0x20) * D_800C7E88;
    k = D_800C7E8C;
    AT(f32, state, 0x20) = t;
    if (t < k) {
        AT(f32, state, 0x20) = k;
    }
    AT(s32, actor, 0x848) = 0;
    func_0023912C(AT(void *, actor, 0x5DC));
    func_00218464((u8 *)actor + 0x938);
    if (AT(u32, state, 0x38) & 0x8000) {
        func_0025DE74(0x2DA, AT(f32, state, 0x8), AT(f32, state, 0xC), AT(f32, state, 0x10), 0, -1);
    } else {
        func_0025DE74(0x2DC, AT(f32, state, 0x8), AT(f32, state, 0xC), AT(f32, state, 0x10), 0, -1);
    }
}
