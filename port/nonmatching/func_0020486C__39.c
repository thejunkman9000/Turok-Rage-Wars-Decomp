#include "m01_types.h"

extern f32 D_800C6B70;
extern s32 D_8011FE88[];
typedef struct M1Pair { s32 a; s32 b; } M1Pair;
void func_002671B0(M1Actor *a, M1Actor *b, s32 n, Vec3f pos, M1Pair p);
void func_00285D80(s32 *p, M1Actor *a, s32 n);
void func_00214178(M1Actor *a, M1State *s, s32 n);

void func_0020486C(M1Actor *actor, M1State *state) {
    M1Info *info = &actor->def->info;
    f32 scale;
    f32 v;
    f32 lim;
    s32 ok;
    M1Pair p;

    if (info->b8 != -1) {
        scale = (f32)info->b8 * D_800C6B70;
        ok = 1;
        if (actor->unkE6 != 1) {
            if (actor->h108 != (s8)state->unkCA) {
                ok = 0;
            } else if (actor->h10A != (s8)state->unkCA) {
                ok = 0;
            } else {
                if (state->unkCB != 0 && !(actor->flags & 0x400)) {
                    ok = 1;
                } else {
                    if (actor->h10C < 3 && (actor->flags & 0x400)) {
                        v = (f32)actor->h12C * scale;
                        lim = actor->f134;
                    } else {
                        v = (f32)actor->h10C * scale;
                        lim = actor->f104;
                    }
                    ok = 1;
                    if (!(v <= lim)) ok = 0;
                }
            }
        }
        if (ok) {
            p.a = 0;
            func_002671B0(actor, actor, 6, actor->pos, p);
            func_00285D80(D_8011FE88, actor, 1);
        }
    }
    if ((actor->def->info.flags & 1) && state->unkCB != 0 && (info->unk4.f == 0.0f || state->f64 < info->unk4.f)) {
        if (state->f64 == 0.0f) {
            state->f40 = 0.0f;
        }
        state->f64 = info->unk4.f;
    }
    if (state->f64 != 0.0f && state->f64 <= state->f40) {
        func_00214178(actor, state, 1);
    }
}
