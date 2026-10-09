/* port (passthru_fix.py): func_0028AFE8 needs a1 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "b15_types.h"

typedef struct B15Pool B15Pool;
void func_00268C1C(B15Pool *pool, s32 val);
s32 func_0028AFE8(void *p, u32);
extern u8 D_8011FE88[];

void func_00268BE0(B15Pool *pool, u32 pt_a1) {
    func_00268C1C(pool, func_0028AFE8(D_8011FE88, pt_a1));
}
