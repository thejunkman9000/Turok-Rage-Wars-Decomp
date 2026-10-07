#include "o04_types.h"
typedef struct { s32 v; s32 pad4; s32 k; s32 pad0C; } O04Pair16;
extern O04Pair16 D_800E5B44[];
extern O04Pair16 D_800E5BC4[];
extern O04Pair16 D_800E5B14[];
s32 func_0042881C(s32 a) {
    s32 i;
    for (i = 0; i < 8; i++) {
        if (D_800E5B44[i].k == a) {
            return D_800E5B44[i].v;
        }
    }
    for (i = 0; i < 4; i++) {
        if (D_800E5BC4[i].k == a) {
            return D_800E5BC4[i].v;
        }
    }
    for (i = 0; i < 3; i++) {
        if (D_800E5B14[i].k == a) {
            return D_800E5B14[i].v;
        }
    }
    return D_800E5BC4[0].v;
}
