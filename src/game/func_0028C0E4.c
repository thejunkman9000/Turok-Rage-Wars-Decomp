#include "b20_types.h"

Entity *func_0028C0E4(Level *lv, s32 id) {
    Entity *found = 0;
    s32 i;
    for (i = 0; i < lv->n1; i++) {
        Entity *a = lv->list1[i];
        if (((DefC *)a->def)->unkC == id) {
            found = a;
            break;
        }
    }
    return found;
}
