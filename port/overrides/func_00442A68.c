/* port (passthru_fix.py): func_00441384 needs a2 a3 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "o06_types.h"
struct O06N;
typedef struct { u8 pad[0xC]; void (*unkC)(struct O06N *, void *); } O06V;
typedef struct { u8 pad[0xB0]; s32 unkB0; s32 unkB4; s32 unkB8; s32 unkBC; } O06B;
typedef struct O06N { u8 pad[8]; s32 unk8; u8 pad2[8]; O06V *unk14; u8 pad3[8]; O06B *unk20; u8 pad3b[4]; s16 unk28; u8 pad4[0x1D4 - 0x2A]; struct O06N *unk1D4; } O06N;
typedef struct { O06N *unk0; u8 pad[0xC]; s32 unk10; } O06H;
extern s32 func_00441384(O06N *n, O06H *h, u32, u32);
extern void func_00255E78(O06H *a, O06N *b);
extern void func_002537D8(s32 a, s32 b);
extern O06H D_8014561C;
void func_00442A68(O06H *a, u32 pt_a1, u32 pt_a2, u32 pt_a3) {
    O06N *n, *next;
    O06B *p;
    for (n = a->unk0; n != 0; n = next) {
        next = n->unk1D4;
        if (n->unk28 == 2 && a != &D_8014561C && D_8014561C.unk10 != 0) continue;
        if (func_00441384(n, a, pt_a2, pt_a3) == 0) continue;
        if (n->unk14->unkC) n->unk14->unkC(n, a);
        p = n->unk20;
        p->unkB0 = 0; p->unkB4 = 0;
        p->unkBC = 0;
        func_00255E78(a, n);
        func_002537D8(0, n->unk8);
    }
}
