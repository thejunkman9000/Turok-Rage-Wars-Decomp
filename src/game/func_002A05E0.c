#include "common.h"
double func_0029BEA4(double, double);
double func_002A05E0(const unsigned char *s)
{
    double sign, scale, ip, frac, esign, e, p10;

    sign = 1.0;
    frac = 0.0;
    scale = sign;
    if (*s == ' ') {
        do {
            s++;
        } while (*s == ' ');
    }
    if (*s == '-') {
        s++;
        sign = -1.0;
    }
    if (*s == '+') {
        s++;
    }
    ip = 0.0;
    while (*s >= '0' && *s <= '9') {
        ip = ip * 10.0 + (*s++ - '0');
    }
    if (*s == '.') {
        s++;
        frac = 0.0;
        while (*s >= '0' && *s <= '9') {
            scale *= 10.0;
            frac = frac * 10.0 + (*s++ - '0');
        }
    }
    if (*s == 'e' || *s == 'E') {
        s++;
        esign = 1.0;
        if (*s == '-') {
            s++;
            esign = -1.0;
        }
        if (*s == '+') {
            s++;
        }
        e = 0.0;
        while (*s >= '0' && *s <= '9') {
            e = e * 10.0 + (*s++ - '0');
        }
        if (e < 30.0) {
            p10 = 1.0;
            if (e != 0.0) {
                do {
                    p10 *= 10.0;
                    e -= 1.0;
                } while (e != 0.0);
            }
        } else {
            p10 = func_0029BEA4(10.0, e);
        }
        if (esign < 0.0) {
            return sign * (ip + frac / scale) / p10;
        }
        return sign * (ip + frac / scale) * p10;
    }
    return sign * (ip + frac / scale);
}
