#include "m01_types.h"

typedef struct M1Quat { f32 x, y, z, w; } M1Quat;
extern f32 D_800C6B04;
extern f32 D_800C6B08;
extern f32 D_80115DEC;
void func_00202CA0(M1Quat *out, Vec3f *v);
void func_002742B4(M1Quat *q, f32 *m);
void func_00274108(M1Quat *out, M1Quat *a, Vec3f *b);
void func_002734EC(f32 *m, f32 x, f32 y, f32 z);
void func_002734B8(f32 *m, f32 x, f32 y, f32 z);
void func_002725BC(Vec3f *p, f32 v);
void func_0026F690(u8 *dst, f32 *a, f32 *b);
void func_00273DDC(u8 *m);

static inline void r01_mk(M1State *state, f32 *m2) {
    M1Quat qB;
    Vec3f vC;
    vC.x = state->vec130.x;
    vC.y = state->vec130.y;
    vC.z = state->vec130.z;
    func_00202CA0(&qB, &vC);
    func_002742B4(&qB, m2);
}

void func_00202E4C(M1Actor *actor, M1State *state) {
    M1Quat Q;
    M1Quat q2;
    f32 m1[16];
    f32 m2[16];
    M1Info *info;
    f32 k;
    f32 sn;

    info = &actor->def->info;
    r01_mk(state, m2);
    if (info->unk40.i == -1) {
        sn = sinf(actor->f6C * 0.5f);
        Q.x = 0.0f;
        Q.y = sn;
        Q.z = 0.0f;
        D_80115DEC = sn;
        Q.w = cosf(actor->f6C * 0.5f);
    } else {
        D_80115DEC = sinf(state->f9C * D_800C6B04);
    }
    Q.x = 0.0f;
    Q.z = 0.0f;
    Q.y = D_80115DEC;
    Q.w = cosf(state->f9C * D_800C6B08);
    func_00274108(&q2, &Q, &actor->v5C);
    func_002742B4(&q2, m1);
    func_002734EC(m1, actor->f50, actor->f54, actor->f58);
    func_002725BC(&actor->pos, 20000.0f);
    func_002734B8(m1, actor->pos.x, actor->pos.y, actor->pos.z);
    func_0026F690(actor->mtx74, m2, m1);
    func_00273DDC(actor->mtx74);
}
