#include "o03_types.h"
void func_0025DF54(s32 snd);
s32 func_0041B5E4(O3Bar *o) {
    O3Hdr *p;
    func_0025DF54(0xE74);
    for (p = o->h.child; p != 0; p = p->next) {
        if (p->id2 != 8) {
            p->alpha = 100;
        }
    }
    return 0;
}
