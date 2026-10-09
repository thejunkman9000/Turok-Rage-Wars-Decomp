/* port: C function-pointer call forwards the argument registers the MIPS code left live at the jalr (this function's own incoming a0..a3); see port/jalrscan.py. */
#include "o06_types.h"
struct O06A;
typedef struct { u8 pad[4]; s32 unk4; u8 pad2[0x10]; void *(*unk18)(struct O06A *); } O06D;
typedef struct O06A { u8 pad[0x14]; O06D *unk14; } O06A;
f32 func_00443030(O06A *a, u32 pt_a1, u32 pt_a2, u32 pt_a3) {
    O06D *d = a->unk14;
    void *p = ((void *(*)(O06A *, u32, u32, u32))d->unk18)(a, pt_a1, pt_a2, pt_a3);
    f32 r;
    switch (d->unk4) {
    default: r = 0.0f; break;
    case 0: r = *(f32 *)p; break;
    case 3: r = (f32)*(s8 *)p; break;
    case 4: r = (f32)*(s16 *)p; break;
    case 1: case 2: case 5: r = (f32)*(s32 *)p; break;
    case 6: r = (f32)*(u8 *)p; break;
    case 7: r = (f32)*(u16 *)p; break;
    case 8: r = (f32)*(u32 *)p; break;
    }
    return r;
}
