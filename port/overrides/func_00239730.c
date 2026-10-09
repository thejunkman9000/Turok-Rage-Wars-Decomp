#include "b08_types.h"

typedef struct Obj20 {
    u8 pad0[0x20];
    s32 unk20;
} Obj20;

Obj20 *func_00237E70(u32 a0, u32 a1, u32 a2, u32 a3);

/* port: func_00237E70(u8 *, s32, s32) reads a0..a2, which the MIPS code leaves as this function's
 * own (undeclared) arguments; forward them. */
Obj20 *func_00239730(u32 a0, u32 a1, u32 a2, u32 a3) {
    Obj20 *o;

    o = func_00237E70(a0, a1, a2, a3);
    if (o != NULL) {
        o->unk20 = 1;
    }
    return o;
}
