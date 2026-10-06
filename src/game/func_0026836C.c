#include "b15_types.h"

void func_00216288(B15Src *a, s32 b, Vec3f pos, s32 d);

void func_0026836C(B15Src *act, B15Src *src, s32 c, Vec3f pos, B15Pair k) {
    switch (src->type) {
    case 0:
        if (*((s8 *)act + 1) != k.b) {
            return;
        }
        break;
    case 1:
        if ((src->unk17C & (1 << k.b)) == 0) {
            return;
        }
        break;
    }
    func_00216288(act, k.a, pos, 0);
}
