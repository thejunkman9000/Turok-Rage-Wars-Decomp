#include "o06_types.h"
typedef struct { u8 pad[0x80]; u32 unk80; u8 pad2[0x24]; u32 unkA8; } O06B;
typedef struct { s16 unk0; u8 pad[0xA]; O06B *unkC; } O06A;
extern void func_002648E8(O06A *a);
extern s32 func_0025CC8C(void);
extern void func_0025CAD0(s32 a);
extern u8 D_801462E5;
void func_00446264(O06A *a) {
    a->unk0 = 2;
    func_002648E8(a);
    if (D_801462E5) {
        a->unkC->unk80 &= ~0x800000;
        a->unkC->unkA8 &= ~0x800000;
    } else {
        a->unkC->unk80 |= 0x800000;
        a->unkC->unkA8 |= 0x800000;
    }
    func_0025CAD0(func_0025CC8C());
}
