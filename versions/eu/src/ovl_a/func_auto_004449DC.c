#include "o06_types.h"
typedef struct { u8 pad[0x10]; s32 *unk10; } O06X;
typedef struct { u8 pad[0x14]; s32 *unk14; O06X *unk18; } O06A;
typedef struct { u8 pad[0x1C]; s32 unk1C; } O06B;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x96 - 8]; } O06R;
extern s32 func_0022A590(void *a, s32 b);
extern s32 func_auto_00442EE0(O06A *a);
extern void func_00265904(s32 a, void *b, s32 c);
extern u8 D_auto_80150F80[];
extern O06R D_auto_801522D8[];
extern u8 D_auto_800EED80[];
s32 func_auto_004449DC(O06A *a, O06B *b) {
    s32 n = func_0022A590(D_auto_80150F80, b->unk1C);
    s32 h = D_auto_801522D8[n].unk6;
    s32 s = a->unk14[D_auto_80150F80[0x1809]];
    func_00265904(s - 4 + func_auto_00442EE0(a), D_auto_800EED80, h);
    return 0;
}
