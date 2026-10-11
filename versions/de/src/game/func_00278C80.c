#include "b17_types.h"

extern FnEnt *D_800D28B8[];
extern GBlk D_80145088;
extern SessMgr D_8011FE88;
extern PtrVal D_800D7F84[];
extern s32 D_800D2980;
extern f32 D_800C9C20;
extern Ent2E8 *D_8011FFC0;
extern s32 D_8013B294;
void func_002398F8(GBlk *g, void *p, s32 a, s32 b, f32 c);
void func_0025E13C(s32 id);
void func_4030E0(s32 id);

void func_00278C80(Rec14 *r) {
    FnEnt *tab;
    FnEnt *ent;
    void *a1;
    s32 v;
    Ent2E8 *e;

    tab = D_800D28B8[r->b11];
    if (tab != 0) {
        if (D_80145088.f125D != 0 || (a1 = D_80145088.u20) == 0) {
            a1 = &D_80145088.u40;
        }
        if (D_8011FE88.mode == 4) {
            if (r->b10 != 0) {
                func_002398F8(&D_80145088, a1, *D_800D7F84[r->b10].p, D_800D2980, D_800C9C20);
                v = D_800D7F84[r->b10].v;
                if (v != 0) {
                    func_0025E13C(v);
                }
            }
            if (r->w8 >= 2) {
                func_4030E0(r->w8);
            }
        }
        tab += r->b12;
        ent = tab;
        if (r->wA == D_8013B294) {
            e = &D_8011FFC0[r->w4];
            if (ent->fn0 != 0) {
                ent->fn0(e, &e->f170, r);
            }
        } else {
            if (ent->fn1 != 0) {
                ent->fn1(r);
            }
        }
    }
}
