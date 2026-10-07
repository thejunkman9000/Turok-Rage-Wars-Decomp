#include "o02_types.h"
typedef struct { u8 pad[0x44]; struct { s32 x, y; } *f44; u8 pad2[3]; u8 b4B; } S_func_004129C0;
S_func_004129C0 *func_0040ECB0(void *n, u16 id);
void *func_00411E4C(s32 i);
s32 func_0029A958(void);
void func_004129C0(s32 id, s32 a, s32 b, s32 *c, s32 *d) {
    S_func_004129C0 *p = func_0040ECB0(func_00411E4C(func_0029A958()), id);
    *c = p->f44[a * p->b4B + b].x;
    *d = p->f44[a * p->b4B + b].y;
}
