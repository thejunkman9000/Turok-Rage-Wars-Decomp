#include "common.h"

s32 func_002023C4(void);
void func_002023D0(s32 mask);

s32 func_00200500(void) {
    s32 mask = func_002023C4();
    func_002023D0(mask & ~1);
    return mask & 1;
}
