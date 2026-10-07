#include "o04_types.h"
extern O04ModeS4690 *D_800E4690;
void func_0040E958(O04Sub10 *p, s32 a);
void func_00428388(void) {
    D_800E4690->unkA64->unk10 = 0xFF;
    D_800E4690->unkA60->unk10 = 0xFF;
    func_0040E958(D_800E4690->unkA60, 1);
    func_0040E958(D_800E4690->unkA64, 1);
    D_800E4690->unkA68 = 0;
}
