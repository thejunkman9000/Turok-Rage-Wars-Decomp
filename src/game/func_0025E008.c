#include "b13_types.h"

extern SndMgr D_8010C080;
extern s32 D_80146890;

s32 func_0025828C(SndMgr *m, s32 id, Vec3f pos, s32 a);

s32 func_0025E008(s32 id, Vec3f pos, s32 a) {
    s32 r;
    if (D_80146890 == 0) {
        r = func_0025828C(&D_8010C080, id, pos, a);
    } else {
        r = -1;
    }
    return r;
}
