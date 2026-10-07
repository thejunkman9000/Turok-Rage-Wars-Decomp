#include "o03_types.h"
s32 func_0041AFF0(O3Bar *o) {
    O3Hdr *p;
    for (p = o->h.child; p != 0; p = p->next) {
        if (p->id2 != 8) {
            p->alpha = 200;
        }
    }
    return 0;
}
