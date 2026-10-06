#include "b20_types.h"
u8 *func_0028FD94(s32 *tbl, s32 idx);
u8 *func_0028B2D4(Level *lv, u16 *idx) {
    u8 *base;
    if (idx == 0) {
        return 0;
    }
    base = func_0028FD94(lv->unk6C, 0) + 8;
    return base + *idx * 100;
}
