#include "o06_types.h"
typedef struct { u8 pad[0x78]; u8 unk78; u8 unk79; u8 unk7A; u8 unk7B; u8 unk7C; u8 unk7D; u8 unk7E; u8 unk7F; u8 unk80; u8 unk81; u8 unk82; u8 unk83; u8 pad2[0x10]; u8 unk94; u8 unk95; } O06A;
extern void func_00444260(O06A *a);
void func_00444204(O06A *a, u8 b) {
    a->unk79 = 0x86; a->unk7A = 0x84; a->unk78 = 0; a->unk7C = 0; a->unk7B = 0; a->unk7D = 1; a->unk7E = 0;
    a->unk7F = b; a->unk80 = 0; a->unk82 = 0; a->unk83 = 0; a->unk81 = 0; a->unk94 = 0; a->unk95 = 0;
    func_00444260(a);
}
