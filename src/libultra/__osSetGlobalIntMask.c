#include "common.h"

void __osSetGlobalIntMask(u32 mask) {
    u32 saveMask = __osDisableInt();

    __OSGlobalIntMask |= mask;
    __osRestoreInt(saveMask);
}
