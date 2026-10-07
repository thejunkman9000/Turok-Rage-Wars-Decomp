#include "o02_types.h"
typedef struct O02Box { u8 pad0[0x14]; u16 f14; u16 f16; u16 f18; u16 f1A; } O02Box;
typedef struct O02Bar {
    u8 pad0[0x44];
    s32 min, max, step, val;
    s32 f54, f58, f5C;
    union { s32 f60; struct { u16 hi; u16 lo; } h60; } u60;
    O02Box *child64;
    O02Box *thumb;
    s32 flags;
} O02Bar;
void func_0040C9D0(O02Bar *w) {
    s32 t;
    if (w->flags & 1) {
        t = (w->u60.f60 - w->f58) * (w->val - w->min) / (w->max - w->min);
        w->thumb->f16 = t;
        w->thumb->f1A = w->u60.h60.lo - t;
        if (w->child64) {
            w->child64->f16 = t - (s16)w->child64->f1A / 2;
        }
    } else {
        t = (w->f5C - w->f54) * (w->val - w->min) / (w->max - w->min);
        w->thumb->f18 = t;
        if (w->child64) {
            w->child64->f14 = w->thumb->f14 - (t - (s16)w->child64->f18 / 2);
        }
    }
}
