#include "b08_types.h"

extern f32 D_800C8660;

void func_00239D80(ChanObj *o) {
    Chan *c1 = &o->ch[1], *c2 = &o->ch[2], *c3 = &o->ch[3];

    o->ch[0].v.x = 0;
    o->ch[0].v.y = 0;
    o->ch[0].v.z = 0;
    o->ch[0].d = D_800C8660;
    c1->v.x = 0;
    c1->v.y = 0;
    c1->v.z = 0;
    c1->d = 0;
    c2->v.x = 0;
    c2->v.y = 0;
    c2->v.z = 0;
    c2->d = 0;
    c3->v.x = 0;
    c3->v.y = 0;
    c3->v.z = 0;
    c3->d = 0;
}
