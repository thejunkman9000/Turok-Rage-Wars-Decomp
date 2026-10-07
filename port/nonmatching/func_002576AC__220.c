#include "b13_types.h"

s32 func_00265984(s32 a);
void *func_0023C77C(s32 size, s32 a, s32 b);
u32 *func_0028FD94(void *node, s32 idx);

void func_002576AC(SndMgr *m) {
    u32 *s3;
    u32 *t0;
    u32 *t1;
    u32 *t2;
    u32 *n3;
    u32 *n4;
    u32 *n5;
    u32 *r;
    u32 *z;
    m->root2B48 = func_0023C77C(func_00265984(0x14) - func_00265984(0x10), 0, func_00265984(0x10));
    s3 = func_0028FD94(m->root2B48, 0);
    func_0028FD94(m->root2B48, 1);
    t0 = func_0028FD94(s3, 0);
    t1 = func_0028FD94(s3, 1);
    t2 = func_0028FD94(s3, 2);
    m->tree2B4C = t2;
    m->unk2B54 = t2[0];
    m->unk2B58 = (u8 *)t0 + 8;
    m->unk2B5C = (s32 *)((u8 *)t1 + 8);
    n3 = func_0028FD94(s3, 3);
    n4 = func_0028FD94(s3, 4);
    n5 = func_0028FD94(s3, 5);
    m->tab70 = (u8 *)n3 + 8;
    m->unk2B7C = n3[1];
    m->tab74 = (u8 *)n4 + 8;
    m->unk2B80 = n4[1];
    m->tab78 = (u8 *)n5 + 8;
    m->unk2B84 = n5[1];
    r = func_0028FD94(m->root2B48, 1);
    z = func_0028FD94(r, 0);
    m->unk2B60 = (u8 *)z + 8;
    m->unk2B64 = z[1];
    m->node2B50 = func_0028FD94(r, 1);
}
