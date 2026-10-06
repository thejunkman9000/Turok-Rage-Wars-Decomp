#include "b22_types.h"
void *func_00252FFC(s32);
void func_002A1724(void *, void *, s32);
void func_0029AB74(B22Buf *b, void *src, s32 n)
{
    s32 o;
    if (b->data == 0) {
        b->data = func_00252FFC(n);
        b->wrpos = 0;
        b->size = n;
    }
    o = b->wrpos;
    func_002A1724(b->data + o, src, n);
    b->wrpos += n;
}
