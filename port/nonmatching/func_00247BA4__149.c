#include "b10_types.h"

extern const f32 D_800C8A58;
extern const f32 D_800C8A5C;
extern const f32 D_800C8A60;
extern const f32 D_800C8A64;
extern const f32 D_800C8A68;
extern const f32 D_800C8A6C;
extern const f32 D_800C8A70;
extern f32 D_80115DEC;
extern B10Obj *D_80120AD8[];
extern s32 D_80120CD8;
f32 sinf(f32 x);
f32 cosf(f32 x);
f32 trw_sqrtf(f32 x) __asm__("sqrtf");
void func_0024795C(B10Q4 *out, B10Obj *o);
f32 func_0024D274(B10Obj *o);
void func_00271FD8(Vec3f *o, Vec3f *a, Vec3f *b);
void func_00272088(Vec3f *o, Vec3f *a, Vec3f *b);
void func_002720EC(Vec3f *v);
void func_00272908(B10Mt *m, Vec3f *a, Vec3f *b);
void func_00274108(B10Q4 *o, B10Q4 *a, B10Q4 *b);
void func_002742B4(B10Q4 *q, B10Mt *m);
f32 func_00274640(f32 x);

B10Q4 *func_00247BA4(B10Q4 *out, B10Obj *self, Vec3f dir, B10Q4 *outq, f32 angle) {
    Vec3f v10;
    Vec3f v20;
    Vec3f v30;
    Vec3f v40;
    Vec3f v50;
    Vec3f v60;
    B10Q4 q70;
    B10Q4 q80;
    B10Q4 q90;
    B10Mt mA0;
    B10Obj *best;
    B10Obj *obj;
    s32 i;
    s32 n;
    f32 thr;
    f32 d;
    f32 t;
    f32 s;
    v20.x = 0;
    v20.y = 0;
    v20.z = D_800C8A58;
    func_0024795C(&q70, self);
    if (angle == 0.0f) {
        if (outq) {
            outq->z = 0;
            outq->y = 0;
            outq->x = 0;
            outq->w = D_800C8A58;
        }
        *out = q70;
        return out;
    }
    func_002742B4(&q70, &mA0);
    func_00272908(&mA0, &v20, &v30);
    best = 0;
    thr = cosf(angle * D_800C8A5C);
    n = D_80120CD8;
    for (i = 0; i < n; i++) {
        obj = D_80120AD8[i];
        if (obj == self) {
            continue;
        }
        if (obj->flags100 & 1) {
            continue;
        }
        if (obj->f174 == 0) {
            continue;
        }
        v60 = *(Vec3f *)&obj->u8;
        v60.y = v60.y + obj->f70;
        v60.y = v60.y + func_0024D274(obj) * D_800C8A60;
        func_00271FD8(&v10, &v60, &dir);
        func_002720EC(&v10);
        d = v30.x * v10.x + v30.y * v10.y + v30.z * v10.z;
        if (thr < d) {
            thr = d;
            v50 = v10;
            best = obj;
        }
    }
    if (best) {
        func_00272088(&v40, &v30, &v50);
        func_002720EC(&v40);
        t = func_00274640(thr);
        t = t * trw_sqrtf(trw_sqrtf(D_800C8A68 - t / (angle * D_800C8A64))) * D_800C8A6C;
        s = sinf(t);
        D_80115DEC = s;
        q80.x = v40.x * s;
        q80.y = v40.y * s;
        q80.z = v40.z * s;
        q80.w = cosf(t);
        func_00274108(&q90, &q70, &q80);
        if (outq) {
            *outq = q80;
        }
        *out = q90;
        return out;
    }
    if (outq) {
        outq->x = outq->y = outq->z = 0.0f;
        outq->w = D_800C8A70;
    }
    *out = q70;
    return out;
}
