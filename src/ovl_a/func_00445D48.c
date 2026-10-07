#include "o06_types.h"
typedef struct { u8 pad[0x14]; void *unk14; } O06A;
extern s32 func_00442158(O06A *a);
extern void func_00265904(s32 a, void *b, s32 c);
extern u8 D_801462E1;
extern u8 D_800D7DD0[];
extern u8 D_800D7DCC[];
extern u8 D_800D7DC8[];
extern s32 D_800D7DD4[];
extern u8 D_800E27E0[];
extern u8 D_800E27E8[];
s32 func_00445D48(O06A *a) {
    s32 n, s;
    n = ((s32)D_801462E1 - 0x80) / 8;
    if (n == 0) {
        a->unk14 = D_800D7DD0;
    } else if (n == 0xF) {
        a->unk14 = D_800D7DCC;
    } else if (n == -0x10) {
        a->unk14 = D_800D7DC8;
    } else if (n > 0) {
        s = D_800D7DD4[0];
        a->unk14 = D_800D7DD4;
        func_00265904(s - 4 + func_00442158(a), D_800E27E0, n);
    } else {
        s = D_800D7DD4[0];
        a->unk14 = D_800D7DD4;
        func_00265904(s - 4 + func_00442158(a), D_800E27E8, n);
    }
    return 0;
}
