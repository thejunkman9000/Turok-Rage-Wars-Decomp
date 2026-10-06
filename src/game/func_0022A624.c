#include "b06_types.h"

Plr *func_0022A624(PlrGroup *g, u32 n) {
    Plr *a = NULL;
    s32 cnt = 0;
    if (n < 8) {
        for (a = g->head; a != NULL; a = a->next) {
            if (a->unk5DC != NULL && a->unk5DC->unk564 == 0) {
                if (cnt == n) {
                    return a;
                }
                cnt += 1;
            }
        }
    }
    return a;
}
