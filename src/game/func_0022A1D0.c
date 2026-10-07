#include "b06_types.h"

s32 func_0024D150(Plr *a);

void func_0022A1D0(PlrGroup *g, PlrList *l) {
    Plr *a;
    for (a = g->head; a != NULL; a = a->next) {
        a->unk70 = 0;
        a->unk358 = 0;
        if (func_0024D150(a) != 0) {
            if (l->cntA != 0x200) {
                l->arrA[l->cntA++] = a;
            }
            if (l->cntB != 0x80) {
                l->arrB[l->cntB++] = a;
            }
        }
    }
}
