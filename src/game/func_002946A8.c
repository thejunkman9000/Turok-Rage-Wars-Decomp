#include "b21_types.h"
#include "b21_world.h"

extern s32 D_800D2980;
extern s32 D_800D2970;
extern f32 D_800D2994;
extern f32 D_800D298C;
extern f32 D_800D2990;
extern f32 D_800CA5C4;
extern u8 D_8011FE88[];
void func_0029324C();
s32 func_00264B8C();
s32 func_00264B7C();
void func_00264BAC();
void func_00293318(B21Game *g, s32 a, s32 b);
void func_0023EDF0();
void func_002954E0();
void func_44DC48(void *a, s32 b);
void func_44E178(void *a, s32 b, s32 c);

void func_002946A8(B21Game *g) {
    B21GameBlk *b;
    B21Sub1288 *s;
    f32 v;
    D_800D2980 = 0;
    func_0029324C();
    if (func_00264B8C()) {
        g->unk26DD8 = func_00264B7C();
    }
    b = &D_80145040.blk;
    b->unk20 = 0;
    b->unk64 = 3;
    s = &D_80145040.sub1288;
    s->unk1D = 1;
    s->unk1E = 8;
    func_00293318(g, g->unk26826, 0);
    if (func_00264B8C()) {
        func_00264BAC();
    }
    func_0023EDF0();
    func_002954E0();
    v = D_800CA5C4;
    D_800D2970 = 0;
    D_800D2994 = v;
    D_800D298C = v;
    D_800D2990 = v;
    func_44DC48(D_8011FE88, g->unk3C4);
    func_44E178(D_8011FE88, g->unk26DD8, 0);
}
