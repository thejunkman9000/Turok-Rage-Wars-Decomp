#include "s804_types.h"

#define GFX(a, b) { S8Dl *_g = D_80110634++; _g->w0 = (a); _g->w1 = (b); }

typedef struct S8Q {
    s32 w0;
    s32 w4;
    u8 *p;
    s32 wC;
} S8Q;

typedef struct S8Ctx {
    u8 pad0[0x120];
    s32 unk120;
} S8Ctx;

extern S8Dl *D_80110634;
extern s32 D_800D297C;
extern f32 D_800CAF88;
extern f32 D_800CAF8C;
extern f32 D_800CAF90;
extern const f32 D_800CAF94;

s32 func_00296EC4();
void func_00296F7C();
void func_00268CE0(s32);
void func_0026925C(s32);
s32 func_002A5124();
void func_00295FB4();
s32 func_002A66B4();
void func_002A3B48(S8Emit *, S8Node *, s32, f32, S8Sp *);
void func_002536F4();

void func_002A4708(s32 arg0, S8Emit *e, S8Ctx *c) {
    S8Q q;
    S8Sp sp;
    s32 handle;
    S8Info *info;
    S8Q *qp;
    S8Node *n1, *n2;
    S8Part *part;
    s32 total;
    s32 id, idm1, i;
    s32 r;
    f32 acc, f, k;

    info = e->info;
    total = 0;
    if (info->unk1C == 2) {
        if (e->unk4C > 0.0f) {
            acc = 0.0f;
            for (part = e->parts; part != NULL; part = part->next) {
                part->unkA8 = acc / e->unk4C;
                acc += part->unkAC;
            }
        }
    }
    handle = func_00296EC4(&e->unk14, -1);
    if (handle != 0) {
        func_00296F7C(handle, &q);
        sp.unk4 = (u8 *)e->info + 0x24;
        sp.unk0 = e->info->unk23;
        qp = &q;
        if (e->flags & 2) {
            sp.unk8 = e->unkC;
            sp.unkC = e->unk10;
        } else {
            sp.unk8 = e->unkC;
            sp.unkC = e->unkC;
        }
        sp.unk10 = (f32)e->info->unk21 * D_800CAF88;
        sp.unk14 = (f32)e->info->unk22 * D_800CAF88;
        if (qp != NULL) {
            sp.unk18 = (f32)(1 << (qp->p[2] + 5));
            sp.unk18 = sp.unk18 * (f32)e->info->unk1D - D_800CAF8C;
            sp.unk1C = (f32)(1 << (qp->p[3] + 5));
            sp.unk20 = D_800CAF90 / ((f32)sp.unk0 - D_800CAF90);
        }
        k = D_800CAF94;
        f = e->unk28;
        if (k <= f) {
            do {
                f -= k;
                e->unk28 = f;
            } while (k <= f);
        }
        GFX(0xE7000000, 0);
        switch (q.p[0]) {
        case 3:
            func_00268CE0(0x29);
            if (c->unk120 != 0) {
                { u32 w = ((((u32)(info->unk19 + info->unk1A + info->unk1B) / 3) << 8) & 0xFF00) | 0xFF; GFX(0xFB000000, w); }
                { u32 w = ((((u32)(info->unk16 + info->unk17 + info->unk18) / 3) << 8) & 0xFF00) | 0xFF; GFX(0xFA000000, w); }
            } else {
                GFX(0xFB000000, (info->unk19 << 24) | (info->unk1A << 16) | (info->unk1B << 8) | 0xFF);
                GFX(0xFA000000, (info->unk16 << 24) | (info->unk17 << 16) | (info->unk18 << 8) | 0xFF);
            }
            break;
        case 0:
        case 1:
            func_00268CE0(0x28);
            break;
        }
        func_0026925C(0xD);
        n1 = e->nodes;
        id = info->unk23;
        n2 = n1->next;
        func_00295FB4(&e->unk14, handle, func_002A5124(e, info, &q), 0, 0xFFFF, 0xFFFF, 0, 0, 0);
        idm1 = id - 1;
        GFX(0xDA380003, (u32)&n1->mtx[D_800D297C]);
        while (n1 != NULL && n2 != NULL && n1->unk8 > 0.0f && n2->unk8 > 0.0f && total + id * 2 < 0x20) {
            r = func_002A66B4(arg0, id);
            if (r == 0) {
                break;
            }
            func_002A3B48(e, n1, r, n1->unkA8, &sp);
            total += id;
            { u32 wt; GFX((id << 12) | (wt = ((id & 0x7F) * 2) | 0x01000000), r); }
            GFX(0xDA380003, (u32)&n2->mtx[D_800D297C]);
            r = func_002A66B4(arg0, id);
            if (r == 0) {
                break;
            }
            f = n2->unkA8;
            while (n1->unkA8 < f) {
                f -= k;
            }
            func_002A3B48(e, n2, r, f, &sp);
            total += id;
            { u32 wt; GFX((id << 12) | (wt = (((id * 2) & 0x7F) * 2) | 0x01000000), r); }
            for (i = 0; i < idm1; i++) {
                u32 t0 = ((i * 2) & 0xFF) << 16;
                s32 a = id + i;
                GFX(t0 | ((a << 9) & 0xFE00) | ((((a + 1) * 2) & 0xFF)) | 0x06000000, t0 | (((((a + 1) * 2) & 0xFF)) << 8) | (((i + 1) * 2) & 0xFF));
            }
            if (e->info->unk12 != 0) {
                u32 t = ((i * 2) & 0xFF) << 16;
                GFX(t | (((id + i) << 9) & 0xFE00) | ((id * 2) & 0xFF) | 0x06000000, t | (((id * 2) & 0xFF) << 8));
            }
            n1 = n2;
            n2 = n1->next;
        }
        func_002536F4(0, handle);
    }
}
