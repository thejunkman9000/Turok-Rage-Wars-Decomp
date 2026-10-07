#include "b13_types.h"

extern SndMgr D_8010C080;

void func_002589C8(SndMgr *m, s32 mask);

void func_0025E20C(s32 mask) {
    func_002589C8(&D_8010C080, mask);
}
