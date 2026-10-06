#include "b10_types.h"

s32 func_00245774(void);
s32 func_0024575C(void);

s32 func_00245804(void) {
    s32 r = 0;
    if (func_00245774() == 0) {
        r = func_0024575C() == 0;
    }
    return r;
}
