#include "o06_types.h"
typedef struct { u8 pad[0x4C]; u8 unk4C[0x16]; u8 unk62[0x16]; u8 pad78[0]; } O06R0;
typedef struct { u8 pad[0x4C]; u8 unk4C[0x16]; u8 unk62[0x16]; u8 unk78; u8 pad79[0x96 - 0x79]; } O06R;
typedef struct { u8 pad[0x4B0]; s32 unk4B0; u8 pad2[0x1C]; } O06P;
typedef struct { O06P base; s32 unk4D0; s32 unk4D4; } O06Q;
typedef struct { s32 unk0; s32 unk4; s32 unk8; s32 unkC; } O06T;
extern O06R D_80146398[];
extern O06P *D_800E59E0;
extern O06T D_800E5BC4[];
extern O06T D_800E5B14[];
extern O06T D_800E5B44[];
void func_0043BA34(void) {
    s32 i, j;
    O06R *row;
    O06P *slot;
    for (i = 0; i < 4; i++) {
        row = &D_80146398[i];
        if (row->unk78 == 1 && (slot = &D_800E59E0[i], ((O06Q *)slot)->unk4D4 == 2)) {
            for (j = 0; j < 0x16; j++) { row->unk4C[j] = 0; row->unk62[j] = 0; }
            for (j = 0; j < 6; j++) {
                u32 tab; O06T *t;
                s32 val;
                switch (j) {
                case 0: case 1: tab = (u32)D_800E5BC4; val = j + 1; break;
                case 4: tab = (u32)D_800E5B14; val = 4; break;
                case 2: case 3: tab = (u32)D_800E5B44; val = j + 3; break;
                default: continue;
                }
                t = (O06T *)((*(s32 *)((u8 *)D_800E59E0 + (i * 0x4D0 + j * 4) + 0x4B8) << 4) + tab);
                row->unk4C[t->unk8] = 1;
                row->unk62[t->unk8] = val;
            }
            row->unk4C[0] = 1;
            row->unk62[0] = 0;
        }
    }
}
