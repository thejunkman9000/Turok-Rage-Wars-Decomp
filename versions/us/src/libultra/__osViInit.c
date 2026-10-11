#include "common.h"

void __osViInit(void) {
    memset(__osViContexts, 0, 2 * sizeof(OSViContext));

    __osViNext = &__osViContexts[1];
    __osViNext->retraceCount = 1;
    __osViContexts[0].retraceCount = 1;
    __osViCurr = &__osViContexts[0];
    __osViNext->buffer = (void *)0x80000000;
    __osViContexts[0].buffer = (void *)0x80000000;

    if (OS_TV_TYPE == 0) {
        __osViNext->modep = &osViModePalLan1;
    } else if (OS_TV_TYPE == 2) {
        __osViNext->modep = &osViModeMpalLan1;
    } else {
        __osViNext->modep = &osViModeNtscLan1;
    }

    __osViNext->state = 0x20;
    __osViNext->features = __osViNext->modep->comRegs.ctrl;

    while (IO_READ(VI_V_CURRENT_LINE_REG) >= 11) {
    }

    IO_WRITE(VI_CONTROL_REG, 0);
    __osViSwapContext();
}
