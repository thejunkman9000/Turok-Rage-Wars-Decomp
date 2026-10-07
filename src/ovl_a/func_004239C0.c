#include "o04_types.h"
extern void *D_800E4518;
void func_00254784(void *p);
void func_002A3358(void);
void func_00245B18(void);
s32 func_004239C0(void) {
    func_00254784(D_800E4518);
    func_002A3358();
    D_800E4518 = 0;
    func_00245B18();
    return 0;
}
