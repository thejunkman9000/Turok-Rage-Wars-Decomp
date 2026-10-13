#include "o01_types.h"
#include "veu3n06_types.h"



extern s32 D_auto_8015D4CC;
extern u8 D_auto_800E41F4[];
extern O01Text D_auto_800E25E4[];
extern u8 D_auto_800ED3FC[];
s32 func_auto_00442EE0();
void func_00265904(char *dst, u8 *fmt, s32 a);

s32 func_auto_0040A61C(O01Item *item, O01Owner *own) {
    char *buf;
    s32 v;
    O01Text *t;
    if (D_auto_8015D4CC != 0) {
        item->unk14 = (O01Text *)D_auto_800E41F4;
    } else {
        v = own->unk20->unk4;
        t = D_auto_800E25E4;
        item->unk14 = t;
        buf = t[D_801462C8.lang].buf;
        func_00265904(buf + (func_auto_00442EE0() - 1), D_auto_800ED3FC, v + 1);
    }
    return 0;
}
