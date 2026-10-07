#include "b13_types.h"

extern SndMgr D_8010C080;

s32 func_00258D70(SndMgr *m, s32 tag);

s32 func_0025E114(s32 tag) {
    return func_00258D70(&D_8010C080, tag);
}
