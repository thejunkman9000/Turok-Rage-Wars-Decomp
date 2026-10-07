#include "o06_types.h"
struct O06A;
typedef struct { u8 pad[0xC]; void (*unkC)(struct O06A *, struct O06A *); } O06V;
typedef struct { u8 pad[0xB0]; s32 unkB0; s32 unkB4; s32 unkB8; s32 unkBC; } O06B;
typedef struct O06A { s32 unk0; u8 pad[4]; s32 unk8; u8 pad2[8]; O06V *unk14; u8 pad3[8]; O06B *unk20; } O06A;
typedef struct O06H { struct O06A *unk0; } O06H;
extern void func_00255E78(O06H *a, O06A *b);
extern void func_002537D8(s32 a, s32 b);
void func_00442BD0(O06H *a) {
 O06A *n; O06B *p;
 top:
 n = a->unk0; if (n == 0) return;
 if (n->unk14->unkC) n->unk14->unkC(n, (O06A *)a);
 p = n->unk20; p->unkB0 = 0; p->unkB4 = 0; p->unkBC = 0;
 func_00255E78(a, n); func_002537D8(0, n->unk8);
 goto top;
}
