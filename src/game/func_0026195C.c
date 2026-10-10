/* func_0026195C: animation sampler (advances the playback time, handles loop wrap, accumulates a delta).
 * Needs flags -O2 -mcpu=r4300.  `seg` is pinned to $s2 (register allocation priority hack). */
#include "s407_types.h"

extern f32 D_800C92E0[];
extern f32 D_800D2988;

void *func_002604BC();
void *func_0028FD94(void *n, s32 i);
void func_002476B8(S407Obj *o, S407Anim *a, f32 t0, f32 t1);
void func_0025E5D0(S407Anim *a, s32 z, f32 t, S407Vec3 *out);
f32 func_00273F54(f32 frac, f32 a, f32 b);
f32 func_00274004(f32 a, f32 b);
void func_00271FA4(S407Vec3 *d, S407Vec3 *s, S407Vec3 *m);
void func_00271FD8(S407Vec3 *d, S407Vec3 *s, S407Vec3 *m);
s32 func_002625E4(S407Anim *a);

/* linear/cubic sample of the 16-bit track at time t; K = scale */
#define INTERP(a, t, K) ({ \
    S407Anim *ia = (a); \
    f32 it = (t); \
    void *p = func_0028FD94(func_002604BC(ia), 0); \
    s32 last = ia->n - 1; \
    s16 *tab = (s16 *)((u8 *)p + 8); \
    s32 i0 = (s32)it; \
    s32 i1 = i0 + 1; \
    if (i1 < last) { \
        last = i1; \
    } \
    func_00273F54(it - (f32)i0, (f32)tab[i0] * (K), (f32)tab[last] * (K)); \
})

void func_0026195C(S407Anim *a, S407Vec3 *out, f32 *acc, S407Obj *o) {
    void *h;
    register S407Seg *seg asm("$18");
    S407Vec3 v10;
    S407Vec3 v20;
    f32 prev;
    f32 t;
    f32 t1;
    f32 fend;
    f32 cur;
    u32 w;
    u32 e;
    s32 last;

    h = func_002604BC(a);
    out->x = 0;
    out->y = 0;
    out->z = 0;
    *acc = 0;
    if (o->flags & 0x8000000) {
        a->t = (f32)(a->n - 1);
        func_002476B8(o, a, 0.0f, a->t);
        o->flags = o->flags & 0xF7FFFFFF;
    }
    seg = func_0028FD94(func_0028FD94(h, 3), 0);
    func_0025E5D0(a, 0, a->t, &v10);
    t = a->t;
    prev = INTERP(a, t, 9.587673e-05f);
    t1 = a->t;
    if (!(o->flags & 0x8000000)) {
        a->t = t1 + D_800D2988 * seg->speed * 0.06666667f;
    }
    func_002476B8(o, a, t1, a->t);
    last = a->n - 1;
    fend = (f32)last;
    if (fend < a->t) {
        func_0025E5D0(a, 0, fend, &v20);
        cur = INTERP(a, fend, 9.587673e-05f);
        func_00271FA4(out, out, &v20);
        func_00271FD8(out, out, &v10);
        *acc += func_00274004(cur, prev);
        e = seg->end;
        w = 0;
        if (e != 0xFFFF) {
            w = e;
        }
        a->t = (f32)w + a->t - fend;
        if (fend < a->t) {
            a->t = (f32)w;
        }
        if (w >= last && a->cur == a->next && func_002625E4(a) == 0) {
            a->fB = 0;
        }
        func_002476B8(o, a, (f32)w, a->t);
        func_0025E5D0(a, 0, (f32)w, &v10);
        prev = INTERP(a, (f32)w, D_800C92E0[0]);
        a->fA = 1;
    }
    func_0025E5D0(a, 0, a->t, &v20);
    cur = a->t;
    cur = INTERP(a, cur, D_800C92E0[1]);
    func_00271FA4(out, out, &v20);
    func_00271FD8(out, out, &v10);
    *acc += func_00274004(cur, prev);
}
