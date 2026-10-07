#include "r03_types.h"

extern DlCmd *D_80110634;
extern s32 D_800D297C;
extern s32 D_800E28D0;
extern s32 D_800E28D4;
extern u8 D_800D0F10[];
extern u8 D_800D0F40[];
extern u8 D_8011FAC0[];
extern u8 D_801450C8[];
extern u32 D_801462C8;
extern struct { u8 pad[0x110]; u32 unk110; } *D_8011FE80;
void func_0026E330(s32 a, void *b, void *c, void *d);
void func_00297008(s32 a);
void func_0026D88C(void);
void func_00296FF8(void);
void func_0026925C(s32 a);
s32 func_002A33AC(void);
s32 func_0029A958(void);
s32 func_00245788(void);
u32 func_00245AE8(void);
void func_00291BF8(void *a, s16 b, s16 c, s16 d, s32 e, s32 f);
void func_0026D914(s32 a);
void func_00265A00(void *a);

void func_00235AD0(R3View *o) {
    s32 s7, s6, s5, s4;
    s32 t3, t6;
    s32 n7, n6, n5, n4;
    s32 idx;
    s32 s0;
    u8 c0, c1, c2;
    DlCmd *d7;
    u8 *a1p;
    u32 w;

    {
        DlCmd *d = D_80110634++;
        d->w0 = 0xE7000000;
        d->w1 = 0;
    }
    {
        DlCmd *d = D_80110634++;
        d->w0 = 0xDE000000;
        d->w1 = (u32)D_800D0F10;
    }
    {
        DlCmd *d = D_80110634++;
        d->w0 = 0xDE000000;
        d->w1 = (u32)D_800D0F40;
    }
    o->unkC = 1.0f;
    o->unk10 = 1.0f;
    o->unkC = o->unk110;
    n7 = (s32)o->unk2A4;
    s7 = n7;
    n6 = (s32)o->unk2A8;
    s6 = n6;
    o->unk10 = o->unk114;
    n5 = (s32)(o->unk2A4 + o->unk29C);
    s5 = n5;
    n4 = (s32)(o->unk2A8 + o->unk2A0);
    t3 = (s32)(2.0f * o->unk29C * o->unk110);
    t6 = (s32)(2.0f * o->unk2A0 * o->unk114);
    s4 = n4;
    if (D_800E28D0 - 1 < (s16)n5) {
        s5 = (u16)D_800E28D0 - 1;
    }
    if (n7 & 0x8000) {
        s7 = 0;
    }
    if (n6 & 0x8000) {
        s6 = 0;
    }
    if (D_800E28D4 - 1 < (s16)n4) {
        s4 = (u16)D_800E28D4 - 1;
    }
    idx = D_800D297C;
    {
        DlCmd *d = D_80110634++;
        d->w0 = 0xDA380007;
        d->w1 = (u32)((u8 *)o + (idx * 64 + 0x380));
    }
    o->rect[idx].x0 = t3;
    o->rect[idx].y0 = t6;
    {
        DlCmd *d = D_80110634++;
        d->w0 = 0xDB0E0000;
        d->w1 = o->unk68;
    }
    o->rect[idx].x1 = (s32)(((f32)(s16)t3 * 0.25f + o->unk2A4) * 4.0f);
    o->rect[idx].y1 = (s32)(((f32)(s16)t6 * 0.25f + o->unk2A8) * 4.0f);
    {
        DlCmd *d = D_80110634++;
        d->w0 = 0xDC080008;
        d->w1 = (u32)((u8 *)o + (idx * 16 + 0x2B0));
    }
    {
        DlCmd *d = D_80110634++;
        d7 = d;
        d->w0 = 0xED000000 | (((s32)((f32)(s16)s7 * 4.0f) & 0xFFF) << 12) | ((s32)((f32)(s16)s6 * 4.0f) & 0xFFF);
        d->w1 = (((s32)((f32)(s16)s5 * 4.0f) & 0xFFF) << 12) | ((s32)((f32)(s16)s4 * 4.0f) & 0xFFF);
    }
    a1p = (u8 *)o + (idx * 32 + 0x400);
    {
        DlCmd *d = D_80110634++;
        d->w0 = 0xDC08000A;
        d->w1 = (u32)a1p;
    }
    {
        DlCmd *d = D_80110634++;
        d->w0 = 0xDC08030A;
        d->w1 = (u32)(a1p + 0x10);
    }
    func_0026E330(o->unk120, a1p + 0x10, (u8 *)o + idx * 16, d7);
    if ((u8 *)o != D_801450C8) {
        func_00297008(o->unk120);
    }
    s0 = 0;
    func_0026D88C();
    func_00296FF8();
    {
        DlCmd *d = D_80110634++;
        d->w0 = 0xE3001201;
        d->w1 = 0x2000;
    }
    if (func_002A33AC() != 0) {
        s0 = (u32)(func_0029A958() ^ 2) > 0;
    }
    if ((u8 *)o != D_801450C8 || ((s32 *)o)[-4] == 0 || s0 != 0) {
        func_0026925C(0x14);
        {
            DlCmd *d = D_80110634++;
            d->w0 = 0xE7000000;
            d->w1 = 0;
        }
        func_00291BF8(D_8011FAC0, (s16)s7, (s16)s5, (s16)s6, (s16)s4, o->unk120);
        {
            DlCmd *d = D_80110634++;
            d->w0 = 0xE3000A01;
            d->w1 = 0x300000;
        }
        if (D_801462C8 & 0x4000) {
            c0 = 0;
            c1 = 0;
            c2 = 0;
        } else {
            c0 = o->col[0] & 0xF8;
            c1 = o->col[1] & 0xF8;
            c2 = o->col[2] & 0xF8;
        }
        if (func_00245788() != 0) {
            w = func_00245AE8();
            if (w != 0xFF00) {
                c2 = w >> 16;
                c1 = w >> 8;
                c0 = w;
            }
        }
        {
            DlCmd *d = D_80110634++;
            d->w0 = 0xD9FFFFFF;
            d->w1 = 0x10000;
        }
        if (o->unk120 != 0) {
            {
                DlCmd *d = D_80110634++;
                d->w0 = 0xF8000000;
                d->w1 = 0xFF;
            }
            {
                DlCmd *d = D_80110634++;
                d->w0 = 0xDB080000;
                d->w1 = 0x64009D00;
            }
        } else {
            {
                DlCmd *d = D_80110634++;
                d->w0 = 0xF8000000;
                d->w1 = (c0 << 24) | (c1 << 16) | (c2 << 8) | 0xFF;
            }
            {
                DlCmd *d = D_80110634++;
                s32 q = 0x3E8 - o->unk53E;
                d->w0 = 0xDB080000;
                d->w1 = ((0x1F400 / q) << 16) | (((0x1F4 - o->unk53E) << 8) / q & 0xFFFF);
            }
        }
        {
            DlCmd *d = D_80110634++;
            d->w0 = ((D_800E28D0 - 1) & 0xFFF) | 0xFF100000;
            d->w1 = D_8011FE80->unk110;
        }
        {
            DlCmd *d = D_80110634++;
            d->w0 = 0xF7000000;
            if (o->unk120 != 0) {
                d->w1 = 0x10001;
            } else {
                u32 q = ((c0 << 8) & 0xF800) | ((c1 * 8) & 0x7C0) | ((c2 >> 2) & 0x3E);
                d->w1 = ((q | 1) << 16) | 1 | q;
            }
        }
        if ((u8 *)o != D_801450C8 || o->unk17B0 == 3) {
            DlCmd *d = D_80110634++;
            d->w0 = ((s5 & 0x3FF) << 14) | ((s4 & 0x3FF) * 4) | 0xF6000000;
            d->w1 = ((s7 & 0x3FF) << 14) | ((s6 & 0x3FF) * 4);
        }
    }
    {
        DlCmd *d = D_80110634++;
        d->w0 = 0xE7000000;
        d->w1 = 0;
    }
    func_0026D914(0);
    {
        DlCmd *d = D_80110634++;
        d->w0 = 0xE3001A01;
        d->w1 = 0x10;
    }
    {
        DlCmd *d = D_80110634++;
        d->w0 = 0xE3000A01;
        d->w1 = 0x100000;
    }
    if ((u8 *)o != D_801450C8) {
        func_00265A00(o);
    }
    {
        DlCmd *d = D_80110634++;
        d->w0 = 0xE7000000;
        d->w1 = 0;
    }
}
