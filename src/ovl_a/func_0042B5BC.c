#include "o04_types.h"
extern O04ModeF60 *D_800E4F60;
extern s32 D_80154020;
void func_0029A73C(void);
void func_0042A994(s32 a);
void func_0040E958(void *p, s32 a);
void func_0025DF54(s32 a);
s32 func_0042B5BC(s32 a, s32 b, u32 c, s32 d) {
    if (D_800E4F60->state != 3) {
        return 0;
    }
    if (D_80154020 != -1) {
        return 0;
    }
    if ((c >> 16) != 3) {
        return 0;
    }
    if (d != 0) {
        return 0;
    }
    func_0029A73C();
    D_800E4F60->state = 8;
    func_0042A994(0x41);
    func_0040E958(D_800E4F60->unk440, 0);
    func_0040E958(D_800E4F60->unk444, 0);
    func_0040E958(D_800E4F60->unk448, 0);
    func_0040E958(D_800E4F60->unk3EC, 0);
    func_0040E958(D_800E4F60->unk3F0, 0);
    D_800E4F60->unk44C->unk10 = 0x5A;
    func_0025DF54(0xE7C);
    return 0;
}
