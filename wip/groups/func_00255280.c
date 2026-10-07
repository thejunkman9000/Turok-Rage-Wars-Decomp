#include "b12_types.h"

extern u32 D_800D0930;
extern u32 D_800D0934;
extern u32 D_80105190;
extern u32 D_80105198;
extern B12Bucket *D_80105194;
extern u8 D_801051A0[];
B12Bucket *func_002558C0(void *heap, u32 size);

inline u32 func_002554E0(u32 n) {
    s32 bits = 0;
    s32 hi = 0;
    s32 i;
    for (i = 0; i < 32; i++) {
        if (n & (1 << i)) {
            bits++;
            hi = i;
        }
    }
    if (bits != 1) {
        hi++;
    }
    return 1 << hi;
}

void func_00255280(u32 n) {
    u32 p = func_002554E0(n);
    s32 i;
    D_800D0934 = p * 2;
    D_800D0930 = p;
    D_80105190 = p * 2 - 2;
    D_80105198 = p * 2 - 1;
    D_80105194 = func_002558C0(D_801051A0, p << 5);
    for (i = 0; i < D_800D0934; i++) {
        D_80105194[i].unk4 = 0;
        D_80105194[i].unk0 = 0;
        D_80105194[i].next = 0;
        D_80105194[i].id = i;
    }
}
