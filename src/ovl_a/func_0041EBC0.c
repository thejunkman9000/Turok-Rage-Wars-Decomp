#include "o03_types.h"
typedef struct { s32 v; u8 pad[0x18]; } O3Slot;
extern O3Slot D_80153F80[3];
s32 func_0041EBC0(void) {
    s32 i, n = 0;
    for (i = 0; i < 3; i++) {
        if (D_80153F80[i].v >= 0) {
            n++;
        }
    }
    return n;
}
