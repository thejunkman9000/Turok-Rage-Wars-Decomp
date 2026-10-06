#include "b08_types.h"

typedef struct Obj88 {
    u8 pad0[0x88];
    f32 unk88;
    f32 unk8C;
    s32 unk90;
    s32 unk94;
    f32 unk98;
    f32 unk9C;
} Obj88;

extern f32 D_800C861C;
extern f32 D_800C8620;
extern f32 D_800C8624;
extern f32 D_800C8628;

void func_0023912C(Obj88 *o) {
    if (o != NULL) {
        o->unk90 = 0;
        o->unk94 = 0;
        o->unk88 = D_800C861C;
        o->unk8C = D_800C8620;
        o->unk98 = D_800C8624;
        o->unk9C = D_800C8628;
    }
}
