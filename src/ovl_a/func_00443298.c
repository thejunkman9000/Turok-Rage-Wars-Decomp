#include "o06_types.h"
typedef struct { u32 w[6]; } O06Seg;
typedef struct { u8 pad[0x140]; O06Seg seg[1]; } O06A;
typedef struct { f32 f0; s32 unk4; s32 unk8; f32 fC; s32 unk10; } O06Cam;
extern s32 D_800D15E0;
extern O06Cam D_800D15E4[];
extern O06Seg D_800D0EF8;
extern s32 D_800D297C;
extern s32 D_801540E0;
extern void func_0024A1C0(void *a, s32 b, s32 c);
void func_00443298(O06A *a, s32 b, s32 c) {
 D_800D15E0 = 3;
 a->seg[D_800D297C] = D_800D0EF8;
 D_800D15E4->f0 = 255.0f;
 D_800D15E4->unk4 = 0;
 D_800D15E4->unk8 = 0;
 D_800D15E4->unk10 = 0;
 D_800D15E4->fC = (f32)(D_801540E0 / 2);
 func_0024A1C0(a, b, c);
 D_800D15E0 = 0;
}
