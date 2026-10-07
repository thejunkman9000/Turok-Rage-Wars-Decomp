#include "o02_types.h"
typedef struct { u8 pad[0x4A]; u8 b4A, b4B, b4C, b4D; u8 b4E, b4F, b50, b51; u8 b52, b53, b54, b55, b56, b57; s32 f58, f5C; } S_func_00412B40;
S_func_00412B40 *func_0040ECB0(void *n, u16 id);
void *func_00411E4C(s32 i);
s32 func_0029A958(void);
void func_00412B40(s32 id, s32 a, s32 b) {
    S_func_00412B40 *p = func_0040ECB0(func_00411E4C(func_0029A958()), id);
    p->f5C = b;
    p->f58 = a;
}
