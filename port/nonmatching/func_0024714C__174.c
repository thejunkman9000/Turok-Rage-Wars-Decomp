#include "b10_types.h"

extern u8 D_801043D8[];
extern B10Pu *D_801041F0;
s32 func_00243A80(B10Obj *o, Vec3f v, B10C *c);
void func_00278E74(B10Hh *p, s32 a, B10Obj *o);
void func_00278DE8(B10Pu *p, s32 a, B10Obj *o);

void func_0024714C(B10Obj *o, Vec3f *v) {
    B10Z *z;
    B10C *c;
    f32 save;
    B10H *old;
    s32 hit;
    if ((o->flags100 & 0x10000) && (z = o->p1A0) != 0) {
        c = z->pC;
        if (c == 0) {
            c = (B10C *)D_801043D8;
        }
        save = c->f8;
        if ((u16)(o->h238 - 0x2B0C) < 8) {
            c->f8 = 0;
        }
        old = o->p14;
        hit = func_00243A80(o, *v, c);
        if (old != o->p14) {
            o->p1F4 = old;
        }
        c->f8 = save;
        if (old) {
            if (o->p14 && ((B10Hh *)old)->h0 != ((B10Hh *)o->p14)->h0 && *o->p18 == 1) {
                func_00278E74((B10Hh *)old, 0x80, o);
                func_00278E74((B10Hh *)o->p14, 0x40, o);
            }
        }
        if (hit && !(o->flags100 & 0x300000)) {
            if (*o->p18 == 1) {
                B10Pu *pu = D_801041F0;
                if (pu && pu->b0 == 1) {
                    func_00278DE8(pu, 0x20, o);
                }
            }
        }
        if (o->fn284) {
            ((void (*)(B10Obj *, void *, B10C *))o->fn284)(o, &o->b170, c);
        }
    } else {
        *(Vec3f *)&o->u8 = *v;
    }
}
