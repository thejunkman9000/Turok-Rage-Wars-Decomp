#include "b23_types.h"

typedef struct Obj6F8C {
    u8 pad0[0x14];
    u8 sub[0x20];
    s32 unk34;
} Obj6F8C;

void func_00296DDC(void *p, s32 v);
void func_00283038(void *a, void *b);

void func_002A6F8C(s32 a0, Obj6F8C *o, void *x) {
    s32 v = o->unk34;

    if (v != -1) {
        func_00296DDC(o->sub, v);
        if (x != 0) {
            func_00283038(x, o->sub);
        }
    }
}
