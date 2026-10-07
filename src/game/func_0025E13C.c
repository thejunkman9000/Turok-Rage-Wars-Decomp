#include "b13_types.h"

extern SndMgr D_8010C080;
extern s32 D_80146890;

void func_00258F30(SndMgr *m, s32 v);

void func_0025E13C(s32 v) {
    if (D_80146890 == 0) {
        func_00258F30(&D_8010C080, v);
    }
}
