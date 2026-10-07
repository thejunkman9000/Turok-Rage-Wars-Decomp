#include "b03_types.h"

extern f32 D_800C71F0;
extern f32 D_800C71F4;
extern f64 D_800C71F8;
extern f64 D_800C7200;
extern f32 D_800C7208;
extern f32 D_800C720C;
extern f32 D_800C7210;
extern f32 D_800C7214;
extern s32 D_801462D0;

void func_002138F0(StateB *s, DefC *def, Vec3f pos, SpawnTail *sp) {
    s32 t1 = 0;
    f32 a = D_800C71F0;
    f32 b = D_800C71F4;
    s32 t0 = 0;
    s32 a3 = 0;
    f32 c;
    f32 f;
    s32 v;

    s->unkC = -1;
    s->unk100 = 0;
    s->unk102 = -1;
    c = a;
    if (def != NULL) {
        t1 = def->unk12;
        t0 = def->unkE;
        a3 = def->unk10;
        switch (def->type) {
        case 1:
            v = def->unk18;
            c = (f32)(u32)v;
            a = (f32)def->unk41;
            b = (f32)def->unk40;
            break;
        case 4:
            v = def->unk18;
            c = (f32)(u32)v;
            break;
        case 7:
            c = (f32)FLD(s16, def, 0x18);
            break;
        }
        if (def->type == 1 || def->type == 4) {
            switch (D_801462D0) {
            case 8:
                f = c * D_800C7208;
                b = 0.0f;
                if (f < D_800C720C) {
                    f = D_800C720C;
                }
                c = f;
                break;
            case 0x20:
                b = D_800C7214;
                c = c * D_800C7210;
                break;
            }
        }
    }
    sp->unk3 = t1;
    sp->unk1 = t0;
    sp->unk2 = a3;
    s->unk4 = (s32)c;
    s->unk10 = (s32)a;
    s->unkCC = (s32)b;
    s->unk4 = s->unk4 << 8;
    s->unk8 = s->unk4;
}
