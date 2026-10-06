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
    u8 pad5F6[0x6CA];
    s32 unkCC0;
    u8 padCC4[0x78C];
    s32 unk1450;
} B05P3;

extern u8 D_801462D5;
extern s32 D_800CE3E8[];
extern B05Row D_80102B10[];



s32 func_00222BC4(B05P3 *p, s32 idx, s32 amt) {
    s16 *cp;
    s32 c;
    s32 v;
    s16 t;
    s32 lim;
    s32 below;
    s32 gm;

    cp = &p->cnt[idx];
    if (idx == -1) {
        lim = 0;
    } else {
        gm = D_801462D5;
        if (gm != 1) {
            lim = p->tbl->lim[idx];
        } else {
            lim = D_800CE3E8[idx];
            if (p->unk1450 == 0) {
                if (idx == 0) {
                    lim += D_80102B10[p->row].b5;
                } else if (idx == gm) {
                    lim += D_80102B10[p->row].b6;
                } else if (idx == 2) {
                    lim += D_80102B10[p->row].b4;
                }
            }
        }
    }
    c = *cp;
    below = c < lim;
    if (below) {
        if (c == 0 && amt > 0) {
            switch (idx) {
            case 0:
                p->unkCC0 = 1;
                break;
            case 1:
                p->unkCC0 = 5;
                break;
            case 2:
                p->unkCC0 = 4;
                break;
            }
        }
        t = *(u16 *)cp + amt;
        *cp = t;
        v = t;
        if (lim < v) {
            v = lim;
        }
        *cp = v;
    }
    return below;
}
