#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;

void func_002C1F10(u8 *arg0) {
    s32 temp_s1;
    u8 *temp_v0;
    u8 *temp_v0_2;
    u8 *var_a0;
    u8 *var_s0;

    var_s0 = arg0;
    temp_s1 = __osDisableInt();
    if (var_s0 == NULL) {
        var_s0 = *(u8 **)0x800D92A0;
    } else if (M2C_FIELD(var_s0, u16 *, 0x10) != 1) {
        __osDequeueThread(M2C_FIELD(var_s0, s32 *, 8), var_s0);
    }
    temp_v0 = *(u8 **)0x800D929C;
    var_a0 = temp_v0;
    if (temp_v0 == var_s0) {
        *(u8 **)0x800D929C = M2C_FIELD(var_s0, u8 **, 0xC);
    } else if (M2C_FIELD(var_a0, s32 *, 4) != -1) {
loop_8:
        temp_v0_2 = M2C_FIELD(var_a0, u8 **, 0xC);
        if (temp_v0_2 != var_s0) {
            var_a0 = temp_v0_2;
            if (M2C_FIELD(var_a0, s32 *, 4) != -1) {
                goto loop_8;
            }
        } else {
            M2C_FIELD(var_a0, u8 **, 0xC) = (u8 *) M2C_FIELD(var_s0, u8 **, 0xC);
        }
    }
    if (var_s0 == *(s32 *)0x800D92A0) {
        __osDispatchThread(var_a0);
    }
    __osRestoreInt(temp_s1);
}
