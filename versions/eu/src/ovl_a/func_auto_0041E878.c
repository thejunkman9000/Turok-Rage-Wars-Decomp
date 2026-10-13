#include "o03_types.h"

extern O3Ps *D_auto_800EFFE0;
extern u8 D_auto_8015DCF0[];
extern O3Row D_auto_800F0070[];
extern O3Chr D_auto_800EFE3C[][17];
extern char ***D_auto_800EFFD4[];
extern O3P2 D_auto_800EFDB0[];
extern u8 D_801462C8[];
O3Obj *func_auto_0040F070(s32 p, s32 id);
void func_auto_0040ED18(s32 it, s32 on);
s32 func_auto_0041F0F8(s32 a, s32 b);
s32 func_auto_0041F5F0(s32 a);
void func_002A125C(void *d, void *s);
#define PF(k) (*(s32 *)(D_auto_8015DCF0 + off + (k)))
void func_auto_0041E878(s32 i) {
    s32 w;
    s32 off;
    O3Obj *o;
    u8 *g;
    w = D_auto_800EFFE0->w[i];
    if (D_auto_800EFFE0->cnt < i) {
        func_auto_0040ED18(w, 0);
        return;
    }
    off = i * 0x1C;
    if (PF(0) < 0) {
        func_auto_0040ED18(w, 0);
        return;
    }
    o = func_auto_0040F070(w, 0x38D);
    o->alpha = 0x7D;
    o->f2C = D_auto_800F0070[func_auto_0041F5F0(PF(0))].f8;
    o = func_auto_0040F070(w, 0x38F);
    o->alpha = 0x7D;
    g = D_801462C8;
    func_002A125C(D_auto_8015DCF0 + off + 0x10, D_auto_800EFE3C[PF(4)][func_auto_0041F0F8(PF(4), PF(0))].s[g[0x581]]);
    o->f38 = D_auto_8015DCF0 + off + 0x10;
    o = func_auto_0040F070(w, 0x38E);
    o->alpha = 0x7D;
    o->f38 = (void *)((char **)D_auto_800EFFD4[PF(4)])[g[0x581]];
    o = func_auto_0040F070(w, 0x390);
    o->alpha = 0x7D;
    o->f2C = D_auto_800EFDB0[PF(8)].a;
    o = func_auto_0040F070(w, 0x391);
    o->alpha = 0x7D;
    o->f2C = D_auto_800EFDB0[PF(8)].b;
}
