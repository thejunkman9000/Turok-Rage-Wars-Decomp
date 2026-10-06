#include "b03_types.h"

extern f32 D_800C7004;

s32 func_0020F984(TargetSet *s) {
    s32 best = -1;
    f32 min = D_800C7004;
    s32 i;

    for (i = 0; i < s->count; i++) {
        if (s->actors[i]->flags & 0x300000) {
            f32 v = (f32)s->value[i];
            if ((v < min || min == D_800C7004) && s->valid[i] != 0) {
                min = v;
                best = i;
            }
        }
    }
    return best;
}
