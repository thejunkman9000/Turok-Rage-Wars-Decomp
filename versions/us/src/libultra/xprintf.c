#include "common.h"

#define MAX_PAD 32

#define isdigit(c) ((c) >= '0' && (c) <= '9')

extern char spaces[];
extern char zeroes[];

static void _Putfld(_Pft *x, va_list *pap, u8 code, u8 *ac);

static const u8 fchar[] = " +-#0";
static const u32 fbit[] = { FLAGS_SPACE, FLAGS_PLUS, FLAGS_MINUS, FLAGS_HASH, FLAGS_ZERO, 0 };

#define PUT(s, n)                          \
    if ((n) > 0) {                         \
        arg = (*prout)(arg, (s), (n));     \
        if (arg != NULL) {                 \
            x.nchar += (n);                \
        } else {                           \
            return x.nchar;                \
        }                                  \
    }

#define PAD(s, n)                                      \
    if ((n) > 0) {                                     \
        s32 i;                                         \
        s32 j = (n);                                   \
        for (; j > 0; j -= i) {                        \
            i = (u32)j > MAX_PAD ? MAX_PAD : j;        \
            PUT(s, i)                                  \
        }                                              \
    }

s32 _Printf(char *(*prout)(char *, const char *, u32), char *arg, const char *fmt, va_list args) {
    _Pft x;
    u8 ac[32];

    x.nchar = 0;

    while (TRUE) {
        const u8 *s;
        s32 c;
        s32 n;
        const u8 *t;

        s = (const u8 *)fmt;
        while ((c = *s) != 0 && c != '%') {
            s++;
        }
        n = s - (const u8 *)fmt;
        PUT(fmt, n)
        if (c == 0) {
            return x.nchar;
        }
        fmt = (const char *)++s;

        for (x.flags = 0; (t = strchr(fchar, *s)) != NULL; s++) {
            x.flags |= fbit[t - fchar];
        }

        if (*s == '*') {
            { s32 w; s32 *ip = (s32 *)(((u32)args + 3) & ~3); w = *ip; args = (va_list)(ip + 1); x.width = w; }
            if (x.width < 0) {
                x.width = -x.width;
                x.flags |= FLAGS_MINUS;
            }
            s++;
        } else {
            for (x.width = 0; isdigit(*s); s++) {
                if (x.width < 999) {
                    x.width = x.width * 10 + *s - '0';
                }
            }
        }

        if (*s != '.') {
            x.prec = -1;
        } else if (*++s == '*') {
            { s32 w; s32 *ip = (s32 *)(((u32)args + 3) & ~3); w = *ip; ++s; args = (va_list)(ip + 1); x.prec = w; }
        } else {
            for (x.prec = 0; isdigit(*s); s++) {
                if (x.prec < 999) {
                    x.prec = x.prec * 10 + *s - '0';
                }
            }
        }

        x.qual = strchr("hlL", *s) ? *s++ : '\0';
        if (x.qual == 'l' && *s == 'l') {
            x.qual = 'L';
            ++s;
        }

        _Putfld(&x, &args, *s, ac);

        x.width -= x.n0 + x.nz0 + x.n1 + x.nz1 + x.n2 + x.nz2;

        if (!(x.flags & FLAGS_MINUS)) {
            PAD(spaces, x.width)
        }
        PUT(ac, x.n0)
        PAD(zeroes, x.nz0)
        PUT(x.s, x.n1)
        PAD(zeroes, x.nz1)
        PUT(x.s + x.n1, x.n2)
        PAD(zeroes, x.nz2)
        if (x.flags & FLAGS_MINUS) {
            PAD(spaces, x.width)
        }

        fmt = (const char *)s + 1;
    }
}

static void _Putfld(_Pft *x, va_list *pap, u8 code, u8 *ac) {
    x->n0 = x->nz0 = x->n1 = x->nz1 = x->n2 = x->nz2 = 0;

    switch (code) {
    case 'c':
        ac[x->n0++] = va_arg(*pap, s32);
        break;

    case 'd':
    case 'i':
        if (x->qual == 'l') {
            x->v.ll = va_arg(*pap, s32);
        } else if (x->qual == 'L') {
            x->v.ll = va_arg(*pap, s64);
        } else {
            x->v.ll = va_arg(*pap, s32);
        }
        if (x->qual == 'h') {
            x->v.ll = (s16)x->v.ll;
        }
        if (x->v.ll < 0) {
            ac[x->n0++] = '-';
        } else if (x->flags & FLAGS_PLUS) {
            ac[x->n0++] = '+';
        } else if (x->flags & FLAGS_SPACE) {
            ac[x->n0++] = ' ';
        }
        x->s = &ac[x->n0];
        _Litob(x, code);
        break;

    case 'o':
    case 'u':
    case 'x':
    case 'X':
        if (x->qual == 'l') {
            x->v.ll = va_arg(*pap, s32);
        } else if (x->qual == 'L') {
            x->v.ll = va_arg(*pap, s64);
        } else {
            x->v.ll = va_arg(*pap, s32);
        }
        if (x->qual == 'h') {
            x->v.ll = (u16)x->v.ll;
        } else if (x->qual == '\0') {
            x->v.ll = (u32)x->v.ll;
        }
        if (x->flags & FLAGS_HASH) {
            ac[x->n0++] = '0';
            if (code == 'x' || code == 'X') {
                ac[x->n0++] = code;
            }
        }
        x->s = &ac[x->n0];
        _Litob(x, code);
        break;

    case 'e':
    case 'E':
    case 'f':
    case 'g':
    case 'G':
        x->v.ld = va_arg(*pap, f64);
        if (((u16 *)&x->v.ld)[0] & 0x8000) {
            ac[x->n0++] = '-';
        } else if (x->flags & FLAGS_PLUS) {
            ac[x->n0++] = '+';
        } else if (x->flags & FLAGS_SPACE) {
            ac[x->n0++] = ' ';
        }
        x->s = &ac[x->n0];
        _Ldtob(x, code);
        break;

    case 'n':
        if (x->qual == 'h') {
            *va_arg(*pap, s16 *) = x->nchar;
        } else if (x->qual == 'l') {
            *va_arg(*pap, s32 *) = x->nchar;
        } else if (x->qual == 'L') {
            *va_arg(*pap, s64 *) = x->nchar;
        } else {
            *va_arg(*pap, s32 *) = x->nchar;
        }
        break;

    case 'p':
        x->v.ll = (s32)va_arg(*pap, void *);
        x->s = &ac[x->n0];
        _Litob(x, 'x');
        break;

    case 's':
        x->s = va_arg(*pap, u8 *);
        x->n1 = strlen(x->s);
        if (x->prec >= 0 && x->prec < x->n1) {
            x->n1 = x->prec;
        }
        break;

    case '%':
        ac[x->n0++] = '%';
        break;

    default:
        ac[x->n0++] = code;
        break;
    }
}
