#include "b15_types.h"

void func_0024E78C(s32 a, Vec3f pos, s32 *out1, s32 *out2, s32 c, s32 d);
void func_002761F4(s32 a);
void func_00276228(s32 a);

void func_00267278(s32 a, Vec3f pos, s32 flag) {
    s32 buf[4];
    s32 res;

    func_0024E78C(a, pos, buf, &res, 0, 0);
    if (flag != 0) {
        func_002761F4(res);
    } else {
        func_00276228(res);
    }
}
