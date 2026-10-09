/* port: C function-pointer call forwards the argument registers the MIPS code left live at the jalr (this function's own incoming a0..a3); see port/jalrscan.py. */
#include "b11_types.h"

void func_0026EE90(void *a, s32 b, void *c);

void func_0024B4E4(Obj *a, s32 b, u32 pt_a2, u32 pt_a3) {
    a->unk28C(a, a->unk170, pt_a2, pt_a3);
    func_0026EE90(a->unk74, b, a->unkE8);
}
