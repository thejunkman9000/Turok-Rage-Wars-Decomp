#include "p1_types.h"
extern f32 D_800C6D8C;
extern f32 D_800C6D90;
extern f32 D_800C6D94;
f32 func_00209B64(ActorRef *ref) {
    Actor *a = ref->actor;
    f32 v = a->def->info.unk14 * D_800C6D8C;
    switch (a->stats->unk93) {
    case 1:
        break;
    default:
        ref->actor->stats->unk93 = 0;
    case 0:
        v *= D_800C6D90;
        break;
    case 2:
        v *= D_800C6D94;
        break;
    }
    return v;
}
