#include "b22_types.h"
extern SndMgr *D_8014D080;
extern s32 D_8014D09C;
extern s32 D_8014D0A0;
s32 func_0029A958(void);
s32 func_00411E4C(s32);
SndCtx *func_0040ECB0(s32, s32);
SndCtx *func_00299170(s32 id)
{
    s32 i;
    s32 x;
    s32 t;
    SndCtx *ctx;
    SndCacheEnt *e;
    x = func_00411E4C(func_0029A958());
    for (i = 0; i < D_8014D080->unk540; i++) {
        if (D_8014D080->unk53C[i].unk8 == x && D_8014D080->unk53C[i].id == id && D_8014D080->unk53C[i].ctx != 0 && D_8014D080->unk53C[i].ctx->id == id) {
            return D_8014D080->unk53C[i].ctx;
        }
    }
    ctx = func_0040ECB0(x, id & 0xFFFF);
    t = D_8014D0A0 + 1;
    D_8014D0A0 = t;
    if (D_8014D09C < t) {
        D_8014D09C = t;
    }
    if (D_8014D080->unk540 < 0x4B) {
        D_8014D080->unk53C[D_8014D080->unk540].id = id;
        D_8014D080->unk53C[D_8014D080->unk540].ctx = ctx;
        D_8014D080->unk53C[D_8014D080->unk540].unk8 = x;
        D_8014D080->unk540++;
    }
    return ctx;
}


