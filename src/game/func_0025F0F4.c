#include "common.h"

typedef struct R05Tab { s32 n; s32 off[1]; } R05Tab;
typedef struct R05V4 { f32 v[4]; } R05V4;
typedef void (*R05Fn)(s32 *, s32 *, s32);

extern const f32 D_800C91F8;
extern s32 D_8010EC84;
extern s32 D_8010EC88;

void func_0025EF54(s32 *p, s32 *q, s32 r);
void func_002611A0(s32 *p, s32 *q, s32 r);
void func_00261258(s32 *p, s32 *q, s32 r);
s32 func_00260684(s32 seed);
void func_002607D8(s32 *p, s32 x);
void func_00274214(R05V4 *p);
R05V4 *func_0028FD94(R05Tab *tab, s32 i);

s32 func_0025F0F4(s32 seed, R05Tab *tab, s32 n, s32 m, s32 blur, s32 kind)
{
    R05Fn fn;
    s32 sp10;
    s32 i;
    s32 j;
    s32 k;
    s32 d;
    s32 a1;
    s32 *q;
    f32 *t0;
    f32 *r3;
    R05V4 *r5;
    f32 sum;
    f32 cnt;

    fn = 0;
    switch (kind) {
    case 0:
        fn = func_002611A0;
        break;
    case 1:
        fn = func_0025EF54;
        break;
    case 2:
        fn = func_00261258;
        break;
    }
    a1 = 1;
    tab->n = n;
    tab->off[0] = (n * 4 + 0xF) & ~7;
    if (n > 0) {
        do {
            tab->off[a1] = 0xDEADBEEF;
            a1++;
        } while (n >= a1);
    }
    i = 0;
    if (n > 0) {
        s32 t = D_8010EC88 << 4;
        do {
            for (a1 = 0; a1 <= tab->n; a1++) {
                if (tab->off[a1] == 0xDEADBEEF) {
                    break;
                }
            }
            a1--;
            i++;
            tab->off[a1 + 1] = tab->off[a1] + t;
        } while (i < n);
    }
    i = 0;
    sp10 = func_00260684(seed);
    if (n > 0) {
        do {
            r3 = func_0028FD94(tab, i);
            j = 0;
            if (m > 0) {
                q = (s32 *)r3;
                do {
                    func_002607D8(&sp10, 0x1F);
                    fn(&sp10, q, D_8010EC84);
                    q++;
                    j++;
                } while (j < m);
            }
            i++;
        } while (i < n);
    }
    i = 0;
    if (n > 0) {
        do {
            t0 = func_0028FD94(tab, i);
            if (m == 4 && blur != 0) {
                s32 D;
                k = 0;
                D = D_8010EC88;
                do {
                    for (j = 0; j < D; j++) {
                        sum = 0.0f;
                        cnt = 0.0f;
                        for (d = -blur; d <= blur; d++) {
                            s32 idx = (j + d + D) % D;
                            cnt += D_800C91F8;
                            sum += t0[idx * 4 + k];
                        }
                        t0[j * 4 + k] = sum / cnt;
                    }
                    k++;
                } while (k < m);
            }
            i++;
        } while (i < n);
    }
    if (m == 4) {
        if (n > 0) {
            j = 0;
            do {
                r5 = func_0028FD94(tab, j);
                for (i = 0; i < D_8010EC88; i++) {
                    func_00274214(&r5[i]);
                }
                j++;
            } while (j < n);
        }
    }
    return 1;
}