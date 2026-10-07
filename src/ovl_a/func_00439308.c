#include "o05_types.h"

typedef struct { s32 f0; u8 pad[0x10]; s32 f14; } S;
extern S *D_800E58A0;
void func_0029A73C(void);
s32 func_0029AA08(void);
void func_0041A4B0(s32 a, s32 b);

s32 func_00439308(void) {
    S *p;
    func_0029A73C();
    if (func_0029AA08() == 0x73) {
        p = D_800E58A0;
        p->f14 = -1;
        func_0041A4B0(p->f0, 2);
    }
    return 0;
}
