#include "b17_types.h"

s32 func_00274544();

s16 func_00279808(WEnt *p) {
    WEnt *start;
    s32 total, r;

    total = 0;
    start = p;
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
