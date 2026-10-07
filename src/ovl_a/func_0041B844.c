#include "o03_types.h"
typedef struct { u8 pad[0x48]; s32 cnt; u8 pad4C[0x10]; s32 arr[1]; } O3Arr;
s32 func_0041B844(O3Arr *o) {
    s32 i, n;
    n = 0;
    for (i = 0; i < o->cnt; i++) {
        if (o->arr[i] != 0) {
            n++;
        }
    }
    return n;
}
