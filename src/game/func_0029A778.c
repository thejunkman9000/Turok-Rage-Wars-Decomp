#include "p4_types.h"
extern P4SlotTbl *D_8014D080;

void func_0029A778(s32 id, s32 kind, s32 val) {
    s32 idx = -1;
    s32 i;
    P4SlotEnt *p = D_8014D080->ent;
    P4SlotEnt *e;
    for (i = 0; i < 64; i++, p++) {
        if (p->id == id) {
            idx = i;
            break;
        }
    }
    e = &D_8014D080->ent[idx];
    if (kind == 1) {
        e->f4 = val;
        e->f8 = 0;
    } else {
        p = e;
        p->f8 = val;
    }
}
