#include "b11_types.h"

s32 func_0024E148(Obj *a) {
    if (a->type == 1 && (a->flags & 0x300000)) {
        return 1;
    }
    switch (a->def->type) {
    case 1:
    case 2:
    case 5:
    case 8:
    case 9:
        return 1;
    default:
        return 0;
    }
}
