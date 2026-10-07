#include "o03_types.h"
extern O3Pj *D_800E42D0;
extern O3IdRow D_800E42D4[];
typedef struct { u8 pad[0x14]; s16 f14; s16 f16; } O3Sp;
void func_0040E958(void *it, s32 on);
O3Sp *func_0040ECB0(s32 p, u16 id);
void func_0041B768(s32 p, s32 i, s16 id);
void func_004204A8(s32 idx);
#define PJ(off) (*(O3Pj *)((s32)D_800E42D0 + (off)))
void func_00420378(s32 idx) {
    O3Sp *a;
    s32 off;
    func_0041B768(D_800E42D0->f0, idx, D_800E42D4[idx].e[0].id);
    a = func_0040ECB0(D_800E42D0->f0, D_800E42D4[idx].e[1].id);
    off = idx * 0x4C8;
    PJ(off).f8 = (s32)a;
    a = func_0040ECB0(D_800E42D0->f0, D_800E42D4[idx].e[0].id);
    ((O3Sp *)PJ(off).f8)->f14 = a->f14 - 2;
    ((O3Sp *)PJ(off).f8)->f16 = a->f16 - 2;
    func_0040E958((void *)PJ(off).f8, 1);
    ((O3Pj *)((s32)D_800E42D0 + off))->state = 1;
    func_004204A8(idx);
    func_0040E958(func_0040ECB0(D_800E42D0->f0, D_800E42D4[idx].e[2].id), 0);
}
