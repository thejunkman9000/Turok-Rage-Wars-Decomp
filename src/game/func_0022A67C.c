#include "p1_types.h"
extern s32 D_8013B29C;
extern GameFlags D_801468A0[];
s32 func_00245774();
s32 func_00245788();
s32 func_0022A67C(ActorGroup *g) {
    Actor *a;
    s32 count;
    if (func_00245788() == 0 && func_00245774() == 0 && D_8013B29C == 0 && D_801468A0->unk20 == 0 && D_801468A0->unk1C != 0) {
        count = 0;
        for (a = g->head; a != NULL; a = a->next) {
            if (a->stats->unk8E == 1) {
                count++;
            }
        }
        if (count > 0) {
            D_801468A0->unk20 = 1;
            D_801468A0->unk1C = 0;
            return 1;
        }
    }
    return 0;
}
