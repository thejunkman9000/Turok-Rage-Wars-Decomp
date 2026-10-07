#include "b06_types.h"

extern GameB6 D_801468A0[];
extern u8 D_8014642A[];

s32 func_002282C8(void) {
    s32 i;
    s32 k;
    s32 want;
    u8 *p;
    u8 *g;
    GameB6 *s;
    if (D_801468A0->unk7C == 0) {
        return 0;
    }
    k = 0;
    want = 0xFF;
    p = (u8 *)D_801468A0 - 0x5D8;
    if (p[0xD] != 0) {
        if (p[0x148] == 0) {
            do {
                p += 0x96;
                k++;
            } while (p[0x148] == 0);
        }
        want = D_8014642A[k * 0x96];
    }
    i = 0;
    s = D_801468A0;
    for (; i < 5; i++) {
        if (s->unk40[i] >= s->unk7C) {
            if (i == want) {
                s->unkA8 = 1;
                return 1;
            }
            s->unkA8 = 0;
            g = (u8 *)D_801468A0 - 0x5D8;
            if (g[0xD] == 0) {
                return 1;
            }
        }
    }
    return 0;
}
