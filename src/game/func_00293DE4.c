#include "b21_types.h"

extern s32 D_800E28C8;
extern s32 D_80146D70;
extern s32 D_800D29C4;
extern s32 D_80146D60;
extern s32 D_800E28CC;
extern s32 D_8014AD94;
extern f32 D_800CA5AC;
void func_40C4A8(s32 a);
void func_00299368(s32 a);

void func_00293DE4(B21Game *g) {
    D_800E28C8 = -1;
    D_80146D70 = 0;
    func_40C4A8(0);
    D_800D29C4 = 1;
    D_80146D60 = 1;
    D_800E28CC = 1;
    D_8014AD94 = 0;
    g->unk26DC4 = D_800CA5AC;
    func_00299368(29);
}
