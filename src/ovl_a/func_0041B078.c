#include "o03_types.h"
void func_0025DF54(s32 snd, void *p);
s32 func_0041B078(O3List *o, s32 a1, s32 a2, s32 a3) {
    O3ListG *g;
    O3ListSel *s = (O3ListSel *)o;
    if (a3 != 1) return 0;
        g = o->g;
        s->sel = s->sel + 1;
        if (s->sel >= s->cnt) {
            s->sel = 0;
        }
        g->sel = &o->ent[s->sel];
        func_0025DF54(0xE81, g);
    return 0;
}