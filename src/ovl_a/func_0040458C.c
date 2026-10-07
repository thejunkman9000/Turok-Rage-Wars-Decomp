#include "o01_types.h"

extern u8 D_800E285C[];

static inline void O01ConvName(u8 *src, u8 *dst, s32 n) {
    s32 i;
    s32 seen;
    for (i = 0; i < n; i++) {
        dst[i] = 0;
    }
    seen = 0;
    for (i = 0; i < n; i++) {
        if (src[i] < 0x42) {
            if (src[i] == 0 && seen == 0) {
                dst[i] = 0x20;
            } else {
                dst[i] = D_800E285C[src[i]];
                seen = 1;
            }
        } else {
            dst[i] = 0x7E;
        }
    }
    for (i = n - 1; i >= 0; i--) {
        if (dst[i] != 0x20 && dst[i] != 0) {
            break;
        }
        dst[i] = 0;
    }
    dst[n - 1] = 0;
}
extern s32 D_801534F0[];
extern O01PadTab *D_800E2854;
void *memcpy(void *dst, const void *src, u32 n);

s32 func_0040458C(s32 pad, s32 idx, s32 *valid, u8 *name, u8 *ext, s32 *blocks, u8 *company, u8 *game) {
    if (D_801534F0[pad] != 3) {
        return -2;
    }
    if (D_800E2854[pad].ent[idx].unk0 == 0) {
        *valid = 0;
    } else {
        *valid = 1;
        *blocks = (u32)D_800E2854[pad].ent[idx].unk0 >> 8;
        memcpy(company, &D_800E2854[pad].ent[idx].unk8, 2);
        memcpy(game, &D_800E2854[pad].ent[idx].unk4, 4);
        O01ConvName(D_800E2854[pad].ent[idx].unkE, name, 17);
        O01ConvName(D_800E2854[pad].ent[idx].unkA, ext, 4);
        game[4] = 0;
        company[2] = 0;
    }
    return 0;
}
