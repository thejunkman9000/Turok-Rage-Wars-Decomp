#include "o04_types.h"
typedef struct { u8 pad0[0xD]; s8 unkD; u8 padE[0x6C - 0xE]; s32 unk6C; u8 pad70[4]; s32 unk74; u8 pad78[0x190 - 0x78]; } O04Row190g;
typedef struct { u8 pad0[2]; s16 unk2; s16 unk4; u8 pad6[0x96 - 6]; } O04Ent96i;
extern O04Row190g D_80102B00[];
extern O04Ent96i D_80146398[];
extern s32 D_80102B74;
void func_00424D70(void) {
    s32 i;
    s32 x;
    s32 y;
    s32 *q;
    O04Ent96i *e;
    O04Ent96i *e2;
    q = &D_80102B74;
    e = D_80146398;
    for (i = 0; i < 4; i++) {
        if (D_80102B00[i].unkD >= 0) {
            x = D_80102B00[i].unk6C + e->unk4;
            if (x > 99999) {
                D_80102B00[i].unk6C = 99999;
            } else {
                D_80102B00[i].unk6C = x;
            }
            e2 = e;
            y = *q + e2->unk2;
            if (y > 99999) {
                *q = 99999;
            } else {
                D_80102B00[i].unk74 = y;
            }
            q += 100;
        } else {
            q += 100;
        }
        e++;
    }
}
