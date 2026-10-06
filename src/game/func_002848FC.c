#include "b19_types.h"
s32 func_002848FC(B19Obj *o) {
    switch (o->id) {
    case 5: case 6: case 7: case 9: case 0x11: case 0x13: case 0x1A: case 0x101: case 0x110:
        return 1;
    default:
        return 0;
    }
}
