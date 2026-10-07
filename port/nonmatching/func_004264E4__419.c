#include "o04_types.h"
typedef struct { u8 pad0[0x78]; u8 unk78; u8 pad79[0x91 - 0x79]; u8 unk91; u8 pad92[0x96 - 0x92]; } O04Ent96x;
typedef struct { u8 pad0[2]; u16 unk2; u8 pad4[0x1C - 4]; } O04Nav2;
typedef O04Sub14 O04Hdl;
extern O04ModeS4690 *D_800E4690;
extern O04Ent96x D_80146398[];
extern O04Nav2 D_800E4694[];
extern s32 D_80154024;
extern u8 D_801462D5;
void *func_00252FFC(s32 a);
s32 func_0041B690(s32 a, s32 b);
void func_0041B768(s32 a, s32 b, s32 c);
void func_002656A8(void *p, s32 a, s32 b);
O04Hdl *func_0040ECB0(s32 a, s32 b);
void *func_00419ED4(s32 a, s32 b);
void func_0040E958(void *p, s32 a);
void func_004271E8(void);
void func_004280F0(void);
void func_0042829C(void);
void func_0043C3F0(void *p, s32 a, s32 b, s32 c, s32 d);
void func_00427B98(void);
void func_004221A0(void);
void func_004284E0(void);
void func_004285EC(void);
void func_004283F4(void);
void func_00427CE8(void);
void func_0025DF54(s32 a);
s32 func_004264E4(s32 a) {
    s32 s0;
    s32 *p;
    O04Hdl *h;
    s32 t;
    D_800E4690 = func_00252FFC(0xA80);
    D_800E4690->unk970 = a;
    D_800E4690->unk974 = func_0041B690(a, 4);
    func_0041B768(a, 0, 0x13E);
    func_0041B768(a, 1, 0x13E);
    func_0041B768(a, 2, 0x13E);
    func_0041B768(a, 3, 0x13E);
    for (s0 = 0; s0 < 0x24; s0++) {
        func_002656A8(D_800E4690->unkA74, s0, 0);
        func_002656A8(D_800E4690->unkA79, s0, 0);
    }
    D_800E4690->unk988 = 1;
    D_800E4690->unk98C = 4;
    D_800E4690->unk978 = func_0040ECB0(a, 0x145);
    D_800E4690->unk978->unk14 = D_800E4690->unk978->unk14 - D_800E4690->unk978->unk18;
    t = D_800E4690->unk978->unk18 / 4;
    D_800E4690->u97C.w = t;
    D_800E4690->unk978->unk14 = D_800E4690->unk978->unk14 + (D_800E4690->unk978->unk18 - (t << 2));
    D_800E4690->unk980 = func_0040ECB0(a, 0x144);
    D_800E4690->unk980->unk14 = D_800E4690->unk980->unk14 + D_800E4690->unk980->unk18;
    t = D_800E4690->unk980->unk18 / 4;
    D_800E4690->u984.w = t;
    D_800E4690->unk980->unk14 = D_800E4690->unk980->unk14 - (D_800E4690->unk980->unk18 - (t << 2));
    s0 = 0;
    D_800E4690->unk990 = func_00419ED4(0x141, 0x6E);
    D_800E4690->unk994 = h = func_0040ECB0(a, 0x13F);
    func_0040E958(h, s0);
    D_800E4690->unk998 = (O04Sub38 *)func_0040ECB0(a, 0x154);
    D_800E4690->unk99C = func_0040ECB0(a, 0x155);
    D_800E4690->unkA5C = 0;
    for (; s0 < 4; s0++) {
        if (D_80146398[s0].unk78 == 1) {
            D_800E4690->unkA5C = s0;
            break;
        }
    }
    for (s0 = 0; s0 < 8; s0++) {
        if (D_80146398[s0].unk91 == 1) {
            D_80146398[s0].unk78 = 0;
            D_80146398[s0].unk91 = 0;
        }
    }
    func_004271E8();
    func_004280F0();
    D_800E4690->unkA48 = (O04Sub10 *)func_0040ECB0(a, D_800E4694[D_800E4690->unkA44].unk2);
    func_0042829C();
    p = &D_80154024;
    p[0] = 0;
    p[-1] = -1;
    func_0043C3F0(D_800E4690, 0x67, 0, 0, 0);
    h = func_0040ECB0(a, 0x151);
    D_800E4690->unkA50 = (O04Sub10 *)h;
    h->unk10 = 0xFF;
    D_800E4690->unkA4C = 0;
    if (D_801462D5 < 5 && D_801462D5 >= 3) {
        D_800E4690->unkA4C = 1;
        func_00427B98();
    }
    D_800E4690->unkA68 = 0;
    D_800E4690->unkA6C = 0;
    D_800E4690->unkA70 = -1;
    if (D_801462D5 == 1 || D_801462D5 == 3 || D_801462D5 == 4) {
        D_800E4690->unkA60 = (O04Sub10 *)func_0040ECB0(a, 0x13D);
        func_004221A0();
        D_800E4690->unkA64 = (O04Sub10 *)func_0040ECB0(a, 0x147);
        func_0040ECB0(a, 0x148)->unk10 = 0x6E;
    }
    switch (D_801462D5) {
    case 2:
        func_004283F4();
        break;
    case 1:
        func_004284E0();
        break;
    case 3:
        func_004285EC();
        break;
    }
    if (D_801462D5 != 2) {
        func_00427CE8();
    }
    func_0025DF54(0xE78);
    return 0;
}
