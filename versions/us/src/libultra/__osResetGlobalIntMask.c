#include "common.h"

void __osResetGlobalIntMask(u32 mask) {
    u32 saveMask = __osDisableInt();

    __OSGlobalIntMask &= ~(mask & ~0x401);
    __osRestoreInt(saveMask);
}
