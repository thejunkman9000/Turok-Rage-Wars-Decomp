#include "b22_types.h"
void func_00254784(void *);
void func_0029AC80(B22Buf *b)
{
    if (b->data) {
        func_00254784(b->data);
        b->data = 0;
    }
    b->wrpos = 0;
    b->rdpos = 0;
    b->size = 0;
}
