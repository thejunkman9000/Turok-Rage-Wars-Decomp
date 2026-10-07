#include "b05_types.h"

typedef struct B05Ent { s16 id; s16 pad2[2]; s16 unk6; } B05Ent;
typedef struct B05Tab { u8 pad0[0x20]; B05Ent *e20; B05Ent *e24; } B05Tab;
typedef struct B05Plr { u8 pad0[0x594]; s32 mode; u8 pad598[0x5F4 - 0x598]; s16 cnt[1]; } B05Plr;

extern B05Tab *D_800D052C[];

s32 func_00222A80(B05Plr *p, s32 idx) {
    B05Ent *e;
    s16 v;

    v = -1;
    if (p->mode == 1) {
        e = D_800D052C[idx]->e20;
    } else {
        e = D_800D052C[idx]->e24;
    }
    if (e != NULL) {
        v = e->id;
    }
    if (v != -1) {
        if (p->mode == 2) {
            if (idx == 3) {
                return p->cnt[v] >= 0x19;
            }
            if (idx == 4) {
                return p->cnt[v] >= 0x30;
            }
            e = D_800D052C[idx]->e24;
            if (e != NULL) {
                return p->cnt[v] >= e->unk6;
            }
            return -1;
        }
        if (p->mode == 1) {
            if (idx == 3) {
                return p->cnt[v] >= 3;
            }
            if (idx == 4) {
                return p->cnt[v] >= 5;
            }
            e = D_800D052C[idx]->e20;
            if (e == NULL) {
                return -1;
            }
            return p->cnt[v] >= e->unk6;
        }
    }
    return -1;
}
