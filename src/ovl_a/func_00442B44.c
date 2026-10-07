#include "o06_types.h"
struct O06N;
typedef struct { u8 pad[0x10]; void (*unk10)(struct O06N *, void *); } O06V;
typedef struct O06N { u8 pad[0x14]; O06V *unk14; u8 pad2[0x1D0 - 0x18]; struct O06N *unk1D0; } O06N;
typedef struct { u8 pad[4]; O06N *unk4; } O06A;
void func_00442B44(O06A *a) { O06N *n; for (n = a->unk4; n != 0; n = n->unk1D0) n->unk14->unk10(n, a); }
