#include "o01_types.h"
typedef struct { u8 pad[0x1C]; s32 unk1C; u8 pad2[2]; s16 unk22; } O01CfgB;
typedef struct { u8 pad[0x14]; char **unk14; } O01ItemB;
extern O01CfgB *D_auto_800EEEDC;
extern u8 D_auto_800ED3F4[];
extern u8 D_auto_80152789;
s32 func_auto_00442EE0();
void func_00265904(char *dst, u8 *fmt, s32 a);

s32 func_auto_0040A85C(O01ItemB *item) {
    s32 v = D_auto_800EEEDC->unk1C >> 8;
    char *buf = item->unk14[D_auto_80152789];
    func_00265904(buf + (func_auto_00442EE0() - 3), D_auto_800ED3F4, v);
    return 0;
}
