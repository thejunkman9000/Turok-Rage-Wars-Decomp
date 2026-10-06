#include "p2_types.h"

s32 func_0022C610(Game *g) {
    Player *p;
    s32 n = 0;

    for (p = g->players; p != NULL; p = p->next) {
        if (p->def->f90 == 0) {
            n++;
        }
    }
    return n;
}