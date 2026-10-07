#include "o04_types.h"
extern O04ModeS4600 *D_800E4600;
extern s32 D_800E28E0;
void func_002A338C(void);
void func_002A3358(void);
void func_0041A4FC(s32 a);
s32 func_0041A4F0(s32 a);
void func_0029A73C(void);
void func_00299368(s32 a);
s32 func_0042439C(void) {
    s32 r;
    if (D_800E28E0 >= 2) {
        func_002A338C();
        return 0;
    }
    func_002A3358();
    if (D_800E4600->unkC > 0) {
        D_800E4600->unkC = D_800E4600->unkC - 1;
        if (D_800E4600->unkC == 0) {
            func_0041A4FC(D_800E4600->unk0);
            return 0;
        }
        return 0;
    }
    r = func_0041A4F0(D_800E4600->unk0);
    switch (r) {
    case 3:
        D_800E4600->unk14 = D_800E4600->unk14 - 1;
        if (D_800E4600->unk14 <= 0) {
            D_800E4600->unk8->unk16 = D_800E4600->unk8->unk16 - 1;
            if ((s16)D_800E4600->unk8->unk16 + D_800E4600->unk8->unk1A < 0) {
                D_800E4600->unk8->unk16 = ((O04Obj44 *)D_800E4600->unk0)->unk44->unk1A;
            }
            D_800E4600->unk14 = 3;
        }
        break;
    case 4:
        func_0029A73C();
        func_00299368(D_800E4600->unk18);
        break;
    }
    return 0;
}
