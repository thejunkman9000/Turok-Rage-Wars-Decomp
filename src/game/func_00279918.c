#include "b17_types.h"

typedef struct PBuf {
    s16 n;
    WEnt e[0x18];
} PBuf;
s32 func_00274544();

s16 func_00279918(PBuf *b) {
    WEnt *p, *start;
    s32 total, r;

    if (b->n == 0) {
        return -1;
    }
    p = start = b->e;
    total = 0;
    b->e[b->n].id = -1;
    while (p->id != -1) {
        total += p->w;
        p++;
    }
    r = func_00274544() % total;
    p = start;
    total = 0;
    while (p->id != -1) {
        total += p->w;
        if (total >= r) {
            break;
        }
        p++;
    }
    return p->id;
}
