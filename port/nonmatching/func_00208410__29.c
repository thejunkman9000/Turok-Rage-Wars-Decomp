#include "b02_types.h"

f32 func_00209308(B2Ctl *ctl, Vec3f *target, f32 a2, f32 a3);
s32 func_00209828(B2Ctl *ctl);
Vec3f *func_0020C994(B2Mgr *m, s32 idx);
B2Edge *func_0020C9B0(B2Mgr *m, s32 idx);
s32 func_0020CC0C(B2Mgr *m, s32 x, s32 y);
B2Node *func_0020CFE0(B2Mgr *m, s32 key);
s32 **func_0024E690(B2Actor *a);
void func_00271FD8(Vec3f *out, Vec3f *a, Vec3f *b);
f32 func_00272768(Vec3f *a, Vec3f *b);
extern B2Mgr D_8013B364;
extern f32 D_800C6CA8;
extern f32 D_800C6CAC;
extern f32 D_800C6CB0;
extern f32 D_800C6CB4;
extern f32 D_800C6CB8;
extern f32 D_800C6CBC;
extern f32 D_800C6CC0;
extern f32 D_800C6CC4;
extern f32 D_800C6CC8;

void func_00208410(B2Ctl *ctl) {
    Vec3f d;
    Vec3f *self;
    Vec3f *cur;
    Vec3f *tgt;
    B2Actor *o;
    B2Edge *e;
    B2Node *n;
    f32 dist;
    f32 lim;
    f32 w;
    s32 edge;
    s32 from;
    s32 st;
    s32 v;
    s32 flag;
    s32 nx;
    s32 f1;
    s32 f2;
    s32 **t;
    B2Mgr *m = &D_8013B364;

    o = ctl->owner;
    if (ctl->unkC != -1 && (ctl->unk300 = 0, ctl->unk310 = 0, ctl->unk304 = 0, ctl->unk308 = 0, ctl->unk30C = 0, ctl->q[0] != -1)) {
        cur = func_0020C994(m, ctl->q[0]);
        self = &ctl->owner->pos;
        dist = func_00272768(self, cur);
        from = ctl->q[0];
        v = ctl->unk4;
        ctl->unk304 = (*(u32 *)((u8 *)cur + 0xC) & 0x300000) != 0;
        if (from == v) {
            v = ctl->unk8;
        }
        edge = func_0020CC0C(m, v, from);
        if (edge > 0) {
            e = func_0020C9B0(m, edge);
            if (e->kind == 4) {
                ctl->unk30C = 1;
            }
            if (e->kind == 8) {
                func_00272768(self, func_0020C994(m, ctl->unk4));
                tgt = func_0020C994(m, ctl->q[0]);
                ctl->unk308 = 1;
                if (edge != ctl->unk32C) {
                    ctl->unk314 = 0;
                    ctl->unk32C = edge;
                }
                if (ctl->unk314 == 0) {
                    cur = func_0020C994(m, ctl->unk4);
                    func_00271FD8(&d, self, cur);
                    if (sqrtf(d.x * d.x + d.z * d.z) < D_800C6CA8) {
                        ctl->unk314 = 1;
                    } else {
                        ctl->v2C = *cur;
                        return;
                    }
                }
                if (ctl->unk314 == 1) {
                    ctl->v2C = *tgt;
                    w = func_00209308(ctl, &ctl->v2C, 2.0f, 0.0f);
                    if (w < 0.0f ? D_800C6CAC < -w : D_800C6CB0 < w) {
                        ctl->unk310 = 1;
                        return;
                    }
                    ctl->unk314 = 2;
                }
                nx = 3;
                if (ctl->unk314 == 2 || (nx = 4, ctl->unk314 == 3) || (nx = 5, ctl->unk314 == 4)) {
                    ctl->v2C = *tgt;
                    ctl->unk314 = nx;
                    return;
                }
                if (ctl->unk314 == 5) {
                    ctl->v2C = *tgt;
                    o->unk6B0 |= 0x10;
                    ctl->unk314 = 6;
                    return;
                }
                if (ctl->unk314 == 6) {
                    v = ctl->owner->flags38;
                    f1 = v & 0x2000;
                    f2 = v & 0x1000;
                    if (f1 || f2) {
                        ctl->unk314 = 2;
                    }
                    ctl->v2C = *tgt;
                }
            } else if (e->kind == 5) {
                if (ctl->unk314 == 0) {
                    cur = func_0020C994(m, ctl->unk4);
                    if (!(func_00272768(self, cur) < D_800C6CB4)) {
                        ctl->v2C = *cur;
                        return;
                    }
                    ctl->unk314 = 1;
                }
                st = ctl->unk314;
                if (st == 1) {
                    n = func_0020CFE0(m, ctl->unk4);
                    if (func_00272768(&n->unk40->pos, &n->v44) < D_800C6CB8) {
                        ctl->v2C = n->unk40->pos;
                        o->unk6B0 |= 0x10;
                        ctl->unk314 = 2;
                        return;
                    }
                    ctl->v2C = n->v44;
                    ctl->unk310 = st;
                }
                if (ctl->unk314 == 2) {
                    flag = 0;
                    t = func_0024E690(ctl->owner);
                    if (t != NULL) {
                        flag = *t == (s32 *)2;
                    }
                    func_00271FD8(&d, self, &func_0020CFE0(m, ctl->unk4)->unk40->pos);
                    lim = sqrtf(d.x * d.x + d.z * d.z);
                    if (flag != 0 && lim < D_800C6CBC) {
                        ctl->unk314 = 3;
                    } else {
                        ctl->v2C = func_0020CFE0(m, ctl->unk4)->unk40->pos;
                        return;
                    }
                }
                if (ctl->unk314 == 3) {
                    flag = 0;
                    t = func_0024E690(ctl->owner);
                    if (t != NULL) {
                        flag = *t == (s32 *)2;
                    }
                    if (flag == 0) {
                        ctl->unk314 = 0;
                    }
                    tgt = func_0020C994(m, ctl->q[0]);
                    n = func_0020CFE0(m, ctl->q[0]);
                    if (func_00272768(&n->unk40->pos, &n->v44) < D_800C6CC0) {
                        ctl->v2C = *tgt;
                        o->unk6B0 |= 0x10;
                    } else {
                        ctl->v2C = *tgt;
                        ctl->unk310 = 1;
                        return;
                    }
                }
            } else {
                ctl->unk314 = 0;
            }
        } else {
            ctl->unk314 = 0;
        }
        if (ctl->q[1] == -1 || (*(u16 *)((u8 *)cur + 0xC) & 0x100) != 0) {
            lim = D_800C6CC8;
        } else {
            lim = D_800C6CC4;
        }
        if (dist < lim && ctl->unk4 == ctl->q[0]) {
            if (func_00209828(ctl) != 0) {
                goto done;
            }
        } else {
done:
            if (ctl->q[0] != -1) {
                cur = func_0020C994(m, ctl->q[0]);
                if (*(u16 *)((u8 *)cur + 0xC) & 2) {
                    ctl->v2C = ctl->dst1B0;
                    return;
                }
                ctl->v2C = *cur;
            }
        }
    } else {
        ctl->unk300 = 1;
    }
}
