#include "b20_types.h"
s32 *func_0028FD94(s32 *tbl, s32 idx);
s32 func_0028BC98(Level *lv, s32 key) {
    s32 *t = lv->unkB0;
    s32 n = t[1];
    s32 *ents = t + 2;
    s32 i;
    for (i = 0; i < n; i++) {
        if (ents[i] == key) {
            s32 *u = func_0028FD94(lv->unk80, 1);
            func_0028FD94(u, 0);
            return *((u8 *)func_0028FD94(u, 1) + i);
        }
    }
    return -1;
}
