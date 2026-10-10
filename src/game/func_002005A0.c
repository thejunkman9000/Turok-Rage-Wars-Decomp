#include "b01_types.h"

u32 func_002005A0(u32 *addr) {
    while (IO_READ(PI_STATUS_REG) & 3) {
    }
    return *addr;
}
