#include "o06_types.h"
typedef struct { u8 pad[0x7F]; s8 unk7F; u8 pad2[4]; u8 unk84[8]; } O06A;
extern u8 *D_800D7C70;
extern u8 *D_800D7C74;
extern u8 *D_800D7C78;
extern u8 *D_800D7C7C;
void func_00444260(O06A *a) {
    s32 i;
    switch (a->unk7F) {
    default:
    case 0: for (i = 0; i < 8; i++) a->unk84[i] = D_800D7C70[i]; break;
    case 1: for (i = 0; i < 8; i++) a->unk84[i] = D_800D7C74[i]; break;
    case 2: for (i = 0; i < 8; i++) a->unk84[i] = D_800D7C78[i]; break;
    case 3: for (i = 0; i < 8; i++) a->unk84[i] = D_800D7C7C[i]; break;
    case 4: case 5: case 6: case 7: break;
    }
}
