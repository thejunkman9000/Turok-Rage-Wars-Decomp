#include "o01_types.h"
#include "veu3n06_types.h"

extern s32 D_auto_8015D4EC;
extern s32 D_auto_8015D4C0;
extern s32 D_auto_8015D4CC;
extern s32 D_auto_800EEEE8;
extern O01Text D_auto_800E26F4;
extern O01Text D_auto_800E2704;
extern O01Text D_auto_800E27E4[];
extern u8 D_auto_800ED3FC[];
s32 func_auto_00442EE0();
void func_00265904(char *dst, u8 *fmt, s32 a);

s32 func_auto_0040A550(O01Item *item) {
    s32 v;
    char *buf;
    O01Text *t;
    if (D_auto_8015D4EC != 0) {
        if (D_auto_8015D4C0 != 0) {
            item->unk14 = &D_auto_800E26F4;
        } else {
            goto chk;
        }
    } else {
        if (D_auto_8015D4C0 != 0) {
            item->unk14 = &D_auto_800E2704;
        } else {
            goto chk;
        }
    }
    goto done;
chk:
    if (D_auto_8015D4CC != 0) {
        t = D_auto_800E27E4;
        item->unk14 = t;
        v = D_auto_800EEEE8;
        buf = t[D_801462C8.lang].buf;
        func_00265904(buf + (func_auto_00442EE0() - 1), D_auto_800ED3FC, v + 1);
    }
done:
    return 0;
}
