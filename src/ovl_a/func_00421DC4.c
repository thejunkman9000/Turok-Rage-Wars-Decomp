#include "o03_types.h"
typedef struct O3Pn { O3B60 *bar; O3A *fx; O3Hdr *w8; s32 fC; s32 f10; } O3Pn;
extern O3Pn *D_800E4450;
void func_0029A73C();
void func_0041A4B0(O3B60 *o, s32 v);
s32 func_00421DC4(void) {
    func_0029A73C();
    D_800E4450->f10 = -1;
    func_0041A4B0(D_800E4450->bar, 2);
    return 0;
}
