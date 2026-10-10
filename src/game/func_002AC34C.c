#include "b24_types.h"

void func_002AC34C(s32 unused, u8 *pairs, s32 n, u8 *tab) {
    s32 i;
    u8 c = 0xFF;
    u8 *p;
    i = 0xFF;
    p = tab + i;
    for (; i >= 0; i--) {
        *p-- = c;
    }
    for (i = 0; i < n; i++) {
        tab[pairs[0]] = pairs[1];
        pairs += 2;
    }
}
