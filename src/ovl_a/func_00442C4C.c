#include "o06_types.h"
typedef struct { u8 pad[4]; s16 unk4; u8 pad2[0xE]; s32 *unk14; } O06A;
extern s32 func_0043F290(void);
extern f32 func_00442460(s32 a, f32 b, f32 c);
f32 func_00442C4C(O06A *a, f32 x) {
    s32 o;
    if (a->unk4 == 5) o = func_0043F290(); else o = *a->unk14;
    return func_00442460(o, x, x);
}
