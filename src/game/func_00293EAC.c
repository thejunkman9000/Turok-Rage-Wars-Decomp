#include "b21_types.h"
#include "b21_world.h"

extern u8 D_8011FE88[];
void func_0025E2F4(s32 a);
void func_00293318(B21Game *g, s32 a, s32 b);
void func_00286A78(void *a, s32 b, s32 c);
void func_44AFC0(void *a, s32 b);
void func_00297008(s32 a);

void func_00293EAC(B21Game *g) {
    B21GameBlk *b = &D_80145040.blk;
    B21Sub1288 *s = &D_80145040.sub1288;
    B21Sub48 *q = &D_80145040.sub48;
    func_0025E2F4(0);
    b->unkAC = 0;
    b->unk88 = 0;
    s->unkB2 = 1;
    s->unk1D = 0;
    s->unk1E = 1;
    func_00293318(g, 0, 0);
    func_00286A78(D_8011FE88, 0, 0);
    func_44AFC0(q, 1);
    q->unk160 = 0;
    func_00297008(0);
}
