
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
} R4Sp;

extern f32 D_800CAF98;
extern s32 D_800D297C;
extern DlCmd *D_80110634;

s32 func_002A66B4();
void func_002A373C(R4Emit *, R4Node *, s32, R4Sp *);

void func_002A4DC4(s32 arg0, R4Emit *e) {
    R4Sp sp;
    R4Node *n1, *n2;
    u8 id;
    s32 idm1, i;
    s32 w38, w3c, w40, w;
    s32 r;
    u32 hi, lo, id2;
    DlCmd *c;

    sp.unk4 = (u8 *)e->info + 0x24;
    sp.unk0 = e->info->unk23;
    if (e->flags & 2) {
        sp.unk8 = e->unkC;
        sp.unkC = e->unk10;
    } else {
        sp.unk8 = e->unkC;
        sp.unkC = e->unkC;
    }
    sp.unk10 = (f32)e->info->unk21 * D_800CAF98;
    sp.unk14 = (f32)e->info->unk22 * D_800CAF98;
    n1 = e->nodes;
    c = D_80110634++;
    n2 = n1->next;
    id = e->info->unk23;
    c->w0 = 0xDA380003;
    idm1 = id - 1;
    c->w1 = (u32)&n1->mtx[D_800D297C];
    if (n1 != NULL && n2 != NULL && n1->unk8 > 0.0f) {
        w38 = (id << 12) | (((id & 0x7F) * 2) | 0x01000000);
        w3c = (id << 12) | ((((id * 2) & 0x7F) * 2) | 0x01000000);
        w40 = ((id * 2) & 0xFF) << 8;
        while (1) {
            if (!(n2->unk8 > 0.0f)) {
                break;
            }
            r = func_002A66B4(arg0, id);
            if (r == 0) {
                break;
            }
            func_002A373C(e, n1, r, &sp);
            c = D_80110634++;
            c->w1 = r;
            c->w0 = w38;
            c = D_80110634++;
            c->w0 = 0xDA380003;
            c->w1 = (u32)&n2->mtx[D_800D297C];
            r = func_002A66B4(arg0, id);
            if (r == 0) {
                break;
            }
            func_002A373C(e, n2, r, &sp);
            c = D_80110634++;
            c->w1 = r;
            c->w0 = w3c;
            for (i = 0; i < idm1; i++) {
                s32 a = id + i;
                u32 t1 = (((a + 1) * 2) & 0xFF);
                u32 t0 = ((i * 2) & 0xFF) << 16;
                c = D_80110634++;
                c->w0 = t0 | ((a << 9) & 0xFE00) | t1 | 0x06000000;
                c->w1 = t0 | (t1 << 8) | (((i + 1) * 2) & 0xFF);
            }
            if (e->info->unk12 != 0) {
                u32 t = ((i * 2) & 0xFF) << 16;
                c = D_80110634++;
                c->w0 = t | (((id + i) << 9) & 0xFE00) | ((id * 2) & 0xFF) | 0x06000000;
                c->w1 = t | w40;
            }
            n1 = n2;
            n2 = n1->next;
            if (n1 == NULL || n2 == NULL || !(n1->unk8 > 0.0f)) break;
        }
    }
}


