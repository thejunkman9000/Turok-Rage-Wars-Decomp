#include "o02_types.h"
extern s32 D_800E2AB0;
extern s32 D_800E2AB4;
typedef struct { s32 a, b, c, d; } O02Q;
extern O02Q D_80153810;
void func_0040F5B4(s32 a, s32 b) {
    a--;
    b--;
    D_800E2AB0 = a;
    D_800E2AB4 = b;
    D_80153810.a = D_80153810.c = 0;
    D_80153810.b = a;
    D_80153810.d = b;
}
