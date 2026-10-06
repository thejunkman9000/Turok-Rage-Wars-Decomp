#include "b06_types.h"

void func_002227D0(Plr *a, Plr *b, s32 c);

void func_0022B974(Plr *a) {
    if (a->unk1210 == 0) {
        func_002227D0(a, a, 0x27);
        a->unk1210 = 1;
        a->unk1214 = 0;
    }
}
