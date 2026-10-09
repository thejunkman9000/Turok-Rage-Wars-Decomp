/* port (passthru_fix.py): func_0024795C needs a1 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "b11_types.h"
#include "m03_types.h"

extern const f32 D_800C8D74;
extern f32 D_800C8D78;
extern f32 D_800C8D7C;
extern f32 D_800C8D80;
extern f32 D_800C8D84;
extern f32 D_80115DEC;
extern u8 D_80145040[];
f32 sinf(f32);
f32 cosf(f32);
Obj *func_0022A470(void *a, Vec3f v);
void func_0024795C(Quat4 *q, u32);
f32 func_0024D274(Obj *a);
void func_00271FD8(Vec3f *o, Vec3f *a, Vec3f *b);
void func_00272088(Vec3f *o, Vec3f *a, Vec3f *b);
void func_002720EC(Vec3f *v);
void func_00272908(void *m, Vec3f *in, Vec3f *out);
void func_002742B4(Quat4 *q, void *m);
f32 func_00274640(f32 x);
void func_00274108(Quat4 *o, Quat4 *a, Quat4 *b);

Quat4 func_0024D49C(Obj *o, Vec3f target) {
    Vec3f pos;
    Vec3f d;
    Vec3f fwd;
    Vec3f tmp;
    Vec3f cross;
    Quat4 q;
    Quat4 qo;
    Quat4 res;
    u8 mtx[0x40];
    Obj *t;
    Obj *tobj;
    f32 ang;
    f32 s;

    t = NULL;
    if (o != NULL && o->type == 1) {
        t = *(Obj **)((u8 *)o + 0x1F0);
        func_0024795C(&qo, o);
        func_002742B4(&qo, mtx);
        tmp.x = 0;
        tmp.y = 0;
        tmp.z = D_800C8D74;
        func_00272908(mtx, &tmp, &fwd);
    } else {
        fwd.x = 0.0f;
        fwd.y = 0.0f;
        fwd.z = D_800C8D78;
    }
    if (t == NULL) {
        tobj = func_0022A470(D_80145040, target);
        if (tobj != NULL) {
            t = tobj;
        }
        if (t == NULL) {
            f32 zero = 0.0f;
            res.z = zero;
            res.y = zero;
            res.x = zero;
            res.w = D_800C8D7C;
            return res;
        }
    }
    pos = t->pos;
    pos.y += t->unk70;
    pos.y += func_0024D274(t) * D_800C8D80;
    func_00271FD8(&d, &pos, &target);
    func_002720EC(&d);
    func_00272088(&cross, &fwd, &d);
    func_002720EC(&cross);
    ang = func_00274640(fwd.x * d.x + fwd.y * d.y + fwd.z * d.z) * D_800C8D84;
    s = sinf(ang);
    D_80115DEC = s;
    q.x = cross.x * s;
    q.y = cross.y * s;
    q.z = cross.z * s;
    q.w = cosf(ang);
    if (o != NULL && o->type == 1) {
        func_00274108(&res, &qo, &q);
    } else {
        res = q;
    }
    return res;
}
