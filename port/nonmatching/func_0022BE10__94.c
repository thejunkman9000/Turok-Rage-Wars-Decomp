#include "b07_types.h"
extern f32 D_800D2988;
extern f32 D_800C7E10;
extern f32 D_800C7E14;
void func_0021BFBC(Actor *actor, ActorState *state, s32 a2, s32 a3, s32 a4);
void func_0022BE10(Actor *actor, ActorState *state)
{
    s32 v;
    s32 n;
    f32 t;
    f32 x;
    t = AT(f32, actor, 0x840) + D_800D2988;
    if (t > D_800C7E10) {
        AT(f32, actor, 0x840) = t;
        v = 0x96 - (actor->unk5E4 >> 8);
        n = 1;
        if (v > 0) {
            s32 q = v / 15;
            if (q > 0) {
                n = q;
            }
        }
        actor->unk848 = 1;
        func_0021BFBC(actor, state, n << 8, 0, 0x1F);
        AT(f32, actor, 0x840) -= D_800C7E14;
    }
}
