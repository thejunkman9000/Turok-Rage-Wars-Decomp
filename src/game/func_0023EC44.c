#include "b09_types.h"

void func_0023EC44(B09FlagObj *o, B09Evt *e) {
    u32 old;
    u32 f;
    if (o->flags & 0x1000) {
        o->flags &= ~0x2000;
    }
    old = o->flags;
    f = old & 0xFFFC7FFF;
    o->flags = f;
    if (old & 0x7000) {
        switch (e->kind) {
        case 8:
            o->flags = f | 0x10000;
            return;
        case 7:
            o->flags = f | 0x8000;
            break;
        }
    }
}
