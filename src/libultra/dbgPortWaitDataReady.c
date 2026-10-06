#include "dbglink_types.h"

s32 dbgPortWaitDataReady(s32 v) {
    return dbgPortWaitRegMask_i(&D_B2000015, 1, v, 0x4E20);
}
