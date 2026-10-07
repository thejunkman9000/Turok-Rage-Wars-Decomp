#include "o06_types.h"
typedef struct { u8 pad[0x20]; void *unk20; } O06A;
extern s32 func_002643A8(void *a);
extern s32 func_002643C0(void *a);
extern s32 func_0026439C(void *a);
s32 func_0044252C(O06A *a, s32 cur, s32 step, s32 lo, s32 hi, s32 wrap) {
    if (func_002643A8(a->unk20)) cur -= step;
    if (func_002643C0(a->unk20) || func_0026439C(a->unk20)) cur += step;
    if (cur < lo) { if (wrap) cur = hi; else cur = lo; }
    else if (cur > hi) { if (wrap) cur = lo; else cur = hi; }
    return cur;
}
