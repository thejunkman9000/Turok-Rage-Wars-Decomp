#include "o06_types.h"
struct O06A;
typedef struct { u8 pad[0xC]; void (*unkC)(struct O06A *, struct O06A *); } O06V;
typedef struct { u8 pad[0xB0]; s32 unkB0; s32 unkB4; s32 unkB8; s32 unkBC; } O06B;
typedef struct O06A { u8 pad[8]; s32 unk8; u8 pad2[8]; O06V *unk14; u8 pad3[8]; O06B *unk20; } O06A;
extern void func_00255E78(O06A *a, O06A *b);
extern void func_002537D8(s32 a, s32 b);
void func_004434BC(O06A *a, O06A *b) {
    O06B *p;
    if (b->unk14->unkC) b->unk14->unkC(b, a);
    p = b->unk20;
    p->unkB0 = 0; p->unkB4 = 0;
    p->unkBC = 0;
    func_00255E78(a, b);
    func_002537D8(0, b->unk8);
}
