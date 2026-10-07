#include "o01_types.h"

extern O01Cfg *D_800E28BC;
extern u8 D_800E0DB4[];
s32 func_00442158();
void func_0026593C(char *dst, u8 *fmt, s32 a, s32 b, s32 c);

s32 func_0040A640(O01Item *item) {
    register s32 x asm("$18");
    register s32 y asm("$19");
    register s32 z asm("$17");
    register char *buf asm("$16");
    x = D_800E28BC->unkC;
    y = D_800E28BC->unk10;
    z = D_800E28BC->unk14;
    buf = item->unk14->buf;
    func_0026593C(buf + (func_00442158() - 9), D_800E0DB4, z, y, x);
    return 0;
}
