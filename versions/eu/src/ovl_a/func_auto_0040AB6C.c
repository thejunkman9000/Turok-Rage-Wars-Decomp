#include "o01_types.h"
#include "veu3n06_types.h"

extern s32 D_auto_8015D4E4;
extern O01Text D_auto_800E2984;
extern O01Text D_auto_800E29A4[];
extern u8 D_auto_8015D49B;
extern u8 D_auto_8015D494[];
s32 func_auto_00442EE0();

s32 func_auto_0040AB6C(O01Item *item) {
    s32 n = 8;
    u8 *p, *q, *end, *w;
    u8 *dst;
    s32 i;
    u8 c;
    if (D_auto_8015D4E4 != 0) {
        item->unk14 = &D_auto_800E2984;
    } else {
        item->unk14 = D_auto_800E29A4;
        p = &D_auto_8015D49B;
        if (*p-- != 0x20) goto done;
        for (;;) {
            if (n == 0) goto done;
            n--;
            if (*p-- != 0x20) goto done;
        }
done:
        dst = (u8 *)item->unk14[D_801462C8.lang].buf;
        dst += func_auto_00442EE0() - 8;
        c = 0x20;
        q = dst + 7;
        for (i = 7; i >= 0; i--) {
            *q-- = c;
        }
        end = dst + 8;
        dst = end - n;
        for (i = 0; i < n; i++) {
            *dst++ = D_auto_8015D494[i];
        }
    }
    return 0;
}
