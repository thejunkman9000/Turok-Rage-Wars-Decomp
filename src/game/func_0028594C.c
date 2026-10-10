#include "span_1000/code_802646F4.h"
#include "span_1000/code_8028567C.h"
#include "types.h"



s32 func_8028597C_de(s32 arg0) {
    s32 result;

    result = 0;
    if (func_80264DF0_de(arg0 + 0x20) != 0) {
        result = 1;
    } else if (func_80264DF0_de(arg0 + 0x2C) != 0) {
        result = 1;
    }
    return result;
}
