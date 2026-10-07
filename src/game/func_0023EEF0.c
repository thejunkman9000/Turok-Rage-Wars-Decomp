
#include "m03_types.h"

typedef struct M03CObj {
    /* 0x00 */ u8 type;
    /* 0x01 */ u8 pad1[7];
    /* 0x08 */ M03V3 pos;
    /* 0x14 */ u8 pad14[4];
    /* 0x18 */ s32 *def;
} M03CObj;
typedef struct M03CBox {
    /* 0x00 */ f32 r;
    /* 0x04 */ f32 f4;
    /* 0x08 */ f32 f8;
    /* 0x0C */ f32 ymin;
    /* 0x10 */ f32 f10;
    /* 0x14 */ f32 f14;
    /* 0x18 */ f32 f18;
    /* 0x1C */ f32 xmin;
    /* 0x20 */ f32 zmin;
    /* 0x24 */ f32 xmax;
    /* 0x28 */ f32 zmax;
    /* 0x2C */ s32 flag;
} M03CBox;
typedef struct M03CDef { u8 pad0[4]; s8 b4; } M03CDef;
typedef struct M03CMover {
    /* 0x000 */ M03CObj *owner;
    /* 0x004 */ u8 pad4[0x3C];
    /* 0x040 */ M03CDef *def;
    /* 0x044 */ M03V3 v44;
    /* 0x050 */ M03V3 v50;
    /* 0x05C */ f32 f5C;
    /* 0x060 */ f32 f60;
    /* 0x064 */ u8 pad64[0x4C];
    /* 0x0B0 */ M03Quad qcopy;
    /* 0x18C */ u8 pad18C[0x1C];
} M03CMover;

f32 func_0024D274(void *o);
f32 func_0024D388(void *o);
f32 func_0024E410(void *o);
void func_00242278(M03CMover *m, M03CObj *o);
void func_00242540(M03CMover *m, M03CObj *o);
s32 func_002AC3F0(M03CObj *a, M03CObj *b);
void func_00272038(M03V3 *o, f32 t, void *a, void *b);
s32 func_0023E168(M03CMover *m, M03V3 *p, f32 h, f32 a, f32 b, s32 c, M03Quad *q, s32 d);
void func_0023E8C4(M03CMover *m, M03Quad *q, s32 a);

void func_0023EEF0(M03CMover *m, M03CBox *b, M03CObj *o) {
    f32 c[4];
    M03V3 p;
    M03V3 w;
    M03Quad q;
    M03CObj *own;
    M03CDef *def;
    f32 ox, oz;
    f32 cr;
    f32 fx, fz;
    f32 y0, y1;
    f32 sx, sz;
    f32 rr;
    f32 t;
    f32 dx, dz;
    s32 s4;
    f32 zero;

    ox = o->pos.x;
    oz = o->pos.z;
    cr = func_0024D388(o);
    c[0] = ox - cr;
    c[2] = ox + cr;
    c[1] = oz - cr;
    c[3] = oz + cr;
    if (c[0] < b->xmax && b->xmin < c[2] && c[1] < b->zmax && b->zmin < c[3]) {
        own = m->owner;
        def = m->def;
        s4 = 0;
        if (own->type == 1 && *own->def == 2) {
            if (o->type == own->type) {
                func_00242540(m, o);
            }
        } else if (o->type == 1 && *o->def == 2) {
            if (own->type == o->type) {
                func_00242278(m, o);
            }
        } else if (o->type == 3) {
            if (func_002AC3F0(o, own) != 0) {
                s4 = 1;
                goto go;
            }
        } else {
go:
            q.f0 = 7;
            q.nv = 1;
            q.f4 = 0;
            q.fC = 0;
            q.f10 = 0;
            q.ref = o;
            q.ref58 = -1;
            y0 = o->pos.y + func_0024E410(o);
            y1 = func_0024D274(o) + y0;
            if (b->flag != 0) {
                zero = 0.0f;
                w.z = zero;
                w.x = zero;
            }
            sx = own->pos.x;
            sz = own->pos.z;
            rr = b->r + cr;
            if (b->flag != 0 && m->f60 != 0.0f) {
                if (b->ymin <= y0 && y0 < b->f14) {
                    t = (y0 - b->ymin) / m->f60;
                    if (t < *(f32 *)((u8 *)m + 0x17C)) {
                        func_00272038(&p, t, &own->pos, &m->v50);
                        dx = ox - p.x;
                        dz = oz - p.z;
                        if (dx * dx + dz * dz < rr * rr) {
                            q.f8 = 7;
                            q.v[0] = p;
                            q.n.x = 0.0f;
                            q.n.z = 0.0f;
                            q.n.y = -1.0f;
                            func_0023E8C4(m, &q, 1);
                        }
                    }
                }
                if (y1 <= b->f10 && b->f18 < y1) {
                    t = (y1 - b->f10) / m->f60;
                    if (t < *(f32 *)((u8 *)m + 0x17C)) {
                        func_00272038(&p, t, &own->pos, &m->v50);
                        dx = ox - p.x;
                        dz = oz - p.z;
                        if (dx * dx + dz * dz < rr * rr) {
                            if (def->b4 == 1) {
                                q.f8 = def->b4;
                            } else {
                                if (*(s32 *)((u8 *)o->def + 4) & 0x80) {
                                    q.f8 = 2;
                                } else {
                                    q.f8 = 7;
                                }
                            }
                            q.v[0] = p;
                            q.n.x = 0.0f;
                            q.n.z = 0.0f;
                            q.n.y = 1.0f;
                            func_0023E8C4(m, &q, 1);
                        }
                    }
                }
            }
            if (s4 == 0) {
                q.f8 = def->b4;
            } else {
                q.f8 = 7;
            }
            func_0023E168(m, &o->pos, rr, y1 - b->f4, y0 - b->f8, 1, &q, 1);
            if (s4 != 0 && *(M03CObj **)((u8 *)m + 0x104) != o && b->f10 <= y1 && y0 < b->ymin) {
                dx = ox - sx;
                dz = oz - sz;
                if (dx * dx + dz * dz < rr * rr) {
                    q.t = 0;
                    q.n.x = 0.0f;
                    q.n.y = 0.0f;
                    q.n.z = 0.0f;
                    q.hit = m->v44;
                    m->qcopy = q;
                }
            }
        }
    }
}
