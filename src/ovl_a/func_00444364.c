#include "o06_types.h"
typedef struct { u8 pad[0x5D8]; u8 *unk5D8; } O06B;
typedef struct { u8 pad[0x1C]; O06B *unk1C; } O06A;
extern u8 D_80146302;
u8 *func_00444364(O06A *a) {
    u8 *r = &D_80146302;
    if (a->unk1C) { u8 *q = a->unk1C->unk5D8; if (q) r = q; }
    return r;
}
