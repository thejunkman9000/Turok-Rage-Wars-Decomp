#include "b07_types.h"

extern s32 D_8011FE88;
extern u8 *D_800D052C[];
extern u32 D_800D2980;
extern u8 D_80145088[];

s32 func_00232770(s32 w);
s32 func_00232790(s32 w);
s32 func_002327C4(s32 w);
void func_00237E70(void *a, void *b, s32 c);
void func_00214178(Actor *actor, ActorState *state, s32 id);

void func_0022FEF4(Actor *actor, ActorState *state)
{
    u16 nu;
    s32 cur;
    s32 nw;
    Actor *owner = actor->owner;

    cur = AT(s16, owner, 0x62E);
    nu = AT(u16, owner, 0x770);
    nw = (s16)nu;

    if (!(cur == nw && D_8011FE88 == 4)) {
        if (func_00232770(nw)) {
            AT(s32, owner, 0x13B8) = 1;
        } else if (func_00232790(nw)) {
            AT(s32, owner, 0x13BC) = 1;
        } else if (func_002327C4(nw)) {
            AT(s32, owner, 0x13C0) = 1;
        }
        AT(u16, owner, 0x62E) = nu;
        AT(s32, state, 0x2C) = AT(s32, D_800D052C[(s16)nu], 0x54);
        AT(s32, state, 0x120) = AT(s32, D_800D052C[AT(s16, owner, 0x62E)], 0x58);
        if (AT(void *, owner, 0x5DC) != NULL && D_800D2980 >= 5) {
            func_00237E70(D_80145088, AT(void *, owner, 0x5DC),
                          AT(s32, AT(u8 *, D_800D052C[AT(s16, owner, 0x62E)], 0), 0));
        }
        AT(s32, state, 0x124) = 0;
        AT(s32, state, 0x128) = 0;
        AT(u8, actor, 1) = 0;
        AT(s32, state, 0x130) = 0;
    }
    AT(s32, state, 0x13C) = 1;
    AT(s32, state, 0x144) = 1;
}
