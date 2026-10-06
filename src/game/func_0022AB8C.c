#include "b06_types.h"
extern u8 *D_800D052C[];
extern s16 D_800D0588[];
s32 func_0022AB8C(u8 *a) {
    u8 *t = D_800D052C[B6F(a, s16, 0x62E)];
    s16 *p = B6F(a, s32, 0x594) == 1 ? B6F(t, s16 *, 0x20) : B6F(t, s16 *, 0x24);
    s32 idx = -1;
    if (p != NULL) {
        idx = *p;
    }
    if (idx != -1) {
        return D_800D0588[idx];
    }
    return -1;
}
