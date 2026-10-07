#include "b06_types.h"

void func_00216488(f32 *out, s32 a, s32 b, f32 c, s32 d, s32 e);
void func_00219A40(Plr *a, u8 *b, f32 *c);
extern f32 D_800D2988;
extern u32 D_801462C8;

void func_0022B8D0(Plr *a) {
    f32 buf[6];
    f32 n;
    if (a->unk11E4 > 0.0f) {
        n = a->unk11E4 - D_800D2988;
        a->unk11E4 = n;
        if (n <= 0.0f && !(D_801462C8 & 1)) {
            func_00216488(buf, a->unk13E0, a->unk174 + 0x1900, 25.599998f, 0x4000, 0);
            func_00219A40(a, (u8 *)a + 0x170, buf);
        }
    }
}
