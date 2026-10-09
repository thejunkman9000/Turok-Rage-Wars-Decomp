/* port (passthru_fix.py): func_002A6DF8 needs a0 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "b23_types.h"

extern s32 D_800D2E58;
extern s32 D_80146894;

void func_002A6DF8();
void func_002A6ED0(s32 a);

void func_002A6670(s32 a) {
    D_800D2E58 = 0;
    if (D_80146894 == 0) {
        func_002A6DF8(a);
        func_002A6ED0(a);
    }
}
