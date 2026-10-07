#include "m02_gen.h"
extern s32 D_800D70E8;
extern M2Row190 D_80102B00[];
extern u8 D_80145040[];
extern u8 D_80145088[];
extern u8 D_801462D5;
void func_00214178(M2Act *a, M2St *s, s32 id);
s32 func_0022A590(void *w, M2Own *o);
s32 func_0022F54C(void *r, s32 w);
s32 func_00230048(M2Act *a, M2St *s);
void func_002398F8(void *w, M2Pawn *p, s32 x, s32 y, f32 f);
void func_0025DF54(s32 id);
s32 func_002301E4(M2Act *a, M2St *s) {
    M2Own *o;
    s32 v;
    s32 ok;
    s32 t;
    o = a->owner;
    if (o->unk11D8 > 0.1f) {
        return 0;
    }
    if ((a->flags & 0x300000) && o->unk1450 != 0) {
        v = o->unk1454->unk23C;
        o->unk1454->unk23C = 0;
    } else {
        v = o->unk6AC & 0x2000;
    }
    if (v != 0) {
        if (func_00230048(a, s) != 0) {
            if (s->unk13C == 2) {
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
                if (ok != 0) {
                    func_00214178(a, s, 8);
                    return 2;
                }
            }
            func_00214178(a, s, 4);
            s->unkCB = 0;
            return 1;
        }
    }
    return 0;
}
