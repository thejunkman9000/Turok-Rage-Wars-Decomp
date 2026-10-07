#include "b01_types.h"

s32 func_002023C4(void);
void func_002023D0(s32 mask);

void func_00200538(s32 mask) {
    func_002023D0(func_002023C4() | mask);
}
