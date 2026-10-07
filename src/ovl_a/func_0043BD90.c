#include "o06_types.h"
typedef struct { u8 pad[0x4B0]; s32 unk4B0; s32 unk4B4; s32 unk4B8[6]; } O06P;
extern void func_0029A73C(void);
extern void func_0043B8C8(s32 a);
extern void func_0043B67C(s32 a, s32 b, s32 c);
extern void func_0025DF54(s32 a);
extern O06P *D_800E59E0;
s32 func_0043BD90(s32 a, s32 b, s32 c, s32 d) {
    s32 i = c & 0xFFFF;
    s32 k;
    O06P *p0 = &D_800E59E0[i];
    if (p0->unk4B0 != 1) return 0;
    if ((u32)c >> 16 != 3) return 0;
    if (d != 0) return 0;
    func_0029A73C();
    func_0043B8C8(i);
    for (k = 0; k < 6; k++) func_0043B67C(i, k, *(s32 *)((u8 *)D_800E59E0 + (i * 0x4D0 + k * 4) + 0x4B8));
    { s32 off = i * 0x4D0; s32 c2 = ((O06P *)((u8 *)D_800E59E0 + off))->unk4B4; func_0043B67C(i, c2, *(s32 *)((u8 *)D_800E59E0 + (c2 * 4 + off) + 0x4B8)); }
    func_0025DF54(0xE7C);
    return 0;
}
