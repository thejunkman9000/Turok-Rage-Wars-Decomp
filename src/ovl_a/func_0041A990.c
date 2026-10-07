#include "o03_types.h"
void func_0041A76C(O3Bar *o, s32 v);
void func_0041A990(O3Bar *o) {
    if (o->val < o->max) {
        func_0041A76C(o, o->val + 1);
    }
}
