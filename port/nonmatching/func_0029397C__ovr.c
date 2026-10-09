/* port (passthru_fix.py): func_0044AFC0 needs a2 a3 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "b21_types.h"

extern u8 D_8011FE88[];
void func_44AFC0(void *a, s32 b, u32, u32);
void func_44A600(void *a, s32 b, s32 c);
s32 func_004030E0(s32 a);
void func_44E178(void *a, s32 b, s32 c);
void func_44DCA4(void *a);
void func_44DD40(void *a);

void func_0029397C(B21Game *g, s32 a, u32 pt_a2, u32 pt_a3) {
    func_44AFC0(g->sub255C8, 1, pt_a2, pt_a3);
    func_44A600(g->sub25580, 1, 0);
    func_44E178(D_8011FE88, ~func_004030E0(a), 0);
    func_44DCA4(D_8011FE88);
    func_44DD40(D_8011FE88);
}
