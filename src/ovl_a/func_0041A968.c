#include "o03_types.h"
void func_0041A76C(O3Bar *o, s32 v);
void func_0041A968(O3Bar *o) {
    if (o->val > 0) {
        func_0041A76C(o, o->val - 1);
    }
}
