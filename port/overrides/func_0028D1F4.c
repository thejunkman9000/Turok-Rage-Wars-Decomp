/* port (passthru_fix.py): func_0028FD94 needs a1 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "b20_types.h"

void *func_0028FD94();

void func_0028D1F4(Level *lv, u32 pt_a1) {
    func_0028FD94(func_0028FD94(lv->unk7C, pt_a1), 0);
}
