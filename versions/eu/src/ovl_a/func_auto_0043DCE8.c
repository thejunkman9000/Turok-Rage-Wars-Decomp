#include "veu3n10_types.h"

extern VeuCheatBuf D_800E5CA0;
extern s32 strlen(char *s);

/* compare the entered line with a scrambled code (code[i] ^ i == buf[i]) */
static inline s32 cheat_match(u8 *s) {
    s32 i = 0;
    if (strlen((char *)s) != strlen((char *)D_800E5CA0.buf)) return 0;
    while (i < strlen((char *)s)) {
        if ((s[i] ^ i) != D_800E5CA0.buf[i]) return 0;
        i++;
    }
    return 1;
}

extern VeuCheatEnt D_0044FB90[];   /* 0x00450210 */
extern s32 D_80154030;
extern s32 D_8013B2D4;
extern s32 D_801462C8[];
extern void func_0025DF54(s32 snd);

/* look the entered line up in the cheat table */
s32 func_auto_0043DCE8(void) {
    u32 n;
    s32 *q = &D_801462C8[1];
    s32 *p;
    D_80154030 = -1;
    for (n = 0; n < 12; n++) {
        if (cheat_match(D_0044FB90[n].code)) {
            p = D_801462C8;
            *q |= D_0044FB90[n].flag;
            D_8013B2D4 = p[1];
            __asm__ volatile ("");
            D_80154030 = n;
            if (D_0044FB90[n].snd) func_0025DF54((s16)D_0044FB90[n].snd);
        }
    }
    return 0;
}
