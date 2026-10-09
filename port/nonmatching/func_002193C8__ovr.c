/* port (passthru_fix.py): func_0028D268 needs a1 a2 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "b04_types.h"
extern u8 D_8011FE88[];
s32 func_0028D268(u8 *, u32, u32);
typedef struct { u8 unk0; u8 unk1; s16 unk2; s16 unk4; } B04Ev;
void func_002193C8(B04Ev *e, s32 a, u32 pt_a2) {
    e->unk0 = 1;
    e->unk1 = a;
    e->unk2 = func_0028D268(D_8011FE88, a, pt_a2);
    e->unk4 = 0;
}
