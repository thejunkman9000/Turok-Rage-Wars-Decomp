#include "common.h"

s32 __osSpSetPc(u32 pc) {
    if (!(IO_READ(SP_STATUS_REG) & SP_STATUS_HALT)) {
        return -1;
    }

    IO_WRITE(SP_PC_REG, pc);
    return 0;
}
