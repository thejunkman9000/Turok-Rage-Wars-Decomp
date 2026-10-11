#include "o05_types.h"

typedef struct { u8 pad[0x28]; O05Vec3 v; } S;

void func_00439E10(S *o, O05Vec3 v) {
    o->v = v;
}
