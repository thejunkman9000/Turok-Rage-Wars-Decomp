#include "dbglink_types.h"

s32 dbgPortWaitTxEmpty(s32 v) {
    return dbgPortWaitRegMask_i(&D_B2000015, 0x40, v << 6, 0x4E20);
}
