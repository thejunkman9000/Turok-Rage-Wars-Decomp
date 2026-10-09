/* port (passthru_fix.py): func_0043F290 needs a0 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "o06_types.h"
typedef struct { u8 pad[4]; s16 unk4; u8 pad2[0xE]; u8 **unk14; } O06A;
extern u8 *func_0043F290(u32);
s32 func_00442158(O06A *a) {
    s32 n = 0;
    u8 *s;
    if (a->unk4 == 5) s = func_0043F290(a); else s = *a->unk14;
    for (; s && *s && *s != 10; s++) n++;
    return n;
}
