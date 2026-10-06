#include "p2_types.h"

extern Player *D_80145060;

Player *func_002392DC(Pawn *pw) {
    Player *p;

    for (p = D_80145060; p != NULL; p = p->next) {
        if (p->pawn == pw) {
            return p;
        }
    }
    return NULL;
}