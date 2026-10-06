#include "b06_types.h"

void func_002227D0(Plr *a, Plr *b, s32 c);

void func_0022B9B4(Plr *a) {
    if (a->unk1210 != 0) {
        if (a->unk5E4 != 0) {
            func_002227D0(a, a, 2);
        }
        a->unk1210 = 0;
        a->unk1214 = 0;
    }
}
