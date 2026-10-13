#include "o06_types.h"
typedef struct { u8 pad[0x14]; void *unk14; } O06A;
extern u8 D_auto_800E2304[];
s32 func_auto_00445FB4(O06A *a) {
    a->unk14 = D_auto_800E2304;
    return 0;
}
