#include "b02_types.h"

f32 func_00272768(void *a, void *b);
s32 func_0028B238(void *g, s16 id);
extern B2ActMgr D_8011FE88[];
extern const f32 D_800C6E30;
extern f32 D_800C6E34;
extern f32 D_800C6E38;

void func_0020AA40(B2Mgr *m) {
    B2Node *n;
    B2Rec *r;
    B2Obj *best;
    B2Obj *a;
    f32 bestd;
    f32 d;
    s32 i;
    register s32 v asm("$2");
    B2ActMgr *g = D_8011FE88;

    for (n = m->head; n != NULL; n = n->next) {
        do { r = (B2Rec *)&m->pool0->data[n->id * m->pool0->elemSize];
        if (r->flags & 1) {
            bestd = D_800C6E34;
            best = NULL;
            if (r->id != 0x653) {
                for (i = 0; i < g->count; i++) {
do {
                    a = &g->actors[i];
                    if (r->id == 0x64E) {
                        v = a->unkE4;
                    } else if ((u32)(a->unkE4 - 0x643) < 2) {
                        v = func_0028B238(g, a->def->info.unk14);
                    } else {
                        continue;
                    }
                    if (v == r->id) {
                        d = func_00272768(r, &a->pos);
                        if (d < bestd || bestd == D_800C6E30) {
                            bestd = d;
                            best = a;
                        }
                    }
} while (0);
                }
                if (best == NULL) {
                    n->unk34 = NULL;
                    goto clear;
                }
                if (bestd < D_800C6E38) {
                    n->unk34 = best;
                    continue;
                }
                n->unk34 = NULL;
clear:
                r->flags &= 0xFFFE;
            }
        } } while (0);
    }
}
