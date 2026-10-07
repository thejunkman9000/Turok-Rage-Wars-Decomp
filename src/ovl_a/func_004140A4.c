#include "o02_types.h"
extern s32 D_80153C60;
extern u8 *D_80153C64;
extern s32 D_80153C68;
void func_004140A4(void) {
    D_80153C68 = (D_80153C64[D_80153C60 * 3] << 16) | (D_80153C64[D_80153C60 * 3 + 1] << 8) | D_80153C64[D_80153C60 * 3 + 2];
}
