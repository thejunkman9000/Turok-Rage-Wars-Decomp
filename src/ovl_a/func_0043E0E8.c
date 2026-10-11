#include "s1009_types.h"
extern S10Ctrl D_8010F328[];
extern s32 func_0026439C(void *p);
S10Ctrl *func_0043E0E8(s32 *out) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (func_0026439C(&D_8010F328[i]) != 0) {
            *out = i;
            return &D_8010F328[i];
        }
    }
    *out = -1;
    return 0;
}
