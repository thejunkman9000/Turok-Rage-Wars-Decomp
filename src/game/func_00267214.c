#include "b15_types.h"

typedef struct B15Disp {
    void (*fn)(s32 a, s32 b, s32 c, Vec3f pos, B15Blk8 blk);
    s32 unk4;
} B15Disp;

extern B15Disp D_800D1380[];

void func_00267214(s32 a, s32 b, s32 c, Vec3f pos, B15Blk8 blk) {
    if (D_800D1380[c].fn != NULL) {
        D_800D1380[c].fn(a, b, c, pos, blk);
    }
}
