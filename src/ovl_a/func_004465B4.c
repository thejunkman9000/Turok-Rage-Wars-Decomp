#include "o06_types.h"
typedef struct { s32 unk0; f32 unk4; s32 unk8; u8 pad[12]; } O06R;
typedef struct { s16 unk0; u8 pad[0x1E]; void *unk20; } O06A2;
typedef struct { u8 pad[0x1C]; s32 unk1C; } O06B;
extern s32 func_0022A590(void *a, s32 b);
extern s32 func_002643A8(void *a);
extern s32 func_002643C0(void *a);
extern u8 D_80145040[];
extern O06R D_800E63C0[];
extern f32 D_800D2988;
extern f32 D_800E2810;
s32 func_004465B4(s32 a, O06A2 *b) {
    s32 n = func_0022A590(D_80145040, *(s32 *)((u8 *)b + 0x1C));
    f32 v = D_800E63C0[n].unk4 + D_800D2988;
    D_800E63C0[n].unk4 = v;
    if (D_800E2810 <= v) D_800E63C0[n].unk4 = v - D_800E2810;
    if (b->unk0 == 1) {
        if (func_002643A8(b->unk20) && D_800E63C0[n].unk0 > 0) {
            D_800E63C0[n].unk0--;
            D_800E63C0[n].unk4 = 0;
        } else if (func_002643C0(b->unk20) && D_800E63C0[n].unk0 < D_800E63C0[n].unk8) {
            D_800E63C0[n].unk0++;
            D_800E63C0[n].unk4 = 0;
        }
    }
    return 0;
}
