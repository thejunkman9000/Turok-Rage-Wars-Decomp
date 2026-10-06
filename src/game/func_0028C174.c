#include "b20_types.h"

s32 func_0028FE08(s32 *tbl, s32 *arg, s32 idx);

s32 func_0028C174(Level *lv, s32 idx) {
    s32 *tbl = lv->unk54;
    if (idx < tbl[0]) {
        return func_0028FE08(tbl, lv->unk24, idx);
    }
    return 0;
}
