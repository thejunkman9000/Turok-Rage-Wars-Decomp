#include "b19_types.h"
extern u8 D_80121990[];
extern B19Vec3 D_801042C8;
extern B19Q D_80104290[];
void func_00271888(B19Vec4 *, B19Vec3 *);
void func_00280094(void *, B19Obj *, s32, s32 *, void *, s32, B19Vec3, B19Vec4, B19Vec3, s32, s32, s32);
void func_00283454(B19Obj *o, s32 arg) {
    B19Vec4 q;
    B19Vec3 v;
    if (o->parent->flags & 0x10) {
        v = D_801042C8;
    } else {
        v = o->pos2;
    }
    func_00271888(&q, &v);
    func_00280094(D_80121990, o, o->unk12C, o->unk130, o->unk134, arg, v, q, D_80104290->v, 0, D_80104290->k, (o->flags & 0x200006) | 1);
}
