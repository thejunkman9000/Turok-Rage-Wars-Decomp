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

void func_002A8A94(ScriptCtx *);

void func_002AB6FC(ScriptCtx *c, s32 *pc) {
    c->pc = pc;
    c->state = 2;
    func_002A8A94(c);
}
