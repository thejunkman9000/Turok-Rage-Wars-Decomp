#include "o02_types.h"
typedef struct { u8 pad0; u8 b1; u8 pad2[0x0E]; s32 f10; s32 f14; s32 f18; } S_func_00413484;
void func_00254784(s32 v);
void func_002A1748(void *p, s32 v, s32 n);
void func_00413484(S_func_00413484 *p) {
    if (p->b1 & 1) {
        func_00254784(p->f18);
    }
    if (p->b1 & 2) {
        if (p->f10 > 0) {
            func_00254784(p->f14);
        }
    }
    func_002A1748(p, 0, 0x20);
}
