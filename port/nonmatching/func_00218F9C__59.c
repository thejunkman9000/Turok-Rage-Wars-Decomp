#include "b04_types.h"
extern f32 D_800C73A0, D_800C73A4, D_800C73A8, D_800C73AC, D_800C73B0, D_800CE3CC;
typedef struct { f32 m[16]; } B04Mtx;
typedef struct { s32 unk0; u8 pad4[4]; f32 unk8; u8 padC[0x10]; B04Ent20 ent[4]; s32 unk6C; } B04Obj3;
void func_002185D0(B04Obj3 *, B04Sel *, s32, s32);
void func_00272848(B04Mtx *);
void func_00272908(B04Mtx *, Vec3f *, Vec3f *);
void func_00273CD8(B04Mtx *, s32);
f32 func_00274878(f32, f32, f32);
void func_00218F9C(B04Obj3 *o, s32 a1, s32 a2) {
    B04Mtx m;
    Vec3f out;
    B04Sel sel[4];
    Vec3f d;
    s32 i;
    f32 fa1;
    f32 k1, k2, k3;
    B04Ent20 *e;
    if (o->unk0 != 0) {
        d.x = 0;
        d.z = 0;
        k1 = D_800C73A4;
        k2 = D_800C73A8;
        k3 = D_800C73B0;
        d.y = D_800C73AC - (D_800C73A0 - o->unk8 * D_800C73A0);
        for (i = 0; i < 4; i++) {
            e = &o->ent[i];
            if (i == o->unk6C)
                fa1 = D_800CE3CC * k1;
            else
                fa1 = D_800CE3CC;
            e->f2C = func_00274878(e->f2C, fa1, D_800CE3CC * k2);
            func_00272848(&m);
            func_00273CD8(&m, e->f24);
            func_00272908(&m, &d, &out);
            sel[i].idx = i;
            sel[i].v = out;
            sel[i].id = i + 0xC1C;
            sel[i].f14 = k3;
            sel[i].f18 = k3;
        }
        func_002185D0(o, sel, 4, a2);
    }
}
