#include "o06_types.h"
typedef struct { u8 pad[0x14]; s32 *unk14; } O06A;
extern u8 D_auto_80152789;
extern void func_0043FFAC(O06A *a, s32 b, s32 c, s32 d, s32 e, s32 f);
void func_auto_00442FA4(O06A *a, s32 b, s32 c, s32 d) { func_0043FFAC(a, b, c, d, a->unk14[D_auto_80152789], 0); }
