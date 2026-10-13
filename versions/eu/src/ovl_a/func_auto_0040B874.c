#include "o01_types.h"
#include "veu3n06_types.h"

extern s32 D_auto_8015D4CC;
extern s32 D_auto_800EEEE8;
extern s32 D_auto_8015D4A4;
extern O01Text D_auto_800E2F84;
extern O01Text D_auto_800E2FB4[];
extern u8 D_auto_800ED41C[];
s32 func_auto_00442EE0();
void func_00265904(char *dst, u8 *fmt, s32 a);

s32 func_auto_0040B874(O01Item *item, O01Owner *own) {
    s32 v;
    char *buf;
    O01Text *t;
    if (D_auto_8015D4CC != 0) {
        v = D_auto_800EEEE8;
    } else {
        v = own->unk20->unk4;
    }
    if (D_auto_8015D4A4 != 0) {
        item->unk14 = &D_auto_800E2F84;
    } else {
        t = D_auto_800E2FB4;
        item->unk14 = t;
        buf = t[D_801462C8.lang].buf;
        func_00265904(buf + (func_auto_00442EE0() - 2), D_auto_800ED41C, v + 1);
    }
    return 0;
}
