#include "b09_types.h"

extern B09World D_8011FE88[];
extern B09BodyDef D_80104170;
void func_0023EEF0(B09Body *, B09Bounds *, B09Ent *);

static inline void calc_bounds(B09Body *b, B09Bounds *o) {
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

void func_0023F42C(B09Body *b) {
    B09BodyDef *d = b->def;
    B09Bounds bounds;
    B09Ent *self;
    B09Ent *e;
    s32 n;
    s32 i;
    if (d->b4 != 0 && d != &D_80104170) {
        self = *(B09Ent **)b;
        n = D_8011FE88->count;
        calc_bounds(b, &bounds);
        for (i = 0; i < n; i++) {
            e = D_8011FE88->ents[i];
            if (e == self) {
                continue;
            }
            switch (e->kind) {
            case 1:
                if ((d->flags & 1) && e->unk174 == 0) {
                    continue;
                }
                break;
            case 3:
                if (!(d->flags & 0x20)) {
                    continue;
                }
                break;
            case 2:
            default:
                break;
            }
            func_0023EEF0(b, &bounds, e);
        }
    }
}
