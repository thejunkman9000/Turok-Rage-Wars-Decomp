#include "common.h"

typedef union {
    struct {
#ifdef TARGET_PC
        u32 lo;
        u32 hi;
#else
        u32 hi;
        u32 lo;
#endif
    } w;
    f64 d;
} du;

typedef union {
    u32 w;
    f32 f;
} fu;

#ifdef TARGET_PC
#define DU(h, l) { { l, h } }       /* the host is little-endian: the double sits as lo,hi in memory */
#else
#define DU(h, l) { { h, l } }
#endif
static const du P[] = {
    DU(0x3FF00000, 0x00000000),
    DU(0xBFC55554, 0xBC83656D),
    DU(0x3F8110ED, 0x3804C2A0),
    DU(0xBF29F6FF, 0xEEA56814),
    DU(0x3EC5DBDF, 0x0E314BFE),
};

static const du rpi = DU(0x3FD45F30, 0x6DC9C883);
static const du pihi = DU(0x400921FB, 0x50000000);
static const du pilo = DU(0x3E6110B4, 0x611A6263);
static const fu zero = { 0x00000000 };

f32 cosf(f32 x) {
    f64 dx;
    f64 xsq;
    f64 poly;
    f64 dn;
    s32 n;
    s32 ix;
    s32 xpt;

    ix = *(s32 *)&x;
    xpt = (ix >> 22) & 0x1FF;

    if (xpt < 0x136) {
        dx = fabsf(x);
        dn = dx * rpi.d + 0.5;
        if (dn >= 0.0) {
            n = dn + 0.5;
        } else {
            n = dn - 0.5;
        }
        dn = n;
        dn -= 0.5;
        dx = dx - dn * pihi.d;
        dx = dx - dn * pilo.d;

        xsq = dx * dx;
        poly = (((P[4].d * xsq + P[3].d) * xsq + P[2].d) * xsq + P[1].d);
        poly = dx + dx * xsq * poly;

        if (!(n & 1)) {
            return (f32)poly;
        }
        return -(f32)poly;
    }

    return zero.f;
}
