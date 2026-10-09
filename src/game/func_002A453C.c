

#include "b23_types.h"

typedef struct Inner14b {
    u8 pad0[0x14];
    s32 unk14;
} Inner14b;

typedef struct Actor453C {
    u8 pad0[0x118];
    Inner14b *unk118;
} Actor453C;

extern f32 D_800CAF80;
extern f32 D_800CAF84;
extern s32 D_800D297C;

void func_002702EC(void *src, void *dst);
void func_00270980(void *m, void *src);
void func_00271FD8(Vec3f *out, void *a, void *b);
void func_00272898(void *m);
void func_00273340(void *src, void *dst);
void func_0027335C(void *src, void *dst);
void func_002734EC(void *m, f32 a, f32 b, f32 c);

static inline void Attach453C(SSlot *slot, SEnt *e, Actor453C *act) {
    u8 m[0x40];
    f32 k;
    func_00270980(m, (u8 *)act + ((D_800D297C << 6) + 0x60));
    k = D_800CAF80;
    if (act->unk118->unk14 != 0) {
        k = D_800CAF84;
    }
    func_002734EC(m, k, k, k);
    func_00272898(m);
    func_00273340(m, e->m10);
    if (slot->flags & 4) {
        func_0027335C(m, e->m1C);
    } else {
        func_002702EC(m, e->m28[D_800D297C]);
    }
}

void func_002A453C(SSlot *slot) {
    Vec3f v;
    SEnt *e, *pv;
    Actor453C *act;
    s32 changed;
    f32 k, d;
    u8 *dst, *src, *t;

    do {
    e = slot->list;
    changed = 0;
    slot->unk4C = 0.0f;
    if (e == 0) {
        goto done;
    }
loop:
    {
        {
            act = (Actor453C *)e->unkB0;
            if (act != 0) {
                if (act == (Actor453C *)-1) {
                    dst = (u8 *)e + (D_800D297C << 6) + 0x28;
                    t = (u8 *)e + ((D_800D297C ^ 1) << 6);
                    src = t + 0x28;
                    do {
                        *(Blk16 *)dst = *(Blk16 *)src;
                        src += 0x10;
                        dst += 0x10;
                    } while (src != t + 0x68);
                    e->unkB0 = 0;
                } else {
                    Attach453C(slot, e, act);
                }
                changed = 1;
                e->unk8 = slot->shape->unk8;
            }
            pv = e->prev;
            if (pv != 0) {
                func_00271FD8(&v, e->m10, pv->m10);
                d = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
                pv->unkAC = d;
                slot->unk4C = slot->unk4C + d;
            }
            e = e->next;
        }
        if (e != 0) {
            goto loop;
        }
    }
done:
    if (changed != 0) {
        slot->unk24 = slot->shape->unk0;
    }
    } while (0);
}
