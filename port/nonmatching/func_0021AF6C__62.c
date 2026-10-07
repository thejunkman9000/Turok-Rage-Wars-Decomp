#include "b04_types.h"
extern u8 D_801462D5;
extern u8 D_801462E5;
extern s32 D_801468F4;
typedef struct { u8 pad0[0x1D]; u8 unk1D; u8 pad1E[0x60E]; s32 unk62C; } B04G;
extern B04G D_801462C8[];
typedef struct { u8 pad0[0x54]; s32 unk54; s32 unk58; } B04W54;
extern B04W54 *D_800D052C[];
typedef struct { u8 pad0[0x4C]; u16 tbl[4]; } B04Def9;
void func_426270(B04Act *, s32);
void func_426354(B04Act *, s32);
void func_4263BC(B04Act *, s32);
void func_0021AF6C(B04Act *p, s32 a1) {
    s32 i, j, w;
    B04Def9 *d;
    for (i = 6; i >= 0; i--)
        p->unk5F4[i] = 0;
    for (i = 21; i >= 0; i--)
        p->pr[i].a = 0;
    if (D_801462C8->unk1D == 1) {
        if (*(B04Def9 **)((u8 *)p + 0x18) != NULL) {
            j = 1;
            if (D_801462C8->unk62C == 0 || p->stats->unk8F == 0) {
                a1 = -1;
                for (; j < 22; j++) {
                    p->pr[j].a = 0;
                    p->pr[j].b = a1;
                }
            }
            switch (D_801462D5) {
            case 1:
                func_426270(p, a1);
                break;
            case 4:
                func_4263BC(p, a1);
                break;
            default:
                func_426354(p, a1);
                break;
            }
            goto blk16;
        }
        goto blk18;
    }
blk16:
    if (*(B04Def9 **)((u8 *)p + 0x18) == NULL) {
blk18:
        p->unk5F4[0] = 0x64;
        p->unk5F4[1] = 0x64;
        p->unk5F4[2] = 0x32;
    } else {
        p->unk5F4[0] = 0x32;
        p->unk5F4[1] = 0;
        p->unk5F4[2] = 0;
        p->unk5F4[3] = 0;
    }
    w = p->unk5E0;
    if (w == 0x11) {
        p->unk770 = 0x10;
        p->unk62E = 0x10;
        p->unk630 = 0x10;
        p->unk632 = 0x10;
    } else {
        if (w == 0x12) {
            p->unk770 = 0x11;
            p->unk62E = 0x11;
            p->unk630 = 0x11;
            p->unk632 = 0x11;
        } else if (D_801468F4 != 0 && p->stats->unk8F != 0) {
            p->unk62E = 0;
            p->unk770 = 0;
            p->unk630 = 0;
            p->unk632 = p->unk62E;
        } else {
            j = 0;
            if (p->unk1450 != 0) {
                d = *(B04Def9 **)((u8 *)p + 0x18);
                if (d != NULL && d->tbl != NULL) {
                    p->unk770 = d->tbl[3] - 0x4C3;
                    p->unk62E = p->unk770;
                } else {
                    goto blk37;
                }
            } else {
                for (; j < 22; j++) {
                    if (p->pr[j].b == 1) break;
                }
                if (j < 22) {
                    p->unk770 = j;
                    p->unk62E = j;
                } else {
blk37:
                    p->unk770 = 0;
                    p->unk62E = 0;
                }
            }
            p->unk630 = p->unk62E;
            p->unk632 = p->unk62E;
        }
    }
    if (D_801462E5 != 0) {
        p->unk484 = D_800D052C[p->unk770]->unk54;
        p->unk578 = D_800D052C[p->unk62E]->unk58;
    }
}
