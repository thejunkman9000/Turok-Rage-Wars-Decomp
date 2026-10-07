#include "b13_types.h"

extern SndMgr D_8010C080;
extern s32 D_80146890;

s32 func_0025828C(SndMgr *m, s32 id, Vec3f pos, s32 a);
s32 func_00258D30(SndMgr *m);
void func_00258D28(SndMgr *m, s32 v);

s32 func_0025E06C(s32 id) {
    Vec3f v;
    s32 saved;
    s32 new_var;
    s32 r;
    if (D_80146890 == 0) {
        v.x = v.y = v.z = 0.0f;
        saved = func_00258D30(&D_8010C080);
        func_00258D28(&D_8010C080, 1);
        new_var = func_0025828C(&D_8010C080, id, v, 0);
        func_00258D28(&D_8010C080, saved);
        r = new_var;
    } else {
        r = -1;
    }
    return r;
}
