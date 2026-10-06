#include "b20_types.h"

s32 *func_0028FD94(s32 *tbl, s32 idx);

s32 func_0028BD88(Level *lv, s32 idx) {
    s32 *t = func_0028FD94(lv->unk80, 1);
    func_0028FD94(t, 0);
    return *((u8 *)func_0028FD94(t, 1) + idx) == 0;
}
