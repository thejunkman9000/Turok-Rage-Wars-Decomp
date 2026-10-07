#include "b06_types.h"

void func_44ACCC();
void func_4426E4(u8 *a, u8 *b, Plr *c, u8 *d, s32 e);
void func_44A37C(Plr *p);
Plr *func_0022A5E4(u8 *a, s32 i);
extern u8 D_45047C[];
extern u8 D_450DA8[];
extern u8 D_451700[];
extern u8 D_451724[];
extern u8 D_451748[];
extern u8 D_45176C[];
extern u8 D_80145040[];
extern u8 D_801462E5;
extern s32 D_80146938;
extern s32 D_8014693C;

void func_0022591C(Plr *a, OutB6 *b) {
    u8 *p;
    PlrStats *st;
    Plr *q;
    Plr *last;
    s32 i, j, cnt, dead;
    b->unk1C = 0;
    b->unk20 = 0;
    b->unk24 = 0;
    func_44ACCC();
    if (D_801462E5 != 0) {
        if (a->unk1450 == 0) {
            switch (a->unk5D4) {
            case 0:
                p = D_451700;
                break;
            case 1:
                p = D_451724;
                break;
            case 2:
                p = D_451748;
                break;
            case 3:
                p = D_45176C;
                break;
            default:
                goto next;
            }
            func_4426E4((u8 *)a->unk5DC + 0x554, p, a, a->unk698, 0);
        }
next:
        if (D_80146938 != 0 && (st = a->stats, st->unk94 == 0) && (dead = 0, st->unk95 != 0)) {
            cnt = 0;
            last = NULL;
            i = 0;
            do {
                q = func_0022A5E4(D_80145040, i);
                if (q != NULL) {
                    if (q->stats->unk95 != 0) {
                        dead++;
                        if (q->unk5E4 == 0) {
                            cnt++;
                        }
                    }
                    if (q->stats->unk80 == 0xE) {
                        last = q;
                    }
                }
                i++;
            } while (i < 8);
            if (cnt == dead) {
                if (D_8014693C == 2) {
                    j = 0;
                    if (last->unk5E4 == 0) {
                        do {
                            q = func_0022A5E4(D_80145040, j);
                            j++;
                            if (q == NULL) continue;
                            if (q->stats->unk95 != 0) {
                                func_44A37C(q);
                            }
                        } while (j < 8);
                    }
                }
                if (D_8014693C < 3) {
                    func_44A37C(last);
                }
            }
        }
    } else {
        if (a->unk5DC != NULL) {
            if (a->unk5EA != 0) {
                func_4426E4((u8 *)a->unk5DC + 0x554, D_45047C, a, a->unk698, 0);
            } else {
                func_4426E4((u8 *)a->unk5DC + 0x554, D_450DA8, a, a->unk698, 0);
            }
        }
    }
}
