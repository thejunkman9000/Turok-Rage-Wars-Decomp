#include "o06_types.h"
typedef struct { u8 pad[0x17]; u8 unk17; } O06A;
extern void func_0043FFAC(O06A *a, s32 b, s32 c, s32 d, u8 *e, s32 f);
void func_00442224(O06A *a, s32 b, s32 c, s32 d) { u8 buf[2]; buf[0] = a->unk17; buf[1] = 0; func_0043FFAC(a, b, c, d, buf, 0); }
