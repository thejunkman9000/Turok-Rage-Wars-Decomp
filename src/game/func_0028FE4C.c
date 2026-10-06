#include "common.h"

static inline s32 off(s32 *t, s32 i) { s32 *p = t + i; return p[1]; }

s32 func_0028FE4C(s32 *tbl, s32 idx, s32 *size) {
    *size = off(tbl, idx + 1) - off(tbl, idx);
    return off(tbl, idx);
}
