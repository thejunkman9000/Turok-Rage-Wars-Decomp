#include "o03_types.h"
extern O3Msg D_800E39C4[];
s32 func_auto_0041F0A8(O3Hdr *obj, s32 msg, s32 a2, s32 a3, s32 a4) {
    s32 i;
    for (i = 0; D_800E39C4[i].fn != 0; i++) {
        if (D_800E39C4[i].msg == msg) {
            if (D_800E39C4[i].type == obj->id || D_800E39C4[i].type == 0x7530) {
                return D_800E39C4[i].fn(obj, msg, a2, a3, a4);
            }
        }
    }
    return 0;
}
