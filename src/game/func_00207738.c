#include "b01_types.h"


s32 func_00207738(B01Actor *actor, B01State *state) {
    s32 r;
    switch (state->unk37) {
    case 3:
        return 0x5280;
    case 1:
    case 2:
        return 0x5294;
    case 0:
        switch (state->unk34) {
        case 0:
        case 2:
            return 0x526C;
        case 1:
        case 3:
            return 0x5276;
        default:
            r = 0x526C;
            break;
        }
        break;
    case 4:
        return 0x528A;
    default:
        return 0x526C;
    }
    return r;
}
