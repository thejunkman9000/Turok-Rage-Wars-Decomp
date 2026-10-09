#include "m01_types.h"

typedef struct V16 { f32 x, y, z, w; } V16;
extern f32 D_800C6B14;
extern M1Actor **D_80103FCC;
extern u8 D_80103FD0[];
extern M1Actor *D_80145060;
extern s32 D_801468C4;
f32 func_0027272C(Vec3f *a, Vec3f *b);
void func_00271FD8(V16 *dst, Vec3f *a, Vec3f *b);
f32 func_0024D274(M1Actor *a);
s32 func_00244494(M1Actor *a, Vec3f pos, Vec3f target, u8 *out);

void func_00203278(M1Actor *actor, M1State *state, M1Out *out) {
    V16 P;
    V16 Q;
    f32 best;
    f32 d;
    f32 r;
    f32 k;
    M1Actor *found;
    M1Actor *p;
    M1Info *info;
    s32 ok;
    s32 vis;
    M1Actor *o;

    best = 0.0f;
    found = NULL;
    p = D_80145060;
    info = &actor->def->info;
    if (p != NULL) {
        k = D_800C6B14;
        do {
            d = func_0027272C(&actor->pos, &p->pos);
            r = info->f54;
            if (d < r * r) {
                o = actor->owner;
                ok = 0;
                if (o != p && p->unk5E4 != 0) {
                    ok = 1;
                    if (D_801468C4 != 0) {
                        ok = o->stats->b92 != p->stats->b92;
                    }
                }
                if (ok != 0) {
                    func_00271FD8(&Q, &p->pos, &actor->pos);
                    P.x = state->vec130.x;
                    P.y = state->vec130.y;
                    P.z = state->vec130.z;
                    *(Vec3f *)&P = actor->pos;
                    P.y = P.y + func_0024D274(actor) * k;
                    *(Vec3f *)&Q = p->pos;
                    Q.y = Q.y + func_0024D274(p) * k;
                    ok = func_00244494(actor, *(Vec3f *)&P, *(Vec3f *)&Q, D_80103FD0);
                    vis = 1;
                    if (ok != 0) {
                        vis = *D_80103FCC == p;
                    }
                    if (vis != 0 && (found == NULL || d < best)) {
                        found = p;
                        best = d;
                    }
                }
            }
            p = p->next;
        } while (p != NULL);
    }
    if (found != NULL) {
        state->unk80 = found;
        out->f40 = sqrtf(best);
        out->tgt = found;
        return;
    }
    out->tgt = NULL;
    state->unk80 = NULL;
}
