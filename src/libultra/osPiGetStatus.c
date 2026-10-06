#include "common.h"

u32 osPiGetStatus(void) {
    return IO_READ(PI_STATUS_REG);
}
