#include "b10_types.h"

void func_0026F690(f32 *a, f32 *b, f32 *c);
s32 *func_0028FD94(s32 *n, s32 i);
void func_00242FD8(B10Obj *o, s32 *n);

void func_00243864(B10Obj *o) {
    B10X *x = o->p58;
    s32 **p = x->pB4;
    s32 *node;
    s32 *t;
    s32 n;
    s32 i;
    if (p) {
        func_0026F690(&o->f64, x->m68, &o->fC);
        node = *p;
        o->pA4 = func_0028FD94(node, 0);
        t = func_0028FD94(node, 2);
        n = *t;
        for (i = 0; i < n; i++) {
            func_00242FD8(o, func_0028FD94(t, i));
        }
    }
}
