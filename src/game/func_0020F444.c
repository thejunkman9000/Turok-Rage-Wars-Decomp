#include "b03_types.h"

extern EntList D_8013B364[];
extern EntNode *D_8013B388;
EntRec *func_0020C994(EntList *list, s32 key);
void func_0020D014(EntList *list);
void func_0020D0CC(EntList *list, s32 key);
void func_0020D114(EntList *list, void *dst, s32 n);
void func_0020D1FC(EntList *list);
void func_0020D220(EntList *list, s32 key);

s32 func_0020F444(QueryObj *o) {
    EntList *L = D_8013B364;
    EntList *L2 = D_8013B364;
    EntNode *n;
    EntRec *r;
    s32 count;

    func_0020D014(L);
    func_0020D1FC(L);
    count = 0;
    for (n = D_8013B388; n != NULL; n = n->next) {
        r = func_0020C994(L2, n->key);
        if ((r->flags & 1) && r->id == 0x64E && n->owner->unk1A4 == 0) {
            func_0020D220(L2, n->key);
            count++;
        }
    }
    if (count == 0) {
        o->unk68 = 0;
        o->unkBC = -1;
        return 1;
    }
    L->sel = -1;
    func_0020D0CC(L, o->key);
    if (L->sel != -1) {
        o->unkC = L->sel;
        func_0020D114(L, &o->unk14, 4);
    }
    return 1;
}
