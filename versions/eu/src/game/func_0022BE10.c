#include "b07_types.h"
extern f32 D_800D2988;
extern f32 D_800C7E10;
extern f32 D_800C7E14;
void func_0021BFBC(Actor *actor, ActorState *state, s32 a2, s32 a3, s32 a4);
void func_0022BE10(Actor *actor, ActorState *state)
{
    s32 v;
    s32 n;
    register f32 t asm("$f2");
    f32 x;
    register f32 cur asm("$f0");
    register f32 d asm("$f1");
    cur = AT(f32, actor, 0x840);
    d = D_800D2988;
    t = cur + d;
    x = D_800C7E10;
    AT(f32, actor, 0x840) = t;
    if (t > x) {
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
