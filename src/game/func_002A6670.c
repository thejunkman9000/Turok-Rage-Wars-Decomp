#include "b23_types.h"

extern s32 D_800D2E58;
extern s32 D_80146894;

void func_002A6DF8();
void func_002A6ED0(s32 a);

void func_002A6670(s32 a) {
    D_800D2E58 = 0;
    if (D_80146894 == 0) {
        func_002A6DF8();
        func_002A6ED0(a);
    }
}
