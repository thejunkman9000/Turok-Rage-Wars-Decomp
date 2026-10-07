#include "b06_types.h"

s32 func_0022A590(PlrGroup *g, Plr *p);
extern GameB6 D_801468A0[];

s32 func_002281CC(PlrGroup *g) {
    Plr *a;
    s32 idx;
    s32 sum;
    s32 i;
    u8 *gp;
    s32 t;
    if (D_801468A0->unk58 == 0) {
        return 0;
    }
    for (a = g->head; a != NULL; a = a->next) {
        idx = func_0022A590(g, a);
        sum = 0;
        for (i = 0; i < 8; i++) {
            if (i != idx) {
                sum += a->stats->unk1C[i];
                if (sum >= D_801468A0->unk58) {
                    gp = (u8 *)D_801468A0 - 0x5D8;
                    t = gp[0xD];
                    if (t == 0) {
                        return 1;
                    }
                    if (a->unk5D4 < 4) {
                        D_801468A0->unkA8 = 1;
                        return 1;
                    }
                    D_801468A0->unkA8 = 0;
                    if (t != 1) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
