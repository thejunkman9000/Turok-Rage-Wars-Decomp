#include "o01_types.h"

extern s32 D_800E28B0;
extern s32 D_800E28B4;
extern s32 D_800E28B8;
extern s32 D_800E28BC;
void func_002538A8(s32 a);
void func_002537D8(s32 a, s32 b);

void func_00409990(void) {
    if (D_800E28B0 != 0 || D_800E28B4 != 0) {
        func_002538A8(0);
    }
    if (D_800E28B0 != 0) {
        func_002537D8(0, D_800E28B0);
    }
    if (D_800E28B4 != 0) {
        func_002537D8(0, D_800E28B4);
    }
    D_800E28B0 = 0;
    D_800E28B4 = 0;
    D_800E28B8 = 0;
    D_800E28BC = 0;
}
