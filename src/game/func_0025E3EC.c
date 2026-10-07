#include "b13_types.h"

extern SndMgr D_8010C080;

void func_00258D3C(SndMgr *m, s32 v);

void func_0025E3EC(void) {
    func_00258D3C(&D_8010C080, 1);
}
