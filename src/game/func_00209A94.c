#include "b02_types.h"

s32 func_00209A94(B2Ctl *ctl) {
    switch (ctl->curId) {
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 13:
        return 1;
    default:
        return 0;
    }
}
