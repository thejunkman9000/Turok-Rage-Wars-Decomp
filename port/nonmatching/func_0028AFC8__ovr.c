/* port (passthru_fix.py): func_0028FD94 needs a1 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "common.h"

typedef struct { u8 pad0[0x70]; s32 *unk70; } Obj;
void *func_0028FD94();

void func_0028AFC8(Obj *o, u32 pt_a1) {
    func_0028FD94(o->unk70, pt_a1);
}
