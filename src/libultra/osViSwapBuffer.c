#include "common.h"

void osViSwapBuffer(void *vaddr) {
    u32 saveMask = __osDisableInt();

    __osViNext->buffer = vaddr;
    __osViNext->state |= 0x10;

    __osRestoreInt(saveMask);
}
