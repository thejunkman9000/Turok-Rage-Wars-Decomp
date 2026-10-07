#include "o06_types.h"
typedef struct { u8 pad[0x14]; void *unk14; } O06A;
extern u8 D_801462E3;
extern u8 D_800D7604[];
extern u8 D_800D7608[];
extern u8 D_800D760C[];
s32 func_0044489C(O06A *a) {
    switch (D_801462E3) {
    case 0: a->unk14 = D_800D7604; break;
    case 1: a->unk14 = D_800D7608; break;
    case 2: a->unk14 = D_800D760C; break;
    }
    return 0;
}
