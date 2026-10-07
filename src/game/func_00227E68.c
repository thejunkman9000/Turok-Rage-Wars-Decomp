#include "b06_types.h"

s32 func_00245774();
s32 func_00245788();
s32 func_002282C8(PlrGroup *g);
void func_0022A738(PlrGroup *g);
extern s32 D_800F7D10;
extern GameB6 D_801468A0[];
extern s32 D_801468BC;
extern s32 D_80146918;
extern s32 D_80146924;

void func_00227E68(PlrGroup *g) {
    Plr *a;
    Plr *r;
    s32 cnt;
    s32 n;
    if (D_80146918 != 0 && func_00245774() == 0 && func_00245788() == 0) {
        cnt = 0;
        for (a = g->head; a != NULL; a = a->next) {
            if (a->stats->unk90 == 0) {
                cnt++;
            }
        }
        n = cnt;
        if (n > 0) {
            for (a = g->head; a != NULL; a = a->next) { if (a->stats->unk8F == 1 || a->stats->unk90 == 1) { break; } }
            r = a;
            if (r != NULL) {
                D_800F7D10 = 0;
            }
            if (D_801468A0->unk84 != 1) {
                if (D_801468A0->unk84 < 2) {
                    goto body;
                }
                if (D_801468A0->unk84 < 4) {
                    goto done;
                }
body:
                if (n > 0) {
                    for (a = g->head; a != NULL; a = a->next) { if (a->stats->unk8F == 1 || a->stats->unk90 == 1) { break; } }
            r = a;
                    if (r != NULL) {
                        r->stats->unk90 = 0;
                        D_80146924 = 3;
                    }
                } else {
                    D_801468A0->unk84 = 2;
                }
            } else {
                D_801468A0->unk84 = 2;
                for (a = g->head; a != NULL; a = a->next) { if (a->stats->unk8F == 1 || a->stats->unk90 == 1) { break; } }
            r = a;
                if (r != NULL) {
                    r->stats->unk90 = 0;
                    *(u16 *)&r->stats->unk4 = *(u16 *)&r->stats->unk4 + 1;
                    D_800F7D10 = 0;
                }
            }
done:
            if (func_002282C8(g) != 0 && D_801468BC == 0) {
                func_0022A738(g);
            }
        }
    }
}
