#include "common.h"

void osSpTaskStartGo(UNUSED OSTask *task) {
    while (__osSpDeviceBusy())
        ;

    __osSpSetStatus(SPSTATUS_SET_INTR_ON_BREAK | SPSTATUS_CLEAR_SSTEP |
                    SPSTATUS_CLEAR_BROKE | SPSTATUS_CLEAR_HALT);
}
