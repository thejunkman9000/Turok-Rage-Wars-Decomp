#include "o04_types.h"
extern O04Ent1C D_800E4694[];
s32 func_00428300(s32 a) {
    s32 i;
    for (i = 0; i < 0x24; i++) {
        if (D_800E4694[i].id == a) {
            return i;
        }
    }
    return 0;
}
