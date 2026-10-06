#include "b22_types.h"
extern SndMgr *D_8014D080;
extern s32 D_8014D084;
extern s32 D_8014D088;
extern s32 D_8014D08C;
extern s32 D_8014D094;
extern s32 D_8014D098;
extern u8 D_0040C640[];
extern u8 D_0040C648[];
extern u8 D_00412624[];
extern u8 D_004126B4[];
extern f64 D_800CA7F8;
void func_002A2918(s32 *, s32 *);
void func_00411F6C(void);
void func_0040F5B4(s32, s32);
void func_0029BA78(void);
void *func_00252FFC(s32);
void func_002A1748(void *, s32, s32);
f64 func_002A28CC(void);
void func_002992C4(s32, void *, void *, s32);
void func_00298FA0(s32 n, s32 (*fn)())
{
    s32 i;
    SndMgr *m;
    SndSlot *s;
    D_8014D098 = -1;
    func_002A2918(&D_8014D088, &D_8014D08C);
    func_00411F6C();
    func_0040F5B4(D_8014D088, D_8014D08C);
    func_0029BA78();
    D_8014D084 = 0;
    D_8014D080 = func_00252FFC(0x544);
    func_002A1748(D_8014D080, 0, 0x544);
    m = D_8014D080;
    m->fn10 = fn;
    m->unk14 = 0xFA0;
    s = m->slot;
    for (i = 0; i < 64; i++) {
        s->unk8 = 0;
        s->id = -1;
        s->unk4 = 0;
        s->unkC = 0;
        s++;
    }
    func_002A1748(D_8014D080->unk53C = func_00252FFC(0x384), 0, 0x384);
    D_8014D080->unk540 = 0;
    D_8014D080->unk524 = func_002A28CC() * D_800CA7F8;
    D_8014D080->unk18 = n;
    func_002A1748(D_8014D080->stk = func_00252FFC(n * 28), 0, n * 28);
    D_8014D094 = 0;
    D_8014D080->top = -1;
    D_8014D080->unk528 = -1;
    D_8014D080->unk534 = 0;
    D_8014D080->unk538 = 0;
    D_8014D080->unk52C = 1;
    func_002992C4(9, D_0040C640, D_0040C648, 1);
    func_002992C4(0xB, D_00412624, D_004126B4, 1);
}

