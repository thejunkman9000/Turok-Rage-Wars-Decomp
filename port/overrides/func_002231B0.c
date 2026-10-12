/* PORT override of src/game/func_002231B0.c (player view: turn and tilt from the pad output): unchanged game logic plus native mouse look (port/input.c). */
#include "s702_types.h"

typedef struct B05P10 {
    u8 pad0[0x5D8];
    void *stats;
    u8 pad5DC[0xB0];
    f32 f68C;                   /* +0x688 pad output: +0x4 = the tilt accumulator of func_002631D0 */
    u8 pad690[0x8];
    struct { u8 pad[4]; s8 port; } *ctl;   /* +0x698 controller slot (0x8010F328 + 0x224 * port; port -1 = merged) */
    f32 f69C;
    f32 f6A0;
    u8 pad6A4[0x80];
    f32 f724;
    u8 pad728[0xC4];
    f32 f7EC;
    u8 pad7F0[0x9C4];
    s32 unk11B4;
    u8 pad11B8[0x20];
    f32 f11D8;
} B05P10;

typedef struct B05A10 {
    u8 pad0[0x6C];
    f32 ang;
} B05A10;

typedef struct B05Sta10 {
    u8 pad0[0x79];
    u8 b79;
    u8 b7A;
    s8 b7B;
    u8 pad7C;
    u8 b7D;
} B05Sta10;

typedef struct B05In10 {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
} B05In10;

typedef struct B05Hit10 {
    u8 pad0[0x50];
    u32 flags;
} B05Hit10;

B05Hit10 *func_0024E7CC(B05A10 *);
void func_002748E0(void *, f32, f32);
int input_native_active(int port);          /* port/input.c (native host code) */
int port_human_slot(const void *ctl);       /* port/input.c: the port of a real controller slot, -2 for an AI controller */
float input_native_get(int port, int what);

void func_002231B0(B05P10 *p, B05A10 *a, B05In10 *in) {
    f32 om;
    B05Sta10 *st;
    B05Hit10 *h;
    f32 turn;
    f32 m;
    f32 spd;
    f32 w;
    f32 x;
    if ((p->unk11B4 == 0) && (!(p->f11D8 > 0.0f))) {
        om = p->f7EC * 0.99f;
        st = p->stats;
        m = (((f32) st->b79) * 0.0078125f) - 1.0f;
        turn = (m * 0.5f) + 0.875f;
        m = (((f32) st->b7A) * 0.0078125f) - 1.0f;
        turn = turn * ((1.0f - om) * in->f4);
        spd = (m * 0.4f) + 0.6f;
        spd = spd * (((1.0f - om) * in->f8) * in->fC);
        switch (st->b7B) {
        case 1:
            spd = 0.5f;
            break;
        case 0:
            if (st->b7D == 0) {
                spd = 0.8f;
            }
            break;
        }

        h = func_0024E7CC(a);
        if ((h == ((void *) 0)) || ((h->flags & 0x6000) != 0x2000)) {
            if (in->f0 != 0.0f) {
                func_002748E0(&a->ang, a->ang + ((p->f69C * 8e+01f * in->f0) * 0.017453294f), turn);
            }
        }
        w = (-p->f6A0) * 8e+01f;
        if (w < 0.0f) {
            x = (w * (-0.71619713f)) * in->f10;
        } else {
            x = (w * 0.71619713f) * in->f14;
        }
        func_002748E0(&p->f724, x * 0.017453294f, spd);
        {   /* PORT: native mouse look (port/input.c, native_controls): turn by exactly the mouse motion, tilt the view to an exact angle */
            /* only actors driven by a real controller slot (0x8010F328 + 0x224 * n, n = -1 merged .. 3): bots carry their own AI controller object
               (e.g. 0x8010EEB8, whose port byte reads 0) and must never get the mouse - they were turned by the player's mouse and ended with NaN angles
               (invisible bots, NaN animation-event positions -> INT_MIN damage, the "health 265 then dead" bug) */
            s32 port = port_human_slot(p->ctl);
            if (port >= -1 && input_native_active(port)) {
                f32 dyaw = input_native_get(port, 2);
                f32 dtilt = input_native_get(port, 3);
                f32 t;
                if ((h == ((void *) 0)) || ((h->flags & 0x6000) != 0x2000)) {
                    a->ang = a->ang + dyaw * 0.017453294f;
                }
                /* view tilt x (degrees) = -f6A0 * 80 * 0.716 * (f10 when looking one way, f14 the other): move it by dtilt, keep f6A0 in the game's range */
                t = (p->f6A0 > 0.0f) ? -in->f10 : in->f14;
                if (t < 0.0f) t = -t;
                if (t > 0.001f && dtilt != 0.0f) {
                    t = p->f6A0 - dtilt / (8e+01f * 0.71619713f * t);
                    if (t > 1.0f) t = 1.0f;
                    if (t < -1.0f) t = -1.0f;
                    p->f6A0 = t;
                    p->f68C = t;
                }
                w = (-p->f6A0) * 8e+01f;
                x = (w < 0.0f) ? (w * (-0.71619713f)) * in->f10 : (w * 0.71619713f) * in->f14;
                p->f724 = x * 0.017453294f;
            }
        }
    }
}
