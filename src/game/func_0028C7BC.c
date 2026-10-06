#include "b20_types.h"

Entity *func_0028C7BC(Level *lv, s32 id) {
    Entity *found = 0;
    s32 i;
    for (i = 0; i < lv->n2; i++) {
        Entity *a = lv->list2[i];
        if (((DefC *)a->def)->unkC == id) {
            found = a;
            break;
        }
    }
    return found;
}
