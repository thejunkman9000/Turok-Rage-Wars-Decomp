#include "o04_types.h"
typedef struct { u8 pad0[0x78]; u8 unk78; u8 pad79[0x7F - 0x79]; u8 unk7F; u8 pad80[0x96 - 0x80]; } O04Ent96d;
typedef struct { u8 pad0[0xD]; s8 unkD; u8 padE[0x190 - 0xE]; } O04Row190b;
extern O04ModeS5430 *D_800E5430;
extern O04Ent96d D_80146398[];
extern O04Row190b D_80102B00[];
void func_0029A73C(void);
void func_0041A4B0(s32 a, s32 b);
void func_0022F1F4(s32 a);
s32 func_0042DDE4(void) {
    s32 i;
    O04Ent96d *e;
    func_0029A73C();
    D_800E5430->unk10 = 7;
    func_0041A4B0(D_800E5430->unk0, 2);
    for (i = 0; i < D_800E5430->unk20; i++) {
        e = &D_80146398[i];
        e->unk78 = 1;
        e->unk7F = i;
        if (D_80102B00[i].unkD < 0) {
            func_0022F1F4(i);
        }
    }
    return 0;
}
