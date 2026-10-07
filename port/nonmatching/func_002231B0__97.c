#include "b05_types.h"

typedef struct B05P10 {
    u8 pad0[0x5D8];
    /* 0x5D8 */ void* stats;
    u8 pad5DC[0xC0];
    /* 0x69C */ f32 f69C;
    /* 0x6A0 */ f32 f6A0;
    u8 pad6A4[0x80];
    /* 0x724 */ f32 f724;
    u8 pad728[0xC4];
    /* 0x7EC */ f32 f7EC;
    u8 pad7F0[0x9C4];
    /* 0x11B4 */ s32 unk11B4;
    u8 pad11B8[0x20];
    /* 0x11D8 */ f32 f11D8;
} B05P10;

typedef struct B05A10 {
    u8 pad0[0x6C];
    /* 0x06C */ f32 ang;
} B05A10;

typedef struct B05Sta10 { u8 pad0[0x79]; u8 b79; u8 b7A; s8 b7B; u8 pad7C; u8 b7D; } B05Sta10;
typedef struct B05In10 { f32 f0, f4, f8, fC, f10, f14; } B05In10;
typedef struct B05Hit10 { u8 pad0[0x50]; u32 flags; } B05Hit10;

extern f32 D_800C796C;
extern f32 D_800C7970;
extern f32 D_800C7974;
extern f32 D_800C7978;
extern f32 D_800C797C;
extern f32 D_800C7980;
extern f32 D_800C7984;
extern f32 D_800C7988;
extern f32 D_800C798C;
extern f32 D_800C7990;
extern f32 D_800C7994;
extern f32 D_800C7998;
extern f32 D_800C799C;
extern f32 D_800C79A0;

B05Hit10 *func_0024E7CC(B05A10 *);
void func_002748E0(void *, f32, f32);

void func_002231B0(B05P10 *p, B05A10 *a, B05In10 *in) {
    B05Sta10 *st;
    B05Hit10 *h;
    f32 turn;
    f32 spd;
    f32 t;
    f32 w;
    f32 x;

    if (p->unk11B4 == 0 && !(p->f11D8 > 0.0f)) {
        st = p->stats;
        t = D_800C7974 - p->f7EC * D_800C796C;
        turn = (((f32)st->b79 * D_800C7970 - D_800C7974) * D_800C7978 + D_800C797C) * (t * in->f4);
        spd = (((f32)st->b7A * D_800C7970 - D_800C7974) * D_800C7980 + D_800C7984) * (t * in->f8 * in->fC);
        switch (st->b7B) {
        case 1:
            spd = D_800C7978;
            break;
        case 0:
            if (st->b7D == 0) {
                spd = D_800C7988;
            }
            break;
        }
        h = func_0024E7CC(a);
        if (h == NULL || (h->flags & 0x6000) != 0x2000) {
            x = in->f0;
            if (x != 0.0f) {
                func_002748E0(&a->ang, a->ang + p->f69C * D_800C798C * x * D_800C7990, turn);
            }
        }
        w = -p->f6A0 * D_800C7994;
        if (w < 0.0f) {
            x = w * D_800C7998 * in->f10;
        } else {
            x = w * D_800C799C * in->f14;
        }
        func_002748E0(&p->f724, x * D_800C79A0, spd);
    }
}
