#include "b05_types.h"

typedef struct B05Obj4 {
    u8 type;
    u8 pad1[0x17];
    s32 *ptr18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    u8 pad28[0x148];
    s32 unk170;
    s32 unk174;
    u8 pad178[0x2C];
    s8 unk1A4;
    s8 unk1A5;
} B05Obj4;

typedef struct B05Obj4b {
    u8 pad0[0x1A4];
    s8 unk1A4;
} B05Obj4b;

typedef struct B05Ply4 {
    u8 pad0[0x5DC];
    void *pawn;
    u8 pad5E0[0x84];
    u32 flags664;
    u8 pad668[0x58];
    f32 unk6C0;
    u8 pad6C4[0x148];
    B05Obj4b *unk80C;
} B05Ply4;

typedef struct B05Src4 {
    u8 pad0[8];
    Vec3f pos;
    u8 pad14[0x58];
    f32 unk6C;
} B05Src4;

extern B05Obj4 *D_801041F0;
extern const f32 D_800C7950;
extern const f32 D_800C7954;
extern f32 D_800C7958;
extern f32 D_800C795C;
extern f32 D_800C7960;
extern f32 D_800C7964;
extern f32 D_800C7968;

f32 sinf(f32);
f32 cosf(f32);
void func_00214178(void *, void *, s32);
void func_00239314(void *, f32, f32, f32, f32, s32, Vec3f);

s32 func_00222FBC(B05Ply4 *p, B05Src4 *src) {
    B05Obj4 *o;
    B05Obj4b *o2;
    s32 s2;
    s32 t;

    o = D_801041F0;
    if (p->flags664 & 0x8000) {
        if (o == NULL) {
            return 0;
        }
        o2 = p->unk80C;
        if (o != (B05Obj4 *)o2) {
            t = o->type;
            if (t != 1) {
                return 0;
            }
            s2 = *o->ptr18;
            if (s2 != t) {
                return 0;
            }
            if (o2 == NULL) {
                return 0;
            }
            if (o->unk174 != 0) {
                o->unk1C = p->unk6C0 * sinf(src->unk6C + D_800C7950) * D_800C7954;
                o->unk20 = p->unk6C0 * D_800C7958;
                o->unk24 = p->unk6C0 * cosf(src->unk6C + D_800C7950) * D_800C7954;
                if (p->pawn != NULL) {
                    func_00239314(p->pawn, D_800C7960, 100.0f, D_800C7960, D_800C795C, s2, src->pos);
                }
                if (o2->unk1A4 == 0x2E) {
                    o->unk170 |= 0x200;
                }
                o->unk1A5 = -1;
                func_00214178(o, (u8 *)o + 0x170, 0x34);
                return 1;
            }
            if (p->pawn != NULL) {
                func_00239314(p->pawn, D_800C7968, 60.0f, D_800C7968, D_800C7964, s2, src->pos);
            }
            return 1;
        }
    }
    return 0;
}
