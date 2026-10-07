#include "b06_types.h"

s32 func_00229A54(PlrGroup *g) {
    Plr *a;
    s32 s4 = 0, s3 = 0, s2 = 0, s1 = 0, s0 = 0;
    s32 i;
    u32 idx;
    s32 max;
    s32 best;
    for (a = g->head; a != NULL; a = a->next) {
        idx = ((u32)a - (u32)g->unk4) / 5864;
        for (i = 0; i < 8; i++) {
            best = i != idx;
            if (best) {
                switch (a->stats->unk92) {
                case 0xFF: return 0;
                case 0: s0 += a->stats->unk3C[i]; break;
                case 1: s1 += a->stats->unk3C[i]; break;
                case 2: s2 += a->stats->unk3C[i]; break;
                case 3: s3 += a->stats->unk3C[i]; break;
                case 4: s4 += a->stats->unk3C[i]; break;
                }
            }
        }
    }
    max = -1;
    best = max;
    if (s0 >= 0) {
        max = s0;
        best = 0;
    }
    if (max < s1) {
        max = s1;
        best = 1;
    }
    if (max < s2) {
        max = s2;
        best = 2;
    }
    if (max < s3) {
        max = s3;
        best = 3;
    }
    if (max < s4) {
        best = 4;
    }
    return best;
}
