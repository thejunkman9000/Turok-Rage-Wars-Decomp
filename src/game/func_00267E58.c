#include "b15_types.h"

void func_002394AC(void *obj, f32 a, f32 b, f32 c, f32 d, s32 e, Vec3f pos);
extern u8 D_80145088[];
extern f32 D_800C9548;

void func_00267E58(s32 a, s32 b, s32 c, Vec3f pos, B15S16x4 r) {
    func_002394AC(D_80145088, r.a, r.b, r.c, r.d * D_800C9548, 0, pos);
}
