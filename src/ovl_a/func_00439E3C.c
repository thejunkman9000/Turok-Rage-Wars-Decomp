#include "o05_types.h"

typedef struct { u8 pad[0x28]; O05Vec3 v; } S;

O05Vec3 func_00439E3C(S *o) {
    return o->v;
}
