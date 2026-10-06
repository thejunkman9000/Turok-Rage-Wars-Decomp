#include "b19_types.h"
void func_00296DDC(void *, s32);
void func_00285540(B19RecOut *d, B19RecIn *s) {
    d->f0 = s->f4;
    d->b[0] = s->b[0];
    d->b[1] = s->b[1];
    d->b[2] = s->b[2];
    d->b[3] = s->b[3];
    d->b[4] = s->b[4];
    d->b[5] = s->b[5];
    d->b[6] = s->b[6];
    d->b[7] = s->b[7];
    d->h18 = s->h14;
    d->h1A = s->h16;
    d->f6 = s->fA;
    if (s->f4 & 0x40) {
        d->f4 = (s->f8 << 1) | 1;
    } else {
        d->f4 = s->f8 << 1;
    }
    if (s->f0 == -1) {
        d->f8 = 0;
    } else {
        func_00296DDC(&d->f8, s->f0);
    }
}
