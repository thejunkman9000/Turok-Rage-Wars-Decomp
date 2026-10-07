#include "o03_types.h"
typedef struct { u8 pad[0x110]; s32 sel; } O3Sel;
s32 func_0041AD84(O3Sel *o) {
    return o->sel;
}
