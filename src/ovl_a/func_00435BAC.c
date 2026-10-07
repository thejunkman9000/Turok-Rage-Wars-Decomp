#include "o05_types.h"

extern void *D_800E54A4;
void func_00254784(void *p);
void func_002A3358(void);
void func_002A3410(s32 a);

s32 func_00435BAC(void) {
    func_00254784(D_800E54A4);
    D_800E54A4 = 0;
    func_002A3358();
    func_002A3410(1);
    return 0;
}
