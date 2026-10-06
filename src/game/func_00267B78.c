#include "p3_types.h"

void func_00266830(void *a, void *b, s32 c, P3Vec3 v, P3S8 s, s32 d, s32 e, s32 f);

void func_00267B78(u8 *a, void *b, s32 c, P3Vec3 v, P3S8 s) {
    if (*a == 1) {
        func_00266830(a, b, c, v, s, 0, 0, 0x80);
    }
}
