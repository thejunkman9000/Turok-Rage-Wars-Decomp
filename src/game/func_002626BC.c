#include "b14_types.h"
typedef struct {
    /* 0x00 */ s32 pad0;
    /* 0x04 */ s16 id;
    /* 0x06 */ s16 pad6;
    /* 0x08 */ s16 f8;
    /* 0x0A */ s16 padA;
    /* 0x0C */ s32 fC;
    /* 0x10 */ s32 h;
} B14Anim3;
s32 func_0028FE1C(s32 a, s32 b, s32 id, s32 *out);
s32 func_002518DC(s32 a, s32 b, s32 c, s32 d, s32 e, void *f, void *g, void *h, s32 i);
s32 func_002624F8(void *o);
void *func_002604BC(void *o);
u16 *func_0028FD94(void *tree, s32 idx);
void func_0025F58C();
extern u8 D_800C92A0[];
s32 func_002626BC(B14Anim3 *o, s32 a, s32 b, s32 id) {
    s32 sz;
    s32 t;
    void *tree;
    u16 v;
    if (id == -1) {
        o->h = 0;
        goto fail;
    }
    t = func_0028FE1C(a, b, id, &sz);
    o->h = func_002518DC(0, t, t, sz, 4, o, func_0025F58C, D_800C92A0, 0);
    if (func_002624F8(o) != 0) {
        tree = func_002604BC(o);
        v = func_0028FD94(tree, 0)[3];
        o->id = id;
        o->f8 = v;
        o->fC = func_0028FD94(func_0028FD94(tree, 3), 0)[1];
        return 1;
    }
    return 0;
fail:
    return 0;
}