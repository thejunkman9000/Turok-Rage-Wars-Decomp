#include "b03_types.h"
s32 func_0022AAC4(Actor *actor, s16 idx);
s32 func_0020F5A4(ActorRef *ref) {
    Actor *a = ref->actor;
    s32 r = func_0022AAC4(a, FLD(s16, a, 0x62E));
    switch (r) {
    case 0:
        return 5;
    case 1:
        return 6;
    case 2:
        return 7;
    default:
        return 4;
    }
}
