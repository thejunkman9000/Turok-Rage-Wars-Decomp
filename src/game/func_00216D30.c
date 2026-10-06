#include "b04_types.h"
typedef struct { u8 pad[0x78]; s32 a; s32 b; } B04Q;
void func_00216D30(void *x, B04Q *q, s32 a, s32 b) {
    q->a = a; q->b = b;
}
