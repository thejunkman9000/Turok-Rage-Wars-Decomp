#include "m02_types.h"
extern s32 D_800CF280;
extern s32 D_800CF284;
extern s32 D_800CF288;
extern M2Row38 *D_800D052C[];
void func_0027200C(Vec3f *dst, Vec3f *src, f32 s);
void func_00272D20(M2Mtx *m, Vec3f v);
void func_00273340(M2Mtx *m, Vec3f *v);
void func_002742B4(M2Quat *q, M2Mtx *m);
void func_002734B8(M2Mtx *m, Vec3f v);
void func_00273DDC(M2Mtx *m);
void func_0026F690(M2Mtx *dst, M2Mtx *a, M2Mtx *b);
void func_00226DAC(Plr *p, M2Mtx *m);
void func_00226C3C(Plr *p, M2Quat *q);
void func_0022F5D0(Plr *c) {
    Plr *o;
    Vec3f sp10;
    M2Mtx sp20;
    Vec3f sp60;
    Vec3f sp70;
    M2Mtx sp80;
    M2Mtx spC0;
    M2Quat sp100;
    M2Quat *q;
    M2Mtx *cm;
    M2Mtx *m;
    o = c->unk1D8;
    sp70 = D_800D052C[o->unk62E]->v38;
    if (D_800CF280 != 0) {
        sp70.x = -sp70.x;
    }
    if (D_800CF284 != 0) {
        sp70.y = -sp70.y;
    }
    if (D_800CF288 != 0) {
        sp70.z = -sp70.z;
    }
    func_0027200C(&sp60, (Vec3f *)&c->unk50, 0.1f);
    func_00272D20(&sp80, sp60);
    func_0027200C(&sp70, &sp70, -10.24f);
    if (o->unk5DC != 0) {
        func_00273340((M2Mtx *)((u8 *)o->unk5DC + 0x160), &sp10);
        
        func_002742B4((M2Quat *)((u8 *)o->unk5DC + 0x140), &sp20);
    } else {
        func_00226DAC(o, &spC0);
        func_00226C3C(o, &sp100);
        func_00273340(&spC0, &sp10);
        
        func_002742B4(&sp100, &sp20);
    }
    cm = (M2Mtx *)((u8 *)c + 0x74);
    m = &sp80;
    func_002734B8(m, sp70);
    func_00273DDC(m);
    func_0026F690(cm, m, &sp20);
    func_002734B8(cm, sp10);
}
