#include "b06_types.h"

s32 func_00245774();
s32 func_00245788();
s32 func_0022804C(PlrGroup *g);
s32 func_0022C640(PlrGroup *g);
void func_0022A738(PlrGroup *g);
s32 func_442B98(u8 *p);
extern f32 D_800D2988;
extern u8 D_8014561C[];
extern GameB6 D_801468A0[];
extern s32 D_80146938;
extern s32 D_80146948;

void func_00228394(PlrGroup *g) {
    u32 i;
    u32 total;
    u32 dead;
    s32 flag;
    s32 j;
    Plr *a;
    Plr *r;
    GameB6 *h;
    if (func_00245774() == 0 && func_00245788() == 0 && D_801468A0->unk1C == 0 && ((u8 *)D_801468A0)[-0x5BB] != 0) {
        if (func_442B98((u8 *)D_801468A0 - 0x1284) == 0 && D_801468A0->unk14 > 0.0f && *(s32 *)((u8 *)D_801468A0 - 0xC) == 0) {
            if (func_0022C640(g) != 0) {
                D_801468A0->unk14 = D_801468A0->unk14 - D_800D2988;
            }
            if (D_801468A0->unk14 <= 0.0f && D_801468A0->unk1C == 0) {
                D_801468A0->unk14 = 0.0f;
                if (((u8 *)D_801468A0)[-0x5CB] == 3) {
                    D_801468A0->unkA8 = 0;
                }
                func_0022A738(g);
            }
        }
        if (func_442B98(D_8014561C) == 0) {
            if (func_0022804C(g) != 0 && (h = (GameB6 *)(D_8014561C + 0x1284), h->unk1C == 0) && *(s32 *)(D_8014561C + 0x1278) == 0 && h->unk18 > 0 && h->unk54 == 0) {
                func_0022A738(g);
            }
        }
        total = 0;
        if (D_80146938 != 0) {
            dead = 0;
            flag = 0;
            i = 0;
            do {
                a = NULL;
                j = 0;
                if (i < 8) {
                    for (a = g->head; a != NULL; a = a->next) {
                        if (j == i) {
                            break;
                        }
                        j++;
                    }
                }
                r = a;
                if (r != NULL) {
                    if (r->stats->unk94 != 0) {
                        total++;
                        if (r->unk5E4 == 0) {
                            dead++;
                        }
                        if (r->stats->unk80 == 0xE) {
                            flag = 1;
                        }
                    }
                }
                i++;
            } while ((s32)i < 8);
            if (dead == total) {
                if (flag != 0) {
                    if (D_801468A0->unk9C >= 3) {
                        D_801468A0->unkA8 = 1;
                        goto call;
                    }
                } else {
                    D_80146948 = 1;
call:
                    func_0022A738(g);
                }
            }
        }
    }
}
