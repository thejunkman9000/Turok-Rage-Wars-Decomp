#include "b03_types.h"

extern GameB D_80145040[];
ActorB *func_0022A5E4(GameB *g, s32 idx);
f32 func_00272768(Vec3f *a, Vec3f *b);
s32 func_0021035C(BrainB *b, s32 idx);

s32 func_00210228(BrainB *b) {
    s32 i;
    s32 n;
    ActorB *a;
    GameB *g;
    GameFlagsB *gf;

    for (i = 0; i < 10; i++) {
        b->actors[i] = NULL;
        b->valid[i] = 0;
        b->value[i] = -1;
    }
    n = 0;
    for (i = 0, g = D_80145040, gf = &g->gf; i < 8; i++) {
        a = func_0022A5E4(g, i);
        if (a != NULL && a != b->actor
            && (gf->unk24 == 0 || a->stats->unk92 != b->actor->stats->unk92)
            && (a->unk5E4 >> 8) > 0) {
            b->actors[n] = a;
            b->value[n] = (s32)func_00272768(&b->actor->pos, &a->pos);
            b->valid[n] = func_0021035C(b, n);
            n++;
        }
    }
    b->count = n;
    return 1;
}
