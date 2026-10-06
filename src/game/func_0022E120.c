#include "b07_types.h"

extern u8 D_8011FE88[];

void *func_0028B2D4(void *tbl, s32 id);

s32 func_0022E120(Actor *actor)
{
    s32 id = AT(s32, actor, 0x14);

    if (id != 0) {
        void *p = func_0028B2D4(D_8011FE88, id);

        if (p != NULL) {
            if (AT(u16, p, 0x52) & 0x40) {
                return 1;
            }
        }
    }
    return 0;
}
