#include "common.h"
#include "b21_rec.h"

extern B21Rec D_8014AEB0;
extern u32 D_800D2AE0;

s32 func_002955C8(void) {
    s32 r = 0;
    if (D_8014AEB0.unk0) {
        r = D_800D2AE0 != 0;
    }
    return r;
}
