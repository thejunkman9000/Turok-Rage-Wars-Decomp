#include "p3_types.h"

typedef struct {
    u8 pad0[0x14];
    u8 list[0x14];
    s32 f28;
} P3List;

void func_00255C40(void *p, s32 a, s32 b);
void func_00255CB4(void *p, void *q);

void func_0025C8F8(P3List *l, u8 *src, s32 n) {
    s32 i;
    func_00255C40(l, 0, 4);
    func_00255C40(l->list, 0, 4);
    for (i = 0; i < n; i++) {
        func_00255CB4(l, src);
        src += 0x20;
    }
    l->f28 = 0;
}
