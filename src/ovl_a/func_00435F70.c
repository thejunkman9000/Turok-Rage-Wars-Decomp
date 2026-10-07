#include "o05_types.h"

typedef struct { u8 pad[0xC]; s16 key; } O05Obj;
extern O05Disp D_800E555C[];

s32 func_00435F70(O05Obj *o, s32 id, s32 a2, s32 a3, s32 a4) {
    s32 i;
    for (i = 0; D_800E555C[i].fn != 0; i++) {
        if (D_800E555C[i].id == id) {
            if (D_800E555C[i].key == o->key || D_800E555C[i].key == 0x7530) {
                return D_800E555C[i].fn(o, id, a2, a3, a4);
            }
        }
    }
    return 0;
}
