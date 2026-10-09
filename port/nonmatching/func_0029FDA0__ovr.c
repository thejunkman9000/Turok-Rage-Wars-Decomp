/* port (passthru_fix.py): func_0029D6A8 needs a1 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "b23_types.h"

void func_0029D6A8(Mtx4f *m, u32);
void func_0029DE3C(Mtx4f *a, Mtx4f *b, Mtx4f *dst);

void func_0029FDA0(Mtx4f *m, u32 pt_a1) {
    Mtx4f tmp;

    func_0029D6A8(&tmp, pt_a1);
    func_0029DE3C(m, &tmp, m);
}
