#include "b07_types.h"
void func_0022BE10(Actor *actor, ActorState *state);
void func_0022BEEC(Actor *actor, ActorState *state);
void func_0022C050(Actor *actor, ActorState *state);
void func_0022BD84(Actor *actor, ActorState *state, s32 flag)
{
    u32 w;
    u32 b1000;
    u32 b8000;
    u32 b10000;
    if (flag) {
        w = AT(u32, state, 0x38);
        b1000 = w & 0x1000;
        b8000 = w & 0x8000;
        b10000 = w & 0x10000;
        if (b1000 == 0) {
            AT(s32, actor, 0x840) = 0;
        } else {
            func_0022BE10(actor, state);
        }
        if (b8000) {
            func_0022BEEC(actor, state);
        }
        if (b10000) {
            func_0022C050(actor, state);
        }
    }
}
