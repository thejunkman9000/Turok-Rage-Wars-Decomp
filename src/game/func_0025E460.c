#include "b13_types.h"

extern SndMgr D_8010C080;

void func_00258E7C(SndMgr *m, f32 v);

void func_0025E460(f32 v) {
    func_00258E7C(&D_8010C080, v);
}
