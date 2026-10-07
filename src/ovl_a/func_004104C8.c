#include "o02_types.h"
typedef struct { u8 pad0[4]; s32 w4; u16 flags8; u8 padA[2]; s32 wC; u8 pad10[0x2C-0x10]; } S_ent;
typedef struct { s32 w0; u8 pad4[0x480]; S_ent **p484; u8 pad488[4]; struct { u8 pad[0xE]; s16 n; } *p48C; u8 b490; u8 pad491[0x49C-0x491]; } S_obj;
typedef struct { s32 id; s16 cnt; s16 pad; } S_e;
typedef struct { u8 pad[4]; s32 flags; u8 pad2[0x1C-8]; } S_o;
extern S_obj *D_80153C28;
extern S_e *D_80153C18;
extern S_o *D_80153C10;
typedef struct { s16 n; u8 pad[0x46]; s32 mode; } S_v;
extern S_v D_80153C0C;
extern s16 D_80153C20;
s32 func_002A2934(void);
void func_004196A4(void *p);
void func_00411598(s32 i);
void func_00411B70(s32 i);
void func_004104C8(void) {
    s32 i, j, k;
    s32 t;
    S_ent *e;
    S_e *q;
    t = func_002A2934();
    if (D_80153C0C.mode == 0) {
        for (i = 0; i < D_80153C0C.n; i++) {
            if (D_80153C10[i].flags & 1) {
                q = D_80153C18 + i;
                if (q->id != -1 && q->cnt == 0 && q->id < t) {
                    func_00411B70(i);
                    return;
                }
            }
        }
        for (i = 0; i < D_80153C20; i++) {
            if (D_80153C28[i].b490 && D_80153C28[i].w0) {
                for (j = 0; j < D_80153C28[i].p48C->n; j++) {
                    e = D_80153C28[i].p484[j];
                    for (k = 0; k < 0x60; k++) {
                        u16 *h = (u16 *)((u8 *)e + k * 0x2C + 8);
                        if (*h & 1) {
                            if (*(s32 *)((u8 *)e + k * 0x2C + 4) < t) {
                                func_004196A4((u8 *)e + k * 0x2C + 0xC);
                                *h = *h & 0xFFFE;
                                *(s32 *)((u8 *)e + k * 0x2C + 4) = 0;
                                D_80153C28[i].b490--;
                                if (D_80153C28[i].b490 != 0) return;
                            }
                        }
                    }
                }
                if (D_80153C28[i].b490 == 0) {
                    func_00411598(i);
                    D_80153C28[i].w0 = 0;
                }
            }
        }
    }
}
