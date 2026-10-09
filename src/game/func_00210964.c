#include "b03_types.h"

typedef struct FbSlot {
    u8 pad[0x1F0];
    f32 v;
} FbSlot;
#define FB(a, i4) (((FbSlot *)((u8 *)(a)->brain + (i4)))->v)

extern f32 D_800C7088;
extern f32 D_800C708C;
extern f32 D_800C7090;
extern f32 D_800C7094;
extern f32 D_800C7098;
extern f32 D_800C709C;
extern Vec3f D_800CDAF0[];
extern HitRec *D_80103FCC;
f32 func_0024E454(void);
f32 func_0024D388(ActorB *a);
f32 func_0024D274(ActorB *a);
f32 func_0024E410(ActorB *a);
s32 func_0024490C(ActorB *a, Vec3f from, Vec3f to, TraceInfo *info, f32 p0, f32 p1, f32 p2, f32 p3);

void func_00210964(ActorB *a, s32 idx) {
    Vec3f v30;
    Vec3f v40;
    Vec3f v50;
    TraceInfo ti;
    f32 r;
    f32 cur;
    f32 q0;
    f32 q1;
    f32 q2;
    s32 steps;
    s32 n;
    s32 m;
    f32 *pf;
    s32 i4;

    i4 = idx * 4;
    do {
        FB(a, i4) = D_800C7088;
        r = func_0024E454();
        cur = FB(a, i4);
        if (!(cur < r)) {
            v50 = D_800CDAF0[idx];
            n = 0;
            steps = (s32)(cur / (r * D_800C708C) + D_800C7090);
            v50.x = v50.x * D_800C708C * r;
            v50.z = v50.z * D_800C708C * r;
            q0 = func_0024D388(a);
            q1 = func_0024D274(a);
            q2 = func_0024E410(a);
            v30 = a->pos;
            ti.mask = 0xC008;
            ti.a = 1;
            ti.b = 1;
            ti.c = 1;
            ti.pad8[0] = 0;
            ti.pad8[1] = 0;
            ti.pad8[2] = 0;
            ti.pad8[3] = 0;
            ti.pad8[4] = 0;
            v30.y += D_800C7094;
            if (n >= steps) goto done;
        top:
            v30.x += v50.x;
            v30.z += v50.z;
            do {
                v40 = v30;
                v40.y -= D_800C7098;
                if (func_0024490C(a, v30, v40, &ti, r, q0, q1, q2) != 0
                    && (u32)(D_80103FCC->type - 5) >= 2
                    && !(D_80103FCC->pos.y <= v40.y - D_800C709C)) {
                    goto cont;
                }
                pf = &FB(a, i4);
                m = n - 1;
                if (m < 0) {
                    m = 0;
                }
                *pf = (f32)m * r;
                goto done;
            } while (0);
        cont:
            n++;
            if (n < steps) goto top;
        done:;
        }
    } while (0);
}
