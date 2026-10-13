#include "o06_types.h"
typedef struct { u8 pad[0x14]; void *unk14; } O06A;
extern u16 D_auto_8015221C;
extern s32 func_auto_00442EE0(O06A *a);
extern void func_00265904(s32 a, void *b, s32 c);
extern u8 D_auto_800E2204[];
extern u8 D_auto_800E2214[];
extern s32 D_auto_800E2224[];
extern u8 D_auto_800EEDD0[];
s32 func_auto_0044594C(O06A *a) {
    u16 *g = &D_auto_8015221C;
    u32 h = *g >> 4;
    if (h == 0) {
        a->unk14 = D_auto_800E2204;
    } else if (h == 0x10) {
        a->unk14 = D_auto_800E2214;
    } else {
        s32 s, *t = D_auto_800E2224;
        a->unk14 = t;
        s = t[((u8 *)g)[0x56D]];
        func_00265904(s - 2 + func_auto_00442EE0(a), D_auto_800EEDD0, h);
    }
    return 0;
}
