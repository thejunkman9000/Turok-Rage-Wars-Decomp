#include "b21_types.h"
#include "b21_world.h"

extern s32 D_80146928;
s32 func_442B98(void *a);
s32 func_00245788();
s32 func_00245AFC();
s32 func_00245840();
void func_4037D4();

s32 func_00294BB0(B21Game *g) {
    B21GameBlk *b;
    s32 r;
    if (func_442B98(D_80145040.sub5DC) == 0) {
        if (func_00245788()) {
            if (func_00245AFC() == 0x78) {
                b = &D_80145040.blk;
                if (b->unk88 != 0) {
                    goto check;
                }
                if (g->unk26DD4 == 0) {
                    b->unk88 = 1;
                    func_4037D4();
                }
            }
        }
    }
    if (D_80146928 != 0) {
check:
        r = func_00245840();
        if (r) return 1;
    }
    return 0;
}
