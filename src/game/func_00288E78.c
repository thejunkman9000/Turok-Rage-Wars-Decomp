#include "b19_types.h"
extern B19Dl *D_80110634;
void func_002538A8(s32);
void func_00288908(B19Scene *);
s32 func_0028FD94(s32, s32);
void func_0026D980(B19Dl *);
void func_0026D9D0(void);
void func_00250458(void *, void *);
void func_00288E78(B19Scene *sc, void *arg) {
    B19Dl *d1, *d2, *d3, *d4;
    B19Dl *e;
    register void *a asm("$22");
    s32 i;
    B19DlItem **p;
    B19DlItem *it;
    a = arg;
    if (sc->fF8 != 0 || (func_002538A8(0), func_00288908(sc), sc->fF8 != 0)) {
        d1 = D_80110634++;
        d1->w0 = 0xDE000000;
        d1->w1 = func_0028FD94(sc->f88, 2);
        if (sc->dlp[0] == 0) {
            for (i = 0; i < 2; i++) {
                sc->dlp[i] = D_80110634;
                d2 = D_80110634++;
                d2->w0 = 0xDE010000;
                d2->w1 = 0;
                func_0026D980(d2);
                p = (B19DlItem **)func_0028FD94(sc->f88, 1);
                while (*p != 0) {
                    it = *p;
                    p++;
                    switch (i) {
                    case 0:
                        if (!(it->fD8 & 4)) func_00250458(it, a);
                        break;
                    case 1:
                        if (it->fD8 & 4) func_00250458(it, a);
                        break;
                    }
                }
                func_0026D9D0();
                d3 = D_80110634++;
                d3->w0 = 0xDF000000;
                d3->w1 = 0;
                e = sc->dlp[i]++;
                e->w0 = 0xDE010000;
                e->w1 = (u32)D_80110634;
            }
        }
        d4 = D_80110634++;
        d4->w0 = 0xDE000000;
        d4->w1 = (u32)sc->dlp[0];
    }
}
