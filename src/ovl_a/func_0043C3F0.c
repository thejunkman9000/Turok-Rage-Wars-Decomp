#include "o06_types.h"
typedef struct { u8 pad[0x10]; s32 unk10; s32 unk14; s32 unk18; } O06A;
extern void func_0043C4D0(O06A *a, s32 b);
extern void func_0043C4D8(O06A *a, s32 b, s32 c, s32 d);
void func_0043C3F0(O06A *a, s32 b, s32 c, s32 d, s32 e) {
    a->unk10 = 0; a->unk14 = 0; a->unk18 = 0;
    func_0043C4D0(a, b);
    func_0043C4D8(a, c, d, e);
}
