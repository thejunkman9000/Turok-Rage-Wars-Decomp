#include "common.h"

f64 func_0029EAA0(f64 x, f64 *ip);

/* printf-style double formatter ("%[width].[prec]f/e/g", right justified with spaces; used by the vfprintf clone func_00414D4C).
 * out: destination, d: value, ch: 'f', 'g' or anything else (= 'e' style), width: field width, prec: digits (clamped to 126).
 * Returns the number of characters written (without the terminating 0).  func_0029EAA0 is modf(). */
int func_00414480(char *out, f64 d, u8 ch, int width, int prec)
{
    u8 buf[256];
    u8 expb[16];
    f64 ip, t1, ip2, t2;
    int neg;
    u8 *p, *e, *e0, *x, *q, *a1p, *op;
    int ndig, nint, nexp, i, j, dof, carry, lim, k, e10, n, iv, padn;
    u8 dg;
    u8 sgn;
    f64 pw, rnd, fr, b, acc, lim2, f2;
    int n2;

    p = buf;
    e = &buf[255];
    x = &expb[15];
    e0 = e;
    buf[255] = 0;
    expb[15] = 0;
    neg = d < 0.0;
    if (neg)
        d = -d;
    if (prec >= 127)
        prec = 126;
    /* pw = 10^prec (by repeated squaring; negative prec uses 0.1^-prec) */
    if (prec == 6) {
        pw = 1000000.0;
        dof = 0;
    } else {
        n = prec;
        b = 10.0;
        if (prec == 0) {
            pw = 1.0;
            dof = 0;
        } else {
            if (prec < 0) {
                n = -prec;
                b = 0.1;
            }
            acc = 1.0;
            for (;;) {
                if (n & 1)
                    acc *= b;
                n >>= 1;
                if (n == 0)
                    break;
                b *= b;
            }
            pw = acc;
            dof = 0;
        }
    }
    rnd = 0.5 / pw;
    /* dof: fixed-point layout ('f', or 'g' with 1e-4 <= d < 10^prec, or d == 0) */
    if (ch == 'f')
        goto L614;
    nint = 0;
    if (ch != 'g')
        goto L61C;
    if (d == 0.0)
        goto L614;
    ndig = nint;
    if (!(1e-4f <= d))
        goto L620;
    if (!(d < pw))
        goto L620;
L614:
    dof = 1;
    nint = 0;
L61C:
    ndig = nint;
L620:
    nexp = nint;
    if (dof == 0)
        goto L994;
    /* fixed point: fraction digits go up from buf, integer digits down from buf + 255 */
    fr = func_0029EAA0(d, &ip);
    if (rnd <= fr) {
        fr += rnd;
    } else {
        if (ch == 'g')
            goto L714;
        fr += rnd;
    }
    if (1.0 <= fr) {
        ip += 1.0;
        fr -= 1.0;
    }
    f2 = fr;
    i = 0;
    if (nexp < prec) {
        do {
            f2 = func_0029EAA0(f2 * 10.0, &t1);
            ndig++;
            i++;
            *p = (int)t1 + '0';
            p++;
        } while (i < prec);
    }
    if (ch == 'g') {
        /* strip trailing zeros of the fraction */
        for (q = p - 1; q >= buf; q--) {
            if (*q != '0')
                break;
            *q = 0;
            ndig--;
        }
    }
L714:
    if (ip == 0.0) {
        if (ch != 'g')
            goto L75C;
        if (ndig < prec)
            goto L75C;
        if (ndig < width)
            goto L75C;
        goto L858;
L75C:
        e--;
        *e = '0';
        nint++;
        goto L850;
    } else if (ip <= 2147483647.0) {
        iv = (int)ip;
        if (iv != 0) {
            do {
                e--;
                nint++;
                *e = (iv % 10) + '0';
                iv /= 10;
            } while (iv != 0);
        }
        goto L850;
    } else if (0.5 < ip) {
        do {
            e--;
            fr = func_0029EAA0(ip * 0.1, &ip);
            *e = (int)((fr + 0.05f) * 10.0) + '0';
            nint++;
        } while (0.5 < ip);
    }
L850:
    ;
L858:
    if (ch != 'g')
        goto L408;
    /* 'g': drop surplus digits (round half up, carry through the fraction, then the integer part) */
    lim = prec;
    if (lim < width)
        lim = width;
    k = nint + ndig - lim;
    if (ndig < k)
        k = ndig;
    if (k <= 0)
        goto L408;
    a1p = &buf[ndig - 1];
    if (a1p < buf)
        goto L408;
    for (;;) {
        if (k <= 0)
            goto L408;
        ndig--;
        dg = *a1p;
        *a1p = 0;
        if (dg >= '6') {
            carry = 1;
            for (q = a1p - 1; q >= buf; q--) {
                if (carry == 0)
                    break;
                *q = *q + 1;
                if (*q >= ':')
                    *q = '0';
                else
                    carry = 0;
            }
            if (carry != 0) {
                for (q = e0 - 1; q >= e; q--) {
                    if (carry == 0)
                        break;
                    *q = *q + 1;
                    if (*q >= ':')
                        *q = '0';
                    else
                        carry = 0;
                }
                if (carry != 0) {
                    e--;
                    *e = '1';
                    nint++;
                    k--;
                }
            }
            /* the empty loop makes reorg predict the join below as taken (branch-likely with the a1p-- slot) */
            do {
            } while (0);
        }
        a1p--;
        k--;
        if (a1p < buf)
            goto L408;
    }

L994:
    /* exponent layout: scale d into [1, 10) */
    e10 = 0;
    if (10.0 <= d) {
        do {
            d *= 0.1f;
            e10++;
        } while (10.0 <= d);
    }
    lim2 = 1.0 - rnd;
    while (0.0 < d && d < lim2) {
        d *= 10.0;
        e10--;
    }
    fr = func_0029EAA0(d, &ip2);
    if (ch == 'g') {
        pw *= 0.1;
        __asm__("" : : "f"(pw)); /* keeps pw in $f20 (higher allocation priority than rnd) */
        rnd = 0.5 / pw;
        prec--;
    }
    if (rnd <= fr) {
        fr += rnd;
    } else {
        if (ch == 'g')
            goto LB48;
        fr += rnd;
    }
    if (1.0 <= fr) {
        fr -= 1.0;
        ip2 += 1.0;
        if (10.0 <= ip2) {
            e10++;
            ip2 *= 0.1;
            fr *= 0.1;
        }
    }
    f2 = fr;
    i = 0;
    if (prec > 0) {
        do {
            f2 = func_0029EAA0(f2 * 10.0, &t2);
            ndig++;
            i++;
            *p = (int)t2 + '0';
            p++;
        } while (i < prec);
    }
    if (ch == 'g') {
        for (q = p - 1; q >= buf; q--) {
            if (*q != '0')
                break;
            *q = 0;
            ndig--;
        }
    }
LB48:
    /* exponent digits, sign, 'e' go (backwards) into expb */
    sgn = e10 < 0;
    if (e10 < 0)
        e10 = -e10;
    if (e10 > 0) {
        do {
            x--;
            nexp++;
            *x = (e10 % 10) + '0';
            e10 /= 10;
        } while (e10 > 0);
    }
    if (nexp < 2) {
        do {
            x--;
            nexp++;
            *x = '0';
        } while (nexp < 2);
    }
    x--;
    if (sgn != 0)
        *x = '-';
    else
        *x = '+';
    x--;
    nexp += 2;
    *x = 'e';
    e--;
    nint++;
    *e = (int)ip2 + '0';
L408:
    /* output: padding, '-', integer digits, '.' + fraction digits, exponent */
    n2 = 0;
    if (ch != 'g' || ndig > 0)
        n2 = 1;
    padn = width - (neg + nint + n2 + ndig + nexp);
    if (padn < 0)
        padn = 0;
    op = (u8 *)out;
    for (j = 0; j < padn; j++)
        *op++ = ' ';
    if (neg != 0)
        *op++ = '-';
    for (j = 0; j < nint; j++)
        *op++ = *e++;
    if (n2 != 0) {
        *op++ = '.';
        p = buf;
        for (j = 0; j < ndig; j++)
            *op++ = *p++;
    }
    for (j = 0; j < nexp; j++)
        *op++ = *x++;
    *op = 0;
    return op - (u8 *)out;
}
