#include "b19_types.h"
extern u8 D_80121990[];
extern f32 D_800C9F7C;
void func_00271888(B19Vec4 *, B19Vec3 *);
void func_00271FD8(B19Vec3 *, B19Vec3 *, B19Vec3 *);
void func_0027200C(B19Vec3 *, B19Vec3 *, f32);
void func_00271FA4(B19Vec3 *, B19Vec3 *, B19Vec3 *);
void func_00280094(void *, B19Obj *, s32, s32 *, void *, s32, B19Vec3, B19Vec4, B19Vec3, s32, s32, s32);
void func_00284200(B19Obj *o) {
    s32 n = o->parent->info38->n;
    B19Vec4 q;
    B19Vec3 d;
    B19Vec3 p;
    unsigned long idv;
    B19Vec3 v;
    s32 i;
    f32 k;
    u8 *g;
    if (n > 0) {
        v = o->pos2;
        func_00271888(&q, &v);
        g = D_80121990;
        func_00271FD8(&d, &o->pos, (B19Vec3 *)((u8 *)o + 0x168));
        i = 1;
        if (i <= n) {
            k = (f32)n + D_800C9F7C;
            do {
                func_0027200C(&p, &d, (f32)i / k);
                func_00271FA4(&p, &p, (B19Vec3 *)((u8 *)o + 0x168));
                idv = o->id;
                func_00280094(g, o, o->unk12C, o->unk130, o->unk134, idv, v, q, p, 0, -1, 0x20E001);
                i++;
            } while (i <= n);
        }
    }
}
