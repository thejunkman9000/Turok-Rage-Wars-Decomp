#include "o04_types.h"
typedef struct { u8 pad0[0xC]; s16 unkC; } O04Obj;
extern O04Evt D_800E45AC[];
s32 func_00423B88(O04Obj *a, s32 b, s32 c, s32 d, s32 e) {
    s32 i;
    for (i = 0; D_800E45AC[i].fn != 0; i++) {
        if (D_800E45AC[i].ev == b) {
            if (D_800E45AC[i].key == a->unkC || D_800E45AC[i].key == 0x7530) {
                return D_800E45AC[i].fn(a, b, c, d, e);
            }
        }
    }
    return 0;
}
