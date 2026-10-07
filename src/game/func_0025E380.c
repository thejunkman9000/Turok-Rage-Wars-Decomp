#include "b13_types.h"

extern SndMgr D_8010C080;

void func_00258EDC(SndMgr *m);

void func_0025E380(void) {
    func_00258EDC(&D_8010C080);
}
