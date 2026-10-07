#include "o04_types.h"
extern O04ModeF60 *D_800E4F60;
void func_0029A73C(void);
s32 func_0042B474(s32 a);
s32 func_0042B334(s32 a);
void func_0025DF54(s32 a);
void func_0042B4C4(void);
void func_0042AB70(void);
void func_0040E958(void *p, s32 a);
void func_00439E60(void *p, s32 a);
s32 func_0042BAE4(s32 a, s32 b, s32 c, s32 d) {
    s32 a0;
    s32 r;
    func_0029A73C();
    if (d != 1) {
        return 0;
    }
    a0 = 0;
    if (D_800E4F60->unk434 != 3) {
        a0 = 1;
        if (D_800E4F60->unk434 == 0) {
            if (D_800E4F60->unk438 >= 0xB) {
                D_800E4F60->unk438 = 0x15 - D_800E4F60->unk438;
            } else {
                D_800E4F60->unk434 = 1;
            }
        } else {
            D_800E4F60->unk434 = D_800E4F60->unk434 + 1;
        }
    }
    if (a0 == 1) {
        func_0025DF54(0xE7D);
        func_0042B4C4();
        D_800E4F60->unk45C = 0;
        D_800E4F60->unk464 = 0;
        D_800E4F60->unk43C->unk10 = 0x41;
        r = func_0042B334(func_0042B474(D_800E4F60->unk434));
        if (D_800E4F60->unk438 >= r) {
            D_800E4F60->unk438 = r - 1;
        }
        func_0042AB70();
        if (D_800E4F60->unk438 == 0) {
            func_00439E60(D_800E4F60->unk308, D_800E4F60->unk434 + 0xEA6);
            func_0040E958(D_800E4F60->unk448, 1);
            D_800E4F60->unk448->unk14 = D_800E4F60->unk434 * 0x22 + 0x7C;
        }
    }
    return 0;
}
