#include "b13_types.h"

extern SndMgr D_8010C080;
extern s32 D_80146890;

s32 func_00258A9C(SndMgr *m, s16 id, Vec3f pos, s32 a, s32 b, f32 c);

s32 func_0025DEE0(s32 id, Vec3f pos, s32 a, s32 b, f32 c) {
    s32 r;
    if (D_80146890 == 0) {
        r = func_00258A9C(&D_8010C080, id, pos, a, b, c);
    } else {
        r = -1;
    }
    return r;
}
