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
/* port: the table entry is entered with a0..a3 as this function received them (the MIPS code sets up no
 * arguments); forward them instead of letting the x86 callee read stack garbage. */
void func_002390E4(Obj14 *o, s16 id, u32 a2, u32 a3) {
    o->unk14 = id;
    o->unk18 = 0;
    o->unk1C = 0;
    o->unk20 = 0;
    if (D_800D05C0[o->unk14].fn != NULL) {
        ((void (*)(Obj14 *, s32, u32, u32))D_800D05C0[o->unk14].fn)(o, id, a2, a3);
    }
}
