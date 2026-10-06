#include "common.h"

void func_0028FE7C(s32 *tbl, s32 **out1, s32 *out2) {
    s32 *p;
    *out1 = tbl;
    p = tbl + tbl[0];
    *out2 = p[1];
}
