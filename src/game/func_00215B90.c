#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#include "b03_types.h"

extern f32 D_800C7288;
extern f32 D_800C72A4;
extern f32 D_800C72A8;
extern f32 D_800C72AC;
extern f32 D_800C72B0;
f32 sinf(f32 x);
f32 cosf(f32 x);
f32 sqrtf(f32 x);
f32 func_00274640(f32 x);
s32 func_00222A80(ActorB *a, s32 id);
f32 func_0024D274(ActorB *a);
void func_00271FD8(f32 *dst, f32 *a, f32 *b);
void func_002720EC(f32 *v);
void func_0024BC84(f32 *out, ActorB *t, Vec3f w);

static inline f32 func_00216F44(ActorB *o, Vec3f v) {
    f32 dx, dz, len, s, c, q, r;
    dx = v.x - o->pos.x;
    dz = v.z - o->pos.z;
    len = sqrtf(dx * dx + dz * dz);
    if (len == 0.0f) return 0.0f;
    s = sinf(o->unk6C);
    c = -cosf(o->unk6C);
    q = ((dx * -s) + (dz * c)) / len;
    q = MAX(-1.0f, MIN(1.0f, q));
    __asm__("" : : "f"(s));
    r = func_00274640(q);
    if (!((dx * c + dz * s) > 0.0f))
        r = -r;
    return r;
}

s32 func_00215B90(ActorB *actor, s32 unused, ActorB *t, f32 w) {
    Vec3f D;
    Vec3f E;
    Vec3f W;
    Vec3f A;
    Vec3f B;
    f32 lo, hi, y, ang;
    ActorB *o;

    if (t == NULL) return 0;
    if (t->flags & 0x300000) {
        o = t->owner;
        if (func_00222A80(o, o->unk62E) <= 0) return 0;
        if (!(FLD(u32, o, 0x6AC) & 0x2000)) return 0;
        goto body;
    }
    switch (FLD(s32, t->def, 0)) {
    case 1:
        if (FLD(s16, t, 0x238) < 0x10CC) return 0;
        goto body;
    case 4:
        if (FLD(s8, t, 0x1A4) != 0x3F) return 0;
        goto body;
    default:
        return 0;
    }
body:
    lo = actor->pos.y + actor->unk70;
    hi = lo + func_0024D274(actor);
    B.x = t->pos.x;
    y = t->pos.y + t->unk70 + func_0024D274(t) * D_800C7288;
    B.y = y;
    B.z = t->pos.z;
    A.x = actor->pos.x;
    A.z = actor->pos.z;
    if (hi < y) A.y = hi;
    else if (y < lo) A.y = lo;
    else A.y = y;
    ang = (func_00216F44(actor, B) < 0.0f) ? -func_00216F44(actor, B) : func_00216F44(actor, B);
    if (D_800C72A4 < ang && ang < D_800C72A8) return 0;
    func_00271FD8(&D.x, &A.x, &B.x);
    func_002720EC(&D.x);
    W.x = 0;
    W.y = 0;
    W.z = D_800C72AC;
    func_0024BC84(&E.x, t, W);
    if (func_00274640(D.x * E.x + D.y * E.y + D.z * E.z) < w * D_800C72B0) {
        if (D.x * -E.z + D.z * E.x < 0.0f) return -1;
        return 1;
    }
    return 0;
}
