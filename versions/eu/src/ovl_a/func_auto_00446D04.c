#include "o06_types.h"
typedef struct { s32 unk0; s32 unk4; s32 unk8; u8 unkC[12]; } O06R;
typedef struct { u8 pad[0x14]; u8 **unk14; u8 pad2[4]; s32 unk1C; } O06A;
extern s32 func_0022A590(void *a, s32 b);
extern u8 D_80145040[];
extern O06R D_800E63C0[];
s32 func_auto_00446D04(O06A *a, O06A *b) {
    s32 n = func_0022A590(D_80145040, b->unk1C);
    D_800E63C0[n].unk4 = 0;
    if (D_800E63C0[n].unk8 == 8) return 0;
    D_800E63C0[n].unkC[D_800E63C0[n].unk0] = *a->unk14[D_80145040[0x1809]];
    D_800E63C0[n].unk0++;
    D_800E63C0[n].unk8++;
    D_800E63C0[n].unkC[D_800E63C0[n].unk8] = 0;
    return 0;
}
