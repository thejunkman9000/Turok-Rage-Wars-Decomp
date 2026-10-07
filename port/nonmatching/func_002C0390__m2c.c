#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;

s32 func_002C0390(u8 *arg0, s32 *arg1, s32 arg2) {
    s32 temp_s1;

    temp_s1 = __osDisableInt();
    if (M2C_FIELD(arg0, s32 *, 8) == 0) {
loop_2:
        if (arg2 == 0) {
            __osRestoreInt(temp_s1);
            return -1;
        }
        M2C_FIELD(*(u8 **)0x800D92A0, s16 *, 0x10) = 8;
        __osEnqueueAndYield(arg0);
        if (M2C_FIELD(arg0, s32 *, 8) != 0) {
            goto block_5;
        }
        goto loop_2;
    }
block_5:
    if (arg1 != NULL) {
        *arg1 = *((M2C_FIELD(arg0, s32 *, 0xC) * 4) + M2C_FIELD(arg0, s32 *, 0x14));
    }
    M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) - 1);
    M2C_FIELD(arg0, s32 *, 0xC) = (s32) ((s32) (M2C_FIELD(arg0, s32 *, 0xC) + 1) % (s32) M2C_FIELD(arg0, s32 *, 0x10));
    if (*M2C_FIELD(arg0, s32 **, 4) != 0) {
        osStartThread(__osPopThread(arg0 + 4));
    }
    __osRestoreInt(temp_s1);
    return 0;
}
