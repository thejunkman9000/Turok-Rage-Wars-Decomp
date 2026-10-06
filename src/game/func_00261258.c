#include "p3_types.h"

typedef struct { f32 v; u8 pad[12]; } P3Slot16;

s32 func_002607D8(void *bits, s32 n);

void func_00261258(void *bits, P3Slot16 *out, s32 n) {
    s32 i;
    for (i = 0; i < n; i++) {
        s32 tmp = func_002607D8(bits, 0x20);
        out[i].v = *(f32 *)&tmp;
    }
}
