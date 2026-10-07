#include "m02_gen.h"
extern f32 D_800D2988;
extern s32 D_800D70E8;
extern M2Row190 D_80102B00[];
extern u8 D_80145040[];
extern u8 D_80145088[];
extern u8 D_801462D5;
s32 func_0022A590(void *w, M2Own *o);
s32 func_0022F54C(void *r, s32 w);
void func_002398F8(void *w, M2Pawn *p, s32 x, s32 y, f32 f);
void func_0025DF54(s32 id);
f32 func_00274810(f32 a, f32 b);
void func_00230D94(M2Act *a, M2St *s) {
    M2Own *o;
    M2Sub698 *sub;
    f32 v;
    s32 ok;
    s32 t;
    o = a->owner;
    if (s->unk34 != 4) {
        s->unk128 = func_00274810(s->unk128, 0.013613569f);
    }
    s->unk124 = s->unk124 + 2.0f * (s->unk128 * D_800D2988);
    v = s->unk128;
    sub = o->unk698;
    if (v < 0.0f) {
        if (1.0f < -v * 1.7904929f) goto A;
    } else {
        if (1.0f < v * 1.7904929f) goto A;
    }
    v = s->unk128;
    if (v < 0.0f) {
        sub->unk168 = -v * 1.7904929f;
    } else {
        sub->unk168 = v * 1.7904929f;
    }
    goto done;
A:
    sub->unk168 = 1.0f;
done:
    if (o->unk6AC & 0x4000) {
        if (o->unk11D8 > 0.0f) {
            ok = 0;
        } else if (o->unk1450 != 0) {
            ok = 1;
        } else if (D_801462D5 != 1) {
            ok = 1;
        } else {
            t = func_0022F54C(&D_80102B00[o->unk5D4], o->unk62E);
            if (t == 0) {
                func_0025DF54(0xD4D);
                if (o->pawn != 0) {
                    func_002398F8(D_80145088, o->pawn, D_800D70E8, func_0022A590(D_80145040, o), 1.0f);
                }
            }
            ok = t;
        }
        if (ok != 0 && o->unk5F6 > 0) {
            if (!(o->unk122C & 0x18400)) {
                func_0025DF54(0x7BC);
            }
            o->unk122C = o->unk122C | 0x18400;
            o->unk1230 = 25.0f;
        }
    }
}
