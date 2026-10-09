/* port (passthru_fix.py): func_0029B558 needs a1 a2 a3 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "b22_types.h"
void func_0029B558(SndMsg *, u32, u32, u32);
void func_0029BB24(s16 a, s32 b, s32 c, u32 pt_a3)
{
    SndMsg m;
    m.type = 4;
    m.a = a;
    m.b = 3;
    m.c = 0x162;
    m.d = 0;
    m.e = 0;
    m.f = b * 100;
    m.g = c * 100;
    m.h = 0;
    func_0029B558(&m, b, c, pt_a3);
}
