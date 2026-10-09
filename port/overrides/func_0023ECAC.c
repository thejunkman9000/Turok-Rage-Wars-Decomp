/* port (passthru_fix.py): func_0028B2D4 needs a1 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "b09_types.h"

extern u8 D_8011FE88[];
B09Seat *func_0028B2D4(u8 *, u32);

void func_0023ECAC(B09FlagObj *o, u32 pt_a1) {
    u32 old;
    B09Seat *s;
    if (o->flags & 0x1000) {
        o->flags &= ~0x2000;
    }
    old = o->flags;
    o->flags = old & 0xFFFC7FFF;
    if (old & 0x7000) {
        s = func_0028B2D4(D_8011FE88, pt_a1);
        if (s != NULL) {
            if (s->flags44 & 0x400000) {
                o->flags |= 0x8000;
            } else if (s->h52 & 0x80) {
                o->flags |= 0x10000;
            }
        }
    }
}
