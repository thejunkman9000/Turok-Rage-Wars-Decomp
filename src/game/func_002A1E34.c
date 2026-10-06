#include "b23_types.h"

extern s32 D_800D2B80;
extern s32 D_800D2BB0;
extern s32 D_800D2BBC;
extern s32 D_800D2BC0;

void func_00254784(s32 a);

void func_002A1E34(void) {
    D_800D2B80 = D_800D2B80 - 1;
    if (D_800D2BB0 != 0) {
        func_00254784(D_800D2BB0);
    }
    D_800D2BB0 = 0;
    D_800D2BBC = 0;
    D_800D2BC0 = 0;
}
