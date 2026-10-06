#include "b06_types.h"

Plr *func_0022A5B0(PlrGroup *g, u8 *p) {
    Plr *a;
    for (a = g->head; a != NULL; a = a->next) {
        if (a->unk698 == p) {
            return a;
        }
    }
    return NULL;
}
