#include "b07_types.h"

s32 func_0022EAFC(Actor *actor, s32 i);
void func_0025DF54(s32 id);

s32 func_0022FAE8(Actor *actor)
{
    s32 lim;
    s32 k;
    s32 j;

    lim = AT(s8, actor, 0x603 + AT(s16, actor, 0x62E) * 2);
    if (lim < 0) {
        lim = 0;
    }
    if (lim < 8) {
        lim = lim + 1;
    } else {
        lim = 1;
    }
    for (; lim < 8; lim++) {
        for (j = 0; j < 22; j++) {
            if (lim == AT(s8, actor, 0x603 + j * 2)) {
                break;
            }
        }
        if (j < 22) {
            if (func_0022EAFC(actor, j) != 0) {
                return j;
            }
        }
    }
    lim = AT(s8, actor, 0x603 + AT(s16, actor, 0x62E) * 2);
    for (k = 1; k < lim; k++) {
        for (j = 0; j < 22; j++) {
            if (k == AT(s8, actor, 0x603 + j * 2)) {
                break;
            }
        }
        if (j < 22) {
            if (func_0022EAFC(actor, j) != 0) {
                return j;
            }
        }
    }
    func_0025DF54(0xD4D);
    return AT(s16, actor, 0x62E);
}
