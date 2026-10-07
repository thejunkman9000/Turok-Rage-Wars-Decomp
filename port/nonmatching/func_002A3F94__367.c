#include "b23_types.h"

typedef struct Owner3F94 {
    u8 pad0[0x100];
    u32 flags;
} Owner3F94;

extern f32 D_800D2988;
extern f32 D_800D298C;
extern f32 D_800D2990;

void func_002A6770(s32 a, SSlot *s, SEnt *e);
void func_002A6FE0(SSlot *s);

s32 func_002A3F94(s32 a0, SSlot *s) {
    f32 saved, k1, k2;
    SEnt *e, *next;
    Owner3F94 *ow;
    s32 r;

    saved = D_800D2988;
    if (s->flags & 2) {
        D_800D2988 = saved * D_800D2990;
    }
    if (s->flags & 1) {
        D_800D2988 = D_800D2988 * D_800D298C;
    }
    if (s->flags & 8) {
        s->unk50 = s->unk50 + 1;
        if (s->unk50 >= 3) {
            s->owner = 0;
        }
    }
    if (s->unk2C >= 0.0f) {
        s->unk30 = s->unk30 + D_800D2988;
    }
    s->unk24 = s->unk24 - D_800D2988;
    if (s->unk24 < 0.0f) {
        s->unk24 = 0.0f;
    }
    e = s->list;
    if (e != 0) {
        k1 = 1.0f;
        k2 = -3.0f;
        do {
            next = e->next;
            if (s->unk24 <= 0.0f && e->unk8 > 0.0f) {
                e->unk8 = 0.0f;
            }
            if (e->unk8 <= 0.0f) {
                e->unk8 = e->unk8 - k1;
                if (e->unk8 < k2) {
                    func_002A6770(a0, s, e);
                }
            } else {
                e->unk8 = e->unk8 - D_800D2988;
                if (e->unk8 < 0.0f) {
                    e->unk8 = 0.0f;
                }
            }
            e = next;
        } while (e != 0);
    }
    ow = (Owner3F94 *)s->owner;
    if (ow != 0 && (s->flags & 1) && !(ow->flags & 0x200)) {
        func_002A6FE0(s);
    }
    D_800D2988 = saved;
    if (s->unk48 != 0) {
        return 1;
    }
    if (s->unk24 != 0.0f) {
        if (s->owner != 0) {
            return 1;
        }
    }
    return 0;
}

