#include "common/types_8fd754e1e915.h"
#include "span_1000/code_802412C0.h"
#include "types.h"

s32 func_8023E178_de(void *, void *, f32, s32, f32, s32, s32 *, s32);
s32 func_8023EA44_de(void *, s32 *, void *, f32, s32);
void func_80240D20_de(s32 *, void *);
void func_80240E00_de(s32 *, void *);

s32 func_80242A94_de(void *arg0, void *arg1, void *arg2, s32 *arg3) {
    f32 temp_f20;
    s32 var_s0;
    void *temp_s3;

    var_s0 = 0;
    temp_s3 = arg1 + 8;
    temp_f20 = ((struct FloatState20 *) ((struct func_80205314_S1 *) arg1)->unk18)->unk_1C + ((struct FloatState68_2 *) arg0)->unk_C;
    if ((((struct FloatState68_2 *) arg0)->unk_5C != 0.0f) || (((struct FloatState68_2 *) arg0)->unk_64 != 0.0f)) {
        *arg3 = 3;
        var_s0 = func_8023E178_de(arg0, temp_s3, temp_f20, ((struct func_80241F14_S3 *) arg2)->unk4, ((struct func_80241F14_S3 *) arg2)->unk34, 1, arg3, 1);
    }
    if (((struct FloatState68_2 *) arg0)->unk_60 > 0.0f) {
        *arg3 = 2;
        func_80240E00_de(arg3, arg2);
        var_s0 |= func_8023EA44_de(arg0, arg3, temp_s3, temp_f20, 1);
    }
    if (((struct FloatState68_2 *) arg0)->unk_60 < 0.0f) {
        *arg3 = 9;
        func_80240D20_de(arg3, arg2);
        var_s0 |= func_8023EA44_de(arg0, arg3, temp_s3, temp_f20, 1);
    }
    return var_s0;
}
