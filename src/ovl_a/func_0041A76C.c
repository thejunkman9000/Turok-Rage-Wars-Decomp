#include "o03_types.h"
void func_0041A76C(O3Bar *o, s32 v) {
    o->val = v;
    o->g->w = (s16)(((f32)v / (f32)o->max) * (f32)o->width);
}
