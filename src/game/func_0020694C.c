#include "b01_types.h"

extern s32 D_800D297C;
s32 func_0024BFC4(B01Actor *actor, s32 idx);
void func_0024AA08(B01Actor *actor, B01State *state, B01Evt *evt);
void func_0026DA4C(s32 a, s32 b, s32 c, B01Seg *seg, s32 d, s32 e);

void func_0020694C(B01Actor *actor, B01State *state, B01Evt *evt) {
    s32 n = actor->unkE7;
    s32 i;
    for (i = 0; i < n; i++) {
        s32 p = func_0024BFC4(actor, i);
        if (p != 0) {
            evt->unkC = p;
            evt->unk10 = p;
            func_0024AA08(actor, state, evt);
            func_0026DA4C(p, actor->unkB4, 1, &actor->seg[D_800D297C], 0, actor->unk3);
        }
    }
}
