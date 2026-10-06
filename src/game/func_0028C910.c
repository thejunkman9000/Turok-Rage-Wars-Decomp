#include "b20_types.h"
void func_0024B8B4(Entity *e);
s32 func_0024D150(Entity *e);
s32 func_0024E1A4(Entity *e);
void func_0028C910(Level *lv, Entity *e) {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 f;
    s32 g;
    s32 h;
    s32 i;
    s32 j;
    func_0024B8B4(e);
    if (func_0024D150(e) != 0) {
        a = lv->cnt944;
        if (a != 0x200) {
            lv->arr144[a] = e;
            lv->cnt944 = a + 1;
        }
    }
    if (func_0024E1A4(e) != 0) {
        b = lv->cntB48;
        if (b != 0x80) {
            lv->arr948[b] = e;
            lv->cntB48 = b + 1;
        }
    }
    c = lv->numActors;
    if (c < 0x80) {
        lv->actors[c] = (Actor *)e;
        lv->numActors = c + 1;
    }
    d = lv->cntF54;
    if (d < 0x40 && e->def->type == 1) {
        lv->list4[d] = (u8 *)e;
        j = lv->cntF54;
        e->unk23E = j;
        lv->cntF54 = j + 1;
    }
    f = lv->cntFDC;
    if (f < 0x20 && (e->flags & 2)) {
        lv->arrF5C[f] = e;
        lv->cntFDC = f + 1;
    }
    g = lv->cnt1020;
    if (g < 0x10 && e->def->type == 5) {
        lv->arrFE0[g] = e;
        lv->cnt1020 = g + 1;
    }
    h = lv->cnt10A4;
    if (h < 0x20) {
        if (e->unkE4 == 0x64F) {
            lv->list3[h] = e;
            lv->cnt10A4 = h + 1;
        }
    }
    if (e->unkE4 == 0x64D) {
        i = lv->cnt10B8;
        if (i < 4) {
            lv->arr10A8[i] = e;
            lv->cnt10B8 = i + 1;
        }
    }
}
