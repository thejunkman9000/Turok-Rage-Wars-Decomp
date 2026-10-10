#include "m03_types.h"

typedef struct M03Poly {
    /* 0x00 */ s32 kind;
    /* 0x04 */ u8 pad4[0x10];
    /* 0x14 */ s32 n;
    /* 0x18 */ M03V3 v[1];
} M03Poly;

f32 sqrtf(f32 x);
void func_00271FD8(M03V3 *o, M03V3 *a, M03V3 *b);
void func_0027200C(M03V3 *o, M03V3 *a, f32 s);
void func_00272088(M03V3 *o, void *a, M03V3 *b);

s32 func_002406C0(M03Poly *a, M03V3 *p, f32 r) {
    M03V3 c;
    M03V3 e;
    M03V3 d;
    M03V3 *prev;
    register M03V3 *cur __asm__("$20");
    s32 i;
    f32 t;
    register f32 lim __asm__("$f0");
    f32 sm;
    f32 sm2;
    f32 len2;
    register f32 r2 __asm__("$f24");

    if (a->n == 1) return 1;
    {
        prev = &a->v[a->n - 1];
        cur = &a->v[0];
        i = a->n;
        r2 = r * r;
        if ((u32)(a->kind - 3) < 2) {
            i--;
            for (; i != -1; i--) {
                func_00271FD8(&e, cur, prev);
                func_00272088(&c, (u8 *)a + 0x48, &e);
                func_00271FD8(&d, p, prev);
                sm = c.x * d.x + c.y * d.y + c.z * d.z;
                if (sm > 0.0f) {
                    if (!(r > 0.0f)) {
                        return 0;
                    }
                    t = e.x * d.x + e.y * d.y + e.z * d.z;
                    if (t > 0.0f) {
                        len2 = e.x * e.x + e.y * e.y + e.z * e.z;
                        if (!(len2 <= t)) {
                            func_0027200C(&e, &e, t / len2);
                        }
                        func_00271FD8(&d, &d, &e);
                    }
                    if (r2 < d.x * d.x + d.y * d.y + d.z * d.z) {
                        do { return 0; } while (0);
                    }
                }
                prev = cur;
                cur++;
            }
            return 1;
        }
        i--;
        for (; i != -1; i--) {
            func_00271FD8(&e, cur, prev);
            func_00272088(&c, (u8 *)a + 0x48, &e);
            func_00271FD8(&d, p, prev);
            sm = c.x * d.x + c.y * d.y + c.z * d.z;
            if (sm > 0.0f) {
                if (!(r > 0.0f)) {
                    return 0;
                }
                t = e.x * d.x + e.y * d.y + e.z * d.z;
                len2 = e.x * e.x + e.y * e.y + e.z * e.z;
                t = t / len2;
                if (t < 0.0f) {
                    lim = -r / sqrtf(len2);
                    if (t < lim) {
                        return 0;
                    }
                } else if (1.0f < t) {
                    if (r / sqrtf(len2) + 1.0f < t) {
                        return 0;
                    }
                }
                func_0027200C(&e, &e, t);
                func_00271FD8(&d, &d, &e);
                if (r2 < d.x * d.x + d.y * d.y + d.z * d.z) {
                    do { return 0; } while (0);
                }
            }
            prev = cur;
            cur++;
        }
        return 1;
    }
}
