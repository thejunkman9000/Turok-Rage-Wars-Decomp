

#include "r04_types.h"

extern f32 D_800C8860[];
extern f32 D_800C8868;
void func_00272908(f32 *m, f32 *in, f32 *out);
void func_00271FD8(Vec3f *a, Vec3f *b, Vec3f *c);
void func_00272088(Vec3f *a, Vec3f *b, Vec3f *c);
void func_002720EC(Vec3f *a);
s32 func_0023E8C4(R4Obj *o, R4Ev *ev, s32 a);
void func_0023DF60(R4Obj *o, Vec3f *p, f32 h, R4Ev *ev, s32 a);

void func_002433CC(R4Mv *mv, R4Vtx **tri) {
    f32 tmp[3];
    Vec3f e1;
    Vec3f e2;
    R4Ev ev;
    Vec3f pt;
    R4Obj *obj;
    R4Fl *fl;
    s32 i;
    s32 n;
    s32 m;
    f32 cross;
    f32 t;
    f32 x0, y0, x1, y1;
    R4Vtx *q0, *q1;
    u32 f;
    s32 k;

    q1 = tri[1];
    q0 = tri[0];
    x1 = q1->x;
    x0 = q0->x;
    y1 = q1->y;
    cross = (x1 - x0) * (tri[2]->y - y1) - (y1 - q0->y) * (tri[2]->x - x1);
    if (!(cross >= 0.0f)) {
        obj = mv->obj;
        ev.nv = 3;
        for (i = 0; i < 3; i++) {
            s16 *p = tri[i]->pos;
            tmp[0] = p[0];
            tmp[1] = p[1];
            tmp[2] = p[2];
            func_00272908(mv->p58->m, tmp, (f32 *)&ev.v[i]);
        }
        func_00271FD8(&e1, &ev.v[1], &ev.v[0]);
        func_00271FD8(&e2, &ev.v[2], &ev.v[1]);
        func_00272088(&ev.n, &e2, &e1);
        func_002720EC(&ev.n);
        fl = obj->p40;
        ev.f54 = (s32)mv->p58;
        ev.f58 = -1;
        ev.fC = mv->mode;
        ev.f10 = mv->flags60;
        m = mv->mode;
        if (m != 1) {
            if (m <= 0) goto kindB;
            if (m >= 9) goto kindB;
            if (m < 7) goto kindB;
        }
        f = fl->flags;
        if (f & 8) {
            if (f & 0x80000) {
                return;
            }
            ev.type = 6;
            ev.f4 = fl->f18;
            ev.f8 = 7;
            func_0023E8C4(obj, &ev, 1);
            ev.type = 5;
            ev.f8 = (fl->flags & 0x100000) ? 7 : fl->b6;
            t = (ev.n.y != 0.0f) ? obj->f1C : 0.0f;
            for (i = 0; i < 3; i++) {
                ev.v[i].y += t;
            }
            goto kindC;
        }
        return;
kindB:
        if (ev.n.y < 0.0f ? (-ev.n.y < D_800C8860[1]) : (ev.n.y < D_800C8868)) {
            k = 3;
            if (!(obj->flags3C & 0x1000)) {
                k = 4;
                if (!(mv->flags60 & 0x10000000)) {
                    k = 3;
                }
            }
            ev.type = k;
            ev.f4 = 0;
            ev.f8 = fl->b5;
        } else {
            k = 2;
            if (!(ev.n.y < 0.0f)) {
                k = 1;
            }
            ev.type = k;
            ev.f4 = fl->f10;
            ev.f8 = fl->b6;
        }
kindC:
        if ((u32)(ev.type - 5) < 2U) {
            func_0023DF60(obj, 0, obj->f8, &ev, 1);
            return;
        }
        if (obj->f8 == 0.0f && obj->fC == 0.0f) {
            func_0023E8C4(obj, &ev, 1);
            return;
        }
        pt.x = 0;
        pt.y = obj->f8;
        pt.z = 0;
        n = mv->cnt;
        n--;
        while (n != -1) {
          {
            if (n == mv->cnt - 1) {
                if (ev.type == 2) {
                    goto skip;
                }
            } else if (n == 0) {
                if (ev.type == 1) {
                    goto skip;
                }
            } else if ((u32)(ev.type - 1) < 2U) {
                goto skip;
            }
            func_0023DF60(obj, &pt, obj->f8, &ev, 1);
skip:
            n--;
            pt.y += mv->step;
          }
        }
    }
}




