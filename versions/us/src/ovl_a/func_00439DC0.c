#include "o05_types.h"

typedef struct { u8 pad[0x1C]; O05Vec3 v; } S;

void func_00439DC0(S *o, O05Vec3 v) {
    o->v = v;
}
