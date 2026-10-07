#include "b09_types.h"

s32 func_0023B93C(B09SortObj **a, B09SortObj **b) {
    s32 r = 1;
    f32 ka = (*a)->key;
    f32 kb = (*b)->key;
    if (kb < ka) {
        r = -1;
    }
    return r;
}
