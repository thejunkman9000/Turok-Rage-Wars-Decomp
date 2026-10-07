#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;

u32 func_002C0B9C(M2C_UNK *arg0) {
    M2C_UNK **temp_v1;
    M2C_UNK *var_a2;
    s32 temp_a1;
    s32 temp_a3;
    u32 temp_v0;
    u32 temp_v1_2;
    u32 temp_v1_3;
    u32 temp_v1_4;
    u32 var_s0;
    u32 var_s1;

    temp_v1 = *(u8 ***)0x800D92B0;
    var_a2 = *temp_v1;
    var_s0 = M2C_FIELD(arg0, u32 *, 0x10);
    var_s1 = M2C_FIELD(arg0, u32 *, 0x14);
    temp_a3 = __osDisableInt();
    if (var_a2 != temp_v1) {
loop_3:
        temp_v1_2 = M2C_FIELD(var_a2, u32 *, 0x10);
        if ((temp_v1_2 < var_s0) || ((var_s0 == temp_v1_2) && ((u32) M2C_FIELD(var_a2, u32 *, 0x14) < var_s1))) {
            temp_v0 = M2C_FIELD(var_a2, u32 *, 0x10);
            temp_v1_3 = M2C_FIELD(var_a2, u32 *, 0x14);
            var_a2 = M2C_FIELD(var_a2, u8 **, 0);
            temp_a1 = var_s1 < temp_v1_3;
            var_s1 -= temp_v1_3;
            var_s0 = (var_s0 - temp_v0) - temp_a1;
            if (var_a2 != *(s32 *)0x800D92B0) {
                goto loop_3;
            }
        }
    }
    M2C_FIELD(arg0, u32 *, 0x10) = var_s0;
    M2C_FIELD(arg0, u32 *, 0x14) = var_s1;
    if (var_a2 != *(s32 *)0x800D92B0) {
        temp_v1_4 = M2C_FIELD(var_a2, u32 *, 0x14);
        M2C_FIELD(var_a2, s32 *, 0x10) = (s32) ((M2C_FIELD(var_a2, s32 *, 0x10) - var_s0) - (temp_v1_4 < var_s1));
        M2C_FIELD(var_a2, u32 *, 0x14) = (u32) (temp_v1_4 - var_s1);
    }
    M2C_FIELD(arg0, M2C_UNK **, 0) = var_a2;
    M2C_FIELD(arg0, M2C_UNK **, 4) = (M2C_UNK *) M2C_FIELD(var_a2, M2C_UNK **, 4);
    *M2C_FIELD(var_a2, M2C_UNK **, 4) = arg0;
    M2C_FIELD(var_a2, M2C_UNK **, 4) = arg0;
    __osRestoreInt(temp_a3);
    return var_s0;
}
