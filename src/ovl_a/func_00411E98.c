#include "o02_types.h"
typedef struct { s32 a, b; void *p; } S12;
extern S12 *D_80153C44;
extern S12 *D_80153C48;
extern s16 *D_80153C50;
extern s32 D_800E2AC4;
void func_00254784(void *p);
void func_00411E98(s32 i) {
    *(u16 *)&D_80153C50[i] -= 1;
    if (D_80153C44[i].p && D_80153C50[i] == 0) {
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
