#include "o03_types.h"
extern O3Ps *D_800E39C0;
extern u8 D_80153F80[];
extern O3Row D_800E3A50[];
extern O3Chr D_800E381C[][17];
extern s32 *D_800E39B4[];
extern O3P2 D_800E3790[];
O3Obj *func_0040ECB0(s32 p, s32 id);
void func_0040E958(s32 it, s32 on);
s32 func_0041ECB4(s32 a, s32 b);
s32 func_0041F1B0(s32 a);
void func_002A125C(void *d, void *s);
#define PF(k) (*(s32 *)(D_80153F80 + off + (k)))
void func_0041E478(s32 i) {
    s32 w;
    s32 off;
    O3Obj *o;
    w = D_800E39C0->w[i];
    if (D_800E39C0->cnt < i) {
        func_0040E958(w, 0);
        return;
    }
    off = i * 0x1C;
    if (PF(0) < 0) {
        func_0040E958(w, 0);
        return;
    }
    o = func_0040ECB0(w, 0x38D);
    o->alpha = 0x7D;
    o->f2C = D_800E3A50[func_0041F1B0(PF(0))].f8;
    o = func_0040ECB0(w, 0x38F);
    o->alpha = 0x7D;
    func_002A125C(D_80153F80 + off + 0x10, *D_800E381C[PF(4)][func_0041ECB4(PF(4), PF(0))].s);
    o->f38 = D_80153F80 + off + 0x10;
    o = func_0040ECB0(w, 0x38E);
    o->alpha = 0x7D;
    o->f38 = (void *)*D_800E39B4[PF(4)];
    o = func_0040ECB0(w, 0x390);
    o->alpha = 0x7D;
    o->f2C = D_800E3790[PF(8)].a;
    o = func_0040ECB0(w, 0x391);
    o->alpha = 0x7D;
    o->f2C = D_800E3790[PF(8)].b;
}
