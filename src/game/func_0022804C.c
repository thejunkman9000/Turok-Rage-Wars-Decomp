#include "b06_types.h"

s32 func_00245774();
s32 func_00245788();
extern GameB6 D_801468A0[];
extern u8 D_8014642A[];

s32 func_0022804C(PlrGroup *g) {
    s32 i;
    s32 k;
    s32 want;
    u8 *p;
    Plr *a;
    if (func_00245774() != 0) {
        return 0;
    }
    if (func_00245788() != 0) {
        return 0;
    }
    if (D_801468A0->unk18 == 0) {
        return 0;
    }
    if (D_801468A0->unk24 != 0) {
        want = 0xFF;
        p = (u8 *)D_801468A0 - 0x5D8;
        if (p[0xD] != 0) {
            k = 0;
            if (p[0x148] == 0) {
                do {
                    p += 0x96;
                    k++;
                } while (p[0x148] == 0);
            }
            want = D_8014642A[k * 0x96];
        }
        i = 0;
        for (; i < 5; i++) {
            s32 lim = D_801468A0->unk18;
            GStateB6 *gp = (GStateB6 *)((u8 *)D_801468A0 - 0x5D8);
            if (D_801468A0->unk2C[i] >= lim) {
                s32 t = gp->unkD;
                if (t == 0) {
                    return 1;
                }
                if (i == want) {
                    D_801468A0->unkA8 = 1;
                    return 1;
                }
                D_801468A0->unkA8 = 0;
                if (t != 1) {
                    return 1;
                }
            }
        }
        return 0;
    } else {
        for (a = g->head; a != NULL; a = a->next) {
            s32 lim = D_801468A0->unk18;
            GStateB6 *gp = (GStateB6 *)((u8 *)D_801468A0 - 0x5D8);
            if (a->stats->unk4 >= lim) {
                s32 t = gp->unkD;
                if (t == 0) {
                    return 1;
                }
                if (a->unk5D4 < 4) {
                    D_801468A0->unkA8 = 1;
                    return 1;
                }
                D_801468A0->unkA8 = 0;
                if (t != 1) { do { return 1; } while (0); }
            }
        }
        return 0;
    }
}
