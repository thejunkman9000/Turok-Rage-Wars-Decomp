#include "b07_types.h"

extern u8 D_801040F0[];
extern u8 *D_80103FCC;

f32 func_0024E454(void *o);
f32 func_0024D388(void *o);
f32 func_0024D274(void *o);
f32 func_0024E410(void *o);
s32 func_0024490C(void *o, f32 x, f32 y, f32 z, Vec3f p, void *tbl, f32 a, f32 b, f32 c, f32 d);

void func_0022DE48(Actor *actor, u8 *o)
{
    f32 d;
    f32 v1, v2, v3, v4;
    f32 t;
    Vec3f p;

    d = AT(f32, actor->def, 0xF4) - AT(f32, actor, 0x780) - AT(f32, actor, 0x718) -
        AT(f32, actor, 0x720) - AT(f32, actor, 0x6F4);
    if (d > 0) {
        v1 = func_0024E454(o);
        v2 = func_0024D388(o);
        v3 = func_0024D274(o);
        v4 = func_0024E410(o);
        p.x = AT(f32, o, 0x8);
        p.y = AT(f32, o, 0xC) + d;
        p.z = AT(f32, o, 0x10);
        if (func_0024490C(o, AT(f32, o, 0x8), AT(f32, o, 0xC), AT(f32, o, 0x10), p, D_801040F0,
                          v1, v2, v3, v4)) {
            t = AT(f32, D_80103FCC, 0xE8) - AT(f32, o, 0xC);
            AT(f32, actor, 0x6EC) -= d - t;
            d = t;
        }
    }
    AT(f32, actor, 0x6F4) += d;
}
