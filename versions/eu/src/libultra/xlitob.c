#include "common.h"

#define BUFF_LEN 0x18

extern char ldigs[];
extern char udigs[];

/* (inlined into _Litob below; GCC emits _Litob first because its name is declared first, in common.h) */
void lldiv(lldiv_t *ans, s64 num, s64 den) {
    ans->quot = num / den;
    ans->rem = num % den;
}

void _Litob(_Pft *x, u8 type) {
    char buff[BUFF_LEN];
    const char *digs;
    s32 base;
    s32 i;
    u64 ullval;

    digs = ldigs;
    if (type == 'X') {
        digs = udigs;
    }

    base = (type == 'o') ? 8 : (type != 'x' && type != 'X') ? 10 : 16;

    i = BUFF_LEN;
    ullval = x->v.ll;

    if ((type == 'd' || type == 'i') && x->v.ll < 0) {
        ullval = -ullval;
    }

    if (ullval != 0 || x->prec != 0) {
        buff[--i] = digs[ullval % base];
    }

    x->v.ll = ullval / base;

    while (x->v.ll > 0 && i > 0) {
        lldiv_t qr;

        lldiv(&qr, x->v.ll, base);

        x->v.ll = qr.quot;
        buff[--i] = digs[qr.rem];
    }

    x->n1 = BUFF_LEN - i;
    memcpy(x->s, buff + i, x->n1);

    if (x->n1 < x->prec) {
        x->nz0 = x->prec - x->n1;
    }

    if (x->prec < 0 && (x->flags & (FLAGS_MINUS | FLAGS_ZERO)) == FLAGS_ZERO) {
        i = x->width - x->n0 - x->nz0 - x->n1;

        if (i > 0) {
            x->nz0 += i;
        }
    }
}
