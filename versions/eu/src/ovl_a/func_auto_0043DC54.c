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

s32 func_auto_0043DC54(u8 *s) {
    return cheat_match(s);
}
