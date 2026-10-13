#include "o04_types.h"
extern O04ModeS4690 *D_800E4690;
void *func_0040ECB0(void *a, s32 b);
void func_0040E958(void *p, s32 a);
s32 func_0042881C(s32 a);
void func_auto_0042854C(s32 idx, s32 b, s32 flag) {
    s32 id;
    void *h;
    s32 r;
    O04Sub2C *p;
    switch (idx) {
    case 0:
        id = !flag ? 0x147 : 0x1DB;
        break;
    case 1:
        id = !flag ? 0x14A : 0x1DC;
        break;
    case 2:
        id = !flag ? 0x14B : 0x1DD;
        break;
    case 3:
        id = !flag ? 0x14C : 0x1DE;
        break;
    case 4:
        id = !flag ? 0x14D : 0x1DF;
        break;
    default:
        id = 0x147;
        break;
    }
    h = func_0040ECB0((void *)D_800E4690->unk970, id);
    func_0040E958(func_0040ECB0(h, 0x149), 0);
    r = func_0042881C(b);
    p = func_0040ECB0(h, 0x148);
    p->unk10 = 0x64;
    p->unk2C = (s32)r;
}
