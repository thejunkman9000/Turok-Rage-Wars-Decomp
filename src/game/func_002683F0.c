#include "b15_types.h"
void func_00266830(B15Src *a, s32 b, s32 c, Vec3f pos, B15Blk8 blk, s32 e, s32 f, s32 g);
extern f32 D_800C9560;
extern f32 D_800C9564;

static inline void w(B15Src *a, s32 b, s32 c, Vec3f pos, B15Blk8 blk) {
    func_00266830(a, b, c, pos, blk, 1, 0, 0x200);
}

void func_002683F0(B15Src *a, s32 b, s32 c, Vec3f pos, B15Blk8 blk) {
    f32 d;

    d = a->pos.y - pos.y;
    if (d < 0.0f ? -d <= D_800C9560 : d <= D_800C9564) {
        w(a, b, c, pos, blk);
    }
}
