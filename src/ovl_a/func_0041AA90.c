#include "o03_types.h"
s32 func_0029EB58(s32 a);
s32 func_0029AB4C(void);
void func_0041A990(O3Bar *o);
s32 func_0041AA90(O3Bar *o, s32 a1, s32 a2, s32 a3, s32 a4) {
    if (func_0029EB58(a4) < func_0029AB4C()) {
        o->f54 = 2;
    }
    if (a3 == 1) {
        o->f54 = a3;
        func_0041A990(o);
        return 0;
    }
    return 0;
}
