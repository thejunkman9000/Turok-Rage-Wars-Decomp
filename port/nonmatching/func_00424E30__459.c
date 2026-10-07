#include "o04_types.h"
typedef struct { s8 pad[0x24]; s8 a; s8 b; } O04P;
typedef struct { u8 pad0[0x78]; u8 unk78; u8 pad79[0x91 - 0x79]; u8 unk91; u8 pad92[0x96 - 0x92]; } O04Ent96;
typedef struct { u8 pad0[0x70]; s32 unk70; u8 pad74[0x190 - 0x74]; } O04Row190h;
extern O04P D_801462C8[];
extern O04Ent96 D_80146398[];
extern s32 D_80103140[];
extern O04Row190h D_80102B00[];
extern u8 D_80102B26[];
static inline s32 o04_chk(void) {
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
void func_00424E30(s32 idx, s32 b) {
    s32 x;
    s32 v;
    if (D_80146398[idx].unk91 == 1) {
        return;
    }
    x = D_80102B00[idx].unk70 + 1;
    if (x > 99999) {
        D_80102B00[idx].unk70 = 99999;
    } else {
        do { D_80102B00[idx].unk70 = x; } while (0);
    }
    if (o04_chk() == 1) {
        if (D_801462C8->a >= 0xA || D_801462C8->b >= 0xA) {
            v = D_80102B26[b + idx * 0x190] + 1;
            if (v >= 6) {
                D_80102B26[b + idx * 0x190] = 5;
            } else {
                D_80102B26[b + idx * 0x190] = v;
            }
        }
    }
}
