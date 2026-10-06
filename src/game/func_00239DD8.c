#include "b08_types.h"

extern f32 D_800C8664;

void func_00239DD8(ChanObj *o, f32 a, f32 b, f32 c, f32 d, s32 e, Vec3f v) {
    o->ch[0].v = v;
    o->ch[0].d = d;
    o->ch[1].mode = e;
    o->ch[2].mode = e;
    o->ch[3].mode = e;
    o->ch[1].v.x = a * D_800C8664;
    o->ch[2].v.x = b * D_800C8664;
    o->ch[3].v.x = c * D_800C8664;
}
