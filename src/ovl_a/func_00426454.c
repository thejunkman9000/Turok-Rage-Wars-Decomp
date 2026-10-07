#include "o04_types.h"
typedef struct { s8 pad[0x24]; s8 a; s8 b; } O04P;
typedef struct { u8 pad0[0x78]; u8 unk78; u8 pad79[0x91 - 0x79]; u8 unk91; u8 pad92[0x96 - 0x92]; } O04Ent96;
extern O04P D_801462C8[];
extern O04Ent96 D_80146398[];
extern s32 D_80103140[];
s32 func_00426454(void) {
    s32 r;
    s32 n;
    s32 i;
    O04Ent96 *e;
    if (D_801462C8->a <= 0 && D_801462C8->b <= 0) {
        return 0;
    }
    r = 1;
    n = 0;
    e = D_80146398;
    for (i = 0; i < 8; i++) {
        if (e[i].unk78 == 1 && e[i].unk91 != e[i].unk78 && D_80103140[i] >= 0x4C) {
            n++;
        }
    }
    if (n < 2) {
        r = 0;
    }
    return r;
}
