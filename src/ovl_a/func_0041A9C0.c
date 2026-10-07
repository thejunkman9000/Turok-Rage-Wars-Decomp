#include "o03_types.h"
s32 func_0041A9C0(O3Bar *o) {
    O3Hdr *p;
    o->f54 = 2;
    for (p = o->h.child; p != 0; p = p->next) {
        if (p->id2 != 8) {
            p->alpha = 100;
        }
    }
    return 0;
}
