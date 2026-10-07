#include "b09_types.h"

extern B09World D_8011FE88[];
extern B09Obj2 *D_80103FCC;
extern B09Misc D_801462C8[];
s32 func_0023DA90(B09Mover *, f32 *, f32 *);
void func_0023EEF0(B09Mover *, B09Bounds *, B09Ent2 *);
void func_0023F634(B09Mover *, B09Bounds *);
void func_0023FD08(B09Mover *, B09Ent2 *, B09V3 *, f32 *);
void func_00285290(B09Hit2 *, s32, s32, s32 (*)(), void (*)());
s32 func_00240628();
void func_002405EC();

void func_00240250(B09Mover *m) {
    B09BodyDef *d;
    B09Bounds bounds;
    B09Hit2 hits[0x20];
    f32 t;
    B09Ent *owner;
    B09V3 *opos;
    B09Ent2 *e;
    s32 n;
    s32 k;
    s32 nhits;
    s32 kind;
    s32 i;
    B09Hit2 *p;

    d = m->def;
    if (d->b4 != 0 && (d->flags & 0x10000)) {
        p = hits;
        k = 0;
        nhits = 0;
        owner = m->owner;
        n = D_8011FE88->count2;
        opos = &owner->v8;
        for (; k < n; k++) {
            if (nhits >= 0x20) {
                break;
            }
            e = D_8011FE88->ents2[k];
            if (owner == (B09Ent *)e) {
                continue;
            }
            if (d->b4 == 7 && D_80103FCC->unk0 == (s32)e) {
                continue;
            }
            if ((d->flags & 0x8000) && e->uE4 == 0x64F) {
                continue;
            }
            if (owner->kind == 2 && owner->unk12C == e) {
                if (*owner->unk118 & 0x40) {
                    continue;
                }
                kind = *e->def;
                if (kind == 1) {
                    continue;
                }
                if (kind == 4) {
                    continue;
                }
            }
            if (!(m->f90 > e->fE8)) {
                continue;
            }
            if (!(m->f84 < e->fF4)) {
                continue;
            }
            if (!(m->f98 > e->fF0)) {
                continue;
            }
            if (!(m->f8C < e->fFC)) {
                continue;
            }
            if (!(m->f94 > e->fEC)) {
                continue;
            }
            if (!(m->f88 < e->fF8)) {
                continue;
            }
            if (func_0023DA90(m, &e->fE8, &t) != 0) {
                nhits++;
                p->e = e;
                p->t = t;
                p++;
            }
        }
        if (nhits != 0) {
            func_00285290(hits, nhits, 8, func_00240628, func_002405EC);
            p = hits;
            for (i = 0; i < nhits; i++, p++) {
                if (!(p->t < m->qcopy.t)) {
                    break;
                }
                e = p->e;
                if ((e->flags100 & 0x300000) && D_801462C8->b1D == 0) {
                    func_0023F634(m, &bounds);
                    func_0023EEF0(m, &bounds, e);
                } else {
                    func_0023FD08(m, e, opos, &m->f84);
                }
            }
        }
    }
}
