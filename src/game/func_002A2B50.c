#include "b23_types.h"
typedef struct ObjC { u8 pad0[0xC]; s16 unkC; } ObjC;
extern DispEnt D_800D2C20[];
s32 func_002A2B50(ObjC *o, s32 a1, s32 a2, s32 a3, s32 a4) {
    s32 i;
    for (i = 0; D_800D2C20[i].fn != 0; i++) {
        if (D_800D2C20[i].key == a1) {
            if (D_800D2C20[i].val == o->unkC || D_800D2C20[i].val == 0x7530) {
                return D_800D2C20[i].fn(o, a1, a2, a3, a4);
            }
        }
    }
    return 0;

}
