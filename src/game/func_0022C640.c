#include "p2_types.h"

s32 func_0022C640(Game *g) {
    Player *p;
    s32 n = 0;

    for (p = g->players; p != NULL; p = p->next) {
        if (p->f5D0 != 0) {
            n++;
        }
    }
    return n;
}