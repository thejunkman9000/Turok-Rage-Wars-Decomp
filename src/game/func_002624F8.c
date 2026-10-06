#include "b14_types.h"
s32 func_00253294(s32 a);
s32 func_002624F8(s32 *p) {
    s32 v = p[4];
    if (v == 0) {
        return 0;
    }
    return func_00253294(v) != 0;
}
