#include "b03_types.h"

void *memset(void *p, s32 c, u32 n);
void func_002138F0(StateB *s, ActorDef *def, Vec3f pos, SpawnB *sp);
void func_0024B52C();
void func_0024B8DC();
f32 func_00275E44(s32 a, s32 x, s32 z);

void func_00213AAC(SpawnB *sp, StateB *s, void (**cb)(SpawnB *, StateB *)) {
    s32 keep;
    s32 a0;
    f32 k;
    register s32 m1 __asm__("$3");

    keep = s->unk68;
    memset(s, 0, 0x170);
    s->flags = 0x40;
    s->unk68 = keep;
    func_002138F0(s, sp->def, sp->pos, sp);
    s->fn11C = func_0024B52C;
    s->fn10C = func_0024B8DC;
    s->id = -1;
    s->unk35 = -1;
    s->cur = 0;
    s->unk48 = sp->pos;
    s->unk54 = sp->pos;
    s->unk6C = 0;
    s->unk70 = 0;
    s->unk74 = 0;
    s->unk60 = sp->unk6C;
    s->unk64 = 0;
    s->unk78 = 0;
    s->unk7C = 0;
    s->unk80 = 0;
    s->unk84 = 0;
    s->unk88 = 0;
    s->unk8C = sp->unk6C;
    s->unk90 = sp->pos.y;
    s->unk9C = sp->unk6C;
    s->unkA0 = sp->pos;
    s->unkAC = sp->unk14;
    s->unkB0 = sp->pos;
    a0 = sp->unk14;
    s->unkBC = a0;
    if ((FLD(u32, sp->def, 4) & 4) && a0 != 0) {
        s->unkB0.y = func_00275E44(a0, *(s32 *)&s->unkB0.x, *(s32 *)&s->unkB0.z);
    }
    k = 1.0f;
    s->unkCA = -1;
    s->unk13 = 0x14;
    s->unk95 = 0xFF;
    m1 = -1;
    s->unkC8 = m1;
    s->unk35 = m1;
    s->unk14 = m1;
    s->unk15 = m1;
    s->unk16 = m1;
    s->unk17 = m1;
    s->unk102 = m1;
    s->unk96 = m1;
    s->unkCB = 0;
    s->unkD0 = 0;
    s->unkD4 = 0;
    s->unk44 = 0;
    s->unk12 = 0;
    s->unk1C = 0;
    s->unk20 = 0;
    s->unk24 = 0;
    s->unk28 = 0;
    s->unk100 = 0;
    s->unk94 = 0;
    s->unkFC = 0;
    s->unkC0 = k;
    s->unkC4 = k;
    s->flags &= ~1;
    s->unk18 = k;
    if (cb != NULL) {
        if (*cb != NULL) {
            (*cb)(sp, s);
        }
    }
    if (sp->flags & 0x8000000) {
        s->unkCB = 1;
    }
}
