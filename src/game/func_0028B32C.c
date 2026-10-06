#include "b20_types.h"
u8 *func_0028FD94(s32 *tbl, s32 idx);
u32 func_0028B32C(Level *lv, u8 *elem) {
    u8 *base;
    if (elem == 0) {
        return -1;
    }
    base = func_0028FD94(lv->unk6C, 2) + 8;
    return (u32)(elem - base) >> 5;
}
