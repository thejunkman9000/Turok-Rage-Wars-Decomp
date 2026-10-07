#include "o05_types.h"

typedef struct { u8 pad[0x34]; s32 f34; } O05Ob;
s32 func_00439E60(void *o, s32 n);
void func_00439EB4(void *o, s32 v);
typedef struct { u8 pad0[4]; O05Vec3 a; O05Vec3 b; s32 w1C, w20, w24, w28, w2C, w30; s32 f34; } O05Box;

s32 func_00439D3C(O05Box *o, s32 n, O05Vec3 a, O05Vec3 b) {
    o->b = b;
    o->a = a;
    o->w1C = 0;
    o->w20 = 0;
    o->w24 = 0;
    o->w28 = 0;
    o->w2C = 0;
    o->w30 = 0;
    func_00439E60(o, n);
    func_00439EB4(o, 0);
    return o->f34;
}
