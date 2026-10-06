#include "b03_types.h"
s32 func_0020F8F0(TargetSet *s) {
    s32 i;
    if (s->target == 0) {
        return 0;
    }
    for (i = 0; i < 10; i++) {
        if (s->actors[i] == s->target && s->valid[i] != 0) {
            return 1;
        }
    }
    return 0;
}
