#include "o01_types.h"

extern s32 D_80153774;
extern O01Text D_800D77F8;
extern O01Text D_800D7800;
extern u8 D_8015372B;
extern u8 D_80153724[];
s32 func_00442158();

s32 func_0040A83C(O01Item *item) {
    s32 n = 8;
    u8 *p;
    u8 *dst;
    s32 i;
    if (D_80153774 != 0) {
        item->unk14 = &D_800D77F8;
    } else {
        item->unk14 = &D_800D7800;
        p = &D_8015372B;
        if (*p-- == 0x20) {
            for (;;) {
                if (n == 0) {
                    break;
                }
                n--;
                if (*p-- != 0x20) {
                    break;
                }
            }
        }
        dst = (u8 *)item->unk14->buf;
        dst += func_00442158() - 8;
        p = dst + 7;
        for (i = 7; i >= 0; i--) {
            *p-- = 0x20;
        }
        dst += 8;
        dst -= n;
        for (i = 0; i < n; i++) {
            *dst++ = D_80153724[i];
        }
    }
    return 0;
}
