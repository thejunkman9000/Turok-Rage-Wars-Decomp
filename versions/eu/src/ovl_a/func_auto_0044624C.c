#include "o06_types.h"
typedef struct { u8 pad[0x14]; s32 *unk14; } O06A;
extern s32 func_auto_00442EE0(O06A *a);
extern void func_00265904(s32 a, void *b, s32 c);
extern u8 D_auto_80152222[];
extern u8 D_auto_800E4124[];
extern u8 D_auto_800E4114[];
extern u8 D_auto_800E4104[];
extern s32 D_auto_800E4134[];
extern u8 D_auto_800EEE10[];
extern u8 D_auto_800EEE18[];
s32 func_auto_0044624C(O06A *a) {
    s32 n, s;
    n = ((s32)D_auto_80152222[0] - 0x80) / 8;
    if (n == 0) {
        a->unk14 = (s32 *)D_auto_800E4124;
    } else if (n == 0xF) {
        a->unk14 = (s32 *)D_auto_800E4114;
    } else if (n == -0x10) {
        a->unk14 = (s32 *)D_auto_800E4104;
    } else if (n > 0) {
        a->unk14 = D_auto_800E4134;
        s = a->unk14[D_auto_80152222[0x567]];
        func_00265904(s - 4 + func_auto_00442EE0(a), D_auto_800EEE10, n);
    } else {
        a->unk14 = D_auto_800E4134;
        s = a->unk14[D_auto_80152222[0x567]];
        func_00265904(s - 4 + func_auto_00442EE0(a), D_auto_800EEE18, n);
    }
    return 0;
}
