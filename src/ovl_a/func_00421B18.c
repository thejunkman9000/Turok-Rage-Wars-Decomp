#include "o03_types.h"
/* ROM has `jal func_0040ECB0 ; addiu a1,zero,0x380` (2 words) BEFORE the prologue (fragment); this body matches from 0x421B20 (rom 0x18FB20). */

void *func_00252FFC(s32 size);
void func_002A3358();
O3B60 *func_0041A300(s32 a, s32 b);
void func_0041A4FC(O3B60 *o);
void func_0041B190(s32 a);
O3Hdr *func_0040ECB0(O3Hdr *p, s32 id);
O3Ps *func_00419ED4(s32 a, s32 b);
typedef struct O3Pn { O3B60 *bar; O3A *fx; O3Hdr *w8; s32 fC; s32 f10; } O3Pn;
extern O3Pn *D_800E4450;
s32 func_00421B18(O3Hdr *root) {
    O3Hdr *h;
    D_800E4450 = func_00252FFC(0x14);
    func_002A3358();
    D_800E4450->bar = func_0041A300(0x39E, 0x39F);
    func_0041A4FC(D_800E4450->bar);
    func_0041B190(0x3A5);
    func_0041B190(0x3A4);
    func_0041B190(0x3A7);
    func_0041B190(0x3A3);
    func_0041B190(0x3A2);
    func_0041B190(0x3A6);
    h = func_0040ECB0(root, 0x3A0);
    D_800E4450->w8 = h;
    h->alpha = 0xF;
    D_800E4450->fx = (O3A *)func_00419ED4(0x3A1, 0x6E);
    D_800E4450->fC = 3;
    return 0;
}
