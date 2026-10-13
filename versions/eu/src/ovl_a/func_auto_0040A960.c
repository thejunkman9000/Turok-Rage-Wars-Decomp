#include "o01_types.h"
#include "veu3n06_types.h"

extern O01Cfg *D_800E28BC;
extern u8 D_auto_800ED404[];
s32 func_auto_00442EE0();
void func_0026593C(char *dst, u8 *fmt, s32 a, s32 b, s32 c);

s32 func_auto_0040A960(O01Item *item) {
    register s32 x asm("$18");
    register s32 y asm("$19");
    register s32 z asm("$17");
    register char *buf asm("$16");
    x = D_800E28BC->unkC;
    y = D_800E28BC->unk10;
    z = D_800E28BC->unk14;
    buf = item->unk14[D_801462C8.lang].buf;
    func_0026593C(buf + (func_auto_00442EE0() - 9), D_auto_800ED404, z, y, x);
    return 0;
}
