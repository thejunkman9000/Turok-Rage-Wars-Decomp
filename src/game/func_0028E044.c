#include "b20_types.h"

void func_0028E044(Level *lv) {
    s32 n = 0;
    s32 i;
    Entity *e = lv->entities;
    lv->n2 = 0;
    for (i = 15; i >= 0; i--) {
        lv->list2[i] = 0;
    }
    for (i = 0; i < lv->numEntities; i++) {
        if (e->def->type == 0xE) {
            lv->list2[n] = e;
            n++;
        }
        if (n >= 16) {
            break;
        }
        e++;
    }
    lv->n2 = n;
}
