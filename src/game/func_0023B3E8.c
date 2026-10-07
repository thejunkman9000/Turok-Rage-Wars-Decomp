#include "b09_types.h"

extern DlCmd *D_80110634;
extern u8 D_80146D20[];
void func_0023A4D0(B09Emitter *, B09Cam *);
void func_0023B928();
s32 func_0023B93C();
s32 func_0023B968();
void func_0026925C();
void func_00285290(B09Emitter **, s32, s32, s32 (*)(), void (*)());

#define GFX(a, b) { DlCmd *p = D_80110634++; p->w0 = (a); p->w1 = (b); }

void func_0023B3E8(B09Scene *sc, B09Cam *cam) {
    B09Emitter *near[4];
    B09Emitter *far[4];
    B09Emitter *e;
    DlCmd *g;
    s32 nn;
    s32 nf;
    s32 i;

    if (sc->unk8C4 != 0 && cam->unk120 == 0) {
        GFX(0xE7000000, 0);
        GFX(0xDA380003, (u32)D_80146D20);
        GFX(0xDB040004, 2);
        GFX(0xDB04000C, 2);
        GFX(0xDB040014, 0xFFFE);
        GFX(0xDB04001C, 0xFFFE);
        GFX(0xD9FEFFFF, 0);
        GFX(0xE3000A01, 0);
        func_0026925C(0xD);
        GFX(0xD9F9FBFF, 0);
        GFX(0xD9FFFFFF, 0x200004);
        GFX(0xE3000C00, 0x80000);
        GFX(0xE3001201, 0x2000);
        nn = 0;
        nf = nn;
        e = sc->emitters;
        if (e != NULL) {
            B09Emitter **pf = far;
            B09Emitter **pn = near;
            do {
                if (e->key > cam->depth) {
                    *pn = e;
                    pn++;
                    nn++;
                } else {
                    *pf = e;
                    pf++;
                    nf++;
                }
                e = e->next;
            } while (e != NULL);
        }
        func_00285290(near, nn, 4, func_0023B93C, func_0023B928);
        func_00285290(far, nf, 4, func_0023B968, func_0023B928);
        for (i = 0; i < nn; i++) {
            func_0023A4D0(near[i], cam);
        }
        for (i = 0; i < nf; i++) {
            func_0023A4D0(far[i], cam);
        }
    }
}
