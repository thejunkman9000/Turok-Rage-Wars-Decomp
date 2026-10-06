#include "b08_types.h"
typedef struct BigObj { u8 pad0[0xA0]; ChanObj co; } BigObj;
extern f32 D_800C862C;
static inline void set(BigObj *o, f32 a, f32 b, f32 c, f32 d, s32 e, Vec3f v) {
    o->co.ch[0].v = v;
    o->co.ch[0].d = d;
    o->co.ch[1].mode = e;
    o->co.ch[2].mode = e;
    o->co.ch[3].mode = e;
    o->co.ch[1].v.x = a * D_800C862C;
    o->co.ch[2].v.x = b * D_800C862C;
    o->co.ch[3].v.x = c * D_800C862C;
}
void func_00239314(BigObj *o, f32 a, f32 b, f32 c, f32 d, s32 e, Vec3f v) {
    if (o != NULL) {
        set(o, a, b, c, d, e, v);
    }
}
