#include "s1009_types.h"
extern S10State D_801462C8[];
s32 func_auto_0043E9A8(S10Msg *a) {
    switch (a->code) {
    case 2: D_801462C8->b2D ^= 1; break;
    case 3: D_801462C8->b2E ^= 1; break;
    case 4: D_801462C8->b2F ^= 1; break;
    case 5: D_801462C8->b30 ^= 1; break;
    case 6: D_801462C8->b31 ^= 1; break;
    case 7: D_801462C8->b32 ^= 1; break;
    case 8: D_801462C8->b33 ^= 1; break;
    case 9: D_801462C8->b35 ^= 1; break;
    }
    return 0;
}
