#include "b07_types.h"

extern u8 D_801462E5[];
extern u8 *D_800D052C[];

void func_0022E998(Actor *actor)
{
    u8 *w;
    s16 idx;
    s8 *q;
    u16 nxt;

    if (D_801462E5[0] != 0) {
        return;
    }
    if (AT(s32, actor, 0xCB8) != 0 && AT(s32, actor, 0x938) != 0) {
        return;
    }
    if (*(s32 *)(D_801462E5 - 0x55) != 0 && (AT(u32, actor, 0x6AC) & 0x20)) {
        return;
    }
    if (AT(u32, actor, 0x6B0) & 0x200) {
        w = D_800D052C[AT(s16, actor, 0x770)];
        idx = AT(s16, w, 0xC);
        nxt = AT(u16, w, 0xC);
        if (idx != -1 && *(q = (s8 *)actor + idx * 2 + 0x602) != 0) {
            AT(u16, actor, 0x770) = nxt;
        }
    }
}
