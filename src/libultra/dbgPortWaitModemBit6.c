#include "dbglink_types.h"

s32 dbgPortWaitModemBit6(s32 v) {
    return dbgPortWaitRegMask_i(&D_B2000011, 0x40, v << 6, 0x4E20);
}
