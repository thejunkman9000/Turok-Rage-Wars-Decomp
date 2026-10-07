#include "o05_types.h"

extern void *D_800E5558;
void func_00254784(void *p);
void func_002A33BC(s32 a);

s32 func_00436430(void) {
    func_00254784(D_800E5558);
    D_800E5558 = 0;
    func_002A33BC(2);
    return 0;
}
