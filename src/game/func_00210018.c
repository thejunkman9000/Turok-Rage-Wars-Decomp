#include "b03_types.h"

void func_0020FDB0(ActorRef *ref, void *tbl);

s32 func_00210018(ActorRef *ref) {
    func_0020FDB0(ref, (u8 *)ref->actor->def + 0x8C);
    return 1;
}
