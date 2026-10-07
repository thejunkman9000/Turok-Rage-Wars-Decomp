#include "b04_types.h"
extern f32 D_800C7310, D_800C7314, D_800C7318, D_800C731C, D_800C7320, D_800CE38C;
typedef struct { u16 pad0; u16 unk6; } B04W6;
typedef struct { u8 pad0[6]; u16 unk6; } B04Wd6;
extern B04Wd6 *D_800D052C[];
typedef struct { f32 m[16]; } B04Mtx;
typedef struct { s32 w0; u8 pad4[4]; f32 f8; u8 padC[0x10]; B04SlotEnt ent[36]; s32 w37C; } B04R2;
void func_00217630(B04R2 *, B04Draw *, s32, s32);
void func_00272848(B04Mtx *);
void func_00272908(B04Mtx *, Vec3f *, Vec3f *);
void func_00273CD8(B04Mtx *, f32);
f32 func_00274878(f32, f32, f32);
void func_00217928(B04R2 *o, s32 a1, s32 a2) {
    B04Mtx m;
    Vec3f out;
    B04Draw sel[36];
    Vec3f d;
    s32 i, n, idx;
    f32 fa1;
    B04SlotEnt *e;
    if (o->w0 != 0) {
        d.x = 0;
        d.z = 0;
        d.y = D_800C7314 - (D_800C7310 - o->f8 * D_800C7310);
        n = 0;
        for (i = 0; i < 8; i++) {
            if (o->ent[i].idx != -1) {
                e = &o->ent[i];
                if (i == o->w37C)
                    fa1 = D_800CE38C * D_800C7318;
                else
                    fa1 = D_800CE38C;
                e->f30 = func_00274878(e->f30, fa1, D_800CE38C * D_800C731C);
                func_00272848(&m);
                func_00273CD8(&m, e->f28);
                func_00272908(&m, &d, &out);
                idx = o->ent[i].idx;
                if (idx >= 0 && idx < 22) {
                    sel[n].i = i;
                    sel[n].idx = o->ent[i].idx;
                    sel[n].v = out;
                    sel[n].u14 = D_800D052C[idx]->unk6;
                    sel[n].f18 = D_800C7320;
                    sel[n].f1C = D_800C7320;
                    n++;
                } else {
                    sel[n].u14 = 0;
                    sel[n].f18 = 0;
                    sel[n].i = i;
                    sel[n].idx = o->ent[i].idx;
                    sel[n].v = out;
                    n++;
                }
            } else {
                sel[n].f18 = 0;
                sel[n].u14 = 0;
            }
        }
        func_00217630(o, sel, n, a2);
    }
}
