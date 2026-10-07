#include "o03_types.h"
void func_00419D04(O3A *o, s32 n);
void func_00419FD8(O3A *o, s32 n) {
    func_00419D04(o, n);
    o->flag = 1;
    o->gobj->alpha = (u8)o->vals[o->idx];
}
