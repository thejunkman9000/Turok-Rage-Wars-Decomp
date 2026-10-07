#include "b10_types.h"

extern f32 D_800C8870;
extern u8 D_8011FE88[];
B10Nd *func_0028B2D4(u8 *a, B10Tri *t);
void func_00240C9C(B10Ev *ev);
void func_0023E8C4(B10Obj *o, B10Ev *ev, s32 a);

void func_00243910(B10Obj *o) {
    B10Ev ev;
    B10Tri *tri;
    B10Fl *fl;
    B10Nd *nd;
    s32 i;
    tri = o->pAC;
    fl = o->p40;
    if (tri) {
        nd = func_0028B2D4(D_8011FE88, tri);
        if (nd) {
            if (fl->flags & 8) {
                if ((fl->flags & 0x100000) == 0) {
                    ev.nv = 3;
                    for (i = 0; i < 3; i++) {
                        ev.v[2 - i].x = tri->pt[i]->x;
                        ev.v[2 - i].y = tri->pt[i]->y + o->v1C.x;
                        ev.v[2 - i].z = tri->pt[i]->z;
                    }
                    func_00240C9C(&ev);
                    if (ev.f4C > D_800C8870) {
                        ev.type = 5;
                        ev.f4 = fl->f18;
                        ev.f8 = fl->b6;
                        ev.f54 = 0;
                        ev.f58 = -1;
                        ev.f10 = 0;
                        if (nd->f44 & 0x400000) {
                            ev.fC = 7;
                        } else if (nd->h52 & 0x80) {
                            ev.fC = 8;
                        } else {
                            ev.fC = 1;
                        }
                        func_0023E8C4(o, &ev, 1);
                    }
                }
            }
        }
    }
}