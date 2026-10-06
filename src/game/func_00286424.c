#include "b19_types.h"
extern B19Dl *D_80110634;
extern const f32 D_800CA1EC;
void *func_002390C0(B19Vec3 *, void *);
void func_00285290(void *, s32, s32, s32 (*)(), void (*)());
s32 func_0028E020();
void func_0028DFC0();
void func_0026D980();
void func_0026D9D0();
void func_00250A44(B19Draw *, void *);
void func_00249E18(B19Draw *, void *);
void func_0024EB80(B19Draw *);
void func_00286424(B19Owner *ow, void *cam) {
    B19Sort list[0x800];
    B19Vec3 v;
    B19Dl *d;
    s32 n;
    s32 i;
    f32 sx, sy, sz;
    f32 x, y, z;
    B19Draw *o;

    if (ow->f124 != 0) {
        { B19Dl **pp = &D_80110634; B19Dl *q = (*pp)++; q->w0 = 0xDE000000; q->w1 = ow->f124; }
    }
    n = ow->ndraw;
    if (n != 0) {
        { B19Dl **pp = &D_80110634; B19Dl *q = (*pp)++; q->w0 = 0xDB040004; q->w1 = 1; }
        { B19Dl **pp = &D_80110634; B19Dl *q = (*pp)++; q->w0 = 0xDB04000C; q->w1 = 1; }
        { B19Dl **pp = &D_80110634; B19Dl *q = (*pp)++; q->w0 = 0xDB040014; q->w1 = 0xFFFF; }
        { B19Dl **pp = &D_80110634; B19Dl *q = (*pp)++; q->w0 = 0xDB04001C; q->w1 = 0xFFFF; }
        func_002390C0(&v, cam);
        sx = v.x * D_800CA1EC;
        func_002390C0(&v, cam);
        sy = v.y * D_800CA1EC;
        func_002390C0(&v, cam);
        sz = v.z * D_800CA1EC;
        for (i = 0; i < n; i++) {
            o = ow->draw[i];
            { s32 t = o->type;
            if (t == 1) goto bb;
            if (t > 1) goto bb;
            if (t != 0) goto bb;
                x = o->aB8 + o->aC4 + sx;
                y = o->aBC + o->aC8 + sy;
                z = o->aC0 + o->aCC + sz;
            goto jn;
            bb:
                x = o->a8 + o->a8 + sx;
                y = o->aC + o->aC + sy;
                z = o->a10 + o->a10 + sz;
            jn:; }
            list[i].obj = (u8 *)o;
            list[i].key = x * x + y * y + z * z;
        }
        func_00285290(list, n, 8, func_0028E020, func_0028DFC0);
        func_0026D980();
        for (i = 0; i < n; i++) {
            o = (B19Draw *)list[i].obj;
            switch (o->type) {
            case 0:
                func_00250A44(o, cam);
                break;
            case 3:
                func_0024EB80(o);
                break;
            case 1:
                func_00249E18(o, cam);
                break;
            }
        }
        func_0026D9D0();
    }
}
