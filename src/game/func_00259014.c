#include "b13_types.h"

s32 func_00259014(SndMgr *m, s32 id) {
    s32 i;
    SndVoice *v;
    if (id == -1) {
        return -1;
    }
    v = m->pool.v;
    for (i = 0; i < 17; i++) {
        if (v->unkC == id) {
            return i;
        }
        v++;
    }
    return -1;
}
