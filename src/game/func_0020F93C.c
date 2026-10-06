#include "b03_types.h"

s32 func_0020F93C(TargetSet *s) {
    s32 n = 0;
    s32 i;

    if (s->count == 0) {
        return 0;
    }
    for (i = 0; i < 10; i++) {
        if (s->actors[i] != 0 && s->valid[i] != 0) {
            n++;
        }
    }
    return n;
}
