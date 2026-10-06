#include "b05_types.h"

typedef struct B05Def7 { u8 pad0[0x1C]; f32 unk1C; } B05Def7;
typedef struct B05Src7 {
    u8 pad0[0x18];
    B05Def7 *def;
    u8 pad1C[0x1C];
    u32 flags38;
} B05Src7;
typedef struct B05Sta7 { u8 pad0[0x93]; u8 unk93; } B05Sta7;
typedef struct B05P7 {
    u8 pad0[0x5D8];
    B05Sta7 *stats;
    u8 pad5DC[0x74];
    u16 state;
    u8 pad652[0x132];
    f32 f784;
    u8 pad788[0xCC8];
    s32 unk1450;
} B05P7;
typedef struct B05X7 {
    u8 pad0[0x30];
    f32 unk30;
    u8 pad34[0x1E];
    u16 unk52;
} B05X7;
typedef struct B05Cfg7 {
    u8 pad0[0x1D];
    u8 unk1D;
    u8 pad1E[2];
    f32 unk20;
} B05Cfg7;

extern f32 D_800C7938;
extern f32 D_800C793C;
extern f32 D_800C7940;
extern f32 D_800C7944;
extern f32 D_800C7948;
extern B05Cfg7 D_801462C8[];

s32 func_0024E61C(B05Src7 *);

void func_002228E4(B05P7 *p, B05Src7 *s, B05X7 *x) {
    f32 v;

    if (p->state < 2) {
        p->f784 = D_800C7938;
        return;
    }
    v = s->def->unk1C;
    p->f784 = v;
    if (p->unk1450 != 0) {
        switch (p->stats->unk93) {
        case 2:
            break;
        default:
            p->stats->unk93 = 0;
        case 0:
            p->f784 = p->f784 * D_800C793C;
            break;
        case 1:
            p->f784 = v * D_800C7940;
            break;
        }
        if (p->unk1450 != 0) {
            switch (p->stats->unk93) {
            case 2:
                break;
            default:
                p->stats->unk93 = 0;
            case 0:
                p->f784 = p->f784 * D_800C7944;
                break;
            case 1:
                p->f784 = p->f784 * D_800C7948;
                break;
            }
        }
    }
    if (D_801462C8->unk1D != 0) {
        p->f784 = p->f784 * D_801462C8->unk20;
    }
    if (!(s->flags38 & 3) && x != NULL && (func_0024E61C(s) != 0 || (x->unk52 & 0x800))) {
        p->f784 = p->f784 * x->unk30;
    }
}
