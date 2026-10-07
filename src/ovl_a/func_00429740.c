#include "o04_types.h"
extern O04S4EF0 *D_800E4EF0;
extern O04Cfg D_801462C8[];
void func_002A2B24(s32 a, s32 b);
s32 func_0041EBC0(void);
void func_0041AD90(s32 a, s32 b);
s32 func_0041E790(void);
void func_00429740(void) {
    s32 b;
    func_002A2B24(D_800E4EF0->unk24, D_801462C8->s25);
    func_002A2B24(D_800E4EF0->unk28, D_801462C8->s24);
    func_002A2B24(D_800E4EF0->unk2C, D_801462C8->s26);
    func_002A2B24(D_800E4EF0->unk30, D_801462C8->s27);
    b = func_0041EBC0();
    if (D_800E4EF0->unk38 < b) {
        b = D_800E4EF0->unk38;
    }
    if (b == 0) {
        b = D_800E4EF0->unk3C;
    }
    func_002A2B24(D_800E4EF0->unk34, b);
    func_0041AD90(D_800E4EF0->unk1C, D_801462C8->u28);
    func_0041AD90(D_800E4EF0->unk20, func_0041E790());
}
