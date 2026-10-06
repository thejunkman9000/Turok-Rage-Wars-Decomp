#include "b22_types.h"
void *func_00252FFC(s32);
void func_0029AC38(B22Buf *b, s32 size)
{
    if (b->data == 0) {
        b->data = func_00252FFC(size);
        b->wrpos = 0;
        b->size = size;
    }
}
