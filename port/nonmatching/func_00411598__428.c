#include "o02_types.h"
typedef struct { u8 pad0[4]; s32 w4; u16 flags8; u8 padA[2]; s32 wC; u8 pad10[0x2C-0x10]; } S_ent;
typedef struct { s32 w0; u8 pad4[0x300]; s32 tbl[0x60]; S_ent **p484; u8 pad488[4]; struct { u8 pad[0xE]; s16 n; } *p48C; u8 b490; u8 pad491[0x49C-0x491]; } S_obj;
extern S_obj *D_80153C28;
void func_004196A4(void *p);
void func_00254784(s32 p);
void func_00411598(s32 i) {
    s32 j, k;
    S_ent *e;
    for (j = 0; j < D_80153C28[i].p48C->n; j++) {
        e = D_80153C28[i].p484[j];
        for (k = 0; k < 0x60; k++) {
            u16 *h = (u16 *)((u8 *)e + k * 0x2C + 8);
            if (*h & 1) {
                func_004196A4((u8 *)e + k * 0x2C + 0xC);
                *h = *h & 0xFFFE;
            }
        }
    }
    if (D_80153C28[i].tbl[0]) {
        func_00254784(D_80153C28[i].tbl[0]);
        D_80153C28[i].tbl[0] = 0;
        for (k = 0; k < 0x60; k++) {
            *(s32 *)((u8 *)D_80153C28 + i * 0x49C + 0x304 + k * 4) = 0;
        }
    }
    D_80153C28[i].w0 = 0;
}
