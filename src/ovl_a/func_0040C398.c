#include "o02_types.h"
extern s32 D_800E28D8;
extern u8 D_800E28DB;
extern s32 D_800E28DC;
extern s32 D_800E28E0;
extern u8 D_80146848;
s32 func_00265370(void);
void func_0040BC30(void);
void func_0040C398(void) {
    if (D_800E28D8 == -1) {
        if (func_00265370() != 0x400000) {
            D_800E28D8 = 1;
        } else {
            D_800E28D8 = 0;
        }
        D_80146848 = D_800E28DB;
    }
    if (D_800E28E0 < 5 && D_800E28DC != D_800E28D8) {
        func_0040BC30();
        D_800E28DC = D_800E28D8;
    }
}
