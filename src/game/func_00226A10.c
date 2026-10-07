#include "b06_types.h"

void func_002631D0(u8 *a, Plr *b);
void func_0022C480(Plr *a);
void func_00220EB0(Plr *a);
void func_00220A5C(Plr *a, Plr *b);
s32 func_00245774();
s32 func_0024575C();
void func_002456FC();
s32 func_0026437C(u8 *p);
s32 func_002A33AC();
s32 func_442B98(u8 *p);
void func_0025E380();
void func_0025E3C8();
void func_00218464(u8 *p);
void func_435CF0();
void func_00228394(PlrGroup *g);
void func_00227014(PlrGroup *g);
void func_00227E68(PlrGroup *g);
extern f32 D_800D2988;
extern Game2B6 D_8014687C[];
extern s32 D_80146894;
extern u8 D_8014561C[];

void func_00226A10(PlrGroup *g) {
    Plr *a;
    f32 save;
    HudSubB6 *h;
    GameB6 *gm;
    if (D_8014687C->mode == 0xB || D_8014687C->mode == 8) {
        return;
    }
    save = D_800D2988;
    g->unk40 = g->unk40 + 5;
    if (g->unk40 >= 0x168) {
        g->unk40 = 0;
    }
    a = g->head;
    gm = &D_8014687C->game;
    for (; a != NULL; a = a->next) {
        func_002631D0(a->unk688, a);
        D_800D2988 = save;
        if (gm->unk24 != 0 || gm->unk78 != 0) {
            func_0022C480(a);
        }
        if (D_80146894 == 0) {
            func_00220EB0(a);
        }
        func_00220A5C(a, a);
    }
    for (a = g->head; a != NULL; a = a->next) {
        if (func_00245774() != 0 && (a->unk6B0 & 0x8000)) {
            goto blk;
        }
        if (func_0026437C(a->unk698) != 0) {
            if (func_00245774() != 0 || func_0024575C() != 0) {
blk:
                func_002456FC();
            } else if (func_002A33AC() == 0 && func_442B98(D_8014561C) == 0 && a->unk5E4 != 0) {
                if (a->unk5DC != NULL && a->unk5DC->unk564 == 0) {
                    h = (HudSubB6 *)(D_8014561C + 0x1284);
                    if (h->unk1C == 0 || D_8014561C[0xCC9] == 0) {
                        *(s32 *)(D_8014561C + 0x1278) = 1;
                        func_0025E380();
                        func_0025E3C8();
                        func_00218464(a->unk938);
                        a->unkF54 = -1;
                        a->unkF90 = -1;
                        func_435CF0();
                    }
                }
            }
        }
    }
    func_00228394(g);
    func_00227014(g);
    func_00227E68(g);
    D_800D2988 = save;
}
