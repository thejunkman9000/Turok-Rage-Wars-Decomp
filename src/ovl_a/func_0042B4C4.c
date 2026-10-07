#include "o04_types.h"
extern O04ModeF60 *D_800E4F60;
void func_0040E958(O04Sub10 *p, s32 a);
void func_0042B4C4(void) {
    D_800E4F60->unk454->unk10 = 0xFF;
    D_800E4F60->unk450->unk10 = 0xFF;
    func_0040E958(D_800E4F60->unk450, 1);
    func_0040E958(D_800E4F60->unk454, 1);
    D_800E4F60->unk46C = 0;
}
