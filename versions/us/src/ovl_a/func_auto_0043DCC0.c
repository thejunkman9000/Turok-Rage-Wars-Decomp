/* US v1.0: real entry 0x43DCC0 (ROM 0x1A1CC0; the word at 0x1A1CBC is pad_1A1CBC) = US v1.1 src/ovl_a/func_0043DCBC.c unchanged, renamed */
#include "o06_types.h"
typedef struct { u8 pad[0x1C]; s32 unk1C; } O06A;
extern void func_0044A37C(s32 a);
s32 func_auto_0043DCC0(s32 a, O06A *b) { func_0044A37C(b->unk1C); return 1; }
