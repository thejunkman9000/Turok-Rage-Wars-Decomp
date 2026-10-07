#include "b03_types.h"

extern EntList D_8013B364[];
extern PathTbl D_8011FE88[];
EntRec *func_0020C994(EntList *list, s32 key);
s32 func_0020993C(BrainB *b);
f32 func_00272768(s32 a, EntRec *r);
PathEnt *func_0028D1F4(PathTbl *t, s32 idx);
s32 func_0028D220(PathTbl *t, s32 a, s32 b);
s32 func_0020CB3C(EntList *list, s32 v);
s32 func_00274544(void);
extern f32 D_800C71C0;
void func_00208410(BrainB *b);
void func_00211020(BrainB *b);
void func_00208AAC(BrainB *b);

void func_00212E04(Actor *actor) {
    BrainB *b = (BrainB *)actor->owner->brain;
    EntList *L = D_8013B364;
    s32 s;

    if (b->unk224 == -1) {
        if (*D_8011FE88->cnt > 0) {
            b->unk224 = 0;
            b->unk228 = 0;
            func_0028D1F4(D_8011FE88, b->unk224);
        } else {
            b->unk224 = -2;
            b->unk228 = -1;
        }
        b->unkC = -1;
    }
    if (b->unk4 == b->unkC) {
        s = func_0020993C(b);
        if (func_00272768(s, func_0020C994(L, b->unkC)) < D_800C71C0) {
            if (b->unk224 >= 0) {
                PathEnt *e = func_0028D1F4(D_8011FE88, b->unk224);
                b->unk228++;
                if (b->unk228 == e->len) {
                    b->unk228 = 0;
                }
            }
            b->unkC = -1;
        }
    }
    if (b->unkC == -1) {
        if (b->unk224 == -2) {
            b->unkC = func_00274544() % L->count;
        } else {
            b->unkC = func_0020CB3C(L, func_0028D220(D_8011FE88, b->unk224, b->unk228));
        }
    }
    func_00208410(b);
    func_00211020(b);
    func_00208AAC(b);
}
