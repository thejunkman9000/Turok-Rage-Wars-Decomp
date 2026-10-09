/* port (passthru_fix.py): func_0044AFC0 needs a1 a2 a3 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "b21_types.h"

void func_44AFC0(void *a, u32, u32, u32);
void func_44A600(void *a, s32 b, s32 c);

void func_00293318(B21Game *g, s32 a, s32 b, u32 pt_a3) {
    func_44AFC0(g->sub255C8, a, b, pt_a3);
    func_44A600(g->sub25580, a, b);
}
