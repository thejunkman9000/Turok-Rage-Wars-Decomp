
#include "r08_types.h"

typedef struct DlCmd { u32 w0; u32 w1; } DlCmd;
typedef struct R4Info {
    /* 0x00 */ u8 pad0[0x12];
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13[0xE];
    /* 0x21 */ u8 unk21;
    /* 0x22 */ u8 unk22;
    /* 0x23 */ u8 unk23;
} R4Info;
typedef struct R4Node R4Node;
struct R4Node {
    /* 0x00 */ R4Node *next;
    /* 0x04 */ u8 pad4[4];
    /* 0x08 */ f32 unk8;
    /* 0x0C */ u8 padC[0x1C];
    /* 0x28 */ R8Mtx mtx[2];
};
typedef struct R4Emit {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ R4Info *info;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ u8 pad14[0x28];
    /* 0x3C */ u32 flags;
    /* 0x40 */ u8 pad40[4];
    /* 0x44 */ R4Node *nodes;
} R4Emit;
typedef struct R4Sp {
    s32 unk0;
    u8 *unk4;
    s32 unk8;
    s32 unkC;
    f32 unk10;
    f32 unk14;
    u8 pad18[16];
} R4Sp;

extern f32 D_800CAF98;
extern s32 D_800D297C;
extern DlCmd *D_80110634;

s32 func_002A66B4();
void func_002A373C(R4Emit *, R4Node *, s32, R4Sp *);

#define GFX(a, b) { DlCmd *_g = D_80110634++; _g->w0 = (a); _g->w1 = (b); }

void func_002A4DC4(s32 arg0, R4Emit *e) {
    R4Sp sp;
    R4Sp *p = &sp;
    R4Node *n1, *n2;
    s32 id;
    s32 idm1, i;
    s32 r;

    p->unk4 = (u8 *)e->info + 0x24;
    sp.unk0 = e->info->unk23;
    if (e->flags & 2) {
        p->unk8 = e->unkC;
        p->unkC = e->unk10;
    } else {
        p->unk8 = e->unkC;
        p->unkC = e->unkC;
    }
    p->unk10 = (f32)e->info->unk21 * D_800CAF98;
    p->unk14 = (f32)e->info->unk22 * D_800CAF98;
    n1 = e->nodes;
    n2 = n1->next;
    id = e->info->unk23;
    GFX(0xDA380003, (u32)&n1->mtx[D_800D297C]);
    idm1 = id - 1;
    while (n1 != NULL && n2 != NULL && n1->unk8 > 0.0f && n2->unk8 > 0.0f) {
            r = func_002A66B4(arg0, id);
            if (r == 0) {
                break;
            }
            func_002A373C(e, n1, r, &sp);
            { u32 wt; GFX((id << 12) | (wt = ((id & 0x7F) * 2) | 0x01000000), r); }
            GFX(0xDA380003, (u32)&n2->mtx[D_800D297C]);
            r = func_002A66B4(arg0, id);
            if (r == 0) {
                break;
            }
            func_002A373C(e, n2, r, &sp);
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
}
