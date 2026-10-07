#include "b08_types.h"

typedef struct ViewObj ViewObj;
struct ViewObj {
    u8 pad0[0x4];
    ViewObj *next4;
    u8 pad8[0x118];
    s32 unk120;
    u8 pad124[2];
    u16 unk126;
    u8 pad128[0x188];
    u16 vp2B0[1];
};

typedef struct ViewList {
    s32 unk0;
    u8 pad4[0x1C];
    ViewObj *unk20;
    u8 pad24[0xC];
    s32 unk30;
    u8 pad34[0x52C];
    u8 unk560;
    u8 unk561;
    u8 unk562;
} ViewList;

typedef struct GfxCtx {
    u8 pad0[0x110];
    u32 unk110;
} GfxCtx;

typedef struct GameBase {
    u8 pad0[0x12A5];
    u8 flag12A5;
} GameBase;

void func_00253B5C(s32 a, s32 b);
void func_00235AD0(void *a);
void func_002362D8(void *a, void *w);
void func_00239FC4(void *a, s32 b);
void func_00233C78(void *a);
void func_00238304(ViewList *o, void *a);
void func_442B44(void *a);
void func_002372C4(void *a);
s32 func_00245774();
s32 func_00245788();
void func_0022A3E8(void *a, void *b);
void func_0026D8F8(void *a, void *b);

extern s32 D_80146894;
extern f32 D_80103224;
extern f32 D_800D2988;
extern s32 D_800D297C;
extern u8 D_800D0F10[];
extern u8 D_800D0F40[];
extern u16 D_800E28D2;
extern u16 D_800E28D6;
extern s32 D_800E28D0;
extern s32 D_800E28D4;
extern GfxCtx *D_8011FE80;
extern DlCmd *D_80110634;
extern GameBase D_80145040;

void func_00236F0C(ViewList *o, void *w) {
    ViewObj *s;
    ViewObj *vp;
    DlCmd *g1, *g2, *g3, *g4, *g5, *g6, *g7, *g8, *g9, *g10, *g11;
    s32 mw, mh;

    o->unk560 = 0;
    o->unk561 = 0;
    o->unk562 = 0;
    if (o->unk0 != 0) {
        func_00253B5C(0, o->unk0);
    }
    if (D_80146894 != 0 || o->unk30 == 3) {
        D_80103224 = 30.0f;
    }
    if (D_80103224 != 0.0f) {
        D_80103224 = D_80103224 - D_800D2988;
    }
    if (D_80103224 < 0.0f) {
        D_80103224 = 0.0f;
    }
    if (D_80103224 != 0.0f) {
        s = o->unk20;
        if (s != NULL) {
            vp = (ViewObj *)((u8 *)s + (D_800D297C << 4));
            g1 = D_80110634++;
            g1->w0 = 0xE7000000;
            g1->w1 = 0;
            g2 = D_80110634++;
            g2->w0 = 0xDE000000;
            g2->w1 = (u32)D_800D0F10;
            g3 = D_80110634++;
            g3->w0 = 0xDE000000;
            g3->w1 = (u32)D_800D0F40;
            ((u16 *)vp)[0x2B0 / 2] = D_800E28D2;
            ((u16 *)vp)[0x2B2 / 2] = D_800E28D6;
            ((u16 *)vp)[0x2B8 / 2] = D_800E28D2;
            ((u16 *)vp)[0x2BA / 2] = D_800E28D6;
            g4 = D_80110634++;
            g4->w0 = 0xDC080008;
            g4->w1 = (u32)((u8 *)vp + 0x2B0);
            g5 = D_80110634++;
            g5->w0 = 0xED000000;
            mw = D_800E28D0;
            mh = D_800E28D4;
            g5->w1 = ((((s32)((f32)(mw - 1) * 4.0f)) & 0xFFF) << 12) | (((s32)((f32)(mh - 1) * 4.0f)) & 0xFFF);
            g6 = D_80110634++;
            g6->w0 = ((u32)(mw - 1) & 0xFFF) | 0xFF100000;
            g6->w1 = D_8011FE80->unk110;
            g7 = D_80110634++;
            g7->w0 = 0xE3000A01;
            g7->w1 = 0x300000;
            g8 = D_80110634++;
            g8->w0 = 0xFCFFFFFF;
            g8->w1 = 0xFFFE793C;
            g9 = D_80110634++;
            g9->w0 = 0xE200001C;
            g9->w1 = 0;
            g10 = D_80110634++;
            g10->w0 = 0xF7000000;
            g10->w1 = 0x10001;
            g11 = D_80110634++;
            g11->w0 = 0xF6000000 | (((u32)mw & 0x3FF) << 14) | (((u32)mh & 0x3FF) << 2);
            g11->w1 = 0;
            func_0026D8F8(g2, g11);
        }
    }
    s = o->unk20;
    if (s != NULL) {
        do {
            func_00235AD0(s);
            func_002362D8(s, w);
            if (s->unk120 != 0) {
                func_00239FC4(s, s->unk126);
            }
            func_00233C78(s);
            func_00238304(o, s);
            func_442B44((u8 *)s + 0x554);
            func_002372C4(s);
            if (func_00245774() != 0) {
                s = NULL;
            } else if (func_00245788() != 0) {
                s = NULL;
            } else {
                s = s->next4;
            }
                } while (s != NULL);
    }
    func_00235AD0((u8 *)o + 0x40);
    if (o->unk30 == 0) {
        func_00233C78((u8 *)o + 0x40);
    }
    func_00238304(o, (u8 *)o + 0x40);
    if (D_80145040.flag12A5 != 0) {
        s = o->unk20;
        if (s != NULL) {
            func_0022A3E8(&D_80145040, s);
        }
    }
    func_442B44((u8 *)o + 0x594);
}
