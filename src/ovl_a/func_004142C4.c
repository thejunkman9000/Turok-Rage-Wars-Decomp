#include "o02_types.h"
extern s32 D_80153C84;
extern u8 *D_80153C88;
extern u8 D_80153C8F;
void func_004142C4(void) {
    s32 i = D_80153C84;
    if (i & 1) {
        D_80153C88[i >> 1] = (D_80153C88[i >> 1] & 0xF0) | (D_80153C8F & 0xF);
    } else {
        D_80153C88[i >> 1] = (D_80153C88[i >> 1] & 0xF) | ((D_80153C8F & 0xF) << 4);
    }
}
