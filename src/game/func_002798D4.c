#include "b17_types.h"

typedef struct PBuf {
    s16 n;
    Pair16 e[0x18];
} PBuf;

s32 func_002798D4(PBuf *b, s16 x, s16 y) {
    if (b->n == 0x18) {
        return 0;
    }
    b->e[b->n].a = x;
    b->e[b->n].b = y;
    b->n++;
    return 1;
}
