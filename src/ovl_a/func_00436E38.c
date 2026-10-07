#include "o05_types.h"

typedef struct { s32 f0; u8 pad[28]; s32 fv; } S;
extern S *D_800E5690;
void func_0029A73C(void);
void func_0041A4B0(s32 a, s32 b);

s32 func_00436E38(void) {
    S *p;
    func_0029A73C();
    p = D_800E5690;
    p->fv = -1;
    func_0041A4B0(p->f0, 2);
    return 0;
}
