#include "b24_types.h"

extern f32 D_800CB03C;
extern f32 D_800CB040;
extern f32 D_800CB044;

void func_002A7058(Emit *e, Emit *e2, EmitOut *o) {
    f32 t;
    o->unk4 = (s32)&e->def->unk24;
    o->unk0 = e->def->unk23;
    if (e->flags & 2) {
        o->unk8 = e->unkC;
        o->unkC = e->unk10;
    } else {
        o->unk8 = e->unkC;
        o->unkC = e->unkC;
    }
    o->unk10 = e->def->unk21 * D_800CB03C;
    o->unk14 = e->def->unk22 * D_800CB03C;
    if (e2 != NULL) {
        t = 1 << (e2->def->unk2 + 5);
        o->unk18 = t;
        o->unk18 = t * e->def->unk1D - D_800CB040;
        o->unk1C = 1 << (e2->def->unk3 + 5);
        o->unk20 = D_800CB044 / (o->unk0 - D_800CB044);
    }
}
