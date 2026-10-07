#include "o03_types.h"
typedef struct O3LC {
    /* 0x00 */ O3Hdr h;
    /* 0x14 */ u8 pad14[0x18];
    /* 0x2C */ O3Blk5 col;
    /* 0x40 */ u8 pad40[4];
    /* 0x44 */ O3ListG *g;
    /* 0x48 */ u8 pad48[0x110 - 0x48];
    /* 0x110 */ s32 sel;
    /* 0x114 */ s32 cnt;
} O3LC;
void *func_00252FFC(s32 size);
void func_002A1748(void *p, s32 v, s32 n);
s32 func_0029A958();
s32 func_00411E4C(s32);
O3LC *func_0040ECB0(s32, s32);
void func_0040EF24(O3LC *, O3LC *);
void func_0040F004(s32, O3LC *, O3LC *);
O3LC *func_0041AC40(s32 a, s32 b) {
    O3LC *src;
    s32 s;
    O3LC *o;
    src = func_0040ECB0(func_00411E4C(func_0029A958()), a & 0xFFFF);
    s = func_00411E4C(func_0029A958());
    o = func_00252FFC(0x118);
    func_002A1748(o, 0, 0x118);
    *(O3Blk11 *)o = *(O3Blk11 *)src;
    o->h.id2 = 0xB64;
    o->col = src->col;
    o->g = (O3ListG *)func_0040ECB0(s, b & 0xFFFF);
    o->sel = 0;
    o->cnt = 0;
    func_0040EF24(src, o);
    src->h.id = -1;
    func_0040F004(s, src, o);
    return o;
}
