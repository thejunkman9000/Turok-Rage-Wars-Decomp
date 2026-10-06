#include "b02_types.h"

s32 func_00209874(B2Ctl *ctl, s32 id) {
    B2AnimTbl *tbl = ctl->tbl;
    B2AnimEnt *found = NULL;
    B2AnimEnt *e;

    ctl->curId = id;
    while (tbl != NULL) {
        for (e = tbl->ent; e->id != -1; e++) {
            if (e->id == id) {
                found = e;
                tbl = NULL;
                break;
            }
        }
        if (tbl != NULL) {
            tbl = tbl->next;
        }
    }
    if (found == NULL) {
        return 0;
    }
    ctl->cur = found;
    if (found->cb != NULL) {
        found->cb(ctl->owner, 0);
    }
    return 1;
}
