#include "b08_types.h"

typedef struct FnEnt {
    void (*fn)(void);
    s32 unk4;
} FnEnt;

typedef struct Obj14 {
    u8 pad0[0x14];
    s16 unk14;
    u8 pad16[2];
    s32 unk18;
    s16 unk1C;
    u8 pad1E[2];
    s32 unk20;
} Obj14;

extern FnEnt D_800D05C0[];

void func_002390E4(Obj14 *o, s16 id) {
    o->unk14 = id;
    o->unk18 = 0;
    o->unk1C = 0;
    o->unk20 = 0;
    if (D_800D05C0[o->unk14].fn != NULL) {
        D_800D05C0[o->unk14].fn();
    }
}
