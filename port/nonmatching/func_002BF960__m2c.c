#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;

void func_002BF960(f32 arg0) {
    s32 temp_v0;
    u8 *temp_a0;

    temp_v0 = __osDisableInt();
    temp_a0 = *(u8 **)0x800D8444;
    M2C_FIELD(temp_a0, f32 *, 0x24) = arg0;
    M2C_FIELD(temp_a0, u16 *, 0) = (u16) (M2C_FIELD(temp_a0, u16 *, 0) | 4);
    __osRestoreInt(temp_v0);
}
