#include "b06_types.h"

void func_0026D980();
void func_0026D9D0();
void func_0021C9B4(Plr *a, Pawn *p);
s32 func_002458F8();

void func_0022A274(PlrGroup *g, Pawn *p) {
    Plr *a;
    func_0026D980();
    for (a = g->head; a != NULL; a = a->next) {
        if (a->unk5DC != p || p->unk24 == 1 || func_002458F8() != 0) {
            func_0021C9B4(a, p);
        }
    }
    func_0026D9D0();
}
