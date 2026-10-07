#include "b13_types.h"

s32 func_00259220(SndMgr *m, s32 tag) {
    s32 i;
    s32 n;
    if (m->unk102 != -1) {
        return 1;
    }
    if (tag < 0x100) {
        n = 0;
        for (i = 0; i < 17; i++) {
            if (m->pool.v[i].tag == tag) {
                n++;
            }
        }
        if (n >= 6) {
            return 1;
        }
    }
    return 0;
}
