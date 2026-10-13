#include "o04_types.h"
extern O04S4EF0 *D_800E4EF0;
extern s32 D_80154028;
extern s32 D_800D74C0[];
extern s32 D_800D74C4[];
extern s32 D_800D74C8[];
extern s32 D_800D74CC[];
extern s32 D_800D74D0[];
extern s32 D_800D74D4[];
extern s32 D_800D74D8[];
void *func_00252FFC(s32 a);
void func_0043C3F0(void *p, s32 a, s32 b, s32 c, s32 d);
s32 func_0041EB34(void);
void *func_0040ECB0(s32 a, s32 b);
void func_0040E9D0(void *p, s32 a);
s32 func_002A2990(s32 a, s32 b, s32 c, s32 d, s32 e);
s32 func_0041AC40(s32 a, s32 b);
void func_0041ADB4(s32 a, s32 b);
void func_0041B190(s32 a);
void func_00429740(void);
void func_00429834(s32 a);
s32 func_auto_004291D0(s32 a) {
    s32 s0;
    s32 t;
    D_800E4EF0 = func_00252FFC(0x40);
    func_0043C3F0(D_800E4EF0, 0x67, 0, 0, 0);
    D_800E4EF0->unk38 = func_0041EB34();
    switch (D_80154028) {
    case 1:
        func_0040E9D0(func_0040ECB0(a, 0x35B), 1);
        func_0040E9D0(func_0040ECB0(a, 0x35F), 1);
        break;
    case 0:
        func_0040E9D0(func_0040ECB0(a, 0x361), 1);
        func_0040E9D0(func_0040ECB0(a, 0x35F), 1);
        break;
    case 2:
    case 3:
        func_0040E9D0(func_0040ECB0(a, 0x35B), 1);
        func_0040E9D0(func_0040ECB0(a, 0x361), 1);
        break;
    }
    s0 = 1;
    D_800E4EF0->unk24 = func_002A2990(0x35F, 0x360, 0, 0x64, s0);
    D_800E4EF0->unk28 = func_002A2990(0x35D, 0x35E, 0, 0x64, s0);
    D_800E4EF0->unk2C = func_002A2990(0x35B, 0x35C, 0, 0x64, s0);
    D_800E4EF0->unk30 = func_002A2990(0x361, 0x362, 0, 0x64, s0);
    D_800E4EF0->unk3C = 0;
    if (D_800E4EF0->unk38 == 3) {
        D_800E4EF0->unk3C = s0;
    }
    D_800E4EF0->unk34 = func_002A2990(0x368, 0x369, D_800E4EF0->unk3C, D_800E4EF0->unk38, s0);
    t = func_0041AC40(0x363, 0x364);
    D_800E4EF0->unk1C = t;
    func_0041ADB4(t, D_800D74C0[0]);
    func_0041ADB4(D_800E4EF0->unk1C, D_800D74C4[0]);
    t = func_0041AC40(0x36A, 0x36B);
    D_800E4EF0->unk20 = t;
    func_0041ADB4(t, D_800D74C8[0]);
    func_0041ADB4(D_800E4EF0->unk20, D_800D74CC[0]);
    func_0041ADB4(D_800E4EF0->unk20, D_800D74D0[0]);
    func_0041ADB4(D_800E4EF0->unk20, D_800D74D4[0]);
    func_0041ADB4(D_800E4EF0->unk20, D_800D74D8[0]);
    func_0041B190(0x365);
    func_0041B190(0x366);
    func_0041B190(0x367);
    func_00429740();
    func_00429834(0);
    func_00429740();
    return 0;
}
