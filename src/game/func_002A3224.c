#include "b23_types.h"

extern s32 D_800D0E54;
extern s32 D_800D2C90[];
extern u8 D_8010A248[];
extern u8 D_800CAF30[];
extern u8 D_0043C500[];

void func_002551C8(void *p);
void func_002538A8(s32 a);
void func_004143E0();
void func_002A26F8(s32 a);
void func_00298FA0(s32 a, void *b);
void func_0040FC14(void *p);
void func_0041B660();
void func_0041991C();
void func_0041A480();
void func_0041B160();
void func_00419EA4();
void func_0041A5D0();
void func_0041AC10();
void func_002A2960();
void func_002A33F8(f32 v);
void func_002A3410(s32 a);
void func_002A3358();
void func_002A33BC(s32 a);

void func_002A3224(void) {
    func_002551C8(D_8010A248);
    func_002538A8(0);
    func_004143E0();
    func_002A26F8(0x3000);
    func_00298FA0(0x23, D_0043C500);
    func_0040FC14(D_800CAF30);
    func_0041B660();
    func_0041991C();
    func_0041A480();
    func_0041B160();
    func_00419EA4();
    func_0041A5D0();
    func_0041AC10();
    func_002A2960();
    D_800D0E54 = 0x3C;
    func_002A33F8(0.0f);
    func_002A3410(1);
    D_800D2C90[2] = 1;
    func_002A3358();
    D_800D2C90[0] = 0;
    func_002A33BC(2);
}
