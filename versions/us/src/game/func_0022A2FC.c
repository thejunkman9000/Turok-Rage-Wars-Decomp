#include "b06_types.h"

void func_0021CBAC(Plr *a, Pawn *p);
extern s32 D_800CE47C;

void func_0022A2FC(PlrGroup *g, Pawn *p) {
    Plr *a;
    for (a = g->head; a != NULL; a = a->next) {
        if (a->unk5DC == p && p->unk24 == 0 && a->unkE4 != D_800CE47C) {
            func_0021CBAC(a, p);
        }
    }
}
