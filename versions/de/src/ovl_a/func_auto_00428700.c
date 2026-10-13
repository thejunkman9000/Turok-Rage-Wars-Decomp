#include "o04_types.h"
extern O04ModeS4690 *D_800E4690;
s32 func_0040ECB0(s32 a, s32 b);
void func_0040E958(s32 a, s32 b);
void func_auto_00428700(void) {
    s32 i;
    s32 id = 0;
    for (i = 0; i < 5; i++) {
        switch (i) {
        case 0:
            id = 0x147;
            break;
        case 1:
            id = 0x14A;
            break;
        case 2:
            id = 0x14B;
            break;
        case 3:
            id = 0x14C;
            break;
        case 4:
            id = 0x14D;
            break;
        }
        func_0040E958(func_0040ECB0(func_0040ECB0(D_800E4690->unk970, id), 0x149), 1);
    }
}
