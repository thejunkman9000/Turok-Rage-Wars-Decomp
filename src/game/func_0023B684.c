#include "b09_types.h"

void func_00296DDC(u8 *, s32);

void func_0023B684(B09Emitter *e, B09EDef *def, s16 n, f32 a, f32 b, f32 c, f32 d) {
    e->def = def;
    e->mask = n;
    func_00296DDC(e->pad14, def->id);
    e->f1C = 0;
    e->f20 = 0;
    e->f208 = 0;
    e->f20C = 0;
    e->f214 = a;
    e->f218 = b;
    e->f21C = c;
    e->f220 = d;
}
