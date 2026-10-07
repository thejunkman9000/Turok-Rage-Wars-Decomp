#include "b15_types.h"

typedef struct B15Eff {
    u8 pad0[0x68];
    f32 unk68;
} B15Eff;

typedef struct B15Slot {
    void *owner;
    u8 pad4[0x10];
    s32 unk14;
    B15Eff eff;
} B15Slot;

typedef struct B15Act2 {
    u8 type;
    u8 pad1[3];
    u16 unk4;
    u8 pad6[2];
    Vec3f pos;
    u8 pad14[0xEC];
    u32 flags;
    u8 pad104[0xD4];
    u8 *owner;
    u8 pad1DC[0x94];
    f32 unk270;
} B15Act2;

s32 func_0024B05C(B15Act2 *a, Vec3f pos, B15Eff *eff);
f32 func_0024D274(B15Act2 *a);
f32 func_0024D388(B15Act2 *a);
f32 func_00272768(Vec3f *a, Vec3f *b);
extern f32 D_800C952C;
extern f32 D_800C9530;
extern f32 D_800C9534;
extern B15Slot D_801041F0;
extern B15Eff D_80110570;
extern u8 D_801462E5;

f32 func_002676FC(B15Act2 *a, B15Act2 *src, Vec3f pos, f32 f6C, s32 s70, u32 flags, B15Eff **out) {
    s32 s2;
    s32 s3;
    s32 s6;
    s32 s4;
    s32 isFx;
    B15Eff *e;
    u8 *own;
    f32 vol;
    f32 fs0;
    f32 t;
    f32 dist;
    Vec3f loc;

    s4 = s70;
    isFx = 0;
    s6 = s3 = 1;
    own = NULL;
    vol = D_800C952C;
    if (a->flags & 0x300000) {
        own = a->owner;
    }
    if (D_801462E5 != 0 && (flags & 0x200)) {
        s3 = 0;
    }
    if (src->type == 2) {
        if (src->unk4 == 0x404 || src->unk4 == 0x402) {
            isFx = 1;
        }
        if (src->type == 2 && D_801041F0.owner == a && D_801041F0.unk14 != -1 && (e = &D_801041F0.eff, isFx == 0)) {
            s4 = 0;
            goto have;
        }
    }
    if (func_0024B05C(a, pos, &D_80110570) != 0) {
        e = &D_80110570;
    } else {
        e = NULL;
    }
have:
    *out = e;
    if (s3 != 0 && e != NULL) {
        vol *= e->unk68;
    }
    if (s4 != 0) {
        if (own != NULL && (*(u32 *)(own + 0x122C) & 2) && vol == D_800C9530 && (flags & 0x200)) {
            vol = 0.0f;
        } else {
            loc = a->pos;
            fs0 = a->pos.y + *(f32 *)((u8 *)a + 0x70);
            t = fs0 + func_0024D274(a);
            if (t < pos.y) {
                loc.y = t;
            } else if (pos.y < fs0) {
                loc.y = fs0;
            } else {
                loc.y = pos.y;
            }
            fs0 = f6C + func_0024D388(a);
            dist = func_00272768(&pos, &loc);
            if (fs0 < dist) {
                return 0.0f;
            }
            if (s6 != 0) {
                vol = vol * (D_800C9534 - dist / fs0);
            }
        }
    }
    return vol;
}
