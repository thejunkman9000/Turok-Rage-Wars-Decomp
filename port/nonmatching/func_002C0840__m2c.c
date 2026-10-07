#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;

void func_002C0840(u8 *arg0) {
    s32 temp_s2;
    s32 temp_v0;
    u16 temp_v1;
    u8 *temp_a1;
    u8 *var_a1;

    temp_s2 = __osDisableInt();
    temp_v1 = M2C_FIELD(arg0, u16 *, 0x10);
    if (temp_v1 != 1) {
        if (temp_v1 == 8) {
            M2C_FIELD(arg0, u16 *, 0x10) = 2U;
            var_a1 = arg0;
            goto block_7;
        }
    } else {
        temp_v0 = M2C_FIELD(arg0, s32 *, 8);
        if ((temp_v0 == 0) || (temp_v0 == 0x800D9298)) {
            M2C_FIELD(arg0, u16 *, 0x10) = 2U;
            var_a1 = arg0;
        } else {
            M2C_FIELD(arg0, u16 *, 0x10) = 8U;
            __osEnqueueThread(M2C_FIELD(arg0, s32 *, 8), arg0);
            var_a1 = __osPopThread(M2C_FIELD(arg0, s32 *, 8));
        }
block_7:
        __osEnqueueThread(0x800D9298, var_a1);
    }
    temp_a1 = *(u8 **)0x800D92A0;
    if (temp_a1 == NULL) {
        __osDispatchThread();
    } else if (M2C_FIELD(temp_a1, s32 *, 4) < M2C_FIELD(*(u8 **)0x800D9298, s32 *, 4)) {
        M2C_FIELD(temp_a1, s16 *, 0x10) = 2;
        __osEnqueueAndYield(0x800D9298, temp_a1);
    }
    __osRestoreInt(temp_s2);
}
