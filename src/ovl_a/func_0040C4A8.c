#include "o02_types.h"
extern s32 D_800E28D8;
extern s32 D_800E28DC;
extern s32 D_800E28E0;
extern s32 D_800E28E4;
void func_0040C4A8(s32 mode) {
    if (D_800E28E0 == 0 && mode != D_800E28D8) {
        D_800E28E4 = 1;
        D_800E28DC = D_800E28D8;
        D_800E28D8 = mode;
        D_800E28E0 = 20;
    }
}
