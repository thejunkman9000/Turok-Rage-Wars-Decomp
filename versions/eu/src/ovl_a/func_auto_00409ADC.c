#include "o01_types.h"

extern u8 D_801462C8[];
extern char *D_auto_800E25D4[];
extern char *D_auto_800E25C4[];
s32 func_002A1238(char *s);
s32 func_002A137C(char *a, char *b);

s32 func_auto_00409ADC(char *a, char *b) {
    u8 *g;
    if (func_002A1238(b) == 4 && func_002A1238(a) == 2 && func_002A137C(b, D_auto_800E25D4[(g = D_801462C8)[0x581]]) == 0 && func_002A137C(a, D_auto_800E25C4[g[0x581]]) == 0) {
        return 1;
    }
    return 0;
}
