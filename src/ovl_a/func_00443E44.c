#include "o06_types.h"
typedef struct { u8 pad[0x58]; u32 unk58; u8 pad2[0xC4]; u32 unk120; u8 pad3[0x9C]; u32 unk1C0; u8 pad4[0x4C]; u32 unk210; u8 pad5[0x24]; u32 unk238; u8 pad6[0x24]; u32 unk260; } O06B;
typedef struct { u8 pad[0xC]; O06B *unkC; u8 pad2[0xC]; void *unk1C; } O06A;
extern s32 func_0022A590(void *a, void *b);
extern void func_00264790(s32 a);
extern void func_00404E28(s32 a);
extern s32 D_800E28C0;
extern s32 D_8015375C;
extern u8 D_80145040[];
extern s32 D_801468F4[];
void func_00443E44(O06A *a) {
    s32 n;
    a->unkC->unk238 |= 0x1800000;
    a->unkC->unk260 |= 0x1800000;
    a->unkC->unk1C0 &= ~0x1800000;
    a->unkC->unk58 &= ~0x1800000;
    a->unkC->unk210 &= ~0x1800000;
    D_8015375C = 0;
    D_800E28C0 = 0;
    n = 0;
    if (D_801468F4[0]) a->unkC->unk120 |= 0x1000000; else a->unkC->unk120 &= ~0x1000000;
    if (a->unk1C) n = func_0022A590(D_80145040, a->unk1C);
    func_00264790(n);
    func_00404E28(n);
}
