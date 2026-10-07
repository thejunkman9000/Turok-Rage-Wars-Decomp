#include "o01_types.h"

extern O01Cfg *D_800E28BC;
extern u8 D_800E0DB4[];
s32 func_00442158();
void func_0026593C(char *dst, u8 *fmt, s32 a, s32 b, s32 c);

s32 func_0040A640(O01Item *item) {
    s32 x = D_800E28BC->unkC;
    s32 y = D_800E28BC->unk10;
    s32 z = D_800E28BC->unk14;
    char *buf = item->unk14->buf;
    func_0026593C(buf + (func_00442158() - 9), D_800E0DB4, z, y, x);
    return 0;
}
