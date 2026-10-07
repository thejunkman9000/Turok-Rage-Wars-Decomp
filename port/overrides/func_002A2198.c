#include "b23_types.h"

extern s32 D_800D2BB0[];

void *func_002A1724(void *dst, void *src, u32 n);

void port_dbg_words(const char *what, void *p, int n, int h);
s32 func_002A2198(s32 a0, void *dst, s32 n) {
    { static int cnt; if (cnt++ < 30) { s32 info[4]; info[0] = D_800D2BB0[0]; info[1] = D_800D2BB0[1]; info[2] = (s32)dst; info[3] = n; port_dbg_words("memfile read base/pos/dst/n", info, 4, a0); } }
    func_002A1724(dst, (void *)(D_800D2BB0[0] + D_800D2BB0[1]), n);
    { static int c2; if (c2++ < 2) port_dbg_words("memfile dst after read", dst, 21, n); }
    D_800D2BB0[1] += n;
    return 1;
}
