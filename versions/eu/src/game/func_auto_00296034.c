#include "common.h"

typedef struct B21Xy {
    s32 x;
    s32 y;
} B21Xy;

extern s32 D_auto_800CE474;
extern u8 D_auto_800C5790[];
void func_auto_00294DB0();
void func_002518DC(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, void *cb, void *g, s32 h);

void func_auto_00296034(B21Xy *p, s32 idx) {
    func_002518DC(0, p->x + idx + (D_auto_800CE474 << 7), p->x, p->y, 0, idx, func_auto_00294DB0, D_auto_800C5790, 0);
}
