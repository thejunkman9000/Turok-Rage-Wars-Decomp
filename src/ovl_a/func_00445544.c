#include "o06_types.h"
typedef struct { u8 pad[0x14]; s32 **unk14; u8 pad2[4]; s32 unk1C; } O06A;
extern s32 func_00442158(O06A *a);
extern s32 sprintf(char *buf, const char *fmt, ...);
extern u8 D_800D0EE1;
extern u8 D_800D0EE5;
extern u8 D_800E27D8[];
s32 func_00445544(O06A *a) {
    char *s = (char *)*a->unk14;
    if (a->unk1C == -1) a->unk1C = D_800D0EE1; else D_800D0EE1 = (u8)a->unk1C;
    D_800D0EE5 = D_800D0EE1;
    sprintf(s - 3 + func_00442158(a), (char *)D_800E27D8, a->unk1C);
    return 0;
}
