/* port (passthru_fix.py): func_0028B1F8 needs a1 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "o05_types.h"

typedef struct { s32 f0; u8 pad[0x30]; s32 f34; } S;
extern u8 D_8011FE88[];
s32 func_0028B1F8(void *p, u32);

s32 func_00439E60(S *o, s32 n) {
    o->f0 = n;
    o->f34 = -1;
    if (n > 0) {
        o->f34 = func_0028B1F8(D_8011FE88, n);
    }
    return o->f34;
}
