#include "m02_gen.h"
extern s32 D_800CE47C;
extern u8 D_800CE7E4[];
extern u8 D_800CE82C[];
extern s16 D_800CE84E;
extern f32 D_800D2988;
extern s32 D_80104418;
f32 sinf(f32);
void func_00218464(void *p);
void func_002227D0(M2P *p, M2Q *q, s32 a);
void func_002231B0(M2P *p, M2Q *q, void *t);
void func_002233CC(M2P *p, M2Q *q, void *t);
void func_0025DE74(s32 id, Vec3f pos, void *pp, s32 x);
void func_002748E0(Vec3f *v, f32 a, f32 b);
void func_00224C28(M2P *p, M2Q *q) {
    f32 amp;
    f32 t;
    s32 ok;
    s32 f;
    s32 id;
    s32 *g;
    s32 *g2;
    s32 m;
    if (p->f6C8 == 0.0f) {
        p->unk650 = 9;
    } else {
        p->unk650 = 10;
    }
    func_002748E0((Vec3f *)&p->f72C, 0.0f, 0.25f);
    func_002231B0(p, q, D_800CE7E4);
    func_002233CC(p, q, D_800CE82C);
    if (!(q->flags38 & 0x2000)) {
        func_00218464((u8 *)p + 0x938);
        func_002227D0(p, q, 3);
        return;
    }
    if (p->f724 * 57.295776f < -40.0f && p->f6A8 > 0.0f) {
        g = &D_80104418;
        p->f6EC = p->f6EC - 10.24f;
        *g |= 0x100000;
    } else {
        m = 0xFFEFFFFF;
        g = &D_80104418;
        *g &= m;
    }
    amp = 0.043633237f;
    p->f730 = sinf(p->f658 * 0.06981318f) * amp;
    p->f734 = sinf(p->f658 * 0.087266475f) * amp;
    p->f738 = sinf(p->f658 * 0.104719765f) * amp;
    if (p->unk7E8 != 0) goto zero;
    if (11.25f < p->f6E4) goto zero;
    if (q->flags38 & 0xC0000) goto zero;
    if (!(q->def->unk14 & 2)) goto zero;
    if (!(p->unk6B0 & 0x10)) goto zero;
    if (!(p->f11D8 <= 0.0f)) goto zero;
    func_002227D0(p, q, 5);
    ok = 1;
    goto join;
zero:
    ok = 0;
join:
    if (ok == 0) {
        f = 0;
        if (p->unk86C == 0x1144) {
            f = p->unk10E == 0;
        }
        if (p->unkE4 == D_800CE47C) {
            id = 0x8A2;
        } else {
            if (f != 0) {
                goto skip;
            }
            if (1.024f <= p->f6C0) {
                id = 0x8A2;
            } else {
                id = 0x8A7;
                if (!(p->f6C0 <= -1.024f)) {
                    id = 0x14;
                }
            }
        }
        p->unk86C = id;
skip:
        t = p->f11C4 + D_800D2988;
        p->f11C4 = t;
        if (5.12f < p->f6C8 && 11.25f < t) {
            p->f11C4 = 0.0f;
            func_0025DE74(D_800CE84E, q->pos, 0, -1);
        }
    }
}
