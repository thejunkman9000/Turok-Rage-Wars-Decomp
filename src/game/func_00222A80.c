#include "b05_types.h"

typedef struct B05Ent { s16 id; s16 pad2[2]; s16 unk6; } B05Ent;
typedef struct B05Tab { u8 pad0[0x20]; B05Ent *e20; B05Ent *e24; } B05Tab;
typedef struct B05Plr { u8 pad0[0x594]; s32 mode; u8 pad598[0x5F4 - 0x598]; s16 cnt[1]; } B05Plr;

extern B05Tab *D_800D052C[];

s32 func_00222A80(B05Plr *p, s32 idx) {
    register B05Ent *e asm("$2");
    B05Ent *e2;
    register s32 ix asm("$2");
    B05Tab *tab;
    register s32 v asm("$3");
    tab = D_800D052C[idx];
    if (p->mode == 1) e = tab->e20; else e = tab->e24;
    v = -1;
    if (e != NULL) v = e->id;
    if (v == -1) goto fin;
    if (p->mode == 2) {
        switch (idx) {
        default:
            e2 = D_800D052C[idx]->e24;
            if (e2 != NULL) {
cmp:
            return (ix = v * 2, *(s16 *)((u8 *)p + ix + 0x5F4)) >= e2->unk6;
            }
nf:
            return -1;
        case 4:
            return (ix = v * 2, *(s16 *)((u8 *)p + ix + 0x5F4)) >= 0x30;
        case 3:
            return (ix = v * 2, *(s16 *)((u8 *)p + ix + 0x5F4)) >= 0x19;
        }
    }
    if (p->mode == 1) {
        switch (idx) {
        default:
            e2 = D_800D052C[idx]->e20;
            if (e2 != NULL) goto cmp;
            goto nf;
        case 4:
            return (ix = v * 2, *(s16 *)((u8 *)p + ix + 0x5F4)) >= 5;
        case 3:
            return (ix = v * 2, *(s16 *)((u8 *)p + ix + 0x5F4)) >= 3;
        }
    }
fin:
    return -1;
}
