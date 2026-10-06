#include "dbglink_types.h"

s32 dbgPortWaitOverrun(s32 v) {
    return dbgPortWaitRegMask_i(&D_B2000015, 2, v << 1, 0x4E20);
}
