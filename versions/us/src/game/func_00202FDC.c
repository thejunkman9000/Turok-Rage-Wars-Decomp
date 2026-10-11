#include "m01_types.h"

extern f32 D_800C6B0C;
extern f32 D_800C6B10;
f32 func_00274878(f32 a, f32 b, f32 c);
void func_00271FD8(Vec3f *dst, Vec3f *a, Vec3f *b);
void func_00273744(f32 *m, f32 a);
void func_00272908(f32 *m, Vec3f *a, Vec3f *out);
void func_00272038(Vec3f *dst, f32 t, Vec3f *a, Vec3f *b);

void func_00202FDC(M1Actor *actor, M1State *state, s32 mode, M1Actor *tgt) {
    M1Info *info = &actor->def->info;
    f32 t = state->f64;
    f32 k;
    f32 fa, d, hi, v;
    Vec3f P;
    Vec3f A;
    Vec3f B;
    f32 m[16];

    if (info->f60 != 0.0f || info->f5C != 0.0f) {
        k = info->f68 / sqrtf(info->f60 * info->f60 + info->f5C * info->f5C);
    } else {
        k = 0.0f;
    }
    switch (mode) {
    case 1:
        fa = k;
        if (state->unk37 == mode) {
            fa = -fa;
        }
        d = func_00274878(state->unk128.f, fa, 0.25f);
        t = t + d;
        state->unk128.f = d;
        if (state->unk37 == 0) {
            hi = D_800C6B0C;
            if (hi < t) {
                state->unk128.f = 0.0f;
                state->unk37 = mode;
            }
        } else {
            if (t < 0.0f) {
                state->unk128.f = 0.0f;
                state->unk37 = 0;
            }
            goto block24;
        }
        break;
    case 2:
        if (tgt != NULL) {
            if (info->f64 != 0.0f) {
                func_00271FD8(&A, &tgt->pos, &state->vA0);
                func_00273744(m, -info->f64);
                func_00272908(m, &A, &B);
                v = B.z / info->f60;
            } else {
                v = 0.0f;
            }
            fa = v - t;
            if (k < fa) {
                fa = k;
            } else if (fa < -k) {
                fa = -k;
            }
            d = func_00274878(state->unk128.f, fa, 0.25f);
            t = t + d;
            state->unk128.f = d;
        }
    case 0:
    default:
block24:
        hi = D_800C6B10;
        break;
    }
    if (hi < t || (hi = 0.0f, t < 0.0f)) {
        t = hi;
    }
    state->f64 = t;
    P = state->vA0;
    P.x = P.x + info->f60 * sinf(info->f64);
    P.y = P.y + info->f5C;
    P.z = P.z + info->f60 * cosf(info->f64);
    func_00272038(&state->v54, t, &state->vA0, &P);
}
