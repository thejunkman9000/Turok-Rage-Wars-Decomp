#include "o06_types.h"
typedef struct { u8 pad[0x14]; void *unk14; } O06A;
typedef struct { u8 pad[0x10]; u32 unk10; u8 pad2[0x56D]; u8 unk581; } O06G;
extern O06G D_auto_80152208;
extern s32 func_0025471C(void);
extern void func_0025470C(s32 a);
extern s32 func_auto_00442EE0(O06A *a);
extern void func_00265904(s32 a, void *b, s32 c);
extern u8 D_auto_800E22E4[];
extern s32 D_auto_800E22F4[];
extern u8 D_auto_800EEDD8[];
s32 func_auto_00445EBC(O06A *a) {
    O06G *g = &D_auto_80152208;
    u32 h = g->unk10 >> 4;
    func_0025470C(func_0025471C() + 2);
    if (h == 0) {
        a->unk14 = D_auto_800E22E4;
    } else {
        s32 s, *t = D_auto_800E22F4;
        a->unk14 = t;
        s = t[g->unk581];
        func_00265904(s - 4 + func_auto_00442EE0(a), D_auto_800EEDD8, h);
    }
    return 0;
}
