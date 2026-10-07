#include "m02_gen.h"
extern s32 D_800CF518;
extern f32 D_800D2988;
extern s32 D_801450B8;
void func_00214178(M2Act *a, M2St *s, s32 id);
void func_0021A9A4(M2Own *o, s32 id);
s32 func_00222A80(M2Own *o, s32 w);
void func_0022AF30(M2Own *o);
void func_0022AFFC(M2Own *o);
void func_0025DE74(s32 id, Vec3f pos, Vec3f *pp, s32 x);
void func_002748E0(Vec3f *v, f32 a, f32 b);
void func_00230BB8(M2Act *a, M2St *s) {
    M2Own *o;
    Vec3f *pv;
    s32 ok;
    s32 t;
    M2Pawn *pawn;
    f32 tm;
    o = a->owner;
    pawn = o->pawn;
    pv = pawn ? &pawn->unk128 : &o->pos;
    if (o->unk11D8 > 0.1f) {
        ok = 1;
    } else if ((a->flags & 0x300000) && o->unk1450 != 0) {
        t = o->unk1454->unk23C;
        o->unk1454->unk23C = 0;
        ok = t == 0;
    } else if (!(o->unk6AC & 0x2000)) {
        ok = 1;
    } else if (o->unk11B4 != 0) {
        ok = 1;
    } else {
        ok = func_00222A80(o, o->unk62E) == 0;
    }
    if (ok != 0) {
        func_00214178(a, s, 2);
        func_0022AF30(o);
        func_0022AFFC(o);
        func_0025DE74(0x794, *pv, pv, -1);
        func_002748E0((Vec3f *)&s->unk128, (f32)D_800CF518 * 0.017453294f, 0.4f);
        return;
    }
    func_002748E0((Vec3f *)&s->unk128, (f32)D_800CF518 * 0.017453294f, 0.4f);
    tm = s->unk64 - D_800D2988;
    s->unk64 = tm;
    if (tm <= 0.0f) {
        s->unk64 = tm + 1.125f;
        if (o->unk1450 == 0 && D_801450B8 == 1) {
            func_0021A9A4(a->owner, 0x3F9);
        } else {
            func_0021A9A4(a->owner, 0x4CB);
        }
    }
}
