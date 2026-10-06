#include "b19_types.h"
s32 func_00284980(B19Obj *o) {
    switch (o->id) {
    case 8:
    case 0xD:
    case 0x12:
        return 1;
    default:
        return 0;
    }
}
