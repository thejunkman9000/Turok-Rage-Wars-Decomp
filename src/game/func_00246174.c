#include "b10_types.h"

extern f32 D_800C8914;
void func_0024DD00(void *o);

typedef struct B10Init {
    u8 pad0[0x1C];
    s32 f1C, f20, f24, f28, f2C, f30, f34, f38, f3C, f40, f44;
    f32 f48;
    s32 f4C;
} B10Init;

void func_00246174(B10Init *o) {
    func_0024DD00(o);
    o->f1C = 0;
    o->f20 = 0;
    o->f24 = 0;
    o->f28 = 0;
    o->f2C = 0;
    o->f30 = 0;
    o->f34 = 0;
    o->f38 = 0;
    o->f3C = -1;
    o->f40 = 0;
    o->f44 = 0;
    o->f4C = 0;
    o->f48 = D_800C8914;
}
