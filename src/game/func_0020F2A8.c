#include "b03_types.h"

extern EntList D_8013B364[];
void func_0020D014(EntList *list);
void func_0020D1FC(EntList *list);
void func_0020D0CC(EntList *list, s32 key);
EntNode *func_0020CFE0(EntList *list, s32 key);
void func_0020D114(EntList *list, void *dst, s32 n);
s32 func_0020F150(s32 *ids);

s32 func_0020F2A8(QueryObj *o) {
    EntList *L = D_8013B364;
    IdQuery q;
    s32 i;
    s32 sel;
    EntNode *n;

    func_0020D014(L);
    func_0020D1FC(L);
    for (i = 0; i < 30; i++) {
        q.ids[i] = 0;
    }
    q.ids[0] = 0xBD7;
    if (func_0020F150(q.ids) == 0) {
        o->unk68 = 0;
        o->unkBC = -1;
        return 1;
    }
    L->sel = -1;
    func_0020D0CC(L, o->key);
    sel = L->sel;
    if (sel != -1) {
        n = func_0020CFE0(L, sel);
        o->unkC = L->sel;
        o->unk68 = n->owner;
        func_0020D114(L, &o->unk14, 4);
    } else {
        o->unk68 = 0;
        o->unkBC = sel;
    }
    return 1;
}
