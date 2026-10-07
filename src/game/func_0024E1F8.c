#include "b11_types.h"

s32 func_00245788();

s32 func_0024E1F8(Obj *a) {
    switch (a->def->type) {
    case 11:
        if (a->type == 1 && (a->flags & 0x300000) && (a->unk1D8->unk80C != 0 || func_00245788() != 0)) {
            return 1;
        }
        return 0;
    case 1:
    case 5:
        return 1;
    default:
        return 0;
    }
}
