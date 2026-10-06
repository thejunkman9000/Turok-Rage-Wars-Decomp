#include "b20_types.h"
s32 func_0028B1F8(Level *lv, s32 id) {
    s32 *t = (s32 *)lv->unk94;
    s32 n = t[1];
    u16 *p = (u16 *)(t + 2);
    s32 i = 0;
    if (n > 0) {
        do {
            if (*p == (u16)id) {
                return i;
            }
            i++;
            p++;
        } while (i < n);
    }
    return -1;
}
