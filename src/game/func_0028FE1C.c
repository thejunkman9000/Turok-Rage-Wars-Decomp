#include "common.h"

static inline s32 off(s32 *t, s32 i) { s32 *p = t + i; return p[1]; }

void *func_0028FE1C(s32 *tbl, u8 *base, s32 idx, s32 *size) {
    *size = off(tbl, idx + 1) - off(tbl, idx);
    return base + off(tbl, idx);
}
