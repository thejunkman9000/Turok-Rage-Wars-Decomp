#include "b20_types.h"

s32 *func_0028FD94(s32 *tbl, s32 idx);

s32 func_0028E6D8(Level *lv) {
    s32 i;
    for (i = 0; i < lv->cnt1504; i++) {
        s32 *t = func_0028FD94(*lv->ents[i].tblp, 2);
        if (t[1] != 0) {
            return 1;
        }
    }
    return 0;
}
