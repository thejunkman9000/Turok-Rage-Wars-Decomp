/* port (passthru_fix.py): func_0028FD94 needs a1 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "b20_types.h"

s32 *func_0028FD94();

void *func_0028D220(Level *lv, s32 unused, s32 idx) {
    s32 *t = func_0028FD94(func_0028FD94(lv->unk7C, unused), 1);
    return (u8 *)t + (idx * t[0] + 8);
}
