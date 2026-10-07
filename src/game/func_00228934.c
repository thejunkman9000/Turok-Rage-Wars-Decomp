#include "b06_types.h"

void func_0022F760(u8 *a, u8 *b);
void func_00229CFC(Plr *a);
Plr *func_002392DC(Pawn *p);
void func_0026D980();
void func_0026D9D0();
void func_0026DF30(s32 a, u8 *b, u8 *c, s32 d, s32 e);
s32 func_0028B1F8(u8 *a, s32 b);
s32 func_0028C174(u8 *a, s32 b);
extern u8 D_800D0EF8[];
extern u8 D_8011FE88[];
extern GameB6 D_801468A0[];

void func_00228934(PlrGroup *g, Pawn *p) {
    Plr *a;
    s32 want = -1;
    s32 r;
    s32 b;
    if (D_801468A0->unk24 != 0 || D_801468A0->unk78 != 0) {
        want = func_002392DC(p)->stats->unk92;
    }
    func_0026D980();
    for (a = g->head; a != NULL; a = a->next) {
        b = 0;
        if (a->unk11FC > 0.0f) {
            b = 1;
        }
        if (b) {
            if (a->unk120C != 0) {
                r = func_0028B1F8(D_8011FE88, 0xC84);
            } else {
                r = func_0028B1F8(D_8011FE88, 0xC85);
            }
            if (r != -1) {
                func_0026DF30(func_0028C174(D_8011FE88, r), (u8 *)a + 0x1600, D_800D0EF8, 0, -1);
            }
        }
        if (a->unk5DC != NULL && a->unk1210 != 0 && a->unk5DC == p) {
            func_0022F760((u8 *)a + 0x2E8, (u8 *)a + 0x458);
        }
        if ((D_801468A0->unk24 != 0 || D_801468A0->unk78 != 0) && a->stats->unk92 == want && func_002392DC(p) != a) {
            func_00229CFC(a);
        }
    }
    func_0026D9D0();
}
