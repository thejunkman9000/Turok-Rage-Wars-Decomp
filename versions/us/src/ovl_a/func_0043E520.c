#include "s1009_types.h"
extern u8 D_800D7688[];
extern u8 D_800D768C[];
s32 func_0043E520(S10Item *a, S10Menu *m) {
    switch (m->ctx->sub->b7B) {
    case 0:
        a->f14 = D_800D7688;
        break;
    case 1:
        a->f14 = D_800D768C;
        break;
    }
    return 0;
}
