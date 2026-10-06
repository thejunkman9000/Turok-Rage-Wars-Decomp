#include "p2_types.h"

s32 func_0022BA90(Player *p) {
    Pawn *w = p->pawn;
    if (w) {
        return w->f564 != 0;
    }
    return 0;
}