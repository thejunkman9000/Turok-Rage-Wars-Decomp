#include "o06_types.h"
typedef struct { u8 pad[0x20]; u8 *unk20; } O06A;
u8 *func_00442384(O06A *a) { u8 *p = a->unk20; u8 *r = 0; if (p) r = p + 0x190; return r; }
