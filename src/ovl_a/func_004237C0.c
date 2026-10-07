#include "o04_types.h"
extern O04ModeS4514 *D_800E4514;
void func_00254784(void *p);
void func_002A3358(void);
s32 func_004237C0(void) {
    func_00254784(D_800E4514);
    func_002A3358();
    D_800E4514 = 0;
    return 0;
}
