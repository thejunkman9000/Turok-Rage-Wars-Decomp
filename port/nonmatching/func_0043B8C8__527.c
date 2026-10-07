#include "o06_types.h"
typedef struct { u8 pad[0x4C]; u8 unk4C[0x4C]; } O06R;
typedef struct { u8 pad[0x4B0]; s32 unk4B0; u8 pad2[0x1C]; } O06P;
typedef struct { O06P base; s32 unk4D0; s32 unk4D4; } O06Q;
typedef struct { s32 unk0; s32 unk4; s32 unk8; s32 unkC; } O06T;
extern O06R D_80146398[];
extern O06P *D_800E59E0;
extern O06T D_800E5BC4[];
extern O06T D_800E5B14[];
extern O06T D_800E5B44[];
void func_0043B8C8(s32 a) {
    O06P *base;
    O06P *slot;
    O06R *row;
    O06T *tab;
    s32 i, k, n, off, cnt, so;
     if (((O06Q *)((u8 *)D_800E59E0 + a * 0x4D0))->unk4D4 == 0) return; 
    row = (O06R *)((u8 *)D_80146398 + a * 0x96);
    base = D_800E59E0;
    so = a * 0x4D0;
    slot = (O06P *)((u8 *)base + so);
    for (i = 0; i < 8; i++) {
        if (((O06Q *)slot)->unk4D4 == 1) {
            switch (i) {
            case 4: tab = D_800E5B14; n = 3; off = 2; break;
            case 5: tab = D_800E5B44; n = 8; off = 1; break;
            case 1: tab = D_800E5BC4; n = 4; off = 0; break;
            default: continue;
            }
        } else {
            switch (i) {
            case 4: tab = D_800E5B14; n = 3; off = 4; break;
            case 5: tab = D_800E5B44; n = 8; off = 2; break;
            case 1: tab = D_800E5BC4; n = 4; off = 0; break;
            default: continue;
            }
        }
        cnt = off;
        for (k = 0; k < n; k++) {
            if (row->unk4C[tab[k].unk8] == 1) {
                *(s32 *)((u8 *)base + (so + cnt * 4) + 0x4B8) = k;
                cnt++;
            }
        }
    }
}

