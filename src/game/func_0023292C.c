#include "b07_types.h"

extern u8 D_801462E5[];
extern s32 D_800D297C;

s32 func_442B98(void *p);
s32 func_0022AB10(Actor *owner, s32 w);
void func_0026DA4C(s32 a0, s32 a1, s32 a2, void *a3, s32 a4, s32 a5);

void func_0023292C(Actor *actor, ActorState *state, u8 *obj)
{
    Actor *owner = actor->owner;
    u8 *pawn = AT(u8 *, owner, 0x5DC);
    s32 id = -1;
    s32 w;

    if (pawn != NULL) {
        if (D_801462E5[0] == 0 || func_442B98(pawn + 0x554) == 0) {
            w = AT(s16, owner, 0x62E);
            if (w == 1 && AT(s32, state, 0x144) == 0) {
                return;
            }
            if (w >= 0x12 && func_0022AB10(owner, w) <= 0) {
                return;
            }
            if (AT(s16, owner, 0x62E) == 0xE || AT(s16, owner, 0x62E) == 1 || AT(s16, owner, 0x62E) == 0) {
                id = AT(s32, owner, 0x11F8);
            }
            func_0026DA4C(AT(s32, obj, 0xC), AT(s32, actor, 0xB4), 1,
                          (u8 *)actor + (D_800D297C * 24 + 0x140), 0, id);
        }
    }
}
