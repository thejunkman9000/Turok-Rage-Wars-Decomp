#include "o06_types.h"
typedef struct { u8 pad[0x1340]; s32 unk1340; u8 pad2[0x10C]; s32 unk1450; } O06P;
typedef struct { u8 pad[0x1C]; O06P *unk1C; } O06A;
typedef struct { u8 pad[0x1C]; s32 unk1C; s32 unk20; s32 pad24; s32 unk28; } O06G;
extern s32 func_0022B168(O06P *p);
extern void func_0044A37C(O06P *p);
extern O06G D_801468A0[];
s32 func_00443A2C(O06A *a) {
    O06P *p = a->unk1C;
    s32 r;
    if (p->unk1450 == 0) {
        if (func_0022B168(p) != 0) {
            p->unk1340++;
            if (p->unk1340 >= 0x4C) { func_0044A37C(a->unk1C); return 1; }
        }
    }
    r = 0;
    if (D_801468A0->unk28 != 0 || D_801468A0->unk1C != 0 || D_801468A0->unk20 != 0) r = 1;
    return r;
}
