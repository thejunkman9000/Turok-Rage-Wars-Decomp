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

typedef struct ScriptHolder {
    u8 pad0[0x48];
    ScriptCtx s;
} ScriptHolder;

extern s32 D_800D31A0[];
void func_002AB6FC(ScriptCtx *, s32 *);

void func_002AB750(ScriptHolder *h, s32 a, s32 b) {
    h->s.unk40 = a;
    h->s.unk3C = b;
    h->s.unk44 = 100;
    func_002AB6FC(&h->s, D_800D31A0);
}
