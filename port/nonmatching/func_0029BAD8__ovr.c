/* port (passthru_fix.py): func_0029B558 needs a1 a3 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "b22_types.h"
void func_0029B558(SndMsg *, u32, u32, u32);
void func_0029BAD8(s16 a, s16 b, s32 c, u32 pt_a3)
{
    SndMsg m;
    m.type = 4;
    m.a = a;
    m.b = 1;
    m.c = b;
    m.d = 0;
    m.e = c != 0;
    m.f = 0;
    m.g = 0;
    m.h = 0;
    func_0029B558(&m, b, 0, pt_a3);
}
