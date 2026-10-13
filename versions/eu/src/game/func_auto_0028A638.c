#include "b20_types.h"

typedef struct { f32 div; u8 r; u8 g; u8 b; u8 pad7; } Pal;

void func_004037D4(f32 *p);
void func_004030E0(s32 a);
s32 func_0044DE70(Level *lv, s32 a, s32 b, u8 *c, s32 d);
void func_00286A78(Level *lv, s32 a, s32 b);
s32 func_002934DC();
void func_00239760(u8 *a, u8 *b, s32 c, f32 d);
extern Pal D_800D2934[];
extern f32 D_800D2988;
extern s32 D_800E34C4[];
typedef struct { s32 unk0; s32 unk4; } G462;
extern G462 D_801462C8;

void func_auto_0028A638(Level *lv) {
    Pal *p;
    G462 *g;
    f32 t;
    s32 v;
    s32 a1;
    p = &D_800D2934[lv->unk1B410];
    switch (lv->unk1B414) {
    case 1:
        if (lv->unk1B418 == p->div) {
            if (lv->unk1B438 == 0x3E7) {
                func_004037D4(&p->div);
                func_004030E0(0x190);
            }
            if (lv->unk1B410 == 0) {
                lv->unk1B414 = 0;
            } else {
                lv->unk1B414 = 2;
            }
            v = lv->unk1B438;
            if (v < 0) {
                lv->unk1B438 = ~v;
                lv->unk1B41C = 0;
            } else {
                lv->unk1B41C = func_0044DE70(lv, -1, v, lv->unk1B420, 1);
            }
            lv->unk1B434 = lv->unk1B438;
            if (lv->unk1B41C != 0) {
                a1 = lv->unk1B430;
            } else {
                a1 = lv->unk1B438;
            }
            func_00286A78(lv, a1, lv->unk1B41C);
            g = &D_801462C8;
            if (lv->unk1B44C != g->unk4 && func_002934DC() != 0) {
                func_00239760((u8 *)g - 0x1240, (u8 *)g - 0x1200, D_800E34C4[((u8 *)g)[0x581]], 4.0f);
                lv->unk1B44C = g->unk4;
                return;
            }
        } else {
            lv->unk1B418 = lv->unk1B418 + D_800D2988;
            if (p->div < lv->unk1B418) {
                lv->unk1B418 = p->div;
                return;
            }
            return;
        }
        break;
    case 2:
        if (lv->unk1B418 == 0.0f) {
            lv->unk1B414 = 0;
            return;
        }
        t = lv->unk1B418 - D_800D2988;
        lv->unk1B418 = t;
        if (t < 0.0f) {
            lv->unk1B418 = 0.0f;
        }
        break;
    case 0:
        break;
    }
}
