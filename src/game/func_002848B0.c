#include "b19_types.h"
s32 func_002848B0(B19Obj *o) {
    switch (o->id) {
    case 2:
    case 0x56:
    case 0x111:
    case 0x126:
        return 1;
    default:
        return 0;
    }
}
