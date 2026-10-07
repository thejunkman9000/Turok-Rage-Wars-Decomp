#include "o04_types.h"
extern O04ModeS4690 *D_800E4690;
extern s32 D_80154024;
extern s32 D_80154020;
extern u8 D_801462D5;
extern f32 D_800E19D4;
extern f32 D_800E19D8;
extern f32 D_800E19DC;
extern f32 D_800E19E0;
void func_0029A73C(void);
void func_00299368(s32 a);
void func_0025DF54(s32 a);
void func_0040E958(void *p, s32 a);
void func_00419FD8(void *p, s32 a);
s32 func_00419FB8(void *p);
void func_00419FA4(void *p);
void func_002A3358(void);
void func_00428388(void);
void func_004275B4(void);
void func_0042EB68(s32 a);
void func_004271E8(void);
f32 cosf(f32 x);
s32 func_00426AF8(s32 a, s32 b, s32 c) {
    s32 *p = &D_80154024;
    s32 k;
    s32 t;
    f32 f;
    if (p[0] == 1) {
        p[0] = 0;
        if (p[-1] != -1) {
            D_800E4690->unkA50->unk10 = 0x5A;
            func_0029A73C();
            func_00299368(p[-1]);
            return 0;
        }
        D_800E4690->unkA50->unk10 = 0xFF;
        D_800E4690->unk988 = 9;
    }
    switch (D_800E4690->unk988) {
    case 1:
        D_800E4690->unk978->unk14 = D_800E4690->unk978->unk14 + D_800E4690->unk97E;
        D_800E4690->unk980->unk14 = D_800E4690->unk980->unk14 - D_800E4690->unk986;
        D_800E4690->unk98C = D_800E4690->unk98C - 1;
        if (D_800E4690->unk98C <= 0) {
            func_0025DF54(0xE79);
            func_0040E958(D_800E4690->unk994, 1);
            func_00419FD8(D_800E4690->unk990, 4);
            D_800E4690->unk988 = 4;
            D_800E4690->unk98C = 4;
        }
        break;
    case 2:
        D_800E4690->unk978->unk14 = D_800E4690->unk978->unk14 - D_800E4690->unk97E;
        D_800E4690->unk980->unk14 = D_800E4690->unk980->unk14 + D_800E4690->unk986;
        D_800E4690->unk98C = D_800E4690->unk98C - 1;
        if (D_800E4690->unk98C <= 0) {
            D_800E4690->unk988 = 3;
            func_0029A73C();
            func_00299368(D_801462D5 == 4 ? 3 : 7);
            return 0;
        }
        break;
    case 3:
        if (D_800E4690->unkA58 == 0) {
            func_002A3358();
            D_800E4690->unkA58 = 1;
        }
        break;
    case 4:
        k = D_800E4690->unk98C;
        D_800E4690->unk98C = (k - 1 < 0) ? 0 : k - 1;
        if (D_800E4690->unk98C <= 0) {
            if (func_00419FB8(D_800E4690->unk990)) {
                func_00419FA4(D_800E4690->unk990);
                D_800E4690->unk988 = 3;
            }
        }
        break;
    case 5:
        func_0025DF54(0xE78);
        func_0040E958(D_800E4690->unk994, 0);
        if (D_801462D5 == 1 || (D_801462D5 != 0 && D_801462D5 < 5 && D_801462D5 >= 3)) {
            func_00428388();
        }
        func_004275B4();
        D_800E4690->unk988 = 2;
        D_800E4690->unk98C = 4;
        break;
    case 8:
        D_800E4690->unk988 = 3;
        func_004275B4();
        func_0042EB68(0xB);
        return 0;
    case 9:
        D_800E4690->unk988 = 3;
        func_004271E8();
        break;
    }
    if (D_800E4690->unk988 == 3) {
        t = D_800E4690->unkA54 + c;
        D_800E4690->unkA54 = t;
        if (D_80154020 == -1) {
            f = cosf((f32)t * D_800E19D4) * D_800E19D8 + D_800E19DC;
            D_800E4690->unkA48->unk10 = (u32)f;
        }
    }
    return 0;
}
