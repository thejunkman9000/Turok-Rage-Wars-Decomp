#include "b09_types.h"

void func_0023EBEC(B09FlagObj *o, B09Evt *e) {
    u32 f = o->flags & ~0xE00;
    u32 m;
    o->flags = f;
    m = e->mask;
    if (m & 0x20000000) {
        o->flags = f | 0x200;
        return;
    }
    if (m & 0x40000000) {
        o->flags = f | 0x400;
        return;
    }
    if ((s32)m < 0) {
        o->flags = f | 0x800;
    }
}
