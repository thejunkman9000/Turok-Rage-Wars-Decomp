#include "p1_types.h"
void func_002174E4(VecSrc *src, s32 unused, VecDst *dst) {
    Vec3f a;
    Vec3f b;
    a = src->v;
    b.x = 0;
    b.y = 0;
    b.z = 0;
    dst->unk0 = 3;
    dst->unk4 = 0;
    dst->unk8 = 0;
    dst->a = a;
    dst->b = b;
    dst->unk24 = 0;
    b.y = 0;
    a.y = 0;
    dst->c = a;
    dst->d = b;
    dst->unk40 = 0;
}
