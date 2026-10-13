#include "m02_gen.h"
extern M2Row18 D_800CE8DC[];
extern s32 D_800E0D44[];
extern u8 D_80152789;
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
void func_auto_00231C24(M2Act *a, M2St *s) {
    M2Own *o;
    s32 kind;
    s32 ok;
    s32 t;
    o = a->owner;
    kind = D_800CE8DC[o->unk650].unk0;
    if (func_00222A80(o, o->unk62E) == 0) {
        o->unk770 = func_0022F95C(o);
        return;
    }
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
                    func_002398F8(D_80145088, o->pawn, D_800E0D44[D_80152789], func_0022A590(D_80145040, o), 1.0f);
                }
            }
            ok = t;
        }
        if (ok != 0) {
            func_00214178(a, s, 8);
            return;
        }
    }
    if (func_002301E4(a, s) == 0 && !(a->flags & 0x400)) {
        func_00214178(a, s, kind);
    }
}
