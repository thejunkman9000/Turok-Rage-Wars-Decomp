#include "b20_types.h"
void func_0028CC80(Level *lv, Actor *owner) {
    s32 i = 0;
    s32 n = lv->numActors;
    Actor **p = lv->actors;
    if (n > 0)
    do {
        Actor *a = *p;
        if (a->owner == owner) {
            a->owner = 0;
        }
        i++;
        p++;
    } while (i < n);
}
