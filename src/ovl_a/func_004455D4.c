#include "o06_types.h"
typedef struct { u8 pad[0x14]; s32 **unk14; u8 pad2[4]; s32 unk1C; } O06A;
extern s32 func_00442158(O06A *a);
extern s32 sprintf(char *buf, const char *fmt, ...);
extern u8 D_800D0EE2;
extern u8 D_800D0EE6;
extern u8 D_800E27D8[];
s32 func_004455D4(O06A *a) {
    char *s = (char *)*a->unk14;
    if (a->unk1C == -1) a->unk1C = D_800D0EE2; else D_800D0EE2 = (u8)a->unk1C;
    D_800D0EE6 = D_800D0EE2;
    sprintf(s - 3 + func_00442158(a), (char *)D_800E27D8, a->unk1C);
    return 0;
}
