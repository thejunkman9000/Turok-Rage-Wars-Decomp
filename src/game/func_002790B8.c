#include "b17_types.h"

typedef struct B17Dst {
    u8 pad0[0x48];
    Vec3f pos;
    u8 pad54[0xC];
    f32 unk60;
} B17Dst;

void func_002790B8(ActorX *a, B17Dst *d) {
    a->flags |= 0x40000000;
    d->pos.x = a->pos.x;
    d->pos.y = a->pos.y;
    d->pos.z = a->pos.z;
    d->unk60 = a->unk6C;
}
