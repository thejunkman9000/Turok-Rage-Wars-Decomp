#include "m01_types.h"

typedef struct M1Quat { f32 x, y, z, w; } M1Quat;
typedef struct B801Out { u8 pad0[4]; M1Actor *tgt; f32 f8; u8 padC[0x34]; f32 f40; u8 pad44[0x44]; } B801Out;
typedef struct V16 { f32 x, y, z, w; } V16;
M1Quat func_00202CA0(Vec3f *v);
void func_00202FDC(M1Actor *a, M1State *s, s32 mode, M1Actor *t);
void func_00203278(M1Actor *a, M1State *s, B801Out *out);
void func_00216808(M1Actor *a, M1State *s, f32 x, f32 y);
void func_00216D3C(M1Actor *a, M1State *s, B801Out *out, s32 z, s32 one);
f32 func_00216F44(M1Actor *a, Vec3f pos);
void func_002172D0(M1Actor *a, M1State *s, s32 id);
void func_00217388(M1Actor *a, M1State *s);
f32 func_0024D274(M1Actor *a);
void func_00271FA4(V16 *dst, V16 *a, V16 *b);
void func_00271FD8(V16 *dst, V16 *a, V16 *b);
f32 func_0027266C(V16 *v);
void func_00272C3C(f32 *m, V16 *v, V16 *out);
void func_00274090(f32 *a);
void func_002742B4(M1Quat *q, f32 *m);
f32 func_00274878(f32 a, f32 b, f32 c);

static inline void r01_mk(M1State *state, f32 *m) {
    M1Quat q;
    V16 V;
    V.x = state->vec130.x;
    V.y = state->vec130.y;
    V.z = state->vec130.z;
    q = func_00202CA0((Vec3f *)&V);
    func_002742B4(&q, m);
}

static inline void r01_xf(f32 *m, V16 *B, V16 *A, V16 *R) {
    func_00271FD8(R, B, A);
    func_00272C3C(m, R, B);
}

s32 func_002034A4(M1Actor *actor, M1State *state) {
    B801Out out;
    V16 A;
    V16 B;
    V16 S;
    f32 mt[16];
    f32 *m;
    V16 R;
    f32 ang;
    M1Info *info;
    M1Actor *t;
    s32 s7;
    f32 fs0, k, fs1;
    f32 lim, d, la;
    s32 mode;

    s7 = 0;
    info = &actor->def->info;
    ang = actor->f6C - state->f9C;
    func_00274090(&ang);
    switch (actor->unkE4) {
    case 0x40B:
        func_00216D3C(actor, state, &out, 0, 1);
        break;
    case 0x40C:
        func_00203278(actor, state, &out);
        break;
    }
    t = state->unk80;
    if (t != NULL && out.f40 <= info->unk4C.f) {
        fs1 = 0.5f;
        *(Vec3f *)&A = actor->pos;
        A.y = A.y + func_0024D274(actor) * fs1;
        *(Vec3f *)&B = t->pos;
        B.y = B.y + func_0024D274(t) * fs1;
        m = mt;
        r01_mk(state, m);
        r01_xf(m, &B, &A, &R);
        func_00271FA4(&B, &B, &A);
        func_00271FD8(&S, &B, &A);
        k = func_0027266C(&S);
        fs0 = func_00216F44(actor, *(Vec3f *)&B);
        out.f8 = fs0;
        if (out.f40 <= info->f54) {
            la = info->f58 * fs1;
            if ((fs0 < 0.0f ? -fs0 : fs0) < la) {
                s7 = 1;
            }
        }
        if (info->unk48.f < 6.283186f) {
            lim = info->unk48.f * 0.5f;
            d = ang + fs0;
            if (lim < d) {
                fs0 = lim - ang;
            } else {
                lim = -lim;
                if (d < lim) {
                    fs0 = lim - ang;
                }
            }
        }
        func_00202FDC(actor, state, info->b70, t);
    } else {
        k = 0.0f;
        fs0 = -ang;
        func_00202FDC(actor, state, info->b71, t);
    }
    if ((fs0 < 0.0f ? 0.01f < -fs0 : 0.01f < fs0) || state->unk124.f != k) {
        func_002172D0(actor, state, 0xC3F);
    } else {
        func_00217388(actor, state);
    }
    func_00216808(actor, state, info->f44, fs0);
    state->unk124.f = func_00274878(state->unk124.f, k, info->f44);
    return s7;
}
