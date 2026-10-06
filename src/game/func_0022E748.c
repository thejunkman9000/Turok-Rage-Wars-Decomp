#include "b07_types.h"

extern u8 D_801462E5[];

s32 func_0022E748(s32 a0, s32 id)
{
    if (id == 0x2DA && D_801462E5[0] != 0) {
        return D_801462E5[0xE];
    }
    return 1;
}
