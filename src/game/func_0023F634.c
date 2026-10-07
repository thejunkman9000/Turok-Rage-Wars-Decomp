#include "b09_types.h"

void func_0023F634(B09Body *b, B09Bounds *o) {
    f32 m;
    B09BodyDef *fp = b->def;
    o->r = b->fC;
    o->flag = fp->flags & 0x400;
    o->c4 = b->f14;
    o->c8 = o->c4 + b->f10;
    o->c10 = b->f48 + o->c4;
    o->cC = b->f48 + o->c8;
    o->c18 = b->f54 + o->c4;
    o->c14 = b->f54 + o->c8;
    m = b->f50;
    if (!(m <= b->f44)) {
        m = b->f44;
    }
    o->c1C = m - o->r;
    m = b->f50;
    if (!(b->f44 <= m)) {
        m = b->f44;
    }
    o->c24 = m + o->r;
    m = b->f58;
    if (!(m <= b->f4C)) {
        m = b->f4C;
    }
    o->c20 = m - o->r;
    m = b->f58;
    if (!(b->f4C <= m)) {
        m = b->f4C;
    }
    o->c28 = m + o->r;
}
