#include "b08_types.h"

typedef struct PawnFx {
    u8 pad0[0x29C];
    f32 unk29C;
    f32 unk2A0;
    f32 unk2A4;
    f32 unk2A8;
    u8 pad2AC[0x274];
    u8 rgba[4];
} PawnFx;

extern Player *D_80145060;
extern s32 D_800CF228;
extern u8 D_80102AD8[];
extern s32 D_801462C8;
extern u8 D_8011FAC0[];
extern u8 D_80145040[];

s32 func_00245788();
s32 func_002934DC();
void func_00245884(PawnFx *a);
void func_0022A37C(void *a, PawnFx *b);
void func_00293100(void *tbl, u8 *col, s32 x, s32 y, s32 x2, s32 y2);

static inline Player *findPlayer(PawnFx *a) {
    Player *p;

    for (p = D_80145060; p != NULL; p = p->next) {
        if (p->pawn == a) {
            return p;
        }
    }
    return NULL;
}

void func_00233C78(PawnFx *a) {
    Player *p;
    u8 c[4];
    s32 i;

    p = findPlayer(a);
    if (p != NULL) {
        if (p->flags38 & 0x1000) {
            c[0] = a->rgba[0];
            c[1] = a->rgba[1];
            c[2] = a->rgba[2];
            c[3] = a->rgba[3];
            if (D_800CF228 != 0) {
                for (i = 0; i < 4; i++) {
                    c[i] = D_80102AD8[i];
                }
            }
            if (D_801462C8 & 0x4000) {
                c[0] >>= 3;
                c[1] >>= 3;
                c[2] >>= 3;
            }
            func_00293100(D_8011FAC0, c, (s32)a->unk2A4, (s32)a->unk2A8, (s32)(a->unk2A4 + a->unk29C),
                          (s32)(a->unk2A8 + a->unk2A0));
        }
        if (func_00245788() == 0 && func_002934DC() != 0) {
            func_0022A37C(D_80145040, a);
        }
        func_00245884(a);
    }
}

