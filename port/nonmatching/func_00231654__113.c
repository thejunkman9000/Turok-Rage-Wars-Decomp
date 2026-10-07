#include "m02_gen.h"
extern M2Row18 D_800CE8DC[];
extern s32 D_800D70E8;
extern M2Row190 D_80102B00[];
extern u8 D_80145040[];
extern u8 D_80145088[];
extern u8 D_801462D5;
void func_00214178(M2Act *a, M2St *s, s32 id);
s32 func_00222A80(M2Own *o, s32 w);
s32 func_0022A590(void *w, M2Own *o);
s32 func_0022F54C(void *r, s32 w);
s32 func_0022F95C(M2Own *o);
s32 func_002301E4(M2Act *a, M2St *s);
void func_002398F8(void *w, M2Pawn *p, s32 x, s32 y, f32 f);
void func_0025DF54(s32 id);
void func_00231654(M2Act *a, M2St *s) {
    M2Own *o;
    s32 kind;
    s32 ok;
    s32 t;
    o = a->owner;
    kind = D_800CE8DC[o->unk650].unk0;
    if (func_00222A80(o, o->unk62E) == 0) {
        if (s->unk13C == 2) {
            s->unk13C = 1;
            if (func_00222A80(o, o->unk62E) != 0) {
                goto b6;
            }
        }
        o->unk770 = func_0022F95C(o);
        return;
    }
b6:
    if (o->unk6B0 & 0x4000) {
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
        if (ok != 0 && s->unk144 > 0) {
            if (s->unk13C == 1) {
                s->unk13C = 2;
                if (func_00222A80(o, o->unk62E) != 0) {
                    s->unk144 = 1;
                } else {
                    func_0025DF54(0xD4D);
                    if (o->pawn != 0) {
                        func_002398F8(D_80145040 + 0x48, o->pawn, D_800D70E8, func_0022A590(D_80145040, o), 1.0f);
                    }
                    s->unk13C = 1;
                }
            } else {
                s->unk13C = 1;
                s->unk144 = 1;
            }
        }
    }
    if (s->unk13C == 1) {
        if (1.0f < o->unk11F4) {
            o->unk11F4 = o->unk11F4 - 0.5f;
        }
        if (o->unk11F4 < 1.0f) {
            o->unk11F4 = 1.0f;
        }
    } else if (s->unk13C == 2) {
        if (o->unk11F4 < 2.0f) {
            o->unk11F4 = o->unk11F4 + 0.05f;
        }
        if (2.0f < o->unk11F4) {
            o->unk11F4 = 2.0f;
        }
    }
    o->unk11F8 = (o->unk11F8 + (s32)o->unk11F4) % 8;
    if (func_002301E4(a, s) == 0) {
        if (!(a->flags & 0x400)) {
            func_00214178(a, s, kind);
        }
    }
}
