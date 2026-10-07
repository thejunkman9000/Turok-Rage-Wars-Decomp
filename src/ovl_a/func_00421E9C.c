#include "o03_types.h"
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; } O3Z;
void func_00421E9C(O3Z *o, s32 v) {
    if (o->f8 != v) {
        o->f8 = v;
        if (v == 0) {
            o->f0 = 0;
        } else {
            o->f0 = 1000;
        }
        o->f4 = 0;
    }
}
