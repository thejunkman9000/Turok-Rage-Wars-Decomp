#include "m02_gen.h"
extern f32 D_800C7FE0;
extern f32 D_800C7FE4;
extern f32 D_800C7FE8;
extern f32 D_800C7FEC;
extern f32 D_800C7FF0;
extern f32 D_800C7FF4;
extern f32 D_800C7FF8;
extern f32 D_800C7FFC;
extern f32 D_800C8000;
extern f32 D_800D2988;
extern s32 D_800E0D44[];
extern u8 D_80152789;
extern M2Row18 D_800CE8DC[];
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
void func_auto_002307E0(M2Act *a, M2St *s) {
    M2Own *o;
    s32 yy;
    f32 w;
    s32 xx;
    M2Sub698 *sub;
    f32 v;
    f32 x;
    s32 kind;
    s32 ok;
    s32 t;
    s32 st;
    o = a->owner;
    kind = D_800CE8DC[o->unk650].unk0;
    if (func_00222A80(o, o->unk62E) == 0) {
        o->unk770 = func_0022F95C(o);
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
                    yy = func_0022A590(D_80145040, o); xx = D_800E0D44[D_80152789]; func_002398F8(D_80145088, o->pawn, xx, yy, D_800C7FE0);
                }
            }
            ok = t;
        }
        if (ok != 0) {
            st = s->unk13C;
            if (st == 1) {
                if (o->unk5F6 >= 0x32) {
                    func_00214178(a, s, 5);
                    s->unk13C = 2;
                    return;
                }
                func_0025DF54(0xD4D);
                if (o->pawn != 0) {
                    yy = func_0022A590(D_80145040, o); xx = D_800E0D44[D_80145040[0x1809]]; func_002398F8(D_80145040 + 0x48, o->pawn, xx, yy, D_800C7FE4);
                }
                s->unk13C = st;
                return;
            }
        }
    }
    if (func_002301E4(a, s) == 0) {
        if (!(a->flags & 0x400)) {
            func_00214178(a, s, kind);
        }
        return;
    }
    x = s->unk128;
    w = x + 2.0f * (x * D_800D2988);
    s->unk128 = w;
    sub = o->unk698;
    if (w < 0.0f) {
        if (D_800C7FEC < -w * D_800C7FE8) goto A;
    } else {
        if (D_800C7FF4 < w * D_800C7FF0) goto A;
    }
    v = s->unk128;
    if (v < 0.0f) {
        sub->unk168 = -v * D_800C7FF8;
    } else {
        sub->unk168 = v * D_800C7FFC;
    }
    goto done;
A:
    sub->unk168 = D_800C8000;
done:
    s->unk124 = 2.0f * (s->unk128 * D_800D2988);
    s->unk13C = 1;
}
