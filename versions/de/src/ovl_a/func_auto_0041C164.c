#include "common.h"

extern s32 D_auto_80146CE0;
extern void func_002A338C(void);
extern void func_0029A73C(void);
extern void func_00299368(s32);

s32 func_auto_0041C164(void) {
    func_002A338C();
    func_0029A73C();
    func_00299368(2);
    D_auto_80146CE0 = 1;
    return 1;
}
