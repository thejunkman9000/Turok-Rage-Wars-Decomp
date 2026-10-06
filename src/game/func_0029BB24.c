#include "b22_types.h"
void func_0029B558(SndMsg *);
void func_0029BB24(s16 a, s32 b, s32 c)
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
    func_0029B558(&m);
}
