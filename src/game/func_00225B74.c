#include "b06_types.h"

void func_00245608(s32 a, s32 b, void (*c)());
void func_0022ECBC();
RecB6 *func_0028B2D4(u8 *a, s32 b);
PlrCls *func_0028CF7C(u8 *a, s32 b, s32 c);
extern s32 D_800CF228;
extern s32 D_800D2930;
extern Plr *D_801029F0;
extern u8 D_80102AD8[];
extern u8 D_8011FE88[];
extern s32 D_8013B290;
extern s32 D_80145048;

void func_00225B74(Plr *a, s32 unused, s32 ev) {
    s32 ok = 1;
    u32 flags = 0;
    s32 t;
    s32 i;
    RecB6 *r;
    PlrCls *c;
    if (a->unk14 != 0) {
        r = func_0028B2D4(D_8011FE88, a->unk14);
        if (r != NULL) {
            flags = r->unk44;
        }
    }
    if (D_8013B290 != 0) {
        ok = 0;
    }
    t = a->flags664 & 0x8000;
    if (t != 0) {
        ok = 0;
    }
    if (D_8013B290 != 0) {
        ok = 0;
    }
    if (D_80145048 >= 2) {
        ok = 0;
    }
    if (ev == 0xC) {
        ok = 0;
    }
    if (t != 0) {
        ok = 0;
    }
    if (flags & 0x1000000) {
        ok = 0;
    }
    if ((flags & 0x80000) && ev != 0x14 && ev != 0x28 && ev != 0x1E) {
        ok = 0;
    }
    a->unk850 = ok;
    if (ok != 0) {
        if (ev == 0x32) {
            D_800CF228 = 1;
            if (a->unk5DC != NULL) {
                for (i = 0; i < 4; i++) {
                    D_80102AD8[i] = a->unk5DC->unk520[i];
                }
            }
        }
        D_800D2930 = 0;
        D_801029F0 = a;
        func_00245608(ev, 0, func_0022ECBC);
    }
    c = func_0028CF7C(D_8011FE88, -1, 0xC45);
    if (c != NULL) {
        a->unk50 = c->unkFC;
        a->unk54 = c->unk100;
        a->unk58 = c->unk104;
    }
}
