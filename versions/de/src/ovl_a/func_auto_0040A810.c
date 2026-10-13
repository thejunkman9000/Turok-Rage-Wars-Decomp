#include "o01_types.h"

extern s32 D_80153774;
extern O01Text D_800D77F8;
extern O01Text D_800D7800;
extern u8 D_8015372B;
extern u8 D_80153724[];

s32 func_auto_0040A810(O01Item *item) {
    s32 n = 8;
    u8 *p, *q, *end, *w;
    u8 *dst;
    s32 i;
    u8 c;
    if (D_80153774 != 0) {
        item->unk14 = &D_800D77F8;
    } else {
        item->unk14 = &D_800D7800;
        p = &D_8015372B;
        if (*p-- != 0x20) goto done;
        for (;;) {
            if (n == 0) goto done;
            n--;
            if (*p-- != 0x20) goto done;
        }
done:
        dst = (u8 *)item->unk14->buf;
        dst += 12;
        c = 0x20;
        q = dst + 7;
        for (i = 7; i >= 0; i--) {
            *q-- = c;
        }
        end = dst + 8;
        dst = end - n;
        for (i = 0; i < n; i++) {
            *dst++ = D_80153724[i];
        }
    }
    return 0;
}
