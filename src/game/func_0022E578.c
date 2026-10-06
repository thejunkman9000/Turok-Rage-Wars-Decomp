#include "p2_types.h"

f32 func_00272768(P2Vec3 *a, P2Vec3 *b);

f32 func_0022E578(Game *g, P2Vec3 *v) {
    Player *p;
    f32 sum = 0.0f;

    for (p = g->players; p != NULL; p = p->next) {
        if (p->pawn != NULL) {
            sum += func_00272768(v, &p->pos);
        }
    }
    return sum;
}