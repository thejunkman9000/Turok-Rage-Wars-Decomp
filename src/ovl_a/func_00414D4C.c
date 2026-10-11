#include "common.h"
#undef va_arg
#define va_arg(AP, TYPE) (((TYPE *)((AP) = (va_list)((((sizeof(TYPE) > 4) ? (((int)(AP) + 7) & -8) : (((int)(AP) + 3) & m4)) + ((sizeof(TYPE) + 3) & -4)))))[-1])

#define ALT 0x10
#define HEXPREFIX 0x20
#define LADJUST 0x40
#define ZEROPAD 0x80
#define LONGDBL 0x1
#define LONGINT 0x2
#define QUADINT 0x4
#define SHORTINT 0x8
#define PADSIZE 16
#define BUFSZ 128
#define to_digit(c) ((c) - '0')
#define is_digit(c) ((unsigned)to_digit(c) <= 9)
#define to_char(n) ((n) + '0')

extern char D_800E3280[];
extern char D_800E3290[];
extern char D_800E11F8[];
extern char D_800E120C[];
extern char D_800E1220[];
int func_00414480(char *buf, double d, int ch, int width, int prec);
void *func_002A17DC();
int func_002A1238();

#define PRINT(p, n) pr(&obuf, (char *)(p), (n))
#define PAD(howmany, with) pad(&obuf, (char *)(with), (howmany))
#define SARG() \
    (flags & LONGINT ? va_arg(ap, long) : \
     flags & SHORTINT ? (long)(short)va_arg(ap, int) : \
     (long)va_arg(ap, int))

static inline void pr(char **pp, char *s, int n) {
    int i;
    for (i = 0; i < n; i++) {
        **pp = s[i];
        (*pp)++;
    }
}

static inline void pad(char **pp, char *with, int howmany) {
    int n;
    if (howmany > 0) {
        n = howmany;
        while (n > PADSIZE) {
            pr(pp, with, PADSIZE);
            n -= PADSIZE;
        }
        pr(pp, with, n);
    }
}

static inline u8 *ultoa(u32 val, u8 *endp, int base, int octzero, char *xdigs) {
    u8 *cp = endp;
    s32 sval;
    switch (base) {
    case 10:
        if (val < 10) {
            *--cp = to_char(val);
            return cp;
        }
        if (val > 0x7FFFFFFF) {
            *--cp = to_char(val % 10);
            sval = val / 10;
        } else
            sval = val;
        do {
            *--cp = to_char(sval % 10);
            sval /= 10;
        } while (sval != 0);
        break;
    case 8:
        do {
            *--cp = to_char(val & 7);
            val >>= 3;
        } while (val);
        if (octzero && *cp != '0')
            *--cp = '0';
        break;
    case 16:
        do {
            *--cp = xdigs[val & 15];
            val >>= 4;
        } while (val);
        break;
    default:
        return 0;
    }
    return cp;
}

static inline u8 *uqtoa(u32 val, u8 *endp, int base, int octzero, char *xdigs) {
    u8 *cp = endp;
    s32 sval;
    switch (base) {
    case 10:
        if (val < 10) {
            *--cp = to_char(val);
            return cp;
        }
        if (val > 0x7FFFFFFF) {
            *--cp = to_char(val % 10);
            sval = val / 10;
        } else
            sval = val;
        do {
            *--cp = to_char(sval % 10);
            sval /= 10;
        } while (sval != 0);
        break;
    case 8:
        do {
            *--cp = to_char(val & 7);
            val >>= 3;
        } while (val);
        if (octzero && *cp != '0')
            *--cp = '0';
        break;
    case 16:
        do {
            *--cp = xdigs[val & 15];
            val >>= 4;
        } while (val);
        break;
    default:
        return 0;
    }
    return cp;
}

int func_00414D4C(char *obuf, const char *fmt0, va_list ap) {
    const unsigned char *fmt;
    unsigned char ch;
    int n;
    int pn;
    u8 *cp;
    int flags;
    int ret;
    int width;
    int prec;


    u32 ulval;
    u32 uqval;
    int base;
    int dprec;
    int fieldsz;
    int realsz;
    int size;
    char *xdigs;
    va_list *pap;

    u8 buf[BUFSZ];
    char ox[2];
    u8 sign;
    s32 m4;
    double _double;

    uqval = ulval = 0;
    xdigs = 0;
    fmt = (const unsigned char *)fmt0;
    ret = 0;
    m4 = -4;
    for (;;) {
    __asm__("" : : "r"(fmt));
        __asm__("" : : "r"(m4));
        __asm__("" : : "r"(m4));
        __asm__("" : : "r"(m4));
        for (cp = (u8 *)fmt; (ch = *fmt) != '\0' && ch != '%'; fmt++)
            ;
        if ((n = (u8 *)fmt - cp) != 0) {
            PRINT(cp, n);
            ret += n;
        }
        if (ch == '\0')
            goto done;
        fmt++;
        flags = 0;
        dprec = 0;
        width = 0;
        prec = -1;
        sign = '\0';
rflag:
        ch = *fmt++;
reswitch:
        switch (ch) {
        case ' ':
            if (!sign)
                sign = ' ';
            goto rflag;
        case '#':
            flags |= ALT;
            goto rflag;
        case '*':
            if ((width = va_arg(ap, int)) >= 0)
                goto rflag;
            width = -width;
        case '-':
            flags |= LADJUST;
            goto rflag;
        case '+':
            sign = '+';
            goto rflag;
        case '.':
            if ((ch = *fmt++) == '*') {
                prec = va_arg(ap, int);
                if (prec < 0)
                    prec = -1;
                goto rflag;
            }
            n = 0;
            if (!is_digit(ch)) goto Lp2;
        Lp1:
            n = 10 * n + to_digit(ch);
            ch = *fmt++;
            if (is_digit(ch)) goto Lp1;
        Lp2:
            prec = n;
            if (prec < 0)
                prec = -1;
            goto reswitch;
        case '0':
            flags |= ZEROPAD;
            goto rflag;
        case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            n = 0;
        Lw1:
            n = 10 * n + to_digit(ch);
            ch = *fmt++;
            if (is_digit(ch)) goto Lw1;
            width = n;
            goto reswitch;
        case 'L':
            flags |= LONGDBL;
            goto rflag;
        case 'h':
            flags |= SHORTINT;
            goto rflag;
        case 'l':
            flags |= LONGINT;
            goto rflag;
        case 'q':
            flags |= QUADINT;
            goto rflag;
        case 'c':
            *(cp = buf) = va_arg(ap, int);
            size = 1;
            sign = '\0';
            break;
        case 'D':
            flags |= LONGINT;
        case 'd':
        case 'i':
            if (flags & QUADINT) {
                uqval = va_arg(ap, int);
                if ((int)uqval < 0) {
                    uqval = -uqval;
                    sign = '-';
                }
            } else {
                pap = &ap;
                switch (flags & (QUADINT | LONGINT | SHORTINT | LONGDBL)) {
                case LONGDBL: case LONGINT: case QUADINT:
                    ulval = va_arg(ap, long);
                    break;
                case SHORTINT:
                    ulval = (short)va_arg(ap, int);
                    break;
                default:
                    ulval = va_arg(*pap, int);
                    break;
                }
                if ((long)ulval < 0) {
                    ulval = -ulval;
                    sign = '-';
                }
            }
            base = 10;
            goto number;
        case 'g':
        case 'G':
            if (prec == 0)
                prec = 1;
        case 'e':
        case 'E':
        case 'f':
            if (sign == '+') {
                PRINT(&sign, 1);
                width--;
                ret++;
            }
            if (prec == -1)
                prec = 6;
            { va_list t = (va_list)((((int)ap + 7) & -8) + 8); _double = *(double *)(t - 8); ap = t; }
            if (flags & LADJUST)
                width = -width;
            size = func_00414480(buf, _double, ch, width, prec);
            if (flags & ZEROPAD) {
                for (n = 0; buf[n] == ' '; n++)
                    buf[n] = '0';
            }
            PRINT(buf, size);
            if (flags & LADJUST)
                PAD(-width - size, D_800E3280);
            ret += width > size ? width : size;
            continue;
        case 'n':
            if (flags & QUADINT)
                *va_arg(ap, int *) = ret;
            else if (flags & LONGINT)
                *va_arg(ap, int *) = ret;
            else if (flags & SHORTINT)
                *va_arg(ap, short *) = ret;
            else
                *va_arg(ap, int *) = ret;
            continue;
        case 'o':
            if (flags & QUADINT)
                uqval = va_arg(ap, int);
            else {
                pap = &ap;
                switch (flags & (QUADINT | LONGINT | SHORTINT | LONGDBL)) {
                case LONGDBL: case LONGINT: case QUADINT:
                    ulval = va_arg(ap, long);
                    break;
                case SHORTINT:
                    ulval = (u16)va_arg(ap, int);
                    break;
                default:
                    ulval = va_arg(*pap, int);
                    break;
                }
            }
            base = 8;
            goto nosign;
        case 'p':
            ulval = (u32)va_arg(ap, void *);
            base = 16;
            xdigs = D_800E11F8;
            flags &= ~QUADINT;
            ch = 'x';
            if (prec < 0)
                prec = 8;
            goto nosign;
        case 's':
            cp = va_arg(ap, u8 *);
            if (prec >= 0) {
                u8 *p = func_002A17DC(cp, 0, prec);
                if (p != 0) {
                    size = p - cp;
                    if (size > prec)
                        size = prec;
                } else
                    size = prec;
            } else
                size = func_002A1238(cp);
            sign = '\0';
            break;
        case 'U':
            flags |= LONGINT;
        case 'u':
            if (flags & QUADINT)
                uqval = va_arg(ap, int);
            else {
                pap = &ap;
                switch (flags & (QUADINT | LONGINT | SHORTINT | LONGDBL)) {
                case LONGDBL: case LONGINT: case QUADINT:
                    ulval = va_arg(ap, long);
                    break;
                case SHORTINT:
                    ulval = (u16)va_arg(ap, int);
                    break;
                default:
                    ulval = va_arg(*pap, int);
                    break;
                }
            }
            base = 10;
            goto nosign;
        case 'X':
            xdigs = D_800E120C;
            goto hex;
        case 'x':
            xdigs = D_800E11F8;
hex:
            if (flags & QUADINT)
                uqval = va_arg(ap, int);
            else {
                pap = &ap;
                switch (flags & (QUADINT | LONGINT | SHORTINT | LONGDBL)) {
                case LONGDBL: case LONGINT: case QUADINT:
                    ulval = va_arg(ap, long);
                    break;
                case SHORTINT:
                    ulval = (u16)va_arg(ap, int);
                    break;
                default:
                    ulval = va_arg(*pap, int);
                    break;
                }
            }
            base = 16;
            if (flags & ALT && (flags & QUADINT ? uqval != 0 : ulval != 0))
                flags |= HEXPREFIX;
nosign:
            sign = '\0';
number:
            if ((dprec = prec) >= 0)
                flags &= ~ZEROPAD;
            cp = buf + BUFSZ;
            if (flags & QUADINT) {
                if (uqval != 0 || prec != 0)
                    cp = uqtoa(uqval, cp, base, flags & ALT, xdigs);
            } else {
                if (ulval != 0 || prec != 0)
                    cp = ultoa(ulval, cp, base, flags & ALT, xdigs);
            }
            size = buf + BUFSZ - cp;
            break;
        default:
            if (ch == '\0')
                goto done;
            cp = buf;
            *cp = ch;
            size = 1;
            sign = '\0';
            break;
        }
        realsz = dprec > size ? dprec : size;
        if (sign)
            realsz++;
        else if (flags & HEXPREFIX)
            realsz += 2;
        if ((flags & (LADJUST | ZEROPAD)) == 0)
            PAD(width - realsz, D_800E3280);
        if (sign) {
            PRINT(&sign, 1);
        } else if (flags & HEXPREFIX) {
            ox[0] = '0';
            ox[1] = ch;
            PRINT(ox, 2);
        }
        if ((flags & (LADJUST | ZEROPAD)) == ZEROPAD)
            PAD(width - realsz, D_800E3290);
        PAD(dprec - size, D_800E3290);
        PRINT(cp, size);
        if (flags & LADJUST)
            PAD(width - realsz, D_800E3280);
finish:
        ret += width > realsz ? width : realsz;
    }
done:
    PRINT(D_800E1220, 1);
    return ret;
}
