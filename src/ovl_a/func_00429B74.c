#include "o04_types.h"
typedef struct { u8 pad0[0xC]; s16 unkC; } O04Obj;
extern O04Evt D_800E4EF4[];
s32 func_00429B74(O04Obj *a, s32 b, s32 c, s32 d, s32 e) {
    s32 i;
    for (i = 0; D_800E4EF4[i].fn != 0; i++) {
        if (D_800E4EF4[i].ev == b) {
            if (D_800E4EF4[i].key == a->unkC || D_800E4EF4[i].key == 0x7530) {
                return D_800E4EF4[i].fn(a, b, c, d, e);
            }
        }
    }
    return 0;
}
