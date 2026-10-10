#include "span_1000/code_802412C0.h"
#include "types.h"

extern s32 func_8023E8D4_de(void *, s32 *, s32);
extern void func_80240D20_de(s32 *, void *);
extern void func_80240E00_de(s32 *, void *);
extern void func_80240EE0_de(s32 *, void *);
extern void func_80240FC0_de(s32 *, void *);
extern void func_802410A0_de(s32 *, void *);
extern void func_80241180_de(s32 *, void *);

s32 func_80242920_de(void *arg0, void *arg1, void *arg2, s32 *arg3) {
    s32 result;

    result = 0;
    if (((struct FloatState68 *) arg0)->unk_60 > 0.0f) {
        *arg3 = 2;
        func_80240E00_de(arg3, arg2);
        result = func_8023E8D4_de(arg0, arg3, 1);
    }
    if ((((struct FloatState68 *) arg0)->unk_5C != 0.0f) || (((struct FloatState68 *) arg0)->unk_64 != 0.0f)) {
        *arg3 = 3;
        func_80240EE0_de(arg3, arg2);
        result |= func_8023E8D4_de(arg0, arg3, 1);
        func_80240FC0_de(arg3, arg2);
        result |= func_8023E8D4_de(arg0, arg3, 1);
        func_802410A0_de(arg3, arg2);
        result |= func_8023E8D4_de(arg0, arg3, 1);
        func_80241180_de(arg3, arg2);
        result |= func_8023E8D4_de(arg0, arg3, 1);
    }
    if (((struct FloatState68 *) arg0)->unk_60 < 0.0f) {
        *arg3 = 9;
        func_80240D20_de(arg3, arg2);
        result |= func_8023E8D4_de(arg0, arg3, 1);
    }
    return result;
}
