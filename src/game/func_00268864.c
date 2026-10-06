#include "p3_types.h"

extern s32 D_80146894;
void func_002172D0(u8 *obj, void *p, s32 a);

/* NOTE: the dead `k = 0` store is what makes gcc load the stack arg at function entry */
void func_00268864(s32 a, u8 *obj, s32 c, P3Vec3 v, s32 e) {
    s32 k = e;
    if (D_80146894 == 0 && obj != NULL && *obj == 1) {
        func_002172D0(obj, obj + 0x170, k);
    }
    k = 0;
}
