#include "o02_types.h"
typedef struct { s32 a, b; void *p; } S12;
extern S12 *D_80153C44;
extern S12 *D_80153C48;
extern u16 *D_80153C4C;
extern s16 *D_80153C50;
extern s16 D_80153C40;
extern s32 D_800E2AC4;
void func_00254784(void *p);
void func_00411964(s32 force) {
    s32 i;
    for (i = 0; i < D_80153C40; i++) {
        if (D_80153C44[i].p == 0) continue;
        if ((D_80153C4C[i] & 1) && force == 0) continue;
        *(u16 *)&D_80153C50[i] = 1;
        *(u16 *)&D_80153C50[i] -= 1;
        if (D_80153C44[i].p == 0) continue;
        if (D_80153C50[i] != 0) continue;
        func_00254784(D_80153C44[i].p);
        if (D_800E2AC4) {
            if (D_80153C48) {
                if (D_80153C48[i].p) {
                    func_00254784(D_80153C48[i].p);
                }
            }
        }
        D_80153C44[i].p = 0;
    }
}
