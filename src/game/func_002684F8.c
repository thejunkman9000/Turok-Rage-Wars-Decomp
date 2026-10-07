#include "b15_types.h"

typedef struct B15Flags {
    u8 type;
    u8 pad1[0x2DF];
    u32 unk2E0;
} B15Flags;

void func_002684F8(B15Flags *a, s32 b, s32 c, Vec3f pos, s32 bit) {
    if (a->type == 1) {
        a->unk2E0 &= ~(1 << bit);
    }
}
