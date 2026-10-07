#include "b06_types.h"

void func_002A125C(PlrRec21 *r);
void func_00239760(u8 *a, Pawn *p, PlrRec21 *r, f32 x);
extern u8 D_80145088[];

void func_0022B74C(Plr *a, s32 unused, f32 x) {
    a->unk13B0 = a->unk13B0 + 1;
    if (a->unk13B0 == 5) {
        a->unk13B0 = 0;
    }
    func_002A125C(&a->rec[a->unk13B0]);
    if (a->unk5DC != NULL) {
        func_00239760(D_80145088, a->unk5DC, &a->rec[a->unk13B0], x);
    }
}
