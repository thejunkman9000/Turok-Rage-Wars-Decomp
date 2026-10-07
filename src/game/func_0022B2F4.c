#include "b06_types.h"

void func_00271FD8(f32 *out, f32 *a, Vec3f *b);

Plr *func_0022B2F4(PlrGroup *g, f32 *v) {
    Plr *a;
    Plr *best = NULL;
    f32 min = 0.0f;
    f32 t[3];
    f32 d;
    for (a = g->head; a != NULL; a = a->next) {
        if (a->unk5D0 != 0 && a->unk11FC != 0.0f) {
            func_00271FD8(t, v, &a->unk1200);
            d = t[0] * t[0] + t[1] * t[1] + t[2] * t[2];
            if (best == NULL || d < min) {
                best = a;
                min = d;
            }
        }
    }
    return best;
}
