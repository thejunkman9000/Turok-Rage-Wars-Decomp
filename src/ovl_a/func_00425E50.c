#include "o04_types.h"
typedef struct { u8 b[0x2A]; } O04B42;
typedef struct { u8 pad0[0x16]; O04B42 tbl[8][20]; } O04Grid;
extern u8 D_8011FE88[];
extern O04B42 D_80153FE0;
O04Grid *func_0028D450(void *a, s32 b);
void *memcpy(void *d, const void *s, u32 n);
O04B42 *func_00425E50(s32 a, s32 b, s32 c) {
    O04Grid *g = func_0028D450(D_8011FE88, a);
    if (g == 0) {
        return 0;
    }
    memcpy(&D_80153FE0, &g->tbl[b][c], 0x2A);
    return &D_80153FE0;
}
