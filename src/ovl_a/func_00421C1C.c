#include "o03_types.h"
typedef struct O3Pn { O3B60 *bar; O3A *fx; O3Spr *w8; s32 fC; s32 f10; } O3Pn;
extern O3Pn *D_800E4450;
extern s32 D_800E28E0;
void func_002A338C();
void func_002A3358();
s32 func_0041A4F0(O3B60 *o);
void func_0029A73C();
void func_00299368(s32 a);
s32 func_00421C1C(void) {
    s32 st;
    s32 t;
    s32 a;
    O3Spr *sp;
    if (D_800E28E0 >= 2) {
        func_002A338C();
        return 0;
    }
    func_002A3358();
    st = func_0041A4F0(D_800E4450->bar);
    switch (st) {
    case 3:
        t = D_800E4450->fC - 1;
        D_800E4450->fC = t;
        if (t <= 0) {
            D_800E4450->w8->f16 = D_800E4450->w8->f16 - 1;
            sp = D_800E4450->w8;
            if (sp->f16 + sp->f1A < 0) {
                sp->f16 = *(s16 *)((u8 *)D_800E4450->bar->g + 0x1A);
            }
            D_800E4450->fC = st;
        }
        return 0;
    case 4:
        func_0029A73C();
        a = D_800E4450->f10;
        if (a == -1) {
            a = 3;
        }
        func_00299368(a);
        return 0;
    default:
        return 0;
    }
}
