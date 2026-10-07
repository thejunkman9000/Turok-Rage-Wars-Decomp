#include "b15_types.h"

typedef struct B15U8 {
    u8 pad[0x270];
    u8 unk270;
} B15U8;

void func_002689BC(B15U8 *a, s32 b, s32 c, Vec3f pos, B15Bytes7 col) {
    a->unk270 = col.c[3];
}
