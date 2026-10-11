#include "b06_types.h"

void func_0021EED8(Plr *a, Pawn *p);
void func_0023941C(Pawn *p);

void func_0022A37C(PlrGroup *g, Pawn *p) {
    Plr *a;
    func_0023941C(p);
    for (a = g->head; a != NULL; a = a->next) {
        if (a->unk5DC == p) {
            func_0021EED8(a, p);
        }
    }
}
