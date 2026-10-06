#include "common.h"

static inline s32 off(s32 *t, s32 i) { s32 *p = t + i; return p[1]; }

void *func_0028FDA8(s32 *tbl, s32 idx, s32 *size) {
    *size = off(tbl, idx + 1) - off(tbl, idx);
    return (u8 *)tbl + off(tbl, idx);
}
