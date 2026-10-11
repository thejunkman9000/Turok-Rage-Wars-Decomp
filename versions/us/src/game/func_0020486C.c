#include "m01_types.h"

extern f32 D_800C6B70;
extern s32 D_8011FE88[];
typedef struct M1Pair { s32 a; s32 b; } M1Pair;
void func_002671B0(M1Actor *a, M1Actor *b, s32 n, Vec3f pos, M1Pair p);
void func_00285D80(s32 *p, M1Actor *a, s32 n);
void func_00214178(M1Actor *a, M1State *s, s32 n);

static inline s32 r01_check(M1Actor *actor, M1State *state, f32 scale) {
    if (actor->unkE6 == 1) return 1;
    if (actor->h108 != (s8)state->unkCA || actor->h10A != (s8)state->unkCA) return 0;
    if (state->unkCB != 0 && !(actor->flags & 0x400)) return 1;
    if (actor->h10C < 3 && (actor->flags & 0x400)) {
        return (f32)actor->h12C * scale <= actor->f134;
    } else {
        return (f32)actor->h10C * scale <= actor->f104;
    }
}

void func_0020486C(M1Actor *actor, M1State *state) {
    M1Info *info = &actor->def->info;
    M1Pair p;
    f32 t;

    if (info->b8 != -1) {
        if (r01_check(actor, state, (f32)info->b8 * D_800C6B70)) {
            p.a = 0;
            func_002671B0(actor, actor, 6, actor->pos, p);
            func_00285D80(D_8011FE88, actor, 1);
        }
    }
    if ((info->flags & 1) && state->unkCB != 0) {
      t = info->unk4.f;
      if (t == 0.0f || state->f64 < t) {
        if (state->f64 == 0.0f) {
            state->f40 = 0.0f;
        }
        state->f64 = t;
      }
    }
    if (state->f64 != 0.0f && state->f64 <= state->f40) {
        func_00214178(actor, state, 1);
    }
}
