#include "b19_types.h"
extern B19Src D_801041F8[];
void func_00283BA0(B19Obj *o) {
    o->flags |= 0x20000;
    o->pos = D_801041F8->a;
    o->pos2 = D_801041F8->b;
}
