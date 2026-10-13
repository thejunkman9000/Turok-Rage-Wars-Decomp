#include "veu3n10_types.h"

extern s32 D_80154034;

/* switch with ten out-of-line `return N` arms: the splat units 0043E0FC..0043E144 are its case labels */
s32 func_auto_0043E0CC(void) {
    switch (D_80154034) {
    case 0:
    default: return 1000;
    case 1: return 2000;
    case 2: return 3000;
    case 3: return 4000;
    case 4: return 5000;
    case 5: return 6000;
    case 6: return 7401;
    case 7: return 7501;
    case 8: return 7601;
    case 9: return 7602;
    case 10: return 8000;
    }
}
