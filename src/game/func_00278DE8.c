#include "b17_types.h"

extern SessMgr D_8011FE88;
void func_0028C248(SessMgr *s, ActorX *a, s32 *out0, s32 *out1);
void func_00279274(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);

void func_00278DE8(ActorX *a, s32 arg1, s32 arg2) {
    s32 sp20;
    s32 sp24;

    if (!(a->flags & 0x80000)) {
        func_0028C248(&D_8011FE88, a, &sp20, &sp24);
        if (sp24 != 0) {
            func_00279274(sp20, sp24, 0, arg1 & 0x3FC1FF, arg1 & 0x400000, 0x400000, arg2);
        }
    }
}
