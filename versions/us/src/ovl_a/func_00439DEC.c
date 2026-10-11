#include "o05_types.h"

typedef struct { u8 pad[0x1C]; O05Vec3 v; } S;

O05Vec3 func_00439DEC(S *o) {
    return o->v;
}
