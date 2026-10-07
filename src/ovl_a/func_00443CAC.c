#include "o06_types.h"
typedef struct { u8 pad[0x10]; s32 *unk10; } O06X;
typedef struct { u8 pad[0x18]; O06X *unk18; } O06A;
typedef struct { u8 pad[0x1C]; s32 unk1C; } O06B;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x96 - 8]; } O06R;
extern s32 func_0022A590(void *a, s32 b);
extern s32 func_00442158(O06A *a);
extern void func_00265904(s32 a, void *b, s32 c);
extern u8 D_80145040[];
extern O06R D_80146398[];
extern u8 D_800E2730[];
s32 func_00443CAC(O06A *a, O06B *b) {
    s32 n = func_0022A590(D_80145040, b->unk1C);
    s32 h = D_80146398[n].unk0;
    s32 s = *a->unk18->unk10;
    func_00265904(s - 4 + func_00442158(a), D_800E2730, h);
    return 0;
}
