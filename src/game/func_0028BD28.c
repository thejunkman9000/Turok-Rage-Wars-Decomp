#include "b20_types.h"

s32 *func_0028FD94(s32 *tbl, s32 idx);

void func_0028BD28(Level *lv, s32 idx) {
    s32 *t = func_0028FD94(lv->unk80, 1);
    u8 *p;
    func_0028FD94(t, 0);
    p = (u8 *)func_0028FD94(t, 1) + idx;
    *p -= 1;
}
