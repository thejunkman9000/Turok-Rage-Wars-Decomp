#include "b03_types.h"

extern PathTbl D_8011FE88[];
void func_00217388(ActorB *a, StateB *s);

s32 func_00214178(ActorB *a, StateB *s, s32 id) {
    StateTable *t;
    StateEntry *e;
    StateEntry *found;

    if (D_8011FE88->mode == 2) {
        return 1;
    }
    if (D_8011FE88->mode == 4) {
        a->flags |= 0x100;
    }
    s->prevId = s->id;
    a->unk10F = 1;
    a->unk123 = 1;
    if (s->cur != NULL && s->id == id) {
        return 1;
    }
    t = s->table;
    found = NULL;
    s->id = id;
    s->unk40 = 0;
    while (t != NULL) {
        for (e = t->ent; e->id != -1; e++) {
            if (e->id == id) {
                found = e;
                t = NULL;
                break;
            }
        }
        if (t != NULL) {
            t = t->next;
        }
    }
    if (found == NULL) {
        return 0;
    }
    s->cur = found;
    a->unk2E0 &= 0x1F80007F;
    if (!(a->flags & 0x8000000)) {
        s->unkCB = 0;
        s->flags &= ~1;
    }
    if (s->unkFC != 0) {
        func_00217388(a, s);
    }
    if (found->fn != NULL) {
        found->fn(a, s);
    }
    s->unk3C = found->flags;
    if (s->unk3C & 4) {
        a->vel.x = 0;
        a->vel.y = 0;
        a->vel.z = 0;
    }
    return s->id == id;
}
