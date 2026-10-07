#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;

s32 func_002C0250(u8 *arg0, s32 arg1, s32 arg2) {
    s32 temp_hi;
    s32 temp_s1;
    s32 temp_v1;

    temp_s1 = __osDisableInt();
    if (M2C_FIELD(arg0, s32 *, 8) >= M2C_FIELD(arg0, s32 *, 0x10)) {
loop_2:
        if (arg2 != 1) {
            __osRestoreInt(temp_s1);
            return -1;
        }
        M2C_FIELD(*(u8 **)0x800D92A0, s16 *, 0x10) = 8;
        __osEnqueueAndYield(arg0 + 4);
        if (M2C_FIELD(arg0, s32 *, 8) < M2C_FIELD(arg0, s32 *, 0x10)) {
            goto block_5;
        }
        goto loop_2;
    }
block_5:
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x10);
    temp_hi = (s32) ((M2C_FIELD(arg0, s32 *, 0xC) + temp_v1) - 1) % temp_v1;
    M2C_FIELD(arg0, s32 *, 0xC) = temp_hi;
    *((temp_hi * 4) + M2C_FIELD(arg0, s32 *, 0x14)) = arg1;
    M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) + 1);
    if (*M2C_FIELD(arg0, s32 **, 0) != 0) {
        osStartThread(__osPopThread(arg0));
    }
    __osRestoreInt(temp_s1);
    return 0;
}
