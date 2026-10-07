#include "o06_types.h"
extern f32 D_800E2528;
extern f32 D_800E26A8;
extern f32 D_800E26AC;
extern f32 D_800E26B0;
extern f32 D_800E26B4;
extern f32 D_800E26B8;
f32 func_0044239C(u8 c, u8 n, f32 x, f32 y) {
    f32 k = D_800E2528;
    switch (c) {
    case '$': case '&': case '~':
        return y;
    case 'I': case 'i':
        k = D_800E26A8;
        break;
    case 'L': case 'l':
        if (n == 't' || n == 'T') k = D_800E26AC;
        break;
    case 'A': case 'a':
        if (n == 't' || n == 'T') k = D_800E26B0;
        break;
    case 'M': case 'm':
        k = D_800E26B4;
        break;
    case '!': case '.':
        k = D_800E26B8;
        break;
    }
    return k * x;
}
