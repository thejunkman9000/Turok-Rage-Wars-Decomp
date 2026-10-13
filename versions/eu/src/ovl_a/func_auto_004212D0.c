#include "o03_types.h"
#include "veu3n06_types.h"
extern O3Pm *D_auto_800F0A20;
extern char *D_auto_800E1C14[];
extern char *D_auto_800E1C24[];
void *func_00252FFC(s32 size);
O3Spr *func_auto_0040F070(s32 p, s32 id);
s32 func_auto_0041A294(s32 a, s32 b);
s32 func_auto_0041A6C0(s32 a, s32 b);
s32 func_auto_0041B000(s32 a, s32 b);
void func_auto_0041B150(s32 o, s32 i);
void func_auto_0041B174(s32 o, char *s);
void func_auto_0041B550(s32 id);
void func_auto_0042175C();
s32 func_auto_004212D0(s32 root) {
    EuGlob *g;
    D_auto_800F0A20 = func_00252FFC(0x3C);
    D_auto_800F0A20->w8 = (O3Hdr *)root;
    D_auto_800F0A20->f38 = 0;
    func_auto_0040F070(root, 0x3A8)->f1A = 0x88;
    D_auto_800F0A20->bar = (O3B60 *)func_auto_0041A6C0(0x3A8, 0x3A9);
    func_auto_0041B550(0x3B6);
    D_auto_800F0A20->fC = func_auto_0041B000(0x3B4, 0x3B5);
    g = &D_801462C8;
    func_auto_0041B174(D_auto_800F0A20->fC, D_auto_800E1C14[g->lang]);
    func_auto_0041B174(D_auto_800F0A20->fC, D_auto_800E1C24[g->lang]);
    if (g->flags & 0x08000000) {
        func_auto_0041B150(D_auto_800F0A20->fC, 1);
    } else {
        func_auto_0041B150(D_auto_800F0A20->fC, 0);
    }
    D_auto_800F0A20->f10 = func_auto_0041B000(0x3B1, 0x3B2);
    g = &D_801462C8;
    func_auto_0041B174(D_auto_800F0A20->f10, D_auto_800E1C14[g->lang]);
    func_auto_0041B174(D_auto_800F0A20->f10, D_auto_800E1C24[g->lang]);
    if (g->flags & 0x10000000) {
        func_auto_0041B150(D_auto_800F0A20->f10, 1);
    } else {
        func_auto_0041B150(D_auto_800F0A20->f10, 0);
    }
    D_auto_800F0A20->f14 = func_auto_0041B000(0x3AD, 0x3AE);
    g = &D_801462C8;
    func_auto_0041B174(D_auto_800F0A20->f14, D_auto_800E1C14[g->lang]);
    func_auto_0041B174(D_auto_800F0A20->f14, D_auto_800E1C24[g->lang]);
    if (g->flags & 8) {
        func_auto_0041B150(D_auto_800F0A20->f14, 1);
    } else {
        func_auto_0041B150(D_auto_800F0A20->f14, 0);
    }
    D_auto_800F0A20->f18 = func_auto_0041B000(0x3AF, 0x3B0);
    g = &D_801462C8;
    func_auto_0041B174(D_auto_800F0A20->f18, D_auto_800E1C14[g->lang]);
    func_auto_0041B174(D_auto_800F0A20->f18, D_auto_800E1C24[g->lang]);
    if (g->flags & 0x20000000) {
        func_auto_0041B150(D_auto_800F0A20->f18, 1);
    } else {
        func_auto_0041B150(D_auto_800F0A20->f18, 0);
    }
    func_auto_0041B550(0x3AC);
    D_auto_800F0A20->item = (O3Spr *)func_auto_0040F070(root, 0x3B7);
    D_auto_800F0A20->f28 = 0;
    D_auto_800F0A20->timer = 0;
    D_auto_800F0A20->f34 = 1;
    D_auto_800F0A20->f4 = func_auto_0041A294(0x3AA, 0x6E);
    func_auto_0042175C();
    return 0;
}
