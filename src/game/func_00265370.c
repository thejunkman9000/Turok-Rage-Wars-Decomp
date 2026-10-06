#include "b14_types.h"
extern u32 D_80000318;
u32 func_00265370(void) {
    if (D_80000318 > 0x7FFFFF) {
        return 0x700000;
    }
    return D_80000318;
}
