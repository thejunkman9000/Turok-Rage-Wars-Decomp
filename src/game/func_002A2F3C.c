#include "b23_types.h"

s32 func_0029EB58(s32 a);
s32 func_0029AB4C();
void func_002A2D14(StateObj *o);
void func_0025DF54(s32 a);

s32 func_002A2F3C(StateObj *o, s32 a1, s32 a2, s32 mode, s32 arg) {
    s32 t = func_0029EB58(arg);

    if (t < func_0029AB4C()) {
        o->unk5C = 2;
        o->unk48 = 0;
    }
    if (mode == 1) {
        o->unk5C = 0;
        func_002A2D14(o);
        func_0025DF54(0xE81);
        return 0;
    }
    return 0;
}
