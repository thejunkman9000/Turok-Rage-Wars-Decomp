/* port (passthru_fix.py): func_002833A4 needs a0 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "b17_types.h"

ActorX *func_002833A4();
s32 func_0022B168(ActorX *p);
void func_00229530(ActorX *p, s32 a, s32 b);
void func_002227D0(Actor *owner, ActorX *a, s32 n);
void func_00284408(ActorX *a);
void func_0025E1E4(ActorX *a);

void func_00279A70(ActorX *a) {
    u16 t;
    ActorX *p, *tg;
    ChildB *c;

    t = a->type;
    if (t != 0x414) {
        if (t == 0x42D) {
            p = func_002833A4(a);
            if (p->u5A8 != 0) {
                if (func_0022B168(p) == 0) {
                    func_00229530(p, p->u5A4, p->u5A8);
                }
            }
            goto L;
        }
    } else {
L:
        p = func_002833A4(a);
        p->u5A8 = 0;
        if (func_0022B168(p) == 0) {
            p->u59C = 1;
        }
    }
    if (a->s1B9 == 8 || a->s1BA == 8 || a->s1B8 == 8) {
        tg = a->tgt;
        if (tg != 0 && tg->kind == 1 && (tg->flags & 0x300000)) {
            func_002227D0(tg->owner, tg, 2);
        }
    }
    func_00284408(a);
    c = a->ch118;
    if (c->def->wBE != 0xFFFF) {
        func_0025E1E4(a);
    }
    if (c->def->wC2 != 0xFFFF) {
        func_0025E1E4(a);
    }
}
