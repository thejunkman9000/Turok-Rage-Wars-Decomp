#include "b13_types.h"

extern SndMgr D_8010C080;

void func_00258C2C(SndMgr *m, s32 tag);

void func_0025E234(s32 tag) {
    func_00258C2C(&D_8010C080, tag);
}
