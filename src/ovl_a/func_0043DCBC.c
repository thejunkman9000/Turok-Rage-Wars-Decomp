/* # real entry 0x43DCC0 (word at 0x43DCBC is stray padding); verified at ROM 0x1ABCC0 */
#include "o06_types.h"
typedef struct { u8 pad[0x1C]; s32 unk1C; } O06A;
extern void func_0044A37C(s32 a);
s32 func_0043DCBC(s32 a, O06A *b) { func_0044A37C(b->unk1C); return 1; }
