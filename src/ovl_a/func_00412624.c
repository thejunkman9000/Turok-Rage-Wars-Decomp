#include "q01_types.h"
typedef struct { s32 id; s32 key; s32 (*fn)(); } Q01Disp;
typedef struct { u8 pad[0xC]; s16 key; } Q01Obj;
extern Q01Disp D_800E2AD0[];
s32 func_00412624(Q01Obj *o, s32 id, s32 a2, s32 a3, s32 a4) {
    s32 i;
    for (i = 0; D_800E2AD0[i].fn != 0; i++) {
        if (D_800E2AD0[i].id == id) {
            if (D_800E2AD0[i].key == o->key || D_800E2AD0[i].key == 0x7530) {
                return D_800E2AD0[i].fn(o, id, a2, a3, a4);
            }
        }
    }
    return 0;
}
