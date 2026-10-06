#include "p1_types.h"
extern DlCmd *D_80110634;
void func_002AA224(s32 a);
void func_00217928(s32 a, s32 b, s32 c);
void func_002183E8(s32 a, s32 b, s32 c) {
    DlCmd *dl;
    func_002AA224(0xFF);
    dl = D_80110634++;
    dl->w0 = 0xE3001201;
    dl->w1 = 0x2000;
    func_00217928(a, b, c);
}
