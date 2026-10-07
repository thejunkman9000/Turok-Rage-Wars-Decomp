#include "m01_types.h"

f32 func_00265734(f32 x);
void func_00272038(Vec3f *dst, f32 t, Vec3f *src, Vec3f *v);
f32 func_00275E44(s32 id, f32 x, f32 z);
void func_0027625C(s32 id, f32 y);

void func_00206DD4(M1Actor *actor, M1State *state) {
    M1Info *info;
    f32 t;
    f32 lo;
    f32 x;
    f32 fs0;
    f32 c;
    Vec3f v;

    t = state->f64;
    lo = 0.0f;
    info = &actor->def->info;
    if (t < lo || (lo = 1.0f, lo < t)) {
        t = lo;
    }
    if (info->unk28.b[1] == 0) {
        t = func_00265734(t);
    }
    v = state->vA0;
    v.y += info->f2C;
    if (info->unk4.hu[0] != 0) {
        v.x += info->f30 * sinf(info->f34);
        v.z += info->f30 * cosf(info->f34);
    }
    func_00272038(&state->v54, t, &state->vA0, &v);
    switch (info->unk28.b[0]) {
    case 0:
        x = sinf(state->f13C);
        goto join;
    case 1:
        fs0 = state->f13C;
        c = 0.25f;
        state->v54.y += info->f44 * (sinf(fs0) * c);
        state->v54.y += info->f44 * (sinf(fs0 * 1.1f) * c);
        state->v54.y += info->f44 * (sinf(fs0 * 1.2f) * c);
        x = sinf(fs0 * 1.3f) * c;
join:
        state->v54.y += info->f44 * x;
        break;
    }
    state->v54.x += state->unk128.f;
    state->v54.y += state->unk12C.f;
    state->v54.z += state->vec130.x;
    switch (info->unk28.b[2]) {
    case 0:
        actor->f6C = state->f9C + t * ((state->f9C + info->f3C) - state->f9C);
        break;
    case 1:
        if (!(state->flags3C & 0x400)) {
    case 2:
            if (info || (&actor->pos)) {
                actor->f6C = actor->f6C + info->f3C * 0.06666667f;
            } else {
                actor->f6C = actor->f6C + info->f3C * 0.06666667f;
            }
        }
        break;
    }
    if (info->unk4.hu[0] == 0) {
        func_0027625C(actor->unk14, (func_00275E44(actor->unk14, actor->pos.x, actor->pos.z) + state->v54.y) - actor->pos.y);
    }
}
