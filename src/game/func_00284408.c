#include "b19_types.h"
void *func_0025CC8C(void);
s32 func_0025CA44(void *, s32);
void func_00284408(B19Obj *o) {
    if (o->unk1DC) {
        func_0025CA44(func_0025CC8C(), o->unk1DC);
        o->unk1DC = 0;
    }
}
