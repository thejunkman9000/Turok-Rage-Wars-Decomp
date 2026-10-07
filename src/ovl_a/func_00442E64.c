#include "o06_types.h"
typedef struct { u8 pad[0x478]; s32 unk478; } O06A;
void func_00442E64(s16 *a, O06A *b) { if (*a == 3) b->unk478 = 1; }
