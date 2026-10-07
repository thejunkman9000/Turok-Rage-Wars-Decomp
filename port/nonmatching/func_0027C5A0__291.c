#include "b18_types.h"

extern s32 D_801042C4;
extern Vec3f D_801042B8;
extern Vec3f D_801042C8;
extern u8 D_80121990[];

void func_00265E30(B18Fx *a, B18Fx *b, u16 c, s32 d, Vec3f e, B18Vec2 f);
void func_00271888(B18Vec4 *a, Vec3f *b);
void func_00280094(void *a, B18Fx *b, s32 c, s32 d, s32 e, s32 f, Vec3f g, B18Vec4 h, Vec3f i, s32 j, s32 k, u32 l);
void func_0025DE74(s16 a, Vec3f b, s32 c, s32 d);
void func_00284544(void *a, B18Fx *b);
void func_00284408(B18Fx *a);

void func_0027C5A0(B18Fx *o) {
    B18Vec2 sp50;
    B18Vec4 sp58;
    Vec3f sp68;
    s32 idx;
    s32 s2, s3, v1;
    B18Cfg *c;

    if (D_801042C4 != 7) {
        idx = 1;
        if (D_801042C4 >= 8) {
            if (D_801042C4 == 8) {
                if (o || o->unk130) { idx = 8; } else { idx = 8; }
            }
        }
    } else {
        idx = 7;
    }
    c = o->cfg;
    s2 = c->tab->a70[idx];
    v1 = c->tab->a8C[idx];
    sp50 = c->tab->vec[idx];
    s3 = c->tab->aA8[idx];
    if (v1 != 0xFFFF) {
        func_00265E30(o, o, v1, -1, D_801042B8, sp50);
    }
    if (s2 != 0xFFFF) {
        if (o->cfg->flags & 0x10) {
            sp68 = D_801042C8;
        } else {
            sp68 = o->unk1C;
        }
        func_00271888(&sp58, &sp68);
        func_00280094(D_80121990, o, o->unk12C, o->unk130, o->unk134, s2, sp68, sp58, D_801042B8, 0, -5,
                      (o->flags & 0x200006) | 1);
    }
    if (s3 != 0xFFFF) {
        func_0025DE74(s3, D_801042B8, 0, -1);
    }
    o->flags |= 0x200;
    if (o->cfg->flags & 0x20000) {
        func_00284544(D_80121990, o);
        func_00284408(o);
    }
}