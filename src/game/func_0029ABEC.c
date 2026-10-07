#include "b22_types.h"
void func_002A1724(void *, void *, s32);
void func_0029ABEC(B22Buf *b, void *dst, s32 n)
{
    u8 *d;
    s32 o = b->rdpos;
    d = b->data;
    d = d + o;
    func_002A1724(dst, d, n);
    b->rdpos += n;
}
