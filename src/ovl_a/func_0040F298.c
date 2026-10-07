#include "o02_types.h"
typedef struct { u8 pad[0x2C]; s32 a, b, c, d; } S_func_0040F298;
void func_0040F298(S_func_0040F298 *p, s32 a, s32 b, s32 c, s32 d) {
    p->a = a;
    p->b = b;
    p->c = c;
    p->d = d;
}
