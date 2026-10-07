#include "o03_types.h"
void *func_00252FFC(s32 size);
void func_002A1748(void *p, s32 v, s32 n);
s32 func_0029A958();
s32 func_00411E4C(s32);
void func_0040EF24(O3B61 *, O3B61 *);
void func_0040F004(s32, O3B61 *, O3B61 *);
void func_0041B2AC(O3B61 *src) {
    s32 s;
    O3B61 *o;
    if (src->h.id2 != 0xB61) {
        s = func_00411E4C(func_0029A958());
        o = func_00252FFC(0x44);
        func_002A1748(o, 0, 0x44);
        *(O3Blk11 *)o = *(O3Blk11 *)src;
        o->h.id2 = 0xB61;
        o->col = src->col;
        func_0040EF24(src, o);
        src->h.id = -1;
        func_0040F004(s, src, o);
    }
}
