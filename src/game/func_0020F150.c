#include "b03_types.h"

extern EntList D_8013B364[];
EntRec *func_0020C994(EntList *list, s32 key);
void func_0020D220(EntList *list, s32 key);

s32 func_0020F150(s32 *ids) {
    EntList *L = D_8013B364;
    EntNode *n;
    EntRec *r;
    s32 count;
    s32 i;

    count = 0;
    for (n = L->head; n != NULL; n = n->next) {
        r = func_0020C994(L, n->key);
        if (r->flags & 1) {
            for (i = 0; i < 30; i++) {
                if (r->id == ids[i]) {
                    if (n->owner != NULL && n->owner->unk294 != 0) {
                        func_0020D220(L, n->key);
                        count++;
                    }
                }
            }
        }
    }
    if (count == 0) {
        for (n = L->head; n != NULL; n = n->next) {
            r = func_0020C994(L, n->key);
            if (r->flags & 1) {
                for (i = 0; i < 30; i++) {
                    if (r->id == ids[i]) {
                        func_0020D220(L, n->key);
                        count++;
                    }
                }
            }
        }
    }
    return count;
}
