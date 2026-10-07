#include "b13_types.h"

extern SndMgr D_8010C080;

void func_00258D44(SndMgr *m, s32 v);

void func_0025E410(s32 v) {
    func_00258D44(&D_8010C080, v);
}
