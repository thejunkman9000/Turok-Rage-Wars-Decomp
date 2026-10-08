#include "common.h"

static inline s32 off(s32 *t, s32 i) { s32 *p = t + i; return p[1]; }

/* port: the original leaves the piece size in v0 (the matching C is void): recompiled callers read it */
s32 func_0028FDD8(s32 *tbl, s32 idx) {
    volatile s32 size;
    size = off(tbl, idx + 1) - off(tbl, idx);
    return size;
}
