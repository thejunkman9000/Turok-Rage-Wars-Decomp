#include "b22_types.h"
void func_0029B558(SndMsg *);
void func_0029BAD8(s16 a, s16 b, s32 c)
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
    func_0029B558(&m);
}
