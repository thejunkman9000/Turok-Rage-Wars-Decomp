#include "common.h"

typedef struct B21Xy {
    s32 x;
    s32 y;
} B21Xy;

extern s32 D_800D2B04;
extern u8 D_800CA680[];
void func_00295B90();
void func_002518DC(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, void *cb, void *g, s32 h);

/* US v1.0 counterpart of func_00296EC4: no D_800D2AE0 test (1.1 added the else branch) */
void func_auto_00295E54(B21Xy *p, s32 idx) {
    func_002518DC(0, p->x + idx + (D_800D2B04 << 7), p->x, p->y, 0, idx, func_00295B90, D_800CA680, 0);
}
