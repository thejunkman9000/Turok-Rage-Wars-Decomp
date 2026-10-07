#include "o04_types.h"
typedef struct { u8 pad0[2]; u16 unk2; u8 pad4[8]; s32 unkC; s32 unk10; s32 unk14; s32 unk18; } O04Nav;
extern O04ModeS4690 *D_800E4690;
extern O04Nav D_800E4694[];
extern O04Cfg D_801462C8[];
void func_0029A73C(void);
s32 func_00265670(void *p, s32 a);
void func_0025DF54(s32 a);
void *func_0040ECB0(s32 a, s32 b);
void func_0042829C(void);
void func_00428388(void);
void func_00427CE8(void);
void func_00427B98(void);
s32 func_00428B94(s32 a, s32 b, s32 c, s32 d) {
    s32 s0;
    s32 s1;
    func_0029A73C();
    if (d != 1) {
        return 0;
    }
    s0 = D_800E4694[D_800E4690->unkA44].unk18;
    if (s0 == -1) {
        return 0;
    }
    s1 = func_00265670(D_800E4690->unkA74, s0);
    if (s1 != d) {
        return 0;
    }
    func_0025DF54(0xE7D);
    if (func_00265670(D_800E4690->unkA79, D_800E4690->unkA44) == s1) {
        D_800E4690->unkA48->unk10 = 0x46;
    } else {
        D_800E4690->unkA48->unk10 = 0xAA;
    }
    D_800E4690->unkA44 = s0;
    D_800E4690->unkA48 = func_0040ECB0(a, D_800E4694[s0].unk2);
    func_0042829C();
    if (D_801462C8->unkD != 2) {
        func_00428388();
        D_800E4690->unkA6C = 0;
        func_00427CE8();
    }
    if (D_801462C8->unkD == 4) {
        func_00427B98();
    }
    return 0;
}
