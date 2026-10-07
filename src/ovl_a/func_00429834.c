#include "o04_types.h"
typedef struct {
    u8 pad0[0x20]; s32 unk20; u8 pad24[0x34 - 0x24]; s32 unk34;
} O04S4EF0b;
extern O04S4EF0b *D_800E4EF0;
s32 func_0041AD84(s32 a);
s32 func_002A2B18(s32 a);
void func_0041EAE0(void);
s32 func_0041EBC0(void);
void func_0041E88C(s32 a, s32 b);
void func_00429834(s32 a) {
    s32 s1;
    s32 s0;
    s1 = func_0041AD84(D_800E4EF0->unk20);
    s0 = func_002A2B18(D_800E4EF0->unk34);
    if (s0 <= 0) {
        func_0041EAE0();
    } else if (s0 != func_0041EBC0() || a == 1) {
        func_0041EAE0();
        func_0041E88C(s0, s1);
    }
}
