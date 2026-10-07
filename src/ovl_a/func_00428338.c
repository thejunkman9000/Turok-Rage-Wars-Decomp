#include "o04_types.h"
typedef struct { s32 a; s32 b; s32 c; } O04Pair;
extern O04Pair D_800E4A84[];
s32 func_00428338(s32 a, s32 b) {
    s32 i;
    if (a == b) {
        return 1;
    }
    for (i = 0; i < 0x40; i++) {
        if (D_800E4A84[i].a == a && D_800E4A84[i].b == b) {
            return 1;
        }
    }
    return 0;
}
