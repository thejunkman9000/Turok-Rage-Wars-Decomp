#include "b20_types.h"

typedef struct {
    s32 type;
    u8 pad4[0x10];
    u32 flags14;
    u8 pad18[8];
    f32 f20;
    f32 f24;
    f32 f28;
} DefQ;

f32 func_0024E410(Entity *e);
f32 func_0024D274(Entity *e);
s32 func_00204308(Entity *e, u8 *p, Entity *me);
void func_00214178(Entity *e, u8 *p, s32 a);

void func_0028A258(Level *lv, Entity *me, Vec3f *p0, Vec3f *p1) {
    s32 isB;
    s32 is1;
    f32 myBot;
    f32 myTop;
    s32 i;
    Entity *e;
    f32 eBot;
    f32 eTop;
    s32 kind;
    s32 s1;
    s32 s2;
    s32 s3;
    s32 s4;
    s32 a0;
    s32 v1;
    s32 a2;
    s32 a1;
    s32 hit;
    s32 hit2;
    f32 r1;
    f32 r2;
    f32 dx;
    f32 dz;
    f32 d0;
    f32 d1;
    f32 ex;
    f32 ez;
    s32 ok;
    u32 fl;
    if (p0->x != p1->x || p0->y != p1->y || p0->z != p1->z) {
        kind = me->def->type;
        isB = kind == 0xB;
        is1 = kind == 1;
        myBot = me->pos.y + func_0024E410(me);
        myTop = myBot + func_0024D274(me);
        for (i = 0; i < lv->cntFDC; i++) {
            e = lv->arrF5C[i];
            s4 = 0;
            if (e != me) {
                s1 = 0;
                eBot = e->pos.y + func_0024E410(e);
                eTop = eBot + func_0024D274(e);
                switch (((DefQ *)e->def)->type) {
                case 6:
                    s2 = 0;
                    s3 = s4 = 1;
                    fl = ((DefQ *)e->def)->flags14;
                    r1 = ((DefQ *)e->def)->f20;
                    r2 = ((DefQ *)e->def)->f24;
                    a0 = fl & 4;
                    v1 = fl & 8;
                    a2 = fl & 0x10;
                    a1 = fl & 0x20;
                    break;
                case 10:
                    s2 = 1;
                    s3 = 0;
                    a2 = s3;
                    a1 = s3;
                    s1 = s2;
                    fl = ((DefQ *)e->def)->flags14;
                    r1 = ((DefQ *)e->def)->f24;
                    r2 = 0.0f;
                    a0 = fl & 4;
                    v1 = fl & 8;
                    break;
                case 7:
                    s2 = 1;
                    s3 = 0;
                    a2 = s3;
                    a1 = s3;
                    s1 = s2;
                    fl = ((DefQ *)e->def)->flags14;
                    r1 = ((DefQ *)e->def)->f28;
                    r2 = 0.0f;
                    a0 = fl & 8;
                    v1 = fl & 0x10;
                    break;
                default:
                    s2 = 0;
                    r1 = 0.0f;
                    a0 = 0;
                    v1 = 0;
                    s3 = 0;
                    a2 = 0;
                    a1 = 0;
                    r2 = 0.0f;
                    break;
                }
                if (s1 != 0 && (hit = 0, myTop < eBot || eTop < myBot)) {
                    hit2 = 0;
                } else {
                    hit = 0;
                    if (isB != 0 && a0 != 0) {
                        hit = 1;
                    } else if (is1 != 0 && v1 != 0) {
                        hit = 1;
                    }
                    hit2 = 0;
                    if ((isB != 0 && a2 != 0) || (is1 != 0 && a1 != 0)) {
                        hit2 = 1;
                    }
                }
                if (hit != 0 || hit2 != 0) {
                    ex = e->pos.x;
                    ez = e->pos.z;
                    dx = p0->x - ex;
                    dz = p0->z - ez;
                    d0 = dx * dx + dz * dz;
                    dx = p1->x - ex;
                    dz = p1->z - ez;
                    d1 = dx * dx + dz * dz;
                    if (hit != 0) {
                        if (s4 != 0) {
                            ok = 0;
                            if (r1 * r1 < d0) {
                                if (d1 <= r1 * r1) {
                                    ok = 1;
                                }
                            }
                        } else {
                            ok = 1;
                            if (!(d1 <= r1 * r1)) {
                                ok = 0;
                            }
                        }
                        if (ok != 0) {
                            if (e->def->type == 10 && s2 == 1) {
                                ok = func_00204308(e, (u8 *)e + 0x170, me);
                            }
                            if (ok != 0) {
                                func_00214178(e, (u8 *)e + 0x170, s2);
                            }
                        }
                    }
                    if (hit2 != 0) {
                        if (s4 != 0) {
                            ok = 0;
                            if (d0 <= r2 * r2) {
                                if (r2 * r2 < d1) {
                                    ok = 1;
                                }
                            }
                        } else {
                            ok = 1;
                            if (!(r2 * r2 < d1)) {
                                ok = 0;
                            }
                        }
                        if (ok != 0) {
                            func_00214178(e, (u8 *)e + 0x170, s3);
                        }
                    }
                }
            }
        }
    }
}
