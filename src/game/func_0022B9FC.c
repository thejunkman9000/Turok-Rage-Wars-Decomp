#include "b06_types.h"

Plr *func_0022B9FC(PlrGroup *g) {
    Plr *a;
    Plr *best = NULL;
    s32 max = -1;
    s32 sum;
    s32 i;
    u32 idx;
    for (a = g->head; a != NULL; a = a->next) {
        idx = ((u32)a - (u32)g->unk4) / 5864;
        sum = 0;
        for (i = 0; i < 8; i++) {
            if (i != idx) {
                sum += a->stats->unk3C[i];
                if (max < sum) {
                    max = sum;
                    best = a;
                }
            }
        }
    }
    return best;
}
