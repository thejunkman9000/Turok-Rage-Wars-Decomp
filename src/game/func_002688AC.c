#include "b15_types.h"

void func_00217388(B15Src *src, void *p);

void func_002688AC(s32 a, B15Src *src, s32 c, Vec3f pos) {
    if (src != NULL && src->type == 1) {
        func_00217388(src, (u8 *)src + 0x170);
    }
}
