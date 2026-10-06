#include "b08_types.h"

typedef struct PoolRef {
    s32 *unk0;
    s32 unk4;
    s32 unk8;
} PoolRef;

extern s32 D_800C83C0[];

s32 *func_002533DC(s32 a, s32 size, s32 c, s32 *d);

void func_0023A104(PoolRef *p, s32 n) {
    s32 size;
    s32 *r;
    s32 buf;

    size = n * 3800;
    p->unk8 = n;
    r = func_002533DC(0, size, 0x23, &D_800C83C0[1]);
    p->unk0 = r;
    buf = r[0];
    p->unk4 = buf;
    memset((void *)buf, 0, size);
}
