#include "b14_types.h"
typedef struct { u8 pad[8]; s16 count; } B14Curve;
void *func_002604BC(void *p);
u8 *func_0028FD94(void *tree, s16 id);
f32 func_00273F54(f32 t, f32 a, f32 b);
extern f32 D_800C9348;
f32 func_00262610(B14Curve *c, f32 t) {
    s16 *tbl = (s16 *)(func_0028FD94(func_002604BC(c), 0) + 8);
    s32 last = c->count - 1;
    s32 i = (s32)t;
    s32 j = i + 1;
    if (j < last) {
        last = j;
    }
    return func_00273F54(t - (f32)i, tbl[i] * D_800C9348, tbl[last] * D_800C9348);
}
