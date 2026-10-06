
#include "b19_types.h"
extern f32 D_800C9F80;
extern const f32 D_800C9F84;
extern B19Plr *D_80145060;
f32 func_0024D274(B19Plr *);
f32 func_0027272C(B19Vec3 *, B19Vec3 *);
void func_00282E6C(B19Obj *, B19Plr *);
void func_00284AF4(B19Obj *o) {
    f32 r = (f32)o->parent->s10;
    B19Plr *p;
    B19Vec3 v;
    s32 done;
    if (!(r <= 0.0f)) {
        r = r * D_800C9F80;
        r = r * r;
        for (p = D_80145060; p != 0; ) {
            v = p->pos;
            done = 0;
            if (o->id != 0x40F) {
                v.y += func_0024D274(p) * D_800C9F84;
            }
            if (func_0027272C(&o->pos, &v) < r) {
                func_00282E6C(o, p);
                if (o->id == 0x40F) done = 1;
            }
            if (done) p = 0;
            else p = p->next;
        }
    }
}
