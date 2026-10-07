#include "common.h"

#ifdef NON_MATCHING
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

/* Near match: all code is identical except that the final `cvt.s.d` of the second polynomial lands in $f1
   (the ROM keeps the double in $f0) instead of in-place in $f0. */
f32 sinf(f32 x) {
    f32 dx;
    f32 dn;
    f32 xsq;
    f32 result;
    f64 poly;
    f32 fpoly;
    s32 n;
    s32 ix;
    s32 xpt;

    ix = *(s32 *)&x;
    xpt = ix >> 22;
    xpt &= 0x1FF;
    dx = x;

    if (xpt < 0xFF) {
        if (xpt >= 0xE6) {
            xsq = dx * dx;
            poly = (((P[4].d * xsq + P[3].d) * xsq + P[2].d) * xsq + P[1].d);
            return dx + dx * xsq * (f32)poly;
        }
        return dx;
    }

    if (xpt < 0x136) {
        dn = dx * rpi.d;
        if (dn >= 0.0f) {
            n = dn + 0.5f;
        } else {
            n = dn - 0.5f;
        }
        dn = n;
        dx = dx - dn * pihi.d;
        dx = dx - dn * pilo.d;

        xsq = dx * dx;
        fpoly = (f32)(((P[4].d * xsq + P[3].d) * xsq + P[2].d) * xsq + P[1].d);
        result = dx + dx * xsq * fpoly;

        if (n & 1) {
            return -result;
        }
        return result;
    }

    return zero.f;
}
#else
INCLUDE_ASM("asm/nonmatchings/libultra/sinf", sinf);
#endif
