#include "o06_types.h"
struct O06A;
typedef struct { u8 pad[0xC]; void (*unkC)(struct O06A *); } O06V;
typedef struct { u8 pad[0xB0]; s32 unkB0; s32 unkB4; s32 unkB8; s32 unkBC; } O06B;
typedef struct O06A { u8 pad[0x14]; O06V *unk14; u8 pad2[8]; O06B *unk20; } O06A;
void func_00443354(O06A *a) {
    O06B *p;
    if (a->unk14->unkC) a->unk14->unkC(a);
    p = a->unk20;
    p->unkB0 = 0; p->unkB4 = 0; p->unkBC = 0;
}
