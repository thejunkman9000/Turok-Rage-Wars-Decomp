#include "b07_types.h"
extern f32 D_800C7E58;
extern f32 D_800C7E5C;
extern f32 D_800C7E60;
extern f32 D_800C7E64;
extern s32 D_8013B2BC;
void func_002227D0(Actor *actor, ActorState *state, s32 kind);
void func_0022CC24(Actor *actor, ActorState *state);
void func_0022CB4C(Actor *actor, ActorState *state)
{
    f32 k = D_800C7E58;
    if (D_8013B2BC == 0x1DB1) {
        k = D_800C7E5C;
    }
    if (actor->unk1450 != 0) {
        if (AT(f32, actor, 0x658) >= D_800C7E60) {
            func_002227D0(actor, state, 6);
        } else {
            AT(f32, state, 0x20) = k * AT(f32, AT(u8 *, state, 0x18), 0x20);
        }
    } else if (!(AT(u32, actor, 0x6AC) & 0x10) || AT(f32, actor, 0x658) >= D_800C7E64) {
        func_002227D0(actor, state, 6);
    } else {
        AT(f32, state, 0x20) = k * AT(f32, AT(u8 *, state, 0x18), 0x20);
    }
    func_0022CC24(actor, state);
}
