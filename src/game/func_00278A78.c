#include "b17_types.h"

#define MN(a,b) ((a) < (b) ? (a) : (b))
#define MX(a,b) ((a) > (b) ? (a) : (b))
#define CL(x) MX(MN((x), 0xE1), 0x1E)

void func_00278A78(VtxBlk *b, u8 *out) {
    s32 i, n;
    B17Vtx *vp, *p;
    u8 *d;

    i = 0;
    n = b->count;
    vp = b->v;
    for (; i < n; i++) {
        p = vp + i;
        d = out;
        out += 4;
        d[0] = CL(p->col[0]);
        d[1] = CL(p->col[1]);
        d[2] = CL(p->col[2]);
    }
}
