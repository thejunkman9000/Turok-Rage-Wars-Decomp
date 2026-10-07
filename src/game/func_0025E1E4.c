#include "b13_types.h"

extern SndMgr D_8010C080;

void func_002588F4(SndMgr *m, SndMgr *owner);

void func_0025E1E4(SndMgr *owner) {
    func_002588F4(&D_8010C080, owner);
}
