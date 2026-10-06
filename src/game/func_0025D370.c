#include "p3_types.h"

typedef struct {
    u32 a;
    u16 b;
} P3Ent;

typedef struct {
    u8 pad0[0x2B50];
    void *tab;
} P3Res;

typedef struct {
    P3Res *res;            /* 0x00 */
    u8 pad04[0x20 - 4];
    f32 f20;
    f32 f24;
} P3Anim;

extern f32 D_800C90B0;
P3Ent *func_0028FD94(void *tab, s32 idx);

void func_0025D370(P3Anim *o, s32 i) {
    P3Ent *e;
    e = func_0028FD94(o->res->tab, i * 2);
    o->f20 = (f32)e->a * D_800C90B0;
    o->f24 = e->b;
    func_0028FD94(o->res->tab, i * 2 + 1);
}
