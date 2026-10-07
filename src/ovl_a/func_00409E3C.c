#include "o01_types.h"

extern s32 D_80146D60;
extern u8 D_8011FAC0[];
extern s32 D_8014AD9C;
extern s32 D_8014ADA0;
extern s32 D_8014AD94;
extern s32 D_80153784;
extern s32 D_800E28C8;
void func_0029324C(u8 *p);
void func_00263C44(void);
s32 func_002645F0(s32 pad);
s32 func_00406178(void *o, s32 pad, s32 z);

s32 func_00409E3C(void *a) {
    if (D_80146D60 == 0) {
        func_0029324C(D_8011FAC0);
        func_00263C44();
        if (D_80146D60 == 0) {
            if (D_8014AD9C != 0) {
                D_8014ADA0 = 1;
            }
            D_8014AD94 = 0;
            D_80153784 = 1;
        }
    }
    if (D_80153784 == 0) {
        if (D_800E28C8 != -1) {
            if (func_002645F0(D_800E28C8) != 0) {
                if (func_00406178(a, D_800E28C8, 0) != 0) {
                    D_8014AD94 = 0;
                    D_80153784 = 1;
                }
            }
        }
    }
    return D_80153784;
}
