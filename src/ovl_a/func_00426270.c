#include "o04_types.h"
typedef struct { u8 pad0[0x78]; u8 unk78; u8 pad79[0x7F - 0x79]; s8 unk7F; u8 pad80[0x91 - 0x80]; u8 unk91; } O04Stat2;
typedef struct { u8 a; u8 b; } O04BytePair2;
typedef struct { u8 pad0[0x4C]; s32 ids[8]; } O04Rec4C;
typedef struct { u8 pad0[0x190]; } O04Row190c;
typedef struct {
    u8 pad0[0x18];
    O04Rec4C *unk18;
    u8 pad1C[0x5D8 - 0x1C];
    O04Stat2 *unk5D8;
    u8 pad5DC[0x602 - 0x5DC];
    O04BytePair2 unk602[1];
} O04Plr2;
extern O04Row190c D_80102B00[];
s32 func_0022F4CC(void *a, s32 b);
void func_00426270(O04Plr2 *p) {
    s32 i;
    O04Rec4C *r;
    s32 row;
    if (p->unk5D8->unk91 == 1 || p->unk5D8->unk78 == 0) {
        return;
    }
    i = 0;
    r = p->unk18;
    row = p->unk5D8->unk7F;
    do {
        s32 id = r->ids[i];
        if (id >= 0x4C3) {
            s32 t;
            id -= 0x4C3;
            t = func_0022F4CC(&D_80102B00[row], id);
            if (t == 1) {
                p->unk602[id].a = t;
                p->unk602[id].b = i;
            }
        }
        i++;
    } while (i < 8);
}
