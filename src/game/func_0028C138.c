#include "b20_types.h"

void *func_0028FE1C(s32 *tbl, u8 *base, s32 idx, s32 *size);

void func_0028C138(Level *lv, s32 idx, void **out, s32 *size) {
    *out = func_0028FE1C(lv->unk50, lv->unk20, idx, size);
}
