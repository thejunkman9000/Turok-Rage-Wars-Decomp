#include "o06_types.h"
typedef struct { u8 pad[0x10]; s32 unk10; } O06O;
extern s32 func_0044252C(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern O06O D_801462C8[];
s32 func_00444EC0(s32 a, s32 b) { D_801462C8->unk10 = func_0044252C(b, D_801462C8->unk10, 0x10, 0, 0x80, 0); return 0; }
