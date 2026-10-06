#include "b24_types.h"

typedef struct ScriptCtx {
    u8 pad0[4];
    s32 *pc;
    s32 state;
    u8 padC[0x30];
    s32 unk3C;
    s32 unk40;
    s32 unk44;
} ScriptCtx;

extern s32 D_800D318C[];
void func_002AB6FC(ScriptCtx *, s32 *);

void func_002AB720(ScriptCtx *c, s32 a, s32 b) {
    c->unk40 = a;
    c->unk3C = b;
    c->unk44 = 100;
    func_002AB6FC(c, D_800D318C);
}
