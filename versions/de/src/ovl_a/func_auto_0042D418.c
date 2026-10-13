#include "o04_types.h"
extern O04ModeS53C0 *D_800E53C0;
s32 func_0040ECB0(s32 a, u16 b);
void func_0040E958(s32 a, s32 b);
void func_auto_0042D418(s32 a) {
    s32 i;
    s32 h = func_0040ECB0(D_800E53C0->unkE0, a);
    for (i = 0; i < 4; i++) {
        s32 id;
        switch (i) {
        case 1:
            id = 0x267;
            break;
        case 0:
            id = 0x268;
            break;
        case 2:
            id = 0x266;
            break;
        case 3:
            id = 0x265;
            break;
        default:
            id = 0x268;
            break;
        }
        func_0040E958(func_0040ECB0(h, id), 0);
    }
}
