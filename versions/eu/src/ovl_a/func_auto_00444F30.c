#include "o06_types.h"
typedef struct { u8 pad[0x7F]; s8 unk7F; u8 pad2[4]; u8 unk84[8]; } O06A;
extern u8 D_auto_80152208[];
extern u8 *D_auto_800E3B64[];
extern u8 *D_auto_800E3B74[];
extern u8 *D_auto_800E3B84[];
extern u8 *D_auto_800E3B94[];
void func_auto_00444F30(O06A *a) {
    s32 i;
    switch (a->unk7F) {
    default:
    case 0: { u8 *g; i = 0; g = D_auto_80152208;
        for (; i < 8; i++) a->unk84[i] = D_auto_800E3B64[g[0x581]][i];
        break; }
    case 1: { u8 *g; i = 0; g = D_auto_80152208;
        for (; i < 8; i++) a->unk84[i] = D_auto_800E3B74[g[0x581]][i];
        break; }
    case 2: { u8 *g; i = 0; g = D_auto_80152208;
        for (; i < 8; i++) a->unk84[i] = D_auto_800E3B84[g[0x581]][i];
        break; }
    case 3: { u8 *g; i = 0; g = D_auto_80152208;
        for (; i < 8; i++) a->unk84[i] = D_auto_800E3B94[g[0x581]][i];
        break; }
    case 4: case 5: case 6: case 7:
        break;
    }
}
