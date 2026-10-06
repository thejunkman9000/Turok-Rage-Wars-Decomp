#include "dbglink_types.h"

void dbgLinkSetCallHook(s32 (*fn)(u32)) {
    D_800D364C = fn;
}
