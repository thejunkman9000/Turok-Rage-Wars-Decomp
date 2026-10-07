#include "o04_types.h"
typedef struct { u8 pad[0x3A]; u8 unk3A[0x190 - 0x3A]; } O04Row190;
extern O04Row190 D_80102B10[];
s32 func_00265670(void *p, s32 i);
s32 func_004261E4(s32 a) {
    s32 i;
    s32 n = 0;
    for (i = 0; i < 0x32; i++) {
        if (func_00265670(D_80102B10[a].unk3A, i) == 1) {
            n++;
        }
    }
    return n;
}
