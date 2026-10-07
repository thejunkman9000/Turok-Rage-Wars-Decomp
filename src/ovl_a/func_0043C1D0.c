#include "o06_types.h"
typedef struct { s16 pad[6]; s16 unkC; } O06A;
typedef struct { s32 key; s32 sub; s32 (*fn)(O06A *, s32, s32, s32, s32); } O06T;
extern O06T D_800E5C04[];
s32 func_0043C1D0(O06A *a, s32 b, s32 c, s32 d, s32 e) {
    s32 i;
    for (i = 0; D_800E5C04[i].fn != 0; i++) {
        if (D_800E5C04[i].key == b && (D_800E5C04[i].sub == a->unkC || D_800E5C04[i].sub == 0x7530)) return D_800E5C04[i].fn(a, b, c, d, e);
    }
    return 0;
}
