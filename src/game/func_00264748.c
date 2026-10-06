#include "b14_types.h"
extern u8 D_8010F308[];
s32 func_00264748(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (D_8010F308[i] != 0) {
            return 1;
        }
    }
    return 0;
}
