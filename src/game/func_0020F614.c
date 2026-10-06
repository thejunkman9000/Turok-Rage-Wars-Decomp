#include "b03_types.h"
extern EntList D_8013B364[];
EntRec *func_0020C994(EntList *list, s32 key);
void func_0020D220(EntList *list, s32 key);
s32 func_0020F614(void) {
    EntList *L = D_8013B364;
    EntNode *n;
    s32 count;
    EntRec *r;
    count = 0;
    for (n = L->head; n != NULL; n = n->next) {
        r = func_0020C994(L, n->key);
        if ((r->flags & 1) && r->id == 0x64E && n->owner->unk1A4 == 0) {
            func_0020D220(L, n->key);
            count++;
        }
    }
    return count;
}
