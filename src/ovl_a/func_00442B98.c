#include "o06_types.h"
typedef struct O06N { u8 pad[0x28]; s16 unk28; u8 pad2[0x1D4-0x2A]; struct O06N *unk1D4; } O06N;
typedef struct { O06N *unk0; } O06A;
s32 func_00442B98(O06A *a) {
    O06N *n; s32 c = 0;
    for (n = a->unk0; n != 0; n = n->unk1D4) { if (n->unk28 != 4) c++; }
    return c;
}
