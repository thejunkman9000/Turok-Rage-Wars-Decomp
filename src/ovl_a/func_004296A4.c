#include "o04_types.h"
extern O04S4EF0 *D_800E4EF0;
extern O04Cfg D_801462C8[];
s32 func_002A2B18(s32 a);
s32 func_0041AD84(s32 a);
void func_004296A4(void) {
    D_801462C8->s24 = func_002A2B18(D_800E4EF0->unk28);
    D_801462C8->s25 = func_002A2B18(D_800E4EF0->unk24);
    D_801462C8->s26 = func_002A2B18(D_800E4EF0->unk2C);
    D_801462C8->s27 = func_002A2B18(D_800E4EF0->unk30);
    D_801462C8->u28 = func_0041AD84(D_800E4EF0->unk1C);
}
