#include "dbglink_types.h"

s32 dbgPortWaitDataReadyFast(s32 v) {
    return dbgPortWaitRegMask_i(&D_B2000015, 1, v, 1);
}
