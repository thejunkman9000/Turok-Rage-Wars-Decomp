#include "o02_types.h"
typedef struct { u8 pad[0x4A]; u8 b4A, b4B, b4C, b4D, b4E, b4F, b50, b51; } S_func_00412BF8;
void func_00412270(S_func_00412BF8 *p);
void func_0029A73C(void);
s32 func_00412BF8(S_func_00412BF8 *p, s32 a, s32 b, s32 d) {
    s32 cur = p->b4C;
    if (d) {
        if (p->b50 < cur) p->b4C = cur - 1;
    }
    func_00412270(p);
    func_0029A73C();
    return 0;
}
