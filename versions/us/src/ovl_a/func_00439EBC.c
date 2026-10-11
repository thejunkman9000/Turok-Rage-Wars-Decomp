#include "o05_types.h"

typedef struct { u8 pad[0x10]; O05Vec3 v; } S;

O05Vec3 func_00439EBC(S *o) {
    return o->v;
}
