#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;

void func_002C0D10(void) {
    s32 temp_s0;

    temp_s0 = __osDisableInt();
    M2C_FIELD(*(u8 **)0x800D92A0, s16 *, 0x10) = 2;
    __osEnqueueAndYield(0x800D9298, 2);
    __osRestoreInt(temp_s0);
}
