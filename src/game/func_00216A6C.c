#include "b04_types.h"
typedef struct { s32 w[20]; } B04Blk80;
typedef struct { u8 pad0[8]; Vec3f pos; u8 pad14[0x5C]; f32 unk70; } B04Obj2;
typedef struct { u16 pad0; u16 flags; } B04Flg;
extern f32 D_800C72BC;
extern u8 D_80103FD0[];
extern B04Flg *D_8010428C;
extern B04Flg *D_801042A4;
f32 func_0024D274(void *);
s32 func_00244494(void *, Vec3f, Vec3f, void *);
s32 func_00216A6C(B04Obj2 *o, s32 a1, B04Obj2 *t) {
    B04Blk80 save;
    Vec3f tp;
    f32 k;
    save = *(B04Blk80 *)o;
    k = D_800C72BC;
    o->pos.y = o->pos.y + func_0024D274(o) * k;
    o->pos.y = o->pos.y + o->unk70;
    tp = t->pos;
    tp.y = tp.y + func_0024D274(t) * k;
    tp.y = tp.y + t->unk70;
    func_00244494(o, o->pos, tp, D_80103FD0);
    *(B04Blk80 *)o = save;
    if (D_8010428C != NULL && (D_8010428C->flags & 2))
        return 1;
    if (D_801042A4 != NULL && (D_801042A4->flags & 2))
        return 1;
    return 0;
}
