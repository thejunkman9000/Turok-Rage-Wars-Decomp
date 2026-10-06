
#include "b19_types.h"
void func_00284544(B19Owner *, B19Obj *);
void func_00284640(B19Owner *owner, u8 idx) {
    s32 i;
    B19List *l;
    for (i = 0; i <= idx; i++) {
        l = (B19List *)((u8 *)owner + i * 0x14 + 0xFC28);
        if (l->tail != 0) {
            func_00284544(owner, l->tail);
            return;
        }
    }
}
