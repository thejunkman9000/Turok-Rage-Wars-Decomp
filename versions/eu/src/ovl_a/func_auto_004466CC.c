#include "o06_types.h"
typedef struct { u8 pad[0x14]; void *unk14; } O06A;
extern s32 D_auto_800F2A88;
extern u8 D_auto_80150F80[];
extern u8 D_auto_800E4144[];
extern s32 D_auto_800E4154[];
extern u8 D_auto_800EEE20[];
extern s32 func_auto_00442EE0(O06A *a);
extern void func_00265904(s32 a, void *b, s32 c);
s32 func_auto_004466CC(O06A *a) {
    if (D_auto_800F2A88 == 0) {
        a->unk14 = D_auto_800E4144;
    } else {
        s32 s, *t = D_auto_800E4154;
        a->unk14 = t;
        s = t[D_auto_80150F80[0x1809]];
        func_00265904(s - 2 + func_auto_00442EE0(a), D_auto_800EEE20, D_auto_800F2A88);
    }
    return 0;
}
