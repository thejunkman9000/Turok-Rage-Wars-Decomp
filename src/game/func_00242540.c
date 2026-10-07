#include "b10_types.h"

void func_00241940(B10Mo *mo, B10Buf *buf, B10Mv *mv, B10T2 *t);
void func_00241B9C(B10Mv *mv, B10Mo *mo, B10Buf *buf, B10Ev *ev, B10T2 *t);
void func_00241F14(B10Mv *mv, B10Mo *mo, B10Buf *buf, B10Ev *ev, B10T2 *t);
void func_00271FD8(Vec3f *a, Vec3f *b, f32 *c);

void func_00242540(B10Mv *mv, B10T2 *t) {
    Vec3f sa;
    Vec3f sb;
    B10Ev ev;
    B10Buf buf;
    B10Mo *mo = mv->p0;
    B10Mkk *k = &mo->p18->k;
    if (mv->p40->flags & 0x40000) {
        sa = mv->a;
        sb = mv->b;
        mv->a = t->pos;
        func_00271FD8(&mv->b, &t->pos, &mv->f5C);
        ev.f4 = 0;
        ev.f8 = 1;
        ev.fC = 0;
        ev.f10 = 0;
        ev.f54 = (s32)t;
        ev.f58 = -1;
        func_00241940(mo, &buf, mv, t);
        switch (k->kind) {
        case 1:
            func_00241F14(mv, mo, &buf, &ev, t);
            break;
        case 2:
            func_00241B9C(mv, mo, &buf, &ev, t);
            break;
        }
        mv->a = sa;
        mv->b = sb;
    }
}