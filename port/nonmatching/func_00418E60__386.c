#include "o03_types.h"
extern s32 D_800E32E0;
extern s32 D_80153F60;
void func_004170B4(s32 a);
void func_00416D74(s32 a);
void func_00416F4C(s32 a);
void func_00415D10(f32 a, f32 b, f32 d, s32 e, s32 f, s32 g, s32 h, s32 i);
void func_00418E60(f32 a, f32 b, s32 c, f32 d, s32 e, s32 f, s32 g, s32 h, s32 i) {
    D_800E32E0 = 0;
    D_800E32E4 = 0;
    func_004170B4(0xC);
    func_00416D74(5);
    O3_SetModeA(7);
    O3_SetModeB(0xE);
    if (D_80153F60 == 0) {
        func_00416F4C(9);
        func_00415D10(a, b, d, e, f, g, h, i);
    }
}
