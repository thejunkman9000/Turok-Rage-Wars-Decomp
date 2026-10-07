#include "b04_types.h"
typedef struct { s32 w[20]; } B04Blk80;
typedef struct { u8 pad0[8]; Vec3f pos; u8 pad14[0x5C]; f32 unk70; } B04Obj2;
extern u8 D_80104030[];
extern B04Obj2 *D_801041F0;
f32 func_0024D274(void *);
s32 func_00244494(void *, Vec3f, Vec3f, void *);
s32 func_00216BF4(B04Obj2 *o, s32 a1, B04Obj2 *t) {
    B04Blk80 save;
    Vec3f tp;
    s32 r;
    save = *(B04Blk80 *)o;
    o->pos.y = o->pos.y + func_0024D274(o);
    o->pos.y = o->pos.y + t->unk70;
    tp = t->pos;
    tp.y = tp.y + func_0024D274(t);
    tp.y = tp.y + t->unk70;
    r = func_00244494(o, o->pos, tp, D_80104030);
    if (D_801041F0 == t)
        r = 0;
    *(B04Blk80 *)o = save;
    return r;
}
