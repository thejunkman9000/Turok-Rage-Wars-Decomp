#include "o06_types.h"
typedef struct { u8 pad[0x698]; s32 unk698; } O06B;
typedef struct { u8 pad[0x1C]; O06B *unk1C; } O06A;
extern void func_0022A590(void *a, void *b);
extern void func_00409814(void);
extern void func_004426E4(void *a, void *b, void *c, s32 d, s32 e);
extern u8 D_80145040[];
extern u8 D_0044F0DC[];
s32 func_00443804(s32 a, O06A *b) {
    O06B *p = b->unk1C;
    func_0022A590(D_80145040, p);
    func_00409814();
    func_004426E4(D_80145040 + 0x5DC, D_0044F0DC, p, p->unk698, 0);
    return 1;
}
