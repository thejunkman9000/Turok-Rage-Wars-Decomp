#include "b20_types.h"

u8 *func_0028FD94(s32 *tbl, s32 idx);

u8 *func_0028B370(Level *lv, s32 idx) {
    s32 *tbl = (s32 *)func_0028FD94(lv->unk6C, 2);
    u8 *ents = (u8 *)tbl + 8;
    if (idx < 0 || idx >= tbl[1]) {
        return 0;
    }
    return ents + (idx << 5);
}
