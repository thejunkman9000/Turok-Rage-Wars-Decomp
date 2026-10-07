#include "o02_types.h"
extern s32 D_80153C78;
extern u8 *D_80153C7C;
extern s32 D_80153C80;
extern s32 D_80153C60;
void func_004141E8(void) {
    s32 i = D_80153C78;
    s32 v;
    if (i & 1) {
        v = D_80153C7C[i >> 1] & 0xF;
    } else {
        v = D_80153C7C[i >> 1] >> 4;
    }
    D_80153C80 = v;
    D_80153C60 = v;
}
