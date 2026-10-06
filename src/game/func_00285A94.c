#include "b19_types.h"
u32 __osDisableInt(void);
void __osRestoreInt(u32);
void func_00255C40(void *, s32, s32);
void func_00255CB4(void *, void *);
void func_00285A94(B19Pool *p, u8 *items, s32 n) {
    u32 mask = __osDisableInt();
    s32 i;
    func_00255C40(p, 0, 4);
    func_00255C40(&p->head, 0, 4);
    for (i = 0; i < n; i++) {
        func_00255CB4(p, items);
        items += 0x3C;
    }
    p->count = 0;
    __osRestoreInt(mask);
}
