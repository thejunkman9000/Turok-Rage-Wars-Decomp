#include "b23_types.h"

typedef struct Obj6A54 {
    u8 pad0[0x14];
    f32 unk14;
    u8 pad18[0xC];
    f32 unk24;
    u8 pad28[0xC];
    f32 unk34;
    f32 unk38;
    f32 unk3C;
} Obj6A54;

extern f32 D_800D15E4[];
extern f32 D_800D15F4[];

void func_002A6AC0(Obj6A54 *o) {
    if (o->unk24 != 0.0f) {
        D_800D15E4[0] += o->unk34;
        D_800D15E4[1] += o->unk38;
        D_800D15E4[2] += o->unk3C;
        D_800D15E4[3] += o->unk24;
    }
    D_800D15F4[0] += o->unk14;
}
