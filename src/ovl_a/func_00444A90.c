#include "o06_types.h"
extern s32 func_0044252C(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
typedef struct { u16 unk0; u8 unk2; } O06D;
extern O06D D_801462DC[];
s32 func_00444A90(s32 a, s32 b) { u8 x;
 D_801462DC->unk0 = func_0044252C(b, D_801462DC->unk0, 0x10, 0, 0x100, 0);
 x = 0xFF; if (D_801462DC->unk0 < 0xFF) x = D_801462DC->unk0; D_801462DC->unk2 = x;
 return 0; }
