#include "b05_types.h"

typedef struct B05Row { u8 pad0[4]; u8 b4, b5, b6; u8 pad7[0x189]; } B05Row;
typedef struct B05Tbl { u8 pad0[0x108]; s32 lim[1]; } B05Tbl;
typedef struct B05Ent2 { u8 pad0[0xC]; s16 idx; } B05Ent2;
typedef struct B05P3 {
    u8 pad0[0x18];
    B05Tbl *tbl;
    u8 pad1C[0x5B8];
    s32 row;
    u8 pad5D8[0x1C];
    s16 cnt[1];
    u8 pad5F6[0xE5A];
    s32 unk1450;
} B05P3;

extern u8 D_801462D5;
extern s32 D_800CE3E8[];
extern B05Row D_80102B10[];
B05Ent2 *func_002AD940(s32);

static inline s32 getLimit(B05P3 *p, s32 idx) {
    s32 r;
    s32 gm;

    if (idx == -1) {
        return 0;
    }
    gm = D_801462D5;
    if (gm != 1) {
        r = p->tbl->lim[idx];
    } else {
        r = D_800CE3E8[idx];
        if (p->unk1450 == 0) {
            if (idx == 0) {
                r += D_80102B10[p->row].b5;
            } else if (idx == gm) {
                r += D_80102B10[p->row].b6;
            } else if (idx == 2) {
                r += D_80102B10[p->row].b4;
            }
        }
    }
    return r;
}

s32 func_00222D40(B05P3 *p, s32 arg) {
    B05Ent2 *e;
    s32 idx;
    s16 *cp;

    e = func_002AD940(arg);
    if (e == NULL) {
        return 0;
    }
    idx = e->idx;
    cp = &p->cnt[idx];
    return *cp < getLimit(p, idx);
}
